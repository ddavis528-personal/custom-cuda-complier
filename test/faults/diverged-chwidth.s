# O-81: a chwidth from a diverged warp raises F-WIDTH at dispatch. Lanes 16-31
# branch past it, so lanes 0-15 issue the chwidth alone: issue mask 0x0000ffff
# against live lanes 0xffffffff. A converged chwidth before the branch is fine.
# Under -ccv-test-diverged-chwidth the run completes.
        SRD          R1, 0              # lane index
        C_CHWIDTH    R5, 1              # converged: every lane
        C_CHWIDTH    R5, 0
        SETP_LT_NPI  P0, R14, R1, 16    # lanes 0-15
        BRA_PRED     4, join            # lanes 16-31 skip it
        C_CHWIDTH    R6, 1              # diverged
        C_CHWIDTH    R6, 0
join:   C_EXIT       0
