// A column walk at a fixed row pitch, for MIU/DCU Phase 1's bank and set
// conflicts (AR 373 (2), DA rev 125). One CTA of 4 warps; thread t of warp w
// (tid = w * 32 + t) sums the float at byte offset r * P + tid * 4 of `in` over
// rows r = 0 to 63, npass times (two in the exported launch), and stores the
// sum at out[tid]. At P of 1 KiB or more each row's 128 threads read one
// 512-byte stretch, so a warp's row is one line and successive rows are P
// apart: the same bank, and from 16 KiB the same sets, row after row.
//
// The pitch is compile-time: -DPITCH_KIB=<P> (1, 2, 4, 8, 16, 32), or
// -DPITCH_BYTES=<P> for the 128-byte sequential control.
//
// The loads are unrolled by 8 and independent of each other, so a warp issues
// eight back to back; only the adds chain. Both loops are kept as loops
// (unroll 1): unrolled whole, the 64 loads would not depend on the pass, and
// the compiler would hoist them out of it and spill them, so the second pass
// would read the spill area instead of re-reading the column from L1. The
// pass count comes from the launch for the same reason.
#include "portable.h"
#ifdef PITCH_KIB
#define PITCH (PITCH_KIB * 1024u)
#elif defined(PITCH_BYTES)
#define PITCH (PITCH_BYTES * 1u)
#else
#error "colwalk.cu: define PITCH_KIB or PITCH_BYTES"
#endif
#define ROWS 64
#define STRIDE (PITCH / 4u)          // floats a row

__global__ void colwalk(float *ALIGNED out, const float *ALIGNED in, int npass) {
    unsigned tid = TID_X;
    const float *col = in + tid;
    float s = 0.0f;
#pragma unroll 1
    for (int p = 0; p < npass; ++p) {
#pragma unroll 1
        for (unsigned r = 0; r < ROWS; r += 8) {
            const float *q = col + r * STRIDE;
            float v0 = q[0 * STRIDE], v1 = q[1 * STRIDE], v2 = q[2 * STRIDE], v3 = q[3 * STRIDE];
            float v4 = q[4 * STRIDE], v5 = q[5 * STRIDE], v6 = q[6 * STRIDE], v7 = q[7 * STRIDE];
            s += v0; s += v1; s += v2; s += v3;
            s += v4; s += v5; s += v6; s += v7;
        }
    }
    out[tid] = s;
}
