//===-- CCVLowerShared.cpp - assign addresses to .shared globals ---------===//
//
// A `__shared__` array arrives as a global in addrspace(3). §5.1 makes that
// space flat 32-bit -- no window, no launch-block indirection -- so a shared
// object's address is simply its offset inside the CTA's shared allocation,
// and that offset is known at compile time.
//
// So there is nothing to relocate. This pass lays the objects out and replaces
// each one with an `inttoptr` of its offset, which leaves the backend selecting
// ordinary base+index arithmetic against a constant it can materialise with one
// `movi`. No relocation kind, no .shared section, no linker step.
//
// The total is recorded as a function attribute so the launch mechanism knows
// how much shared memory the kernel needs. That is an ABI fact, not an encoding
// one, and it belongs in the launch block's companion document; the attribute
// is where it lives until that exists.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-lower-shared"

namespace {

constexpr unsigned AS_SHARED = 3;

bool runOnMod(Module &M) {
  const DataLayout &DL = M.getDataLayout();

  SmallVector<GlobalVariable *, 4> Shared;
  for (GlobalVariable &GV : M.globals())
    if (GV.getAddressSpace() == AS_SHARED)
      Shared.push_back(&GV);
  if (Shared.empty())
    return false;

  // Module order, each object at its own natural alignment. Deterministic and
  // stable, which matters because the offsets end up baked into the code.
  uint64_t Offset = 0;
  for (GlobalVariable *GV : Shared) {
    Align A = GV->getAlign().value_or(DL.getPrefTypeAlign(GV->getValueType()));
    Offset = alignTo(Offset, A);

    Type *PtrTy = GV->getType();
    Constant *Addr = ConstantExpr::getIntToPtr(
        ConstantInt::get(Type::getInt32Ty(M.getContext()), Offset), PtrTy);
    GV->replaceAllUsesWith(Addr);

    Offset += DL.getTypeAllocSize(GV->getValueType());
  }

  for (GlobalVariable *GV : Shared)
    GV->eraseFromParent();

  // Every kernel in the module shares one static allocation, which is what a
  // module-scope layout means. Per-kernel accounting needs a call graph and
  // belongs with dynamic shared memory, which is not specified yet.
  for (Function &F : M)
    if (!F.isDeclaration())
      F.addFnAttr("ccv-shared-bytes", std::to_string(Offset));
  return true;
}

class CCVLowerShared : public ModulePass {
public:
  static char ID;
  CCVLowerShared() : ModulePass(ID) {}
  bool runOnModule(Module &M) override { return runOnMod(M); }
  StringRef getPassName() const override { return "CCV .shared layout"; }
};

} // namespace

char CCVLowerShared::ID = 0;

namespace llvm {
ModulePass *createCCVLowerShared() { return new CCVLowerShared(); }
} // namespace llvm
