#!/usr/bin/env bash
# A local array addressed two ways must be the SAME array (F-131).
#
# The codegen for a dynamically indexed frame slot is `[r15, rindex, 1, disp]`
# and for a constant index it is `[r15 + disp']`. Both are plausible-looking
# whatever the frame offset or the scale-enable bit happen to be, and a wrong
# one produces a valid instruction addressing the wrong slot. Reading back what
# the same kernel wrote through the OTHER form is what catches that.
#
# test/accept/local-array.ll writes 2.5 at a[i] and 1.5 at a[3], then reads both
# back and adds. So the answer is 4.0 -- except at i == 3, where the two writes
# alias and the second wins, giving 3.0. That aliasing case is the test: it can
# only come out right if the dynamic form and the constant form agree on where
# a[3] is, which pins the frame displacement AND the scale together.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

build/ccv-llc test/accept/local-array.ll -o "$TMP/a.o" -obj 2>/dev/null || {
  echo "  FAIL  local-array.ll did not compile"; exit 1; }
llvm-objcopy -O binary --only-section=.text "$TMP/a.o" "$TMP/a.bin" || exit 1

# The base+index form must actually have been selected, or this checks nothing.
if ! build/ccv-llc test/accept/local-array.ll -o - 2>/dev/null |
     grep -qE '\[r15, r[0-9]+, [0-9]+, -?[0-9]+\]'; then
  echo "  FAIL  no base+index frame access emitted -- the dynamic index did"
  echo "        not select Format D base+index, so the execution below would"
  echo "        prove nothing about it"
  exit 1
fi

python3 - "$TMP/a.bin" <<'PY'
import re, struct, subprocess, sys
binf = sys.argv[1]
LAUNCH, OUT = 0x20000, 0x30008
bad = 0
for i in range(8):
    pokes = ["-poke", f"{hex(LAUNCH + 24)}=8",      # .local window base
             "-poke", f"{hex(LAUNCH + 56)}={i}"]    # the dynamic index
    r = subprocess.run(["build/ccv-sim", binf, *pokes, "-peek", hex(OUT)],
                       capture_output=True, text=True)
    got = re.findall(r"= (\d+)", r.stdout)
    if not got:
        print(f"  FAIL  i={i}: simulator produced nothing")
        print("  " + (r.stderr.strip() or r.stdout.strip())[:200]); sys.exit(1)
    val = struct.unpack("<f", struct.pack("<I", int(got[0])))[0]
    want = 3.0 if i == 3 else 4.0
    if val != want:
        print(f"  FAIL  i={i}: a[i]+a[3] = {val}, want {want}")
        bad = 1
if bad:
    sys.exit(1)
print("  PASS  local array: dynamic and constant indexing agree, "
      "including where they alias")
PY
