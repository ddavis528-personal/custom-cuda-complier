//===-- main.cpp - CCV functional simulator ------------------------------===//
//
// Executes one warp with independent per-thread PCs. Lanes are grouped for
// issue only where their PCs coincide; nothing forces convergence, and lanes
// that drift apart simply issue separately. That is the machine's actual
// divergence model (§1), not an approximation of a mask-stack one.
//
//===----------------------------------------------------------------------===//

#include "Interp.h"
#include "NarrowFP.h"
#include "SfuMath.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
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
#include "llvm/Support/Endian.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/bit.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/MC/MCInstrDesc.h"
#include <algorithm>

using namespace llvm;
using namespace ccv;

extern "C" void LLVMInitializeCCVTargetInfo();
extern "C" void LLVMInitializeCCVTargetMC();
extern "C" void LLVMInitializeCCVDisassembler();

static cl::opt<std::string> InputFile(cl::Positional, cl::Required,
                                      cl::desc("<kernel.bin>"));
// CP-6: evaluate FP operations from a case file instead of running a kernel.
// Each line is `OPCODE wd wa wb wc x y z` (width codes, then operand bits in
// hex); each output line is the result in hex, or F-FORMAT.
static cl::opt<std::string> FpCases("fp-cases", cl::Hidden,
                                    cl::desc("evaluate FP cases from a file (CP-6)"));
static cl::opt<bool> TestFpFtz("ccv-test-fp-ftz", cl::Hidden,
    cl::desc("flush subnormal FP results to zero, to test that it is caught"));
static cl::opt<bool> TestFpNoSat("ccv-test-fp-no-saturate", cl::Hidden,
    cl::desc("narrow FP overflow gives NaN, to test that it is caught"));
// TI-35: the hardware warp context srd #2 (%lanectx) reports (O-64). The core
// gives each resident warp its own, so one run standing for one warp of a
// multi-CTA launch takes the context that warp will have. The value is only a
// name (§12.1's bounded nondeterminism). Default: the -warp index.
static cl::opt<int> LaneContext("context", cl::init(-1),
    cl::desc("hardware warp context for srd #2 (default: the -warp index)"));
static cl::opt<bool> TestMixedByValue("ccv-test-mixed-by-value", cl::Hidden,
    cl::desc("read integer sources at their own width, to test that it is caught"));
static cl::opt<unsigned> SfuErrorUlps("sfu-error-ulps", cl::init(0),
    cl::desc("return FP SFU values up to N units from the exact result, as an "
             "approximate SFU may: an ulp, or O-70's absolute unit for lg2 near "
             "1 and sin/cos on [-pi, pi]; N = 2 is O-70's bound (SfuMath.h)"));
static cl::opt<unsigned> LaneContexts("lane-contexts", cl::init(4096),
    cl::desc("CCV_LANE_CONTEXTS: where O-69's spill space starts (default the "
             "core's params, the device's %lanectx range: 2^(CCV_P_W_DEV_CORE "
             "+ CCV_W_WARP_ID + 5))"));
static cl::opt<bool> TestFAddDescending("ccv-test-atomic-fadd-descending",
    cl::Hidden, cl::desc("apply atom.add.f32's lanes in descending order, to "
                         "test that the order is observed (O-76)"));
static cl::opt<bool> TestAddrFull(
    "ccv-test-address-full-width", cl::Hidden,
    cl::desc("read a narrow address or return register at all 32 bits, as O-39 "
             "did, rather than its element (O-79)"));
static cl::opt<bool> TestAtomNoIndex("ccv-test-atomic-no-index", cl::Hidden,
    cl::desc("address atomics without their index register, as before O-72, "
             "to test that it is caught"));
static cl::opt<bool> TestSfuTruncate("ccv-test-sfu-truncate", cl::Hidden,
    cl::desc("truncate the FP SFU's values instead of rounding them, to test "
             "that it is caught"));
static cl::opt<bool> TestFpHostNaN("ccv-test-fp-host-nan", cl::Hidden,
    cl::desc("FP32 NaN results keep the host's bits, to test that it is caught"));
static cl::opt<unsigned> NumThreads("threads", cl::init(32),
                                    cl::desc("active threads in the CTA"));
static cl::opt<unsigned> CtaId("ctaid", cl::init(0), cl::desc("CTA index"));
// TI-29: one warp of a CTA of several. Lane L is thread 32w + L, so srd's
// %ctatid gives it, and the warp's lanes are [0, min(32, T - 32w)). A CTA's
// warps share .shared and barriers, which a run of one warp cannot model, so
// this is for warps that do not communicate, and a barrier in a CTA of more
// than 32 threads stops the run.
static cl::opt<unsigned> WarpInCta("warp", cl::init(0),
                                   cl::desc("which warp of the CTA to run (TI-29)"));
// TI-29: or every warp of the CTA, sharing memory, .shared and the barriers,
// for a kernel whose warps communicate. They issue in turn, one issue group
// each, warp 0 first; a warp with nothing runnable is passed over. Warp w is
// hardware context -context + w. A barrier completes once every live lane of
// every warp has arrived. -oracle then writes one record file per warp
// (CP-30).
static cl::opt<bool> WholeCta(
    "cta", cl::desc("run every warp of the CTA, with shared barriers (TI-29)"));
static cl::opt<bool> TestWarpBarrier("ccv-test-cta-warp-barrier", cl::Hidden,
    cl::desc("with -cta, a barrier waits for its own warp only, to test that "
             "it is caught"));
static cl::opt<bool> NoopWidthPCs("noop-width-pcs", cl::Hidden,
    cl::desc("with -counters, list the PCs of chwidths that set a register to "
             "the width it already had (TI-45)"));
static cl::opt<bool> TestIgnoreCount("ccv-test-bar-ignore-count", cl::Hidden,
    cl::desc("make bar.init a no-op, as before O-74, to test that it is "
             "caught"));
static cl::opt<uint64_t> CodeBase("code-base", cl::init(0x1000),
                                  cl::desc("load address for the kernel"));
static cl::opt<uint64_t> Entry(
    "entry", cl::init(0),
    cl::desc("the kernel's offset in the image: device functions come before "
             "it once calls exist (F-21)"));
static cl::opt<unsigned> Barriers(
    "barriers", cl::init(16),
    cl::desc("barriers the CTA has allocated, at most 16 (ISA v1.9 O-59)"));
// O-60 (ISA v1.9 §1, IS-17): every diverged group of a live warp that is not
// waiting at a barrier eventually issues. Strict lowest-PC-first does not
// meet that -- a lane spinning at a low PC on a flag a higher-PC lane sets
// starves the setter forever (test/cuda/spinwait.cu) -- so the oracle needs a
// fairness rule. It is FET's (AR's IS-17 rows, revs 119 to 121; FET spec rev
// 15), because a kernel whose lanes talk to each other has more than one
// legal order and the oracle must be the one the hardware takes: min-PC,
// except that once the group holding lane r has gone N picks without
// issuing, the next pick is that group. r is a rotating pointer; whenever
// its group issues, by either path, the count restarts and r moves to the
// next live lane. Lanes waiting at a barrier are skipped. N is FET's
// CCV_FAIR_N and must stay equal to it; N = 0 is strict min-PC, kept as the
// spin-wait kernel's hanging control.
static cl::opt<unsigned> Fairness(
    "fairness", cl::init(48),
    cl::desc("picks lane r's group may go without issuing before it is "
             "issued (O-60, FET's CCV_FAIR_N); 0 = strict lowest-PC-first"));
static cl::opt<bool> Trace("trace", cl::desc("print each issue group"));
static cl::opt<bool> Stats("counters", cl::desc("print execution counters"));
static cl::opt<unsigned> MaxSteps("max-steps", cl::init(100000),
                                  cl::desc("issue-group limit"));
// O-61: a module's data image, loaded at -data-window << 16 with its data
// pointers relocated, and the window written to launch-block word 28. It
// becomes pokes ahead of -poke's, so the oracle's initial memory has it and a
// -poke can still override any word.
static cl::opt<std::string> DataImage(
    "data", cl::desc("the module's data image (.ccv_data), O-61"),
    cl::value_desc("file"));
static cl::opt<std::string> DataReloc(
    "data-reloc", cl::desc("its relocation list (.ccv_reloc): u32 image "
                           "offsets of 8-byte data-pointer slots"),
    cl::value_desc("file"));
static cl::opt<unsigned> DataWindow("data-window", cl::init(0x200),
                                    cl::desc("the window the image is loaded at"));
static cl::opt<std::string> DataInfo(
    "data-info", cl::desc("the image's .ccv_info: u32 size of its constant "
                          "part, which becomes the .const range (O-61)"),
    cl::value_desc("file"));
// F-RO's .const range for a kernel not built with -data: [base, limit),
// flat addresses. The launch window, 2, is always read-only.
static cl::opt<std::string> ConstRange(
    "const-range", cl::desc("the .const range, base:limit (F-RO, O-51)"),
    cl::value_desc("base:limit"));
static cl::list<std::string> Pokes("poke", cl::desc("addr=value, before run"),
                                   cl::value_desc("hex=hex"));
static cl::list<std::string> Peeks("peek", cl::desc("addr, after run"),
                                   cl::value_desc("hex"));
static cl::opt<std::string> OracleFile(
    "oracle", cl::desc("write a per-issue-group oracle record (JSON lines) "
                       "for the CCV core's Stage 3 skeleton"),
    cl::value_desc("file"));

/// Operations that read and write only the predicate file. A predicate is 32
/// bits, one per lane (invariant 5), so these are narrow bitwise ops rather
/// than 32 lanes of ALU -- they belong in their own counter, not in
/// `lane-activations`, whose definition is GPR lanes that toggled. Compares are
/// NOT here: they read GPRs.
static bool isPredicateFileOp(unsigned Op) {
  switch (Op) {
  case CCV::PAND: case CCV::POR: case CCV::PXOR: case CCV::PMOV_IMM:
    return true;
  default:
    return false;
  }
}

// ---- oracle records (-oracle) ---------------------------------------------
//
// The CCV core's Stage 3 skeleton is a timing model that asks this simulator
// WHAT each instruction does and owns WHEN (strategy §1). It consumes one
// record per issue group: the bytes, the lane mask, every register operand's
// value before the step, every register written and its value after, and each
// memory access attributed to its lane. The skeleton routes those values
// through its channels and checks them at every consumer, so the record has to
// be exact -- which is why an access that cannot be attributed to a lane stops
// the run rather than being approximated.
static void jsonU32s(std::FILE *F, const uint32_t *V, unsigned N) {
  std::fputc('[', F);
  for (unsigned I = 0; I != N; ++I)
    std::fprintf(F, I ? ",%u" : "%u", V[I]);
  std::fputc(']', F);
}

int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv, "CCV functional simulator\n");

  LLVMInitializeCCVTargetInfo();
  LLVMInitializeCCVTargetMC();
  LLVMInitializeCCVDisassembler();

  std::string Err;
  const Target *T = TargetRegistry::lookupTarget("ccv", Err);
  if (!T) { errs() << "error: " << Err << "\n"; return 1; }

  Triple TT("ccv-unknown-unknown");
  std::unique_ptr<const MCRegisterInfo> MRI(T->createMCRegInfo(TT.str()));
  MCTargetOptions Opts;
  std::unique_ptr<const MCAsmInfo> MAI(T->createMCAsmInfo(*MRI, TT.str(), Opts));
  std::unique_ptr<const MCInstrInfo> MII(T->createMCInstrInfo());
  nfp::TestFtz = TestFpFtz;
  nfp::TestNoSaturate = TestFpNoSat;
  nfp::TestHostNaN = TestFpHostNaN;
  sfu::TestTruncate = TestSfuTruncate;
  nfp::TestAtomNoIndex = TestAtomNoIndex;
  nfp::TestAddrFull = TestAddrFull;
  nfp::TestFAddDescending = TestFAddDescending;
  nfp::SfuErrorUlps = SfuErrorUlps;
  nfp::TestByValue = TestMixedByValue;
  if (!FpCases.empty()) {
    StringMap<unsigned> ByName;
    for (unsigned Op = 0, N = MII->getNumOpcodes(); Op != N; ++Op)
      ByName[MII->getName(Op)] = Op;
    auto Buf = MemoryBuffer::getFile(FpCases);
    if (!Buf) { errs() << "error: cannot read " << FpCases << "\n"; return 1; }
    SmallVector<StringRef, 0> Lines;
    (*Buf)->getBuffer().split(Lines, '\n', -1, false);
    for (StringRef Line : Lines) {
      SmallVector<StringRef, 8> F;
      Line.split(F, ' ', -1, false);
      if (F.size() != 8 || !ByName.count(F[0])) {
        errs() << "error: bad case: " << Line << "\n";
        return 1;
      }
      uint8_t W[4];
      uint32_t V[3];
      for (int K = 0; K != 4; ++K) W[K] = uint8_t(std::stoul(F[1 + K].str()));
      for (int K = 0; K != 3; ++K) V[K] = uint32_t(std::stoul(F[5 + K].str(), nullptr, 16));
      uint32_t Out;
      if (Interp::evalFp(ByName[F[0]], W, V[0], V[1], V[2], Out))
        outs() << format("%x\n", Out);
      else
        outs() << "F-FORMAT\n";
    }
    return 0;
  }
  std::unique_ptr<const MCSubtargetInfo> STI(
      T->createMCSubtargetInfo(TT.str(), "generic", ""));
  MCContext Ctx(TT, MAI.get(), MRI.get(), STI.get());
  std::unique_ptr<MCDisassembler> DisAsm(T->createMCDisassembler(*STI, Ctx));
  std::unique_ptr<MCInstPrinter> IP(T->createMCInstPrinter(TT, 0, *MAI, *MII, *MRI));

  auto Buf = MemoryBuffer::getFile(InputFile);
  if (!Buf) { errs() << "error: cannot read " << InputFile << "\n"; return 1; }
  StringRef Code = (*Buf)->getBuffer();

  Interp I;
  I.BarrierCount = std::min(unsigned(Barriers), 16u);
  I.LaneContexts = LaneContexts;
  I.Mem.AddrLimit = 1ull << 48;            // F-ADDR (O-75); .shared has none
  if (WholeCta && WarpInCta) {
    errs() << "error: -cta runs every warp; -warp names one\n";
    return 1;
  }
  if (uint64_t(kLanes) * WarpInCta >= NumThreads) {
    errs() << "error: -warp=" << WarpInCta << " has no threads in a CTA of "
           << NumThreads << "\n";
    return 1;
  }
  // The warps this run executes: all of the CTA's with -cta, else -warp's.
  const unsigned NumWarps = WholeCta ? (NumThreads + kLanes - 1) / kLanes : 1;
  std::vector<Warp> Warps(NumWarps);
  for (unsigned K = 0; K != NumWarps; ++K) {
    Warp &X = Warps[K];
    const unsigned WI = WarpInCta + K;     // the warp's index in its CTA
    X.CtaId = CtaId;
    // -context names warp 0's (one warp's without -cta); else warp w's is w.
    X.WarpCtx = LaneContext >= 0 ? unsigned(LaneContext) + K : WI;
    if (X.WarpCtx >= (1u << 27)) {
      errs() << "error: -context=" << X.WarpCtx << " does not fit srd #2's "
             << "(context << 5) | lane\n";
      return 1;
    }
    for (unsigned L = 0; L != kLanes; ++L) {
      X.PC[L] = CodeBase + Entry;
      X.CtaTid[L] = kLanes * WI + L;       // warp w, lane L is thread 32w + L
    }
    const unsigned WarpThreads = std::min(kLanes, NumThreads - kLanes * WI);
    X.Active = WarpThreads >= kLanes ? ~0u : ((1u << WarpThreads) - 1);
  }
  if (WholeCta)
    I.Cta = &Warps;
  I.TestWarpBarrier = TestWarpBarrier;
  I.TestIgnoreCount = TestIgnoreCount;
  std::map<uint64_t, uint64_t> NoopPCs;
  if (NoopWidthPCs)
    I.NoopWidthPCs = &NoopPCs;

  std::vector<std::string> AllPokes;
  if (!DataImage.empty()) {
    auto Img = MemoryBuffer::getFile(DataImage);
    if (!Img) { errs() << "error: cannot read " << DataImage << "\n"; return 1; }
    std::vector<uint8_t> D((*Img)->getBufferStart(), (*Img)->getBufferEnd());
    D.resize((D.size() + 3) & ~size_t(3), 0);
    const uint64_t Base = uint64_t(DataWindow) << 16;
    if (!DataReloc.empty()) {
      auto R = MemoryBuffer::getFile(DataReloc);
      if (!R) { errs() << "error: cannot read " << DataReloc << "\n"; return 1; }
      StringRef RB = (*R)->getBuffer();
      for (size_t I = 0; I + 4 <= RB.size(); I += 4) {
        uint32_t Off = support::endian::read32le(RB.data() + I);
        if (Off + 8 > D.size()) { errs() << "error: relocation past the image\n"; return 1; }
        uint64_t V = support::endian::read64le(&D[Off]) + Base;
        support::endian::write64le(&D[Off], V);
      }
    }
    for (size_t I = 0; I != D.size(); I += 4)
      AllPokes.push_back(utostr(Base + I) + "=" +
                         utostr(support::endian::read32le(&D[I])));
    AllPokes.push_back(utostr(launchBlockBase() + 28) + "=" + utostr(DataWindow));
  }
  AllPokes.insert(AllPokes.end(), Pokes.begin(), Pokes.end());

  // F-RO's .const range: the image's constant part, or -const-range.
  if (!DataInfo.empty()) {
    auto Info = MemoryBuffer::getFile(DataInfo);
    if (!Info || (*Info)->getBufferSize() < 4) {
      errs() << "error: cannot read " << DataInfo << "\n"; return 1;
    }
    I.Mem.ConstBase = uint64_t(DataWindow) << 16;
    I.Mem.ConstLimit =
        I.Mem.ConstBase + support::endian::read32le((*Info)->getBufferStart());
  }
  if (!ConstRange.empty()) {
    auto [B, L] = StringRef(ConstRange).split(':');
    if (B.getAsInteger(0, I.Mem.ConstBase) || L.getAsInteger(0, I.Mem.ConstLimit)) {
      errs() << "error: bad -const-range '" << ConstRange << "'\n"; return 1;
    }
  }

  for (const auto &P : AllPokes) {
    auto [A, V] = StringRef(P).split('=');
    uint64_t Addr; uint32_t Val;
    if (A.getAsInteger(0, Addr) || V.getAsInteger(0, Val)) {
      errs() << "error: bad -poke '" << P << "'\n"; return 1;
    }
    I.Mem.write32(Addr, Val);
  }

  // One record file per warp (CP-30): -oracle's for warp 0, and with -cta
  // oracle.<w>.jsonl beside it for warp w, as the skeleton's loader reads a
  // CTA. Each is that warp's records alone, in its issue order; the files
  // share the init, and the final memory, which is the CTA's.
  std::vector<std::FILE *> OFs(NumWarps, nullptr);
  std::FILE *OF = nullptr;                     // the issuing warp's
  std::vector<Memory::Access> MemLog, ShLog;
  std::vector<uint64_t> Touched;               // every address an access saw
  if (!OracleFile.empty()) for (unsigned K = 0; K != NumWarps; ++K) {
    std::string Path = OracleFile;
    if (K) {
      StringRef Stem(OracleFile);
      Path = Stem.consume_back(".jsonl") ? (Stem + "." + Twine(K) + ".jsonl").str()
                                          : OracleFile + "." + utostr(K);
    }
    OF = OFs[K] = std::fopen(Path.c_str(), "w");
    if (!OF) { errs() << "error: cannot write " << Path << "\n"; return 1; }
    const unsigned WI = WarpInCta + K;
    std::fprintf(OF, "{\"init\":{\"code_base\":%llu,\"threads\":%u,"
                     "\"ctaid\":%u,",
                 (unsigned long long)CodeBase, unsigned(NumThreads),
                 unsigned(CtaId));
    // The warp's index in its CTA, when it is not the first (TI-29). Absent,
    // it is 0, so a one-warp record is exactly what it was.
    if (WI)
      std::fprintf(OF, "\"warp_in_cta\":%u,", WI);
    // The warp's hardware context, when it is not its index (TI-35).
    if (Warps[K].WarpCtx != WI)
      std::fprintf(OF, "\"lane_context\":%u,", unsigned(Warps[K].WarpCtx));
    // F-RO's .const range, when there is one, for MIU's const_base and
    // const_limit (TI-26). Absent, the range is empty.
    if (I.Mem.ConstLimit > I.Mem.ConstBase)
      std::fprintf(OF, "\"const\":[%llu,%llu],",
                   (unsigned long long)I.Mem.ConstBase,
                   (unsigned long long)I.Mem.ConstLimit);
    std::fprintf(OF, "\"code\":\"");
    for (unsigned char Ch : Code) std::fprintf(OF, "%02x", Ch);
    std::fprintf(OF, "\",\"mem\":[");
    bool First = true;
    for (const auto &P : AllPokes) {
      auto [A, V] = StringRef(P).split('=');
      uint64_t Addr; uint32_t Val;
      A.getAsInteger(0, Addr); V.getAsInteger(0, Val);
      std::fprintf(OF, First ? "[%llu,%u]" : ",[%llu,%u]",
                   (unsigned long long)Addr, Val);
      First = false;
      if (!K)
        Touched.push_back(Addr);
    }
    std::fprintf(OF, "]}}\n");
    I.Mem.Log = &MemLog;
    I.Shared.Log = &ShLog;
  }

  std::vector<Memory::Undo> Journal, ShJournal;
  I.Mem.Journal = &Journal;
  I.Shared.Journal = &ShJournal;

  // A V1 fault terminates the context (ISA v1.9 §12.6). The record carries
  // the cause, the PC, the lane mask, and for an execute-stage memory fault
  // the lowest faulting lane's address; it is printed, written to the oracle
  // file, and the run exits with status 3 -- distinct from 1, a simulator
  // error, so a check can tell a fault the ISA defines from a tool failure.
  // Peeks still print: the state is the faulting instruction's predecessors',
  // which is what precision (§12.4) promises.
  unsigned Steps = 0, Issued = 0;
  std::vector<unsigned> IssuedBy(NumWarps, 0);   // per warp, for its record

  // Final architectural state: every GPR lane, every predicate, and every
  // global word any access or poke touched -- what the skeleton's retired
  // state is compared against. After a fault it is the state the rollback
  // left, which is what precision (§12.4) promises (TI-28).
  // Each warp's file gets its own registers and the CTA's memory.
  auto emitFinal = [&](unsigned K) {
    std::FILE *OF = OFs[K];
    I.Mem.Log = nullptr;
    I.Shared.Log = nullptr;
    std::fprintf(OF, "{\"final\":{\"gpr\":[");
    for (unsigned G = 0; G != kGPRs; ++G) {
      if (G) std::fputc(',', OF);
      jsonU32s(OF, Warps[K].GPR[G].data(), kLanes);
    }
    std::fprintf(OF, "],\"pred\":");
    jsonU32s(OF, Warps[K].Pred.data(), kPreds);
    std::sort(Touched.begin(), Touched.end());
    std::fprintf(OF, ",\"mem\":[");
    uint64_t LastWord = UINT64_MAX;
    bool First = true;
    for (uint64_t A : Touched) {
      uint64_t Wd = A & ~uint64_t(3);
      if (Wd == LastWord) continue;
      LastWord = Wd;
      uint32_t V = 0;
      for (unsigned B = 0; B != 4; ++B)
        V |= uint32_t(I.Mem.peekByte(Wd + B)) << (8 * B);
      std::fprintf(OF, First ? "[%llu,%u]" : ",[%llu,%u]",
                   (unsigned long long)Wd, V);
      First = false;
    }
    std::fprintf(OF, "],\"issue_groups\":%u}}\n", IssuedBy[K]);
  };
  auto emitFinals = [&] {
    for (unsigned K = 0; K != NumWarps; ++K) {
      emitFinal(K);
      std::fclose(OFs[K]);
    }
  };

  // The warp issuing, an index into Warps: always 0 without -cta.
  unsigned Cur = NumWarps - 1;
  auto fault = [&](const char *Cause, uint64_t PC, uint32_t Lanes,
                   uint64_t Addr) {
    outs() << format("  FAULT %s  pc=%#llx  lanes=%08x  addr=%#llx  cta=%u warp=%u\n",
                     Cause, (unsigned long long)PC, Lanes,
                     (unsigned long long)Addr, unsigned(CtaId),
                     unsigned(WholeCta ? Cur : 0));
    if (OF) {
      // In the faulting warp's file; a fault ends the run, so every file
      // then gets its final state.
      std::fprintf(OFs[Cur], "{\"fault\":{\"cause\":\"%s\",\"pc\":%llu,\"lanes\":%u,"
                             "\"addr\":%llu,\"cta\":%u,\"warp\":0}}\n",
                   Cause, (unsigned long long)PC, Lanes,
                   (unsigned long long)Addr, unsigned(CtaId));
      emitFinals();
    }
    I.Mem.Log = nullptr;
    for (const auto &P : Peeks) {
      uint64_t A;
      if (!StringRef(P).getAsInteger(0, A))
        outs() << format("  [%#llx] = %u\n", (unsigned long long)A, I.Mem.read32(A));
    }
    return 3;
  };
  std::vector<uint64_t> Seqs(NumWarps, 0);     // each file's own sequence

  Counters C;

  // O-60 fairness state, FET's, per warp: picks since lane r's group last
  // issued, and the rotating lane pointer r.
  std::vector<std::pair<unsigned, unsigned>> Fair(NumWarps);
  auto live = [&] {
    return std::any_of(Warps.begin(), Warps.end(),
                       [](const Warp &X) { return X.Active != 0; });
  };
  while (live() && Steps++ < MaxSteps) {
    // The next warp in turn with a runnable lane (TI-29). Without -cta there
    // is one, and it is always the one.
    for (unsigned K = 0; K != NumWarps; ++K) {
      Cur = (Cur + 1) % NumWarps;
      if (Warps[Cur].Active & ~Warps[Cur].Stalled)
        break;
    }
    Warp &W = Warps[Cur];
    if (OF)
      OF = OFs[Cur];
    auto &[Picks, FairLane] = Fair[Cur];
    // Group by PC: pick the lowest PC among active lanes and issue for every
    // lane sitting there. Lowest-first is a scheduling policy, not semantics:
    // for code whose lanes do not communicate, any order gives the same
    // results. A spin-wait or an intra-warp lock has several legal outcomes,
    // in issue count at least, and this order is FET's.
    uint32_t Runnable = W.Active & ~W.Stalled;
    if (!Runnable) {
      // Every remaining lane is blocked at a barrier that no one can now
      // complete. Report it as what it is rather than running to the step
      // limit: a deadlocked kernel and a slow one look nothing alike.
      unsigned Blocked = 0;
      for (const Warp &X : Warps)
        Blocked += llvm::popcount(X.Active);
      errs() << "error: deadlock -- " << Blocked
             << " lanes blocked at a barrier with no lane able to arrive\n";
      return 1;
    }

    uint64_t Target = UINT64_MAX;
    for (unsigned L = 0; L != kLanes; ++L)
      if ((Runnable >> L) & 1)
        Target = std::min(Target, W.PC[L]);

    // O-60's fairness: lane r is the first runnable lane at or after the
    // pointer. Its group's issue restarts the count and moves the pointer on;
    // at N picks without one, this pick is its group.
    if (Fairness) {
      unsigned R = FairLane;
      while (!((Runnable >> R) & 1))
        R = (R + 1) % kLanes;
      bool Served = W.PC[R] == Target;
      if (!Served && ++Picks == Fairness) {
        ++C.FairPicks;
        Target = W.PC[R];
        Served = true;
      }
      if (Served) {
        Picks = 0;
        FairLane = (R + 1) % kLanes;
        while (!((W.Active >> FairLane) & 1))
          FairLane = (FairLane + 1) % kLanes;
      }
    }

    uint32_t Mask = 0;
    for (unsigned L = 0; L != kLanes; ++L)
      if (((Runnable >> L) & 1) && W.PC[L] == Target)
        Mask |= 1u << L;

    // F-FETCH (ISA v1.9 §12.3): the selected PC outside the kernel's image,
    // or not 16-bit aligned -- a ret to an odd offset among them.
    uint64_t Off = Target - CodeBase;
    if (Target < CodeBase || Off >= Code.size() || (Target & 1))
      return fault("F-FETCH", Target, Mask, 0);
    ArrayRef<uint8_t> Bytes(reinterpret_cast<const uint8_t *>(Code.data()) + Off,
                            Code.size() - Off);

    MCInst MI;
    uint64_t Size = 0;
    // F-ILLEGAL: an encoding that names no operation (§12.3).
    if (DisAsm->getInstruction(MI, Size, Bytes, Target, nulls()) !=
        MCDisassembler::Success)
      return fault("F-ILLEGAL", Target, Mask, 0);

    if (Trace) {
      std::string S; raw_string_ostream OS(S);
      IP->printInst(&MI, Target, "", *STI, OS);
      outs() << format("  %04x  mask=%08x  %s\n", unsigned(Off), Mask, OS.str().c_str());
    }

    // A fault is precise (§12.4): the faulting instruction has no
    // architectural effect. So every step can be undone -- registers from
    // this copy, memory from the write journals.
    if (!WholeCta && NumThreads > kLanes &&
        (MI.getOpcode() == CCV::C_BAR_ARRIVE || MI.getOpcode() == CCV::C_BAR_WAIT ||
         MI.getOpcode() == CCV::BAR_WAIT_PHASE)) {
      errs() << "error: a barrier in a CTA of " << NumThreads << " threads, "
             << "whose other warps this run does not model; -cta runs them "
             << "(TI-29)\n";
      return 1;
    }
    Warp Before = W;
    if (OF) { MemLog.clear(); ShLog.clear(); }
    Journal.clear(); ShJournal.clear();

    auto R = I.step(W, MI, Mask, Target, unsigned(Size));
    ++Issued;
    ++IssuedBy[Cur];
    // A fault: undo it first, then record the instruction as it was issued
    // -- kind "fault", its uses, no defs, each executing lane's address and
    // no written value -- so the skeleton fetches it and MIU sees it, then the
    // fault, then the state the rollback left (TI-28).
    const bool Faulted = R.Kind == Interp::Result::Fault;
    if (Faulted) {
      W = Before;
      I.Mem.rollBack();
      I.Shared.rollBack();
    }

    if (OF) {
      const MCInstrDesc &D = MII->get(MI.getOpcode());
      std::fprintf(OF, "{\"seq\":%llu,\"pc\":%llu,\"size\":%u,\"bytes\":\"",
                   (unsigned long long)Seqs[Cur]++, (unsigned long long)Target,
                   unsigned(Size));
      for (uint64_t K = 0; K != Size; ++K) std::fprintf(OF, "%02x", Bytes[K]);
      const char *Kind = R.Kind == Interp::Result::Advance ? "advance"
                         : R.Kind == Interp::Result::Branch ? "branch"
                         : R.Kind == Interp::Result::BranchPred ? "branchpred"
                         : R.Kind == Interp::Result::Return ? "return"
                         : R.Kind == Interp::Result::Fault ? "fault"
                         : R.Kind == Interp::Result::Exit ? "exit" : "stall";
      std::fprintf(OF, "\",\"mask\":%u,\"op\":\"%s\",\"kind\":\"%s\","
                       "\"target\":%llu,\"taken\":%u,\"load\":%d,\"store\":%d",
                   Mask, MII->getName(MI.getOpcode()).str().c_str(), Kind,
                   // A return's targets are per lane; the record carries the
                   // lowest issuing lane's, and the register it came from is
                   // in the instruction bytes.
                   (unsigned long long)(R.Kind == Interp::Result::Return
                       ? ((Target & ~uint64_t(0xffffffff)) |
                          W.GPR[R.Target][llvm::countr_zero(Mask)])
                       : R.Target),
                   R.TakenMask,
                   int(D.mayLoad()), int(D.mayStore()));
      // Register operands in operand order: uses read BEFORE the step, defs
      // -- the descriptor's defs plus any register that actually changed --
      // AFTER it. A GPR is 32 lanes; a predicate is one 32-bit mask.
      auto regName = [&](unsigned Reg) { return std::string(MRI->getName(Reg)); };
      auto gprIdx = [&](const std::string &N) {
        return (N.size() >= 2 && N[0] == 'R') ? std::atoi(N.c_str() + 1) : -1;
      };
      auto prdIdx = [&](const std::string &N) {
        return (N.size() >= 2 && N[0] == 'P') ? std::atoi(N.c_str() + 1) : -1;
      };
      std::vector<std::string> Uses, Defs;
      std::vector<int64_t> Imms;   // immediate operands, operand order
      std::vector<int64_t> Quals;  // predicate qualifiers/sources/masks, raw
      auto addTo = [](std::vector<std::string> &V, const std::string &N) {
        if (std::find(V.begin(), V.end(), N) == V.end()) V.push_back(N);
      };
      for (unsigned K = 0; K != MI.getNumOperands(); ++K) {
        const MCOperand &Op = MI.getOperand(K);
        if (Op.isReg()) {
          // Format C's `rd` is a def in the descriptor that no compare writes;
          // listing it would give the skeleton a false dependency.
          if (K == 1 && Interp::isCompare(MI.getOpcode())) continue;
          addTo(K < D.getNumDefs() ? Defs : Uses, regName(Op.getReg()));
          continue;
        }
        // A guard qualifier or a predicate-logic source reads a predicate, and
        // st.pred reads the ones its mask names, though none is a register
        // operand.
        if (!Op.isImm() || K >= D.getNumOperands()) continue;
        uint8_t T = D.operands()[K].OperandType;
        // Everything that is not a predicate name is an immediate the core
        // has to carry: displacements, scale enables, ALU immediates,
        // branch offsets, special-register selectors.
        if (T != CCVOp::OPERAND_PQUAL && T != CCVOp::OPERAND_PSRC &&
            T != CCVOp::OPERAND_PMASK4)
          Imms.push_back(Op.getImm());
        else
          Quals.push_back(Op.getImm());   // index + negate, as encoded
        if (T == CCVOp::OPERAND_PQUAL ||
            (T == CCVOp::OPERAND_PSRC &&
             !(MI.getOpcode() == CCV::PMOV && K == 2))) // pmov reads ps0 only
          addTo(Uses, "P" + std::to_string(Op.getImm() & 3));
        else if (T == CCVOp::OPERAND_PMASK4 && D.mayStore())
          for (unsigned B = 0; B != 4; ++B)
            if (Op.getImm() & (1 << B)) addTo(Uses, "P" + std::to_string(B));
      }
      if (Faulted)
        Defs.clear();
      for (unsigned G = 0; G != kGPRs; ++G)
        if (Before.GPR[G] != W.GPR[G]) {
          std::string N = "R" + std::to_string(G);
          if (std::find(Defs.begin(), Defs.end(), N) == Defs.end()) Defs.push_back(N);
        }
      for (unsigned P = 0; P != kPreds; ++P)
        if (Before.Pred[P] != W.Pred[P]) {
          std::string N = "P" + std::to_string(P);
          if (std::find(Defs.begin(), Defs.end(), N) == Defs.end()) Defs.push_back(N);
        }
      auto emitRegs = [&](const char *Key, const std::vector<std::string> &Rs,
                          const Warp &S) {
        std::fprintf(OF, ",\"%s\":[", Key);
        bool First = true;
        for (const auto &N : Rs) {
          int G = gprIdx(N), P = prdIdx(N);
          if (G < 0 && P < 0) continue;       // not a GPR or predicate
          std::fprintf(OF, First ? "{\"reg\":\"%s\",\"vals\":" : ",{\"reg\":\"%s\",\"vals\":",
                       N.c_str());
          if (G >= 0) jsonU32s(OF, S.GPR[G].data(), kLanes);
          else        std::fprintf(OF, "%u", S.Pred[P]);
          std::fputc('}', OF);
          First = false;
        }
        std::fputc(']', OF);
      };
      std::fprintf(OF, ",\"imms\":[");
      for (size_t K = 0; K != Imms.size(); ++K)
        std::fprintf(OF, K ? ",%lld" : "%lld", (long long)Imms[K]);
      std::fputc(']', OF);
      std::fprintf(OF, ",\"quals\":[");
      for (size_t K = 0; K != Quals.size(); ++K)
        std::fprintf(OF, K ? ",%lld" : "%lld", (long long)Quals[K]);
      std::fputc(']', OF);
      emitRegs("uses", Uses, Before);
      emitRegs("defs", Defs, W);
      // Memory: one access per executing lane, in ascending lane order -- the
      // order forEachLane visits them. Executing means past the guard: a
      // guarded load (ld.global.p) touches only its active lanes, so the
      // count is checked against those, not the issue mask. Anything else
      // cannot be attributed and is refused rather than guessed.
      // The descriptor has to agree with the traffic: F-153 was a load whose
      // descriptor said it touched no memory, which this record reported as
      // "load":0 while listing 32 reads.
      bool Rd = false, Wr = false;
      for (const auto *Log : {&MemLog, &ShLog})
        for (const auto &A : *Log) (A.Write ? Wr : Rd) = true;
      if ((Rd && !D.mayLoad()) || (Wr && !D.mayStore())) {
        errs() << "error: -oracle: " << MII->getName(MI.getOpcode())
               << (Rd && !D.mayLoad() ? " reads" : " writes")
               << " memory but its descriptor does not say so (F-153)\n";
        return 1;
      }
      std::fprintf(OF, ",\"mem\":[");
      const uint32_t Exec = R.ActiveSet ? R.Active : Mask;
      unsigned NLanes = llvm::popcount(Exec), Emitted = 0;
      const unsigned Opc = MI.getOpcode();
      const bool WarpScoped = Opc == CCV::LD_PRED_G || Opc == CCV::ST_PRED_G ||
                              Opc == CCV::LD_PRED_S || Opc == CCV::ST_PRED_S ||
                              Opc == CCV::LD_PRED_LOCAL ||
                              Opc == CCV::ST_PRED_LOCAL;
      for (int SpaceIdx = 0; SpaceIdx != 2; ++SpaceIdx) {
        const auto &Log = SpaceIdx ? ShLog : MemLog;
        if (Log.empty()) continue;
        // A predicate transfer is warp-scoped: one word per predicate in the
        // mask, at lane 0's address (§3, §12.8), not one access per lane. Its
        // words are attributed to lane 0, the lane whose rbase forms them (in
        // the .local forms, the lane term is 0; O-69), whether or not lane 0
        // is executing (TI's rev 115).
        if (WarpScoped) {
          unsigned L = 0;
          for (const auto &A : Log) {
            std::fprintf(OF, "%s{\"lane\":%u,\"space\":\"%s\",\"w\":%d,"
                             "\"addr\":%llu,\"bytes\":%u",
                         Emitted ? "," : "", L, SpaceIdx ? "shared" : "global",
                         int(A.Write), (unsigned long long)A.Addr, A.Bytes);
            if (!Faulted)
              std::fprintf(OF, ",\"val\":%u", A.Val);
            std::fputc('}', OF);
            ++Emitted;
            if (!SpaceIdx) Touched.push_back(A.Addr);
          }
          continue;
        }
        // An atomic (Format M) reads and writes each lane's word: two
        // accesses a lane, read first, both attributed to it.
        const unsigned PerLane =
            D.mayLoad() && D.mayStore() && Log.size() == 2 * NLanes ? 2 : 1;
        if (Log.size() != PerLane * NLanes) {
          errs() << "error: -oracle: " << Log.size() << " memory accesses for "
                 << NLanes << " lanes at " << format_hex(Target, 10)
                 << " -- cannot attribute them to lanes\n";
          return 1;
        }
        unsigned K = 0;
        for (unsigned L = 0; L != kLanes; ++L) {
          if (!(Exec & (1u << L))) continue;
          for (unsigned Rep = 0; Rep != PerLane; ++Rep) {
            const auto &A = Log[K++];
            std::fprintf(OF, "%s{\"lane\":%u,\"space\":\"%s\",\"w\":%d,"
                             "\"addr\":%llu,\"bytes\":%u",
                         Emitted ? "," : "", L, SpaceIdx ? "shared" : "global",
                         int(A.Write), (unsigned long long)A.Addr, A.Bytes);
            // A faulting instruction writes nothing, so it has no value.
            if (!Faulted)
              std::fprintf(OF, ",\"val\":%u", A.Val);
            std::fputc('}', OF);
            ++Emitted;
            if (!SpaceIdx) Touched.push_back(A.Addr);
          }
        }
      }
      std::fprintf(OF, "]}\n");
    }
    if (Faulted)
      return fault(R.Cause, Target, R.TakenMask, R.FaultAddr);

    // --- counters -------------------------------------------------------
    ++C.IssueGroups;
    C.LaneInstrs += llvm::popcount(Mask);
    // Lanes that actually switched, after predication (O-33).
    // A predicate-file operation does not activate a GPR lane.
    //
    // `lane-activations` is defined as the energy proxy for O-33: lanes that
    // toggled ALU operands, a register-file write port or a result bus. A
    // predicate is 32 bits, one per lane (invariant 5), so `pand` is a 32-bit
    // bitwise AND on a narrow file -- 32 gates, not 32 ALU lanes. Charging it
    // the same 32 as a vector operation overstates it by roughly the width of
    // a lane, and it did: it made F-58's `pand` composition look like a loss
    // when measured against the counter rather than against the machine.
    //
    // Counted separately rather than dropped, because it is not free either.
    if (isPredicateFileOp(MI.getOpcode()))
      ++C.PredOps;
    else
      C.ActiveLanes += llvm::popcount(R.ActiveSet ? R.Active : Mask);
    C.Bytes += Size;
    {
      const MCInstrDesc &D = MII->get(MI.getOpcode());
      unsigned Op = MI.getOpcode();
      bool IsBar = Op == CCV::C_BAR_ARRIVE || Op == CCV::C_BAR_WAIT ||
                   Op == CCV::BAR_WAIT_PHASE || Op == CCV::BAR_INIT;
      bool IsPred = Op == CCV::PAND || Op == CCV::POR || Op == CCV::PXOR ||
                    Op == CCV::PMOV_IMM;
      if (IsBar)               ++C.Barrier;
      else if (IsPred)         ++C.Pred;
      else if (D.isBranch() || D.isReturn() || D.isCall() || Op == CCV::C_EXIT) {
        ++C.Ctrl;
        if (D.isCall()) ++C.Calls;
      }
      else if (D.mayLoad() || D.mayStore()) {
        ++C.Mem;
        int Slot = Op == CCV::LD_GLOBAL || Op == CCV::LD_GLOBAL_IDX ? 0
                   : Op == CCV::ST_GLOBAL || Op == CCV::ST_GLOBAL_IDX ? 1
                   : Op == CCV::LD_SHARED || Op == CCV::LD_SHARED_IDX ? 2
                   : Op == CCV::ST_SHARED || Op == CCV::ST_SHARED_IDX ? 3 : -1;
        if (Slot >= 0) ++C.LdSt[Slot];
        // A transfer through the frame pointer is a spill; R15 is reserved
        // (O-30), so nothing else can be addressing through it.
        for (unsigned K = 0; K != MI.getNumOperands(); ++K)
          if (MI.getOperand(K).isReg() && MI.getOperand(K).getReg() == CCV::R15) {
            ++C.Spill;
            break;
          }
      } else                   ++C.ALU;

      // By element width, for O-40's retire-rate model. Only the two pipes
      // that do element work are split: a branch, a barrier or a predicate op
      // has no element width to exploit, and `chwidth` itself is pipeline
      // control that drains dependents rather than arithmetic -- counting it
      // as narrow work would credit the model with the very instruction the
      // model exists to pay for.
      if (Op != CCV::C_CHWIDTH && Op != CCV::CHWIDTH_MULTI) {
        if (D.mayLoad() || D.mayStore()) ++C.WidthMem[R.WidthCode & 3];
        else if (!IsBar && !IsPred && !D.isBranch() && !D.isReturn() && !D.isCall() &&
                 Op != CCV::C_EXIT)      ++C.WidthALU[R.WidthCode & 3];
      }
    }
    if (R.Kind == Interp::Result::Stall)
      C.Stalls += llvm::popcount(R.TakenMask);
    if (R.Kind == Interp::Result::BranchPred && R.TakenMask != 0 &&
        R.TakenMask != Mask)
      ++C.Diverged;

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
    case Interp::Result::Return:
      for (unsigned L = 0; L != kLanes; ++L)
        // §3 Format E (v1.8, 3013036): the PC is {PC[47:32] of the ret,
        // rs[31:0]} -- a concatenation under the ret's own 4 GiB code window,
        // not an add, so no image base reaches the redirect.
        // A narrow rs contributes its element, zero-extended (O-79).
        if (Mask & (1u << L)) {
          uint32_t RS = W.GPR[R.Target][L];
          unsigned N = 32 >> W.ChWidth[R.Target];
          if (N < 32 && !TestAddrFull)
            RS &= (1u << N) - 1;
          W.PC[L] = (Target & ~uint64_t(0xffffffff)) | RS;
        }
      break;
    case Interp::Result::BranchPred:
      // Lanes split here. No bracket, no mask stack -- they simply hold
      // different PCs from now on, and regroup if and when those coincide.
      for (unsigned L = 0; L != kLanes; ++L)
        if (Mask & (1u << L))
          W.PC[L] = (R.TakenMask & (1u << L)) ? R.Target : Target + Size;
      break;
    case Interp::Result::Stall:
      // The blocked lanes hold their PC and drop out of scheduling until the
      // barrier releases them. Lanes of the same group that got through -- the
      // ones the barrier had already retired -- advance normally.
      for (unsigned L = 0; L != kLanes; ++L)
        if ((Mask & (1u << L)) && !(R.TakenMask & (1u << L)))
          W.PC[L] += Size;
      break;
    case Interp::Result::Exit:
      W.Active &= ~Mask;
      C.Regrouped += 0;   // exiting is not reconvergence
      // An exiting lane can be what a barrier was waiting for, since a lane
      // that has left never arrives. Re-check every barrier against the lanes
      // that remain.
      W.Stalled = 0;
      if (live())
        for (unsigned Id = 0; Id != kBarriers; ++Id)
          if (std::any_of(Warps.begin(), Warps.end(),
                          [&](const Warp &X) { return X.Bar[Id].Arrived; }))
            I.retireIfComplete(W, Id);
      break;
    }
  }

  if (live()) {
    errs() << "error: step limit reached with lanes still active\n";
    return 1;
  }

  outs() << "  executed " << Issued << " issue groups\n";

  if (OF)
    emitFinals();
  if (Stats) {
    unsigned Threads = NumThreads >= kLanes ? kLanes : NumThreads;
    auto pct = [](uint64_t N, uint64_t D) {
      return D ? (100.0 * double(N) / double(D)) : 0.0;
    };
    outs() << format("  issue groups            %10llu\n", (unsigned long long)C.IssueGroups)
           << format("  lane-instructions       %10llu   (issued, before predication)\n",
                     (unsigned long long)C.LaneInstrs)
           << format("  lane-activations        %10llu   %5.1f%%  (after predication -- "
                     "the energy number, O-33)\n",
                     (unsigned long long)C.ActiveLanes,
                     pct(C.ActiveLanes, C.LaneInstrs))
           << format("  per thread              %10.1f   (lane-instructions / %u threads)\n",
                     double(C.LaneInstrs) / std::max(1u, unsigned(WholeCta ? NumThreads : Threads)),
                     unsigned(WholeCta ? NumThreads : Threads))
           << format("  SIMT efficiency         %9.1f%%   (lanes active per issue, of %u)\n",
                     pct(C.LaneInstrs, C.IssueGroups * Threads), Threads)
           << format("  no-op widths            %10llu   (registers a chwidth set to the "
                     "width they had, TI-45)\n", (unsigned long long)I.NoopWidths)
           << format("  fairness overrides      %10llu   (O-60 picks that left min-PC)\n",
                     (unsigned long long)C.FairPicks)
           << format("  predicate-file ops      %10llu   (no GPR lane activates)\n",
                     (unsigned long long)C.PredOps)
           << format("  instruction bytes       %10llu\n", (unsigned long long)C.Bytes)
           << format("  dynamic bits/instr      %10.1f\n",
                     C.IssueGroups ? 8.0 * double(C.Bytes) / double(C.IssueGroups) : 0.0)
           << "\n"
           << format("  ALU                     %10llu   %5.1f%%\n",
                     (unsigned long long)C.ALU, pct(C.ALU, C.IssueGroups))
           << format("  memory                  %10llu   %5.1f%%   "
                     "(g:%llu/%llu  s:%llu/%llu  spill:%llu)\n",
                     (unsigned long long)C.Mem, pct(C.Mem, C.IssueGroups),
                     (unsigned long long)C.LdSt[0], (unsigned long long)C.LdSt[1],
                     (unsigned long long)C.LdSt[2], (unsigned long long)C.LdSt[3],
                     (unsigned long long)C.Spill)
           << format("  control                 %10llu   %5.1f%%   (%llu divergent, %llu calls)\n",
                     (unsigned long long)C.Ctrl, pct(C.Ctrl, C.IssueGroups),
                     (unsigned long long)C.Diverged, (unsigned long long)C.Calls)
           << format("  predicate               %10llu   %5.1f%%\n",
                     (unsigned long long)C.Pred, pct(C.Pred, C.IssueGroups))
           << format("  barrier                 %10llu   %5.1f%%   (%llu lane-stalls)\n",
                     (unsigned long long)C.Barrier, pct(C.Barrier, C.IssueGroups),
                     (unsigned long long)C.Stalls);

    // O-40's fraction. The split allocation gives narrow operations a higher
    // retire rate; what that is worth is bounded by how much of the stream is
    // narrow, and nothing measured it before this counter existed.
    uint64_t EW = 0;
    for (int I = 0; I != 4; ++I) EW += C.WidthALU[I] + C.WidthMem[I];
    if (EW) {
      static const char *WN[4] = {"32-bit", "16-bit", "8-bit", "4-bit"};
      outs() << "\n  element-work instructions by width (O-40)\n";
      for (int I = 0; I != 4; ++I) {
        uint64_t N = C.WidthALU[I] + C.WidthMem[I];
        if (!N) continue;
        outs() << format("  %-8s                %10llu   %5.1f%%   "
                         "(alu %llu, mem %llu)\n",
                         WN[I], (unsigned long long)N, pct(N, EW),
                         (unsigned long long)C.WidthALU[I],
                         (unsigned long long)C.WidthMem[I]);
      }
      outs() << format("  narrow fraction         %14.3f   "
                       "(of %llu element-work instructions)\n",
                       double(EW - C.WidthALU[0] - C.WidthMem[0]) / double(EW),
                       (unsigned long long)EW);
    }
  }
  for (const auto &P : Peeks) {
    uint64_t Addr;
    if (StringRef(P).getAsInteger(0, Addr)) {
      errs() << "error: bad -peek '" << P << "'\n"; return 1;
    }
    outs() << format("  [%#llx] = %u\n", (unsigned long long)Addr, I.Mem.read32(Addr));
  }
  for (auto [PC, N] : NoopPCs)
    outs() << format("  no-op width at %#llx: %llu\n", (unsigned long long)PC,
                     (unsigned long long)N);
  return 0;
}
