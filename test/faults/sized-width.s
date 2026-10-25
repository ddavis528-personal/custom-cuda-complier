# O-80: a sized transfer wider than rdata's element raises F-WIDTH at dispatch.
# R7 is at 8 bits and ld.global.u16 moves two bytes into it.
        MOVI48     R2, 8
        MOVI       R4, 0
        C_CHWIDTH  R7, 2
        SZ_GLOBAL_LD_U16 R7, R2, R4, 0, 0
        C_EXIT     0
