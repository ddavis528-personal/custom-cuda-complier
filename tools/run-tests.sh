#!/usr/bin/env bash
# Step 2 gate: kernels assemble, execute, and produce correct results.
set -uo pipefail
cd "$(dirname "$0")/.."

AS=tools/ccg-as.py
JSON=build/generated/CCG.json
SIM=build/ccg-sim
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
if [ -x build/ccg-llc ]; then
  for f in test/accept/*.ll; do
    if build/ccg-llc "$f" -o "$TMP/a.s" >/dev/null 2>&1; then
      echo "  PASS  accepts $(basename "$f")"
    else
      echo "  FAIL  rejects $(basename "$f") -- should compile"; fail=1
    fi
  done
  for f in test/reject/*.ll; do
    out=$(build/ccg-llc "$f" -o "$TMP/r.s" 2>&1); rc=$?
    if [ $rc -eq 1 ] && echo "$out" | grep -q "cannot be lowered"; then
      echo "  PASS  diagnoses $(basename "$f")"
    elif [ $rc -eq 0 ]; then
      echo "  FAIL  $(basename "$f") compiled -- should be rejected"; fail=1
    else
      echo "  FAIL  $(basename "$f") crashed (rc=$rc) instead of diagnosing"; fail=1
    fi
  done
else
  echo "  (ccg-llc not built; skipping)"
fi

# --- the whole pipeline: CUDA source -> executed result --------------------
echo
./tools/run-e2e.sh || fail=1

echo
./tools/run-reduce.sh || fail=1

# --- assembler / encoder cross-check --------------------------------------
# ccg-as.py encodes from the TableGen JSON; the C++ MCCodeEmitter encodes from
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
