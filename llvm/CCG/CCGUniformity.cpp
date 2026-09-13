//===-- CCGUniformity.cpp - how much work is warp-redundant? --------------===//
//
// O-25 named this as the evidence that would size a warp-uniform register file,
// and F-52 turned it from an argument into a measurement: AMD computes the
// transpose kernel's divisor once on the scalar unit while CCG recomputes it in
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
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/InitializePasses.h"
#include "llvm/Support/raw_ostream.h"
#include <algorithm>
#include <vector>

using namespace llvm;

#define DEBUG_TYPE "ccg-uniformity"

static cl::opt<bool>
    ReportUniformity("ccg-uniformity-stats",
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

/// Can this operation be predicated at all? §4 puts Format A′'s opcode at seven
/// bits, so only points 0-127 are reachable predicated -- the integer and FP
/// ranges. Conversions (128+) and the SFU (256+) are Format A only, so the
/// division sequence's `cvt` and `rcp` cannot be masked however uniform they
/// are. That is an encoding limit, not an oversight to fix here.
bool isPredicable(const Instruction &I) {
  if (I.mayHaveSideEffects() || I.mayReadFromMemory())
    return !I.mayHaveSideEffects() && isa<LoadInst>(I);  // D′ exists for loads
  switch (I.getOpcode()) {
  case Instruction::Add: case Instruction::Sub:  case Instruction::Mul:
  case Instruction::And: case Instruction::Or:   case Instruction::Xor:
  case Instruction::Shl: case Instruction::LShr: case Instruction::AShr:
  case Instruction::FAdd: case Instruction::FSub: case Instruction::FMul:
  case Instruction::Select:
    return true;
  // Compares have a predicated form: Formats C and C′ carry a mandatory
  // qualifier, which is what O-32 added C″ to escape.
  case Instruction::ICmp: case Instruction::FCmp:
    return true;
  // uitofp / fptoui are §4 points 128+, and there is no A′ form.
  case Instruction::UIToFP: case Instruction::SIToFP:
  case Instruction::FPToUI: case Instruction::FPToSI:
  case Instruction::FDiv:            // lowers to rcp, §4 point 256
    return false;
  default:
    return false;
  }
}

class CCGUniformity : public FunctionPass {
public:
  static char ID;
  CCGUniformity() : FunctionPass(ID) {
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
    unsigned BlockedByEncoding = 0, BlockedByControl = 0;

    auto maskable = [&](const Instruction *I) {
      return I && isRealWork(*I) && !UI.isDivergent(I) &&
             UniformReach.count(I->getParent()) && isPredicable(*I);
    };

    for (Instruction &I : instructions(F)) {
      if (!isRealWork(I))
        continue;
      ++Total;
      if (UI.isDivergent(&I))
        continue;
      ++Uniform;
      if (!UniformReach.count(I.getParent())) { ++BlockedByControl; continue; }
      if (!isPredicable(I))                   { ++BlockedByEncoding; continue; }
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
    errs() << "\n"
           << "      maskable to lane 0    : " << Maskable << "\n"
           << "      blocked: encoding     : " << BlockedByEncoding
           << "   (§4 128+/256+ have no A\u2032 form)\n"
           << "      blocked: control flow : " << BlockedByControl
           << "   (block not reached by every lane)\n"
           << "    broadcasts needed       : " << Crossings << "\n"
           << "    net masked instructions : " << Net;
    if (Total)
      errs() << "   (" << (Net > 0 ? 100 * Net * 31 / int(Total * 32) : 0)
             << "% of lane-activations saved)";
    errs() << "\n    peak uniform values live: " << Peak
           << "   (a uniform file would hold these)\n";
    return false;
  }

  StringRef getPassName() const override { return "CCG warp-uniformity stats"; }
};

} // namespace

char CCGUniformity::ID = 0;

namespace llvm {
FunctionPass *createCCGUniformity() { return new CCGUniformity(); }
} // namespace llvm
