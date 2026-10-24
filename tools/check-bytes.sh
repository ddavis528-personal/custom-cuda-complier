#!/usr/bin/env bash
# Byte memory access (F-161), executed: test/cuda/bytes.cu.
#
# A byte is a load or store at chwidth 8: §3 takes the transfer size from
# rdata's width. Signed bytes must sign-extend, unsigned ones zero-extend, a
# string must stop at its terminator, a byte array works in .shared and in the
# thread's frame, and 32 lanes storing the 32 bytes of eight words must leave
# every neighbour intact -- which a 32-bit store, or a read-modify-write of the
# word, would not. Every lane's results and every packed byte are checked
# against values written from the source, and so are the shorts stored one
# block after the compare that widened them (F-164).
#
# Controls, which must fail: -ccv-test-bytes-at-32 selects the 32-bit forms for
# byte accesses, so each transfer moves four bytes; and the chwidth model of
# narrow data (-ccv-test-i16-legal -ccv-test-no-sized), whose width changes
# this kernel's diverged lanes fault on (O-81). F-164's control,
# -ccv-test-chwidth-defs-only, runs on CoreMark-derived, which never diverges.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS=-Itest/bench ./tools/cuda-to-asm.sh test/cuda/bytes.cu "$TMP/b.s" "$TMP/b" \
  >/dev/null 2>&1 || { echo "  FAIL  bytes.cu did not compile"; exit 1; }

run() {
  build/ccv-llc "$TMP/b-lowered.ll" -o "$TMP/b.o" -obj "$@" 2>"$TMP/llc.err" ||
    { echo "compile failed: $(head -1 "$TMP/llc.err")"; return; }
  llvm-objcopy -O binary --only-section=.text "$TMP/b.o" "$TMP/b.bin" || return
  python3 - "$TMP/b.bin" <<'PY'
import struct, subprocess, sys
N, IN, STR, PACK, OUT, H, HOUT = 32, 0x30000, 0x40000, 0x50000, 0x70000, 0x60000, 0x80000
inb = [-1, -128, 127, 5, -7, 0, 100, -100, 3, -3, 64, -64, 1, 2, -2, 9]
text = b"Hello, CCV!\0" + b"\xee" * 20
def words(bs):
    bs = bytes(bs) + b"\0" * (-len(bs) % 4)
    return [struct.unpack("<I", bs[k:k + 4])[0] for k in range(0, len(bs), 4)]
def s32(x):
    x &= 0xffffffff
    return x - (1 << 32) if x & 0x80000000 else x
args = ["-poke", "0x20000=32", "-poke", "0x20018=256"]
for k, (w, base) in enumerate([(3, IN), (4, STR), (5, PACK), (7, OUT), (6, H), (8, HOUT)]):
    args += ["-poke", f"{0x20020 + 8 * k:#x}={w}", "-poke", f"{0x20024 + 8 * k:#x}=0"]
for k, v in enumerate(words([b & 0xff for b in inb])):
    args += ["-poke", f"{IN + 4 * k:#x}={v}"]
for k, v in enumerate(words(text)):
    args += ["-poke", f"{STR + 4 * k:#x}={v}"]
hv = [0 if i % 3 == 0 else (i * 1000 - 9000) for i in range(N)]
for k, v in enumerate(words(b"".join(struct.pack("<h", x) for x in hv))):
    args += ["-poke", f"{H + 4 * k:#x}={v}"]
for k in range(N // 2):
    args += ["-poke", f"{HOUT + 4 * k:#x}=3735928559", "-peek", f"{HOUT + 4 * k:#x}"]
for k in range(N // 4 + 1):           # one guard word past the packed bytes
    args += ["-poke", f"{PACK + 4 * k:#x}=3735928559", "-peek", f"{PACK + 4 * k:#x}"]
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
hello = len("Hello, CCV!")
for i in range(N):
    s = sum(inb[(i + k) & 15] for k in range(4))
    crc = 0
    for k in range(4):
        crc ^= inb[(i * 3 + k) & 15] & 0xff
        for _ in range(8):
            crc = ((crc << 1) ^ 0x07) & 0xff if crc & 0x80 else (crc << 1) & 0xff
    want = [s, crc, (hello - (i & 3)) * 1000 + ord("!"), 231 - i]
    have = [s32(got.get(OUT + 16 * i + 4 * k, 0)) for k in range(4)]
    if have != want:
        bad.append(f"lane {i}: {have}, want {want}")
want_pack = words([(i * 7 + 1) & 0xff for i in range(N)]) + [3735928559]
have_pack = [got.get(PACK + 4 * k) for k in range(N // 4 + 1)]
if have_pack != want_pack:
    bad.append(f"packed bytes {[hex(x or 0) for x in have_pack]}, want {[hex(x) for x in want_pack]}")
poison = struct.pack("<I", 3735928559)
want_h = words(b"".join(struct.pack("<h", x) if x else poison[2 * (i % 2):2 * (i % 2) + 2]
                        for i, x in enumerate(hv)))
have_h = [got.get(HOUT + 4 * k) for k in range(N // 2)]
if have_h != want_h:
    bad.append(f"shorts {[hex(x or 0) for x in have_h[:4]]}, want {[hex(x) for x in want_h[:4]]}")
if bad:
    print(f"{len(bad)} wrong; {bad[0]}")
else:
    print("ok", next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?"))
PY
}

fail=0
out=$(run)
case "$out" in
  ok*) echo "  PASS  bytes.cu: signed and unsigned bytes, a string, .shared, the frame, and 32 packed byte stores on 32 lanes (${out#ok } issue groups)" ;;
  *)   echo "  FAIL  bytes.cu: $out"; fail=1 ;;
esac
for c in -ccv-test-bytes-at-32 "-ccv-test-i16-legal -ccv-test-no-sized"; do
  out=$(run $c)
  case "$out" in
    ok*) echo "  FAIL  control $c still computed every lane right"; fail=1 ;;
    *" wrong; "*|"did not run"*) echo "  PASS  control $c is caught: $out" ;;
    *)   echo "  FAIL  control $c broke something else: $out"; fail=1 ;;
  esac
done
exit $fail
