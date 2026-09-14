#!/usr/bin/env python3
"""
Mechanical check of the CCV encoding against the invariants stated in
docs/isa-v1.5-operation-map-and-encoding.md.

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
# single shared J/K geometry, which is not what §3's bit maps say; v1.4 corrects
# the invariant's wording to match the bit maps.
CANON_J = {"rd": (7, 4), "rs0": (11, 8), "rs1": (15, 12)}
CANON_K = {"rd": (11, 8), "rs": (15, 12)}

# Formats invariant 8 does not enumerate. As of v1.4 the invariant names its
# exclusions rather than claiming a blanket "no exceptions": Format G conforms,
# Format I deliberately does not. Listed here so the exclusion stays visible in
# the check output rather than being silently skipped.
EXEMPT = {"PMOV_IMM": "Format I metadata: pd at [9:8], excluded by invariant 8 (v1.4)",
          "CHWIDTH_MULTI": "Format I metadata: register mask, no canonical slots"}

def bit_span(inst, var):
    """Return (hi, lo) of the contiguous span holding var, or None if split."""
    pos = [i for i, b in enumerate(inst)
           if isinstance(b, dict) and b.get("var") == var]
    if not pos:
        return None
    lo, hi = min(pos), max(pos)
    return (hi, lo) if hi - lo + 1 == len(pos) else None

# §4 ranges that O-34 made adjacent. Points 32-47 are FP at format codes
# 00/01; 48-63 is dp4/dp8; 64-127 is the conversion product.
FP_RANGE, DP_RANGE, CVT_RANGE = (32, 47), (48, 63), (64, 127)


def format_a_opcode(inst):
    """Format A/A'/A" opcode, or None if it is not one or the opcode is not fixed."""
    if len(inst) != 32:
        return None
    fixed = lambda hi, lo: (
        None if any(not isinstance(inst[b], int) for b in range(lo, hi + 1))
        else sum(inst[b] << (b - lo) for b in range(lo, hi + 1)))
    tag = fixed(5, 2)
    if tag not in (0b0000, 0b0001, 0b0010):
        return None
    low = fixed(10, 6)                      # opcode[4:0], same in all three tiers
    if low is None:
        return None
    if tag == 0b0000:                       # A  -- opcode[9:5] at [31:27]
        high = fixed(31, 27)
    elif tag == 0b0001:                     # A' -- opcode[6:5] at [31:30]
        high = fixed(31, 30)
    else:                                   # A" -- 5-bit opcode, nothing above
        high = 0
    return None if high is None else (high << 5) | low


def check_fp_dp_collision(insts):
    """Nothing but dp4/dp8 may sit in 48-63, and no two instructions may share a point.

    O-34 packed 32-127 solid: FP at 32-47 (format codes 00/01 only), dp4/dp8 at
    48-63, conversions at 64-127. Both halves of that are silently breakable --
    an FP instruction at format code 10 lands on a dp opcode, and every one of
    these is a well-formed Format A that the decoder will happily accept.
    """
    out, seen = [], {}
    strip_p = lambda n: n[:-2] if n.endswith("_P") else n
    for name in sorted(insts):
        opc = format_a_opcode(insts[name]["Inst"])
        if opc is None or not (FP_RANGE[0] <= opc <= CVT_RANGE[1]):
            continue
        # A predicated twin shares its base's point by design (the tier rule).
        if opc in seen and strip_p(seen[opc]) != strip_p(name):
            out.append(f"{name}: opcode {opc} is already {seen[opc]} -- "
                       f"O-34 packs 32-127 with no spare")
        seen.setdefault(opc, name)
        if DP_RANGE[0] <= opc <= DP_RANGE[1] and not strip_p(name).startswith("DP"):
            out.append(
                f"{name}: opcode {opc} is inside {DP_RANGE[0]}-{DP_RANGE[1]}, "
                f"which O-34 gave to dp4/dp8. `32 + 8*format + op` is restricted "
                f"to format codes 00 and 01; 10 and 11 are no longer available.")
    return out


def check_long_ap_not_redundant(insts):
    """48-bit Format A′ must encode points 128-1023, never 0-127 (O-37).

    With opcode[9:7] = 000 the long form would encode a point the 32-bit A′
    already encodes -- two encodings of one instruction, which invariant 7's
    second sentence forbids ("if it fits in 32, it has no 48-bit encoding") and
    which hands the round trip a canonicalization question with no answer.

    The original proposal did not state this; the encoding owner did, and it is
    a constraint on the field rather than a size preference, so it is asserted
    here rather than left to whoever writes the next instruction.
    """
    out = []
    for name in sorted(insts):
        r = insts[name]
        inst = r["Inst"]
        if len(inst) != 48:
            continue
        tag = 0
        for b in range(5, 1, -1):
            if not isinstance(inst[b], int):
                break
            tag = (tag << 1) | inst[b]
        else:
            if tag != 0b0001:
                continue
            hi = 0
            for b in range(34, 31, -1):
                if not isinstance(inst[b], int):
                    hi = None
                    break
                hi = (hi << 1) | inst[b]
            if hi == 0:
                out.append(
                    f"{name}: 48-bit Format A\u2032 with opcode[9:7] = 000 "
                    f"encodes a point 0-127 that the 32-bit A\u2032 already "
                    f"encodes -- two encodings of one instruction (O-37)")
    return out


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

    # 5. O-34's domain restriction on the Format A floating-point rule.
    #
    # `32 + 8*format + op` generates 48-63 for format codes 10 and 11. Those
    # codes are reserved at every `chwidth`, so O-34 put dp4/dp8 there rather
    # than make conversions and packed dot-product compete for 64-127. The
    # price is that the FP rule's domain is now format in {00, 01}: an FP
    # instruction emitted at code 10 or 11 would land on a dp opcode and the
    # decoder would accept it silently, because both are well-formed Format A.
    #
    # The decision document called this "a documentation wart". It is
    # checkable, so it is checked -- nothing else in this repository catches a
    # collision between two instructions that are each individually valid.
    errors += check_fp_dp_collision(insts)
    errors += check_long_ap_not_redundant(insts)

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
