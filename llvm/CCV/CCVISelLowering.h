//===-- CCVISelLowering.h ---------------------------------------*- C++ -*-===//
#ifndef CCV_CCVISELLOWERING_H
#define CCV_CCVISELLOWERING_H

#include "llvm/CodeGen/TargetLowering.h"
#include "llvm/CodeGen/ValueTypes.h"

namespace llvm {
class CCVSubtarget;

namespace CCVISD {
enum NodeType : unsigned {
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,       ///< kernel/function return
  SRD,       ///< identity / dynamic state read (§5.3)
  LD_BASEIDX, ///< load  from (rbase << 16) + idx  -- chain, rbase, idx
  ST_BASEIDX, ///< store to   (rbase << 16) + idx  -- chain, value, rbase, idx
  LD_BASEOFF, ///< load  from (rbase << 16) + off  -- chain, rbase, off
  ST_BASEOFF, ///< store to   (rbase << 16) + off  -- chain, value, rbase, off
};
} // namespace CCVISD

class CCVTargetLowering : public TargetLowering {
public:
  explicit CCVTargetLowering(const TargetMachine &TM, const CCVSubtarget &STI);

  /// A compare writes a predicate, and a predicate is one bit per lane at every
  /// chwidth (invariant 5). The default here is a pointer-sized integer, which
  /// on a 64-bit pointer target means setcc produces an i64 that then has to be
  /// truncated -- reintroducing the 64-bit value invariant 11 exists to
  /// prevent. i1 is both correct and the only representable answer.
  EVT getSetCCResultType(const DataLayout &, LLVMContext &,
                         EVT VT) const override {
    return MVT::i1;
  }

  SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
                               bool IsVarArg,
                               const SmallVectorImpl<ISD::InputArg> &Ins,
                               const SDLoc &DL, SelectionDAG &DAG,
                               SmallVectorImpl<SDValue> &InVals) const override;
  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      const SmallVectorImpl<SDValue> &OutVals, const SDLoc &DL,
                      SelectionDAG &DAG) const override;
  SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const override;
  SDValue PerformDAGCombine(SDNode *N, DAGCombinerInfo &DCI) const override;
  const char *getTargetNodeName(unsigned Opcode) const override;

  /// 'r' is a GPR. Predicates are a separate namespace (invariant 5) and get
  /// their own constraint letter when if-conversion needs one.
  std::pair<unsigned, const TargetRegisterClass *>
  getRegForInlineAsmConstraint(const TargetRegisterInfo *TRI,
                               StringRef Constraint, MVT VT) const override;

  /// Shift amounts are 32-bit. The default is the pointer type, which is 64
  /// bits here (§5.1) -- but no register holds 64 bits (invariant 11), so the
  /// default produces shifts that cannot be selected.
  MVT getScalarShiftAmountTy(const DataLayout &, EVT) const override {
    return MVT::i32;
  }
};
} // namespace llvm
#endif
