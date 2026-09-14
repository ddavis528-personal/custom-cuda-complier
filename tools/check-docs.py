#!/usr/bin/env python3
"""Mechanical documentation audit: the parts of "is this still true" a program can do.

This exists because a hand audit found, among other things, an F-number with two
rows contradicting each other, three findings still marked "open, blocks Step 4"
two steps after Step 4 shipped, a document written against a spec version that
had been superseded twice, and a "next is the MC layer" line three steps late.
None of that is detectable by a checker in general -- prose staleness is not a
computable property -- but the structural half of it is:

  1. Every file path a document names exists.
  2. Every F-NN and O-NN reference resolves to a definition.
  3. No finding has two rows in the roadmap's tracking table.
  4. Documents naming a spec version name the current one, unless they are
     explicitly marked historical.

What this cannot check is whether a number in prose is still the number the
machine produces. `check-bench-doc.py`, `check-spec-vs-codegen.py` and
`check-listings.py` cover that for the documents that carry figures; anywhere
else, the rule is that a figure belongs in one of those documents.
"""
import re
import sys
import pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
CURRENT_SPEC = "isa-v1.5-operation-map-and-encoding.md"

DOCS = sorted(
    list(ROOT.glob("docs/*.md"))
    + list(ROOT.glob("docs/proposals/*.md"))
    + [ROOT / "README.md", ROOT / "llvm/CCV/README.md", ROOT / "tools/ccv-sim/README.md"]
)
# Superseded spec revisions are kept verbatim as the decision trail. They are
# supposed to name their own version and their own era's file paths.
HISTORICAL = re.compile(r"isa-v1\.[0-4]-|compiler-findings-v1\.[0-4]\.md")


def rel(p):
    return str(p.relative_to(ROOT))


def main():
    fail = 0
    spec = (ROOT / "docs" / CURRENT_SPEC).read_text()
    roadmap = (ROOT / "docs/roadmap.md").read_text()

    # --- 1. every path a document names exists --------------------------------
    for doc in DOCS:
        if HISTORICAL.search(doc.name):
            continue
        text = doc.read_text()
        for m in re.finditer(r"`((?:tools|llvm|test|docs)/[A-Za-z0-9_./-]+)`", text):
            path = m.group(1).rstrip(".,)")
            # llvm/Target/... is upstream LLVM, not this tree.
            if path.startswith("llvm/Target/"):
                continue
            if not (ROOT / path).exists():
                print(f"  FAIL  {rel(doc)} names `{path}`, which does not exist")
                fail = 1

    # --- 2. F- and O- references resolve --------------------------------------
    # Findings are defined by a row in roadmap Part 3; decisions by a bold entry
    # in the spec's decision log.
    part3 = roadmap[roadmap.index("## Part 3"):]
    findings = set(re.findall(r"^\| (F-\d+[a-z]?)", part3, re.M))
    # Part 1 carries F-1..F-7 as prose sections rather than rows.
    findings |= set(re.findall(r"^### (F-\d+) —", roadmap, re.M))
    decisions = set(re.findall(r"^\*\*(O-\d+)", spec, re.M))

    sources = DOCS + sorted(
        list(ROOT.glob("llvm/CCV/*.cpp")) + list(ROOT.glob("llvm/CCV/*.h"))
        + list(ROOT.glob("llvm/CCV/*.td")) + list(ROOT.glob("tools/*.py"))
        + list(ROOT.glob("tools/*.sh")) + list(ROOT.glob("tools/ccv-sim/*"))
    )
    for src in sources:
        if src.is_dir() or HISTORICAL.search(src.name):
            continue
        try:
            text = src.read_text()
        except (UnicodeDecodeError, OSError):
            continue
        for ref in sorted(set(re.findall(r"\bF-\d+\b", text))):
            if ref not in findings:
                print(f"  FAIL  {rel(src)} cites {ref}, which has no row in roadmap Part 3")
                fail = 1
        for ref in sorted(set(re.findall(r"\bO-\d+\b", text))):
            if ref not in decisions:
                print(f"  FAIL  {rel(src)} cites {ref}, which is not in the {CURRENT_SPEC} decision log")
                fail = 1

    # --- 3. no finding tracked twice ------------------------------------------
    rows = re.findall(r"^\| (F-\d+[a-z]?)", part3, re.M)
    for f in sorted({r for r in rows if rows.count(r) > 1}):
        print(f"  FAIL  {f} has {rows.count(f)} rows in roadmap Part 3 -- "
              f"they will disagree, and one already did")
        fail = 1

    # --- 4. live documents point at the current spec --------------------------
    for doc in DOCS:
        if HISTORICAL.search(doc.name):
            continue
        # A proposal records an argument as it was made, against the spec as it
        # stood. Citing v1.2 there is the point, not a staleness bug -- what
        # matters for a proposal is its Status line, which a program cannot read.
        if doc.parent.name == "proposals":
            continue
        text = doc.read_text()
        if re.search(r"^> \*\*Historical", text, re.M):
            continue
        stale = sorted(set(re.findall(r"isa-v1\.[0-4](?:-operation-map-and-encoding)?", text)))
        # A reference inside a "superseded by" table row is the point of that row.
        stale = [v for v in stale
                 if not re.search(rf"{re.escape(v)}[^\n]*Superseded", text)]
        if stale:
            print(f"  FAIL  {rel(doc)} points at {', '.join(stale)}; current is {CURRENT_SPEC}")
            fail = 1

    if not fail:
        print(f"  PASS  {len(DOCS)} documents: paths resolve, "
              f"{len(findings)} findings and {len(decisions)} decisions all defined, "
              f"no duplicate tracking rows")
    return fail


if __name__ == "__main__":
    sys.exit(main())
