//===-- CCVExpandPseudos.cpp - lower codegen pseudos ---------------------===//
//
// Runs after register allocation, when every predicate has a physical register.
// Turns the codegen pseudos into real instructions, which is where a predicate
// REGISTER becomes a qualifier IMMEDIATE: §3 encodes the qualifier at [29:27]
// as a 2-bit address plus a negate bit, but register allocation has to see a
// register, so the two representations meet here.
//
//===----------------------------------------------------------------------===//

#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/InitializePasses.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-expand-pseudos"

namespace {

/// §1: a predicate qualifier is a 2-bit address plus a negate bit at bit 2.
unsigned qualFor(Register R, bool Negate) {
  assert(R >= CCV::P0 && R <= CCV::P3 && "not a predicate register");
  return (R - CCV::P0) | (Negate ? 4u : 0u);
}

class CCVExpandPseudos : public MachineFunctionPass {
public:
  static char ID;
  CCVExpandPseudos() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  StringRef getPassName() const override { return "CCV pseudo expansion"; }
};

char CCVExpandPseudos::ID = 0;

} // namespace

bool CCVExpandPseudos::runOnMachineFunction(MachineFunction &MF) {
  const auto *TII = MF.getSubtarget<CCVSubtarget>().getInstrInfo();
  bool Changed = false;

  for (MachineBasicBlock &MBB : MF) {
    for (MachineInstr &MI : llvm::make_early_inc_range(MBB)) {
      const DebugLoc &DL = MI.getDebugLoc();
      switch (MI.getOpcode()) {

      case CCV::PSEUDO_PAND:
      case CCV::PSEUDO_POR:
      case CCV::PSEUDO_PXOR: {
        unsigned Opc = MI.getOpcode() == CCV::PSEUDO_PAND ? CCV::PAND
                       : MI.getOpcode() == CCV::PSEUDO_POR ? CCV::POR
                                                           : CCV::PXOR;
        BuildMI(MBB, MI, DL, TII->get(Opc), MI.getOperand(0).getReg())
            .addImm(qualFor(MI.getOperand(1).getReg(), /*Negate=*/false))
            .addImm(qualFor(MI.getOperand(2).getReg(), /*Negate=*/false));
        break;
      }

      case CCV::PSEUDO_BCAST: {
        // Lanes 1-31 read lane 0's copy; lane 0 is excluded by the NEGATED
        // qualifier and keeps its own value (invariant 10), which is what
        // makes one instruction a complete broadcast. rd and rs0 are the same
        // register -- the tie guaranteed that.
        Register Rd = MI.getOperand(0).getReg();
        BuildMI(MBB, MI, DL, TII->get(CCV::SHFL_IDX), Rd)
            .addImm(qualFor(CCV::P3, /*Negate=*/true))
            .addReg(Rd)
            .addImm(0);
        break;
      }

      case CCV::PSEUDO_PMOV: {
        // operands: rd(tied), false, cond, a  ->  @cond mov rd, a
        // rs1 is unread by `mov`; tie it to rs0 rather than leave a third
        // register live, as the other Format A′ forms do.
        BuildMI(MBB, MI, DL, TII->get(CCV::MOV_P), MI.getOperand(0).getReg())
            .add(MI.getOperand(1))                                   // $false
            .addImm(qualFor(MI.getOperand(2).getReg(), /*Negate=*/false))
            .add(MI.getOperand(3))                                   // rs0 = a
            .add(MI.getOperand(3))                                   // rs1, unread
            .add(MI.getOperand(3));                                  // rs2, unread
        break;
      }

      case CCV::PSEUDO_BRA_PRED: {
        Register Guard = MI.getOperand(0).getReg();
        bool Neg = MI.getOperand(1).getImm() != 0;
        BuildMI(MBB, MI, DL, TII->get(CCV::BRA_PRED))
            .addImm(qualFor(Guard, Neg))
            .add(MI.getOperand(2));
        break;
      }

      default:
        continue;
      }
      MI.eraseFromParent();
      Changed = true;
    }
  }
  return Changed;
}

namespace llvm {
FunctionPass *createCCVExpandPseudos() { return new CCVExpandPseudos(); }
} // namespace llvm
