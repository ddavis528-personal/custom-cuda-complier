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

// §5.2's address-space numbering, shared with CCGCheckIR.
static constexpr unsigned AS_GLOBAL = 1;
static constexpr unsigned AS_SHARED = 3;
static constexpr unsigned AS_CONST  = 4;

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
    // NOT Expand. Expanding SELECT produces SELECT_CC, and expanding SELECT_CC
    // produces SELECT, so marking both Expand is an infinite legalization loop
    // -- the compiler hangs rather than failing. It went unnoticed until the
    // division expansion produced the first `select` this backend had ever
    // seen. §4 point 19 is `sel`, so the operation is Legal and selected in
    // C++ like the other predicate-consuming nodes. See F-42.
    setOperationAction(ISD::SELECT, VT, Legal);
  }
  setOperationAction(ISD::BR_CC, MVT::f32, Expand);
  setOperationAction(ISD::SELECT_CC, MVT::f32, Expand);
  setOperationAction(ISD::SELECT, MVT::f32, Legal);
  // brcond takes an i1; there is no BRCOND over a GPR bit pattern, because a
  // branch reads the predicate file directly (§3, Format E).
  setOperationAction(ISD::BRCOND, MVT::Other, Legal);

  // There is no constant pool: §5.1 gives the AGU a window and an index, and a
  // pool would need a third live pointer plus a relocation kind for it. The
  // default expansion of ConstantFP is a pool load, so keep the node legal and
  // let the f48 wide immediate carry the bit pattern -- a float constant costs
  // exactly what an integer constant costs, which is the right answer for a
  // machine whose GPRs hold either.
  setOperationAction(ISD::ConstantFP, MVT::f32, Legal);
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

/// Reduce an i64 address term to the 32-bit register it is built from, or a
/// null SDValue. Extends are transparent: every index in this machine is a
/// 32-bit value widened only because LLVM's pointer type is 64 bits.
static SDValue narrowTo32(SDValue V) {
  while (V.getOpcode() == ISD::ZERO_EXTEND || V.getOpcode() == ISD::SIGN_EXTEND ||
         V.getOpcode() == ISD::ANY_EXTEND)
    V = V.getOperand(0);
  return V.getValueType() == MVT::i32 ? V : SDValue();
}

/// Is this (zext rbase) << 16 -- the window half of an address?
static SDValue matchWindow(SDValue V) {
  if (V.getOpcode() != ISD::SHL)
    return SDValue();
  auto *C = dyn_cast<ConstantSDNode>(V.getOperand(1));
  if (!C || C->getZExtValue() != 16)
    return SDValue();
  return narrowTo32(V.getOperand(0));
}

/// Match an address onto Format D base+index: (rbase << 16) + (rindex << scale).
///
/// Two shapes arrive, and they are §5.6 and §5.5 respectively:
///
///   aligned   (rbase << 16) + (i << log2 elem)
///             -- two addends. The shift is exactly what O-7's scale-enable
///                does, so it is handed to the AGU and the index register
///                carries an ELEMENT index.
///
///   unaligned ((rbase << 16) + roffset) + (i << log2 elem)
///             -- THREE addends against a three-input AGU whose third input is
///                an immediate displacement, so it does not fit. §5.5 resolves
///                it by folding: the compiler computes roffset + (i << scale)
///                into one register, which then carries a BYTE offset, and
///                scale-enable stays clear. That fold is the extra `add` per
///                pointer in §5.5, and the reason O-7 does not pay off there.
///
/// The fold is sound only because a single allocation is smaller than
/// 4 GiB − 2^16, so roffset + byte-index cannot overflow 32 bits. That is F-23,
/// and it is a precondition the compiler cannot check.
static bool matchBaseIdx(SelectionDAG &DAG, const SDLoc &DL, SDValue Addr,
                         EVT MemVT, SDValue &Base, SDValue &Idx,
                         bool &ScaleEnable) {
  if (Addr.getOpcode() != ISD::ADD)
    return false;
  SDValue A = Addr.getOperand(0), B = Addr.getOperand(1);

  SDValue Win, Other, ROff;
  if ((Win = matchWindow(A)))      Other = B;
  else if ((Win = matchWindow(B))) Other = A;
  else {
    // Unaligned: one side is itself (window + roffset).
    for (auto [X, Y] : {std::pair{A, B}, std::pair{B, A}}) {
      if (X.getOpcode() != ISD::ADD)
        continue;
      SDValue W2 = matchWindow(X.getOperand(0));
      SDValue R2 = W2 ? narrowTo32(X.getOperand(1)) : SDValue();
      if (!W2) {
        W2 = matchWindow(X.getOperand(1));
        R2 = W2 ? narrowTo32(X.getOperand(0)) : SDValue();
      }
      if (W2 && R2) { Win = W2; ROff = R2; Other = Y; break; }
    }
    if (!Win)
      return false;
  }

  // Peel the element scaling, if present.
  unsigned ElemLog2 = Log2_32(MemVT.getStoreSize());
  bool Scaled = false;
  if (Other.getOpcode() == ISD::SHL)
    if (auto *C = dyn_cast<ConstantSDNode>(Other.getOperand(1)))
      if (C->getZExtValue() == ElemLog2) {
        Other = Other.getOperand(0);
        Scaled = true;
      }
  SDValue Index = narrowTo32(Other);
  if (!Index)
    return false;

  Base = Win;
  if (!ROff) {                       // aligned: let the AGU do the scaling
    Idx = Index;
    ScaleEnable = Scaled;
    return true;
  }

  // Unaligned: fold roffset and the byte index into one register. The index
  // then carries bytes, so the AGU must not scale it again.
  SDValue Bytes =
      Scaled ? DAG.getNode(ISD::SHL, DL, MVT::i32, Index,
                           DAG.getConstant(ElemLog2, DL, MVT::i32))
             : Index;
  Idx = DAG.getNode(ISD::ADD, DL, MVT::i32, ROff, Bytes);
  ScaleEnable = false;
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

  // This combine folds §5.1's windowed address into a Format D addressing mode.
  // §5.1 windows `.global`, `.const` and `.local` alike -- the shift comes from
  // the address space and only `.shared` is exempt, being flat 32-bit. So the
  // predicate is "not shared", not "is global": the launch block itself lives
  // in `.const`, and excluding it leaves every launch-block load holding a
  // 64-bit constant address that the type legalizer cannot expand.
  //
  // Shared has to be excluded, though, and not merely left unmatched:
  // matchBaseOff matches any constant address, so `sdata[0]` would otherwise
  // become an ld.global of the shared offset.
  auto IsWindowed = [](unsigned AS) { return AS != AS_SHARED; };

  if (auto *LD = dyn_cast<LoadSDNode>(N)) {
    if (LD->getExtensionType() != ISD::NON_EXTLOAD || !LD->isSimple() ||
        !IsWindowed(LD->getAddressSpace()))
      return SDValue();
    SDVTList VTs = DAG.getVTList(LD->getValueType(0), MVT::Other);
    SDValue Base, Idx, New;
    bool Scale = false;
    if (matchBaseIdx(DAG, DL, LD->getBasePtr(), LD->getMemoryVT(), Base, Idx, Scale)) {
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
    if (ST->isTruncatingStore() || !ST->isSimple() ||
        !IsWindowed(ST->getAddressSpace()))
      return SDValue();
    SDVTList VTs = DAG.getVTList(MVT::Other);
    SDValue Base, Idx;
    bool Scale = false;
    if (matchBaseIdx(DAG, DL, ST->getBasePtr(), ST->getMemoryVT(), Base, Idx, Scale)) {
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
