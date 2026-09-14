#!/usr/bin/env python3
"""docs/benchmarks.md carries numbers; this checks they are still the machine's.

The document had four separate stale figures when this was written -- a
transpose row from before O-33, a "below GCN on every kernel" claim that O-33
had made false, an O-32 comparison missing its O-33 row, and a prose "77
instructions issued" contradicting its own table's 72 two screens up. Nothing
caught any of it, because a hand-copied table is only checked by whoever
remembers to re-copy it.

Same shape as check-spec-vs-codegen.py: regenerate, compare, fail on drift.
Prose is not checked -- a checker cannot -- so the rule is that any prose claim
about a number must name the table it comes from, and the tables are what this
holds down.
"""
import re
import subprocess
import sys
import pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
DOC = ROOT / "docs/benchmarks.md"


def fenced(text, first_line_starts):
    """Every ``` block whose first line starts with the given prefix."""
    out = []
    for m in re.finditer(r"```\n(.*?)\n```", text, re.S):
        body = m.group(1)
        if body.lstrip().startswith(first_line_starts):
            out.append(body)
    return out


def section(output, header):
    """The contiguous non-blank block that follows `header` in a tool's output."""
    lines = output.splitlines()
    i = next(n for n, l in enumerate(lines) if header in l)
    body = []
    for l in lines[i + 1:]:
        if not l.strip():
            if body:
                break
            continue
        body.append(l)
    return "\n".join(body)


def norm(text):
    """Trailing whitespace is invisible in a diff and meaningless in a table."""
    return "\n".join(l.rstrip() for l in text.strip().splitlines())


def compare(name, want, got):
    want, got = norm(want), norm(got)
    if want == got:
        print(f"  PASS  {name} matches the tool")
        return 0
    print(f"  FAIL  {name} in docs/benchmarks.md is not what the tool prints")
    wl, gl = want.splitlines(), got.splitlines()
    for i in range(max(len(wl), len(gl))):
        a = wl[i] if i < len(wl) else "<missing>"
        b = gl[i] if i < len(gl) else "<missing>"
        if a != b:
            print(f"        doc : {b}")
            print(f"        tool: {a}")
    return 1


def main():
    if not (ROOT / "build/ccv-llc").exists():
        print("  (build/ccv-llc not built -- skipping benchmark document check)")
        return 0
    doc = DOC.read_text()
    fail = 0

    bench = subprocess.run([sys.executable, str(ROOT / "tools/bench.py")],
                           capture_output=True, text=True, cwd=ROOT)
    if bench.returncode:
        print("  FAIL  tools/bench.py did not run")
        print(bench.stderr[-500:])
        return 1

    for name, header, blocks in (
            ("static table", "STATIC --", fenced(doc, "kernel     |")),
            ("dynamic table", "DYNAMIC --", fenced(doc, "kernel          CCV"))):
        if not blocks:
            print(f"  FAIL  {name} not found in docs/benchmarks.md")
            fail = 1
            continue
        fail |= compare(name, section(bench.stdout, header), blocks[0])

    sweep = subprocess.run([str(ROOT / "tools/sweep-tiles.sh")],
                           capture_output=True, text=True, cwd=ROOT)
    blocks = fenced(doc, "tile  accs")
    if sweep.returncode or not blocks:
        print("  FAIL  GEMM sweep table missing, or tools/sweep-tiles.sh did not run")
        fail = 1
    else:
        # sweep-tiles.sh prints a blank line before the table, so anchor on the
        # line above the header rather than on the header itself.
        want = section(sweep.stdout, "tile  accs")
        fail |= compare("GEMM sweep table",
                        "  tile  accs    instrs     bits b/instr  spills"
                        "    fma sp/fma    K-hit\n" + want, blocks[0])
    return fail


if __name__ == "__main__":
    sys.exit(main())
