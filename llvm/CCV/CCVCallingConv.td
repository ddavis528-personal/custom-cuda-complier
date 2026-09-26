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

// Nothing is callee-saved yet. Warp state is deliberately small (§3, Format E:
// link-register-plus-convention was chosen over a hardware call stack to keep
// it that way), so a save/restore convention is a decision to make with data,
// not a default to inherit.
def CSR_CCV : CalleeSavedRegs<(add)>;
