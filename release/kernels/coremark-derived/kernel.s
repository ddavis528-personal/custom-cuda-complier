# coremark-derived: test/coremark-derived, compiled; ccv-as source, reassembled
# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base
# (0x1000: function pointers are absolute); the kernel's entry is 0x3330.
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
        SRD              R0, 2   # 0x0fb8
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
        ST_GLOBAL        R7, R15, -8   # 0x0fe4
        ST_GLOBAL        R7, R15, -12   # 0x0fe8
        ST_GLOBAL        R7, R15, -16   # 0x0fec
        ST_GLOBAL        R7, R15, -20   # 0x0ff0
        ST_GLOBAL        R7, R15, -24   # 0x0ff4
        ST_GLOBAL        R7, R15, -28   # 0x0ff8
        ST_GLOBAL        R7, R15, -32   # 0x0ffc
        ST_GLOBAL        R7, R15, -36   # 0x1000
        SZ_GLOBAL_LD_U8  R11, R2, R3, 0, 0   # 0x1004
        LD_GLOBAL        R0, R15, -4   # 0x1008
        ST_LOCAL         R0, 48   # 0x100c
        SETP_EQ_NPI      P0, R0, R11, 0   # 0x1010
        MOVI             R0, 0   # 0x1014
        ST_LOCAL         R0, 20   # 0x1018
        ST_LOCAL         R0, 24   # 0x101c
        ST_LOCAL         R0, 16   # 0x1020
        ST_LOCAL         R0, 12   # 0x1024
        ST_LOCAL         R0, 32   # 0x1028
        ST_LOCAL         R0, 28   # 0x102c
        BRA_PRED         0, L1262   # 0x1030
        MOVI             R0, 3   # 0x1034
        MOVI             R1, 0   # 0x1038
        ST_LOCAL         R1, 20   # 0x103c
        ST_LOCAL         R1, 24   # 0x1040
        ST_LOCAL         R1, 16   # 0x1044
        ST_LOCAL         R1, 12   # 0x1048
        ST_LOCAL         R1, 32   # 0x104c
        ST_LOCAL         R1, 28   # 0x1050
        MOVI             R13, 0   # 0x1054
        MOVI             R8, 0   # 0x1058
        C_MOV            R14, R11   # 0x105c
        MOVI             R9, 0   # 0x105e
        C_MOV            R6, R3   # 0x1062
        C_BRA            L1084   # 0x1064
L1066:  LD_GLOBAL_IDX    R6, R15, R9, 1, -36   # 0x1066
        C_ADDI           R6, 1   # 0x106a
        ST_GLOBAL_IDX    R6, R15, R9, 1, -36   # 0x106c
        SZ_GLOBAL_LD_U8  R14, R2, R1, 0, 0   # 0x1070
        MOVI             R9, 0   # 0x1074
        SETP_EQ_NPI      P0, R6, R14, 0   # 0x1078
        C_MOV            R8, R13   # 0x107c
        BRA_PRED         0, L1262   # 0x107e
L1082:  C_MOV            R6, R1   # 0x1082
L1084:  ANDI             R12, R14, 255   # 0x1084
        SETP_NE_NPI      P0, R1, R12, 44   # 0x1088
        ADDI             R1, R6, 1   # 0x108c
        BRA_PRED         4, L1066   # 0x1090
        SETP_LT_NP       P0, R10, R0, R9   # 0x1094
        BRA_PRED         4, L10cc   # 0x1098
        MOVI             R10, 5   # 0x109c
        SETP_LT_NP       P0, R10, R10, R9   # 0x10a0
        BRA_PRED         0, L10fc   # 0x10a4
        SETP_EQ_NPI      P0, R10, R9, 4   # 0x10a8
        BRA_PRED         0, L1170   # 0x10ac
        SETP_EQ_NPI      P0, R10, R9, 5   # 0x10b0
        BRA_PRED         4, L124a   # 0x10b4
        ANDI             R9, R14, 223   # 0x10b8
        SETP_NE_NPI      P0, R9, R9, 69   # 0x10bc
        BRA_PRED         0, L11ec   # 0x10c0
        MOVI             R9, 3   # 0x10c4
        BRA              L1208   # 0x10c8
L10cc:  SETP_EQ_NPI      P0, R10, R9, 0   # 0x10cc
        BRA_PRED         0, L1136   # 0x10d0
        SETP_EQ_NPI      P0, R10, R9, 2   # 0x10d4
        BRA_PRED         0, L119e   # 0x10d8
        SETP_EQ_NPI      P0, R14, R9, 3   # 0x10dc
        BRA_PRED         4, L124a   # 0x10e0
        SETP_EQ_NPI      P0, R14, R12, 45   # 0x10e4
        BRA_PRED         0, L10f4   # 0x10e8
        SETP_NE_NPI      P0, R14, R12, 43   # 0x10ec
        BRA_PRED         0, L1224   # 0x10f0
L10f4:  MOVI             R9, 6   # 0x10f4
        BRA              L1228   # 0x10f8
L10fc:  SETP_EQ_NPI      P0, R10, R9, 6   # 0x10fc
        BRA_PRED         0, L117e   # 0x1100
        SETP_EQ_NPI      P0, R10, R9, 7   # 0x1104
        BRA_PRED         4, L124a   # 0x1108
        ADDI             R14, R14, -58   # 0x110c
        ANDI             R14, R14, 255   # 0x1110
        MOVI             R9, 245   # 0x1114
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x1118
        MOVI             R9, 7   # 0x111c
        BRA_PRED         0, L124a   # 0x1120
        MOVI             R9, 1   # 0x1124
        LD_LOCAL         R14, 32   # 0x1128
        C_ADDI           R14, 1   # 0x112c
        ST_LOCAL         R14, 32   # 0x112e
        BRA              L124a   # 0x1132
L1136:  ADDI             R14, R14, -58   # 0x1136
        ANDI             R14, R14, 255   # 0x113a
        MOVI             R9, 245   # 0x113e
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x1142
        MOVI             R9, 4   # 0x1146
        BRA_PRED         0, L1242   # 0x114a
        MOVI             R9, 2   # 0x114e
        SETP_EQ_NPI      P0, R14, R12, 43   # 0x1152
        BRA_PRED         0, L1242   # 0x1156
        SETP_EQ_NPI      P0, R14, R12, 45   # 0x115a
        BRA_PRED         0, L1242   # 0x115e
        SETP_NE_NPI      P0, R14, R12, 46   # 0x1162
        BRA_PRED         0, L1234   # 0x1166
        MOVI             R9, 5   # 0x116a
        C_BRA            L1242   # 0x116e
L1170:  SETP_NE_NPI      P0, R9, R12, 46   # 0x1170
        BRA_PRED         0, L11c4   # 0x1174
        MOVI             R9, 5   # 0x1178
        C_BRA            L11e0   # 0x117c
L117e:  ADDI             R14, R14, -58   # 0x117e
        ANDI             R14, R14, 255   # 0x1182
        MOVI             R9, 246   # 0x1186
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x118a
        MOVI             R9, 7   # 0x118e
        MOVI             R14, 1   # 0x1192
        MOV_P            R9, 0, R14, R14, R14   # 0x1196
        C_ADDI           R7, 1   # 0x119a
        C_BRA            L124a   # 0x119c
L119e:  ADDI             R14, R14, -58   # 0x119e
        ANDI             R14, R14, 255   # 0x11a2
        MOVI             R9, 246   # 0x11a6
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x11aa
        BRA_PRED         4, L1214   # 0x11ae
        SETP_EQ_NPI      P0, R14, R12, 46   # 0x11b2
        MOVI             R9, 1   # 0x11b6
        MOVI             R14, 5   # 0x11ba
        MOV_P            R9, 0, R14, R14, R14   # 0x11be
        C_BRA            L1218   # 0x11c2
L11c4:  ADDI             R14, R14, -58   # 0x11c4
        ANDI             R14, R14, 255   # 0x11c8
        MOVI             R9, 245   # 0x11cc
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x11d0
        MOVI             R9, 4   # 0x11d4
        BRA_PRED         0, L124a   # 0x11d8
        MOVI             R9, 1   # 0x11dc
L11e0:  LD_LOCAL         R14, 24   # 0x11e0
        C_ADDI           R14, 1   # 0x11e4
        ST_LOCAL         R14, 24   # 0x11e6
        C_BRA            L124a   # 0x11ea
L11ec:  ADDI             R14, R14, -58   # 0x11ec
        ANDI             R14, R14, 255   # 0x11f0
        MOVI             R9, 245   # 0x11f4
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x11f8
        MOVI             R9, 5   # 0x11fc
        BRA_PRED         0, L124a   # 0x1200
        MOVI             R9, 1   # 0x1204
L1208:  LD_LOCAL         R14, 20   # 0x1208
        C_ADDI           R14, 1   # 0x120c
        ST_LOCAL         R14, 20   # 0x120e
        C_BRA            L124a   # 0x1212
L1214:  MOVI             R9, 4   # 0x1214
L1218:  LD_LOCAL         R14, 12   # 0x1218
        C_ADDI           R14, 1   # 0x121c
        ST_LOCAL         R14, 12   # 0x121e
        C_BRA            L124a   # 0x1222
L1224:  MOVI             R9, 1   # 0x1224
L1228:  LD_LOCAL         R14, 16   # 0x1228
        C_ADDI           R14, 1   # 0x122c
        ST_LOCAL         R14, 16   # 0x122e
        C_BRA            L124a   # 0x1232
L1234:  MOVI             R9, 1   # 0x1234
        LD_LOCAL         R14, 32   # 0x1238
        C_ADDI           R14, 1   # 0x123c
        ST_LOCAL         R14, 32   # 0x123e
L1242:  C_ADDI           R8, 1   # 0x1242
        C_MOV            R13, R8   # 0x1244
        ST_LOCAL         R8, 28   # 0x1246
L124a:  SZ_GLOBAL_LD_U8  R14, R2, R6, 0, 1   # 0x124a
        SETP_EQ_NPI      P0, R6, R14, 0   # 0x124e
        BRA_PRED         0, L1066   # 0x1252
        SETP_EQ_NPI      P0, R6, R9, 1   # 0x1256
        BRA_PRED         4, L1082   # 0x125a
        BRA              L1066   # 0x125e
L1262:  LD_LOCAL         R1, 36   # 0x1262
        SETP_EQ_NPI      P0, R0, R1, 0   # 0x1266
        SHLI             R0, R2, 16   # 0x126a
        LD_LOCAL         R6, 40   # 0x126e
        SHLI             R6, R6, 16   # 0x1272
        ST_LOCAL         R6, 40   # 0x1276
        ADD              R6, R3, R1, R3   # 0x127a
        SHRI             R12, R2, 16   # 0x127e
        BRA_PRED         0, L1306   # 0x1282
        ADD              R8, R3, R0, R3   # 0x1286
        LD_LOCAL         R1, 40   # 0x128a
        SRAI             R1, R1, 16   # 0x128e
        ADD              R14, R1, R0, R1   # 0x1292
        C_ADD            R8, R1   # 0x1296
        C_NOT            R8, R8   # 0x1298
        C_MOV            R11, R3   # 0x129a
L129c:  SZ_GLOBAL_LD_U8  R9, R2, R11, 0, 0   # 0x129c
        SETP_EQ_NPI      P0, R10, R9, 44   # 0x12a0
        BRA_PRED         0, L12ae   # 0x12a4
        C_XOR            R9, R4   # 0x12a8
        SZ_GLOBAL_ST_8   R9, R2, R11, 0, 0   # 0x12aa
L12ae:  ADD              R9, R1, R11, R1   # 0x12ae
        OR               R10, R0, R9, R0   # 0x12b2
        C_AND            R10, R8   # 0x12b6
        AND              R13, R0, R9, R0   # 0x12b8
        OR               R10, R13, R10, R13   # 0x12bc
        ADD              R11, R14, R11, R14   # 0x12c0
        ADD              R13, R0, R6, R0   # 0x12c4
        SETP_LT_U_NP     P0, R11, R11, R13   # 0x12c8
        OR               R11, R0, R6, R0   # 0x12cc
        C_ANDN           R11, R13   # 0x12d0
        AND              R13, R0, R6, R0   # 0x12d2
        OR               R11, R13, R11, R13   # 0x12d6
        SHRI             R11, R11, 31   # 0x12da
        SHRI             R10, R10, 31   # 0x12de
        SETP_EQ_NP       P1, R13, R10, R11   # 0x12e2
        ADD              R11, R12, R11, R12   # 0x12e6
        ADD              R10, R12, R10, R12   # 0x12ea
        SETP_LT_U_NP     P2, R10, R10, R11   # 0x12ee
        C_SUB            R8, R1   # 0x12f2
        C_MOV            R11, R9   # 0x12f4
        BRA_PRED         2, L129c   # 0x12f6
        PAND             P0, 1, 0   # 0x12fa
        C_MOV            R11, R9   # 0x12fc
        BRA_PRED         0, L129c   # 0x12fe
        SZ_GLOBAL_LD_U8  R11, R2, R3, 0, 0   # 0x1302
L1306:  SETP_EQ_NPI      P0, R1, R11, 0   # 0x1306
        BRA_PRED         0, L1512   # 0x130a
        MOVI             R9, 0   # 0x130e
        MOVI             R4, 3   # 0x1312
        MOVI             R1, 5   # 0x1316
        C_MOV            R13, R3   # 0x131a
        C_BRA            L133a   # 0x131c
L131e:  LD_GLOBAL_IDX    R14, R15, R9, 1, -36   # 0x131e
        C_ADDI           R14, 1   # 0x1322
        ST_GLOBAL_IDX    R14, R15, R9, 1, -36   # 0x1324
        SZ_GLOBAL_LD_U8  R11, R2, R8, 0, 0   # 0x1328
        MOVI             R9, 0   # 0x132c
        SETP_EQ_NPI      P0, R14, R11, 0   # 0x1330
        BRA_PRED         0, L1512   # 0x1334
L1338:  C_MOV            R13, R8   # 0x1338
L133a:  ANDI             R14, R11, 255   # 0x133a
        SETP_NE_NPI      P0, R8, R14, 44   # 0x133e
        ADDI             R8, R13, 1   # 0x1342
        BRA_PRED         4, L131e   # 0x1346
        SETP_LT_NP       P0, R10, R4, R9   # 0x134a
        BRA_PRED         4, L137e   # 0x134e
        SETP_LT_NP       P0, R10, R1, R9   # 0x1352
        BRA_PRED         0, L13ae   # 0x1356
        SETP_EQ_NPI      P0, R10, R9, 4   # 0x135a
        BRA_PRED         0, L1422   # 0x135e
        SETP_EQ_NPI      P0, R14, R9, 5   # 0x1362
        BRA_PRED         4, L14fa   # 0x1366
        ANDI             R14, R11, 223   # 0x136a
        SETP_NE_NPI      P0, R14, R14, 69   # 0x136e
        BRA_PRED         0, L149a   # 0x1372
        MOVI             R9, 3   # 0x1376
        BRA              L14b6   # 0x137a
L137e:  SETP_EQ_NPI      P0, R10, R9, 0   # 0x137e
        BRA_PRED         0, L13e8   # 0x1382
        SETP_EQ_NPI      P0, R10, R9, 2   # 0x1386
        BRA_PRED         0, L1450   # 0x138a
        SETP_EQ_NPI      P0, R10, R9, 3   # 0x138e
        BRA_PRED         4, L14fa   # 0x1392
        SETP_EQ_NPI      P0, R9, R14, 45   # 0x1396
        BRA_PRED         0, L13a6   # 0x139a
        SETP_NE_NPI      P0, R14, R14, 43   # 0x139e
        BRA_PRED         0, L14d2   # 0x13a2
L13a6:  MOVI             R9, 6   # 0x13a6
        BRA              L14d6   # 0x13aa
L13ae:  SETP_EQ_NPI      P0, R14, R9, 6   # 0x13ae
        BRA_PRED         0, L1430   # 0x13b2
        SETP_EQ_NPI      P0, R14, R9, 7   # 0x13b6
        BRA_PRED         4, L14fa   # 0x13ba
        ADDI             R14, R11, -58   # 0x13be
        ANDI             R14, R14, 255   # 0x13c2
        MOVI             R9, 245   # 0x13c6
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x13ca
        MOVI             R9, 7   # 0x13ce
        BRA_PRED         0, L14fa   # 0x13d2
        MOVI             R9, 1   # 0x13d6
        LD_LOCAL         R14, 32   # 0x13da
        C_ADDI           R14, 1   # 0x13de
        ST_LOCAL         R14, 32   # 0x13e0
        BRA              L14fa   # 0x13e4
L13e8:  ADDI             R9, R11, -58   # 0x13e8
        ANDI             R9, R9, 255   # 0x13ec
        MOVI             R10, 245   # 0x13f0
        SETP_LT_U_NP     P0, R9, R10, R9   # 0x13f4
        MOVI             R9, 4   # 0x13f8
        BRA_PRED         0, L14f0   # 0x13fc
        MOVI             R9, 2   # 0x1400
        SETP_EQ_NPI      P0, R10, R14, 43   # 0x1404
        BRA_PRED         0, L14f0   # 0x1408
        SETP_EQ_NPI      P0, R10, R14, 45   # 0x140c
        BRA_PRED         0, L14f0   # 0x1410
        SETP_NE_NPI      P0, R14, R14, 46   # 0x1414
        BRA_PRED         0, L14e2   # 0x1418
        MOVI             R9, 5   # 0x141c
        C_BRA            L14f0   # 0x1420
L1422:  SETP_NE_NPI      P0, R14, R14, 46   # 0x1422
        BRA_PRED         0, L1472   # 0x1426
        MOVI             R9, 5   # 0x142a
        C_BRA            L148e   # 0x142e
L1430:  ADDI             R14, R11, -58   # 0x1430
        ANDI             R14, R14, 255   # 0x1434
        MOVI             R9, 246   # 0x1438
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x143c
        MOVI             R9, 7   # 0x1440
        MOVI             R14, 1   # 0x1444
        MOV_P            R9, 0, R14, R14, R14   # 0x1448
        C_ADDI           R7, 1   # 0x144c
        C_BRA            L14fa   # 0x144e
L1450:  ADDI             R9, R11, -58   # 0x1450
        ANDI             R9, R9, 255   # 0x1454
        MOVI             R10, 246   # 0x1458
        SETP_LT_U_NP     P0, R9, R9, R10   # 0x145c
        BRA_PRED         4, L14c2   # 0x1460
        SETP_EQ_NPI      P0, R14, R14, 46   # 0x1464
        MOVI             R9, 1   # 0x1468
        MOV_P            R9, 0, R1, R1, R1   # 0x146c
        C_BRA            L14c6   # 0x1470
L1472:  ADDI             R14, R11, -58   # 0x1472
        ANDI             R14, R14, 255   # 0x1476
        MOVI             R9, 245   # 0x147a
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x147e
        MOVI             R9, 4   # 0x1482
        BRA_PRED         0, L14fa   # 0x1486
        MOVI             R9, 1   # 0x148a
L148e:  LD_LOCAL         R14, 24   # 0x148e
        C_ADDI           R14, 1   # 0x1492
        ST_LOCAL         R14, 24   # 0x1494
        C_BRA            L14fa   # 0x1498
L149a:  ADDI             R14, R11, -58   # 0x149a
        ANDI             R14, R14, 255   # 0x149e
        MOVI             R9, 245   # 0x14a2
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x14a6
        MOVI             R9, 5   # 0x14aa
        BRA_PRED         0, L14fa   # 0x14ae
        MOVI             R9, 1   # 0x14b2
L14b6:  LD_LOCAL         R14, 20   # 0x14b6
        C_ADDI           R14, 1   # 0x14ba
        ST_LOCAL         R14, 20   # 0x14bc
        C_BRA            L14fa   # 0x14c0
L14c2:  MOVI             R9, 4   # 0x14c2
L14c6:  LD_LOCAL         R14, 12   # 0x14c6
        C_ADDI           R14, 1   # 0x14ca
        ST_LOCAL         R14, 12   # 0x14cc
        C_BRA            L14fa   # 0x14d0
L14d2:  MOVI             R9, 1   # 0x14d2
L14d6:  LD_LOCAL         R14, 16   # 0x14d6
        C_ADDI           R14, 1   # 0x14da
        ST_LOCAL         R14, 16   # 0x14dc
        C_BRA            L14fa   # 0x14e0
L14e2:  MOVI             R9, 1   # 0x14e2
        LD_LOCAL         R14, 32   # 0x14e6
        C_ADDI           R14, 1   # 0x14ea
        ST_LOCAL         R14, 32   # 0x14ec
L14f0:  LD_LOCAL         R14, 28   # 0x14f0
        C_ADDI           R14, 1   # 0x14f4
        ST_LOCAL         R14, 28   # 0x14f6
L14fa:  SZ_GLOBAL_LD_U8  R11, R2, R13, 0, 1   # 0x14fa
        SETP_EQ_NPI      P0, R14, R11, 0   # 0x14fe
        BRA_PRED         0, L131e   # 0x1502
        SETP_EQ_NPI      P0, R14, R9, 1   # 0x1506
        BRA_PRED         4, L1338   # 0x150a
        BRA              L131e   # 0x150e
L1512:  LD_LOCAL         R1, 36   # 0x1512
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x1516
        BRA_PRED         0, L1598   # 0x151a
        ADD              R14, R3, R0, R3   # 0x151e
        LD_LOCAL         R1, 40   # 0x1522
        SRAI             R1, R1, 16   # 0x1526
        ADD              R4, R1, R0, R1   # 0x152a
        C_ADD            R14, R1   # 0x152e
        C_NOT            R14, R14   # 0x1530
L1532:  SZ_GLOBAL_LD_U8  R8, R2, R3, 0, 0   # 0x1532
        SETP_EQ_NPI      P0, R9, R8, 44   # 0x1536
        BRA_PRED         0, L1544   # 0x153a
        C_XOR            R8, R5   # 0x153e
        SZ_GLOBAL_ST_8   R8, R2, R3, 0, 0   # 0x1540
L1544:  ADD              R8, R1, R3, R1   # 0x1544
        OR               R9, R0, R8, R0   # 0x1548
        C_AND            R9, R14   # 0x154c
        AND              R10, R0, R8, R0   # 0x154e
        OR               R9, R10, R9, R10   # 0x1552
        ADD              R3, R4, R3, R4   # 0x1556
        ADD              R10, R0, R6, R0   # 0x155a
        SETP_LT_U_NP     P0, R3, R3, R10   # 0x155e
        OR               R3, R0, R6, R0   # 0x1562
        C_ANDN           R3, R10   # 0x1566
        AND              R10, R0, R6, R0   # 0x1568
        OR               R3, R10, R3, R10   # 0x156c
        SHRI             R3, R3, 31   # 0x1570
        SHRI             R9, R9, 31   # 0x1574
        SETP_EQ_NP       P1, R10, R9, R3   # 0x1578
        ADD              R3, R12, R3, R12   # 0x157c
        ADD              R9, R12, R9, R12   # 0x1580
        SETP_LT_U_NP     P2, R3, R9, R3   # 0x1584
        C_SUB            R14, R1   # 0x1588
        C_MOV            R3, R8   # 0x158a
        BRA_PRED         2, L1532   # 0x158c
        PAND             P0, 1, 0   # 0x1590
        C_MOV            R3, R8   # 0x1592
        BRA_PRED         0, L1532   # 0x1594
L1598:  MOVI             R0, 65535   # 0x1598
        LD_LOCAL         R1, 48   # 0x159c
        AND              R2, R1, R0, R1   # 0x15a0
        LD_GLOBAL        R1, R15, -36   # 0x15a4
        CALL             R14, 129904   # 0x15a8
        MOVI             R15, 2   # 0x15ac
        LD_GLOBAL        R15, R15, 24   # 0x15b0
        SRD              R3, 2   # 0x15b4
        C_ADD            R15, R3   # 0x15b6
        C_MOV            R2, R1   # 0x15b8
        LD_LOCAL         R1, 28   # 0x15ba
        CALL             R14, 129893   # 0x15be
        MOVI             R15, 2   # 0x15c2
        LD_GLOBAL        R15, R15, 24   # 0x15c6
        SRD              R3, 2   # 0x15ca
        C_ADD            R15, R3   # 0x15cc
        C_MOV            R2, R1   # 0x15ce
        LD_GLOBAL        R1, R15, -32   # 0x15d0
        CALL             R14, 129882   # 0x15d4
        MOVI             R15, 2   # 0x15d8
        LD_GLOBAL        R15, R15, 24   # 0x15dc
        SRD              R3, 2   # 0x15e0
        C_ADD            R15, R3   # 0x15e2
        C_MOV            R2, R1   # 0x15e4
        LD_LOCAL         R1, 32   # 0x15e6
        CALL             R14, 129871   # 0x15ea
        MOVI             R15, 2   # 0x15ee
        LD_GLOBAL        R15, R15, 24   # 0x15f2
        SRD              R3, 2   # 0x15f6
        C_ADD            R15, R3   # 0x15f8
        C_MOV            R2, R1   # 0x15fa
        LD_GLOBAL        R1, R15, -28   # 0x15fc
        CALL             R14, 129860   # 0x1600
        MOVI             R15, 2   # 0x1604
        LD_GLOBAL        R15, R15, 24   # 0x1608
        SRD              R3, 2   # 0x160c
        C_ADD            R15, R3   # 0x160e
        C_MOV            R2, R1   # 0x1610
        LD_LOCAL         R1, 12   # 0x1612
        CALL             R14, 129849   # 0x1616
        MOVI             R15, 2   # 0x161a
        LD_GLOBAL        R15, R15, 24   # 0x161e
        SRD              R3, 2   # 0x1622
        C_ADD            R15, R3   # 0x1624
        C_MOV            R2, R1   # 0x1626
        LD_GLOBAL        R1, R15, -24   # 0x1628
        CALL             R14, 129838   # 0x162c
        MOVI             R15, 2   # 0x1630
        LD_GLOBAL        R15, R15, 24   # 0x1634
        SRD              R3, 2   # 0x1638
        C_ADD            R15, R3   # 0x163a
        C_MOV            R2, R1   # 0x163c
        LD_LOCAL         R1, 16   # 0x163e
        CALL             R14, 129827   # 0x1642
        MOVI             R15, 2   # 0x1646
        LD_GLOBAL        R15, R15, 24   # 0x164a
        SRD              R3, 2   # 0x164e
        C_ADD            R15, R3   # 0x1650
        C_MOV            R2, R1   # 0x1652
        LD_GLOBAL        R1, R15, -20   # 0x1654
        CALL             R14, 129816   # 0x1658
        MOVI             R15, 2   # 0x165c
        LD_GLOBAL        R15, R15, 24   # 0x1660
        SRD              R3, 2   # 0x1664
        C_ADD            R15, R3   # 0x1666
        C_MOV            R2, R1   # 0x1668
        LD_LOCAL         R1, 24   # 0x166a
        CALL             R14, 129805   # 0x166e
        MOVI             R15, 2   # 0x1672
        LD_GLOBAL        R15, R15, 24   # 0x1676
        SRD              R3, 2   # 0x167a
        C_ADD            R15, R3   # 0x167c
        C_MOV            R2, R1   # 0x167e
        LD_GLOBAL        R1, R15, -16   # 0x1680
        CALL             R14, 129794   # 0x1684
        MOVI             R15, 2   # 0x1688
        LD_GLOBAL        R15, R15, 24   # 0x168c
        SRD              R3, 2   # 0x1690
        C_ADD            R15, R3   # 0x1692
        C_MOV            R2, R1   # 0x1694
        LD_LOCAL         R1, 20   # 0x1696
        CALL             R14, 129783   # 0x169a
        MOVI             R15, 2   # 0x169e
        LD_GLOBAL        R15, R15, 24   # 0x16a2
        SRD              R3, 2   # 0x16a6
        C_ADD            R15, R3   # 0x16a8
        C_MOV            R2, R1   # 0x16aa
        LD_GLOBAL        R1, R15, -12   # 0x16ac
        CALL             R14, 129772   # 0x16b0
        MOVI             R15, 2   # 0x16b4
        LD_GLOBAL        R15, R15, 24   # 0x16b8
        SRD              R3, 2   # 0x16bc
        C_ADD            R15, R3   # 0x16be
        C_MOV            R2, R1   # 0x16c0
        C_MOV            R1, R7   # 0x16c2
        CALL             R14, 129762   # 0x16c4
        MOVI             R15, 2   # 0x16c8
        LD_GLOBAL        R15, R15, 24   # 0x16cc
        SRD              R3, 2   # 0x16d0
        C_ADD            R15, R3   # 0x16d2
        C_MOV            R2, R1   # 0x16d4
        LD_GLOBAL        R1, R15, -8   # 0x16d6
        CALL             R14, 129751   # 0x16da
        MOVI             R15, 2   # 0x16de
        LD_GLOBAL        R15, R15, 24   # 0x16e2
        SRD              R3, 2   # 0x16e6
        C_ADD            R15, R3   # 0x16e8
        C_MOV            R2, R1   # 0x16ea
        MOVI             R1, 0   # 0x16ec
        CALL             R14, 129740   # 0x16f0
        MOVI             R15, 2   # 0x16f4
        LD_GLOBAL        R15, R15, 24   # 0x16f8
        SRD              R3, 2   # 0x16fc
        C_ADD            R15, R3   # 0x16fe
        LD_LOCAL         R14, 44   # 0x1700
        LD_LOCAL         R13, 72   # 0x1704
        LD_LOCAL         R12, 68   # 0x1708
        LD_LOCAL         R11, 64   # 0x170c
        LD_LOCAL         R10, 60   # 0x1710
        LD_LOCAL         R9, 56   # 0x1714
        LD_LOCAL         R8, 52   # 0x1718
        C_RET            224   # 0x171c
        XOR              R0, R2, R1, R2   # 0x171e
        C_ANDI           R0, 1   # 0x1722
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1724
        C_SHRI           R2, 1   # 0x1728
        MOVI48           R3, 4294942721   # 0x172a
        XOR              R0, R2, R3, R2   # 0x1730
        MOV_P            R2, 0, R0, R0, R0   # 0x1734
        C_MOV            R0, R1   # 0x1738
        C_SHRI           R0, 1   # 0x173a
        C_XOR            R0, R2   # 0x173c
        C_ANDI           R0, 1   # 0x173e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1740
        C_SHRI           R2, 1   # 0x1744
        MOVI             R0, 32767   # 0x1746
        C_AND            R2, R0   # 0x174a
        XOR              R4, R2, R3, R2   # 0x174c
        MOV_P            R2, 0, R4, R4, R4   # 0x1750
        C_MOV            R4, R1   # 0x1754
        C_SHRI           R4, 2   # 0x1756
        C_XOR            R4, R2   # 0x1758
        C_ANDI           R4, 1   # 0x175a
        SETP_NE_NPI      P0, R4, R4, 0   # 0x175c
        C_SHRI           R2, 1   # 0x1760
        C_AND            R2, R0   # 0x1762
        XOR              R4, R2, R3, R2   # 0x1764
        MOV_P            R2, 0, R4, R4, R4   # 0x1768
        C_MOV            R4, R1   # 0x176c
        C_SHRI           R4, 3   # 0x176e
        C_XOR            R4, R2   # 0x1770
        C_ANDI           R4, 1   # 0x1772
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1774
        C_SHRI           R2, 1   # 0x1778
        C_AND            R2, R0   # 0x177a
        XOR              R4, R2, R3, R2   # 0x177c
        MOV_P            R2, 0, R4, R4, R4   # 0x1780
        C_MOV            R4, R1   # 0x1784
        C_SHRI           R4, 4   # 0x1786
        C_XOR            R4, R2   # 0x1788
        C_ANDI           R4, 1   # 0x178a
        SETP_NE_NPI      P0, R4, R4, 0   # 0x178c
        C_SHRI           R2, 1   # 0x1790
        C_AND            R2, R0   # 0x1792
        XOR              R4, R2, R3, R2   # 0x1794
        MOV_P            R2, 0, R4, R4, R4   # 0x1798
        C_MOV            R4, R1   # 0x179c
        C_SHRI           R4, 5   # 0x179e
        C_XOR            R4, R2   # 0x17a0
        C_ANDI           R4, 1   # 0x17a2
        SETP_NE_NPI      P0, R4, R4, 0   # 0x17a4
        C_SHRI           R2, 1   # 0x17a8
        C_AND            R2, R0   # 0x17aa
        XOR              R4, R2, R3, R2   # 0x17ac
        MOV_P            R2, 0, R4, R4, R4   # 0x17b0
        C_MOV            R4, R1   # 0x17b4
        C_SHRI           R4, 6   # 0x17b6
        C_XOR            R4, R2   # 0x17b8
        C_ANDI           R4, 1   # 0x17ba
        SETP_NE_NPI      P0, R4, R4, 0   # 0x17bc
        C_SHRI           R2, 1   # 0x17c0
        C_AND            R2, R0   # 0x17c2
        XOR              R4, R2, R3, R2   # 0x17c4
        MOV_P            R2, 0, R4, R4, R4   # 0x17c8
        ANDI             R4, R1, 128   # 0x17cc
        C_SHRI           R4, 7   # 0x17d0
        ANDI             R5, R2, 1   # 0x17d2
        SETP_EQ_NP       P0, R4, R4, R5   # 0x17d6
        C_SHRI           R2, 1   # 0x17da
        C_AND            R2, R0   # 0x17dc
        XOR              R4, R2, R3, R2   # 0x17de
        MOV_P            R4, 0, R2, R2, R2   # 0x17e2
        C_MOV            R2, R1   # 0x17e6
        C_SHRI           R2, 8   # 0x17e8
        XOR              R2, R4, R2, R4   # 0x17ea
        C_ANDI           R2, 1   # 0x17ee
        SETP_NE_NPI      P0, R2, R2, 0   # 0x17f0
        C_SHRI           R4, 1   # 0x17f4
        AND              R2, R4, R0, R4   # 0x17f6
        XOR              R4, R2, R3, R2   # 0x17fa
        MOV_P            R2, 0, R4, R4, R4   # 0x17fe
        C_MOV            R4, R1   # 0x1802
        C_SHRI           R4, 9   # 0x1804
        C_XOR            R4, R2   # 0x1806
        C_ANDI           R4, 1   # 0x1808
        SETP_NE_NPI      P0, R4, R4, 0   # 0x180a
        C_SHRI           R2, 1   # 0x180e
        C_AND            R2, R0   # 0x1810
        XOR              R4, R2, R3, R2   # 0x1812
        MOV_P            R2, 0, R4, R4, R4   # 0x1816
        C_MOV            R4, R1   # 0x181a
        C_SHRI           R4, 10   # 0x181c
        C_XOR            R4, R2   # 0x181e
        C_ANDI           R4, 1   # 0x1820
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1822
        C_SHRI           R2, 1   # 0x1826
        C_AND            R2, R0   # 0x1828
        XOR              R4, R2, R3, R2   # 0x182a
        MOV_P            R2, 0, R4, R4, R4   # 0x182e
        C_MOV            R4, R1   # 0x1832
        C_SHRI           R4, 11   # 0x1834
        C_XOR            R4, R2   # 0x1836
        C_ANDI           R4, 1   # 0x1838
        SETP_NE_NPI      P0, R4, R4, 0   # 0x183a
        C_SHRI           R2, 1   # 0x183e
        C_AND            R2, R0   # 0x1840
        XOR              R4, R2, R3, R2   # 0x1842
        MOV_P            R2, 0, R4, R4, R4   # 0x1846
        C_MOV            R4, R1   # 0x184a
        C_SHRI           R4, 12   # 0x184c
        C_XOR            R4, R2   # 0x184e
        C_ANDI           R4, 1   # 0x1850
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1852
        C_SHRI           R2, 1   # 0x1856
        C_AND            R2, R0   # 0x1858
        XOR              R4, R2, R3, R2   # 0x185a
        MOV_P            R2, 0, R4, R4, R4   # 0x185e
        C_MOV            R4, R1   # 0x1862
        C_SHRI           R4, 13   # 0x1864
        C_XOR            R4, R2   # 0x1866
        C_ANDI           R4, 1   # 0x1868
        SETP_NE_NPI      P0, R4, R4, 0   # 0x186a
        C_SHRI           R2, 1   # 0x186e
        C_AND            R2, R0   # 0x1870
        XOR              R4, R2, R3, R2   # 0x1872
        MOV_P            R2, 0, R4, R4, R4   # 0x1876
        C_MOV            R4, R1   # 0x187a
        C_SHRI           R4, 14   # 0x187c
        C_XOR            R4, R2   # 0x187e
        C_SHRI           R2, 1   # 0x1880
        C_AND            R2, R0   # 0x1882
        XOR              R3, R2, R3, R2   # 0x1884
        C_ANDI           R4, 1   # 0x1888
        SETP_NE_NPI      P0, R4, R4, 0   # 0x188a
        MOV_P            R2, 0, R3, R3, R3   # 0x188e
        MOVI             R3, 32768   # 0x1892
        C_AND            R1, R3   # 0x1896
        C_SHRI           R1, 15   # 0x1898
        ANDI             R3, R2, 1   # 0x189a
        SETP_EQ_NP       P0, R1, R1, R3   # 0x189e
        C_SHRI           R2, 1   # 0x18a2
        AND              R0, R2, R0, R2   # 0x18a4
        MOVI             R1, 40961   # 0x18a8
        XOR              R1, R0, R1, R0   # 0x18ac
        MOV_P            R1, 0, R0, R0, R0   # 0x18b0
        C_RET            224   # 0x18b4
        ST_LOCAL         R8, 68   # 0x18b6
        ST_LOCAL         R9, 72   # 0x18ba
        ST_LOCAL         R10, 76   # 0x18be
        ST_LOCAL         R11, 80   # 0x18c2
        ST_LOCAL         R12, 84   # 0x18c6
        ST_LOCAL         R13, 88   # 0x18ca
        ST_LOCAL         R14, 52   # 0x18ce
        ST_LOCAL         R4, 56   # 0x18d2
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x18d6
        SHLI             R0, R0, 16   # 0x18da
        ST_LOCAL         R0, 36   # 0x18de
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x18e2
        ST_LOCAL         R0, 40   # 0x18e6
        SHRI             R0, R0, 16   # 0x18ea
        ST_LOCAL         R0, 60   # 0x18ee
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x18f2
        SHLI             R0, R0, 16   # 0x18f6
        LD_GLOBAL_IDX    R7, R1, R2, 0, 8   # 0x18fa
        SHRI             R4, R7, 16   # 0x18fe
        C_OR             R0, R4   # 0x1902
        LD_GLOBAL_IDX    R4, R1, R2, 0, 28   # 0x1904
        SHLI             R4, R4, 16   # 0x1908
        LD_GLOBAL_IDX    R5, R1, R2, 0, 24   # 0x190c
        SHRI             R6, R5, 16   # 0x1910
        C_OR             R4, R6   # 0x1914
        ST_LOCAL         R4, 12   # 0x1916
        MOVI             R6, 65535   # 0x191a
        AND              R4, R7, R6, R7   # 0x191e
        AND              R12, R5, R6, R5   # 0x1922
        LD_GLOBAL_IDX    R2, R1, R2, 0, 0   # 0x1926
        ST_LOCAL         R3, 44   # 0x192a
        ORI              R1, R3, -4096   # 0x192e
        ST_LOCAL         R1, 32   # 0x1932
        SETP_EQ_NPI      P0, R1, R2, 0   # 0x1936
        ANDI             R10, R2, -2   # 0x193a
        ANDI             R1, R2, 1   # 0x193e
        ST_LOCAL         R1, 24   # 0x1942
        ADDI             R1, R2, -1   # 0x1946
        ST_LOCAL         R1, 20   # 0x194a
        ANDI             R1, R2, -4   # 0x194e
        ST_LOCAL         R1, 48   # 0x1952
        MOVI             R15, 0   # 0x1956
        ST_LOCAL         R12, 16   # 0x195a
        BRA_PRED         0, L1bfc   # 0x195e
        ANDI             R1, R2, 3   # 0x1962
        MOVI             R5, 0   # 0x1966
        MOVI             R6, 0   # 0x196a
        LD_LOCAL         R7, 44   # 0x196e
        LD_LOCAL         R14, 48   # 0x1972
        C_BRA            L1984   # 0x1976
L1978:  C_ADD            R5, R2   # 0x1978
        C_ADDI           R6, 1   # 0x197a
        SETP_NE_NP       P0, R3, R6, R2   # 0x197c
        BRA_PRED         4, L1a08   # 0x1980
L1984:  LD_LOCAL         R3, 20   # 0x1984
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1988
        MOVI             R3, 0   # 0x198c
        BRA_PRED         0, L19da   # 0x1990
L1994:  ADD              R8, R5, R3, R5   # 0x1994
        C_SHLI           R8, 1   # 0x1998
        ADD              R8, R4, R8, R4   # 0x199a
        SZ_GLOBAL_LD_U16 R9, R0, R8, 0, 0   # 0x199e
        C_ADD            R9, R7   # 0x19a2
        SZ_GLOBAL_ST_16  R9, R0, R8, 0, 0   # 0x19a4
        ADDI             R9, R8, 2   # 0x19a8
        SZ_GLOBAL_LD_U16 R11, R0, R9, 0, 0   # 0x19ac
        C_ADD            R11, R7   # 0x19b0
        SZ_GLOBAL_ST_16  R11, R0, R9, 0, 0   # 0x19b2
        ADDI             R9, R8, 4   # 0x19b6
        SZ_GLOBAL_LD_U16 R11, R0, R9, 0, 0   # 0x19ba
        C_ADD            R11, R7   # 0x19be
        SZ_GLOBAL_ST_16  R11, R0, R9, 0, 0   # 0x19c0
        C_ADDI           R8, 6   # 0x19c4
        SZ_GLOBAL_LD_U16 R9, R0, R8, 0, 0   # 0x19c6
        C_ADD            R9, R7   # 0x19ca
        SZ_GLOBAL_ST_16  R9, R0, R8, 0, 0   # 0x19cc
        C_ADDI           R3, 4   # 0x19d0
        SETP_NE_NP       P0, R8, R14, R3   # 0x19d2
        BRA_PRED         0, L1994   # 0x19d6
L19da:  SETP_EQ_NPI      P0, R8, R1, 0   # 0x19da
        BRA_PRED         0, L1978   # 0x19de
        C_ADD            R3, R5   # 0x19e2
        C_MOV            R8, R1   # 0x19e4
L19e6:  C_MOV            R9, R3   # 0x19e6
        C_SHLI           R9, 1   # 0x19e8
        ADD              R9, R4, R9, R4   # 0x19ea
        SZ_GLOBAL_LD_U16 R11, R0, R9, 0, 0   # 0x19ee
        C_ADD            R11, R7   # 0x19f2
        SZ_GLOBAL_ST_16  R11, R0, R9, 0, 0   # 0x19f4
        C_ADDI           R3, 1   # 0x19f8
        ADDI             R8, R8, -1   # 0x19fa
        SETP_NE_NPI      P0, R9, R8, 0   # 0x19fe
        BRA_PRED         0, L19e6   # 0x1a02
        C_BRA            L1978   # 0x1a06
L1a08:  MOVI             R5, 0   # 0x1a08
        SHLI             R3, R7, 16   # 0x1a0c
        SRAI             R8, R3, 16   # 0x1a10
        MOVI             R11, 0   # 0x1a14
        C_BRA            L1a26   # 0x1a18
L1a1a:  C_ADD            R5, R2   # 0x1a1a
        C_ADDI           R11, 1   # 0x1a1c
        SETP_NE_NP       P0, R3, R11, R2   # 0x1a1e
        BRA_PRED         4, L1af4   # 0x1a22
L1a26:  LD_LOCAL         R3, 20   # 0x1a26
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1a2a
        MOVI             R6, 0   # 0x1a2e
        LD_LOCAL         R7, 16   # 0x1a32
        BRA_PRED         0, L1ab8   # 0x1a36
L1a3a:  ADD              R3, R5, R6, R5   # 0x1a3a
        C_MOV            R9, R3   # 0x1a3e
        C_SHLI           R9, 2   # 0x1a40
        ADD              R9, R7, R9, R7   # 0x1a42
        C_MOV            R12, R3   # 0x1a46
        C_SHLI           R12, 1   # 0x1a48
        ADD              R12, R4, R12, R4   # 0x1a4a
        SZ_GLOBAL_LD_S16 R12, R0, R12, 0, 0   # 0x1a4e
        C_MUL_LO         R12, R8   # 0x1a52
        LD_LOCAL         R15, 12   # 0x1a54
        ST_GLOBAL_IDX    R12, R15, R9, 0, 0   # 0x1a58
        ADDI             R9, R3, 1   # 0x1a5c
        C_MOV            R12, R9   # 0x1a60
        C_SHLI           R12, 2   # 0x1a62
        ADD              R12, R7, R12, R7   # 0x1a64
        C_SHLI           R9, 1   # 0x1a68
        ADD              R9, R4, R9, R4   # 0x1a6a
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1a6e
        C_MUL_LO         R9, R8   # 0x1a72
        ST_GLOBAL_IDX    R9, R15, R12, 0, 0   # 0x1a74
        ADDI             R9, R3, 2   # 0x1a78
        C_MOV            R12, R9   # 0x1a7c
        C_SHLI           R12, 2   # 0x1a7e
        ADD              R12, R7, R12, R7   # 0x1a80
        C_SHLI           R9, 1   # 0x1a84
        ADD              R9, R4, R9, R4   # 0x1a86
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1a8a
        C_MUL_LO         R9, R8   # 0x1a8e
        ST_GLOBAL_IDX    R9, R15, R12, 0, 0   # 0x1a90
        C_ADDI           R3, 3   # 0x1a94
        C_MOV            R9, R3   # 0x1a96
        C_SHLI           R9, 2   # 0x1a98
        ADD              R9, R7, R9, R7   # 0x1a9a
        C_SHLI           R3, 1   # 0x1a9e
        ADD              R3, R4, R3, R4   # 0x1aa0
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x1aa4
        C_MUL_LO         R3, R8   # 0x1aa8
        ST_GLOBAL_IDX    R3, R15, R9, 0, 0   # 0x1aaa
        C_ADDI           R6, 4   # 0x1aae
        SETP_NE_NP       P0, R3, R14, R6   # 0x1ab0
        BRA_PRED         0, L1a3a   # 0x1ab4
L1ab8:  SETP_EQ_NPI      P0, R3, R1, 0   # 0x1ab8
        BRA_PRED         0, L1a1a   # 0x1abc
        ADD              R3, R6, R5, R6   # 0x1ac0
        C_MOV            R6, R1   # 0x1ac4
L1ac6:  C_MOV            R9, R3   # 0x1ac6
        C_SHLI           R9, 2   # 0x1ac8
        ADD              R9, R7, R9, R7   # 0x1aca
        C_MOV            R12, R3   # 0x1ace
        C_SHLI           R12, 1   # 0x1ad0
        ADD              R12, R4, R12, R4   # 0x1ad2
        SZ_GLOBAL_LD_S16 R12, R0, R12, 0, 0   # 0x1ad6
        C_MUL_LO         R12, R8   # 0x1ada
        LD_LOCAL         R15, 12   # 0x1adc
        ST_GLOBAL_IDX    R12, R15, R9, 0, 0   # 0x1ae0
        C_ADDI           R3, 1   # 0x1ae4
        ADDI             R6, R6, -1   # 0x1ae6
        SETP_NE_NPI      P0, R9, R6, 0   # 0x1aea
        BRA_PRED         0, L1ac6   # 0x1aee
        C_BRA            L1a1a   # 0x1af2
L1af4:  MOVI             R5, 10   # 0x1af4
        MOVI             R9, 0   # 0x1af8
        MOVI             R8, 0   # 0x1afc
        MOVI             R15, 0   # 0x1b00
        MOVI             R11, 0   # 0x1b04
        MOVI             R13, 0   # 0x1b08
        LD_LOCAL         R12, 16   # 0x1b0c
        LD_LOCAL         R14, 32   # 0x1b10
        C_BRA            L1b22   # 0x1b14
L1b16:  C_ADD            R9, R2   # 0x1b16
        C_ADDI           R8, 1   # 0x1b18
        SETP_NE_NP       P0, R3, R8, R2   # 0x1b1a
        BRA_PRED         4, L1bfc   # 0x1b1e
L1b22:  ST_LOCAL         R8, 28   # 0x1b22
        LD_LOCAL         R3, 20   # 0x1b26
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1b2a
        BRA_PRED         0, L1baa   # 0x1b2e
        MOVI             R6, 0   # 0x1b32
        C_MOV            R3, R11   # 0x1b36
L1b38:  C_MOV            R8, R9   # 0x1b38
        ADD              R9, R8, R6, R8   # 0x1b3a
        C_SHLI           R9, 2   # 0x1b3e
        C_ADD            R9, R12   # 0x1b40
        LD_LOCAL         R1, 12   # 0x1b42
        LD_GLOBAL_IDX    R7, R1, R9, 0, 0   # 0x1b46
        C_ADDI           R9, 4   # 0x1b4a
        LD_GLOBAL_IDX    R11, R1, R9, 0, 0   # 0x1b4c
        SETP_LT_NP       P0, R9, R7, R11   # 0x1b50
        MOVI             R9, 0   # 0x1b54
        ADDI_P           R9, 0, R9, 1   # 0x1b58
        ADD              R13, R7, R13, R7   # 0x1b5c
        C_MOV            R5, R12   # 0x1b60
        SETP_LT_NP       P0, R12, R14, R13   # 0x1b62
        MOVI             R1, 0   # 0x1b66
        MOV_P            R13, 0, R1, R1, R1   # 0x1b6a
        ADD              R13, R11, R13, R11   # 0x1b6e
        SETP_LT_NP       P1, R12, R14, R13   # 0x1b72
        C_MOV            R12, R5   # 0x1b76
        MOVI             R5, 10   # 0x1b78
        MOV_P            R13, 1, R1, R1, R1   # 0x1b7c
        MOV_P            R9, 1, R5, R5, R5   # 0x1b80
        SETP_LT_NP       P1, R3, R3, R7   # 0x1b84
        MOVI             R3, 0   # 0x1b88
        ADDI_P           R3, 1, R3, 1   # 0x1b8c
        MOV_P            R3, 0, R5, R5, R5   # 0x1b90
        C_ADD            R3, R15   # 0x1b94
        ADD              R15, R9, R3, R9   # 0x1b96
        C_MOV            R9, R8   # 0x1b9a
        C_ADDI           R6, 2   # 0x1b9c
        SETP_NE_NP       P0, R3, R10, R6   # 0x1b9e
        C_MOV            R3, R11   # 0x1ba2
        BRA_PRED         0, L1b38   # 0x1ba4
        C_BRA            L1bae   # 0x1ba8
L1baa:  MOVI             R6, 0   # 0x1baa
L1bae:  LD_LOCAL         R3, 24   # 0x1bae
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1bb2
        MOVI             R1, 0   # 0x1bb6
        LD_LOCAL         R8, 28   # 0x1bba
        BRA_PRED         0, L1b16   # 0x1bbe
        MUL_LO           R3, R8, R2, R2   # 0x1bc2
        ADD              R3, R6, R3, R6   # 0x1bc6
        C_SHLI           R3, 2   # 0x1bca
        ADD              R3, R12, R3, R12   # 0x1bcc
        LD_LOCAL         R6, 12   # 0x1bd0
        LD_GLOBAL_IDX    R3, R6, R3, 0, 0   # 0x1bd4
        ADD              R13, R3, R13, R3   # 0x1bd8
        SETP_LT_NP       P0, R6, R14, R13   # 0x1bdc
        MOV_P            R13, 0, R1, R1, R1   # 0x1be0
        SETP_LT_NP       P1, R6, R11, R3   # 0x1be4
        MOVI             R6, 0   # 0x1be8
        ADDI_P           R6, 1, R6, 1   # 0x1bec
        MOV_P            R6, 0, R5, R5, R5   # 0x1bf0
        ADD              R15, R6, R15, R6   # 0x1bf4
        C_MOV            R11, R3   # 0x1bf8
        C_BRA            L1b16   # 0x1bfa
L1bfc:  ST_LOCAL         R15, 64   # 0x1bfc
        LD_LOCAL         R1, 36   # 0x1c00
        LD_LOCAL         R3, 60   # 0x1c04
        OR               R13, R1, R3, R1   # 0x1c08
        LD_LOCAL         R1, 40   # 0x1c0c
        MOVI             R3, 65535   # 0x1c10
        AND              R6, R1, R3, R1   # 0x1c14
        SETP_EQ_NPI      P0, R1, R2, 0   # 0x1c18
        MOVI             R5, 0   # 0x1c1c
        BRA_PRED         0, L1de0   # 0x1c20
        MOVI             R1, 0   # 0x1c24
        C_BRA            L1c4a   # 0x1c28
L1c2a:  C_MOV            R3, R5   # 0x1c2a
        C_SHLI           R3, 2   # 0x1c2c
        LD_LOCAL         R14, 16   # 0x1c2e
        ADD              R3, R14, R3, R14   # 0x1c32
        LD_LOCAL         R14, 12   # 0x1c36
        ST_GLOBAL_IDX    R7, R14, R3, 0, 0   # 0x1c3a
        C_ADD            R1, R2   # 0x1c3e
        C_ADDI           R5, 1   # 0x1c40
        SETP_NE_NP       P0, R3, R5, R2   # 0x1c42
        BRA_PRED         4, L1cba   # 0x1c46
L1c4a:  LD_LOCAL         R3, 20   # 0x1c4a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1c4e
        MOVI             R3, 0   # 0x1c52
        MOVI             R7, 0   # 0x1c56
        BRA_PRED         0, L1c8e   # 0x1c5a
L1c5e:  ADD              R8, R1, R3, R1   # 0x1c5e
        C_SHLI           R8, 1   # 0x1c62
        C_ADD            R8, R4   # 0x1c64
        C_MOV            R9, R3   # 0x1c66
        C_SHLI           R9, 1   # 0x1c68
        C_ADD            R9, R6   # 0x1c6a
        SZ_GLOBAL_LD_S16 R11, R13, R9, 0, 0   # 0x1c6c
        SZ_GLOBAL_LD_S16 R12, R0, R8, 0, 0   # 0x1c70
        MAD_ACC          R7, R11, R12   # 0x1c74
        C_ADDI           R9, 2   # 0x1c76
        SZ_GLOBAL_LD_S16 R9, R13, R9, 0, 0   # 0x1c78
        C_ADDI           R8, 2   # 0x1c7c
        SZ_GLOBAL_LD_S16 R8, R0, R8, 0, 0   # 0x1c7e
        MAD_ACC          R7, R9, R8   # 0x1c82
        C_ADDI           R3, 2   # 0x1c84
        SETP_NE_NP       P0, R8, R10, R3   # 0x1c86
        BRA_PRED         0, L1c5e   # 0x1c8a
L1c8e:  LD_LOCAL         R14, 24   # 0x1c8e
        SETP_EQ_NPI      P0, R8, R14, 0   # 0x1c92
        BRA_PRED         0, L1c2a   # 0x1c96
        MUL_LO           R8, R5, R2, R2   # 0x1c9a
        C_MOV            R9, R3   # 0x1c9e
        C_SHLI           R9, 1   # 0x1ca0
        ADD              R9, R6, R9, R6   # 0x1ca2
        SZ_GLOBAL_LD_S16 R9, R13, R9, 0, 0   # 0x1ca6
        C_ADD            R3, R8   # 0x1caa
        C_SHLI           R3, 1   # 0x1cac
        ADD              R3, R4, R3, R4   # 0x1cae
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x1cb2
        MAD_ACC          R7, R9, R3   # 0x1cb6
        C_BRA            L1c2a   # 0x1cb8
L1cba:  MOVI             R3, 0   # 0x1cba
        MOVI             R1, 0   # 0x1cbe
        ST_LOCAL         R1, 36   # 0x1cc2
        MOVI             R5, 0   # 0x1cc6
        MOVI             R12, 0   # 0x1cca
        MOVI             R11, 0   # 0x1cce
        C_BRA            L1cec   # 0x1cd2
L1cd4:  LD_LOCAL         R3, 28   # 0x1cd4
        C_ADD            R3, R2   # 0x1cd8
        LD_LOCAL         R1, 36   # 0x1cda
        C_ADDI           R1, 1   # 0x1cde
        ST_LOCAL         R1, 36   # 0x1ce0
        SETP_NE_NP       P0, R1, R1, R2   # 0x1ce4
        BRA_PRED         4, L1de0   # 0x1ce8
L1cec:  ST_LOCAL         R3, 28   # 0x1cec
        LD_LOCAL         R1, 20   # 0x1cf0
        SETP_EQ_NPI      P0, R3, R1, 0   # 0x1cf4
        BRA_PRED         0, L1d82   # 0x1cf8
        MOVI             R8, 0   # 0x1cfc
        C_MOV            R3, R12   # 0x1d00
        LD_LOCAL         R15, 32   # 0x1d02
        LD_LOCAL         R1, 16   # 0x1d06
        LD_LOCAL         R1, 28   # 0x1d0a
L1d0e:  LD_LOCAL         R1, 28   # 0x1d0e
        ADD              R9, R1, R8, R1   # 0x1d12
        C_SHLI           R9, 2   # 0x1d16
        LD_LOCAL         R1, 16   # 0x1d18
        C_ADD            R9, R1   # 0x1d1c
        LD_LOCAL         R7, 12   # 0x1d1e
        LD_GLOBAL_IDX    R1, R7, R9, 0, 0   # 0x1d22
        C_ADDI           R9, 4   # 0x1d26
        LD_GLOBAL_IDX    R12, R7, R9, 0, 0   # 0x1d28
        SETP_LT_NP       P0, R9, R1, R12   # 0x1d2c
        MOVI             R9, 0   # 0x1d30
        ADDI_P           R9, 0, R9, 1   # 0x1d34
        ADD              R11, R1, R11, R1   # 0x1d38
        C_MOV            R14, R5   # 0x1d3c
        SETP_LT_NP       P0, R5, R15, R11   # 0x1d3e
        MOVI             R7, 0   # 0x1d42
        MOV_P            R11, 0, R7, R7, R7   # 0x1d46
        ADD              R11, R12, R11, R12   # 0x1d4a
        SETP_LT_NP       P1, R5, R15, R11   # 0x1d4e
        MOV_P            R11, 1, R7, R7, R7   # 0x1d52
        MOVI             R5, 10   # 0x1d56
        MOV_P            R9, 1, R5, R5, R5   # 0x1d5a
        SETP_LT_NP       P1, R1, R3, R1   # 0x1d5e
        MOVI             R1, 0   # 0x1d62
        ADDI_P           R1, 1, R1, 1   # 0x1d66
        MOV_P            R1, 0, R5, R5, R5   # 0x1d6a
        C_ADD            R1, R14   # 0x1d6e
        ADD              R5, R9, R1, R9   # 0x1d70
        C_ADDI           R8, 2   # 0x1d74
        SETP_NE_NP       P0, R1, R10, R8   # 0x1d76
        C_MOV            R3, R12   # 0x1d7a
        BRA_PRED         0, L1d0e   # 0x1d7c
        C_BRA            L1d8a   # 0x1d80
L1d82:  MOVI             R8, 0   # 0x1d82
        LD_LOCAL         R15, 32   # 0x1d86
L1d8a:  LD_LOCAL         R1, 24   # 0x1d8a
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x1d8e
        MOVI             R14, 0   # 0x1d92
        MOVI             R9, 10   # 0x1d96
        BRA_PRED         0, L1cd4   # 0x1d9a
        LD_LOCAL         R1, 36   # 0x1d9e
        C_MUL_LO         R1, R2   # 0x1da2
        ADD              R1, R8, R1, R8   # 0x1da4
        C_SHLI           R1, 2   # 0x1da8
        LD_LOCAL         R3, 16   # 0x1daa
        ADD              R1, R3, R1, R3   # 0x1dae
        LD_LOCAL         R3, 12   # 0x1db2
        LD_GLOBAL_IDX    R1, R3, R1, 0, 0   # 0x1db6
        ADD              R11, R1, R11, R1   # 0x1dba
        SETP_LT_NP       P0, R3, R15, R11   # 0x1dbe
        MOV_P            R11, 0, R14, R14, R14   # 0x1dc2
        SETP_LT_NP       P1, R3, R12, R1   # 0x1dc6
        MOVI             R3, 0   # 0x1dca
        ADDI_P           R3, 1, R3, 1   # 0x1dce
        MOV_P            R3, 0, R9, R9, R9   # 0x1dd2
        ADD              R5, R3, R5, R3   # 0x1dd6
        C_MOV            R12, R1   # 0x1dda
        BRA              L1cd4   # 0x1ddc
L1de0:  ST_LOCAL         R5, 60   # 0x1de0
        MOVI             R1, 0   # 0x1de4
        ST_LOCAL         R1, 36   # 0x1de8
        SETP_EQ_NPI      P0, R1, R2, 0   # 0x1dec
        C_MOV            R1, R2   # 0x1df0
        C_SHLI           R1, 1   # 0x1df2
        LD_LOCAL         R3, 12   # 0x1df4
        MOVI             R15, 0   # 0x1df8
        BRA_PRED         0, L200a   # 0x1dfc
        MOVI             R5, 0   # 0x1e00
        MOVI             R7, 0   # 0x1e04
        C_BRA            L1e1a   # 0x1e08
L1e0a:  C_ADD            R5, R2   # 0x1e0a
        LD_LOCAL         R7, 28   # 0x1e0c
        C_ADDI           R7, 1   # 0x1e10
        SETP_NE_NP       P0, R3, R7, R2   # 0x1e12
        BRA_PRED         4, L1ed6   # 0x1e16
L1e1a:  ST_LOCAL         R7, 28   # 0x1e1a
        MUL_LO           R8, R7, R2, R2   # 0x1e1e
        MOVI             R15, 0   # 0x1e22
        C_BRA            L1e48   # 0x1e26
L1e28:  ADD              R3, R15, R8, R15   # 0x1e28
        C_SHLI           R3, 2   # 0x1e2c
        LD_LOCAL         R14, 16   # 0x1e2e
        ADD              R3, R14, R3, R14   # 0x1e32
        LD_LOCAL         R14, 12   # 0x1e36
        ST_GLOBAL_IDX    R7, R14, R3, 0, 0   # 0x1e3a
        C_ADDI           R15, 1   # 0x1e3e
        SETP_NE_NP       P0, R3, R15, R2   # 0x1e40
        BRA_PRED         4, L1e0a   # 0x1e44
L1e48:  LD_LOCAL         R3, 20   # 0x1e48
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1e4c
        BRA_PRED         0, L1ea2   # 0x1e50
        MOVI             R9, 0   # 0x1e54
        C_MOV            R12, R15   # 0x1e58
        MOVI             R7, 0   # 0x1e5a
L1e5e:  ADD              R11, R5, R9, R5   # 0x1e5e
        C_SHLI           R11, 1   # 0x1e62
        C_ADD            R11, R4   # 0x1e64
        C_MOV            R3, R12   # 0x1e66
        C_SHLI           R3, 1   # 0x1e68
        ADD              R3, R6, R3, R6   # 0x1e6a
        SZ_GLOBAL_LD_S16 R3, R13, R3, 0, 0   # 0x1e6e
        SZ_GLOBAL_LD_S16 R14, R0, R11, 0, 0   # 0x1e72
        MADLO            R3, R3, R14, R7   # 0x1e76
        ADD              R7, R2, R12, R2   # 0x1e7a
        C_SHLI           R7, 1   # 0x1e7e
        ADD              R7, R6, R7, R6   # 0x1e80
        SZ_GLOBAL_LD_S16 R7, R13, R7, 0, 0   # 0x1e84
        ADDI             R14, R11, 2   # 0x1e88
        SZ_GLOBAL_LD_S16 R14, R0, R14, 0, 0   # 0x1e8c
        MADLO            R7, R7, R14, R3   # 0x1e90
        C_ADD            R12, R1   # 0x1e94
        C_ADDI           R9, 2   # 0x1e96
        SETP_NE_NP       P0, R3, R10, R9   # 0x1e98
        BRA_PRED         0, L1e5e   # 0x1e9c
        C_BRA            L1eaa   # 0x1ea0
L1ea2:  MOVI             R9, 0   # 0x1ea2
        MOVI             R7, 0   # 0x1ea6
L1eaa:  LD_LOCAL         R3, 24   # 0x1eaa
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1eae
        BRA_PRED         0, L1e28   # 0x1eb2
        MADLO            R3, R9, R2, R15   # 0x1eb6
        C_SHLI           R3, 1   # 0x1eba
        ADD              R3, R6, R3, R6   # 0x1ebc
        SZ_GLOBAL_LD_S16 R3, R13, R3, 0, 0   # 0x1ec0
        ADD              R14, R9, R8, R9   # 0x1ec4
        C_SHLI           R14, 1   # 0x1ec8
        ADD              R14, R4, R14, R4   # 0x1eca
        SZ_GLOBAL_LD_S16 R14, R0, R14, 0, 0   # 0x1ece
        MAD_ACC          R7, R3, R14   # 0x1ed2
        C_BRA            L1e28   # 0x1ed4
L1ed6:  MOVI             R14, 0   # 0x1ed6
        MOVI             R3, 0   # 0x1eda
        ST_LOCAL         R3, 40   # 0x1ede
        MOVI             R15, 0   # 0x1ee2
        MOVI             R12, 0   # 0x1ee6
        MOVI             R5, 0   # 0x1eea
        LD_LOCAL         R11, 12   # 0x1eee
        C_BRA            L1f08   # 0x1ef2
L1ef4:  C_ADD            R14, R2   # 0x1ef4
        LD_LOCAL         R3, 40   # 0x1ef6
        C_ADDI           R3, 1   # 0x1efa
        ST_LOCAL         R3, 40   # 0x1efc
        SETP_NE_NP       P0, R3, R3, R2   # 0x1f00
        BRA_PRED         4, L200a   # 0x1f04
L1f08:  LD_LOCAL         R3, 20   # 0x1f08
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1f0c
        BRA_PRED         0, L1fac   # 0x1f10
        MOVI             R9, 0   # 0x1f14
        C_MOV            R3, R12   # 0x1f18
        LD_LOCAL         R7, 16   # 0x1f1a
        LD_LOCAL         R7, 32   # 0x1f1e
L1f22:  ST_LOCAL         R15, 28   # 0x1f22
        C_MOV            R8, R14   # 0x1f26
        ADD              R14, R8, R9, R8   # 0x1f28
        C_SHLI           R14, 2   # 0x1f2c
        LD_LOCAL         R7, 16   # 0x1f2e
        C_ADD            R14, R7   # 0x1f32
        LD_LOCAL         R7, 12   # 0x1f34
        LD_GLOBAL_IDX    R15, R7, R14, 0, 0   # 0x1f38
        C_ADDI           R14, 4   # 0x1f3c
        LD_LOCAL         R7, 12   # 0x1f3e
        LD_GLOBAL_IDX    R12, R7, R14, 0, 0   # 0x1f42
        SETP_LT_NP       P0, R14, R15, R12   # 0x1f46
        MOVI             R14, 0   # 0x1f4a
        ADDI_P           R14, 0, R14, 1   # 0x1f4e
        ADD              R5, R15, R5, R15   # 0x1f52
        LD_LOCAL         R7, 32   # 0x1f56
        SETP_LT_NP       P0, R11, R7, R5   # 0x1f5a
        MOVI             R11, 0   # 0x1f5e
        MOV_P            R5, 0, R11, R11, R11   # 0x1f62
        ADD              R5, R12, R5, R12   # 0x1f66
        SETP_LT_NP       P1, R11, R7, R5   # 0x1f6a
        MOVI             R7, 0   # 0x1f6e
        MOV_P            R5, 1, R7, R7, R7   # 0x1f72
        MOVI             R7, 10   # 0x1f76
        MOV_P            R14, 1, R7, R7, R7   # 0x1f7a
        SETP_LT_NP       P1, R3, R3, R15   # 0x1f7e
        LD_LOCAL         R11, 12   # 0x1f82
        MOVI             R3, 0   # 0x1f86
        ADDI_P           R3, 1, R3, 1   # 0x1f8a
        MOV_P            R3, 0, R7, R7, R7   # 0x1f8e
        LD_LOCAL         R7, 28   # 0x1f92
        C_ADD            R3, R7   # 0x1f96
        ADD              R15, R14, R3, R14   # 0x1f98
        C_MOV            R14, R8   # 0x1f9c
        C_ADDI           R9, 2   # 0x1f9e
        SETP_NE_NP       P0, R3, R10, R9   # 0x1fa0
        C_MOV            R3, R12   # 0x1fa4
        BRA_PRED         0, L1f22   # 0x1fa6
        C_BRA            L1fb0   # 0x1faa
L1fac:  MOVI             R9, 0   # 0x1fac
L1fb0:  LD_LOCAL         R3, 24   # 0x1fb0
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1fb4
        MOVI             R8, 0   # 0x1fb8
        MOVI             R7, 10   # 0x1fbc
        BRA_PRED         0, L1ef4   # 0x1fc0
        LD_LOCAL         R3, 40   # 0x1fc4
        C_MUL_LO         R3, R2   # 0x1fc8
        ADD              R3, R9, R3, R9   # 0x1fca
        C_SHLI           R3, 2   # 0x1fce
        C_MOV            R9, R14   # 0x1fd0
        LD_LOCAL         R14, 16   # 0x1fd2
        ADD              R3, R14, R3, R14   # 0x1fd6
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x1fda
        ADD              R5, R3, R5, R3   # 0x1fde
        LD_LOCAL         R14, 32   # 0x1fe2
        SETP_LT_NP       P0, R14, R14, R5   # 0x1fe6
        MOV_P            R5, 0, R8, R8, R8   # 0x1fea
        SETP_LT_NP       P1, R14, R12, R3   # 0x1fee
        MOVI             R14, 0   # 0x1ff2
        ADDI_P           R14, 1, R14, 1   # 0x1ff6
        MOV_P            R14, 0, R7, R7, R7   # 0x1ffa
        ADD              R15, R14, R15, R14   # 0x1ffe
        C_MOV            R14, R9   # 0x2002
        C_MOV            R12, R3   # 0x2004
        BRA              L1ef4   # 0x2006
L200a:  ST_LOCAL         R15, 28   # 0x200a
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x200e
        BRA_PRED         0, L222c   # 0x2012
        MOVI             R5, 0   # 0x2016
        MOVI             R7, 0   # 0x201a
        C_BRA            L2030   # 0x201e
L2020:  C_ADD            R5, R2   # 0x2020
        LD_LOCAL         R7, 36   # 0x2022
        C_ADDI           R7, 1   # 0x2026
        SETP_NE_NP       P0, R3, R7, R2   # 0x2028
        BRA_PRED         4, L2118   # 0x202c
L2030:  ST_LOCAL         R7, 36   # 0x2030
        MUL_LO           R11, R7, R2, R2   # 0x2034
        MOVI             R3, 0   # 0x2038
        C_BRA            L205e   # 0x203c
L203e:  ADD              R7, R3, R11, R3   # 0x203e
        C_SHLI           R7, 2   # 0x2042
        LD_LOCAL         R14, 16   # 0x2044
        ADD              R7, R14, R7, R14   # 0x2048
        LD_LOCAL         R15, 12   # 0x204c
        ST_GLOBAL_IDX    R8, R15, R7, 0, 0   # 0x2050
        C_ADDI           R3, 1   # 0x2054
        SETP_NE_NP       P0, R7, R3, R2   # 0x2056
        BRA_PRED         4, L2020   # 0x205a
L205e:  LD_LOCAL         R7, 20   # 0x205e
        SETP_EQ_NPI      P0, R14, R7, 0   # 0x2062
        BRA_PRED         0, L20d6   # 0x2066
        MOVI             R9, 0   # 0x206a
        C_MOV            R12, R3   # 0x206e
        MOVI             R8, 0   # 0x2070
L2074:  ADD              R14, R5, R9, R5   # 0x2074
        C_SHLI           R14, 1   # 0x2078
        C_ADD            R14, R4   # 0x207a
        C_MOV            R15, R12   # 0x207c
        C_SHLI           R15, 1   # 0x207e
        ADD              R15, R6, R15, R6   # 0x2080
        SZ_GLOBAL_LD_U16 R15, R13, R15, 0, 0   # 0x2084
        SZ_GLOBAL_LD_U16 R7, R0, R14, 0, 0   # 0x2088
        MUL_LO           R7, R15, R7, R7   # 0x208c
        C_MOV            R15, R7   # 0x2090
        C_SHRI           R15, 5   # 0x2092
        ANDI             R15, R15, 127   # 0x2094
        C_SHRI           R7, 2   # 0x2098
        C_ANDI           R7, 15   # 0x209a
        MADLO            R7, R7, R15, R8   # 0x209c
        ADD              R15, R2, R12, R2   # 0x20a0
        C_SHLI           R15, 1   # 0x20a4
        ADD              R15, R6, R15, R6   # 0x20a6
        SZ_GLOBAL_LD_U16 R15, R13, R15, 0, 0   # 0x20aa
        C_ADDI           R14, 2   # 0x20ae
        SZ_GLOBAL_LD_U16 R14, R0, R14, 0, 0   # 0x20b0
        MUL_LO           R14, R15, R14, R14   # 0x20b4
        C_MOV            R15, R14   # 0x20b8
        C_SHRI           R15, 5   # 0x20ba
        ANDI             R15, R15, 127   # 0x20bc
        C_SHRI           R14, 2   # 0x20c0
        C_ANDI           R14, 15   # 0x20c2
        MADLO            R8, R14, R15, R7   # 0x20c4
        C_ADD            R12, R1   # 0x20c8
        C_ADDI           R9, 2   # 0x20ca
        SETP_NE_NP       P0, R7, R10, R9   # 0x20cc
        BRA_PRED         0, L2074   # 0x20d0
        C_BRA            L20de   # 0x20d4
L20d6:  MOVI             R9, 0   # 0x20d6
        MOVI             R8, 0   # 0x20da
L20de:  LD_LOCAL         R7, 24   # 0x20de
        SETP_EQ_NPI      P0, R7, R7, 0   # 0x20e2
        BRA_PRED         0, L203e   # 0x20e6
        MADLO            R7, R9, R2, R3   # 0x20ea
        C_SHLI           R7, 1   # 0x20ee
        ADD              R7, R6, R7, R6   # 0x20f0
        SZ_GLOBAL_LD_U16 R7, R13, R7, 0, 0   # 0x20f4
        ADD              R14, R9, R11, R9   # 0x20f8
        C_SHLI           R14, 1   # 0x20fc
        ADD              R14, R4, R14, R4   # 0x20fe
        SZ_GLOBAL_LD_U16 R14, R0, R14, 0, 0   # 0x2102
        C_MUL_LO         R7, R14   # 0x2106
        C_MOV            R14, R7   # 0x2108
        C_SHRI           R14, 5   # 0x210a
        ANDI             R14, R14, 127   # 0x210c
        C_SHRI           R7, 2   # 0x2110
        C_ANDI           R7, 15   # 0x2112
        MAD_ACC          R8, R7, R14   # 0x2114
        C_BRA            L203e   # 0x2116
L2118:  MOVI             R11, 0   # 0x2118
        MOVI             R5, 10   # 0x211c
        MOVI             R6, 0   # 0x2120
        MOVI             R8, 0   # 0x2124
        MOVI             R1, 0   # 0x2128
        ST_LOCAL         R1, 36   # 0x212c
        MOVI             R13, 0   # 0x2130
        MOVI             R12, 0   # 0x2134
        C_BRA            L2146   # 0x2138
L213a:  C_ADD            R6, R2   # 0x213a
        C_ADDI           R8, 1   # 0x213c
        SETP_NE_NP       P0, R3, R8, R2   # 0x213e
        BRA_PRED         4, L222c   # 0x2142
L2146:  ST_LOCAL         R8, 40   # 0x2146
        LD_LOCAL         R3, 20   # 0x214a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x214e
        BRA_PRED         0, L21ce   # 0x2152
        MOVI             R9, 0   # 0x2156
        C_MOV            R3, R13   # 0x215a
        LD_LOCAL         R8, 32   # 0x215c
        LD_LOCAL         R1, 36   # 0x2160
L2164:  ADD              R7, R6, R9, R6   # 0x2164
        C_SHLI           R7, 2   # 0x2168
        C_ADD            R7, R14   # 0x216a
        LD_GLOBAL_IDX    R14, R15, R7, 0, 0   # 0x216c
        C_ADDI           R7, 4   # 0x2170
        LD_GLOBAL_IDX    R13, R15, R7, 0, 0   # 0x2172
        SETP_LT_NP       P0, R7, R14, R13   # 0x2176
        MOVI             R7, 0   # 0x217a
        ADDI_P           R7, 0, R7, 1   # 0x217e
        ADD              R15, R14, R12, R14   # 0x2182
        SETP_LT_NP       P0, R11, R8, R15   # 0x2186
        MOVI             R11, 0   # 0x218a
        MOV_P            R15, 0, R11, R11, R11   # 0x218e
        ADD              R12, R13, R15, R13   # 0x2192
        SETP_LT_NP       P1, R15, R8, R12   # 0x2196
        LD_LOCAL         R15, 12   # 0x219a
        MOV_P            R12, 1, R11, R11, R11   # 0x219e
        MOV_P            R7, 1, R5, R5, R5   # 0x21a2
        SETP_LT_NP       P1, R3, R3, R14   # 0x21a6
        LD_LOCAL         R14, 16   # 0x21aa
        MOVI             R3, 0   # 0x21ae
        ADDI_P           R3, 1, R3, 1   # 0x21b2
        MOV_P            R3, 0, R5, R5, R5   # 0x21b6
        C_ADD            R3, R1   # 0x21ba
        ADD              R1, R7, R3, R7   # 0x21bc
        C_ADDI           R9, 2   # 0x21c0
        SETP_NE_NP       P0, R3, R10, R9   # 0x21c2
        C_MOV            R3, R13   # 0x21c6
        BRA_PRED         0, L2164   # 0x21c8
        C_BRA            L21d6   # 0x21cc
L21ce:  MOVI             R9, 0   # 0x21ce
        LD_LOCAL         R1, 36   # 0x21d2
L21d6:  ST_LOCAL         R1, 36   # 0x21d6
        LD_LOCAL         R3, 24   # 0x21da
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x21de
        LD_LOCAL         R8, 40   # 0x21e2
        BRA_PRED         0, L213a   # 0x21e6
        MUL_LO           R3, R8, R2, R2   # 0x21ea
        ADD              R3, R9, R3, R9   # 0x21ee
        C_SHLI           R3, 2   # 0x21f2
        ADD              R3, R14, R3, R14   # 0x21f4
        LD_GLOBAL_IDX    R3, R15, R3, 0, 0   # 0x21f8
        ADD              R12, R3, R12, R3   # 0x21fc
        LD_LOCAL         R7, 32   # 0x2200
        SETP_LT_NP       P0, R7, R7, R12   # 0x2204
        MOV_P            R12, 0, R11, R11, R11   # 0x2208
        SETP_LT_NP       P1, R7, R13, R3   # 0x220c
        MOVI             R7, 0   # 0x2210
        ADDI_P           R7, 1, R7, 1   # 0x2214
        MOV_P            R7, 0, R5, R5, R5   # 0x2218
        LD_LOCAL         R1, 36   # 0x221c
        ADD              R1, R7, R1, R7   # 0x2220
        ST_LOCAL         R1, 36   # 0x2224
        C_MOV            R13, R3   # 0x2228
        C_BRA            L213a   # 0x222a
L222c:  SETP_EQ_NPI      P0, R1, R2, 0   # 0x222c
        LD_LOCAL         R8, 44   # 0x2230
        LD_LOCAL         R9, 48   # 0x2234
        LD_LOCAL         R10, 36   # 0x2238
        BRA_PRED         0, L22de   # 0x223c
        MOVI             R1, 0   # 0x2240
        ANDI             R5, R2, 3   # 0x2244
        MOVI             R3, 0   # 0x2248
        C_BRA            L225a   # 0x224c
L224e:  C_ADD            R1, R2   # 0x224e
        C_ADDI           R3, 1   # 0x2250
        SETP_NE_NP       P0, R6, R3, R2   # 0x2252
        BRA_PRED         4, L22de   # 0x2256
L225a:  LD_LOCAL         R6, 20   # 0x225a
        SETP_LT_U_NPI    P0, R6, R6, 3   # 0x225e
        MOVI             R6, 0   # 0x2262
        BRA_PRED         0, L22b0   # 0x2266
L226a:  ADD              R7, R1, R6, R1   # 0x226a
        C_SHLI           R7, 1   # 0x226e
        ADD              R7, R4, R7, R4   # 0x2270
        SZ_GLOBAL_LD_U16 R14, R0, R7, 0, 0   # 0x2274
        C_SUB            R14, R8   # 0x2278
        SZ_GLOBAL_ST_16  R14, R0, R7, 0, 0   # 0x227a
        ADDI             R14, R7, 2   # 0x227e
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x2282
        C_SUB            R15, R8   # 0x2286
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x2288
        ADDI             R14, R7, 4   # 0x228c
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x2290
        C_SUB            R15, R8   # 0x2294
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x2296
        C_ADDI           R7, 6   # 0x229a
        SZ_GLOBAL_LD_U16 R14, R0, R7, 0, 0   # 0x229c
        C_SUB            R14, R8   # 0x22a0
        SZ_GLOBAL_ST_16  R14, R0, R7, 0, 0   # 0x22a2
        C_ADDI           R6, 4   # 0x22a6
        SETP_NE_NP       P0, R7, R9, R6   # 0x22a8
        BRA_PRED         0, L226a   # 0x22ac
L22b0:  SETP_EQ_NPI      P0, R7, R5, 0   # 0x22b0
        BRA_PRED         0, L224e   # 0x22b4
        C_ADD            R6, R1   # 0x22b8
        C_MOV            R14, R5   # 0x22ba
L22bc:  C_MOV            R7, R6   # 0x22bc
        C_SHLI           R7, 1   # 0x22be
        ADD              R7, R4, R7, R4   # 0x22c0
        SZ_GLOBAL_LD_U16 R15, R0, R7, 0, 0   # 0x22c4
        C_SUB            R15, R8   # 0x22c8
        SZ_GLOBAL_ST_16  R15, R0, R7, 0, 0   # 0x22ca
        C_ADDI           R6, 1   # 0x22ce
        ADDI             R14, R14, -1   # 0x22d0
        SETP_NE_NPI      P0, R7, R14, 0   # 0x22d4
        BRA_PRED         0, L22bc   # 0x22d8
        C_BRA            L224e   # 0x22dc
L22de:  LD_LOCAL         R0, 64   # 0x22de
        SHLI             R0, R0, 16   # 0x22e2
        SRAI             R1, R0, 16   # 0x22e6
        MOVI             R2, 0   # 0x22ea
        CALL             R14, 129558   # 0x22ee
        C_MOV            R2, R1   # 0x22f2
        LD_LOCAL         R0, 60   # 0x22f4
        SHLI             R0, R0, 16   # 0x22f8
        SRAI             R1, R0, 16   # 0x22fc
        CALL             R14, 129549   # 0x2300
        C_MOV            R2, R1   # 0x2304
        LD_LOCAL         R0, 28   # 0x2306
        SHLI             R0, R0, 16   # 0x230a
        SRAI             R1, R0, 16   # 0x230e
        CALL             R14, 129540   # 0x2312
        C_MOV            R2, R1   # 0x2316
        SHLI             R0, R10, 16   # 0x2318
        SRAI             R1, R0, 16   # 0x231c
        CALL             R14, 129533   # 0x2320
        MOVI             R0, 65535   # 0x2324
        LD_LOCAL         R2, 56   # 0x2328
        C_AND            R2, R0   # 0x232c
        SHLI             R0, R1, 16   # 0x232e
        SRAI             R1, R0, 16   # 0x2332
        CALL             R14, 129522   # 0x2336
        LD_LOCAL         R14, 52   # 0x233a
        LD_LOCAL         R13, 88   # 0x233e
        LD_LOCAL         R12, 84   # 0x2342
        LD_LOCAL         R11, 80   # 0x2346
        LD_LOCAL         R10, 76   # 0x234a
        LD_LOCAL         R9, 72   # 0x234e
        LD_LOCAL         R8, 68   # 0x2352
        C_RET            224   # 0x2356
        XOR              R0, R2, R1, R2   # 0x2358
        C_ANDI           R0, 1   # 0x235c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x235e
        C_SHRI           R2, 1   # 0x2362
        MOVI48           R0, 4294942721   # 0x2364
        XOR              R3, R2, R0, R2   # 0x236a
        MOV_P            R2, 0, R3, R3, R3   # 0x236e
        C_MOV            R3, R1   # 0x2372
        C_SHRI           R3, 1   # 0x2374
        C_XOR            R3, R2   # 0x2376
        C_ANDI           R3, 1   # 0x2378
        SETP_NE_NPI      P0, R3, R3, 0   # 0x237a
        C_SHRI           R2, 1   # 0x237e
        MOVI             R3, 32767   # 0x2380
        C_AND            R2, R3   # 0x2384
        XOR              R4, R2, R0, R2   # 0x2386
        MOV_P            R2, 0, R4, R4, R4   # 0x238a
        C_MOV            R4, R1   # 0x238e
        C_SHRI           R4, 2   # 0x2390
        C_XOR            R4, R2   # 0x2392
        C_ANDI           R4, 1   # 0x2394
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2396
        C_SHRI           R2, 1   # 0x239a
        C_AND            R2, R3   # 0x239c
        XOR              R4, R2, R0, R2   # 0x239e
        MOV_P            R2, 0, R4, R4, R4   # 0x23a2
        C_MOV            R4, R1   # 0x23a6
        C_SHRI           R4, 3   # 0x23a8
        C_XOR            R4, R2   # 0x23aa
        C_ANDI           R4, 1   # 0x23ac
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23ae
        C_SHRI           R2, 1   # 0x23b2
        C_AND            R2, R3   # 0x23b4
        XOR              R4, R2, R0, R2   # 0x23b6
        MOV_P            R2, 0, R4, R4, R4   # 0x23ba
        C_MOV            R4, R1   # 0x23be
        C_SHRI           R4, 4   # 0x23c0
        C_XOR            R4, R2   # 0x23c2
        C_ANDI           R4, 1   # 0x23c4
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23c6
        C_SHRI           R2, 1   # 0x23ca
        C_AND            R2, R3   # 0x23cc
        XOR              R4, R2, R0, R2   # 0x23ce
        MOV_P            R2, 0, R4, R4, R4   # 0x23d2
        C_MOV            R4, R1   # 0x23d6
        C_SHRI           R4, 5   # 0x23d8
        C_XOR            R4, R2   # 0x23da
        C_ANDI           R4, 1   # 0x23dc
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23de
        C_SHRI           R2, 1   # 0x23e2
        C_AND            R2, R3   # 0x23e4
        XOR              R4, R2, R0, R2   # 0x23e6
        MOV_P            R2, 0, R4, R4, R4   # 0x23ea
        C_MOV            R4, R1   # 0x23ee
        C_SHRI           R4, 6   # 0x23f0
        C_XOR            R4, R2   # 0x23f2
        C_ANDI           R4, 1   # 0x23f4
        SETP_NE_NPI      P0, R4, R4, 0   # 0x23f6
        C_SHRI           R2, 1   # 0x23fa
        C_AND            R2, R3   # 0x23fc
        XOR              R4, R2, R0, R2   # 0x23fe
        MOV_P            R2, 0, R4, R4, R4   # 0x2402
        ANDI             R4, R1, 128   # 0x2406
        C_SHRI           R4, 7   # 0x240a
        ANDI             R5, R2, 1   # 0x240c
        SETP_EQ_NP       P0, R4, R4, R5   # 0x2410
        C_SHRI           R2, 1   # 0x2414
        C_AND            R2, R3   # 0x2416
        XOR              R4, R2, R0, R2   # 0x2418
        MOV_P            R4, 0, R2, R2, R2   # 0x241c
        C_MOV            R2, R1   # 0x2420
        C_SHRI           R2, 8   # 0x2422
        XOR              R2, R4, R2, R4   # 0x2424
        C_ANDI           R2, 1   # 0x2428
        SETP_NE_NPI      P0, R2, R2, 0   # 0x242a
        C_SHRI           R4, 1   # 0x242e
        AND              R2, R4, R3, R4   # 0x2430
        XOR              R4, R2, R0, R2   # 0x2434
        MOV_P            R2, 0, R4, R4, R4   # 0x2438
        C_MOV            R4, R1   # 0x243c
        C_SHRI           R4, 9   # 0x243e
        C_XOR            R4, R2   # 0x2440
        C_ANDI           R4, 1   # 0x2442
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2444
        C_SHRI           R2, 1   # 0x2448
        C_AND            R2, R3   # 0x244a
        XOR              R4, R2, R0, R2   # 0x244c
        MOV_P            R2, 0, R4, R4, R4   # 0x2450
        C_MOV            R4, R1   # 0x2454
        C_SHRI           R4, 10   # 0x2456
        C_XOR            R4, R2   # 0x2458
        C_ANDI           R4, 1   # 0x245a
        SETP_NE_NPI      P0, R4, R4, 0   # 0x245c
        C_SHRI           R2, 1   # 0x2460
        C_AND            R2, R3   # 0x2462
        XOR              R4, R2, R0, R2   # 0x2464
        MOV_P            R2, 0, R4, R4, R4   # 0x2468
        C_MOV            R4, R1   # 0x246c
        C_SHRI           R4, 11   # 0x246e
        C_XOR            R4, R2   # 0x2470
        C_ANDI           R4, 1   # 0x2472
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2474
        C_SHRI           R2, 1   # 0x2478
        C_AND            R2, R3   # 0x247a
        XOR              R4, R2, R0, R2   # 0x247c
        MOV_P            R2, 0, R4, R4, R4   # 0x2480
        C_MOV            R4, R1   # 0x2484
        C_SHRI           R4, 12   # 0x2486
        C_XOR            R4, R2   # 0x2488
        C_ANDI           R4, 1   # 0x248a
        SETP_NE_NPI      P0, R4, R4, 0   # 0x248c
        C_SHRI           R2, 1   # 0x2490
        C_AND            R2, R3   # 0x2492
        XOR              R4, R2, R0, R2   # 0x2494
        MOV_P            R2, 0, R4, R4, R4   # 0x2498
        C_MOV            R4, R1   # 0x249c
        C_SHRI           R4, 13   # 0x249e
        C_XOR            R4, R2   # 0x24a0
        C_ANDI           R4, 1   # 0x24a2
        SETP_NE_NPI      P0, R4, R4, 0   # 0x24a4
        C_SHRI           R2, 1   # 0x24a8
        C_AND            R2, R3   # 0x24aa
        XOR              R4, R2, R0, R2   # 0x24ac
        MOV_P            R2, 0, R4, R4, R4   # 0x24b0
        C_MOV            R4, R1   # 0x24b4
        C_SHRI           R4, 14   # 0x24b6
        C_XOR            R4, R2   # 0x24b8
        C_SHRI           R2, 1   # 0x24ba
        C_AND            R2, R3   # 0x24bc
        XOR              R0, R2, R0, R2   # 0x24be
        C_ANDI           R4, 1   # 0x24c2
        SETP_NE_NPI      P0, R4, R4, 0   # 0x24c4
        MOV_P            R2, 0, R0, R0, R0   # 0x24c8
        C_SHRI           R1, 15   # 0x24cc
        ANDI             R0, R2, 1   # 0x24ce
        SETP_EQ_NP       P0, R0, R1, R0   # 0x24d2
        C_SHRI           R2, 1   # 0x24d6
        AND              R0, R2, R3, R2   # 0x24d8
        MOVI             R1, 40961   # 0x24dc
        XOR              R1, R0, R1, R0   # 0x24e0
        MOV_P            R1, 0, R0, R0, R0   # 0x24e4
        C_RET            224   # 0x24e8
        MOVI             R15, 2   # 0x24ea
        LD_GLOBAL        R15, R15, 24   # 0x24ee
        SRD              R0, 2   # 0x24f2
        C_ADD            R15, R0   # 0x24f4
        ST_LOCAL         R8, 172   # 0x24f6
        ST_LOCAL         R9, 176   # 0x24fa
        ST_LOCAL         R10, 180   # 0x24fe
        ST_LOCAL         R11, 184   # 0x2502
        ST_LOCAL         R12, 188   # 0x2506
        ST_LOCAL         R13, 192   # 0x250a
        ST_LOCAL         R14, 164   # 0x250e
        C_MOV            R14, R3   # 0x2512
        ST_LOCAL         R2, 112   # 0x2514
        ST_LOCAL         R1, 116   # 0x2518
        LD_GLOBAL_IDX    R0, R1, R2, 0, 60   # 0x251c
        SHLI             R0, R0, 16   # 0x2520
        LD_GLOBAL_IDX    R4, R1, R2, 0, 56   # 0x2524
        SHRI             R3, R4, 16   # 0x2528
        OR               R12, R0, R3, R0   # 0x252c
        MOVI             R0, 65535   # 0x2530
        AND              R6, R4, R0, R4   # 0x2534
        SZ_GLOBAL_LD_S16 R1, R1, R2, 0, 4   # 0x2538
        SETP_LT_NPI      P0, R2, R1, 1   # 0x253c
        BRA_PRED         0, L281e   # 0x2540
        MOVI             R4, 0   # 0x2544
        ADDI             R2, R1, 255   # 0x2548
        ST_LOCAL         R2, 100   # 0x254c
        MOVI             R5, 0   # 0x2550
        MOVI             R7, 0   # 0x2554
        MOVI             R2, 0   # 0x2558
        ST_LOCAL         R2, 92   # 0x255c
        ST_LOCAL         R14, 96   # 0x2560
        C_MOV            R3, R14   # 0x2564
        C_BRA            L25cc   # 0x2566
L2568:  C_MOV            R12, R14   # 0x2568
        C_MOV            R6, R8   # 0x256a
        LD_GLOBAL_IDX    R2, R12, R6, 0, 0   # 0x256c
        LD_GLOBAL_IDX    R6, R12, R6, 0, 4   # 0x2570
        SHLI             R6, R6, 16   # 0x2574
        SHRI             R9, R2, 16   # 0x2578
        C_OR             R6, R9   # 0x257c
        C_AND            R2, R0   # 0x257e
        LD_GLOBAL_IDX    R9, R6, R2, 0, 8   # 0x2580
        LD_GLOBAL_IDX    R2, R6, R2, 0, 12   # 0x2584
        SHLI             R2, R2, 16   # 0x2588
        SHRI             R6, R9, 16   # 0x258c
        C_OR             R2, R6   # 0x2590
        AND              R6, R9, R0, R9   # 0x2592
        SZ_GLOBAL_LD_U16 R2, R2, R6, 0, 0   # 0x2596
        LD_LOCAL         R6, 92   # 0x259a
        C_ADDI           R6, 1   # 0x259e
        ST_LOCAL         R6, 92   # 0x25a0
        C_SHRI           R2, 8   # 0x25a4
        ANDI             R11, R2, 1   # 0x25a6
L25aa:  AND              R2, R1, R0, R1   # 0x25aa
        C_ADDI           R4, 1   # 0x25ae
        AND              R6, R4, R0, R4   # 0x25b0
        SETP_NE_NP       P0, R2, R6, R2   # 0x25b4
        ADD              R5, R11, R5, R11   # 0x25b8
        MOVI             R2, 32768   # 0x25bc
        C_ANDN           R2, R3   # 0x25c0
        C_SHRI           R2, 15   # 0x25c2
        C_ADD            R3, R2   # 0x25c4
        C_MOV            R6, R8   # 0x25c6
        BRA_PRED         4, L2804   # 0x25c8
L25cc:  SHLI             R2, R12, 16   # 0x25cc
        AND              R9, R2, R6, R2   # 0x25d0
        ADD              R10, R2, R6, R2   # 0x25d4
        C_OR             R2, R6   # 0x25d8
        C_ANDN           R2, R10   # 0x25da
        OR               R2, R9, R2, R9   # 0x25dc
        SHRI             R2, R2, 31   # 0x25e0
        SHRI             R9, R12, 16   # 0x25e4
        ADD              R2, R9, R2, R9   # 0x25e8
        OR               R11, R10, R2, R10   # 0x25ec
        SHLI             R2, R3, 16   # 0x25f0
        SRAI             R2, R2, 16   # 0x25f4
        MOVI48           R14, 4294967295   # 0x25f8
        SETP_LT_NP       P0, R2, R14, R2   # 0x25fe
        BRA_PRED         4, L2666   # 0x2602
        MOVI             R9, 0   # 0x2606
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x260a
        BRA_PRED         0, L2736   # 0x260e
        C_MOV            R14, R12   # 0x2612
        C_MOV            R8, R6   # 0x2614
        C_MOV            R10, R6   # 0x2616
L2618:  LD_GLOBAL_IDX    R2, R12, R10, 0, 8   # 0x2618
        LD_GLOBAL_IDX    R13, R12, R10, 0, 12   # 0x261c
        SHLI             R13, R13, 16   # 0x2620
        SHRI             R6, R2, 16   # 0x2624
        OR               R6, R13, R6, R13   # 0x2628
        C_MOV            R13, R3   # 0x262c
        C_AND            R2, R0   # 0x262e
        SZ_GLOBAL_LD_U16 R2, R6, R2, 0, 2   # 0x2630
        AND              R6, R13, R0, R13   # 0x2634
        SETP_EQ_NP       P0, R2, R2, R6   # 0x2638
        BRA_PRED         0, L26c8   # 0x263c
        LD_GLOBAL_IDX    R2, R12, R10, 0, 4   # 0x2640
        LD_GLOBAL_IDX    R6, R12, R10, 0, 0   # 0x2644
        SHRI             R10, R6, 16   # 0x2648
        SHLI             R12, R2, 16   # 0x264c
        C_OR             R12, R10   # 0x2650
        C_AND            R2, R0   # 0x2652
        OR               R2, R6, R2, R6   # 0x2654
        AND              R10, R6, R0, R6   # 0x2658
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x265c
        BRA_PRED         4, L2618   # 0x2660
        C_BRA            L26c2   # 0x2664
L2666:  MOVI             R9, 0   # 0x2666
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x266a
        C_MOV            R14, R12   # 0x266e
        C_MOV            R8, R6   # 0x2670
        C_MOV            R10, R6   # 0x2672
        BRA_PRED         0, L26c2   # 0x2674
L2678:  LD_GLOBAL_IDX    R2, R12, R10, 0, 8   # 0x2678
        LD_GLOBAL_IDX    R6, R12, R10, 0, 12   # 0x267c
        SHLI             R6, R6, 16   # 0x2680
        SHRI             R13, R2, 16   # 0x2684
        C_OR             R6, R13   # 0x2688
        C_AND            R2, R0   # 0x268a
        SZ_GLOBAL_LD_U16 R2, R6, R2, 0, 0   # 0x268c
        C_XOR            R2, R4   # 0x2690
        ANDI             R2, R2, 255   # 0x2692
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x2696
        BRA_PRED         0, L26c8   # 0x269a
        LD_GLOBAL_IDX    R2, R12, R10, 0, 4   # 0x269e
        LD_GLOBAL_IDX    R6, R12, R10, 0, 0   # 0x26a2
        SHRI             R10, R6, 16   # 0x26a6
        SHLI             R12, R2, 16   # 0x26aa
        C_OR             R12, R10   # 0x26ae
        C_AND            R2, R0   # 0x26b0
        OR               R2, R6, R2, R6   # 0x26b2
        AND              R10, R6, R0, R6   # 0x26b6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x26ba
        BRA_PRED         0, L2678   # 0x26be
L26c2:  MOVI             R10, 0   # 0x26c2
        C_BRA            L26ca   # 0x26c6
L26c8:  C_MOV            R9, R12   # 0x26c8
L26ca:  C_MOV            R12, R14   # 0x26ca
        C_MOV            R6, R8   # 0x26cc
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x26ce
        BRA_PRED         0, L2742   # 0x26d2
L26d6:  MOVI             R14, 0   # 0x26d6
        MOVI             R2, 0   # 0x26da
L26de:  C_MOV            R13, R6   # 0x26de
        C_MOV            R11, R12   # 0x26e0
        SHLI             R6, R14, 16   # 0x26e2
        AND              R12, R6, R2, R6   # 0x26e6
        ADD              R8, R6, R2, R6   # 0x26ea
        OR               R2, R6, R2, R6   # 0x26ee
        C_ANDN           R2, R8   # 0x26f2
        OR               R2, R12, R2, R12   # 0x26f4
        SHRI             R2, R2, 31   # 0x26f8
        SHRI             R6, R14, 16   # 0x26fc
        ADD              R2, R6, R2, R6   # 0x2700
        LD_GLOBAL_IDX    R6, R11, R13, 0, 0   # 0x2704
        ST_GLOBAL_IDX    R8, R11, R13, 0, 0   # 0x2708
        LD_GLOBAL_IDX    R14, R11, R13, 0, 4   # 0x270c
        ST_GLOBAL_IDX    R2, R11, R13, 0, 4   # 0x2710
        SHRI             R2, R6, 16   # 0x2714
        SHLI             R12, R14, 16   # 0x2718
        C_OR             R12, R2   # 0x271c
        AND              R2, R14, R0, R14   # 0x271e
        OR               R2, R6, R2, R6   # 0x2722
        C_AND            R6, R0   # 0x2726
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2728
        C_MOV            R14, R11   # 0x272c
        C_MOV            R2, R13   # 0x272e
        BRA_PRED         0, L26de   # 0x2730
        C_BRA            L274a   # 0x2734
L2736:  MOVI             R10, 0   # 0x2736
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x273a
        BRA_PRED         4, L26d6   # 0x273e
L2742:  MOVI             R11, 0   # 0x2742
        MOVI             R13, 0   # 0x2746
L274a:  C_MOV            R8, R13   # 0x274a
        C_MOV            R14, R11   # 0x274c
        SHLI             R2, R9, 16   # 0x274e
        AND              R6, R2, R10, R2   # 0x2752
        ADD              R11, R2, R10, R2   # 0x2756
        C_OR             R2, R10   # 0x275a
        C_ANDN           R2, R11   # 0x275c
        OR               R2, R6, R2, R6   # 0x275e
        SHRI             R2, R2, 31   # 0x2762
        SHRI             R6, R9, 16   # 0x2766
        ADD              R2, R6, R2, R6   # 0x276a
        OR               R2, R11, R2, R11   # 0x276e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2772
        BRA_PRED         4, L2568   # 0x2776
        LD_GLOBAL_IDX    R2, R9, R10, 0, 12   # 0x277a
        SHLI             R2, R2, 16   # 0x277e
        LD_GLOBAL_IDX    R6, R9, R10, 0, 8   # 0x2782
        SHRI             R11, R6, 16   # 0x2786
        C_OR             R2, R11   # 0x278a
        C_AND            R6, R0   # 0x278c
        SZ_GLOBAL_LD_U16 R6, R2, R6, 0, 0   # 0x278e
        LD_GLOBAL_IDX    R2, R9, R10, 0, 4   # 0x2792
        LD_GLOBAL_IDX    R12, R9, R10, 0, 0   # 0x2796
        C_MOV            R11, R6   # 0x279a
        C_SHRI           R11, 9   # 0x279c
        C_AND            R6, R11   # 0x279e
        AND              R11, R2, R0, R2   # 0x27a0
        OR               R13, R12, R11, R12   # 0x27a4
        C_ADDI           R7, 1   # 0x27a8
        ANDI             R11, R6, 1   # 0x27aa
        SETP_EQ_NPI      P0, R6, R13, 0   # 0x27ae
        BRA_PRED         0, L27fe   # 0x27b2
        SHRI             R6, R12, 16   # 0x27b6
        SHLI             R2, R2, 16   # 0x27ba
        C_OR             R2, R6   # 0x27be
        AND              R6, R12, R0, R12   # 0x27c0
        LD_GLOBAL_IDX    R12, R2, R6, 0, 0   # 0x27c4
        SZ_GLOBAL_LD_U16 R13, R2, R6, 0, 4   # 0x27c8
        ST_GLOBAL_IDX    R13, R9, R10, 0, 4   # 0x27cc
        ST_GLOBAL_IDX    R12, R9, R10, 0, 0   # 0x27d0
        C_MOV            R12, R14   # 0x27d4
        C_MOV            R14, R8   # 0x27d6
        LD_GLOBAL_IDX    R9, R12, R14, 0, 0   # 0x27d8
        SZ_GLOBAL_LD_U16 R10, R12, R14, 0, 4   # 0x27dc
        ST_GLOBAL_IDX    R10, R2, R6, 0, 4   # 0x27e0
        ST_GLOBAL_IDX    R9, R2, R6, 0, 0   # 0x27e4
        SHRI             R9, R2, 16   # 0x27e8
        ST_GLOBAL_IDX    R9, R12, R14, 0, 4   # 0x27ec
        SHLI             R2, R2, 16   # 0x27f0
        C_OR             R2, R6   # 0x27f4
        ST_GLOBAL_IDX    R2, R12, R14, 0, 0   # 0x27f6
        BRA              L25aa   # 0x27fa
L27fe:  C_MOV            R12, R14   # 0x27fe
        BRA              L25aa   # 0x2800
L2804:  C_SHLI           R7, 2   # 0x2804
        LD_LOCAL         R0, 92   # 0x2806
        SUB              R0, R7, R0, R7   # 0x280a
        C_ADD            R0, R5   # 0x280e
        LD_LOCAL         R1, 100   # 0x2810
        ANDI             R1, R1, 255   # 0x2814
        LD_LOCAL         R14, 96   # 0x2818
        C_BRA            L2828   # 0x281c
L281e:  MOVI             R1, 0   # 0x281e
        C_MOV            R3, R14   # 0x2822
        MOVI             R0, 0   # 0x2824
L2828:  ST_LOCAL         R1, 168   # 0x2828
        ST_LOCAL         R3, 160   # 0x282c
        ST_LOCAL         R0, 156   # 0x2830
        SHLI             R0, R14, 16   # 0x2834
        SRAI             R0, R0, 16   # 0x2838
        SETP_LT_NPI      P0, R0, R0, 1   # 0x283c
        BRA_PRED         0, L2d7c   # 0x2840
        MOVI             R4, 1   # 0x2844
        MOVI             R7, 65535   # 0x2848
        MOVI             R8, 0   # 0x284c
        C_BRA            L2874   # 0x2850
L2852:  ST_GLOBAL_IDX    R8, R11, R10, 0, 4   # 0x2852
        ST_GLOBAL_IDX    R8, R11, R10, 0, 0   # 0x2856
        C_SHLI           R4, 1   # 0x285a
        LD_LOCAL         R0, 152   # 0x285c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2860
        LD_LOCAL         R9, 136   # 0x2864
        C_MOV            R12, R9   # 0x2868
        LD_LOCAL         R13, 140   # 0x286a
        C_MOV            R6, R13   # 0x286e
        BRA_PRED         4, L2d80   # 0x2870
L2874:  MOVI             R5, 0   # 0x2874
        MOVI             R11, 0   # 0x2878
        MOVI             R10, 0   # 0x287c
        MOVI             R0, 0   # 0x2880
        ST_LOCAL         R0, 136   # 0x2884
        ST_LOCAL         R0, 140   # 0x2888
        LD_LOCAL         R0, 116   # 0x288c
        ST_LOCAL         R4, 144   # 0x2890
        C_BRA            L28a6   # 0x2894
L2896:  SETP_EQ_NPI      P0, R0, R0, 0   # 0x2896
        LD_LOCAL         R4, 144   # 0x289a
        LD_LOCAL         R5, 148   # 0x289e
        BRA_PRED         0, L2852   # 0x28a2
L28a6:  SETP_LT_NPI      P0, R0, R4, 1   # 0x28a6
        BRA_PRED         0, L28e8   # 0x28aa
        MOVI             R2, 0   # 0x28ae
        C_MOV            R0, R12   # 0x28b2
        C_MOV            R1, R6   # 0x28b4
L28b6:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x28b6
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x28ba
        AND              R0, R3, R7, R3   # 0x28be
        OR               R0, R1, R0, R1   # 0x28c2
        SETP_NE_NPI      P0, R0, R0, 0   # 0x28c6
        BRA_PRED         4, L28f2   # 0x28ca
        SHRI             R0, R1, 16   # 0x28ce
        SHLI             R3, R3, 16   # 0x28d2
        OR               R0, R3, R0, R3   # 0x28d6
        C_AND            R1, R7   # 0x28da
        C_ADDI           R2, 1   # 0x28dc
        SETP_EQ_NP       P0, R3, R4, R2   # 0x28de
        BRA_PRED         4, L28b6   # 0x28e2
        C_BRA            L28fe   # 0x28e6
L28e8:  MOVI             R4, 0   # 0x28e8
        C_MOV            R0, R12   # 0x28ec
        C_MOV            R1, R6   # 0x28ee
        C_BRA            L28fe   # 0x28f0
L28f2:  MOVI             R0, 0   # 0x28f2
        ADDI             R4, R2, 1   # 0x28f6
        MOVI             R1, 0   # 0x28fa
L28fe:  ST_LOCAL         R5, 152   # 0x28fe
        ADDI             R2, R5, 1   # 0x2902
        ST_LOCAL         R2, 148   # 0x2906
        C_MOV            R9, R12   # 0x290a
        C_MOV            R14, R6   # 0x290c
        C_MOV            R12, R0   # 0x290e
        C_MOV            R6, R1   # 0x2910
        LD_LOCAL         R0, 144   # 0x2912
        ST_LOCAL         R0, 96   # 0x2916
        C_BRA            L2938   # 0x291a
L291c:  ST_LOCAL         R4, 136   # 0x291c
        ST_LOCAL         R5, 140   # 0x2920
L2924:  C_MOV            R9, R1   # 0x2924
        C_MOV            R14, R3   # 0x2926
        C_MOV            R12, R0   # 0x2928
        C_MOV            R6, R2   # 0x292a
        C_MOV            R11, R4   # 0x292c
        C_MOV            R10, R5   # 0x292e
        MOVI             R7, 65535   # 0x2930
        LD_LOCAL         R4, 92   # 0x2934
L2938:  SETP_LT_NP       P0, R0, R8, R4   # 0x2938
        BRA_PRED         0, L2978   # 0x293c
        SHLI             R0, R12, 16   # 0x2940
        AND              R1, R0, R6, R0   # 0x2944
        ADD              R2, R0, R6, R0   # 0x2948
        C_OR             R0, R6   # 0x294c
        C_ANDN           R0, R2   # 0x294e
        OR               R0, R1, R0, R1   # 0x2950
        SHRI             R0, R0, 31   # 0x2954
        SHRI             R1, R12, 16   # 0x2958
        ADD              R0, R1, R0, R1   # 0x295c
        OR               R0, R2, R0, R2   # 0x2960
        LD_LOCAL         R1, 96   # 0x2964
        SETP_LT_NPI      P0, R1, R1, 1   # 0x2968
        BRA_PRED         0, L2896   # 0x296c
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x2970
        BRA_PRED         0, L2896   # 0x2974
L2978:  SETP_NE_NPI      P0, R0, R4, 0   # 0x2978
        BRA_PRED         4, L2a92   # 0x297c
        LD_LOCAL         R0, 96   # 0x2980
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2984
        BRA_PRED         0, L2ac8   # 0x2988
        SHLI             R0, R12, 16   # 0x298c
        AND              R1, R0, R6, R0   # 0x2990
        ADD              R2, R0, R6, R0   # 0x2994
        C_OR             R0, R6   # 0x2998
        C_ANDN           R0, R2   # 0x299a
        OR               R0, R1, R0, R1   # 0x299c
        SHRI             R0, R0, 31   # 0x29a0
        SHRI             R1, R12, 16   # 0x29a4
        ADD              R0, R1, R0, R1   # 0x29a8
        OR               R0, R2, R0, R2   # 0x29ac
        SETP_NE_NPI      P0, R0, R0, 0   # 0x29b0
        BRA_PRED         4, L2ac8   # 0x29b4
        LD_GLOBAL_IDX    R3, R12, R6, 0, 8   # 0x29b8
        ST_LOCAL         R12, 100   # 0x29bc
        LD_GLOBAL_IDX    R5, R12, R6, 0, 12   # 0x29c0
        LD_GLOBAL_IDX    R0, R9, R14, 0, 8   # 0x29c4
        LD_GLOBAL_IDX    R1, R9, R14, 0, 12   # 0x29c8
        SHLI             R1, R1, 16   # 0x29cc
        SHRI             R2, R0, 16   # 0x29d0
        OR               R13, R1, R2, R1   # 0x29d4
        AND              R1, R0, R7, R0   # 0x29d8
        SZ_GLOBAL_LD_U16 R12, R13, R1, 0, 0   # 0x29dc
        ANDI             R0, R12, 128   # 0x29e0
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x29e4
        ST_LOCAL         R4, 92   # 0x29e8
        ST_LOCAL         R6, 104   # 0x29ec
        ST_LOCAL         R14, 108   # 0x29f0
        BRA_PRED         4, L2af2   # 0x29f4
        ST_LOCAL         R1, 128   # 0x29f8
        ST_LOCAL         R13, 132   # 0x29fc
        ST_LOCAL         R5, 124   # 0x2a00
        ST_LOCAL         R3, 120   # 0x2a04
        C_MOV            R0, R12   # 0x2a08
        C_SHRI           R0, 3   # 0x2a0a
        C_ANDI           R0, 15   # 0x2a0c
        MULI             R3, R0, 17   # 0x2a0e
        ANDI             R0, R12, 7   # 0x2a12
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x2a16
        LD_LOCAL         R8, 116   # 0x2a1a
        BRA_PRED         0, L2afc   # 0x2a1e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2a22
        C_MOV            R6, R12   # 0x2a26
        BRA_PRED         0, L2b30   # 0x2a28
        MOVI             R0, 34   # 0x2a2c
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x2a30
        MOVI             R6, 34   # 0x2a34
        MOV_P            R6, 0, R3, R3, R3   # 0x2a38
        C_MOV            R13, R8   # 0x2a3c
        LD_LOCAL         R8, 112   # 0x2a3e
        SZ_GLOBAL_LD_U16 R5, R13, R8, 0, 2   # 0x2a42
        SZ_GLOBAL_LD_U16 R4, R13, R8, 0, 0   # 0x2a46
        LD_GLOBAL_IDX    R1, R13, R8, 0, 40   # 0x2a4a
        LD_GLOBAL_IDX    R0, R13, R8, 0, 32   # 0x2a4e
        LD_GLOBAL_IDX    R2, R13, R8, 0, 36   # 0x2a52
        SZ_GLOBAL_LD_U16 R3, R13, R8, 0, 96   # 0x2a56
        ST_GLOBAL        R3, R15, -4   # 0x2a5a
        SHLI             R2, R2, 16   # 0x2a5e
        SHRI             R3, R0, 16   # 0x2a62
        C_OR             R2, R3   # 0x2a66
        AND              R3, R0, R7, R0   # 0x2a68
        CALL             R14, 127648   # 0x2a6c
        MOVI             R15, 2   # 0x2a70
        LD_GLOBAL        R15, R15, 24   # 0x2a74
        SRD              R3, 2   # 0x2a78
        C_ADD            R15, R3   # 0x2a7a
        C_MOV            R6, R1   # 0x2a7c
        SZ_GLOBAL_LD_U16 R0, R13, R8, 0, 102   # 0x2a7e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2a82
        BRA_PRED         0, L2a8e   # 0x2a86
        SZ_GLOBAL_ST_16  R6, R13, R8, 0, 102   # 0x2a8a
L2a8e:  C_MOV            R8, R13   # 0x2a8e
        C_BRA            L2b2c   # 0x2a90
L2a92:  LD_GLOBAL_IDX    R1, R12, R6, 0, 0   # 0x2a92
        LD_GLOBAL_IDX    R0, R12, R6, 0, 4   # 0x2a96
        SHLI             R0, R0, 16   # 0x2a9a
        SHRI             R2, R1, 16   # 0x2a9e
        C_OR             R0, R2   # 0x2aa2
        AND              R2, R1, R7, R1   # 0x2aa4
        MOVI             R1, 0   # 0x2aa8
        ST_LOCAL         R1, 92   # 0x2aac
        LD_LOCAL         R1, 96   # 0x2ab0
        ADDI             R1, R1, -1   # 0x2ab4
        ST_LOCAL         R1, 96   # 0x2ab8
        C_MOV            R1, R9   # 0x2abc
        C_MOV            R3, R14   # 0x2abe
        C_MOV            R4, R12   # 0x2ac0
        C_MOV            R5, R6   # 0x2ac2
        BRA              L2d24   # 0x2ac4
L2ac8:  LD_GLOBAL_IDX    R0, R9, R14, 0, 0   # 0x2ac8
        LD_GLOBAL_IDX    R1, R9, R14, 0, 4   # 0x2acc
        SHLI             R1, R1, 16   # 0x2ad0
        SHRI             R2, R0, 16   # 0x2ad4
        C_OR             R1, R2   # 0x2ad8
        AND              R3, R0, R7, R0   # 0x2ada
        ADDI             R4, R4, -1   # 0x2ade
        ST_LOCAL         R4, 92   # 0x2ae2
        C_MOV            R0, R12   # 0x2ae6
        C_MOV            R2, R6   # 0x2ae8
        C_MOV            R4, R9   # 0x2aea
        C_MOV            R5, R14   # 0x2aec
        BRA              L2d24   # 0x2aee
L2af2:  ANDI             R2, R12, 127   # 0x2af2
        LD_LOCAL         R8, 116   # 0x2af6
        C_BRA            L2b82   # 0x2afa
L2afc:  LD_LOCAL         R13, 112   # 0x2afc
        SZ_GLOBAL_LD_U16 R4, R8, R13, 0, 96   # 0x2b00
        ADDI             R2, R13, 64   # 0x2b04
        C_MOV            R1, R8   # 0x2b08
        CALL             R14, 128724   # 0x2b0a
        MOVI             R15, 2   # 0x2b0e
        LD_GLOBAL        R15, R15, 24   # 0x2b12
        SRD              R3, 2   # 0x2b16
        C_ADD            R15, R3   # 0x2b18
        C_MOV            R6, R1   # 0x2b1a
        SZ_GLOBAL_LD_U16 R0, R8, R13, 0, 100   # 0x2b1c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2b20
        BRA_PRED         0, L2b2c   # 0x2b24
        SZ_GLOBAL_ST_16  R6, R8, R13, 0, 100   # 0x2b28
L2b2c:  MOVI             R7, 65535   # 0x2b2c
L2b30:  AND              R1, R6, R7, R6   # 0x2b30
        LD_LOCAL         R7, 112   # 0x2b34
        SZ_GLOBAL_LD_U16 R2, R8, R7, 0, 96   # 0x2b38
        CALL             R14, 130060   # 0x2b3c
        MOVI             R15, 2   # 0x2b40
        LD_GLOBAL        R15, R15, 24   # 0x2b44
        SRD              R3, 2   # 0x2b48
        C_ADD            R15, R3   # 0x2b4a
        SZ_GLOBAL_ST_16  R1, R8, R7, 0, 96   # 0x2b4c
        MOVI             R7, 65535   # 0x2b50
        MOVI             R0, 65280   # 0x2b54
        AND              R0, R12, R0, R12   # 0x2b58
        ANDI             R2, R6, 127   # 0x2b5c
        C_OR             R0, R2   # 0x2b60
        ORI              R0, R0, 128   # 0x2b62
        LD_LOCAL         R1, 128   # 0x2b66
        LD_LOCAL         R3, 132   # 0x2b6a
        SZ_GLOBAL_ST_16  R0, R3, R1, 0, 0   # 0x2b6e
        LD_LOCAL         R6, 104   # 0x2b72
        LD_LOCAL         R14, 108   # 0x2b76
        LD_LOCAL         R3, 120   # 0x2b7a
        LD_LOCAL         R5, 124   # 0x2b7e
L2b82:  SHLI             R0, R5, 16   # 0x2b82
        SHRI             R1, R3, 16   # 0x2b86
        OR               R13, R0, R1, R0   # 0x2b8a
        AND              R1, R3, R7, R3   # 0x2b8e
        SZ_GLOBAL_LD_U16 R12, R13, R1, 0, 0   # 0x2b92
        ANDI             R0, R12, 128   # 0x2b96
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2b9a
        BRA_PRED         4, L2c30   # 0x2b9e
        ST_LOCAL         R1, 128   # 0x2ba2
        ST_LOCAL         R2, 120   # 0x2ba6
        C_MOV            R0, R12   # 0x2baa
        C_SHRI           R0, 3   # 0x2bac
        C_ANDI           R0, 15   # 0x2bae
        MULI             R3, R0, 17   # 0x2bb0
        ANDI             R0, R12, 7   # 0x2bb4
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x2bb8
        ST_LOCAL         R13, 124   # 0x2bbc
        BRA_PRED         0, L2c3a   # 0x2bc0
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2bc4
        C_MOV            R6, R12   # 0x2bc8
        BRA_PRED         0, L2c72   # 0x2bca
        MOVI             R0, 34   # 0x2bce
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x2bd2
        MOVI             R6, 34   # 0x2bd6
        MOV_P            R6, 0, R3, R3, R3   # 0x2bda
        LD_LOCAL         R13, 112   # 0x2bde
        SZ_GLOBAL_LD_U16 R5, R8, R13, 0, 2   # 0x2be2
        SZ_GLOBAL_LD_U16 R4, R8, R13, 0, 0   # 0x2be6
        LD_GLOBAL_IDX    R1, R8, R13, 0, 40   # 0x2bea
        LD_GLOBAL_IDX    R0, R8, R13, 0, 32   # 0x2bee
        LD_GLOBAL_IDX    R2, R8, R13, 0, 36   # 0x2bf2
        SZ_GLOBAL_LD_U16 R3, R8, R13, 0, 96   # 0x2bf6
        ST_GLOBAL        R3, R15, -4   # 0x2bfa
        SHLI             R2, R2, 16   # 0x2bfe
        SHRI             R3, R0, 16   # 0x2c02
        C_OR             R2, R3   # 0x2c06
        AND              R3, R0, R7, R0   # 0x2c08
        CALL             R14, 127440   # 0x2c0c
        MOVI             R15, 2   # 0x2c10
        LD_GLOBAL        R15, R15, 24   # 0x2c14
        SRD              R3, 2   # 0x2c18
        C_ADD            R15, R3   # 0x2c1a
        C_MOV            R6, R1   # 0x2c1c
        SZ_GLOBAL_LD_U16 R0, R8, R13, 0, 102   # 0x2c1e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2c22
        BRA_PRED         0, L2c6e   # 0x2c26
        SZ_GLOBAL_ST_16  R6, R8, R13, 0, 102   # 0x2c2a
        C_BRA            L2c6e   # 0x2c2e
L2c30:  MOVI             R13, 65535   # 0x2c30
        ANDI             R0, R12, 127   # 0x2c34
        C_BRA            L2cc0   # 0x2c38
L2c3a:  LD_LOCAL         R0, 112   # 0x2c3a
        SZ_GLOBAL_LD_U16 R4, R8, R0, 0, 96   # 0x2c3e
        ADDI             R2, R0, 64   # 0x2c42
        C_MOV            R1, R8   # 0x2c46
        CALL             R14, 128565   # 0x2c48
        MOVI             R15, 2   # 0x2c4c
        LD_GLOBAL        R15, R15, 24   # 0x2c50
        SRD              R3, 2   # 0x2c54
        C_ADD            R15, R3   # 0x2c56
        C_MOV            R6, R1   # 0x2c58
        LD_LOCAL         R1, 112   # 0x2c5a
        SZ_GLOBAL_LD_U16 R0, R8, R1, 0, 100   # 0x2c5e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2c62
        BRA_PRED         0, L2c6e   # 0x2c66
        SZ_GLOBAL_ST_16  R6, R8, R1, 0, 100   # 0x2c6a
L2c6e:  MOVI             R7, 65535   # 0x2c6e
L2c72:  MOVI             R13, 65535   # 0x2c72
        AND              R1, R6, R7, R6   # 0x2c76
        LD_LOCAL         R7, 112   # 0x2c7a
        SZ_GLOBAL_LD_U16 R2, R8, R7, 0, 96   # 0x2c7e
        CALL             R14, 129897   # 0x2c82
        MOVI             R15, 2   # 0x2c86
        LD_GLOBAL        R15, R15, 24   # 0x2c8a
        SRD              R3, 2   # 0x2c8e
        C_ADD            R15, R3   # 0x2c90
        SZ_GLOBAL_ST_16  R1, R8, R7, 0, 96   # 0x2c92
        MOVI             R0, 65280   # 0x2c96
        AND              R1, R12, R0, R12   # 0x2c9a
        ANDI             R0, R6, 127   # 0x2c9e
        C_OR             R1, R0   # 0x2ca2
        ORI              R1, R1, 128   # 0x2ca4
        LD_LOCAL         R2, 124   # 0x2ca8
        LD_LOCAL         R3, 128   # 0x2cac
        SZ_GLOBAL_ST_16  R1, R2, R3, 0, 0   # 0x2cb0
        LD_LOCAL         R6, 104   # 0x2cb4
        LD_LOCAL         R14, 108   # 0x2cb8
        LD_LOCAL         R2, 120   # 0x2cbc
L2cc0:  SETP_LT_U_NP     P0, R0, R0, R2   # 0x2cc0
        LD_LOCAL         R4, 100   # 0x2cc4
        BRA_PRED         4, L2cf6   # 0x2cc8
        LD_GLOBAL_IDX    R1, R4, R6, 0, 0   # 0x2ccc
        LD_GLOBAL_IDX    R0, R4, R6, 0, 4   # 0x2cd0
        SHLI             R0, R0, 16   # 0x2cd4
        SHRI             R2, R1, 16   # 0x2cd8
        C_OR             R0, R2   # 0x2cdc
        AND              R2, R1, R13, R1   # 0x2cde
        LD_LOCAL         R1, 96   # 0x2ce2
        ADDI             R1, R1, -1   # 0x2ce6
        ST_LOCAL         R1, 96   # 0x2cea
        C_MOV            R1, R9   # 0x2cee
        C_MOV            R3, R14   # 0x2cf0
        C_MOV            R5, R6   # 0x2cf2
        C_BRA            L2d20   # 0x2cf4
L2cf6:  LD_GLOBAL_IDX    R0, R9, R14, 0, 0   # 0x2cf6
        LD_GLOBAL_IDX    R1, R9, R14, 0, 4   # 0x2cfa
        SHLI             R1, R1, 16   # 0x2cfe
        SHRI             R2, R0, 16   # 0x2d02
        C_OR             R1, R2   # 0x2d06
        AND              R3, R0, R13, R0   # 0x2d08
        LD_LOCAL         R0, 92   # 0x2d0c
        ADDI             R0, R0, -1   # 0x2d10
        ST_LOCAL         R0, 92   # 0x2d14
        C_MOV            R0, R4   # 0x2d18
        C_MOV            R2, R6   # 0x2d1a
        C_MOV            R4, R9   # 0x2d1c
        C_MOV            R5, R14   # 0x2d1e
L2d20:  MOVI             R8, 0   # 0x2d20
L2d24:  SHLI             R6, R11, 16   # 0x2d24
        AND              R7, R6, R10, R6   # 0x2d28
        ADD              R14, R6, R10, R6   # 0x2d2c
        C_OR             R6, R10   # 0x2d30
        C_ANDN           R6, R14   # 0x2d32
        OR               R6, R7, R6, R7   # 0x2d34
        SHRI             R6, R6, 31   # 0x2d38
        SHRI             R7, R11, 16   # 0x2d3c
        ADD              R6, R7, R6, R7   # 0x2d40
        OR               R6, R14, R6, R14   # 0x2d44
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x2d48
        BRA_PRED         0, L291c   # 0x2d4c
        SHLI             R6, R4, 16   # 0x2d50
        ADD              R7, R6, R5, R6   # 0x2d54
        ST_GLOBAL_IDX    R7, R11, R10, 0, 0   # 0x2d58
        OR               R14, R6, R5, R6   # 0x2d5c
        ANDN             R7, R14, R7, R14   # 0x2d60
        C_AND            R6, R5   # 0x2d64
        C_OR             R6, R7   # 0x2d66
        SHRI             R6, R6, 31   # 0x2d68
        SHRI             R7, R4, 16   # 0x2d6c
        ADD              R6, R7, R6, R7   # 0x2d70
        ST_GLOBAL_IDX    R6, R11, R10, 0, 4   # 0x2d74
        BRA              L2924   # 0x2d78
L2d7c:  C_MOV            R9, R12   # 0x2d7c
        C_MOV            R13, R6   # 0x2d7e
L2d80:  LD_GLOBAL_IDX    R1, R9, R13, 0, 0   # 0x2d80
        LD_GLOBAL_IDX    R0, R9, R13, 0, 4   # 0x2d84
        SHLI             R0, R0, 16   # 0x2d88
        SHRI             R2, R1, 16   # 0x2d8c
        OR               R3, R0, R2, R0   # 0x2d90
        MOVI             R0, 65535   # 0x2d94
        AND              R4, R1, R0, R1   # 0x2d98
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x2d9c
        SHLI             R1, R1, 16   # 0x2da0
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x2da4
        SHRI             R5, R2, 16   # 0x2da8
        OR               R7, R1, R5, R1   # 0x2dac
        AND              R8, R2, R0, R2   # 0x2db0
        LD_GLOBAL_IDX    R5, R7, R8, 0, 8   # 0x2db4
        SZ_GLOBAL_LD_U16 R1, R7, R8, 0, 12   # 0x2db8
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x2dbc
        ST_GLOBAL_IDX    R1, R3, R4, 0, 12   # 0x2dc0
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x2dc4
        ST_GLOBAL_IDX    R5, R3, R4, 0, 8   # 0x2dc8
        AND              R5, R2, R0, R2   # 0x2dcc
        ST_GLOBAL_IDX    R5, R7, R8, 0, 12   # 0x2dd0
        ST_GLOBAL_IDX    R1, R7, R8, 0, 8   # 0x2dd4
        LD_GLOBAL_IDX    R5, R7, R8, 0, 0   # 0x2dd8
        SZ_GLOBAL_LD_U16 R6, R7, R8, 0, 4   # 0x2ddc
        ST_GLOBAL_IDX    R6, R3, R4, 0, 4   # 0x2de0
        ST_GLOBAL_IDX    R5, R3, R4, 0, 0   # 0x2de4
        LD_LOCAL         R3, 160   # 0x2de8
        SHLI             R3, R3, 16   # 0x2dec
        SRAI             R3, R3, 16   # 0x2df0
        MOVI48           R4, 4294967295   # 0x2df4
        SETP_LT_NP       P0, R3, R4, R3   # 0x2dfa
        MOVI             R3, 0   # 0x2dfe
        ST_GLOBAL_IDX    R3, R7, R8, 0, 4   # 0x2e02
        ST_GLOBAL_IDX    R3, R7, R8, 0, 0   # 0x2e06
        ST_LOCAL         R9, 136   # 0x2e0a
        C_MOV            R14, R13   # 0x2e0e
        C_MOV            R10, R14   # 0x2e10
        BRA_PRED         4, L2e66   # 0x2e12
        LD_LOCAL         R11, 160   # 0x2e16
L2e1a:  LD_GLOBAL_IDX    R3, R9, R10, 0, 8   # 0x2e1a
        LD_GLOBAL_IDX    R4, R9, R10, 0, 12   # 0x2e1e
        SHLI             R4, R4, 16   # 0x2e22
        SHRI             R5, R3, 16   # 0x2e26
        C_OR             R4, R5   # 0x2e2a
        C_AND            R3, R0   # 0x2e2c
        SZ_GLOBAL_LD_U16 R3, R4, R3, 0, 2   # 0x2e2e
        AND              R4, R11, R0, R11   # 0x2e32
        SETP_EQ_NP       P0, R3, R3, R4   # 0x2e36
        BRA_PRED         0, L2eb8   # 0x2e3a
        LD_GLOBAL_IDX    R3, R9, R10, 0, 4   # 0x2e3e
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2e42
        SHRI             R5, R4, 16   # 0x2e46
        SHLI             R6, R3, 16   # 0x2e4a
        OR               R9, R6, R5, R6   # 0x2e4e
        C_AND            R3, R0   # 0x2e52
        OR               R3, R4, R3, R4   # 0x2e54
        AND              R10, R4, R0, R4   # 0x2e58
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2e5c
        BRA_PRED         4, L2e1a   # 0x2e60
        C_BRA            L2eb0   # 0x2e64
L2e66:  LD_LOCAL         R11, 168   # 0x2e66
L2e6a:  LD_GLOBAL_IDX    R3, R9, R10, 0, 8   # 0x2e6a
        LD_GLOBAL_IDX    R4, R9, R10, 0, 12   # 0x2e6e
        SHLI             R4, R4, 16   # 0x2e72
        SHRI             R5, R3, 16   # 0x2e76
        C_OR             R4, R5   # 0x2e7a
        C_AND            R3, R0   # 0x2e7c
        SZ_GLOBAL_LD_U8  R3, R4, R3, 0, 0   # 0x2e7e
        SETP_EQ_NP       P0, R3, R3, R11   # 0x2e82
        BRA_PRED         0, L2eb8   # 0x2e86
        LD_GLOBAL_IDX    R3, R9, R10, 0, 4   # 0x2e8a
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2e8e
        SHRI             R5, R4, 16   # 0x2e92
        SHLI             R6, R3, 16   # 0x2e96
        OR               R9, R6, R5, R6   # 0x2e9a
        C_AND            R3, R0   # 0x2e9e
        OR               R3, R4, R3, R4   # 0x2ea0
        AND              R10, R4, R0, R4   # 0x2ea4
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2ea8
        BRA_PRED         0, L2e6a   # 0x2eac
L2eb0:  MOVI             R9, 0   # 0x2eb0
        MOVI             R10, 0   # 0x2eb4
L2eb8:  SHLI             R2, R2, 16   # 0x2eb8
        SHRI             R3, R1, 16   # 0x2ebc
        SHLI             R4, R9, 16   # 0x2ec0
        AND              R5, R4, R10, R4   # 0x2ec4
        ADD              R6, R4, R10, R4   # 0x2ec8
        C_OR             R4, R10   # 0x2ecc
        C_ANDN           R4, R6   # 0x2ece
        OR               R4, R5, R4, R5   # 0x2ed0
        SHRI             R4, R4, 31   # 0x2ed4
        SHRI             R5, R9, 16   # 0x2ed8
        ADD              R4, R5, R4, R5   # 0x2edc
        OR               R4, R6, R4, R6   # 0x2ee0
        SETP_NE_NPI      P0, R4, R4, 0   # 0x2ee4
        BRA_PRED         0, L2f0c   # 0x2ee8
        LD_LOCAL         R5, 136   # 0x2eec
        LD_GLOBAL_IDX    R4, R5, R14, 0, 0   # 0x2ef0
        LD_GLOBAL_IDX    R5, R5, R14, 0, 4   # 0x2ef4
        SHLI             R5, R5, 16   # 0x2ef8
        SHRI             R6, R4, 16   # 0x2efc
        OR               R9, R5, R6, R5   # 0x2f00
        MOVI             R5, 65535   # 0x2f04
        AND              R10, R4, R5, R4   # 0x2f08
L2f0c:  OR               R11, R2, R3, R2   # 0x2f0c
        AND              R0, R1, R0, R1   # 0x2f10
        ST_LOCAL         R0, 92   # 0x2f14
        SHLI             R0, R9, 16   # 0x2f18
        AND              R1, R0, R10, R0   # 0x2f1c
        ADD              R2, R0, R10, R0   # 0x2f20
        C_OR             R0, R10   # 0x2f24
        C_ANDN           R0, R2   # 0x2f26
        OR               R0, R1, R0, R1   # 0x2f28
        SHRI             R0, R0, 31   # 0x2f2c
        SHRI             R1, R9, 16   # 0x2f30
        ADD              R0, R1, R0, R1   # 0x2f34
        OR               R0, R2, R0, R2   # 0x2f38
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2f3c
        BRA_PRED         0, L2fa8   # 0x2f40
        LD_LOCAL         R1, 136   # 0x2f44
        LD_GLOBAL_IDX    R0, R1, R14, 0, 8   # 0x2f48
        C_MOV            R12, R14   # 0x2f4c
        LD_GLOBAL_IDX    R1, R1, R14, 0, 12   # 0x2f4e
        SHLI             R1, R1, 16   # 0x2f52
        SHRI             R2, R0, 16   # 0x2f56
        C_OR             R1, R2   # 0x2f5a
        MOVI             R13, 65535   # 0x2f5c
        C_AND            R0, R13   # 0x2f60
        SZ_GLOBAL_LD_S16 R6, R1, R0, 0, 0   # 0x2f62
        LD_LOCAL         R1, 156   # 0x2f66
L2f6a:  AND              R2, R1, R13, R1   # 0x2f6a
        C_MOV            R1, R6   # 0x2f6e
        CALL             R14, 127957   # 0x2f70
        MOVI             R15, 2   # 0x2f74
        LD_GLOBAL        R15, R15, 24   # 0x2f78
        SRD              R3, 2   # 0x2f7c
        C_ADD            R15, R3   # 0x2f7e
        LD_GLOBAL_IDX    R0, R9, R10, 0, 4   # 0x2f80
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2f84
        SHRI             R2, R4, 16   # 0x2f88
        SHLI             R3, R0, 16   # 0x2f8c
        OR               R9, R3, R2, R3   # 0x2f90
        C_AND            R0, R13   # 0x2f94
        OR               R0, R4, R0, R4   # 0x2f96
        AND              R10, R4, R13, R4   # 0x2f9a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2f9e
        BRA_PRED         0, L2f6a   # 0x2fa2
        C_BRA            L2fae   # 0x2fa6
L2fa8:  C_MOV            R12, R14   # 0x2fa8
        LD_LOCAL         R1, 156   # 0x2faa
L2fae:  ST_LOCAL         R1, 156   # 0x2fae
        LD_LOCAL         R5, 136   # 0x2fb2
        C_MOV            R13, R12   # 0x2fb6
        LD_GLOBAL_IDX    R1, R5, R13, 0, 0   # 0x2fb8
        LD_GLOBAL_IDX    R0, R5, R13, 0, 4   # 0x2fbc
        SHLI             R0, R0, 16   # 0x2fc0
        SHRI             R2, R1, 16   # 0x2fc4
        OR               R2, R0, R2, R0   # 0x2fc8
        MOVI             R0, 65535   # 0x2fcc
        C_AND            R1, R0   # 0x2fd0
        LD_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x2fd2
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 12   # 0x2fd6
        ST_GLOBAL_IDX    R4, R7, R8, 0, 12   # 0x2fda
        ST_GLOBAL_IDX    R3, R7, R8, 0, 8   # 0x2fde
        SHRI             R3, R11, 16   # 0x2fe2
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x2fe6
        SHLI             R3, R11, 16   # 0x2fea
        LD_LOCAL         R4, 92   # 0x2fee
        C_OR             R3, R4   # 0x2ff2
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x2ff4
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x2ff8
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 4   # 0x2ffc
        ST_GLOBAL_IDX    R4, R7, R8, 0, 4   # 0x3000
        ST_GLOBAL_IDX    R3, R7, R8, 0, 0   # 0x3004
        SHRI             R3, R7, 16   # 0x3008
        ST_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x300c
        SHLI             R3, R7, 16   # 0x3010
        C_OR             R3, R8   # 0x3014
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3016
        C_MOV            R1, R5   # 0x301a
        MOVI             R9, 1   # 0x301c
        MOVI             R3, 0   # 0x3020
        C_BRA            L3048   # 0x3024
L3026:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x3026
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x302a
        C_SHLI           R9, 1   # 0x302e
        LD_LOCAL         R1, 100   # 0x3030
        SETP_NE_NPI      P0, R1, R1, 0   # 0x3034
        LD_LOCAL         R4, 92   # 0x3038
        C_MOV            R1, R4   # 0x303c
        LD_LOCAL         R5, 96   # 0x303e
        C_MOV            R13, R5   # 0x3042
        BRA_PRED         4, L3288   # 0x3044
L3048:  MOVI             R6, 0   # 0x3048
        MOVI             R2, 0   # 0x304c
        MOVI             R4, 0   # 0x3050
        MOVI             R5, 0   # 0x3054
        ST_LOCAL         R5, 92   # 0x3058
        ST_LOCAL         R5, 96   # 0x305c
        ST_LOCAL         R9, 108   # 0x3060
        C_BRA            L3076   # 0x3064
L3066:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x3066
        LD_LOCAL         R9, 108   # 0x306a
        LD_LOCAL         R6, 104   # 0x306e
        BRA_PRED         0, L3026   # 0x3072
L3076:  ST_LOCAL         R6, 100   # 0x3076
        SETP_LT_NPI      P0, R5, R9, 1   # 0x307a
        BRA_PRED         0, L30be   # 0x307e
        MOVI             R5, 0   # 0x3082
        C_MOV            R6, R1   # 0x3086
        C_MOV            R7, R13   # 0x3088
L308a:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x308a
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x308e
        AND              R6, R14, R0, R14   # 0x3092
        OR               R6, R7, R6, R7   # 0x3096
        SETP_NE_NPI      P0, R6, R6, 0   # 0x309a
        BRA_PRED         4, L30c8   # 0x309e
        SHRI             R6, R7, 16   # 0x30a2
        SHLI             R14, R14, 16   # 0x30a6
        OR               R6, R14, R6, R14   # 0x30aa
        C_AND            R7, R0   # 0x30ae
        C_ADDI           R5, 1   # 0x30b0
        SETP_EQ_NP       P0, R14, R9, R5   # 0x30b2
        BRA_PRED         4, L308a   # 0x30b6
        C_MOV            R8, R9   # 0x30ba
        C_BRA            L30d4   # 0x30bc
L30be:  MOVI             R8, 0   # 0x30be
        C_MOV            R6, R1   # 0x30c2
        C_MOV            R7, R13   # 0x30c4
        C_BRA            L30d4   # 0x30c6
L30c8:  MOVI             R6, 0   # 0x30c8
        ADDI             R8, R5, 1   # 0x30cc
        MOVI             R7, 0   # 0x30d0
L30d4:  LD_LOCAL         R5, 100   # 0x30d4
        C_ADDI           R5, 1   # 0x30d8
        ST_LOCAL         R5, 104   # 0x30da
        C_MOV            R5, R1   # 0x30de
        C_MOV            R14, R13   # 0x30e0
        C_MOV            R1, R6   # 0x30e2
        C_MOV            R13, R7   # 0x30e4
        C_BRA            L30fa   # 0x30e6
L30e8:  ST_LOCAL         R6, 92   # 0x30e8
        ST_LOCAL         R7, 96   # 0x30ec
L30f0:  C_MOV            R5, R11   # 0x30f0
        C_MOV            R14, R10   # 0x30f2
        C_MOV            R1, R12   # 0x30f4
        C_MOV            R2, R6   # 0x30f6
        C_MOV            R4, R7   # 0x30f8
L30fa:  SETP_LT_NP       P0, R6, R3, R8   # 0x30fa
        BRA_PRED         0, L3136   # 0x30fe
        SHLI             R6, R1, 16   # 0x3102
        AND              R7, R6, R13, R6   # 0x3106
        ADD              R10, R6, R13, R6   # 0x310a
        C_OR             R6, R13   # 0x310e
        C_ANDN           R6, R10   # 0x3110
        OR               R6, R7, R6, R7   # 0x3112
        SHRI             R6, R6, 31   # 0x3116
        SHRI             R7, R1, 16   # 0x311a
        ADD              R6, R7, R6, R7   # 0x311e
        OR               R6, R10, R6, R10   # 0x3122
        SETP_LT_NPI      P0, R7, R9, 1   # 0x3126
        BRA_PRED         0, L3066   # 0x312a
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x312e
        BRA_PRED         0, L3066   # 0x3132
L3136:  SETP_NE_NPI      P0, R6, R8, 0   # 0x3136
        BRA_PRED         4, L320a   # 0x313a
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x313e
        BRA_PRED         0, L31e6   # 0x3142
        SHLI             R6, R1, 16   # 0x3146
        AND              R7, R6, R13, R6   # 0x314a
        ADD              R10, R6, R13, R6   # 0x314e
        C_OR             R6, R13   # 0x3152
        C_ANDN           R6, R10   # 0x3154
        OR               R6, R7, R6, R7   # 0x3156
        SHRI             R6, R6, 31   # 0x315a
        SHRI             R7, R1, 16   # 0x315e
        ADD              R6, R7, R6, R7   # 0x3162
        OR               R6, R10, R6, R10   # 0x3166
        SETP_NE_NPI      P0, R6, R6, 0   # 0x316a
        BRA_PRED         4, L31e6   # 0x316e
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x3172
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x3176
        SHLI             R7, R7, 16   # 0x317a
        SHRI             R10, R6, 16   # 0x317e
        C_OR             R7, R10   # 0x3182
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x3184
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x3188
        C_AND            R6, R0   # 0x318c
        SZ_GLOBAL_LD_U8  R12, R7, R6, 0, 1   # 0x318e
        SZ_GLOBAL_ST_8   R12, R7, R6, 0, 0   # 0x3192
        SHLI             R11, R11, 16   # 0x3196
        SHRI             R12, R10, 16   # 0x319a
        C_OR             R11, R12   # 0x319e
        C_AND            R10, R0   # 0x31a0
        SZ_GLOBAL_LD_U8  R12, R11, R10, 0, 1   # 0x31a2
        SZ_GLOBAL_ST_8   R12, R11, R10, 0, 0   # 0x31a6
        SZ_GLOBAL_LD_U16 R6, R7, R6, 0, 2   # 0x31aa
        SZ_GLOBAL_LD_U16 R7, R11, R10, 0, 2   # 0x31ae
        SHLI             R7, R7, 16   # 0x31b2
        SRAI             R7, R7, 16   # 0x31b6
        SHLI             R6, R6, 16   # 0x31ba
        SRAI             R6, R6, 16   # 0x31be
        SETP_LT_NP       P0, R6, R7, R6   # 0x31c2
        BRA_PRED         4, L31e6   # 0x31c6
        LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x31ca
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x31ce
        SHLI             R7, R7, 16   # 0x31d2
        SHRI             R10, R6, 16   # 0x31d6
        OR               R12, R7, R10, R7   # 0x31da
        C_MOV            R7, R13   # 0x31de
        AND              R13, R6, R0, R6   # 0x31e0
        C_BRA            L3228   # 0x31e4
L31e6:  LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x31e6
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x31ea
        SHLI             R7, R7, 16   # 0x31ee
        SHRI             R10, R6, 16   # 0x31f2
        OR               R11, R7, R10, R7   # 0x31f6
        AND              R10, R6, R0, R6   # 0x31fa
        ADDI             R8, R8, -1   # 0x31fe
        C_MOV            R12, R1   # 0x3202
        C_MOV            R6, R5   # 0x3204
        C_MOV            R7, R14   # 0x3206
        C_BRA            L3232   # 0x3208
L320a:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x320a
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x320e
        SHLI             R7, R7, 16   # 0x3212
        SHRI             R8, R6, 16   # 0x3216
        OR               R12, R7, R8, R7   # 0x321a
        C_MOV            R7, R13   # 0x321e
        AND              R13, R6, R0, R6   # 0x3220
        MOVI             R8, 0   # 0x3224
L3228:  ADDI             R9, R9, -1   # 0x3228
        C_MOV            R11, R5   # 0x322c
        C_MOV            R10, R14   # 0x322e
        C_MOV            R6, R1   # 0x3230
L3232:  SHLI             R5, R2, 16   # 0x3232
        AND              R14, R5, R4, R5   # 0x3236
        ADD              R1, R5, R4, R5   # 0x323a
        C_OR             R5, R4   # 0x323e
        C_ANDN           R5, R1   # 0x3240
        OR               R5, R14, R5, R14   # 0x3242
        SHRI             R5, R5, 31   # 0x3246
        SHRI             R14, R2, 16   # 0x324a
        ADD              R5, R14, R5, R14   # 0x324e
        C_OR             R1, R5   # 0x3252
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x3254
        BRA_PRED         0, L30e8   # 0x3258
        SHLI             R1, R6, 16   # 0x325c
        ADD              R5, R1, R7, R1   # 0x3260
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x3264
        OR               R14, R1, R7, R1   # 0x3268
        ANDN             R5, R14, R5, R14   # 0x326c
        C_AND            R1, R7   # 0x3270
        C_OR             R1, R5   # 0x3272
        SHRI             R1, R1, 31   # 0x3274
        SHRI             R5, R6, 16   # 0x3278
        ADD              R1, R5, R1, R5   # 0x327c
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x3280
        BRA              L30f0   # 0x3284
L3288:  LD_GLOBAL_IDX    R1, R4, R5, 0, 4   # 0x3288
        LD_GLOBAL_IDX    R0, R4, R5, 0, 0   # 0x328c
        MOVI             R7, 65535   # 0x3290
        AND              R2, R1, R7, R1   # 0x3294
        OR               R2, R0, R2, R0   # 0x3298
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x329c
        BRA_PRED         0, L330e   # 0x32a0
        SHRI             R2, R0, 16   # 0x32a4
        SHLI             R1, R1, 16   # 0x32a8
        OR               R8, R1, R2, R1   # 0x32ac
        AND              R9, R0, R7, R0   # 0x32b0
        LD_GLOBAL_IDX    R0, R4, R5, 0, 8   # 0x32b4
        LD_GLOBAL_IDX    R1, R4, R5, 0, 12   # 0x32b8
        SHLI             R1, R1, 16   # 0x32bc
        SHRI             R2, R0, 16   # 0x32c0
        C_OR             R1, R2   # 0x32c4
        C_AND            R0, R7   # 0x32c6
        SZ_GLOBAL_LD_S16 R6, R1, R0, 0, 0   # 0x32c8
        LD_LOCAL         R1, 156   # 0x32cc
L32d0:  AND              R2, R1, R7, R1   # 0x32d0
        C_MOV            R1, R6   # 0x32d4
        CALL             R14, 127522   # 0x32d6
        MOVI             R15, 2   # 0x32da
        LD_GLOBAL        R15, R15, 24   # 0x32de
        SRD              R3, 2   # 0x32e2
        C_ADD            R15, R3   # 0x32e4
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x32e6
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x32ea
        SHRI             R2, R4, 16   # 0x32ee
        SHLI             R3, R0, 16   # 0x32f2
        OR               R8, R3, R2, R3   # 0x32f6
        C_AND            R0, R7   # 0x32fa
        OR               R0, R4, R0, R4   # 0x32fc
        AND              R9, R4, R7, R4   # 0x3300
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3304
        BRA_PRED         0, L32d0   # 0x3308
        C_BRA            L3312   # 0x330c
L330e:  LD_LOCAL         R1, 156   # 0x330e
L3312:  LD_LOCAL         R14, 164   # 0x3312
        LD_LOCAL         R13, 192   # 0x3316
        LD_LOCAL         R12, 188   # 0x331a
        LD_LOCAL         R11, 184   # 0x331e
        LD_LOCAL         R10, 180   # 0x3322
        LD_LOCAL         R9, 176   # 0x3326
        LD_LOCAL         R8, 172   # 0x332a
        C_RET            224   # 0x332e
        MOVI             R15, 2   # 0x3330
        LD_GLOBAL        R15, R15, 24   # 0x3334
        SRD              R14, 2   # 0x3338
        C_ADD            R15, R14   # 0x333a
        MOVI             R1, 2   # 0x333c
        LD_GLOBAL        R0, R1, 44   # 0x3340
        ST_LOCAL         R0, 200   # 0x3344
        LD_GLOBAL        R0, R1, 40   # 0x3348
        ST_LOCAL         R0, 196   # 0x334c
        LD_GLOBAL        R0, R1, 48   # 0x3350
        LD_GLOBAL        R9, R1, 32   # 0x3354
        LD_GLOBAL        R1, R1, 36   # 0x3358
        ADDI             R4, R15, -1   # 0x335c
        ST_LOCAL         R4, 208   # 0x3360
        MOVI             R2, 65388   # 0x3364
        C_ADDI           R2, 4   # 0x3368
        MOVI             R3, 102   # 0x336a
        SZ_GLOBAL_ST_16  R3, R4, R2, 0, 0   # 0x336e
        MOVI             R2, 2000   # 0x3372
        SRD              R3, 0   # 0x3376
        ST_LOCAL         R3, 204   # 0x3378
        MADLO            R3, R3, R2, R1   # 0x337c
        ADDI             R5, R3, 666   # 0x3380
        ST_LOCAL         R5, 212   # 0x3384
        SHLI             R1, R9, 16   # 0x3388
        ADD              R2, R1, R5, R1   # 0x338c
        OR               R4, R1, R5, R1   # 0x3390
        C_ANDN           R4, R2   # 0x3394
        AND              R5, R1, R5, R1   # 0x3396
        OR               R4, R5, R4, R5   # 0x339a
        ADDI             R5, R3, 1332   # 0x339e
        ADD              R6, R1, R5, R1   # 0x33a2
        OR               R7, R1, R5, R1   # 0x33a6
        C_ANDN           R7, R6   # 0x33aa
        AND              R5, R1, R5, R1   # 0x33ac
        C_OR             R5, R7   # 0x33b0
        ADD              R7, R1, R3, R1   # 0x33b2
        OR               R8, R1, R3, R1   # 0x33b6
        C_ANDN           R8, R7   # 0x33ba
        C_AND            R1, R3   # 0x33bc
        C_OR             R1, R8   # 0x33be
        MOVI             R8, 7   # 0x33c0
        ST_GLOBAL        R8, R15, -100   # 0x33c4
        ST_GLOBAL        R0, R15, -104   # 0x33c8
        ST_GLOBAL        R7, R15, -132   # 0x33cc
        ST_GLOBAL        R7, R15, -140   # 0x33d0
        ST_GLOBAL        R6, R15, -116   # 0x33d4
        ST_GLOBAL        R2, R15, -124   # 0x33d8
        SHRI             R0, R1, 31   # 0x33dc
        C_MOV            R2, R9   # 0x33e0
        ST_LOCAL         R2, 216   # 0x33e2
        SHRI             R1, R2, 16   # 0x33e6
        ADD              R0, R1, R0, R1   # 0x33ea
        ST_GLOBAL        R0, R15, -128   # 0x33ee
        ST_GLOBAL        R0, R15, -136   # 0x33f2
        SHRI             R0, R5, 31   # 0x33f6
        ADD              R0, R1, R0, R1   # 0x33fa
        ST_GLOBAL        R0, R15, -112   # 0x33fe
        SHRI             R0, R4, 31   # 0x3402
        ADD              R0, R1, R0, R1   # 0x3406
        ST_GLOBAL        R0, R15, -120   # 0x340a
        MOVI             R0, 0   # 0x340e
        ST_GLOBAL        R0, R15, -148   # 0x3412
        MOVI             R0, 666   # 0x3416
        ST_GLOBAL        R0, R15, -108   # 0x341a
        MOVI             R1, 666   # 0x341e
        MOVI             R4, 0   # 0x3422
        CALL             R14, 124395   # 0x3426
        MOVI             R15, 2   # 0x342a
        LD_GLOBAL        R15, R15, 24   # 0x342e
        SRD              R3, 2   # 0x3432
        C_ADD            R15, R3   # 0x3434
        SHLI             R0, R1, 16   # 0x3436
        ADD              R3, R0, R2, R0   # 0x343a
        ST_GLOBAL        R3, R15, -92   # 0x343e
        OR               R4, R0, R2, R0   # 0x3442
        ANDN             R3, R4, R3, R4   # 0x3446
        C_AND            R0, R2   # 0x344a
        C_OR             R0, R3   # 0x344c
        SHRI             R0, R0, 31   # 0x344e
        SHRI             R1, R1, 16   # 0x3452
        ADD              R0, R1, R0, R1   # 0x3456
        ST_GLOBAL        R0, R15, -88   # 0x345a
        ADDI             R5, R15, -1   # 0x345e
        MOVI             R0, 65388   # 0x3462
        ADDI             R6, R0, 64   # 0x3466
        MOVI             R1, 666   # 0x346a
        LD_LOCAL         R2, 216   # 0x346e
        LD_LOCAL         R3, 212   # 0x3472
        MOVI             R4, 0   # 0x3476
        CALL             R14, 125395   # 0x347a
        MOVI             R15, 2   # 0x347e
        LD_GLOBAL        R15, R15, 24   # 0x3482
        SRD              R3, 2   # 0x3486
        C_ADD            R15, R3   # 0x3488
        MOVI             R0, 65388   # 0x348a
        LD_LOCAL         R1, 208   # 0x348e
        SZ_GLOBAL_LD_U16 R2, R1, R0, 0, 0   # 0x3492
        MOVI             R1, 65535   # 0x3496
        LD_GLOBAL        R0, R15, -116   # 0x349a
        AND              R4, R0, R1, R0   # 0x349e
        SHRI             R0, R0, 16   # 0x34a2
        LD_GLOBAL        R1, R15, -112   # 0x34a6
        SHLI             R1, R1, 16   # 0x34aa
        OR               R3, R1, R0, R1   # 0x34ae
        LD_GLOBAL        R1, R15, -108   # 0x34b2
        CALL             R14, 125703   # 0x34b6
        MOVI             R15, 2   # 0x34ba
        LD_GLOBAL        R15, R15, 24   # 0x34be
        SRD              R3, 2   # 0x34c2
        C_ADD            R15, R3   # 0x34c4
        MOVI             R5, 0   # 0x34c6
        ST_GLOBAL        R5, R15, -48   # 0x34ca
        ST_GLOBAL        R5, R15, -52   # 0x34ce
        LD_GLOBAL        R0, R15, -104   # 0x34d2
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x34d6
        MOVI             R2, 0   # 0x34da
        MOVI             R0, 0   # 0x34de
        MOVI             R1, 0   # 0x34e2
        BRA_PRED         0, L3630   # 0x34e6
        ADDI             R8, R15, -1   # 0x34ea
        MOVI             R9, 1   # 0x34ee
        C_MOV            R1, R8   # 0x34f2
        MOVI             R2, 65388   # 0x34f4
        MOVI             R3, 1   # 0x34f8
        CALL             R14, 129013   # 0x34fc
        MOVI             R15, 2   # 0x3500
        LD_GLOBAL        R15, R15, 24   # 0x3504
        SRD              R3, 2   # 0x3508
        C_ADD            R15, R3   # 0x350a
        MOVI             R12, 65535   # 0x350c
        C_AND            R1, R12   # 0x3510
        MOVI             R11, 65388   # 0x3512
        ADDI             R10, R11, 96   # 0x3516
        SZ_GLOBAL_LD_U16 R2, R8, R10, 0, 0   # 0x351a
        CALL             R14, 128795   # 0x351e
        MOVI             R15, 2   # 0x3522
        LD_GLOBAL        R15, R15, 24   # 0x3526
        SRD              R3, 2   # 0x352a
        C_ADD            R15, R3   # 0x352c
        SZ_GLOBAL_ST_16  R1, R8, R10, 0, 0   # 0x352e
        ADDI             R1, R15, -1   # 0x3532
        MOVI             R2, 65388   # 0x3536
        MOVI             R3, 65535   # 0x353a
        CALL             R14, 128980   # 0x353e
        MOVI             R15, 2   # 0x3542
        LD_GLOBAL        R15, R15, 24   # 0x3546
        SRD              R3, 2   # 0x354a
        C_ADD            R15, R3   # 0x354c
        C_AND            R1, R12   # 0x354e
        SZ_GLOBAL_LD_U16 R2, R8, R10, 0, 0   # 0x3550
        CALL             R14, 128768   # 0x3554
        MOVI             R15, 2   # 0x3558
        LD_GLOBAL        R15, R15, 24   # 0x355c
        SRD              R3, 2   # 0x3560
        C_ADD            R15, R3   # 0x3562
        C_MOV            R0, R1   # 0x3564
        ADDI             R1, R11, 98   # 0x3566
        SZ_GLOBAL_ST_16  R0, R8, R1, 0, 0   # 0x356a
        SZ_GLOBAL_ST_16  R0, R8, R10, 0, 0   # 0x356e
        LD_GLOBAL        R1, R15, -104   # 0x3572
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x3576
        C_MOV            R1, R0   # 0x357a
        BRA_PRED         0, L3618   # 0x357c
        MOVI             R0, 65388   # 0x3580
        MOVI             R10, 65535   # 0x3584
        ADDI             R11, R0, 96   # 0x3588
L358c:  ADDI             R8, R15, -1   # 0x358c
        C_MOV            R1, R8   # 0x3590
        MOVI             R2, 65388   # 0x3592
        MOVI             R3, 1   # 0x3596
        CALL             R14, 128934   # 0x359a
        MOVI             R15, 2   # 0x359e
        LD_GLOBAL        R15, R15, 24   # 0x35a2
        SRD              R3, 2   # 0x35a6
        C_ADD            R15, R3   # 0x35a8
        C_AND            R1, R10   # 0x35aa
        SZ_GLOBAL_LD_U16 R2, R8, R11, 0, 0   # 0x35ac
        CALL             R14, 128722   # 0x35b0
        MOVI             R15, 2   # 0x35b4
        LD_GLOBAL        R15, R15, 24   # 0x35b8
        SRD              R3, 2   # 0x35bc
        C_ADD            R15, R3   # 0x35be
        SZ_GLOBAL_ST_16  R1, R8, R11, 0, 0   # 0x35c0
        ADDI             R1, R15, -1   # 0x35c4
        MOVI             R2, 65388   # 0x35c8
        MOVI             R3, 65535   # 0x35cc
        CALL             R14, 128907   # 0x35d0
        MOVI             R15, 2   # 0x35d4
        LD_GLOBAL        R15, R15, 24   # 0x35d8
        SRD              R3, 2   # 0x35dc
        C_ADD            R15, R3   # 0x35de
        C_AND            R1, R10   # 0x35e0
        SZ_GLOBAL_LD_U16 R2, R8, R11, 0, 0   # 0x35e2
        CALL             R14, 128695   # 0x35e6
        MOVI             R15, 2   # 0x35ea
        LD_GLOBAL        R15, R15, 24   # 0x35ee
        SRD              R3, 2   # 0x35f2
        C_ADD            R15, R3   # 0x35f4
        SZ_GLOBAL_ST_16  R1, R8, R11, 0, 0   # 0x35f6
        C_ADDI           R9, 1   # 0x35fa
        LD_GLOBAL        R0, R15, -104   # 0x35fc
        SETP_LT_U_NP     P0, R0, R9, R0   # 0x3600
        BRA_PRED         0, L358c   # 0x3604
        MOVI             R0, 65388   # 0x3608
        ADDI             R0, R0, 98   # 0x360c
        ADDI             R2, R15, -1   # 0x3610
        SZ_GLOBAL_LD_U16 R0, R2, R0, 0, 0   # 0x3614
L3618:  ADDI             R2, R15, -1   # 0x3618
        MOVI             R3, 65388   # 0x361c
        ADDI             R4, R3, 102   # 0x3620
        SZ_GLOBAL_LD_U16 R5, R2, R4, 0, 0   # 0x3624
        ADDI             R3, R3, 100   # 0x3628
        SZ_GLOBAL_LD_U16 R2, R2, R3, 0, 0   # 0x362c
L3630:  LD_LOCAL         R4, 204   # 0x3630
        C_SHLI           R4, 3   # 0x3634
        LD_LOCAL         R3, 200   # 0x3636
        C_ADD            R3, R4   # 0x363a
        LD_LOCAL         R4, 196   # 0x363c
        SZ_GLOBAL_ST_16  R1, R4, R3, 0, 0   # 0x3640
        ADDI             R1, R3, 2   # 0x3644
        SZ_GLOBAL_ST_16  R0, R4, R1, 0, 0   # 0x3648
        ADDI             R0, R3, 4   # 0x364c
        SZ_GLOBAL_ST_16  R2, R4, R0, 0, 0   # 0x3650
        ADDI             R0, R3, 6   # 0x3654
        SZ_GLOBAL_ST_16  R5, R4, R0, 0, 0   # 0x3658
        C_EXIT           0   # 0x365c
