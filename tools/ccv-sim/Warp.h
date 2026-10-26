//===-- Warp.h - CCV warp state ---------------------------------*- C++ -*-===//
//
// Execution state for one warp, modelled as the ISA describes it rather than as
// a convenient approximation:
//
//   - A GPR holds 32 lanes, one element per lane, always (§1).
//   - A predicate is 32 bits, one per lane, at every chwidth (invariant 5).
//   - PC is per *thread*, not per warp (§1, divergence handling). Lanes are
//     grouped for issue only when their PCs happen to coincide; nothing forces
//     convergence.
//
//===----------------------------------------------------------------------===//
#ifndef CCV_SIM_WARP_H
#define CCV_SIM_WARP_H

#include <array>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace ccv {

static constexpr unsigned kLanes = 32;
static constexpr unsigned kGPRs = 16;
static constexpr unsigned kPreds = 4;
/// §3, Format E: 6-bit barrier ID, "64 entries -- matches the 4x16 table".
static constexpr unsigned kBarriers = 64;

/// Sparse 48-bit address space. Paged so a kernel can use widely separated
/// windows (§5.4: thread-, warp- and CTA-private scopes) without allocating
/// anything between them.
class Memory {
  static constexpr uint64_t kPageBits = 12;
  static constexpr uint64_t kPageSize = 1ull << kPageBits;
  std::unordered_map<uint64_t, std::vector<uint8_t>> Pages;

  uint8_t *byteAt(uint64_t Addr) {
    auto &P = Pages[Addr >> kPageBits];
    if (P.empty())
      P.resize(kPageSize, 0);
    return &P[Addr & (kPageSize - 1)];
  }

public:
  /// One architectural access, for the oracle record (`-oracle`). Only
  /// recorded while `Log` is set, so the simulator's own runs pay nothing,
  /// and pokes/peeks made from outside a step never appear.
  /// Refused: the access was not made, for F-ALIGN or F-RO. It is logged so
  /// a faulting instruction's oracle record still has every executing lane's
  /// address (TI-28).
  struct Access { uint64_t Addr; unsigned Bytes; uint32_t Val; bool Write;
                  bool Refused = false; };
  std::vector<Access> *Log = nullptr;

  uint32_t read32(uint64_t Addr) {
    uint32_t V = 0;
    for (unsigned I = 0; I != 4; ++I)
      V |= uint32_t(*byteAt(Addr + I)) << (8 * I);
    if (Log) Log->push_back({Addr, 4, V, false});
    return V;
  }
  void write32(uint64_t Addr, uint32_t V) {
    for (unsigned I = 0; I != 4; ++I) {
      journal(Addr + I);
      *byteAt(Addr + I) = uint8_t(V >> (8 * I));
    }
    if (Log) Log->push_back({Addr, 4, V, true});
  }
  uint8_t read8(uint64_t Addr) {
    uint8_t V = *byteAt(Addr);
    if (Log) Log->push_back({Addr, 1, V, false});
    return V;
  }
  void write8(uint64_t Addr, uint8_t V) {
    journal(Addr);
    *byteAt(Addr) = V;
    if (Log) Log->push_back({Addr, 1, V, true});
  }
  /// A raw byte, never logged: for dumping final state.
  uint8_t peekByte(uint64_t Addr) { return *byteAt(Addr); }
  /// A word the AGU reads to form an address -- the launch-slot form's window
  /// (O-45) -- which is not one of the lanes' accesses, so it is never logged.
  uint32_t peek32(uint64_t Addr) {
    uint32_t V = 0;
    for (unsigned I = 0; I != 4; ++I)
      V |= uint32_t(*byteAt(Addr + I)) << (8 * I);
    return V;
  }

  /// O-58 (ISA v1.9, from IS-1): a lane's effective address must be a multiple
  /// of its transfer size -- 4 at 32 bits, 2 at 16, any at 8. A violation is
  /// F-ALIGN, an execute-stage fault, per lane (§12). The access is not made;
  /// the lane is recorded, and Interp::step turns the record into the fault.
  /// Only the lanes an instruction actually executes reach here, so the
  /// predicate gating §12.2 requires is the simulator's ordinary lane loop.
  /// The first lane recorded is the lowest, since lanes run in ascending
  /// order, which is the address §12.6's record reports.
  unsigned CurLane = 0;
  uint32_t AlignLanes = 0;
  uint64_t AlignAddr = 0;

  bool alignOK(uint64_t Addr, unsigned Bytes) {
    if (Bytes <= 1 || (Addr % Bytes) == 0)
      return true;
    if (!AlignLanes)
      AlignAddr = Addr;
    AlignLanes |= 1u << CurLane;
    return false;
  }

  /// F-ADDR (O-75): a .global effective address is the exact sum, and one
  /// below 0 or at or above 2^48 maps nothing. Refused per lane and recorded,
  /// as F-ALIGN is; Interp::step raises it after F-ALIGN and before F-RO
  /// (§12.5). 0 is no limit: .shared wraps at 2^32 instead (O-75), and its
  /// own fault, F-SHARED, needs the CTA's allocation, which ccv-sim does not
  /// take.
  uint64_t AddrLimit = 0;
  uint32_t AddrLanes = 0;
  uint64_t AddrAddr = 0;
  /// O-83 (§5.9): the run's own windows [UnmapLo, UnmapHi) name logical
  /// offsets only, and the runtime maps no page there, so an ordinary access
  /// into them raises F-ADDR. Refuse is one-shot: an interleaved lane whose b
  /// lies outside [0, L) is refused at the address it would otherwise form.
  uint64_t UnmapLo = 0, UnmapHi = 0;
  bool Refuse = false;
  bool addrOK(uint64_t Addr) {
    bool Bad = Refuse || (Addr >= UnmapLo && Addr < UnmapHi);
    Refuse = false;
    if (!Bad && (!AddrLimit || Addr < AddrLimit))
      return true;
    if (!AddrLanes)
      AddrAddr = Addr;
    AddrLanes |= 1u << CurLane;
    return false;
  }

  /// F-RO (O-51, O-61; ISA v1.9 §5.2): a store any byte of which lies in
  /// read-only memory -- the whole launch window, and the module's .const
  /// range [ConstBase, ConstLimit) -- is refused per lane and recorded, as
  /// F-ALIGN is, and Interp::step raises it after F-ALIGN (§12.5). Loads are
  /// unaffected.
  uint64_t LaunchWindow = 2;
  uint64_t ConstBase = 0, ConstLimit = 0;
  uint32_t RoLanes = 0;
  uint64_t RoAddr = 0;
  bool roOK(uint64_t Addr, unsigned Bytes) {
    bool InLaunch = (Addr >> 16) == LaunchWindow ||
                    ((Addr + Bytes - 1) >> 16) == LaunchWindow;
    bool InConst = Addr < ConstLimit && Addr + Bytes > ConstBase;
    if (!InLaunch && !InConst)
      return true;
    if (!RoLanes)
      RoAddr = Addr;
    RoLanes |= 1u << CurLane;
    return false;
  }

  /// A fault is precise (§12.4): the faulting instruction has no architectural
  /// effect, though other lanes of it may already have written. While a step
  /// runs, every byte written is journalled, and a fault undoes them.
  struct Undo { uint64_t Addr; uint8_t Old; };
  std::vector<Undo> *Journal = nullptr;
  void journal(uint64_t Addr) {
    if (Journal) Journal->push_back({Addr, *byteAt(Addr)});
  }
  void rollBack() {
    for (auto It = Journal->rbegin(); It != Journal->rend(); ++It)
      *byteAt(It->Addr) = It->Old;
  }

  /// §3: "Transfer size is inherited from `rdata`'s `chwidth` -- no size
  /// field." So a load is 4, 2 or 1 bytes depending on the destination
  /// register's current width, and the 4-bit width has no byte transfer at all.
  uint32_t readN(uint64_t Addr, unsigned Bytes) {
    if (!alignOK(Addr, Bytes) || !addrOK(Addr)) {
      if (Log) Log->push_back({Addr, Bytes, 0, false, true});
      return 0;
    }
    uint32_t V = 0;
    for (unsigned I = 0; I != Bytes; ++I)
      V |= uint32_t(*byteAt(Addr + I)) << (8 * I);
    if (Log) Log->push_back({Addr, Bytes, V, false});
    return V;
  }
  void writeN(uint64_t Addr, uint32_t V, unsigned Bytes) {
    if (!alignOK(Addr, Bytes) || !addrOK(Addr) || !roOK(Addr, Bytes)) {
      if (Log) Log->push_back({Addr, Bytes, V, true, true});
      return;
    }
    for (unsigned I = 0; I != Bytes; ++I) {
      journal(Addr + I);
      *byteAt(Addr + I) = uint8_t(V >> (8 * I));
    }
    if (Log) Log->push_back({Addr, Bytes, V, true});
  }
};

/// Execution counters. Static code size is what an encoding is usually judged
/// on, but "instructions required to complete a task" is a dynamic question and
/// the two can differ by orders of magnitude -- a 32-iteration division loop is
/// 35 instructions statically and over a thousand in flight.
///
/// Warp-level and thread-level are both reported because they answer different
/// questions: issue groups are what the machine schedules and what code size
/// predicts, lane-instructions are the work actually done, and their ratio is
/// what divergence costs.
struct Counters {
  uint64_t IssueGroups = 0;   ///< instructions issued, warp granularity
  uint64_t LaneInstrs = 0;    ///< sum of issue-mask lanes over all issues
  uint64_t ActiveLanes = 0;   ///< the same after predication (O-33)
  uint64_t PredOps = 0;       ///< predicate-file ops: no GPR lane activates
  uint64_t Bytes = 0;         ///< dynamic instruction bytes fetched
  uint64_t Stalls = 0;        ///< issue slots spent blocked at a barrier
  uint64_t Diverged = 0;      ///< predicated branches where the mask split
  uint64_t FairPicks = 0;     ///< issues O-60's fairness rule redirected
  uint64_t Regrouped = 0;     ///< issues that reunited lanes previously apart

  // By class. Taken from MCInstrDesc where possible rather than from an opcode
  // list here, so the simulator does not carry a second opinion about what an
  // instruction is.
  uint64_t ALU = 0, Mem = 0, Ctrl = 0, Pred = 0, Barrier = 0;
  // Memory detail. `Spill` is a subset of Mem: a transfer through the frame
  // pointer, which nothing else uses because R15 is reserved (O-30).
  uint64_t LdSt[4] = {};      ///< ld.global, st.global, ld.shared, st.shared
  uint64_t Spill = 0;
  // Calls issued, for AR-20's traffic per call. A call is control; it used to
  // fall through to ALU, being neither a branch nor a return.
  uint64_t Calls = 0;

  // Issued instructions by element width (0 = 32, 1 = 16, 2 = 8, 3 = 4), split
  // by pipe. O-40 gives narrow operations a higher retire rate by splitting the
  // datapath allocation, and whether that recovers the instructions the narrow
  // form costs depends entirely on how much of the stream is narrow -- Amdahl,
  // on a fraction nothing had measured. Split by pipe because the ALU and the
  // memory path do not have to dual-issue on the same terms, and the person
  // designing them should be able to price each separately.
  uint64_t WidthALU[4] = {};
  uint64_t WidthMem[4] = {};
};

struct Warp {
  /// gpr[r][lane] -- 32 lanes per register, one element each.
  std::array<std::array<uint32_t, kLanes>, kGPRs> GPR{};
  /// One bit per lane. Does not narrow with chwidth.
  std::array<uint32_t, kPreds> Pred{};
  /// Per-thread PC. This is the actual hardware cost of the scheduling model,
  /// not a simulation convenience.
  std::array<uint64_t, kLanes> PC{};
  /// Cleared by exit. A lane that has exited is never grouped again.
  uint32_t Active = 0xffffffffu;
  /// Per-logical-register element width, as a width code (§1). Not renamed,
  /// not speculative -- architecturally committed by the time it is observed.
  std::array<uint8_t, kGPRs> ChWidth{};

  /// Flat thread index within the CTA, per lane. Supplied by srd (§5.3);
  /// the only value the launch block structurally cannot carry.
  std::array<uint32_t, kLanes> CtaTid{};
  uint32_t CtaId = 0;
  // The warp's hardware context, which srd #2 (%lanectx) reads (O-64). Which
  // context a warp gets is the dispatcher's choice; ccv-sim gives warp w of
  // the CTA context w unless -context names another (TI-35).
  uint32_t WarpCtx = 0;

  /// Lanes blocked at a barrier. They hold their PC and are skipped when the
  /// scheduler picks an issue group -- otherwise a lowest-PC scheduler would
  /// select a blocked lane forever. Not architectural state; it is the
  /// simulator's representation of "this thread is not runnable".
  uint32_t Stalled = 0;

  /// Barrier state (O-27). The arrival epoch is per *thread* here because a
  /// thread is what arrives -- §1's per-thread PCs mean lanes of one warp can
  /// reach a barrier at different times, which is exactly what makes a barrier
  /// a real synchronisation point rather than a formality. Hardware tracks
  /// this per warp; per lane is the finer-grained version of the same thing.
  struct BarrierState {
    uint32_t Arrived = 0;                     ///< lanes arrived this epoch
    uint64_t Epoch = 0;                       ///< completions so far
    std::array<uint64_t, kLanes> ArrivalEpoch{}; ///< epoch each lane arrived in
  };
  std::array<BarrierState, kBarriers> Bar{};

  Warp() { ChWidth.fill(0); } // 00 = 32-bit, the reset default
};

} // namespace ccv
#endif
