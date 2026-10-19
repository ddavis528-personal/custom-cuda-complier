//===-- CCVInternalize.cpp - device functions are local to the image ------===//
//
// Device code is one closed module (no -rdc): every device function and every
// call to it is in the image, and nothing outside can call in except through a
// kernel. So a device function is given internal linkage before codegen
// (F-21).
//
// This is not tidiness. A PC-relative reference to a GLOBAL ELF symbol is left
// as a relocation, because a global symbol could be preempted, and the image
// is the bare .text with relocations discarded. A call to an external-linkage
// device function therefore encoded a zero offset and fell through to the next
// instruction. It compiled, assembled and ran, and every lane computed the
// wrong answer; tools/check-calls.sh is what found it.
//
// Kernels keep their linkage: they are the image's entry points.
//
//===----------------------------------------------------------------------===//
#include "CCVFrameLowering.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
class CCVInternalize : public ModulePass {
public:
  static char ID;
  CCVInternalize() : ModulePass(ID) {}
  bool runOnModule(Module &M) override {
    bool Changed = false;
    for (Function &F : M) {
      if (F.isDeclaration() || F.hasLocalLinkage() || ccvIsKernel(F))
        continue;
      F.setLinkage(GlobalValue::InternalLinkage);
      F.setDSOLocal(true);
      Changed = true;
    }
    return Changed;
  }
  StringRef getPassName() const override {
    return "CCV device functions are local to the image";
  }
};
} // namespace

char CCVInternalize::ID = 0;

namespace llvm {
ModulePass *createCCVInternalize() { return new CCVInternalize(); }
} // namespace llvm
