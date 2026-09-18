// A fused elementwise epilogue over NT input tensors (F-129).
//
// This is the shape that dominates instruction count in real inference outside
// the matrix multiplies: residual add, per-channel scale, bias, activation --
// fused into one pass so the intermediate tensors never reach memory. Fusion is
// the whole point of it, and fusion is what raises the TENSOR COUNT, which is
// what makes it interesting here. Every tensor needs its own §5.1 window base,
// every base is warp-uniform, and none of them can be spilled to make room for
// the others without paying for it on every iteration.
//
// So NT is the independent variable, exactly as TM x TN is in sweep-tiles.sh,
// and it isolates address pressure the way the tile sweep isolates accumulator
// pressure. Arithmetic per element is held constant at one FMA per tensor, so
// anything that moves is addressing.
#include "portable.h"

#ifndef NT
#define NT 4
#endif

__global__ void fused(float *ALIGNED out, const float *ALIGNED x,
                      const float *ALIGNED t0, const float *ALIGNED t1,
                      const float *ALIGNED t2, const float *ALIGNED t3,
                      const float *ALIGNED t4, const float *ALIGNED t5,
                      const float *ALIGNED t6, const float *ALIGNED t7,
                      const float *ALIGNED t8,
                      const float *ALIGNED t9,
                      const float *ALIGNED t10,
                      const float *ALIGNED t11,
                      const float *ALIGNED t12,
                      const float *ALIGNED t13,
                      const float *ALIGNED t14,
                      const float *ALIGNED t15,
                      float s, int n) {
#ifdef GRID_STRIDE
    // The realistic form. A grid-stride loop makes every window base
    // loop-INVARIANT, so it is hoisted and has to stay live across the whole
    // loop -- which is where uniform values actually compete for the register
    // file. The straight-line form below never holds one for more than two
    // instructions, so it answers a different question.
    for (unsigned i = CTAID_X * NTID_X + TID_X; i < (unsigned)n;
         i += NTID_X * GRID_STRIDE) {
#else
    unsigned i = CTAID_X * NTID_X + TID_X;
    if (i >= (unsigned)n) return;
#endif
    float v = x[i];
#if NT > 0
    v = v * s + t0[i];
#endif
#if NT > 1
    v = v * s + t1[i];
#endif
#if NT > 2
    v = v * s + t2[i];
#endif
#if NT > 3
    v = v * s + t3[i];
#endif
#if NT > 4
    v = v * s + t4[i];
#endif
#if NT > 5
    v = v * s + t5[i];
#endif
#if NT > 6
    v = v * s + t6[i];
#endif
#if NT > 7
    v = v * s + t7[i];
#endif
#if NT > 8
    v = v * s + t8[i];
#endif
#if NT > 9
    v = v * s + t9[i];
#endif
#if NT > 10
    v = v * s + t10[i];
#endif
#if NT > 11
    v = v * s + t11[i];
#endif
#if NT > 12
    v = v * s + t12[i];
#endif
#if NT > 13
    v = v * s + t13[i];
#endif
#if NT > 14
    v = v * s + t14[i];
#endif
#if NT > 15
    v = v * s + t15[i];
#endif
    out[i] = v > 0.0f ? v : 0.0f;          // ReLU, no transcendental needed
#ifdef GRID_STRIDE
    }
#endif
}
