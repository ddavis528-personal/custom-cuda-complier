# Execute-stage faults are predicate-gated (§12.2). Every lane's address is
# misaligned (offset 1), but P0 is false in every lane, so nothing faults and
# the kernel runs to its end. The control, gated-on.s, sets P0 in every lane.
        SRD          R1, 0
        MOVI48       R3, 5
        SETP_LT_NPI  P0, R14, R1, 0     # i < 0: false everywhere
        LD_GLOBAL_P  R4, 0, R3, 1
        C_EXIT       0
