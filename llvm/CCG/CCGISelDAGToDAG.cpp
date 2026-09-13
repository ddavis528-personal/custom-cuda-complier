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
  case CCGISD::LD_BASEIDX:
  case CCGISD::ST_BASEIDX: {
    // (rbase << 16) + (idx << scale) is exactly Format D base+index, with the
    // base shift coming from the address space rather than a field (§5.1). The
    // 48-bit width therefore exists only in the AGU -- invariant 11 holds all
    // the way down, and no register ever holds an address.
    bool IsLoad = N->getOpcode() == CCGISD::LD_BASEIDX;
    SmallVector<SDValue, 6> Ops;
    unsigned ScaleOp;
    if (IsLoad) {
      Ops.push_back(N->getOperand(1));                              // rbase
      Ops.push_back(N->getOperand(2));                              // rindex
      ScaleOp = 3;
    } else {
      Ops.push_back(N->getOperand(1));                              // value
      Ops.push_back(N->getOperand(2));                              // rbase
      Ops.push_back(N->getOperand(3));                              // rindex
      ScaleOp = 4;
    }
    // scale-enable, decided by the matcher: set when the index is an element
    // index, so the AGU supplies the chwidth-derived shift (O-7); clear when
    // it is a byte offset, which is the unaligned shape (O-23).
    Ops.push_back(N->getOperand(ScaleOp));
    Ops.push_back(CurDAG->getTargetConstant(0, DL, MVT::i32));      // disp
    Ops.push_back(N->getOperand(0));                                // chain

    MachineSDNode *MN =
        IsLoad ? CurDAG->getMachineNode(CCG::LD_GLOBAL_IDX, DL,
                                        N->getValueType(0), MVT::Other, Ops)
               : CurDAG->getMachineNode(CCG::ST_GLOBAL_IDX, DL, MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case CCGISD::LD_BASEOFF:
  case CCGISD::ST_BASEOFF: {
    bool IsLoad = N->getOpcode() == CCGISD::LD_BASEOFF;
    SmallVector<SDValue, 5> Ops;
    if (IsLoad) {
      Ops.push_back(N->getOperand(1));   // rbase
      Ops.push_back(N->getOperand(2));   // offset
    } else {
      Ops.push_back(N->getOperand(1));   // value
      Ops.push_back(N->getOperand(2));   // rbase
      Ops.push_back(N->getOperand(3));   // offset
    }
    Ops.push_back(N->getOperand(0));     // chain
    MachineSDNode *MN =
        IsLoad ? CurDAG->getMachineNode(CCG::LD_GLOBAL, DL, N->getValueType(0),
                                        MVT::Other, Ops)
               : CurDAG->getMachineNode(CCG::ST_GLOBAL, DL, MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case ISD::SETCC: {
    // O-24: there is no unpredicated compare, and no hardwired always-true
    // predicate, so a guard has to be manufactured. PSEUDO_PTRUE supplies one
    // and the tie on PSEUDO_SETP forces it into the compare's own destination
    // -- the self-guarding form, which costs one predicate rather than two.
    ISD::CondCode CC = cast<CondCodeSDNode>(N->getOperand(2))->get();
    SDValue LHS = N->getOperand(0), RHS = N->getOperand(1);
    unsigned Opc;
    // gt/ge are lt/le with the operands swapped -- §3 allocates 18 setp points
    // and there is no reason to spend two of them on reversible predicates.
    switch (CC) {
    case ISD::SETLT: Opc = CCG::PSEUDO_SETP_LT; break;
    case ISD::SETLE: Opc = CCG::PSEUDO_SETP_LE; break;
    case ISD::SETEQ: Opc = CCG::PSEUDO_SETP_EQ; break;
    case ISD::SETNE: Opc = CCG::PSEUDO_SETP_NE; break;
    case ISD::SETGT: Opc = CCG::PSEUDO_SETP_LT; std::swap(LHS, RHS); break;
    case ISD::SETGE: Opc = CCG::PSEUDO_SETP_LE; std::swap(LHS, RHS); break;
    // Unsigned. eq/ne are the signed points: they compare bit patterns.
    case ISD::SETULT: Opc = CCG::PSEUDO_SETP_LT_U; break;
    case ISD::SETULE: Opc = CCG::PSEUDO_SETP_LE_U; break;
    case ISD::SETUGT: Opc = CCG::PSEUDO_SETP_LT_U; std::swap(LHS, RHS); break;
    case ISD::SETUGE: Opc = CCG::PSEUDO_SETP_LE_U; std::swap(LHS, RHS); break;
    // FP. `eq.f` is ordered-equal and `ne.f` its exact complement, so `une`
    // -- what C's `!=` produces -- is the natural point rather than a
    // negation. Swapping operands is safe for the ordered relations: NaN makes
    // both directions false either way.
    case ISD::SETOLT: Opc = CCG::PSEUDO_SETP_LT_F; break;
    case ISD::SETOLE: Opc = CCG::PSEUDO_SETP_LE_F; break;
    case ISD::SETOGT: Opc = CCG::PSEUDO_SETP_LT_F; std::swap(LHS, RHS); break;
    case ISD::SETOGE: Opc = CCG::PSEUDO_SETP_LE_F; std::swap(LHS, RHS); break;
    case ISD::SETOEQ: Opc = CCG::PSEUDO_SETP_EQ_F; break;
    case ISD::SETUNE: Opc = CCG::PSEUDO_SETP_NE_F; break;
    default:
      // SETONE, SETUEQ, SETO, SETUO and the unordered inequalities need either
      // two compares or opcode points the map does not spend. Diagnosed rather
      // than miscompiled; see F-24.
      report_fatal_error("CCG: condition code " + Twine(unsigned(CC)) +
                         " not implemented -- ordered/unordered FP variants "
                         "beyond olt/ole/ogt/oge/oeq/une are roadmap F-24");
    }
    SDNode *True = CurDAG->getMachineNode(CCG::PSEUDO_PTRUE, DL, MVT::i1);
    ReplaceNode(N, CurDAG->getMachineNode(Opc, DL, MVT::i1,
                                          {SDValue(True, 0), LHS, RHS}));
    return;
  }
  case ISD::BRCOND: {
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCG::PSEUDO_BRA_PRED, DL, MVT::Other,
                       {N->getOperand(1),
                        CurDAG->getTargetConstant(0, DL, MVT::i32),
                        N->getOperand(2), N->getOperand(0)}));
    return;
  }
  case ISD::INTRINSIC_VOID: {
    // __syncthreads() is an arrive followed by a wait on the same barrier
    // (O-12): arriving and blocking are separate operations here, because with
    // per-thread PCs a thread arrives individually.
    if (N->getConstantOperandVal(1) != Intrinsic::nvvm_barrier0)
      break;
    // Format K payload. bar.arrive: [13:8] is the 6-bit barrier ID, so the ID
    // sits in payload bits [5:0]. bar.wait adds the phase parity at [14],
    // which is payload bit [6].
    const unsigned BarrierID = 0;      // one CTA-wide barrier; see F-30
    const unsigned Phase = 0;
    SDValue Chain = N->getOperand(0);
    SDNode *Arrive = CurDAG->getMachineNode(
        CCG::C_BAR_ARRIVE, DL, MVT::Other,
        {CurDAG->getTargetConstant(BarrierID, DL, MVT::i32), Chain});
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCG::C_BAR_WAIT, DL, MVT::Other,
                       {CurDAG->getTargetConstant(BarrierID | (Phase << 6), DL,
                                                  MVT::i32),
                        SDValue(Arrive, 0)}));
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
