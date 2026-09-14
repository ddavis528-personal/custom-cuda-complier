//===-- Interp.h - CCV instruction semantics --------------------*- C++ -*-===//
#ifndef CCV_SIM_INTERP_H
#define CCV_SIM_INTERP_H

#include "Warp.h"
#include <cstdint>

namespace llvm { class MCInst; }

namespace ccv {

class Interp {
public:
  Memory Mem;
  /// §5.1 makes `.shared` a separate flat 32-bit space, not a window into the
  /// 48-bit one, so it is a separate memory here too. CTA-private falls out:
  /// the simulator runs one CTA.
  Memory Shared;

  struct Result {
    enum Kind { Advance, Branch, BranchPred, Exit, Stall, Unimplemented } Kind;
    uint64_t Target = 0;
    /// Lanes that actually did work, after the predicate qualifier. Defaults
    /// to the whole issue mask; a predicated instruction narrows it. This is
    /// the energy number -- O-33 exists to make it smaller than the issue
    /// mask, and it is only a real saving if the hardware gates mask-off lanes.
    uint32_t Active = 0;
    bool ActiveSet = false;

    /// Element width this instruction operated at, as a `chwidth` code
    /// (0 = 32, 1 = 16, 2 = 8, 3 = 4). O-40 splits the datapath allocation so
    /// that narrow operations retire at a multiple of the 32-bit rate, and the
    /// multiple is only worth anything on the FRACTION of the stream that is
    /// narrow -- so the fraction has to be measured, not assumed.
    uint8_t WidthCode = 0;

    /// For BranchPred: the subset of the issue mask that takes the branch.
    /// Lanes outside it fall through -- which is how divergence arises, with
    /// no bracket instruction and nothing forcing reconvergence (§1).
    uint32_t TakenMask = 0;
  };

  Result step(Warp &W, const llvm::MCInst &MI, uint32_t Mask, uint64_t PC,
              unsigned Size);
};

} // namespace ccv
#endif
