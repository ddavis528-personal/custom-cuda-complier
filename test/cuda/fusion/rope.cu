// Rotary position embedding, applied in place to the query and key projections.
//
// Four tensors, shaped after vLLM's `rotary_embedding_kernel`: the token
// positions, the query and key tensors (read-modify-write), and a precomputed
// cos/sin table indexed by position. The table is the thing to notice -- every
// production RoPE precomputes it rather than calling `sinf`/`cosf` per element,
// which turns a transcendental workload into an ADDRESSING one, and makes this
// kernel four window bases doing almost no arithmetic.
//
// One deviation from the reference, stated rather than hidden: vLLM computes
// `head_idx = i / embed_dim` inside the thread loop, an integer division by a
// runtime value. §4 has no integer divide and the expansion is about thirty
// instructions (F-49), which would drown the addressing this kernel is here to
// show. The loop is nested over heads instead, which is what a hand-tuned
// version does and what the divide was standing in for.
#include "fusion.h"

__global__ void rope(const int *ALIGNED positions, float *ALIGNED query,
                     float *ALIGNED key, const float *ALIGNED cos_sin_cache,
                     int num_heads, int num_kv_heads, int head_size,
                     int rot_dim) {
    unsigned tok = CTAID_X;
    unsigned pos = (unsigned)positions[tok];
    unsigned half = (unsigned)rot_dim >> 1;
    unsigned cache = pos * (unsigned)rot_dim;

    for (int h = 0; h < num_heads; ++h) {
        unsigned q = (tok * (unsigned)num_heads + (unsigned)h) *
                     (unsigned)head_size;
        for (unsigned i = TID_X; i < half; i += NTID_X) {
            float c = cos_sin_cache[cache + i];
            float s = cos_sin_cache[cache + half + i];
            float x = query[q + i], y = query[q + half + i];
            query[q + i] = x * c - y * s;
            query[q + half + i] = y * c + x * s;
        }
    }
    for (int h = 0; h < num_kv_heads; ++h) {
        unsigned k = (tok * (unsigned)num_kv_heads + (unsigned)h) *
                     (unsigned)head_size;
        for (unsigned i = TID_X; i < half; i += NTID_X) {
            float c = cos_sin_cache[cache + i];
            float s = cos_sin_cache[cache + half + i];
            float x = key[k + i], y = key[k + half + i];
            key[k + i] = x * c - y * s;
            key[k + half + i] = y * c + x * s;
        }
    }
}
