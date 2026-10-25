# O-82: a mov is an operation (O-67): it reads rs's element, zero-extended or
# truncated to rd's width. R1 holds 0x1234F678 at 32 bits; R2 is set to 16
# bits, and `mov r2, r1` truncates to the element 0xF678. `mov r3, r2` into a
# 32-bit R3 zero-extends it. Result word at 0x90000: 0x0000F678 (63096). A raw
# 32-bit copy gives 0x1234F678; a sign extension gives 0xFFFFF678.
        MOVI48     R9, 9               # result window
        MOVI48     R1, 305460856       # 0x1234F678
        C_CHWIDTH  R2, 1
        C_MOV      R2, R1
        C_MOV      R3, R2
        ST_GLOBAL  R3, R9, 0
        C_EXIT     0
