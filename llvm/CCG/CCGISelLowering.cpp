//===-- CCGISelLowering.cpp -----------------------------------------------===//
#include "CCGISelLowering.h"
#include "CCGSubtarget.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/IR/IntrinsicsNVPTX.h"

using namespace llvm;

#include "CCGGenCallingConv.inc"

CCGTargetLowering::CCGTargetLowering(const TargetMachine &TM,
                                     const CCGSubtarget &STI)
    : TargetLowering(TM) {
  addRegisterClass(MVT::i32, &CCG::GPRRegClass);
  addRegisterClass(MVT::f32, &CCG::GPRRegClass);
  computeRegisterProperties(STI.getRegisterInfo());

  setStackPointerRegisterToSaveRestore(0);
  setBooleanContents(ZeroOrOneBooleanContent);

  // 48-bit addressing is formed in the AGU from two 32-bit registers
  // (invariant 11), so i64 is never a register type. It appears only as
  // address arithmetic, which the address-mode matcher consumes.
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
    setOperationAction(ISD::BR_CC, VT, Expand);
    setOperationAction(ISD::SELECT_CC, VT, Expand);
  }
  setOperationAction(ISD::BR_CC, MVT::f32, Expand);
  setOperationAction(ISD::SELECT_CC, MVT::f32, Expand);
}

const char *CCGTargetLowering::getTargetNodeName(unsigned Opcode) const {
  switch (Opcode) {
  case CCGISD::RET: return "CCGISD::RET";
  case CCGISD::SRD: return "CCGISD::SRD";
  default:          return nullptr;
  }
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
