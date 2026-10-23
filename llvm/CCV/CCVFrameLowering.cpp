//===-- CCVFrameLowering.cpp ----------------------------------------------===//
#include "CCVFrameLowering.h"
#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

// Must match CCVLowerKernelArgs. The block's byte layout is an ABI choice, not
// an encoding one, and lives in both places until the ABI document exists.
static cl::opt<uint64_t> LaunchBase("ccv-frame-launch-base", cl::init(0x20000),
                                    cl::desc("CCV launch block address"));
static constexpr unsigned kBaseShift = 16;
static constexpr unsigned kOffLocalBase = 24;

uint64_t llvm::ccvLaunchBase() { return LaunchBase; }

bool llvm::ccvIsKernel(const Function &F) {
  const NamedMDNode *Annos = F.getParent()->getNamedMetadata("nvvm.annotations");
  // Hand-written IR (test/accept) marks nothing. There, a function nothing in
  // the module uses is an entry point, which is what every such test is.
  if (!Annos)
    return F.use_empty();
  for (const MDNode *N : Annos->operands()) {
    if (N->getNumOperands() < 3)
      continue;
    auto *V = dyn_cast_or_null<ValueAsMetadata>(N->getOperand(0).get());
    auto *S = dyn_cast_or_null<MDString>(N->getOperand(1).get());
    if (V && V->getValue() == &F && S && S->getString() == "kernel")
      return true;
  }
  return false;
}

// The static frame layout (F-21; proposals/calling-convention.md §2). R15 is a
// window index, so there is no byte stack to push; instead every function's
// frame has a fixed place in the thread's window, below the frames of
// everything it calls. Sibling callees overlap, which is right: they are never
// live together. Functions are laid out callees first -- IPRA makes codegen
// walk the call graph bottom-up -- so a callee's extent is known when its
// caller's prologue is emitted, and a callee that is not is a cycle.
static DenseMap<const Function *, unsigned> FrameBase, FrameExtent;

// O-69: the same layout for spill slots, in the warp's interleaved spill space.
// Offsets there are absolute in the warp's frame -- no register says where a
// function's slots are -- so a function's slots sit above the largest extent
// of everything it calls, exactly as its R15 frame sits below theirs.
static DenseMap<const Function *, unsigned> LocalExtent;
static DenseMap<const MachineFunction *, DenseMap<int, unsigned>> LocalSlots;

static cl::opt<bool> LocalSpills(
    "ccv-local-spills", cl::init(true),
    cl::desc("spill to O-69's interleaved spill space (ld.local/st.local) and "
             "reserve R15 only where O-30's frame is needed; false spills to "
             "the R15 frame as before O-69"));

bool llvm::ccvLocalSpills() { return LocalSpills; }

// The answer is taken once, the first time it is asked -- when the reserved
// set is frozen, straight after selection -- and kept: after allocation R15 is
// an ordinary register in a function that does not reserve it, so asking
// again would see its uses and change the answer.
static DenseMap<const Function *, bool> NeedsR15;

static bool needsR15Now(const MachineFunction &MF);

bool llvm::ccvNeedsR15(const MachineFunction &MF) {
  if (!LocalSpills)
    return true;
  auto [It, New] = NeedsR15.try_emplace(&MF.getFunction(), false);
  if (New)
    It->second = needsR15Now(MF);
  return It->second;
}

static bool needsR15Now(const MachineFunction &MF) {
  const MachineFrameInfo &MFI = MF.getFrameInfo();
  // An address-taken object or an incoming stack argument: everything in the
  // frame before allocation, which adds only spill slots.
  for (int FI = MFI.getObjectIndexBegin(); FI != MFI.getObjectIndexEnd(); ++FI)
    if (!MFI.isDeadObjectIndex(FI) && !MFI.isSpillSlotObjectIndex(FI) &&
        LocalSlots.lookup(&MF).count(FI) == 0)
      return true;
  // An outgoing stack argument is written through R15 into the callee's frame
  // by the call lowering, before allocation.
  const MachineRegisterInfo &MRI = MF.getRegInfo();
  for (const MachineInstr &MI : MRI.reg_nodbg_instructions(CCV::R15))
    if (!MI.isCall() && !MI.isReturn())
      return true;
  return false;
}

int64_t llvm::ccvLocalSlot(const MachineFunction &MF, int FI) {
  auto It = LocalSlots.find(&MF);
  if (It == LocalSlots.end())
    return -1;
  auto J = It->second.find(FI);
  return J == It->second.end() ? -1 : int64_t(J->second);
}

/// The deepest extent, in Extent, of everything F calls -- directly, or
/// through a function pointer to an address-taken function of the call's type
/// (CCVCodePointers' ccv-icall-targets). A callee not yet laid out is a cycle.
static unsigned calleeExtent(const MachineFunction &MF,
                             const DenseMap<const Function *, unsigned> &Extent,
                             bool IgnoreIndirect) {
  const Function &F = MF.getFunction();
  unsigned Base = 0;
  for (const MachineBasicBlock &B : MF)
    for (const MachineInstr &MI : B) {
      if (!MI.isCall())
        continue;
      for (const MachineOperand &MO : MI.operands()) {
        if (!MO.isGlobal())
          continue;
        const auto *Callee = dyn_cast<Function>(MO.getGlobal());
        auto It = Callee ? Extent.find(Callee) : Extent.end();
        if (It == Extent.end())
          report_fatal_error(
              "CCV: " + F.getName() + " calls " + MO.getGlobal()->getName() +
              " before that function's frame is laid out -- a recursive call, "
              "which a static frame layout cannot place (F-21)");
        Base = std::max(Base, It->second);
      }
    }
  // An indirect call may reach any address-taken function of its type, which
  // CCVCodePointers recorded and placed first in the module (§2).
  if (F.hasFnAttribute("ccv-icall-targets")) {
    SmallVector<StringRef, 8> Names;
    F.getFnAttribute("ccv-icall-targets").getValueAsString().split(Names, ',');
    for (StringRef N : Names) {
      const Function *T = F.getParent()->getFunction(N);
      auto It = T ? Extent.find(T) : Extent.end();
      if (It == Extent.end())
        report_fatal_error("CCV: " + F.getName() + " may call " + N +
                           " indirectly before that function's frame is laid "
                           "out -- a recursion through a function pointer, "
                           "which a static frame layout cannot place (F-21)");
      if (!IgnoreIndirect)
        Base = std::max(Base, It->second);
    }
  }
  return Base;
}

// Mutation control for tools/check-calls.sh: every frame at base 0, as before
// the static layout, so a callee's frame lands on its caller's.
static cl::opt<bool> TestFlatFrames(
    "ccv-test-flat-frames", cl::init(false), cl::Hidden,
    cl::desc("lay every frame out at base 0, to test that it is caught"));

// Mutation control for tools/check-calls.sh: lay a caller out ignoring what
// its indirect calls may reach, so a target's frame lands on the caller's.
static cl::opt<bool> TestIgnoreIndirectFrames(
    "ccv-test-ignore-indirect-frames", cl::init(false), cl::Hidden,
    cl::desc("ignore indirect-call targets in the frame layout, to test that "
             "it is caught"));

// Mutation control for tools/check-calls.sh: every function's spill slots
// from the bottom of the spill frame, ignoring its callees, so a callee's
// slots land on its caller's.
static cl::opt<bool> TestFlatLocal(
    "ccv-test-flat-local", cl::init(false), cl::Hidden,
    cl::desc("lay every function's spill slots out from the bottom of the "
             "spill frame, to test that it is caught"));

// AR-23: each kernel's frame extent, its own frame and everything it calls.
static cl::opt<bool> FrameStats(
    "ccv-frame-stats", cl::init(false), cl::Hidden,
    cl::desc("report each kernel's per-thread frame extent (AR-23)"));

unsigned llvm::ccvFrameBase(const Function &F) {
  if (TestFlatFrames)
    return 0;
  auto It = FrameBase.find(&F);
  return It == FrameBase.end() ? 0 : It->second;
}

bool llvm::ccvFrameLaidOut(const Function &F) {
  return FrameExtent.count(&F);
}

void CCVFrameLowering::processFunctionBeforeFrameFinalized(
    MachineFunction &MF, RegScavenger *) const {
  if (!LocalSpills)
    return;
  MachineFrameInfo &MFI = MF.getFrameInfo();
  // Above every callee's slots; and at 12 at least, because the predicate
  // forms are positional -- Pi's word is at b + 4i, emitted as b - 4i for a
  // slot at b (CCVRegisterInfo), and the offset is unsigned.
  unsigned Cursor = std::max(
      TestFlatLocal ? 0u : calleeExtent(MF, LocalExtent, false), 12u);
  auto &Slots = LocalSlots[&MF];
  Slots.clear();
  for (int FI = MFI.getObjectIndexBegin(); FI != MFI.getObjectIndexEnd(); ++FI) {
    if (FI < 0 || MFI.isDeadObjectIndex(FI) || !MFI.isSpillSlotObjectIndex(FI))
      continue;
    // Whole 4-byte cells: an access stays inside its lane's cell (O-69), and a
    // narrower spill is still one cell.
    unsigned Size =
        unsigned(alignTo(std::max<int64_t>(MFI.getObjectSize(FI), 4), 4));
    Slots[FI] = Cursor;
    Cursor += Size;
    MFI.RemoveStackObject(FI);
  }
  if (Cursor >= (1u << 17))
    report_fatal_error("CCV: " + MF.getName() + " and what it calls spill " +
                       Twine(Cursor) + " bytes a thread, past the 17-bit "
                       "offset of O-69's ld.local/st.local (128 KiB)");
  LocalExtent[&MF.getFunction()] = Cursor;
}

void CCVFrameLowering::emitPrologue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {
  const Function &F = MF.getFunction();
  unsigned Base = calleeExtent(MF, FrameExtent, TestIgnoreIndirectFrames);
  const unsigned Size = unsigned(MF.getFrameInfo().getStackSize());
  FrameBase[&F] = Base;
  FrameExtent[&F] = Base + Size;
  if (FrameStats && ccvIsKernel(F))
    errs() << "  frame " << F.getName() << ": " << Base + Size
           << " bytes a thread (own " << Size << ")\n";
  if (FrameStats && LocalSpills) {
    if (ccvIsKernel(F))
      errs() << "  spill-space " << F.getName() << ": "
             << LocalExtent.lookup(&F) << " bytes a thread\n";
    for (auto [FI, B] : LocalSlots.lookup(&MF))
      errs() << "  local-slot " << F.getName() << " " << B << " " << B + 4
             << "\n";
  }
  // IS-19: each frame object's displacement range from R15, by kind -- a
  // spill slot (the allocator's, and callee-saved saves), a fixed object (a
  // stack argument), or any other object (a local array, an address-taken
  // scalar), which a lane-interleaved register-free form could not hold.
  if (FrameStats) {
    const MachineFrameInfo &MFI = MF.getFrameInfo();
    for (int FI = MFI.getObjectIndexBegin(); FI != MFI.getObjectIndexEnd(); ++FI) {
      // An empty object is printed too: a zero-size spill slot is a bug, and
      // skipping it hid one (F-179).
      if (MFI.isDeadObjectIndex(FI))
        continue;
      int64_t D = MFI.getObjectOffset(FI) - int64_t(Base);
      const char *Kind = MFI.isFixedObjectIndex(FI) ? "fixed"
                         : MFI.isSpillSlotObjectIndex(FI) ? "spill" : "object";
      errs() << "  frame-object " << F.getName() << " " << Kind << " " << D
             << " " << D + int64_t(MFI.getObjectSize(FI)) << "\n";
    }
  }

  const auto *TII = MF.getSubtarget<CCVSubtarget>().getInstrInfo();
  // R15 = launch-block window, then the context's .local window base, then this
  // thread's own window. The scratch is R14 in a kernel, where nothing is live
  // at entry (§5.2), and R0 in a device function, where R14 holds the return
  // address; R0 is neither an argument nor callee-saved, so it is free at
  // entry and straight after a call.
  const Register Scratch = ccvIsKernel(F) ? CCV::R14 : CCV::R0;
  auto formR15 = [&](MachineBasicBlock &B, MachineBasicBlock::iterator I) {
    DebugLoc DL;
    BuildMI(B, I, DL, TII->get(CCV::MOVI), CCV::R15)
        .addImm(LaunchBase >> kBaseShift);
    BuildMI(B, I, DL, TII->get(CCV::LD_GLOBAL), CCV::R15)
        .addReg(CCV::R15)
        .addImm(kOffLocalBase);
    // O-64: the window is indexed by %lanectx (srd #2), unique among the
    // device's live lanes, not by %ctatid, which every CTA repeats.
    BuildMI(B, I, DL, TII->get(CCV::SRD), Scratch).addImm(2);  // %lanectx
    BuildMI(B, I, DL, TII->get(CCV::ADD), CCV::R15)
        .addReg(CCV::R15)
        .addReg(Scratch)
        .addReg(CCV::R15);
  };

  if (!LocalSpills) {
    // Before O-69: only a kernel sets R15, and a device function inherits its
    // caller's, which is the same window. A kernel sets it when anything
    // below it has a frame.
    if (ccvIsKernel(F) && Base + Size != 0)
      formR15(MBB, MBB.begin());
    return;
  }
  // O-69: a function that needs O-30's frame forms R15 itself, at entry and
  // after every call, since R15 is not preserved across calls -- every other
  // function allocates it as an ordinary register.
  if (!ccvNeedsR15(MF))
    return;
  formR15(MBB, MBB.begin());
  for (MachineBasicBlock &B : MF)
    for (MachineInstr &MI : llvm::make_early_inc_range(B))
      if (MI.isCall())
        formR15(B, std::next(MI.getIterator()));
}
