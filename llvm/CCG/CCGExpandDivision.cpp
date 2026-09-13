//===-- CCGExpandDivision.cpp - integer division has no instruction -------===//
//
// §4's integer map ends at `prmt` with no divide, and there is no runtime
// library to call, so LLVM's default expansion -- a libcall -- fails as
// "Cannot select: udivrem" with no diagnostic. Real GPUs are in the same
// position: NVIDIA has no integer divide instruction either, and nvcc emits an
// inline sequence.
//
// So do what they do. LLVM already carries the shift-subtract expansion used by
// targets without a divider; this pass applies it in IR, before anything can
// ask for a libcall. The cost is a loop of roughly 32 iterations, which is what
// integer division costs on a machine that does not have one -- the point is
// that `a / b` compiles and is correct, not that it is cheap.
//
// Constant divisors never reach here: instcombine turns those into a multiply
// and a shift long before codegen, which is the case that actually appears in
// index arithmetic.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/Transforms/Utils/IntegerDivision.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccg-expand-division"

namespace {

bool runOnFn(Function &F) {
  SmallVector<BinaryOperator *, 4> Divs, Rems;
  for (Instruction &I : instructions(F)) {
    auto *BO = dyn_cast<BinaryOperator>(&I);
    if (!BO || !BO->getType()->isIntegerTy())
      continue;
    switch (BO->getOpcode()) {
    case Instruction::SDiv:
    case Instruction::UDiv:
      Divs.push_back(BO);
      break;
    case Instruction::SRem:
    case Instruction::URem:
      Rems.push_back(BO);
      break;
    default:
      break;
    }
  }
  // Remainders first: expandRemainder builds a division of its own, and
  // expanding that division in the same walk would be expanding an instruction
  // this walk never saw.
  bool Changed = false;
  for (BinaryOperator *Rem : Rems)
    Changed |= expandRemainderUpTo32Bits(Rem);
  for (BinaryOperator *Div : Divs)
    Changed |= expandDivisionUpTo32Bits(Div);

  // The remainder expansion leaves a fresh division behind, so sweep again.
  if (Changed) {
    SmallVector<BinaryOperator *, 4> More;
    for (Instruction &I : instructions(F))
      if (auto *BO = dyn_cast<BinaryOperator>(&I))
        if (BO->getOpcode() == Instruction::SDiv ||
            BO->getOpcode() == Instruction::UDiv)
          More.push_back(BO);
    for (BinaryOperator *Div : More)
      expandDivisionUpTo32Bits(Div);
  }
  if (getenv("CCG_DIV_DUMP")) errs() << "[div] done\n" << F << "\n";
  return Changed;
}

class CCGExpandDivision : public FunctionPass {
public:
  static char ID;
  CCGExpandDivision() : FunctionPass(ID) {}
  bool runOnFunction(Function &F) override { return runOnFn(F); }
  StringRef getPassName() const override { return "CCG integer division expansion"; }
};

} // namespace

char CCGExpandDivision::ID = 0;

namespace llvm {
FunctionPass *createCCGExpandDivision() { return new CCGExpandDivision(); }
} // namespace llvm
