//===-- CCVInstrInfo.cpp --------------------------------------------------===//
#include "CCVInstrInfo.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "CCVGenInstrInfo.inc"

using namespace llvm;

/// Spill and reload. The frame pointer holds this thread's `.local` WINDOW
/// index (O-30), so the frame offset is the whole address computation -- one
/// base+offset instruction, no index register, and the frame costs one
/// reserved GPR rather than two.
///
/// A predicate spills through `ld.pred`/`st.pred` (O-19), which is what those
/// instructions were added for in v1.3: F-2 found there was no way to get a
/// predicate into memory at all, and without one the allocator cannot spill a
/// predicate even in principle.
void CCVInstrInfo::storeRegToStackSlot(MachineBasicBlock &MBB,
                                       MachineBasicBlock::iterator MI,
                                       Register SrcReg, bool isKill,
                                       int FrameIndex,
                                       const TargetRegisterClass *RC,
                                       const TargetRegisterInfo *,
                                       Register) const {
  DebugLoc DL = MI != MBB.end() ? MI->getDebugLoc() : DebugLoc();
  if (RC->getID() == CCV::PRRegClassID) {
    // §3: [14:11] is a 4-bit predicate MASK, not a register number, so one
    // instruction can move any subset of the file. The allocator spills one at
    // a time, so the mask has a single bit set.
    BuildMI(MBB, MI, DL, get(CCV::ST_PRED_G))
        .addImm(1u << (SrcReg - CCV::P0))
        .addFrameIndex(FrameIndex)
        .addImm(0);
    return;
  }
  BuildMI(MBB, MI, DL, get(CCV::ST_GLOBAL))
      .addReg(SrcReg, getKillRegState(isKill))
      .addFrameIndex(FrameIndex)
      .addImm(0);
}

void CCVInstrInfo::loadRegFromStackSlot(MachineBasicBlock &MBB,
                                        MachineBasicBlock::iterator MI,
                                        Register DestReg, int FrameIndex,
                                        const TargetRegisterClass *RC,
                                        const TargetRegisterInfo *,
                                        Register) const {
  DebugLoc DL = MI != MBB.end() ? MI->getDebugLoc() : DebugLoc();
  if (RC->getID() == CCV::PRRegClassID) {
    BuildMI(MBB, MI, DL, get(CCV::LD_PRED_G))
        .addImm(1u << (DestReg - CCV::P0))
        .addFrameIndex(FrameIndex)
        .addImm(0);
    return;
  }
  BuildMI(MBB, MI, DL, get(CCV::LD_GLOBAL), DestReg)
      .addFrameIndex(FrameIndex)
      .addImm(0);
}

/// §1: a predicate is 32 bits, one per lane, in a register file of its own
/// (invariant 5). `regOf` and the encoding both number P0-P3 from zero, so a
/// predicate copy emitted as a GPR move is not a type error anywhere -- it
/// assembles, disassembles and executes, and silently clobbers R0-R3.
static bool isPred(MCRegister R) { return R >= CCV::P0 && R <= CCV::P3; }

void CCVInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                               MachineBasicBlock::iterator MI,
                               const DebugLoc &DL, MCRegister DestReg,
                               MCRegister SrcReg, bool KillSrc) const {
  if (isPred(DestReg) != isPred(SrcReg))
    report_fatal_error("CCV: no copy between a GPR and a predicate -- they are "
                       "separate files (invariant 5); use ballot/unballot");

  if (isPred(DestReg)) {
    // O-20's predicate logic gives a copy for free: `por pd, ps, ps` is ps.
    // 16 bits, no new opcode point, and it reads the source twice rather than
    // needing a dedicated move.
    auto qual = [](MCRegister R) { return unsigned(R - CCV::P0); };
    BuildMI(MBB, MI, DL, get(CCV::POR), DestReg)
        .addImm(qual(SrcReg))
        .addImm(qual(SrcReg));
    return;
  }

  // The compressed mov is 16 bits and is a rename-time no-op at execution
  // (§3, Format K).
  BuildMI(MBB, MI, DL, get(CCV::C_MOV), DestReg)
      .addReg(SrcReg, getKillRegState(KillSrc));
}

// A condition is {guard predicate register, negate bit} -- the two halves of
// the qualifier at §3's [29:27].
static bool isCondBranch(const MachineInstr &MI) {
  return MI.getOpcode() == CCV::PSEUDO_BRA_PRED;
}
/// Both lengths. The selector emits the 16-bit `bra.short` and the assembler
/// relaxes it to Format E's 32-bit `bra` when the target does not reach
/// (F-28) -- but that decision belongs to layout, so at this level they are
/// one operation and every hook below has to accept either. Recognising only
/// `BRA` here is not a missed optimisation: the branch folder stops working,
/// and the dead fall-through branch F-26 removed comes straight back.
static bool isUncondBranch(const MachineInstr &MI) {
  return MI.getOpcode() == CCV::BRA || MI.getOpcode() == CCV::C_BRA;
}

bool CCVInstrInfo::analyzeBranch(MachineBasicBlock &MBB,
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

unsigned CCVInstrInfo::removeBranch(MachineBasicBlock &MBB,
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

unsigned CCVInstrInfo::insertBranch(MachineBasicBlock &MBB,
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
    BuildMI(&MBB, DL, get(CCV::C_BRA)).addMBB(TBB);
    return 1;
  }

  BuildMI(&MBB, DL, get(CCV::PSEUDO_BRA_PRED))
      .add(Cond[0])
      .add(Cond[1])
      .addMBB(TBB);
  if (!FBB)
    return 1;
  BuildMI(&MBB, DL, get(CCV::C_BRA)).addMBB(FBB);
  return 2;
}

bool CCVInstrInfo::reverseBranchCondition(
    SmallVectorImpl<MachineOperand> &Cond) const {
  assert(Cond.size() == 2 && "condition is {guard, negate}");
  // The qualifier carries a negate bit (§1), so inverting a branch costs
  // nothing -- no extra instruction, no extra predicate.
  Cond[1].setImm(Cond[1].getImm() ? 0 : 1);
  return false;
}
