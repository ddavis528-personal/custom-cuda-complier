// IS-25: a frame pointer is lane-relative, so one handed to another thread
// names the receiver's frame there. ccv-llc warns where that is visible.
// tools/check-frame-escape.sh compiles this and expects exactly the two
// escapes marked below, and none for the private uses.
#include "portable.h"
__device__ __attribute__((noinline)) void bump(unsigned *p) { *p += 1; }
__device__ __attribute__((noinline)) void keep(unsigned **slot, unsigned *p) { *slot = p; }
__global__ void frame_escape(unsigned *ALIGNED out, unsigned **ALIGNED where) {
    __shared__ unsigned *handoff[32];
    unsigned t = TID_X;
    unsigned mine[4] = {t, t + 1, t + 2, t + 3};
    unsigned *alias[1];
    bump(&mine[0]);                 // private: through a device function
    keep(&alias[0], &mine[1]);      // private: stored into another frame object
    handoff[t] = &mine[2];          // ESCAPE: to .shared
    where[t] = &mine[3];            // ESCAPE: to .global
    __syncthreads();
    out[t] = mine[0] + *alias[0] + *handoff[t ^ 1] + *where[t];
}
