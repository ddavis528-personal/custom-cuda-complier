//===-- CCGTargetTransformInfo.h --------------------------------*- C++ -*-===//
//
// Exists for one question: which values are WARP-uniform.
//
// That is not the same question LLVM's stock NVPTX answer gives. NVPTX marks
// `ctaid` divergent, which is right across a grid and wrong across a warp --
// every lane of a warp is in the same CTA, so `ctaid` and `ntid` are uniform
// here and only `tid` is not. O-25 names warp-invariance reporting as "the only
// evidence that would size a uniform register file", and that evidence needs
// the warp-scoped notion.
//
//===----------------------------------------------------------------------===//
#ifndef CCG_CCGTARGETTRANSFORMINFO_H
#define CCG_CCGTARGETTRANSFORMINFO_H

#include "CCGTargetMachine.h"
#include "llvm/CodeGen/BasicTTIImpl.h"

namespace llvm {

class CCGTTIImpl : public BasicTTIImplBase<CCGTTIImpl> {
  using BaseT = BasicTTIImplBase<CCGTTIImpl>;
  friend BaseT;
  const CCGSubtarget *ST;
  const TargetLowering *TLI;

public:
  explicit CCGTTIImpl(const CCGTargetMachine *TM, const Function &F)
      : BaseT(TM, F.getParent()->getDataLayout()),
        ST(TM->getSubtargetImpl(F)), TLI(ST->getTargetLowering()) {}

  const CCGSubtarget *getST() const { return ST; }
  const TargetLowering *getTLI() const { return TLI; }

  /// §1: lanes have independent PCs and regroup only where those coincide, so
  /// branch divergence is the machine's normal state rather than an exception.
  bool hasBranchDivergence(const Function * = nullptr) const { return true; }

  bool isSourceOfDivergence(const Value *V) const;

  /// A value that is uniform stays uniform when read back, so nothing here
  /// needs the "always uniform" escape hatch yet.
  bool isAlwaysUniform(const Value *) const { return false; }
};

} // namespace llvm
#endif
