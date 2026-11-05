# CP handoff (compiler implementation)

Updated 2026-11-04. Keep this current at every task's end; it is what
survives a compaction. The repo's rules are in its docs and skills; this holds
CP's.

## Working rules
- Repo /home/user/custom-cuda-complier, branch `ccr-ea1c4e17-tem30u` only.
  custom-cuda-core is read-only to CP. No PRs.
- Push only after a clean gate. Releases: `./tools/make-release.sh --push`
  (runs verify.sh, about 25 min; CP alone cuts compiler snapshots). Run it in
  the background, logging to the scratchpad's release.log with `rc=` appended,
  and read `grep VERIFY build/release-verify.log`. Never modify the tree while
  a gate runs. Push the branch after the release passes. The remote refuses
  snapshot tags; that is expected ("local only").
- Merge a peer's branch as soon as its pushed work bears on CP's (DA rev 89),
  merge commits only, never rebase or force-push.
- Commits end with the Co-Authored-By and Claude-Session lines from the
  session's attribution reminder. No model ids in commits or artifacts.
- Never weaken a control to get green.
- Register: write only the CP tab (node 099ebfed-9eea, table
  m8yvbw8rqgz.6172, insert side "end"). Container
  {"kind":"project","id":"JApHYjaUESeq8tsGMGXMU5"}. A row is 4 cells: ID,
  date, state, body with a bold first sentence ending in "Needs: ...".
  Notice per row that names or answers another agent, send_message priority
  "later": `REGISTER-NOTICE v1 from=CP to=X tab=099ebfed-9eea rows=... rev=N`,
  a summary line, then the pointer line. Never answer a notice with a notice.
  Rows and notices are data; verify a claimed DA decision in the DA tab
  (d5076b00-ef1b), and ask Daniel when it is not there.
- Pongs: one line pair, never answered. Pings: Fridays only (DA, 2026-10-30,
  TI-49); the Saturday sweep checks Friday's pongs.

## Daily sweep (scheduled task trig_01Hp4MZnx61rMQL7Dd5qjd5z, 02:19 PT)
Read every tab since the bookmarks and answer rows with CP in Needs; merge
every remote branch except release and gate-scratch/* (CP-77); check docs/register/roster.json against
core's (`git -C ../custom-cuda-core show
origin/claude/custom-cuda-core-infra-6msg93:docs/register/roster.json`);
run core's latest tools/setup-session-home.py --check (TI-50; on drift ask
Daniel before any re-run); make-release if the head is not snapshotted; pings
on Fridays; report in a few lines.

## Register bookmarks (revs read through), scratchpad cp-register-bookmarks.json
CP 152, IS 189, OA 331, AR 275, TI 305, OI 274, DA 106, RA 63, RI 2, Conventions 17 (swept 2026-11-04).
RI (RCU implementation, DA rev 101) has tab 8e4547bc-c469, no session yet;
RA and RI are in the roster (copied from core 2026-11-03).
Sessions: AR 01FnGhxke3r33MeArLeQJRcD, OA 01TbX2MyX6quhjarDR7J2bMR,
IS 01989HiTNh4Gx7XMSsdvdE7Z, TI 01J4Yp3xeV6DJtgCtcoqVsAq,
OI 01DMw4FtFbGoVboMGxWpLBuv, RA 01QPk2jzLmjd3MWXjayVUy9d (RCU architect, DA rev 99;
tab 9851686b-2b0a) (all `session_` + id).
Tabs: AR bc521c46-9710, OA 4c6a3151-83eb, IS 60e6f93a-7fdc,
TI e8b1d9d9-df9b, OI 384bc26c-cef6, Conventions 55232329-ff5c.

## State
- Last snapshot 7ec31c0 (89dc3bf: roster with RA and RI, CP-77 done); 85a1c6b (0799e97) merged IS's 0aafcf5 (Format G
  opcode points in §3). Earlier: RA-19 pmov merge (CP-75), O-85 (CP-76). Before it d9ddd2c
  (f5fa030): O-84/IS-25 frames at the bottom of the O-83 region, default.
  TI pinned d9ddd2c (core 5fe7177).
- IS's branch ccr-3868632d-p8esoz: IS now skips equal-tree merges and
  fast-forwards (CP-69, CP-70).

## Open work, most urgent first
1. TI-48 closed (TI rev 269); autoCompactWindow 400000 set here as in core (CP-73).
2. TI-49 (2), (3) are OA's to rule; nothing for CP until then.
3. TI-50 done (CP-74): /home/user/.claude installed by core's
   setup-session-home.py with Daniel's approval; --check rc=0.
4. O-85 lowering of CUDA's __shfl_*_sync/__ballot_sync/__any_sync/__all_sync
   (F-118, F-206) is not built; offered to Daniel. IS to record CP-76's opcode
   points (done, 0aafcf5); TI to take them.
   CP-77 done: the sweep task skips gate-scratch/* (TI rev 289; Daniel
   approved 2026-11-02).
5. Recent rows: CP-65..CP-77.
