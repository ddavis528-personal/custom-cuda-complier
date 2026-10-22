# F-RO covers an access any byte of which is read-only (§12, 94e76e8). With
# -const-range 0x50000:0x50006, a 4-byte store at 0x50004 starts inside the
# range and ends past it. Expect FAULT F-RO, every lane, at 0x50004.
        MOVI48        R3, 5
        MOVI          R4, 77
        ST_GLOBAL     R4, R3, 4
        C_EXIT        0
