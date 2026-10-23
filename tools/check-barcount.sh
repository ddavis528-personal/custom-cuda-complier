#!/usr/bin/env bash
# O-74: named barriers with a thread count. test/cuda/barcount.cu on 160
# threads (ccv-sim -cta, five warps): two producer warps and two consumer
# warps double-buffer through .shared on four barriers counting 128 each, and
# a fifth warp, which takes no part in them, waits on a fifth for the
# consumers' 64 arrivals. Every output word is compared with Python. The
# compiler gives each ID one bar.init at the entry, since one count serves
# the kernel, and __syncthreads none (CCVBarrierInit): both are checked in
# the assembly.
#
# Control: ccv-sim -ccv-test-bar-ignore-count, bar.init as a no-op (before
# O-74), under which barrier 0 waits for the fifth warp, which waits for the
# consumers: a deadlock, which must be reported.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
for t in build/ccv-llc build/ccv-sim build/CCVLowerKernelArgs.so; do
  [ -e "$t" ] || { echo "  $t not built"; exit 1; }
done
# clang refuses the sync-with-count builtin without a PTX version, which only
# a CUDA install would otherwise supply.
CCV_CFLAGS="-Itest/bench -Xclang -target-feature -Xclang +ptx70" \
  ./tools/cuda-to-ir.sh test/cuda/barcount.cu "$TMP/b.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/b.ll" -o "$TMP/b.low.ll" 2>/dev/null || exit 1
build/ccv-llc "$TMP/b.low.ll" -o "$TMP/b.s" 2>"$TMP/err" &&
build/ccv-llc "$TMP/b.low.ll" -o "$TMP/b.o" -obj 2>>"$TMP/err" ||
  { echo "  FAIL  barcount.cu did not compile: $(head -1 "$TMP/err")"; exit 1; }
llvm-objcopy -O binary --only-section=.text "$TMP/b.o" "$TMP/b.bin"
entry=$(llvm-nm "$TMP/b.o" | awk '/ T .*barcount/ {print "0x"$1}')

fail=0
inits=$(grep -oE 'bar\.init [0-9]+, [0-9]+' "$TMP/b.s" | sort | xargs)
if [ "$inits" = "bar.init 0, 128 bar.init 1, 128 bar.init 2, 128 bar.init 3, 128 bar.init 4, 96" ]; then
  echo "  PASS  one bar.init per barrier, at the entry: $(grep -c 'bar\.init' "$TMP/b.s") for 5 IDs"
else
  echo "  FAIL  bar.init emitted: '$inits'"; fail=1
fi
CCV_CFLAGS=-Itest/bench ./tools/cuda-to-ir.sh test/cuda/cta-reduce.cu "$TMP/r.ll" >/dev/null &&
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/r.ll" -o "$TMP/r.low.ll" 2>/dev/null && build/ccv-llc "$TMP/r.low.ll" -o "$TMP/r.s" || exit 1
if grep -q 'bar\.init' "$TMP/r.s"; then
  echo "  FAIL  __syncthreads() kept a bar.init"; fail=1
else
  echo "  PASS  __syncthreads() needs no bar.init: count 0 is the launch's"
fi

python3 - "$TMP/b.bin" "$entry" <<'PY' || fail=1
import random, re, subprocess, sys
N, L, ITER = 160, 0x20000, 8
random.seed(74)
IN = [random.getrandbits(20) for _ in range(ITER * 64)]
want = [sum(IN[k * 64 + c] * 3 + k for k in range(ITER)) & 0xFFFFFFFF for c in range(64)]
want += [(want[l] + want[32 + l]) & 0xFFFFFFFF for l in range(32)]
args = ["-threads", str(N), "-cta", "-poke", f"{hex(L + 24)}=256",
        "-poke", f"{hex(L + 32)}=3", "-poke", f"{hex(L + 36)}=0",
        "-poke", f"{hex(L + 40)}=4", "-poke", f"{hex(L + 44)}=0"]
for i, v in enumerate(IN):
    args += ["-poke", f"{hex(0x30000 + 4 * i)}={v}"]
for i in range(96):
    args += ["-peek", hex(0x40000 + 4 * i)]
def run(extra):
    r = subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", sys.argv[2], *args, *extra],
                       capture_output=True, text=True)
    if r.returncode:
        return None, (r.stderr or r.stdout).strip().splitlines()[0]
    got = [int(v) for v in re.findall(r"\] = (\d+)", r.stdout)]
    groups = next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?")
    return [i for i in range(96) if got[i] != want[i]], groups
fail = 0
bad, info = run([])
if bad == []:
    print(f"  PASS  barcount.cu: producers, consumers and a bystander warp on five counted "
          f"barriers, all 96 words right ({info} issue groups)")
else:
    print(f"  FAIL  barcount.cu: " + (f"did not run: {info}" if bad is None else f"{len(bad)} words wrong"))
    fail = 1
bad, info = run(["-ccv-test-bar-ignore-count"])
if bad is None and "deadlock" in info:
    print(f"  PASS  control -ccv-test-bar-ignore-count is caught: {info[7:70]}...")
else:
    print(f"  FAIL  control -ccv-test-bar-ignore-count: " +
          (info if bad is None else f"{len(bad)} words wrong, no deadlock"))
    fail = 1
sys.exit(fail)
PY
exit $fail
