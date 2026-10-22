#!/usr/bin/env bash
# Pointers in memory (CP-3; ISA v1.9 §5.7, O-54), executed.
#
# test/cuda/ptrmem.cu reads pointers out of a table in global memory and
# writes pointers back. Memory holds the host's flat 64-bit address; the
# backend splits one on load into the window and offset the AGU takes, and
# joins them on store with a carry. Every lane's loaded value and stored
# pointer is checked. Entry 3 sits just under 4 GiB, so the lanes that use
# it read across the boundary and store pointers whose low word wraps.
#
# Controls, each of which must fail: the carry dropped (entry 3's pointers
# come back 4 GiB short), and the halves of a loaded pointer swapped.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS=-Itest/bench ./tools/cuda-to-asm.sh test/cuda/ptrmem.cu "$TMP/p.s" "$TMP/p" \
  >/dev/null 2>&1 || { echo "  FAIL  ptrmem.cu did not compile"; exit 1; }

# Runs the kernel compiled with the given ccv-llc flags. Prints "ok <groups>",
# or what went wrong.
run() {
  build/ccv-llc "$TMP/p-lowered.ll" -o "$TMP/p.o" -obj "$@" 2>"$TMP/llc.err" ||
    { echo "compile failed: $(head -1 "$TMP/llc.err")"; return; }
  llvm-objcopy -O binary --only-section=.text "$TMP/p.o" "$TMP/p.bin" || return
  python3 - "$TMP/p.bin" <<'PY'
import struct, subprocess, sys
N = 32
TBL, SLOTS, OUT = 0x30000, 0x40000, 0x70000              # windows 3, 4, 7
entries = [0x50000, 0x50100, 0x60008, 0xFFFFFFF0]
f2u = lambda x: struct.unpack("<I", struct.pack("<f", x))[0]
args = ["-poke", "0x20000=32",
        "-poke", "0x20020=3", "-poke", "0x20024=0",      # tbl
        "-poke", "0x20028=4", "-poke", "0x2002c=0",      # slots
        "-poke", "0x20030=7", "-poke", "0x20034=0"]      # out
for e, a in enumerate(entries):                          # tbl[e], flat 64-bit
    args += ["-poke", f"{TBL + 8 * e:#x}={a & 0xffffffff}",
             "-poke", f"{TBL + 8 * e + 4:#x}={a >> 32}"]
    for k in range(8):
        args += ["-poke", f"{a + 4 * k:#x}={f2u(e * 100.0 + k)}"]
for w in range(2 * N):
    args += ["-poke", f"{SLOTS + 4 * w:#x}=3735928559", "-peek", f"{SLOTS + 4 * w:#x}"]
for i in range(N):
    args += ["-poke", f"{OUT + 4 * i:#x}=3735928559", "-peek", f"{OUT + 4 * i:#x}"]
r = subprocess.run(["build/ccv-sim", sys.argv[1]] + args, capture_output=True, text=True)
if r.returncode:
    print("did not run:", (r.stderr or r.stdout).strip().splitlines()[0]); sys.exit()
got = {}
for line in r.stdout.splitlines():
    if line.strip().startswith("[0x"):
        a, v = line.split("=")
        got[int(a.strip()[1:-1], 16)] = int(v.split()[0]) & 0xffffffff
bad = []
for i in range(N):
    e, k = i & 3, i >> 2
    if got.get(OUT + 4 * i) != f2u(2.0 * (e * 100.0 + k)):
        bad.append(f"out[{i}] = {got.get(OUT + 4 * i):#x}")
    want = entries[e] + 4 * (k + 4)
    have = (got.get(SLOTS + 8 * i + 4, 0) << 32) | got.get(SLOTS + 8 * i, 0)
    if have != want:
        bad.append(f"slots[{i}] = {have:#x}, want {want:#x}")
if bad:
    print(f"{len(bad)} wrong; first: {bad[0]}")
else:
    print("ok", next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?"))
PY
}

fail=0
out=$(run)
case "$out" in
  ok*) echo "  PASS  ptrmem.cu: 32 pointers read from memory and 32 written, across 4 GiB (${out#ok } issue groups)" ;;
  *)   echo "  FAIL  ptrmem.cu: $out"; fail=1 ;;
esac
for c in "-ccv-test-no-ptr-carry" "-ccv-test-swap-ptr-halves"; do
  out=$(run $c)
  case "$out" in
    ok*) echo "  FAIL  control $c still computed every lane right"; fail=1 ;;
    *" wrong; "*|"did not run"*) echo "  PASS  control $c is caught: $out" ;;
    *)   echo "  FAIL  control $c broke something else: $out"; fail=1 ;;
  esac
done
exit $fail
