# The canonical NaN (O-66) and the FP compare's format bit (O-65), executed.
# Results are words in window 9 (0x90000):
#   +0   FP32 inf + -inf              0x7FFFFFFF  (not x86's 0xFFC00000)
#   +4   FP16 inf + -inf              0x7FFF      (widened, O-38)
#   +8   compare bits: 0x7E is a NaN in E5M2 and 448 in E4M3
#          setp.eq.f1 x, x  false     +0
#          setp.eq.f  x, x  true      +2
#          @P1 setp.ne.f1 x, x  true  +4          = 6
        MOVI48     R9, 9               # result window
        MOVI48     R1, 2139095040      # FP32 +inf, 0x7F800000
        FNEG_F0    R2, R1, R1, R1      # -inf
        FADD       R3, R1, R2, R1
        ST_GLOBAL  R3, R9, 0
        MOVI       R1, 31744           # FP16 +inf, 0x7C00
        C_CHWIDTH  R1, 1
        C_CHWIDTH  R2, 1
        C_CHWIDTH  R3, 1
        FNEG_F0    R2, R1, R1, R1
        FADD       R3, R1, R2, R1
        C_CHWIDTH  R3, 0
        ST_GLOBAL  R3, R9, 4
        MOVI       R4, 126             # 0x7E
        C_CHWIDTH  R4, 2
        MOVI       R5, 0
        SETP_EQ_F1_NP P0, R6, R4, R4   # E5M2: NaN, unordered
        ADDI_P     R5, 0, R5, 1
        SETP_EQ_F_NP  P1, R6, R4, R4   # E4M3: 448 == 448
        ADDI_P     R5, 1, R5, 2
        SETP_NE_F1 P0, R6, 1, R4, R4   # @P1, E5M2: ne.f is true on a NaN
        ADDI_P     R5, 0, R5, 4
        ST_GLOBAL  R5, R9, 8
        C_EXIT     0
