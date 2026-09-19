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
//   warp-uniform   the value is the same in all 32 lanes, established
//                  structurally rather than inferred. Three shapes qualify: a
//                  read of the launch block (§5.2), which is CTA-wide and
//                  read-only for the kernel's lifetime; `srd %ctaid`, which is
//                  the CTA index; and O-33's broadcast pseudo, which exists
//                  precisely to distribute a value the masking pass has already
//                  proved uniform. Nothing else is counted here, so the column
//                  is a floor on uniform spill and not an estimate of it.
//
//                  This column was added when the real fused-kernel corpus
//                  (F-143) put every one of its spills in `unclassified`.
//                  `unclassified` is where a measurement goes to stop being
//                  evidence, and the residual turned out to be the most
//                  decisive quantity in the register-file question: after O-45
//                  removed the window bases from the register file, what real
//                  fused kernels spill is warp-uniform SCALARS. Neither of the
//                  two previous arguments for a warp-uniform register file --
//                  GEMM accumulators (divergent) and GEMM window bases (O-45,
//                  now gone) -- named that.
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
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

static cl::opt<bool> ReportSpills(
    "ccv-spill-stats", cl::Hidden, cl::init(false),
    cl::desc("report spill traffic separated by cause (F-113)"));

namespace {

enum Cause { Unclassified = 0, Staged, Uniform, Accumulator, Address,
             NumCauses };

const char *causeName(unsigned C) {
  switch (C) {
  case Address:      return "pointer/index";
  case Accumulator:  return "accumulator";
  case Uniform:      return "warp-uniform";
  case Staged:       return "staged operand";
  default:           return "unclassified";
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

/// The window index of the launch block: §5.2 puts it at a fixed architectural
/// address, and the prologue materialises that address as `movi rN, <window>`.
/// This is a FIFTH copy of a constant the other four already have to agree on,
/// and tools/check-launch-abi.sh checks this one with them.
static constexpr unsigned kLaunchWindow = 0x20000 >> 16;

/// True when this instruction defines a value that is the same in all 32 lanes.
///
/// Each of the three cases is structural, not inferred:
///
///   - a Format D base+displacement load whose base register was materialised
///     by `movi` with the launch-block window. §5.2 makes the whole block
///     read-only and CTA-wide, so anything read from it is warp-uniform. The
///     base is checked rather than assumed, because `[rN + imm]` is also how a
///     DATA pointer's element zero is reached, and that is not uniform at all.
///   - `srd %ctaid` (selector 1). Selector 0 is `%ctatid`, which is per-lane;
///     confusing the two would report the thread index as uniform.
///   - O-33's broadcast pseudo. The masking pass emits it only for a value it
///     has proved warp-uniform -- that is the pass's entire contract -- so the
///     broadcast is the strongest evidence available, not the weakest.
bool isUniformDef(const MachineInstr &MI, const MachineBasicBlock &MBB) {
  switch (MI.getOpcode()) {
  case CCV::PSEUDO_BCAST:
    return true;
  case CCV::SRD:
    return MI.getOperand(1).getImm() == 1;              // %ctaid, not %ctatid
  case CCV::LD_GLOBAL: case CCV::LD_GLOBAL_W16: case CCV::C_LD_GLOBAL:
  case CCV::LD_GLOBAL_P:
    break;
  default:
    return false;
  }
  // Find the base operand and walk back to whatever defined it.
  unsigned BaseOp = MI.getOpcode() == CCV::LD_GLOBAL_P ? 2 : 1;
  if (BaseOp >= MI.getNumOperands() || !MI.getOperand(BaseOp).isReg())
    return false;
  Register B = MI.getOperand(BaseOp).getReg();
  for (auto It = MI.getIterator(); It != MBB.begin();) {
    --It;
    for (const MachineOperand &MO : It->operands())
      if (MO.isReg() && MO.isDef() && MO.getReg() == B)
        return It->getOpcode() == CCV::MOVI &&
               It->getOperand(1).isImm() &&
               It->getOperand(1).getImm() == kLaunchWindow;
  }
  return false;
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

/// Every definition of physical register `R` that can reach `At` in `MBB`.
///
/// Backwards within the block first; on reaching the top without a definition,
/// on through the predecessors, with a visited set so a loop back edge is
/// followed once. Bounded by the block count, which is what makes it safe to
/// run on every spill store.
void reachingDefs(const MachineBasicBlock &MBB,
                  MachineBasicBlock::const_iterator At, Register R,
                  const TargetRegisterInfo *TRI,
                  SmallVectorImpl<const MachineInstr *> &Out,
                  SmallPtrSetImpl<const MachineBasicBlock *> *Seen = nullptr) {
  SmallPtrSet<const MachineBasicBlock *, 8> Local;
  if (!Seen)
    Seen = &Local;
  for (auto It = At; It != MBB.begin();) {
    --It;
    for (const MachineOperand &MO : It->operands())
      if (MO.isReg() && MO.isDef() && MO.getReg().isPhysical() &&
          TRI->regsOverlap(MO.getReg(), R)) {
        Out.push_back(&*It);
        return;
      }
  }
  for (const MachineBasicBlock *P : MBB.predecessors())
    if (Seen->insert(P).second)
      reachingDefs(*P, P->end(), R, TRI, Out, Seen);
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
      Cur = C;                 // Address > Accumulator > Uniform > Staged
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
      //
      // The def is not always in this block. A value spilled inside a loop was
      // very often computed in the preheader and arrives as a live-in, and the
      // first version of this walk stopped at the block boundary and gave up --
      // which put four of `attn_combine`'s five spill slots in `unclassified`
      // and two of `rope`'s seven. So the search follows predecessors, and
      // classifies only when EVERY reaching definition agrees. Disagreement
      // stays unclassified rather than being resolved by a rule, because a slot
      // reached by an accumulator on one path and a uniform scalar on another
      // is not evidence about either.
      SmallVector<const MachineInstr *, 4> Defs;
      reachingDefs(MBB, MachineBasicBlock::const_iterator(&MI), R, TRI, Defs);
      if (Defs.empty())
        continue;
      auto all = [&](bool (*P)(const MachineInstr &)) {
        return llvm::all_of(Defs, [&](const MachineInstr *D) { return P(*D); });
      };
      if (all(isAccumulatorDef))
        raise(*FI, Accumulator);
      else if (llvm::all_of(Defs, [&](const MachineInstr *D) {
                 return isUniformDef(*D, *D->getParent());
               }))
        raise(*FI, Uniform);
      else if (all(isStagedDef))
        raise(*FI, Staged);
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
