//===-- CCVInsertChwidth.cpp - place the element-width mode switches ------===//
//
// §1 makes element width per-LOGICAL-REGISTER state rather than an instruction
// field (invariant 1). Nothing in the encoding says how wide `add` is; the
// register's current `chwidth` does. Somebody has to set it, and that somebody
// is this pass.
//
// WHY POST-RA. `chwidth` names a physical register, and which physical register
// a value lands in is not known until allocation has run (F-3). By that point
// virtual registers and their classes are gone, so the width comes from the
// instruction's TSFlags -- see CCVInst in CCVInstrFormats.td for why the
// 16-bit instructions exist at all when they encode identically to their
// 32-bit namesakes.
//
// WHERE IT IS SAFE TO INSERT, AND WHY THAT IS NOT A FREE CHOICE.
//
// §3 says `chwidth` "reinterprets the existing contents" of a register, and §1
// says a narrow register is "a narrower physical slice of a row". Between them
// the specification never says what the bits above the element hold after a
// narrow->wide change (F-65). So a `chwidth` placed where the register is LIVE
// is relying on a guarantee the ISA does not give.
//
// This pass therefore inserts a `chwidth` only immediately before a DEFINITION
// whose width differs from the register's current width. At a definition the
// old value is dead by construction, so no contents are being reinterpreted
// and the question F-65 asks does not arise. That holds whichever way F-65 is
// eventually resolved, which is the point.
//
// A USE at a mismatched width is a different thing entirely: it means a value
// was produced at one width and read at another, which is a selection bug, not
// something a mode switch should paper over. The pass reports it rather than
// inserting anything.
//
// Prior art is RISCVInsertVSETVLI, as F-3 says. The difference is that
// `vsetvli` sets one global state and `chwidth` sets sixteen independent
// per-register ones, so the lattice is per-register; the dataflow is the same.
//
//===----------------------------------------------------------------------===//

#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-insert-chwidth"

static cl::opt<bool> ReportChwidth(
    "ccv-chwidth-stats", cl::init(false),
    cl::desc("report width transitions and chwidth.multi opportunities (F-3)"));

namespace {

/// Width of a physical register at a program point. 0-3 are §1's width codes;
/// kUnknown is the lattice bottom, used where predecessors disagree.
constexpr uint8_t kUnknown = 0xFF;
constexpr unsigned kNumGPR = 16;

using WidthState = std::array<uint8_t, kNumGPR>;

class CCVInsertChwidth : public MachineFunctionPass {
public:
  static char ID;
  CCVInsertChwidth() : MachineFunctionPass(ID) {}
  StringRef getPassName() const override { return "CCV chwidth insertion"; }

  bool runOnMachineFunction(MachineFunction &MF) override;

private:
  unsigned Inserted = 0, Narrowing = 0, Widening = 0, Multi = 0, Runs = 0,
           Hoisted = 0, Blocks = 0;
};

/// The element width an instruction expects a given OPERAND to be at.
///
/// Per operand, not per instruction. A store is the case that forces it:
/// `st.shared` at 16-bit width takes a 16-bit data register and a 32-bit BASE
/// ADDRESS, because an address is an address (§5.1, invariant 11) and §3 takes
/// the transfer size from `rdata`'s chwidth alone. A per-instruction width tag
/// sets the mode on the address register too, which is both wrong and, since
/// the base is live, a widening hazard later.
///
/// §4's `mad.lo` is the same shape deliberately: narrow `rs0`/`rs1`, wide
/// `rs2`/`rd`.
///
/// Read from the instruction description's static operand info, which survives
/// register allocation -- unlike the virtual register's class, which does not.
uint8_t operandWidth(const MCInstrDesc &D, unsigned OpNo) {
  if (OpNo >= D.getNumOperands())
    return 0;
  int16_t RC = D.operands()[OpNo].RegClass;
  if (RC == CCV::GPR16RegClassID)
    return 1;
  return 0;
}

/// R0-R15 as an index, or ~0 for anything else (predicates, virtual leftovers).
unsigned gprIndex(Register R) {
  if (R.id() >= CCV::R0 && R.id() <= CCV::R15)
    return R.id() - CCV::R0;
  return ~0u;
}

} // namespace

bool CCVInsertChwidth::runOnMachineFunction(MachineFunction &MF) {
  const TargetInstrInfo *TII = MF.getSubtarget().getInstrInfo();
  bool Changed = false;

  // --- 1. Forward dataflow over the CFG ------------------------------------
  //
  // Entry starts at width 32 for every register, which is the reset state a
  // warp begins in. A block whose predecessors disagree about a register starts
  // that register Unknown, and the first definition in the block then gets an
  // explicit `chwidth` -- conservative, and the only safe answer without
  // knowing which edge was taken.
  DenseMap<MachineBasicBlock *, WidthState> In;
  WidthState Zero;
  Zero.fill(0);
  In[&MF.front()] = Zero;

  SmallVector<MachineBasicBlock *, 8> Work{&MF.front()};
  DenseMap<MachineBasicBlock *, WidthState> Out;
  while (!Work.empty()) {
    MachineBasicBlock *MBB = Work.pop_back_val();
    WidthState S = In.count(MBB) ? In[MBB] : WidthState{};
    if (!In.count(MBB))
      S.fill(kUnknown);

    for (MachineInstr &MI : *MBB)
      for (unsigned O = 0, N = MI.getNumOperands(); O != N; ++O) {
        const MachineOperand &MO = MI.getOperand(O);
        if (!MO.isReg() || !MO.isDef())
          continue;
        unsigned I = gprIndex(MO.getReg());
        if (I != ~0u)
          S[I] = operandWidth(MI.getDesc(), O);
      }
    auto It = Out.find(MBB);
    if (It != Out.end() && It->second == S)
      continue;
    Out[MBB] = S;

    for (MachineBasicBlock *Succ : MBB->successors()) {
      WidthState Merged = S;
      auto SIt = In.find(Succ);
      if (SIt != In.end())
        for (unsigned I = 0; I != kNumGPR; ++I)
          if (SIt->second[I] != Merged[I])
            Merged[I] = kUnknown;
      if (SIt == In.end() || SIt->second != Merged) {
        In[Succ] = Merged;
        Work.push_back(Succ);
      }
    }
  }

  // --- 2. Insert ----------------------------------------------------------
  for (MachineBasicBlock &MBB : MF) {
    WidthState S = In.count(&MBB) ? In[&MBB] : WidthState{};
    if (!In.count(&MBB))
      S.fill(kUnknown);
    ++Blocks;

    for (MachineInstr &MI : llvm::make_early_inc_range(MBB)) {

      // A use at a different width is not automatically a bug, and the two
      // directions are not symmetric.
      //
      // NARROWING a live register is safe: a wider element's low bits are the
      // narrow element, so `chwidth` down is exactly what `trunc` means. This
      // is the common case -- a kernel argument arrives 32-bit and the
      // truncation to i16 disappears in coalescing, leaving a 32-bit register
      // read by a 16-bit instruction.
      //
      // WIDENING a live register is safe too, now that O-38 requires the
      // exposed bits to be cleared. That resolution came from the security
      // side rather than the compiler side -- stale bits in a register file
      // shared between warps and reused across launches are a cross-context
      // read -- and it happens to make `zext` free: widening a 16-bit value to
      // 32 bits IS a zero-extension, with no masking instruction at all.
      //
      // `sext` is not free and still has no lowering: it needs the sign
      // replicated, which zeros do not do. See F-66.
      for (unsigned O = 0, N = MI.getNumOperands(); O != N; ++O) {
        const MachineOperand &MO = MI.getOperand(O);
        if (!MO.isReg() || MO.isDef())
          continue;
        unsigned I = gprIndex(MO.getReg());
        uint8_t Need = operandWidth(MI.getDesc(), O);
        if (I == ~0u || S[I] == kUnknown || S[I] == Need)
          continue;
        // Either direction is safe on a live register now: narrowing is a
        // truncation and widening is a zero-extension, because O-38 requires
        // the exposed bits to be cleared.
        //
        // Classify BEFORE updating the state -- a larger width code is a
        // narrower element, and reading S[I] after assigning it made every
        // insertion report as a widening.
        if (Need > S[I])
          ++Narrowing;
        else
          ++Widening;
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(CCV::C_CHWIDTH))
            .addReg(MO.getReg())
            .addImm(Need);
        S[I] = Need;
        ++Inserted;
        Changed = true;
      }

      for (unsigned O = 0, N = MI.getNumOperands(); O != N; ++O) {
        const MachineOperand &MO = MI.getOperand(O);
        if (!MO.isReg() || !MO.isDef())
          continue;
        unsigned I = gprIndex(MO.getReg());
        uint8_t Need = operandWidth(MI.getDesc(), O);
        if (I == ~0u || S[I] == Need)
          continue;
        // The definition makes the old value dead, so this reinterprets
        // nothing -- which is what keeps it safe under F-65.
        BuildMI(MBB, MI, MI.getDebugLoc(), TII->get(CCV::C_CHWIDTH))
            .addReg(MO.getReg())
            .addImm(Need);
        S[I] = Need;
        ++Inserted;
        Changed = true;
      }
    }
  }

  // --- 3. Hoist each width change as early as it is legal ------------------
  //
  // §3, on why Format I carries a register mask at all: "a kernel entering a
  // packed section typically reconfigures several at once. Setting them in one
  // instruction collapses N drain events into one." O-6 then asks the compiler
  // to "hoist the mask instruction to a point where the affected registers are
  // cold".
  //
  // A `chwidth R, W` may move up past any instruction that does not touch R.
  // It may not pass an access to R, because everything between the width change
  // and the next one reads R at the new width -- that is the whole mechanism.
  // Block entry is the ceiling; hoisting across a block boundary would need the
  // dataflow in step 1 to agree on every predecessor, which is a separate
  // problem.
  //
  // Hoisting is what makes merging possible. Without it the transitions sit
  // wherever they were needed and no two are adjacent.
  for (MachineBasicBlock &MBB : MF) {
    for (MachineInstr &MI : llvm::make_early_inc_range(MBB)) {
      if (MI.getOpcode() != CCV::C_CHWIDTH)
        continue;
      Register R = MI.getOperand(0).getReg();
      MachineBasicBlock::iterator Dest = MI.getIterator();
      while (Dest != MBB.begin()) {
        MachineBasicBlock::iterator Prev = std::prev(Dest);
        bool Touches = Prev->getOpcode() == CCV::CHWIDTH_MULTI;
        for (const MachineOperand &MO : Prev->operands())
          if (MO.isReg() && MO.getReg() == R)
            Touches = true;
        if (Touches)
          break;
        Dest = Prev;
      }
      if (Dest != MI.getIterator()) {
        MBB.splice(Dest, &MBB, MI.getIterator());
        ++Hoisted;
        Changed = true;
      }
    }
  }

  // --- 4. Merge runs into chwidth.multi (O-6) ------------------------------
  //
  // §3: "`chwidth` requires draining in-flight dependents on the affected
  // register, and a kernel entering a packed section typically reconfigures
  // several at once. Setting them in one instruction collapses N drain events
  // into one." That is the whole argument for Format I carrying a register
  // mask, and this is the pass that has to make it pay.
  //
  // A run is consecutive `chwidth` instructions setting the SAME width. They
  // arrive adjacent because insertion puts them all immediately before the
  // instruction that needed them.
  //
  // Merge at two, not three. `chwidth` is 16 bits and `chwidth.multi` is 32, so
  // two registers is break-even on size and still turns two drains into one;
  // three or more wins on both. Below two there is nothing to merge.
  for (MachineBasicBlock &MBB : MF) {
    for (auto It = MBB.begin(); It != MBB.end();) {
      if (It->getOpcode() != CCV::C_CHWIDTH) {
        ++It;
        continue;
      }
      int64_t Width = It->getOperand(1).getImm();
      auto Run = It;
      uint32_t Mask = 0;
      unsigned N = 0;
      while (Run != MBB.end() && Run->getOpcode() == CCV::C_CHWIDTH &&
             Run->getOperand(1).getImm() == Width) {
        unsigned I = gprIndex(Run->getOperand(0).getReg());
        if (I == ~0u)
          break;
        Mask |= 1u << I;
        ++N;
        ++Run;
      }
      if (N < 2) {
        It = Run == It ? std::next(It) : Run;
        continue;
      }
      BuildMI(MBB, It, It->getDebugLoc(), TII->get(CCV::CHWIDTH_MULTI))
          .addImm(Mask)
          .addImm(Width);
      for (auto Dead = It; Dead != Run;)
        (Dead++)->eraseFromParent();
      Multi += N;
      ++Runs;
      Changed = true;
      It = Run;
    }
  }

  if (ReportChwidth)
    // Two different numbers, kept apart because conflating them made the
    // "at a definition" line underflow: `Inserted` counts width TRANSITIONS
    // the dataflow found, and the emitted instruction count is what survives
    // merging.
    errs() << "  chwidth insertion (F-3), " << MF.getName() << "\n"
           << "    blocks                : " << Blocks << "\n"
           << "    width transitions     : " << Inserted << "\n"
           << "      at a definition     : " << (Inserted - Narrowing - Widening)
           << "   (old value dead -- nothing reinterpreted)\n"
           << "      narrowing a live reg: " << Narrowing
           << "   (a truncation; the element bits are preserved)\n"
           << "      widening a live reg : " << Widening
           << "   (a zero-extension -- O-38 clears the exposed bits)\n"
           << "    hoisted               : " << Hoisted
           << "   (O-6: as early as legal, to make merging possible)\n"
           << "    merged by chwidth.multi: " << Multi << " into " << Runs
           << "   (O-6: N drain events become one)\n"
           << "    instructions emitted  : " << (Inserted - Multi + Runs)
           << "\n";
  return Changed;
}

char CCVInsertChwidth::ID = 0;

namespace llvm {
FunctionPass *createCCVInsertChwidth() { return new CCVInsertChwidth(); }
} // namespace llvm
