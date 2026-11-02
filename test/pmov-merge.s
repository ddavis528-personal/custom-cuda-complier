# pmov #lanemask under divergence (RA-19; invariant 10, O-62): only the issuing
# group's lanes take the immediate's bits. Lanes 0-15 branch apart from 16-31,
# set P1 to a constant, and P1 is stored after the join.
# Expected, in window 9:
#   0x90040  P1 afterwards: lanes 16-31 kept their ones, 0-15 took 0x5555
#            0xffff5555
# An ungated pmov (-ccv-test-pmov-all-lanes) gives 0x00005555.
        SRD          R1, 0              # lane index
        MOVI48       R3, 9              # frame window, warp-uniform
        SETP_LT_NPI  P0, R14, R1, 16    # lanes 0-15
        POR          P1, 5, 1           # P1 = !P1 | P1: all ones
        BRA_PRED     4, join            # lanes 16-31 skip the pmov
        PMOV_IMM     P1, 0x5555         # lanes 0-15 only
join:   ST_PRED_G    2, R3, 60          # P1 out to 0x90040
        C_EXIT       0
