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

  // Without these the generic branch folder cannot act, and every
  // fall-through edge is emitted as an explicit branch to the next
  // instruction. See roadmap F-26.
  bool analyzeBranch(MachineBasicBlock &MBB, MachineBasicBlock *&TBB,
                     MachineBasicBlock *&FBB,
                     SmallVectorImpl<MachineOperand> &Cond,
                     bool AllowModify) const override;
  unsigned removeBranch(MachineBasicBlock &MBB,
                        int *BytesRemoved = nullptr) const override;
  unsigned insertBranch(MachineBasicBlock &MBB, MachineBasicBlock *TBB,
                        MachineBasicBlock *FBB, ArrayRef<MachineOperand> Cond,
                        const DebugLoc &DL,
                        int *BytesAdded = nullptr) const override;
  bool reverseBranchCondition(
      SmallVectorImpl<MachineOperand> &Cond) const override;
};
} // namespace llvm
#endif
