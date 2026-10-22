#!/usr/bin/env bash
# Pointers as values (F-22), executed: test/cuda/ptrlist.cu.
#
# Each lane builds a linked list of eight nodes, reverses it in place, walks it
# into a struct in its own frame through a callee, and searches it, once for a
# value that is there and once for one that is not. That is pointer phis,
# pointer stores of a select that is sometimes NULL, compares against NULL and
# between two pointers, a frame object's address passed down a call, and a
# pointer's low bits read as an integer. The pool starts at window 3, offset
# 0xF800, so the nodes straddle the window boundary: a pointer read back from
# memory comes back as window 4, the same address reached by indexing stays
# window 3 with a large offset, and only the flat address compares them equal.
#
# Controls, each of which must fail: pointers compared by their pairs rather
# than their addresses (h == &base[7] goes false for the lanes past the
# boundary), and a frame pointer given R15's window rather than the one below
# it (tally writes another thread's frame, and the sums stay 0).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS=-Itest/bench ./tools/cuda-to-asm.sh test/cuda/ptrlist.cu "$TMP/p.s" "$TMP/p" \
  >/dev/null 2>&1 || { echo "  FAIL  ptrlist.cu did not compile"; exit 1; }

run() {
  build/ccv-llc "$TMP/p-lowered.ll" -o "$TMP/p.o" -obj "$@" 2>"$TMP/llc.err" ||
    { echo "compile failed: $(head -1 "$TMP/llc.err")"; return; }
  llvm-objcopy -O binary --only-section=.text "$TMP/p.o" "$TMP/p.bin" || return
  local entry; entry=$(llvm-nm "$TMP/p.o" | awk '/ T .*ptrlist/ {print "0x"$1}')
  python3 - "$TMP/p.bin" "$entry" <<'PY'
import subprocess, sys
N, OUT = 32, 0x70000
args = ["-entry", sys.argv[2], "-poke", "0x20000=32", "-poke", "0x20018=256",
        "-poke", "0x20020=3", "-poke", "0x20024=63488",   # pool -> 3:0xF800
        "-poke", "0x20028=7", "-poke", "0x2002c=0"]       # out  -> window 7
for w in range(4 * N):
    args += ["-poke", f"{OUT + 4 * w:#x}=3735928559", "-peek", f"{OUT + 4 * w:#x}"]
r = subprocess.run(["build/ccv-sim", sys.argv[1]] + args, capture_output=True, text=True)
if r.returncode:
    print("did not run:", (r.stderr or r.stdout).strip().splitlines()[0]); sys.exit()
got = {}
for line in r.stdout.splitlines():
    if line.strip().startswith("[0x"):
        a, v = line.split("=")
        got[int(a.strip()[1:-1], 16)] = int(v.split()[0]) & 0xffffffff
bad = []
for t in range(N):
    want = [80 * t + 28, 8, t * 10 + (t & 7), 1 + 2 + 4 * 8]
    have = [got.get(OUT + 16 * t + 4 * k) for k in range(4)]
    if have != want:
        bad.append(f"lane {t}: {have}, want {want}")
if bad:
    print(f"{len(bad)} of {N} lanes wrong; {bad[0]}")
else:
    print("ok", next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?"))
PY
}

fail=0
out=$(run)
case "$out" in
  ok*) echo "  PASS  ptrlist.cu: lists built, reversed, walked and searched on 32 lanes across a window boundary (${out#ok } issue groups)" ;;
  *)   echo "  FAIL  ptrlist.cu: $out"; fail=1 ;;
esac
for c in "-ccv-test-raw-ptr-compare" "-ccv-test-frame-window-r15"; do
  out=$(run $c)
  case "$out" in
    ok*) echo "  FAIL  control $c still computed every lane right"; fail=1 ;;
    *" lanes wrong; "*|"did not run"*) echo "  PASS  control $c is caught: $out" ;;
    *)   echo "  FAIL  control $c broke something else: $out"; fail=1 ;;
  esac
done
exit $fail
