#!/usr/bin/env bash
# Each SFU intrinsic selects ITS OWN instruction, and the instruction computes
# the function it is named after (F-141).
#
# A pattern table is where two entries get crossed: `flog2 -> EX2_F32` compiles,
# encodes, disassembles and round-trips perfectly, and no encoding check can see
# it. Only running the thing and comparing against the function it claims to be
# can, so that is what this does -- for all five at once, from one kernel, so a
# swap between any two of them has nowhere to hide.
#
# The comparison is to a RELATIVE TOLERANCE, not to equality, and that is not
# slackness: §4 says accuracy of the floating-point special-function set is
# implementation-defined and approximate. What is being checked here is which
# instruction the compiler chose, and 1e-5 separates `ex2` from `lg2`, `sin`
# from `cos`, and any of them from a reciprocal by many orders of magnitude.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

./tools/cuda-to-asm.sh test/cuda/sfu.cu "$TMP/s.s" "$TMP/s" >/dev/null 2>&1 \
  || { echo "  FAIL  sfu.cu did not compile"; exit 1; }
build/ccv-llc "$TMP/s-lowered.ll" -o "$TMP/s.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/s.o" "$TMP/s.bin" || exit 1

# All five must be present. If one silently became a libcall, or two collapsed
# onto the same instruction, the execution below would still pass on four.
for m in ex2 lg2 rsqrt sin cos; do
  if ! grep -qE "^[[:space:]]*$m\.f32 " "$TMP/s.s"; then
    echo "  FAIL  no $m.f32 in the generated assembly -- that intrinsic did not"
    echo "        select its own instruction, so executing it proves nothing"
    exit 1
  fi
done

python3 - "$TMP/s.bin" <<'PY'
import math, re, struct, subprocess, sys
binf = sys.argv[1]
LAUNCH, O, A = 0x20000, 0x30000, 0x40000
N = 8

def f2i(x): return struct.unpack("<I", struct.pack("<f", x))[0]
def i2f(x): return struct.unpack("<f", struct.pack("<I", x))[0]

# Positive, because lg2 and rsqrt are only defined there, and spread over
# several decades so that a confusion between ex2 and lg2 cannot be excused by
# the numbers being close. 1.0 is included on purpose: it is the one input
# where lg2 is 0 and rsqrt is 1, which pins the pair by inspection.
xs = [0.25, 0.5, 1.0, 2.0, 3.0, 7.5, 30.0, 100.0][:N]

pokes = ["-poke", f"{hex(LAUNCH)}=32",
         "-poke", f"{hex(LAUNCH + 32)}={O >> 16}",
         "-poke", f"{hex(LAUNCH + 40)}={A >> 16}",
         "-poke", f"{hex(LAUNCH + 48)}={N}"]
for i, x in enumerate(xs):
    pokes += ["-poke", f"{hex(A + i * 4)}={f2i(x)}"]
peeks = [t for i in range(N * 5) for t in ("-peek", hex(O + i * 4))]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                   capture_output=True, text=True)
got = [int(t) for t in re.findall(r"= (\d+)", r.stdout)]
if len(got) != N * 5:
    print(f"  FAIL  simulator returned {len(got)} words, expected {N * 5}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

REF = [("ex2",   lambda x: 2.0 ** x),
       ("lg2",   math.log2),
       ("rsqrt", lambda x: 1.0 / math.sqrt(x)),
       ("sin",   math.sin),
       ("cos",   math.cos)]
bad = 0
for i, x in enumerate(xs):
    for k, (name, f) in enumerate(REF):
        val, want = i2f(got[i * 5 + k]), f(x)
        if abs(val - want) > 1e-5 * max(1.0, abs(want)):
            print(f"  FAIL  {name}({x}) = {val}, want {want}")
            bad += 1
            if bad > 4:
                sys.exit(1)
if bad:
    sys.exit(1)
print(f"  PASS  SFU: ex2, lg2, rsqrt, sin, cos each compute their own "
      f"function over {N} inputs")
PY
