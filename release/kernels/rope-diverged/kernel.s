# rope-diverged: test/cuda/fusion/rope.cu, compiled; ccv-as source, reassembled byte for byte
# by tools/ccv-dis.py --check. Load at ccv-sim's -code-base; entry at offset 0.
        MOVI             R15, 2   # 0x0000
        LD_GLOBAL        R15, R15, 24   # 0x0004
        SRD              R14, 2   # 0x0008
        C_ADD            R15, R14   # 0x000a
        PMOV_IMM         P3, 1   # 0x000c
        SRD              R0, 1   # 0x0012
        ST_GLOBAL        R0, R15, -24   # 0x0014
        C_SHLI           R0, 2   # 0x0018
        MOVI             R6, 2   # 0x001a
        LD_GLOBAL_P      R1, 3, R6, 36   # 0x001e
        ADD_P            R3, 3, R1, R0, R1   # 0x0022
        SHFL_IDX         R3, 7, R3, 0   # 0x0026
        LD_GLOBAL_P      R0, 3, R6, 72   # 0x002a
        SHFL_IDX         R0, 7, R0, 0   # 0x002e
        ST_GLOBAL        R0, R15, -4   # 0x0032
        LD_GLOBAL_P      R0, 3, R6, 68   # 0x0036
        SHFL_IDX         R0, 7, R0, 0   # 0x003a
        ST_GLOBAL        R0, R15, -12   # 0x003e
        LD_GLOBAL_P      R2, 3, R6, 0   # 0x0042
        SHFL_IDX         R2, 7, R2, 0   # 0x0046
        LD_GLOBAL_SLOT   R4, 0, R3, 0, 0   # 0x004a
        LD_GLOBAL_P      R3, 3, R6, 76   # 0x004e
        SHFL_IDX         R3, 7, R3, 0   # 0x0052
        C_MUL_LO         R4, R3   # 0x0056
        C_SHRI           R3, 1   # 0x0058
        LD_GLOBAL_P      R0, 3, R6, 64   # 0x005a
        SHFL_IDX         R0, 7, R0, 0   # 0x005e
        ST_GLOBAL        R0, R15, -16   # 0x0062
        SETP_LT_NPI      P0, R8, R0, 1   # 0x0066
        BRA_PRED         0, L012a   # 0x006a
        LD_GLOBAL        R0, R15, -24   # 0x006e
        LD_GLOBAL        R1, R15, -16   # 0x0072
        MUL_LO           R10, R0, R1, R1   # 0x0076
        ADD_P            R8, 3, R3, R4, R3   # 0x007a
        SHFL_IDX         R8, 7, R8, 0   # 0x007e
        LD_GLOBAL        R0, R15, -4   # 0x0082
        MADLO_P          R9, 3, R10, R0, R3   # 0x0086
        SHFL_IDX         R9, 7, R9, 0   # 0x008a
        C_MUL_LO         R10, R0   # 0x008e
        MOVI             R1, 0   # 0x0090
        SRD              R0, 0   # 0x0094
        ST_GLOBAL        R0, R15, -20   # 0x0096
        C_BRA            L00b6   # 0x009a
L009c:  LD_GLOBAL        R0, R15, -4   # 0x009c
        C_ADD            R10, R0   # 0x00a0
        C_ADD            R9, R0   # 0x00a2
        LD_GLOBAL        R1, R15, -8   # 0x00a4
        C_ADDI           R1, 1   # 0x00a8
        LD_GLOBAL        R0, R15, -16   # 0x00aa
        SETP_EQ_NP       P0, R13, R1, R0   # 0x00ae
        BRA_PRED         0, L012a   # 0x00b2
L00b6:  ST_GLOBAL        R1, R15, -8   # 0x00b6
        LD_GLOBAL        R0, R15, -20   # 0x00ba
        SETP_LE_U_NP     P0, R13, R3, R0   # 0x00be
        C_MOV            R13, R0   # 0x00c2
        BRA_PRED         0, L009c   # 0x00c4
L00c8:  ADD              R14, R9, R13, R9   # 0x00c8
        C_SHLI           R14, 2   # 0x00cc
        ADD              R5, R10, R13, R10   # 0x00ce
        C_SHLI           R5, 2   # 0x00d2
        LD_GLOBAL        R1, R6, 44   # 0x00d4
        ADD              R5, R1, R5, R1   # 0x00d8
        C_ADD            R1, R14   # 0x00dc
        ADD              R14, R4, R13, R4   # 0x00de
        C_SHLI           R14, 2   # 0x00e2
        LD_GLOBAL        R7, R6, 60   # 0x00e4
        ADD              R14, R7, R14, R7   # 0x00e8
        ADD              R0, R8, R13, R8   # 0x00ec
        C_SHLI           R0, 2   # 0x00f0
        ADD              R0, R7, R0, R7   # 0x00f2
        LD_GLOBAL_SLOT   R12, 3, R0, 0, 0   # 0x00f6
        LD_GLOBAL_SLOT   R7, 1, R1, 0, 0   # 0x00fa
        C_MOV            R0, R12   # 0x00fe
        C_FMUL           R0, R7   # 0x0100
        FNEG_F0          R0, R0, R0, R0   # 0x0102
        LD_GLOBAL_SLOT   R14, 3, R14, 0, 0   # 0x0106
        LD_GLOBAL_SLOT   R11, 1, R5, 0, 0   # 0x010a
        FFMA_ACC_F0      R0, R14, R11   # 0x010e
        ST_GLOBAL_SLOT   R0, 1, R5, 0, 0   # 0x0110
        C_FMUL           R14, R7   # 0x0114
        FFMA_F0          R0, R12, R11, R14   # 0x0116
        ST_GLOBAL_SLOT   R0, 1, R1, 0, 0   # 0x011a
        C_ADD            R13, R2   # 0x011e
        SETP_LT_U_NP     P0, R0, R13, R3   # 0x0120
        BRA_PRED         0, L00c8   # 0x0124
        C_BRA            L009c   # 0x0128
L012a:  LD_GLOBAL        R0, R15, -12   # 0x012a
        SETP_LT_NPI      P0, R6, R0, 1   # 0x012e
        BRA_PRED         0, L01ec   # 0x0132
        LD_GLOBAL        R0, R15, -12   # 0x0136
        LD_GLOBAL        R1, R15, -24   # 0x013a
        MUL_LO           R7, R1, R0, R0   # 0x013e
        ADD              R5, R3, R4, R3   # 0x0142
        LD_GLOBAL        R0, R15, -4   # 0x0146
        MADLO            R6, R7, R0, R3   # 0x014a
        C_MUL_LO         R7, R0   # 0x014e
        MOVI             R1, 0   # 0x0150
        SRD              R0, 0   # 0x0154
        ST_GLOBAL        R0, R15, -16   # 0x0156
        MOVI             R10, 2   # 0x015a
        C_BRA            L017a   # 0x015e
L0160:  LD_GLOBAL        R0, R15, -4   # 0x0160
        C_ADD            R7, R0   # 0x0164
        C_ADD            R6, R0   # 0x0166
        LD_GLOBAL        R1, R15, -8   # 0x0168
        C_ADDI           R1, 1   # 0x016c
        LD_GLOBAL        R0, R15, -12   # 0x016e
        SETP_EQ_NP       P0, R0, R1, R0   # 0x0172
        BRA_PRED         0, L01ec   # 0x0176
L017a:  ST_GLOBAL        R1, R15, -8   # 0x017a
        LD_GLOBAL        R11, R15, -16   # 0x017e
        SETP_LE_U_NP     P0, R0, R3, R11   # 0x0182
        BRA_PRED         0, L0160   # 0x0186
L018a:  ADD              R0, R6, R11, R6   # 0x018a
        C_SHLI           R0, 2   # 0x018e
        ADD              R1, R7, R11, R7   # 0x0190
        C_SHLI           R1, 2   # 0x0194
        LD_GLOBAL        R12, R10, 52   # 0x0196
        ADD              R1, R12, R1, R12   # 0x019a
        ADD              R0, R12, R0, R12   # 0x019e
        ADD              R12, R4, R11, R4   # 0x01a2
        C_SHLI           R12, 2   # 0x01a6
        LD_GLOBAL        R13, R10, 60   # 0x01a8
        ADD              R12, R13, R12, R13   # 0x01ac
        ADD              R14, R5, R11, R5   # 0x01b0
        C_SHLI           R14, 2   # 0x01b4
        C_ADD            R13, R14   # 0x01b6
        LD_GLOBAL_SLOT   R9, 3, R13, 0, 0   # 0x01b8
        LD_GLOBAL_SLOT   R14, 2, R0, 0, 0   # 0x01bc
        C_MOV            R13, R9   # 0x01c0
        C_FMUL           R13, R14   # 0x01c2
        FNEG_F0          R13, R13, R13, R13   # 0x01c4
        LD_GLOBAL_SLOT   R12, 3, R12, 0, 0   # 0x01c8
        LD_GLOBAL_SLOT   R8, 2, R1, 0, 0   # 0x01cc
        FFMA_ACC_F0      R13, R12, R8   # 0x01d0
        ST_GLOBAL_SLOT   R13, 2, R1, 0, 0   # 0x01d2
        C_FMUL           R12, R14   # 0x01d6
        FFMA_F0          R1, R9, R8, R12   # 0x01d8
        ST_GLOBAL_SLOT   R1, 2, R0, 0, 0   # 0x01dc
        C_ADD            R11, R2   # 0x01e0
        SETP_LT_U_NP     P0, R0, R11, R3   # 0x01e2
        BRA_PRED         0, L018a   # 0x01e6
        C_BRA            L0160   # 0x01ea
L01ec:  C_EXIT           0   # 0x01ec
