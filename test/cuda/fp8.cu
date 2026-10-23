// CP-6, stage 2: CUDA's FP8 conversions, from cuda_fp8.h itself. At sm_89 the
// header converts in inline PTX, which CCVExpandPTXAsm makes native; the
// clang IR is checked in as fp8-clang.ll (tools/gen-fp8-ir.sh), since the
// gate does not fetch NVIDIA's headers.
#include <cuda_fp8.h>
#include <cuda_fp16.h>

#define K(name) extern "C" __global__ void name
K(to_e4m3)(__nv_fp8_storage_t *o, const float *a) {
  int i = threadIdx.x;
  o[i] = __nv_cvt_float_to_fp8(a[i], __NV_SATFINITE, __NV_E4M3);
}
K(to_e5m2)(__nv_fp8_storage_t *o, const float *a) {
  int i = threadIdx.x;
  o[i] = __nv_cvt_float_to_fp8(a[i], __NV_SATFINITE, __NV_E5M2);
}
K(to_e4m3x2)(__nv_fp8x2_storage_t *o, const float *a) {
  int i = threadIdx.x;
  o[i] = __nv_cvt_float2_to_fp8x2(make_float2(a[2 * i], a[2 * i + 1]),
                                  __NV_SATFINITE, __NV_E4M3);
}
K(from_e4m3)(float *o, const __nv_fp8_e4m3 *a) {
  int i = threadIdx.x;
  o[i] = float(a[i]);
}
K(from_e5m2)(float *o, const __nv_fp8_e5m2 *a) {
  int i = threadIdx.x;
  o[i] = float(a[i]);
}
K(from_e5m2x2)(unsigned *o, const __nv_fp8x2_storage_t *a) {
  int i = threadIdx.x;
  __half2_raw h = __nv_cvt_fp8x2_to_halfraw2(a[i], __NV_E5M2);
  o[i] = h.x | (unsigned)h.y << 16;
}
K(half_round_trip)(float *o, const float *a) {
  int i = threadIdx.x;
  o[i] = __half2float(__float2half(a[i]));
}
// CP-6, stage 3: an FP8 dot product written in FP32 is one dp4.
K(dot_e4m3)(float *o, const __nv_fp8x4_e4m3 *a, const __nv_fp8x4_e4m3 *b) {
  int i = threadIdx.x;
  float4 x = float4(a[i]), y = float4(b[i]);
  o[i] += x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w;
}
K(dot_e5m2)(float *o, const __nv_fp8x4_e5m2 *a, const __nv_fp8x4_e5m2 *b) {
  int i = threadIdx.x;
  float4 x = float4(a[i]), y = float4(b[i]);
  o[i] = x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w;
}
// CP-6, stage 4: one operation in FP32, converted back, is the native one.
K(add_e4m3)(__nv_fp8_e4m3 *o, const __nv_fp8_e4m3 *a, const __nv_fp8_e4m3 *b) {
  int i = threadIdx.x;
  o[i] = __nv_fp8_e4m3(float(a[i]) + float(b[i]));
}
K(sub_e5m2)(__nv_fp8_e5m2 *o, const __nv_fp8_e5m2 *a, const __nv_fp8_e5m2 *b) {
  int i = threadIdx.x;
  o[i] = __nv_fp8_e5m2(float(a[i]) - float(b[i]));
}
K(mul_e4m3)(__nv_fp8_e4m3 *o, const __nv_fp8_e4m3 *a, const __nv_fp8_e4m3 *b) {
  int i = threadIdx.x;
  o[i] = __nv_fp8_e4m3(float(a[i]) * float(b[i]));
}
// Mixed formats have no native form, and must still be right.
K(add_mixed)(__nv_fp8_e4m3 *o, const __nv_fp8_e4m3 *a, const __nv_fp8_e5m2 *b) {
  int i = threadIdx.x;
  o[i] = __nv_fp8_e4m3(float(a[i]) + float(b[i]));
}
