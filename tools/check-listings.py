#!/usr/bin/env python3
"""
Verify the arithmetic of the worked assembly listings in the ISA spec.

Three figures in §5.5 were wrong across two revisions -- instruction count,
bits per instruction, and peak live registers -- while the bit total was right.
Prose review does not catch that. This does: it re-derives every stated figure
from the listing itself and fails if the text disagrees.

Usage: check-listings.py docs/isa-v1.5-operation-map-and-encoding.md
"""
import re, sys

def parse(listing):
    """Return (sizes, rows) for lines carrying a ';  <bits>' annotation."""
    sizes, rows = [], []
    for line in listing.splitlines():
        m = re.search(r';\s*(16|32|48)\b', line)
        if not m:
            continue
        sizes.append(int(m.group(1)))
        code = line.split(';')[0]
        dest = None
        if not re.match(r'\s*(st\.|setp|@?\S*\s*bra|exit)', code.strip()):
            d = re.match(r'\s*\S+\s+[Rr](\d+)\s*,', code)
            dest = d.group(1) if d else None
        rows.append((dest, re.findall(r'\b[Rr](\d+)\b', code)))
    return sizes, rows

def peak_live(rows):
    first, last = {}, {}
    for i, (_, regs) in enumerate(rows):
        for r in regs:
            first.setdefault(r, i)
            last[r] = i
    return max((sum(1 for r in first if first[r] <= t <= last[r])
                for t in range(len(rows))), default=0)

def main(path):
    text = open(path).read()
    blocks = re.findall(r'```\n(.*?)```', text, re.S)
    listings = [b for b in blocks if re.search(r';\s*(16|32|48)\b', b)]
    if not listings:
        print("  no annotated listings found"); return 1

    bad = 0
    for n, block in enumerate(listings, 1):
        sizes, rows = parse(block)
        total = sum(sizes)
        count = len(sizes)
        bpi = total / count
        live = peak_live(rows)
        print(f"  listing {n}: {count} instructions, {total} bits, "
              f"{bpi:.1f} b/instr, fixed-32 {count*32}, peak live {live}")

        # Every figure the surrounding prose states must match.
        window = text[text.index(block) + len(block):][:1400]
        for pat, actual, label in (
            (r'(\d+) instructions, (\d+) bits', (count, total), "count/bits"),
            (r'\*\*([\d.]+) bits per instruction\*\*', (round(bpi, 1),), "b/instr"),
            (r'against (?:a fixed-32\s+encoding\'s )?(\d+)', (count * 32,), "fixed-32"),
            (r'[Pp]eak live GPRs is \*\*(\d+) of 16\*\*', (live,), "peak live"),
        ):
            m = re.search(pat, window)
            if not m:
                continue
            stated = tuple(float(g) if '.' in g else int(g) for g in m.groups())
            if stated != actual:
                print(f"    MISMATCH {label}: text says {stated}, listing gives {actual}")
                bad += 1
    print()
    print("  all stated figures match the listings" if not bad
          else f"  {bad} figure(s) disagree with the listings")
    return 1 if bad else 0

if __name__ == "__main__":
    sys.exit(main(sys.argv[1]))
