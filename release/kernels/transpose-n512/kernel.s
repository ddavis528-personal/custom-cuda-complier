# transpose-n512: test/cuda/transpose32.cu -DROWS=1, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        PMOV_IMM         P3, 1   # 0x0000
        MOVI             R0, 2   # 0x0006
        LD_GLOBAL_P      R0, 3, R0, 48   # 0x000a
        SHFL_IDX         R0, 7, R0, 0   # 0x000e
        C_MOV            R1, R0   # 0x0012
        C_SHRI           R1, 5   # 0x0014
        RCP_U32          R2, R1, R1, R1   # 0x0016
        MUL_LO           R3, R2, R1, R1   # 0x001a
        C_NEG            R3, R3   # 0x001e
        MUL_HI_U_P       R3, 3, R2, R3, R2   # 0x0020
        ADD_P            R2, 3, R2, R3, R2   # 0x0024
        SRD              R3, 1   # 0x0028
        MUL_HI_U_P       R2, 3, R3, R2, R3   # 0x002a
        SHFL_IDX         R2, 7, R2, 0   # 0x002e
        MUL_LO           R4, R2, R1, R1   # 0x0032
        SUB_P            R4, 3, R3, R4, R3   # 0x0036
        SHFL_IDX         R4, 7, R4, 0   # 0x003a
        SETP_LE_U_NP     P0, R5, R1, R4   # 0x003e
        ADDI_P           R5, 3, R2, 1   # 0x0042
        PAND             P0, 0, 3   # 0x0046
        MOV_P            R2, 0, R5, R5, R5   # 0x0048
        SUB_P            R5, 3, R4, R1, R4   # 0x004c
        MOV_P            R4, 0, R5, R5, R5   # 0x0050
        SHFL_IDX         R4, 7, R4, 0   # 0x0054
        SETP_LE_U_NP     P0, R4, R1, R4   # 0x0058
        ADDI_P           R4, 3, R2, 1   # 0x005c
        PAND             P0, 0, 3   # 0x0060
        MOV_P            R2, 0, R4, R4, R4   # 0x0062
        SHFL_IDX         R2, 7, R2, 0   # 0x0066
        MUL_LO           R1, R2, R1, R1   # 0x006a
        ST_LOCAL         R3, 16   # 0x006e
        ST_LOCAL         R1, 20   # 0x0072
        SUB_P            R6, 3, R3, R1, R3   # 0x0076
        SHFL_IDX         R6, 7, R6, 0   # 0x007a
        SRD              R7, 0   # 0x007e
        C_MOV            R5, R7   # 0x0080
        C_SHRI           R5, 5   # 0x0082
        MOVI             R1, 1023   # 0x0084
        SETP_LT_U_NP     P0, R1, R1, R7   # 0x0088
        ANDI             R1, R7, 31   # 0x008c
        C_SHLI           R6, 5   # 0x0090
        C_SHLI           R2, 5   # 0x0092
        ANDI             R3, R7, 32   # 0x0094
        ST_LOCAL         R3, 12   # 0x0098
        BRA_PRED         0, L0146   # 0x009c
        LD_LOCAL         R3, 12   # 0x00a0
        SETP_EQ_NPI      P0, R8, R3, 0   # 0x00a4
        C_MOV            R10, R5   # 0x00a8
        BRA_PRED         0, L00d6   # 0x00aa
        OR               R8, R6, R1, R6   # 0x00ae
        OR               R10, R5, R2, R5   # 0x00b2
        MAD_ACC          R8, R10, R0   # 0x00b6
        C_SHLI           R8, 2   # 0x00b8
        MOVI             R10, 2   # 0x00ba
        LD_GLOBAL        R10, R10, 44   # 0x00be
        ADD              R8, R10, R8, R10   # 0x00c2
        LD_GLOBAL_SLOT   R8, 1, R8, 0, 0   # 0x00c6
        MULI             R10, R5, 132   # 0x00ca
        ST_SHARED_IDX    R8, R10, R1, 1, 0   # 0x00ce
        ADDI             R10, R5, 1   # 0x00d2
L00d6:  SETP_EQ_NPI      P0, R8, R5, 31   # 0x00d6
        BRA_PRED         0, L0146   # 0x00da
        LD_LOCAL         R8, 16   # 0x00de
        C_SHLI           R8, 5   # 0x00e2
        C_OR             R8, R1   # 0x00e4
        LD_LOCAL         R11, 20   # 0x00e6
        C_SHLI           R11, 5   # 0x00ea
        SUB              R11, R8, R11, R8   # 0x00ec
        ADD              R8, R10, R2, R10   # 0x00f0
        MUL_LO           R12, R0, R8, R8   # 0x00f4
        C_ADDI           R8, 1   # 0x00f8
        MUL_LO           R13, R0, R8, R8   # 0x00fa
        C_MOV            R14, R0   # 0x00fe
        C_SHLI           R14, 1   # 0x0100
        MOVI             R15, 2   # 0x0102
        MOVI             R8, 132   # 0x0106
L010a:  ADD              R9, R12, R11, R12   # 0x010a
        C_SHLI           R9, 2   # 0x010e
        LD_GLOBAL        R4, R15, 44   # 0x0110
        ADD              R9, R4, R9, R4   # 0x0114
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x0118
        MULI             R3, R10, 132   # 0x011c
        ST_SHARED_IDX    R9, R3, R1, 1, 0   # 0x0120
        C_MOV            R3, R1   # 0x0124
        C_SHLI           R3, 2   # 0x0126
        MAD_ACC          R3, R10, R8   # 0x0128
        ADD              R9, R13, R11, R13   # 0x012a
        C_SHLI           R9, 2   # 0x012e
        C_ADD            R4, R9   # 0x0130
        LD_GLOBAL_SLOT   R4, 1, R4, 0, 0   # 0x0132
        ST_SHARED        R4, R3, 132   # 0x0136
        C_ADD            R11, R14   # 0x013a
        C_ADDI           R10, 2   # 0x013c
        SETP_EQ_NPI      P0, R3, R10, 32   # 0x013e
        BRA_PRED         4, L010a   # 0x0142
L0146:  MOVI             R3, 1023   # 0x0146
        SETP_LT_U_NP     P0, R7, R3, R7   # 0x014a
        C_BAR_ARRIVE     0   # 0x014e
        C_BAR_WAIT       0   # 0x0150
        BRA_PRED         0, L01fa   # 0x0152
        LD_LOCAL         R3, 12   # 0x0156
        SETP_EQ_NPI      P0, R7, R3, 0   # 0x015a
        MULI             R7, R1, 132   # 0x015e
        C_MOV            R8, R5   # 0x0162
        BRA_PRED         0, L018e   # 0x0164
        OR               R8, R2, R1, R2   # 0x0168
        OR               R6, R5, R6, R5   # 0x016c
        MADLO            R6, R6, R0, R8   # 0x0170
        C_SHLI           R6, 2   # 0x0174
        MOVI             R8, 2   # 0x0176
        LD_GLOBAL        R8, R8, 36   # 0x017a
        ADD              R6, R8, R6, R8   # 0x017e
        LD_SHARED_IDX    R8, R7, R5, 1, 0   # 0x0182
        ST_GLOBAL_SLOT   R8, 0, R6, 0, 0   # 0x0186
        ADDI             R8, R5, 1   # 0x018a
L018e:  SETP_EQ_NPI      P0, R5, R5, 31   # 0x018e
        BRA_PRED         0, L01fa   # 0x0192
        LD_LOCAL         R3, 16   # 0x0196
        C_SHLI           R3, 5   # 0x019a
        ADD              R3, R8, R3, R8   # 0x019c
        LD_LOCAL         R4, 20   # 0x01a0
        C_SHLI           R4, 5   # 0x01a4
        SUB              R4, R3, R4, R3   # 0x01a6
        C_ADD            R2, R1   # 0x01aa
        MUL_LO           R3, R0, R4, R4   # 0x01ac
        C_ADDI           R4, 1   # 0x01b0
        MUL_LO           R4, R0, R4, R4   # 0x01b2
        C_SHLI           R0, 1   # 0x01b6
        MOVI             R5, 2   # 0x01b8
        MOVI             R6, 132   # 0x01bc
L01c0:  LD_SHARED_IDX    R9, R7, R8, 1, 0   # 0x01c0
        ADD              R10, R3, R2, R3   # 0x01c4
        C_SHLI           R10, 2   # 0x01c8
        LD_GLOBAL        R11, R5, 36   # 0x01ca
        ADD              R10, R11, R10, R11   # 0x01ce
        ST_GLOBAL_SLOT   R9, 0, R10, 0, 0   # 0x01d2
        C_MOV            R9, R8   # 0x01d6
        C_SHLI           R9, 2   # 0x01d8
        MAD_ACC          R9, R1, R6   # 0x01da
        ADD              R10, R4, R2, R4   # 0x01dc
        C_SHLI           R10, 2   # 0x01e0
        ADD              R10, R11, R10, R11   # 0x01e2
        LD_SHARED        R9, R9, 4   # 0x01e6
        ST_GLOBAL_SLOT   R9, 0, R10, 0, 0   # 0x01ea
        C_ADD            R2, R0   # 0x01ee
        C_ADDI           R8, 2   # 0x01f0
        SETP_EQ_NPI      P0, R9, R8, 32   # 0x01f2
        BRA_PRED         4, L01c0   # 0x01f6
L01fa:  C_EXIT           0   # 0x01fa
