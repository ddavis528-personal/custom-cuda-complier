//===-- CCGInstrInfo.cpp --------------------------------------------------===//
#include "CCGInstrInfo.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "CCGGenInstrInfo.inc"

using namespace llvm;

/// §1: a predicate is 32 bits, one per lane, in a register file of its own
/// (invariant 5). `regOf` and the encoding both number P0-P3 from zero, so a
/// predicate copy emitted as a GPR move is not a type error anywhere -- it
/// assembles, disassembles and executes, and silently clobbers R0-R3.
static bool isPred(MCRegister R) { return R >= CCG::P0 && R <= CCG::P3; }

void CCGInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                               MachineBasicBlock::iterator MI,
                               const DebugLoc &DL, MCRegister DestReg,
                               MCRegister SrcReg, bool KillSrc) const {
  if (isPred(DestReg) != isPred(SrcReg))
    report_fatal_error("CCG: no copy between a GPR and a predicate -- they are "
                       "separate files (invariant 5); use ballot/unballot");

  if (isPred(DestReg)) {
    // O-20's predicate logic gives a copy for free: `por pd, ps, ps` is ps.
    // 16 bits, no new opcode point, and it reads the source twice rather than
    // needing a dedicated move.
    auto qual = [](MCRegister R) { return unsigned(R - CCG::P0); };
    BuildMI(MBB, MI, DL, get(CCG::POR), DestReg)
        .addImm(qual(SrcReg))
        .addImm(qual(SrcReg));
    return;
  }

  // The compressed mov is 16 bits and is a rename-time no-op at execution
  // (§3, Format K).
  BuildMI(MBB, MI, DL, get(CCG::C_MOV), DestReg)
      .addReg(SrcReg, getKillRegState(KillSrc));
}

// A condition is {guard predicate register, negate bit} -- the two halves of
// the qualifier at §3's [29:27].
static bool isCondBranch(const MachineInstr &MI) {
  return MI.getOpcode() == CCG::PSEUDO_BRA_PRED;
}
/// Both lengths. The selector emits the 16-bit `bra.short` and the assembler
/// relaxes it to Format E's 32-bit `bra` when the target does not reach
/// (F-28) -- but that decision belongs to layout, so at this level they are
/// one operation and every hook below has to accept either. Recognising only
/// `BRA` here is not a missed optimisation: the branch folder stops working,
/// and the dead fall-through branch F-26 removed comes straight back.
static bool isUncondBranch(const MachineInstr &MI) {
  return MI.getOpcode() == CCG::BRA || MI.getOpcode() == CCG::C_BRA;
}

bool CCGInstrInfo::analyzeBranch(MachineBasicBlock &MBB,
                                 MachineBasicBlock *&TBB,
                                 MachineBasicBlock *&FBB,
                                 SmallVectorImpl<MachineOperand> &Cond,
                                 bool AllowModify) const {
  TBB = FBB = nullptr;
  Cond.clear();

  MachineBasicBlock::iterator I = MBB.getLastNonDebugInstr();
  if (I == MBB.end() || !isUnpredicatedTerminator(*I))
    return false;

  MachineBasicBlock::iterator FirstTerm = I;
  unsigned NumTerm = 0;
  while (I != MBB.begin() && isUnpredicatedTerminator(*std::prev(I))) {
    --I;
    ++NumTerm;
  }
  FirstTerm = I;
  (void)NumTerm;

  MachineInstr &Last = *MBB.getLastNonDebugInstr();

  // Anything that is not a branch we understand -- `exit`, for instance --
  // means the block cannot be analyzed.
  for (auto J = FirstTerm; J != MBB.end(); ++J)
    if (!J->isDebugInstr() && !isCondBranch(*J) && !isUncondBranch(*J))
      return true;

  if (FirstTerm == std::prev(MBB.end())) {
    if (isUncondBranch(Last)) {
      TBB = Last.getOperand(0).getMBB();
      return false;
    }
    if (isCondBranch(Last)) {
      TBB = Last.getOperand(2).getMBB();
      Cond.push_back(Last.getOperand(0));   // guard register
      Cond.push_back(Last.getOperand(1));   // negate bit
      return false;
    }
    return true;
  }

  // Two terminators: conditional then unconditional.
  MachineInstr &First = *FirstTerm;
  if (isCondBranch(First) && isUncondBranch(Last)) {
    TBB = First.getOperand(2).getMBB();
    Cond.push_back(First.getOperand(0));
    Cond.push_back(First.getOperand(1));
    FBB = Last.getOperand(0).getMBB();
    return false;
  }
  return true;
}

unsigned CCGInstrInfo::removeBranch(MachineBasicBlock &MBB,
                                    int *BytesRemoved) const {
  if (BytesRemoved)
    *BytesRemoved = 0;
  unsigned Count = 0;
  MachineBasicBlock::iterator I = MBB.end();
  while (I != MBB.begin()) {
    --I;
    if (I->isDebugInstr())
      continue;
    if (!isCondBranch(*I) && !isUncondBranch(*I))
      break;
    if (BytesRemoved)
      *BytesRemoved += getInstSizeInBytes(*I);
    I = MBB.erase(I);
    I = MBB.end();
    ++Count;
  }
  return Count;
}

unsigned CCGInstrInfo::insertBranch(MachineBasicBlock &MBB,
                                    MachineBasicBlock *TBB,
                                    MachineBasicBlock *FBB,
                                    ArrayRef<MachineOperand> Cond,
                                    const DebugLoc &DL, int *BytesAdded) const {
  if (BytesAdded)
    *BytesAdded = 0;
  assert(TBB && "insertBranch needs a destination");
  assert((Cond.size() == 2 || Cond.empty()) &&
         "condition is {guard, negate}");

  if (Cond.empty()) {
    BuildMI(&MBB, DL, get(CCG::C_BRA)).addMBB(TBB);
    return 1;
  }

  BuildMI(&MBB, DL, get(CCG::PSEUDO_BRA_PRED))
      .add(Cond[0])
      .add(Cond[1])
      .addMBB(TBB);
  if (!FBB)
    return 1;
  BuildMI(&MBB, DL, get(CCG::C_BRA)).addMBB(FBB);
  return 2;
}

bool CCGInstrInfo::reverseBranchCondition(
    SmallVectorImpl<MachineOperand> &Cond) const {
  assert(Cond.size() == 2 && "condition is {guard, negate}");
  // The qualifier carries a negate bit (§1), so inverting a branch costs
  // nothing -- no extra instruction, no extra predicate.
  Cond[1].setImm(Cond[1].getImm() ? 0 : 1);
  return false;
}
