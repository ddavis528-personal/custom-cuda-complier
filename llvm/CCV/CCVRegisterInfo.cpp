//===-- CCVRegisterInfo.cpp -----------------------------------------------===//
#include "CCVRegisterInfo.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "CCVFrameLowering.h"
#include "CCVSubtarget.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MathExtras.h"

#define GET_REGINFO_TARGET_DESC
#include "CCVGenRegisterInfo.inc"

using namespace llvm;

// No return-address register convention: the link register is explicit in
// call/ret and chosen by the compiler (§3, Format E).
CCVRegisterInfo::CCVRegisterInfo() : CCVGenRegisterInfo(/*RA=*/0) {}

// The callee-saved set is CP-9's open question (proposals/calling-convention.md
// §6): a choice for measurement to settle, so it is an option to sweep rather
// than a constant to argue about.
static cl::opt<std::string> CSRSet(
    "ccv-csr", cl::init("six"),
    cl::desc("CCV callee-saved registers: none, six (R8-R13) or eight "
             "(R0, R7-R13)"));

const MCPhysReg *
CCVRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  // A kernel has no caller to preserve anything for.
  if (MF && ccvIsKernel(MF->getFunction()))
    return CSR_CCV_None_SaveList;
  if (CSRSet == "none")  return CSR_CCV_None_SaveList;
  if (CSRSet == "eight") return CSR_CCV_Eight_SaveList;
  if (CSRSet != "six")
    report_fatal_error("CCV: -ccv-csr takes none, six or eight");
  return CSR_CCV_SaveList;
}

const uint32_t *
CCVRegisterInfo::getCallPreservedMask(const MachineFunction &,
                                      CallingConv::ID) const {
  if (CSRSet == "none")  return CSR_CCV_None_RegMask;
  if (CSRSet == "eight") return CSR_CCV_Eight_RegMask;
  return CSR_CCV_RegMask;
}

static cl::opt<bool> ReserveLaneIndex(
    "ccv-reserve-lane-index", cl::init(false), cl::Hidden,
    cl::desc("reserve R0 as a lane-index register, to measure what a "
             "lane-interleaved .local through a second register costs (AR-23)"));

BitVector CCVRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  // R15 is the frame pointer: it holds the WINDOW INDEX of this thread's
  // `.local` frame (O-30). Spills used to need it too, so it was reserved
  // unconditionally, 6% of the file in every function. Under O-69 spills go
  // to the interleaved spill space, which names no register, so R15 is
  // reserved only where O-30's frame is still needed -- an address-taken
  // object or a stack argument, known before allocation (ccvNeedsR15).
  if (ccvNeedsR15(MF))
    Reserved.set(CCV::R15);
  // P3 is the lane-0 mask for O-33's mask-and-broadcast. Like R15 it has to be
  // reserved before allocation runs, because whether a function has uniform
  // work to mask is decided by a pass that runs after this is asked. Measured
  // predicate pressure across every kernel here is 1-2 of 4, so the quarter of
  // the file this costs is currently unused anyway -- O-32 removing the
  // manufactured guards is most of why.
  Reserved.set(CCV::P3);
  // AR-23 option (ii): a lane-interleaved .local through a second reserved
  // register holding 4 x laneid. Measurement only: what the GPR costs in
  // spills. R0 is neither an argument nor callee-saved.
  if (ReserveLaneIndex)
    Reserved.set(CCV::R0);
  return Reserved;
}

bool CCVRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *) const {
  MachineInstr &I = *MI;
  MachineFunction &MF = *I.getParent()->getParent();
  int FI = I.getOperand(FIOperandNum).getIndex();

  // Where the displacement sits depends on the addressing form. Format D
  // base+offset puts it straight after the base; base+index has the index and
  // the scale-enable in between (§3). A local array indexed by a loop variable
  // selects the second (F-131), and assuming the first would have folded the
  // frame offset into the SCALE field -- silently, since both are immediates.
  // A frame object's address as a pair's offset (CCVPointerPairs). Under
  // IS-25 the window is R15's own and slot d is at d in it; under O-64 the
  // window is R15 - 1, so slot d is at 65536 + d.
  if (I.getOpcode() == CCV::MOVI) {
    int64_t D = ccvFrameDisp(MF.getFunction(),
                             MF.getFrameInfo().getObjectOffset(FI));
    int64_t InWindow = ccvFrameInPriv() ? D : 65536 + D;
    if (InWindow < 0 || InWindow >= 65536)
      report_fatal_error("CCV: a frame object outside its pair's window");
    I.getOperand(FIOperandNum).ChangeToImmediate(InWindow);
    return false;
  }

  // O-69: a spill slot in the interleaved spill space. The access names no
  // register; its offset is the slot's absolute byte in the warp's frame.
  int64_t Local = ccvLocalSlot(MF, FI);
  if (Local >= 0) {
    const TargetInstrInfo &TII = *MF.getSubtarget().getInstrInfo();
    MachineBasicBlock &MBB = *I.getParent();
    int64_t Disp = I.getOperand(FIOperandNum + 1).getImm();
    switch (I.getOpcode()) {
    case CCV::ST_GLOBAL:
      BuildMI(MBB, MI, I.getDebugLoc(), TII.get(CCV::ST_LOCAL))
          .add(I.getOperand(0))
          .addImm(Local + Disp);
      break;
    case CCV::LD_GLOBAL:
      BuildMI(MBB, MI, I.getDebugLoc(), TII.get(CCV::LD_LOCAL))
          .add(I.getOperand(0))
          .addImm(Local + Disp);
      break;
    case CCV::PSEUDO_ST_PRED:
    case CCV::PSEUDO_LD_PRED: {
      // Positional, as ld.pred/st.pred are: Pi's word is at b + 4i, so a
      // slot at b is addressed as b - 4i. Slots start at 12 (CCVFrameLowering).
      const unsigned P = I.getOperand(0).getReg() - CCV::P0;
      BuildMI(MBB, MI, I.getDebugLoc(),
              TII.get(I.getOpcode() == CCV::PSEUDO_ST_PRED ? CCV::ST_PRED_LOCAL
                                                           : CCV::LD_PRED_LOCAL))
          .addImm(1u << P)
          .addImm(Local + Disp - 4 * int64_t(P));
      break;
    }
    default:
      report_fatal_error("CCV: a spill slot reached by an instruction the "
                         "interleaved spill space has no form for (O-69)");
    }
    I.eraseFromParent();
    return true;
  }

  unsigned DispOp;
  switch (I.getOpcode()) {
  case CCV::LD_GLOBAL_IDX: case CCV::LD_GLOBAL_IDX_W16: case CCV::LD_GLOBAL_IDX_W8:
  case CCV::ST_GLOBAL_IDX: case CCV::ST_GLOBAL_IDX_W16: case CCV::ST_GLOBAL_IDX_W8:
    DispOp = FIOperandNum + 3;
    break;
  default:
    DispOp = FIOperandNum + 1;
    break;
  }
  // Frames are laid out statically over the whole module (F-21): this
  // function's frame sits beside every frame its callees reach -- above them
  // under IS-25, below them under O-64 -- so the same R15 serves every
  // function and a call moves nothing.
  int64_t Off = ccvFrameDisp(MF.getFunction(),
                             MF.getFrameInfo().getObjectOffset(FI)) +
                I.getOperand(DispOp).getImm();

  // R15 holds the window index, so the whole frame is addressed by the
  // displacement alone -- and the two Format D sub-layouts do not give it the
  // same width. Base+offset has 13 signed bits at [31:19]; base+index spends
  // those bits on the index register and keeps 8 at [31:24] (§3). Checking 13
  // for both would let a frame offset past 127 bytes truncate silently into
  // the narrower field, which is a wrong address rather than a diagnostic.
  bool Narrow = DispOp != FIOperandNum + 1;
  if (Narrow ? !isInt<8>(Off) : !isInt<13>(Off))
    report_fatal_error(
        Narrow ? "CCV: a dynamically indexed local array sits more than 128 "
                 "bytes into the frame, past the 8-bit displacement §3 leaves "
                 "Format D's base+index form (roadmap F-131)"
               : "CCV: stack frame exceeds the 13-bit displacement of "
                 "§3's Format D; this kernel and the functions it calls "
                 "spill more than 4 KiB per thread");

  I.getOperand(FIOperandNum).ChangeToRegister(CCV::R15, /*isDef=*/false);
  I.getOperand(DispOp).ChangeToImmediate(Off);
  return false;
}

Register CCVRegisterInfo::getFrameRegister(const MachineFunction &) const {
  return CCV::R15;
}

// Mutation control for tools/check-narrow-loop.sh: a narrow kernel's 32-bit
// values take R8-R13 first, the registers it holds at 16 bits, so their 16-bit
// view truncates them. A run must catch it.
static cl::opt<bool> TestNarrowNoPartition(
    "ccv-test-narrow-no-partition", cl::init(false), cl::Hidden,
    cl::desc("allocate a narrow kernel's 32-bit values to R8-R13 first, to "
             "test that the partition is what keeps them whole"));

namespace llvm {
/// CCVRegisterInfo.td's GPR order for a narrow kernel with N narrow
/// registers: N - 1 for F-200's partition (orders 1 to 5), 6 the control's.
unsigned ccvNarrowGPROrder(unsigned N) {
  return TestNarrowNoPartition ? 6 : N - 1;
}
} // namespace llvm

bool CCVRegisterInfo::shouldCoalesce(MachineInstr *MI,
                                     const TargetRegisterClass *SrcRC,
                                     unsigned, const TargetRegisterClass *DstRC,
                                     unsigned, const TargetRegisterClass *,
                                     LiveIntervals &) const {
  // F-200: a narrow kernel keeps its 16-bit integers in R8-R13 at width 16 and
  // everything else out of them, so a value crossing between the classes is a
  // copy, a `mov` across widths: rs's element, zero-extended or truncated to
  // rd's width (O-82). The classes have different value types, so the coalescer has no
  // common class to join them in today; this keeps that true if one appears.
  const MachineFunction &MF = *MI->getMF();
  if (!MF.getSubtarget<CCVSubtarget>().narrowInt())
    return true;
  auto Narrow = [](const TargetRegisterClass *RC) {
    return RC == &CCV::GPR16RegClass;
  };
  return Narrow(SrcRC) == Narrow(DstRC);
}
