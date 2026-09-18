//===-- CCVCompress.cpp - select Format K where it already fits ----------===//
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

#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/IR/Module.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-compress"

STATISTIC(NumCompressed, "Format A/B instructions compressed to Format K");
STATISTIC(NumMissed,
          "three-operand ALU instructions where rd != rs0 (O-8 hit rate)");
STATISTIC(NumBitsSaved, "instruction bits saved by compression");

/// O-8 asks for a hit rate, and a release build compiles STATISTIC out, so the
/// counters are also reportable on demand. This is the instrumentation the
/// roadmap has listed as "not started" since Step 1.
static cl::opt<bool>
    ReportCompression("ccv-compress-stats",
                      cl::desc("report Format K compression hit rate"));

namespace {

/// Three-operand Format A -> two-operand destructive Format K. The compressed
/// form reads and writes rd, so it is only legal when rd is already rs0.
unsigned compressedALU(unsigned Op) {
  switch (Op) {
  case CCV::ADD:   return CCV::C_ADD;
  case CCV::SUB:   return CCV::C_SUB;
  case CCV::AND:   return CCV::C_AND;
  case CCV::OR:    return CCV::C_OR;
  case CCV::XOR:   return CCV::C_XOR;
  case CCV::ANDN:  return CCV::C_ANDN;
  case CCV::SHL:   return CCV::C_SHL;
  case CCV::SHR:   return CCV::C_SHR;
  case CCV::SRA:   return CCV::C_SRA;
  case CCV::MUL_LO: return CCV::C_MUL_LO;
  case CCV::MIN_S: return CCV::C_MIN_S;
  case CCV::MIN_U: return CCV::C_MIN_U;
  case CCV::MAX_S: return CCV::C_MAX_S;
  case CCV::MAX_U: return CCV::C_MAX_U;
  // FADD, FMUL, FMIN and FMAX are deliberately absent. ISel matches them to
  // the compressed form directly (O-8), so entries here could never fire --
  // dead code in a lowering table, which is how a pass quietly stops doing
  // its job. F-111 measured the alternative and it was not better; F-117.
  default:         return 0;
  }
}

/// One-source Format A -> Format K. These carry rd and rs in separate fields
/// (§3 points 15-17), so unlike the two-operand forms there is no constraint
/// to satisfy and the rewrite is unconditional.
unsigned compressedUnary(unsigned Op) {
  switch (Op) {
  case CCV::NEG: return CCV::C_NEG;
  case CCV::ABS: return CCV::C_ABS;
  default:       return 0;
  }
}

/// Format B register-immediate -> Format K's two-address `uimm4` form.
unsigned compressedALUImm(unsigned Op) {
  switch (Op) {
  case CCV::ADDI: return CCV::C_ADDI;
  case CCV::SUBI: return CCV::C_SUBI;
  case CCV::ANDI: return CCV::C_ANDI;
  case CCV::ORI:  return CCV::C_ORI;
  case CCV::XORI: return CCV::C_XORI;
  default:        return 0;
  }
}

class CCVCompress : public MachineFunctionPass {
public:
  static char ID;
  CCVCompress() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  bool doFinalization(Module &M) override;
  StringRef getPassName() const override { return "CCV Format K compression"; }

  /// Counted here as well as in STATISTIC so the numbers survive a release
  /// build, which is the only kind this project builds.
  unsigned Compressed = 0, Missed = 0, Unary = 0;
};

char CCVCompress::ID = 0;

} // namespace

bool CCVCompress::runOnMachineFunction(MachineFunction &MF) {
  const auto *TII = MF.getSubtarget<CCVSubtarget>().getInstrInfo();
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

      // Format D with a zero displacement -> Format K's memory form, which
      // carries rd and rbase in separate 4-bit fields and so has neither a tie
      // to satisfy nor an immediate to fit. Sixteen bits saved unconditionally
      // wherever the displacement is zero, and F-111's audit found the two
      // encodings defined and unreachable.
      //
      // Only the 32-bit forms. Format K has no width twin, so compressing a
      // LD_GLOBAL_W16 would move its destination out of GPR16 and take the
      // width dataflow in CCVInsertChwidth with it -- and since §3 takes
      // transfer size from that width, the result would be a four-byte
      // transfer for a two-byte element. Exactly the bug F-111 found in the
      // base+offset selection, reintroduced one pass later.
      if (MI.getOpcode() == CCV::LD_GLOBAL || MI.getOpcode() == CCV::ST_GLOBAL) {
        unsigned OffOp = MI.getOpcode() == CCV::LD_GLOBAL ? 2 : 2;
        if (MI.getOperand(OffOp).isImm() && MI.getOperand(OffOp).getImm() == 0) {
          if (MI.getOpcode() == CCV::LD_GLOBAL)
            BuildMI(MBB, MI, DL, TII->get(CCV::C_LD_GLOBAL),
                    MI.getOperand(0).getReg())
                .addReg(MI.getOperand(1).getReg());
          else
            BuildMI(MBB, MI, DL, TII->get(CCV::C_ST_GLOBAL))
                .addReg(MI.getOperand(0).getReg())
                .addReg(MI.getOperand(1).getReg());
          MI.eraseFromParent();
          ++NumCompressed;
          ++Compressed;
          NumBitsSaved += 16;
          Changed = true;
          continue;
        }
      }

      // Format B register-immediate -> Format K's 4-bit unsigned immediate
      // form, which additionally needs the immediate to fit. This handled only
      // `addi` until F-111's audit: C_SUBI, C_ANDI, C_ORI and C_XORI were
      // defined, encodable and unreachable. The shift forms are absent on
      // purpose -- CCVInstrPatterns.td selects C_SHLI/C_SHRI/C_SRAI directly,
      // so anything still wearing the Format B opcode here has an immediate
      // over 15 and would not fit anyway.
      if (unsigned C = compressedALUImm(MI.getOpcode())) {
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
        BuildMI(MBB, MI, DL, TII->get(C), Rd).addReg(Rd).addImm(Imm);
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

bool CCVCompress::doFinalization(Module &M) {
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
FunctionPass *createCCVCompress() { return new CCVCompress(); }
} // namespace llvm
