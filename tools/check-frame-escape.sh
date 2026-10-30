#!/usr/bin/env bash
# IS-25 (DA tab rev 97): a frame pointer is lane-relative, so ccv-llc warns
# where one visibly reaches another thread (CCVFrameEscape).
#
# test/cuda/frame-escape.cu must give exactly its two marked escapes (to
# .shared and to .global) and nothing for its private uses (a pointer passed to
# a device function, or stored into another frame object). Then every CUDA
# kernel in the corpus, and CoreMark-derived, must give none: CP-67's reading,
# that no corpus kernel hands &local across threads, made mechanical.
#
# Control, which must fail: -ccv-frame-in-priv=false, under which frame
# pointers are flat and the warning is off, so the test kernel gives none.
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
fail=0
warnings() {   # <kernel.cu> [ccv-llc flags]: the warning lines
  CCV_CFLAGS="-Itest/bench" CCV_LLCFLAGS="${2:-}" \
    ./tools/cuda-to-asm.sh "$1" "$TMP/k.s" 2>&1 >/dev/null | grep "warning: CCV:.*IS-25" || true
}
w=$(warnings test/cuda/frame-escape.cu)
ctl=$(warnings test/cuda/frame-escape.cu -ccv-frame-in-priv=false)
if [ "$(grep -c . <<< "$w")" = 2 ] && grep -q "stored to .shared" <<< "$w" &&
   grep -q "stored to memory outside the thread's frame" <<< "$w" && [ -z "$ctl" ]; then
  echo "  PASS  frame-escape.cu: its two escapes, to .shared and .global, are warned and its private uses are not (control: off without IS-25)"
else
  echo "  FAIL  frame-escape.cu: '$w' (control '$ctl')"; fail=1
fi

hits=""
for k in test/cuda/*.cu; do
  [ "$k" = test/cuda/frame-escape.cu ] && continue
  h=$(warnings "$k")
  [ -n "$h" ] && hits="$hits $k"
done
python3 - "$TMP" <<'PY' > "$TMP/cm.txt" 2>&1 || true
import importlib.util, subprocess, sys
tmp = sys.argv[1]
spec = importlib.util.spec_from_file_location("sw", "tools/sweep-coremark.py")
sw = importlib.util.module_from_spec(spec); spec.loader.exec_module(sw)
sw.build(tmp, "", "cm")
r = subprocess.run(["build/ccv-llc", f"{tmp}/cm-lowered.ll", "-o", f"{tmp}/cm.s"],
                   capture_output=True, text=True)
print(r.stderr)
print("built" if r.returncode == 0 else "not built")
PY
grep -q "warning: CCV:.*IS-25" "$TMP/cm.txt" && hits="$hits coremark-derived"
grep -qx built "$TMP/cm.txt" || hits="$hits coremark-derived(did-not-build)"
n=$(ls test/cuda/*.cu | grep -vc frame-escape)
if [ -z "$hits" ]; then
  echo "  PASS  no corpus kernel hands a frame pointer to another thread ($n CUDA kernels and CoreMark-derived; CP-67)"
else
  echo "  FAIL  frame pointers escape in:$hits"; fail=1
fi
exit $fail
