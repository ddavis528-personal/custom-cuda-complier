#!/usr/bin/env bash
# Regenerates every artifact in docs/walkthrough/ from the current toolchain.
# The walkthrough document embeds these files rather than quoting them, so it
# cannot drift from what the compiler actually produces.
set -euo pipefail
cd "$(dirname "$0")/.."
OUT=docs/walkthrough
mkdir -p "$OUT"

./tools/cuda-to-asm.sh test/cuda/vadd-aligned.cu "$OUT/4-asm.s" "$OUT/x"
mv "$OUT/x-clang.ll" "$OUT/2-clang.ll"; mv "$OUT/x-lowered.ll" "$OUT/3-lowered.ll"

# The unaligned shape as well: §5.5 is generated from it, and it is the only
# thing exercising the roffset fold (F-27). Same source, no alignment attribute.
./tools/cuda-to-asm.sh test/cuda/vadd.cu "$OUT/4-asm-unaligned.s"

# §8's narrow-width case. Both widths of the same loop kernel, so the section
# can put them side by side, plus the chwidth pass's own account of where it
# put the mode switches and why.
CCV_CFLAGS=-DCCV_ALIGNED ./tools/cuda-to-asm.sh test/bench/vadd16_loop.cu \
    "$OUT/8-narrow-asm.s" "$OUT/n" >/dev/null
CCV_CFLAGS=-DCCV_ALIGNED ./tools/cuda-to-asm.sh test/bench/vadd_loop.cu \
    "$OUT/8-wide-asm.s" "$OUT/w" >/dev/null
./tools/cuda-to-asm.sh test/bench/vadd16_loop.cu "$OUT/8-narrow-asm-unaligned.s" \
    "$OUT/nu" >/dev/null
build/ccv-llc "$OUT/n-lowered.ll" -o /dev/null -ccv-chwidth-stats \
    2> "$OUT/8-chwidth-stats.txt"
# The same kernel with each optimisation turned off, so the section shows what
# they are worth rather than asserting it.
build/ccv-llc "$OUT/n-lowered.ll" -o "$OUT/8-narrow-asm-noedge.s" \
    -ccv-chwidth-cross-block=false
rm -f "$OUT"/n-*.ll "$OUT"/w-*.ll "$OUT"/nu-*.ll

build/ccv-llc "$OUT/3-lowered.ll" -o "$OUT/5-object.o" -obj
llvm-objcopy -O binary --only-section=.text "$OUT/5-object.o" "$OUT/5-text.bin"

# Disassembly, from the generated decoder, walking the stream by §2's length
# rule. -max-steps 1 stops after the first group; a full trace is the execution
# record, so take the disassembly from a run that reaches every instruction.
# n=20, not 32: the trace has to show the mask narrowing, or §6 asserts
# something its own evidence does not demonstrate.
build/ccv-sim "$OUT/5-text.bin" -trace \
    -poke 0x20000=32 -poke 0x20020=5 -poke 0x20028=3 -poke 0x20030=4 \
    -poke 0x20038=20 > "$OUT/6-trace.txt" 2>&1 || true

python3 tools/hexdump-ccv.py "$OUT/5-text.bin" > "$OUT/5-hexdump.txt"
echo "  regenerated $OUT/"
python3 tools/gen-walkthrough-doc.py
