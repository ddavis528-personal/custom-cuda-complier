# The mixed-width rule (O-67): a source is its raw field, zero-extended or
# truncated to the operating width (the destination's chwidth), never
# converted. Results are words in window 9 (0x90000):
#   +0  shr, 32-bit 0x12340 into 16 bits, by 4    0x0234  (by value: 0x1234)
#   +4  min.s, 8-bit 0xFF into 32 bits, with 5    5       (by value: -1)
#   +8  FP16 add, FP32 1.0 as a source             0x3C00  (its low 16 bits are +0)
        MOVI48     R9, 9               # result window
        MOVI48     R1, 74560           # 0x12340
        C_CHWIDTH  R3, 1
        SHRI       R3, R1, 4
        C_CHWIDTH  R3, 0
        ST_GLOBAL  R3, R9, 0
        MOVI       R4, 255
        C_CHWIDTH  R4, 2
        MOVI       R5, 5
        MIN_S      R6, R4, R5, R4
        ST_GLOBAL  R6, R9, 4
        MOVI48     R7, 1065353216      # FP32 1.0, 0x3F800000
        MOVI       R8, 15360           # FP16 1.0
        C_CHWIDTH  R8, 1
        C_CHWIDTH  R10, 1
        FADD       R10, R8, R7, R8
        C_CHWIDTH  R10, 0
        ST_GLOBAL  R10, R9, 8
        C_EXIT     0
