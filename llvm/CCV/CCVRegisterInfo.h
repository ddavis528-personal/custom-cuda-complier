//===-- CCVRegisterInfo.h ---------------------------------------*- C++ -*-===//
#ifndef CCV_CCVREGISTERINFO_H
#define CCV_CCVREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "CCVGenRegisterInfo.inc"

namespace llvm {
struct CCVRegisterInfo : public CCVGenRegisterInfo {
  CCVRegisterInfo();
  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;
  BitVector getReservedRegs(const MachineFunction &MF) const override;
  bool eliminateFrameIndex(MachineBasicBlock::iterator MI, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;
  Register getFrameRegister(const MachineFunction &MF) const override;
};
} // namespace llvm
#endif
