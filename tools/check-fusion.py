#!/usr/bin/env python3
"""Every kernel in the fused corpus EXECUTES, and computes the right numbers.

F-134 is the reason this exists in the form it does. `sgemm` had never been run:
every check it had passed -- instruction counts, spill counts, the tile sweep,
the register-pressure argument the GPR decision rests on -- was a check on its
text, and the first time it was executed it hung. A corpus assembled to settle
an architectural question has to be one whose kernels are known to work, or the
question is being settled from the compiler's opinion of itself.

WHAT THE REFERENCE IS, AND WHY THE TOLERANCE IS NOT SLACKNESS
-------------------------------------------------------------
Each reference below is written from the kernel's MATHEMATICAL definition in
double precision -- not from the kernel's own decomposition. So it does not
agree bit for bit: `rsqrt` and `ex2` are implementation-defined and approximate
by §4, and the reciprocal-instead-of-divide of F-49 rounds differently. The
comparison is to a relative tolerance that those account for many times over.

That tolerance is safe for what these checks are actually for. An addressing
fault -- a wrong launch slot, a wrong Format D displacement, an element index
where a byte offset belongs, a 32-bit transfer for a 16-bit element -- does not
produce a number that is slightly wrong. It produces another tensor's data, or
zero, or a value from the next row. Nothing in the tolerance hides that, and the
inputs below are chosen asymmetric and non-repeating so that reading the wrong
element cannot agree with the right one by luck.
"""
import math
import os
import re
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LAUNCH = 0x20000
OFF_ARGS = 32
NTID = 32                       # one warp per CTA: what ccv-sim executes


def f2i(x): return struct.unpack("<I", struct.pack("<f", float(x)))[0]
def i2f(x): return struct.unpack("<f", struct.pack("<I", x & 0xFFFFFFFF))[0]
def s2i(x): return struct.unpack("<I", struct.pack("<i", int(x)))[0]
def i2s(x): return struct.unpack("<i", struct.pack("<I", x & 0xFFFFFFFF))[0]


def sigmoid(x): return 1.0 / (1.0 + math.exp(-x))
def silu(x): return x * sigmoid(x)
def gelu(x):
    y = 0.7978845608028654 * (x + 0.044715 * x * x * x)
    return x * sigmoid(2.0 * y)


# --- the corpus -----------------------------------------------------------
#
# Each entry gives the arguments in declaration order. A pointer argument is
# ("p", contents-or-None, length); a scalar is ("f", value) or ("i", value).
# `check` receives the final contents of every pointer argument and returns a
# list of (name, got, want) triples.
#
# Inputs are non-repeating and asymmetric on purpose: a kernel that reads row
# r+1, or element i+1, or the other half of a split tensor, has to produce a
# different answer, and a symmetric input would let it produce the same one.

H = 40                          # hidden size: not a multiple of the warp, so
                                # the strided loop runs a partial last pass
def ramp(n, a, b):
    return [a + b * ((i * 7) % 13 - 6) / 8.0 for i in range(n)]


def spec_swiglu():
    d = 20
    inp = ramp(2 * d, 0.5, 0.9)
    def check(mem):
        out = mem[0]
        return [(f"out[{i}]", out[i], silu(inp[i]) * inp[d + i])
                for i in range(d)]
    return dict(args=[("p", None, d), ("p", inp, 2 * d), ("i", d)], check=check)


def spec_rmsnorm():
    x = ramp(H, 1.0, 1.3)
    w = ramp(H, 0.7, 0.4)
    eps = 1e-5
    def check(mem):
        out = mem[0]
        r = 1.0 / math.sqrt(sum(v * v for v in x) / H + eps)
        return [(f"out[{i}]", out[i], x[i] * r * w[i]) for i in range(H)]
    return dict(args=[("p", None, H), ("p", x, H), ("p", w, H),
                      ("f", eps), ("i", H)], check=check)


def spec_add_rmsnorm():
    x = ramp(H, 1.0, 1.3)
    res = ramp(H, -0.4, 0.9)
    w = ramp(H, 0.7, 0.4)
    eps = 1e-5
    def check(mem):
        inp_out, res_out = mem[0], mem[1]
        s = [x[i] + res[i] for i in range(H)]
        r = 1.0 / math.sqrt(sum(v * v for v in s) / H + eps)
        out = [(f"residual[{i}]", res_out[i], s[i]) for i in range(H)]
        out += [(f"input[{i}]", inp_out[i], s[i] * r * w[i]) for i in range(H)]
        return out
    return dict(args=[("p", x, H), ("p", res, H), ("p", w, H),
                      ("f", eps), ("i", H)], check=check)


def spec_rope():
    nh, nkv, hs, rot = 2, 1, 8, 8
    half, pos = rot // 2, 1
    q = ramp(nh * hs, 0.3, 1.1)
    k = ramp(nkv * hs, -0.2, 0.8)
    cache = ramp((pos + 1) * rot, 0.1, 0.5)
    def rotate(t, heads, hsz):
        o = list(t)
        for h in range(heads):
            b = h * hsz
            for i in range(half):
                c, s = cache[pos * rot + i], cache[pos * rot + half + i]
                xx, yy = t[b + i], t[b + half + i]
                o[b + i] = xx * c - yy * s
                o[b + half + i] = yy * c + xx * s
        return o
    def check(mem):
        wq, wk = rotate(q, nh, hs), rotate(k, nkv, hs)
        r = [(f"query[{i}]", mem[1][i], wq[i]) for i in range(nh * hs)]
        r += [(f"key[{i}]", mem[2][i], wk[i]) for i in range(nkv * hs)]
        return r
    return dict(args=[("pi", [pos], 1), ("p", q, nh * hs), ("p", k, nkv * hs),
                      ("p", cache, len(cache)), ("i", nh), ("i", nkv),
                      ("i", hs), ("i", rot)], check=check)


def spec_adamw():
    n = NTID                     # one grid-stride pass, gridDim 1
    p_ = ramp(n, 0.5, 1.7)
    g = ramp(n, -0.3, 1.1)
    m0 = ramp(n, 0.05, 0.2)
    v0 = [abs(x) + 0.5 for x in ramp(n, 0.4, 0.3)]
    lr, b1, b2, eps, wd, bc1, bc2r = 0.01, 0.9, 0.999, 1e-8, 0.01, 1.05, 0.98
    def check(mem):
        out = []
        for i in range(n):
            m = m0[i] * b1 + g[i] * (1 - b1)
            v = v0[i] * b2 + g[i] * g[i] * (1 - b2)
            pp = p_[i] * (1 - lr * wd)
            want = pp - lr * bc1 * m / (math.sqrt(v) * bc2r + eps)
            out.append((f"param[{i}]", mem[0][i], want))
            out.append((f"exp_avg[{i}]", mem[2][i], m))
            out.append((f"exp_avg_sq[{i}]", mem[3][i], v))
        return out
    return dict(args=[("p", p_, n), ("p", g, n), ("p", m0, n), ("p", v0, n),
                      ("f", lr), ("f", b1), ("f", b2), ("f", eps), ("f", wd),
                      ("f", bc1), ("f", bc2r), ("i", n)],
                check=check, nctaid=1)


def spec_dequant():
    cols = H
    acc = [(i * 37) % 101 - 50 for i in range(cols)]
    sr = ramp(4, 0.02, 0.01)
    sc = ramp(cols, 0.03, 0.02)
    bias = ramp(cols, 0.1, 0.4)
    res = ramp(cols, -0.2, 0.7)
    def check(mem):
        out = mem[0]
        return [(f"out[{i}]",
                 out[i],
                 gelu(acc[i] * sr[0] * sc[i] + bias[i] + res[i]))
                for i in range(cols)]
    return dict(args=[("p", None, cols), ("pi", acc, cols), ("p", sr, 4),
                      ("p", sc, cols), ("p", bias, cols), ("p", res, cols),
                      ("i", cols)], check=check)


def spec_layernorm():
    x = ramp(H, 1.0, 1.3)
    w = ramp(H, 0.7, 0.4)
    b = ramp(H, -0.3, 0.6)
    eps = 1e-5
    def check(mem):
        m = sum(x) / H
        r = 1.0 / math.sqrt(sum(v * v for v in x) / H - m * m + eps)
        out = [("mean", mem[1][0], m), ("rstd", mem[2][0], r)]
        out += [(f"out[{i}]", mem[0][i], (x[i] - m) * r * w[i] + b[i])
                for i in range(H)]
        return out
    return dict(args=[("p", None, H), ("p", None, 4), ("p", None, 4),
                      ("p", x, H), ("p", w, H), ("p", b, H),
                      ("f", eps), ("i", H)], check=check)


def spec_attn_combine():
    splits, hs = 4, 20
    tmp = ramp(splits * hs, 0.2, 1.4)
    sums = [1.5, 0.75, 2.25, 0.5]
    maxl = [0.5, -0.25, 1.25, 0.0]
    def check(mem):
        m = max(maxl)
        tot = sum(sums[s] * math.exp(maxl[s] - m) for s in range(splits))
        out = []
        for i in range(hs):
            a = sum(tmp[s * hs + i] * sums[s] * math.exp(maxl[s] - m)
                    for s in range(splits))
            out.append((f"out[{i}]", mem[0][i], a / tot))
        return out
    return dict(args=[("p", None, hs), ("p", tmp, splits * hs),
                      ("p", sums, splits), ("p", maxl, splits),
                      ("i", splits), ("i", hs)], check=check)


CORPUS = [
    ("swiglu", spec_swiglu), ("rmsnorm", spec_rmsnorm),
    ("add_rmsnorm", spec_add_rmsnorm), ("rope", spec_rope),
    ("adamw", spec_adamw), ("dequant", spec_dequant),
    ("layernorm", spec_layernorm), ("attn_combine", spec_attn_combine),
]


def build(name, tmp):
    """Compile one kernel and return (binary path, argument layout)."""
    s = os.path.join(tmp, name + ".s")
    pre = os.path.join(tmp, name)
    env = dict(os.environ, CCV_CFLAGS="-Itest/bench -Itest/cuda/fusion")
    r = subprocess.run([os.path.join(ROOT, "tools/cuda-to-asm.sh"),
                        f"test/cuda/fusion/{name}.cu", s, pre],
                       capture_output=True, text=True, cwd=ROOT, env=env)
    if r.returncode or not os.path.exists(s):
        return None, (r.stderr.strip() or "compile failed")[:300]
    ll = open(pre + "-lowered.ll").read()
    m = re.search(r'ccv-arg-layout"="([^"]*)"', ll)
    if not m:
        return None, "no ccv-arg-layout attribute -- the ABI moved"
    obj, binf = pre + ".o", pre + ".bin"
    if subprocess.run([os.path.join(ROOT, "build/ccv-llc"), pre + "-lowered.ll",
                       "-o", obj, "-obj"], capture_output=True,
                      cwd=ROOT).returncode:
        return None, "object emission failed"
    if subprocess.run(["llvm-objcopy", "-O", "binary", "--only-section=.text",
                       obj, binf], capture_output=True).returncode:
        return None, "objcopy failed"
    return (binf, m.group(1).split(",")), None


def run(name, spec, binf, layout):
    """Lay out memory per the kernel's own argument layout, run, read back."""
    pokes = ["-poke", f"{hex(LAUNCH)}={NTID}"]
    if "nctaid" in spec:
        pokes += ["-poke", f"{hex(LAUNCH + 12)}={spec['nctaid']}"]
    ptrs, win = [], 3
    for arg, ent in zip(spec["args"], layout):
        off = int(ent[1:])
        if arg[0] in ("p", "pi"):
            kind, data, n = arg
            addr = win << 16
            pokes += ["-poke", f"{hex(LAUNCH + off)}={win}"]
            if data is not None:
                enc = s2i if kind == "pi" else f2i
                for i, v in enumerate(data):
                    pokes += ["-poke", f"{hex(addr + 4 * i)}={enc(v)}"]
            ptrs.append((addr, n, kind))
            win += 1
        else:
            kind, v = arg
            pokes += ["-poke",
                      f"{hex(LAUNCH + off)}={f2i(v) if kind == 'f' else s2i(v)}"]
    peeks = [t for addr, n, _ in ptrs
             for i in range(n) for t in ("-peek", hex(addr + 4 * i))]

    r = subprocess.run([os.path.join(ROOT, "build/ccv-sim"), binf, *pokes,
                        *peeks, "-max-steps", "2000000"],
                       capture_output=True, text=True, cwd=ROOT)
    if "step limit" in r.stderr:
        return None, ("did not terminate -- lanes were still active at the "
                      "step limit, which is what a barrier waiting for a lane "
                      "that already left the loop looks like")
    words = [int(t) for t in re.findall(r"= (\d+)", r.stdout)]
    if len(words) != sum(n for _, n, _ in ptrs):
        return None, (f"simulator returned {len(words)} words, expected "
                      f"{sum(n for _, n, _ in ptrs)}: "
                      + (r.stderr.strip() or r.stdout.strip())[:200])
    mem, at = [], 0
    for _, n, kind in ptrs:
        dec = i2s if kind == "pi" else i2f
        mem.append([dec(w) for w in words[at:at + n]])
        at += n
    return mem, None


def main():
    import tempfile
    tmp = tempfile.mkdtemp()
    bad = 0
    for name, mk in CORPUS:
        spec = mk()
        built, err = build(name, tmp)
        if not built:
            print(f"  FAIL  {name}: {err}")
            bad = 1
            continue
        binf, layout = built
        mem, err = run(name, spec, binf, layout)
        if mem is None:
            print(f"  FAIL  {name}: {err}")
            bad = 1
            continue
        wrong = []
        for label, got, want in spec["check"](mem):
            if abs(got - want) > 1e-4 * max(1.0, abs(want)):
                wrong.append((label, got, want))
        if wrong:
            print(f"  FAIL  {name}: {len(wrong)} value(s) wrong")
            for label, got, want in wrong[:4]:
                print(f"          {label} = {got!r}, want {want!r}")
            bad = 1
    if bad:
        return 1
    print(f"  PASS  fused corpus: {len(CORPUS)} kernels execute and agree with "
          f"a reference written from the mathematics")
    return 0


if __name__ == "__main__":
    sys.exit(main())
