//===-- CCVRegisterInfo.td - CCV register file --------------*- tablegen -*-===//
//
// Register file for the custom CUDA-compatible target.
// Source of truth: docs/isa-v1.3-operation-map-and-encoding.md §1, invariant 5.
//
// A logical GPR always holds 32 lanes. At chwidth=32 that is 32x32 = 1024 bits.
// Narrow registers are a narrower physical slice of a row, not more elements per
// lane, so the value types below differ in element width and all carry 32 lanes.
//
// A predicate is 32 bits -- one bit per lane -- at every chwidth (invariant 5),
// so the predicate class has exactly one value type and uniform allocation.
//
//===----------------------------------------------------------------------===//

class CCVReg<bits<4> enc, string n> : Register<n> {
  let HWEncoding{3-0} = enc;
  let Namespace = "CCV";
}

class CCVPredReg<bits<2> enc, string n> : Register<n> {
  let HWEncoding{1-0} = enc;
  let Namespace = "CCV";
}

// ---------------------------------------------------------------------------
// General-purpose registers.
//
// Sixteen, settled (§1, O-25). Every register field in the ISA is 4 bits --
// including the compressed forms, which is what makes the count structural
// rather than a parameter: at 5-bit fields Format J overruns 16 bits outright.
// There is one register class because there is one encoding path.
// ---------------------------------------------------------------------------

foreach i = 0-15 in {
  def R#i : CCVReg<i, "r"#i>;
}

foreach i = 0-3 in {
  def P#i : CCVPredReg<i, "p"#i>;
}

// chwidth=32 only, for now. See the note above on the narrow widths.
def GPR : RegisterClass<"CCV", [i32, f32], 32, (sequence "R%u", 0, 15)>;

// The SAME sixteen registers, viewed at 16-bit element width. §1 makes element
// width per-register state, not a second register file, so this is not a
// subregister relationship and there is no physical distinction -- a COPY
// between the classes is a no-op the coalescer removes.
//
// A separate class rather than adding i16 to GPR's type list, which is what
// F-3 proposed and which TableGen will not accept: with one multi-typed class
// it cannot infer whether a bare `add` means the 32-bit or the 16-bit
// instruction, and the ambiguity is real -- the two select to different
// MachineInstr opcodes that encode identically and differ only in the TSFlags
// bit CCVInsertChwidth reads.
//
// i8 would be a third class; i4 has no MVT at all.
//
// WIDTH AFFINITY, AND WHY IT LIVES IN THE ALLOCATION ORDER (F-80).
//
// Same sixteen registers, DESCENDING. The set is identical to GPR's -- it has
// to be, or a cross-class COPY would not be the no-op §1 says it is -- and only
// the preference differs.
//
// Element width is per-register state, so two values of different widths in one
// physical register cost a `chwidth` at each handover. In straight-line code
// that is one instruction; in a loop body it is one PER ITERATION, which is
// what F-87 could not lift out by placement because the width genuinely changes
// inside the body. The allocator is the only pass that can prevent it, and the
// register class is the only width information it has -- `chwidth` names
// physical registers, so width is otherwise a post-RA concept entirely.
//
// Opposite orders make 32-bit values cluster from R0 up and 16-bit values from
// R14 down, so under low pressure they never meet and no handover exists to pay
// for. Under high pressure they meet in the middle and share exactly as before:
// the degradation is graceful, and sharing a register is still far cheaper than
// spilling to keep them apart. R15 is last rather than absent so the set stays
// equal to GPR's; it is reserved (O-30) and the allocator skips it regardless.
def GPR16 : RegisterClass<"CCV", [i16], 32,
    (add R14, R13, R12, R11, R10, R9, R8, R7, R6, R5, R4, R3, R2, R1, R0,
         R15)>;

// One bit per lane in hardware; i1 per thread in the type system.
def PR : RegisterClass<"CCV", [i1], 32, (sequence "P%u", 0, 3)>;
