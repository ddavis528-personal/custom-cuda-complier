//===-- CCVRegisterInfo.h ---------------------------------------*- C++ -*-===//
#ifndef CCV_CCVREGISTERINFO_H
#define CCV_CCVREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "CCVGenRegisterInfo.inc"

namespace llvm {
unsigned ccvNarrowGPROrder(unsigned N);   // F-200's GPR order, or its control's
struct CCVRegisterInfo : public CCVGenRegisterInfo {
  CCVRegisterInfo();
  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;
  const uint32_t *getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID) const override;
  BitVector getReservedRegs(const MachineFunction &MF) const override;
  bool eliminateFrameIndex(MachineBasicBlock::iterator MI, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;
  Register getFrameRegister(const MachineFunction &MF) const override;
  /// F-200: in a narrow kernel a copy between a 16-bit and a 32-bit class is a
  /// move between the partitions, never coalesced away.
  bool shouldCoalesce(MachineInstr *MI, const TargetRegisterClass *SrcRC,
                      unsigned SubReg, const TargetRegisterClass *DstRC,
                      unsigned DstSubReg, const TargetRegisterClass *NewRC,
                      LiveIntervals &LIS) const override;
};
} // namespace llvm
#endif
