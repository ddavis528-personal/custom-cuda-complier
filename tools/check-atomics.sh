#!/usr/bin/env bash
# O-72: CUDA atomics, compiled and executed. test/cuda/atomics.cu runs on one
# warp, whose 32 lanes collide on bins and on single words, and on two
# (ccv-sim -cta, TI-29), whose CAS loops interleave on the same words: a
# 64-bin histogram in .global, integer (one
# atom.add.global at a computed address) and float (a CAS loop), a 16-bin one
# in .shared merged after a barrier, and min, max, or, xor, sub (seq_cst, so
# fenced), and, CAS, a 16-bit counter (a CAS loop on its word) and exchange.
# Final memory is compared with Python; where it depends on the order lanes
# apply in -- which CAS wins, what each exchange saw -- with the set §3's
# "any order" allows.
#
# Controls: ccv-sim -ccv-test-atomic-no-index (the address without its index
# register, as before O-72), and the kernel compiled with every atomic made a
# plain read-modify-write (ccv-llc -ccv-test-atomic-plain), which lanes
# racing on one word expose.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
for t in build/ccv-llc build/ccv-sim build/CCVLowerKernelArgs.so; do
  [ -e "$t" ] || { echo "  $t not built"; exit 1; }
done
CCV_CFLAGS=-Itest/bench ./tools/cuda-to-ir.sh test/cuda/atomics.cu "$TMP/a.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/a.ll" -o "$TMP/a.low.ll" 2>/dev/null || exit 1

run() {   # $1 = ccv-llc flags, $2 = ccv-sim flags, $3 = threads (32)
  build/ccv-llc "$TMP/a.low.ll" -o "$TMP/a.o" -obj $1 2>"$TMP/err" ||
    { echo "compile failed: $(head -1 "$TMP/err")"; return; }
  llvm-objcopy -O binary --only-section=.text "$TMP/a.o" "$TMP/a.bin" || return
  local entry; entry=$(llvm-nm "$TMP/a.o" | awk '/ T .*atomics/ {print "0x"$1}')
  python3 - "$TMP/a.bin" "$entry" "$2" "${3:-32}" <<'PY'
import random, re, struct, subprocess, sys
N = int(sys.argv[4])
random.seed(72)
IN = [random.getrandbits(11) for _ in range(N)]
W = [float(random.randint(1, 8)) for _ in range(N)]    # exact in any order
f2b = lambda f: struct.unpack("<I", struct.pack("<f", f))[0]
L, WIN = 0x20000, {"in": 3, "w": 4, "bins": 5, "fbins": 6, "misc": 7}
args = ["-threads", str(N), "-poke", f"{hex(L + 24)}=256"]
for k, name in enumerate(["in", "w", "bins", "fbins", "misc"]):
    args += ["-poke", f"{hex(L + 32 + 8 * k)}={WIN[name]}", "-poke", f"{hex(L + 36 + 8 * k)}=0"]
args += ["-poke", f"{hex(L + 72)}={N}"]
for i in range(N):
    args += ["-poke", f"{hex(0x30000 + 4 * i)}={IN[i]}", "-poke", f"{hex(0x40000 + 4 * i)}={f2b(W[i])}"]
init = {0: 0, 1: -(1 << 31), 2: 0xFFFFFFFF, 3: 0, 4: 0, 5: 0x5A5A5A5A, 6: 1000,
        7: -1, 8: 0, 9: 0, 10: 0, 11: 7}
for k, v in init.items():
    args += ["-poke", f"{hex(0x70000 + 4 * k)}={v & 0xFFFFFFFF}"]
peeks = [0x50000 + 4 * b for b in range(64)] + [0x60000 + 4 * b for b in range(64)] + \
        [0x70000 + 4 * k for k in range(32 + N)]
for a in peeks:
    args += ["-peek", hex(a)]
extra = sys.argv[3].split()
r = subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", sys.argv[2], *args, *extra],
                   capture_output=True, text=True)
if r.returncode:
    print("did not run:", (r.stderr or r.stdout).strip().splitlines()[0]); sys.exit()
got = {int(a, 16): int(v) for a, v in re.findall(r"\[(0x[0-9a-f]+)\] = (\d+)", r.stdout)}
s32 = lambda v: v - (1 << 32) if v >> 31 else v
bad = []
def want(addr, val, what):
    if got.get(addr) != val & 0xFFFFFFFF:
        bad.append(f"{what} = {got.get(addr)}, want {val & 0xFFFFFFFF}")
bins, fb, sh = [0] * 64, [0.0] * 64, [0] * 16
for i in range(N):
    bins[IN[i] & 63] += 1; fb[IN[i] & 63] += W[i]; sh[IN[i] & 15] += 1
for b in range(64):
    want(0x50000 + 4 * b, bins[b], f"bins[{b}]")
    want(0x60000 + 4 * b, f2b(fb[b]), f"fbins[{b}]")
for b in range(16):
    want(0x70040 + 4 * b, sh[b], f"shared bin {b}")
V = [x - 1000 for x in IN]
want(0x70000, min(V), "min.s"); want(0x70004, max(V), "max.s")
want(0x70008, min(IN), "min.u"); want(0x7000c, max(IN), "max.u")
want(0x70010, 0xFFFFFFFF, "or")
x = 0x5A5A5A5A
for v in IN: x ^= v
want(0x70014, x, "xor")
want(0x70018, 1000 - sum(range(N)), "sub")
want(0x7001c, 0, "and")
w8 = got.get(0x70020, 0)
if not 1 <= w8 <= N: bad.append(f"cas word = {w8}, want some lane's i + 1")
want(0x70024, 1, "cas winners")
want(0x70028, N << 16, "16-bit counter (high half of word 10)")
olds = [s32(got.get(0x70080 + 4 * i, 0)) for i in range(N)]
fin = s32(got.get(0x7002c, 0))
# Exchange forms a chain: the olds and the final value are 7 and each i, once.
if sorted(olds + [fin]) != sorted([7] + list(range(N))): bad.append("exchange olds are not a permutation")
if bad:
    print(f"{len(bad)} wrong; first: {bad[0]}")
else:
    print("ok", next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?"))
PY
}

fail=0
# O-73's fence codes: the seq_cst subtract is bracketed by ordering 0
# (sequentially consistent) at system scope, payload 2, and nothing else in
# the kernel is stronger than relaxed.
build/ccv-llc "$TMP/a.low.ll" -o "$TMP/a.s" || exit 1
fences=$(grep -oE '^\s*fence [0-9]+' "$TMP/a.s" | awk '{print $2}' | sort | uniq -c | xargs)
if [ "$fences" = "2 2" ]; then
  echo "  PASS  the seq_cst atomic is bracketed by two fences, ordering 0 at system scope (O-73)"
else
  echo "  FAIL  fences emitted: '$fences', want two of payload 2"; fail=1
fi
out=$(run "" "")
case "$out" in
  ok*) echo "  PASS  atomics.cu: global and shared histograms (int, and float by CAS loop), min/max/or/xor/sub/and, CAS, a 16-bit counter and exchange on 32 lanes (${out#ok } issue groups)" ;;
  *)   echo "  FAIL  atomics.cu: $out"; fail=1 ;;
esac
out=$(run "" "-cta" 64)
case "$out" in
  ok*) echo "  PASS  atomics.cu on 64 threads, two warps (-cta): every word right (${out#ok } issue groups)" ;;
  *)   echo "  FAIL  atomics.cu on 64 threads (-cta): $out"; fail=1 ;;
esac
for c in "|-ccv-test-atomic-no-index" "-ccv-test-atomic-plain|"; do
  out=$(run "${c%%|*}" "${c#*|}")
  case "$out" in
    ok*) echo "  FAIL  control ${c//|/} still computed every word right"; fail=1 ;;
    *"wrong"*|"did not run"*) echo "  PASS  control ${c//|/} is caught: $out" ;;
    *)   echo "  FAIL  control ${c//|/} broke something else: $out"; fail=1 ;;
  esac
done

# IS-14 (1): the float scatter-add against its integer twin, whose one
# atom.add.global is what an atom.add.f32 would cost, with every lane on its
# own word, 32 lanes over 64 bins, and every lane on one word. Each must also
# compute the right sums.
CCV_CFLAGS=-Itest/bench ./tools/cuda-to-ir.sh test/cuda/scatter.cu "$TMP/s.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/s.ll" -o "$TMP/s.low.ll" 2>/dev/null || exit 1
build/ccv-llc "$TMP/s.low.ll" -o "$TMP/s.o" -obj || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/s.o" "$TMP/s.bin" || exit 1
python3 - "$TMP/s.bin" "$TMP/s.o" <<'PY' || fail=1
import random, re, struct, subprocess, sys
syms = {l.split()[2]: int(l.split()[0], 16) for l in
        subprocess.run(["llvm-nm", sys.argv[2]], capture_output=True, text=True).stdout.splitlines()
        if " T " in l}
entry = lambda k: next(v for n, v in syms.items() if k in n)
f2b = lambda f: struct.unpack("<I", struct.pack("<f", f))[0]
N, L = 32, 0x20000
random.seed(14)
W = [random.randint(1, 9) for _ in range(8 * N)]
shapes = {"one word each": [8 * i + j for i in range(N) for j in range(8)],
          "64 bins": [random.randrange(64) for _ in range(8 * N)],
          "one word": [0] * (8 * N)}
fail, rows = 0, []
for shape, idx in shapes.items():
    issued = {}
    for kind in ("f", "i"):
        args = ["-threads", str(N), "-poke", f"{hex(L + 24)}=256"]
        for k, win in enumerate((3, 4, 5)):
            args += ["-poke", f"{hex(L + 32 + 8 * k)}={win}", "-poke", f"{hex(L + 36 + 8 * k)}=0"]
        args += ["-poke", f"{hex(L + 56)}={N}"]
        for j, v in enumerate(idx):
            args += ["-poke", f"{hex(0x30000 + 4 * j)}={v}"]
        for j, v in enumerate(W):
            args += ["-poke", f"{hex(0x40000 + 4 * j)}={f2b(float(v)) if kind == 'f' else v}"]
        used = sorted(set(idx))
        args += [x for a in used for x in ("-peek", hex(0x50000 + 4 * a))]
        r = subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", hex(entry("scatter_" + kind)), *args],
                           capture_output=True, text=True)
        got = {int(a, 16): int(v) for a, v in re.findall(r"\[(0x[0-9a-f]+)\] = (\d+)", r.stdout)}
        sums = {}
        for a, v in zip(idx, W):
            sums[a] = sums.get(a, 0) + v
        want = {0x50000 + 4 * a: (f2b(float(s)) if kind == "f" else s) for a, s in sums.items()}
        if r.returncode or got != want:
            print(f"  FAIL  scatter_{kind}, {shape}: wrong sums or did not run"); fail = 1
        issued[kind] = int(next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "0"))
    rows.append((shape, issued["f"], issued["i"]))
for shape, f, i in rows:
    print(f"  INFO  scatter-add, {shape}: float by CAS loop {f} issue groups, "
          f"integer atom.add {i}; atom.add.f32 would save {f - i} ({100.0 * (f - i) / f:.0f}%)")
if not fail:
    print("  PASS  scatter_f and scatter_i compute the right sums at three contention levels")
sys.exit(fail)
PY
exit $fail
