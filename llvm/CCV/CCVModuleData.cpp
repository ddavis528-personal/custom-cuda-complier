//===-- CCVModuleData.cpp - a module's globals as one data image ----------===//
//
// ISA v1.9 §5.2, O-61 (CP-10). Device code is one closed module, and every
// global it holds -- __constant__ and __device__ variables, string literals,
// lookup tables -- is laid out in one data image: the constant globals first,
// then the writable ones. The runtime loads the image once per module per
// context at W_d << 16 and writes W_d to launch-block word 28.
//
// So a global at image offset o is the pair (W_d, o), which this pass builds
// at each function's entry in the shape CCVPointerPairs and the address
// combine already take: one launch-block load, warp-uniform, then ordinary
// Format D accesses.
//
// The image itself becomes arrays in sections of their own, which the object
// carries beside .text: .ccv_data, the bytes; .ccv_reloc, the image offsets
// of the 8-byte slots holding data pointers, to which the loader adds
// W_d << 16; and .ccv_info, the size of the constant part, which is the
// .const range F-RO protects (§5.2). Such a slot holds its target's image offset until
// then (O-54's flat address, relative to the image). A code pointer would
// need no relocation (O-61), but needs the code layout, which is not known
// here; it is diagnosed until it is needed.
//
//===----------------------------------------------------------------------===//
#include "CCVCheckIR.h"
#include "CCVFrameLowering.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/ReplaceConstant.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

// Mutation controls for tools/check-globals.sh: an image with no relocation
// list, so its data pointers stay image offsets; and the window read from
// word 24 (.local's) rather than 28. Both compile cleanly.
static cl::opt<bool> TestNoDataReloc(
    "ccv-test-no-data-reloc", cl::init(false), cl::Hidden,
    cl::desc("emit no relocation list, to test that it is caught"));
static cl::opt<bool> TestDataWord24(
    "ccv-test-data-word-24", cl::init(false), cl::Hidden,
    cl::desc("read the data window from word 24, to test that it is caught"));

namespace {

constexpr unsigned AS_SHARED = 3, AS_CONST = 4;
constexpr uint64_t OffDataWindow = 28;     // O-61

struct Image {
  const DataLayout &DL;
  DenseMap<const GlobalVariable *, uint64_t> &Offset;
  SmallVector<uint8_t, 256> Bytes;
  SmallVector<uint32_t, 16> Relocs;

  void put(uint64_t At, uint64_t V, unsigned N) {
    for (unsigned I = 0; I != N; ++I)
      Bytes[At + I] = uint8_t(V >> (8 * I));
  }

  void write(const Constant *C, uint64_t At) {
    if (isa<ConstantAggregateZero>(C) || isa<ConstantPointerNull>(C) ||
        isa<UndefValue>(C))
      return;                                   // already zero
    Type *T = C->getType();
    if (auto *CI = dyn_cast<ConstantInt>(C))
      return put(At, CI->getZExtValue(), DL.getTypeStoreSize(T));
    if (auto *CF = dyn_cast<ConstantFP>(C))
      return put(At, CF->getValueAPF().bitcastToAPInt().getZExtValue(),
                 DL.getTypeStoreSize(T));
    if (auto *CDS = dyn_cast<ConstantDataSequential>(C)) {
      uint64_t E = DL.getTypeAllocSize(CDS->getElementType());
      for (unsigned I = 0, N = CDS->getNumElements(); I != N; ++I)
        write(CDS->getElementAsConstant(I), At + I * E);
      return;
    }
    if (auto *CS = dyn_cast<ConstantStruct>(C)) {
      const StructLayout *SL = DL.getStructLayout(CS->getType());
      for (unsigned I = 0, N = CS->getNumOperands(); I != N; ++I)
        write(CS->getOperand(I), At + SL->getElementOffset(I));
      return;
    }
    if (auto *CA = dyn_cast<ConstantArray>(C)) {
      uint64_t E = DL.getTypeAllocSize(CA->getType()->getElementType());
      for (unsigned I = 0, N = CA->getNumOperands(); I != N; ++I)
        write(CA->getOperand(I), At + I * E);
      return;
    }
    if (T->isPointerTy()) {
      APInt Off(64, 0);
      const Value *Base = C->stripAndAccumulateConstantOffsets(DL, Off, true);
      if (auto *G = dyn_cast<GlobalVariable>(Base); G && Offset.count(G)) {
        if (At % 8)
          report_fatal_error("CCV: a pointer in a global's initializer is not "
                             "8-byte aligned (O-61, O-58)");
        put(At, Offset[G] + Off.getZExtValue(), 8);
        Relocs.push_back(uint32_t(At));
        return;
      }
      if (isa<Function>(Base))
        report_fatal_error("CCV: a function pointer in a global's initializer: "
                           "its code address needs the code layout, which is "
                           "not built yet (O-61)");
    }
    report_fatal_error("CCV: a global's initializer has a constant this "
                       "compiler cannot lay out in the data image (O-61)");
  }
};

bool inImage(const GlobalVariable &G) {
  return !G.getName().starts_with("llvm.") && !G.getName().starts_with("__ccv_") &&
         G.getAddressSpace() != AS_SHARED;
}

} // namespace

void llvm::lowerCCVModuleData(Module &M) {
  const DataLayout &DL = M.getDataLayout();
  SmallVector<GlobalVariable *, 16> Const, Writable;
  for (GlobalVariable &G : M.globals()) {
    if (!inImage(G))
      continue;
    if (!G.hasInitializer())
      report_fatal_error("CCV: the global " + G.getName() + " is declared but "
                         "not defined: device code is one closed module (O-61)");
    (G.isConstant() || G.getAddressSpace() == AS_CONST ? Const : Writable).push_back(&G);
  }
  if (Const.empty() && Writable.empty())
    return;

  // 1. Layout: constants first, so the .const range is the image's prefix,
  //    [0, ConstSize): F-RO's range, recorded for the loader in .ccv_info.
  DenseMap<const GlobalVariable *, uint64_t> Offset;
  uint64_t Size = 0, ConstSize = 0;
  for (auto *Part : {&Const, &Writable}) {
    for (GlobalVariable *G : *Part) {
      Size = alignTo(Size, DL.getPreferredAlign(G).value());
      Offset[G] = Size;
      Size += DL.getTypeAllocSize(G->getValueType());
    }
    if (Part == &Const)
      ConstSize = Size;
  }
  Image Img{DL, Offset, {}, {}};
  Img.Bytes.assign(alignTo(Size, 8), 0);
  for (auto *Part : {&Const, &Writable})
    for (GlobalVariable *G : *Part)
      Img.write(G->getInitializer(), Offset[G]);

  // 2. Every use in code becomes the pair (W_d, offset), made at its
  //    function's entry, which dominates every use.
  SmallVector<Constant *, 16> All(Const.begin(), Const.end());
  All.append(Writable.begin(), Writable.end());
  if (auto *U = M.getGlobalVariable("llvm.compiler.used"))
    U->eraseFromParent();
  if (auto *U = M.getGlobalVariable("llvm.used"))
    U->eraseFromParent();
  convertUsersOfConstantsToInstructions(All);
  LLVMContext &Ctx = M.getContext();
  Type *I32 = Type::getInt32Ty(Ctx), *I64 = Type::getInt64Ty(Ctx);
  DenseMap<Function *, Instruction *> Window;
  for (Constant *C : All) {
    auto *G = cast<GlobalVariable>(C);
    for (Use &U : make_early_inc_range(G->uses())) {
      auto *I = dyn_cast<Instruction>(U.getUser());
      if (!I)
        continue;                      // another global's initializer: laid out
      Function *F = I->getFunction();
      Instruction *&W = Window[F];
      if (!W) {
        IRBuilder<> EB(&*F->getEntryBlock().getFirstInsertionPt());
        auto *Slot = ConstantExpr::getIntToPtr(
            ConstantInt::get(I64, ccvLaunchBase() + (TestDataWord24 ? 24 : OffDataWindow)),
            PointerType::get(Ctx, AS_CONST));
        auto *L = EB.CreateAlignedLoad(I32, Slot, Align(4), "data.window");
        L->setMetadata(LLVMContext::MD_invariant_load, MDNode::get(Ctx, {}));
        W = L;
      }
      IRBuilder<> B(W->getNextNode());    // after the window, before any use
      Value *A = B.CreateAdd(B.CreateShl(B.CreateZExt(W, I64), 16),
                             ConstantInt::get(I64, Offset[G]), "", true, true);
      U.set(B.CreateIntToPtr(A, G->getType(), G->getName() + ".addr"));
    }
  }
  for (Constant *C : All)
    cast<GlobalVariable>(C)->dropAllReferences();
  for (Constant *C : All) {
    auto *G = cast<GlobalVariable>(C);
    G->replaceAllUsesWith(PoisonValue::get(G->getType()));
    G->eraseFromParent();
  }

  // 3. The image and its relocations, in sections of their own.
  auto Emit = [&](StringRef Name, StringRef Section, Constant *Init) {
    auto *G = new GlobalVariable(M, Init->getType(), true,
                                 GlobalValue::ExternalLinkage, Init, Name);
    G->setSection(Section);
    G->setAlignment(Align(8));
  };
  Emit("__ccv_data", ".ccv_data",
       ConstantDataArray::get(Ctx, ArrayRef<uint8_t>(Img.Bytes)));
  Emit("__ccv_info", ".ccv_info",
       ConstantDataArray::get(Ctx, ArrayRef<uint32_t>{uint32_t(ConstSize)}));
  if (!Img.Relocs.empty() && !TestNoDataReloc)
    Emit("__ccv_reloc", ".ccv_reloc",
         ConstantDataArray::get(Ctx, ArrayRef<uint32_t>(Img.Relocs)));
}
