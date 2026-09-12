//===-- CCGTargetInfo.cpp - CCG target registration -----------------------===//
#include "CCGTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheCCGTarget() {
  static Target TheCCGTarget;
  return TheCCGTarget;
}

extern "C" void LLVMInitializeCCGTargetInfo() {
  RegisterTarget<Triple::UnknownArch, /*HasJIT=*/false> X(
      getTheCCGTarget(), "ccg", "Custom CUDA-compatible GPU", "CCG");
}
