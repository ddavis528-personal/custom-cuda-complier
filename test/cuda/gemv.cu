// Decode-shaped GEMV: y = W x, batch 1 (F-129).
//
// This is what LLM inference does per token once the prompt is processed, and
// it is the opposite of `sgemm` in the way that matters here. There is no reuse
// to tile for: every weight is read once and used once, so arithmetic intensity
// is fixed at one MAC per weight element regardless of how the kernel is
// written. The register file cannot buy anything back, because there is nothing
// to keep. Whatever spills here is not accumulator pressure.
//
// One output row per thread. The activation vector x is the only reused
// operand, so it is staged through shared memory exactly as sgemm stages its
// K-tile -- same structure, so the comparison is about the arithmetic and not
// about the staging.
#include "portable.h"

#ifndef KT
#define KT 32                      // activation tile staged per pass
#endif

__global__ void gemv(float *ALIGNED y, const float *ALIGNED W,
                     const float *ALIGNED x, int K) {
    __shared__ float xs[KT];
    unsigned row = CTAID_X * NTID_X + TID_X;
    float acc = 0.0f;
    for (int k0 = 0; k0 < K; k0 += KT) {
        if (TID_X < KT) xs[TID_X] = x[k0 + TID_X];
        SYNC();
#pragma unroll
        for (int k = 0; k < KT; ++k)
            acc += W[row * K + (k0 + k)] * xs[k];
        SYNC();
    }
    y[row] = acc;
}
