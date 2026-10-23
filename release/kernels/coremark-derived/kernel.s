# coremark-derived: test/coremark-derived, compiled; ccv-as source, reassembled
# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base
# (0x1000: function pointers are absolute); the kernel's entry is 0x3a68.
        ST_LOCAL         R14, 44   # 0x0000
        ST_LOCAL         R4, 32   # 0x0004
        C_MOV            R14, R3   # 0x0008
        C_MOV            R7, R2   # 0x000a
        MOVI48           R0, 3435973837   # 0x000c
        MUL_HI_U         R11, R1, R0, R1   # 0x0012
        C_SHRI           R11, 4   # 0x0016
        ADDI             R8, R11, -2   # 0x0018
        C_MOV            R0, R8   # 0x001c
        C_SHLI           R0, 4   # 0x001e
        ADD              R3, R14, R0, R14   # 0x0020
        SHLI             R5, R7, 16   # 0x0024
        ADD              R15, R5, R3, R5   # 0x0028
        OR               R0, R5, R3, R5   # 0x002c
        C_ANDN           R0, R15   # 0x0030
        AND              R2, R5, R3, R5   # 0x0032
        OR               R0, R2, R0, R2   # 0x0036
        ST_GLOBAL_IDX    R15, R7, R14, 0, 8   # 0x003a
        SHRI             R0, R0, 31   # 0x003e
        SHRI             R6, R7, 16   # 0x0042
        ST_LOCAL         R0, 24   # 0x0046
        ADD              R10, R6, R0, R6   # 0x004a
        ST_GLOBAL_IDX    R10, R7, R14, 0, 12   # 0x004e
        MOVI             R13, 0   # 0x0052
        ST_GLOBAL_IDX    R13, R7, R14, 0, 4   # 0x0056
        ST_GLOBAL_IDX    R13, R7, R14, 0, 0   # 0x005a
        MOVI             R0, 32896   # 0x005e
        C_CHWIDTH        R0, 1   # 0x0062
        ST_GLOBAL_IDX    R0, R7, R3, 0, 0   # 0x0064
        C_MOV            R4, R13   # 0x0068
        C_CHWIDTH        R4, 1   # 0x006a
        ST_GLOBAL_IDX    R4, R7, R3, 0, 2   # 0x006c
        SETP_LT_U_NPI    P0, R0, R8, 3   # 0x0070
        ST_LOCAL         R8, 40   # 0x0074
        ST_LOCAL         R3, 12   # 0x0078
        BRA_PRED         0, L010e   # 0x007c
        CHWIDTH_MULTI    17, 0   # 0x0080
        C_MOV            R2, R3   # 0x0084
        ADDI             R3, R14, 16   # 0x0086
        ADD              R0, R5, R3, R5   # 0x008a
        OR               R4, R5, R3, R5   # 0x008e
        C_ANDN           R4, R0   # 0x0092
        AND              R9, R5, R3, R5   # 0x0094
        OR               R4, R9, R4, R9   # 0x0098
        MOVI             R9, 0   # 0x009c
        ST_GLOBAL_IDX    R9, R7, R14, 0, 20   # 0x00a0
        ST_GLOBAL_IDX    R9, R7, R14, 0, 16   # 0x00a4
        ST_GLOBAL_IDX    R0, R7, R14, 0, 0   # 0x00a8
        SHRI             R0, R4, 31   # 0x00ac
        ADD              R0, R6, R0, R6   # 0x00b0
        ST_GLOBAL_IDX    R0, R7, R14, 0, 4   # 0x00b4
        ADDI             R0, R2, 4   # 0x00b8
        ADD              R4, R5, R0, R5   # 0x00bc
        ST_GLOBAL_IDX    R4, R7, R14, 0, 24   # 0x00c0
        OR               R9, R5, R0, R5   # 0x00c4
        ANDN             R4, R9, R4, R9   # 0x00c8
        LD_LOCAL         R8, 40   # 0x00cc
        AND              R0, R5, R0, R5   # 0x00d0
        C_OR             R0, R4   # 0x00d4
        SHRI             R0, R0, 31   # 0x00d6
        ADD              R0, R6, R0, R6   # 0x00da
        ST_GLOBAL_IDX    R0, R7, R14, 0, 28   # 0x00de
        MOVI             R0, 32767   # 0x00e2
        C_CHWIDTH        R0, 1   # 0x00e6
        ST_GLOBAL_IDX    R0, R7, R2, 0, 6   # 0x00e8
        C_CHWIDTH        R0, 0   # 0x00ec
        MOVI             R0, 65535   # 0x00ee
        C_CHWIDTH        R0, 1   # 0x00f2
        ST_GLOBAL_IDX    R0, R7, R2, 0, 4   # 0x00f4
        ADDI             R12, R14, 32   # 0x00f8
        ADDI             R4, R2, 8   # 0x00fc
        C_MOV            R13, R7   # 0x0100
        SETP_EQ_NPI      P0, R0, R8, 0   # 0x0102
        BRA_PRED         4, L0124   # 0x0106
        BRA              L059e   # 0x010a
L010e:  C_CHWIDTH        R4, 0   # 0x010e
        ADDI             R12, R14, 16   # 0x0110
        ADDI             R4, R3, 4   # 0x0114
        MOVI             R3, 0   # 0x0118
        SETP_EQ_NPI      P0, R0, R8, 0   # 0x011c
        BRA_PRED         0, L059e   # 0x0120
L0124:  C_CHWIDTH        R0, 0   # 0x0124
        MOVI             R9, 0   # 0x0126
        C_MOV            R2, R9   # 0x012a
        ANDI             R0, R11, 1   # 0x012c
        ST_LOCAL         R0, 48   # 0x0130
        ADDI             R1, R1, -60   # 0x0134
        SETP_LT_U_NPI    P0, R1, R1, 20   # 0x0138
        C_MOV            R0, R8   # 0x013c
        C_SHLI           R0, 2   # 0x013e
        ST_LOCAL         R0, 16   # 0x0140
        BRA_PRED         4, L0154   # 0x0144
        MOVI             R11, 0   # 0x0148
        LD_LOCAL         R8, 24   # 0x014c
        BRA              L043c   # 0x0150
L0154:  MOVI             R0, 0   # 0x0154
        ANDI             R1, R8, -2   # 0x0158
        ST_LOCAL         R1, 20   # 0x015c
        MOVI             R9, 32767   # 0x0160
        C_MOV            R2, R9   # 0x0164
        ST_LOCAL         R2, 36   # 0x0166
        ST_LOCAL         R10, 28   # 0x016a
        LD_LOCAL         R8, 24   # 0x016e
        C_BRA            L0188   # 0x0172
L0174:  C_MOV            R4, R11   # 0x0174
        C_MOV            R12, R9   # 0x0176
L0178:  C_CHWIDTH        R1, 0   # 0x0178
        C_ADDI           R0, 2   # 0x017a
        LD_LOCAL         R1, 20   # 0x017c
        SETP_EQ_NP       P0, R1, R1, R0   # 0x0180
        BRA_PRED         0, L0436   # 0x0184
L0188:  ADDI             R9, R12, 16   # 0x0188
        ADD              R11, R5, R9, R5   # 0x018c
        SETP_LT_U_NP     P0, R1, R11, R15   # 0x0190
        OR               R1, R5, R9, R5   # 0x0194
        C_ANDN           R1, R11   # 0x0198
        AND              R11, R5, R9, R5   # 0x019a
        OR               R1, R11, R1, R11   # 0x019e
        SHRI             R1, R1, 31   # 0x01a2
        SETP_EQ_NP       P1, R11, R1, R8   # 0x01a6
        ADD              R1, R6, R1, R6   # 0x01aa
        SETP_LT_U_NP     P2, R1, R1, R10   # 0x01ae
        BRA_PRED         2, L01c4   # 0x01b2
        PAND             P0, 1, 0   # 0x01b6
        BRA_PRED         0, L01c4   # 0x01b8
        C_MOV            R11, R4   # 0x01bc
        C_MOV            R9, R12   # 0x01be
        BRA              L02dc   # 0x01c0
L01c4:  LD_LOCAL         R1, 12   # 0x01c4
        LD_LOCAL         R2, 16   # 0x01c8
        C_ADD            R1, R2   # 0x01cc
        ADD              R10, R5, R1, R5   # 0x01ce
        OR               R11, R5, R1, R5   # 0x01d2
        C_ANDN           R11, R10   # 0x01d6
        AND              R1, R5, R1, R5   # 0x01d8
        C_OR             R1, R11   # 0x01dc
        ADDI             R11, R4, 4   # 0x01de
        ADD              R2, R5, R11, R5   # 0x01e2
        SETP_LT_U_NP     P0, R10, R2, R10   # 0x01e6
        OR               R10, R5, R11, R5   # 0x01ea
        ANDN             R2, R10, R2, R10   # 0x01ee
        AND              R10, R5, R11, R5   # 0x01f2
        OR               R2, R10, R2, R10   # 0x01f6
        SHRI             R2, R2, 31   # 0x01fa
        SHRI             R1, R1, 31   # 0x01fe
        SETP_EQ_NP       P1, R10, R2, R1   # 0x0202
        ADD              R2, R6, R2, R6   # 0x0206
        ADD              R1, R6, R1, R6   # 0x020a
        SETP_LT_U_NP     P2, R1, R2, R1   # 0x020e
        BRA_PRED         2, L0222   # 0x0212
        PAND             P0, 1, 0   # 0x0216
        BRA_PRED         0, L0222   # 0x0218
        C_MOV            R11, R4   # 0x021c
        C_MOV            R9, R12   # 0x021e
        C_BRA            L02d8   # 0x0220
L0222:  LD_LOCAL         R1, 32   # 0x0222
        C_CHWIDTH        R1, 1   # 0x0226
        XOR              R1, R0, R1, R0   # 0x0228
        C_CHWIDTH        R1, 0   # 0x022c
        SHLI             R1, R1, 3   # 0x022e
        MOVI             R2, 120   # 0x0232
        C_CHWIDTH        R2, 1   # 0x0236
        AND              R2, R1, R2, R1   # 0x0238
        MOVI             R1, 6   # 0x023c
        C_CHWIDTH        R1, 1   # 0x0240
        AND              R1, R0, R1, R0   # 0x0242
        OR               R1, R2, R1, R2   # 0x0246
        CHWIDTH_MULTI    6, 0   # 0x024a
        MULI             R1, R1, 257   # 0x024e
        C_CHWIDTH        R1, 1   # 0x0252
        SHLI             R2, R13, 16   # 0x0254
        AND              R10, R2, R3, R2   # 0x0258
        ADD              R8, R2, R3, R2   # 0x025c
        C_OR             R2, R3   # 0x0260
        C_ANDN           R2, R8   # 0x0262
        OR               R2, R10, R2, R10   # 0x0264
        SHRI             R2, R2, 31   # 0x0268
        SHRI             R3, R13, 16   # 0x026c
        ADD              R2, R3, R2, R3   # 0x0270
        ST_GLOBAL_IDX    R8, R7, R12, 0, 0   # 0x0274
        ST_GLOBAL_IDX    R2, R7, R12, 0, 4   # 0x0278
        ADD              R2, R5, R12, R5   # 0x027c
        OR               R3, R5, R12, R5   # 0x0280
        C_ANDN           R3, R2   # 0x0284
        AND              R8, R5, R12, R5   # 0x0286
        OR               R3, R8, R3, R8   # 0x028a
        SHRI             R3, R3, 31   # 0x028e
        ADD              R3, R6, R3, R6   # 0x0292
        ST_GLOBAL_IDX    R3, R7, R14, 0, 4   # 0x0296
        ST_GLOBAL_IDX    R2, R7, R14, 0, 0   # 0x029a
        ADD              R2, R5, R4, R5   # 0x029e
        OR               R3, R5, R4, R5   # 0x02a2
        C_ANDN           R3, R2   # 0x02a6
        AND              R8, R5, R4, R5   # 0x02a8
        OR               R3, R8, R3, R8   # 0x02ac
        LD_LOCAL         R8, 24   # 0x02b0
        SHRI             R3, R3, 31   # 0x02b4
        ADD              R3, R6, R3, R6   # 0x02b8
        ST_GLOBAL_IDX    R3, R7, R12, 0, 12   # 0x02bc
        ST_GLOBAL_IDX    R2, R7, R12, 0, 8   # 0x02c0
        LD_LOCAL         R3, 36   # 0x02c4
        C_CHWIDTH        R3, 1   # 0x02c8
        ST_GLOBAL_IDX    R3, R7, R4, 0, 2   # 0x02ca
        C_CHWIDTH        R3, 0   # 0x02ce
        ST_GLOBAL_IDX    R1, R7, R4, 0, 0   # 0x02d0
        C_MOV            R13, R7   # 0x02d4
        C_MOV            R3, R12   # 0x02d6
L02d8:  LD_LOCAL         R10, 28   # 0x02d8
L02dc:  C_CHWIDTH        R1, 0   # 0x02dc
        ADDI             R12, R9, 16   # 0x02de
        ADD              R1, R5, R12, R5   # 0x02e2
        SETP_LT_U_NP     P0, R2, R1, R15   # 0x02e6
        OR               R2, R5, R12, R5   # 0x02ea
        ANDN             R1, R2, R1, R2   # 0x02ee
        AND              R2, R5, R12, R5   # 0x02f2
        OR               R1, R2, R1, R2   # 0x02f6
        SHRI             R1, R1, 31   # 0x02fa
        SETP_EQ_NP       P1, R2, R1, R8   # 0x02fe
        ADD              R1, R6, R1, R6   # 0x0302
        SETP_LT_U_NP     P2, R1, R1, R10   # 0x0306
        BRA_PRED         2, L0314   # 0x030a
        PAND             P0, 1, 0   # 0x030e
        BRA_PRED         4, L0174   # 0x0310
L0314:  LD_LOCAL         R1, 12   # 0x0314
        LD_LOCAL         R2, 16   # 0x0318
        C_ADD            R1, R2   # 0x031c
        ADD              R2, R5, R1, R5   # 0x031e
        OR               R4, R5, R1, R5   # 0x0322
        C_ANDN           R4, R2   # 0x0326
        AND              R1, R5, R1, R5   # 0x0328
        C_OR             R1, R4   # 0x032c
        ADDI             R4, R11, 4   # 0x032e
        ADD              R8, R5, R4, R5   # 0x0332
        SETP_LT_U_NP     P0, R2, R8, R2   # 0x0336
        OR               R2, R5, R4, R5   # 0x033a
        C_ANDN           R2, R8   # 0x033e
        AND              R8, R5, R4, R5   # 0x0340
        OR               R2, R8, R2, R8   # 0x0344
        SHRI             R2, R2, 31   # 0x0348
        SHRI             R1, R1, 31   # 0x034c
        SETP_EQ_NP       P1, R8, R2, R1   # 0x0350
        ADD              R2, R6, R2, R6   # 0x0354
        ADD              R1, R6, R1, R6   # 0x0358
        SETP_LT_U_NP     P2, R1, R2, R1   # 0x035c
        BRA_PRED         2, L0370   # 0x0360
        PAND             P0, 1, 0   # 0x0364
        BRA_PRED         0, L0370   # 0x0366
        C_MOV            R4, R11   # 0x036a
        C_MOV            R12, R9   # 0x036c
        C_BRA            L042e   # 0x036e
L0370:  C_CHWIDTH        R2, 1   # 0x0370
        MOVI             R1, 1   # 0x0372
        OR               R2, R0, R1, R0   # 0x0376
        LD_LOCAL         R1, 32   # 0x037a
        C_CHWIDTH        R1, 1   # 0x037e
        XOR              R1, R2, R1, R2   # 0x0380
        C_CHWIDTH        R1, 0   # 0x0384
        MOVI             R8, 7   # 0x0386
        AND              R2, R2, R8, R2   # 0x038a
        SHLI             R1, R1, 3   # 0x038e
        C_CHWIDTH        R1, 1   # 0x0392
        MOVI             R8, 120   # 0x0394
        AND              R1, R1, R8, R1   # 0x0398
        OR               R1, R1, R2, R1   # 0x039c
        CHWIDTH_MULTI    6, 0   # 0x03a0
        MULI             R1, R1, 257   # 0x03a4
        C_CHWIDTH        R1, 1   # 0x03a8
        SHLI             R2, R13, 16   # 0x03aa
        AND              R8, R2, R3, R2   # 0x03ae
        ADD              R10, R2, R3, R2   # 0x03b2
        C_OR             R2, R3   # 0x03b6
        C_ANDN           R2, R10   # 0x03b8
        OR               R2, R8, R2, R8   # 0x03ba
        SHRI             R2, R2, 31   # 0x03be
        SHRI             R3, R13, 16   # 0x03c2
        ADD              R2, R3, R2, R3   # 0x03c6
        ST_GLOBAL_IDX    R10, R7, R9, 0, 0   # 0x03ca
        LD_LOCAL         R10, 28   # 0x03ce
        ST_GLOBAL_IDX    R2, R7, R9, 0, 4   # 0x03d2
        ADD              R2, R5, R9, R5   # 0x03d6
        OR               R3, R5, R9, R5   # 0x03da
        C_ANDN           R3, R2   # 0x03de
        AND              R8, R5, R9, R5   # 0x03e0
        OR               R3, R8, R3, R8   # 0x03e4
        SHRI             R3, R3, 31   # 0x03e8
        ADD              R3, R6, R3, R6   # 0x03ec
        ST_GLOBAL_IDX    R3, R7, R14, 0, 4   # 0x03f0
        ST_GLOBAL_IDX    R2, R7, R14, 0, 0   # 0x03f4
        ADD              R2, R5, R11, R5   # 0x03f8
        OR               R3, R5, R11, R5   # 0x03fc
        C_ANDN           R3, R2   # 0x0400
        AND              R8, R5, R11, R5   # 0x0402
        OR               R3, R8, R3, R8   # 0x0406
        SHRI             R3, R3, 31   # 0x040a
        ADD              R3, R6, R3, R6   # 0x040e
        ST_GLOBAL_IDX    R3, R7, R9, 0, 12   # 0x0412
        ST_GLOBAL_IDX    R2, R7, R9, 0, 8   # 0x0416
        LD_LOCAL         R3, 36   # 0x041a
        C_CHWIDTH        R3, 1   # 0x041e
        ST_GLOBAL_IDX    R3, R7, R11, 0, 2   # 0x0420
        C_CHWIDTH        R3, 0   # 0x0424
        ST_GLOBAL_IDX    R1, R7, R11, 0, 0   # 0x0426
        C_MOV            R13, R7   # 0x042a
        C_MOV            R3, R9   # 0x042c
L042e:  LD_LOCAL         R8, 24   # 0x042e
        BRA              L0178   # 0x0432
L0436:  C_MOV            R2, R0   # 0x0436
        C_MOV            R9, R13   # 0x0438
        C_MOV            R11, R3   # 0x043a
L043c:  LD_LOCAL         R0, 48   # 0x043c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x0440
        BRA_PRED         0, L05a6   # 0x0444
        C_MOV            R11, R2   # 0x0448
        LD_LOCAL         R0, 12   # 0x044a
        LD_LOCAL         R1, 16   # 0x044e
        C_ADD            R0, R1   # 0x0452
        ADD              R1, R5, R0, R5   # 0x0454
        OR               R9, R5, R0, R5   # 0x0458
        C_ANDN           R9, R1   # 0x045c
        AND              R0, R5, R0, R5   # 0x045e
        C_OR             R0, R9   # 0x0462
        ADDI             R9, R4, 4   # 0x0464
        C_MOV            R2, R10   # 0x0468
        ADD              R10, R5, R9, R5   # 0x046a
        SETP_LT_U_NP     P0, R1, R10, R1   # 0x046e
        ST_PRED_LOCAL    1, 12   # 0x0472
        OR               R1, R5, R9, R5   # 0x0476
        C_ANDN           R1, R10   # 0x047a
        AND              R9, R5, R9, R5   # 0x047c
        OR               R1, R9, R1, R9   # 0x0480
        SHRI             R1, R1, 31   # 0x0484
        SHRI             R0, R0, 31   # 0x0488
        SETP_EQ_NP       P0, R9, R1, R0   # 0x048c
        ST_PRED_LOCAL    1, 16   # 0x0490
        ADD              R1, R6, R1, R6   # 0x0494
        ADD              R0, R6, R0, R6   # 0x0498
        SETP_LT_U_NP     P2, R0, R1, R0   # 0x049c
        ADDI             R0, R12, 16   # 0x04a0
        ADD              R1, R5, R0, R5   # 0x04a4
        SETP_LE_U_NP     P0, R15, R15, R1   # 0x04a8
        OR               R15, R5, R0, R5   # 0x04ac
        ANDN             R1, R15, R1, R15   # 0x04b0
        AND              R0, R5, R0, R5   # 0x04b4
        C_OR             R0, R1   # 0x04b8
        SHRI             R0, R0, 31   # 0x04ba
        SETP_NE_NP       P1, R1, R0, R8   # 0x04be
        POR              P0, 1, 0   # 0x04c2
        ADD              R0, R6, R0, R6   # 0x04c4
        SETP_LE_U_NP     P1, R0, R2, R0   # 0x04c8
        PAND             P0, 1, 0   # 0x04cc
        BRA_PRED         0, L059e   # 0x04ce
        LD_PRED_LOCAL    1, 12   # 0x04d2
        LD_PRED_LOCAL    2, 12   # 0x04d6
        PAND             P0, 1, 0   # 0x04da
        POR              P0, 2, 0   # 0x04dc
        BRA_PRED         4, L059e   # 0x04de
        SHLI             R0, R13, 16   # 0x04e2
        AND              R1, R0, R3, R0   # 0x04e6
        ADD              R2, R0, R3, R0   # 0x04ea
        C_OR             R0, R3   # 0x04ee
        C_ANDN           R0, R2   # 0x04f0
        OR               R0, R1, R0, R1   # 0x04f2
        SHRI             R0, R0, 31   # 0x04f6
        SHRI             R1, R13, 16   # 0x04fa
        ADD              R0, R1, R0, R1   # 0x04fe
        ST_GLOBAL_IDX    R2, R7, R12, 0, 0   # 0x0502
        ST_GLOBAL_IDX    R0, R7, R12, 0, 4   # 0x0506
        ADD              R0, R5, R12, R5   # 0x050a
        OR               R1, R5, R12, R5   # 0x050e
        C_ANDN           R1, R0   # 0x0512
        AND              R2, R5, R12, R5   # 0x0514
        OR               R1, R2, R1, R2   # 0x0518
        SHRI             R1, R1, 31   # 0x051c
        ADD              R1, R6, R1, R6   # 0x0520
        ST_GLOBAL_IDX    R1, R7, R14, 0, 4   # 0x0524
        ST_GLOBAL_IDX    R0, R7, R14, 0, 0   # 0x0528
        ADD              R0, R5, R4, R5   # 0x052c
        OR               R1, R5, R4, R5   # 0x0530
        C_ANDN           R1, R0   # 0x0534
        AND              R2, R5, R4, R5   # 0x0536
        C_CHWIDTH        R5, 1   # 0x053a
        OR               R1, R2, R1, R2   # 0x053c
        SHRI             R1, R1, 31   # 0x0540
        ADD              R1, R6, R1, R6   # 0x0544
        C_CHWIDTH        R6, 1   # 0x0548
        ST_GLOBAL_IDX    R1, R7, R12, 0, 12   # 0x054a
        ST_GLOBAL_IDX    R0, R7, R12, 0, 8   # 0x054e
        MOVI             R0, 7   # 0x0552
        AND              R6, R11, R0, R11   # 0x0556
        LD_LOCAL         R0, 32   # 0x055a
        C_CHWIDTH        R0, 1   # 0x055e
        XOR              R0, R11, R0, R11   # 0x0560
        C_CHWIDTH        R0, 0   # 0x0564
        MOVI             R1, 32767   # 0x0566
        C_CHWIDTH        R1, 1   # 0x056a
        ST_GLOBAL_IDX    R1, R7, R4, 0, 2   # 0x056c
        C_CHWIDTH        R1, 0   # 0x0570
        SHLI             R0, R0, 3   # 0x0572
        MOVI             R1, 120   # 0x0576
        AND              R5, R0, R1, R0   # 0x057a
        C_CHWIDTH        R0, 1   # 0x057e
        OR               R0, R5, R6, R5   # 0x0580
        CHWIDTH_MULTI    33, 0   # 0x0584
        MULI             R0, R0, 257   # 0x0588
        C_MOV            R1, R0   # 0x058c
        C_CHWIDTH        R0, 0   # 0x058e
        C_CHWIDTH        R1, 1   # 0x0590
        ST_GLOBAL_IDX    R1, R7, R4, 0, 0   # 0x0592
        C_CHWIDTH        R1, 0   # 0x0596
        C_MOV            R9, R7   # 0x0598
        C_MOV            R11, R12   # 0x059a
        C_BRA            L05a6   # 0x059c
L059e:  CHWIDTH_MULTI    1, 0   # 0x059e
        C_MOV            R9, R13   # 0x05a2
        C_MOV            R11, R3   # 0x05a4
L05a6:  CHWIDTH_MULTI    64, 0   # 0x05a6
        LD_GLOBAL_IDX    R1, R9, R11, 0, 4   # 0x05aa
        LD_GLOBAL_IDX    R0, R9, R11, 0, 0   # 0x05ae
        MOVI             R5, 65535   # 0x05b2
        AND              R2, R1, R5, R1   # 0x05b6
        OR               R2, R0, R2, R0   # 0x05ba
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x05be
        LD_LOCAL         R12, 32   # 0x05c2
        BRA_PRED         0, L066e   # 0x05c6
        C_CHWIDTH        R6, 0   # 0x05ca
        SHRI             R2, R0, 16   # 0x05cc
        SHLI             R1, R1, 16   # 0x05d0
        OR               R15, R1, R2, R1   # 0x05d4
        AND              R8, R0, R5, R0   # 0x05d8
        MOVI48           R0, 3435973837   # 0x05dc
        LD_LOCAL         R1, 40   # 0x05e2
        MUL_HI_U         R0, R1, R0, R1   # 0x05e6
        MOVI             R10, 1   # 0x05ea
        C_SHRI           R0, 2   # 0x05ee
        MOVI             R1, 16383   # 0x05f0
        MOVI             R2, 1792   # 0x05f4
        C_BRA            L0642   # 0x05f8
L05fa:  C_CHWIDTH        R15, 1   # 0x05fa
        LD_GLOBAL_IDX    R8, R9, R11, 0, 8   # 0x05fc
        LD_GLOBAL_IDX    R9, R9, R11, 0, 12   # 0x0600
        SHLI             R9, R9, 16   # 0x0604
        SHRI             R10, R8, 16   # 0x0608
        C_OR             R9, R10   # 0x060c
        C_AND            R8, R5   # 0x060e
        ST_GLOBAL_IDX    R15, R9, R8, 0, 2   # 0x0610
        C_CHWIDTH        R15, 0   # 0x0614
        LD_GLOBAL_IDX    R8, R4, R3, 0, 4   # 0x0616
        LD_GLOBAL_IDX    R9, R4, R3, 0, 0   # 0x061a
        SHRI             R15, R9, 16   # 0x061e
        SHLI             R10, R8, 16   # 0x0622
        OR               R15, R10, R15, R10   # 0x0626
        C_AND            R8, R5   # 0x062a
        OR               R10, R9, R8, R9   # 0x062c
        AND              R8, R9, R5, R9   # 0x0630
        SETP_NE_NPI      P0, R9, R10, 0   # 0x0634
        C_MOV            R9, R4   # 0x0638
        C_MOV            R11, R3   # 0x063a
        C_MOV            R10, R6   # 0x063c
        BRA_PRED         4, L066e   # 0x063e
L0642:  C_MOV            R3, R8   # 0x0642
        C_MOV            R4, R15   # 0x0644
        C_MOV            R15, R10   # 0x0646
        SETP_LT_U_NP     P0, R6, R10, R0   # 0x0648
        ADDI             R6, R10, 1   # 0x064c
        BRA_PRED         0, L05fa   # 0x0650
        CHWIDTH_MULTI    40960, 1   # 0x0654
        XOR              R15, R10, R12, R10   # 0x0658
        AND              R15, R15, R1, R15   # 0x065c
        SHLI             R8, R6, 8   # 0x0660
        AND              R13, R8, R2, R8   # 0x0664
        OR               R15, R13, R15, R13   # 0x0668
        C_BRA            L05fa   # 0x066c
L066e:  MOVI             R10, 1   # 0x066e
        MOVI             R6, 0   # 0x0672
        C_BRA            L069a   # 0x0676
L0678:  ST_GLOBAL_IDX    R6, R4, R1, 0, 4   # 0x0678
        ST_GLOBAL_IDX    R6, R4, R1, 0, 0   # 0x067c
        C_SHLI           R10, 1   # 0x0680
        LD_LOCAL         R0, 20   # 0x0682
        SETP_NE_NPI      P0, R0, R0, 0   # 0x0686
        LD_LOCAL         R1, 12   # 0x068a
        C_MOV            R7, R1   # 0x068e
        LD_LOCAL         R2, 16   # 0x0690
        C_MOV            R14, R2   # 0x0694
        BRA_PRED         4, L08ec   # 0x0696
L069a:  MOVI             R2, 0   # 0x069a
        MOVI             R4, 0   # 0x069e
        MOVI             R1, 0   # 0x06a2
        MOVI             R0, 0   # 0x06a6
        ST_LOCAL         R0, 12   # 0x06aa
        ST_LOCAL         R0, 16   # 0x06ae
        ST_LOCAL         R10, 28   # 0x06b2
        C_BRA            L06c8   # 0x06b6
L06b8:  SETP_EQ_NPI      P0, R0, R3, 0   # 0x06b8
        LD_LOCAL         R10, 28   # 0x06bc
        LD_LOCAL         R2, 24   # 0x06c0
        BRA_PRED         0, L0678   # 0x06c4
L06c8:  ST_LOCAL         R2, 20   # 0x06c8
        SETP_LT_NPI      P0, R0, R10, 1   # 0x06cc
        BRA_PRED         0, L0712   # 0x06d0
        MOVI             R0, 0   # 0x06d4
        C_MOV            R3, R7   # 0x06d8
        C_MOV            R15, R14   # 0x06da
L06dc:  LD_GLOBAL_IDX    R8, R3, R15, 0, 4   # 0x06dc
        LD_GLOBAL_IDX    R2, R3, R15, 0, 0   # 0x06e0
        AND              R3, R8, R5, R8   # 0x06e4
        OR               R3, R2, R3, R2   # 0x06e8
        SETP_NE_NPI      P0, R3, R3, 0   # 0x06ec
        BRA_PRED         4, L071c   # 0x06f0
        SHRI             R3, R2, 16   # 0x06f4
        SHLI             R15, R8, 16   # 0x06f8
        OR               R3, R15, R3, R15   # 0x06fc
        AND              R15, R2, R5, R2   # 0x0700
        C_ADDI           R0, 1   # 0x0704
        SETP_EQ_NP       P0, R2, R10, R0   # 0x0706
        BRA_PRED         4, L06dc   # 0x070a
        C_MOV            R9, R10   # 0x070e
        C_BRA            L0728   # 0x0710
L0712:  MOVI             R9, 0   # 0x0712
        C_MOV            R3, R7   # 0x0716
        C_MOV            R15, R14   # 0x0718
        C_BRA            L0728   # 0x071a
L071c:  MOVI             R3, 0   # 0x071c
        ADDI             R9, R0, 1   # 0x0720
        MOVI             R15, 0   # 0x0724
L0728:  LD_LOCAL         R0, 20   # 0x0728
        C_ADDI           R0, 1   # 0x072c
        ST_LOCAL         R0, 24   # 0x072e
        C_MOV            R2, R7   # 0x0732
        C_MOV            R0, R14   # 0x0734
        C_MOV            R7, R3   # 0x0736
        C_MOV            R14, R15   # 0x0738
        C_BRA            L0750   # 0x073a
L073c:  ST_LOCAL         R15, 12   # 0x073c
        ST_LOCAL         R8, 16   # 0x0740
L0744:  C_MOV            R2, R12   # 0x0744
        C_MOV            R0, R11   # 0x0746
        C_MOV            R7, R13   # 0x0748
        C_MOV            R14, R3   # 0x074a
        C_MOV            R4, R15   # 0x074c
        C_MOV            R1, R8   # 0x074e
L0750:  SETP_LT_NP       P0, R3, R6, R9   # 0x0750
        BRA_PRED         0, L078c   # 0x0754
        SHLI             R3, R7, 16   # 0x0758
        AND              R15, R3, R14, R3   # 0x075c
        ADD              R8, R3, R14, R3   # 0x0760
        C_OR             R3, R14   # 0x0764
        C_ANDN           R3, R8   # 0x0766
        OR               R3, R15, R3, R15   # 0x0768
        SHRI             R3, R3, 31   # 0x076c
        SHRI             R15, R7, 16   # 0x0770
        ADD              R3, R15, R3, R15   # 0x0774
        OR               R3, R8, R3, R8   # 0x0778
        SETP_LT_NPI      P0, R15, R10, 1   # 0x077c
        BRA_PRED         0, L06b8   # 0x0780
        SETP_EQ_NPI      P0, R15, R3, 0   # 0x0784
        BRA_PRED         0, L06b8   # 0x0788
L078c:  SETP_NE_NPI      P0, R3, R9, 0   # 0x078c
        BRA_PRED         4, L086a   # 0x0790
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x0794
        BRA_PRED         0, L0840   # 0x0798
        SHLI             R3, R7, 16   # 0x079c
        AND              R15, R3, R14, R3   # 0x07a0
        ADD              R8, R3, R14, R3   # 0x07a4
        C_OR             R3, R14   # 0x07a8
        C_ANDN           R3, R8   # 0x07aa
        OR               R3, R15, R3, R15   # 0x07ac
        SHRI             R3, R3, 31   # 0x07b0
        SHRI             R15, R7, 16   # 0x07b4
        ADD              R3, R15, R3, R15   # 0x07b8
        OR               R3, R8, R3, R8   # 0x07bc
        SETP_NE_NPI      P0, R3, R3, 0   # 0x07c0
        BRA_PRED         4, L0840   # 0x07c4
        C_CHWIDTH        R12, 2   # 0x07c8
        LD_GLOBAL_IDX    R3, R2, R0, 0, 8   # 0x07ca
        LD_GLOBAL_IDX    R15, R2, R0, 0, 12   # 0x07ce
        SHLI             R15, R15, 16   # 0x07d2
        SHRI             R8, R3, 16   # 0x07d6
        C_OR             R15, R8   # 0x07da
        LD_GLOBAL_IDX    R8, R7, R14, 0, 8   # 0x07dc
        LD_GLOBAL_IDX    R11, R7, R14, 0, 12   # 0x07e0
        C_AND            R3, R5   # 0x07e4
        LD_GLOBAL_IDX    R12, R15, R3, 0, 1   # 0x07e6
        ST_GLOBAL_IDX    R12, R15, R3, 0, 0   # 0x07ea
        C_CHWIDTH        R3, 1   # 0x07ee
        C_CHWIDTH        R12, 0   # 0x07f0
        SHLI             R11, R11, 16   # 0x07f2
        SHRI             R12, R8, 16   # 0x07f6
        C_OR             R11, R12   # 0x07fa
        C_CHWIDTH        R12, 2   # 0x07fc
        C_AND            R8, R5   # 0x07fe
        LD_GLOBAL_IDX    R12, R11, R8, 0, 1   # 0x0800
        ST_GLOBAL_IDX    R12, R11, R8, 0, 0   # 0x0804
        LD_GLOBAL_IDX    R3, R15, R3, 0, 2   # 0x0808
        C_CHWIDTH        R15, 1   # 0x080c
        LD_GLOBAL_IDX    R15, R11, R8, 0, 2   # 0x080e
        CVT_SEXT         R8, R15, R15, R15   # 0x0812
        C_CHWIDTH        R15, 0   # 0x0816
        CVT_SEXT         R15, R3, R3, R3   # 0x0818
        SETP_LT_NP       P0, R3, R8, R15   # 0x081c
        BRA_PRED         4, L0840   # 0x0820
        CHWIDTH_MULTI    8200, 0   # 0x0824
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x0828
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x082c
        SHLI             R15, R15, 16   # 0x0830
        SHRI             R8, R3, 16   # 0x0834
        OR               R13, R15, R8, R15   # 0x0838
        C_AND            R3, R5   # 0x083c
        C_BRA            L0886   # 0x083e
L0840:  CHWIDTH_MULTI    12296, 0   # 0x0840
        LD_GLOBAL_IDX    R3, R2, R0, 0, 0   # 0x0844
        LD_GLOBAL_IDX    R15, R2, R0, 0, 4   # 0x0848
        SHLI             R15, R15, 16   # 0x084c
        SHRI             R8, R3, 16   # 0x0850
        OR               R12, R15, R8, R15   # 0x0854
        AND              R11, R3, R5, R3   # 0x0858
        ADDI             R9, R9, -1   # 0x085c
        C_MOV            R13, R7   # 0x0860
        C_MOV            R3, R14   # 0x0862
        C_MOV            R15, R2   # 0x0864
        C_MOV            R8, R0   # 0x0866
        C_BRA            L0894   # 0x0868
L086a:  C_CHWIDTH        R13, 0   # 0x086a
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x086c
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x0870
        SHLI             R15, R15, 16   # 0x0874
        SHRI             R8, R3, 16   # 0x0878
        OR               R13, R15, R8, R15   # 0x087c
        C_AND            R3, R5   # 0x0880
        MOVI             R9, 0   # 0x0882
L0886:  C_CHWIDTH        R12, 0   # 0x0886
        ADDI             R10, R10, -1   # 0x0888
        C_MOV            R12, R2   # 0x088c
        C_MOV            R11, R0   # 0x088e
        C_MOV            R15, R7   # 0x0890
        C_MOV            R8, R14   # 0x0892
L0894:  SHLI             R0, R4, 16   # 0x0894
        AND              R2, R0, R1, R0   # 0x0898
        ADD              R7, R0, R1, R0   # 0x089c
        C_OR             R0, R1   # 0x08a0
        C_ANDN           R0, R7   # 0x08a2
        OR               R0, R2, R0, R2   # 0x08a4
        SHRI             R0, R0, 31   # 0x08a8
        SHRI             R2, R4, 16   # 0x08ac
        ADD              R0, R2, R0, R2   # 0x08b0
        OR               R0, R7, R0, R7   # 0x08b4
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x08b8
        BRA_PRED         0, L073c   # 0x08bc
        SHLI             R0, R15, 16   # 0x08c0
        ADD              R2, R0, R8, R0   # 0x08c4
        ST_GLOBAL_IDX    R2, R4, R1, 0, 0   # 0x08c8
        OR               R7, R0, R8, R0   # 0x08cc
        ANDN             R2, R7, R2, R7   # 0x08d0
        C_AND            R0, R8   # 0x08d4
        C_OR             R0, R2   # 0x08d6
        SHRI             R0, R0, 31   # 0x08d8
        SHRI             R2, R15, 16   # 0x08dc
        ADD              R0, R2, R0, R2   # 0x08e0
        ST_GLOBAL_IDX    R0, R4, R1, 0, 4   # 0x08e4
        BRA              L0744   # 0x08e8
L08ec:  C_CHWIDTH        R13, 0   # 0x08ec
        LD_LOCAL         R14, 44   # 0x08ee
        C_RET            224   # 0x08f2
        ST_LOCAL         R14, 48   # 0x08f4
        ST_LOCAL         R6, 52   # 0x08f8
        ST_LOCAL         R5, 56   # 0x08fc
        ST_LOCAL         R3, 24   # 0x0900
        C_MOV            R0, R1   # 0x0904
        MOVI             R3, 1   # 0x0906
        SETP_LT_U_NP     P0, R1, R3, R4   # 0x090a
        MOVI             R7, 1   # 0x090e
        MOV_P            R7, 0, R4, R4, R4   # 0x0912
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0916
        BRA_PRED         0, L093e   # 0x091a
        MOVI48           R8, 4294967295   # 0x091e
        MOVI             R4, 8   # 0x0924
L0928:  ADDI             R5, R8, 2   # 0x0928
        MUL_LO           R5, R4, R5, R5   # 0x092c
        SETP_LT_U_NP     P0, R5, R5, R0   # 0x0930
        C_ADDI           R4, 8   # 0x0934
        C_ADDI           R8, 1   # 0x0936
        BRA_PRED         0, L0928   # 0x0938
        C_BRA            L0944   # 0x093c
L093e:  MOVI48           R8, 4294967295   # 0x093e
L0944:  SHLI             R1, R2, 16   # 0x0944
        LD_LOCAL         R0, 24   # 0x0948
        ADD              R0, R1, R0, R1   # 0x094c
        C_NEG            R4, R0   # 0x0950
        C_ANDI           R4, 3   # 0x0952
        ST_LOCAL         R4, 32   # 0x0954
        ADD              R4, R0, R4, R0   # 0x0958
        MUL_LO           R5, R8, R8, R8   # 0x095c
        C_SHLI           R5, 1   # 0x0960
        ST_LOCAL         R5, 28   # 0x0962
        ADD              R5, R4, R5, R4   # 0x0966
        MOVI             R10, 0   # 0x096a
        SETP_LT_U_NP     P0, R5, R5, R4   # 0x096e
        MOVI             R5, 0   # 0x0972
        MOV_P            R5, 0, R3, R3, R3   # 0x0976
        SETP_LT_U_NP     P0, R4, R4, R0   # 0x097a
        MOVI             R4, 0   # 0x097e
        MOV_P            R4, 0, R3, R3, R3   # 0x0982
        ST_LOCAL         R1, 60   # 0x0986
        SETP_LT_U_NP     P0, R0, R0, R1   # 0x098a
        MOVI             R0, 0   # 0x098e
        MOV_P            R0, 0, R3, R3, R3   # 0x0992
        SETP_EQ_NPI      P0, R0, R8, 0   # 0x0996
        BRA_PRED         0, L0b42   # 0x099a
        C_CHWIDTH        R0, 1   # 0x099e
        LD_LOCAL         R1, 24   # 0x09a0
        SUB              R0, R10, R1, R10   # 0x09a4
        C_CHWIDTH        R0, 0   # 0x09a8
        C_ANDI           R0, 3   # 0x09aa
        ADD              R9, R1, R0, R1   # 0x09ac
        MOVI             R4, 1   # 0x09b0
        C_MOV            R11, R8   # 0x09b4
        C_SHLI           R11, 1   # 0x09b6
        ANDI             R12, R8, -2   # 0x09b8
        ANDI             R14, R8, 1   # 0x09bc
        LD_LOCAL         R0, 28   # 0x09c0
        ADD              R0, R9, R0, R9   # 0x09c4
        MOVI             R6, 255   # 0x09c8
        MOVI             R13, 0   # 0x09cc
        ST_LOCAL         R8, 36   # 0x09d0
        ST_LOCAL         R11, 40   # 0x09d4
        ST_LOCAL         R14, 44   # 0x09d8
        C_BRA            L09f2   # 0x09dc
L09de:  CHWIDTH_MULTI    32, 0   # 0x09de
        C_ADD            R0, R11   # 0x09e2
        C_ADD            R9, R11   # 0x09e4
        C_ADD            R10, R8   # 0x09e6
        C_ADDI           R13, 1   # 0x09e8
        SETP_NE_NP       P0, R1, R13, R8   # 0x09ea
        BRA_PRED         4, L0b42   # 0x09ee
L09f2:  C_CHWIDTH        R15, 0   # 0x09f2
        MOVI             R15, 0   # 0x09f4
        SETP_EQ_NPI      P0, R3, R8, 1   # 0x09f8
        BRA_PRED         0, L0ade   # 0x09fc
        ST_LOCAL         R13, 20   # 0x0a00
        ST_LOCAL         R10, 16   # 0x0a04
        MOVI             R3, 0   # 0x0a08
        C_MOV            R10, R4   # 0x0a0c
        C_SHLI           R10, 1   # 0x0a0e
        MOVI             R15, 0   # 0x0a10
        ST_LOCAL         R0, 12   # 0x0a14
        C_MOV            R0, R9   # 0x0a18
        C_MOV            R9, R4   # 0x0a1a
        MOVI             R4, 255   # 0x0a1c
        MOVI48           R6, 4294901760   # 0x0a20
L0a26:  C_CHWIDTH        R5, 0   # 0x0a26
        ADD              R13, R9, R15, R9   # 0x0a28
        MUL_LO           R11, R7, R13, R13   # 0x0a2c
        SRAI             R8, R11, 31   # 0x0a30
        SHRI             R8, R8, 16   # 0x0a34
        MADLO            R7, R7, R13, R8   # 0x0a38
        C_AND            R7, R6   # 0x0a3c
        SUB              R7, R11, R7, R11   # 0x0a3e
        LD_LOCAL         R1, 12   # 0x0a42
        ADD              R8, R1, R3, R1   # 0x0a46
        ADD              R11, R13, R7, R13   # 0x0a4a
        C_CHWIDTH        R11, 1   # 0x0a4e
        ST_GLOBAL_IDX    R11, R2, R8, 0, 0   # 0x0a50
        C_CHWIDTH        R11, 0   # 0x0a54
        ADDI             R11, R13, 1   # 0x0a56
        MUL_LO           R5, R7, R11, R11   # 0x0a5a
        SRAI             R1, R5, 31   # 0x0a5e
        SHRI             R1, R1, 16   # 0x0a62
        MAD_ACC          R1, R7, R11   # 0x0a66
        ADD              R11, R0, R3, R0   # 0x0a68
        C_MOV            R14, R12   # 0x0a6c
        ADD              R12, R10, R3, R10   # 0x0a6e
        ADD              R7, R12, R7, R12   # 0x0a72
        C_CHWIDTH        R7, 1   # 0x0a76
        AND              R7, R7, R4, R7   # 0x0a78
        ST_GLOBAL_IDX    R7, R2, R11, 0, 0   # 0x0a7c
        C_CHWIDTH        R7, 0   # 0x0a80
        C_AND            R1, R6   # 0x0a82
        SUB              R7, R5, R1, R5   # 0x0a84
        ADDI             R1, R8, 2   # 0x0a88
        ADD              R5, R13, R7, R13   # 0x0a8c
        C_CHWIDTH        R5, 1   # 0x0a90
        ADDI             R5, R5, 1   # 0x0a92
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0a96
        ADD              R1, R12, R7, R12   # 0x0a9a
        C_MOV            R12, R14   # 0x0a9e
        ADDI             R5, R1, 2   # 0x0aa0
        AND              R5, R5, R4, R5   # 0x0aa4
        ADDI             R1, R11, 2   # 0x0aa8
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0aac
        C_ADDI           R3, 4   # 0x0ab0
        C_ADDI           R15, 2   # 0x0ab2
        SETP_NE_NP       P0, R1, R12, R15   # 0x0ab4
        BRA_PRED         0, L0a26   # 0x0ab8
        C_ADD            R9, R15   # 0x0abc
        LD_LOCAL         R8, 36   # 0x0abe
        LD_LOCAL         R10, 16   # 0x0ac2
        LD_LOCAL         R11, 40   # 0x0ac6
        LD_LOCAL         R14, 44   # 0x0aca
        MOVI             R6, 255   # 0x0ace
        C_MOV            R4, R9   # 0x0ad2
        C_MOV            R9, R0   # 0x0ad4
        LD_LOCAL         R0, 12   # 0x0ad6
        LD_LOCAL         R13, 20   # 0x0ada
L0ade:  SETP_EQ_NPI      P0, R1, R14, 0   # 0x0ade
        BRA_PRED         0, L09de   # 0x0ae2
        C_CHWIDTH        R5, 0   # 0x0ae6
        MUL_LO           R1, R13, R8, R8   # 0x0ae8
        MUL_LO           R3, R7, R4, R4   # 0x0aec
        SRAI             R5, R3, 31   # 0x0af0
        SHRI             R5, R5, 16   # 0x0af4
        MAD_ACC          R5, R7, R4   # 0x0af8
        MOVI48           R7, 4294901760   # 0x0afa
        C_AND            R5, R7   # 0x0b00
        SUB              R7, R3, R5, R3   # 0x0b02
        LD_LOCAL         R3, 24   # 0x0b06
        LD_LOCAL         R5, 32   # 0x0b0a
        C_ADD            R3, R5   # 0x0b0e
        ADD              R1, R15, R1, R15   # 0x0b10
        C_SHLI           R1, 1   # 0x0b14
        ADD              R1, R3, R1, R3   # 0x0b16
        LD_LOCAL         R3, 28   # 0x0b1a
        ADD              R3, R1, R3, R1   # 0x0b1e
        ADD              R5, R7, R4, R7   # 0x0b22
        C_MOV            R15, R5   # 0x0b26
        C_CHWIDTH        R15, 1   # 0x0b28
        ST_GLOBAL_IDX    R15, R2, R3, 0, 0   # 0x0b2a
        ADD              R3, R5, R4, R5   # 0x0b2e
        C_CHWIDTH        R5, 1   # 0x0b32
        AND              R5, R3, R6, R3   # 0x0b34
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0b38
        C_ADDI           R4, 1   # 0x0b3c
        BRA              L09de   # 0x0b3e
L0b42:  C_CHWIDTH        R15, 0   # 0x0b42
        LD_LOCAL         R0, 24   # 0x0b44
        LD_LOCAL         R1, 32   # 0x0b48
        C_ADD            R0, R1   # 0x0b4c
        LD_LOCAL         R14, 60   # 0x0b4e
        ADD              R1, R14, R0, R14   # 0x0b52
        OR               R3, R14, R0, R14   # 0x0b56
        C_ANDN           R3, R1   # 0x0b5a
        AND              R4, R14, R0, R14   # 0x0b5c
        OR               R3, R4, R3, R4   # 0x0b60
        LD_LOCAL         R4, 28   # 0x0b64
        C_ADD            R0, R4   # 0x0b68
        ADD              R4, R0, R4, R0   # 0x0b6a
        ADD              R5, R14, R4, R14   # 0x0b6e
        C_NEG            R5, R5   # 0x0b72
        C_ANDI           R5, 3   # 0x0b74
        C_ADD            R4, R5   # 0x0b76
        ADD              R5, R14, R0, R14   # 0x0b78
        OR               R6, R14, R0, R14   # 0x0b7c
        C_ANDN           R6, R5   # 0x0b80
        AND              R0, R14, R0, R14   # 0x0b82
        C_OR             R0, R6   # 0x0b86
        LD_LOCAL         R6, 52   # 0x0b88
        LD_LOCAL         R7, 56   # 0x0b8c
        ST_GLOBAL_IDX    R1, R7, R6, 0, 8   # 0x0b90
        ST_GLOBAL_IDX    R5, R7, R6, 0, 16   # 0x0b94
        SHRI             R1, R3, 31   # 0x0b98
        SHRI             R2, R2, 16   # 0x0b9c
        ADD              R1, R2, R1, R2   # 0x0ba0
        ST_GLOBAL_IDX    R1, R7, R6, 0, 12   # 0x0ba4
        SHRI             R0, R0, 31   # 0x0ba8
        ADD              R0, R2, R0, R2   # 0x0bac
        ST_GLOBAL_IDX    R0, R7, R6, 0, 20   # 0x0bb0
        ADD              R0, R14, R4, R14   # 0x0bb4
        ST_GLOBAL_IDX    R0, R7, R6, 0, 24   # 0x0bb8
        OR               R1, R14, R4, R14   # 0x0bbc
        ANDN             R0, R1, R0, R1   # 0x0bc0
        AND              R1, R14, R4, R14   # 0x0bc4
        OR               R0, R1, R0, R1   # 0x0bc8
        SHRI             R0, R0, 31   # 0x0bcc
        ADD              R0, R2, R0, R2   # 0x0bd0
        ST_GLOBAL_IDX    R0, R7, R6, 0, 28   # 0x0bd4
        ST_GLOBAL_IDX    R8, R7, R6, 0, 0   # 0x0bd8
        LD_LOCAL         R14, 48   # 0x0bdc
        C_MOV            R1, R8   # 0x0be0
        C_RET            224   # 0x0be2
        ST_LOCAL         R14, 12   # 0x0be4
        MOVI             R0, 0   # 0x0be8
        ST_LOCAL         R1, 16   # 0x0bec
        ADDI             R5, R1, -1   # 0x0bf0
        SETP_LT_U_NPI    P0, R6, R5, 2   # 0x0bf4
        BRA_PRED         0, L0d18   # 0x0bf8
        MOVI             R9, 0   # 0x0bfc
        MOVI             R6, 2   # 0x0c00
        MOVI             R7, 65535   # 0x0c04
        MOVI             R10, 0   # 0x0c08
        MOVI             R8, 0   # 0x0c0c
        C_BRA            L0c4e   # 0x0c10
L0c12:  MOVI             R8, 8   # 0x0c12
        MOVI             R9, 96   # 0x0c16
L0c1a:  C_CHWIDTH        R14, 0   # 0x0c1a
        ANDI             R1, R2, 24   # 0x0c1c
        ADD              R1, R9, R1, R9   # 0x0c20
        LD_GLOBAL        R14, R6, 28   # 0x0c24
        LD_GLOBAL_IDX    R15, R14, R1, 0, 0   # 0x0c28
        LD_GLOBAL_IDX    R1, R14, R1, 0, 4   # 0x0c2c
        SHLI             R1, R1, 16   # 0x0c30
        SHRI             R14, R15, 16   # 0x0c34
        OR               R9, R1, R14, R1   # 0x0c38
        AND              R10, R15, R7, R15   # 0x0c3c
        ADD              R1, R0, R8, R0   # 0x0c40
        C_ADDI           R1, 1   # 0x0c44
        SETP_LT_U_NP     P0, R1, R1, R5   # 0x0c46
        BRA_PRED         4, L0d18   # 0x0c4a
L0c4e:  SETP_EQ_NPI      P0, R11, R8, 0   # 0x0c4e
        BRA_PRED         0, L0cd4   # 0x0c52
        SETP_LT_U_NPI    P0, R11, R8, 4   # 0x0c56
        BRA_PRED         0, L0cc0   # 0x0c5a
        ADD              R11, R4, R0, R4   # 0x0c5e
        MOVI             R12, 0   # 0x0c62
L0c66:  C_CHWIDTH        R1, 0   # 0x0c66
        C_CHWIDTH        R14, 2   # 0x0c68
        ADD              R13, R11, R12, R11   # 0x0c6a
        ADD              R15, R12, R10, R12   # 0x0c6e
        LD_GLOBAL_IDX    R14, R9, R15, 0, 0   # 0x0c72
        ST_GLOBAL_IDX    R14, R3, R13, 0, 0   # 0x0c76
        C_CHWIDTH        R14, 0   # 0x0c7a
        ADDI             R14, R15, 1   # 0x0c7c
        C_CHWIDTH        R14, 2   # 0x0c80
        LD_GLOBAL_IDX    R14, R9, R14, 0, 0   # 0x0c82
        ADDI             R1, R13, 1   # 0x0c86
        ST_GLOBAL_IDX    R14, R3, R1, 0, 0   # 0x0c8a
        C_CHWIDTH        R14, 0   # 0x0c8e
        ADDI             R1, R15, 2   # 0x0c90
        C_CHWIDTH        R1, 2   # 0x0c94
        LD_GLOBAL_IDX    R1, R9, R1, 0, 0   # 0x0c96
        ADDI             R14, R13, 2   # 0x0c9a
        ST_GLOBAL_IDX    R1, R3, R14, 0, 0   # 0x0c9e
        C_CHWIDTH        R1, 0   # 0x0ca2
        ADDI             R1, R15, 3   # 0x0ca4
        C_CHWIDTH        R1, 2   # 0x0ca8
        LD_GLOBAL_IDX    R1, R9, R1, 0, 0   # 0x0caa
        ADDI             R14, R13, 3   # 0x0cae
        ST_GLOBAL_IDX    R1, R3, R14, 0, 0   # 0x0cb2
        C_ADDI           R12, 4   # 0x0cb6
        SETP_NE_NP       P0, R1, R8, R12   # 0x0cb8
        BRA_PRED         0, L0c66   # 0x0cbc
L0cc0:  C_CHWIDTH        R1, 0   # 0x0cc0
        C_ADD            R0, R8   # 0x0cc2
        ADD              R1, R0, R4, R0   # 0x0cc4
        MOVI             R14, 44   # 0x0cc8
        C_CHWIDTH        R14, 2   # 0x0ccc
        ST_GLOBAL_IDX    R14, R3, R1, 0, 0   # 0x0cce
        C_ADDI           R0, 1   # 0x0cd2
L0cd4:  C_CHWIDTH        R2, 1   # 0x0cd4
        ADDI             R2, R2, 1   # 0x0cd6
        C_CHWIDTH        R2, 0   # 0x0cda
        ANDI             R10, R2, 7   # 0x0cdc
        MOVI             R8, 4   # 0x0ce0
        SETP_LT_NP       P0, R1, R8, R10   # 0x0ce4
        BRA_PRED         0, L0d02   # 0x0ce8
        MOVI             R9, 0   # 0x0cec
        SETP_LT_U_NPI    P0, R1, R10, 3   # 0x0cf0
        BRA_PRED         0, L0c1a   # 0x0cf4
        MOVI             R8, 8   # 0x0cf8
        MOVI             R9, 32   # 0x0cfc
        C_BRA            L0c1a   # 0x0d00
L0d02:  ADDI             R1, R10, -5   # 0x0d02
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x0d06
        BRA_PRED         4, L0c12   # 0x0d0a
        MOVI             R8, 8   # 0x0d0e
        MOVI             R9, 64   # 0x0d12
        C_BRA            L0c1a   # 0x0d16
L0d18:  LD_LOCAL         R1, 16   # 0x0d18
        SETP_LE_U_NP     P0, R2, R1, R0   # 0x0d1c
        BRA_PRED         0, L0dc2   # 0x0d20
        SUB              R2, R1, R0, R1   # 0x0d24
        ANDI             R5, R2, 7   # 0x0d28
        SETP_EQ_NPI      P0, R2, R5, 0   # 0x0d2c
        C_MOV            R2, R0   # 0x0d30
        BRA_PRED         0, L0d54   # 0x0d32
        MOVI             R6, 0   # 0x0d36
        C_CHWIDTH        R6, 2   # 0x0d3a
        C_MOV            R2, R0   # 0x0d3c
L0d3e:  ADD              R7, R4, R2, R4   # 0x0d3e
        ST_GLOBAL_IDX    R6, R3, R7, 0, 0   # 0x0d42
        C_ADDI           R2, 1   # 0x0d46
        ADDI             R5, R5, -1   # 0x0d48
        SETP_NE_NPI      P0, R7, R5, 0   # 0x0d4c
        BRA_PRED         0, L0d3e   # 0x0d50
L0d54:  C_SUB            R0, R1   # 0x0d54
        MOVI48           R5, 4294967288   # 0x0d56
        SETP_LT_U_NP     P0, R0, R5, R0   # 0x0d5c
        BRA_PRED         0, L0dc2   # 0x0d60
        CHWIDTH_MULTI    64, 0   # 0x0d64
        ADDI             R0, R2, 7   # 0x0d68
        C_NEG            R1, R1   # 0x0d6c
        MOVI             R2, 0   # 0x0d6e
        C_CHWIDTH        R2, 2   # 0x0d72
L0d74:  ADD              R5, R4, R0, R4   # 0x0d74
        ADDI             R6, R5, -7   # 0x0d78
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0d7c
        ADDI             R6, R5, -6   # 0x0d80
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0d84
        ADDI             R6, R5, -5   # 0x0d88
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0d8c
        ADDI             R6, R5, -4   # 0x0d90
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0d94
        ADDI             R6, R5, -3   # 0x0d98
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0d9c
        ADDI             R6, R5, -2   # 0x0da0
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0da4
        ADDI             R6, R5, -1   # 0x0da8
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0dac
        ST_GLOBAL_IDX    R2, R3, R5, 0, 0   # 0x0db0
        C_ADDI           R0, 8   # 0x0db4
        ADD              R5, R1, R0, R1   # 0x0db6
        SETP_NE_NPI      P0, R5, R5, 7   # 0x0dba
        BRA_PRED         0, L0d74   # 0x0dbe
L0dc2:  CHWIDTH_MULTI    68, 0   # 0x0dc2
        LD_LOCAL         R14, 12   # 0x0dc6
        C_RET            224   # 0x0dca
        CHWIDTH_MULTI    17, 1   # 0x0dcc
        XOR              R0, R1, R2, R1   # 0x0dd0
        C_CHWIDTH        R0, 0   # 0x0dd4
        C_ANDI           R0, 1   # 0x0dd6
        SETP_NE_NPI      P0, R0, R0, 0   # 0x0dd8
        MOVI             R0, 40961   # 0x0ddc
        SHRI             R2, R2, 1   # 0x0de0
        C_MOV            R3, R2   # 0x0de4
        C_CHWIDTH        R2, 1   # 0x0de6
        XOR              R2, R2, R0, R2   # 0x0de8
        C_CHWIDTH        R2, 0   # 0x0dec
        MOV_P            R3, 0, R2, R2, R2   # 0x0dee
        SHRI             R2, R1, 1   # 0x0df2
        C_CHWIDTH        R2, 1   # 0x0df6
        XOR              R2, R2, R3, R2   # 0x0df8
        C_CHWIDTH        R2, 0   # 0x0dfc
        C_ANDI           R2, 1   # 0x0dfe
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e00
        SHRI             R2, R3, 1   # 0x0e04
        C_MOV            R3, R2   # 0x0e08
        C_CHWIDTH        R2, 1   # 0x0e0a
        XOR              R2, R2, R0, R2   # 0x0e0c
        C_CHWIDTH        R2, 0   # 0x0e10
        MOV_P            R3, 0, R2, R2, R2   # 0x0e12
        SHRI             R2, R1, 2   # 0x0e16
        C_CHWIDTH        R2, 1   # 0x0e1a
        XOR              R2, R2, R3, R2   # 0x0e1c
        C_CHWIDTH        R2, 0   # 0x0e20
        C_ANDI           R2, 1   # 0x0e22
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e24
        SHRI             R2, R3, 1   # 0x0e28
        C_MOV            R3, R2   # 0x0e2c
        C_CHWIDTH        R2, 1   # 0x0e2e
        XOR              R2, R2, R0, R2   # 0x0e30
        C_CHWIDTH        R2, 0   # 0x0e34
        MOV_P            R3, 0, R2, R2, R2   # 0x0e36
        SHRI             R2, R1, 3   # 0x0e3a
        C_CHWIDTH        R2, 1   # 0x0e3e
        XOR              R2, R2, R3, R2   # 0x0e40
        C_CHWIDTH        R2, 0   # 0x0e44
        C_ANDI           R2, 1   # 0x0e46
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e48
        SHRI             R2, R3, 1   # 0x0e4c
        C_MOV            R3, R2   # 0x0e50
        C_CHWIDTH        R2, 1   # 0x0e52
        XOR              R2, R2, R0, R2   # 0x0e54
        C_CHWIDTH        R2, 0   # 0x0e58
        MOV_P            R3, 0, R2, R2, R2   # 0x0e5a
        SHRI             R2, R1, 4   # 0x0e5e
        C_CHWIDTH        R2, 1   # 0x0e62
        XOR              R2, R2, R3, R2   # 0x0e64
        C_CHWIDTH        R2, 0   # 0x0e68
        C_ANDI           R2, 1   # 0x0e6a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e6c
        SHRI             R2, R3, 1   # 0x0e70
        C_MOV            R3, R2   # 0x0e74
        C_CHWIDTH        R2, 1   # 0x0e76
        XOR              R2, R2, R0, R2   # 0x0e78
        C_CHWIDTH        R2, 0   # 0x0e7c
        MOV_P            R3, 0, R2, R2, R2   # 0x0e7e
        SHRI             R2, R1, 5   # 0x0e82
        C_CHWIDTH        R2, 1   # 0x0e86
        XOR              R2, R2, R3, R2   # 0x0e88
        C_CHWIDTH        R2, 0   # 0x0e8c
        C_ANDI           R2, 1   # 0x0e8e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e90
        SHRI             R2, R3, 1   # 0x0e94
        C_MOV            R3, R2   # 0x0e98
        C_CHWIDTH        R2, 1   # 0x0e9a
        XOR              R2, R2, R0, R2   # 0x0e9c
        C_CHWIDTH        R2, 0   # 0x0ea0
        MOV_P            R3, 0, R2, R2, R2   # 0x0ea2
        SHRI             R2, R1, 6   # 0x0ea6
        C_CHWIDTH        R2, 1   # 0x0eaa
        XOR              R2, R2, R3, R2   # 0x0eac
        C_CHWIDTH        R2, 0   # 0x0eb0
        C_ANDI           R2, 1   # 0x0eb2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0eb4
        SHRI             R2, R3, 1   # 0x0eb8
        C_MOV            R3, R2   # 0x0ebc
        C_CHWIDTH        R2, 1   # 0x0ebe
        XOR              R2, R2, R0, R2   # 0x0ec0
        C_CHWIDTH        R2, 0   # 0x0ec4
        MOV_P            R3, 0, R2, R2, R2   # 0x0ec6
        MOVI             R2, 128   # 0x0eca
        AND              R4, R1, R2, R1   # 0x0ece
        C_CHWIDTH        R2, 1   # 0x0ed2
        C_CHWIDTH        R4, 0   # 0x0ed4
        SHRI             R4, R4, 7   # 0x0ed6
        ANDI             R5, R3, 1   # 0x0eda
        SETP_EQ_NP       P0, R4, R4, R5   # 0x0ede
        SHRI             R3, R3, 1   # 0x0ee2
        C_MOV            R4, R3   # 0x0ee6
        C_CHWIDTH        R3, 1   # 0x0ee8
        XOR              R3, R3, R0, R3   # 0x0eea
        C_CHWIDTH        R3, 0   # 0x0eee
        MOV_P            R3, 0, R4, R4, R4   # 0x0ef0
        SHRI             R4, R1, 8   # 0x0ef4
        C_CHWIDTH        R4, 1   # 0x0ef8
        XOR              R4, R3, R4, R3   # 0x0efa
        C_CHWIDTH        R4, 0   # 0x0efe
        C_ANDI           R4, 1   # 0x0f00
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f02
        SHRI             R3, R3, 1   # 0x0f06
        C_MOV            R4, R3   # 0x0f0a
        C_CHWIDTH        R3, 1   # 0x0f0c
        XOR              R3, R3, R0, R3   # 0x0f0e
        C_CHWIDTH        R3, 0   # 0x0f12
        MOV_P            R4, 0, R3, R3, R3   # 0x0f14
        SHRI             R3, R1, 9   # 0x0f18
        C_CHWIDTH        R3, 1   # 0x0f1c
        XOR              R3, R3, R4, R3   # 0x0f1e
        C_CHWIDTH        R3, 0   # 0x0f22
        C_ANDI           R3, 1   # 0x0f24
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f26
        SHRI             R3, R4, 1   # 0x0f2a
        C_MOV            R4, R3   # 0x0f2e
        C_CHWIDTH        R3, 1   # 0x0f30
        XOR              R3, R3, R0, R3   # 0x0f32
        C_CHWIDTH        R3, 0   # 0x0f36
        MOV_P            R4, 0, R3, R3, R3   # 0x0f38
        SHRI             R3, R1, 10   # 0x0f3c
        C_CHWIDTH        R3, 1   # 0x0f40
        XOR              R3, R3, R4, R3   # 0x0f42
        C_CHWIDTH        R3, 0   # 0x0f46
        C_ANDI           R3, 1   # 0x0f48
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f4a
        SHRI             R3, R4, 1   # 0x0f4e
        C_MOV            R4, R3   # 0x0f52
        C_CHWIDTH        R3, 1   # 0x0f54
        XOR              R3, R3, R0, R3   # 0x0f56
        C_CHWIDTH        R3, 0   # 0x0f5a
        MOV_P            R4, 0, R3, R3, R3   # 0x0f5c
        SHRI             R3, R1, 11   # 0x0f60
        C_CHWIDTH        R3, 1   # 0x0f64
        XOR              R3, R3, R4, R3   # 0x0f66
        C_CHWIDTH        R3, 0   # 0x0f6a
        C_ANDI           R3, 1   # 0x0f6c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f6e
        SHRI             R3, R4, 1   # 0x0f72
        C_MOV            R4, R3   # 0x0f76
        C_CHWIDTH        R3, 1   # 0x0f78
        XOR              R3, R3, R0, R3   # 0x0f7a
        C_CHWIDTH        R3, 0   # 0x0f7e
        MOV_P            R4, 0, R3, R3, R3   # 0x0f80
        SHRI             R3, R1, 12   # 0x0f84
        C_CHWIDTH        R3, 1   # 0x0f88
        XOR              R3, R3, R4, R3   # 0x0f8a
        C_CHWIDTH        R3, 0   # 0x0f8e
        C_ANDI           R3, 1   # 0x0f90
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f92
        SHRI             R3, R4, 1   # 0x0f96
        C_MOV            R4, R3   # 0x0f9a
        C_CHWIDTH        R3, 1   # 0x0f9c
        XOR              R3, R3, R0, R3   # 0x0f9e
        C_CHWIDTH        R3, 0   # 0x0fa2
        MOV_P            R4, 0, R3, R3, R3   # 0x0fa4
        SHRI             R3, R1, 13   # 0x0fa8
        C_CHWIDTH        R3, 1   # 0x0fac
        XOR              R3, R3, R4, R3   # 0x0fae
        C_CHWIDTH        R3, 0   # 0x0fb2
        C_ANDI           R3, 1   # 0x0fb4
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fb6
        SHRI             R3, R4, 1   # 0x0fba
        C_MOV            R4, R3   # 0x0fbe
        C_CHWIDTH        R3, 1   # 0x0fc0
        XOR              R3, R3, R0, R3   # 0x0fc2
        C_CHWIDTH        R3, 0   # 0x0fc6
        MOV_P            R4, 0, R3, R3, R3   # 0x0fc8
        SHRI             R3, R1, 14   # 0x0fcc
        C_CHWIDTH        R3, 1   # 0x0fd0
        XOR              R3, R3, R4, R3   # 0x0fd2
        C_CHWIDTH        R3, 0   # 0x0fd6
        C_ANDI           R3, 1   # 0x0fd8
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fda
        SHRI             R3, R4, 1   # 0x0fde
        C_MOV            R4, R3   # 0x0fe2
        C_CHWIDTH        R3, 1   # 0x0fe4
        XOR              R3, R3, R0, R3   # 0x0fe6
        C_CHWIDTH        R3, 0   # 0x0fea
        MOV_P            R4, 0, R3, R3, R3   # 0x0fec
        SHRI             R3, R1, 15   # 0x0ff0
        ANDI             R5, R4, 1   # 0x0ff4
        SETP_EQ_NP       P0, R3, R3, R5   # 0x0ff8
        C_CHWIDTH        R5, 1   # 0x0ffc
        SHRI             R3, R4, 1   # 0x0ffe
        C_MOV            R4, R3   # 0x1002
        XOR              R5, R3, R0, R3   # 0x1004
        C_CHWIDTH        R5, 0   # 0x1008
        MOV_P            R5, 0, R4, R4, R4   # 0x100a
        C_CHWIDTH        R4, 1   # 0x100e
        SHRI             R3, R1, 16   # 0x1010
        XOR              R4, R5, R3, R5   # 0x1014
        C_CHWIDTH        R4, 0   # 0x1018
        C_ANDI           R4, 1   # 0x101a
        SETP_NE_NPI      P0, R4, R4, 0   # 0x101c
        SHRI             R4, R5, 1   # 0x1020
        C_MOV            R5, R4   # 0x1024
        C_CHWIDTH        R4, 1   # 0x1026
        XOR              R4, R4, R0, R4   # 0x1028
        C_CHWIDTH        R4, 0   # 0x102c
        MOV_P            R5, 0, R4, R4, R4   # 0x102e
        SHRI             R4, R1, 17   # 0x1032
        C_XOR            R4, R5   # 0x1036
        C_ANDI           R4, 1   # 0x1038
        SETP_NE_NPI      P0, R4, R4, 0   # 0x103a
        SHRI             R4, R5, 1   # 0x103e
        C_MOV            R5, R4   # 0x1042
        C_CHWIDTH        R4, 1   # 0x1044
        XOR              R4, R4, R0, R4   # 0x1046
        C_CHWIDTH        R4, 0   # 0x104a
        MOV_P            R5, 0, R4, R4, R4   # 0x104c
        SHRI             R4, R1, 18   # 0x1050
        C_XOR            R4, R5   # 0x1054
        C_ANDI           R4, 1   # 0x1056
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1058
        SHRI             R4, R5, 1   # 0x105c
        C_MOV            R5, R4   # 0x1060
        C_CHWIDTH        R4, 1   # 0x1062
        XOR              R4, R4, R0, R4   # 0x1064
        C_CHWIDTH        R4, 0   # 0x1068
        MOV_P            R5, 0, R4, R4, R4   # 0x106a
        SHRI             R4, R1, 19   # 0x106e
        C_XOR            R4, R5   # 0x1072
        C_ANDI           R4, 1   # 0x1074
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1076
        SHRI             R4, R5, 1   # 0x107a
        C_MOV            R5, R4   # 0x107e
        C_CHWIDTH        R4, 1   # 0x1080
        XOR              R4, R4, R0, R4   # 0x1082
        C_CHWIDTH        R4, 0   # 0x1086
        MOV_P            R5, 0, R4, R4, R4   # 0x1088
        SHRI             R4, R1, 20   # 0x108c
        C_XOR            R4, R5   # 0x1090
        C_ANDI           R4, 1   # 0x1092
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1094
        SHRI             R4, R5, 1   # 0x1098
        C_MOV            R5, R4   # 0x109c
        C_CHWIDTH        R4, 1   # 0x109e
        XOR              R4, R4, R0, R4   # 0x10a0
        C_CHWIDTH        R4, 0   # 0x10a4
        MOV_P            R5, 0, R4, R4, R4   # 0x10a6
        SHRI             R4, R1, 21   # 0x10aa
        C_XOR            R4, R5   # 0x10ae
        C_ANDI           R4, 1   # 0x10b0
        SETP_NE_NPI      P0, R4, R4, 0   # 0x10b2
        SHRI             R4, R5, 1   # 0x10b6
        C_MOV            R5, R4   # 0x10ba
        C_CHWIDTH        R4, 1   # 0x10bc
        XOR              R4, R4, R0, R4   # 0x10be
        C_CHWIDTH        R4, 0   # 0x10c2
        MOV_P            R5, 0, R4, R4, R4   # 0x10c4
        SHRI             R4, R1, 22   # 0x10c8
        C_XOR            R4, R5   # 0x10cc
        C_ANDI           R4, 1   # 0x10ce
        SETP_NE_NPI      P0, R4, R4, 0   # 0x10d0
        SHRI             R4, R5, 1   # 0x10d4
        C_MOV            R5, R4   # 0x10d8
        C_CHWIDTH        R4, 1   # 0x10da
        XOR              R4, R4, R0, R4   # 0x10dc
        C_CHWIDTH        R4, 0   # 0x10e0
        MOV_P            R5, 0, R4, R4, R4   # 0x10e2
        AND              R2, R3, R2, R3   # 0x10e6
        C_CHWIDTH        R2, 0   # 0x10ea
        SHRI             R2, R2, 7   # 0x10ec
        ANDI             R3, R5, 1   # 0x10f0
        SETP_EQ_NP       P0, R2, R2, R3   # 0x10f4
        SHRI             R2, R5, 1   # 0x10f8
        C_MOV            R3, R2   # 0x10fc
        C_CHWIDTH        R2, 1   # 0x10fe
        XOR              R2, R2, R0, R2   # 0x1100
        C_CHWIDTH        R2, 0   # 0x1104
        MOV_P            R2, 0, R3, R3, R3   # 0x1106
        SHRI             R3, R1, 24   # 0x110a
        XOR              R3, R2, R3, R2   # 0x110e
        C_ANDI           R3, 1   # 0x1112
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1114
        SHRI             R2, R2, 1   # 0x1118
        C_MOV            R3, R2   # 0x111c
        C_CHWIDTH        R2, 1   # 0x111e
        XOR              R2, R2, R0, R2   # 0x1120
        C_CHWIDTH        R2, 0   # 0x1124
        MOV_P            R3, 0, R2, R2, R2   # 0x1126
        SHRI             R2, R1, 25   # 0x112a
        C_XOR            R2, R3   # 0x112e
        C_ANDI           R2, 1   # 0x1130
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1132
        SHRI             R2, R3, 1   # 0x1136
        C_MOV            R3, R2   # 0x113a
        C_CHWIDTH        R2, 1   # 0x113c
        XOR              R2, R2, R0, R2   # 0x113e
        C_CHWIDTH        R2, 0   # 0x1142
        MOV_P            R3, 0, R2, R2, R2   # 0x1144
        SHRI             R2, R1, 26   # 0x1148
        C_XOR            R2, R3   # 0x114c
        C_ANDI           R2, 1   # 0x114e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1150
        SHRI             R2, R3, 1   # 0x1154
        C_MOV            R3, R2   # 0x1158
        C_CHWIDTH        R2, 1   # 0x115a
        XOR              R2, R2, R0, R2   # 0x115c
        C_CHWIDTH        R2, 0   # 0x1160
        MOV_P            R3, 0, R2, R2, R2   # 0x1162
        SHRI             R2, R1, 27   # 0x1166
        C_XOR            R2, R3   # 0x116a
        C_ANDI           R2, 1   # 0x116c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x116e
        SHRI             R2, R3, 1   # 0x1172
        C_MOV            R3, R2   # 0x1176
        C_CHWIDTH        R2, 1   # 0x1178
        XOR              R2, R2, R0, R2   # 0x117a
        C_CHWIDTH        R2, 0   # 0x117e
        MOV_P            R3, 0, R2, R2, R2   # 0x1180
        SHRI             R2, R1, 28   # 0x1184
        C_XOR            R2, R3   # 0x1188
        C_ANDI           R2, 1   # 0x118a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x118c
        SHRI             R2, R3, 1   # 0x1190
        C_MOV            R3, R2   # 0x1194
        C_CHWIDTH        R2, 1   # 0x1196
        XOR              R2, R2, R0, R2   # 0x1198
        C_CHWIDTH        R2, 0   # 0x119c
        MOV_P            R3, 0, R2, R2, R2   # 0x119e
        SHRI             R2, R1, 29   # 0x11a2
        C_XOR            R2, R3   # 0x11a6
        C_ANDI           R2, 1   # 0x11a8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11aa
        SHRI             R2, R3, 1   # 0x11ae
        C_MOV            R3, R2   # 0x11b2
        C_CHWIDTH        R2, 1   # 0x11b4
        XOR              R2, R2, R0, R2   # 0x11b6
        C_CHWIDTH        R2, 0   # 0x11ba
        MOV_P            R3, 0, R2, R2, R2   # 0x11bc
        SHRI             R2, R1, 30   # 0x11c0
        C_XOR            R2, R3   # 0x11c4
        C_ANDI           R2, 1   # 0x11c6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11c8
        SHRI             R2, R3, 1   # 0x11cc
        C_MOV            R3, R2   # 0x11d0
        C_CHWIDTH        R2, 1   # 0x11d2
        XOR              R2, R2, R0, R2   # 0x11d4
        C_CHWIDTH        R0, 1   # 0x11d8
        C_CHWIDTH        R2, 0   # 0x11da
        MOV_P            R3, 0, R2, R2, R2   # 0x11dc
        SHRI             R1, R1, 31   # 0x11e0
        ANDI             R2, R3, 1   # 0x11e4
        SETP_EQ_NP       P0, R1, R1, R2   # 0x11e8
        SHRI             R1, R3, 1   # 0x11ec
        C_MOV            R2, R1   # 0x11f0
        XOR              R0, R1, R0, R1   # 0x11f2
        C_CHWIDTH        R0, 0   # 0x11f6
        MOV_P            R0, 0, R2, R2, R2   # 0x11f8
        MOVI             R1, 65535   # 0x11fc
        AND              R1, R0, R1, R0   # 0x1200
        C_RET            224   # 0x1204
        MOVI             R15, 2   # 0x1206
        LD_GLOBAL        R15, R15, 24   # 0x120a
        SRD              R0, 2   # 0x120e
        C_ADD            R15, R0   # 0x1210
        ST_LOCAL         R8, 60   # 0x1212
        ST_LOCAL         R9, 64   # 0x1216
        ST_LOCAL         R10, 68   # 0x121a
        ST_LOCAL         R11, 72   # 0x121e
        ST_LOCAL         R12, 76   # 0x1222
        ST_LOCAL         R13, 80   # 0x1226
        ST_LOCAL         R14, 48   # 0x122a
        C_MOV            R13, R3   # 0x122e
        ST_LOCAL         R1, 36   # 0x1230
        MOVI             R1, 0   # 0x1234
        ST_GLOBAL        R1, R15, -8   # 0x1238
        ST_GLOBAL        R1, R15, -12   # 0x123c
        ST_GLOBAL        R1, R15, -16   # 0x1240
        ST_GLOBAL        R1, R15, -20   # 0x1244
        ST_GLOBAL        R1, R15, -24   # 0x1248
        ST_GLOBAL        R1, R15, -28   # 0x124c
        ST_GLOBAL        R1, R15, -32   # 0x1250
        MOVI             R0, 0   # 0x1254
        ST_LOCAL         R0, 44   # 0x1258
        C_CHWIDTH        R0, 2   # 0x125c
        ST_GLOBAL        R1, R15, -36   # 0x125e
        C_CHWIDTH        R1, 1   # 0x1262
        LD_GLOBAL_IDX    R0, R2, R13, 0, 0   # 0x1264
        C_CHWIDTH        R0, 0   # 0x1268
        LD_GLOBAL        R1, R15, -4   # 0x126a
        C_CHWIDTH        R1, 0   # 0x126e
        ST_LOCAL         R1, 52   # 0x1270
        C_MOV            R14, R0   # 0x1274
        ANDI             R0, R0, 255   # 0x1276
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x127a
        MOVI             R7, 0   # 0x127e
        MOVI             R0, 0   # 0x1282
        ST_LOCAL         R0, 20   # 0x1286
        ST_LOCAL         R0, 32   # 0x128a
        ST_LOCAL         R0, 12   # 0x128e
        ST_LOCAL         R0, 28   # 0x1292
        ST_LOCAL         R0, 24   # 0x1296
        ST_LOCAL         R5, 40   # 0x129a
        BRA_PRED         0, L1518   # 0x129e
        ST_LOCAL         R6, 56   # 0x12a2
        MOVI             R0, 255   # 0x12a6
        MOVI             R6, 3   # 0x12aa
        MOVI             R9, 5   # 0x12ae
        MOVI             R1, 0   # 0x12b2
        ST_LOCAL         R1, 16   # 0x12b6
        ST_LOCAL         R1, 20   # 0x12ba
        MOVI             R5, 0   # 0x12be
        ST_LOCAL         R1, 12   # 0x12c2
        ST_LOCAL         R1, 28   # 0x12c6
        ST_LOCAL         R1, 24   # 0x12ca
        ST_LOCAL         R1, 32   # 0x12ce
        C_MOV            R3, R14   # 0x12d2
        MOVI             R10, 0   # 0x12d4
        C_MOV            R11, R13   # 0x12d8
        C_BRA            L12de   # 0x12da
L12dc:  C_MOV            R11, R1   # 0x12dc
L12de:  C_CHWIDTH        R8, 1   # 0x12de
        AND              R8, R3, R0, R3   # 0x12e0
        C_CHWIDTH        R8, 0   # 0x12e4
        SETP_NE_NPI      P0, R1, R8, 44   # 0x12e6
        ADDI             R1, R11, 1   # 0x12ea
        BRA_PRED         0, L1316   # 0x12ee
L12f2:  LD_GLOBAL_IDX    R3, R15, R10, 1, -36   # 0x12f2
        C_ADDI           R3, 1   # 0x12f6
        ST_GLOBAL_IDX    R3, R15, R10, 1, -36   # 0x12f8
        C_CHWIDTH        R3, 2   # 0x12fc
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x12fe
        C_CHWIDTH        R3, 0   # 0x1302
        ANDI             R8, R3, 255   # 0x1304
        SETP_EQ_NPI      P0, R8, R8, 0   # 0x1308
        BRA_PRED         0, L1504   # 0x130c
        MOVI             R10, 0   # 0x1310
        C_BRA            L12dc   # 0x1314
L1316:  SETP_LT_NP       P0, R12, R6, R10   # 0x1316
        BRA_PRED         4, L1352   # 0x131a
        SETP_LT_NP       P0, R12, R9, R10   # 0x131e
        BRA_PRED         0, L1384   # 0x1322
        SETP_EQ_NPI      P0, R12, R10, 4   # 0x1326
        BRA_PRED         0, L1400   # 0x132a
        SETP_EQ_NPI      P0, R8, R10, 5   # 0x132e
        BRA_PRED         4, L14e4   # 0x1332
        MOVI             R8, 223   # 0x1336
        C_CHWIDTH        R8, 1   # 0x133a
        AND              R8, R3, R8, R3   # 0x133c
        C_CHWIDTH        R8, 0   # 0x1340
        SETP_NE_NPI      P0, R8, R8, 69   # 0x1342
        BRA_PRED         0, L1484   # 0x1346
        MOVI             R10, 3   # 0x134a
        BRA              L14a4   # 0x134e
L1352:  SETP_EQ_NPI      P0, R12, R10, 0   # 0x1352
        BRA_PRED         0, L13c2   # 0x1356
        SETP_EQ_NPI      P0, R12, R10, 2   # 0x135a
        BRA_PRED         0, L1432   # 0x135e
        SETP_EQ_NPI      P0, R3, R10, 3   # 0x1362
        BRA_PRED         4, L14e4   # 0x1366
        SETP_EQ_NPI      P0, R3, R8, 45   # 0x136a
        BRA_PRED         0, L137a   # 0x136e
        SETP_NE_NPI      P0, R3, R8, 43   # 0x1372
        BRA_PRED         0, L14c0   # 0x1376
L137a:  MOVI             R10, 6   # 0x137a
        C_ADDI           R5, 1   # 0x137e
        BRA              L14e4   # 0x1380
L1384:  SETP_EQ_NPI      P0, R8, R10, 6   # 0x1384
        BRA_PRED         0, L140e   # 0x1388
        SETP_EQ_NPI      P0, R8, R10, 7   # 0x138c
        BRA_PRED         4, L14e4   # 0x1390
        C_CHWIDTH        R3, 1   # 0x1394
        ADDI             R3, R3, -58   # 0x1396
        AND              R3, R3, R0, R3   # 0x139a
        C_CHWIDTH        R3, 0   # 0x139e
        MOVI             R8, 245   # 0x13a0
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x13a4
        MOVI             R10, 7   # 0x13a8
        BRA_PRED         0, L14e4   # 0x13ac
        MOVI             R10, 1   # 0x13b0
        LD_LOCAL         R3, 28   # 0x13b4
        C_ADDI           R3, 1   # 0x13b8
        ST_LOCAL         R3, 28   # 0x13ba
        BRA              L14e4   # 0x13be
L13c2:  C_CHWIDTH        R3, 1   # 0x13c2
        ADDI             R3, R3, -58   # 0x13c4
        AND              R3, R3, R0, R3   # 0x13c8
        C_CHWIDTH        R3, 0   # 0x13cc
        MOVI             R10, 245   # 0x13ce
        SETP_LT_U_NP     P0, R3, R10, R3   # 0x13d2
        MOVI             R10, 4   # 0x13d6
        BRA_PRED         0, L14d6   # 0x13da
        MOVI             R10, 2   # 0x13de
        SETP_EQ_NPI      P0, R3, R8, 43   # 0x13e2
        BRA_PRED         0, L14d6   # 0x13e6
        SETP_EQ_NPI      P0, R3, R8, 45   # 0x13ea
        BRA_PRED         0, L14d6   # 0x13ee
        SETP_NE_NPI      P0, R3, R8, 46   # 0x13f2
        BRA_PRED         0, L14c8   # 0x13f6
        MOVI             R10, 5   # 0x13fa
        C_BRA            L14d6   # 0x13fe
L1400:  SETP_NE_NPI      P0, R8, R8, 46   # 0x1400
        BRA_PRED         0, L1458   # 0x1404
        MOVI             R10, 5   # 0x1408
        C_BRA            L1478   # 0x140c
L140e:  C_CHWIDTH        R3, 1   # 0x140e
        ADDI             R3, R3, -58   # 0x1410
        AND              R3, R3, R0, R3   # 0x1414
        C_CHWIDTH        R3, 0   # 0x1418
        MOVI             R8, 246   # 0x141a
        SETP_LT_U_NP     P0, R3, R3, R8   # 0x141e
        MOVI             R10, 7   # 0x1422
        MOVI             R3, 1   # 0x1426
        MOV_P            R10, 0, R3, R3, R3   # 0x142a
        C_ADDI           R7, 1   # 0x142e
        C_BRA            L14e4   # 0x1430
L1432:  C_CHWIDTH        R3, 1   # 0x1432
        ADDI             R3, R3, -58   # 0x1434
        AND              R3, R3, R0, R3   # 0x1438
        C_CHWIDTH        R3, 0   # 0x143c
        MOVI             R10, 246   # 0x143e
        SETP_LT_U_NP     P0, R3, R3, R10   # 0x1442
        BRA_PRED         4, L14b0   # 0x1446
        SETP_EQ_NPI      P0, R3, R8, 46   # 0x144a
        MOVI             R10, 1   # 0x144e
        MOV_P            R10, 0, R9, R9, R9   # 0x1452
        C_BRA            L14b4   # 0x1456
L1458:  C_CHWIDTH        R3, 1   # 0x1458
        ADDI             R3, R3, -58   # 0x145a
        AND              R3, R3, R0, R3   # 0x145e
        C_CHWIDTH        R3, 0   # 0x1462
        MOVI             R8, 245   # 0x1464
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x1468
        MOVI             R10, 4   # 0x146c
        BRA_PRED         0, L14e4   # 0x1470
        MOVI             R10, 1   # 0x1474
L1478:  LD_LOCAL         R3, 20   # 0x1478
        C_ADDI           R3, 1   # 0x147c
        ST_LOCAL         R3, 20   # 0x147e
        C_BRA            L14e4   # 0x1482
L1484:  C_CHWIDTH        R3, 1   # 0x1484
        ADDI             R3, R3, -58   # 0x1486
        AND              R3, R3, R0, R3   # 0x148a
        C_CHWIDTH        R3, 0   # 0x148e
        MOVI             R8, 245   # 0x1490
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x1494
        MOVI             R10, 5   # 0x1498
        BRA_PRED         0, L14e4   # 0x149c
        MOVI             R10, 1   # 0x14a0
L14a4:  LD_LOCAL         R3, 16   # 0x14a4
        C_ADDI           R3, 1   # 0x14a8
        ST_LOCAL         R3, 16   # 0x14aa
        C_BRA            L14e4   # 0x14ae
L14b0:  MOVI             R10, 4   # 0x14b0
L14b4:  LD_LOCAL         R3, 12   # 0x14b4
        C_ADDI           R3, 1   # 0x14b8
        ST_LOCAL         R3, 12   # 0x14ba
        C_BRA            L14e4   # 0x14be
L14c0:  MOVI             R10, 1   # 0x14c0
        C_ADDI           R5, 1   # 0x14c4
        C_BRA            L14e4   # 0x14c6
L14c8:  MOVI             R10, 1   # 0x14c8
        LD_LOCAL         R3, 28   # 0x14cc
        C_ADDI           R3, 1   # 0x14d0
        ST_LOCAL         R3, 28   # 0x14d2
L14d6:  LD_LOCAL         R3, 32   # 0x14d6
        C_ADDI           R3, 1   # 0x14da
        ST_LOCAL         R3, 24   # 0x14dc
        ST_LOCAL         R3, 32   # 0x14e0
L14e4:  C_CHWIDTH        R3, 2   # 0x14e4
        LD_GLOBAL_IDX    R3, R2, R11, 0, 1   # 0x14e6
        C_CHWIDTH        R3, 0   # 0x14ea
        ANDI             R8, R3, 255   # 0x14ec
        SETP_EQ_NPI      P0, R8, R8, 0   # 0x14f0
        BRA_PRED         0, L12f2   # 0x14f4
        SETP_EQ_NPI      P0, R8, R10, 1   # 0x14f8
        BRA_PRED         4, L12dc   # 0x14fc
        BRA              L12f2   # 0x1500
L1504:  ST_LOCAL         R7, 44   # 0x1504
        ST_LOCAL         R5, 32   # 0x1508
        LD_LOCAL         R5, 40   # 0x150c
        LD_LOCAL         R7, 16   # 0x1510
        LD_LOCAL         R6, 56   # 0x1514
L1518:  C_CHWIDTH        R6, 1   # 0x1518
        LD_LOCAL         R1, 36   # 0x151a
        SETP_EQ_NPI      P0, R0, R1, 0   # 0x151e
        SHLI             R0, R2, 16   # 0x1522
        CVT_SEXT         R12, R6, R6, R6   # 0x1526
        C_CHWIDTH        R6, 0   # 0x152a
        ADD              R6, R13, R1, R13   # 0x152c
        SHRI             R8, R2, 16   # 0x1530
        BRA_PRED         0, L15ca   # 0x1534
        ADD              R3, R13, R0, R13   # 0x1538
        ADD              R1, R12, R0, R12   # 0x153c
        C_ADD            R3, R12   # 0x1540
        C_NOT            R3, R3   # 0x1542
        C_MOV            R9, R13   # 0x1544
L1546:  C_CHWIDTH        R14, 2   # 0x1546
        LD_GLOBAL_IDX    R14, R2, R9, 0, 0   # 0x1548
        C_CHWIDTH        R14, 0   # 0x154c
        ANDI             R10, R14, 255   # 0x154e
        SETP_EQ_NPI      P0, R10, R10, 44   # 0x1552
        BRA_PRED         0, L1566   # 0x1556
        C_CHWIDTH        R14, 1   # 0x155a
        XOR              R14, R14, R4, R14   # 0x155c
        C_CHWIDTH        R14, 2   # 0x1560
        ST_GLOBAL_IDX    R14, R2, R9, 0, 0   # 0x1562
L1566:  C_CHWIDTH        R14, 0   # 0x1566
        ADD              R14, R12, R9, R12   # 0x1568
        OR               R10, R0, R14, R0   # 0x156c
        C_AND            R10, R3   # 0x1570
        AND              R11, R0, R14, R0   # 0x1572
        OR               R10, R11, R10, R11   # 0x1576
        ADD              R9, R1, R9, R1   # 0x157a
        ADD              R11, R0, R6, R0   # 0x157e
        SETP_LT_U_NP     P0, R9, R9, R11   # 0x1582
        OR               R9, R0, R6, R0   # 0x1586
        C_ANDN           R9, R11   # 0x158a
        AND              R11, R0, R6, R0   # 0x158c
        OR               R9, R11, R9, R11   # 0x1590
        SHRI             R9, R9, 31   # 0x1594
        SHRI             R10, R10, 31   # 0x1598
        SETP_EQ_NP       P1, R11, R10, R9   # 0x159c
        ADD              R9, R8, R9, R8   # 0x15a0
        ADD              R10, R8, R10, R8   # 0x15a4
        SETP_LT_U_NP     P2, R9, R10, R9   # 0x15a8
        C_SUB            R3, R12   # 0x15ac
        C_MOV            R9, R14   # 0x15ae
        BRA_PRED         2, L1546   # 0x15b0
        PAND             P0, 1, 0   # 0x15b4
        C_MOV            R9, R14   # 0x15b6
        BRA_PRED         0, L1546   # 0x15b8
        C_CHWIDTH        R1, 2   # 0x15bc
        LD_GLOBAL_IDX    R1, R2, R13, 0, 0   # 0x15be
        C_CHWIDTH        R1, 0   # 0x15c2
        C_MOV            R14, R1   # 0x15c4
        LD_LOCAL         R5, 40   # 0x15c6
L15ca:  ST_LOCAL         R7, 16   # 0x15ca
        MOVI             R1, 255   # 0x15ce
        C_CHWIDTH        R1, 1   # 0x15d2
        AND              R1, R14, R1, R14   # 0x15d4
        C_CHWIDTH        R1, 0   # 0x15d8
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x15da
        BRA_PRED         0, L1840   # 0x15de
        MOVI             R10, 0   # 0x15e2
        MOVI             R4, 255   # 0x15e6
        MOVI             R5, 3   # 0x15ea
        C_MOV            R3, R13   # 0x15ee
        LD_LOCAL         R7, 44   # 0x15f0
        C_BRA            L15fa   # 0x15f4
L15f6:  C_MOV            R14, R1   # 0x15f6
        C_MOV            R3, R11   # 0x15f8
L15fa:  C_CHWIDTH        R1, 1   # 0x15fa
        AND              R1, R14, R4, R14   # 0x15fc
        C_CHWIDTH        R1, 0   # 0x1600
        SETP_NE_NPI      P0, R11, R1, 44   # 0x1602
        ADDI             R11, R3, 1   # 0x1606
        BRA_PRED         0, L1632   # 0x160a
L160e:  LD_GLOBAL_IDX    R1, R15, R10, 1, -36   # 0x160e
        C_ADDI           R1, 1   # 0x1612
        ST_GLOBAL_IDX    R1, R15, R10, 1, -36   # 0x1614
        C_CHWIDTH        R1, 2   # 0x1618
        LD_GLOBAL_IDX    R1, R2, R11, 0, 0   # 0x161a
        C_CHWIDTH        R1, 0   # 0x161e
        ANDI             R3, R1, 255   # 0x1620
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1624
        BRA_PRED         0, L183a   # 0x1628
        MOVI             R10, 0   # 0x162c
        C_BRA            L15f6   # 0x1630
L1632:  SETP_LT_NP       P0, R9, R5, R10   # 0x1632
        BRA_PRED         4, L1672   # 0x1636
        MOVI             R9, 5   # 0x163a
        SETP_LT_NP       P0, R9, R9, R10   # 0x163e
        BRA_PRED         0, L16a2   # 0x1642
        SETP_EQ_NPI      P0, R9, R10, 4   # 0x1646
        BRA_PRED         0, L1722   # 0x164a
        SETP_EQ_NPI      P0, R1, R10, 5   # 0x164e
        BRA_PRED         4, L181a   # 0x1652
        MOVI             R1, 223   # 0x1656
        C_CHWIDTH        R1, 1   # 0x165a
        AND              R1, R14, R1, R14   # 0x165c
        C_CHWIDTH        R1, 0   # 0x1660
        SETP_NE_NPI      P0, R1, R1, 69   # 0x1662
        BRA_PRED         0, L17b2   # 0x1666
        MOVI             R10, 3   # 0x166a
        BRA              L17d6   # 0x166e
L1672:  SETP_EQ_NPI      P0, R9, R10, 0   # 0x1672
        BRA_PRED         0, L16e4   # 0x1676
        SETP_EQ_NPI      P0, R9, R10, 2   # 0x167a
        BRA_PRED         0, L1758   # 0x167e
        SETP_EQ_NPI      P0, R14, R10, 3   # 0x1682
        BRA_PRED         4, L181a   # 0x1686
        SETP_EQ_NPI      P0, R14, R1, 45   # 0x168a
        BRA_PRED         0, L169a   # 0x168e
        SETP_NE_NPI      P0, R1, R1, 43   # 0x1692
        BRA_PRED         0, L17f2   # 0x1696
L169a:  MOVI             R10, 6   # 0x169a
        BRA              L17f6   # 0x169e
L16a2:  SETP_EQ_NPI      P0, R1, R10, 6   # 0x16a2
        BRA_PRED         0, L1730   # 0x16a6
        SETP_EQ_NPI      P0, R1, R10, 7   # 0x16aa
        BRA_PRED         4, L181a   # 0x16ae
        CHWIDTH_MULTI    16386, 1   # 0x16b2
        ADDI             R14, R14, -58   # 0x16b6
        AND              R1, R14, R4, R14   # 0x16ba
        CHWIDTH_MULTI    16386, 0   # 0x16be
        MOVI             R14, 245   # 0x16c2
        SETP_LT_U_NP     P0, R1, R14, R1   # 0x16c6
        MOVI             R10, 7   # 0x16ca
        BRA_PRED         0, L181a   # 0x16ce
        MOVI             R10, 1   # 0x16d2
        LD_LOCAL         R1, 28   # 0x16d6
        C_ADDI           R1, 1   # 0x16da
        ST_LOCAL         R1, 28   # 0x16dc
        BRA              L181a   # 0x16e0
L16e4:  C_CHWIDTH        R14, 1   # 0x16e4
        ADDI             R14, R14, -58   # 0x16e6
        AND              R14, R14, R4, R14   # 0x16ea
        C_CHWIDTH        R14, 0   # 0x16ee
        MOVI             R9, 245   # 0x16f0
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x16f4
        MOVI             R10, 4   # 0x16f8
        BRA_PRED         0, L1810   # 0x16fc
        MOVI             R10, 2   # 0x1700
        SETP_EQ_NPI      P0, R14, R1, 43   # 0x1704
        BRA_PRED         0, L1810   # 0x1708
        SETP_EQ_NPI      P0, R14, R1, 45   # 0x170c
        BRA_PRED         0, L1810   # 0x1710
        SETP_NE_NPI      P0, R1, R1, 46   # 0x1714
        BRA_PRED         0, L1802   # 0x1718
        MOVI             R10, 5   # 0x171c
        C_BRA            L1810   # 0x1720
L1722:  SETP_NE_NPI      P0, R1, R1, 46   # 0x1722
        BRA_PRED         0, L1782   # 0x1726
        MOVI             R10, 5   # 0x172a
        C_BRA            L17a6   # 0x172e
L1730:  CHWIDTH_MULTI    16386, 1   # 0x1730
        ADDI             R14, R14, -58   # 0x1734
        AND              R1, R14, R4, R14   # 0x1738
        CHWIDTH_MULTI    16386, 0   # 0x173c
        MOVI             R14, 246   # 0x1740
        SETP_LT_U_NP     P0, R1, R1, R14   # 0x1744
        MOVI             R10, 7   # 0x1748
        MOVI             R1, 1   # 0x174c
        MOV_P            R10, 0, R1, R1, R1   # 0x1750
        C_ADDI           R7, 1   # 0x1754
        C_BRA            L181a   # 0x1756
L1758:  C_CHWIDTH        R14, 1   # 0x1758
        ADDI             R14, R14, -58   # 0x175a
        AND              R14, R14, R4, R14   # 0x175e
        C_CHWIDTH        R14, 0   # 0x1762
        MOVI             R9, 246   # 0x1764
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x1768
        BRA_PRED         4, L17e2   # 0x176c
        SETP_EQ_NPI      P0, R1, R1, 46   # 0x1770
        MOVI             R10, 1   # 0x1774
        MOVI             R1, 5   # 0x1778
        MOV_P            R10, 0, R1, R1, R1   # 0x177c
        C_BRA            L17e6   # 0x1780
L1782:  CHWIDTH_MULTI    16386, 1   # 0x1782
        ADDI             R14, R14, -58   # 0x1786
        AND              R1, R14, R4, R14   # 0x178a
        CHWIDTH_MULTI    16386, 0   # 0x178e
        MOVI             R14, 245   # 0x1792
        SETP_LT_U_NP     P0, R1, R14, R1   # 0x1796
        MOVI             R10, 4   # 0x179a
        BRA_PRED         0, L181a   # 0x179e
        MOVI             R10, 1   # 0x17a2
L17a6:  LD_LOCAL         R1, 20   # 0x17a6
        C_ADDI           R1, 1   # 0x17aa
        ST_LOCAL         R1, 20   # 0x17ac
        C_BRA            L181a   # 0x17b0
L17b2:  CHWIDTH_MULTI    16386, 1   # 0x17b2
        ADDI             R14, R14, -58   # 0x17b6
        AND              R1, R14, R4, R14   # 0x17ba
        CHWIDTH_MULTI    16386, 0   # 0x17be
        MOVI             R14, 245   # 0x17c2
        SETP_LT_U_NP     P0, R1, R14, R1   # 0x17c6
        MOVI             R10, 5   # 0x17ca
        BRA_PRED         0, L181a   # 0x17ce
        MOVI             R10, 1   # 0x17d2
L17d6:  LD_LOCAL         R1, 16   # 0x17d6
        C_ADDI           R1, 1   # 0x17da
        ST_LOCAL         R1, 16   # 0x17dc
        C_BRA            L181a   # 0x17e0
L17e2:  MOVI             R10, 4   # 0x17e2
L17e6:  LD_LOCAL         R1, 12   # 0x17e6
        C_ADDI           R1, 1   # 0x17ea
        ST_LOCAL         R1, 12   # 0x17ec
        C_BRA            L181a   # 0x17f0
L17f2:  MOVI             R10, 1   # 0x17f2
L17f6:  LD_LOCAL         R1, 32   # 0x17f6
        C_ADDI           R1, 1   # 0x17fa
        ST_LOCAL         R1, 32   # 0x17fc
        C_BRA            L181a   # 0x1800
L1802:  MOVI             R10, 1   # 0x1802
        LD_LOCAL         R1, 28   # 0x1806
        C_ADDI           R1, 1   # 0x180a
        ST_LOCAL         R1, 28   # 0x180c
L1810:  LD_LOCAL         R1, 24   # 0x1810
        C_ADDI           R1, 1   # 0x1814
        ST_LOCAL         R1, 24   # 0x1816
L181a:  C_CHWIDTH        R1, 2   # 0x181a
        LD_GLOBAL_IDX    R1, R2, R3, 0, 1   # 0x181c
        C_CHWIDTH        R1, 0   # 0x1820
        ANDI             R3, R1, 255   # 0x1822
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1826
        BRA_PRED         0, L160e   # 0x182a
        SETP_EQ_NPI      P0, R3, R10, 1   # 0x182e
        BRA_PRED         4, L15f6   # 0x1832
        BRA              L160e   # 0x1836
L183a:  LD_LOCAL         R5, 40   # 0x183a
        C_BRA            L1844   # 0x183e
L1840:  LD_LOCAL         R7, 44   # 0x1840
L1844:  LD_LOCAL         R1, 36   # 0x1844
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x1848
        BRA_PRED         0, L18d4   # 0x184c
        ADD              R3, R13, R0, R13   # 0x1850
        ADD              R1, R12, R0, R12   # 0x1854
        C_ADD            R3, R12   # 0x1858
        C_NOT            R3, R3   # 0x185a
L185c:  C_CHWIDTH        R4, 2   # 0x185c
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x185e
        C_CHWIDTH        R4, 0   # 0x1862
        ANDI             R14, R4, 255   # 0x1864
        SETP_EQ_NPI      P0, R14, R14, 44   # 0x1868
        BRA_PRED         0, L187c   # 0x186c
        C_CHWIDTH        R4, 1   # 0x1870
        XOR              R4, R4, R5, R4   # 0x1872
        C_CHWIDTH        R4, 2   # 0x1876
        ST_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x1878
L187c:  C_CHWIDTH        R4, 0   # 0x187c
        ADD              R4, R12, R13, R12   # 0x187e
        OR               R14, R0, R4, R0   # 0x1882
        AND              R9, R14, R3, R14   # 0x1886
        AND              R14, R0, R4, R0   # 0x188a
        OR               R10, R14, R9, R14   # 0x188e
        ADD              R14, R1, R13, R1   # 0x1892
        ADD              R9, R0, R6, R0   # 0x1896
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x189a
        OR               R14, R0, R6, R0   # 0x189e
        C_ANDN           R14, R9   # 0x18a2
        AND              R9, R0, R6, R0   # 0x18a4
        OR               R14, R9, R14, R9   # 0x18a8
        SHRI             R14, R14, 31   # 0x18ac
        SHRI             R10, R10, 31   # 0x18b0
        SETP_EQ_NP       P1, R9, R10, R14   # 0x18b4
        ADD              R14, R8, R14, R8   # 0x18b8
        ADD              R9, R8, R10, R8   # 0x18bc
        SETP_LT_U_NP     P2, R14, R9, R14   # 0x18c0
        C_SUB            R3, R12   # 0x18c4
        C_MOV            R13, R4   # 0x18c6
        BRA_PRED         2, L185c   # 0x18c8
        PAND             P0, 1, 0   # 0x18cc
        C_MOV            R13, R4   # 0x18ce
        BRA_PRED         0, L185c   # 0x18d0
L18d4:  LD_GLOBAL        R1, R15, -36   # 0x18d4
        LD_LOCAL         R2, 52   # 0x18d8
        CALL             R14, 129654   # 0x18dc
        MOVI             R15, 2   # 0x18e0
        LD_GLOBAL        R15, R15, 24   # 0x18e4
        SRD              R3, 2   # 0x18e8
        C_ADD            R15, R3   # 0x18ea
        C_MOV            R2, R1   # 0x18ec
        LD_LOCAL         R1, 24   # 0x18ee
        CALL             R14, 129643   # 0x18f2
        MOVI             R15, 2   # 0x18f6
        LD_GLOBAL        R15, R15, 24   # 0x18fa
        SRD              R3, 2   # 0x18fe
        C_ADD            R15, R3   # 0x1900
        C_MOV            R2, R1   # 0x1902
        LD_GLOBAL        R1, R15, -32   # 0x1904
        CALL             R14, 129632   # 0x1908
        MOVI             R15, 2   # 0x190c
        LD_GLOBAL        R15, R15, 24   # 0x1910
        SRD              R3, 2   # 0x1914
        C_ADD            R15, R3   # 0x1916
        C_MOV            R2, R1   # 0x1918
        LD_LOCAL         R1, 28   # 0x191a
        CALL             R14, 129621   # 0x191e
        MOVI             R15, 2   # 0x1922
        LD_GLOBAL        R15, R15, 24   # 0x1926
        SRD              R3, 2   # 0x192a
        C_ADD            R15, R3   # 0x192c
        C_MOV            R2, R1   # 0x192e
        LD_GLOBAL        R1, R15, -28   # 0x1930
        CALL             R14, 129610   # 0x1934
        MOVI             R15, 2   # 0x1938
        LD_GLOBAL        R15, R15, 24   # 0x193c
        SRD              R3, 2   # 0x1940
        C_ADD            R15, R3   # 0x1942
        C_MOV            R2, R1   # 0x1944
        LD_LOCAL         R1, 12   # 0x1946
        CALL             R14, 129599   # 0x194a
        MOVI             R15, 2   # 0x194e
        LD_GLOBAL        R15, R15, 24   # 0x1952
        SRD              R3, 2   # 0x1956
        C_ADD            R15, R3   # 0x1958
        C_MOV            R2, R1   # 0x195a
        LD_GLOBAL        R1, R15, -24   # 0x195c
        CALL             R14, 129588   # 0x1960
        MOVI             R15, 2   # 0x1964
        LD_GLOBAL        R15, R15, 24   # 0x1968
        SRD              R3, 2   # 0x196c
        C_ADD            R15, R3   # 0x196e
        C_MOV            R2, R1   # 0x1970
        LD_LOCAL         R1, 32   # 0x1972
        CALL             R14, 129577   # 0x1976
        MOVI             R15, 2   # 0x197a
        LD_GLOBAL        R15, R15, 24   # 0x197e
        SRD              R3, 2   # 0x1982
        C_ADD            R15, R3   # 0x1984
        C_MOV            R2, R1   # 0x1986
        LD_GLOBAL        R1, R15, -20   # 0x1988
        CALL             R14, 129566   # 0x198c
        MOVI             R15, 2   # 0x1990
        LD_GLOBAL        R15, R15, 24   # 0x1994
        SRD              R3, 2   # 0x1998
        C_ADD            R15, R3   # 0x199a
        C_MOV            R2, R1   # 0x199c
        LD_LOCAL         R1, 20   # 0x199e
        CALL             R14, 129555   # 0x19a2
        MOVI             R15, 2   # 0x19a6
        LD_GLOBAL        R15, R15, 24   # 0x19aa
        SRD              R3, 2   # 0x19ae
        C_ADD            R15, R3   # 0x19b0
        C_MOV            R2, R1   # 0x19b2
        LD_GLOBAL        R1, R15, -16   # 0x19b4
        CALL             R14, 129544   # 0x19b8
        MOVI             R15, 2   # 0x19bc
        LD_GLOBAL        R15, R15, 24   # 0x19c0
        SRD              R3, 2   # 0x19c4
        C_ADD            R15, R3   # 0x19c6
        C_MOV            R2, R1   # 0x19c8
        LD_LOCAL         R1, 16   # 0x19ca
        CALL             R14, 129533   # 0x19ce
        MOVI             R15, 2   # 0x19d2
        LD_GLOBAL        R15, R15, 24   # 0x19d6
        SRD              R3, 2   # 0x19da
        C_ADD            R15, R3   # 0x19dc
        C_MOV            R2, R1   # 0x19de
        LD_GLOBAL        R1, R15, -12   # 0x19e0
        CALL             R14, 129522   # 0x19e4
        MOVI             R15, 2   # 0x19e8
        LD_GLOBAL        R15, R15, 24   # 0x19ec
        SRD              R3, 2   # 0x19f0
        C_ADD            R15, R3   # 0x19f2
        C_MOV            R2, R1   # 0x19f4
        C_MOV            R1, R7   # 0x19f6
        CALL             R14, 129512   # 0x19f8
        MOVI             R15, 2   # 0x19fc
        LD_GLOBAL        R15, R15, 24   # 0x1a00
        SRD              R3, 2   # 0x1a04
        C_ADD            R15, R3   # 0x1a06
        C_MOV            R2, R1   # 0x1a08
        LD_GLOBAL        R1, R15, -8   # 0x1a0a
        CALL             R14, 129501   # 0x1a0e
        MOVI             R15, 2   # 0x1a12
        LD_GLOBAL        R15, R15, 24   # 0x1a16
        SRD              R3, 2   # 0x1a1a
        C_ADD            R15, R3   # 0x1a1c
        C_MOV            R2, R1   # 0x1a1e
        MOVI             R1, 0   # 0x1a20
        CALL             R14, 129490   # 0x1a24
        MOVI             R15, 2   # 0x1a28
        LD_GLOBAL        R15, R15, 24   # 0x1a2c
        SRD              R3, 2   # 0x1a30
        C_ADD            R15, R3   # 0x1a32
        LD_LOCAL         R14, 48   # 0x1a34
        LD_LOCAL         R13, 80   # 0x1a38
        LD_LOCAL         R12, 76   # 0x1a3c
        LD_LOCAL         R11, 72   # 0x1a40
        LD_LOCAL         R10, 68   # 0x1a44
        LD_LOCAL         R9, 64   # 0x1a48
        LD_LOCAL         R8, 60   # 0x1a4c
        C_RET            224   # 0x1a50
        C_CHWIDTH        R0, 1   # 0x1a52
        XOR              R0, R2, R1, R2   # 0x1a54
        C_CHWIDTH        R0, 0   # 0x1a58
        C_ANDI           R0, 1   # 0x1a5a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1a5c
        MOVI             R0, 40961   # 0x1a60
        SHRI             R2, R2, 1   # 0x1a64
        C_MOV            R3, R2   # 0x1a68
        C_CHWIDTH        R2, 1   # 0x1a6a
        XOR              R2, R2, R0, R2   # 0x1a6c
        C_CHWIDTH        R2, 0   # 0x1a70
        MOV_P            R3, 0, R2, R2, R2   # 0x1a72
        SHRI             R2, R1, 1   # 0x1a76
        C_CHWIDTH        R2, 1   # 0x1a7a
        XOR              R2, R2, R3, R2   # 0x1a7c
        C_CHWIDTH        R2, 0   # 0x1a80
        C_ANDI           R2, 1   # 0x1a82
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1a84
        SHRI             R2, R3, 1   # 0x1a88
        C_MOV            R3, R2   # 0x1a8c
        C_CHWIDTH        R2, 1   # 0x1a8e
        XOR              R2, R2, R0, R2   # 0x1a90
        C_CHWIDTH        R2, 0   # 0x1a94
        MOV_P            R3, 0, R2, R2, R2   # 0x1a96
        SHRI             R2, R1, 2   # 0x1a9a
        C_CHWIDTH        R2, 1   # 0x1a9e
        XOR              R2, R2, R3, R2   # 0x1aa0
        C_CHWIDTH        R2, 0   # 0x1aa4
        C_ANDI           R2, 1   # 0x1aa6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1aa8
        SHRI             R2, R3, 1   # 0x1aac
        C_MOV            R3, R2   # 0x1ab0
        C_CHWIDTH        R2, 1   # 0x1ab2
        XOR              R2, R2, R0, R2   # 0x1ab4
        C_CHWIDTH        R2, 0   # 0x1ab8
        MOV_P            R3, 0, R2, R2, R2   # 0x1aba
        SHRI             R2, R1, 3   # 0x1abe
        C_CHWIDTH        R2, 1   # 0x1ac2
        XOR              R2, R2, R3, R2   # 0x1ac4
        C_CHWIDTH        R2, 0   # 0x1ac8
        C_ANDI           R2, 1   # 0x1aca
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1acc
        SHRI             R2, R3, 1   # 0x1ad0
        C_MOV            R3, R2   # 0x1ad4
        C_CHWIDTH        R2, 1   # 0x1ad6
        XOR              R2, R2, R0, R2   # 0x1ad8
        C_CHWIDTH        R2, 0   # 0x1adc
        MOV_P            R3, 0, R2, R2, R2   # 0x1ade
        SHRI             R2, R1, 4   # 0x1ae2
        C_CHWIDTH        R2, 1   # 0x1ae6
        XOR              R2, R2, R3, R2   # 0x1ae8
        C_CHWIDTH        R2, 0   # 0x1aec
        C_ANDI           R2, 1   # 0x1aee
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1af0
        SHRI             R2, R3, 1   # 0x1af4
        C_MOV            R3, R2   # 0x1af8
        C_CHWIDTH        R2, 1   # 0x1afa
        XOR              R2, R2, R0, R2   # 0x1afc
        C_CHWIDTH        R2, 0   # 0x1b00
        MOV_P            R3, 0, R2, R2, R2   # 0x1b02
        SHRI             R2, R1, 5   # 0x1b06
        C_CHWIDTH        R2, 1   # 0x1b0a
        XOR              R2, R2, R3, R2   # 0x1b0c
        C_CHWIDTH        R2, 0   # 0x1b10
        C_ANDI           R2, 1   # 0x1b12
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b14
        SHRI             R2, R3, 1   # 0x1b18
        C_MOV            R3, R2   # 0x1b1c
        C_CHWIDTH        R2, 1   # 0x1b1e
        XOR              R2, R2, R0, R2   # 0x1b20
        C_CHWIDTH        R2, 0   # 0x1b24
        MOV_P            R3, 0, R2, R2, R2   # 0x1b26
        SHRI             R2, R1, 6   # 0x1b2a
        C_CHWIDTH        R2, 1   # 0x1b2e
        XOR              R2, R2, R3, R2   # 0x1b30
        C_CHWIDTH        R2, 0   # 0x1b34
        C_ANDI           R2, 1   # 0x1b36
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b38
        SHRI             R2, R3, 1   # 0x1b3c
        C_MOV            R3, R2   # 0x1b40
        C_CHWIDTH        R2, 1   # 0x1b42
        XOR              R2, R2, R0, R2   # 0x1b44
        C_CHWIDTH        R2, 0   # 0x1b48
        MOV_P            R3, 0, R2, R2, R2   # 0x1b4a
        MOVI             R2, 128   # 0x1b4e
        C_CHWIDTH        R2, 1   # 0x1b52
        AND              R2, R1, R2, R1   # 0x1b54
        C_CHWIDTH        R2, 0   # 0x1b58
        SHRI             R2, R2, 7   # 0x1b5a
        ANDI             R4, R3, 1   # 0x1b5e
        SETP_EQ_NP       P0, R2, R2, R4   # 0x1b62
        SHRI             R2, R3, 1   # 0x1b66
        C_MOV            R3, R2   # 0x1b6a
        C_CHWIDTH        R2, 1   # 0x1b6c
        XOR              R2, R2, R0, R2   # 0x1b6e
        C_CHWIDTH        R2, 0   # 0x1b72
        MOV_P            R2, 0, R3, R3, R3   # 0x1b74
        SHRI             R3, R1, 8   # 0x1b78
        C_CHWIDTH        R3, 1   # 0x1b7c
        XOR              R3, R2, R3, R2   # 0x1b7e
        C_CHWIDTH        R3, 0   # 0x1b82
        C_ANDI           R3, 1   # 0x1b84
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1b86
        SHRI             R2, R2, 1   # 0x1b8a
        C_MOV            R3, R2   # 0x1b8e
        C_CHWIDTH        R2, 1   # 0x1b90
        XOR              R2, R2, R0, R2   # 0x1b92
        C_CHWIDTH        R2, 0   # 0x1b96
        MOV_P            R3, 0, R2, R2, R2   # 0x1b98
        SHRI             R2, R1, 9   # 0x1b9c
        C_CHWIDTH        R2, 1   # 0x1ba0
        XOR              R2, R2, R3, R2   # 0x1ba2
        C_CHWIDTH        R2, 0   # 0x1ba6
        C_ANDI           R2, 1   # 0x1ba8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1baa
        SHRI             R2, R3, 1   # 0x1bae
        C_MOV            R3, R2   # 0x1bb2
        C_CHWIDTH        R2, 1   # 0x1bb4
        XOR              R2, R2, R0, R2   # 0x1bb6
        C_CHWIDTH        R2, 0   # 0x1bba
        MOV_P            R3, 0, R2, R2, R2   # 0x1bbc
        SHRI             R2, R1, 10   # 0x1bc0
        C_CHWIDTH        R2, 1   # 0x1bc4
        XOR              R2, R2, R3, R2   # 0x1bc6
        C_CHWIDTH        R2, 0   # 0x1bca
        C_ANDI           R2, 1   # 0x1bcc
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bce
        SHRI             R2, R3, 1   # 0x1bd2
        C_MOV            R3, R2   # 0x1bd6
        C_CHWIDTH        R2, 1   # 0x1bd8
        XOR              R2, R2, R0, R2   # 0x1bda
        C_CHWIDTH        R2, 0   # 0x1bde
        MOV_P            R3, 0, R2, R2, R2   # 0x1be0
        SHRI             R2, R1, 11   # 0x1be4
        C_CHWIDTH        R2, 1   # 0x1be8
        XOR              R2, R2, R3, R2   # 0x1bea
        C_CHWIDTH        R2, 0   # 0x1bee
        C_ANDI           R2, 1   # 0x1bf0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bf2
        SHRI             R2, R3, 1   # 0x1bf6
        C_MOV            R3, R2   # 0x1bfa
        C_CHWIDTH        R2, 1   # 0x1bfc
        XOR              R2, R2, R0, R2   # 0x1bfe
        C_CHWIDTH        R2, 0   # 0x1c02
        MOV_P            R3, 0, R2, R2, R2   # 0x1c04
        SHRI             R2, R1, 12   # 0x1c08
        C_CHWIDTH        R2, 1   # 0x1c0c
        XOR              R2, R2, R3, R2   # 0x1c0e
        C_CHWIDTH        R2, 0   # 0x1c12
        C_ANDI           R2, 1   # 0x1c14
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c16
        SHRI             R2, R3, 1   # 0x1c1a
        C_MOV            R3, R2   # 0x1c1e
        C_CHWIDTH        R2, 1   # 0x1c20
        XOR              R2, R2, R0, R2   # 0x1c22
        C_CHWIDTH        R2, 0   # 0x1c26
        MOV_P            R3, 0, R2, R2, R2   # 0x1c28
        SHRI             R2, R1, 13   # 0x1c2c
        C_CHWIDTH        R2, 1   # 0x1c30
        XOR              R2, R2, R3, R2   # 0x1c32
        C_CHWIDTH        R2, 0   # 0x1c36
        C_ANDI           R2, 1   # 0x1c38
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c3a
        SHRI             R2, R3, 1   # 0x1c3e
        C_MOV            R3, R2   # 0x1c42
        C_CHWIDTH        R2, 1   # 0x1c44
        XOR              R2, R2, R0, R2   # 0x1c46
        C_CHWIDTH        R2, 0   # 0x1c4a
        MOV_P            R3, 0, R2, R2, R2   # 0x1c4c
        SHRI             R2, R1, 14   # 0x1c50
        C_CHWIDTH        R2, 1   # 0x1c54
        XOR              R2, R2, R3, R2   # 0x1c56
        C_CHWIDTH        R2, 0   # 0x1c5a
        C_ANDI           R2, 1   # 0x1c5c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c5e
        SHRI             R2, R3, 1   # 0x1c62
        C_MOV            R3, R2   # 0x1c66
        C_CHWIDTH        R2, 1   # 0x1c68
        XOR              R2, R2, R0, R2   # 0x1c6a
        C_CHWIDTH        R0, 1   # 0x1c6e
        C_CHWIDTH        R2, 0   # 0x1c70
        MOV_P            R3, 0, R2, R2, R2   # 0x1c72
        SHRI             R1, R1, 15   # 0x1c76
        ANDI             R2, R3, 1   # 0x1c7a
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1c7e
        SHRI             R1, R3, 1   # 0x1c82
        C_MOV            R2, R1   # 0x1c86
        XOR              R0, R1, R0, R1   # 0x1c88
        C_CHWIDTH        R0, 0   # 0x1c8c
        MOV_P            R0, 0, R2, R2, R2   # 0x1c8e
        MOVI             R1, 65535   # 0x1c92
        AND              R1, R0, R1, R0   # 0x1c96
        C_RET            224   # 0x1c9a
        ST_LOCAL         R8, 72   # 0x1c9c
        ST_LOCAL         R9, 76   # 0x1ca0
        ST_LOCAL         R10, 80   # 0x1ca4
        ST_LOCAL         R11, 84   # 0x1ca8
        ST_LOCAL         R12, 88   # 0x1cac
        ST_LOCAL         R13, 92   # 0x1cb0
        C_MOV            R15, R14   # 0x1cb4
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x1cb6
        SHLI             R10, R0, 16   # 0x1cba
        LD_GLOBAL_IDX    R13, R1, R2, 0, 16   # 0x1cbe
        SHRI             R0, R13, 16   # 0x1cc2
        ST_LOCAL         R0, 68   # 0x1cc6
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x1cca
        SHLI             R0, R0, 16   # 0x1cce
        LD_GLOBAL_IDX    R7, R1, R2, 0, 8   # 0x1cd2
        SHRI             R5, R7, 16   # 0x1cd6
        C_OR             R0, R5   # 0x1cda
        LD_GLOBAL_IDX    R5, R1, R2, 0, 28   # 0x1cdc
        SHLI             R14, R5, 16   # 0x1ce0
        LD_GLOBAL_IDX    R5, R1, R2, 0, 24   # 0x1ce4
        SHRI             R6, R5, 16   # 0x1ce8
        OR               R6, R14, R6, R14   # 0x1cec
        ST_LOCAL         R6, 16   # 0x1cf0
        MOVI             R6, 65535   # 0x1cf4
        AND              R14, R7, R6, R7   # 0x1cf8
        C_CHWIDTH        R7, 1   # 0x1cfc
        AND              R11, R5, R6, R5   # 0x1cfe
        LD_GLOBAL_IDX    R8, R1, R2, 0, 0   # 0x1d02
        MOVI             R2, 0   # 0x1d06
        MOVI             R1, 61440   # 0x1d0a
        C_MOV            R5, R3   # 0x1d0e
        OR               R7, R3, R1, R3   # 0x1d10
        SETP_EQ_NPI      P0, R1, R8, 0   # 0x1d14
        ANDI             R12, R8, -2   # 0x1d18
        ANDI             R1, R8, 1   # 0x1d1c
        ST_LOCAL         R1, 24   # 0x1d20
        ADDI             R1, R8, -1   # 0x1d24
        ST_LOCAL         R1, 20   # 0x1d28
        CVT_SEXT         R1, R7, R7, R7   # 0x1d2c
        ST_LOCAL         R1, 32   # 0x1d30
        ANDI             R9, R8, -4   # 0x1d34
        ST_LOCAL         R9, 48   # 0x1d38
        ST_LOCAL         R15, 56   # 0x1d3c
        ST_LOCAL         R5, 60   # 0x1d40
        ST_LOCAL         R4, 64   # 0x1d44
        ST_LOCAL         R11, 12   # 0x1d48
        ST_LOCAL         R10, 40   # 0x1d4c
        ST_LOCAL         R13, 52   # 0x1d50
        BRA_PRED         0, L2072   # 0x1d54
        ANDI             R1, R8, 3   # 0x1d58
        MOVI             R6, 0   # 0x1d5c
        C_MOV            R4, R5   # 0x1d60
        C_BRA            L1d74   # 0x1d62
L1d64:  CHWIDTH_MULTI    32768, 0   # 0x1d64
        C_ADD            R2, R8   # 0x1d68
        C_ADDI           R6, 1   # 0x1d6a
        SETP_NE_NP       P0, R3, R6, R8   # 0x1d6c
        BRA_PRED         4, L1e0e   # 0x1d70
L1d74:  MOVI             R3, 0   # 0x1d74
        LD_LOCAL         R5, 20   # 0x1d78
        SETP_LT_U_NPI    P0, R5, R5, 3   # 0x1d7c
        BRA_PRED         0, L1dda   # 0x1d80
L1d84:  CHWIDTH_MULTI    32896, 1   # 0x1d84
        ADD              R5, R2, R3, R2   # 0x1d88
        C_SHLI           R5, 1   # 0x1d8c
        ADD              R5, R14, R5, R14   # 0x1d8e
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1d92
        ADD              R7, R7, R4, R7   # 0x1d96
        ST_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1d9a
        C_CHWIDTH        R7, 0   # 0x1d9e
        ADDI             R7, R5, 2   # 0x1da0
        LD_GLOBAL_IDX    R15, R0, R7, 0, 0   # 0x1da4
        ADD              R15, R15, R4, R15   # 0x1da8
        ST_GLOBAL_IDX    R15, R0, R7, 0, 0   # 0x1dac
        ADDI             R7, R5, 4   # 0x1db0
        LD_GLOBAL_IDX    R15, R0, R7, 0, 0   # 0x1db4
        ADD              R15, R15, R4, R15   # 0x1db8
        ST_GLOBAL_IDX    R15, R0, R7, 0, 0   # 0x1dbc
        C_CHWIDTH        R7, 1   # 0x1dc0
        C_ADDI           R5, 6   # 0x1dc2
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1dc4
        ADD              R7, R7, R4, R7   # 0x1dc8
        ST_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1dcc
        C_ADDI           R3, 4   # 0x1dd0
        SETP_NE_NP       P0, R5, R9, R3   # 0x1dd2
        BRA_PRED         0, L1d84   # 0x1dd6
L1dda:  SETP_EQ_NPI      P0, R5, R1, 0   # 0x1dda
        BRA_PRED         0, L1d64   # 0x1dde
        C_ADD            R3, R2   # 0x1de2
        C_MOV            R5, R1   # 0x1de4
L1de6:  C_CHWIDTH        R15, 1   # 0x1de6
        C_CHWIDTH        R7, 0   # 0x1de8
        C_MOV            R7, R3   # 0x1dea
        C_SHLI           R7, 1   # 0x1dec
        ADD              R7, R14, R7, R14   # 0x1dee
        LD_GLOBAL_IDX    R15, R0, R7, 0, 0   # 0x1df2
        ADD              R15, R15, R4, R15   # 0x1df6
        ST_GLOBAL_IDX    R15, R0, R7, 0, 0   # 0x1dfa
        C_ADDI           R3, 1   # 0x1dfe
        ADDI             R5, R5, -1   # 0x1e00
        SETP_NE_NPI      P0, R7, R5, 0   # 0x1e04
        BRA_PRED         0, L1de6   # 0x1e08
        C_BRA            L1d64   # 0x1e0c
L1e0e:  C_CHWIDTH        R4, 1   # 0x1e0e
        MOVI             R2, 0   # 0x1e10
        CVT_SEXT         R6, R4, R4, R4   # 0x1e14
        C_CHWIDTH        R4, 0   # 0x1e18
        MOVI             R15, 0   # 0x1e1a
        LD_LOCAL         R4, 16   # 0x1e1e
        ST_LOCAL         R1, 28   # 0x1e22
        C_BRA            L1e38   # 0x1e26
L1e28:  CHWIDTH_MULTI    8192, 0   # 0x1e28
        C_ADD            R2, R8   # 0x1e2c
        C_ADDI           R15, 1   # 0x1e2e
        SETP_NE_NP       P0, R3, R15, R8   # 0x1e30
        BRA_PRED         4, L1f32   # 0x1e34
L1e38:  LD_LOCAL         R3, 20   # 0x1e38
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1e3c
        MOVI             R5, 0   # 0x1e40
        LD_LOCAL         R1, 48   # 0x1e44
        BRA_PRED         0, L1eec   # 0x1e48
L1e4c:  C_CHWIDTH        R13, 1   # 0x1e4c
        C_CHWIDTH        R7, 0   # 0x1e4e
        ADD              R3, R2, R5, R2   # 0x1e50
        C_MOV            R7, R3   # 0x1e54
        C_SHLI           R7, 2   # 0x1e56
        ADD              R7, R11, R7, R11   # 0x1e58
        C_MOV            R9, R3   # 0x1e5c
        C_SHLI           R9, 1   # 0x1e5e
        ADD              R9, R14, R9, R14   # 0x1e60
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1e64
        CVT_SEXT         R9, R13, R13, R13   # 0x1e68
        C_MUL_LO         R9, R6   # 0x1e6c
        ST_GLOBAL_IDX    R9, R4, R7, 0, 0   # 0x1e6e
        ADDI             R7, R3, 1   # 0x1e72
        C_MOV            R9, R7   # 0x1e76
        C_SHLI           R9, 2   # 0x1e78
        ADD              R9, R11, R9, R11   # 0x1e7a
        C_SHLI           R7, 1   # 0x1e7e
        ADD              R7, R14, R7, R14   # 0x1e80
        C_CHWIDTH        R7, 1   # 0x1e84
        LD_GLOBAL_IDX    R7, R0, R7, 0, 0   # 0x1e86
        CVT_SEXT         R10, R7, R7, R7   # 0x1e8a
        C_CHWIDTH        R7, 0   # 0x1e8e
        MUL_LO           R7, R10, R6, R6   # 0x1e90
        ST_GLOBAL_IDX    R7, R4, R9, 0, 0   # 0x1e94
        ADDI             R7, R3, 2   # 0x1e98
        C_MOV            R9, R7   # 0x1e9c
        C_SHLI           R9, 2   # 0x1e9e
        ADD              R9, R11, R9, R11   # 0x1ea0
        C_SHLI           R7, 1   # 0x1ea4
        ADD              R7, R14, R7, R14   # 0x1ea6
        C_CHWIDTH        R7, 1   # 0x1eaa
        LD_GLOBAL_IDX    R7, R0, R7, 0, 0   # 0x1eac
        CVT_SEXT         R10, R7, R7, R7   # 0x1eb0
        C_CHWIDTH        R7, 0   # 0x1eb4
        MUL_LO           R7, R10, R6, R6   # 0x1eb6
        ST_GLOBAL_IDX    R7, R4, R9, 0, 0   # 0x1eba
        C_ADDI           R3, 3   # 0x1ebe
        C_MOV            R7, R3   # 0x1ec0
        C_SHLI           R7, 2   # 0x1ec2
        ADD              R7, R11, R7, R11   # 0x1ec4
        C_SHLI           R3, 1   # 0x1ec8
        ADD              R3, R14, R3, R14   # 0x1eca
        C_CHWIDTH        R3, 1   # 0x1ece
        LD_GLOBAL_IDX    R3, R0, R3, 0, 0   # 0x1ed0
        CVT_SEXT         R9, R3, R3, R3   # 0x1ed4
        C_CHWIDTH        R3, 0   # 0x1ed8
        MUL_LO           R3, R9, R6, R6   # 0x1eda
        ST_GLOBAL_IDX    R3, R4, R7, 0, 0   # 0x1ede
        C_ADDI           R5, 4   # 0x1ee2
        SETP_NE_NP       P0, R3, R1, R5   # 0x1ee4
        BRA_PRED         0, L1e4c   # 0x1ee8
L1eec:  LD_LOCAL         R1, 28   # 0x1eec
        SETP_EQ_NPI      P0, R3, R1, 0   # 0x1ef0
        BRA_PRED         0, L1e28   # 0x1ef4
        ADD              R3, R5, R2, R5   # 0x1ef8
        C_MOV            R5, R1   # 0x1efc
L1efe:  C_CHWIDTH        R13, 1   # 0x1efe
        C_CHWIDTH        R7, 0   # 0x1f00
        C_MOV            R7, R3   # 0x1f02
        C_SHLI           R7, 2   # 0x1f04
        ADD              R7, R11, R7, R11   # 0x1f06
        C_MOV            R9, R3   # 0x1f0a
        C_SHLI           R9, 1   # 0x1f0c
        ADD              R9, R14, R9, R14   # 0x1f0e
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1f12
        CVT_SEXT         R9, R13, R13, R13   # 0x1f16
        C_MUL_LO         R9, R6   # 0x1f1a
        ST_GLOBAL_IDX    R9, R4, R7, 0, 0   # 0x1f1c
        C_ADDI           R3, 1   # 0x1f20
        ADDI             R5, R5, -1   # 0x1f22
        SETP_NE_NPI      P0, R7, R5, 0   # 0x1f26
        BRA_PRED         0, L1efe   # 0x1f2a
        BRA              L1e28   # 0x1f2e
L1f32:  MOVI             R1, 0   # 0x1f32
        ST_LOCAL         R1, 44   # 0x1f36
        MOVI             R2, 0   # 0x1f3a
        MOVI             R13, 0   # 0x1f3e
        MOVI             R10, 0   # 0x1f42
        MOVI             R15, 0   # 0x1f46
        C_BRA            L1f5c   # 0x1f4a
L1f4c:  LD_LOCAL         R2, 28   # 0x1f4c
        C_ADD            R2, R8   # 0x1f50
        C_ADDI           R13, 1   # 0x1f52
        SETP_NE_NP       P0, R1, R13, R8   # 0x1f54
        BRA_PRED         4, L207c   # 0x1f58
L1f5c:  ST_LOCAL         R13, 36   # 0x1f5c
        ST_LOCAL         R2, 28   # 0x1f60
        LD_LOCAL         R1, 20   # 0x1f64
        SETP_EQ_NPI      P0, R3, R1, 0   # 0x1f68
        BRA_PRED         0, L1ffa   # 0x1f6c
        C_CHWIDTH        R7, 0   # 0x1f70
        MOVI             R7, 0   # 0x1f72
        C_MOV            R3, R10   # 0x1f76
        LD_LOCAL         R2, 32   # 0x1f78
        LD_LOCAL         R9, 44   # 0x1f7c
        MOVI             R11, 10   # 0x1f80
        LD_LOCAL         R13, 28   # 0x1f84
L1f88:  C_CHWIDTH        R9, 1   # 0x1f88
        C_CHWIDTH        R5, 0   # 0x1f8a
        ADD              R5, R13, R7, R13   # 0x1f8c
        C_SHLI           R5, 2   # 0x1f90
        LD_LOCAL         R1, 12   # 0x1f92
        C_ADD            R5, R1   # 0x1f96
        ADDI             R10, R5, 4   # 0x1f98
        LD_GLOBAL_IDX    R10, R4, R10, 0, 0   # 0x1f9c
        LD_GLOBAL_IDX    R5, R4, R5, 0, 0   # 0x1fa0
        SETP_LT_NP       P0, R3, R3, R5   # 0x1fa4
        SETP_LT_NP       P1, R3, R5, R10   # 0x1fa8
        MOVI             R3, 0   # 0x1fac
        MOVI             R6, 1   # 0x1fb0
        MOV_P            R3, 1, R6, R6, R6   # 0x1fb4
        MOVI             R1, 0   # 0x1fb8
        MOV_P            R1, 0, R6, R6, R6   # 0x1fbc
        C_ADD            R5, R15   # 0x1fc0
        SETP_LT_NP       P0, R15, R2, R5   # 0x1fc2
        MOV_P            R1, 0, R11, R11, R11   # 0x1fc6
        MOVI             R6, 0   # 0x1fca
        MOV_P            R5, 0, R6, R6, R6   # 0x1fce
        ADD              R15, R10, R5, R10   # 0x1fd2
        SETP_LT_NP       P0, R5, R2, R15   # 0x1fd6
        C_CHWIDTH        R5, 1   # 0x1fda
        MOV_P            R3, 0, R11, R11, R11   # 0x1fdc
        MOV_P            R15, 0, R6, R6, R6   # 0x1fe0
        ADD              R5, R1, R9, R1   # 0x1fe4
        ADD              R9, R3, R5, R3   # 0x1fe8
        C_ADDI           R7, 2   # 0x1fec
        SETP_NE_NP       P0, R1, R12, R7   # 0x1fee
        C_MOV            R3, R10   # 0x1ff2
        BRA_PRED         0, L1f88   # 0x1ff4
        C_BRA            L2004   # 0x1ff8
L1ffa:  C_CHWIDTH        R7, 0   # 0x1ffa
        MOVI             R7, 0   # 0x1ffc
        LD_LOCAL         R9, 44   # 0x2000
L2004:  C_CHWIDTH        R9, 0   # 0x2004
        ST_LOCAL         R9, 44   # 0x2006
        LD_LOCAL         R1, 24   # 0x200a
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x200e
        MOVI             R9, 0   # 0x2012
        MOVI             R2, 1   # 0x2016
        MOVI             R6, 10   # 0x201a
        LD_LOCAL         R11, 12   # 0x201e
        LD_LOCAL         R13, 36   # 0x2022
        BRA_PRED         0, L1f4c   # 0x2026
        MUL_LO           R1, R13, R8, R8   # 0x202a
        ADD              R1, R7, R1, R7   # 0x202e
        C_SHLI           R1, 2   # 0x2032
        ADD              R1, R11, R1, R11   # 0x2034
        LD_GLOBAL_IDX    R1, R4, R1, 0, 0   # 0x2038
        SETP_LT_NP       P0, R3, R10, R1   # 0x203c
        MOVI             R3, 0   # 0x2040
        MOV_P            R3, 0, R2, R2, R2   # 0x2044
        ADD              R15, R1, R15, R1   # 0x2048
        LD_LOCAL         R2, 32   # 0x204c
        SETP_LT_NP       P0, R5, R2, R15   # 0x2050
        MOV_P            R15, 0, R9, R9, R9   # 0x2054
        MOV_P            R3, 0, R6, R6, R6   # 0x2058
        LD_LOCAL         R2, 44   # 0x205c
        C_CHWIDTH        R2, 1   # 0x2060
        ADD              R2, R3, R2, R3   # 0x2062
        C_CHWIDTH        R2, 0   # 0x2066
        ST_LOCAL         R2, 44   # 0x2068
        C_MOV            R10, R1   # 0x206c
        BRA              L1f4c   # 0x206e
L2072:  C_MOV            R1, R2   # 0x2072
        ST_LOCAL         R1, 44   # 0x2074
        LD_LOCAL         R4, 16   # 0x2078
L207c:  CHWIDTH_MULTI    32, 0   # 0x207c
        LD_LOCAL         R1, 40   # 0x2080
        LD_LOCAL         R2, 68   # 0x2084
        OR               R15, R1, R2, R1   # 0x2088
        LD_LOCAL         R1, 52   # 0x208c
        MOVI             R2, 65535   # 0x2090
        AND              R10, R1, R2, R1   # 0x2094
        MOVI             R1, 0   # 0x2098
        SETP_EQ_NPI      P0, R2, R8, 0   # 0x209c
        BRA_PRED         0, L22ac   # 0x20a0
        MOVI             R9, 0   # 0x20a4
        C_BRA            L20c6   # 0x20a8
L20aa:  CHWIDTH_MULTI    8224, 0   # 0x20aa
        C_MOV            R2, R9   # 0x20ae
        C_SHLI           R2, 2   # 0x20b0
        ADD              R2, R11, R2, R11   # 0x20b2
        ST_GLOBAL_IDX    R6, R4, R2, 0, 0   # 0x20b6
        C_ADD            R1, R8   # 0x20ba
        C_ADDI           R9, 1   # 0x20bc
        SETP_NE_NP       P0, R2, R9, R8   # 0x20be
        BRA_PRED         4, L2176   # 0x20c2
L20c6:  ST_LOCAL         R9, 28   # 0x20c6
        LD_LOCAL         R2, 20   # 0x20ca
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x20ce
        BRA_PRED         0, L2132   # 0x20d2
        MOVI             R5, 0   # 0x20d6
        MOVI             R6, 0   # 0x20da
L20de:  C_CHWIDTH        R13, 1   # 0x20de
        C_CHWIDTH        R7, 0   # 0x20e0
        ADD              R3, R1, R5, R1   # 0x20e2
        C_SHLI           R3, 1   # 0x20e6
        C_ADD            R3, R14   # 0x20e8
        C_MOV            R7, R5   # 0x20ea
        C_SHLI           R7, 1   # 0x20ec
        C_ADD            R7, R10   # 0x20ee
        LD_GLOBAL_IDX    R13, R15, R7, 0, 0   # 0x20f0
        CVT_SEXT         R9, R13, R13, R13   # 0x20f4
        LD_GLOBAL_IDX    R13, R0, R3, 0, 0   # 0x20f8
        CVT_SEXT         R2, R13, R13, R13   # 0x20fc
        MADLO            R2, R9, R2, R6   # 0x2100
        C_CHWIDTH        R6, 1   # 0x2104
        C_ADDI           R3, 2   # 0x2106
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x2108
        ADDI             R3, R7, 2   # 0x210c
        C_CHWIDTH        R7, 1   # 0x2110
        LD_GLOBAL_IDX    R7, R15, R3, 0, 0   # 0x2112
        CVT_SEXT         R3, R7, R7, R7   # 0x2116
        C_CHWIDTH        R7, 0   # 0x211a
        CVT_SEXT         R7, R6, R6, R6   # 0x211c
        C_CHWIDTH        R6, 0   # 0x2120
        MADLO            R6, R3, R7, R2   # 0x2122
        C_ADDI           R5, 2   # 0x2126
        SETP_NE_NP       P0, R2, R12, R5   # 0x2128
        BRA_PRED         0, L20de   # 0x212c
        C_BRA            L213a   # 0x2130
L2132:  MOVI             R5, 0   # 0x2132
        MOVI             R6, 0   # 0x2136
L213a:  LD_LOCAL         R2, 24   # 0x213a
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x213e
        LD_LOCAL         R9, 28   # 0x2142
        BRA_PRED         0, L20aa   # 0x2146
        C_CHWIDTH        R7, 1   # 0x214a
        MUL_LO           R2, R9, R8, R8   # 0x214c
        ADD              R2, R5, R2, R5   # 0x2150
        C_SHLI           R2, 1   # 0x2154
        ADD              R2, R14, R2, R14   # 0x2156
        LD_GLOBAL_IDX    R7, R0, R2, 0, 0   # 0x215a
        C_SHLI           R5, 1   # 0x215e
        ADD              R2, R10, R5, R10   # 0x2160
        C_CHWIDTH        R5, 1   # 0x2164
        LD_GLOBAL_IDX    R5, R15, R2, 0, 0   # 0x2166
        CVT_SEXT         R2, R5, R5, R5   # 0x216a
        CVT_SEXT         R3, R7, R7, R7   # 0x216e
        MAD_ACC          R6, R2, R3   # 0x2172
        C_BRA            L20aa   # 0x2174
L2176:  MOVI             R1, 0   # 0x2176
        C_MOV            R5, R1   # 0x217a
        MOVI             R3, 0   # 0x217c
        ST_LOCAL         R1, 40   # 0x2180
        MOVI             R6, 0   # 0x2184
        MOVI             R13, 0   # 0x2188
        C_BRA            L21a6   # 0x218c
L218e:  LD_LOCAL         R3, 28   # 0x218e
        C_ADD            R3, R8   # 0x2192
        LD_LOCAL         R2, 40   # 0x2194
        C_ADDI           R2, 1   # 0x2198
        ST_LOCAL         R2, 40   # 0x219a
        SETP_NE_NP       P0, R2, R2, R8   # 0x219e
        BRA_PRED         4, L22ae   # 0x21a2
L21a6:  ST_LOCAL         R3, 28   # 0x21a6
        LD_LOCAL         R2, 20   # 0x21aa
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x21ae
        BRA_PRED         0, L224c   # 0x21b2
        MOVI             R2, 0   # 0x21b6
        C_MOV            R3, R6   # 0x21ba
        LD_LOCAL         R1, 32   # 0x21bc
        LD_LOCAL         R1, 28   # 0x21c0
L21c4:  CHWIDTH_MULTI    160, 0   # 0x21c4
        ST_LOCAL         R5, 36   # 0x21c8
        LD_LOCAL         R1, 28   # 0x21cc
        C_ADD            R1, R2   # 0x21d0
        C_SHLI           R1, 2   # 0x21d2
        LD_LOCAL         R5, 12   # 0x21d4
        ADD              R5, R1, R5, R1   # 0x21d8
        ADDI             R1, R5, 4   # 0x21dc
        LD_GLOBAL_IDX    R6, R4, R1, 0, 0   # 0x21e0
        LD_GLOBAL_IDX    R5, R4, R5, 0, 0   # 0x21e4
        SETP_LT_NP       P0, R3, R3, R5   # 0x21e8
        SETP_LT_NP       P1, R3, R5, R6   # 0x21ec
        MOVI             R3, 0   # 0x21f0
        MOVI             R11, 1   # 0x21f4
        MOV_P            R3, 1, R11, R11, R11   # 0x21f8
        MOVI             R7, 0   # 0x21fc
        MOV_P            R7, 0, R11, R11, R11   # 0x2200
        C_ADD            R5, R13   # 0x2204
        LD_LOCAL         R1, 32   # 0x2206
        SETP_LT_NP       P0, R13, R1, R5   # 0x220a
        MOVI             R9, 10   # 0x220e
        MOV_P            R7, 0, R9, R9, R9   # 0x2212
        C_CHWIDTH        R7, 1   # 0x2216
        MOVI             R11, 0   # 0x2218
        MOV_P            R5, 0, R11, R11, R11   # 0x221c
        ADD              R13, R6, R5, R6   # 0x2220
        SETP_LT_NP       P0, R5, R1, R13   # 0x2224
        C_CHWIDTH        R5, 1   # 0x2228
        MOV_P            R3, 0, R9, R9, R9   # 0x222a
        MOV_P            R13, 0, R11, R11, R11   # 0x222e
        LD_LOCAL         R1, 36   # 0x2232
        ADD              R7, R7, R1, R7   # 0x2236
        ADD              R5, R3, R7, R3   # 0x223a
        C_ADDI           R2, 2   # 0x223e
        SETP_NE_NP       P0, R3, R12, R2   # 0x2240
        C_MOV            R3, R6   # 0x2244
        BRA_PRED         0, L21c4   # 0x2246
        C_BRA            L2250   # 0x224a
L224c:  MOVI             R2, 0   # 0x224c
L2250:  C_CHWIDTH        R7, 0   # 0x2250
        LD_LOCAL         R3, 24   # 0x2252
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2256
        MOVI             R9, 0   # 0x225a
        LD_LOCAL         R11, 12   # 0x225e
        MOVI             R7, 1   # 0x2262
        BRA_PRED         0, L218e   # 0x2266
        C_CHWIDTH        R5, 1   # 0x226a
        LD_LOCAL         R3, 40   # 0x226c
        C_MUL_LO         R3, R8   # 0x2270
        C_ADD            R2, R3   # 0x2272
        C_SHLI           R2, 2   # 0x2274
        ADD              R2, R11, R2, R11   # 0x2276
        LD_GLOBAL_IDX    R2, R4, R2, 0, 0   # 0x227a
        SETP_LT_NP       P0, R1, R6, R2   # 0x227e
        MOVI             R1, 0   # 0x2282
        MOV_P            R1, 0, R7, R7, R7   # 0x2286
        ADD              R13, R2, R13, R2   # 0x228a
        LD_LOCAL         R3, 32   # 0x228e
        SETP_LT_NP       P0, R3, R3, R13   # 0x2292
        MOV_P            R13, 0, R9, R9, R9   # 0x2296
        MOVI             R3, 10   # 0x229a
        MOV_P            R1, 0, R3, R3, R3   # 0x229e
        ADD              R5, R1, R5, R1   # 0x22a2
        C_MOV            R6, R2   # 0x22a6
        BRA              L218e   # 0x22a8
L22ac:  C_MOV            R5, R1   # 0x22ac
L22ae:  CHWIDTH_MULTI    160, 0   # 0x22ae
        ST_LOCAL         R5, 36   # 0x22b2
        MOVI             R1, 0   # 0x22b6
        SETP_EQ_NPI      P0, R2, R8, 0   # 0x22ba
        C_MOV            R2, R8   # 0x22be
        C_SHLI           R2, 1   # 0x22c0
        C_MOV            R4, R8   # 0x22c2
        BRA_PRED         0, L2518   # 0x22c4
        LD_LOCAL         R3, 48   # 0x22c8
        MOVI             R5, 0   # 0x22cc
        C_BRA            L22e6   # 0x22d0
L22d2:  CHWIDTH_MULTI    128, 0   # 0x22d2
        C_ADD            R1, R8   # 0x22d6
        LD_LOCAL         R5, 40   # 0x22d8
        C_ADDI           R5, 1   # 0x22dc
        SETP_NE_NP       P0, R3, R5, R8   # 0x22de
        BRA_PRED         4, L23d2   # 0x22e2
L22e6:  ST_LOCAL         R5, 40   # 0x22e6
        MUL_LO           R3, R5, R8, R8   # 0x22ea
        ST_LOCAL         R3, 28   # 0x22ee
        MOVI             R11, 0   # 0x22f2
        C_BRA            L231e   # 0x22f6
L22f8:  C_CHWIDTH        R6, 0   # 0x22f8
        LD_LOCAL         R3, 28   # 0x22fa
        ADD              R3, R11, R3, R11   # 0x22fe
        C_SHLI           R3, 2   # 0x2302
        LD_LOCAL         R6, 12   # 0x2304
        ADD              R3, R6, R3, R6   # 0x2308
        LD_LOCAL         R6, 16   # 0x230c
        ST_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x2310
        C_ADDI           R11, 1   # 0x2314
        SETP_NE_NP       P0, R3, R11, R8   # 0x2316
        BRA_PRED         4, L22d2   # 0x231a
L231e:  LD_LOCAL         R3, 20   # 0x231e
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2322
        MOVI             R13, 0   # 0x2326
        MOVI             R5, 0   # 0x232a
        BRA_PRED         0, L2394   # 0x232e
        C_MOV            R9, R11   # 0x2332
L2334:  C_CHWIDTH        R7, 0   # 0x2334
        ADD              R6, R1, R13, R1   # 0x2336
        C_SHLI           R6, 1   # 0x233a
        C_ADD            R6, R14   # 0x233c
        C_MOV            R3, R9   # 0x233e
        C_SHLI           R3, 1   # 0x2340
        ADD              R3, R10, R3, R10   # 0x2342
        C_CHWIDTH        R3, 1   # 0x2346
        LD_GLOBAL_IDX    R3, R15, R3, 0, 0   # 0x2348
        CVT_SEXT         R8, R3, R3, R3   # 0x234c
        LD_GLOBAL_IDX    R3, R0, R6, 0, 0   # 0x2350
        CVT_SEXT         R7, R3, R3, R3   # 0x2354
        C_CHWIDTH        R3, 0   # 0x2358
        MADLO            R3, R8, R7, R5   # 0x235a
        C_CHWIDTH        R7, 1   # 0x235e
        C_MOV            R8, R4   # 0x2360
        ADDI             R5, R6, 2   # 0x2362
        C_CHWIDTH        R6, 1   # 0x2366
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x2368
        ADD              R5, R8, R9, R8   # 0x236c
        C_SHLI           R5, 1   # 0x2370
        ADD              R5, R10, R5, R10   # 0x2372
        LD_GLOBAL_IDX    R6, R15, R5, 0, 0   # 0x2376
        CVT_SEXT         R5, R6, R6, R6   # 0x237a
        C_CHWIDTH        R6, 0   # 0x237e
        CVT_SEXT         R6, R7, R7, R7   # 0x2380
        MADLO            R5, R5, R6, R3   # 0x2384
        C_ADD            R9, R2   # 0x2388
        C_ADDI           R13, 2   # 0x238a
        SETP_NE_NP       P0, R3, R12, R13   # 0x238c
        BRA_PRED         0, L2334   # 0x2390
L2394:  LD_LOCAL         R3, 24   # 0x2394
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2398
        BRA_PRED         0, L22f8   # 0x239c
        CHWIDTH_MULTI    192, 1   # 0x23a0
        MADLO            R3, R13, R8, R11   # 0x23a4
        C_SHLI           R3, 1   # 0x23a8
        ADD              R3, R10, R3, R10   # 0x23aa
        LD_GLOBAL_IDX    R7, R15, R3, 0, 0   # 0x23ae
        LD_LOCAL         R3, 28   # 0x23b2
        ADD              R3, R13, R3, R13   # 0x23b6
        C_SHLI           R3, 1   # 0x23ba
        ADD              R3, R14, R3, R14   # 0x23bc
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x23c0
        CVT_SEXT         R3, R7, R7, R7   # 0x23c4
        C_CHWIDTH        R7, 0   # 0x23c8
        CVT_SEXT         R7, R6, R6, R6   # 0x23ca
        MAD_ACC          R5, R3, R7   # 0x23ce
        C_BRA            L22f8   # 0x23d0
L23d2:  MOVI             R1, 0   # 0x23d2
        C_MOV            R7, R1   # 0x23d6
        MOVI             R5, 0   # 0x23d8
        ST_LOCAL         R1, 28   # 0x23dc
        MOVI             R11, 0   # 0x23e0
        LD_LOCAL         R3, 48   # 0x23e4
        C_BRA            L23fe   # 0x23e8
L23ea:  C_ADD            R5, R8   # 0x23ea
        LD_LOCAL         R3, 28   # 0x23ec
        C_ADDI           R3, 1   # 0x23f0
        ST_LOCAL         R3, 28   # 0x23f2
        SETP_NE_NP       P0, R3, R3, R8   # 0x23f6
        BRA_PRED         4, L251a   # 0x23fa
L23fe:  LD_LOCAL         R3, 20   # 0x23fe
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2402
        BRA_PRED         0, L24aa   # 0x2406
        MOVI             R6, 0   # 0x240a
        C_MOV            R3, R11   # 0x240e
        LD_LOCAL         R8, 16   # 0x2410
        LD_LOCAL         R8, 12   # 0x2414
        LD_LOCAL         R8, 32   # 0x2418
L241c:  C_CHWIDTH        R7, 0   # 0x241c
        ST_LOCAL         R7, 40   # 0x241e
        C_MOV            R7, R5   # 0x2422
        ADD              R5, R7, R6, R7   # 0x2424
        C_SHLI           R5, 2   # 0x2428
        LD_LOCAL         R8, 12   # 0x242a
        C_ADD            R5, R8   # 0x242e
        ADDI             R8, R5, 4   # 0x2430
        LD_LOCAL         R9, 16   # 0x2434
        LD_GLOBAL_IDX    R11, R9, R8, 0, 0   # 0x2438
        LD_GLOBAL_IDX    R5, R9, R5, 0, 0   # 0x243c
        SETP_LT_NP       P0, R3, R3, R5   # 0x2440
        SETP_LT_NP       P1, R3, R5, R11   # 0x2444
        MOVI             R3, 0   # 0x2448
        MOVI             R9, 1   # 0x244c
        MOV_P            R3, 1, R9, R9, R9   # 0x2450
        MOVI             R8, 0   # 0x2454
        MOV_P            R8, 0, R9, R9, R9   # 0x2458
        ADD              R1, R5, R1, R5   # 0x245c
        LD_LOCAL         R13, 32   # 0x2460
        SETP_LT_NP       P0, R5, R13, R1   # 0x2464
        MOVI             R5, 10   # 0x2468
        MOV_P            R8, 0, R5, R5, R5   # 0x246c
        MOVI             R9, 0   # 0x2470
        MOV_P            R1, 0, R9, R9, R9   # 0x2474
        ADD              R1, R11, R1, R11   # 0x2478
        SETP_LT_NP       P0, R5, R13, R1   # 0x247c
        MOVI             R5, 10   # 0x2480
        MOV_P            R3, 0, R5, R5, R5   # 0x2484
        C_MOV            R5, R7   # 0x2488
        MOV_P            R1, 0, R9, R9, R9   # 0x248a
        LD_LOCAL         R7, 40   # 0x248e
        C_CHWIDTH        R7, 1   # 0x2492
        ADD              R7, R8, R7, R8   # 0x2494
        ADD              R7, R3, R7, R3   # 0x2498
        C_ADDI           R6, 2   # 0x249c
        SETP_NE_NP       P0, R3, R12, R6   # 0x249e
        C_MOV            R3, R11   # 0x24a2
        BRA_PRED         0, L241c   # 0x24a4
        C_BRA            L24b2   # 0x24a8
L24aa:  MOVI             R6, 0   # 0x24aa
        LD_LOCAL         R3, 12   # 0x24ae
L24b2:  LD_LOCAL         R3, 24   # 0x24b2
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x24b6
        C_MOV            R8, R4   # 0x24ba
        LD_LOCAL         R9, 12   # 0x24bc
        MOVI             R13, 0   # 0x24c0
        BRA_PRED         0, L23ea   # 0x24c4
        C_CHWIDTH        R7, 1   # 0x24c8
        LD_LOCAL         R3, 28   # 0x24ca
        C_MUL_LO         R3, R8   # 0x24ce
        ADD              R3, R6, R3, R6   # 0x24d0
        C_SHLI           R3, 2   # 0x24d4
        ADD              R3, R9, R3, R9   # 0x24d6
        C_MOV            R9, R5   # 0x24da
        LD_LOCAL         R5, 16   # 0x24dc
        LD_GLOBAL_IDX    R3, R5, R3, 0, 0   # 0x24e0
        SETP_LT_NP       P0, R5, R11, R3   # 0x24e4
        MOVI             R5, 0   # 0x24e8
        MOVI             R6, 1   # 0x24ec
        MOV_P            R5, 0, R6, R6, R6   # 0x24f0
        ADD              R1, R3, R1, R3   # 0x24f4
        LD_LOCAL         R6, 32   # 0x24f8
        SETP_LT_NP       P0, R6, R6, R1   # 0x24fc
        MOV_P            R1, 0, R13, R13, R13   # 0x2500
        MOVI             R6, 10   # 0x2504
        MOV_P            R5, 0, R6, R6, R6   # 0x2508
        ADD              R7, R5, R7, R5   # 0x250c
        C_MOV            R5, R9   # 0x2510
        C_MOV            R11, R3   # 0x2512
        BRA              L23ea   # 0x2514
L2518:  C_MOV            R7, R1   # 0x2518
L251a:  C_CHWIDTH        R7, 0   # 0x251a
        MOVI             R1, 0   # 0x251c
        SETP_EQ_NPI      P0, R3, R8, 0   # 0x2520
        ST_LOCAL         R7, 40   # 0x2524
        BRA_PRED         0, L2778   # 0x2528
        LD_LOCAL         R3, 48   # 0x252c
        MOVI             R5, 0   # 0x2530
        C_BRA            L2546   # 0x2534
L2536:  C_ADD            R1, R8   # 0x2536
        LD_LOCAL         R5, 52   # 0x2538
        C_ADDI           R5, 1   # 0x253c
        SETP_NE_NP       P0, R3, R5, R8   # 0x253e
        BRA_PRED         4, L264a   # 0x2542
L2546:  ST_LOCAL         R5, 52   # 0x2546
        MUL_LO           R3, R5, R8, R8   # 0x254a
        ST_LOCAL         R3, 28   # 0x254e
        MOVI             R3, 0   # 0x2552
        C_BRA            L257c   # 0x2556
L2558:  LD_LOCAL         R5, 28   # 0x2558
        ADD              R5, R3, R5, R3   # 0x255c
        C_SHLI           R5, 2   # 0x2560
        LD_LOCAL         R7, 12   # 0x2562
        ADD              R5, R7, R5, R7   # 0x2566
        LD_LOCAL         R7, 16   # 0x256a
        ST_GLOBAL_IDX    R6, R7, R5, 0, 0   # 0x256e
        C_ADDI           R3, 1   # 0x2572
        SETP_NE_NP       P0, R5, R3, R8   # 0x2574
        BRA_PRED         4, L2536   # 0x2578
L257c:  LD_LOCAL         R5, 20   # 0x257c
        SETP_EQ_NPI      P0, R5, R5, 0   # 0x2580
        MOVI             R5, 0   # 0x2584
        MOVI             R6, 0   # 0x2588
        C_MOV            R9, R8   # 0x258c
        BRA_PRED         0, L2602   # 0x258e
        C_MOV            R13, R3   # 0x2592
L2594:  C_CHWIDTH        R7, 1   # 0x2594
        ADD              R8, R1, R5, R1   # 0x2596
        C_SHLI           R8, 1   # 0x259a
        C_ADD            R8, R14   # 0x259c
        C_MOV            R11, R13   # 0x259e
        C_SHLI           R11, 1   # 0x25a0
        ADD              R11, R10, R11, R10   # 0x25a2
        C_CHWIDTH        R11, 1   # 0x25a6
        LD_GLOBAL_IDX    R11, R15, R11, 0, 0   # 0x25a8
        C_CHWIDTH        R11, 0   # 0x25ac
        LD_GLOBAL_IDX    R7, R0, R8, 0, 0   # 0x25ae
        C_CHWIDTH        R7, 0   # 0x25b2
        MUL_LO           R7, R11, R7, R7   # 0x25b4
        C_MOV            R11, R7   # 0x25b8
        C_SHRI           R11, 5   # 0x25ba
        ANDI             R11, R11, 127   # 0x25bc
        C_SHRI           R7, 2   # 0x25c0
        C_ANDI           R7, 15   # 0x25c2
        MAD_ACC          R6, R7, R11   # 0x25c4
        ADDI             R7, R8, 2   # 0x25c6
        C_CHWIDTH        R7, 1   # 0x25ca
        LD_GLOBAL_IDX    R7, R0, R7, 0, 0   # 0x25cc
        C_CHWIDTH        R7, 0   # 0x25d0
        ADD              R8, R9, R13, R9   # 0x25d2
        C_SHLI           R8, 1   # 0x25d6
        ADD              R8, R10, R8, R10   # 0x25d8
        C_CHWIDTH        R8, 1   # 0x25dc
        LD_GLOBAL_IDX    R8, R15, R8, 0, 0   # 0x25de
        C_CHWIDTH        R8, 0   # 0x25e2
        MUL_LO           R7, R8, R7, R7   # 0x25e4
        C_MOV            R8, R7   # 0x25e8
        C_SHRI           R8, 5   # 0x25ea
        ANDI             R8, R8, 127   # 0x25ec
        C_SHRI           R7, 2   # 0x25f0
        C_ANDI           R7, 15   # 0x25f2
        MAD_ACC          R6, R7, R8   # 0x25f4
        C_ADD            R13, R2   # 0x25f6
        C_ADDI           R5, 2   # 0x25f8
        SETP_NE_NP       P0, R7, R12, R5   # 0x25fa
        BRA_PRED         0, L2594   # 0x25fe
L2602:  LD_LOCAL         R7, 24   # 0x2602
        SETP_EQ_NPI      P0, R7, R7, 0   # 0x2606
        C_MOV            R8, R9   # 0x260a
        BRA_PRED         0, L2558   # 0x260c
        MADLO            R7, R5, R8, R3   # 0x2610
        C_SHLI           R7, 1   # 0x2614
        ADD              R7, R10, R7, R10   # 0x2616
        C_CHWIDTH        R7, 1   # 0x261a
        LD_GLOBAL_IDX    R7, R15, R7, 0, 0   # 0x261c
        C_CHWIDTH        R7, 0   # 0x2620
        LD_LOCAL         R9, 28   # 0x2622
        C_ADD            R5, R9   # 0x2626
        C_SHLI           R5, 1   # 0x2628
        ADD              R5, R14, R5, R14   # 0x262a
        C_CHWIDTH        R5, 1   # 0x262e
        LD_GLOBAL_IDX    R5, R0, R5, 0, 0   # 0x2630
        C_CHWIDTH        R5, 0   # 0x2634
        MUL_LO           R5, R7, R5, R5   # 0x2636
        C_MOV            R7, R5   # 0x263a
        C_SHRI           R7, 5   # 0x263c
        ANDI             R7, R7, 127   # 0x263e
        C_SHRI           R5, 2   # 0x2642
        C_ANDI           R5, 15   # 0x2644
        MAD_ACC          R6, R5, R7   # 0x2646
        C_BRA            L2558   # 0x2648
L264a:  MOVI             R1, 0   # 0x264a
        C_MOV            R15, R1   # 0x264e
        MOVI             R7, 0   # 0x2650
        MOVI             R11, 0   # 0x2654
        MOVI             R10, 0   # 0x2658
        MOVI             R13, 0   # 0x265c
        LD_LOCAL         R2, 48   # 0x2660
        C_BRA            L2672   # 0x2664
L2666:  C_ADD            R7, R8   # 0x2666
        C_ADDI           R11, 1   # 0x2668
        SETP_NE_NP       P0, R2, R11, R8   # 0x266a
        BRA_PRED         4, L277a   # 0x266e
L2672:  ST_LOCAL         R11, 28   # 0x2672
        LD_LOCAL         R2, 20   # 0x2676
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x267a
        BRA_PRED         0, L270e   # 0x267e
        MOVI             R2, 0   # 0x2682
        C_MOV            R3, R10   # 0x2686
        LD_LOCAL         R11, 16   # 0x2688
        LD_LOCAL         R1, 12   # 0x268c
        LD_LOCAL         R6, 32   # 0x2690
        MOVI             R1, 10   # 0x2694
L2698:  C_CHWIDTH        R15, 1   # 0x2698
        ADD              R5, R7, R2, R7   # 0x269a
        C_SHLI           R5, 2   # 0x269e
        LD_LOCAL         R8, 12   # 0x26a0
        C_ADD            R5, R8   # 0x26a4
        C_MOV            R9, R7   # 0x26a6
        ADDI             R7, R5, 4   # 0x26a8
        LD_GLOBAL_IDX    R10, R11, R7, 0, 0   # 0x26ac
        LD_GLOBAL_IDX    R5, R11, R5, 0, 0   # 0x26b0
        SETP_LT_NP       P0, R3, R3, R5   # 0x26b4
        SETP_LT_NP       P1, R3, R5, R10   # 0x26b8
        MOVI             R3, 0   # 0x26bc
        MOVI             R8, 1   # 0x26c0
        MOV_P            R3, 1, R8, R8, R8   # 0x26c4
        MOVI             R7, 0   # 0x26c8
        MOV_P            R7, 0, R8, R8, R8   # 0x26cc
        C_ADD            R5, R13   # 0x26d0
        SETP_LT_NP       P0, R8, R6, R5   # 0x26d2
        MOV_P            R7, 0, R1, R1, R1   # 0x26d6
        C_CHWIDTH        R7, 1   # 0x26da
        MOVI             R8, 0   # 0x26dc
        MOV_P            R5, 0, R8, R8, R8   # 0x26e0
        ADD              R13, R10, R5, R10   # 0x26e4
        SETP_LT_NP       P0, R5, R6, R13   # 0x26e8
        MOV_P            R3, 0, R1, R1, R1   # 0x26ec
        MOV_P            R13, 0, R8, R8, R8   # 0x26f0
        ADD              R7, R7, R15, R7   # 0x26f4
        ADD              R15, R3, R7, R3   # 0x26f8
        C_CHWIDTH        R7, 0   # 0x26fc
        C_MOV            R7, R9   # 0x26fe
        C_ADDI           R2, 2   # 0x2700
        SETP_NE_NP       P0, R3, R12, R2   # 0x2702
        C_MOV            R3, R10   # 0x2706
        BRA_PRED         0, L2698   # 0x2708
        C_BRA            L2716   # 0x270c
L270e:  MOVI             R2, 0   # 0x270e
        LD_LOCAL         R1, 12   # 0x2712
L2716:  LD_LOCAL         R3, 24   # 0x2716
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x271a
        C_MOV            R8, R4   # 0x271e
        LD_LOCAL         R9, 12   # 0x2720
        MOVI             R1, 0   # 0x2724
        MOVI             R5, 1   # 0x2728
        MOVI             R6, 10   # 0x272c
        LD_LOCAL         R11, 28   # 0x2730
        BRA_PRED         0, L2666   # 0x2734
        C_CHWIDTH        R15, 1   # 0x2738
        MUL_LO           R3, R11, R8, R8   # 0x273a
        C_ADD            R2, R3   # 0x273e
        C_SHLI           R2, 2   # 0x2740
        ADD              R2, R9, R2, R9   # 0x2742
        LD_LOCAL         R3, 16   # 0x2746
        LD_GLOBAL_IDX    R2, R3, R2, 0, 0   # 0x274a
        SETP_LT_NP       P0, R3, R10, R2   # 0x274e
        MOVI             R3, 0   # 0x2752
        MOV_P            R3, 0, R5, R5, R5   # 0x2756
        ADD              R13, R2, R13, R2   # 0x275a
        LD_LOCAL         R5, 32   # 0x275e
        SETP_LT_NP       P0, R5, R5, R13   # 0x2762
        MOV_P            R13, 0, R1, R1, R1   # 0x2766
        MOV_P            R3, 0, R6, R6, R6   # 0x276a
        ADD              R15, R3, R15, R3   # 0x276e
        C_MOV            R10, R2   # 0x2772
        BRA              L2666   # 0x2774
L2778:  C_MOV            R15, R1   # 0x2778
L277a:  C_MOV            R1, R8   # 0x277a
        LD_LOCAL         R2, 64   # 0x277c
        C_MOV            R8, R2   # 0x2780
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x2782
        LD_LOCAL         R9, 60   # 0x2786
        LD_LOCAL         R1, 44   # 0x278a
        BRA_PRED         0, L2850   # 0x278e
        MOVI             R10, 0   # 0x2792
        ANDI             R2, R4, 3   # 0x2796
        MOVI             R5, 0   # 0x279a
        C_BRA            L27b2   # 0x279e
L27a0:  CHWIDTH_MULTI    8192, 0   # 0x27a0
        C_MOV            R3, R4   # 0x27a4
        C_ADD            R10, R3   # 0x27a6
        C_ADDI           R5, 1   # 0x27a8
        SETP_NE_NP       P0, R3, R5, R3   # 0x27aa
        BRA_PRED         4, L2850   # 0x27ae
L27b2:  LD_LOCAL         R3, 20   # 0x27b2
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x27b6
        MOVI             R3, 0   # 0x27ba
        LD_LOCAL         R11, 48   # 0x27be
        BRA_PRED         0, L281c   # 0x27c2
L27c6:  CHWIDTH_MULTI    8320, 1   # 0x27c6
        ADD              R6, R10, R3, R10   # 0x27ca
        C_SHLI           R6, 1   # 0x27ce
        ADD              R6, R14, R6, R14   # 0x27d0
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27d4
        SUB              R7, R7, R9, R7   # 0x27d8
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27dc
        C_CHWIDTH        R7, 0   # 0x27e0
        ADDI             R7, R6, 2   # 0x27e2
        LD_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27e6
        SUB              R13, R13, R9, R13   # 0x27ea
        ST_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27ee
        ADDI             R7, R6, 4   # 0x27f2
        LD_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27f6
        SUB              R13, R13, R9, R13   # 0x27fa
        ST_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27fe
        C_CHWIDTH        R7, 1   # 0x2802
        C_ADDI           R6, 6   # 0x2804
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x2806
        SUB              R7, R7, R9, R7   # 0x280a
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x280e
        C_ADDI           R3, 4   # 0x2812
        SETP_NE_NP       P0, R6, R11, R3   # 0x2814
        BRA_PRED         0, L27c6   # 0x2818
L281c:  SETP_EQ_NPI      P0, R6, R2, 0   # 0x281c
        BRA_PRED         0, L27a0   # 0x2820
        C_ADD            R3, R10   # 0x2824
        C_MOV            R6, R2   # 0x2826
L2828:  C_CHWIDTH        R13, 1   # 0x2828
        C_CHWIDTH        R7, 0   # 0x282a
        C_MOV            R7, R3   # 0x282c
        C_SHLI           R7, 1   # 0x282e
        ADD              R7, R14, R7, R14   # 0x2830
        LD_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x2834
        SUB              R13, R13, R9, R13   # 0x2838
        ST_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x283c
        C_ADDI           R3, 1   # 0x2840
        ADDI             R6, R6, -1   # 0x2842
        SETP_NE_NPI      P0, R7, R6, 0   # 0x2846
        BRA_PRED         0, L2828   # 0x284a
        C_BRA            L27a0   # 0x284e
L2850:  CHWIDTH_MULTI    32896, 0   # 0x2850
        MOVI             R2, 0   # 0x2854
        CALL             R14, 129275   # 0x2858
        C_MOV            R2, R1   # 0x285c
        LD_LOCAL         R1, 36   # 0x285e
        CALL             R14, 129270   # 0x2862
        C_MOV            R2, R1   # 0x2866
        LD_LOCAL         R1, 40   # 0x2868
        CALL             R14, 129265   # 0x286c
        C_MOV            R2, R1   # 0x2870
        C_MOV            R1, R15   # 0x2872
        CALL             R14, 129261   # 0x2874
        C_MOV            R2, R8   # 0x2878
        CALL             R14, 129258   # 0x287a
        LD_LOCAL         R14, 56   # 0x287e
        LD_LOCAL         R13, 92   # 0x2882
        LD_LOCAL         R12, 88   # 0x2886
        LD_LOCAL         R11, 84   # 0x288a
        LD_LOCAL         R10, 80   # 0x288e
        LD_LOCAL         R9, 76   # 0x2892
        LD_LOCAL         R8, 72   # 0x2896
        C_RET            224   # 0x289a
        C_CHWIDTH        R0, 1   # 0x289c
        XOR              R0, R2, R1, R2   # 0x289e
        C_CHWIDTH        R0, 0   # 0x28a2
        C_ANDI           R0, 1   # 0x28a4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x28a6
        MOVI             R0, 40961   # 0x28aa
        SHRI             R2, R2, 1   # 0x28ae
        C_MOV            R3, R2   # 0x28b2
        C_CHWIDTH        R2, 1   # 0x28b4
        XOR              R2, R2, R0, R2   # 0x28b6
        C_CHWIDTH        R2, 0   # 0x28ba
        MOV_P            R3, 0, R2, R2, R2   # 0x28bc
        SHRI             R2, R1, 1   # 0x28c0
        C_CHWIDTH        R2, 1   # 0x28c4
        XOR              R2, R2, R3, R2   # 0x28c6
        C_CHWIDTH        R2, 0   # 0x28ca
        C_ANDI           R2, 1   # 0x28cc
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28ce
        SHRI             R2, R3, 1   # 0x28d2
        C_MOV            R3, R2   # 0x28d6
        C_CHWIDTH        R2, 1   # 0x28d8
        XOR              R2, R2, R0, R2   # 0x28da
        C_CHWIDTH        R2, 0   # 0x28de
        MOV_P            R3, 0, R2, R2, R2   # 0x28e0
        SHRI             R2, R1, 2   # 0x28e4
        C_CHWIDTH        R2, 1   # 0x28e8
        XOR              R2, R2, R3, R2   # 0x28ea
        C_CHWIDTH        R2, 0   # 0x28ee
        C_ANDI           R2, 1   # 0x28f0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28f2
        SHRI             R2, R3, 1   # 0x28f6
        C_MOV            R3, R2   # 0x28fa
        C_CHWIDTH        R2, 1   # 0x28fc
        XOR              R2, R2, R0, R2   # 0x28fe
        C_CHWIDTH        R2, 0   # 0x2902
        MOV_P            R3, 0, R2, R2, R2   # 0x2904
        SHRI             R2, R1, 3   # 0x2908
        C_CHWIDTH        R2, 1   # 0x290c
        XOR              R2, R2, R3, R2   # 0x290e
        C_CHWIDTH        R2, 0   # 0x2912
        C_ANDI           R2, 1   # 0x2914
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2916
        SHRI             R2, R3, 1   # 0x291a
        C_MOV            R3, R2   # 0x291e
        C_CHWIDTH        R2, 1   # 0x2920
        XOR              R2, R2, R0, R2   # 0x2922
        C_CHWIDTH        R2, 0   # 0x2926
        MOV_P            R3, 0, R2, R2, R2   # 0x2928
        SHRI             R2, R1, 4   # 0x292c
        C_CHWIDTH        R2, 1   # 0x2930
        XOR              R2, R2, R3, R2   # 0x2932
        C_CHWIDTH        R2, 0   # 0x2936
        C_ANDI           R2, 1   # 0x2938
        SETP_NE_NPI      P0, R2, R2, 0   # 0x293a
        SHRI             R2, R3, 1   # 0x293e
        C_MOV            R3, R2   # 0x2942
        C_CHWIDTH        R2, 1   # 0x2944
        XOR              R2, R2, R0, R2   # 0x2946
        C_CHWIDTH        R2, 0   # 0x294a
        MOV_P            R3, 0, R2, R2, R2   # 0x294c
        SHRI             R2, R1, 5   # 0x2950
        C_CHWIDTH        R2, 1   # 0x2954
        XOR              R2, R2, R3, R2   # 0x2956
        C_CHWIDTH        R2, 0   # 0x295a
        C_ANDI           R2, 1   # 0x295c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x295e
        SHRI             R2, R3, 1   # 0x2962
        C_MOV            R3, R2   # 0x2966
        C_CHWIDTH        R2, 1   # 0x2968
        XOR              R2, R2, R0, R2   # 0x296a
        C_CHWIDTH        R2, 0   # 0x296e
        MOV_P            R3, 0, R2, R2, R2   # 0x2970
        SHRI             R2, R1, 6   # 0x2974
        C_CHWIDTH        R2, 1   # 0x2978
        XOR              R2, R2, R3, R2   # 0x297a
        C_CHWIDTH        R2, 0   # 0x297e
        C_ANDI           R2, 1   # 0x2980
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2982
        SHRI             R2, R3, 1   # 0x2986
        C_MOV            R3, R2   # 0x298a
        C_CHWIDTH        R2, 1   # 0x298c
        XOR              R2, R2, R0, R2   # 0x298e
        C_CHWIDTH        R2, 0   # 0x2992
        MOV_P            R3, 0, R2, R2, R2   # 0x2994
        MOVI             R2, 128   # 0x2998
        C_CHWIDTH        R2, 1   # 0x299c
        AND              R2, R1, R2, R1   # 0x299e
        C_CHWIDTH        R2, 0   # 0x29a2
        SHRI             R2, R2, 7   # 0x29a4
        ANDI             R4, R3, 1   # 0x29a8
        SETP_EQ_NP       P0, R2, R2, R4   # 0x29ac
        SHRI             R2, R3, 1   # 0x29b0
        C_MOV            R3, R2   # 0x29b4
        C_CHWIDTH        R2, 1   # 0x29b6
        XOR              R2, R2, R0, R2   # 0x29b8
        C_CHWIDTH        R2, 0   # 0x29bc
        MOV_P            R2, 0, R3, R3, R3   # 0x29be
        SHRI             R3, R1, 8   # 0x29c2
        C_CHWIDTH        R3, 1   # 0x29c6
        XOR              R3, R2, R3, R2   # 0x29c8
        C_CHWIDTH        R3, 0   # 0x29cc
        C_ANDI           R3, 1   # 0x29ce
        SETP_NE_NPI      P0, R3, R3, 0   # 0x29d0
        SHRI             R2, R2, 1   # 0x29d4
        C_MOV            R3, R2   # 0x29d8
        C_CHWIDTH        R2, 1   # 0x29da
        XOR              R2, R2, R0, R2   # 0x29dc
        C_CHWIDTH        R2, 0   # 0x29e0
        MOV_P            R3, 0, R2, R2, R2   # 0x29e2
        SHRI             R2, R1, 9   # 0x29e6
        C_CHWIDTH        R2, 1   # 0x29ea
        XOR              R2, R2, R3, R2   # 0x29ec
        C_CHWIDTH        R2, 0   # 0x29f0
        C_ANDI           R2, 1   # 0x29f2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29f4
        SHRI             R2, R3, 1   # 0x29f8
        C_MOV            R3, R2   # 0x29fc
        C_CHWIDTH        R2, 1   # 0x29fe
        XOR              R2, R2, R0, R2   # 0x2a00
        C_CHWIDTH        R2, 0   # 0x2a04
        MOV_P            R3, 0, R2, R2, R2   # 0x2a06
        SHRI             R2, R1, 10   # 0x2a0a
        C_CHWIDTH        R2, 1   # 0x2a0e
        XOR              R2, R2, R3, R2   # 0x2a10
        C_CHWIDTH        R2, 0   # 0x2a14
        C_ANDI           R2, 1   # 0x2a16
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a18
        SHRI             R2, R3, 1   # 0x2a1c
        C_MOV            R3, R2   # 0x2a20
        C_CHWIDTH        R2, 1   # 0x2a22
        XOR              R2, R2, R0, R2   # 0x2a24
        C_CHWIDTH        R2, 0   # 0x2a28
        MOV_P            R3, 0, R2, R2, R2   # 0x2a2a
        SHRI             R2, R1, 11   # 0x2a2e
        C_CHWIDTH        R2, 1   # 0x2a32
        XOR              R2, R2, R3, R2   # 0x2a34
        C_CHWIDTH        R2, 0   # 0x2a38
        C_ANDI           R2, 1   # 0x2a3a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a3c
        SHRI             R2, R3, 1   # 0x2a40
        C_MOV            R3, R2   # 0x2a44
        C_CHWIDTH        R2, 1   # 0x2a46
        XOR              R2, R2, R0, R2   # 0x2a48
        C_CHWIDTH        R2, 0   # 0x2a4c
        MOV_P            R3, 0, R2, R2, R2   # 0x2a4e
        SHRI             R2, R1, 12   # 0x2a52
        C_CHWIDTH        R2, 1   # 0x2a56
        XOR              R2, R2, R3, R2   # 0x2a58
        C_CHWIDTH        R2, 0   # 0x2a5c
        C_ANDI           R2, 1   # 0x2a5e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a60
        SHRI             R2, R3, 1   # 0x2a64
        C_MOV            R3, R2   # 0x2a68
        C_CHWIDTH        R2, 1   # 0x2a6a
        XOR              R2, R2, R0, R2   # 0x2a6c
        C_CHWIDTH        R2, 0   # 0x2a70
        MOV_P            R3, 0, R2, R2, R2   # 0x2a72
        SHRI             R2, R1, 13   # 0x2a76
        C_CHWIDTH        R2, 1   # 0x2a7a
        XOR              R2, R2, R3, R2   # 0x2a7c
        C_CHWIDTH        R2, 0   # 0x2a80
        C_ANDI           R2, 1   # 0x2a82
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a84
        SHRI             R2, R3, 1   # 0x2a88
        C_MOV            R3, R2   # 0x2a8c
        C_CHWIDTH        R2, 1   # 0x2a8e
        XOR              R2, R2, R0, R2   # 0x2a90
        C_CHWIDTH        R2, 0   # 0x2a94
        MOV_P            R3, 0, R2, R2, R2   # 0x2a96
        SHRI             R2, R1, 14   # 0x2a9a
        C_CHWIDTH        R2, 1   # 0x2a9e
        XOR              R2, R2, R3, R2   # 0x2aa0
        C_CHWIDTH        R2, 0   # 0x2aa4
        C_ANDI           R2, 1   # 0x2aa6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2aa8
        SHRI             R2, R3, 1   # 0x2aac
        C_MOV            R3, R2   # 0x2ab0
        C_CHWIDTH        R2, 1   # 0x2ab2
        XOR              R2, R2, R0, R2   # 0x2ab4
        C_CHWIDTH        R0, 1   # 0x2ab8
        C_CHWIDTH        R2, 0   # 0x2aba
        MOV_P            R3, 0, R2, R2, R2   # 0x2abc
        SHRI             R1, R1, 15   # 0x2ac0
        ANDI             R2, R3, 1   # 0x2ac4
        SETP_EQ_NP       P0, R1, R1, R2   # 0x2ac8
        SHRI             R1, R3, 1   # 0x2acc
        C_MOV            R2, R1   # 0x2ad0
        XOR              R0, R1, R0, R1   # 0x2ad2
        C_CHWIDTH        R0, 0   # 0x2ad6
        MOV_P            R0, 0, R2, R2, R2   # 0x2ad8
        MOVI             R1, 65535   # 0x2adc
        AND              R1, R0, R1, R0   # 0x2ae0
        C_RET            224   # 0x2ae4
        C_CHWIDTH        R6, 1   # 0x2ae6
        MOVI             R15, 2   # 0x2ae8
        LD_GLOBAL        R15, R15, 24   # 0x2aec
        SRD              R0, 2   # 0x2af0
        C_ADD            R15, R0   # 0x2af2
        ST_LOCAL         R8, 172   # 0x2af4
        ST_LOCAL         R9, 176   # 0x2af8
        ST_LOCAL         R10, 180   # 0x2afc
        ST_LOCAL         R11, 184   # 0x2b00
        ST_LOCAL         R12, 188   # 0x2b04
        ST_LOCAL         R13, 192   # 0x2b08
        ST_LOCAL         R14, 160   # 0x2b0c
        ST_LOCAL         R2, 108   # 0x2b10
        C_MOV            R13, R1   # 0x2b14
        LD_GLOBAL_IDX    R0, R13, R2, 0, 60   # 0x2b16
        SHLI             R0, R0, 16   # 0x2b1a
        LD_GLOBAL_IDX    R1, R13, R2, 0, 56   # 0x2b1e
        SHRI             R4, R1, 16   # 0x2b22
        OR               R8, R0, R4, R0   # 0x2b26
        MOVI             R0, 65535   # 0x2b2a
        C_AND            R1, R0   # 0x2b2e
        LD_GLOBAL_IDX    R6, R13, R2, 0, 4   # 0x2b30
        C_MOV            R5, R3   # 0x2b34
        CVT_SEXT         R2, R6, R6, R6   # 0x2b36
        SETP_LT_NPI      P0, R2, R2, 1   # 0x2b3a
        BRA_PRED         0, L2e7a   # 0x2b3e
        CHWIDTH_MULTI    16416, 1   # 0x2b42
        ST_LOCAL         R3, 104   # 0x2b46
        MOVI             R2, 0   # 0x2b4a
        ADDI             R14, R6, 255   # 0x2b4e
        C_CHWIDTH        R14, 0   # 0x2b52
        ST_LOCAL         R14, 112   # 0x2b54
        C_MOV            R7, R2   # 0x2b58
        ST_LOCAL         R2, 96   # 0x2b5a
        ST_LOCAL         R2, 100   # 0x2b5e
        C_BRA            L2bde   # 0x2b62
L2b64:  C_CHWIDTH        R12, 1   # 0x2b64
        C_MOV            R4, R8   # 0x2b66
        C_MOV            R14, R1   # 0x2b68
        LD_GLOBAL_IDX    R3, R4, R14, 0, 0   # 0x2b6a
        LD_GLOBAL_IDX    R4, R4, R14, 0, 4   # 0x2b6e
        SHLI             R4, R4, 16   # 0x2b72
        SHRI             R14, R3, 16   # 0x2b76
        C_OR             R4, R14   # 0x2b7a
        C_AND            R3, R0   # 0x2b7c
        LD_GLOBAL_IDX    R14, R4, R3, 0, 8   # 0x2b7e
        LD_GLOBAL_IDX    R3, R4, R3, 0, 12   # 0x2b82
        SHLI             R3, R3, 16   # 0x2b86
        SHRI             R4, R14, 16   # 0x2b8a
        C_OR             R3, R4   # 0x2b8e
        C_CHWIDTH        R3, 1   # 0x2b90
        AND              R4, R14, R0, R14   # 0x2b92
        LD_GLOBAL_IDX    R3, R3, R4, 0, 0   # 0x2b96
        C_CHWIDTH        R3, 0   # 0x2b9a
        SHRI             R3, R3, 8   # 0x2b9c
        MOVI             R4, 1   # 0x2ba0
        AND              R12, R3, R4, R3   # 0x2ba4
        LD_LOCAL         R14, 100   # 0x2ba8
        C_CHWIDTH        R14, 1   # 0x2bac
        ADDI             R14, R14, 1   # 0x2bae
        C_CHWIDTH        R14, 0   # 0x2bb2
        ST_LOCAL         R14, 100   # 0x2bb4
L2bb8:  C_CHWIDTH        R6, 0   # 0x2bb8
        CHWIDTH_MULTI    172, 1   # 0x2bba
        ADD              R7, R12, R7, R12   # 0x2bbe
        XOR              R3, R5, R0, R5   # 0x2bc2
        C_CHWIDTH        R3, 0   # 0x2bc6
        SHRI             R3, R3, 15   # 0x2bc8
        ADD              R5, R5, R3, R5   # 0x2bcc
        ADDI             R2, R2, 1   # 0x2bd0
        C_CHWIDTH        R2, 0   # 0x2bd4
        SETP_NE_NP       P0, R3, R2, R6   # 0x2bd6
        BRA_PRED         4, L2e3e   # 0x2bda
L2bde:  C_CHWIDTH        R12, 0   # 0x2bde
        C_MOV            R12, R8   # 0x2be0
        SHLI             R4, R12, 16   # 0x2be2
        C_MOV            R10, R1   # 0x2be6
        AND              R14, R4, R10, R4   # 0x2be8
        ADD              R9, R4, R10, R4   # 0x2bec
        C_OR             R4, R10   # 0x2bf0
        C_ANDN           R4, R9   # 0x2bf2
        OR               R4, R14, R4, R14   # 0x2bf4
        SHRI             R4, R4, 31   # 0x2bf8
        SHRI             R14, R12, 16   # 0x2bfc
        ADD              R4, R14, R4, R14   # 0x2c00
        OR               R11, R9, R4, R9   # 0x2c04
        CVT_SEXT         R4, R5, R5, R5   # 0x2c08
        MOVI48           R3, 4294967295   # 0x2c0c
        SETP_LT_NP       P0, R4, R3, R4   # 0x2c12
        BRA_PRED         4, L2c7a   # 0x2c16
        MOVI             R9, 0   # 0x2c1a
        SETP_EQ_NPI      P0, R4, R11, 0   # 0x2c1e
        BRA_PRED         0, L2ce0   # 0x2c22
        C_MOV            R12, R8   # 0x2c26
        C_MOV            R10, R1   # 0x2c28
L2c2a:  C_CHWIDTH        R5, 0   # 0x2c2a
        LD_GLOBAL_IDX    R4, R12, R10, 0, 8   # 0x2c2c
        LD_GLOBAL_IDX    R14, R12, R10, 0, 12   # 0x2c30
        SHLI             R14, R14, 16   # 0x2c34
        SHRI             R3, R4, 16   # 0x2c38
        OR               R3, R14, R3, R14   # 0x2c3c
        C_CHWIDTH        R3, 1   # 0x2c40
        C_AND            R4, R0   # 0x2c42
        LD_GLOBAL_IDX    R3, R3, R4, 0, 2   # 0x2c44
        C_CHWIDTH        R3, 0   # 0x2c48
        SETP_EQ_NP       P0, R3, R3, R5   # 0x2c4a
        BRA_PRED         0, L2d50   # 0x2c4e
        LD_GLOBAL_IDX    R3, R12, R10, 0, 4   # 0x2c52
        LD_GLOBAL_IDX    R4, R12, R10, 0, 0   # 0x2c56
        SHRI             R14, R4, 16   # 0x2c5a
        SHLI             R10, R3, 16   # 0x2c5e
        OR               R12, R10, R14, R10   # 0x2c62
        C_AND            R3, R0   # 0x2c66
        OR               R3, R4, R3, R4   # 0x2c68
        AND              R10, R4, R0, R4   # 0x2c6c
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c70
        BRA_PRED         4, L2c2a   # 0x2c74
        C_BRA            L2ce0   # 0x2c78
L2c7a:  MOVI             R9, 0   # 0x2c7a
        SETP_EQ_NPI      P0, R4, R11, 0   # 0x2c7e
        BRA_PRED         0, L2ce0   # 0x2c82
L2c86:  LD_GLOBAL_IDX    R3, R12, R10, 0, 8   # 0x2c86
        LD_GLOBAL_IDX    R4, R12, R10, 0, 12   # 0x2c8a
        SHLI             R4, R4, 16   # 0x2c8e
        SHRI             R14, R3, 16   # 0x2c92
        C_OR             R4, R14   # 0x2c96
        C_CHWIDTH        R14, 1   # 0x2c98
        C_AND            R3, R0   # 0x2c9a
        LD_GLOBAL_IDX    R14, R4, R3, 0, 0   # 0x2c9c
        XOR              R14, R14, R2, R14   # 0x2ca0
        MOVI             R3, 255   # 0x2ca4
        C_CHWIDTH        R3, 1   # 0x2ca8
        AND              R3, R14, R3, R14   # 0x2caa
        C_CHWIDTH        R3, 0   # 0x2cae
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2cb0
        BRA_PRED         0, L2d50   # 0x2cb4
        C_CHWIDTH        R14, 0   # 0x2cb8
        LD_GLOBAL_IDX    R3, R12, R10, 0, 4   # 0x2cba
        LD_GLOBAL_IDX    R4, R12, R10, 0, 0   # 0x2cbe
        SHRI             R14, R4, 16   # 0x2cc2
        SHLI             R10, R3, 16   # 0x2cc6
        OR               R12, R10, R14, R10   # 0x2cca
        C_AND            R3, R0   # 0x2cce
        OR               R3, R4, R3, R4   # 0x2cd0
        AND              R10, R4, R0, R4   # 0x2cd4
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2cd8
        BRA_PRED         0, L2c86   # 0x2cdc
L2ce0:  MOVI             R10, 0   # 0x2ce0
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2ce4
        BRA_PRED         0, L2d5a   # 0x2ce8
L2cec:  MOVI             R11, 0   # 0x2cec
        MOVI             R4, 0   # 0x2cf0
L2cf4:  C_CHWIDTH        R14, 0   # 0x2cf4
        C_MOV            R14, R1   # 0x2cf6
        C_MOV            R12, R8   # 0x2cf8
        SHLI             R3, R11, 16   # 0x2cfa
        AND              R1, R3, R4, R3   # 0x2cfe
        ADD              R8, R3, R4, R3   # 0x2d02
        C_OR             R3, R4   # 0x2d06
        C_ANDN           R3, R8   # 0x2d08
        OR               R3, R1, R3, R1   # 0x2d0a
        SHRI             R3, R3, 31   # 0x2d0e
        SHRI             R4, R11, 16   # 0x2d12
        ADD              R3, R4, R3, R4   # 0x2d16
        LD_GLOBAL_IDX    R4, R12, R14, 0, 0   # 0x2d1a
        ST_GLOBAL_IDX    R8, R12, R14, 0, 0   # 0x2d1e
        LD_GLOBAL_IDX    R1, R12, R14, 0, 4   # 0x2d22
        ST_GLOBAL_IDX    R3, R12, R14, 0, 4   # 0x2d26
        SHRI             R3, R4, 16   # 0x2d2a
        SHLI             R11, R1, 16   # 0x2d2e
        OR               R8, R11, R3, R11   # 0x2d32
        AND              R3, R1, R0, R1   # 0x2d36
        OR               R3, R4, R3, R4   # 0x2d3a
        AND              R1, R4, R0, R4   # 0x2d3e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d42
        C_MOV            R11, R12   # 0x2d46
        C_MOV            R4, R14   # 0x2d48
        BRA_PRED         0, L2cf4   # 0x2d4a
        C_BRA            L2d64   # 0x2d4e
L2d50:  C_MOV            R9, R12   # 0x2d50
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2d52
        BRA_PRED         4, L2cec   # 0x2d56
L2d5a:  C_CHWIDTH        R14, 0   # 0x2d5a
        MOVI             R12, 0   # 0x2d5c
        MOVI             R14, 0   # 0x2d60
L2d64:  C_MOV            R1, R14   # 0x2d64
        C_MOV            R8, R12   # 0x2d66
        SHLI             R3, R9, 16   # 0x2d68
        AND              R4, R3, R10, R3   # 0x2d6c
        ADD              R14, R3, R10, R3   # 0x2d70
        C_OR             R3, R10   # 0x2d74
        C_ANDN           R3, R14   # 0x2d76
        OR               R3, R4, R3, R4   # 0x2d78
        SHRI             R3, R3, 31   # 0x2d7c
        SHRI             R4, R9, 16   # 0x2d80
        ADD              R3, R4, R3, R4   # 0x2d84
        OR               R3, R14, R3, R14   # 0x2d88
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d8c
        BRA_PRED         4, L2b64   # 0x2d90
        LD_GLOBAL_IDX    R3, R9, R10, 0, 12   # 0x2d94
        SHLI             R3, R3, 16   # 0x2d98
        LD_GLOBAL_IDX    R4, R9, R10, 0, 8   # 0x2d9c
        SHRI             R14, R4, 16   # 0x2da0
        C_OR             R3, R14   # 0x2da4
        C_CHWIDTH        R3, 1   # 0x2da6
        C_AND            R4, R0   # 0x2da8
        LD_GLOBAL_IDX    R3, R3, R4, 0, 0   # 0x2daa
        C_CHWIDTH        R3, 0   # 0x2dae
        LD_GLOBAL_IDX    R14, R9, R10, 0, 4   # 0x2db0
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2db4
        SHRI             R11, R3, 9   # 0x2db8
        C_CHWIDTH        R3, 1   # 0x2dbc
        AND              R3, R3, R11, R3   # 0x2dbe
        AND              R11, R14, R0, R14   # 0x2dc2
        OR               R11, R4, R11, R4   # 0x2dc6
        MOVI             R12, 1   # 0x2dca
        C_CHWIDTH        R12, 1   # 0x2dce
        AND              R12, R3, R12, R3   # 0x2dd0
        C_CHWIDTH        R3, 0   # 0x2dd4
        LD_LOCAL         R3, 96   # 0x2dd6
        C_CHWIDTH        R3, 1   # 0x2dda
        ADDI             R3, R3, 1   # 0x2ddc
        C_CHWIDTH        R3, 0   # 0x2de0
        ST_LOCAL         R3, 96   # 0x2de2
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2de6
        BRA_PRED         0, L2bb8   # 0x2dea
        SHRI             R3, R4, 16   # 0x2dee
        SHLI             R14, R14, 16   # 0x2df2
        OR               R3, R14, R3, R14   # 0x2df6
        C_CHWIDTH        R14, 1   # 0x2dfa
        C_AND            R4, R0   # 0x2dfc
        LD_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x2dfe
        C_CHWIDTH        R14, 0   # 0x2e02
        LD_GLOBAL_IDX    R11, R3, R4, 0, 0   # 0x2e04
        ST_GLOBAL_IDX    R11, R9, R10, 0, 0   # 0x2e08
        ST_GLOBAL_IDX    R14, R9, R10, 0, 4   # 0x2e0c
        C_CHWIDTH        R14, 1   # 0x2e10
        C_MOV            R10, R8   # 0x2e12
        C_MOV            R11, R1   # 0x2e14
        LD_GLOBAL_IDX    R14, R10, R11, 0, 4   # 0x2e16
        C_CHWIDTH        R14, 0   # 0x2e1a
        LD_GLOBAL_IDX    R9, R10, R11, 0, 0   # 0x2e1c
        ST_GLOBAL_IDX    R9, R3, R4, 0, 0   # 0x2e20
        ST_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x2e24
        SHRI             R14, R3, 16   # 0x2e28
        ST_GLOBAL_IDX    R14, R10, R11, 0, 4   # 0x2e2c
        SHLI             R3, R3, 16   # 0x2e30
        C_OR             R3, R4   # 0x2e34
        ST_GLOBAL_IDX    R3, R10, R11, 0, 0   # 0x2e36
        BRA              L2bb8   # 0x2e3a
L2e3e:  CHWIDTH_MULTI    32, 0   # 0x2e3e
        C_CHWIDTH        R2, 1   # 0x2e42
        MOVI             R0, 255   # 0x2e44
        LD_LOCAL         R14, 112   # 0x2e48
        AND              R2, R14, R0, R14   # 0x2e4c
        CHWIDTH_MULTI    4, 0   # 0x2e50
        LD_LOCAL         R0, 96   # 0x2e54
        SHLI             R0, R0, 2   # 0x2e58
        LD_LOCAL         R14, 100   # 0x2e5c
        C_CHWIDTH        R14, 1   # 0x2e60
        SUB              R14, R0, R14, R0   # 0x2e62
        C_CHWIDTH        R0, 1   # 0x2e66
        ADD              R0, R14, R7, R14   # 0x2e68
        CHWIDTH_MULTI    16513, 0   # 0x2e6c
        ST_LOCAL         R0, 156   # 0x2e70
        LD_LOCAL         R3, 104   # 0x2e74
        C_BRA            L2e88   # 0x2e78
L2e7a:  CHWIDTH_MULTI    64, 0   # 0x2e7a
        MOVI             R0, 0   # 0x2e7e
        C_MOV            R2, R0   # 0x2e82
        ST_LOCAL         R2, 156   # 0x2e84
L2e88:  CHWIDTH_MULTI    4096, 0   # 0x2e88
        ST_LOCAL         R5, 164   # 0x2e8c
        C_MOV            R14, R3   # 0x2e90
        C_CHWIDTH        R14, 1   # 0x2e92
        C_MOV            R7, R3   # 0x2e94
        C_CHWIDTH        R7, 1   # 0x2e96
        C_MOV            R6, R3   # 0x2e98
        C_CHWIDTH        R6, 1   # 0x2e9a
        CVT_SEXT         R0, R14, R7, R6   # 0x2e9c
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2ea0
        ST_LOCAL         R2, 168   # 0x2ea4
        BRA_PRED         0, L3488   # 0x2ea8
        CHWIDTH_MULTI    192, 0   # 0x2eac
        MOVI             R0, 1   # 0x2eb0
        ST_LOCAL         R0, 144   # 0x2eb4
        MOVI             R12, 65535   # 0x2eb8
        C_MOV            R7, R8   # 0x2ebc
        C_MOV            R6, R1   # 0x2ebe
        ST_LOCAL         R13, 132   # 0x2ec0
        C_BRA            L2ef4   # 0x2ec4
L2ec6:  MOVI             R0, 0   # 0x2ec6
        ST_GLOBAL_IDX    R0, R10, R11, 0, 4   # 0x2eca
        ST_GLOBAL_IDX    R0, R10, R11, 0, 0   # 0x2ece
        LD_LOCAL         R0, 144   # 0x2ed2
        C_SHLI           R0, 1   # 0x2ed6
        ST_LOCAL         R0, 144   # 0x2ed8
        LD_LOCAL         R0, 152   # 0x2edc
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2ee0
        LD_LOCAL         R8, 140   # 0x2ee4
        C_MOV            R7, R8   # 0x2ee8
        LD_LOCAL         R9, 136   # 0x2eea
        C_MOV            R6, R9   # 0x2eee
        BRA_PRED         4, L348e   # 0x2ef0
L2ef4:  MOVI             R5, 0   # 0x2ef4
        MOVI             R10, 0   # 0x2ef8
        MOVI             R11, 0   # 0x2efc
        MOVI             R0, 0   # 0x2f00
        ST_LOCAL         R0, 140   # 0x2f04
        ST_LOCAL         R0, 136   # 0x2f08
        C_BRA            L2f1a   # 0x2f0c
L2f0e:  SETP_EQ_NPI      P0, R0, R0, 0   # 0x2f0e
        LD_LOCAL         R5, 148   # 0x2f12
        BRA_PRED         0, L2ec6   # 0x2f16
L2f1a:  LD_LOCAL         R4, 144   # 0x2f1a
        SETP_LT_NPI      P0, R0, R4, 1   # 0x2f1e
        BRA_PRED         0, L2f60   # 0x2f22
        MOVI             R2, 0   # 0x2f26
        C_MOV            R0, R7   # 0x2f2a
        C_MOV            R1, R6   # 0x2f2c
L2f2e:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x2f2e
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x2f32
        AND              R0, R3, R12, R3   # 0x2f36
        OR               R0, R1, R0, R1   # 0x2f3a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2f3e
        BRA_PRED         4, L2f6a   # 0x2f42
        SHRI             R0, R1, 16   # 0x2f46
        SHLI             R3, R3, 16   # 0x2f4a
        OR               R0, R3, R0, R3   # 0x2f4e
        C_AND            R1, R12   # 0x2f52
        C_ADDI           R2, 1   # 0x2f54
        SETP_EQ_NP       P0, R3, R4, R2   # 0x2f56
        BRA_PRED         4, L2f2e   # 0x2f5a
        C_BRA            L2f76   # 0x2f5e
L2f60:  MOVI             R4, 0   # 0x2f60
        C_MOV            R0, R7   # 0x2f64
        C_MOV            R1, R6   # 0x2f66
        C_BRA            L2f76   # 0x2f68
L2f6a:  MOVI             R0, 0   # 0x2f6a
        ADDI             R4, R2, 1   # 0x2f6e
        MOVI             R1, 0   # 0x2f72
L2f76:  ST_LOCAL         R5, 152   # 0x2f76
        ADDI             R2, R5, 1   # 0x2f7a
        ST_LOCAL         R2, 148   # 0x2f7e
        C_MOV            R9, R7   # 0x2f82
        C_MOV            R8, R6   # 0x2f84
        C_MOV            R7, R0   # 0x2f86
        C_MOV            R6, R1   # 0x2f88
        LD_LOCAL         R0, 144   # 0x2f8a
        ST_LOCAL         R0, 100   # 0x2f8e
        C_BRA            L2fac   # 0x2f92
L2f94:  ST_LOCAL         R4, 140   # 0x2f94
        ST_LOCAL         R5, 136   # 0x2f98
L2f9c:  C_MOV            R9, R1   # 0x2f9c
        C_MOV            R8, R3   # 0x2f9e
        C_MOV            R7, R0   # 0x2fa0
        C_MOV            R6, R2   # 0x2fa2
        C_MOV            R10, R4   # 0x2fa4
        C_MOV            R11, R5   # 0x2fa6
        LD_LOCAL         R4, 96   # 0x2fa8
L2fac:  MOVI             R0, 0   # 0x2fac
        SETP_LT_NP       P0, R0, R0, R4   # 0x2fb0
        BRA_PRED         0, L2ff0   # 0x2fb4
        SHLI             R0, R7, 16   # 0x2fb8
        AND              R1, R0, R6, R0   # 0x2fbc
        ADD              R2, R0, R6, R0   # 0x2fc0
        C_OR             R0, R6   # 0x2fc4
        C_ANDN           R0, R2   # 0x2fc6
        OR               R0, R1, R0, R1   # 0x2fc8
        SHRI             R0, R0, 31   # 0x2fcc
        SHRI             R1, R7, 16   # 0x2fd0
        ADD              R0, R1, R0, R1   # 0x2fd4
        OR               R0, R2, R0, R2   # 0x2fd8
        LD_LOCAL         R1, 100   # 0x2fdc
        SETP_LT_NPI      P0, R1, R1, 1   # 0x2fe0
        BRA_PRED         0, L2f0e   # 0x2fe4
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x2fe8
        BRA_PRED         0, L2f0e   # 0x2fec
L2ff0:  SETP_NE_NPI      P0, R0, R4, 0   # 0x2ff0
        BRA_PRED         4, L3140   # 0x2ff4
        LD_LOCAL         R0, 100   # 0x2ff8
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2ffc
        BRA_PRED         0, L3408   # 0x3000
        SHLI             R0, R7, 16   # 0x3004
        AND              R1, R0, R6, R0   # 0x3008
        ADD              R2, R0, R6, R0   # 0x300c
        C_OR             R0, R6   # 0x3010
        C_ANDN           R0, R2   # 0x3012
        OR               R0, R1, R0, R1   # 0x3014
        SHRI             R0, R0, 31   # 0x3018
        SHRI             R1, R7, 16   # 0x301c
        ADD              R0, R1, R0, R1   # 0x3020
        OR               R0, R2, R0, R2   # 0x3024
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3028
        BRA_PRED         4, L3408   # 0x302c
        C_CHWIDTH        R14, 0   # 0x3030
        LD_GLOBAL_IDX    R5, R7, R6, 0, 8   # 0x3032
        LD_GLOBAL_IDX    R14, R7, R6, 0, 12   # 0x3036
        LD_GLOBAL_IDX    R0, R9, R8, 0, 8   # 0x303a
        LD_GLOBAL_IDX    R1, R9, R8, 0, 12   # 0x303e
        SHLI             R1, R1, 16   # 0x3042
        SHRI             R2, R0, 16   # 0x3046
        C_OR             R1, R2   # 0x304a
        AND              R2, R0, R12, R0   # 0x304c
        C_CHWIDTH        R12, 1   # 0x3050
        LD_GLOBAL_IDX    R12, R1, R2, 0, 0   # 0x3052
        MOVI             R0, 128   # 0x3056
        C_CHWIDTH        R0, 1   # 0x305a
        AND              R0, R12, R0, R12   # 0x305c
        C_CHWIDTH        R0, 0   # 0x3060
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3062
        ST_LOCAL         R4, 96   # 0x3066
        ST_LOCAL         R6, 104   # 0x306a
        BRA_PRED         4, L3162   # 0x306e
        ST_LOCAL         R2, 128   # 0x3072
        ST_LOCAL         R1, 124   # 0x3076
        ST_LOCAL         R14, 120   # 0x307a
        ST_LOCAL         R5, 116   # 0x307e
        MOVI             R0, 7   # 0x3082
        C_CHWIDTH        R0, 1   # 0x3086
        AND              R0, R12, R0, R12   # 0x3088
        CHWIDTH_MULTI    4097, 0   # 0x308c
        SHRI             R1, R12, 3   # 0x3090
        C_CHWIDTH        R1, 1   # 0x3094
        MOVI             R2, 15   # 0x3096
        AND              R1, R1, R2, R1   # 0x309a
        C_CHWIDTH        R1, 0   # 0x309e
        MULI             R1, R1, 17   # 0x30a0
        C_MOV            R3, R1   # 0x30a4
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x30a6
        BRA_PRED         0, L3172   # 0x30aa
        SETP_NE_NPI      P0, R0, R0, 0   # 0x30ae
        C_MOV            R5, R12   # 0x30b2
        BRA_PRED         0, L31be   # 0x30b4
        CHWIDTH_MULTI    48, 1   # 0x30b8
        ST_LOCAL         R7, 112   # 0x30bc
        MOVI             R0, 34   # 0x30c0
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x30c4
        C_CHWIDTH        R0, 1   # 0x30c8
        MOVI             R6, 34   # 0x30ca
        MOV_P            R6, 0, R3, R3, R3   # 0x30ce
        C_MOV            R2, R13   # 0x30d2
        LD_LOCAL         R13, 108   # 0x30d4
        LD_GLOBAL_IDX    R0, R2, R13, 0, 96   # 0x30d8
        C_CHWIDTH        R0, 0   # 0x30dc
        LD_GLOBAL_IDX    R1, R2, R13, 0, 40   # 0x30de
        LD_GLOBAL_IDX    R5, R2, R13, 0, 2   # 0x30e2
        C_CHWIDTH        R5, 0   # 0x30e6
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x30e8
        C_CHWIDTH        R4, 0   # 0x30ec
        LD_GLOBAL_IDX    R3, R2, R13, 0, 32   # 0x30ee
        LD_GLOBAL_IDX    R2, R2, R13, 0, 36   # 0x30f2
        ST_GLOBAL        R0, R15, -4   # 0x30f6
        SHLI             R0, R2, 16   # 0x30fa
        SHRI             R2, R3, 16   # 0x30fe
        OR               R2, R0, R2, R0   # 0x3102
        MOVI             R0, 65535   # 0x3106
        C_AND            R3, R0   # 0x310a
        CALL             R14, 127099   # 0x310c
        C_CHWIDTH        R0, 1   # 0x3110
        MOVI             R15, 2   # 0x3112
        LD_GLOBAL        R15, R15, 24   # 0x3116
        SRD              R3, 2   # 0x311a
        C_ADD            R15, R3   # 0x311c
        C_MOV            R2, R13   # 0x311e
        LD_LOCAL         R13, 132   # 0x3120
        LD_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x3124
        C_CHWIDTH        R0, 0   # 0x3128
        C_MOV            R5, R1   # 0x312a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x312c
        BRA_PRED         0, L31ba   # 0x3130
        C_MOV            R0, R5   # 0x3134
        C_CHWIDTH        R0, 1   # 0x3136
        ST_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x3138
        C_CHWIDTH        R0, 0   # 0x313c
        C_BRA            L31ba   # 0x313e
L3140:  LD_GLOBAL_IDX    R1, R7, R6, 0, 0   # 0x3140
        LD_GLOBAL_IDX    R0, R7, R6, 0, 4   # 0x3144
        SHLI             R0, R0, 16   # 0x3148
        SHRI             R2, R1, 16   # 0x314c
        C_OR             R0, R2   # 0x3150
        AND              R2, R1, R12, R1   # 0x3152
        MOVI             R1, 0   # 0x3156
        ST_LOCAL         R1, 96   # 0x315a
        BRA              L33f2   # 0x315e
L3162:  C_CHWIDTH        R3, 1   # 0x3162
        MOVI             R0, 127   # 0x3164
        AND              R3, R12, R0, R12   # 0x3168
        MOVI             R2, 128   # 0x316c
        C_BRA            L3222   # 0x3170
L3172:  C_CHWIDTH        R4, 1   # 0x3172
        ST_LOCAL         R7, 112   # 0x3174
        C_MOV            R1, R13   # 0x3178
        LD_LOCAL         R13, 108   # 0x317a
        LD_GLOBAL_IDX    R4, R1, R13, 0, 96   # 0x317e
        C_CHWIDTH        R4, 0   # 0x3182
        ADDI             R2, R13, 64   # 0x3184
        CALL             R14, 128392   # 0x3188
        C_CHWIDTH        R0, 1   # 0x318c
        MOVI             R15, 2   # 0x318e
        LD_GLOBAL        R15, R15, 24   # 0x3192
        SRD              R3, 2   # 0x3196
        C_ADD            R15, R3   # 0x3198
        C_MOV            R2, R13   # 0x319a
        LD_LOCAL         R13, 132   # 0x319c
        LD_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x31a0
        C_CHWIDTH        R0, 0   # 0x31a4
        C_MOV            R5, R1   # 0x31a6
        SETP_NE_NPI      P0, R0, R0, 0   # 0x31a8
        BRA_PRED         0, L31ba   # 0x31ac
        C_MOV            R0, R5   # 0x31b0
        C_CHWIDTH        R0, 1   # 0x31b2
        ST_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x31b4
        C_CHWIDTH        R0, 0   # 0x31b8
L31ba:  LD_LOCAL         R7, 112   # 0x31ba
L31be:  C_CHWIDTH        R2, 1   # 0x31be
        LD_LOCAL         R6, 108   # 0x31c0
        LD_GLOBAL_IDX    R2, R13, R6, 0, 96   # 0x31c4
        C_CHWIDTH        R2, 0   # 0x31c8
        C_MOV            R1, R5   # 0x31ca
        CALL             R14, 129894   # 0x31cc
        CHWIDTH_MULTI    16386, 1   # 0x31d0
        MOVI             R15, 2   # 0x31d4
        LD_GLOBAL        R15, R15, 24   # 0x31d8
        SRD              R3, 2   # 0x31dc
        C_ADD            R15, R3   # 0x31de
        C_CHWIDTH        R3, 1   # 0x31e0
        ST_GLOBAL_IDX    R1, R13, R6, 0, 96   # 0x31e2
        C_CHWIDTH        R1, 0   # 0x31e6
        MOVI             R0, 127   # 0x31e8
        AND              R3, R5, R0, R5   # 0x31ec
        MOVI             R0, 65280   # 0x31f0
        AND              R14, R12, R0, R12   # 0x31f4
        OR               R14, R14, R3, R14   # 0x31f8
        MOVI             R2, 128   # 0x31fc
        OR               R14, R14, R2, R14   # 0x3200
        LD_LOCAL         R0, 124   # 0x3204
        LD_LOCAL         R1, 128   # 0x3208
        ST_GLOBAL_IDX    R14, R0, R1, 0, 0   # 0x320c
        C_CHWIDTH        R14, 0   # 0x3210
        LD_LOCAL         R6, 104   # 0x3212
        LD_LOCAL         R4, 96   # 0x3216
        LD_LOCAL         R5, 116   # 0x321a
        LD_LOCAL         R14, 120   # 0x321e
L3222:  C_CHWIDTH        R12, 1   # 0x3222
        SHLI             R0, R14, 16   # 0x3224
        SHRI             R1, R5, 16   # 0x3228
        OR               R1, R0, R1, R0   # 0x322c
        MOVI             R0, 65535   # 0x3230
        C_AND            R5, R0   # 0x3234
        C_CHWIDTH        R0, 1   # 0x3236
        LD_GLOBAL_IDX    R12, R1, R5, 0, 0   # 0x3238
        AND              R0, R12, R2, R12   # 0x323c
        C_CHWIDTH        R0, 0   # 0x3240
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3242
        BRA_PRED         4, L3316   # 0x3246
        C_CHWIDTH        R3, 0   # 0x324a
        ST_LOCAL         R5, 124   # 0x324c
        ST_LOCAL         R1, 120   # 0x3250
        ST_LOCAL         R3, 116   # 0x3254
        MOVI             R0, 7   # 0x3258
        C_CHWIDTH        R0, 1   # 0x325c
        AND              R0, R12, R0, R12   # 0x325e
        CHWIDTH_MULTI    4097, 0   # 0x3262
        SHRI             R1, R12, 3   # 0x3266
        C_CHWIDTH        R1, 1   # 0x326a
        MOVI             R2, 15   # 0x326c
        AND              R1, R1, R2, R1   # 0x3270
        C_CHWIDTH        R1, 0   # 0x3274
        MULI             R1, R1, 17   # 0x3276
        C_MOV            R3, R1   # 0x327a
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x327c
        BRA_PRED         0, L3322   # 0x3280
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3284
        C_MOV            R5, R12   # 0x3288
        BRA_PRED         0, L336e   # 0x328a
        CHWIDTH_MULTI    48, 1   # 0x328e
        ST_LOCAL         R7, 112   # 0x3292
        MOVI             R0, 34   # 0x3296
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x329a
        C_CHWIDTH        R0, 1   # 0x329e
        MOVI             R6, 34   # 0x32a0
        MOV_P            R6, 0, R3, R3, R3   # 0x32a4
        C_MOV            R2, R13   # 0x32a8
        LD_LOCAL         R13, 108   # 0x32aa
        LD_GLOBAL_IDX    R0, R2, R13, 0, 96   # 0x32ae
        C_CHWIDTH        R0, 0   # 0x32b2
        LD_GLOBAL_IDX    R1, R2, R13, 0, 40   # 0x32b4
        LD_GLOBAL_IDX    R5, R2, R13, 0, 2   # 0x32b8
        C_CHWIDTH        R5, 0   # 0x32bc
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x32be
        C_CHWIDTH        R4, 0   # 0x32c2
        LD_GLOBAL_IDX    R3, R2, R13, 0, 32   # 0x32c4
        LD_GLOBAL_IDX    R2, R2, R13, 0, 36   # 0x32c8
        ST_GLOBAL        R0, R15, -4   # 0x32cc
        SHLI             R0, R2, 16   # 0x32d0
        SHRI             R2, R3, 16   # 0x32d4
        OR               R2, R0, R2, R0   # 0x32d8
        MOVI             R0, 65535   # 0x32dc
        C_AND            R3, R0   # 0x32e0
        CALL             R14, 126864   # 0x32e2
        C_CHWIDTH        R0, 1   # 0x32e6
        MOVI             R15, 2   # 0x32e8
        LD_GLOBAL        R15, R15, 24   # 0x32ec
        SRD              R3, 2   # 0x32f0
        C_ADD            R15, R3   # 0x32f2
        C_MOV            R2, R13   # 0x32f4
        LD_LOCAL         R13, 132   # 0x32f6
        LD_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x32fa
        C_CHWIDTH        R0, 0   # 0x32fe
        C_MOV            R5, R1   # 0x3300
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3302
        BRA_PRED         0, L336a   # 0x3306
        C_MOV            R0, R5   # 0x330a
        C_CHWIDTH        R0, 1   # 0x330c
        ST_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x330e
        C_CHWIDTH        R0, 0   # 0x3312
        C_BRA            L336a   # 0x3314
L3316:  MOVI             R0, 127   # 0x3316
        C_CHWIDTH        R0, 1   # 0x331a
        AND              R0, R12, R0, R12   # 0x331c
        C_BRA            L33cc   # 0x3320
L3322:  C_CHWIDTH        R4, 1   # 0x3322
        ST_LOCAL         R7, 112   # 0x3324
        C_MOV            R1, R13   # 0x3328
        LD_LOCAL         R13, 108   # 0x332a
        LD_GLOBAL_IDX    R4, R1, R13, 0, 96   # 0x332e
        C_CHWIDTH        R4, 0   # 0x3332
        ADDI             R2, R13, 64   # 0x3334
        CALL             R14, 128176   # 0x3338
        C_CHWIDTH        R0, 1   # 0x333c
        MOVI             R15, 2   # 0x333e
        LD_GLOBAL        R15, R15, 24   # 0x3342
        SRD              R3, 2   # 0x3346
        C_ADD            R15, R3   # 0x3348
        C_MOV            R2, R13   # 0x334a
        LD_LOCAL         R13, 132   # 0x334c
        LD_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x3350
        C_CHWIDTH        R0, 0   # 0x3354
        C_MOV            R5, R1   # 0x3356
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3358
        BRA_PRED         0, L336a   # 0x335c
        C_MOV            R0, R5   # 0x3360
        C_CHWIDTH        R0, 1   # 0x3362
        ST_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x3364
        C_CHWIDTH        R0, 0   # 0x3368
L336a:  LD_LOCAL         R7, 112   # 0x336a
L336e:  C_CHWIDTH        R2, 1   # 0x336e
        LD_LOCAL         R6, 108   # 0x3370
        LD_GLOBAL_IDX    R2, R13, R6, 0, 96   # 0x3374
        C_CHWIDTH        R2, 0   # 0x3378
        C_MOV            R1, R5   # 0x337a
        CALL             R14, 129678   # 0x337c
        CHWIDTH_MULTI    16386, 1   # 0x3380
        MOVI             R15, 2   # 0x3384
        LD_GLOBAL        R15, R15, 24   # 0x3388
        SRD              R3, 2   # 0x338c
        C_ADD            R15, R3   # 0x338e
        ST_GLOBAL_IDX    R1, R13, R6, 0, 96   # 0x3390
        C_CHWIDTH        R1, 0   # 0x3394
        MOVI             R0, 127   # 0x3396
        C_CHWIDTH        R0, 1   # 0x339a
        AND              R0, R5, R0, R5   # 0x339c
        MOVI             R1, 65280   # 0x33a0
        AND              R14, R12, R1, R12   # 0x33a4
        OR               R14, R14, R0, R14   # 0x33a8
        MOVI             R1, 128   # 0x33ac
        OR               R14, R14, R1, R14   # 0x33b0
        LD_LOCAL         R1, 120   # 0x33b4
        LD_LOCAL         R2, 124   # 0x33b8
        ST_GLOBAL_IDX    R14, R1, R2, 0, 0   # 0x33bc
        LD_LOCAL         R6, 104   # 0x33c0
        LD_LOCAL         R4, 96   # 0x33c4
        LD_LOCAL         R3, 116   # 0x33c8
L33cc:  CHWIDTH_MULTI    4105, 0   # 0x33cc
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x33d0
        MOVI             R12, 65535   # 0x33d4
        BRA_PRED         4, L3408   # 0x33d8
        LD_GLOBAL_IDX    R1, R7, R6, 0, 0   # 0x33dc
        LD_GLOBAL_IDX    R0, R7, R6, 0, 4   # 0x33e0
        SHLI             R0, R0, 16   # 0x33e4
        SHRI             R2, R1, 16   # 0x33e8
        C_OR             R0, R2   # 0x33ec
        AND              R2, R1, R12, R1   # 0x33ee
L33f2:  LD_LOCAL         R1, 100   # 0x33f2
        ADDI             R1, R1, -1   # 0x33f6
        ST_LOCAL         R1, 100   # 0x33fa
        C_MOV            R1, R9   # 0x33fe
        C_MOV            R3, R8   # 0x3400
        C_MOV            R4, R7   # 0x3402
        C_MOV            R5, R6   # 0x3404
        C_BRA            L342e   # 0x3406
L3408:  LD_GLOBAL_IDX    R0, R9, R8, 0, 0   # 0x3408
        LD_GLOBAL_IDX    R1, R9, R8, 0, 4   # 0x340c
        SHLI             R1, R1, 16   # 0x3410
        SHRI             R2, R0, 16   # 0x3414
        C_OR             R1, R2   # 0x3418
        AND              R3, R0, R12, R0   # 0x341a
        ADDI             R4, R4, -1   # 0x341e
        ST_LOCAL         R4, 96   # 0x3422
        C_MOV            R0, R7   # 0x3426
        C_MOV            R2, R6   # 0x3428
        C_MOV            R4, R9   # 0x342a
        C_MOV            R5, R8   # 0x342c
L342e:  C_CHWIDTH        R14, 0   # 0x342e
        SHLI             R6, R10, 16   # 0x3430
        AND              R7, R6, R11, R6   # 0x3434
        ADD              R14, R6, R11, R6   # 0x3438
        C_OR             R6, R11   # 0x343c
        C_ANDN           R6, R14   # 0x343e
        OR               R6, R7, R6, R7   # 0x3440
        SHRI             R6, R6, 31   # 0x3444
        SHRI             R7, R10, 16   # 0x3448
        ADD              R6, R7, R6, R7   # 0x344c
        OR               R6, R14, R6, R14   # 0x3450
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x3454
        BRA_PRED         0, L2f94   # 0x3458
        SHLI             R6, R4, 16   # 0x345c
        ADD              R7, R6, R5, R6   # 0x3460
        ST_GLOBAL_IDX    R7, R10, R11, 0, 0   # 0x3464
        OR               R14, R6, R5, R6   # 0x3468
        ANDN             R7, R14, R7, R14   # 0x346c
        C_AND            R6, R5   # 0x3470
        C_OR             R6, R7   # 0x3472
        SHRI             R6, R6, 31   # 0x3474
        SHRI             R7, R4, 16   # 0x3478
        ADD              R6, R7, R6, R7   # 0x347c
        ST_GLOBAL_IDX    R6, R10, R11, 0, 4   # 0x3480
        BRA              L2f9c   # 0x3484
L3488:  CHWIDTH_MULTI    64, 0   # 0x3488
        C_MOV            R9, R1   # 0x348c
L348e:  CHWIDTH_MULTI    16512, 0   # 0x348e
        LD_GLOBAL_IDX    R1, R8, R9, 0, 0   # 0x3492
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x3496
        SHLI             R0, R0, 16   # 0x349a
        SHRI             R2, R1, 16   # 0x349e
        OR               R3, R0, R2, R0   # 0x34a2
        MOVI             R0, 65535   # 0x34a6
        AND              R4, R1, R0, R1   # 0x34aa
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x34ae
        SHLI             R1, R1, 16   # 0x34b2
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x34b6
        SHRI             R5, R2, 16   # 0x34ba
        OR               R6, R1, R5, R1   # 0x34be
        C_CHWIDTH        R5, 1   # 0x34c2
        AND              R7, R2, R0, R2   # 0x34c4
        LD_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x34c8
        C_CHWIDTH        R5, 0   # 0x34cc
        LD_GLOBAL_IDX    R2, R6, R7, 0, 8   # 0x34ce
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x34d2
        ST_GLOBAL_IDX    R2, R3, R4, 0, 8   # 0x34d6
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x34da
        ST_GLOBAL_IDX    R5, R3, R4, 0, 12   # 0x34de
        AND              R5, R2, R0, R2   # 0x34e2
        ST_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x34e6
        C_CHWIDTH        R5, 1   # 0x34ea
        ST_GLOBAL_IDX    R1, R6, R7, 0, 8   # 0x34ec
        LD_GLOBAL_IDX    R5, R6, R7, 0, 4   # 0x34f0
        C_CHWIDTH        R5, 0   # 0x34f4
        LD_GLOBAL_IDX    R14, R6, R7, 0, 0   # 0x34f6
        ST_GLOBAL_IDX    R14, R3, R4, 0, 0   # 0x34fa
        ST_GLOBAL_IDX    R5, R3, R4, 0, 4   # 0x34fe
        LD_LOCAL         R10, 164   # 0x3502
        C_MOV            R4, R10   # 0x3506
        C_CHWIDTH        R4, 1   # 0x3508
        C_MOV            R5, R10   # 0x350a
        C_CHWIDTH        R5, 1   # 0x350c
        C_MOV            R11, R10   # 0x350e
        C_CHWIDTH        R11, 1   # 0x3510
        CVT_SEXT         R3, R4, R5, R11   # 0x3512
        CHWIDTH_MULTI    2096, 0   # 0x3516
        MOVI48           R4, 4294967295   # 0x351a
        SETP_LT_NP       P0, R3, R4, R3   # 0x3520
        MOVI             R3, 0   # 0x3524
        ST_GLOBAL_IDX    R3, R6, R7, 0, 4   # 0x3528
        ST_GLOBAL_IDX    R3, R6, R7, 0, 0   # 0x352c
        C_MOV            R13, R8   # 0x3530
        ST_LOCAL         R9, 136   # 0x3532
        BRA_PRED         4, L3586   # 0x3536
L353a:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x353a
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x353e
        SHLI             R4, R4, 16   # 0x3542
        SHRI             R5, R3, 16   # 0x3546
        C_OR             R4, R5   # 0x354a
        C_AND            R3, R0   # 0x354c
        C_CHWIDTH        R3, 1   # 0x354e
        LD_GLOBAL_IDX    R3, R4, R3, 0, 2   # 0x3550
        C_CHWIDTH        R3, 0   # 0x3554
        SETP_EQ_NP       P0, R3, R3, R10   # 0x3556
        BRA_PRED         0, L35de   # 0x355a
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x355e
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x3562
        SHRI             R5, R4, 16   # 0x3566
        SHLI             R14, R3, 16   # 0x356a
        OR               R8, R14, R5, R14   # 0x356e
        C_AND            R3, R0   # 0x3572
        OR               R3, R4, R3, R4   # 0x3574
        AND              R9, R4, R0, R4   # 0x3578
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x357c
        BRA_PRED         4, L353a   # 0x3580
        C_BRA            L35d6   # 0x3584
L3586:  LD_LOCAL         R10, 168   # 0x3586
L358a:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x358a
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x358e
        SHLI             R4, R4, 16   # 0x3592
        SHRI             R5, R3, 16   # 0x3596
        C_OR             R4, R5   # 0x359a
        C_AND            R3, R0   # 0x359c
        C_CHWIDTH        R3, 2   # 0x359e
        LD_GLOBAL_IDX    R3, R4, R3, 0, 0   # 0x35a0
        C_CHWIDTH        R3, 0   # 0x35a4
        C_AND            R3, R0   # 0x35a6
        SETP_EQ_NP       P0, R3, R3, R10   # 0x35a8
        BRA_PRED         0, L35de   # 0x35ac
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x35b0
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x35b4
        SHRI             R5, R4, 16   # 0x35b8
        SHLI             R14, R3, 16   # 0x35bc
        OR               R8, R14, R5, R14   # 0x35c0
        C_AND            R3, R0   # 0x35c4
        OR               R3, R4, R3, R4   # 0x35c6
        AND              R9, R4, R0, R4   # 0x35ca
        SETP_NE_NPI      P0, R3, R3, 0   # 0x35ce
        BRA_PRED         0, L358a   # 0x35d2
L35d6:  MOVI             R8, 0   # 0x35d6
        MOVI             R9, 0   # 0x35da
L35de:  SHLI             R2, R2, 16   # 0x35de
        SHRI             R3, R1, 16   # 0x35e2
        SHLI             R4, R8, 16   # 0x35e6
        AND              R5, R4, R9, R4   # 0x35ea
        ADD              R14, R4, R9, R4   # 0x35ee
        C_OR             R4, R9   # 0x35f2
        C_ANDN           R4, R14   # 0x35f4
        OR               R4, R5, R4, R5   # 0x35f6
        SHRI             R4, R4, 31   # 0x35fa
        SHRI             R5, R8, 16   # 0x35fe
        ADD              R4, R5, R4, R5   # 0x3602
        OR               R4, R14, R4, R14   # 0x3606
        SETP_NE_NPI      P0, R4, R4, 0   # 0x360a
        BRA_PRED         0, L3634   # 0x360e
        C_MOV            R5, R13   # 0x3612
        LD_LOCAL         R14, 136   # 0x3614
        LD_GLOBAL_IDX    R4, R5, R14, 0, 0   # 0x3618
        LD_GLOBAL_IDX    R5, R5, R14, 0, 4   # 0x361c
        SHLI             R5, R5, 16   # 0x3620
        SHRI             R14, R4, 16   # 0x3624
        OR               R8, R5, R14, R5   # 0x3628
        MOVI             R5, 65535   # 0x362c
        AND              R9, R4, R5, R4   # 0x3630
L3634:  OR               R10, R2, R3, R2   # 0x3634
        AND              R11, R1, R0, R1   # 0x3638
        SHLI             R0, R8, 16   # 0x363c
        AND              R1, R0, R9, R0   # 0x3640
        ADD              R2, R0, R9, R0   # 0x3644
        C_OR             R0, R9   # 0x3648
        C_ANDN           R0, R2   # 0x364a
        OR               R0, R1, R0, R1   # 0x364c
        SHRI             R0, R0, 31   # 0x3650
        SHRI             R1, R8, 16   # 0x3654
        ADD              R0, R1, R0, R1   # 0x3658
        OR               R0, R2, R0, R2   # 0x365c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3660
        BRA_PRED         0, L36ce   # 0x3664
        C_CHWIDTH        R5, 1   # 0x3668
        C_MOV            R1, R13   # 0x366a
        LD_LOCAL         R2, 136   # 0x366c
        LD_GLOBAL_IDX    R0, R1, R2, 0, 8   # 0x3670
        LD_GLOBAL_IDX    R1, R1, R2, 0, 12   # 0x3674
        SHLI             R1, R1, 16   # 0x3678
        SHRI             R2, R0, 16   # 0x367c
        C_OR             R1, R2   # 0x3680
        MOVI             R12, 65535   # 0x3682
        C_AND            R0, R12   # 0x3686
        LD_GLOBAL_IDX    R5, R1, R0, 0, 0   # 0x3688
        LD_LOCAL         R2, 156   # 0x368c
L3690:  C_CHWIDTH        R5, 0   # 0x3690
        C_MOV            R1, R5   # 0x3692
        CALL             R14, 127453   # 0x3694
        MOVI             R15, 2   # 0x3698
        LD_GLOBAL        R15, R15, 24   # 0x369c
        SRD              R3, 2   # 0x36a0
        C_ADD            R15, R3   # 0x36a2
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x36a4
        LD_GLOBAL_IDX    R2, R8, R9, 0, 0   # 0x36a8
        SHRI             R3, R2, 16   # 0x36ac
        SHLI             R4, R0, 16   # 0x36b0
        OR               R8, R4, R3, R4   # 0x36b4
        C_AND            R0, R12   # 0x36b8
        OR               R0, R2, R0, R2   # 0x36ba
        AND              R9, R2, R12, R2   # 0x36be
        C_MOV            R2, R1   # 0x36c2
        SETP_NE_NPI      P0, R0, R0, 0   # 0x36c4
        BRA_PRED         0, L3690   # 0x36c8
        C_BRA            L36d2   # 0x36cc
L36ce:  LD_LOCAL         R2, 156   # 0x36ce
L36d2:  C_CHWIDTH        R3, 1   # 0x36d2
        ST_LOCAL         R2, 156   # 0x36d4
        LD_LOCAL         R5, 136   # 0x36d8
        LD_GLOBAL_IDX    R1, R13, R5, 0, 0   # 0x36dc
        LD_GLOBAL_IDX    R0, R13, R5, 0, 4   # 0x36e0
        SHLI             R0, R0, 16   # 0x36e4
        SHRI             R2, R1, 16   # 0x36e8
        OR               R2, R0, R2, R0   # 0x36ec
        MOVI             R0, 65535   # 0x36f0
        C_AND            R1, R0   # 0x36f4
        LD_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x36f6
        C_CHWIDTH        R3, 0   # 0x36fa
        LD_GLOBAL_IDX    R4, R2, R1, 0, 8   # 0x36fc
        ST_GLOBAL_IDX    R4, R6, R7, 0, 8   # 0x3700
        ST_GLOBAL_IDX    R3, R6, R7, 0, 12   # 0x3704
        SHRI             R3, R10, 16   # 0x3708
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x370c
        SHLI             R3, R10, 16   # 0x3710
        C_OR             R3, R11   # 0x3714
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x3716
        C_CHWIDTH        R3, 1   # 0x371a
        LD_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x371c
        C_CHWIDTH        R3, 0   # 0x3720
        LD_GLOBAL_IDX    R4, R2, R1, 0, 0   # 0x3722
        ST_GLOBAL_IDX    R4, R6, R7, 0, 0   # 0x3726
        ST_GLOBAL_IDX    R3, R6, R7, 0, 4   # 0x372a
        SHLI             R3, R6, 16   # 0x372e
        C_OR             R3, R7   # 0x3732
        SHRI             R4, R6, 16   # 0x3734
        ST_GLOBAL_IDX    R4, R2, R1, 0, 4   # 0x3738
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x373c
        C_MOV            R1, R13   # 0x3740
        C_MOV            R13, R5   # 0x3742
        MOVI             R9, 1   # 0x3744
        MOVI             R3, 0   # 0x3748
        C_BRA            L3770   # 0x374c
L374e:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x374e
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x3752
        C_SHLI           R9, 1   # 0x3756
        LD_LOCAL         R1, 104   # 0x3758
        SETP_NE_NPI      P0, R1, R1, 0   # 0x375c
        LD_LOCAL         R4, 96   # 0x3760
        C_MOV            R1, R4   # 0x3764
        LD_LOCAL         R5, 100   # 0x3766
        C_MOV            R13, R5   # 0x376a
        BRA_PRED         4, L39bc   # 0x376c
L3770:  MOVI             R6, 0   # 0x3770
        MOVI             R2, 0   # 0x3774
        MOVI             R4, 0   # 0x3778
        MOVI             R5, 0   # 0x377c
        ST_LOCAL         R5, 96   # 0x3780
        ST_LOCAL         R5, 100   # 0x3784
        ST_LOCAL         R9, 112   # 0x3788
        C_BRA            L379e   # 0x378c
L378e:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x378e
        LD_LOCAL         R9, 112   # 0x3792
        LD_LOCAL         R6, 108   # 0x3796
        BRA_PRED         0, L374e   # 0x379a
L379e:  ST_LOCAL         R6, 104   # 0x379e
        SETP_LT_NPI      P0, R5, R9, 1   # 0x37a2
        BRA_PRED         0, L37e6   # 0x37a6
        MOVI             R5, 0   # 0x37aa
        C_MOV            R6, R1   # 0x37ae
        C_MOV            R7, R13   # 0x37b0
L37b2:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x37b2
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x37b6
        AND              R6, R14, R0, R14   # 0x37ba
        OR               R6, R7, R6, R7   # 0x37be
        SETP_NE_NPI      P0, R6, R6, 0   # 0x37c2
        BRA_PRED         4, L37f0   # 0x37c6
        SHRI             R6, R7, 16   # 0x37ca
        SHLI             R14, R14, 16   # 0x37ce
        OR               R6, R14, R6, R14   # 0x37d2
        C_AND            R7, R0   # 0x37d6
        C_ADDI           R5, 1   # 0x37d8
        SETP_EQ_NP       P0, R14, R9, R5   # 0x37da
        BRA_PRED         4, L37b2   # 0x37de
        C_MOV            R8, R9   # 0x37e2
        C_BRA            L37fc   # 0x37e4
L37e6:  MOVI             R8, 0   # 0x37e6
        C_MOV            R6, R1   # 0x37ea
        C_MOV            R7, R13   # 0x37ec
        C_BRA            L37fc   # 0x37ee
L37f0:  MOVI             R6, 0   # 0x37f0
        ADDI             R8, R5, 1   # 0x37f4
        MOVI             R7, 0   # 0x37f8
L37fc:  LD_LOCAL         R5, 104   # 0x37fc
        C_ADDI           R5, 1   # 0x3800
        ST_LOCAL         R5, 108   # 0x3802
        C_MOV            R5, R1   # 0x3806
        C_MOV            R14, R13   # 0x3808
        C_MOV            R1, R6   # 0x380a
        C_MOV            R13, R7   # 0x380c
        C_BRA            L3822   # 0x380e
L3810:  ST_LOCAL         R6, 96   # 0x3810
        ST_LOCAL         R7, 100   # 0x3814
L3818:  C_MOV            R5, R11   # 0x3818
        C_MOV            R14, R10   # 0x381a
        C_MOV            R1, R12   # 0x381c
        C_MOV            R2, R6   # 0x381e
        C_MOV            R4, R7   # 0x3820
L3822:  SETP_LT_NP       P0, R6, R3, R8   # 0x3822
        BRA_PRED         0, L385e   # 0x3826
        SHLI             R6, R1, 16   # 0x382a
        AND              R7, R6, R13, R6   # 0x382e
        ADD              R10, R6, R13, R6   # 0x3832
        C_OR             R6, R13   # 0x3836
        C_ANDN           R6, R10   # 0x3838
        OR               R6, R7, R6, R7   # 0x383a
        SHRI             R6, R6, 31   # 0x383e
        SHRI             R7, R1, 16   # 0x3842
        ADD              R6, R7, R6, R7   # 0x3846
        OR               R6, R10, R6, R10   # 0x384a
        SETP_LT_NPI      P0, R7, R9, 1   # 0x384e
        BRA_PRED         0, L378e   # 0x3852
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x3856
        BRA_PRED         0, L378e   # 0x385a
L385e:  SETP_NE_NPI      P0, R6, R8, 0   # 0x385e
        BRA_PRED         4, L393e   # 0x3862
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x3866
        BRA_PRED         0, L3916   # 0x386a
        SHLI             R6, R1, 16   # 0x386e
        AND              R7, R6, R13, R6   # 0x3872
        ADD              R10, R6, R13, R6   # 0x3876
        C_OR             R6, R13   # 0x387a
        C_ANDN           R6, R10   # 0x387c
        OR               R6, R7, R6, R7   # 0x387e
        SHRI             R6, R6, 31   # 0x3882
        SHRI             R7, R1, 16   # 0x3886
        ADD              R6, R7, R6, R7   # 0x388a
        OR               R6, R10, R6, R10   # 0x388e
        SETP_NE_NPI      P0, R6, R6, 0   # 0x3892
        BRA_PRED         4, L3916   # 0x3896
        C_CHWIDTH        R12, 2   # 0x389a
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x389c
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x38a0
        SHLI             R7, R7, 16   # 0x38a4
        SHRI             R10, R6, 16   # 0x38a8
        C_OR             R7, R10   # 0x38ac
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x38ae
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x38b2
        C_AND            R6, R0   # 0x38b6
        LD_GLOBAL_IDX    R12, R7, R6, 0, 1   # 0x38b8
        ST_GLOBAL_IDX    R12, R7, R6, 0, 0   # 0x38bc
        C_CHWIDTH        R7, 1   # 0x38c0
        C_CHWIDTH        R12, 0   # 0x38c2
        SHLI             R11, R11, 16   # 0x38c4
        SHRI             R12, R10, 16   # 0x38c8
        C_OR             R11, R12   # 0x38cc
        C_CHWIDTH        R12, 2   # 0x38ce
        C_AND            R10, R0   # 0x38d0
        LD_GLOBAL_IDX    R12, R11, R10, 0, 1   # 0x38d2
        ST_GLOBAL_IDX    R12, R11, R10, 0, 0   # 0x38d6
        LD_GLOBAL_IDX    R7, R7, R6, 0, 2   # 0x38da
        C_CHWIDTH        R6, 1   # 0x38de
        LD_GLOBAL_IDX    R6, R11, R10, 0, 2   # 0x38e0
        CVT_SEXT         R10, R6, R6, R6   # 0x38e4
        C_CHWIDTH        R6, 0   # 0x38e8
        CVT_SEXT         R6, R7, R7, R7   # 0x38ea
        SETP_LT_NP       P0, R6, R10, R6   # 0x38ee
        BRA_PRED         4, L3916   # 0x38f2
        CHWIDTH_MULTI    4224, 0   # 0x38f6
        LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x38fa
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x38fe
        SHLI             R7, R7, 16   # 0x3902
        SHRI             R10, R6, 16   # 0x3906
        OR               R12, R7, R10, R7   # 0x390a
        C_MOV            R7, R13   # 0x390e
        AND              R13, R6, R0, R6   # 0x3910
        C_BRA            L395c   # 0x3914
L3916:  CHWIDTH_MULTI    4224, 0   # 0x3916
        LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x391a
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x391e
        SHLI             R7, R7, 16   # 0x3922
        SHRI             R10, R6, 16   # 0x3926
        OR               R11, R7, R10, R7   # 0x392a
        AND              R10, R6, R0, R6   # 0x392e
        ADDI             R8, R8, -1   # 0x3932
        C_MOV            R12, R1   # 0x3936
        C_MOV            R6, R5   # 0x3938
        C_MOV            R7, R14   # 0x393a
        C_BRA            L3966   # 0x393c
L393e:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x393e
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x3942
        SHLI             R7, R7, 16   # 0x3946
        SHRI             R8, R6, 16   # 0x394a
        OR               R12, R7, R8, R7   # 0x394e
        C_MOV            R7, R13   # 0x3952
        AND              R13, R6, R0, R6   # 0x3954
        MOVI             R8, 0   # 0x3958
L395c:  ADDI             R9, R9, -1   # 0x395c
        C_MOV            R11, R5   # 0x3960
        C_MOV            R10, R14   # 0x3962
        C_MOV            R6, R1   # 0x3964
L3966:  SHLI             R5, R2, 16   # 0x3966
        AND              R14, R5, R4, R5   # 0x396a
        ADD              R1, R5, R4, R5   # 0x396e
        C_OR             R5, R4   # 0x3972
        C_ANDN           R5, R1   # 0x3974
        OR               R5, R14, R5, R14   # 0x3976
        SHRI             R5, R5, 31   # 0x397a
        SHRI             R14, R2, 16   # 0x397e
        ADD              R5, R14, R5, R14   # 0x3982
        C_OR             R1, R5   # 0x3986
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x3988
        BRA_PRED         0, L3810   # 0x398c
        SHLI             R1, R6, 16   # 0x3990
        ADD              R5, R1, R7, R1   # 0x3994
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x3998
        OR               R14, R1, R7, R1   # 0x399c
        ANDN             R5, R14, R5, R14   # 0x39a0
        C_AND            R1, R7   # 0x39a4
        C_OR             R1, R5   # 0x39a6
        SHRI             R1, R1, 31   # 0x39a8
        SHRI             R5, R6, 16   # 0x39ac
        ADD              R1, R5, R1, R5   # 0x39b0
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x39b4
        BRA              L3818   # 0x39b8
L39bc:  LD_GLOBAL_IDX    R1, R4, R5, 0, 4   # 0x39bc
        LD_GLOBAL_IDX    R0, R4, R5, 0, 0   # 0x39c0
        MOVI             R6, 65535   # 0x39c4
        AND              R2, R1, R6, R1   # 0x39c8
        OR               R2, R0, R2, R0   # 0x39cc
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x39d0
        BRA_PRED         0, L3a44   # 0x39d4
        SHRI             R2, R0, 16   # 0x39d8
        SHLI             R1, R1, 16   # 0x39dc
        OR               R7, R1, R2, R1   # 0x39e0
        AND              R8, R0, R6, R0   # 0x39e4
        LD_GLOBAL_IDX    R0, R4, R5, 0, 8   # 0x39e8
        LD_GLOBAL_IDX    R1, R4, R5, 0, 12   # 0x39ec
        C_CHWIDTH        R5, 1   # 0x39f0
        SHLI             R1, R1, 16   # 0x39f2
        SHRI             R2, R0, 16   # 0x39f6
        C_OR             R1, R2   # 0x39fa
        C_AND            R0, R6   # 0x39fc
        LD_GLOBAL_IDX    R5, R1, R0, 0, 0   # 0x39fe
        LD_LOCAL         R2, 156   # 0x3a02
L3a06:  C_CHWIDTH        R5, 0   # 0x3a06
        C_MOV            R1, R5   # 0x3a08
        CALL             R14, 127010   # 0x3a0a
        MOVI             R15, 2   # 0x3a0e
        LD_GLOBAL        R15, R15, 24   # 0x3a12
        SRD              R3, 2   # 0x3a16
        C_ADD            R15, R3   # 0x3a18
        LD_GLOBAL_IDX    R0, R7, R8, 0, 4   # 0x3a1a
        LD_GLOBAL_IDX    R2, R7, R8, 0, 0   # 0x3a1e
        SHRI             R3, R2, 16   # 0x3a22
        SHLI             R4, R0, 16   # 0x3a26
        OR               R7, R4, R3, R4   # 0x3a2a
        C_AND            R0, R6   # 0x3a2e
        OR               R0, R2, R0, R2   # 0x3a30
        AND              R8, R2, R6, R2   # 0x3a34
        C_MOV            R2, R1   # 0x3a38
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3a3a
        BRA_PRED         0, L3a06   # 0x3a3e
        C_BRA            L3a48   # 0x3a42
L3a44:  LD_LOCAL         R2, 156   # 0x3a44
L3a48:  C_MOV            R1, R2   # 0x3a48
        LD_LOCAL         R14, 160   # 0x3a4a
        LD_LOCAL         R13, 192   # 0x3a4e
        LD_LOCAL         R12, 188   # 0x3a52
        LD_LOCAL         R11, 184   # 0x3a56
        LD_LOCAL         R10, 180   # 0x3a5a
        LD_LOCAL         R9, 176   # 0x3a5e
        LD_LOCAL         R8, 172   # 0x3a62
        C_RET            224   # 0x3a66
        MOVI             R15, 2   # 0x3a68
        LD_GLOBAL        R15, R15, 24   # 0x3a6c
        SRD              R14, 2   # 0x3a70
        C_ADD            R15, R14   # 0x3a72
        MOVI             R8, 2   # 0x3a74
        LD_GLOBAL        R0, R8, 36   # 0x3a78
        MOVI             R1, 2000   # 0x3a7c
        SRD              R2, 0   # 0x3a80
        ST_LOCAL         R2, 196   # 0x3a82
        MADLO            R3, R2, R1, R0   # 0x3a86
        ADDI             R4, R3, 666   # 0x3a8a
        ST_LOCAL         R4, 200   # 0x3a8e
        LD_GLOBAL        R0, R8, 32   # 0x3a92
        SHLI             R1, R0, 16   # 0x3a96
        C_MOV            R9, R0   # 0x3a9a
        ADD              R2, R1, R4, R1   # 0x3a9c
        OR               R0, R1, R4, R1   # 0x3aa0
        C_ANDN           R0, R2   # 0x3aa4
        AND              R4, R1, R4, R1   # 0x3aa6
        OR               R0, R4, R0, R4   # 0x3aaa
        ADDI             R4, R3, 1332   # 0x3aae
        ADD              R5, R1, R4, R1   # 0x3ab2
        OR               R6, R1, R4, R1   # 0x3ab6
        C_ANDN           R6, R5   # 0x3aba
        AND              R4, R1, R4, R1   # 0x3abc
        C_OR             R4, R6   # 0x3ac0
        ADD              R6, R1, R3, R1   # 0x3ac2
        OR               R7, R1, R3, R1   # 0x3ac6
        C_ANDN           R7, R6   # 0x3aca
        C_AND            R1, R3   # 0x3acc
        C_OR             R1, R7   # 0x3ace
        LD_GLOBAL        R7, R8, 48   # 0x3ad0
        MOVI             R8, 7   # 0x3ad4
        ST_GLOBAL        R8, R15, -100   # 0x3ad8
        ST_GLOBAL        R7, R15, -104   # 0x3adc
        MOVI             R7, 102   # 0x3ae0
        C_MOV            R8, R7   # 0x3ae4
        C_CHWIDTH        R8, 1   # 0x3ae6
        ST_GLOBAL        R8, R15, -144   # 0x3ae8
        C_CHWIDTH        R8, 0   # 0x3aec
        ST_GLOBAL        R6, R15, -132   # 0x3aee
        ST_GLOBAL        R6, R15, -140   # 0x3af2
        ST_GLOBAL        R5, R15, -116   # 0x3af6
        ST_GLOBAL        R2, R15, -124   # 0x3afa
        SHRI             R1, R1, 31   # 0x3afe
        C_MOV            R2, R9   # 0x3b02
        ST_LOCAL         R2, 204   # 0x3b04
        SHRI             R5, R2, 16   # 0x3b08
        ADD              R1, R5, R1, R5   # 0x3b0c
        ST_GLOBAL        R1, R15, -128   # 0x3b10
        ST_GLOBAL        R1, R15, -136   # 0x3b14
        SHRI             R1, R4, 31   # 0x3b18
        ADD              R1, R5, R1, R5   # 0x3b1c
        ST_GLOBAL        R1, R15, -112   # 0x3b20
        SHRI             R0, R0, 31   # 0x3b24
        ADD              R0, R5, R0, R5   # 0x3b28
        ST_GLOBAL        R0, R15, -120   # 0x3b2c
        MOVI             R0, 0   # 0x3b30
        ST_GLOBAL        R0, R15, -148   # 0x3b34
        MOVI             R0, 666   # 0x3b38
        ST_GLOBAL        R0, R15, -108   # 0x3b3c
        MOVI             R1, 666   # 0x3b40
        MOVI             R4, 0   # 0x3b44
        CALL             R14, 123482   # 0x3b48
        MOVI             R15, 2   # 0x3b4c
        LD_GLOBAL        R15, R15, 24   # 0x3b50
        SRD              R3, 2   # 0x3b54
        C_ADD            R15, R3   # 0x3b56
        SHLI             R0, R1, 16   # 0x3b58
        ADD              R3, R0, R2, R0   # 0x3b5c
        OR               R4, R0, R2, R0   # 0x3b60
        C_ANDN           R4, R3   # 0x3b64
        ST_GLOBAL        R3, R15, -92   # 0x3b66
        C_AND            R0, R2   # 0x3b6a
        C_OR             R0, R4   # 0x3b6c
        SHRI             R0, R0, 31   # 0x3b6e
        SHRI             R1, R1, 16   # 0x3b72
        ADD              R0, R1, R0, R1   # 0x3b76
        ST_GLOBAL        R0, R15, -88   # 0x3b7a
        MOVI             R0, 65388   # 0x3b7e
        ADDI             R6, R0, 64   # 0x3b82
        ADDI             R5, R15, -1   # 0x3b86
        MOVI             R1, 666   # 0x3b8a
        LD_LOCAL         R2, 204   # 0x3b8e
        LD_LOCAL         R3, 200   # 0x3b92
        MOVI             R4, 0   # 0x3b96
        CALL             R14, 124587   # 0x3b9a
        C_CHWIDTH        R2, 1   # 0x3b9e
        MOVI             R15, 2   # 0x3ba0
        LD_GLOBAL        R15, R15, 24   # 0x3ba4
        SRD              R3, 2   # 0x3ba8
        C_ADD            R15, R3   # 0x3baa
        MOVI             R0, 65535   # 0x3bac
        LD_GLOBAL        R1, R15, -116   # 0x3bb0
        AND              R4, R1, R0, R1   # 0x3bb4
        SHRI             R0, R1, 16   # 0x3bb8
        LD_GLOBAL        R1, R15, -112   # 0x3bbc
        SHLI             R1, R1, 16   # 0x3bc0
        OR               R3, R1, R0, R1   # 0x3bc4
        LD_GLOBAL        R1, R15, -108   # 0x3bc8
        LD_GLOBAL        R2, R15, -148   # 0x3bcc
        C_CHWIDTH        R2, 0   # 0x3bd0
        CALL             R14, 124935   # 0x3bd2
        MOVI             R15, 2   # 0x3bd6
        LD_GLOBAL        R15, R15, 24   # 0x3bda
        SRD              R3, 2   # 0x3bde
        C_ADD            R15, R3   # 0x3be0
        MOVI             R1, 0   # 0x3be2
        ST_GLOBAL        R1, R15, -48   # 0x3be6
        ST_GLOBAL        R1, R15, -52   # 0x3bea
        LD_GLOBAL        R0, R15, -104   # 0x3bee
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3bf2
        BRA_PRED         0, L3d32   # 0x3bf6
        ADDI             R1, R15, -1   # 0x3bfa
        MOVI             R8, 1   # 0x3bfe
        MOVI             R2, 65388   # 0x3c02
        MOVI             R3, 1   # 0x3c06
        CALL             R14, 128876   # 0x3c0a
        C_CHWIDTH        R2, 1   # 0x3c0e
        MOVI             R15, 2   # 0x3c10
        LD_GLOBAL        R15, R15, 24   # 0x3c14
        SRD              R3, 2   # 0x3c18
        C_ADD            R15, R3   # 0x3c1a
        LD_GLOBAL        R2, R15, -52   # 0x3c1c
        C_CHWIDTH        R2, 0   # 0x3c20
        CALL             R14, 128571   # 0x3c22
        C_CHWIDTH        R1, 1   # 0x3c26
        MOVI             R15, 2   # 0x3c28
        LD_GLOBAL        R15, R15, 24   # 0x3c2c
        SRD              R3, 2   # 0x3c30
        C_ADD            R15, R3   # 0x3c32
        ST_GLOBAL        R1, R15, -52   # 0x3c34
        C_CHWIDTH        R1, 0   # 0x3c38
        ADDI             R1, R15, -1   # 0x3c3a
        MOVI             R2, 65388   # 0x3c3e
        MOVI             R3, 65535   # 0x3c42
        CALL             R14, 128846   # 0x3c46
        C_CHWIDTH        R2, 1   # 0x3c4a
        MOVI             R15, 2   # 0x3c4c
        LD_GLOBAL        R15, R15, 24   # 0x3c50
        SRD              R3, 2   # 0x3c54
        C_ADD            R15, R3   # 0x3c56
        LD_GLOBAL        R2, R15, -52   # 0x3c58
        C_CHWIDTH        R2, 0   # 0x3c5c
        CALL             R14, 128541   # 0x3c5e
        MOVI             R15, 2   # 0x3c62
        LD_GLOBAL        R15, R15, 24   # 0x3c66
        SRD              R3, 2   # 0x3c6a
        C_ADD            R15, R3   # 0x3c6c
        C_MOV            R14, R1   # 0x3c6e
        C_MOV            R0, R14   # 0x3c70
        C_CHWIDTH        R0, 1   # 0x3c72
        ST_GLOBAL        R0, R15, -50   # 0x3c74
        C_CHWIDTH        R0, 0   # 0x3c78
        C_MOV            R0, R14   # 0x3c7a
        C_CHWIDTH        R0, 1   # 0x3c7c
        ST_GLOBAL        R0, R15, -52   # 0x3c7e
        C_CHWIDTH        R0, 0   # 0x3c82
        LD_GLOBAL        R0, R15, -104   # 0x3c84
        SETP_LT_U_NPI    P0, R0, R0, 2   # 0x3c88
        C_MOV            R13, R14   # 0x3c8c
        BRA_PRED         0, L3d22   # 0x3c8e
L3c92:  ADDI             R1, R15, -1   # 0x3c92
        MOVI             R2, 65388   # 0x3c96
        MOVI             R3, 1   # 0x3c9a
        CALL             R14, 128802   # 0x3c9e
        C_CHWIDTH        R2, 1   # 0x3ca2
        MOVI             R15, 2   # 0x3ca4
        LD_GLOBAL        R15, R15, 24   # 0x3ca8
        SRD              R3, 2   # 0x3cac
        C_ADD            R15, R3   # 0x3cae
        LD_GLOBAL        R2, R15, -52   # 0x3cb0
        C_CHWIDTH        R2, 0   # 0x3cb4
        CALL             R14, 128497   # 0x3cb6
        C_CHWIDTH        R1, 1   # 0x3cba
        MOVI             R15, 2   # 0x3cbc
        LD_GLOBAL        R15, R15, 24   # 0x3cc0
        SRD              R3, 2   # 0x3cc4
        C_ADD            R15, R3   # 0x3cc6
        ST_GLOBAL        R1, R15, -52   # 0x3cc8
        C_CHWIDTH        R1, 0   # 0x3ccc
        ADDI             R1, R15, -1   # 0x3cce
        MOVI             R2, 65388   # 0x3cd2
        MOVI             R3, 65535   # 0x3cd6
        CALL             R14, 128772   # 0x3cda
        C_CHWIDTH        R2, 1   # 0x3cde
        MOVI             R15, 2   # 0x3ce0
        LD_GLOBAL        R15, R15, 24   # 0x3ce4
        SRD              R3, 2   # 0x3ce8
        C_ADD            R15, R3   # 0x3cea
        LD_GLOBAL        R2, R15, -52   # 0x3cec
        C_CHWIDTH        R2, 0   # 0x3cf0
        CALL             R14, 128467   # 0x3cf2
        MOVI             R15, 2   # 0x3cf6
        LD_GLOBAL        R15, R15, 24   # 0x3cfa
        SRD              R3, 2   # 0x3cfe
        C_ADD            R15, R3   # 0x3d00
        C_ADDI           R8, 1   # 0x3d02
        LD_GLOBAL        R0, R15, -104   # 0x3d04
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x3d08
        C_MOV            R13, R1   # 0x3d0c
        C_MOV            R0, R13   # 0x3d0e
        C_CHWIDTH        R0, 1   # 0x3d10
        ST_GLOBAL        R0, R15, -52   # 0x3d12
        C_CHWIDTH        R0, 0   # 0x3d16
        BRA_PRED         0, L3c92   # 0x3d18
        C_CHWIDTH        R14, 1   # 0x3d1c
        LD_GLOBAL        R14, R15, -50   # 0x3d1e
L3d22:  C_CHWIDTH        R14, 0   # 0x3d22
        CHWIDTH_MULTI    30720, 1   # 0x3d24
        LD_GLOBAL        R12, R15, -46   # 0x3d28
        LD_GLOBAL        R11, R15, -48   # 0x3d2c
        C_BRA            L3d42   # 0x3d30
L3d32:  C_MOV            R12, R1   # 0x3d32
        C_MOV            R11, R12   # 0x3d34
        C_CHWIDTH        R11, 1   # 0x3d36
        C_MOV            R14, R12   # 0x3d38
        C_CHWIDTH        R14, 1   # 0x3d3a
        C_MOV            R13, R12   # 0x3d3c
        CHWIDTH_MULTI    12288, 1   # 0x3d3e
L3d42:  LD_LOCAL         R1, 196   # 0x3d42
        C_SHLI           R1, 3   # 0x3d46
        MOVI             R0, 2   # 0x3d48
        LD_GLOBAL        R0, R0, 44   # 0x3d4c
        C_ADD            R0, R1   # 0x3d50
        ST_GLOBAL_SLOT   R13, 1, R0, 0, 0   # 0x3d52
        ADDI             R1, R0, 2   # 0x3d56
        ST_GLOBAL_SLOT   R14, 1, R1, 0, 0   # 0x3d5a
        ADDI             R1, R0, 4   # 0x3d5e
        ST_GLOBAL_SLOT   R11, 1, R1, 0, 0   # 0x3d62
        C_ADDI           R0, 6   # 0x3d66
        ST_GLOBAL_SLOT   R12, 1, R0, 0, 0   # 0x3d68
        C_EXIT           0   # 0x3d6c
