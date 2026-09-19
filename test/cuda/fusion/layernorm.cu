// LayerNorm, forward, saving the statistics the backward pass needs.
//
// Six tensors: output, input, weight, bias, and the per-row mean and reciprocal
// standard deviation. The last two are what makes this a SIX-pointer kernel
// rather than a four-pointer one, and they are there for a reason that has
// nothing to do with this measurement -- recomputing them in the backward pass
// costs a second pass over the activations. Every training-stack LayerNorm saves
// them.
//
// This is the largest real pointer count in the corpus that is fixed by the
// mathematics, which makes it the kernel that says most about where the
// launch-slot limit (F-140) actually bites.
#include "fusion.h"

#ifndef NWARP_THREADS
#define NWARP_THREADS 32
#endif

__global__ void layernorm(float *ALIGNED out, float *ALIGNED mean_out,
                          float *ALIGNED rstd_out, const float *ALIGNED input,
                          const float *ALIGNED weight, const float *ALIGNED bias,
                          float eps, int hidden) {
    __shared__ float rs[NWARP_THREADS];
    __shared__ float rq[NWARP_THREADS];
    unsigned t = TID_X;
    unsigned row = CTAID_X;
    unsigned base = row * (unsigned)hidden;

    // One pass for both moments, which is what the fused kernels do -- two
    // passes over the row would double the traffic on the tensor that does not
    // fit in cache.
    float s = 0.0f, q = 0.0f;
    for (unsigned i = t; i < (unsigned)hidden; i += NTID_X) {
        float v = input[base + i];
        s += v;
        q += v * v;
    }
    rs[t] = s;
    rq[t] = q;
    SYNC();
    for (unsigned k = NTID_X / 2; k > 0; k >>= 1) {
        if (t < k) { rs[t] += rs[t + k]; rq[t] += rq[t + k]; }
        SYNC();
    }
    float inv = ccv_recip((float)hidden);
    float m = rs[0] * inv;
    float r = ccv_rsqrt(rq[0] * inv - m * m + eps);
    if (t == 0) { mean_out[row] = m; rstd_out[row] = r; }

    for (unsigned i = t; i < (unsigned)hidden; i += NTID_X)
        out[base + i] = (input[base + i] - m) * r * weight[i] + bias[i];
}
