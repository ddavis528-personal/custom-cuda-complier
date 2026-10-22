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
#include "llvm/ADT/DenseMap.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/GetElementPtrTypeIterator.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/ValueHandle.h"
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
static cl::opt<bool> TestRawPtrCompare(
    "ccv-test-raw-ptr-compare", cl::init(false), cl::Hidden,
    cl::desc("compare pointers' pairs rather than their addresses, to test "
             "that it is caught"));
static cl::opt<bool> TestSwapPtrHalves(
    "ccv-test-swap-ptr-halves", cl::init(false), cl::Hidden,
    cl::desc("load pointers with their words swapped, to test that it is caught"));

namespace {

struct Pair {
  Value *Base, *Off;
};

/// A pointer the AGU can reach through a window: generic, .global or .const
/// (a module's constant data, O-61). .shared is flat 32-bit (§5.1).
bool isWindowed(Type *T) {
  auto *PT = dyn_cast<PointerType>(T);
  unsigned AS = PT ? PT->getAddressSpace() : ~0u;
  return AS == 0 || AS == 1 || AS == 4;
}

/// An i64 index expression rebuilt in 32 bits, or null: extensions of i32
/// values, constants, and the arithmetic whose low 32 bits depend only on its
/// operands' low 32 bits. Sound for a byte offset, which is 32-bit by F-23.
Value *narrowTree(IRBuilder<> &B, Value *V, unsigned Depth = 0) {
  Value *X;
  if (V->getType()->isIntegerTy(32))
    return V;
  if ((match(V, m_SExt(m_Value(X))) || match(V, m_ZExt(m_Value(X)))) &&
      X->getType()->isIntegerTy(32))
    return X;
  if (auto *C = dyn_cast<ConstantInt>(V))
    return B.getInt32(uint32_t(C->getZExtValue()));
  auto *BO = dyn_cast<BinaryOperator>(V);
  if (!BO || Depth > 8)
    return nullptr;
  switch (BO->getOpcode()) {
  case Instruction::Add: case Instruction::Sub: case Instruction::Mul:
  case Instruction::And: case Instruction::Or:  case Instruction::Xor:
  case Instruction::Shl:
    break;
  default:
    return nullptr;
  }
  Value *L = narrowTree(B, BO->getOperand(0), Depth + 1);
  Value *R = L ? narrowTree(B, BO->getOperand(1), Depth + 1) : nullptr;
  return R ? B.CreateBinOp(BO->getOpcode(), L, R) : nullptr;
}

/// An i32 for a GEP index: the operand of the sign- or zero-extension clang
/// put there, the index rebuilt in 32 bits, or a truncation. Byte offsets are
/// 32-bit by F-23.
Value *narrow(IRBuilder<> &B, Value *Idx) {
  if (Value *N = narrowTree(B, Idx))
    return N;
  return B.CreateSExtOrTrunc(Idx, B.getInt32Ty());
}

/// Is V an index the backend's address matcher takes as it is: a constant, or
/// a 32-bit value, extended or not?
bool simpleIndex(Value *V) {
  Value *X;
  return isa<ConstantInt>(V) || V->getType()->isIntegerTy(32) ||
         ((match(V, m_SExt(m_Value(X))) || match(V, m_ZExt(m_Value(X)))) &&
          X->getType()->isIntegerTy(32));
}

/// Do V's users read only its low 32 bits? Followed through the arithmetic
/// whose low bits depend only on its operands' low bits, to truncations, GEP
/// indices and masks. Anything else -- a compare, a division, a store of the
/// whole value -- may read the high half.
bool onlyLowBits(Value *V, unsigned Depth = 0) {
  if (Depth > 8)
    return false;
  for (User *U : V->users()) {
    if (auto *T = dyn_cast<TruncInst>(U); T && T->getType()->getIntegerBitWidth() <= 32)
      continue;
    if (auto *G = dyn_cast<GetElementPtrInst>(U); G && G->getPointerOperand() != V)
      continue;
    auto *BO = dyn_cast<BinaryOperator>(U);
    if (!BO)
      return false;
    if (BO->getOpcode() == Instruction::And)
      if (auto *C = dyn_cast<ConstantInt>(BO->getOperand(1)); C && C->getValue().isIntN(32))
        continue;
    switch (BO->getOpcode()) {
    case Instruction::Add: case Instruction::Sub: case Instruction::Mul:
    case Instruction::And: case Instruction::Or:  case Instruction::Xor:
    case Instruction::Shl:
      if (!onlyLowBits(BO, Depth + 1))
        return false;
      continue;
    default:
      return false;
    }
  }
  return true;
}

/// Pairs already built for pointer phis and selects (step 2.5), while that
/// step runs: a phi's pair is made before its incoming values are, so a loop
/// can refer to itself.
DenseMap<Value *, Pair> *Known = nullptr;

/// The (rbase, roffset) a pointer was built from, materialized at B's
/// insertion point, or nothing if it was not built from one.
std::optional<Pair> decompose(Value *V, IRBuilder<> &B, const DataLayout &DL) {
  V = V->stripPointerCasts();
  if (Known)
    if (auto It = Known->find(V); It != Known->end())
      return It->second;

  // NULL is address 0: window 0, offset 0.
  if (isa<ConstantPointerNull>(V) || isa<UndefValue>(V))
    return Pair{B.getInt32(0), B.getInt32(0)};

  // A select of pointers is a select of each half, made where the select is.
  if (auto *S = dyn_cast<SelectInst>(V); S && Known) {
    IRBuilder<> SB(S);
    auto T = decompose(S->getTrueValue(), SB, DL);
    auto F = T ? decompose(S->getFalseValue(), SB, DL) : std::nullopt;
    if (!T || !F)
      return std::nullopt;
    Pair P{SB.CreateSelect(S->getCondition(), T->Base, F->Base),
           SB.CreateSelect(S->getCondition(), T->Off, F->Off)};
    return (*Known)[S] = P;
  }

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

  // A pointer into the thread's frame. Frame slot d (-4096 <= d < 0) is at
  // (R15 << 16) + d, which as a pair is (R15 - 1, 65536 + d): the window below
  // R15's and an offset only frame layout knows. The backend recognises these
  // two calls by name (CCVISelLowering, LowerCall).
  if (auto *AI = dyn_cast<AllocaInst>(V)) {
    Module *M = AI->getModule();
    Type *I32 = B.getInt32Ty();
    FunctionCallee W =
        M->getOrInsertFunction("__ccv_frame_window", FunctionType::get(I32, false));
    FunctionCallee O = M->getOrInsertFunction(
        "__ccv_frame_offset", FunctionType::get(I32, {AI->getType()}, false));
    for (FunctionCallee C : {W, O})
      cast<Function>(C.getCallee())->setDoesNotAccessMemory();
    return Pair{B.CreateCall(W), B.CreateCall(O, {AI})};
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
  // A constant offset: a global in the module's data image (O-61), whose
  // `zext` of an i32 offset constant-folded to an i64 constant.
  const APInt *K;
  if (match(Int, m_c_Add(m_Shl(m_ZExt(m_Value(RBase)), m_SpecificInt(16)),
                         m_APInt(K))) &&
      RBase->getType()->isIntegerTy(32) && K->isIntN(32))
    return Pair{RBase, B.getInt32(uint32_t(K->getZExtValue()))};
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

/// A pair's flat 64-bit address as two words (§5.7): lo = (rbase << 16) +
/// roffset, hi = (rbase >> 16) plus the carry out of lo. The carry is the
/// arithmetic carry-out of x + y = s, ((x & y) | ((x | y) & ~s)) >> 31, not a
/// compare and a predicated add: there are three allocatable predicates, and
/// seven pointer stores scheduled together held seven carries live at once,
/// which ran the allocator out of predicate registers rather than spilling.
std::pair<Value *, Value *> flat(IRBuilder<> &B, Value *RBase, Value *ROff,
                                 bool Carry = true) {
  Value *X = B.CreateShl(RBase, 16), *Y = ROff;
  Value *Lo = B.CreateAdd(X, Y);
  Value *Hi = B.CreateLShr(RBase, 16);
  if (Carry)
    Hi = B.CreateAdd(
        Hi, B.CreateLShr(B.CreateOr(B.CreateAnd(X, Y),
                                    B.CreateAnd(B.CreateOr(X, Y), B.CreateNot(Lo))),
                         31));
  return {Lo, Hi};
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
          std::tie(Lo, Hi) = flat(B, P->Base, P->Off, !TestNoPtrCarry);
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

  // 0b. A 64-bit integer access is two 32-bit ones, low word first: there is
  //     no 64-bit load or store, and the type legalizer cannot split one whose
  //     address has already become a frame or window node. The middle end
  //     makes them by merging narrower stores -- four 16-bit zeroings of
  //     CoreMark's CRC fields became one `store i64 0`.
  for (Function &F : M)
    for (Instruction &I : make_early_inc_range(instructions(F))) {
      IRBuilder<> B(&I);
      if (auto *SI = dyn_cast<StoreInst>(&I);
          SI && SI->isSimple() && SI->getValueOperand()->getType()->isIntegerTy(64)) {
        Value *V = SI->getValueOperand();
        Align A = std::min(SI->getAlign(), Align(4));
        auto [LoP, HiP] = halves(B, SI->getPointerOperand());
        B.CreateAlignedStore(B.CreateTrunc(V, I32), LoP, A);
        B.CreateAlignedStore(B.CreateTrunc(B.CreateLShr(V, 32), I32), HiP, A);
        SI->eraseFromParent();
      } else if (auto *LI = dyn_cast<LoadInst>(&I);
                 LI && LI->isSimple() && LI->getType()->isIntegerTy(64)) {
        Align A = std::min(LI->getAlign(), Align(4));
        auto [LoP, HiP] = halves(B, LI->getPointerOperand());
        Value *Lo = B.CreateZExt(B.CreateAlignedLoad(I32, LoP, A), LI->getType());
        Value *Hi = B.CreateZExt(B.CreateAlignedLoad(I32, HiP, A), LI->getType());
        LI->replaceAllUsesWith(B.CreateOr(Lo, B.CreateShl(Hi, 32)));
        LI->eraseFromParent();
      }
    }

  // Call arguments step 2 could not split until step 2.5 has given every
  // pointer phi and select its pair: the call, the argument's first slot, and
  // the pointer, tracked through step 2.5's replacement.
  struct Later {
    CallInst *NC;
    unsigned K;
    WeakTrackingVH A;
  };
  SmallVector<Later, 8> Pending;

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
      SmallVector<std::pair<unsigned, Value *>, 2> Later;
      for (Value *A : CB->args()) {
        if (!isWindowed(A->getType())) {
          Args.push_back(A);
          continue;
        }
        auto P = decompose(A, B, DL);
        if (!P) {                      // a phi or a select: step 2.5 first
          Later.push_back({unsigned(Args.size()), A});
          Args.append({PoisonValue::get(I32), PoisonValue::get(I32)});
          continue;
        }
        Args.push_back(P->Base);
        Args.push_back(P->Off);
      }
      auto *NC = B.CreateCall(NF, Args);
      for (auto [K, A] : Later)
        Pending.push_back({NC, K, WeakTrackingVH(A)});
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
      SmallVector<std::pair<unsigned, Value *>, 2> Later;
      for (Value *A : CB->args()) {
        if (!isWindowed(A->getType())) {
          Params.push_back(A->getType());
          Args.push_back(A);
          continue;
        }
        Params.append({I32, I32});
        auto P = decompose(A, B, DL);
        if (!P) {
          Later.push_back({unsigned(Args.size()), A});
          Args.append({PoisonValue::get(I32), PoisonValue::get(I32)});
          continue;
        }
        Args.append({P->Base, P->Off});
      }
      Type *Ret = isWindowed(FT->getReturnType()) ? PairTy : FT->getReturnType();
      auto *NC = B.CreateCall(FunctionType::get(Ret, Params, false),
                              CB->getCalledOperand(), Args);
      for (auto [K, A] : Later)
        Pending.push_back({NC, K, WeakTrackingVH(A)});
      if (isWindowed(CB->getType())) {
        Value *RB = B.CreateExtractValue(NC, 0), *RO = B.CreateExtractValue(NC, 1);
        CB->replaceAllUsesWith(rebuild(B, RB, RO, CB->getType()));
      } else if (!CB->getType()->isVoidTy()) {
        CB->replaceAllUsesWith(NC);
      }
      NC->takeName(CB);
      CB->eraseFromParent();
    }

  // 2.5. Pointer phis and selects become pairs: two i32 phis, made before
  //      their incoming values so a loop's phi can refer to itself, and a
  //      select of each half. Each original is then replaced by its rebuilt
  //      shape, which everything after this decomposes.
  {
    DenseMap<Value *, Pair> Map;
    Known = &Map;
    SmallVector<PHINode *, 16> Phis;
    SmallVector<SelectInst *, 16> Selects;
    for (Function &F : M)
      for (Instruction &I : instructions(F)) {
        if (auto *PN = dyn_cast<PHINode>(&I); PN && isWindowed(PN->getType())) {
          IRBuilder<> PB(PN);
          unsigned N = PN->getNumIncomingValues();
          Map[PN] = Pair{PB.CreatePHI(I32, N, PN->getName() + ".rbase"),
                         PB.CreatePHI(I32, N, PN->getName() + ".roffset")};
          Phis.push_back(PN);
        } else if (auto *S = dyn_cast<SelectInst>(&I); S && isWindowed(S->getType())) {
          Selects.push_back(S);
        }
      }
    auto Fail = [](Instruction *I) {
      report_fatal_error("CCV: a pointer " +
                         Twine(isa<PHINode>(I) ? "phi" : "select") + " in " +
                         I->getFunction()->getName() +
                         " has a value this compiler cannot split into a "
                         "window and an offset (F-22)");
    };
    for (PHINode *PN : Phis) {
      Pair P = Map[PN];
      for (unsigned I = 0, E = PN->getNumIncomingValues(); I != E; ++I) {
        BasicBlock *From = PN->getIncomingBlock(I);
        IRBuilder<> IB(From->getTerminator());
        auto X = decompose(PN->getIncomingValue(I), IB, DL);
        if (!X)
          Fail(PN);
        cast<PHINode>(P.Base)->addIncoming(X->Base, From);
        cast<PHINode>(P.Off)->addIncoming(X->Off, From);
      }
    }
    for (SelectInst *S : Selects) {
      IRBuilder<> SB(S);
      if (!decompose(S, SB, DL))
        Fail(S);
    }
    for (PHINode *PN : Phis) {
      IRBuilder<> B(&*PN->getParent()->getFirstInsertionPt());
      PN->replaceAllUsesWith(rebuild(B, Map[PN].Base, Map[PN].Off, PN->getType()));
    }
    for (SelectInst *S : Selects) {
      IRBuilder<> B(S);
      S->replaceAllUsesWith(rebuild(B, Map[S].Base, Map[S].Off, S->getType()));
    }
    for (PHINode *PN : Phis)
      PN->eraseFromParent();
    for (SelectInst *S : Selects)
      S->eraseFromParent();
    Known = nullptr;
  }

  // 2.75. The call arguments step 2 could not split yet.
  for (auto &[NC, K, A] : Pending) {
    IRBuilder<> B(NC);
    auto P = A ? decompose(A, B, DL) : std::nullopt;
    if (!P)
      report_fatal_error("CCV: a pointer passed to a call in " +
                         NC->getFunction()->getName() +
                         " is not one this compiler can split into a window "
                         "and an offset (F-22, CP-3)");
    NC->setArgOperand(K, P->Base);
    NC->setArgOperand(K + 1, P->Off);
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

  // 6 (below, after 5 has turned pointer conversions into integers). An
  //    address with an index the backend's matcher does not take -- an i64
  //    expression, as align_mem leaves, or a second dynamic index -- is
  //    rebuilt as one pair, its whole byte offset folded into the offset in
  //    32 bits.
  auto FoldAddresses = [&] {
    for (Function &F : M)
      for (Instruction &I : instructions(F)) {
        Value *Addr = nullptr;
        if (auto *LI = dyn_cast<LoadInst>(&I))
          Addr = LI->getPointerOperand();
        else if (auto *SI = dyn_cast<StoreInst>(&I))
          Addr = SI->getPointerOperand();
        if (!Addr || !isWindowed(Addr->getType()))
          continue;
        // Also more than one dynamic index, as `p[total + i]` written as two
        // GEPs: with the window and the offset that is more register addends
        // than the AGU takes (§5.1).
        bool Simple = true;
        unsigned Dynamic = 0;
        for (Value *W = Addr; auto *G = dyn_cast<GEPOperator>(W);
             W = G->getPointerOperand())
          for (Value *Idx : G->indices()) {
            Simple &= simpleIndex(Idx);
            Dynamic += !isa<ConstantInt>(Idx);
          }
        if (Simple && Dynamic <= 1)
          continue;
        IRBuilder<> B(&I);
        if (auto P = decompose(Addr, B, DL))
          I.replaceUsesOfWith(Addr, rebuild(B, P->Base, P->Off, Addr->getType()));
      }
  };

  // 5. Pointers compared, and a pointer's low bits read as an integer: both
  //    take the flat address (§5.7), since two pairs can name one address
  //    with different offsets.
  for (Function &F : M)
    for (Instruction &I : make_early_inc_range(instructions(F))) {
      IRBuilder<> B(&I);
      if (auto *C = dyn_cast<ICmpInst>(&I)) {
        if (!isWindowed(C->getOperand(0)->getType()) || C->isSigned())
          continue;
        auto PA = decompose(C->getOperand(0), B, DL);
        auto PB = PA ? decompose(C->getOperand(1), B, DL) : std::nullopt;
        if (!PB)
          continue;                    // CCVCheckIR names it
        auto [LA, HA] = flat(B, PA->Base, PA->Off);
        auto [LB, HB] = flat(B, PB->Base, PB->Off);
        if (TestRawPtrCompare) {
          LA = PA->Off, HA = PA->Base, LB = PB->Off, HB = PB->Base;
        }
        Value *R;
        if (C->isEquality()) {          // one compare: both words' differences
          R = B.CreateICmp(C->getPredicate(),
                           B.CreateOr(B.CreateXor(LA, LB), B.CreateXor(HA, HB)),
                           B.getInt32(0));
        } else {                       // unsigned: the high words, then the low
          R = B.CreateOr(B.CreateICmp(C->getStrictPredicate(), HA, HB),
                         B.CreateAnd(B.CreateICmpEQ(HA, HB),
                                     B.CreateICmp(C->getPredicate(), LA, LB)));
        }
        C->replaceAllUsesWith(R);
        C->eraseFromParent();
      } else if (auto *PI = dyn_cast<PtrToIntInst>(&I)) {
        if (!isWindowed(PI->getPointerOperand()->getType()))
          continue;
        auto P = decompose(PI->getPointerOperand(), B, DL);
        if (!P)
          continue;
        Value *Lo = flat(B, P->Base, P->Off, false).first;
        // Only the low 32 bits are representable without a 64-bit register.
        // A 64-bit conversion whose users read only those -- align_mem's
        // `(-(intptr)p) & 3`, a truncation -- takes the low word extended.
        if (PI->getType()->getIntegerBitWidth() <= 32 || onlyLowBits(PI)) {
          PI->replaceAllUsesWith(B.CreateZExtOrTrunc(Lo, PI->getType()));
          PI->eraseFromParent();
          continue;
        }
        for (User *U : make_early_inc_range(PI->users()))
          if (auto *T = dyn_cast<TruncInst>(U); T && T->getType()->getIntegerBitWidth() <= 32) {
            IRBuilder<> TB(T);
            T->replaceAllUsesWith(TB.CreateZExtOrTrunc(Lo, T->getType()));
            T->eraseFromParent();
          }
        if (PI->use_empty())
          PI->eraseFromParent();
      }
    }
  FoldAddresses();
}
