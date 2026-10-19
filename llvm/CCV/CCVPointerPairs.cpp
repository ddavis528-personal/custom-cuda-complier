//===-- CCVPointerPairs.cpp - pointers cross a call as (rbase, roffset) ---===//
//
// F-22, for calls (proposals/calling-convention.md §3). Invariant 11 keeps an
// address out of every register: the AGU forms it from a window index and an
// in-window offset, two 32-bit values. So a pointer crosses a call as exactly
// that pair, in two argument registers, and a returned pointer comes back in
// R1:R2.
//
// The rewrite is on IR, before CCVCheckIR, and it needs nothing new from the
// backend: the callee rebuilds each pointer parameter as
//
//     inttoptr((zext rbase << 16) + zext roffset)
//
// which is the shape CCVLowerKernelArgs already gives a kernel's pointer
// arguments and the address combine already matches. A caller decomposes the
// pointer it passes into the pair it was built from, walking back through
// GEPs and adding their byte offsets to roffset in 32-bit arithmetic -- the
// unaligned ABI's fold, under the same one-allocation precondition (F-23).
//
// What does not decompose stays as it was, and CCVCheckIR then reports it as
// before: a pointer from a phi or a select, from memory (CP-3), or into
// .shared or a frame.
//
//===----------------------------------------------------------------------===//
#include "CCVCheckIR.h"
#include "CCVFrameLowering.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/GetElementPtrTypeIterator.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Operator.h"
#include "llvm/IR/PatternMatch.h"
#include "llvm/Support/CommandLine.h"
#include <optional>

using namespace llvm;
using namespace llvm::PatternMatch;

// Mutation control for tools/check-calls.sh: forget a GEP's offset when
// splitting a pointer, so a forwarded or returned pointer names the wrong
// element. It must be caught by the values, since it compiles cleanly.
static cl::opt<bool> TestDropPairOffset(
    "ccv-test-drop-pair-offset", cl::init(false), cl::Hidden,
    cl::desc("drop GEP offsets when splitting a pointer, to test that it is caught"));

namespace {

struct Pair {
  Value *Base, *Off;
};

/// A pointer the AGU can reach through a window: generic or .global. .shared
/// is flat 32-bit (§5.1) and a frame pointer is R15's, so neither is a pair.
bool isWindowed(Type *T) {
  auto *PT = dyn_cast<PointerType>(T);
  return PT && (PT->getAddressSpace() == 0 || PT->getAddressSpace() == 1);
}

/// An i32 for a GEP index: the operand of the sign- or zero-extension clang
/// put there, or a truncation. Byte offsets are 32-bit by F-23.
Value *narrow(IRBuilder<> &B, Value *Idx) {
  Value *X;
  if ((match(Idx, m_SExt(m_Value(X))) || match(Idx, m_ZExt(m_Value(X)))) &&
      X->getType()->isIntegerTy(32))
    return X;
  return B.CreateSExtOrTrunc(Idx, B.getInt32Ty());
}

/// The (rbase, roffset) a pointer was built from, materialized at B's
/// insertion point, or nothing if it was not built from one.
std::optional<Pair> decompose(Value *V, IRBuilder<> &B, const DataLayout &DL) {
  V = V->stripPointerCasts();

  if (auto *GEP = dyn_cast<GEPOperator>(V)) {
    auto P = decompose(GEP->getPointerOperand(), B, DL);
    if (!P)
      return std::nullopt;
    Value *Off = P->Off;
    for (gep_type_iterator GTI = gep_type_begin(GEP), E = gep_type_end(GEP);
         GTI != E; ++GTI) {
      Value *Idx = GTI.getOperand();
      if (StructType *ST = GTI.getStructTypeOrNull()) {
        uint64_t F = DL.getStructLayout(ST)->getElementOffset(
            unsigned(cast<ConstantInt>(Idx)->getZExtValue()));
        if (F)
          Off = B.CreateAdd(Off, B.getInt32(uint32_t(F)));
        continue;
      }
      uint64_t Size = DL.getTypeAllocSize(GTI.getIndexedType());
      if (auto *C = dyn_cast<ConstantInt>(Idx)) {
        if (!C->isZero())
          Off = B.CreateAdd(Off, B.getInt32(uint32_t(C->getSExtValue() * Size)));
        continue;
      }
      Off = B.CreateAdd(Off, B.CreateMul(narrow(B, Idx), B.getInt32(uint32_t(Size))));
    }
    return Pair{P->Base, TestDropPairOffset ? P->Off : Off};
  }

  Value *Int = nullptr;
  if (auto *I2P = dyn_cast<IntToPtrInst>(V))
    Int = I2P->getOperand(0);
  else if (auto *CE = dyn_cast<ConstantExpr>(V))
    if (CE->getOpcode() == Instruction::IntToPtr)
      Int = CE->getOperand(0);
  if (!Int)
    return std::nullopt;

  // (zext rbase << 16) + zext roffset, either operand order, or with no
  // offset at all for an aligned pointer (O-23).
  Value *RBase, *ROff;
  if (match(Int, m_c_Add(m_Shl(m_ZExt(m_Value(RBase)), m_SpecificInt(16)),
                         m_ZExt(m_Value(ROff)))) ||
      match(Int, m_c_DisjointOr(m_Shl(m_ZExt(m_Value(RBase)), m_SpecificInt(16)),
                                m_ZExt(m_Value(ROff))))) {
    if (RBase->getType()->isIntegerTy(32) && ROff->getType()->isIntegerTy(32))
      return Pair{RBase, ROff};
    return std::nullopt;
  }
  if (match(Int, m_Shl(m_ZExt(m_Value(RBase)), m_SpecificInt(16))) &&
      RBase->getType()->isIntegerTy(32))
    return Pair{RBase, B.getInt32(0)};
  return std::nullopt;
}

Value *rebuild(IRBuilder<> &B, Value *RBase, Value *ROff, Type *PtrTy) {
  Value *W = B.CreateShl(B.CreateZExt(RBase, B.getInt64Ty()), 16);
  Value *A = B.CreateAdd(W, B.CreateZExt(ROff, B.getInt64Ty()), "", true, true);
  return B.CreateIntToPtr(A, PtrTy);
}

bool eligible(const Function &F) {
  if (F.isDeclaration() || ccvIsKernel(F) || F.isVarArg())
    return false;
  bool Any = isWindowed(F.getReturnType());
  for (const Argument &A : F.args())
    Any |= isWindowed(A.getType());
  if (!Any)
    return false;
  // Every use a direct call: an address-taken function keeps its signature
  // until indirect calls exist (calling-convention.md §4).
  for (const Use &U : F.uses()) {
    auto *CB = dyn_cast<CallBase>(U.getUser());
    if (!CB || !CB->isCallee(&U))
      return false;
  }
  return true;
}

} // namespace

void llvm::lowerCCVPointerPairs(Module &M) {
  const DataLayout &DL = M.getDataLayout();
  LLVMContext &Ctx = M.getContext();
  Type *I32 = Type::getInt32Ty(Ctx);
  StructType *PairTy = StructType::get(I32, I32);

  // 1. New signatures. Each windowed pointer parameter becomes two i32, and
  //    a windowed pointer return becomes {i32, i32}. The body moves across,
  //    and each pointer parameter is rebuilt at entry.
  SmallVector<std::pair<Function *, Function *>, 8> Rewritten;
  for (Function &F : make_early_inc_range(M)) {
    if (!eligible(F))
      continue;
    SmallVector<Type *, 8> Params;
    for (Argument &A : F.args()) {
      Params.push_back(isWindowed(A.getType()) ? I32 : A.getType());
      if (isWindowed(A.getType()))
        Params.push_back(I32);
    }
    Type *Ret = isWindowed(F.getReturnType()) ? PairTy : F.getReturnType();
    Function *NF = Function::Create(FunctionType::get(Ret, Params, false),
                                    F.getLinkage(), F.getAddressSpace(), "", &M);
    NF->copyAttributesFrom(&F);
    NF->setAttributes(AttributeList());         // types changed; keep none
    NF->addFnAttrs(AttrBuilder(Ctx, F.getAttributes().getFnAttrs()));
    NF->takeName(&F);
    NF->splice(NF->end(), &F);

    IRBuilder<> B(&*NF->getEntryBlock().getFirstInsertionPt());
    auto NA = NF->arg_begin();
    for (Argument &A : F.args()) {
      if (!isWindowed(A.getType())) {
        A.replaceAllUsesWith(&*NA);
        NA->takeName(&A);
        ++NA;
        continue;
      }
      Argument *RB = &*NA++, *RO = &*NA++;
      RB->setName(A.getName() + ".rbase");
      RO->setName(A.getName() + ".roffset");
      A.replaceAllUsesWith(rebuild(B, RB, RO, A.getType()));
    }
    Rewritten.push_back({&F, NF});
  }

  // 2. Call sites. Every caller's pointers are now in the rebuilt shape, its
  //    own parameters included, so they decompose.
  for (auto [F, NF] : Rewritten) {
    for (User *U : make_early_inc_range(F->users())) {
      auto *CB = cast<CallBase>(U);
      IRBuilder<> B(CB);
      SmallVector<Value *, 8> Args;
      bool OK = true;
      for (Value *A : CB->args()) {
        if (!isWindowed(A->getType())) {
          Args.push_back(A);
          continue;
        }
        auto P = decompose(A, B, DL);
        if (!P) {
          OK = false;
          break;
        }
        Args.push_back(P->Base);
        Args.push_back(P->Off);
      }
      if (!OK)
        report_fatal_error(
            "CCV: a pointer passed to " + NF->getName() +
            " is not one this compiler can split into a window and an offset "
            "-- one read from memory, or from a phi or a select (F-22, CP-3)");
      auto *NC = B.CreateCall(NF, Args);
      if (isWindowed(CB->getType())) {
        Value *RB = B.CreateExtractValue(NC, 0), *RO = B.CreateExtractValue(NC, 1);
        CB->replaceAllUsesWith(rebuild(B, RB, RO, CB->getType()));
      } else if (!CB->getType()->isVoidTy()) {
        CB->replaceAllUsesWith(NC);
      }
      NC->takeName(CB);
      CB->eraseFromParent();
    }
    F->eraseFromParent();
  }

  // 3. Returns. A returned pointer decomposes at its `ret`, now that every
  //    pointer a callee hands back has been rebuilt in step 2.
  for (Function &F : M) {
    if (!F.getReturnType()->isStructTy() || F.getReturnType() != PairTy)
      continue;
    for (BasicBlock &BB : F) {
      auto *RI = dyn_cast<ReturnInst>(BB.getTerminator());
      if (!RI || !RI->getReturnValue() ||
          !isWindowed(RI->getReturnValue()->getType()))
        continue;
      IRBuilder<> B(RI);
      auto P = decompose(RI->getReturnValue(), B, DL);
      if (!P)
        report_fatal_error("CCV: " + F.getName() +
                           " returns a pointer this compiler cannot split into "
                           "a window and an offset (F-22, CP-3)");
      Value *Agg = B.CreateInsertValue(PoisonValue::get(PairTy), P->Base, 0);
      Agg = B.CreateInsertValue(Agg, P->Off, 1);
      B.CreateRet(Agg);
      RI->eraseFromParent();
    }
  }
}
