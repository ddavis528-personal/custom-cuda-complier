//===-- CCVFrameLowering.h --------------------------------------*- C++ -*-===//
//
// The frame is thread-private, reached through one window index in R15, so an
// access is a single base+offset instruction with no index register, and the
// frame costs one reserved GPR. IS-25 (DA tab rev 97), the default: R15 is W,
// the base of the thread's O-83 region (local_base + %privoff, srd #3), and the
// frame takes the region's bottom bytes, which MIU interleaves by lane, so the
// same R15 names each thread's own frame. Before it, O-30/O-64: each lane had
// a whole 64 KiB window of its own, `local_base + %lanectx` (srd #2), and the
// frame sat at the top of the window below R15's (-ccv-frame-in-priv=false).
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
/// Whether O-30's frame is at the bottom of the thread's O-83 region (IS-25,
/// -ccv-frame-in-priv) rather than in O-64's window below R15's.
bool ccvFrameInPriv();
/// The displacement from R15's window of byte ObjOff (a frame object's offset,
/// negative, in F's own frame), with F's base taken as 0 when AtZero (the
/// stack-argument control). Only once F is laid out.
int64_t ccvFrameDisp(const Function &F, int64_t ObjOff, bool AtZero = false);
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
