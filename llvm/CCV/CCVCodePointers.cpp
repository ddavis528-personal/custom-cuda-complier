//===-- CCVCodePointers.cpp - function pointers as 32-bit code addresses --===//
//
// F-21 step 5 (proposals/calling-convention.md §4). A function pointer is a
// code address, and a code address is the low 32 bits of the PC (ISA v1.8 §3
// Format E): `call` writes one and `ret` jumps to one under its own 4 GiB
// window. So a code pointer is an i32, never a windowed data pointer, and it
// must be told apart from one before CCVPointerPairs splits every pointer
// parameter into (rbase, roffset).
//
// With opaque pointers the type does not say which a `ptr` is, so this pass
// traces it, from each function used as a value and from each indirect callee,
// through direct-call parameters, selects and phis:
//
//   - a function used as a value becomes `ptrtoint @f to i32`, which the
//     backend materialises as a `movi` of its link-time code address;
//   - a parameter that carries one becomes i32, rebuilt as `inttoptr` at entry
//     so the body can call through it;
//   - an indirect call keeps its `inttoptr` callee, and the backend calls a
//     one-instruction `ret` stub with the target in R7.
//
// It also records, on each function that makes an indirect call, which
// functions it may reach: every address-taken function of the call's type
// (§2, "Indirect calls"). The static frame layout needs their extents before
// it can place the caller, so those functions are moved to the front of the
// module, which is where codegen's call-graph walk starts.
//
// A code pointer this cannot trace -- read from memory, returned, compared --
// is left as it was, and CCVCheckIR or the backend says so.
//
//===----------------------------------------------------------------------===//
#include "CCVCheckIR.h"
#include "CCVFrameLowering.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"

using namespace llvm;

namespace {

bool isDirectCallee(const Use &U) {
  auto *CB = dyn_cast<CallBase>(U.getUser());
  return CB && CB->isCallee(&U);
}

/// A defined device function whose address is used as a value.
bool addressTaken(const Function &F) {
  if (F.isDeclaration() || F.isIntrinsic() || ccvIsKernel(F))
    return false;
  for (const Use &U : F.uses())
    if (!isDirectCallee(U))
      return true;
  return false;
}

struct Tracer {
  // In module order, so the targets recorded and the order codegen sees are
  // the same on every run.
  SmallSetVector<const Function *, 8> Taken;
  SmallPtrSet<const Argument *, 8> CodeArgs;

  /// Does V carry a code address, as far as is known so far?
  bool isCode(const Value *V, unsigned Depth = 0) const {
    V = V->stripPointerCasts();
    if (auto *F = dyn_cast<Function>(V))
      return Taken.count(F);
    if (auto *A = dyn_cast<Argument>(V))
      return CodeArgs.count(A);
    if (Depth > 8)
      return false;
    if (auto *S = dyn_cast<SelectInst>(V))
      return isCode(S->getTrueValue(), Depth + 1) ||
             isCode(S->getFalseValue(), Depth + 1);
    if (auto *P = dyn_cast<PHINode>(V))
      return any_of(P->incoming_values(),
                    [&](const Value *I) { return isCode(I, Depth + 1); });
    return false;
  }
};

/// The i32 code address V carries, built at B's insertion point. Phis are
/// rebuilt as i32 phis, memoized so a loop's phi refers to itself.
Value *toCode(Value *V, IRBuilder<> &B, DenseMap<Value *, Value *> &Memo) {
  V = V->stripPointerCasts();
  if (auto It = Memo.find(V); It != Memo.end())
    return It->second;
  Type *I32 = B.getInt32Ty();
  if (auto *F = dyn_cast<Function>(V))
    return ConstantExpr::getPtrToInt(F, I32);
  if (auto *ITP = dyn_cast<IntToPtrInst>(V))
    if (ITP->getOperand(0)->getType()->isIntegerTy(32))
      return ITP->getOperand(0);
  if (auto *S = dyn_cast<SelectInst>(V)) {
    IRBuilder<> SB(S);
    Value *T = toCode(S->getTrueValue(), SB, Memo);
    Value *F = toCode(S->getFalseValue(), SB, Memo);
    if (!T || !F)
      return nullptr;
    return Memo[V] = SB.CreateSelect(S->getCondition(), T, F);
  }
  if (auto *P = dyn_cast<PHINode>(V)) {
    IRBuilder<> PB(P);
    PHINode *N = PB.CreatePHI(I32, P->getNumIncomingValues());
    Memo[V] = N;
    for (unsigned I = 0, E = P->getNumIncomingValues(); I != E; ++I) {
      IRBuilder<> IB(P->getIncomingBlock(I)->getTerminator());
      Value *X = toCode(P->getIncomingValue(I), IB, Memo);
      if (!X)
        return nullptr;
      N->addIncoming(X, P->getIncomingBlock(I));
    }
    return N;
  }
  if (isa<ConstantPointerNull>(V))
    return ConstantInt::get(I32, 0);
  return nullptr;
}

} // namespace

void llvm::lowerCCVCodePointers(Module &M) {
  Tracer T;
  for (Function &F : M)
    if (addressTaken(F))
      T.Taken.insert(&F);

  // 1. Which parameters carry code addresses: those that reach an indirect
  //    call as its callee, and those a direct call passes one to, to a
  //    fixed point.
  for (Function &F : M)
    for (Instruction &I : instructions(F))
      if (auto *CB = dyn_cast<CallBase>(&I))
        if (!CB->getCalledFunction() && !CB->isInlineAsm())
          if (auto *A = dyn_cast<Argument>(CB->getCalledOperand()->stripPointerCasts()))
            T.CodeArgs.insert(A);
  for (bool Changed = true; Changed;) {
    Changed = false;
    for (Function &F : M)
      for (Instruction &I : instructions(F)) {
        auto *CB = dyn_cast<CallBase>(&I);
        Function *Callee = CB ? CB->getCalledFunction() : nullptr;
        if (!Callee || Callee->isDeclaration())
          continue;
        for (unsigned K = 0, E = CB->arg_size(); K != E && K < Callee->arg_size(); ++K)
          if (T.isCode(CB->getArgOperand(K)) && T.CodeArgs.insert(Callee->getArg(K)).second)
            Changed = true;
      }
  }

  // 2. Indirect calls: the callee as i32 under an inttoptr, and the targets
  //    the frame layout must clear. Done before parameters change type, so
  //    the call's type still matches its targets' as written.
  DenseMap<Value *, Value *> Memo;
  for (Function &F : M)
    for (Instruction &I : make_early_inc_range(instructions(F))) {
      auto *CB = dyn_cast<CallBase>(&I);
      if (!CB || CB->getCalledFunction() || CB->isInlineAsm() ||
          !T.isCode(CB->getCalledOperand()))
        continue;
      std::string Targets;
      for (const Function *G : T.Taken)
        if (G->getFunctionType() == CB->getFunctionType())
          Targets += (Targets.empty() ? "" : ",") + G->getName().str();
      if (Targets.empty())
        report_fatal_error("CCV: an indirect call in " + F.getName() +
                           " has no address-taken function of its type to reach");
      std::string Prev =
          F.getFnAttribute("ccv-icall-targets").getValueAsString().str();
      F.addFnAttr("ccv-icall-targets", Prev.empty() ? Targets : Prev + "," + Targets);
      IRBuilder<> B(CB);
      Value *C = toCode(CB->getCalledOperand(), B, Memo);
      if (!C)
        continue;                      // CCVCheckIR names it
      CB->setCalledOperand(B.CreateIntToPtr(C, CB->getCalledOperand()->getType()));
    }

  // 3. Parameters: each code-pointer parameter becomes i32, and every direct
  //    call passes the i32 it carries.
  SmallVector<Function *, 8> Work;
  for (Function &F : M)
    if (any_of(F.args(), [&](Argument &A) { return T.CodeArgs.count(&A); }))
      Work.push_back(&F);
  for (Function *F : Work) {
    if (T.Taken.count(F) || ccvIsKernel(*F))
      report_fatal_error("CCV: " + F->getName() + " takes a function pointer "
                         "and is itself a kernel or address-taken, which is "
                         "not implemented (F-21 step 5)");
    SmallVector<Type *, 8> Params;
    for (Argument &A : F->args())
      Params.push_back(T.CodeArgs.count(&A) ? Type::getInt32Ty(M.getContext())
                                            : A.getType());
    Function *NF = Function::Create(
        FunctionType::get(F->getReturnType(), Params, false), F->getLinkage(),
        F->getAddressSpace(), "");
    M.getFunctionList().insert(F->getIterator(), NF);
    NF->copyAttributesFrom(F);
    NF->setAttributes(AttributeList());
    NF->addFnAttrs(AttrBuilder(M.getContext(), F->getAttributes().getFnAttrs()));
    NF->takeName(F);
    NF->splice(NF->end(), F);
    IRBuilder<> B(&*NF->getEntryBlock().getFirstInsertionPt());
    for (auto [A, NA] : zip(F->args(), NF->args())) {
      NA.takeName(&A);
      A.replaceAllUsesWith(T.CodeArgs.count(&A)
                               ? B.CreateIntToPtr(&NA, A.getType())
                               : static_cast<Value *>(&NA));
    }
    for (User *U : make_early_inc_range(F->users())) {
      auto *CB = cast<CallBase>(U);
      IRBuilder<> CBB(CB);
      SmallVector<Value *, 8> Args;
      for (auto [K, A] : enumerate(F->args())) {
        Value *V = CB->getArgOperand(K);
        if (T.CodeArgs.count(&A)) {
          V = toCode(V, CBB, Memo);
          if (!V)
            report_fatal_error("CCV: a function pointer passed to " +
                               NF->getName() + " that this compiler cannot "
                               "trace to its functions (F-21 step 5)");
        }
        Args.push_back(V);
      }
      auto *NC = CBB.CreateCall(NF, Args);
      NC->takeName(CB);
      CB->replaceAllUsesWith(NC);
      CB->eraseFromParent();
    }
    F->eraseFromParent();
  }

  // 4. Pointer-typed selects, phis and inttoptrs left dead now that their
  //    users take the i32 forms.
  for (bool Changed = true; Changed;) {
    Changed = false;
    for (Function &F : M)
      for (Instruction &I : make_early_inc_range(instructions(F)))
        if ((isa<SelectInst>(I) || isa<PHINode>(I) || isa<IntToPtrInst>(I)) &&
            I.getType()->isPointerTy() && I.use_empty()) {
          I.eraseFromParent();
          Changed = true;
        }
  }

  // 5. Address-taken functions first, so codegen lays their frames out
  //    before any caller that reaches them indirectly.
  for (const Function *CF : reverse(T.Taken)) {
    Function *F = const_cast<Function *>(CF);
    F->removeFromParent();
    M.getFunctionList().push_front(F);
  }
}
