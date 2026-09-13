//===-- CCGRegisterInfo.cpp -----------------------------------------------===//
#include "CCGRegisterInfo.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "CCGFrameLowering.h"
#include "CCGSubtarget.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/MathExtras.h"

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
  BitVector Reserved(getNumRegs());
  // R15 is the frame pointer: it holds the WINDOW INDEX of this thread's
  // `.local` frame, so a spill is one base+offset instruction and needs no
  // index register. See O-30.
  //
  // It has to be reserved unconditionally, which costs 6% of the file in every
  // kernel: whether a function spills is decided during register allocation,
  // and this is asked before. It only binds at 16 simultaneously live values,
  // so no kernel measured so far pays anything for it.
  Reserved.set(CCG::R15);
  return Reserved;
}

bool CCGRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *) const {
  MachineInstr &I = *MI;
  MachineFunction &MF = *I.getParent()->getParent();
  int FI = I.getOperand(FIOperandNum).getIndex();
  int64_t Off = MF.getFrameInfo().getObjectOffset(FI) +
                I.getOperand(FIOperandNum + 1).getImm();

  // R15 holds the window index, so the whole frame is addressed by the
  // displacement alone. §3 gives Format D 13 signed bits, which caps a frame
  // at 4 KiB in each direction -- far inside the 64 KiB window it sits in.
  if (!isInt<13>(Off))
    report_fatal_error("CCG: stack frame exceeds the 13-bit displacement of "
                       "§3's Format D; this kernel spills more than 4 KiB per "
                       "thread");

  I.getOperand(FIOperandNum).ChangeToRegister(CCG::R15, /*isDef=*/false);
  I.getOperand(FIOperandNum + 1).ChangeToImmediate(Off);
  return false;
}

Register CCGRegisterInfo::getFrameRegister(const MachineFunction &) const {
  return CCG::R15;
}
