// Elementwise add on 16-bit integers -- the same shape as vadd.cu at half the
// element width, so the two are directly comparable.
//
// This exists to measure what F-3 asked for: how often a real kernel changes
// element width, and how much `chwidth.multi` merging recovers. One
// hand-written test answers neither question.
//
// `short` rather than `half` because §4's FP paths are not width-aware in the
// simulator yet; the width machinery is the same either way.
#include "portable.h"
__global__ void vadd16(short *ALIGNED c, const short *ALIGNED a,
                       const short *ALIGNED b, int n) {
    unsigned i = CTAID_X * NTID_X + TID_X;
    if (i < (unsigned)n) c[i] = (short)(a[i] + b[i]);
}
