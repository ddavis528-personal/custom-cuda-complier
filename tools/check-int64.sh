#!/usr/bin/env bash
# 64-bit integers through 32-bit pairs (IS-13 (2)): add, subtract and
# multiply, constant and variable shifts both ways, unsigned and signed
# compares, and divide and remainder (unsigned, signed, by a constant),
# executed on 32 lanes and compared with C's semantics, computed in Python.
#
# Before this, every one of them aborted: LLVM's combiner folds
# `zext (load i32)` into one 64-bit extending load, whose address reached the
# type legalizer unmatched, and the multiply, the compare's select and the
# divide had no expansion either. The control sign-extends every load the
# compiler widens to 64 bits, so a word with its top bit set corrupts the
# high half.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
for t in build/ccv-llc build/ccv-sim build/CCVLowerKernelArgs.so; do
  [ -e "$t" ] || { echo "  $t not built"; exit 1; }
done

CCV_CFLAGS=-Itest/bench ./tools/cuda-to-ir.sh test/cuda/int64.cu "$TMP/k.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/k.ll" -o "$TMP/k.low.ll" 2>/dev/null || exit 1

# Prints "ok <issue groups>", or what went wrong.
run() {
  build/ccv-llc "$TMP/k.low.ll" -o "$TMP/k.o" -obj "$@" 2>"$TMP/llc.err" ||
    { echo "compile failed: $(head -1 "$TMP/llc.err")"; return; }
  llvm-objcopy -O binary --only-section=.text "$TMP/k.o" "$TMP/k.bin" || return
  local entry; entry=$(llvm-nm "$TMP/k.o" | awk '/ T .*int64ops/ {print "0x"$1}')
  python3 - "$TMP/k.bin" "$entry" <<'PY'
import random, subprocess, sys
M = (1 << 64) - 1
def s64(v):
    v &= M
    return v - (1 << 64) if v >> 63 else v
def cdiv(a, b):                     # C: toward zero
    q = abs(a) // abs(b)
    return q if (a < 0) == (b < 0) else -q
N = 32
random.seed(64)
edge = [0, 1, 0xFFFFFFFF, 0x80000000, 0x7FFFFFFF, 0xFFFFFFFE]
A = edge + [random.getrandbits(32) for _ in range(N - len(edge))]
B = list(reversed(edge)) + [random.getrandbits(32) for _ in range(N - len(edge))]
want = []
for i in range(N):
    x = (A[i] << 32) | B[i]
    y = (B[i] << 32) | A[(i + 1) % N]
    sx, sy, s = s64(x), s64(y), B[i] & 63
    r = [x + y, x - y, x * y, x >> 7, x << s, x >> s, sx >> s,
         min(x, y), x if sx < sy else y,
         x // (y | 1), x % (y | 1),
         cdiv(sx, s64(y | 1)), sx - cdiv(sx, s64(y | 1)) * s64(y | 1),
         x % 1000, cdiv(sx, -7), int(x == y), A[i] * B[i] + x]
    for v in r:
        v &= M
        want += [v & 0xFFFFFFFF, v >> 32]
L = 0x20000
args = [f"-poke {hex(L + 24)}=256",
        f"-poke {hex(L + 32)}=3", f"-poke {hex(L + 36)}=0",   # a -> window 3
        f"-poke {hex(L + 40)}=4", f"-poke {hex(L + 44)}=0",   # b -> window 4
        f"-poke {hex(L + 48)}=5", f"-poke {hex(L + 52)}=0",   # o -> window 5
        f"-poke {hex(L + 56)}={N}"]
args += [f"-poke {hex(0x30000 + 4 * i)}={v}" for i, v in enumerate(A)]
args += [f"-poke {hex(0x40000 + 4 * i)}={v}" for i, v in enumerate(B)]
args += [f"-peek {hex(0x50000 + 4 * i)}" for i in range(len(want))]
r = subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", sys.argv[2]] + " ".join(args).split(),
                   capture_output=True, text=True)
if r.returncode:
    print("did not run:", (r.stderr or r.stdout).strip().splitlines()[0]); sys.exit()
got = {}
for line in r.stdout.splitlines():
    if line.strip().startswith("[0x5"):
        a, v = line.split("=")
        got[int(a.strip()[1:-1], 16)] = int(v.split()[0])
NAMES = ["x+y", "x-y", "x*y", "x>>7", "x<<s", "x>>s", "sx>>s", "min.u", "min.s",
         "x/y", "x%y", "sx/sy", "sx%sy", "x%1000", "sx/-7", "x==y", "a*b+x"]
bad = [k for k in range(len(want)) if got.get(0x50000 + 4 * k) != want[k]]
if bad:
    k = bad[0]; lane, op = divmod(k // 2, 17)
    print(f"{len(bad)} of {len(want)} words wrong; first: lane {lane} {NAMES[op]} "
          f"{'hi' if k & 1 else 'lo'} got {got.get(0x50000 + 4 * k)}, want {want[k]}")
else:
    print("ok", next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?"))
PY
}

fail=0
out=$(run)
case "$out" in
  ok*) echo "  PASS  int64.cu: 17 64-bit operations on 32 lanes, edge words included, as C computes them (${out#ok } issue groups)" ;;
  *)   echo "  FAIL  int64.cu: $out"; fail=1 ;;
esac
out=$(run -ccv-test-wide-load-sext)
case "$out" in
  *"words wrong"*|"did not run"*) echo "  PASS  control -ccv-test-wide-load-sext is caught: $out" ;;
  ok*) echo "  FAIL  control -ccv-test-wide-load-sext still computed every word right"; fail=1 ;;
  *)   echo "  FAIL  control -ccv-test-wide-load-sext broke something else: $out"; fail=1 ;;
esac

# The measurement IS-13 (2) asked for: hash64.cu, splitmix64 and FNV-1a as CUDA
# writes them, executed against Python, with what add.cc/addc would remove.
# Each 64-bit add or subtract is now add, setp.lt.u, add, @p add +-1; with a
# carry-producing add and a carry-consuming one it is two instructions, so it
# saves the compare and the predicated add.
CCV_CFLAGS=-Itest/bench ./tools/cuda-to-ir.sh test/cuda/hash64.cu "$TMP/h.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/h.ll" -o "$TMP/h.low.ll" 2>/dev/null || exit 1
build/ccv-llc "$TMP/h.low.ll" -o "$TMP/h.s" || exit 1
build/ccv-llc "$TMP/h.low.ll" -o "$TMP/h.o" -obj || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/h.o" "$TMP/h.bin" || exit 1
entry=$(llvm-nm "$TMP/h.o" | awk '/ T .*hash64/ {print "0x"$1}')
python3 - "$TMP/h.bin" "$entry" "$TMP/h.s" <<'PY' || fail=1
import random, re, subprocess, sys
M = (1 << 64) - 1
N = 32
random.seed(65)
seed = [random.getrandbits(32) for _ in range(N)]
key = [random.getrandbits(8) for _ in range(16 * N)]
def splitmix(s):
    s = (s + 0x9E3779B97F4A7C15) & M
    z = s
    z = ((z ^ (z >> 30)) * 0xBF58476D1CE4E5B9) & M
    z = ((z ^ (z >> 27)) * 0x94D049BB133111EB) & M
    return s, z ^ (z >> 31)
want = []
for i in range(N):
    s, acc = (seed[i] << 32) | i, 0
    for _ in range(8):
        s, z = splitmix(s)
        acc = (acc + z) & M
    h = 0xCBF29CE484222325
    for k in range(16):
        h = ((h ^ key[16 * i + k]) * 0x100000001B3) & M
    want += [acc & 0xFFFFFFFF, acc >> 32, h & 0xFFFFFFFF, h >> 32]
L = 0x20000
args = [f"-poke {hex(L + 24)}=256",
        f"-poke {hex(L + 32)}=3", f"-poke {hex(L + 36)}=0",   # seed -> window 3
        f"-poke {hex(L + 40)}=4", f"-poke {hex(L + 44)}=0",   # key  -> window 4
        f"-poke {hex(L + 48)}=5", f"-poke {hex(L + 52)}=0",   # o    -> window 5
        f"-poke {hex(L + 56)}={N}"]
args += [f"-poke {hex(0x30000 + 4 * i)}={v}" for i, v in enumerate(seed)]
args += [f"-poke {hex(0x40000 + 4 * i)}={key[4*i] | key[4*i+1] << 8 | key[4*i+2] << 16 | key[4*i+3] << 24}"
         for i in range(len(key) // 4)]
args += [f"-peek {hex(0x50000 + 4 * i)}" for i in range(len(want))]
r = subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", sys.argv[2]] + " ".join(args).split(),
                   capture_output=True, text=True)
if r.returncode:
    print("  FAIL  hash64.cu did not run:", (r.stderr or r.stdout).strip().splitlines()[0]); sys.exit(1)
got = {int(a, 16): int(v) for a, v in re.findall(r"\[(0x5[0-9a-f]+)\] = (\d+)", r.stdout)}
bad = [k for k in range(len(want)) if got.get(0x50000 + 4 * k) != want[k]]
if bad:
    print(f"  FAIL  hash64.cu: {len(bad)} of {len(want)} words wrong"); sys.exit(1)
issued = next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?")
asm = [l.strip() for l in open(sys.argv[3]) if re.match(r"\s+[a-z@]", l)]
carry = sum(1 for l in asm if re.fullmatch(r"@p\d add r\d+, r\d+, -?1", l))
spill = sum(1 for l in asm if re.match(r"(ld|st)(\.pred)?\.local ", l))
print(f"  PASS  hash64.cu: splitmix64 and FNV-1a on 32 lanes as Python computes them "
      f"({issued} issue groups)")
print(f"  INFO  hash64.cu, {len(asm)} instructions: {carry} 64-bit carries or borrows, "
      f"which add.cc/addc would take {2 * carry} instructions out of "
      f"({100.0 * 2 * carry / len(asm):.1f}%); {spill} spill transfers ({100.0 * spill / len(asm):.1f}%)")
PY
exit $fail
