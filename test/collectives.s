# The warp collectives as O-85 defines them (RA-20, DA 2026-11-02).
# Lane l's results go to word l of a window: up 3, down 4, bfly 5, register
# down 6, ballot 7; the predicates to window 9, word P at 0x90400 + 4P.
# Expected (and what each control changes):
#   0x30000 up 1, lane 0 keeps its own:          0   (-ccv-test-shfl-wrap: 31)
#   0x30014 up 1, lane 5 reads lane 4:            4
#   0x4007c down 1, lane 31 keeps its own:       31   (wrap: 0)
#   0x50010 bfly 1, lane 4 reads lane 5:          5
#   0x6000c down by R1, lane 3 reads lane 6:      6
#   0x60050 down by R1, lane 20 keeps its own:   20   (wrap: lane 8, 8)
# Then lanes 16-31 branch away, and lanes 0-15 alone run the rest:
#   0x70000 ballot !P0, lane 0: no participant has it   0   (-ccv-test-collective-issue: 0xffff0000)
#   0x70050 ballot, lane 20 did not participate: 0x77
#   0x90404 P1 = unballot of R8 (0 in lanes 0-3, 0xffff in 4-31), guard P1:
#           lanes 4-15 take their own bit l, 16-31 keep P1's ones  0xfffffff0
#           (-ccv-test-unballot-lowest: lane 0's whole R8 = 0, so 0xffff0000)
#   0x90408 P2 = vote.all P0 over lanes 0-15: 1 there, 0 kept above  0x0000ffff
#           (collective-issue: all 32 lanes vote, P0 is not all set, 0)
#   0x9040c P3 = vote.any !P0, from all ones: 0 in lanes 0-15     0xffff0000
#           (collective-issue: lanes 16-31 have !P0, so 0xffffffff)
        SRD          R1, 0              # lane index
        POR          P1, 5, 1           # P1 = !P1 | P1: all ones, the guard
        POR          P3, 7, 3           # P3 all ones
        MOVI         R10, 3
        MOVI         R11, 4
        MOVI         R12, 5
        MOVI         R13, 6
        SHFL_UP      R4, 1, R1, 1
        ST_GLOBAL_IDX R4, R10, R1, 1, 0
        SHFL_DOWN    R4, 1, R1, 1
        ST_GLOBAL_IDX R4, R11, R1, 1, 0
        SHFL_BFLY    R4, 1, R1, 1
        ST_GLOBAL_IDX R4, R12, R1, 1, 0
        SHFL_DOWN_R  R4, 1, R1, R1
        ST_GLOBAL_IDX R4, R13, R1, 1, 0
        MOVI         R7, 0x77
        MOVI         R8, 0xffff
        MOVI         R9, 0
        MOVI         R10, 7
        MOVI48       R3, 9
        SETP_LT_NPI  P0, R14, R1, 16    # lanes 0-15
        SETP_LT_NPI  P2, R14, R1, 4     # lanes 0-3
        MOV_P        R8, 2, R9, R9, R9  # @P2 R8 = 0
        BRA_PRED     4, join            # lanes 16-31 skip the collectives
        BALLOT       R7, 1, 4           # @P1 ballot R7, !P0
        VOTE_ALL     P2, 1, 0           # @P1 vote.all P2, P0
        VOTE_ANY     P3, 1, 4           # @P1 vote.any P3, !P0
        UNBALLOT     P1, 1, R8          # last: it rewrites the guard; @P1 unballot P1, R8
join:   ST_GLOBAL_IDX R7, R10, R1, 1, 0
        ST_PRED_G    14, R3, 1024       # P1, P2, P3 to 0x90404..0x9040c
        C_EXIT       0
