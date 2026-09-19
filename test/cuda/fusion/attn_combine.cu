// The flash-decoding combine: fold the partial attention outputs of several
// key/value splits into one, rescaling by their softmax statistics.
//
// Four tensors, shaped after vLLM's `paged_attention_v2_reduce_kernel`. This is
// the kernel that makes long-context decode parallel -- the K/V sequence is cut
// into splits, each produces a partial output with its own running max and
// exponential sum, and this pass reconciles them. It is pure epilogue: no matrix
// multiply, a handful of flops per element, and its whole cost is addressing and
// the exponentials.
//
// `ccv_exp` here is `ex2` on a scaled argument, which is what `__expf` is (F-141)
// and what a real attention kernel uses -- an accurate `expf` inside a softmax
// is not something anyone ships.
#include "fusion.h"

#ifndef MAX_SPLITS
#define MAX_SPLITS 8
#endif

__global__ void attn_combine(float *ALIGNED out, const float *ALIGNED tmp_out,
                             const float *ALIGNED exp_sums,
                             const float *ALIGNED max_logits,
                             int num_splits, int head_size) {
    unsigned head = CTAID_X;
    unsigned st = head * (unsigned)num_splits;

    // The global max over the splits, then the rescaled sum of their weights.
    float m = max_logits[st];
    for (int s = 1; s < num_splits; ++s) {
        float v = max_logits[st + (unsigned)s];
        m = v > m ? v : m;
    }
    float total = 0.0f;
    for (int s = 0; s < num_splits; ++s)
        total += exp_sums[st + (unsigned)s] *
                 ccv_exp(max_logits[st + (unsigned)s] - m);
    float inv = ccv_recip(total);

    for (unsigned i = TID_X; i < (unsigned)head_size; i += NTID_X) {
        float a = 0.0f;
        for (int s = 0; s < num_splits; ++s) {
            unsigned o = (head * (unsigned)num_splits + (unsigned)s) *
                         (unsigned)head_size + i;
            a += tmp_out[o] * exp_sums[st + (unsigned)s] *
                 ccv_exp(max_logits[st + (unsigned)s] - m);
        }
        out[head * (unsigned)head_size + i] = a * inv;
    }
}
