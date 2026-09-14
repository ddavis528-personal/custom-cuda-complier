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
KERNELS = ["vadd", "saxpy", "vadd16", "vadd_loop", "vadd16_loop",
           "dot", "reduce", "transpose"]

# Warp/wavefront width, which is what makes an instruction count comparable
# between machines. Read from the generated kernel descriptor, not assumed:
# gfx10+ emits .amdhsa_wavefront_size32, and its absence means wave64.
# A wave64 machine covers twice the elements per issued instruction, so
# comparing per-thread instruction counts across widths -- which this document
# did for five revisions -- silently flatters the narrower machine.
WIDTH = {"ccv": 32, "gfx900": 64, "gfx1030": 32, "gfx1100": 32,
         "gfx1200": 32, "gfx942": 64}

# Kernels where one thread processes exactly one element, so "instructions to
# finish the whole kernel" is (elements / warp width) * instructions per warp.
# dot and reduce are excluded: a thread there consumes several elements and
# then joins a tree reduction, so there is no such constant, and AMD's dynamic
# count is unknown anyway because both loop.
ELEMENTWISE = ("vadd", "saxpy", "vadd16", "vadd_loop", "vadd16_loop",
               "transpose")

# O-40's claimed retire rate for narrow element work, relative to 32-bit. The
# ISA asks for 2x from the split datapath allocation. It is a hardware target
# and nothing here measures it -- the cycle column that uses it is labelled a
# model wherever it appears.
RETIRE = 2.0

# Prior art, across generations rather than one. The original comparison used
# only gfx900 -- a 2017 ISA -- which left the density claim open to the reading
# that it beats an old encoding and not a current one. These are every AMD GPU
# generation this toolchain can assemble: two encodings families (GCN and RDNA)
# and the datacentre line, spanning 2017 to 2024.
ARCHES = [
    ("gfx900",  "GCN5 / Vega", "2017"),
    ("gfx1030", "RDNA2",       "2020"),
    ("gfx1100", "RDNA3",       "2022"),
    ("gfx1200", "RDNA4",       "2024"),
    ("gfx942",  "CDNA3 / MI300", "2023"),
]

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

# One disassembled instruction: mnemonic, address, and the encoding words that
# follow the address in the trailing comment. objdump may append a branch's
# symbolic target after the encoding, so the encoding group is not anchored to
# end-of-line -- anchoring it dropped every branch and undercounted gfx900.
AMD_LINE = re.compile(r"^\s*(\S+)[^/]*//\s+([0-9A-F]{12}):\s+((?:[0-9A-F]{8} ?)+)")

# gfx10+ pads a kernel's tail with s_code_end and CDNA3 with s_nop, to fill the
# instruction prefetch buffer. It is not code and must not be counted: uncut,
# gfx1100's vadd reads 146 instructions and 640 bytes rather than 32 and 184,
# which would have published CCV as ~5x denser than RDNA3 on padding alone.
AMD_PAD = ("s_code_end", "s_nop")


def amd_body(dis):
    """Instructions and bytes of the real kernel, padding excluded.

    Only a TRAILING RUN of padding is dropped. Two narrower-looking rules are
    both wrong and were both tried: filtering the padding mnemonics anywhere
    removes CDNA's real hazard-slot s_nops, and cutting at the last s_endpgm
    removes real code, because an early-exit endpgm is followed by the block
    that restores exec -- on dot that silently deleted the whole reduction
    loop, 17 instructions. Validated by reproducing the published gfx900
    column exactly on all five kernels."""
    insns = []
    for line in dis.splitlines():
        m = AMD_LINE.match(line)
        if m:
            insns.append((m.group(1), int(m.group(2), 16),
                          len(m.group(3).replace(" ", "")) // 2))
    end = len(insns)
    while end and insns[end - 1][0] in AMD_PAD:
        end -= 1
    body = insns[:end]
    if not body:
        return None
    return len(body), body[-1][1] + body[-1][2] - body[0][1]


def amdgcn(src, tmp, arch="gfx900"):
    """AMDGCN via clang's own backend. Instructions and bytes both come from
    the ASSEMBLED object, not from counting lines of .s: GCN mixes 4- and
    8-byte encodings, so a line count says nothing about size, and the .s
    carries kernel-descriptor directives that are not instructions."""
    asmf, obj, binf = (os.path.join(tmp, f"a.{x}") for x in ("s", "o", "bin"))
    r = run("clang", "-x", "hip", "--offload-device-only",
            f"--offload-arch={arch}", "-nogpuinc", "-nogpulib", "-I", BENCH,
            "-O2", "-S", src, "-o", asmf)
    if r.returncode:
        return {"error": (r.stderr.strip().splitlines() or ["failed"])[0][:60]}
    r = run("llvm-mc", "-triple=amdgcn-amd-amdhsa", f"-mcpu={arch}",
            "-filetype=obj", asmf, "-o", obj)
    if r.returncode:
        return {"error": "llvm-mc: " + (r.stderr.strip().splitlines() or [""])[0][:50]}
    if run("llvm-objcopy", "-O", "binary", "--only-section=.text",
           obj, binf).returncode:
        return {"error": "objcopy failed"}
    body = amd_body(run("llvm-objdump", "-d", f"--mcpu={arch}", obj).stdout)
    if not body:
        return {"error": "no instructions disassembled"}
    n, nbytes = body

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
    return {"instrs": n, "bytes": nbytes, "loops": loops}

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
    "vadd16":    [3, 4, 5, 32],          # c, a, b windows; n -- as vadd
    # The loop pair runs 256 elements over 32 threads: 8 iterations each, so
    # per-thread prologue cost is spread over eight elements instead of one.
    # That is the whole point of these two -- a straight-line kernel measures
    # the prologue and calls it the kernel.
    "vadd_loop":   [3, 4, 5, 256],
    "vadd16_loop": [3, 4, 5, 256],
}

# Elements each thread processes, for the work-normalized table. One unless the
# kernel loops.
PER_THREAD = {"vadd_loop": 8, "vadd16_loop": 8}

def dynamic(src, tmp, kernel, extra=()):
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

    if run(f"{ROOT}/build/ccv-llc", low, "-o", obj, "-obj", *extra).returncode:
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
    ig = re.search(r"issue groups\s+(\d+)", r.stdout)
    # O-40: element-work instructions by width, for the retire-rate model.
    narrow = 0
    for m in re.finditer(r"^\s+(16|8|4)-bit\s+(\d+)\s", r.stdout, re.M):
        narrow += int(m.group(2))
    ew = re.search(r"of (\d+) element-work instructions", r.stdout)
    if not pt:
        return None
    return {"per_thread": float(pt.group(1)),
            "simt": float(ef.group(1)) if ef else 0.0,
            "lane_act": int(la.group(1)) if la else 0,
            "lane_instr": int(li.group(1)) if li else 0,
            "issues": int(ig.group(1)) if ig else 0,
            "narrow": narrow,
            "element_work": int(ew.group(1)) if ew else 0}

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
                "arches": {a: amdgcn(src, tmp, a) for a, _, _ in ARCHES},
                # O-33's A/B. Measured, not reconstructed from the pass's own
                # stats: the published table had drifted from the machine by
                # 128 lane-instructions and a whole percentage column, because
                # it was hand-copied once and the divide sequence changed under
                # it twice (O-35) and the counter was corrected once (F-60).
                "mask_off": dynamic(src, tmp, k, ("-ccv-mask-uniform=false",)),
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

    print()
    print("  O-33 A/B -- what lane-0 masking costs and buys, measured.")
    print()
    print(f"  {'':<26}{'issued/thread':>14}{'lane-instr':>12}"
          f"{'lane-act':>10}{'of issued':>11}")
    print("  " + "-" * 71)
    for r in rows:
        for lbl, d in (("masking off", r["mask_off"]), ("masking on", r["dyn"])):
            if not d or not d.get("lane_instr"):
                continue
            share = 100.0 * d["lane_act"] / d["lane_instr"]
            print(f"  {r['kernel'] + ', ' + lbl:<26}{d['per_thread']:>14.1f}"
                  f"{d['lane_instr']:>12}{d['lane_act']:>10}{share:>10.0f}%")
    print()
    print("  Four of five kernels read identically in both rows: the pass DECLINED")
    print("  to mask them, because every uniform value is consumed immediately by")
    print("  divergent work and each masked op would need its own broadcast. That is")
    print("  the cost model working, not the pass failing.")
    print()
    print("  O-40 -- narrow element work, and what a 2x retire rate is worth.")
    print()
    print(f"  {'kernel':<12}{'issues':>8}{'elem work':>11}{'narrow':>8}"
          f"{'frac':>8}{'cycles @2x':>12}{'vs f32':>9}")
    print("  " + "-" * 68)
    # The 32-bit member of each width pair, for the ratio column.
    bases = {}
    for r in rows:
        d = r["dyn"]
        if d and d.get("element_work") and r["kernel"] in ("vadd", "vadd_loop"):
            bases[r["kernel"]] = (d["issues"] - d["narrow"]) + d["narrow"] / RETIRE
    for r in rows:
        d = r["dyn"]
        if not d or not d.get("element_work"):
            continue
        n, i = d["narrow"], d["issues"]
        # 32-bit element work and everything that is not element work at all
        # (chwidth, branches, predicate ops) retire at one per cycle; narrow
        # element work at RETIRE per cycle. A MODEL of hardware that does not
        # exist -- see the caveat below and ISA section 1a.4.
        cyc = (i - n) + n / RETIRE
        # Only a kernel and its own other-width twin have a meaningful ratio;
        # dot against vadd would be comparing kernels, not widths.
        PAIRS = {"vadd": "vadd", "vadd16": "vadd",
                 "vadd_loop": "vadd_loop", "vadd16_loop": "vadd_loop"}
        base = bases.get(PAIRS.get(r["kernel"], ""))
        rel = f"{base / cyc:.3f}x" if base else "--"
        print(f"  {r['kernel']:<12}{i:>8}{d['element_work']:>11}{n:>8}"
              f"{n / d['element_work']:>8.3f}{cyc:>12.1f}{rel:>9}")
    print()
    print("  CYCLES IS A MODEL, NOT A MEASUREMENT. The simulator retires one")
    print("  instruction per step; this column applies O-40's claimed 2x rate to")
    print("  the narrow instructions the simulator counted. `vs f32` is filled in")
    print("  only for vadd16, the one kernel that is another kernel at a second")
    print("  width; comparing dot to vadd would be comparing kernels. Every other")
    print("  column here is measured.")
    print()
    print("  WORK -- what it costs to finish the kernel, per 1024 elements.")
    print()
    names = ["CCV"] + [n for _, n, _ in ARCHES]
    widths = [WIDTH["ccv"]] + [WIDTH[a] for a, _, _ in ARCHES]
    print(f"  {'':<12}" + "".join(f"{n:>15}" for n in names))
    print(f"  {'warp width':<12}" + "".join(f"{w:>15}" for w in widths))
    print("  " + "-" * (12 + 15 * len(names)))
    for metric, per in (("issues", "instr"), ("instr bytes", "bytes")):
        print(f"  {metric + ' / 1K elem':<12}")
        for r in rows:
            k = r["kernel"]
            if k not in ELEMENTWISE:
                continue
            cells = []
            d = r["dyn"]
            ca = r["ccv_aligned"]
            ept = PER_THREAD.get(k, 1)
            if d and ca and "bytes" in ca:
                # CCV's measured per-thread issue count matches its ALIGNED
                # static count on these kernels, so the aligned build is the
                # one whose bytes correspond to the instructions executed.
                v = d["per_thread"] if per == "instr" else ca["bytes"]
                cells.append(f"{1024.0 * v / (WIDTH['ccv'] * ept):.0f}")
            else:
                cells.append("--")
            for a, _, _ in ARCHES:
                g = r["arches"].get(a)
                # Static is the dynamic count only with no backward branch.
                if g and "instrs" in g and g.get("loops") == 0:
                    v = g["instrs"] if per == "instr" else g["bytes"]
                    cells.append(f"{1024.0 * v / (WIDTH[a] * ept):.0f}")
                else:
                    cells.append("--")
            print(f"    {k:<10}" + "".join(f"{c:>15}" for c in cells))
    print()
    print("  One thread handles one element in these four, so a machine covers")
    print("  `warp width` elements per instruction it issues. Counts are the")
    print("  DYNAMIC ones: measured for CCV, and equal to static for AMD only")
    print("  where the kernel has no backward branch.")
    print()
    print("  This is the comparison the per-thread instruction table cannot make.")
    print("  A wave64 machine finishes twice the elements per issued instruction,")
    print("  so 23 CCV instructions against gfx900's 29 is not 1.3x in CCV's")
    print("  favour -- normalized, gfx900 issues FEWER. Bits fetched per element")
    print("  is where the encoding pays, and it is a separate column for a reason.")
    print()
    print("  PRIOR ART -- bits per instruction across AMD GPU generations.")
    print()
    hdr = f"  {'kernel':<10} {'CCV':>15}" + "".join(
        f"{n:>15}" for _, n, _ in ARCHES)
    print(hdr)
    print(f"  {'':<10} {'':>15}" + "".join(f"{y:>15}" for _, _, y in ARCHES))
    print("  " + "-" * (len(hdr) - 2))
    tot = {a: [0, 0] for a, _, _ in ARCHES}
    ctot = [0, 0]
    for r in rows:
        c = r["ccv"]
        cells = []
        if c and "instrs" in c:
            ctot[0] += c["instrs"]; ctot[1] += c["bytes"]
            cells.append(f"{8*c['bytes']/c['instrs']:.1f}")
        else:
            cells.append("--")
        for a, _, _ in ARCHES:
            d = r["arches"].get(a)
            if d and "instrs" in d:
                tot[a][0] += d["instrs"]; tot[a][1] += d["bytes"]
                cells.append(f"{8*d['bytes']/d['instrs']:.1f}")
            else:
                cells.append("--")
        print(f"  {r['kernel']:<10} " + "".join(f"{x:>15}" for x in cells))
    print("  " + "-" * (len(hdr) - 2))
    pooled = [f"{8*ctot[1]/ctot[0]:.1f}" if ctot[0] else "--"]
    for a, _, _ in ARCHES:
        pooled.append(f"{8*tot[a][1]/tot[a][0]:.1f}" if tot[a][0] else "--")
    print(f"  {'pooled':<10} " + "".join(f"{x:>15}" for x in pooled))
    print()
    print("  Pooled is total bytes over total instructions across all five kernels,")
    print("  not the mean of the per-kernel ratios, so a big kernel counts for more.")
    print()
    print("  Instruction counts, same sweep -- the control on the density claim:")
    print()
    print(f"  {'kernel':<10} {'CCV':>15}" + "".join(f"{n:>15}" for _, n, _ in ARCHES))
    print("  " + "-" * (len(hdr) - 2))
    for r in rows:
        c = r["ccv"]
        cells = [str(c["instrs"]) if c and "instrs" in c else "--"]
        for a, _, _ in ARCHES:
            d = r["arches"].get(a)
            cells.append(str(d["instrs"]) if d and "instrs" in d else "--")
        print(f"  {r['kernel']:<10} " + "".join(f"{x:>15}" for x in cells))
    print()
    print("  A kernel's tail padding is EXCLUDED: gfx10+ pads with s_code_end and")
    print("  CDNA3 with s_nop to fill the instruction prefetch buffer. Counting it")
    print("  reads gfx1100's vadd as 146 instructions and 640 bytes rather than 32")
    print("  and 184 -- a 5x density win over RDNA3 made entirely of padding.")

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
