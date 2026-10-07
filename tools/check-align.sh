#!/usr/bin/env bash
# A lane's address is a multiple of its element size, and what that rests on.
#
# IS-1 settled it: natural element alignment is REQUIRED, unaligned access is
# rejected, and a violation raises F-ALIGN at execute. The compiler-side
# obligation IS-1 assigns to CP is narrower than the whole addressing mode:
# with scale-enable SET, `rindex << scale` is element-aligned by construction,
# so only `disp`, an unaligned base, or a byte-offset index with scale CLEAR
# can misalign -- and that last is O-23's unaligned-ABI path, §5.5's fold.
#
# THE FOLD, AND WHERE THE GUARANTEE ACTUALLY COMES FROM. `matchBaseIdx` builds
# the unaligned byte offset as `roffset + (index << elemLog2) [+ disp]`. The
# index term is a multiple of the element size because that is what the shift
# is; `disp` is a multiple of it because a well-typed GEP scales by the element
# size. **`roffset` is neither -- it is where the runtime placed the allocation
# inside its window, and nothing in the compiler constrains it.** So the
# compiler cannot discharge this obligation alone: it discharges its two terms
# and the launch ABI owes the third.
#
# That is what this checks, in both directions, because an argument is not a
# proof and a detector nobody has seen fire is not a detector:
#
#   roffset 4-aligned  -> zero misaligned accesses       (the obligation holds)
#   roffset odd        -> misaligned accesses, same code (the precondition is
#                         real, and the detector works)
#
# The corpus half lives in check-fusion.py, which fails any kernel whose run
# reports a misaligned access -- eight real kernels rather than this one.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

# Deliberately the UNALIGNED build: -DCCV_ALIGNED would constant-fold roffset
# away and there would be nothing to test.
CCV_CFLAGS="-Itest/bench" ./tools/cuda-to-asm.sh test/cuda/vadd.cu \
    "$TMP/v.s" "$TMP/v" >/dev/null 2>&1 \
  || { echo "  FAIL  vadd.cu did not compile"; exit 1; }

layout=$(grep -oP 'ccv-arg-layout"="\K[^"]*' "$TMP/v-lowered.ll" | head -1)
if [ "$layout" != "p32,p40,p48,s56" ]; then
  echo "  FAIL  argument layout is '$layout', expected 'p32,p40,p48,s56' --"
  echo "        the pokes below address roffset by that layout and would be"
  echo "        writing somewhere else"
  exit 1
fi

build/ccv-llc "$TMP/v-lowered.ll" -o "$TMP/v.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/v.o" "$TMP/v.bin" || exit 1

# The folded byte offset must have been built, or this proves nothing about it:
# scale-enable clear on a base+index access is the shape under test.
if ! grep -qE '\[(#[0-9]+|r[0-9]+), r[0-9]+, 0, [0-9-]+\]' "$TMP/v.s"; then
  echo "  FAIL  no scale-clear base+index access emitted -- the unaligned fold"
  echo "        did not happen, so the runs below exercise a different path"
  exit 1
fi

run() {                      # $1 = roffset for all three pointers
  build/ccv-sim "$TMP/v.bin" \
      -poke 0x20000=32 \
      -poke 0x20020=3 -poke 0x20024="$1" \
      -poke 0x20028=4 -poke 0x2002c="$1" \
      -poke 0x20030=5 -poke 0x20034="$1" \
      -poke 0x20038=8 2>&1 |
    grep -oP 'misaligned lane accesses \K[0-9]+' || echo 0
}

fail=0
for r in 0 4 8 64; do
  n=$(run "$r")
  if [ "$n" != "0" ]; then
    echo "  FAIL  roffset=$r is element-aligned, yet $n misaligned access(es)"
    echo "        -- the fold does not preserve alignment even when its one"
    echo "        unconstrained term does, which is worse than IS-1 assumed"
    fail=1
  fi
done
for r in 1 2 3; do
  n=$(run "$r")
  if [ "$n" = "0" ]; then
    echo "  FAIL  roffset=$r is not element-aligned, yet no misaligned access"
    echo "        was reported -- the detector is not looking, so every other"
    echo "        row of this check is green for the wrong reason"
    fail=1
  fi
done
[ $fail -ne 0 ] && exit 1

echo "  PASS  element alignment: the unaligned fold preserves it for every"
echo "        aligned roffset and demonstrably loses it for an odd one, which"
echo "        is the launch-ABI precondition CP cannot discharge (IS-1)"
