# coremark-derived-pl: test/coremark-derived -DCCV_SEED_PER_LANE, compiled; ccv-as source, reassembled
# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base
# (0x1000: function pointers are absolute); the kernel's entry is 0x332c.
        ST_LOCAL         R14, 36   # 0x0000
        ST_LOCAL         R4, 32   # 0x0004
        C_MOV            R14, R3   # 0x0008
        C_MOV            R7, R2   # 0x000a
        MOVI48           R0, 3435973837   # 0x000c
        MUL_HI_U         R3, R1, R0, R1   # 0x0012
        C_SHRI           R3, 4   # 0x0016
        ADDI             R4, R3, -2   # 0x0018
        C_MOV            R0, R4   # 0x001c
        C_SHLI           R0, 4   # 0x001e
        ADD              R10, R14, R0, R14   # 0x0020
        SHLI             R5, R7, 16   # 0x0024
        ADD              R15, R5, R10, R5   # 0x0028
        OR               R0, R5, R10, R5   # 0x002c
        C_ANDN           R0, R15   # 0x0030
        AND              R2, R5, R10, R5   # 0x0032
        OR               R0, R2, R0, R2   # 0x0036
        C_MOV            R2, R4   # 0x003a
        ST_GLOBAL_IDX    R15, R7, R14, 0, 8   # 0x003c
        SHRI             R0, R0, 31   # 0x0040
        SHRI             R6, R7, 16   # 0x0044
        ST_LOCAL         R0, 12   # 0x0048
        ADD              R8, R6, R0, R6   # 0x004c
        ST_GLOBAL_IDX    R8, R7, R14, 0, 12   # 0x0050
        MOVI             R13, 0   # 0x0054
        ST_GLOBAL_IDX    R13, R7, R14, 0, 4   # 0x0058
        ST_GLOBAL_IDX    R13, R7, R14, 0, 0   # 0x005c
        MOVI             R0, 32896   # 0x0060
        SZ_GLOBAL_ST_16  R0, R7, R10, 0, 0   # 0x0064
        SZ_GLOBAL_ST_16  R13, R7, R10, 0, 2   # 0x0068
        SETP_LT_U_NPI    P0, R0, R2, 3   # 0x006c
        BRA_PRED         0, L00e8   # 0x0070
        ADDI             R0, R14, 16   # 0x0074
        ADD              R4, R5, R0, R5   # 0x0078
        OR               R9, R5, R0, R5   # 0x007c
        C_ANDN           R9, R4   # 0x0080
        AND              R11, R5, R0, R5   # 0x0082
        OR               R9, R11, R9, R11   # 0x0086
        MOVI             R11, 0   # 0x008a
        ST_GLOBAL_IDX    R11, R7, R14, 0, 20   # 0x008e
        ST_GLOBAL_IDX    R11, R7, R14, 0, 16   # 0x0092
        ST_GLOBAL_IDX    R4, R7, R14, 0, 0   # 0x0096
        SHRI             R4, R9, 31   # 0x009a
        ADD              R4, R6, R4, R6   # 0x009e
        ST_GLOBAL_IDX    R4, R7, R14, 0, 4   # 0x00a2
        ADDI             R4, R10, 4   # 0x00a6
        ADD              R9, R5, R4, R5   # 0x00aa
        ST_GLOBAL_IDX    R9, R7, R14, 0, 24   # 0x00ae
        OR               R11, R5, R4, R5   # 0x00b2
        ANDN             R9, R11, R9, R11   # 0x00b6
        AND              R4, R5, R4, R5   # 0x00ba
        C_OR             R4, R9   # 0x00be
        SHRI             R4, R4, 31   # 0x00c0
        ADD              R4, R6, R4, R6   # 0x00c4
        ST_GLOBAL_IDX    R4, R7, R14, 0, 28   # 0x00c8
        MOVI             R4, 32767   # 0x00cc
        SZ_GLOBAL_ST_16  R4, R7, R10, 0, 6   # 0x00d0
        MOVI             R4, 65535   # 0x00d4
        SZ_GLOBAL_ST_16  R4, R7, R10, 0, 4   # 0x00d8
        ADDI             R12, R14, 32   # 0x00dc
        ADDI             R4, R10, 8   # 0x00e0
        C_MOV            R13, R7   # 0x00e4
        C_BRA            L00f4   # 0x00e6
L00e8:  ADDI             R12, R14, 16   # 0x00e8
        ADDI             R4, R10, 4   # 0x00ec
        MOVI             R0, 0   # 0x00f0
L00f4:  SETP_EQ_NPI      P0, R9, R2, 0   # 0x00f4
        ST_LOCAL         R2, 40   # 0x00f8
        BRA_PRED         0, L04fe   # 0x00fc
        ST_LOCAL         R10, 16   # 0x0100
        MOVI             R9, 0   # 0x0104
        C_ANDI           R3, 1   # 0x0108
        ADDI             R1, R1, -60   # 0x010a
        SETP_LT_U_NPI    P0, R1, R1, 20   # 0x010e
        C_MOV            R1, R2   # 0x0112
        C_SHLI           R1, 2   # 0x0114
        ST_LOCAL         R1, 20   # 0x0116
        BRA_PRED         4, L0132   # 0x011a
        MOVI             R11, 0   # 0x011e
        MOVI             R1, 0   # 0x0122
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x0126
        BRA_PRED         4, L03ce   # 0x012a
        BRA              L0502   # 0x012e
L0132:  ST_LOCAL         R3, 44   # 0x0132
        MOVI             R1, 0   # 0x0136
        ANDI             R2, R2, -2   # 0x013a
        ST_LOCAL         R2, 24   # 0x013e
        ST_LOCAL         R8, 28   # 0x0142
        C_BRA            L015a   # 0x0146
L0148:  C_MOV            R4, R11   # 0x0148
        C_MOV            R12, R9   # 0x014a
L014c:  C_ADDI           R1, 2   # 0x014c
        LD_LOCAL         R2, 24   # 0x014e
        SETP_EQ_NP       P0, R2, R2, R1   # 0x0152
        BRA_PRED         0, L03be   # 0x0156
L015a:  ADDI             R9, R12, 16   # 0x015a
        AND              R3, R5, R9, R5   # 0x015e
        ADD              R11, R5, R9, R5   # 0x0162
        OR               R10, R5, R9, R5   # 0x0166
        C_ANDN           R10, R11   # 0x016a
        C_OR             R3, R10   # 0x016c
        SHRI             R3, R3, 31   # 0x016e
        LD_LOCAL         R2, 12   # 0x0172
        SETP_EQ_NP       P0, R10, R3, R2   # 0x0176
        ADD              R3, R6, R3, R6   # 0x017a
        SETP_LT_U_NP     P1, R10, R11, R15   # 0x017e
        SETP_LT_U_NP     P2, R3, R3, R8   # 0x0182
        BRA_PRED         2, L0190   # 0x0186
        PAND             P0, 0, 1   # 0x018a
        BRA_PRED         4, L01ea   # 0x018c
L0190:  LD_LOCAL         R2, 16   # 0x0190
        LD_LOCAL         R3, 20   # 0x0194
        ADD              R3, R2, R3, R2   # 0x0198
        ADD              R10, R5, R3, R5   # 0x019c
        OR               R11, R5, R3, R5   # 0x01a0
        C_ANDN           R11, R10   # 0x01a4
        AND              R3, R5, R3, R5   # 0x01a6
        C_OR             R3, R11   # 0x01aa
        ADDI             R11, R4, 4   # 0x01ac
        ADD              R2, R5, R11, R5   # 0x01b0
        SETP_LT_U_NP     P0, R10, R2, R10   # 0x01b4
        OR               R10, R5, R11, R5   # 0x01b8
        ANDN             R2, R10, R2, R10   # 0x01bc
        AND              R10, R5, R11, R5   # 0x01c0
        OR               R2, R10, R2, R10   # 0x01c4
        SHRI             R2, R2, 31   # 0x01c8
        SHRI             R3, R3, 31   # 0x01cc
        SETP_EQ_NP       P1, R10, R2, R3   # 0x01d0
        ADD              R2, R6, R2, R6   # 0x01d4
        ADD              R3, R6, R3, R6   # 0x01d8
        SETP_LT_U_NP     P2, R2, R2, R3   # 0x01dc
        BRA_PRED         2, L01f0   # 0x01e0
        PAND             P0, 1, 0   # 0x01e4
        BRA_PRED         0, L01f0   # 0x01e6
L01ea:  C_MOV            R11, R4   # 0x01ea
        C_MOV            R9, R12   # 0x01ec
        C_BRA            L028a   # 0x01ee
L01f0:  LD_LOCAL         R2, 32   # 0x01f0
        XOR              R2, R1, R2, R1   # 0x01f4
        C_SHLI           R2, 3   # 0x01f8
        ANDI             R2, R2, 120   # 0x01fa
        ANDI             R3, R1, 6   # 0x01fe
        C_OR             R2, R3   # 0x0202
        MULI             R2, R2, 257   # 0x0204
        SHLI             R3, R13, 16   # 0x0208
        AND              R10, R3, R0, R3   # 0x020c
        ADD              R8, R3, R0, R3   # 0x0210
        OR               R0, R3, R0, R3   # 0x0214
        C_ANDN           R0, R8   # 0x0218
        OR               R0, R10, R0, R10   # 0x021a
        SHRI             R0, R0, 31   # 0x021e
        SHRI             R3, R13, 16   # 0x0222
        ADD              R0, R3, R0, R3   # 0x0226
        ST_GLOBAL_IDX    R8, R7, R12, 0, 0   # 0x022a
        ST_GLOBAL_IDX    R0, R7, R12, 0, 4   # 0x022e
        ADD              R0, R5, R12, R5   # 0x0232
        OR               R3, R5, R12, R5   # 0x0236
        C_ANDN           R3, R0   # 0x023a
        AND              R8, R5, R12, R5   # 0x023c
        OR               R3, R8, R3, R8   # 0x0240
        SHRI             R3, R3, 31   # 0x0244
        ADD              R3, R6, R3, R6   # 0x0248
        ST_GLOBAL_IDX    R3, R7, R14, 0, 4   # 0x024c
        ST_GLOBAL_IDX    R0, R7, R14, 0, 0   # 0x0250
        ADD              R0, R5, R4, R5   # 0x0254
        OR               R3, R5, R4, R5   # 0x0258
        C_ANDN           R3, R0   # 0x025c
        AND              R8, R5, R4, R5   # 0x025e
        OR               R3, R8, R3, R8   # 0x0262
        LD_LOCAL         R8, 28   # 0x0266
        SHRI             R3, R3, 31   # 0x026a
        ADD              R3, R6, R3, R6   # 0x026e
        ST_GLOBAL_IDX    R3, R7, R12, 0, 12   # 0x0272
        ST_GLOBAL_IDX    R0, R7, R12, 0, 8   # 0x0276
        MOVI             R0, 32767   # 0x027a
        SZ_GLOBAL_ST_16  R0, R7, R4, 0, 2   # 0x027e
        SZ_GLOBAL_ST_16  R2, R7, R4, 0, 0   # 0x0282
        C_MOV            R13, R7   # 0x0286
        C_MOV            R0, R12   # 0x0288
L028a:  ADDI             R12, R9, 16   # 0x028a
        AND              R2, R5, R12, R5   # 0x028e
        ADD              R3, R5, R12, R5   # 0x0292
        OR               R4, R5, R12, R5   # 0x0296
        C_ANDN           R4, R3   # 0x029a
        C_OR             R2, R4   # 0x029c
        SHRI             R2, R2, 31   # 0x029e
        LD_LOCAL         R4, 12   # 0x02a2
        SETP_EQ_NP       P0, R4, R2, R4   # 0x02a6
        ADD              R2, R6, R2, R6   # 0x02aa
        SETP_LT_U_NP     P1, R3, R3, R15   # 0x02ae
        SETP_LT_U_NP     P2, R2, R2, R8   # 0x02b2
        BRA_PRED         2, L02c0   # 0x02b6
        PAND             P0, 0, 1   # 0x02ba
        BRA_PRED         4, L0148   # 0x02bc
L02c0:  LD_LOCAL         R2, 16   # 0x02c0
        LD_LOCAL         R3, 20   # 0x02c4
        C_ADD            R2, R3   # 0x02c8
        ADD              R3, R5, R2, R5   # 0x02ca
        OR               R4, R5, R2, R5   # 0x02ce
        C_ANDN           R4, R3   # 0x02d2
        AND              R2, R5, R2, R5   # 0x02d4
        C_OR             R2, R4   # 0x02d8
        ADDI             R4, R11, 4   # 0x02da
        ADD              R8, R5, R4, R5   # 0x02de
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x02e2
        OR               R3, R5, R4, R5   # 0x02e6
        C_ANDN           R3, R8   # 0x02ea
        AND              R8, R5, R4, R5   # 0x02ec
        OR               R3, R8, R3, R8   # 0x02f0
        SHRI             R3, R3, 31   # 0x02f4
        SHRI             R2, R2, 31   # 0x02f8
        SETP_EQ_NP       P1, R8, R3, R2   # 0x02fc
        ADD              R3, R6, R3, R6   # 0x0300
        ADD              R2, R6, R2, R6   # 0x0304
        SETP_LT_U_NP     P2, R2, R3, R2   # 0x0308
        BRA_PRED         2, L031c   # 0x030c
        PAND             P0, 1, 0   # 0x0310
        BRA_PRED         0, L031c   # 0x0312
        C_MOV            R4, R11   # 0x0316
        C_MOV            R12, R9   # 0x0318
        C_BRA            L03b6   # 0x031a
L031c:  ORI              R2, R1, 1   # 0x031c
        LD_LOCAL         R3, 32   # 0x0320
        XOR              R3, R2, R3, R2   # 0x0324
        C_SHLI           R3, 3   # 0x0328
        ANDI             R3, R3, 120   # 0x032a
        C_ANDI           R2, 7   # 0x032e
        OR               R2, R3, R2, R3   # 0x0330
        MULI             R2, R2, 257   # 0x0334
        SHLI             R3, R13, 16   # 0x0338
        AND              R8, R3, R0, R3   # 0x033c
        ADD              R10, R3, R0, R3   # 0x0340
        OR               R0, R3, R0, R3   # 0x0344
        C_ANDN           R0, R10   # 0x0348
        OR               R0, R8, R0, R8   # 0x034a
        SHRI             R0, R0, 31   # 0x034e
        SHRI             R3, R13, 16   # 0x0352
        ADD              R0, R3, R0, R3   # 0x0356
        ST_GLOBAL_IDX    R10, R7, R9, 0, 0   # 0x035a
        ST_GLOBAL_IDX    R0, R7, R9, 0, 4   # 0x035e
        ADD              R0, R5, R9, R5   # 0x0362
        OR               R3, R5, R9, R5   # 0x0366
        C_ANDN           R3, R0   # 0x036a
        AND              R8, R5, R9, R5   # 0x036c
        OR               R3, R8, R3, R8   # 0x0370
        SHRI             R3, R3, 31   # 0x0374
        ADD              R3, R6, R3, R6   # 0x0378
        ST_GLOBAL_IDX    R3, R7, R14, 0, 4   # 0x037c
        ST_GLOBAL_IDX    R0, R7, R14, 0, 0   # 0x0380
        ADD              R0, R5, R11, R5   # 0x0384
        OR               R3, R5, R11, R5   # 0x0388
        C_ANDN           R3, R0   # 0x038c
        AND              R8, R5, R11, R5   # 0x038e
        OR               R3, R8, R3, R8   # 0x0392
        SHRI             R3, R3, 31   # 0x0396
        ADD              R3, R6, R3, R6   # 0x039a
        ST_GLOBAL_IDX    R3, R7, R9, 0, 12   # 0x039e
        ST_GLOBAL_IDX    R0, R7, R9, 0, 8   # 0x03a2
        MOVI             R0, 32767   # 0x03a6
        SZ_GLOBAL_ST_16  R0, R7, R11, 0, 2   # 0x03aa
        SZ_GLOBAL_ST_16  R2, R7, R11, 0, 0   # 0x03ae
        C_MOV            R13, R7   # 0x03b2
        C_MOV            R0, R9   # 0x03b4
L03b6:  LD_LOCAL         R8, 28   # 0x03b6
        BRA              L014c   # 0x03ba
L03be:  C_MOV            R9, R13   # 0x03be
        C_MOV            R11, R0   # 0x03c0
        LD_LOCAL         R3, 44   # 0x03c2
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x03c6
        BRA_PRED         0, L0502   # 0x03ca
L03ce:  LD_LOCAL         R2, 16   # 0x03ce
        LD_LOCAL         R3, 20   # 0x03d2
        ADD              R3, R2, R3, R2   # 0x03d6
        ADD              R9, R5, R3, R5   # 0x03da
        OR               R10, R5, R3, R5   # 0x03de
        C_ANDN           R10, R9   # 0x03e2
        AND              R3, R5, R3, R5   # 0x03e4
        C_OR             R3, R10   # 0x03e8
        ADDI             R10, R4, 4   # 0x03ea
        ADD              R11, R5, R10, R5   # 0x03ee
        SETP_LT_U_NP     P0, R9, R11, R9   # 0x03f2
        ST_PRED_LOCAL    1, 16   # 0x03f6
        OR               R9, R5, R10, R5   # 0x03fa
        C_ANDN           R9, R11   # 0x03fe
        AND              R10, R5, R10, R5   # 0x0400
        OR               R9, R10, R9, R10   # 0x0404
        SHRI             R9, R9, 31   # 0x0408
        SHRI             R3, R3, 31   # 0x040c
        SETP_EQ_NP       P0, R10, R9, R3   # 0x0410
        ST_PRED_LOCAL    1, 20   # 0x0414
        ADD              R9, R6, R9, R6   # 0x0418
        ADD              R3, R6, R3, R6   # 0x041c
        SETP_LT_U_NP     P2, R3, R9, R3   # 0x0420
        ADDI             R3, R12, 16   # 0x0424
        ADD              R9, R5, R3, R5   # 0x0428
        SETP_LE_U_NP     P0, R15, R15, R9   # 0x042c
        OR               R15, R5, R3, R5   # 0x0430
        C_ANDN           R15, R9   # 0x0434
        AND              R3, R5, R3, R5   # 0x0436
        C_OR             R3, R15   # 0x043a
        SHRI             R3, R3, 31   # 0x043c
        LD_LOCAL         R2, 12   # 0x0440
        SETP_NE_NP       P1, R15, R3, R2   # 0x0444
        POR              P0, 1, 0   # 0x0448
        ADD              R3, R6, R3, R6   # 0x044a
        SETP_LE_U_NP     P1, R2, R8, R3   # 0x044e
        PAND             P0, 1, 0   # 0x0452
        BRA_PRED         0, L04fe   # 0x0454
        LD_PRED_LOCAL    1, 16   # 0x0458
        LD_PRED_LOCAL    2, 16   # 0x045c
        PAND             P0, 1, 0   # 0x0460
        POR              P0, 2, 0   # 0x0462
        BRA_PRED         4, L04fe   # 0x0464
        SHLI             R2, R13, 16   # 0x0468
        AND              R3, R2, R0, R2   # 0x046c
        ADD              R15, R2, R0, R2   # 0x0470
        OR               R0, R2, R0, R2   # 0x0474
        C_ANDN           R0, R15   # 0x0478
        OR               R0, R3, R0, R3   # 0x047a
        SHRI             R0, R0, 31   # 0x047e
        SHRI             R2, R13, 16   # 0x0482
        ADD              R0, R2, R0, R2   # 0x0486
        ST_GLOBAL_IDX    R15, R7, R12, 0, 0   # 0x048a
        ST_GLOBAL_IDX    R0, R7, R12, 0, 4   # 0x048e
        ADD              R0, R5, R12, R5   # 0x0492
        OR               R2, R5, R12, R5   # 0x0496
        C_ANDN           R2, R0   # 0x049a
        AND              R3, R5, R12, R5   # 0x049c
        OR               R2, R3, R2, R3   # 0x04a0
        SHRI             R2, R2, 31   # 0x04a4
        ADD              R2, R6, R2, R6   # 0x04a8
        ST_GLOBAL_IDX    R2, R7, R14, 0, 4   # 0x04ac
        ST_GLOBAL_IDX    R0, R7, R14, 0, 0   # 0x04b0
        ADD              R0, R5, R4, R5   # 0x04b4
        OR               R2, R5, R4, R5   # 0x04b8
        C_ANDN           R2, R0   # 0x04bc
        AND              R3, R5, R4, R5   # 0x04be
        OR               R2, R3, R2, R3   # 0x04c2
        SHRI             R2, R2, 31   # 0x04c6
        ADD              R2, R6, R2, R6   # 0x04ca
        ST_GLOBAL_IDX    R2, R7, R12, 0, 12   # 0x04ce
        ST_GLOBAL_IDX    R0, R7, R12, 0, 8   # 0x04d2
        MOVI             R0, 32767   # 0x04d6
        SZ_GLOBAL_ST_16  R0, R7, R4, 0, 2   # 0x04da
        LD_LOCAL         R0, 32   # 0x04de
        XOR              R0, R1, R0, R1   # 0x04e2
        C_SHLI           R0, 3   # 0x04e6
        ANDI             R0, R0, 120   # 0x04e8
        C_ANDI           R1, 7   # 0x04ec
        C_OR             R0, R1   # 0x04ee
        MULI             R0, R0, 257   # 0x04f0
        SZ_GLOBAL_ST_16  R0, R7, R4, 0, 0   # 0x04f4
        C_MOV            R9, R7   # 0x04f8
        C_MOV            R11, R12   # 0x04fa
        C_BRA            L0502   # 0x04fc
L04fe:  C_MOV            R9, R13   # 0x04fe
        C_MOV            R11, R0   # 0x0500
L0502:  LD_GLOBAL_IDX    R1, R9, R11, 0, 4   # 0x0502
        LD_GLOBAL_IDX    R0, R9, R11, 0, 0   # 0x0506
        MOVI             R5, 65535   # 0x050a
        AND              R2, R1, R5, R1   # 0x050e
        OR               R2, R0, R2, R0   # 0x0512
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x0516
        LD_LOCAL         R10, 32   # 0x051a
        BRA_PRED         0, L05b0   # 0x051e
        SHRI             R2, R0, 16   # 0x0522
        SHLI             R1, R1, 16   # 0x0526
        OR               R15, R1, R2, R1   # 0x052a
        AND              R8, R0, R5, R0   # 0x052e
        MOVI48           R0, 3435973837   # 0x0532
        LD_LOCAL         R1, 40   # 0x0538
        MUL_HI_U         R0, R1, R0, R1   # 0x053c
        MOVI             R3, 1   # 0x0540
        C_SHRI           R0, 2   # 0x0544
        MOVI             R1, 16383   # 0x0546
        C_BRA            L058e   # 0x054a
L054c:  LD_GLOBAL_IDX    R15, R9, R11, 0, 8   # 0x054c
        LD_GLOBAL_IDX    R8, R9, R11, 0, 12   # 0x0550
        SHLI             R8, R8, 16   # 0x0554
        SHRI             R9, R15, 16   # 0x0558
        C_OR             R8, R9   # 0x055c
        C_AND            R15, R5   # 0x055e
        SZ_GLOBAL_ST_16  R3, R8, R15, 0, 2   # 0x0560
        LD_GLOBAL_IDX    R3, R4, R2, 0, 4   # 0x0564
        LD_GLOBAL_IDX    R8, R4, R2, 0, 0   # 0x0568
        SHRI             R15, R8, 16   # 0x056c
        SHLI             R9, R3, 16   # 0x0570
        OR               R15, R9, R15, R9   # 0x0574
        C_AND            R3, R5   # 0x0578
        OR               R3, R8, R3, R8   # 0x057a
        C_AND            R8, R5   # 0x057e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0580
        C_MOV            R9, R4   # 0x0584
        C_MOV            R11, R2   # 0x0586
        C_MOV            R3, R6   # 0x0588
        BRA_PRED         4, L05b0   # 0x058a
L058e:  C_MOV            R2, R8   # 0x058e
        C_MOV            R4, R15   # 0x0590
        SETP_LT_U_NP     P0, R6, R3, R0   # 0x0592
        ADDI             R6, R3, 1   # 0x0596
        BRA_PRED         0, L054c   # 0x059a
        C_XOR            R3, R10   # 0x059e
        C_AND            R3, R1   # 0x05a0
        C_MOV            R15, R6   # 0x05a2
        C_SHLI           R15, 8   # 0x05a4
        ANDI             R15, R15, 1792   # 0x05a6
        OR               R3, R15, R3, R15   # 0x05aa
        C_BRA            L054c   # 0x05ae
L05b0:  MOVI             R10, 1   # 0x05b0
        MOVI             R6, 0   # 0x05b4
        C_BRA            L05dc   # 0x05b8
L05ba:  ST_GLOBAL_IDX    R6, R4, R1, 0, 4   # 0x05ba
        ST_GLOBAL_IDX    R6, R4, R1, 0, 0   # 0x05be
        C_SHLI           R10, 1   # 0x05c2
        LD_LOCAL         R0, 20   # 0x05c4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x05c8
        LD_LOCAL         R1, 12   # 0x05cc
        C_MOV            R7, R1   # 0x05d0
        LD_LOCAL         R2, 16   # 0x05d2
        C_MOV            R14, R2   # 0x05d6
        BRA_PRED         4, L081e   # 0x05d8
L05dc:  MOVI             R2, 0   # 0x05dc
        MOVI             R4, 0   # 0x05e0
        MOVI             R1, 0   # 0x05e4
        MOVI             R0, 0   # 0x05e8
        ST_LOCAL         R0, 12   # 0x05ec
        ST_LOCAL         R0, 16   # 0x05f0
        ST_LOCAL         R10, 28   # 0x05f4
        C_BRA            L060a   # 0x05f8
L05fa:  SETP_EQ_NPI      P0, R0, R3, 0   # 0x05fa
        LD_LOCAL         R10, 28   # 0x05fe
        LD_LOCAL         R2, 24   # 0x0602
        BRA_PRED         0, L05ba   # 0x0606
L060a:  ST_LOCAL         R2, 20   # 0x060a
        SETP_LT_NPI      P0, R0, R10, 1   # 0x060e
        BRA_PRED         0, L0654   # 0x0612
        MOVI             R0, 0   # 0x0616
        C_MOV            R3, R7   # 0x061a
        C_MOV            R15, R14   # 0x061c
L061e:  LD_GLOBAL_IDX    R8, R3, R15, 0, 4   # 0x061e
        LD_GLOBAL_IDX    R2, R3, R15, 0, 0   # 0x0622
        AND              R3, R8, R5, R8   # 0x0626
        OR               R3, R2, R3, R2   # 0x062a
        SETP_NE_NPI      P0, R3, R3, 0   # 0x062e
        BRA_PRED         4, L065e   # 0x0632
        SHRI             R3, R2, 16   # 0x0636
        SHLI             R15, R8, 16   # 0x063a
        OR               R3, R15, R3, R15   # 0x063e
        AND              R15, R2, R5, R2   # 0x0642
        C_ADDI           R0, 1   # 0x0646
        SETP_EQ_NP       P0, R2, R10, R0   # 0x0648
        BRA_PRED         4, L061e   # 0x064c
        C_MOV            R9, R10   # 0x0650
        C_BRA            L066a   # 0x0652
L0654:  MOVI             R9, 0   # 0x0654
        C_MOV            R3, R7   # 0x0658
        C_MOV            R15, R14   # 0x065a
        C_BRA            L066a   # 0x065c
L065e:  MOVI             R3, 0   # 0x065e
        ADDI             R9, R0, 1   # 0x0662
        MOVI             R15, 0   # 0x0666
L066a:  LD_LOCAL         R0, 20   # 0x066a
        C_ADDI           R0, 1   # 0x066e
        ST_LOCAL         R0, 24   # 0x0670
        C_MOV            R2, R7   # 0x0674
        C_MOV            R0, R14   # 0x0676
        C_MOV            R7, R3   # 0x0678
        C_MOV            R14, R15   # 0x067a
        C_BRA            L0692   # 0x067c
L067e:  ST_LOCAL         R15, 12   # 0x067e
        ST_LOCAL         R8, 16   # 0x0682
L0686:  C_MOV            R2, R12   # 0x0686
        C_MOV            R0, R11   # 0x0688
        C_MOV            R7, R13   # 0x068a
        C_MOV            R14, R3   # 0x068c
        C_MOV            R4, R15   # 0x068e
        C_MOV            R1, R8   # 0x0690
L0692:  SETP_LT_NP       P0, R3, R6, R9   # 0x0692
        BRA_PRED         0, L06ce   # 0x0696
        SHLI             R3, R7, 16   # 0x069a
        AND              R15, R3, R14, R3   # 0x069e
        ADD              R8, R3, R14, R3   # 0x06a2
        C_OR             R3, R14   # 0x06a6
        C_ANDN           R3, R8   # 0x06a8
        OR               R3, R15, R3, R15   # 0x06aa
        SHRI             R3, R3, 31   # 0x06ae
        SHRI             R15, R7, 16   # 0x06b2
        ADD              R3, R15, R3, R15   # 0x06b6
        OR               R3, R8, R3, R8   # 0x06ba
        SETP_LT_NPI      P0, R15, R10, 1   # 0x06be
        BRA_PRED         0, L05fa   # 0x06c2
        SETP_EQ_NPI      P0, R15, R3, 0   # 0x06c6
        BRA_PRED         0, L05fa   # 0x06ca
L06ce:  SETP_NE_NPI      P0, R3, R9, 0   # 0x06ce
        BRA_PRED         4, L07a0   # 0x06d2
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x06d6
        BRA_PRED         0, L077a   # 0x06da
        SHLI             R3, R7, 16   # 0x06de
        AND              R15, R3, R14, R3   # 0x06e2
        ADD              R8, R3, R14, R3   # 0x06e6
        C_OR             R3, R14   # 0x06ea
        C_ANDN           R3, R8   # 0x06ec
        OR               R3, R15, R3, R15   # 0x06ee
        SHRI             R3, R3, 31   # 0x06f2
        SHRI             R15, R7, 16   # 0x06f6
        ADD              R3, R15, R3, R15   # 0x06fa
        OR               R3, R8, R3, R8   # 0x06fe
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0702
        BRA_PRED         4, L077a   # 0x0706
        LD_GLOBAL_IDX    R3, R2, R0, 0, 8   # 0x070a
        LD_GLOBAL_IDX    R15, R2, R0, 0, 12   # 0x070e
        SHLI             R15, R15, 16   # 0x0712
        SHRI             R8, R3, 16   # 0x0716
        C_OR             R15, R8   # 0x071a
        LD_GLOBAL_IDX    R8, R7, R14, 0, 8   # 0x071c
        LD_GLOBAL_IDX    R11, R7, R14, 0, 12   # 0x0720
        C_AND            R3, R5   # 0x0724
        SZ_GLOBAL_LD_U8  R12, R15, R3, 0, 1   # 0x0726
        SZ_GLOBAL_ST_8   R12, R15, R3, 0, 0   # 0x072a
        SHLI             R11, R11, 16   # 0x072e
        SHRI             R12, R8, 16   # 0x0732
        C_OR             R11, R12   # 0x0736
        C_AND            R8, R5   # 0x0738
        SZ_GLOBAL_LD_U8  R12, R11, R8, 0, 1   # 0x073a
        SZ_GLOBAL_ST_8   R12, R11, R8, 0, 0   # 0x073e
        SZ_GLOBAL_LD_U16 R3, R15, R3, 0, 2   # 0x0742
        SZ_GLOBAL_LD_U16 R15, R11, R8, 0, 2   # 0x0746
        SHLI             R15, R15, 16   # 0x074a
        SRAI             R15, R15, 16   # 0x074e
        SHLI             R3, R3, 16   # 0x0752
        SRAI             R3, R3, 16   # 0x0756
        SETP_LT_NP       P0, R3, R15, R3   # 0x075a
        BRA_PRED         4, L077a   # 0x075e
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x0762
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x0766
        SHLI             R15, R15, 16   # 0x076a
        SHRI             R8, R3, 16   # 0x076e
        OR               R13, R15, R8, R15   # 0x0772
        C_AND            R3, R5   # 0x0776
        C_BRA            L07ba   # 0x0778
L077a:  LD_GLOBAL_IDX    R3, R2, R0, 0, 0   # 0x077a
        LD_GLOBAL_IDX    R15, R2, R0, 0, 4   # 0x077e
        SHLI             R15, R15, 16   # 0x0782
        SHRI             R8, R3, 16   # 0x0786
        OR               R12, R15, R8, R15   # 0x078a
        AND              R11, R3, R5, R3   # 0x078e
        ADDI             R9, R9, -1   # 0x0792
        C_MOV            R13, R7   # 0x0796
        C_MOV            R3, R14   # 0x0798
        C_MOV            R15, R2   # 0x079a
        C_MOV            R8, R0   # 0x079c
        C_BRA            L07c6   # 0x079e
L07a0:  LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x07a0
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x07a4
        SHLI             R15, R15, 16   # 0x07a8
        SHRI             R8, R3, 16   # 0x07ac
        OR               R13, R15, R8, R15   # 0x07b0
        C_AND            R3, R5   # 0x07b4
        MOVI             R9, 0   # 0x07b6
L07ba:  ADDI             R10, R10, -1   # 0x07ba
        C_MOV            R12, R2   # 0x07be
        C_MOV            R11, R0   # 0x07c0
        C_MOV            R15, R7   # 0x07c2
        C_MOV            R8, R14   # 0x07c4
L07c6:  SHLI             R0, R4, 16   # 0x07c6
        AND              R2, R0, R1, R0   # 0x07ca
        ADD              R7, R0, R1, R0   # 0x07ce
        C_OR             R0, R1   # 0x07d2
        C_ANDN           R0, R7   # 0x07d4
        OR               R0, R2, R0, R2   # 0x07d6
        SHRI             R0, R0, 31   # 0x07da
        SHRI             R2, R4, 16   # 0x07de
        ADD              R0, R2, R0, R2   # 0x07e2
        OR               R0, R7, R0, R7   # 0x07e6
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x07ea
        BRA_PRED         0, L067e   # 0x07ee
        SHLI             R0, R15, 16   # 0x07f2
        ADD              R2, R0, R8, R0   # 0x07f6
        ST_GLOBAL_IDX    R2, R4, R1, 0, 0   # 0x07fa
        OR               R7, R0, R8, R0   # 0x07fe
        ANDN             R2, R7, R2, R7   # 0x0802
        C_AND            R0, R8   # 0x0806
        C_OR             R0, R2   # 0x0808
        SHRI             R0, R0, 31   # 0x080a
        SHRI             R2, R15, 16   # 0x080e
        ADD              R0, R2, R0, R2   # 0x0812
        ST_GLOBAL_IDX    R0, R4, R1, 0, 4   # 0x0816
        BRA              L0686   # 0x081a
L081e:  LD_LOCAL         R14, 36   # 0x081e
        C_RET            224   # 0x0822
        ST_LOCAL         R14, 44   # 0x0824
        ST_LOCAL         R6, 48   # 0x0828
        ST_LOCAL         R5, 52   # 0x082c
        ST_LOCAL         R3, 20   # 0x0830
        C_MOV            R0, R1   # 0x0834
        MOVI             R7, 1   # 0x0836
        SETP_LT_U_NP     P0, R1, R7, R4   # 0x083a
        MOV_P            R7, 0, R4, R4, R4   # 0x083e
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0842
        BRA_PRED         0, L086a   # 0x0846
        MOVI48           R15, 4294967295   # 0x084a
        MOVI             R3, 8   # 0x0850
L0854:  ADDI             R4, R15, 2   # 0x0854
        MUL_LO           R4, R3, R4, R4   # 0x0858
        SETP_LT_U_NP     P0, R4, R4, R0   # 0x085c
        C_ADDI           R3, 8   # 0x0860
        C_ADDI           R15, 1   # 0x0862
        BRA_PRED         0, L0854   # 0x0864
        C_BRA            L0870   # 0x0868
L086a:  MOVI48           R15, 4294967295   # 0x086a
L0870:  SHLI             R1, R2, 16   # 0x0870
        LD_LOCAL         R0, 20   # 0x0874
        ADD              R0, R1, R0, R1   # 0x0878
        ST_LOCAL         R1, 56   # 0x087c
        SETP_LT_U_NP     P0, R3, R0, R1   # 0x0880
        SHRI             R3, R2, 16   # 0x0884
        ST_LOCAL         R3, 60   # 0x0888
        ADDI_P           R3, 0, R3, 1   # 0x088c
        C_NEG            R4, R0   # 0x0890
        ANDI             R1, R4, 3   # 0x0892
        ST_LOCAL         R1, 28   # 0x0896
        ADD              R4, R0, R1, R0   # 0x089a
        SETP_LT_U_NP     P0, R0, R4, R0   # 0x089e
        ADDI_P           R3, 0, R3, 1   # 0x08a2
        MUL_LO           R1, R15, R15, R15   # 0x08a6
        SHRI             R0, R1, 31   # 0x08aa
        ADD              R0, R3, R0, R3   # 0x08ae
        C_SHLI           R1, 1   # 0x08b2
        ST_LOCAL         R1, 24   # 0x08b4
        ADD              R3, R4, R1, R4   # 0x08b8
        SETP_LT_U_NP     P0, R3, R3, R4   # 0x08bc
        ADDI_P           R0, 0, R0, 1   # 0x08c0
        SETP_EQ_NPI      P0, R0, R15, 0   # 0x08c4
        BRA_PRED         0, L0a28   # 0x08c8
        LD_LOCAL         R1, 20   # 0x08cc
        C_NEG            R0, R1   # 0x08d0
        C_ANDI           R0, 3   # 0x08d2
        ADD              R9, R1, R0, R1   # 0x08d4
        MOVI             R3, 1   # 0x08d8
        MOVI             R8, 0   # 0x08dc
        C_MOV            R10, R15   # 0x08e0
        C_SHLI           R10, 1   # 0x08e2
        ANDI             R13, R15, -2   # 0x08e4
        ANDI             R11, R15, 1   # 0x08e8
        LD_LOCAL         R0, 24   # 0x08ec
        ADD              R14, R9, R0, R9   # 0x08f0
        MOVI48           R0, 4294901760   # 0x08f4
        MOVI             R12, 0   # 0x08fa
        ST_LOCAL         R15, 32   # 0x08fe
        ST_LOCAL         R10, 36   # 0x0902
        ST_LOCAL         R11, 40   # 0x0906
        C_BRA            L091c   # 0x090a
L090c:  C_ADD            R14, R10   # 0x090c
        C_ADD            R9, R10   # 0x090e
        C_ADD            R8, R15   # 0x0910
        C_ADDI           R12, 1   # 0x0912
        SETP_NE_NP       P0, R1, R12, R15   # 0x0914
        BRA_PRED         4, L0a28   # 0x0918
L091c:  SETP_EQ_NPI      P0, R5, R15, 1   # 0x091c
        BRA_PRED         4, L0932   # 0x0920
        MOVI             R5, 0   # 0x0924
        SETP_EQ_NPI      P0, R1, R11, 0   # 0x0928
        BRA_PRED         0, L090c   # 0x092c
        C_BRA            L09da   # 0x0930
L0932:  ST_LOCAL         R12, 16   # 0x0932
        ST_LOCAL         R8, 12   # 0x0936
        MOVI             R8, 0   # 0x093a
        C_MOV            R10, R3   # 0x093e
        C_SHLI           R10, 1   # 0x0940
        MOVI             R5, 0   # 0x0942
L0946:  ADD              R15, R3, R5, R3   # 0x0946
        MUL_LO           R4, R7, R15, R15   # 0x094a
        SRAI             R12, R4, 31   # 0x094e
        SHRI             R12, R12, 16   # 0x0952
        MADLO            R7, R7, R15, R12   # 0x0956
        C_AND            R7, R0   # 0x095a
        C_SUB            R4, R7   # 0x095c
        ADD              R12, R14, R8, R14   # 0x095e
        ADD              R7, R15, R4, R15   # 0x0962
        SZ_GLOBAL_ST_16  R7, R2, R12, 0, 0   # 0x0966
        ADD              R11, R9, R8, R9   # 0x096a
        ADD              R6, R10, R8, R10   # 0x096e
        ADD              R7, R6, R4, R6   # 0x0972
        ANDI             R7, R7, 255   # 0x0976
        SZ_GLOBAL_ST_16  R7, R2, R11, 0, 0   # 0x097a
        C_ADDI           R15, 1   # 0x097e
        MUL_LO           R7, R4, R15, R15   # 0x0980
        SRAI             R1, R7, 31   # 0x0984
        SHRI             R1, R1, 16   # 0x0988
        MAD_ACC          R1, R4, R15   # 0x098c
        C_AND            R1, R0   # 0x098e
        C_SUB            R7, R1   # 0x0990
        ADDI             R1, R12, 2   # 0x0992
        ADD              R4, R15, R7, R15   # 0x0996
        SZ_GLOBAL_ST_16  R4, R2, R1, 0, 0   # 0x099a
        ADDI             R1, R11, 2   # 0x099e
        ADD              R4, R6, R7, R6   # 0x09a2
        C_ADDI           R4, 2   # 0x09a6
        ANDI             R4, R4, 255   # 0x09a8
        SZ_GLOBAL_ST_16  R4, R2, R1, 0, 0   # 0x09ac
        C_ADDI           R8, 4   # 0x09b0
        C_ADDI           R5, 2   # 0x09b2
        SETP_NE_NP       P0, R1, R13, R5   # 0x09b4
        BRA_PRED         0, L0946   # 0x09b8
        C_ADD            R3, R5   # 0x09bc
        LD_LOCAL         R15, 32   # 0x09be
        LD_LOCAL         R8, 12   # 0x09c2
        LD_LOCAL         R10, 36   # 0x09c6
        LD_LOCAL         R11, 40   # 0x09ca
        LD_LOCAL         R12, 16   # 0x09ce
        SETP_EQ_NPI      P0, R1, R11, 0   # 0x09d2
        BRA_PRED         0, L090c   # 0x09d6
L09da:  MUL_LO           R1, R12, R15, R15   # 0x09da
        MUL_LO           R4, R7, R3, R3   # 0x09de
        SRAI             R6, R4, 31   # 0x09e2
        SHRI             R6, R6, 16   # 0x09e6
        MAD_ACC          R6, R7, R3   # 0x09ea
        C_AND            R6, R0   # 0x09ec
        SUB              R7, R4, R6, R4   # 0x09ee
        LD_LOCAL         R4, 20   # 0x09f2
        LD_LOCAL         R6, 28   # 0x09f6
        C_ADD            R4, R6   # 0x09fa
        ADD              R1, R5, R1, R5   # 0x09fc
        C_SHLI           R1, 1   # 0x0a00
        ADD              R1, R4, R1, R4   # 0x0a02
        LD_LOCAL         R4, 24   # 0x0a06
        ADD              R4, R1, R4, R1   # 0x0a0a
        ADD              R5, R7, R3, R7   # 0x0a0e
        SZ_GLOBAL_ST_16  R5, R2, R4, 0, 0   # 0x0a12
        ADD              R4, R5, R3, R5   # 0x0a16
        ANDI             R4, R4, 255   # 0x0a1a
        SZ_GLOBAL_ST_16  R4, R2, R1, 0, 0   # 0x0a1e
        C_ADDI           R3, 1   # 0x0a22
        BRA              L090c   # 0x0a24
L0a28:  LD_LOCAL         R0, 20   # 0x0a28
        LD_LOCAL         R1, 28   # 0x0a2c
        C_ADD            R0, R1   # 0x0a30
        LD_LOCAL         R7, 56   # 0x0a32
        ADD              R1, R7, R0, R7   # 0x0a36
        OR               R2, R7, R0, R7   # 0x0a3a
        C_ANDN           R2, R1   # 0x0a3e
        AND              R3, R7, R0, R7   # 0x0a40
        OR               R2, R3, R2, R3   # 0x0a44
        LD_LOCAL         R3, 24   # 0x0a48
        C_ADD            R0, R3   # 0x0a4c
        ADD              R3, R0, R3, R0   # 0x0a4e
        ADD              R4, R7, R3, R7   # 0x0a52
        C_NEG            R4, R4   # 0x0a56
        C_ANDI           R4, 3   # 0x0a58
        C_ADD            R3, R4   # 0x0a5a
        ADD              R4, R7, R0, R7   # 0x0a5c
        OR               R5, R7, R0, R7   # 0x0a60
        C_ANDN           R5, R4   # 0x0a64
        AND              R0, R7, R0, R7   # 0x0a66
        C_OR             R0, R5   # 0x0a6a
        LD_LOCAL         R5, 48   # 0x0a6c
        LD_LOCAL         R6, 52   # 0x0a70
        ST_GLOBAL_IDX    R1, R6, R5, 0, 8   # 0x0a74
        ST_GLOBAL_IDX    R4, R6, R5, 0, 16   # 0x0a78
        SHRI             R1, R2, 31   # 0x0a7c
        LD_LOCAL         R2, 60   # 0x0a80
        ADD              R1, R2, R1, R2   # 0x0a84
        ST_GLOBAL_IDX    R1, R6, R5, 0, 12   # 0x0a88
        SHRI             R0, R0, 31   # 0x0a8c
        ADD              R0, R2, R0, R2   # 0x0a90
        ST_GLOBAL_IDX    R0, R6, R5, 0, 20   # 0x0a94
        ADD              R0, R7, R3, R7   # 0x0a98
        ST_GLOBAL_IDX    R0, R6, R5, 0, 24   # 0x0a9c
        OR               R1, R7, R3, R7   # 0x0aa0
        ANDN             R0, R1, R0, R1   # 0x0aa4
        AND              R1, R7, R3, R7   # 0x0aa8
        OR               R0, R1, R0, R1   # 0x0aac
        SHRI             R0, R0, 31   # 0x0ab0
        ADD              R0, R2, R0, R2   # 0x0ab4
        ST_GLOBAL_IDX    R0, R6, R5, 0, 28   # 0x0ab8
        ST_GLOBAL_IDX    R15, R6, R5, 0, 0   # 0x0abc
        LD_LOCAL         R14, 44   # 0x0ac0
        C_MOV            R1, R15   # 0x0ac4
        C_RET            224   # 0x0ac6
        ST_LOCAL         R14, 12   # 0x0ac8
        MOVI             R0, 0   # 0x0acc
        ST_LOCAL         R1, 16   # 0x0ad0
        ADDI             R5, R1, -1   # 0x0ad4
        SETP_LT_U_NPI    P0, R6, R5, 2   # 0x0ad8
        BRA_PRED         0, L0be4   # 0x0adc
        MOVI             R9, 0   # 0x0ae0
        MOVI             R6, 65535   # 0x0ae4
        MOVI             R7, 2   # 0x0ae8
        MOVI             R10, 0   # 0x0aec
        MOVI             R8, 0   # 0x0af0
        C_BRA            L0b34   # 0x0af4
L0af6:  MOVI             R8, 8   # 0x0af6
        MOVI             R9, 96   # 0x0afa
L0afe:  AND              R1, R2, R6, R2   # 0x0afe
        ANDI             R1, R1, 24   # 0x0b02
        ADD              R1, R9, R1, R9   # 0x0b06
        LD_GLOBAL        R14, R7, 28   # 0x0b0a
        LD_GLOBAL_IDX    R15, R14, R1, 0, 0   # 0x0b0e
        LD_GLOBAL_IDX    R1, R14, R1, 0, 4   # 0x0b12
        SHLI             R1, R1, 16   # 0x0b16
        SHRI             R14, R15, 16   # 0x0b1a
        OR               R9, R1, R14, R1   # 0x0b1e
        AND              R10, R15, R6, R15   # 0x0b22
        ADD              R1, R0, R8, R0   # 0x0b26
        C_ADDI           R1, 1   # 0x0b2a
        SETP_LT_U_NP     P0, R1, R1, R5   # 0x0b2c
        BRA_PRED         4, L0be4   # 0x0b30
L0b34:  SETP_EQ_NPI      P0, R11, R8, 0   # 0x0b34
        BRA_PRED         0, L0ba6   # 0x0b38
        SETP_LT_U_NPI    P0, R11, R8, 4   # 0x0b3c
        BRA_PRED         0, L0b96   # 0x0b40
        ADD              R11, R4, R0, R4   # 0x0b44
        MOVI             R12, 0   # 0x0b48
L0b4c:  ADD              R13, R11, R12, R11   # 0x0b4c
        ADD              R15, R12, R10, R12   # 0x0b50
        SZ_GLOBAL_LD_U8  R14, R9, R15, 0, 0   # 0x0b54
        SZ_GLOBAL_ST_8   R14, R3, R13, 0, 0   # 0x0b58
        ADDI             R14, R15, 1   # 0x0b5c
        SZ_GLOBAL_LD_U8  R14, R9, R14, 0, 0   # 0x0b60
        ADDI             R1, R13, 1   # 0x0b64
        SZ_GLOBAL_ST_8   R14, R3, R1, 0, 0   # 0x0b68
        ADDI             R1, R15, 2   # 0x0b6c
        SZ_GLOBAL_LD_U8  R1, R9, R1, 0, 0   # 0x0b70
        ADDI             R14, R13, 2   # 0x0b74
        SZ_GLOBAL_ST_8   R1, R3, R14, 0, 0   # 0x0b78
        ADDI             R1, R15, 3   # 0x0b7c
        SZ_GLOBAL_LD_U8  R1, R9, R1, 0, 0   # 0x0b80
        ADDI             R14, R13, 3   # 0x0b84
        SZ_GLOBAL_ST_8   R1, R3, R14, 0, 0   # 0x0b88
        C_ADDI           R12, 4   # 0x0b8c
        SETP_NE_NP       P0, R1, R8, R12   # 0x0b8e
        BRA_PRED         0, L0b4c   # 0x0b92
L0b96:  C_ADD            R0, R8   # 0x0b96
        ADD              R1, R0, R4, R0   # 0x0b98
        MOVI             R14, 44   # 0x0b9c
        SZ_GLOBAL_ST_8   R14, R3, R1, 0, 0   # 0x0ba0
        C_ADDI           R0, 1   # 0x0ba4
L0ba6:  C_ADDI           R2, 1   # 0x0ba6
        ANDI             R10, R2, 7   # 0x0ba8
        MOVI             R8, 4   # 0x0bac
        SETP_LT_NP       P0, R1, R8, R10   # 0x0bb0
        BRA_PRED         0, L0bce   # 0x0bb4
        MOVI             R9, 0   # 0x0bb8
        SETP_LT_U_NPI    P0, R1, R10, 3   # 0x0bbc
        BRA_PRED         0, L0afe   # 0x0bc0
        MOVI             R8, 8   # 0x0bc4
        MOVI             R9, 32   # 0x0bc8
        C_BRA            L0afe   # 0x0bcc
L0bce:  ADDI             R1, R10, -5   # 0x0bce
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x0bd2
        BRA_PRED         4, L0af6   # 0x0bd6
        MOVI             R8, 8   # 0x0bda
        MOVI             R9, 64   # 0x0bde
        C_BRA            L0afe   # 0x0be2
L0be4:  LD_LOCAL         R1, 16   # 0x0be4
        SETP_LE_U_NP     P0, R2, R1, R0   # 0x0be8
        BRA_PRED         0, L0c86   # 0x0bec
        SUB              R2, R1, R0, R1   # 0x0bf0
        ANDI             R5, R2, 7   # 0x0bf4
        SETP_EQ_NPI      P0, R2, R5, 0   # 0x0bf8
        C_MOV            R2, R0   # 0x0bfc
        BRA_PRED         0, L0c1e   # 0x0bfe
        MOVI             R6, 0   # 0x0c02
        C_MOV            R2, R0   # 0x0c06
L0c08:  ADD              R7, R4, R2, R4   # 0x0c08
        SZ_GLOBAL_ST_8   R6, R3, R7, 0, 0   # 0x0c0c
        C_ADDI           R2, 1   # 0x0c10
        ADDI             R5, R5, -1   # 0x0c12
        SETP_NE_NPI      P0, R7, R5, 0   # 0x0c16
        BRA_PRED         0, L0c08   # 0x0c1a
L0c1e:  C_SUB            R0, R1   # 0x0c1e
        MOVI48           R5, 4294967288   # 0x0c20
        SETP_LT_U_NP     P0, R0, R5, R0   # 0x0c26
        BRA_PRED         0, L0c86   # 0x0c2a
        ADDI             R0, R2, 7   # 0x0c2e
        C_NEG            R1, R1   # 0x0c32
        MOVI             R2, 0   # 0x0c34
L0c38:  ADD              R5, R4, R0, R4   # 0x0c38
        ADDI             R6, R5, -7   # 0x0c3c
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0c40
        ADDI             R6, R5, -6   # 0x0c44
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0c48
        ADDI             R6, R5, -5   # 0x0c4c
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0c50
        ADDI             R6, R5, -4   # 0x0c54
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0c58
        ADDI             R6, R5, -3   # 0x0c5c
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0c60
        ADDI             R6, R5, -2   # 0x0c64
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0c68
        ADDI             R6, R5, -1   # 0x0c6c
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0c70
        SZ_GLOBAL_ST_8   R2, R3, R5, 0, 0   # 0x0c74
        C_ADDI           R0, 8   # 0x0c78
        ADD              R5, R1, R0, R1   # 0x0c7a
        SETP_NE_NPI      P0, R5, R5, 7   # 0x0c7e
        BRA_PRED         0, L0c38   # 0x0c82
L0c86:  LD_LOCAL         R14, 12   # 0x0c86
        C_RET            224   # 0x0c8a
        XOR              R0, R1, R2, R1   # 0x0c8c
        C_ANDI           R0, 1   # 0x0c90
        SETP_NE_NPI      P0, R0, R0, 0   # 0x0c92
        C_SHRI           R2, 1   # 0x0c96
        MOVI48           R0, 4294942721   # 0x0c98
        XOR              R3, R2, R0, R2   # 0x0c9e
        MOV_P            R2, 0, R3, R3, R3   # 0x0ca2
        C_MOV            R3, R1   # 0x0ca6
        C_SHRI           R3, 1   # 0x0ca8
        C_XOR            R3, R2   # 0x0caa
        C_ANDI           R3, 1   # 0x0cac
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0cae
        C_SHRI           R2, 1   # 0x0cb2
        MOVI             R3, 32767   # 0x0cb4
        C_AND            R2, R3   # 0x0cb8
        XOR              R4, R2, R0, R2   # 0x0cba
        MOV_P            R2, 0, R4, R4, R4   # 0x0cbe
        C_MOV            R4, R1   # 0x0cc2
        C_SHRI           R4, 2   # 0x0cc4
        C_XOR            R4, R2   # 0x0cc6
        C_ANDI           R4, 1   # 0x0cc8
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0cca
        C_SHRI           R2, 1   # 0x0cce
        C_AND            R2, R3   # 0x0cd0
        XOR              R4, R2, R0, R2   # 0x0cd2
        MOV_P            R2, 0, R4, R4, R4   # 0x0cd6
        C_MOV            R4, R1   # 0x0cda
        C_SHRI           R4, 3   # 0x0cdc
        C_XOR            R4, R2   # 0x0cde
        C_ANDI           R4, 1   # 0x0ce0
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0ce2
        C_SHRI           R2, 1   # 0x0ce6
        C_AND            R2, R3   # 0x0ce8
        XOR              R4, R2, R0, R2   # 0x0cea
        MOV_P            R2, 0, R4, R4, R4   # 0x0cee
        C_MOV            R4, R1   # 0x0cf2
        C_SHRI           R4, 4   # 0x0cf4
        C_XOR            R4, R2   # 0x0cf6
        C_ANDI           R4, 1   # 0x0cf8
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0cfa
        C_SHRI           R2, 1   # 0x0cfe
        C_AND            R2, R3   # 0x0d00
        XOR              R4, R2, R0, R2   # 0x0d02
        MOV_P            R2, 0, R4, R4, R4   # 0x0d06
        C_MOV            R4, R1   # 0x0d0a
        C_SHRI           R4, 5   # 0x0d0c
        C_XOR            R4, R2   # 0x0d0e
        C_ANDI           R4, 1   # 0x0d10
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0d12
        C_SHRI           R2, 1   # 0x0d16
        C_AND            R2, R3   # 0x0d18
        XOR              R4, R2, R0, R2   # 0x0d1a
        MOV_P            R2, 0, R4, R4, R4   # 0x0d1e
        C_MOV            R4, R1   # 0x0d22
        C_SHRI           R4, 6   # 0x0d24
        C_XOR            R4, R2   # 0x0d26
        C_ANDI           R4, 1   # 0x0d28
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0d2a
        C_SHRI           R2, 1   # 0x0d2e
        C_AND            R2, R3   # 0x0d30
        XOR              R4, R2, R0, R2   # 0x0d32
        MOV_P            R2, 0, R4, R4, R4   # 0x0d36
        ANDI             R4, R1, 128   # 0x0d3a
        C_SHRI           R4, 7   # 0x0d3e
        ANDI             R5, R2, 1   # 0x0d40
        SETP_EQ_NP       P0, R4, R4, R5   # 0x0d44
        C_SHRI           R2, 1   # 0x0d48
        C_AND            R2, R3   # 0x0d4a
        XOR              R4, R2, R0, R2   # 0x0d4c
        MOV_P            R4, 0, R2, R2, R2   # 0x0d50
        C_MOV            R2, R1   # 0x0d54
        C_SHRI           R2, 8   # 0x0d56
        XOR              R2, R4, R2, R4   # 0x0d58
        C_ANDI           R2, 1   # 0x0d5c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0d5e
        C_SHRI           R4, 1   # 0x0d62
        AND              R2, R4, R3, R4   # 0x0d64
        XOR              R4, R2, R0, R2   # 0x0d68
        MOV_P            R2, 0, R4, R4, R4   # 0x0d6c
        C_MOV            R4, R1   # 0x0d70
        C_SHRI           R4, 9   # 0x0d72
        C_XOR            R4, R2   # 0x0d74
        C_ANDI           R4, 1   # 0x0d76
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0d78
        C_SHRI           R2, 1   # 0x0d7c
        C_AND            R2, R3   # 0x0d7e
        XOR              R4, R2, R0, R2   # 0x0d80
        MOV_P            R2, 0, R4, R4, R4   # 0x0d84
        C_MOV            R4, R1   # 0x0d88
        C_SHRI           R4, 10   # 0x0d8a
        C_XOR            R4, R2   # 0x0d8c
        C_ANDI           R4, 1   # 0x0d8e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0d90
        C_SHRI           R2, 1   # 0x0d94
        C_AND            R2, R3   # 0x0d96
        XOR              R4, R2, R0, R2   # 0x0d98
        MOV_P            R2, 0, R4, R4, R4   # 0x0d9c
        C_MOV            R4, R1   # 0x0da0
        C_SHRI           R4, 11   # 0x0da2
        C_XOR            R4, R2   # 0x0da4
        C_ANDI           R4, 1   # 0x0da6
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0da8
        C_SHRI           R2, 1   # 0x0dac
        C_AND            R2, R3   # 0x0dae
        XOR              R4, R2, R0, R2   # 0x0db0
        MOV_P            R2, 0, R4, R4, R4   # 0x0db4
        C_MOV            R4, R1   # 0x0db8
        C_SHRI           R4, 12   # 0x0dba
        C_XOR            R4, R2   # 0x0dbc
        C_ANDI           R4, 1   # 0x0dbe
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0dc0
        C_SHRI           R2, 1   # 0x0dc4
        C_AND            R2, R3   # 0x0dc6
        XOR              R4, R2, R0, R2   # 0x0dc8
        MOV_P            R2, 0, R4, R4, R4   # 0x0dcc
        C_MOV            R4, R1   # 0x0dd0
        C_SHRI           R4, 13   # 0x0dd2
        C_XOR            R4, R2   # 0x0dd4
        C_ANDI           R4, 1   # 0x0dd6
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0dd8
        C_SHRI           R2, 1   # 0x0ddc
        C_AND            R2, R3   # 0x0dde
        XOR              R4, R2, R0, R2   # 0x0de0
        MOV_P            R2, 0, R4, R4, R4   # 0x0de4
        C_MOV            R4, R1   # 0x0de8
        C_SHRI           R4, 14   # 0x0dea
        C_XOR            R4, R2   # 0x0dec
        C_ANDI           R4, 1   # 0x0dee
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0df0
        C_SHRI           R2, 1   # 0x0df4
        C_AND            R2, R3   # 0x0df6
        XOR              R4, R2, R0, R2   # 0x0df8
        MOV_P            R2, 0, R4, R4, R4   # 0x0dfc
        MOVI             R4, 32768   # 0x0e00
        AND              R4, R1, R4, R1   # 0x0e04
        C_SHRI           R4, 15   # 0x0e08
        ANDI             R5, R2, 1   # 0x0e0a
        SETP_EQ_NP       P0, R4, R4, R5   # 0x0e0e
        C_SHRI           R2, 1   # 0x0e12
        C_AND            R2, R3   # 0x0e14
        XOR              R4, R2, R0, R2   # 0x0e16
        MOV_P            R4, 0, R2, R2, R2   # 0x0e1a
        SHRI             R2, R1, 16   # 0x0e1e
        XOR              R2, R4, R2, R4   # 0x0e22
        C_ANDI           R2, 1   # 0x0e26
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e28
        C_SHRI           R4, 1   # 0x0e2c
        AND              R2, R4, R3, R4   # 0x0e2e
        XOR              R4, R2, R0, R2   # 0x0e32
        MOV_P            R2, 0, R4, R4, R4   # 0x0e36
        SHRI             R4, R1, 17   # 0x0e3a
        C_XOR            R4, R2   # 0x0e3e
        C_ANDI           R4, 1   # 0x0e40
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0e42
        C_SHRI           R2, 1   # 0x0e46
        C_AND            R2, R3   # 0x0e48
        XOR              R4, R2, R0, R2   # 0x0e4a
        MOV_P            R2, 0, R4, R4, R4   # 0x0e4e
        SHRI             R4, R1, 18   # 0x0e52
        C_XOR            R4, R2   # 0x0e56
        C_ANDI           R4, 1   # 0x0e58
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0e5a
        C_SHRI           R2, 1   # 0x0e5e
        C_AND            R2, R3   # 0x0e60
        XOR              R4, R2, R0, R2   # 0x0e62
        MOV_P            R2, 0, R4, R4, R4   # 0x0e66
        SHRI             R4, R1, 19   # 0x0e6a
        C_XOR            R4, R2   # 0x0e6e
        C_ANDI           R4, 1   # 0x0e70
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0e72
        C_SHRI           R2, 1   # 0x0e76
        C_AND            R2, R3   # 0x0e78
        XOR              R4, R2, R0, R2   # 0x0e7a
        MOV_P            R2, 0, R4, R4, R4   # 0x0e7e
        SHRI             R4, R1, 20   # 0x0e82
        C_XOR            R4, R2   # 0x0e86
        C_ANDI           R4, 1   # 0x0e88
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0e8a
        C_SHRI           R2, 1   # 0x0e8e
        C_AND            R2, R3   # 0x0e90
        XOR              R4, R2, R0, R2   # 0x0e92
        MOV_P            R2, 0, R4, R4, R4   # 0x0e96
        SHRI             R4, R1, 21   # 0x0e9a
        C_XOR            R4, R2   # 0x0e9e
        C_ANDI           R4, 1   # 0x0ea0
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0ea2
        C_SHRI           R2, 1   # 0x0ea6
        C_AND            R2, R3   # 0x0ea8
        XOR              R4, R2, R0, R2   # 0x0eaa
        MOV_P            R2, 0, R4, R4, R4   # 0x0eae
        SHRI             R4, R1, 22   # 0x0eb2
        C_XOR            R4, R2   # 0x0eb6
        C_ANDI           R4, 1   # 0x0eb8
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0eba
        C_SHRI           R2, 1   # 0x0ebe
        C_AND            R2, R3   # 0x0ec0
        XOR              R4, R2, R0, R2   # 0x0ec2
        MOV_P            R2, 0, R4, R4, R4   # 0x0ec6
        SHRI             R4, R1, 23   # 0x0eca
        C_ANDI           R4, 1   # 0x0ece
        ANDI             R5, R2, 1   # 0x0ed0
        SETP_EQ_NP       P0, R4, R4, R5   # 0x0ed4
        C_SHRI           R2, 1   # 0x0ed8
        C_AND            R2, R3   # 0x0eda
        XOR              R4, R2, R0, R2   # 0x0edc
        MOV_P            R4, 0, R2, R2, R2   # 0x0ee0
        SHRI             R2, R1, 24   # 0x0ee4
        XOR              R2, R4, R2, R4   # 0x0ee8
        C_ANDI           R2, 1   # 0x0eec
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0eee
        C_SHRI           R4, 1   # 0x0ef2
        AND              R2, R4, R3, R4   # 0x0ef4
        XOR              R4, R2, R0, R2   # 0x0ef8
        MOV_P            R2, 0, R4, R4, R4   # 0x0efc
        SHRI             R4, R1, 25   # 0x0f00
        C_XOR            R4, R2   # 0x0f04
        C_ANDI           R4, 1   # 0x0f06
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f08
        C_SHRI           R2, 1   # 0x0f0c
        C_AND            R2, R3   # 0x0f0e
        XOR              R4, R2, R0, R2   # 0x0f10
        MOV_P            R2, 0, R4, R4, R4   # 0x0f14
        SHRI             R4, R1, 26   # 0x0f18
        C_XOR            R4, R2   # 0x0f1c
        C_ANDI           R4, 1   # 0x0f1e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f20
        C_SHRI           R2, 1   # 0x0f24
        C_AND            R2, R3   # 0x0f26
        XOR              R4, R2, R0, R2   # 0x0f28
        MOV_P            R2, 0, R4, R4, R4   # 0x0f2c
        SHRI             R4, R1, 27   # 0x0f30
        C_XOR            R4, R2   # 0x0f34
        C_ANDI           R4, 1   # 0x0f36
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f38
        C_SHRI           R2, 1   # 0x0f3c
        C_AND            R2, R3   # 0x0f3e
        XOR              R4, R2, R0, R2   # 0x0f40
        MOV_P            R2, 0, R4, R4, R4   # 0x0f44
        SHRI             R4, R1, 28   # 0x0f48
        C_XOR            R4, R2   # 0x0f4c
        C_ANDI           R4, 1   # 0x0f4e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f50
        C_SHRI           R2, 1   # 0x0f54
        C_AND            R2, R3   # 0x0f56
        XOR              R4, R2, R0, R2   # 0x0f58
        MOV_P            R2, 0, R4, R4, R4   # 0x0f5c
        SHRI             R4, R1, 29   # 0x0f60
        C_XOR            R4, R2   # 0x0f64
        C_ANDI           R4, 1   # 0x0f66
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f68
        C_SHRI           R2, 1   # 0x0f6c
        C_AND            R2, R3   # 0x0f6e
        XOR              R4, R2, R0, R2   # 0x0f70
        MOV_P            R2, 0, R4, R4, R4   # 0x0f74
        SHRI             R4, R1, 30   # 0x0f78
        C_XOR            R4, R2   # 0x0f7c
        C_SHRI           R2, 1   # 0x0f7e
        C_AND            R2, R3   # 0x0f80
        XOR              R0, R2, R0, R2   # 0x0f82
        C_ANDI           R4, 1   # 0x0f86
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f88
        MOV_P            R2, 0, R0, R0, R0   # 0x0f8c
        SHRI             R0, R1, 31   # 0x0f90
        ANDI             R1, R2, 1   # 0x0f94
        SETP_EQ_NP       P0, R0, R0, R1   # 0x0f98
        C_SHRI           R2, 1   # 0x0f9c
        AND              R0, R2, R3, R2   # 0x0f9e
        MOVI             R1, 40961   # 0x0fa2
        XOR              R1, R0, R1, R0   # 0x0fa6
        MOV_P            R1, 0, R0, R0, R0   # 0x0faa
        C_RET            224   # 0x0fae
        MOVI             R15, 2   # 0x0fb0
        LD_GLOBAL        R15, R15, 24   # 0x0fb4
        SRD              R0, 3   # 0x0fb8
        C_ADD            R15, R0   # 0x0fba
        ST_LOCAL         R8, 52   # 0x0fbc
        ST_LOCAL         R9, 56   # 0x0fc0
        ST_LOCAL         R10, 60   # 0x0fc4
        ST_LOCAL         R11, 64   # 0x0fc8
        ST_LOCAL         R12, 68   # 0x0fcc
        ST_LOCAL         R13, 72   # 0x0fd0
        ST_LOCAL         R14, 44   # 0x0fd4
        ST_LOCAL         R6, 40   # 0x0fd8
        ST_LOCAL         R1, 36   # 0x0fdc
        MOVI             R7, 0   # 0x0fe0
        ST_GLOBAL        R7, R15, 28   # 0x0fe4
        ST_GLOBAL        R7, R15, 24   # 0x0fe8
        ST_GLOBAL        R7, R15, 20   # 0x0fec
        ST_GLOBAL        R7, R15, 16   # 0x0ff0
        ST_GLOBAL        R7, R15, 12   # 0x0ff4
        ST_GLOBAL        R7, R15, 8   # 0x0ff8
        ST_GLOBAL        R7, R15, 4   # 0x0ffc
        C_ST_GLOBAL      R7, R15   # 0x1000
        SZ_GLOBAL_LD_U8  R11, R2, R3, 0, 0   # 0x1002
        LD_GLOBAL        R0, R15, 32   # 0x1006
        ST_LOCAL         R0, 48   # 0x100a
        SETP_EQ_NPI      P0, R0, R11, 0   # 0x100e
        MOVI             R0, 0   # 0x1012
        ST_LOCAL         R0, 20   # 0x1016
        ST_LOCAL         R0, 24   # 0x101a
        ST_LOCAL         R0, 16   # 0x101e
        ST_LOCAL         R0, 12   # 0x1022
        ST_LOCAL         R0, 32   # 0x1026
        ST_LOCAL         R0, 28   # 0x102a
        BRA_PRED         0, L1260   # 0x102e
        MOVI             R0, 3   # 0x1032
        MOVI             R1, 0   # 0x1036
        ST_LOCAL         R1, 20   # 0x103a
        ST_LOCAL         R1, 24   # 0x103e
        ST_LOCAL         R1, 16   # 0x1042
        ST_LOCAL         R1, 12   # 0x1046
        ST_LOCAL         R1, 32   # 0x104a
        ST_LOCAL         R1, 28   # 0x104e
        MOVI             R13, 0   # 0x1052
        MOVI             R8, 0   # 0x1056
        C_MOV            R14, R11   # 0x105a
        MOVI             R9, 0   # 0x105c
        C_MOV            R6, R3   # 0x1060
        C_BRA            L1082   # 0x1062
L1064:  LD_GLOBAL_IDX    R6, R15, R9, 1, 0   # 0x1064
        C_ADDI           R6, 1   # 0x1068
        ST_GLOBAL_IDX    R6, R15, R9, 1, 0   # 0x106a
        SZ_GLOBAL_LD_U8  R14, R2, R1, 0, 0   # 0x106e
        MOVI             R9, 0   # 0x1072
        SETP_EQ_NPI      P0, R6, R14, 0   # 0x1076
        C_MOV            R8, R13   # 0x107a
        BRA_PRED         0, L1260   # 0x107c
L1080:  C_MOV            R6, R1   # 0x1080
L1082:  ANDI             R12, R14, 255   # 0x1082
        SETP_NE_NPI      P0, R1, R12, 44   # 0x1086
        ADDI             R1, R6, 1   # 0x108a
        BRA_PRED         4, L1064   # 0x108e
        SETP_LT_NP       P0, R10, R0, R9   # 0x1092
        BRA_PRED         4, L10ca   # 0x1096
        MOVI             R10, 5   # 0x109a
        SETP_LT_NP       P0, R10, R10, R9   # 0x109e
        BRA_PRED         0, L10fa   # 0x10a2
        SETP_EQ_NPI      P0, R10, R9, 4   # 0x10a6
        BRA_PRED         0, L116e   # 0x10aa
        SETP_EQ_NPI      P0, R10, R9, 5   # 0x10ae
        BRA_PRED         4, L1248   # 0x10b2
        ANDI             R9, R14, 223   # 0x10b6
        SETP_NE_NPI      P0, R9, R9, 69   # 0x10ba
        BRA_PRED         0, L11ea   # 0x10be
        MOVI             R9, 3   # 0x10c2
        BRA              L1206   # 0x10c6
L10ca:  SETP_EQ_NPI      P0, R10, R9, 0   # 0x10ca
        BRA_PRED         0, L1134   # 0x10ce
        SETP_EQ_NPI      P0, R10, R9, 2   # 0x10d2
        BRA_PRED         0, L119c   # 0x10d6
        SETP_EQ_NPI      P0, R14, R9, 3   # 0x10da
        BRA_PRED         4, L1248   # 0x10de
        SETP_EQ_NPI      P0, R14, R12, 45   # 0x10e2
        BRA_PRED         0, L10f2   # 0x10e6
        SETP_NE_NPI      P0, R14, R12, 43   # 0x10ea
        BRA_PRED         0, L1222   # 0x10ee
L10f2:  MOVI             R9, 6   # 0x10f2
        BRA              L1226   # 0x10f6
L10fa:  SETP_EQ_NPI      P0, R10, R9, 6   # 0x10fa
        BRA_PRED         0, L117c   # 0x10fe
        SETP_EQ_NPI      P0, R10, R9, 7   # 0x1102
        BRA_PRED         4, L1248   # 0x1106
        ADDI             R14, R14, -58   # 0x110a
        ANDI             R14, R14, 255   # 0x110e
        MOVI             R9, 245   # 0x1112
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x1116
        MOVI             R9, 7   # 0x111a
        BRA_PRED         0, L1248   # 0x111e
        MOVI             R9, 1   # 0x1122
        LD_LOCAL         R14, 32   # 0x1126
        C_ADDI           R14, 1   # 0x112a
        ST_LOCAL         R14, 32   # 0x112c
        BRA              L1248   # 0x1130
L1134:  ADDI             R14, R14, -58   # 0x1134
        ANDI             R14, R14, 255   # 0x1138
        MOVI             R9, 245   # 0x113c
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x1140
        MOVI             R9, 4   # 0x1144
        BRA_PRED         0, L1240   # 0x1148
        MOVI             R9, 2   # 0x114c
        SETP_EQ_NPI      P0, R14, R12, 43   # 0x1150
        BRA_PRED         0, L1240   # 0x1154
        SETP_EQ_NPI      P0, R14, R12, 45   # 0x1158
        BRA_PRED         0, L1240   # 0x115c
        SETP_NE_NPI      P0, R14, R12, 46   # 0x1160
        BRA_PRED         0, L1232   # 0x1164
        MOVI             R9, 5   # 0x1168
        C_BRA            L1240   # 0x116c
L116e:  SETP_NE_NPI      P0, R9, R12, 46   # 0x116e
        BRA_PRED         0, L11c2   # 0x1172
        MOVI             R9, 5   # 0x1176
        C_BRA            L11de   # 0x117a
L117c:  ADDI             R14, R14, -58   # 0x117c
        ANDI             R14, R14, 255   # 0x1180
        MOVI             R9, 246   # 0x1184
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x1188
        MOVI             R9, 7   # 0x118c
        MOVI             R14, 1   # 0x1190
        MOV_P            R9, 0, R14, R14, R14   # 0x1194
        C_ADDI           R7, 1   # 0x1198
        C_BRA            L1248   # 0x119a
L119c:  ADDI             R14, R14, -58   # 0x119c
        ANDI             R14, R14, 255   # 0x11a0
        MOVI             R9, 246   # 0x11a4
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x11a8
        BRA_PRED         4, L1212   # 0x11ac
        SETP_EQ_NPI      P0, R14, R12, 46   # 0x11b0
        MOVI             R9, 1   # 0x11b4
        MOVI             R14, 5   # 0x11b8
        MOV_P            R9, 0, R14, R14, R14   # 0x11bc
        C_BRA            L1216   # 0x11c0
L11c2:  ADDI             R14, R14, -58   # 0x11c2
        ANDI             R14, R14, 255   # 0x11c6
        MOVI             R9, 245   # 0x11ca
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x11ce
        MOVI             R9, 4   # 0x11d2
        BRA_PRED         0, L1248   # 0x11d6
        MOVI             R9, 1   # 0x11da
L11de:  LD_LOCAL         R14, 24   # 0x11de
        C_ADDI           R14, 1   # 0x11e2
        ST_LOCAL         R14, 24   # 0x11e4
        C_BRA            L1248   # 0x11e8
L11ea:  ADDI             R14, R14, -58   # 0x11ea
        ANDI             R14, R14, 255   # 0x11ee
        MOVI             R9, 245   # 0x11f2
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x11f6
        MOVI             R9, 5   # 0x11fa
        BRA_PRED         0, L1248   # 0x11fe
        MOVI             R9, 1   # 0x1202
L1206:  LD_LOCAL         R14, 20   # 0x1206
        C_ADDI           R14, 1   # 0x120a
        ST_LOCAL         R14, 20   # 0x120c
        C_BRA            L1248   # 0x1210
L1212:  MOVI             R9, 4   # 0x1212
L1216:  LD_LOCAL         R14, 12   # 0x1216
        C_ADDI           R14, 1   # 0x121a
        ST_LOCAL         R14, 12   # 0x121c
        C_BRA            L1248   # 0x1220
L1222:  MOVI             R9, 1   # 0x1222
L1226:  LD_LOCAL         R14, 16   # 0x1226
        C_ADDI           R14, 1   # 0x122a
        ST_LOCAL         R14, 16   # 0x122c
        C_BRA            L1248   # 0x1230
L1232:  MOVI             R9, 1   # 0x1232
        LD_LOCAL         R14, 32   # 0x1236
        C_ADDI           R14, 1   # 0x123a
        ST_LOCAL         R14, 32   # 0x123c
L1240:  C_ADDI           R8, 1   # 0x1240
        C_MOV            R13, R8   # 0x1242
        ST_LOCAL         R8, 28   # 0x1244
L1248:  SZ_GLOBAL_LD_U8  R14, R2, R6, 0, 1   # 0x1248
        SETP_EQ_NPI      P0, R6, R14, 0   # 0x124c
        BRA_PRED         0, L1064   # 0x1250
        SETP_EQ_NPI      P0, R6, R9, 1   # 0x1254
        BRA_PRED         4, L1080   # 0x1258
        BRA              L1064   # 0x125c
L1260:  LD_LOCAL         R1, 36   # 0x1260
        SETP_EQ_NPI      P0, R0, R1, 0   # 0x1264
        SHLI             R0, R2, 16   # 0x1268
        LD_LOCAL         R6, 40   # 0x126c
        SHLI             R6, R6, 16   # 0x1270
        ST_LOCAL         R6, 40   # 0x1274
        ADD              R6, R3, R1, R3   # 0x1278
        SHRI             R12, R2, 16   # 0x127c
        BRA_PRED         0, L1304   # 0x1280
        ADD              R8, R3, R0, R3   # 0x1284
        LD_LOCAL         R1, 40   # 0x1288
        SRAI             R1, R1, 16   # 0x128c
        ADD              R14, R1, R0, R1   # 0x1290
        C_ADD            R8, R1   # 0x1294
        C_NOT            R8, R8   # 0x1296
        C_MOV            R11, R3   # 0x1298
L129a:  SZ_GLOBAL_LD_U8  R9, R2, R11, 0, 0   # 0x129a
        SETP_EQ_NPI      P0, R10, R9, 44   # 0x129e
        BRA_PRED         0, L12ac   # 0x12a2
        C_XOR            R9, R4   # 0x12a6
        SZ_GLOBAL_ST_8   R9, R2, R11, 0, 0   # 0x12a8
L12ac:  ADD              R9, R1, R11, R1   # 0x12ac
        OR               R10, R0, R9, R0   # 0x12b0
        C_AND            R10, R8   # 0x12b4
        AND              R13, R0, R9, R0   # 0x12b6
        OR               R10, R13, R10, R13   # 0x12ba
        ADD              R11, R14, R11, R14   # 0x12be
        ADD              R13, R0, R6, R0   # 0x12c2
        SETP_LT_U_NP     P0, R11, R11, R13   # 0x12c6
        OR               R11, R0, R6, R0   # 0x12ca
        C_ANDN           R11, R13   # 0x12ce
        AND              R13, R0, R6, R0   # 0x12d0
        OR               R11, R13, R11, R13   # 0x12d4
        SHRI             R11, R11, 31   # 0x12d8
        SHRI             R10, R10, 31   # 0x12dc
        SETP_EQ_NP       P1, R13, R10, R11   # 0x12e0
        ADD              R11, R12, R11, R12   # 0x12e4
        ADD              R10, R12, R10, R12   # 0x12e8
        SETP_LT_U_NP     P2, R10, R10, R11   # 0x12ec
        C_SUB            R8, R1   # 0x12f0
        C_MOV            R11, R9   # 0x12f2
        BRA_PRED         2, L129a   # 0x12f4
        PAND             P0, 1, 0   # 0x12f8
        C_MOV            R11, R9   # 0x12fa
        BRA_PRED         0, L129a   # 0x12fc
        SZ_GLOBAL_LD_U8  R11, R2, R3, 0, 0   # 0x1300
L1304:  SETP_EQ_NPI      P0, R1, R11, 0   # 0x1304
        BRA_PRED         0, L1510   # 0x1308
        MOVI             R9, 0   # 0x130c
        MOVI             R4, 3   # 0x1310
        MOVI             R1, 5   # 0x1314
        C_MOV            R13, R3   # 0x1318
        C_BRA            L1338   # 0x131a
L131c:  LD_GLOBAL_IDX    R14, R15, R9, 1, 0   # 0x131c
        C_ADDI           R14, 1   # 0x1320
        ST_GLOBAL_IDX    R14, R15, R9, 1, 0   # 0x1322
        SZ_GLOBAL_LD_U8  R11, R2, R8, 0, 0   # 0x1326
        MOVI             R9, 0   # 0x132a
        SETP_EQ_NPI      P0, R14, R11, 0   # 0x132e
        BRA_PRED         0, L1510   # 0x1332
L1336:  C_MOV            R13, R8   # 0x1336
L1338:  ANDI             R14, R11, 255   # 0x1338
        SETP_NE_NPI      P0, R8, R14, 44   # 0x133c
        ADDI             R8, R13, 1   # 0x1340
        BRA_PRED         4, L131c   # 0x1344
        SETP_LT_NP       P0, R10, R4, R9   # 0x1348
        BRA_PRED         4, L137c   # 0x134c
        SETP_LT_NP       P0, R10, R1, R9   # 0x1350
        BRA_PRED         0, L13ac   # 0x1354
        SETP_EQ_NPI      P0, R10, R9, 4   # 0x1358
        BRA_PRED         0, L1420   # 0x135c
        SETP_EQ_NPI      P0, R14, R9, 5   # 0x1360
        BRA_PRED         4, L14f8   # 0x1364
        ANDI             R14, R11, 223   # 0x1368
        SETP_NE_NPI      P0, R14, R14, 69   # 0x136c
        BRA_PRED         0, L1498   # 0x1370
        MOVI             R9, 3   # 0x1374
        BRA              L14b4   # 0x1378
L137c:  SETP_EQ_NPI      P0, R10, R9, 0   # 0x137c
        BRA_PRED         0, L13e6   # 0x1380
        SETP_EQ_NPI      P0, R10, R9, 2   # 0x1384
        BRA_PRED         0, L144e   # 0x1388
        SETP_EQ_NPI      P0, R10, R9, 3   # 0x138c
        BRA_PRED         4, L14f8   # 0x1390
        SETP_EQ_NPI      P0, R9, R14, 45   # 0x1394
        BRA_PRED         0, L13a4   # 0x1398
        SETP_NE_NPI      P0, R14, R14, 43   # 0x139c
        BRA_PRED         0, L14d0   # 0x13a0
L13a4:  MOVI             R9, 6   # 0x13a4
        BRA              L14d4   # 0x13a8
L13ac:  SETP_EQ_NPI      P0, R14, R9, 6   # 0x13ac
        BRA_PRED         0, L142e   # 0x13b0
        SETP_EQ_NPI      P0, R14, R9, 7   # 0x13b4
        BRA_PRED         4, L14f8   # 0x13b8
        ADDI             R14, R11, -58   # 0x13bc
        ANDI             R14, R14, 255   # 0x13c0
        MOVI             R9, 245   # 0x13c4
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x13c8
        MOVI             R9, 7   # 0x13cc
        BRA_PRED         0, L14f8   # 0x13d0
        MOVI             R9, 1   # 0x13d4
        LD_LOCAL         R14, 32   # 0x13d8
        C_ADDI           R14, 1   # 0x13dc
        ST_LOCAL         R14, 32   # 0x13de
        BRA              L14f8   # 0x13e2
L13e6:  ADDI             R9, R11, -58   # 0x13e6
        ANDI             R9, R9, 255   # 0x13ea
        MOVI             R10, 245   # 0x13ee
        SETP_LT_U_NP     P0, R9, R10, R9   # 0x13f2
        MOVI             R9, 4   # 0x13f6
        BRA_PRED         0, L14ee   # 0x13fa
        MOVI             R9, 2   # 0x13fe
        SETP_EQ_NPI      P0, R10, R14, 43   # 0x1402
        BRA_PRED         0, L14ee   # 0x1406
        SETP_EQ_NPI      P0, R10, R14, 45   # 0x140a
        BRA_PRED         0, L14ee   # 0x140e
        SETP_NE_NPI      P0, R14, R14, 46   # 0x1412
        BRA_PRED         0, L14e0   # 0x1416
        MOVI             R9, 5   # 0x141a
        C_BRA            L14ee   # 0x141e
L1420:  SETP_NE_NPI      P0, R14, R14, 46   # 0x1420
        BRA_PRED         0, L1470   # 0x1424
        MOVI             R9, 5   # 0x1428
        C_BRA            L148c   # 0x142c
L142e:  ADDI             R14, R11, -58   # 0x142e
        ANDI             R14, R14, 255   # 0x1432
        MOVI             R9, 246   # 0x1436
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x143a
        MOVI             R9, 7   # 0x143e
        MOVI             R14, 1   # 0x1442
        MOV_P            R9, 0, R14, R14, R14   # 0x1446
        C_ADDI           R7, 1   # 0x144a
        C_BRA            L14f8   # 0x144c
L144e:  ADDI             R9, R11, -58   # 0x144e
        ANDI             R9, R9, 255   # 0x1452
        MOVI             R10, 246   # 0x1456
        SETP_LT_U_NP     P0, R9, R9, R10   # 0x145a
        BRA_PRED         4, L14c0   # 0x145e
        SETP_EQ_NPI      P0, R14, R14, 46   # 0x1462
        MOVI             R9, 1   # 0x1466
        MOV_P            R9, 0, R1, R1, R1   # 0x146a
        C_BRA            L14c4   # 0x146e
L1470:  ADDI             R14, R11, -58   # 0x1470
        ANDI             R14, R14, 255   # 0x1474
        MOVI             R9, 245   # 0x1478
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x147c
        MOVI             R9, 4   # 0x1480
        BRA_PRED         0, L14f8   # 0x1484
        MOVI             R9, 1   # 0x1488
L148c:  LD_LOCAL         R14, 24   # 0x148c
        C_ADDI           R14, 1   # 0x1490
        ST_LOCAL         R14, 24   # 0x1492
        C_BRA            L14f8   # 0x1496
L1498:  ADDI             R14, R11, -58   # 0x1498
        ANDI             R14, R14, 255   # 0x149c
        MOVI             R9, 245   # 0x14a0
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x14a4
        MOVI             R9, 5   # 0x14a8
        BRA_PRED         0, L14f8   # 0x14ac
        MOVI             R9, 1   # 0x14b0
L14b4:  LD_LOCAL         R14, 20   # 0x14b4
        C_ADDI           R14, 1   # 0x14b8
        ST_LOCAL         R14, 20   # 0x14ba
        C_BRA            L14f8   # 0x14be
L14c0:  MOVI             R9, 4   # 0x14c0
L14c4:  LD_LOCAL         R14, 12   # 0x14c4
        C_ADDI           R14, 1   # 0x14c8
        ST_LOCAL         R14, 12   # 0x14ca
        C_BRA            L14f8   # 0x14ce
L14d0:  MOVI             R9, 1   # 0x14d0
L14d4:  LD_LOCAL         R14, 16   # 0x14d4
        C_ADDI           R14, 1   # 0x14d8
        ST_LOCAL         R14, 16   # 0x14da
        C_BRA            L14f8   # 0x14de
L14e0:  MOVI             R9, 1   # 0x14e0
        LD_LOCAL         R14, 32   # 0x14e4
        C_ADDI           R14, 1   # 0x14e8
        ST_LOCAL         R14, 32   # 0x14ea
L14ee:  LD_LOCAL         R14, 28   # 0x14ee
        C_ADDI           R14, 1   # 0x14f2
        ST_LOCAL         R14, 28   # 0x14f4
L14f8:  SZ_GLOBAL_LD_U8  R11, R2, R13, 0, 1   # 0x14f8
        SETP_EQ_NPI      P0, R14, R11, 0   # 0x14fc
        BRA_PRED         0, L131c   # 0x1500
        SETP_EQ_NPI      P0, R14, R9, 1   # 0x1504
        BRA_PRED         4, L1336   # 0x1508
        BRA              L131c   # 0x150c
L1510:  LD_LOCAL         R1, 36   # 0x1510
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x1514
        BRA_PRED         0, L1596   # 0x1518
        ADD              R14, R3, R0, R3   # 0x151c
        LD_LOCAL         R1, 40   # 0x1520
        SRAI             R1, R1, 16   # 0x1524
        ADD              R4, R1, R0, R1   # 0x1528
        C_ADD            R14, R1   # 0x152c
        C_NOT            R14, R14   # 0x152e
L1530:  SZ_GLOBAL_LD_U8  R8, R2, R3, 0, 0   # 0x1530
        SETP_EQ_NPI      P0, R9, R8, 44   # 0x1534
        BRA_PRED         0, L1542   # 0x1538
        C_XOR            R8, R5   # 0x153c
        SZ_GLOBAL_ST_8   R8, R2, R3, 0, 0   # 0x153e
L1542:  ADD              R8, R1, R3, R1   # 0x1542
        OR               R9, R0, R8, R0   # 0x1546
        C_AND            R9, R14   # 0x154a
        AND              R10, R0, R8, R0   # 0x154c
        OR               R9, R10, R9, R10   # 0x1550
        ADD              R3, R4, R3, R4   # 0x1554
        ADD              R10, R0, R6, R0   # 0x1558
        SETP_LT_U_NP     P0, R3, R3, R10   # 0x155c
        OR               R3, R0, R6, R0   # 0x1560
        C_ANDN           R3, R10   # 0x1564
        AND              R10, R0, R6, R0   # 0x1566
        OR               R3, R10, R3, R10   # 0x156a
        SHRI             R3, R3, 31   # 0x156e
        SHRI             R9, R9, 31   # 0x1572
        SETP_EQ_NP       P1, R10, R9, R3   # 0x1576
        ADD              R3, R12, R3, R12   # 0x157a
        ADD              R9, R12, R9, R12   # 0x157e
        SETP_LT_U_NP     P2, R3, R9, R3   # 0x1582
        C_SUB            R14, R1   # 0x1586
        C_MOV            R3, R8   # 0x1588
        BRA_PRED         2, L1530   # 0x158a
        PAND             P0, 1, 0   # 0x158e
        C_MOV            R3, R8   # 0x1590
        BRA_PRED         0, L1530   # 0x1592
L1596:  MOVI             R0, 65535   # 0x1596
        LD_LOCAL         R1, 48   # 0x159a
        AND              R2, R1, R0, R1   # 0x159e
        C_LD_GLOBAL      R1, R15   # 0x15a2
        CALL             R14, 129906   # 0x15a4
        MOVI             R15, 2   # 0x15a8
        LD_GLOBAL        R15, R15, 24   # 0x15ac
        SRD              R3, 3   # 0x15b0
        C_ADD            R15, R3   # 0x15b2
        C_MOV            R2, R1   # 0x15b4
        LD_LOCAL         R1, 28   # 0x15b6
        CALL             R14, 129895   # 0x15ba
        MOVI             R15, 2   # 0x15be
        LD_GLOBAL        R15, R15, 24   # 0x15c2
        SRD              R3, 3   # 0x15c6
        C_ADD            R15, R3   # 0x15c8
        C_MOV            R2, R1   # 0x15ca
        LD_GLOBAL        R1, R15, 4   # 0x15cc
        CALL             R14, 129884   # 0x15d0
        MOVI             R15, 2   # 0x15d4
        LD_GLOBAL        R15, R15, 24   # 0x15d8
        SRD              R3, 3   # 0x15dc
        C_ADD            R15, R3   # 0x15de
        C_MOV            R2, R1   # 0x15e0
        LD_LOCAL         R1, 32   # 0x15e2
        CALL             R14, 129873   # 0x15e6
        MOVI             R15, 2   # 0x15ea
        LD_GLOBAL        R15, R15, 24   # 0x15ee
        SRD              R3, 3   # 0x15f2
        C_ADD            R15, R3   # 0x15f4
        C_MOV            R2, R1   # 0x15f6
        LD_GLOBAL        R1, R15, 8   # 0x15f8
        CALL             R14, 129862   # 0x15fc
        MOVI             R15, 2   # 0x1600
        LD_GLOBAL        R15, R15, 24   # 0x1604
        SRD              R3, 3   # 0x1608
        C_ADD            R15, R3   # 0x160a
        C_MOV            R2, R1   # 0x160c
        LD_LOCAL         R1, 12   # 0x160e
        CALL             R14, 129851   # 0x1612
        MOVI             R15, 2   # 0x1616
        LD_GLOBAL        R15, R15, 24   # 0x161a
        SRD              R3, 3   # 0x161e
        C_ADD            R15, R3   # 0x1620
        C_MOV            R2, R1   # 0x1622
        LD_GLOBAL        R1, R15, 12   # 0x1624
        CALL             R14, 129840   # 0x1628
        MOVI             R15, 2   # 0x162c
        LD_GLOBAL        R15, R15, 24   # 0x1630
        SRD              R3, 3   # 0x1634
        C_ADD            R15, R3   # 0x1636
        C_MOV            R2, R1   # 0x1638
        LD_LOCAL         R1, 16   # 0x163a
        CALL             R14, 129829   # 0x163e
        MOVI             R15, 2   # 0x1642
        LD_GLOBAL        R15, R15, 24   # 0x1646
        SRD              R3, 3   # 0x164a
        C_ADD            R15, R3   # 0x164c
        C_MOV            R2, R1   # 0x164e
        LD_GLOBAL        R1, R15, 16   # 0x1650
        CALL             R14, 129818   # 0x1654
        MOVI             R15, 2   # 0x1658
        LD_GLOBAL        R15, R15, 24   # 0x165c
        SRD              R3, 3   # 0x1660
        C_ADD            R15, R3   # 0x1662
        C_MOV            R2, R1   # 0x1664
        LD_LOCAL         R1, 24   # 0x1666
        CALL             R14, 129807   # 0x166a
        MOVI             R15, 2   # 0x166e
        LD_GLOBAL        R15, R15, 24   # 0x1672
        SRD              R3, 3   # 0x1676
        C_ADD            R15, R3   # 0x1678
        C_MOV            R2, R1   # 0x167a
        LD_GLOBAL        R1, R15, 20   # 0x167c
        CALL             R14, 129796   # 0x1680
        MOVI             R15, 2   # 0x1684
        LD_GLOBAL        R15, R15, 24   # 0x1688
        SRD              R3, 3   # 0x168c
        C_ADD            R15, R3   # 0x168e
        C_MOV            R2, R1   # 0x1690
        LD_LOCAL         R1, 20   # 0x1692
        CALL             R14, 129785   # 0x1696
        MOVI             R15, 2   # 0x169a
        LD_GLOBAL        R15, R15, 24   # 0x169e
        SRD              R3, 3   # 0x16a2
        C_ADD            R15, R3   # 0x16a4
        C_MOV            R2, R1   # 0x16a6
        LD_GLOBAL        R1, R15, 24   # 0x16a8
        CALL             R14, 129774   # 0x16ac
        MOVI             R15, 2   # 0x16b0
        LD_GLOBAL        R15, R15, 24   # 0x16b4
        SRD              R3, 3   # 0x16b8
        C_ADD            R15, R3   # 0x16ba
        C_MOV            R2, R1   # 0x16bc
        C_MOV            R1, R7   # 0x16be
        CALL             R14, 129764   # 0x16c0
        MOVI             R15, 2   # 0x16c4
        LD_GLOBAL        R15, R15, 24   # 0x16c8
        SRD              R3, 3   # 0x16cc
        C_ADD            R15, R3   # 0x16ce
        C_MOV            R2, R1   # 0x16d0
        LD_GLOBAL        R1, R15, 28   # 0x16d2
        CALL             R14, 129753   # 0x16d6
        MOVI             R15, 2   # 0x16da
        LD_GLOBAL        R15, R15, 24   # 0x16de
        SRD              R3, 3   # 0x16e2
        C_ADD            R15, R3   # 0x16e4
        C_MOV            R2, R1   # 0x16e6
        MOVI             R1, 0   # 0x16e8
        CALL             R14, 129742   # 0x16ec
        MOVI             R15, 2   # 0x16f0
        LD_GLOBAL        R15, R15, 24   # 0x16f4
        SRD              R3, 3   # 0x16f8
        C_ADD            R15, R3   # 0x16fa
        LD_LOCAL         R14, 44   # 0x16fc
        LD_LOCAL         R13, 72   # 0x1700
        LD_LOCAL         R12, 68   # 0x1704
        LD_LOCAL         R11, 64   # 0x1708
        LD_LOCAL         R10, 60   # 0x170c
        LD_LOCAL         R9, 56   # 0x1710
        LD_LOCAL         R8, 52   # 0x1714
        C_RET            224   # 0x1718
        XOR              R0, R2, R1, R2   # 0x171a
        C_ANDI           R0, 1   # 0x171e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1720
        C_SHRI           R2, 1   # 0x1724
        MOVI48           R3, 4294942721   # 0x1726
        XOR              R0, R2, R3, R2   # 0x172c
        MOV_P            R2, 0, R0, R0, R0   # 0x1730
        C_MOV            R0, R1   # 0x1734
        C_SHRI           R0, 1   # 0x1736
        C_XOR            R0, R2   # 0x1738
        C_ANDI           R0, 1   # 0x173a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x173c
        C_SHRI           R2, 1   # 0x1740
        MOVI             R0, 32767   # 0x1742
        C_AND            R2, R0   # 0x1746
        XOR              R4, R2, R3, R2   # 0x1748
        MOV_P            R2, 0, R4, R4, R4   # 0x174c
        C_MOV            R4, R1   # 0x1750
        C_SHRI           R4, 2   # 0x1752
        C_XOR            R4, R2   # 0x1754
        C_ANDI           R4, 1   # 0x1756
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1758
        C_SHRI           R2, 1   # 0x175c
        C_AND            R2, R0   # 0x175e
        XOR              R4, R2, R3, R2   # 0x1760
        MOV_P            R2, 0, R4, R4, R4   # 0x1764
        C_MOV            R4, R1   # 0x1768
        C_SHRI           R4, 3   # 0x176a
        C_XOR            R4, R2   # 0x176c
        C_ANDI           R4, 1   # 0x176e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1770
        C_SHRI           R2, 1   # 0x1774
        C_AND            R2, R0   # 0x1776
        XOR              R4, R2, R3, R2   # 0x1778
        MOV_P            R2, 0, R4, R4, R4   # 0x177c
        C_MOV            R4, R1   # 0x1780
        C_SHRI           R4, 4   # 0x1782
        C_XOR            R4, R2   # 0x1784
        C_ANDI           R4, 1   # 0x1786
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1788
        C_SHRI           R2, 1   # 0x178c
        C_AND            R2, R0   # 0x178e
        XOR              R4, R2, R3, R2   # 0x1790
        MOV_P            R2, 0, R4, R4, R4   # 0x1794
        C_MOV            R4, R1   # 0x1798
        C_SHRI           R4, 5   # 0x179a
        C_XOR            R4, R2   # 0x179c
        C_ANDI           R4, 1   # 0x179e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x17a0
        C_SHRI           R2, 1   # 0x17a4
        C_AND            R2, R0   # 0x17a6
        XOR              R4, R2, R3, R2   # 0x17a8
        MOV_P            R2, 0, R4, R4, R4   # 0x17ac
        C_MOV            R4, R1   # 0x17b0
        C_SHRI           R4, 6   # 0x17b2
        C_XOR            R4, R2   # 0x17b4
        C_ANDI           R4, 1   # 0x17b6
        SETP_NE_NPI      P0, R4, R4, 0   # 0x17b8
        C_SHRI           R2, 1   # 0x17bc
        C_AND            R2, R0   # 0x17be
        XOR              R4, R2, R3, R2   # 0x17c0
        MOV_P            R2, 0, R4, R4, R4   # 0x17c4
        ANDI             R4, R1, 128   # 0x17c8
        C_SHRI           R4, 7   # 0x17cc
        ANDI             R5, R2, 1   # 0x17ce
        SETP_EQ_NP       P0, R4, R4, R5   # 0x17d2
        C_SHRI           R2, 1   # 0x17d6
        C_AND            R2, R0   # 0x17d8
        XOR              R4, R2, R3, R2   # 0x17da
        MOV_P            R4, 0, R2, R2, R2   # 0x17de
        C_MOV            R2, R1   # 0x17e2
        C_SHRI           R2, 8   # 0x17e4
        XOR              R2, R4, R2, R4   # 0x17e6
        C_ANDI           R2, 1   # 0x17ea
        SETP_NE_NPI      P0, R2, R2, 0   # 0x17ec
        C_SHRI           R4, 1   # 0x17f0
        AND              R2, R4, R0, R4   # 0x17f2
        XOR              R4, R2, R3, R2   # 0x17f6
        MOV_P            R2, 0, R4, R4, R4   # 0x17fa
        C_MOV            R4, R1   # 0x17fe
        C_SHRI           R4, 9   # 0x1800
        C_XOR            R4, R2   # 0x1802
        C_ANDI           R4, 1   # 0x1804
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1806
        C_SHRI           R2, 1   # 0x180a
        C_AND            R2, R0   # 0x180c
        XOR              R4, R2, R3, R2   # 0x180e
        MOV_P            R2, 0, R4, R4, R4   # 0x1812
        C_MOV            R4, R1   # 0x1816
        C_SHRI           R4, 10   # 0x1818
        C_XOR            R4, R2   # 0x181a
        C_ANDI           R4, 1   # 0x181c
        SETP_NE_NPI      P0, R4, R4, 0   # 0x181e
        C_SHRI           R2, 1   # 0x1822
        C_AND            R2, R0   # 0x1824
        XOR              R4, R2, R3, R2   # 0x1826
        MOV_P            R2, 0, R4, R4, R4   # 0x182a
        C_MOV            R4, R1   # 0x182e
        C_SHRI           R4, 11   # 0x1830
        C_XOR            R4, R2   # 0x1832
        C_ANDI           R4, 1   # 0x1834
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1836
        C_SHRI           R2, 1   # 0x183a
        C_AND            R2, R0   # 0x183c
        XOR              R4, R2, R3, R2   # 0x183e
        MOV_P            R2, 0, R4, R4, R4   # 0x1842
        C_MOV            R4, R1   # 0x1846
        C_SHRI           R4, 12   # 0x1848
        C_XOR            R4, R2   # 0x184a
        C_ANDI           R4, 1   # 0x184c
        SETP_NE_NPI      P0, R4, R4, 0   # 0x184e
        C_SHRI           R2, 1   # 0x1852
        C_AND            R2, R0   # 0x1854
        XOR              R4, R2, R3, R2   # 0x1856
        MOV_P            R2, 0, R4, R4, R4   # 0x185a
        C_MOV            R4, R1   # 0x185e
        C_SHRI           R4, 13   # 0x1860
        C_XOR            R4, R2   # 0x1862
        C_ANDI           R4, 1   # 0x1864
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1866
        C_SHRI           R2, 1   # 0x186a
        C_AND            R2, R0   # 0x186c
        XOR              R4, R2, R3, R2   # 0x186e
        MOV_P            R2, 0, R4, R4, R4   # 0x1872
        C_MOV            R4, R1   # 0x1876
        C_SHRI           R4, 14   # 0x1878
        C_XOR            R4, R2   # 0x187a
        C_SHRI           R2, 1   # 0x187c
        C_AND            R2, R0   # 0x187e
        XOR              R3, R2, R3, R2   # 0x1880
        C_ANDI           R4, 1   # 0x1884
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1886
        MOV_P            R2, 0, R3, R3, R3   # 0x188a
        MOVI             R3, 32768   # 0x188e
        C_AND            R1, R3   # 0x1892
        C_SHRI           R1, 15   # 0x1894
        ANDI             R3, R2, 1   # 0x1896
        SETP_EQ_NP       P0, R1, R1, R3   # 0x189a
        C_SHRI           R2, 1   # 0x189e
        AND              R0, R2, R0, R2   # 0x18a0
        MOVI             R1, 40961   # 0x18a4
        XOR              R1, R0, R1, R0   # 0x18a8
        MOV_P            R1, 0, R0, R0, R0   # 0x18ac
        C_RET            224   # 0x18b0
        ST_LOCAL         R8, 68   # 0x18b2
        ST_LOCAL         R9, 72   # 0x18b6
        ST_LOCAL         R10, 76   # 0x18ba
        ST_LOCAL         R11, 80   # 0x18be
        ST_LOCAL         R12, 84   # 0x18c2
        ST_LOCAL         R13, 88   # 0x18c6
        ST_LOCAL         R14, 52   # 0x18ca
        ST_LOCAL         R4, 56   # 0x18ce
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x18d2
        SHLI             R0, R0, 16   # 0x18d6
        ST_LOCAL         R0, 36   # 0x18da
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x18de
        ST_LOCAL         R0, 40   # 0x18e2
        SHRI             R0, R0, 16   # 0x18e6
        ST_LOCAL         R0, 60   # 0x18ea
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x18ee
        SHLI             R0, R0, 16   # 0x18f2
        LD_GLOBAL_IDX    R7, R1, R2, 0, 8   # 0x18f6
        SHRI             R4, R7, 16   # 0x18fa
        C_OR             R0, R4   # 0x18fe
        LD_GLOBAL_IDX    R4, R1, R2, 0, 28   # 0x1900
        SHLI             R4, R4, 16   # 0x1904
        LD_GLOBAL_IDX    R5, R1, R2, 0, 24   # 0x1908
        SHRI             R6, R5, 16   # 0x190c
        C_OR             R4, R6   # 0x1910
        ST_LOCAL         R4, 12   # 0x1912
        MOVI             R6, 65535   # 0x1916
        AND              R4, R7, R6, R7   # 0x191a
        AND              R12, R5, R6, R5   # 0x191e
        LD_GLOBAL_IDX    R2, R1, R2, 0, 0   # 0x1922
        ST_LOCAL         R3, 44   # 0x1926
        ORI              R1, R3, -4096   # 0x192a
        ST_LOCAL         R1, 32   # 0x192e
        SETP_EQ_NPI      P0, R1, R2, 0   # 0x1932
        ANDI             R10, R2, -2   # 0x1936
        ANDI             R1, R2, 1   # 0x193a
        ST_LOCAL         R1, 24   # 0x193e
        ADDI             R1, R2, -1   # 0x1942
        ST_LOCAL         R1, 20   # 0x1946
        ANDI             R1, R2, -4   # 0x194a
        ST_LOCAL         R1, 48   # 0x194e
        MOVI             R15, 0   # 0x1952
        ST_LOCAL         R12, 16   # 0x1956
        BRA_PRED         0, L1bf8   # 0x195a
        ANDI             R1, R2, 3   # 0x195e
        MOVI             R5, 0   # 0x1962
        MOVI             R6, 0   # 0x1966
        LD_LOCAL         R7, 44   # 0x196a
        LD_LOCAL         R14, 48   # 0x196e
        C_BRA            L1980   # 0x1972
L1974:  C_ADD            R5, R2   # 0x1974
        C_ADDI           R6, 1   # 0x1976
        SETP_NE_NP       P0, R3, R6, R2   # 0x1978
        BRA_PRED         4, L1a04   # 0x197c
L1980:  LD_LOCAL         R3, 20   # 0x1980
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1984
        MOVI             R3, 0   # 0x1988
        BRA_PRED         0, L19d6   # 0x198c
L1990:  ADD              R8, R5, R3, R5   # 0x1990
        C_SHLI           R8, 1   # 0x1994
        ADD              R8, R4, R8, R4   # 0x1996
        SZ_GLOBAL_LD_U16 R9, R0, R8, 0, 0   # 0x199a
        C_ADD            R9, R7   # 0x199e
        SZ_GLOBAL_ST_16  R9, R0, R8, 0, 0   # 0x19a0
        ADDI             R9, R8, 2   # 0x19a4
        SZ_GLOBAL_LD_U16 R11, R0, R9, 0, 0   # 0x19a8
        C_ADD            R11, R7   # 0x19ac
        SZ_GLOBAL_ST_16  R11, R0, R9, 0, 0   # 0x19ae
        ADDI             R9, R8, 4   # 0x19b2
        SZ_GLOBAL_LD_U16 R11, R0, R9, 0, 0   # 0x19b6
        C_ADD            R11, R7   # 0x19ba
        SZ_GLOBAL_ST_16  R11, R0, R9, 0, 0   # 0x19bc
        C_ADDI           R8, 6   # 0x19c0
        SZ_GLOBAL_LD_U16 R9, R0, R8, 0, 0   # 0x19c2
        C_ADD            R9, R7   # 0x19c6
        SZ_GLOBAL_ST_16  R9, R0, R8, 0, 0   # 0x19c8
        C_ADDI           R3, 4   # 0x19cc
        SETP_NE_NP       P0, R8, R14, R3   # 0x19ce
        BRA_PRED         0, L1990   # 0x19d2
L19d6:  SETP_EQ_NPI      P0, R8, R1, 0   # 0x19d6
        BRA_PRED         0, L1974   # 0x19da
        C_ADD            R3, R5   # 0x19de
        C_MOV            R8, R1   # 0x19e0
L19e2:  C_MOV            R9, R3   # 0x19e2
        C_SHLI           R9, 1   # 0x19e4
        ADD              R9, R4, R9, R4   # 0x19e6
        SZ_GLOBAL_LD_U16 R11, R0, R9, 0, 0   # 0x19ea
        C_ADD            R11, R7   # 0x19ee
        SZ_GLOBAL_ST_16  R11, R0, R9, 0, 0   # 0x19f0
        C_ADDI           R3, 1   # 0x19f4
        ADDI             R8, R8, -1   # 0x19f6
        SETP_NE_NPI      P0, R9, R8, 0   # 0x19fa
        BRA_PRED         0, L19e2   # 0x19fe
        C_BRA            L1974   # 0x1a02
L1a04:  MOVI             R5, 0   # 0x1a04
        SHLI             R3, R7, 16   # 0x1a08
        SRAI             R8, R3, 16   # 0x1a0c
        MOVI             R11, 0   # 0x1a10
        C_BRA            L1a22   # 0x1a14
L1a16:  C_ADD            R5, R2   # 0x1a16
        C_ADDI           R11, 1   # 0x1a18
        SETP_NE_NP       P0, R3, R11, R2   # 0x1a1a
        BRA_PRED         4, L1af0   # 0x1a1e
L1a22:  LD_LOCAL         R3, 20   # 0x1a22
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1a26
        MOVI             R6, 0   # 0x1a2a
        LD_LOCAL         R7, 16   # 0x1a2e
        BRA_PRED         0, L1ab4   # 0x1a32
L1a36:  ADD              R3, R5, R6, R5   # 0x1a36
        C_MOV            R9, R3   # 0x1a3a
        C_SHLI           R9, 2   # 0x1a3c
        ADD              R9, R7, R9, R7   # 0x1a3e
        C_MOV            R12, R3   # 0x1a42
        C_SHLI           R12, 1   # 0x1a44
        ADD              R12, R4, R12, R4   # 0x1a46
        SZ_GLOBAL_LD_S16 R12, R0, R12, 0, 0   # 0x1a4a
        C_MUL_LO         R12, R8   # 0x1a4e
        LD_LOCAL         R15, 12   # 0x1a50
        ST_GLOBAL_IDX    R12, R15, R9, 0, 0   # 0x1a54
        ADDI             R9, R3, 1   # 0x1a58
        C_MOV            R12, R9   # 0x1a5c
        C_SHLI           R12, 2   # 0x1a5e
        ADD              R12, R7, R12, R7   # 0x1a60
        C_SHLI           R9, 1   # 0x1a64
        ADD              R9, R4, R9, R4   # 0x1a66
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1a6a
        C_MUL_LO         R9, R8   # 0x1a6e
        ST_GLOBAL_IDX    R9, R15, R12, 0, 0   # 0x1a70
        ADDI             R9, R3, 2   # 0x1a74
        C_MOV            R12, R9   # 0x1a78
        C_SHLI           R12, 2   # 0x1a7a
        ADD              R12, R7, R12, R7   # 0x1a7c
        C_SHLI           R9, 1   # 0x1a80
        ADD              R9, R4, R9, R4   # 0x1a82
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1a86
        C_MUL_LO         R9, R8   # 0x1a8a
        ST_GLOBAL_IDX    R9, R15, R12, 0, 0   # 0x1a8c
        C_ADDI           R3, 3   # 0x1a90
        C_MOV            R9, R3   # 0x1a92
        C_SHLI           R9, 2   # 0x1a94
        ADD              R9, R7, R9, R7   # 0x1a96
        C_SHLI           R3, 1   # 0x1a9a
        ADD              R3, R4, R3, R4   # 0x1a9c
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x1aa0
        C_MUL_LO         R3, R8   # 0x1aa4
        ST_GLOBAL_IDX    R3, R15, R9, 0, 0   # 0x1aa6
        C_ADDI           R6, 4   # 0x1aaa
        SETP_NE_NP       P0, R3, R14, R6   # 0x1aac
        BRA_PRED         0, L1a36   # 0x1ab0
L1ab4:  SETP_EQ_NPI      P0, R3, R1, 0   # 0x1ab4
        BRA_PRED         0, L1a16   # 0x1ab8
        ADD              R3, R6, R5, R6   # 0x1abc
        C_MOV            R6, R1   # 0x1ac0
L1ac2:  C_MOV            R9, R3   # 0x1ac2
        C_SHLI           R9, 2   # 0x1ac4
        ADD              R9, R7, R9, R7   # 0x1ac6
        C_MOV            R12, R3   # 0x1aca
        C_SHLI           R12, 1   # 0x1acc
        ADD              R12, R4, R12, R4   # 0x1ace
        SZ_GLOBAL_LD_S16 R12, R0, R12, 0, 0   # 0x1ad2
        C_MUL_LO         R12, R8   # 0x1ad6
        LD_LOCAL         R15, 12   # 0x1ad8
        ST_GLOBAL_IDX    R12, R15, R9, 0, 0   # 0x1adc
        C_ADDI           R3, 1   # 0x1ae0
        ADDI             R6, R6, -1   # 0x1ae2
        SETP_NE_NPI      P0, R9, R6, 0   # 0x1ae6
        BRA_PRED         0, L1ac2   # 0x1aea
        C_BRA            L1a16   # 0x1aee
L1af0:  MOVI             R5, 10   # 0x1af0
        MOVI             R9, 0   # 0x1af4
        MOVI             R8, 0   # 0x1af8
        MOVI             R15, 0   # 0x1afc
        MOVI             R11, 0   # 0x1b00
        MOVI             R13, 0   # 0x1b04
        LD_LOCAL         R12, 16   # 0x1b08
        LD_LOCAL         R14, 32   # 0x1b0c
        C_BRA            L1b1e   # 0x1b10
L1b12:  C_ADD            R9, R2   # 0x1b12
        C_ADDI           R8, 1   # 0x1b14
        SETP_NE_NP       P0, R3, R8, R2   # 0x1b16
        BRA_PRED         4, L1bf8   # 0x1b1a
L1b1e:  ST_LOCAL         R8, 28   # 0x1b1e
        LD_LOCAL         R3, 20   # 0x1b22
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1b26
        BRA_PRED         0, L1ba6   # 0x1b2a
        MOVI             R6, 0   # 0x1b2e
        C_MOV            R3, R11   # 0x1b32
L1b34:  C_MOV            R8, R9   # 0x1b34
        ADD              R9, R8, R6, R8   # 0x1b36
        C_SHLI           R9, 2   # 0x1b3a
        C_ADD            R9, R12   # 0x1b3c
        LD_LOCAL         R1, 12   # 0x1b3e
        LD_GLOBAL_IDX    R7, R1, R9, 0, 0   # 0x1b42
        C_ADDI           R9, 4   # 0x1b46
        LD_GLOBAL_IDX    R11, R1, R9, 0, 0   # 0x1b48
        SETP_LT_NP       P0, R9, R7, R11   # 0x1b4c
        MOVI             R9, 0   # 0x1b50
        ADDI_P           R9, 0, R9, 1   # 0x1b54
        ADD              R13, R7, R13, R7   # 0x1b58
        C_MOV            R5, R12   # 0x1b5c
        SETP_LT_NP       P0, R12, R14, R13   # 0x1b5e
        MOVI             R1, 0   # 0x1b62
        MOV_P            R13, 0, R1, R1, R1   # 0x1b66
        ADD              R13, R11, R13, R11   # 0x1b6a
        SETP_LT_NP       P1, R12, R14, R13   # 0x1b6e
        C_MOV            R12, R5   # 0x1b72
        MOVI             R5, 10   # 0x1b74
        MOV_P            R13, 1, R1, R1, R1   # 0x1b78
        MOV_P            R9, 1, R5, R5, R5   # 0x1b7c
        SETP_LT_NP       P1, R3, R3, R7   # 0x1b80
        MOVI             R3, 0   # 0x1b84
        ADDI_P           R3, 1, R3, 1   # 0x1b88
        MOV_P            R3, 0, R5, R5, R5   # 0x1b8c
        C_ADD            R3, R15   # 0x1b90
        ADD              R15, R9, R3, R9   # 0x1b92
        C_MOV            R9, R8   # 0x1b96
        C_ADDI           R6, 2   # 0x1b98
        SETP_NE_NP       P0, R3, R10, R6   # 0x1b9a
        C_MOV            R3, R11   # 0x1b9e
        BRA_PRED         0, L1b34   # 0x1ba0
        C_BRA            L1baa   # 0x1ba4
L1ba6:  MOVI             R6, 0   # 0x1ba6
L1baa:  LD_LOCAL         R3, 24   # 0x1baa
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1bae
        MOVI             R1, 0   # 0x1bb2
        LD_LOCAL         R8, 28   # 0x1bb6
        BRA_PRED         0, L1b12   # 0x1bba
        MUL_LO           R3, R8, R2, R2   # 0x1bbe
        ADD              R3, R6, R3, R6   # 0x1bc2
        C_SHLI           R3, 2   # 0x1bc6
        ADD              R3, R12, R3, R12   # 0x1bc8
        LD_LOCAL         R6, 12   # 0x1bcc
        LD_GLOBAL_IDX    R3, R6, R3, 0, 0   # 0x1bd0
        ADD              R13, R3, R13, R3   # 0x1bd4
        SETP_LT_NP       P0, R6, R14, R13   # 0x1bd8
        MOV_P            R13, 0, R1, R1, R1   # 0x1bdc
        SETP_LT_NP       P1, R6, R11, R3   # 0x1be0
        MOVI             R6, 0   # 0x1be4
        ADDI_P           R6, 1, R6, 1   # 0x1be8
        MOV_P            R6, 0, R5, R5, R5   # 0x1bec
        ADD              R15, R6, R15, R6   # 0x1bf0
        C_MOV            R11, R3   # 0x1bf4
        C_BRA            L1b12   # 0x1bf6
L1bf8:  ST_LOCAL         R15, 64   # 0x1bf8
        LD_LOCAL         R1, 36   # 0x1bfc
        LD_LOCAL         R3, 60   # 0x1c00
        OR               R13, R1, R3, R1   # 0x1c04
        LD_LOCAL         R1, 40   # 0x1c08
        MOVI             R3, 65535   # 0x1c0c
        AND              R6, R1, R3, R1   # 0x1c10
        SETP_EQ_NPI      P0, R1, R2, 0   # 0x1c14
        MOVI             R5, 0   # 0x1c18
        BRA_PRED         0, L1ddc   # 0x1c1c
        MOVI             R1, 0   # 0x1c20
        C_BRA            L1c46   # 0x1c24
L1c26:  C_MOV            R3, R5   # 0x1c26
        C_SHLI           R3, 2   # 0x1c28
        LD_LOCAL         R14, 16   # 0x1c2a
        ADD              R3, R14, R3, R14   # 0x1c2e
        LD_LOCAL         R14, 12   # 0x1c32
        ST_GLOBAL_IDX    R7, R14, R3, 0, 0   # 0x1c36
        C_ADD            R1, R2   # 0x1c3a
        C_ADDI           R5, 1   # 0x1c3c
        SETP_NE_NP       P0, R3, R5, R2   # 0x1c3e
        BRA_PRED         4, L1cb6   # 0x1c42
L1c46:  LD_LOCAL         R3, 20   # 0x1c46
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1c4a
        MOVI             R3, 0   # 0x1c4e
        MOVI             R7, 0   # 0x1c52
        BRA_PRED         0, L1c8a   # 0x1c56
L1c5a:  ADD              R8, R1, R3, R1   # 0x1c5a
        C_SHLI           R8, 1   # 0x1c5e
        C_ADD            R8, R4   # 0x1c60
        C_MOV            R9, R3   # 0x1c62
        C_SHLI           R9, 1   # 0x1c64
        C_ADD            R9, R6   # 0x1c66
        SZ_GLOBAL_LD_S16 R11, R13, R9, 0, 0   # 0x1c68
        SZ_GLOBAL_LD_S16 R12, R0, R8, 0, 0   # 0x1c6c
        MAD_ACC          R7, R11, R12   # 0x1c70
        C_ADDI           R9, 2   # 0x1c72
        SZ_GLOBAL_LD_S16 R9, R13, R9, 0, 0   # 0x1c74
        C_ADDI           R8, 2   # 0x1c78
        SZ_GLOBAL_LD_S16 R8, R0, R8, 0, 0   # 0x1c7a
        MAD_ACC          R7, R9, R8   # 0x1c7e
        C_ADDI           R3, 2   # 0x1c80
        SETP_NE_NP       P0, R8, R10, R3   # 0x1c82
        BRA_PRED         0, L1c5a   # 0x1c86
L1c8a:  LD_LOCAL         R14, 24   # 0x1c8a
        SETP_EQ_NPI      P0, R8, R14, 0   # 0x1c8e
        BRA_PRED         0, L1c26   # 0x1c92
        MUL_LO           R8, R5, R2, R2   # 0x1c96
        C_MOV            R9, R3   # 0x1c9a
        C_SHLI           R9, 1   # 0x1c9c
        ADD              R9, R6, R9, R6   # 0x1c9e
        SZ_GLOBAL_LD_S16 R9, R13, R9, 0, 0   # 0x1ca2
        C_ADD            R3, R8   # 0x1ca6
        C_SHLI           R3, 1   # 0x1ca8
        ADD              R3, R4, R3, R4   # 0x1caa
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x1cae
        MAD_ACC          R7, R9, R3   # 0x1cb2
        C_BRA            L1c26   # 0x1cb4
L1cb6:  MOVI             R3, 0   # 0x1cb6
        MOVI             R1, 0   # 0x1cba
        ST_LOCAL         R1, 36   # 0x1cbe
        MOVI             R5, 0   # 0x1cc2
        MOVI             R12, 0   # 0x1cc6
        MOVI             R11, 0   # 0x1cca
        C_BRA            L1ce8   # 0x1cce
L1cd0:  LD_LOCAL         R3, 28   # 0x1cd0
        C_ADD            R3, R2   # 0x1cd4
        LD_LOCAL         R1, 36   # 0x1cd6
        C_ADDI           R1, 1   # 0x1cda
        ST_LOCAL         R1, 36   # 0x1cdc
        SETP_NE_NP       P0, R1, R1, R2   # 0x1ce0
        BRA_PRED         4, L1ddc   # 0x1ce4
L1ce8:  ST_LOCAL         R3, 28   # 0x1ce8
        LD_LOCAL         R1, 20   # 0x1cec
        SETP_EQ_NPI      P0, R3, R1, 0   # 0x1cf0
        BRA_PRED         0, L1d7e   # 0x1cf4
        MOVI             R8, 0   # 0x1cf8
        C_MOV            R3, R12   # 0x1cfc
        LD_LOCAL         R15, 32   # 0x1cfe
        LD_LOCAL         R1, 16   # 0x1d02
        LD_LOCAL         R1, 28   # 0x1d06
L1d0a:  LD_LOCAL         R1, 28   # 0x1d0a
        ADD              R9, R1, R8, R1   # 0x1d0e
        C_SHLI           R9, 2   # 0x1d12
        LD_LOCAL         R1, 16   # 0x1d14
        C_ADD            R9, R1   # 0x1d18
        LD_LOCAL         R7, 12   # 0x1d1a
        LD_GLOBAL_IDX    R1, R7, R9, 0, 0   # 0x1d1e
        C_ADDI           R9, 4   # 0x1d22
        LD_GLOBAL_IDX    R12, R7, R9, 0, 0   # 0x1d24
        SETP_LT_NP       P0, R9, R1, R12   # 0x1d28
        MOVI             R9, 0   # 0x1d2c
        ADDI_P           R9, 0, R9, 1   # 0x1d30
        ADD              R11, R1, R11, R1   # 0x1d34
        C_MOV            R14, R5   # 0x1d38
        SETP_LT_NP       P0, R5, R15, R11   # 0x1d3a
        MOVI             R7, 0   # 0x1d3e
        MOV_P            R11, 0, R7, R7, R7   # 0x1d42
        ADD              R11, R12, R11, R12   # 0x1d46
        SETP_LT_NP       P1, R5, R15, R11   # 0x1d4a
        MOV_P            R11, 1, R7, R7, R7   # 0x1d4e
        MOVI             R5, 10   # 0x1d52
        MOV_P            R9, 1, R5, R5, R5   # 0x1d56
        SETP_LT_NP       P1, R1, R3, R1   # 0x1d5a
        MOVI             R1, 0   # 0x1d5e
        ADDI_P           R1, 1, R1, 1   # 0x1d62
        MOV_P            R1, 0, R5, R5, R5   # 0x1d66
        C_ADD            R1, R14   # 0x1d6a
        ADD              R5, R9, R1, R9   # 0x1d6c
        C_ADDI           R8, 2   # 0x1d70
        SETP_NE_NP       P0, R1, R10, R8   # 0x1d72
        C_MOV            R3, R12   # 0x1d76
        BRA_PRED         0, L1d0a   # 0x1d78
        C_BRA            L1d86   # 0x1d7c
L1d7e:  MOVI             R8, 0   # 0x1d7e
        LD_LOCAL         R15, 32   # 0x1d82
L1d86:  LD_LOCAL         R1, 24   # 0x1d86
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x1d8a
        MOVI             R14, 0   # 0x1d8e
        MOVI             R9, 10   # 0x1d92
        BRA_PRED         0, L1cd0   # 0x1d96
        LD_LOCAL         R1, 36   # 0x1d9a
        C_MUL_LO         R1, R2   # 0x1d9e
        ADD              R1, R8, R1, R8   # 0x1da0
        C_SHLI           R1, 2   # 0x1da4
        LD_LOCAL         R3, 16   # 0x1da6
        ADD              R1, R3, R1, R3   # 0x1daa
        LD_LOCAL         R3, 12   # 0x1dae
        LD_GLOBAL_IDX    R1, R3, R1, 0, 0   # 0x1db2
        ADD              R11, R1, R11, R1   # 0x1db6
        SETP_LT_NP       P0, R3, R15, R11   # 0x1dba
        MOV_P            R11, 0, R14, R14, R14   # 0x1dbe
        SETP_LT_NP       P1, R3, R12, R1   # 0x1dc2
        MOVI             R3, 0   # 0x1dc6
        ADDI_P           R3, 1, R3, 1   # 0x1dca
        MOV_P            R3, 0, R9, R9, R9   # 0x1dce
        ADD              R5, R3, R5, R3   # 0x1dd2
        C_MOV            R12, R1   # 0x1dd6
        BRA              L1cd0   # 0x1dd8
L1ddc:  ST_LOCAL         R5, 60   # 0x1ddc
        MOVI             R1, 0   # 0x1de0
        ST_LOCAL         R1, 36   # 0x1de4
        SETP_EQ_NPI      P0, R1, R2, 0   # 0x1de8
        C_MOV            R1, R2   # 0x1dec
        C_SHLI           R1, 1   # 0x1dee
        LD_LOCAL         R3, 12   # 0x1df0
        MOVI             R15, 0   # 0x1df4
        BRA_PRED         0, L2006   # 0x1df8
        MOVI             R5, 0   # 0x1dfc
        MOVI             R7, 0   # 0x1e00
        C_BRA            L1e16   # 0x1e04
L1e06:  C_ADD            R5, R2   # 0x1e06
        LD_LOCAL         R7, 28   # 0x1e08
        C_ADDI           R7, 1   # 0x1e0c
        SETP_NE_NP       P0, R3, R7, R2   # 0x1e0e
        BRA_PRED         4, L1ed2   # 0x1e12
L1e16:  ST_LOCAL         R7, 28   # 0x1e16
        MUL_LO           R8, R7, R2, R2   # 0x1e1a
        MOVI             R15, 0   # 0x1e1e
        C_BRA            L1e44   # 0x1e22
L1e24:  ADD              R3, R15, R8, R15   # 0x1e24
        C_SHLI           R3, 2   # 0x1e28
        LD_LOCAL         R14, 16   # 0x1e2a
        ADD              R3, R14, R3, R14   # 0x1e2e
        LD_LOCAL         R14, 12   # 0x1e32
        ST_GLOBAL_IDX    R7, R14, R3, 0, 0   # 0x1e36
        C_ADDI           R15, 1   # 0x1e3a
        SETP_NE_NP       P0, R3, R15, R2   # 0x1e3c
        BRA_PRED         4, L1e06   # 0x1e40
L1e44:  LD_LOCAL         R3, 20   # 0x1e44
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1e48
        BRA_PRED         0, L1e9e   # 0x1e4c
        MOVI             R9, 0   # 0x1e50
        C_MOV            R12, R15   # 0x1e54
        MOVI             R7, 0   # 0x1e56
L1e5a:  ADD              R11, R5, R9, R5   # 0x1e5a
        C_SHLI           R11, 1   # 0x1e5e
        C_ADD            R11, R4   # 0x1e60
        C_MOV            R3, R12   # 0x1e62
        C_SHLI           R3, 1   # 0x1e64
        ADD              R3, R6, R3, R6   # 0x1e66
        SZ_GLOBAL_LD_S16 R3, R13, R3, 0, 0   # 0x1e6a
        SZ_GLOBAL_LD_S16 R14, R0, R11, 0, 0   # 0x1e6e
        MADLO            R3, R3, R14, R7   # 0x1e72
        ADD              R7, R2, R12, R2   # 0x1e76
        C_SHLI           R7, 1   # 0x1e7a
        ADD              R7, R6, R7, R6   # 0x1e7c
        SZ_GLOBAL_LD_S16 R7, R13, R7, 0, 0   # 0x1e80
        ADDI             R14, R11, 2   # 0x1e84
        SZ_GLOBAL_LD_S16 R14, R0, R14, 0, 0   # 0x1e88
        MADLO            R7, R7, R14, R3   # 0x1e8c
        C_ADD            R12, R1   # 0x1e90
        C_ADDI           R9, 2   # 0x1e92
        SETP_NE_NP       P0, R3, R10, R9   # 0x1e94
        BRA_PRED         0, L1e5a   # 0x1e98
        C_BRA            L1ea6   # 0x1e9c
L1e9e:  MOVI             R9, 0   # 0x1e9e
        MOVI             R7, 0   # 0x1ea2
L1ea6:  LD_LOCAL         R3, 24   # 0x1ea6
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1eaa
        BRA_PRED         0, L1e24   # 0x1eae
        MADLO            R3, R9, R2, R15   # 0x1eb2
        C_SHLI           R3, 1   # 0x1eb6
        ADD              R3, R6, R3, R6   # 0x1eb8
        SZ_GLOBAL_LD_S16 R3, R13, R3, 0, 0   # 0x1ebc
        ADD              R14, R9, R8, R9   # 0x1ec0
        C_SHLI           R14, 1   # 0x1ec4
        ADD              R14, R4, R14, R4   # 0x1ec6
        SZ_GLOBAL_LD_S16 R14, R0, R14, 0, 0   # 0x1eca
        MAD_ACC          R7, R3, R14   # 0x1ece
        C_BRA            L1e24   # 0x1ed0
L1ed2:  MOVI             R14, 0   # 0x1ed2
        MOVI             R3, 0   # 0x1ed6
        ST_LOCAL         R3, 40   # 0x1eda
        MOVI             R15, 0   # 0x1ede
        MOVI             R12, 0   # 0x1ee2
        MOVI             R5, 0   # 0x1ee6
        LD_LOCAL         R11, 12   # 0x1eea
        C_BRA            L1f04   # 0x1eee
L1ef0:  C_ADD            R14, R2   # 0x1ef0
        LD_LOCAL         R3, 40   # 0x1ef2
        C_ADDI           R3, 1   # 0x1ef6
        ST_LOCAL         R3, 40   # 0x1ef8
        SETP_NE_NP       P0, R3, R3, R2   # 0x1efc
        BRA_PRED         4, L2006   # 0x1f00
L1f04:  LD_LOCAL         R3, 20   # 0x1f04
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1f08
        BRA_PRED         0, L1fa8   # 0x1f0c
        MOVI             R9, 0   # 0x1f10
        C_MOV            R3, R12   # 0x1f14
        LD_LOCAL         R7, 16   # 0x1f16
        LD_LOCAL         R7, 32   # 0x1f1a
L1f1e:  ST_LOCAL         R15, 28   # 0x1f1e
        C_MOV            R8, R14   # 0x1f22
        ADD              R14, R8, R9, R8   # 0x1f24
        C_SHLI           R14, 2   # 0x1f28
        LD_LOCAL         R7, 16   # 0x1f2a
        C_ADD            R14, R7   # 0x1f2e
        LD_LOCAL         R7, 12   # 0x1f30
        LD_GLOBAL_IDX    R15, R7, R14, 0, 0   # 0x1f34
        C_ADDI           R14, 4   # 0x1f38
        LD_LOCAL         R7, 12   # 0x1f3a
        LD_GLOBAL_IDX    R12, R7, R14, 0, 0   # 0x1f3e
        SETP_LT_NP       P0, R14, R15, R12   # 0x1f42
        MOVI             R14, 0   # 0x1f46
        ADDI_P           R14, 0, R14, 1   # 0x1f4a
        ADD              R5, R15, R5, R15   # 0x1f4e
        LD_LOCAL         R7, 32   # 0x1f52
        SETP_LT_NP       P0, R11, R7, R5   # 0x1f56
        MOVI             R11, 0   # 0x1f5a
        MOV_P            R5, 0, R11, R11, R11   # 0x1f5e
        ADD              R5, R12, R5, R12   # 0x1f62
        SETP_LT_NP       P1, R11, R7, R5   # 0x1f66
        MOVI             R7, 0   # 0x1f6a
        MOV_P            R5, 1, R7, R7, R7   # 0x1f6e
        MOVI             R7, 10   # 0x1f72
        MOV_P            R14, 1, R7, R7, R7   # 0x1f76
        SETP_LT_NP       P1, R3, R3, R15   # 0x1f7a
        LD_LOCAL         R11, 12   # 0x1f7e
        MOVI             R3, 0   # 0x1f82
        ADDI_P           R3, 1, R3, 1   # 0x1f86
        MOV_P            R3, 0, R7, R7, R7   # 0x1f8a
        LD_LOCAL         R7, 28   # 0x1f8e
        C_ADD            R3, R7   # 0x1f92
        ADD              R15, R14, R3, R14   # 0x1f94
        C_MOV            R14, R8   # 0x1f98
        C_ADDI           R9, 2   # 0x1f9a
        SETP_NE_NP       P0, R3, R10, R9   # 0x1f9c
        C_MOV            R3, R12   # 0x1fa0
        BRA_PRED         0, L1f1e   # 0x1fa2
        C_BRA            L1fac   # 0x1fa6
L1fa8:  MOVI             R9, 0   # 0x1fa8
L1fac:  LD_LOCAL         R3, 24   # 0x1fac
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1fb0
        MOVI             R8, 0   # 0x1fb4
        MOVI             R7, 10   # 0x1fb8
        BRA_PRED         0, L1ef0   # 0x1fbc
        LD_LOCAL         R3, 40   # 0x1fc0
        C_MUL_LO         R3, R2   # 0x1fc4
        ADD              R3, R9, R3, R9   # 0x1fc6
        C_SHLI           R3, 2   # 0x1fca
        C_MOV            R9, R14   # 0x1fcc
        LD_LOCAL         R14, 16   # 0x1fce
        ADD              R3, R14, R3, R14   # 0x1fd2
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x1fd6
        ADD              R5, R3, R5, R3   # 0x1fda
        LD_LOCAL         R14, 32   # 0x1fde
        SETP_LT_NP       P0, R14, R14, R5   # 0x1fe2
        MOV_P            R5, 0, R8, R8, R8   # 0x1fe6
        SETP_LT_NP       P1, R14, R12, R3   # 0x1fea
        MOVI             R14, 0   # 0x1fee
        ADDI_P           R14, 1, R14, 1   # 0x1ff2
        MOV_P            R14, 0, R7, R7, R7   # 0x1ff6
        ADD              R15, R14, R15, R14   # 0x1ffa
        C_MOV            R14, R9   # 0x1ffe
        C_MOV            R12, R3   # 0x2000
        BRA              L1ef0   # 0x2002
L2006:  ST_LOCAL         R15, 28   # 0x2006
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x200a
        BRA_PRED         0, L2228   # 0x200e
        MOVI             R5, 0   # 0x2012
        MOVI             R7, 0   # 0x2016
        C_BRA            L202c   # 0x201a
L201c:  C_ADD            R5, R2   # 0x201c
        LD_LOCAL         R7, 36   # 0x201e
        C_ADDI           R7, 1   # 0x2022
        SETP_NE_NP       P0, R3, R7, R2   # 0x2024
        BRA_PRED         4, L2114   # 0x2028
L202c:  ST_LOCAL         R7, 36   # 0x202c
        MUL_LO           R11, R7, R2, R2   # 0x2030
        MOVI             R3, 0   # 0x2034
        C_BRA            L205a   # 0x2038
L203a:  ADD              R7, R3, R11, R3   # 0x203a
        C_SHLI           R7, 2   # 0x203e
        LD_LOCAL         R14, 16   # 0x2040
        ADD              R7, R14, R7, R14   # 0x2044
        LD_LOCAL         R15, 12   # 0x2048
        ST_GLOBAL_IDX    R8, R15, R7, 0, 0   # 0x204c
        C_ADDI           R3, 1   # 0x2050
        SETP_NE_NP       P0, R7, R3, R2   # 0x2052
        BRA_PRED         4, L201c   # 0x2056
L205a:  LD_LOCAL         R7, 20   # 0x205a
        SETP_EQ_NPI      P0, R14, R7, 0   # 0x205e
        BRA_PRED         0, L20d2   # 0x2062
        MOVI             R9, 0   # 0x2066
        C_MOV            R12, R3   # 0x206a
        MOVI             R8, 0   # 0x206c
L2070:  ADD              R14, R5, R9, R5   # 0x2070
        C_SHLI           R14, 1   # 0x2074
        C_ADD            R14, R4   # 0x2076
        C_MOV            R15, R12   # 0x2078
        C_SHLI           R15, 1   # 0x207a
        ADD              R15, R6, R15, R6   # 0x207c
        SZ_GLOBAL_LD_U16 R15, R13, R15, 0, 0   # 0x2080
        SZ_GLOBAL_LD_U16 R7, R0, R14, 0, 0   # 0x2084
        MUL_LO           R7, R15, R7, R7   # 0x2088
        C_MOV            R15, R7   # 0x208c
        C_SHRI           R15, 5   # 0x208e
        ANDI             R15, R15, 127   # 0x2090
        C_SHRI           R7, 2   # 0x2094
        C_ANDI           R7, 15   # 0x2096
        MADLO            R7, R7, R15, R8   # 0x2098
        ADD              R15, R2, R12, R2   # 0x209c
        C_SHLI           R15, 1   # 0x20a0
        ADD              R15, R6, R15, R6   # 0x20a2
        SZ_GLOBAL_LD_U16 R15, R13, R15, 0, 0   # 0x20a6
        C_ADDI           R14, 2   # 0x20aa
        SZ_GLOBAL_LD_U16 R14, R0, R14, 0, 0   # 0x20ac
        MUL_LO           R14, R15, R14, R14   # 0x20b0
        C_MOV            R15, R14   # 0x20b4
        C_SHRI           R15, 5   # 0x20b6
        ANDI             R15, R15, 127   # 0x20b8
        C_SHRI           R14, 2   # 0x20bc
        C_ANDI           R14, 15   # 0x20be
        MADLO            R8, R14, R15, R7   # 0x20c0
        C_ADD            R12, R1   # 0x20c4
        C_ADDI           R9, 2   # 0x20c6
        SETP_NE_NP       P0, R7, R10, R9   # 0x20c8
        BRA_PRED         0, L2070   # 0x20cc
        C_BRA            L20da   # 0x20d0
L20d2:  MOVI             R9, 0   # 0x20d2
        MOVI             R8, 0   # 0x20d6
L20da:  LD_LOCAL         R7, 24   # 0x20da
        SETP_EQ_NPI      P0, R7, R7, 0   # 0x20de
        BRA_PRED         0, L203a   # 0x20e2
        MADLO            R7, R9, R2, R3   # 0x20e6
        C_SHLI           R7, 1   # 0x20ea
        ADD              R7, R6, R7, R6   # 0x20ec
        SZ_GLOBAL_LD_U16 R7, R13, R7, 0, 0   # 0x20f0
        ADD              R14, R9, R11, R9   # 0x20f4
        C_SHLI           R14, 1   # 0x20f8
        ADD              R14, R4, R14, R4   # 0x20fa
        SZ_GLOBAL_LD_U16 R14, R0, R14, 0, 0   # 0x20fe
        C_MUL_LO         R7, R14   # 0x2102
        C_MOV            R14, R7   # 0x2104
        C_SHRI           R14, 5   # 0x2106
        ANDI             R14, R14, 127   # 0x2108
        C_SHRI           R7, 2   # 0x210c
        C_ANDI           R7, 15   # 0x210e
        MAD_ACC          R8, R7, R14   # 0x2110
        C_BRA            L203a   # 0x2112
L2114:  MOVI             R11, 0   # 0x2114
        MOVI             R5, 10   # 0x2118
        MOVI             R6, 0   # 0x211c
        MOVI             R8, 0   # 0x2120
        MOVI             R1, 0   # 0x2124
        ST_LOCAL         R1, 36   # 0x2128
        MOVI             R13, 0   # 0x212c
        MOVI             R12, 0   # 0x2130
        C_BRA            L2142   # 0x2134
L2136:  C_ADD            R6, R2   # 0x2136
        C_ADDI           R8, 1   # 0x2138
        SETP_NE_NP       P0, R3, R8, R2   # 0x213a
        BRA_PRED         4, L2228   # 0x213e
L2142:  ST_LOCAL         R8, 40   # 0x2142
        LD_LOCAL         R3, 20   # 0x2146
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x214a
        BRA_PRED         0, L21ca   # 0x214e
        MOVI             R9, 0   # 0x2152
        C_MOV            R3, R13   # 0x2156
        LD_LOCAL         R8, 32   # 0x2158
        LD_LOCAL         R1, 36   # 0x215c
L2160:  ADD              R7, R6, R9, R6   # 0x2160
        C_SHLI           R7, 2   # 0x2164
        C_ADD            R7, R14   # 0x2166
        LD_GLOBAL_IDX    R14, R15, R7, 0, 0   # 0x2168
        C_ADDI           R7, 4   # 0x216c
        LD_GLOBAL_IDX    R13, R15, R7, 0, 0   # 0x216e
        SETP_LT_NP       P0, R7, R14, R13   # 0x2172
        MOVI             R7, 0   # 0x2176
        ADDI_P           R7, 0, R7, 1   # 0x217a
        ADD              R15, R14, R12, R14   # 0x217e
        SETP_LT_NP       P0, R11, R8, R15   # 0x2182
        MOVI             R11, 0   # 0x2186
        MOV_P            R15, 0, R11, R11, R11   # 0x218a
        ADD              R12, R13, R15, R13   # 0x218e
        SETP_LT_NP       P1, R15, R8, R12   # 0x2192
        LD_LOCAL         R15, 12   # 0x2196
        MOV_P            R12, 1, R11, R11, R11   # 0x219a
        MOV_P            R7, 1, R5, R5, R5   # 0x219e
        SETP_LT_NP       P1, R3, R3, R14   # 0x21a2
        LD_LOCAL         R14, 16   # 0x21a6
        MOVI             R3, 0   # 0x21aa
        ADDI_P           R3, 1, R3, 1   # 0x21ae
        MOV_P            R3, 0, R5, R5, R5   # 0x21b2
        C_ADD            R3, R1   # 0x21b6
        ADD              R1, R7, R3, R7   # 0x21b8
        C_ADDI           R9, 2   # 0x21bc
        SETP_NE_NP       P0, R3, R10, R9   # 0x21be
        C_MOV            R3, R13   # 0x21c2
        BRA_PRED         0, L2160   # 0x21c4
        C_BRA            L21d2   # 0x21c8
L21ca:  MOVI             R9, 0   # 0x21ca
        LD_LOCAL         R1, 36   # 0x21ce
L21d2:  ST_LOCAL         R1, 36   # 0x21d2
        LD_LOCAL         R3, 24   # 0x21d6
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x21da
        LD_LOCAL         R8, 40   # 0x21de
        BRA_PRED         0, L2136   # 0x21e2
        MUL_LO           R3, R8, R2, R2   # 0x21e6
        ADD              R3, R9, R3, R9   # 0x21ea
        C_SHLI           R3, 2   # 0x21ee
        ADD              R3, R14, R3, R14   # 0x21f0
        LD_GLOBAL_IDX    R3, R15, R3, 0, 0   # 0x21f4
        ADD              R12, R3, R12, R3   # 0x21f8
        LD_LOCAL         R7, 32   # 0x21fc
        SETP_LT_NP       P0, R7, R7, R12   # 0x2200
        MOV_P            R12, 0, R11, R11, R11   # 0x2204
        SETP_LT_NP       P1, R7, R13, R3   # 0x2208
        MOVI             R7, 0   # 0x220c
        ADDI_P           R7, 1, R7, 1   # 0x2210
        MOV_P            R7, 0, R5, R5, R5   # 0x2214
        LD_LOCAL         R1, 36   # 0x2218
        ADD              R1, R7, R1, R7   # 0x221c
        ST_LOCAL         R1, 36   # 0x2220
        C_MOV            R13, R3   # 0x2224
        C_BRA            L2136   # 0x2226
L2228:  SETP_EQ_NPI      P0, R1, R2, 0   # 0x2228
        LD_LOCAL         R8, 44   # 0x222c
        LD_LOCAL         R9, 48   # 0x2230
        LD_LOCAL         R10, 36   # 0x2234
        BRA_PRED         0, L22da   # 0x2238
        MOVI             R1, 0   # 0x223c
        ANDI             R5, R2, 3   # 0x2240
        MOVI             R3, 0   # 0x2244
        C_BRA            L2256   # 0x2248
L224a:  C_ADD            R1, R2   # 0x224a
        C_ADDI           R3, 1   # 0x224c
        SETP_NE_NP       P0, R6, R3, R2   # 0x224e
        BRA_PRED         4, L22da   # 0x2252
L2256:  LD_LOCAL         R6, 20   # 0x2256
        SETP_LT_U_NPI    P0, R6, R6, 3   # 0x225a
        MOVI             R6, 0   # 0x225e
        BRA_PRED         0, L22ac   # 0x2262
L2266:  ADD              R7, R1, R6, R1   # 0x2266
        C_SHLI           R7, 1   # 0x226a
        ADD              R7, R4, R7, R4   # 0x226c
        SZ_GLOBAL_LD_U16 R14, R0, R7, 0, 0   # 0x2270
        C_SUB            R14, R8   # 0x2274
        SZ_GLOBAL_ST_16  R14, R0, R7, 0, 0   # 0x2276
        ADDI             R14, R7, 2   # 0x227a
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x227e
        C_SUB            R15, R8   # 0x2282
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x2284
        ADDI             R14, R7, 4   # 0x2288
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x228c
        C_SUB            R15, R8   # 0x2290
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x2292
        C_ADDI           R7, 6   # 0x2296
        SZ_GLOBAL_LD_U16 R14, R0, R7, 0, 0   # 0x2298
        C_SUB            R14, R8   # 0x229c
        SZ_GLOBAL_ST_16  R14, R0, R7, 0, 0   # 0x229e
        C_ADDI           R6, 4   # 0x22a2
        SETP_NE_NP       P0, R7, R9, R6   # 0x22a4
        BRA_PRED         0, L2266   # 0x22a8
L22ac:  SETP_EQ_NPI      P0, R7, R5, 0   # 0x22ac
        BRA_PRED         0, L224a   # 0x22b0
        C_ADD            R6, R1   # 0x22b4
        C_MOV            R14, R5   # 0x22b6
L22b8:  C_MOV            R7, R6   # 0x22b8
        C_SHLI           R7, 1   # 0x22ba
        ADD              R7, R4, R7, R4   # 0x22bc
        SZ_GLOBAL_LD_U16 R15, R0, R7, 0, 0   # 0x22c0
        C_SUB            R15, R8   # 0x22c4
        SZ_GLOBAL_ST_16  R15, R0, R7, 0, 0   # 0x22c6
        C_ADDI           R6, 1   # 0x22ca
        ADDI             R14, R14, -1   # 0x22cc
        SETP_NE_NPI      P0, R7, R14, 0   # 0x22d0
        BRA_PRED         0, L22b8   # 0x22d4
        C_BRA            L224a   # 0x22d8
L22da:  LD_LOCAL         R0, 64   # 0x22da
        SHLI             R0, R0, 16   # 0x22de
        SRAI             R1, R0, 16   # 0x22e2
        MOVI             R2, 0   # 0x22e6
        CALL             R14, 129558   # 0x22ea
        C_MOV            R2, R1   # 0x22ee
        LD_LOCAL         R0, 60   # 0x22f0
        SHLI             R0, R0, 16   # 0x22f4
        SRAI             R1, R0, 16   # 0x22f8
        CALL             R14, 129549   # 0x22fc
        C_MOV            R2, R1   # 0x2300
        LD_LOCAL         R0, 28   # 0x2302
        SHLI             R0, R0, 16   # 0x2306
        SRAI             R1, R0, 16   # 0x230a
        CALL             R14, 129540   # 0x230e
        C_MOV            R2, R1   # 0x2312
        SHLI             R0, R10, 16   # 0x2314
        SRAI             R1, R0, 16   # 0x2318
        CALL             R14, 129533   # 0x231c
        MOVI             R0, 65535   # 0x2320
        LD_LOCAL         R2, 56   # 0x2324
        C_AND            R2, R0   # 0x2328
        SHLI             R0, R1, 16   # 0x232a
        SRAI             R1, R0, 16   # 0x232e
        CALL             R14, 129522   # 0x2332
        LD_LOCAL         R14, 52   # 0x2336
        LD_LOCAL         R13, 88   # 0x233a
        LD_LOCAL         R12, 84   # 0x233e
        LD_LOCAL         R11, 80   # 0x2342
        LD_LOCAL         R10, 76   # 0x2346
        LD_LOCAL         R9, 72   # 0x234a
        LD_LOCAL         R8, 68   # 0x234e
        C_RET            224   # 0x2352
        XOR              R0, R2, R1, R2   # 0x2354
        C_ANDI           R0, 1   # 0x2358
        SETP_NE_NPI      P0, R0, R0, 0   # 0x235a
        C_SHRI           R2, 1   # 0x235e
        MOVI48           R0, 4294942721   # 0x2360
        XOR              R3, R2, R0, R2   # 0x2366
        MOV_P            R2, 0, R3, R3, R3   # 0x236a
        C_MOV            R3, R1   # 0x236e
        C_SHRI           R3, 1   # 0x2370
        C_XOR            R3, R2   # 0x2372
        C_ANDI           R3, 1   # 0x2374
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2376
        C_SHRI           R2, 1   # 0x237a
        MOVI             R3, 32767   # 0x237c
        C_AND            R2, R3   # 0x2380
        XOR              R4, R2, R0, R2   # 0x2382
        MOV_P            R2, 0, R4, R4, R4   # 0x2386
        C_MOV            R4, R1   # 0x238a
        C_SHRI           R4, 2   # 0x238c
        C_XOR            R4, R2   # 0x238e
        C_ANDI           R4, 1   # 0x2390
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2392
        C_SHRI           R2, 1   # 0x2396
        C_AND            R2, R3   # 0x2398
        XOR              R4, R2, R0, R2   # 0x239a
        MOV_P            R2, 0, R4, R4, R4   # 0x239e
        C_MOV            R4, R1   # 0x23a2
        C_SHRI           R4, 3   # 0x23a4
        C_XOR            R4, R2   # 0x23a6
        C_ANDI           R4, 1   # 0x23a8
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23aa
        C_SHRI           R2, 1   # 0x23ae
        C_AND            R2, R3   # 0x23b0
        XOR              R4, R2, R0, R2   # 0x23b2
        MOV_P            R2, 0, R4, R4, R4   # 0x23b6
        C_MOV            R4, R1   # 0x23ba
        C_SHRI           R4, 4   # 0x23bc
        C_XOR            R4, R2   # 0x23be
        C_ANDI           R4, 1   # 0x23c0
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23c2
        C_SHRI           R2, 1   # 0x23c6
        C_AND            R2, R3   # 0x23c8
        XOR              R4, R2, R0, R2   # 0x23ca
        MOV_P            R2, 0, R4, R4, R4   # 0x23ce
        C_MOV            R4, R1   # 0x23d2
        C_SHRI           R4, 5   # 0x23d4
        C_XOR            R4, R2   # 0x23d6
        C_ANDI           R4, 1   # 0x23d8
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23da
        C_SHRI           R2, 1   # 0x23de
        C_AND            R2, R3   # 0x23e0
        XOR              R4, R2, R0, R2   # 0x23e2
        MOV_P            R2, 0, R4, R4, R4   # 0x23e6
        C_MOV            R4, R1   # 0x23ea
        C_SHRI           R4, 6   # 0x23ec
        C_XOR            R4, R2   # 0x23ee
        C_ANDI           R4, 1   # 0x23f0
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23f2
        C_SHRI           R2, 1   # 0x23f6
        C_AND            R2, R3   # 0x23f8
        XOR              R4, R2, R0, R2   # 0x23fa
        MOV_P            R2, 0, R4, R4, R4   # 0x23fe
        ANDI             R4, R1, 128   # 0x2402
        C_SHRI           R4, 7   # 0x2406
        ANDI             R5, R2, 1   # 0x2408
        SETP_EQ_NP       P0, R4, R4, R5   # 0x240c
        C_SHRI           R2, 1   # 0x2410
        C_AND            R2, R3   # 0x2412
        XOR              R4, R2, R0, R2   # 0x2414
        MOV_P            R4, 0, R2, R2, R2   # 0x2418
        C_MOV            R2, R1   # 0x241c
        C_SHRI           R2, 8   # 0x241e
        XOR              R2, R4, R2, R4   # 0x2420
        C_ANDI           R2, 1   # 0x2424
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2426
        C_SHRI           R4, 1   # 0x242a
        AND              R2, R4, R3, R4   # 0x242c
        XOR              R4, R2, R0, R2   # 0x2430
        MOV_P            R2, 0, R4, R4, R4   # 0x2434
        C_MOV            R4, R1   # 0x2438
        C_SHRI           R4, 9   # 0x243a
        C_XOR            R4, R2   # 0x243c
        C_ANDI           R4, 1   # 0x243e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2440
        C_SHRI           R2, 1   # 0x2444
        C_AND            R2, R3   # 0x2446
        XOR              R4, R2, R0, R2   # 0x2448
        MOV_P            R2, 0, R4, R4, R4   # 0x244c
        C_MOV            R4, R1   # 0x2450
        C_SHRI           R4, 10   # 0x2452
        C_XOR            R4, R2   # 0x2454
        C_ANDI           R4, 1   # 0x2456
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2458
        C_SHRI           R2, 1   # 0x245c
        C_AND            R2, R3   # 0x245e
        XOR              R4, R2, R0, R2   # 0x2460
        MOV_P            R2, 0, R4, R4, R4   # 0x2464
        C_MOV            R4, R1   # 0x2468
        C_SHRI           R4, 11   # 0x246a
        C_XOR            R4, R2   # 0x246c
        C_ANDI           R4, 1   # 0x246e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2470
        C_SHRI           R2, 1   # 0x2474
        C_AND            R2, R3   # 0x2476
        XOR              R4, R2, R0, R2   # 0x2478
        MOV_P            R2, 0, R4, R4, R4   # 0x247c
        C_MOV            R4, R1   # 0x2480
        C_SHRI           R4, 12   # 0x2482
        C_XOR            R4, R2   # 0x2484
        C_ANDI           R4, 1   # 0x2486
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2488
        C_SHRI           R2, 1   # 0x248c
        C_AND            R2, R3   # 0x248e
        XOR              R4, R2, R0, R2   # 0x2490
        MOV_P            R2, 0, R4, R4, R4   # 0x2494
        C_MOV            R4, R1   # 0x2498
        C_SHRI           R4, 13   # 0x249a
        C_XOR            R4, R2   # 0x249c
        C_ANDI           R4, 1   # 0x249e
        SETP_NE_NPI      P0, R4, R4, 0   # 0x24a0
        C_SHRI           R2, 1   # 0x24a4
        C_AND            R2, R3   # 0x24a6
        XOR              R4, R2, R0, R2   # 0x24a8
        MOV_P            R2, 0, R4, R4, R4   # 0x24ac
        C_MOV            R4, R1   # 0x24b0
        C_SHRI           R4, 14   # 0x24b2
        C_XOR            R4, R2   # 0x24b4
        C_SHRI           R2, 1   # 0x24b6
        C_AND            R2, R3   # 0x24b8
        XOR              R0, R2, R0, R2   # 0x24ba
        C_ANDI           R4, 1   # 0x24be
        SETP_NE_NPI      P0, R4, R4, 0   # 0x24c0
        MOV_P            R2, 0, R0, R0, R0   # 0x24c4
        C_SHRI           R1, 15   # 0x24c8
        ANDI             R0, R2, 1   # 0x24ca
        SETP_EQ_NP       P0, R0, R1, R0   # 0x24ce
        C_SHRI           R2, 1   # 0x24d2
        AND              R0, R2, R3, R2   # 0x24d4
        MOVI             R1, 40961   # 0x24d8
        XOR              R1, R0, R1, R0   # 0x24dc
        MOV_P            R1, 0, R0, R0, R0   # 0x24e0
        C_RET            224   # 0x24e4
        MOVI             R15, 2   # 0x24e6
        LD_GLOBAL        R15, R15, 24   # 0x24ea
        SRD              R0, 3   # 0x24ee
        C_ADD            R15, R0   # 0x24f0
        ST_LOCAL         R8, 172   # 0x24f2
        ST_LOCAL         R9, 176   # 0x24f6
        ST_LOCAL         R10, 180   # 0x24fa
        ST_LOCAL         R11, 184   # 0x24fe
        ST_LOCAL         R12, 188   # 0x2502
        ST_LOCAL         R13, 192   # 0x2506
        ST_LOCAL         R14, 164   # 0x250a
        C_MOV            R14, R3   # 0x250e
        ST_LOCAL         R2, 112   # 0x2510
        ST_LOCAL         R1, 116   # 0x2514
        LD_GLOBAL_IDX    R0, R1, R2, 0, 60   # 0x2518
        SHLI             R0, R0, 16   # 0x251c
        LD_GLOBAL_IDX    R4, R1, R2, 0, 56   # 0x2520
        SHRI             R3, R4, 16   # 0x2524
        OR               R12, R0, R3, R0   # 0x2528
        MOVI             R0, 65535   # 0x252c
        AND              R6, R4, R0, R4   # 0x2530
        SZ_GLOBAL_LD_S16 R1, R1, R2, 0, 4   # 0x2534
        SETP_LT_NPI      P0, R2, R1, 1   # 0x2538
        BRA_PRED         0, L281a   # 0x253c
        MOVI             R4, 0   # 0x2540
        ADDI             R2, R1, 255   # 0x2544
        ST_LOCAL         R2, 100   # 0x2548
        MOVI             R5, 0   # 0x254c
        MOVI             R7, 0   # 0x2550
        MOVI             R2, 0   # 0x2554
        ST_LOCAL         R2, 92   # 0x2558
        ST_LOCAL         R14, 96   # 0x255c
        C_MOV            R3, R14   # 0x2560
        C_BRA            L25c8   # 0x2562
L2564:  C_MOV            R12, R14   # 0x2564
        C_MOV            R6, R8   # 0x2566
        LD_GLOBAL_IDX    R2, R12, R6, 0, 0   # 0x2568
        LD_GLOBAL_IDX    R6, R12, R6, 0, 4   # 0x256c
        SHLI             R6, R6, 16   # 0x2570
        SHRI             R9, R2, 16   # 0x2574
        C_OR             R6, R9   # 0x2578
        C_AND            R2, R0   # 0x257a
        LD_GLOBAL_IDX    R9, R6, R2, 0, 8   # 0x257c
        LD_GLOBAL_IDX    R2, R6, R2, 0, 12   # 0x2580
        SHLI             R2, R2, 16   # 0x2584
        SHRI             R6, R9, 16   # 0x2588
        C_OR             R2, R6   # 0x258c
        AND              R6, R9, R0, R9   # 0x258e
        SZ_GLOBAL_LD_U16 R2, R2, R6, 0, 0   # 0x2592
        LD_LOCAL         R6, 92   # 0x2596
        C_ADDI           R6, 1   # 0x259a
        ST_LOCAL         R6, 92   # 0x259c
        C_SHRI           R2, 8   # 0x25a0
        ANDI             R11, R2, 1   # 0x25a2
L25a6:  AND              R2, R1, R0, R1   # 0x25a6
        C_ADDI           R4, 1   # 0x25aa
        AND              R6, R4, R0, R4   # 0x25ac
        SETP_NE_NP       P0, R2, R6, R2   # 0x25b0
        ADD              R5, R11, R5, R11   # 0x25b4
        MOVI             R2, 32768   # 0x25b8
        C_ANDN           R2, R3   # 0x25bc
        C_SHRI           R2, 15   # 0x25be
        C_ADD            R3, R2   # 0x25c0
        C_MOV            R6, R8   # 0x25c2
        BRA_PRED         4, L2800   # 0x25c4
L25c8:  SHLI             R2, R12, 16   # 0x25c8
        AND              R9, R2, R6, R2   # 0x25cc
        ADD              R10, R2, R6, R2   # 0x25d0
        C_OR             R2, R6   # 0x25d4
        C_ANDN           R2, R10   # 0x25d6
        OR               R2, R9, R2, R9   # 0x25d8
        SHRI             R2, R2, 31   # 0x25dc
        SHRI             R9, R12, 16   # 0x25e0
        ADD              R2, R9, R2, R9   # 0x25e4
        OR               R11, R10, R2, R10   # 0x25e8
        SHLI             R2, R3, 16   # 0x25ec
        SRAI             R2, R2, 16   # 0x25f0
        MOVI48           R14, 4294967295   # 0x25f4
        SETP_LT_NP       P0, R2, R14, R2   # 0x25fa
        BRA_PRED         4, L2662   # 0x25fe
        MOVI             R9, 0   # 0x2602
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x2606
        BRA_PRED         0, L2732   # 0x260a
        C_MOV            R14, R12   # 0x260e
        C_MOV            R8, R6   # 0x2610
        C_MOV            R10, R6   # 0x2612
L2614:  LD_GLOBAL_IDX    R2, R12, R10, 0, 8   # 0x2614
        LD_GLOBAL_IDX    R13, R12, R10, 0, 12   # 0x2618
        SHLI             R13, R13, 16   # 0x261c
        SHRI             R6, R2, 16   # 0x2620
        OR               R6, R13, R6, R13   # 0x2624
        C_MOV            R13, R3   # 0x2628
        C_AND            R2, R0   # 0x262a
        SZ_GLOBAL_LD_U16 R2, R6, R2, 0, 2   # 0x262c
        AND              R6, R13, R0, R13   # 0x2630
        SETP_EQ_NP       P0, R2, R2, R6   # 0x2634
        BRA_PRED         0, L26c4   # 0x2638
        LD_GLOBAL_IDX    R2, R12, R10, 0, 4   # 0x263c
        LD_GLOBAL_IDX    R6, R12, R10, 0, 0   # 0x2640
        SHRI             R10, R6, 16   # 0x2644
        SHLI             R12, R2, 16   # 0x2648
        C_OR             R12, R10   # 0x264c
        C_AND            R2, R0   # 0x264e
        OR               R2, R6, R2, R6   # 0x2650
        AND              R10, R6, R0, R6   # 0x2654
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x2658
        BRA_PRED         4, L2614   # 0x265c
        C_BRA            L26be   # 0x2660
L2662:  MOVI             R9, 0   # 0x2662
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x2666
        C_MOV            R14, R12   # 0x266a
        C_MOV            R8, R6   # 0x266c
        C_MOV            R10, R6   # 0x266e
        BRA_PRED         0, L26be   # 0x2670
L2674:  LD_GLOBAL_IDX    R2, R12, R10, 0, 8   # 0x2674
        LD_GLOBAL_IDX    R6, R12, R10, 0, 12   # 0x2678
        SHLI             R6, R6, 16   # 0x267c
        SHRI             R13, R2, 16   # 0x2680
        C_OR             R6, R13   # 0x2684
        C_AND            R2, R0   # 0x2686
        SZ_GLOBAL_LD_U16 R2, R6, R2, 0, 0   # 0x2688
        C_XOR            R2, R4   # 0x268c
        ANDI             R2, R2, 255   # 0x268e
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x2692
        BRA_PRED         0, L26c4   # 0x2696
        LD_GLOBAL_IDX    R2, R12, R10, 0, 4   # 0x269a
        LD_GLOBAL_IDX    R6, R12, R10, 0, 0   # 0x269e
        SHRI             R10, R6, 16   # 0x26a2
        SHLI             R12, R2, 16   # 0x26a6
        C_OR             R12, R10   # 0x26aa
        C_AND            R2, R0   # 0x26ac
        OR               R2, R6, R2, R6   # 0x26ae
        AND              R10, R6, R0, R6   # 0x26b2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x26b6
        BRA_PRED         0, L2674   # 0x26ba
L26be:  MOVI             R10, 0   # 0x26be
        C_BRA            L26c6   # 0x26c2
L26c4:  C_MOV            R9, R12   # 0x26c4
L26c6:  C_MOV            R12, R14   # 0x26c6
        C_MOV            R6, R8   # 0x26c8
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x26ca
        BRA_PRED         0, L273e   # 0x26ce
L26d2:  MOVI             R14, 0   # 0x26d2
        MOVI             R2, 0   # 0x26d6
L26da:  C_MOV            R13, R6   # 0x26da
        C_MOV            R11, R12   # 0x26dc
        SHLI             R6, R14, 16   # 0x26de
        AND              R12, R6, R2, R6   # 0x26e2
        ADD              R8, R6, R2, R6   # 0x26e6
        OR               R2, R6, R2, R6   # 0x26ea
        C_ANDN           R2, R8   # 0x26ee
        OR               R2, R12, R2, R12   # 0x26f0
        SHRI             R2, R2, 31   # 0x26f4
        SHRI             R6, R14, 16   # 0x26f8
        ADD              R2, R6, R2, R6   # 0x26fc
        LD_GLOBAL_IDX    R6, R11, R13, 0, 0   # 0x2700
        ST_GLOBAL_IDX    R8, R11, R13, 0, 0   # 0x2704
        LD_GLOBAL_IDX    R14, R11, R13, 0, 4   # 0x2708
        ST_GLOBAL_IDX    R2, R11, R13, 0, 4   # 0x270c
        SHRI             R2, R6, 16   # 0x2710
        SHLI             R12, R14, 16   # 0x2714
        C_OR             R12, R2   # 0x2718
        AND              R2, R14, R0, R14   # 0x271a
        OR               R2, R6, R2, R6   # 0x271e
        C_AND            R6, R0   # 0x2722
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2724
        C_MOV            R14, R11   # 0x2728
        C_MOV            R2, R13   # 0x272a
        BRA_PRED         0, L26da   # 0x272c
        C_BRA            L2746   # 0x2730
L2732:  MOVI             R10, 0   # 0x2732
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x2736
        BRA_PRED         4, L26d2   # 0x273a
L273e:  MOVI             R11, 0   # 0x273e
        MOVI             R13, 0   # 0x2742
L2746:  C_MOV            R8, R13   # 0x2746
        C_MOV            R14, R11   # 0x2748
        SHLI             R2, R9, 16   # 0x274a
        AND              R6, R2, R10, R2   # 0x274e
        ADD              R11, R2, R10, R2   # 0x2752
        C_OR             R2, R10   # 0x2756
        C_ANDN           R2, R11   # 0x2758
        OR               R2, R6, R2, R6   # 0x275a
        SHRI             R2, R2, 31   # 0x275e
        SHRI             R6, R9, 16   # 0x2762
        ADD              R2, R6, R2, R6   # 0x2766
        OR               R2, R11, R2, R11   # 0x276a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x276e
        BRA_PRED         4, L2564   # 0x2772
        LD_GLOBAL_IDX    R2, R9, R10, 0, 12   # 0x2776
        SHLI             R2, R2, 16   # 0x277a
        LD_GLOBAL_IDX    R6, R9, R10, 0, 8   # 0x277e
        SHRI             R11, R6, 16   # 0x2782
        C_OR             R2, R11   # 0x2786
        C_AND            R6, R0   # 0x2788
        SZ_GLOBAL_LD_U16 R6, R2, R6, 0, 0   # 0x278a
        LD_GLOBAL_IDX    R2, R9, R10, 0, 4   # 0x278e
        LD_GLOBAL_IDX    R12, R9, R10, 0, 0   # 0x2792
        C_MOV            R11, R6   # 0x2796
        C_SHRI           R11, 9   # 0x2798
        C_AND            R6, R11   # 0x279a
        AND              R11, R2, R0, R2   # 0x279c
        OR               R13, R12, R11, R12   # 0x27a0
        C_ADDI           R7, 1   # 0x27a4
        ANDI             R11, R6, 1   # 0x27a6
        SETP_EQ_NPI      P0, R6, R13, 0   # 0x27aa
        BRA_PRED         0, L27fa   # 0x27ae
        SHRI             R6, R12, 16   # 0x27b2
        SHLI             R2, R2, 16   # 0x27b6
        C_OR             R2, R6   # 0x27ba
        AND              R6, R12, R0, R12   # 0x27bc
        LD_GLOBAL_IDX    R12, R2, R6, 0, 0   # 0x27c0
        SZ_GLOBAL_LD_U16 R13, R2, R6, 0, 4   # 0x27c4
        ST_GLOBAL_IDX    R13, R9, R10, 0, 4   # 0x27c8
        ST_GLOBAL_IDX    R12, R9, R10, 0, 0   # 0x27cc
        C_MOV            R12, R14   # 0x27d0
        C_MOV            R14, R8   # 0x27d2
        LD_GLOBAL_IDX    R9, R12, R14, 0, 0   # 0x27d4
        SZ_GLOBAL_LD_U16 R10, R12, R14, 0, 4   # 0x27d8
        ST_GLOBAL_IDX    R10, R2, R6, 0, 4   # 0x27dc
        ST_GLOBAL_IDX    R9, R2, R6, 0, 0   # 0x27e0
        SHRI             R9, R2, 16   # 0x27e4
        ST_GLOBAL_IDX    R9, R12, R14, 0, 4   # 0x27e8
        SHLI             R2, R2, 16   # 0x27ec
        C_OR             R2, R6   # 0x27f0
        ST_GLOBAL_IDX    R2, R12, R14, 0, 0   # 0x27f2
        BRA              L25a6   # 0x27f6
L27fa:  C_MOV            R12, R14   # 0x27fa
        BRA              L25a6   # 0x27fc
L2800:  C_SHLI           R7, 2   # 0x2800
        LD_LOCAL         R0, 92   # 0x2802
        SUB              R0, R7, R0, R7   # 0x2806
        C_ADD            R0, R5   # 0x280a
        LD_LOCAL         R1, 100   # 0x280c
        ANDI             R1, R1, 255   # 0x2810
        LD_LOCAL         R14, 96   # 0x2814
        C_BRA            L2824   # 0x2818
L281a:  MOVI             R1, 0   # 0x281a
        C_MOV            R3, R14   # 0x281e
        MOVI             R0, 0   # 0x2820
L2824:  ST_LOCAL         R1, 168   # 0x2824
        ST_LOCAL         R3, 160   # 0x2828
        ST_LOCAL         R0, 156   # 0x282c
        SHLI             R0, R14, 16   # 0x2830
        SRAI             R0, R0, 16   # 0x2834
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2838
        BRA_PRED         0, L2d78   # 0x283c
        MOVI             R4, 1   # 0x2840
        MOVI             R7, 65535   # 0x2844
        MOVI             R8, 0   # 0x2848
        C_BRA            L2870   # 0x284c
L284e:  ST_GLOBAL_IDX    R8, R11, R10, 0, 4   # 0x284e
        ST_GLOBAL_IDX    R8, R11, R10, 0, 0   # 0x2852
        C_SHLI           R4, 1   # 0x2856
        LD_LOCAL         R0, 152   # 0x2858
        SETP_NE_NPI      P0, R0, R0, 0   # 0x285c
        LD_LOCAL         R9, 136   # 0x2860
        C_MOV            R12, R9   # 0x2864
        LD_LOCAL         R13, 140   # 0x2866
        C_MOV            R6, R13   # 0x286a
        BRA_PRED         4, L2d7c   # 0x286c
L2870:  MOVI             R5, 0   # 0x2870
        MOVI             R11, 0   # 0x2874
        MOVI             R10, 0   # 0x2878
        MOVI             R0, 0   # 0x287c
        ST_LOCAL         R0, 136   # 0x2880
        ST_LOCAL         R0, 140   # 0x2884
        LD_LOCAL         R0, 116   # 0x2888
        ST_LOCAL         R4, 144   # 0x288c
        C_BRA            L28a2   # 0x2890
L2892:  SETP_EQ_NPI      P0, R0, R0, 0   # 0x2892
        LD_LOCAL         R4, 144   # 0x2896
        LD_LOCAL         R5, 148   # 0x289a
        BRA_PRED         0, L284e   # 0x289e
L28a2:  SETP_LT_NPI      P0, R0, R4, 1   # 0x28a2
        BRA_PRED         0, L28e4   # 0x28a6
        MOVI             R2, 0   # 0x28aa
        C_MOV            R0, R12   # 0x28ae
        C_MOV            R1, R6   # 0x28b0
L28b2:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x28b2
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x28b6
        AND              R0, R3, R7, R3   # 0x28ba
        OR               R0, R1, R0, R1   # 0x28be
        SETP_NE_NPI      P0, R0, R0, 0   # 0x28c2
        BRA_PRED         4, L28ee   # 0x28c6
        SHRI             R0, R1, 16   # 0x28ca
        SHLI             R3, R3, 16   # 0x28ce
        OR               R0, R3, R0, R3   # 0x28d2
        C_AND            R1, R7   # 0x28d6
        C_ADDI           R2, 1   # 0x28d8
        SETP_EQ_NP       P0, R3, R4, R2   # 0x28da
        BRA_PRED         4, L28b2   # 0x28de
        C_BRA            L28fa   # 0x28e2
L28e4:  MOVI             R4, 0   # 0x28e4
        C_MOV            R0, R12   # 0x28e8
        C_MOV            R1, R6   # 0x28ea
        C_BRA            L28fa   # 0x28ec
L28ee:  MOVI             R0, 0   # 0x28ee
        ADDI             R4, R2, 1   # 0x28f2
        MOVI             R1, 0   # 0x28f6
L28fa:  ST_LOCAL         R5, 152   # 0x28fa
        ADDI             R2, R5, 1   # 0x28fe
        ST_LOCAL         R2, 148   # 0x2902
        C_MOV            R9, R12   # 0x2906
        C_MOV            R14, R6   # 0x2908
        C_MOV            R12, R0   # 0x290a
        C_MOV            R6, R1   # 0x290c
        LD_LOCAL         R0, 144   # 0x290e
        ST_LOCAL         R0, 96   # 0x2912
        C_BRA            L2934   # 0x2916
L2918:  ST_LOCAL         R4, 136   # 0x2918
        ST_LOCAL         R5, 140   # 0x291c
L2920:  C_MOV            R9, R1   # 0x2920
        C_MOV            R14, R3   # 0x2922
        C_MOV            R12, R0   # 0x2924
        C_MOV            R6, R2   # 0x2926
        C_MOV            R11, R4   # 0x2928
        C_MOV            R10, R5   # 0x292a
        MOVI             R7, 65535   # 0x292c
        LD_LOCAL         R4, 92   # 0x2930
L2934:  SETP_LT_NP       P0, R0, R8, R4   # 0x2934
        BRA_PRED         0, L2974   # 0x2938
        SHLI             R0, R12, 16   # 0x293c
        AND              R1, R0, R6, R0   # 0x2940
        ADD              R2, R0, R6, R0   # 0x2944
        C_OR             R0, R6   # 0x2948
        C_ANDN           R0, R2   # 0x294a
        OR               R0, R1, R0, R1   # 0x294c
        SHRI             R0, R0, 31   # 0x2950
        SHRI             R1, R12, 16   # 0x2954
        ADD              R0, R1, R0, R1   # 0x2958
        OR               R0, R2, R0, R2   # 0x295c
        LD_LOCAL         R1, 96   # 0x2960
        SETP_LT_NPI      P0, R1, R1, 1   # 0x2964
        BRA_PRED         0, L2892   # 0x2968
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x296c
        BRA_PRED         0, L2892   # 0x2970
L2974:  SETP_NE_NPI      P0, R0, R4, 0   # 0x2974
        BRA_PRED         4, L2a8e   # 0x2978
        LD_LOCAL         R0, 96   # 0x297c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2980
        BRA_PRED         0, L2ac4   # 0x2984
        SHLI             R0, R12, 16   # 0x2988
        AND              R1, R0, R6, R0   # 0x298c
        ADD              R2, R0, R6, R0   # 0x2990
        C_OR             R0, R6   # 0x2994
        C_ANDN           R0, R2   # 0x2996
        OR               R0, R1, R0, R1   # 0x2998
        SHRI             R0, R0, 31   # 0x299c
        SHRI             R1, R12, 16   # 0x29a0
        ADD              R0, R1, R0, R1   # 0x29a4
        OR               R0, R2, R0, R2   # 0x29a8
        SETP_NE_NPI      P0, R0, R0, 0   # 0x29ac
        BRA_PRED         4, L2ac4   # 0x29b0
        LD_GLOBAL_IDX    R3, R12, R6, 0, 8   # 0x29b4
        ST_LOCAL         R12, 100   # 0x29b8
        LD_GLOBAL_IDX    R5, R12, R6, 0, 12   # 0x29bc
        LD_GLOBAL_IDX    R0, R9, R14, 0, 8   # 0x29c0
        LD_GLOBAL_IDX    R1, R9, R14, 0, 12   # 0x29c4
        SHLI             R1, R1, 16   # 0x29c8
        SHRI             R2, R0, 16   # 0x29cc
        OR               R13, R1, R2, R1   # 0x29d0
        AND              R1, R0, R7, R0   # 0x29d4
        SZ_GLOBAL_LD_U16 R12, R13, R1, 0, 0   # 0x29d8
        ANDI             R0, R12, 128   # 0x29dc
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x29e0
        ST_LOCAL         R4, 92   # 0x29e4
        ST_LOCAL         R6, 104   # 0x29e8
        ST_LOCAL         R14, 108   # 0x29ec
        BRA_PRED         4, L2aee   # 0x29f0
        ST_LOCAL         R1, 128   # 0x29f4
        ST_LOCAL         R13, 132   # 0x29f8
        ST_LOCAL         R5, 124   # 0x29fc
        ST_LOCAL         R3, 120   # 0x2a00
        C_MOV            R0, R12   # 0x2a04
        C_SHRI           R0, 3   # 0x2a06
        C_ANDI           R0, 15   # 0x2a08
        MULI             R3, R0, 17   # 0x2a0a
        ANDI             R0, R12, 7   # 0x2a0e
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x2a12
        LD_LOCAL         R8, 116   # 0x2a16
        BRA_PRED         0, L2af8   # 0x2a1a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2a1e
        C_MOV            R6, R12   # 0x2a22
        BRA_PRED         0, L2b2c   # 0x2a24
        MOVI             R0, 34   # 0x2a28
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x2a2c
        MOVI             R6, 34   # 0x2a30
        MOV_P            R6, 0, R3, R3, R3   # 0x2a34
        C_MOV            R13, R8   # 0x2a38
        LD_LOCAL         R8, 112   # 0x2a3a
        SZ_GLOBAL_LD_U16 R5, R13, R8, 0, 2   # 0x2a3e
        SZ_GLOBAL_LD_U16 R4, R13, R8, 0, 0   # 0x2a42
        LD_GLOBAL_IDX    R1, R13, R8, 0, 40   # 0x2a46
        LD_GLOBAL_IDX    R0, R13, R8, 0, 32   # 0x2a4a
        LD_GLOBAL_IDX    R2, R13, R8, 0, 36   # 0x2a4e
        SZ_GLOBAL_LD_U16 R3, R13, R8, 0, 96   # 0x2a52
        ST_GLOBAL        R3, R15, 32   # 0x2a56
        SHLI             R2, R2, 16   # 0x2a5a
        SHRI             R3, R0, 16   # 0x2a5e
        C_OR             R2, R3   # 0x2a62
        AND              R3, R0, R7, R0   # 0x2a64
        CALL             R14, 127650   # 0x2a68
        MOVI             R15, 2   # 0x2a6c
        LD_GLOBAL        R15, R15, 24   # 0x2a70
        SRD              R3, 3   # 0x2a74
        C_ADD            R15, R3   # 0x2a76
        C_MOV            R6, R1   # 0x2a78
        SZ_GLOBAL_LD_U16 R0, R13, R8, 0, 102   # 0x2a7a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2a7e
        BRA_PRED         0, L2a8a   # 0x2a82
        SZ_GLOBAL_ST_16  R6, R13, R8, 0, 102   # 0x2a86
L2a8a:  C_MOV            R8, R13   # 0x2a8a
        C_BRA            L2b28   # 0x2a8c
L2a8e:  LD_GLOBAL_IDX    R1, R12, R6, 0, 0   # 0x2a8e
        LD_GLOBAL_IDX    R0, R12, R6, 0, 4   # 0x2a92
        SHLI             R0, R0, 16   # 0x2a96
        SHRI             R2, R1, 16   # 0x2a9a
        C_OR             R0, R2   # 0x2a9e
        AND              R2, R1, R7, R1   # 0x2aa0
        MOVI             R1, 0   # 0x2aa4
        ST_LOCAL         R1, 92   # 0x2aa8
        LD_LOCAL         R1, 96   # 0x2aac
        ADDI             R1, R1, -1   # 0x2ab0
        ST_LOCAL         R1, 96   # 0x2ab4
        C_MOV            R1, R9   # 0x2ab8
        C_MOV            R3, R14   # 0x2aba
        C_MOV            R4, R12   # 0x2abc
        C_MOV            R5, R6   # 0x2abe
        BRA              L2d20   # 0x2ac0
L2ac4:  LD_GLOBAL_IDX    R0, R9, R14, 0, 0   # 0x2ac4
        LD_GLOBAL_IDX    R1, R9, R14, 0, 4   # 0x2ac8
        SHLI             R1, R1, 16   # 0x2acc
        SHRI             R2, R0, 16   # 0x2ad0
        C_OR             R1, R2   # 0x2ad4
        AND              R3, R0, R7, R0   # 0x2ad6
        ADDI             R4, R4, -1   # 0x2ada
        ST_LOCAL         R4, 92   # 0x2ade
        C_MOV            R0, R12   # 0x2ae2
        C_MOV            R2, R6   # 0x2ae4
        C_MOV            R4, R9   # 0x2ae6
        C_MOV            R5, R14   # 0x2ae8
        BRA              L2d20   # 0x2aea
L2aee:  ANDI             R2, R12, 127   # 0x2aee
        LD_LOCAL         R8, 116   # 0x2af2
        C_BRA            L2b7e   # 0x2af6
L2af8:  LD_LOCAL         R13, 112   # 0x2af8
        SZ_GLOBAL_LD_U16 R4, R8, R13, 0, 96   # 0x2afc
        ADDI             R2, R13, 64   # 0x2b00
        C_MOV            R1, R8   # 0x2b04
        CALL             R14, 128724   # 0x2b06
        MOVI             R15, 2   # 0x2b0a
        LD_GLOBAL        R15, R15, 24   # 0x2b0e
        SRD              R3, 3   # 0x2b12
        C_ADD            R15, R3   # 0x2b14
        C_MOV            R6, R1   # 0x2b16
        SZ_GLOBAL_LD_U16 R0, R8, R13, 0, 100   # 0x2b18
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2b1c
        BRA_PRED         0, L2b28   # 0x2b20
        SZ_GLOBAL_ST_16  R6, R8, R13, 0, 100   # 0x2b24
L2b28:  MOVI             R7, 65535   # 0x2b28
L2b2c:  AND              R1, R6, R7, R6   # 0x2b2c
        LD_LOCAL         R7, 112   # 0x2b30
        SZ_GLOBAL_LD_U16 R2, R8, R7, 0, 96   # 0x2b34
        CALL             R14, 130060   # 0x2b38
        MOVI             R15, 2   # 0x2b3c
        LD_GLOBAL        R15, R15, 24   # 0x2b40
        SRD              R3, 3   # 0x2b44
        C_ADD            R15, R3   # 0x2b46
        SZ_GLOBAL_ST_16  R1, R8, R7, 0, 96   # 0x2b48
        MOVI             R7, 65535   # 0x2b4c
        MOVI             R0, 65280   # 0x2b50
        AND              R0, R12, R0, R12   # 0x2b54
        ANDI             R2, R6, 127   # 0x2b58
        C_OR             R0, R2   # 0x2b5c
        ORI              R0, R0, 128   # 0x2b5e
        LD_LOCAL         R1, 128   # 0x2b62
        LD_LOCAL         R3, 132   # 0x2b66
        SZ_GLOBAL_ST_16  R0, R3, R1, 0, 0   # 0x2b6a
        LD_LOCAL         R6, 104   # 0x2b6e
        LD_LOCAL         R14, 108   # 0x2b72
        LD_LOCAL         R3, 120   # 0x2b76
        LD_LOCAL         R5, 124   # 0x2b7a
L2b7e:  SHLI             R0, R5, 16   # 0x2b7e
        SHRI             R1, R3, 16   # 0x2b82
        OR               R13, R0, R1, R0   # 0x2b86
        AND              R1, R3, R7, R3   # 0x2b8a
        SZ_GLOBAL_LD_U16 R12, R13, R1, 0, 0   # 0x2b8e
        ANDI             R0, R12, 128   # 0x2b92
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2b96
        BRA_PRED         4, L2c2c   # 0x2b9a
        ST_LOCAL         R1, 128   # 0x2b9e
        ST_LOCAL         R2, 120   # 0x2ba2
        C_MOV            R0, R12   # 0x2ba6
        C_SHRI           R0, 3   # 0x2ba8
        C_ANDI           R0, 15   # 0x2baa
        MULI             R3, R0, 17   # 0x2bac
        ANDI             R0, R12, 7   # 0x2bb0
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x2bb4
        ST_LOCAL         R13, 124   # 0x2bb8
        BRA_PRED         0, L2c36   # 0x2bbc
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2bc0
        C_MOV            R6, R12   # 0x2bc4
        BRA_PRED         0, L2c6e   # 0x2bc6
        MOVI             R0, 34   # 0x2bca
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x2bce
        MOVI             R6, 34   # 0x2bd2
        MOV_P            R6, 0, R3, R3, R3   # 0x2bd6
        LD_LOCAL         R13, 112   # 0x2bda
        SZ_GLOBAL_LD_U16 R5, R8, R13, 0, 2   # 0x2bde
        SZ_GLOBAL_LD_U16 R4, R8, R13, 0, 0   # 0x2be2
        LD_GLOBAL_IDX    R1, R8, R13, 0, 40   # 0x2be6
        LD_GLOBAL_IDX    R0, R8, R13, 0, 32   # 0x2bea
        LD_GLOBAL_IDX    R2, R8, R13, 0, 36   # 0x2bee
        SZ_GLOBAL_LD_U16 R3, R8, R13, 0, 96   # 0x2bf2
        ST_GLOBAL        R3, R15, 32   # 0x2bf6
        SHLI             R2, R2, 16   # 0x2bfa
        SHRI             R3, R0, 16   # 0x2bfe
        C_OR             R2, R3   # 0x2c02
        AND              R3, R0, R7, R0   # 0x2c04
        CALL             R14, 127442   # 0x2c08
        MOVI             R15, 2   # 0x2c0c
        LD_GLOBAL        R15, R15, 24   # 0x2c10
        SRD              R3, 3   # 0x2c14
        C_ADD            R15, R3   # 0x2c16
        C_MOV            R6, R1   # 0x2c18
        SZ_GLOBAL_LD_U16 R0, R8, R13, 0, 102   # 0x2c1a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2c1e
        BRA_PRED         0, L2c6a   # 0x2c22
        SZ_GLOBAL_ST_16  R6, R8, R13, 0, 102   # 0x2c26
        C_BRA            L2c6a   # 0x2c2a
L2c2c:  MOVI             R13, 65535   # 0x2c2c
        ANDI             R0, R12, 127   # 0x2c30
        C_BRA            L2cbc   # 0x2c34
L2c36:  LD_LOCAL         R0, 112   # 0x2c36
        SZ_GLOBAL_LD_U16 R4, R8, R0, 0, 96   # 0x2c3a
        ADDI             R2, R0, 64   # 0x2c3e
        C_MOV            R1, R8   # 0x2c42
        CALL             R14, 128565   # 0x2c44
        MOVI             R15, 2   # 0x2c48
        LD_GLOBAL        R15, R15, 24   # 0x2c4c
        SRD              R3, 3   # 0x2c50
        C_ADD            R15, R3   # 0x2c52
        C_MOV            R6, R1   # 0x2c54
        LD_LOCAL         R1, 112   # 0x2c56
        SZ_GLOBAL_LD_U16 R0, R8, R1, 0, 100   # 0x2c5a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2c5e
        BRA_PRED         0, L2c6a   # 0x2c62
        SZ_GLOBAL_ST_16  R6, R8, R1, 0, 100   # 0x2c66
L2c6a:  MOVI             R7, 65535   # 0x2c6a
L2c6e:  MOVI             R13, 65535   # 0x2c6e
        AND              R1, R6, R7, R6   # 0x2c72
        LD_LOCAL         R7, 112   # 0x2c76
        SZ_GLOBAL_LD_U16 R2, R8, R7, 0, 96   # 0x2c7a
        CALL             R14, 129897   # 0x2c7e
        MOVI             R15, 2   # 0x2c82
        LD_GLOBAL        R15, R15, 24   # 0x2c86
        SRD              R3, 3   # 0x2c8a
        C_ADD            R15, R3   # 0x2c8c
        SZ_GLOBAL_ST_16  R1, R8, R7, 0, 96   # 0x2c8e
        MOVI             R0, 65280   # 0x2c92
        AND              R1, R12, R0, R12   # 0x2c96
        ANDI             R0, R6, 127   # 0x2c9a
        C_OR             R1, R0   # 0x2c9e
        ORI              R1, R1, 128   # 0x2ca0
        LD_LOCAL         R2, 124   # 0x2ca4
        LD_LOCAL         R3, 128   # 0x2ca8
        SZ_GLOBAL_ST_16  R1, R2, R3, 0, 0   # 0x2cac
        LD_LOCAL         R6, 104   # 0x2cb0
        LD_LOCAL         R14, 108   # 0x2cb4
        LD_LOCAL         R2, 120   # 0x2cb8
L2cbc:  SETP_LT_U_NP     P0, R0, R0, R2   # 0x2cbc
        LD_LOCAL         R4, 100   # 0x2cc0
        BRA_PRED         4, L2cf2   # 0x2cc4
        LD_GLOBAL_IDX    R1, R4, R6, 0, 0   # 0x2cc8
        LD_GLOBAL_IDX    R0, R4, R6, 0, 4   # 0x2ccc
        SHLI             R0, R0, 16   # 0x2cd0
        SHRI             R2, R1, 16   # 0x2cd4
        C_OR             R0, R2   # 0x2cd8
        AND              R2, R1, R13, R1   # 0x2cda
        LD_LOCAL         R1, 96   # 0x2cde
        ADDI             R1, R1, -1   # 0x2ce2
        ST_LOCAL         R1, 96   # 0x2ce6
        C_MOV            R1, R9   # 0x2cea
        C_MOV            R3, R14   # 0x2cec
        C_MOV            R5, R6   # 0x2cee
        C_BRA            L2d1c   # 0x2cf0
L2cf2:  LD_GLOBAL_IDX    R0, R9, R14, 0, 0   # 0x2cf2
        LD_GLOBAL_IDX    R1, R9, R14, 0, 4   # 0x2cf6
        SHLI             R1, R1, 16   # 0x2cfa
        SHRI             R2, R0, 16   # 0x2cfe
        C_OR             R1, R2   # 0x2d02
        AND              R3, R0, R13, R0   # 0x2d04
        LD_LOCAL         R0, 92   # 0x2d08
        ADDI             R0, R0, -1   # 0x2d0c
        ST_LOCAL         R0, 92   # 0x2d10
        C_MOV            R0, R4   # 0x2d14
        C_MOV            R2, R6   # 0x2d16
        C_MOV            R4, R9   # 0x2d18
        C_MOV            R5, R14   # 0x2d1a
L2d1c:  MOVI             R8, 0   # 0x2d1c
L2d20:  SHLI             R6, R11, 16   # 0x2d20
        AND              R7, R6, R10, R6   # 0x2d24
        ADD              R14, R6, R10, R6   # 0x2d28
        C_OR             R6, R10   # 0x2d2c
        C_ANDN           R6, R14   # 0x2d2e
        OR               R6, R7, R6, R7   # 0x2d30
        SHRI             R6, R6, 31   # 0x2d34
        SHRI             R7, R11, 16   # 0x2d38
        ADD              R6, R7, R6, R7   # 0x2d3c
        OR               R6, R14, R6, R14   # 0x2d40
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x2d44
        BRA_PRED         0, L2918   # 0x2d48
        SHLI             R6, R4, 16   # 0x2d4c
        ADD              R7, R6, R5, R6   # 0x2d50
        ST_GLOBAL_IDX    R7, R11, R10, 0, 0   # 0x2d54
        OR               R14, R6, R5, R6   # 0x2d58
        ANDN             R7, R14, R7, R14   # 0x2d5c
        C_AND            R6, R5   # 0x2d60
        C_OR             R6, R7   # 0x2d62
        SHRI             R6, R6, 31   # 0x2d64
        SHRI             R7, R4, 16   # 0x2d68
        ADD              R6, R7, R6, R7   # 0x2d6c
        ST_GLOBAL_IDX    R6, R11, R10, 0, 4   # 0x2d70
        BRA              L2920   # 0x2d74
L2d78:  C_MOV            R9, R12   # 0x2d78
        C_MOV            R13, R6   # 0x2d7a
L2d7c:  LD_GLOBAL_IDX    R1, R9, R13, 0, 0   # 0x2d7c
        LD_GLOBAL_IDX    R0, R9, R13, 0, 4   # 0x2d80
        SHLI             R0, R0, 16   # 0x2d84
        SHRI             R2, R1, 16   # 0x2d88
        OR               R3, R0, R2, R0   # 0x2d8c
        MOVI             R0, 65535   # 0x2d90
        AND              R4, R1, R0, R1   # 0x2d94
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x2d98
        SHLI             R1, R1, 16   # 0x2d9c
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x2da0
        SHRI             R5, R2, 16   # 0x2da4
        OR               R7, R1, R5, R1   # 0x2da8
        AND              R8, R2, R0, R2   # 0x2dac
        LD_GLOBAL_IDX    R5, R7, R8, 0, 8   # 0x2db0
        SZ_GLOBAL_LD_U16 R1, R7, R8, 0, 12   # 0x2db4
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x2db8
        ST_GLOBAL_IDX    R1, R3, R4, 0, 12   # 0x2dbc
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x2dc0
        ST_GLOBAL_IDX    R5, R3, R4, 0, 8   # 0x2dc4
        AND              R5, R2, R0, R2   # 0x2dc8
        ST_GLOBAL_IDX    R5, R7, R8, 0, 12   # 0x2dcc
        ST_GLOBAL_IDX    R1, R7, R8, 0, 8   # 0x2dd0
        LD_GLOBAL_IDX    R5, R7, R8, 0, 0   # 0x2dd4
        SZ_GLOBAL_LD_U16 R6, R7, R8, 0, 4   # 0x2dd8
        ST_GLOBAL_IDX    R6, R3, R4, 0, 4   # 0x2ddc
        ST_GLOBAL_IDX    R5, R3, R4, 0, 0   # 0x2de0
        LD_LOCAL         R3, 160   # 0x2de4
        SHLI             R3, R3, 16   # 0x2de8
        SRAI             R3, R3, 16   # 0x2dec
        MOVI48           R4, 4294967295   # 0x2df0
        SETP_LT_NP       P0, R3, R4, R3   # 0x2df6
        MOVI             R3, 0   # 0x2dfa
        ST_GLOBAL_IDX    R3, R7, R8, 0, 4   # 0x2dfe
        ST_GLOBAL_IDX    R3, R7, R8, 0, 0   # 0x2e02
        ST_LOCAL         R9, 136   # 0x2e06
        C_MOV            R14, R13   # 0x2e0a
        C_MOV            R10, R14   # 0x2e0c
        BRA_PRED         4, L2e62   # 0x2e0e
        LD_LOCAL         R11, 160   # 0x2e12
L2e16:  LD_GLOBAL_IDX    R3, R9, R10, 0, 8   # 0x2e16
        LD_GLOBAL_IDX    R4, R9, R10, 0, 12   # 0x2e1a
        SHLI             R4, R4, 16   # 0x2e1e
        SHRI             R5, R3, 16   # 0x2e22
        C_OR             R4, R5   # 0x2e26
        C_AND            R3, R0   # 0x2e28
        SZ_GLOBAL_LD_U16 R3, R4, R3, 0, 2   # 0x2e2a
        AND              R4, R11, R0, R11   # 0x2e2e
        SETP_EQ_NP       P0, R3, R3, R4   # 0x2e32
        BRA_PRED         0, L2eb4   # 0x2e36
        LD_GLOBAL_IDX    R3, R9, R10, 0, 4   # 0x2e3a
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2e3e
        SHRI             R5, R4, 16   # 0x2e42
        SHLI             R6, R3, 16   # 0x2e46
        OR               R9, R6, R5, R6   # 0x2e4a
        C_AND            R3, R0   # 0x2e4e
        OR               R3, R4, R3, R4   # 0x2e50
        AND              R10, R4, R0, R4   # 0x2e54
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2e58
        BRA_PRED         4, L2e16   # 0x2e5c
        C_BRA            L2eac   # 0x2e60
L2e62:  LD_LOCAL         R11, 168   # 0x2e62
L2e66:  LD_GLOBAL_IDX    R3, R9, R10, 0, 8   # 0x2e66
        LD_GLOBAL_IDX    R4, R9, R10, 0, 12   # 0x2e6a
        SHLI             R4, R4, 16   # 0x2e6e
        SHRI             R5, R3, 16   # 0x2e72
        C_OR             R4, R5   # 0x2e76
        C_AND            R3, R0   # 0x2e78
        SZ_GLOBAL_LD_U8  R3, R4, R3, 0, 0   # 0x2e7a
        SETP_EQ_NP       P0, R3, R3, R11   # 0x2e7e
        BRA_PRED         0, L2eb4   # 0x2e82
        LD_GLOBAL_IDX    R3, R9, R10, 0, 4   # 0x2e86
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2e8a
        SHRI             R5, R4, 16   # 0x2e8e
        SHLI             R6, R3, 16   # 0x2e92
        OR               R9, R6, R5, R6   # 0x2e96
        C_AND            R3, R0   # 0x2e9a
        OR               R3, R4, R3, R4   # 0x2e9c
        AND              R10, R4, R0, R4   # 0x2ea0
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2ea4
        BRA_PRED         0, L2e66   # 0x2ea8
L2eac:  MOVI             R9, 0   # 0x2eac
        MOVI             R10, 0   # 0x2eb0
L2eb4:  SHLI             R2, R2, 16   # 0x2eb4
        SHRI             R3, R1, 16   # 0x2eb8
        SHLI             R4, R9, 16   # 0x2ebc
        AND              R5, R4, R10, R4   # 0x2ec0
        ADD              R6, R4, R10, R4   # 0x2ec4
        C_OR             R4, R10   # 0x2ec8
        C_ANDN           R4, R6   # 0x2eca
        OR               R4, R5, R4, R5   # 0x2ecc
        SHRI             R4, R4, 31   # 0x2ed0
        SHRI             R5, R9, 16   # 0x2ed4
        ADD              R4, R5, R4, R5   # 0x2ed8
        OR               R4, R6, R4, R6   # 0x2edc
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2ee0
        BRA_PRED         0, L2f08   # 0x2ee4
        LD_LOCAL         R5, 136   # 0x2ee8
        LD_GLOBAL_IDX    R4, R5, R14, 0, 0   # 0x2eec
        LD_GLOBAL_IDX    R5, R5, R14, 0, 4   # 0x2ef0
        SHLI             R5, R5, 16   # 0x2ef4
        SHRI             R6, R4, 16   # 0x2ef8
        OR               R9, R5, R6, R5   # 0x2efc
        MOVI             R5, 65535   # 0x2f00
        AND              R10, R4, R5, R4   # 0x2f04
L2f08:  OR               R11, R2, R3, R2   # 0x2f08
        AND              R0, R1, R0, R1   # 0x2f0c
        ST_LOCAL         R0, 92   # 0x2f10
        SHLI             R0, R9, 16   # 0x2f14
        AND              R1, R0, R10, R0   # 0x2f18
        ADD              R2, R0, R10, R0   # 0x2f1c
        C_OR             R0, R10   # 0x2f20
        C_ANDN           R0, R2   # 0x2f22
        OR               R0, R1, R0, R1   # 0x2f24
        SHRI             R0, R0, 31   # 0x2f28
        SHRI             R1, R9, 16   # 0x2f2c
        ADD              R0, R1, R0, R1   # 0x2f30
        OR               R0, R2, R0, R2   # 0x2f34
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2f38
        BRA_PRED         0, L2fa4   # 0x2f3c
        LD_LOCAL         R1, 136   # 0x2f40
        LD_GLOBAL_IDX    R0, R1, R14, 0, 8   # 0x2f44
        C_MOV            R12, R14   # 0x2f48
        LD_GLOBAL_IDX    R1, R1, R14, 0, 12   # 0x2f4a
        SHLI             R1, R1, 16   # 0x2f4e
        SHRI             R2, R0, 16   # 0x2f52
        C_OR             R1, R2   # 0x2f56
        MOVI             R13, 65535   # 0x2f58
        C_AND            R0, R13   # 0x2f5c
        SZ_GLOBAL_LD_S16 R6, R1, R0, 0, 0   # 0x2f5e
        LD_LOCAL         R1, 156   # 0x2f62
L2f66:  AND              R2, R1, R13, R1   # 0x2f66
        C_MOV            R1, R6   # 0x2f6a
        CALL             R14, 127957   # 0x2f6c
        MOVI             R15, 2   # 0x2f70
        LD_GLOBAL        R15, R15, 24   # 0x2f74
        SRD              R3, 3   # 0x2f78
        C_ADD            R15, R3   # 0x2f7a
        LD_GLOBAL_IDX    R0, R9, R10, 0, 4   # 0x2f7c
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2f80
        SHRI             R2, R4, 16   # 0x2f84
        SHLI             R3, R0, 16   # 0x2f88
        OR               R9, R3, R2, R3   # 0x2f8c
        C_AND            R0, R13   # 0x2f90
        OR               R0, R4, R0, R4   # 0x2f92
        AND              R10, R4, R13, R4   # 0x2f96
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2f9a
        BRA_PRED         0, L2f66   # 0x2f9e
        C_BRA            L2faa   # 0x2fa2
L2fa4:  C_MOV            R12, R14   # 0x2fa4
        LD_LOCAL         R1, 156   # 0x2fa6
L2faa:  ST_LOCAL         R1, 156   # 0x2faa
        LD_LOCAL         R5, 136   # 0x2fae
        C_MOV            R13, R12   # 0x2fb2
        LD_GLOBAL_IDX    R1, R5, R13, 0, 0   # 0x2fb4
        LD_GLOBAL_IDX    R0, R5, R13, 0, 4   # 0x2fb8
        SHLI             R0, R0, 16   # 0x2fbc
        SHRI             R2, R1, 16   # 0x2fc0
        OR               R2, R0, R2, R0   # 0x2fc4
        MOVI             R0, 65535   # 0x2fc8
        C_AND            R1, R0   # 0x2fcc
        LD_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x2fce
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 12   # 0x2fd2
        ST_GLOBAL_IDX    R4, R7, R8, 0, 12   # 0x2fd6
        ST_GLOBAL_IDX    R3, R7, R8, 0, 8   # 0x2fda
        SHRI             R3, R11, 16   # 0x2fde
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x2fe2
        SHLI             R3, R11, 16   # 0x2fe6
        LD_LOCAL         R4, 92   # 0x2fea
        C_OR             R3, R4   # 0x2fee
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x2ff0
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x2ff4
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 4   # 0x2ff8
        ST_GLOBAL_IDX    R4, R7, R8, 0, 4   # 0x2ffc
        ST_GLOBAL_IDX    R3, R7, R8, 0, 0   # 0x3000
        SHRI             R3, R7, 16   # 0x3004
        ST_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x3008
        SHLI             R3, R7, 16   # 0x300c
        C_OR             R3, R8   # 0x3010
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3012
        C_MOV            R1, R5   # 0x3016
        MOVI             R9, 1   # 0x3018
        MOVI             R3, 0   # 0x301c
        C_BRA            L3044   # 0x3020
L3022:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x3022
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x3026
        C_SHLI           R9, 1   # 0x302a
        LD_LOCAL         R1, 100   # 0x302c
        SETP_NE_NPI      P0, R1, R1, 0   # 0x3030
        LD_LOCAL         R4, 92   # 0x3034
        C_MOV            R1, R4   # 0x3038
        LD_LOCAL         R5, 96   # 0x303a
        C_MOV            R13, R5   # 0x303e
        BRA_PRED         4, L3284   # 0x3040
L3044:  MOVI             R6, 0   # 0x3044
        MOVI             R2, 0   # 0x3048
        MOVI             R4, 0   # 0x304c
        MOVI             R5, 0   # 0x3050
        ST_LOCAL         R5, 92   # 0x3054
        ST_LOCAL         R5, 96   # 0x3058
        ST_LOCAL         R9, 108   # 0x305c
        C_BRA            L3072   # 0x3060
L3062:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x3062
        LD_LOCAL         R9, 108   # 0x3066
        LD_LOCAL         R6, 104   # 0x306a
        BRA_PRED         0, L3022   # 0x306e
L3072:  ST_LOCAL         R6, 100   # 0x3072
        SETP_LT_NPI      P0, R5, R9, 1   # 0x3076
        BRA_PRED         0, L30ba   # 0x307a
        MOVI             R5, 0   # 0x307e
        C_MOV            R6, R1   # 0x3082
        C_MOV            R7, R13   # 0x3084
L3086:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x3086
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x308a
        AND              R6, R14, R0, R14   # 0x308e
        OR               R6, R7, R6, R7   # 0x3092
        SETP_NE_NPI      P0, R6, R6, 0   # 0x3096
        BRA_PRED         4, L30c4   # 0x309a
        SHRI             R6, R7, 16   # 0x309e
        SHLI             R14, R14, 16   # 0x30a2
        OR               R6, R14, R6, R14   # 0x30a6
        C_AND            R7, R0   # 0x30aa
        C_ADDI           R5, 1   # 0x30ac
        SETP_EQ_NP       P0, R14, R9, R5   # 0x30ae
        BRA_PRED         4, L3086   # 0x30b2
        C_MOV            R8, R9   # 0x30b6
        C_BRA            L30d0   # 0x30b8
L30ba:  MOVI             R8, 0   # 0x30ba
        C_MOV            R6, R1   # 0x30be
        C_MOV            R7, R13   # 0x30c0
        C_BRA            L30d0   # 0x30c2
L30c4:  MOVI             R6, 0   # 0x30c4
        ADDI             R8, R5, 1   # 0x30c8
        MOVI             R7, 0   # 0x30cc
L30d0:  LD_LOCAL         R5, 100   # 0x30d0
        C_ADDI           R5, 1   # 0x30d4
        ST_LOCAL         R5, 104   # 0x30d6
        C_MOV            R5, R1   # 0x30da
        C_MOV            R14, R13   # 0x30dc
        C_MOV            R1, R6   # 0x30de
        C_MOV            R13, R7   # 0x30e0
        C_BRA            L30f6   # 0x30e2
L30e4:  ST_LOCAL         R6, 92   # 0x30e4
        ST_LOCAL         R7, 96   # 0x30e8
L30ec:  C_MOV            R5, R11   # 0x30ec
        C_MOV            R14, R10   # 0x30ee
        C_MOV            R1, R12   # 0x30f0
        C_MOV            R2, R6   # 0x30f2
        C_MOV            R4, R7   # 0x30f4
L30f6:  SETP_LT_NP       P0, R6, R3, R8   # 0x30f6
        BRA_PRED         0, L3132   # 0x30fa
        SHLI             R6, R1, 16   # 0x30fe
        AND              R7, R6, R13, R6   # 0x3102
        ADD              R10, R6, R13, R6   # 0x3106
        C_OR             R6, R13   # 0x310a
        C_ANDN           R6, R10   # 0x310c
        OR               R6, R7, R6, R7   # 0x310e
        SHRI             R6, R6, 31   # 0x3112
        SHRI             R7, R1, 16   # 0x3116
        ADD              R6, R7, R6, R7   # 0x311a
        OR               R6, R10, R6, R10   # 0x311e
        SETP_LT_NPI      P0, R7, R9, 1   # 0x3122
        BRA_PRED         0, L3062   # 0x3126
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x312a
        BRA_PRED         0, L3062   # 0x312e
L3132:  SETP_NE_NPI      P0, R6, R8, 0   # 0x3132
        BRA_PRED         4, L3206   # 0x3136
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x313a
        BRA_PRED         0, L31e2   # 0x313e
        SHLI             R6, R1, 16   # 0x3142
        AND              R7, R6, R13, R6   # 0x3146
        ADD              R10, R6, R13, R6   # 0x314a
        C_OR             R6, R13   # 0x314e
        C_ANDN           R6, R10   # 0x3150
        OR               R6, R7, R6, R7   # 0x3152
        SHRI             R6, R6, 31   # 0x3156
        SHRI             R7, R1, 16   # 0x315a
        ADD              R6, R7, R6, R7   # 0x315e
        OR               R6, R10, R6, R10   # 0x3162
        SETP_NE_NPI      P0, R6, R6, 0   # 0x3166
        BRA_PRED         4, L31e2   # 0x316a
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x316e
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x3172
        SHLI             R7, R7, 16   # 0x3176
        SHRI             R10, R6, 16   # 0x317a
        C_OR             R7, R10   # 0x317e
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x3180
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x3184
        C_AND            R6, R0   # 0x3188
        SZ_GLOBAL_LD_U8  R12, R7, R6, 0, 1   # 0x318a
        SZ_GLOBAL_ST_8   R12, R7, R6, 0, 0   # 0x318e
        SHLI             R11, R11, 16   # 0x3192
        SHRI             R12, R10, 16   # 0x3196
        C_OR             R11, R12   # 0x319a
        C_AND            R10, R0   # 0x319c
        SZ_GLOBAL_LD_U8  R12, R11, R10, 0, 1   # 0x319e
        SZ_GLOBAL_ST_8   R12, R11, R10, 0, 0   # 0x31a2
        SZ_GLOBAL_LD_U16 R6, R7, R6, 0, 2   # 0x31a6
        SZ_GLOBAL_LD_U16 R7, R11, R10, 0, 2   # 0x31aa
        SHLI             R7, R7, 16   # 0x31ae
        SRAI             R7, R7, 16   # 0x31b2
        SHLI             R6, R6, 16   # 0x31b6
        SRAI             R6, R6, 16   # 0x31ba
        SETP_LT_NP       P0, R6, R7, R6   # 0x31be
        BRA_PRED         4, L31e2   # 0x31c2
        LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x31c6
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x31ca
        SHLI             R7, R7, 16   # 0x31ce
        SHRI             R10, R6, 16   # 0x31d2
        OR               R12, R7, R10, R7   # 0x31d6
        C_MOV            R7, R13   # 0x31da
        AND              R13, R6, R0, R6   # 0x31dc
        C_BRA            L3224   # 0x31e0
L31e2:  LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x31e2
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x31e6
        SHLI             R7, R7, 16   # 0x31ea
        SHRI             R10, R6, 16   # 0x31ee
        OR               R11, R7, R10, R7   # 0x31f2
        AND              R10, R6, R0, R6   # 0x31f6
        ADDI             R8, R8, -1   # 0x31fa
        C_MOV            R12, R1   # 0x31fe
        C_MOV            R6, R5   # 0x3200
        C_MOV            R7, R14   # 0x3202
        C_BRA            L322e   # 0x3204
L3206:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x3206
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x320a
        SHLI             R7, R7, 16   # 0x320e
        SHRI             R8, R6, 16   # 0x3212
        OR               R12, R7, R8, R7   # 0x3216
        C_MOV            R7, R13   # 0x321a
        AND              R13, R6, R0, R6   # 0x321c
        MOVI             R8, 0   # 0x3220
L3224:  ADDI             R9, R9, -1   # 0x3224
        C_MOV            R11, R5   # 0x3228
        C_MOV            R10, R14   # 0x322a
        C_MOV            R6, R1   # 0x322c
L322e:  SHLI             R5, R2, 16   # 0x322e
        AND              R14, R5, R4, R5   # 0x3232
        ADD              R1, R5, R4, R5   # 0x3236
        C_OR             R5, R4   # 0x323a
        C_ANDN           R5, R1   # 0x323c
        OR               R5, R14, R5, R14   # 0x323e
        SHRI             R5, R5, 31   # 0x3242
        SHRI             R14, R2, 16   # 0x3246
        ADD              R5, R14, R5, R14   # 0x324a
        C_OR             R1, R5   # 0x324e
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x3250
        BRA_PRED         0, L30e4   # 0x3254
        SHLI             R1, R6, 16   # 0x3258
        ADD              R5, R1, R7, R1   # 0x325c
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x3260
        OR               R14, R1, R7, R1   # 0x3264
        ANDN             R5, R14, R5, R14   # 0x3268
        C_AND            R1, R7   # 0x326c
        C_OR             R1, R5   # 0x326e
        SHRI             R1, R1, 31   # 0x3270
        SHRI             R5, R6, 16   # 0x3274
        ADD              R1, R5, R1, R5   # 0x3278
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x327c
        BRA              L30ec   # 0x3280
L3284:  LD_GLOBAL_IDX    R1, R4, R5, 0, 4   # 0x3284
        LD_GLOBAL_IDX    R0, R4, R5, 0, 0   # 0x3288
        MOVI             R7, 65535   # 0x328c
        AND              R2, R1, R7, R1   # 0x3290
        OR               R2, R0, R2, R0   # 0x3294
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x3298
        BRA_PRED         0, L330a   # 0x329c
        SHRI             R2, R0, 16   # 0x32a0
        SHLI             R1, R1, 16   # 0x32a4
        OR               R8, R1, R2, R1   # 0x32a8
        AND              R9, R0, R7, R0   # 0x32ac
        LD_GLOBAL_IDX    R0, R4, R5, 0, 8   # 0x32b0
        LD_GLOBAL_IDX    R1, R4, R5, 0, 12   # 0x32b4
        SHLI             R1, R1, 16   # 0x32b8
        SHRI             R2, R0, 16   # 0x32bc
        C_OR             R1, R2   # 0x32c0
        C_AND            R0, R7   # 0x32c2
        SZ_GLOBAL_LD_S16 R6, R1, R0, 0, 0   # 0x32c4
        LD_LOCAL         R1, 156   # 0x32c8
L32cc:  AND              R2, R1, R7, R1   # 0x32cc
        C_MOV            R1, R6   # 0x32d0
        CALL             R14, 127522   # 0x32d2
        MOVI             R15, 2   # 0x32d6
        LD_GLOBAL        R15, R15, 24   # 0x32da
        SRD              R3, 3   # 0x32de
        C_ADD            R15, R3   # 0x32e0
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x32e2
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x32e6
        SHRI             R2, R4, 16   # 0x32ea
        SHLI             R3, R0, 16   # 0x32ee
        OR               R8, R3, R2, R3   # 0x32f2
        C_AND            R0, R7   # 0x32f6
        OR               R0, R4, R0, R4   # 0x32f8
        AND              R9, R4, R7, R4   # 0x32fc
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3300
        BRA_PRED         0, L32cc   # 0x3304
        C_BRA            L330e   # 0x3308
L330a:  LD_LOCAL         R1, 156   # 0x330a
L330e:  LD_LOCAL         R14, 164   # 0x330e
        LD_LOCAL         R13, 192   # 0x3312
        LD_LOCAL         R12, 188   # 0x3316
        LD_LOCAL         R11, 184   # 0x331a
        LD_LOCAL         R10, 180   # 0x331e
        LD_LOCAL         R9, 176   # 0x3322
        LD_LOCAL         R8, 172   # 0x3326
        C_RET            224   # 0x332a
        MOVI             R15, 2   # 0x332c
        LD_GLOBAL        R15, R15, 24   # 0x3330
        SRD              R14, 3   # 0x3334
        C_ADD            R15, R14   # 0x3336
        MOVI             R0, 2   # 0x3338
        LD_GLOBAL        R1, R0, 44   # 0x333c
        ST_LOCAL         R1, 204   # 0x3340
        LD_GLOBAL        R1, R0, 40   # 0x3344
        ST_LOCAL         R1, 200   # 0x3348
        LD_GLOBAL        R1, R0, 48   # 0x334c
        LD_GLOBAL        R9, R0, 32   # 0x3350
        LD_GLOBAL        R0, R0, 36   # 0x3354
        MOVI             R2, 36   # 0x3358
        C_ADDI           R2, 4   # 0x335c
        MOVI             R8, 36   # 0x335e
        MOVI             R3, 102   # 0x3362
        SZ_GLOBAL_ST_16  R3, R15, R2, 0, 0   # 0x3366
        MOVI             R2, 2000   # 0x336a
        SRD              R11, 0   # 0x336e
        MADLO            R3, R11, R2, R0   # 0x3370
        ADDI             R2, R3, 1332   # 0x3374
        SHLI             R0, R9, 16   # 0x3378
        ADD              R4, R0, R2, R0   # 0x337c
        OR               R5, R0, R2, R0   # 0x3380
        C_ANDN           R5, R4   # 0x3384
        AND              R2, R0, R2, R0   # 0x3386
        OR               R10, R2, R5, R2   # 0x338a
        ADD              R5, R0, R3, R0   # 0x338e
        OR               R6, R0, R3, R0   # 0x3392
        C_ANDN           R6, R5   # 0x3396
        AND              R7, R0, R3, R0   # 0x3398
        OR               R6, R7, R6, R7   # 0x339c
        ADDI             R7, R8, 2   # 0x33a0
        MOVI             R12, 36   # 0x33a4
        MOVI             R8, 0   # 0x33a8
        SZ_GLOBAL_ST_16  R8, R15, R7, 0, 0   # 0x33ac
        MOVI             R7, 7   # 0x33b0
        ST_GLOBAL        R7, R15, 84   # 0x33b4
        ST_GLOBAL        R1, R15, 80   # 0x33b8
        ST_GLOBAL        R5, R15, 52   # 0x33bc
        ST_GLOBAL        R5, R15, 44   # 0x33c0
        ST_GLOBAL        R4, R15, 68   # 0x33c4
        ADDI             R2, R3, 666   # 0x33c8
        ADD              R1, R0, R2, R0   # 0x33cc
        OR               R4, R0, R2, R0   # 0x33d0
        C_MOV            R7, R2   # 0x33d4
        ST_LOCAL         R7, 208   # 0x33d6
        C_ANDN           R4, R1   # 0x33da
        ST_GLOBAL        R1, R15, 60   # 0x33dc
        SHRI             R1, R6, 31   # 0x33e0
        C_MOV            R2, R9   # 0x33e4
        ST_LOCAL         R2, 212   # 0x33e6
        SHRI             R5, R2, 16   # 0x33ea
        ADD              R1, R5, R1, R5   # 0x33ee
        ST_GLOBAL        R1, R15, 56   # 0x33f2
        ST_GLOBAL        R1, R15, 48   # 0x33f6
        SHRI             R1, R10, 31   # 0x33fa
        ADD              R1, R5, R1, R5   # 0x33fe
        ST_GLOBAL        R1, R15, 72   # 0x3402
        C_AND            R0, R7   # 0x3406
        C_OR             R0, R4   # 0x3408
        SHRI             R0, R0, 31   # 0x340a
        ADD              R0, R5, R0, R5   # 0x340e
        ST_GLOBAL        R0, R15, 64   # 0x3412
        C_MOV            R4, R11   # 0x3416
        ST_LOCAL         R4, 196   # 0x3418
        SZ_GLOBAL_ST_16  R4, R15, R12, 0, 0   # 0x341c
        MOVI             R0, 666   # 0x3420
        ST_GLOBAL        R0, R15, 76   # 0x3424
        MOVI             R1, 666   # 0x3428
        CALL             R14, 124392   # 0x342c
        MOVI             R15, 2   # 0x3430
        LD_GLOBAL        R15, R15, 24   # 0x3434
        SRD              R3, 3   # 0x3438
        C_ADD            R15, R3   # 0x343a
        SHLI             R0, R1, 16   # 0x343c
        ADD              R3, R0, R2, R0   # 0x3440
        OR               R4, R0, R2, R0   # 0x3444
        C_ANDN           R4, R3   # 0x3448
        ST_GLOBAL        R3, R15, 92   # 0x344a
        C_AND            R0, R2   # 0x344e
        C_OR             R0, R4   # 0x3450
        SHRI             R0, R0, 31   # 0x3452
        SHRI             R1, R1, 16   # 0x3456
        ADD              R0, R1, R0, R1   # 0x345a
        ST_GLOBAL        R0, R15, 96   # 0x345e
        LD_LOCAL         R0, 196   # 0x3462
        SHLI             R0, R0, 16   # 0x3466
        SRAI             R4, R0, 16   # 0x346a
        MOVI             R0, 36   # 0x346e
        ADDI             R6, R0, 64   # 0x3472
        MOVI             R1, 666   # 0x3476
        LD_LOCAL         R2, 212   # 0x347a
        LD_LOCAL         R3, 208   # 0x347e
        C_MOV            R5, R15   # 0x3482
        CALL             R14, 125390   # 0x3484
        MOVI             R15, 2   # 0x3488
        LD_GLOBAL        R15, R15, 24   # 0x348c
        SRD              R3, 3   # 0x3490
        C_ADD            R15, R3   # 0x3492
        MOVI             R0, 36   # 0x3494
        SZ_GLOBAL_LD_U16 R2, R15, R0, 0, 0   # 0x3498
        MOVI             R1, 65535   # 0x349c
        LD_GLOBAL        R0, R15, 68   # 0x34a0
        AND              R4, R0, R1, R0   # 0x34a4
        SHRI             R0, R0, 16   # 0x34a8
        LD_GLOBAL        R1, R15, 72   # 0x34ac
        SHLI             R1, R1, 16   # 0x34b0
        OR               R3, R1, R0, R1   # 0x34b4
        LD_GLOBAL        R1, R15, 76   # 0x34b8
        CALL             R14, 125700   # 0x34bc
        MOVI             R15, 2   # 0x34c0
        LD_GLOBAL        R15, R15, 24   # 0x34c4
        SRD              R3, 3   # 0x34c8
        C_ADD            R15, R3   # 0x34ca
        MOVI             R5, 0   # 0x34cc
        ST_GLOBAL        R5, R15, 136   # 0x34d0
        ST_GLOBAL        R5, R15, 132   # 0x34d4
        LD_GLOBAL        R0, R15, 80   # 0x34d8
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x34dc
        MOVI             R2, 0   # 0x34e0
        MOVI             R0, 0   # 0x34e4
        MOVI             R1, 0   # 0x34e8
        BRA_PRED         0, L3622   # 0x34ec
        MOVI             R8, 1   # 0x34f0
        C_MOV            R1, R15   # 0x34f4
        MOVI             R2, 36   # 0x34f6
        MOVI             R3, 1   # 0x34fa
        CALL             R14, 129010   # 0x34fe
        MOVI             R15, 2   # 0x3502
        LD_GLOBAL        R15, R15, 24   # 0x3506
        SRD              R3, 3   # 0x350a
        C_ADD            R15, R3   # 0x350c
        MOVI             R11, 65535   # 0x350e
        C_AND            R1, R11   # 0x3512
        MOVI             R10, 36   # 0x3514
        ADDI             R9, R10, 96   # 0x3518
        SZ_GLOBAL_LD_U16 R2, R15, R9, 0, 0   # 0x351c
        CALL             R14, 128792   # 0x3520
        MOVI             R15, 2   # 0x3524
        LD_GLOBAL        R15, R15, 24   # 0x3528
        SRD              R3, 3   # 0x352c
        C_ADD            R15, R3   # 0x352e
        SZ_GLOBAL_ST_16  R1, R15, R9, 0, 0   # 0x3530
        C_MOV            R1, R15   # 0x3534
        MOVI             R2, 36   # 0x3536
        MOVI             R3, 65535   # 0x353a
        CALL             R14, 128978   # 0x353e
        MOVI             R15, 2   # 0x3542
        LD_GLOBAL        R15, R15, 24   # 0x3546
        SRD              R3, 3   # 0x354a
        C_ADD            R15, R3   # 0x354c
        C_AND            R1, R11   # 0x354e
        SZ_GLOBAL_LD_U16 R2, R15, R9, 0, 0   # 0x3550
        CALL             R14, 128766   # 0x3554
        MOVI             R15, 2   # 0x3558
        LD_GLOBAL        R15, R15, 24   # 0x355c
        SRD              R3, 3   # 0x3560
        C_ADD            R15, R3   # 0x3562
        C_MOV            R0, R1   # 0x3564
        ADDI             R1, R10, 98   # 0x3566
        SZ_GLOBAL_ST_16  R0, R15, R1, 0, 0   # 0x356a
        SZ_GLOBAL_ST_16  R0, R15, R9, 0, 0   # 0x356e
        LD_GLOBAL        R1, R15, 80   # 0x3572
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x3576
        C_MOV            R1, R0   # 0x357a
        BRA_PRED         0, L360e   # 0x357c
        MOVI             R0, 36   # 0x3580
        MOVI             R9, 65535   # 0x3584
        ADDI             R10, R0, 96   # 0x3588
L358c:  C_MOV            R1, R15   # 0x358c
        MOVI             R2, 36   # 0x358e
        MOVI             R3, 1   # 0x3592
        CALL             R14, 128934   # 0x3596
        MOVI             R15, 2   # 0x359a
        LD_GLOBAL        R15, R15, 24   # 0x359e
        SRD              R3, 3   # 0x35a2
        C_ADD            R15, R3   # 0x35a4
        C_AND            R1, R9   # 0x35a6
        SZ_GLOBAL_LD_U16 R2, R15, R10, 0, 0   # 0x35a8
        CALL             R14, 128722   # 0x35ac
        MOVI             R15, 2   # 0x35b0
        LD_GLOBAL        R15, R15, 24   # 0x35b4
        SRD              R3, 3   # 0x35b8
        C_ADD            R15, R3   # 0x35ba
        SZ_GLOBAL_ST_16  R1, R15, R10, 0, 0   # 0x35bc
        C_MOV            R1, R15   # 0x35c0
        MOVI             R2, 36   # 0x35c2
        MOVI             R3, 65535   # 0x35c6
        CALL             R14, 128908   # 0x35ca
        MOVI             R15, 2   # 0x35ce
        LD_GLOBAL        R15, R15, 24   # 0x35d2
        SRD              R3, 3   # 0x35d6
        C_ADD            R15, R3   # 0x35d8
        C_AND            R1, R9   # 0x35da
        SZ_GLOBAL_LD_U16 R2, R15, R10, 0, 0   # 0x35dc
        CALL             R14, 128696   # 0x35e0
        MOVI             R15, 2   # 0x35e4
        LD_GLOBAL        R15, R15, 24   # 0x35e8
        SRD              R3, 3   # 0x35ec
        C_ADD            R15, R3   # 0x35ee
        SZ_GLOBAL_ST_16  R1, R15, R10, 0, 0   # 0x35f0
        C_ADDI           R8, 1   # 0x35f4
        LD_GLOBAL        R0, R15, 80   # 0x35f6
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x35fa
        BRA_PRED         0, L358c   # 0x35fe
        MOVI             R0, 36   # 0x3602
        ADDI             R0, R0, 98   # 0x3606
        SZ_GLOBAL_LD_U16 R0, R15, R0, 0, 0   # 0x360a
L360e:  MOVI             R2, 36   # 0x360e
        ADDI             R3, R2, 102   # 0x3612
        SZ_GLOBAL_LD_U16 R5, R15, R3, 0, 0   # 0x3616
        ADDI             R2, R2, 100   # 0x361a
        SZ_GLOBAL_LD_U16 R2, R15, R2, 0, 0   # 0x361e
L3622:  LD_LOCAL         R4, 196   # 0x3622
        C_SHLI           R4, 3   # 0x3626
        LD_LOCAL         R3, 204   # 0x3628
        C_ADD            R3, R4   # 0x362c
        LD_LOCAL         R4, 200   # 0x362e
        SZ_GLOBAL_ST_16  R1, R4, R3, 0, 0   # 0x3632
        ADDI             R1, R3, 2   # 0x3636
        SZ_GLOBAL_ST_16  R0, R4, R1, 0, 0   # 0x363a
        ADDI             R0, R3, 4   # 0x363e
        SZ_GLOBAL_ST_16  R2, R4, R0, 0, 0   # 0x3642
        ADDI             R0, R3, 6   # 0x3646
        SZ_GLOBAL_ST_16  R5, R4, R0, 0, 0   # 0x364a
        C_EXIT           0   # 0x364e
