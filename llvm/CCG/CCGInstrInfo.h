//===-- CCGInstrInfo.h ------------------------------------------*- C++ -*-===//
#ifndef CCG_CCGINSTRINFO_H
#define CCG_CCGINSTRINFO_H

#include "CCGRegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "CCGGenInstrInfo.inc"

namespace llvm {
class CCGInstrInfo : public CCGGenInstrInfo {
  const CCGRegisterInfo RI;

public:
  CCGInstrInfo() = default;
  const CCGRegisterInfo &getRegisterInfo() const { return RI; }

  void copyPhysReg(MachineBasicBlock &MBB, MachineBasicBlock::iterator MI,
                   const DebugLoc &DL, MCRegister DestReg, MCRegister SrcReg,
                   bool KillSrc) const override;
};
} // namespace llvm
#endif
