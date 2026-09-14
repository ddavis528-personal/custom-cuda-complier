#!/usr/bin/env python3
"""Every instruction the walkthrough's prose names must appear in its listings.

docs/walkthrough.md regenerates its listings from the toolchain on every build
and says so: "nothing here is transcribed". The PROSE around them is not
regenerated -- it lives in tools/gen-walkthrough-doc.py -- and it drifted:

  - an annotation table described `f48 r0, 2` where the listing said `movi r0, 2`
  - it described `por p0, 4, 0`, an instruction O-32 removed the need for
    entirely, and which had not appeared in the listing for several revisions
  - it described `@p0 setp.le p0, r2, r1`, a predicated compare, where the
    listing shows the unpredicated Format C" form that replaced it

All three survived because the regeneration check compares the LISTINGS and the
prose sits beside them. It is the same failure the ISA document kept hitting and
check-spec-tables.py now covers there: a fact stated in two places eventually
disagrees with itself.

The rule here is narrow and mechanical: a table's FIRST column is where the
walkthrough names the instruction a row is about, so every backticked fragment
in a first column must appear verbatim in one of the document's own code blocks.
Description columns are prose and may discuss instructions that are gone -- that
is exactly what the O-24 row now does -- so they are not checked.
"""
import re
import sys
import pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
DOC = ROOT / "docs/walkthrough.md"

# Fragments that name a field or a concept rather than something the assembler
# prints. Kept explicit and short: an escape hatch that grows is a checker that
# stops checking.
EXEMPT = set()


def main():
    text = DOC.read_text()
    listings = "\n".join(m.group(1) for m in
                         re.finditer(r"```[a-z]*\n(.*?)\n```", text, re.S))

    missing = []
    for line in text.splitlines():
        t = line.strip()
        if not t.startswith("|") or not t.endswith("|"):
            continue
        first = t.strip("|").split("|")[0].strip()
        if not first.startswith("`"):
            continue
        for frag in re.findall(r"`([^`]+)`", first):
            frag = frag.strip()
            if frag in EXEMPT or not frag:
                continue
            if frag not in listings:
                missing.append(frag)

    if missing:
        print("  FAIL  walkthrough prose names instructions no listing contains:")
        for m in missing:
            print(f"        `{m}`")
        print("        The listings are regenerated from the toolchain; the prose")
        print("        in tools/gen-walkthrough-doc.py is not. Fix the prose.")
        return 1
    print("  PASS  every instruction the walkthrough names appears in its listings")
    return 0


if __name__ == "__main__":
    sys.exit(main())
