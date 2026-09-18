//===-- CCVMaskUniform.cpp - run warp-uniform work on one lane ------------===//
//
// O-33. Measured with `-ccv-uniformity-stats`, half of what an addressing-heavy
// kernel does is warp-uniform: the same value computed identically in all 32
// lanes. This runs that work with only lane 0 active and broadcasts the result,
// so 31 lanes never switch.
//
//     pmov       P3, #1            ; lane 0 only -- once, in the entry block
//     @P3 add    R1, R2, R3        ; uniform work, one lane active
//     @P3 shl    R1, R1, #2
//     @!P3 shfl.idx R1, R1, 0      ; lanes 1-31 read lane 0; lane 0 keeps its
//                                  ; own value, so one instruction suffices
//
// **This is a power optimisation and it only pays if the hardware gates
// mask-off lanes.** Nothing above makes that true; it is an RTL obligation.
// If predicated-off lanes still burn dynamic power, this transformation costs
// one broadcast per region and returns nothing. See O-33.
//
// Predication rather than branching, deliberately: a branch would split the
// per-thread PCs (§1) and the broadcast is a warp-collective instruction, which
// needs the lanes co-issued. Predication keeps every lane at the same PC.
//
// Two safety conditions, and the second is the subtle one:
//
//   - The operation must HAVE a predicated form. §4 gives Format A′ a 7-bit
//     opcode, so points 128+ (conversions) and 256+ (SFU) cannot be masked.
//
//   - The block must be reached by EVERY lane. A uniform value computed in a
//     divergently-reached block is still uniform, but lane 0 might not be among
//     the lanes that get there, and the broadcast would then read a value
//     nobody computed.
//
//===----------------------------------------------------------------------===//

#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/ADT/DenseSet.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/MachineDominators.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachinePostDominators.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-mask-uniform"

static cl::opt<bool> EnableMasking("ccv-mask-uniform", cl::init(true),
                                   cl::desc("run warp-uniform work on lane 0 "
                                            "and broadcast (O-33)"));
/// F-58's composition. ON by default, by design-track decision.
///
/// An instruction that already carries a control-flow predicate can ALSO be
/// masked to lane 0: the qualifier names a predicate register, and the
/// conjunction of two conditions is a predicate register. §3's `pand` is a
/// 16-bit Format K instruction that computes it.
///
/// Measured on `transpose`: 5 `pand` for 62 lane-activations, about 12 per
/// instruction added, against the 31 a plainly-masked instruction saves.
///
/// **This spends a second RTL property**, on top of O-33's. O-33 requires that
/// a predicated-off lane not toggle its ALU operands, write port or result bus.
/// This additionally requires that a PREDICATE-FILE operation cost much less
/// than a warp-wide one -- a predicate is 32 bits, one per lane (invariant 5),
/// so `pand` is 32 AND gates against 32 lanes of 32-bit datapath. The ratio
/// should be about the width of a lane. If the RTL instead runs predicate logic
/// through the vector path, this is a net loss of 5 instructions per kernel and
/// the compiler cannot tell. Both properties are recorded in §9, O-33.
static cl::opt<bool> ComposePredicates("ccv-mask-compose", cl::init(true),
    cl::desc("also mask instructions that already carry a predicate, by "
             "computing the conjunction with `pand` (F-58)"));

static cl::opt<bool> ReportMasking("ccv-mask-stats",
                                   cl::desc("report what was masked"));

namespace {

/// The predicated twin, or 0 if this operation has none.
unsigned predicatedForm(unsigned Op) {
  switch (Op) {
  case CCV::ADD:   return CCV::ADD_P;
  case CCV::SUB:   return CCV::SUB_P;
  case CCV::AND:   return CCV::AND_P;
  case CCV::OR:    return CCV::OR_P;
  case CCV::XOR:   return CCV::XOR_P;
  case CCV::SHL:   return CCV::SHL_P;
  case CCV::SHR:   return CCV::SHR_P;
  case CCV::SRA:   return CCV::SRA_P;
  case CCV::MIN_S: return CCV::MIN_S_P;
  case CCV::MIN_U: return CCV::MIN_U_P;
  case CCV::MAX_S: return CCV::MAX_S_P;
  case CCV::MAX_U: return CCV::MAX_U_P;
  case CCV::MUL_HI_S: return CCV::MUL_HI_S_P;
  case CCV::MUL_HI_U: return CCV::MUL_HI_U_P;
  case CCV::MADLO: return CCV::MADLO_P;
  // O-41's Format B projection. These were added with the immediate forms and
  // this table was not extended, so every `add rd, rs, #k` in uniform code was
  // unmaskable -- which is most of the addressing arithmetic O-33 exists to
  // gate. Format B' splits its immediate field around the qualifier and keeps
  // only 10 of the 13 bits, so narrowsImmediate() below refuses the ones that
  // would not survive the rewrite. The shift forms carry uimm5 in both tiers
  // and lose nothing.
  case CCV::ADDI:  return CCV::ADDI_P;
  case CCV::SUBI:  return CCV::SUBI_P;
  case CCV::MULI:  return CCV::MULI_P;
  case CCV::ANDI:  return CCV::ANDI_P;
  case CCV::ORI:   return CCV::ORI_P;
  case CCV::XORI:  return CCV::XORI_P;
  case CCV::ANDNI: return CCV::ANDNI_P;
  case CCV::SHLI:  return CCV::SHLI_P;
  case CCV::SHRI:  return CCV::SHRI_P;
  case CCV::SRAI:  return CCV::SRAI_P;
  // Only FSUB: `fadd` and `fmul` select the compressed two-address form, so
  // entries for them could never fire. The consequence is that O-33 cannot
  // gate a uniform float add or multiply -- which costs nothing on the current
  // kernels, where the float arithmetic is per-lane data and divergent anyway,
  // and is recorded as F-117 rather than assumed harmless.
  case CCV::FSUB:  return CCV::FSUB_P;
  // ld.global is conditional: Format D′'s offset is 10 bits where D's is 13
  // (§3), so the displacement has to fit. Launch-block offsets are tens of
  // bytes, so it essentially always does -- and leaving loads out entirely
  // made the pass fire on nothing at all, because launch-block loads ARE the
  // uniform work in these kernels.
  case CCV::LD_GLOBAL: return CCV::LD_GLOBAL_P;
  // O-34 moved conversions from 128+ into 64-127, which is inside Format A′'s
  // 7-bit reach, so the division sequence's two `cvt`s can now be masked.
  // `rcp.f32` still cannot -- the SFU is at 256+ and Format A′ stops at 127.
  case CCV::CVT_F32_S32: return CCV::CVT_F32_S32_P;
  case CCV::CVT_F32_U32: return CCV::CVT_F32_U32_P;
  case CCV::CVT_S32_F32: return CCV::CVT_S32_F32_P;
  case CCV::CVT_U32_F32: return CCV::CVT_U32_F32_P;
  // O-37: the SFU is at §4 256+, outside A′'s 7-bit reach, so `rcp.f32` gets
  // its qualifier from the 48-bit sibling instead. Six bytes rather than four,
  // on the one instruction of the division sequence that was still burning all
  // 32 lanes.
  case CCV::RCP_F32:     return CCV::RCP_F32_P;
  default:         return 0;
  }
}

/// True when the predicated sibling's immediate field is too narrow to hold
/// what this instruction holds. Predication costs three bits of qualifier and
/// they come out of the immediate: Format D' keeps 10 of the 13-bit
/// displacement and Format B' keeps 10 of the 13-bit immediate. Rewriting past
/// that limit produces an instruction that encodes a different number, which
/// the round-trip check catches -- but only for the forms it happens to
/// exercise, so the pass refuses rather than relying on being caught.
bool narrowsImmediate(const MachineInstr &MI) {
  switch (MI.getOpcode()) {
  default:
    return false;
  case CCV::LD_GLOBAL: // Format D' displacement, operand 2
  case CCV::ADDI:
  case CCV::SUBI:
  case CCV::MULI:
  case CCV::ANDI:
  case CCV::ORI:
  case CCV::XORI:
  case CCV::ANDNI: // Format B' immediate, operand 2
    return !isInt<10>(MI.getOperand(2).getImm());
  case CCV::SHLI:
  case CCV::SHRI:
  case CCV::SRAI:
    return false; // uimm5 in both tiers, nothing is lost
  }
}

/// §5.3: `srd` selector 0 is `%ctatid`, the one architectural source of
/// per-lane difference. Everything else a kernel can read is CTA-wide or
/// grid-wide, and both are uniform across a warp.
bool isDivergentSource(const MachineInstr &MI) {
  return MI.getOpcode() == CCV::SRD && MI.getOperand(1).isImm() &&
         MI.getOperand(1).getImm() == 0;
}

class CCVMaskUniform : public MachineFunctionPass {
public:
  static char ID;
  CCVMaskUniform() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.addRequired<MachinePostDominatorTree>();
    MachineFunctionPass::getAnalysisUsage(AU);
  }
  StringRef getPassName() const override {
    return "CCV warp-uniform lane-0 masking";
  }
};

char CCVMaskUniform::ID = 0;

} // namespace

bool CCVMaskUniform::runOnMachineFunction(MachineFunction &MF) {
  if (!EnableMasking)
    return false;
  MachineRegisterInfo &MRI = MF.getRegInfo();
  const auto *TII = MF.getSubtarget<CCVSubtarget>().getInstrInfo();
  auto &PDT = getAnalysis<MachinePostDominatorTree>();

  // --- 1. Which values differ between lanes ------------------------------
  DenseSet<Register> Divergent;
  bool Changed = true;
  while (Changed) {
    Changed = false;
    for (MachineBasicBlock &MBB : MF)
      for (MachineInstr &MI : MBB) {
        bool Div = isDivergentSource(MI);
        if (!Div)
          for (const MachineOperand &MO : MI.uses())
            if (MO.isReg() && MO.getReg().isVirtual() &&
                Divergent.count(MO.getReg())) {
              Div = true;
              break;
            }
        if (!Div)
          continue;
        for (const MachineOperand &MO : MI.defs())
          if (MO.isReg() && MO.getReg().isVirtual())
            Changed |= Divergent.insert(MO.getReg()).second;
      }
  }

  // --- 2. Which blocks every lane reaches --------------------------------
  // A block is divergently reached exactly when it is control-dependent on a
  // branch whose condition differs between lanes.
  DenseSet<const MachineBasicBlock *> DivReached;
  for (MachineBasicBlock &P : MF) {
    if (P.succ_size() < 2)
      continue;
    bool DivergentBranch = false;
    for (MachineInstr &T : P.terminators())
      for (const MachineOperand &MO : T.uses())
        if (MO.isReg() && MO.getReg().isVirtual() && Divergent.count(MO.getReg()))
          DivergentBranch = true;
    if (!DivergentBranch)
      continue;
    MachineDomTreeNode *Stop =
        PDT.getNode(&P) ? PDT.getNode(&P)->getIDom() : nullptr;
    for (MachineBasicBlock *S : P.successors())
      for (MachineDomTreeNode *N = PDT.getNode(S); N && N != Stop;
           N = N->getIDom())
        if (N->getBlock())
          DivReached.insert(N->getBlock());
  }

  // --- 3. What can be masked, and whether it pays ------------------------
  SmallVector<MachineInstr *, 32> Maskable;
  DenseSet<MachineInstr *> InSet;
  for (MachineBasicBlock &MBB : MF) {
    if (DivReached.count(&MBB))
      continue;
    for (MachineInstr &MI : MBB) {
      if (!predicatedForm(MI.getOpcode()) || MI.getNumDefs() != 1)
        continue;
      if (narrowsImmediate(MI))
        continue;
      Register Def = MI.getOperand(0).getReg();
      if (!Def.isVirtual() || Divergent.count(Def))
        continue;
      Maskable.push_back(&MI);
      InSet.insert(&MI);
    }
  }

  // --- 3b. Instructions that ALREADY carry a predicate -------------------
  //
  // F-58 said these were unreachable: the qualifier field is three bits and
  // one predicate, so an instruction guarded by a control-flow condition
  // cannot also be guarded by the lane mask. That is true of the FIELD and
  // false of the MACHINE. The qualifier names a predicate REGISTER, and the
  // conjunction of two conditions is a predicate register -- §3's `pand` is a
  // 16-bit Format K instruction that computes exactly that.
  //
  // So the cost is not "impossible", it is one compressed instruction per
  // guarded value, and it buys the same 31 lane-activations any other masked
  // instruction buys.
  SmallVector<MachineInstr *, 8> Composable;
  for (MachineBasicBlock &MBB : MF) {
    if (DivReached.count(&MBB))
      continue;
    for (MachineInstr &MI : MBB) {
      if (!ComposePredicates || MI.getOpcode() != CCV::PSEUDO_PMOV)
        continue;
      Register Def = MI.getOperand(0).getReg();
      Register Cond = MI.getOperand(2).getReg();
      // The guard has to be uniform too: masking to lane 0 under a guard only
      // lane 5 satisfies would compute nothing and broadcast garbage.
      if (!Def.isVirtual() || Divergent.count(Def) || !Cond.isVirtual() ||
          Divergent.count(Cond))
        continue;
      Composable.push_back(&MI);
      InSet.insert(&MI);
    }
  }

  // A broadcast is needed only where a uniform value reaches DIVERGENT work --
  // not merely where it reaches something unmaskable.
  //
  // That distinction is worth stating, because getting it wrong doubles the
  // broadcast count. A uniform instruction with no predicated form (a
  // compressed shift, say) still runs on all 32 lanes, and lanes 1-31 will
  // compute from whatever garbage the masked region left them. That is
  // harmless: lane 0's input was correct, so lane 0's result is correct, and
  // lane 0 is the only lane the eventual broadcast reads. Such an instruction
  // costs a missed saving, not a broadcast.
  auto inUniformRegion = [&](const MachineInstr *MI) {
    if (!MI || DivReached.count(MI->getParent()))
      return false;
    bool AnyDef = false;
    for (const MachineOperand &MO : MI->defs())
      if (MO.isReg() && MO.getReg().isVirtual()) {
        AnyDef = true;
        if (Divergent.count(MO.getReg()))
          return false;
      }
    // No virtual def at all -- a store or a branch. It consumes values in
    // every lane, so anything feeding it has to be broadcast first.
    return AnyDef;
  };

  // TRIED AND WRONG: skipping the mask on any value that needs its own
  // broadcast. The arithmetic looks compelling -- masking saves 31
  // lane-activations and the broadcast spends 31, so it is break-even in energy
  // and one instruction worse -- and it miscompiles. An unmasked instruction is
  // not correct in all lanes, because its INPUTS were masked: lanes 1-31 hold
  // whatever the masked region left them. The broadcast is not the price of
  // masking this instruction, it is the price of the region.
  //
  // `transpose` went 79 instructions to 76 and produced wrong answers in 31 of
  // 32 lanes. tools/check-mask.sh caught it immediately, which is what it is
  // for.
  SmallVector<MachineInstr *, 16> NeedsBroadcast;
  for (MachineInstr *MI : Composable) {
    Register Def = MI->getOperand(0).getReg();
    for (MachineInstr &U : MRI.use_nodbg_instructions(Def))
      if (!inUniformRegion(&U)) {
        NeedsBroadcast.push_back(MI);
        break;
      }
  }
  for (MachineInstr *MI : Maskable) {
    Register Def = MI->getOperand(0).getReg();
    for (MachineInstr &U : MRI.use_nodbg_instructions(Def))
      if (!inUniformRegion(&U)) {
        NeedsBroadcast.push_back(MI);
        break;
      }
  }
  if (Maskable.size() + Composable.size() <= NeedsBroadcast.size()) {
    if (ReportMasking)
      errs() << "  lane-0 masking, " << MF.getName() << ": "
             << (Maskable.size() + Composable.size()) << " maskable vs "
             << NeedsBroadcast.size()
             << " broadcasts -- does not pay, skipped\n";
    return false;
  }

  // --- 4. Rewrite --------------------------------------------------------
  // P3 is reserved, so the qualifier is a compile-time immediate and none of
  // this needs a pseudo or a post-RA fixup.
  const unsigned QualTrue = unsigned(CCV::P3 - CCV::P0);

  MachineBasicBlock &Entry = MF.front();
  BuildMI(Entry, Entry.begin(), DebugLoc(), TII->get(CCV::PMOV_IMM), CCV::P3)
      .addImm(1);                       // lane 0 only

  DenseSet<MachineInstr *> WantsBroadcast(NeedsBroadcast.begin(),
                                          NeedsBroadcast.end());
  unsigned Masked = 0, Broadcasts = 0;

  for (MachineInstr *MI : Maskable) {
    Register Def = MI->getOperand(0).getReg();
    bool Crossing = WantsBroadcast.count(MI);

    // A value that leaves the region is computed into a temporary and the
    // broadcast produces the original register, so every existing use keeps
    // reading the name it already reads.
    Register Dst = Crossing ? MRI.createVirtualRegister(MRI.getRegClass(Def))
                            : Def;

    MachineInstrBuilder B = BuildMI(*MI->getParent(), *MI, MI->getDebugLoc(),
                                    TII->get(predicatedForm(MI->getOpcode())),
                                    Dst);
    B.addImm(QualTrue);
    for (unsigned I = 1, N = MI->getNumOperands(); I != N; ++I)
      B.add(MI->getOperand(I));
    // Format A′ is three-source like A; a two-source operation leaves rs2
    // unread, so tie it to rs0 rather than leave a third value live.
    while (B->getNumOperands() < TII->get(B->getOpcode()).getNumOperands())
      B.addReg(MI->getOperand(1).getReg());

    if (Crossing) {
      BuildMI(*MI->getParent(), *MI, MI->getDebugLoc(),
              TII->get(CCV::PSEUDO_BCAST), Def)
          .addReg(Dst);
      ++Broadcasts;
    }
    MI->eraseFromParent();
    ++Masked;
  }

  // Compose each already-guarded instruction's condition with the lane mask.
  // `pand` is 16 bits, so a region with more than one instruction under the
  // same guard amortises it -- but the conjunction is computed per guarded
  // instruction here rather than per guard, because two instructions under one
  // guard may sit in different blocks and CSE will fold the duplicates.
  unsigned Composed = 0;
  for (MachineInstr *MI : Composable) {
    Register Def = MI->getOperand(0).getReg();
    Register Cond = MI->getOperand(2).getReg();
    // MEASURED, not assumed: composing a crossing value costs a `pand` plus a
    // 31-lane broadcast to save at most popcount(cond) - 1, and popcount(cond)
    // is 0 whenever the guard is false -- which for a warp-uniform guard is
    // half the time. Composing every candidate made `transpose` WORSE, 76
    // instructions to 81 and 1587 lane-activations to 1685. Only the
    // non-crossing ones pay.
    if (WantsBroadcast.count(MI))
      continue;
    const bool Crossing = false;

    Register Both = MRI.createVirtualRegister(&CCV::PRRegClass);
    BuildMI(*MI->getParent(), *MI, MI->getDebugLoc(),
            TII->get(CCV::PSEUDO_PAND), Both)
        .addReg(Cond)
        .addReg(CCV::P3);

    Register Dst = Crossing ? MRI.createVirtualRegister(MRI.getRegClass(Def))
                            : Def;
    // Two-address: the tied false arm has to become the new destination too,
    // or the excluded lanes would preserve the wrong register.
    BuildMI(*MI->getParent(), *MI, MI->getDebugLoc(),
            TII->get(CCV::PSEUDO_PMOV), Dst)
        .addReg(Crossing ? Def : MI->getOperand(1).getReg())
        .addReg(Both)
        .add(MI->getOperand(3));

    if (Crossing) {
      BuildMI(*MI->getParent(), *MI, MI->getDebugLoc(),
              TII->get(CCV::PSEUDO_BCAST), Def)
          .addReg(Dst);
      ++Broadcasts;
    }
    MI->eraseFromParent();
    ++Composed;
  }

  if (ReportMasking)
    errs() << "  lane-0 masking (O-33), " << MF.getName() << "\n"
           << "    composed with `pand`  : " << Composed
           << "   (already-predicated, F-58)\n"
           << "    masked to lane 0      : " << Masked << "\n"
           << "    broadcasts inserted   : " << Broadcasts << "\n"
           << "    net lane-activations  : -"
           << (31 * (Masked + Composed - Broadcasts))
           << "   (31 saved per masked op, 31 spent per broadcast)\n";
  return true;
}

namespace llvm {
FunctionPass *createCCVMaskUniform() { return new CCVMaskUniform(); }
} // namespace llvm
