//===-- CCVFrameLowering.cpp ----------------------------------------------===//
#include "CCVFrameLowering.h"
#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

// Must match CCVLowerKernelArgs. The block's byte layout is an ABI choice, not
// an encoding one, and lives in both places until the ABI document exists.
static cl::opt<uint64_t> LaunchBase("ccv-frame-launch-base", cl::init(0x20000),
                                    cl::desc("CCV launch block address"));
static constexpr unsigned kBaseShift = 16;
static constexpr unsigned kOffLocalBase = 24;

void CCVFrameLowering::emitPrologue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {
  if (MF.getFrameInfo().getStackSize() == 0)
    return;    // nothing spilled: R15 stays reserved but unwritten

  const auto *TII = MF.getSubtarget<CCVSubtarget>().getInstrInfo();
  MachineBasicBlock::iterator I = MBB.begin();
  DebugLoc DL;

  // R15 = launch-block window, then the CTA's .local window base, then this
  // thread's own window. Nothing is live at function entry -- a kernel takes
  // no register arguments (§5.2) -- so R14 is free to use as a scratch here
  // regardless of what the allocator does with it later.
  BuildMI(MBB, I, DL, TII->get(CCV::MOVI), CCV::R15)
      .addImm(LaunchBase >> kBaseShift);
  BuildMI(MBB, I, DL, TII->get(CCV::LD_GLOBAL), CCV::R15)
      .addReg(CCV::R15)
      .addImm(kOffLocalBase);
  BuildMI(MBB, I, DL, TII->get(CCV::SRD), CCV::R14).addImm(0);  // %ctatid
  BuildMI(MBB, I, DL, TII->get(CCV::ADD), CCV::R15)
      .addReg(CCV::R15)
      .addReg(CCV::R14)
      .addReg(CCV::R15);
}
