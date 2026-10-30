// O-83 (§5.9): a thread's interleaved region through __ccv_privbase. Each
// thread writes eight words of its own region and sums them back, so every
// thread reads its own bytes at the same pointer. A size over L gives a null
// pointer at run time, where the source's fallback takes over (here, a marker).
// With PRIV_CONST defined the size is that constant, and one over L must not
// compile. With FRAME defined the kernel also keeps FRAME bytes of frame (an
// address-taken array), which IS-25 puts at the bottom of the same region: the
// data, from L down, must stay above it, so a size that would reach it gives
// null, or does not compile where it is a constant, and a size that fits
// leaves the frame intact. tools/check-privbase.sh runs it.
#include "portable.h"
extern "C" __device__ void *__ccv_privbase(unsigned size);
#ifdef FRAME
__device__ __attribute__((noinline)) void fill(unsigned *a, unsigned t) {
    for (unsigned i = 0; i < FRAME / 4; ++i)
        a[i] = t + i;
}
__device__ __attribute__((noinline)) unsigned sum(const unsigned *a) {
    unsigned s = 0;
    for (unsigned i = 0; i < FRAME / 4; ++i)
        s += a[i];
    return s;
}
#endif
__global__ void privbase(unsigned *ALIGNED out, unsigned n) {
    unsigned t = TID_X;
#ifdef FRAME
    unsigned frame[FRAME / 4];
    fill(frame, t);
#endif
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
#ifdef FRAME
    // The frame's sum, FRAME/4 * t + the sum of 0..FRAME/4-1, as a second
    // result: the data's stores must not have reached it.
    out[32 + t] = sum(frame);
#endif
    out[t] = s;
}
