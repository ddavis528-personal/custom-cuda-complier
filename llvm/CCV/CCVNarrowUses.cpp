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
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

using namespace llvm;

namespace llvm {
uint8_t operandWidth(const MCInstrDesc &D, unsigned OpNo);
bool lowBitsClosed(unsigned Op);
bool ccvTestNarrowInPlace();   // -ccv-test-narrow-in-place, CCVInsertChwidth's
} // namespace llvm

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
    return ID == CCV::GPR16RegClassID ? 1 : ID == CCV::GPR8RegClassID ? 2 : 0;
  };
  for (MachineBasicBlock &MBB : MF)
    for (MachineInstr &MI : llvm::make_early_inc_range(MBB)) {
      if (!MI.isCopy())
        continue;
      Register D = MI.getOperand(0).getReg(), S = MI.getOperand(1).getReg();
      if (!D.isVirtual() || !S.isVirtual() || MI.getOperand(1).getSubReg() ||
          width(D) <= width(S))
        continue;
      BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(CCV::PSEUDO_NARROW), D)
          .addReg(S);
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
        .addReg(R);
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
