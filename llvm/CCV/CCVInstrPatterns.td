//===-- CCVInstrPatterns.td - selection patterns ------------*- tablegen -*-===//
//
// Patterns are kept out of CCVInstrInfo.td so that file stays a transcription
// of §3's bit maps and nothing else.
//
//===----------------------------------------------------------------------===//

// ---------------------------------------------------------------------------
// Target nodes
// ---------------------------------------------------------------------------
def SDT_CCVRet : SDTypeProfile<0, 0, []>;
def ccv_ret : SDNode<"CCVISD::RET", SDT_CCVRet,
                     [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

// Selected in C++ (CCVISelDAGToDAG::Select): the node is variadic over the
// return registers, which a declarative pattern cannot bind. A kernel ends
// with `exit`; `ret rs` for device functions arrives with the calling sequence.

// ---------------------------------------------------------------------------
// Control flow. The conditional forms are selected in C++ -- every compare
// needs a true guard manufactured first (O-24), which is a sequence rather
// than a tree rewrite.
// ---------------------------------------------------------------------------
// F-28: emit the 16-bit form and let the assembler relax it to Format E's
// 32-bit `bra` when the target is further than ±256 bytes. Picking here would
// mean guessing at a distance that does not exist until layout.
def : Pat<(br bb:$t), (C_BRA bb:$t)>;

// ---------------------------------------------------------------------------
// Integer arithmetic. Format A is three-source; the two-source operations leave
// rs2 unread, so it is tied to rs0 to avoid an extra live value.
// ---------------------------------------------------------------------------
// rs2 is unread by the two-source operations, so it is tied to rs0 rather than
// left as a second live value the allocator has to keep.
// The result type has to be written out now that GPR holds i16 as well as i32
// (F-3). Without it TableGen cannot infer which width a bare `add` means, and
// the ambiguity is real rather than pedantic -- the two select to different
// MachineInstr opcodes that encode the same bits.
multiclass AluPat<SDPatternOperator node, Instruction inst> {
  def : Pat<(node GPR:$a, GPR:$b), (inst GPR:$a, GPR:$b, GPR:$a)>;
}
defm : AluPat<add,  ADD>;
defm : AluPat<sub,  SUB>;
defm : AluPat<and,  AND>;
defm : AluPat<or,   OR>;
defm : AluPat<xor,  XOR>;
defm : AluPat<shl,  SHL>;
defm : AluPat<srl,  SHR>;
defm : AluPat<sra,  SRA>;
defm : AluPat<smin, MIN_S>;
defm : AluPat<umin, MIN_U>;
defm : AluPat<smax, MAX_S>;
defm : AluPat<umax, MAX_U>;
defm : AluPat<mulhs, MUL_HI_S>;
defm : AluPat<mulhu, MUL_HI_U>;

def : Pat<(ctpop GPR:$a),  (POPC GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(ctlz GPR:$a),   (CLZ GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(bitreverse GPR:$a), (BREV GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(abs GPR:$a),    (ABS GPR:$a, GPR:$a, GPR:$a)>;
// `not` is xor with -1 in LLVM; Format K has a real one-source form.
def : Pat<(xor GPR:$a, (i32 -1)), (C_NOT GPR:$a)>;

def : Pat<(mul GPR:$a, GPR:$b), (MADLO GPR:$a, GPR:$b, (MOVI 0))>;
def : Pat<(add (mul GPR:$a, GPR:$b), GPR:$c), (MADLO GPR:$a, GPR:$b, GPR:$c)>;
// §3 gives Format B's immediate THIRTEEN bits, signed, and B48's TWENTY-NINE,
// unsigned. This pattern carried no predicate at all, so any larger constant
// was selected into ADDI and the encoder rejected it -- a hard error where a
// register-form add was available. It is the same defect as F-43 below, one
// line above the comment that describes F-43, and it went unnoticed because
// nothing in the test suite added a constant above 4095 until the software
// fp32 divide added 0x3F800000.
//
// Out of range for both, the constant goes to a register through MOVI48 and
// the reg-reg add selects; no fallback pattern is needed for that.
def simm13_imm : ImmLeaf<i32, [{ return isInt<13>(Imm); }]>;
def uimm29_imm : ImmLeaf<i32, [{ return Imm >= 0 && isUInt<29>(Imm); }]>;
let AddedComplexity = 10 in
def : Pat<(add GPR:$a, (i32 simm13_imm:$i)), (ADDI GPR:$a, imm:$i)>;
let AddedComplexity = 5 in
def : Pat<(add GPR:$a, (i32 uimm29_imm:$i)), (ADDI48 GPR:$a, imm:$i)>;

// §3: Format K's register-immediate forms carry FOUR bits, unsigned. Without
// this predicate the encoder silently truncates -- a shift by 31 became a shift
// by 15, which is how integer division miscompiled while every primitive it
// uses tested correct (F-43). Out of range, the constant goes to a register and
// the three-operand Format A form does the shift.
def uimm4_imm : ImmLeaf<i32, [{ return Imm >= 0 && Imm < 16; }]>;
def : Pat<(shl GPR:$a, (i32 uimm4_imm:$i)), (C_SHLI GPR:$a, imm:$i)>;
def : Pat<(srl GPR:$a, (i32 uimm4_imm:$i)), (C_SHRI GPR:$a, imm:$i)>;
def : Pat<(sra GPR:$a, (i32 uimm4_imm:$i)), (C_SRAI GPR:$a, imm:$i)>;

// ---------------------------------------------------------------------------
// Floating point. The compressed destructive form is the natural match for a
// two-operand add -- it is what Format K exists for (§3).
// ---------------------------------------------------------------------------
def : Pat<(fadd GPR:$a, GPR:$b), (C_FADD GPR:$a, GPR:$b)>;
def : Pat<(fmul GPR:$a, GPR:$b), (C_FMUL GPR:$a, GPR:$b)>;
def : Pat<(fsub GPR:$a, GPR:$b), (FSUB GPR:$a, GPR:$b, GPR:$a)>;
def : Pat<(fminnum GPR:$a, GPR:$b), (C_FMIN GPR:$a, GPR:$b)>;
def : Pat<(fmaxnum GPR:$a, GPR:$b), (C_FMAX GPR:$a, GPR:$b)>;
def : Pat<(fneg GPR:$a), (FNEG_F0 GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(fabs GPR:$a), (FABS_F0 GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(fma GPR:$a, GPR:$b, GPR:$c), (FFMA_F0 GPR:$a, GPR:$b, GPR:$c)>;

// ---------------------------------------------------------------------------
// Constants. Format F's 48-bit form materialises any 32-bit constant in one
// instruction (§3), so there is no hi/lo pair to synthesise.
// ---------------------------------------------------------------------------
// Format F's 32-bit form carries 17 unsigned bits, which covers small constants
// -- including every FP32 value whose bit pattern happens to be small, of which
// 0.0 is the one that actually occurs. Preferring it saves 16 bits per
// materialisation, and a kernel materialises constants more often than it looks.
def uimm17_imm : ImmLeaf<i32, [{ return Imm >= 0 && Imm < (1 << 17); }]>;
let AddedComplexity = 10 in
def : Pat<(i32 uimm17_imm:$i), (MOVI imm:$i)>;
// The immediate has to be ZERO-extended into the 33-bit field. A negative i32
// constant reaches here sign-extended to 64 bits, and the encoder's range check
// rejects it -- so `and x, 0x807FFFFF` (or any mask with the top bit set) was a
// hard compiler error rather than an instruction. The bit pattern is what the
// machine wants; a GPR is 32 bits and the width comes from `chwidth`, not from
// a sign. Found when the software fp32 divide needed exactly that mask.
def imm_bits32 : SDNodeXForm<imm, [{
  // i64, not i32: a 32-bit target constant is carried to the MachineOperand
  // sign-extended, which is the whole problem. The field is 33 bits and the
  // value is a 32-bit pattern, so it must arrive zero-extended.
  return CurDAG->getTargetConstant(N->getZExtValue() & 0xFFFFFFFFull, SDLoc(N),
                                   MVT::i64);
}]>;
def : Pat<(i32 imm:$i), (MOVI48 (imm_bits32 $i))>;

// A float constant is an integer constant in a GPR. GPR holds i32 and f32
// alike (§1: a lane is 32 bits and the width comes from `chwidth`, not from the
// register), so the bit pattern goes in through the same wide immediate and no
// conversion instruction exists or is needed.
def fpimm_bits : SDNodeXForm<fpimm, [{
  return CurDAG->getTargetConstant(
      N->getValueAPF().bitcastToAPInt().getZExtValue(), SDLoc(N), MVT::i32);
}]>;
def fpimm_small : PatLeaf<(fpimm), [{
  return N->getValueAPF().bitcastToAPInt().getZExtValue() < (1u << 17);
}]>;
let AddedComplexity = 10 in
def : Pat<(f32 fpimm_small:$i), (MOVI (fpimm_bits $i))>;
def : Pat<(f32 fpimm:$i), (MOVI48 (fpimm_bits $i))>;

// bitcast between i32 and f32 is the identity on a GPR -- no instruction, and
// the operand types have to be written out or TableGen cannot infer which
// direction is meant, since GPR holds both.
def : Pat<(i32 (bitconvert (f32 GPR:$a))), (i32 GPR:$a)>;
def : Pat<(f32 (bitconvert (i32 GPR:$a))), (f32 GPR:$a)>;

// ---------------------------------------------------------------------------
// Loads and stores. AddrRI matches (rbase << 16) + index, which is the shape
// CCVLowerKernelArgs leaves behind for a global pointer (§5.1). The scale is
// chwidth-derived and enabled only when the index is an element index, which
// is the aligned case (O-23, O-7).
// ---------------------------------------------------------------------------
// Selected in C++ rather than declaratively: the match has to inspect the
// shape CCVLowerKernelArgs produced -- a shl-by-16 of a zero-extended window
// index, plus a scaled element index -- and decide whether scale-enable can be
// set. That is a judgement about alignment (O-23), not a tree shape, so it
// lives in CCVISelDAGToDAG::selectAddrBaseIdx.

// ---------------------------------------------------------------------------
// Shared memory. §5.1: `.shared` is flat 32-bit -- no window, no launch-block
// indirection, and the address fits in one register. So unlike `.global` it
// needs no DAGCombine; ordinary patterns select it, distinguished from
// `.global` by the address space, which §3 puts in the opcode.
// ---------------------------------------------------------------------------
class SharedLoad<SDPatternOperator op>
    : PatFrag<(ops node:$ptr), (op node:$ptr), [{
  return cast<LoadSDNode>(N)->getAddressSpace() == 3;
}]>;
class SharedStore<SDPatternOperator op>
    : PatFrag<(ops node:$val, node:$ptr), (op node:$val, node:$ptr), [{
  return cast<StoreSDNode>(N)->getAddressSpace() == 3;
}]>;
def ld_shared : SharedLoad<load>;
def st_shared : SharedStore<store>;

// The element scale comes from rdata's chwidth when [23] is set (O-7), so a
// float array indexed by element needs no shift instruction at all.
foreach ty = [i32, f32] in {
  // base + (index << 2), scale enable set: the shift is chwidth-derived.
  def : Pat<(ty (ld_shared (add GPR:$rbase, (shl GPR:$ri, (i32 2))))),
            (LD_SHARED_IDX GPR:$rbase, GPR:$ri, 1, 0)>;
  def : Pat<(st_shared ty:$v, (add GPR:$rbase, (shl GPR:$ri, (i32 2)))),
            (ST_SHARED_IDX GPR:$v, GPR:$rbase, GPR:$ri, 1, 0)>;
  // base + register index already in bytes: scale enable clear.
  def : Pat<(ty (ld_shared (add GPR:$rbase, GPR:$ri))),
            (LD_SHARED_IDX GPR:$rbase, GPR:$ri, 0, 0)>;
  def : Pat<(st_shared ty:$v, (add GPR:$rbase, GPR:$ri)),
            (ST_SHARED_IDX GPR:$v, GPR:$rbase, GPR:$ri, 0, 0)>;
  // base + immediate displacement, and the bare base.
  def : Pat<(ty (ld_shared (add GPR:$rbase, (i32 imm:$off)))),
            (LD_SHARED GPR:$rbase, imm:$off)>;
  def : Pat<(st_shared ty:$v, (add GPR:$rbase, (i32 imm:$off))),
            (ST_SHARED GPR:$v, GPR:$rbase, imm:$off)>;
  def : Pat<(ty (ld_shared GPR:$rbase)), (LD_SHARED GPR:$rbase, 0)>;
  def : Pat<(st_shared ty:$v, GPR:$rbase), (ST_SHARED GPR:$v, GPR:$rbase, 0)>;
}

// ---------------------------------------------------------------------------
// Predicate logic (O-20). These are the i1 domain -- a predicate is 32 bits,
// one per lane, and never narrows (invariant 5), so i1 operations are real
// register operations rather than something to widen into a GPR.
// ---------------------------------------------------------------------------
def : Pat<(and PR:$a, PR:$b), (PSEUDO_PAND PR:$a, PR:$b)>;
def : Pat<(or  PR:$a, PR:$b), (PSEUDO_POR  PR:$a, PR:$b)>;
def : Pat<(xor PR:$a, PR:$b), (PSEUDO_PXOR PR:$a, PR:$b)>;

// ---------------------------------------------------------------------------
// Conversions and SFU (§4 points 128+ and 256+, O-31).
// ---------------------------------------------------------------------------
def : Pat<(f32 (sint_to_fp GPR:$a)), (CVT_F32_S32 GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(f32 (uint_to_fp GPR:$a)), (CVT_F32_U32 GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(i32 (fp_to_sint GPR:$a)), (CVT_S32_F32 GPR:$a, GPR:$a, GPR:$a)>;
def : Pat<(i32 (fp_to_uint GPR:$a)), (CVT_U32_F32 GPR:$a, GPR:$a, GPR:$a)>;

// 1.0f / x is the reciprocal instruction. This is the only fdiv this backend
// selects: general float division needs a Newton sequence of its own and is
// not implemented -- see F-49.
def fpimm_one : PatLeaf<(fpimm), [{ return N->isExactlyValue(1.0); }]>;
def : Pat<(fdiv fpimm_one, GPR:$a), (RCP_F32 GPR:$a, GPR:$a, GPR:$a)>;

def : Pat<(fsqrt GPR:$a), (SQRT_F32 GPR:$a, GPR:$a, GPR:$a)>;

// ---------------------------------------------------------------------------
// 16-bit element width (§1, F-3).
//
// The register is the same register; only how many of its bits are the element
// changes, and that is state rather than an operand. So these patterns pick
// instructions that differ from their 32-bit namesakes ONLY in the TSFlags bit
// that CCVInsertChwidth reads -- the encoding is identical.
//
// `trunc i32 -> i16` is free: the consumer reads at width 16 and the bits above
// the element are not part of the register. The reverse is NOT free and has no
// pattern here -- widening a narrow register yields unspecified high bits
// (F-65), so zext and sext need real instructions. Nothing emits them yet.
def : Pat<(i16 (trunc GPR:$a)), (COPY GPR:$a)>;

def : Pat<(add GPR16:$a, GPR16:$b), (ADD_W16 GPR16:$a, GPR16:$b, GPR16:$a)>;
def : Pat<(sub GPR16:$a, GPR16:$b), (SUB_W16 GPR16:$a, GPR16:$b, GPR16:$a)>;
def : Pat<(and GPR16:$a, GPR16:$b), (AND_W16 GPR16:$a, GPR16:$b, GPR16:$a)>;
def : Pat<(or GPR16:$a, GPR16:$b), (OR_W16 GPR16:$a, GPR16:$b, GPR16:$a)>;
def : Pat<(xor GPR16:$a, GPR16:$b), (XOR_W16 GPR16:$a, GPR16:$b, GPR16:$a)>;

def : Pat<(i16 (ld_shared GPR:$rbase)), (LD_SHARED_W16 GPR:$rbase, 0)>;
def : Pat<(st_shared GPR16:$v, GPR:$rbase), (ST_SHARED_W16 GPR16:$v, GPR:$rbase, 0)>;
def : Pat<(i16 (ld_shared (add GPR:$rbase, (i32 imm:$off)))),
          (LD_SHARED_W16 GPR:$rbase, imm:$off)>;
def : Pat<(st_shared GPR16:$v, (add GPR:$rbase, (i32 imm:$off))),
          (ST_SHARED_W16 GPR16:$v, GPR:$rbase, imm:$off)>;
