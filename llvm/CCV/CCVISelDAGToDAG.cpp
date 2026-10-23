//===-- CCVISelDAGToDAG.cpp - CCV instruction selection ------------------===//
#include "CCVISelLowering.h"
#include "llvm/Support/CommandLine.h"
#include "CCVFrameLowering.h"
#include "CCVSubtarget.h"
#include "CCVTargetMachine.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/IR/IntrinsicsNVPTX.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

#define DEBUG_TYPE "ccv-isel"

namespace {

class CCVDAGToDAGISel : public SelectionDAGISel {
public:
  static char ID;
  CCVDAGToDAGISel(CCVTargetMachine &TM, CodeGenOptLevel OL)
      : SelectionDAGISel(ID, TM, OL) {}

  void Select(SDNode *N) override;
  bool selectAddrBaseIdx(SDValue Addr, SDValue &Base, SDValue &Idx);
  StringRef getPassName() const override { return "CCV DAG->DAG pattern instruction selection"; }

#include "CCVGenDAGISel.inc"
};

char CCVDAGToDAGISel::ID = 0;

} // namespace

/// Match the address shape CCVLowerKernelArgs leaves for a global pointer:
///
///     (rbase << 16) + (idx << 2)        -- aligned, O-23
///     ((rbase << 16) + roffset) + ...   -- unaligned
///
/// Format D base+index computes (rbase << 16) + (rindex << scale) + disp, with
/// the base shift coming from the address space rather than a field (§5.1), so
/// a match here consumes the whole shape and the 48-bit width never reaches a
/// register (invariant 11).
bool CCVDAGToDAGISel::selectAddrBaseIdx(SDValue Addr, SDValue &Base,
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

/// The Format C" immediate twin of an unpredicated compare, or 0 when the point
/// has none this compiler can reach. gt/ge are absent deliberately: they are
/// selected by swapping the operands, which puts the constant on the left.
static unsigned immediateCompare(unsigned Opc) {
  switch (Opc) {
  case CCV::SETP_LT_NP:   return CCV::SETP_LT_NPI;
  case CCV::SETP_LE_NP:   return CCV::SETP_LE_NPI;
  case CCV::SETP_EQ_NP:   return CCV::SETP_EQ_NPI;
  case CCV::SETP_NE_NP:   return CCV::SETP_NE_NPI;
  case CCV::SETP_LT_U_NP: return CCV::SETP_LT_U_NPI;
  case CCV::SETP_LE_U_NP: return CCV::SETP_LE_U_NPI;
  case CCV::SETP_LT_F_NP: return CCV::SETP_LT_F_NPI;
  case CCV::SETP_LE_F_NP: return CCV::SETP_LE_F_NPI;
  case CCV::SETP_EQ_F_NP: return CCV::SETP_EQ_F_NPI;
  case CCV::SETP_NE_F_NP: return CCV::SETP_NE_F_NPI;
  default:                return 0;
  }
}

/// A memory access's opcode at its element width. §3 takes the transfer size
/// from `rdata`'s chwidth, so a 16- or 8-bit access must select the twin whose
/// data operand is GPR16 or GPR8: the 32-bit form moves four bytes and
/// clobbers the neighbouring elements with nothing downstream noticing (F-125,
/// F-111). One table for every addressing path, so no path can miss a width
/// again -- the frame path had no narrow form at all until F-161.
// Mutation control for tools/check-bytes.sh: byte accesses select the 32-bit
// forms, so every transfer moves four bytes. It must be caught by the values.
static cl::opt<bool> TestBytesAt32(
    "ccv-test-bytes-at-32", cl::init(false), cl::Hidden,
    cl::desc("select 32-bit forms for byte accesses, to test that it is caught"));

static unsigned atWidth(unsigned Opc, EVT MemVT) {
  if (TestBytesAt32 && MemVT == MVT::i8)
    return Opc;
  const bool W16 = MemVT == MVT::i16, W8 = MemVT == MVT::i8;
  switch (Opc) {
  case CCV::LD_GLOBAL:
    return W16 ? CCV::LD_GLOBAL_W16 : W8 ? CCV::LD_GLOBAL_W8 : CCV::LD_GLOBAL;
  case CCV::ST_GLOBAL:
    return W16 ? CCV::ST_GLOBAL_W16 : W8 ? CCV::ST_GLOBAL_W8 : CCV::ST_GLOBAL;
  case CCV::LD_GLOBAL_IDX:
    return W16 ? CCV::LD_GLOBAL_IDX_W16 : W8 ? CCV::LD_GLOBAL_IDX_W8 : CCV::LD_GLOBAL_IDX;
  case CCV::ST_GLOBAL_IDX:
    return W16 ? CCV::ST_GLOBAL_IDX_W16 : W8 ? CCV::ST_GLOBAL_IDX_W8 : CCV::ST_GLOBAL_IDX;
  case CCV::LD_GLOBAL_SLOT:
    return W16 ? CCV::LD_GLOBAL_SLOT_W16 : W8 ? CCV::LD_GLOBAL_SLOT_W8 : CCV::LD_GLOBAL_SLOT;
  case CCV::ST_GLOBAL_SLOT:
    return W16 ? CCV::ST_GLOBAL_SLOT_W16 : W8 ? CCV::ST_GLOBAL_SLOT_W8 : CCV::ST_GLOBAL_SLOT;
  default:
    return Opc;
  }
}

/// O-72's RMW point for an operation, in §3's order (add, min.s, min.u, max.s,
/// max.u, and, or, xor, exch), and an address space.
static unsigned atomOpcode(unsigned Kind, bool Shared) {
  switch (Kind) {
  case 0:  return Shared ? CCV::ATOM_ADD_S : CCV::ATOM_ADD_G;
  case 1:  return Shared ? CCV::ATOM_MIN_S_S : CCV::ATOM_MIN_S_G;
  case 2:  return Shared ? CCV::ATOM_MIN_U_S : CCV::ATOM_MIN_U_G;
  case 3:  return Shared ? CCV::ATOM_MAX_S_S : CCV::ATOM_MAX_S_G;
  case 4:  return Shared ? CCV::ATOM_MAX_U_S : CCV::ATOM_MAX_U_G;
  case 5:  return Shared ? CCV::ATOM_AND_S : CCV::ATOM_AND_G;
  case 6:  return Shared ? CCV::ATOM_OR_S : CCV::ATOM_OR_G;
  case 7:  return Shared ? CCV::ATOM_XOR_S : CCV::ATOM_XOR_G;
  default: return Shared ? CCV::ATOM_EXCH_S : CCV::ATOM_EXCH_G;
  }
}

void CCVDAGToDAGISel::Select(SDNode *N) {
  if (N->isMachineOpcode()) {
    N->setNodeId(-1);
    return;
  }
  SDLoc DL(N);

  switch (N->getOpcode()) {
  case CCVISD::CODEADDR:
    // A function's code address: a `movi` the asm printer gives its
    // link-time value (F-21 step 5).
    ReplaceNode(N, CurDAG->getMachineNode(CCV::MOVI, DL, MVT::i32,
                                          N->getOperand(0)));
    return;
  case CCVISD::FRAMEOFF:
    // movi of a frame object; eliminateFrameIndex makes it the offset.
    ReplaceNode(N, CurDAG->getMachineNode(CCV::MOVI, DL, MVT::i32,
                                          N->getOperand(0)));
    return;
  case CCVISD::CALL: {
    // An indirect call targets its function's `ret` stub, an MCSymbol, which
    // the i32-typed declarative pattern cannot match (mcsym is pointer-typed).
    if (!isa<MCSymbolSDNode>(N->getOperand(1)))
      break;
    SmallVector<SDValue, 8> Ops;
    unsigned E = N->getNumOperands();
    bool HasGlue = N->getOperand(E - 1).getValueType() == MVT::Glue;
    for (unsigned I = 1, Last = HasGlue ? E - 1 : E; I != Last; ++I)
      Ops.push_back(N->getOperand(I));
    Ops.push_back(N->getOperand(0));
    if (HasGlue)
      Ops.push_back(N->getOperand(E - 1));
    ReplaceNode(N, CurDAG->getMachineNode(CCV::PSEUDO_CALL, DL, N->getVTList(), Ops));
    return;
  }
  case CCVISD::RET: {
    // A device function returns through its link value, operand 1, carrying
    // the return registers as uses so they stay live to the `ret` (F-21).
    if (!ccvIsKernel(CurDAG->getMachineFunction().getFunction())) {
      SmallVector<SDValue, 6> Ops;
      unsigned E = N->getNumOperands();
      bool HasGlue = N->getOperand(E - 1).getValueType() == MVT::Glue;
      for (unsigned I = 1, Last = HasGlue ? E - 1 : E; I != Last; ++I)
        Ops.push_back(N->getOperand(I));
      Ops.push_back(N->getOperand(0));             // then the chain,
      if (HasGlue)
        Ops.push_back(N->getOperand(E - 1));       // then the glue
      ReplaceNode(N, CurDAG->getMachineNode(CCV::PSEUDO_RET, DL, MVT::Other,
                                            Ops));
      return;
    }
    // A kernel ends with `exit` -- 16 bits, no operand content (§3,
    // invariant 7). It returns nothing; LowerReturn refuses a value.
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCV::C_EXIT, DL, MVT::Other,
                       CurDAG->getTargetConstant(0, DL, MVT::i32),
                       N->getOperand(0)));
    return;
  }
  case CCVISD::LD_BASEIDX:
  case CCVISD::ST_BASEIDX: {
    // (rbase << 16) + (idx << scale) is exactly Format D base+index, with the
    // base shift coming from the address space rather than a field (§5.1). The
    // 48-bit width therefore exists only in the AGU -- invariant 11 holds all
    // the way down, and no register ever holds an address.
    bool IsLoad = N->getOpcode() == CCVISD::LD_BASEIDX;
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
    Ops.push_back(N->getOperand(ScaleOp + 1));                      // disp
    Ops.push_back(N->getOperand(0));                                // chain

    // §3 takes transfer size from `rdata`'s chwidth, so a 16-bit access has to
    // select the 16-bit form -- the instructions are otherwise identical and
    // encode identically (F-3).
    //
    // Getting this wrong is not a missed optimisation. A `short` array stored
    // through the 32-bit form writes FOUR bytes and clobbers the neighbouring
    // element, and the value written is still correct, so nothing downstream
    // notices. That is exactly what happened before this check existed.
    EVT MemVT = cast<MemSDNode>(N)->getMemoryVT();
    MachineSDNode *MN =
        IsLoad ? CurDAG->getMachineNode(atWidth(CCV::LD_GLOBAL_IDX, MemVT),
                                        DL, N->getValueType(0), MVT::Other, Ops)
               : CurDAG->getMachineNode(atWidth(CCV::ST_GLOBAL_IDX, MemVT),
                                        DL, MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case CCVISD::ATOM: {
    // O-72: operands chain, base, idx, scale, disp, value, op, shared.
    SDValue Ops[] = {N->getOperand(1), N->getOperand(2), N->getOperand(3),
                     N->getOperand(4), N->getOperand(5), N->getOperand(0)};
    MachineSDNode *MN = CurDAG->getMachineNode(
        atomOpcode(N->getConstantOperandVal(6), N->getConstantOperandVal(7)),
        DL, MVT::i32, MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case CCVISD::CAS: {
    // Operands chain, base, idx, scale, disp, cmp, swap, shared. Every lane
    // the warp runs takes part, so the guard is a predicate of all ones.
    SDValue All(CurDAG->getMachineNode(
                    CCV::PMOV_IMM, DL, MVT::i1,
                    CurDAG->getTargetConstant(0xFFFFFFFFu, DL, MVT::i32)),
                0);
    SDValue Ops[] = {All, N->getOperand(1), N->getOperand(2), N->getOperand(3),
                     N->getOperand(4), N->getOperand(5), N->getOperand(6),
                     N->getOperand(0)};
    MachineSDNode *MN = CurDAG->getMachineNode(
        N->getConstantOperandVal(7) ? CCV::PSEUDO_CAS_S : CCV::PSEUDO_CAS_G, DL,
        MVT::i32, MVT::i1, MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case ISD::ATOMIC_FENCE: {
    // §3's fence: scope at [10:8] and ordering at [12:11], payload bits
    // [2:0] and [4:3], with O-73's codes: scope 0 CTA, 1 device, 2 system;
    // ordering 0 sequentially consistent, 1 acquire, 2 release, 3
    // acquire-release. A single-thread fence orders nothing the hardware sees.
    auto Ord = AtomicOrdering(N->getConstantOperandVal(1));
    auto Scope = SyncScope::ID(N->getConstantOperandVal(2));
    if (Scope == SyncScope::SingleThread) {
      ReplaceUses(SDValue(N, 0), N->getOperand(0));
      CurDAG->RemoveDeadNode(N);
      return;
    }
    unsigned ScopeCode = 2;
    SmallVector<StringRef, 8> Names;
    CurDAG->getContext()->getSyncScopeNames(Names);
    if (Scope < Names.size()) {
      StringRef Nm = Names[Scope];
      if (Nm == "block" || Nm == "cta" || Nm == "workgroup")
        ScopeCode = 0;
      else if (Nm == "device" || Nm == "gpu" || Nm == "agent")
        ScopeCode = 1;
    }
    unsigned OrdCode = Ord == AtomicOrdering::Acquire          ? 1
                       : Ord == AtomicOrdering::Release        ? 2
                       : Ord == AtomicOrdering::AcquireRelease ? 3
                                                               : 0;
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCV::C_FENCE, DL, MVT::Other,
                       {CurDAG->getTargetConstant(ScopeCode | OrdCode << 3, DL,
                                                  MVT::i32),
                        N->getOperand(0)}));
    return;
  }
  case CCVISD::DP4_SS: {
    // §3: all three operands are ordinary chwidth=32 registers. The packing is
    // in the opcode and nothing outside it can observe the packed view, so
    // there is no register class or width to arrange here. CCVCompress folds
    // this to Format J's `dp4.acc` wherever the allocator lands the
    // accumulator on the destination.
    ReplaceNode(N, CurDAG->getMachineNode(CCV::DP4_SS, DL, MVT::i32,
                                          {N->getOperand(0), N->getOperand(1),
                                           N->getOperand(2)}));
    return;
  }
  case CCVISD::LD_SLOTIDX:
  case CCVISD::ST_SLOTIDX: {
    // O-45. Same shape as base+index, with a 4-bit launch-slot immediate where
    // `rbase` would be.
    bool IsLoad = N->getOpcode() == CCVISD::LD_SLOTIDX;
    SmallVector<SDValue, 6> Ops;
    unsigned B = IsLoad ? 1 : 2;              // first non-chain/value operand
    if (!IsLoad)
      Ops.push_back(N->getOperand(1));        // value
    Ops.push_back(N->getOperand(B));          // slot
    Ops.push_back(N->getOperand(B + 1));      // rindex
    Ops.push_back(N->getOperand(B + 2));      // scale enable
    Ops.push_back(N->getOperand(B + 3));      // disp
    Ops.push_back(N->getOperand(0));          // chain
    // Transfer size comes from `rdata`'s chwidth, so a 16-bit access must select
    // the narrow form to put its data register in GPR16 (F-125, and F-139 for
    // the repeat).
    EVT MemVT = cast<MemSDNode>(N)->getMemoryVT();
    MachineSDNode *MN =
        IsLoad ? CurDAG->getMachineNode(atWidth(CCV::LD_GLOBAL_SLOT, MemVT),
                                        DL, N->getValueType(0), MVT::Other, Ops)
               : CurDAG->getMachineNode(atWidth(CCV::ST_GLOBAL_SLOT, MemVT),
                                        DL, MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case CCVISD::LD_FRAME:
  case CCVISD::ST_FRAME: {
    // A .local access. R15 is the window base (O-30) and eliminateFrameIndex
    // supplies it, so what is selected here is an ordinary Format D access
    // whose base operand happens to still be a frame index.
    //
    // A constant index is a displacement -- it folds into the frame offset
    // eliminateFrameIndex already adds -- so it takes the base+offset form and
    // only a dynamic index needs base+index. That is what keeps an ordinary
    // scalar local variable costing exactly what a spill slot costs.
    bool IsLoad = N->getOpcode() == CCVISD::LD_FRAME;
    unsigned FIOp = IsLoad ? 1 : 2;
    SDValue Base = N->getOperand(FIOp), Idx = N->getOperand(FIOp + 1);

    SDValue Disp = N->getOperand(FIOp + 3);
    SmallVector<SDValue, 6> Ops;
    if (!IsLoad)
      Ops.push_back(N->getOperand(1));                    // value
    Ops.push_back(Base);
    unsigned Opc;
    if (Idx.isUndef()) {
      // No dynamic term: the whole address is a displacement, and
      // eliminateFrameIndex folds the frame offset into it.
      Opc = IsLoad ? CCV::LD_GLOBAL : CCV::ST_GLOBAL;
      Ops.push_back(Disp);
    } else {
      Opc = IsLoad ? CCV::LD_GLOBAL_IDX : CCV::ST_GLOBAL_IDX;
      Ops.push_back(Idx);
      Ops.push_back(N->getOperand(FIOp + 2));             // scale enable
      Ops.push_back(Disp);
    }
    Ops.push_back(N->getOperand(0));                      // chain

    Opc = atWidth(Opc, cast<MemSDNode>(N)->getMemoryVT());
    MachineSDNode *MN =
        IsLoad ? CurDAG->getMachineNode(Opc, DL, N->getValueType(0), MVT::Other,
                                        Ops)
               : CurDAG->getMachineNode(Opc, DL, MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case CCVISD::LD_BASEOFF:
  case CCVISD::ST_BASEOFF: {
    bool IsLoad = N->getOpcode() == CCVISD::LD_BASEOFF;
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
    // Transfer size comes from `rdata`'s chwidth, exactly as in the base+index
    // case above -- and this path did not check. A `short` store through it
    // selected the 32-bit form, wrote FOUR bytes and clobbered the neighbouring
    // element with a correct value in the wrong place, which is the silent
    // failure the comment above describes having already been fixed once. The
    // base+index path got the check; this one was missed, and F-111's audit
    // found it by noticing that nothing could produce LD_GLOBAL_W16 or
    // ST_GLOBAL_W16.
    EVT MemVT = cast<MemSDNode>(N)->getMemoryVT();
    MachineSDNode *MN =
        IsLoad ? CurDAG->getMachineNode(atWidth(CCV::LD_GLOBAL, MemVT),
                                        DL, N->getValueType(0), MVT::Other, Ops)
               : CurDAG->getMachineNode(atWidth(CCV::ST_GLOBAL, MemVT), DL,
                                        MVT::Other, Ops);
    CurDAG->setNodeMemRefs(MN, {cast<MemSDNode>(N)->getMemOperand()});
    ReplaceNode(N, MN);
    return;
  }
  case ISD::TRUNCATE: {
    // The low bit as a predicate. The combiner makes `(x & 1) == 0`, which a
    // select between two function pointers produced (F-21 step 5), into a
    // truncate to i1; it is (x & 1) != 0, an `andi` and an immediate compare.
    if (N->getValueType(0) != MVT::i1)
      break;
    SDNode *And = CurDAG->getMachineNode(
        CCV::ANDI, DL, MVT::i32,
        {N->getOperand(0), CurDAG->getTargetConstant(1, DL, MVT::i32)});
    ReplaceNode(N, CurDAG->getMachineNode(
                       immediateCompare(CCV::SETP_NE_NP), DL, MVT::i1, MVT::i32,
                       {SDValue(And, 0), CurDAG->getTargetConstant(0, DL, MVT::i32)}));
    return;
  }
  case ISD::SETCC: {
    // O-32: Format C" is unpredicated, so a compare is one instruction. It used
    // to be two -- Formats C and C' carry a mandatory qualifier and there is no
    // always-true predicate (§1), so every compare manufactured its own guard
    // with `por pd, !pd, pd` first (O-24). That cost 13% of dynamically issued
    // instructions in the reduction kernels, which is what paid for the format.
    //
    // The predicated forms remain, and are what if-conversion would select;
    // nothing selects them today.
    ISD::CondCode CC = cast<CondCodeSDNode>(N->getOperand(2))->get();
    SDValue LHS = N->getOperand(0), RHS = N->getOperand(1);
    unsigned Opc;
    // gt/ge are lt/le with the operands swapped -- §3 allocates 16 setp points
    // and there is no reason to spend two of them on reversible predicates.
    switch (CC) {
    case ISD::SETLT: Opc = CCV::SETP_LT_NP; break;
    case ISD::SETLE: Opc = CCV::SETP_LE_NP; break;
    case ISD::SETEQ: Opc = CCV::SETP_EQ_NP; break;
    case ISD::SETNE: Opc = CCV::SETP_NE_NP; break;
    case ISD::SETGT: Opc = CCV::SETP_LT_NP; std::swap(LHS, RHS); break;
    case ISD::SETGE: Opc = CCV::SETP_LE_NP; std::swap(LHS, RHS); break;
    // Unsigned. eq/ne are the signed points: they compare bit patterns.
    case ISD::SETULT: Opc = CCV::SETP_LT_U_NP; break;
    case ISD::SETULE: Opc = CCV::SETP_LE_U_NP; break;
    case ISD::SETUGT: Opc = CCV::SETP_LT_U_NP; std::swap(LHS, RHS); break;
    case ISD::SETUGE: Opc = CCV::SETP_LE_U_NP; std::swap(LHS, RHS); break;
    // FP. `eq.f` is ordered-equal and `ne.f` its exact complement, so `une`
    // -- what C's `!=` produces -- is the natural point rather than a
    // negation. Swapping operands is safe for the ordered relations: NaN makes
    // both directions false either way.
    case ISD::SETOLT: Opc = CCV::SETP_LT_F_NP; break;
    case ISD::SETOLE: Opc = CCV::SETP_LE_F_NP; break;
    case ISD::SETOGT: Opc = CCV::SETP_LT_F_NP; std::swap(LHS, RHS); break;
    case ISD::SETOGE: Opc = CCV::SETP_LE_F_NP; std::swap(LHS, RHS); break;
    case ISD::SETOEQ: Opc = CCV::SETP_EQ_F_NP; break;
    case ISD::SETUNE: Opc = CCV::SETP_NE_F_NP; break;
    default:
      // SETONE, SETUEQ, SETO, SETUO and the unordered inequalities need either
      // two compares or opcode points the map does not spend. Diagnosed rather
      // than miscompiled; see F-24.
      report_fatal_error("CCV: condition code " + Twine(unsigned(CC)) +
                         " not implemented -- ordered/unordered FP variants "
                         "beyond olt/ole/ogt/oge/oeq/une are roadmap F-24");
    }
    // Format C" also has an immediate form, and until F-111's audit nothing
    // selected it: the encoding existed, §3 documented it, the simulator
    // executed it, and every `i < n` against a constant still paid a `movi`
    // first. The field is 8 bits signed, and it is only reachable when the
    // constant did not end up on the LEFT -- the gt/ge cases above put it
    // there, and `k < x` has no immediate form. Those points are unreachable
    // by construction; see F-115.
    if (unsigned ImmOpc = immediateCompare(Opc)) {
      std::optional<int64_t> K;
      if (auto *C = dyn_cast<ConstantSDNode>(RHS)) {
        if (isInt<8>(C->getSExtValue()))
          K = C->getSExtValue();
      } else if (auto *C = dyn_cast<ConstantFPSDNode>(RHS)) {
        // A float immediate is a BIT PATTERN in the same 8-bit field, so the
        // only comparands it reaches are the ones whose encoding is small.
        // 0.0f is the one that occurs, and it is the one that matters; -0.0f
        // has the sign bit set and does not fit, which is correct rather than
        // unfortunate -- `x < -0.0f` is not `x < 0.0f`.
        APInt Bits = C->getValueAPF().bitcastToAPInt();
        if (Bits.getBitWidth() == 32 && isInt<8>(Bits.getSExtValue()))
          K = Bits.getSExtValue();
      }
      if (K) {
        SDNode *New = CurDAG->getMachineNode(
            ImmOpc, DL, MVT::i1, MVT::i32,
            {LHS, CurDAG->getTargetConstant(*K, DL, MVT::i32)});
        ReplaceNode(N, SDValue(New, 0).getNode());
        return;
      }
    }
    // Two results: the predicate, and the materialization destination §3 says
    // is always allocated but which these opcodes do not write.
    SDNode *New = CurDAG->getMachineNode(Opc, DL, MVT::i1, MVT::i32,
                                         {LHS, RHS});
    ReplaceNode(N, SDValue(New, 0).getNode());
    return;
  }
  case ISD::ADD:
  case ISD::SUB: {
    // x + zext c, or x - zext c: one predicated add of +1 or -1 rather than
    // the predicate materialized as 0/1 and then added. The carry of a
    // 64-bit add and the borrow of a subtract are this shape (IS-13 (2)).
    if (N->getValueType(0) != MVT::i32)
      break;
    auto IsBit = [](SDValue V) {
      return (V.getOpcode() == ISD::ZERO_EXTEND ||
              V.getOpcode() == ISD::ANY_EXTEND) &&
             V.getOperand(0).getValueType() == MVT::i1;
    };
    SDValue X = N->getOperand(0), C = N->getOperand(1);
    if (N->getOpcode() == ISD::ADD && !IsBit(C) && IsBit(X))
      std::swap(X, C);
    if (!IsBit(C))
      break;
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCV::PSEUDO_PADDI, DL, MVT::i32,
                       {X, C.getOperand(0),
                        CurDAG->getTargetConstant(
                            N->getOpcode() == ISD::ADD ? 1 : -1, DL, MVT::i32)}));
    return;
  }
  case ISD::ZERO_EXTEND:
  case ISD::ANY_EXTEND: {
    // A predicate as 0 or 1: 0, plus 1 where the predicate holds -- two
    // instructions, where a select of two materialized constants took three.
    // (`x + zext c` itself, a stored pointer's carry (§5.7), is ISD::ADD's.)
    // At 16 bits (NVIDIA's software FP8/FP4 conversions, CP-6 stage 2b) it
    // is the 32-bit 0/1 read at width 16, as `trunc i32 -> i16` is.
    EVT VT = N->getValueType(0);
    if ((VT != MVT::i32 && VT != MVT::i16) ||
        N->getOperand(0).getValueType() != MVT::i1)
      break;
    SDValue Zero(CurDAG->getMachineNode(
                     CCV::MOVI, DL, MVT::i32,
                     CurDAG->getTargetConstant(0, DL, MVT::i32)),
                 0);
    SDNode *Bit = CurDAG->getMachineNode(
        CCV::PSEUDO_PADDI, DL, MVT::i32,
        {Zero, N->getOperand(0), CurDAG->getTargetConstant(1, DL, MVT::i32)});
    if (VT == MVT::i16)
      Bit = CurDAG->getMachineNode(TargetOpcode::COPY, DL, MVT::i16,
                                   SDValue(Bit, 0));
    ReplaceNode(N, Bit);
    return;
  }
  case ISD::SELECT: {
    // A select between predicates -- a 64-bit compare joining its halves'
    // compares (IS-13 (2)) -- is b ^ (c & (a ^ b)): three predicate
    // operations, where going through a GPR cost a materialized 0/1 per arm.
    if (N->getValueType(0) == MVT::i1) {
      auto P = [&](unsigned Opc, SDValue L, SDValue R) {
        return SDValue(CurDAG->getMachineNode(Opc, DL, MVT::i1, {L, R}), 0);
      };
      SDValue C = N->getOperand(0), A = N->getOperand(1), B = N->getOperand(2);
      ReplaceNode(N, P(CCV::PSEUDO_PXOR, B,
                       P(CCV::PSEUDO_PAND, C, P(CCV::PSEUDO_PXOR, A, B)))
                         .getNode());
      return;
    }
    // (select cond, a, b) -- cond is an i1 in a predicate register.
    if (N->getValueType(0) != MVT::i32 && N->getValueType(0) != MVT::f32)
      break;
    // Two-address: the FALSE arm is the tied input, so the excluded lanes keep
    // it for free under invariant 10 and only the true arm needs a write.
    // (select cond, a, b) -> PSEUDO_PMOV b, cond, a
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCV::PSEUDO_PMOV, DL, N->getValueType(0),
                       {N->getOperand(2), N->getOperand(0), N->getOperand(1)}));
    return;
  }
  case ISD::BR_CC: {
    // A branch on a predicate compared with a predicate: the combiner makes
    // `br (xor c, true)` into `br_cc setne c, true`, which a list walk's
    // `if (!found)` reached (the CoreMark-derived port). The branch's negate
    // bit is the comparison against a constant; two predicates are an xor.
    SDValue LHS = N->getOperand(2), RHS = N->getOperand(3);
    if (LHS.getValueType() != MVT::i1)
      break;
    ISD::CondCode CC = cast<CondCodeSDNode>(N->getOperand(1))->get();
    if (CC != ISD::SETEQ && CC != ISD::SETNE)
      report_fatal_error("CCV: ordered compare of two predicates");
    bool Neg = CC == ISD::SETEQ;
    SDValue Guard = LHS;
    if (auto *C = dyn_cast<ConstantSDNode>(RHS))
      Neg ^= C->isAllOnes();
    else
      Guard = SDValue(CurDAG->getMachineNode(CCV::PSEUDO_PXOR, DL, MVT::i1,
                                             {LHS, RHS}), 0);
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCV::PSEUDO_BRA_PRED, DL, MVT::Other,
                       {Guard, CurDAG->getTargetConstant(Neg, DL, MVT::i32),
                        N->getOperand(4), N->getOperand(0)}));
    return;
  }
  case ISD::BRCOND: {
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCV::PSEUDO_BRA_PRED, DL, MVT::Other,
                       {N->getOperand(1),
                        CurDAG->getTargetConstant(0, DL, MVT::i32),
                        N->getOperand(2), N->getOperand(0)}));
    return;
  }
  case ISD::INTRINSIC_VOID: {
    // __syncthreads() is an arrive followed by a wait on the same barrier
    // (O-12): arriving and blocking are separate operations here, because with
    // per-thread PCs a thread arrives individually. PTX's named barriers,
    // `bar.sync a{, b}` (`__syncthreads()` is a = 0 with no b), are the same
    // on barrier a, after `bar.init #a, b` (O-74): b lane arrivals complete a
    // phase, and no b, or b = 1024 (only legal in a CTA of exactly 1024,
    // where it is the same rule), is count 0, every live lane. Every use gets
    // its own bar.init; CCVBarrierInit then keeps one at the entry, or none,
    // wherever one count serves the whole kernel. CCVCheckIR has refused an
    // a or b that is not a constant in range.
    unsigned IID = N->getConstantOperandVal(1);
    if (IID != Intrinsic::nvvm_barrier0 && IID != Intrinsic::nvvm_bar_sync &&
        IID != Intrinsic::nvvm_barrier_sync && IID != Intrinsic::nvvm_barrier_n &&
        IID != Intrinsic::nvvm_barrier_sync_cnt && IID != Intrinsic::nvvm_barrier)
      break;
    const bool HasId = IID != Intrinsic::nvvm_barrier0;
    const bool HasCount = IID == Intrinsic::nvvm_barrier_sync_cnt ||
                          IID == Intrinsic::nvvm_barrier;
    // Format K payload: [13:8] is the 6-bit barrier ID, so the ID sits in
    // payload bits [5:0]. The compressed wait carries no phase -- O-27 puts
    // the epoch in hardware, so "wait until the arrival I just made has
    // retired" needs no operand. A wait on a phase this warp did not arrive
    // in is bar.wait.phase, a different instruction (Format E).
    const unsigned BarrierID = HasId ? N->getConstantOperandVal(2) : 0;
    uint64_t Count = HasCount ? N->getConstantOperandVal(3) : 0;
    if (Count == 1024)
      Count = 0;
    SDValue Chain = N->getOperand(0);
    SDNode *Init = CurDAG->getMachineNode(
        CCV::BAR_INIT, DL, MVT::Other,
        {CurDAG->getTargetConstant(BarrierID, DL, MVT::i32),
         CurDAG->getTargetConstant(Count, DL, MVT::i32), Chain});
    SDNode *Arrive = CurDAG->getMachineNode(
        CCV::C_BAR_ARRIVE, DL, MVT::Other,
        {CurDAG->getTargetConstant(BarrierID, DL, MVT::i32), SDValue(Init, 0)});
    ReplaceNode(N, CurDAG->getMachineNode(
                       CCV::C_BAR_WAIT, DL, MVT::Other,
                       {CurDAG->getTargetConstant(BarrierID, DL, MVT::i32),
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
                         CCV::SRD, DL, MVT::i32,
                         CurDAG->getTargetConstant(Sel, DL, MVT::i32)));
      return;
    }
    break;
  }
  }
  SelectCode(N);
}

namespace llvm {
FunctionPass *createCCVISelDag(CCVTargetMachine &TM, CodeGenOptLevel OL) {
  return new CCVDAGToDAGISel(TM, OL);
}
} // namespace llvm
