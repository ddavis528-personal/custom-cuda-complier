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

  Warp() { ChWidth.fill(0); } // 00 = 32-bit, the reset default
};

} // namespace ccg
#endif
