//===-- CCGISelLowering.cpp -----------------------------------------------===//
#include "CCGISelLowering.h"
#include "CCGSubtarget.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/IntrinsicsNVPTX.h"

using namespace llvm;

#include "CCGGenCallingConv.inc"

CCGTargetLowering::CCGTargetLowering(const TargetMachine &TM,
                                     const CCGSubtarget &STI)
    : TargetLowering(TM) {
  addRegisterClass(MVT::i32, &CCG::GPRRegClass);
  addRegisterClass(MVT::f32, &CCG::GPRRegClass);
  // A predicate is its own namespace with its own RAT (invariant 5), so i1
  // lives in PR rather than being promoted into a GPR. One bit per lane in
  // hardware; i1 per thread in the type system.
  addRegisterClass(MVT::i1, &CCG::PRRegClass);
  computeRegisterProperties(STI.getRegisterInfo());

  setStackPointerRegisterToSaveRestore(0);
  setBooleanContents(ZeroOrOneBooleanContent);

  // 48-bit addressing is formed in the AGU from two 32-bit registers
  // (invariant 11), so i64 is never a register type -- there is no register
  // that could hold one. LLVM requires a load's pointer operand to be legal,
  // and a pointer cannot be "expanded" into two registers the way an integer
  // can, because the node takes one address.
  //
  // So the address is consumed BEFORE type legalization ever sees it, in a
  // DAGCombine at BeforeLegalizeTypes. See PerformDAGCombine and F-20.
  setTargetDAGCombine({ISD::LOAD, ISD::STORE});
  setOperationAction(ISD::GlobalAddress, MVT::i64, Custom);

  // No hardware divide (§4's integer map ends at prmt with no divide).
  for (MVT VT : {MVT::i32}) {
    setOperationAction(ISD::SDIV, VT, Expand);
    setOperationAction(ISD::UDIV, VT, Expand);
    setOperationAction(ISD::SREM, VT, Expand);
    setOperationAction(ISD::UREM, VT, Expand);
    setOperationAction(ISD::ROTL, VT, Expand);
    setOperationAction(ISD::ROTR, VT, Expand);
    // Format C compares produce a predicate, not a GPR bit pattern; branches
    // read the predicate directly, so BR_CC / SELECT_CC are the natural forms.
    // Format C compares write a predicate; branches read one. BR_CC and
    // SELECT_CC are expanded into setcc + brcond so the predicate is an
    // explicit value the allocator can see.
    setOperationAction(ISD::BR_CC, VT, Expand);
    setOperationAction(ISD::SELECT_CC, VT, Expand);
    setOperationAction(ISD::SELECT, VT, Expand);
  }
  setOperationAction(ISD::BR_CC, MVT::f32, Expand);
  setOperationAction(ISD::SELECT_CC, MVT::f32, Expand);
  setOperationAction(ISD::SELECT, MVT::f32, Expand);
  // brcond takes an i1; there is no BRCOND over a GPR bit pattern, because a
  // branch reads the predicate file directly (§3, Format E).
  setOperationAction(ISD::BRCOND, MVT::Other, Legal);
}

const char *CCGTargetLowering::getTargetNodeName(unsigned Opcode) const {
  switch (Opcode) {
  case CCGISD::RET: return "CCGISD::RET";
  case CCGISD::SRD: return "CCGISD::SRD";
  case CCGISD::LD_BASEIDX: return "CCGISD::LD_BASEIDX";
  case CCGISD::ST_BASEIDX: return "CCGISD::ST_BASEIDX";
  case CCGISD::LD_BASEOFF: return "CCGISD::LD_BASEOFF";
  case CCGISD::ST_BASEOFF: return "CCGISD::ST_BASEOFF";
  default:          return nullptr;
  }
}

/// Match (rbase << 16) + (idx << scale), the shape CCGLowerKernelArgs leaves
/// for a global pointer once a getelementptr has scaled the element index
/// (§5.1).
///
/// The scale is the interesting part. O-7 derives the index shift from the
/// destination's chwidth so that A[i] is one instruction at any element width;
/// a GEP has already applied exactly that shift, so matching it and setting
/// scale-enable hands the work back to the AGU. If the index is a raw byte
/// offset instead -- which is what the unaligned case produces, since the
/// in-window offset has to be folded into it -- scale-enable stays clear.
static bool matchBaseIdx(SDValue Addr, EVT MemVT, SDValue &Base, SDValue &Idx,
                         bool &ScaleEnable) {
  if (Addr.getOpcode() != ISD::ADD)
    return false;
  auto window = [](SDValue V, SDValue &Out) {
    if (V.getOpcode() != ISD::SHL)
      return false;
    auto *C = dyn_cast<ConstantSDNode>(V.getOperand(1));
    if (!C || C->getZExtValue() != 16)
      return false;
    SDValue In = V.getOperand(0);
    while (In.getOpcode() == ISD::ZERO_EXTEND || In.getOpcode() == ISD::ANY_EXTEND)
      In = In.getOperand(0);
    if (In.getValueType() != MVT::i32)
      return false;
    Out = In;
    return true;
  };
  SDValue Other;
  if (window(Addr.getOperand(0), Base))
    Other = Addr.getOperand(1);
  else if (window(Addr.getOperand(1), Base))
    Other = Addr.getOperand(0);
  else
    return false;

  // A shift by log2(element size) is the GEP's scaling, which the AGU can do.
  ScaleEnable = false;
  unsigned ElemLog2 = Log2_32(MemVT.getStoreSize());
  if (Other.getOpcode() == ISD::SHL)
    if (auto *C = dyn_cast<ConstantSDNode>(Other.getOperand(1)))
      if (C->getZExtValue() == ElemLog2) {
        Other = Other.getOperand(0);
        ScaleEnable = true;
      }

  while (Other.getOpcode() == ISD::ZERO_EXTEND ||
         Other.getOpcode() == ISD::SIGN_EXTEND ||
         Other.getOpcode() == ISD::ANY_EXTEND)
    Other = Other.getOperand(0);
  if (Other.getValueType() != MVT::i32)
    return false;
  Idx = Other;
  return true;
}

/// A constant address -- the launch block, whose base the prologue materialises
/// with a 48-bit Format F constant (§5.2). Splits it into the window index and
/// the in-window displacement, which is the Format D base+offset form.
static bool matchBaseOff(SelectionDAG &DAG, const SDLoc &DL, SDValue Addr,
                         SDValue &Base, SDValue &Off) {
  auto *C = dyn_cast<ConstantSDNode>(Addr);
  if (!C)
    return false;
  uint64_t A = C->getZExtValue();
  uint64_t Window = A >> 16, Disp = A & 0xffff;
  // The base+offset displacement field is 13 bits signed (§3, Format D).
  if (Disp > 4095)
    return false;
  Base = DAG.getConstant(Window, DL, MVT::i32);
  Off = DAG.getTargetConstant(Disp, DL, MVT::i32);
  return true;
}

SDValue CCGTargetLowering::PerformDAGCombine(SDNode *N,
                                             DAGCombinerInfo &DCI) const {
  // Must run before type legalization: once the legalizer sees a 64-bit
  // pointer operand it has nowhere to put it (F-20).
  if (!DCI.isBeforeLegalize())
    return SDValue();

  SelectionDAG &DAG = DCI.DAG;
  SDLoc DL(N);

  if (auto *LD = dyn_cast<LoadSDNode>(N)) {
    if (LD->getExtensionType() != ISD::NON_EXTLOAD || !LD->isSimple())
      return SDValue();
    SDVTList VTs = DAG.getVTList(LD->getValueType(0), MVT::Other);
    SDValue Base, Idx, New;
    bool Scale = false;
    if (matchBaseIdx(LD->getBasePtr(), LD->getMemoryVT(), Base, Idx, Scale)) {
      SDValue Ops[] = {LD->getChain(), Base, Idx,
                       DAG.getTargetConstant(Scale, DL, MVT::i32)};
      New = DAG.getMemIntrinsicNode(CCGISD::LD_BASEIDX, DL, VTs, Ops,
                                    LD->getMemoryVT(), LD->getMemOperand());
    } else if (matchBaseOff(DAG, DL, LD->getBasePtr(), Base, Idx)) {
      SDValue Ops[] = {LD->getChain(), Base, Idx};
      New = DAG.getMemIntrinsicNode(CCGISD::LD_BASEOFF, DL, VTs, Ops,
                                    LD->getMemoryVT(), LD->getMemOperand());
    } else {
      return SDValue();
    }
    // A load has two results. Returning one SDValue would replace only the
    // value and leave the chain hanging off the dead original, which shows up
    // later as an unexpandable i64 rather than as anything recognisable.
    DCI.CombineTo(N, New.getValue(0), New.getValue(1));
    return SDValue(N, 0);
  }

  if (auto *ST = dyn_cast<StoreSDNode>(N)) {
    if (ST->isTruncatingStore() || !ST->isSimple())
      return SDValue();
    SDVTList VTs = DAG.getVTList(MVT::Other);
    SDValue Base, Idx;
    bool Scale = false;
    if (matchBaseIdx(ST->getBasePtr(), ST->getMemoryVT(), Base, Idx, Scale)) {
      SDValue Ops[] = {ST->getChain(), ST->getValue(), Base, Idx,
                       DAG.getTargetConstant(Scale, DL, MVT::i32)};
      return DAG.getMemIntrinsicNode(CCGISD::ST_BASEIDX, DL, VTs, Ops,
                                     ST->getMemoryVT(), ST->getMemOperand());
    }
    if (matchBaseOff(DAG, DL, ST->getBasePtr(), Base, Idx)) {
      SDValue Ops[] = {ST->getChain(), ST->getValue(), Base, Idx};
      return DAG.getMemIntrinsicNode(CCGISD::ST_BASEOFF, DL, VTs, Ops,
                                     ST->getMemoryVT(), ST->getMemOperand());
    }
    return SDValue();
  }
  return SDValue();
}

std::pair<unsigned, const TargetRegisterClass *>
CCGTargetLowering::getRegForInlineAsmConstraint(const TargetRegisterInfo *TRI,
                                                StringRef Constraint,
                                                MVT VT) const {
  if (Constraint.size() == 1 && Constraint[0] == 'r')
    return {0U, &CCG::GPRRegClass};
  return TargetLowering::getRegForInlineAsmConstraint(TRI, Constraint, VT);
}

SDValue CCGTargetLowering::LowerOperation(SDValue Op, SelectionDAG &) const {
  report_fatal_error("CCG: unhandled custom lowering for " +
                     Twine(Op.getOpcode()));
}

SDValue CCGTargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    const SmallVectorImpl<ISD::InputArg> &Ins, const SDLoc &DL,
    SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {
  // A kernel has no formal arguments by the time selection runs:
  // CCGLowerKernelArgs has already turned every one into a launch-block load
  // (§5.2). Anything still here is an ordinary device function.
  MachineFunction &MF = DAG.getMachineFunction();
  SmallVector<CCValAssign, 8> ArgLocs;
  CCState CCInfo(CallConv, IsVarArg, MF, ArgLocs, *DAG.getContext());
  CCInfo.AnalyzeFormalArguments(Ins, CC_CCG);

  for (const CCValAssign &VA : ArgLocs) {
    if (!VA.isRegLoc())
      report_fatal_error("CCG: stack arguments are not implemented");
    Register VReg = MF.getRegInfo().createVirtualRegister(&CCG::GPRRegClass);
    MF.getRegInfo().addLiveIn(VA.getLocReg(), VReg);
    InVals.push_back(DAG.getCopyFromReg(Chain, DL, VReg, VA.getLocVT()));
  }
  return Chain;
}

SDValue CCGTargetLowering::LowerReturn(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    const SmallVectorImpl<ISD::OutputArg> &Outs,
    const SmallVectorImpl<SDValue> &OutVals, const SDLoc &DL,
    SelectionDAG &DAG) const {
  MachineFunction &MF = DAG.getMachineFunction();
  SmallVector<CCValAssign, 4> RVLocs;
  CCState CCInfo(CallConv, IsVarArg, MF, RVLocs, *DAG.getContext());
  CCInfo.AnalyzeReturn(Outs, RetCC_CCG);

  SDValue Glue;
  SmallVector<SDValue, 4> Ops(1, Chain);
  for (unsigned I = 0, E = RVLocs.size(); I != E; ++I) {
    Chain = DAG.getCopyToReg(Chain, DL, RVLocs[I].getLocReg(), OutVals[I], Glue);
    Glue = Chain.getValue(1);
    Ops.push_back(DAG.getRegister(RVLocs[I].getLocReg(), RVLocs[I].getLocVT()));
  }
  Ops[0] = Chain;
  if (Glue.getNode())
    Ops.push_back(Glue);
  return DAG.getNode(CCGISD::RET, DL, MVT::Other, Ops);
}
