#!/usr/bin/env bash
# Forward progress between diverged lanes (ISA v1.9 O-60; IS-17).
#
# test/cuda/spinwait.cu: lane 0 spins on a volatile flag that lane 1 sets, and
# lane 1's store sits at a HIGHER PC than lane 0's loop. Under strict
# lowest-PC-first scheduling lane 1 never issues again, so the kernel hangs.
# O-60 says every diverged group of a live warp eventually issues, so under
# any fairness rule it finishes, with out[0] = 1 (lane 0 really waited),
# out[1] = 7 and the flag set.
#
# Four claims, each of which can fail on its own:
#   (1) the PC order the test rests on holds in the emitted code -- a layout
#       change that put the releaser first would make (2) pass vacuously;
#   (2) with ccv-sim's fairness off (-fairness 0, strict min-PC) it hangs:
#       the control, without which (3) proves nothing;
#   (3) with fairness at N = 4, 8, 16, 32 and the default, it finishes with
#       the right values. The issue counts are printed because TI chooses
#       FET's N from this kernel (AR's IS-17 response): a smaller N hands the
#       flag over sooner;
#   (4) test/spinwait.s, the hand-annotated copy TI runs, assembles to the
#       same bytes as the compiled kernel, so the two cannot drift apart.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS=-Itest/bench ./tools/cuda-to-asm.sh test/cuda/spinwait.cu "$TMP/s.s" "$TMP/s" \
  >/dev/null 2>&1 || { echo "  FAIL  spinwait.cu did not compile"; exit 1; }
build/ccv-llc "$TMP/s-lowered.ll" -o "$TMP/s.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/s.o" "$TMP/s.bin" || exit 1

# (1) The waiter's flag load (slot 0, the flag) comes before the releaser's
# flag store in the code, which is PC order.
ld=$(grep -n 'ld.global r[0-9]*, \[#0,' "$TMP/s.s" | head -1 | cut -d: -f1)
st=$(grep -n 'st.global r[0-9]*, \[#0,' "$TMP/s.s" | head -1 | cut -d: -f1)
if [ -z "$ld" ] || [ -z "$st" ] || [ "$ld" -ge "$st" ]; then
  echo "  FAIL  the spin loop is not below the releasing store (load at line"
  echo "        ${ld:-none}, store at ${st:-none}), so the kernel tests nothing"
  exit 1
fi

run() {
  build/ccv-sim "$TMP/s.bin" "$@" \
    -poke 0x20020=3 -poke 0x20024=0 -poke 0x20028=5 -poke 0x2002c=0 \
    -peek 0x30000 -peek 0x50000 -peek 0x50004 2>&1
}

fail=0
# (2) The control.
out=$(run -fairness 0)
if ! grep -q 'step limit reached' <<< "$out"; then
  echo "  FAIL  strict lowest-PC-first did not hang: $out"
  echo "        -- the kernel no longer needs O-60, so (3) proves nothing"
  fail=1
else
  echo "  PASS  spinwait hangs under strict lowest-PC-first (the control)"
fi

# (3) Fairness, at the N TI sweeps and ccv-sim's default.
res=""
for n in 4 8 16 32 default; do
  if [ "$n" = default ]; then out=$(run); else out=$(run -fairness "$n"); fi
  if grep -q '\[0x30000\] = 1$' <<< "$out" && grep -q '\[0x50000\] = 1$' <<< "$out" &&
     grep -q '\[0x50004\] = 7$' <<< "$out"; then
    res="$res N=$n:$(grep -oP 'executed \K\d+' <<< "$out")"
  else
    echo "  FAIL  fairness N=$n: $out"; fail=1
  fi
done
# (4) The annotated copy is the compiled kernel, byte for byte.
if python3 tools/ccv-as.py build/generated/CCV.json test/spinwait.s "$TMP/hand.bin" >/dev/null 2>&1 &&
   cmp -s "$TMP/hand.bin" "$TMP/s.bin"; then
  echo "  PASS  test/spinwait.s assembles to the compiled kernel's bytes"
else
  echo "  FAIL  test/spinwait.s no longer matches the compiled spinwait.cu"; fail=1
fi
[ $fail -eq 0 ] && echo "  PASS  spinwait finishes under O-60's fairness, issue groups at$res"
exit $fail
