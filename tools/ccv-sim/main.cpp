//===-- main.cpp - CCV functional simulator ------------------------------===//
//
// Executes one warp with independent per-thread PCs. Lanes are grouped for
// issue only where their PCs coincide; nothing forces convergence, and lanes
// that drift apart simply issue separately. That is the machine's actual
// divergence model (§1), not an approximation of a mask-stack one.
//
//===----------------------------------------------------------------------===//

#include "Interp.h"
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
static cl::opt<unsigned> NumThreads("threads", cl::init(32),
                                    cl::desc("active threads in the CTA"));
static cl::opt<unsigned> CtaId("ctaid", cl::init(0), cl::desc("CTA index"));
static cl::opt<uint64_t> CodeBase("code-base", cl::init(0x1000),
                                  cl::desc("load address for the kernel"));
static cl::opt<bool> Trace("trace", cl::desc("print each issue group"));
static cl::opt<bool> Stats("counters", cl::desc("print execution counters"));
static cl::opt<unsigned> MaxSteps("max-steps", cl::init(100000),
                                  cl::desc("issue-group limit"));
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

  std::FILE *OF = nullptr;
  std::vector<Memory::Access> MemLog, ShLog;
  std::vector<uint64_t> Touched;               // every address an access saw
  if (!OracleFile.empty()) {
    OF = std::fopen(OracleFile.c_str(), "w");
    if (!OF) { errs() << "error: cannot write " << OracleFile << "\n"; return 1; }
    std::fprintf(OF, "{\"init\":{\"code_base\":%llu,\"threads\":%u,"
                     "\"ctaid\":%u,\"code\":\"",
                 (unsigned long long)CodeBase, unsigned(NumThreads),
                 unsigned(CtaId));
    for (unsigned char Ch : Code) std::fprintf(OF, "%02x", Ch);
    std::fprintf(OF, "\",\"mem\":[");
    bool First = true;
    for (const auto &P : Pokes) {
      auto [A, V] = StringRef(P).split('=');
      uint64_t Addr; uint32_t Val;
      A.getAsInteger(0, Addr); V.getAsInteger(0, Val);
      std::fprintf(OF, First ? "[%llu,%u]" : ",[%llu,%u]",
                   (unsigned long long)Addr, Val);
      First = false;
      Touched.push_back(Addr);
    }
    std::fprintf(OF, "]}}\n");
    I.Mem.Log = &MemLog;
    I.Shared.Log = &ShLog;
  }
  uint64_t Seq = 0;

  Counters C;
  // Distinct PCs among runnable lanes, to tell reconvergence from mere
  // progress: §1 claims lanes regroup opportunistically when their PCs
  // coincide, and that is only observable by watching the count fall.
  auto distinctPCs = [&](uint32_t Run) {
    unsigned N = 0;
    uint64_t Seen[kLanes];
    for (unsigned L = 0; L != kLanes; ++L) {
      if (!((Run >> L) & 1)) continue;
      bool New = true;
      for (unsigned J = 0; J != N; ++J)
        if (Seen[J] == W.PC[L]) { New = false; break; }
      if (New) Seen[N++] = W.PC[L];
    }
    return N;
  };
  unsigned PrevGroups = 1;

  unsigned Steps = 0, Issued = 0;
  while (W.Active && Steps++ < MaxSteps) {
    // Group by PC: pick the lowest PC among active lanes and issue for every
    // lane sitting there. Lowest-first is a scheduling policy, not semantics --
    // any order gives the same results.
    uint32_t Runnable = W.Active & ~W.Stalled;
    if (!Runnable) {
      // Every remaining lane is blocked at a barrier that no one can now
      // complete. Report it as what it is rather than running to the step
      // limit: a deadlocked kernel and a slow one look nothing alike.
      errs() << "error: deadlock -- " << llvm::popcount(W.Active)
             << " lanes blocked at a barrier with no lane able to arrive\n";
      return 1;
    }

    uint64_t Target = UINT64_MAX;
    for (unsigned L = 0; L != kLanes; ++L)
      if ((Runnable >> L) & 1)
        Target = std::min(Target, W.PC[L]);

    uint32_t Mask = 0;
    for (unsigned L = 0; L != kLanes; ++L)
      if (((Runnable >> L) & 1) && W.PC[L] == Target)
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

    Warp Before;
    if (OF) { Before = W; MemLog.clear(); ShLog.clear(); }

    auto R = I.step(W, MI, Mask, Target, unsigned(Size));
    ++Issued;

    if (OF) {
      const MCInstrDesc &D = MII->get(MI.getOpcode());
      std::fprintf(OF, "{\"seq\":%llu,\"pc\":%llu,\"size\":%u,\"bytes\":\"",
                   (unsigned long long)Seq++, (unsigned long long)Target,
                   unsigned(Size));
      for (uint64_t K = 0; K != Size; ++K) std::fprintf(OF, "%02x", Bytes[K]);
      const char *Kind = R.Kind == Interp::Result::Advance ? "advance"
                         : R.Kind == Interp::Result::Branch ? "branch"
                         : R.Kind == Interp::Result::BranchPred ? "branchpred"
                         : R.Kind == Interp::Result::Exit ? "exit" : "stall";
      std::fprintf(OF, "\",\"mask\":%u,\"op\":\"%s\",\"kind\":\"%s\","
                       "\"target\":%llu,\"taken\":%u,\"load\":%d,\"store\":%d",
                   Mask, MII->getName(MI.getOpcode()).str().c_str(), Kind,
                   (unsigned long long)R.Target, R.TakenMask,
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
      // order forEachLane visits them. Anything else cannot be attributed and
      // is refused rather than guessed.
      // The descriptor has to agree with the traffic: F-141 was a load whose
      // descriptor said it touched no memory, which this record reported as
      // "load":0 while listing 32 reads.
      bool Rd = false, Wr = false;
      for (const auto *Log : {&MemLog, &ShLog})
        for (const auto &A : *Log) (A.Write ? Wr : Rd) = true;
      if ((Rd && !D.mayLoad()) || (Wr && !D.mayStore())) {
        errs() << "error: -oracle: " << MII->getName(MI.getOpcode())
               << (Rd && !D.mayLoad() ? " reads" : " writes")
               << " memory but its descriptor does not say so (F-141)\n";
        return 1;
      }
      std::fprintf(OF, ",\"mem\":[");
      unsigned NLanes = llvm::popcount(Mask), Emitted = 0;
      for (int SpaceIdx = 0; SpaceIdx != 2; ++SpaceIdx) {
        const auto &Log = SpaceIdx ? ShLog : MemLog;
        if (Log.empty()) continue;
        if (Log.size() != NLanes) {
          errs() << "error: -oracle: " << Log.size() << " memory accesses for "
                 << NLanes << " lanes at " << format_hex(Target, 10)
                 << " -- cannot attribute them to lanes\n";
          return 1;
        }
        unsigned K = 0;
        for (unsigned L = 0; L != kLanes; ++L) {
          if (!(Mask & (1u << L))) continue;
          const auto &A = Log[K++];
          std::fprintf(OF, Emitted ? ",{\"lane\":%u,\"space\":\"%s\",\"w\":%d,"
                                     "\"addr\":%llu,\"bytes\":%u,\"val\":%u}"
                                   : "{\"lane\":%u,\"space\":\"%s\",\"w\":%d,"
                                     "\"addr\":%llu,\"bytes\":%u,\"val\":%u}",
                       L, SpaceIdx ? "shared" : "global", int(A.Write),
                       (unsigned long long)A.Addr, A.Bytes, A.Val);
          ++Emitted;
          if (!SpaceIdx) Touched.push_back(A.Addr);
        }
      }
      std::fprintf(OF, "]}\n");
    }

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
      else if (D.isBranch() || D.isReturn() || Op == CCV::C_EXIT) ++C.Ctrl;
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
        else if (!IsBar && !IsPred && !D.isBranch() && !D.isReturn() &&
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
      for (auto &B : W.Bar)
        if (B.Arrived && W.Active && (B.Arrived & W.Active) == W.Active) {
          B.Arrived = 0;
          ++B.Epoch;
        }
      break;
    }
  }

  if (W.Active) {
    errs() << "error: step limit reached with lanes still active\n";
    return 1;
  }

  outs() << "  executed " << Issued << " issue groups\n";
  if (OF) {
    // Final architectural state: every GPR lane, every predicate, and every
    // global word any access or poke touched -- what the skeleton's retired
    // state is compared against.
    I.Mem.Log = nullptr;
    I.Shared.Log = nullptr;
    std::fprintf(OF, "{\"final\":{\"gpr\":[");
    for (unsigned G = 0; G != kGPRs; ++G) {
      if (G) std::fputc(',', OF);
      jsonU32s(OF, W.GPR[G].data(), kLanes);
    }
    std::fprintf(OF, "],\"pred\":");
    jsonU32s(OF, W.Pred.data(), kPreds);
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
    std::fprintf(OF, "],\"issue_groups\":%u}}\n", Issued);
    std::fclose(OF);
  }
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
                     double(C.LaneInstrs) / std::max(1u, Threads), Threads)
           << format("  SIMT efficiency         %9.1f%%   (lanes active per issue, of %u)\n",
                     pct(C.LaneInstrs, C.IssueGroups * Threads), Threads)
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
           << format("  control                 %10llu   %5.1f%%   (%llu divergent)\n",
                     (unsigned long long)C.Ctrl, pct(C.Ctrl, C.IssueGroups),
                     (unsigned long long)C.Diverged)
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
  return 0;
}
