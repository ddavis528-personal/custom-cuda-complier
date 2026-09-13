#!/usr/bin/env bash
# Step 4's milestone: a block reduction compiled from CUDA source and executed.
#
#   reduce.cu -> clang -> NVVM IR -> infer-address-spaces
#             -> CCGLowerKernelArgs -> ccg-llc -> ELF -> .text -> ccg-sim
#
# What this exercises that vadd does not: shared memory, barriers, a loop with
# a backward branch, unsigned compares, and lanes that reach the barrier at
# different times. That last one is the point -- with per-thread PCs (§1) a
# barrier is a real synchronisation between lanes of one warp, and the trace
# shows half the warp blocked while the other half reduces.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0

./tools/cuda-to-asm.sh test/cuda/reduce.cu "$TMP/r.s" "$TMP/r" >/dev/null 2>&1 || {
  echo "  FAIL  reduce.cu did not compile"; exit 1; }
build/ccg-llc "$TMP/r-lowered.ll" -o "$TMP/r.o" -obj || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/r.o" "$TMP/r.bin" || exit 1

run() {           # $1 = n (elements, also the CTA size the kernel reduces over)
  local n=$1
  python3 - "$n" > "$TMP/args" <<'PY'
import struct, sys
n = int(sys.argv[1])
f = lambda x: struct.unpack('<I', struct.pack('<f', float(x)))[0]
# Launch block at 0x20000: +0 ntid.x, +32 out.rbase, +40 in.rbase, +48 n.
a = ["-poke 0x20000=32", "-poke 0x20020=3", "-poke 0x20028=5",
     f"-poke 0x20030={n}"]
for i in range(32):
    a.append(f"-poke {0x50000+i*4}={f(i)}")       # in[i] = i
a.append("-poke 0x30000=3735928559")              # poison out[0]
a.append("-peek 0x30000")
print(" ".join(a))
PY
  # shellcheck disable=SC2046
  build/ccg-sim "$TMP/r.bin" $(cat "$TMP/args") > "$TMP/out" 2>&1 || {
    echo "  FAIL  n=$n: $(head -1 "$TMP/out")"; return 1; }

  python3 - "$n" "$TMP/out" <<'PY'
import re, struct, sys
n = int(sys.argv[1]); out = open(sys.argv[2]).read()
tof = lambda u: struct.unpack('<f', struct.pack('<I', u & 0xffffffff))[0]
m = re.search(r'\[0x30000\] = (\d+)', out)
if not m:
    print(f"  FAIL  n={n}: no result"); sys.exit(1)
got = tof(int(m.group(1)))
# The kernel sums in[i] for the threads that pass the i<n guard; the rest
# contribute the 0.0 the ternary supplies, so the sum is of 0..n-1.
want = float(sum(range(min(n, 32))))
groups = re.search(r'executed (\d+) issue groups', out)
if got != want:
    print(f"  FAIL  n={n}: got {got}, want {want}"); sys.exit(1)
print(f"  PASS  n={n:2d}: sum = {want:g} ({groups.group(1)} issue groups)")
PY
}

echo "  --- block reduction: shared memory, barriers, backward branch ---"
for n in 32 20 8 1; do run "$n" || fail=1; done
exit $fail
