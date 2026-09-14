//===-- CCVMCTargetDesc.h ---------------------------------------*- C++ -*-===//
#ifndef CCV_MCTARGETDESC_CCVMCTARGETDESC_H
#define CCV_MCTARGETDESC_CCVMCTARGETDESC_H

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

MCCodeEmitter *createCCVMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createCCVAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
} // namespace llvm

// Generated declarations.
#define GET_REGINFO_ENUM
#include "CCVGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "CCVGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "CCVGenSubtargetInfo.inc"

#endif
