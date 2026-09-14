#!/usr/bin/env python3
"""
Minimal assembler for CCV, driven entirely by the TableGen description.

Operands are positional in TableGen order (outs then ins), which is how the
bit maps name them, so there is no assembly grammar to keep in sync with §3 --
placement comes from the same JSON the encoder does. Tied operands are implicit.

This is deliberately a *second* implementation of the encoding, independent of
the C++ MCCodeEmitter that gen-emitter produces. tools/verify.sh cross-checks
the two, which is the independent-decoder property roadmap F-6 asked for.

A real assembly grammar arrives with -gen-asm-matcher; this exists so the
simulator can be fed text kernels now.

Usage: ccv-as.py <ccv.json> <input.s> <output.bin>
"""
import json, re, sys

class AsmError(Exception):
    pass

def load(jsonpath):
    recs = json.load(open(jsonpath))
    insts = {}
    for k, v in recs.items():
        if not (isinstance(v, dict) and "Inst" in v and isinstance(v.get("Size"), int)):
            continue
        if v["Size"] == 0 or "CCVInst" not in v.get("!superclasses", []):
            continue
        ops, tied = [], set()
        for lst in ("OutOperandList", "InOperandList"):
            for a in v[lst]["args"]:
                ops.append(a[1])
        # A tied operand carries the same value as the one it ties to and is
        # never spelled in source; §3's destructive forms require rd == rs0.
        for c in v.get("Constraints", "") .split(","):
            m = re.match(r'\s*\$(\w+)\s*=\s*\$(\w+)', c)
            if m:
                tied.add(m.group(2) if m.group(2) != m.group(1) else m.group(1))
        insts[k] = {"size": v["Size"], "bits": v["Inst"], "ops": ops, "tied": tied}
    return insts

def encode(inst, values):
    """Place operand values into the instruction's bit map."""
    word = 0
    for i, b in enumerate(inst["bits"]):
        if isinstance(b, int):
            word |= b << i
        elif isinstance(b, dict) and b.get("kind") == "varbit":
            v = values.get(b["var"])
            if v is None:
                raise AsmError(f"no value for field '{b['var']}'")
            word |= ((v >> b["index"]) & 1) << i
        elif b is None:
            raise AsmError(f"unassigned bit {i}")
    return word.to_bytes(inst["size"], "little")

REG = re.compile(r'^[Rr](\d+)$')
PREG = re.compile(r'^[Pp](\d+)$')

def parse_operand(tok, symbols, pc, size):
    tok = tok.strip().rstrip(',')
    m = REG.match(tok)
    if m:
        n = int(m.group(1))
        if n > 15:
            raise AsmError(f"R{n}: register fields are 4 bits, R0-R15 only (§1)")
        return n
    m = PREG.match(tok)
    if m:
        return int(m.group(1))
    if tok in symbols:                       # label -> halfword-relative offset
        return (symbols[tok] - (pc + size)) // 2
    try:
        return int(tok, 0)
    except ValueError:
        raise AsmError(f"cannot parse operand '{tok}'")

def assemble(insts, text):
    # Pass 1: sizes and labels.
    lines, pc, symbols = [], 0, {}
    for lineno, raw in enumerate(text.splitlines(), 1):
        line = raw.split('#')[0].split(';')[0].strip()
        if not line:
            continue
        while True:
            m = re.match(r'^([A-Za-z_]\w*):\s*(.*)$', line)
            if not m:
                break
            symbols[m.group(1)] = pc
            line = m.group(2).strip()
        if not line:
            continue
        mnem = line.split()[0]
        if mnem not in insts:
            raise AsmError(f"line {lineno}: unknown instruction '{mnem}'")
        lines.append((lineno, pc, mnem, line[len(mnem):].strip()))
        pc += insts[mnem]["size"]

    # Pass 2: encode.
    out = bytearray()
    for lineno, pc, mnem, rest in lines:
        inst = insts[mnem]
        named = [o for o in inst["ops"] if o not in inst["tied"]]
        toks = [t for t in re.split(r'[,\s]+', rest) if t]
        if len(toks) != len(named):
            raise AsmError(f"line {lineno}: {mnem} takes {len(named)} operand(s) "
                           f"({', '.join(named)}), got {len(toks)}")
        values = {}
        try:
            for name, tok in zip(named, toks):
                values[name] = parse_operand(tok, symbols, pc, inst["size"])
            for t in inst["tied"]:
                # The tie is on the register, which is already placed.
                values.setdefault(t, values.get("rd", 0))
            out += encode(inst, values)
        except AsmError as e:
            raise AsmError(f"line {lineno}: {mnem}: {e}")
    return bytes(out)

def main():
    insts = load(sys.argv[1])
    try:
        code = assemble(insts, open(sys.argv[2]).read())
    except AsmError as e:
        print(f"ccv-as: {e}", file=sys.stderr)
        return 1
    open(sys.argv[3], "wb").write(code)
    print(f"  assembled {sys.argv[2]}: {len(code)} bytes")
    return 0

if __name__ == "__main__":
    sys.exit(main())
