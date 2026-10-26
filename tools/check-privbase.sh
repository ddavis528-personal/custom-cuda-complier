#!/usr/bin/env bash
# O-83 (§5.9; PF-46, DA tab rev 95): __ccv_privbase, executed.
#
# test/cuda/privbase.cu: each of 32 threads writes eight words at the same
# pointer and sums them back. Every thread must read its own words, and they
# must lie interleaved, word i of lane l at R(0) + 128*i + 4*l. A size over L
# must give the source's null at run time, and a constant one must not
# compile; with -ccv-priv-windows=2 (and ccv-sim's -priv-windows 2) L doubles
# and the same size works. Then CoreMark-derived with its blocks in the region
# (-DCCV_PRIV_BASE): every lane's CRCs are the host's, and a load touches
# about one line.
#
# Controls, which must fail: ccv-sim -ccv-test-priv-contiguous (each lane's
# region contiguous, so the cells are not where O-83 puts them, and
# CoreMark's loads touch many lines again).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0
SIMA="-lane-contexts 1024 -poke 0x20018=256"     # W = 256 + 3 * 1024 = 3328
REG=$((3329 << 16))                               # warp context 0's region

build() {   # <out-stem> [CCV_CFLAGS] [CCV_OPTFLAGS]
  CCV_CFLAGS="-Itest/bench ${2:-}" CCV_OPTFLAGS="${3:-}" \
    ./tools/cuda-to-asm.sh test/cuda/privbase.cu "$1.s" "$1" >/dev/null 2>&1 || return 1
  build/ccv-llc "$1-lowered.ll" -o "$1.o" -obj 2>/dev/null &&
    llvm-objcopy -O binary --only-section=.text "$1.o" "$1.bin"
}
run() {     # <bin> <n> [ccv-sim flags...]: each thread's sum, then lane cells
  local bin=$1 n=$2; shift 2
  local p=""
  for l in 0 1 31; do p="$p -peek $(printf 0x%x $((0x30000 + 4 * l)))"; done
  for l in 0 1 31; do p="$p -peek $(printf 0x%x $((REG + 128 * 5 + 4 * l)))"; done
  build/ccv-sim "$bin" $SIMA -poke 0x20000=32 -poke 0x20020=3 -poke 0x20024=0 \
    -poke 0x20028=$n $p "$@" 2>&1 | grep -oP '\] = \K\d+' | xargs
}
build "$TMP/p" || { echo "  FAIL  privbase.cu did not compile"; exit 1; }
want="28 156 3996 5 21 501"            # 128t + 28; word 5 of lane l is 16l + 5
got=$(run "$TMP/p.bin" 1024)
ctl=$(run "$TMP/p.bin" 1024 -ccv-test-priv-contiguous)
null=$(run "$TMP/p.bin" 70000 | cut -d' ' -f1-3)
if [ "$got" = "$want" ] && [ "${ctl% * * *}" = "${want% * * *}" ] && [ "$ctl" != "$want" ] &&
   [ "$null" = "4294967295 4294967295 4294967295" ]; then
  echo "  PASS  __ccv_privbase: 32 threads read their own words at one pointer, interleaved a lane a word; a size over L gives null (control: contiguous regions are caught)"
else
  echo "  FAIL  privbase: got '$got', want '$want'; contiguous '$ctl'; over L '$null'"; fail=1
fi

# A constant size over L does not compile, and names the limit; at
# -ccv-priv-windows=2 it does, and runs with ccv-sim's -priv-windows 2.
CCV_CFLAGS="-Itest/bench -DPRIV_CONST=70000" ./tools/cuda-to-ir.sh test/cuda/privbase.cu "$TMP/c.ll" >/dev/null 2>&1
err=$(opt -load-pass-plugin=build/CCVLowerKernelArgs.so -passes=ccv-lower-kernel-args \
        -S "$TMP/c.ll" -o /dev/null 2>&1)
if grep -q "interleaved region is 65536 bytes" <<< "$err" &&
   build "$TMP/w2" "-DPRIV_CONST=70000" "-ccv-priv-windows=2" &&
   [ "$(run "$TMP/w2.bin" 0 -priv-windows 2 | cut -d' ' -f1-3)" = "28 156 3996" ]; then
  echo "  PASS  a constant size over L is a compile error naming L; at -ccv-priv-windows=2 it compiles and runs"
else
  echo "  FAIL  constant size: '$err'"; fail=1
fi

# CoreMark-derived with its per-thread blocks in the region.
D=test/coremark-derived
python3 - "$TMP" <<'PY' || fail=1
import importlib.util, json, os, re, subprocess, sys
tmp = sys.argv[1]
spec = importlib.util.spec_from_file_location("sw", "tools/sweep-coremark.py")
sw = importlib.util.module_from_spec(spec); spec.loader.exec_module(sw)
sw.build(tmp, "-DCCV_PRIV_BASE", "pv")
o = f"{tmp}/pv.o"
subprocess.run(["build/ccv-llc", f"{tmp}/pv-lowered.ll", "-o", o, "-obj"], check=True)
for sec in ("text", "ccv_data", "ccv_reloc", "ccv_info"):
    subprocess.run(["llvm-objcopy", "-O", "binary", f"--only-section=.{sec}", o,
                    f"{tmp}/pv.{sec}"], check=True)
entry = next("0x" + l.split()[0] for l in subprocess.run(["llvm-nm", o], capture_output=True,
             text=True).stdout.splitlines() if " T _Z8coremark" in l)
want = subprocess.run([f"{tmp}/host", "1"], capture_output=True, text=True).stdout.strip()
N, OUT = 32, 7
def go(*extra):
    args = ["build/ccv-sim", f"{tmp}/pv.text", "-entry", entry, "-data", f"{tmp}/pv.ccv_data",
            "-data-info", f"{tmp}/pv.ccv_info", "-max-steps", "100000000", "-oracle",
            f"{tmp}/pv.jsonl", "-poke", f"0x20000={N}", "-poke", "0x20018=256",
            "-poke", "0x20020=3", "-poke", "0x20024=66000", "-poke", f"0x20028={OUT}",
            "-poke", "0x2002c=0", "-poke", "0x20030=1", *extra]
    if os.path.getsize(f"{tmp}/pv.ccv_reloc"):
        args += ["-data-reloc", f"{tmp}/pv.ccv_reloc"]
    for w in range(2 * N):
        args += ["-peek", f"{(OUT << 16) + 4 * w:#x}"]
    r = subprocess.run(args, capture_output=True, text=True)
    if r.returncode:
        return None, 0
    got = {int(a, 16): int(v) for a, v in re.findall(r"\[(0x[0-9a-f]+)\] = (\d+)", r.stdout)}
    crcs = {f"{got[(OUT << 16) + 8 * t] & 0xffff:04x} {got[(OUT << 16) + 8 * t] >> 16:04x} "
            f"{got[(OUT << 16) + 8 * t + 4] & 0xffff:04x} {got[(OUT << 16) + 8 * t + 4] >> 16:04x}"
            for t in range(N)}
    lines = []
    for line in open(f"{tmp}/pv.jsonl"):
        rec = json.loads(line)
        if rec.get("load") and "mem" in rec:
            m = [a for a in rec["mem"] if a["space"] == "global"]
            if len(m) > 1:
                lines.append(len({a["addr"] >> 7 for a in m}))
    return crcs, sum(lines) / max(1, len(lines))
crcs, per = go()
crc2, per2 = go("-ccv-test-priv-contiguous")
if crcs == {want} and per < 2 and per2 > 10:
    print(f"  PASS  CoreMark-derived in the region: 32 lanes give the host's {want}, "
          f"{per:.2f} lines a load memop (contiguous control: {per2:.1f})")
else:
    print(f"  FAIL  CoreMark-derived in the region: {sorted(crcs or [])}, want {want}; "
          f"{per:.2f} lines a load (control {per2:.1f})")
    sys.exit(1)
PY
exit $fail
