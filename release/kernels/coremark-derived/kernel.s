# coremark-derived: test/coremark-derived, compiled; ccv-as source, reassembled
# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base
# (0x1000: function pointers are absolute); the kernel's entry is 0x3a44.
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
        ST_LOCAL         R3, 28   # 0x0900
        C_MOV            R0, R1   # 0x0904
        MOVI             R7, 1   # 0x0906
        SETP_LT_U_NP     P0, R1, R7, R4   # 0x090a
        MOV_P            R7, 0, R4, R4, R4   # 0x090e
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0912
        BRA_PRED         0, L093a   # 0x0916
        MOVI48           R9, 4294967295   # 0x091a
        MOVI             R3, 8   # 0x0920
L0924:  ADDI             R4, R9, 2   # 0x0924
        MUL_LO           R4, R3, R4, R4   # 0x0928
        SETP_LT_U_NP     P0, R4, R4, R0   # 0x092c
        C_ADDI           R3, 8   # 0x0930
        C_ADDI           R9, 1   # 0x0932
        BRA_PRED         0, L0924   # 0x0934
        C_BRA            L0940   # 0x0938
L093a:  MOVI48           R9, 4294967295   # 0x093a
L0940:  SHLI             R1, R2, 16   # 0x0940
        LD_LOCAL         R0, 28   # 0x0944
        ADD              R0, R1, R0, R1   # 0x0948
        ST_LOCAL         R1, 60   # 0x094c
        SETP_LT_U_NP     P0, R3, R0, R1   # 0x0950
        SHRI             R3, R2, 16   # 0x0954
        ST_LOCAL         R3, 64   # 0x0958
        ADDI_P           R3, 0, R3, 1   # 0x095c
        C_NEG            R4, R0   # 0x0960
        ANDI             R1, R4, 3   # 0x0962
        ST_LOCAL         R1, 36   # 0x0966
        ADD              R4, R0, R1, R0   # 0x096a
        SETP_LT_U_NP     P0, R0, R4, R0   # 0x096e
        ADDI_P           R3, 0, R3, 1   # 0x0972
        MUL_LO           R1, R9, R9, R9   # 0x0976
        SHRI             R0, R1, 31   # 0x097a
        ADD              R0, R3, R0, R3   # 0x097e
        C_SHLI           R1, 1   # 0x0982
        ST_LOCAL         R1, 32   # 0x0984
        ADD              R3, R4, R1, R4   # 0x0988
        SETP_LT_U_NP     P0, R3, R3, R4   # 0x098c
        ADDI_P           R0, 0, R0, 1   # 0x0990
        SETP_EQ_NPI      P0, R0, R9, 0   # 0x0994
        BRA_PRED         0, L0b44   # 0x0998
        C_CHWIDTH        R0, 1   # 0x099c
        MOVI             R11, 0   # 0x099e
        LD_LOCAL         R1, 28   # 0x09a2
        SUB              R0, R11, R1, R11   # 0x09a6
        C_CHWIDTH        R0, 0   # 0x09aa
        C_ANDI           R0, 3   # 0x09ac
        ADD              R10, R1, R0, R1   # 0x09ae
        MOVI             R4, 1   # 0x09b2
        C_MOV            R12, R9   # 0x09b6
        C_SHLI           R12, 1   # 0x09b8
        ANDI             R13, R9, -2   # 0x09ba
        ANDI             R0, R9, 1   # 0x09be
        ST_LOCAL         R0, 16   # 0x09c2
        LD_LOCAL         R0, 32   # 0x09c6
        ADD              R5, R10, R0, R10   # 0x09ca
        MOVI             R6, 255   # 0x09ce
        MOVI             R14, 0   # 0x09d2
        ST_LOCAL         R9, 40   # 0x09d6
        ST_LOCAL         R12, 44   # 0x09da
        C_BRA            L09f0   # 0x09de
L09e0:  C_ADD            R5, R12   # 0x09e0
        C_ADD            R10, R12   # 0x09e2
        C_ADD            R11, R9   # 0x09e4
        C_ADDI           R14, 1   # 0x09e6
        SETP_NE_NP       P0, R1, R14, R9   # 0x09e8
        BRA_PRED         4, L0b44   # 0x09ec
L09f0:  SETP_EQ_NPI      P0, R3, R9, 1   # 0x09f0
        BRA_PRED         4, L09fe   # 0x09f4
        MOVI             R8, 0   # 0x09f8
        C_BRA            L0ad6   # 0x09fc
L09fe:  ST_LOCAL         R14, 24   # 0x09fe
        ST_LOCAL         R11, 20   # 0x0a02
        MOVI             R3, 0   # 0x0a06
        C_MOV            R11, R4   # 0x0a0a
        C_SHLI           R11, 1   # 0x0a0c
        MOVI             R8, 0   # 0x0a0e
        MOVI             R15, 255   # 0x0a12
        MOVI48           R6, 4294901760   # 0x0a16
        ST_LOCAL         R10, 12   # 0x0a1c
L0a20:  C_MOV            R10, R4   # 0x0a20
        ADD              R4, R10, R8, R10   # 0x0a22
        MUL_LO           R12, R7, R4, R4   # 0x0a26
        SRAI             R9, R12, 31   # 0x0a2a
        SHRI             R9, R9, 16   # 0x0a2e
        MADLO            R7, R7, R4, R9   # 0x0a32
        C_AND            R7, R6   # 0x0a36
        SUB              R7, R12, R7, R12   # 0x0a38
        ADD              R9, R5, R3, R5   # 0x0a3c
        ADD              R12, R4, R7, R4   # 0x0a40
        C_CHWIDTH        R12, 1   # 0x0a44
        ST_GLOBAL_IDX    R12, R2, R9, 0, 0   # 0x0a46
        C_CHWIDTH        R12, 0   # 0x0a4a
        ADDI             R12, R4, 1   # 0x0a4c
        C_MOV            R14, R5   # 0x0a50
        MUL_LO           R5, R7, R12, R12   # 0x0a52
        SRAI             R1, R5, 31   # 0x0a56
        SHRI             R1, R1, 16   # 0x0a5a
        MAD_ACC          R1, R7, R12   # 0x0a5e
        LD_LOCAL         R0, 12   # 0x0a60
        ADD              R12, R0, R3, R0   # 0x0a64
        C_MOV            R0, R13   # 0x0a68
        ADD              R13, R11, R3, R11   # 0x0a6a
        ADD              R7, R13, R7, R13   # 0x0a6e
        C_CHWIDTH        R7, 1   # 0x0a72
        AND              R7, R7, R15, R7   # 0x0a74
        ST_GLOBAL_IDX    R7, R2, R12, 0, 0   # 0x0a78
        C_CHWIDTH        R7, 0   # 0x0a7c
        C_AND            R1, R6   # 0x0a7e
        SUB              R7, R5, R1, R5   # 0x0a80
        C_CHWIDTH        R5, 1   # 0x0a84
        ADDI             R1, R9, 2   # 0x0a86
        C_ADD            R4, R7   # 0x0a8a
        ADDI             R5, R4, 1   # 0x0a8c
        C_MOV            R4, R10   # 0x0a90
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0a92
        ADD              R1, R13, R7, R13   # 0x0a96
        C_MOV            R13, R0   # 0x0a9a
        ADDI             R5, R1, 2   # 0x0a9c
        AND              R5, R5, R15, R5   # 0x0aa0
        ADDI             R1, R12, 2   # 0x0aa4
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0aa8
        C_CHWIDTH        R5, 0   # 0x0aac
        C_MOV            R5, R14   # 0x0aae
        C_ADDI           R3, 4   # 0x0ab0
        C_ADDI           R8, 2   # 0x0ab2
        SETP_NE_NP       P0, R1, R13, R8   # 0x0ab4
        BRA_PRED         0, L0a20   # 0x0ab8
        C_ADD            R4, R8   # 0x0abc
        LD_LOCAL         R9, 40   # 0x0abe
        LD_LOCAL         R11, 20   # 0x0ac2
        LD_LOCAL         R12, 44   # 0x0ac6
        MOVI             R6, 255   # 0x0aca
        LD_LOCAL         R10, 12   # 0x0ace
        LD_LOCAL         R14, 24   # 0x0ad2
L0ad6:  LD_LOCAL         R0, 16   # 0x0ad6
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0ada
        BRA_PRED         0, L09e0   # 0x0ade
        MUL_LO           R1, R14, R9, R9   # 0x0ae2
        MUL_LO           R3, R7, R4, R4   # 0x0ae6
        MOVI48           R0, 4294901760   # 0x0aea
        C_MOV            R15, R4   # 0x0af0
        SRAI             R4, R3, 31   # 0x0af2
        SHRI             R4, R4, 16   # 0x0af6
        MAD_ACC          R4, R7, R15   # 0x0afa
        C_AND            R4, R0   # 0x0afc
        SUB              R7, R3, R4, R3   # 0x0afe
        LD_LOCAL         R3, 28   # 0x0b02
        LD_LOCAL         R4, 36   # 0x0b06
        C_ADD            R3, R4   # 0x0b0a
        ADD              R1, R8, R1, R8   # 0x0b0c
        C_SHLI           R1, 1   # 0x0b10
        ADD              R1, R3, R1, R3   # 0x0b12
        LD_LOCAL         R3, 32   # 0x0b16
        ADD              R3, R1, R3, R1   # 0x0b1a
        ADD              R4, R7, R15, R7   # 0x0b1e
        C_MOV            R0, R5   # 0x0b22
        C_MOV            R5, R4   # 0x0b24
        C_CHWIDTH        R5, 1   # 0x0b26
        ST_GLOBAL_IDX    R5, R2, R3, 0, 0   # 0x0b28
        ADD              R3, R4, R15, R4   # 0x0b2c
        C_MOV            R4, R15   # 0x0b30
        AND              R5, R3, R6, R3   # 0x0b32
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0b36
        C_CHWIDTH        R5, 0   # 0x0b3a
        C_MOV            R5, R0   # 0x0b3c
        C_ADDI           R4, 1   # 0x0b3e
        BRA              L09e0   # 0x0b40
L0b44:  LD_LOCAL         R0, 28   # 0x0b44
        LD_LOCAL         R1, 36   # 0x0b48
        C_ADD            R0, R1   # 0x0b4c
        LD_LOCAL         R7, 60   # 0x0b4e
        ADD              R1, R7, R0, R7   # 0x0b52
        OR               R2, R7, R0, R7   # 0x0b56
        C_ANDN           R2, R1   # 0x0b5a
        AND              R3, R7, R0, R7   # 0x0b5c
        OR               R2, R3, R2, R3   # 0x0b60
        LD_LOCAL         R3, 32   # 0x0b64
        C_ADD            R0, R3   # 0x0b68
        ADD              R3, R0, R3, R0   # 0x0b6a
        ADD              R4, R7, R3, R7   # 0x0b6e
        C_NEG            R4, R4   # 0x0b72
        C_ANDI           R4, 3   # 0x0b74
        C_ADD            R3, R4   # 0x0b76
        ADD              R4, R7, R0, R7   # 0x0b78
        OR               R5, R7, R0, R7   # 0x0b7c
        C_ANDN           R5, R4   # 0x0b80
        AND              R0, R7, R0, R7   # 0x0b82
        C_OR             R0, R5   # 0x0b86
        LD_LOCAL         R5, 52   # 0x0b88
        LD_LOCAL         R6, 56   # 0x0b8c
        ST_GLOBAL_IDX    R1, R6, R5, 0, 8   # 0x0b90
        ST_GLOBAL_IDX    R4, R6, R5, 0, 16   # 0x0b94
        SHRI             R1, R2, 31   # 0x0b98
        LD_LOCAL         R2, 64   # 0x0b9c
        ADD              R1, R2, R1, R2   # 0x0ba0
        ST_GLOBAL_IDX    R1, R6, R5, 0, 12   # 0x0ba4
        SHRI             R0, R0, 31   # 0x0ba8
        ADD              R0, R2, R0, R2   # 0x0bac
        ST_GLOBAL_IDX    R0, R6, R5, 0, 20   # 0x0bb0
        ADD              R0, R7, R3, R7   # 0x0bb4
        ST_GLOBAL_IDX    R0, R6, R5, 0, 24   # 0x0bb8
        OR               R1, R7, R3, R7   # 0x0bbc
        ANDN             R0, R1, R0, R1   # 0x0bc0
        AND              R1, R7, R3, R7   # 0x0bc4
        OR               R0, R1, R0, R1   # 0x0bc8
        SHRI             R0, R0, 31   # 0x0bcc
        ADD              R0, R2, R0, R2   # 0x0bd0
        ST_GLOBAL_IDX    R0, R6, R5, 0, 28   # 0x0bd4
        ST_GLOBAL_IDX    R9, R6, R5, 0, 0   # 0x0bd8
        LD_LOCAL         R14, 48   # 0x0bdc
        C_MOV            R1, R9   # 0x0be0
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
        ST_LOCAL         R8, 76   # 0x1c9c
        ST_LOCAL         R9, 80   # 0x1ca0
        ST_LOCAL         R10, 84   # 0x1ca4
        ST_LOCAL         R11, 88   # 0x1ca8
        ST_LOCAL         R12, 92   # 0x1cac
        ST_LOCAL         R13, 96   # 0x1cb0
        C_MOV            R15, R14   # 0x1cb4
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x1cb6
        SHLI             R10, R0, 16   # 0x1cba
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x1cbe
        ST_LOCAL         R0, 40   # 0x1cc2
        SHRI             R0, R0, 16   # 0x1cc6
        ST_LOCAL         R0, 68   # 0x1cca
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x1cce
        SHLI             R0, R0, 16   # 0x1cd2
        LD_GLOBAL_IDX    R7, R1, R2, 0, 8   # 0x1cd6
        SHRI             R5, R7, 16   # 0x1cda
        C_OR             R0, R5   # 0x1cde
        LD_GLOBAL_IDX    R5, R1, R2, 0, 28   # 0x1ce0
        SHLI             R14, R5, 16   # 0x1ce4
        LD_GLOBAL_IDX    R5, R1, R2, 0, 24   # 0x1ce8
        SHRI             R6, R5, 16   # 0x1cec
        OR               R6, R14, R6, R14   # 0x1cf0
        ST_LOCAL         R6, 16   # 0x1cf4
        MOVI             R6, 65535   # 0x1cf8
        AND              R14, R7, R6, R7   # 0x1cfc
        AND              R11, R5, R6, R5   # 0x1d00
        C_CHWIDTH        R6, 1   # 0x1d04
        LD_GLOBAL_IDX    R8, R1, R2, 0, 0   # 0x1d06
        MOVI             R2, 0   # 0x1d0a
        MOVI             R1, 61440   # 0x1d0e
        C_MOV            R5, R3   # 0x1d12
        OR               R6, R3, R1, R3   # 0x1d14
        SETP_EQ_NPI      P0, R1, R8, 0   # 0x1d18
        ANDI             R12, R8, -2   # 0x1d1c
        ANDI             R1, R8, 1   # 0x1d20
        ST_LOCAL         R1, 28   # 0x1d24
        ADDI             R1, R8, -1   # 0x1d28
        ST_LOCAL         R1, 24   # 0x1d2c
        CVT_SEXT         R1, R6, R6, R6   # 0x1d30
        ST_LOCAL         R1, 32   # 0x1d34
        ANDI             R9, R8, -4   # 0x1d38
        ST_LOCAL         R9, 44   # 0x1d3c
        ST_LOCAL         R15, 52   # 0x1d40
        ST_LOCAL         R5, 56   # 0x1d44
        ST_LOCAL         R4, 60   # 0x1d48
        ST_LOCAL         R10, 36   # 0x1d4c
        BRA_PRED         0, L2048   # 0x1d50
        C_CHWIDTH        R6, 0   # 0x1d54
        ANDI             R1, R8, 3   # 0x1d56
        MOVI             R6, 0   # 0x1d5a
        C_MOV            R7, R5   # 0x1d5e
        LD_LOCAL         R3, 16   # 0x1d60
        C_BRA            L1d76   # 0x1d64
L1d66:  CHWIDTH_MULTI    32768, 0   # 0x1d66
        C_ADD            R2, R8   # 0x1d6a
        C_ADDI           R6, 1   # 0x1d6c
        SETP_NE_NP       P0, R3, R6, R8   # 0x1d6e
        BRA_PRED         4, L1e10   # 0x1d72
L1d76:  MOVI             R3, 0   # 0x1d76
        LD_LOCAL         R5, 24   # 0x1d7a
        SETP_LT_U_NPI    P0, R5, R5, 3   # 0x1d7e
        BRA_PRED         0, L1ddc   # 0x1d82
L1d86:  CHWIDTH_MULTI    40960, 1   # 0x1d86
        ADD              R5, R2, R3, R2   # 0x1d8a
        C_SHLI           R5, 1   # 0x1d8e
        ADD              R5, R14, R5, R14   # 0x1d90
        LD_GLOBAL_IDX    R15, R0, R5, 0, 0   # 0x1d94
        ADD              R15, R15, R7, R15   # 0x1d98
        ST_GLOBAL_IDX    R15, R0, R5, 0, 0   # 0x1d9c
        C_CHWIDTH        R15, 0   # 0x1da0
        ADDI             R15, R5, 2   # 0x1da2
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x1da6
        ADD              R13, R13, R7, R13   # 0x1daa
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x1dae
        ADDI             R15, R5, 4   # 0x1db2
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x1db6
        ADD              R13, R13, R7, R13   # 0x1dba
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x1dbe
        C_CHWIDTH        R15, 1   # 0x1dc2
        C_ADDI           R5, 6   # 0x1dc4
        LD_GLOBAL_IDX    R15, R0, R5, 0, 0   # 0x1dc6
        ADD              R15, R15, R7, R15   # 0x1dca
        ST_GLOBAL_IDX    R15, R0, R5, 0, 0   # 0x1dce
        C_ADDI           R3, 4   # 0x1dd2
        SETP_NE_NP       P0, R5, R9, R3   # 0x1dd4
        BRA_PRED         0, L1d86   # 0x1dd8
L1ddc:  SETP_EQ_NPI      P0, R5, R1, 0   # 0x1ddc
        BRA_PRED         0, L1d66   # 0x1de0
        C_ADD            R3, R2   # 0x1de4
        C_MOV            R5, R1   # 0x1de6
L1de8:  C_CHWIDTH        R13, 1   # 0x1de8
        C_CHWIDTH        R15, 0   # 0x1dea
        C_MOV            R15, R3   # 0x1dec
        C_SHLI           R15, 1   # 0x1dee
        ADD              R15, R14, R15, R14   # 0x1df0
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x1df4
        ADD              R13, R13, R7, R13   # 0x1df8
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x1dfc
        C_ADDI           R3, 1   # 0x1e00
        ADDI             R5, R5, -1   # 0x1e02
        SETP_NE_NPI      P0, R15, R5, 0   # 0x1e06
        BRA_PRED         0, L1de8   # 0x1e0a
        C_BRA            L1d66   # 0x1e0e
L1e10:  MOVI             R2, 0   # 0x1e10
        C_MOV            R3, R7   # 0x1e14
        C_CHWIDTH        R3, 1   # 0x1e16
        C_MOV            R4, R7   # 0x1e18
        C_CHWIDTH        R4, 1   # 0x1e1a
        C_MOV            R5, R7   # 0x1e1c
        C_CHWIDTH        R7, 0   # 0x1e1e
        C_CHWIDTH        R5, 1   # 0x1e20
        CVT_SEXT         R6, R3, R4, R5   # 0x1e22
        CHWIDTH_MULTI    56, 0   # 0x1e26
        MOVI             R15, 0   # 0x1e2a
        C_BRA            L1e40   # 0x1e2e
L1e30:  CHWIDTH_MULTI    8192, 0   # 0x1e30
        C_ADD            R2, R8   # 0x1e34
        C_ADDI           R15, 1   # 0x1e36
        SETP_NE_NP       P0, R3, R15, R8   # 0x1e38
        BRA_PRED         4, L1f2c   # 0x1e3c
L1e40:  LD_LOCAL         R3, 24   # 0x1e40
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1e44
        MOVI             R5, 0   # 0x1e48
        LD_LOCAL         R7, 44   # 0x1e4c
        BRA_PRED         0, L1eea   # 0x1e50
L1e54:  C_CHWIDTH        R13, 1   # 0x1e54
        ADD              R3, R2, R5, R2   # 0x1e56
        C_MOV            R9, R3   # 0x1e5a
        C_SHLI           R9, 2   # 0x1e5c
        ADD              R9, R11, R9, R11   # 0x1e5e
        C_MOV            R10, R3   # 0x1e62
        C_SHLI           R10, 1   # 0x1e64
        ADD              R10, R14, R10, R14   # 0x1e66
        LD_GLOBAL_IDX    R13, R0, R10, 0, 0   # 0x1e6a
        CVT_SEXT         R10, R13, R13, R13   # 0x1e6e
        C_MUL_LO         R10, R6   # 0x1e72
        LD_LOCAL         R4, 16   # 0x1e74
        ST_GLOBAL_IDX    R10, R4, R9, 0, 0   # 0x1e78
        ADDI             R9, R3, 1   # 0x1e7c
        C_MOV            R10, R9   # 0x1e80
        C_SHLI           R10, 2   # 0x1e82
        ADD              R10, R11, R10, R11   # 0x1e84
        C_SHLI           R9, 1   # 0x1e88
        ADD              R9, R14, R9, R14   # 0x1e8a
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1e8e
        CVT_SEXT         R9, R13, R13, R13   # 0x1e92
        C_MUL_LO         R9, R6   # 0x1e96
        ST_GLOBAL_IDX    R9, R4, R10, 0, 0   # 0x1e98
        ADDI             R9, R3, 2   # 0x1e9c
        C_MOV            R10, R9   # 0x1ea0
        C_SHLI           R10, 2   # 0x1ea2
        ADD              R10, R11, R10, R11   # 0x1ea4
        C_SHLI           R9, 1   # 0x1ea8
        ADD              R9, R14, R9, R14   # 0x1eaa
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1eae
        CVT_SEXT         R9, R13, R13, R13   # 0x1eb2
        C_MUL_LO         R9, R6   # 0x1eb6
        ST_GLOBAL_IDX    R9, R4, R10, 0, 0   # 0x1eb8
        C_ADDI           R3, 3   # 0x1ebc
        C_MOV            R9, R3   # 0x1ebe
        C_SHLI           R9, 2   # 0x1ec0
        ADD              R9, R11, R9, R11   # 0x1ec2
        C_SHLI           R3, 1   # 0x1ec6
        ADD              R3, R14, R3, R14   # 0x1ec8
        C_CHWIDTH        R3, 1   # 0x1ecc
        LD_GLOBAL_IDX    R3, R0, R3, 0, 0   # 0x1ece
        CVT_SEXT         R10, R3, R3, R3   # 0x1ed2
        C_CHWIDTH        R3, 0   # 0x1ed6
        MUL_LO           R3, R10, R6, R6   # 0x1ed8
        ST_GLOBAL_IDX    R3, R4, R9, 0, 0   # 0x1edc
        C_ADDI           R5, 4   # 0x1ee0
        SETP_NE_NP       P0, R3, R7, R5   # 0x1ee2
        BRA_PRED         0, L1e54   # 0x1ee6
L1eea:  SETP_EQ_NPI      P0, R3, R1, 0   # 0x1eea
        BRA_PRED         0, L1e30   # 0x1eee
        ADD              R3, R5, R2, R5   # 0x1ef2
        C_MOV            R5, R1   # 0x1ef6
L1ef8:  C_CHWIDTH        R13, 1   # 0x1ef8
        C_MOV            R9, R3   # 0x1efa
        C_SHLI           R9, 2   # 0x1efc
        ADD              R9, R11, R9, R11   # 0x1efe
        C_MOV            R10, R3   # 0x1f02
        C_SHLI           R10, 1   # 0x1f04
        ADD              R10, R14, R10, R14   # 0x1f06
        LD_GLOBAL_IDX    R13, R0, R10, 0, 0   # 0x1f0a
        CVT_SEXT         R10, R13, R13, R13   # 0x1f0e
        C_MUL_LO         R10, R6   # 0x1f12
        LD_LOCAL         R4, 16   # 0x1f14
        ST_GLOBAL_IDX    R10, R4, R9, 0, 0   # 0x1f18
        C_ADDI           R3, 1   # 0x1f1c
        ADDI             R5, R5, -1   # 0x1f1e
        SETP_NE_NPI      P0, R9, R5, 0   # 0x1f22
        BRA_PRED         0, L1ef8   # 0x1f26
        C_BRA            L1e30   # 0x1f2a
L1f2c:  MOVI             R1, 0   # 0x1f2c
        C_MOV            R5, R1   # 0x1f30
        MOVI             R7, 0   # 0x1f32
        MOVI             R9, 0   # 0x1f36
        MOVI             R15, 0   # 0x1f3a
        MOVI             R13, 0   # 0x1f3e
        C_BRA            L1f50   # 0x1f42
L1f44:  C_ADD            R7, R8   # 0x1f44
        C_ADDI           R9, 1   # 0x1f46
        SETP_NE_NP       P0, R3, R9, R8   # 0x1f48
        BRA_PRED         4, L2050   # 0x1f4c
L1f50:  ST_LOCAL         R9, 12   # 0x1f50
        LD_LOCAL         R3, 24   # 0x1f54
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1f58
        BRA_PRED         0, L1fea   # 0x1f5c
        MOVI             R10, 0   # 0x1f60
        LD_LOCAL         R2, 32   # 0x1f64
L1f68:  C_CHWIDTH        R5, 0   # 0x1f68
        ADD              R3, R7, R10, R7   # 0x1f6a
        C_SHLI           R3, 2   # 0x1f6e
        C_ADD            R3, R11   # 0x1f70
        C_MOV            R6, R5   # 0x1f72
        LD_LOCAL         R4, 16   # 0x1f74
        LD_GLOBAL_IDX    R5, R4, R3, 0, 0   # 0x1f78
        SETP_LT_NP       P0, R1, R1, R5   # 0x1f7c
        C_MOV            R9, R11   # 0x1f80
        C_MOV            R11, R7   # 0x1f82
        MOVI             R7, 0   # 0x1f84
        ADDI_P           R7, 0, R7, 1   # 0x1f88
        ADD              R15, R5, R15, R5   # 0x1f8c
        LD_LOCAL         R2, 32   # 0x1f90
        SETP_LT_NP       P0, R1, R2, R15   # 0x1f94
        MOVI             R1, 10   # 0x1f98
        MOV_P            R7, 0, R1, R1, R1   # 0x1f9c
        C_CHWIDTH        R7, 1   # 0x1fa0
        MOV_P            R15, 0, R13, R13, R13   # 0x1fa2
        ADDI             R1, R3, 4   # 0x1fa6
        LD_GLOBAL_IDX    R1, R4, R1, 0, 0   # 0x1faa
        SETP_LT_NP       P0, R3, R5, R1   # 0x1fae
        MOVI             R3, 0   # 0x1fb2
        ADDI_P           R3, 0, R3, 1   # 0x1fb6
        ADD              R15, R1, R15, R1   # 0x1fba
        SETP_LT_NP       P0, R5, R2, R15   # 0x1fbe
        C_CHWIDTH        R5, 1   # 0x1fc2
        MOVI             R2, 10   # 0x1fc4
        MOV_P            R3, 0, R2, R2, R2   # 0x1fc8
        MOV_P            R15, 0, R13, R13, R13   # 0x1fcc
        ADD              R7, R7, R6, R7   # 0x1fd0
        ADD              R5, R3, R7, R3   # 0x1fd4
        C_CHWIDTH        R7, 0   # 0x1fd8
        C_MOV            R7, R11   # 0x1fda
        C_MOV            R11, R9   # 0x1fdc
        C_ADDI           R10, 2   # 0x1fde
        SETP_NE_NP       P0, R3, R12, R10   # 0x1fe0
        BRA_PRED         0, L1f68   # 0x1fe4
        C_BRA            L1fee   # 0x1fe8
L1fea:  MOVI             R10, 0   # 0x1fea
L1fee:  LD_LOCAL         R3, 28   # 0x1fee
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1ff2
        MOVI             R2, 0   # 0x1ff6
        MOVI             R6, 10   # 0x1ffa
        LD_LOCAL         R9, 12   # 0x1ffe
        BRA_PRED         0, L1f44   # 0x2002
        C_CHWIDTH        R5, 1   # 0x2006
        MUL_LO           R3, R9, R8, R8   # 0x2008
        ADD              R3, R10, R3, R10   # 0x200c
        C_SHLI           R3, 2   # 0x2010
        ADD              R3, R11, R3, R11   # 0x2012
        LD_LOCAL         R4, 16   # 0x2016
        LD_GLOBAL_IDX    R3, R4, R3, 0, 0   # 0x201a
        SETP_LT_NP       P0, R1, R1, R3   # 0x201e
        ADD              R15, R3, R15, R3   # 0x2022
        LD_LOCAL         R1, 32   # 0x2026
        SETP_LT_NP       P1, R1, R1, R15   # 0x202a
        MOV_P            R15, 1, R2, R2, R2   # 0x202e
        MOVI             R1, 0   # 0x2032
        ADDI_P           R1, 0, R1, 1   # 0x2036
        MOV_P            R1, 1, R6, R6, R6   # 0x203a
        ADD              R5, R1, R5, R1   # 0x203e
        C_MOV            R1, R3   # 0x2042
        BRA              L1f44   # 0x2044
L2048:  C_MOV            R1, R2   # 0x2048
        C_MOV            R5, R1   # 0x204a
        LD_LOCAL         R1, 16   # 0x204c
L2050:  C_CHWIDTH        R5, 0   # 0x2050
        ST_LOCAL         R5, 64   # 0x2052
        LD_LOCAL         R1, 36   # 0x2056
        LD_LOCAL         R2, 68   # 0x205a
        OR               R15, R1, R2, R1   # 0x205e
        LD_LOCAL         R1, 40   # 0x2062
        MOVI             R2, 65535   # 0x2066
        AND              R10, R1, R2, R1   # 0x206a
        MOVI             R1, 0   # 0x206e
        SETP_EQ_NPI      P0, R2, R8, 0   # 0x2072
        ST_LOCAL         R11, 20   # 0x2076
        BRA_PRED         0, L2288   # 0x207a
        MOVI             R9, 0   # 0x207e
        C_BRA            L20a4   # 0x2082
L2084:  CHWIDTH_MULTI    8224, 0   # 0x2084
        C_MOV            R2, R9   # 0x2088
        C_SHLI           R2, 2   # 0x208a
        ADD              R2, R11, R2, R11   # 0x208c
        LD_LOCAL         R3, 16   # 0x2090
        ST_GLOBAL_IDX    R6, R3, R2, 0, 0   # 0x2094
        C_ADD            R1, R8   # 0x2098
        C_ADDI           R9, 1   # 0x209a
        SETP_NE_NP       P0, R2, R9, R8   # 0x209c
        BRA_PRED         4, L2158   # 0x20a0
L20a4:  ST_LOCAL         R9, 12   # 0x20a4
        LD_LOCAL         R2, 24   # 0x20a8
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x20ac
        BRA_PRED         0, L2112   # 0x20b0
        C_CHWIDTH        R6, 0   # 0x20b4
        MOVI             R5, 0   # 0x20b6
        MOVI             R6, 0   # 0x20ba
L20be:  C_CHWIDTH        R13, 1   # 0x20be
        C_CHWIDTH        R7, 0   # 0x20c0
        ADD              R3, R1, R5, R1   # 0x20c2
        C_SHLI           R3, 1   # 0x20c6
        C_ADD            R3, R14   # 0x20c8
        C_MOV            R7, R5   # 0x20ca
        C_SHLI           R7, 1   # 0x20cc
        C_ADD            R7, R10   # 0x20ce
        LD_GLOBAL_IDX    R13, R15, R7, 0, 0   # 0x20d0
        CVT_SEXT         R9, R13, R13, R13   # 0x20d4
        LD_GLOBAL_IDX    R13, R0, R3, 0, 0   # 0x20d8
        CVT_SEXT         R2, R13, R13, R13   # 0x20dc
        MADLO            R2, R9, R2, R6   # 0x20e0
        C_CHWIDTH        R6, 1   # 0x20e4
        C_ADDI           R3, 2   # 0x20e6
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x20e8
        ADDI             R3, R7, 2   # 0x20ec
        C_CHWIDTH        R7, 1   # 0x20f0
        LD_GLOBAL_IDX    R7, R15, R3, 0, 0   # 0x20f2
        CVT_SEXT         R3, R7, R7, R7   # 0x20f6
        C_CHWIDTH        R7, 0   # 0x20fa
        CVT_SEXT         R7, R6, R6, R6   # 0x20fc
        C_CHWIDTH        R6, 0   # 0x2100
        MADLO            R6, R3, R7, R2   # 0x2102
        C_ADDI           R5, 2   # 0x2106
        SETP_NE_NP       P0, R2, R12, R5   # 0x2108
        BRA_PRED         0, L20be   # 0x210c
        C_BRA            L211c   # 0x2110
L2112:  C_CHWIDTH        R6, 0   # 0x2112
        MOVI             R5, 0   # 0x2114
        MOVI             R6, 0   # 0x2118
L211c:  LD_LOCAL         R2, 28   # 0x211c
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x2120
        LD_LOCAL         R9, 12   # 0x2124
        BRA_PRED         0, L2084   # 0x2128
        C_CHWIDTH        R7, 1   # 0x212c
        MUL_LO           R2, R9, R8, R8   # 0x212e
        ADD              R2, R5, R2, R5   # 0x2132
        C_SHLI           R2, 1   # 0x2136
        ADD              R2, R14, R2, R14   # 0x2138
        LD_GLOBAL_IDX    R7, R0, R2, 0, 0   # 0x213c
        C_SHLI           R5, 1   # 0x2140
        ADD              R2, R10, R5, R10   # 0x2142
        C_CHWIDTH        R5, 1   # 0x2146
        LD_GLOBAL_IDX    R5, R15, R2, 0, 0   # 0x2148
        CVT_SEXT         R2, R5, R5, R5   # 0x214c
        CVT_SEXT         R3, R7, R7, R7   # 0x2150
        MAD_ACC          R6, R2, R3   # 0x2154
        C_BRA            L2084   # 0x2156
L2158:  MOVI             R1, 0   # 0x2158
        C_MOV            R5, R1   # 0x215c
        MOVI             R3, 0   # 0x215e
        MOVI             R9, 0   # 0x2162
        MOVI             R13, 0   # 0x2166
        ST_LOCAL         R14, 48   # 0x216a
        C_BRA            L2184   # 0x216e
L2170:  LD_LOCAL         R3, 12   # 0x2170
        C_ADD            R3, R8   # 0x2174
        C_ADDI           R9, 1   # 0x2176
        SETP_NE_NP       P0, R2, R9, R8   # 0x2178
        LD_LOCAL         R14, 48   # 0x217c
        BRA_PRED         4, L228a   # 0x2180
L2184:  ST_LOCAL         R9, 36   # 0x2184
        ST_LOCAL         R3, 12   # 0x2188
        LD_LOCAL         R2, 24   # 0x218c
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x2190
        BRA_PRED         0, L2224   # 0x2194
        MOVI             R6, 0   # 0x2198
        LD_LOCAL         R2, 32   # 0x219c
        LD_LOCAL         R2, 12   # 0x21a0
L21a4:  CHWIDTH_MULTI    160, 0   # 0x21a4
        LD_LOCAL         R2, 12   # 0x21a8
        ADD              R3, R2, R6, R2   # 0x21ac
        C_SHLI           R3, 2   # 0x21b0
        LD_LOCAL         R2, 20   # 0x21b2
        C_ADD            R3, R2   # 0x21b6
        C_MOV            R9, R5   # 0x21b8
        LD_LOCAL         R4, 16   # 0x21ba
        LD_GLOBAL_IDX    R5, R4, R3, 0, 0   # 0x21be
        SETP_LT_NP       P0, R1, R1, R5   # 0x21c2
        MOVI             R2, 0   # 0x21c6
        ADDI_P           R2, 0, R2, 1   # 0x21ca
        ADD              R13, R5, R13, R5   # 0x21ce
        LD_LOCAL         R14, 32   # 0x21d2
        SETP_LT_NP       P0, R1, R14, R13   # 0x21d6
        MOVI             R7, 10   # 0x21da
        MOV_P            R2, 0, R7, R7, R7   # 0x21de
        MOVI             R11, 0   # 0x21e2
        MOV_P            R13, 0, R11, R11, R11   # 0x21e6
        ADDI             R1, R3, 4   # 0x21ea
        LD_GLOBAL_IDX    R1, R4, R1, 0, 0   # 0x21ee
        SETP_LT_NP       P0, R3, R5, R1   # 0x21f2
        MOVI             R3, 0   # 0x21f6
        ADDI_P           R3, 0, R3, 1   # 0x21fa
        ADD              R13, R1, R13, R1   # 0x21fe
        SETP_LT_NP       P0, R5, R14, R13   # 0x2202
        C_CHWIDTH        R5, 1   # 0x2206
        MOV_P            R3, 0, R7, R7, R7   # 0x2208
        MOV_P            R13, 0, R11, R11, R11   # 0x220c
        ADD              R5, R2, R9, R2   # 0x2210
        ADD              R5, R3, R5, R3   # 0x2214
        C_ADDI           R6, 2   # 0x2218
        SETP_NE_NP       P0, R2, R12, R6   # 0x221a
        BRA_PRED         0, L21a4   # 0x221e
        C_BRA            L2228   # 0x2222
L2224:  MOVI             R6, 0   # 0x2224
L2228:  C_CHWIDTH        R7, 0   # 0x2228
        LD_LOCAL         R2, 28   # 0x222a
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x222e
        MOVI             R3, 0   # 0x2232
        LD_LOCAL         R11, 20   # 0x2236
        MOVI             R7, 10   # 0x223a
        LD_LOCAL         R9, 36   # 0x223e
        BRA_PRED         0, L2170   # 0x2242
        C_CHWIDTH        R5, 1   # 0x2246
        MUL_LO           R2, R9, R8, R8   # 0x2248
        ADD              R2, R6, R2, R6   # 0x224c
        C_SHLI           R2, 2   # 0x2250
        ADD              R2, R11, R2, R11   # 0x2252
        LD_LOCAL         R4, 16   # 0x2256
        LD_GLOBAL_IDX    R2, R4, R2, 0, 0   # 0x225a
        SETP_LT_NP       P0, R1, R1, R2   # 0x225e
        ADD              R13, R2, R13, R2   # 0x2262
        LD_LOCAL         R1, 32   # 0x2266
        SETP_LT_NP       P1, R1, R1, R13   # 0x226a
        MOV_P            R13, 1, R3, R3, R3   # 0x226e
        MOVI             R1, 0   # 0x2272
        ADDI_P           R1, 0, R1, 1   # 0x2276
        MOV_P            R1, 1, R7, R7, R7   # 0x227a
        ADD              R5, R1, R5, R1   # 0x227e
        C_MOV            R1, R2   # 0x2282
        BRA              L2170   # 0x2284
L2288:  C_MOV            R5, R1   # 0x2288
L228a:  C_CHWIDTH        R5, 0   # 0x228a
        ST_LOCAL         R5, 68   # 0x228c
        MOVI             R1, 0   # 0x2290
        SETP_EQ_NPI      P0, R2, R8, 0   # 0x2294
        C_MOV            R2, R8   # 0x2298
        C_SHLI           R2, 1   # 0x229a
        ST_LOCAL         R8, 12   # 0x229c
        BRA_PRED         0, L24ec   # 0x22a0
        LD_LOCAL         R3, 44   # 0x22a4
        MOVI             R5, 0   # 0x22a8
        C_BRA            L22c2   # 0x22ac
L22ae:  CHWIDTH_MULTI    128, 0   # 0x22ae
        C_ADD            R1, R8   # 0x22b2
        LD_LOCAL         R5, 40   # 0x22b4
        C_ADDI           R5, 1   # 0x22b8
        SETP_NE_NP       P0, R3, R5, R8   # 0x22ba
        BRA_PRED         4, L23b2   # 0x22be
L22c2:  ST_LOCAL         R5, 40   # 0x22c2
        MUL_LO           R3, R5, R8, R8   # 0x22c6
        ST_LOCAL         R3, 36   # 0x22ca
        MOVI             R11, 0   # 0x22ce
        C_BRA            L22fa   # 0x22d2
L22d4:  C_CHWIDTH        R6, 0   # 0x22d4
        LD_LOCAL         R3, 36   # 0x22d6
        ADD              R3, R11, R3, R11   # 0x22da
        C_SHLI           R3, 2   # 0x22de
        LD_LOCAL         R6, 20   # 0x22e0
        ADD              R3, R6, R3, R6   # 0x22e4
        LD_LOCAL         R6, 16   # 0x22e8
        ST_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x22ec
        C_ADDI           R11, 1   # 0x22f0
        SETP_NE_NP       P0, R3, R11, R8   # 0x22f2
        BRA_PRED         4, L22ae   # 0x22f6
L22fa:  LD_LOCAL         R3, 24   # 0x22fa
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x22fe
        MOVI             R13, 0   # 0x2302
        MOVI             R5, 0   # 0x2306
        BRA_PRED         0, L2374   # 0x230a
        C_MOV            R9, R11   # 0x230e
L2310:  CHWIDTH_MULTI    192, 0   # 0x2310
        ADD              R6, R1, R13, R1   # 0x2314
        C_SHLI           R6, 1   # 0x2318
        C_ADD            R6, R14   # 0x231a
        C_MOV            R3, R9   # 0x231c
        C_SHLI           R3, 1   # 0x231e
        ADD              R3, R10, R3, R10   # 0x2320
        C_CHWIDTH        R3, 1   # 0x2324
        LD_GLOBAL_IDX    R3, R15, R3, 0, 0   # 0x2326
        CVT_SEXT         R8, R3, R3, R3   # 0x232a
        LD_GLOBAL_IDX    R3, R0, R6, 0, 0   # 0x232e
        CVT_SEXT         R7, R3, R3, R3   # 0x2332
        C_CHWIDTH        R3, 0   # 0x2336
        MADLO            R3, R8, R7, R5   # 0x2338
        C_CHWIDTH        R7, 1   # 0x233c
        LD_LOCAL         R8, 12   # 0x233e
        ADDI             R5, R6, 2   # 0x2342
        C_CHWIDTH        R6, 1   # 0x2346
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x2348
        ADD              R5, R8, R9, R8   # 0x234c
        C_SHLI           R5, 1   # 0x2350
        ADD              R5, R10, R5, R10   # 0x2352
        LD_GLOBAL_IDX    R6, R15, R5, 0, 0   # 0x2356
        CVT_SEXT         R5, R6, R6, R6   # 0x235a
        C_CHWIDTH        R6, 0   # 0x235e
        CVT_SEXT         R6, R7, R7, R7   # 0x2360
        MADLO            R5, R5, R6, R3   # 0x2364
        C_ADD            R9, R2   # 0x2368
        C_ADDI           R13, 2   # 0x236a
        SETP_NE_NP       P0, R3, R12, R13   # 0x236c
        BRA_PRED         0, L2310   # 0x2370
L2374:  LD_LOCAL         R3, 28   # 0x2374
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2378
        BRA_PRED         0, L22d4   # 0x237c
        CHWIDTH_MULTI    192, 1   # 0x2380
        MADLO            R3, R13, R8, R11   # 0x2384
        C_SHLI           R3, 1   # 0x2388
        ADD              R3, R10, R3, R10   # 0x238a
        LD_GLOBAL_IDX    R7, R15, R3, 0, 0   # 0x238e
        LD_LOCAL         R3, 36   # 0x2392
        ADD              R3, R13, R3, R13   # 0x2396
        C_SHLI           R3, 1   # 0x239a
        ADD              R3, R14, R3, R14   # 0x239c
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x23a0
        CVT_SEXT         R3, R7, R7, R7   # 0x23a4
        C_CHWIDTH        R7, 0   # 0x23a8
        CVT_SEXT         R7, R6, R6, R6   # 0x23aa
        MAD_ACC          R5, R3, R7   # 0x23ae
        C_BRA            L22d4   # 0x23b0
L23b2:  MOVI             R1, 0   # 0x23b2
        C_MOV            R7, R1   # 0x23b6
        MOVI             R5, 0   # 0x23b8
        ST_LOCAL         R1, 36   # 0x23bc
        MOVI             R9, 0   # 0x23c0
        LD_LOCAL         R3, 44   # 0x23c4
        C_BRA            L23de   # 0x23c8
L23ca:  C_ADD            R5, R8   # 0x23ca
        LD_LOCAL         R3, 36   # 0x23cc
        C_ADDI           R3, 1   # 0x23d0
        ST_LOCAL         R3, 36   # 0x23d2
        SETP_NE_NP       P0, R3, R3, R8   # 0x23d6
        BRA_PRED         4, L24f2   # 0x23da
L23de:  LD_LOCAL         R3, 24   # 0x23de
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x23e2
        BRA_PRED         0, L2480   # 0x23e6
        MOVI             R13, 0   # 0x23ea
        LD_LOCAL         R3, 16   # 0x23ee
        LD_LOCAL         R3, 20   # 0x23f2
        LD_LOCAL         R3, 32   # 0x23f6
L23fa:  C_CHWIDTH        R7, 0   # 0x23fa
        ADD              R3, R5, R13, R5   # 0x23fc
        C_SHLI           R3, 2   # 0x2400
        LD_LOCAL         R6, 20   # 0x2402
        C_ADD            R3, R6   # 0x2406
        C_MOV            R11, R7   # 0x2408
        C_MOV            R7, R5   # 0x240a
        LD_LOCAL         R4, 16   # 0x240c
        LD_GLOBAL_IDX    R5, R4, R3, 0, 0   # 0x2410
        SETP_LT_NP       P0, R1, R1, R5   # 0x2414
        MOVI             R8, 0   # 0x2418
        ADDI_P           R8, 0, R8, 1   # 0x241c
        ADD              R9, R5, R9, R5   # 0x2420
        LD_LOCAL         R6, 32   # 0x2424
        SETP_LT_NP       P0, R1, R6, R9   # 0x2428
        MOVI             R1, 10   # 0x242c
        MOV_P            R8, 0, R1, R1, R1   # 0x2430
        MOVI             R1, 0   # 0x2434
        MOV_P            R9, 0, R1, R1, R1   # 0x2438
        ADDI             R1, R3, 4   # 0x243c
        LD_GLOBAL_IDX    R1, R4, R1, 0, 0   # 0x2440
        SETP_LT_NP       P0, R3, R5, R1   # 0x2444
        MOVI             R3, 0   # 0x2448
        ADDI_P           R3, 0, R3, 1   # 0x244c
        ADD              R9, R1, R9, R1   # 0x2450
        SETP_LT_NP       P0, R5, R6, R9   # 0x2454
        MOVI             R5, 10   # 0x2458
        MOV_P            R3, 0, R5, R5, R5   # 0x245c
        C_MOV            R5, R7   # 0x2460
        C_CHWIDTH        R7, 1   # 0x2462
        MOVI             R4, 0   # 0x2464
        MOV_P            R9, 0, R4, R4, R4   # 0x2468
        ADD              R7, R8, R11, R8   # 0x246c
        ADD              R7, R3, R7, R3   # 0x2470
        C_ADDI           R13, 2   # 0x2474
        SETP_NE_NP       P0, R3, R12, R13   # 0x2476
        BRA_PRED         0, L23fa   # 0x247a
        C_BRA            L2488   # 0x247e
L2480:  MOVI             R13, 0   # 0x2480
        LD_LOCAL         R3, 20   # 0x2484
L2488:  LD_LOCAL         R3, 28   # 0x2488
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x248c
        LD_LOCAL         R8, 12   # 0x2490
        LD_LOCAL         R6, 20   # 0x2494
        MOVI             R11, 0   # 0x2498
        BRA_PRED         0, L23ca   # 0x249c
        C_CHWIDTH        R7, 1   # 0x24a0
        LD_LOCAL         R3, 36   # 0x24a2
        C_MUL_LO         R3, R8   # 0x24a6
        ADD              R3, R13, R3, R13   # 0x24a8
        C_SHLI           R3, 2   # 0x24ac
        ADD              R3, R6, R3, R6   # 0x24ae
        C_MOV            R6, R5   # 0x24b2
        LD_LOCAL         R5, 16   # 0x24b4
        LD_GLOBAL_IDX    R3, R5, R3, 0, 0   # 0x24b8
        MOVI             R5, 10   # 0x24bc
        SETP_LT_NP       P0, R1, R1, R3   # 0x24c0
        ADD              R9, R3, R9, R3   # 0x24c4
        LD_LOCAL         R1, 32   # 0x24c8
        SETP_LT_NP       P1, R1, R1, R9   # 0x24cc
        MOV_P            R9, 1, R11, R11, R11   # 0x24d0
        MOVI             R1, 0   # 0x24d4
        ADDI_P           R1, 0, R1, 1   # 0x24d8
        MOV_P            R1, 1, R5, R5, R5   # 0x24dc
        C_MOV            R5, R6   # 0x24e0
        ADD              R7, R1, R7, R1   # 0x24e2
        C_MOV            R1, R3   # 0x24e6
        BRA              L23ca   # 0x24e8
L24ec:  CHWIDTH_MULTI    64, 0   # 0x24ec
        C_MOV            R7, R1   # 0x24f0
L24f2:  C_CHWIDTH        R7, 0   # 0x24f2
        MOVI             R6, 0   # 0x24f4
        SETP_EQ_NPI      P0, R1, R8, 0   # 0x24f8
        ST_LOCAL         R7, 72   # 0x24fc
        BRA_PRED         0, L2750   # 0x2500
        LD_LOCAL         R1, 44   # 0x2504
        MOVI             R3, 0   # 0x2508
        C_BRA            L251e   # 0x250c
L250e:  C_ADD            R6, R8   # 0x250e
        LD_LOCAL         R3, 40   # 0x2510
        C_ADDI           R3, 1   # 0x2514
        SETP_NE_NP       P0, R1, R3, R8   # 0x2516
        BRA_PRED         4, L2624   # 0x251a
L251e:  ST_LOCAL         R3, 40   # 0x251e
        MUL_LO           R1, R3, R8, R8   # 0x2522
        ST_LOCAL         R1, 36   # 0x2526
        MOVI             R3, 0   # 0x252a
        C_BRA            L2554   # 0x252e
L2530:  LD_LOCAL         R1, 36   # 0x2530
        ADD              R5, R3, R1, R3   # 0x2534
        C_SHLI           R5, 2   # 0x2538
        LD_LOCAL         R1, 20   # 0x253a
        ADD              R5, R1, R5, R1   # 0x253e
        LD_LOCAL         R1, 16   # 0x2542
        ST_GLOBAL_IDX    R9, R1, R5, 0, 0   # 0x2546
        C_ADDI           R3, 1   # 0x254a
        SETP_NE_NP       P0, R5, R3, R8   # 0x254c
        BRA_PRED         4, L250e   # 0x2550
L2554:  LD_LOCAL         R1, 24   # 0x2554
        SETP_EQ_NPI      P0, R5, R1, 0   # 0x2558
        MOVI             R5, 0   # 0x255c
        MOVI             R9, 0   # 0x2560
        C_MOV            R1, R8   # 0x2564
        BRA_PRED         0, L25dc   # 0x2566
        C_MOV            R13, R3   # 0x256a
L256c:  C_CHWIDTH        R7, 1   # 0x256c
        ADD              R8, R6, R5, R6   # 0x256e
        C_SHLI           R8, 1   # 0x2572
        C_ADD            R8, R14   # 0x2574
        C_MOV            R11, R13   # 0x2576
        C_SHLI           R11, 1   # 0x2578
        ADD              R11, R10, R11, R10   # 0x257a
        C_CHWIDTH        R11, 1   # 0x257e
        LD_GLOBAL_IDX    R11, R15, R11, 0, 0   # 0x2580
        C_CHWIDTH        R11, 0   # 0x2584
        LD_GLOBAL_IDX    R7, R0, R8, 0, 0   # 0x2586
        C_CHWIDTH        R7, 0   # 0x258a
        MUL_LO           R7, R11, R7, R7   # 0x258c
        C_MOV            R11, R7   # 0x2590
        C_SHRI           R11, 5   # 0x2592
        ANDI             R11, R11, 127   # 0x2594
        C_SHRI           R7, 2   # 0x2598
        C_ANDI           R7, 15   # 0x259a
        MADLO            R7, R7, R11, R9   # 0x259c
        C_ADDI           R8, 2   # 0x25a0
        C_CHWIDTH        R8, 1   # 0x25a2
        LD_GLOBAL_IDX    R8, R0, R8, 0, 0   # 0x25a4
        C_CHWIDTH        R8, 0   # 0x25a8
        ADD              R9, R1, R13, R1   # 0x25aa
        C_SHLI           R9, 1   # 0x25ae
        ADD              R9, R10, R9, R10   # 0x25b0
        C_CHWIDTH        R9, 1   # 0x25b4
        LD_GLOBAL_IDX    R9, R15, R9, 0, 0   # 0x25b6
        C_CHWIDTH        R9, 0   # 0x25ba
        MUL_LO           R8, R9, R8, R8   # 0x25bc
        C_MOV            R9, R8   # 0x25c0
        C_SHRI           R9, 5   # 0x25c2
        ANDI             R9, R9, 127   # 0x25c4
        C_SHRI           R8, 2   # 0x25c8
        C_ANDI           R8, 15   # 0x25ca
        MADLO            R9, R8, R9, R7   # 0x25cc
        C_ADD            R13, R2   # 0x25d0
        C_ADDI           R5, 2   # 0x25d2
        SETP_NE_NP       P0, R7, R12, R5   # 0x25d4
        BRA_PRED         0, L256c   # 0x25d8
L25dc:  LD_LOCAL         R7, 28   # 0x25dc
        SETP_EQ_NPI      P0, R7, R7, 0   # 0x25e0
        C_MOV            R8, R1   # 0x25e4
        BRA_PRED         0, L2530   # 0x25e6
        MADLO            R7, R5, R8, R3   # 0x25ea
        C_SHLI           R7, 1   # 0x25ee
        ADD              R7, R10, R7, R10   # 0x25f0
        C_CHWIDTH        R7, 1   # 0x25f4
        LD_GLOBAL_IDX    R7, R15, R7, 0, 0   # 0x25f6
        C_CHWIDTH        R7, 0   # 0x25fa
        LD_LOCAL         R1, 36   # 0x25fc
        C_ADD            R5, R1   # 0x2600
        C_SHLI           R5, 1   # 0x2602
        ADD              R5, R14, R5, R14   # 0x2604
        C_CHWIDTH        R5, 1   # 0x2608
        LD_GLOBAL_IDX    R5, R0, R5, 0, 0   # 0x260a
        C_CHWIDTH        R5, 0   # 0x260e
        MUL_LO           R5, R7, R5, R5   # 0x2610
        C_MOV            R7, R5   # 0x2614
        C_SHRI           R7, 5   # 0x2616
        ANDI             R7, R7, 127   # 0x2618
        C_SHRI           R5, 2   # 0x261c
        C_ANDI           R5, 15   # 0x261e
        MAD_ACC          R9, R5, R7   # 0x2620
        C_BRA            L2530   # 0x2622
L2624:  MOVI             R1, 0   # 0x2624
        C_MOV            R15, R1   # 0x2628
        MOVI             R5, 0   # 0x262a
        MOVI             R11, 0   # 0x262e
        MOVI             R13, 0   # 0x2632
        MOVI             R1, 0   # 0x2636
        LD_LOCAL         R2, 44   # 0x263a
        MOVI             R4, 0   # 0x263e
        C_BRA            L2650   # 0x2642
L2644:  C_ADD            R5, R8   # 0x2644
        C_ADDI           R11, 1   # 0x2646
        SETP_NE_NP       P0, R3, R11, R8   # 0x2648
        BRA_PRED         4, L2752   # 0x264c
L2650:  ST_LOCAL         R11, 36   # 0x2650
        LD_LOCAL         R3, 24   # 0x2654
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2658
        BRA_PRED         0, L26e0   # 0x265c
        MOVI             R10, 0   # 0x2660
        LD_LOCAL         R11, 16   # 0x2664
        LD_LOCAL         R2, 20   # 0x2668
        LD_LOCAL         R9, 32   # 0x266c
        MOVI             R2, 10   # 0x2670
L2674:  C_CHWIDTH        R15, 1   # 0x2674
        ADD              R3, R5, R10, R5   # 0x2676
        C_SHLI           R3, 2   # 0x267a
        LD_LOCAL         R6, 20   # 0x267c
        C_ADD            R3, R6   # 0x2680
        C_MOV            R6, R5   # 0x2682
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x2684
        SETP_LT_NP       P0, R7, R13, R5   # 0x2688
        C_CHWIDTH        R7, 0   # 0x268c
        MOVI             R7, 0   # 0x268e
        ADDI_P           R7, 0, R7, 1   # 0x2692
        ADD              R1, R5, R1, R5   # 0x2696
        SETP_LT_NP       P0, R8, R9, R1   # 0x269a
        MOV_P            R7, 0, R2, R2, R2   # 0x269e
        C_CHWIDTH        R7, 1   # 0x26a2
        MOV_P            R1, 0, R4, R4, R4   # 0x26a4
        C_ADDI           R3, 4   # 0x26a8
        LD_GLOBAL_IDX    R13, R11, R3, 0, 0   # 0x26aa
        SETP_LT_NP       P0, R3, R5, R13   # 0x26ae
        MOVI             R3, 0   # 0x26b2
        ADDI_P           R3, 0, R3, 1   # 0x26b6
        ADD              R1, R13, R1, R13   # 0x26ba
        SETP_LT_NP       P0, R5, R9, R1   # 0x26be
        C_MOV            R5, R6   # 0x26c2
        MOV_P            R3, 0, R2, R2, R2   # 0x26c4
        MOV_P            R1, 0, R4, R4, R4   # 0x26c8
        ADD              R7, R7, R15, R7   # 0x26cc
        ADD              R15, R3, R7, R3   # 0x26d0
        C_ADDI           R10, 2   # 0x26d4
        SETP_NE_NP       P0, R3, R12, R10   # 0x26d6
        BRA_PRED         0, L2674   # 0x26da
        C_BRA            L26e8   # 0x26de
L26e0:  MOVI             R10, 0   # 0x26e0
        LD_LOCAL         R2, 20   # 0x26e4
L26e8:  C_CHWIDTH        R7, 0   # 0x26e8
        LD_LOCAL         R3, 28   # 0x26ea
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x26ee
        LD_LOCAL         R8, 12   # 0x26f2
        LD_LOCAL         R2, 20   # 0x26f6
        MOVI             R6, 0   # 0x26fa
        MOVI             R7, 10   # 0x26fe
        LD_LOCAL         R11, 36   # 0x2702
        BRA_PRED         0, L2644   # 0x2706
        C_CHWIDTH        R15, 1   # 0x270a
        MUL_LO           R3, R11, R8, R8   # 0x270c
        ADD              R3, R10, R3, R10   # 0x2710
        C_SHLI           R3, 2   # 0x2714
        ADD              R3, R2, R3, R2   # 0x2716
        C_MOV            R9, R5   # 0x271a
        LD_LOCAL         R5, 16   # 0x271c
        LD_GLOBAL_IDX    R3, R5, R3, 0, 0   # 0x2720
        SETP_LT_NP       P0, R5, R13, R3   # 0x2724
        ADD              R1, R3, R1, R3   # 0x2728
        LD_LOCAL         R2, 32   # 0x272c
        SETP_LT_NP       P1, R5, R2, R1   # 0x2730
        MOV_P            R1, 1, R6, R6, R6   # 0x2734
        MOVI             R5, 0   # 0x2738
        ADDI_P           R5, 0, R5, 1   # 0x273c
        MOV_P            R5, 1, R7, R7, R7   # 0x2740
        ADD              R15, R5, R15, R5   # 0x2744
        C_MOV            R5, R9   # 0x2748
        C_MOV            R13, R3   # 0x274a
        BRA              L2644   # 0x274c
L2750:  C_MOV            R15, R6   # 0x2750
L2752:  C_MOV            R1, R8   # 0x2752
        LD_LOCAL         R2, 60   # 0x2754
        C_MOV            R8, R2   # 0x2758
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x275a
        LD_LOCAL         R9, 56   # 0x275e
        LD_LOCAL         R10, 44   # 0x2762
        BRA_PRED         0, L2828   # 0x2766
        MOVI             R1, 0   # 0x276a
        LD_LOCAL         R2, 12   # 0x276e
        C_ANDI           R2, 3   # 0x2772
        MOVI             R5, 0   # 0x2774
        C_BRA            L278e   # 0x2778
L277a:  CHWIDTH_MULTI    8192, 0   # 0x277a
        LD_LOCAL         R3, 12   # 0x277e
        C_ADD            R1, R3   # 0x2782
        C_ADDI           R5, 1   # 0x2784
        SETP_NE_NP       P0, R3, R5, R3   # 0x2786
        BRA_PRED         4, L2828   # 0x278a
L278e:  LD_LOCAL         R3, 24   # 0x278e
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x2792
        MOVI             R3, 0   # 0x2796
        BRA_PRED         0, L27f4   # 0x279a
L279e:  CHWIDTH_MULTI    8320, 1   # 0x279e
        ADD              R6, R1, R3, R1   # 0x27a2
        C_SHLI           R6, 1   # 0x27a6
        ADD              R6, R14, R6, R14   # 0x27a8
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27ac
        SUB              R7, R7, R9, R7   # 0x27b0
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27b4
        C_CHWIDTH        R7, 0   # 0x27b8
        ADDI             R7, R6, 2   # 0x27ba
        LD_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27be
        SUB              R13, R13, R9, R13   # 0x27c2
        ST_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27c6
        ADDI             R7, R6, 4   # 0x27ca
        LD_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27ce
        SUB              R13, R13, R9, R13   # 0x27d2
        ST_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x27d6
        C_CHWIDTH        R7, 1   # 0x27da
        C_ADDI           R6, 6   # 0x27dc
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27de
        SUB              R7, R7, R9, R7   # 0x27e2
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27e6
        C_ADDI           R3, 4   # 0x27ea
        SETP_NE_NP       P0, R6, R10, R3   # 0x27ec
        BRA_PRED         0, L279e   # 0x27f0
L27f4:  SETP_EQ_NPI      P0, R6, R2, 0   # 0x27f4
        BRA_PRED         0, L277a   # 0x27f8
        C_ADD            R3, R1   # 0x27fc
        C_MOV            R6, R2   # 0x27fe
L2800:  C_CHWIDTH        R13, 1   # 0x2800
        C_CHWIDTH        R7, 0   # 0x2802
        C_MOV            R7, R3   # 0x2804
        C_SHLI           R7, 1   # 0x2806
        ADD              R7, R14, R7, R14   # 0x2808
        LD_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x280c
        SUB              R13, R13, R9, R13   # 0x2810
        ST_GLOBAL_IDX    R13, R0, R7, 0, 0   # 0x2814
        C_ADDI           R3, 1   # 0x2818
        ADDI             R6, R6, -1   # 0x281a
        SETP_NE_NPI      P0, R7, R6, 0   # 0x281e
        BRA_PRED         0, L2800   # 0x2822
        C_BRA            L277a   # 0x2826
L2828:  CHWIDTH_MULTI    32896, 0   # 0x2828
        LD_LOCAL         R1, 64   # 0x282c
        MOVI             R2, 0   # 0x2830
        CALL             R14, 129293   # 0x2834
        C_MOV            R2, R1   # 0x2838
        LD_LOCAL         R1, 68   # 0x283a
        CALL             R14, 129288   # 0x283e
        C_MOV            R2, R1   # 0x2842
        LD_LOCAL         R1, 72   # 0x2844
        CALL             R14, 129283   # 0x2848
        C_MOV            R2, R1   # 0x284c
        C_MOV            R1, R15   # 0x284e
        CALL             R14, 129279   # 0x2850
        C_MOV            R2, R8   # 0x2854
        CALL             R14, 129276   # 0x2856
        LD_LOCAL         R14, 52   # 0x285a
        LD_LOCAL         R13, 96   # 0x285e
        LD_LOCAL         R12, 92   # 0x2862
        LD_LOCAL         R11, 88   # 0x2866
        LD_LOCAL         R10, 84   # 0x286a
        LD_LOCAL         R9, 80   # 0x286e
        LD_LOCAL         R8, 76   # 0x2872
        C_RET            224   # 0x2876
        C_CHWIDTH        R0, 1   # 0x2878
        XOR              R0, R2, R1, R2   # 0x287a
        C_CHWIDTH        R0, 0   # 0x287e
        C_ANDI           R0, 1   # 0x2880
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2882
        MOVI             R0, 40961   # 0x2886
        SHRI             R2, R2, 1   # 0x288a
        C_MOV            R3, R2   # 0x288e
        C_CHWIDTH        R2, 1   # 0x2890
        XOR              R2, R2, R0, R2   # 0x2892
        C_CHWIDTH        R2, 0   # 0x2896
        MOV_P            R3, 0, R2, R2, R2   # 0x2898
        SHRI             R2, R1, 1   # 0x289c
        C_CHWIDTH        R2, 1   # 0x28a0
        XOR              R2, R2, R3, R2   # 0x28a2
        C_CHWIDTH        R2, 0   # 0x28a6
        C_ANDI           R2, 1   # 0x28a8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28aa
        SHRI             R2, R3, 1   # 0x28ae
        C_MOV            R3, R2   # 0x28b2
        C_CHWIDTH        R2, 1   # 0x28b4
        XOR              R2, R2, R0, R2   # 0x28b6
        C_CHWIDTH        R2, 0   # 0x28ba
        MOV_P            R3, 0, R2, R2, R2   # 0x28bc
        SHRI             R2, R1, 2   # 0x28c0
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
        SHRI             R2, R1, 3   # 0x28e4
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
        SHRI             R2, R1, 4   # 0x2908
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
        SHRI             R2, R1, 5   # 0x292c
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
        SHRI             R2, R1, 6   # 0x2950
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
        MOVI             R2, 128   # 0x2974
        C_CHWIDTH        R2, 1   # 0x2978
        AND              R2, R1, R2, R1   # 0x297a
        C_CHWIDTH        R2, 0   # 0x297e
        SHRI             R2, R2, 7   # 0x2980
        ANDI             R4, R3, 1   # 0x2984
        SETP_EQ_NP       P0, R2, R2, R4   # 0x2988
        SHRI             R2, R3, 1   # 0x298c
        C_MOV            R3, R2   # 0x2990
        C_CHWIDTH        R2, 1   # 0x2992
        XOR              R2, R2, R0, R2   # 0x2994
        C_CHWIDTH        R2, 0   # 0x2998
        MOV_P            R2, 0, R3, R3, R3   # 0x299a
        SHRI             R3, R1, 8   # 0x299e
        C_CHWIDTH        R3, 1   # 0x29a2
        XOR              R3, R2, R3, R2   # 0x29a4
        C_CHWIDTH        R3, 0   # 0x29a8
        C_ANDI           R3, 1   # 0x29aa
        SETP_NE_NPI      P0, R3, R3, 0   # 0x29ac
        SHRI             R2, R2, 1   # 0x29b0
        C_MOV            R3, R2   # 0x29b4
        C_CHWIDTH        R2, 1   # 0x29b6
        XOR              R2, R2, R0, R2   # 0x29b8
        C_CHWIDTH        R2, 0   # 0x29bc
        MOV_P            R3, 0, R2, R2, R2   # 0x29be
        SHRI             R2, R1, 9   # 0x29c2
        C_CHWIDTH        R2, 1   # 0x29c6
        XOR              R2, R2, R3, R2   # 0x29c8
        C_CHWIDTH        R2, 0   # 0x29cc
        C_ANDI           R2, 1   # 0x29ce
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29d0
        SHRI             R2, R3, 1   # 0x29d4
        C_MOV            R3, R2   # 0x29d8
        C_CHWIDTH        R2, 1   # 0x29da
        XOR              R2, R2, R0, R2   # 0x29dc
        C_CHWIDTH        R2, 0   # 0x29e0
        MOV_P            R3, 0, R2, R2, R2   # 0x29e2
        SHRI             R2, R1, 10   # 0x29e6
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
        SHRI             R2, R1, 11   # 0x2a0a
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
        SHRI             R2, R1, 12   # 0x2a2e
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
        SHRI             R2, R1, 13   # 0x2a52
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
        SHRI             R2, R1, 14   # 0x2a76
        C_CHWIDTH        R2, 1   # 0x2a7a
        XOR              R2, R2, R3, R2   # 0x2a7c
        C_CHWIDTH        R2, 0   # 0x2a80
        C_ANDI           R2, 1   # 0x2a82
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a84
        SHRI             R2, R3, 1   # 0x2a88
        C_MOV            R3, R2   # 0x2a8c
        C_CHWIDTH        R2, 1   # 0x2a8e
        XOR              R2, R2, R0, R2   # 0x2a90
        C_CHWIDTH        R0, 1   # 0x2a94
        C_CHWIDTH        R2, 0   # 0x2a96
        MOV_P            R3, 0, R2, R2, R2   # 0x2a98
        SHRI             R1, R1, 15   # 0x2a9c
        ANDI             R2, R3, 1   # 0x2aa0
        SETP_EQ_NP       P0, R1, R1, R2   # 0x2aa4
        SHRI             R1, R3, 1   # 0x2aa8
        C_MOV            R2, R1   # 0x2aac
        XOR              R0, R1, R0, R1   # 0x2aae
        C_CHWIDTH        R0, 0   # 0x2ab2
        MOV_P            R0, 0, R2, R2, R2   # 0x2ab4
        MOVI             R1, 65535   # 0x2ab8
        AND              R1, R0, R1, R0   # 0x2abc
        C_RET            224   # 0x2ac0
        C_CHWIDTH        R6, 1   # 0x2ac2
        MOVI             R15, 2   # 0x2ac4
        LD_GLOBAL        R15, R15, 24   # 0x2ac8
        SRD              R0, 2   # 0x2acc
        C_ADD            R15, R0   # 0x2ace
        ST_LOCAL         R8, 176   # 0x2ad0
        ST_LOCAL         R9, 180   # 0x2ad4
        ST_LOCAL         R10, 184   # 0x2ad8
        ST_LOCAL         R11, 188   # 0x2adc
        ST_LOCAL         R12, 192   # 0x2ae0
        ST_LOCAL         R13, 196   # 0x2ae4
        ST_LOCAL         R14, 164   # 0x2ae8
        ST_LOCAL         R2, 112   # 0x2aec
        C_MOV            R13, R1   # 0x2af0
        LD_GLOBAL_IDX    R0, R13, R2, 0, 60   # 0x2af2
        SHLI             R0, R0, 16   # 0x2af6
        LD_GLOBAL_IDX    R1, R13, R2, 0, 56   # 0x2afa
        SHRI             R4, R1, 16   # 0x2afe
        OR               R8, R0, R4, R0   # 0x2b02
        MOVI             R0, 65535   # 0x2b06
        C_AND            R1, R0   # 0x2b0a
        LD_GLOBAL_IDX    R6, R13, R2, 0, 4   # 0x2b0c
        C_MOV            R5, R3   # 0x2b10
        CVT_SEXT         R2, R6, R6, R6   # 0x2b12
        SETP_LT_NPI      P0, R2, R2, 1   # 0x2b16
        BRA_PRED         0, L2e56   # 0x2b1a
        CHWIDTH_MULTI    16416, 1   # 0x2b1e
        ST_LOCAL         R3, 108   # 0x2b22
        MOVI             R2, 0   # 0x2b26
        ADDI             R14, R6, 255   # 0x2b2a
        C_CHWIDTH        R14, 0   # 0x2b2e
        ST_LOCAL         R14, 116   # 0x2b30
        C_MOV            R7, R2   # 0x2b34
        ST_LOCAL         R2, 100   # 0x2b36
        ST_LOCAL         R2, 104   # 0x2b3a
        C_BRA            L2bba   # 0x2b3e
L2b40:  C_CHWIDTH        R12, 1   # 0x2b40
        C_MOV            R4, R8   # 0x2b42
        C_MOV            R14, R1   # 0x2b44
        LD_GLOBAL_IDX    R3, R4, R14, 0, 0   # 0x2b46
        LD_GLOBAL_IDX    R4, R4, R14, 0, 4   # 0x2b4a
        SHLI             R4, R4, 16   # 0x2b4e
        SHRI             R14, R3, 16   # 0x2b52
        C_OR             R4, R14   # 0x2b56
        C_AND            R3, R0   # 0x2b58
        LD_GLOBAL_IDX    R14, R4, R3, 0, 8   # 0x2b5a
        LD_GLOBAL_IDX    R3, R4, R3, 0, 12   # 0x2b5e
        SHLI             R3, R3, 16   # 0x2b62
        SHRI             R4, R14, 16   # 0x2b66
        C_OR             R3, R4   # 0x2b6a
        C_CHWIDTH        R3, 1   # 0x2b6c
        AND              R4, R14, R0, R14   # 0x2b6e
        LD_GLOBAL_IDX    R3, R3, R4, 0, 0   # 0x2b72
        C_CHWIDTH        R3, 0   # 0x2b76
        SHRI             R3, R3, 8   # 0x2b78
        MOVI             R4, 1   # 0x2b7c
        AND              R12, R3, R4, R3   # 0x2b80
        LD_LOCAL         R14, 104   # 0x2b84
        C_CHWIDTH        R14, 1   # 0x2b88
        ADDI             R14, R14, 1   # 0x2b8a
        C_CHWIDTH        R14, 0   # 0x2b8e
        ST_LOCAL         R14, 104   # 0x2b90
L2b94:  C_CHWIDTH        R6, 0   # 0x2b94
        CHWIDTH_MULTI    172, 1   # 0x2b96
        ADD              R7, R12, R7, R12   # 0x2b9a
        XOR              R3, R5, R0, R5   # 0x2b9e
        C_CHWIDTH        R3, 0   # 0x2ba2
        SHRI             R3, R3, 15   # 0x2ba4
        ADD              R5, R5, R3, R5   # 0x2ba8
        ADDI             R2, R2, 1   # 0x2bac
        C_CHWIDTH        R2, 0   # 0x2bb0
        SETP_NE_NP       P0, R3, R2, R6   # 0x2bb2
        BRA_PRED         4, L2e1a   # 0x2bb6
L2bba:  C_CHWIDTH        R12, 0   # 0x2bba
        C_MOV            R12, R8   # 0x2bbc
        SHLI             R4, R12, 16   # 0x2bbe
        C_MOV            R10, R1   # 0x2bc2
        AND              R14, R4, R10, R4   # 0x2bc4
        ADD              R9, R4, R10, R4   # 0x2bc8
        C_OR             R4, R10   # 0x2bcc
        C_ANDN           R4, R9   # 0x2bce
        OR               R4, R14, R4, R14   # 0x2bd0
        SHRI             R4, R4, 31   # 0x2bd4
        SHRI             R14, R12, 16   # 0x2bd8
        ADD              R4, R14, R4, R14   # 0x2bdc
        OR               R11, R9, R4, R9   # 0x2be0
        CVT_SEXT         R4, R5, R5, R5   # 0x2be4
        MOVI48           R3, 4294967295   # 0x2be8
        SETP_LT_NP       P0, R4, R3, R4   # 0x2bee
        BRA_PRED         4, L2c56   # 0x2bf2
        MOVI             R9, 0   # 0x2bf6
        SETP_EQ_NPI      P0, R4, R11, 0   # 0x2bfa
        BRA_PRED         0, L2cbc   # 0x2bfe
        C_MOV            R12, R8   # 0x2c02
        C_MOV            R10, R1   # 0x2c04
L2c06:  C_CHWIDTH        R5, 0   # 0x2c06
        LD_GLOBAL_IDX    R4, R12, R10, 0, 8   # 0x2c08
        LD_GLOBAL_IDX    R14, R12, R10, 0, 12   # 0x2c0c
        SHLI             R14, R14, 16   # 0x2c10
        SHRI             R3, R4, 16   # 0x2c14
        OR               R3, R14, R3, R14   # 0x2c18
        C_CHWIDTH        R3, 1   # 0x2c1c
        C_AND            R4, R0   # 0x2c1e
        LD_GLOBAL_IDX    R3, R3, R4, 0, 2   # 0x2c20
        C_CHWIDTH        R3, 0   # 0x2c24
        SETP_EQ_NP       P0, R3, R3, R5   # 0x2c26
        BRA_PRED         0, L2d2c   # 0x2c2a
        LD_GLOBAL_IDX    R3, R12, R10, 0, 4   # 0x2c2e
        LD_GLOBAL_IDX    R4, R12, R10, 0, 0   # 0x2c32
        SHRI             R14, R4, 16   # 0x2c36
        SHLI             R10, R3, 16   # 0x2c3a
        OR               R12, R10, R14, R10   # 0x2c3e
        C_AND            R3, R0   # 0x2c42
        OR               R3, R4, R3, R4   # 0x2c44
        AND              R10, R4, R0, R4   # 0x2c48
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c4c
        BRA_PRED         4, L2c06   # 0x2c50
        C_BRA            L2cbc   # 0x2c54
L2c56:  MOVI             R9, 0   # 0x2c56
        SETP_EQ_NPI      P0, R4, R11, 0   # 0x2c5a
        BRA_PRED         0, L2cbc   # 0x2c5e
L2c62:  LD_GLOBAL_IDX    R3, R12, R10, 0, 8   # 0x2c62
        LD_GLOBAL_IDX    R4, R12, R10, 0, 12   # 0x2c66
        SHLI             R4, R4, 16   # 0x2c6a
        SHRI             R14, R3, 16   # 0x2c6e
        C_OR             R4, R14   # 0x2c72
        C_CHWIDTH        R14, 1   # 0x2c74
        C_AND            R3, R0   # 0x2c76
        LD_GLOBAL_IDX    R14, R4, R3, 0, 0   # 0x2c78
        XOR              R14, R14, R2, R14   # 0x2c7c
        MOVI             R3, 255   # 0x2c80
        C_CHWIDTH        R3, 1   # 0x2c84
        AND              R3, R14, R3, R14   # 0x2c86
        C_CHWIDTH        R3, 0   # 0x2c8a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c8c
        BRA_PRED         0, L2d2c   # 0x2c90
        C_CHWIDTH        R14, 0   # 0x2c94
        LD_GLOBAL_IDX    R3, R12, R10, 0, 4   # 0x2c96
        LD_GLOBAL_IDX    R4, R12, R10, 0, 0   # 0x2c9a
        SHRI             R14, R4, 16   # 0x2c9e
        SHLI             R10, R3, 16   # 0x2ca2
        OR               R12, R10, R14, R10   # 0x2ca6
        C_AND            R3, R0   # 0x2caa
        OR               R3, R4, R3, R4   # 0x2cac
        AND              R10, R4, R0, R4   # 0x2cb0
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2cb4
        BRA_PRED         0, L2c62   # 0x2cb8
L2cbc:  MOVI             R10, 0   # 0x2cbc
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2cc0
        BRA_PRED         0, L2d36   # 0x2cc4
L2cc8:  MOVI             R11, 0   # 0x2cc8
        MOVI             R4, 0   # 0x2ccc
L2cd0:  C_CHWIDTH        R14, 0   # 0x2cd0
        C_MOV            R14, R1   # 0x2cd2
        C_MOV            R12, R8   # 0x2cd4
        SHLI             R3, R11, 16   # 0x2cd6
        AND              R1, R3, R4, R3   # 0x2cda
        ADD              R8, R3, R4, R3   # 0x2cde
        C_OR             R3, R4   # 0x2ce2
        C_ANDN           R3, R8   # 0x2ce4
        OR               R3, R1, R3, R1   # 0x2ce6
        SHRI             R3, R3, 31   # 0x2cea
        SHRI             R4, R11, 16   # 0x2cee
        ADD              R3, R4, R3, R4   # 0x2cf2
        LD_GLOBAL_IDX    R4, R12, R14, 0, 0   # 0x2cf6
        ST_GLOBAL_IDX    R8, R12, R14, 0, 0   # 0x2cfa
        LD_GLOBAL_IDX    R1, R12, R14, 0, 4   # 0x2cfe
        ST_GLOBAL_IDX    R3, R12, R14, 0, 4   # 0x2d02
        SHRI             R3, R4, 16   # 0x2d06
        SHLI             R11, R1, 16   # 0x2d0a
        OR               R8, R11, R3, R11   # 0x2d0e
        AND              R3, R1, R0, R1   # 0x2d12
        OR               R3, R4, R3, R4   # 0x2d16
        AND              R1, R4, R0, R4   # 0x2d1a
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d1e
        C_MOV            R11, R12   # 0x2d22
        C_MOV            R4, R14   # 0x2d24
        BRA_PRED         0, L2cd0   # 0x2d26
        C_BRA            L2d40   # 0x2d2a
L2d2c:  C_MOV            R9, R12   # 0x2d2c
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2d2e
        BRA_PRED         4, L2cc8   # 0x2d32
L2d36:  C_CHWIDTH        R14, 0   # 0x2d36
        MOVI             R12, 0   # 0x2d38
        MOVI             R14, 0   # 0x2d3c
L2d40:  C_MOV            R1, R14   # 0x2d40
        C_MOV            R8, R12   # 0x2d42
        SHLI             R3, R9, 16   # 0x2d44
        AND              R4, R3, R10, R3   # 0x2d48
        ADD              R14, R3, R10, R3   # 0x2d4c
        C_OR             R3, R10   # 0x2d50
        C_ANDN           R3, R14   # 0x2d52
        OR               R3, R4, R3, R4   # 0x2d54
        SHRI             R3, R3, 31   # 0x2d58
        SHRI             R4, R9, 16   # 0x2d5c
        ADD              R3, R4, R3, R4   # 0x2d60
        OR               R3, R14, R3, R14   # 0x2d64
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d68
        BRA_PRED         4, L2b40   # 0x2d6c
        LD_GLOBAL_IDX    R3, R9, R10, 0, 12   # 0x2d70
        SHLI             R3, R3, 16   # 0x2d74
        LD_GLOBAL_IDX    R4, R9, R10, 0, 8   # 0x2d78
        SHRI             R14, R4, 16   # 0x2d7c
        C_OR             R3, R14   # 0x2d80
        C_CHWIDTH        R3, 1   # 0x2d82
        C_AND            R4, R0   # 0x2d84
        LD_GLOBAL_IDX    R3, R3, R4, 0, 0   # 0x2d86
        C_CHWIDTH        R3, 0   # 0x2d8a
        LD_GLOBAL_IDX    R14, R9, R10, 0, 4   # 0x2d8c
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2d90
        SHRI             R11, R3, 9   # 0x2d94
        C_CHWIDTH        R3, 1   # 0x2d98
        AND              R3, R3, R11, R3   # 0x2d9a
        AND              R11, R14, R0, R14   # 0x2d9e
        OR               R11, R4, R11, R4   # 0x2da2
        MOVI             R12, 1   # 0x2da6
        C_CHWIDTH        R12, 1   # 0x2daa
        AND              R12, R3, R12, R3   # 0x2dac
        C_CHWIDTH        R3, 0   # 0x2db0
        LD_LOCAL         R3, 100   # 0x2db2
        C_CHWIDTH        R3, 1   # 0x2db6
        ADDI             R3, R3, 1   # 0x2db8
        C_CHWIDTH        R3, 0   # 0x2dbc
        ST_LOCAL         R3, 100   # 0x2dbe
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2dc2
        BRA_PRED         0, L2b94   # 0x2dc6
        SHRI             R3, R4, 16   # 0x2dca
        SHLI             R14, R14, 16   # 0x2dce
        OR               R3, R14, R3, R14   # 0x2dd2
        C_CHWIDTH        R14, 1   # 0x2dd6
        C_AND            R4, R0   # 0x2dd8
        LD_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x2dda
        C_CHWIDTH        R14, 0   # 0x2dde
        LD_GLOBAL_IDX    R11, R3, R4, 0, 0   # 0x2de0
        ST_GLOBAL_IDX    R11, R9, R10, 0, 0   # 0x2de4
        ST_GLOBAL_IDX    R14, R9, R10, 0, 4   # 0x2de8
        C_CHWIDTH        R14, 1   # 0x2dec
        C_MOV            R10, R8   # 0x2dee
        C_MOV            R11, R1   # 0x2df0
        LD_GLOBAL_IDX    R14, R10, R11, 0, 4   # 0x2df2
        C_CHWIDTH        R14, 0   # 0x2df6
        LD_GLOBAL_IDX    R9, R10, R11, 0, 0   # 0x2df8
        ST_GLOBAL_IDX    R9, R3, R4, 0, 0   # 0x2dfc
        ST_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x2e00
        SHRI             R14, R3, 16   # 0x2e04
        ST_GLOBAL_IDX    R14, R10, R11, 0, 4   # 0x2e08
        SHLI             R3, R3, 16   # 0x2e0c
        C_OR             R3, R4   # 0x2e10
        ST_GLOBAL_IDX    R3, R10, R11, 0, 0   # 0x2e12
        BRA              L2b94   # 0x2e16
L2e1a:  CHWIDTH_MULTI    32, 0   # 0x2e1a
        C_CHWIDTH        R2, 1   # 0x2e1e
        MOVI             R0, 255   # 0x2e20
        LD_LOCAL         R14, 116   # 0x2e24
        AND              R2, R14, R0, R14   # 0x2e28
        CHWIDTH_MULTI    4, 0   # 0x2e2c
        LD_LOCAL         R0, 100   # 0x2e30
        SHLI             R0, R0, 2   # 0x2e34
        LD_LOCAL         R14, 104   # 0x2e38
        C_CHWIDTH        R14, 1   # 0x2e3c
        SUB              R14, R0, R14, R0   # 0x2e3e
        C_CHWIDTH        R0, 1   # 0x2e42
        ADD              R0, R14, R7, R14   # 0x2e44
        CHWIDTH_MULTI    16513, 0   # 0x2e48
        ST_LOCAL         R0, 160   # 0x2e4c
        LD_LOCAL         R3, 108   # 0x2e50
        C_BRA            L2e64   # 0x2e54
L2e56:  CHWIDTH_MULTI    64, 0   # 0x2e56
        MOVI             R0, 0   # 0x2e5a
        C_MOV            R2, R0   # 0x2e5e
        ST_LOCAL         R2, 160   # 0x2e60
L2e64:  CHWIDTH_MULTI    4096, 0   # 0x2e64
        ST_LOCAL         R5, 168   # 0x2e68
        C_MOV            R14, R3   # 0x2e6c
        C_CHWIDTH        R14, 1   # 0x2e6e
        C_MOV            R7, R3   # 0x2e70
        C_CHWIDTH        R7, 1   # 0x2e72
        C_MOV            R6, R3   # 0x2e74
        C_CHWIDTH        R6, 1   # 0x2e76
        CVT_SEXT         R0, R14, R7, R6   # 0x2e78
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2e7c
        ST_LOCAL         R2, 172   # 0x2e80
        BRA_PRED         0, L3464   # 0x2e84
        CHWIDTH_MULTI    192, 0   # 0x2e88
        MOVI             R0, 1   # 0x2e8c
        ST_LOCAL         R0, 148   # 0x2e90
        MOVI             R12, 65535   # 0x2e94
        C_MOV            R7, R8   # 0x2e98
        C_MOV            R6, R1   # 0x2e9a
        ST_LOCAL         R13, 136   # 0x2e9c
        C_BRA            L2ed0   # 0x2ea0
L2ea2:  MOVI             R0, 0   # 0x2ea2
        ST_GLOBAL_IDX    R0, R10, R11, 0, 4   # 0x2ea6
        ST_GLOBAL_IDX    R0, R10, R11, 0, 0   # 0x2eaa
        LD_LOCAL         R0, 148   # 0x2eae
        C_SHLI           R0, 1   # 0x2eb2
        ST_LOCAL         R0, 148   # 0x2eb4
        LD_LOCAL         R0, 156   # 0x2eb8
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2ebc
        LD_LOCAL         R8, 144   # 0x2ec0
        C_MOV            R7, R8   # 0x2ec4
        LD_LOCAL         R9, 140   # 0x2ec6
        C_MOV            R6, R9   # 0x2eca
        BRA_PRED         4, L346a   # 0x2ecc
L2ed0:  MOVI             R5, 0   # 0x2ed0
        MOVI             R10, 0   # 0x2ed4
        MOVI             R11, 0   # 0x2ed8
        MOVI             R0, 0   # 0x2edc
        ST_LOCAL         R0, 144   # 0x2ee0
        ST_LOCAL         R0, 140   # 0x2ee4
        C_BRA            L2ef6   # 0x2ee8
L2eea:  SETP_EQ_NPI      P0, R0, R0, 0   # 0x2eea
        LD_LOCAL         R5, 152   # 0x2eee
        BRA_PRED         0, L2ea2   # 0x2ef2
L2ef6:  LD_LOCAL         R4, 148   # 0x2ef6
        SETP_LT_NPI      P0, R0, R4, 1   # 0x2efa
        BRA_PRED         0, L2f3c   # 0x2efe
        MOVI             R2, 0   # 0x2f02
        C_MOV            R0, R7   # 0x2f06
        C_MOV            R1, R6   # 0x2f08
L2f0a:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x2f0a
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x2f0e
        AND              R0, R3, R12, R3   # 0x2f12
        OR               R0, R1, R0, R1   # 0x2f16
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2f1a
        BRA_PRED         4, L2f46   # 0x2f1e
        SHRI             R0, R1, 16   # 0x2f22
        SHLI             R3, R3, 16   # 0x2f26
        OR               R0, R3, R0, R3   # 0x2f2a
        C_AND            R1, R12   # 0x2f2e
        C_ADDI           R2, 1   # 0x2f30
        SETP_EQ_NP       P0, R3, R4, R2   # 0x2f32
        BRA_PRED         4, L2f0a   # 0x2f36
        C_BRA            L2f52   # 0x2f3a
L2f3c:  MOVI             R4, 0   # 0x2f3c
        C_MOV            R0, R7   # 0x2f40
        C_MOV            R1, R6   # 0x2f42
        C_BRA            L2f52   # 0x2f44
L2f46:  MOVI             R0, 0   # 0x2f46
        ADDI             R4, R2, 1   # 0x2f4a
        MOVI             R1, 0   # 0x2f4e
L2f52:  ST_LOCAL         R5, 156   # 0x2f52
        ADDI             R2, R5, 1   # 0x2f56
        ST_LOCAL         R2, 152   # 0x2f5a
        C_MOV            R9, R7   # 0x2f5e
        C_MOV            R8, R6   # 0x2f60
        C_MOV            R7, R0   # 0x2f62
        C_MOV            R6, R1   # 0x2f64
        LD_LOCAL         R0, 148   # 0x2f66
        ST_LOCAL         R0, 104   # 0x2f6a
        C_BRA            L2f88   # 0x2f6e
L2f70:  ST_LOCAL         R4, 144   # 0x2f70
        ST_LOCAL         R5, 140   # 0x2f74
L2f78:  C_MOV            R9, R1   # 0x2f78
        C_MOV            R8, R3   # 0x2f7a
        C_MOV            R7, R0   # 0x2f7c
        C_MOV            R6, R2   # 0x2f7e
        C_MOV            R10, R4   # 0x2f80
        C_MOV            R11, R5   # 0x2f82
        LD_LOCAL         R4, 100   # 0x2f84
L2f88:  MOVI             R0, 0   # 0x2f88
        SETP_LT_NP       P0, R0, R0, R4   # 0x2f8c
        BRA_PRED         0, L2fcc   # 0x2f90
        SHLI             R0, R7, 16   # 0x2f94
        AND              R1, R0, R6, R0   # 0x2f98
        ADD              R2, R0, R6, R0   # 0x2f9c
        C_OR             R0, R6   # 0x2fa0
        C_ANDN           R0, R2   # 0x2fa2
        OR               R0, R1, R0, R1   # 0x2fa4
        SHRI             R0, R0, 31   # 0x2fa8
        SHRI             R1, R7, 16   # 0x2fac
        ADD              R0, R1, R0, R1   # 0x2fb0
        OR               R0, R2, R0, R2   # 0x2fb4
        LD_LOCAL         R1, 104   # 0x2fb8
        SETP_LT_NPI      P0, R1, R1, 1   # 0x2fbc
        BRA_PRED         0, L2eea   # 0x2fc0
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x2fc4
        BRA_PRED         0, L2eea   # 0x2fc8
L2fcc:  SETP_NE_NPI      P0, R0, R4, 0   # 0x2fcc
        BRA_PRED         4, L311c   # 0x2fd0
        LD_LOCAL         R0, 104   # 0x2fd4
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2fd8
        BRA_PRED         0, L33e4   # 0x2fdc
        SHLI             R0, R7, 16   # 0x2fe0
        AND              R1, R0, R6, R0   # 0x2fe4
        ADD              R2, R0, R6, R0   # 0x2fe8
        C_OR             R0, R6   # 0x2fec
        C_ANDN           R0, R2   # 0x2fee
        OR               R0, R1, R0, R1   # 0x2ff0
        SHRI             R0, R0, 31   # 0x2ff4
        SHRI             R1, R7, 16   # 0x2ff8
        ADD              R0, R1, R0, R1   # 0x2ffc
        OR               R0, R2, R0, R2   # 0x3000
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3004
        BRA_PRED         4, L33e4   # 0x3008
        C_CHWIDTH        R14, 0   # 0x300c
        LD_GLOBAL_IDX    R5, R7, R6, 0, 8   # 0x300e
        LD_GLOBAL_IDX    R14, R7, R6, 0, 12   # 0x3012
        LD_GLOBAL_IDX    R0, R9, R8, 0, 8   # 0x3016
        LD_GLOBAL_IDX    R1, R9, R8, 0, 12   # 0x301a
        SHLI             R1, R1, 16   # 0x301e
        SHRI             R2, R0, 16   # 0x3022
        C_OR             R1, R2   # 0x3026
        AND              R2, R0, R12, R0   # 0x3028
        C_CHWIDTH        R12, 1   # 0x302c
        LD_GLOBAL_IDX    R12, R1, R2, 0, 0   # 0x302e
        MOVI             R0, 128   # 0x3032
        C_CHWIDTH        R0, 1   # 0x3036
        AND              R0, R12, R0, R12   # 0x3038
        C_CHWIDTH        R0, 0   # 0x303c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x303e
        ST_LOCAL         R4, 100   # 0x3042
        ST_LOCAL         R6, 108   # 0x3046
        BRA_PRED         4, L313e   # 0x304a
        ST_LOCAL         R2, 132   # 0x304e
        ST_LOCAL         R1, 128   # 0x3052
        ST_LOCAL         R14, 124   # 0x3056
        ST_LOCAL         R5, 120   # 0x305a
        MOVI             R0, 7   # 0x305e
        C_CHWIDTH        R0, 1   # 0x3062
        AND              R0, R12, R0, R12   # 0x3064
        CHWIDTH_MULTI    4097, 0   # 0x3068
        SHRI             R1, R12, 3   # 0x306c
        C_CHWIDTH        R1, 1   # 0x3070
        MOVI             R2, 15   # 0x3072
        AND              R1, R1, R2, R1   # 0x3076
        C_CHWIDTH        R1, 0   # 0x307a
        MULI             R1, R1, 17   # 0x307c
        C_MOV            R3, R1   # 0x3080
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x3082
        BRA_PRED         0, L314e   # 0x3086
        SETP_NE_NPI      P0, R0, R0, 0   # 0x308a
        C_MOV            R5, R12   # 0x308e
        BRA_PRED         0, L319a   # 0x3090
        CHWIDTH_MULTI    48, 1   # 0x3094
        ST_LOCAL         R7, 116   # 0x3098
        MOVI             R0, 34   # 0x309c
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x30a0
        C_CHWIDTH        R0, 1   # 0x30a4
        MOVI             R6, 34   # 0x30a6
        MOV_P            R6, 0, R3, R3, R3   # 0x30aa
        C_MOV            R2, R13   # 0x30ae
        LD_LOCAL         R13, 112   # 0x30b0
        LD_GLOBAL_IDX    R0, R2, R13, 0, 96   # 0x30b4
        C_CHWIDTH        R0, 0   # 0x30b8
        LD_GLOBAL_IDX    R1, R2, R13, 0, 40   # 0x30ba
        LD_GLOBAL_IDX    R5, R2, R13, 0, 2   # 0x30be
        C_CHWIDTH        R5, 0   # 0x30c2
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x30c4
        C_CHWIDTH        R4, 0   # 0x30c8
        LD_GLOBAL_IDX    R3, R2, R13, 0, 32   # 0x30ca
        LD_GLOBAL_IDX    R2, R2, R13, 0, 36   # 0x30ce
        ST_GLOBAL        R0, R15, -4   # 0x30d2
        SHLI             R0, R2, 16   # 0x30d6
        SHRI             R2, R3, 16   # 0x30da
        OR               R2, R0, R2, R0   # 0x30de
        MOVI             R0, 65535   # 0x30e2
        C_AND            R3, R0   # 0x30e6
        CALL             R14, 127117   # 0x30e8
        C_CHWIDTH        R0, 1   # 0x30ec
        MOVI             R15, 2   # 0x30ee
        LD_GLOBAL        R15, R15, 24   # 0x30f2
        SRD              R3, 2   # 0x30f6
        C_ADD            R15, R3   # 0x30f8
        C_MOV            R2, R13   # 0x30fa
        LD_LOCAL         R13, 136   # 0x30fc
        LD_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x3100
        C_CHWIDTH        R0, 0   # 0x3104
        C_MOV            R5, R1   # 0x3106
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3108
        BRA_PRED         0, L3196   # 0x310c
        C_MOV            R0, R5   # 0x3110
        C_CHWIDTH        R0, 1   # 0x3112
        ST_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x3114
        C_CHWIDTH        R0, 0   # 0x3118
        C_BRA            L3196   # 0x311a
L311c:  LD_GLOBAL_IDX    R1, R7, R6, 0, 0   # 0x311c
        LD_GLOBAL_IDX    R0, R7, R6, 0, 4   # 0x3120
        SHLI             R0, R0, 16   # 0x3124
        SHRI             R2, R1, 16   # 0x3128
        C_OR             R0, R2   # 0x312c
        AND              R2, R1, R12, R1   # 0x312e
        MOVI             R1, 0   # 0x3132
        ST_LOCAL         R1, 100   # 0x3136
        BRA              L33ce   # 0x313a
L313e:  C_CHWIDTH        R3, 1   # 0x313e
        MOVI             R0, 127   # 0x3140
        AND              R3, R12, R0, R12   # 0x3144
        MOVI             R2, 128   # 0x3148
        C_BRA            L31fe   # 0x314c
L314e:  C_CHWIDTH        R4, 1   # 0x314e
        ST_LOCAL         R7, 116   # 0x3150
        C_MOV            R1, R13   # 0x3154
        LD_LOCAL         R13, 112   # 0x3156
        LD_GLOBAL_IDX    R4, R1, R13, 0, 96   # 0x315a
        C_CHWIDTH        R4, 0   # 0x315e
        ADDI             R2, R13, 64   # 0x3160
        CALL             R14, 128410   # 0x3164
        C_CHWIDTH        R0, 1   # 0x3168
        MOVI             R15, 2   # 0x316a
        LD_GLOBAL        R15, R15, 24   # 0x316e
        SRD              R3, 2   # 0x3172
        C_ADD            R15, R3   # 0x3174
        C_MOV            R2, R13   # 0x3176
        LD_LOCAL         R13, 136   # 0x3178
        LD_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x317c
        C_CHWIDTH        R0, 0   # 0x3180
        C_MOV            R5, R1   # 0x3182
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3184
        BRA_PRED         0, L3196   # 0x3188
        C_MOV            R0, R5   # 0x318c
        C_CHWIDTH        R0, 1   # 0x318e
        ST_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x3190
        C_CHWIDTH        R0, 0   # 0x3194
L3196:  LD_LOCAL         R7, 116   # 0x3196
L319a:  C_CHWIDTH        R2, 1   # 0x319a
        LD_LOCAL         R6, 112   # 0x319c
        LD_GLOBAL_IDX    R2, R13, R6, 0, 96   # 0x31a0
        C_CHWIDTH        R2, 0   # 0x31a4
        C_MOV            R1, R5   # 0x31a6
        CALL             R14, 129894   # 0x31a8
        CHWIDTH_MULTI    16386, 1   # 0x31ac
        MOVI             R15, 2   # 0x31b0
        LD_GLOBAL        R15, R15, 24   # 0x31b4
        SRD              R3, 2   # 0x31b8
        C_ADD            R15, R3   # 0x31ba
        C_CHWIDTH        R3, 1   # 0x31bc
        ST_GLOBAL_IDX    R1, R13, R6, 0, 96   # 0x31be
        C_CHWIDTH        R1, 0   # 0x31c2
        MOVI             R0, 127   # 0x31c4
        AND              R3, R5, R0, R5   # 0x31c8
        MOVI             R0, 65280   # 0x31cc
        AND              R14, R12, R0, R12   # 0x31d0
        OR               R14, R14, R3, R14   # 0x31d4
        MOVI             R2, 128   # 0x31d8
        OR               R14, R14, R2, R14   # 0x31dc
        LD_LOCAL         R0, 128   # 0x31e0
        LD_LOCAL         R1, 132   # 0x31e4
        ST_GLOBAL_IDX    R14, R0, R1, 0, 0   # 0x31e8
        C_CHWIDTH        R14, 0   # 0x31ec
        LD_LOCAL         R6, 108   # 0x31ee
        LD_LOCAL         R4, 100   # 0x31f2
        LD_LOCAL         R5, 120   # 0x31f6
        LD_LOCAL         R14, 124   # 0x31fa
L31fe:  C_CHWIDTH        R12, 1   # 0x31fe
        SHLI             R0, R14, 16   # 0x3200
        SHRI             R1, R5, 16   # 0x3204
        OR               R1, R0, R1, R0   # 0x3208
        MOVI             R0, 65535   # 0x320c
        C_AND            R5, R0   # 0x3210
        C_CHWIDTH        R0, 1   # 0x3212
        LD_GLOBAL_IDX    R12, R1, R5, 0, 0   # 0x3214
        AND              R0, R12, R2, R12   # 0x3218
        C_CHWIDTH        R0, 0   # 0x321c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x321e
        BRA_PRED         4, L32f2   # 0x3222
        C_CHWIDTH        R3, 0   # 0x3226
        ST_LOCAL         R5, 128   # 0x3228
        ST_LOCAL         R1, 124   # 0x322c
        ST_LOCAL         R3, 120   # 0x3230
        MOVI             R0, 7   # 0x3234
        C_CHWIDTH        R0, 1   # 0x3238
        AND              R0, R12, R0, R12   # 0x323a
        CHWIDTH_MULTI    4097, 0   # 0x323e
        SHRI             R1, R12, 3   # 0x3242
        C_CHWIDTH        R1, 1   # 0x3246
        MOVI             R2, 15   # 0x3248
        AND              R1, R1, R2, R1   # 0x324c
        C_CHWIDTH        R1, 0   # 0x3250
        MULI             R1, R1, 17   # 0x3252
        C_MOV            R3, R1   # 0x3256
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x3258
        BRA_PRED         0, L32fe   # 0x325c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3260
        C_MOV            R5, R12   # 0x3264
        BRA_PRED         0, L334a   # 0x3266
        CHWIDTH_MULTI    48, 1   # 0x326a
        ST_LOCAL         R7, 116   # 0x326e
        MOVI             R0, 34   # 0x3272
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x3276
        C_CHWIDTH        R0, 1   # 0x327a
        MOVI             R6, 34   # 0x327c
        MOV_P            R6, 0, R3, R3, R3   # 0x3280
        C_MOV            R2, R13   # 0x3284
        LD_LOCAL         R13, 112   # 0x3286
        LD_GLOBAL_IDX    R0, R2, R13, 0, 96   # 0x328a
        C_CHWIDTH        R0, 0   # 0x328e
        LD_GLOBAL_IDX    R1, R2, R13, 0, 40   # 0x3290
        LD_GLOBAL_IDX    R5, R2, R13, 0, 2   # 0x3294
        C_CHWIDTH        R5, 0   # 0x3298
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x329a
        C_CHWIDTH        R4, 0   # 0x329e
        LD_GLOBAL_IDX    R3, R2, R13, 0, 32   # 0x32a0
        LD_GLOBAL_IDX    R2, R2, R13, 0, 36   # 0x32a4
        ST_GLOBAL        R0, R15, -4   # 0x32a8
        SHLI             R0, R2, 16   # 0x32ac
        SHRI             R2, R3, 16   # 0x32b0
        OR               R2, R0, R2, R0   # 0x32b4
        MOVI             R0, 65535   # 0x32b8
        C_AND            R3, R0   # 0x32bc
        CALL             R14, 126882   # 0x32be
        C_CHWIDTH        R0, 1   # 0x32c2
        MOVI             R15, 2   # 0x32c4
        LD_GLOBAL        R15, R15, 24   # 0x32c8
        SRD              R3, 2   # 0x32cc
        C_ADD            R15, R3   # 0x32ce
        C_MOV            R2, R13   # 0x32d0
        LD_LOCAL         R13, 136   # 0x32d2
        LD_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x32d6
        C_CHWIDTH        R0, 0   # 0x32da
        C_MOV            R5, R1   # 0x32dc
        SETP_NE_NPI      P0, R0, R0, 0   # 0x32de
        BRA_PRED         0, L3346   # 0x32e2
        C_MOV            R0, R5   # 0x32e6
        C_CHWIDTH        R0, 1   # 0x32e8
        ST_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x32ea
        C_CHWIDTH        R0, 0   # 0x32ee
        C_BRA            L3346   # 0x32f0
L32f2:  MOVI             R0, 127   # 0x32f2
        C_CHWIDTH        R0, 1   # 0x32f6
        AND              R0, R12, R0, R12   # 0x32f8
        C_BRA            L33a8   # 0x32fc
L32fe:  C_CHWIDTH        R4, 1   # 0x32fe
        ST_LOCAL         R7, 116   # 0x3300
        C_MOV            R1, R13   # 0x3304
        LD_LOCAL         R13, 112   # 0x3306
        LD_GLOBAL_IDX    R4, R1, R13, 0, 96   # 0x330a
        C_CHWIDTH        R4, 0   # 0x330e
        ADDI             R2, R13, 64   # 0x3310
        CALL             R14, 128194   # 0x3314
        C_CHWIDTH        R0, 1   # 0x3318
        MOVI             R15, 2   # 0x331a
        LD_GLOBAL        R15, R15, 24   # 0x331e
        SRD              R3, 2   # 0x3322
        C_ADD            R15, R3   # 0x3324
        C_MOV            R2, R13   # 0x3326
        LD_LOCAL         R13, 136   # 0x3328
        LD_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x332c
        C_CHWIDTH        R0, 0   # 0x3330
        C_MOV            R5, R1   # 0x3332
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3334
        BRA_PRED         0, L3346   # 0x3338
        C_MOV            R0, R5   # 0x333c
        C_CHWIDTH        R0, 1   # 0x333e
        ST_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x3340
        C_CHWIDTH        R0, 0   # 0x3344
L3346:  LD_LOCAL         R7, 116   # 0x3346
L334a:  C_CHWIDTH        R2, 1   # 0x334a
        LD_LOCAL         R6, 112   # 0x334c
        LD_GLOBAL_IDX    R2, R13, R6, 0, 96   # 0x3350
        C_CHWIDTH        R2, 0   # 0x3354
        C_MOV            R1, R5   # 0x3356
        CALL             R14, 129678   # 0x3358
        CHWIDTH_MULTI    16386, 1   # 0x335c
        MOVI             R15, 2   # 0x3360
        LD_GLOBAL        R15, R15, 24   # 0x3364
        SRD              R3, 2   # 0x3368
        C_ADD            R15, R3   # 0x336a
        ST_GLOBAL_IDX    R1, R13, R6, 0, 96   # 0x336c
        C_CHWIDTH        R1, 0   # 0x3370
        MOVI             R0, 127   # 0x3372
        C_CHWIDTH        R0, 1   # 0x3376
        AND              R0, R5, R0, R5   # 0x3378
        MOVI             R1, 65280   # 0x337c
        AND              R14, R12, R1, R12   # 0x3380
        OR               R14, R14, R0, R14   # 0x3384
        MOVI             R1, 128   # 0x3388
        OR               R14, R14, R1, R14   # 0x338c
        LD_LOCAL         R1, 124   # 0x3390
        LD_LOCAL         R2, 128   # 0x3394
        ST_GLOBAL_IDX    R14, R1, R2, 0, 0   # 0x3398
        LD_LOCAL         R6, 108   # 0x339c
        LD_LOCAL         R4, 100   # 0x33a0
        LD_LOCAL         R3, 120   # 0x33a4
L33a8:  CHWIDTH_MULTI    4105, 0   # 0x33a8
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x33ac
        MOVI             R12, 65535   # 0x33b0
        BRA_PRED         4, L33e4   # 0x33b4
        LD_GLOBAL_IDX    R1, R7, R6, 0, 0   # 0x33b8
        LD_GLOBAL_IDX    R0, R7, R6, 0, 4   # 0x33bc
        SHLI             R0, R0, 16   # 0x33c0
        SHRI             R2, R1, 16   # 0x33c4
        C_OR             R0, R2   # 0x33c8
        AND              R2, R1, R12, R1   # 0x33ca
L33ce:  LD_LOCAL         R1, 104   # 0x33ce
        ADDI             R1, R1, -1   # 0x33d2
        ST_LOCAL         R1, 104   # 0x33d6
        C_MOV            R1, R9   # 0x33da
        C_MOV            R3, R8   # 0x33dc
        C_MOV            R4, R7   # 0x33de
        C_MOV            R5, R6   # 0x33e0
        C_BRA            L340a   # 0x33e2
L33e4:  LD_GLOBAL_IDX    R0, R9, R8, 0, 0   # 0x33e4
        LD_GLOBAL_IDX    R1, R9, R8, 0, 4   # 0x33e8
        SHLI             R1, R1, 16   # 0x33ec
        SHRI             R2, R0, 16   # 0x33f0
        C_OR             R1, R2   # 0x33f4
        AND              R3, R0, R12, R0   # 0x33f6
        ADDI             R4, R4, -1   # 0x33fa
        ST_LOCAL         R4, 100   # 0x33fe
        C_MOV            R0, R7   # 0x3402
        C_MOV            R2, R6   # 0x3404
        C_MOV            R4, R9   # 0x3406
        C_MOV            R5, R8   # 0x3408
L340a:  C_CHWIDTH        R14, 0   # 0x340a
        SHLI             R6, R10, 16   # 0x340c
        AND              R7, R6, R11, R6   # 0x3410
        ADD              R14, R6, R11, R6   # 0x3414
        C_OR             R6, R11   # 0x3418
        C_ANDN           R6, R14   # 0x341a
        OR               R6, R7, R6, R7   # 0x341c
        SHRI             R6, R6, 31   # 0x3420
        SHRI             R7, R10, 16   # 0x3424
        ADD              R6, R7, R6, R7   # 0x3428
        OR               R6, R14, R6, R14   # 0x342c
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x3430
        BRA_PRED         0, L2f70   # 0x3434
        SHLI             R6, R4, 16   # 0x3438
        ADD              R7, R6, R5, R6   # 0x343c
        ST_GLOBAL_IDX    R7, R10, R11, 0, 0   # 0x3440
        OR               R14, R6, R5, R6   # 0x3444
        ANDN             R7, R14, R7, R14   # 0x3448
        C_AND            R6, R5   # 0x344c
        C_OR             R6, R7   # 0x344e
        SHRI             R6, R6, 31   # 0x3450
        SHRI             R7, R4, 16   # 0x3454
        ADD              R6, R7, R6, R7   # 0x3458
        ST_GLOBAL_IDX    R6, R10, R11, 0, 4   # 0x345c
        BRA              L2f78   # 0x3460
L3464:  CHWIDTH_MULTI    64, 0   # 0x3464
        C_MOV            R9, R1   # 0x3468
L346a:  CHWIDTH_MULTI    16512, 0   # 0x346a
        LD_GLOBAL_IDX    R1, R8, R9, 0, 0   # 0x346e
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x3472
        SHLI             R0, R0, 16   # 0x3476
        SHRI             R2, R1, 16   # 0x347a
        OR               R3, R0, R2, R0   # 0x347e
        MOVI             R0, 65535   # 0x3482
        AND              R4, R1, R0, R1   # 0x3486
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x348a
        SHLI             R1, R1, 16   # 0x348e
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x3492
        SHRI             R5, R2, 16   # 0x3496
        OR               R6, R1, R5, R1   # 0x349a
        C_CHWIDTH        R5, 1   # 0x349e
        AND              R7, R2, R0, R2   # 0x34a0
        LD_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x34a4
        C_CHWIDTH        R5, 0   # 0x34a8
        LD_GLOBAL_IDX    R2, R6, R7, 0, 8   # 0x34aa
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x34ae
        ST_GLOBAL_IDX    R2, R3, R4, 0, 8   # 0x34b2
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x34b6
        ST_GLOBAL_IDX    R5, R3, R4, 0, 12   # 0x34ba
        AND              R5, R2, R0, R2   # 0x34be
        ST_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x34c2
        C_CHWIDTH        R5, 1   # 0x34c6
        ST_GLOBAL_IDX    R1, R6, R7, 0, 8   # 0x34c8
        LD_GLOBAL_IDX    R5, R6, R7, 0, 4   # 0x34cc
        C_CHWIDTH        R5, 0   # 0x34d0
        LD_GLOBAL_IDX    R14, R6, R7, 0, 0   # 0x34d2
        ST_GLOBAL_IDX    R14, R3, R4, 0, 0   # 0x34d6
        ST_GLOBAL_IDX    R5, R3, R4, 0, 4   # 0x34da
        LD_LOCAL         R10, 168   # 0x34de
        C_MOV            R4, R10   # 0x34e2
        C_CHWIDTH        R4, 1   # 0x34e4
        C_MOV            R5, R10   # 0x34e6
        C_CHWIDTH        R5, 1   # 0x34e8
        C_MOV            R11, R10   # 0x34ea
        C_CHWIDTH        R11, 1   # 0x34ec
        CVT_SEXT         R3, R4, R5, R11   # 0x34ee
        CHWIDTH_MULTI    2096, 0   # 0x34f2
        MOVI48           R4, 4294967295   # 0x34f6
        SETP_LT_NP       P0, R3, R4, R3   # 0x34fc
        MOVI             R3, 0   # 0x3500
        ST_GLOBAL_IDX    R3, R6, R7, 0, 4   # 0x3504
        ST_GLOBAL_IDX    R3, R6, R7, 0, 0   # 0x3508
        C_MOV            R13, R8   # 0x350c
        ST_LOCAL         R9, 140   # 0x350e
        BRA_PRED         4, L3562   # 0x3512
L3516:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x3516
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x351a
        SHLI             R4, R4, 16   # 0x351e
        SHRI             R5, R3, 16   # 0x3522
        C_OR             R4, R5   # 0x3526
        C_AND            R3, R0   # 0x3528
        C_CHWIDTH        R3, 1   # 0x352a
        LD_GLOBAL_IDX    R3, R4, R3, 0, 2   # 0x352c
        C_CHWIDTH        R3, 0   # 0x3530
        SETP_EQ_NP       P0, R3, R3, R10   # 0x3532
        BRA_PRED         0, L35ba   # 0x3536
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x353a
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x353e
        SHRI             R5, R4, 16   # 0x3542
        SHLI             R14, R3, 16   # 0x3546
        OR               R8, R14, R5, R14   # 0x354a
        C_AND            R3, R0   # 0x354e
        OR               R3, R4, R3, R4   # 0x3550
        AND              R9, R4, R0, R4   # 0x3554
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x3558
        BRA_PRED         4, L3516   # 0x355c
        C_BRA            L35b2   # 0x3560
L3562:  LD_LOCAL         R10, 172   # 0x3562
L3566:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x3566
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x356a
        SHLI             R4, R4, 16   # 0x356e
        SHRI             R5, R3, 16   # 0x3572
        C_OR             R4, R5   # 0x3576
        C_AND            R3, R0   # 0x3578
        C_CHWIDTH        R3, 2   # 0x357a
        LD_GLOBAL_IDX    R3, R4, R3, 0, 0   # 0x357c
        C_CHWIDTH        R3, 0   # 0x3580
        C_AND            R3, R0   # 0x3582
        SETP_EQ_NP       P0, R3, R3, R10   # 0x3584
        BRA_PRED         0, L35ba   # 0x3588
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x358c
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x3590
        SHRI             R5, R4, 16   # 0x3594
        SHLI             R14, R3, 16   # 0x3598
        OR               R8, R14, R5, R14   # 0x359c
        C_AND            R3, R0   # 0x35a0
        OR               R3, R4, R3, R4   # 0x35a2
        AND              R9, R4, R0, R4   # 0x35a6
        SETP_NE_NPI      P0, R3, R3, 0   # 0x35aa
        BRA_PRED         0, L3566   # 0x35ae
L35b2:  MOVI             R8, 0   # 0x35b2
        MOVI             R9, 0   # 0x35b6
L35ba:  SHLI             R2, R2, 16   # 0x35ba
        SHRI             R3, R1, 16   # 0x35be
        SHLI             R4, R8, 16   # 0x35c2
        AND              R5, R4, R9, R4   # 0x35c6
        ADD              R14, R4, R9, R4   # 0x35ca
        C_OR             R4, R9   # 0x35ce
        C_ANDN           R4, R14   # 0x35d0
        OR               R4, R5, R4, R5   # 0x35d2
        SHRI             R4, R4, 31   # 0x35d6
        SHRI             R5, R8, 16   # 0x35da
        ADD              R4, R5, R4, R5   # 0x35de
        OR               R4, R14, R4, R14   # 0x35e2
        SETP_NE_NPI      P0, R4, R4, 0   # 0x35e6
        BRA_PRED         0, L3610   # 0x35ea
        C_MOV            R5, R13   # 0x35ee
        LD_LOCAL         R14, 140   # 0x35f0
        LD_GLOBAL_IDX    R4, R5, R14, 0, 0   # 0x35f4
        LD_GLOBAL_IDX    R5, R5, R14, 0, 4   # 0x35f8
        SHLI             R5, R5, 16   # 0x35fc
        SHRI             R14, R4, 16   # 0x3600
        OR               R8, R5, R14, R5   # 0x3604
        MOVI             R5, 65535   # 0x3608
        AND              R9, R4, R5, R4   # 0x360c
L3610:  OR               R10, R2, R3, R2   # 0x3610
        AND              R11, R1, R0, R1   # 0x3614
        SHLI             R0, R8, 16   # 0x3618
        AND              R1, R0, R9, R0   # 0x361c
        ADD              R2, R0, R9, R0   # 0x3620
        C_OR             R0, R9   # 0x3624
        C_ANDN           R0, R2   # 0x3626
        OR               R0, R1, R0, R1   # 0x3628
        SHRI             R0, R0, 31   # 0x362c
        SHRI             R1, R8, 16   # 0x3630
        ADD              R0, R1, R0, R1   # 0x3634
        OR               R0, R2, R0, R2   # 0x3638
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x363c
        BRA_PRED         0, L36aa   # 0x3640
        C_CHWIDTH        R5, 1   # 0x3644
        C_MOV            R1, R13   # 0x3646
        LD_LOCAL         R2, 140   # 0x3648
        LD_GLOBAL_IDX    R0, R1, R2, 0, 8   # 0x364c
        LD_GLOBAL_IDX    R1, R1, R2, 0, 12   # 0x3650
        SHLI             R1, R1, 16   # 0x3654
        SHRI             R2, R0, 16   # 0x3658
        C_OR             R1, R2   # 0x365c
        MOVI             R12, 65535   # 0x365e
        C_AND            R0, R12   # 0x3662
        LD_GLOBAL_IDX    R5, R1, R0, 0, 0   # 0x3664
        LD_LOCAL         R2, 160   # 0x3668
L366c:  C_CHWIDTH        R5, 0   # 0x366c
        C_MOV            R1, R5   # 0x366e
        CALL             R14, 127471   # 0x3670
        MOVI             R15, 2   # 0x3674
        LD_GLOBAL        R15, R15, 24   # 0x3678
        SRD              R3, 2   # 0x367c
        C_ADD            R15, R3   # 0x367e
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x3680
        LD_GLOBAL_IDX    R2, R8, R9, 0, 0   # 0x3684
        SHRI             R3, R2, 16   # 0x3688
        SHLI             R4, R0, 16   # 0x368c
        OR               R8, R4, R3, R4   # 0x3690
        C_AND            R0, R12   # 0x3694
        OR               R0, R2, R0, R2   # 0x3696
        AND              R9, R2, R12, R2   # 0x369a
        C_MOV            R2, R1   # 0x369e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x36a0
        BRA_PRED         0, L366c   # 0x36a4
        C_BRA            L36ae   # 0x36a8
L36aa:  LD_LOCAL         R2, 160   # 0x36aa
L36ae:  C_CHWIDTH        R3, 1   # 0x36ae
        ST_LOCAL         R2, 160   # 0x36b0
        LD_LOCAL         R5, 140   # 0x36b4
        LD_GLOBAL_IDX    R1, R13, R5, 0, 0   # 0x36b8
        LD_GLOBAL_IDX    R0, R13, R5, 0, 4   # 0x36bc
        SHLI             R0, R0, 16   # 0x36c0
        SHRI             R2, R1, 16   # 0x36c4
        OR               R2, R0, R2, R0   # 0x36c8
        MOVI             R0, 65535   # 0x36cc
        C_AND            R1, R0   # 0x36d0
        LD_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x36d2
        C_CHWIDTH        R3, 0   # 0x36d6
        LD_GLOBAL_IDX    R4, R2, R1, 0, 8   # 0x36d8
        ST_GLOBAL_IDX    R4, R6, R7, 0, 8   # 0x36dc
        ST_GLOBAL_IDX    R3, R6, R7, 0, 12   # 0x36e0
        SHRI             R3, R10, 16   # 0x36e4
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x36e8
        SHLI             R3, R10, 16   # 0x36ec
        C_OR             R3, R11   # 0x36f0
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x36f2
        C_CHWIDTH        R3, 1   # 0x36f6
        LD_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x36f8
        C_CHWIDTH        R3, 0   # 0x36fc
        LD_GLOBAL_IDX    R4, R2, R1, 0, 0   # 0x36fe
        ST_GLOBAL_IDX    R4, R6, R7, 0, 0   # 0x3702
        ST_GLOBAL_IDX    R3, R6, R7, 0, 4   # 0x3706
        SHLI             R3, R6, 16   # 0x370a
        C_OR             R3, R7   # 0x370e
        SHRI             R4, R6, 16   # 0x3710
        ST_GLOBAL_IDX    R4, R2, R1, 0, 4   # 0x3714
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3718
        C_MOV            R1, R13   # 0x371c
        C_MOV            R13, R5   # 0x371e
        MOVI             R9, 1   # 0x3720
        MOVI             R3, 0   # 0x3724
        C_BRA            L374c   # 0x3728
L372a:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x372a
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x372e
        C_SHLI           R9, 1   # 0x3732
        LD_LOCAL         R1, 108   # 0x3734
        SETP_NE_NPI      P0, R1, R1, 0   # 0x3738
        LD_LOCAL         R4, 100   # 0x373c
        C_MOV            R1, R4   # 0x3740
        LD_LOCAL         R5, 104   # 0x3742
        C_MOV            R13, R5   # 0x3746
        BRA_PRED         4, L3998   # 0x3748
L374c:  MOVI             R6, 0   # 0x374c
        MOVI             R2, 0   # 0x3750
        MOVI             R4, 0   # 0x3754
        MOVI             R5, 0   # 0x3758
        ST_LOCAL         R5, 100   # 0x375c
        ST_LOCAL         R5, 104   # 0x3760
        ST_LOCAL         R9, 116   # 0x3764
        C_BRA            L377a   # 0x3768
L376a:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x376a
        LD_LOCAL         R9, 116   # 0x376e
        LD_LOCAL         R6, 112   # 0x3772
        BRA_PRED         0, L372a   # 0x3776
L377a:  ST_LOCAL         R6, 108   # 0x377a
        SETP_LT_NPI      P0, R5, R9, 1   # 0x377e
        BRA_PRED         0, L37c2   # 0x3782
        MOVI             R5, 0   # 0x3786
        C_MOV            R6, R1   # 0x378a
        C_MOV            R7, R13   # 0x378c
L378e:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x378e
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x3792
        AND              R6, R14, R0, R14   # 0x3796
        OR               R6, R7, R6, R7   # 0x379a
        SETP_NE_NPI      P0, R6, R6, 0   # 0x379e
        BRA_PRED         4, L37cc   # 0x37a2
        SHRI             R6, R7, 16   # 0x37a6
        SHLI             R14, R14, 16   # 0x37aa
        OR               R6, R14, R6, R14   # 0x37ae
        C_AND            R7, R0   # 0x37b2
        C_ADDI           R5, 1   # 0x37b4
        SETP_EQ_NP       P0, R14, R9, R5   # 0x37b6
        BRA_PRED         4, L378e   # 0x37ba
        C_MOV            R8, R9   # 0x37be
        C_BRA            L37d8   # 0x37c0
L37c2:  MOVI             R8, 0   # 0x37c2
        C_MOV            R6, R1   # 0x37c6
        C_MOV            R7, R13   # 0x37c8
        C_BRA            L37d8   # 0x37ca
L37cc:  MOVI             R6, 0   # 0x37cc
        ADDI             R8, R5, 1   # 0x37d0
        MOVI             R7, 0   # 0x37d4
L37d8:  LD_LOCAL         R5, 108   # 0x37d8
        C_ADDI           R5, 1   # 0x37dc
        ST_LOCAL         R5, 112   # 0x37de
        C_MOV            R5, R1   # 0x37e2
        C_MOV            R14, R13   # 0x37e4
        C_MOV            R1, R6   # 0x37e6
        C_MOV            R13, R7   # 0x37e8
        C_BRA            L37fe   # 0x37ea
L37ec:  ST_LOCAL         R6, 100   # 0x37ec
        ST_LOCAL         R7, 104   # 0x37f0
L37f4:  C_MOV            R5, R11   # 0x37f4
        C_MOV            R14, R10   # 0x37f6
        C_MOV            R1, R12   # 0x37f8
        C_MOV            R2, R6   # 0x37fa
        C_MOV            R4, R7   # 0x37fc
L37fe:  SETP_LT_NP       P0, R6, R3, R8   # 0x37fe
        BRA_PRED         0, L383a   # 0x3802
        SHLI             R6, R1, 16   # 0x3806
        AND              R7, R6, R13, R6   # 0x380a
        ADD              R10, R6, R13, R6   # 0x380e
        C_OR             R6, R13   # 0x3812
        C_ANDN           R6, R10   # 0x3814
        OR               R6, R7, R6, R7   # 0x3816
        SHRI             R6, R6, 31   # 0x381a
        SHRI             R7, R1, 16   # 0x381e
        ADD              R6, R7, R6, R7   # 0x3822
        OR               R6, R10, R6, R10   # 0x3826
        SETP_LT_NPI      P0, R7, R9, 1   # 0x382a
        BRA_PRED         0, L376a   # 0x382e
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x3832
        BRA_PRED         0, L376a   # 0x3836
L383a:  SETP_NE_NPI      P0, R6, R8, 0   # 0x383a
        BRA_PRED         4, L391a   # 0x383e
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x3842
        BRA_PRED         0, L38f2   # 0x3846
        SHLI             R6, R1, 16   # 0x384a
        AND              R7, R6, R13, R6   # 0x384e
        ADD              R10, R6, R13, R6   # 0x3852
        C_OR             R6, R13   # 0x3856
        C_ANDN           R6, R10   # 0x3858
        OR               R6, R7, R6, R7   # 0x385a
        SHRI             R6, R6, 31   # 0x385e
        SHRI             R7, R1, 16   # 0x3862
        ADD              R6, R7, R6, R7   # 0x3866
        OR               R6, R10, R6, R10   # 0x386a
        SETP_NE_NPI      P0, R6, R6, 0   # 0x386e
        BRA_PRED         4, L38f2   # 0x3872
        C_CHWIDTH        R12, 2   # 0x3876
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x3878
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x387c
        SHLI             R7, R7, 16   # 0x3880
        SHRI             R10, R6, 16   # 0x3884
        C_OR             R7, R10   # 0x3888
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x388a
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x388e
        C_AND            R6, R0   # 0x3892
        LD_GLOBAL_IDX    R12, R7, R6, 0, 1   # 0x3894
        ST_GLOBAL_IDX    R12, R7, R6, 0, 0   # 0x3898
        C_CHWIDTH        R7, 1   # 0x389c
        C_CHWIDTH        R12, 0   # 0x389e
        SHLI             R11, R11, 16   # 0x38a0
        SHRI             R12, R10, 16   # 0x38a4
        C_OR             R11, R12   # 0x38a8
        C_CHWIDTH        R12, 2   # 0x38aa
        C_AND            R10, R0   # 0x38ac
        LD_GLOBAL_IDX    R12, R11, R10, 0, 1   # 0x38ae
        ST_GLOBAL_IDX    R12, R11, R10, 0, 0   # 0x38b2
        LD_GLOBAL_IDX    R7, R7, R6, 0, 2   # 0x38b6
        C_CHWIDTH        R6, 1   # 0x38ba
        LD_GLOBAL_IDX    R6, R11, R10, 0, 2   # 0x38bc
        CVT_SEXT         R10, R6, R6, R6   # 0x38c0
        C_CHWIDTH        R6, 0   # 0x38c4
        CVT_SEXT         R6, R7, R7, R7   # 0x38c6
        SETP_LT_NP       P0, R6, R10, R6   # 0x38ca
        BRA_PRED         4, L38f2   # 0x38ce
        CHWIDTH_MULTI    4224, 0   # 0x38d2
        LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x38d6
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x38da
        SHLI             R7, R7, 16   # 0x38de
        SHRI             R10, R6, 16   # 0x38e2
        OR               R12, R7, R10, R7   # 0x38e6
        C_MOV            R7, R13   # 0x38ea
        AND              R13, R6, R0, R6   # 0x38ec
        C_BRA            L3938   # 0x38f0
L38f2:  CHWIDTH_MULTI    4224, 0   # 0x38f2
        LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x38f6
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x38fa
        SHLI             R7, R7, 16   # 0x38fe
        SHRI             R10, R6, 16   # 0x3902
        OR               R11, R7, R10, R7   # 0x3906
        AND              R10, R6, R0, R6   # 0x390a
        ADDI             R8, R8, -1   # 0x390e
        C_MOV            R12, R1   # 0x3912
        C_MOV            R6, R5   # 0x3914
        C_MOV            R7, R14   # 0x3916
        C_BRA            L3942   # 0x3918
L391a:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x391a
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x391e
        SHLI             R7, R7, 16   # 0x3922
        SHRI             R8, R6, 16   # 0x3926
        OR               R12, R7, R8, R7   # 0x392a
        C_MOV            R7, R13   # 0x392e
        AND              R13, R6, R0, R6   # 0x3930
        MOVI             R8, 0   # 0x3934
L3938:  ADDI             R9, R9, -1   # 0x3938
        C_MOV            R11, R5   # 0x393c
        C_MOV            R10, R14   # 0x393e
        C_MOV            R6, R1   # 0x3940
L3942:  SHLI             R5, R2, 16   # 0x3942
        AND              R14, R5, R4, R5   # 0x3946
        ADD              R1, R5, R4, R5   # 0x394a
        C_OR             R5, R4   # 0x394e
        C_ANDN           R5, R1   # 0x3950
        OR               R5, R14, R5, R14   # 0x3952
        SHRI             R5, R5, 31   # 0x3956
        SHRI             R14, R2, 16   # 0x395a
        ADD              R5, R14, R5, R14   # 0x395e
        C_OR             R1, R5   # 0x3962
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x3964
        BRA_PRED         0, L37ec   # 0x3968
        SHLI             R1, R6, 16   # 0x396c
        ADD              R5, R1, R7, R1   # 0x3970
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x3974
        OR               R14, R1, R7, R1   # 0x3978
        ANDN             R5, R14, R5, R14   # 0x397c
        C_AND            R1, R7   # 0x3980
        C_OR             R1, R5   # 0x3982
        SHRI             R1, R1, 31   # 0x3984
        SHRI             R5, R6, 16   # 0x3988
        ADD              R1, R5, R1, R5   # 0x398c
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x3990
        BRA              L37f4   # 0x3994
L3998:  LD_GLOBAL_IDX    R1, R4, R5, 0, 4   # 0x3998
        LD_GLOBAL_IDX    R0, R4, R5, 0, 0   # 0x399c
        MOVI             R6, 65535   # 0x39a0
        AND              R2, R1, R6, R1   # 0x39a4
        OR               R2, R0, R2, R0   # 0x39a8
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x39ac
        BRA_PRED         0, L3a20   # 0x39b0
        SHRI             R2, R0, 16   # 0x39b4
        SHLI             R1, R1, 16   # 0x39b8
        OR               R7, R1, R2, R1   # 0x39bc
        AND              R8, R0, R6, R0   # 0x39c0
        LD_GLOBAL_IDX    R0, R4, R5, 0, 8   # 0x39c4
        LD_GLOBAL_IDX    R1, R4, R5, 0, 12   # 0x39c8
        C_CHWIDTH        R5, 1   # 0x39cc
        SHLI             R1, R1, 16   # 0x39ce
        SHRI             R2, R0, 16   # 0x39d2
        C_OR             R1, R2   # 0x39d6
        C_AND            R0, R6   # 0x39d8
        LD_GLOBAL_IDX    R5, R1, R0, 0, 0   # 0x39da
        LD_LOCAL         R2, 160   # 0x39de
L39e2:  C_CHWIDTH        R5, 0   # 0x39e2
        C_MOV            R1, R5   # 0x39e4
        CALL             R14, 127028   # 0x39e6
        MOVI             R15, 2   # 0x39ea
        LD_GLOBAL        R15, R15, 24   # 0x39ee
        SRD              R3, 2   # 0x39f2
        C_ADD            R15, R3   # 0x39f4
        LD_GLOBAL_IDX    R0, R7, R8, 0, 4   # 0x39f6
        LD_GLOBAL_IDX    R2, R7, R8, 0, 0   # 0x39fa
        SHRI             R3, R2, 16   # 0x39fe
        SHLI             R4, R0, 16   # 0x3a02
        OR               R7, R4, R3, R4   # 0x3a06
        C_AND            R0, R6   # 0x3a0a
        OR               R0, R2, R0, R2   # 0x3a0c
        AND              R8, R2, R6, R2   # 0x3a10
        C_MOV            R2, R1   # 0x3a14
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3a16
        BRA_PRED         0, L39e2   # 0x3a1a
        C_BRA            L3a24   # 0x3a1e
L3a20:  LD_LOCAL         R2, 160   # 0x3a20
L3a24:  C_MOV            R1, R2   # 0x3a24
        LD_LOCAL         R14, 164   # 0x3a26
        LD_LOCAL         R13, 196   # 0x3a2a
        LD_LOCAL         R12, 192   # 0x3a2e
        LD_LOCAL         R11, 188   # 0x3a32
        LD_LOCAL         R10, 184   # 0x3a36
        LD_LOCAL         R9, 180   # 0x3a3a
        LD_LOCAL         R8, 176   # 0x3a3e
        C_RET            224   # 0x3a42
        MOVI             R15, 2   # 0x3a44
        LD_GLOBAL        R15, R15, 24   # 0x3a48
        SRD              R14, 2   # 0x3a4c
        C_ADD            R15, R14   # 0x3a4e
        MOVI             R8, 2   # 0x3a50
        LD_GLOBAL        R0, R8, 36   # 0x3a54
        MOVI             R1, 2000   # 0x3a58
        SRD              R2, 0   # 0x3a5c
        ST_LOCAL         R2, 200   # 0x3a5e
        MADLO            R3, R2, R1, R0   # 0x3a62
        ADDI             R4, R3, 666   # 0x3a66
        ST_LOCAL         R4, 204   # 0x3a6a
        LD_GLOBAL        R0, R8, 32   # 0x3a6e
        SHLI             R1, R0, 16   # 0x3a72
        C_MOV            R9, R0   # 0x3a76
        ADD              R2, R1, R4, R1   # 0x3a78
        OR               R0, R1, R4, R1   # 0x3a7c
        C_ANDN           R0, R2   # 0x3a80
        AND              R4, R1, R4, R1   # 0x3a82
        OR               R0, R4, R0, R4   # 0x3a86
        ADDI             R4, R3, 1332   # 0x3a8a
        ADD              R5, R1, R4, R1   # 0x3a8e
        OR               R6, R1, R4, R1   # 0x3a92
        C_ANDN           R6, R5   # 0x3a96
        AND              R4, R1, R4, R1   # 0x3a98
        C_OR             R4, R6   # 0x3a9c
        ADD              R6, R1, R3, R1   # 0x3a9e
        OR               R7, R1, R3, R1   # 0x3aa2
        C_ANDN           R7, R6   # 0x3aa6
        C_AND            R1, R3   # 0x3aa8
        C_OR             R1, R7   # 0x3aaa
        LD_GLOBAL        R7, R8, 48   # 0x3aac
        MOVI             R8, 7   # 0x3ab0
        ST_GLOBAL        R8, R15, -100   # 0x3ab4
        ST_GLOBAL        R7, R15, -104   # 0x3ab8
        MOVI             R7, 102   # 0x3abc
        C_MOV            R8, R7   # 0x3ac0
        C_CHWIDTH        R8, 1   # 0x3ac2
        ST_GLOBAL        R8, R15, -144   # 0x3ac4
        C_CHWIDTH        R8, 0   # 0x3ac8
        ST_GLOBAL        R6, R15, -132   # 0x3aca
        ST_GLOBAL        R6, R15, -140   # 0x3ace
        ST_GLOBAL        R5, R15, -116   # 0x3ad2
        ST_GLOBAL        R2, R15, -124   # 0x3ad6
        SHRI             R1, R1, 31   # 0x3ada
        C_MOV            R2, R9   # 0x3ade
        ST_LOCAL         R2, 208   # 0x3ae0
        SHRI             R5, R2, 16   # 0x3ae4
        ADD              R1, R5, R1, R5   # 0x3ae8
        ST_GLOBAL        R1, R15, -128   # 0x3aec
        ST_GLOBAL        R1, R15, -136   # 0x3af0
        SHRI             R1, R4, 31   # 0x3af4
        ADD              R1, R5, R1, R5   # 0x3af8
        ST_GLOBAL        R1, R15, -112   # 0x3afc
        SHRI             R0, R0, 31   # 0x3b00
        ADD              R0, R5, R0, R5   # 0x3b04
        ST_GLOBAL        R0, R15, -120   # 0x3b08
        MOVI             R0, 0   # 0x3b0c
        ST_GLOBAL        R0, R15, -148   # 0x3b10
        MOVI             R0, 666   # 0x3b14
        ST_GLOBAL        R0, R15, -108   # 0x3b18
        MOVI             R1, 666   # 0x3b1c
        MOVI             R4, 0   # 0x3b20
        CALL             R14, 123500   # 0x3b24
        MOVI             R15, 2   # 0x3b28
        LD_GLOBAL        R15, R15, 24   # 0x3b2c
        SRD              R3, 2   # 0x3b30
        C_ADD            R15, R3   # 0x3b32
        SHLI             R0, R1, 16   # 0x3b34
        ADD              R3, R0, R2, R0   # 0x3b38
        OR               R4, R0, R2, R0   # 0x3b3c
        C_ANDN           R4, R3   # 0x3b40
        ST_GLOBAL        R3, R15, -92   # 0x3b42
        C_AND            R0, R2   # 0x3b46
        C_OR             R0, R4   # 0x3b48
        SHRI             R0, R0, 31   # 0x3b4a
        SHRI             R1, R1, 16   # 0x3b4e
        ADD              R0, R1, R0, R1   # 0x3b52
        ST_GLOBAL        R0, R15, -88   # 0x3b56
        MOVI             R0, 65388   # 0x3b5a
        ADDI             R6, R0, 64   # 0x3b5e
        ADDI             R5, R15, -1   # 0x3b62
        MOVI             R1, 666   # 0x3b66
        LD_LOCAL         R2, 208   # 0x3b6a
        LD_LOCAL         R3, 204   # 0x3b6e
        MOVI             R4, 0   # 0x3b72
        CALL             R14, 124605   # 0x3b76
        C_CHWIDTH        R2, 1   # 0x3b7a
        MOVI             R15, 2   # 0x3b7c
        LD_GLOBAL        R15, R15, 24   # 0x3b80
        SRD              R3, 2   # 0x3b84
        C_ADD            R15, R3   # 0x3b86
        MOVI             R0, 65535   # 0x3b88
        LD_GLOBAL        R1, R15, -116   # 0x3b8c
        AND              R4, R1, R0, R1   # 0x3b90
        SHRI             R0, R1, 16   # 0x3b94
        LD_GLOBAL        R1, R15, -112   # 0x3b98
        SHLI             R1, R1, 16   # 0x3b9c
        OR               R3, R1, R0, R1   # 0x3ba0
        LD_GLOBAL        R1, R15, -108   # 0x3ba4
        LD_GLOBAL        R2, R15, -148   # 0x3ba8
        C_CHWIDTH        R2, 0   # 0x3bac
        CALL             R14, 124953   # 0x3bae
        MOVI             R15, 2   # 0x3bb2
        LD_GLOBAL        R15, R15, 24   # 0x3bb6
        SRD              R3, 2   # 0x3bba
        C_ADD            R15, R3   # 0x3bbc
        MOVI             R1, 0   # 0x3bbe
        ST_GLOBAL        R1, R15, -48   # 0x3bc2
        ST_GLOBAL        R1, R15, -52   # 0x3bc6
        LD_GLOBAL        R0, R15, -104   # 0x3bca
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3bce
        BRA_PRED         0, L3d0e   # 0x3bd2
        ADDI             R1, R15, -1   # 0x3bd6
        MOVI             R8, 1   # 0x3bda
        MOVI             R2, 65388   # 0x3bde
        MOVI             R3, 1   # 0x3be2
        CALL             R14, 128876   # 0x3be6
        C_CHWIDTH        R2, 1   # 0x3bea
        MOVI             R15, 2   # 0x3bec
        LD_GLOBAL        R15, R15, 24   # 0x3bf0
        SRD              R3, 2   # 0x3bf4
        C_ADD            R15, R3   # 0x3bf6
        LD_GLOBAL        R2, R15, -52   # 0x3bf8
        C_CHWIDTH        R2, 0   # 0x3bfc
        CALL             R14, 128571   # 0x3bfe
        C_CHWIDTH        R1, 1   # 0x3c02
        MOVI             R15, 2   # 0x3c04
        LD_GLOBAL        R15, R15, 24   # 0x3c08
        SRD              R3, 2   # 0x3c0c
        C_ADD            R15, R3   # 0x3c0e
        ST_GLOBAL        R1, R15, -52   # 0x3c10
        C_CHWIDTH        R1, 0   # 0x3c14
        ADDI             R1, R15, -1   # 0x3c16
        MOVI             R2, 65388   # 0x3c1a
        MOVI             R3, 65535   # 0x3c1e
        CALL             R14, 128846   # 0x3c22
        C_CHWIDTH        R2, 1   # 0x3c26
        MOVI             R15, 2   # 0x3c28
        LD_GLOBAL        R15, R15, 24   # 0x3c2c
        SRD              R3, 2   # 0x3c30
        C_ADD            R15, R3   # 0x3c32
        LD_GLOBAL        R2, R15, -52   # 0x3c34
        C_CHWIDTH        R2, 0   # 0x3c38
        CALL             R14, 128541   # 0x3c3a
        MOVI             R15, 2   # 0x3c3e
        LD_GLOBAL        R15, R15, 24   # 0x3c42
        SRD              R3, 2   # 0x3c46
        C_ADD            R15, R3   # 0x3c48
        C_MOV            R14, R1   # 0x3c4a
        C_MOV            R0, R14   # 0x3c4c
        C_CHWIDTH        R0, 1   # 0x3c4e
        ST_GLOBAL        R0, R15, -50   # 0x3c50
        C_CHWIDTH        R0, 0   # 0x3c54
        C_MOV            R0, R14   # 0x3c56
        C_CHWIDTH        R0, 1   # 0x3c58
        ST_GLOBAL        R0, R15, -52   # 0x3c5a
        C_CHWIDTH        R0, 0   # 0x3c5e
        LD_GLOBAL        R0, R15, -104   # 0x3c60
        SETP_LT_U_NPI    P0, R0, R0, 2   # 0x3c64
        C_MOV            R13, R14   # 0x3c68
        BRA_PRED         0, L3cfe   # 0x3c6a
L3c6e:  ADDI             R1, R15, -1   # 0x3c6e
        MOVI             R2, 65388   # 0x3c72
        MOVI             R3, 1   # 0x3c76
        CALL             R14, 128802   # 0x3c7a
        C_CHWIDTH        R2, 1   # 0x3c7e
        MOVI             R15, 2   # 0x3c80
        LD_GLOBAL        R15, R15, 24   # 0x3c84
        SRD              R3, 2   # 0x3c88
        C_ADD            R15, R3   # 0x3c8a
        LD_GLOBAL        R2, R15, -52   # 0x3c8c
        C_CHWIDTH        R2, 0   # 0x3c90
        CALL             R14, 128497   # 0x3c92
        C_CHWIDTH        R1, 1   # 0x3c96
        MOVI             R15, 2   # 0x3c98
        LD_GLOBAL        R15, R15, 24   # 0x3c9c
        SRD              R3, 2   # 0x3ca0
        C_ADD            R15, R3   # 0x3ca2
        ST_GLOBAL        R1, R15, -52   # 0x3ca4
        C_CHWIDTH        R1, 0   # 0x3ca8
        ADDI             R1, R15, -1   # 0x3caa
        MOVI             R2, 65388   # 0x3cae
        MOVI             R3, 65535   # 0x3cb2
        CALL             R14, 128772   # 0x3cb6
        C_CHWIDTH        R2, 1   # 0x3cba
        MOVI             R15, 2   # 0x3cbc
        LD_GLOBAL        R15, R15, 24   # 0x3cc0
        SRD              R3, 2   # 0x3cc4
        C_ADD            R15, R3   # 0x3cc6
        LD_GLOBAL        R2, R15, -52   # 0x3cc8
        C_CHWIDTH        R2, 0   # 0x3ccc
        CALL             R14, 128467   # 0x3cce
        MOVI             R15, 2   # 0x3cd2
        LD_GLOBAL        R15, R15, 24   # 0x3cd6
        SRD              R3, 2   # 0x3cda
        C_ADD            R15, R3   # 0x3cdc
        C_ADDI           R8, 1   # 0x3cde
        LD_GLOBAL        R0, R15, -104   # 0x3ce0
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x3ce4
        C_MOV            R13, R1   # 0x3ce8
        C_MOV            R0, R13   # 0x3cea
        C_CHWIDTH        R0, 1   # 0x3cec
        ST_GLOBAL        R0, R15, -52   # 0x3cee
        C_CHWIDTH        R0, 0   # 0x3cf2
        BRA_PRED         0, L3c6e   # 0x3cf4
        C_CHWIDTH        R14, 1   # 0x3cf8
        LD_GLOBAL        R14, R15, -50   # 0x3cfa
L3cfe:  C_CHWIDTH        R14, 0   # 0x3cfe
        CHWIDTH_MULTI    30720, 1   # 0x3d00
        LD_GLOBAL        R12, R15, -46   # 0x3d04
        LD_GLOBAL        R11, R15, -48   # 0x3d08
        C_BRA            L3d1e   # 0x3d0c
L3d0e:  C_MOV            R12, R1   # 0x3d0e
        C_MOV            R11, R12   # 0x3d10
        C_CHWIDTH        R11, 1   # 0x3d12
        C_MOV            R14, R12   # 0x3d14
        C_CHWIDTH        R14, 1   # 0x3d16
        C_MOV            R13, R12   # 0x3d18
        CHWIDTH_MULTI    12288, 1   # 0x3d1a
L3d1e:  LD_LOCAL         R1, 200   # 0x3d1e
        C_SHLI           R1, 3   # 0x3d22
        MOVI             R0, 2   # 0x3d24
        LD_GLOBAL        R0, R0, 44   # 0x3d28
        C_ADD            R0, R1   # 0x3d2c
        ST_GLOBAL_SLOT   R13, 1, R0, 0, 0   # 0x3d2e
        ADDI             R1, R0, 2   # 0x3d32
        ST_GLOBAL_SLOT   R14, 1, R1, 0, 0   # 0x3d36
        ADDI             R1, R0, 4   # 0x3d3a
        ST_GLOBAL_SLOT   R11, 1, R1, 0, 0   # 0x3d3e
        C_ADDI           R0, 6   # 0x3d42
        ST_GLOBAL_SLOT   R12, 1, R0, 0, 0   # 0x3d44
        C_EXIT           0   # 0x3d48
