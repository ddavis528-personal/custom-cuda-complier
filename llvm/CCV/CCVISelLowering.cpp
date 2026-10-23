//===-- CCVISelLowering.cpp -----------------------------------------------===//
#include "CCVISelLowering.h"
#include "CCVSubtarget.h"
#include "CCVFrameLowering.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/MC/MCContext.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicsNVPTX.h"

using namespace llvm;

// §5.2's address-space numbering, shared with CCVCheckIR.
static constexpr unsigned AS_GLOBAL = 1;
static constexpr unsigned AS_SHARED = 3;
static constexpr unsigned AS_CONST  = 4;

#include "CCVGenCallingConv.inc"

// Mutation control for tools/check-int64.sh: sign-extend every load widened
// to 64 bits, whatever its extension.
static cl::opt<bool> TestWideLoadSext(
    "ccv-test-wide-load-sext", cl::init(false), cl::Hidden,
    cl::desc("sign-extend every load widened to 64 bits, to test that it is "
             "caught"));

CCVTargetLowering::CCVTargetLowering(const TargetMachine &TM,
                                     const CCVSubtarget &STI)
    : TargetLowering(TM) {
  addRegisterClass(MVT::i32, &CCV::GPRRegClass);
  // §1: element width is per-register state, so the SAME sixteen registers
  // hold 16-bit elements. There is no separate class -- the width is a
  // property of the value, carried to the post-RA chwidth pass in TSFlags
  // (F-3). i8 and i4 are not legal yet; i4 has no MVT at all.
  addRegisterClass(MVT::i16, &CCV::GPR16RegClass);
  addRegisterClass(MVT::f32, &CCV::GPRRegClass);
  // A predicate is its own namespace with its own RAT (invariant 5), so i1
  // lives in PR rather than being promoted into a GPR. One bit per lane in
  // hardware; i1 per thread in the type system.
  addRegisterClass(MVT::i1, &CCV::PRRegClass);
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
  setTargetDAGCombine({ISD::INLINEASM, ISD::LOAD, ISD::STORE, ISD::ADD, ISD::TRUNCATE,
                       ISD::LIFETIME_START, ISD::LIFETIME_END});
  setOperationAction(ISD::GlobalAddress, MVT::i64, Custom);

  // O-72 atomics: a word at most, so a sub-word atomic is a CAS loop on its
  // word (AtomicExpand), as is any operation Format M has no point for. Their
  // 64-bit addresses are consumed before type legalization, as a load's are.
  setMaxAtomicSizeInBitsSupported(32);
  setMinCmpXchgSizeInBits(32);
  setTargetDAGCombine({ISD::ATOMIC_LOAD_ADD, ISD::ATOMIC_LOAD_SUB,
                       ISD::ATOMIC_LOAD_AND, ISD::ATOMIC_LOAD_OR,
                       ISD::ATOMIC_LOAD_XOR, ISD::ATOMIC_LOAD_MIN,
                       ISD::ATOMIC_LOAD_MAX, ISD::ATOMIC_LOAD_UMIN,
                       ISD::ATOMIC_LOAD_UMAX, ISD::ATOMIC_SWAP,
                       ISD::ATOMIC_CMP_SWAP_WITH_SUCCESS, ISD::ATOMIC_LOAD,
                       ISD::ATOMIC_STORE});
  // A signed byte (F-161): a shift pair. combineDP4 has matched the byte
  // extracts it wants by the time this applies, before legalization.
  setOperationAction(ISD::SIGN_EXTEND_INREG, MVT::i8, Expand);

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
  // A compare or select on 16-bit values is done at 32 bits. The compare's
  // operand class is GPR, so CCVInsertChwidth would widen a GPR16 operand
  // first, which zero-extends (O-38) and so gets a signed compare wrong;
  // promotion extends each operand as the compare's signedness asks. Byte
  // loads (F-161) were the first thing to reach one.
  setOperationAction(ISD::BR_CC, MVT::i16, Expand);
  setOperationAction(ISD::SELECT_CC, MVT::i16, Expand);
  setOperationAction(ISD::SETCC, MVT::i16, Promote);
  AddPromotedToType(ISD::SETCC, MVT::i16, MVT::i32);
  setOperationAction(ISD::SELECT, MVT::i16, Promote);
  AddPromotedToType(ISD::SELECT, MVT::i16, MVT::i32);
  // 16-bit arithmetic with no 16-bit form (patterns exist for add, sub, the
  // logic ops and signed min/max) is done at 32 bits. The middle end narrows
  // byte arithmetic to i16 because i16 is legal, so `(unsigned char)(i * 7)`
  // reached an i16 multiply nothing selects (F-161).
  // Shifts are not here: LegalizeDAG does not promote them, so they have
  // patterns that do the same through the 32-bit instructions.
  for (unsigned Op : {ISD::MUL, ISD::MULHS, ISD::MULHU,
                      ISD::SDIV, ISD::UDIV, ISD::SREM, ISD::UREM,
                      ISD::UMIN, ISD::UMAX, ISD::ABS, ISD::CTPOP, ISD::CTLZ,
                      ISD::CTTZ, ISD::BSWAP, ISD::ROTL, ISD::ROTR}) {
    setOperationAction(Op, MVT::i16, Promote);
    AddPromotedToType(Op, MVT::i16, MVT::i32);
  }
  // A 64-bit shift by a variable amount is split into 32-bit halves as
  // *_PARTS, which has no instruction; expanded, it is two shifts, an or and a
  // select on the amount. Switch lowering reaches one without any i64 in the
  // source: a bit test is done at the pointer's width (the CoreMark-derived
  // port's state machine).
  // Without a library name the legalizer does it inline rather than calling
  // __ashldi3, which nothing here defines.
  for (unsigned Op : {ISD::SHL_PARTS, ISD::SRL_PARTS, ISD::SRA_PARTS})
    setOperationAction(Op, MVT::i32, Expand);
  for (RTLIB::Libcall LC : {RTLIB::SHL_I64, RTLIB::SRL_I64, RTLIB::SRA_I64})
    setLibcallName(LC, nullptr);
  // A 64-bit multiply (IS-13's 64-bit integers) is split into 32-bit halves
  // as *MUL_LOHI, which has no instruction; expanded, it is mul.lo and
  // mul.hi.u / mul.hi.s, both in §4.
  for (unsigned Op : {ISD::UMUL_LOHI, ISD::SMUL_LOHI})
    setOperationAction(Op, MVT::i32, Expand);
  // A 64-bit compare is split into the halves' compares, joined by a
  // select_cc on their i1 results, which has no instruction either.
  setOperationAction(ISD::SELECT_CC, MVT::i1, Expand);
  // ... and that select picks between the halves' predicates, i1: predicate
  // logic, selected in CCVISelDAGToDAG.
  setOperationAction(ISD::SELECT, MVT::i1, Legal);
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

  // §4's SFU points 259 and 260 are the base-2 exponential and logarithm, and
  // LLVM's default for both is Expand -- which does not mean "expand into
  // arithmetic", it means "call exp2f". With no calling sequence (F-21) that
  // libcall reached the back of the pipeline and crashed the compiler rather
  // than diagnosing anything, which is how these stayed unreachable without
  // anyone seeing a "cannot select". Declaring them Legal hands them to the
  // patterns in CCVInstrPatterns.td, where the instruction has been all along.
  //
  // f32 only, and deliberately: this legalises the fast-math/`__expf` form,
  // which is a single SFU instruction on this machine as it is on NVIDIA's. The
  // accurate libm form is a different function and still needs F-21.
  setOperationAction(ISD::FEXP2, MVT::f32, Legal);
  setOperationAction(ISD::FLOG2, MVT::f32, Legal);
}

const char *CCVTargetLowering::getTargetNodeName(unsigned Opcode) const {
  switch (Opcode) {
  case CCVISD::RET: return "CCVISD::RET";
  case CCVISD::CALL: return "CCVISD::CALL";
  case CCVISD::SRD: return "CCVISD::SRD";
  case CCVISD::LD_BASEIDX: return "CCVISD::LD_BASEIDX";
  case CCVISD::ST_BASEIDX: return "CCVISD::ST_BASEIDX";
  case CCVISD::LD_BASEOFF: return "CCVISD::LD_BASEOFF";
  case CCVISD::ST_BASEOFF: return "CCVISD::ST_BASEOFF";
  case CCVISD::CODEADDR: return "CCVISD::CODEADDR";
  case CCVISD::FRAMEOFF: return "CCVISD::FRAMEOFF";
  case CCVISD::ATOM: return "CCVISD::ATOM";
  case CCVISD::CAS: return "CCVISD::CAS";
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

/// An index term scaled by a constant the AGU cannot apply -- an element
/// larger than the access, like either word of an 8-byte pointer in a table
/// (CP-3), or a struct field. `(ext i) << c` and `(ext i) * c` are rebuilt in
/// 32 bits, which is sound for the reason narrowTo32 is: the index is a 32-bit
/// value, and byte offsets are 32-bit by F-23.
static SDValue narrowScaledIndex(SelectionDAG &DAG, const SDLoc &DL, SDValue V) {
  if (V.getOpcode() != ISD::SHL && V.getOpcode() != ISD::MUL)
    return SDValue();
  auto *C = dyn_cast<ConstantSDNode>(V.getOperand(1));
  SDValue X = narrowTo32(V.getOperand(0));
  if (!C || !X)
    return SDValue();
  return DAG.getNode(V.getOpcode(), DL, MVT::i32, X,
                     DAG.getConstant(C->getZExtValue(), DL, MVT::i32));
}

/// Is this (zext rbase) << 16 -- the window half of an address?
// O-45 needs the launch block's address to recognise a slot load. FOURTH copy
// of these -- CCVLowerKernelArgs.cpp owns them, CCVFrameLowering.cpp repeats the
// base, the simulator's AGU model repeats both. tools/check-launch-abi.sh
// requires all four to agree; there is no shared header between the compiler
// and the simulator to put them in.
static cl::opt<uint64_t> LaunchBase("ccv-isel-launch-base", cl::Hidden,
                                    cl::init(0x20000),
                                    cl::desc("CCV launch block address"));
static constexpr unsigned kOffArgs = 32;
/// Bytes between one launch slot and the next. EIGHT, not four: the field
/// gives the AGU a WINDOW INDEX, and §5.2 puts a pointer argument's window
/// word 8 bytes from the next one's, so every odd 4-byte step named an
/// in-window offset or a scalar and could never be a legal `rbase` -- half the
/// slot space dead by construction. DA's response CP-4, 2026-10-08: re-scale,
/// which doubles the reach to sixteen pointer arguments with no encoding
/// change at all. The ABI rule that makes the reach usable (pointer arguments
/// at the front of the argument area) is in CCVLowerKernelArgs.cpp.
static constexpr unsigned kSlotStride = 8;

static SDValue matchWindow(SDValue V) {
  if (V.getOpcode() != ISD::SHL)
    return SDValue();
  auto *C = dyn_cast<ConstantSDNode>(V.getOperand(1));
  if (!C || C->getZExtValue() != 16)
    return SDValue();
  return narrowTo32(V.getOperand(0));
}

/// O-45: is this window value a load of a pointer argument's window index out
/// of the launch block? If so, give back the slot number so the AGU can read it
/// and the value never needs a register.
///
/// Two shapes reach here depending on what the combiner has already done to the
/// window load: the original constant-address `.const` load, or the
/// `CCVISD::LD_BASEOFF` the windowed-address combine turns it into. Matching
/// only one of them would make the optimisation depend on visitation order,
/// which is the kind of thing that works on the kernel it was written for.
static std::optional<unsigned> matchLaunchSlot(SDValue Win) {
  auto slotOf = [](uint64_t Addr) -> std::optional<unsigned> {
    uint64_t Args = LaunchBase + kOffArgs;
    if (Addr < Args || (Addr - Args) % kSlotStride)
      return std::nullopt;
    uint64_t Slot = (Addr - Args) / kSlotStride;
    return Slot < 16 ? std::optional<unsigned>(unsigned(Slot)) : std::nullopt;
  };

  if (auto *LD = dyn_cast<LoadSDNode>(Win)) {
    if (!LD->isSimple() || LD->getExtensionType() != ISD::NON_EXTLOAD ||
        LD->getAddressSpace() != AS_CONST)
      return std::nullopt;
    if (auto *C = dyn_cast<ConstantSDNode>(LD->getBasePtr()))
      return slotOf(C->getZExtValue());
    return std::nullopt;
  }
  if (Win.getOpcode() == CCVISD::LD_BASEOFF) {
    auto *B = dyn_cast<ConstantSDNode>(Win.getOperand(1));
    auto *O = dyn_cast<ConstantSDNode>(Win.getOperand(2));
    if (!B || !O)
      return std::nullopt;
    return slotOf((B->getZExtValue() << 16) + O->getZExtValue());
  }
  return std::nullopt;
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
///
/// A CONSTANT BYTE DISPLACEMENT may sit on top of either shape, and Format D
/// base+index has an 8-bit signed field for exactly that (`disp`, `Inst{31:24}`).
/// It is what `out[i + 1]` compiles to: the GEP for the element index and a
/// second GEP for the constant, which instcombine leaves as `(window + i*4) + 4`
/// rather than folding into the index. This matcher ignored it for the life of
/// the backend and the field was written as a literal zero at selection, so the
/// address did not match here, did not match base+offset either, and reached
/// the type legalizer as a live 64-bit add -- which has no expansion and
/// SEGFAULTED the compiler. F-142.
static bool matchBaseIdx(SelectionDAG &DAG, const SDLoc &DL, SDValue Addr,
                         EVT MemVT, SDValue &Base, SDValue &Idx,
                         bool &ScaleEnable, int64_t &Disp) {
  // An address with its low bits masked off -- `ptrmask p, -4`, which is how
  // AtomicExpand finds a sub-word atomic's word (O-72). The window term is a
  // multiple of 2^16, so a mask of fewer than 16 low bits touches only the
  // in-window part: ((rbase << 16) + off) & ~m == (rbase << 16) + (off & ~m).
  if (Addr.getOpcode() == ISD::AND)
    if (auto *M = dyn_cast<ConstantSDNode>(Addr.getOperand(1))) {
      int64_t Mask = M->getSExtValue();
      if (Mask < 0 && isPowerOf2_64(uint64_t(-Mask)) && -Mask <= (1 << 16)) {
        if (!matchBaseIdx(DAG, DL, Addr.getOperand(0), MemVT, Base, Idx,
                          ScaleEnable, Disp))
          return false;
        SDValue Bytes =
            ScaleEnable
                ? DAG.getNode(ISD::SHL, DL, MVT::i32, Idx,
                              DAG.getConstant(Log2_32(MemVT.getStoreSize()),
                                              DL, MVT::i32))
                : Idx;
        if (Disp)
          Bytes = DAG.getNode(ISD::ADD, DL, MVT::i32, Bytes,
                              DAG.getConstant(Disp, DL, MVT::i32));
        Idx = DAG.getNode(ISD::AND, DL, MVT::i32, Bytes,
                          DAG.getConstant(int32_t(Mask), DL, MVT::i32));
        ScaleEnable = false;
        Disp = 0;
        return true;
      }
    }
  // Peel the constant addend first, so the shapes below see the two- and
  // three-addend forms they were written for. ADD canonicalises a constant to
  // the right, but the check is symmetric because nothing here guarantees the
  // combiner has run on this node yet.
  Disp = 0;
  if (Addr.getOpcode() == ISD::ADD) {
    for (unsigned I = 0; I != 2; ++I)
      if (auto *C = dyn_cast<ConstantSDNode>(Addr.getOperand(I))) {
        Disp = C->getSExtValue();
        Addr = Addr.getOperand(1 - I);
        break;
      }
  }
  if (Addr.getOpcode() != ISD::ADD)
    return false;
  SDValue A = Addr.getOperand(0), B = Addr.getOperand(1);

  // A constant inside the window term -- a global at a fixed offset in the
  // module's data image, indexed (O-61): ((W << 16) + c) + idx. The constant
  // is a displacement like any other.
  for (SDValue *X : {&A, &B})
    if ((X->getOpcode() == ISD::ADD || X->getOpcode() == ISD::OR) &&
        matchWindow(X->getOperand(0)))
      if (auto *K = dyn_cast<ConstantSDNode>(X->getOperand(1))) {
        if (X->getOpcode() == ISD::OR && !isUInt<16>(K->getZExtValue()))
          continue;
        Disp += K->getSExtValue();
        *X = X->getOperand(0);
        break;
      }

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
    Index = narrowScaledIndex(DAG, DL, Other);
  if (!Index)
    return false;

  Base = Win;
  if (!ROff && isInt<8>(Disp)) {     // aligned: let the AGU do the scaling
    Idx = Index;
    ScaleEnable = Scaled;
    return true;
  }

  // Either the displacement is too big for the 8-bit field, or this is the
  // unaligned shape and the in-window offset has to be folded anyway. Both
  // resolve the same way: compute a BYTE offset in one register, which means
  // the AGU must not scale it again.
  //
  // A displacement that fits stays in the field even here -- the fold is one
  // `add` per access and the field is free, so spending it when it is available
  // is the whole reason the field exists.
  SDValue Bytes =
      Scaled ? DAG.getNode(ISD::SHL, DL, MVT::i32, Index,
                           DAG.getConstant(ElemLog2, DL, MVT::i32))
             : Index;
  if (ROff)
    Bytes = DAG.getNode(ISD::ADD, DL, MVT::i32, ROff, Bytes);
  if (!isInt<8>(Disp)) {
    Bytes = DAG.getNode(ISD::ADD, DL, MVT::i32, Bytes,
                        DAG.getConstant(Disp, DL, MVT::i32));
    Disp = 0;
  }
  Idx = Bytes;
  ScaleEnable = false;
  return true;
}

/// A constant address -- the launch block, whose base the prologue materialises
/// with a 48-bit Format F constant (§5.2). Splits it into the window index and
/// the in-window displacement, which is the Format D base+offset form.
/// An address rooted at a frame object: a local array the middle end could not
/// promote to registers (F-131).
///
/// §5.1 windows `.local` exactly as it windows `.global`, and O-30 reserves R15
/// as the window base, which is why a spill is already `[r15 + disp]`. What was
/// missing is the case where the displacement is not a constant -- an array
/// indexed by a loop variable -- and that is Format D base+index with R15 as
/// the base. The addressing model needed nothing new; only this matcher and a
/// selection did.
///
/// Matched here, before legalization, for the same reason the window combine is
/// (F-20): an alloca's pointer is addrspace(0), which this data layout makes 64
/// bits, and the type legalizer has nowhere to put an i64. Folding the shape
/// away early means it never sees one -- which is why the failure this replaces
/// was "Do not know how to expand the result of this operator!" rather than
/// anything naming a frame.
/// Is this address rooted at a frame object at all? Used only to tell a shape
/// matchFrame does not handle from one that was never a frame access, so the
/// first can be diagnosed instead of reaching a legalizer that will abort
/// naming an operator rather than a cause.
static bool touchesFrame(SDValue V, unsigned Depth = 0) {
  if (Depth > 8)
    return false;
  if (isa<FrameIndexSDNode>(V))
    return true;
  if (V.getOpcode() != ISD::ADD)
    return false;
  return touchesFrame(V.getOperand(0), Depth + 1) ||
         touchesFrame(V.getOperand(1), Depth + 1);
}

static bool matchFrame(SelectionDAG &DAG, const SDLoc &DL, SDValue Addr,
                       EVT MemVT, SDValue &FI, SDValue &Idx, SDValue &Disp,
                       bool &ScaleEnable) {
  // Walk the address expression, adding up constants and keeping at most one
  // dynamic term, until the frame object turns up. A multi-dimensional array
  // produces a nest of adds with the frame index buried inside it and a
  // constant for the innermost subscript -- `acc[i][1]` is
  // `add(add(FI, i*8), 4)` -- so matching only a top-level `add(FI, x)` finds
  // the one-dimensional case and nothing else.
  SDValue Frame, Dyn;
  int64_t Const = 0;
  SmallVector<SDValue, 8> Work{Addr};
  while (!Work.empty()) {
    SDValue V = Work.pop_back_val();
    if (isa<FrameIndexSDNode>(V)) {
      if (Frame)
        return false;                  // two frame objects is not an address
      Frame = V;
    } else if (V.getOpcode() == ISD::ADD && Work.size() < 8) {
      Work.push_back(V.getOperand(0));
      Work.push_back(V.getOperand(1));
    } else if (auto *C = dyn_cast<ConstantSDNode>(V)) {
      Const += C->getSExtValue();
    } else if (!Dyn) {
      Dyn = V;
    } else {
      return false;                    // two dynamic terms, one index field
    }
  }
  if (!Frame)
    return false;

  // Re-create the frame index as a TARGET frame index of type i32 rather than
  // passing the original through. The original is an addrspace(0) pointer and
  // so i64 here, and handing it on as an operand leaves the type legalizer an
  // i64 to expand -- the exact error this combine exists to prevent, arriving
  // one node later and looking identical.
  FI = DAG.getTargetFrameIndex(cast<FrameIndexSDNode>(Frame)->getIndex(),
                               MVT::i32);
  ScaleEnable = false;

  // The constant is a displacement, and it has somewhere to go whether or not
  // there is also a dynamic term: eliminateFrameIndex adds the frame offset to
  // whatever this field holds. `acc[1][j]` is the case -- a constant middle
  // subscript and a dynamic last one -- and refusing it here was refusing the
  // shape a two-dimensional accumulator tile actually produces.
  Disp = DAG.getTargetConstant(Const, DL, MVT::i32);
  if (!Dyn) {
    Idx = DAG.getUNDEF(MVT::i32);
    return true;
  }

  // Peel the element scaling so the AGU can do it, exactly as matchBaseIdx
  // does for a windowed address.
  unsigned ElemLog2 = Log2_32(MemVT.getStoreSize());
  if (Dyn.getOpcode() == ISD::SHL)
    if (auto *C = dyn_cast<ConstantSDNode>(Dyn.getOperand(1)))
      if (C->getZExtValue() == ElemLog2) {
        Dyn = Dyn.getOperand(0);
        ScaleEnable = true;
      }

  if (SDValue Narrow = narrowTo32(Dyn)) {
    Idx = Narrow;
    return true;
  }
  // An index the middle end widened to i64 -- a loop counter typed by the GEP
  // rather than by the program. Truncating is sound HERE and only here: the
  // whole `.local` window is 64 KiB (§5.1) and eliminateFrameIndex caps a
  // frame far below that, so an index whose top half matters is out of bounds
  // and the access is undefined already. This is not a general licence to
  // narrow an i64; it rests on the frame being small, which is checked.
  if (Dyn.getValueType() == MVT::i64) {
    Idx = DAG.getNode(ISD::TRUNCATE, DL, MVT::i32, Dyn);
    return true;
  }
  return false;
}

static bool matchBaseOff(SelectionDAG &DAG, const SDLoc &DL, SDValue Addr,
                         SDValue &Base, SDValue &Off) {
  // A window plus a constant, or a window alone: a global at a fixed offset
  // in the module's data image (O-61), which is Format D base+offset with the
  // window in a register.
  SDValue W = Addr;
  int64_t D = 0;
  // The combiner writes the add as an `or` when the bits are disjoint, as
  // they are below a window's 16.
  if (Addr.getOpcode() == ISD::ADD || Addr.getOpcode() == ISD::OR)
    if (auto *K = dyn_cast<ConstantSDNode>(Addr.getOperand(1))) {
      W = Addr.getOperand(0);
      D = K->getSExtValue();
      if (Addr.getOpcode() == ISD::OR && !isUInt<16>(D))
        W = Addr;
    }
  if (SDValue Win = matchWindow(W); Win && isInt<13>(D)) {
    Base = Win;
    Off = DAG.getTargetConstant(D, DL, MVT::i32);
    return true;
  }

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

namespace {

/// One byte of `V`, sign-extended to 32 bits, or SDValue() if this is not that.
/// `Which` comes back as the byte index 0-3.
///
/// Three shapes reach here, and all three are the SAME source written
/// differently, which is the whole reason this is a combine. The generic
/// combiner canonicalises `sra(shl(V, 24 - 8k), 24)` into
/// `sign_extend_inreg(srl(V, 8k), i8)`, drops the `srl` when k is 0, and folds
/// the top byte to a bare `sra(V, 24)` because the left shift there is empty.
/// Matching only the form the C source suggests finds nothing.
SDValue sextByte(SDValue Op, unsigned &Which) {
  // sign_extend_inreg(V, i8)  or  sign_extend_inreg(srl(V, 8k), i8)
  if (Op.getOpcode() == ISD::SIGN_EXTEND_INREG &&
      cast<VTSDNode>(Op.getOperand(1))->getVT() == MVT::i8) {
    SDValue Inner = Op.getOperand(0);
    if (Inner.getOpcode() != ISD::SRL) {
      Which = 0;
      return Inner;
    }
    auto *Sh = dyn_cast<ConstantSDNode>(Inner.getOperand(1));
    if (!Sh)
      return SDValue();
    uint64_t S = Sh->getZExtValue();
    if (S % 8 || S > 24)
      return SDValue();
    Which = unsigned(S / 8);
    return Inner.getOperand(0);
  }
  // sra(shl(V, 24 - 8k), 24), and sra(V, 24) for the top byte.
  if (Op.getOpcode() != ISD::SRA)
    return SDValue();
  auto *ShAmt = dyn_cast<ConstantSDNode>(Op.getOperand(1));
  if (!ShAmt || ShAmt->getZExtValue() != 24)
    return SDValue();
  SDValue Inner = Op.getOperand(0);
  if (Inner.getOpcode() != ISD::SHL) {
    Which = 3;
    return Inner;
  }
  auto *Lo = dyn_cast<ConstantSDNode>(Inner.getOperand(1));
  if (!Lo)
    return SDValue();
  uint64_t S = Lo->getZExtValue();
  if (S % 8 || S > 24)
    return SDValue();
  Which = unsigned(3 - S / 8);
  return Inner.getOperand(0);
}

/// Flatten a tree of ISD::ADD into its leaves, up to a bound.
void addTerms(SDValue V, SmallVectorImpl<SDValue> &Out, unsigned Depth = 0) {
  if (V.getOpcode() == ISD::ADD && Depth < 8 && V.hasOneUse()) {
    addTerms(V.getOperand(0), Out, Depth + 1);
    addTerms(V.getOperand(1), Out, Depth + 1);
    return;
  }
  Out.push_back(V);
}

} // namespace

/// Recognise the four-byte dot product and give it the one instruction §4
/// allocates for it.
///
/// `dp4.ss` reads two ordinary 32-bit registers, reads each lane's four bytes
/// as INT8, multiplies elementwise and sums the four products into the
/// accumulator -- §3's packing factor lives in the OPCODE, so no register is
/// narrow and invariant 1 is untouched. Written out in C it is four shift
/// pairs, four multiplies and four adds; the spec puts the `mad.lo`
/// alternative at roughly 3x the instructions, and that is what this backend
/// emitted until F-111's audit asked what could produce `DP4_SS` and the
/// answer was nothing.
///
/// This is a combine rather than a TableGen pattern because the shape is a
/// COMMUTATIVE SUM of four products: matching it as a tree would need every
/// association and operand order written out. Forming dot products in a
/// combine is what the in-tree targets do for the same reason.
///
/// LLVM 18 has no `dp4a` intrinsic, so there is no shortcut through one. When
/// a later LLVM adds it, this stays useful -- it catches the hand-written form
/// that no intrinsic covers.
static SDValue combineDP4(SDNode *N, SelectionDAG &DAG) {
  if (N->getValueType(0) != MVT::i32)
    return SDValue();

  SmallVector<SDValue, 16> Terms;
  addTerms(SDValue(N, 0), Terms);
  if (Terms.size() < 4 || Terms.size() > 31)
    return SDValue();                      // `Used` below is a 32-bit mask

  // A dot product is a SUBSET of the sum, not the whole of it. Unrolling the
  // K loop and reassociating leaves one add tree holding the products of
  // several different (x, y) pairs, and an earlier version of this required
  // the tree to be exactly one dot product -- so it matched the toy kernel and
  // not the GEMM it was written for. Group by source pair instead, take the
  // first group that has all four bytes, and leave everything else as the
  // accumulator. What remains is another add tree, so a second dot product in
  // the same sum is found when the combiner revisits it.
  struct Group {
    SDValue X, Y;
    unsigned Bytes = 0;                    // bitmask of byte indices seen
    SmallVector<unsigned, 4> TermIdx;
  };
  SmallVector<Group, 4> Groups;

  for (unsigned I = 0; I != Terms.size(); ++I) {
    SDValue T = Terms[I];
    if (T.getOpcode() != ISD::MUL)
      continue;
    unsigned BX, BY;
    SDValue A = sextByte(T.getOperand(0), BX);
    SDValue B = sextByte(T.getOperand(1), BY);
    if (!A || !B || BX != BY)
      continue;
    Group *G = nullptr;
    for (Group &Cand : Groups)
      if ((Cand.X == A && Cand.Y == B) || (Cand.X == B && Cand.Y == A)) {
        G = &Cand;
        break;
      }
    if (!G) {
      Groups.push_back(Group{A, B});
      G = &Groups.back();
    }
    if (G->Bytes & (1u << BX))
      continue;                            // the same byte twice is not a lane
    G->Bytes |= 1u << BX;
    G->TermIdx.push_back(I);
  }

  const Group *Hit = nullptr;
  for (const Group &G : Groups)
    if (G.Bytes == 0xf) {
      Hit = &G;
      break;
    }
  if (!Hit)
    return SDValue();

  SDLoc DL(N);
  unsigned Used = 0;                       // Terms is bounded well under 32
  for (unsigned I : Hit->TermIdx)
    Used |= 1u << I;

  SDValue Acc;
  for (unsigned I = 0; I != Terms.size(); ++I) {
    if (Used & (1u << I))
      continue;
    Acc = Acc ? DAG.getNode(ISD::ADD, DL, MVT::i32, Acc, Terms[I]) : Terms[I];
  }
  if (!Acc)
    Acc = DAG.getConstant(0, DL, MVT::i32);
  return DAG.getNode(CCVISD::DP4_SS, DL, MVT::i32, Hit->X, Hit->Y, Acc);
}

/// O-72: an atomic's address as Format M's base + index + displacement, the
/// displacement in DispBits signed bits (4 for an RMW, 11 for CAS). `.global`
/// is matched as a load's address is, and `.shared` is flat 32-bit.
static bool matchAtomicAddr(SelectionDAG &DAG, const SDLoc &DL, SDValue Ptr,
                            bool Shared, unsigned DispBits, SDValue &Base,
                            SDValue &Idx, bool &Scale, int64_t &Disp) {
  Scale = false;
  Disp = 0;
  if (Shared) {
    Base = Ptr;
    Idx = DAG.getConstant(0, DL, MVT::i32);
    if (Ptr.getOpcode() == ISD::ADD) {
      Base = Ptr.getOperand(0);
      SDValue R = Ptr.getOperand(1);
      auto *K = dyn_cast<ConstantSDNode>(R);
      auto *Sh = R.getOpcode() == ISD::SHL
                     ? dyn_cast<ConstantSDNode>(R.getOperand(1))
                     : nullptr;
      if (K && isIntN(DispBits, K->getSExtValue())) {
        Disp = K->getSExtValue();
      } else if (Sh && Sh->getZExtValue() == 2) {
        Idx = R.getOperand(0);
        Scale = true;
      } else {
        Idx = R;
      }
    }
    return true;
  }
  if (matchBaseIdx(DAG, DL, Ptr, MVT::i32, Base, Idx, Scale, Disp)) {
    // A displacement the field cannot hold goes into the index, in bytes.
    if (!isIntN(DispBits, Disp)) {
      SDValue Bytes =
          Scale ? DAG.getNode(ISD::SHL, DL, MVT::i32, Idx,
                              DAG.getConstant(2, DL, MVT::i32))
                : Idx;
      Idx = DAG.getNode(ISD::ADD, DL, MVT::i32, Bytes,
                        DAG.getConstant(Disp, DL, MVT::i32));
      Scale = false;
      Disp = 0;
    }
    return true;
  }
  SDValue Off;
  if (matchBaseOff(DAG, DL, Ptr, Base, Off)) {
    Idx = DAG.getConstant(cast<ConstantSDNode>(Off)->getSExtValue(), DL,
                          MVT::i32);
    return true;
  }
  return false;
}

/// O-72: an atomic read-modify-write or compare-and-swap of a word, as one
/// Format M instruction. A relaxed atomic load or store becomes the plain
/// access (§3), which the load and store combines below then address.
static SDValue combineAtomic(AtomicSDNode *AN, TargetLowering::DAGCombinerInfo &DCI) {
  SelectionDAG &DAG = DCI.DAG;
  SDLoc DL(AN);
  const unsigned Opc = AN->getOpcode();
  if (Opc == ISD::ATOMIC_LOAD) {
    SDValue L = DAG.getLoad(AN->getValueType(0), DL, AN->getChain(),
                            AN->getBasePtr(), AN->getMemOperand());
    return DCI.CombineTo(AN, L, L.getValue(1));
  }
  if (Opc == ISD::ATOMIC_STORE)
    return DCI.CombineTo(AN, DAG.getStore(AN->getChain(), DL, AN->getVal(),
                                          AN->getBasePtr(),
                                          AN->getMemOperand()));
  if (AN->getMemoryVT() != MVT::i32)
    return SDValue();       // AtomicExpand made it a word; nothing else is
  const bool Shared = AN->getAddressSpace() == AS_SHARED;
  const bool Cas = Opc == ISD::ATOMIC_CMP_SWAP_WITH_SUCCESS;
  SDValue Base, Idx;
  bool Scale;
  int64_t Disp;
  if (!matchAtomicAddr(DAG, DL, AN->getBasePtr(), Shared, Cas ? 11 : 4, Base,
                       Idx, Scale, Disp)) {
    std::string Shape;
    raw_string_ostream OS(Shape);
    AN->getBasePtr()->printrFull(OS, &DAG);
    report_fatal_error(Twine("CCV: this atomic's address has no Format M "
                             "form -- it is neither a window plus an index "
                             "nor .shared (O-72): ") + OS.str());
  }
  SDValue TC = DAG.getTargetConstant(Shared, DL, MVT::i32);
  SDValue Sc = DAG.getTargetConstant(Scale, DL, MVT::i32);
  SDValue Dp = DAG.getTargetConstant(Disp, DL, MVT::i32);
  if (Cas) {
    SDValue Ops[] = {AN->getChain(), Base, Idx, Sc, Dp, AN->getOperand(2),
                     AN->getOperand(3), TC};
    SDValue New = DAG.getMemIntrinsicNode(
        CCVISD::CAS, DL, DAG.getVTList(MVT::i32, MVT::i1, MVT::Other), Ops,
        AN->getMemoryVT(), AN->getMemOperand());
    return DCI.CombineTo(AN, {New.getValue(0), New.getValue(1), New.getValue(2)});
  }
  // §3's order: add, min.s, min.u, max.s, max.u, and, or, xor, exch. A
  // subtract is an add of the negation.
  unsigned Kind;
  SDValue Val = AN->getVal();
  switch (Opc) {
  case ISD::ATOMIC_LOAD_SUB:
    Val = DAG.getNode(ISD::SUB, DL, MVT::i32, DAG.getConstant(0, DL, MVT::i32),
                      Val);
    [[fallthrough]];
  case ISD::ATOMIC_LOAD_ADD:  Kind = 0; break;
  case ISD::ATOMIC_LOAD_MIN:  Kind = 1; break;
  case ISD::ATOMIC_LOAD_UMIN: Kind = 2; break;
  case ISD::ATOMIC_LOAD_MAX:  Kind = 3; break;
  case ISD::ATOMIC_LOAD_UMAX: Kind = 4; break;
  case ISD::ATOMIC_LOAD_AND:  Kind = 5; break;
  case ISD::ATOMIC_LOAD_OR:   Kind = 6; break;
  case ISD::ATOMIC_LOAD_XOR:  Kind = 7; break;
  case ISD::ATOMIC_SWAP:      Kind = 8; break;
  default:
    return SDValue();
  }
  SDValue Ops[] = {AN->getChain(), Base, Idx, Sc, Dp, Val,
                   DAG.getTargetConstant(Kind, DL, MVT::i32), TC};
  SDValue New = DAG.getMemIntrinsicNode(
      CCVISD::ATOM, DL, DAG.getVTList(MVT::i32, MVT::Other), Ops,
      AN->getMemoryVT(), AN->getMemOperand());
  return DCI.CombineTo(AN, New, New.getValue(1));
}

// Mutation control for tools/check-atomics.sh: every atomic a plain load,
// operation and store, which lanes racing on one word expose.
static cl::opt<bool> TestAtomicPlain(
    "ccv-test-atomic-plain", cl::init(false), cl::Hidden,
    cl::desc("make every atomic a plain read-modify-write, to test that it is "
             "caught"));

TargetLowering::AtomicExpansionKind
CCVTargetLowering::shouldExpandAtomicCmpXchgInIR(AtomicCmpXchgInst *) const {
  return TestAtomicPlain ? AtomicExpansionKind::NotAtomic
                         : AtomicExpansionKind::None;
}

TargetLowering::AtomicExpansionKind
CCVTargetLowering::shouldExpandAtomicRMWInIR(AtomicRMWInst *RMW) const {
  if (TestAtomicPlain)
    return AtomicExpansionKind::NotAtomic;
  // Format M's nine operations at a word are native (sub as add); anything
  // else -- a float add, nand, the wrapping increments -- and anything
  // narrower is a CAS loop.
  if (!RMW->getType()->isIntegerTy(32))
    return AtomicExpansionKind::CmpXChg;
  switch (RMW->getOperation()) {
  case AtomicRMWInst::Add: case AtomicRMWInst::Sub: case AtomicRMWInst::And:
  case AtomicRMWInst::Or:  case AtomicRMWInst::Xor: case AtomicRMWInst::Max:
  case AtomicRMWInst::Min: case AtomicRMWInst::UMax: case AtomicRMWInst::UMin:
  case AtomicRMWInst::Xchg:
    return AtomicExpansionKind::None;
  default:
    return AtomicExpansionKind::CmpXChg;
  }
}

SDValue CCVTargetLowering::PerformDAGCombine(SDNode *N,
                                             DAGCombinerInfo &DCI) const {
  // A lifetime marker on a frame object is dropped, chain and all. It carries
  // no semantics this target acts on -- there is no stack colouring here -- and
  // its operand is the alloca's addrspace(0) pointer, which this data layout
  // makes i64. Left in place it is the last thing holding an i64 frame index
  // live into the type legalizer, which has no expansion for one, and the
  // abort names the operator rather than the marker (F-131). The loads and
  // stores are folded by matchFrame below; this is the user that is neither.
  if (N->getOpcode() == ISD::LIFETIME_START ||
      N->getOpcode() == ISD::LIFETIME_END)
    return N->getOperand(0);

  // An inline asm's template is an operand of the program pointer type, i64
  // under this data layout, and the type legalizer has no expansion for a
  // TargetExternalSymbol. Nothing reads it as an address -- the emitter takes
  // its name -- so it is re-typed i32 before legalization. CCVExpandPTXAsm
  // then replaces the asm (CP-6).
  if (N->getOpcode() == ISD::INLINEASM) {
    auto *Sym = dyn_cast<ExternalSymbolSDNode>(N->getOperand(1));
    if (!Sym || Sym->getValueType(0) == MVT::i32)
      return SDValue();
    assert(Sym->getTargetFlags() == 0 && "an asm string already re-typed");
    SmallVector<SDValue, 8> Ops(N->op_begin(), N->op_end());
    // Symbols are uniqued by name and flags, not type, so the i32 one carries
    // a flag of its own; the inline-asm emitter copies only the name.
    Ops[1] = DCI.DAG.getTargetExternalSymbol(Sym->getSymbol(), MVT::i32,
                                             /*TargetFlags=*/1);
    SDValue New = DCI.DAG.getNode(ISD::INLINEASM, SDLoc(N), N->getVTList(), Ops);
    SmallVector<SDValue, 2> Res;
    for (unsigned I = 0, E = N->getNumValues(); I != E; ++I)
      Res.push_back(New.getValue(I));
    return DCI.CombineTo(N, Res);
  }

  // A function's code address as a value (F-21 step 5): CCVCodePointers
  // leaves `ptrtoint @f to i32`, which arrives as a truncate of the 64-bit
  // GlobalAddress the legalizer has nowhere to put. The low 32 bits are the
  // code address, a link-time constant `movi` materialises.
  if (N->getOpcode() == ISD::TRUNCATE) {
    auto *G = dyn_cast<GlobalAddressSDNode>(N->getOperand(0));
    if (!G || !isa<Function>(G->getGlobal()) || N->getValueType(0) != MVT::i32)
      return SDValue();
    SDLoc DL(N);
    return DCI.DAG.getNode(
        CCVISD::CODEADDR, DL, MVT::i32,
        DCI.DAG.getTargetGlobalAddress(G->getGlobal(), DL, MVT::i32, 0,
                                       CCVII::MO_CODEADDR));
  }

  // The dot product is formed before legalization too, and for a second
  // reason: the byte extracts it consumes are `sign_extend_inreg i8` shapes
  // this target cannot select, so matching them early makes them disappear
  // rather than reach a legalizer with nowhere to put them.
  if (N->getOpcode() == ISD::ADD)
    return DCI.isBeforeLegalize() ? combineDP4(N, DCI.DAG) : SDValue();

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

  if (auto *AN = dyn_cast<AtomicSDNode>(N))
    return combineAtomic(AN, DCI);

  // Volatile accesses take the same addressing as any other: volatility is an
  // ordering property, carried by the memory operand onto the target node,
  // not a different address. Excluding them (isSimple) left a volatile load's
  // 64-bit address to the type legalizer, which aborted -- found by the IS-17
  // spin-wait kernel, whose flag is volatile. A relaxed atomic load or store
  // is a plain access too (§3: a plain `ld` serves as the relaxed atomic
  // load); AtomicExpand has put fences around anything stronger.
  auto Stronger = [](const MemSDNode *M) {
    return M->isAtomic() &&
           M->getMergedOrdering() != AtomicOrdering::Monotonic &&
           M->getMergedOrdering() != AtomicOrdering::Unordered;
  };
  if (auto *LD = dyn_cast<LoadSDNode>(N)) {
    if (Stronger(LD) || !IsWindowed(LD->getAddressSpace()))
      return SDValue();
    // A 16-bit load extended to 32 is a 16-bit load at width 16, then the
    // extension: free for zero (O-38's widening clears the bits it exposes),
    // `cvt.sext` for sign. Left alone, its 64-bit address reached the type
    // legalizer unmatched and aborted (a `short` field; O-61's globals.cu).
    //
    // A byte load (F-161) is a W8 load into a 32-bit register: zero-extended
    // by the widening chwidth, sign-extended by `sext_inreg`, truncated for an
    // i8 or i16 user. i8 is not legal, so this has to happen here, before the
    // type legalizer meets the 64-bit address.
    //
    // A load extended to 64 bits (IS-13's 64-bit integers) is the same load
    // at 32 bits, then extended: the combiner folds `zext (load i32)` into
    // one i64 extending load, whose address then reached the type legalizer
    // unmatched and aborted -- every 64-bit kernel that read 32-bit data.
    ISD::LoadExtType WideExt = LD->getExtensionType(), Ext = WideExt;
    EVT MemVT = LD->getMemoryVT(), VT = LD->getValueType(0);
    const bool Wide = VT == MVT::i64 && Ext != ISD::NON_EXTLOAD &&
                      MemVT.getSizeInBits() <= 32;
    if (Wide) {
      VT = MVT::i32;
      if (MemVT == MVT::i32)
        Ext = ISD::NON_EXTLOAD;
    }
    const bool Byte = MemVT == MVT::i8;
    if (Byte ? !(VT == MVT::i8 || VT == MVT::i16 || VT == MVT::i32)
             : Ext != ISD::NON_EXTLOAD && (MemVT != MVT::i16 || VT != MVT::i32))
      return SDValue();
    SDVTList VTs = DAG.getVTList(Byte                      ? MVT::i32
                                 : Ext == ISD::NON_EXTLOAD ? VT
                                                           : MVT::i16,
                                 MVT::Other);
    SDValue Base, Idx, New;
    bool Scale = false;
    int64_t IdxDisp = 0;
    if (matchBaseIdx(DAG, DL, LD->getBasePtr(), LD->getMemoryVT(), Base, Idx,
                     Scale, IdxDisp)) {
      SDValue D = DAG.getTargetConstant(IdxDisp, DL, MVT::i32);
      // O-45: when the window is a launch-block slot, the AGU reads it and the
      // value never occupies a register. The window load is left behind with no
      // uses of its value and the generic combiner drops it.
      if (auto Slot = matchLaunchSlot(Base)) {
        SDValue Ops[] = {LD->getChain(),
                         DAG.getTargetConstant(*Slot, DL, MVT::i32), Idx,
                         DAG.getTargetConstant(Scale, DL, MVT::i32), D};
        New = DAG.getMemIntrinsicNode(CCVISD::LD_SLOTIDX, DL, VTs, Ops,
                                      LD->getMemoryVT(), LD->getMemOperand());
      } else {
        SDValue Ops[] = {LD->getChain(), Base, Idx,
                         DAG.getTargetConstant(Scale, DL, MVT::i32), D};
        New = DAG.getMemIntrinsicNode(CCVISD::LD_BASEIDX, DL, VTs, Ops,
                                      LD->getMemoryVT(), LD->getMemOperand());
      }
    } else if (matchBaseOff(DAG, DL, LD->getBasePtr(), Base, Idx)) {
      SDValue Ops[] = {LD->getChain(), Base, Idx};
      New = DAG.getMemIntrinsicNode(CCVISD::LD_BASEOFF, DL, VTs, Ops,
                                    LD->getMemoryVT(), LD->getMemOperand());
    } else if (SDValue Disp; matchFrame(DAG, DL, LD->getBasePtr(),
                                        LD->getMemoryVT(), Base, Idx, Disp,
                                        Scale)) {
      SDValue Ops[] = {LD->getChain(), Base, Idx,
                       DAG.getTargetConstant(Scale, DL, MVT::i32), Disp};
      New = DAG.getMemIntrinsicNode(CCVISD::LD_FRAME, DL, VTs, Ops,
                                    LD->getMemoryVT(), LD->getMemOperand());
    } else if (touchesFrame(LD->getBasePtr())) {
      report_fatal_error("CCV: this local-array address shape has no Format D "
                         "form -- it is rooted at a frame object but is not "
                         "base, one index and a constant (roadmap F-131)");
    } else {
      return SDValue();
    }
    // A load has two results. Returning one SDValue would replace only the
    // value and leave the chain hanging off the dead original, which shows up
    // later as an unexpandable i64 rather than as anything recognisable.
    SDValue V = New.getValue(0);
    if (Byte) {
      if (Ext == ISD::SEXTLOAD)
        V = DAG.getNode(ISD::SIGN_EXTEND_INREG, DL, MVT::i32, V,
                        DAG.getValueType(MVT::i8));
      if (VT != MVT::i32)
        V = DAG.getNode(ISD::TRUNCATE, DL, VT, V);
    } else if (Ext != ISD::NON_EXTLOAD) {
      V = DAG.getNode(Ext == ISD::SEXTLOAD ? ISD::SIGN_EXTEND : ISD::ZERO_EXTEND,
                      DL, MVT::i32, V);
    }
    if (Wide)
      V = DAG.getNode(WideExt == ISD::SEXTLOAD || TestWideLoadSext
                                                 ? ISD::SIGN_EXTEND
                      : WideExt == ISD::ZEXTLOAD ? ISD::ZERO_EXTEND
                                                 : ISD::ANY_EXTEND,
                      DL, MVT::i64, V);
    DCI.CombineTo(N, V, New.getValue(1));
    return SDValue(N, 0);
  }

  if (auto *ST = dyn_cast<StoreSDNode>(N)) {
    if (Stronger(ST) || !IsWindowed(ST->getAddressSpace()))
      return SDValue();
    // A 16-bit store of a 32-bit value is a store of its low half at width
    // 16, as `trunc i32 -> i16` is free. Left alone, it reached the type
    // legalizer with its 64-bit address unmatched, which crashed rather than
    // diagnosing (C's `ee_s16` fields; AR-20).
    // A byte store (F-161) stores a 32-bit register's low byte at width 8:
    // its value is any-extended to i32 and the memory type stays i8, which
    // selects the W8 form.
    SDValue Val = ST->getValue();
    if (ST->getMemoryVT() == MVT::i8) {
      if (Val.getValueType() != MVT::i32)
        Val = DAG.getNode(ISD::ANY_EXTEND, DL, MVT::i32, Val);
    } else if (ST->isTruncatingStore()) {
      if (ST->getMemoryVT() != MVT::i16 || Val.getValueType() != MVT::i32)
        return SDValue();
      Val = DAG.getNode(ISD::TRUNCATE, DL, MVT::i16, Val);
    }
    SDVTList VTs = DAG.getVTList(MVT::Other);
    SDValue Base, Idx;
    bool Scale = false;
    int64_t IdxDisp = 0;
    if (matchBaseIdx(DAG, DL, ST->getBasePtr(), ST->getMemoryVT(), Base, Idx,
                     Scale, IdxDisp)) {
      SDValue D = DAG.getTargetConstant(IdxDisp, DL, MVT::i32);
      if (auto Slot = matchLaunchSlot(Base)) {        // O-45
        SDValue Ops[] = {ST->getChain(), Val,
                         DAG.getTargetConstant(*Slot, DL, MVT::i32), Idx,
                         DAG.getTargetConstant(Scale, DL, MVT::i32), D};
        return DAG.getMemIntrinsicNode(CCVISD::ST_SLOTIDX, DL, VTs, Ops,
                                       ST->getMemoryVT(), ST->getMemOperand());
      }
      SDValue Ops[] = {ST->getChain(), Val, Base, Idx,
                       DAG.getTargetConstant(Scale, DL, MVT::i32), D};
      return DAG.getMemIntrinsicNode(CCVISD::ST_BASEIDX, DL, VTs, Ops,
                                     ST->getMemoryVT(), ST->getMemOperand());
    }
    if (matchBaseOff(DAG, DL, ST->getBasePtr(), Base, Idx)) {
      SDValue Ops[] = {ST->getChain(), Val, Base, Idx};
      return DAG.getMemIntrinsicNode(CCVISD::ST_BASEOFF, DL, VTs, Ops,
                                     ST->getMemoryVT(), ST->getMemOperand());
    }
    if (SDValue Disp; matchFrame(DAG, DL, ST->getBasePtr(), ST->getMemoryVT(),
                                 Base, Idx, Disp, Scale)) {
      SDValue Ops[] = {ST->getChain(), Val, Base, Idx,
                       DAG.getTargetConstant(Scale, DL, MVT::i32), Disp};
      return DAG.getMemIntrinsicNode(CCVISD::ST_FRAME, DL, VTs, Ops,
                                     ST->getMemoryVT(), ST->getMemOperand());
    }
    if (touchesFrame(ST->getBasePtr()))
      report_fatal_error("CCV: this local-array address shape has no Format D "
                         "form -- it is rooted at a frame object but is not "
                         "base, one index and a constant (roadmap F-131)");
    return SDValue();
  }
  return SDValue();
}

std::pair<unsigned, const TargetRegisterClass *>
CCVTargetLowering::getRegForInlineAsmConstraint(const TargetRegisterInfo *TRI,
                                                StringRef Constraint,
                                                MVT VT) const {
  // PTX's register constraints, as CUDA's headers write them (CP-6): `r` a
  // 32-bit integer, `f` an FP32 value, `h` a 16-bit one. CCVExpandPTXAsm
  // replaces the asm that uses them, so these only carry the operands there.
  if (Constraint.size() == 1 && (Constraint[0] == 'r' || Constraint[0] == 'f'))
    return {0U, &CCV::GPRRegClass};
  if (Constraint.size() == 1 && Constraint[0] == 'h')
    return {0U, &CCV::GPR16RegClass};
  return TargetLowering::getRegForInlineAsmConstraint(TRI, Constraint, VT);
}

SDValue CCVTargetLowering::LowerOperation(SDValue Op, SelectionDAG &DAG) const {
  std::string Node;
  raw_string_ostream OS(Node);
  Op->print(OS, &DAG);
  report_fatal_error("CCV: unhandled custom lowering in " +
                     DAG.getMachineFunction().getName() + ": " + OS.str());
}

SDValue CCVTargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    const SmallVectorImpl<ISD::InputArg> &Ins, const SDLoc &DL,
    SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {
  // A kernel has no formal arguments by the time selection runs:
  // CCVLowerKernelArgs has already turned every one into a launch-block load
  // (§5.2). Anything still here is an ordinary device function.
  MachineFunction &MF = DAG.getMachineFunction();
  SmallVector<CCValAssign, 8> ArgLocs;
  CCState CCInfo(CallConv, IsVarArg, MF, ArgLocs, *DAG.getContext());
  CCInfo.AnalyzeFormalArguments(Ins, CC_CCV);

  for (const CCValAssign &VA : ArgLocs) {
    if (VA.isMemLoc()) {
      // A stack argument (F-21, calling-convention.md §3): the caller wrote
      // it at the top of this function's frame, where a fixed object with a
      // negative offset puts it -- PEI lays the locals out below.
      int FI = MF.getFrameInfo().CreateFixedObject(
          4, -int64_t(VA.getLocMemOffset()) - 4, /*IsImmutable=*/true);
      SDValue V = DAG.getLoad(VA.getLocVT(), DL, Chain,
                              DAG.getFrameIndex(FI, getPointerTy(DAG.getDataLayout())),
                              MachinePointerInfo::getFixedStack(MF, FI));
      if (VA.getValVT() != VA.getLocVT())
        V = DAG.getNode(ISD::TRUNCATE, DL, VA.getValVT(), V);
      InVals.push_back(V);
      continue;
    }
    Register VReg = MF.getRegInfo().createVirtualRegister(&CCV::GPRRegClass);
    MF.getRegInfo().addLiveIn(VA.getLocReg(), VReg);
    SDValue V = DAG.getCopyFromReg(Chain, DL, VReg, VA.getLocVT());
    if (VA.getValVT() != VA.getLocVT())       // i1/i8/i16, promoted to i32
      V = DAG.getNode(ISD::TRUNCATE, DL, VA.getValVT(), V);
    InVals.push_back(V);
  }

  // A device function returns through the link value its caller's `call` left
  // in R14 (F-21). Taken as an ordinary live-in, so the allocator keeps it in
  // R14 in a leaf and moves or spills it in a function that calls.
  if (!ccvIsKernel(MF.getFunction()))
    MF.getRegInfo().addLiveIn(
        CCV::R14, MF.getRegInfo().createVirtualRegister(&CCV::GPRRegClass));
  return Chain;
}

// Mutation control for tools/check-ptrlist.sh: a frame pointer's window taken
// as R15 itself rather than the window below it, so it names the next
// thread's frame.
static cl::opt<bool> TestFrameWindowR15(
    "ccv-test-frame-window-r15", cl::init(false), cl::Hidden,
    cl::desc("give frame pointers R15's window, to test that it is caught"));

// Mutation control for tools/check-calls.sh: a caller writes stack arguments
// as if its callee's frame were at base 0, so they miss the callee's slots.
static cl::opt<bool> TestStackArgsAtZero(
    "ccv-test-stack-args-at-zero", cl::init(false), cl::Hidden,
    cl::desc("write stack arguments ignoring the callee's frame base, to test "
             "that it is caught"));

/// A direct call (F-21; proposals/calling-convention.md). Arguments go in
/// R1-R6 per CC_CCV, the callee runs on the same R15 with its frame at a
/// static place below its caller's, and returns in R1-R2. Arguments past the
/// sixth go on the callee's frame. Indirect calls are the proposal's step 5.
SDValue CCVTargetLowering::LowerCall(CallLoweringInfo &CLI,
                                     SmallVectorImpl<SDValue> &InVals) const {
  SelectionDAG &DAG = CLI.DAG;
  const SDLoc &DL = CLI.DL;
  SDValue Chain = CLI.Chain;
  MachineFunction &MF = DAG.getMachineFunction();
  CLI.IsTailCall = false;
  if (CLI.IsVarArg)
    report_fatal_error("CCV: variadic calls are not supported");

  const auto *G = dyn_cast<GlobalAddressSDNode>(CLI.Callee);
  if (auto *E = dyn_cast<ExternalSymbolSDNode>(CLI.Callee))
    report_fatal_error(Twine("CCV: a call to the library function ") +
                       E->getSymbol() + ", which this module does not define (F-21)");
  // An indirect call (§4): the target's code address, an i32 CCVCodePointers
  // put under an inttoptr, goes in R7, and `call R14` goes to a one-instruction
  // stub, `ret r7`, that the asm printer places after this function. `call`
  // sets the link and `ret` jumps to the target.
  SDValue Target;
  if (!G) {
    Target = narrowTo32(CLI.Callee);
    if (!Target)
      report_fatal_error("CCV: an indirect call in " + MF.getName() +
                         " through a pointer that is not a code address "
                         "(F-21 step 5)");
  }
  // A pointer into the frame as a pair (CCVPointerPairs): the window below
  // R15's, and the object's offset in it, which eliminateFrameIndex fills in.
  if (G && G->getGlobal()->getName() == "__ccv_frame_window") {
    SDValue R15 = DAG.getCopyFromReg(Chain, DL, CCV::R15, MVT::i32);
    InVals.push_back(TestFrameWindowR15
                         ? R15
                         : DAG.getNode(ISD::ADD, DL, MVT::i32, R15,
                                       DAG.getConstant(-1, DL, MVT::i32)));
    return R15.getValue(1);
  }
  if (G && G->getGlobal()->getName() == "__ccv_frame_offset") {
    // The i64 pointer argument arrives split into i32 halves, as any i64
    // argument does here; the frame index is under the low one.
    SDValue A = CLI.OutVals[0];
    if (A.getOpcode() == ISD::EXTRACT_ELEMENT)
      A = A.getOperand(0);
    auto *FIN = dyn_cast<FrameIndexSDNode>(A);
    if (!FIN) {
      std::string Node;
      raw_string_ostream OS(Node);
      CLI.OutVals[0]->print(OS, &DAG);
      report_fatal_error(Twine("CCV: a frame pointer that is not a frame "
                               "object: ") + OS.str());
    }
    InVals.push_back(DAG.getNode(
        CCVISD::FRAMEOFF, DL, MVT::i32,
        DAG.getTargetFrameIndex(FIN->getIndex(), MVT::i32)));
    return Chain;
  }
  if (G && G->getGlobal()->isDeclaration())
    report_fatal_error("CCV: a call to " + G->getGlobal()->getName() +
                       ", which this module does not define: device code is "
                       "one closed module (F-21)");

  SmallVector<CCValAssign, 8> ArgLocs;
  CCState CCInfo(CLI.CallConv, false, MF, ArgLocs, *DAG.getContext());
  CCInfo.AnalyzeCallOperands(CLI.Outs, CC_CCV);

  Chain = DAG.getCALLSEQ_START(Chain, 0, 0, DL);

  // Stack arguments go where the callee reads them: the top of its frame,
  // whose base is fixed module-wide and already known, since callees are laid
  // out first. Every function runs on the same R15, so the address is a
  // constant displacement, stored straight to [R15 + d] (§3).
  const Function *Callee = G ? cast<Function>(G->getGlobal()) : nullptr;
  SmallVector<SDValue, 4> Stores;
  for (unsigned I = 0, E = ArgLocs.size(); I != E; ++I) {
    const CCValAssign &VA = ArgLocs[I];
    if (!VA.isMemLoc())
      continue;
    if (!Callee)
      report_fatal_error("CCV: an indirect call in " + MF.getName() +
                         " passes more than six arguments; its targets' frames "
                         "differ, so there is no one place to write them");
    if (!ccvFrameLaidOut(*Callee))
      report_fatal_error(
          "CCV: " + MF.getName() + " passes stack arguments to " +
          Callee->getName() + " before that function's frame is laid out -- "
          "a recursive call, which a static frame layout cannot place (F-21)");
    int64_t Disp = -int64_t(TestStackArgsAtZero ? 0 : ccvFrameBase(*Callee)) -
                   int64_t(VA.getLocMemOffset()) - 4;
    if (!isInt<13>(Disp))
      report_fatal_error("CCV: a stack argument to " + Callee->getName() +
                         " lies past the 13-bit displacement of §3's Format D");
    SDValue V = CLI.OutVals[I];
    if (VA.getLocVT() != VA.getValVT())
      V = DAG.getNode(ISD::ANY_EXTEND, DL, VA.getLocVT(), V);
    MachineSDNode *St = DAG.getMachineNode(
        CCV::ST_GLOBAL, DL, MVT::Other,
        {V, DAG.getRegister(CCV::R15, MVT::i32),
         DAG.getTargetConstant(Disp, DL, MVT::i32), Chain});
    DAG.setNodeMemRefs(St, {MF.getMachineMemOperand(
                               MachinePointerInfo(), MachineMemOperand::MOStore,
                               4, Align(4))});
    Stores.push_back(SDValue(St, 0));
  }
  if (!Stores.empty())
    Chain = DAG.getNode(ISD::TokenFactor, DL, MVT::Other, Stores);

  SDValue Glue;
  SmallVector<SDValue, 8> Ops = {
      // i32, not the 64-bit pointer type: no register holds an address
      // (invariant 11), and a code address is 32-bit (§3 Format E).
      Chain, G ? DAG.getTargetGlobalAddress(G->getGlobal(), DL, MVT::i32)
               : DAG.getMCSymbol(MF.getContext().getOrCreateSymbol(
                                     ".Lccv_icall_" + MF.getName()),
                                 MVT::i32)};
  if (!G) {
    Chain = DAG.getCopyToReg(Chain, DL, CCV::R7, Target, Glue);
    Glue = Chain.getValue(1);
    Ops.push_back(DAG.getRegister(CCV::R7, MVT::i32));
  }
  for (unsigned I = 0, E = ArgLocs.size(); I != E; ++I) {
    const CCValAssign &VA = ArgLocs[I];
    if (!VA.isRegLoc())
      continue;
    SDValue V = CLI.OutVals[I];
    if (VA.getLocVT() != VA.getValVT())
      V = DAG.getNode(ISD::ANY_EXTEND, DL, VA.getLocVT(), V);
    Chain = DAG.getCopyToReg(Chain, DL, VA.getLocReg(), V, Glue);
    Glue = Chain.getValue(1);
    Ops.push_back(DAG.getRegister(VA.getLocReg(), VA.getLocVT()));
  }
  const TargetRegisterInfo *TRI = MF.getSubtarget().getRegisterInfo();
  Ops.push_back(DAG.getRegisterMask(TRI->getCallPreservedMask(MF, CLI.CallConv)));
  Ops[0] = Chain;
  if (Glue.getNode())
    Ops.push_back(Glue);
  Chain = DAG.getNode(CCVISD::CALL, DL, {MVT::Other, MVT::Glue}, Ops);
  Glue = Chain.getValue(1);
  Chain = DAG.getCALLSEQ_END(Chain, 0, 0, Glue, DL);
  Glue = Chain.getValue(1);

  SmallVector<CCValAssign, 2> RVLocs;
  CCState RetInfo(CLI.CallConv, false, MF, RVLocs, *DAG.getContext());
  RetInfo.AnalyzeCallResult(CLI.Ins, RetCC_CCV);
  for (const CCValAssign &VA : RVLocs) {
    SDValue V = DAG.getCopyFromReg(Chain, DL, VA.getLocReg(), VA.getLocVT(), Glue);
    Chain = V.getValue(1);
    Glue = V.getValue(2);
    if (VA.getValVT() != VA.getLocVT())
      V = DAG.getNode(ISD::TRUNCATE, DL, VA.getValVT(), V);
    InVals.push_back(V);
  }
  return Chain;
}

SDValue CCVTargetLowering::LowerReturn(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    const SmallVectorImpl<ISD::OutputArg> &Outs,
    const SmallVectorImpl<SDValue> &OutVals, const SDLoc &DL,
    SelectionDAG &DAG) const {
  MachineFunction &MF = DAG.getMachineFunction();
  SmallVector<CCValAssign, 4> RVLocs;
  CCState CCInfo(CallConv, IsVarArg, MF, RVLocs, *DAG.getContext());
  CCInfo.AnalyzeReturn(Outs, RetCC_CCV);

  SDValue Glue;
  SmallVector<SDValue, 4> Ops(1, Chain);
  // Operand 1 of a device function's RET is the link value (F-21); a kernel's
  // RET has none and becomes `exit`.
  //
  // The link value goes back into R14 for the `ret`, rather than being returned
  // through whatever register held it. The epilogue restores callee-saved
  // registers immediately before the return, so a link value the allocator had
  // kept in one of them would be overwritten by the caller's value first --
  // which is what -ccv-csr=eight did, returning through R0. R14 is in no
  // callee-saved set. A leaf keeps it in R14 throughout and pays nothing; a
  // function that calls pays at most one `mov`.
  if (!ccvIsKernel(MF.getFunction())) {
    Register Link = MF.getRegInfo().getLiveInVirtReg(CCV::R14);
    assert(Link && "LowerFormalArguments took R14 as a live-in");
    SDValue L = DAG.getCopyFromReg(Chain, DL, Link, MVT::i32);
    Chain = DAG.getCopyToReg(L.getValue(1), DL, CCV::R14, L, Glue);
    Glue = Chain.getValue(1);
    Ops.push_back(DAG.getRegister(CCV::R14, MVT::i32));
  } else if (!RVLocs.empty()) {
    report_fatal_error("CCV: a kernel cannot return a value");
  }
  for (unsigned I = 0, E = RVLocs.size(); I != E; ++I) {
    SDValue V = OutVals[I];
    if (RVLocs[I].getLocVT() != RVLocs[I].getValVT())
      V = DAG.getNode(ISD::ANY_EXTEND, DL, RVLocs[I].getLocVT(), V);
    Chain = DAG.getCopyToReg(Chain, DL, RVLocs[I].getLocReg(), V, Glue);
    Glue = Chain.getValue(1);
    Ops.push_back(DAG.getRegister(RVLocs[I].getLocReg(), RVLocs[I].getLocVT()));
  }
  Ops[0] = Chain;
  if (Glue.getNode())
    Ops.push_back(Glue);
  return DAG.getNode(CCVISD::RET, DL, MVT::Other, Ops);
}
