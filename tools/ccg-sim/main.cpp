//===-- main.cpp - CCG functional simulator ------------------------------===//
//
// Executes one warp with independent per-thread PCs. Lanes are grouped for
// issue only where their PCs coincide; nothing forces convergence, and lanes
// that drift apart simply issue separately. That is the machine's actual
// divergence model (§1), not an approximation of a mask-stack one.
//
//===----------------------------------------------------------------------===//

#include "Interp.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;
using namespace ccg;

extern "C" void LLVMInitializeCCGTargetInfo();
extern "C" void LLVMInitializeCCGTargetMC();
extern "C" void LLVMInitializeCCGDisassembler();

static cl::opt<std::string> InputFile(cl::Positional, cl::Required,
                                      cl::desc("<kernel.bin>"));
static cl::opt<unsigned> NumThreads("threads", cl::init(32),
                                    cl::desc("active threads in the CTA"));
static cl::opt<unsigned> CtaId("ctaid", cl::init(0), cl::desc("CTA index"));
static cl::opt<uint64_t> CodeBase("code-base", cl::init(0x1000),
                                  cl::desc("load address for the kernel"));
static cl::opt<bool> Trace("trace", cl::desc("print each issue group"));
static cl::opt<unsigned> MaxSteps("max-steps", cl::init(100000),
                                  cl::desc("issue-group limit"));
static cl::list<std::string> Pokes("poke", cl::desc("addr=value, before run"),
                                   cl::value_desc("hex=hex"));
static cl::list<std::string> Peeks("peek", cl::desc("addr, after run"),
                                   cl::value_desc("hex"));

int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv, "CCG functional simulator\n");

  LLVMInitializeCCGTargetInfo();
  LLVMInitializeCCGTargetMC();
  LLVMInitializeCCGDisassembler();

  std::string Err;
  const Target *T = TargetRegistry::lookupTarget("ccg", Err);
  if (!T) { errs() << "error: " << Err << "\n"; return 1; }

  Triple TT("ccg-unknown-unknown");
  std::unique_ptr<const MCRegisterInfo> MRI(T->createMCRegInfo(TT.str()));
  MCTargetOptions Opts;
  std::unique_ptr<const MCAsmInfo> MAI(T->createMCAsmInfo(*MRI, TT.str(), Opts));
  std::unique_ptr<const MCInstrInfo> MII(T->createMCInstrInfo());
  std::unique_ptr<const MCSubtargetInfo> STI(
      T->createMCSubtargetInfo(TT.str(), "generic", ""));
  MCContext Ctx(TT, MAI.get(), MRI.get(), STI.get());
  std::unique_ptr<MCDisassembler> DisAsm(T->createMCDisassembler(*STI, Ctx));
  std::unique_ptr<MCInstPrinter> IP(T->createMCInstPrinter(TT, 0, *MAI, *MII, *MRI));

  auto Buf = MemoryBuffer::getFile(InputFile);
  if (!Buf) { errs() << "error: cannot read " << InputFile << "\n"; return 1; }
  StringRef Code = (*Buf)->getBuffer();

  Interp I;
  Warp W;
  W.CtaId = CtaId;
  for (unsigned L = 0; L != kLanes; ++L) {
    W.PC[L] = CodeBase;
    W.CtaTid[L] = L;                       // one warp, lane L is thread L
  }
  W.Active = NumThreads >= kLanes ? ~0u : ((1u << NumThreads) - 1);

  for (const auto &P : Pokes) {
    auto [A, V] = StringRef(P).split('=');
    uint64_t Addr; uint32_t Val;
    if (A.getAsInteger(0, Addr) || V.getAsInteger(0, Val)) {
      errs() << "error: bad -poke '" << P << "'\n"; return 1;
    }
    I.Mem.write32(Addr, Val);
  }

  unsigned Steps = 0, Issued = 0;
  while (W.Active && Steps++ < MaxSteps) {
    // Group by PC: pick the lowest PC among active lanes and issue for every
    // lane sitting there. Lowest-first is a scheduling policy, not semantics --
    // any order gives the same results.
    uint64_t Target = UINT64_MAX;
    for (unsigned L = 0; L != kLanes; ++L)
      if ((W.Active >> L) & 1)
        Target = std::min(Target, W.PC[L]);

    uint32_t Mask = 0;
    for (unsigned L = 0; L != kLanes; ++L)
      if (((W.Active >> L) & 1) && W.PC[L] == Target)
        Mask |= 1u << L;

    uint64_t Off = Target - CodeBase;
    if (Off >= Code.size()) {
      errs() << "error: PC " << format_hex(Target, 10) << " outside kernel\n";
      return 1;
    }
    ArrayRef<uint8_t> Bytes(reinterpret_cast<const uint8_t *>(Code.data()) + Off,
                            Code.size() - Off);

    MCInst MI;
    uint64_t Size = 0;
    if (DisAsm->getInstruction(MI, Size, Bytes, Target, nulls()) !=
        MCDisassembler::Success) {
      errs() << "error: cannot decode at " << format_hex(Target, 10) << "\n";
      return 1;
    }

    if (Trace) {
      std::string S; raw_string_ostream OS(S);
      IP->printInst(&MI, Target, "", *STI, OS);
      outs() << format("  %04x  mask=%08x  %s\n", unsigned(Off), Mask, OS.str().c_str());
    }

    auto R = I.step(W, MI, Mask, Target, unsigned(Size));
    ++Issued;

    switch (R.Kind) {
    case Interp::Result::Unimplemented:
      errs() << "error: " << MII->getName(MI.getOpcode())
             << " has no semantics in the simulator yet\n";
      return 1;
    case Interp::Result::Advance:
      for (unsigned L = 0; L != kLanes; ++L)
        if (Mask & (1u << L)) W.PC[L] += Size;
      break;
    case Interp::Result::Branch:
      for (unsigned L = 0; L != kLanes; ++L)
        if (Mask & (1u << L)) W.PC[L] = R.Target;
      break;
    case Interp::Result::BranchPred:
      // Lanes split here. No bracket, no mask stack -- they simply hold
      // different PCs from now on, and regroup if and when those coincide.
      for (unsigned L = 0; L != kLanes; ++L)
        if (Mask & (1u << L))
          W.PC[L] = (R.TakenMask & (1u << L)) ? R.Target : Target + Size;
      break;
    case Interp::Result::Exit:
      W.Active &= ~Mask;
      break;
    }
  }

  if (W.Active) {
    errs() << "error: step limit reached with lanes still active\n";
    return 1;
  }

  outs() << "  executed " << Issued << " issue groups\n";
  for (const auto &P : Peeks) {
    uint64_t Addr;
    if (StringRef(P).getAsInteger(0, Addr)) {
      errs() << "error: bad -peek '" << P << "'\n"; return 1;
    }
    outs() << format("  [%#llx] = %u\n", (unsigned long long)Addr, I.Mem.read32(Addr));
  }
  return 0;
}
