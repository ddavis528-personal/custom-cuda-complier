#!/usr/bin/env python3
"""Cross-table consistency inside the ISA spec: facts stated twice must agree.

An external review found Format F's immediate given as 18/34 bits at `[31:14]` in
the wide-immediate siblings table and as 17/33 at `[31:15]` in the Format F bit
map. The bit map was right; the table row had been stale since the V1.2 deep dive
realigned F to put `rd` at `[14:11]` for invariant 8, costing exactly the one bit.
It survived prose review through 1.2, 1.3, 1.4, 1.5 and 1.6 without symptoms,
because the TableGen classes were written from the bit maps rather than from the
summary table. Nothing downstream disagreed -- only the document did.

The same review found §2 claiming "nine of sixteen" tags have a 48-bit form where
the table above it lists eleven, and naming an exclusion list that contradicted
both the table and §3's copy of the same sentence.

All three are the same failure: a table was updated, the prose or summary beside it
was not. Prose review has missed this class three times now, so it stops being the
reviewer's job. The rule this encodes:

    a fact stated in two places is a fact that will eventually disagree with
    itself, so the checker owns the agreement rather than the reviewer.

Two checks, both against the current spec only -- frozen revisions are history and
are allowed to be wrong in the way they shipped:

  1. The wide-immediate siblings table vs. the §3 bit maps. Every row's immediate
     must occupy exactly the bits the format's own bit map marks as immediate, the
     48-bit width must be the 32-bit width plus 16, and the high half must be
     `[47:32]`. Compared as SETS of bit positions, so `[31:19]` and
     `[31:30]`,`[26:19]` compare equal when they cover the same bits.

  2. The tag-length table vs. the two prose sentences that summarize it. The count
     of tags with a 48-bit form must match the number spelled out in §2, and both
     §2's and §3's exclusion lists must equal the set of formats the table gives no
     48-bit form.

A siblings row with no wiring into check 1 is a failure, not a skip. The point of
this file is to not be green because it stopped looking.
"""
import re
import sys
import pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
SPEC = (pathlib.Path(sys.argv[1]) if len(sys.argv) > 1
        else ROOT / "docs" / "isa-v1.7-operation-map-and-encoding.md")

# Fields whose bits the siblings table is summarizing. Load/store bit maps call the
# immediate an offset or a displacement; the ALU and compare maps call it an
# immediate. "scale enable", "reserved", "pred qualifier" and register fields are
# none of those and must not be counted.
IMM_WORDS = ("immediate", "offset", "displacement")

NUMBER_WORDS = {
    "one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6, "seven": 7,
    "eight": 8, "nine": 9, "ten": 10, "eleven": 11, "twelve": 12, "thirteen": 13,
    "fourteen": 14, "fifteen": 15, "sixteen": 16,
}

# Siblings-table row label -> how to find its bits in §3.
#   ("col", <table anchor>, <column header>)  for the multi-tier shared tables
#   ("rows", <table anchor>)                  for single-column tables
SIBLING_SOURCES = {
    "B":                 ("col",  "### Formats B / B′ / B″", "B"),
    "B′":           ("col",  "### Formats B / B′ / B″", "B′"),
    "B″":           ("col",  "### Formats B / B′ / B″", "B″"),
    "C′":           ("col",  "### Formats C / C′", "C′ (reg-imm)"),
    "D (base+offset)":   ("rows", "**D — unpredicated, base + offset:**"),
    "D (base+index)":    ("rows", "**D — unpredicated, base + index:**"),
    "D′ (base+offset)": ("rows", "**D′ — predicated, base + offset:**"),
    "D′ (base+index)":  ("rows", "**D′ — predicated, base + index:**"),
    "F":                 ("rows", "**32-bit form:**"),
}


def bits_of(spec_range):
    """`[31:19]` -> {19..31}; `[23]` -> {23}. Accepts a comma-separated list."""
    out = set()
    for m in re.finditer(r"\[(\d+)(?::(\d+))?\]", spec_range):
        hi = int(m.group(1))
        lo = int(m.group(2)) if m.group(2) else hi
        out |= set(range(lo, hi + 1))
    return out


def fmt_bits(bs):
    """Render a bit set as descending ranges, for error messages."""
    if not bs:
        return "{}"
    parts, cur = [], []
    for b in sorted(bs, reverse=True):
        if cur and b == cur[-1] - 1:
            cur.append(b)
        else:
            if cur:
                parts.append(cur)
            cur = [b]
    parts.append(cur)
    return ",".join(f"[{p[0]}:{p[-1]}]" if len(p) > 1 else f"[{p[0]}]" for p in parts)


class MissingAnchor(Exception):
    pass


def table_after(text, anchor):
    """The first markdown table following `anchor`, as a list of cell-lists."""
    i = text.find(anchor)
    if i < 0:
        raise MissingAnchor(anchor)
    rows = []
    started = False
    for line in text[i + len(anchor):].splitlines():
        s = line.strip()
        if s.startswith("|"):
            started = True
            rows.append([c.strip() for c in s.strip("|").split("|")])
        elif started and not s:
            break
    return rows


def immediate_bits(text, source):
    kind, anchor = source[0], source[1]
    rows = table_after(text, anchor)
    header, body = rows[0], [r for r in rows[1:] if not set("".join(r)) <= set("-: ")]
    if kind == "col":
        col = header.index(source[2])
    else:
        col = 2  # | Bits | Width | Field |
    bits = set()
    for r in body:
        if col >= len(r):
            continue
        if any(w in r[col].lower() for w in IMM_WORDS):
            bits |= bits_of(r[0])
    return bits


def check_siblings(text, fail):
    rows = table_after(text, "### Wide-immediate siblings (48-bit)")
    body = [r for r in rows[1:] if not set("".join(r)) <= set("-: ")]
    seen = set()
    for r in body:
        label = r[0].strip()
        seen.add(label)
        w32 = int(re.search(r"\d+", r[1]).group())
        w48 = int(re.search(r"\d+", r[2]).group())
        low, high = bits_of(r[3]), bits_of(r[4])

        if label not in SIBLING_SOURCES:
            print(f"FAIL siblings table: row '{label}' has no bit-map wiring in "
                  f"check-spec-tables.py -- add it to SIBLING_SOURCES")
            fail.append(1)
            continue

        try:
            spec_bits = immediate_bits(text, SIBLING_SOURCES[label])
        except MissingAnchor as e:
            print(f"FAIL siblings table: {label}'s bit map was found by the heading "
                  f"{e.args[0]!r}, which is no longer in the document -- if it was "
                  f"renamed, update SIBLING_SOURCES rather than letting the row go "
                  f"unchecked")
            fail.append(1)
            continue
        if low != spec_bits:
            print(f"FAIL siblings table: {label} low bits {r[3]} = {fmt_bits(low)}, "
                  f"but the §3 bit map marks {fmt_bits(spec_bits)} as immediate")
            fail.append(1)
        if len(low) != w32:
            print(f"FAIL siblings table: {label} claims {w32} 32-bit immediate bits "
                  f"but {r[3]} covers {len(low)}")
            fail.append(1)
        if len(spec_bits) != w32:
            print(f"FAIL siblings table: {label} claims {w32} 32-bit immediate bits "
                  f"but the §3 bit map has {len(spec_bits)}")
            fail.append(1)
        if w48 != w32 + 16:
            print(f"FAIL siblings table: {label} 48-bit immediate is {w48}, "
                  f"expected {w32} + 16 = {w32 + 16}")
            fail.append(1)
        if high != bits_of("[47:32]"):
            print(f"FAIL siblings table: {label} high bits are {r[4]}, "
                  f"expected `[47:32]` -- §2 says no field moves")
            fail.append(1)

    missing = set(SIBLING_SOURCES) - seen
    if missing:
        print(f"FAIL siblings table: wired formats absent from the table: "
              f"{', '.join(sorted(missing))}")
        fail.append(1)
    return len(body)


def check_tag_prose(text, fail):
    # Code -> format name, from the format tag table.
    names = {}
    for r in table_after(text, "### Format tag — bits `[5:2]`, all lengths")[1:]:
        if len(r) >= 2 and re.fullmatch(r"`[01]{4}`", r[0]):
            names[r[0].strip("`")] = r[1].strip()

    # Which tags have a 48-bit form. A row's tag cell may be a range (`0011`-`0101`).
    has48 = {}
    for r in table_after(text, "**Which tags have which lengths:**")[1:]:
        if len(r) < 3 or not re.match(r"`[01]{4}`", r[0]):
            continue
        codes = re.findall(r"`([01]{4})`", r[0])
        span = ([f"{n:04b}" for n in range(int(codes[0], 2), int(codes[-1], 2) + 1)]
                if len(codes) == 2 else codes)
        # An em dash alone (optionally with a parenthetical) means no 48-bit form.
        none = re.fullmatch(r"—(\s*\(.*\))?", r[2].strip())
        for c in span:
            has48[c] = not none

    if len(has48) != 16:
        print(f"FAIL tag-length table: parsed {len(has48)} of 16 tags")
        fail.append(1)
        return 0

    count = sum(1 for v in has48.values() if v)
    excluded = sorted(names[c] for c, v in has48.items() if not v)

    m = re.search(r"^(\w+) of sixteen tags have a 48-bit form", text, re.M)
    if not m:
        print("FAIL: §2's 'N of sixteen tags' sentence is gone -- "
              "if it was reworded, reword this check with it")
        fail.append(1)
    else:
        claimed = NUMBER_WORDS.get(m.group(1).lower())
        if claimed != count:
            print(f"FAIL §2: prose says '{m.group(1)} of sixteen tags have a "
                  f"48-bit form'; the table above it lists {count}")
            fail.append(1)

    # Both prose exclusion lists: "... — A, A″, C, E, G — have no 48-bit rendering"
    lists = re.findall(r"—\s*([A-Z′″,\s]+?)\s*—\s*have no\s*\n?\s*48-bit rendering",
                       text)
    if len(lists) != 2:
        print(f"FAIL: expected 2 prose exclusion lists (§2 and §3), found "
              f"{len(lists)} -- if one was reworded, reword this check with it")
        fail.append(1)
    for i, raw in enumerate(lists):
        got = sorted(x.strip() for x in raw.split(","))
        if got != excluded:
            print(f"FAIL: prose exclusion list #{i + 1} is "
                  f"{', '.join(got)}; the tag table gives no 48-bit form to "
                  f"{', '.join(excluded)}")
            fail.append(1)
    return count


WORDS = {"one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6,
         "seven": 7, "eight": 8, "nine": 9, "ten": 10}


def check_self_version(text, fail):
    """The document must not cite a revision later than its own.

    §3's Format B map read "Until v1.7 this range was described but never
    enumerated" in a document headed Version 1.6 -- a change described in the
    past tense against a revision that does not exist. Harmless in isolation and
    not in aggregate: the revision number is how every other document, every
    proposal and the roadmap refer to what is settled, and a spec that
    mis-numbers its own changes makes the decision trail unreadable.
    """
    m = re.search(r"^\*\*Version (\d+)\.(\d+)\*\*", text, re.M)
    if not m:
        fail.append("no '**Version X.Y**' header -- this check cannot run")
        return None
    own = (int(m.group(1)), int(m.group(2)))
    bad = 0
    for cite in re.finditer(r"\bv?(\d)\.(\d)\b", text):
        ver = (int(cite.group(1)), int(cite.group(2)))
        # Only revisions of THIS document: 1.x, and not a measurement that
        # happens to read like one.
        if ver[0] != own[0] or ver <= own:
            continue
        line = text[:cite.start()].count("\n") + 1
        fail.append(f"line {line}: cites revision {cite.group(0)}, but this "
                    f"document is {own[0]}.{own[1]}")
        bad += 1
    return bad


def check_obligation_count(text, fail):
    """§1a's prose count must equal the number of obligations §1a lists.

    The intro said "§1a states three obligations" for two revisions after O-40
    added a fourth. §1a is the one section that is addressed to the hardware
    side rather than to the compiler, and an undercount there is an obligation
    someone does not know they have.
    """
    body = re.search(r"^## 1a\..*?(?=^## 2\.)", text, re.M | re.S)
    if not body:
        fail.append("§1a not found -- this check cannot run")
        return None
    listed = len(re.findall(r"^### \d+\.", body.group(0), re.M))
    stated = re.search(r"\u00a71a states (\w+) obligations", text)
    if not stated:
        fail.append("no '\u00a71a states N obligations' sentence -- if it was "
                    "reworded, reword this check with it")
        return None
    want = WORDS.get(stated.group(1).lower())
    if want != listed:
        fail.append(f"prose says \u00a71a states {stated.group(1)} obligations; "
                    f"\u00a71a lists {listed}")
    return listed


def check_dp_points(text, fail):
    """§4's packed dot-product table must agree with the machine description.

    O-47. The block carried twelve operations and no point column through 1.6,
    and O-44 added four instructions to it -- so the revision that adopted them
    would have shipped four opcodes whose encoding the document did not state.
    The numbering existed in TableGen, in the encoder, in the disassembler and in
    the simulator, and those agreed with each other the whole time; only the
    specification did not say it.

    Read from the machine description itself rather than from a second copy kept
    here, because a checker holding its own copy of the answer is the thing this
    file exists to stop. The opcode is the first template argument of the format
    class, which is where TableGen takes it from too: the generated JSON bakes it
    into the instruction's bit vector, so reading it back would mean duplicating
    the format's field placement here as well.
    """
    td = ROOT / "llvm/CCV/CCVInstrInfo.td"
    if not td.exists():
        print("  SKIP  \u00a74's dp point table: the machine description is not "
              "present, so it cannot be checked against it")
        return None
    # The table is two columns wide, so a row carries two points. Scan each row
    # for every (point, mnemonic) pair rather than anchoring on the line start,
    # or the right-hand column -- which is where `dp8` lives -- goes unchecked.
    spec = {}
    for line in text.splitlines():
        if not line.startswith("|"):
            continue
        for pt, op in re.findall(r"\|\s*(\d+)\s*\|\s*`([a-z0-9._]+)`", line):
            if 48 <= int(pt) <= 63:
                spec[int(pt)] = op
    if not spec:
        fail.append("\u00a74's dp table has no enumerated points -- if it was "
                    "reformatted, reword this check with it (O-47)")
        return None

    got = {}
    for m in re.finditer(
            r"def\s+(DP[248]_\w+)\s*:\s*Format\w+<\s*(\d+)\s*,.*?\"([a-z0-9._]+)",
            td.read_text(), re.S):
        got[int(m.group(2))] = m.group(3)
    if not got:
        fail.append("no dp instructions found in the machine description -- if "
                    "they were renamed, reword this check with them (O-47)")
        return None

    for pt, mnem in sorted(got.items()):
        if pt not in spec:
            fail.append(f"the machine description puts `{mnem}` at point {pt}, "
                        f"which \u00a74's table does not list")
        elif spec[pt] != mnem:
            fail.append(f"point {pt}: \u00a74 says `{spec[pt]}`, the machine "
                        f"description says `{mnem}`")
    return len(spec)


def main():
    text = SPEC.read_text()
    fail = []
    n = check_siblings(text, fail)
    try:
        c = check_tag_prose(text, fail)
    except MissingAnchor as e:
        print(f"FAIL: the tag table headed {e.args[0]!r} is no longer in the "
              f"document -- if it was renamed, update check-spec-tables.py rather "
              f"than letting the prose go unchecked")
        return 1
    check_self_version(text, fail)
    o = check_obligation_count(text, fail)
    d = check_dp_points(text, fail)
    if fail:
        print(f"  FAIL  {len(fail)} cross-table inconsistenc"
              f"{'y' if len(fail) == 1 else 'ies'} in {SPEC.name}")
        for f in fail:
            print(f"        {f}")
        return 1
    print(f"  PASS  {n} sibling rows agree with their bit maps, "
          f"{c} 48-bit tags agree with §2/§3 prose, "
          f"{o} obligations agree with §1a, no forward version citations"
          + (f", {d} dp points agree with the machine description" if d else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
