#!/usr/bin/env bash
# Step 5's accumulator-tile sweep (O-25, §1's "one live risk").
#
# Register-tile size drives register count on every GPU: a TM x TN per-thread
# C tile is TM*TN accumulators before a single pointer or index. This reports
# which tiles fit in the 16 GPRs O-25 settled on, and what they cost.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

printf '  %-5s %-5s %8s %8s %7s %7s %6s %6s %8s\n' \
       tile accs instrs bits b/instr spills fma sp/fma K-hit
printf '  %s\n' "-------------------------------------------------------------------------"
for t in 1x1 1x2 2x2 2x4 4x4; do
  tm=${t%x*}; tn=${t#*x}
  CCV_CFLAGS="-DTM=$tm -DTN=$tn" ./tools/cuda-to-asm.sh test/cuda/sgemm.cu \
      "$TMP/s.s" "$TMP/s" >/dev/null 2>"$TMP/err"
  if [ ! -s "$TMP/s.s" ]; then
    why=$(grep -oP 'CCV: \K.*?(?= --|$)' "$TMP/err" | head -1)
    printf '  %-5s %-5s %8s %8s %7s %7s %6s %6s %8s  %s\n' \
        "$t" "$((tm*tn))" — — — — — — — "${why:-did not compile}"
    continue
  fi
  read -r n b <<<"$(python3 tools/count-code.py "$TMP/s.s")"
  # A spill is a transfer through the frame pointer. Nothing else uses r15:
  # it is reserved (O-30), so this count is exact rather than a heuristic.
  sst=$(grep -cE '^\s*st\.(global|pred).*\[r15' "$TMP/s.s")
  sld=$(grep -cE '^\s*ld\.(global|pred).*\[r15' "$TMP/s.s")
  hit=$(build/ccv-llc "$TMP/s-lowered.ll" -o /dev/null -ccv-compress-stats 2>&1 |
        grep -oP 'rd == rs0 already\s*:\s*\d+\s*\(\K\d+' || echo 0)
  sp=$((sst + sld))
  fma=$(grep -cE '^\s*(ffma|fadd|fmul)' "$TMP/s.s")
  printf '  %-5s %-5s %8s %8s %7.1f %7s %6s %6.2f %7s%%\n' \
      "$t" "$((tm*tn))" "$n" "$b" "$(python3 -c "print($b/$n)")" "$sp" "$fma" \
      "$(python3 -c "print($sp/max($fma,1))")" "$hit"
done

echo
echo "  sp/fma is the decision number: memory traffic the register file forced,"
echo "  per unit of arithmetic it bought. A bigger tile raises arithmetic"
echo "  intensity as TM*TN/(TM+TN), so it is only worth it while sp/fma does not"
echo "  rise faster. Spill that scales with TM*TN is accumulator spill -- the one"
echo "  §1 names as having no mitigation; spill that does not is pointer and"
echo "  index traffic, which O-23 already addresses."
