#!/usr/bin/env bash
# Step 2 gate: kernels assemble, execute, and produce correct results.
set -uo pipefail
cd "$(dirname "$0")/.."

AS=tools/ccv-as.py
JSON=build/generated/CCV.json
SIM=build/ccv-sim
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0

if [ ! -x "$SIM" ] || [ ! -f "$JSON" ]; then
  echo "  build not present -- run cmake --build build"; exit 1
fi

# --- elementwise: c[i] = a[i] + b[i] --------------------------------------
# a[i] = 10i, b[i] = i+1, so c[i] = 11i + 1.
run_elementwise() {
  local n=$1 label=$2
  python3 "$AS" "$JSON" test/elementwise.s "$TMP/ew.bin" >/dev/null || return 1
  local args=(-poke 0x20000=32 -poke 0x20004=$n
              -poke 0x20008=5 -poke 0x2000c=3 -poke 0x20010=4)
  for i in $(seq 0 31); do
    args+=(-poke $((0x30000 + i*4))=$((i*10)) -poke $((0x40000 + i*4))=$((i+1)))
    args+=(-poke $((0x50000 + i*4))=4294967295)      # poison c[]
  done
  for i in $(seq 0 31); do args+=(-peek $((0x50000 + i*4))); done

  local out; out=$("$SIM" "$TMP/ew.bin" "${args[@]}" 2>&1) || { echo "$out"; return 1; }
  local bad=0
  for i in $(seq 0 31); do
    local got want
    got=$(echo "$out" | grep -oP "\[0x$(printf %x $((0x50000 + i*4)))\] = \K\d+")
    if [ "$i" -lt "$n" ]; then want=$((11*i + 1)); else want=4294967295; fi
    if [ "$got" != "$want" ]; then
      echo "    lane $i: got $got, want $want"; bad=1
    fi
  done
  if [ $bad -eq 0 ]; then
    echo "  PASS  $label ($(echo "$out" | grep -oP 'executed \K\d+') issue groups)"
  else
    echo "  FAIL  $label"; return 1
  fi
}

echo "  --- frontend and kernel ABI ---"
./tools/check-kernel-args.sh || fail=1

echo
echo "  --- functional simulator ---"
run_elementwise 32 "elementwise, all 32 lanes active"        || fail=1
# n < 32 makes lanes n..31 take the guard branch. They diverge from the rest and
# never rejoin -- there is no bracket and nothing forces reconvergence (§1).
run_elementwise 20 "elementwise, 20 of 32 lanes (divergence)" || fail=1
run_elementwise  1 "elementwise, 1 of 32 lanes (max divergence)" || fail=1

# --- O-24 addendum: por Pd, !Pd, Pd re-materialises from a MIXED mask -------
# The in-loop case. A second compare in a loop body faces a predicate already
# holding a partial mask; all 32 lanes must come back true.
run_remat() {
  python3 "$AS" "$JSON" test/predicate-remat.s "$TMP/rm.bin" >/dev/null || return 1
  local args=(-poke 0x20000=16)
  for i in $(seq 0 31); do args+=(-peek $((0x50000 + i*4))); done
  local out; out=$("$SIM" "$TMP/rm.bin" "${args[@]}" 2>&1) || { echo "$out"; return 1; }
  local bad=0
  for i in $(seq 0 31); do
    local got
    got=$(echo "$out" | grep -oP "\[0x$(printf %x $((0x50000 + i*4)))\] = \K\d+")
    [ "$got" = "99" ] || { echo "    lane $i: got $got, want 99"; bad=1; }
  done
  [ $bad -eq 0 ] && echo "  PASS  predicate re-materialisation from a mixed mask" \
                 || { echo "  FAIL  predicate re-materialisation"; return 1; }
}
echo
echo "  --- predicate idiom (O-24) ---"
run_remat || fail=1

# --- select lowers to a predicated move, not `sel` (F-58) ------------------
# `sel` (§4 point 19) writes all 32 lanes and spends the qualifier on the
# selector; a predicated `mov` writes only the guarded lanes (invariant 10) and
# gives the same answer for the conditional-overwrite shape, which is every
# select the compiler has ever generated here. The difference is 31 lane
# activations and it is invisible in results, so nothing else would catch a
# regression.
echo
echo "  --- select lowering ---"
sel_out=$(build/ccv-llc test/accept/select-predicated.ll -o - 2>/dev/null)
if echo "$sel_out" | grep -qw sel; then
  echo "  FAIL  select lowered to \`sel\`, which activates all 32 lanes"
  echo "$sel_out" | grep -w sel | sed 's/^/        /'
  fail=1
elif echo "$sel_out" | grep -q "@p[0-9] mov"; then
  echo "  PASS  select lowers to a predicated move ($(echo "$sel_out" | grep -c "@p[0-9] mov") of them)"
else
  echo "  FAIL  select produced neither \`sel\` nor a predicated move"
  fail=1
fi

# --- backend: what it accepts, and what it refuses LOUDLY ------------------
# Invariant 11 means no register holds an address, so the backend consumes
# address arithmetic before type legalization (F-20). That combine is a
# whitelist; anything outside it used to reach the legalizer and crash with
# SIGSEGV or a stack-smash abort and no diagnostic. These assert that every
# such case is a diagnostic (exit 1) instead -- a crash is indistinguishable
# from a compiler bug and tells the user nothing.
echo
echo "  --- backend accept / reject ---"
# An empty suite must not pass. Every one of these files was gitignored by a
# stray *.ll rule, so a fresh clone would have run zero cases and said nothing.
for d in test/accept test/reject; do
  n=$(find "$d" -name '*.ll' 2>/dev/null | wc -l)
  if [ "$n" -eq 0 ]; then
    echo "  FAIL  $d is empty -- the suite is missing, not passing"; fail=1
  fi
done
if [ -x build/ccv-llc ]; then
  for f in test/accept/*.ll; do
    if build/ccv-llc "$f" -o "$TMP/a.s" >/dev/null 2>&1; then
      echo "  PASS  accepts $(basename "$f")"
    else
      echo "  FAIL  rejects $(basename "$f") -- should compile"; fail=1
    fi
  done
  for f in test/reject/*.ll; do
    out=$(build/ccv-llc "$f" -o "$TMP/r.s" 2>&1); rc=$?
    if [ $rc -eq 1 ] && echo "$out" | grep -q "cannot be lowered"; then
      echo "  PASS  diagnoses $(basename "$f")"
    elif [ $rc -eq 0 ]; then
      echo "  FAIL  $(basename "$f") compiled -- should be rejected"; fail=1
    else
      echo "  FAIL  $(basename "$f") crashed (rc=$rc) instead of diagnosing"; fail=1
    fi
  done
else
  echo "  (ccv-llc not built; skipping)"
fi

# --- the whole pipeline: CUDA source -> executed result --------------------
echo
./tools/run-e2e.sh || fail=1

echo
./tools/run-reduce.sh || fail=1

# --- integer division: compiles AND computes -------------------------------
# Every primitive the expansion uses tested correct on its own; the kernel was
# still wrong. Only executing it finds that.
echo
echo "  --- integer division (expanded in IR) ---"
if [ -x build/ccv-llc ]; then
  if build/ccv-llc test/accept/integer-divide.ll -o "$TMP/dv.o" -obj 2>/dev/null &&
     llvm-objcopy -O binary --only-section=.text "$TMP/dv.o" "$TMP/dv.bin"; then
    dargs=(-poke 0x20020=3)
    for i in $(seq 0 15); do dargs+=(-peek $((0x30000 + i*4))); done
    dout=$("$SIM" "$TMP/dv.bin" "${dargs[@]}" 2>&1)
    dbad=0
    for i in $(seq 0 15); do
      got=$(echo "$dout" | grep -oP "\[0x$(printf %x $((0x30000 + i*4)))\] = \K\d+")
      want=$(( (i*7 + 13) / (i + 1) ))
      [ "$got" = "$want" ] || { echo "    lane $i: got $got, want $want"; dbad=1; }
    done
    [ $dbad -eq 0 ] && echo "  PASS  udiv by a runtime value, 16 lanes" \
                    || { echo "  FAIL  udiv results wrong"; fail=1; }
  else
    echo "  FAIL  integer-divide.ll did not compile"; fail=1
  fi
fi

# --- division exactness (F-48, O-31, O-35) ---------------------------------
echo
echo "  --- integer-reciprocal division ---"
./tools/check-div.sh 12 || fail=1

# The 16-bit figure in §4's `rcp.u32` contract is a measurement, and this is the
# measurement. It re-derives the minimum accuracy each candidate sequence needs,
# so nobody can quietly shorten the sequence past what the hardware promises.
python3 tools/model-rcp.py --samples 20000 || fail=1

# --- lane-0 masking (O-33) -------------------------------------------------
echo
echo "  --- warp-uniform lane-0 masking ---"
./tools/check-mask.sh || fail=1

# --- uniformity-report buckets (F-57) --------------------------------------
# The report is evidence for a spec change, so a bucket that names an encoding
# limit must contain only that limit. See the header of the script.
echo
echo "  --- uniformity report buckets ---"
./tools/check-uniformity-buckets.sh || fail=1

# --- branch relaxation (F-28) ---------------------------------------------
# Neither direction is visible in the .s: it prints `bra.short` whether or not
# the assembler grew it. So check the objects.
echo
echo "  --- branch relaxation ---"
if [ -x build/ccv-llc ]; then
  relax_ok=1
  ./tools/cuda-to-asm.sh test/cuda/reduce.cu "$TMP/rd.s" "$TMP/rd" >/dev/null 2>&1 &&
    build/ccv-llc "$TMP/rd-lowered.ll" -o "$TMP/rd.o" -obj &&
    llvm-objcopy -O binary --only-section=.text "$TMP/rd.o" "$TMP/short.bin" || relax_ok=0
  build/ccv-llc test/accept/branch-relax.ll -o "$TMP/rx.o" -obj &&
    llvm-objcopy -O binary --only-section=.text "$TMP/rx.o" "$TMP/relaxed.bin" || relax_ok=0
  if [ $relax_ok -eq 1 ]; then
    python3 tools/check-relaxation.py "$JSON" "$TMP/short.bin" "$TMP/relaxed.bin" || fail=1
  else
    echo "  FAIL  could not build the relaxation inputs"; fail=1
  fi
fi

# --- assembler / encoder cross-check --------------------------------------
# ccv-as.py encodes from the TableGen JSON; the C++ MCCodeEmitter encodes from
# gen-emitter. Two independent paths over one description (roadmap F-6).
echo
echo "  --- assembler vs generated encoder ---"
python3 "$AS" "$JSON" test/smoke.s "$TMP/smoke.bin" >/dev/null
if python3 tools/check-assembler.py "$JSON" test/smoke.s "$TMP/smoke.bin"; then
  echo "  PASS  independent encoders agree"
else
  echo "  FAIL  encoder disagreement"; fail=1
fi

echo
[ $fail -eq 0 ] && echo "  all simulator tests pass" || echo "  SIMULATOR TESTS FAILED"
exit $fail
