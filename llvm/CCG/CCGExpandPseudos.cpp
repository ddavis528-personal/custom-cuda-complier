//===-- CCGExpandPseudos.cpp - lower codegen pseudos ---------------------===//
//
// Runs after register allocation, when every predicate has a physical register.
// Turns the codegen pseudos into real instructions, which is where a predicate
// REGISTER becomes a qualifier IMMEDIATE: §3 encodes the qualifier at [29:27]
// as a 2-bit address plus a negate bit, but register allocation has to see a
// register, so the two representations meet here.
//
//===----------------------------------------------------------------------===//

#include "CCGInstrInfo.h"
#include "CCGSubtarget.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/InitializePasses.h"

using namespace llvm;

#define DEBUG_TYPE "ccg-expand-pseudos"

namespace {

/// §1: a predicate qualifier is a 2-bit address plus a negate bit at bit 2.
unsigned qualFor(Register R, bool Negate) {
  assert(R >= CCG::P0 && R <= CCG::P3 && "not a predicate register");
  return (R - CCG::P0) | (Negate ? 4u : 0u);
}

class CCGExpandPseudos : public MachineFunctionPass {
public:
  static char ID;
  CCGExpandPseudos() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  StringRef getPassName() const override { return "CCG pseudo expansion"; }
};

char CCGExpandPseudos::ID = 0;

} // namespace

bool CCGExpandPseudos::runOnMachineFunction(MachineFunction &MF) {
  const auto *TII = MF.getSubtarget<CCGSubtarget>().getInstrInfo();
  bool Changed = false;

  for (MachineBasicBlock &MBB : MF) {
    for (MachineInstr &MI : llvm::make_early_inc_range(MBB)) {
      const DebugLoc &DL = MI.getDebugLoc();
      switch (MI.getOpcode()) {

      case CCG::PSEUDO_PTRUE: {
        // O-24: `por pd, !pd, pd` is all-ones whatever pd holds, in 16 bits.
        // Compressed forms are never predicated, which is what breaks the
        // bootstrap cycle -- a compare cannot manufacture its own guard.
        Register Pd = MI.getOperand(0).getReg();
        BuildMI(MBB, MI, DL, TII->get(CCG::POR), Pd)
            .addImm(qualFor(Pd, /*Negate=*/true))
            .addImm(qualFor(Pd, /*Negate=*/false));
        break;
      }

      case CCG::PSEUDO_SETP_LT:
      case CCG::PSEUDO_SETP_LE:
      case CCG::PSEUDO_SETP_EQ:
      case CCG::PSEUDO_SETP_NE: {
        // The guard is tied to the destination, so this is the self-guarding
        // form: the compare reads the predicate it is about to overwrite.
        Register Pd = MI.getOperand(0).getReg();
        Register Guard = MI.getOperand(1).getReg();
        assert(Pd == Guard && "tie should have forced guard == destination");
        unsigned Opc;
        switch (MI.getOpcode()) {
        case CCG::PSEUDO_SETP_LT: Opc = CCG::SETP_LT; break;
        case CCG::PSEUDO_SETP_LE: Opc = CCG::SETP_LE; break;
        case CCG::PSEUDO_SETP_EQ: Opc = CCG::SETP_EQ; break;
        default:                  Opc = CCG::SETP_NE; break;
        }
        BuildMI(MBB, MI, DL, TII->get(Opc))
            .addReg(Pd, RegState::Define)
            .addReg(CCG::R0, RegState::Undef) // rd: allocated, opcode selects
                                              // whether it is written (§3)
            .addImm(qualFor(Guard, /*Negate=*/false))
            .add(MI.getOperand(2))
            .add(MI.getOperand(3));
        break;
      }

      case CCG::PSEUDO_BRA_PRED: {
        Register Guard = MI.getOperand(0).getReg();
        bool Neg = MI.getOperand(1).getImm() != 0;
        BuildMI(MBB, MI, DL, TII->get(CCG::BRA_PRED))
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
FunctionPass *createCCGExpandPseudos() { return new CCGExpandPseudos(); }
} // namespace llvm
