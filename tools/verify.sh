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

echo "  worked-listing arithmetic"
python3 tools/check-listings.py docs/isa-v1.5-operation-map-and-encoding.md || fail=1

# Spec listing against real codegen. check-listings.py only proves the spec is
# internally consistent; it cannot notice the listing drifting from the machine,
# which is how an extra branch and a pessimistic register count both survived.
# Spec listings against real codegen, regenerated here rather than read from the
# tree: the .s files are gitignored, so reading them would make this check skip
# silently on a fresh clone.
SPEC=docs/isa-v1.5-operation-map-and-encoding.md
if [ -x build/ccg-llc ] && [ -f build/CCGLowerKernelArgs.so ]; then
  for pair in "5.5:test/cuda/vadd.cu" "5.6:test/cuda/vadd-aligned.cu"; do
    sec=${pair%%:*}; src=${pair#*:}
    echo "  §$sec listing vs codegen"
    if ./tools/cuda-to-asm.sh "$src" "$OUT/$sec.s"; then
      python3 tools/check-spec-vs-codegen.py "$SPEC" "$sec" "$OUT/$sec.s" || fail=1
    else
      echo "      could not compile $src"; fail=1
    fi
  done
else
  echo "  (build/ccg-llc or the kernel-arg plugin not built -- skipping listing provenance)"
fi

# Round trip, if the MC layer has been built. The encoder and the disassembler
# come from different TableGen backends, so a disagreement means the encoding is
# ambiguous or the tables are inconsistent -- not visible from reading §3.
if [ -x build/ccg-roundtrip ]; then
  echo "  encode -> decode round trip"
  ./build/ccg-roundtrip || fail=1
else
  echo "  (build/ccg-roundtrip not built -- see llvm/CCG/README.md; skipping round trip)"
fi

if [ -x build/ccg-sim ]; then
  echo
  ./tools/run-tests.sh || fail=1
fi

echo
if [ $fail -eq 0 ]; then
  echo "  ================  VERIFY: PASS  ================"
else
  echo "  ================  VERIFY: FAIL  ================"
fi
exit $fail
