#!/usr/bin/env python3
"""
Disassemble a CCV image into source tools/ccv-as.py reassembles byte for byte.

Driven by the same TableGen JSON as the assembler: each instruction is the one
whose fixed bits match, and its operands are printed positionally in TableGen
order (outs then ins), tied operands omitted, which is what ccv-as reads.
Registers print as R/P, branch offsets as labels, and every other field as its
raw value, sign-extended where the operand is signed. Where several records
encode identically (the width twins, F-161), the first whose name ccv-as
re-encodes to the same bytes is taken; `--check` fails if any does not.

It exists so a kernel the compiler built can be run by something that has
ccv-as but not ccv-llc: the core's skeleton (TI-30).

Usage: ccv-dis.py <ccv.json> <image.bin> [--check]
"""
import importlib.util, json, os, re, sys

spec = importlib.util.spec_from_file_location(
    "ccv_as", os.path.join(os.path.dirname(os.path.abspath(__file__)), "ccv-as.py"))
ccv_as = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ccv_as)

LEN = {0b00: 4, 0b01: 2, 0b10: 2, 0b11: 6}


def load(path):
    recs = json.load(open(path))
    insts = ccv_as.load(path)
    for name, inst in insts.items():
        r = recs[name]
        kinds = {}
        for lst in ("OutOperandList", "InOperandList"):
            for a in r[lst]["args"]:
                kinds[a[1]] = a[0]["def"]
        inst["kinds"] = kinds
        inst["codegen_only"] = bool(r.get("isCodeGenOnly"))
    return recs, insts


def fields(inst, word):
    """Each named field's value, from the instruction's bit map."""
    vals, width = {}, {}
    for i, b in enumerate(inst["bits"]):
        if isinstance(b, dict) and b.get("kind") == "varbit":
            v = b["var"]
            vals[v] = vals.get(v, 0) | (((word >> i) & 1) << b["index"])
            width[v] = max(width.get(v, 0), b["index"] + 1)
    return vals, width


def matches(inst, word):
    return all(not isinstance(b, int) or ((word >> i) & 1) == b
               for i, b in enumerate(inst["bits"]))


def disassemble(insts, data, check):
    # Pass 1: decode, choose a name, find branch targets.
    out, pc, targets = [], 0, set()
    while pc < len(data):
        size = LEN[data[pc] & 3]
        raw = data[pc:pc + size]
        word = int.from_bytes(raw, "little")
        cands = [n for n, i in insts.items() if i["size"] == size and matches(i, word)]
        cands.sort(key=lambda n: (insts[n]["codegen_only"], n))
        chosen = None
        for n in cands:
            inst = insts[n]
            vals, width = fields(inst, word)
            named = [o for o in inst["ops"] if o not in inst["tied"]]
            if any(o not in vals for o in named):
                continue
            try:
                if ccv_as.encode(inst, {**vals, **{t: vals.get(t, vals.get("rd", 0))
                                                   for t in inst["tied"]}}) != raw:
                    continue
            except ccv_as.AsmError:
                continue
            chosen = (n, named, vals, width)
            break
        if chosen is None:
            sys.exit(f"ccv-dis: nothing re-encodes {raw.hex()} at {pc:#06x}")
        n, named, vals, width = chosen
        ops = []
        for o in named:
            kind, v, w = insts[n]["kinds"].get(o, ""), vals[o], width[o]
            if kind in ("GPR", "GPR16", "GPR8"):
                ops.append(("reg", f"R{v}"))
            elif kind == "PR":
                ops.append(("reg", f"P{v}"))
            elif kind.startswith("brtarget"):
                off = v - (1 << w) if v >> (w - 1) else v
                t = pc + size + 2 * off
                targets.add(t)
                ops.append(("label", t))
            elif kind.startswith("simm"):
                ops.append(("imm", v - (1 << w) if v >> (w - 1) else v))
            else:
                ops.append(("imm", v))
        out.append((pc, n, ops, raw))
        pc += size

    # Pass 2: print, with a label at every branch target.
    lines = []
    for pc, n, ops, raw in out:
        lab = f"L{pc:04x}:" if pc in targets else ""
        text = ", ".join(f"L{v:04x}" if k == "label" else str(v) for k, v in ops)
        lines.append(f"{lab:<7} {n:<16} {text}".rstrip() + f"   # {pc:#06x}")
    src = "\n".join(lines) + "\n"
    if check:
        again = ccv_as.assemble(insts, src)
        if again != data:
            sys.exit("ccv-dis: the source does not reassemble to the image")
    return src


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    check = "--check" in sys.argv
    _, insts = load(args[0])
    data = open(args[1], "rb").read()
    sys.stdout.write(disassemble(insts, data, check))


if __name__ == "__main__":
    main()
