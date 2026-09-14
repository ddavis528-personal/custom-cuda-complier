#!/usr/bin/env python3
"""
Instruction density and instruction count, CCV against what can be measured.

WHAT THIS MEASURES AND WHAT IT DOES NOT
---------------------------------------
Three targets, one source, one frontend:

  CCV      this backend, via clang's CUDA frontend
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

def ccv(src, tmp, aligned):
    """CCV: instructions and BYTES, the latter straight from the .text section
    rather than from counting mnemonics -- it is the number that matters and
    the object file is the authority on it."""
    ll, low, obj, binf = (os.path.join(tmp, f"c.{x}") for x in
                          ("ll", "low.ll", "o", "bin"))
    flags = ["-DCCV_ALIGNED"] if aligned else []
    r = run("clang", "-x", "cuda", "-nocudainc", "-nocudalib",
            "--cuda-device-only", "--cuda-gpu-arch=sm_70", "-I", CUDA_INC,
            "-I", BENCH, "-O2", *flags, "-emit-llvm", "-S", src, "-o", ll)
    if r.returncode:
        return None
    r = run("opt", f"-load-pass-plugin={ROOT}/build/CCVLowerKernelArgs.so",
            "-passes=function(infer-address-spaces),ccv-lower-kernel-args,"
            "function(instcombine,gvn,simplifycfg)", "-S", ll, "-o", low)
    if r.returncode:
        return None
    r = run(f"{ROOT}/build/ccv-llc", low, "-o", obj, "-obj")
    if r.returncode:
        return {"error": (r.stderr.strip().splitlines() or ["failed"])[0]}
    if run("llvm-objcopy", "-O", "binary", "--only-section=.text",
           obj, binf).returncode:
        return None
    n = count_ccv(binf)
    return {"instrs": n, "bytes": os.path.getsize(binf)}

def count_ccv(path):
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

    # A kernel with no backward branch executes each instruction at most once,
    # so its static count IS its dynamic count -- no simulator needed and no
    # modelling involved. With a loop, static says nothing about dynamic and
    # this reports nothing rather than guessing.
    text = open(asmf).read().splitlines()
    label = {}
    for i, l in enumerate(text):
        m = re.match(r"^(\.\S+):", l.strip())
        if m:
            label[m.group(1)] = i
    loops = sum(1 for i, l in enumerate(text)
                for m in [re.search(r"s_c?branch\S*\s+(\.\S+)", l)]
                if m and label.get(m.group(1), 1 << 30) < i)
    return {"instrs": n, "bytes": os.path.getsize(binf), "loops": loops}

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
# are not written here: the compiler emits them as a `ccv-arg-layout` attribute
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
           "-I", BENCH, "-O2", "-DCCV_ALIGNED", "-emit-llvm", "-S", src,
           "-o", ll).returncode:
        return None
    if run("opt", f"-load-pass-plugin={ROOT}/build/CCVLowerKernelArgs.so",
           "-passes=function(infer-address-spaces),ccv-lower-kernel-args,"
           "function(instcombine,gvn,simplifycfg)", "-S", ll, "-o",
           low).returncode:
        return None
    m = re.search(r'ccv-arg-layout"="([^"]*)"', open(low).read())
    if not m:
        return {"error": "no ccv-arg-layout attribute"}
    slots = [e for e in m.group(1).split(",") if e]
    vals = ARGS[kernel]
    if len(slots) != len(vals):
        return {"error": f"{len(slots)} args in layout, {len(vals)} values given"}

    if run(f"{ROOT}/build/ccv-llc", low, "-o", obj, "-obj").returncode:
        return None
    if run("llvm-objcopy", "-O", "binary", "--only-section=.text",
           obj, binf).returncode:
        return None

    LAUNCH = 0x20000
    pokes = ["-poke", f"{hex(LAUNCH)}=32"]             # ntid.x
    for slot, v in zip(slots, vals):
        pokes += ["-poke", f"{hex(LAUNCH + int(slot[1:]))}={v}"]
    r = run(f"{ROOT}/build/ccv-sim", binf, *pokes, "-counters")
    if r.returncode:
        return {"error": (r.stderr.strip().splitlines() or ["ran off"])[0][:50]}
    pt = re.search(r"per thread\s+([0-9.]+)", r.stdout)
    ef = re.search(r"SIMT efficiency\s+([0-9.]+)", r.stdout)
    # O-33 trades instructions for energy: masking ADDS a broadcast and removes
    # 31 lane-activations. A table with only an instruction column therefore
    # shows the cost and hides the win, which is how transpose grew from 78 to
    # 84 instructions here with nothing to explain it.
    la = re.search(r"lane-activations\s+(\d+)", r.stdout)
    li = re.search(r"lane-instructions\s+(\d+)", r.stdout)
    if not pt:
        return None
    return {"per_thread": float(pt.group(1)),
            "simt": float(ef.group(1)) if ef else 0.0,
            "lane_act": int(la.group(1)) if la else 0,
            "lane_instr": int(li.group(1)) if li else 0}

def main():
    rows = []
    with tempfile.TemporaryDirectory() as tmp:
        for k in KERNELS:
            src = os.path.join(BENCH, k + ".cu")
            rows.append({
                "kernel": k,
                "ccv": ccv(src, tmp, aligned=False),
                "ccv_aligned": ccv(src, tmp, aligned=True),
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
    print("  STATIC -- code size. Every column is a measurement.")
    print()
    print(f"  {'kernel':<10} | {'CCV unaligned':^21} | {'CCV aligned':^14} | "
          f"{'AMDGCN gfx900':^21} | {'PTX':^6}")
    print(f"  {'':<10} | {'instr':>6} {'bytes':>6} {'b/i':>6} | "
          f"{'instr':>6} {'bytes':>6} | {'instr':>6} {'bytes':>6} {'b/i':>6} | "
          f"{'instr':>6}")
    print("  " + "-" * 80)
    for r in rows:
        c, ca, g, p = r["ccv"], r["ccv_aligned"], r["amdgcn"], r["ptx"]
        cbi = f"{8*c['bytes']/c['instrs']:.1f}" if c and "instrs" in c else "--"
        gbi = f"{8*g['bytes']/g['instrs']:.1f}" if g and "instrs" in g else "--"
        print(f"  {r['kernel']:<10} | {cell(c,'instrs',6)} {cell(c,'bytes',6)} "
              f"{cbi:>6} | {cell(ca,'instrs',6)} {cell(ca,'bytes',6)} | "
              f"{cell(g,'instrs',6)} {cell(g,'bytes',6)} {gbi:>6} | "
              f"{cell(p,'instrs',6)}")

    print()
    print("  DYNAMIC -- instructions actually issued, per thread of work.")
    print()
    print(f"  {'kernel':<10} {'CCV':>8} {'SIMT':>6}   {'AMDGCN':>8} | "
          f"{'lane-act':>9} {'of issued':>10}   how AMDGCN was obtained")
    print("  " + "-" * 94)
    for r in rows:
        d, g = r["dyn"], r["amdgcn"]
        mine = dcell(d, "per_thread")
        simt = dcell(d, "simt")
        if g and "loops" in g and g["loops"] == 0:
            gd, how = str(g["instrs"]), "exact: no backward branch"
        elif g and "loops" in g:
            gd, how = "--", f"has {g['loops']} loops; not modelled"
        else:
            gd, how = "--", "did not build"
        act = f"{d['lane_act']}" if d and d.get("lane_instr") else "--"
        frac = (f"{100.0 * d['lane_act'] / d['lane_instr']:.0f}%"
                if d and d.get("lane_instr") else "--")
        print(f"  {r['kernel']:<10} {mine:>8} {simt:>6}   {gd:>8} | "
              f"{act:>9} {frac:>10}   {how}")

    for r in rows:
        for name, d in (("ccv", r["ccv"]), ("amdgcn", r["amdgcn"])):
            if d and "error" in d:
                print(f"  note: {r['kernel']} {name}: {d['error']}")
    print()
    print("  CCV dynamic is MEASURED on the simulator: lane-instructions divided by")
    print("  threads, which for a fully-active warp is the issue count. AMDGCN has no")
    print("  simulator here, so its dynamic column is filled in only where the kernel")
    print("  provably has no loop and static and dynamic must therefore agree. The two")
    print("  reduction kernels loop on both sides and are left blank rather than")
    print("  modelled.")
    print()
    print("  SIMT is CCV ONLY and is not comparable as printed: a CCV warp is 32 lanes")
    print("  (§1) and a gfx900 wavefront is 64, so the same 32-thread block that fills")
    print("  a CCV warp half-fills theirs. Comparing occupancy needs the same block")
    print("  size expressed in each machine's own warp width, which these kernels do")
    print("  not hold fixed.")
    print()
    print("  LANE-ACT is the energy number (O-33), and it is the ONLY column that")
    print("  moves in the right direction when lane-0 masking fires: masking adds a")
    print("  broadcast instruction and removes 31 lane-activations, so an instruction")
    print("  count alone reports the cost and hides the win. `of issued` is")
    print("  lane-activations over lane-instructions -- the share of issued lane slots")
    print("  that actually did work. It has no AMDGCN counterpart here: gfx900 gates")
    print("  on an exec mask this project does not model, so there is nothing honest")
    print("  to put in a comparison column.")
    print()
    print("  PTX is a VIRTUAL ISA. Task complexity, NOT density -- ptxas expands,")
    print("  schedules and re-allocates it before anything executes.")
    return 0

if __name__ == "__main__":
    sys.exit(main())
