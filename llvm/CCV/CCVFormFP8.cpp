//===-- CCVFormFP8.cpp - FP8 arithmetic written in FP32, made native -------===//
//
// CUDA's FP8 types are storage types: a kernel computes by converting to
// float, operating and converting back (§5.8). This pass recognises the two
// shapes that have a native form and rewrites them, in CCV-internal asm
// templates that CCVExpandPTXAsm selects, since LLVM 18 has no IR for either.
//
// STAGE 4: ONE OPERATION. `__nv_fp8_e4m3(float(a) + float(b))` is
//
//   cvt.rn.satfinite.e4m3x2.f32(fadd(cvt(a), cvt(b)), 0.0f)
//
// and §5.8 shows it is exactly `fadd.f0` at chwidth 8: for add, subtract and
// multiply the FP32 result of two narrow values is exact (E4M3, E2M1) or its
// one rounding is innocuous (E5M2), and the native operation rounds to
// nearest even, keeps subnormals and saturates as the conversion does. So it
// needs no leave from the source -- it is the same number -- and it becomes
// `ccv.fadd.e4m3`. Operands and result are i16 whose low byte is the element,
// as the PTX they replace has them; the high element converts +0.0, which is
// 0x00. Both sources must be in the destination's format.
//
// STAGE 3: A DOT PRODUCT. `__nv_fp8x4_e4m3` is one 32-bit word, the operand of
// `dp4.e4m3` (§5.8, O-44). CUDA has no dot-product function for it, so the
// source is the obvious one:
//
//   float4 x = float4(a[i]), y = float4(b[i]);
//   acc += x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w;
//
// and cuda_fp8.hpp decodes each word in inline PTX: two
// `cvt.rn.f16x2.e4m3x2` on its halves, then `cvt.f32.f16` on each half of
// those. This pass finds an `fadd` tree whose leaves are the four products of
// byte k of one word with byte k of another, in one FP8 format, plus at most
// one other addend, and makes it one `dp4`, which CCVExpandPTXAsm selects.
// LLVM 18 has nothing to express `dp4` in IR, so the pass writes it as a
// CCV-internal asm template, `ccv.dp4.e4m3`, in the same channel the PTX it
// replaces arrived in.
//
// WHEN IT MAY. `dp4.e4m3` sums the products exactly and rounds once (O-44);
// the source rounds at every `fadd`. The two differ, so the pass needs leave:
// every `fmul` and `fadd` in the tree must carry `contract`, which is C's
// FP_CONTRACT -- an expression "evaluated as though it were a single
// operation, thereby omitting rounding errors implied by the source code"
// (C11 6.5p8). CUDA compiles with -ffp-contract=fast, so CUDA source has it.
// The products themselves are exact in FP32 for both formats, so the only
// roundings removed are the additions'.
//
// The accumulator is any other addend; with none, it is -0.0, the identity
// that keeps an all-(-0) sum -0.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/PatternMatch.h"
#include "llvm/IR/ValueHandle.h"
#include "llvm/Pass.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Regex.h"
#include "llvm/Transforms/Utils/Local.h"

using namespace llvm;
using namespace llvm::PatternMatch;

static cl::opt<bool> FormArith(
    "ccv-fp8-arith", cl::init(true), cl::Hidden,
    cl::desc("make cvt.satfinite(op.f32(cvt a, cvt b)) a native FP8 add, "
             "subtract or multiply (CP-6)"));
static cl::opt<bool> FormDot(
    "ccv-fp8-dot", cl::init(true), cl::Hidden,
    cl::desc("contract an FP8 dot product written in FP32 into dp4.e4m3 or "
             "dp4.e5m2 (CP-6)"));

namespace {

/// The asm text of a call, without braces, `;` and spacing -- as
/// CCVExpandPTXAsm compares it.
std::optional<std::string> asmText(const Value *V) {
  auto *CB = dyn_cast<CallBase>(V);
  if (!CB || !CB->isInlineAsm())
    return std::nullopt;
  std::string Out;
  for (char C : cast<InlineAsm>(CB->getCalledOperand())->getAsmString())
    if (C != '{' && C != '}' && C != '\n' && C != ';')
      Out += C;
  return StringRef(Out).trim().str();
}

/// `trunc i32 W to i16` is half 0 of W; `trunc (lshr W, 16)` is half 1.
std::optional<std::pair<Value *, unsigned>> half(Value *V) {
  Value *W;
  if (match(V, m_Trunc(m_LShr(m_Value(W), m_SpecificInt(16)))) &&
      W->getType()->isIntegerTy(32))
    return std::make_pair(W, 1u);
  if (match(V, m_Trunc(m_Value(W))) && W->getType()->isIntegerTy(32) &&
      V->getType()->isIntegerTy(16))
    return std::make_pair(W, 0u);
  return std::nullopt;
}

/// One FP8 element as CUDA decodes it to FP32: byte K of word W, in format
/// E5M2 or not.
struct Elem {
  Value *Word = nullptr;
  unsigned K = 0;
  bool E5M2 = false;
};

std::optional<Elem> fp8Elem(Value *V) {
  auto T = asmText(V);
  if (!T || *T != "cvt.f32.f16 $0, $1")
    return std::nullopt;
  auto Lo = half(cast<CallBase>(V)->getArgOperand(0));   // f16 of the f16x2
  if (!Lo)
    return std::nullopt;
  auto T2 = asmText(Lo->first);
  bool E5M2;
  if (T2 && *T2 == "cvt.rn.f16x2.e4m3x2 $0, $1")
    E5M2 = false;
  else if (T2 && *T2 == "cvt.rn.f16x2.e5m2x2 $0, $1")
    E5M2 = true;
  else
    return std::nullopt;
  auto Pair = half(cast<CallBase>(Lo->first)->getArgOperand(0));
  if (!Pair)
    return std::nullopt;
  return Elem{Pair->first, 2 * Pair->second + Lo->second, E5M2};
}

bool contracts(const Value *V) {
  auto *I = dyn_cast<Instruction>(V);
  return I && isa<FPMathOperator>(I) && I->hasAllowContract();
}

/// Stage 4: a satfinite x2 conversion of +0.0 and one FP32 add, subtract or
/// multiply of two FP8 elements of its format. Returns whether it rewrote.
bool formArith(CallBase &C) {
  static const Regex ToX2(
      "^cvt\\.rn\\.satfinite\\.(e4m3|e5m2)x2\\.f32 \\$0, \\$([12]), \\$([12])$");
  SmallVector<StringRef, 4> M;
  auto T = asmText(&C);
  if (!T || !ToX2.match(*T, &M) || M[2] == M[3])
    return false;
  // $1 and $2 are the call's arguments 0 and 1; the first-named is high.
  Value *Hi = C.getArgOperand(M[2] == "1" ? 0 : 1);
  Value *Lo = C.getArgOperand(M[3] == "1" ? 0 : 1);
  auto *Z = dyn_cast<ConstantFP>(Hi);
  if (!Z || !Z->isZero() || Z->isNegative())
    return false;
  auto *Op = dyn_cast<BinaryOperator>(Lo);
  if (!Op || !Op->hasOneUse())
    return false;
  StringRef Name;
  switch (Op->getOpcode()) {
  case Instruction::FAdd: Name = "fadd"; break;
  case Instruction::FSub: Name = "fsub"; break;
  case Instruction::FMul: Name = "fmul"; break;
  default: return false;
  }
  bool E5M2 = M[1] == "e5m2";
  // Each source: the low element of an f16x2 conversion of an i16, in the
  // destination's format. That i16's low byte is the FP8 value.
  SmallVector<Value *, 2> Src;
  for (Value *V : {Op->getOperand(0), Op->getOperand(1)}) {
    auto T1 = asmText(V);
    if (!T1 || *T1 != "cvt.f32.f16 $0, $1")
      return false;
    auto H = half(cast<CallBase>(V)->getArgOperand(0));
    if (!H || H->second != 0)
      return false;
    auto T2 = asmText(H->first);
    if (!T2 || *T2 != (E5M2 ? "cvt.rn.f16x2.e5m2x2 $0, $1"
                            : "cvt.rn.f16x2.e4m3x2 $0, $1"))
      return false;
    Src.push_back(cast<CallBase>(H->first)->getArgOperand(0));
  }
  IRBuilder<> B(&C);
  Type *I16 = B.getInt16Ty();
  auto *Ty = FunctionType::get(I16, {I16, I16}, false);
  auto *IA = InlineAsm::get(
      Ty, ("ccv." + Name + (E5M2 ? ".e5m2" : ".e4m3") + " $0, $1, $2").str(),
      "=h,h,h", /*hasSideEffects=*/false);
  CallInst *N = B.CreateCall(Ty, IA, Src);
  N->setDoesNotAccessMemory();
  C.replaceAllUsesWith(N);
  RecursivelyDeleteTriviallyDeadInstructions(&C);
  return true;
}

class CCVFormFP8 : public FunctionPass {
public:
  static char ID;
  CCVFormFP8() : FunctionPass(ID) {}
  bool runOnFunction(Function &F) override;
  StringRef getPassName() const override { return "CCV form FP8"; }
};

char CCVFormFP8::ID = 0;

bool CCVFormFP8::runOnFunction(Function &F) {
  bool Changed = false;
  if (FormArith) {
    // A rewrite can delete other asm calls (the sources' conversions), so the
    // list holds weak handles.
    SmallVector<WeakTrackingVH, 8> Calls;
    for (Instruction &I : instructions(F))
      if (auto *C = dyn_cast<CallBase>(&I))
        if (C->isInlineAsm())
          Calls.push_back(C);
    for (WeakTrackingVH &H : Calls)
      if (auto *C = dyn_cast_or_null<CallBase>(H))
        Changed |= formArith(*C);
  }
  if (!FormDot)
    return Changed;
  SmallVector<Instruction *, 8> Roots;
  for (Instruction &I : instructions(F))
    if (I.getOpcode() == Instruction::FAdd && I.getType()->isFloatTy() &&
        contracts(&I))
      Roots.push_back(&I);

  SmallPtrSet<Instruction *, 16> Used;
  // Largest trees first: a root that is inside another root's tree is
  // visited after it, and skipped once that one is formed.
  for (Instruction *Root : llvm::reverse(Roots)) {
    if (Used.count(Root))
      continue;
    // The addends: through contracting fadds used only inside the tree.
    SmallVector<Value *, 8> Addends, Work{Root};
    SmallVector<Instruction *, 8> Tree;
    while (!Work.empty()) {
      Value *V = Work.pop_back_val();
      auto *I = dyn_cast<Instruction>(V);
      if (I && I->getOpcode() == Instruction::FAdd && contracts(I) &&
          (I == Root || I->hasOneUse()) && Addends.size() + Work.size() < 8) {
        Tree.push_back(I);
        Work.push_back(I->getOperand(0));
        Work.push_back(I->getOperand(1));
      } else {
        Addends.push_back(V);
      }
    }
    // Four products of byte k against byte k, and at most one other addend.
    Value *WA = nullptr, *WB = nullptr, *Acc = nullptr;
    std::optional<bool> E5M2;
    unsigned Seen = 0;
    bool OK = true;
    for (Value *V : Addends) {
      Value *X, *Y;
      std::optional<Elem> EX, EY;
      if (match(V, m_FMul(m_Value(X), m_Value(Y))) && contracts(V) &&
          V->hasOneUse() && (EX = fp8Elem(X)) && (EY = fp8Elem(Y)) &&
          EX->K == EY->K && EX->E5M2 == EY->E5M2 && !(Seen >> EX->K & 1)) {
        if (!WA) {
          WA = EX->Word, WB = EY->Word, E5M2 = EX->E5M2;
        } else if (EX->Word == WB && EY->Word == WA) {
          std::swap(EX, EY);          // a product is symmetric
        }
        if (EX->Word != WA || EY->Word != WB || EX->E5M2 != *E5M2) {
          OK = false;
          break;
        }
        Seen |= 1u << EX->K;
        Tree.push_back(cast<Instruction>(V));
      } else if (!Acc) {
        Acc = V;
      } else {
        OK = false;
        break;
      }
    }
    if (!OK || Seen != 0xF)
      continue;

    IRBuilder<> B(Root);
    LLVMContext &Ctx = F.getContext();
    if (!Acc)
      Acc = ConstantFP::getNegativeZero(Type::getFloatTy(Ctx));
    auto *Ty = FunctionType::get(Type::getFloatTy(Ctx),
                                 {B.getInt32Ty(), B.getInt32Ty(),
                                  Type::getFloatTy(Ctx)}, false);
    auto *IA = InlineAsm::get(
        Ty, *E5M2 ? "ccv.dp4.e5m2 $0, $1, $2, $3" : "ccv.dp4.e4m3 $0, $1, $2, $3",
        "=f,r,r,f", /*hasSideEffects=*/false);
    CallInst *Dot = B.CreateCall(Ty, IA, {WA, WB, Acc});
    Dot->setDoesNotAccessMemory();
    Root->replaceAllUsesWith(Dot);
    for (Instruction *I : Tree)
      Used.insert(I);
    RecursivelyDeleteTriviallyDeadInstructions(Root);
    Changed = true;
  }
  return Changed;
}

} // namespace

namespace llvm {
FunctionPass *createCCVFormFP8() { return new CCVFormFP8(); }
} // namespace llvm
