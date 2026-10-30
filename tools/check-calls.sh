#!/usr/bin/env bash
# Device-function calls, executed (F-21; docs/proposals/calling-convention.md).
#
# test/cuda/calls.cu calls __noinline__ device functions: a value return, a
# two-deep chain whose middle function must keep its own link value across its
# inner call, four register arguments, a 16-bit argument and return, values
# live across calls in a loop, and a local array in both the kernel and a
# callee, live at once, and arguments past the sixth on the callee's frame.
# Every one of those compiles, assembles and round-trips
# whether or not it is right; only running it says so (F-147). So the kernel
# runs on all 32 lanes against a reference written from the source, under each
# callee-saved set the backend offers (-ccv-csr), since CP-9 leaves that set
# to measurement and each must be correct before it can be measured.
#
# The inputs reach past 16 bits so half_step's truncation is exercised, and
# include negatives so the arithmetic is signed. Pointers cross calls as
# (rbase, roffset) pairs (F-22): read through, forwarded with an offset, and
# returned -- the store itself goes through the returned pair.
#
# Controls, each of which must fail: the frames laid out at one base (the
# callee's array lands on the kernel's), lane-0 masking let into a device
# function (every lane gets lane 0's answer), and the call frame's width rule
# dropped (half_step leaves a register narrow behind it), and a pointer split
# without its GEP offset (sum3_via reads one element short, advance stores
# every lane's result to out[0]), and stack arguments written as if every
# callee's frame were at base 0 (many2 reads its seventh and eighth arguments
# from slots nobody wrote), a caller laid out ignoring what its indirect
# calls reach (sub_frame's array lands on apply's, and its saved register on
# apply's spill cells), every function's spill cells laid out from the bottom
# (a callee's saves land on its caller's spills), and function
# pointers built for an image at 0 rather than at its load address (each
# indirect call jumps 4 KiB short).
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
def many(a, b, c, d, e, f, g, h, k):
    return s32(a - b * 2 + c * 3 - d * 4 + e * 5 - f * 6 + g * 7 - s16(h) * 8 + k * 9)
def many2(a, b, c, d, e, f, g, h):
    return s32(many(h, g, f, e, d, c, b, a, s32(g + h)) + g * h)
def add_at(a, b, p):    return s32(a + b + p[0])
def sub_frame(a, b, p):
    r = s32(s32(a * ((b & 3) + 1) - b) - p[1])
    return s32(add_at(r, b, p) ^ r)
def apply(f, a, b, p):  return s32(f(a, b, p) * 2 + s32(a + ((a ^ b) & 3) * b))
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
    j = (i & 7) + 1
    s3 = s32(inp[j] + inp[j + 1] + inp[j + 2])
    m = many2(v, i, v ^ i, s32(v + 1), i * 3, s32(v - 7), i + 11, v >> 2)
    pk = s32(inp[2 + (i & 3)] + v - i * 5 + 13 - (v >> 4))
    g = add_at if i & 1 else sub_frame
    ic = s32(apply(g, v, i, inp[4:]) + g(i, v & 15, inp))
    want.append(s32(acc + scratch(v, i) * 3 + s32(v * 7 + ((i + 1) & 3)) + q + s3 + m + pk + ic))
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
# must not share an offset from R15 (above it under IS-25, the kernel's frame
# above its callees'; below it with -ccv-frame-in-priv=false). The kernel also stores its callees'
# stack arguments into their frames, which is where they belong; a slot a
# device function loads and never stores is such an argument, so it is not
# counted as the kernel's.
build/ccv-llc "$TMP/c.low.ll" -o "$TMP/c.s" 2>/dev/null
python3 - "$TMP/c.s" <<'PY' || fail=1
import re, sys
loads, stores, fn = {}, {}, None
for line in open(sys.argv[1]):
    m = re.match(r'^(\w+):', line)
    if m: fn = m.group(1)
    for op, o in re.findall(r'(ld|st)\.global r\d+, \[r15 \+ (-?\d+)\]', line):
        (loads if op == "ld" else stores).setdefault(fn, set()).add(int(o))
k = next(f for f in stores if "calls" in f)
s = next(f for f in stores if "scratch" in f)
args = set()
for f in loads:
    if f != k:
        args |= loads[f] - stores.get(f, set())
own = (loads.get(k, set()) | stores[k]) - args
if own & stores[s]:
    print(f"  FAIL  the kernel's and scratch's frames share offsets {sorted(own & stores[s])}")
    sys.exit(1)
print(f"  PASS  static frames: scratch at {min(stores[s])}..{max(stores[s])}, the kernel "
      f"apart from it at {min(own)}..{max(own)}; stack arguments at {sorted(args)}")
PY

# Controls. Each breaks one thing the passes above depend on. The call-widths
# one needs a narrow register live across a call, which only 16-bit integers
# at width 16 make (F-199: by default they run at 32 bits).
for c in "-ccv-test-flat-frames" "-ccv-test-mask-device-functions" \
         "-ccv-test-i16-legal -ccv-test-no-call-widths" "-ccv-test-drop-pair-offset" \
         "-ccv-test-stack-args-at-zero" "-ccv-test-ignore-indirect-frames" \
         "-ccv-test-flat-local" "-ccv-code-base=0"; do
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
