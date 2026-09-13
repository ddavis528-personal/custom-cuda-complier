//===-- CCGFrameLowering.h --------------------------------------*- C++ -*-===//
//
// The frame is a thread-private `.local` region, reached through its own window
// (§5.1). O-30: with S=16 a window is 64 KiB, so giving each thread a whole one
// makes the frame POINTER a window index rather than an address -- thread t
// uses window `local_base + t`. A spill is then a single base+offset
// instruction with no index register, and the frame costs one reserved GPR
// instead of two.
//
//===----------------------------------------------------------------------===//
#ifndef CCG_CCGFRAMELOWERING_H
#define CCG_CCGFRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class CCGFrameLowering : public TargetFrameLowering {
public:
  CCGFrameLowering()
      : TargetFrameLowering(StackGrowsDown, Align(4), /*LocalAreaOffset=*/0) {}
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &, MachineBasicBlock &) const override {}
  /// A kernel has no caller to restore anything for, and nothing is dynamic --
  /// so the frame pointer is the only frame register and it never needs an
  /// epilogue.
  bool hasFP(const MachineFunction &MF) const override { return true; }
};
} // namespace llvm
#endif
