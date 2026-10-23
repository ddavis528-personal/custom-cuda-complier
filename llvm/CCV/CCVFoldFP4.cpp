//===-- CCVFoldFP4.cpp - NVIDIA's software FP4 conversions, made native ---===//
//
// CP-6 stage 2b, the fold. Below sm_100 cuda_fp4.hpp converts in software:
// float to E2M1 widens to double and rounds on its 64 bits, and E2M1 to float
// builds an FP16 and converts that in inline PTX. Both come out of clang
// inlined, a dozen blocks of integer arithmetic, and lowerCCVFP64Bits can run
// the first (F-186). §4 has each as one conversion at chwidth 4, so this
// replaces them with that.
//
// They are recognized by what they compute, not by their shape, so a
// different header version or optimization level is still found and a near
// miss is never folded. A candidate is a value V that depends on a value X:
// the code from X's definition to V's is run on constants, through LLVM's
// constant folder, and V is folded only if every probe gives §4's result:
//
//   - E2M1 to float: every one of the 256 bytes, so the low nibble is the
//     input and the high one must not matter. Exhaustive: a proof.
//   - float to E2M1 (round to nearest even, saturating at +-6, a NaN +6): every
//     E2M1 value, every midpoint between two, and their neighbours one and two
//     ulps away, both signs; zeros, subnormals, infinities and NaNs of either
//     sign; and an even spread of 2^12 others. Not exhaustive: a routine that
//     differed only off those inputs would be folded. tools/check-fp4.sh runs
//     the result against NVIDIA's own code on its inputs.
//
// The fold writes `ccv.cvt.e2m1.f32` or `ccv.cvt.f32.e2m1` as inline asm,
// which CCVExpandPTXAsm selects, and the software's branches are left with no
// use: they are removed here, so nothing of them reaches instruction selection.
//
//===----------------------------------------------------------------------===//

#include "CCVCheckIR.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/Analysis/ConstantFolding.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/Transforms/Utils/SimplifyCFGOptions.h"
#include <cmath>
#include <cstring>

using namespace llvm;

// Mutation control for tools/check-fp4.sh: recognize against a reference
// that rounds ties away from zero and reads E2M1 code 1 as 0.25. NVIDIA's
// routines then match neither direction and nothing is folded.
static cl::opt<bool> TestWrongRef(
    "ccv-test-fp4-wrong-ref", cl::init(false), cl::Hidden,
    cl::desc("recognize FP4 conversions against a wrong reference, to test "
             "that nothing is then folded"));

static cl::opt<bool> NoFold("ccv-no-fold-fp4", cl::init(false), cl::Hidden,
                            cl::desc("keep CUDA's software FP4 conversions"));

namespace {

const float E2M1[8] = {0, 0.5f, 1, 1.5f, 2, 3, 4, 6};

/// §4's E2M1 code 0-15 as a float.
float fromE2M1(unsigned C) {
  float M = TestWrongRef && (C & 7) == 1 ? 0.25f : E2M1[C & 7];
  return C & 8 ? -M : M;
}

/// §4's conversion of FP32 bits X to E2M1: round to nearest even, +-6 at and
/// past the largest finite, a NaN +6 (O-56).
unsigned toE2M1(uint32_t X) {
  if ((X & 0x7FFFFFFFu) > 0x7F800000u)
    return 7;
  float F;
  std::memcpy(&F, &X, 4);
  float A = std::fabs(F);
  unsigned Mag = 7;
  for (unsigned C = 0; C != 7; ++C) {
    float Mid = (E2M1[C] + E2M1[C + 1]) / 2;
    // A tie goes to the even code, the one whose mantissa bit is 0.
    if (A < Mid || (A == Mid && (TestWrongRef ? false : C % 2 == 0))) {
      Mag = C;
      break;
    }
  }
  return (X >> 31) << 3 | Mag;
}

/// The probes for float to E2M1.
std::vector<uint32_t> toProbes() {
  std::vector<uint32_t> P = {0x00000000, 0x00000001, 0x007FFFFF, 0x00800000,
                             0x7F7FFFFF, 0x7F800000, 0x7F800001, 0x7FC00000,
                             0x7FFFFFFF};
  auto bits = [](float F) { uint32_t B; std::memcpy(&B, &F, 4); return B; };
  for (unsigned C = 0; C != 8; ++C) {
    P.push_back(bits(E2M1[C]));
    if (C != 7)
      P.push_back(bits((E2M1[C] + E2M1[C + 1]) / 2));
  }
  P.push_back(bits(7.0f));       // past +6: saturates
  for (unsigned I = 0, N = P.size(); I != N; ++I)
    for (int D : {-2, -1, 1, 2})
      if (P[I] != 0 || D > 0)
        P.push_back(P[I] + D);
  for (uint32_t K = 0; K != 1u << 12; ++K)
    P.push_back(K * 0x000FFFFFu + 0x1234u);   // spread over every exponent
  for (unsigned I = 0, N = P.size(); I != N; ++I)
    P.push_back(P[I] ^ 0x80000000u);
  return P;
}

/// Runs the code from X's definition until V is computed, with X = XC, on
/// constants. Null if it reaches anything it cannot fold on the way: a branch
/// on an unknown, a terminator other than `br`, or more steps than a
/// conversion takes.
Constant *evaluate(Value *X, Constant *XC, Instruction *V,
                   const DataLayout &DL) {
  DenseMap<Value *, Constant *> Val;
  Val[X] = XC;
  auto get = [&](Value *Op) -> Constant * {
    if (auto *C = dyn_cast<Constant>(Op))
      return isa<ConstantExpr>(C) || isa<GlobalValue>(C) ? nullptr : C;
    return Val.lookup(Op);
  };
  BasicBlock *BB;
  BasicBlock::iterator It;
  if (auto *I = dyn_cast<Instruction>(X)) {
    BB = I->getParent();
    It = std::next(I->getIterator());
    if (isa<PHINode>(*It))
      It = BB->getFirstNonPHIIt();
  } else {
    BB = &cast<Argument>(X)->getParent()->getEntryBlock();
    It = BB->begin();
  }
  for (unsigned Steps = 0; Steps != 2000; ++Steps) {
    Instruction &I = *It++;
    if (auto *Br = dyn_cast<BranchInst>(&I)) {
      BasicBlock *Next = Br->getSuccessor(0);
      if (Br->isConditional()) {
        auto *C = dyn_cast_or_null<ConstantInt>(get(Br->getCondition()));
        if (!C)
          return nullptr;
        Next = Br->getSuccessor(C->isZero());
      }
      // Every phi at once, from the values on the edge taken.
      SmallVector<std::pair<PHINode *, Constant *>, 4> Phis;
      for (PHINode &P : Next->phis())
        Phis.push_back({&P, get(P.getIncomingValueForBlock(BB))});
      for (auto [P, C] : Phis) {
        if (C)
          Val[P] = C;
        else
          Val.erase(P);
        if (P == V)
          return C;
      }
      BB = Next;
      It = BB->getFirstNonPHIIt();
      continue;
    }
    if (I.isTerminator())
      return nullptr;
    SmallVector<Constant *, 4> Ops;
    for (Value *Op : I.operands())
      if (Constant *C = isa<Function>(Op) ? cast<Constant>(Op) : get(Op))
        Ops.push_back(C);       // a callee too: the folder takes it last
    Constant *R = nullptr;
    auto *Call = dyn_cast<CallInst>(&I);
    if (Call && Call->isInlineAsm()) {
      // The one PTX the E2M1-to-float routine ends in: FP16 to FP32, exact.
      auto *IA = cast<InlineAsm>(Call->getCalledOperand());
      if (StringRef(IA->getAsmString()).contains("cvt.f32.f16") &&
          Ops.size() == 1 && isa<ConstantInt>(Ops[0])) {
        APFloat H(APFloat::IEEEhalf(), cast<ConstantInt>(Ops[0])->getValue());
        bool Lost;
        H.convert(APFloat::IEEEsingle(), APFloat::rmNearestTiesToEven, &Lost);
        R = ConstantFP::get(I.getContext(), H);
      }
    } else if (Ops.size() == I.getNumOperands() &&
               (!Call || canConstantFoldCallTo(Call, Call->getCalledFunction()))) {
      if (auto *Cmp = dyn_cast<CmpInst>(&I))
        R = ConstantFoldCompareInstOperands(Cmp->getPredicate(), Ops[0], Ops[1],
                                            DL);
      else if (!I.mayReadOrWriteMemory() || Call)
        R = ConstantFoldInstOperands(&I, Ops, DL);
    }
    // Poison is carried: a select can discard it, as the E2M1-to-float
    // routine's does a ctlz of zero. It never satisfies a branch or a probe.
    if (R && isa<ConstantExpr>(R))
      R = nullptr;
    if (R)
      Val[&I] = R;
    else
      Val.erase(&I);
    if (&I == V)
      return R;
  }
  return nullptr;
}

/// Everything that depends on X, through data and phis.
SetVector<Instruction *> slice(Value *X) {
  SetVector<Instruction *> S;
  SmallVector<Value *, 16> Work = {X};
  while (!Work.empty()) {
    Value *W = Work.pop_back_val();
    for (User *U : W->users())
      if (auto *I = dyn_cast<Instruction>(U))
        if (S.insert(I))
          Work.push_back(I);
  }
  return S;
}

bool matchesTo(Value *X, Instruction *V, const DataLayout &DL,
               ArrayRef<uint32_t> Probes) {
  for (uint32_t P : Probes) {
    Constant *R = evaluate(X, ConstantFP::get(X->getContext(),
                                              APFloat(APFloat::IEEEsingle(), APInt(32, P))),
                           V, DL);
    auto *CI = dyn_cast_or_null<ConstantInt>(R);
    if (!CI || CI->getZExtValue() != toE2M1(P))
      return false;
  }
  return true;
}

bool matchesFrom(Value *X, Instruction *V, const DataLayout &DL) {
  // 2 first, 1.0: nearly every candidate is rejected there, by one run.
  for (unsigned K = 0; K != 256; ++K) {
    unsigned B = K ^ 2;
    Constant *R = evaluate(X, ConstantInt::get(X->getType(), B), V, DL);
    auto *CF = dyn_cast_or_null<ConstantFP>(R);
    if (!CF || CF->getValueAPF().convertToFloat() != fromE2M1(B & 15) ||
        CF->getValueAPF().isNegative() != bool(B & 8))
      return false;
  }
  return true;
}

} // namespace

unsigned llvm::foldCCVFP4(Module &M) {
  if (NoFold)
    return 0;
  const DataLayout &DL = M.getDataLayout();
  std::vector<uint32_t> Probes = toProbes();
  unsigned Folded = 0;
  for (Function &F : M) {
    if (F.isDeclaration())
      continue;
    // Inputs: a float widened to double, or a byte.
    SmallVector<std::pair<Value *, bool>, 8> Inputs;   // (X, to E2M1)
    // A byte is an argument, a load or a truncation: the storage, not a
    // step inside some other computation.
    for (Argument &A : F.args())
      if (A.getType()->isIntegerTy(8))
        Inputs.push_back({&A, false});
    for (BasicBlock &BB : F)
      for (Instruction &I : BB) {
        if (auto *E = dyn_cast<FPExtInst>(&I))
          if (E->getSrcTy()->isFloatTy() && E->getDestTy()->isDoubleTy())
            Inputs.push_back({E->getOperand(0), true});
        if (I.getType()->isIntegerTy(8) && (isa<LoadInst>(I) || isa<TruncInst>(I)))
          Inputs.push_back({&I, false});
      }
    DominatorTree DT(F);
    bool Changed = false;
    SmallPtrSet<Value *, 8> Done;
    SmallVector<CallInst *, 2> DeadAsm;
    for (auto [X, To] : Inputs) {
      if (!Done.insert(X).second)
        continue;
      for (Instruction *V : slice(X)) {
        if (To ? !V->getType()->isIntegerTy(8) : !V->getType()->isFloatTy())
          continue;
        Instruction *At = &*V->getParent()->getFirstInsertionPt();
        if (V->use_empty() ||
            (isa<Instruction>(X) && !DT.dominates(cast<Instruction>(X), At)) ||
            !(To ? matchesTo(X, V, DL, Probes) : matchesFrom(X, V, DL)))
          continue;
        IRBuilder<> B(At);
        Value *R;
        if (To) {
          auto *IA = InlineAsm::get(
              FunctionType::get(B.getInt32Ty(), {B.getFloatTy()}, false),
              "ccv.cvt.e2m1.f32 $0, $1", "=r,f", false);
          R = B.CreateTrunc(B.CreateCall(IA, {X}), B.getInt8Ty());
        } else {
          auto *IA = InlineAsm::get(
              FunctionType::get(B.getFloatTy(), {B.getInt32Ty()}, false),
              "ccv.cvt.f32.e2m1 $0, $1", "=f,r", false);
          R = B.CreateCall(IA, {B.CreateZExt(X, B.getInt32Ty())});
        }
        V->replaceAllUsesWith(R);
        // The E2M1-to-float routine ends in an asm call without `sideeffect`,
        // which is pure, but which nothing below deletes as dead.
        if (auto *Call = dyn_cast<CallInst>(V))
          if (Call->isInlineAsm() &&
              !cast<InlineAsm>(Call->getCalledOperand())->hasSideEffects())
            DeadAsm.push_back(Call);
        ++Folded;
        Changed = true;
        break;
      }
    }
    if (!Changed)
      continue;
    for (CallInst *Call : DeadAsm)
      Call->eraseFromParent();
    // The software, now unused: its instructions, then its branches.
    for (bool Again = true; Again;) {
      Again = false;
      for (BasicBlock &BB : F)
        for (Instruction &I : make_early_inc_range(reverse(BB)))
          if (isInstructionTriviallyDead(&I)) {
            I.eraseFromParent();
            Again = true;
          }
      // simplifyCFG can delete blocks other than the one it is given, so the
      // walk starts over after each change.
      TargetTransformInfo TTI(DL);
      for (bool Simplified = true; Simplified;) {
        Simplified = false;
        for (BasicBlock &BB : F)
          if (simplifyCFG(&BB, TTI, nullptr, SimplifyCFGOptions())) {
            Simplified = Again = true;
            break;
          }
      }
      Again |= removeUnreachableBlocks(F);
    }
  }
  return Folded;
}
