# gemv-128: test/cuda/gemv.cu, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        MOVI             R0, 2   # 0x0000
        C_LD_GLOBAL      R1, R0   # 0x0004
        SRD              R2, 0   # 0x0006
        SRD              R3, 1   # 0x0008
        MADLO            R4, R3, R1, R2   # 0x000a
        LD_GLOBAL        R3, R0, 56   # 0x000e
        SETP_LT_NPI      P0, R1, R3, 1   # 0x0012
        ST_LOCAL         R4, 12   # 0x0016
        BRA_PRED         0, L02b2   # 0x001a
        C_MUL_LO         R4, R3   # 0x001e
        MOVI             R6, 0   # 0x0020
        C_MOV            R7, R2   # 0x0024
        C_SHLI           R7, 2   # 0x0026
        MOVI             R14, 104   # 0x0028
        MOVI             R15, 108   # 0x002c
        MOVI             R1, 112   # 0x0030
        MOVI             R5, 116   # 0x0034
        MOVI             R8, 120   # 0x0038
        MOVI             R9, 124   # 0x003c
        MOVI             R11, 0   # 0x0040
        BRA              L028c   # 0x0044
L0048:  ADD              R10, R4, R6, R4   # 0x0048
        C_SHLI           R10, 2   # 0x004c
        C_BAR_ARRIVE     0   # 0x004e
        C_BAR_WAIT       0   # 0x0050
        LD_GLOBAL        R12, R0, 44   # 0x0052
        C_ADD            R10, R12   # 0x0056
        MOVI             R12, 0   # 0x0058
        LD_SHARED        R12, R12, 0   # 0x005c
        LD_GLOBAL_SLOT   R13, 1, R10, 0, 0   # 0x0060
        FFMA_ACC_F0      R11, R13, R12   # 0x0064
        ADDI             R12, R10, 4   # 0x0066
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x006a
        MOVI             R13, 4   # 0x006e
        LD_SHARED        R13, R13, 0   # 0x0072
        FFMA_ACC_F0      R11, R12, R13   # 0x0076
        ADDI             R12, R10, 8   # 0x0078
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x007c
        MOVI             R13, 8   # 0x0080
        LD_SHARED        R13, R13, 0   # 0x0084
        FFMA_ACC_F0      R11, R12, R13   # 0x0088
        ADDI             R12, R10, 12   # 0x008a
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x008e
        MOVI             R13, 12   # 0x0092
        LD_SHARED        R13, R13, 0   # 0x0096
        FFMA_ACC_F0      R11, R12, R13   # 0x009a
        ADDI             R12, R10, 16   # 0x009c
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x00a0
        MOVI             R13, 16   # 0x00a4
        LD_SHARED        R13, R13, 0   # 0x00a8
        FFMA_ACC_F0      R11, R12, R13   # 0x00ac
        ADDI             R12, R10, 20   # 0x00ae
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x00b2
        MOVI             R13, 20   # 0x00b6
        LD_SHARED        R13, R13, 0   # 0x00ba
        FFMA_ACC_F0      R11, R12, R13   # 0x00be
        ADDI             R12, R10, 24   # 0x00c0
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x00c4
        MOVI             R13, 24   # 0x00c8
        LD_SHARED        R13, R13, 0   # 0x00cc
        FFMA_ACC_F0      R11, R12, R13   # 0x00d0
        ADDI             R12, R10, 28   # 0x00d2
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x00d6
        MOVI             R13, 28   # 0x00da
        LD_SHARED        R13, R13, 0   # 0x00de
        FFMA_ACC_F0      R11, R12, R13   # 0x00e2
        ADDI             R12, R10, 32   # 0x00e4
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x00e8
        MOVI             R13, 32   # 0x00ec
        LD_SHARED        R13, R13, 0   # 0x00f0
        FFMA_ACC_F0      R11, R12, R13   # 0x00f4
        ADDI             R12, R10, 36   # 0x00f6
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x00fa
        MOVI             R13, 36   # 0x00fe
        LD_SHARED        R13, R13, 0   # 0x0102
        FFMA_ACC_F0      R11, R12, R13   # 0x0106
        ADDI             R12, R10, 40   # 0x0108
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x010c
        MOVI             R13, 40   # 0x0110
        LD_SHARED        R13, R13, 0   # 0x0114
        FFMA_ACC_F0      R11, R12, R13   # 0x0118
        ADDI             R12, R10, 44   # 0x011a
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x011e
        MOVI             R13, 44   # 0x0122
        LD_SHARED        R13, R13, 0   # 0x0126
        FFMA_ACC_F0      R11, R12, R13   # 0x012a
        ADDI             R12, R10, 48   # 0x012c
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0130
        MOVI             R13, 48   # 0x0134
        LD_SHARED        R13, R13, 0   # 0x0138
        FFMA_ACC_F0      R11, R12, R13   # 0x013c
        ADDI             R12, R10, 52   # 0x013e
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0142
        MOVI             R13, 52   # 0x0146
        LD_SHARED        R13, R13, 0   # 0x014a
        FFMA_ACC_F0      R11, R12, R13   # 0x014e
        ADDI             R12, R10, 56   # 0x0150
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0154
        MOVI             R13, 56   # 0x0158
        LD_SHARED        R13, R13, 0   # 0x015c
        FFMA_ACC_F0      R11, R12, R13   # 0x0160
        ADDI             R12, R10, 60   # 0x0162
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0166
        MOVI             R13, 60   # 0x016a
        LD_SHARED        R13, R13, 0   # 0x016e
        FFMA_ACC_F0      R11, R12, R13   # 0x0172
        ADDI             R12, R10, 64   # 0x0174
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0178
        MOVI             R13, 64   # 0x017c
        LD_SHARED        R13, R13, 0   # 0x0180
        FFMA_ACC_F0      R11, R12, R13   # 0x0184
        ADDI             R12, R10, 68   # 0x0186
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x018a
        MOVI             R13, 68   # 0x018e
        LD_SHARED        R13, R13, 0   # 0x0192
        FFMA_ACC_F0      R11, R12, R13   # 0x0196
        ADDI             R12, R10, 72   # 0x0198
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x019c
        MOVI             R13, 72   # 0x01a0
        LD_SHARED        R13, R13, 0   # 0x01a4
        FFMA_ACC_F0      R11, R12, R13   # 0x01a8
        ADDI             R12, R10, 76   # 0x01aa
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x01ae
        MOVI             R13, 76   # 0x01b2
        LD_SHARED        R13, R13, 0   # 0x01b6
        FFMA_ACC_F0      R11, R12, R13   # 0x01ba
        ADDI             R12, R10, 80   # 0x01bc
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x01c0
        MOVI             R13, 80   # 0x01c4
        LD_SHARED        R13, R13, 0   # 0x01c8
        FFMA_ACC_F0      R11, R12, R13   # 0x01cc
        ADDI             R12, R10, 84   # 0x01ce
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x01d2
        MOVI             R13, 84   # 0x01d6
        LD_SHARED        R13, R13, 0   # 0x01da
        FFMA_ACC_F0      R11, R12, R13   # 0x01de
        ADDI             R12, R10, 88   # 0x01e0
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x01e4
        MOVI             R13, 88   # 0x01e8
        LD_SHARED        R13, R13, 0   # 0x01ec
        FFMA_ACC_F0      R11, R12, R13   # 0x01f0
        ADDI             R12, R10, 92   # 0x01f2
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x01f6
        MOVI             R13, 92   # 0x01fa
        LD_SHARED        R13, R13, 0   # 0x01fe
        FFMA_ACC_F0      R11, R12, R13   # 0x0202
        ADDI             R12, R10, 96   # 0x0204
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0208
        MOVI             R13, 96   # 0x020c
        LD_SHARED        R13, R13, 0   # 0x0210
        FFMA_ACC_F0      R11, R12, R13   # 0x0214
        ADDI             R12, R10, 100   # 0x0216
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x021a
        MOVI             R13, 100   # 0x021e
        LD_SHARED        R13, R13, 0   # 0x0222
        FFMA_ACC_F0      R11, R12, R13   # 0x0226
        ADDI             R12, R10, 104   # 0x0228
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x022c
        LD_SHARED        R13, R14, 0   # 0x0230
        FFMA_ACC_F0      R11, R12, R13   # 0x0234
        ADDI             R12, R10, 108   # 0x0236
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x023a
        LD_SHARED        R13, R15, 0   # 0x023e
        FFMA_ACC_F0      R11, R12, R13   # 0x0242
        ADDI             R12, R10, 112   # 0x0244
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0248
        LD_SHARED        R13, R1, 0   # 0x024c
        FFMA_ACC_F0      R11, R12, R13   # 0x0250
        ADDI             R12, R10, 116   # 0x0252
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0256
        LD_SHARED        R13, R5, 0   # 0x025a
        FFMA_ACC_F0      R11, R12, R13   # 0x025e
        ADDI             R12, R10, 120   # 0x0260
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0264
        LD_SHARED        R13, R8, 0   # 0x0268
        FFMA_ACC_F0      R11, R12, R13   # 0x026c
        ADDI             R10, R10, 124   # 0x026e
        LD_GLOBAL_SLOT   R10, 1, R10, 0, 0   # 0x0272
        LD_SHARED        R12, R9, 0   # 0x0276
        FFMA_ACC_F0      R11, R10, R12   # 0x027a
        ADDI             R6, R6, 32   # 0x027c
        SETP_LT_NP       P0, R10, R6, R3   # 0x0280
        C_BAR_ARRIVE     0   # 0x0284
        C_BAR_WAIT       0   # 0x0286
        BRA_PRED         4, L02b6   # 0x0288
L028c:  MOVI             R10, 31   # 0x028c
        SETP_LT_U_NP     P0, R10, R10, R2   # 0x0290
        BRA_PRED         0, L0048   # 0x0294
        ADD              R10, R2, R6, R2   # 0x0298
        C_SHLI           R10, 2   # 0x029c
        LD_GLOBAL        R12, R0, 52   # 0x029e
        ADD              R10, R12, R10, R12   # 0x02a2
        LD_GLOBAL_SLOT   R10, 2, R10, 0, 0   # 0x02a6
        ST_SHARED        R10, R7, 0   # 0x02aa
        BRA              L0048   # 0x02ae
L02b2:  MOVI             R11, 0   # 0x02b2
L02b6:  LD_LOCAL         R1, 12   # 0x02b6
        C_SHLI           R1, 2   # 0x02ba
        LD_GLOBAL        R0, R0, 36   # 0x02bc
        C_ADD            R0, R1   # 0x02c0
        ST_GLOBAL_SLOT   R11, 0, R0, 0, 0   # 0x02c2
        C_EXIT           0   # 0x02c6
