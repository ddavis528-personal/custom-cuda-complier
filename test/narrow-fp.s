# Narrow FP executed (CP-6): each form once, through a real kernel, so the
# operand positions, widths, predication and compressed forms are the step
# function's and not only the library's (tools/check-narrow-fp.py covers the
# arithmetic exhaustively). Results are widened -- zero-extended, O-38 -- and
# stored as words in window 9 (0x90000):
#   +0   E4M3  1.0 + 0.5          0x3C
#   +4   E5M2  0.5 + 0.125        0x39   (format code 1)
#   +8   E2M1  6 x 6              0x7    (saturated to max finite, O-56)
#   +12  FP16  ffma 1 x 2 + 1     0x4200
#   +16  FP32 500.0 to E4M3       0x7E   (448, saturated, O-53)
#   +20  E4M3  compressed fadd    0x3C
#   +24  BF16  ffma.acc 2 x 3 + 1 0x40E0
#   +64 + 4l   predicated E4M3 fadd: lanes 0-15 0x3C, 16-31 keep 0x11
        MOVI48     R9, 9               # result window
        MOVI       R1, 56              # 0x38
        MOVI       R2, 48              # 0x30
        C_CHWIDTH  R1, 2
        C_CHWIDTH  R2, 2
        C_CHWIDTH  R3, 2
        FADD       R3, R1, R2, R1      # E4M3
        C_CHWIDTH  R3, 0
        ST_GLOBAL  R3, R9, 0
        C_CHWIDTH  R3, 2
        FADD_F1    R3, R1, R2, R1      # E5M2: the same bits, the other format
        C_CHWIDTH  R3, 0
        ST_GLOBAL  R3, R9, 4
        MOVI       R4, 7               # E2M1 6.0
        C_CHWIDTH  R4, 3
        C_CHWIDTH  R5, 3
        FMUL       R5, R4, R4, R4
        C_CHWIDTH  R5, 0
        ST_GLOBAL  R5, R9, 8
        C_CHWIDTH  R4, 0               # widen before reuse: a write lands
        C_CHWIDTH  R5, 0               # only in the element
        MOVI       R4, 15360           # FP16 1.0
        MOVI       R5, 16384           # FP16 2.0
        C_CHWIDTH  R4, 1
        C_CHWIDTH  R5, 1
        C_CHWIDTH  R6, 1
        FFMA_F0    R6, R4, R5, R4      # 1 x 2 + 1
        C_CHWIDTH  R6, 0
        ST_GLOBAL  R6, R9, 12
        C_CHWIDTH  R4, 0
        MOVI48     R4, 1140457472      # FP32 500.0 = 0x43FA0000
        C_CHWIDTH  R6, 2
        CVT_D0_S0_R0 R6, R4, R4, R4    # to E4M3 at R6's width
        C_CHWIDTH  R6, 0
        ST_GLOBAL  R6, R9, 16
        C_FADD     R1, R2              # R1 = R1 + R2, both 8-bit
        C_CHWIDTH  R1, 0
        ST_GLOBAL  R1, R9, 20
        C_CHWIDTH  R5, 0
        MOVI       R4, 16256           # BF16 1.0
        MOVI       R5, 16384           # BF16 2.0
        MOVI       R6, 16448           # BF16 3.0
        C_CHWIDTH  R4, 1
        C_CHWIDTH  R5, 1
        C_CHWIDTH  R6, 1
        FFMA_ACC_F1 R4, R5, R6         # R4 = R5 x R6 + R4
        C_CHWIDTH  R4, 0
        ST_GLOBAL  R4, R9, 24
        SRD        R8, 0               # lane
        SETP_LT_NPI P0, R14, R8, 16    # lanes 0-15
        MOVI       R1, 56
        C_CHWIDTH  R1, 2
        MOVI       R3, 17              # 0x11
        C_CHWIDTH  R3, 2
        FADD_P     R3, 0, R1, R2, R1   # lanes 0-15 only
        C_CHWIDTH  R3, 0
        ST_GLOBAL_IDX R3, R9, R8, 1, 64
        C_EXIT     0
