#!/usr/bin/env bash
# CUDA source -> NVVM-flavoured LLVM IR, using clang's CUDA frontend unmodified.
#
# Per roadmap F-7 the frontend is not modified; its output is retargeted. This
# script is the whole frontend half of the pipeline.
#
# No CUDA toolkit is needed. -nocudainc/-nocudalib skip the SDK headers and
# libdevice; the builtin variables (threadIdx, blockIdx, ...) come from clang's
# own __clang_cuda_builtin_vars.h, which ships with clang.
set -euo pipefail
IN=${1:?usage: cuda-to-ir.sh <kernel.cu> [out.ll]}
OUT=${2:-${IN%.cu}.ll}
BV=$(find "$(clang -print-resource-dir)/include" -name '__clang_cuda_builtin_vars.h' | head -1)
[ -n "$BV" ] || { echo "cannot find __clang_cuda_builtin_vars.h" >&2; exit 1; }
# CCG_CFLAGS lets a caller pass -D for kernels parameterised at compile
# time, which is how the accumulator-tile sweep is driven.
clang -x cuda -nocudainc -nocudalib --cuda-device-only --cuda-gpu-arch=sm_70 \
      -I "$(dirname "$BV")" -O2 ${CCG_CFLAGS:-} -emit-llvm -S "$IN" -o "$OUT"
echo "  $IN -> $OUT"
