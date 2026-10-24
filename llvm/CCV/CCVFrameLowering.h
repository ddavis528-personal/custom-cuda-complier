//===-- CCVFrameLowering.h --------------------------------------*- C++ -*-===//
//
// The frame is a thread-private `.local` region, reached through its own window
// (§5.1). O-30: with S=16 a window is 64 KiB, so giving each thread a whole one
// makes the frame POINTER a window index rather than an address -- a lane
// uses window `local_base + %lanectx` (O-64: srd #2, unique among the device's
// live lanes; O-30's `local_base + t` repeated across CTAs). A spill is then a single base+offset
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
  /// O-69: spill slots move to the interleaved spill space, laid out
  /// statically over the call graph, and leave the R15 frame.
  void processFunctionBeforeFrameFinalized(MachineFunction &MF,
                                           RegScavenger *RS) const override;
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
/// function. Only a kernel ends in `exit`.
bool ccvIsKernel(const Function &F);
/// Whether spills go to O-69's interleaved space (-ccv-local-spills).
bool ccvLocalSpills();
/// Whether MF needs O-30's R15 frame: an address-taken object, a stack
/// argument either way, or every spill when O-69's space is off. Decided
/// from facts present before register allocation, so getReservedRegs gives
/// the same answer whenever it is asked.
bool ccvNeedsR15(const MachineFunction &MF);
/// O-69: the byte offset in the warp's spill frame of MF's spill slot FI, or
/// -1 if FI is not one there.
int64_t ccvLocalSlot(const MachineFunction &MF, int FI);
} // namespace llvm
#endif
