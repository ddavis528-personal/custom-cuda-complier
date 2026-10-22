"""
A reference for §4's FP formats, written from the specifications and nothing
else (CP-6): exact rationals (fractions.Fraction), so it shares no arithmetic
with ccv-sim's NarrowFP.h, which works in 128-bit integers.

Formats, by register width code (0 = 32, 1 = 16, 2 = 8, 3 = 4) and format code:
FP32, FP16 and BF16 are IEEE 754 binary32, binary16 and bfloat16; E4M3 and E5M2
are OCP OFP8 1.0; E2M1 is OCP MX 1.0. The arithmetic rules are §4's (O-53, O-56):
round as asked, subnormals kept, IEEE overflow at 16 and 32 bits, saturation to
max finite at 8 and 4, NaN as the format allows (E2M1's invalid result is +6).
"""
from fractions import Fraction as Q

# (bits, exponent bits, mantissa bits, bias, specials, saturates, NaN encoding)
FORMATS = {
    (0, 0): (32, 8, 23, 127, "ieee", False, 0x7FC00000),
    (1, 0): (16, 5, 10, 15, "ieee", False, 0x7E00),
    (1, 1): (16, 8, 7, 127, "ieee", False, 0x7FC0),
    (2, 0): (8, 4, 3, 7, "e4m3", True, 0x7F),
    (2, 1): (8, 5, 2, 15, "ieee", True, 0x7F),
    (3, 0): (4, 2, 1, 1, "none", True, 0x7),
}
NAN, INF = "nan", "inf"
WIDTH = {0: 32, 1: 16, 2: 8, 3: 4}


class V:
    """A value: kind 'fin' with an exact rational (sign kept for zero), 'inf' or 'nan'."""
    __slots__ = ("k", "neg", "q")

    def __init__(self, k, neg=False, q=Q(0)):
        self.k, self.neg, self.q = k, neg, q

    def val(self):
        return -self.q if self.neg else self.q


def decode(fmt, x):
    bits, eb, mb, bias, spec, _, _ = FORMATS[fmt]
    s = (x >> (bits - 1)) & 1
    e = (x >> mb) & ((1 << eb) - 1)
    m = x & ((1 << mb) - 1)
    emax = (1 << eb) - 1
    if spec == "ieee" and e == emax:
        return V(NAN if m else INF, bool(s))
    if spec == "e4m3" and e == emax and m == (1 << mb) - 1:
        return V(NAN, bool(s))
    if e == 0:
        q = Q(m, 1 << mb) * Q(2) ** (1 - bias)
    else:
        q = (1 + Q(m, 1 << mb)) * Q(2) ** (e - bias)
    return V("fin", bool(s), q)


def finite_values(fmt):
    """Every finite non-negative encoding with its value, in increasing order."""
    bits = FORMATS[fmt][0]
    out = []
    for x in range(1 << (bits - 1)):
        v = decode(fmt, x)
        if v.k == "fin":
            out.append((v.q, x))
    return out


_CACHE = {}


def encode(fmt, v, rnd="rn"):
    """Round a value into fmt. The candidate encodings are enumerated outright
    at 8 and 4 bits; at 16 and 32 bits the neighbours are found arithmetically.
    Either way the choice is made on exact rationals."""
    bits, eb, mb, bias, spec, sat, nan = FORMATS[fmt]
    sign = 1 << (bits - 1)
    if v.k == NAN:
        return nan
    if fmt not in _CACHE:
        _CACHE[fmt] = None
    maxq, maxx = max_finite(fmt)
    s = sign if v.neg else 0
    if v.k == INF:
        return s | maxx if sat else s | (((1 << eb) - 1) << mb)
    a = v.q                                   # magnitude
    if a == 0:
        return s
    lo, hi = neighbours(fmt, a)               # (q, x) below/at and above
    if hi is None:                            # beyond max finite
        lo_q, lo_x = lo
        over = True
    else:
        over = False
    if lo[0] == a:                            # exact, max finite included
        return s | lo[1]
    # Directed choice on the magnitude, by the sign.
    toward_zero = (rnd == "rz" or (rnd == "rp" and v.neg) or (rnd == "rm" and not v.neg))
    away = (rnd == "rp" and not v.neg) or (rnd == "rm" and v.neg)
    if over:
        # Above max finite: the IEEE "next" value is infinity, of ulp size.
        ulp = maxq - prev_finite(fmt, maxq)
        if sat:
            return s | maxx
        inf = s | (((1 << eb) - 1) << mb)
        if toward_zero:
            return s | maxx
        if away:
            return inf
        # Nearest: halfway to the next binade's first value, 2^(emax+1).
        return inf if a >= maxq + ulp / 2 else s | maxx
    if toward_zero:
        return s | lo[1]
    if away:
        return s | hi[1]
    mid = (lo[0] + hi[0]) / 2
    if a < mid:
        return s | lo[1]
    if a > mid:
        return s | hi[1]
    return s | (lo[1] if lo[1] % 2 == 0 else hi[1])


def max_finite(fmt):
    bits, eb, mb, bias, spec, _, _ = FORMATS[fmt]
    emax = (1 << eb) - 1
    if spec == "ieee":
        x = ((emax - 1) << mb) | ((1 << mb) - 1)
    elif spec == "e4m3":
        x = (emax << mb) | ((1 << mb) - 2)
    else:
        x = (emax << mb) | ((1 << mb) - 1)
    return decode(fmt, x).q, x


def prev_finite(fmt, q):
    lo, _ = neighbours(fmt, q - Q(1, 1 << 200))
    return lo[0]


def neighbours(fmt, a):
    """The largest finite encoding <= a and the smallest > a (None past max)."""
    bits, eb, mb, bias, spec, _, _ = FORMATS[fmt]
    maxq, maxx = max_finite(fmt)
    if a > maxq:
        return (maxq, maxx), None
    # The grid spacing at a: 2^(e - mb) for a's binade e, but never below the
    # subnormal step 2^(1 - bias - mb).
    e = 1 - bias
    while Q(2) ** (e + 1) <= a:
        e += 1
    step = Q(2) ** (e - mb)
    k = a // step                              # floor
    lo_q = k * step
    hi_q = lo_q + step
    return (lo_q, enc_exact(fmt, lo_q)), \
        ((hi_q, enc_exact(fmt, hi_q)) if hi_q <= maxq else None)


def enc_exact(fmt, q):
    """The encoding of an exactly representable non-negative value."""
    bits, eb, mb, bias, spec, _, _ = FORMATS[fmt]
    if q == 0:
        return 0
    e = 1 - bias
    while Q(2) ** (e + 1) <= q:
        e += 1
    if q < Q(2) ** (1 - bias):                 # subnormal
        m = q / Q(2) ** (1 - bias - mb)
        assert m.denominator == 1
        return int(m)
    m = q / Q(2) ** e - 1
    m = m * (1 << mb)
    assert m.denominator == 1
    return ((e + bias) << mb) | int(m)


def add(a, b, rnd="rn"):
    if a.k == NAN or b.k == NAN:
        return V(NAN)
    if a.k == INF and b.k == INF:
        return V(INF, a.neg) if a.neg == b.neg else V(NAN)
    if a.k == INF:
        return a
    if b.k == INF:
        return b
    s = a.val() + b.val()
    if s == 0:
        if a.q == 0 and b.q == 0 and a.neg == b.neg:
            return V("fin", a.neg)
        return V("fin", rnd == "rm")
    return V("fin", s < 0, abs(s))


def mul(a, b):
    n = a.neg != b.neg
    if a.k == NAN or b.k == NAN:
        return V(NAN)
    if a.k == INF or b.k == INF:
        if (a.k == "fin" and a.q == 0) or (b.k == "fin" and b.q == 0):
            return V(NAN)
        return V(INF, n)
    return V("fin", n, a.q * b.q)


def neg(a):
    return V(a.k, not a.neg, a.q)


def less(a, b):
    """a < b for non-NaN values, -0 below +0."""
    if a.k == INF or b.k == INF:
        ka = (1 if not a.neg else -1) if a.k == INF else 0
        kb = (1 if not b.neg else -1) if b.k == INF else 0
        if ka != kb:
            return ka < kb
        if ka != 0:
            return False
    if a.val() != b.val():
        return a.val() < b.val()
    return a.neg and not b.neg


def from_int(x, w, signed):
    x &= (1 << w) - 1
    if signed and x >> (w - 1):
        x -= 1 << w
    return V("fin", x < 0, Q(abs(x)))


def to_int(v, w, signed, rnd):
    lo, hi = (-(1 << (w - 1)), (1 << (w - 1)) - 1) if signed else (0, (1 << w) - 1)
    if v.k == NAN:
        return 0
    if v.k == INF:
        r = lo if v.neg else hi
    else:
        x = v.val()
        f = x.numerator // x.denominator           # floor
        frac = x - f
        if frac == 0:
            r = f
        elif rnd == "rz":
            r = f if x > 0 else f + 1
        elif rnd == "rm":
            r = f
        elif rnd == "rp":
            r = f + 1
        else:
            r = f if frac < Q(1, 2) else f + 1 if frac > Q(1, 2) else (f if f % 2 == 0 else f + 1)
        r = max(lo, min(hi, r))
    return r & ((1 << w) - 1)


ROUND = ["rn", "rz", "rm", "rp"]


def op(name, code, wd, wa, wb, wc, x, y, z):
    """One lane: name is the base operation, widths are width codes. Returns the
    destination element's bits, or 'F-FORMAT'."""
    if name.startswith("cvt"):
        _, d, s, r = name.split(":")
        d, s, r = int(d), int(s), int(r)
        if (s < 2 and (wa, s) not in FORMATS) or (d < 2 and (wd, d) not in FORMATS):
            return "F-FORMAT"
        v = decode((wa, s), x) if s < 2 else from_int(x, WIDTH[wa], s == 2)
        return encode((wd, d), v, ROUND[r]) if d < 2 else to_int(v, WIDTH[wd], d == 2, ROUND[r])
    used = [wd, wa] + ([wb] if name in ("fadd", "fsub", "fmul", "fmin", "fmax", "ffma") else []) \
        + ([wc] if name == "ffma" else [])
    if any((w, code) not in FORMATS for w in used):
        return "F-FORMAT"
    fd = (wd, code)
    a = decode((wa, code), x)
    if name in ("fneg", "fabs"):
        if wa == wd:
            sb = 1 << (FORMATS[fd][0] - 1)
            return x ^ sb if name == "fneg" else x & ~sb
        if a.k != NAN:
            a = V(a.k, (not a.neg) if name == "fneg" else False, a.q)
        return encode(fd, a)
    b = decode((wb, code), y)
    if name == "fadd":
        return encode(fd, add(a, b))
    if name == "fsub":
        return encode(fd, add(a, neg(b)))
    if name == "fmul":
        return encode(fd, mul(a, b))
    if name in ("fmin", "fmax"):
        if a.k == NAN and b.k == NAN:
            return FORMATS[fd][6]
        if a.k == NAN:
            return encode(fd, b)
        if b.k == NAN:
            return encode(fd, a)
        take_a = (not less(b, a)) if name == "fmin" else (not less(a, b))
        return encode(fd, a if take_a else b)
    c = decode((wc, code), z)
    return encode(fd, add(mul(a, b), c))
