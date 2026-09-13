//===-- CCGFrameLowering.cpp ----------------------------------------------===//
#include "CCGFrameLowering.h"
#include "CCGInstrInfo.h"
#include "CCGSubtarget.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

// Must match CCGLowerKernelArgs. The block's byte layout is an ABI choice, not
// an encoding one, and lives in both places until the ABI document exists.
static cl::opt<uint64_t> LaunchBase("ccg-frame-launch-base", cl::init(0x20000),
                                    cl::desc("CCG launch block address"));
static constexpr unsigned kBaseShift = 16;
static constexpr unsigned kOffLocalBase = 24;

void CCGFrameLowering::emitPrologue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {
  if (MF.getFrameInfo().getStackSize() == 0)
    return;    // nothing spilled: R15 stays reserved but unwritten

  const auto *TII = MF.getSubtarget<CCGSubtarget>().getInstrInfo();
  MachineBasicBlock::iterator I = MBB.begin();
  DebugLoc DL;

  // R15 = launch-block window, then the CTA's .local window base, then this
  // thread's own window. Nothing is live at function entry -- a kernel takes
  // no register arguments (§5.2) -- so R14 is free to use as a scratch here
  // regardless of what the allocator does with it later.
  BuildMI(MBB, I, DL, TII->get(CCG::MOVI), CCG::R15)
      .addImm(LaunchBase >> kBaseShift);
  BuildMI(MBB, I, DL, TII->get(CCG::LD_GLOBAL), CCG::R15)
      .addReg(CCG::R15)
      .addImm(kOffLocalBase);
  BuildMI(MBB, I, DL, TII->get(CCG::SRD), CCG::R14).addImm(0);  // %ctatid
  BuildMI(MBB, I, DL, TII->get(CCG::ADD), CCG::R15)
      .addReg(CCG::R15)
      .addReg(CCG::R14)
      .addReg(CCG::R15);
}
