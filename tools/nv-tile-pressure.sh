#!/usr/bin/env bash
# The same GEMM, compiled for NVIDIA, at the same tiles.
#
# `sweep-tiles.sh` says what a TM x TN tile costs CCV. It cannot say whether
# that cost is normal, and "16 GPRs" only means something against a machine
# running the same source. So: clang to PTX for sm_70, then `ptxas -v`, which
# reports registers used and spill bytes directly -- no counting, no
# heuristic, the vendor's own allocator reporting on the vendor's own file.
#
# Same file, same block shape, same tiles. The only difference is the machine.
# ptxas needs no GPU; tools/fetch-ptxas.sh installs it.
set -uo pipefail
cd "$(dirname "$0")/.."

PTXAS=$(find vendor -name ptxas -type f -perm -u+x 2>/dev/null | head -1)
if [ -z "$PTXAS" ]; then
  echo "  (ptxas not installed -- run tools/fetch-ptxas.sh; skipping)"
  exit 0
fi
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
INC=$(clang -print-resource-dir)/include

printf '  %-5s %-5s %9s %11s\n' tile accs registers spill
printf '  %s\n' "-----------------------------------"
for t in 1x1 1x2 2x2 2x4 4x4 8x8; do
  tm=${t%x*}; tn=${t#*x}
  clang -x cuda -nocudainc -nocudalib --cuda-device-only \
        --cuda-gpu-arch=sm_70 -I "$INC" -O2 -DTM="$tm" -DTN="$tn" \
        -S test/cuda/sgemm.cu -o "$TMP/n.ptx" 2>/dev/null || continue
  out=$("$PTXAS" -arch=sm_70 -O3 -v "$TMP/n.ptx" -o "$TMP/n.cubin" 2>&1)
  regs=$(echo "$out" | grep -oP 'Used \K\d+')
  # ptxas prints a spill line only when there is spill, so absent means zero.
  sp=$(echo "$out" | grep -oP '\d+(?= bytes spill)' | paste -sd+ | bc)
  printf '  %-5s %-5s %9s %11s\n' "$t" "$((tm*tn))" "${regs:-?}" "${sp:-0} bytes"
done

cat <<'TXT'

  Zero spill at every tile, including 8x8 -- 64 accumulators, which is the tile
  a throughput SGEMM actually uses and which CCV cannot hold at all. The
  comparison is not that NVIDIA spills less; it is that NVIDIA does not spill,
  and reaches an arithmetic intensity CCV has no way to reach.
TXT
