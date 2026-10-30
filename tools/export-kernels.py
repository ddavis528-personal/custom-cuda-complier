#!/usr/bin/env python3
"""
Kernels exported for a consumer with ccv-as and ccv-sim but no ccv-llc (TI-30).

The core's skeleton runs a kernel from ccv-as source plus its launch, the
launch-block words and memory it needs, as -poke lines. For each kernel here
this compiles the CUDA source, disassembles the image to ccv-as syntax
(tools/ccv-dis.py, which checks the source reassembles to the same bytes),
runs every CTA of a fixed launch in ccv-sim, and checks the results against a
Python reference written from the source. Then it writes, per kernel:

  kernel.s     ccv-as source: TableGen opcode names, positional operands
  kernel.bin   the image ccv-as makes from it, which is the compiler's
  launch.txt   threads, the CTAs, and per CTA the -poke lines
  ops.txt      every opcode the kernel issues, with its dynamic count

Each CTA is its own run (`-ctaid i`): the kernels are one warp a CTA and the
CTAs share nothing. The CoreMark-derived workload (AR-20) is exported the same
way, with its entry, its module data among the pokes and its .const range, and
checked by replaying launch.txt alone. Results are checked to a relative 1e-5, since ccv-sim's
rsqrt and the fused multiply-adds round differently from Python's doubles.

Usage: export-kernels.py <out-dir>   (exit 1 if any kernel's results are wrong)
"""
import collections, json, math, os, re, struct, subprocess, sys, tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
JSON = os.path.join(ROOT, "build/generated/CCV.json")
SIM = os.path.join(ROOT, "build/ccv-sim")
LAUNCH = 0x20000


# IS-25 (DA tab rev 97): each kernel's frame extent F, its frames' bytes at the
# bottom of the thread's O-83 region, from the compile that built it. launch.txt
# carries it as 'frame <F>', and the launch sets the region up from it.
FRAME = [0]


def llc(ll, o, *flags):
    """ccv-llc, as every export compiles, keeping the kernel's frame extent."""
    r = subprocess.run([f"{ROOT}/build/ccv-llc", ll, "-o", o, "-obj", "-ccv-frame-stats",
                        *flags], check=True, capture_output=True, text=True)
    sizes = [int(n) for n in re.findall(r"^  frame \S+: (\d+) bytes", r.stderr, re.M)]
    FRAME[0] = max(sizes, default=0)


def frame_line():
    return (f"# F: the kernel's frame bytes at the bottom of each thread's O-83 region (IS-25).\n"
            f"frame {FRAME[0]}\n")


def f2u(x):
    return struct.unpack("<I", struct.pack("<f", x))[0]


def u2f(u):
    return struct.unpack("<f", struct.pack("<I", u & 0xffffffff))[0]


class Launch:
    """One CTA's -poke lines, built from the kernel's argument layout."""

    def __init__(self, threads):
        self.pokes = [(LAUNCH + 0, threads), (LAUNCH + 24, 256)]   # ntid, .local
        self.peeks = []

    def ptr(self, off, window):            # a pointer: window, then offset 0
        self.pokes += [(LAUNCH + off, window), (LAUNCH + off + 4, 0)]

    def word(self, off, v):
        self.pokes.append((LAUNCH + off, v & 0xffffffff))

    def floats(self, window, xs):
        self.pokes += [((window << 16) + 4 * i, f2u(x)) for i, x in enumerate(xs)]

    def ints(self, window, xs):
        self.pokes += [((window << 16) + 4 * i, x & 0xffffffff) for i, x in enumerate(xs)]

    def watch(self, window, n):
        self.peeks += [(window << 16) + 4 * i for i in range(n)]


# --- rope: rotary embedding, query and key heads ---------------------------
def rope(NH=2, NKV=1, HS=64, RD=64, positions=(3, 7), T=32):
    NPOS = 8
    half = RD // 2
    positions = list(positions)
    cache = [math.cos(0.1 * p * (i + 1)) if i < half else math.sin(0.1 * p * (i - half + 1))
             for p in range(NPOS) for i in range(RD)]
    q0 = [((i * 37) % 101 - 50) / 25.0 for i in range(len(positions) * NH * HS)]
    k0 = [((i * 53) % 97 - 48) / 24.0 for i in range(len(positions) * NKV * HS)]
    ctas = []
    for tok in range(len(positions)):
        L = Launch(T)
        L.ptr(32, 3); L.ptr(40, 4); L.ptr(48, 5); L.ptr(56, 6)
        L.word(64, NH); L.word(68, NKV); L.word(72, HS); L.word(76, RD)
        L.ints(3, positions); L.floats(4, q0); L.floats(5, k0); L.floats(6, cache)
        L.watch(4, len(q0)); L.watch(5, len(k0))
        pos = positions[tok]
        q, k = list(q0), list(k0)
        for vec, heads in ((q, NH), (k, NKV)):
            for h in range(heads):
                b = (tok * heads + h) * HS
                for i in range(half):
                    c, s = cache[pos * RD + i], cache[pos * RD + half + i]
                    x, y = vec[b + i], vec[b + half + i]
                    vec[b + i], vec[b + half + i] = x * c - y * s, y * c + x * s
        want = {(4 << 16) + 4 * i: v for i, v in enumerate(q)}
        want.update({(5 << 16) + 4 * i: v for i, v in enumerate(k)})
        ctas.append((L, want))
    return T, ctas


# --- layernorm: one row a CTA, saved mean and rstd ---------------------------
def layernorm():
    T, H, ROWS, EPS = 32, 96, 2, 1e-5
    x = [((i * 29) % 83 - 41) / 16.0 for i in range(ROWS * H)]
    w = [1.0 + ((i * 7) % 11) / 20.0 for i in range(H)]
    bias = [((i * 5) % 13 - 6) / 10.0 for i in range(H)]
    ctas = []
    for row in range(ROWS):
        L = Launch(T)
        for k, win in enumerate((3, 4, 5, 6, 7, 8)):        # out mean rstd in w b
            L.ptr(32 + 8 * k, win)
        L.word(80, f2u(EPS)); L.word(84, H)
        L.floats(6, x); L.floats(7, w); L.floats(8, bias)
        L.watch(3, ROWS * H); L.watch(4, ROWS); L.watch(5, ROWS)
        r = x[row * H:(row + 1) * H]
        m = sum(r) / H
        var = sum(v * v for v in r) / H - m * m
        rstd = 1.0 / math.sqrt(var + EPS)
        want = {(3 << 16) + 4 * (row * H + i): (r[i] - m) * rstd * w[i] + bias[i]
                for i in range(H)}
        want[(4 << 16) + 4 * row] = m
        want[(5 << 16) + 4 * row] = rstd
        ctas.append((L, want))
    return T, ctas


# rope-diverged is check-fusion.py's geometry, rot_dim 8: half is 4, so only
# lanes 0-3 work in each loop and the warp diverges. It is the shape whose
# fairness picks set CCV_FAIR_N (CP's IS-17 sweep, AR's rev 121); the default
# rope, rot_dim 64, keeps all 32 lanes busy and makes none (AR's rev 143).
KERNELS = {"rope": rope,
           "rope-diverged": lambda: rope(2, 1, 8, 8, (1, 1)),
           "layernorm": layernorm}
SOURCE = {"rope-diverged": "rope"}


def build(name, tmp):
    name = SOURCE.get(name, name)
    env = dict(os.environ, CCV_CFLAGS="-Itest/bench -Itest/cuda/fusion")
    subprocess.run(["./tools/cuda-to-asm.sh", f"test/cuda/fusion/{name}.cu",
                    f"{tmp}/{name}.ll.s", f"{tmp}/{name}"],
                   cwd=ROOT, env=env, check=True, capture_output=True)
    llc(f"{tmp}/{name}-lowered.ll", f"{tmp}/{name}.o")
    subprocess.run(["llvm-objcopy", "-O", "binary", "--only-section=.text",
                    f"{tmp}/{name}.o", f"{tmp}/{name}.bin"], check=True)
    for sec in ("ccv_data", "ccv_reloc"):          # module data: none expected
        p = f"{tmp}/{name}.{sec}"
        subprocess.run(["llvm-objcopy", "-O", "binary", f"--only-section=.{sec}",
                        f"{tmp}/{name}.o", p], check=True)
        if os.path.getsize(p):
            sys.exit(f"export-kernels: {name} has module data, which launch.txt "
                     "cannot carry yet")
    nm = subprocess.run(["llvm-nm", f"{tmp}/{name}.o"], capture_output=True,
                        text=True, check=True).stdout
    entry = [l.split()[0] for l in nm.splitlines() if l.split()[1:2] == ["T"]
             and name in l.split()[2]]
    if int(entry[0], 16) != 0:
        sys.exit(f"export-kernels: {name}'s entry is not at offset 0")
    src = subprocess.run([sys.executable, f"{ROOT}/tools/ccv-dis.py", JSON,
                          f"{tmp}/{name}.bin", "--check"],
                         capture_output=True, text=True, check=True).stdout
    return src, open(f"{tmp}/{name}.bin", "rb").read()


def run(binpath, cta, L, oracle):
    args = [SIM, binpath, "-ctaid", str(cta), "-oracle", oracle]
    for a, v in L.pokes:
        args += ["-poke", f"{a:#x}={v}"]
    for a in L.peeks:
        args += ["-peek", f"{a:#x}"]
    r = subprocess.run(args, capture_output=True, text=True)
    if r.returncode:
        return None, (r.stderr or r.stdout).strip().splitlines()[0]
    got = {}
    for line in r.stdout.splitlines():
        if line.strip().startswith("[0x"):
            a, v = line.split("=")
            got[int(a.strip()[1:-1], 16)] = int(v.split()[0])
    return got, r.stdout


def export_coremark(out, tmp, per_lane=False, priv=False):
    """The CoreMark-derived workload (AR-20): module data, calls, an entry past
    its device functions. Its pokes are the oracle init record's seeded memory
    from a run with the data image, so they are exactly what ccv-sim loads: the
    launch block, the relocated image and word 28. Checked by every lane's
    CRCs against the host build; the control runs without the image.

    per_lane: coremark-derived-pl (AR-24's fourth shape), lane t seeded with t,
    so the lanes take their own paths and the warp diverges; it is the core's
    O-81 control kernel. Lane t's CRCs are the host's at seed t.

    priv: coremark-derived-priv, each thread's block in its O-83 interleaved
    region (-DCCV_PRIV_BASE, __ccv_privbase), so a warp's same-offset access is
    one line (PF-46, DA tab rev 95). Its run needs ccv-sim's defaults
    -lane-contexts 4096 and -priv-windows 1, and the launch's word 24."""
    import importlib.util
    spec = importlib.util.spec_from_file_location(
        "sweep", os.path.join(ROOT, "tools/sweep-coremark.py"))
    sw = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(sw)
    name, mod, flag = (("coremark-derived-pl", "pl", "-DCCV_SEED_PER_LANE") if per_lane else
                       ("coremark-derived-priv", "pv", "-DCCV_PRIV_BASE") if priv else
                       ("coremark-derived", "cm", ""))
    sw.build(tmp, flag, mod)
    it, threads, MEMW, OUTW = 1, 32, sw.MEM, sw.OUT
    wants = [subprocess.run([f"{tmp}/host", str(it)] + ([str(t)] if per_lane else []),
                            capture_output=True, text=True, check=True).stdout.strip()
             for t in range(128 if per_lane else 1)]    # AR-20's largest shape
    want = wants[:threads] if per_lane else wants * threads
    o = f"{tmp}/{mod}.o"
    llc(f"{tmp}/{mod}-lowered.ll", o)
    for sec in ("text", "ccv_data", "ccv_reloc", "ccv_info"):
        subprocess.run(["llvm-objcopy", "-O", "binary", f"--only-section=.{sec}", o,
                        f"{tmp}/cm.{sec}"], check=True)
    entry = next(int(l.split()[0], 16) for l in subprocess.run(
        ["llvm-nm", o], capture_output=True, text=True, check=True).stdout.splitlines()
        if " T _Z8coremark" in l)
    src = subprocess.run([sys.executable, f"{ROOT}/tools/ccv-dis.py", JSON,
                          f"{tmp}/cm.text", "--check"],
                         capture_output=True, text=True, check=True).stdout
    launch = [(LAUNCH + 0, threads), (LAUNCH + 24, 256), (LAUNCH + 32, MEMW),
              (LAUNCH + 36, 66000), (LAUNCH + 40, OUTW), (LAUNCH + 44, 0),
              (LAUNCH + 48, it)]

    def go(with_data, oracle, replay=None):
        args = [SIM, f"{tmp}/cm.text", "-entry", hex(entry), "-threads", str(threads),
                "-max-steps", "100000000", "-oracle", oracle]
        if replay is not None:                  # launch.txt alone, as TI runs it
            mem, const = replay
            if const:
                args += ["-const-range", f"{const[0]:#x}:{const[1]:#x}"]
            for a, v in mem:
                args += ["-poke", f"{a:#x}={v}"]
        elif with_data:
            args += ["-data", f"{tmp}/cm.ccv_data", "-data-info", f"{tmp}/cm.ccv_info"]
            if os.path.getsize(f"{tmp}/cm.ccv_reloc"):
                args += ["-data-reloc", f"{tmp}/cm.ccv_reloc"]
        if replay is None:
            for a, v in launch:
                args += ["-poke", f"{a:#x}={v}"]
        for t in range(threads):
            args += ["-peek", f"{(OUTW << 16) + 8 * t:#x}", "-peek", f"{(OUTW << 16) + 8 * t + 4:#x}"]
        r = subprocess.run(args, capture_output=True, text=True)
        if r.returncode:
            return None
        got = {int(m[0], 16): int(m[1]) for m in
               re.findall(r"\[(0x[0-9a-f]+)\] = (\d+)", r.stdout)}
        return [f"{got[(OUTW << 16) + 8 * t] & 0xffff:04x} {got[(OUTW << 16) + 8 * t] >> 16:04x} "
                f"{got[(OUTW << 16) + 8 * t + 4] & 0xffff:04x} {got[(OUTW << 16) + 8 * t + 4] >> 16:04x}"
                for t in range(threads)]

    crcs = go(True, f"{tmp}/cm.jsonl")
    init = json.loads(open(f"{tmp}/cm.jsonl").readline())["init"]
    ops, issued = collections.Counter(), 0
    for line in open(f"{tmp}/cm.jsonl"):
        rec = json.loads(line)
        if "op" in rec:
            ops[rec["op"]] += 1
            issued += 1
    control = go(False, f"{tmp}/ctl.jsonl")
    replayed = go(False, f"{tmp}/rp.jsonl", (init["mem"], init.get("const")))
    d = os.path.join(out, name)
    os.makedirs(d, exist_ok=True)
    open(f"{d}/kernel.s", "w").write(
        f"# {name}: test/coremark-derived{' ' + flag if flag else ''}, compiled; ccv-as source, reassembled\n"
        f"# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base\n"
        f"# (0x1000: function pointers are absolute); the kernel's entry is {entry:#x}.\n" + src)
    open(f"{d}/kernel.bin", "wb").write(open(f"{tmp}/cm.text", "rb").read())
    with open(f"{d}/launch.txt", "w") as f:
        f.write(f"# {name}: ccv-sim kernel.bin -entry <entry> -threads <T> "
                "[-warp <w>] -const-range <const>\n# followed by the pokes: the launch "
                "block and the module's relocated data image, at its window (word 28).\n"
                "# Word 0x20030 is the iteration count; word 0x20000, ntid, follows -threads.\n"
                "# Every lane runs its own context, so AR-20's shapes are -threads 1, 32, and\n"
                "# 128 with -warp 0-3; each thread's CRCs are written to window "
                f"{OUTW:#x}, 8 bytes a thread,\n" +
                (f"# and thread t's must be the host's at seed t ({it} iteration), threads 0..127:\n"
                 + "".join(f"#   {t:2} {w}\n" for t, w in enumerate(wants)) if per_lane else
                 f"# and must be {wants[0]} ({it} iteration).\n"))
        f.write(f"threads {threads}\nctas 1\nentry {entry:#x}\n" + frame_line())
        if "const" in init:
            f.write(f"const {init['const'][0]:#x}:{init['const'][1]:#x}\n")
        f.write("cta 0\n")
        f.writelines(f"-poke {a:#x}={v}\n" for a, v in init["mem"])
    with open(f"{d}/ops.txt", "w") as f:
        f.write(f"# {name}: opcodes issued by one warp of {threads} lanes, "
                f"by ccv-sim's names; {issued} issue groups\n")
        f.writelines(f"{n:<18} {c}\n" for n, c in sorted(ops.items()))
    if crcs != want:
        bad = next((t for t in range(threads) if not crcs or crcs[t] != want[t]), 0)
        print(f"  FAIL  {name}: lane {bad}: {crcs[bad] if crcs else 'did not run'}, "
              f"want {want[bad]}")
        return 1
    if replayed != want:
        print(f"  FAIL  {name}: launch.txt alone does not reproduce every lane's CRCs")
        return 1
    if control == want:
        print(f"  FAIL  {name}: control: without the data image it still matched")
        return 1
    what = ("each lane its own seed, diverging, gives the host's CRCs at that seed"
            if per_lane else f"{threads} lanes give {wants[0]}")
    print(f"  PASS  {name}: {what}; {len(ops)} opcodes, "
          f"{issued} issue groups; launch.txt alone reproduces it, data image included; "
          "without the image it fails")
    return 0


def export_coremark_fault(out, tmp):
    """coremark-derived-pl-fault: O-81's negative kernel (TI's rev 194). The
    per-lane-seed module compiled with -ccv-test-i16-legal, which runs its
    16-bit integers at width 16 by chwidth, as before F-199, so a chwidth
    issues while the warp is diverged and ccv-sim raises F-WIDTH. The export
    checks the fault is F-WIDTH, on a chwidth, from a partial issue mask; that
    the oracle's last record is that fault; that launch.txt alone reproduces
    it; and, as the control, that coremark-derived-pl, the same launch built as
    released, does not fault."""
    import importlib.util
    spec = importlib.util.spec_from_file_location(
        "sweep", os.path.join(ROOT, "tools/sweep-coremark.py"))
    sw = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(sw)
    sw.build(tmp, "-DCCV_SEED_PER_LANE", "pl")
    name, it, threads, MEMW, OUTW = "coremark-derived-pl-fault", 1, 32, sw.MEM, sw.OUT
    o = f"{tmp}/plf.o"
    llc(f"{tmp}/pl-lowered.ll", o, "-ccv-test-i16-legal")
    for sec in ("text", "ccv_data", "ccv_reloc", "ccv_info"):
        subprocess.run(["llvm-objcopy", "-O", "binary", f"--only-section=.{sec}", o,
                        f"{tmp}/plf.{sec}"], check=True)
    entry = next(int(l.split()[0], 16) for l in subprocess.run(
        ["llvm-nm", o], capture_output=True, text=True, check=True).stdout.splitlines()
        if " T _Z8coremark" in l)
    src = subprocess.run([sys.executable, f"{ROOT}/tools/ccv-dis.py", JSON,
                          f"{tmp}/plf.text", "--check"],
                         capture_output=True, text=True, check=True).stdout
    launch = [(LAUNCH + 0, threads), (LAUNCH + 24, 256), (LAUNCH + 32, MEMW),
              (LAUNCH + 36, 66000), (LAUNCH + 40, OUTW), (LAUNCH + 44, 0),
              (LAUNCH + 48, it)]
    base = [SIM, f"{tmp}/plf.text", "-entry", hex(entry), "-threads", str(threads),
            "-max-steps", "100000000"]
    data = ["-data", f"{tmp}/plf.ccv_data", "-data-info", f"{tmp}/plf.ccv_info"]
    if os.path.getsize(f"{tmp}/plf.ccv_reloc"):
        data += ["-data-reloc", f"{tmp}/plf.ccv_reloc"]
    pokes = [x for a, v in launch for x in ("-poke", f"{a:#x}={v}")]

    def fault(r):
        return next((l.strip() for l in r.stdout.splitlines() if "FAULT" in l), None)
    r = subprocess.run(base + data + pokes + ["-oracle", f"{tmp}/plf.jsonl"],
                       capture_output=True, text=True)
    first = fault(r)
    recs = [json.loads(l) for l in open(f"{tmp}/plf.jsonl")]
    init = recs[0]["init"]
    last = next((x for x in reversed(recs) if x.get("kind") == "fault"), {})
    replay = list(base)
    if "const" in init:
        replay += ["-const-range", f"{init['const'][0]:#x}:{init['const'][1]:#x}"]
    replay += [x for a, v in init["mem"] for x in ("-poke", f"{a:#x}={v}")]
    again = fault(subprocess.run(replay, capture_output=True, text=True))

    d = os.path.join(out, name)
    os.makedirs(d, exist_ok=True)
    open(f"{d}/kernel.s", "w").write(
        f"# {name}: test/coremark-derived -DCCV_SEED_PER_LANE, compiled with\n"
        "# -ccv-test-i16-legal so that it FAULTS (O-81's negative kernel); ccv-as\n"
        "# source, reassembled byte for byte by tools/ccv-dis.py --check. Load at\n"
        f"# ccv-sim's -code-base (0x1000); the kernel's entry is {entry:#x}.\n" + src)
    open(f"{d}/kernel.bin", "wb").write(open(f"{tmp}/plf.text", "rb").read())
    with open(f"{d}/launch.txt", "w") as f:
        f.write(f"# {name}: ccv-sim kernel.bin -entry <entry> -threads <T> -const-range "
                "<const>\n# followed by the pokes, as coremark-derived-pl's. It must "
                "not finish: it must raise\n# F-WIDTH at the chwidth fault.txt names, "
                "with that issue mask (O-81).\n")
        f.write(f"threads {threads}\nctas 1\nentry {entry:#x}\n" + frame_line())
        if "const" in init:
            f.write(f"const {init['const'][0]:#x}:{init['const'][1]:#x}\n")
        f.write("cta 0\n")
        f.writelines(f"-poke {a:#x}={v}\n" for a, v in init["mem"])
    with open(f"{d}/fault.txt", "w") as f:
        f.write(f"# {name}: what ccv-sim raises, and its oracle's record of the faulting\n"
                f"# instruction (kind \"fault\"), issue {last.get('seq')}.\n")
        f.write(f"FAULT={first.split()[1] if first else ''}\n{first}\n")
        f.write(json.dumps(last) + "\n")
    ok = (first and first.split()[1] == "F-WIDTH" and last.get("kind") == "fault"
          and "CHWIDTH" in last.get("op", "") and last.get("mask") != 0xffffffff
          and f"pc={last['pc']:#x}" in first)
    if not ok:
        print(f"  FAIL  {name}: want F-WIDTH on a diverged chwidth; got {first}, "
              f"record {last.get('kind')} {last.get('op')} mask {last.get('mask', 0):#x}")
        return 1
    if again != first:
        print(f"  FAIL  {name}: launch.txt alone gives {again}, not {first}")
        return 1
    print(f"  PASS  {name}: {first}, at {last['op']} (issue {last['seq']}, mask {last['mask']:#010x}); "
          "launch.txt alone raises the same; coremark-derived-pl, built as released, "
          "does not fault")
    return 0


# --- AR-24's corpus sweep: one CTA of four warps (TI's rev 227) --------------
# Each kernel runs one CTA of 128 threads as a whole, its four warps sharing
# .shared and the barriers (ccv-sim -cta), and is checked against a reference
# computed here. The inputs are small multiples of 1/8, so every product and
# sum is exact in fp32 and the float kernels' results must match exactly; the
# transcendental ones (rope, layernorm) keep the relative 1e-5 the 32-thread
# exports use. The control runs each launch without its input data.
T4 = 128
DATA = 0x30000                       # windows 3 and up hold the kernels' arrays


def q8(i, mod, off):                  # a small multiple of 1/8, exact in fp32
    return ((i * 37 + off) % mod - mod // 2) / 8.0


def layernorm128():
    H, ROWS, EPS = 512, 2, 1e-5
    x = [((i * 29) % 83 - 41) / 16.0 for i in range(ROWS * H)]
    w = [1.0 + ((i * 7) % 11) / 20.0 for i in range(H)]
    bias = [((i * 5) % 13 - 6) / 10.0 for i in range(H)]
    ctas = []
    for row in range(ROWS):
        L = Launch(T4)
        for k, win in enumerate((3, 4, 5, 6, 7, 8)):        # out mean rstd in w b
            L.ptr(32 + 8 * k, win)
        L.word(80, f2u(EPS)); L.word(84, H)
        L.floats(6, x); L.floats(7, w); L.floats(8, bias)
        L.watch(3, ROWS * H); L.watch(4, ROWS); L.watch(5, ROWS)
        r = x[row * H:(row + 1) * H]
        m = sum(r) / H
        rstd = 1.0 / math.sqrt(sum(v * v for v in r) / H - m * m + EPS)
        want = {(3 << 16) + 4 * (row * H + i): (r[i] - m) * rstd * w[i] + bias[i]
                for i in range(H)}
        want[(4 << 16) + 4 * row] = m
        want[(5 << 16) + 4 * row] = rstd
        ctas.append((L, want, 1e-5))
    return ctas


def rope_diverged128():
    _, ctas = rope(2, 1, 8, 8, (1, 1), T4)
    return [(L, want, 1e-5) for L, want in ctas]


def gemv128():
    K, NCTA = 64, 2
    rows = T4 * NCTA
    W = [q8(i, 15, 3) for i in range(rows * K)]
    x = [q8(i, 9, 1) for i in range(K)]
    y = [sum(W[r * K + k] * x[k] for k in range(K)) for r in range(rows)]
    ctas = []
    for c in range(NCTA):
        L = Launch(T4)
        L.ptr(32, 3); L.ptr(40, 4); L.ptr(48, 5); L.word(56, K)
        L.floats(4, W); L.floats(5, x); L.watch(3, rows)
        ctas.append((L, {(3 << 16) + 4 * r: y[r] for r in range(c * T4, (c + 1) * T4)}, 0))
    return ctas


def sgemm128():
    N, BX, BY, TM, TN = 32, 16, 8, 2, 2
    bpr = N // (BX * TN)
    A = [q8(i, 11, 2) for i in range(N * N)]
    B = [q8(i, 13, 5) for i in range(N * N)]
    C = [sum(A[r * N + k] * B[k * N + c] for k in range(N)) for r in range(N) for c in range(N)]
    ctas = []
    for cta in range((N // (BY * TM)) * bpr):
        brow, bcol = cta // bpr, cta % bpr
        L = Launch(T4)
        L.ptr(32, 3); L.ptr(40, 4); L.ptr(48, 5); L.word(56, N); L.word(60, bpr)
        L.floats(4, A); L.floats(5, B); L.watch(3, N * N)
        want = {(3 << 16) + 4 * (r * N + c): C[r * N + c]
                for r in range(brow * BY * TM, (brow + 1) * BY * TM)
                for c in range(bcol * BX * TN, (bcol + 1) * BX * TN)}
        ctas.append((L, want, 0))
    return ctas


def cta_reduce128():
    vin = [(i * 2654435761) % 1000 + 1 for i in range(T4)]
    def steps(v):
        n = 0
        while v > 1:
            v = 3 * v + 1 if v & 1 else v >> 1
            n += 1
        return n
    total = sum(steps(v) for v in vin)
    L = Launch(T4)
    L.ptr(32, 3); L.ptr(40, 4)
    L.ints(3, vin); L.watch(4, T4)
    return [(L, {(4 << 16) + 4 * t: total + t for t in range(T4)}, None)]


def transpose128():
    n, TILE = 64, 32
    a = [q8(i, 17, 4) for i in range(n * n)]
    ctas = []
    tiles = n // TILE
    for cta in range(tiles * tiles):
        bx, by = cta % tiles, cta // tiles
        L = Launch(T4)
        L.ptr(32, 3); L.ptr(40, 4); L.word(48, n)
        L.floats(4, a); L.watch(3, n * n)
        want = {(3 << 16) + 4 * ((bx * TILE + r) * n + by * TILE + c): a[(by * TILE + c) * n + bx * TILE + r]
                for r in range(TILE) for c in range(TILE)}
        ctas.append((L, want, 0))
    return ctas


# name: (source, extra flags, the argument layout it must have, generator)
KERNELS128 = {
    "rope-diverged-128": ("test/cuda/fusion/rope.cu", "-Itest/cuda/fusion",
                          "p32,p40,p48,p56,s64,s68,s72,s76", rope_diverged128),
    "layernorm-128": ("test/cuda/fusion/layernorm.cu", "-Itest/cuda/fusion -DNWARP_THREADS=128",
                      "p32,p40,p48,p56,p64,p72,s80,s84", layernorm128),
    "gemv-128": ("test/cuda/gemv.cu", "", "p32,p40,p48,s56", gemv128),
    "sgemm-128": ("test/cuda/sgemm.cu", "-DBX=16 -DBY=8", "p32,p40,p48,s56,s60", sgemm128),
    "cta-reduce-128": ("test/cuda/cta-reduce.cu", "", "p32,p40", cta_reduce128),
    "transpose-128": ("test/cuda/transpose32.cu", "", "p32,p40,s48", transpose128),
}


def build128(name, tmp, spec=None):
    src, flags, layout, _ = spec or KERNELS128[name]
    stem = f"{tmp}/{name}"
    env = dict(os.environ, CCV_CFLAGS=f"-Itest/bench {flags}")
    subprocess.run(["./tools/cuda-to-asm.sh", src, f"{stem}.ll.s", stem],
                   cwd=ROOT, env=env, check=True, capture_output=True)
    got = re.search(r'ccv-arg-layout"="([^"]*)"', open(f"{stem}-lowered.ll").read())
    if not got or got.group(1).rstrip(",") != layout:
        sys.exit(f"export-kernels: {name}'s argument layout is "
                 f"{got.group(1) if got else 'missing'}, not {layout}")
    llc(f"{stem}-lowered.ll", f"{stem}.o")
    subprocess.run(["llvm-objcopy", "-O", "binary", "--only-section=.text",
                    f"{stem}.o", f"{stem}.bin"], check=True)
    for sec in ("ccv_data", "ccv_reloc"):
        p = f"{stem}.{sec}"
        subprocess.run(["llvm-objcopy", "-O", "binary", f"--only-section=.{sec}",
                        f"{stem}.o", p], check=True)
        if os.path.getsize(p):
            sys.exit(f"export-kernels: {name} has module data, which launch.txt "
                     "cannot carry yet")
    nm = subprocess.run(["llvm-nm", f"{stem}.o"], capture_output=True, text=True,
                        check=True).stdout
    if not any(l.split()[1:2] == ["T"] and int(l.split()[0], 16) == 0 for l in nm.splitlines()):
        sys.exit(f"export-kernels: {name}'s entry is not at offset 0")
    dis = subprocess.run([sys.executable, f"{ROOT}/tools/ccv-dis.py", JSON, f"{stem}.bin",
                          "--check"], capture_output=True, text=True, check=True).stdout
    return dis, open(f"{stem}.bin", "rb").read()


def run128(binpath, cta, pokes, peeks, oracle):
    args = [SIM, binpath, "-threads", str(T4), "-cta", "-ctaid", str(cta), "-oracle", oracle]
    for a, v in pokes:
        args += ["-poke", f"{a:#x}={v}"]
    for a in peeks:
        args += ["-peek", f"{a:#x}"]
    r = subprocess.run(args, capture_output=True, text=True)
    if r.returncode:
        return None, (r.stderr or r.stdout).strip().splitlines()[0]
    return {int(a, 16): int(v) for a, v in
            re.findall(r"\[(0x[0-9a-f]+)\] = (\d+)", r.stdout)}, r.stdout


def matches(got, want, tol):
    for a, v in want.items():
        g = got.get(a)
        if g is None:
            return f"[{a:#x}] not read"
        if tol is None:
            if g != v:
                return f"[{a:#x}] = {g}, want {v}"
        elif not abs(u2f(g) - v) <= tol * max(1.0, abs(v)):
            return f"[{a:#x}] = {u2f(g)}, want {v}"
    return None


def export128(out, tmp):
    bad = 0
    for name, (src_path, flags, _, gen) in KERNELS128.items():
        dis, image = build128(name, tmp)
        ctas = gen()
        d = os.path.join(out, name)
        os.makedirs(d, exist_ok=True)
        open(f"{d}/kernel.s", "w").write(
            f"# {name}: {src_path}{' ' + flags if flags else ''}, compiled; ccv-as source,\n"
            "# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's\n"
            "# -code-base; entry at offset 0.\n" + dis)
        open(f"{d}/kernel.bin", "wb").write(image)
        ops, issued, wrong = collections.Counter(), 0, []
        for cta, (L, want, tol) in enumerate(ctas):
            got, text = run128(f"{d}/kernel.bin", cta, L.pokes, L.peeks, f"{tmp}/o.jsonl")
            if got is None:
                wrong.append(f"CTA {cta} did not run: {text}"); continue
            for w in range(T4 // 32):
                path = f"{tmp}/o.jsonl" if w == 0 else f"{tmp}/o.{w}.jsonl"
                for line in open(path):
                    rec = json.loads(line)
                    if "op" in rec:
                        ops[rec["op"]] += 1
                        issued += 1
            err = matches(got, want, tol)
            if err:
                wrong.append(f"CTA {cta} {err}")
            # The control: the same launch without its input data must not match.
            bare = [(a, v) for a, v in L.pokes if a < DATA]
            got0, _ = run128(f"{d}/kernel.bin", cta, bare, L.peeks, f"{tmp}/c.jsonl")
            if got0 is not None and matches(got0, want, tol) is None:
                wrong.append(f"control: CTA {cta} without its input data still matched")
        with open(f"{d}/launch.txt", "w") as f:
            f.write(f"# {name}: ccv-sim kernel.bin -threads {T4} -cta -ctaid <cta>, followed by\n"
                    "# that CTA's pokes. One CTA of four warps a run, sharing .shared and the\n"
                    "# barriers; with the skeleton, the four warps' records are oracle.jsonl and\n"
                    "# oracle.<w>.jsonl. Results are checked exactly"
                    + (", or to a relative 1e-5 for its transcendentals" if any(t for _, _, t in ctas) else "")
                    + " (export-kernels.py).\n")
            f.write(f"threads {T4}\nwarps {T4 // 32}\nctas {len(ctas)}\n" + frame_line())
            for cta, (L, _, _) in enumerate(ctas):
                f.write(f"cta {cta}\n")
                f.writelines(f"-poke {a:#x}={v}\n" for a, v in L.pokes)
        with open(f"{d}/ops.txt", "w") as f:
            f.write(f"# {name}: opcodes issued over the launch's {len(ctas)} CTAs of four warps, "
                    f"by ccv-sim's names; {issued} issue groups\n")
            f.writelines(f"{n:<18} {c}\n" for n, c in sorted(ops.items()))
        if wrong:
            bad = 1
            print(f"  FAIL  {name}: {len(wrong)} wrong; {wrong[0]}")
        else:
            print(f"  PASS  {name}: {len(ctas)} CTA(s) of {T4} threads, four warps, match the "
                  f"reference; {len(ops)} opcodes, {issued} issue groups; without its input "
                  "data each fails")
    return bad


# --- AR-24's L1 capacity traces (AR's rev 229) -------------------------------
# gemv, sgemm and transpose at sizes whose working sets span about 64 KiB to
# 1 MiB, as one-warp CTAs meant to run four resident on a core, so they
# compete for L1. The inputs are megabytes, so they ship as files of
# little-endian words beside launch.txt, loaded with ccv-sim -load (whose
# oracle init record lists them as pokes), and each CTA's result is read back
# with -dump. Inputs are small multiples of 1/8 and every sum is exact in
# fp32, so results are checked bit for bit. The control runs each CTA without
# its loaded inputs. The arrays sit in windows 0x20, 0x60 and 0xA0 (2, 6 and
# 10 MiB), clear of the launch block and of .local's windows from 256 up.
import array

WA, WB, WC = 0x20, 0x60, 0xA0


def fbits(xs):
    return array.array("f", xs)


def l1_gemv(K):
    T, NCTA = 32, 8
    rows = T * NCTA
    W = [q8(i, 15, 3) for i in range(rows * K)]
    x = [q8(i, 9, 1) for i in range(K)]
    y = [sum(W[r * K + k] * x[k] for k in range(K)) for r in range(rows)]
    ctas = []
    for c in range(NCTA):
        L = Launch(T)
        L.ptr(32, WC); L.ptr(40, WA); L.ptr(48, WB); L.word(56, K)
        ctas.append((L, (WC << 16) + 4 * c * T, y[c * T:(c + 1) * T], 1))
    return T, {"W.bin": (WA, fbits(W)), "x.bin": (WB, fbits(x))}, ctas, \
        f"gemv.cu, K {K}: W is {rows} x {K} floats ({rows * K * 4 // 1024} KiB)"


def l1_sgemm(N, NCTA=16):
    T, BX, BY, TM, TN = 32, 8, 4, 2, 2
    bpr = N // (BX * TN)
    A = [q8(i, 11, 2) for i in range(N * N)]
    B = [q8(i, 13, 5) for i in range(N * N)]
    ctas = []
    for cta in range(NCTA):          # row band 0: every CTA reads the same rows of A
        brow, bcol = cta // bpr, cta % bpr
        rows = range(brow * BY * TM, (brow + 1) * BY * TM)
        cols = range(bcol * BX * TN, (bcol + 1) * BX * TN)
        want = []
        for r in rows:
            for c in range(N):
                want.append(sum(A[r * N + k] * B[k * N + c] for k in range(N))
                            if c in cols else None)
        L = Launch(T)
        L.ptr(32, WC); L.ptr(40, WA); L.ptr(48, WB); L.word(56, N); L.word(60, bpr)
        ctas.append((L, (WC << 16) + 4 * rows[0] * N, want, 1))
    return T, {"A.bin": (WA, fbits(A)), "B.bin": (WB, fbits(B))}, ctas, \
        f"sgemm.cu, N {N}: A and B are {N * N * 4 // 1024} KiB each; CTAs 0-{NCTA - 1} of " \
        f"{(N // (BY * TM)) * bpr}, the first row band, so they share A's rows"


def l1_transpose(n):
    T, TILE = 32, 32
    a = [q8(i, 17, 4) for i in range(n * n)]
    tiles = n // TILE
    ctas = []
    for cta in range(tiles * tiles):
        bx, by = cta % tiles, cta // tiles
        want = []
        for r in range(TILE):
            for c in range(n):
                want.append(a[(by * TILE + (c - by * TILE)) * n + bx * TILE + r]
                            if by * TILE <= c < (by + 1) * TILE else None)
        L = Launch(T)
        L.ptr(32, WC); L.ptr(40, WA); L.word(48, n)
        ctas.append((L, (WC << 16) + 4 * (bx * TILE) * n, want, 1))
    return T, {"in.bin": (WA, fbits(a))}, ctas, \
        f"transpose32.cu -DROWS=1, n {n}: {n * n * 4 // 1024} KiB in and out; every CTA"


# name: (source, flags, argument layout, generator)
KERNELS_L1 = {
    "gemv-k128":      ("test/cuda/gemv.cu", "", "p32,p40,p48,s56", lambda: l1_gemv(128)),
    "gemv-k512":      ("test/cuda/gemv.cu", "", "p32,p40,p48,s56", lambda: l1_gemv(512)),
    "gemv-k2048":     ("test/cuda/gemv.cu", "", "p32,p40,p48,s56", lambda: l1_gemv(2048)),
    "sgemm-n256":     ("test/cuda/sgemm.cu", "", "p32,p40,p48,s56,s60", lambda: l1_sgemm(256)),
    "sgemm-n512":     ("test/cuda/sgemm.cu", "", "p32,p40,p48,s56,s60", lambda: l1_sgemm(512)),
    "transpose-n128": ("test/cuda/transpose32.cu", "-DROWS=1", "p32,p40,s48", lambda: l1_transpose(128)),
    "transpose-n256": ("test/cuda/transpose32.cu", "-DROWS=1", "p32,p40,s48", lambda: l1_transpose(256)),
    "transpose-n512": ("test/cuda/transpose32.cu", "-DROWS=1", "p32,p40,s48", lambda: l1_transpose(512)),
}


def export_l1(out, tmp):
    bad = 0
    for name, (src_path, flags, layout, gen) in KERNELS_L1.items():
        dis, image = build128(name, tmp, (src_path, flags, layout, None))
        T, files, ctas, what = gen()
        d = os.path.join(out, name)
        os.makedirs(d, exist_ok=True)
        open(f"{d}/kernel.s", "w").write(
            f"# {name}: {src_path}{' ' + flags if flags else ''}, compiled; ccv-as source,\n"
            "# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's\n"
            "# -code-base; entry at offset 0.\n" + dis)
        open(f"{d}/kernel.bin", "wb").write(image)
        loads = []
        for fname, (win, data) in files.items():
            with open(f"{d}/{fname}", "wb") as f:
                data.tofile(f)
            loads += ["-load", f"{win << 16:#x}={d}/{fname}"]
        ops, issued, wrong = collections.Counter(), 0, []
        for cta, (L, at, want, _) in enumerate(ctas):
            def go(with_loads, oracle):
                args = [SIM, f"{d}/kernel.bin", "-threads", str(T), "-ctaid", str(cta),
                        "-context", str(cta % 4), "-max-steps", "200000000",
                        "-dump", f"{at:#x},{4 * len(want)},{tmp}/dump.bin"]
                if oracle:
                    args += ["-oracle", oracle]
                if with_loads:
                    args += loads
                for a, v in L.pokes:
                    args += ["-poke", f"{a:#x}={v}"]
                r = subprocess.run(args, capture_output=True, text=True)
                if r.returncode:
                    return None
                got = array.array("f")
                with open(f"{tmp}/dump.bin", "rb") as f:
                    got.fromfile(f, len(want))
                return got
            got = go(True, f"{tmp}/l1.jsonl")
            if got is None:
                wrong.append(f"CTA {cta} did not run"); continue
            for line in open(f"{tmp}/l1.jsonl"):
                if line.startswith('{"seq"'):
                    issued += 1
                    ops[json.loads(line)["op"]] += 1
            want32 = fbits([0.0 if v is None else v for v in want])
            bad_at = next((i for i, v in enumerate(want) if v is not None and got[i] != want32[i]), None)
            if bad_at is not None:
                wrong.append(f"CTA {cta} [{at + 4 * bad_at:#x}] = {got[bad_at]}, want {want[bad_at]}")
            got0 = go(False, None)
            if got0 is not None and all(v is None or got0[i] == want32[i] for i, v in enumerate(want)):
                wrong.append(f"control: CTA {cta} without its loaded inputs still matched")
        with open(f"{d}/launch.txt", "w") as f:
            f.write(f"# {name}: {what}.\n"
                    f"# One-warp CTAs, meant to run four resident on a core (CTA c on hardware\n"
                    f"# context c mod 4), so they compete for L1 (AR's rev 229). Each CTA alone is\n"
                    f"# ccv-sim kernel.bin -threads {T} -ctaid <cta> -context <cta mod 4>, the\n"
                    "# 'load' lines as -load=<addr>=<file> (files of little-endian words, in this\n"
                    "# directory), then that CTA's pokes. Results are checked bit for bit\n"
                    "# (export-kernels.py), and without the loaded inputs each CTA fails.\n")
            f.write(f"threads {T}\nresident 4\nctas {len(ctas)}\n" + frame_line())
            for fname, (win, data) in files.items():
                f.write(f"load {win << 16:#x} {fname} {len(data) * 4}\n")
            for cta, (L, _, _, _) in enumerate(ctas):
                f.write(f"cta {cta}\n")
                f.writelines(f"-poke {a:#x}={v}\n" for a, v in L.pokes)
        with open(f"{d}/ops.txt", "w") as f:
            f.write(f"# {name}: opcodes issued over the launch's {len(ctas)} CTAs, "
                    f"by ccv-sim's names; {issued} issue groups\n")
            f.writelines(f"{n:<18} {c}\n" for n, c in sorted(ops.items()))
        if wrong:
            bad = 1
            print(f"  FAIL  {name}: {len(wrong)} wrong; {wrong[0]}")
        else:
            print(f"  PASS  {name}: {len(ctas)} one-warp CTAs exact; {issued} issue groups; "
                  "without the loaded inputs each fails")
    return bad


def main():
    out = sys.argv[1]
    bad = 0
    with tempfile.TemporaryDirectory() as tmp:
        bad |= export_coremark(out, tmp)
        bad |= export_coremark(out, tmp, per_lane=True)
        bad |= export_coremark(out, tmp, priv=True)
        bad |= export_coremark_fault(out, tmp)
        bad |= export128(out, tmp)
        bad |= export_l1(out, tmp)
        for name, fn in KERNELS.items():
            src, image = build(name, tmp)
            threads, ctas = fn()
            d = os.path.join(out, name)
            os.makedirs(d, exist_ok=True)
            hdr = (f"# {name}: test/cuda/fusion/{SOURCE.get(name, name)}.cu, compiled; ccv-as source, "
                   "reassembled byte for byte\n# by tools/ccv-dis.py --check. "
                   "Load at ccv-sim's -code-base; entry at offset 0.\n")
            open(f"{d}/kernel.s", "w").write(hdr + src)
            open(f"{d}/kernel.bin", "wb").write(image)
            ops = collections.Counter()
            wrong, issued = [], 0
            for cta, (L, want) in enumerate(ctas):
                got, text = run(f"{d}/kernel.bin", cta, L, f"{tmp}/o.jsonl")
                if got is None:
                    wrong.append(f"CTA {cta} did not run: {text}"); continue
                for line in open(f"{tmp}/o.jsonl"):
                    rec = json.loads(line)
                    if "op" in rec:
                        ops[rec["op"]] += 1
                        issued += 1
                for a, v in want.items():
                    g = u2f(got.get(a, 0))
                    if not (abs(g - v) <= 1e-5 * max(1.0, abs(v))):
                        wrong.append(f"CTA {cta} [{a:#x}] = {g}, want {v}")
            with open(f"{d}/launch.txt", "w") as f:
                f.write(f"# {name}: ccv-sim kernel.bin -threads {threads} -ctaid <cta> "
                        "followed by that CTA's pokes.\n# Each CTA is its own run; "
                        "results are checked to a relative 1e-5.\n")
                f.write(f"threads {threads}\nctas {len(ctas)}\n" + frame_line())
                for cta, (L, _) in enumerate(ctas):
                    f.write(f"cta {cta}\n")
                    f.writelines(f"-poke {a:#x}={v}\n" for a, v in L.pokes)
            with open(f"{d}/ops.txt", "w") as f:
                f.write(f"# {name}: opcodes issued over the launch's {len(ctas)} CTAs, "
                        f"by ccv-sim's names; {issued} issue groups\n")
                f.writelines(f"{n:<18} {c}\n" for n, c in sorted(ops.items()))
            # The control: CTA 0's launch run as CTA 1 must not match, or the
            # check could not see a wrong token or row.
            L0, want0 = ctas[0]
            got, _ = run(f"{d}/kernel.bin", 1, L0, f"{tmp}/o.jsonl")
            if got is not None and all(abs(u2f(got.get(a, 0)) - v) <= 1e-5 * max(1.0, abs(v))
                                       for a, v in want0.items()):
                wrong.append("control: CTA 0's launch as -ctaid 1 still matched")
            if wrong:
                bad = 1
                print(f"  FAIL  {name}: {len(wrong)} wrong; {wrong[0]}")
            else:
                print(f"  PASS  {name}: {len(ctas)} CTAs of {threads} threads match the "
                      f"reference; {len(ops)} opcodes, {issued} issue groups; "
                      "ccv-as source reassembles to the image; the wrong CTA is caught")
    sys.exit(bad)


if __name__ == "__main__":
    main()
