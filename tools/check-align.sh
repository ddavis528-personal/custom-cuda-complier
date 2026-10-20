#!/usr/bin/env bash
# A lane's address is a multiple of its element size, and what that rests on.
#
# IS-1 settled it, and ISA v1.9 adopts it as O-58: natural element alignment
# is REQUIRED, and a violation raises F-ALIGN at execute, per lane, for lanes
# in issue mask and predicate only (section 12). ccv-sim faults rather than
# counting, and a fault ends the run with status 3 and a FAULT record. The compiler-side
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
#   roffset 4-aligned  -> runs to completion, no fault   (the obligation holds)
#   roffset odd        -> F-ALIGN, same code            (the precondition is
#                         real, and the fault fires)
#
# With n = 8 the bounds guard sends lanes 8-31 away, so the fault's lane mask
# must lie within lanes 0-7: a fault on a lane that never executed the access
# would be the section 12.2 error the ISA calls the likeliest.
#
# The corpus half lives in check-fusion.py, where any fault fails a kernel.
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
  # A fault exits 3 by design, so the simulator's status is not the signal;
  # the FAULT record is.
  { build/ccv-sim "$TMP/v.bin" \
      -poke 0x20000=32 \
      -poke 0x20020=3 -poke 0x20024="$1" \
      -poke 0x20028=4 -poke 0x2002c="$1" \
      -poke 0x20030=5 -poke 0x20034="$1" \
      -poke 0x20038=8 2>&1 || true; } | grep -oP 'FAULT \S+  pc=\S+  lanes=\S+' || echo none
}

fail=0
for r in 0 4 8 64; do
  n=$(run "$r")
  if [ "$n" != "none" ]; then
    echo "  FAIL  roffset=$r is element-aligned, yet: $n"
    echo "        -- the fold does not preserve alignment even when its one"
    echo "        unconstrained term does, which is worse than IS-1 assumed"
    fail=1
  fi
done
for r in 1 2 3; do
  n=$(run "$r")
  case "$n" in
    "FAULT F-ALIGN"*)
      lanes=$((16#${n##*lanes=}))
      if [ $((lanes & ~0xff)) -ne 0 ] || [ $lanes -eq 0 ]; then
        echo "  FAIL  roffset=$r faulted on lanes $(printf %08x $lanes), outside the"
        echo "        eight that execute the access (section 12.2)"
        fail=1
      fi ;;
    *)
      echo "  FAIL  roffset=$r is not element-aligned, yet: $n -- the fault is"
      echo "        not firing, so every other row of this check is green for"
      echo "        the wrong reason"
      fail=1 ;;
  esac
done
[ $fail -ne 0 ] && exit 1

echo "  PASS  element alignment: the unaligned fold preserves it for every"
echo "        aligned roffset, and an odd one raises F-ALIGN on executing lanes"
echo "        only -- the launch-ABI precondition CP cannot discharge (O-58)"
