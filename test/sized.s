# O-80: the sized loads and stores. Window 8 holds bytes FF F0 81 80 at
# 0x80000 (poked as one word); results are words in window 9 (0x90000).
#   +0   ld.global.u8   byte 0                      255
#   +4   ld.global.s8   byte 0                      0xFFFFFFFF
#   +8   ld.global.u16  bytes 2-3                   0x8081
#   +12  ld.global.s16  bytes 2-3                   0xFFFF8081
#   +16  st.global.8    0x12345678 over 0xAAAAAAAA  0xAAAAAA78
#   +20  st.global.16   the same                    0xAAAA5678
#   +24  st.shared.16, ld.shared.s16                0x5678
#   +28  ld.shared.u8 of the byte above             0x56
#   +32  ld.global.u16, index 1 scaled by 2         0x8081
#   +36  ld.global.s8 into a 16-bit rdata, widened  0xFFFF
        MOVI48     R9, 9               # result window
        MOVI48     R2, 8               # table window
        MOVI       R4, 0
        MOVI       R6, 2
        SZ_GLOBAL_LD_U8  R1, R2, R4, 0, 0
        ST_GLOBAL  R1, R9, 0
        SZ_GLOBAL_LD_S8  R1, R2, R4, 0, 0
        ST_GLOBAL  R1, R9, 4
        SZ_GLOBAL_LD_U16 R1, R2, R6, 0, 0
        ST_GLOBAL  R1, R9, 8
        SZ_GLOBAL_LD_S16 R1, R2, R6, 0, 0
        ST_GLOBAL  R1, R9, 12
        MOVI48     R5, 305419896       # 0x12345678
        MOVI       R3, 16
        SZ_GLOBAL_ST_8   R5, R9, R3, 0, 0
        MOVI       R3, 20
        SZ_GLOBAL_ST_16  R5, R9, R3, 0, 0
        MOVI       R3, 32
        SZ_SHARED_ST_16  R5, R4, R3, 0, 0
        SZ_SHARED_LD_S16 R1, R4, R3, 0, 0
        ST_GLOBAL  R1, R9, 24
        SZ_SHARED_LD_U8  R1, R4, R3, 0, 1
        ST_GLOBAL  R1, R9, 28
        MOVI       R3, 1
        SZ_GLOBAL_LD_U16 R1, R2, R3, 1, 0
        ST_GLOBAL  R1, R9, 32
        C_CHWIDTH  R7, 1
        SZ_GLOBAL_LD_S8  R7, R2, R4, 0, 0
        C_CHWIDTH  R7, 0
        ST_GLOBAL  R7, R9, 36
        C_EXIT     0
