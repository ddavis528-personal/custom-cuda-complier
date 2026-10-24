//===-- CCVNarrowUses.cpp - a narrow use reads its own copy ---------------===//
//
// F-169. A register's element width is one state for the whole register
// (invariant 1). A value read at 16 bits is narrowed in place by
// CCVInsertChwidth, and a later read at 32 bits widens it again, which
// zero-extends (O-38): the bits above the element are gone. Selection makes
// exactly that: `trunc i32 -> i16` is a COPY, and since GPR, GPR16 and GPR8
// hold the same registers, the emitter and MachineCSE fold it into the 32-bit
// value, which a 16-bit instruction then reads directly. `align_mem` read a
// pointer's in-window offset at 16 bits and the pointer lost the offset's high
// half -- invisible below 64 KiB, wrong past it (the CoreMark-derived
// workload's four-warp shape).
//
// So before allocation, each narrow use of a value that is also read wider
// gets its own value through PSEUDO_NARROW, which the allocator sees and pays
// for (in the same register when the wide value dies there). A source of an
// instruction whose result's low bits depend only on its sources' low bits
// needs nothing: CCVInsertChwidth leaves a wider source as it is (§3 reads an
// operand at its register's width).
//
//===----------------------------------------------------------------------===//

#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

using namespace llvm;

namespace llvm {
uint8_t operandWidth(const MCInstrDesc &D, unsigned OpNo);
bool lowBitsClosed(unsigned Op);
bool ccvTestNarrowInPlace();   // -ccv-test-narrow-in-place, CCVInsertChwidth's
} // namespace llvm

// Measurement control for F-195: every truncation narrows its register,
// whether or not anything reads it at 32 bits.
static cl::opt<bool> TestTruncAlwaysNarrow(
    "ccv-test-trunc-always-narrow", cl::init(false), cl::Hidden,
    cl::desc("narrow every truncation's register, to measure what narrowing "
             "only where a 32-bit read needs it saves"));

// Mutation control for tools/check-coremark-derived.sh (F-198): a narrow
// load's destination may share a register with its base or index again, as
// O-39 allows.
static cl::opt<bool> TestNarrowDataShared(
    "ccv-test-narrow-data-shared", cl::init(false), cl::Hidden,
    cl::desc("let a narrow load's destination share a register with its base "
             "or index, as before F-198"));

namespace {

class CCVNarrowUses : public MachineFunctionPass {
public:
  static char ID;
  CCVNarrowUses() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  StringRef getPassName() const override { return "CCV narrow uses"; }
};

char CCVNarrowUses::ID = 0;

bool CCVNarrowUses::runOnMachineFunction(MachineFunction &MF) {
  if (ccvTestNarrowInPlace())
    return false;
  MachineRegisterInfo &MRI = MF.getRegInfo();
  const TargetInstrInfo *TII = MF.getSubtarget().getInstrInfo();

  // F-198: a narrow load's destination gets a register of its own. Shared with
  // the base or index, the chwidth before the load narrows the address
  // register too, and O-39's 32-bit read of it then takes bits above the
  // element that a sliced register (OI-29) does not hold. Kept apart, the
  // address never depends on them, whichever way IS rules, and CoreMark-derived
  // runs 1,865 fewer issue groups a warp, since the chwidth no longer has to be
  // undone for the index's next reader.
  if (!TestNarrowDataShared)
    for (MachineBasicBlock &MBB : MF)
      for (MachineInstr &MI : MBB)
        if (MI.mayLoad() && MI.getNumExplicitDefs() == 1 &&
            MI.getOperand(0).isReg() && operandWidth(MI.getDesc(), 0) != 0)
          MI.getOperand(0).setIsEarlyClobber(true);

  // Each virtual GPR's narrowest and widest reads. A use whose width the
  // descriptor does not give (a COPY, a PHI, a call's argument) counts as 32.
  DenseMap<Register, std::pair<uint8_t, uint8_t>> Widths;   // min, max code
  SmallVector<std::pair<MachineInstr *, unsigned>, 16> Narrow;
  for (MachineBasicBlock &MBB : MF)
    for (MachineInstr &MI : MBB)
      for (unsigned O = 0, N = MI.getNumOperands(); O != N; ++O) {
        const MachineOperand &MO = MI.getOperand(O);
        if (!MO.isReg() || !MO.isUse() || !MO.getReg().isVirtual() ||
            MO.isUndef())
          continue;
        const TargetRegisterClass *RC = MRI.getRegClass(MO.getReg());
        if (!CCV::GPRRegClass.hasSubClassEq(RC))
          continue;
        uint8_t W = MI.isPseudo() && !MI.getDesc().getNumOperands()
                        ? 0 : operandWidth(MI.getDesc(), O);
        if (MI.isCopy() || MI.isPHI() || MI.isCall())
          W = 0;
        if (W != 0 && lowBitsClosed(MI.getOpcode()))
          continue;                     // reads a wider source as is
        auto [It, New] = Widths.try_emplace(MO.getReg(), W, W);
        if (!New) {
          It->second.first = std::min(It->second.first, W);
          It->second.second = std::max(It->second.second, W);
        }
        if (W != 0)
          Narrow.push_back({&MI, O});
      }

  bool Changed = false;

  // A narrowing COPY -- `trunc` -- into a narrower class. The coalescer merges
  // a copy with its source even while both are live, the value being the
  // same, and through chains of copies, so whether the source is read wider
  // cannot be told from the copy: every one becomes PSEUDO_NARROW, hinted to
  // its source's register, which it takes wherever the source dies there.
  auto width = [&](Register R) -> uint8_t {
    unsigned ID = MRI.getRegClass(R)->getID();
    return ID == CCV::GPR16RegClassID ? 1 : ID == CCV::GPR8RegClassID ? 2
         : ID == CCV::GPR4RegClassID ? 3 : 0;
  };
  // F-195: does the narrow value in D reach a 32-bit read? Only such a read
  // sees the high bits a truncation leaves, and only then must the register
  // be narrowed, so that the read's widening clears them (O-38). Copy folding
  // can re-class a register to GPR, so what counts is how each use reads it:
  // a copy is followed, and any other use is wide if its operand is 32-bit.
  // A phi keeps the narrowing.
  auto readWide = [&](Register D) {
    SmallVector<Register, 4> Work{D};
    SmallPtrSet<MachineInstr *, 8> Seen;
    while (!Work.empty()) {
      Register R = Work.pop_back_val();
      for (MachineOperand &MO : MRI.use_nodbg_operands(R)) {
        MachineInstr &U = *MO.getParent();
        if (U.isPHI())
          return true;
        if (U.isCopy()) {
          Register C = U.getOperand(0).getReg();
          if (!C.isVirtual() || width(C) < 1)
            return true;
          if (Seen.insert(&U).second)
            Work.push_back(C);
          continue;
        }
        if (operandWidth(U.getDesc(), U.getOperandNo(&MO)) == 0)
          return true;
      }
    }
    return false;
  };
  for (MachineBasicBlock &MBB : MF)
    for (MachineInstr &MI : llvm::make_early_inc_range(MBB)) {
      // A truncation (F-195) takes its source's register where it can, as a
      // narrowing COPY does below, and narrows it only if readWide says so.
      if (MI.getOpcode() == CCV::PSEUDO_TRUNC16) {
        Register D = MI.getOperand(0).getReg();
        if (MI.getOperand(1).getReg().isVirtual())
          MRI.setSimpleHint(D, MI.getOperand(1).getReg());
        if (MI.getOperand(2).getImm() && !readWide(D) && !TestTruncAlwaysNarrow)
          MI.getOperand(2).setImm(0);
      }
      if (!MI.isCopy())
        continue;
      Register D = MI.getOperand(0).getReg(), S = MI.getOperand(1).getReg();
      if (!D.isVirtual() || !S.isVirtual() || MI.getOperand(1).getSubReg() ||
          width(D) <= width(S))
        continue;
      BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(CCV::PSEUDO_NARROW), D)
          .addReg(S)
          .addImm(readWide(D) || TestTruncAlwaysNarrow ? width(D) : 0);
      MRI.setSimpleHint(D, S);
      MI.eraseFromParent();
      Changed = true;
    }

  for (auto [MI, O] : Narrow) {
    Register R = MI->getOperand(O).getReg();
    auto [Wide, Nar] = Widths[R];
    if (Wide == Nar)                    // every read at one width
      continue;
    Register N = MRI.createVirtualRegister(
        operandWidth(MI->getDesc(), O) == 1 ? &CCV::GPR16RegClass
                                            : &CCV::GPR8RegClass);
    BuildMI(*MI->getParent(), MI, MI->getDebugLoc(),
            TII->get(CCV::PSEUDO_NARROW), N)
        .addReg(R)
        .addImm(0);             // read at W by MI alone, which narrows it
    MRI.setSimpleHint(N, R);
    MI->getOperand(O).setReg(N);
    MI->getOperand(O).setIsKill(false);
    Changed = true;
  }
  return Changed;
}

} // namespace

namespace llvm {
FunctionPass *createCCVNarrowUses() { return new CCVNarrowUses(); }
} // namespace llvm
