#!/usr/bin/env bash
# Device-function calls, executed (F-21; docs/proposals/calling-convention.md).
#
# test/cuda/calls.cu calls __noinline__ device functions: a value return, a
# two-deep chain whose middle function must keep its own link value across its
# inner call, four register arguments, a 16-bit argument and return, values
# live across calls in a loop, and a local array in both the kernel and a
# callee, live at once. Every one of those compiles, assembles and round-trips
# whether or not it is right; only running it says so (F-147). So the kernel
# runs on all 32 lanes against a reference written from the source, under each
# callee-saved set the backend offers (-ccv-csr), since CP-9 leaves that set
# to measurement and each must be correct before it can be measured.
#
# The inputs reach past 16 bits so half_step's truncation is exercised, and
# include negatives so the arithmetic is signed.
#
# Controls, each of which must fail: the frames laid out at one base (the
# callee's array lands on the kernel's), lane-0 masking let into a device
# function (every lane gets lane 0's answer), and the call frame's width rule
# dropped (half_step leaves a register narrow behind it).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
for t in build/ccv-llc build/ccv-sim build/CCVLowerKernelArgs.so; do
  [ -e "$t" ] || { echo "  $t not built"; exit 1; }
done

CCV_CFLAGS=-Itest/bench ./tools/cuda-to-ir.sh test/cuda/calls.cu "$TMP/c.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/c.ll" -o "$TMP/c.low.ll" 2>/dev/null || exit 1

# Runs the kernel compiled with the given ccv-llc flags. Prints "ok <calls>
# <instructions>", or what went wrong.
run() {
  build/ccv-llc "$TMP/c.low.ll" -o "$TMP/c.o" -obj "$@" 2>"$TMP/llc.err" ||
    { echo "compile failed: $(head -1 "$TMP/llc.err")"; return; }
  llvm-objcopy -O binary --only-section=.text "$TMP/c.o" "$TMP/c.bin" || return
  # Callees are emitted first, so the kernel is not at offset 0.
  local entry; entry=$(llvm-nm "$TMP/c.o" | awk '/ T .*calls/ {print "0x"$1}')
  python3 - "$TMP/c.bin" "$entry" <<'PY'
import subprocess, sys
def s32(x):
    x &= 0xffffffff
    return x - (1 << 32) if x & 0x80000000 else x
def s16(x):
    x &= 0xffff
    return x - (1 << 16) if x & 0x8000 else x
def mix(a, b, c, d): return s32(s32(a * 3 + b) ^ s32(c - d))
def half_step(x):    return s16(s16(x) + 3)
def chain(x, k):     return s32(mix(x, k, s32(x + 7), s32(k - 2)) + half_step(x) + s32(x * k))
def scratch(x, j):   return s32(x * ((j & 3) + 2) + 100)
def narrow3(a, b, c):
    a, b, c = s16(a), s16(b), s16(c)
    x, y = s16(a + b), s16(c - a)
    return s16(s16(x ^ y) + c)
N = 32
inp = [s32(i * 2731 - 40000) for i in range(N)]
want = []
for i, v in enumerate(inp):
    acc = 0
    for k in range(4):
        acc = s32(acc + chain(s32(v + k), k + 1))
    w = narrow3(v, v >> 3, i)
    p0, p1, p2, p3, p4 = s32(v * 3), s32(v ^ i), s32(v - i * 5), s32(v + 99), s32(i * i)
    q = s32(s32(p0 * p1) + s32(p2 * p3) + s32(p4 * w) + (p0 ^ p3) + s32(p1 - p4))
    want.append(s32(acc + scratch(v, i) * 3 + s32(v * 7 + ((i + 1) & 3)) + q))
L = 0x20000
args = [f"-poke {hex(L + 24)}=256",            # .local windows from 256
        f"-poke {hex(L + 32)}=3", f"-poke {hex(L + 36)}=0",   # in  -> window 3
        f"-poke {hex(L + 40)}=5", f"-poke {hex(L + 44)}=0",   # out -> window 5
        f"-poke {hex(L + 48)}={N}"]
args += [f"-poke {hex(0x30000 + 4 * i)}={v & 0xffffffff}" for i, v in enumerate(inp)]
args += [f"-poke {hex(0x50000 + 4 * i)}=3735928559" for i in range(N)]
args += [f"-peek {hex(0x50000 + 4 * i)}" for i in range(N)]
r = subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", sys.argv[2]] + " ".join(args).split(),
                   capture_output=True, text=True)
if r.returncode:
    print("did not run:", (r.stderr or r.stdout).strip().splitlines()[0]); sys.exit()
got = {}
for line in r.stdout.splitlines():
    if line.strip().startswith("[0x5"):
        a, v = line.split("=")
        got[int(a.strip()[1:-1], 16)] = s32(int(v.split()[0]))
bad = [i for i in range(N) if got.get(0x50000 + 4 * i) != want[i]]
if bad:
    i = bad[0]
    print(f"{len(bad)} of {N} lanes wrong; lane {i}: got {got.get(0x50000 + 4 * i)}, want {want[i]}")
else:
    issued = next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?")
    print("ok", issued)
PY
}

fail=0
for csr in none six eight; do
  out=$(run -ccv-csr=$csr)
  case "$out" in
    ok*) echo "  PASS  calls.cu, callee-saved set '$csr': 32 lanes correct (${out#ok } issue groups)" ;;
    *)   echo "  FAIL  calls.cu, callee-saved set '$csr': $out"; fail=1 ;;
  esac
done

# The static layout is visible in the code: scratch's array and the kernel's
# must not share an offset below R15.
build/ccv-llc "$TMP/c.low.ll" -o "$TMP/c.s" 2>/dev/null
python3 - "$TMP/c.s" <<'PY' || fail=1
import re, sys
offs, fn = {}, None
for line in open(sys.argv[1]):
    m = re.match(r'^(\w+):', line)
    if m: fn = m.group(1)
    for o in re.findall(r'\[r15 \+ (-\d+)\]', line):
        offs.setdefault(fn, set()).add(int(o))
k = next(f for f in offs if "calls" in f)
s = next(f for f in offs if "scratch" in f)
if offs[k] & offs[s]:
    print(f"  FAIL  the kernel's and scratch's frames share offsets {sorted(offs[k] & offs[s])}")
    sys.exit(1)
print(f"  PASS  static frames: scratch at {min(offs[s])}..{max(offs[s])}, the kernel "
      f"below it at {min(offs[k])}..{max(offs[k])}")
PY

# Controls. Each breaks one thing the passes above depend on.
for c in "-ccv-test-flat-frames" "-ccv-test-mask-device-functions" "-ccv-test-no-call-widths"; do
  out=$(run $c)
  # Caught means it compiled and then computed wrong or never finished. A
  # control that fails to compile proves nothing about the property.
  case "$out" in
    ok*) echo "  FAIL  control $c still computed every lane right"; fail=1 ;;
    *"lanes wrong"*|"did not run"*) echo "  PASS  control $c is caught: $out" ;;
    *)   echo "  FAIL  control $c broke something else: $out"; fail=1 ;;
  esac
done
exit $fail
