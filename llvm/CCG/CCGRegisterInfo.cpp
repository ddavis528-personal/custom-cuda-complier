//===-- CCGRegisterInfo.cpp -----------------------------------------------===//
#include "CCGRegisterInfo.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "CCGFrameLowering.h"
#include "CCGSubtarget.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

#define GET_REGINFO_TARGET_DESC
#include "CCGGenRegisterInfo.inc"

using namespace llvm;

// No return-address register convention: the link register is explicit in
// call/ret and chosen by the compiler (§3, Format E).
CCGRegisterInfo::CCGRegisterInfo() : CCGGenRegisterInfo(/*RA=*/0) {}

const MCPhysReg *
CCGRegisterInfo::getCalleeSavedRegs(const MachineFunction *) const {
  return CSR_CCG_SaveList;
}

BitVector CCGRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  // Nothing is reserved. There is no frame pointer, no stack pointer and no
  // always-true predicate to set aside (§1) -- with 16 registers, reserving one
  // is 6% of the file and has to earn it.
  return BitVector(getNumRegs());
}

bool CCGRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *) const {
  // Reached only once something spills or takes an address of a local. The
  // frame lives in the thread-private .local window (§5.4); until Step 5
  // produces a spill, there is nothing to lower and reaching here is a bug
  // worth hearing about rather than silently miscompiling.
  report_fatal_error("CCG: frame index lowering not implemented -- no stack "
                     "frame exists yet (see roadmap Step 5)");
}

Register CCGRegisterInfo::getFrameRegister(const MachineFunction &) const {
  return 0;
}
