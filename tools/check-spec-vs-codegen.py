#!/usr/bin/env python3
"""
Compare an ISA worked listing against what ccv-llc actually emits.

check-listings.py verifies that the spec's prose matches the spec's listings.
That is internal consistency: it cannot notice when the listing stops matching
the machine. Both hand-written listings drifted from codegen -- an extra branch
and a pessimistic register count -- and passed straight through it.

This closes that gap by deriving the same figures from real output and diffing
them. A divergence is a build failure, not a review catch.

Usage: check-spec-vs-codegen.py <spec.md> <section> <codegen.s>
"""
import re, sys

def parse_spec(path, section="5.6"):
    """Figures from the §5.6 listing: count, bits, peak live GPRs."""
    text = open(path).read()
    start = text.index(f"### {section}")
    block = text[start:text.index("```", text.index("```", start) + 3)]
    body = block[block.index("```") + 3:]
    return derive([l for l in body.splitlines() if re.search(r';\s*(16|32|48)\b', l)],
                  sizes=[int(re.search(r';\s*(16|32|48)\b', l).group(1))
                         for l in body.splitlines()
                         if re.search(r';\s*(16|32|48)\b', l)])

# Mnemonics with a 16-bit form. The two-operand ALU ops (Format K) only take it
# when the operand shape allows: two operands, or three with rd == rs0. Sizing
# them 16 unconditionally would credit the encoding for compression the selector
# has not actually performed -- see F-29.
ALWAYS16 = {"srd", "por", "pand", "pxor", "pnot", "pmov", "exit", "ret",
            "chwidth", "reconv.hint", "bra.short"}
COMPRESSIBLE = {"add", "sub", "and", "or", "xor", "shl", "shr", "mul",
                "fadd", "fsub", "fmul", "max", "min", "mov"}

def size_of(text):
    """Instruction length in bits, per §2."""
    mnem = re.sub(r'^@\S+\s+', '', text).split()[0]
    if mnem in ("f48", "movi48") or mnem.endswith("48"):
        return 48
    if mnem in ALWAYS16:
        return 16
    if mnem in COMPRESSIBLE:
        ops = [o.strip() for o in text.split(None, 1)[1].split(',')] \
              if len(text.split(None, 1)) > 1 else []
        if len(ops) == 2:
            return 16                       # already two-operand
        if len(ops) == 3 and ops[0] == ops[1]:
            return 16                       # destructive: rd == rs0
    return 32

def parse_asm(path):
    """Figures from emitted assembly. Sizes follow §2: the compressed forms are
    16 bits, everything here else is 32, and Format F's long form is 48."""
    lines, sizes = [], []
    for raw in open(path):
        # Instructions are indented; labels sit at column 0 and directives
        # start with a dot.
        if not raw.strip() or not raw[:1].isspace():
            continue
        text = raw.strip()
        if text.startswith('.'):
            continue
        sizes.append(size_of(text))
        lines.append(text)
    return derive(lines, sizes)

def derive(lines, sizes):
    first, last = {}, {}
    for i, l in enumerate(lines):
        for r in re.findall(r'\b[Rr](\d+)\b', l.split(';')[0]):
            first.setdefault(r, i)
            last[r] = i
    peak = max((sum(1 for r in first if first[r] <= t <= last[r])
                for t in range(len(lines))), default=0)
    return {"instructions": len(sizes), "bits": sum(sizes), "peak_live": peak}

def main(spec, section, asm):
    a, b = parse_spec(spec, section), parse_asm(asm)
    print(f"  {'figure':<14} {'§'+section+' listing':>14} {'ccv-llc':>10}")
    print("  " + "-" * 42)
    bad = 0
    for k in ("instructions", "bits", "peak_live"):
        flag = "" if a[k] == b[k] else "   <-- DIVERGED"
        bad += a[k] != b[k]
        print(f"  {k:<14} {a[k]:>14} {b[k]:>10}{flag}")
    print()
    if bad:
        print(f"  {bad} figure(s) differ: the spec listing no longer describes what")
        print("  the compiler emits. Regenerate the listing or fix codegen.")
        return 1
    print("  spec listing matches codegen")
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv[1], sys.argv[2], sys.argv[3]))
