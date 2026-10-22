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
// A pointer in memory (CP-3; ISA v1.9 §5.7, O-54) is the host's flat 64-bit
// address, never the pair, so loading one is two 32-bit loads and a split:
//
//     rbase = (hi << 16) | (lo >> 16),  roffset = lo & 0xFFFF
//
// rebuilt in the same shape as a parameter. Storing one decomposes it and
// joins the halves, with the carry §5.7 asks for, since a register roffset
// may exceed 16 bits:
//
//     lo = (rbase << 16) + roffset,  hi = (rbase >> 16) + (lo <u roffset)
//
// What does not decompose stays as it was, and CCVCheckIR then reports it as
// before: a pointer from a phi or a select, or into .shared or a frame.
//
//===----------------------------------------------------------------------===//
#include "CCVCheckIR.h"
#include "CCVFrameLowering.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/GetElementPtrTypeIterator.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
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

// Mutation controls for tools/check-ptrmem.sh: drop the carry from a stored
// pointer's low word into its high word, or read a loaded pointer's words in
// the wrong order. Both compile cleanly, so the values must catch them.
static cl::opt<bool> TestNoPtrCarry(
    "ccv-test-no-ptr-carry", cl::init(false), cl::Hidden,
    cl::desc("store pointers without the carry, to test that it is caught"));
static cl::opt<bool> TestSwapPtrHalves(
    "ccv-test-swap-ptr-halves", cl::init(false), cl::Hidden,
    cl::desc("load pointers with their words swapped, to test that it is caught"));

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

/// A load or store of a pointer the AGU reaches through a window. Volatile
/// is kept on both halves, as any 32-bit target splits a 64-bit volatile
/// access. An atomic one cannot be split and is diagnosed.
bool memPointer(const Instruction &I) {
  if (auto *LI = dyn_cast<LoadInst>(&I))
    return !LI->isAtomic() && isWindowed(LI->getType());
  if (auto *SI = dyn_cast<StoreInst>(&I))
    return !SI->isAtomic() && isWindowed(SI->getValueOperand()->getType());
  return false;
}

/// The two 32-bit halves of a pointer access at Addr: the low word, then the
/// high word four bytes on, both little-endian (§5.7).
std::pair<Value *, Value *> halves(IRBuilder<> &B, Value *Addr) {
  Value *Hi = B.CreateConstInBoundsGEP1_32(B.getInt8Ty(), Addr, 4);
  return {Addr, Hi};
}

/// Loads of pointers, rewritten before anything else so that a pointer read
/// from memory can then be passed, forwarded and stored like any other.
void lowerPointerLoads(Module &M) {
  for (Function &F : M)
    for (BasicBlock &BB : F)
      for (Instruction &I : make_early_inc_range(BB)) {
        auto *LI = dyn_cast<LoadInst>(&I);
        if (!LI || !memPointer(I))
          continue;
        IRBuilder<> B(LI);
        Align A = std::min(LI->getAlign(), Align(4));
        auto [LoP, HiP] = halves(B, LI->getPointerOperand());
        if (TestSwapPtrHalves)
          std::swap(LoP, HiP);
        Value *Lo = B.CreateAlignedLoad(B.getInt32Ty(), LoP, A, LI->isVolatile());
        Value *Hi = B.CreateAlignedLoad(B.getInt32Ty(), HiP, A, LI->isVolatile());
        Value *RBase = B.CreateOr(B.CreateShl(Hi, 16), B.CreateLShr(Lo, 16));
        Value *ROff = B.CreateAnd(Lo, B.getInt32(0xFFFF));
        LI->replaceAllUsesWith(rebuild(B, RBase, ROff, LI->getType()));
        LI->eraseFromParent();
      }
}

/// Stores of pointers, after every pointer has its rebuilt shape.
void lowerPointerStores(Module &M) {
  const DataLayout &DL = M.getDataLayout();
  for (Function &F : M)
    for (BasicBlock &BB : F)
      for (Instruction &I : make_early_inc_range(BB)) {
        auto *SI = dyn_cast<StoreInst>(&I);
        if (!SI || !memPointer(I))
          continue;
        IRBuilder<> B(SI);
        Value *Lo, *Hi;
        if (isa<ConstantPointerNull>(SI->getValueOperand())) {
          Lo = Hi = B.getInt32(0);
        } else {
          auto P = decompose(SI->getValueOperand(), B, DL);
          if (!P)
            continue;                  // CCVCheckIR names it
          Lo = B.CreateAdd(B.CreateShl(P->Base, 16), P->Off);
          Hi = B.CreateLShr(P->Base, 16);
          // A compare and a predicated add (§5.7; §4 has no add-with-carry).
          if (!TestNoPtrCarry)
            Hi = B.CreateSelect(B.CreateICmpULT(Lo, P->Off),
                                B.CreateAdd(Hi, B.getInt32(1)), Hi);
        }
        Align A = std::min(SI->getAlign(), Align(4));
        auto [LoP, HiP] = halves(B, SI->getPointerOperand());
        B.CreateAlignedStore(Lo, LoP, A, SI->isVolatile());
        B.CreateAlignedStore(Hi, HiP, A, SI->isVolatile());
        SI->eraseFromParent();
      }
}

bool eligible(const Function &F) {
  if (F.isDeclaration() || ccvIsKernel(F) || F.isVarArg())
    return false;
  bool Any = isWindowed(F.getReturnType());
  for (const Argument &A : F.args())
    Any |= isWindowed(A.getType());
  if (!Any)
    return false;
  // Every use a direct call, or the code address CCVCodePointers made of an
  // address-taken function. Its indirect calls are rewritten by the same rule
  // in step 2, so they keep matching it (calling-convention.md §4).
  for (const Use &U : F.uses()) {
    auto *CB = dyn_cast<CallBase>(U.getUser());
    auto *CE = dyn_cast<ConstantExpr>(U.getUser());
    if (!(CB && CB->isCallee(&U)) &&
        !(CE && CE->getOpcode() == Instruction::PtrToInt))
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

  // 0. Pointers read from memory take the rebuilt shape first.
  lowerPointerLoads(M);

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
    // In F's place, not at the end: module order is codegen's order among
    // call-graph roots, and CCVCodePointers put indirect targets first.
    Function *NF = Function::Create(FunctionType::get(Ret, Params, false),
                                    F.getLinkage(), F.getAddressSpace(), "");
    M.getFunctionList().insert(F.getIterator(), NF);
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
      auto *CB = dyn_cast<CallBase>(U);
      if (!CB)
        continue;                      // a code address: moved to NF below
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
    F->replaceAllUsesWith(NF);         // both are `ptr`: the code addresses
    F->eraseFromParent();
  }

  // 2b. Indirect calls, by the same rule as the functions they reach.
  for (Function &Fn : M)
    for (Instruction &I : make_early_inc_range(instructions(Fn))) {
      auto *CB = dyn_cast<CallBase>(&I);
      if (!CB || CB->getCalledFunction() || CB->isInlineAsm())
        continue;
      FunctionType *FT = CB->getFunctionType();
      bool Any = isWindowed(FT->getReturnType());
      for (Type *P : FT->params())
        Any |= isWindowed(P);
      if (!Any)
        continue;
      IRBuilder<> B(CB);
      SmallVector<Type *, 8> Params;
      SmallVector<Value *, 8> Args;
      bool OK = true;
      for (Value *A : CB->args()) {
        if (!isWindowed(A->getType())) {
          Params.push_back(A->getType());
          Args.push_back(A);
          continue;
        }
        auto P = decompose(A, B, DL);
        if (!P) {
          OK = false;
          break;
        }
        Params.append({I32, I32});
        Args.append({P->Base, P->Off});
      }
      if (!OK)
        report_fatal_error("CCV: a pointer passed by an indirect call in " +
                           Fn.getName() + " is not one this compiler can split "
                           "into a window and an offset (F-22, CP-3)");
      Type *Ret = isWindowed(FT->getReturnType()) ? PairTy : FT->getReturnType();
      auto *NC = B.CreateCall(FunctionType::get(Ret, Params, false),
                              CB->getCalledOperand(), Args);
      if (isWindowed(CB->getType())) {
        Value *RB = B.CreateExtractValue(NC, 0), *RO = B.CreateExtractValue(NC, 1);
        CB->replaceAllUsesWith(rebuild(B, RB, RO, CB->getType()));
      } else if (!CB->getType()->isVoidTy()) {
        CB->replaceAllUsesWith(NC);
      }
      NC->takeName(CB);
      CB->eraseFromParent();
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

  // 4. Pointers written to memory, now that every pointer can decompose.
  lowerPointerStores(M);
}
