#!/usr/bin/env bash
# The Phase 1 milestone (backend-context.md §5.1): a CUDA kernel compiled from
# source and executed, producing correct results.
#
#   vadd.cu -> clang -> NVVM IR -> CCGLowerKernelArgs -> ccg-llc -> ELF
#           -> .text -> ccg-sim
#
# Nothing hand-written anywhere in that chain.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0

for t in build/ccg-llc build/ccg-sim build/CCGLowerKernelArgs.so; do
  [ -e "$t" ] || { echo "  $t not built"; exit 1; }
done

./tools/cuda-to-ir.sh test/cuda/vadd-aligned.cu "$TMP/v.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCGLowerKernelArgs.so \
    -passes='ccg-lower-kernel-args,instcombine,gvn,simplifycfg' \
    -S "$TMP/v.ll" -o "$TMP/v.low.ll" 2>/dev/null || exit 1
build/ccg-llc "$TMP/v.low.ll" -o "$TMP/v.o" -obj || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/v.o" "$TMP/v.bin" || exit 1

run() {           # $1 = n (active threads)
  local n=$1
  python3 - "$n" > "$TMP/args" <<'PY'
import struct, sys
n = int(sys.argv[1])
f = lambda x: struct.unpack('<I', struct.pack('<f', float(x)))[0]
# Launch block at 0x20000: +0 ntid.x, +32/+40/+48 c/a/b rbase, +56 n.
a = [f"-poke 0x20000=32", "-poke 0x20020=5", "-poke 0x20028=3",
     "-poke 0x20030=4", f"-poke 0x20038={n}"]
for i in range(32):
    a += [f"-poke {0x30000+i*4}={f(10*i)}",     # a[i] = 10i
          f"-poke {0x40000+i*4}={f(i+1)}",      # b[i] = i+1
          f"-poke {0x50000+i*4}=3735928559"]    # poison c[i]
a += [f"-peek {0x50000+i*4}" for i in range(32)]
print(" ".join(a))
PY
  # shellcheck disable=SC2046
  build/ccg-sim "$TMP/v.bin" $(cat "$TMP/args") > "$TMP/out" 2>&1 || {
    echo "  FAIL  n=$n: $(head -1 "$TMP/out")"; return 1; }

  python3 - "$n" "$TMP/out" <<'PY'
import re, struct, sys
n = int(sys.argv[1]); out = open(sys.argv[2]).read()
tof = lambda u: struct.unpack('<f', struct.pack('<I', u & 0xffffffff))[0]
bad = []
for i in range(32):
    m = re.search(r'\[0x%x\] = (\d+)' % (0x50000 + i*4), out)
    raw = int(m.group(1)) if m else None
    if i < n:
        if tof(raw) != float(11*i + 1):
            bad.append(f"lane {i}: {tof(raw)} != {11*i+1}")
    elif raw != 0xdeadbeef:                     # inactive lanes must be untouched
        bad.append(f"lane {i}: inactive lane was written")
groups = re.search(r'executed (\d+) issue groups', out)
if bad:
    for b in bad[:4]: print("    " + b)
    sys.exit(1)
print(f"  PASS  n={n:2d}: 32 lanes correct ({groups.group(1)} issue groups)")
PY
}

echo "  --- CUDA source to executed result ---"
run 32 || fail=1     # no divergence
run 20 || fail=1     # the compiled guard branch diverges
run  1 || fail=1     # maximum divergence
run  0 || fail=1     # every lane exits at the guard
exit $fail
