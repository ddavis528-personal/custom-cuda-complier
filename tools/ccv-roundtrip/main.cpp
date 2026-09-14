//===-- main.cpp - CCV encode/decode round-trip ---------------------------===//
//
// Step 1's exit criterion. For every instruction, build an MCInst with random
// operands that exactly fill their encoded fields, encode it, decode the bytes
// back, and require the result to match.
//
// The point is that the encoder and the disassembler are produced by *different*
// TableGen backends from the same description. If they disagree, the encoding is
// ambiguous or the tables are inconsistent -- neither of which is visible from
// reading the bit maps in §3.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "TargetInfo/CCVTargetInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/MathExtras.h"
#include <random>
#include <string>

using namespace llvm;

// Registration entry points. Out-of-tree, so there is no generated
// AllTargets header declaring these.
extern "C" void LLVMInitializeCCVTargetInfo();
extern "C" void LLVMInitializeCCVTargetMC();
extern "C" void LLVMInitializeCCVDisassembler();

#include "CCVOperandWidths.inc"

static cl::opt<unsigned> NumTrials("trials", cl::init(64),
                                   cl::desc("random operand sets per instruction"));
static cl::opt<unsigned> Seed("seed", cl::init(20260912), cl::desc("RNG seed"));
static cl::opt<bool> Verbose("v", cl::desc("print every round-trip"));

namespace {
struct Stats {
  unsigned Checked = 0, Trips = 0, NotOurs = 0, Unbuildable = 0, Failed = 0;
};
} // namespace

/// Per-operand encoding info, in MCInst operand order. Two things this replaces
/// were each hiding a class of bug:
///
///   - Every immediate used to be bounded by the NARROWEST field on the
///     instruction, which on a Format C compare is the 2-bit predicate
///     destination. Wide immediates were therefore only ever tested with tiny
///     values. Per-operand widths test each field at its real width.
///   - Signedness used to be unknown, so every generated value was
///     non-negative. That is how F-39 -- a decoder that zero-extended every
///     signed field -- ran green through three steps of work: a backward
///     branch and a negative displacement were never once encoded.
static const CCVOperandInfo *operandInfo(StringRef Inst, unsigned Idx) {
  for (unsigned I = 0; I != CCVNumInstOperands; ++I) {
    if (Inst != CCVInstOperandTable[I].Inst)
      continue;
    if (Idx >= CCVInstOperandTable[I].NumOperands)
      return nullptr;
    return &CCVInstOperandTable[I].Operands[Idx];
  }
  return nullptr;
}


int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv, "CCV encode/decode round-trip\n");

  LLVMInitializeCCVTargetInfo();
  LLVMInitializeCCVTargetMC();
  LLVMInitializeCCVDisassembler();

  std::string Error;
  const Target *T = TargetRegistry::lookupTarget("ccv", Error);
  if (!T) {
    errs() << "error: " << Error << "\n";
    return 1;
  }

  Triple TT("ccv-unknown-unknown");
  std::unique_ptr<const MCRegisterInfo> MRI(T->createMCRegInfo(TT.str()));
  MCTargetOptions Opts;
  std::unique_ptr<const MCAsmInfo> MAI(T->createMCAsmInfo(*MRI, TT.str(), Opts));
  std::unique_ptr<const MCInstrInfo> MII(T->createMCInstrInfo());
  std::unique_ptr<const MCSubtargetInfo> STI(
      T->createMCSubtargetInfo(TT.str(), "generic", ""));

  MCContext Ctx(TT, MAI.get(), MRI.get(), STI.get());
  std::unique_ptr<MCCodeEmitter> Emitter(T->createMCCodeEmitter(*MII, Ctx));
  std::unique_ptr<MCDisassembler> DisAsm(T->createMCDisassembler(*STI, Ctx));
  std::unique_ptr<MCInstPrinter> IP(
      T->createMCInstPrinter(TT, 0, *MAI, *MII, *MRI));

  if (!Emitter || !DisAsm || !IP) {
    errs() << "error: MC layer incomplete\n";
    return 1;
  }

  std::mt19937 RNG(Seed);
  Stats S;

  for (unsigned Op = 0, E = MII->getNumOpcodes(); Op != E; ++Op) {
    const MCInstrDesc &Desc = MII->get(Op);
    StringRef Name = MII->getName(Op);
    // LLVM's opcode space starts with the target-independent pseudos and the
    // ~250 GlobalISel generic opcodes, none of which have an encoding.
    if (Desc.getSize() == 0) {
      ++S.NotOurs;
      continue;
    }
    ++S.Checked;



    for (unsigned Trial = 0; Trial != NumTrials; ++Trial) {
      MCInst MI;
      MI.setOpcode(Op);

      bool Buildable = true;
      for (unsigned I = 0, N = Desc.getNumOperands(); I != N; ++I) {
        const MCOperandInfo &OI = Desc.operands()[I];

        // A tied operand is not free: Format J's accumulator and Format K's
        // destructive forms require rd == rs0 (§3), expressed in the .td as
        // "$rd = $rd_in". The encoder encodes the register once, so the two
        // operands must carry the same value or the round trip is comparing
        // against an MCInst the ISA does not permit.
        int Tied = Desc.getOperandConstraint(I, MCOI::TIED_TO);
        if (Tied >= 0) {
          MI.addOperand(MI.getOperand(Tied));
          continue;
        }

        if (OI.RegClass >= 0) {
          const MCRegisterClass &RC = MRI->getRegClass(OI.RegClass);
          if (RC.getNumRegs() == 0) {
            Buildable = false;
            break;
          }
          MI.addOperand(MCOperand::createReg(RC.getRegister(RNG() % RC.getNumRegs())));
        } else if (OI.OperandType == MCOI::OPERAND_IMMEDIATE ||
                   OI.OperandType == MCOI::OPERAND_UNKNOWN) {
          const CCVOperandInfo *OpI = operandInfo(Name, I);
          unsigned Bits = OpI ? OpI->Bits : 0;
          bool Signed = OpI && OpI->Signed;
          uint64_t Mask = Bits >= 64 ? ~0ULL : ((1ULL << Bits) - 1);
          uint64_t Raw = Bits ? (RNG() & Mask) : 0;
          // A signed field is generated across its own signed range, so half
          // the trials are negative -- the case a decoder can get wrong while
          // still agreeing with the encoder on every bit.
          int64_t V = (Signed && Bits && Bits < 64)
                          ? llvm::SignExtend64(Raw, Bits)
                          : int64_t(Raw);
          MI.addOperand(MCOperand::createImm(V));
        } else {
          Buildable = false;
          break;
        }
      }
      if (!Buildable) {
        ++S.Unbuildable;
        break;
      }

      SmallVector<char, 8> Code;
      SmallVector<MCFixup, 2> Fixups;
      Emitter->encodeInstruction(MI, Code, Fixups, *STI);

      if (Code.size() != Desc.getSize()) {
        errs() << "FAIL " << Name << ": emitted " << Code.size()
               << " bytes, MCInstrDesc says " << Desc.getSize() << "\n";
        ++S.Failed;
        break;
      }

      SmallVector<uint8_t, 8> Bytes(Code.begin(), Code.end());
      MCInst Decoded;
      uint64_t DecSize = 0;
      if (DisAsm->getInstruction(Decoded, DecSize, Bytes, 0, nulls()) !=
          MCDisassembler::Success) {
        errs() << "FAIL " << Name << ": encoded but did not decode\n";
        ++S.Failed;
        break;
      }
      if (DecSize != Code.size()) {
        errs() << "FAIL " << Name << ": decoded length " << DecSize
               << " != encoded " << Code.size() << "\n";
        ++S.Failed;
        break;
      }
      // A `_W16` variant is the SAME ENCODING as its 32-bit namesake -- §1's
      // invariant 1 says no instruction carries a width field, so `add` is
      // opcode 0 at any register width. The two differ only in a TSFlags bit
      // that exists to carry the width to CCVInsertChwidth (F-3) and is never
      // emitted. So the decoder producing the base form is correct, not a
      // round-trip failure; there is nothing in the bits to distinguish them
      // and nothing downstream of emission that needs to.
      StringRef DecName = MII->getName(Decoded.getOpcode());
      bool WidthAlias = Name.ends_with("_W16") &&
                        Name.drop_back(4) == DecName;
      if (Decoded.getOpcode() != Op && !WidthAlias) {
        errs() << "FAIL " << Name << ": decoded as " << DecName << "\n";
        ++S.Failed;
        break;
      }

      // Registers AND immediates. Comparing only registers left the entire
      // immediate path unchecked, which is the other half of why F-39 -- a
      // decoder that zero-extended every signed field -- ran green for three
      // steps of work.
      const char *Bad = nullptr;
      for (unsigned I = 0, N = std::min(MI.getNumOperands(),
                                        Decoded.getNumOperands());
           I != N; ++I) {
        const MCOperand &A = MI.getOperand(I), &B = Decoded.getOperand(I);
        if (A.isReg() && B.isReg() && A.getReg() != B.getReg())
          Bad = "register operands changed";
        else if (A.isImm() && B.isImm() && A.getImm() != B.getImm())
          Bad = "immediate operands changed";
      }
      if (Bad) {
        errs() << "FAIL " << Name << ": " << Bad << "\n";
        ++S.Failed;
        break;
      }

      if (Verbose && Trial == 0) {
        std::string Str;
        raw_string_ostream OS(Str);
        IP->printInst(&Decoded, 0, "", *STI, OS);
        outs() << format("  %-16s %u bytes  %s\n", Name.str().c_str(),
                         (unsigned)Code.size(), OS.str().c_str());
      }
      ++S.Trips;
    }
  }

  outs() << "\n  CCV instructions     : " << S.Checked << "\n"
         << "  round trips          : " << S.Trips << " (" << NumTrials
         << " random operand sets each)\n"
         << "  non-CCV opcodes      : " << S.NotOurs
         << " (LLVM pseudos and GlobalISel generics, no encoding)\n"
         << "  unbuildable operands : " << S.Unbuildable << "\n"
         << "  failures             : " << S.Failed << "\n\n";
  if (S.Failed) {
    outs() << "  ROUND-TRIP FAILED\n";
    return 1;
  }
  outs() << "  all round trips clean\n";
  return 0;
}
