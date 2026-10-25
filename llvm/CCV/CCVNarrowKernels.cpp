//===-- CCVNarrowKernels.cpp - kernels that keep 16-bit integers narrow ---===//
//
// F-200. F-199 runs 16-bit integer code at 32 bits, because a chwidth may
// issue only where the warp is converged (O-81) and scalar code cannot tell
// where that is. That costs O-40's narrow retire rate. But the warp is always
// converged at kernel entry. So a kernel can keep its 16-bit integers narrow if
// their registers are set to 16 bits once, at the entry, and never change
// width again, whatever diverges later.
//
// This pass marks such a kernel "ccv-narrow-int". CCVTargetMachine gives it a
// subtarget with i16 a legal type. Its register classes then split the file:
// 16-bit values in the top N of R8-R13, 32-bit values in the rest
// (CCVRegisterInfo.td's alternative orders), N sized by its 16-bit work so a
// small kernel does not spill its 32-bit values. CCVRegisterInfo::shouldCoalesce
// keeps a conversion between them a copy: a `mov` across widths, which
// zero-extends or truncates (O-82).
// CCVInsertChwidth sets the narrow registers at the entry and checks that it
// places nothing else.
//
// A kernel qualifies when it calls nothing, since a call resets every width
// (F-21). It must have no inline asm and no narrow-FP value, whose widths are
// not 16-bit integers'. And it must do some 16-bit integer arithmetic, or the
// split only costs registers. A device function never qualifies.
//
//===----------------------------------------------------------------------===//

#include "CCVFrameLowering.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/CommandLine.h"
#include <algorithm>

using namespace llvm;

namespace llvm {
FunctionPass *createCCVNarrowKernels();
}

namespace {

static cl::opt<bool> Disable(
    "ccv-no-narrow-kernels", cl::init(false), cl::Hidden,
    cl::desc("run 16-bit integers at 32 bits in every kernel, as F-199 does, "
             "to measure what F-200 buys"));

class CCVNarrowKernels : public FunctionPass {
public:
  static char ID;
  CCVNarrowKernels() : FunctionPass(ID) {}

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
  }

  bool runOnFunction(Function &F) override {
    unsigned N;
    if (Disable || F.isDeclaration() || !ccvIsKernel(F) || !(N = qualifies(F)))
      return false;
    F.addFnAttr("ccv-narrow-int", utostr(N));
    return true;
  }

  StringRef getPassName() const override { return "CCV narrow kernels"; }

private:
  /// How many registers the kernel's 16-bit integers get: one per 16-bit
  /// value it computes or loads, between 2 and 6, so a small kernel gives its
  /// 32-bit values all but two. 0 if it does not qualify.
  static unsigned qualifies(Function &F) {
    unsigned Narrow16 = 0;
    for (Instruction &I : instructions(F)) {
      if (auto *CB = dyn_cast<CallBase>(&I))
        if (CB->isInlineAsm() || !CB->getCalledFunction() ||
            !CB->getCalledFunction()->isIntrinsic())
          return 0;
      auto narrowFP = [](Type *T) {
        return T->getScalarType()->isHalfTy() || T->getScalarType()->isBFloatTy();
      };
      if (narrowFP(I.getType()))
        return 0;
      for (Value *Op : I.operands())
        if (narrowFP(Op->getType()))
          return 0;
      if ((isa<BinaryOperator>(I) || isa<LoadInst>(I)) &&
          I.getType()->isIntegerTy(16))
        ++Narrow16;
    }
    return Narrow16 ? std::min(std::max(Narrow16, 2u), 6u) : 0;
  }
};

char CCVNarrowKernels::ID = 0;

} // namespace

FunctionPass *llvm::createCCVNarrowKernels() { return new CCVNarrowKernels(); }
