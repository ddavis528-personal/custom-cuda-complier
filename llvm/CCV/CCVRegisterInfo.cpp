//===-- CCVRegisterInfo.cpp -----------------------------------------------===//
#include "CCVRegisterInfo.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "CCVFrameLowering.h"
#include "CCVSubtarget.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/MathExtras.h"

#define GET_REGINFO_TARGET_DESC
#include "CCVGenRegisterInfo.inc"

using namespace llvm;

// No return-address register convention: the link register is explicit in
// call/ret and chosen by the compiler (§3, Format E).
CCVRegisterInfo::CCVRegisterInfo() : CCVGenRegisterInfo(/*RA=*/0) {}

const MCPhysReg *
CCVRegisterInfo::getCalleeSavedRegs(const MachineFunction *) const {
  return CSR_CCV_SaveList;
}

BitVector CCVRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  // R15 is the frame pointer: it holds the WINDOW INDEX of this thread's
  // `.local` frame, so a spill is one base+offset instruction and needs no
  // index register. See O-30.
  //
  // It has to be reserved unconditionally, which costs 6% of the file in every
  // kernel: whether a function spills is decided during register allocation,
  // and this is asked before. It only binds at 16 simultaneously live values,
  // so no kernel measured so far pays anything for it.
  Reserved.set(CCV::R15);
  // P3 is the lane-0 mask for O-33's mask-and-broadcast. Like R15 it has to be
  // reserved before allocation runs, because whether a function has uniform
  // work to mask is decided by a pass that runs after this is asked. Measured
  // predicate pressure across every kernel here is 1-2 of 4, so the quarter of
  // the file this costs is currently unused anyway -- O-32 removing the
  // manufactured guards is most of why.
  Reserved.set(CCV::P3);
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
  unsigned DispOp;
  switch (I.getOpcode()) {
  case CCV::LD_GLOBAL_IDX: case CCV::LD_GLOBAL_IDX_W16:
  case CCV::ST_GLOBAL_IDX: case CCV::ST_GLOBAL_IDX_W16:
    DispOp = FIOperandNum + 3;
    break;
  default:
    DispOp = FIOperandNum + 1;
    break;
  }
  int64_t Off = MF.getFrameInfo().getObjectOffset(FI) +
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
                 "§3's Format D; this kernel spills more than 4 KiB per "
                 "thread");

  I.getOperand(FIOperandNum).ChangeToRegister(CCV::R15, /*isDef=*/false);
  I.getOperand(DispOp).ChangeToImmediate(Off);
  return false;
}

Register CCVRegisterInfo::getFrameRegister(const MachineFunction &) const {
  return CCV::R15;
}
