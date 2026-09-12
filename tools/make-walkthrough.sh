#!/usr/bin/env bash
# Regenerates every artifact in docs/walkthrough/ from the current toolchain.
# The walkthrough document embeds these files rather than quoting them, so it
# cannot drift from what the compiler actually produces.
set -euo pipefail
cd "$(dirname "$0")/.."
OUT=docs/walkthrough
mkdir -p "$OUT"

./tools/cuda-to-ir.sh test/cuda/vadd-aligned.cu "$OUT/2-clang.ll" >/dev/null
opt -load-pass-plugin=build/CCGLowerKernelArgs.so \
    -passes='ccg-lower-kernel-args,instcombine,gvn,simplifycfg' \
    -S "$OUT/2-clang.ll" -o "$OUT/3-lowered.ll" 2>/dev/null
build/ccg-llc "$OUT/3-lowered.ll" -o "$OUT/4-asm.s"

# The unaligned shape as well: §5.5 is generated from it, and it is the only
# thing exercising the roffset fold (F-27). Same source, no alignment attribute.
./tools/cuda-to-ir.sh test/cuda/vadd.cu "$OUT/2-clang-unaligned.ll" >/dev/null
opt -load-pass-plugin=build/CCGLowerKernelArgs.so \
    -passes='ccg-lower-kernel-args,instcombine,gvn,simplifycfg' \
    -S "$OUT/2-clang-unaligned.ll" -o "$OUT/3-lowered-unaligned.ll" 2>/dev/null
build/ccg-llc "$OUT/3-lowered-unaligned.ll" -o "$OUT/4-asm-unaligned.s"
build/ccg-llc "$OUT/3-lowered.ll" -o "$OUT/5-object.o" -obj
llvm-objcopy -O binary --only-section=.text "$OUT/5-object.o" "$OUT/5-text.bin"

# Disassembly, from the generated decoder, walking the stream by §2's length
# rule. -max-steps 1 stops after the first group; a full trace is the execution
# record, so take the disassembly from a run that reaches every instruction.
# n=20, not 32: the trace has to show the mask narrowing, or §6 asserts
# something its own evidence does not demonstrate.
build/ccg-sim "$OUT/5-text.bin" -trace \
    -poke 0x20000=32 -poke 0x20020=5 -poke 0x20028=3 -poke 0x20030=4 \
    -poke 0x20038=20 > "$OUT/6-trace.txt" 2>&1 || true

python3 tools/hexdump-ccg.py "$OUT/5-text.bin" > "$OUT/5-hexdump.txt"
echo "  regenerated $OUT/"
python3 tools/gen-walkthrough-doc.py
