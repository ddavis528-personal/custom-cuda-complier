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
import json
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


def row_numbers(doc, prefix):
    """The numeric cells of the markdown table row starting `| <prefix> |`."""
    for line in doc.splitlines():
        t = line.strip()
        if t.startswith(prefix) and t.endswith("|"):
            cells = [c.strip().strip("*` ") for c in t.strip("|").split("|")]
            return cells
    return None


def check_markdown_claims(doc, rows):
    """Markdown tables and prose figures that restate generated numbers."""
    fail = 0
    KERNELS = ["vadd", "saxpy", "vadd16", "dot", "reduce", "transpose"]

    # The control table: CCV and GCN static instruction counts, per kernel.
    for label, get in (("| CCV |", lambda k: rows[k]["ccv"]["instrs"]),
                       ("| GCN |", lambda k: rows[k]["arches"]["gfx900"]["instrs"])):
        cells = row_numbers(doc, label)
        if not cells:
            print(f"  FAIL  control table row '{label}' not found")
            fail = 1
            continue
        want = [str(get(k)) for k in KERNELS]
        if cells[1:] != want:
            print(f"  FAIL  control table row '{label.strip('| ')}' is "
                  f"{', '.join(cells[1:])}; the tool says {', '.join(want)}")
            fail = 1

    # The O-33 A/B table, transpose only -- the only kernel the pass masks.
    for label, key in (("| `transpose`, masking off |", "mask_off"),
                       ("| `transpose`, masking on |", "dyn")):
        cells = row_numbers(doc, label)
        d = rows["transpose"][key]
        if not cells:
            print(f"  FAIL  masking table row '{label}' not found")
            fail = 1
            continue
        want = [f"{d['per_thread']:.1f}", str(d["lane_instr"]), str(d["lane_act"]),
                f"{100.0 * d['lane_act'] / d['lane_instr']:.0f}%"]
        if cells[1:] != want:
            print(f"  FAIL  masking row '{label.strip('| ')}' is "
                  f"{', '.join(cells[1:])}; the tool says {', '.join(want)}")
            fail = 1

    # Prose figures that restate the tables. Each is (regex, expected value).
    t = rows["transpose"]
    off, on = t["mask_off"], t["dyn"]
    claims = [
        (r"grew to \*\*(\d+) instructions and (\d+) bytes\*\*",
         (str(t["ccv"]["instrs"]), str(t["ccv"]["bytes"])),
         "transpose static size after O-33"),
        (r"\*\*(\d+) fewer lanes switched — a (\d+)% cut — for (\d+) added "
         r"instructions per thread\.\*\*",
         (str(off["lane_act"] - on["lane_act"]),
          f"{100.0 * (off['lane_act'] - on['lane_act']) / off['lane_act']:.0f}",
          f"{on['per_thread'] - off['per_thread']:.0f}"),
         "what masking costs and buys"),
        (r"^(\d+) instructions issued against GCN5's (\d+)",
         (f"{on['per_thread']:.0f}", str(t["arches"]["gfx900"]["instrs"])),
         "transpose issued vs GCN5"),
    ]
    for pat, want, what in claims:
        m = re.search(pat, doc, re.M)
        if not m:
            print(f"  FAIL  the prose claim about {what} is gone or reworded -- "
                  f"reword this check with it")
            fail = 1
        elif tuple(m.groups()) != want:
            print(f"  FAIL  prose about {what} says {m.groups()}; "
                  f"the tool says {want}")
            fail = 1
    return fail


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

    # The prior-art sweep, generated as of this revision.
    prior = fenced(doc, "kernel                 CCV")
    if len(prior) >= 2:
        fail |= compare("prior-art bits/instr table",
                        section(bench.stdout, "PRIOR ART --"), prior[0])
        fail |= compare("prior-art instruction-count table",
                        section(bench.stdout, "Instruction counts, same sweep"),
                        prior[1])
    else:
        print("  FAIL  the two prior-art tables were not both found")
        fail = 1

    fail |= compare("work-per-element table",
                    section(bench.stdout, "WORK --"),
                    (fenced(doc, "CCV    GCN5") or [""])[0])

    # Markdown tables restating the generated numbers. These are the ones prose
    # review kept missing: the control table's transpose cell was three
    # instructions stale and the masking A/B was stale in every cell. Text
    # comparison cannot be used -- the document renders them as markdown and the
    # tool as fixed-width -- so the VALUES are compared instead.
    js = subprocess.run([sys.executable, str(ROOT / "tools/bench.py"), "--json"],
                        capture_output=True, text=True, cwd=ROOT)
    if js.returncode:
        print("  FAIL  tools/bench.py --json did not run")
        return 1
    rows = {r["kernel"]: r for r in json.loads(js.stdout)}
    fail |= check_markdown_claims(doc, rows)

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
