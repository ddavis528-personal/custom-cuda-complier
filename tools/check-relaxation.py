#!/usr/bin/env python3
"""
Check that branch relaxation actually happened (F-28).

Usage: check-relaxation.py <ccv.json> <short.bin> <relaxed.bin>

The selector always emits the 16-bit `bra.short`; whether it survives depends
on the final layout, so the assembler grows it to Format E's 32-bit `bra` when
the target is out of range. Both halves of that need checking, and neither is
visible in the assembly -- `.s` says `bra.short` either way.

So: one binary whose branches fit must contain C_BRA, and one whose branch does
not fit must contain BRA instead. Asserting only the first would pass with the
relaxation code deleted; asserting only the second would pass with the short
form never selected at all.
"""
import json, sys

LEN = {0b00: 4, 0b01: 2, 0b10: 2, 0b11: 6}

recs = json.load(open(sys.argv[1]))
insts = {k: v for k, v in recs.items()
         if isinstance(v, dict) and "Inst" in v and isinstance(v.get("Size"), int)
         and v["Size"] > 0 and "CCVInst" in v.get("!superclasses", [])}

def decode(word, size):
    """Name every instruction whose fixed bits match, longest match first."""
    best = None
    for name, rec in insts.items():
        if rec["Size"] != size:
            continue
        fixed = 0
        ok = True
        for i, b in enumerate(rec["Inst"]):
            if isinstance(b, int):
                fixed += 1
                if ((word >> i) & 1) != b:
                    ok = False
                    break
        if ok and (best is None or fixed > best[1]):
            best = (name, fixed)
    return best[0] if best else None

def opcodes(path):
    data = open(path, "rb").read()
    out, pos = [], 0
    while pos < len(data):
        size = LEN[data[pos] & 3]
        if pos + size > len(data):
            break
        name = decode(int.from_bytes(data[pos:pos + size], "little"), size)
        if name:
            out.append(name)
        pos += size
    return out

short_bin, relaxed_bin = sys.argv[2], sys.argv[3]
a, b = opcodes(short_bin), opcodes(relaxed_bin)

fail = 0
if "C_BRA" in a:
    print(f"  PASS  short branch stays 16-bit ({a.count('C_BRA')} bra.short)")
else:
    print(f"  FAIL  {short_bin} has no bra.short -- the 16-bit form is not "
          "being selected"); fail = 1

if "BRA" in b and "C_BRA" not in b:
    print("  PASS  out-of-range branch relaxed to 32-bit bra")
elif "C_BRA" in b:
    print(f"  FAIL  {relaxed_bin} still has bra.short -- relaxation did not "
          "grow a branch that cannot reach"); fail = 1
else:
    print(f"  FAIL  {relaxed_bin} has no unconditional branch to check"); fail = 1

sys.exit(fail)
