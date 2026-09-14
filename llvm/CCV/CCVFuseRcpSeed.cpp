//===-- CCVFuseRcpSeed.cpp - fold the fp32 reciprocal seed into rcp.u32 ---===//
//
// O-31's integer division opens by computing an integer reciprocal seed through
// floating point, because §4 had no integer reciprocal:
//
//     cvt.f32.u32  t, d
//     rcp.f32      t, t
//     f48          k, 0x4F7FFFFE      ; 2^32(1 - 2^-23)
//     fmul         t, k
//     cvt.u32.f32  e, t
//
// Five instructions to produce what O-35's `rcp.u32` produces in one. The fp32
// round trip was never about precision -- tools/model-rcp.py shows the sequence
// needs 16 bits of reciprocal and fp32 supplies about 23 -- it was about the
// absence of an instruction.
//
// WHY THIS MATCHES MACHINE INSTRUCTIONS RATHER THAN IR. The shape is emitted by
// CCVExpandDivision, an IR pass, so it could be matched there. Doing it after
// instruction selection instead means the middle end has already run and cannot
// reassociate the idiom out from under the matcher, and -- more importantly --
// a failure to match is not a correctness problem. The fp32 sequence stands and
// computes the same answer, four instructions more slowly. An optimisation that
// cannot be wrong is worth the slightly awkward placement.
//
//===----------------------------------------------------------------------===//

#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/Debug.h"
#include <array>
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-fuse-rcp"

namespace {

/// 2^32(1 - 2^-23), O-31's scale constant. The one bit pattern that identifies
/// this idiom rather than an ordinary multiply.
constexpr uint64_t kSeedScale = 0x4F7FFFFEull;

class CCVFuseRcpSeed : public MachineFunctionPass {
public:
  static char ID;
  CCVFuseRcpSeed() : MachineFunctionPass(ID) {}

  StringRef getPassName() const override { return "CCV fuse rcp.u32 seed"; }

  bool runOnMachineFunction(MachineFunction &MF) override {
    MachineRegisterInfo &MRI = MF.getRegInfo();
    // The matched fp32 chain per fusion site, so it can be collected after the
    // replacement rather than left for a DCE that does not run.
    SmallVector<std::array<MachineInstr *, 4>, 4> Chain;
    unsigned Erased = 0;
    const TargetInstrInfo *TII = MF.getSubtarget().getInstrInfo();

    /// The unique defining instruction of a virtual register, if it has one.
    auto def = [&](const MachineOperand &MO) -> MachineInstr * {
      if (!MO.isReg() || !MO.getReg().isVirtual())
        return nullptr;
      return MRI.getUniqueVRegDef(MO.getReg());
    };
    auto isOpc = [](MachineInstr *MI, unsigned Op) {
      return MI && MI->getOpcode() == Op;
    };

    SmallVector<std::pair<MachineInstr *, Register>, 4> Found;
    for (MachineBasicBlock &MBB : MF) {
      for (MachineInstr &MI : MBB) {
        if (MI.getOpcode() != CCV::CVT_U32_F32)
          continue;
        MachineInstr *Mul = def(MI.getOperand(1));
        // Either tier of multiply. Instruction selection picks the compressed
        // Format K form directly when `rd == rs0` falls out, which it does
        // here, so matching only the 32-bit FMUL matched nothing at all.
        if (!isOpc(Mul, CCV::FMUL) && !isOpc(Mul, CCV::C_FMUL))
          continue;

        // Find the scale constant and the reciprocal among the multiply's
        // register uses, without assuming operand positions -- the two tiers
        // number them differently and C_FMUL ties its first source to `rd`.
        MachineInstr *Scale = nullptr, *Rcp = nullptr;
        (void)Chain;
        for (const MachineOperand &MO : Mul->uses()) {
          MachineInstr *D = def(MO);
          if (isOpc(D, CCV::MOVI48) && D->getOperand(1).isImm() &&
              uint64_t(D->getOperand(1).getImm()) == kSeedScale)
            Scale = D;
          else if (isOpc(D, CCV::RCP_F32))
            Rcp = D;
        }
        if (!Scale || !Rcp)
          continue;

        MachineInstr *Cvt = def(Rcp->getOperand(1));
        if (!isOpc(Cvt, CCV::CVT_F32_U32))
          continue;

        Found.emplace_back(&MI, Cvt->getOperand(1).getReg());
        Chain.push_back({Mul, Rcp, Cvt, Scale});
      }
    }

    for (auto [MI, Divisor] : Found) {
      BuildMI(*MI->getParent(), *MI, MI->getDebugLoc(),
              TII->get(CCV::RCP_U32), MI->getOperand(0).getReg())
          .addReg(Divisor)
          .addReg(Divisor)          // rs1, unread
          .addReg(Divisor);         // rs2, unread
      MI->eraseFromParent();
    }

    // Erase the fp32 chain this replaced.
    //
    // It used to be left for "the generic dead-machine-instr elimination that
    // follows", on the reasoning that the scale constant may be shared between
    // two divisions and deciding that by hand is how CCVWindowRemat produced a
    // use-after-free (F-47). The caution was right and the conclusion was
    // wrong: no DCE removed them, and `transpose` carried a dead
    // `cvt.f32.u32` + `rcp.f32` pair for every division it contains. Neither
    // is marked with side effects, so nothing was protecting them -- they
    // simply outlived the pass that was supposed to collect them.
    //
    // Sharing is decided by MachineRegisterInfo rather than by hand, which is
    // what makes this safe where the hand version was not: this runs pre-RA on
    // SSA virtual registers, so `use_empty` after the replacement is exactly
    // the question "is anything still reading this". A shared scale constant
    // has a remaining use and stays. Repeat to a fixpoint so erasing the
    // multiply exposes its operands.
    bool Again = true;
    while (Again) {
      Again = false;
      for (auto &C : Chain)
        for (MachineInstr *&I : C) {
          if (!I || I->getNumOperands() == 0 || !I->getOperand(0).isReg() ||
              !I->getOperand(0).isDef())
            continue;
          Register R = I->getOperand(0).getReg();
          if (!R.isVirtual() || !MRI.use_nodbg_empty(R))
            continue;
          I->eraseFromParent();
          I = nullptr;
          ++Erased;
          Again = true;
        }
    }
    return !Found.empty();
  }
};

} // namespace

char CCVFuseRcpSeed::ID = 0;

namespace llvm {
FunctionPass *createCCVFuseRcpSeed() { return new CCVFuseRcpSeed(); }
} // namespace llvm
