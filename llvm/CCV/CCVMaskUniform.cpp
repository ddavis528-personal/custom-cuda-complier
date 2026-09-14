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
  case CCV::FADD:  return CCV::FADD_P;
  case CCV::FSUB:  return CCV::FSUB_P;
  case CCV::FMUL:  return CCV::FMUL_P;
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
  default:         return 0;
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
      // Format D′ narrows the displacement from 13 bits to 10.
      if (MI.getOpcode() == CCV::LD_GLOBAL &&
          !isInt<10>(MI.getOperand(2).getImm()))
        continue;
      Register Def = MI.getOperand(0).getReg();
      if (!Def.isVirtual() || Divergent.count(Def))
        continue;
      Maskable.push_back(&MI);
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

  SmallVector<MachineInstr *, 16> NeedsBroadcast;
  for (MachineInstr *MI : Maskable) {
    Register Def = MI->getOperand(0).getReg();
    for (MachineInstr &U : MRI.use_nodbg_instructions(Def))
      if (!inUniformRegion(&U)) {
        NeedsBroadcast.push_back(MI);
        break;
      }
  }
  if (Maskable.size() <= NeedsBroadcast.size()) {
    if (ReportMasking)
      errs() << "  lane-0 masking, " << MF.getName() << ": "
             << Maskable.size() << " maskable vs " << NeedsBroadcast.size()
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

  if (ReportMasking)
    errs() << "  lane-0 masking (O-33), " << MF.getName() << "\n"
           << "    masked to lane 0      : " << Masked << "\n"
           << "    broadcasts inserted   : " << Broadcasts << "\n"
           << "    net lane-activations  : -" << (31 * (Masked - Broadcasts))
           << "   (31 saved per masked op, 31 spent per broadcast)\n";
  return true;
}

namespace llvm {
FunctionPass *createCCVMaskUniform() { return new CCVMaskUniform(); }
} // namespace llvm
