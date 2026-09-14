#!/usr/bin/env bash
# O-33 is a POWER optimisation. It must be invisible in the answer.
#
# So: compile the same kernel with masking on and off, execute both, and
# require identical results. A transformation that quietly changes what a
# kernel computes is worse than no transformation, and the ways this one can
# go wrong are all silent -- a value read from a lane that never computed it
# looks like a plausible number.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0

run_one() {              # $1 = label, $2 = extra llc flags
  build/ccv-llc test/accept/mask-uniform.ll -o "$TMP/$1.o" -obj $2 2>/dev/null || return 1
  llvm-objcopy -O binary --only-section=.text "$TMP/$1.o" "$TMP/$1.bin" || return 1
  local args=(-poke 0x20020=3 -poke 0x20030=1234)
  for i in $(seq 0 31); do args+=(-peek $((0x30000 + i*4))); done
  build/ccv-sim "$TMP/$1.bin" "${args[@]}" 2>&1
}

on=$(run_one on "")                        || { echo "  FAIL  masked build did not run"; exit 1; }
off=$(run_one off "-ccv-mask-uniform=false") || { echo "  FAIL  unmasked build did not run"; exit 1; }

got_on=$(echo "$on" | grep -oP '= \K\d+' | tr '\n' ' ')
got_off=$(echo "$off" | grep -oP '= \K\d+' | tr '\n' ' ')

# Independent reference: the chain in the kernel, evaluated in Python.
want=$(python3 - <<'PY'
M = 0xffffffff
a = 1234
a = (a * 3 + 1) & M
a = (a ^ (a >> 2)) & M
a = (a + 7) & M
a = (a * 5) & M
a = (a ^ (a >> 3)) & M
a = (a + 11) & M
print(' '.join(str((a + t) & M) for t in range(32)), end=' ')
PY
)

if [ "$got_on" != "$want" ]; then
  echo "  FAIL  masked result differs from reference"
  echo "        got  $got_on"; echo "        want $want"; fail=1
elif [ "$got_on" != "$got_off" ]; then
  echo "  FAIL  masking changed the result"; fail=1
else
  n=$(build/ccv-llc test/accept/mask-uniform.ll -o /dev/null -ccv-mask-stats 2>&1 |
      grep -oP 'masked to lane 0\s+: \K\d+')
  b=$(build/ccv-llc test/accept/mask-uniform.ll -o /dev/null -ccv-mask-stats 2>&1 |
      grep -oP 'broadcasts inserted\s+: \K\d+')
  echo "  PASS  lane-0 masking is result-identical ($n masked, $b broadcasts)"
  # A run where nothing was masked would pass vacuously.
  [ "${n:-0}" -gt 0 ] || { echo "  FAIL  nothing was masked -- test proves nothing"; fail=1; }
fi
exit $fail
