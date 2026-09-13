//===-- portable.h - one source, three compilers -------------------------===//
//
// The benchmark kernels are compiled unchanged for CCG (via clang's CUDA
// frontend), for PTX (nvptx64) and for AMDGCN. That is the whole point: an
// instruction-count comparison is only meaningful when the three compilers are
// given the same algorithm, and a density comparison is only meaningful when
// they are given the same kernel.
//
// Nothing here is a shim around a capability gap -- every construct below
// exists natively in all three. Where a builtin is spelled differently the
// macro renames it; it never emulates.
//
//===----------------------------------------------------------------------===//
#ifndef CCG_BENCH_PORTABLE_H
#define CCG_BENCH_PORTABLE_H

#define __global__ __attribute__((global))
#define __device__ __attribute__((device))
#define __shared__ __attribute__((shared))

#ifdef __HIP__
#define TID_X   __builtin_amdgcn_workitem_id_x()
#define CTAID_X __builtin_amdgcn_workgroup_id_x()
#define NTID_X  __builtin_amdgcn_workgroup_size_x()
#define SYNC()  __builtin_amdgcn_s_barrier()
#define ALIGNED
#else
#include <__clang_cuda_builtin_vars.h>
#define TID_X   threadIdx.x
#define CTAID_X blockIdx.x
#define NTID_X  blockDim.x
#define SYNC()  __syncthreads()
// O-23's per-argument alignment attribute. AMDGCN has no equivalent and does
// not need one -- it has 64-bit pointers in registers -- so the comparison is
// run BOTH ways and both are reported. See the benchmark notes.
#ifdef CCG_ALIGNED
#define ALIGNED __attribute__((align_value(65536)))
#else
#define ALIGNED
#endif
#endif

#endif
