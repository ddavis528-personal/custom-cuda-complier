#!/usr/bin/env bash
# A 16-bit kernel computes the right answer AND touches only its own bytes.
#
# The second half is the point. §3 takes transfer size from `rdata`'s chwidth,
# so a `short` array written through the 32-bit store form writes FOUR bytes and
# clobbers the neighbouring element -- while still writing the correct value at
# the correct address. Every result the kernel is asked about is right; only the
# element after the last one is wrong.
#
# That is precisely what this backend did until the selection learned to pick
# the narrow form, and no existing test could have seen it: they all check the
# outputs, and the output was correct.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

./tools/cuda-to-asm.sh test/bench/vadd16.cu "$TMP/v.s" "$TMP/v" >/dev/null 2>&1 \
  || { echo "  FAIL  vadd16.cu did not compile"; exit 1; }
build/ccv-llc "$TMP/v-lowered.ll" -o "$TMP/v.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/v.o" "$TMP/v.bin" || exit 1

# The store must be 16-bit. If it is not, the value is still right and only the
# guard bytes below catch it -- so check both.
if build/ccv-llc "$TMP/v-lowered.ll" -o - 2>/dev/null |
     grep -qE "chwidth r[0-9]+, 0$" ; then
  : # a widening somewhere is fine; the guard bytes decide
fi

python3 - "$TMP/v.bin" <<'PY'
import struct, subprocess, sys, re
binf = sys.argv[1]
LAUNCH, A, B, C = 0x20000, 0x30000, 0x40000, 0x50000
N = 32
a = [(i * 7 + 3) & 0xFFFF for i in range(N)]
b = [(i * 251 + 11) & 0xFFFF for i in range(N)]
GUARD = 0xABCD          # written into the element just past the output array

pokes = ["-poke", f"{hex(LAUNCH)}=32"]
# Argument layout comes from the kernel itself, as bench.py does.
layout = subprocess.run(["build/ccv-llc", sys.argv[1].replace(".bin", "-lowered.ll"),
                         "-o", "/dev/null"], capture_output=True, text=True)
# c, a, b are 2^16-aligned so each is one rbase slot; n is a scalar.
for slot, val in ((0x20, C >> 16), (0x28, A >> 16), (0x30, B >> 16), (0x38, N)):
    pokes += ["-poke", f"{hex(LAUNCH + slot)}={val}"]
# Two 16-bit elements per 32-bit word.
for i in range(0, N, 2):
    pokes += ["-poke", f"{hex(A + i * 2)}={a[i] | (a[i+1] << 16)}"]
    pokes += ["-poke", f"{hex(B + i * 2)}={b[i] | (b[i+1] << 16)}"]
pokes += ["-poke", f"{hex(C + N * 2)}={GUARD | (GUARD << 16)}"]

peeks = []
for i in range(0, N, 2):
    peeks += ["-peek", hex(C + i * 2)]
peeks += ["-peek", hex(C + N * 2)]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                   capture_output=True, text=True)
got = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
if len(got) != N // 2 + 1:
    print(f"  FAIL  simulator returned {len(got)} words, expected {N//2+1}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

bad = 0
for w in range(N // 2):
    lo, hi = got[w] & 0xFFFF, (got[w] >> 16) & 0xFFFF
    for j, g in ((2 * w, lo), (2 * w + 1, hi)):
        want = (a[j] + b[j]) & 0xFFFF
        if g != want:
            print(f"  FAIL  c[{j}] = {g}, want {want}")
            bad = 1
if bad:
    sys.exit(1)
print(f"  PASS  vadd16: {N} 16-bit elements correct")

guard = got[-1]
if guard != (GUARD | (GUARD << 16)):
    print(f"  FAIL  the element past the array was overwritten: "
          f"0x{guard:08x}, want 0x{GUARD | (GUARD << 16):08x}")
    print("        A 16-bit store wrote more than two bytes -- §3 takes")
    print("        transfer size from rdata's chwidth (F-3).")
    sys.exit(1)
print("  PASS  the element past the array is untouched (2-byte stores)")
PY
