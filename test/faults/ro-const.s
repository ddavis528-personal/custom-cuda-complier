# F-RO (O-51, O-61): a store into the .const range, run with -const-range
# 0x50000:0x50006. Lane i stores to 0x50000 + 8i, so only lane 0's address is
# read-only. Expect FAULT F-RO, lanes 0x00000001 at 0x50000, and precision:
# lane 1's store to 0x50008, outside the range, must not land either.
        SRD           R1, 0
        SHLI          R2, R1, 3
        MOVI48        R3, 5
        MOVI          R4, 77
        ST_GLOBAL_IDX R4, R3, R2, 0, 0
        C_EXIT        0
