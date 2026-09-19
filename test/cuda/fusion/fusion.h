//===-- fusion.h - what the fused-kernel corpus shares -------------------===//
//
// WHY THIS DIRECTORY EXISTS
// -------------------------
// The fused-kernel evidence the register-file argument rests on was ONE kernel
// -- test/cuda/fused.cu -- written for the measurement, with the tensor count as
// a free knob whose range was also chosen here. F-129 read the uniform-pressure
// conclusion off it and F-139 read the O-45 result off it. A number that is a
// knob is a measurement of the knob: "fused chains exceed the register file at
// high tensor counts" is true of that kernel at its top setting and says nothing
// about where real kernels sit.
//
// So these are written from the published shape of kernels that actually run in
// inference and training stacks -- RMSNorm and its fused-residual form, the GLU
// activation pair, rotary embedding, LayerNorm with saved statistics, the
// quantised-GEMM dequantisation epilogue, the flash-decoding combine, and the
// fused optimiser step. **Each one's pointer count comes from its own
// mathematics and is not a parameter.** RMSNorm takes three tensors because
// RMSNorm takes three tensors; `silu_and_mul` takes two because the gate and up
// projections are halves of one allocation, which is a detail a synthetic kernel
// would never have reproduced and which matters directly to the slot question.
//
// The first thing the corpus found was not a measurement. It was F-142: `out[i
// + 1]` segfaulted the compiler, because Format D's base+index displacement
// field was written as a literal zero at selection and **no kernel in the tree
// had ever emitted a non-zero one**. A corpus written to exercise addressing
// modes had missed a crash in the most ordinary addressing shape there is.
//
// WHAT IS STOOD IN FOR, AND WHY IT CANNOT MOVE THE RESULT
// ------------------------------------------------------
// One thing: DIVISION. F-49 leaves `1.0f / x` -- the reciprocal instruction --
// as the only `fdiv` this backend selects, so every division below is written
// that way. That is also what a real kernel gets from `-use_fast_math`, and
// `ccv_recip` names it rather than hiding it.
//
// Nothing else is stood in for. The transcendentals these kernels need are
// reachable as of F-141, through the same intrinsics a CUDA kernel uses:
// `__expf` is `ex2` on a scaled argument on this machine exactly as it is on
// NVIDIA's, and `rsqrtf` is one instruction on both.
//
// The substitution is acceptable rather than merely convenient because it cannot
// move what is being measured. The quantity is the warp-UNIFORM working set --
// window bases and launch-block scalars -- and that is fixed by a kernel's
// signature and its loop structure. A reciprocal is per-lane arithmetic on a
// divergent value. It changes the instruction count, so instruction counts here
// are reported as this backend's cost for the shape and are not offered as a
// cross-machine density comparison.
//
//===----------------------------------------------------------------------===//
#ifndef CCV_FUSION_H
#define CCV_FUSION_H

#include "portable.h"

// Grid-stride loops need the grid size, which §5.3 puts in the launch block
// rather than in a register -- it is launch-time data, so it is a load and not
// an instruction. This is CUDA-only; the corpus is not part of the three-target
// density comparison portable.h serves.
#define NCTAID_X gridDim.x

// 1/x, spelled so it selects `rcp.f32` (F-49).
__device__ static inline float ccv_recip(float x) { return 1.0f / x; }

// x^-1/2, one `rsqrt.f32` (F-141). This is `rsqrtf`, and it is what every
// normalisation kernel in an inference stack calls.
__device__ static inline float ccv_rsqrt(float x) {
    return __nvvm_rsqrt_approx_f(x);
}

// e^x as `ex2` on a scaled argument -- which is what `__expf` IS, on this
// machine and on NVIDIA's. Not an approximation of the CUDA function: the same
// decomposition, one multiply and one SFU instruction.
__device__ static inline float ccv_exp(float x) {
    return __builtin_exp2f(x * 1.44269504088896340736f);
}

// The logistic sigmoid and SiLU/swish, the Llama-family MLP activation.
__device__ static inline float ccv_sigmoid(float x) {
    return ccv_recip(1.0f + ccv_exp(-x));
}
__device__ static inline float ccv_silu(float x) { return x * ccv_sigmoid(x); }

// GELU, tanh flavour -- the BERT/GPT MLP activation. tanh(y) = 2*sigmoid(2y) - 1.
__device__ static inline float ccv_gelu(float x) {
    float y = 0.7978845608028654f * (x + 0.044715f * x * x * x);
    return x * ccv_sigmoid(2.0f * y);
}

#endif
