# Does por Pd, !Pd, Pd give all-ones when Pd already holds a MIXED mask?
# That is the in-loop case: the first compare leaves a partial mask behind.
        POR        P0, 4, 0             # P0 = all ones
        MOVI48     R0, 2
        SRD        R1, 0                # lane index 0..31
        LD_GLOBAL  R2, R0, 0            # threshold = 16
        SETP_LT    P0, R15, 0, R1, R2   # P0 = 0x0000ffff  (mixed)
        POR        P0, 4, 0             # re-materialise from a NONZERO P0
        MOVI48     R3, 5                # c.rbase
        MOVI48     R4, 99
        SETP_LT    P1, R15, 0, R1, R2   # @P0 again -- if P0 is all ones, all
                                        # 32 lanes execute and all 32 store
        ST_GLOBAL_IDX R4, R3, R1, 1, 0
        C_EXIT     0
