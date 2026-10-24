//===-- CCVFP64Bits.cpp - a double that is only its bits ------------------===//
//
// CP-6 stage 2b. Below sm_100 NVIDIA's cuda_fp4.hpp converts in software, and
// so does cuda_fp8.hpp for __NV_NOSAT: the float is widened to double and the
// conversion is integer arithmetic on the double's 64 bits. FP64 is out of
// scope for V1 (ISA §10, DA's response IS-13), but nothing here is FP64
// ARITHMETIC: every double is a float widened, a constant, a select of those,
// fabs or fneg of one, and its end is a bitcast to i64. So the chain is
// rebuilt on i64 bit patterns, where 64-bit integers now lower (F-186), and the
// doubles die. A chain that does anything else -- a double add, a compare, a
// truncation back to float -- is left as it was, and CCVCheckIR reports it as
// FP64.
//
//===----------------------------------------------------------------------===//

#include "CCVCheckIR.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

// Mutation control for tools/check-fp4.sh: rebias a widened float's exponent
// one too high, as if double's bias were 1024.
static cl::opt<bool> TestRebias(
    "ccv-test-fp64bits-rebias", cl::init(false), cl::Hidden,
    cl::desc("rebias a widened float's exponent by one too many, to test that "
             "it is caught"));

namespace {

/// Whether V, a double, is made only of what the rewrite can carry as bits.
bool convertible(Value *V, DenseMap<Value *, bool> &Seen) {
  auto [It, New] = Seen.try_emplace(V, true);   // a phi cycle is convertible
  if (!New)
    return It->second;
  bool Ok = false;
  if (isa<ConstantFP>(V) || isa<UndefValue>(V)) {
    Ok = true;
  } else if (auto *E = dyn_cast<FPExtInst>(V)) {
    Ok = E->getSrcTy()->isFloatTy();
  } else if (auto *S = dyn_cast<SelectInst>(V)) {
    Ok = convertible(S->getTrueValue(), Seen) &&
         convertible(S->getFalseValue(), Seen);
  } else if (auto *P = dyn_cast<PHINode>(V)) {
    Ok = true;
    for (Value *In : P->incoming_values())
      Ok = Ok && convertible(In, Seen);
  } else if (auto *U = dyn_cast<UnaryOperator>(V)) {
    Ok = U->getOpcode() == Instruction::FNeg && convertible(U->getOperand(0), Seen);
  } else if (auto *II = dyn_cast<IntrinsicInst>(V)) {
    Ok = II->getIntrinsicID() == Intrinsic::fabs &&
         convertible(II->getArgOperand(0), Seen);
  }
  Seen[V] = Ok;
  return Ok;
}

/// The IEEE double bits of a float, exactly as fpext gives them: a subnormal
/// float is normal in double, and a NaN keeps its payload and is quieted.
Value *widenBits(IRBuilder<> &B, Value *F) {
  Type *I32 = B.getInt32Ty(), *I64 = B.getInt64Ty();
  Value *X = B.CreateBitCast(F, I32);
  Value *Sign = B.CreateShl(B.CreateZExt(B.CreateLShr(X, 31), I64), 63);
  Value *E = B.CreateAnd(B.CreateLShr(X, 23), 0xFF);
  Value *M = B.CreateAnd(X, 0x7FFFFF);
  Value *M64 = B.CreateZExt(M, I64);
  // Normal: rebias 127 to 1023, the 23 fraction bits to the top of 52.
  Value *Normal = B.CreateOr(
      B.CreateShl(B.CreateZExt(B.CreateAdd(E, B.getInt32(1023 - 127 + TestRebias)), I64), 52),
      B.CreateShl(M64, 29));
  // Infinity or NaN: exponent all ones, a NaN quieted (fraction bit 22).
  Value *QM = B.CreateSelect(B.CreateICmpNE(M, B.getInt32(0)),
                             B.CreateOr(M, 0x400000), M);
  Value *Special = B.CreateOr(B.getInt64(0x7FFull << 52),
                              B.CreateShl(B.CreateZExt(QM, I64), 29));
  // Subnormal: m * 2^-149 with its top bit at p = 31 - clz(m), so the double's
  // exponent field is p - 149 + 1023 and the fraction is m below that bit.
  Value *Clz = B.CreateBinaryIntrinsic(Intrinsic::ctlz, M, B.getTrue());
  Value *P = B.CreateSub(B.getInt32(31), Clz);
  Value *SubExp = B.CreateZExt(B.CreateAdd(P, B.getInt32(1023 - 149 + TestRebias)), I64);
  Value *SubFrac = B.CreateAnd(
      B.CreateShl(M64, B.CreateZExt(B.CreateSub(B.getInt32(52), P), I64)),
      B.getInt64((1ull << 52) - 1));
  Value *Sub = B.CreateOr(B.CreateShl(SubExp, 52), SubFrac);
  Value *Mag = B.CreateSelect(
      B.CreateICmpEQ(E, B.getInt32(0xFF)), Special,
      B.CreateSelect(B.CreateICmpNE(E, B.getInt32(0)), Normal,
                     B.CreateSelect(B.CreateICmpEQ(M, B.getInt32(0)),
                                    B.getInt64(0), Sub)));
  return B.CreateOr(Sign, Mag);
}

struct Rewriter {
  DenseMap<Value *, Value *> Bits;

  Value *get(Value *V) {
    if (Value *Done = Bits.lookup(V))
      return Done;
    Type *I64 = Type::getInt64Ty(V->getContext());
    if (auto *C = dyn_cast<ConstantFP>(V))
      return ConstantInt::get(I64, C->getValueAPF().bitcastToAPInt());
    if (isa<UndefValue>(V))
      return UndefValue::get(I64);
    auto *I = cast<Instruction>(V);
    if (auto *P = dyn_cast<PHINode>(I)) {
      // Made first and filled after, so a cycle through it terminates.
      PHINode *N = PHINode::Create(I64, P->getNumIncomingValues(),
                                   P->getName() + ".bits", P);
      Bits[V] = N;
      for (unsigned K = 0; K != P->getNumIncomingValues(); ++K)
        N->addIncoming(get(P->getIncomingValue(K)), P->getIncomingBlock(K));
      return N;
    }
    IRBuilder<> B(I);
    Value *R;
    if (auto *E = dyn_cast<FPExtInst>(I))
      R = widenBits(B, E->getOperand(0));
    else if (auto *S = dyn_cast<SelectInst>(I))
      R = B.CreateSelect(S->getCondition(), get(S->getTrueValue()),
                         get(S->getFalseValue()));
    else if (isa<UnaryOperator>(I))
      R = B.CreateXor(get(I->getOperand(0)), B.getInt64(1ull << 63));
    else
      R = B.CreateAnd(get(cast<IntrinsicInst>(I)->getArgOperand(0)),
                      B.getInt64(~(1ull << 63)));
    Bits[V] = R;
    return R;
  }
};

} // namespace

void llvm::lowerCCVFP64Bits(Module &M) {
  for (Function &F : M) {
    SmallVector<BitCastInst *, 8> Roots;
    for (BasicBlock &BB : F)
      for (Instruction &I : BB)
        if (auto *BC = dyn_cast<BitCastInst>(&I))
          if (BC->getSrcTy()->isDoubleTy() && BC->getDestTy()->isIntegerTy(64))
            Roots.push_back(BC);
    if (Roots.empty())
      continue;
    DenseMap<Value *, bool> Seen;
    Rewriter R;
    for (BitCastInst *BC : Roots) {
      if (!convertible(BC->getOperand(0), Seen))
        continue;                       // CCVCheckIR reports it as FP64
      BC->replaceAllUsesWith(R.get(BC->getOperand(0)));
      BC->eraseFromParent();
    }
    // The doubles the rewrite replaced, now dead, users first.
    for (bool Changed = true; Changed;) {
      Changed = false;
      for (BasicBlock &BB : F)
        for (Instruction &I : make_early_inc_range(reverse(BB)))
          if (I.getType()->isDoubleTy() && I.use_empty()) {
            I.eraseFromParent();
            Changed = true;
          }
    }
  }
}
