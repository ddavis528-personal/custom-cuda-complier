//===-- Warp.h - CCG warp state ---------------------------------*- C++ -*-===//
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
#ifndef CCG_SIM_WARP_H
#define CCG_SIM_WARP_H

#include <array>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace ccg {

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
  uint32_t read32(uint64_t Addr) {
    uint32_t V = 0;
    for (unsigned I = 0; I != 4; ++I)
      V |= uint32_t(*byteAt(Addr + I)) << (8 * I);
    return V;
  }
  void write32(uint64_t Addr, uint32_t V) {
    for (unsigned I = 0; I != 4; ++I)
      *byteAt(Addr + I) = uint8_t(V >> (8 * I));
  }
  uint8_t read8(uint64_t Addr) { return *byteAt(Addr); }
  void write8(uint64_t Addr, uint8_t V) { *byteAt(Addr) = V; }
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
  uint64_t LaneInstrs = 0;    ///< sum of active lanes over all issues
  uint64_t Bytes = 0;         ///< dynamic instruction bytes fetched
  uint64_t Stalls = 0;        ///< issue slots spent blocked at a barrier
  uint64_t Diverged = 0;      ///< predicated branches where the mask split
  uint64_t Regrouped = 0;     ///< issues that reunited lanes previously apart

  // By class. Taken from MCInstrDesc where possible rather than from an opcode
  // list here, so the simulator does not carry a second opinion about what an
  // instruction is.
  uint64_t ALU = 0, Mem = 0, Ctrl = 0, Pred = 0, Barrier = 0;
  // Memory detail. `Spill` is a subset of Mem: a transfer through the frame
  // pointer, which nothing else uses because R15 is reserved (O-30).
  uint64_t LdSt[4] = {};      ///< ld.global, st.global, ld.shared, st.shared
  uint64_t Spill = 0;
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

} // namespace ccg
#endif
