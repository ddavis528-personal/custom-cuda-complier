#!/usr/bin/env python3
"""
Decode one instruction field by field, straight from the TableGen bit maps.

Usage: decode-one.py <ccg.json> <binary> <byte-offset>

Identifies the instruction by matching every fixed bit, then prints each field
with its bit range and value. The field ranges come from the same .td the
encoder and disassembler are generated from, so this is the §3 table applied to
real bytes rather than a second opinion about it.
"""
import json, sys
from collections import defaultdict

LEN = {0b00: 4, 0b01: 2, 0b10: 2, 0b11: 6}

recs = json.load(open(sys.argv[1]))
insts = {k: v for k, v in recs.items()
         if isinstance(v, dict) and "Inst" in v and isinstance(v.get("Size"), int)
         and v["Size"] > 0 and "CCGInst" in v.get("!superclasses", [])}

data = open(sys.argv[2], "rb").read()
off = int(sys.argv[3], 0)
size = LEN[data[off] & 3]
word = int.from_bytes(data[off:off + size], "little")

def fixed_bits_match(bits):
    for i, b in enumerate(bits):
        if isinstance(b, int) and ((word >> i) & 1) != b:
            return False
    return True

cands = [n for n, r in insts.items()
         if r["Size"] == size and fixed_bits_match(r["Inst"])]
if not cands:
    print(f"no instruction matches {word:#0{size*2+2}x}"); sys.exit(1)
name = cands[0]
bits = insts[name]["Inst"]

print(f"  {size*8}-bit instruction at {off:#06x}: "
      f"{data[off:off+size].hex(' ')}  ->  {name}")
print(f"  raw = {word:#0{size*2+2}x} = {word:0{size*8}b}\n")

fields, fixed = defaultdict(dict), {}
for i, b in enumerate(bits):
    if isinstance(b, dict) and b.get("kind") == "varbit":
        fields[b["var"]][b["index"]] = (word >> i) & 1
        fields[b["var"]].setdefault("_pos", []) if False else None
    elif isinstance(b, int):
        fixed[i] = b

pos = defaultdict(list)
for i, b in enumerate(bits):
    if isinstance(b, dict) and b.get("kind") == "varbit":
        pos[b["var"]].append(i)

print(f"  {'bits':<12} {'field':<10} value")
print("  " + "-" * 44)
# Fixed header bits first, in §2 order.
def span(lo, hi):
    return sum(((word >> i) & 1) << (i - lo) for i in range(lo, hi + 1))
if size == 2:
    print(f"  {'[1:0]':<12} {'class':<10} {span(0,1):#04b}  (§2: length from bits [1:0] alone)")
    print(f"  {'[7:2]':<12} {'opcode':<10} {span(2,7)}")
else:
    print(f"  {'[1:0]':<12} {'class':<10} {span(0,1):#04b}  (§2: length from bits [1:0] alone)")
    print(f"  {'[5:2]':<12} {'fmt tag':<10} {span(2,5):#06b}")
for var in sorted(pos, key=lambda v: min(pos[v])):
    ps = sorted(pos[var])
    val = sum(fields[var][i] << i for i in fields[var])
    rng = (f"[{max(ps)}:{min(ps)}]" if ps == list(range(min(ps), max(ps) + 1))
           else "[" + ",".join(str(p) for p in reversed(ps)) + "]")
    print(f"  {rng:<12} {var:<10} {val}")
