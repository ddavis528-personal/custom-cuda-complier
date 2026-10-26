# cta-reduce-128: test/cuda/cta-reduce.cu, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        MOVI             R0, 2   # 0x0000
        LD_GLOBAL        R2, R0, 36   # 0x0004
        SRD              R0, 0   # 0x0008
        C_MOV            R1, R0   # 0x000a
        C_SHLI           R1, 2   # 0x000c
        ADD              R3, R2, R1, R2   # 0x000e
        MOVI             R2, 0   # 0x0012
        LD_GLOBAL_SLOT   R3, 0, R3, 0, 0   # 0x0016
        SETP_LT_U_NPI    P0, R4, R3, 2   # 0x001a
        BRA_PRED         0, L0044   # 0x001e
        MOVI             R4, 1   # 0x0022
L0026:  MULI             R5, R3, 3   # 0x0026
        C_ADDI           R5, 1   # 0x002a
        ANDI             R6, R3, 1   # 0x002c
        C_SHRI           R3, 1   # 0x0030
        SETP_NE_NPI      P0, R6, R6, 0   # 0x0032
        MOV_P            R3, 0, R5, R5, R5   # 0x0036
        C_ADDI           R2, 1   # 0x003a
        SETP_LT_U_NP     P0, R5, R4, R3   # 0x003c
        BRA_PRED         0, L0026   # 0x0040
L0044:  ST_SHARED        R2, R1, 0   # 0x0044
        MOVI             R2, 63   # 0x0048
        SETP_LT_NP       P0, R2, R2, R0   # 0x004c
        C_BAR_ARRIVE     0   # 0x0050
        C_BAR_WAIT       0   # 0x0052
        BRA_PRED         0, L006c   # 0x0054
        MOVI             R2, 256   # 0x0058
        LD_SHARED_IDX    R2, R2, R0, 1, 0   # 0x005c
        LD_SHARED        R3, R1, 0   # 0x0060
        ADD              R2, R3, R2, R3   # 0x0064
        ST_SHARED        R2, R1, 0   # 0x0068
L006c:  MOVI             R2, 31   # 0x006c
        SETP_LT_NP       P0, R2, R2, R0   # 0x0070
        C_BAR_ARRIVE     0   # 0x0074
        C_BAR_WAIT       0   # 0x0076
        BRA_PRED         0, L0090   # 0x0078
        MOVI             R2, 128   # 0x007c
        LD_SHARED_IDX    R2, R2, R0, 1, 0   # 0x0080
        LD_SHARED        R3, R1, 0   # 0x0084
        ADD              R2, R3, R2, R3   # 0x0088
        ST_SHARED        R2, R1, 0   # 0x008c
L0090:  MOVI             R2, 15   # 0x0090
        SETP_LT_NP       P0, R2, R2, R0   # 0x0094
        C_BAR_ARRIVE     0   # 0x0098
        C_BAR_WAIT       0   # 0x009a
        BRA_PRED         0, L00b4   # 0x009c
        MOVI             R2, 64   # 0x00a0
        LD_SHARED_IDX    R2, R2, R0, 1, 0   # 0x00a4
        LD_SHARED        R3, R1, 0   # 0x00a8
        ADD              R2, R3, R2, R3   # 0x00ac
        ST_SHARED        R2, R1, 0   # 0x00b0
L00b4:  MOVI             R2, 7   # 0x00b4
        SETP_LT_NP       P0, R2, R2, R0   # 0x00b8
        C_BAR_ARRIVE     0   # 0x00bc
        C_BAR_WAIT       0   # 0x00be
        BRA_PRED         0, L00d8   # 0x00c0
        MOVI             R2, 32   # 0x00c4
        LD_SHARED_IDX    R2, R2, R0, 1, 0   # 0x00c8
        LD_SHARED        R3, R1, 0   # 0x00cc
        ADD              R2, R3, R2, R3   # 0x00d0
        ST_SHARED        R2, R1, 0   # 0x00d4
L00d8:  MOVI             R2, 3   # 0x00d8
        SETP_LT_NP       P0, R2, R2, R0   # 0x00dc
        C_BAR_ARRIVE     0   # 0x00e0
        C_BAR_WAIT       0   # 0x00e2
        BRA_PRED         0, L00fc   # 0x00e4
        MOVI             R2, 16   # 0x00e8
        LD_SHARED_IDX    R2, R2, R0, 1, 0   # 0x00ec
        LD_SHARED        R3, R1, 0   # 0x00f0
        ADD              R2, R3, R2, R3   # 0x00f4
        ST_SHARED        R2, R1, 0   # 0x00f8
L00fc:  MOVI             R2, 1   # 0x00fc
        SETP_LT_NP       P0, R2, R2, R0   # 0x0100
        C_BAR_ARRIVE     0   # 0x0104
        C_BAR_WAIT       0   # 0x0106
        BRA_PRED         0, L0120   # 0x0108
        MOVI             R2, 8   # 0x010c
        LD_SHARED_IDX    R2, R2, R0, 1, 0   # 0x0110
        LD_SHARED        R3, R1, 0   # 0x0114
        ADD              R2, R3, R2, R3   # 0x0118
        ST_SHARED        R2, R1, 0   # 0x011c
L0120:  MOVI             R2, 0   # 0x0120
        SETP_LT_NP       P0, R3, R2, R0   # 0x0124
        C_BAR_ARRIVE     0   # 0x0128
        C_BAR_WAIT       0   # 0x012a
        BRA_PRED         0, L0144   # 0x012c
        MOVI             R3, 4   # 0x0130
        LD_SHARED_IDX    R3, R3, R0, 1, 0   # 0x0134
        LD_SHARED        R4, R1, 0   # 0x0138
        ADD              R3, R4, R3, R4   # 0x013c
        ST_SHARED        R3, R1, 0   # 0x0140
L0144:  C_BAR_ARRIVE     0   # 0x0144
        C_BAR_WAIT       0   # 0x0146
        MOVI             R3, 2   # 0x0148
        LD_GLOBAL        R3, R3, 44   # 0x014c
        ADD              R1, R3, R1, R3   # 0x0150
        LD_SHARED        R2, R2, 0   # 0x0154
        ADD              R0, R2, R0, R2   # 0x0158
        ST_GLOBAL_SLOT   R0, 1, R1, 0, 0   # 0x015c
        C_EXIT           0   # 0x0160
