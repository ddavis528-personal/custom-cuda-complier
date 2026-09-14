//===-- CCVInstrFormats.td - CCV instruction formats --------*- tablegen -*-===//
//
// One class per format in docs/isa-v1.5-operation-map-and-encoding.md §3.
// Bit assignments below are transcribed directly from that section's tables and
// are the mechanical check on them: TableGen rejects any double-assigned bit,
// and tools/check-encoding.py rejects any gap. Field positions are load-bearing
// (invariant 8) -- do not "tidy" them.
//
//===----------------------------------------------------------------------===//

// Length / class field, bits [1:0]. See §2.
class LenClass<bits<2> v> { bits<2> value = v; }
def LEN32 : LenClass<0b00>;   // 32-bit, format tag in [5:2]
def LENJ  : LenClass<0b01>;   // 16-bit compressed, group 0 (Format J)
def LENK  : LenClass<0b10>;   // 16-bit compressed, group 1 (Format K)
def LEN48 : LenClass<0b11>;   // 48-bit, format tag in [5:2]

// Format tags occupy bits [5:2] and are identical across lengths (§2); each
// format class below hardcodes its own tag.

class CCVInst<int sz, dag outs, dag ins, string asm> : Instruction {
  let Namespace     = "CCV";
  let Size          = sz;
  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString      = asm;
  let Pattern        = [];
}

// ---------------------------------------------------------------------------
// 32-bit base. Header is bits [5:0] in every 32-bit format.
// ---------------------------------------------------------------------------
class CCVInst32<bits<4> tag, dag outs, dag ins, string asm>
    : CCVInst<4, outs, ins, asm> {
  field bits<32> Inst;
  let Inst{1-0} = 0b00;
  let Inst{5-2} = tag;
}

// 48-bit sibling: identical to its 32-bit form in [31:6], 16 more bits at
// [47:32], same tag. Those bits are an immediate in B/C′/D/F and an opcode
// extension in A′ (O-37). See §3, "Wide-immediate siblings".
class CCVInst48<bits<4> tag, dag outs, dag ins, string asm>
    : CCVInst<6, outs, ins, asm> {
  field bits<48> Inst;
  let Inst{1-0} = 0b11;
  let Inst{5-2} = tag;
}

// ---------------------------------------------------------------------------
// Formats A / A' / A" -- ALU register-register. §3.
// rd, rs0, rs1, rs2 and opcode[4:0] sit at identical positions across all
// three tiers; only [31:27] is interpreted per-tier. Invariant 8.
// ---------------------------------------------------------------------------
class FormatA<bits<10> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0000, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<4> rs1; bits<4> rs2;
  let Inst{10-6}  = opc{4-0};
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{22-19} = rs1;
  let Inst{26-23} = rs2;
  let Inst{29-27} = opc{7-5};
  let Inst{31-30} = opc{9-8};
}

class FormatAp<bits<7> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0001, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<4> rs1; bits<4> rs2; bits<3> pq;
  let Inst{10-6}  = opc{4-0};
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{22-19} = rs1;
  let Inst{26-23} = rs2;
  let Inst{29-27} = pq;          // predicate qualifier: 2-bit addr + negate
  let Inst{31-30} = opc{6-5};
}

// Format A′ long -- 48-bit predicated ALU. §3, O-37.
//
// A′'s 7-bit opcode reaches points 0-127 only, so everything above is Format A
// and cannot carry a qualifier. This is A′'s 48-bit SIBLING: the low 32 bits
// are bit-identical to a 32-bit A′ instruction and the third halfword carries
// opcode[9:7], which is the same sibling rule §2 applies to B, D and F.
//
// CONTENT IS 35 BITS -- a 32-bit A′ plus three opcode bits -- so 48 is the
// minimum length available at 16-bit granularity. The reserved bits are a
// rounding artifact, not headroom; invariant 7 asks for minimum length and this
// is at it.
//
// opcode[9:7] != 000 is a CONSTRAINT, not a convention. With those bits zero
// the form would encode points 0-127, which the 32-bit A′ already encodes --
// two encodings of one instruction, which invariant 7's second sentence
// forbids. The long form encodes exactly points 128-1023: complementary to the
// short one rather than overlapping it. tools/check-encoding.py asserts it.
class FormatAp48<bits<10> opc, dag outs, dag ins, string asm>
    : CCVInst48<0b0001, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<4> rs1; bits<4> rs2; bits<3> pq;
  let Inst{10-6}  = opc{4-0};
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{22-19} = rs1;
  let Inst{26-23} = rs2;
  let Inst{29-27} = pq;            // predicate qualifier, canonical position
  let Inst{31-30} = opc{6-5};
  let Inst{34-32} = opc{9-7};      // the extension; must not be 000
  let Inst{36-35} = 0b00;          // reserved, named for a future `pd` (O-37)
  let Inst{47-37} = 0;             // reserved
}

class FormatApp<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0010, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<4> rs1; bits<4> rs2; bits<3> pq; bits<2> pd;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{22-19} = rs1;
  let Inst{26-23} = rs2;
  let Inst{29-27} = pq;
  let Inst{31-30} = pd;          // predicate dest, no negate on the write side
}

// ---------------------------------------------------------------------------
// Formats B / B' / B" -- ALU register-immediate. §3.
// Immediate is contiguous with its MSB always at bit 31.
// ---------------------------------------------------------------------------
class FormatB<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0011, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<13> imm;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{31-19} = imm;
}

class FormatBp<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0100, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<3> pq; bits<10> imm;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{26-19} = imm{7-0};
  let Inst{29-27} = pq;          // canonical position as of v1.4 (O-22)
  let Inst{31-30} = imm{9-8};    // immediate split around the qualifier, as D'
}

class FormatBpp<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0101, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<3> pq; bits<2> pd; bits<8> imm;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{26-19} = imm;         // MSB at 26; layout identical to C' as of v1.4
  let Inst{29-27} = pq;
  let Inst{31-30} = pd;
}

// 48-bit sibling of Format B: [31:6] identical, 16 more immediate bits.
class FormatB48<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst48<0b0011, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<29> imm;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{31-19} = imm{12-0};
  let Inst{47-32} = imm{28-13};
}

// ---------------------------------------------------------------------------
// Formats C / C' -- Compare. §3. Predicate dest is mandatory.
// ---------------------------------------------------------------------------
class FormatC<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0110, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<4> rs1; bits<3> pq; bits<2> pd;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{22-19} = rs1;
  let Inst{26-23} = 0;           // reserved
  let Inst{29-27} = pq;
  let Inst{31-30} = pd;
}

// Format C" -- UNPREDICATED compare, tag 1111 at 32 bits.
//
// §1's own rule is that a predicated operation needs a distinct unpredicated
// encoding, which is why A/A'/A" and D/D' exist. The compare family broke it:
// it spent both its tags on reg-reg versus reg-imm and left no unpredicated
// form, so every compare had to manufacture a guard first (O-24). Measured, that
// was 13% of dynamically issued instructions in the reduction kernels.
//
// Tag 1111 is free at 32 bits -- H is 48-bit only, and §2 makes the length
// decodable from [1:0] before the tag is read, so the two cannot be confused.
//
// One tag covers both operand shapes, where the predicated forms needed two:
// dropping the qualifier frees [29:27], and bit [27] selects register versus
// immediate. rd, rs0, rs1 and pd stay exactly where C and C' put them
// (invariant 8), and the immediate lands at [26:19] exactly as in C'.
class FormatCu<bits<5> opc, bit isimm, dag outs, dag ins, string asm>
    : CCVInst32<0b1111, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<4> rs1; bits<8> imm; bits<2> pd;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{22-19} = !if(isimm, imm{3-0}, rs1);
  let Inst{26-23} = !if(isimm, imm{7-4}, 0b0000);
  let Inst{27}    = isimm;
  let Inst{29-28} = 0;           // reserved
  let Inst{31-30} = pd;
}

class FormatCp<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b0111, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<8> imm; bits<3> pq; bits<2> pd;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{26-19} = imm;         // MSB at bit 26
  let Inst{29-27} = pq;
  let Inst{31-30} = pd;
}

// ---------------------------------------------------------------------------
// Format D -- load / store, base + offset. §3.
// Also carries ld.pred / st.pred, where [14:11] is a predicate mask rather
// than rdata. Same skeleton, no field moves. (v1.3, O-19.)
// ---------------------------------------------------------------------------
class FormatD<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1000, outs, ins, asm> {
  bits<4> rdata; bits<4> rbase; bits<13> off;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rdata;
  let Inst{18-15} = rbase;
  let Inst{31-19} = off;
}

// Format D, base + index. Effective address for .global is
// (rbase << 16) + (rindex << scale) + disp -- the shift is a property of the
// address space, not a field, so this bit map is unchanged from v1.2. §5.1.
class FormatDidx<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1000, outs, ins, asm> {
  bits<4> rdata; bits<4> rbase; bits<4> rindex; bits<1> scale; bits<8> disp;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rdata;
  let Inst{18-15} = rbase;
  let Inst{22-19} = rindex;
  let Inst{23}    = scale;
  let Inst{31-24} = disp;
}

// Format D' -- predicated load/store, base + offset. Offset is split around
// the qualifier so the qualifier stays at [29:27] and the sign bit at 31.
// This is the O-10 resolution; do not merge the halves.
class FormatDp<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1101, outs, ins, asm> {
  bits<4> rdata; bits<4> rbase; bits<10> off; bits<3> pq;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rdata;
  let Inst{18-15} = rbase;
  let Inst{26-19} = off{7-0};
  let Inst{29-27} = pq;
  let Inst{31-30} = off{9-8};
}

// ---------------------------------------------------------------------------
// Formats M / M' -- atomics. §3.
// ---------------------------------------------------------------------------
class FormatM<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1001, outs, ins, asm> {
  bits<4> rd; bits<4> rbase; bits<4> rs1; bits<9> off;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rbase;
  let Inst{22-19} = rs1;
  let Inst{31-23} = off;
}

class FormatMp<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst48<0b1001, outs, ins, asm> {
  bits<4> rd; bits<4> rbase; bits<4> rs1; bits<4> rs2;
  bits<3> pq; bits<2> pd; bits<16> off;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rbase;
  let Inst{22-19} = rs1;
  let Inst{26-23} = rs2;
  let Inst{29-27} = pq;
  let Inst{31-30} = pd;
  let Inst{47-32} = off;
}

// ---------------------------------------------------------------------------
// Format E -- control flow, barrier. §3.
// ---------------------------------------------------------------------------
class FormatEbra<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1010, outs, ins, asm> {
  bits<21> off;
  let Inst{10-6}  = opc;
  let Inst{31-11} = off;
}

class FormatEcall<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1010, outs, ins, asm> {
  bits<4> rd; bits<17> off;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{31-15} = off;
}

// Predicated branch: offset split around the qualifier, same technique as D'.
class FormatEbrap<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1010, outs, ins, asm> {
  bits<18> off; bits<3> pq;
  let Inst{10-6}  = opc;
  let Inst{26-11} = off{15-0};
  let Inst{29-27} = pq;
  let Inst{31-30} = off{17-16};
}

class FormatEbarinit<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1010, outs, ins, asm> {
  bits<6> barid; bits<10> count;
  let Inst{10-6}  = opc;
  let Inst{16-11} = barid;
  let Inst{26-17} = count;
  let Inst{31-27} = 0;           // reserved
}

// bar.wait.phase -- the explicit-phase barrier wait (O-27). The barrier ID sits
// at [16:11], exactly where bar.init puts it, so the same operand occupies the
// same field across the format. `ps` is a predicate SOURCE supplying the
// expected phase, which is a different thing from the qualifier at [29:27]:
// the qualifier decides whether the instruction executes, `ps` is data it
// reads. Both are present, and the qualifier is what the compressed Format K
// form cannot have.
class FormatEbarwait<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1010, outs, ins, asm> {
  bits<6> barid; bits<2> ps; bits<3> pq;
  let Inst{10-6}  = opc;
  let Inst{16-11} = barid;
  let Inst{18-17} = ps;
  let Inst{26-19} = 0;           // reserved
  let Inst{29-27} = pq;
  let Inst{31-30} = 0;           // reserved
}

// ---------------------------------------------------------------------------
// Format F -- wide immediate. §3.
// ---------------------------------------------------------------------------
class FormatF<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1011, outs, ins, asm> {
  bits<4> rd; bits<17> imm;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{31-15} = imm;
}

class FormatF48<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst48<0b1011, outs, ins, asm> {
  bits<4> rd; bits<33> imm;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{31-15} = imm{16-0};
  let Inst{47-32} = imm{32-17};
}

// ---------------------------------------------------------------------------
// Format G -- warp-collective. §3. Carries unballot as of v1.3 (O-14).
//
// v1.4 writes Format G out as four field layouts rather than one table with "or"
// clauses; these classes match those tables one for one. See O-22's neighbours
// in the v1.4 change list, and roadmap F-13 for how the split was found.
// ---------------------------------------------------------------------------

// Shuffles: rd, rs, 5-bit lane index. No predicate destination.
class FormatGshfl<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1100, outs, ins, asm> {
  bits<4> rd; bits<4> rs0; bits<5> lane; bits<3> pq;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = rs0;
  let Inst{23-19} = lane;
  let Inst{26-24} = 0;           // reserved (PTX clamp/segment operand)
  let Inst{29-27} = pq;
  let Inst{31-30} = 0;           // reserved: shuffles write a GPR, not a predicate
}

// vote.any / vote.all: predicate source at [21:19], predicate dest at [31:30].
class FormatGvote<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1100, outs, ins, asm> {
  bits<3> ps; bits<3> pq; bits<2> pd;
  let Inst{10-6}  = opc;
  let Inst{14-11} = 0;           // unused: vote has no GPR operand
  let Inst{18-15} = 0;
  let Inst{21-19} = ps;
  let Inst{23-22} = 0;
  let Inst{26-24} = 0;
  let Inst{29-27} = pq;
  let Inst{31-30} = pd;
}

// ballot: predicate source at [21:19], GPR destination at [14:11].
class FormatGballot<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1100, outs, ins, asm> {
  bits<4> rd; bits<3> ps; bits<3> pq;
  let Inst{10-6}  = opc;
  let Inst{14-11} = rd;
  let Inst{18-15} = 0;
  let Inst{21-19} = ps;
  let Inst{23-22} = 0;
  let Inst{26-24} = 0;
  let Inst{29-27} = pq;
  let Inst{31-30} = 0;
}

// unballot (v1.3, O-14): the exact inverse of ballot. GPR source at the
// canonical rs0 position, predicate dest at the canonical [31:30]. No new
// fields -- which is what O-14 claimed, now mechanically confirmed.
class FormatGunballot<bits<5> opc, dag outs, dag ins, string asm>
    : CCVInst32<0b1100, outs, ins, asm> {
  bits<4> rs0; bits<3> pq; bits<2> pd;
  let Inst{10-6}  = opc;
  let Inst{14-11} = 0;
  let Inst{18-15} = rs0;
  let Inst{23-19} = 0;
  let Inst{26-24} = 0;
  let Inst{29-27} = pq;
  let Inst{31-30} = pd;
}

// ---------------------------------------------------------------------------
// Format I -- register / predicate metadata. §3.
// The two subops live at different lengths, which invariant 7 permits: each
// exists only at the length its operand actually requires.
// ---------------------------------------------------------------------------
class FormatIchw<dag outs, dag ins, string asm>
    : CCVInst32<0b1110, outs, ins, asm> {
  bits<16> regmask; bits<2> width;
  let Inst{7-6}   = 0b00;        // subop
  let Inst{23-8}  = regmask;
  let Inst{25-24} = width;
  let Inst{31-26} = 0;           // reserved
}

class FormatIpmov<dag outs, dag ins, string asm>
    : CCVInst48<0b1110, outs, ins, asm> {
  bits<2> pd; bits<32> lanemask;
  let Inst{7-6}   = 0b01;        // subop
  let Inst{9-8}   = pd;
  let Inst{15-10} = 0;           // reserved
  let Inst{47-16} = lanemask;
}

// ---------------------------------------------------------------------------
// Format J -- compressed accumulate (16-bit). §3.
// rd = rd + (rs0 * rs1). Twelve bits of register fields leave exactly two for
// the subop, which is why this needs a whole class code rather than a point
// inside Format K. Register fields are 4-bit and cannot name R16-R31.
// ---------------------------------------------------------------------------
class FormatJ<bits<2> subop, dag outs, dag ins, string asm>
    : CCVInst<2, outs, ins, asm> {
  field bits<16> Inst;
  bits<4> rd; bits<4> rs0; bits<4> rs1;
  let Inst{1-0}   = 0b01;
  let Inst{3-2}   = subop;
  let Inst{7-4}   = rd;          // accumulator, read and written
  let Inst{11-8}  = rs0;
  let Inst{15-12} = rs1;
}

// ---------------------------------------------------------------------------
// Format K -- compressed two-operand (16-bit). §3.
// 6-bit opcode leaves 8 bits of operand at [15:8].
// ---------------------------------------------------------------------------
class CCVInstK<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInst<2, outs, ins, asm> {
  field bits<16> Inst;
  let Inst{1-0} = 0b10;
  let Inst{7-2} = opc;
}

// Destructive reg-reg: rd = rd OP rs.
class FormatKrr<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<4> rd; bits<4> rs;
  let Inst{11-8}  = rd;
  let Inst{15-12} = rs;
}

// Destructive reg-imm: rd = rd OP imm4.
class FormatKri<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<4> rd; bits<4> imm;
  let Inst{11-8}  = rd;
  let Inst{15-12} = imm;
}

// Predicate logic (v1.3, O-20). pd + two qualifier-shaped sources = 8 bits
// exactly, which is why these do not align with the K GPR geometry. Predicates
// have their own RAT (invariant 5), so the predicate rename path reads its own
// fixed wires; these positions are fixed across all four ops.
class FormatKplog<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<2> pd; bits<3> ps0; bits<3> ps1;
  let Inst{9-8}   = pd;
  let Inst{12-10} = ps0;         // 2-bit addr + negate
  let Inst{15-13} = ps1;
}

// srd rd, #sel (v1.3, O-18). Four bits of operand would otherwise be reserved;
// they carry a selector, so one opcode point covers sixteen values.
class FormatKsrd<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<4> rd; bits<4> sel;
  let Inst{11-8}  = rd;
  let Inst{15-12} = sel;
}

// Compressed load/store, implicit zero offset.
class FormatKmem<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<4> rd; bits<4> rbase;
  let Inst{11-8}  = rd;
  let Inst{15-12} = rbase;
}

// Small-operand control ops that use [15:8] ad hoc.
// bra.short: the 8-bit payload is a signed halfword offset, named so the
// encoder can attach a fixup to it rather than treating it as a literal.
class FormatKbra<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<8> off;
  let Inst{15-8} = off;
}

// `chwidth rd, width` -- Format K opcode 48. §3 puts `rd` at the canonical
// [11:8] and the 2-bit width code at [13:12]; [15:14] is reserved. It had been
// modelled as an opaque 8-bit payload, which encodes the same bits but gives
// the compiler nothing to allocate a register into.
class FormatKchw<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<4> rd; bits<2> width;
  let Inst{11-8}  = rd;
  let Inst{13-12} = width;
  let Inst{15-14} = 0;
}

class FormatKraw<bits<6> opc, dag outs, dag ins, string asm>
    : CCVInstK<opc, outs, ins, asm> {
  bits<8> payload;
  let Inst{15-8} = payload;
}
