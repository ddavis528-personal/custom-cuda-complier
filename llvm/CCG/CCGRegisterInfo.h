//===-- CCGRegisterInfo.h ---------------------------------------*- C++ -*-===//
#ifndef CCG_CCGREGISTERINFO_H
#define CCG_CCGREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "CCGGenRegisterInfo.inc"

namespace llvm {
struct CCGRegisterInfo : public CCGGenRegisterInfo {
  CCGRegisterInfo();
  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;
  BitVector getReservedRegs(const MachineFunction &MF) const override;
  bool eliminateFrameIndex(MachineBasicBlock::iterator MI, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;
  Register getFrameRegister(const MachineFunction &MF) const override;
};
} // namespace llvm
#endif
