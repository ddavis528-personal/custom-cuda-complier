#!/usr/bin/env bash
# Division by compile-time constants gives the right answer.
#
# The cases that matter are the ones a naive lowering gets wrong: C rounds
# toward zero and an arithmetic shift rounds toward negative infinity, so
# -1 / 16 is 0 and not -1. INT_MIN and negative divisors are the other two.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS=-DCCV_ALIGNED ./tools/cuda-to-asm.sh test/cuda/divconst.cu \
    "$TMP/d.s" "$TMP/d" >/dev/null 2>&1 \
  || { echo "  FAIL  divconst.cu did not compile"; exit 1; }
build/ccv-llc "$TMP/d-lowered.ll" -o "$TMP/d.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/d.o" "$TMP/d.bin" || exit 1

python3 - "$TMP/d.bin" "$TMP/d.s" <<'PY'
import subprocess, sys, re
binf, asmf = sys.argv[1], sys.argv[2]
LAUNCH, OUT, IN = 0x20000, 0x30000, 0x40000
N = 32

def c_div(a, b):            # C rounds toward zero; Python floors.
    q = abs(a) // abs(b)
    return -q if (a < 0) != (b < 0) else q
def c_rem(a, b):
    return a - c_div(a, b) * b

INT_MIN = -2**31
vals = [0, 1, -1, 15, -15, 16, -16, 17, -17, 7, -7, 6, -6, 8, -8,
        100, -100, 1000, -1000, 123456, -123456, 2**30, -(2**30),
        INT_MIN, 2**31 - 1, -2, 2, 3, -3, 31, -31, 12345]
assert len(vals) == N

pokes = ["-poke", f"{hex(LAUNCH)}=32",
         "-poke", f"{hex(LAUNCH + 0x20)}={OUT >> 16}",
         "-poke", f"{hex(LAUNCH + 0x28)}={IN >> 16}",
         "-poke", f"{hex(LAUNCH + 0x30)}={N}"]
for i, v in enumerate(vals):
    pokes += ["-poke", f"{hex(IN + i * 4)}={v & 0xFFFFFFFF}"]
peeks = []
for i in range(N):
    for j in range(8):
        peeks += ["-peek", hex(OUT + (i * 8 + j) * 4)]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                   capture_output=True, text=True)
got = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
if len(got) != N * 8:
    print(f"  FAIL  simulator returned {len(got)} words, expected {N*8}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

def s32(u): return u - 2**32 if u >= 2**31 else u
def u32(v): return v & 0xFFFFFFFF

bad = 0
for i, v in enumerate(vals):
    want = [c_div(v, 16), c_rem(v, 16), c_div(v, 7), c_rem(v, 7),
            c_div(v, -16), u32(v) // 16, u32(v) // 7, u32(v) % 7]
    for j, w in enumerate(want):
        g = s32(got[i * 8 + j])
        if g != s32(u32(w)):
            print(f"  FAIL  v={v}  case {j}: got {g}, want {s32(u32(w))}")
            bad += 1
            if bad > 8:
                print("        ..."); sys.exit(1)
if bad:
    sys.exit(1)
print(f"  PASS  divconst: {N} dividends x 8 constant divisors, all correct")

# Size, because the answers are right either way and nothing else would show a
# regression to the generic expansion.
#
# Checking for `rcp` does NOT work and was tried: `rcp.u32` of a constant folds
# at compile time, so the generic path emits no reciprocal either -- just the
# folded seed and every Newton and correction step after it. The instruction
# count is what separates them. Measured today: 56 strength-reduced against 91
# through the generic path, for the same eight divisions.
BUDGET = 70
n = len([l for l in open(asmf)
         if l.strip() and not re.match(r'\s*(//|\.|[A-Za-z_0-9]+:)', l)])
if n > BUDGET:
    print(f"  FAIL  {n} instructions for eight constant divisors (budget "
          f"{BUDGET}) -- one fell through to the runtime-divisor expansion")
    sys.exit(1)
print(f"  PASS  {n} instructions for eight constant divisors, all "
      f"strength-reduced (generic expansion would be ~91)")
PY
