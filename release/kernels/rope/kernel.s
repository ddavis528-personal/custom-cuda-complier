# rope: test/cuda/fusion/rope.cu, compiled; ccv-as source, reassembled byte for byte
# by tools/ccv-dis.py --check. Load at ccv-sim's -code-base; entry at offset 0.
        PMOV_IMM         P3, 1   # 0x0000
        SRD              R0, 1   # 0x0006
        ST_LOCAL         R0, 28   # 0x0008
        C_SHLI           R0, 2   # 0x000c
        MOVI             R6, 2   # 0x000e
        LD_GLOBAL_P      R1, 3, R6, 36   # 0x0012
        ADD_P            R3, 3, R1, R0, R1   # 0x0016
        SHFL_IDX         R3, 7, R3, 0   # 0x001a
        LD_GLOBAL_P      R0, 3, R6, 72   # 0x001e
        SHFL_IDX         R0, 7, R0, 0   # 0x0022
        ST_LOCAL         R0, 12   # 0x0026
        LD_GLOBAL_P      R0, 3, R6, 68   # 0x002a
        SHFL_IDX         R0, 7, R0, 0   # 0x002e
        ST_LOCAL         R0, 16   # 0x0032
        LD_GLOBAL_P      R2, 3, R6, 0   # 0x0036
        SHFL_IDX         R2, 7, R2, 0   # 0x003a
        LD_GLOBAL_SLOT   R4, 0, R3, 0, 0   # 0x003e
        LD_GLOBAL_P      R3, 3, R6, 76   # 0x0042
        SHFL_IDX         R3, 7, R3, 0   # 0x0046
        C_MUL_LO         R4, R3   # 0x004a
        C_SHRI           R3, 1   # 0x004c
        LD_GLOBAL_P      R0, 3, R6, 64   # 0x004e
        SHFL_IDX         R0, 7, R0, 0   # 0x0052
        ST_LOCAL         R0, 20   # 0x0056
        SETP_LT_NPI      P0, R8, R0, 1   # 0x005a
        BRA_PRED         0, L0114   # 0x005e
        LD_LOCAL         R0, 28   # 0x0062
        LD_LOCAL         R1, 20   # 0x0066
        MUL_LO           R10, R0, R1, R1   # 0x006a
        ADD_P            R8, 3, R3, R4, R3   # 0x006e
        SHFL_IDX         R8, 7, R8, 0   # 0x0072
        LD_LOCAL         R0, 12   # 0x0076
        MADLO_P          R9, 3, R10, R0, R3   # 0x007a
        SHFL_IDX         R9, 7, R9, 0   # 0x007e
        C_MUL_LO         R10, R0   # 0x0082
        MOVI             R11, 0   # 0x0084
        SRD              R0, 0   # 0x0088
        ST_LOCAL         R0, 24   # 0x008a
        C_BRA            L00a6   # 0x008e
L0090:  LD_LOCAL         R0, 12   # 0x0090
        C_ADD            R10, R0   # 0x0094
        C_ADD            R9, R0   # 0x0096
        C_ADDI           R11, 1   # 0x0098
        LD_LOCAL         R0, 20   # 0x009a
        SETP_EQ_NP       P0, R13, R11, R0   # 0x009e
        BRA_PRED         0, L0114   # 0x00a2
L00a6:  LD_LOCAL         R0, 24   # 0x00a6
        SETP_LE_U_NP     P0, R13, R3, R0   # 0x00aa
        C_MOV            R13, R0   # 0x00ae
        BRA_PRED         0, L0090   # 0x00b0
L00b4:  ADD              R14, R9, R13, R9   # 0x00b4
        C_SHLI           R14, 2   # 0x00b8
        ADD              R15, R10, R13, R10   # 0x00ba
        C_SHLI           R15, 2   # 0x00be
        LD_GLOBAL        R5, R6, 44   # 0x00c0
        ADD              R15, R5, R15, R5   # 0x00c4
        C_ADD            R5, R14   # 0x00c8
        ADD              R14, R4, R13, R4   # 0x00ca
        C_SHLI           R14, 2   # 0x00ce
        LD_GLOBAL        R1, R6, 60   # 0x00d0
        ADD              R14, R1, R14, R1   # 0x00d4
        ADD              R7, R8, R13, R8   # 0x00d8
        C_SHLI           R7, 2   # 0x00dc
        C_ADD            R1, R7   # 0x00de
        LD_GLOBAL_SLOT   R0, 3, R1, 0, 0   # 0x00e0
        LD_GLOBAL_SLOT   R7, 1, R5, 0, 0   # 0x00e4
        C_MOV            R1, R0   # 0x00e8
        C_FMUL           R1, R7   # 0x00ea
        FNEG_F0          R1, R1, R1, R1   # 0x00ec
        LD_GLOBAL_SLOT   R14, 3, R14, 0, 0   # 0x00f0
        LD_GLOBAL_SLOT   R12, 1, R15, 0, 0   # 0x00f4
        FFMA_ACC_F0      R1, R14, R12   # 0x00f8
        ST_GLOBAL_SLOT   R1, 1, R15, 0, 0   # 0x00fa
        C_FMUL           R14, R7   # 0x00fe
        FFMA_F0          R0, R0, R12, R14   # 0x0100
        ST_GLOBAL_SLOT   R0, 1, R5, 0, 0   # 0x0104
        C_ADD            R13, R2   # 0x0108
        SETP_LT_U_NP     P0, R0, R13, R3   # 0x010a
        BRA_PRED         0, L00b4   # 0x010e
        C_BRA            L0090   # 0x0112
L0114:  LD_LOCAL         R0, 16   # 0x0114
        SETP_LT_NPI      P0, R6, R0, 1   # 0x0118
        BRA_PRED         0, L01ce   # 0x011c
        LD_LOCAL         R0, 16   # 0x0120
        LD_LOCAL         R1, 28   # 0x0124
        MUL_LO           R7, R1, R0, R0   # 0x0128
        ADD              R5, R3, R4, R3   # 0x012c
        LD_LOCAL         R0, 12   # 0x0130
        MADLO            R6, R7, R0, R3   # 0x0134
        C_MUL_LO         R7, R0   # 0x0138
        MOVI             R8, 0   # 0x013a
        SRD              R0, 0   # 0x013e
        ST_LOCAL         R0, 20   # 0x0140
        MOVI             R10, 2   # 0x0144
        C_BRA            L0160   # 0x0148
L014a:  LD_LOCAL         R0, 12   # 0x014a
        C_ADD            R7, R0   # 0x014e
        C_ADD            R6, R0   # 0x0150
        C_ADDI           R8, 1   # 0x0152
        LD_LOCAL         R0, 16   # 0x0154
        SETP_EQ_NP       P0, R0, R8, R0   # 0x0158
        BRA_PRED         0, L01ce   # 0x015c
L0160:  LD_LOCAL         R11, 20   # 0x0160
        SETP_LE_U_NP     P0, R0, R3, R11   # 0x0164
        BRA_PRED         0, L014a   # 0x0168
L016c:  ADD              R0, R6, R11, R6   # 0x016c
        C_SHLI           R0, 2   # 0x0170
        ADD              R1, R7, R11, R7   # 0x0172
        C_SHLI           R1, 2   # 0x0176
        LD_GLOBAL        R12, R10, 52   # 0x0178
        ADD              R1, R12, R1, R12   # 0x017c
        ADD              R0, R12, R0, R12   # 0x0180
        ADD              R12, R4, R11, R4   # 0x0184
        C_SHLI           R12, 2   # 0x0188
        LD_GLOBAL        R13, R10, 60   # 0x018a
        ADD              R12, R13, R12, R13   # 0x018e
        ADD              R14, R5, R11, R5   # 0x0192
        C_SHLI           R14, 2   # 0x0196
        C_ADD            R13, R14   # 0x0198
        LD_GLOBAL_SLOT   R13, 3, R13, 0, 0   # 0x019a
        LD_GLOBAL_SLOT   R14, 2, R0, 0, 0   # 0x019e
        C_MOV            R15, R13   # 0x01a2
        C_FMUL           R15, R14   # 0x01a4
        FNEG_F0          R15, R15, R15, R15   # 0x01a6
        LD_GLOBAL_SLOT   R12, 3, R12, 0, 0   # 0x01aa
        LD_GLOBAL_SLOT   R9, 2, R1, 0, 0   # 0x01ae
        FFMA_ACC_F0      R15, R12, R9   # 0x01b2
        ST_GLOBAL_SLOT   R15, 2, R1, 0, 0   # 0x01b4
        C_FMUL           R12, R14   # 0x01b8
        FFMA_F0          R1, R13, R9, R12   # 0x01ba
        ST_GLOBAL_SLOT   R1, 2, R0, 0, 0   # 0x01be
        C_ADD            R11, R2   # 0x01c2
        SETP_LT_U_NP     P0, R0, R11, R3   # 0x01c4
        BRA_PRED         0, L016c   # 0x01c8
        C_BRA            L014a   # 0x01cc
L01ce:  C_EXIT           0   # 0x01ce
