# transpose-128: test/cuda/transpose32.cu, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        PMOV_IMM         P3, 1   # 0x0000
        MOVI             R1, 2   # 0x0006
        LD_GLOBAL_P      R0, 3, R1, 48   # 0x000a
        SHFL_IDX         R0, 7, R0, 0   # 0x000e
        C_MOV            R5, R0   # 0x0012
        C_SHRI           R5, 5   # 0x0014
        RCP_U32          R2, R5, R5, R5   # 0x0016
        MUL_LO           R3, R2, R5, R5   # 0x001a
        C_NEG            R3, R3   # 0x001e
        MUL_HI_U_P       R3, 3, R2, R3, R2   # 0x0020
        ADD_P            R2, 3, R2, R3, R2   # 0x0024
        SRD              R3, 1   # 0x0028
        MUL_HI_U_P       R2, 3, R3, R2, R3   # 0x002a
        SHFL_IDX         R2, 7, R2, 0   # 0x002e
        MUL_LO           R4, R2, R5, R5   # 0x0032
        SUB_P            R4, 3, R3, R4, R3   # 0x0036
        SHFL_IDX         R4, 7, R4, 0   # 0x003a
        SETP_LE_U_NP     P0, R6, R5, R4   # 0x003e
        ADDI_P           R6, 3, R2, 1   # 0x0042
        PAND             P0, 0, 3   # 0x0046
        MOV_P            R2, 0, R6, R6, R6   # 0x0048
        SUB_P            R6, 3, R4, R5, R4   # 0x004c
        MOV_P            R4, 0, R6, R6, R6   # 0x0050
        SHFL_IDX         R4, 7, R4, 0   # 0x0054
        SETP_LE_U_NP     P0, R4, R5, R4   # 0x0058
        ADDI_P           R4, 3, R2, 1   # 0x005c
        PAND             P0, 0, 3   # 0x0060
        MOV_P            R2, 0, R4, R4, R4   # 0x0062
        SHFL_IDX         R2, 7, R2, 0   # 0x0066
        SRD              R8, 0   # 0x006a
        C_MOV            R4, R8   # 0x006c
        C_SHRI           R4, 5   # 0x006e
        MOVI             R9, 1023   # 0x0070
        SETP_LT_U_NP     P0, R6, R9, R8   # 0x0074
        ANDI             R6, R8, 31   # 0x0078
        C_SHLI           R3, 5   # 0x007c
        MUL_LO           R7, R2, R5, R5   # 0x007e
        C_SHLI           R2, 5   # 0x0082
        C_MOV            R5, R0   # 0x0084
        C_SHLI           R5, 2   # 0x0086
        BRA_PRED         0, L00c4   # 0x0088
        ADD              R10, R4, R2, R4   # 0x008c
        MADLO            R10, R0, R10, R3   # 0x0090
        C_ADD            R10, R6   # 0x0094
        C_MOV            R11, R7   # 0x0096
        C_SHLI           R11, 5   # 0x0098
        C_SUB            R10, R11   # 0x009a
        C_MOV            R11, R4   # 0x009c
L009e:  LD_GLOBAL        R12, R1, 44   # 0x009e
        C_MOV            R13, R10   # 0x00a2
        C_SHLI           R13, 2   # 0x00a4
        C_ADD            R12, R13   # 0x00a6
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x00a8
        MULI             R13, R11, 132   # 0x00ac
        ST_SHARED_IDX    R12, R13, R6, 1, 0   # 0x00b0
        C_ADD            R10, R5   # 0x00b4
        ADDI             R12, R11, 4   # 0x00b6
        SETP_LT_U_NPI    P0, R11, R11, 28   # 0x00ba
        C_MOV            R11, R12   # 0x00be
        BRA_PRED         0, L009e   # 0x00c0
L00c4:  SETP_LT_U_NP     P0, R1, R9, R8   # 0x00c4
        C_BAR_ARRIVE     0   # 0x00c8
        C_BAR_WAIT       0   # 0x00ca
        BRA_PRED         0, L0108   # 0x00cc
        ADD              R1, R4, R3, R4   # 0x00d0
        C_SHLI           R7, 5   # 0x00d4
        C_SUB            R1, R7   # 0x00d6
        MADLO            R0, R0, R1, R2   # 0x00d8
        C_ADD            R0, R6   # 0x00dc
        MOVI             R1, 2   # 0x00de
        MULI             R2, R6, 132   # 0x00e2
L00e6:  LD_GLOBAL        R3, R1, 36   # 0x00e6
        C_MOV            R6, R0   # 0x00ea
        C_SHLI           R6, 2   # 0x00ec
        C_ADD            R3, R6   # 0x00ee
        LD_SHARED_IDX    R6, R2, R4, 1, 0   # 0x00f0
        ST_GLOBAL_SLOT   R6, 0, R3, 0, 0   # 0x00f4
        C_ADD            R0, R5   # 0x00f8
        ADDI             R3, R4, 4   # 0x00fa
        SETP_LT_U_NPI    P0, R4, R4, 28   # 0x00fe
        C_MOV            R4, R3   # 0x0102
        BRA_PRED         0, L00e6   # 0x0104
L0108:  C_EXIT           0   # 0x0108
