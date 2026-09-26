//===-- CCVTargetInfo.cpp - CCV target registration -----------------------===//
#include "CCVTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheCCVTarget() {
  static Target TheCCVTarget;
  return TheCCVTarget;
}

extern "C" void LLVMInitializeCCVTargetInfo() {
  RegisterTarget<Triple::UnknownArch, /*HasJIT=*/false> X(
      getTheCCVTarget(), "ccv", "Custom CUDA-compatible GPU", "CCV");
}
