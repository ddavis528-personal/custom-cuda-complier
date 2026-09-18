#!/usr/bin/env bash
# The gate has to catch the three bugs it was written for.
#
# F-111 exists because three defined-but-unselected encodings were found by
# three separate human reviews. A checker that passes today proves nothing about
# whether it would have caught them, so remove each production path in turn and
# require the failure. Source files are restored either way.
set -uo pipefail
cd "$(dirname "$0")/.."
fail=0
INC=${LLVM_INCLUDEDIR:-$(llvm-config --includedir)}
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
TMPINC=$TMP/isel.inc; TMPCPP=$TMP/instrinfo.cpp

mutate() {                 # $1 = label, $2 = file, $3 = sed expression
  local label=$1 file=$2 expr=$3
  cp "$file" "$file.mutbak"
  sed -i "$expr" "$file"
  if cmp -s "$file" "$file.mutbak"; then
    echo "  FAIL  mutation '$label' changed nothing -- the pattern has moved"
    mv "$file.mutbak" "$file"; fail=1; return
  fi
  if python3 tools/check-unselected.py >/dev/null 2>&1; then
    echo "  FAIL  removing $label did not fail the check"
    fail=1
  else
    echo "  PASS  removing $label fails the check"
  fi
  mv "$file.mutbak" "$file"
}

# A mutation in the .td needs the matcher table regenerated, since that table
# -- not the .td -- is what the checker reads.
mutate_td() {            # $1 = label, $2 = sed expression
  local label=$1 expr=$2 f=llvm/CCV/CCVInstrPatterns.td
  cp "$f" "$f.mutbak"
  sed -i "$expr" "$f"
  if cmp -s "$f" "$f.mutbak"; then
    echo "  FAIL  mutation '$label' changed nothing -- the pattern has moved"
    mv "$f.mutbak" "$f"; fail=1; return
  fi
  cp build/generated/CCVGenDAGISel.inc "$TMPINC"
  if llvm-tblgen -I "$INC" -I llvm/CCV --gen-dag-isel llvm/CCV/CCV.td \
       -o build/generated/CCVGenDAGISel.inc 2>/dev/null \
     && ! python3 tools/check-unselected.py >/dev/null 2>&1; then
    echo "  PASS  removing $label fails the check"
  else
    echo "  FAIL  removing $label did not fail the check"
    fail=1
  fi
  cp "$TMPINC" build/generated/CCVGenDAGISel.inc
  mv "$f.mutbak" "$f"
}

# 1. `bra.short`, found by the walkthrough review. ISel reaches it through one
#    pattern; CCVInstrInfo::insertBranch is a second producer, so BOTH have to
#    go before it is unreachable -- which is the checker being right, not
#    lenient.
cp llvm/CCV/CCVInstrInfo.cpp "$TMPCPP"
sed -i 's/get(CCV::C_BRA)/get(CCV::BRA)/g' llvm/CCV/CCVInstrInfo.cpp
mutate_td "the bra.short pattern (with insertBranch also removed)" \
          's/^def : Pat<(br bb:$t), (C_BRA bb:$t)>;/\/\/ mutated/'
cp "$TMPCPP" llvm/CCV/CCVInstrInfo.cpp

# 2. The Format C" immediate compare, found by reading §3 beside the generated
#    code. Ten opcodes hang off one mapping function.
mutate "the immediate-compare mapping" llvm/CCV/CCVISelDAGToDAG.cpp \
       's/^  case CCV::SETP_LT_NP:   return CCV::SETP_LT_NPI;/  \/\/ mutated/'

# 3. The compressed immediate forms, found by looking for the first two.
mutate "C_ANDI from the compression table" llvm/CCV/CCVCompress.cpp \
       's/^  case CCV::ANDI: return CCV::C_ANDI;/  \/\/ mutated/'

# 4. The transitive case, in both directions. F-116 removed the last live
#    example of it -- the dead PSEUDO_SETP_* expansions -- so it is injected
#    here rather than relying on one surviving in the tree, which is how a
#    check quietly stops testing what it was written for.
#
#    A gated emit whose trigger is unreachable must NOT count as a production
#    path: `SETP_LT` is declared unreachable, so a table entry keyed on it
#    produces nothing, and the checker has to still pass. Without the fixpoint
#    it would see an emit site and report the declaration as stale.
f=llvm/CCV/CCVCompress.cpp
cp "$f" "$f.mutbak"
sed -i 's|^  case CCV::ADDI: return CCV::C_ADDI;|  case CCV::ADDI: return CCV::C_ADDI;\n  case CCV::SETP_LT: return CCV::SETP_LT_I;|' "$f"
if cmp -s "$f" "$f.mutbak"; then
  echo "  FAIL  the trigger-gating mutation changed nothing -- the table has moved"
  fail=1
elif python3 tools/check-unselected.py >/dev/null 2>&1; then
  echo "  PASS  an emit gated on an unreachable trigger is not a production path"
else
  echo "  FAIL  an emit gated on an unreachable trigger was counted as a"
  echo "        production path -- reachability is not a fixpoint"
  fail=1
fi

#    And the same entry UNGATED is a real production path, so the declaration
#    becomes stale and the check has to say so. This is the half that proves
#    the pass above came from the fixpoint and not from the checker ignoring
#    the file.
sed -i 's|^  case CCV::SETP_LT: return CCV::SETP_LT_I;|  return CCV::SETP_LT_I;\n  case CCV::SETP_LT: return CCV::C_ADDI;|' "$f"
if python3 tools/check-unselected.py >/dev/null 2>&1; then
  echo "  FAIL  an ungated emit of a declared-unreachable instruction did not"
  echo "        fail the check"
  fail=1
else
  echo "  PASS  an ungated emit makes the declaration stale, and it is caught"
fi
mv "$f.mutbak" "$f"

exit $fail
