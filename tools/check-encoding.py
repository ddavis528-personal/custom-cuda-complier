#!/usr/bin/env python3
"""
Mechanical check of the CCG encoding against the invariants stated in
docs/isa-v1.3-operation-map-and-encoding.md.

TableGen already rejects a double-assigned bit. This adds the checks it does
not make:

  1. Instruction width matches its declared Size.
  2. No gaps -- every bit of Inst is assigned. Invariant 7 calls reserved bits
     in a long form where a short form exists a bug, so an unassigned bit is
     at minimum something to justify.
  3. The length/class field [1:0] agrees with Size (§2).
  4. Invariant 8: register fields, the predicate qualifier and the predicate
     destination sit at fixed positions across all 32/48-bit formats, and the
     compressed forms keep their own fixed internal geometry.

Usage: llvm-tblgen ... --dump-json | check-encoding.py -
"""
import json, sys
from collections import defaultdict

# §2: length/class field [1:0] -> instruction size in bytes.
LEN_CLASS = {0b00: 4, 0b01: 2, 0b10: 2, 0b11: 6}

# Invariant 8, 32/48-bit formats: canonical field slot -> (hi, lo).
CANON = {
    "rd":  (14, 11),
    "rs0": (18, 15),
    "rs1": (22, 19),
    "rs2": (26, 23),
    "pq":  (29, 27),
    "pd":  (31, 30),
}
# Formats name the same slots differently; map to the canonical slot. Fields
# whose name already is a canonical slot need no entry.
ALIAS = {"rdata": "rd", "rbase": "rs0", "rindex": "rs1"}

# Compressed forms have their own geometry, and J and K do NOT share it:
# Format J needs three 4-bit register fields in the 12 bits left after the
# class code and subop, so its rd sits lower than K's. Invariant 8 states a
# single shared J/K geometry, which is not what §3's bit maps say -- see
# roadmap F-15.
CANON_J = {"rd": (7, 4), "rs0": (11, 8), "rs1": (15, 12)}
CANON_K = {"rd": (11, 8), "rs": (15, 12)}

# Formats invariant 8 does not enumerate. It names A/A'/A", C/C', B/B'/B",
# D/D' and M/M', then claims "no exceptions among the 32/48-bit formats",
# which Format I contradicts. Listed explicitly so the gap is visible rather
# than silently skipped -- see roadmap F-16.
EXEMPT = {"PMOV_IMM": "Format I metadata: pd at [9:8], outside invariant 8's list",
          "CHWIDTH_MULTI": "Format I metadata: register mask, no canonical slots"}

def bit_span(inst, var):
    """Return (hi, lo) of the contiguous span holding var, or None if split."""
    pos = [i for i, b in enumerate(inst)
           if isinstance(b, dict) and b.get("var") == var]
    if not pos:
        return None
    lo, hi = min(pos), max(pos)
    return (hi, lo) if hi - lo + 1 == len(pos) else None

def main(path):
    recs = json.load(open(path) if path != "-" else sys.stdin)
    insts = {k: v for k, v in recs.items()
             if isinstance(v, dict) and "Inst" in v and "Size" in v
             and isinstance(v.get("Size"), int) and v["Size"] > 0}

    errors, warnings, exempted = [], [], []
    for name in sorted(insts):
        r = insts[name]
        inst, size = r["Inst"], r["Size"]

        # 1. width vs Size
        if len(inst) != size * 8:
            errors.append(f"{name}: Inst is {len(inst)} bits, Size says {size*8}")
            continue

        # 2. gaps
        gaps = [i for i, b in enumerate(inst) if b is None]
        if gaps:
            errors.append(f"{name}: unassigned bits {gaps}")

        # 3. length class vs size
        lo2 = inst[0], inst[1]
        if all(isinstance(b, int) for b in lo2):
            code = lo2[0] | (lo2[1] << 1)
            if LEN_CLASS.get(code) != size:
                errors.append(
                    f"{name}: length class {code:02b} implies "
                    f"{LEN_CLASS.get(code)} bytes, Size says {size}")

        # 4. invariant 8
        if name in EXEMPT:
            exempted.append(f"{name}: {EXEMPT[name]}")
            continue
        if size == 2:
            cls = inst[0] | (inst[1] << 1) if all(isinstance(b, int) for b in inst[:2]) else None
            table = CANON_J if cls == 0b01 else CANON_K
        else:
            table = CANON
        for var in {b["var"] for b in inst if isinstance(b, dict)}:
            slot = var if var in table else ALIAS.get(var)
            if slot is None or slot not in table:
                continue
            span = bit_span(inst, var)
            if span is None:
                continue           # deliberately split field (D', bra.pred)
            if span != table[slot]:
                hi, lo = span
                chi, clo = table[slot]
                warnings.append(
                    f"{name}: {var} (slot {slot}) at [{hi}:{lo}], "
                    f"invariant 8 says [{chi}:{clo}]")

    print(f"checked {len(insts)} instructions\n")
    for e in exempted:
        print(f"  EXEMPT       {e}")
    if exempted:
        print()
    for w in warnings:
        print(f"  INVARIANT-8  {w}")
    for e in errors:
        print(f"  ERROR        {e}")
    if not errors and not warnings:
        print("  all checks pass")
    print()
    print(f"{len(errors)} error(s), {len(warnings)} invariant-8 deviation(s)")
    return 1 if errors else 0

if __name__ == "__main__":
    sys.exit(main(sys.argv[1] if len(sys.argv) > 1 else "-"))
