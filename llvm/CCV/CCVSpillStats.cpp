//===- CCVSpillStats.cpp - what the register file actually spilled --------===//
//
// F-113. `gpr-count-decision.md` settled 16 GPRs and named ONE live risk:
// FP32 GEMM accumulator pressure, which is the case that gets neither
// mitigation the decision credits -- out-of-order tolerance of lower
// arithmetic intensity, and `dp4.acc` doing four MACs per accumulator
// register. It asked for spill to be measured SEPARATED BY CAUSE: accumulator
// spill, which has no mitigation, against pointer and index spill, which O-23
// already addresses.
//
// What existed instead was a total. `tools/sweep-tiles.sh` counted transfers
// through r15 -- exact, because O-30 reserves r15 and nothing else touches it
// -- and the prose beside it INFERRED the split from how the total scaled with
// TM*TN. That inference is precisely the thing the decision asked to have
// measured, and it is the kind of inference that is right until the day the
// addressing changes.
//
// This pass measures it. It runs after register allocation and before the
// frame index is resolved, so every spill still names its slot, and it
// classifies each slot by what the spilled value IS:
//
//   pointer/index  the value is used as a base or index operand of a memory
//                  instruction. Unambiguous: invariant 11 says no register
//                  holds an address, so this is the window base or an element
//                  index, and O-23's per-argument alignment attribute is the
//                  mitigation that applies to it.
//   accumulator    the value is the accumulating operand of a multiply-add or
//                  a dot product -- Format J's tied `rd_in`, or the third
//                  source of the three-address forms. This is the one the
//                  decision calls unmitigated for FP32.
//   staged operand the value came from shared memory and feeds arithmetic as a
//                  multiplicand. Neither of the two the decision names, and
//                  worth its own column rather than being folded into either:
//                  it scales with TM+TN where accumulator spill scales with
//                  TM*TN, so mixing them is what makes a total uninformative.
//
// Classification is by USE where a use exists, because a use names the role
// exactly, and by defining opcode otherwise. Address wins over accumulator:
// a value used as a base is an address whatever produced it.
//
//===----------------------------------------------------------------------===//
#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

static cl::opt<bool> ReportSpills(
    "ccv-spill-stats", cl::Hidden, cl::init(false),
    cl::desc("report spill traffic separated by cause (F-113)"));

namespace {

enum Cause { Unclassified = 0, Staged, Accumulator, Address, NumCauses };

const char *causeName(unsigned C) {
  switch (C) {
  case Address:     return "pointer/index";
  case Accumulator: return "accumulator";
  case Staged:      return "staged operand";
  default:          return "unclassified";
  }
}

/// True when operand `I` of `MI` is a memory instruction's base or index.
bool isAddressOperand(const MachineInstr &MI, unsigned I) {
  switch (MI.getOpcode()) {
  case CCV::LD_GLOBAL:      case CCV::LD_GLOBAL_W16:
  case CCV::LD_SHARED:      case CCV::LD_SHARED_W16:
  case CCV::ST_GLOBAL:      case CCV::ST_GLOBAL_W16:
  case CCV::ST_SHARED:      case CCV::ST_SHARED_W16:
  case CCV::C_LD_GLOBAL:    case CCV::C_ST_GLOBAL:
  case CCV::LD_GLOBAL_P:
    return I == 1;                       // rbase
  case CCV::LD_GLOBAL_IDX:  case CCV::LD_GLOBAL_IDX_W16:
  case CCV::ST_GLOBAL_IDX:  case CCV::ST_GLOBAL_IDX_W16:
  case CCV::LD_SHARED_IDX:  case CCV::ST_SHARED_IDX:
    return I == 1 || I == 2;             // rbase, rindex
  default:
    return false;
  }
}

/// True when operand `I` of `MI` is the ACCUMULATING operand -- the one the
/// running sum arrives on, as opposed to a multiplicand.
bool isAccumulatorOperand(const MachineInstr &MI, unsigned I) {
  switch (MI.getOpcode()) {
  case CCV::FFMA_ACC_F0: case CCV::FFMA_ACC_F1:
  case CCV::MAD_ACC:     case CCV::DP4_ACC:
  case CCV::C_FADD:
    return I == 0 || I == 1;             // rd, and the tied rd_in
  case CCV::FFMA_F0: case CCV::MADLO: case CCV::DP4_SS:
    return I == 0 || I == 3;             // rd, and the third source
  case CCV::FADD:
    return I == 0;
  default:
    return false;
  }
}

/// True when this opcode produces a value staged out of shared memory.
bool isStagedDef(const MachineInstr &MI) {
  switch (MI.getOpcode()) {
  case CCV::LD_SHARED:     case CCV::LD_SHARED_W16:
  case CCV::LD_SHARED_IDX:
    return true;
  default:
    return false;
  }
}

bool isAccumulatorDef(const MachineInstr &MI) {
  switch (MI.getOpcode()) {
  case CCV::FFMA_ACC_F0: case CCV::FFMA_ACC_F1:
  case CCV::MAD_ACC:     case CCV::DP4_ACC:
  case CCV::FFMA_F0:     case CCV::MADLO:  case CCV::DP4_SS:
  case CCV::C_FADD:      case CCV::FADD:
    return true;
  default:
    return false;
  }
}

class CCVSpillStats : public MachineFunctionPass {
public:
  static char ID;
  CCVSpillStats() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  StringRef getPassName() const override { return "CCV spill attribution"; }
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
    MachineFunctionPass::getAnalysisUsage(AU);
  }
};

/// The frame index a spill or reload names, or std::nullopt.
std::optional<int> spillSlot(const MachineInstr &MI, bool &IsStore) {
  switch (MI.getOpcode()) {
  case CCV::ST_GLOBAL: case CCV::ST_PRED_G: IsStore = true;  break;
  case CCV::LD_GLOBAL: case CCV::LD_PRED_G: IsStore = false; break;
  default: return std::nullopt;
  }
  for (const MachineOperand &MO : MI.operands())
    if (MO.isFI())
      return MO.getIndex();
  return std::nullopt;
}

bool CCVSpillStats::runOnMachineFunction(MachineFunction &MF) {
  if (!ReportSpills)
    return false;

  const TargetRegisterInfo *TRI = MF.getSubtarget().getRegisterInfo();
  DenseMap<int, unsigned> SlotCause;     // frame index -> Cause
  DenseMap<int, std::pair<unsigned, unsigned>> SlotCount;  // -> (stores, loads)

  auto raise = [&](int FI, unsigned C) {
    unsigned &Cur = SlotCause[FI];
    if (C > Cur)
      Cur = C;                           // Address > Accumulator > Staged
  };

  for (MachineBasicBlock &MBB : MF) {
    for (MachineInstr &MI : MBB) {
      bool IsStore = false;
      auto FI = spillSlot(MI, IsStore);
      if (!FI)
        continue;
      auto &N = SlotCount[*FI];
      (IsStore ? N.first : N.second)++;

      // Predicate spill is neither an address nor an accumulator, and there is
      // no third thing it could be: §3's predicate file is 4 entries and they
      // hold control-flow conditions.
      if (MI.getOpcode() == CCV::ST_PRED_G || MI.getOpcode() == CCV::LD_PRED_G)
        continue;

      Register R = MI.getOperand(0).getReg();
      if (!R.isPhysical())
        continue;

      if (!IsStore) {
        // A reload: classify by what reads the value, which names its role.
        for (auto It = std::next(MI.getIterator()); It != MBB.end(); ++It) {
          bool Redefined = false;
          for (unsigned I = 0, E = It->getNumOperands(); I != E; ++I) {
            const MachineOperand &MO = It->getOperand(I);
            if (!MO.isReg() || !MO.getReg().isPhysical() ||
                !TRI->regsOverlap(MO.getReg(), R))
              continue;
            if (MO.isUse()) {
              if (isAddressOperand(*It, I))
                raise(*FI, Address);
              else if (isAccumulatorOperand(*It, I))
                raise(*FI, Accumulator);
              else if (It->getOpcode() == CCV::FFMA_F0 ||
                       It->getOpcode() == CCV::FFMA_ACC_F0 ||
                       It->getOpcode() == CCV::DP4_SS ||
                       It->getOpcode() == CCV::DP4_ACC ||
                       It->getOpcode() == CCV::C_FMUL ||
                       It->getOpcode() == CCV::FMUL)
                raise(*FI, Staged);
            }
            if (MO.isDef())
              Redefined = true;
          }
          if (Redefined)
            break;
        }
        continue;
      }

      // A spill store: classify by what produced the value.
      for (auto It = MI.getIterator(); It != MBB.begin();) {
        --It;
        bool Defines = false;
        for (const MachineOperand &MO : It->operands())
          if (MO.isReg() && MO.isDef() && MO.getReg().isPhysical() &&
              TRI->regsOverlap(MO.getReg(), R))
            Defines = true;
        if (!Defines)
          continue;
        if (isAccumulatorDef(*It))
          raise(*FI, Accumulator);
        else if (isStagedDef(*It))
          raise(*FI, Staged);
        break;
      }
    }
  }

  unsigned St[NumCauses] = {}, Ld[NumCauses] = {};
  for (auto &[FI, N] : SlotCount) {
    unsigned C = SlotCause.count(FI) ? SlotCause[FI] : Unclassified;
    St[C] += N.first;
    Ld[C] += N.second;
  }

  errs() << "  spill by cause (F-113), " << MF.getName() << "\n";
  for (unsigned C = NumCauses; C-- > 0;)
    errs() << "    " << causeName(C) << " : " << St[C]
           << " st, " << Ld[C] << " ld\n";
  return false;
}

char CCVSpillStats::ID = 0;
} // namespace

namespace llvm {
FunctionPass *createCCVSpillStats() { return new CCVSpillStats(); }
} // namespace llvm
