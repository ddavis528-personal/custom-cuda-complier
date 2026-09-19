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
python3 tools/check-listings.py docs/isa-v1.6-operation-map-and-encoding.md || fail=1

# Spec listing against real codegen. check-listings.py only proves the spec is
# internally consistent; it cannot notice the listing drifting from the machine,
# which is how an extra branch and a pessimistic register count both survived.
# Spec listings against real codegen, regenerated here rather than read from the
# tree: the .s files are gitignored, so reading them would make this check skip
# silently on a fresh clone.
SPEC=docs/isa-v1.6-operation-map-and-encoding.md
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

# O-45 made the launch-block ABI a fourth-copy problem: the AGU model in the
# simulator needs the base and the argument offset that CCVLowerKernelArgs owns,
# and the ISel matcher needs them again. A constant that disagrees with itself
# produces a kernel reading the wrong argument, which looks like nothing.
echo "  launch-block ABI constants agree"
./tools/check-launch-abi.sh || fail=1

# O-44's FP packed dot products cannot be reached from CUDA -- the backend has
# no bfloat, half or FP8 type -- so nothing would notice if their semantics were
# wrong. §4 makes the rounding rule normative; this executes it against a
# reference computed in exact rationals.
if [ -x build/ccv-sim ]; then
  echo "  FP packed dot product, exact-sum reference"
  ./tools/check-dp-fp.sh || fail=1
fi

# F-134: sgemm had never been executed. Every check it passed -- instruction
# counts, spill counts, the tile sweep, the register-pressure argument the GPR
# decision rests on -- was a check on its text, and the first time it ran it
# hung. It is the most complex kernel here and the one most of the architecture
# conclusions lean on, so it executes in the gate now.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  sgemm executes and computes a matrix product"
  ./tools/check-sgemm.sh || fail=1
fi

# F-131 gave local arrays a lowering path through Format D base+index off the
# frame pointer. The two addressing forms it selects -- constant index and
# dynamic index -- are each plausible whatever the frame offset and the
# scale-enable bit happen to be, so the check reads back through one what the
# same kernel wrote through the other.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  local array addressed two ways"
  ./tools/check-local-array.sh || fail=1
fi

# F-147: a by-value parameter struct was classified as a pointer, so the kernel
# read every field from whatever window the struct's first four bytes named. It
# compiled, assembled and round-tripped. Only execution sees that, and only with
# field values that would name a real window if they were misread as one.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  by-value struct argument reads the launch block"
  ./tools/check-byval.sh || fail=1
fi

# F-143's fused-kernel corpus executes. F-134's lesson applies with full force
# here: a corpus assembled to settle an architectural question has to be one
# whose kernels are known to work, or the question is being settled from the
# compiler's opinion of itself. This is also the regression test for F-145 --
# `rope` ran forever before the co-issue condition was added to O-33's masking.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  the fused corpus executes and computes the right numbers"
  python3 tools/check-fusion.py || fail=1
fi

# F-141 made the SFU group reachable from CUDA through the intrinsics a kernel
# actually uses. Five patterns into one instruction family is where two entries
# get crossed, and a crossed entry compiles, encodes, disassembles and round
# trips perfectly. This also stands as the regression test for F-142: the kernel
# writes `o[i*5+k]`, which is the constant-displacement shape that used to
# segfault the compiler.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  each SFU intrinsic computes its own function"
  ./tools/check-sfu.sh || fail=1
fi

# F-121 formed the four-byte dot product in a DAG combine, which is the
# compiler asserting that a tree of shifts, sign-extends, multiplies and adds
# means `dp4`. A combine that picks the wrong byte or drops the accumulator
# emits a perfectly valid instruction computing the wrong number, and no
# encoding check can see that.
if [ -x build/ccv-llc ] && [ -x build/ccv-sim ]; then
  echo "  dp4 against a four-MAC reference"
  ./tools/check-dp4.sh || fail=1
fi

# F-111: every instruction the description defines must be producible. The
# encoding checks above prove the bits are decodable and that the assembler and
# the disassembler agree -- both properties of the ENCODING. Whether the
# COMPILER can ever emit it had no check, and three reviews in a row found an
# encoding that nothing selected.
echo "  every instruction has a production path"
python3 tools/check-unselected.py || fail=1

# And the gate has to catch the bugs it was written for, so remove each
# production path in turn and require the failure.
echo "  the production-path gate catches its own cases"
./tools/check-unselected-mutation.sh || fail=1

# Documentation structure: paths that resolve, findings and decisions that are
# defined where they are cited, no finding tracked twice. Prose staleness is not
# computable; this is the half that is.
echo "  documentation structure"
python3 tools/check-docs.py || fail=1

# Cross-table consistency inside the spec: the summary tables must agree with the
# bit maps they summarize, and the prose counts must agree with the tables above
# them. An external review found Format F given two immediate widths, stale since
# 1.2 in a table nothing downstream read. Prose review missed that class three
# times; it is mechanical, so it stops being the reviewer's job.
echo "  spec cross-table consistency"
python3 tools/check-spec-tables.py || fail=1

# The walkthrough regenerates its listings and says "nothing here is
# transcribed". The prose beside them is not regenerated, and it drifted three
# instructions behind the compiler before anything noticed.
echo "  walkthrough prose vs its own listings"
python3 tools/check-walkthrough.py || fail=1

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
