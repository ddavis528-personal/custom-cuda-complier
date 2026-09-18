#!/usr/bin/env bash
# `dp4.ss` computes what four MACs compute, and `dp4.acc` computes the same.
#
# F-121 formed the dot product in a DAG combine rather than from an intrinsic,
# which means the compiler is asserting that a particular tree of shifts,
# sign-extends, multiplies and adds means `dp4`. Nothing about that assertion
# is checked by the encoding gate: a combine that picks the wrong byte, or the
# wrong operand order, or drops the accumulator, produces a perfectly valid
# instruction computing the wrong number. So execute it against a reference
# that shares no code with either the combine or the simulator.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

./tools/cuda-to-asm.sh test/cuda/dp4.cu "$TMP/d.s" "$TMP/d" >/dev/null 2>&1 \
  || { echo "  FAIL  dp4.cu did not compile"; exit 1; }
build/ccv-llc "$TMP/d-lowered.ll" -o "$TMP/d.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/d.o" "$TMP/d.bin" || exit 1

# The combine has to have fired, or this test passes by computing the long way.
n=$(grep -cE '^\s*dp4\.(ss|acc)' "$TMP/d.s")
if [ "$n" -eq 0 ]; then
  echo "  FAIL  no dp4 instruction emitted -- the combine did not fire, so the"
  echo "        execution below would prove nothing about it"
  exit 1
fi

python3 - "$TMP/d.bin" "$n" <<'PY'
import random, re, subprocess, sys
binf, ndp4 = sys.argv[1], int(sys.argv[2])
LAUNCH, C, A, B = 0x20000, 0x30000, 0x40000, 0x50000
N = 32
random.seed(4)
# Signed bytes across the whole range, including the sign-bit corners: a
# combine that reads a byte unsigned agrees with a signed one on 0..127 and
# nowhere else, so a small-positive test would not see it.
def word():
    return sum((random.choice([-128, -1, 0, 1, 127] +
                              [random.randint(-128, 127)]) & 0xFF) << (8 * k)
               for k in range(4))
a = [word() for _ in range(N)]
b = [word() for _ in range(N)]
c = [random.randint(-1000, 1000) & 0xFFFFFFFF for _ in range(N)]

pokes = ["-poke", f"{hex(LAUNCH)}=32"]
for slot, val in ((0x20, C >> 16), (0x28, A >> 16), (0x30, B >> 16), (0x38, N)):
    pokes += ["-poke", f"{hex(LAUNCH + slot)}={val}"]
for i in range(N):
    pokes += ["-poke", f"{hex(A + i * 4)}={a[i]}"]
    pokes += ["-poke", f"{hex(B + i * 4)}={b[i]}"]
    pokes += ["-poke", f"{hex(C + i * 4)}={c[i]}"]
peeks = [x for i in range(N) for x in ("-peek", hex(C + i * 4))]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                   capture_output=True, text=True)
got = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
if len(got) != N:
    print(f"  FAIL  simulator returned {len(got)} words, expected {N}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

def sb(w, k):                     # byte k of w, as a signed 8-bit value
    v = (w >> (8 * k)) & 0xFF
    return v - 256 if v & 0x80 else v

bad = 0
for i in range(N):
    want = (c[i] + sum(sb(a[i], k) * sb(b[i], k) for k in range(4))) & 0xFFFFFFFF
    if got[i] != want:
        print(f"  FAIL  c[{i}] = {got[i]}, want {want}")
        bad = 1
        if bad > 3:
            break
if bad:
    sys.exit(1)
print(f"  PASS  dp4: {N} lanes correct against a four-MAC reference "
      f"({ndp4} dp4 instruction(s) emitted)")
PY
