//===-- CCGMCTargetDesc.cpp - CCG MC layer registration -------------------===//
//
// Registers the pieces the MC layer needs to encode, decode and print CCG
// instructions. Deliberately minimal: no object-file writing, no streamer.
// The round-trip tool drives the encoder and disassembler directly.
//
//===----------------------------------------------------------------------===//

#include "CCGMCTargetDesc.h"
#include "CCGInstPrinter.h"
#include "TargetInfo/CCGTargetInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "CCGGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "CCGGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "CCGGenSubtargetInfo.inc"

namespace {
class CCGMCAsmInfo : public MCAsmInfo {
public:
  CCGMCAsmInfo() {
    CommentString = ";";
    SupportsDebugInformation = false;
  }
};
} // namespace

static MCAsmInfo *createCCGMCAsmInfo(const MCRegisterInfo &, const Triple &,
                                     const MCTargetOptions &) {
  return new CCGMCAsmInfo();
}

static MCInstrInfo *createCCGMCInstrInfo() {
  auto *X = new MCInstrInfo();
  InitCCGMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createCCGMCRegisterInfo(const Triple &) {
  auto *X = new MCRegisterInfo();
  // No return-address register convention yet: the link register is explicit
  // in call/ret (§3, Format E), chosen by the compiler rather than fixed.
  InitCCGMCRegisterInfo(X, 0);
  return X;
}

static MCSubtargetInfo *createCCGMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  return createCCGMCSubtargetInfoImpl(TT, CPU.empty() ? "generic" : CPU,
                                      /*TuneCPU=*/CPU, FS);
}

static MCInstPrinter *createCCGMCInstPrinter(const Triple &, unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  return new CCGInstPrinter(MAI, MII, MRI);
}

extern "C" void LLVMInitializeCCGTargetMC() {
  Target &T = getTheCCGTarget();
  TargetRegistry::RegisterMCAsmInfo(T, createCCGMCAsmInfo);
  TargetRegistry::RegisterMCInstrInfo(T, createCCGMCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(T, createCCGMCRegisterInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createCCGMCSubtargetInfo);
  TargetRegistry::RegisterMCInstPrinter(T, createCCGMCInstPrinter);
  TargetRegistry::RegisterMCCodeEmitter(T, [](const MCInstrInfo &MCII,
                                              MCContext &Ctx) {
    return createCCGMCCodeEmitter(MCII, Ctx);
  });
}
