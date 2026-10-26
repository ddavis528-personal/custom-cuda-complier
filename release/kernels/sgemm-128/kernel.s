# sgemm-128: test/cuda/sgemm.cu -DBX=16 -DBY=8, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        PMOV_IMM         P3, 1   # 0x0000
        MOVI             R4, 2   # 0x0006
        LD_GLOBAL_P      R1, 3, R4, 60   # 0x000a
        SHFL_IDX         R1, 7, R1, 0   # 0x000e
        RCP_U32          R0, R1, R1, R1   # 0x0012
        MUL_LO           R2, R0, R1, R1   # 0x0016
        C_NEG            R2, R2   # 0x001a
        MUL_HI_U_P       R2, 3, R0, R2, R0   # 0x001c
        ADD_P            R2, 3, R0, R2, R0   # 0x0020
        SRD              R0, 1   # 0x0024
        MUL_HI_U_P       R5, 3, R0, R2, R0   # 0x0026
        SHFL_IDX         R5, 7, R5, 0   # 0x002a
        MUL_LO           R2, R5, R1, R1   # 0x002e
        SUB_P            R2, 3, R0, R2, R0   # 0x0032
        SHFL_IDX         R2, 7, R2, 0   # 0x0036
        SETP_LE_U_NP     P0, R3, R1, R2   # 0x003a
        ADDI_P           R3, 3, R5, 1   # 0x003e
        PAND             P0, 0, 3   # 0x0042
        MOV_P            R5, 0, R3, R3, R3   # 0x0044
        SUB_P            R3, 3, R2, R1, R2   # 0x0048
        MOV_P            R2, 0, R3, R3, R3   # 0x004c
        SHFL_IDX         R2, 7, R2, 0   # 0x0050
        SETP_LE_U_NP     P0, R2, R1, R2   # 0x0054
        ADDI_P           R2, 3, R5, 1   # 0x0058
        PAND             P0, 0, 3   # 0x005c
        MOV_P            R5, 0, R2, R2, R2   # 0x005e
        SHFL_IDX         R5, 7, R5, 0   # 0x0062
        MUL_LO           R2, R5, R1, R1   # 0x0066
        SUB_P            R7, 3, R0, R2, R0   # 0x006a
        SHFL_IDX         R7, 7, R7, 0   # 0x006e
        SRD              R6, 0   # 0x0072
        C_MOV            R1, R6   # 0x0074
        C_SHRI           R1, 3   # 0x0076
        MOVI48           R3, 536870910   # 0x0078
        AND              R8, R1, R3, R1   # 0x007e
        C_MOV            R3, R6   # 0x0082
        C_SHLI           R3, 1   # 0x0084
        ANDI             R9, R3, 30   # 0x0086
        C_SHLI           R5, 4   # 0x008a
        C_SHLI           R7, 5   # 0x008c
        ST_LOCAL         R7, 152   # 0x008e
        LD_GLOBAL_P      R10, 3, R4, 56   # 0x0092
        SHFL_IDX         R10, 7, R10, 0   # 0x0096
        SETP_LT_NPI      P0, R3, R10, 1   # 0x009a
        ST_LOCAL         R5, 148   # 0x009e
        ST_LOCAL         R8, 156   # 0x00a2
        ST_LOCAL         R9, 160   # 0x00a6
        BRA_PRED         0, L0404   # 0x00aa
        C_SHLI           R0, 5   # 0x00ae
        ANDI             R3, R6, 31   # 0x00b0
        C_OR             R0, R3   # 0x00b4
        C_SHLI           R2, 5   # 0x00b6
        SUB              R7, R0, R2, R0   # 0x00b8
        ANDI             R0, R6, 15   # 0x00bc
        ADD              R2, R5, R0, R5   # 0x00c0
        C_SHLI           R0, 2   # 0x00c4
        C_MOV            R4, R6   # 0x00c6
        C_SHRI           R4, 4   # 0x00c8
        MADLO            R2, R10, R2, R4   # 0x00ca
        ST_LOCAL         R2, 124   # 0x00ce
        C_SHLI           R4, 6   # 0x00d2
        OR               R0, R4, R0, R4   # 0x00d4
        ST_LOCAL         R0, 128   # 0x00d8
        C_SHLI           R3, 2   # 0x00dc
        C_MOV            R0, R6   # 0x00de
        C_SHRI           R0, 5   # 0x00e0
        ADDI             R2, R6, 128   # 0x00e2
        C_SHRI           R2, 5   # 0x00e6
        MUL_LO           R4, R10, R2, R2   # 0x00e8
        ST_LOCAL         R4, 140   # 0x00ec
        C_SHLI           R2, 7   # 0x00f0
        OR               R14, R2, R3, R2   # 0x00f2
        MUL_LO           R2, R10, R0, R0   # 0x00f6
        ST_LOCAL         R2, 132   # 0x00fa
        C_SHLI           R0, 7   # 0x00fe
        OR               R15, R0, R3, R0   # 0x0100
        MOVI             R12, 0   # 0x0104
        MOVI             R0, 0   # 0x0108
        C_MOV            R2, R10   # 0x010c
        C_SHLI           R2, 3   # 0x010e
        ST_LOCAL         R2, 12   # 0x0110
        C_MOV            R2, R9   # 0x0114
        C_SHLI           R2, 2   # 0x0116
        ORI              R3, R2, 1412   # 0x0118
        ST_LOCAL         R3, 16   # 0x011c
        ORI              R3, R2, 1408   # 0x0120
        ST_LOCAL         R3, 20   # 0x0124
        C_MOV            R4, R8   # 0x0128
        C_SHLI           R4, 2   # 0x012a
        ADDI             R3, R4, 448   # 0x012c
        ST_LOCAL         R3, 24   # 0x0130
        ORI              R3, R2, 1284   # 0x0134
        ST_LOCAL         R3, 28   # 0x0138
        ORI              R3, R2, 1280   # 0x013c
        ST_LOCAL         R3, 32   # 0x0140
        ADDI             R3, R4, 384   # 0x0144
        ST_LOCAL         R3, 36   # 0x0148
        ORI              R3, R2, 1156   # 0x014c
        ST_LOCAL         R3, 40   # 0x0150
        ORI              R3, R2, 1152   # 0x0154
        ST_LOCAL         R3, 44   # 0x0158
        ADDI             R3, R4, 320   # 0x015c
        ST_LOCAL         R3, 48   # 0x0160
        ORI              R3, R2, 1028   # 0x0164
        ST_LOCAL         R3, 52   # 0x0168
        ORI              R3, R2, 1024   # 0x016c
        ST_LOCAL         R3, 56   # 0x0170
        ADDI             R3, R4, 256   # 0x0174
        ST_LOCAL         R3, 60   # 0x0178
        ORI              R3, R2, 900   # 0x017c
        ST_LOCAL         R3, 64   # 0x0180
        ORI              R3, R2, 896   # 0x0184
        ST_LOCAL         R3, 68   # 0x0188
        ADDI             R3, R4, 192   # 0x018c
        ST_LOCAL         R3, 72   # 0x0190
        ORI              R3, R2, 772   # 0x0194
        ST_LOCAL         R3, 76   # 0x0198
        ORI              R3, R2, 768   # 0x019c
        ST_LOCAL         R3, 80   # 0x01a0
        ADDI             R3, R4, 128   # 0x01a4
        ST_LOCAL         R3, 84   # 0x01a8
        ORI              R3, R2, 644   # 0x01ac
        ST_LOCAL         R3, 88   # 0x01b0
        ORI              R3, R2, 640   # 0x01b4
        ST_LOCAL         R3, 92   # 0x01b8
        ADDI             R3, R4, 64   # 0x01bc
        ST_LOCAL         R3, 96   # 0x01c0
        ORI              R3, R2, 516   # 0x01c4
        ST_LOCAL         R3, 100   # 0x01c8
        ORI              R2, R2, 512   # 0x01cc
        ST_LOCAL         R2, 104   # 0x01d0
        C_SHLI           R1, 2   # 0x01d4
        ORI              R5, R1, 4   # 0x01d6
        ADDI             R1, R5, 448   # 0x01da
        ST_LOCAL         R1, 108   # 0x01de
        ADDI             R1, R5, 384   # 0x01e2
        ST_LOCAL         R1, 112   # 0x01e6
        ADDI             R1, R5, 320   # 0x01ea
        ST_LOCAL         R1, 116   # 0x01ee
        ADDI             R1, R5, 256   # 0x01f2
        ST_LOCAL         R1, 120   # 0x01f6
        ADDI             R9, R5, 192   # 0x01fa
        ADDI             R13, R5, 128   # 0x01fe
        ADDI             R11, R5, 64   # 0x0202
        ADDI             R1, R15, 512   # 0x0206
        ST_LOCAL         R1, 136   # 0x020a
        ADDI             R1, R14, 512   # 0x020e
        ST_LOCAL         R1, 144   # 0x0212
        MOVI             R1, 0   # 0x0216
        MOVI             R14, 0   # 0x021a
        MOVI             R15, 0   # 0x021e
        BRA              L037a   # 0x0222
L0226:  C_BAR_ARRIVE     0   # 0x0226
        C_BAR_WAIT       0   # 0x0228
        LD_LOCAL         R2, 100   # 0x022a
        LD_SHARED        R2, R2, 0   # 0x022e
        LD_LOCAL         R3, 104   # 0x0232
        LD_SHARED        R10, R3, 0   # 0x0236
        LD_SHARED        R3, R4, 0   # 0x023a
        FFMA_ACC_F0      R15, R3, R10   # 0x023e
        FFMA_F0          R3, R3, R2, R14   # 0x0240
        LD_SHARED        R14, R5, 0   # 0x0244
        FFMA_ACC_F0      R1, R14, R10   # 0x0248
        FFMA_ACC_F0      R0, R14, R2   # 0x024a
        LD_LOCAL         R2, 92   # 0x024c
        LD_SHARED        R2, R2, 0   # 0x0250
        LD_LOCAL         R10, 88   # 0x0254
        LD_SHARED        R10, R10, 0   # 0x0258
        LD_SHARED        R14, R11, 0   # 0x025c
        FFMA_ACC_F0      R0, R14, R10   # 0x0260
        FFMA_ACC_F0      R1, R14, R2   # 0x0262
        LD_LOCAL         R14, 96   # 0x0264
        LD_SHARED        R14, R14, 0   # 0x0268
        FFMA_ACC_F0      R3, R14, R10   # 0x026c
        FFMA_F0          R2, R14, R2, R15   # 0x026e
        LD_LOCAL         R10, 76   # 0x0272
        LD_SHARED        R10, R10, 0   # 0x0276
        LD_LOCAL         R14, 80   # 0x027a
        LD_SHARED        R14, R14, 0   # 0x027e
        LD_LOCAL         R15, 84   # 0x0282
        LD_SHARED        R15, R15, 0   # 0x0286
        FFMA_ACC_F0      R2, R15, R14   # 0x028a
        FFMA_ACC_F0      R3, R15, R10   # 0x028c
        LD_SHARED        R15, R13, 0   # 0x028e
        FFMA_ACC_F0      R1, R15, R14   # 0x0292
        FFMA_ACC_F0      R0, R15, R10   # 0x0294
        LD_LOCAL         R10, 68   # 0x0296
        LD_SHARED        R10, R10, 0   # 0x029a
        LD_LOCAL         R14, 64   # 0x029e
        LD_SHARED        R14, R14, 0   # 0x02a2
        LD_SHARED        R15, R9, 0   # 0x02a6
        FFMA_ACC_F0      R0, R15, R14   # 0x02aa
        FFMA_ACC_F0      R1, R15, R10   # 0x02ac
        LD_LOCAL         R15, 72   # 0x02ae
        LD_SHARED        R15, R15, 0   # 0x02b2
        FFMA_ACC_F0      R3, R15, R14   # 0x02b6
        FFMA_ACC_F0      R2, R15, R10   # 0x02b8
        LD_LOCAL         R10, 52   # 0x02ba
        LD_SHARED        R10, R10, 0   # 0x02be
        LD_LOCAL         R14, 56   # 0x02c2
        LD_SHARED        R14, R14, 0   # 0x02c6
        LD_LOCAL         R15, 60   # 0x02ca
        LD_SHARED        R15, R15, 0   # 0x02ce
        FFMA_ACC_F0      R2, R15, R14   # 0x02d2
        FFMA_ACC_F0      R3, R15, R10   # 0x02d4
        LD_LOCAL         R15, 120   # 0x02d6
        LD_SHARED        R15, R15, 0   # 0x02da
        FFMA_ACC_F0      R1, R15, R14   # 0x02de
        FFMA_ACC_F0      R0, R15, R10   # 0x02e0
        LD_LOCAL         R10, 44   # 0x02e2
        LD_SHARED        R10, R10, 0   # 0x02e6
        LD_LOCAL         R14, 40   # 0x02ea
        LD_SHARED        R14, R14, 0   # 0x02ee
        LD_LOCAL         R15, 116   # 0x02f2
        LD_SHARED        R15, R15, 0   # 0x02f6
        FFMA_ACC_F0      R0, R15, R14   # 0x02fa
        FFMA_ACC_F0      R1, R15, R10   # 0x02fc
        LD_LOCAL         R15, 48   # 0x02fe
        LD_SHARED        R15, R15, 0   # 0x0302
        FFMA_ACC_F0      R3, R15, R14   # 0x0306
        FFMA_ACC_F0      R2, R15, R10   # 0x0308
        LD_LOCAL         R10, 28   # 0x030a
        LD_SHARED        R10, R10, 0   # 0x030e
        LD_LOCAL         R14, 32   # 0x0312
        LD_SHARED        R14, R14, 0   # 0x0316
        LD_LOCAL         R15, 36   # 0x031a
        LD_SHARED        R15, R15, 0   # 0x031e
        FFMA_ACC_F0      R2, R15, R14   # 0x0322
        FFMA_ACC_F0      R3, R15, R10   # 0x0324
        LD_LOCAL         R15, 112   # 0x0326
        LD_SHARED        R15, R15, 0   # 0x032a
        FFMA_ACC_F0      R1, R15, R14   # 0x032e
        FFMA_ACC_F0      R0, R15, R10   # 0x0330
        LD_LOCAL         R10, 20   # 0x0332
        LD_SHARED        R10, R10, 0   # 0x0336
        LD_LOCAL         R14, 16   # 0x033a
        LD_SHARED        R14, R14, 0   # 0x033e
        LD_LOCAL         R15, 108   # 0x0342
        LD_SHARED        R15, R15, 0   # 0x0346
        FFMA_ACC_F0      R0, R15, R14   # 0x034a
        FFMA_ACC_F0      R1, R15, R10   # 0x034c
        LD_LOCAL         R15, 24   # 0x034e
        LD_SHARED        R15, R15, 0   # 0x0352
        FFMA_F0          R14, R15, R14, R3   # 0x0356
        FFMA_F0          R15, R15, R10, R2   # 0x035a
        LD_LOCAL         R2, 12   # 0x035e
        C_ADD            R7, R2   # 0x0362
        ADDI_P           R12, 3, R12, 8   # 0x0364
        SHFL_IDX         R12, 7, R12, 0   # 0x0368
        C_MOV            R10, R8   # 0x036c
        SETP_LT_NP       P0, R2, R12, R10   # 0x036e
        C_BAR_ARRIVE     0   # 0x0372
        C_BAR_WAIT       0   # 0x0374
        BRA_PRED         4, L0414   # 0x0376
L037a:  C_MOV            R8, R10   # 0x037a
        MOVI             R2, 128   # 0x037c
        SETP_LT_U_NP     P0, R2, R6, R2   # 0x0380
        BRA_PRED         4, L03a8   # 0x0384
        LD_LOCAL         R2, 124   # 0x0388
        C_ADD            R2, R12   # 0x038c
        C_SHLI           R2, 2   # 0x038e
        MOVI             R3, 2   # 0x0390
        LD_GLOBAL        R10, R3, 44   # 0x0394
        ADD              R2, R10, R2, R10   # 0x0398
        LD_GLOBAL_SLOT   R2, 1, R2, 0, 0   # 0x039c
        LD_LOCAL         R3, 128   # 0x03a0
        ST_SHARED        R2, R3, 0   # 0x03a4
L03a8:  MOVI             R2, 255   # 0x03a8
        SETP_LT_U_NP     P0, R2, R2, R6   # 0x03ac
        BRA_PRED         0, L0226   # 0x03b0
        LD_LOCAL         R2, 132   # 0x03b4
        C_ADD            R2, R7   # 0x03b8
        C_SHLI           R2, 2   # 0x03ba
        MOVI             R3, 2   # 0x03bc
        LD_GLOBAL        R10, R3, 52   # 0x03c0
        ADD              R2, R10, R2, R10   # 0x03c4
        LD_GLOBAL_SLOT   R2, 2, R2, 0, 0   # 0x03c8
        LD_LOCAL         R3, 136   # 0x03cc
        ST_SHARED        R2, R3, 0   # 0x03d0
        MOVI             R2, 128   # 0x03d4
        SETP_LT_U_NP     P0, R2, R6, R2   # 0x03d8
        BRA_PRED         4, L0226   # 0x03dc
        LD_LOCAL         R2, 140   # 0x03e0
        C_ADD            R2, R7   # 0x03e4
        C_SHLI           R2, 2   # 0x03e6
        MOVI             R3, 2   # 0x03e8
        LD_GLOBAL        R3, R3, 52   # 0x03ec
        ADD              R2, R3, R2, R3   # 0x03f0
        LD_GLOBAL_SLOT   R2, 2, R2, 0, 0   # 0x03f4
        LD_LOCAL         R3, 144   # 0x03f8
        ST_SHARED        R2, R3, 0   # 0x03fc
        BRA              L0226   # 0x0400
L0404:  MOVI             R0, 0   # 0x0404
        MOVI             R1, 0   # 0x0408
        MOVI             R14, 0   # 0x040c
        MOVI             R15, 0   # 0x0410
L0414:  LD_LOCAL         R2, 152   # 0x0414
        LD_LOCAL         R3, 160   # 0x0418
        OR               R2, R3, R2, R3   # 0x041c
        LD_LOCAL         R3, 148   # 0x0420
        LD_LOCAL         R4, 156   # 0x0424
        C_ADD            R3, R4   # 0x0428
        MADLO            R4, R3, R10, R2   # 0x042a
        C_SHLI           R4, 2   # 0x042e
        MOVI             R5, 2   # 0x0430
        LD_GLOBAL_P      R5, 3, R5, 36   # 0x0434
        SHFL_IDX         R5, 7, R5, 0   # 0x0438
        ADD              R4, R5, R4, R5   # 0x043c
        ST_GLOBAL_SLOT   R15, 0, R4, 0, 0   # 0x0440
        C_ADDI           R4, 4   # 0x0444
        ST_GLOBAL_SLOT   R14, 0, R4, 0, 0   # 0x0446
        C_ORI            R3, 1   # 0x044a
        MAD_ACC          R2, R3, R10   # 0x044c
        C_SHLI           R2, 2   # 0x044e
        ADD              R2, R5, R2, R5   # 0x0450
        ST_GLOBAL_SLOT   R1, 0, R2, 0, 0   # 0x0454
        ADDI             R1, R2, 4   # 0x0458
        ST_GLOBAL_SLOT   R0, 0, R1, 0, 0   # 0x045c
        C_EXIT           0   # 0x0460
