//===-- CCVCallingConv.td - CCV calling convention ----------*- tablegen -*-===//
//
// Kernels take no register arguments at all: their parameters arrive in the
// launch block and CCVLowerKernelArgs has already rewritten every use into a
// load by the time instruction selection runs (§5.2). So this convention only
// has to cover ordinary device functions.
//
// Entry register state is undefined (§5.2), and the link register is explicit
// in call/ret rather than fixed (§3, Format E), so there is no ABI here beyond
// where arguments sit.
//
//===----------------------------------------------------------------------===//

def CC_CCV : CallingConv<[
  CCIfType<[i1, i8, i16], CCPromoteToType<i32>>,
  CCIfType<[i32, f32], CCAssignToReg<[R1, R2, R3, R4, R5, R6]>>,
  CCIfType<[i32, f32], CCAssignToStack<4, 4>>
]>;

def RetCC_CCV : CallingConv<[
  CCIfType<[i1, i8, i16], CCPromoteToType<i32>>,
  CCIfType<[i32, f32], CCAssignToReg<[R1, R2]>>
]>;

// Which registers survive a call is an ABI decision still open (CP-9;
// proposals/calling-convention.md §6), to be settled by measurement on the
// CoreMark port. Warp state is deliberately small (§3, Format E chose a link
// register over a hardware call stack to keep it so), so the set is a choice
// to make with data, not a default to inherit. -ccv-csr picks one (none, six, eight); six is
// built until the sweep decides. R14 (the link register) and R15 (the frame
// window, reserved) are in none of them.
def CSR_CCV_None : CalleeSavedRegs<(add)>;
def CSR_CCV      : CalleeSavedRegs<(sequence "R%u", 8, 13)>;
// Every register that is neither an argument (R1-R6) nor the link: the most a
// convention can keep without making a callee preserve its own inputs.
def CSR_CCV_Eight : CalleeSavedRegs<(add R0, (sequence "R%u", 7, 13))>;
