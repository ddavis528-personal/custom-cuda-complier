//===-- CCGMCTargetDesc.h ---------------------------------------*- C++ -*-===//
#ifndef CCG_MCTARGETDESC_CCGMCTARGETDESC_H
#define CCG_MCTARGETDESC_CCGMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"
#include <memory>

namespace llvm {
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createCCGMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createCCGAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
} // namespace llvm

// Generated declarations.
#define GET_REGINFO_ENUM
#include "CCGGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "CCGGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "CCGGenSubtargetInfo.inc"

#endif
