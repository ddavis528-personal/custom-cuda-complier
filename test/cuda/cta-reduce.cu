// TI-29: a CTA's warps talking through .shared across __syncthreads, which
// ccv-sim runs with -cta. Each thread counts the Collatz steps of its input,
// a loop whose length the input sets, so warps reach the first barrier far
// apart; then a tree sum over .shared, a barrier at every level, reads other
// warps' words. tools/check-cta.sh gives warp 0 short inputs and the rest
// long ones: a barrier that let warp 0 through before the others arrived
// would have it read words they have not yet written.
#include "portable.h"

__global__ void cta_reduce(const unsigned *in, unsigned *out) {
  __shared__ unsigned s[128];
  int t = TID_X;
  unsigned v = in[t], steps = 0;
  while (v > 1) {
    v = v & 1 ? 3 * v + 1 : v >> 1;
    ++steps;
  }
  s[t] = steps;
  __syncthreads();
  for (int k = 64; k > 0; k >>= 1) {
    if (t < k)
      s[t] += s[t + k];
    __syncthreads();
  }
  out[t] = s[0] + (unsigned)t;
}
