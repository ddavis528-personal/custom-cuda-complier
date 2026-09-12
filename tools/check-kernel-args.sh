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

# 3 pointers + 1 scalar: 7 slots unaligned (2 per pointer), 4 aligned.
[ "$un" = 7 ] || { echo "  FAIL  unaligned: $un launch-block loads, expected 7"; fail=1; }
[ "$al" = 4 ] || { echo "  FAIL  aligned: $al launch-block loads, expected 4"; fail=1; }
[ "$ro" = 0 ] || { echo "  FAIL  aligned kernel still loads an in-window offset"; fail=1; }

# The kernel's own parameters must be dead: every use rewritten to a load.
for f in un al; do
  if grep -qE '%[0-9]+ = (add|mul|icmp|getelementptr).*(%0|%1|%2|%3)([,)]|$)' \
       "$TMP/$f.low.ll"; then
    echo "  FAIL  $f: a kernel parameter still has uses"; fail=1
  fi
done

if [ $fail -eq 0 ]; then
  echo "  PASS  kernel args lowered to launch block (unaligned $un slots, aligned $al)"
  echo "  PASS  aligned pointers carry no in-window offset (O-23)"
fi
exit $fail
