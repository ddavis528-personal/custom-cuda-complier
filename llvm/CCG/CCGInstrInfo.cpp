//===-- CCGInstrInfo.cpp --------------------------------------------------===//
#include "CCGInstrInfo.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "CCGGenInstrInfo.inc"

using namespace llvm;

void CCGInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                               MachineBasicBlock::iterator MI,
                               const DebugLoc &DL, MCRegister DestReg,
                               MCRegister SrcReg, bool KillSrc) const {
  // The compressed mov is 16 bits and is a rename-time no-op at execution
  // (§3, Format K).
  BuildMI(MBB, MI, DL, get(CCG::C_MOV), DestReg)
      .addReg(SrcReg, getKillRegState(KillSrc));
}
