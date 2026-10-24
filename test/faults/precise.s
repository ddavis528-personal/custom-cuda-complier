# F-ALIGN is precise (ISA v1.9 §12.4): odd lanes store to 4i+1, even lanes to
# 4i. The odd lanes fault, so the instruction has no architectural effect --
# even lane 0's aligned store must not land. Expect FAULT F-ALIGN with lanes
# 0xaaaaaaaa at 0x50005 (lane 1, the lowest), and [0x50000] still poisoned.
        SRD          R1, 0
        SHLI         R2, R1, 2
        ANDI         R5, R1, 1
        ADD          R2, R2, R5, R2
        MOVI48       R3, 5
        MOVI         R4, 77
        ST_GLOBAL_IDX R4, R3, R2, 0, 0
        C_EXIT       0
