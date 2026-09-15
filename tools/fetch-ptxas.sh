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
# Separate target directories per wheel. Both unpack under vendor/<dir>/nvidia/
# with different prefixes, and installing the second one into the same target
# silently removed the first.
find_tool() { find "vendor/$1" -name "$2" -type f -perm -u+x 2>/dev/null | head -1; }

if [ -z "$(find_tool ptxas ptxas)" ]; then
  pip install --quiet --no-deps --target vendor/ptxas nvidia-cuda-nvcc-cu12
fi
echo "  ptxas    $($(find_tool ptxas ptxas) --version | tail -1)"

# nvdisasm is optional: the density measurement needs only the cubin's .text
# size, and the disassembler is for reading what SASS actually does. Its 13.x
# releases have dropped sm_70, so it disassembles sm_90 while the density
# tables stay on sm_70 -- both measure 128.0 bits per instruction.
if [ -z "$(find_tool nvdisasm nvdisasm)" ]; then
  pip install --quiet --no-deps --target vendor/nvdisasm nvidia-cuda-nvdisasm || {
    echo "  nvdisasm unavailable (optional -- density does not need it)"; exit 0; }
fi
echo "  nvdisasm $($(find_tool nvdisasm nvdisasm) --version | tail -1)"
