//===-- CCGAsmBackend.cpp -------------------------------------------------===//
//
// Minimal: enough to emit an object file. No relaxation yet -- the 48-bit
// siblings of §3 are chosen at selection time rather than by relaxing a short
// form, and branch ranges (±2 MB for `bra`) have not yet bound on anything.
//
//===----------------------------------------------------------------------===//

#include "CCGMCTargetDesc.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCValue.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

namespace {

class CCGAsmBackend : public MCAsmBackend {
public:
  CCGAsmBackend() : MCAsmBackend(llvm::endianness::little) {}

  unsigned getNumFixupKinds() const override { return 1; }

  void applyFixup(const MCAssembler &, const MCFixup &, const MCValue &,
                  MutableArrayRef<char>, uint64_t, bool,
                  const MCSubtargetInfo *) const override {}

  bool fixupNeedsRelaxation(const MCFixup &, uint64_t,
                            const MCRelaxableFragment *,
                            const MCAsmLayout &) const override {
    return false;
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
