#!/usr/bin/env bash
# A static snapshot of the compiler repository, browsable on GitHub, WITH what
# the build generates -- and a built simulator other repositories can run.
#
#   tools/make-release.sh [--branch=release] [--push]
#
# The development branch keeps generated files out of git: each has one source
# of truth here, and a stale checked-in copy is a second truth that drifts. A
# snapshot is a SEPARATE branch, never merged back, holding:
#
#   - the source tree at one commit, exactly;
#   - build/generated/: TableGen's output at its real path, including
#     CCV.json, the instruction description tools/ccv-as.py assembles from;
#   - release/bin/ccv-sim: the built functional simulator, with its dynamic
#     dependencies recorded. It links LLVM statically and needs only system
#     libraries, so a sibling repository (custom-cuda-core) can pin a
#     snapshot commit and run ccv-sim from it, rather than keeping ccv-sim's
#     output as checked-in checkpoint data;
#   - release/bench/: tools/bench.py (text and --json) and both sweeps --
#     what docs/benchmarks.md is checked against;
#   - release/asm/: the compiled CCV assembly of every CUDA kernel in test/;
#   - release/verify.log, and SNAPSHOT.md: source commit, date, tool
#     versions, gate result, and a sha256 manifest of release/.
#
# One commit per snapshot on the release branch, parented on the previous
# one. The COMMIT is the identity: it is tagged snapshot-<date>-<sha7> where
# the remote accepts tags, and nothing depends on that. The gate must pass.
set -uo pipefail
cd "$(dirname "$0")/.."
BRANCH=release
PUSH=0
for a in "$@"; do
  case "$a" in
    --branch=*) BRANCH=${a#--branch=} ;;
    --push)     PUSH=1 ;;
    *) echo "usage: $0 [--branch=<name>] [--push]" >&2; exit 2 ;;
  esac
done
MAXFILE=$((5 * 1024 * 1024))
MAXTOTAL=$((30 * 1024 * 1024))

die() { echo "make-release: $*" >&2; exit 1; }

[ -z "$(git status --porcelain --untracked-files=no)" ] ||
  die "the working tree has uncommitted changes; a snapshot must be a commit"
SHA=$(git rev-parse HEAD)
SHA7=$(git rev-parse --short=7 HEAD)
SRCBRANCH=$(git rev-parse --abbrev-ref HEAD)
DATE=$(date -u +%Y-%m-%d)
TAG="snapshot-$DATE-$SHA7"
git rev-parse -q --verify "refs/tags/$TAG" >/dev/null &&
  die "$TAG exists: this commit has been snapshotted today already"

# -- 1. the gate, on exactly this commit -----------------------------------
echo "make-release: running the gate on $SRCBRANCH@$SHA7"
mkdir -p build
if ! ./tools/verify.sh >build/release-verify.log 2>&1; then
  tail -5 build/release-verify.log >&2
  die "tools/verify.sh failed; no snapshot of a red tree (log: build/release-verify.log)"
fi
[ -x build/ccv-sim ] && [ -f build/generated/CCV.json ] ||
  die "no build/ccv-sim or build/generated/CCV.json after the gate"

# -- 2. artifacts ----------------------------------------------------------
STAGE=$(mktemp -d)
WT=$(mktemp -d)
trap 'rm -rf "$STAGE"; git worktree remove --force "$WT" >/dev/null 2>&1; rm -rf "$WT"' EXIT
git archive "$SHA" | tar -x -C "$STAGE"
A="$STAGE/release"
mkdir -p "$STAGE/build/generated" "$A/bin" "$A/bench" "$A/asm"
cp -p build/generated/* "$STAGE/build/generated/"
cp build/release-verify.log "$A/verify.log"
cp build/ccv-sim "$A/bin/ccv-sim"
{
  echo "ccv-sim built from $SRCBRANCH@$SHA on $(uname -m), $(ldd --version 2>&1 | head -1)"
  echo
  echo "Dynamic dependencies (LLVM is linked statically):"
  ldd build/ccv-sim | sed 's/ (0x[0-9a-f]*)//'
} >"$A/bin/ccv-sim.txt"

python3 tools/bench.py >"$A/bench/bench.txt" 2>&1 || die "tools/bench.py failed"
python3 tools/bench.py --json >"$A/bench/bench.json" 2>/dev/null || die "bench --json failed"
./tools/sweep-tiles.sh >"$A/bench/sweep-tiles.txt" 2>&1 || die "sweep-tiles failed"
./tools/sweep-decode.sh >"$A/bench/sweep-decode.txt" 2>&1 || die "sweep-decode failed"

# Every CUDA kernel in the repo, compiled. A kernel that does not compile at
# its default parameters is listed, not hidden.
ASM_FAILED=""
for cu in test/bench/*.cu test/cuda/*.cu; do
  name="$(basename "$(dirname "$cu")")-$(basename "$cu" .cu)"
  # -Itest/bench: the shared portable.h, as tools/sweep-decode.sh passes it.
  if ! CCV_CFLAGS="-Itest/bench" ./tools/cuda-to-asm.sh "$cu" "$A/asm/$name.s" >/dev/null 2>&1; then
    rm -f "$A/asm/$name.s"
    ASM_FAILED="$ASM_FAILED $cu"
  fi
done

big=$(find "$A" -type f -size +"$MAXFILE"c)
[ -z "$big" ] || die "artifact over the $((MAXFILE / 1024 / 1024)) MB cap: $big"
total=$(du -sb "$A" | cut -f1)
[ "$total" -le "$MAXTOTAL" ] || die "release/ is $total bytes, over the cap"

ver() { "$@" 2>&1 | head -1; }
{
  echo "# Snapshot $TAG"
  echo
  echo "**A generated, read-only snapshot. Do not edit or merge it.** The source"
  echo "is \`$SRCBRANCH\` at \`$SHA\`; this branch is rebuilt from source by"
  echo "\`tools/make-release.sh\`, and nothing here flows back."
  echo
  echo "Beyond the source tree at that commit:"
  echo
  echo "- **\`build/generated/\`:** TableGen's output, including \`CCV.json\`,"
  echo "  which \`tools/ccv-as.py\` assembles from. A build product on the"
  echo "  development branch."
  echo "- **\`release/bin/ccv-sim\`:** the built functional simulator"
  echo "  (\`ccv-sim.txt\` records its system-library dependencies). A pinned"
  echo "  snapshot commit is how another repository runs it."
  echo "- **\`release/bench/\`:** \`tools/bench.py\` and both sweeps -- the"
  echo "  numbers \`docs/benchmarks.md\` is checked against."
  echo "- **\`release/asm/\`:** every CUDA kernel under \`test/\`, compiled."
  echo "- **\`release/verify.log\`:** the gate."
  echo
  echo "| | |"
  echo "|---|---|"
  echo "| Source | \`$SRCBRANCH\` @ \`$SHA\` |"
  echo "| Built | $DATE (UTC) |"
  echo "| Gate | \`tools/verify.sh\`: $(grep -o 'VERIFY: [A-Z]*' build/release-verify.log | tail -1) |"
  echo "| clang | $(ver clang --version) |"
  echo "| LLVM | $(ver llvm-config --version) |"
  echo "| Platform | $(uname -m), $(ldd --version 2>&1 | head -1) |"
  if [ -n "$ASM_FAILED" ]; then
    echo "| Kernels not compiled at default parameters |$ASM_FAILED |"
  fi
  echo
  echo "## Manifest of release/"
  echo
  echo '```'
  (cd "$STAGE" && find release -type f | sort | xargs sha256sum)
  echo '```'
} >"$STAGE/SNAPSHOT.md"

# -- 3. commit it on the release branch --------------------------------------
PARENT=$(git rev-parse -q --verify "refs/heads/$BRANCH" ||
         git rev-parse -q --verify "refs/remotes/origin/$BRANCH" || true)
rm -rf "$WT"
git worktree add --detach "$WT" "$SHA" >/dev/null 2>&1 || die "worktree failed"
(
  cd "$WT"
  git rm -rq --cached . >/dev/null
  find . -mindepth 1 -maxdepth 1 ! -name .git -exec rm -rf {} +
  cp -a "$STAGE"/. .
  git add -A -f .
  TREE=$(git write-tree)
  MSG=$(printf 'Snapshot of %s@%s\n\nGenerated by tools/make-release.sh: the source tree at %s,\nbuild/generated/, a built ccv-sim, and the artifacts under release/.\nRead-only; never merged back.\n' "$SRCBRANCH" "$SHA7" "$SHA")
  if [ -n "$PARENT" ]; then
    NEW=$(git commit-tree "$TREE" -p "$PARENT" -m "$MSG")
  else
    NEW=$(git commit-tree "$TREE" -m "$MSG")
  fi
  git update-ref "refs/heads/$BRANCH" "$NEW"
  git tag "$TAG" "$NEW"
) || die "commit failed"

NFILES=$(git ls-tree -r --name-only "$BRANCH" | wc -l)
echo "make-release: $TAG on branch $BRANCH at $(git rev-parse --short "$BRANCH") ($NFILES files, release/ $((total / 1024)) KB)"
if [ "$PUSH" = 1 ]; then
  git push -u origin "$BRANCH" || die "push of $BRANCH failed; the snapshot is local"
  echo "make-release: pushed $BRANCH ($(git rev-parse "$BRANCH"))"
  if git push origin "refs/tags/$TAG" >/dev/null 2>&1; then
    echo "make-release: pushed $TAG"
  else
    echo "make-release: the remote refused $TAG; it is local only"
  fi
else
  echo "make-release: local only; publish with --push"
fi
