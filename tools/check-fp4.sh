#!/usr/bin/env bash
# CP-6 stage 2b: CUDA's FP4 (E2M1) conversions both ways, and FP8 with
# __NV_NOSAT, compiled from NVIDIA's own headers (test/cuda/fp4-clang.ll).
# Below sm_100 the headers do these in software on the double's 64 bits;
# lowerCCVFP64Bits rebuilds that on 64-bit integers (F-186). Each kernel runs
# in ccv-sim over test/cuda/fp4-expected.txt's inputs -- every FP4 nibble, and
# every target value, midpoint and their FP32 neighbours, overflow, specials
# and random patterns -- against NVIDIA's code compiled for the host.
#
# Control: ccv-llc -ccv-test-fp64bits-rebias, which widens a float with its
# exponent one too high.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S test/cuda/fp4-clang.ll -o "$TMP/l.ll" 2>/dev/null || { echo "  FAIL  fp4.cu's IR did not lower"; exit 1; }
for v in "0:" "1:-ccv-test-fp64bits-rebias"; do
  build/ccv-llc "$TMP/l.ll" -o "$TMP/f${v%%:*}.o" -obj ${v#*:} 2>"$TMP/err" ||
    { echo "  FAIL  fp4.cu did not compile${v#*:+ (${v#*:})}: $(head -1 "$TMP/err")"; exit 1; }
  llvm-objcopy -O binary --only-section=.text "$TMP/f${v%%:*}.o" "$TMP/f${v%%:*}.bin"
done

python3 - "$TMP" <<'PY'
import re, subprocess, sys
tmp = sys.argv[1]
LAUNCH, O, A = 0x20000, 0x30000, 0x40000
cases = {}
for line in open("test/cuda/fp4-expected.txt"):
    k, x, r = line.split()
    cases.setdefault(k, []).append((int(x, 16), int(r, 16)))
# (input bytes, output bytes) per kernel
SIZES = {"to_e2m1": (4, 1), "to_e4m3_nosat": (4, 1), "to_e5m2_nosat": (4, 1),
         "from_e2m1": (1, 4)}

def syms(obj):
    out = subprocess.run(["llvm-nm", obj], capture_output=True, text=True).stdout
    return {l.split()[2]: int(l.split()[0], 16) for l in out.splitlines() if " T " in l}

def run(binf, entry, ins, isz, osz):
    got = []
    for w in range(0, len(ins), 32):
        chunk = ins[w:w + 32]
        pokes = ["-poke", f"{hex(LAUNCH)}=32",
                 "-poke", f"{hex(LAUNCH + 0x20)}={O >> 16}",
                 "-poke", f"{hex(LAUNCH + 0x28)}={A >> 16}"]
        per = 4 // isz
        words = [0] * ((len(chunk) * isz + 3) // 4)
        for k, v in enumerate(chunk):
            words[k // per] |= v << (8 * isz * (k % per))
        for k, v in enumerate(words):
            pokes += ["-poke", f"{hex(A + 4 * k)}={v}"]
        nout = (len(chunk) * osz + 3) // 4
        peeks = [x for k in range(nout) for x in ("-peek", hex(O + 4 * k))]
        r = subprocess.run(["build/ccv-sim", binf, "-entry", hex(entry),
                            "-threads", str(len(chunk)), *pokes, *peeks],
                           capture_output=True, text=True)
        vals = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
        if len(vals) != nout:
            return None, (r.stderr or r.stdout).strip()[:300]
        oper = 4 // osz
        for k in range(len(chunk)):
            got.append((vals[k // oper] >> (8 * osz * (k % oper))) & ((1 << (8 * osz)) - 1))
    return got, ""

fail, caught = 0, 0
for v in ("0", "1"):
    S = syms(f"{tmp}/f{v}.o")
    for name, pairs in cases.items():
        ins = [x for x, _ in pairs]
        got, err = run(f"{tmp}/f{v}.bin", S[name], ins, *SIZES[name])
        bad = [(x, g, r) for (x, r), g in zip(pairs, got or [])] if got else []
        bad = [b for b in bad if b[1] != b[2]]
        if v == "0":
            if got is None or bad:
                first = f"; first: {name}({bad[0][0]:08x}) = {bad[0][1]:08x}, want {bad[0][2]:08x}" if bad else f": {err}"
                print(f"  FAIL  {name}: {len(bad) if got else 'did not run'}{first}")
                fail = 1
            else:
                print(f"  PASS  {name}: {len(pairs)} inputs as NVIDIA's header computes them")
        elif got is None or bad:
            caught += 1
if caught:
    print(f"  PASS  control -ccv-test-fp64bits-rebias is caught in {caught} of {len(cases)} kernels")
else:
    print("  FAIL  control -ccv-test-fp64bits-rebias still computed every input right")
    fail = 1
sys.exit(fail)
PY
