//===-- CCVTargetMachine.h --------------------------------------*- C++ -*-===//
#ifndef CCV_CCVTARGETMACHINE_H
#define CCV_CCVTARGETMACHINE_H

#include "CCVSubtarget.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/Target/TargetMachine.h"
#include <algorithm>
#include <memory>
#include <optional>

namespace llvm {
class CCVTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  CCVSubtarget ST;
  /// F-200: the subtargets for a kernel marked "ccv-narrow-int"="N", whose
  /// 16-bit integers stay narrow in N registers set once at its entry (O-81),
  /// one for each N from 2 to 6.
  std::unique_ptr<CCVSubtarget> NarrowST[5];

public:
  CCVTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const CCVSubtarget *getSubtargetImpl(const Function &F) const override {
    if (!F.hasFnAttribute("ccv-narrow-int"))
      return &ST;
    unsigned N = 2;
    F.getFnAttribute("ccv-narrow-int").getValueAsString().getAsInteger(10, N);
    return NarrowST[std::min(std::max(N, 2u), 6u) - 2].get();
  }
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  /// The module is closed (no -rdc), so a direct call can use its callee's
  /// real clobbers, and IPRA's bottom-up codegen order is what the static
  /// frame layout relies on (F-21).
  bool useIPRA() const override { return true; }
  TargetTransformInfo getTargetTransformInfo(const Function &F) const override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
};
} // namespace llvm
#endif
