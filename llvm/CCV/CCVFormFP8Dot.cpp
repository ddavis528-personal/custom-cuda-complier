//===-- CCVFormFP8Dot.cpp - an FP8 dot product is one dp4 -----------------===//
//
// CP-6, stage 3. `__nv_fp8x4_e4m3` is one 32-bit word, the operand of
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
#include "llvm/Pass.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/Utils/Local.h"

using namespace llvm;
using namespace llvm::PatternMatch;

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

class CCVFormFP8Dot : public FunctionPass {
public:
  static char ID;
  CCVFormFP8Dot() : FunctionPass(ID) {}
  bool runOnFunction(Function &F) override;
  StringRef getPassName() const override { return "CCV form FP8 dot"; }
};

char CCVFormFP8Dot::ID = 0;

bool CCVFormFP8Dot::runOnFunction(Function &F) {
  if (!FormDot)
    return false;
  bool Changed = false;
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
FunctionPass *createCCVFormFP8Dot() { return new CCVFormFP8Dot(); }
} // namespace llvm
