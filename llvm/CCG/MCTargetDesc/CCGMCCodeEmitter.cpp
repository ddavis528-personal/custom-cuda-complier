//===-- CCGMCCodeEmitter.cpp - CCG machine code emitter ------------------===//
//
// Instructions are 16, 32 or 48 bits (§2). The generated encoder returns the
// value; the size comes from MCInstrDesc, and bytes go out little-endian.
//
//===----------------------------------------------------------------------===//

#include "CCGFixupKinds.h"
#include "CCGMCTargetDesc.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/EndianStream.h"

using namespace llvm;

namespace {

class CCGMCCodeEmitter : public MCCodeEmitter {
  const MCInstrInfo &MCII;
  MCContext &Ctx;

public:
  CCGMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx)
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

private:
  unsigned branchOpValue(const MCInst &MI, unsigned OpNo,
                         SmallVectorImpl<MCFixup> &Fixups, unsigned Kind) const;
};

} // namespace

unsigned CCGMCCodeEmitter::getMachineOpValue(const MCInst &, const MCOperand &MO,
                                             SmallVectorImpl<MCFixup> &,
                                             const MCSubtargetInfo &) const {
  if (MO.isReg())
    return Ctx.getRegisterInfo()->getEncodingValue(MO.getReg());
  if (MO.isImm())
    return static_cast<unsigned>(MO.getImm());
  // Branch targets go through the per-operand encoders above, which create
  // fixups; anything else reaching here with an expression is a bug.
  llvm_unreachable("CCG: unhandled operand kind in getMachineOpValue");
}

/// A resolved target is encoded directly; an unresolved one becomes a fixup at
/// offset 0 of the instruction, so applyFixup sees the whole word and can
/// scatter a split field.
unsigned CCGMCCodeEmitter::branchOpValue(const MCInst &MI, unsigned OpNo,
                                         SmallVectorImpl<MCFixup> &Fixups,
                                         unsigned Kind) const {
  const MCOperand &MO = MI.getOperand(OpNo);
  if (MO.isImm())
    return unsigned(MO.getImm());
  assert(MO.isExpr() && "branch target must be an immediate or an expression");
  Fixups.push_back(MCFixup::create(0, MO.getExpr(), MCFixupKind(Kind)));
  return 0;
}

unsigned CCGMCCodeEmitter::getBranch21OpValue(const MCInst &MI, unsigned OpNo,
                                              SmallVectorImpl<MCFixup> &Fixups,
                                              const MCSubtargetInfo &) const {
  return branchOpValue(MI, OpNo, Fixups, CCG::fixup_ccg_bra21);
}

unsigned CCGMCCodeEmitter::getBranch18OpValue(const MCInst &MI, unsigned OpNo,
                                              SmallVectorImpl<MCFixup> &Fixups,
                                              const MCSubtargetInfo &) const {
  return branchOpValue(MI, OpNo, Fixups, CCG::fixup_ccg_brapred18);
}

void CCGMCCodeEmitter::encodeInstruction(const MCInst &MI,
                                         SmallVectorImpl<char> &CB,
                                         SmallVectorImpl<MCFixup> &Fixups,
                                         const MCSubtargetInfo &STI) const {
  uint64_t Bits = getBinaryCodeForInstr(MI, Fixups, STI);
  unsigned Size = MCII.get(MI.getOpcode()).getSize();
  assert((Size == 2 || Size == 4 || Size == 6) &&
         "CCG instructions are 16, 32 or 48 bits (§2)");
  // 16-bit granular, little-endian halfwords.
  for (unsigned I = 0; I != Size; ++I)
    CB.push_back(static_cast<char>((Bits >> (8 * I)) & 0xff));
}

#include "CCGGenMCCodeEmitter.inc"

MCCodeEmitter *llvm::createCCGMCCodeEmitter(const MCInstrInfo &MCII,
                                            MCContext &Ctx) {
  return new CCGMCCodeEmitter(MCII, Ctx);
}
