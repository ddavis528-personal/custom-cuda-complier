// Tiled transpose at four warps: a 32 x 32 tile staged through shared memory
// by a CTA of 32 x 4 threads, each moving eight rows. It is the CUDA samples'
// coalesced transpose, with the +1 column that keeps the tile's columns in
// different banks. test/bench/transpose.cu is the one-tile-per-thread form,
// which needs 256 threads; this one is AR-24's four-warp shape
// (release/kernels/transpose-128).
#include "portable.h"
#define TILE 32
#ifndef ROWS
#define ROWS 4
#endif
__global__ void transpose32(float *ALIGNED out, const float *ALIGNED in, int n) {
    __shared__ float tile[TILE][TILE + 1];
    unsigned tx = TID_X % TILE, ty = TID_X / TILE;
    unsigned tiles = (unsigned)n / TILE;
    unsigned bx = CTAID_X % tiles, by = CTAID_X / tiles;
    for (unsigned r = ty; r < TILE; r += ROWS)
        tile[r][tx] = in[(by * TILE + r) * (unsigned)n + bx * TILE + tx];
    SYNC();
    for (unsigned r = ty; r < TILE; r += ROWS)
        out[(bx * TILE + r) * (unsigned)n + by * TILE + tx] = tile[tx][r];
}
