//===-- CCVMCCodeEmitter.cpp - CCV machine code emitter ------------------===//
//
// Instructions are 16, 32 or 48 bits (§2). The generated encoder returns the
// value; the size comes from MCInstrDesc, and bytes go out little-endian.
//
//===----------------------------------------------------------------------===//

#include "CCVFixupKinds.h"
#include "CCVMCTargetDesc.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/Support/MathExtras.h"
#include "CCVOperandWidths.inc"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/EndianStream.h"

using namespace llvm;

namespace {

class CCVMCCodeEmitter : public MCCodeEmitter {
  const MCInstrInfo &MCII;
  MCContext &Ctx;

public:
  CCVMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx)
      : MCII(MCII), Ctx(Ctx) {}

  void encodeInstruction(const MCInst &MI, SmallVectorImpl<char> &CB,
                         SmallVectorImpl<MCFixup> &Fixups,
                         const MCSubtargetInfo &STI) const override;

  // Generated.
  uint64_t getBinaryCodeForInstr(const MCInst &MI,
                                 SmallVectorImpl<MCFixup> &Fixups,
                                 const MCSubtargetInfo &STI) const;

  unsigned getMachineOpValue(const MCInst &MI, const MCOperand &MO,
                             SmallVectorImpl<MCFixup> &Fixups,
                             const MCSubtargetInfo &STI) const;

  // Generated code calls these by name for the branch-target operands.
  unsigned getBranch21OpValue(const MCInst &MI, unsigned OpNo,
                              SmallVectorImpl<MCFixup> &Fixups,
                              const MCSubtargetInfo &STI) const;
  unsigned getBranch18OpValue(const MCInst &MI, unsigned OpNo,
                              SmallVectorImpl<MCFixup> &Fixups,
                              const MCSubtargetInfo &STI) const;
  unsigned getBranch8OpValue(const MCInst &MI, unsigned OpNo,
                             SmallVectorImpl<MCFixup> &Fixups,
                             const MCSubtargetInfo &STI) const;

private:
  unsigned branchOpValue(const MCInst &MI, unsigned OpNo,
                         SmallVectorImpl<MCFixup> &Fixups, unsigned Kind) const;
};

} // namespace

unsigned CCVMCCodeEmitter::getMachineOpValue(const MCInst &, const MCOperand &MO,
                                             SmallVectorImpl<MCFixup> &,
                                             const MCSubtargetInfo &) const {
  if (MO.isReg())
    return Ctx.getRegisterInfo()->getEncodingValue(MO.getReg());
  if (MO.isImm())
    return static_cast<unsigned>(MO.getImm());
  // Branch targets go through the per-operand encoders above, which create
  // fixups; anything else reaching here with an expression is a bug.
  llvm_unreachable("CCV: unhandled operand kind in getMachineOpValue");
}

/// A resolved target is encoded directly; an unresolved one becomes a fixup at
/// offset 0 of the instruction, so applyFixup sees the whole word and can
/// scatter a split field.
unsigned CCVMCCodeEmitter::branchOpValue(const MCInst &MI, unsigned OpNo,
                                         SmallVectorImpl<MCFixup> &Fixups,
                                         unsigned Kind) const {
  const MCOperand &MO = MI.getOperand(OpNo);
  if (MO.isImm())
    return unsigned(MO.getImm());
  assert(MO.isExpr() && "branch target must be an immediate or an expression");
  Fixups.push_back(MCFixup::create(0, MO.getExpr(), MCFixupKind(Kind)));
  return 0;
}

unsigned CCVMCCodeEmitter::getBranch21OpValue(const MCInst &MI, unsigned OpNo,
                                              SmallVectorImpl<MCFixup> &Fixups,
                                              const MCSubtargetInfo &) const {
  return branchOpValue(MI, OpNo, Fixups, CCV::fixup_ccv_bra21);
}

unsigned CCVMCCodeEmitter::getBranch18OpValue(const MCInst &MI, unsigned OpNo,
                                              SmallVectorImpl<MCFixup> &Fixups,
                                              const MCSubtargetInfo &) const {
  return branchOpValue(MI, OpNo, Fixups, CCV::fixup_ccv_brapred18);
}

unsigned CCVMCCodeEmitter::getBranch8OpValue(const MCInst &MI, unsigned OpNo,
                                             SmallVectorImpl<MCFixup> &Fixups,
                                             const MCSubtargetInfo &) const {
  return branchOpValue(MI, OpNo, Fixups, CCV::fixup_ccv_bra8);
}

/// An immediate wider than its field is silently truncated by the generated
/// encoder -- the bits simply do not reach the instruction. That is not a
/// theoretical hazard: a shift by 31 selected into Format K's 4-bit immediate
/// became a shift by 15, and integer division miscompiled while every
/// primitive it used tested correct (F-43). Nothing downstream can notice,
/// because the encoder and the decoder agree perfectly on the truncated value.
///
/// So check it here, against the same .td the encoder is generated from.
static void verifyImmediatesFit(const MCInst &MI, StringRef Name) {
  for (unsigned I = 0, N = MI.getNumOperands(); I != N; ++I) {
    const MCOperand &MO = MI.getOperand(I);
    if (!MO.isImm())
      continue;
    const CCVOperandInfo *OI = nullptr;
    for (unsigned J = 0; J != CCVNumInstOperands; ++J) {
      if (Name != CCVInstOperandTable[J].Inst)
        continue;
      if (I < CCVInstOperandTable[J].NumOperands)
        OI = &CCVInstOperandTable[J].Operands[I];
      break;
    }
    if (!OI || OI->Bits == 0 || OI->Bits >= 64)
      continue;
    int64_t V = MO.getImm();
    bool Fits = OI->Signed ? isIntN(OI->Bits, V) : isUIntN(OI->Bits, uint64_t(V));
    if (!Fits)
      report_fatal_error(Twine("CCV: ") + Name + " operand " + Twine(I) +
                         " value " + Twine(V) + " does not fit its " +
                         Twine(OI->Bits) + "-bit field -- selecting this form "
                         "truncates it silently");
  }
}

void CCVMCCodeEmitter::encodeInstruction(const MCInst &MI,
                                         SmallVectorImpl<char> &CB,
                                         SmallVectorImpl<MCFixup> &Fixups,
                                         const MCSubtargetInfo &STI) const {
  verifyImmediatesFit(MI, MCII.getName(MI.getOpcode()));
  uint64_t Bits = getBinaryCodeForInstr(MI, Fixups, STI);
  unsigned Size = MCII.get(MI.getOpcode()).getSize();
  assert((Size == 2 || Size == 4 || Size == 6) &&
         "CCV instructions are 16, 32 or 48 bits (§2)");
  // 16-bit granular, little-endian halfwords.
  for (unsigned I = 0; I != Size; ++I)
    CB.push_back(static_cast<char>((Bits >> (8 * I)) & 0xff));
}

#include "CCVGenMCCodeEmitter.inc"

MCCodeEmitter *llvm::createCCVMCCodeEmitter(const MCInstrInfo &MCII,
                                            MCContext &Ctx) {
  return new CCVMCCodeEmitter(MCII, Ctx);
}
