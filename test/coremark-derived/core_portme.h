// CCV port layer for a CoreMark-derived device workload (AR-20). Not a
// CoreMark score: the sources run unmodified but under a modified harness.
#ifndef CORE_PORTME_H
#define CORE_PORTME_H
#define HAS_FLOAT 0
#define HAS_TIME_H 0
#define USE_CLOCK 0
#define HAS_STDIO 0
#define HAS_PRINTF 0
#define COMPILER_VERSION "clang, CCV backend"
#define COMPILER_FLAGS "-O2"
#define MEM_LOCATION "global"
typedef signed short ee_s16;
typedef unsigned short ee_u16;
typedef signed int ee_s32;
typedef float ee_f32;
typedef unsigned char ee_u8;
typedef unsigned int ee_u32;
typedef unsigned long ee_ptr_int;
typedef unsigned long ee_size_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
// Round up to 4 bytes by pointer arithmetic: only the low bits are read.
#define align_mem(x) \
  (void *)((ee_u8 *)(x) + ((4 - ((ee_u32)(ee_ptr_int)(x) & 3)) & 3))
#define CORETIMETYPE ee_u32
typedef ee_u32 CORE_TICKS;
#define SEED_METHOD SEED_FUNC
#define MEM_METHOD MEM_MALLOC
#define MULTITHREAD 1
#define MAIN_HAS_NOARGC 1
#define MAIN_HAS_NORETURN 0
typedef struct CORE_PORTABLE_S { ee_u8 portable_id; } core_portable;
#define ee_printf(...) 0
#ifdef __cplusplus
extern "C" {
#endif
ee_s32 portme_sys1(void);
ee_s32 portme_sys2(void);
ee_s32 portme_sys3(void);
ee_s32 portme_sys4(void);
ee_s32 portme_sys5(void);
#ifdef __cplusplus
}
#endif
#endif
