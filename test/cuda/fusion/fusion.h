//===-- fusion.h - what the fused-kernel corpus shares -------------------===//
//
// The corpus in this directory exists because the fused-kernel evidence this
// project's register-file argument rests on was ONE kernel -- test/cuda/fused.cu
// -- written for the measurement, with the tensor count as a free knob whose
// range was also chosen here. F-129 and F-139 both read off it. A number that
// is a knob is not a measurement of the workload, it is a measurement of the
// knob, and the conclusion drawn from it ("fused chains exceed the register
// file at high tensor counts") is true of the knob at its top setting and says
// nothing about where real kernels sit.
//
// So these are written from the published shape of kernels that actually run in
// inference and training stacks -- normalisation, the GLU activation pair,
// rotary embedding, the quantised-GEMM epilogue, the flash-decoding combine,
// the fused optimiser step. Each one's POINTER COUNT comes from its own
// mathematics and is not a parameter: RMSNorm has three tensors because RMSNorm
// has three tensors. Where a real kernel's count is genuinely variable the
// variation is structural and is modelled as such, not swept.
//
// TWO SUBSTITUTIONS, BOTH DISCLOSED
// ---------------------------------
// 1. TRANSCENDENTALS. F-120: clang lowers expf/rsqrtf/tanhf to libm calls and
//    this backend has no calling sequence, so `ex2`, `lg2` and `rsqrt` are
//    unreachable from CUDA even though the ISA defines them. Every activation
//    below that needs one uses the rational stand-in in this header instead.
//
// 2. DIVISION. F-49: the only `fdiv` this backend selects is `1.0f / x`, which
//    is the reciprocal instruction. Every division below is written that way,
//    which is also what a real kernel compiled with fast-math gets.
//
// NEITHER SUBSTITUTION CAN MOVE WHAT IS BEING MEASURED, and that is the reason
// they are acceptable rather than merely convenient. Both replace one piece of
// per-lane arithmetic on a DIVERGENT value with another. The quantity under
// measurement is the warp-UNIFORM working set -- window bases and launch-block
// scalars -- and the count of those is fixed by the kernel's signature and its
// loop structure, neither of which an activation function touches. What the
// substitution does change is the instruction count, so instruction counts in
// this corpus are reported as the shape's cost on THIS backend and are not
// compared against another machine's.
//
//===----------------------------------------------------------------------===//
#ifndef CCV_FUSION_H
#define CCV_FUSION_H

#include "portable.h"

// x^-1/2. `rsqrtf` is one SFU instruction on every real GPU and on this ISA
// (`rsqrt.f32`, §4 point 257); F-120 makes it unreachable, so it costs two here
// -- `sqrt.f32` then `rcp.f32`. Structurally identical, one instruction dearer.
__device__ static inline float ccv_rsqrt(float x) {
    return 1.0f / __builtin_sqrtf(x);
}

// 1/x, spelled so it selects `rcp.f32` (F-49).
__device__ static inline float ccv_recip(float x) { return 1.0f / x; }

// The logistic sigmoid, standing in for 1/(1+expf(-x)). This is the "fast
// sigmoid" x/(1+|x|) rescaled, not a Taylor series: it is accurate to about
// 2e-2, which is useless numerically and irrelevant here, because nothing in
// this corpus checks an activation's VALUE -- the executed checks in
// tools/check-fusion.sh are built around the kernels whose arithmetic is exact.
__device__ static inline float ccv_sigmoid(float x) {
    return 0.5f * x * ccv_recip(1.0f + __builtin_fabsf(x)) + 0.5f;
}

// SiLU / swish, the activation in the Llama-family MLP.
__device__ static inline float ccv_silu(float x) { return x * ccv_sigmoid(x); }

// GELU, tanh flavour. tanh(y) = 2*sigmoid(2y) - 1, so it inherits the stand-in
// above rather than adding a second one.
__device__ static inline float ccv_gelu(float x) {
    float y = 0.7978845608f * (x + 0.044715f * x * x * x);
    return 0.5f * x * (2.0f * ccv_sigmoid(2.0f * y));
}

#endif
