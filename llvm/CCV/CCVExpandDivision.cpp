//===-- CCVExpandDivision.cpp - integer division has no instruction -------===//
//
// §4's integer map ends at `prmt` with no divide and there is no runtime
// library, so LLVM's default expansion -- a libcall -- fails as "Cannot select:
// udivrem" with no diagnostic. Real GPUs are in the same position: NVIDIA has
// no integer divide either, and nvcc emits an inline sequence.
//
// The first version of this pass used LLVM's generic shift-subtract expansion,
// which is correct and costs a loop of up to 32 iterations: measured on the
// simulator, ONE udiv took 97 dynamic instructions per thread. AMD's compiler
// does the same division in about ten straight-line instructions via a float
// reciprocal, and the 143-vs-64 static gap on the transpose benchmark was
// almost entirely this. See F-48.
//
// So this now does what both vendors do. The sequence is:
//
//     e = (u32)(rcp((float)d) * 2^32)      approximate floor(2^32 / d)
//     e = e + mulhi(e, -(e*d))             one Newton step in fixed point
//     q = mulhi(n, e)                      quotient, low by at most two
//     two conditional corrections
//
// Exactness is the whole question, and it is not assumed: `tools/check-div.sh`
// runs the result against exact integer division over the edge cases and a
// large pseudo-random sample, on the simulator, including d = 1 (where the
// reciprocal scaling saturates) and d = 0 (poison, but it must not hang).
//
// Constant divisors never reach here -- instcombine turns those into a
// multiply and a shift long before codegen.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-expand-division"

namespace {

/// floor(n / d) for 32-bit unsigned, exact, straight-line.
Value *udiv32(IRBuilder<> &B, Value *N, Value *D) {
  Type *I32 = B.getInt32Ty(), *F32 = B.getFloatTy(), *I64 = B.getInt64Ty();

  auto mulhi = [&](Value *A, Value *Bv) {
    // Written as a 64-bit multiply and shift, which is the canonical IR form;
    // DAGCombine folds it to MULHU (§4 point 4) before type legalization, so
    // no 64-bit value ever reaches a register (invariant 11).
    Value *W = B.CreateMul(B.CreateZExt(A, I64), B.CreateZExt(Bv, I64));
    return B.CreateTrunc(B.CreateLShr(W, 32), I32);
  };

  // Initial estimate of floor(2^32 / d), through the SFU (O-31).
  Value *FD = B.CreateUIToFP(D, F32);
  Value *R = B.CreateFDiv(ConstantFP::get(F32, 1.0), FD);      // -> rcp.f32
  // Scale by just UNDER 2^32 (0x4F7FFFFE), not 2^32. The Newton step below
  // converges only from below: if e ever exceeds 2^32/d then e*d wraps past
  // 2^32 and the correction term becomes huge instead of small, pushing e
  // further out. rcp can be up to an ulp high, so 2^32 exactly is not safe --
  // 2^32(1 - 2^-23) is. This is why AMD's sequence carries the same odd
  // constant.
  //
  // It also removes the d == 1 saturation case: the estimate is finite there
  // instead of clamping at UINT32_MAX. d == 0 still gives +inf and saturates,
  // which is fine -- udiv by zero is poison, and nothing here loops.
  APFloat Scale(APFloat::IEEEsingle(), APInt(32, 0x4F7FFFFEu));
  Value *Scaled = B.CreateFMul(R, ConstantFP::get(F32->getContext(), Scale));
  Value *E = B.CreateFPToUI(Scaled, I32);

  // One Newton step: e += mulhi(e, 2^32 - e*d). The subtraction is modular, so
  // it needs no extra width.
  Value *T = B.CreateSub(ConstantInt::get(I32, 0), B.CreateMul(E, D));
  E = B.CreateAdd(E, mulhi(E, T));

  Value *Q = mulhi(N, E);
  Value *Rem = B.CreateSub(N, B.CreateMul(Q, D));

  // At most two corrections: the estimate is low, never high.
  for (int I = 0; I != 2; ++I) {
    Value *Ge = B.CreateICmpUGE(Rem, D);
    Q = B.CreateSelect(Ge, B.CreateAdd(Q, ConstantInt::get(I32, 1)), Q);
    Rem = B.CreateSelect(Ge, B.CreateSub(Rem, D), Rem);
  }
  return Q;
}

/// Signed division is the unsigned one on magnitudes, with the sign put back.
/// LLVM defines sdiv as truncating toward zero, which is what this gives.
Value *sdiv32(IRBuilder<> &B, Value *N, Value *D, bool WantRem) {
  Type *I32 = B.getInt32Ty();
  Value *Zero = ConstantInt::get(I32, 0);
  Value *NN = B.CreateSelect(B.CreateICmpSLT(N, Zero), B.CreateNeg(N), N);
  Value *DD = B.CreateSelect(B.CreateICmpSLT(D, Zero), B.CreateNeg(D), D);
  Value *Q = udiv32(B, NN, DD);
  if (WantRem) {
    // The remainder takes the sign of the DIVIDEND, per LLVM's srem.
    Value *R = B.CreateSub(NN, B.CreateMul(Q, DD));
    return B.CreateSelect(B.CreateICmpSLT(N, Zero), B.CreateNeg(R), R);
  }
  Value *Neg = B.CreateICmpSLT(B.CreateXor(N, D), Zero);
  return B.CreateSelect(Neg, B.CreateNeg(Q), Q);
}

bool expand(BinaryOperator *BO) {
  if (!BO->getType()->isIntegerTy(32))
    return false;
  IRBuilder<> B(BO);
  Value *N = BO->getOperand(0), *D = BO->getOperand(1), *Res = nullptr;
  switch (BO->getOpcode()) {
  case Instruction::UDiv: Res = udiv32(B, N, D); break;
  case Instruction::URem: {
    Value *Q = udiv32(B, N, D);
    Res = B.CreateSub(N, B.CreateMul(Q, D));
    break;
  }
  case Instruction::SDiv: Res = sdiv32(B, N, D, /*WantRem=*/false); break;
  case Instruction::SRem: Res = sdiv32(B, N, D, /*WantRem=*/true); break;
  default: return false;
  }
  BO->replaceAllUsesWith(Res);
  BO->eraseFromParent();
  return true;
}

bool runOnFn(Function &F) {
  SmallVector<BinaryOperator *, 4> Work;
  for (Instruction &I : instructions(F)) {
    auto *BO = dyn_cast<BinaryOperator>(&I);
    if (!BO)
      continue;
    switch (BO->getOpcode()) {
    case Instruction::SDiv: case Instruction::UDiv:
    case Instruction::SRem: case Instruction::URem:
      Work.push_back(BO);
      break;
    default:
      break;
    }
  }
  bool Changed = false;
  for (BinaryOperator *BO : Work)
    Changed |= expand(BO);
  // Anything not 32-bit is left alone and will be diagnosed by isel rather
  // than silently miscompiled; nothing in the CUDA path produces one.
  return Changed;
}

class CCVExpandDivision : public FunctionPass {
public:
  static char ID;
  CCVExpandDivision() : FunctionPass(ID) {}
  bool runOnFunction(Function &F) override { return runOnFn(F); }
  StringRef getPassName() const override { return "CCV integer division expansion"; }
};

} // namespace

char CCVExpandDivision::ID = 0;

namespace llvm {
FunctionPass *createCCVExpandDivision() { return new CCVExpandDivision(); }
} // namespace llvm
