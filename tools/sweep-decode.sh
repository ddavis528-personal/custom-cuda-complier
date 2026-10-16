#!/usr/bin/env bash
# The shapes that dominate inference outside the matrix multiply (F-129).
#
# F-127 measured the GEMM tile ceiling and F-128 read the spill split beside
# the uniform-value count and concluded a warp-uniform register file would hold
# what was spilling. Both were about `sgemm`. This sweeps the other shapes --
# batch-1 GEMV, which is what decode does per token, and a fused elementwise
# epilogue over a swept number of tensors -- and reports the numbers that
# actually decide whether a uniform file pays.
#
#   div/unif   peak simultaneously-live values, split by divergence. A uniform
#              file holds the uniform ones and CANNOT hold the divergent ones,
#              whatever role they play -- so if the divergent peak alone
#              exceeds the 16-entry file, a uniform file does not stop the
#              spilling. This is the column F-128 did not look at.
#   uni-ld     loads of a warp-uniform value from the launch block, and their
#              share of the kernel. These are the §5.1 window bases and
#              per-argument offsets, re-fetched at each use instead of held in
#              a register. Nothing spills because of them -- they were never in
#              a register to spill -- but they are not free, and they are
#              exactly what a uniform file would hold.
#
# Distinguishing them from data loads is structural rather than a guess:
# Format D base+displacement `[rN + imm]` is how the launch block is read, and
# every data access in these kernels is base+index `[rN, rM, s, d]`.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

row() {                       # $1 = label, $2 = source, $3 = extra cflags
  CCV_CFLAGS="-Itest/bench ${3:-}" ./tools/cuda-to-asm.sh "$2" \
      "$TMP/k.s" "$TMP/k" >/dev/null 2>&1
  if [ ! -s "$TMP/k.s" ]; then
    printf '  %-12s %8s %8s %7s %9s %8s\n' "$1" — — — — —
    return
  fi
  read -r n b <<<"$(python3 tools/count-code.py "$TMP/k.s")"
  sp=$(grep -cE '^\s*(st|ld)\.(global|pred).*\[r15' "$TMP/k.s")
  uni=$(grep -cE '^\s*ld\.global r[0-9]+, \[r[0-9]+( \+ [0-9]+)?\]$' "$TMP/k.s")
  pk=$(build/ccv-llc "$TMP/k-lowered.ll" -o /dev/null -ccv-uniformity-stats 2>&1)
  u=$(echo "$pk" | grep -oP 'peak uniform live\s*:\s*\K\d+')
  d=$(echo "$pk" | grep -oP 'peak divergent live\s*:\s*\K\d+')
  printf '  %-12s %8s %8s %7s %9s %7s%%\n' \
      "$1" "$n" "$b" "$sp" "${d:-?}/${u:-?}" \
      "$(python3 -c "print(round(100*$uni/$n))")"
}

echo "  decode and fused shapes -- what binds when there is no tile to fill"
printf '  %-12s %8s %8s %7s %9s %8s\n' kernel instrs bits spills div/unif uni-ld
printf '  %s\n' "------------------------------------------------------------"
row "gemv"        test/cuda/gemv.cu
row "gemv8"       test/cuda/gemv8.cu
for n in 1 4 8 16; do
  row "fused NT=$n" test/cuda/fused.cu "-DNT=$n"
done
echo
echo "  ...and the same fused chain as a grid-stride LOOP, which is how one is"
echo "  actually written. The bases become loop-invariant, so they are hoisted"
echo "  and have to stay live across the loop instead of for two instructions:"
printf '  %s\n' "------------------------------------------------------------"
for n in 1 4 8 16; do
  row "loop NT=$n" test/cuda/fused.cu "-DNT=$n -DGRID_STRIDE=64"
done
echo
echo "  For contrast, the same two columns on the GEMM this was compared against:"
printf '  %s\n' "------------------------------------------------------------"
for t in 2x2 2x4 4x4; do
  tm=${t%x*}; tn=${t#*x}
  row "sgemm $t" test/cuda/sgemm.cu "-DCCV_ALIGNED -DTM=$tm -DTN=$tn"
done

cat <<'TXT'

  Read the div/unif column first. In `sgemm` the divergent peak alone is several
  times the 16-entry register file -- its addressing is indexed by `threadIdx`,
  so the row and column offsets differ per lane and a uniform file cannot hold
  them. In the fused kernels it is the other way round: almost everything live
  is uniform, and the divergent peak never leaves single digits.

  Then read uni-ld. No fused shape spills at any tensor count, straight-line or
  looped, which is not the same as not paying: each window base the slot form
  does not reach is re-fetched from the launch block at its use rather than
  kept in a register, so the cost lands in the instruction count -- a quarter
  of it -- instead of in spill traffic.

  The grid-stride rows are the ones that decide it, and what they decide
  CHANGED when the launch-slot stride was re-scaled to 8 bytes (DA's response
  CP-4, 2026-10-08). Making the chain a loop makes the bases loop-invariant, so
  they are hoisted and must stay live: the divergent peak stays at 4 whatever
  the tensor count while the uniform peak passes the 16-entry file. Under the
  4-byte stride the slot form reached only the first eight pointer arguments,
  and loop NT=16 spilled 9 transfers on top of 114 instructions -- the one
  shape measured here where a warp-uniform register file would have removed
  essentially all of the traffic. At 8 bytes the form reaches all sixteen, and
  that row is 92 instructions with NO spill traffic at all.

  So the honest reading now: uniform pressure in this corpus costs INSTRUCTIONS
  and not spills. That is a real weakening of the measured case for a
  warp-uniform register file (F-106), whose revival condition was that O-45 be
  adopted and then measured to leave significant uniform pressure behind. What
  it leaves is a quarter of the instruction stream re-reading a table that is
  already in cache, which is a smaller claim than spill traffic and has to be
  argued on its own terms rather than on this row.
TXT
