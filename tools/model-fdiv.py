#!/usr/bin/env python3
"""Is the software fp32 divide correctly rounded, and exactly where?

F-49: only `1.0f/x` selected, to `rcp.f32`; a general `a/b` was a hard "cannot
select". CUDA's default `/` on floats is IEEE-correct, so this is a
compatibility gap. The design decision was to build no hardware divider in the
first implementation -- its latency would complicate scheduling -- so the
quotient is a software sequence over `rcp.f32` and `ffma`.

    ea, eb = exponent(a), exponent(b)     am, bm = a, b with exponent forced to 0
    y  = rcp(bm)                          q  = am * y
    y  = fma(y, fma(-bm, y, 1), y)   x2   r  = fma(-bm, q, am)      exact residual
                                          qm = fma(r, y, q)         one rounding
    result = qm * 2^(k/2) * 2^(k - k/2)   where k = ea - eb

Two parts do the work. The FMA residual is what makes the result correctly
rounded rather than merely close: `fma(-b, q, a)` is the exact remainder because
FMA rounds once. And forcing both exponents to zero is what keeps every
intermediate in range -- the reciprocal, the product and the residual all sit
near 1 regardless of how large or small the operands were.

THE BOUNDARY THIS REPORTS IS THE POINT. The final scalbn is two multiplies, and
when the result is subnormal the last one rounds a value that was already
rounded. Double rounding, 1 ulp, and not fixable with multiplies. So the claim
is "correctly rounded whenever the result is normal" -- measured here, not
asserted, and the gate fails if either half of that stops being true.
"""
import argparse
import math
import random
import struct
from fractions import Fraction


def f32(x):
    """Round to fp32, overflowing to infinity as the hardware does."""
    try:
        return struct.unpack("f", struct.pack("f", x))[0]
    except OverflowError:
        return math.copysign(math.inf, x)


def round_f32(fr):
    """Round an exact rational to fp32, nearest-even, in a single step.

    Normal:    value = n * 2^(e-23),  n = round(frac * 2^23),  frac in [1,2)
    Subnormal: value = n * 2^-149,    n = round(frac * 2^(e+149))

    Getting the subnormal scale wrong here reported two thousand failures that
    were the reference's, not the sequence's -- and worse, it mis-sorted cases
    into the "result normal" bucket, so the headline number was measuring the
    wrong population.
    """
    if fr == 0:
        return 0.0
    sign, fr = (-1.0, -fr) if fr < 0 else (1.0, fr)
    e = 0
    while fr >= 2:
        fr /= 2
        e += 1
    while fr < 1:
        fr *= 2
        e -= 1

    if e >= -126:                                   # normal
        n, scale = fr * (1 << 23), e - 23
    else:                                           # subnormal
        shift = e + 149
        if shift < 0:
            return sign * 0.0
        n, scale = fr * (1 << shift), -149

    whole = int(n)
    rem = n - whole
    if rem > Fraction(1, 2) or (rem == Fraction(1, 2) and whole % 2):
        whole += 1
    return f32(sign * float(whole) * 2.0 ** scale)


B = lambda x: struct.unpack("I", struct.pack("f", f32(x)))[0]
FB = lambda b: struct.unpack("f", struct.pack("I", b & 0xFFFFFFFF))[0]
P2 = lambda k: FB((k + 127) << 23)
TINY = 1.1754943508222875e-38            # smallest normal fp32
NORMAL = lambda v: math.isfinite(v) and abs(v) >= TINY


def fma(a, b, c):
    """One rounding, as `ffma` gives -- and ONE, not two.

    Routing the exact product through a Python float first would round to fp64
    and then to fp32. That double rounding turned a value a hair above a
    tie into the tie itself, and reported the sequence as wrong on
    1.0 / 16777215.0 when the sequence was right. The reference has to round
    from the exact rational in a single step or it is not a reference.
    """
    if not (math.isfinite(a) and math.isfinite(b) and math.isfinite(c)):
        return f32(a * b + c)
    return round_f32(Fraction(a) * Fraction(b) + Fraction(c))



def divide(a, b):
    ea, eb = (B(a) >> 23) & 0xFF, (B(b) >> 23) & 0xFF
    am = FB((B(a) & 0x807FFFFF) | (127 << 23))
    bm = FB((B(b) & 0x807FFFFF) | (127 << 23))
    y = f32(1.0 / bm)                                # rcp.f32
    for _ in range(2):
        y = fma(y, fma(-bm, y, 1.0), y)
    q = f32(am * y)
    r = fma(-bm, q, am)
    qm = fma(r, y, q)
    k = ea - eb
    k1 = int(k / 2)                                  # toward zero: same sign
    return f32(f32(qm * P2(k1)) * P2(k - k1))


def reference(a, b):
    return round_f32(Fraction(a) / Fraction(b))


def sample(n, pred, seed=20260914):
    rng = random.Random(seed)
    out = []
    while len(out) < n:
        x, y = FB(rng.getrandbits(32)), FB(rng.getrandbits(32))
        if NORMAL(x) and NORMAL(y) and pred(x, y):
            out.append((x, y))
    return out


def specials():
    # Every value forced through fp32 first. Listing 2^24+1 without rounding it
    # made the reference divide by a number the sequence never saw, and the
    # harness reported an algorithm failure that was its own.
    v = [f32(x) for x in
         (1.0, 2.0, 0.5, 3.0, -1.0, -7.0, math.pi, 1e-30, 1e30, TINY, -TINY,
          3.4028234663852886e38, 2.0 ** 24, 2.0 ** 24 + 1, 2.0 ** 24 - 1)]
    for a in v:
        for b in v:
            yield a, b


def run(pairs):
    bad = []
    for x, y in pairs:
        got, want = divide(x, y), reference(x, y)
        if B(got) != B(want):
            bad.append((x, y, got, want))
    return bad


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--samples", type=int, default=40000)
    a = ap.parse_args()
    fail = 0

    # 1. The claim: correctly rounded whenever the result is normal.
    pairs = sample(a.samples, lambda x, y: NORMAL(reference(x, y)))
    pairs += [(x, y) for x, y in specials() if NORMAL(reference(x, y))]
    bad = run(pairs)
    print(f"  result normal    : {len(pairs) - len(bad)}/{len(pairs)} correctly rounded")
    if bad:
        x, y, got, want = bad[0]
        print(f"      FAIL {x!r} / {y!r}: got {got!r}, want {want!r}")
        fail = 1

    # 2. The known gap, measured rather than hand-waved. A regression here means
    #    the gap grew, which is worth knowing even though it is not a failure.
    pairs = sample(a.samples // 4, lambda x, y: not NORMAL(reference(x, y)))
    bad = run(pairs)
    worst = max((abs(B(g) - B(w)) for _, _, g, w in bad), default=0)
    print(f"  result subnormal : {len(bad)}/{len(pairs)} off, worst {worst} ulp "
          f"(known gap -- double rounding in the final scale, F-62)")
    if worst > 1:
        print(f"      FAIL the subnormal gap is supposed to be at most 1 ulp")
        fail = 1
    return fail


if __name__ == "__main__":
    raise SystemExit(main())
