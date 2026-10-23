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
// Constant divisors are skipped entirely and left to DAGCombiner's
// BuildSDIV/BuildUDIV, which strength-reduce them properly. See runOnFn.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IntrinsicsNVPTX.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-expand-division"

// Mutation control for tools/check-fdiv.sh: the divide without its IEEE
// special cases, as it was before F-178.
static cl::opt<bool> TestNoSpecials(
    "ccv-test-fdiv-no-specials", cl::init(false), cl::Hidden,
    cl::desc("drop the fp32 divide's zero, infinity and NaN cases, to test "
             "that it is caught"));

namespace {

/// The SFU's approximate reciprocal and square-root seeds, as NVVM names them.
/// They select to `rcp.f32`, `rsqrt.f32` and `sqrt.f32` one for one. Every
/// IEEE sequence below starts from one and refines it, so none of them depends
/// on the SFU being better than approximate (IS-12).
Value *sfu(IRBuilder<> &B, Intrinsic::ID ID, Value *X) {
  return B.CreateIntrinsic(ID, {}, {X});
}

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
  Value *R = sfu(B, Intrinsic::nvvm_rcp_approx_ftz_f, FD);  // -> rcp.f32
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

/// IEEE fp32 division, correctly rounded at every input (F-49, O-36, F-62,
/// F-178).
///
/// CUDA's default `/` on floats is IEEE-correct, so this is a compatibility
/// requirement. There is no divider (O-36): the quotient comes from the SFU's
/// approximate reciprocal and `ffma`.
///
///  1. Operands are reduced to magnitudes am, bm in [1, 2) and exponents ea,
///     eb, subnormals normalised first by an exact multiply by 2^24.
///  2. y = rcp(bm), refined twice by Newton: y = fma(y, fma(-bm, y, 1), y).
///     The seed may be off by a few ulps; two steps leave y far inside the
///     half ulp the next step needs.
///  3. q = am * y; r = fma(-bm, q, am); qm = fma(r, y, q): the quotient of the
///     reduced operands to within an ulp (Markstein), in [0.5, 2]. Its last
///     bit is then settled from exact residuals against the midpoints either
///     side, since an approximate seed can leave y an ulp off at a tie. The
///     FMA residual is exact because FMA rounds once.
///  4. The result is ASSEMBLED, not scaled. Its exponent is qm's plus ea - eb.
///     In the normal range that is the answer, with no rounding left to do.
///     Above it, infinity. Below it, the subnormal result rounds qm's 24-bit
///     significand once, at 2^-149, in integers, and qm's own residual
///     r2 = fma(-bm, qm, am) says which side of qm the exact quotient lies on,
///     the sticky that decides a tie. The old final scalbn rounded a value
///     already rounded, up to 1 ulp out (F-62).
///  5. NaN, infinite and zero operands are IEEE's, and a NaN result is the
///     canonical one (O-66). The old sequence had no special cases at all and
///     forced every exponent to 0 regardless, so 0/1 was 2^-127 and 1/0 was
///     2^127 (F-178).
///
/// tools/model-ieee-sfu.cpp checks this formula exhaustively where it can
/// (1/x over every float) and on a large sample elsewhere, with the seed off
/// by up to 2 ulps either way; tools/check-fdiv.sh checks the machine.
Value *fdiv32(IRBuilder<> &B, Value *A, Value *D) {
  Type *F32 = B.getFloatTy();
  Type *I32 = B.getInt32Ty();
  auto ibits = [&](Value *V) { return B.CreateBitCast(V, I32); };
  auto fbits = [&](Value *V) { return B.CreateBitCast(V, F32); };
  auto konst = [&](uint32_t C) { return ConstantInt::get(I32, C); };
  auto fma = [&](Value *X, Value *Y, Value *Z) {
    return B.CreateIntrinsic(Intrinsic::fma, {F32}, {X, Y, Z});
  };

  Value *IA = ibits(A), *ID = ibits(D);
  Value *Sign = B.CreateAnd(B.CreateXor(IA, ID), konst(0x80000000));
  Value *MagA = B.CreateAnd(IA, konst(0x7FFFFFFF));
  Value *MagD = B.CreateAnd(ID, konst(0x7FFFFFFF));

  // 1. Reduce: a subnormal is multiplied by 2^24 (exact) and its exponent
  //    marked 24 lower. Ex is the biased exponent field of the reduced value.
  auto reduce = [&](Value *Mag, Value *&Ex) {
    Value *Sub = B.CreateICmpULT(Mag, konst(0x00800000));
    Value *Scaled = ibits(B.CreateFMul(fbits(Mag),
                                       ConstantFP::get(F32, 16777216.0)));
    Value *N = B.CreateSelect(Sub, Scaled, Mag);
    Ex = B.CreateSub(B.CreateLShr(N, 23), B.CreateSelect(Sub, konst(24), konst(0)));
    return fbits(B.CreateOr(B.CreateAnd(N, konst(0x007FFFFF)), konst(0x3F800000)));
  };
  Value *Ea, *Eb;
  Value *Am = reduce(MagA, Ea), *Bm = reduce(MagD, Eb);

  // 2-3. The reduced quotient, correctly rounded.
  Value *One = ConstantFP::get(F32, 1.0);
  Value *NegBm = B.CreateFNeg(Bm);
  Value *Y = sfu(B, Intrinsic::nvvm_rcp_approx_ftz_f, Bm);
  for (int I = 0; I != 2; ++I)
    Y = fma(Y, fma(NegBm, Y, One), Y);
  Value *Q = B.CreateFMul(Am, Y);
  Value *Qm = fma(fma(NegBm, Q, Am), Y, Q);
  Value *R2 = fma(NegBm, Qm, Am);
  // The last bit, from exact residuals. Markstein's step is correctly rounded
  // when y is RN(1/bm), and a seed below 1/bm's binade can leave Newton
  // stuck one ulp short at a tie (bm = 2 - 2^-23, seed 2 ulps low). So the
  // midpoints on either side of qm are tested directly: r - bm*ulp/2 is
  // exact in sign (one FMA, every term normal in the reduced domain), and
  // zero only at a true tie.
  {
    Value *Iq = ibits(Qm);
    Value *Up = fbits(B.CreateAdd(Iq, konst(1)));
    Value *Dn = fbits(B.CreateSub(Iq, konst(1)));
    Value *Hf = ConstantFP::get(F32, 0.5);
    Value *Mu = fma(NegBm, B.CreateFMul(B.CreateFSub(Up, Qm), Hf), R2);
    Value *Md = fma(Bm, B.CreateFMul(B.CreateFSub(Qm, Dn), Hf), R2);
    Value *Zero = ConstantFP::get(F32, 0.0);
    Value *QOdd = B.CreateICmpNE(B.CreateAnd(Iq, konst(1)), konst(0));
    Value *GoUp = B.CreateAnd(
        B.CreateFCmpOGT(R2, Zero),
        B.CreateOr(B.CreateFCmpOGT(Mu, Zero),
                   B.CreateAnd(B.CreateFCmpOEQ(Mu, Zero), QOdd)));
    Value *GoDn = B.CreateAnd(
        B.CreateFCmpOLT(R2, Zero),
        B.CreateOr(B.CreateFCmpOLT(Md, Zero),
                   B.CreateAnd(B.CreateFCmpOEQ(Md, Zero), QOdd)));
    Qm = B.CreateSelect(GoUp, Up, B.CreateSelect(GoDn, Dn, Qm));
    R2 = fma(NegBm, Qm, Am);
  }

  // 4. Assemble. E is the unbiased exponent of the result.
  Value *IQ = ibits(Qm);
  Value *E = B.CreateAdd(B.CreateSub(B.CreateLShr(IQ, 23), konst(127)),
                         B.CreateSub(Ea, Eb));
  Value *Frac = B.CreateAnd(IQ, konst(0x007FFFFF));
  Value *Normal = B.CreateOr(B.CreateShl(B.CreateAdd(E, konst(127)), 23), Frac);
  Value *Inf = konst(0x7F800000);
  // Below the normal range: round the 24-bit significand at 2^-149, once.
  Value *N24 = B.CreateOr(Frac, konst(0x00800000));
  Value *Sh = B.CreateSub(konst(uint32_t(-126)), E);         // >= 1 here
  Value *Far = B.CreateICmpSGT(Sh, konst(24));               // below 2^-150: 0
  Value *ShC = B.CreateSelect(Far, konst(24), Sh);
  Value *Qs = B.CreateLShr(N24, ShC);
  Value *Rem = B.CreateAnd(N24, B.CreateSub(B.CreateShl(konst(1), ShC), konst(1)));
  Value *Half = B.CreateShl(konst(1), B.CreateSub(ShC, konst(1)));
  Value *Zero = ConstantFP::get(F32, 0.0);
  Value *Above = B.CreateFCmpOGT(R2, Zero);                  // exact > qm
  Value *Exact = B.CreateFCmpOEQ(R2, Zero);
  Value *Odd = B.CreateICmpNE(B.CreateAnd(Qs, konst(1)), konst(0));
  Value *Up = B.CreateOr(
      B.CreateICmpUGT(Rem, Half),
      B.CreateAnd(B.CreateICmpEQ(Rem, Half),
                  B.CreateOr(Above, B.CreateAnd(Exact, Odd))));
  Value *Sub = B.CreateSelect(Far, konst(0),
                              B.CreateAdd(Qs, B.CreateZExt(Up, I32)));
  Value *Res = B.CreateSelect(
      B.CreateICmpSGT(E, konst(127)), Inf,
      B.CreateSelect(B.CreateICmpSGE(E, konst(uint32_t(-126))), Normal, Sub));

  // 5. IEEE's special cases, last so they win.
  if (TestNoSpecials)
    return fbits(B.CreateOr(Res, Sign));
  Value *AZero = B.CreateICmpEQ(MagA, konst(0));
  Value *DZero = B.CreateICmpEQ(MagD, konst(0));
  Value *AInf = B.CreateICmpEQ(MagA, Inf);
  Value *DInf = B.CreateICmpEQ(MagD, Inf);
  Value *NaN = B.CreateOr(
      B.CreateOr(B.CreateICmpUGT(MagA, Inf), B.CreateICmpUGT(MagD, Inf)),
      B.CreateOr(B.CreateAnd(AZero, DZero), B.CreateAnd(AInf, DInf)));
  Res = B.CreateSelect(B.CreateOr(AZero, DInf), konst(0), Res);
  Res = B.CreateSelect(B.CreateOr(AInf, DZero), Inf, Res);
  Res = B.CreateOr(Res, Sign);
  Res = B.CreateSelect(NaN, konst(0x7FFFFFFF), Res);
  return fbits(Res);
}

/// IEEE fp32 square root, correctly rounded at every input (IS-12).
///
/// `sqrt.f32` is approximate, so `sqrtf` (CUDA's default -prec-sqrt=true) is
/// a sequence: x = m * 2^2j with m in [1, 4); from the SFU's rsqrt seed,
/// g ~ sqrt(m) and h ~ 1/(2 sqrt(m)) are refined once by Goldschmidt, and the
/// exact residual d = fma(-g, g, m) gives s = fma(d, h, g), correctly rounded
/// (Markstein). sqrt(m) is in [1, 2), so the result is s with j added to its
/// exponent: always normal, never rounded again. Negative inputs give the
/// canonical NaN, and +-0, +inf and NaN are their own.
Value *sqrt32(IRBuilder<> &B, Value *X) {
  Type *F32 = B.getFloatTy();
  Type *I32 = B.getInt32Ty();
  auto ibits = [&](Value *V) { return B.CreateBitCast(V, I32); };
  auto fbits = [&](Value *V) { return B.CreateBitCast(V, F32); };
  auto konst = [&](uint32_t C) { return ConstantInt::get(I32, C); };
  auto fma = [&](Value *P, Value *Q, Value *R) {
    return B.CreateIntrinsic(Intrinsic::fma, {F32}, {P, Q, R});
  };

  Value *IX = ibits(X);
  Value *Sub = B.CreateICmpULT(IX, konst(0x00800000));
  Value *N = B.CreateSelect(
      Sub, ibits(B.CreateFMul(X, ConstantFP::get(F32, 16777216.0))), IX);
  Value *E = B.CreateSub(B.CreateSub(B.CreateLShr(N, 23), konst(127)),
                         B.CreateSelect(Sub, konst(24), konst(0)));
  Value *Odd = B.CreateAnd(E, konst(1));
  Value *M = fbits(B.CreateOr(B.CreateAnd(N, konst(0x007FFFFF)),
                              B.CreateShl(B.CreateAdd(Odd, konst(127)), 23)));
  Value *J = B.CreateAShr(B.CreateSub(E, Odd), konst(1));

  Value *Y = sfu(B, Intrinsic::nvvm_rsqrt_approx_f, M);
  Value *G = B.CreateFMul(M, Y);
  Value *H = B.CreateFMul(ConstantFP::get(F32, 0.5), Y);
  Value *R = fma(B.CreateFNeg(G), H, ConstantFP::get(F32, 0.5));
  G = fma(G, R, G);
  H = fma(H, R, H);
  Value *S = fma(fma(B.CreateFNeg(G), G, M), H, G);
  Value *Res = B.CreateAdd(ibits(S), B.CreateShl(J, 23));

  // x < 0 (not -0) and NaN give the canonical NaN; +-0 and +inf themselves.
  Value *Mag = B.CreateAnd(IX, konst(0x7FFFFFFF));
  Value *Inf = konst(0x7F800000);
  Value *Self = B.CreateOr(B.CreateICmpEQ(Mag, konst(0)), B.CreateICmpEQ(IX, Inf));
  Value *NaN = B.CreateOr(B.CreateICmpUGT(Mag, Inf),
                          B.CreateAnd(B.CreateICmpNE(Mag, konst(0)),
                                      B.CreateICmpSLT(IX, konst(0))));
  Res = B.CreateSelect(Self, IX, Res);
  Res = B.CreateSelect(NaN, konst(0x7FFFFFFF), Res);
  return fbits(Res);
}

bool expand(BinaryOperator *BO) {
  if (BO->getOpcode() == Instruction::FDiv) {
    if (!BO->getType()->isFloatTy())
      return false;
    IRBuilder<> B(BO);
    Value *Res;
    if (BO->hasAllowReciprocal() || BO->hasApproxFunc()) {
      // Fast-math (-use_fast_math, __fdividef): the SFU's reciprocal, times
      // the numerator unless it is 1. CUDA's own approximate divide is this.
      Value *R = sfu(B, Intrinsic::nvvm_rcp_approx_ftz_f, BO->getOperand(1));
      auto *C = dyn_cast<ConstantFP>(BO->getOperand(0));
      Res = C && C->isExactlyValue(1.0) ? R : B.CreateFMul(BO->getOperand(0), R);
    } else {
      Res = fdiv32(B, BO->getOperand(0), BO->getOperand(1));
    }
    BO->replaceAllUsesWith(Res);
    BO->eraseFromParent();
    return true;
  }
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
      // A CONSTANT divisor is not this pass's job, and taking it was costing
      // an order of magnitude.
      //
      // The header above used to claim "constant divisors never reach here --
      // instcombine turns those into a shift". That is true for UNSIGNED and
      // false for signed: instcombine reduces `udiv x, 16` to `lshr` and
      // leaves `sdiv x, 16` alone, because rounding toward zero needs three
      // extra instructions and that is a CodeGen trade, not a canonicalisation.
      // So every signed constant divisor was being expanded into the full
      // runtime sequence -- and invisibly, because `rcp.u32` of a constant
      // folds, leaving the Newton and correction steps with no reciprocal in
      // the listing to give it away.
      //
      // DAGCombiner's BuildSDIV/BuildUDIV handle constants properly: a shift
      // for a power of two, a magic-number multiply otherwise. Leaving them
      // alone costs nothing and takes `transpose` from 79 instructions to 60.
      // tools/check-divconst.sh holds both the answers and the size.
      if (isa<ConstantInt>(BO->getOperand(1)))
        break;
      Work.push_back(BO);
      break;
    case Instruction::FDiv:
      Work.push_back(BO);
      break;
    default:
      break;
    }
  }
  bool Changed = false;
  for (BinaryOperator *BO : Work)
    Changed |= expand(BO);
  // Square roots and the NVVM correctly-rounded forms: IEEE sequences, unless
  // fast-math asks for the SFU's (afn).
  SmallVector<CallInst *, 4> Calls;
  for (Instruction &I : instructions(F))
    if (auto *CI = dyn_cast<CallInst>(&I))
      switch (CI->getIntrinsicID()) {
      case Intrinsic::sqrt: case Intrinsic::nvvm_sqrt_f:
      case Intrinsic::nvvm_sqrt_rn_f: case Intrinsic::nvvm_rcp_rn_f:
        if (CI->getType()->isFloatTy())
          Calls.push_back(CI);
        break;
      default:
        break;
      }
  for (CallInst *CI : Calls) {
    IRBuilder<> B(CI);
    Value *X = CI->getArgOperand(0), *Res;
    if (CI->getIntrinsicID() == Intrinsic::nvvm_rcp_rn_f)
      Res = fdiv32(B, ConstantFP::get(B.getFloatTy(), 1.0), X);
    else if (isa<FPMathOperator>(CI) && CI->hasApproxFunc())
      Res = sfu(B, Intrinsic::nvvm_sqrt_approx_f, X);
    else
      Res = sqrt32(B, X);
    CI->replaceAllUsesWith(Res);
    CI->eraseFromParent();
    Changed = true;
  }
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
