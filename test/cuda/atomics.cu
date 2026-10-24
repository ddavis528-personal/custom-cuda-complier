// O-72: CUDA atomics on computed addresses, as clang's builtins write them.
// A 64-bin histogram in .global, integer and float (the float add is
// atom.add.f32, O-76; it was a CAS loop), a 16-bin one in .shared merged after a
// barrier, and one word for each other operation. tools/check-atomics.sh
// compares the final memory with Python; where the result depends on the
// order lanes and warps apply in (which CAS wins), it checks the set §3's
// "any order" permits.
#include "portable.h"

__global__ void atomics(const unsigned *in, const float *w, unsigned *bins,
                        float *fbins, int *misc, int n) {
  __shared__ unsigned sh[16];
  int i = TID_X;
  if (i < 16)
    sh[i] = 0;
  __syncthreads();
  if (i < n) {
    unsigned x = in[i];
    unsigned b = x & 63;
    __atomic_fetch_add(&bins[b], 1u, __ATOMIC_RELAXED);
    __atomic_fetch_add(&fbins[b], w[i], __ATOMIC_RELAXED);
    __atomic_fetch_add(&sh[x & 15], 1u, __ATOMIC_RELAXED);
    int v = (int)x - 1000;
    __atomic_fetch_min(&misc[0], v, __ATOMIC_RELAXED);
    __atomic_fetch_max(&misc[1], v, __ATOMIC_RELAXED);
    __atomic_fetch_min((unsigned *)&misc[2], x, __ATOMIC_RELAXED);
    __atomic_fetch_max((unsigned *)&misc[3], x, __ATOMIC_RELAXED);
    __atomic_fetch_or(&misc[4], 1 << (i & 31), __ATOMIC_RELAXED);
    __atomic_fetch_xor(&misc[5], (int)x, __ATOMIC_RELAXED);
    __atomic_fetch_sub(&misc[6], i, __ATOMIC_SEQ_CST);
    __atomic_fetch_and(&misc[7], ~(1 << (i & 31)), __ATOMIC_RELAXED);
    int expect = 0;
    bool won = __atomic_compare_exchange_n(&misc[8], &expect, i + 1, false,
                                           __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __atomic_fetch_add(&misc[9], won ? 1 : 0, __ATOMIC_RELAXED);
    // A 16-bit counter: a sub-word atomic is a CAS loop on its word.
    __atomic_fetch_add(&((unsigned short *)misc)[21], (unsigned short)1,
                       __ATOMIC_RELAXED);
    // Exchange: every lane's old value is some lane's i, or the initial 7.
    int old = __atomic_exchange_n(&misc[11], i, __ATOMIC_RELAXED);
    misc[32 + i] = old;
  }
  __syncthreads();
  if (i < 16)
    misc[16 + i] = (int)sh[i];
}
