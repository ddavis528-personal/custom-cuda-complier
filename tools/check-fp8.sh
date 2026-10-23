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
