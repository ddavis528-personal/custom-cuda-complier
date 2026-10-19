#!/usr/bin/env bash
# sgemm executes, and computes a matrix product (F-134).
#
# Until this existed, `sgemm` had never been RUN. It is not in bench.py's ARGS
# table, so every check it passed -- instruction counts, spill counts, the tile
# sweep, the register-pressure argument the GPR decision rests on -- was a check
# on its text. The first time it was executed it hung: O-33's lane-0 masking had
# computed the `bpr` division in lane 0 only and not broadcast the result, the
# unmasked compare that reads it disagreed across lanes, lane 0 left the K loop
# while the other 31 stayed in it, and those 31 waited at a `bar.wait` for a
# lane that was never going to arrive.
#
# So this checks two things that a static count cannot: that it terminates, and
# that the numbers are right.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS="-Itest/bench -DCCV_ALIGNED -DTM=1 -DTN=1" ./tools/cuda-to-asm.sh test/cuda/sgemm.cu \
    "$TMP/s.s" "$TMP/s" >/dev/null 2>&1 || {
  echo "  FAIL  sgemm.cu did not compile"; exit 1; }
build/ccv-llc "$TMP/s-lowered.ll" -o "$TMP/s.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/s.o" "$TMP/s.bin" || exit 1

python3 - "$TMP/s.bin" <<'PY'
import re, struct, subprocess, sys
binf = sys.argv[1]
LAUNCH, C, A, B = 0x20000, 0x30000, 0x40000, 0x50000
N = 8                      # one K-tile: KT is 8
BX, BY = 8, 4              # 32 threads cover BY rows x BX columns of C

def f2i(x): return struct.unpack("<I", struct.pack("<f", x))[0]
def i2f(x): return struct.unpack("<f", struct.pack("<I", x))[0]

# Small integers, exact in FP32, and asymmetric so a transposed or mis-strided
# access cannot agree with the reference by accident.
a = [[(r * 3 + k + 1) % 7 - 3 for k in range(N)] for r in range(N)]
b = [[(k * 5 + c * 2 + 1) % 5 - 2 for c in range(N)] for k in range(N)]

pokes = ["-poke", f"{hex(LAUNCH)}=32",
         "-poke", f"{hex(LAUNCH + 32)}={C >> 16}",
         "-poke", f"{hex(LAUNCH + 40)}={A >> 16}",
         "-poke", f"{hex(LAUNCH + 48)}={B >> 16}",
         "-poke", f"{hex(LAUNCH + 56)}={N}",
         "-poke", f"{hex(LAUNCH + 60)}=1"]          # bpr: one block per row
for r in range(N):
    for k in range(N):
        pokes += ["-poke", f"{hex(A + (r * N + k) * 4)}={f2i(float(a[r][k]))}"]
        pokes += ["-poke", f"{hex(B + (r * N + k) * 4)}={f2i(float(b[r][k]))}"]

peeks = []
for r in range(BY):
    for c in range(BX):
        peeks += ["-peek", hex(C + (r * N + c) * 4)]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks, "-max-steps",
                    "2000000"], capture_output=True, text=True)
if "step limit" in r.stderr:
    print("  FAIL  sgemm did not terminate -- lanes still active at the step")
    print("        limit, which is what a lane waiting at a barrier for a lane")
    print("        that already left the loop looks like")
    sys.exit(1)
got = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
if len(got) != BY * BX:
    print(f"  FAIL  simulator returned {len(got)} words, expected {BY*BX}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:200]); sys.exit(1)

bad = 0
for r_ in range(BY):
    for c in range(BX):
        want = float(sum(a[r_][k] * b[k][c] for k in range(N)))
        val = i2f(got[r_ * BX + c])
        if val != want:
            print(f"  FAIL  C[{r_}][{c}] = {val}, want {want}")
            bad += 1
            if bad > 3:
                sys.exit(1)
if bad:
    sys.exit(1)
print(f"  PASS  sgemm: {BY}x{BX} of C correct against a matrix-product reference")
PY
