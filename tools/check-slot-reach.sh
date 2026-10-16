#!/usr/bin/env bash
# The launch-slot form reaches sixteen pointer arguments, and the ABI rule that
# makes it reach them (DA's response CP-4, 2026-10-08).
#
# Three claims, and they fail in different ways, so each is checked separately.
#
# (1) THE ABI RULE. Directly-passed pointer arguments occupy the front of the
#     argument area whatever order the signature declares them in. Checked on
#     `argorder.cu`, whose signature interleaves pointers and scalars on
#     purpose: declaration order is out, n, a, s, b and the layout must be
#     out, a, b, n, s. This is the only kernel in the tree that can tell
#     whether the rule is applied, because every other one already declares
#     its pointers first.
#
# (2) THAT IT STILL COMPUTES. An argument area laid out somewhere other than
#     where the code reads it compiles, assembles and round-trips, and reads
#     whatever is at the offsets it chose -- the F-147 failure shape. Only
#     running it catches that, so `argorder.cu` is executed against a
#     reference, with every poke addressed by the layout above.
#
# (3) THE REACH. `fused.cu` as a grid-stride loop at NT=16 has eighteen pointer
#     arguments. Under the old 4-byte stride the slot form reached the first
#     eight and the kernel spilled 9 transfers; the stride is 8 now, so the
#     count of slot-form accesses must pass the old ceiling of 8, and nothing
#     may spill. Asserting a floor rather than an exact count: a later
#     scheduling change may move an access without weakening the reach, and a
#     gate that fails on an improvement gets edited rather than read.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0

# ---- (1) and (2): the ABI rule, and that the kernel reads what it wrote -----
CCV_CFLAGS="-Itest/bench" ./tools/cuda-to-asm.sh test/cuda/argorder.cu \
    "$TMP/a.s" "$TMP/a" >/dev/null 2>&1 \
  || { echo "  FAIL  argorder.cu did not compile"; exit 1; }

layout=$(grep -oP 'ccv-arg-layout"="\K[^"]*' "$TMP/a-lowered.ll" | head -1)
if [ "$layout" != "p32,p40,p48,s56,s60" ]; then
  echo "  FAIL  argument layout is '$layout', expected 'p32,p40,p48,s56,s60'."
  echo "        The pointers are not front-loaded: the signature declares"
  echo "        out, n, a, s, b and the ABI must place out, a, b first so that"
  echo "        slot k is pointer argument k (DA's response CP-4)."
  fail=1
fi

# Dense slot numbering follows from the rule, and is what the reach depends on:
# three pointers must use slots 0, 1 and 2 and nothing higher.
slots=$(grep -oP '\[#\K[0-9]+' "$TMP/a.s" | sort -n | uniq | paste -sd, -)
if [ "$slots" != "0,1,2" ]; then
  echo "  FAIL  slot numbers used are '$slots', expected '0,1,2' -- three"
  echo "        pointer arguments should take the first three slots"
  fail=1
fi

build/ccv-llc "$TMP/a-lowered.ll" -o "$TMP/a.o" -obj 2>/dev/null \
  || { echo "  FAIL  argorder.cu did not select"; exit 1; }
llvm-objcopy -O binary --only-section=.text "$TMP/a.o" "$TMP/a.bin" || exit 1

python3 - "$TMP/a.bin" <<'PY' || fail=1
import re, struct, subprocess, sys
binf = sys.argv[1]
LAUNCH, OUT, A, B = 0x20000, 0x30000, 0x40000, 0x50000
N, S = 6, 0.5

def f2i(x): return struct.unpack("<I", struct.pack("<f", float(x)))[0]
def i2f(x): return struct.unpack("<f", struct.pack("<I", x))[0]

av = [1.0, 2.0, 3.0, -4.0, 0.25, 8.0, 7.0, 7.0]   # past n: must stay untouched
bv = [0.5, 0.5, -1.0, 2.0, 0.75, 1.0, 7.0, 7.0]

# Addressed by the layout the check above just pinned: out 32, a 40, b 48,
# n 56, s 60, with each pointer's in-window offset in the word after it.
pokes = ["-poke", f"{hex(LAUNCH)}=32",
         "-poke", f"{hex(LAUNCH + 32)}={OUT >> 16}", "-poke", f"{hex(LAUNCH + 36)}=0",
         "-poke", f"{hex(LAUNCH + 40)}={A >> 16}",   "-poke", f"{hex(LAUNCH + 44)}=0",
         "-poke", f"{hex(LAUNCH + 48)}={B >> 16}",   "-poke", f"{hex(LAUNCH + 52)}=0",
         "-poke", f"{hex(LAUNCH + 56)}={N}",
         "-poke", f"{hex(LAUNCH + 60)}={f2i(S)}"]
for i, (x, y) in enumerate(zip(av, bv)):
    pokes += ["-poke", f"{hex(A + 4 * i)}={f2i(x)}",
              "-poke", f"{hex(B + 4 * i)}={f2i(y)}"]
for i in range(len(av)):
    pokes += ["-poke", f"{hex(OUT + 4 * i)}={f2i(-1.0)}"]
peeks = [t for i in range(len(av)) for t in ("-peek", hex(OUT + 4 * i))]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                   capture_output=True, text=True)
got = [int(t) for t in re.findall(r"= (\d+)", r.stdout)]
if len(got) != len(av):
    print(f"  FAIL  simulator returned {len(got)} words, expected {len(av)}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

bad = 0
for i in range(len(av)):
    want = av[i] * S + bv[i] if i < N else -1.0
    val = i2f(got[i])
    if val != want:
        print(f"  FAIL  out[{i}] = {val}, want {want}")
        bad += 1
        if bad > 3:
            sys.exit(1)
sys.exit(1 if bad else 0)
PY

# ---- (3) the reach: past the old eight-pointer ceiling, and no spill --------
CCV_CFLAGS="-Itest/bench -DNT=16 -DGRID_STRIDE=64" ./tools/cuda-to-asm.sh \
    test/cuda/fused.cu "$TMP/f.s" "$TMP/f" >/dev/null 2>&1 \
  || { echo "  FAIL  fused.cu (NT=16, grid-stride) did not compile"; exit 1; }

slotforms=$(grep -cE '^\s*(ld|st)\.global [^,]+, \[#' "$TMP/f.s")
spills=$(grep -cE '^\s*(st|ld)\.(global|pred).*\[r15' "$TMP/f.s")

if [ "$slotforms" -le 8 ]; then
  echo "  FAIL  $slotforms slot-form accesses at NT=16 -- the 4-byte stride's"
  echo "        ceiling was 8, so the re-scaling is not in effect"
  fail=1
fi
if [ "$spills" -ne 0 ]; then
  echo "  FAIL  $spills spill transfers at NT=16, expected none: the sixteen"
  echo "        slots should hold every window base this kernel needs"
  fail=1
fi

if [ $fail -eq 0 ]; then
  echo "  PASS  pointer arguments front-loaded (layout $layout, slots $slots)"
  echo "        and argorder executes correctly from that layout"
  echo "  PASS  slot reach: $slotforms slot-form accesses at NT=16, past the"
  echo "        4-byte stride's ceiling of 8, with $spills spill transfers"
fi
exit $fail
