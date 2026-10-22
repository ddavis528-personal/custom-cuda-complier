# layernorm: test/cuda/fusion/layernorm.cu, compiled; ccv-as source, reassembled byte for byte
# by tools/ccv-dis.py --check. Load at ccv-sim's -code-base; entry at offset 0.
        PMOV_IMM         P3, 1   # 0x0000
        MOVI             R6, 0   # 0x0006
        SRD              R4, 1   # 0x000a
        MOVI             R7, 2   # 0x000c
        LD_GLOBAL_P      R0, 3, R7, 84   # 0x0010
        SHFL_IDX         R0, 7, R0, 0   # 0x0014
        MUL_LO           R1, R4, R0, R0   # 0x0018
        SRD              R2, 0   # 0x001c
        SETP_LE_U_NP     P0, R3, R0, R2   # 0x001e
        LD_GLOBAL_P      R5, 3, R7, 80   # 0x0022
        SHFL_IDX         R5, 7, R5, 0   # 0x0026
        LD_GLOBAL_P      R3, 3, R7, 0   # 0x002a
        SHFL_IDX         R3, 7, R3, 0   # 0x002e
        MOVI             R8, 0   # 0x0032
        BRA_PRED         0, L005c   # 0x0036
        C_MOV            R9, R2   # 0x003a
L003c:  ADD              R10, R1, R9, R1   # 0x003c
        C_SHLI           R10, 2   # 0x0040
        LD_GLOBAL        R11, R7, 60   # 0x0042
        ADD              R10, R11, R10, R11   # 0x0046
        LD_GLOBAL_SLOT   R10, 3, R10, 0, 0   # 0x004a
        FFMA_ACC_F0      R6, R10, R10   # 0x004e
        C_FADD           R8, R10   # 0x0050
        C_ADD            R9, R3   # 0x0052
        SETP_LT_U_NP     P0, R10, R9, R0   # 0x0054
        BRA_PRED         0, L003c   # 0x0058
L005c:  MOVI             R7, 128   # 0x005c
        ST_SHARED_IDX    R6, R7, R2, 1, 0   # 0x0060
        C_MOV            R6, R2   # 0x0064
        C_SHLI           R6, 2   # 0x0066
        ST_SHARED        R8, R6, 0   # 0x0068
        C_BAR_ARRIVE     0   # 0x006c
        C_BAR_WAIT       0   # 0x006e
        SETP_LT_U_NPI    P0, R8, R3, 2   # 0x0070
        BRA_PRED         4, L00ba   # 0x0074
L0078:  MOVI             R6, 0   # 0x0078
        LD_SHARED        R8, R6, 0   # 0x007c
        CVT_F32_S32_P    R6, 3, R0, R0, R0   # 0x0080
        RCP_F32_P        R9, 3, R6, R6, R6   # 0x0084
        SHFL_IDX         R9, 7, R9, 0   # 0x008a
        C_MOV            R6, R9   # 0x008e
        C_FMUL           R6, R8   # 0x0090
        C_MOV            R8, R6   # 0x0092
        C_FMUL           R8, R8   # 0x0094
        FNEG_F0          R8, R8, R8, R8   # 0x0096
        LD_SHARED        R7, R7, 0   # 0x009a
        FFMA_F0          R7, R9, R7, R8   # 0x009e
        C_FADD           R7, R5   # 0x00a2
        RSQRT_F32        R5, R7, R7, R7   # 0x00a4
        SETP_EQ_NPI      P0, R7, R2, 0   # 0x00a8
        BRA_PRED         0, L0102   # 0x00ac
        SETP_LE_U_NP     P0, R4, R0, R2   # 0x00b0
        BRA_PRED         4, L0126   # 0x00b4
        C_BRA            L0174   # 0x00b8
L00ba:  ADDI             R8, R6, 128   # 0x00ba
        C_MOV            R10, R3   # 0x00be
        C_MOV            R9, R10   # 0x00c0
        C_BRA            L00d2   # 0x00c2
L00c4:  C_BAR_ARRIVE     0   # 0x00c4
        C_BAR_WAIT       0   # 0x00c6
        SETP_LT_U_NPI    P0, R10, R10, 4   # 0x00c8
        C_MOV            R10, R9   # 0x00cc
        BRA_PRED         0, L0078   # 0x00ce
L00d2:  C_SHRI           R9, 1   # 0x00d2
        SETP_LE_U_NP     P0, R11, R9, R2   # 0x00d4
        BRA_PRED         0, L00c4   # 0x00d8
        ADD              R11, R9, R2, R9   # 0x00dc
        C_MOV            R12, R11   # 0x00e0
        C_SHLI           R12, 2   # 0x00e2
        LD_SHARED        R12, R12, 0   # 0x00e4
        LD_SHARED        R13, R6, 0   # 0x00e8
        C_FADD           R12, R13   # 0x00ec
        ST_SHARED        R12, R6, 0   # 0x00ee
        LD_SHARED_IDX    R11, R7, R11, 1, 0   # 0x00f2
        LD_SHARED        R12, R8, 0   # 0x00f6
        C_FADD           R11, R12   # 0x00fa
        ST_SHARED        R11, R8, 0   # 0x00fc
        C_BRA            L00c4   # 0x0100
L0102:  C_SHLI           R4, 2   # 0x0102
        MOVI             R7, 2   # 0x0104
        LD_GLOBAL        R8, R7, 44   # 0x0108
        C_ADD            R8, R4   # 0x010c
        ST_GLOBAL_SLOT   R6, 1, R8, 0, 0   # 0x010e
        LD_GLOBAL        R7, R7, 52   # 0x0112
        ADD              R4, R7, R4, R7   # 0x0116
        ST_GLOBAL_SLOT   R5, 2, R4, 0, 0   # 0x011a
        SETP_LE_U_NP     P0, R4, R0, R2   # 0x011e
        BRA_PRED         0, L0174   # 0x0122
L0126:  MOVI             R4, 2   # 0x0126
L012a:  ADD              R7, R1, R2, R1   # 0x012a
        C_SHLI           R7, 2   # 0x012e
        LD_GLOBAL        R8, R4, 60   # 0x0130
        C_ADD            R8, R7   # 0x0134
        LD_GLOBAL_SLOT   R8, 3, R8, 0, 0   # 0x0136
        FSUB             R8, R8, R6, R8   # 0x013a
        C_MOV            R9, R5   # 0x013e
        C_FMUL           R9, R8   # 0x0140
        C_MOV            R8, R2   # 0x0142
        C_SHLI           R8, 2   # 0x0144
        LD_GLOBAL        R10, R4, 68   # 0x0146
        C_ADD            R10, R8   # 0x014a
        LD_GLOBAL        R11, R4, 76   # 0x014c
        ADD              R8, R11, R8, R11   # 0x0150
        LD_GLOBAL_SLOT   R8, 5, R8, 0, 0   # 0x0154
        LD_GLOBAL_SLOT   R10, 4, R10, 0, 0   # 0x0158
        FFMA_ACC_F0      R8, R10, R9   # 0x015c
        LD_GLOBAL        R9, R4, 36   # 0x015e
        ADD              R7, R9, R7, R9   # 0x0162
        ST_GLOBAL_SLOT   R8, 0, R7, 0, 0   # 0x0166
        C_ADD            R2, R3   # 0x016a
        SETP_LT_U_NP     P0, R7, R2, R0   # 0x016c
        BRA_PRED         0, L012a   # 0x0170
L0174:  C_EXIT           0   # 0x0174
