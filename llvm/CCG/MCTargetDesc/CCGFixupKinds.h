//===-- CCGFixupKinds.h -----------------------------------------*- C++ -*-===//
//
// Branch offsets in §3 are PC-relative, **16-bit granular**, and measured from
// the instruction after the branch -- so a fixup value is (target - next) / 2.
//
// `bra.pred`'s offset is **split around the predicate qualifier** (O-10's
// technique, applied in Format E): bits [15:0] at [26:11] and [17:16] at
// [31:30], which keeps the qualifier at the canonical [29:27] and the sign bit
// at 31. MCFixupKindInfo can only describe a contiguous field, so the scatter
// is done by hand in applyFixup.
//
//===----------------------------------------------------------------------===//
#ifndef CCG_MCTARGETDESC_CCGFIXUPKINDS_H
#define CCG_MCTARGETDESC_CCGFIXUPKINDS_H

#include "llvm/MC/MCFixup.h"

namespace llvm {
namespace CCG {
enum Fixups {
  /// `bra`: 21-bit signed halfword offset, contiguous at [31:11].
  fixup_ccg_bra21 = FirstTargetFixupKind,
  /// `bra.pred`: 18-bit signed halfword offset, split [26:11] and [31:30].
  fixup_ccg_brapred18,
  /// `call`: 17-bit signed halfword offset, contiguous at [31:15].
  fixup_ccg_call17,
  /// bra.short (Format K point 49): 8-bit signed halfword offset on a 16-bit
  /// instruction. Selected optimistically and relaxed to fixup_ccg_bra21 when
  /// the target turns out to be further than ±256 bytes, which is a decision
  /// only layout can make.
  fixup_ccg_bra8,

  LastTargetFixupKind,
  NumTargetFixupKinds = LastTargetFixupKind - FirstTargetFixupKind
};
} // namespace CCG
} // namespace llvm
#endif
