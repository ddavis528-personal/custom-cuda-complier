// CP-6 stage 2b: CUDA's conversions that NVIDIA's headers do in software below
// sm_100 -- FP4 (E2M1) both ways, and FP8 with __NV_NOSAT -- from the headers
// themselves. They widen the float to double and work on its 64 bits, which
// lowerCCVFP64Bits rebuilds on 64-bit integers (F-186). The clang IR is
// checked in as fp4-clang.ll, and NVIDIA's own results for every input
// tools/check-fp4.sh uses as fp4-expected.txt (tools/gen-fp8-ir.sh).
#include <cuda_fp8.h>
#include <cuda_fp4.h>

#define K(name) extern "C" __global__ void name
K(to_e2m1)(__nv_fp4_storage_t *o, const float *a) {
  int i = threadIdx.x;
  o[i] = __nv_cvt_float_to_fp4(a[i], __NV_E2M1, cudaRoundNearest);
}
K(from_e2m1)(float *o, const __nv_fp4_e2m1 *a) {
  int i = threadIdx.x;
  o[i] = float(a[i]);
}
K(to_e4m3_nosat)(__nv_fp8_storage_t *o, const float *a) {
  int i = threadIdx.x;
  o[i] = __nv_cvt_float_to_fp8(a[i], __NV_NOSAT, __NV_E4M3);
}
K(to_e5m2_nosat)(__nv_fp8_storage_t *o, const float *a) {
  int i = threadIdx.x;
  o[i] = __nv_cvt_float_to_fp8(a[i], __NV_NOSAT, __NV_E5M2);
}
