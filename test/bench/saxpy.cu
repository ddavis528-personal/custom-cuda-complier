// a*x + y -- the canonical FMA kernel, and the one where an accumulate form
// should show.
#include "portable.h"
__global__ void saxpy(float *ALIGNED y, const float *ALIGNED x, float a, int n) {
    unsigned i = CTAID_X * NTID_X + TID_X;
    if (i < (unsigned)n) y[i] = a * x[i] + y[i];
}
