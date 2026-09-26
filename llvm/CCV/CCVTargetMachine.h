//===-- CCVTargetMachine.h --------------------------------------*- C++ -*-===//
#ifndef CCV_CCVTARGETMACHINE_H
#define CCV_CCVTARGETMACHINE_H

#include "CCVSubtarget.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/Target/TargetMachine.h"
#include <optional>

namespace llvm {
class CCVTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  CCVSubtarget ST;

public:
  CCVTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const CCVSubtarget *getSubtargetImpl(const Function &) const override {
    return &ST;
  }
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetTransformInfo getTargetTransformInfo(const Function &F) const override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
};
} // namespace llvm
#endif
