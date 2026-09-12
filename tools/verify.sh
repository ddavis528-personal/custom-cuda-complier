#!/usr/bin/env bash
# Step 1 gate: the machine description must generate cleanly through every
# TableGen backend, and must satisfy the encoding invariants in
# docs/isa-v1.3-operation-map-and-encoding.md §7.
#
# The disassembler generator is the load-bearing one: it fails if the encoding
# is not uniquely decodable, which is a property no amount of reading the bit
# maps will establish.
set -euo pipefail
cd "$(dirname "$0")/.."

INC=${LLVM_INCLUDEDIR:-$(llvm-config --includedir)}
TD=llvm/CCG/CCG.td
OUT=$(mktemp -d); trap 'rm -rf "$OUT"' EXIT

fail=0
for g in gen-register-info gen-instr-info gen-emitter gen-disassembler gen-asm-writer; do
  printf '  %-20s ' "$g"
  if llvm-tblgen -I "$INC" -I llvm/CCG --$g "$TD" -o "$OUT/$g.inc" 2>"$OUT/$g.err"; then
    printf 'ok (%s lines)\n' "$(wc -l < "$OUT/$g.inc")"
  else
    printf 'FAIL\n'; sed 's/^/      /' "$OUT/$g.err" | head -8; fail=1
  fi
done

echo
llvm-tblgen -I "$INC" -I llvm/CCG --dump-json "$TD" -o "$OUT/ccg.json" 2>/dev/null
python3 tools/check-encoding.py "$OUT/ccg.json" || fail=1

# Round trip, if the MC layer has been built. The encoder and the disassembler
# come from different TableGen backends, so a disagreement means the encoding is
# ambiguous or the tables are inconsistent -- not visible from reading §3.
if [ -x build/ccg-roundtrip ]; then
  echo "  encode -> decode round trip"
  ./build/ccg-roundtrip || fail=1
else
  echo "  (build/ccg-roundtrip not built -- see llvm/CCG/README.md; skipping round trip)"
fi

exit $fail
