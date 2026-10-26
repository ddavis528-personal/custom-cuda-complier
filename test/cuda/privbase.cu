// O-83 (§5.9): a thread's interleaved region through __ccv_privbase. Each
// thread writes eight words of its own region and sums them back, so every
// thread reads its own bytes at the same pointer. A size over L gives a null
// pointer at run time, where the source's fallback takes over (here, a marker).
// With PRIV_CONST defined the size is that constant, and one over L must not
// compile. tools/check-privbase.sh runs it.
#include "portable.h"
extern "C" __device__ void *__ccv_privbase(unsigned size);
__global__ void privbase(unsigned *ALIGNED out, unsigned n) {
    unsigned t = TID_X;
#ifdef PRIV_CONST
    unsigned *p = (unsigned *)__ccv_privbase(PRIV_CONST);
    (void)n;
#else
    unsigned *p = (unsigned *)__ccv_privbase(n);
#endif
    if (!p) {
        out[t] = 0xFFFFFFFFu;
        return;
    }
    for (unsigned i = 0; i < 8; ++i)
        p[i] = t * 16 + i;
    unsigned s = 0;
    for (unsigned i = 0; i < 8; ++i)
        s += p[i];
    out[t] = s;
}
