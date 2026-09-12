//===-- CCGInstrInfo.td - CCG instruction definitions -------*- tablegen -*-===//
//
// Instruction set for docs/isa-v1.5-operation-map-and-encoding.md.
// Coverage goal for Step 1 is one instruction per format plus everything the
// worked prologue in §5.5 needs -- not full opcode-map coverage. Opcode values
// are taken from §3 and §4; where the spec lists a range without fixing points,
// the assignment here is the first free point and is marked ASSIGNED.
//
//===----------------------------------------------------------------------===//

// ---------------------------------------------------------------------------
// Operand classes
// ---------------------------------------------------------------------------
def simm13  : Operand<i32>;
def simm10  : Operand<i32>;
def simm8   : Operand<i32>;
def simm9   : Operand<i32>;
def simm21  : Operand<i32>;
def simm17  : Operand<i32>;
def simm18  : Operand<i32>;
def uimm2   : Operand<i32>;
def uimm3   : Operand<i32>;
def uimm4   : Operand<i32>;
def uimm5   : Operand<i32>;
def uimm6   : Operand<i32>;
def uimm8   : Operand<i32>;
def uimm10  : Operand<i32>;
def uimm16  : Operand<i32>;
def uimm17  : Operand<i32>;
def uimm29  : Operand<i32>;
def uimm32  : Operand<i32>;
def uimm33  : Operand<i32>;
// 2-bit predicate address + negate (§1). Printed as @p1 / @!p1 rather than as
// a raw field value -- these listings are the verification artifact.
def pqual   : Operand<i32> { let PrintMethod = "printPredQual"; }
def brtarget21 : Operand<OtherVT> { let EncoderMethod = "getBranch21OpValue"; }
def brtarget18 : Operand<OtherVT> { let EncoderMethod = "getBranch18OpValue"; }
def psrc    : Operand<i32>;   // same shape, used by predicate logic
def pmask4  : Operand<i32>;   // 4-bit predicate bitmask for ld.pred/st.pred
def srdsel  : Operand<i32>;   // srd selector

// ---------------------------------------------------------------------------
// Format A -- ALU register-register. §4 integer map, points 0-31.
// ---------------------------------------------------------------------------
let isReMaterializable = 1 in
def ADD  : FormatA<0,  (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                   "add $rd, $rs0, $rs1">;
def MADLO : FormatA<5, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                    "mad.lo $rd, $rs0, $rs1, $rs2">;
// FP lives at points 32-63, format code in the low 2 bits of the sub-range.
def FFMA_F0 : FormatA<35, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                      "ffma.f0 $rd, $rs0, $rs1, $rs2">;
// dp4 lives at 64-127, signedness per operand. All operands are chwidth=32.
def DP4_SS : FormatA<64, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     "dp4.ss $rd, $rs0, $rs1, $rs2">;

def ADD_P : FormatAp<0, (outs GPR:$rd), (ins pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     "@$pq add $rd, $rs0, $rs1">;
def ADD_PP : FormatApp<0, (outs GPR:$rd, PR:$pd),
                       (ins pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                       "@$pq add $rd, $rs0, $rs1, $pd">;

// ---------------------------------------------------------------------------
// Format B -- ALU register-immediate, and its 48-bit sibling.
// ---------------------------------------------------------------------------
def ADDI   : FormatB<0,  (outs GPR:$rd), (ins GPR:$rs0, simm13:$imm),
                     "add $rd, $rs0, $imm">;
def ADDI48 : FormatB48<0, (outs GPR:$rd), (ins GPR:$rs0, uimm29:$imm),
                       "add $rd, $rs0, $imm">;
def ADDI_P : FormatBp<0, (outs GPR:$rd), (ins pqual:$pq, GPR:$rs0, simm10:$imm),
                      "@$pq add $rd, $rs0, $imm">;
def ADDI_PP : FormatBpp<0, (outs GPR:$rd, PR:$pd),
                        (ins pqual:$pq, GPR:$rs0, simm8:$imm),
                        "@$pq add $rd, $rs0, $imm, $pd">;

// packi reads its destination -- the one rd-as-source deviation in Format B.
// packi.z clears the slots it does not write (v1.3, O-21). ASSIGNED: 20, 21.
let Constraints = "$rd = $rd_in" in
def PACKI : FormatB<20, (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs0, uimm3:$imm),
                    "packi $rd, $rs0, $imm">;
def PACKI_Z : FormatB<21, (outs GPR:$rd), (ins GPR:$rs0, uimm3:$imm),
                      "packi.z $rd, $rs0, $imm">;
def UNPACKI : FormatB<22, (outs GPR:$rd), (ins GPR:$rs0, uimm3:$imm),
                      "unpacki $rd, $rs0, $imm">;

// ---------------------------------------------------------------------------
// Format C / C' -- compare. Predicate destination is mandatory.
// ---------------------------------------------------------------------------
// §3: the 5-bit opcode covers {6 comparison predicates} x {signed, unsigned,
// FP} = 18 points. Signed integer forms; ASSIGNED 0-3. `gt` and `ge` come from
// swapping the operands rather than spending points on them.
def SETP_LT : FormatC<0, (outs PR:$pd, GPR:$rd), (ins pqual:$pq, GPR:$rs0, GPR:$rs1),
                      "@$pq setp.lt $pd, $rs0, $rs1">;
def SETP_LE : FormatC<1, (outs PR:$pd, GPR:$rd), (ins pqual:$pq, GPR:$rs0, GPR:$rs1),
                      "@$pq setp.le $pd, $rs0, $rs1">;
def SETP_EQ : FormatC<2, (outs PR:$pd, GPR:$rd), (ins pqual:$pq, GPR:$rs0, GPR:$rs1),
                      "@$pq setp.eq $pd, $rs0, $rs1">;
def SETP_NE : FormatC<3, (outs PR:$pd, GPR:$rd), (ins pqual:$pq, GPR:$rs0, GPR:$rs1),
                      "@$pq setp.ne $pd, $rs0, $rs1">;
def SETP_GE_I : FormatCp<3, (outs PR:$pd, GPR:$rd),
                         (ins pqual:$pq, GPR:$rs0, simm8:$imm),
                         "@$pq setp.ge $pd, $rs0, $imm">;

// ---------------------------------------------------------------------------
// Format D -- load / store. §3 opcode map.
// 00000-00011 base+offset, 00100-00111 base+index, 01000-01011 predicate
// transfer (v1.3, O-19), 01100+ reserved for span.
// ---------------------------------------------------------------------------
def LD_GLOBAL  : FormatD<0b00000, (outs GPR:$rdata), (ins GPR:$rbase, simm13:$off),
                         "ld.global $rdata, [$rbase + $off]">;
def ST_GLOBAL  : FormatD<0b00001, (outs), (ins GPR:$rdata, GPR:$rbase, simm13:$off),
                         "st.global $rdata, [$rbase + $off]">;
def LD_SHARED  : FormatD<0b00010, (outs GPR:$rdata), (ins GPR:$rbase, simm13:$off),
                         "ld.shared $rdata, [$rbase + $off]">;
def ST_SHARED  : FormatD<0b00011, (outs), (ins GPR:$rdata, GPR:$rbase, simm13:$off),
                         "st.shared $rdata, [$rbase + $off]">;

// Base+index. For .global the AGU computes (rbase << 16) + (rindex << scale)
// + disp; the shift comes from the address space, not from a field. §5.1.
def LD_GLOBAL_IDX : FormatDidx<0b00100, (outs GPR:$rdata),
                               (ins GPR:$rbase, GPR:$rindex, uimm2:$scale, simm8:$disp),
                               "ld.global $rdata, [$rbase, $rindex, $scale, $disp]">;
def ST_GLOBAL_IDX : FormatDidx<0b00101, (outs),
                               (ins GPR:$rdata, GPR:$rbase, GPR:$rindex, uimm2:$scale, simm8:$disp),
                               "st.global $rdata, [$rbase, $rindex, $scale, $disp]">;

// Predicate transfer (v1.3, O-19). [14:11] is a predicate mask, not rdata.
def LD_PRED_G : FormatD<0b01000, (outs), (ins pmask4:$rdata, GPR:$rbase, simm13:$off),
                        "ld.pred $rdata, [$rbase + $off]">;
def ST_PRED_G : FormatD<0b01001, (outs), (ins pmask4:$rdata, GPR:$rbase, simm13:$off),
                        "st.pred $rdata, [$rbase + $off]">;
def LD_PRED_S : FormatD<0b01010, (outs), (ins pmask4:$rdata, GPR:$rbase, simm13:$off),
                        "ld.pred.shared $rdata, [$rbase + $off]">;
def ST_PRED_S : FormatD<0b01011, (outs), (ins pmask4:$rdata, GPR:$rbase, simm13:$off),
                        "st.pred.shared $rdata, [$rbase + $off]">;

def LD_GLOBAL_P : FormatDp<0b00000, (outs GPR:$rdata),
                           (ins pqual:$pq, GPR:$rbase, simm10:$off),
                           "@$pq ld.global $rdata, [$rbase + $off]">;

// ---------------------------------------------------------------------------
// Format M / M' -- atomics.
// ---------------------------------------------------------------------------
def ATOM_ADD_G : FormatM<0, (outs GPR:$rd), (ins GPR:$rbase, GPR:$rs1, simm9:$off),
                         "atom.add.global $rd, [$rbase + $off], $rs1">;
def CAS_G : FormatMp<16, (outs GPR:$rd, PR:$pd),
                     (ins pqual:$pq, GPR:$rbase, GPR:$rs1, GPR:$rs2, uimm16:$off),
                     "@$pq cas.global $rd, [$rbase + $off], $rs1, $rs2, $pd">;

// ---------------------------------------------------------------------------
// Format E -- control flow, barrier.
// ---------------------------------------------------------------------------
let isBranch = 1, isTerminator = 1, isBarrier = 1 in
def BRA : FormatEbra<0b00000, (outs), (ins brtarget21:$off), "bra $off">;

let isBranch = 1, isTerminator = 1 in
def BRA_PRED : FormatEbrap<0b00001, (outs), (ins pqual:$pq, brtarget18:$off),
                           "@$pq bra $off">;

let isCall = 1 in
def CALL : FormatEcall<0b00010, (outs GPR:$rd), (ins simm17:$off), "call $rd, $off">;

def BAR_INIT : FormatEbarinit<0b00011, (outs), (ins uimm6:$barid, uimm10:$count),
                              "bar.init $barid, $count">;

// ---------------------------------------------------------------------------
// Format F -- wide immediate. The 48-bit form materializes any 32-bit constant
// in one instruction, which is what the prologue uses for the launch base.
// ---------------------------------------------------------------------------
let isReMaterializable = 1, isAsCheapAsAMove = 1 in {
def MOVI   : FormatF<0,   (outs GPR:$rd), (ins uimm17:$imm), "movi $rd, $imm">;
def MOVI48 : FormatF48<0, (outs GPR:$rd), (ins uimm33:$imm), "f48 $rd, $imm">;
}

// ---------------------------------------------------------------------------
// Format G -- warp-collective. unballot added in v1.3 (O-14).
// ASSIGNED: shfl.idx 0, ballot 8, unballot 9.
// ---------------------------------------------------------------------------
def SHFL_IDX : FormatGshfl<0, (outs GPR:$rd), (ins pqual:$pq, GPR:$rs0, uimm5:$lane),
                           "@$pq shfl.idx $rd, $rs0, $lane">;
def VOTE_ANY : FormatGvote<4, (outs PR:$pd), (ins pqual:$pq, psrc:$ps),
                           "@$pq vote.any $pd, $ps">;
def BALLOT   : FormatGballot<8, (outs GPR:$rd), (ins pqual:$pq, psrc:$ps),
                             "@$pq ballot $rd, $ps">;
def UNBALLOT : FormatGunballot<9, (outs PR:$pd), (ins pqual:$pq, GPR:$rs0),
                               "@$pq unballot $pd, $rs0">;

// ---------------------------------------------------------------------------
// Format I -- metadata. Subops live at different lengths (invariant 7).
// ---------------------------------------------------------------------------
def CHWIDTH_MULTI : FormatIchw<(outs), (ins uimm16:$regmask, uimm2:$width),
                               "chwidth.multi $regmask, $width">;
def PMOV_IMM : FormatIpmov<(outs PR:$pd), (ins uimm32:$lanemask),
                           "pmov $pd, $lanemask">;

// ---------------------------------------------------------------------------
// Format J -- compressed accumulate. rd is read and written.
// ---------------------------------------------------------------------------
let Constraints = "$rd = $rd_in" in {
def FFMA_ACC_F0 : FormatJ<0b00, (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs0, GPR:$rs1),
                          "ffma.acc.f0 $rd, $rs0, $rs1">;
def FFMA_ACC_F1 : FormatJ<0b01, (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs0, GPR:$rs1),
                          "ffma.acc.f1 $rd, $rs0, $rs1">;
def DP4_ACC     : FormatJ<0b10, (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs0, GPR:$rs1),
                          "dp4.acc $rd, $rs0, $rs1">;
def MAD_ACC     : FormatJ<0b11, (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs0, GPR:$rs1),
                          "mad.acc $rd, $rs0, $rs1">;
}

// ---------------------------------------------------------------------------
// Format K -- compressed. Opcode map from §3.
// ---------------------------------------------------------------------------
let Constraints = "$rd = $rd_in" in {
def C_ADD  : FormatKrr<0,  (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs), "add $rd, $rs">;
def C_SHL  : FormatKrr<7,  (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs), "shl $rd, $rs">;
def C_FADD : FormatKrr<18, (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs), "fadd $rd, $rs">;
def C_ADDI : FormatKri<32, (outs GPR:$rd), (ins GPR:$rd_in, uimm4:$imm), "add $rd, $imm">;
def C_SHLI : FormatKri<37, (outs GPR:$rd), (ins GPR:$rd_in, uimm4:$imm), "shl $rd, $imm">;
}
def C_MOV  : FormatKrr<14, (outs GPR:$rd), (ins GPR:$rs), "mov $rd, $rs">;

// Compressed load/store, implicit zero offset (points 24-27).
def C_LD_GLOBAL : FormatKmem<24, (outs GPR:$rd), (ins GPR:$rbase), "ld.global $rd, [$rbase]">;
def C_ST_GLOBAL : FormatKmem<25, (outs), (ins GPR:$rd, GPR:$rbase), "st.global $rd, [$rbase]">;

// srd -- identity / dynamic state read (v1.3, O-18). Point 28.
let isReMaterializable = 1 in
def SRD : FormatKsrd<28, (outs GPR:$rd), (ins srdsel:$sel), "srd $rd, $sel">;

// Small-operand control ops (points 48-56).
def C_CHWIDTH : FormatKraw<48, (outs), (ins uimm8:$payload), "chwidth $payload">;
let isBranch = 1, isTerminator = 1, isBarrier = 1 in
def C_BRA     : FormatKraw<49, (outs), (ins uimm8:$payload), "bra.short $payload">;
def C_BAR_ARRIVE : FormatKraw<51, (outs), (ins uimm8:$payload), "bar.arrive $payload">;
def C_BAR_WAIT   : FormatKraw<52, (outs), (ins uimm8:$payload), "bar.wait $payload">;
let isReturn = 1, isTerminator = 1 in
def C_RET     : FormatKraw<53, (outs), (ins uimm8:$payload), "ret $payload">;
let isTerminator = 1, isBarrier = 1 in
def C_EXIT    : FormatKraw<54, (outs), (ins uimm8:$payload), "exit">;
def C_RECONV  : FormatKraw<55, (outs), (ins uimm8:$payload), "reconv.hint $payload">;
def C_FENCE   : FormatKraw<56, (outs), (ins uimm8:$payload), "fence $payload">;

// Predicate logic (v1.3, O-20). Points 60-63. Three points reach every
// two-input boolean function; the fourth buys rename-time copy elision.
def PAND : FormatKplog<60, (outs PR:$pd), (ins psrc:$ps0, psrc:$ps1), "pand $pd, $ps0, $ps1">;
def POR  : FormatKplog<61, (outs PR:$pd), (ins psrc:$ps0, psrc:$ps1), "por $pd, $ps0, $ps1">;
def PXOR : FormatKplog<62, (outs PR:$pd), (ins psrc:$ps0, psrc:$ps1), "pxor $pd, $ps0, $ps1">;
def PMOV : FormatKplog<63, (outs PR:$pd), (ins psrc:$ps0, psrc:$ps1), "pmov $pd, $ps0">;


// ---------------------------------------------------------------------------
// Codegen pseudos -- see the note above. None of these encode; each expands to
// a real instruction in CCGExpandPseudos, after register allocation.
// ---------------------------------------------------------------------------
let isPseudo = 1, isCodeGenOnly = 1, Size = 0 in {

  // O-24: Formats C/C' carry a MANDATORY predicate qualifier and there is no
  // unpredicated compare, so every compare needs a true guard. Expands to
  // `por pd, !pd, pd`, which is all-ones whatever pd held.
  def PSEUDO_PTRUE : CCGInst<0, (outs PR:$pd), (ins), "# ptrue $pd">;

  // The guard is TIED to the destination, which forces the self-guarding form
  // of the O-24 addendum: `por P0,!P0,P0` then `@P0 setp P0, ...`. One
  // predicate, not two, so the effective file stays at four.
  let Constraints = "$pd = $guard" in {
    foreach cc = ["LT", "LE", "EQ", "NE"] in
      def PSEUDO_SETP_#cc : CCGInst<0, (outs PR:$pd),
                                    (ins PR:$guard, GPR:$a, GPR:$b),
                                    "# setp."#cc#" $pd, $a, $b">;
  }

  let isBranch = 1, isTerminator = 1 in
  def PSEUDO_BRA_PRED : CCGInst<0, (outs), (ins PR:$guard, brtarget18:$off),
                                "# @$guard bra $off">;
}
