#!/usr/bin/env python3
"""
Frame sizes, frame traffic, and register-base indexed stores (AR-23, PF-43).

AR-23 asks whether .local should interleave lanes, and two of its options need
numbers from the compiler:

  extent     each kernel's per-thread frame, its own and everything it calls
             (the static layout, F-21), in 4-byte words. Option (ii) -- R15 the
             warp's window, a second reserved register holding 4 x laneid,
             disp = 128 w -- reaches only words w with 128 w inside Format D's
             13-bit signed displacement: 32 words a thread on one side of R15.
  frame st   transfers through R15 in the code, the default against R0
             reserved as the lane-index register (-ccv-reserve-lane-index):
             what (ii)'s GPR costs in spills, statically.
  frame dyn  the same, issued, for the kernels with a known launch: the ten
             bench kernels (tools/bench.py's arguments), rope and layernorm
             (tools/export-kernels.py's), and the CoreMark-derived workload
             (one iteration, 32 lanes).

PF-43 (TI-32) asks for the dynamic count of indexed stores with a register
base -- the only memop that needs three per-lane values in the address
channel -- as a share of all memops: `st idx` below, ST_GLOBAL_IDX and
ST_SHARED_IDX at every width, issued, over `memops`, every issued load and
store. The slot form (O-45) has no register base and is not counted.

Issue counts are warp issue groups. Every dynamic run checks nothing beyond
running to completion; the kernels' results are checked by the gate's own
tests, at these launches or the exports'.

Usage: sweep-frames.py
"""
import glob, importlib.util, json, os, re, subprocess, sys, tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LLC = f"{ROOT}/build/ccv-llc"
SIM = f"{ROOT}/build/ccv-sim"
LAUNCH = 0x20000
FRAME = re.compile(r"^\s*(?:ld|st)\.(?:global|pred)\S*\s.*\[r15\b", re.M)


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, os.path.join(ROOT, path))
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def sh(*cmd, **kw):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, **kw)


def lower(src, out, flags=""):
    env = dict(os.environ, CCV_CFLAGS=f"-Itest/bench -Itest/cuda/fusion {flags}")
    r = sh("./tools/cuda-to-asm.sh", src, f"{out}.s", out, env=env)
    return f"{out}-lowered.ll" if r.returncode == 0 else None


def static(ll):
    """Frame extent in words, and frame transfers in the code, default and
    with the lane-index register reserved."""
    r = sh(LLC, ll, "-o", "-", "-ccv-frame-stats")
    if r.returncode:
        return None
    ext = [int(b) for b in re.findall(r"frame \S+: (\d+) bytes", r.stderr)]
    r2 = sh(LLC, ll, "-o", "-", "-ccv-reserve-lane-index")
    return (max(ext, default=0) // 4, len(FRAME.findall(r.stdout)),
            len(FRAME.findall(r2.stdout)) if r2.returncode == 0 else None)


def dynamic(ll, pokes, tmp, extra=(), sim_extra=()):
    """Issue groups, frame transfers, memops and register-base indexed stores
    issued, from the oracle's records."""
    o, b, orc = f"{tmp}/d.o", f"{tmp}/d.bin", f"{tmp}/d.jsonl"
    if sh(LLC, ll, "-o", o, "-obj", *extra).returncode:
        return None
    for sec, path in (("text", b), ("ccv_data", f"{tmp}/d.data"),
                      ("ccv_reloc", f"{tmp}/d.reloc"), ("ccv_info", f"{tmp}/d.info")):
        sh("llvm-objcopy", "-O", "binary", f"--only-section=.{sec}", o, path)
    entry = next((l.split()[0] for l in sh("llvm-nm", o).stdout.splitlines()
                  if l.split()[1:2] == ["T"]), "0")
    args = [SIM, b, "-entry", "0x" + entry, "-max-steps", "200000000", "-oracle", orc,
            *sim_extra]
    if os.path.getsize(f"{tmp}/d.data"):
        args += ["-data", f"{tmp}/d.data", "-data-info", f"{tmp}/d.info"]
        if os.path.getsize(f"{tmp}/d.reloc"):
            args += ["-data-reloc", f"{tmp}/d.reloc"]
    for a, v in pokes:
        args += ["-poke", f"{a:#x}={v}"]
    r = subprocess.run(args, capture_output=True, text=True)
    if r.returncode:
        return None
    n = frame = mem = idx = 0
    for line in open(orc):
        rec = json.loads(line)
        if "op" not in rec:
            continue
        n += 1
        if rec["load"] or rec["store"]:
            mem += 1
            if any(u["reg"] == "R15" for u in rec["uses"]):
                frame += 1
            if rec["store"] and re.match(r"ST_(GLOBAL|SHARED)_IDX", rec["op"]):
                idx += 1
    return n, frame, mem, idx


def main():
    bench = load("bench", "tools/bench.py")
    exp = load("export", "tools/export-kernels.py")
    sweep = load("sweep", "tools/sweep-coremark.py")
    rows, dyn = [], []
    with tempfile.TemporaryDirectory() as tmp:
        # Static: every kernel in the corpus.
        srcs = sorted(glob.glob(f"{ROOT}/test/bench/*.cu") + glob.glob(f"{ROOT}/test/cuda/*.cu")
                      + glob.glob(f"{ROOT}/test/cuda/fusion/*.cu"))
        for src in srcs:
            name = os.path.relpath(src, ROOT)
            ll = lower(src, f"{tmp}/s")
            st = static(ll) if ll else None
            rows.append((name, st))
        sweep.build(tmp)
        rows.append(("test/coremark-derived", static(f"{tmp}/cm-lowered.ll")))

        # Dynamic: bench's launches.
        for k, vals in bench.ARGS.items():
            ll = lower(os.path.relpath(bench.source(k), ROOT), f"{tmp}/b{k}", "-DCCV_ALIGNED")
            if not ll:
                continue
            m = re.search(r'ccv-arg-layout"="([^"]*)"', open(ll).read())
            slots = [e for e in m.group(1).split(",") if e] if m else []
            pokes = [(LAUNCH, 32), (LAUNCH + 24, 256)] + \
                    [(LAUNCH + int(s[1:]), v) for s, v in zip(slots, vals)]
            dyn.append((k, ll, pokes, ()))
        for k, fn in exp.KERNELS.items():
            ll = lower(f"test/cuda/fusion/{k}.cu", f"{tmp}/f{k}")
            _, ctas = fn()
            dyn.append((k, ll, ctas[0][0].pokes, ()))
        cm = [(LAUNCH, 32), (LAUNCH + 24, 256), (LAUNCH + 32, sweep.MEM), (LAUNCH + 36, 66000),
              (LAUNCH + 40, sweep.OUT), (LAUNCH + 44, 0), (LAUNCH + 48, 1)]
        dyn.append(("coremark-derived", f"{tmp}/cm-lowered.ll", cm, ("-threads", "32")))

        print("  frames, per thread, every kernel in the corpus (static)")
        print(f"  {'kernel':<34} {'words':>6} {'frame st':>9} {'+lane reg':>10}")
        hist = {"0": 0, "1-32": 0, "33-64": 0, ">64": 0}
        for name, st in rows:
            if st is None:
                print(f"  {name:<34} {'--':>6}")
                continue
            w, a, b = st
            hist["0" if w == 0 else "1-32" if w <= 32 else "33-64" if w <= 64 else ">64"] += 1
            print(f"  {name:<34} {w:>6} {a:>9} {b if b is not None else '--':>10}")
        print("  frame words: " + ", ".join(f"{k}: {v}" for k, v in hist.items()) +
              f" of {sum(hist.values())} kernels")
        print()
        print("  issued, at each kernel's launch (dynamic)")
        print(f"  {'kernel':<18} {'issue':>9} {'memops':>8} {'frame':>7} {'+lane reg':>10} "
              f"{'st idx':>7} {'idx/mem':>8}")
        tot = [0, 0, 0, 0, 0]
        for k, ll, pokes, sx in dyn:
            if not ll:
                continue
            d0 = dynamic(ll, pokes, tmp, sim_extra=sx)
            d1 = dynamic(ll, pokes, tmp, ("-ccv-reserve-lane-index",), sx)
            if d0 is None:
                print(f"  {k:<18} did not run")
                continue
            n, frame, mem, idx = d0
            f1 = d1[1] if d1 else None
            print(f"  {k:<18} {n:>9} {mem:>8} {frame:>7} {f1 if f1 is not None else '--':>10} "
                  f"{idx:>7} {100.0 * idx / mem if mem else 0:>7.1f}%")
            for i, v in enumerate((n, mem, frame, f1 or 0, idx)):
                tot[i] += v
        print(f"  {'total':<18} {tot[0]:>9} {tot[1]:>8} {tot[2]:>7} {tot[3]:>10} {tot[4]:>7} "
              f"{100.0 * tot[4] / tot[1] if tot[1] else 0:>7.1f}%")


if __name__ == "__main__":
    main()
