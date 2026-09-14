//===-- CCVInstrInfo.h ------------------------------------------*- C++ -*-===//
#ifndef CCV_CCVINSTRINFO_H
#define CCV_CCVINSTRINFO_H

#include "CCVRegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "CCVGenInstrInfo.inc"

namespace llvm {


class CCVInstrInfo : public CCVGenInstrInfo {
  const CCVRegisterInfo RI;

public:
  CCVInstrInfo() = default;
  const CCVRegisterInfo &getRegisterInfo() const { return RI; }

  /// Spilling needs somewhere to spill TO, and there is none: §5.1 mentions
  /// `.local` reaching memory through its own window, but no window is
  /// allocated, no frame index is lowered, and the launch block carries no
  /// per-thread stack base. The default implementations of these do not
  /// diagnose -- the allocator's spiller calls into them and corrupts the heap,
  /// which is how this surfaced. See F-46.
  void storeRegToStackSlot(MachineBasicBlock &MBB,
                           MachineBasicBlock::iterator MI, Register SrcReg,
                           bool isKill, int FrameIndex,
                           const TargetRegisterClass *RC,
                           const TargetRegisterInfo *TRI,
                           Register VReg) const override;
  void loadRegFromStackSlot(MachineBasicBlock &MBB,
                            MachineBasicBlock::iterator MI, Register DestReg,
                            int FrameIndex, const TargetRegisterClass *RC,
                            const TargetRegisterInfo *TRI,
                            Register VReg) const override;

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
