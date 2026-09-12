//===-- CCGInstrPatterns.td - selection patterns ------------*- tablegen -*-===//
//
// Patterns are kept out of CCGInstrInfo.td so that file stays a transcription
// of §3's bit maps and nothing else.
//
//===----------------------------------------------------------------------===//

// ---------------------------------------------------------------------------
// Target nodes
// ---------------------------------------------------------------------------
def SDT_CCGRet : SDTypeProfile<0, 0, []>;
def ccg_ret : SDNode<"CCGISD::RET", SDT_CCGRet,
                     [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

// Selected in C++ (CCGISelDAGToDAG::Select): the node is variadic over the
// return registers, which a declarative pattern cannot bind. A kernel ends
// with `exit`; `ret rs` for device functions arrives with the calling sequence.

// ---------------------------------------------------------------------------
// Integer arithmetic. Format A is three-source; the two-source operations leave
// rs2 unread, so it is tied to rs0 to avoid an extra live value.
// ---------------------------------------------------------------------------
def : Pat<(add GPR:$a, GPR:$b), (ADD GPR:$a, GPR:$b, GPR:$a)>;
def : Pat<(mul GPR:$a, GPR:$b), (MADLO GPR:$a, GPR:$b, (MOVI 0))>;
def : Pat<(add (mul GPR:$a, GPR:$b), GPR:$c), (MADLO GPR:$a, GPR:$b, GPR:$c)>;
def : Pat<(add GPR:$a, (i32 imm:$i)), (ADDI GPR:$a, imm:$i)>;
def : Pat<(shl GPR:$a, (i32 imm:$i)), (C_SHLI GPR:$a, imm:$i)>;

// ---------------------------------------------------------------------------
// Floating point. The compressed destructive form is the natural match for a
// two-operand add -- it is what Format K exists for (§3).
// ---------------------------------------------------------------------------
def : Pat<(fadd GPR:$a, GPR:$b), (C_FADD GPR:$a, GPR:$b)>;
def : Pat<(fma GPR:$a, GPR:$b, GPR:$c), (FFMA_F0 GPR:$a, GPR:$b, GPR:$c)>;

// ---------------------------------------------------------------------------
// Constants. Format F's 48-bit form materialises any 32-bit constant in one
// instruction (§3), so there is no hi/lo pair to synthesise.
// ---------------------------------------------------------------------------
def : Pat<(i32 imm:$i), (MOVI48 imm:$i)>;

// ---------------------------------------------------------------------------
// Loads and stores. AddrRI matches (rbase << 16) + index, which is the shape
// CCGLowerKernelArgs leaves behind for a global pointer (§5.1). The scale is
// chwidth-derived and enabled only when the index is an element index, which
// is the aligned case (O-23, O-7).
// ---------------------------------------------------------------------------
// Selected in C++ rather than declaratively: the match has to inspect the
// shape CCGLowerKernelArgs produced -- a shl-by-16 of a zero-extended window
// index, plus a scaled element index -- and decide whether scale-enable can be
// set. That is a judgement about alignment (O-23), not a tree shape, so it
// lives in CCGISelDAGToDAG::selectAddrBaseIdx.
