//===-- CCVTargetTransformInfo.cpp ----------------------------------------===//
#include "CCVTargetTransformInfo.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/IntrinsicsNVPTX.h"

using namespace llvm;

bool CCVTTIImpl::isSourceOfDivergence(const Value *V) const {
  // A kernel takes no register arguments at all -- its parameters arrive in the
  // launch block (§5.2), which is CTA-wide and therefore warp-uniform. By the
  // time this runs they are `.const` loads, but an unlowered argument is
  // uniform too.
  if (isa<Argument>(V))
    return false;

  const auto *II = dyn_cast<IntrinsicInst>(V);
  if (!II)
    return false;

  switch (II->getIntrinsicID()) {
  // The thread index is the ONLY architectural source of divergence: it is
  // what `srd` supplies per lane (§5.3), and everything else a kernel can read
  // is either CTA-wide or grid-wide.
  case Intrinsic::nvvm_read_ptx_sreg_tid_x:
  case Intrinsic::nvvm_read_ptx_sreg_tid_y:
  case Intrinsic::nvvm_read_ptx_sreg_tid_z:
  case Intrinsic::nvvm_read_ptx_sreg_laneid:
    return true;
  // ctaid, nctaid and ntid are uniform across a warp -- every lane of a warp is
  // in one CTA. This is exactly where the warp-scoped question parts company
  // with NVPTX's grid-scoped one, which calls ctaid divergent.
  default:
    return false;
  }
}
