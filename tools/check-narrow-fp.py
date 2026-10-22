#!/usr/bin/env python3
"""
Narrow FP in ccv-sim against an independent reference (CP-6).

ccv-sim's -fp-cases evaluates one lane of an FP-block operation or a conversion
through the same routine its step function uses (Interp::evalFp ->
NarrowFP.h). tools/nfp_ref.py computes the same from the specifications on
exact rationals. Every case must agree bit for bit, F-FORMAT included:

  - every pair of 8-bit operands (E4M3, E5M2) and of 4-bit operands (E2M1),
    for fadd, fsub, fmul, fmin and fmax, and every operand for fneg and fabs;
  - every E2M1 triple and 40,000 random 8-bit triples for ffma;
  - 20,000 random FP16 and BF16 pairs per operation, specials, subnormals and
    the largest values among them, and FP32 through the same path;
  - mixed widths (an 8-bit source with a 16-bit destination, and so on);
  - every conversion point of §4's product: all narrow sources exhaustively,
    into every destination width and format, at every rounding mode; sampled
    16- and 32-bit FP sources weighted to the narrow formats' range and their
    rounding midpoints; and integer sources at every width;
  - F-FORMAT for format code 1 at 32 and 4 bits.

Controls, which must fail: ccv-sim -fp-cases with -ccv-test-fp-ftz (subnormal
results flushed) and with -ccv-test-fp-no-saturate (narrow overflow wrapping
to NaN, the rule O-56 rejected).

Usage: check-narrow-fp.py [--quick]
"""
import os, random, subprocess, sys, tempfile
from fractions import Fraction as Q

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import nfp_ref as R

SIM = os.path.join(ROOT, "build/ccv-sim")
QUICK = "--quick" in sys.argv

# Fast exact encoding for the small formats: a sorted table of every finite
# non-negative value, searched by bisection. Same rule as R.encode.
import bisect
_TAB = {}


def table(fmt):
    if fmt not in _TAB:
        vals = R.finite_values(fmt)
        _TAB[fmt] = ([q for q, _ in vals], [x for _, x in vals])
    return _TAB[fmt]


_orig_encode = R.encode


def fast_encode(fmt, v, rnd="rn"):
    bits = R.FORMATS[fmt][0]
    if bits > 8 or v.k != "fin" or v.q == 0:
        return _orig_encode(fmt, v, rnd)
    qs, xs = table(fmt)
    if v.q > qs[-1]:
        return _orig_encode(fmt, v, rnd)
    i = bisect.bisect_right(qs, v.q) - 1
    s = (1 << (bits - 1)) if v.neg else 0
    if qs[i] == v.q:
        return s | xs[i]
    lo, hi = i, i + 1
    tz = rnd == "rz" or (rnd == "rp" and v.neg) or (rnd == "rm" and not v.neg)
    aw = (rnd == "rp" and not v.neg) or (rnd == "rm" and v.neg)
    if tz:
        return s | xs[lo]
    if aw:
        return s | xs[hi]
    mid = (qs[lo] + qs[hi]) / 2
    if v.q != mid:
        return s | xs[lo if v.q < mid else hi]
    return s | xs[lo if xs[lo] % 2 == 0 else hi]


R.encode = fast_encode

_DEC = {}
_dec0 = R.decode


def cached_decode(fmt, x):
    k = (fmt, x)
    if k not in _DEC:
        _DEC[k] = _dec0(fmt, x)
    return _DEC[k]


R.decode = cached_decode

BIN = {"fadd": ("FADD", "FADD_F1"), "fsub": ("FSUB", "FSUB_F1"), "fmul": ("FMUL", "FMUL_F1"),
       "fmin": ("FMIN", "FMIN_F1"), "fmax": ("FMAX", "FMAX_F1")}
UN = {"fneg": ("FNEG_F0", "FNEG_F1"), "fabs": ("FABS_F0", "FABS_F1")}
NAMED = {(0, 2, 0): "CVT_F32_S32", (0, 3, 0): "CVT_F32_U32", (2, 0, 1): "CVT_S32_F32",
         (3, 0, 1): "CVT_U32_F32", (2, 2, 0): "CVT_SEXT"}


def cvt_name(d, s, r):
    return NAMED.get((d, s, r), f"CVT_D{d}_S{s}_R{r}")


def edge(fmt):
    """Specials, zeros, subnormal and normal extremes, and their negatives."""
    bits, eb, mb, bias, spec, _, _ = R.FORMATS[fmt]
    xs = {0, 1, (1 << mb) - 1, 1 << mb, R.max_finite(fmt)[1],
          R.max_finite(fmt)[1] - 1, (bias << mb), ((bias + 1) << mb) | 1}
    if spec == "ieee":
        xs |= {((1 << eb) - 1) << mb, (((1 << eb) - 1) << mb) | 1,
               (((1 << eb) - 1) << mb) | (1 << (mb - 1))}
    sign = 1 << (bits - 1)
    return sorted(xs | {x | sign for x in xs})


def main():
    rng = random.Random(1)
    cases = []                                  # (sim line, reference thunk)

    def add(opc, w, xs, ref):
        cases.append((f"{opc} {w[0]} {w[1]} {w[2]} {w[3]} {xs[0]:x} {xs[1]:x} {xs[2]:x}", ref))

    narrow = [(2, 0), (2, 1), (3, 0)]
    for (wc, code) in narrow:
        n = 1 << R.WIDTH[wc]
        for name, opcs in BIN.items():
            for x in range(n):
                for y in range(n):
                    if QUICK and (x * n + y) % 7:
                        continue
                    add(opcs[code], (wc, wc, wc, 0), (x, y, 0),
                        (name, code, wc, wc, wc, 0, x, y, 0))
        for name, opcs in UN.items():
            for x in range(n):
                add(opcs[code], (wc, wc, 0, 0), (x, 0, 0), (name, code, wc, wc, 0, 0, x, 0, 0))
        opc = "FFMA_F1" if code else "FFMA_F0"
        trip = ([(a, b, c) for a in range(16) for b in range(16) for c in range(16)]
                if wc == 3 else
                [(rng.randrange(n), rng.randrange(n), rng.randrange(n))
                 for _ in range(4000 if QUICK else 40000)])
        for a, b, c in trip:
            add(opc, (wc, wc, wc, wc), (a, b, c), ("ffma", code, wc, wc, wc, wc, a, b, c))

    # 16 and 32 bits, sampled, specials and extremes weighted in.
    for (wc, code) in [(1, 0), (1, 1), (0, 0)]:
        bits = R.WIDTH[wc]
        pool = edge((wc, code))
        draw = lambda: rng.choice(pool) if rng.random() < 0.15 else rng.getrandbits(bits)
        k = 2000 if QUICK else 20000
        for name, opcs in BIN.items():
            for _ in range(k):
                x, y = draw(), draw()
                add(opcs[code], (wc, wc, wc, 0), (x, y, 0), (name, code, wc, wc, wc, 0, x, y, 0))
        for _ in range(k):
            x, y, z = draw(), draw(), draw()
            add("FFMA_F1" if code else "FFMA_F0", (wc,) * 4, (x, y, z),
                ("ffma", code, wc, wc, wc, wc, x, y, z))

    # Mixed widths: the code reads each register at its own width.
    for _ in range(2000 if QUICK else 20000):
        code = rng.randrange(2)
        ws = [w for w in (0, 1, 2) if (w, code) in R.FORMATS]
        wd, wa, wb = rng.choice(ws), rng.choice(ws), rng.choice(ws)
        x, y = rng.getrandbits(R.WIDTH[wa]), rng.getrandbits(R.WIDTH[wb])
        name = rng.choice(list(BIN))
        add(BIN[name][code], (wd, wa, wb, 0), (x, y, 0), (name, code, wd, wa, wb, 0, x, y, 0))

    # F-FORMAT: format code 1 at 32 and at 4 bits.
    for wc in (0, 3):
        add("FADD_F1", (wc, wc, wc, 0), (0, 0, 0), ("fadd", 1, wc, wc, wc, 0, 0, 0, 0))
        add("CVT_D1_S0_R0", (wc, 1, 0, 0), (0, 0, 0), ("cvt:1:0:0", 0, wc, 1, 0, 0, 0, 0, 0))

    # Conversions: every point, every width pairing.
    def srcs(wa, s):
        bits = R.WIDTH[wa]
        if bits <= 8:
            return range(1 << bits)
        if s >= 2:
            return [0, 1, (1 << bits) - 1, 1 << (bits - 1), (1 << (bits - 1)) - 1] + \
                   [rng.getrandbits(bits) for _ in range(300 if QUICK else 2000)]
        fmt = (wa, s)
        if fmt not in R.FORMATS:
            return [0]
        out = list(edge(fmt))
        # Values in the narrow formats' range, and their rounding midpoints.
        for nf in narrow:
            qs, _ = table(nf)
            for i in range(len(qs) - 1):
                for v in (qs[i], (qs[i] + qs[i + 1]) / 2):
                    for sgn in (False, True):
                        x = R.enc_exact(fmt, v) if exact_in(fmt, v) else None
                        if x is not None:
                            out.append(x | ((1 << (bits - 1)) if sgn else 0))
        out += [rng.getrandbits(bits) for _ in range(300 if QUICK else 3000)]
        return out

    def exact_in(fmt, v):
        try:
            R.enc_exact(fmt, v)
            return R.decode(fmt, R.enc_exact(fmt, v)).q == v
        except AssertionError:
            return False

    for d in range(4):
        for s in range(4):
            for r in range(4):
                if d >= 2 and s >= 2 and r:
                    continue
                for wd in range(4):
                    for wa in range(4):
                        if d < 2 and (wd, d) not in R.FORMATS:
                            continue
                        if s < 2 and (wa, s) not in R.FORMATS:
                            continue
                        for x in srcs(wa, s):
                            add(cvt_name(d, s, r), (wd, wa, 0, 0), (x, 0, 0),
                                (f"cvt:{d}:{s}:{r}", 0, wd, wa, 0, 0, x, 0, 0))

    with tempfile.TemporaryDirectory() as tmp:
        path = os.path.join(tmp, "cases.txt")
        with open(path, "w") as f:
            f.write("\n".join(c for c, _ in cases) + "\n")

        def sim(*extra):
            r = subprocess.run([SIM, "/dev/null", "-fp-cases", path, *extra],
                               capture_output=True, text=True)
            if r.returncode:
                return None
            return r.stdout.split()

        got = sim()
        if got is None or len(got) != len(cases):
            print(f"  FAIL  narrow FP: ccv-sim -fp-cases did not run")
            return 1
        want = []
        for _, ref in cases:
            v = R.op(*ref)
            want.append(v if isinstance(v, str) else f"{v:x}")
        bad = [(c, g, w) for (c, _), g, w in zip(cases, got, want) if g != w]
        if bad and os.environ.get("NFP_SHOW"):
            for c, g, w in bad[:40]:
                print("   ", c, "->", g, "ref", w)
        if bad:
            c, g, w = bad[0]
            print(f"  FAIL  narrow FP: {len(bad)} of {len(cases)} cases differ; first: "
                  f"{c} -> ccv-sim {g}, reference {w}")
            return 1
        print(f"  PASS  narrow FP: {len(cases)} cases agree with the reference bit for bit "
              "(every 8- and 4-bit pair, every conversion point, F-FORMAT)")
        fail = 0
        for ctl in ("-ccv-test-fp-ftz", "-ccv-test-fp-no-saturate"):
            g2 = sim(ctl)
            if g2 is None:
                print(f"  FAIL  control {ctl} did not run"); fail = 1; continue
            n = sum(1 for a, b in zip(g2, want) if a != b)
            if n:
                print(f"  PASS  control {ctl} is caught: {n} cases differ")
            else:
                print(f"  FAIL  control {ctl} still agreed everywhere"); fail = 1
        return fail


if __name__ == "__main__":
    sys.exit(main())
