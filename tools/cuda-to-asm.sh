#!/usr/bin/env bash
# CUDA source -> CCV assembly, the whole pipeline in one step.
#
# Factored out so that tools/verify.sh can regenerate the assembly it checks the
# spec's worked listings against, rather than reading a committed .s file. The
# generated assembly is gitignored, so a gate that read it from the tree would
# silently skip on a fresh clone -- which is precisely the "checker passes while
# being wrong about the machine" failure the provenance check exists to stop.
set -euo pipefail
cd "$(dirname "$0")/.."
IN=${1:?usage: cuda-to-asm.sh <kernel.cu> <out.s> [keep-ir-prefix]}
OUT=${2:?usage: cuda-to-asm.sh <kernel.cu> <out.s> [keep-ir-prefix]}
PREFIX=${3:-}

if [ -n "$PREFIX" ]; then
  CLANG_LL="$PREFIX-clang.ll"; LOWERED_LL="$PREFIX-lowered.ll"
else
  TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
  CLANG_LL="$TMP/clang.ll"; LOWERED_LL="$TMP/lowered.ll"
fi

# infer-address-spaces first: clang emits shared-memory accesses through a
# generic-pointer addrspacecast, and a generic pointer is 64-bit. Inferring the
# address space back restores native addrspace(3) accesses, which are flat
# 32-bit (§5.1) and need no window at all. NVPTX runs the same pass for the
# same reason.
./tools/cuda-to-ir.sh "$IN" "$CLANG_LL" >/dev/null
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$CLANG_LL" -o "$LOWERED_LL" 2>/dev/null
build/ccv-llc "$LOWERED_LL" -o "$OUT"
