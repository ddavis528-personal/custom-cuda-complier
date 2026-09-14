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
TD=llvm/CCV/CCV.td
OUT=$(mktemp -d); trap 'rm -rf "$OUT"' EXIT

fail=0
for g in gen-register-info gen-instr-info gen-emitter gen-disassembler \
         gen-asm-writer gen-dag-isel gen-callingconv; do
  printf '  %-20s ' "$g"
  if llvm-tblgen -I "$INC" -I llvm/CCV --$g "$TD" -o "$OUT/$g.inc" 2>"$OUT/$g.err"; then
    printf 'ok (%s lines)\n' "$(wc -l < "$OUT/$g.inc")"
  else
    printf 'FAIL\n'; sed 's/^/      /' "$OUT/$g.err" | head -8; fail=1
  fi
done

echo
llvm-tblgen -I "$INC" -I llvm/CCV --dump-json "$TD" -o "$OUT/ccv.json" 2>/dev/null
python3 tools/check-encoding.py "$OUT/ccv.json" || fail=1

echo "  worked-listing arithmetic"
python3 tools/check-listings.py docs/isa-v1.5-operation-map-and-encoding.md || fail=1

# Spec listing against real codegen. check-listings.py only proves the spec is
# internally consistent; it cannot notice the listing drifting from the machine,
# which is how an extra branch and a pessimistic register count both survived.
# Spec listings against real codegen, regenerated here rather than read from the
# tree: the .s files are gitignored, so reading them would make this check skip
# silently on a fresh clone.
SPEC=docs/isa-v1.5-operation-map-and-encoding.md
if [ -x build/ccv-llc ] && [ -f build/CCVLowerKernelArgs.so ]; then
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
  echo "  (build/ccv-llc or the kernel-arg plugin not built -- skipping listing provenance)"
fi

# Documentation structure: paths that resolve, findings and decisions that are
# defined where they are cited, no finding tracked twice. Prose staleness is not
# computable; this is the half that is.
echo "  documentation structure"
python3 tools/check-docs.py || fail=1

# docs/walkthrough.md is assembled from generated artifacts and claims "nothing
# here is transcribed". Regenerate it and require the tree copy to match, so the
# claim is checked rather than trusted.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  walkthrough document vs toolchain"
  cp docs/walkthrough.md "$OUT/walkthrough.before"
  if ./tools/make-walkthrough.sh >/dev/null 2>&1 \
     && python3 tools/gen-walkthrough-doc.py >/dev/null 2>&1; then
    if diff -q "$OUT/walkthrough.before" docs/walkthrough.md >/dev/null; then
      echo "  PASS  docs/walkthrough.md matches the toolchain"
    else
      echo "  FAIL  docs/walkthrough.md is stale -- regenerated copy differs"
      diff "$OUT/walkthrough.before" docs/walkthrough.md | head -20
      fail=1
    fi
  else
    echo "  FAIL  could not regenerate the walkthrough"; fail=1
  fi
fi

# docs/benchmarks.md carries measured tables. Regenerate and compare, for the
# same reason the spec listings are regenerated: a hand-copied number is only
# as current as whoever last remembered to copy it, and four of them were not.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  benchmark document vs tools"
  python3 tools/check-bench-doc.py || fail=1
fi

# Round trip, if the MC layer has been built. The encoder and the disassembler
# come from different TableGen backends, so a disagreement means the encoding is
# ambiguous or the tables are inconsistent -- not visible from reading §3.
if [ -x build/ccv-roundtrip ]; then
  echo "  encode -> decode round trip"
  ./build/ccv-roundtrip || fail=1
else
  echo "  (build/ccv-roundtrip not built -- see llvm/CCV/README.md; skipping round trip)"
fi

if [ -x build/ccv-sim ]; then
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
