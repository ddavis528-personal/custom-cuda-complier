#!/usr/bin/env bash
# Regenerate test/cuda/fp8-clang.ll from test/cuda/fp8.cu with NVIDIA's own
# cuda_fp8.h (CP-6, stage 2).
#
# The compatibility contract is CUDA source, so the FP8 test is compiled from
# the real header, not a CCV imitation of it. The gate does not fetch it: the
# clang IR is checked in, and this script is how it was made. NVIDIA ships the
# headers as pip wheels, like ptxas (tools/fetch-ptxas.sh); clang's CUDA mode
# wants them under one --cuda-path, so the wheels are linked into
# vendor/cuda-sdk. curand's headers are there only because clang's CUDA
# runtime wrapper includes one.
#
# sm_89 is the first architecture whose cuda_fp8.hpp converts in PTX (`cvt`
# with .satfinite); below it the header converts in software through double,
# which CCV does not lower yet.
set -euo pipefail
cd "$(dirname "$0")/.."
SDK=vendor/cuda-sdk
if [ ! -f "$SDK/include/cuda_fp8.h" ]; then
  ./tools/fetch-ptxas.sh >/dev/null
  for w in nvidia-cuda-runtime-cu12 nvidia-cuda-cccl-cu12 nvidia-curand-cu12; do
    [ -d "vendor/$w" ] || pip install --quiet --no-deps --target "vendor/$w" "$w"
  done
  mkdir -p "$SDK/include" "$SDK/nvvm/libdevice" "$SDK/bin"
  for d in vendor/nvidia-cuda-runtime-cu12/nvidia/cuda_runtime/include \
           vendor/ptxas/nvidia/cuda_nvcc/include \
           vendor/nvidia-cuda-cccl-cu12/nvidia/cuda_cccl/include \
           vendor/nvidia-curand-cu12/nvidia/curand/include; do
    cp -rs --update=none "$PWD/$d/." "$SDK/include/"
  done
  ln -sf "$PWD/$(find vendor/ptxas -name 'libdevice*.bc' | head -1)" \
         "$SDK/nvvm/libdevice/libdevice.10.bc"
  ln -sf "$PWD/$(find vendor/ptxas -name ptxas -type f | head -1)" "$SDK/bin/ptxas"
fi
clang -x cuda --cuda-path="$SDK" -nocudalib --cuda-device-only \
      --cuda-gpu-arch=sm_89 -O2 -emit-llvm -S test/cuda/fp8.cu \
      -o test/cuda/fp8-clang.ll 2> >(grep -v "warning: CUDA version" >&2)
# The path is the machine's, not the test's.
sed -i '/^source_filename/d; /^; ModuleID/d' test/cuda/fp8-clang.ll
echo "  test/cuda/fp8.cu -> test/cuda/fp8-clang.ll"
