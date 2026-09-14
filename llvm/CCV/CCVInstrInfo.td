//===-- CCVInstrInfo.td - CCV instruction definitions -------*- tablegen -*-===//
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
// Signed fields need an explicit decoder: TableGen's default zero-extends the
// field, which silently turns every negative displacement and every backward
// branch into a huge positive one. See F-39.
class SImm<int n> : Operand<i32> {
  let DecoderMethod = "decodeSImm<" # n # ">";
}
def simm13  : SImm<13>;
def simm10  : SImm<10>;
def simm8   : SImm<8>;
def simm9   : SImm<9>;
def simm21  : SImm<21>;
def simm17  : SImm<17>;
def simm18  : SImm<18>;
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
// Branch offsets are halfword-granular and SIGNED -- §3 puts the sign bit at 31
// in both forms. The decoder side needs saying explicitly for the same reason
// the simm classes do (F-39): a backward branch is the common case that the
// default zero-extension gets wrong.
def brtarget21 : Operand<OtherVT> {
  let EncoderMethod = "getBranch21OpValue";
  let DecoderMethod = "decodeSImm<21>";
}
def brtarget18 : Operand<OtherVT> {
  let EncoderMethod = "getBranch18OpValue";
  let DecoderMethod = "decodeSImm<18>";
}
def brtarget8 : Operand<OtherVT> {
  let EncoderMethod = "getBranch8OpValue";
  let DecoderMethod = "decodeSImm<8>";
}
def psrc    : Operand<i32>;   // same shape, used by predicate logic
def pmask4  : Operand<i32>;   // 4-bit predicate bitmask for ld.pred/st.pred
def pidx2   : Operand<i32>;   // 2-bit predicate address, read side, no negate
def srdsel  : Operand<i32>;   // srd selector

// ---------------------------------------------------------------------------
// Format A -- ALU register-register. §4 integer map, points 0-31.
// ---------------------------------------------------------------------------
// §4 lists 26 operations for points 0-31 but assigns no numbers. The numbering
// below is the order §4 lists them in, which is what `add` = 0 and `mad.lo` = 5
// already assumed. See O-28: this is now load-bearing in the encoder, the
// decoder and the simulator, so it is spec, not a backend detail.
class AluOpc {
  int ADD = 0;      int SUB = 1;      int MUL_LO = 2;   int MUL_HI_S = 3;
  int MUL_HI_U = 4; int MAD_LO = 5;   int MAD_HI = 6;   int AND = 7;
  int OR = 8;       int XOR = 9;      int ANDN = 10;    int SHL = 11;
  int SHR = 12;     int SRA = 13;     int MIN_S = 14;   int MIN_U = 15;
  int MAX_S = 16;   int MAX_U = 17;   int MOV = 18;     int SEL = 19;
  int ABS = 20;     int NEG = 21;     int POPC = 22;    int CLZ = 23;
  int BREV = 24;    int PRMT = 25;
}
def aluOpc : AluOpc;

// Two-source integer. Format A is three-source, so rs2 goes unread and is tied
// to rs0 by the pattern rather than left as a second live value.
multiclass AluRR<int opc, string mnem> {
  def NAME : FormatA<opc, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     mnem#" $rd, $rs0, $rs1">;
}
let isReMaterializable = 1 in
defm ADD : AluRR<aluOpc.ADD, "add">;
defm SUB     : AluRR<aluOpc.SUB,   "sub">;
defm AND     : AluRR<aluOpc.AND,   "and">;
defm OR      : AluRR<aluOpc.OR,    "or">;
defm XOR     : AluRR<aluOpc.XOR,   "xor">;
defm ANDN    : AluRR<aluOpc.ANDN,  "andn">;
defm SHL     : AluRR<aluOpc.SHL,   "shl">;
defm SHR     : AluRR<aluOpc.SHR,   "shr">;
defm SRA     : AluRR<aluOpc.SRA,   "sra">;
defm MIN_S   : AluRR<aluOpc.MIN_S, "min.s">;
defm MIN_U   : AluRR<aluOpc.MIN_U, "min.u">;
defm MAX_S   : AluRR<aluOpc.MAX_S, "max.s">;
defm MAX_U   : AluRR<aluOpc.MAX_U, "max.u">;
defm MUL_HI_S : AluRR<aluOpc.MUL_HI_S, "mul.hi.s">;
defm MUL_HI_U : AluRR<aluOpc.MUL_HI_U, "mul.hi.u">;

def MADLO : FormatA<aluOpc.MAD_LO, (outs GPR:$rd),
                    (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                    "mad.lo $rd, $rs0, $rs1, $rs2">;

// One-source integer. rs1 and rs2 go unread.
multiclass AluR<int opc, string mnem> {
  def NAME : FormatA<opc, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     mnem#" $rd, $rs0">;
}
defm NEG  : AluR<aluOpc.NEG,  "neg">;
defm ABS  : AluR<aluOpc.ABS,  "abs">;
defm POPC : AluR<aluOpc.POPC, "popc">;
defm CLZ  : AluR<aluOpc.CLZ,  "clz">;
defm BREV : AluR<aluOpc.BREV, "brev">;

// FP lives at points 32-63: eight operations in a block per format code, so the
// opcode is 32 + 8*fmt + op. That is what `ffma.f0` = 35 already assumed
// (32 + 0 + 3), and it is why Format K can carry `fadd.f0`/`fadd.f1` as
// adjacent points. See O-28.
class FpOp {
  int FADD = 0; int FSUB = 1; int FMUL = 2; int FFMA = 3;
  int FMIN = 4; int FMAX = 5; int FNEG = 6; int FABS = 7;
}
def fpOp : FpOp;
class FpOpc<int op, int fmt> { int V = !add(32, !add(!mul(8, fmt), op)); }

multiclass FpRR<int op, string mnem> {
  def NAME : FormatA<FpOpc<op, 0>.V, (outs GPR:$rd),
                     (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     mnem#".f0 $rd, $rs0, $rs1">;
}
defm FADD : FpRR<fpOp.FADD, "fadd">;
defm FSUB : FpRR<fpOp.FSUB, "fsub">;
defm FMUL : FpRR<fpOp.FMUL, "fmul">;
defm FMIN : FpRR<fpOp.FMIN, "fmin">;
defm FMAX : FpRR<fpOp.FMAX, "fmax">;
def FNEG_F0 : FormatA<FpOpc<fpOp.FNEG, 0>.V, (outs GPR:$rd),
                      (ins GPR:$rs0, GPR:$rs1, GPR:$rs2), "fneg.f0 $rd, $rs0">;
def FABS_F0 : FormatA<FpOpc<fpOp.FABS, 0>.V, (outs GPR:$rd),
                      (ins GPR:$rs0, GPR:$rs1, GPR:$rs2), "fabs.f0 $rd, $rs0">;
// §4 reserves 128-255 for conversions and 256+ for SFU. Both were empty, which
// is why integer division fell back to a 32-iteration shift-subtract loop: the
// float-reciprocal algorithm every GPU uses needs exactly these two things.
// Only the points actually needed are assigned; the rest of both ranges stays
// reserved rather than being filled in speculatively. See O-31.
// Conversions, §4 points 64-127. The block is a product, and the arithmetic is
// normative (O-34, extending O-28 to the third range that needed a rule rather
// than a list):
//
//     opcode = 64 + 16*dest + 4*src + round
//
// `dest` and `src` are 2-bit FORMAT CODES, read against each register's
// `chwidth` exactly as `fadd.f0`'s format code is -- 00/01 are the two FP
// interpretations at that width, 10 is signed integer, 11 is unsigned. The
// instruction therefore names no width, which is invariant 1, and which the
// superseded eight-base scheme (`cvt2fp32`, `cvt2fp16`, ...) did not satisfy:
// those bases differed only in element width.
//
// dest and src are adjacent so the pair forms one 4-bit field naming the
// conversion path, which is what a converter datapath selects on; rounding is
// rounding-logic control and sits in the low bits.
class FmtCode { int FP0 = 0; int FP1 = 1; int SINT = 2; int UINT = 3; }
def fmtCode : FmtCode;
class Round { int RN = 0; int RZ = 1; int RM = 2; int RP = 3; }
def round : Round;
class CvtOpc<int dest, int src, int rnd> {
  int V = !add(64, !add(!mul(16, dest), !add(!mul(4, src), rnd)));
}
multiclass Cvt<int opc, string mnem> {
  def NAME : FormatA<opc, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     mnem#" $rd, $rs0">;
  // Inside A′'s 7-bit reach now, so conversions can be masked to lane 0 (O-33).
  def NAME#_P : FormatAp<opc, (outs GPR:$rd),
                         (ins pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                         "@$pq "#mnem#" $rd, $rs0">;
}
defm CVT_F32_S32 : Cvt<CvtOpc<fmtCode.FP0,  fmtCode.SINT, round.RN>.V, "cvt.f32.s32">;
defm CVT_F32_U32 : Cvt<CvtOpc<fmtCode.FP0,  fmtCode.UINT, round.RN>.V, "cvt.f32.u32">;
defm CVT_S32_F32 : Cvt<CvtOpc<fmtCode.SINT, fmtCode.FP0,  round.RZ>.V, "cvt.s32.f32">;
defm CVT_U32_F32 : Cvt<CvtOpc<fmtCode.UINT, fmtCode.FP0,  round.RZ>.V, "cvt.u32.f32">;

// SFU, §4 point 256+. `rcp` is the one the division algorithm needs; the rest
// of the classic set is here because they share the unit and CUDA requires
// them, and because assigning them together fixes the numbering once (O-28).
class SfuOpc { int RCP = 256; int RSQRT = 257; int SQRT = 258;
               int EX2 = 259; int LG2 = 260; int SIN = 261; int COS = 262;
               int RCP_U32 = 263; }
def sfuOpc : SfuOpc;
multiclass Sfu<int opc, string mnem> {
  def NAME : FormatA<opc, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     mnem#" $rd, $rs0">;
}
defm RCP_F32   : Sfu<sfuOpc.RCP,   "rcp.f32">;
defm RSQRT_F32 : Sfu<sfuOpc.RSQRT, "rsqrt.f32">;
defm SQRT_F32  : Sfu<sfuOpc.SQRT,  "sqrt.f32">;
defm EX2_F32   : Sfu<sfuOpc.EX2,   "ex2.f32">;
defm LG2_F32   : Sfu<sfuOpc.LG2,   "lg2.f32">;
defm SIN_F32   : Sfu<sfuOpc.SIN,   "sin.f32">;
defm COS_F32   : Sfu<sfuOpc.COS,   "cos.f32">;

// Integer reciprocal seed, §4 point 263 (O-35).
//
// `rcp.u32 rd, rs` returns an UNDER-ESTIMATE of floor(2^32 / rs) with 16 bits
// of RELATIVE accuracy:
//
//     floor(2^32/rs) * (1 - 2^-16)  <=  rd  <=  floor(2^32/rs)
//
// Two halves of that contract, both load-bearing:
//
//  - RELATIVE, not absolute. A reciprocal unit produces N correct leading bits,
//    so the absolute error scales with the result and a large divisor -- whose
//    reciprocal is small -- is cheap to get right.
//
//  - NEVER AN OVER-ESTIMATE. The Newton step that follows converges only from
//    below: if the seed exceeds 2^32/d then e*d wraps past 2^32 and the
//    correction term becomes huge instead of small, pushing the estimate
//    further out. This is the same requirement that makes the fp32 path scale
//    by 0x4F7FFFFE rather than by 2^32 (O-31); it is now the hardware's to
//    honour rather than the compiler's to engineer around.
//
// 16 bits is not a guess. tools/model-rcp.py runs the sequence against exact
// integer division over the edge cases and a large sample, at every accuracy
// from 1 bit up, and 16 is the least that is exact -- which is what one Newton
// step doubling to 32 predicts. See O-35.
defm RCP_U32   : Sfu<sfuOpc.RCP_U32, "rcp.u32">;

def FFMA_F0 : FormatA<FpOpc<fpOp.FFMA, 0>.V, (outs GPR:$rd),
                      (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                      "ffma.f0 $rd, $rs0, $rs1, $rs2">;
// dp4/dp8 live at 48-63, signedness per operand. All operands are chwidth=32.
//
// That range is what `32 + 8*format + op` would generate for FP format codes
// 10 and 11, which are reserved at every `chwidth` and hold nothing. Taking it
// keeps dp inside A′'s reach AND leaves 64-127 for conversions -- the two do
// not have to compete (O-34). The price is that the FP formula's domain is now
// format in {00, 01}: an FP instruction emitted at code 10 or 11 would silently
// alias a dp opcode. tools/check-encoding.py rejects that.
def DP4_SS : FormatA<48, (outs GPR:$rd), (ins GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     "dp4.ss $rd, $rs0, $rs1, $rs2">;

// Predicated twins, Format A′ (O-33). These are what mask-and-broadcast
// selects: a warp-uniform computation runs with only lane 0 active and the
// result is broadcast, so lanes 1-31 never switch.
//
// §4 puts A′'s opcode at SEVEN bits, so only points 0-127 are reachable this
// way. O-34 moved conversions into that range, so the division sequence's two
// `cvt`s can now be masked. `rcp.f32` still cannot: the SFU is at 256+ and
// 128-255 is Format A only, so relocating the SFU there would not help. One
// instruction of the division sequence therefore still burns all 32 lanes --
// see F-56.
multiclass AluRRP<int opc, string mnem> {
  def NAME : FormatAp<opc, (outs GPR:$rd),
                      (ins pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                      "@$pq "#mnem#" $rd, $rs0, $rs1">;
}
defm ADD_P   : AluRRP<aluOpc.ADD,   "add">;
defm SUB_P   : AluRRP<aluOpc.SUB,   "sub">;
defm AND_P   : AluRRP<aluOpc.AND,   "and">;
defm OR_P    : AluRRP<aluOpc.OR,    "or">;
defm XOR_P   : AluRRP<aluOpc.XOR,   "xor">;
defm SHL_P   : AluRRP<aluOpc.SHL,   "shl">;
defm SHR_P   : AluRRP<aluOpc.SHR,   "shr">;
defm SRA_P   : AluRRP<aluOpc.SRA,   "sra">;
defm MIN_S_P : AluRRP<aluOpc.MIN_S, "min.s">;
defm MIN_U_P : AluRRP<aluOpc.MIN_U, "min.u">;
defm MAX_S_P : AluRRP<aluOpc.MAX_S, "max.s">;
defm MAX_U_P : AluRRP<aluOpc.MAX_U, "max.u">;
defm MUL_HI_S_P : AluRRP<aluOpc.MUL_HI_S, "mul.hi.s">;
defm MUL_HI_U_P : AluRRP<aluOpc.MUL_HI_U, "mul.hi.u">;

// §4 point 18, Format A′. A predicated move writes only the lanes the
// qualifier selects and preserves the rest (invariant 10), which is exactly
// `sel rd, a, rd` -- see PSEUDO_PMOV below and F-58.
let Constraints = "$rd = $false" in
def MOV_P : FormatAp<aluOpc.MOV, (outs GPR:$rd),
                     (ins GPR:$false, pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                     "@$pq mov $rd, $rs0">;

def MADLO_P : FormatAp<aluOpc.MAD_LO, (outs GPR:$rd),
                       (ins pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                       "@$pq mad.lo $rd, $rs0, $rs1, $rs2">;

// FP: 32 + 8*format + op (O-28), all inside A′'s reach at format code 0.
multiclass FpRRP<int op, string mnem> {
  def NAME : FormatAp<FpOpc<op, 0>.V, (outs GPR:$rd),
                      (ins pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                      "@$pq "#mnem#".f0 $rd, $rs0, $rs1">;
}
defm FADD_P : FpRRP<fpOp.FADD, "fadd">;
defm FSUB_P : FpRRP<fpOp.FSUB, "fsub">;
defm FMUL_P : FpRRP<fpOp.FMUL, "fmul">;

// §4 point 19. `sel` is predicated in shape but not in semantics: it writes rd
// unconditionally and the qualifier chooses which source, where every other
// predicated instruction writes only the lanes the qualifier selects and
// preserves the rest (invariant 10). That difference is exactly why it needs an
// opcode of its own rather than being `@p mov` plus `@!p mov`.
def SEL : FormatAp<aluOpc.SEL, (outs GPR:$rd),
                   (ins pqual:$pq, GPR:$rs0, GPR:$rs1, GPR:$rs2),
                   "@$pq sel $rd, $rs0, $rs1">;
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
// §3 allocates one 5-bit opcode map shared by C and C', so a mnemonic means the
// same opcode value whichever way its second operand arrives. That matters:
// the register form is reachable by swapping operands, but the immediate form
// is not -- `setp.ge rs0, #imm` cannot be expressed as `setp.le #imm, rs0` --
// so gt/ge need real points even though the selector never picks them for
// register-register. See O-26.
//
// 16 points, not the 18 of §3's original count: integer eq/ne compare bit
// patterns and are sign-agnostic, so they are not duplicated across the signed
// and unsigned classes.
class SetpOpc {
  int LT = 0;  int LE = 1;  int EQ = 2;  int NE = 3;  int GT = 4;  int GE = 5;
  int LT_U = 6;  int LE_U = 7;  int GT_U = 8;  int GE_U = 9;
  int LT_F = 10; int LE_F = 11; int EQ_F = 12; int NE_F = 13;
  int GT_F = 14; int GE_F = 15;
}
def setpOpc : SetpOpc;

// Unpredicated (Format C", O-32) alongside the two predicated forms. Same
// opcode map -- O-26 made it shared, so a mnemonic is one opcode value in all
// three formats.
multiclass Setp<int opc, string suffix> {
  def NAME    : FormatC<opc, (outs PR:$pd, GPR:$rd),
                        (ins pqual:$pq, GPR:$rs0, GPR:$rs1),
                        "@$pq setp."#suffix#" $pd, $rs0, $rs1">;
  def NAME#_I : FormatCp<opc, (outs PR:$pd, GPR:$rd),
                         (ins pqual:$pq, GPR:$rs0, simm8:$imm),
                         "@$pq setp."#suffix#" $pd, $rs0, $imm">;
  def NAME#_NP : FormatCu<opc, 0, (outs PR:$pd, GPR:$rd),
                         (ins GPR:$rs0, GPR:$rs1),
                         "setp."#suffix#" $pd, $rs0, $rs1">;
  def NAME#_NPI : FormatCu<opc, 1, (outs PR:$pd, GPR:$rd),
                          (ins GPR:$rs0, simm8:$imm),
                          "setp."#suffix#" $pd, $rs0, $imm">;
}

// Signed integer, and the sign-agnostic equalities.
defm SETP_LT : Setp<setpOpc.LT, "lt">;
defm SETP_LE : Setp<setpOpc.LE, "le">;
defm SETP_EQ : Setp<setpOpc.EQ, "eq">;
defm SETP_NE : Setp<setpOpc.NE, "ne">;
defm SETP_GT : Setp<setpOpc.GT, "gt">;
defm SETP_GE : Setp<setpOpc.GE, "ge">;
// Unsigned integer. No eq/ne: they would be the same instruction.
defm SETP_LT_U : Setp<setpOpc.LT_U, "lt.u">;
defm SETP_LE_U : Setp<setpOpc.LE_U, "le.u">;
defm SETP_GT_U : Setp<setpOpc.GT_U, "gt.u">;
defm SETP_GE_U : Setp<setpOpc.GE_U, "ge.u">;
// FP32. eq/ne are an exact complementary pair: `eq.f` is ordered-equal and
// `ne.f` is unordered-or-not-equal, so exactly one holds for any operand pair
// including NaN. The remaining orderings are reachable by negating a qualifier.
defm SETP_LT_F : Setp<setpOpc.LT_F, "lt.f">;
defm SETP_LE_F : Setp<setpOpc.LE_F, "le.f">;
defm SETP_EQ_F : Setp<setpOpc.EQ_F, "eq.f">;
defm SETP_NE_F : Setp<setpOpc.NE_F, "ne.f">;
defm SETP_GT_F : Setp<setpOpc.GT_F, "gt.f">;
defm SETP_GE_F : Setp<setpOpc.GE_F, "ge.f">;

// ---------------------------------------------------------------------------
// Format D -- load / store. §3 opcode map.
// 00000-00011 base+offset, 00100-00111 base+index, 01000-01011 predicate
// transfer (v1.3, O-19), 01100+ reserved for span.
// ---------------------------------------------------------------------------
let mayLoad = 1 in
// mayLoad/mayStore have to be stated explicitly here: these are selected in
// C++ from CCVISD nodes rather than from TableGen patterns, so there is nothing
// for TableGen to infer them from, and every memory instruction was marked as
// having no memory effect. Nothing has depended on it -- no scheduler is
// enabled -- but it is wrong for anything that reorders, and it made the
// simulator's counters classify every global access as ALU.
let mayLoad = 1 in
def LD_GLOBAL  : FormatD<0b00000, (outs GPR:$rdata), (ins GPR:$rbase, simm13:$off),
                         "ld.global $rdata, [$rbase + $off]">;
let mayStore = 1 in
let mayStore = 1 in
def ST_GLOBAL  : FormatD<0b00001, (outs), (ins GPR:$rdata, GPR:$rbase, simm13:$off),
                         "st.global $rdata, [$rbase + $off]">;
let mayLoad = 1 in
let mayLoad = 1 in
def LD_SHARED  : FormatD<0b00010, (outs GPR:$rdata), (ins GPR:$rbase, simm13:$off),
                         "ld.shared $rdata, [$rbase + $off]">;
let mayStore = 1 in
let mayStore = 1 in
def ST_SHARED  : FormatD<0b00011, (outs), (ins GPR:$rdata, GPR:$rbase, simm13:$off),
                         "st.shared $rdata, [$rbase + $off]">;

// Base+index. For .global the AGU computes (rbase << 16) + (rindex << scale)
// + disp; the shift comes from the address space, not from a field. §5.1.
let mayLoad = 1 in
def LD_GLOBAL_IDX : FormatDidx<0b00100, (outs GPR:$rdata),
                               (ins GPR:$rbase, GPR:$rindex, uimm2:$scale, simm8:$disp),
                               "ld.global $rdata, [$rbase, $rindex, $scale, $disp]">;
let mayStore = 1 in
def ST_GLOBAL_IDX : FormatDidx<0b00101, (outs),
                               (ins GPR:$rdata, GPR:$rbase, GPR:$rindex, uimm2:$scale, simm8:$disp),
                               "st.global $rdata, [$rbase, $rindex, $scale, $disp]">;

// .shared does not shift (§5.1): the AGU computes rbase + (rindex << scale) +
// disp, a plain three-input add. Chwidth-derived scaling applies unconditionally
// here -- there is no window offset to fold into the index, which is the reason
// O-7 fires for .shared and only for aligned .global.
let mayLoad = 1 in
def LD_SHARED_IDX : FormatDidx<0b00110, (outs GPR:$rdata),
                               (ins GPR:$rbase, GPR:$rindex, uimm2:$scale, simm8:$disp),
                               "ld.shared $rdata, [$rbase, $rindex, $scale, $disp]">;
let mayStore = 1 in
def ST_SHARED_IDX : FormatDidx<0b00111, (outs),
                               (ins GPR:$rdata, GPR:$rbase, GPR:$rindex, uimm2:$scale, simm8:$disp),
                               "st.shared $rdata, [$rbase, $rindex, $scale, $disp]">;

// Predicate transfer (v1.3, O-19). [14:11] is a predicate mask, not rdata.
let mayLoad = 1 in
def LD_PRED_G : FormatD<0b01000, (outs), (ins pmask4:$rdata, GPR:$rbase, simm13:$off),
                        "ld.pred $rdata, [$rbase + $off]">;
let mayStore = 1 in
def ST_PRED_G : FormatD<0b01001, (outs), (ins pmask4:$rdata, GPR:$rbase, simm13:$off),
                        "st.pred $rdata, [$rbase + $off]">;
let mayLoad = 1 in
def LD_PRED_S : FormatD<0b01010, (outs), (ins pmask4:$rdata, GPR:$rbase, simm13:$off),
                        "ld.pred.shared $rdata, [$rbase + $off]">;
let mayStore = 1 in
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

// O-27: wait for a named barrier to reach a phase the instruction names, rather
// than the one this warp last arrived in. Hardware epoch tracking answers
// "has my own arrival retired", which is the whole of __syncthreads() and none
// of a pipelined producer/consumer, where a warp arrives at one barrier and
// waits on another. The phase comes from a predicate so software can flip it
// per stage.
let hasSideEffects = 1, mayLoad = 1, mayStore = 1 in
def BAR_WAIT_PHASE : FormatEbarwait<0b00100, (outs),
                                    (ins pqual:$pq, uimm6:$barid, pidx2:$ps),
                                    "@$pq bar.wait.phase $barid, $ps">;

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
// §3 points 0-23, in the order §3 lists them. `add` = 0, `shl` = 7, `fadd.f0`
// = 18 and `mov` = 14 were already assigned and the order reproduces all four.
let Constraints = "$rd = $rd_in" in {
multiclass CAlu<int opc, string mnem> {
  def NAME : FormatKrr<opc, (outs GPR:$rd), (ins GPR:$rd_in, GPR:$rs),
                       mnem#" $rd, $rs">;
}
defm C_ADD    : CAlu<0,  "add">;
defm C_SUB    : CAlu<1,  "sub">;
defm C_MUL_LO : CAlu<2,  "mul.lo">;
defm C_AND    : CAlu<3,  "and">;
defm C_OR     : CAlu<4,  "or">;
defm C_XOR    : CAlu<5,  "xor">;
defm C_ANDN   : CAlu<6,  "andn">;
defm C_SHL    : CAlu<7,  "shl">;
defm C_SHR    : CAlu<8,  "shr">;
defm C_SRA    : CAlu<9,  "sra">;
defm C_MIN_S  : CAlu<10, "min.s">;
defm C_MIN_U  : CAlu<11, "min.u">;
defm C_MAX_S  : CAlu<12, "max.s">;
defm C_MAX_U  : CAlu<13, "max.u">;
defm C_FADD   : CAlu<18, "fadd">;
defm C_FMUL   : CAlu<20, "fmul">;
defm C_FMIN   : CAlu<22, "fmin">;
defm C_FMAX   : CAlu<23, "fmax">;

// Reg-immediate, points 32-47, 4-bit unsigned immediate. `add` = 32 and
// `shl` = 37 were already assigned; the set is a selection rather than a
// mirror of 0-15, which is what those two numbers imply. See O-28.
multiclass CAluI<int opc, string mnem> {
  def NAME : FormatKri<opc, (outs GPR:$rd), (ins GPR:$rd_in, uimm4:$imm),
                       mnem#" $rd, $imm">;
}
defm C_ADDI : CAluI<32, "add">;
defm C_SUBI : CAluI<33, "sub">;
defm C_ANDI : CAluI<34, "and">;
defm C_ORI  : CAluI<35, "or">;
defm C_XORI : CAluI<36, "xor">;
defm C_SHLI : CAluI<37, "shl">;
defm C_SHRI : CAluI<38, "shr">;
defm C_SRAI : CAluI<39, "sra">;
}
def C_NEG  : FormatKrr<15, (outs GPR:$rd), (ins GPR:$rs), "neg $rd, $rs">;
def C_NOT  : FormatKrr<16, (outs GPR:$rd), (ins GPR:$rs), "not $rd, $rs">;
def C_ABS  : FormatKrr<17, (outs GPR:$rd), (ins GPR:$rs), "abs $rd, $rs">;
def C_MOV  : FormatKrr<14, (outs GPR:$rd), (ins GPR:$rs), "mov $rd, $rs">;

// Compressed load/store, implicit zero offset (points 24-27).
def C_LD_GLOBAL : FormatKmem<24, (outs GPR:$rd), (ins GPR:$rbase), "ld.global $rd, [$rbase]">;
def C_ST_GLOBAL : FormatKmem<25, (outs), (ins GPR:$rd, GPR:$rbase), "st.global $rd, [$rbase]">;

// srd -- identity / dynamic state read (v1.3, O-18). Point 28.
let isReMaterializable = 1 in
def SRD : FormatKsrd<28, (outs GPR:$rd), (ins srdsel:$sel), "srd $rd, $sel">;

// Small-operand control ops (points 48-56).
def C_CHWIDTH : FormatKraw<48, (outs), (ins uimm8:$payload), "chwidth $payload">;
// §3 point 49. The payload is the 8-bit signed halfword offset, so this is a
// branch operand rather than a raw immediate. Whether it fits is a layout
// question, so the assembler relaxes it to Format E's `bra` when it does not.
let isBranch = 1, isTerminator = 1, isBarrier = 1 in
def C_BRA : FormatKbra<49, (outs), (ins brtarget8:$off), "bra.short $off">;
let hasSideEffects = 1, mayLoad = 1, mayStore = 1 in {
def C_BAR_ARRIVE : FormatKraw<51, (outs), (ins uimm8:$payload), "bar.arrive $payload">;
def C_BAR_WAIT   : FormatKraw<52, (outs), (ins uimm8:$payload), "bar.wait $payload">;
}
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
// a real instruction in CCVExpandPseudos, after register allocation.
// ---------------------------------------------------------------------------
let isPseudo = 1, isCodeGenOnly = 1, Size = 0 in {

  // O-24: Formats C/C' carry a MANDATORY predicate qualifier and there is no
  // unpredicated compare, so every compare needs a true guard. Expands to
  // `por pd, !pd, pd`, which is all-ones whatever pd held.
  def PSEUDO_PTRUE : CCVInst<0, (outs PR:$pd), (ins), "# ptrue $pd">;

  // The guard is TIED to the destination, which forces the self-guarding form
  // of the O-24 addendum: `por P0,!P0,P0` then `@P0 setp P0, ...`. One
  // predicate, not two, so the effective file stays at four.
  let Constraints = "$pd = $guard" in {
    foreach cc = ["LT", "LE", "EQ", "NE",
                  "LT_U", "LE_U",
                  "LT_F", "LE_F", "EQ_F", "NE_F"] in
      def PSEUDO_SETP_#cc : CCVInst<0, (outs PR:$pd),
                                    (ins PR:$guard, GPR:$a, GPR:$b),
                                    "# setp."#cc#" $pd, $a, $b">;
  }

  // $neg is the qualifier's negate bit (§1). Carrying it lets the generic
  // branch folder invert a condition rather than adding an instruction.
  // O-33's broadcast. Tied because the shuffle is in-place: lanes 1-31 read
  // lane 0's copy of the SAME register, and lane 0 keeps its own value because
  // the qualifier excludes it (invariant 10). That is what makes one
  // instruction a complete broadcast rather than needing a second to fix up
  // lane 0.
  let Constraints = "$rd = $rd_in" in
  def PSEUDO_BCAST : CCVInst<0, (outs GPR:$rd), (ins GPR:$rd_in),
                             "# broadcast $rd from lane 0">;

  // Predicate logic, same register-vs-qualifier problem: §3's pand/por/pxor
  // take their sources as 3-bit qualifier-shaped fields (2-bit address plus a
  // negate bit), but allocation has to see registers.
  foreach op = ["AND", "OR", "XOR"] in
    def PSEUDO_P#op : CCVInst<0, (outs PR:$pd), (ins PR:$ps0, PR:$ps1),
                              "# p"#op#" $pd, $ps0, $ps1">;

  // The condition arrives as a predicate REGISTER, which is what allocation has
  // to see; §3 encodes it as a qualifier immediate. Same two-representation
  // problem as the compares, solved the same way.
  // `rd = cond ? a : false`, written two-address so that `rd` and the false
  // source coalesce. That is what turns a select into a PREDICATED WRITE
  // rather than a `sel`: invariant 10 preserves the excluded lanes, so the
  // false arm needs no instruction and no lane activation.
  //
  // Every select the compiler generates across the benchmark set is this
  // shape -- `sel rd, a, rd`, a conditional overwrite -- so `sel` itself
  // (§4 point 19) currently buys nothing. It earns its point only on a general
  // three-register select, which nothing has emitted yet. See F-58.
  let Constraints = "$rd = $false" in
  def PSEUDO_PMOV : CCVInst<0, (outs GPR:$rd),
                            (ins GPR:$false, PR:$cond, GPR:$a),
                            "# @$cond mov $rd, $a">;

  let isBranch = 1, isTerminator = 1 in
  def PSEUDO_BRA_PRED : CCVInst<0, (outs),
                                (ins PR:$guard, i32imm:$neg, brtarget18:$off),
                                "# @$guard($neg) bra $off">;
}
