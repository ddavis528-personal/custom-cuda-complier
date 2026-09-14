#!/usr/bin/env bash
# The uniformity report is evidence for a SPEC change (F-56), so its buckets
# have to mean what they say.
#
# The version this replaces had one "blocked: encoding (§4 128+/256+ have no A′
# form)" line fed by a `default: return false`. Branches, stores, `srd` and
# `select` all fell into it, and F-56 was sized off the total -- 5 in transpose,
# of which 3 were actually conversions. A bucket labelled with a claim about the
# ISA must not be a catch-all, and nothing in the gate noticed.
#
# So: every instruction the report declines to mask must land in a bucket that
# names a real reason, and the F-56 bucket in particular must be non-empty
# exactly where a uniform conversion exists and empty where none does.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0

report() {               # $1 = benchmark name -> report on stdout
  ./tools/cuda-to-asm.sh "test/bench/$1.cu" "$TMP/$1.s" "$TMP/$1" >/dev/null 2>&1 \
    || { echo "  FAIL  $1 did not compile"; return 1; }
  ./build/ccv-llc "$TMP/$1-lowered.ll" -o /dev/null -ccv-uniformity-stats 2>&1
}

bucket() {               # $1 = report text, $2 = label -> count (0 if absent)
  echo "$1" | sed -n "s/.*blocked: $2 *: *\([0-9]*\).*/\1/p" | head -1 | grep -E '^[0-9]+$' || echo 0
}

for k in vadd saxpy dot reduce transpose; do
  r=$(report "$k") || { fail=1; continue; }

  # 1. No catch-all. An opcode this report does not model must be visible as
  #    unmodelled, and there must not be any.
  u=$(bucket "$r" "UNMODELLED")
  if [ "$u" != "0" ]; then
    echo "  FAIL  $k: $u unmodelled instruction(s) -- $(echo "$r" | grep 'unmodelled opcodes')"
    echo "        add them to classify() in CCVUniformity.cpp; do NOT let them"
    echo "        fall into a bucket that names an encoding limit."
    fail=1
  fi

  # 2. The F-56 bucket tracks conversions and SFU, and nothing else. Count the
  #    uniform ones independently, from the IR, and require agreement.
  want=$(python3 - "$TMP/$k-lowered.ll" <<'PY'
import re, sys
# A conversion or fdiv anywhere in the kernel is a candidate; whether it is
# warp-uniform is the report's job, so this is an upper bound and the check
# below is one-sided on purpose.
src = open(sys.argv[1]).read()
print(len(re.findall(r'\b(uitofp|sitofp|fptoui|fptosi|fdiv|udiv|sdiv|urem|srem)\b', src)))
PY
)
  got=$(bucket "$r" "no A′ form")
  if [ "$want" = "0" ] && [ "$got" != "0" ]; then
    echo "  FAIL  $k: report blames $got instruction(s) on §4 128+/256+, but the"
    echo "        kernel has no conversion, no SFU call and no division."
    fail=1
  fi
  if [ "$want" != "0" ] && [ "$got" = "0" ]; then
    echo "  note  $k: $want division/conversion site(s), none counted against"
    echo "        F-56 -- expected when the divisor is divergent."
  fi
  echo "  $k: maskable $(echo "$r" | sed -n 's/.*maskable to lane 0 *: *\([0-9]*\).*/\1/p'), F-56 blocks $got, unmodelled $u"
done

exit $fail
