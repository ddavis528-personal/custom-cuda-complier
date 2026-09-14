//===-- CCVUniformity.cpp - how much work is warp-redundant? --------------===//
//
// O-25 named this as the evidence that would size a warp-uniform register file,
// and F-52 turned it from an argument into a measurement: AMD computes the
// transpose kernel's divisor once on the scalar unit while CCV recomputes it in
// all 32 lanes.
//
// Two numbers come out, and they size two different things:
//
//   - The fraction of INSTRUCTIONS that are warp-uniform. Multiplied by 31/32,
//     that is the lane-activation energy spent computing the same value 32
//     times. It sizes the scalar-execution opportunity.
//
//   - The peak number of uniform values SIMULTANEOUSLY LIVE. That is what a
//     uniform register file would have to hold, and it is the number §1's
//     "16-entry uniform file" was guessed at without.
//
//===----------------------------------------------------------------------===//

#include "llvm/Analysis/PostDominators.h"
#include "llvm/Analysis/UniformityAnalysis.h"
#include "llvm/ADT/DenseSet.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/IntrinsicsNVPTX.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/InitializePasses.h"
#include "llvm/Support/raw_ostream.h"
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace llvm;

#define DEBUG_TYPE "ccv-uniformity"

static cl::opt<bool>
    ReportUniformity("ccv-uniformity-stats",
                     cl::desc("report warp-uniform instruction and liveness "
                              "counts (O-25)"));

namespace {

/// Does this instruction represent work the machine performs? Casts that are
/// free here (a zext feeding an addressing mode) and metadata are not.
bool isRealWork(const Instruction &I) {
  if (I.isTerminator() && isa<ReturnInst>(I))
    return false;
  if (isa<PHINode>(I) || I.isDebugOrPseudoInst())
    return false;
  // Markers and assumptions emit nothing.
  if (const auto *II = dyn_cast<IntrinsicInst>(&I))
    if (II->isLifetimeStartOrEnd() || II->isAssumeLikeIntrinsic())
      return false;
  // zext/trunc between i32 and i64 exist only because LLVM's pointer type is
  // 64 bits; §5.1 keeps that out of registers entirely, so they cost nothing.
  if (isa<ZExtInst>(I) || isa<TruncInst>(I) || isa<SExtInst>(I))
    return false;
  // A getelementptr is not an instruction either: §5.1's addressing mode does
  // base + index + displacement in the AGU, so the GEP folds into the access
  // it feeds and costs nothing of its own.
  if (isa<GetElementPtrInst>(I) || isa<IntToPtrInst>(I) || isa<PtrToIntInst>(I))
    return false;
  return true;
}

/// Blocks that every lane of the warp reaches together.
///
/// This is the safety condition for masking work to lane 0, and it is NOT the
/// same as the instruction being uniform. A uniform `add` inside a
/// divergently-reached block is still uniform -- all lanes that run it compute
/// the same answer -- but lane 0 might not be one of them, and masking it there
/// would leave the broadcast reading a value nobody computed.
///
/// A block is divergently reached exactly when it is control-dependent on a
/// divergent branch, which is what the post-dominator walk below computes.
void findUniformlyReached(Function &F, UniformityInfo &UI,
                          const PostDominatorTree &PDT,
                          DenseSet<const BasicBlock *> &Out) {
  DenseSet<const BasicBlock *> Divergent;
  for (BasicBlock &P : F) {
    if (P.getTerminator()->getNumSuccessors() < 2)
      continue;
    if (!UI.hasDivergentTerminator(P))
      continue;
    // Everything control-dependent on this branch: walk up the post-dominator
    // tree from each successor until the branch's own immediate post-dominator.
    DomTreeNode *Stop = PDT.getNode(&P) ? PDT.getNode(&P)->getIDom() : nullptr;
    for (BasicBlock *S : successors(&P))
      for (DomTreeNode *N = PDT.getNode(S); N && N != Stop; N = N->getIDom())
        if (N->getBlock())
          Divergent.insert(N->getBlock());
  }
  for (BasicBlock &B : F)
    if (!Divergent.count(&B))
      Out.insert(&B);
}

/// Why an instruction can or cannot be masked to lane 0.
///
/// This used to be a single `isPredicable` returning bool, with a `default:
/// return false` catch-all, and everything that fell through was reported as
/// "blocked: encoding (§4 128+/256+ have no A′ form)". That label was a claim
/// about the ISA, and the bucket it labelled was mostly not about the ISA at
/// all -- branches and stores landed in it, and F-56 was sized off the total.
/// The buckets below are separate because their fixes are separate: an opcode
/// range is a spec change, a missing `_P` twin is an afternoon in the .td, a
/// contended field is a format change, and an unmodelled opcode is a hole in
/// THIS report that must never again read as a fact about the machine.
enum class Mask {
  Yes,
  /// §4 puts the operation at point 128 or above. Format A′'s opcode is seven
  /// bits, so it is Format A only and cannot carry a qualifier. This is F-56,
  /// and it is the only bucket that is evidence for it.
  NoPredForm,
  /// The ISA gives it a predicated encoding; CCVInstrInfo.td has no `_P` twin
  /// yet. Costs the same lane-activations as NoPredForm and is fixed here, not
  /// in the spec -- which is exactly why it must not be counted as F-56.
  NoMIForm,
  /// The operation has no 32-bit encoding at all. `srd` is the case: §3 puts
  /// it at Format K point 28 because its content is an opcode and a
  /// destination, and invariant 7 requires the 16-bit form when the content
  /// fits. Format K has no qualifier field, so this is unmaskable by a design
  /// rule rather than by an opcode-range accident -- and unlike F-56 it is not
  /// a mistake to fix.
  NoLongForm,
  /// Masking would change what the kernel does. Barriers are the case: a
  /// barrier reached by all 32 lanes and arrived at by one is a hang.
  Semantics,
  /// The predicate qualifier field is already carrying data for this opcode,
  /// so there is nowhere to put a mask. `sel` is the case: §4 point 19 reads
  /// `[29:27]` as the selector, not as an execution condition.
  QualifierTaken,
  /// Branches. Predication is not the mechanism they would need, and a warp
  /// executing a uniform branch is not redundant work in the sense being
  /// counted -- every lane has its own PC.
  ControlFlow,
  /// This report does not know. Printed with its opcode name so that a hole
  /// here is visible as a hole rather than as an encoding limit.
  Unmodelled,
};

/// §4 point 35 (`ffma.f0`) is inside A′'s reach, but FpRRP only covers
/// fadd/fsub/fmul, so the fused form is an MI-level gap rather than an
/// encoding one. Kept in one place so the two facts stay distinguishable.
Mask classifyIntrinsic(Intrinsic::ID ID) {
  switch (ID) {
  case Intrinsic::fma:
  case Intrinsic::fmuladd:
    return Mask::NoMIForm;          // point 35, FpRRP stops at fmul
  case Intrinsic::ctpop:
  case Intrinsic::ctlz:
  case Intrinsic::bitreverse:
  case Intrinsic::abs:
    return Mask::NoMIForm;          // points 20-24, AluR has no `_P` twin
  case Intrinsic::smin: case Intrinsic::smax:
  case Intrinsic::umin: case Intrinsic::umax:
    return Mask::Yes;               // points 14-17, AluRRP covers all four
  case Intrinsic::sqrt:
  case Intrinsic::exp2:
  case Intrinsic::log2:
  case Intrinsic::sin:
  case Intrinsic::cos:
    return Mask::NoPredForm;        // SFU, §4 256+ -- F-56
  // §5.3: thread and CTA identity select to `srd`, Format K point 28.
  case Intrinsic::nvvm_read_ptx_sreg_tid_x:
  case Intrinsic::nvvm_read_ptx_sreg_tid_y:
  case Intrinsic::nvvm_read_ptx_sreg_tid_z:
  case Intrinsic::nvvm_read_ptx_sreg_ctaid_x:
  case Intrinsic::nvvm_read_ptx_sreg_ctaid_y:
  case Intrinsic::nvvm_read_ptx_sreg_ctaid_z:
  case Intrinsic::nvvm_read_ptx_sreg_laneid:
    return Mask::NoLongForm;
  // ntid/nctaid come from the launch block and are already loads by the time
  // this runs (§5.3). If one survives as a call the lowering did not fire,
  // which is worth seeing rather than bucketing.
  case Intrinsic::nvvm_barrier0:
    return Mask::Semantics;
  default:
    return Mask::Unmodelled;
  }
}

Mask classify(const Instruction &I) {
  if (const auto *CI = dyn_cast<CallInst>(&I)) {
    if (Function *F = CI->getCalledFunction())
      if (Intrinsic::ID ID = F->getIntrinsicID())
        return classifyIntrinsic(ID);
    return Mask::Unmodelled;
  }
  switch (I.getOpcode()) {
  // Points 0-25 and 32-63, all with `_P` twins in CCVInstrInfo.td. `mul`
  // selects to MADLO (point 5), which has MADLO_P.
  case Instruction::Add:  case Instruction::Sub:  case Instruction::Mul:
  case Instruction::And:  case Instruction::Or:   case Instruction::Xor:
  case Instruction::Shl:  case Instruction::LShr: case Instruction::AShr:
  case Instruction::FAdd: case Instruction::FSub: case Instruction::FMul:
    return Mask::Yes;
  // Formats C and C′ carry a MANDATORY qualifier (O-32 added C″ to escape it),
  // so a compare is masked by setting that qualifier rather than by needing a
  // new form.
  case Instruction::ICmp: case Instruction::FCmp:
    return Mask::Yes;
  // Format D′ exists and LD_GLOBAL_P is defined. Whether a particular load
  // fits is an offset question -- D′ narrows the displacement from 13 bits to
  // 10 -- and the offset is not formed yet at IR level, so this over-counts by
  // however many loads have a displacement above 511. Launch-block offsets are
  // tens of bytes; CCVMaskUniform does the real check.
  case Instruction::Load:
    return Mask::Yes;
  // D′ opcode `00001` is `st.global` predicated, so the ISA allows this. The
  // .td has no ST_GLOBAL_P, which is why it does not happen.
  case Instruction::Store:
    return Mask::NoMIForm;
  // §4 point 19: the qualifier is the selector. See SEL in CCVInstrInfo.td.
  case Instruction::Select:
    return Mask::QualifierTaken;
  // THE F-56 BUCKET. Conversions are §4 128+, `rcp` is 256.
  case Instruction::UIToFP: case Instruction::SIToFP:
  case Instruction::FPToUI: case Instruction::FPToSI:
  case Instruction::FDiv:
    return Mask::NoPredForm;
  case Instruction::Br: case Instruction::Switch: case Instruction::IndirectBr:
    return Mask::ControlFlow;
  default:
    return Mask::Unmodelled;
  }
}

class CCVUniformity : public FunctionPass {
public:
  static char ID;
  CCVUniformity() : FunctionPass(ID) {
    // Registered here rather than through INITIALIZE_PASS, which wants a
    // generated initializer for every dependency and gives nothing back for
    // an out-of-tree pass that is never referenced by name.
    initializeUniformityInfoWrapperPassPass(*PassRegistry::getPassRegistry());
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<UniformityInfoWrapperPass>();
    AU.setPreservesAll();
  }

  bool runOnFunction(Function &F) override {
    if (!ReportUniformity || F.isDeclaration())
      return false;
    UniformityInfo &UI =
        getAnalysis<UniformityInfoWrapperPass>().getUniformityInfo();

    PostDominatorTree PDT(F);
    DenseSet<const BasicBlock *> UniformReach;
    findUniformlyReached(F, UI, PDT, UniformReach);

    unsigned Total = 0, Uniform = 0, Maskable = 0, Crossings = 0;
    unsigned Blocked[8] = {};   // indexed by Mask
    // Opcode names behind the Unmodelled bucket, so a gap in this report
    // announces itself instead of inflating whichever bucket it fell into.
    std::map<std::string, unsigned> Unknown;

    auto maskable = [&](const Instruction *I) {
      return I && isRealWork(*I) && !UI.isDivergent(I) &&
             UniformReach.count(I->getParent()) && classify(*I) == Mask::Yes;
    };

    for (Instruction &I : instructions(F)) {
      if (!isRealWork(I))
        continue;
      ++Total;
      if (UI.isDivergent(&I))
        continue;
      ++Uniform;
      if (!UniformReach.count(I.getParent())) { ++Blocked[unsigned(Mask::ControlFlow)]; continue; }
      Mask M = classify(I);
      if (M != Mask::Yes) {
        ++Blocked[unsigned(M)];
        if (M == Mask::Unmodelled)
          ++Unknown[I.getOpcodeName()];
        continue;
      }
      ++Maskable;
      // One broadcast per value that leaves the masked region. Values consumed
      // only by other masked instructions need none -- which is what makes
      // regions pay and single instructions not.
      for (const User *U : I.users())
        if (!maskable(dyn_cast<Instruction>(U))) { ++Crossings; break; }
    }

    // Peak simultaneously-live uniform values, over a linear walk. A real
    // allocator sees the CFG; this is a lower bound on what a uniform file
    // would need, computed the same way for every kernel so the numbers
    // compare.
    unsigned Peak = 0;
    std::vector<Instruction *> Order;
    for (Instruction &I : instructions(F))
      Order.push_back(&I);
    for (unsigned At = 0; At != Order.size(); ++At) {
      unsigned Live = 0;
      for (unsigned D = 0; D <= At; ++D) {
        Instruction *Def = Order[D];
        if (Def->getType()->isVoidTy() || UI.isDivergent(Def))
          continue;
        for (const User *U : Def->users())
          if (const auto *U2 = dyn_cast<Instruction>(U)) {
            auto It = std::find(Order.begin() + At, Order.end(), U2);
            if (It != Order.end()) { ++Live; break; }
          }
      }
      Peak = std::max(Peak, Live);
    }

    // Each masked instruction saves 31 lane-activations; each broadcast costs
    // 31 (lanes 1-31 are the ones that read). So the scheme pays exactly when
    // masked work exceeds crossings.
    int Net = int(Maskable) - int(Crossings);

    errs() << "  warp uniformity (O-25), " << F.getName() << "\n"
           << "    instructions            : " << Total << "\n"
           << "    warp-uniform            : " << Uniform;
    if (Total)
      errs() << "  (" << (100 * Uniform / Total) << "%)";
    errs() << "\n      maskable to lane 0      : " << Maskable << "\n";

    // One line per reason, and only for reasons that actually occurred. The
    // single "blocked: encoding" line this replaces was read as a measurement
    // of F-56 when most of what it counted was not F-56 at all.
    struct Row { Mask M; const char *Label; const char *Why; };
    static const Row Rows[] = {
        {Mask::ControlFlow, "control flow",
         "block not reached by every lane, or a branch"},
        {Mask::NoPredForm, "no A\u2032 form",
         "\u00a74 128+/256+, F-56 -- spec change"},
        {Mask::NoMIForm, "no MI form",
         "ISA predicates it, CCVInstrInfo.td does not"},
        {Mask::NoLongForm, "16-bit only",
         "Format K point, invariant 7 -- no qualifier exists"},
        {Mask::Semantics, "semantics",
         "masking it would change what the kernel does"},
        {Mask::QualifierTaken, "qualifier used",
         "the predicate field is data for this opcode"},
        {Mask::Unmodelled, "UNMODELLED",
         "this report does not know -- see below"},
    };
    for (const Row &R : Rows) {
      if (!Blocked[unsigned(R.M)])
        continue;
      std::string Label = std::string("blocked: ") + R.Label;
      // Pad to a display width, not a byte count: the A\u2032 label carries a
      // multi-byte prime and would otherwise sit two columns short.
      unsigned Cont = 0;
      for (unsigned char C : Label)
        if ((C & 0xC0) == 0x80)
          ++Cont;
      Label.resize(24 + Cont, ' ');
      errs() << "      " << Label << ": " << Blocked[unsigned(R.M)]
             << "   (" << R.Why << ")\n";
    }
    if (!Unknown.empty()) {
      errs() << "      unmodelled opcodes      :";
      for (auto &KV : Unknown)
        errs() << " " << KV.first << "\u00d7" << KV.second;
      errs() << "\n";
    }

    errs() << "    broadcasts needed       : " << Crossings << "\n"
           << "    net masked instructions : " << Net;
    if (Total)
      errs() << "   (" << (Net > 0 ? 100 * Net * 31 / int(Total * 32) : 0)
             << "% of lane-activations saved)";
    errs() << "\n    peak uniform values live: " << Peak
           << "   (a uniform file would hold these)\n"
    // Said out loud because the two numbers do not match and should not be
    // expected to. This pass runs on IR and counts what the ENCODING permits;
    // CCVMaskUniform runs post-ISel, sees real opcodes and real displacements,
    // and declines any region whose masked work does not exceed its crossings.
    // "maskable" above is the ceiling, not the take.
           << "    (ceiling, at IR level -- CCVMaskUniform decides the take;"
              " ccv-sim -counters measures it)\n";
    return false;
  }

  StringRef getPassName() const override { return "CCV warp-uniformity stats"; }
};

} // namespace

char CCVUniformity::ID = 0;

namespace llvm {
FunctionPass *createCCVUniformity() { return new CCVUniformity(); }
} // namespace llvm
