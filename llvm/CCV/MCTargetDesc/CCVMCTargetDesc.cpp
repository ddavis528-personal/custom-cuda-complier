//===-- CCVMCTargetDesc.cpp - CCV MC layer registration -------------------===//
//
// Registers the pieces the MC layer needs to encode, decode and print CCV
// instructions. Deliberately minimal: no object-file writing, no streamer.
// The round-trip tool drives the encoder and disassembler directly.
//
//===----------------------------------------------------------------------===//

#include "CCVMCTargetDesc.h"
#include "CCVInstPrinter.h"
#include "TargetInfo/CCVTargetInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "CCVGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "CCVGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "CCVGenSubtargetInfo.inc"

namespace {
class CCVMCAsmInfo : public MCAsmInfo {
public:
  CCVMCAsmInfo() {
    CommentString = ";";
    SupportsDebugInformation = false;
  }
};
} // namespace

static MCAsmInfo *createCCVMCAsmInfo(const MCRegisterInfo &, const Triple &,
                                     const MCTargetOptions &) {
  return new CCVMCAsmInfo();
}

static MCInstrInfo *createCCVMCInstrInfo() {
  auto *X = new MCInstrInfo();
  InitCCVMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createCCVMCRegisterInfo(const Triple &) {
  auto *X = new MCRegisterInfo();
  // No return-address register convention yet: the link register is explicit
  // in call/ret (§3, Format E), chosen by the compiler rather than fixed.
  InitCCVMCRegisterInfo(X, 0);
  return X;
}

static MCSubtargetInfo *createCCVMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  return createCCVMCSubtargetInfoImpl(TT, CPU.empty() ? "generic" : CPU,
                                      /*TuneCPU=*/CPU, FS);
}

static MCInstPrinter *createCCVMCInstPrinter(const Triple &, unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  return new CCVInstPrinter(MAI, MII, MRI);
}

extern "C" void LLVMInitializeCCVTargetMC() {
  Target &T = getTheCCVTarget();
  TargetRegistry::RegisterMCAsmInfo(T, createCCVMCAsmInfo);
  TargetRegistry::RegisterMCInstrInfo(T, createCCVMCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(T, createCCVMCRegisterInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createCCVMCSubtargetInfo);
  TargetRegistry::RegisterMCInstPrinter(T, createCCVMCInstPrinter);
  TargetRegistry::RegisterMCAsmBackend(T, createCCVAsmBackend);
  TargetRegistry::RegisterMCCodeEmitter(T, [](const MCInstrInfo &MCII,
                                              MCContext &Ctx) {
    return createCCVMCCodeEmitter(MCII, Ctx);
  });
}
