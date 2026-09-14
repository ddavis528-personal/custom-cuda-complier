#!/usr/bin/env bash
# Fetch ptxas, so the SASS comparison can be reproduced.
#
# SASS is the comparison this project's density argument is actually written
# against -- CCV's compatibility target is CUDA -- and for most of the project's
# life it was absent, with the 128-bits-per-instruction figure carried as a
# citation. ptxas is a host compiler and needs no GPU; NVIDIA ships it as a
# pip wheel, which is the whole install.
#
# No disassembler is needed and none is published on PyPI. The cubin's
# .text.<kernel> section IS the SASS, and Volta-and-later encodes every
# instruction in exactly 16 bytes -- which tools/bench.py verifies rather than
# assumes, by checking that the section divides evenly.
set -euo pipefail
cd "$(dirname "$0")/.."
if [ -x vendor/cuda/nvidia/cuda_nvcc/bin/ptxas ]; then
  echo "  ptxas already present: $(vendor/cuda/nvidia/cuda_nvcc/bin/ptxas --version | tail -1)"
  exit 0
fi
pip install --quiet --no-deps --target vendor/cuda nvidia-cuda-nvcc-cu12
echo "  installed $(vendor/cuda/nvidia/cuda_nvcc/bin/ptxas --version | tail -1)"
