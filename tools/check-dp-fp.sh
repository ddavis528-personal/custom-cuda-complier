#!/usr/bin/env bash
# O-44's FP packed dot products compute what they say, and round once (F-137).
#
# These four cannot be reached from CUDA: the backend has no bfloat, half or
# FP8 type, so nothing forms them and nothing would notice if their semantics
# were wrong. They are hand-assembled here and executed against a reference
# written from §4's rule -- products summed exactly, one rounding into the
# accumulator -- computed independently in Python's arbitrary-precision
# fractions rather than in the same floating point the simulator uses.
#
# The rounding rule is the point. A per-product-rounding implementation agrees
# with this one on most inputs and disagrees on the ones chosen below, which is
# exactly the failure §4 calls an O-28-class gap: identical binaries, different
# numbers, visible as a convergence drift rather than as a test failure.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

python3 - "$TMP" <<'PY'
import json, struct, subprocess, sys, re
from fractions import Fraction
TMP = sys.argv[1]
LAUNCH, OUT = 0x20000, 0x30000

def f2i(x): return struct.unpack("<I", struct.pack("<f", x))[0]
def i2f(x): return struct.unpack("<f", struct.pack("<I", x))[0]

def bf16(x):                       # float -> bf16 bits (round to nearest even)
    b = f2i(x)
    lo = b & 0xffff
    up = 1 if (lo > 0x8000 or (lo == 0x8000 and (b >> 16) & 1)) else 0
    return ((b >> 16) + up) & 0xffff
def bf16_val(h): return i2f(h << 16)

# The discriminating cases are about the SUMMATION, not the products. A product
# of two BF16 values has at most 16 mantissa bits and is therefore exact in
# FP32 whatever the rule -- so rounding each product changes nothing, and a
# first version of this test mutated exactly that and passed. What the rule
# actually decides is whether the addends are summed at full width and rounded
# once, or rounded at each step.
#
# 2^24 is where FP32 runs out of integers: 2^24 + 1 is not representable and
# rounds back to 2^24, so a step-rounded sum loses both products, while the
# exact sum 2^24 + 2 is representable and survives. The last case looks like it
# should agree under both rules and does not: +1 then -1 step-rounds to
# 2^24 - 1, because the first addition rounds to even and the second then has a
# full ulp to give back. Written down because the comment here first claimed
# the opposite.
cases = [
    (1.0, 1.0, 1.0, 1.0, 0.0),
    (1.5, 2.5, -0.75, 4.0, 1.25),
    (1.0, 1.0, 1.0, 1.0, 16777216.0),        # 2^24: step-rounding loses both
    (1.0, 1.0, 1.0, 1.0, 16777218.0),        # 2^24+2: and here it loses one
    (1.0, 1.0, -1.0, 1.0, 16777216.0),       # +1 then -1 is NOT a no-op at 2^24
]

asm, want = [], []
# r0 holds the output window; r1/r2 the packed operands; r3 the accumulator.
asm.append("MOVI48 R0, 3")
for i, (a0, b0, a1, b1, acc) in enumerate(cases):
    pa = bf16(a0) | (bf16(a1) << 16)
    pb = bf16(b0) | (bf16(b1) << 16)
    asm.append(f"MOVI48 R1, {pa}")
    asm.append(f"MOVI48 R2, {pb}")
    asm.append(f"MOVI48 R3, {f2i(acc)}")
    asm.append("DP2_BF16 R3, R1, R2, R3")
    asm.append(f"ST_GLOBAL R3, R0, {i * 4}")
    # Reference: exact rational sum, rounded once to FP32.
    exact = (Fraction(bf16_val(bf16(a0))) * Fraction(bf16_val(bf16(b0))) +
             Fraction(bf16_val(bf16(a1))) * Fraction(bf16_val(bf16(b1))) +
             Fraction(acc))
    want.append(struct.unpack("<f", struct.pack("<f", float(exact)))[0])
asm.append("C_EXIT 0")

open(f"{TMP}/t.s", "w").write("\n".join(asm) + "\n")
r = subprocess.run([sys.executable, "tools/ccv-as.py", "build/generated/CCV.json",
                    f"{TMP}/t.s", f"{TMP}/t.bin"], capture_output=True, text=True)
if r.returncode:
    print("  FAIL  could not assemble the dp2 test")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

peeks = [x for i in range(len(cases)) for x in ("-peek", hex(OUT + i * 4))]
r = subprocess.run(["build/ccv-sim", f"{TMP}/t.bin", "-poke", f"{hex(LAUNCH)}=32",
                    *peeks], capture_output=True, text=True)
got = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
if len(got) != len(cases):
    print(f"  FAIL  simulator returned {len(got)} words, expected {len(cases)}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

bad = 0
for i, w in enumerate(want):
    v = i2f(got[i])
    if v != w:
        print(f"  FAIL  case {i}: dp2.bf16 = {v!r}, want {w!r} (exact sum, one rounding)")
        bad = 1
if bad:
    sys.exit(1)
print(f"  PASS  dp2.bf16: {len(cases)} cases match an exactly-summed reference")
PY
