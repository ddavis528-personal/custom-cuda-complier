//===-- CCGTargetMachine.h --------------------------------------*- C++ -*-===//
#ifndef CCG_CCGTARGETMACHINE_H
#define CCG_CCGTARGETMACHINE_H

#include "CCGSubtarget.h"
#include "llvm/Target/TargetMachine.h"
#include <optional>

namespace llvm {
class CCGTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  CCGSubtarget ST;

public:
  CCGTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const CCGSubtarget *getSubtargetImpl(const Function &) const override {
    return &ST;
  }
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
};
} // namespace llvm
#endif
