//===-- CCGLowerKernelArgs.cpp - kernel ABI lowering ---------------------===//
//
// Rewrites kernel parameters into loads from the CTA-private launch block
// (§5.2), and materialises the address model (§5.1) as explicit IR arithmetic.
//
// Modelled on AMDGPULowerKernelArguments, which solves the same problem for the
// same reason: kernel arguments do not arrive in registers, they arrive in a
// block of read-only memory the launch mechanism populated.
//
// Two things are expressed in IR rather than left to the backend:
//
//   - The (rbase << 16) + roffset address model becomes real arithmetic. The
//     backend's addressing mode then folds the shape back up, and -- more
//     usefully -- an *aligned* pointer has roffset == 0, which constant-folds
//     away on its own, leaving the one-register form of §5.6 without the
//     backend needing a special case. O-23 falls out of the optimiser.
//
//   - Launch-block loads are marked invariant, so they can be hoisted,
//     CSE'd and rematerialised rather than spilled. At 16 GPRs (O-25) that
//     matters.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

// §5.2: the block sits at a fixed architectural address, CTA-private by
// windowing, and the prologue materialises the constant. Entry register state
// stays undefined, so the ISA takes on no ABI.
static cl::opt<uint64_t> LaunchBase("ccg-launch-base", cl::init(0x20000),
                                    cl::desc("CCG launch block address"));
// §5.1, settled at 16.
static constexpr unsigned kBaseShift = 16;
// O-23: an argument at least this aligned has a zero in-window offset.
static constexpr uint64_t kWindowAlign = 1ull << kBaseShift;

namespace {

/// Layout of the launch block header, ahead of the argument area. Offsets are
/// an ABI choice, not an encoding one; they live here until the ABI document
/// exists.
enum : unsigned {
  OffNtidX   = 0,
  OffNtidY   = 4,
  OffNtidZ   = 8,
  OffNctaidX = 12,
  OffArgs    = 32,
};

struct LowerKernelArgs : PassInfoMixin<LowerKernelArgs> {
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &);
};

/// Kernels are marked by !nvvm.annotations {ptr, "kernel", i32 1}. Reading
/// clang's own marker means the frontend stays unmodified (F-7).
static bool isKernel(const Function &F) {
  const Module *M = F.getParent();
  const NamedMDNode *Annos = M->getNamedMetadata("nvvm.annotations");
  if (!Annos)
    return false;
  for (const MDNode *N : Annos->operands()) {
    if (N->getNumOperands() < 3)
      continue;
    auto *V = dyn_cast_or_null<ValueAsMetadata>(N->getOperand(0));
    if (!V || V->getValue() != &F)
      continue;
    auto *S = dyn_cast<MDString>(N->getOperand(1));
    if (S && S->getString() == "kernel")
      return true;
  }
  return false;
}

} // namespace

PreservedAnalyses LowerKernelArgs::run(Module &M, ModuleAnalysisManager &) {
  bool Changed = false;
  LLVMContext &Ctx = M.getContext();
  Type *I32 = Type::getInt32Ty(Ctx);
  Type *I64 = Type::getInt64Ty(Ctx);

  for (Function &F : M) {
    if (F.isDeclaration() || !isKernel(F) || F.arg_empty())
      continue;

    IRBuilder<> B(&*F.getEntryBlock().getFirstInsertionPt());

    // The launch block is .const: read-only for the kernel's lifetime, so
    // every load from it is invariant (§5.2).
    MDNode *Invariant = MDNode::get(Ctx, {});
    Value *Base = B.CreateIntToPtr(
        ConstantInt::get(I64, LaunchBase),
        PointerType::get(Ctx, /*AddressSpace=*/4), "launch.base");

    auto loadSlot = [&](unsigned Off, const Twine &Name) -> Value * {
      Value *P = B.CreateConstInBoundsGEP1_64(Type::getInt8Ty(Ctx), Base, Off);
      auto *L = B.CreateAlignedLoad(I32, P, Align(4), Name);
      L->setMetadata(LLVMContext::MD_invariant_load, Invariant);
      return L;
    };

    unsigned Off = OffArgs;
    for (Argument &A : F.args()) {
      if (A.getType()->isPointerTy()) {
        // O-23: alignment is a property of the argument. Query it rather than
        // special-casing an attribute -- getParamAlign covers align_value and
        // anything else that establishes it.
        MaybeAlign PA = A.getParamAlign();
        bool Aligned = PA && PA->value() >= kWindowAlign;

        Value *RBase = loadSlot(Off, A.getName() + ".rbase");
        Value *Addr = B.CreateShl(B.CreateZExt(RBase, I64),
                                  ConstantInt::get(I64, kBaseShift),
                                  A.getName() + ".window");
        if (!Aligned) {
          // Unaligned: the in-window offset is a second slot, and the shape
          // costs a register and a fold (§5.5). Aligned, this whole branch
          // disappears and the constant-folder removes the add.
          Value *ROff = loadSlot(Off + 4, A.getName() + ".roffset");
          Addr = B.CreateAdd(Addr, B.CreateZExt(ROff, I64));
        }
        Off += 8; // Layout is uniform whether or not the argument is aligned,
                  // so the runtime never needs to know which kernels declared
                  // what (O-23).

        Value *P = B.CreateIntToPtr(Addr, A.getType(), A.getName() + ".ptr");
        A.replaceAllUsesWith(P);
      } else {
        Value *V = loadSlot(Off, A.getName() + ".val");
        if (A.getType() != I32)
          V = B.CreateBitOrPointerCast(V, A.getType());
        Off += 4;
        A.replaceAllUsesWith(V);
      }
      Changed = true;
    }
  }
  return Changed ? PreservedAnalyses::none() : PreservedAnalyses::all();
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "CCGLowerKernelArgs", "0.1",
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, ModulePassManager &MPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "ccg-lower-kernel-args") {
                    MPM.addPass(LowerKernelArgs());
                    return true;
                  }
                  return false;
                });
          }};
}
