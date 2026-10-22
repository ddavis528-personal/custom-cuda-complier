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
CTAs share nothing. Results are checked to a relative 1e-5, since ccv-sim's
rsqrt and the fused multiply-adds round differently from Python's doubles.

Usage: export-kernels.py <out-dir>   (exit 1 if any kernel's results are wrong)
"""
import collections, json, math, os, struct, subprocess, sys, tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
JSON = os.path.join(ROOT, "build/generated/CCV.json")
SIM = os.path.join(ROOT, "build/ccv-sim")
LAUNCH = 0x20000


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
def rope():
    T, NH, NKV, HS, RD, NPOS = 32, 2, 1, 64, 64, 8
    half = RD // 2
    positions = [3, 7]
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


KERNELS = {"rope": rope, "layernorm": layernorm}


def build(name, tmp):
    env = dict(os.environ, CCV_CFLAGS="-Itest/bench -Itest/cuda/fusion")
    subprocess.run(["./tools/cuda-to-asm.sh", f"test/cuda/fusion/{name}.cu",
                    f"{tmp}/{name}.ll.s", f"{tmp}/{name}"],
                   cwd=ROOT, env=env, check=True, capture_output=True)
    subprocess.run([f"{ROOT}/build/ccv-llc", f"{tmp}/{name}-lowered.ll",
                    "-o", f"{tmp}/{name}.o", "-obj"], check=True, capture_output=True)
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


def main():
    out = sys.argv[1]
    bad = 0
    with tempfile.TemporaryDirectory() as tmp:
        for name, fn in KERNELS.items():
            src, image = build(name, tmp)
            threads, ctas = fn()
            d = os.path.join(out, name)
            os.makedirs(d, exist_ok=True)
            hdr = (f"# {name}: test/cuda/fusion/{name}.cu, compiled; ccv-as source, "
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
                f.write(f"threads {threads}\nctas {len(ctas)}\n")
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
