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

# CP-6 stage 2b: FP4 and __NV_NOSAT, which the headers do in software below
# sm_100. Their expected results are NVIDIA's own code compiled for the host
# (tools/fp4-hostref), so the check needs no model of what the header does:
# every FP4 nibble, and for each conversion from FP32 every target value, the
# midpoints between them, each nudged an FP32 ulp either way, both signs, the
# specials, overflow, subnormals and random patterns.
clang -x cuda --cuda-path="$SDK" -nocudalib --cuda-device-only \
      --cuda-gpu-arch=sm_89 -O2 -emit-llvm -S test/cuda/fp4.cu \
      -o test/cuda/fp4-clang.ll 2> >(grep -v "warning: CUDA version" >&2)
sed -i '/^source_filename/d; /^; ModuleID/d' test/cuda/fp4-clang.ll
REF=$(mktemp -d); trap 'rm -rf "$REF"' EXIT
clang++ -x cuda --cuda-path="$SDK" -nocudalib --cuda-host-only -O1 \
        tools/fp4-hostref/hostref.cu -o "$REF/hostref" 2> >(grep -v "warning: CUDA version" >&2)
python3 - <<'PY' | "$REF/hostref" > test/cuda/fp4-expected.txt
import random, struct
f2b = lambda f: struct.unpack("<I", struct.pack("<f", f))[0]
def values(eb, mb, bias, top):
    """Every non-negative finite value of a format, ascending, to `top`."""
    out = []
    for e in range(1 << eb):
        for m in range(1 << mb):
            v = (m / (1 << mb)) * 2.0 ** (1 - bias) if e == 0 else \
                (1 + m / (1 << mb)) * 2.0 ** (e - bias)
            if v <= top:
                out.append(v)
    return sorted(set(out))
rng = random.Random(4)
for kind, (eb, mb, bias, top) in (("to_e2m1", (2, 1, 1, 6.0)),
                                  ("to_e4m3_nosat", (4, 3, 7, 448.0)),
                                  ("to_e5m2_nosat", (5, 2, 15, 57344.0))):
    q = values(eb, mb, bias, top)
    pts = q + [(a + b) / 2 for a, b in zip(q, q[1:])]
    # Past the top: the half-ulp above it, where rounding overflows.
    pts += [top * 1.0625, top * 1.125, top * 1.25, top * 2, top * 1e3]
    xs = set()
    for p in pts:
        b = f2b(p)
        for d in (-1, 0, 1):
            if 0 <= b + d < 0x7F800000:
                xs |= {b + d, (b + d) | 0x80000000}
    xs |= {0x7F800000, 0xFF800000, 0x7FC00000, 0xFFC00001, 0x7F800001,
           0x7F7FFFFF, 0x00000001, 0x80000001, 0x007FFFFF, 0x00800000}
    xs |= {rng.getrandbits(32) for _ in range(300)}
    for x in sorted(xs):
        print(kind, f"{x:08x}")
for n in range(16):
    print("from_e2m1", f"{n:08x}")
PY
echo "  test/cuda/fp4.cu -> test/cuda/fp4-clang.ll, fp4-expected.txt ($(wc -l < test/cuda/fp4-expected.txt) results)"
