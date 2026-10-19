#!/usr/bin/env bash
# A by-value struct argument reads the launch block, not a window (F-147).
#
# Two halves, and both are needed. The STRUCTURAL half is that the argument
# layout must record the struct as an aggregate resident in the launch block
# rather than as a pointer -- if it goes back to being a pointer, it silently
# consumes a launch slot and shifts every argument after it. The EXECUTED half
# is that the values must come out right, because the miscompile this replaced
# produced perfectly valid instructions reading the wrong memory, and no static
# check can see that.
#
# The field values below are chosen so that a regression cannot pass by luck:
# `n` is 5, so a kernel that misread the struct as a window index would address
# window 5 -- which is where `in` is poked. It would read plausible floats and
# get plausible-looking answers.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

CCV_CFLAGS="-Itest/bench" ./tools/cuda-to-asm.sh test/cuda/byval.cu \
    "$TMP/b.s" "$TMP/b" >/dev/null 2>&1 \
  || { echo "  FAIL  byval.cu did not compile"; exit 1; }

layout=$(grep -oP 'ccv-arg-layout"="\K[^"]*' "$TMP/b-lowered.ll" | head -1)
if [ "$layout" != "p32,p40,a48:16" ]; then
  echo "  FAIL  argument layout is '$layout', expected 'p32,p40,a48:16'."
  echo "        The struct is not resident in the launch block -- if it is"
  echo "        back to being classified as a pointer it has taken a slot and"
  echo "        moved every argument after it."
  exit 1
fi

build/ccv-llc "$TMP/b-lowered.ll" -o "$TMP/b.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/b.o" "$TMP/b.bin" || exit 1

python3 - "$TMP/b.bin" <<'PY'
import re, struct, subprocess, sys
binf = sys.argv[1]
LAUNCH, OUT, IN = 0x20000, 0x30000, 0x50000      # IN is window 5, and n is 5
N, MUL, ADD = 5, 3, 0.25

def f2i(x): return struct.unpack("<I", struct.pack("<f", float(x)))[0]
def i2f(x): return struct.unpack("<f", struct.pack("<I", x))[0]

xs = [1.5, -2.0, 0.75, 4.0, -0.5, 9.0, 9.0, 9.0]   # past n: must stay untouched
pokes = ["-poke", f"{hex(LAUNCH)}=32",
         "-poke", f"{hex(LAUNCH + 32)}={OUT >> 16}",
         "-poke", f"{hex(LAUNCH + 40)}={IN >> 16}",
         "-poke", f"{hex(LAUNCH + 48)}={N}",
         "-poke", f"{hex(LAUNCH + 52)}={MUL}",
         "-poke", f"{hex(LAUNCH + 56)}={f2i(ADD)}",
         "-poke", f"{hex(LAUNCH + 60)}=0"]
for i, v in enumerate(xs):
    pokes += ["-poke", f"{hex(IN + 4 * i)}={f2i(v)}"]
for i in range(len(xs)):
    pokes += ["-poke", f"{hex(OUT + 4 * i)}={f2i(-1.0)}"]
peeks = [t for i in range(len(xs)) for t in ("-peek", hex(OUT + 4 * i))]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                   capture_output=True, text=True)
got = [int(t) for t in re.findall(r"= (\d+)", r.stdout)]
if len(got) != len(xs):
    print(f"  FAIL  simulator returned {len(got)} words, expected {len(xs)}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

bad = 0
for i in range(len(xs)):
    want = xs[i] * MUL + ADD if i < N else -1.0
    val = i2f(got[i])
    if val != want:
        print(f"  FAIL  out[{i}] = {val}, want {want}")
        bad += 1
        if bad > 3:
            sys.exit(1)
if bad:
    sys.exit(1)
print("  PASS  by-value struct: fields read from the launch block, and the "
      "guard uses the right one")
PY
