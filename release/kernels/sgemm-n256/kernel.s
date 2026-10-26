# sgemm-n256: test/cuda/sgemm.cu, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        PMOV_IMM         P3, 1   # 0x0000
        MOVI             R4, 2   # 0x0006
        LD_GLOBAL_P      R0, 3, R4, 60   # 0x000a
        SHFL_IDX         R0, 7, R0, 0   # 0x000e
        RCP_U32          R1, R0, R0, R0   # 0x0012
        MUL_LO           R2, R1, R0, R0   # 0x0016
        C_NEG            R2, R2   # 0x001a
        MUL_HI_U_P       R2, 3, R1, R2, R1   # 0x001c
        ADD_P            R2, 3, R1, R2, R1   # 0x0020
        SRD              R1, 1   # 0x0024
        MUL_HI_U_P       R12, 3, R1, R2, R1   # 0x0026
        SHFL_IDX         R12, 7, R12, 0   # 0x002a
        MUL_LO           R2, R12, R0, R0   # 0x002e
        SUB_P            R2, 3, R1, R2, R1   # 0x0032
        SHFL_IDX         R2, 7, R2, 0   # 0x0036
        SETP_LE_U_NP     P0, R3, R0, R2   # 0x003a
        ADDI_P           R3, 3, R12, 1   # 0x003e
        PAND             P0, 0, 3   # 0x0042
        MOV_P            R12, 0, R3, R3, R3   # 0x0044
        SUB_P            R3, 3, R2, R0, R2   # 0x0048
        MOV_P            R2, 0, R3, R3, R3   # 0x004c
        SHFL_IDX         R2, 7, R2, 0   # 0x0050
        SETP_LE_U_NP     P0, R2, R0, R2   # 0x0054
        ADDI_P           R2, 3, R12, 1   # 0x0058
        PAND             P0, 0, 3   # 0x005c
        MOV_P            R12, 0, R2, R2, R2   # 0x005e
        SHFL_IDX         R12, 7, R12, 0   # 0x0062
        MUL_LO           R3, R12, R0, R0   # 0x0066
        SUB_P            R5, 3, R1, R3, R1   # 0x006a
        SHFL_IDX         R5, 7, R5, 0   # 0x006e
        SRD              R6, 0   # 0x0072
        C_MOV            R0, R6   # 0x0074
        C_SHRI           R0, 2   # 0x0076
        MOVI48           R2, 1073741822   # 0x0078
        AND              R14, R0, R2, R0   # 0x007e
        C_MOV            R2, R6   # 0x0082
        C_SHLI           R2, 1   # 0x0084
        ANDI             R15, R2, 14   # 0x0086
        C_SHLI           R12, 3   # 0x008a
        C_SHLI           R5, 4   # 0x008c
        ST_LOCAL         R5, 180   # 0x008e
        LD_GLOBAL_P      R13, 3, R4, 56   # 0x0092
        SHFL_IDX         R13, 7, R13, 0   # 0x0096
        SETP_LT_NPI      P0, R2, R13, 1   # 0x009a
        ST_LOCAL         R12, 176   # 0x009e
        ST_LOCAL         R15, 184   # 0x00a2
        BRA_PRED         0, L0502   # 0x00a6
        ADDI             R2, R6, 96   # 0x00aa
        C_SHRI           R2, 4   # 0x00ae
        C_SHLI           R1, 4   # 0x00b0
        C_MOV            R4, R6   # 0x00b2
        C_SHRI           R4, 4   # 0x00b4
        ADDI             R5, R4, 4   # 0x00b6
        MADLO            R9, R13, R5, R1   # 0x00ba
        ADDI             R11, R6, 32   # 0x00be
        MADLO            R10, R13, R2, R1   # 0x00c2
        C_MOV            R5, R11   # 0x00c6
        C_SHRI           R5, 4   # 0x00c8
        MADLO            R8, R13, R5, R1   # 0x00ca
        MAD_ACC          R1, R13, R4   # 0x00ce
        C_SHLI           R3, 4   # 0x00d0
        SUB              R7, R1, R3, R1   # 0x00d2
        C_SUB            R8, R3   # 0x00d6
        C_SUB            R9, R3   # 0x00d8
        C_SUB            R10, R3   # 0x00da
        ANDI             R1, R6, 7   # 0x00dc
        ADD              R3, R12, R1, R12   # 0x00e0
        C_SHLI           R1, 2   # 0x00e4
        C_SHRI           R11, 3   # 0x00e6
        MADLO            R12, R13, R3, R11   # 0x00e8
        ST_LOCAL         R12, 160   # 0x00ec
        C_SHLI           R11, 5   # 0x00f0
        C_MOV            R12, R6   # 0x00f2
        C_SHRI           R12, 3   # 0x00f4
        MADLO            R3, R13, R3, R12   # 0x00f6
        ST_LOCAL         R3, 148   # 0x00fa
        C_SHLI           R12, 5   # 0x00fe
        OR               R3, R12, R1, R12   # 0x0100
        ST_LOCAL         R3, 152   # 0x0104
        OR               R1, R11, R1, R11   # 0x0108
        ST_LOCAL         R1, 164   # 0x010c
        C_SHLI           R5, 6   # 0x0110
        C_SHLI           R4, 6   # 0x0112
        C_SHLI           R2, 6   # 0x0114
        ANDI             R1, R6, 15   # 0x0116
        ST_LOCAL         R1, 144   # 0x011a
        C_SHLI           R1, 2   # 0x011e
        OR               R11, R2, R1, R2   # 0x0120
        OR               R2, R4, R1, R4   # 0x0124
        OR               R1, R5, R1, R5   # 0x0128
        ST_LOCAL         R1, 168   # 0x012c
        MOVI             R4, 0   # 0x0130
        MOVI             R12, 0   # 0x0134
        C_MOV            R3, R13   # 0x0138
        C_SHLI           R3, 3   # 0x013a
        C_MOV            R1, R15   # 0x013c
        C_SHLI           R1, 2   # 0x013e
        ORI              R15, R1, 708   # 0x0140
        ST_LOCAL         R15, 16   # 0x0144
        ORI              R15, R1, 704   # 0x0148
        ST_LOCAL         R15, 20   # 0x014c
        C_MOV            R15, R14   # 0x0150
        C_SHLI           R15, 2   # 0x0152
        ADDI             R5, R15, 224   # 0x0154
        ST_LOCAL         R5, 28   # 0x0158
        ORI              R5, R1, 644   # 0x015c
        ST_LOCAL         R5, 32   # 0x0160
        ORI              R5, R1, 640   # 0x0164
        ST_LOCAL         R5, 36   # 0x0168
        ADDI             R5, R15, 192   # 0x016c
        ST_LOCAL         R5, 40   # 0x0170
        ORI              R5, R1, 580   # 0x0174
        ST_LOCAL         R5, 44   # 0x0178
        ORI              R5, R1, 576   # 0x017c
        ST_LOCAL         R5, 48   # 0x0180
        ADDI             R5, R15, 160   # 0x0184
        ST_LOCAL         R5, 52   # 0x0188
        ORI              R5, R1, 516   # 0x018c
        ST_LOCAL         R5, 56   # 0x0190
        ORI              R5, R1, 512   # 0x0194
        ST_LOCAL         R5, 60   # 0x0198
        ADDI             R5, R15, 128   # 0x019c
        ST_LOCAL         R5, 64   # 0x01a0
        ORI              R5, R1, 452   # 0x01a4
        ST_LOCAL         R5, 68   # 0x01a8
        ORI              R5, R1, 448   # 0x01ac
        ST_LOCAL         R5, 72   # 0x01b0
        ADDI             R5, R15, 96   # 0x01b4
        ST_LOCAL         R5, 76   # 0x01b8
        ORI              R5, R1, 388   # 0x01bc
        ST_LOCAL         R5, 80   # 0x01c0
        ORI              R5, R1, 384   # 0x01c4
        ST_LOCAL         R5, 84   # 0x01c8
        ADDI             R5, R15, 64   # 0x01cc
        ST_LOCAL         R5, 88   # 0x01d0
        ORI              R5, R1, 324   # 0x01d4
        ST_LOCAL         R5, 92   # 0x01d8
        ORI              R5, R1, 320   # 0x01dc
        ST_LOCAL         R5, 96   # 0x01e0
        ST_LOCAL         R15, 24   # 0x01e4
        ADDI             R5, R15, 32   # 0x01e8
        ST_LOCAL         R5, 100   # 0x01ec
        ORI              R5, R1, 260   # 0x01f0
        ST_LOCAL         R5, 104   # 0x01f4
        ORI              R1, R1, 256   # 0x01f8
        ST_LOCAL         R1, 108   # 0x01fc
        C_SHLI           R0, 2   # 0x0200
        C_ORI            R0, 4   # 0x0202
        ADDI             R1, R0, 224   # 0x0204
        ST_LOCAL         R1, 116   # 0x0208
        ADDI             R1, R0, 192   # 0x020c
        ST_LOCAL         R1, 120   # 0x0210
        ADDI             R1, R0, 160   # 0x0214
        ST_LOCAL         R1, 124   # 0x0218
        ADDI             R1, R0, 128   # 0x021c
        ST_LOCAL         R1, 128   # 0x0220
        ADDI             R1, R0, 96   # 0x0224
        ST_LOCAL         R1, 132   # 0x0228
        ADDI             R1, R0, 64   # 0x022c
        ST_LOCAL         R1, 136   # 0x0230
        ST_LOCAL         R0, 112   # 0x0234
        ADDI             R0, R0, 32   # 0x0238
        ST_LOCAL         R0, 140   # 0x023c
        ADDI             R0, R2, 256   # 0x0240
        ST_LOCAL         R0, 156   # 0x0244
        ADDI             R0, R11, 256   # 0x0248
        ST_LOCAL         R0, 188   # 0x024c
        ORI              R11, R2, 256   # 0x0250
        ADDI             R0, R11, 256   # 0x0254
        ST_LOCAL         R0, 172   # 0x0258
        LD_LOCAL         R0, 168   # 0x025c
        ADDI             R0, R0, 256   # 0x0260
        ST_LOCAL         R0, 168   # 0x0264
        MOVI             R15, 0   # 0x0268
        MOVI             R2, 0   # 0x026c
        MOVI             R11, 0   # 0x0270
        ST_LOCAL         R13, 12   # 0x0274
        BRA              L03f6   # 0x0278
L027c:  C_BAR_ARRIVE     0   # 0x027c
        C_BAR_WAIT       0   # 0x027e
        LD_LOCAL         R0, 104   # 0x0280
        LD_SHARED        R5, R0, 0   # 0x0284
        LD_LOCAL         R0, 108   # 0x0288
        LD_SHARED        R13, R0, 0   # 0x028c
        LD_LOCAL         R0, 24   # 0x0290
        LD_SHARED        R0, R0, 0   # 0x0294
        FFMA_ACC_F0      R11, R0, R13   # 0x0298
        FFMA_F0          R0, R0, R5, R2   # 0x029a
        LD_LOCAL         R2, 112   # 0x029e
        LD_SHARED        R2, R2, 0   # 0x02a2
        FFMA_F0          R13, R2, R13, R15   # 0x02a6
        FFMA_F0          R2, R2, R5, R12   # 0x02aa
        LD_LOCAL         R5, 96   # 0x02ae
        LD_SHARED        R5, R5, 0   # 0x02b2
        LD_LOCAL         R12, 92   # 0x02b6
        LD_SHARED        R12, R12, 0   # 0x02ba
        LD_LOCAL         R14, 140   # 0x02be
        LD_SHARED        R15, R14, 0   # 0x02c2
        FFMA_ACC_F0      R2, R15, R12   # 0x02c6
        FFMA_ACC_F0      R13, R15, R5   # 0x02c8
        LD_LOCAL         R14, 100   # 0x02ca
        LD_SHARED        R15, R14, 0   # 0x02ce
        FFMA_ACC_F0      R0, R15, R12   # 0x02d2
        FFMA_F0          R5, R15, R5, R11   # 0x02d4
        LD_LOCAL         R11, 80   # 0x02d8
        LD_SHARED        R11, R11, 0   # 0x02dc
        LD_LOCAL         R12, 84   # 0x02e0
        LD_SHARED        R12, R12, 0   # 0x02e4
        LD_LOCAL         R14, 88   # 0x02e8
        LD_SHARED        R15, R14, 0   # 0x02ec
        FFMA_ACC_F0      R5, R15, R12   # 0x02f0
        FFMA_ACC_F0      R0, R15, R11   # 0x02f2
        LD_LOCAL         R14, 136   # 0x02f4
        LD_SHARED        R15, R14, 0   # 0x02f8
        FFMA_F0          R12, R15, R12, R13   # 0x02fc
        FFMA_ACC_F0      R2, R15, R11   # 0x0300
        LD_LOCAL         R11, 72   # 0x0302
        LD_SHARED        R11, R11, 0   # 0x0306
        LD_LOCAL         R13, 68   # 0x030a
        LD_SHARED        R13, R13, 0   # 0x030e
        LD_LOCAL         R14, 132   # 0x0312
        LD_SHARED        R15, R14, 0   # 0x0316
        FFMA_ACC_F0      R2, R15, R13   # 0x031a
        FFMA_ACC_F0      R12, R15, R11   # 0x031c
        LD_LOCAL         R14, 76   # 0x031e
        LD_SHARED        R15, R14, 0   # 0x0322
        FFMA_ACC_F0      R0, R15, R13   # 0x0326
        FFMA_ACC_F0      R5, R15, R11   # 0x0328
        LD_LOCAL         R11, 56   # 0x032a
        LD_SHARED        R11, R11, 0   # 0x032e
        LD_LOCAL         R13, 60   # 0x0332
        LD_SHARED        R13, R13, 0   # 0x0336
        LD_LOCAL         R14, 64   # 0x033a
        LD_SHARED        R15, R14, 0   # 0x033e
        FFMA_ACC_F0      R5, R15, R13   # 0x0342
        FFMA_ACC_F0      R0, R15, R11   # 0x0344
        LD_LOCAL         R14, 128   # 0x0346
        LD_SHARED        R15, R14, 0   # 0x034a
        FFMA_ACC_F0      R12, R15, R13   # 0x034e
        FFMA_ACC_F0      R2, R15, R11   # 0x0350
        LD_LOCAL         R11, 48   # 0x0352
        LD_SHARED        R11, R11, 0   # 0x0356
        LD_LOCAL         R13, 44   # 0x035a
        LD_SHARED        R13, R13, 0   # 0x035e
        LD_LOCAL         R14, 124   # 0x0362
        LD_SHARED        R15, R14, 0   # 0x0366
        FFMA_ACC_F0      R2, R15, R13   # 0x036a
        FFMA_ACC_F0      R12, R15, R11   # 0x036c
        LD_LOCAL         R14, 52   # 0x036e
        LD_SHARED        R15, R14, 0   # 0x0372
        FFMA_ACC_F0      R0, R15, R13   # 0x0376
        FFMA_ACC_F0      R5, R15, R11   # 0x0378
        LD_LOCAL         R11, 32   # 0x037a
        LD_SHARED        R11, R11, 0   # 0x037e
        LD_LOCAL         R13, 36   # 0x0382
        LD_SHARED        R13, R13, 0   # 0x0386
        LD_LOCAL         R14, 40   # 0x038a
        LD_SHARED        R15, R14, 0   # 0x038e
        FFMA_ACC_F0      R5, R15, R13   # 0x0392
        FFMA_ACC_F0      R0, R15, R11   # 0x0394
        LD_LOCAL         R14, 120   # 0x0396
        LD_SHARED        R15, R14, 0   # 0x039a
        FFMA_F0          R13, R15, R13, R12   # 0x039e
        FFMA_ACC_F0      R2, R15, R11   # 0x03a2
        LD_LOCAL         R11, 20   # 0x03a4
        LD_SHARED        R11, R11, 0   # 0x03a8
        LD_LOCAL         R12, 16   # 0x03ac
        LD_SHARED        R14, R12, 0   # 0x03b0
        LD_LOCAL         R12, 116   # 0x03b4
        LD_SHARED        R15, R12, 0   # 0x03b8
        FFMA_F0          R12, R15, R14, R2   # 0x03bc
        FFMA_F0          R15, R15, R11, R13   # 0x03c0
        LD_LOCAL         R2, 28   # 0x03c4
        LD_SHARED        R13, R2, 0   # 0x03c8
        FFMA_F0          R2, R13, R14, R0   # 0x03cc
        FFMA_F0          R11, R13, R11, R5   # 0x03d0
        C_ADD            R7, R3   # 0x03d4
        C_ADD            R8, R3   # 0x03d6
        C_ADD            R9, R3   # 0x03d8
        C_ADD            R10, R3   # 0x03da
        ADDI_P           R4, 3, R4, 8   # 0x03dc
        SHFL_IDX         R4, 7, R4, 0   # 0x03e0
        LD_LOCAL         R13, 12   # 0x03e4
        SETP_LT_NP       P0, R0, R4, R13   # 0x03e8
        C_BAR_ARRIVE     0   # 0x03ec
        C_BAR_WAIT       0   # 0x03ee
        C_MOV            R14, R1   # 0x03f0
        BRA_PRED         4, L0512   # 0x03f2
L03f6:  MOVI             R0, 63   # 0x03f6
        SETP_LT_U_NP     P0, R5, R0, R6   # 0x03fa
        BRA_PRED         0, L044e   # 0x03fe
        LD_LOCAL         R0, 148   # 0x0402
        ADD              R5, R0, R4, R0   # 0x0406
        C_SHLI           R5, 2   # 0x040a
        MOVI             R0, 2   # 0x040c
        LD_GLOBAL        R13, R0, 44   # 0x0410
        ADD              R5, R13, R5, R13   # 0x0414
        LD_GLOBAL_SLOT   R5, 1, R5, 0, 0   # 0x0418
        LD_LOCAL         R0, 152   # 0x041c
        ST_SHARED        R5, R0, 0   # 0x0420
        SETP_LT_U_NPI    P0, R5, R6, 32   # 0x0424
        BRA_PRED         4, L044e   # 0x0428
        LD_LOCAL         R0, 160   # 0x042c
        ADD              R5, R0, R4, R0   # 0x0430
        C_SHLI           R5, 2   # 0x0434
        MOVI             R0, 2   # 0x0436
        LD_GLOBAL        R13, R0, 44   # 0x043a
        ADD              R5, R13, R5, R13   # 0x043e
        LD_GLOBAL_SLOT   R5, 1, R5, 0, 0   # 0x0442
        LD_LOCAL         R0, 164   # 0x0446
        ST_SHARED        R5, R0, 0   # 0x044a
L044e:  C_MOV            R1, R14   # 0x044e
        MOVI             R0, 127   # 0x0450
        SETP_LT_U_NP     P0, R5, R0, R6   # 0x0454
        BRA_PRED         0, L027c   # 0x0458
        LD_LOCAL         R0, 144   # 0x045c
        ADD              R5, R0, R7, R0   # 0x0460
        C_SHLI           R5, 2   # 0x0464
        MOVI             R0, 2   # 0x0466
        LD_GLOBAL        R13, R0, 52   # 0x046a
        ADD              R5, R13, R5, R13   # 0x046e
        LD_GLOBAL_SLOT   R5, 2, R5, 0, 0   # 0x0472
        LD_LOCAL         R0, 156   # 0x0476
        ST_SHARED        R5, R0, 0   # 0x047a
        SETP_LT_U_NPI    P0, R5, R6, 96   # 0x047e
        BRA_PRED         4, L027c   # 0x0482
        LD_LOCAL         R0, 144   # 0x0486
        C_ADD            R0, R8   # 0x048a
        C_SHLI           R0, 2   # 0x048c
        MOVI             R5, 2   # 0x048e
        LD_GLOBAL        R5, R5, 52   # 0x0492
        ADD              R0, R5, R0, R5   # 0x0496
        LD_GLOBAL_SLOT   R0, 2, R0, 0, 0   # 0x049a
        LD_LOCAL         R5, 168   # 0x049e
        ST_SHARED        R0, R5, 0   # 0x04a2
        MOVI             R0, 63   # 0x04a6
        SETP_LT_U_NP     P0, R0, R0, R6   # 0x04aa
        BRA_PRED         0, L027c   # 0x04ae
        LD_LOCAL         R0, 144   # 0x04b2
        C_ADD            R0, R9   # 0x04b6
        C_SHLI           R0, 2   # 0x04b8
        MOVI             R5, 2   # 0x04ba
        LD_GLOBAL        R5, R5, 52   # 0x04be
        ADD              R0, R5, R0, R5   # 0x04c2
        LD_GLOBAL_SLOT   R0, 2, R0, 0, 0   # 0x04c6
        LD_LOCAL         R5, 172   # 0x04ca
        ST_SHARED        R0, R5, 0   # 0x04ce
        MOVI             R0, 31   # 0x04d2
        SETP_LT_U_NP     P0, R0, R0, R6   # 0x04d6
        BRA_PRED         0, L027c   # 0x04da
        LD_LOCAL         R0, 144   # 0x04de
        C_ADD            R0, R10   # 0x04e2
        C_SHLI           R0, 2   # 0x04e4
        MOVI             R5, 2   # 0x04e6
        LD_GLOBAL        R5, R5, 52   # 0x04ea
        ADD              R0, R5, R0, R5   # 0x04ee
        LD_GLOBAL_SLOT   R0, 2, R0, 0, 0   # 0x04f2
        LD_LOCAL         R5, 188   # 0x04f6
        ST_SHARED        R0, R5, 0   # 0x04fa
        BRA              L027c   # 0x04fe
L0502:  MOVI             R12, 0   # 0x0502
        MOVI             R15, 0   # 0x0506
        MOVI             R2, 0   # 0x050a
        MOVI             R11, 0   # 0x050e
L0512:  LD_LOCAL         R0, 180   # 0x0512
        LD_LOCAL         R1, 184   # 0x0516
        OR               R0, R1, R0, R1   # 0x051a
        LD_LOCAL         R1, 176   # 0x051e
        C_ADD            R1, R14   # 0x0522
        MADLO            R3, R1, R13, R0   # 0x0524
        C_SHLI           R3, 2   # 0x0528
        MOVI             R4, 2   # 0x052a
        LD_GLOBAL_P      R4, 3, R4, 36   # 0x052e
        SHFL_IDX         R4, 7, R4, 0   # 0x0532
        ADD              R3, R4, R3, R4   # 0x0536
        ST_GLOBAL_SLOT   R11, 0, R3, 0, 0   # 0x053a
        C_ADDI           R3, 4   # 0x053e
        ST_GLOBAL_SLOT   R2, 0, R3, 0, 0   # 0x0540
        C_ORI            R1, 1   # 0x0544
        MAD_ACC          R0, R1, R13   # 0x0546
        C_SHLI           R0, 2   # 0x0548
        ADD              R0, R4, R0, R4   # 0x054a
        ST_GLOBAL_SLOT   R15, 0, R0, 0, 0   # 0x054e
        C_ADDI           R0, 4   # 0x0552
        ST_GLOBAL_SLOT   R12, 0, R0, 0, 0   # 0x0554
        C_EXIT           0   # 0x0558
