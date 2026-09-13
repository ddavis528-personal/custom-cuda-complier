//===-- Interp.h - CCG instruction semantics --------------------*- C++ -*-===//
#ifndef CCG_SIM_INTERP_H
#define CCG_SIM_INTERP_H

#include "Warp.h"
#include <cstdint>

namespace llvm { class MCInst; }

namespace ccg {

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
    /// For BranchPred: the subset of the issue mask that takes the branch.
    /// Lanes outside it fall through -- which is how divergence arises, with
    /// no bracket instruction and nothing forcing reconvergence (§1).
    uint32_t TakenMask = 0;
  };

  Result step(Warp &W, const llvm::MCInst &MI, uint32_t Mask, uint64_t PC,
              unsigned Size);
};

} // namespace ccg
#endif
