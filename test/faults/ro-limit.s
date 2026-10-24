# The control for ro-straddle: a 2-byte store starting AT the limit, 0x50006,
# is outside [0x50000, 0x50006) and must not fault. It lands in the high half
# of the word at 0x50004.
        MOVI48        R3, 5
        MOVI          R4, 77
        C_CHWIDTH     R4, 1
        ST_GLOBAL     R4, R3, 6
        C_EXIT        0
