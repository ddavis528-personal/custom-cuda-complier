#!/usr/bin/env bash
# What partial unrolling actually costs, executed rather than counted (F-131).
#
# The static numbers are dramatic and could be exactly backwards. A K loop
# unrolled by 1 has an eighth of the body and runs it eight times as often, so
# fewer static spill transfers can still mean more dynamic ones -- and dynamic
# is what a machine pays. Nothing settles that except running it, which is why
# sgemm needed to execute at all (F-134).
#
# N=8 is one K-tile: the loop body runs KT/KUNROLL times per tile, so the
# comparison is of the body, not of how many tiles a matrix happens to have.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
LAUNCH=0x20000

printf '  %-5s %-8s %8s %8s %8s %9s %9s\n' \
       tile unroll static dyn-iss dyn-spill st-spill dyn/static
printf '  %s\n' "---------------------------------------------------------------------"
for t in 1x1 2x2; do
  tm=${t%x*}; tn=${t#*x}
  for u in 1 2 4 8; do
    CCV_CFLAGS="-Itest/bench -DCCV_ALIGNED -DTM=$tm -DTN=$tn -DKUNROLL=$u" ./tools/cuda-to-asm.sh \
        test/cuda/sgemm.cu "$TMP/s.s" "$TMP/s" >/dev/null 2>&1
    if [ ! -s "$TMP/s.s" ]; then
      printf '  %-5s %-8s %8s %8s %8s %9s %9s\n' "$t" "$u" — — — — —
      continue
    fi
    read -r n _ <<<"$(python3 tools/count-code.py "$TMP/s.s")"
    sst=$(grep -cE '^\s*(st|ld)\.(global|pred).*\[r15' "$TMP/s.s")
    build/ccv-llc "$TMP/s-lowered.ll" -o "$TMP/s.o" -obj 2>/dev/null
    llvm-objcopy -O binary --only-section=.text "$TMP/s.o" "$TMP/s.bin"
    out=$(build/ccv-sim "$TMP/s.bin" \
            -poke ${LAUNCH}=32 -poke $((LAUNCH + 32))=3 \
            -poke $((LAUNCH + 40))=4 -poke $((LAUNCH + 48))=5 \
            -poke $((LAUNCH + 56))=8 -poke $((LAUNCH + 60))=1 \
            -counters -max-steps 2000000 2>&1)
    iss=$(echo "$out" | grep -oP 'issue groups\s+\K\d+' | head -1)
    dsp=$(echo "$out" | grep -oP 'spill:\K\d+')
    if [ -z "$iss" ]; then
      printf '  %-5s %-8s %8s %8s %8s %9s  %s\n' "$t" "$u" "$n" — — "$sst" \
             "$(echo "$out" | head -1 | cut -c1-40)"
      continue
    fi
    printf '  %-5s %-8s %8s %8s %8s %9s %9s\n' "$t" "$u" "$n" "$iss" \
           "${dsp:-0}" "$sst" \
           "$(python3 -c "print(round($iss/$n,2))")"
  done
done

cat <<'TXT'

  static is instructions in the .text section; dyn-iss is issue groups actually
  executed for one K-tile; dyn-spill is transfers through the frame pointer
  executed, which is the traffic the register file really forced. st-spill is
  the static count the earlier claim was based on.

  The column that decides it is dyn-spill against st-spill. A shorter body
  executed more often can spill less statically and more dynamically, and the
  static figure alone cannot tell the two apart.
TXT
