#!/usr/bin/env python3
"""
Hex dump of a CCG instruction stream, split at instruction boundaries.

Length comes from bits [1:0] of the first halfword alone (§2), before any
format decode -- so this walker never looks at the format tag, which is the
property §2 claims.
"""
import sys

LEN = {0b00: (4, "32-bit"), 0b01: (2, "16-bit, Format J"),
       0b10: (2, "16-bit, Format K"), 0b11: (6, "48-bit")}
TAG = {0b0000:"A",0b0001:"A'",0b0010:'A"',0b0011:"B",0b0100:"B'",0b0101:'B"',
       0b0110:"C",0b0111:"C'",0b1000:"D",0b1001:"M",0b1010:"E",0b1011:"F",
       0b1100:"G",0b1101:"D'",0b1110:"I",0b1111:"H"}

data = open(sys.argv[1], "rb").read()
print(f"{'addr':>6}  {'bytes':<18} {'len':<18} fmt")
print("-" * 58)
pos = 0
while pos < len(data):
    size, what = LEN[data[pos] & 3]
    if pos + size > len(data):
        print(f"{pos:#06x}  truncated"); break
    raw = data[pos:pos + size]
    word = int.from_bytes(raw, "little")
    if size == 2:
        fmt = "J" if (word & 3) == 1 else "K"
    else:
        fmt = TAG[(word >> 2) & 0xF]
    print(f"{pos:#06x}  {raw.hex(' '):<18} {what:<18} {fmt}")
    pos += size
print(f"\n{len(data)} bytes total")
