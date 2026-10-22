// Host reference for kernel.cu: the same harness, one context.
#include <stdio.h>
#include <stdlib.h>
#include "coremark.h"
ee_s32 portme_sys1(void) { return 0; }
ee_s32 portme_sys2(void) { return 0; }
ee_s32 portme_sys3(void) { return 0x66; }
ee_s32 portme_sys4(void) { return 1; }
ee_s32 portme_sys5(void) { return 0; }
void *iterate(void *p) { return 0; }
int main(int argc, char **argv) {
  static ee_u8 mem[TOTAL_DATA_SIZE];
  core_results r;
  r.seed1 = 0; r.seed2 = 0; r.seed3 = 0x66; r.iterations = atoi(argv[1]);
  r.execs = ALL_ALGORITHMS_MASK;
  r.size = TOTAL_DATA_SIZE / NUM_ALGORITHMS;
  ee_u8 *b = mem;
  r.memblock[0] = b;
  for (int i = 0; i < NUM_ALGORITHMS; ++i) r.memblock[i + 1] = b + r.size * i;
  r.list = core_list_init(r.size, (list_head *)r.memblock[1], r.seed1);
  core_init_matrix(r.size, r.memblock[2], (ee_s32)r.seed1 | (((ee_s32)r.seed2) << 16), &r.mat);
  core_init_state(r.size, r.seed1, (ee_u8 *)r.memblock[3]);
  r.crc = 0; r.crclist = 0; r.crcmatrix = 0; r.crcstate = 0;
  for (ee_u32 i = 0; i < r.iterations; ++i) {
    ee_u16 c = core_bench_list(&r, 1);
    r.crc = crcu16(c, r.crc);
    c = core_bench_list(&r, -1);
    r.crc = crcu16(c, r.crc);
    if (i == 0) r.crclist = r.crc;
  }
  printf("%04x %04x %04x %04x\n", r.crc, r.crclist, r.crcmatrix, r.crcstate);
}
