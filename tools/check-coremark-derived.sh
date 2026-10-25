#!/usr/bin/env bash
# A CoreMark-derived workload, executed: test/coremark-derived (AR-20).
#
# CoreMark's list, matrix and state benchmarks, unmodified, compiled for the
# device and run on 32 lanes, one context per lane. Each lane's list, matrix and
# state CRCs must be CoreMark's published values for the 2K performance-run
# seeds (0xe714, 0x1fd7, 0x8e3a), and its final CRC after two iterations the
# one the same harness computes on the host. Not a CoreMark score: see
# test/coremark-derived/README.md.
#
# It is the first workload with calls, bytes, shorts, pointers in memory,
# module data and predicate spills all at once, which is where each of those
# met the others. `mem` starts 66000 bytes into its window, so every lane's
# block lies past 64 KiB there: an in-window offset that does not fit 16 bits,
# which `align_mem` reads at 16 (F-169). Controls, which must fail:
# -ccv-test-hoist-past-calls lets a width transition move above a call, which
# resets it; -ccv-test-no-data-reloc leaves the pointers in the module's data
# (the state benchmark's pattern tables) unrelocated; and
# -ccv-test-narrow-in-place narrows a register for a 16-bit read while its
# 32-bit value is still live. F-195 made a truncation an instruction of its
# own, which never shares a register with a live source, so that control runs
# with -ccv-test-trunc-as-copy, which puts the old shape back, and must still
# be caught there.
#
# F-195: a truncation to 16 bits clears the high half whenever a 32-bit read
# may see it (tools/check-trunc16.sh has its soundness control). Here
# -ccv-test-trunc-ignore-known and -ccv-test-trunc-always-narrow clear where
# the source's known bits or its readers say it is not needed, and must cost
# more.
#
# F-198 (TI's rev 185): a narrow load's destination never shares a register
# with its base or index, checked on the assembly. Its control,
# -ccv-test-narrow-data-shared, must show the sites there, and must compute
# wrong lanes, since ccv-sim reads a narrow index as its element (O-79).
#
# TI-45: width changes that buy nothing. The run counts the chwidths that set
# a register to the width it already had (ccv-sim -counters), and two controls
# put back what made them, each of which must cost more: placing a loop
# header's transition on an outer-loop predecessor refused as a back edge
# (-ccv-test-chwidth-reach-back-edge), a byte load not marked as
# zero-extended, so a zext's `and 255` stays (-ccv-test-no-byte-assertzext).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
D=test/coremark-derived
ITER=2

for c in core_list_join core_matrix core_state core_util; do
  clang -x c --target=nvptx64-nvidia-cuda -O2 -fno-vectorize -fno-slp-vectorize \
        -I"$D" -emit-llvm -S "$D/upstream/$c.c" -o "$TMP/$c.ll" 2>"$TMP/cc.err" ||
    { echo "  FAIL  $c.c did not compile: $(head -1 "$TMP/cc.err")"; exit 1; }
done
# The module twice: CoreMark's seeds on every lane (cm), and a seed per lane
# (pl), whose lanes take their own paths, so the warp diverges (O-81).
for v in "cm:" "pl:-DCCV_SEED_PER_LANE"; do
  n=${v%%:*}
  CCV_CFLAGS="-Itest/bench -I$D -I$D/upstream -fno-vectorize -fno-slp-vectorize ${v#*:}" \
    ./tools/cuda-to-ir.sh "$D/kernel.cu" "$TMP/kernel-$n.ll" >/dev/null 2>"$TMP/cc.err" ||
    { echo "  FAIL  kernel.cu did not compile (${v#*:}): $(head -1 "$TMP/cc.err")"; exit 1; }
  llvm-link -S "$TMP/kernel-$n.ll" "$TMP"/core_*.ll -o "$TMP/$n.ll" &&
  opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
      -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
      -S "$TMP/$n.ll" -o "$TMP/$n-lowered.ll" 2>/dev/null ||
    { echo "  FAIL  the module did not link or lower"; exit 1; }
done

cc -O1 -I"$D" -I"$D/upstream" -o "$TMP/host" "$D/host.c" "$D"/upstream/core_*.c 2>/dev/null ||
  { echo "  FAIL  the host reference did not build"; exit 1; }
want=$("$TMP/host" $ITER)
case "$want" in
  *" e714 1fd7 8e3a") ;;
  *) echo "  FAIL  the host reference is not CoreMark's: $want"; exit 1 ;;
esac
# Lane t of the per-lane-seed module against the host at seed t.
wantpl=$(for t in $(seq 0 31); do "$TMP/host" $ITER $t; done | paste -sd'|')

MOD=cm
run() {
  build/ccv-llc "$TMP/$MOD-lowered.ll" -o "$TMP/cm.o" -obj "$@" 2>"$TMP/llc.err" ||
    { echo "compile failed: $(head -1 "$TMP/llc.err")"; return; }
  for s in text ccv_data ccv_reloc ccv_info; do
    llvm-objcopy -O binary --only-section=.$s "$TMP/cm.o" "$TMP/$s.bin" || return
  done
  local entry; entry=$(llvm-nm "$TMP/cm.o" | awk '/ T _Z8coremark/ {print "0x"$1}')
  python3 - "$TMP" "$entry" "$([ $MOD = pl ] && echo "$wantpl" || echo "$want")" <<'PY'
import os, subprocess, sys
tmp, entry, wants = sys.argv[1], sys.argv[2], sys.argv[3].split("|")
N, MEM, OUT, ITER = 32, 3, 7, 2
args = ["-entry", entry, "-data", f"{tmp}/ccv_data.bin", "-data-info", f"{tmp}/ccv_info.bin",
        "-max-steps", "100000000", "-counters",
        "-poke", f"0x20000={N}", "-poke", "0x20018=256",
        "-poke", f"0x20020={MEM}", "-poke", "0x20024=66000",  # mem, past 64 KiB
        "-poke", f"0x20028={OUT}", "-poke", "0x2002c=0",      # out
        "-poke", f"0x20030={ITER}"]                           # iterations
if os.path.getsize(f"{tmp}/ccv_reloc.bin"):
    args += ["-data-reloc", f"{tmp}/ccv_reloc.bin"]
for w in range(2 * N):
    args += ["-poke", f"{(OUT << 16) + 4 * w:#x}=3735928559", "-peek", f"{(OUT << 16) + 4 * w:#x}"]
r = subprocess.run(["build/ccv-sim", f"{tmp}/text.bin"] + args, capture_output=True, text=True)
if r.returncode:
    lines = (r.stdout + r.stderr).strip().splitlines()
    print("did not run:", next((l.strip() for l in lines if "FAULT" in l), lines[0] if lines else "?"))
    sys.exit()
got = {}
for line in r.stdout.splitlines():
    if line.strip().startswith("[0x"):
        a, v = line.split("=")
        got[int(a.strip()[1:-1], 16)] = int(v.split()[0]) & 0xffffffff
bad = []
for t in range(N):
    want = wants[t % len(wants)]
    w0, w1 = got.get((OUT << 16) + 8 * t, 0), got.get((OUT << 16) + 8 * t + 4, 0)
    have = f"{w0 & 0xffff:04x} {w0 >> 16:04x} {w1 & 0xffff:04x} {w1 >> 16:04x}"
    if have != want:
        bad.append(f"lane {t}: {have}, want {want}")
if bad:
    print(f"{len(bad)} of {N} lanes wrong; {bad[0]}")
else:
    noop = next((l.split()[2] for l in r.stdout.splitlines() if "no-op widths" in l), "?")
    print("ok", next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?"), noop)
PY
}

fail=0
out=$(run)
case "$out" in
  ok*) read -r _ groups noop <<< "$out"
       echo "  PASS  CoreMark-derived: list, matrix and state on 32 lanes give CoreMark's CRCs, and the host's after $ITER iterations ($want; $groups issue groups, $noop no-op widths)" ;;
  *)   echo "  FAIL  CoreMark-derived: $out"; fail=1; groups=0; noop=0 ;;
esac
# The chwidth machinery's controls. Default code has no narrow integer width
# left to place (F-199): 16-bit integers run at 32 bits and narrow accesses
# take O-80's sized forms. The machinery still serves narrow FP, so its
# controls run on the configuration that exercises it, LEGACY, against
# LEGACY's own counts.
LEGACY="-ccv-test-i16-legal -ccv-test-no-sized"
out=$(run $LEGACY)
case "$out" in
  ok*) read -r _ groups noop <<< "$out"
       echo "  PASS  the same at width 16 and with chwidth accesses ($LEGACY): $groups issue groups, $noop no-op widths" ;;
  *)   echo "  FAIL  CoreMark-derived under $LEGACY: $out"; fail=1; groups=0; noop=0 ;;
esac
# TI-45's controls: each must still compute every lane right, at a cost.
for c in "-ccv-test-chwidth-reach-back-edge:noop" "-ccv-test-no-byte-assertzext:groups" \
         "-ccv-test-trunc-ignore-known:groups" \
         "-ccv-test-trunc-always-narrow:groups"; do
  out=$(run $LEGACY ${c%%:*})
  read -r tag cg cn <<< "$out"
  if [ "$tag" != ok ]; then
    echo "  FAIL  control ${c%%:*} broke the workload: $out"; fail=1
  elif [ "${c#*:}" = noop ] && [ "$cn" -gt "$noop" ]; then
    echo "  PASS  control ${c%%:*}: $cn no-op widths, against $noop"
  elif [ "${c#*:}" = groups ] && [ "$cg" -gt "$groups" ]; then
    echo "  PASS  control ${c%%:*}: $cg issue groups, against $groups"
  else
    echo "  FAIL  control ${c%%:*} costs nothing ($cg issue groups, $cn no-op widths)"; fail=1
  fi
done
for c in "$LEGACY -ccv-test-hoist-past-calls" -ccv-test-no-data-reloc \
         "$LEGACY -ccv-test-narrow-data-shared" \
         "$LEGACY -ccv-test-narrow-in-place -ccv-test-trunc-as-copy" \
         "$LEGACY -ccv-test-chwidth-defs-only"; do
  out=$(run $c)
  case "$out" in
    ok*) echo "  FAIL  control $c still computed every lane right"; fail=1 ;;
    *" lanes wrong; "*|"did not run"*) echo "  PASS  control $c is caught: $out" ;;
    *)   echo "  FAIL  control $c broke something else: $out"; fail=1 ;;
  esac
done
# F-199 (O-81): the per-lane-seed module diverges, so any chwidth there faults;
# every lane must match the host at its own seed. Controls: 16-bit integers
# at width 16 (-ccv-test-i16-legal) and narrow accesses by chwidth
# (-ccv-test-no-sized) each put chwidths into divergent code, and must fail.
MOD=pl
out=$(run)
case "$out" in
  ok*) read -r _ pg pn <<< "$out"
       echo "  PASS  CoreMark-derived with a seed per lane: every lane diverges on its own data and matches the host at its seed ($pg issue groups)" ;;
  *)   echo "  FAIL  CoreMark-derived with a seed per lane: $out"; fail=1 ;;
esac
for c in -ccv-test-i16-legal -ccv-test-no-sized; do
  out=$(run $c)
  case "$out" in
    ok*) echo "  FAIL  control $c still computed every per-lane-seed lane right"; fail=1 ;;
    *)   echo "  PASS  control $c is caught on the per-lane-seed module: $out" ;;
  esac
done
MOD=cm

# F-198: no narrow access names its data register as its base or index, so no
# chwidth before it narrows an address register. The control shares them again,
# as O-39 allows, and must show the sites.
shared() {
  build/ccv-llc "$TMP/cm-lowered.ll" -o "$TMP/cm.s" "$@" 2>/dev/null || { echo x; return; }
  python3 - "$TMP/cm.s" <<'PY'
import re, sys
L = open(sys.argv[1]).read().splitlines()
n = 0
for i, l in enumerate(L[:-1]):
    m = re.match(r'\s*chwidth\s+(r\d+),\s*[123]\s*$', l)
    a = re.match(r'\s*(?:ld|st)\.\w+\s+r\d+,\s*\[(.*)\]', L[i + 1])
    if m and a and m.group(1) in re.findall(r'r\d+', a.group(1)):
        n += 1
print(n)
PY
}
n=$(shared $LEGACY); c=$(shared $LEGACY -ccv-test-narrow-data-shared)
if [ "$n" = 0 ] && [ "$c" != x ] && [ "$c" -gt 0 ]; then
  echo "  PASS  no narrow access shares its data register with its address (control -ccv-test-narrow-data-shared: $c sites)"
else
  echo "  FAIL  narrow accesses sharing data and address registers: $n (control: $c)"; fail=1
fi
exit $fail
