#!/usr/bin/env bash
# The real fused-kernel corpus, measured (F-143).
#
# `tools/sweep-decode.sh` answered "where would a warp-uniform register file
# pay?" from ONE kernel -- test/cuda/fused.cu -- whose tensor count is a compile
# flag. Its answer was "the grid-strided fused chain at high tensor counts", and
# that is a statement about the top setting of a knob that was chosen here.
#
# test/cuda/fusion/ holds kernels written from the published shape of ones that
# actually run: RMSNorm and its fused-residual form, the GLU activation pair,
# rotary embedding, LayerNorm with saved statistics, the INT8 dequantisation
# epilogue, the flash-decoding combine, and the fused AdamW step. Every pointer
# count below is forced by the kernel's own mathematics. None of them is a knob.
#
# COLUMNS
#   ptrs/scal  kernel arguments, split. Both occupy launch-block words; only
#              pointers can use O-45's slot form, and only pointers were what
#              F-140 counted when it proposed widening the slot field.
#   slots      accesses that took the O-45 launch-slot form, so their window
#              base never entered the register file at all.
#   spills     transfers through r15, the whole of them (O-30 reserves r15).
#   uni/ptr/acc  those transfers by cause (F-113): warp-uniform values,
#              pointer and index values, accumulators. They do not sum to
#              `spills`; the residual is unclassified and is meant to be read.
#   div/unif   peak simultaneously-live values by divergence. A uniform
#              register file can hold the second and CANNOT hold the first.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

KERNELS="swiglu rmsnorm add_rmsnorm rope adamw dequant layernorm attn_combine"

cause() {                      # $1 = stats text, $2 = cause label
  echo "$1" | grep -oP "$2 : \K\d+ st, \d+ ld" |
    awk '{print $1 + $3}'
}

row() {
  local k=$1
  CCV_CFLAGS="-Itest/bench -Itest/cuda/fusion" ./tools/cuda-to-asm.sh \
      "test/cuda/fusion/$k.cu" "$TMP/k.s" "$TMP/k" >/dev/null 2>&1
  if [ ! -s "$TMP/k.s" ]; then
    printf '  %-13s %5s %5s %7s %7s %6s %7s %6s %6s %6s %9s\n' \
        "$k" — — — — — — — — — —
    return
  fi
  read -r n b <<<"$(python3 tools/count-code.py "$TMP/k.s")"
  local layout ptrs scal slots sp stats uni ptr acc pk u d
  layout=$(grep -oP 'ccv-arg-layout"="\K[^"]*' "$TMP/k-lowered.ll" | head -1)
  ptrs=$(echo "$layout" | tr ',' '\n' | grep -c '^p')
  scal=$(echo "$layout" | tr ',' '\n' | grep -c '^s')
  slots=$(grep -cE '\[#[0-9]+,' "$TMP/k.s")
  sp=$(grep -cE '^\s*(st|ld)\.(global|pred).*\[r15' "$TMP/k.s")
  stats=$(build/ccv-llc "$TMP/k-lowered.ll" -o /dev/null -ccv-spill-stats 2>&1)
  uni=$(cause "$stats" "warp-uniform"); ptr=$(cause "$stats" "pointer/index")
  acc=$(cause "$stats" "accumulator")
  pk=$(build/ccv-llc "$TMP/k-lowered.ll" -o /dev/null -ccv-uniformity-stats 2>&1)
  u=$(echo "$pk" | grep -oP 'peak uniform live\s*:\s*\K\d+')
  d=$(echo "$pk" | grep -oP 'peak divergent live\s*:\s*\K\d+')
  printf '  %-13s %5s %5s %7s %7s %6s %7s %6s %6s %6s %9s\n' \
      "$k" "$ptrs" "$scal" "$n" "$b" "$slots" "$sp" \
      "${uni:-0}" "${ptr:-0}" "${acc:-0}" "${d:-?}/${u:-?}"
}

echo "  real fused kernels -- pointer counts fixed by the mathematics, not swept"
printf '  %-13s %5s %5s %7s %7s %6s %7s %6s %6s %6s %9s\n' \
    kernel ptrs scal instrs bits slots spills uni-sp ptr-sp acc-sp div/unif
printf '  %s\n' "---------------------------------------------------------------------------------------"
for k in $KERNELS; do row "$k"; done

cat <<'TXT'

  THE POINTER COUNTS ARE 2 TO 6. The synthetic `fused.cu` swept 1 to 16 and the
  conclusions drawn from it -- F-129's case for a uniform register file, F-140's
  case for widening the launch-slot field -- were both read off its top settings.
  Nothing in this corpus reaches eight pointer arguments, which is the reach of
  O-45's 4-bit slot index. On this evidence the slot field is not the constraint.

  PTR-SP IS ZERO EVERYWHERE. F-126 and F-128 argued that what a uniform register
  file would hold is the spilling window bases and indices. After O-45 there are
  no spilling window bases: every one of these kernels addresses global memory
  through the slot form or a base the allocator never has to evict.

  WHAT SPILLS IS WARP-UNIFORM SCALARS. The three kernels that spill at all spill
  their non-pointer arguments -- `rope`'s head geometry, `adamw`'s eight
  optimiser constants, `attn_combine`'s split count -- together with the CTA
  index. Each is one launch-block word, each is identical in all 32 lanes, each
  is loop-invariant, and each currently costs a lane-0 masked load plus a
  broadcast (O-33) or a spill slot. They are exactly what a warp-uniform
  register file holds, and they are NOT what either previous argument for one
  named: not GEMM accumulators, which are per-lane, and not window bases, which
  O-45 removed.
TXT
