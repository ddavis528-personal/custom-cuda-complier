# O-83: an interleaved access whose logical byte b is at or above L raises
# F-ADDR. Run as test/priv.s is, with -priv-windows 1, so L = 64 KiB: the
# store is at b = 65536.
        MOVI         R2, 2
        LD_GLOBAL    R3, R2, 24         # local_base
        SRD          R4, 3              # %privoff
        ADD          R5, R3, R4, R3     # W
        MOVI48       R8, 65536
        ST_GLOBAL_IDX R1, R5, R8, 0, 0
        C_EXIT       0
