#!/usr/bin/env bash
# Exactness check for the float-reciprocal division sequence (F-48, O-31).
#
# A reciprocal-based integer division is only useful if it is EXACT, and the
# ways it fails are concentrated in places a casual test never reaches: d = 1,
# where the 2^32 scaling saturates; d = 0, which is poison but must not hang;
# powers of two either side of a rounding boundary; and operands near 2^32
# where the float estimate has the least room.
#
# So this runs the real kernel on the simulator against Python's exact integer
# division, over the edge cases and a large pseudo-random sample.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

build/ccv-llc test/accept/divide-all.ll -o "$TMP/d.o" -obj || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/d.o" "$TMP/d.bin" || exit 1

BATCHES=${1:-40}
python3 - "$TMP/d.bin" "$BATCHES" <<'PY'
import random, struct, subprocess, sys
binf, batches = sys.argv[1], int(sys.argv[2])
M = 0xffffffff
def s32(u): return u - (1 << 32) if u & 0x80000000 else u

# Edge cases first, then random. The edges are where this algorithm breaks.
edge = [(0,1),(1,1),(M,1),(M,2),(M,M),(1,M),(0,M),(M,3),(2**31,1),(2**31,2),
        (2**31-1,2**31),(2**31,2**31),(2**32-1,2**31-1),(7,7),(6,7),(8,7),
        (2**24,2**24),(2**24+1,2**24),(2**16,2**16-1),(0xdeadbeef,0xcafe),
        (M,0x7fffffff),(0x80000000,0xffffffff),(3,2),(2,3),(100,10)]
rnd = random.Random(20260913)
pairs = list(edge)
while len(pairs) < batches * 32:
    # Mix magnitudes deliberately: uniform 32-bit alone almost never produces
    # a small divisor, which is where the estimate is tightest.
    b = rnd.choice([4, 8, 12, 16, 20, 24, 28, 32])
    pairs.append((rnd.getrandbits(rnd.choice([4,8,16,24,32])),
                  max(1, rnd.getrandbits(b))))
pairs = pairs[:batches * 32]

bad = 0
for g in range(0, len(pairs), 32):
    chunk = pairs[g:g+32]
    args = ["-poke", "0x20020=3"]
    for i, (n, d) in enumerate(chunk):
        args += [f"-poke {0x30000+4*i}={n}", f"-poke {0x30400+4*i}={d}"]
    for base in (0x30800, 0x30c00, 0x31000, 0x31400):
        args += [f"-peek {base+4*i}" for i in range(len(chunk))]
    out = subprocess.run(["build/ccv-sim", binf, *" ".join(args).split()],
                         capture_output=True, text=True)
    got = [int(x) for x in
           __import__("re").findall(r"= (\d+)", out.stdout)]
    if len(got) < 4 * len(chunk):
        print(f"  FAIL  simulator produced {len(got)} results, expected "
              f"{4*len(chunk)}"); sys.exit(1)
    for i, (n, d) in enumerate(chunk):
        uq, ur = got[i], got[len(chunk)+i]
        sq, sr = got[2*len(chunk)+i], got[3*len(chunk)+i]
        wuq, wur = n // d, n % d
        checks = [("udiv", uq, wuq), ("urem", ur, wur)]
        sn, sd = s32(n), s32(d)
        # sdiv(INT32_MIN, -1) overflows i32 and is POISON in LLVM, so there is
        # no right answer to check against. Hardware returns INT32_MIN and so
        # does this; the case is skipped rather than pretended otherwise.
        if not (sn == -2**31 and sd == -1):
            wsq = abs(sn) // abs(sd) * (1 if (sn < 0) == (sd < 0) else -1)
            wsr = sn - wsq * sd
            checks += [("sdiv", s32(sq), wsq), ("srem", s32(sr), wsr)]
        for name, g_, w in checks:
            if g_ != w:
                if bad < 8:
                    print(f"  FAIL  {name}({n}, {d}) = {g_}, want {w}")
                bad += 1
print(f"  {'FAIL' if bad else 'PASS'}  {len(pairs)} operand pairs x 4 "
      f"operations, {bad} wrong")
sys.exit(1 if bad else 0)
PY
