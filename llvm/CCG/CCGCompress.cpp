//===-- CCGCompress.cpp - select Format K where it already fits ----------===//
//
// O-8's question is "how often can the allocator arrange rd == rs0", because
// Format K's two-operand ALU forms are 16 bits against Format A's 32 and the
// only thing standing between them is that the destination has to be the first
// source. Nothing in the backend was asking that question, let alone answering
// it: §5.5's three offset folds land on `rd == rs0` twice and miss once, by
// accident in both directions (F-29).
//
// This pass takes the free half. It runs after register allocation and rewrites
// a three-operand instruction to its compressed form ONLY when the registers it
// already has satisfy the constraint. It never inserts a copy, so it can never
// lose: every rewrite is 16 bits saved.
//
// What it deliberately does not do is make `rd == rs0` happen. Selecting the
// tied form up front would let the register allocator insert a `mov` to satisfy
// the tie, and a `mov` is 16 bits -- exactly what the compression saves, so the
// trade is a wash when the copy is needed and a loss when it also lengthens a
// live range. Biasing allocation toward the tie is the real answer and it needs
// the hit-rate data this pass collects first.
//
//===----------------------------------------------------------------------===//

#include "CCGInstrInfo.h"
#include "CCGSubtarget.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/IR/Module.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccg-compress"

STATISTIC(NumCompressed, "Format A/B instructions compressed to Format K");
STATISTIC(NumMissed,
          "three-operand ALU instructions where rd != rs0 (O-8 hit rate)");
STATISTIC(NumBitsSaved, "instruction bits saved by compression");

/// O-8 asks for a hit rate, and a release build compiles STATISTIC out, so the
/// counters are also reportable on demand. This is the instrumentation the
/// roadmap has listed as "not started" since Step 1.
static cl::opt<bool>
    ReportCompression("ccg-compress-stats",
                      cl::desc("report Format K compression hit rate"));

namespace {

/// Three-operand Format A -> two-operand destructive Format K. The compressed
/// form reads and writes rd, so it is only legal when rd is already rs0.
unsigned compressedALU(unsigned Op) {
  switch (Op) {
  case CCG::ADD:   return CCG::C_ADD;
  case CCG::SUB:   return CCG::C_SUB;
  case CCG::AND:   return CCG::C_AND;
  case CCG::OR:    return CCG::C_OR;
  case CCG::XOR:   return CCG::C_XOR;
  case CCG::ANDN:  return CCG::C_ANDN;
  case CCG::SHL:   return CCG::C_SHL;
  case CCG::SHR:   return CCG::C_SHR;
  case CCG::SRA:   return CCG::C_SRA;
  case CCG::MIN_S: return CCG::C_MIN_S;
  case CCG::MIN_U: return CCG::C_MIN_U;
  case CCG::MAX_S: return CCG::C_MAX_S;
  case CCG::MAX_U: return CCG::C_MAX_U;
  case CCG::FADD:  return CCG::C_FADD;
  case CCG::FMUL:  return CCG::C_FMUL;
  case CCG::FMIN:  return CCG::C_FMIN;
  case CCG::FMAX:  return CCG::C_FMAX;
  default:         return 0;
  }
}

/// One-source Format A -> Format K. These carry rd and rs in separate fields
/// (§3 points 15-17), so unlike the two-operand forms there is no constraint
/// to satisfy and the rewrite is unconditional.
unsigned compressedUnary(unsigned Op) {
  switch (Op) {
  case CCG::NEG: return CCG::C_NEG;
  case CCG::ABS: return CCG::C_ABS;
  default:       return 0;
  }
}

class CCGCompress : public MachineFunctionPass {
public:
  static char ID;
  CCGCompress() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  bool doFinalization(Module &M) override;
  StringRef getPassName() const override { return "CCG Format K compression"; }

  /// Counted here as well as in STATISTIC so the numbers survive a release
  /// build, which is the only kind this project builds.
  unsigned Compressed = 0, Missed = 0, Unary = 0;
};

char CCGCompress::ID = 0;

} // namespace

bool CCGCompress::runOnMachineFunction(MachineFunction &MF) {
  const auto *TII = MF.getSubtarget<CCGSubtarget>().getInstrInfo();
  bool Changed = false;

  for (MachineBasicBlock &MBB : MF) {
    for (MachineInstr &MI : make_early_inc_range(MBB)) {
      const DebugLoc &DL = MI.getDebugLoc();

      if (unsigned C = compressedUnary(MI.getOpcode())) {
        BuildMI(MBB, MI, DL, TII->get(C), MI.getOperand(0).getReg())
            .addReg(MI.getOperand(1).getReg());
        MI.eraseFromParent();
        ++NumCompressed;
        ++Unary;
        NumBitsSaved += 16;
        Changed = true;
        continue;
      }

      if (unsigned C = compressedALU(MI.getOpcode())) {
        Register Rd = MI.getOperand(0).getReg();
        Register Rs0 = MI.getOperand(1).getReg();
        Register Rs1 = MI.getOperand(2).getReg();
        if (Rd != Rs0) {
          ++NumMissed;
          ++Missed;                // O-8: the allocator did not land the tie
          continue;
        }
        BuildMI(MBB, MI, DL, TII->get(C), Rd).addReg(Rd).addReg(Rs1);
        MI.eraseFromParent();
        ++NumCompressed;
        ++Compressed;
        NumBitsSaved += 16;
        Changed = true;
        continue;
      }

      // Format B register-immediate -> Format K's 4-bit unsigned immediate
      // form, which additionally needs the immediate to fit.
      if (MI.getOpcode() == CCG::ADDI) {
        Register Rd = MI.getOperand(0).getReg();
        Register Rs0 = MI.getOperand(1).getReg();
        int64_t Imm = MI.getOperand(2).getImm();
        if (Rd != Rs0) {
          ++NumMissed;
          ++Missed;
          continue;
        }
        if (Imm < 0 || Imm > 15)
          continue;                // §3: the compressed immediate is 4 bits
        BuildMI(MBB, MI, DL, TII->get(CCG::C_ADDI), Rd).addReg(Rd).addImm(Imm);
        MI.eraseFromParent();
        ++NumCompressed;
        ++Compressed;
        NumBitsSaved += 16;
        Changed = true;
      }
    }
  }
  return Changed;
}

bool CCGCompress::doFinalization(Module &M) {
  if (!ReportCompression)
    return false;
  unsigned Tied = Compressed + Missed;
  errs() << "  Format K compression (O-8)\n"
         << "    two-operand candidates : " << Tied << "\n"
         << "    rd == rs0 already      : " << Compressed;
  if (Tied)
    errs() << "  (" << (100 * Compressed / Tied) << "%)";
  errs() << "\n    rd != rs0, missed      : " << Missed << "\n"
         << "    unary, always shrinks  : " << Unary << "\n"
         << "    bits saved             : " << 16 * (Compressed + Unary) << "\n";
  return false;
}

namespace llvm {
FunctionPass *createCCGCompress() { return new CCGCompress(); }
} // namespace llvm
