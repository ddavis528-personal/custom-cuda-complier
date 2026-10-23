#!/usr/bin/env python3
"""The correctly rounded FP32 value of an SFU function, from mpmath at 400 bits.

Reads lines "<fn> <x-hex>" and prints "<fn> <x-hex> <result-hex>". Used once, to
judge the inputs where a double-precision reference is too near an FP32
midpoint to say which way the exact value rounds.
"""
import struct
import sys

from mpmath import mp

mp.prec = 400


def f32(bits):
    return struct.unpack("<f", struct.pack("<I", bits))[0]


def bits32(v):
    return struct.unpack("<I", struct.pack("<f", v))[0]


def round32(x):
    """Round to nearest even, into FP32's normal and subnormal range."""
    if x == 0:
        return 0
    s = 0x80000000 if x < 0 else 0
    a = abs(x)
    e = max(int(mp.floor(mp.log(a, 2))), -126)
    # floor(log2) can be off by one at 400 bits only for exact powers; fix up.
    while mp.mpf(2) ** e > a and e > -126:
        e -= 1
    while mp.mpf(2) ** (e + 1) <= a:
        e += 1
    ulp = mp.mpf(2) ** (e - 23)
    q = a / ulp
    n = int(mp.floor(q))
    r = q - n
    if r > 0.5 or (r == 0.5 and n & 1):
        n += 1
    v = n * ulp
    if v >= mp.mpf(2) ** 128:
        return s | 0x7F800000
    return s | bits32(float(v))


FNS = {
    "rcp": lambda x: 1 / x,
    "rsqrt": lambda x: 1 / mp.sqrt(x),
    "sqrt": mp.sqrt,
    "ex2": lambda x: mp.power(2, x),
    "lg2": lambda x: mp.log(x, 2),
    "sin": mp.sin,
    "cos": mp.cos,
}

for line in sys.stdin:
    fn, xh = line.split()[:2]
    x = mp.mpf(f32(int(xh, 16)))
    print(f"{fn} {xh} {round32(FNS[fn](x)):08x}")
