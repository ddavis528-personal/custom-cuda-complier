#!/usr/bin/env python3
"""Every instruction the machine description defines must be producible.

F-111. Three separate reviews found the same shape of bug: an encoding exists in
`CCVInstrInfo.td`, the assembler and disassembler round-trip it, the spec
documents it -- and instruction selection never emits it. `bra.short` was found
by a walkthrough review. The Format C' immediate compare was found by reading
§3 beside the generated code. The compressed `C_ANDI`/`C_SHRI` forms were found
by looking for the first two. Three independent instances is a pattern, not
three incidents, and nothing in the gate was looking: `verify.sh` proves the
encoding is uniquely decodable and that the assembler and disassembler agree,
which is a property of the ENCODING. Whether anything can ever generate the
encoding is a property of the COMPILER, and it had no check at all.

This file is that check. For every instruction in the `CCV` namespace it
demands a production path, and the path must be evidence rather than assertion:

  isel          the name appears in a `TARGET_VAL(CCV::x)` slot of the
                generated SelectionDAG matcher table, so a pattern reaches it.
  pass:<file>   the name appears at an EMIT site in that backend source file --
                `get(CCV::x)`, `getMachineNode(CCV::x`, `return CCV::x`,
                `= CCV::x`, a ternary arm, `setOpcode(CCV::x)`. A `case CCV::x:`
                or a `getOpcode() == CCV::x` is a READ and does not count: that
                distinction is the whole point, because the dead
                `PSEUDO_SETP_*` expansions below look exactly like producers
                until you ask who produces their input.
  declared      listed in UNREACHABLE with a category and a reason.

A pass emit site is not automatically a production path. `CCVExpandPseudos.cpp`
lowers `PSEUDO_SETP_LT` to `SETP_LT` and therefore looks like a producer of
`SETP_LT` -- but O-32 gave compares an unpredicated form that ISel now selects
directly, so nothing emits the pseudo any more and both are dead. The first
version of this file passed that whole path as healthy, which is the same
failure it exists to catch. So an emit site that shares a statement with a
`case CCV::TRIGGER:` is recorded as CONDITIONAL on that trigger, and
reachability is a fixpoint: a conditional emit counts only once its trigger is
itself reachable.

That analysis is deliberately narrow -- it pairs a `case` label with an emit in
the same `;`-delimited statement, which is the shape both the pseudo-expansion
switch and `CCVCompress.cpp`'s mapping table use. It is not a general
interprocedural analysis and does not claim to be; an emit inside a braced case
body reads as unconditional. What it buys is that the two mapping tables in this
backend cannot go dead without the gate noticing.

Anything with no production path and no declaration fails. That is the gate: a
new instruction cannot be added without either wiring it up or saying, on the
record, why it is not wired up.

The declarations are not a suppression list. Each carries a category that is
itself checked where checking is possible:

  design    the compiler can never emit it because a deliberate earlier choice
            makes the node it would match unreachable. The reason must name
            that choice. `setp.gt` is the example: `CCVISelDAGToDAG.cpp` selects
            gt/ge as lt/le with the operands swapped, so six of §3's sixteen
            compare points are unreachable BY CONSTRUCTION -- which is a finding
            about the ISA, not about the compiler.
  todo      a feature the backend has not implemented. The reason must cite a
            finding or decision id, and `check-docs.py` already proves those
            resolve.
  dead      reachable in the machine description but unreachable in this
            compiler because something superseded it. Must name what.
  mc        produced below the MI layer -- relaxation, mostly.

Run with --list to print the full classification instead of only failures.
"""
import json
import re
import sys
import glob
import os
import pathlib
import collections

ROOT = pathlib.Path(__file__).resolve().parent.parent

# --------------------------------------------------------------------------
# Declared-unreachable instructions. Categories are defined in the docstring.
# Keep this ordered the way the audit walked it, so a diff reads as a change of
# position rather than a reshuffle.
# --------------------------------------------------------------------------
UNREACHABLE = {
    # -- design: the compiler chose a different route and cannot reach these --
    # CCVISelDAGToDAG.cpp selects SETGT/SETGE as LT/LE with the operands
    # swapped, for every signedness and for float. That makes the entire gt/ge
    # family unreachable, reg-reg and immediate alike: for an immediate the swap
    # is unavailable, but `x > k` is `!(x <= k)` and a predicate qualifier
    # carries a negate bit, so the consumer absorbs it for free. Six of the
    # sixteen compare points §3 allocates cannot be produced by this compiler.
    # Recorded as F-115: it is an ISA observation, not a compiler defect.
    **{n: ("design", "gt/ge selected as lt/le with operands swapped "
                     "(CCVISelDAGToDAG.cpp); F-115")
       for n in """SETP_GE SETP_GE_U SETP_GE_F SETP_GT SETP_GT_U SETP_GT_F
                   SETP_GE_NP SETP_GE_U_NP SETP_GE_F_NP
                   SETP_GT_NP SETP_GT_U_NP SETP_GT_F_NP
                   SETP_GE_I SETP_GE_U_I SETP_GE_F_I
                   SETP_GT_I SETP_GT_U_I SETP_GT_F_I
                   SETP_GE_NPI SETP_GE_U_NPI SETP_GE_F_NPI
                   SETP_GT_NPI SETP_GT_U_NPI SETP_GT_F_NPI""".split()},

    # -- todo: the predicated compare tiers (Formats C and C') --------------
    # Both tiers wait on the same missing primitive. Format C is what lane-0
    # masking of a uniform compare would select, and Format C' is the same with
    # an immediate -- but CCVMaskUniform cannot mask a compare at all: its
    # result is a PREDICATE, and the broadcast that makes masking safe
    # (PSEUDO_BCAST) is a `shfl` on a GPR. A predicate broadcast is a different
    # primitive, and `ballot`/`unballot` are the pair to build it from. F-119.
    #
    # These were "dead" until F-116. Until O-32 added the unpredicated compare
    # they were selected through PSEUDO_SETP_*, whose expansion arms in
    # CCVExpandPseudos survived the change and looked exactly like producers --
    # which is why reachability here is a fixpoint rather than a grep. F-116
    # removed the scaffolding; the encodings stay, because they are §3 and the
    # assembler and round-trip check cover them.
    # -- todo: the predicated IMMEDIATE compare (Format C') ------------------
    # Distinct from the dead reg-reg forms above. Format C' is reachable in
    # principle -- it is what lane-0 masking of a uniform compare would select
    # -- but CCVMaskUniform cannot mask a compare at all: its result is a
    # PREDICATE, and the broadcast that makes masking safe (PSEUDO_BCAST) is a
    # `shfl` on a GPR. Masking a compare needs a predicate broadcast, which is
    # a different primitive. F-119.
    **{n: ("todo", "lane-0 masking cannot gate a compare -- the result is a "
                   "predicate and the broadcast is a GPR shuffle; F-119")
       for n in """SETP_LT_I SETP_LE_I SETP_EQ_I SETP_NE_I
                   SETP_LT_U_I SETP_LE_U_I
                   SETP_LT_F_I SETP_LE_F_I SETP_EQ_F_I SETP_NE_F_I
                   SETP_LT SETP_LE SETP_EQ SETP_NE SETP_LT_U SETP_LE_U
                   SETP_LT_F SETP_LE_F SETP_EQ_F SETP_NE_F""".split()},

    # -- design: the float patterns select the compressed destructive form --
    # CCVInstrPatterns.td matches fadd/fmul/fminnum/fmaxnum straight to
    # C_FADD/C_FMUL/C_FMIN/C_FMAX per O-8. The three-address Format A forms are
    # therefore unreachable, and so are the predicated twins of the two that
    # had them -- O-33 cannot gate a uniform float add or multiply. Measured
    # rather than assumed: selecting three-address instead is instruction-for-
    # instruction identical on all eight kernels and two bytes worse in three
    # of them, and changes no lane-activation count, because the float
    # arithmetic in these kernels is per-lane data and divergent anyway. F-117.
    **{n: ("design", "fadd/fmul/fmin/fmax select the compressed two-address "
                     "form at ISel (CCVInstrPatterns.td); F-117")
       for n in "FADD FMUL FMIN FMAX FADD_P FMUL_P".split()},

    # -- design: `select` does not need `sel` -------------------------------
    "SEL": ("design", "select lowers to a predicated move whose tied false arm "
                      "gives the excluded lanes for free under invariant 10, so "
                      "§4 point 19 is never selected; F-58"),

    # -- todo: no lowering in the backend yet -------------------------------
    # The intrinsic surface: atomics, the warp vote/ballot group, the barrier
    # phase operations, and predicate spill to shared. Each needs a PTX
    # intrinsic mapped in CCVISelLowering, not an encoding. F-118.
    **{n: ("todo", "no PTX intrinsic lowering yet; F-118")
       for n in """ATOM_ADD_G CAS_G BALLOT UNBALLOT VOTE_ANY
                   BAR_INIT BAR_WAIT_PHASE PMOV LD_PRED_S ST_PRED_S""".split()},
    # Format J's second FP format code is BF16/E5M2, and the backend has no
    # bfloat type, so nothing can produce a contract-flagged bf16 multiply-add
    # for CCVCompress to fold. F-121.
    "FFMA_ACC_F1": ("todo", "no bf16 type in the backend, so there is no "
                            "format-1 multiply-add to compress; F-121"),

    # O-44's FP packed dot products. Adopted encodings the compiler cannot yet
    # reach: forming one needs a bfloat, half or FP8 value in the IR, and this
    # backend has none of those types. The simulator implements them and
    # tools/check-dp-fp.sh executes them, so the SEMANTICS are pinned even
    # though selection is not. F-137.
    **{n: ("todo", "no bf16/half/FP8 type in the backend, so nothing forms the "
                   "packed operand; semantics pinned by check-dp-fp.sh; F-137")
       for n in "DP2_BF16 DP2_F16 DP4_E4M3 DP4_E5M2".split()},
    # Sub-word pack/unpack. These address MEMORY packing -- a lane still holds
    # one element at every width (O-13, F-79) -- and nothing in the backend
    # forms a packed load. F-122.
    **{n: ("todo", "no packed-memory lowering; a lane still holds one element "
                   "at every width (O-13); F-122")
       for n in "PACKI PACKI_Z UNPACKI".split()},
    # Carry-out arithmetic. Format A''/B'' write a predicate beside the
    # result, which is what multi-precision addition wants; nothing lowers
    # i64 arithmetic yet. F-123.
    **{n: ("todo", "no multi-precision lowering to consume the carry "
                   "predicate; F-123")
       for n in "ADD_PP ADDI_PP".split()},
    # Calls and the compressed return. Both wait on the calling sequence.
    **{n: ("todo", "waiting on the calling sequence; F-21")
       for n in "CALL C_RET".split()},
    "C_RECONV": ("todo", "reconvergence is opportunistic and the compiler emits "
                         "no hint; F-124"),
    "C_FENCE": ("todo", "no fence lowering -- the barrier path covers what the "
                        "kernels need; F-124"),
}


def instructions(jsonpath):
    j = json.load(open(jsonpath))
    return {k: v for k, v in j.items()
            if isinstance(v, dict)
            and "Instruction" in v.get("!superclasses", [])
            and v.get("Namespace") == "CCV"}


def isel_reachable(iselinc):
    txt = open(iselinc).read()
    return set(re.findall(r"TARGET_VAL\(CCV::([A-Za-z0-9_]+)\)", txt))


# An occurrence of CCV::NAME is an emit site if it appears in one of these
# shapes. `case CCV::NAME:` and `getOpcode() == CCV::NAME` match none of them,
# which is deliberate -- see the docstring.
EMIT_SHAPES = [
    r"\bget\(\s*CCV::%s\b",                  # BuildMI(..., get(CCV::X))
    r"getMachineNode\(\s*CCV::%s\b",         # CurDAG->getMachineNode(CCV::X,
    r"MorphNodeTo\(\s*[^;]*?,\s*CCV::%s\b",  # CurDAG->MorphNodeTo(N, CCV::X,
    r"\breturn\s+CCV::%s\b",                 # return CCV::X;
    r"(?<![=!<>])=\s*CCV::%s\b",             # Opc = CCV::X;
    r"\?\s*CCV::%s\b",                       # cond ? CCV::X
    r"(?<!:):\s*CCV::%s\b",                  # ... : CCV::X   (ternary else)
    r"setOpcode\(\s*CCV::%s\b",              # MC-layer relaxation
]


def emit_sites(names):
    """opcode -> {file: set of triggers}, where a trigger of None means the emit
    is unconditional and a trigger of T means the emit shares a statement with
    `case CCV::T:` and so happens only when T is present."""
    sites = collections.defaultdict(lambda: collections.defaultdict(set))
    files = (glob.glob(str(ROOT / "llvm/CCV/**/*.cpp"), recursive=True) +
             glob.glob(str(ROOT / "llvm/CCV/**/*.h"), recursive=True))
    for f in files:
        base = os.path.basename(f)
        for stmt in open(f).read().split(";"):
            if "CCV::" not in stmt:
                continue
            triggers = {m for m in re.findall(r"case\s+CCV::([A-Za-z0-9_]+)\s*:",
                                              stmt) if m in names}
            for n in set(re.findall(r"CCV::([A-Za-z0-9_]+)", stmt)):
                if n not in names or n in triggers:
                    continue
                for shape in EMIT_SHAPES:
                    if re.search(shape % re.escape(n), stmt, re.S):
                        sites[n][base] |= (triggers or {None})
                        break
    return sites


def reachable_set(isel, emits):
    """Fixpoint over conditional emits. An unconditional emit is a production
    path on its own; a conditional one waits for its trigger."""
    reach = set(isel)
    for n, byfile in emits.items():
        if any(None in tr for tr in byfile.values()):
            reach.add(n)
    changed = True
    while changed:
        changed = False
        for n, byfile in emits.items():
            if n in reach:
                continue
            if any(t in reach for tr in byfile.values() for t in tr if t):
                reach.add(n)
                changed = True
    return reach


def main():
    gen = ROOT / "build" / "generated"
    jsonpath = sys.argv[1] if len(sys.argv) > 1 and sys.argv[1].endswith(".json") \
        else gen / "CCV.json"
    iselinc = gen / "CCVGenDAGISel.inc"
    for p in (jsonpath, iselinc):
        if not os.path.exists(p):
            print("  SKIP  %s is absent -- run tools/verify.sh or the TableGen "
                  "step first" % p)
            return 0

    insts = instructions(jsonpath)
    isel = isel_reachable(iselinc) & set(insts)
    emits = emit_sites(set(insts))
    reach = reachable_set(isel, emits)

    failures = []
    classified = {}
    for name in sorted(insts):
        if name in reach:
            if name in isel:
                classified[name] = ("isel", "")
            else:
                where = ",".join(sorted(emits[name]))
                classified[name] = ("mc" if where == "CCVAsmBackend.cpp"
                                    else "pass", where)
            # A declaration for something reachable is stale, and a stale
            # declaration is worse than a missing one: it makes the list look
            # like it covers ground it does not.
            if name in UNREACHABLE:
                failures.append(
                    "%s is declared %s but is reachable (%s) -- the "
                    "declaration is stale" %
                    (name, UNREACHABLE[name][0],
                     "ISel" if name in isel else ",".join(sorted(emits[name]))))
        elif name in UNREACHABLE:
            cat, reason = UNREACHABLE[name]
            classified[name] = (cat, reason)
            if cat not in ("design", "todo", "dead", "mc"):
                failures.append("%s: unknown category %r" % (name, cat))
            if not reason:
                failures.append("%s: declared %s with no reason" % (name, cat))
        else:
            classified[name] = ("UNREACHABLE", "")
            failures.append(
                "%s is defined but nothing can produce it: no ISel pattern "
                "reaches it, no pass emits it, and it is not declared in "
                "UNREACHABLE" % name)

    for name in UNREACHABLE:
        if name not in insts:
            failures.append("%s is declared unreachable but is not an "
                            "instruction in this description" % name)

    # A mapping-table entry whose SOURCE is unreachable is dead code, and dead
    # code in a lowering table is how a pass silently stops doing its job. The
    # float half of CCVCompress.cpp's table is the live example: ISel selects
    # the compressed form directly, so the entries that would narrow FADD and
    # FMUL can never fire. Reported, not failed -- an entry can legitimately
    # outlive its source for a release.
    stale_edges = []
    for n, byfile in sorted(emits.items()):
        for f, triggers in sorted(byfile.items()):
            for tr in sorted(t for t in triggers if t):
                if tr not in reach:
                    stale_edges.append((f, tr, n))

    tally = collections.Counter(c for c, _ in classified.values())
    if "--list" in sys.argv:
        for name, (cat, why) in classified.items():
            print("  %-10s %-24s %s" % (cat, name, why))
        print()
    for f, tr, n in stale_edges:
        print("  note  %s maps %s -> %s, but nothing produces %s"
              % (f, tr, n, tr))

    if failures:
        print("  FAIL  %d instruction(s) with no production path" % len(failures))
        for f in failures:
            print("      " + f)
        return 1

    print("  PASS  %d instructions, all with a production path "
          "(isel %d, pass %d, mc %d, declared %d)"
          % (len(insts), tally["isel"], tally["pass"], tally["mc"],
             tally["design"] + tally["todo"] + tally["dead"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
