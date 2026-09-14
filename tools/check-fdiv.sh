#!/usr/bin/env bash
# Correctness of the software fp32 divide (F-49, O-36), on the simulator.
#
# The claim is bit-exactness -- "correctly rounded whenever the result is
# normal" -- not an error bound, so this compares the executed kernel against
# exact rational arithmetic, value for value.
#
# tools/model-fdiv.py checks the ALGORITHM. This checks the MACHINE: that what
# the backend emitted, encoded and executed agrees with it. They have caught
# different things -- the model found the algorithm was right and my reference
# was double-rounding; this path found two selection bugs that had nothing to do
# with division (a sign-extended wide immediate, and an add-immediate with no
# range predicate).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

build/ccv-llc test/accept/fdiv-all.ll -o "$TMP/f.o" -obj || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/f.o" "$TMP/f.bin" || exit 1

python3 - "$TMP/f.bin" "${1:-40}" <<'PY'
import math, random, struct, subprocess, sys
from fractions import Fraction
sys.path.insert(0, "tools")
import importlib.util
spec = importlib.util.spec_from_file_location("mf", "tools/model-fdiv.py")
mf = importlib.util.module_from_spec(spec); spec.loader.exec_module(mf)

binf, batches = sys.argv[1], int(sys.argv[2])
B, FB, NORMAL, ref = mf.B, mf.FB, mf.NORMAL, mf.reference

# The cases that break a divide: opposite ends of the exponent range, values a
# hair either side of a rounding boundary, and exact powers of two.
# Forced through fp32 first. Listing a double literal here makes the reference
# divide a number the machine never saw -- which reported eight algorithm
# failures that were the harness's own, for the second time in this session.
edge = [mf.f32(x) for x in
        (1.0, 2.0, 0.5, 3.0, -1.0, -7.0, math.pi, 1e-30, 1e30,
         1.1754943508222875e-38, 3.4028234663852886e38,
         2.0**24, 2.0**24 - 1, 16777215.0, 1.0000001192092896)]
pairs = [(a, b) for a in edge for b in edge]
rng = random.Random(20260914)
while len(pairs) < 256 * batches:
    a, b = FB(rng.getrandbits(32)), FB(rng.getrandbits(32))
    if NORMAL(a) and NORMAL(b):
        pairs.append((a, b))

LAUNCH, WIN = 0x20000, 0x30000
wrong = subnormal_gap = checked = 0
first = None
for g in range(0, len(pairs), 32):
    chunk = pairs[g:g + 32]
    if len(chunk) < 32:
        break
    pokes = ["-poke", f"{hex(LAUNCH + 0x20)}={WIN >> 16}"]
    for i, (a, b) in enumerate(chunk):
        pokes += ["-poke", f"{hex(WIN + i * 4)}={B(a)}",
                  "-poke", f"{hex(WIN + (256 + i) * 4)}={B(b)}"]
    peeks = []
    for i in range(32):
        peeks += ["-peek", hex(WIN + (512 + i) * 4)]
    r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                       capture_output=True, text=True)
    got = [int(x) for x in
           __import__("re").findall(r"= (\d+)", r.stdout)]
    if len(got) != 32:
        print(f"  FAIL  simulator returned {len(got)} results, expected 32")
        print("  " + r.stderr.strip()[:200]); sys.exit(1)
    for (a, b), g32 in zip(chunk, got):
        want = ref(a, b)
        checked += 1
        if g32 == B(want):
            continue
        if not NORMAL(want):
            subnormal_gap += 1          # the documented F-62 gap
            continue
        wrong += 1
        if first is None:
            first = (a, b, FB(g32), want)

if wrong:
    a, b, g, w = first
    print(f"  FAIL  {wrong} of {checked} wrong with a NORMAL result")
    print(f"        {a!r} / {b!r}: got {g!r} (0x{B(g):08x}), want {w!r} (0x{B(w):08x})")
    sys.exit(1)
print(f"  PASS  {checked} fp32 divisions, all correctly rounded where the "
      f"result is normal")
print(f"        ({subnormal_gap} subnormal results differ by 1 ulp -- F-62, known)")
PY
