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

#include "llvm/Analysis/UniformityAnalysis.h"
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
  return true;
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
    const UniformityInfo &UI =
        getAnalysis<UniformityInfoWrapperPass>().getUniformityInfo();

    unsigned Total = 0, Uniform = 0;
    for (Instruction &I : instructions(F)) {
      if (!isRealWork(I))
        continue;
      ++Total;
      if (!UI.isDivergent(&I))
        ++Uniform;
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
        // Live if any use comes at or after this point.
        for (const User *U : Def->users())
          if (const auto *UI2 = dyn_cast<Instruction>(U)) {
            auto It = std::find(Order.begin() + At, Order.end(), UI2);
            if (It != Order.end()) { ++Live; break; }
          }
      }
      Peak = std::max(Peak, Live);
    }

    errs() << "  warp uniformity (O-25), " << F.getName() << "\n"
           << "    instructions            : " << Total << "\n"
           << "    warp-uniform            : " << Uniform;
    if (Total)
      errs() << "  (" << (100 * Uniform / Total) << "%)";
    errs() << "\n    lane-activations wasted : "
           << (Total ? (100 * Uniform * 31 / (Total * 32)) : 0)
           << "%  (uniform work done 32x)\n"
           << "    peak uniform values live: " << Peak
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
