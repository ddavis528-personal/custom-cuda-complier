//===-- CCGISelDAGToDAG.cpp - CCG instruction selection ------------------===//
#include "CCGISelLowering.h"
#include "CCGSubtarget.h"
#include "CCGTargetMachine.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/IR/IntrinsicsNVPTX.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

#define DEBUG_TYPE "ccg-isel"

namespace {

class CCGDAGToDAGISel : public SelectionDAGISel {
public:
  static char ID;
  CCGDAGToDAGISel(CCGTargetMachine &TM, CodeGenOptLevel OL)
      : SelectionDAGISel(ID, TM, OL) {}

  void Select(SDNode *N) override;
  bool selectAddrBaseIdx(SDValue Addr, SDValue &Base, SDValue &Idx);
  StringRef getPassName() const override { return "CCG DAG->DAG pattern instruction selection"; }

#include "CCGGenDAGISel.inc"
};

char CCGDAGToDAGISel::ID = 0;

} // namespace

/// Match the address shape CCGLowerKernelArgs leaves for a global pointer:
///
///     (rbase << 16) + (idx << 2)        -- aligned, O-23
///     ((rbase << 16) + roffset) + ...   -- unaligned
///
/// Format D base+index computes (rbase << 16) + (rindex << scale) + disp, with
/// the base shift coming from the address space rather than a field (§5.1), so
/// a match here consumes the whole shape and the 48-bit width never reaches a
/// register (invariant 11).
bool CCGDAGToDAGISel::selectAddrBaseIdx(SDValue Addr, SDValue &Base,
                                        SDValue &Idx) {
  if (Addr.getOpcode() != ISD::ADD)
    return false;

  // One side must be the window: a shl-by-16 of a zero-extended 32-bit value.
  auto matchWindow = [](SDValue V, SDValue &Out) {
    if (V.getOpcode() != ISD::SHL)
      return false;
    auto *C = dyn_cast<ConstantSDNode>(V.getOperand(1));
    if (!C || C->getZExtValue() != 16)
      return false;
    SDValue Inner = V.getOperand(0);
    if (Inner.getOpcode() == ISD::ZERO_EXTEND || Inner.getOpcode() == ISD::ANY_EXTEND)
      Inner = Inner.getOperand(0);
    if (Inner.getValueType() != MVT::i32)
      return false;
    Out = Inner;
    return true;
  };

  SDValue Other;
  if (matchWindow(Addr.getOperand(0), Base))
    Other = Addr.getOperand(1);
  else if (matchWindow(Addr.getOperand(1), Base))
    Other = Addr.getOperand(0);
  else
    return false;

  // The index side is a 32-bit element index, possibly extended.
  if (Other.getOpcode() == ISD::ZERO_EXTEND || Other.getOpcode() == ISD::SIGN_EXTEND ||
      Other.getOpcode() == ISD::ANY_EXTEND)
    Other = Other.getOperand(0);
  if (Other.getValueType() != MVT::i32)
    return false;

  Idx = Other;
  return true;
}

void CCGDAGToDAGISel::Select(SDNode *N) {
  if (N->isMachineOpcode()) {
    N->setNodeId(-1);
    return;
  }
  SDLoc DL(N);

  switch (N->getOpcode()) {
  case CCGISD::RET: {
    // A kernel ends with `exit` -- 16 bits, no operand content (§3,
    // invariant 7). Kernels return void, so there are no return registers to
    // carry through; a value-returning device function needs the calling
    // sequence, which is Step 4 (see roadmap F-21).
    if (N->getNumOperands() > 1)
      report_fatal_error("CCG: value-returning functions need the calling "
                         "sequence (roadmap F-21)");
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCG::C_EXIT, DL, MVT::Other,
                       CurDAG->getTargetConstant(0, DL, MVT::i32),
                       N->getOperand(0)));
    return;
  }
  case ISD::INTRINSIC_WO_CHAIN: {
    // §5.3: the launch block supplies anything known at launch; only thread and
    // CTA identity need an instruction. ntid comes from the block and is
    // already a load by this point, so only these two reach selection.
    unsigned IID = N->getConstantOperandVal(0);
    int Sel = -1;
    if (IID == Intrinsic::nvvm_read_ptx_sreg_tid_x)
      Sel = 0;   // %ctatid
    else if (IID == Intrinsic::nvvm_read_ptx_sreg_ctaid_x)
      Sel = 1;   // %ctaid
    if (Sel >= 0) {
      ReplaceNode(N, CurDAG->getMachineNode(
                         CCG::SRD, DL, MVT::i32,
                         CurDAG->getTargetConstant(Sel, DL, MVT::i32)));
      return;
    }
    break;
  }
  }
  SelectCode(N);
}

namespace llvm {
FunctionPass *createCCGISelDag(CCGTargetMachine &TM, CodeGenOptLevel OL) {
  return new CCGDAGToDAGISel(TM, OL);
}
} // namespace llvm
