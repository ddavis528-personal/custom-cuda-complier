// Host reference: NVIDIA's own conversions, compiled for the host.
#include <cuda_fp8.h>
#include <cuda_fp4.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
int main(int argc, char **argv) {
  // Reads "<kind> <hex>" lines; prints the result in hex.
  char kind[32]; unsigned x;
  while (scanf("%31s %x", kind, &x) == 2) {
    float f; memcpy(&f, &x, 4);
    unsigned r;
    if (!strcmp(kind, "to_e2m1")) r = __nv_cvt_float_to_fp4(f, __NV_E2M1, cudaRoundNearest);
    else if (!strcmp(kind, "to_e4m3_nosat")) r = __nv_cvt_float_to_fp8(f, __NV_NOSAT, __NV_E4M3);
    else if (!strcmp(kind, "to_e5m2_nosat")) r = __nv_cvt_float_to_fp8(f, __NV_NOSAT, __NV_E5M2);
    else if (!strcmp(kind, "from_e2m1")) { __nv_fp4_e2m1 v; v.__x = (__nv_fp4_storage_t)x; float g = float(v); memcpy(&r, &g, 4); }
    else return 2;
    printf("%s %08x %08x\n", kind, x, r);
  }
}
