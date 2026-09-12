//===-- CCGRegisterInfo.td - CCG register file --------------*- tablegen -*-===//
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

class CCGReg<bits<5> enc, string n> : Register<n> {
  let HWEncoding{4-0} = enc;
  let Namespace = "CCG";
}

class CCGPredReg<bits<2> enc, string n> : Register<n> {
  let HWEncoding{1-0} = enc;
  let Namespace = "CCG";
}

// ---------------------------------------------------------------------------
// General-purpose registers.
//
// R0-R15 are the architectural file at the settled 16-GPR parameter. R16-R31
// are defined but not in any allocatable class -- see llvm/CCG/README.md and
// roadmap F-12 for why 32 GPRs is an encoding fork rather than a subtarget
// flag, and why they cannot simply be added to GPR here.
// ---------------------------------------------------------------------------

foreach i = 0-31 in {
  def R#i : CCGReg<i, "r"#i>;
}

foreach i = 0-3 in {
  def P#i : CCGPredReg<i, "p"#i>;
}

// v32i32 = 32 lanes x 32b = 1024b, the full physical row.
// v32i16 / v32i8 are the same 32 lanes at narrower chwidth.
// chwidth=4 (v32i4) has no MVT and is deferred; see README.
def GPR : RegisterClass<"CCG", [v32i32, v32i16, v32i8], 1024,
                        (sequence "R%u", 0, 15)>;

// The compressed forms (J, K) carry 4-bit register fields and so can only
// name R0-R15. At 16 GPRs that is the whole file and the class is identical
// to GPR; it exists as a distinct class so the constraint stays expressed
// rather than implied, and so a future 32-GPR encoding does not silently
// widen the compressed forms. See roadmap F-12.
def GPRC : RegisterClass<"CCG", [v32i32, v32i16, v32i8], 1024,
                         (sequence "R%u", 0, 15)>;

// A predicate is 32 lanes x 1 bit, at every chwidth.
def PR : RegisterClass<"CCG", [v32i1], 32, (sequence "P%u", 0, 3)>;
