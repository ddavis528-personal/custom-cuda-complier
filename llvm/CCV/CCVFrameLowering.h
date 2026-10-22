//===-- CCVFrameLowering.h --------------------------------------*- C++ -*-===//
//
// The frame is a thread-private `.local` region, reached through its own window
// (§5.1). O-30: with S=16 a window is 64 KiB, so giving each thread a whole one
// makes the frame POINTER a window index rather than an address -- thread t
// uses window `local_base + t`. A spill is then a single base+offset
// instruction with no index register, and the frame costs one reserved GPR
// instead of two.
//
//===----------------------------------------------------------------------===//
#ifndef CCV_CCVFRAMELOWERING_H
#define CCV_CCVFRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class CCVFrameLowering : public TargetFrameLowering {
public:
  CCVFrameLowering()
      : TargetFrameLowering(StackGrowsDown, Align(4), /*LocalAreaOffset=*/0) {}
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &, MachineBasicBlock &) const override {}
  /// The call frame is static (F-21), so the call-sequence markers adjust
  /// nothing.
  MachineBasicBlock::iterator
  eliminateCallFramePseudoInstr(MachineFunction &, MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator I) const override {
    return MBB.erase(I);
  }
  /// A kernel has no caller to restore anything for, and nothing is dynamic --
  /// so the frame pointer is the only frame register and it never needs an
  /// epilogue.
  bool hasFP(const MachineFunction &MF) const override { return true; }
};
/// Where F's frame starts below R15, in bytes: the deepest extent any of its
/// callees' frames reach. Laid out by emitPrologue, callees first.
unsigned ccvFrameBase(const Function &F);
/// The launch block's address, which the kernel prologue and module data
/// (word 28, O-61) read. One copy, checked against the others by
/// tools/check-launch-abi.sh.
uint64_t ccvLaunchBase();
/// Whether F's frame has been laid out yet. A caller's stack arguments are
/// written at its callee's base, so the callee must come first.
bool ccvFrameLaidOut(const Function &F);
/// Whether F is a kernel (!nvvm.annotations "kernel") rather than a device
/// function. Only a kernel sets up R15 and ends in `exit`.
bool ccvIsKernel(const Function &F);
} // namespace llvm
#endif
