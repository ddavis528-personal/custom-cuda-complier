#!/usr/bin/env python3
"""What precision must `rcp.u32` deliver, and what does the sequence cost?

The point of an integer reciprocal is to skip work the fp32 path is forced into.
fp32 has a 24-bit significand, so even a CORRECTLY ROUNDED rcp.f32 leaves an
error near 2^8 when scaled to 2^32 -- the Newton step is required by the format,
not by the unit's sloppiness. An integer reciprocal is not bounded that way.

So the question is not "how accurate can we make it" but "how accurate does it
have to be", for each sequence we might write. This answers that by brute force:
model rcp.u32 at N bits, run the sequence, and require an EXACT quotient over the
edge cases plus a large sample. No claim here is analytic.

Convention, chosen to match what the existing sequence already relies on:

    rcp.u32 d  ->  e, an UNDER-estimate of floor(2^32 / d)
                   with 0 <= floor(2^32/d) - e <= 2^(32-N)

Under-estimation is not a detail. The Newton step converges only from below: if e
ever exceeds 2^32/d then e*d wraps past 2^32 and the correction term becomes huge
instead of small. That is why the fp32 path scales by 0x4F7FFFFE (2^32(1-2^-23))
rather than by 2^32, and the same requirement lands on the hardware unit.
"""
import argparse
import random
import struct

M = 0xFFFFFFFF


def rcp_u32(d, bits):
    """An under-estimate of floor(2^32/d) with `bits` of RELATIVE accuracy.

    Relative, not absolute. A reciprocal unit produces a result with N correct
    leading bits; the absolute error therefore scales with the result, and a
    large divisor -- whose reciprocal is small -- is cheap to get right. Modelling
    a fixed absolute slack instead says a 16-bit unit returns garbage for
    d = 2^31, where the true answer is 2, and that is not a machine anyone would
    build. Getting this backwards made the first run of this script report that
    even the Newton path needs 31 bits, which is nonsense: Newton exists
    precisely to turn a cheap seed into an exact one.
    """
    if d == 0:
        return M
    exact = min((1 << 32) // d, M)
    if bits is None:                                 # a perfect seed, for reference
        return exact
    # e in [exact*(1 - 2^-bits), exact]; take the worst (lowest) member.
    return max(0, (exact * ((1 << bits) - 1)) >> bits)


F32 = lambda x: struct.unpack("f", struct.pack("f", x))[0]
SCALE = float.fromhex("0x1.fffffcp+31")   # 2^32(1 - 2^-23), the O-31 constant


def seq_fp32(n, d):
    """Today's sequence. 21 instructions; see CCVExpandDivision.

    fp32 rounding is emulated at every step -- computing this in Python floats
    would be fp64 and would silently model a machine we are not building.
    """
    if d == 0:
        return None
    e = int(F32(F32(1.0) / F32(float(d))) * SCALE) & M
    t = (0 - e * d) & M
    e = (e + (((e * t) >> 32) & M)) & M
    q = ((n * e) >> 32) & M
    rem = (n - q * d) & M
    for _ in range(2):
        if rem >= d:
            q, rem = (q + 1) & M, (rem - d) & M
    return q


def seq_newton(n, d, bits):
    """rcp.u32 seed, keep the Newton step, keep two corrections."""
    e = rcp_u32(d, bits)
    t = (0 - e * d) & M
    e = (e + (((e * t) >> 32) & M)) & M
    q = ((n * e) >> 32) & M
    rem = (n - q * d) & M
    for _ in range(2):
        if rem >= d:
            q, rem = (q + 1) & M, (rem - d) & M
    return q


def seq_direct(n, d, bits, corrections):
    """rcp.u32 seed, NO Newton step, `corrections` fixups."""
    e = rcp_u32(d, bits)
    q = ((n * e) >> 32) & M
    rem = (n - q * d) & M
    for _ in range(corrections):
        if rem >= d:
            q, rem = (q + 1) & M, (rem - d) & M
    return q


# Instruction counts, from the emitted assembly for one udiv (21 today).
#   fp32 seed          cvt, rcp, f48, fmul, cvt                       = 5
#   rcp.u32 seed       rcp                                            = 1
#   zero               movi r, 0 -- §4 has no 32-bit mul.lo, so a plain
#                      multiply is mad.lo with a zero addend               = 1
#   Newton             mad.lo, sub, mul.hi.u, add                     = 4
#   quotient+remainder mul.hi.u, mad.lo, sub                          = 3
#   each correction    setp, add, @p mov, sub, @p mov                 = 5
#   last correction    setp, add, @p mov -- the remainder is dead after  = 3
#
# Today's 21 is 5 + 1 + 4 + 3 + 5 + 3, which matches the emitted assembly
# instruction for instruction.
COST = dict(fp32_seed=5, int_seed=1, zero=1, newton=4, quot=3,
            corr=5, last_corr=3)


def cost(seed, newton, corrections):
    c = COST["fp32_seed" if seed == "fp32" else "int_seed"]
    c += COST["zero"] + COST["quot"]
    c += COST["newton"] if newton else 0
    if corrections:
        c += COST["corr"] * (corrections - 1) + COST["last_corr"]
    return c


def cases(samples, seed=20260914):
    rng = random.Random(seed)
    edge = [1, 2, 3, 7, 0xFFFF, 0x10000, 0x7FFFFFFF, 0x80000000, M, M - 1]
    for d in edge:
        for n in edge + [0]:
            yield n, d
    for _ in range(samples):
        yield rng.getrandbits(32), rng.randint(1, M)
    # Powers of two and their neighbours: where floor(2^32/d) is exact or nearly.
    for k in range(32):
        for dd in (1 << k, (1 << k) - 1, (1 << k) + 1):
            if 1 <= dd <= M:
                for n in (M, (1 << 31), dd, dd - 1, dd * 3):
                    yield n & M, dd


def check(fn, samples):
    for n, d in cases(samples):
        if fn(n, d) != n // d:
            return (n, d)
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--samples", type=int, default=200000)
    a = ap.parse_args()

    bad = check(lambda n, d: seq_fp32(n, d), a.samples)
    print(f"  today, fp32 seed + Newton + 2 corrections     "
          f"{cost('fp32', True, 2):>3} instrs   "
          f"{'EXACT' if bad is None else f'WRONG at {bad}'}")
    print()
    print("  rcp.u32 seed -- minimum accurate bits for an exact quotient")
    print()
    print(f"  {'sequence':<44}{'instrs':>7}   min bits")
    print("  " + "-" * 64)
    for label, newton, corr in (("+ Newton + 2 corrections", True, 2),
                                ("no Newton, 2 corrections", False, 2),
                                ("no Newton, 1 correction", False, 1),
                                ("no Newton, no correction", False, 0)):
        found = None
        for bits in list(range(1, 41)) + [None]:
            fn = ((lambda n, d, b=bits: seq_newton(n, d, b)) if newton
                  else (lambda n, d, b=bits, c=corr: seq_direct(n, d, b, c)))
            if check(fn, a.samples) is None:
                found = bits
                break
        else:
            found = "never"
        shown = ("exact seed only" if found is None else
                 str(found) if isinstance(found, int) else "never")
        print(f"  {label:<44}{cost('int', newton, corr):>7}   {shown}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
