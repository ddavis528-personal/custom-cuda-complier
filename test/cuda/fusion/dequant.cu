// The dequantisation epilogue of an INT8 matrix multiply.
//
// Six tensors, and every one of them is forced by the quantisation scheme:
// the INT32 accumulator the tensor cores produced, a per-ROW activation scale, a
// per-COLUMN weight scale, the bias, the residual stream to add, and the output.
// This is the kernel that makes quantised inference worth doing and it is
// usually fused into the GEMM's epilogue for exactly the reason this corpus
// cares about -- so the INT32 accumulator never reaches memory.
//
// The two scale vectors are the shape worth having in a corpus: one is indexed
// by the row and is therefore warp-uniform within a CTA, the other is indexed by
// the column and is divergent. A measurement that only ever saw per-element
// tensors would never separate those.
#include "fusion.h"

__global__ void dequant(float *ALIGNED out, const int *ALIGNED acc,
                        const float *ALIGNED scale_row,
                        const float *ALIGNED scale_col,
                        const float *ALIGNED bias,
                        const float *ALIGNED residual, int cols) {
    unsigned r = CTAID_X;
    unsigned base = r * (unsigned)cols;
    float sr = scale_row[r];
    for (unsigned c = TID_X; c < (unsigned)cols; c += NTID_X) {
        float v = (float)acc[base + c] * sr * scale_col[c] + bias[c];
        out[base + c] = ccv_gelu(v + residual[base + c]);
    }
}
