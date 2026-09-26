//===-- CCVDisassembler.cpp - CCV disassembler ---------------------------===//
//
// Instruction length is decodable from bits [1:0] alone, before any format
// decode (§2). That property is what makes this function trivial, and it is
// worth noting that it holds: the length dispatch below never inspects the
// format tag.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "TargetInfo/CCVTargetInfo.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDecoderOps.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/MathExtras.h"

using namespace llvm;

using DecodeStatus = MCDisassembler::DecodeStatus;

namespace {
class CCVDisassembler : public MCDisassembler {
public:
  CCVDisassembler(const MCSubtargetInfo &STI, MCContext &Ctx)
      : MCDisassembler(STI, Ctx) {}

  DecodeStatus getInstruction(MCInst &MI, uint64_t &Size,
                              ArrayRef<uint8_t> Bytes, uint64_t Address,
                              raw_ostream &CStream) const override;
};
} // namespace

// §1: sixteen registers, settled (O-25). Every register field in the ISA is
// 4 bits, compressed forms included, so this table is exhaustive.
static const MCPhysReg GPRDecoderTable[] = {
    CCV::R0,  CCV::R1,  CCV::R2,  CCV::R3,  CCV::R4,  CCV::R5,
    CCV::R6,  CCV::R7,  CCV::R8,  CCV::R9,  CCV::R10, CCV::R11,
    CCV::R12, CCV::R13, CCV::R14, CCV::R15};

static const MCPhysReg PRDecoderTable[] = {CCV::P0, CCV::P1, CCV::P2, CCV::P3};

static DecodeStatus DecodeGPRRegisterClass(MCInst &MI, uint64_t RegNo,
                                           uint64_t, const MCDisassembler *) {
  if (RegNo >= std::size(GPRDecoderTable))
    return MCDisassembler::Fail;
  MI.addOperand(MCOperand::createReg(GPRDecoderTable[RegNo]));
  return MCDisassembler::Success;
}

/// GPR16 is the SAME sixteen registers viewed at 16-bit element width (§1), so
/// it decodes through the same table. There is no physical distinction to
/// recover -- the encoding carries no width, which is invariant 1, and the
/// width lives in `chwidth` state the disassembler cannot see.
static DecodeStatus DecodeGPR16RegisterClass(MCInst &MI, uint64_t RegNo,
                                             uint64_t A,
                                             const MCDisassembler *D) {
  return DecodeGPRRegisterClass(MI, RegNo, A, D);
}

static DecodeStatus DecodePRRegisterClass(MCInst &MI, uint64_t RegNo, uint64_t,
                                          const MCDisassembler *) {
  if (RegNo >= std::size(PRDecoderTable))
    return MCDisassembler::Fail;
  MI.addOperand(MCOperand::createReg(PRDecoderTable[RegNo]));
  return MCDisassembler::Success;
}

/// Sign-extend a field that the .td declares signed. Without this the generated
/// decoder zero-extends, which is invisible to a forward branch and to any
/// non-negative displacement -- and wrong for every other case. The round trip
/// could not catch it either: it encodes and decodes the same bit pattern, so
/// both sides agreed on a value that was simply not the one the assembler
/// meant. See F-39.
template <unsigned N>
static DecodeStatus decodeSImm(MCInst &MI, uint64_t Imm, int64_t,
                               const MCDisassembler *) {
  MI.addOperand(MCOperand::createImm(SignExtend64<N>(Imm)));
  return MCDisassembler::Success;
}

#include "CCVGenDisassemblerTables.inc"

DecodeStatus CCVDisassembler::getInstruction(MCInst &MI, uint64_t &Size,
                                             ArrayRef<uint8_t> Bytes,
                                             uint64_t Address,
                                             raw_ostream &) const {
  Size = 0;
  if (Bytes.size() < 2)
    return MCDisassembler::Fail;

  // §2: length from bits [1:0], inside the first halfword, in every case.
  switch (Bytes[0] & 0x3) {
  case 0x1: // compressed group 0 -- Format J
  case 0x2: // compressed group 1 -- Format K
    Size = 2;
    break;
  case 0x0: // 32-bit
    Size = 4;
    break;
  default: // 0x3 -- 48-bit
    Size = 6;
    break;
  }

  if (Bytes.size() < Size) {
    Size = 0;
    return MCDisassembler::Fail;
  }

  uint64_t Insn = 0;
  for (unsigned I = 0; I != Size; ++I)
    Insn |= static_cast<uint64_t>(Bytes[I]) << (8 * I);

  switch (Size) {
  case 2:
    return decodeInstruction(DecoderTable16, MI, static_cast<uint16_t>(Insn),
                             Address, this, STI);
  case 4:
    return decodeInstruction(DecoderTable32, MI, static_cast<uint32_t>(Insn),
                             Address, this, STI);
  default:
    return decodeInstruction(DecoderTable48, MI, Insn, Address, this, STI);
  }
}

static MCDisassembler *createCCVDisassembler(const Target &,
                                             const MCSubtargetInfo &STI,
                                             MCContext &Ctx) {
  return new CCVDisassembler(STI, Ctx);
}

extern "C" void LLVMInitializeCCVDisassembler() {
  TargetRegistry::RegisterMCDisassembler(getTheCCVTarget(),
                                         createCCVDisassembler);
}
