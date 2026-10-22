//===-- Interp.h - CCV instruction semantics --------------------*- C++ -*-===//
#ifndef CCV_SIM_INTERP_H
#define CCV_SIM_INTERP_H

#include "Warp.h"
#include <cstdint>

namespace llvm { class MCInst; }

namespace ccv {

class Interp {
public:
  /// CP-6: one lane of an FP-block operation or a conversion, for
  /// tools/check-narrow-fp.py. Widths are the registers' width codes in the
  /// order destination, a, b, c (unused ones ignored). False is F-FORMAT, or an
  /// opcode that is neither.
  static bool evalFp(unsigned Op, const uint8_t Widths[4], uint32_t X,
                     uint32_t Y, uint32_t Z, uint32_t &Out);

  Memory Mem;
  /// §5.1 makes `.shared` a separate flat 32-bit space, not a window into the
  /// 48-bit one, so it is a separate memory here too. CTA-private falls out:
  /// the simulator runs one CTA.
  Memory Shared;
  /// Barriers the CTA has allocated, at most 16 (O-59); an ID at or above it
  /// raises F-BARRIER.
  unsigned BarrierCount = 16;

  struct Result {
    /// Return: each issuing lane's PC becomes its own lane of GPR `Target`.
    enum Kind { Advance, Branch, BranchPred, Return, Exit, Stall, Fault, Unimplemented } Kind;
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

    /// For Fault: the cause (ISA v1.9 §12.3), and for an execute-stage memory
    /// fault the address of the lowest faulting lane. The faulting lanes are
    /// TakenMask: the issue mask for decode and dispatch faults, the lanes
    /// that faulted for execute ones (§12.6).
    const char *Cause = nullptr;
    uint64_t FaultAddr = 0;
  };

  Result step(Warp &W, const llvm::MCInst &MI, uint32_t Mask, uint64_t PC,
              unsigned Size);

  /// Is this one of the 64 Format C compares (every `setp` form)? Operand 1 of
  /// each is the materialization destination `rd`, which these semantics never
  /// write -- so it is neither data for the width counter nor a def for the
  /// -oracle record.
  static bool isCompare(unsigned Op);
};

} // namespace ccv
/// The launch block's address (§5.2), for main's -data loading (O-61).
uint64_t launchBlockBase();

#endif
