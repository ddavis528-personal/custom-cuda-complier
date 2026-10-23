#!/usr/bin/env bash
# CUDA's FP8 conversions, from cuda_fp8.h itself, executed (CP-6, stage 2).
#
# test/cuda/fp8-clang.ll is clang's IR for test/cuda/fp8.cu with NVIDIA's
# header at sm_89 (tools/gen-fp8-ir.sh): every conversion arrives as inline
# PTX, which CCVExpandPTXAsm turns into §4 conversions. Each kernel runs in
# ccv-sim and is compared with tools/nfp_ref.py, which shares no code with
# either. FP8 sources are exhaustive (every byte); FP32 sources are every E4M3
# and E5M2 value and midpoint of both signs, the specials, and random values.
#
# Controls, which must fail: ccv-llc -ccv-test-ptx-swap-x2 (an x2's elements
# in the wrong halves), and ccv-sim -ccv-test-fp-no-saturate (overflow to NaN,
# the rule O-53 rejected for these conversions).
#
# Stage 3: two dot products over __nv_fp8x4_*, which CCVFormFP8Dot makes one
# dp4 each, against an exact sum rounded once (O-44). Its control is ccv-llc
# -ccv-fp8-dot=false, which leaves the FP32 additions to round one by one; on
# the case built for it (448^2 and three 2^-7 products) that is a different
# number.
#
# Stage 4: `__nv_fp8_e4m3(float(a) op float(b))` for add, subtract and
# multiply is the native operation at chwidth 8 (§5.8). Checked on every byte
# against a fixed spread of partners, against both readings -- the source's
# (FP32, then a saturating conversion) and the native operation's -- which
# §5.8 says agree. A mixed-format add has no native form and is checked too.
# Its control is ccv-llc -ccv-test-fp8-wrong-format (E4M3's add in E5M2's
# format code).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

build() {   # $1 = extra ccv-llc flag; leaves $TMP/f$2.bin and $TMP/f$2.o
  opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
      -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
      -S test/cuda/fp8-clang.ll -o "$TMP/l.ll" 2>/dev/null || return 1
  build/ccv-llc "$TMP/l.ll" -o "$TMP/f$2.o" -obj $1 2>/dev/null || return 1
  llvm-objcopy -O binary --only-section=.text "$TMP/f$2.o" "$TMP/f$2.bin"
}
build "" 0 || { echo "  FAIL  fp8.cu's IR did not compile"; exit 1; }
build "-ccv-test-ptx-swap-x2" 1 || { echo "  FAIL  the swap control did not compile"; exit 1; }
build "-ccv-fp8-dot=false" 2 || { echo "  FAIL  the dot control did not compile"; exit 1; }
build "-ccv-test-fp8-wrong-format" 3 || { echo "  FAIL  the format control did not compile"; exit 1; }
# Inline PTX CCV does not implement is refused by name, never emitted.
sed 's/cvt\.f32\.f16 \$0, \$1;/mov.b16 $0, $1;/' "$TMP/l.ll" > "$TMP/bad.ll"
bad=$(build/ccv-llc "$TMP/bad.ll" -o /dev/null 2>&1)
if grep -q "inline PTX 'mov.b16 \$0, \$1' is not one CCV implements" <<< "$bad"; then
  echo "  PASS  inline PTX outside the conversions is refused by name"
else
  echo "  FAIL  unknown inline PTX was not refused"; exit 1
fi
n=$(build/ccv-llc "$TMP/l.ll" -o - 2>/dev/null | grep -cE '^\s*cvt\.')
if [ "$n" -lt 7 ]; then
  echo "  FAIL  only $n conversions emitted; the PTX was not made native"; exit 1
fi

python3 - "$TMP" <<'PY'
import random, re, struct, subprocess, sys
sys.path.insert(0, "tools")
import nfp_ref as R
tmp = sys.argv[1]
LAUNCH, O, A = 0x20000, 0x30000, 0x40000

def syms(obj):
    out = subprocess.run(["llvm-nm", obj], capture_output=True, text=True).stdout
    return {l.split()[2]: int(l.split()[0], 16) for l in out.splitlines()
            if " T " in l}

def run(binf, entry, ins, esize, outsize, extra=()):
    """Run a kernel over ins (each esize bytes), one warp at a time."""
    got = []
    for w in range(0, len(ins), 32):
        chunk = ins[w:w + 32]
        pokes = ["-poke", f"{hex(LAUNCH)}=32",
                 "-poke", f"{hex(LAUNCH + 0x20)}={O >> 16}",
                 "-poke", f"{hex(LAUNCH + 0x28)}={A >> 16}"]
        # Inputs as words: bytes and halfwords packed little-endian.
        per = 4 // esize
        words = [0] * ((len(chunk) * esize + 3) // 4)
        for k, v in enumerate(chunk):
            words[k // per] |= v << (8 * esize * (k % per))
        for k, v in enumerate(words):
            pokes += ["-poke", f"{hex(A + 4 * k)}={v}"]
        nout = (len(chunk) * outsize + 3) // 4
        peeks = [x for k in range(nout) for x in ("-peek", hex(O + 4 * k))]
        r = subprocess.run(["build/ccv-sim", binf, "-entry", hex(entry),
                            "-threads", str(len(chunk)), *pokes, *peeks, *extra],
                           capture_output=True, text=True)
        vals = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
        if len(vals) != nout:
            return None, (r.stderr or r.stdout).strip()[:300]
        oper = 4 // outsize
        for k in range(len(chunk)):
            got.append((vals[k // oper] >> (8 * outsize * (k % oper))) & ((1 << (8 * outsize)) - 1))
    return got, ""

f32 = lambda q: struct.unpack("<I", struct.pack("<f", q))[0]
rng = random.Random(8)
# FP32 sources: every E4M3 and E5M2 value and midpoint, both signs, the
# specials, values past each format's range, and random bit patterns.
src = set()
for fmt in ((2, 0), (2, 1)):
    qs = [q for q, _ in R.finite_values(fmt)]
    for i, q in enumerate(qs):
        for v in [q] + ([(q + qs[i + 1]) / 2] if i + 1 < len(qs) else []):
            if R.decode((0, 0), R.encode((0, 0), R.V("fin", False, v))).q == v:
                x = R.encode((0, 0), R.V("fin", False, v))
                src |= {x, x | 0x80000000}
src |= {0x7F800000, 0xFF800000, 0x7FC00000, 0xFFFFFFFF, 0x7F7FFFFF, 0x47000000,
        0x47800000, 0x43E00000, 0x43F00000, 0x00000001, 0x80000001}
src |= {rng.getrandbits(32) for _ in range(400)}
src = sorted(src)
bytes_ = list(range(256))
pairs = [rng.getrandbits(16) for _ in range(256)] + [0x7F7E, 0xFF80, 0x0000, 0x7C7B]

def cvt(d, s, x):
    return R.op(f"cvt:{d[1]}:{s[1]}:0", 0, d[0], s[0], 0, 0, x, 0, 0)

cases = {
    "to_e4m3":  (src, 4, 1, lambda x: cvt((2, 0), (0, 0), x)),
    "to_e5m2":  (src, 4, 1, lambda x: cvt((2, 1), (0, 0), x)),
    "from_e4m3": (bytes_, 1, 4, lambda x: cvt((0, 0), (2, 0), x)),
    "from_e5m2": (bytes_, 1, 4, lambda x: cvt((0, 0), (2, 1), x)),
    "from_e5m2x2": (pairs, 2, 4, lambda x: cvt((1, 0), (2, 1), x & 0xFF)
                    | cvt((1, 0), (2, 1), x >> 8) << 16),
    "half_round_trip": (src, 4, 4, lambda x: cvt((0, 0), (1, 0), cvt((1, 0), (0, 0), x))),
}
# to_e4m3x2 reads a float2 per lane: element 2i is the low byte (x), 2i+1 the
# high (y), as __nv_cvt_float2_to_fp8x2 defines it.
x2in = src[: len(src) // 2 * 2]

def check(binf, extra=()):
    S = syms(binf.replace(".bin", ".o"))
    fails = {}
    for name, (ins, es, os_, ref) in cases.items():
        got, err = run(binf, S[name], ins, es, os_, extra)
        if got is None:
            fails[name] = f"did not run: {err}"
            continue
        bad = [(x, g, ref(x)) for x, g in zip(ins, got) if g != ref(x)]
        if bad:
            x, g, w = bad[0]
            fails[name] = f"{len(bad)}/{len(ins)} differ; first {x:#x} -> {g:#x}, want {w:#x}"
    return fails

def x2check(binf, extra=()):
    S = syms(binf.replace(".bin", ".o"))
    n = len(x2in) // 2
    bad = 0
    for w in range(0, n, 32):
        lanes = min(32, n - w)
        pokes = ["-poke", f"{hex(LAUNCH)}=32", "-poke", f"{hex(LAUNCH + 0x20)}={O >> 16}",
                 "-poke", f"{hex(LAUNCH + 0x28)}={A >> 16}"]
        for k in range(2 * lanes):
            pokes += ["-poke", f"{hex(A + 4 * k)}={x2in[2 * w + k]}"]
        peeks = [x for k in range((lanes + 1) // 2) for x in ("-peek", hex(O + 4 * k))]
        r = subprocess.run(["build/ccv-sim", binf, "-entry", hex(S["to_e4m3x2"]),
                            "-threads", str(lanes), *pokes, *peeks, *extra],
                           capture_output=True, text=True)
        vals = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
        if len(vals) != (lanes + 1) // 2:
            return f"did not run: {(r.stderr or r.stdout).strip()[:200]}"
        for i in range(lanes):
            g = (vals[i // 2] >> (16 * (i % 2))) & 0xFFFF
            lo, hi = x2in[2 * (w + i)], x2in[2 * (w + i) + 1]
            want = cvt((2, 0), (0, 0), lo) | cvt((2, 0), (0, 0), hi) << 8
            if g != want:
                if not bad:
                    first = f"lane {w + i}: {lo:#x},{hi:#x} -> {g:#x}, want {want:#x}"
                bad += 1
    return f"{bad}/{n} differ; first {first}" if bad else None

f0 = check(f"{tmp}/f0.bin")
x0 = x2check(f"{tmp}/f0.bin")
total = sum(len(c[0]) for c in cases.values()) + len(x2in) // 2
if f0 or x0:
    for k, v in f0.items():
        print(f"  FAIL  fp8 {k}: {v}")
    if x0:
        print(f"  FAIL  fp8 to_e4m3x2: {x0}")
    sys.exit(1)
print(f"  PASS  fp8: cuda_fp8.h's conversions, native, agree with the reference "
      f"on {total} lanes (every FP8 byte; FP8 grid points and midpoints from FP32)")
fail = 0
x1 = x2check(f"{tmp}/f1.bin")
print(f"  PASS  control -ccv-test-ptx-swap-x2 is caught: {x1}" if x1
      else "  FAIL  control -ccv-test-ptx-swap-x2 still agreed"); fail |= not x1
ns = check(f"{tmp}/f0.bin", ("-ccv-test-fp-no-saturate",))
print(f"  PASS  control -ccv-test-fp-no-saturate is caught: {', '.join(sorted(ns))}" if ns
      else "  FAIL  control -ccv-test-fp-no-saturate still agreed"); fail |= not ns
sys.exit(fail)
PY
[ $? -eq 0 ] || exit 1

d=$(build/ccv-llc "$TMP/l.ll" -o - 2>/dev/null | grep -cE '^\s*dp4\.e(4m3|5m2)')
if [ "$d" -ne 2 ]; then
  echo "  FAIL  $d dp4.e4m3/e5m2 emitted for the two dot products"; exit 1
fi
python3 - "$TMP" <<'PY'
import random, re, subprocess, sys
sys.path.insert(0, "tools")
import nfp_ref as R
tmp = sys.argv[1]
LAUNCH, O, A, B = 0x20000, 0x30000, 0x40000, 0x50000
rng = random.Random(9)

def syms(obj):
    out = subprocess.run(["llvm-nm", obj], capture_output=True, text=True).stdout
    return {l.split()[2]: int(l.split()[0], 16) for l in out.splitlines() if " T " in l}

def run(k, name, xs, ys, accs):
    got = []
    for w in range(0, len(xs), 32):
        n = min(32, len(xs) - w)
        pokes = ["-poke", f"{hex(LAUNCH)}=32"]
        for slot, base in ((0x20, O), (0x28, A), (0x30, B)):
            pokes += ["-poke", f"{hex(LAUNCH + slot)}={base >> 16}"]
        for i in range(n):
            pokes += ["-poke", f"{hex(A + 4 * i)}={xs[w + i]}", "-poke", f"{hex(B + 4 * i)}={ys[w + i]}",
                      "-poke", f"{hex(O + 4 * i)}={accs[w + i]}"]
        peeks = [x for i in range(n) for x in ("-peek", hex(O + 4 * i))]
        r = subprocess.run(["build/ccv-sim", f"{tmp}/f{k}.bin", "-entry", hex(syms(f"{tmp}/f{k}.o")[name]),
                            "-threads", str(n), *pokes, *peeks], capture_output=True, text=True)
        v = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
        if len(v) != n:
            return None
        got += v
    return got

def word(fmt):
    pool = [x for x in range(256) if R.decode(fmt, x).k != "nan"]
    return sum(rng.choice(pool) << (8 * k) for k in range(4))

# 448^2 + 3 x 2^-7: one rounding gives 200704.03125; four give 200704.
crafted = (0x0404047E, 0x3838387E, 0)
cases = {"dot_e4m3": ((2, 0), True), "dot_e5m2": ((2, 1), False)}
bad, total, ctl = [], 0, []
for name, (fmt, acc) in cases.items():
    xs = [word(fmt) for _ in range(256)] + [crafted[0]]
    ys = [word(fmt) for _ in range(256)] + [crafted[1]]
    accs = [rng.getrandbits(32) & 0x3FFFFFFF if acc else 0 for _ in range(256)] + [0]
    if fmt == (2, 1):                   # the crafted words are E4M3's
        xs.pop(); ys.pop(); accs.pop()
    want = [R.op(f"dp:{fmt[0]}:{fmt[1]}", 0, 0, 0, 0, 0, x, y, a if acc else 0x80000000)
            for x, y, a in zip(xs, ys, accs)]
    got = run(0, name, xs, ys, accs)
    total += len(xs)
    if got is None:
        bad.append(f"{name}: did not run")
    elif got != want:
        i = next(i for i in range(len(xs)) if got[i] != want[i])
        bad.append(f"{name}: {sum(g != w for g, w in zip(got, want))}/{len(xs)} differ; "
                   f"first {xs[i]:#x}.{ys[i]:#x}+{accs[i]:#x} -> {got[i]:#x}, want {want[i]:#x}")
    g2 = run(2, name, xs, ys, accs)
    if g2 is not None and g2 != want:
        ctl.append(name)
for b in bad:
    print(f"  FAIL  fp8 {b}")
if bad:
    sys.exit(1)
print(f"  PASS  fp8 dot products: two dp4 emitted, {total} lanes exact-sum-once (O-44)")
print(f"  PASS  control -ccv-fp8-dot=false is caught: {', '.join(ctl)}" if ctl
      else "  FAIL  control -ccv-fp8-dot=false still agreed")
sys.exit(0 if ctl else 1)
PY
[ $? -eq 0 ] || exit 1

asm=$(build/ccv-llc "$TMP/l.ll" -o - 2>/dev/null)
for k in add_e4m3:fadd.f0 sub_e5m2:fsub.f1 mul_e4m3:fmul.f0; do
  body=$(sed -n "/^${k%%:*}:/,/^Lfunc/p" <<< "$asm")
  if ! grep -qE "^\s*${k#*:} " <<< "$body" || grep -qE '^\s*cvt' <<< "$body"; then
    echo "  FAIL  ${k%%:*} is not one native ${k#*:}:"; echo "$body" | head -20; exit 1
  fi
done
python3 - "$TMP" <<'PY'
import re, subprocess, sys
sys.path.insert(0, "tools")
import nfp_ref as R
tmp = sys.argv[1]
LAUNCH, O, A, B = 0x20000, 0x30000, 0x40000, 0x50000

def syms(obj):
    out = subprocess.run(["llvm-nm", obj], capture_output=True, text=True).stdout
    return {l.split()[2]: int(l.split()[0], 16) for l in out.splitlines() if " T " in l}

def run(k, name, xs, ys):
    entry, got = syms(f"{tmp}/f{k}.o")[name], []
    for w in range(0, len(xs), 32):
        n = min(32, len(xs) - w)
        pokes = ["-poke", f"{hex(LAUNCH)}=32"]
        for slot, base in ((0x20, O), (0x28, A), (0x30, B)):
            pokes += ["-poke", f"{hex(LAUNCH + slot)}={base >> 16}"]
        for arr, base in ((xs, A), (ys, B)):
            for q in range((n + 3) // 4):
                v = sum(arr[w + 4 * q + j] << (8 * j) for j in range(4) if 4 * q + j < n)
                pokes += ["-poke", f"{hex(base + 4 * q)}={v}"]
        peeks = [x for q in range((n + 3) // 4) for x in ("-peek", hex(O + 4 * q))]
        r = subprocess.run(["build/ccv-sim", f"{tmp}/f{k}.bin", "-entry", hex(entry),
                            "-threads", str(n), *pokes, *peeks], capture_output=True, text=True)
        v = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
        if len(v) != (n + 3) // 4:
            return None
        got += [(v[j // 4] >> (8 * (j % 4))) & 0xFF for j in range(n)]
    return got

def neg(v): return R.V(v.k, not v.neg, v.q)
OPS = {"+": lambda a, b: R.add(a, b), "-": lambda a, b: R.add(a, neg(b)),
       "*": lambda a, b: R.mul(a, b)}
NAT = {"+": "fadd", "-": "fsub", "*": "fmul"}
def source(op, fa, fb, fo, x, y):     # FP32, then cvt.rn.satfinite
    f = R.encode((0, 0), OPS[op](R.decode(fa, x), R.decode(fb, y)))
    return R.encode(fo, R.decode((0, 0), f))

partners = [0x00, 0x80, 0x01, 0x38, 0xB8, 0x3C, 0x7E, 0xFE, 0x7F, 0x7B, 0x7C, 0x40, 0x08]
xs = [x for x in range(256) for _ in partners]
ys = [p for _ in range(256) for p in partners]
E4, E5 = (2, 0), (2, 1)
kern = {"add_e4m3": ("+", E4, E4, E4), "sub_e5m2": ("-", E5, E5, E5),
        "mul_e4m3": ("*", E4, E4, E4), "add_mixed": ("+", E4, E5, E4)}
bad, agree = [], True
for name, (op, fa, fb, fo) in kern.items():
    want = [source(op, fa, fb, fo, x, y) for x, y in zip(xs, ys)]
    if fa == fb == fo:                # §5.8: the source and native readings agree
        nat = [R.op(NAT[op], fo[1], 2, 2, 2, 0, x, y, 0) for x, y in zip(xs, ys)]
        if nat != want:
            agree = False
            i = next(i for i in range(len(xs)) if nat[i] != want[i])
            bad.append(f"{name}: the native operation and the source differ at "
                       f"{xs[i]:#x} {op} {ys[i]:#x} ({nat[i]:#x} vs {want[i]:#x}) -- §5.8's claim")
    got = run(0, name, xs, ys)
    if got is None:
        bad.append(f"{name}: did not run")
    elif got != want:
        i = next(i for i in range(len(xs)) if got[i] != want[i])
        bad.append(f"{name}: {sum(g != w for g, w in zip(got, want))}/{len(xs)} differ; "
                   f"first {xs[i]:#x} {op} {ys[i]:#x} -> {got[i]:#x}, want {want[i]:#x}")
for b in bad:
    print(f"  FAIL  fp8 {b}")
if bad:
    sys.exit(1)
print(f"  PASS  fp8 add, sub, mul: native at chwidth 8, {4 * len(xs)} lanes equal to "
      f"FP32 then saturating conversion; the native reading agrees (§5.8)")
c = run(3, "add_e4m3", xs, ys)
want = [source("+", E4, E4, E4, x, y) for x, y in zip(xs, ys)]
ok = c is not None and c != want
print("  PASS  control -ccv-test-fp8-wrong-format is caught" if ok
      else "  FAIL  control -ccv-test-fp8-wrong-format still agreed")
sys.exit(0 if ok else 1)
PY
