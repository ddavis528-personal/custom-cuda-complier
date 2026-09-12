//===-- CCGDisassembler.cpp - CCG disassembler ---------------------------===//
//
// Instruction length is decodable from bits [1:0] alone, before any format
// decode (§2). That property is what makes this function trivial, and it is
// worth noting that it holds: the length dispatch below never inspects the
// format tag.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "TargetInfo/CCGTargetInfo.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDecoderOps.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

using DecodeStatus = MCDisassembler::DecodeStatus;

namespace {
class CCGDisassembler : public MCDisassembler {
public:
  CCGDisassembler(const MCSubtargetInfo &STI, MCContext &Ctx)
      : MCDisassembler(STI, Ctx) {}

  DecodeStatus getInstruction(MCInst &MI, uint64_t &Size,
                              ArrayRef<uint8_t> Bytes, uint64_t Address,
                              raw_ostream &CStream) const override;
};
} // namespace

// §1: sixteen registers, settled (O-25). Every register field in the ISA is
// 4 bits, compressed forms included, so this table is exhaustive.
static const MCPhysReg GPRDecoderTable[] = {
    CCG::R0,  CCG::R1,  CCG::R2,  CCG::R3,  CCG::R4,  CCG::R5,
    CCG::R6,  CCG::R7,  CCG::R8,  CCG::R9,  CCG::R10, CCG::R11,
    CCG::R12, CCG::R13, CCG::R14, CCG::R15};

static const MCPhysReg PRDecoderTable[] = {CCG::P0, CCG::P1, CCG::P2, CCG::P3};

static DecodeStatus DecodeGPRRegisterClass(MCInst &MI, uint64_t RegNo,
                                           uint64_t, const MCDisassembler *) {
  if (RegNo >= std::size(GPRDecoderTable))
    return MCDisassembler::Fail;
  MI.addOperand(MCOperand::createReg(GPRDecoderTable[RegNo]));
  return MCDisassembler::Success;
}

static DecodeStatus DecodePRRegisterClass(MCInst &MI, uint64_t RegNo, uint64_t,
                                          const MCDisassembler *) {
  if (RegNo >= std::size(PRDecoderTable))
    return MCDisassembler::Fail;
  MI.addOperand(MCOperand::createReg(PRDecoderTable[RegNo]));
  return MCDisassembler::Success;
}

#include "CCGGenDisassemblerTables.inc"

DecodeStatus CCGDisassembler::getInstruction(MCInst &MI, uint64_t &Size,
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

static MCDisassembler *createCCGDisassembler(const Target &,
                                             const MCSubtargetInfo &STI,
                                             MCContext &Ctx) {
  return new CCGDisassembler(STI, Ctx);
}

extern "C" void LLVMInitializeCCGDisassembler() {
  TargetRegistry::RegisterMCDisassembler(getTheCCGTarget(),
                                         createCCGDisassembler);
}
