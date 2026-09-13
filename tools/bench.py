#!/usr/bin/env python3
"""
Instruction density and instruction count, CCG against what can be measured.

WHAT THIS MEASURES AND WHAT IT DOES NOT
---------------------------------------
Three targets, one source, one frontend:

  CCG      this backend, via clang's CUDA frontend
  AMDGCN   clang's AMD GPU backend (gfx900), a REAL ISA with real encodings
  PTX      nvptx64 -- a VIRTUAL ISA

Only the first two give a defensible density number. PTX is not a machine
encoding: ptxas expands, schedules and re-allocates it, so a PTX instruction
count is a statement about what the frontend thought the task needed, not
about what any hardware executes. It is reported because "instructions to
complete the task" is a fair question at that level and PTX is this project's
compatibility contract -- but it is not evidence about density and is labelled
so.

SASS is the comparison that would matter most and cannot be made here: it
needs ptxas, which needs the CUDA toolkit. Published SASS figures are cited in
docs/benchmarks.md rather than measured, and are marked as citations.

Static counts, not dynamic. Two kernels with the same static size can execute
wildly different amounts; every kernel here has data-independent control flow
apart from the guard, so static count is a reasonable proxy, but it is still a
proxy.
"""
import re, os, subprocess, sys, tempfile, json

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BENCH = os.path.join(ROOT, "test", "bench")
KERNELS = ["vadd", "saxpy", "dot", "reduce", "transpose"]

def run(*a, **kw):
    return subprocess.run(a, capture_output=True, text=True, **kw)

def clang_cuda_include():
    rd = run("clang", "-print-resource-dir").stdout.strip()
    for root, _, files in os.walk(os.path.join(rd, "include")):
        if "__clang_cuda_builtin_vars.h" in files:
            return root
    sys.exit("cannot find __clang_cuda_builtin_vars.h")

CUDA_INC = clang_cuda_include()

def ccg(src, tmp, aligned):
    """CCG: instructions and BYTES, the latter straight from the .text section
    rather than from counting mnemonics -- it is the number that matters and
    the object file is the authority on it."""
    ll, low, obj, binf = (os.path.join(tmp, f"c.{x}") for x in
                          ("ll", "low.ll", "o", "bin"))
    flags = ["-DCCG_ALIGNED"] if aligned else []
    r = run("clang", "-x", "cuda", "-nocudainc", "-nocudalib",
            "--cuda-device-only", "--cuda-gpu-arch=sm_70", "-I", CUDA_INC,
            "-I", BENCH, "-O2", *flags, "-emit-llvm", "-S", src, "-o", ll)
    if r.returncode:
        return None
    r = run("opt", f"-load-pass-plugin={ROOT}/build/CCGLowerKernelArgs.so",
            "-passes=function(infer-address-spaces),ccg-lower-kernel-args,"
            "function(instcombine,gvn,simplifycfg)", "-S", ll, "-o", low)
    if r.returncode:
        return None
    r = run(f"{ROOT}/build/ccg-llc", low, "-o", obj, "-obj")
    if r.returncode:
        return {"error": (r.stderr.strip().splitlines() or ["failed"])[0]}
    if run("llvm-objcopy", "-O", "binary", "--only-section=.text",
           obj, binf).returncode:
        return None
    n = count_ccg(binf)
    return {"instrs": n, "bytes": os.path.getsize(binf)}

def count_ccg(path):
    """Walk the stream by §2's length rule: bits [1:0] of the first halfword,
    before any format decode. Counting mnemonics in the .s would miss branch
    relaxation, which changes sizes after the .s is written."""
    data = open(path, "rb").read()
    LEN = {0b00: 4, 0b01: 2, 0b10: 2, 0b11: 6}
    pos = n = 0
    while pos < len(data):
        pos += LEN[data[pos] & 3]
        n += 1
    return n

def amdgcn(src, tmp):
    """AMDGCN via clang's own backend. Instructions and bytes both come from
    the ASSEMBLED object, not from counting lines of .s: GCN mixes 4- and
    8-byte encodings, so a line count says nothing about size, and the .s
    carries kernel-descriptor directives that are not instructions."""
    asmf, obj, binf = (os.path.join(tmp, f"a.{x}") for x in ("s", "o", "bin"))
    r = run("clang", "-x", "hip", "--offload-device-only",
            "--offload-arch=gfx900", "-nogpuinc", "-nogpulib", "-I", BENCH,
            "-O2", "-S", src, "-o", asmf)
    if r.returncode:
        return {"error": (r.stderr.strip().splitlines() or ["failed"])[0][:60]}
    r = run("llvm-mc", "-triple=amdgcn-amd-amdhsa", "-mcpu=gfx900",
            "-filetype=obj", asmf, "-o", obj)
    if r.returncode:
        return {"error": "llvm-mc: " + (r.stderr.strip().splitlines() or [""])[0][:50]}
    if run("llvm-objcopy", "-O", "binary", "--only-section=.text",
           obj, binf).returncode:
        return {"error": "objcopy failed"}
    dis = run("llvm-objdump", "-d", "--mcpu=gfx900", obj).stdout
    # Every disassembled instruction carries its encoding in a trailing
    # comment; directives and labels do not.
    n = len(re.findall(r"//\s+[0-9A-F]{12}:", dis))
    return {"instrs": n, "bytes": os.path.getsize(binf)}

def ptx(src, tmp):
    asm = run("clang", "-x", "cuda", "-nocudainc", "-nocudalib",
              "--cuda-device-only", "--cuda-gpu-arch=sm_70", "-I", CUDA_INC,
              "-I", BENCH, "-O2", "-S", src, "-o", "-")
    if asm.returncode:
        return {"error": "failed"}
    n = 0
    for l in asm.stdout.splitlines():
        t = l.strip()
        if not t or t.startswith(("//", ".", "{", "}", "$", "@%")):
            continue
        # A PTX instruction ends in ';'. Labels and directives do not.
        if t.endswith(";"):
            n += 1
    return {"instrs": n}

# Argument VALUES in declaration order, one list per kernel. The byte offsets
# are not written here: the compiler emits them as a `ccg-arg-layout` attribute
# and this reads them, because a pointer takes 8 bytes and a scalar packs into
# 4, so the offsets depend on the signature. Hardcoding them produced a
# benchmark that measured saxpy's guard failing for every lane -- its `n` is at
# +52, not the +56 a uniform-slot assumption gives.
ARGS = {
    "vadd":      [3, 4, 5, 32],          # c, a, b windows; n
    "saxpy":     [3, 4, 0x40000000, 32], # y, x windows; a = 2.0f; n
    "dot":       [3, 4, 5, 32],
    "reduce":    [3, 4, 32],
    "transpose": [3, 4, 16],
}

def dynamic(src, tmp, kernel):
    """Lane-instructions per thread, from the simulator. This is the number the
    static count is a proxy for, and the two diverge exactly where an
    instruction hides a loop -- which is the whole reason to measure it."""
    if kernel not in ARGS:
        return None
    ll, low, obj, binf = (os.path.join(tmp, f"d.{x}") for x in
                          ("ll", "low.ll", "o", "bin"))
    if run("clang", "-x", "cuda", "-nocudainc", "-nocudalib",
           "--cuda-device-only", "--cuda-gpu-arch=sm_70", "-I", CUDA_INC,
           "-I", BENCH, "-O2", "-DCCG_ALIGNED", "-emit-llvm", "-S", src,
           "-o", ll).returncode:
        return None
    if run("opt", f"-load-pass-plugin={ROOT}/build/CCGLowerKernelArgs.so",
           "-passes=function(infer-address-spaces),ccg-lower-kernel-args,"
           "function(instcombine,gvn,simplifycfg)", "-S", ll, "-o",
           low).returncode:
        return None
    m = re.search(r'ccg-arg-layout"="([^"]*)"', open(low).read())
    if not m:
        return {"error": "no ccg-arg-layout attribute"}
    slots = [e for e in m.group(1).split(",") if e]
    vals = ARGS[kernel]
    if len(slots) != len(vals):
        return {"error": f"{len(slots)} args in layout, {len(vals)} values given"}

    if run(f"{ROOT}/build/ccg-llc", low, "-o", obj, "-obj").returncode:
        return None
    if run("llvm-objcopy", "-O", "binary", "--only-section=.text",
           obj, binf).returncode:
        return None

    LAUNCH = 0x20000
    pokes = ["-poke", f"{hex(LAUNCH)}=32"]             # ntid.x
    for slot, v in zip(slots, vals):
        pokes += ["-poke", f"{hex(LAUNCH + int(slot[1:]))}={v}"]
    r = run(f"{ROOT}/build/ccg-sim", binf, *pokes, "-counters")
    if r.returncode:
        return {"error": (r.stderr.strip().splitlines() or ["ran off"])[0][:50]}
    pt = re.search(r"per thread\s+([0-9.]+)", r.stdout)
    ef = re.search(r"SIMT efficiency\s+([0-9.]+)", r.stdout)
    if not pt:
        return None
    return {"per_thread": float(pt.group(1)),
            "simt": float(ef.group(1)) if ef else 0.0}

def main():
    rows = []
    with tempfile.TemporaryDirectory() as tmp:
        for k in KERNELS:
            src = os.path.join(BENCH, k + ".cu")
            rows.append({
                "kernel": k,
                "ccg": ccg(src, tmp, aligned=False),
                "ccg_aligned": ccg(src, tmp, aligned=True),
                "amdgcn": amdgcn(src, tmp),
                "ptx": ptx(src, tmp),
                "dyn": dynamic(src, tmp, k),
            })
    if "--json" in sys.argv:
        print(json.dumps(rows, indent=2))
        return 0

    def dcell(d, key):
        if not d or key not in d:
            return "--"
        return f"{d[key]:.0f}%" if key == "simt" else f"{d[key]:.1f}"

    def cell(d, key, w):
        if not d or "error" in d:
            return f"{'--':>{w}}"
        return f"{d.get(key, '--'):>{w}}"

    print()
    print("  Static instruction count and code size, one source per row.")
    print()
    print(f"  {'kernel':<10} {'CCG':>6} {'CCGb':>7} {'b/i':>5} "
          f"{'align':>6} {'alnb':>7} {'GCN':>6} {'GCNb':>7} {'b/i':>5} {'PTX':>6}"
          f" {'dyn/thr':>8} {'SIMT':>6}")
    print("  " + "-" * 92)
    for r in rows:
        c, ca, g, p, d = (r["ccg"], r["ccg_aligned"], r["amdgcn"],
                          r["ptx"], r["dyn"])
        cbi = f"{8*c['bytes']/c['instrs']:.1f}" if c and "instrs" in c else "--"
        gbi = f"{8*g['bytes']/g['instrs']:.1f}" if g and "instrs" in g else "--"
        print(f"  {r['kernel']:<10} {cell(c,'instrs',6)} {cell(c,'bytes',7)} "
              f"{cbi:>5} {cell(ca,'instrs',6)} {cell(ca,'bytes',7)} "
              f"{cell(g,'instrs',6)} {cell(g,'bytes',7)} {gbi:>5} "
              f"{cell(p,'instrs',6)} "
              f"{dcell(d, 'per_thread'):>8} "
              f"{dcell(d, 'simt'):>6}")
    for r in rows:
        for name, d in (("ccg", r["ccg"]), ("amdgcn", r["amdgcn"])):
            if d and "error" in d:
                print(f"  note: {r['kernel']} {name}: {d['error']}")
    print()
    print("  CCG/CCGb  = instructions / bytes, unaligned pointers (the general case)")
    print("  align     = the same kernel with O-23's alignment attribute")
    print("  GCN       = AMD gfx900, a real ISA -- the only like-for-like density row")
    print("  PTX       = nvptx64, a VIRTUAL ISA. Task complexity, NOT density.")
    print("  dyn/thr   = lane-instructions per thread, EXECUTED on the simulator")
    print("  SIMT      = lanes active per issue -- what divergence costs")
    return 0

if __name__ == "__main__":
    sys.exit(main())
