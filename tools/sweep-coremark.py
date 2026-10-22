#!/usr/bin/env python3
"""
The CoreMark-derived workload's run shapes and callee-saved sweep (AR-20).

AR-20 runs each benchmark three ways: one active lane in one warp (latency and
ILP), 32 independent copies on one warp's lanes (SIMT), and four warps (whether
four-wide issue can be filled). AR's response to CP-9 asked the callee-saved
set to be settled by measurement, reporting memory traffic per call beside
spills and instructions, since one GPR saved is 32 lanes x 4 bytes = 128 bytes
each way per warp.

This builds test/coremark-derived once, compiles it at each -ccv-csr setting,
and runs every shape in ccv-sim, checking each thread's four CRCs against the
host build of the same harness. Cycles are not measured here: ccv-sim is
functional, and timing is the core's skeleton's (TI). What it reports:

  static     instructions in the image
  issue      issue groups, summed over the shape's warps
  lane-ins   lane-instructions (issue-mask lanes per issue, summed)
  calls      calls issued, summed over warps
  frame      transfers through R15 issued: spills, callee saves and restores,
             stack arguments; R15 addresses nothing else (O-30)
  /call      frame transfers per call, and the warp bytes they move at 128 a
             transfer; a one-lane run moves 4 bytes a lane but occupies the
             same memop

The traffic per call is all frame traffic over all calls, not only the saves:
the sweep's point is what a setting costs in total, and the difference between
two rows is what moving registers between caller- and callee-saved buys.

Usage: sweep-coremark.py [iterations]
"""
import os, re, subprocess, sys, tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
D = "test/coremark-derived"
SIM = "build/ccv-sim"
MEM, OUT = 16, 64                    # windows: 2000 bytes a thread, CRCs
SETTINGS = ["none", "six", "eight"]
SHAPES = [("1 lane", 1, [0]), ("32 lanes", 32, [0]), ("4 warps", 128, [0, 1, 2, 3])]


def sh(*cmd, **kw):
    return subprocess.run(cmd, cwd=ROOT, check=True, capture_output=True, text=True, **kw)


def build(tmp):
    for c in ("core_list_join", "core_matrix", "core_state", "core_util"):
        sh("clang", "-x", "c", "--target=nvptx64-nvidia-cuda", "-O2", "-fno-vectorize",
           "-fno-slp-vectorize", f"-I{D}", "-emit-llvm", "-S", f"{D}/upstream/{c}.c",
           "-o", f"{tmp}/{c}.ll")
    env = dict(os.environ, CCV_CFLAGS=f"-Itest/bench -I{D} -I{D}/upstream "
               "-fno-vectorize -fno-slp-vectorize")
    sh("./tools/cuda-to-ir.sh", f"{D}/kernel.cu", f"{tmp}/kernel.ll", env=env)
    sh("llvm-link", "-S", f"{tmp}/kernel.ll", *[f"{tmp}/{c}.ll" for c in
       ("core_list_join", "core_matrix", "core_state", "core_util")], "-o", f"{tmp}/cm.ll")
    sh("opt", "-load-pass-plugin=build/CCVLowerKernelArgs.so",
       "-passes=function(infer-address-spaces),ccv-lower-kernel-args,"
       "function(instcombine,gvn,simplifycfg)", "-S", f"{tmp}/cm.ll", "-o", f"{tmp}/cm-lowered.ll")
    sh("cc", "-O1", f"-I{D}", f"-I{D}/upstream", "-o", f"{tmp}/host", f"{D}/host.c",
       *[f"{D}/upstream/{c}.c" for c in ("core_list_join", "core_matrix", "core_state", "core_util")])


def image(tmp, csr):
    o = f"{tmp}/cm-{csr}.o"
    sh("build/ccv-llc", f"{tmp}/cm-lowered.ll", "-o", o, "-obj", f"-ccv-csr={csr}")
    for s in ("text", "ccv_data", "ccv_reloc", "ccv_info"):
        sh("llvm-objcopy", "-O", "binary", f"--only-section=.{s}", o, f"{tmp}/{csr}.{s}")
    entry = next("0x" + l.split()[0] for l in sh("llvm-nm", o).stdout.splitlines()
                 if " T _Z8coremark" in l)
    text = open(f"{tmp}/{csr}.text", "rb").read()
    n, pc = 0, 0
    while pc < len(text):                      # length from bits [1:0] (§2)
        pc += {0: 4, 1: 2, 2: 2, 3: 6}[text[pc] & 3]
        n += 1
    return entry, n


def run(tmp, csr, entry, threads, warp, it):
    args = [SIM, f"{tmp}/{csr}.text", "-entry", entry, "-counters", "-max-steps", "200000000",
            "-data", f"{tmp}/{csr}.ccv_data", "-data-info", f"{tmp}/{csr}.ccv_info",
            "-threads", str(threads), "-warp", str(warp),
            "-poke", f"0x20000={threads}", "-poke", "0x20018=256",
            "-poke", f"0x20020={MEM}", "-poke", "0x20024=0",
            "-poke", f"0x20028={OUT}", "-poke", "0x2002c=0", "-poke", f"0x20030={it}"]
    if os.path.getsize(f"{tmp}/{csr}.ccv_reloc"):
        args += ["-data-reloc", f"{tmp}/{csr}.ccv_reloc"]
    lanes = range(32 * warp, min(threads, 32 * warp + 32))
    for t in lanes:
        for k in (0, 4):
            args += ["-peek", f"{(OUT << 16) + 8 * t + k:#x}"]
    r = subprocess.run(args, cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"sweep-coremark: {csr}, {threads} threads, warp {warp} did not run: "
                 f"{(r.stderr or r.stdout).strip().splitlines()[0]}")
    got = {int(m.group(1), 16): int(m.group(2)) for m in
           re.finditer(r"\[(0x[0-9a-f]+)\] = (\d+)", r.stdout)}
    crcs = set()
    for t in lanes:
        w0, w1 = got[(OUT << 16) + 8 * t], got[(OUT << 16) + 8 * t + 4]
        crcs.add(f"{w0 & 0xffff:04x} {w0 >> 16:04x} {w1 & 0xffff:04x} {w1 >> 16:04x}")

    def num(pat):
        return int(re.search(pat, r.stdout).group(1))
    return crcs, {"issue": num(r"issue groups\s+(\d+)"),
                  "lane": num(r"lane-instructions\s+(\d+)"),
                  "frame": num(r"spill:(\d+)"), "calls": num(r"(\d+) calls\)")}


def main():
    it = int(sys.argv[1]) if len(sys.argv) > 1 else 2
    with tempfile.TemporaryDirectory() as tmp:
        build(tmp)
        want = sh(f"{tmp}/host", str(it)).stdout.strip()
        if not want.endswith(" e714 1fd7 8e3a"):
            sys.exit(f"sweep-coremark: the host reference is not CoreMark's: {want}")
        print(f"  CoreMark-derived workload, {it} iterations a thread; every thread's CRCs "
              f"checked against the host's ({want})")
        print(f"  {'csr':<6} {'shape':<9} {'static':>6} {'issue':>9} {'lane-ins':>10} "
              f"{'calls':>6} {'frame':>7} {'/call':>6} {'bytes/call':>10}")
        bad = 0
        for csr in SETTINGS:
            entry, static = image(tmp, csr)
            for shape, threads, warps in SHAPES:
                tot = {"issue": 0, "lane": 0, "frame": 0, "calls": 0}
                for w in warps:
                    crcs, c = run(tmp, csr, entry, threads, w, it)
                    if crcs != {want}:
                        bad = 1
                        print(f"  FAIL  {csr}, {shape}, warp {w}: CRCs {sorted(crcs)}")
                    for k in tot:
                        tot[k] += c[k]
                per = tot["frame"] / tot["calls"] if tot["calls"] else 0.0
                print(f"  {csr:<6} {shape:<9} {static:>6} {tot['issue']:>9} {tot['lane']:>10} "
                      f"{tot['calls']:>6} {tot['frame']:>7} {per:>6.1f} {128 * per:>10.0f}")
    sys.exit(bad)


if __name__ == "__main__":
    main()
