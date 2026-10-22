#!/usr/bin/env bash
# A module's globals (ISA v1.9 §5.2, O-61; CP-10), executed: test/cuda/globals.cu.
#
# ccv-llc lays every global out in one image, .ccv_data, with the offsets of
# its data-pointer slots in .ccv_reloc. ccv-sim loads it as the runtime would:
# at -data-window << 16, each slot relocated, the window in launch-block word
# 28. Every lane's results are checked against values written from the
# source; the writable array's are its value after the kernel's update.
#
# Controls, each of which must fail: no relocation list (the pointer table
# keeps image offsets, which name memory outside the image), and the window
# read from word 24 rather than 28.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS=-Itest/bench ./tools/cuda-to-asm.sh test/cuda/globals.cu "$TMP/g.s" "$TMP/g" \
  >/dev/null 2>&1 || { echo "  FAIL  globals.cu did not compile"; exit 1; }

run() {
  build/ccv-llc "$TMP/g-lowered.ll" -o "$TMP/g.o" -obj "$@" 2>"$TMP/llc.err" ||
    { echo "compile failed: $(head -1 "$TMP/llc.err")"; return; }
  for s in text ccv_data ccv_reloc; do
    llvm-objcopy -O binary --only-section=.$s "$TMP/g.o" "$TMP/$s.bin" || return
  done
  local entry; entry=$(llvm-nm "$TMP/g.o" | awk '/ T .*globals/ {print "0x"$1}')
  python3 - "$TMP" "$entry" <<'PY'
import os, struct, subprocess, sys
tmp, entry = sys.argv[1], sys.argv[2]
N, OUT, DW = 32, 0x70000, 0x200
row0, row1 = [1, 2, 3, 4], [10, 20, 30, 40]
pts = [(1, -7), (-2, 9), (3, 100)]
scale = [0.5, 2.0]
def s32(x):
    x &= 0xffffffff
    return x - (1 << 32) if x & 0x80000000 else x
args = ["-entry", entry, "-data", f"{tmp}/ccv_data.bin", "-data-window", str(DW),
        "-poke", "0x20000=32", "-poke", "0x20020=7", "-poke", "0x20024=0"]
if os.path.getsize(f"{tmp}/ccv_reloc.bin"):
    args += ["-data-reloc", f"{tmp}/ccv_reloc.bin"]
for w in range(2 * N):
    args += ["-poke", f"{OUT + 4 * w:#x}=3735928559", "-peek", f"{OUT + 4 * w:#x}"]
r = subprocess.run(["build/ccv-sim", f"{tmp}/text.bin"] + args, capture_output=True, text=True)
if r.returncode:
    print("did not run:", (r.stderr or r.stdout).strip().splitlines()[0]); sys.exit()
got = {}
for line in r.stdout.splitlines():
    if line.strip().startswith("[0x"):
        a, v = line.split("=")
        got[int(a.strip()[1:-1], 16)] = s32(int(v.split()[0]))
bad = []
for i in range(N):
    x, y = pts[i % 3]
    want = [s32((row1 if i & 1 else row0)[i & 3] + x * y + 5), int(scale[i & 1] * i)]
    have = [got.get(OUT + 8 * i), got.get(OUT + 8 * i + 4)]
    if have != want:
        bad.append(f"lane {i}: {have}, want {want}")
if bad:
    print(f"{len(bad)} of {N} lanes wrong; {bad[0]}")
else:
    print("ok", next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?"))
PY
}

fail=0
out=$(run)
case "$out" in
  ok*) echo "  PASS  globals.cu: a module's data image, relocated and read through word 28 on 32 lanes (${out#ok } issue groups)" ;;
  *)   echo "  FAIL  globals.cu: $out"; fail=1 ;;
esac
for c in "-ccv-test-no-data-reloc" "-ccv-test-data-word-24"; do
  out=$(run $c)
  case "$out" in
    ok*) echo "  FAIL  control $c still computed every lane right"; fail=1 ;;
    *" lanes wrong; "*|"did not run"*) echo "  PASS  control $c is caught: $out" ;;
    *)   echo "  FAIL  control $c broke something else: $out"; fail=1 ;;
  esac
done
exit $fail
