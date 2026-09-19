// RMSNorm. Three tensors, because RMSNorm has three tensors.
//
// Shaped after vLLM's `rms_norm_kernel`: one CTA per row, each thread striding
// the hidden dimension, a block reduction of the sum of squares, then a second
// pass that scales by the reciprocal RMS and by a per-channel weight. This is
// the normalisation every Llama-family block runs twice, and on a decode step
// it is a meaningful share of the non-GEMM time.
//
// The reason it is in a corpus about ADDRESS pressure: three window bases, and
// one of them (`weight`) is indexed by the channel and therefore reused across
// every row, while the other two move with the row. Nothing about that is a
// knob.
#include "fusion.h"

#ifndef NWARP_THREADS
#define NWARP_THREADS 32
#endif

__global__ void rmsnorm(float *ALIGNED out, const float *ALIGNED input,
                        const float *ALIGNED weight, float eps, int hidden) {
    __shared__ float red[NWARP_THREADS];
    unsigned t = TID_X;
    unsigned base = CTAID_X * (unsigned)hidden;

    float ss = 0.0f;
    for (unsigned i = t; i < (unsigned)hidden; i += NTID_X) {
        float v = input[base + i];
        ss += v * v;
    }
    red[t] = ss;
    SYNC();
    for (unsigned s = NTID_X / 2; s > 0; s >>= 1) {
        if (t < s) red[t] += red[t + s];
        SYNC();
    }
    float scale = ccv_rsqrt(red[0] * ccv_recip((float)hidden) + eps);

    for (unsigned i = t; i < (unsigned)hidden; i += NTID_X)
        out[base + i] = input[base + i] * scale * weight[i];
}
