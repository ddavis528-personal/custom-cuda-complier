#!/usr/bin/env bash
# Frontend + kernel-ABI lowering, on real clang output.
#
# Checks the O-23 claim that matters for codegen: an aligned pointer argument
# costs one launch-block slot and an unaligned one costs two, and that the
# difference arrives from the optimiser rather than a backend special case.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
PLUGIN=build/CCGLowerKernelArgs.so
fail=0

[ -f "$PLUGIN" ] || { echo "  plugin not built"; exit 1; }

lower() {
  ./tools/cuda-to-ir.sh "$1" "$TMP/$2.ll" >/dev/null || return 1
  opt -load-pass-plugin="$PLUGIN" -passes='ccg-lower-kernel-args,instcombine,gvn' \
      -S "$TMP/$2.ll" -o "$TMP/$2.low.ll" 2>/dev/null
}

lower test/cuda/vadd.cu un       || { echo "  FAIL  frontend (unaligned)"; fail=1; }
lower test/cuda/vadd-aligned.cu al || { echo "  FAIL  frontend (aligned)"; fail=1; }

# grep -c prints 0 and exits 1 when there are no matches, so no "|| echo 0".
un=$(grep -c 'invariant.load' "$TMP/un.low.ll" 2>/dev/null)
al=$(grep -c 'invariant.load' "$TMP/al.low.ll" 2>/dev/null)
ro=$(grep -c 'roffset'        "$TMP/al.low.ll" 2>/dev/null)

# Three pointers, so the aligned form must save exactly three slots -- one per
# pointer. Asserting the DELTA rather than absolute counts: the block also
# supplies blockDim and grid dimensions (§5.3), and more launch-time values may
# join them, which would move both totals without changing what O-23 claims.
delta=$(( un - al ))
[ "$delta" = 3 ] || {
  echo "  FAIL  aligned form saved $delta slots for 3 pointers, expected 3"
  echo "        (unaligned $un, aligned $al)"; fail=1; }
[ "$un" -gt "$al" ] || { echo "  FAIL  aligned form is not cheaper"; fail=1; }
[ "$ro" = 0 ] || { echo "  FAIL  aligned kernel still loads an in-window offset"; fail=1; }

# The kernel must end up with NO parameters at all: they arrive in the launch
# block, so the signature should say so. Checking the signature rather than
# hunting for uses -- an earlier version of this test grepped for %0..%3 and
# produced false positives once stripping the parameters renumbered the
# instruction results into that range.
for f in un al; do
  if ! grep -qE '^define[^@]*@_Z4vadd[A-Za-z0-9_]*\(\)' "$TMP/$f.low.ll"; then
    sig=$(grep -oE '^define.*@_Z4vadd[^{]*' "$TMP/$f.low.ll" | head -1)
    echo "  FAIL  $f: kernel still takes parameters: $sig"; fail=1
  fi
done

if [ $fail -eq 0 ]; then
  echo "  PASS  kernel args lowered to launch block (unaligned $un slots, aligned $al: -$delta, one per pointer)"
  echo "  PASS  aligned pointers carry no in-window offset (O-23)"
fi
exit $fail
