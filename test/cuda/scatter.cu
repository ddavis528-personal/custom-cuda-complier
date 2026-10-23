// IS-14 (1)'s measurement: what atom.add.f32 would buy over a CAS loop. Each
// thread scatter-adds 8 values, as an embedding's backward pass or a
// histogram does: scatter_f in float (today a CAS loop: Format M has no FP
// add), scatter_i the same in integers (one atom.add.global each), which is
// what an atom.add.f32 would cost. tools/check-atomics.sh runs both at three
// levels of contention.
#include "portable.h"

__global__ void scatter_f(const unsigned *idx, const float *w, float *out,
                          int n) {
  int i = TID_X;
  if (i >= n) return;
#pragma unroll
  for (int j = 0; j < 8; ++j)
    __atomic_fetch_add(&out[idx[8 * i + j]], w[8 * i + j], __ATOMIC_RELAXED);
}

__global__ void scatter_i(const unsigned *idx, const unsigned *w,
                          unsigned *out, int n) {
  int i = TID_X;
  if (i >= n) return;
#pragma unroll
  for (int j = 0; j < 8; ++j)
    __atomic_fetch_add(&out[idx[8 * i + j]], w[8 * i + j], __ATOMIC_RELAXED);
}
