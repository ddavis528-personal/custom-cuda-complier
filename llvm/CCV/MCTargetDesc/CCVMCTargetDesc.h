//===-- CCVMCTargetDesc.h ---------------------------------------*- C++ -*-===//
#ifndef CCV_MCTARGETDESC_CCVMCTARGETDESC_H
#define CCV_MCTARGETDESC_CCVMCTARGETDESC_H

#include "llvm/MC/MCInstrDesc.h"
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

namespace CCVOp {
/// Immediate operands that name predicate registers. They are read (a guard)
/// or moved (a predicate transfer) like registers but encoded as fields, so
/// nothing generic can see them; the operand type is how a consumer does.
enum OperandType : unsigned {
  OPERAND_PQUAL = MCOI::OPERAND_FIRST_TARGET, // 2-bit address + negate
  OPERAND_PSRC,                               // same shape, a logic source
  OPERAND_PMASK4,                             // bit k selects P<k>
};
} // namespace CCVOp
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
