#!/usr/bin/env bash
# TI-29: ccv-sim -cta, every warp of a CTA in one run, sharing memory, .shared
# and the barriers. test/cuda/cta-reduce.cu on 128 threads, four warps: warp 0
# finishes its first phase in a few dozen issue groups and the others in
# hundreds, so warp 0 is held at each barrier until the last warp arrives.
# Every thread's result, the CTA's sum plus its index, is compared with
# Python. tools/check-atomics.sh runs O-72's atomics.cu on two warps too.
#
# With -oracle, the run writes one record file per warp (CP-30), checked for
# shape here; and -cta on one warp must write what a plain run writes.
#
# Controls: ccv-sim -ccv-test-cta-warp-barrier, a barrier that waits for its
# own warp only, which must give wrong sums; and the same run without -cta,
# which must still be refused (a barrier with other warps unmodelled).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
for t in build/ccv-llc build/ccv-sim build/CCVLowerKernelArgs.so; do
  [ -e "$t" ] || { echo "  $t not built"; exit 1; }
done
CCV_CFLAGS=-Itest/bench ./tools/cuda-to-ir.sh test/cuda/cta-reduce.cu "$TMP/r.ll" >/dev/null || exit 1
opt -load-pass-plugin=build/CCVLowerKernelArgs.so \
    -passes='function(infer-address-spaces),ccv-lower-kernel-args,function(instcombine,gvn,simplifycfg)' \
    -S "$TMP/r.ll" -o "$TMP/r.low.ll" 2>/dev/null || exit 1
build/ccv-llc "$TMP/r.low.ll" -o "$TMP/r.o" -obj 2>"$TMP/err" ||
  { echo "  FAIL  cta-reduce.cu did not compile: $(head -1 "$TMP/err")"; exit 1; }
llvm-objcopy -O binary --only-section=.text "$TMP/r.o" "$TMP/r.bin"
entry=$(llvm-nm "$TMP/r.o" | awk '/ T .*cta_reduce/ {print "0x"$1}')

python3 - "$TMP/r.bin" "$entry" <<'PY'
import re, subprocess, sys
N, L = 128, 0x20000
# Warp 0: 1 and 2 (0 or 1 step). Warps 1-3: inputs with long orbits.
IN = [1 + (i & 1) for i in range(32)] + [27 + 2 * (i % 40) for i in range(32, N)]
def steps(v):
    n = 0
    while v > 1:
        v = 3 * v + 1 if v & 1 else v >> 1
        n += 1
    return n
total = sum(steps(v) for v in IN)
args = ["-threads", str(N), "-poke", f"{hex(L + 24)}=256",
        "-poke", f"{hex(L + 32)}=3", "-poke", f"{hex(L + 36)}=0",
        "-poke", f"{hex(L + 40)}=4", "-poke", f"{hex(L + 44)}=0"]
for i, v in enumerate(IN):
    args += ["-poke", f"{hex(0x30000 + 4 * i)}={v}"]
for i in range(N):
    args += ["-peek", hex(0x40000 + 4 * i)]
fail = 0
def run(extra):
    r = subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", sys.argv[2], *args, *extra],
                       capture_output=True, text=True)
    if r.returncode:
        return None, (r.stderr or r.stdout).strip().splitlines()[0]
    got = [int(v) for v in re.findall(r"\] = (\d+)", r.stdout)]
    bad = [i for i in range(N) if got[i] != total + i]
    groups = next((l.split()[1] for l in r.stdout.splitlines() if "executed" in l), "?")
    return bad, groups
bad, info = run(["-cta"])
if bad is None or bad:
    print(f"  FAIL  cta-reduce.cu on 4 warps: " +
          (f"did not run: {info}" if bad is None else f"{len(bad)} threads wrong"))
    fail = 1
else:
    print(f"  PASS  cta-reduce.cu: 4 warps, a tree sum over .shared across 8 barriers, "
          f"every thread's result right ({info} issue groups)")
bad, info = run(["-cta", "-ccv-test-cta-warp-barrier"])
if bad:
    print(f"  PASS  control -ccv-test-cta-warp-barrier is caught: {len(bad)} threads wrong")
else:
    print(f"  FAIL  control -ccv-test-cta-warp-barrier " +
          ("did not run: " + info if bad is None else "still computed every thread right"))
    fail = 1
# CP-30: -oracle with -cta writes one record file per warp, as the core's
# loader reads a CTA: oracle.jsonl for warp 0, oracle.<w>.jsonl for warp w.
import json, os
tmp = os.path.dirname(sys.argv[1])
bad, info = run(["-cta", "-oracle", f"{tmp}/o.jsonl"])
files = [f"{tmp}/o.jsonl"] + [f"{tmp}/o.{w}.jsonl" for w in range(1, 4)]
why = "" if bad == [] else f"did not run: {info}"
recs = []
if not why:
    if not all(os.path.exists(f) for f in files) or os.path.exists(f"{tmp}/o.4.jsonl"):
        why = "not one file per warp"
    else:
        recs = [[json.loads(l) for l in open(f)] for f in files]
if recs:
    inits = [r[0]["init"] for r in recs]
    finals = [r[-1]["final"] for r in recs]
    steps = [x for r in recs for x in r[1:-1]]
    for w, (i, f, r) in enumerate(zip(inits, finals, recs)):
        rest = {k: v for k, v in i.items() if k not in ("warp_in_cta", "lane_context")}
        if rest != {k: v for k, v in inits[0].items() if k != "warp_in_cta"}:
            why = f"warp {w}'s init differs from warp 0's"
        elif i.get("warp_in_cta", 0) != w or "lane_context" in i:
            why = f"warp {w}'s init names warp {i.get('warp_in_cta', 0)}"
        elif f["mem"] != finals[0]["mem"]:
            why = f"warp {w}'s final memory differs from warp 0's"
        elif [x["seq"] for x in r[1:-1]] != list(range(len(r) - 2)) or \
             f["issue_groups"] != len(r) - 2:
            why = f"warp {w}'s records are not its own sequence"
        elif f["gpr"][0] == finals[(w + 1) % 4]["gpr"][0]:
            why = f"warp {w}'s final registers are another warp's"
    if not why and len(steps) != int(info):
        why = f"{len(steps)} records for {info} issue groups"
if why:
    print(f"  FAIL  -cta -oracle: {why}"); fail = 1
else:
    print(f"  PASS  -cta -oracle: one file per warp, each its own records "
          f"({', '.join(str(len(r) - 2) for r in recs)}), init and final memory shared")
# One warp under -cta is the plain run, record for record.
one = ["-threads", "32"] + args[2:]
for extra, f in ((["-cta"], "c1.jsonl"), ([], "p1.jsonl")):
    subprocess.run(["build/ccv-sim", sys.argv[1], "-entry", sys.argv[2], *one, *extra,
                    "-oracle", f"{tmp}/{f}"], capture_output=True)
if open(f"{tmp}/c1.jsonl").read() == open(f"{tmp}/p1.jsonl").read():
    print("  PASS  -cta on one warp writes the same oracle file as a run without it")
else:
    print("  FAIL  -cta on one warp changes the oracle file"); fail = 1
bad, info = run([])
if bad is None and "TI-29" in info:
    print("  PASS  without -cta, a barrier in a CTA of 128 is still refused")
else:
    print(f"  FAIL  without -cta: {info}")
    fail = 1
sys.exit(fail)
PY
fail=$?
exit $fail
