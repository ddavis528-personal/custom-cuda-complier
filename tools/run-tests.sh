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

# --- per-register element width (F-3) --------------------------------------
# Written in assembly because the backend cannot yet produce narrow-width code;
# this pins the SEMANTICS the chwidth-insertion pass will be built against.
run_chwidth() {
  local tmp; tmp=$(mktemp -d); trap 'rm -rf "$tmp"' RETURN
  python3 tools/ccv-as.py build/generated/CCV.json test/chwidth.s "$tmp/c.bin" \
    >/dev/null 2>&1 || { echo "  FAIL  chwidth.s did not assemble"; return 1; }
  local out
  out=$(build/ccv-sim "$tmp/c.bin" -poke 0x30000=0x0003BEEF \
        -peek 0x30010 -peek 0x30020 -peek 0x30030 2>&1)
  local narrow wide shared
  narrow=$(echo "$out" | sed -n 's/.*\[0x30010\] = \([0-9]*\).*/\1/p')
  wide=$(echo   "$out" | sed -n 's/.*\[0x30020\] = \([0-9]*\).*/\1/p')
  shared=$(echo "$out" | sed -n 's/.*\[0x30030\] = \([0-9]*\).*/\1/p')
  # 0xBEEF + 3 = 0xBEF2, wrapped at 16 bits and stored as two bytes.
  if [ "$narrow" != "48882" ]; then
    echo "  FAIL  16-bit add/store gave $narrow, want 48882 (0xBEF2)"; return 1
  fi
  echo "  PASS  16-bit load, add and store (transfer size follows chwidth)"
  # R2 held 0xEFBEADC9 before being narrowed. Widening must clear the exposed
  # bits: anything but 0x0000BEF2 here means the machine hands back whatever
  # last occupied that slice of the register file -- another warp's data, or
  # the previous kernel's. This is the security property, not a nicety (O-38).
  if [ "$wide" != "48882" ]; then
    echo "  FAIL  widened register read $wide, want 48882 (0x0000BEF2)."
    if [ "$wide" = "4023238386" ]; then
      echo "        Got 0xEFBEBEF2 -- the stale top half survived the width"
      echo "        change. That is a cross-context register-file leak (O-38)."
    fi
    return 1
  fi
  echo "  PASS  widening clears the exposed bits -- no stale data (O-38)"
  # A 16-bit .shared store into zeroed memory must leave the next halfword
  # alone. §3 takes transfer size from rdata's chwidth in .shared exactly as in
  # .global; these two were on the simulator's width-aware list while still
  # calling read32/write32, which the list vouched for and nothing checked.
  if [ "$shared" != "43981" ]; then
    echo "  FAIL  16-bit .shared store read back as $shared, want 43981 (0x0000ABCD)"
    echo "        A larger value means the store wrote more than two bytes."
    return 1
  fi
  echo "  PASS  16-bit .shared store writes two bytes, not four"
}
echo
echo "  --- per-register element width ---"
run_chwidth || fail=1

# --- call and ret (F-21) ----------------------------------------------------
# Hand-written, because the backend cannot emit a call yet: this pins the
# semantics LowerCall is built against. Every lane is checked, and each
# control mutates one thing the semantics depend on and must change an answer.
call_results() {   # $1 = binary; prints "direct nested indirect link" per lane
  local args=(); for i in $(seq 0 31); do for w in 5 6 7 8; do
    args+=(-peek $((w * 0x10000 + i*4))); done; done
  "$SIM" "$@" "${args[@]}" 2>&1
}
run_call() {
  python3 "$AS" "$JSON" test/call.s "$TMP/call.bin" >/dev/null || return 1
  local out; out=$(call_results "$TMP/call.bin") ||
    { echo "$out"; echo "  FAIL  call.s did not run to completion"; return 1; }
  local bad=0 i got want
  for i in $(seq 0 31); do
    for pair in "5:$((3*i + 1))" "6:$((3*i + 101))" \
                "7:$(( i % 2 ? i + 7 : 3*i + 1 ))" "8:$((0x1000 + 8))"; do
      local w=${pair%%:*}; want=${pair#*:}
      got=$(echo "$out" | grep -oP "\[0x$(printf %x $((w * 0x10000 + i*4)))\] = \K\d+")
      [ "$got" = "$want" ] || { echo "    lane $i window $w: got $got, want $want"; bad=1; }
    done
  done
  [ $bad -eq 0 ] || { echo "  FAIL  call and ret"; return 1; }
  echo "  PASS  call/ret: value return, two link registers nested, divergent indirect"
  echo "        return, link = byte address of the next instruction (32 lanes)"
  # Controls: outer returning through R14 (its callee's link, not its own);
  # the indirect stub returning through R6 rather than the target register;
  # a callee that never returns its value. Each must fail.
  local c ok=1
  for c in 's/C_RET      208 /C_RET      224 /' 's/^stub:   C_RET      80/stub:   C_RET      96/' \
           's/^        ADDI       R1, R1, 100/        ADDI       R4, R1, 100/'; do
    sed "$c" test/call.s > "$TMP/callm.s"
    cmp -s test/call.s "$TMP/callm.s" && { echo "  FAIL  control '$c' did not apply"; ok=0; continue; }
    python3 "$AS" "$JSON" "$TMP/callm.s" "$TMP/callm.bin" >/dev/null 2>&1 || continue
    if [ "$(call_results "$TMP/callm.bin")" = "$out" ]; then
      echo "  FAIL  control '$c' left every answer unchanged"; ok=0
    fi
  done
  [ $ok -eq 1 ] && echo "  PASS  three mutated call sequences each change an answer" || return 1
  # §3 (v1.8, 3013036): ret is {PC[47:32], rs}, a concatenation under its own
  # 4 GiB window. Loaded above 4 GiB, a zero-extending ret leaves the image.
  local hi; hi=$(call_results "$TMP/call.bin" -code-base 0x100001000) ||
    { echo "$hi"; echo "  FAIL  call.s loaded at 0x1_0000_1000 did not run"; return 1; }
  [ "$hi" = "$out" ] && echo "  PASS  the same answers loaded at 0x1_0000_1000: ret keeps its 4 GiB window" \
                     || { echo "  FAIL  call.s gives different answers loaded above 4 GiB"; return 1; }
}
# --- ld.pred / st.pred (IS-15) -----------------------------------------------
# The backend spills predicates through these, and until IS-15 the simulator
# could not execute them. Positional frame, whole-warp words, lane 0's base.
run_pred_spill() {
  python3 "$AS" "$JSON" test/pred-spill.s "$TMP/ps.bin" >/dev/null || return 1
  local out; out=$("$SIM" "$TMP/ps.bin" -peek 0x90040 -peek 0x90044 -peek 0x90048 \
                   -peek 0x90020 -peek 0x90038 -peek 0x90030 2>&1) ||
    { echo "$out"; echo "  FAIL  pred-spill.s did not run"; return 1; }
  local bad=0 pair a want got
  for pair in 90040:255 90044:65535 90048:16777215 90020:65535 \
              90038:4294967295 90030:65535; do
    a=${pair%%:*}; want=${pair#*:}
    got=$(echo "$out" | grep -oP "\[0x$a\] = \K\d+")
    [ "$got" = "$want" ] || { echo "    [0x$a]: got $got, want $want"; bad=1; }
  done
  [ $bad -eq 0 ] && echo "  PASS  ld.pred/st.pred: positional frame, whole-warp words, a clobbered predicate restored" \
                 || { echo "  FAIL  ld.pred/st.pred"; return 1; }
  # O-62, O-63: a diverged group's reload and store leave the other group's
  # lanes alone, in the register and in the word.
  python3 "$AS" "$JSON" test/pred-merge.s "$TMP/pm.bin" >/dev/null || return 1
  out=$("$SIM" "$TMP/pm.bin" -peek 0x90040 -peek 0x90050 2>&1) ||
    { echo "$out"; echo "  FAIL  pred-merge.s did not run"; return 1; }
  local r=$(echo "$out" | grep -oP "\[0x90040\] = \K\d+") w=$(echo "$out" | grep -oP "\[0x90050\] = \K\d+")
  [ "$r $w" = "4294901760 0" ] && echo "  PASS  ld.pred and st.pred move only the issuing group's lanes (O-62, O-63)" \
                               || { echo "  FAIL  predicate transfers under divergence: got $r $w, want 4294901760 0"; return 1; }
}
echo
echo "  --- predicate spill (IS-15) ---"
run_pred_spill || fail=1

# --- one warp of a CTA of several (TI-29) ----------------------------------
run_warp() {
  python3 "$AS" "$JSON" test/warp.s "$TMP/w.bin" >/dev/null || return 1
  local args="-threads 52 -poke 0x300d0=7 -peek 0x3007c -peek 0x30080 -peek 0x300cc -peek 0x300d0"
  local out ctl want="0 32 51 7"
  out=$("$SIM" "$TMP/w.bin" $args -warp 1 -oracle "$TMP/w.jsonl" 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # The control: warp 0 of the same CTA stores threads 0-31, not 32-51.
  ctl=$("$SIM" "$TMP/w.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  local bar; bar=$(python3 "$AS" "$JSON" test/faults/barrier.s "$TMP/b.bin" >/dev/null &&
                   "$SIM" "$TMP/b.bin" -threads 52 2>&1)
  if [ "${out% }" = "$want" ] && [ "${ctl% }" != "$want" ] &&
     grep -q '"warp_in_cta":1,' "$TMP/w.jsonl" && grep -q "barrier in a CTA of 52" <<< "$bar"; then
    echo "  PASS  -warp 1 of a 52-thread CTA: threads 32-51 on lanes 0-19, warp_in_cta in the record, a barrier refused"
  else
    echo "  FAIL  -warp: got '$out' (warp 0: '$ctl'), want '$want'; barrier: $bar"; return 1
  fi
}
# --- O-69's interleaved spill space --------------------------------------------
run_local() {
  python3 "$AS" "$JSON" test/local.s "$TMP/lo.bin" >/dev/null || return 1
  # The addresses below are at CCV_LANE_CONTEXTS 1,024, one core's contexts.
  local args="-lane-contexts 1024 -poke 0x20018=256 -context 2 -peek 0x90000 -peek 0x9007c -peek 0x5800100
              -peek 0x580017c -peek 0x5800084 -peek 0x58000fc -peek 0x5800280
              -peek 0x90080 -peek 0x900bc -peek 0x900c0"
  local want="101 132 100 131 3203334144 3203334144 65535 7 7 0" got ctl
  got=$("$SIM" "$TMP/lo.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # The control: CCV_LANE_CONTEXTS 0 moves the frame, so the cells are empty.
  ctl=$("$SIM" "$TMP/lo.bin" $args -lane-contexts 0 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  if [ "${got% }" = "$want" ] && [ "${ctl% }" != "$want" ]; then
    echo "  PASS  ld.local/st.local and the .pred forms at O-69's interleaved addresses, a narrow store included"
  else
    echo "  FAIL  local: got '$got', want '$want' (control: '$ctl')"; return 1
  fi
}
# --- frame objects are disjoint (F-179) --------------------------------------
# A predicate's spill size was i1's one bit, zero bytes, so every predicate
# spill slot sat at one offset and a spilled predicate was overwritten by the
# next. The invariant, over every accepted kernel: no frame object is empty and
# no two overlap. The control is the checker on a frame that breaks it.
frames_disjoint() {   # stdin: -ccv-frame-stats output
  python3 -c '
import re, sys
objs = {}
for l in sys.stdin:
    m = re.match(r"\s*frame-object (\S+) \S+ (-?\d+) (-?\d+)", l)
    if m:
        objs.setdefault(m[1], []).append((int(m[2]), int(m[3])))
    m = re.match(r"\s*local-slot (\S+) (\d+) (\d+)", l)    # O-69
    if m:
        objs.setdefault("local " + m[1], []).append((int(m[2]), int(m[3])))
bad = [f"{f}: [{a},{b})" for f, o in objs.items() for a, b in o if b <= a]
for f, o in objs.items():
    o.sort()
    bad += [f"{f}: [{a},{b}) meets [{c},{d})" for (a, b), (c, d) in zip(o, o[1:]) if c < b]
print("\n".join(bad)); sys.exit(1 if bad else 0)'
}
run_frames() {
  local f all="" n=0
  for f in test/accept/*.ll; do
    all+=$(build/ccv-llc "$f" -o /dev/null -ccv-frame-stats 2>&1 | sed "s|frame-object |frame-object $(basename "$f"):|; s|local-slot |local-slot $(basename "$f"):|")$'\n'
  done
  n=$(grep -c "frame-object\|local-slot" <<< "$all")
  local np; np=$(build/ccv-llc test/accept/fdiv-all.ll -o - 2>/dev/null | grep -c "st.pred")
  if ! out=$(frames_disjoint <<< "$all"); then
    echo "  FAIL  frame objects overlap or are empty:"; echo "$out" | head -5; return 1
  fi
  if frames_disjoint <<< $'  frame-object k spill -4 0\n  frame-object k spill -4 0' >/dev/null; then
    echo "  FAIL  control: two objects at one offset were not caught"; return 1
  fi
  if [ "$np" -lt 2 ]; then
    echo "  FAIL  fdiv-all.ll spills $np predicates; the check needs two in memory at once"; return 1
  fi
  echo "  PASS  $n frame objects across test/accept are non-empty and disjoint ($np predicate spills in fdiv-all), and an overlap is caught"
}
# --- canonical NaN and the compare format bit (O-66, O-65) ------------------
run_fp_canon() {
  python3 "$AS" "$JSON" test/fp-canon.s "$TMP/fc.bin" >/dev/null || return 1
  local args="-peek 0x90000 -peek 0x90004 -peek 0x90008" want="2147483647 32767 6" got nan f0 ff
  got=$("$SIM" "$TMP/fc.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # Controls: the host's FP32 NaN; the format bit ignored (setp.eq.f for .f1);
  # and a format-1 compare at 32 bits, which is F-FORMAT.
  nan=$("$SIM" "$TMP/fc.bin" $args -ccv-test-fp-host-nan 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  sed 's/SETP_EQ_F1_NP/SETP_EQ_F_NP /' test/fp-canon.s > "$TMP/fc0.s"
  python3 "$AS" "$JSON" "$TMP/fc0.s" "$TMP/fc0.bin" >/dev/null || return 1
  f0=$("$SIM" "$TMP/fc0.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  sed '/C_CHWIDTH  R4, 2/d' test/fp-canon.s > "$TMP/fcw.s"
  python3 "$AS" "$JSON" "$TMP/fcw.s" "$TMP/fcw.bin" >/dev/null || return 1
  ff=$("$SIM" "$TMP/fcw.bin" 2>&1)
  if [ "${got% }" = "$want" ] && [ "${nan% }" != "$want" ] && [ "${f0% }" != "$want" ] &&
     grep -q "F-FORMAT" <<< "$ff"; then
    echo "  PASS  canonical NaN at FP32 and FP16 (O-66), the compare's format bit (O-65), F-FORMAT at 32 bits"
  else
    echo "  FAIL  fp-canon: got '$got', want '$want' (host NaN: '$nan', bit ignored: '$f0'); 32-bit .f1: $ff"; return 1
  fi
}
# --- Format M atomics (O-72) ---------------------------------------------------
run_atomics() {
  python3 "$AS" "$JSON" test/atomics.s "$TMP/at.bin" >/dev/null || return 1
  local args="-poke 0x90004=4294967196 -poke 0x90008=1000 -poke 0x9000c=90 -poke 0xa0000=7
              -peek 0x90000 -peek 0x90004 -peek 0x90008 -peek 0x9000c -peek 0x8007c -peek 0xa007c
              -peek 0xc007c -peek 0xc0000 -peek 0xb0000 -peek 0xb0004 -peek 0xb0100"
  local want="32 15 5 90 31 93 0 7 1 0 4294967295" got ctl
  got=$("$SIM" "$TMP/at.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # The control: the index register ignored, as before O-72.
  ctl=$("$SIM" "$TMP/at.bin" $args -ccv-test-atomic-no-index 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  if [ "${got% }" = "$want" ] && [ "${ctl% }" != "$want" ]; then
    echo "  PASS  atomics: add, max.s, min.u, xor and exch on .global, CAS and or on .shared, at base + index addresses (O-72)"
  else
    echo "  FAIL  atomics: got '$got', want '$want' (no index: '$ctl')"; return 1
  fi
}
# --- atom.add.f32 (O-76) -----------------------------------------------------
run_atomics_fadd() {
  python3 "$AS" "$JSON" test/atomics-fadd.s "$TMP/af.bin" >/dev/null || return 1
  local args="-poke 0xc0000=1266679808" l got ctl
  for l in $(seq 1 31); do args+=" -poke $(printf 0x%x $((0xc0000 + 4 * l)))=1065353216"; done
  args+=" -peek 0xd0000 -peek 0xd0004 -peek 0xe0000 -peek 0xe0004 -peek 0xe007c"
  local want="1266679808 1266679808 0 1266679808 1266679808"
  got=$("$SIM" "$TMP/af.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # The control: the lanes in descending order, whose sum rounds differently.
  ctl=$("$SIM" "$TMP/af.bin" $args -ccv-test-atomic-fadd-descending 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  if [ "${got% }" = "$want" ] && [ "${ctl% }" != "$want" ]; then
    echo "  PASS  atom.add.f32 on .global and .shared: lanes in ascending order, each add rounded, each lane's old value (O-76)"
  else
    echo "  FAIL  atom.add.f32: got '$got', want '$want' (descending: '$ctl')"; return 1
  fi
}
# --- the FP SFU's values (O-70) --------------------------------------------
run_sfu() {
  python3 "$AS" "$JSON" test/sfu.s "$TMP/sfu.bin" >/dev/null || return 1
  local args="" i got trunc moved
  for i in $(seq 0 11); do args+=" -peek $(printf 0x%x $((0x90000 + 4 * i)))"; done
  local want="1051372203 1058262330 1068827891 1068827891 362 1070260237 876128826 1041269187 3015425326 3209333168 3212836864 1065353216"
  got=$("$SIM" "$TMP/sfu.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # Controls: truncation instead of rounding; and -sfu-error-ulps must move
  # some of them (check-sfu-math holds the moved values to O-70's bound).
  trunc=$("$SIM" "$TMP/sfu.bin" $args -ccv-test-sfu-truncate 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  moved=$("$SIM" "$TMP/sfu.bin" $args -sfu-error-ulps 2 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  if [ "${got% }" = "$want" ] && [ "${trunc% }" != "$want" ] && [ "${moved% }" != "$want" ]; then
    echo "  PASS  rcp, rsqrt, sqrt, ex2, lg2, sin and cos executed, correctly rounded (O-70), a subnormal and sin(1e30) included"
  else
    echo "  FAIL  sfu: got '$got', want '$want' (truncated: '$trunc', -sfu-error-ulps 2: '$moved')"; return 1
  fi
}
# --- the mixed-width rule (O-67) --------------------------------------------
run_mixed_width() {
  python3 "$AS" "$JSON" test/mixed-width.s "$TMP/mw.bin" >/dev/null || return 1
  local args="-peek 0x90000 -peek 0x90004 -peek 0x90008" want="564 5 15360" got ctl
  got=$("$SIM" "$TMP/mw.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # The control: integer sources read by value, at their own width.
  ctl=$("$SIM" "$TMP/mw.bin" $args -ccv-test-mixed-by-value 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  if [ "${got% }" = "$want" ] && [ "${ctl% }" != "$want" ]; then
    echo "  PASS  mixed widths read as raw fields at the operating width: shr, min.s, an FP16 add (O-67)"
  else
    echo "  FAIL  mixed-width: got '$got', want '$want' (by value: '$ctl')"; return 1
  fi
}
# --- a narrow address register (O-79) ---------------------------------------
run_addr_narrow() {
  python3 "$AS" "$JSON" test/addr-narrow.s "$TMP/an.bin" >/dev/null || return 1
  local args="-poke 0x80004=17 -poke 0x80704=34 -peek 0x90000" got ctl
  got=$("$SIM" "$TMP/an.bin" $args 2>&1 | grep -oP '\] = \K\d+')
  # The control: the index read at all 32 bits, as O-39 had it.
  ctl=$("$SIM" "$TMP/an.bin" $args -ccv-test-address-full-width 2>&1 | grep -oP '\] = \K\d+')
  if [ "$got" = 17 ] && [ "$ctl" = 34 ]; then
    echo "  PASS  a narrow index contributes only its element (O-79; control reads 32 bits)"
  else
    echo "  FAIL  addr-narrow: got '$got', want 17 (control: '$ctl', want 34)"; return 1
  fi
}
# --- sized loads and stores (O-80) ------------------------------------------
run_sized() {
  python3 "$AS" "$JSON" test/sized.s "$TMP/sz.bin" >/dev/null || return 1
  python3 "$AS" "$JSON" test/faults/sized-width.s "$TMP/szw.bin" >/dev/null || return 1
  local args="-poke 0x80000=2155999487 -poke 0x90010=2863311530 -poke 0x90014=2863311530"
  local k got ctl fault
  for k in 0 4 8 12 16 20 24 28 32 36; do args="$args -peek $(printf 0x%x $((0x90000 + k)))"; done
  local want="255 4294967295 32897 4294934657 2863311480 2863289976 22136 86 32897 65535"
  got=$("$SIM" "$TMP/sz.bin" $args 2>&1 | grep -oP '\] = \K\d+' | xargs)
  # The control: ld.s8 and ld.s16 zero-extend.
  ctl=$("$SIM" "$TMP/sz.bin" $args -ccv-test-sized-no-sext 2>&1 | grep -oP '\] = \K\d+' | xargs)
  fault=$("$SIM" "$TMP/szw.bin" 2>&1 | grep -c 'FAULT F-WIDTH')
  if [ "$got" = "$want" ] && [ "$ctl" != "$want" ] && [ "$fault" = 1 ]; then
    echo "  PASS  sized loads and stores: u8, s8, u16, s16, st.8, st.16 on .global and .shared, scaled, into a narrow rdata, and F-WIDTH when the transfer is wider (O-80)"
  else
    echo "  FAIL  sized: got '$got', want '$want' (control '$ctl', F-WIDTH $fault)"; return 1
  fi
}
# --- a chwidth from a diverged warp (O-81) ----------------------------------
run_diverged_chwidth() {
  python3 "$AS" "$JSON" test/faults/diverged-chwidth.s "$TMP/dc.bin" >/dev/null || return 1
  local got ctl
  got=$("$SIM" "$TMP/dc.bin" 2>&1 | grep -c 'FAULT F-WIDTH  pc=0x100e  lanes=0000ffff')
  # The control: the diverged chwidth executes, as before O-81.
  ctl=$("$SIM" "$TMP/dc.bin" -ccv-test-diverged-chwidth 2>&1 | grep -c 'FAULT')
  if [ "$got" = 1 ] && [ "$ctl" = 0 ]; then
    echo "  PASS  a chwidth from a diverged warp raises F-WIDTH, a converged one does not (O-81)"
  else
    echo "  FAIL  diverged-chwidth: fault $got, want 1 (control faults $ctl, want 0)"; return 1
  fi
}
# --- srd #2, %lanectx (O-64) -----------------------------------------------
run_lanectx() {
  python3 "$AS" "$JSON" test/lanectx.s "$TMP/lc.bin" >/dev/null || return 1
  local args="-threads 52 -warp 1 -peek 0x30080 -peek 0x300cc" out ill
  out=$("$SIM" "$TMP/lc.bin" $args 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # The control: selector 3 is still reserved, F-ILLEGAL.
  sed 's/SRD           R1, 2 /SRD           R1, 3 /' test/lanectx.s > "$TMP/lc3.s"
  python3 "$AS" "$JSON" "$TMP/lc3.s" "$TMP/lc3.bin" >/dev/null || return 1
  ill=$("$SIM" "$TMP/lc3.bin" $args 2>&1)
  # TI-35: -context names the warp's hardware context, here 3 for warp 0.
  local ctx="-threads 32 -context 3 -peek 0x30180 -peek 0x301fc -oracle $TMP/lc.jsonl"
  local c3; c3=$("$SIM" "$TMP/lc.bin" $ctx 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  if [ "${out% }" = "32 51" ] && grep -q "F-ILLEGAL" <<< "$ill" && [ "${c3% }" = "96 127" ] &&
     grep -q '"lane_context":3,' "$TMP/lc.jsonl"; then
    echo "  PASS  srd #2 gives (context << 5) | lane, -context sets it (TI-35), and srd #3 is still F-ILLEGAL"
  else
    echo "  FAIL  srd #2: got '$out', want '32 51'; -context 3: '$c3', want '96 127'; srd #3: $ill"; return 1
  fi
}
# --- narrow FP executed (CP-6) ----------------------------------------------
run_narrow_fp() {
  python3 "$AS" "$JSON" test/narrow-fp.s "$TMP/nf.bin" >/dev/null || return 1
  local peeks="" o
  for o in 0 4 8 12 16 20 24 64 124 128 188; do peeks="$peeks -peek $(printf 0x%x $((0x90000 + o)))"; done
  local want="60 57 7 16896 126 60 16608 60 60 17 17" got ctl
  got=$("$SIM" "$TMP/nf.bin" $peeks 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  # The control: narrow overflow to NaN, the rule O-56 rejected.
  ctl=$("$SIM" "$TMP/nf.bin" $peeks -ccv-test-fp-no-saturate 2>&1 | grep -oP '\] = \K\d+' | tr '\n' ' ')
  if [ "${got% }" = "$want" ] && [ "${ctl% }" != "$want" ]; then
    echo "  PASS  narrow FP in a kernel: E4M3, E5M2, E2M1, FP16 ffma, BF16 ffma.acc, a saturating conversion, compressed and predicated forms"
  else
    echo "  FAIL  narrow FP in a kernel: got '$got', want '$want' (control: '$ctl')"; return 1
  fi
}
echo
echo "  --- narrow FP (CP-6) ---"
run_narrow_fp || fail=1

echo
echo "  --- one warp of several (TI-29) ---"
run_warp || fail=1
echo
echo "  --- srd #2, %lanectx (O-64) ---"
run_lanectx || fail=1
echo
echo "  --- the interleaved spill space (O-69) ---"
run_local || fail=1
echo
echo "  --- frame objects disjoint (F-179) ---"
run_frames || fail=1
echo
echo "  --- canonical NaN, compare format (O-66, O-65) ---"
run_fp_canon || fail=1
run_sfu || fail=1
run_atomics || fail=1
run_atomics_fadd || fail=1
echo
echo "  --- the mixed-width rule (O-67) ---"
run_mixed_width || fail=1
run_addr_narrow || fail=1
run_sized || fail=1
run_diverged_chwidth || fail=1

# --- the fault model (ISA v1.9 section 12, O-57/O-58) ------------------------
# Each case names the record it must produce. A fault exits 3, distinct from a
# simulator error (1), so the status is checked too.
run_faults() {
  local bad=0 t want out rc
  for pair in "precise:FAULT F-ALIGN  pc=0x1018  lanes=aaaaaaaa  addr=0x50005" \
              "gated:" \
              "gated-on:FAULT F-ALIGN  pc=0x100c  lanes=ffffffff  addr=0x50001" \
              "width:FAULT F-WIDTH  pc=0x100e  lanes=ffffffff" \
              "illegal:FAULT F-ILLEGAL  pc=0x1000  lanes=ffffffff" \
              "format:FAULT F-FORMAT  pc=0x1004  lanes=ffffffff" \
              "fetch:FAULT F-FETCH  pc=0x1001  lanes=ffffffff" \
              "barrier:FAULT F-BARRIER  pc=0x1000  lanes=ffffffff"; do
    t=${pair%%:*}; want=${pair#*:}
    python3 "$AS" "$JSON" "test/faults/$t.s" "$TMP/f.bin" >/dev/null || { bad=1; continue; }
    out=$("$SIM" "$TMP/f.bin" -poke 0x50000=57005 -peek 0x50000 2>&1); rc=$?
    if [ -z "$want" ]; then
      if [ $rc -ne 0 ] || grep -q FAULT <<< "$out"; then
        echo "    $t: faulted or failed where nothing executes the access: $out"; bad=1; fi
    elif [ $rc -ne 3 ] || ! grep -qF "$want" <<< "$out"; then
      echo "    $t: want '$want' (status 3), got status $rc: $out"; bad=1
    fi
    # Precision: the faulting instruction leaves no trace, its aligned lanes
    # included -- and nothing before it in these tests touches 0x50000.
    grep -q '\[0x50000\] = 57005' <<< "$out" || { echo "    $t: [0x50000] changed"; bad=1; }
  done
  [ $bad -eq 0 ] && echo "  PASS  faults: F-ALIGN precise and predicate-gated, F-WIDTH ignores the predicate, F-ILLEGAL, F-FETCH, F-BARRIER" \
                 || { echo "  FAIL  the fault model"; return 1; }
}
# F-RO (O-51, O-61; TI-26): a store any byte of which is read-only -- the
# .const range, here [0x50000, 0x50006) by -const-range, or the whole launch
# window -- faults per lane, gated, after F-ALIGN; loads, and a store starting
# at the limit, do not. Every faulting case must leave memory as poked.
run_ro() {
  local bad=0 t want out rc
  local mem="-poke 0x50000=57005 -poke 0x50004=48879 -poke 0x50008=4660 -peek 0x50000 -peek 0x50004 -peek 0x50008"
  for pair in "ro-const:FAULT F-RO  pc=0x1010  lanes=00000001  addr=0x50000" \
              "ro-straddle:FAULT F-RO  pc=0x100a  lanes=ffffffff  addr=0x50004" \
              "ro-launch:FAULT F-RO  pc=0x1008  lanes=ffffffff  addr=0x20040" \
              "ro-gated:FAULT F-RO  pc=0x1014  lanes=ffff0000  addr=0x50000" \
              "ro-pred:FAULT F-RO  pc=0x100e  lanes=ffff0000  addr=0x20040" \
              "ro-load:" "ro-limit:"; do
    t=${pair%%:*}; want=${pair#*:}
    python3 "$AS" "$JSON" "test/faults/$t.s" "$TMP/f.bin" >/dev/null || { bad=1; continue; }
    out=$("$SIM" "$TMP/f.bin" -const-range 0x50000:0x50006 $mem 2>&1); rc=$?
    if [ -z "$want" ]; then
      if [ $rc -ne 0 ] || grep -q FAULT <<< "$out"; then
        echo "    $t: faulted where nothing is read-only: $out"; bad=1; fi
    elif [ $rc -ne 3 ] || ! grep -qF "$want" <<< "$out"; then
      echo "    $t: want '$want' (status 3), got status $rc: $out"; bad=1
    else
      for w in "0x50000] = 57005" "0x50004] = 48879" "0x50008] = 4660"; do
        grep -qF "[$w" <<< "$out" || { echo "    $t: not precise, [$w changed"; bad=1; }
      done
    fi
  done
  # The control for ro-straddle: the store at the limit landed.
  python3 "$AS" "$JSON" test/faults/ro-limit.s "$TMP/f.bin" >/dev/null &&
    grep -qF "[0x50004] = 5095151" <<< "$("$SIM" "$TMP/f.bin" -const-range 0x50000:0x50006 $mem 2>&1)" ||
    { echo "    ro-limit: the store at const_limit did not land"; bad=1; }
  # The oracle's init record carries the range, for MIU's const_base and
  # const_limit (TI-26).
  "$SIM" "$TMP/f.bin" -const-range 0x50000:0x50006 -oracle "$TMP/ro.jsonl" >/dev/null 2>&1
  head -1 "$TMP/ro.jsonl" | grep -qF '"const":[327680,327686]' ||
    { echo "    the oracle's init record has no .const range"; bad=1; }
  # TI-28: a faulting kernel's oracle ends with the faulting instruction's
  # record (kind "fault", no defs, each executing lane's address and no
  # value), the fault, and the state the rollback left -- in which lane 1's
  # store to 0x50008, outside the range, did not land.
  python3 "$AS" "$JSON" test/faults/ro-const.s "$TMP/f.bin" >/dev/null &&
    "$SIM" "$TMP/f.bin" -const-range 0x50000:0x50006 -poke 0x50008=4660 \
      -oracle "$TMP/ro.jsonl" >/dev/null 2>&1
  python3 - "$TMP/ro.jsonl" <<'PY' || bad=1
import json, sys
r = [json.loads(l) for l in open(sys.argv[1])]
ins, flt, fin = r[-3], r[-2], r[-1]
ok = (ins.get("kind") == "fault" and ins.get("defs") == [] and len(ins["mem"]) == 32
      and all("val" not in m and m["w"] == 1 for m in ins["mem"])
      and ins["mem"][1]["addr"] == 0x50008
      and flt.get("fault", {}).get("cause") == "F-RO"
      and [0x50008, 4660] in fin.get("final", {}).get("mem", []))
if not ok:
    print("    the faulting kernel's oracle is not instruction, fault, final state (TI-28)")
sys.exit(0 if ok else 1)
PY
  [ $bad -eq 0 ] && echo "  PASS  F-RO: .const and the launch window, any byte, per lane and gated, precise; loads and the limit itself do not fault; the oracle records the faulting instruction and the state after it" \
                 || { echo "  FAIL  F-RO"; return 1; }
}

echo
echo "  --- the fault model (ISA v1.9 section 12) ---"
run_faults || fail=1
run_ro || fail=1
# F-ADDR (O-75): a .global address is the exact sum, and one outside
# [0, 2^48) faults, per lane and precisely; the last word below 2^48 is
# mapped. (.shared wraps at 2^32 instead: tools/check-barcount.sh.)
run_addr() {
  local bad=0 t want out rc
  local mem="-poke 0xffffffffffc0=5 -poke 0xfffffffffffc=6 -peek 0xffffffffffc0 -peek 0xfffffffffffc"
  for pair in "addr-high:FAULT F-ADDR  pc=0x1016  lanes=ffff0000  addr=0x1000000000000" \
              "addr-neg:FAULT F-ADDR  pc=0x1004  lanes=ffffffff  addr=0xfffffffffffffffc"; do
    t=${pair%%:*}; want=${pair#*:}
    python3 "$AS" "$JSON" "test/faults/$t.s" "$TMP/f.bin" >/dev/null || { bad=1; continue; }
    out=$("$SIM" "$TMP/f.bin" $mem 2>&1); rc=$?
    if [ $rc -ne 3 ] || ! grep -qF "$want" <<< "$out"; then
      echo "    $t: want '$want' (status 3), got status $rc: $out"; bad=1
    elif ! grep -qF "[0xffffffffffc0] = 5" <<< "$out"; then
      echo "    $t: not precise, a lane below 2^48 stored"; bad=1
    fi
  done
  # The control: 2^48 - 4 is mapped, and the store lands.
  python3 "$AS" "$JSON" test/faults/addr-limit.s "$TMP/f.bin" >/dev/null &&
    out=$("$SIM" "$TMP/f.bin" $mem 2>&1) &&
    grep -qF "[0xfffffffffffc] = 77" <<< "$out" ||
    { echo "    addr-limit: the store below 2^48 did not land: $out"; bad=1; }
  [ $bad -eq 0 ] && echo "  PASS  F-ADDR: a .global sum at or past 2^48, or below 0, faults per lane and precisely; 2^48 - 4 does not" \
                 || { echo "  FAIL  F-ADDR"; return 1; }
}
run_addr || fail=1

echo
echo "  --- call and ret (F-21) ---"
run_call || fail=1

# The compiler side: CCVInsertChwidth places the mode switches, and the two
# things that are easy to get wrong are both pinned here. Default code has no
# 16-bit integer width to place (F-199: i16 runs at 32 bits, narrow accesses
# are sized), so this runs the configuration that still has one.
chw=$(build/ccv-llc test/accept/chwidth-i16.ll -o - -ccv-test-i16-legal -ccv-test-no-sized 2>/dev/null)
if ! grep -q "chwidth r" <<< "$chw"; then
  echo "  FAIL  no chwidth emitted for a 16-bit kernel"
  fail=1
elif grep -qE "^	chwidth r1," <<< "$chw"; then
  # r1 is the store's base address. §3 takes transfer size from rdata's
  # chwidth alone, and invariant 11 says an address is never narrow. A
  # per-instruction width tag sets the mode here; a per-operand one does not.
  echo "  FAIL  chwidth set on the store's base address register"
  echo "$chw" | sed 's/^/        /'
  fail=1
else
  echo "  PASS  chwidth placed on data registers only ($(echo "$chw" | grep -c "chwidth") emitted, incl. chwidth.multi)"
fi

# F-111: the base+DISPLACEMENT form of a 16-bit global access. The base+index
# form has checked the memory type since a `short` kernel first clobbered its
# neighbour; this form did not, and selected the 32-bit instruction -- so the
# data register was 32 bits wide at the access and narrowed afterwards, which
# makes the transfer four bytes for a two-byte element. Both the load (reading
# past the end) and the store (writing over the next element) are wrong, and
# neither shows up in any value the kernel is asked about.
#
# The tell is a WIDENING chwidth: the whole kernel works at 16 bits, so every
# width change in it should be to width code 1. Selecting the wide form forces
# a `chwidth.multi <mask>, 0` back to 32 before the store.
bo=$(build/ccv-llc test/accept/base-offset-i16.ll -o - 2>/dev/null)
if [ -z "$bo" ]; then
  echo "  FAIL  base-offset-i16.ll did not compile"
  fail=1
elif grep -q "ld.global.u16" <<< "$bo" && grep -q "st.global.16" <<< "$bo" &&
     ! grep -qE "^	(ld|st)\.global r" <<< "$bo"; then
  # O-80: the sized forms name the transfer in the opcode, so a 16-bit access
  # cannot move four bytes whatever the data register's width.
  echo "  PASS  16-bit base+offset accesses take the sized forms ($(grep -cE 'global\.(u16|16)' <<< "$bo") accesses, O-80)"
elif grep -qE "chwidth(\.multi)? [^,]+, 0$" <<< "$bo"; then
  echo "  FAIL  16-bit base+offset access selected the 32-bit form"
  echo "        (a widening chwidth in an all-16-bit kernel means the"
  echo "         transfer is four bytes wide for a two-byte element)"
  echo "$bo" | sed 's/^/        /'
  fail=1
else
  echo "  PASS  16-bit base+offset access stays 16 bits ($(echo "$bo" | grep -c 'global') accesses, no widening)"
fi
# zext is free under O-38 -- widening clears the exposed bits, which IS the
# zero-extension. If a masking instruction ever appears in that path, either
# O-38 was reverted or the pattern stopped firing.
zx=$(echo "$chw" | sed -n '/zext_is_free:/,/exit/p')
if grep -qE "^	(and|f48) " <<< "$zx"; then
  echo "  FAIL  zext emitted a masking instruction; O-38 makes it free"
  echo "$zx" | sed 's/^/        /'
  fail=1
else
  echo "  PASS  zext costs no instruction beyond the width change (O-38)"
fi

# A 16-bit kernel end to end, including the bytes it must NOT touch.
./tools/check-divconst.sh || fail=1
./tools/check-narrow.sh || fail=1
# The same kernel with a loop. F-87 moved the width transitions onto the
# incoming edges, so the loop runs narrow for its whole lifetime and never
# re-establishes the mode -- which is the saving and also the risk.
./tools/check-narrow-loop.sh || fail=1

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
if grep -qw sel <<< "$sel_out"; then
  echo "  FAIL  select lowered to \`sel\`, which activates all 32 lanes"
  echo "$sel_out" | grep -w sel | sed 's/^/        /'
  fail=1
elif grep -q "@p[0-9] mov" <<< "$sel_out"; then
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
    # An object, not a listing: the encoder checks every immediate fits its
    # field, and a listing never reaches it.
    if build/ccv-llc "$f" -o "$TMP/a.o" -obj >/dev/null 2>&1; then
      echo "  PASS  accepts $(basename "$f")"
    else
      echo "  FAIL  rejects $(basename "$f") -- should compile"; fail=1
    fi
  done
  # Each test names the diagnostic it exists for (`; expect:`), so a module
  # that several rules reject still proves its own one fires.
  for f in test/reject/*.ll; do
    out=$(build/ccv-llc "$f" -o "$TMP/r.s" 2>&1); rc=$?
    want=$(sed -n 's/^; expect: //p' "$f" | head -1)
    if [ -z "$want" ]; then
      echo "  FAIL  $(basename "$f") names no '; expect:' diagnostic"; fail=1
    elif [ $rc -eq 1 ] && grep -q "cannot be lowered" <<< "$out" &&
         grep -qF -- "- $want in @" <<< "$out"; then
      echo "  PASS  diagnoses $(basename "$f"): $want"
    elif [ $rc -eq 0 ]; then
      echo "  FAIL  $(basename "$f") compiled -- should be rejected"; fail=1
    elif [ $rc -eq 1 ] && grep -q "cannot be lowered" <<< "$out"; then
      echo "  FAIL  $(basename "$f") was rejected, but not with '$want'"; fail=1
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

# --- IEEE fp32 division, 1/x and sqrtf over an approximate SFU --------------
# (F-49, O-36, F-62, F-178, IS-12.) Two checks that catch different things:
# the model checks the ALGORITHM against exact rounding -- every reduced
# divisor and argument at every seed error up to 2 ulps, and sampled divides;
# `model-ieee-sfu --all` adds every float -- and the simulator run checks the
# MACHINE. The model's control drops the divide's residual check of the last
# bit and sqrt's refinement, which a correctly rounded SFU would have hidden.
echo
echo "  --- IEEE fp32 division, 1/x and sqrtf ---"
build/model-ieee-sfu --divs 500000 || fail=1
if build/model-ieee-sfu --divs 500000 --control >/dev/null; then
  echo "  FAIL  control: model-ieee-sfu --control still passed"; fail=1
else
  echo "  PASS  control: model-ieee-sfu --control fails, as an exact SFU would hide"
fi
./tools/check-fdiv.sh 20 || fail=1

# --- the FP SFU's values (O-70) --------------------------------------------
# ccv-sim's values are its own integer arithmetic (SfuMath.cpp). check-sfu-math
# holds them to the host's double functions, and to mpmath's judgement where a
# double is too near a midpoint (test/sfu-hard-cases.txt, every such input in
# FP32); and -sfu-error-ulps 2 to O-70's bound. The controls: truncation for
# rounding, and -sfu-error-ulps 3 against the same bound.
echo
echo "  --- the FP SFU's values (O-70) ---"
build/check-sfu-math --sample 4093 || fail=1
if build/check-sfu-math --sample 65521 --control >/dev/null; then
  echo "  FAIL  control: check-sfu-math --control (truncation) still passed"; fail=1
else
  echo "  PASS  control: truncating instead of rounding is caught"
fi
build/check-sfu-math --within 2 2 4093 || fail=1
if build/check-sfu-math --within 3 2 65521 >/dev/null; then
  echo "  FAIL  control: -sfu-error-ulps 3 still within O-70's bound"; fail=1
else
  echo "  PASS  control: -sfu-error-ulps 3 is caught outside O-70's bound"
fi

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

# --- srd's destination is never narrow (F-157) -----------------------------
# srd truncates to its register's width (§5.3, invariant 3), so a narrow
# destination aliases every CTA above some index onto a lower one -- no fault,
# a plausible wrong answer at scale. The backend refuses it by name. Today no
# narrow srd can be built, so the refusal is proven by a mutation: pretend
# srd's destination is 16-bit, and the compile must fail naming F-157. The
# unmutated compile must still succeed and still emit srd.
echo
echo "  --- srd destination width ---"
if [ -x build/ccv-llc ]; then
  if grep -q "srd " <<< "$(build/ccv-llc test/accept/base-index.ll -o - 2>/dev/null)"; then
    echo "  PASS  srd compiles at 32 bits"
  else
    echo "  FAIL  base-index.ll no longer compiles to an srd"; fail=1
  fi
  # (A subshell, so the shell's own "Aborted" notice stays out of the log.)
  if ! (build/ccv-llc test/accept/base-index.ll -o /dev/null -ccv-test-narrow-srd \
       2>"$TMP/srd.err"; exit $?) 2>/dev/null && grep -q "srd's destination must be 32 bits wide.*F-157" "$TMP/srd.err"; then
    echo "  PASS  a narrow srd destination is refused, by name"
  else
    echo "  FAIL  a narrow srd destination was not refused"; fail=1
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
