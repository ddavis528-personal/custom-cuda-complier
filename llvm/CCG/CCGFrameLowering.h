//===-- CCGFrameLowering.h --------------------------------------*- C++ -*-===//
#ifndef CCG_CCGFRAMELOWERING_H
#define CCG_CCGFRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class CCGFrameLowering : public TargetFrameLowering {
public:
  CCGFrameLowering()
      : TargetFrameLowering(StackGrowsDown, Align(4), /*LocalAreaOffset=*/0) {}
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override {}
  bool hasFP(const MachineFunction &MF) const override { return false; }
};
} // namespace llvm
#endif
