// Tiled transpose: the classic shared-memory staging pattern, and a pure
// addressing benchmark -- almost no arithmetic, all index computation.
#include "portable.h"
#define T 16
__global__ void transpose(float *ALIGNED out, const float *ALIGNED in, int n) {
    __shared__ float tile[T][T + 1];
    unsigned tx = TID_X % T, ty = TID_X / T;
    unsigned bx = CTAID_X % (unsigned)(n / T), by = CTAID_X / (unsigned)(n / T);
    tile[ty][tx] = in[(by * T + ty) * (unsigned)n + bx * T + tx];
    SYNC();
    out[(bx * T + ty) * (unsigned)n + by * T + tx] = tile[tx][ty];
}
