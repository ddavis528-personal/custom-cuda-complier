#!/usr/bin/env bash
# Step 5's accumulator-tile sweep (O-25, §1's "one live risk"), by cause.
#
# Register-tile size drives register count on every GPU: a TM x TN per-thread
# C tile is TM*TN accumulators before a single pointer or index. This reports
# which tiles fit in the 16 GPRs O-25 settled on, what they cost, and -- since
# F-113 -- WHICH of the two causes the cost.
#
# `gpr-count-decision.md` asked for that split explicitly, and named FP32 as
# the case that gets neither mitigation it credits: out-of-order tolerance of
# lower arithmetic intensity, and `dp4.acc` doing four MACs per accumulator
# register. So both kernels are swept, identical in shape and differing only in
# arithmetic, and the accumulator column is the one the decision is about.
#
# The MAC column counts multiply-accumulates, not instructions: one `ffma`, one
# `mad.acc`, FOUR per `dp4`. Counting instructions would make the INT8 kernel
# look cheap for doing four times the work per instruction, which is the thing
# being measured rather than a property of the sweep.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

sweep() {                      # $1 = label, $2 = source
  echo
  echo "  $1"
  printf '  %-5s %-5s %8s %8s %7s %7s %6s %6s %7s %7s %5s\n' \
         tile accs instrs bits b/instr spills macs sp/mac acc-sp ptr-sp unif
  printf '  %s\n' "---------------------------------------------------------------------------------"
  for t in 1x1 1x2 2x2 2x4 4x4; do
    tm=${t%x*}; tn=${t#*x}
    CCV_CFLAGS="-DTM=$tm -DTN=$tn" ./tools/cuda-to-asm.sh "$2" \
        "$TMP/s.s" "$TMP/s" >/dev/null 2>"$TMP/err"
    if [ ! -s "$TMP/s.s" ]; then
      why=$(grep -oP 'CCV: \K.*?(?= --|$)' "$TMP/err" | head -1)
      printf '  %-5s %-5s %8s %8s %7s %7s %6s %6s %7s %7s %5s  %s\n' \
          "$t" "$((tm*tn))" — — — — — — — — — "${why:-did not compile}"
      continue
    fi
    read -r n b <<<"$(python3 tools/count-code.py "$TMP/s.s")"
    # A spill is a transfer through the frame pointer. Nothing else uses r15:
    # it is reserved (O-30), so this count is exact rather than a heuristic.
    sst=$(grep -cE '^\s*st\.(global|pred).*\[r15' "$TMP/s.s")
    sld=$(grep -cE '^\s*ld\.(global|pred).*\[r15' "$TMP/s.s")
    sp=$((sst + sld))
    # Multiply-accumulates, weighted: dp4 is four.
    m1=$(grep -cE '^\s*(ffma|mad)' "$TMP/s.s")
    m4=$(grep -cE '^\s*dp4' "$TMP/s.s")
    macs=$((m1 + 4 * m4))
    stats=$(build/ccv-llc "$TMP/s-lowered.ll" -o /dev/null -ccv-spill-stats 2>&1)
    pick() { echo "$stats" | grep -oP "^\s*$1 : \K\d+ st, \d+ ld" |
             awk '{print $1 + $3}'; }
    acc=$(pick accumulator); ptr=$(pick 'pointer/index')
    # Peak warp-uniform values live, from the analysis that already computes it.
    # Beside ptr-sp this is the whole F-106 question in two columns: an address
    # is warp-uniform in this kernel, so a uniform file sized like `unif` is
    # holding exactly the values `ptr-sp` is spilling.
    unif=$(build/ccv-llc "$TMP/s-lowered.ll" -o /dev/null -ccv-uniformity-stats \
           2>&1 | grep -oP 'peak uniform values live:\s*\K\d+')
    printf '  %-5s %-5s %8s %8s %7.1f %7s %6s %6.2f %7s %7s %5s\n' \
        "$t" "$((tm*tn))" "$n" "$b" "$(python3 -c "print($b/$n)")" "$sp" \
        "$macs" "$(python3 -c "print($sp/max($macs,1))")" \
        "${acc:-0}" "${ptr:-0}" "${unif:-0}"
  done
}

sweep "FP32 -- test/cuda/sgemm.cu" test/cuda/sgemm.cu
sweep "INT8 -- test/cuda/igemm.cu, four MACs per dp4" test/cuda/igemm.cu

cat <<'TXT'

  sp/mac is the decision number: memory traffic the register file forced, per
  multiply-accumulate it bought. A bigger tile raises arithmetic intensity as
  TM*TN/(TM+TN), so it is only worth it while sp/mac does not rise faster.

  acc-sp and ptr-sp are that traffic separated by cause (F-113), which is what
  `gpr-count-decision.md` asked for: accumulator spill is the risk §1 names as
  unmitigated for FP32, and pointer/index spill is the one O-23 addresses.
  They do not sum to `spills`: a slot whose role neither a use nor a defining
  opcode establishes -- a value live across a block boundary in both
  directions, mostly -- is left unclassified rather than assigned to whichever
  column looks likelier, and the residual is visible in the pass's own output.

  unif is the peak number of warp-uniform values live at once, from the same
  analysis that produced F-52 and F-58. It sits beside ptr-sp deliberately: an
  address in these kernels IS warp-uniform -- the window base and the block
  offsets are CTA-wide -- so a uniform register file of that size would hold
  the values the ptr-sp column is spilling. That pairing, not the accumulator
  column, is what the F-106 decision turns on.
TXT
