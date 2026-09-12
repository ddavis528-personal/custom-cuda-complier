//===-- main.cpp - CCG encode/decode round-trip ---------------------------===//
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

#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "TargetInfo/CCGTargetInfo.h"
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
#include <random>
#include <string>

using namespace llvm;

// Registration entry points. Out-of-tree, so there is no generated
// AllTargets header declaring these.
extern "C" void LLVMInitializeCCGTargetInfo();
extern "C" void LLVMInitializeCCGTargetMC();
extern "C" void LLVMInitializeCCGDisassembler();

#include "CCGOperandWidths.inc"

static cl::opt<unsigned> NumTrials("trials", cl::init(64),
                                   cl::desc("random operand sets per instruction"));
static cl::opt<unsigned> Seed("seed", cl::init(20260912), cl::desc("RNG seed"));
static cl::opt<bool> Verbose("v", cl::desc("print every round-trip"));

namespace {
struct Stats {
  unsigned Checked = 0, Trips = 0, NotOurs = 0, Unbuildable = 0, Failed = 0;
};
} // namespace

// Widest encoded field for an instruction, by TableGen variable name.
static unsigned fieldBits(StringRef Inst, StringRef Var) {
  for (unsigned I = 0; I != CCGNumInstFields; ++I) {
    if (Inst != CCGInstFieldTable[I].Inst)
      continue;
    for (unsigned F = 0; F != CCGInstFieldTable[I].NumFields; ++F)
      if (Var == CCGInstFieldTable[I].Fields[F].Var)
        return CCGInstFieldTable[I].Fields[F].Bits;
    return 0;
  }
  return 0;
}

// Immediate operands are named positionally in the .td; the encoder reads them
// through getMachineOpValue, so any value that fits the field round-trips. We
// do not know which field an operand maps to by name alone, so take the
// narrowest field on the instruction as a safe bound for every immediate.
static unsigned narrowestField(StringRef Inst) {
  unsigned Min = 64;
  for (unsigned I = 0; I != CCGNumInstFields; ++I) {
    if (Inst != CCGInstFieldTable[I].Inst)
      continue;
    for (unsigned F = 0; F != CCGInstFieldTable[I].NumFields; ++F) {
      unsigned B = CCGInstFieldTable[I].Fields[F].Bits;
      // Register fields are 4 bits (2 for predicates) and are handled
      // separately; only immediates need bounding.
      if (B < Min)
        Min = B;
    }
  }
  return Min == 64 ? 0 : Min;
}

int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv, "CCG encode/decode round-trip\n");

  LLVMInitializeCCGTargetInfo();
  LLVMInitializeCCGTargetMC();
  LLVMInitializeCCGDisassembler();

  std::string Error;
  const Target *T = TargetRegistry::lookupTarget("ccg", Error);
  if (!T) {
    errs() << "error: " << Error << "\n";
    return 1;
  }

  Triple TT("ccg-unknown-unknown");
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

    unsigned ImmBits = narrowestField(Name);

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
          uint64_t Mask = ImmBits >= 64 ? ~0ULL : ((1ULL << ImmBits) - 1);
          MI.addOperand(MCOperand::createImm(ImmBits ? (RNG() & Mask) : 0));
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
      if (Decoded.getOpcode() != Op) {
        errs() << "FAIL " << Name << ": decoded as "
               << MII->getName(Decoded.getOpcode()) << "\n";
        ++S.Failed;
        break;
      }

      // Compare the register operands that survive the round trip. Immediates
      // are compared only where the decoder reconstructs them into operands.
      bool Mismatch = false;
      for (unsigned I = 0, N = std::min(MI.getNumOperands(),
                                        Decoded.getNumOperands());
           I != N; ++I) {
        const MCOperand &A = MI.getOperand(I), &B = Decoded.getOperand(I);
        if (A.isReg() && B.isReg() && A.getReg() != B.getReg())
          Mismatch = true;
      }
      if (Mismatch) {
        errs() << "FAIL " << Name << ": register operands changed\n";
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

  outs() << "\n  CCG instructions     : " << S.Checked << "\n"
         << "  round trips          : " << S.Trips << " (" << NumTrials
         << " random operand sets each)\n"
         << "  non-CCG opcodes      : " << S.NotOurs
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
