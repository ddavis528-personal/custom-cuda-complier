# O-79: a narrow address register contributes only its element, zero-extended.
# R3 holds 0x704 and is narrowed to 8 bits, then used as its own load's index,
# the idiom O-39 allowed (F-198). The index is 0x04, so the byte comes from
# 0x80004 (poked 0x11), not 0x80704 (poked 0x22). Result word at 0x90000.
        MOVI48     R9, 9               # result window
        MOVI48     R2, 8               # table window
        MOVI       R3, 1796            # 0x704
        C_CHWIDTH  R3, 2
        LD_GLOBAL_IDX R3, R2, R3, 0, 0
        C_CHWIDTH  R3, 0
        ST_GLOBAL  R3, R9, 0
        C_EXIT     0
