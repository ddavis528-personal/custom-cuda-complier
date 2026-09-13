//===-- CCGAsmBackend.cpp -------------------------------------------------===//
//
// Minimal: enough to emit an object file. No relaxation yet -- the 48-bit
// siblings of §3 are chosen at selection time rather than by relaxing a short
// form, and branch ranges (±2 MB for `bra`) have not yet bound on anything.
//
//===----------------------------------------------------------------------===//

#include "CCGFixupKinds.h"
#include "llvm/MC/MCInst.h"
#include "CCGMCTargetDesc.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCFixupKindInfo.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCValue.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

/// are 16-bit granular. LLVM computes a PC-relative fixup value relative to the
/// fixup location, which is the start of the instruction, so the instruction's
/// own size comes off before the halfword division.
static int64_t branchDisplacement(uint64_t Value, unsigned InstrSize) {
  return (int64_t(Value) - int64_t(InstrSize)) / 2;
}

namespace {

class CCGAsmBackend : public MCAsmBackend {
public:
  CCGAsmBackend() : MCAsmBackend(llvm::endianness::little) {}

  unsigned getNumFixupKinds() const override {
    return CCG::NumTargetFixupKinds;
  }

  const MCFixupKindInfo &getFixupKindInfo(MCFixupKind Kind) const override {
    // Offsets and widths here describe the *contiguous* case; bra.pred's field
    // is split and is scattered by hand in applyFixup, so its entry only has to
    // carry the PC-relative flag.
    static const MCFixupKindInfo Infos[CCG::NumTargetFixupKinds] = {
        // name                    offset  size  flags
        {"fixup_ccg_bra21",        11,     21,   MCFixupKindInfo::FKF_IsPCRel},
        {"fixup_ccg_brapred18",    0,      32,   MCFixupKindInfo::FKF_IsPCRel},
        {"fixup_ccg_call17",       15,     17,   MCFixupKindInfo::FKF_IsPCRel},
        {"fixup_ccg_bra8",          8,      8,   MCFixupKindInfo::FKF_IsPCRel},
    };
    if (Kind < FirstTargetFixupKind)
      return MCAsmBackend::getFixupKindInfo(Kind);
    return Infos[Kind - FirstTargetFixupKind];
  }

  void applyFixup(const MCAssembler &, const MCFixup &Fixup,
                  const MCValue &Target, MutableArrayRef<char> Data,
                  uint64_t Value, bool IsResolved,
                  const MCSubtargetInfo *) const override;

  /// §3 gives bra.short ±256 bytes. Whether a branch fits is a property of the
  /// final layout, not of the IR, so the selector emits the 16-bit form
  /// optimistically and this grows it when it turns out not to reach.
  bool mayNeedRelaxation(const MCInst &Inst, const MCSubtargetInfo &)
      const override {
    return Inst.getOpcode() == CCG::C_BRA;
  }

  bool fixupNeedsRelaxation(const MCFixup &Fixup, uint64_t Value,
                            const MCRelaxableFragment *,
                            const MCAsmLayout &) const override {
    if (Fixup.getKind() != CCG::fixup_ccg_bra8)
      return false;
    return !isInt<8>(branchDisplacement(Value, /*InstrSize=*/2));
  }

  void relaxInstruction(MCInst &Inst,
                        const MCSubtargetInfo &) const override {
    assert(Inst.getOpcode() == CCG::C_BRA && "nothing else relaxes");
    Inst.setOpcode(CCG::BRA);   // same single operand, 16 bits -> 32
  }

  bool writeNopData(raw_ostream &OS, uint64_t Count,
                    const MCSubtargetInfo *) const override {
    // Instruction length is 16-bit granular (§2), so padding is whole
    // halfwords. A zero halfword decodes as a 32-bit form, so pad with the
    // compressed encoding of a value that is at least well-formed.
    if (Count % 2 != 0)
      return false;
    for (uint64_t I = 0; I != Count; I += 2)
      OS.write("\x02\x00", 2); // class=10 (Format K), opcode 0
    return true;
  }
};

/// §3: branch offsets are measured from the instruction *after* the branch and

static void write32le(MutableArrayRef<char> Data, uint64_t Off, uint32_t V) {
  for (unsigned I = 0; I != 4; ++I)
    Data[Off + I] = char((V >> (8 * I)) & 0xff);
}
static uint32_t read32le(MutableArrayRef<char> Data, uint64_t Off) {
  uint32_t V = 0;
  for (unsigned I = 0; I != 4; ++I)
    V |= uint32_t(uint8_t(Data[Off + I])) << (8 * I);
  return V;
}

class CCGELFObjectWriter : public MCELFObjectTargetWriter {
public:
  CCGELFObjectWriter()
      : MCELFObjectTargetWriter(/*Is64Bit=*/true, /*OSABI=*/0,
                                ELF::EM_NONE, /*HasRelocationAddend=*/true) {}
  unsigned getRelocType(MCContext &, const MCValue &, const MCFixup &,
                        bool) const override {
    return 0;
  }
};

void CCGAsmBackend::applyFixup(const MCAssembler &, const MCFixup &Fixup,
                               const MCValue &, MutableArrayRef<char> Data,
                               uint64_t Value, bool IsResolved,
                               const MCSubtargetInfo *) const {
  if (!Value)
    return;
  const unsigned Kind = Fixup.getKind();
  const uint64_t Off = Fixup.getOffset();

  // bra.short is the one branch on a 16-bit instruction, so its displacement
  // is measured from a different instruction size and it patches a halfword.
  if (Kind == CCG::fixup_ccg_bra8) {
    const int64_t D8 = branchDisplacement(Value, /*InstrSize=*/2);
    if (!isInt<8>(D8))
      report_fatal_error("CCG: bra.short target out of range -- relaxation "
                         "should have grown this to Format E's bra");
    Data[Off + 1] = char(uint8_t(D8));      // payload is [15:8]
    return;
  }

  // Every other branch fixup in §3 sits on a 32-bit instruction.
  const int64_t D = branchDisplacement(Value, /*InstrSize=*/4);
  uint32_t Word = read32le(Data, Off);

  switch (Kind) {
  case CCG::fixup_ccg_bra21:
    if (!isInt<21>(D))
      report_fatal_error("CCG: bra target out of range (±2 MB, §3 Format E)");
    Word |= uint32_t(D & 0x1fffff) << 11;
    break;

  case CCG::fixup_ccg_brapred18: {
    // Split around the predicate qualifier, which stays at [29:27]: low 16
    // bits at [26:11], high 2 at [31:30]. Same technique as Format D′ (O-10).
    if (!isInt<18>(D))
      report_fatal_error("CCG: bra.pred target out of range (±256 KB, §3)");
    uint32_t U = uint32_t(D) & 0x3ffff;
    Word |= (U & 0xffff) << 11;
    Word |= ((U >> 16) & 0x3) << 30;
    break;
  }

  case CCG::fixup_ccg_call17:
    if (!isInt<17>(D))
      report_fatal_error("CCG: call target out of range (±128 KB, §3)");
    Word |= uint32_t(D & 0x1ffff) << 15;
    break;

  default:
    report_fatal_error("CCG: unknown fixup kind");
  }
  write32le(Data, Off, Word);
}

} // namespace

namespace {
class CCGAsmBackendWithWriter : public CCGAsmBackend {
public:
  std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override {
    return std::make_unique<CCGELFObjectWriter>();
  }
};
} // namespace

MCAsmBackend *llvm::createCCGAsmBackend(const Target &, const MCSubtargetInfo &,
                                        const MCRegisterInfo &,
                                        const MCTargetOptions &) {
  return new CCGAsmBackendWithWriter();
}
