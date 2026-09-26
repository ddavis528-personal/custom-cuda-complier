#!/usr/bin/env bash
# A 16-bit kernel with a LOOP computes the right answer, and the width mode
# survives the back edge.
#
# F-87 moved the width transitions out of the loop body and onto the incoming
# edges: the loop now runs with r6/r7 narrow for its whole lifetime and never
# re-establishes the mode. That is the entire saving, and it is also the entire
# risk -- if the mode does not actually persist across the back edge, or if some
# instruction in the body silently restores it, the second iteration computes at
# the wrong width. The straight-line test cannot see any of that: it has one
# iteration.
#
# So this checks every element of a multi-iteration run, not just the first, and
# checks the guard element past the array for transfer size (F-67).
set -uo pipefail
cd "$(dirname "$0")/.."
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT

# Built BOTH ways. O-23's aligned form is what the benchmark measures and what
# the ISA document recommends, and it is where F-87's claim is made. The
# unaligned form still pays per-iteration transitions for a different reason --
# the allocator gives one register the in-window address arithmetic AND the
# narrow data, so the width genuinely changes inside the body (F-80) and no
# amount of edge placement can lift it out. That is reported, not asserted,
# because it is someone else's bug.
CCV_CFLAGS=-DCCV_ALIGNED ./tools/cuda-to-asm.sh test/bench/vadd16_loop.cu \
    "$TMP/v.s" "$TMP/v" >/dev/null 2>&1 \
  || { echo "  FAIL  vadd16_loop.cu did not compile"; exit 1; }
build/ccv-llc "$TMP/v-lowered.ll" -o "$TMP/v.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/v.o" "$TMP/v.bin" || exit 1

./tools/cuda-to-asm.sh test/bench/vadd16_loop.cu "$TMP/u.s" "$TMP/u" >/dev/null 2>&1 \
  || { echo "  FAIL  vadd16_loop.cu did not compile unaligned"; exit 1; }
build/ccv-llc "$TMP/u-lowered.ll" -o "$TMP/u.o" -obj 2>/dev/null || exit 1
llvm-objcopy -O binary --only-section=.text "$TMP/u.o" "$TMP/u.bin" || exit 1

# The aligned body must contain no width transition at all: that is what F-87
# bought, and a regression would be invisible in the results.
body=$(sed -n '/^LBB0_1:/,/bra LBB0_1/p' "$TMP/v.s" | grep -cE '^\s*chwidth')
if [ "$body" -ne 0 ]; then
  echo "  FAIL  $body chwidth left in the aligned loop body -- F-87 regressed"
  sed -n '/^LBB0_1:/,/bra LBB0_1/p' "$TMP/v.s" | sed 's/^/        /'
  exit 1
fi
echo "  PASS  no width transition inside the aligned loop body (F-87)"
# The unaligned body is held to the same standard since F-80: the allocator's
# width affinity is what keeps the address arithmetic and the narrow data in
# different registers, and without it this body regains three transitions.
ub=$(sed -n '/^LBB0_1:/,/bra LBB0_1/p' "$TMP/u.s" | grep -cE '^\s*chwidth')
if [ "$ub" -ne 0 ]; then
  echo "  FAIL  $ub chwidth in the unaligned loop body -- F-80 regressed"
  sed -n '/^LBB0_1:/,/bra LBB0_1/p' "$TMP/u.s" | sed 's/^/        /'
  exit 1
fi
echo "  PASS  no width transition inside the unaligned loop body either (F-80)"

for BIN in "$TMP/v.bin" "$TMP/u.bin"; do
python3 - "$BIN" <<'PY'
import subprocess, sys, re
binf = sys.argv[1]
LAUNCH, A, B, C = 0x20000, 0x30000, 0x40000, 0x50000
N = 256            # 8 iterations per thread at 32 threads
GUARD = 0xABCD
a = [(i * 7 + 3) & 0xFFFF for i in range(N)]
b = [(i * 251 + 11) & 0xFFFF for i in range(N)]

pokes = ["-poke", f"{hex(LAUNCH)}=32"]
for slot, val in ((0x20, C >> 16), (0x28, A >> 16), (0x30, B >> 16), (0x38, N)):
    pokes += ["-poke", f"{hex(LAUNCH + slot)}={val}"]
for i in range(0, N, 2):
    pokes += ["-poke", f"{hex(A + i * 2)}={a[i] | (a[i+1] << 16)}"]
    pokes += ["-poke", f"{hex(B + i * 2)}={b[i] | (b[i+1] << 16)}"]
pokes += ["-poke", f"{hex(C + N * 2)}={GUARD | (GUARD << 16)}"]

peeks = []
for i in range(0, N, 2):
    peeks += ["-peek", hex(C + i * 2)]
peeks += ["-peek", hex(C + N * 2)]

r = subprocess.run(["build/ccv-sim", binf, *pokes, *peeks],
                   capture_output=True, text=True)
got = [int(x) for x in re.findall(r"= (\d+)", r.stdout)]
if len(got) != N // 2 + 1:
    print(f"  FAIL  simulator returned {len(got)} words, expected {N//2+1}")
    print("  " + (r.stderr.strip() or r.stdout.strip())[:300]); sys.exit(1)

bad = []
for w in range(N // 2):
    lo, hi = got[w] & 0xFFFF, (got[w] >> 16) & 0xFFFF
    for j, g in ((2 * w, lo), (2 * w + 1, hi)):
        want = (a[j] + b[j]) & 0xFFFF
        if g != want:
            bad.append((j, g, want))
if bad:
    print(f"  FAIL  {len(bad)} of {N} elements wrong; first: "
          f"c[{bad[0][0]}] = {bad[0][1]}, want {bad[0][2]}")
    # Which iteration failed says what broke: element j is handled on
    # iteration j//32, so all-but-the-first means the mode did not survive
    # the back edge.
    iters = sorted({j // 32 for j, _, _ in bad})
    print(f"        failing iterations: {iters}")
    sys.exit(1)
print(f"  PASS  vadd16_loop: {N} elements over 8 iterations per thread, all correct")

guard = got[-1]
if guard != (GUARD | (GUARD << 16)):
    print(f"  FAIL  the element past the array was overwritten: 0x{guard:08x}")
    sys.exit(1)
print("  PASS  the element past the array is untouched (2-byte stores)")
PY
done
