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

void CCVFrameLowering::emitPrologue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {
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
        auto It = Callee ? FrameExtent.find(Callee) : FrameExtent.end();
        if (It == FrameExtent.end())
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
      auto It = T ? FrameExtent.find(T) : FrameExtent.end();
      if (It == FrameExtent.end())
        report_fatal_error("CCV: " + F.getName() + " may call " + N +
                           " indirectly before that function's frame is laid "
                           "out -- a recursion through a function pointer, "
                           "which a static frame layout cannot place (F-21)");
      if (!TestIgnoreIndirectFrames)
        Base = std::max(Base, It->second);
    }
  }
  const unsigned Size = unsigned(MF.getFrameInfo().getStackSize());
  FrameBase[&F] = Base;
  FrameExtent[&F] = Base + Size;
  if (FrameStats && ccvIsKernel(F))
    errs() << "  frame " << F.getName() << ": " << Base + Size
           << " bytes a thread (own " << Size << ")\n";
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

  // Only a kernel sets R15: a device function inherits its caller's, which is
  // the same window. A kernel sets it when anything below it has a frame.
  if (!ccvIsKernel(F) || Base + Size == 0)
    return;

  const auto *TII = MF.getSubtarget<CCVSubtarget>().getInstrInfo();
  MachineBasicBlock::iterator I = MBB.begin();
  DebugLoc DL;

  // R15 = launch-block window, then the context's .local window base, then this
  // thread's own window. Nothing is live at function entry -- a kernel takes
  // no register arguments (§5.2) -- so R14 is free to use as a scratch here
  // regardless of what the allocator does with it later.
  BuildMI(MBB, I, DL, TII->get(CCV::MOVI), CCV::R15)
      .addImm(LaunchBase >> kBaseShift);
  BuildMI(MBB, I, DL, TII->get(CCV::LD_GLOBAL), CCV::R15)
      .addReg(CCV::R15)
      .addImm(kOffLocalBase);
  // O-64: the window is indexed by %lanectx (srd #2), unique among the
  // device's live lanes, not by %ctatid, which every CTA repeats.
  BuildMI(MBB, I, DL, TII->get(CCV::SRD), CCV::R14).addImm(2);  // %lanectx
  BuildMI(MBB, I, DL, TII->get(CCV::ADD), CCV::R15)
      .addReg(CCV::R15)
      .addReg(CCV::R14)
      .addReg(CCV::R15);
}
