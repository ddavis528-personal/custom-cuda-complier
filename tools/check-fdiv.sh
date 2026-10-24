#!/usr/bin/env bash
# IEEE fp32 division, 1.0f/x and sqrtf, executed (F-49, O-36, F-62, F-178,
# IS-12).
#
# The claim is bit-exactness at every input -- zeros, infinities, NaN (the
# canonical one, O-66), subnormal operands and results -- not an error bound,
# so each result is compared with the exact rational answer rounded once
# (tools/nfp_ref.py). The machine runs twice: with the SFU correctly rounded,
# and with -sfu-error-ulps 2, its rcp, rsqrt and sqrt each up to 2 ulps off,
# as IS-12 lets a real unit be.
#
# tools/model-ieee-sfu checks the ALGORITHM, exhaustively where it can. This
# checks the MACHINE: that what the backend emitted, encoded and executed is
# that algorithm. Its control, ccv-llc -ccv-test-fdiv-no-specials, is the
# divide without its special cases, as it was before F-178.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
for k in fdiv-all sqrt-rcp; do
  build/ccv-llc "test/accept/$k.ll" -o "$TMP/$k.o" -obj || exit 1
  llvm-objcopy -O binary --only-section=.text "$TMP/$k.o" "$TMP/$k.bin" || exit 1
done
build/ccv-llc test/accept/fdiv-all.ll -o "$TMP/ctl.o" -obj -ccv-test-fdiv-no-specials || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/ctl.o" "$TMP/ctl.bin" || exit 1

python3 - "$TMP" "${1:-40}" <<'PY'
import math, random, re, subprocess, sys
from fractions import Fraction as Q
sys.path.insert(0, "tools")
import nfp_ref as R
tmp, batches = sys.argv[1], int(sys.argv[2])
F32 = (0, 0)
LAUNCH, WIN = 0x20000, 0x30000

def val(x):
    return R.decode(F32, x)

def ref_div(a, b):
    x, y = val(a), val(b)
    if "nan" in (x.k, y.k) or (x.k == y.k == "inf") or (x.k == y.k == "fin" and x.q == 0 == y.q):
        return 0x7FFFFFFF
    s = 0x80000000 if x.neg != y.neg else 0
    if x.k == "inf" or (y.k == "fin" and y.q == 0):
        return s | 0x7F800000
    if y.k == "inf" or x.q == 0:
        return s
    return R.encode(F32, R.V("fin", x.neg != y.neg, x.q / y.q))

def ref_sqrt(a):
    x = val(a)
    if x.k == "nan" or (x.neg and not (x.k == "fin" and x.q == 0)):
        return 0x7FFFFFFF
    if x.k == "inf" or x.q == 0:
        return a
    # The exact root of x, rounded once: sqrt(n/d) = sqrt(n*d)/d, and the
    # integer root of n*d*4^k gives enough bits, with the remainder as sticky.
    n, d = x.q.numerator, x.q.denominator
    k = 60
    v = n * d * 4 ** k
    r = math.isqrt(v)
    q = Q(r, d * 2 ** k)
    if r * r != v:                     # strictly between r and r + 1: sticky
        q += Q(1, d * 2 ** (k + 1))
    return R.encode(F32, R.V("fin", False, q))

edge = [0, 0x80000000, 1, 2, 3, 0x80000001, 0x007FFFFF, 0x00800000, 0x00800001,
        0x3F800000, 0xBF800000, 0x40000000, 0x3FFFFFFF, 0x7F7FFFFF, 0xFF7FFFFF,
        0x7F800000, 0xFF800000, 0x7FC00000, 0xFFFFFFFF, 0x0B800000, 0x73800000,
        0x4B800001, 0x33800000, 0x00400000, 0x3EAAAAAB]
rng = random.Random(20261023)
def draw():
    r = rng.random()
    if r < 0.2: return rng.choice(edge)
    if r < 0.35: return rng.getrandbits(23) | (rng.getrandbits(1) << 31)     # subnormal
    return rng.getrandbits(32)

def run(binf, ins, outs, extra=()):
    """ins: list of (word index, value) per lane chunk; returns peeked words."""
    got = []
    for g in range(0, len(ins), 32):
        chunk = ins[g:g + 32]
        pokes = ["-poke", f"{hex(LAUNCH)}=32", "-poke", f"{hex(LAUNCH + 24)}=256",
                 "-poke", f"{hex(LAUNCH + 0x20)}={WIN >> 16}"]
        for i, vs in enumerate(chunk):
            for off, v in vs:
                pokes += ["-poke", f"{hex(WIN + (off + i) * 4)}={v}"]
        peeks = [x for i in range(len(chunk)) for o in outs for x in ("-peek", hex(WIN + (o + i) * 4))]
        r = subprocess.run(["build/ccv-sim", binf, "-threads", str(len(chunk)), *pokes, *peeks, *extra],
                           capture_output=True, text=True)
        v = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
        if len(v) != len(peeks) // 2:
            print("  FAIL  the simulator did not run: " + (r.stderr or r.stdout).strip()[-200:])
            sys.exit(1)
        got += [tuple(v[i * len(outs):(i + 1) * len(outs)]) for i in range(len(chunk))]
    return got

pairs = [(a, b) for a in edge for b in edge]
while len(pairs) < 32 * batches + len(edge) ** 2:
    pairs.append((draw(), draw()))
xs = edge + [draw() for _ in range(32 * batches)]
wdiv = [ref_div(a, b) for a, b in pairs]
wsq = [(ref_sqrt(x), ref_div(0x3F800000, x)) for x in xs]
fail = 0
for extra, tag in (((), "exact SFU"), (("-sfu-error-ulps", "2"), "SFU off by up to 2 ulps")):
    got = run(f"{tmp}/fdiv-all.bin", [((0, a), (256, b)) for a, b in pairs], [512], extra)
    bad = [(p, g[0], w) for p, g, w in zip(pairs, got, wdiv) if g[0] != w]
    got2 = run(f"{tmp}/sqrt-rcp.bin", [((0, x),) for x in xs], [256, 512], extra)
    bad2 = [(x, g, w) for x, g, w in zip(xs, got2, wsq) if g != w]
    if bad or bad2:
        fail = 1
        if bad:
            (a, b), g, w = bad[0]
            print(f"  FAIL  {tag}: {len(bad)}/{len(pairs)} divisions wrong; "
                  f"first {a:08x} / {b:08x} -> {g:08x}, want {w:08x}")
        if bad2:
            x, g, w = bad2[0]
            print(f"  FAIL  {tag}: {len(bad2)}/{len(xs)} sqrt or 1/x wrong; "
                  f"first {x:08x} -> {g[0]:08x} {g[1]:08x}, want {w[0]:08x} {w[1]:08x}")
    else:
        print(f"  PASS  {tag}: {len(pairs)} divisions and {len(xs)} each of sqrtf and "
              f"1.0f/x correctly rounded, every operand class")
got = run(f"{tmp}/ctl.bin", [((0, a), (256, b)) for a, b in pairs], [512])
n = sum(g[0] != w for g, w in zip(got, wdiv))
print(f"  PASS  control -ccv-test-fdiv-no-specials is caught: {n} wrong" if n
      else "  FAIL  control -ccv-test-fdiv-no-specials still agreed")
sys.exit(fail or not n)
PY
