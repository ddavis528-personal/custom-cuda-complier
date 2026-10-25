#!/usr/bin/env bash
# F-195: a truncation to 16 bits clears the high half wherever a 32-bit read
# would see it. test/cuda/trunc16.ll computes (uint16_t)(x >> 5) >> (t & 7) on
# 32 lanes whose x have bits set throughout, against Python.
#
# Controls, which must fail: ccv-llc -ccv-test-trunc-no-narrow, which drops
# the clearing, and -ccv-test-trunc-as-copy, the truncation as the register
# copy it was before F-195; and for F-200, -ccv-test-narrow-no-partition, which
# lets 32-bit values into a narrow kernel's 16-bit registers.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args' \
    -S test/cuda/trunc16.ll -o "$TMP/t.ll" 2>/dev/null ||
  { echo "  FAIL  trunc16.ll did not lower"; exit 1; }
# Two ways the truncation is made: a narrow kernel's (F-200, the default for
# this call-free kernel), where a 32-bit destination is cleared by the ALU, and
# the 16-bit-legal path without one (-ccv-test-i16-legal -ccv-no-narrow-kernels),
# where it is a chwidth pair. Both must compute right; the controls run on the
# second, the path they were written for.
L="-ccv-test-i16-legal -ccv-no-narrow-kernels"
for v in "0:" "3:$L" "1:$L -ccv-test-trunc-no-narrow" "2:$L -ccv-test-trunc-as-copy" \
         "4:-ccv-test-trunc-no-narrow" "5:-ccv-test-narrow-no-partition"; do
  build/ccv-llc "$TMP/t.ll" -o "$TMP/t${v%%:*}.o" -obj ${v#*:} 2>"$TMP/err" ||
    { echo "  FAIL  trunc16.ll did not compile${v#*:+ (${v#*:})}: $(head -1 "$TMP/err")"; exit 1; }
  llvm-objcopy -O binary --only-section=.text "$TMP/t${v%%:*}.o" "$TMP/t${v%%:*}.bin"
done
entry=$(llvm-nm "$TMP/t0.o" | awk '/ T trunc16/ {print "0x"$1}')
python3 - "$TMP" "$entry" <<'PY'
import random, re, subprocess, sys
tmp, entry = sys.argv[1], sys.argv[2]
N, L, O, A = 32, 0x20000, 3, 4
random.seed(195)
IN = [random.getrandbits(32) | 0x80000000 for _ in range(N)]
want = [((x >> 5) & 0xFFFF) >> (t & 7) for t, x in enumerate(IN)]
def run(v):
    args = ["-entry", entry, "-threads", str(N), "-poke", f"{L:#x}={N}",
            "-poke", f"{L + 32:#x}={O}", "-poke", f"{L + 36:#x}=0",
            "-poke", f"{L + 40:#x}={A}", "-poke", f"{L + 44:#x}=0"]
    for t, x in enumerate(IN):
        # The output word starts as garbage, so a store narrower than the
        # word it owes leaves some of it behind.
        args += ["-poke", f"{(A << 16) + 4 * t:#x}={x}",
                 "-poke", f"{(O << 16) + 4 * t:#x}=3735928559",
                 "-peek", f"{(O << 16) + 4 * t:#x}"]
    r = subprocess.run(["build/ccv-sim", f"{tmp}/t{v}.bin", *args], capture_output=True, text=True)
    return [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
fail = 0
got = run(0)
bad = [t for t in range(N) if t >= len(got) or got[t] != want[t]]
if bad:
    t = bad[0]
    print(f"  FAIL  trunc16: {len(bad)} of {N} lanes wrong; lane {t}: {got[t] if t < len(got) else None}, want {want[t]}")
    fail = 1
else:
    print(f"  PASS  trunc16: a truncation read at 32 bits has its high half clear, {N} lanes")
if run(3) != want:
    print("  FAIL  trunc16 on the 16-bit-legal path (no narrow kernel) computed wrong"); fail = 1
else:
    print("  PASS  trunc16 on the 16-bit-legal path, no narrow kernel, too")
for v, name in (("1", "-ccv-test-trunc-no-narrow (16-bit-legal path)"),
                ("2", "-ccv-test-trunc-as-copy (16-bit-legal path)"),
                ("4", "-ccv-test-trunc-no-narrow (narrow kernel)"),
                ("5", "-ccv-test-narrow-no-partition (narrow kernel)")):
    if run(v) == want:
        print(f"  FAIL  control {name} still computed every lane right"); fail = 1
    else:
        print(f"  PASS  control {name} is caught")
sys.exit(fail)
PY
