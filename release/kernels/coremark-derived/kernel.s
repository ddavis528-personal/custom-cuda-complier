# coremark-derived: test/coremark-derived, compiled; ccv-as source, reassembled
# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base
# (0x1000: function pointers are absolute); the kernel's entry is 0x39ca.
        ST_GLOBAL        R14, R15, -36   # 0x0000
        ST_GLOBAL        R4, R15, -8   # 0x0004
        C_MOV            R4, R3   # 0x0008
        C_MOV            R9, R2   # 0x000a
        C_MOV            R14, R1   # 0x000c
        MOVI48           R0, 3435973837   # 0x000e
        MUL_HI_U         R12, R14, R0, R14   # 0x0014
        C_SHRI           R12, 4   # 0x0018
        ADDI             R2, R12, -2   # 0x001a
        C_MOV            R0, R2   # 0x001e
        C_SHLI           R0, 4   # 0x0020
        ADD              R11, R4, R0, R4   # 0x0022
        SHLI             R5, R9, 16   # 0x0026
        ADD              R3, R5, R11, R5   # 0x002a
        OR               R0, R5, R11, R5   # 0x002e
        C_ANDN           R0, R3   # 0x0032
        AND              R1, R5, R11, R5   # 0x0034
        OR               R0, R1, R0, R1   # 0x0038
        ST_GLOBAL_IDX    R3, R9, R4, 0, 8   # 0x003c
        SHRI             R1, R0, 31   # 0x0040
        C_MOV            R0, R2   # 0x0044
        SHRI             R6, R9, 16   # 0x0046
        ST_GLOBAL        R1, R15, -4   # 0x004a
        ADD              R8, R6, R1, R6   # 0x004e
        ST_GLOBAL_IDX    R8, R9, R4, 0, 12   # 0x0052
        MOVI             R2, 0   # 0x0056
        ST_GLOBAL_IDX    R2, R9, R4, 0, 4   # 0x005a
        ST_GLOBAL_IDX    R2, R9, R4, 0, 0   # 0x005e
        MOVI             R1, 32896   # 0x0062
        C_CHWIDTH        R1, 1   # 0x0066
        ST_GLOBAL_IDX    R1, R9, R11, 0, 0   # 0x0068
        C_MOV            R7, R2   # 0x006c
        C_CHWIDTH        R7, 1   # 0x006e
        ST_GLOBAL_IDX    R7, R9, R11, 0, 2   # 0x0070
        SETP_LT_U_NPI    P0, R1, R0, 3   # 0x0074
        ST_GLOBAL        R11, R15, -12   # 0x0078
        BRA_PRED         0, L00fc   # 0x007c
        CHWIDTH_MULTI    130, 0   # 0x0080
        ADDI             R7, R4, 16   # 0x0084
        ADD              R1, R5, R7, R5   # 0x0088
        OR               R2, R5, R7, R5   # 0x008c
        C_ANDN           R2, R1   # 0x0090
        AND              R10, R5, R7, R5   # 0x0092
        OR               R2, R10, R2, R10   # 0x0096
        MOVI             R10, 0   # 0x009a
        ST_GLOBAL_IDX    R10, R9, R4, 0, 20   # 0x009e
        ST_GLOBAL_IDX    R10, R9, R4, 0, 16   # 0x00a2
        ST_GLOBAL_IDX    R1, R9, R4, 0, 0   # 0x00a6
        SHRI             R1, R2, 31   # 0x00aa
        ADD              R1, R6, R1, R6   # 0x00ae
        ST_GLOBAL_IDX    R1, R9, R4, 0, 4   # 0x00b2
        ADDI             R1, R11, 4   # 0x00b6
        ADD              R2, R5, R1, R5   # 0x00ba
        ST_GLOBAL_IDX    R2, R9, R4, 0, 24   # 0x00be
        OR               R10, R5, R1, R5   # 0x00c2
        ANDN             R2, R10, R2, R10   # 0x00c6
        AND              R1, R5, R1, R5   # 0x00ca
        C_OR             R1, R2   # 0x00ce
        SHRI             R1, R1, 31   # 0x00d0
        ADD              R1, R6, R1, R6   # 0x00d4
        ST_GLOBAL_IDX    R1, R9, R4, 0, 28   # 0x00d8
        MOVI             R1, 32767   # 0x00dc
        C_CHWIDTH        R1, 1   # 0x00e0
        ST_GLOBAL_IDX    R1, R9, R11, 0, 6   # 0x00e2
        C_CHWIDTH        R1, 0   # 0x00e6
        MOVI             R1, 65535   # 0x00e8
        C_CHWIDTH        R1, 1   # 0x00ec
        ST_GLOBAL_IDX    R1, R9, R11, 0, 4   # 0x00ee
        ADDI             R13, R4, 32   # 0x00f2
        C_ADDI           R11, 8   # 0x00f6
        C_MOV            R2, R9   # 0x00f8
        C_BRA            L0108   # 0x00fa
L00fc:  C_CHWIDTH        R7, 0   # 0x00fc
        ADDI             R13, R4, 16   # 0x00fe
        C_ADDI           R11, 4   # 0x0102
        MOVI             R7, 0   # 0x0104
L0108:  SETP_EQ_NPI      P0, R1, R0, 0   # 0x0108
        ST_GLOBAL        R0, R15, -40   # 0x010c
        BRA_PRED         0, L05b6   # 0x0110
        C_CHWIDTH        R1, 0   # 0x0114
        MOVI             R10, 0   # 0x0116
        C_MOV            R1, R10   # 0x011a
        ST_GLOBAL        R1, R15, -20   # 0x011c
        C_ANDI           R12, 1   # 0x0120
        ADDI             R1, R14, -60   # 0x0122
        SETP_LT_U_NPI    P0, R1, R1, 20   # 0x0126
        C_MOV            R1, R0   # 0x012a
        C_SHLI           R1, 2   # 0x012c
        ST_GLOBAL        R1, R15, -16   # 0x012e
        BRA_PRED         4, L0146   # 0x0132
        MOVI             R14, 0   # 0x0136
        SETP_EQ_NPI      P0, R1, R12, 0   # 0x013a
        BRA_PRED         4, L0456   # 0x013e
        BRA              L05be   # 0x0142
L0146:  ST_GLOBAL        R12, R15, -44   # 0x0146
        MOVI             R14, 0   # 0x014a
        ANDI             R0, R0, -2   # 0x014e
        ST_GLOBAL        R0, R15, -24   # 0x0152
        MOVI             R1, 32767   # 0x0156
        ST_GLOBAL        R1, R15, -32   # 0x015a
        ST_GLOBAL        R8, R15, -28   # 0x015e
        ST_GLOBAL        R3, R15, -20   # 0x0162
        C_BRA            L017a   # 0x0166
L0168:  C_MOV            R11, R12   # 0x0168
        C_MOV            R13, R10   # 0x016a
L016c:  C_ADDI           R14, 2   # 0x016c
        LD_GLOBAL        R0, R15, -24   # 0x016e
        SETP_EQ_NP       P0, R0, R0, R14   # 0x0172
        BRA_PRED         0, L043e   # 0x0176
L017a:  C_CHWIDTH        R1, 0   # 0x017a
        ADDI             R10, R13, 16   # 0x017c
        ADD              R1, R5, R10, R5   # 0x0180
        SETP_LT_U_NP     P0, R12, R1, R3   # 0x0184
        OR               R12, R5, R10, R5   # 0x0188
        ANDN             R1, R12, R1, R12   # 0x018c
        AND              R12, R5, R10, R5   # 0x0190
        OR               R1, R12, R1, R12   # 0x0194
        SHRI             R1, R1, 31   # 0x0198
        LD_GLOBAL        R0, R15, -4   # 0x019c
        SETP_EQ_NP       P1, R12, R1, R0   # 0x01a0
        ADD              R1, R6, R1, R6   # 0x01a4
        SETP_LT_U_NP     P2, R1, R1, R8   # 0x01a8
        BRA_PRED         2, L01be   # 0x01ac
        PAND             P0, 1, 0   # 0x01b0
        BRA_PRED         0, L01be   # 0x01b2
        C_MOV            R12, R11   # 0x01b6
        C_MOV            R10, R13   # 0x01b8
        BRA              L02dc   # 0x01ba
L01be:  LD_GLOBAL        R0, R15, -12   # 0x01be
        LD_GLOBAL        R1, R15, -16   # 0x01c2
        ADD              R1, R0, R1, R0   # 0x01c6
        ADD              R3, R5, R1, R5   # 0x01ca
        OR               R12, R5, R1, R5   # 0x01ce
        C_ANDN           R12, R3   # 0x01d2
        AND              R1, R5, R1, R5   # 0x01d4
        C_OR             R1, R12   # 0x01d8
        ADDI             R12, R11, 4   # 0x01da
        ADD              R0, R5, R12, R5   # 0x01de
        SETP_LT_U_NP     P0, R3, R0, R3   # 0x01e2
        OR               R3, R5, R12, R5   # 0x01e6
        ANDN             R0, R3, R0, R3   # 0x01ea
        AND              R3, R5, R12, R5   # 0x01ee
        OR               R0, R3, R0, R3   # 0x01f2
        SHRI             R0, R0, 31   # 0x01f6
        SHRI             R1, R1, 31   # 0x01fa
        SETP_EQ_NP       P1, R3, R0, R1   # 0x01fe
        ADD              R0, R6, R0, R6   # 0x0202
        ADD              R1, R6, R1, R6   # 0x0206
        SETP_LT_U_NP     P2, R0, R0, R1   # 0x020a
        BRA_PRED         2, L021e   # 0x020e
        PAND             P0, 1, 0   # 0x0212
        BRA_PRED         0, L021e   # 0x0214
        C_MOV            R12, R11   # 0x0218
        C_MOV            R10, R13   # 0x021a
        C_BRA            L02d8   # 0x021c
L021e:  C_CHWIDTH        R3, 1   # 0x021e
        LD_GLOBAL        R0, R15, -8   # 0x0220
        C_CHWIDTH        R0, 1   # 0x0224
        XOR              R0, R14, R0, R14   # 0x0226
        C_CHWIDTH        R0, 0   # 0x022a
        SHLI             R0, R0, 3   # 0x022c
        MOVI             R1, 120   # 0x0230
        AND              R3, R0, R1, R0   # 0x0234
        C_CHWIDTH        R1, 1   # 0x0238
        MOVI             R0, 6   # 0x023a
        AND              R1, R14, R0, R14   # 0x023e
        C_CHWIDTH        R0, 1   # 0x0242
        OR               R0, R3, R1, R3   # 0x0244
        CHWIDTH_MULTI    11, 0   # 0x0248
        MULI             R0, R0, 257   # 0x024c
        C_MOV            R1, R0   # 0x0250
        C_CHWIDTH        R1, 1   # 0x0252
        SHLI             R0, R2, 16   # 0x0254
        AND              R3, R0, R7, R0   # 0x0258
        ADD              R8, R0, R7, R0   # 0x025c
        C_OR             R0, R7   # 0x0260
        C_ANDN           R0, R8   # 0x0262
        OR               R0, R3, R0, R3   # 0x0264
        SHRI             R0, R0, 31   # 0x0268
        SHRI             R2, R2, 16   # 0x026c
        ADD              R0, R2, R0, R2   # 0x0270
        ST_GLOBAL_IDX    R8, R9, R13, 0, 0   # 0x0274
        LD_GLOBAL        R8, R15, -28   # 0x0278
        ST_GLOBAL_IDX    R0, R9, R13, 0, 4   # 0x027c
        ADD              R0, R5, R13, R5   # 0x0280
        OR               R2, R5, R13, R5   # 0x0284
        C_ANDN           R2, R0   # 0x0288
        AND              R3, R5, R13, R5   # 0x028a
        OR               R2, R3, R2, R3   # 0x028e
        SHRI             R2, R2, 31   # 0x0292
        ADD              R2, R6, R2, R6   # 0x0296
        ST_GLOBAL_IDX    R2, R9, R4, 0, 4   # 0x029a
        ST_GLOBAL_IDX    R0, R9, R4, 0, 0   # 0x029e
        ADD              R0, R5, R11, R5   # 0x02a2
        OR               R2, R5, R11, R5   # 0x02a6
        C_ANDN           R2, R0   # 0x02aa
        AND              R3, R5, R11, R5   # 0x02ac
        OR               R2, R3, R2, R3   # 0x02b0
        SHRI             R2, R2, 31   # 0x02b4
        ADD              R2, R6, R2, R6   # 0x02b8
        ST_GLOBAL_IDX    R2, R9, R13, 0, 12   # 0x02bc
        ST_GLOBAL_IDX    R0, R9, R13, 0, 8   # 0x02c0
        LD_GLOBAL        R7, R15, -32   # 0x02c4
        C_CHWIDTH        R7, 1   # 0x02c8
        ST_GLOBAL_IDX    R7, R9, R11, 0, 2   # 0x02ca
        C_CHWIDTH        R7, 0   # 0x02ce
        ST_GLOBAL_IDX    R1, R9, R11, 0, 0   # 0x02d0
        C_MOV            R2, R9   # 0x02d4
        C_MOV            R7, R13   # 0x02d6
L02d8:  LD_GLOBAL        R3, R15, -20   # 0x02d8
L02dc:  ADDI             R13, R10, 16   # 0x02dc
        ADD              R0, R5, R13, R5   # 0x02e0
        SETP_LT_U_NP     P0, R1, R0, R3   # 0x02e4
        C_CHWIDTH        R1, 0   # 0x02e8
        OR               R1, R5, R13, R5   # 0x02ea
        ANDN             R0, R1, R0, R1   # 0x02ee
        AND              R1, R5, R13, R5   # 0x02f2
        OR               R0, R1, R0, R1   # 0x02f6
        SHRI             R0, R0, 31   # 0x02fa
        LD_GLOBAL        R1, R15, -4   # 0x02fe
        SETP_EQ_NP       P1, R1, R0, R1   # 0x0302
        ADD              R0, R6, R0, R6   # 0x0306
        SETP_LT_U_NP     P2, R0, R0, R8   # 0x030a
        BRA_PRED         2, L0318   # 0x030e
        PAND             P0, 1, 0   # 0x0312
        BRA_PRED         4, L0168   # 0x0314
L0318:  LD_GLOBAL        R0, R15, -12   # 0x0318
        LD_GLOBAL        R1, R15, -16   # 0x031c
        C_ADD            R0, R1   # 0x0320
        ADD              R1, R5, R0, R5   # 0x0322
        OR               R3, R5, R0, R5   # 0x0326
        C_ANDN           R3, R1   # 0x032a
        AND              R0, R5, R0, R5   # 0x032c
        C_OR             R0, R3   # 0x0330
        ADDI             R11, R12, 4   # 0x0332
        ADD              R3, R5, R11, R5   # 0x0336
        SETP_LT_U_NP     P0, R1, R3, R1   # 0x033a
        OR               R1, R5, R11, R5   # 0x033e
        C_ANDN           R1, R3   # 0x0342
        AND              R3, R5, R11, R5   # 0x0344
        OR               R1, R3, R1, R3   # 0x0348
        SHRI             R1, R1, 31   # 0x034c
        SHRI             R0, R0, 31   # 0x0350
        SETP_EQ_NP       P1, R3, R1, R0   # 0x0354
        ADD              R1, R6, R1, R6   # 0x0358
        ADD              R0, R6, R0, R6   # 0x035c
        SETP_LT_U_NP     P2, R0, R1, R0   # 0x0360
        BRA_PRED         2, L0374   # 0x0364
        PAND             P0, 1, 0   # 0x0368
        BRA_PRED         0, L0374   # 0x036a
        C_MOV            R11, R12   # 0x036e
        C_MOV            R13, R10   # 0x0370
        C_BRA            L0436   # 0x0372
L0374:  C_CHWIDTH        R3, 1   # 0x0374
        MOVI             R0, 1   # 0x0376
        OR               R3, R14, R0, R14   # 0x037a
        LD_GLOBAL        R0, R15, -8   # 0x037e
        C_CHWIDTH        R0, 1   # 0x0382
        XOR              R0, R3, R0, R3   # 0x0384
        C_CHWIDTH        R0, 0   # 0x0388
        MOVI             R1, 7   # 0x038a
        AND              R3, R3, R1, R3   # 0x038e
        SHLI             R0, R0, 3   # 0x0392
        MOVI             R1, 120   # 0x0396
        C_CHWIDTH        R1, 1   # 0x039a
        AND              R1, R0, R1, R0   # 0x039c
        C_CHWIDTH        R0, 1   # 0x03a0
        OR               R0, R1, R3, R1   # 0x03a2
        CHWIDTH_MULTI    11, 0   # 0x03a6
        MULI             R0, R0, 257   # 0x03aa
        C_MOV            R1, R0   # 0x03ae
        C_CHWIDTH        R1, 1   # 0x03b0
        SHLI             R0, R2, 16   # 0x03b2
        AND              R3, R0, R7, R0   # 0x03b6
        ADD              R8, R0, R7, R0   # 0x03ba
        C_OR             R0, R7   # 0x03be
        C_ANDN           R0, R8   # 0x03c0
        OR               R0, R3, R0, R3   # 0x03c2
        SHRI             R0, R0, 31   # 0x03c6
        SHRI             R2, R2, 16   # 0x03ca
        ADD              R0, R2, R0, R2   # 0x03ce
        ST_GLOBAL_IDX    R8, R9, R10, 0, 0   # 0x03d2
        LD_GLOBAL        R8, R15, -28   # 0x03d6
        ST_GLOBAL_IDX    R0, R9, R10, 0, 4   # 0x03da
        ADD              R0, R5, R10, R5   # 0x03de
        OR               R2, R5, R10, R5   # 0x03e2
        C_ANDN           R2, R0   # 0x03e6
        AND              R3, R5, R10, R5   # 0x03e8
        OR               R2, R3, R2, R3   # 0x03ec
        SHRI             R2, R2, 31   # 0x03f0
        ADD              R2, R6, R2, R6   # 0x03f4
        ST_GLOBAL_IDX    R2, R9, R4, 0, 4   # 0x03f8
        ST_GLOBAL_IDX    R0, R9, R4, 0, 0   # 0x03fc
        ADD              R0, R5, R12, R5   # 0x0400
        OR               R2, R5, R12, R5   # 0x0404
        C_ANDN           R2, R0   # 0x0408
        AND              R3, R5, R12, R5   # 0x040a
        OR               R2, R3, R2, R3   # 0x040e
        SHRI             R2, R2, 31   # 0x0412
        ADD              R2, R6, R2, R6   # 0x0416
        ST_GLOBAL_IDX    R2, R9, R10, 0, 12   # 0x041a
        ST_GLOBAL_IDX    R0, R9, R10, 0, 8   # 0x041e
        LD_GLOBAL        R7, R15, -32   # 0x0422
        C_CHWIDTH        R7, 1   # 0x0426
        ST_GLOBAL_IDX    R7, R9, R12, 0, 2   # 0x0428
        C_CHWIDTH        R7, 0   # 0x042c
        ST_GLOBAL_IDX    R1, R9, R12, 0, 0   # 0x042e
        C_MOV            R2, R9   # 0x0432
        C_MOV            R7, R10   # 0x0434
L0436:  LD_GLOBAL        R3, R15, -20   # 0x0436
        BRA              L016c   # 0x043a
L043e:  ST_GLOBAL        R14, R15, -20   # 0x043e
        C_MOV            R10, R2   # 0x0442
        C_MOV            R14, R7   # 0x0444
        LD_GLOBAL        R12, R15, -44   # 0x0446
        SETP_EQ_NPI      P0, R1, R12, 0   # 0x044a
        CHWIDTH_MULTI    2, 0   # 0x044e
        BRA_PRED         0, L05be   # 0x0452
L0456:  LD_GLOBAL        R0, R15, -12   # 0x0456
        LD_GLOBAL        R1, R15, -16   # 0x045a
        ADD              R1, R0, R1, R0   # 0x045e
        ADD              R14, R5, R1, R5   # 0x0462
        OR               R10, R5, R1, R5   # 0x0466
        C_ANDN           R10, R14   # 0x046a
        AND              R1, R5, R1, R5   # 0x046c
        C_OR             R1, R10   # 0x0470
        ADDI             R10, R11, 4   # 0x0472
        ADD              R12, R5, R10, R5   # 0x0476
        SETP_LT_U_NP     P0, R14, R12, R14   # 0x047a
        ST_PRED_G        1, R15, -12   # 0x047e
        OR               R14, R5, R10, R5   # 0x0482
        C_ANDN           R14, R12   # 0x0486
        AND              R10, R5, R10, R5   # 0x0488
        OR               R14, R10, R14, R10   # 0x048c
        SHRI             R14, R14, 31   # 0x0490
        SHRI             R1, R1, 31   # 0x0494
        SETP_EQ_NP       P0, R10, R14, R1   # 0x0498
        ST_PRED_G        1, R15, -16   # 0x049c
        ADD              R14, R6, R14, R6   # 0x04a0
        ADD              R1, R6, R1, R6   # 0x04a4
        SETP_LT_U_NP     P2, R1, R14, R1   # 0x04a8
        ADDI             R1, R13, 16   # 0x04ac
        ADD              R14, R5, R1, R5   # 0x04b0
        C_MOV            R0, R3   # 0x04b4
        C_MOV            R3, R8   # 0x04b6
        SETP_LE_U_NP     P0, R8, R0, R14   # 0x04b8
        OR               R8, R5, R1, R5   # 0x04bc
        ANDN             R14, R8, R14, R8   # 0x04c0
        AND              R1, R5, R1, R5   # 0x04c4
        C_OR             R1, R14   # 0x04c8
        SHRI             R1, R1, 31   # 0x04ca
        LD_GLOBAL        R0, R15, -4   # 0x04ce
        SETP_NE_NP       P1, R0, R1, R0   # 0x04d2
        POR              P0, 1, 0   # 0x04d6
        ADD              R0, R6, R1, R6   # 0x04d8
        SETP_LE_U_NP     P1, R0, R3, R0   # 0x04dc
        PAND             P0, 1, 0   # 0x04e0
        BRA_PRED         0, L05b6   # 0x04e2
        LD_PRED_G        1, R15, -12   # 0x04e6
        LD_PRED_G        2, R15, -20   # 0x04ea
        PAND             P0, 1, 0   # 0x04ee
        POR              P0, 2, 0   # 0x04f0
        BRA_PRED         4, L05b6   # 0x04f2
        C_CHWIDTH        R14, 1   # 0x04f6
        SHLI             R0, R2, 16   # 0x04f8
        AND              R1, R0, R7, R0   # 0x04fc
        ADD              R3, R0, R7, R0   # 0x0500
        C_OR             R0, R7   # 0x0504
        C_ANDN           R0, R3   # 0x0506
        OR               R0, R1, R0, R1   # 0x0508
        SHRI             R0, R0, 31   # 0x050c
        SHRI             R1, R2, 16   # 0x0510
        ADD              R0, R1, R0, R1   # 0x0514
        ST_GLOBAL_IDX    R3, R9, R13, 0, 0   # 0x0518
        ST_GLOBAL_IDX    R0, R9, R13, 0, 4   # 0x051c
        ADD              R0, R5, R13, R5   # 0x0520
        OR               R1, R5, R13, R5   # 0x0524
        C_ANDN           R1, R0   # 0x0528
        AND              R2, R5, R13, R5   # 0x052a
        OR               R1, R2, R1, R2   # 0x052e
        SHRI             R1, R1, 31   # 0x0532
        ADD              R1, R6, R1, R6   # 0x0536
        ST_GLOBAL_IDX    R1, R9, R4, 0, 4   # 0x053a
        ST_GLOBAL_IDX    R0, R9, R4, 0, 0   # 0x053e
        ADD              R0, R5, R11, R5   # 0x0542
        OR               R1, R5, R11, R5   # 0x0546
        C_ANDN           R1, R0   # 0x054a
        AND              R2, R5, R11, R5   # 0x054c
        OR               R1, R2, R1, R2   # 0x0550
        SHRI             R1, R1, 31   # 0x0554
        ADD              R1, R6, R1, R6   # 0x0558
        ST_GLOBAL_IDX    R1, R9, R13, 0, 12   # 0x055c
        ST_GLOBAL_IDX    R0, R9, R13, 0, 8   # 0x0560
        MOVI             R0, 7   # 0x0564
        LD_GLOBAL        R7, R15, -20   # 0x0568
        AND              R14, R7, R0, R7   # 0x056c
        LD_GLOBAL        R0, R15, -8   # 0x0570
        C_CHWIDTH        R0, 1   # 0x0574
        XOR              R0, R7, R0, R7   # 0x0576
        C_CHWIDTH        R7, 1   # 0x057a
        C_CHWIDTH        R0, 0   # 0x057c
        MOVI             R1, 32767   # 0x057e
        C_CHWIDTH        R1, 1   # 0x0582
        ST_GLOBAL_IDX    R1, R9, R11, 0, 2   # 0x0584
        C_CHWIDTH        R1, 0   # 0x0588
        SHLI             R0, R0, 3   # 0x058a
        MOVI             R1, 120   # 0x058e
        AND              R7, R0, R1, R0   # 0x0592
        C_CHWIDTH        R0, 1   # 0x0596
        OR               R0, R7, R14, R7   # 0x0598
        CHWIDTH_MULTI    16385, 0   # 0x059c
        MULI             R0, R0, 257   # 0x05a0
        C_MOV            R1, R0   # 0x05a4
        C_CHWIDTH        R0, 0   # 0x05a6
        C_CHWIDTH        R1, 1   # 0x05a8
        ST_GLOBAL_IDX    R1, R9, R11, 0, 0   # 0x05aa
        C_CHWIDTH        R1, 0   # 0x05ae
        C_MOV            R10, R9   # 0x05b0
        C_MOV            R14, R13   # 0x05b2
        C_BRA            L05be   # 0x05b4
L05b6:  CHWIDTH_MULTI    2, 0   # 0x05b6
        C_MOV            R10, R2   # 0x05ba
        C_MOV            R14, R7   # 0x05bc
L05be:  LD_GLOBAL_IDX    R1, R10, R14, 0, 4   # 0x05be
        LD_GLOBAL_IDX    R0, R10, R14, 0, 0   # 0x05c2
        MOVI             R2, 65535   # 0x05c6
        MOVI             R3, 65535   # 0x05ca
        AND              R2, R1, R2, R1   # 0x05ce
        OR               R2, R0, R2, R0   # 0x05d2
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x05d6
        BRA_PRED         0, L068e   # 0x05da
        CHWIDTH_MULTI    128, 0   # 0x05de
        SHRI             R2, R0, 16   # 0x05e2
        SHLI             R1, R1, 16   # 0x05e6
        OR               R8, R1, R2, R1   # 0x05ea
        AND              R11, R0, R3, R0   # 0x05ee
        MOVI48           R0, 3435973837   # 0x05f2
        LD_GLOBAL        R1, R15, -40   # 0x05f8
        MUL_HI_U         R0, R1, R0, R1   # 0x05fc
        MOVI             R12, 1   # 0x0600
        C_SHRI           R0, 2   # 0x0604
        MOVI             R1, 16383   # 0x0606
        MOVI             R2, 1792   # 0x060a
        MOVI             R5, 65535   # 0x060e
        C_BRA            L065c   # 0x0612
L0614:  C_CHWIDTH        R12, 0   # 0x0614
        C_CHWIDTH        R13, 1   # 0x0616
        LD_GLOBAL_IDX    R8, R10, R14, 0, 8   # 0x0618
        LD_GLOBAL_IDX    R14, R10, R14, 0, 12   # 0x061c
        SHLI             R14, R14, 16   # 0x0620
        SHRI             R10, R8, 16   # 0x0624
        C_OR             R14, R10   # 0x0628
        C_AND            R8, R5   # 0x062a
        ST_GLOBAL_IDX    R13, R14, R8, 0, 2   # 0x062c
        LD_GLOBAL_IDX    R14, R6, R3, 0, 4   # 0x0630
        LD_GLOBAL_IDX    R10, R6, R3, 0, 0   # 0x0634
        SHRI             R8, R10, 16   # 0x0638
        SHLI             R11, R14, 16   # 0x063c
        OR               R8, R11, R8, R11   # 0x0640
        C_AND            R14, R5   # 0x0644
        OR               R14, R10, R14, R10   # 0x0646
        AND              R11, R10, R5, R10   # 0x064a
        SETP_NE_NPI      P0, R14, R14, 0   # 0x064e
        C_MOV            R10, R6   # 0x0652
        C_MOV            R14, R3   # 0x0654
        C_MOV            R12, R7   # 0x0656
        BRA_PRED         4, L068e   # 0x0658
L065c:  C_CHWIDTH        R13, 0   # 0x065c
        C_MOV            R3, R11   # 0x065e
        C_MOV            R6, R8   # 0x0660
        C_MOV            R13, R12   # 0x0662
        SETP_LT_U_NP     P0, R7, R12, R0   # 0x0664
        ADDI             R7, R12, 1   # 0x0668
        BRA_PRED         0, L0614   # 0x066c
        C_CHWIDTH        R13, 1   # 0x0670
        LD_GLOBAL        R8, R15, -8   # 0x0672
        XOR              R13, R12, R8, R12   # 0x0676
        C_CHWIDTH        R12, 1   # 0x067a
        AND              R13, R13, R1, R13   # 0x067c
        SHLI             R8, R7, 8   # 0x0680
        AND              R12, R8, R2, R8   # 0x0684
        OR               R13, R12, R13, R12   # 0x0688
        C_BRA            L0614   # 0x068c
L068e:  MOVI             R11, 1   # 0x068e
        C_BRA            L06ba   # 0x0692
L0694:  MOVI             R0, 0   # 0x0694
        ST_GLOBAL_IDX    R0, R1, R6, 0, 4   # 0x0698
        ST_GLOBAL_IDX    R0, R1, R6, 0, 0   # 0x069c
        C_SHLI           R11, 1   # 0x06a0
        LD_GLOBAL        R0, R15, -12   # 0x06a2
        SETP_NE_NPI      P0, R0, R0, 0   # 0x06a6
        LD_GLOBAL        R1, R15, -4   # 0x06aa
        C_MOV            R9, R1   # 0x06ae
        LD_GLOBAL        R2, R15, -8   # 0x06b0
        C_MOV            R4, R2   # 0x06b4
        BRA_PRED         4, L0938   # 0x06b6
L06ba:  MOVI             R2, 0   # 0x06ba
        MOVI             R1, 0   # 0x06be
        MOVI             R6, 0   # 0x06c2
        MOVI             R0, 0   # 0x06c6
        ST_GLOBAL        R0, R15, -4   # 0x06ca
        ST_GLOBAL        R0, R15, -8   # 0x06ce
        ST_GLOBAL        R11, R15, -20   # 0x06d2
        C_BRA            L06e8   # 0x06d6
L06d8:  SETP_EQ_NPI      P0, R0, R2, 0   # 0x06d8
        LD_GLOBAL        R11, R15, -20   # 0x06dc
        LD_GLOBAL        R2, R15, -16   # 0x06e0
        BRA_PRED         0, L0694   # 0x06e4
L06e8:  ST_GLOBAL        R2, R15, -12   # 0x06e8
        SETP_LT_NPI      P0, R0, R11, 1   # 0x06ec
        MOVI             R5, 65535   # 0x06f0
        BRA_PRED         0, L0736   # 0x06f4
        MOVI             R0, 0   # 0x06f8
        C_MOV            R2, R9   # 0x06fc
        C_MOV            R3, R4   # 0x06fe
L0700:  C_CHWIDTH        R7, 0   # 0x0700
        LD_GLOBAL_IDX    R7, R2, R3, 0, 4   # 0x0702
        LD_GLOBAL_IDX    R3, R2, R3, 0, 0   # 0x0706
        AND              R2, R7, R5, R7   # 0x070a
        OR               R2, R3, R2, R3   # 0x070e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0712
        BRA_PRED         4, L0740   # 0x0716
        SHRI             R2, R3, 16   # 0x071a
        SHLI             R7, R7, 16   # 0x071e
        OR               R2, R7, R2, R7   # 0x0722
        C_AND            R3, R5   # 0x0726
        C_ADDI           R0, 1   # 0x0728
        SETP_EQ_NP       P0, R7, R11, R0   # 0x072a
        BRA_PRED         4, L0700   # 0x072e
        C_MOV            R10, R11   # 0x0732
        C_BRA            L074c   # 0x0734
L0736:  MOVI             R10, 0   # 0x0736
        C_MOV            R2, R9   # 0x073a
        C_MOV            R3, R4   # 0x073c
        C_BRA            L074c   # 0x073e
L0740:  MOVI             R2, 0   # 0x0740
        ADDI             R10, R0, 1   # 0x0744
        MOVI             R3, 0   # 0x0748
L074c:  C_CHWIDTH        R7, 0   # 0x074c
        LD_GLOBAL        R0, R15, -12   # 0x074e
        C_ADDI           R0, 1   # 0x0752
        ST_GLOBAL        R0, R15, -16   # 0x0754
        C_MOV            R0, R9   # 0x0758
        C_MOV            R7, R4   # 0x075a
        C_MOV            R9, R2   # 0x075c
        C_MOV            R4, R3   # 0x075e
        C_BRA            L0776   # 0x0760
L0762:  ST_GLOBAL        R14, R15, -4   # 0x0762
        ST_GLOBAL        R8, R15, -8   # 0x0766
L076a:  C_MOV            R0, R13   # 0x076a
        C_MOV            R7, R12   # 0x076c
        C_MOV            R9, R2   # 0x076e
        C_MOV            R4, R3   # 0x0770
        C_MOV            R1, R14   # 0x0772
        C_MOV            R6, R8   # 0x0774
L0776:  MOVI             R2, 0   # 0x0776
        SETP_LT_NP       P0, R2, R2, R10   # 0x077a
        BRA_PRED         0, L07b6   # 0x077e
        SHLI             R2, R9, 16   # 0x0782
        AND              R3, R2, R4, R2   # 0x0786
        ADD              R14, R2, R4, R2   # 0x078a
        C_OR             R2, R4   # 0x078e
        C_ANDN           R2, R14   # 0x0790
        OR               R2, R3, R2, R3   # 0x0792
        SHRI             R2, R2, 31   # 0x0796
        SHRI             R3, R9, 16   # 0x079a
        ADD              R2, R3, R2, R3   # 0x079e
        OR               R2, R14, R2, R14   # 0x07a2
        SETP_LT_NPI      P0, R3, R11, 1   # 0x07a6
        BRA_PRED         0, L06d8   # 0x07aa
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x07ae
        BRA_PRED         0, L06d8   # 0x07b2
L07b6:  SETP_NE_NPI      P0, R2, R10, 0   # 0x07b6
        BRA_PRED         4, L086a   # 0x07ba
        SETP_EQ_NPI      P0, R2, R11, 0   # 0x07be
        BRA_PRED         0, L0898   # 0x07c2
        SHLI             R2, R9, 16   # 0x07c6
        AND              R3, R2, R4, R2   # 0x07ca
        ADD              R14, R2, R4, R2   # 0x07ce
        C_OR             R2, R4   # 0x07d2
        C_ANDN           R2, R14   # 0x07d4
        OR               R2, R3, R2, R3   # 0x07d6
        SHRI             R2, R2, 31   # 0x07da
        SHRI             R3, R9, 16   # 0x07de
        ADD              R2, R3, R2, R3   # 0x07e2
        OR               R2, R14, R2, R14   # 0x07e6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x07ea
        BRA_PRED         4, L0898   # 0x07ee
        C_CHWIDTH        R12, 2   # 0x07f2
        LD_GLOBAL_IDX    R2, R0, R7, 0, 8   # 0x07f4
        LD_GLOBAL_IDX    R3, R0, R7, 0, 12   # 0x07f8
        SHLI             R3, R3, 16   # 0x07fc
        SHRI             R14, R2, 16   # 0x0800
        C_OR             R3, R14   # 0x0804
        LD_GLOBAL_IDX    R14, R9, R4, 0, 8   # 0x0806
        LD_GLOBAL_IDX    R8, R9, R4, 0, 12   # 0x080a
        MOVI             R5, 65535   # 0x080e
        C_AND            R2, R5   # 0x0812
        LD_GLOBAL_IDX    R12, R3, R2, 0, 1   # 0x0814
        ST_GLOBAL_IDX    R12, R3, R2, 0, 0   # 0x0818
        C_CHWIDTH        R3, 1   # 0x081c
        C_CHWIDTH        R12, 0   # 0x081e
        SHLI             R8, R8, 16   # 0x0820
        SHRI             R12, R14, 16   # 0x0824
        C_OR             R8, R12   # 0x0828
        C_CHWIDTH        R12, 2   # 0x082a
        C_AND            R14, R5   # 0x082c
        LD_GLOBAL_IDX    R12, R8, R14, 0, 1   # 0x082e
        ST_GLOBAL_IDX    R12, R8, R14, 0, 0   # 0x0832
        C_CHWIDTH        R14, 1   # 0x0836
        LD_GLOBAL_IDX    R3, R3, R2, 0, 2   # 0x0838
        LD_GLOBAL_IDX    R14, R8, R14, 0, 2   # 0x083c
        CVT_SEXT         R2, R14, R14, R14   # 0x0840
        C_CHWIDTH        R14, 0   # 0x0844
        CVT_SEXT         R14, R3, R3, R3   # 0x0846
        SETP_LT_NP       P0, R2, R2, R14   # 0x084a
        BRA_PRED         4, L08b8   # 0x084e
        C_CHWIDTH        R3, 0   # 0x0852
        LD_GLOBAL_IDX    R3, R9, R4, 0, 0   # 0x0854
        LD_GLOBAL_IDX    R2, R9, R4, 0, 4   # 0x0858
        SHLI             R2, R2, 16   # 0x085c
        SHRI             R14, R3, 16   # 0x0860
        C_OR             R2, R14   # 0x0864
        C_AND            R3, R5   # 0x0866
        C_BRA            L0886   # 0x0868
L086a:  LD_GLOBAL_IDX    R3, R9, R4, 0, 0   # 0x086a
        LD_GLOBAL_IDX    R2, R9, R4, 0, 4   # 0x086e
        SHLI             R2, R2, 16   # 0x0872
        SHRI             R14, R3, 16   # 0x0876
        C_OR             R2, R14   # 0x087a
        MOVI             R5, 65535   # 0x087c
        C_AND            R3, R5   # 0x0880
        MOVI             R10, 0   # 0x0882
L0886:  CHWIDTH_MULTI    12288, 0   # 0x0886
        ADDI             R11, R11, -1   # 0x088a
        C_MOV            R13, R0   # 0x088e
        C_MOV            R12, R7   # 0x0890
        C_MOV            R14, R9   # 0x0892
        C_MOV            R8, R4   # 0x0894
        C_BRA            L08e0   # 0x0896
L0898:  C_CHWIDTH        R13, 0   # 0x0898
        LD_GLOBAL_IDX    R2, R0, R7, 0, 0   # 0x089a
        LD_GLOBAL_IDX    R3, R0, R7, 0, 4   # 0x089e
        SHLI             R3, R3, 16   # 0x08a2
        SHRI             R14, R2, 16   # 0x08a6
        OR               R13, R3, R14, R3   # 0x08aa
        MOVI             R3, 65535   # 0x08ae
        AND              R12, R2, R3, R2   # 0x08b2
        C_BRA            L08d4   # 0x08b6
L08b8:  CHWIDTH_MULTI    12296, 0   # 0x08b8
        LD_GLOBAL_IDX    R2, R0, R7, 0, 0   # 0x08bc
        LD_GLOBAL_IDX    R3, R0, R7, 0, 4   # 0x08c0
        SHLI             R3, R3, 16   # 0x08c4
        SHRI             R14, R2, 16   # 0x08c8
        OR               R13, R3, R14, R3   # 0x08cc
        AND              R12, R2, R5, R2   # 0x08d0
L08d4:  ADDI             R10, R10, -1   # 0x08d4
        C_MOV            R2, R9   # 0x08d8
        C_MOV            R3, R4   # 0x08da
        C_MOV            R14, R0   # 0x08dc
        C_MOV            R8, R7   # 0x08de
L08e0:  SHLI             R0, R1, 16   # 0x08e0
        AND              R4, R0, R6, R0   # 0x08e4
        ADD              R7, R0, R6, R0   # 0x08e8
        C_OR             R0, R6   # 0x08ec
        C_ANDN           R0, R7   # 0x08ee
        OR               R0, R4, R0, R4   # 0x08f0
        SHRI             R0, R0, 31   # 0x08f4
        SHRI             R4, R1, 16   # 0x08f8
        ADD              R0, R4, R0, R4   # 0x08fc
        OR               R0, R7, R0, R7   # 0x0900
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x0904
        BRA_PRED         0, L0762   # 0x0908
        SHLI             R0, R14, 16   # 0x090c
        ADD              R4, R0, R8, R0   # 0x0910
        ST_GLOBAL_IDX    R4, R1, R6, 0, 0   # 0x0914
        OR               R7, R0, R8, R0   # 0x0918
        ANDN             R4, R7, R4, R7   # 0x091c
        C_AND            R0, R8   # 0x0920
        C_OR             R0, R4   # 0x0922
        SHRI             R0, R0, 31   # 0x0924
        SHRI             R4, R14, 16   # 0x0928
        ADD              R0, R4, R0, R4   # 0x092c
        ST_GLOBAL_IDX    R0, R1, R6, 0, 4   # 0x0930
        BRA              L076a   # 0x0934
L0938:  C_CHWIDTH        R13, 0   # 0x0938
        LD_GLOBAL        R14, R15, -36   # 0x093a
        C_RET            224   # 0x093e
        ST_GLOBAL        R14, R15, -40   # 0x0940
        ST_GLOBAL        R6, R15, -44   # 0x0944
        ST_GLOBAL        R5, R15, -48   # 0x0948
        ST_GLOBAL        R3, R15, -20   # 0x094c
        C_MOV            R0, R1   # 0x0950
        MOVI             R3, 1   # 0x0952
        SETP_LT_U_NP     P0, R1, R3, R4   # 0x0956
        MOVI             R7, 1   # 0x095a
        MOV_P            R7, 0, R4, R4, R4   # 0x095e
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0962
        BRA_PRED         0, L098a   # 0x0966
        MOVI48           R8, 4294967295   # 0x096a
        MOVI             R4, 8   # 0x0970
L0974:  ADDI             R5, R8, 2   # 0x0974
        MUL_LO           R5, R4, R5, R5   # 0x0978
        SETP_LT_U_NP     P0, R5, R5, R0   # 0x097c
        C_ADDI           R4, 8   # 0x0980
        C_ADDI           R8, 1   # 0x0982
        BRA_PRED         0, L0974   # 0x0984
        C_BRA            L0990   # 0x0988
L098a:  MOVI48           R8, 4294967295   # 0x098a
L0990:  SHLI             R1, R2, 16   # 0x0990
        LD_GLOBAL        R0, R15, -20   # 0x0994
        ADD              R0, R1, R0, R1   # 0x0998
        C_NEG            R4, R0   # 0x099c
        C_ANDI           R4, 3   # 0x099e
        ST_GLOBAL        R4, R15, -28   # 0x09a0
        ADD              R4, R0, R4, R0   # 0x09a4
        MUL_LO           R5, R8, R8, R8   # 0x09a8
        C_SHLI           R5, 1   # 0x09ac
        ST_GLOBAL        R5, R15, -24   # 0x09ae
        ADD              R5, R4, R5, R4   # 0x09b2
        MOVI             R9, 0   # 0x09b6
        SETP_LT_U_NP     P0, R5, R5, R4   # 0x09ba
        MOVI             R5, 0   # 0x09be
        MOV_P            R5, 0, R3, R3, R3   # 0x09c2
        SETP_LT_U_NP     P0, R4, R4, R0   # 0x09c6
        MOVI             R4, 0   # 0x09ca
        MOV_P            R4, 0, R3, R3, R3   # 0x09ce
        ST_GLOBAL        R1, R15, -52   # 0x09d2
        SETP_LT_U_NP     P0, R0, R0, R1   # 0x09d6
        MOVI             R0, 0   # 0x09da
        MOV_P            R0, 0, R3, R3, R3   # 0x09de
        SETP_EQ_NPI      P0, R0, R8, 0   # 0x09e2
        BRA_PRED         0, L0b92   # 0x09e6
        C_CHWIDTH        R0, 1   # 0x09ea
        LD_GLOBAL        R1, R15, -20   # 0x09ec
        SUB              R0, R9, R1, R9   # 0x09f0
        C_CHWIDTH        R0, 0   # 0x09f4
        C_ANDI           R0, 3   # 0x09f6
        ADD              R6, R1, R0, R1   # 0x09f8
        MOVI             R0, 1   # 0x09fc
        C_MOV            R11, R8   # 0x0a00
        C_SHLI           R11, 1   # 0x0a02
        ANDI             R12, R8, -2   # 0x0a04
        ANDI             R5, R8, 1   # 0x0a08
        LD_GLOBAL        R1, R15, -24   # 0x0a0c
        ADD              R14, R6, R1, R6   # 0x0a10
        MOVI48           R13, 4294901760   # 0x0a14
        MOVI             R10, 0   # 0x0a1a
        ST_GLOBAL        R8, R15, -32   # 0x0a1e
        ST_GLOBAL        R11, R15, -36   # 0x0a22
        ST_GLOBAL        R5, R15, -8   # 0x0a26
        C_BRA            L0a3c   # 0x0a2a
L0a2c:  C_ADD            R14, R11   # 0x0a2c
        C_ADD            R6, R11   # 0x0a2e
        C_ADD            R9, R8   # 0x0a30
        C_ADDI           R10, 1   # 0x0a32
        SETP_NE_NP       P0, R1, R10, R8   # 0x0a34
        BRA_PRED         4, L0b92   # 0x0a38
L0a3c:  MOVI             R3, 0   # 0x0a3c
        SETP_EQ_NPI      P0, R4, R8, 1   # 0x0a40
        BRA_PRED         0, L0b26   # 0x0a44
        ST_GLOBAL        R10, R15, -16   # 0x0a48
        ST_GLOBAL        R9, R15, -12   # 0x0a4c
        MOVI             R4, 0   # 0x0a50
        C_MOV            R1, R0   # 0x0a54
        C_SHLI           R1, 1   # 0x0a56
        ST_GLOBAL        R1, R15, -4   # 0x0a58
L0a5c:  C_MOV            R10, R12   # 0x0a5c
        ADD              R12, R0, R3, R0   # 0x0a5e
        MUL_LO           R9, R7, R12, R12   # 0x0a62
        SRAI             R8, R9, 31   # 0x0a66
        SHRI             R8, R8, 16   # 0x0a6a
        MADLO            R7, R7, R12, R8   # 0x0a6e
        C_AND            R7, R13   # 0x0a72
        SUB              R7, R9, R7, R9   # 0x0a74
        ADD              R8, R14, R4, R14   # 0x0a78
        ADD              R9, R12, R7, R12   # 0x0a7c
        C_CHWIDTH        R9, 1   # 0x0a80
        ST_GLOBAL_IDX    R9, R2, R8, 0, 0   # 0x0a82
        C_CHWIDTH        R9, 0   # 0x0a86
        ADDI             R9, R12, 1   # 0x0a88
        MUL_LO           R1, R7, R9, R9   # 0x0a8c
        SRAI             R13, R1, 31   # 0x0a90
        SHRI             R13, R13, 16   # 0x0a94
        MADLO            R9, R7, R9, R13   # 0x0a98
        ADD              R13, R6, R4, R6   # 0x0a9c
        C_MOV            R11, R14   # 0x0aa0
        C_MOV            R14, R6   # 0x0aa2
        LD_GLOBAL        R6, R15, -4   # 0x0aa4
        C_ADD            R6, R4   # 0x0aa8
        ADD              R7, R6, R7, R6   # 0x0aaa
        C_CHWIDTH        R7, 1   # 0x0aae
        MOVI             R5, 255   # 0x0ab0
        AND              R7, R7, R5, R7   # 0x0ab4
        ST_GLOBAL_IDX    R7, R2, R13, 0, 0   # 0x0ab8
        C_CHWIDTH        R7, 0   # 0x0abc
        MOVI48           R7, 4294901760   # 0x0abe
        AND              R7, R9, R7, R9   # 0x0ac4
        SUB              R7, R1, R7, R1   # 0x0ac8
        ADDI             R1, R8, 2   # 0x0acc
        ADD              R8, R12, R7, R12   # 0x0ad0
        C_CHWIDTH        R12, 1   # 0x0ad4
        ADDI             R12, R8, 1   # 0x0ad6
        ST_GLOBAL_IDX    R12, R2, R1, 0, 0   # 0x0ada
        C_CHWIDTH        R12, 0   # 0x0ade
        C_MOV            R12, R10   # 0x0ae0
        ADD              R1, R6, R7, R6   # 0x0ae2
        C_CHWIDTH        R6, 1   # 0x0ae6
        ADDI             R6, R1, 2   # 0x0ae8
        AND              R6, R6, R5, R6   # 0x0aec
        ADDI             R1, R13, 2   # 0x0af0
        MOVI48           R13, 4294901760   # 0x0af4
        ST_GLOBAL_IDX    R6, R2, R1, 0, 0   # 0x0afa
        C_CHWIDTH        R6, 0   # 0x0afe
        C_MOV            R6, R14   # 0x0b00
        C_MOV            R14, R11   # 0x0b02
        C_ADDI           R4, 4   # 0x0b04
        C_ADDI           R3, 2   # 0x0b06
        SETP_NE_NP       P0, R1, R12, R3   # 0x0b08
        BRA_PRED         0, L0a5c   # 0x0b0c
        C_ADD            R0, R3   # 0x0b10
        LD_GLOBAL        R8, R15, -32   # 0x0b12
        LD_GLOBAL        R9, R15, -12   # 0x0b16
        LD_GLOBAL        R11, R15, -36   # 0x0b1a
        LD_GLOBAL        R5, R15, -8   # 0x0b1e
        LD_GLOBAL        R10, R15, -16   # 0x0b22
L0b26:  SETP_EQ_NPI      P0, R1, R5, 0   # 0x0b26
        BRA_PRED         0, L0a2c   # 0x0b2a
        MUL_LO           R1, R10, R8, R8   # 0x0b2e
        MUL_LO           R4, R7, R0, R0   # 0x0b32
        C_MOV            R5, R10   # 0x0b36
        C_MOV            R10, R6   # 0x0b38
        SRAI             R6, R4, 31   # 0x0b3a
        SHRI             R6, R6, 16   # 0x0b3e
        MAD_ACC          R6, R7, R0   # 0x0b42
        C_AND            R6, R13   # 0x0b44
        SUB              R7, R4, R6, R4   # 0x0b46
        LD_GLOBAL        R4, R15, -20   # 0x0b4a
        LD_GLOBAL        R6, R15, -28   # 0x0b4e
        C_ADD            R4, R6   # 0x0b52
        ADD              R1, R3, R1, R3   # 0x0b54
        C_SHLI           R1, 1   # 0x0b58
        ADD              R1, R4, R1, R4   # 0x0b5a
        LD_GLOBAL        R3, R15, -24   # 0x0b5e
        ADD              R3, R1, R3, R1   # 0x0b62
        ADD              R4, R7, R0, R7   # 0x0b66
        C_MOV            R6, R4   # 0x0b6a
        C_CHWIDTH        R6, 1   # 0x0b6c
        ST_GLOBAL_IDX    R6, R2, R3, 0, 0   # 0x0b6e
        ADD              R3, R4, R0, R4   # 0x0b72
        MOVI             R4, 255   # 0x0b76
        AND              R6, R3, R4, R3   # 0x0b7a
        ST_GLOBAL_IDX    R6, R2, R1, 0, 0   # 0x0b7e
        C_CHWIDTH        R6, 0   # 0x0b82
        C_MOV            R6, R10   # 0x0b84
        C_MOV            R10, R5   # 0x0b86
        LD_GLOBAL        R5, R15, -8   # 0x0b88
        C_ADDI           R0, 1   # 0x0b8c
        BRA              L0a2c   # 0x0b8e
L0b92:  LD_GLOBAL        R0, R15, -20   # 0x0b92
        LD_GLOBAL        R1, R15, -28   # 0x0b96
        C_ADD            R0, R1   # 0x0b9a
        LD_GLOBAL        R14, R15, -52   # 0x0b9c
        ADD              R1, R14, R0, R14   # 0x0ba0
        OR               R3, R14, R0, R14   # 0x0ba4
        C_ANDN           R3, R1   # 0x0ba8
        AND              R4, R14, R0, R14   # 0x0baa
        OR               R3, R4, R3, R4   # 0x0bae
        LD_GLOBAL        R4, R15, -24   # 0x0bb2
        C_ADD            R0, R4   # 0x0bb6
        ADD              R4, R0, R4, R0   # 0x0bb8
        ADD              R5, R14, R4, R14   # 0x0bbc
        C_NEG            R5, R5   # 0x0bc0
        C_ANDI           R5, 3   # 0x0bc2
        C_ADD            R4, R5   # 0x0bc4
        ADD              R5, R14, R0, R14   # 0x0bc6
        OR               R6, R14, R0, R14   # 0x0bca
        C_ANDN           R6, R5   # 0x0bce
        AND              R0, R14, R0, R14   # 0x0bd0
        C_OR             R0, R6   # 0x0bd4
        LD_GLOBAL        R6, R15, -44   # 0x0bd6
        LD_GLOBAL        R7, R15, -48   # 0x0bda
        ST_GLOBAL_IDX    R1, R7, R6, 0, 8   # 0x0bde
        ST_GLOBAL_IDX    R5, R7, R6, 0, 16   # 0x0be2
        SHRI             R1, R3, 31   # 0x0be6
        SHRI             R2, R2, 16   # 0x0bea
        ADD              R1, R2, R1, R2   # 0x0bee
        ST_GLOBAL_IDX    R1, R7, R6, 0, 12   # 0x0bf2
        SHRI             R0, R0, 31   # 0x0bf6
        ADD              R0, R2, R0, R2   # 0x0bfa
        ST_GLOBAL_IDX    R0, R7, R6, 0, 20   # 0x0bfe
        ADD              R0, R14, R4, R14   # 0x0c02
        ST_GLOBAL_IDX    R0, R7, R6, 0, 24   # 0x0c06
        OR               R1, R14, R4, R14   # 0x0c0a
        ANDN             R0, R1, R0, R1   # 0x0c0e
        AND              R1, R14, R4, R14   # 0x0c12
        OR               R0, R1, R0, R1   # 0x0c16
        SHRI             R0, R0, 31   # 0x0c1a
        ADD              R0, R2, R0, R2   # 0x0c1e
        ST_GLOBAL_IDX    R0, R7, R6, 0, 28   # 0x0c22
        ST_GLOBAL_IDX    R8, R7, R6, 0, 0   # 0x0c26
        LD_GLOBAL        R14, R15, -40   # 0x0c2a
        C_MOV            R1, R8   # 0x0c2e
        C_RET            224   # 0x0c30
        ST_GLOBAL        R14, R15, -4   # 0x0c32
        MOVI             R0, 0   # 0x0c36
        ST_GLOBAL        R1, R15, -8   # 0x0c3a
        ADDI             R5, R1, -1   # 0x0c3e
        SETP_LT_U_NPI    P0, R6, R5, 2   # 0x0c42
        BRA_PRED         0, L0d64   # 0x0c46
        MOVI             R10, 0   # 0x0c4a
        MOVI             R7, 65535   # 0x0c4e
        MOVI             R11, 0   # 0x0c52
        MOVI             R9, 0   # 0x0c56
        C_BRA            L0c9c   # 0x0c5a
L0c5c:  MOVI             R9, 8   # 0x0c5c
        MOVI             R10, 96   # 0x0c60
L0c64:  C_CHWIDTH        R6, 0   # 0x0c64
        ANDI             R1, R2, 24   # 0x0c66
        ADD              R1, R10, R1, R10   # 0x0c6a
        MOVI             R6, 2   # 0x0c6e
        LD_GLOBAL        R6, R6, 28   # 0x0c72
        LD_GLOBAL_IDX    R14, R6, R1, 0, 0   # 0x0c76
        LD_GLOBAL_IDX    R1, R6, R1, 0, 4   # 0x0c7a
        SHLI             R1, R1, 16   # 0x0c7e
        SHRI             R6, R14, 16   # 0x0c82
        OR               R10, R1, R6, R1   # 0x0c86
        AND              R11, R14, R7, R14   # 0x0c8a
        ADD              R1, R0, R9, R0   # 0x0c8e
        C_ADDI           R1, 1   # 0x0c92
        SETP_LT_U_NP     P0, R1, R1, R5   # 0x0c94
        BRA_PRED         4, L0d64   # 0x0c98
L0c9c:  SETP_EQ_NPI      P0, R12, R9, 0   # 0x0c9c
        BRA_PRED         0, L0d20   # 0x0ca0
        SETP_LT_U_NPI    P0, R12, R9, 4   # 0x0ca4
        BRA_PRED         0, L0d0c   # 0x0ca8
        ADD              R12, R4, R0, R4   # 0x0cac
        MOVI             R13, 0   # 0x0cb0
L0cb4:  C_CHWIDTH        R1, 2   # 0x0cb4
        ADD              R8, R12, R13, R12   # 0x0cb6
        ADD              R14, R13, R11, R13   # 0x0cba
        LD_GLOBAL_IDX    R1, R10, R14, 0, 0   # 0x0cbe
        ST_GLOBAL_IDX    R1, R3, R8, 0, 0   # 0x0cc2
        C_CHWIDTH        R1, 0   # 0x0cc6
        ADDI             R1, R14, 1   # 0x0cc8
        C_CHWIDTH        R1, 2   # 0x0ccc
        LD_GLOBAL_IDX    R1, R10, R1, 0, 0   # 0x0cce
        ADDI             R6, R8, 1   # 0x0cd2
        ST_GLOBAL_IDX    R1, R3, R6, 0, 0   # 0x0cd6
        C_CHWIDTH        R1, 0   # 0x0cda
        ADDI             R1, R14, 2   # 0x0cdc
        C_CHWIDTH        R1, 2   # 0x0ce0
        LD_GLOBAL_IDX    R1, R10, R1, 0, 0   # 0x0ce2
        ADDI             R6, R8, 2   # 0x0ce6
        ST_GLOBAL_IDX    R1, R3, R6, 0, 0   # 0x0cea
        C_CHWIDTH        R1, 0   # 0x0cee
        ADDI             R1, R14, 3   # 0x0cf0
        C_CHWIDTH        R1, 2   # 0x0cf4
        LD_GLOBAL_IDX    R1, R10, R1, 0, 0   # 0x0cf6
        ADDI             R6, R8, 3   # 0x0cfa
        ST_GLOBAL_IDX    R1, R3, R6, 0, 0   # 0x0cfe
        C_ADDI           R13, 4   # 0x0d02
        SETP_NE_NP       P0, R1, R9, R13   # 0x0d04
        BRA_PRED         0, L0cb4   # 0x0d08
L0d0c:  C_CHWIDTH        R1, 0   # 0x0d0c
        C_ADD            R0, R9   # 0x0d0e
        ADD              R1, R0, R4, R0   # 0x0d10
        MOVI             R6, 44   # 0x0d14
        C_CHWIDTH        R6, 2   # 0x0d18
        ST_GLOBAL_IDX    R6, R3, R1, 0, 0   # 0x0d1a
        C_ADDI           R0, 1   # 0x0d1e
L0d20:  C_CHWIDTH        R2, 1   # 0x0d20
        ADDI             R2, R2, 1   # 0x0d22
        C_CHWIDTH        R2, 0   # 0x0d26
        ANDI             R11, R2, 7   # 0x0d28
        MOVI             R9, 4   # 0x0d2c
        SETP_LT_NP       P0, R1, R9, R11   # 0x0d30
        BRA_PRED         0, L0d4e   # 0x0d34
        MOVI             R10, 0   # 0x0d38
        SETP_LT_U_NPI    P0, R1, R11, 3   # 0x0d3c
        BRA_PRED         0, L0c64   # 0x0d40
        MOVI             R9, 8   # 0x0d44
        MOVI             R10, 32   # 0x0d48
        C_BRA            L0c64   # 0x0d4c
L0d4e:  ADDI             R1, R11, -5   # 0x0d4e
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x0d52
        BRA_PRED         4, L0c5c   # 0x0d56
        MOVI             R9, 8   # 0x0d5a
        MOVI             R10, 64   # 0x0d5e
        C_BRA            L0c64   # 0x0d62
L0d64:  LD_GLOBAL        R1, R15, -8   # 0x0d64
        SETP_LE_U_NP     P0, R2, R1, R0   # 0x0d68
        BRA_PRED         0, L0e0e   # 0x0d6c
        SUB              R2, R1, R0, R1   # 0x0d70
        ANDI             R5, R2, 7   # 0x0d74
        SETP_EQ_NPI      P0, R2, R5, 0   # 0x0d78
        C_MOV            R2, R0   # 0x0d7c
        BRA_PRED         0, L0da0   # 0x0d7e
        MOVI             R6, 0   # 0x0d82
        C_CHWIDTH        R6, 2   # 0x0d86
        C_MOV            R2, R0   # 0x0d88
L0d8a:  ADD              R7, R4, R2, R4   # 0x0d8a
        ST_GLOBAL_IDX    R6, R3, R7, 0, 0   # 0x0d8e
        C_ADDI           R2, 1   # 0x0d92
        ADDI             R5, R5, -1   # 0x0d94
        SETP_NE_NPI      P0, R7, R5, 0   # 0x0d98
        BRA_PRED         0, L0d8a   # 0x0d9c
L0da0:  C_SUB            R0, R1   # 0x0da0
        MOVI48           R5, 4294967288   # 0x0da2
        SETP_LT_U_NP     P0, R0, R5, R0   # 0x0da8
        BRA_PRED         0, L0e0e   # 0x0dac
        CHWIDTH_MULTI    64, 0   # 0x0db0
        ADDI             R0, R2, 7   # 0x0db4
        C_NEG            R1, R1   # 0x0db8
        MOVI             R2, 0   # 0x0dba
        C_CHWIDTH        R2, 2   # 0x0dbe
L0dc0:  ADD              R5, R4, R0, R4   # 0x0dc0
        ADDI             R6, R5, -7   # 0x0dc4
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0dc8
        ADDI             R6, R5, -6   # 0x0dcc
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0dd0
        ADDI             R6, R5, -5   # 0x0dd4
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0dd8
        ADDI             R6, R5, -4   # 0x0ddc
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0de0
        ADDI             R6, R5, -3   # 0x0de4
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0de8
        ADDI             R6, R5, -2   # 0x0dec
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0df0
        ADDI             R6, R5, -1   # 0x0df4
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0df8
        ST_GLOBAL_IDX    R2, R3, R5, 0, 0   # 0x0dfc
        C_ADDI           R0, 8   # 0x0e00
        ADD              R5, R1, R0, R1   # 0x0e02
        SETP_NE_NPI      P0, R5, R5, 7   # 0x0e06
        BRA_PRED         0, L0dc0   # 0x0e0a
L0e0e:  CHWIDTH_MULTI    68, 0   # 0x0e0e
        LD_GLOBAL        R14, R15, -4   # 0x0e12
        C_RET            224   # 0x0e16
        CHWIDTH_MULTI    17, 1   # 0x0e18
        XOR              R0, R1, R2, R1   # 0x0e1c
        C_CHWIDTH        R0, 0   # 0x0e20
        C_ANDI           R0, 1   # 0x0e22
        SETP_NE_NPI      P0, R0, R0, 0   # 0x0e24
        MOVI             R0, 40961   # 0x0e28
        SHRI             R2, R2, 1   # 0x0e2c
        C_MOV            R3, R2   # 0x0e30
        C_CHWIDTH        R2, 1   # 0x0e32
        XOR              R2, R2, R0, R2   # 0x0e34
        C_CHWIDTH        R2, 0   # 0x0e38
        MOV_P            R3, 0, R2, R2, R2   # 0x0e3a
        SHRI             R2, R1, 1   # 0x0e3e
        C_CHWIDTH        R2, 1   # 0x0e42
        XOR              R2, R2, R3, R2   # 0x0e44
        C_CHWIDTH        R2, 0   # 0x0e48
        C_ANDI           R2, 1   # 0x0e4a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e4c
        SHRI             R2, R3, 1   # 0x0e50
        C_MOV            R3, R2   # 0x0e54
        C_CHWIDTH        R2, 1   # 0x0e56
        XOR              R2, R2, R0, R2   # 0x0e58
        C_CHWIDTH        R2, 0   # 0x0e5c
        MOV_P            R3, 0, R2, R2, R2   # 0x0e5e
        SHRI             R2, R1, 2   # 0x0e62
        C_CHWIDTH        R2, 1   # 0x0e66
        XOR              R2, R2, R3, R2   # 0x0e68
        C_CHWIDTH        R2, 0   # 0x0e6c
        C_ANDI           R2, 1   # 0x0e6e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e70
        SHRI             R2, R3, 1   # 0x0e74
        C_MOV            R3, R2   # 0x0e78
        C_CHWIDTH        R2, 1   # 0x0e7a
        XOR              R2, R2, R0, R2   # 0x0e7c
        C_CHWIDTH        R2, 0   # 0x0e80
        MOV_P            R3, 0, R2, R2, R2   # 0x0e82
        SHRI             R2, R1, 3   # 0x0e86
        C_CHWIDTH        R2, 1   # 0x0e8a
        XOR              R2, R2, R3, R2   # 0x0e8c
        C_CHWIDTH        R2, 0   # 0x0e90
        C_ANDI           R2, 1   # 0x0e92
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0e94
        SHRI             R2, R3, 1   # 0x0e98
        C_MOV            R3, R2   # 0x0e9c
        C_CHWIDTH        R2, 1   # 0x0e9e
        XOR              R2, R2, R0, R2   # 0x0ea0
        C_CHWIDTH        R2, 0   # 0x0ea4
        MOV_P            R3, 0, R2, R2, R2   # 0x0ea6
        SHRI             R2, R1, 4   # 0x0eaa
        C_CHWIDTH        R2, 1   # 0x0eae
        XOR              R2, R2, R3, R2   # 0x0eb0
        C_CHWIDTH        R2, 0   # 0x0eb4
        C_ANDI           R2, 1   # 0x0eb6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0eb8
        SHRI             R2, R3, 1   # 0x0ebc
        C_MOV            R3, R2   # 0x0ec0
        C_CHWIDTH        R2, 1   # 0x0ec2
        XOR              R2, R2, R0, R2   # 0x0ec4
        C_CHWIDTH        R2, 0   # 0x0ec8
        MOV_P            R3, 0, R2, R2, R2   # 0x0eca
        SHRI             R2, R1, 5   # 0x0ece
        C_CHWIDTH        R2, 1   # 0x0ed2
        XOR              R2, R2, R3, R2   # 0x0ed4
        C_CHWIDTH        R2, 0   # 0x0ed8
        C_ANDI           R2, 1   # 0x0eda
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0edc
        SHRI             R2, R3, 1   # 0x0ee0
        C_MOV            R3, R2   # 0x0ee4
        C_CHWIDTH        R2, 1   # 0x0ee6
        XOR              R2, R2, R0, R2   # 0x0ee8
        C_CHWIDTH        R2, 0   # 0x0eec
        MOV_P            R3, 0, R2, R2, R2   # 0x0eee
        SHRI             R2, R1, 6   # 0x0ef2
        C_CHWIDTH        R2, 1   # 0x0ef6
        XOR              R2, R2, R3, R2   # 0x0ef8
        C_CHWIDTH        R2, 0   # 0x0efc
        C_ANDI           R2, 1   # 0x0efe
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0f00
        SHRI             R2, R3, 1   # 0x0f04
        C_MOV            R3, R2   # 0x0f08
        C_CHWIDTH        R2, 1   # 0x0f0a
        XOR              R2, R2, R0, R2   # 0x0f0c
        C_CHWIDTH        R2, 0   # 0x0f10
        MOV_P            R3, 0, R2, R2, R2   # 0x0f12
        MOVI             R2, 128   # 0x0f16
        AND              R4, R1, R2, R1   # 0x0f1a
        C_CHWIDTH        R2, 1   # 0x0f1e
        C_CHWIDTH        R4, 0   # 0x0f20
        SHRI             R4, R4, 7   # 0x0f22
        ANDI             R5, R3, 1   # 0x0f26
        SETP_EQ_NP       P0, R4, R4, R5   # 0x0f2a
        SHRI             R3, R3, 1   # 0x0f2e
        C_MOV            R4, R3   # 0x0f32
        C_CHWIDTH        R3, 1   # 0x0f34
        XOR              R3, R3, R0, R3   # 0x0f36
        C_CHWIDTH        R3, 0   # 0x0f3a
        MOV_P            R3, 0, R4, R4, R4   # 0x0f3c
        SHRI             R4, R1, 8   # 0x0f40
        C_CHWIDTH        R4, 1   # 0x0f44
        XOR              R4, R3, R4, R3   # 0x0f46
        C_CHWIDTH        R4, 0   # 0x0f4a
        C_ANDI           R4, 1   # 0x0f4c
        SETP_NE_NPI      P0, R4, R4, 0   # 0x0f4e
        SHRI             R3, R3, 1   # 0x0f52
        C_MOV            R4, R3   # 0x0f56
        C_CHWIDTH        R3, 1   # 0x0f58
        XOR              R3, R3, R0, R3   # 0x0f5a
        C_CHWIDTH        R3, 0   # 0x0f5e
        MOV_P            R4, 0, R3, R3, R3   # 0x0f60
        SHRI             R3, R1, 9   # 0x0f64
        C_CHWIDTH        R3, 1   # 0x0f68
        XOR              R3, R3, R4, R3   # 0x0f6a
        C_CHWIDTH        R3, 0   # 0x0f6e
        C_ANDI           R3, 1   # 0x0f70
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f72
        SHRI             R3, R4, 1   # 0x0f76
        C_MOV            R4, R3   # 0x0f7a
        C_CHWIDTH        R3, 1   # 0x0f7c
        XOR              R3, R3, R0, R3   # 0x0f7e
        C_CHWIDTH        R3, 0   # 0x0f82
        MOV_P            R4, 0, R3, R3, R3   # 0x0f84
        SHRI             R3, R1, 10   # 0x0f88
        C_CHWIDTH        R3, 1   # 0x0f8c
        XOR              R3, R3, R4, R3   # 0x0f8e
        C_CHWIDTH        R3, 0   # 0x0f92
        C_ANDI           R3, 1   # 0x0f94
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f96
        SHRI             R3, R4, 1   # 0x0f9a
        C_MOV            R4, R3   # 0x0f9e
        C_CHWIDTH        R3, 1   # 0x0fa0
        XOR              R3, R3, R0, R3   # 0x0fa2
        C_CHWIDTH        R3, 0   # 0x0fa6
        MOV_P            R4, 0, R3, R3, R3   # 0x0fa8
        SHRI             R3, R1, 11   # 0x0fac
        C_CHWIDTH        R3, 1   # 0x0fb0
        XOR              R3, R3, R4, R3   # 0x0fb2
        C_CHWIDTH        R3, 0   # 0x0fb6
        C_ANDI           R3, 1   # 0x0fb8
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fba
        SHRI             R3, R4, 1   # 0x0fbe
        C_MOV            R4, R3   # 0x0fc2
        C_CHWIDTH        R3, 1   # 0x0fc4
        XOR              R3, R3, R0, R3   # 0x0fc6
        C_CHWIDTH        R3, 0   # 0x0fca
        MOV_P            R4, 0, R3, R3, R3   # 0x0fcc
        SHRI             R3, R1, 12   # 0x0fd0
        C_CHWIDTH        R3, 1   # 0x0fd4
        XOR              R3, R3, R4, R3   # 0x0fd6
        C_CHWIDTH        R3, 0   # 0x0fda
        C_ANDI           R3, 1   # 0x0fdc
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fde
        SHRI             R3, R4, 1   # 0x0fe2
        C_MOV            R4, R3   # 0x0fe6
        C_CHWIDTH        R3, 1   # 0x0fe8
        XOR              R3, R3, R0, R3   # 0x0fea
        C_CHWIDTH        R3, 0   # 0x0fee
        MOV_P            R4, 0, R3, R3, R3   # 0x0ff0
        SHRI             R3, R1, 13   # 0x0ff4
        C_CHWIDTH        R3, 1   # 0x0ff8
        XOR              R3, R3, R4, R3   # 0x0ffa
        C_CHWIDTH        R3, 0   # 0x0ffe
        C_ANDI           R3, 1   # 0x1000
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1002
        SHRI             R3, R4, 1   # 0x1006
        C_MOV            R4, R3   # 0x100a
        C_CHWIDTH        R3, 1   # 0x100c
        XOR              R3, R3, R0, R3   # 0x100e
        C_CHWIDTH        R3, 0   # 0x1012
        MOV_P            R4, 0, R3, R3, R3   # 0x1014
        SHRI             R3, R1, 14   # 0x1018
        C_CHWIDTH        R3, 1   # 0x101c
        XOR              R3, R3, R4, R3   # 0x101e
        C_CHWIDTH        R3, 0   # 0x1022
        C_ANDI           R3, 1   # 0x1024
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1026
        SHRI             R3, R4, 1   # 0x102a
        C_MOV            R4, R3   # 0x102e
        C_CHWIDTH        R3, 1   # 0x1030
        XOR              R3, R3, R0, R3   # 0x1032
        C_CHWIDTH        R3, 0   # 0x1036
        MOV_P            R4, 0, R3, R3, R3   # 0x1038
        SHRI             R3, R1, 15   # 0x103c
        ANDI             R5, R4, 1   # 0x1040
        SETP_EQ_NP       P0, R3, R3, R5   # 0x1044
        C_CHWIDTH        R5, 1   # 0x1048
        SHRI             R3, R4, 1   # 0x104a
        C_MOV            R4, R3   # 0x104e
        XOR              R5, R3, R0, R3   # 0x1050
        C_CHWIDTH        R5, 0   # 0x1054
        MOV_P            R5, 0, R4, R4, R4   # 0x1056
        C_CHWIDTH        R4, 1   # 0x105a
        SHRI             R3, R1, 16   # 0x105c
        XOR              R4, R5, R3, R5   # 0x1060
        C_CHWIDTH        R4, 0   # 0x1064
        C_ANDI           R4, 1   # 0x1066
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1068
        SHRI             R4, R5, 1   # 0x106c
        C_MOV            R5, R4   # 0x1070
        C_CHWIDTH        R4, 1   # 0x1072
        XOR              R4, R4, R0, R4   # 0x1074
        C_CHWIDTH        R4, 0   # 0x1078
        MOV_P            R5, 0, R4, R4, R4   # 0x107a
        SHRI             R4, R1, 17   # 0x107e
        C_XOR            R4, R5   # 0x1082
        C_ANDI           R4, 1   # 0x1084
        SETP_NE_NPI      P0, R4, R4, 0   # 0x1086
        SHRI             R4, R5, 1   # 0x108a
        C_MOV            R5, R4   # 0x108e
        C_CHWIDTH        R4, 1   # 0x1090
        XOR              R4, R4, R0, R4   # 0x1092
        C_CHWIDTH        R4, 0   # 0x1096
        MOV_P            R5, 0, R4, R4, R4   # 0x1098
        SHRI             R4, R1, 18   # 0x109c
        C_XOR            R4, R5   # 0x10a0
        C_ANDI           R4, 1   # 0x10a2
        SETP_NE_NPI      P0, R4, R4, 0   # 0x10a4
        SHRI             R4, R5, 1   # 0x10a8
        C_MOV            R5, R4   # 0x10ac
        C_CHWIDTH        R4, 1   # 0x10ae
        XOR              R4, R4, R0, R4   # 0x10b0
        C_CHWIDTH        R4, 0   # 0x10b4
        MOV_P            R5, 0, R4, R4, R4   # 0x10b6
        SHRI             R4, R1, 19   # 0x10ba
        C_XOR            R4, R5   # 0x10be
        C_ANDI           R4, 1   # 0x10c0
        SETP_NE_NPI      P0, R4, R4, 0   # 0x10c2
        SHRI             R4, R5, 1   # 0x10c6
        C_MOV            R5, R4   # 0x10ca
        C_CHWIDTH        R4, 1   # 0x10cc
        XOR              R4, R4, R0, R4   # 0x10ce
        C_CHWIDTH        R4, 0   # 0x10d2
        MOV_P            R5, 0, R4, R4, R4   # 0x10d4
        SHRI             R4, R1, 20   # 0x10d8
        C_XOR            R4, R5   # 0x10dc
        C_ANDI           R4, 1   # 0x10de
        SETP_NE_NPI      P0, R4, R4, 0   # 0x10e0
        SHRI             R4, R5, 1   # 0x10e4
        C_MOV            R5, R4   # 0x10e8
        C_CHWIDTH        R4, 1   # 0x10ea
        XOR              R4, R4, R0, R4   # 0x10ec
        C_CHWIDTH        R4, 0   # 0x10f0
        MOV_P            R5, 0, R4, R4, R4   # 0x10f2
        SHRI             R4, R1, 21   # 0x10f6
        C_XOR            R4, R5   # 0x10fa
        C_ANDI           R4, 1   # 0x10fc
        SETP_NE_NPI      P0, R4, R4, 0   # 0x10fe
        SHRI             R4, R5, 1   # 0x1102
        C_MOV            R5, R4   # 0x1106
        C_CHWIDTH        R4, 1   # 0x1108
        XOR              R4, R4, R0, R4   # 0x110a
        C_CHWIDTH        R4, 0   # 0x110e
        MOV_P            R5, 0, R4, R4, R4   # 0x1110
        SHRI             R4, R1, 22   # 0x1114
        C_XOR            R4, R5   # 0x1118
        C_ANDI           R4, 1   # 0x111a
        SETP_NE_NPI      P0, R4, R4, 0   # 0x111c
        SHRI             R4, R5, 1   # 0x1120
        C_MOV            R5, R4   # 0x1124
        C_CHWIDTH        R4, 1   # 0x1126
        XOR              R4, R4, R0, R4   # 0x1128
        C_CHWIDTH        R4, 0   # 0x112c
        MOV_P            R5, 0, R4, R4, R4   # 0x112e
        AND              R2, R3, R2, R3   # 0x1132
        C_CHWIDTH        R2, 0   # 0x1136
        SHRI             R2, R2, 7   # 0x1138
        ANDI             R3, R5, 1   # 0x113c
        SETP_EQ_NP       P0, R2, R2, R3   # 0x1140
        SHRI             R2, R5, 1   # 0x1144
        C_MOV            R3, R2   # 0x1148
        C_CHWIDTH        R2, 1   # 0x114a
        XOR              R2, R2, R0, R2   # 0x114c
        C_CHWIDTH        R2, 0   # 0x1150
        MOV_P            R2, 0, R3, R3, R3   # 0x1152
        SHRI             R3, R1, 24   # 0x1156
        XOR              R3, R2, R3, R2   # 0x115a
        C_ANDI           R3, 1   # 0x115e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1160
        SHRI             R2, R2, 1   # 0x1164
        C_MOV            R3, R2   # 0x1168
        C_CHWIDTH        R2, 1   # 0x116a
        XOR              R2, R2, R0, R2   # 0x116c
        C_CHWIDTH        R2, 0   # 0x1170
        MOV_P            R3, 0, R2, R2, R2   # 0x1172
        SHRI             R2, R1, 25   # 0x1176
        C_XOR            R2, R3   # 0x117a
        C_ANDI           R2, 1   # 0x117c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x117e
        SHRI             R2, R3, 1   # 0x1182
        C_MOV            R3, R2   # 0x1186
        C_CHWIDTH        R2, 1   # 0x1188
        XOR              R2, R2, R0, R2   # 0x118a
        C_CHWIDTH        R2, 0   # 0x118e
        MOV_P            R3, 0, R2, R2, R2   # 0x1190
        SHRI             R2, R1, 26   # 0x1194
        C_XOR            R2, R3   # 0x1198
        C_ANDI           R2, 1   # 0x119a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x119c
        SHRI             R2, R3, 1   # 0x11a0
        C_MOV            R3, R2   # 0x11a4
        C_CHWIDTH        R2, 1   # 0x11a6
        XOR              R2, R2, R0, R2   # 0x11a8
        C_CHWIDTH        R2, 0   # 0x11ac
        MOV_P            R3, 0, R2, R2, R2   # 0x11ae
        SHRI             R2, R1, 27   # 0x11b2
        C_XOR            R2, R3   # 0x11b6
        C_ANDI           R2, 1   # 0x11b8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11ba
        SHRI             R2, R3, 1   # 0x11be
        C_MOV            R3, R2   # 0x11c2
        C_CHWIDTH        R2, 1   # 0x11c4
        XOR              R2, R2, R0, R2   # 0x11c6
        C_CHWIDTH        R2, 0   # 0x11ca
        MOV_P            R3, 0, R2, R2, R2   # 0x11cc
        SHRI             R2, R1, 28   # 0x11d0
        C_XOR            R2, R3   # 0x11d4
        C_ANDI           R2, 1   # 0x11d6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11d8
        SHRI             R2, R3, 1   # 0x11dc
        C_MOV            R3, R2   # 0x11e0
        C_CHWIDTH        R2, 1   # 0x11e2
        XOR              R2, R2, R0, R2   # 0x11e4
        C_CHWIDTH        R2, 0   # 0x11e8
        MOV_P            R3, 0, R2, R2, R2   # 0x11ea
        SHRI             R2, R1, 29   # 0x11ee
        C_XOR            R2, R3   # 0x11f2
        C_ANDI           R2, 1   # 0x11f4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11f6
        SHRI             R2, R3, 1   # 0x11fa
        C_MOV            R3, R2   # 0x11fe
        C_CHWIDTH        R2, 1   # 0x1200
        XOR              R2, R2, R0, R2   # 0x1202
        C_CHWIDTH        R2, 0   # 0x1206
        MOV_P            R3, 0, R2, R2, R2   # 0x1208
        SHRI             R2, R1, 30   # 0x120c
        C_XOR            R2, R3   # 0x1210
        C_ANDI           R2, 1   # 0x1212
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1214
        SHRI             R2, R3, 1   # 0x1218
        C_MOV            R3, R2   # 0x121c
        C_CHWIDTH        R2, 1   # 0x121e
        XOR              R2, R2, R0, R2   # 0x1220
        C_CHWIDTH        R0, 1   # 0x1224
        C_CHWIDTH        R2, 0   # 0x1226
        MOV_P            R3, 0, R2, R2, R2   # 0x1228
        SHRI             R1, R1, 31   # 0x122c
        ANDI             R2, R3, 1   # 0x1230
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1234
        SHRI             R1, R3, 1   # 0x1238
        C_MOV            R2, R1   # 0x123c
        XOR              R0, R1, R0, R1   # 0x123e
        C_CHWIDTH        R0, 0   # 0x1242
        MOV_P            R0, 0, R2, R2, R2   # 0x1244
        MOVI             R1, 65535   # 0x1248
        AND              R1, R0, R1, R0   # 0x124c
        C_RET            224   # 0x1250
        ST_GLOBAL        R8, R15, -8   # 0x1252
        ST_GLOBAL        R9, R15, -12   # 0x1256
        ST_GLOBAL        R10, R15, -16   # 0x125a
        ST_GLOBAL        R11, R15, -20   # 0x125e
        ST_GLOBAL        R12, R15, -24   # 0x1262
        ST_GLOBAL        R13, R15, -28   # 0x1266
        ST_GLOBAL        R14, R15, -100   # 0x126a
        C_MOV            R13, R3   # 0x126e
        ST_GLOBAL        R1, R15, -88   # 0x1270
        MOVI             R1, 0   # 0x1274
        ST_GLOBAL        R1, R15, -32   # 0x1278
        ST_GLOBAL        R1, R15, -36   # 0x127c
        ST_GLOBAL        R1, R15, -40   # 0x1280
        ST_GLOBAL        R1, R15, -44   # 0x1284
        ST_GLOBAL        R1, R15, -48   # 0x1288
        ST_GLOBAL        R1, R15, -52   # 0x128c
        ST_GLOBAL        R1, R15, -56   # 0x1290
        MOVI             R0, 0   # 0x1294
        ST_GLOBAL        R0, R15, -96   # 0x1298
        C_CHWIDTH        R0, 2   # 0x129c
        ST_GLOBAL        R1, R15, -60   # 0x129e
        C_CHWIDTH        R1, 1   # 0x12a2
        LD_GLOBAL_IDX    R0, R2, R13, 0, 0   # 0x12a4
        C_CHWIDTH        R0, 0   # 0x12a8
        LD_GLOBAL        R1, R15, -4   # 0x12aa
        C_CHWIDTH        R1, 0   # 0x12ae
        ST_GLOBAL        R1, R15, -104   # 0x12b0
        C_MOV            R14, R0   # 0x12b4
        ANDI             R0, R0, 255   # 0x12b6
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x12ba
        MOVI             R7, 0   # 0x12be
        MOVI             R0, 0   # 0x12c2
        ST_GLOBAL        R0, R15, -72   # 0x12c6
        ST_GLOBAL        R0, R15, -84   # 0x12ca
        ST_GLOBAL        R0, R15, -64   # 0x12ce
        ST_GLOBAL        R0, R15, -80   # 0x12d2
        ST_GLOBAL        R0, R15, -76   # 0x12d6
        ST_GLOBAL        R5, R15, -92   # 0x12da
        BRA_PRED         0, L1558   # 0x12de
        ST_GLOBAL        R6, R15, -108   # 0x12e2
        MOVI             R0, 255   # 0x12e6
        MOVI             R6, 3   # 0x12ea
        MOVI             R9, 5   # 0x12ee
        MOVI             R1, 0   # 0x12f2
        ST_GLOBAL        R1, R15, -68   # 0x12f6
        ST_GLOBAL        R1, R15, -72   # 0x12fa
        MOVI             R5, 0   # 0x12fe
        ST_GLOBAL        R1, R15, -64   # 0x1302
        ST_GLOBAL        R1, R15, -80   # 0x1306
        ST_GLOBAL        R1, R15, -76   # 0x130a
        ST_GLOBAL        R1, R15, -84   # 0x130e
        C_MOV            R3, R14   # 0x1312
        MOVI             R10, 0   # 0x1314
        C_MOV            R11, R13   # 0x1318
        C_BRA            L131e   # 0x131a
L131c:  C_MOV            R11, R1   # 0x131c
L131e:  C_CHWIDTH        R8, 1   # 0x131e
        AND              R8, R3, R0, R3   # 0x1320
        C_CHWIDTH        R8, 0   # 0x1324
        SETP_NE_NPI      P0, R1, R8, 44   # 0x1326
        ADDI             R1, R11, 1   # 0x132a
        BRA_PRED         0, L1356   # 0x132e
L1332:  LD_GLOBAL_IDX    R3, R15, R10, 1, -60   # 0x1332
        C_ADDI           R3, 1   # 0x1336
        ST_GLOBAL_IDX    R3, R15, R10, 1, -60   # 0x1338
        C_CHWIDTH        R3, 2   # 0x133c
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x133e
        C_CHWIDTH        R3, 0   # 0x1342
        ANDI             R8, R3, 255   # 0x1344
        SETP_EQ_NPI      P0, R8, R8, 0   # 0x1348
        BRA_PRED         0, L1544   # 0x134c
        MOVI             R10, 0   # 0x1350
        C_BRA            L131c   # 0x1354
L1356:  SETP_LT_NP       P0, R12, R6, R10   # 0x1356
        BRA_PRED         4, L1392   # 0x135a
        SETP_LT_NP       P0, R12, R9, R10   # 0x135e
        BRA_PRED         0, L13c4   # 0x1362
        SETP_EQ_NPI      P0, R12, R10, 4   # 0x1366
        BRA_PRED         0, L1440   # 0x136a
        SETP_EQ_NPI      P0, R8, R10, 5   # 0x136e
        BRA_PRED         4, L1524   # 0x1372
        MOVI             R8, 223   # 0x1376
        C_CHWIDTH        R8, 1   # 0x137a
        AND              R8, R3, R8, R3   # 0x137c
        C_CHWIDTH        R8, 0   # 0x1380
        SETP_NE_NPI      P0, R8, R8, 69   # 0x1382
        BRA_PRED         0, L14c4   # 0x1386
        MOVI             R10, 3   # 0x138a
        BRA              L14e4   # 0x138e
L1392:  SETP_EQ_NPI      P0, R12, R10, 0   # 0x1392
        BRA_PRED         0, L1402   # 0x1396
        SETP_EQ_NPI      P0, R12, R10, 2   # 0x139a
        BRA_PRED         0, L1472   # 0x139e
        SETP_EQ_NPI      P0, R3, R10, 3   # 0x13a2
        BRA_PRED         4, L1524   # 0x13a6
        SETP_EQ_NPI      P0, R3, R8, 45   # 0x13aa
        BRA_PRED         0, L13ba   # 0x13ae
        SETP_NE_NPI      P0, R3, R8, 43   # 0x13b2
        BRA_PRED         0, L1500   # 0x13b6
L13ba:  MOVI             R10, 6   # 0x13ba
        C_ADDI           R5, 1   # 0x13be
        BRA              L1524   # 0x13c0
L13c4:  SETP_EQ_NPI      P0, R8, R10, 6   # 0x13c4
        BRA_PRED         0, L144e   # 0x13c8
        SETP_EQ_NPI      P0, R8, R10, 7   # 0x13cc
        BRA_PRED         4, L1524   # 0x13d0
        C_CHWIDTH        R3, 1   # 0x13d4
        ADDI             R3, R3, -58   # 0x13d6
        AND              R3, R3, R0, R3   # 0x13da
        C_CHWIDTH        R3, 0   # 0x13de
        MOVI             R8, 245   # 0x13e0
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x13e4
        MOVI             R10, 7   # 0x13e8
        BRA_PRED         0, L1524   # 0x13ec
        MOVI             R10, 1   # 0x13f0
        LD_GLOBAL        R3, R15, -80   # 0x13f4
        C_ADDI           R3, 1   # 0x13f8
        ST_GLOBAL        R3, R15, -80   # 0x13fa
        BRA              L1524   # 0x13fe
L1402:  C_CHWIDTH        R3, 1   # 0x1402
        ADDI             R3, R3, -58   # 0x1404
        AND              R3, R3, R0, R3   # 0x1408
        C_CHWIDTH        R3, 0   # 0x140c
        MOVI             R10, 245   # 0x140e
        SETP_LT_U_NP     P0, R3, R10, R3   # 0x1412
        MOVI             R10, 4   # 0x1416
        BRA_PRED         0, L1516   # 0x141a
        MOVI             R10, 2   # 0x141e
        SETP_EQ_NPI      P0, R3, R8, 43   # 0x1422
        BRA_PRED         0, L1516   # 0x1426
        SETP_EQ_NPI      P0, R3, R8, 45   # 0x142a
        BRA_PRED         0, L1516   # 0x142e
        SETP_NE_NPI      P0, R3, R8, 46   # 0x1432
        BRA_PRED         0, L1508   # 0x1436
        MOVI             R10, 5   # 0x143a
        C_BRA            L1516   # 0x143e
L1440:  SETP_NE_NPI      P0, R8, R8, 46   # 0x1440
        BRA_PRED         0, L1498   # 0x1444
        MOVI             R10, 5   # 0x1448
        C_BRA            L14b8   # 0x144c
L144e:  C_CHWIDTH        R3, 1   # 0x144e
        ADDI             R3, R3, -58   # 0x1450
        AND              R3, R3, R0, R3   # 0x1454
        C_CHWIDTH        R3, 0   # 0x1458
        MOVI             R8, 246   # 0x145a
        SETP_LT_U_NP     P0, R3, R3, R8   # 0x145e
        MOVI             R10, 7   # 0x1462
        MOVI             R3, 1   # 0x1466
        MOV_P            R10, 0, R3, R3, R3   # 0x146a
        C_ADDI           R7, 1   # 0x146e
        C_BRA            L1524   # 0x1470
L1472:  C_CHWIDTH        R3, 1   # 0x1472
        ADDI             R3, R3, -58   # 0x1474
        AND              R3, R3, R0, R3   # 0x1478
        C_CHWIDTH        R3, 0   # 0x147c
        MOVI             R10, 246   # 0x147e
        SETP_LT_U_NP     P0, R3, R3, R10   # 0x1482
        BRA_PRED         4, L14f0   # 0x1486
        SETP_EQ_NPI      P0, R3, R8, 46   # 0x148a
        MOVI             R10, 1   # 0x148e
        MOV_P            R10, 0, R9, R9, R9   # 0x1492
        C_BRA            L14f4   # 0x1496
L1498:  C_CHWIDTH        R3, 1   # 0x1498
        ADDI             R3, R3, -58   # 0x149a
        AND              R3, R3, R0, R3   # 0x149e
        C_CHWIDTH        R3, 0   # 0x14a2
        MOVI             R8, 245   # 0x14a4
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x14a8
        MOVI             R10, 4   # 0x14ac
        BRA_PRED         0, L1524   # 0x14b0
        MOVI             R10, 1   # 0x14b4
L14b8:  LD_GLOBAL        R3, R15, -72   # 0x14b8
        C_ADDI           R3, 1   # 0x14bc
        ST_GLOBAL        R3, R15, -72   # 0x14be
        C_BRA            L1524   # 0x14c2
L14c4:  C_CHWIDTH        R3, 1   # 0x14c4
        ADDI             R3, R3, -58   # 0x14c6
        AND              R3, R3, R0, R3   # 0x14ca
        C_CHWIDTH        R3, 0   # 0x14ce
        MOVI             R8, 245   # 0x14d0
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x14d4
        MOVI             R10, 5   # 0x14d8
        BRA_PRED         0, L1524   # 0x14dc
        MOVI             R10, 1   # 0x14e0
L14e4:  LD_GLOBAL        R3, R15, -68   # 0x14e4
        C_ADDI           R3, 1   # 0x14e8
        ST_GLOBAL        R3, R15, -68   # 0x14ea
        C_BRA            L1524   # 0x14ee
L14f0:  MOVI             R10, 4   # 0x14f0
L14f4:  LD_GLOBAL        R3, R15, -64   # 0x14f4
        C_ADDI           R3, 1   # 0x14f8
        ST_GLOBAL        R3, R15, -64   # 0x14fa
        C_BRA            L1524   # 0x14fe
L1500:  MOVI             R10, 1   # 0x1500
        C_ADDI           R5, 1   # 0x1504
        C_BRA            L1524   # 0x1506
L1508:  MOVI             R10, 1   # 0x1508
        LD_GLOBAL        R3, R15, -80   # 0x150c
        C_ADDI           R3, 1   # 0x1510
        ST_GLOBAL        R3, R15, -80   # 0x1512
L1516:  LD_GLOBAL        R3, R15, -84   # 0x1516
        C_ADDI           R3, 1   # 0x151a
        ST_GLOBAL        R3, R15, -76   # 0x151c
        ST_GLOBAL        R3, R15, -84   # 0x1520
L1524:  C_CHWIDTH        R3, 2   # 0x1524
        LD_GLOBAL_IDX    R3, R2, R11, 0, 1   # 0x1526
        C_CHWIDTH        R3, 0   # 0x152a
        ANDI             R8, R3, 255   # 0x152c
        SETP_EQ_NPI      P0, R8, R8, 0   # 0x1530
        BRA_PRED         0, L1332   # 0x1534
        SETP_EQ_NPI      P0, R8, R10, 1   # 0x1538
        BRA_PRED         4, L131c   # 0x153c
        BRA              L1332   # 0x1540
L1544:  ST_GLOBAL        R7, R15, -96   # 0x1544
        ST_GLOBAL        R5, R15, -84   # 0x1548
        LD_GLOBAL        R5, R15, -92   # 0x154c
        LD_GLOBAL        R7, R15, -68   # 0x1550
        LD_GLOBAL        R6, R15, -108   # 0x1554
L1558:  C_CHWIDTH        R6, 1   # 0x1558
        LD_GLOBAL        R1, R15, -88   # 0x155a
        SETP_EQ_NPI      P0, R0, R1, 0   # 0x155e
        SHLI             R0, R2, 16   # 0x1562
        CVT_SEXT         R12, R6, R6, R6   # 0x1566
        C_CHWIDTH        R6, 0   # 0x156a
        ADD              R6, R13, R1, R13   # 0x156c
        SHRI             R8, R2, 16   # 0x1570
        BRA_PRED         0, L160a   # 0x1574
        ADD              R3, R13, R0, R13   # 0x1578
        ADD              R1, R12, R0, R12   # 0x157c
        C_ADD            R3, R12   # 0x1580
        C_NOT            R3, R3   # 0x1582
        C_MOV            R9, R13   # 0x1584
L1586:  C_CHWIDTH        R14, 2   # 0x1586
        LD_GLOBAL_IDX    R14, R2, R9, 0, 0   # 0x1588
        C_CHWIDTH        R14, 0   # 0x158c
        ANDI             R10, R14, 255   # 0x158e
        SETP_EQ_NPI      P0, R10, R10, 44   # 0x1592
        BRA_PRED         0, L15a6   # 0x1596
        C_CHWIDTH        R14, 1   # 0x159a
        XOR              R14, R14, R4, R14   # 0x159c
        C_CHWIDTH        R14, 2   # 0x15a0
        ST_GLOBAL_IDX    R14, R2, R9, 0, 0   # 0x15a2
L15a6:  C_CHWIDTH        R14, 0   # 0x15a6
        ADD              R14, R12, R9, R12   # 0x15a8
        OR               R10, R0, R14, R0   # 0x15ac
        C_AND            R10, R3   # 0x15b0
        AND              R11, R0, R14, R0   # 0x15b2
        OR               R10, R11, R10, R11   # 0x15b6
        ADD              R9, R1, R9, R1   # 0x15ba
        ADD              R11, R0, R6, R0   # 0x15be
        SETP_LT_U_NP     P0, R9, R9, R11   # 0x15c2
        OR               R9, R0, R6, R0   # 0x15c6
        C_ANDN           R9, R11   # 0x15ca
        AND              R11, R0, R6, R0   # 0x15cc
        OR               R9, R11, R9, R11   # 0x15d0
        SHRI             R9, R9, 31   # 0x15d4
        SHRI             R10, R10, 31   # 0x15d8
        SETP_EQ_NP       P1, R11, R10, R9   # 0x15dc
        ADD              R9, R8, R9, R8   # 0x15e0
        ADD              R10, R8, R10, R8   # 0x15e4
        SETP_LT_U_NP     P2, R9, R10, R9   # 0x15e8
        C_SUB            R3, R12   # 0x15ec
        C_MOV            R9, R14   # 0x15ee
        BRA_PRED         2, L1586   # 0x15f0
        PAND             P0, 1, 0   # 0x15f4
        C_MOV            R9, R14   # 0x15f6
        BRA_PRED         0, L1586   # 0x15f8
        C_CHWIDTH        R1, 2   # 0x15fc
        LD_GLOBAL_IDX    R1, R2, R13, 0, 0   # 0x15fe
        C_CHWIDTH        R1, 0   # 0x1602
        C_MOV            R14, R1   # 0x1604
        LD_GLOBAL        R5, R15, -92   # 0x1606
L160a:  ST_GLOBAL        R7, R15, -68   # 0x160a
        MOVI             R1, 255   # 0x160e
        C_CHWIDTH        R1, 1   # 0x1612
        AND              R1, R14, R1, R14   # 0x1614
        C_CHWIDTH        R1, 0   # 0x1618
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x161a
        BRA_PRED         0, L1880   # 0x161e
        MOVI             R10, 0   # 0x1622
        MOVI             R4, 255   # 0x1626
        MOVI             R5, 3   # 0x162a
        C_MOV            R3, R13   # 0x162e
        LD_GLOBAL        R7, R15, -96   # 0x1630
        C_BRA            L163a   # 0x1634
L1636:  C_MOV            R14, R1   # 0x1636
        C_MOV            R3, R11   # 0x1638
L163a:  C_CHWIDTH        R1, 1   # 0x163a
        AND              R1, R14, R4, R14   # 0x163c
        C_CHWIDTH        R1, 0   # 0x1640
        SETP_NE_NPI      P0, R11, R1, 44   # 0x1642
        ADDI             R11, R3, 1   # 0x1646
        BRA_PRED         0, L1672   # 0x164a
L164e:  LD_GLOBAL_IDX    R1, R15, R10, 1, -60   # 0x164e
        C_ADDI           R1, 1   # 0x1652
        ST_GLOBAL_IDX    R1, R15, R10, 1, -60   # 0x1654
        C_CHWIDTH        R1, 2   # 0x1658
        LD_GLOBAL_IDX    R1, R2, R11, 0, 0   # 0x165a
        C_CHWIDTH        R1, 0   # 0x165e
        ANDI             R3, R1, 255   # 0x1660
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1664
        BRA_PRED         0, L187a   # 0x1668
        MOVI             R10, 0   # 0x166c
        C_BRA            L1636   # 0x1670
L1672:  SETP_LT_NP       P0, R9, R5, R10   # 0x1672
        BRA_PRED         4, L16b2   # 0x1676
        MOVI             R9, 5   # 0x167a
        SETP_LT_NP       P0, R9, R9, R10   # 0x167e
        BRA_PRED         0, L16e2   # 0x1682
        SETP_EQ_NPI      P0, R9, R10, 4   # 0x1686
        BRA_PRED         0, L1762   # 0x168a
        SETP_EQ_NPI      P0, R1, R10, 5   # 0x168e
        BRA_PRED         4, L185a   # 0x1692
        MOVI             R1, 223   # 0x1696
        C_CHWIDTH        R1, 1   # 0x169a
        AND              R1, R14, R1, R14   # 0x169c
        C_CHWIDTH        R1, 0   # 0x16a0
        SETP_NE_NPI      P0, R1, R1, 69   # 0x16a2
        BRA_PRED         0, L17f2   # 0x16a6
        MOVI             R10, 3   # 0x16aa
        BRA              L1816   # 0x16ae
L16b2:  SETP_EQ_NPI      P0, R9, R10, 0   # 0x16b2
        BRA_PRED         0, L1724   # 0x16b6
        SETP_EQ_NPI      P0, R9, R10, 2   # 0x16ba
        BRA_PRED         0, L1798   # 0x16be
        SETP_EQ_NPI      P0, R14, R10, 3   # 0x16c2
        BRA_PRED         4, L185a   # 0x16c6
        SETP_EQ_NPI      P0, R14, R1, 45   # 0x16ca
        BRA_PRED         0, L16da   # 0x16ce
        SETP_NE_NPI      P0, R1, R1, 43   # 0x16d2
        BRA_PRED         0, L1832   # 0x16d6
L16da:  MOVI             R10, 6   # 0x16da
        BRA              L1836   # 0x16de
L16e2:  SETP_EQ_NPI      P0, R1, R10, 6   # 0x16e2
        BRA_PRED         0, L1770   # 0x16e6
        SETP_EQ_NPI      P0, R1, R10, 7   # 0x16ea
        BRA_PRED         4, L185a   # 0x16ee
        CHWIDTH_MULTI    16386, 1   # 0x16f2
        ADDI             R14, R14, -58   # 0x16f6
        AND              R1, R14, R4, R14   # 0x16fa
        CHWIDTH_MULTI    16386, 0   # 0x16fe
        MOVI             R14, 245   # 0x1702
        SETP_LT_U_NP     P0, R1, R14, R1   # 0x1706
        MOVI             R10, 7   # 0x170a
        BRA_PRED         0, L185a   # 0x170e
        MOVI             R10, 1   # 0x1712
        LD_GLOBAL        R1, R15, -80   # 0x1716
        C_ADDI           R1, 1   # 0x171a
        ST_GLOBAL        R1, R15, -80   # 0x171c
        BRA              L185a   # 0x1720
L1724:  C_CHWIDTH        R14, 1   # 0x1724
        ADDI             R14, R14, -58   # 0x1726
        AND              R14, R14, R4, R14   # 0x172a
        C_CHWIDTH        R14, 0   # 0x172e
        MOVI             R9, 245   # 0x1730
        SETP_LT_U_NP     P0, R14, R9, R14   # 0x1734
        MOVI             R10, 4   # 0x1738
        BRA_PRED         0, L1850   # 0x173c
        MOVI             R10, 2   # 0x1740
        SETP_EQ_NPI      P0, R14, R1, 43   # 0x1744
        BRA_PRED         0, L1850   # 0x1748
        SETP_EQ_NPI      P0, R14, R1, 45   # 0x174c
        BRA_PRED         0, L1850   # 0x1750
        SETP_NE_NPI      P0, R1, R1, 46   # 0x1754
        BRA_PRED         0, L1842   # 0x1758
        MOVI             R10, 5   # 0x175c
        C_BRA            L1850   # 0x1760
L1762:  SETP_NE_NPI      P0, R1, R1, 46   # 0x1762
        BRA_PRED         0, L17c2   # 0x1766
        MOVI             R10, 5   # 0x176a
        C_BRA            L17e6   # 0x176e
L1770:  CHWIDTH_MULTI    16386, 1   # 0x1770
        ADDI             R14, R14, -58   # 0x1774
        AND              R1, R14, R4, R14   # 0x1778
        CHWIDTH_MULTI    16386, 0   # 0x177c
        MOVI             R14, 246   # 0x1780
        SETP_LT_U_NP     P0, R1, R1, R14   # 0x1784
        MOVI             R10, 7   # 0x1788
        MOVI             R1, 1   # 0x178c
        MOV_P            R10, 0, R1, R1, R1   # 0x1790
        C_ADDI           R7, 1   # 0x1794
        C_BRA            L185a   # 0x1796
L1798:  C_CHWIDTH        R14, 1   # 0x1798
        ADDI             R14, R14, -58   # 0x179a
        AND              R14, R14, R4, R14   # 0x179e
        C_CHWIDTH        R14, 0   # 0x17a2
        MOVI             R9, 246   # 0x17a4
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x17a8
        BRA_PRED         4, L1822   # 0x17ac
        SETP_EQ_NPI      P0, R1, R1, 46   # 0x17b0
        MOVI             R10, 1   # 0x17b4
        MOVI             R1, 5   # 0x17b8
        MOV_P            R10, 0, R1, R1, R1   # 0x17bc
        C_BRA            L1826   # 0x17c0
L17c2:  CHWIDTH_MULTI    16386, 1   # 0x17c2
        ADDI             R14, R14, -58   # 0x17c6
        AND              R1, R14, R4, R14   # 0x17ca
        CHWIDTH_MULTI    16386, 0   # 0x17ce
        MOVI             R14, 245   # 0x17d2
        SETP_LT_U_NP     P0, R1, R14, R1   # 0x17d6
        MOVI             R10, 4   # 0x17da
        BRA_PRED         0, L185a   # 0x17de
        MOVI             R10, 1   # 0x17e2
L17e6:  LD_GLOBAL        R1, R15, -72   # 0x17e6
        C_ADDI           R1, 1   # 0x17ea
        ST_GLOBAL        R1, R15, -72   # 0x17ec
        C_BRA            L185a   # 0x17f0
L17f2:  CHWIDTH_MULTI    16386, 1   # 0x17f2
        ADDI             R14, R14, -58   # 0x17f6
        AND              R1, R14, R4, R14   # 0x17fa
        CHWIDTH_MULTI    16386, 0   # 0x17fe
        MOVI             R14, 245   # 0x1802
        SETP_LT_U_NP     P0, R1, R14, R1   # 0x1806
        MOVI             R10, 5   # 0x180a
        BRA_PRED         0, L185a   # 0x180e
        MOVI             R10, 1   # 0x1812
L1816:  LD_GLOBAL        R1, R15, -68   # 0x1816
        C_ADDI           R1, 1   # 0x181a
        ST_GLOBAL        R1, R15, -68   # 0x181c
        C_BRA            L185a   # 0x1820
L1822:  MOVI             R10, 4   # 0x1822
L1826:  LD_GLOBAL        R1, R15, -64   # 0x1826
        C_ADDI           R1, 1   # 0x182a
        ST_GLOBAL        R1, R15, -64   # 0x182c
        C_BRA            L185a   # 0x1830
L1832:  MOVI             R10, 1   # 0x1832
L1836:  LD_GLOBAL        R1, R15, -84   # 0x1836
        C_ADDI           R1, 1   # 0x183a
        ST_GLOBAL        R1, R15, -84   # 0x183c
        C_BRA            L185a   # 0x1840
L1842:  MOVI             R10, 1   # 0x1842
        LD_GLOBAL        R1, R15, -80   # 0x1846
        C_ADDI           R1, 1   # 0x184a
        ST_GLOBAL        R1, R15, -80   # 0x184c
L1850:  LD_GLOBAL        R1, R15, -76   # 0x1850
        C_ADDI           R1, 1   # 0x1854
        ST_GLOBAL        R1, R15, -76   # 0x1856
L185a:  C_CHWIDTH        R1, 2   # 0x185a
        LD_GLOBAL_IDX    R1, R2, R3, 0, 1   # 0x185c
        C_CHWIDTH        R1, 0   # 0x1860
        ANDI             R3, R1, 255   # 0x1862
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1866
        BRA_PRED         0, L164e   # 0x186a
        SETP_EQ_NPI      P0, R3, R10, 1   # 0x186e
        BRA_PRED         4, L1636   # 0x1872
        BRA              L164e   # 0x1876
L187a:  LD_GLOBAL        R5, R15, -92   # 0x187a
        C_BRA            L1884   # 0x187e
L1880:  LD_GLOBAL        R7, R15, -96   # 0x1880
L1884:  LD_GLOBAL        R1, R15, -88   # 0x1884
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x1888
        BRA_PRED         0, L1914   # 0x188c
        ADD              R3, R13, R0, R13   # 0x1890
        ADD              R1, R12, R0, R12   # 0x1894
        C_ADD            R3, R12   # 0x1898
        C_NOT            R3, R3   # 0x189a
L189c:  C_CHWIDTH        R4, 2   # 0x189c
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x189e
        C_CHWIDTH        R4, 0   # 0x18a2
        ANDI             R14, R4, 255   # 0x18a4
        SETP_EQ_NPI      P0, R14, R14, 44   # 0x18a8
        BRA_PRED         0, L18bc   # 0x18ac
        C_CHWIDTH        R4, 1   # 0x18b0
        XOR              R4, R4, R5, R4   # 0x18b2
        C_CHWIDTH        R4, 2   # 0x18b6
        ST_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x18b8
L18bc:  C_CHWIDTH        R4, 0   # 0x18bc
        ADD              R4, R12, R13, R12   # 0x18be
        OR               R14, R0, R4, R0   # 0x18c2
        AND              R9, R14, R3, R14   # 0x18c6
        AND              R14, R0, R4, R0   # 0x18ca
        OR               R10, R14, R9, R14   # 0x18ce
        ADD              R14, R1, R13, R1   # 0x18d2
        ADD              R9, R0, R6, R0   # 0x18d6
        SETP_LT_U_NP     P0, R14, R14, R9   # 0x18da
        OR               R14, R0, R6, R0   # 0x18de
        C_ANDN           R14, R9   # 0x18e2
        AND              R9, R0, R6, R0   # 0x18e4
        OR               R14, R9, R14, R9   # 0x18e8
        SHRI             R14, R14, 31   # 0x18ec
        SHRI             R10, R10, 31   # 0x18f0
        SETP_EQ_NP       P1, R9, R10, R14   # 0x18f4
        ADD              R14, R8, R14, R8   # 0x18f8
        ADD              R9, R8, R10, R8   # 0x18fc
        SETP_LT_U_NP     P2, R14, R9, R14   # 0x1900
        C_SUB            R3, R12   # 0x1904
        C_MOV            R13, R4   # 0x1906
        BRA_PRED         2, L189c   # 0x1908
        PAND             P0, 1, 0   # 0x190c
        C_MOV            R13, R4   # 0x190e
        BRA_PRED         0, L189c   # 0x1910
L1914:  LD_GLOBAL        R1, R15, -60   # 0x1914
        LD_GLOBAL        R2, R15, -104   # 0x1918
        CALL             R14, 129660   # 0x191c
        C_MOV            R2, R1   # 0x1920
        LD_GLOBAL        R1, R15, -76   # 0x1922
        CALL             R14, 129655   # 0x1926
        C_MOV            R2, R1   # 0x192a
        LD_GLOBAL        R1, R15, -56   # 0x192c
        CALL             R14, 129650   # 0x1930
        C_MOV            R2, R1   # 0x1934
        LD_GLOBAL        R1, R15, -80   # 0x1936
        CALL             R14, 129645   # 0x193a
        C_MOV            R2, R1   # 0x193e
        LD_GLOBAL        R1, R15, -52   # 0x1940
        CALL             R14, 129640   # 0x1944
        C_MOV            R2, R1   # 0x1948
        LD_GLOBAL        R1, R15, -64   # 0x194a
        CALL             R14, 129635   # 0x194e
        C_MOV            R2, R1   # 0x1952
        LD_GLOBAL        R1, R15, -48   # 0x1954
        CALL             R14, 129630   # 0x1958
        C_MOV            R2, R1   # 0x195c
        LD_GLOBAL        R1, R15, -84   # 0x195e
        CALL             R14, 129625   # 0x1962
        C_MOV            R2, R1   # 0x1966
        LD_GLOBAL        R1, R15, -44   # 0x1968
        CALL             R14, 129620   # 0x196c
        C_MOV            R2, R1   # 0x1970
        LD_GLOBAL        R1, R15, -72   # 0x1972
        CALL             R14, 129615   # 0x1976
        C_MOV            R2, R1   # 0x197a
        LD_GLOBAL        R1, R15, -40   # 0x197c
        CALL             R14, 129610   # 0x1980
        C_MOV            R2, R1   # 0x1984
        LD_GLOBAL        R1, R15, -68   # 0x1986
        CALL             R14, 129605   # 0x198a
        C_MOV            R2, R1   # 0x198e
        LD_GLOBAL        R1, R15, -36   # 0x1990
        CALL             R14, 129600   # 0x1994
        C_MOV            R2, R1   # 0x1998
        C_MOV            R1, R7   # 0x199a
        CALL             R14, 129596   # 0x199c
        C_MOV            R2, R1   # 0x19a0
        LD_GLOBAL        R1, R15, -32   # 0x19a2
        CALL             R14, 129591   # 0x19a6
        C_MOV            R2, R1   # 0x19aa
        MOVI             R1, 0   # 0x19ac
        CALL             R14, 129586   # 0x19b0
        LD_GLOBAL        R14, R15, -100   # 0x19b4
        LD_GLOBAL        R13, R15, -28   # 0x19b8
        LD_GLOBAL        R12, R15, -24   # 0x19bc
        LD_GLOBAL        R11, R15, -20   # 0x19c0
        LD_GLOBAL        R10, R15, -16   # 0x19c4
        LD_GLOBAL        R9, R15, -12   # 0x19c8
        LD_GLOBAL        R8, R15, -8   # 0x19cc
        C_RET            224   # 0x19d0
        C_CHWIDTH        R0, 1   # 0x19d2
        XOR              R0, R2, R1, R2   # 0x19d4
        C_CHWIDTH        R0, 0   # 0x19d8
        C_ANDI           R0, 1   # 0x19da
        SETP_NE_NPI      P0, R0, R0, 0   # 0x19dc
        MOVI             R0, 40961   # 0x19e0
        SHRI             R2, R2, 1   # 0x19e4
        C_MOV            R3, R2   # 0x19e8
        C_CHWIDTH        R2, 1   # 0x19ea
        XOR              R2, R2, R0, R2   # 0x19ec
        C_CHWIDTH        R2, 0   # 0x19f0
        MOV_P            R3, 0, R2, R2, R2   # 0x19f2
        SHRI             R2, R1, 1   # 0x19f6
        C_CHWIDTH        R2, 1   # 0x19fa
        XOR              R2, R2, R3, R2   # 0x19fc
        C_CHWIDTH        R2, 0   # 0x1a00
        C_ANDI           R2, 1   # 0x1a02
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1a04
        SHRI             R2, R3, 1   # 0x1a08
        C_MOV            R3, R2   # 0x1a0c
        C_CHWIDTH        R2, 1   # 0x1a0e
        XOR              R2, R2, R0, R2   # 0x1a10
        C_CHWIDTH        R2, 0   # 0x1a14
        MOV_P            R3, 0, R2, R2, R2   # 0x1a16
        SHRI             R2, R1, 2   # 0x1a1a
        C_CHWIDTH        R2, 1   # 0x1a1e
        XOR              R2, R2, R3, R2   # 0x1a20
        C_CHWIDTH        R2, 0   # 0x1a24
        C_ANDI           R2, 1   # 0x1a26
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1a28
        SHRI             R2, R3, 1   # 0x1a2c
        C_MOV            R3, R2   # 0x1a30
        C_CHWIDTH        R2, 1   # 0x1a32
        XOR              R2, R2, R0, R2   # 0x1a34
        C_CHWIDTH        R2, 0   # 0x1a38
        MOV_P            R3, 0, R2, R2, R2   # 0x1a3a
        SHRI             R2, R1, 3   # 0x1a3e
        C_CHWIDTH        R2, 1   # 0x1a42
        XOR              R2, R2, R3, R2   # 0x1a44
        C_CHWIDTH        R2, 0   # 0x1a48
        C_ANDI           R2, 1   # 0x1a4a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1a4c
        SHRI             R2, R3, 1   # 0x1a50
        C_MOV            R3, R2   # 0x1a54
        C_CHWIDTH        R2, 1   # 0x1a56
        XOR              R2, R2, R0, R2   # 0x1a58
        C_CHWIDTH        R2, 0   # 0x1a5c
        MOV_P            R3, 0, R2, R2, R2   # 0x1a5e
        SHRI             R2, R1, 4   # 0x1a62
        C_CHWIDTH        R2, 1   # 0x1a66
        XOR              R2, R2, R3, R2   # 0x1a68
        C_CHWIDTH        R2, 0   # 0x1a6c
        C_ANDI           R2, 1   # 0x1a6e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1a70
        SHRI             R2, R3, 1   # 0x1a74
        C_MOV            R3, R2   # 0x1a78
        C_CHWIDTH        R2, 1   # 0x1a7a
        XOR              R2, R2, R0, R2   # 0x1a7c
        C_CHWIDTH        R2, 0   # 0x1a80
        MOV_P            R3, 0, R2, R2, R2   # 0x1a82
        SHRI             R2, R1, 5   # 0x1a86
        C_CHWIDTH        R2, 1   # 0x1a8a
        XOR              R2, R2, R3, R2   # 0x1a8c
        C_CHWIDTH        R2, 0   # 0x1a90
        C_ANDI           R2, 1   # 0x1a92
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1a94
        SHRI             R2, R3, 1   # 0x1a98
        C_MOV            R3, R2   # 0x1a9c
        C_CHWIDTH        R2, 1   # 0x1a9e
        XOR              R2, R2, R0, R2   # 0x1aa0
        C_CHWIDTH        R2, 0   # 0x1aa4
        MOV_P            R3, 0, R2, R2, R2   # 0x1aa6
        SHRI             R2, R1, 6   # 0x1aaa
        C_CHWIDTH        R2, 1   # 0x1aae
        XOR              R2, R2, R3, R2   # 0x1ab0
        C_CHWIDTH        R2, 0   # 0x1ab4
        C_ANDI           R2, 1   # 0x1ab6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1ab8
        SHRI             R2, R3, 1   # 0x1abc
        C_MOV            R3, R2   # 0x1ac0
        C_CHWIDTH        R2, 1   # 0x1ac2
        XOR              R2, R2, R0, R2   # 0x1ac4
        C_CHWIDTH        R2, 0   # 0x1ac8
        MOV_P            R3, 0, R2, R2, R2   # 0x1aca
        MOVI             R2, 128   # 0x1ace
        C_CHWIDTH        R2, 1   # 0x1ad2
        AND              R2, R1, R2, R1   # 0x1ad4
        C_CHWIDTH        R2, 0   # 0x1ad8
        SHRI             R2, R2, 7   # 0x1ada
        ANDI             R4, R3, 1   # 0x1ade
        SETP_EQ_NP       P0, R2, R2, R4   # 0x1ae2
        SHRI             R2, R3, 1   # 0x1ae6
        C_MOV            R3, R2   # 0x1aea
        C_CHWIDTH        R2, 1   # 0x1aec
        XOR              R2, R2, R0, R2   # 0x1aee
        C_CHWIDTH        R2, 0   # 0x1af2
        MOV_P            R2, 0, R3, R3, R3   # 0x1af4
        SHRI             R3, R1, 8   # 0x1af8
        C_CHWIDTH        R3, 1   # 0x1afc
        XOR              R3, R2, R3, R2   # 0x1afe
        C_CHWIDTH        R3, 0   # 0x1b02
        C_ANDI           R3, 1   # 0x1b04
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1b06
        SHRI             R2, R2, 1   # 0x1b0a
        C_MOV            R3, R2   # 0x1b0e
        C_CHWIDTH        R2, 1   # 0x1b10
        XOR              R2, R2, R0, R2   # 0x1b12
        C_CHWIDTH        R2, 0   # 0x1b16
        MOV_P            R3, 0, R2, R2, R2   # 0x1b18
        SHRI             R2, R1, 9   # 0x1b1c
        C_CHWIDTH        R2, 1   # 0x1b20
        XOR              R2, R2, R3, R2   # 0x1b22
        C_CHWIDTH        R2, 0   # 0x1b26
        C_ANDI           R2, 1   # 0x1b28
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b2a
        SHRI             R2, R3, 1   # 0x1b2e
        C_MOV            R3, R2   # 0x1b32
        C_CHWIDTH        R2, 1   # 0x1b34
        XOR              R2, R2, R0, R2   # 0x1b36
        C_CHWIDTH        R2, 0   # 0x1b3a
        MOV_P            R3, 0, R2, R2, R2   # 0x1b3c
        SHRI             R2, R1, 10   # 0x1b40
        C_CHWIDTH        R2, 1   # 0x1b44
        XOR              R2, R2, R3, R2   # 0x1b46
        C_CHWIDTH        R2, 0   # 0x1b4a
        C_ANDI           R2, 1   # 0x1b4c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b4e
        SHRI             R2, R3, 1   # 0x1b52
        C_MOV            R3, R2   # 0x1b56
        C_CHWIDTH        R2, 1   # 0x1b58
        XOR              R2, R2, R0, R2   # 0x1b5a
        C_CHWIDTH        R2, 0   # 0x1b5e
        MOV_P            R3, 0, R2, R2, R2   # 0x1b60
        SHRI             R2, R1, 11   # 0x1b64
        C_CHWIDTH        R2, 1   # 0x1b68
        XOR              R2, R2, R3, R2   # 0x1b6a
        C_CHWIDTH        R2, 0   # 0x1b6e
        C_ANDI           R2, 1   # 0x1b70
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b72
        SHRI             R2, R3, 1   # 0x1b76
        C_MOV            R3, R2   # 0x1b7a
        C_CHWIDTH        R2, 1   # 0x1b7c
        XOR              R2, R2, R0, R2   # 0x1b7e
        C_CHWIDTH        R2, 0   # 0x1b82
        MOV_P            R3, 0, R2, R2, R2   # 0x1b84
        SHRI             R2, R1, 12   # 0x1b88
        C_CHWIDTH        R2, 1   # 0x1b8c
        XOR              R2, R2, R3, R2   # 0x1b8e
        C_CHWIDTH        R2, 0   # 0x1b92
        C_ANDI           R2, 1   # 0x1b94
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b96
        SHRI             R2, R3, 1   # 0x1b9a
        C_MOV            R3, R2   # 0x1b9e
        C_CHWIDTH        R2, 1   # 0x1ba0
        XOR              R2, R2, R0, R2   # 0x1ba2
        C_CHWIDTH        R2, 0   # 0x1ba6
        MOV_P            R3, 0, R2, R2, R2   # 0x1ba8
        SHRI             R2, R1, 13   # 0x1bac
        C_CHWIDTH        R2, 1   # 0x1bb0
        XOR              R2, R2, R3, R2   # 0x1bb2
        C_CHWIDTH        R2, 0   # 0x1bb6
        C_ANDI           R2, 1   # 0x1bb8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bba
        SHRI             R2, R3, 1   # 0x1bbe
        C_MOV            R3, R2   # 0x1bc2
        C_CHWIDTH        R2, 1   # 0x1bc4
        XOR              R2, R2, R0, R2   # 0x1bc6
        C_CHWIDTH        R2, 0   # 0x1bca
        MOV_P            R3, 0, R2, R2, R2   # 0x1bcc
        SHRI             R2, R1, 14   # 0x1bd0
        C_CHWIDTH        R2, 1   # 0x1bd4
        XOR              R2, R2, R3, R2   # 0x1bd6
        C_CHWIDTH        R2, 0   # 0x1bda
        C_ANDI           R2, 1   # 0x1bdc
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bde
        SHRI             R2, R3, 1   # 0x1be2
        C_MOV            R3, R2   # 0x1be6
        C_CHWIDTH        R2, 1   # 0x1be8
        XOR              R2, R2, R0, R2   # 0x1bea
        C_CHWIDTH        R0, 1   # 0x1bee
        C_CHWIDTH        R2, 0   # 0x1bf0
        MOV_P            R3, 0, R2, R2, R2   # 0x1bf2
        SHRI             R1, R1, 15   # 0x1bf6
        ANDI             R2, R3, 1   # 0x1bfa
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1bfe
        SHRI             R1, R3, 1   # 0x1c02
        C_MOV            R2, R1   # 0x1c06
        XOR              R0, R1, R0, R1   # 0x1c08
        C_CHWIDTH        R0, 0   # 0x1c0c
        MOV_P            R0, 0, R2, R2, R2   # 0x1c0e
        MOVI             R1, 65535   # 0x1c12
        AND              R1, R0, R1, R0   # 0x1c16
        C_RET            224   # 0x1c1a
        C_CHWIDTH        R7, 1   # 0x1c1c
        ST_GLOBAL        R8, R15, -4   # 0x1c1e
        ST_GLOBAL        R9, R15, -8   # 0x1c22
        ST_GLOBAL        R10, R15, -12   # 0x1c26
        ST_GLOBAL        R11, R15, -16   # 0x1c2a
        ST_GLOBAL        R12, R15, -20   # 0x1c2e
        ST_GLOBAL        R13, R15, -24   # 0x1c32
        ST_GLOBAL        R4, R15, -88   # 0x1c36
        C_MOV            R10, R3   # 0x1c3a
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x1c3c
        SHLI             R0, R0, 16   # 0x1c40
        ST_GLOBAL        R0, R15, -44   # 0x1c44
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x1c48
        ST_GLOBAL        R0, R15, -60   # 0x1c4c
        SHRI             R0, R0, 16   # 0x1c50
        ST_GLOBAL        R0, R15, -76   # 0x1c54
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x1c58
        SHLI             R0, R0, 16   # 0x1c5c
        LD_GLOBAL_IDX    R3, R1, R2, 0, 8   # 0x1c60
        SHRI             R4, R3, 16   # 0x1c64
        C_OR             R0, R4   # 0x1c68
        ST_GLOBAL        R0, R15, -56   # 0x1c6a
        LD_GLOBAL_IDX    R4, R1, R2, 0, 28   # 0x1c6e
        SHLI             R4, R4, 16   # 0x1c72
        LD_GLOBAL_IDX    R5, R1, R2, 0, 24   # 0x1c76
        SHRI             R6, R5, 16   # 0x1c7a
        C_OR             R4, R6   # 0x1c7e
        ST_GLOBAL        R4, R15, -40   # 0x1c80
        MOVI             R0, 65535   # 0x1c84
        AND              R12, R3, R0, R3   # 0x1c88
        AND              R9, R5, R0, R5   # 0x1c8c
        LD_GLOBAL_IDX    R3, R1, R2, 0, 0   # 0x1c90
        MOVI             R2, 0   # 0x1c94
        MOVI             R1, 61440   # 0x1c98
        OR               R7, R10, R1, R10   # 0x1c9c
        SETP_EQ_NPI      P0, R1, R3, 0   # 0x1ca0
        ANDI             R0, R3, -2   # 0x1ca4
        ST_GLOBAL        R0, R15, -36   # 0x1ca8
        ANDI             R0, R3, 1   # 0x1cac
        ST_GLOBAL        R0, R15, -52   # 0x1cb0
        ADDI             R13, R3, -1   # 0x1cb4
        CVT_SEXT         R0, R7, R7, R7   # 0x1cb8
        ST_GLOBAL        R0, R15, -64   # 0x1cbc
        ANDI             R1, R3, -4   # 0x1cc0
        ST_GLOBAL        R9, R15, -32   # 0x1cc4
        ST_GLOBAL        R13, R15, -48   # 0x1cc8
        ST_GLOBAL        R10, R15, -68   # 0x1ccc
        ST_GLOBAL        R1, R15, -72   # 0x1cd0
        ST_GLOBAL        R14, R15, -84   # 0x1cd4
        BRA_PRED         0, L2002   # 0x1cd8
        C_MOV            R8, R3   # 0x1cdc
        ANDI             R0, R3, 3   # 0x1cde
        ST_GLOBAL        R0, R15, -28   # 0x1ce2
        MOVI             R4, 0   # 0x1ce6
        LD_GLOBAL        R0, R15, -56   # 0x1cea
        C_BRA            L1cfe   # 0x1cee
L1cf0:  C_MOV            R3, R8   # 0x1cf0
        C_ADD            R2, R3   # 0x1cf2
        C_ADDI           R4, 1   # 0x1cf4
        SETP_NE_NP       P0, R3, R4, R3   # 0x1cf6
        BRA_PRED         4, L1d8e   # 0x1cfa
L1cfe:  MOVI             R3, 0   # 0x1cfe
        SETP_LT_U_NPI    P0, R5, R13, 3   # 0x1d02
        BRA_PRED         0, L1d58   # 0x1d06
L1d0a:  ADD              R5, R2, R3, R2   # 0x1d0a
        C_SHLI           R5, 1   # 0x1d0e
        ADD              R5, R12, R5, R12   # 0x1d10
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1d14
        ADD              R7, R7, R10, R7   # 0x1d18
        ST_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1d1c
        ADDI             R6, R5, 2   # 0x1d20
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x1d24
        ADD              R7, R7, R10, R7   # 0x1d28
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x1d2c
        ADDI             R6, R5, 4   # 0x1d30
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x1d34
        ADD              R7, R7, R10, R7   # 0x1d38
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x1d3c
        C_ADDI           R5, 6   # 0x1d40
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1d42
        ADD              R7, R7, R10, R7   # 0x1d46
        ST_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x1d4a
        C_ADDI           R3, 4   # 0x1d4e
        SETP_NE_NP       P0, R5, R1, R3   # 0x1d50
        BRA_PRED         0, L1d0a   # 0x1d54
L1d58:  LD_GLOBAL        R5, R15, -28   # 0x1d58
        SETP_EQ_NPI      P0, R5, R5, 0   # 0x1d5c
        BRA_PRED         0, L1cf0   # 0x1d60
        C_ADD            R3, R2   # 0x1d64
        LD_GLOBAL        R5, R15, -28   # 0x1d66
L1d6a:  C_MOV            R6, R3   # 0x1d6a
        C_SHLI           R6, 1   # 0x1d6c
        ADD              R6, R12, R6, R12   # 0x1d6e
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x1d72
        ADD              R7, R7, R10, R7   # 0x1d76
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x1d7a
        C_ADDI           R3, 1   # 0x1d7e
        ADDI             R5, R5, -1   # 0x1d80
        SETP_NE_NPI      P0, R6, R5, 0   # 0x1d84
        BRA_PRED         0, L1d6a   # 0x1d88
        C_BRA            L1cf0   # 0x1d8c
L1d8e:  MOVI             R2, 0   # 0x1d8e
        C_MOV            R1, R10   # 0x1d92
        C_CHWIDTH        R1, 1   # 0x1d94
        C_MOV            R3, R10   # 0x1d96
        C_CHWIDTH        R3, 1   # 0x1d98
        C_MOV            R5, R10   # 0x1d9a
        C_CHWIDTH        R10, 0   # 0x1d9c
        C_CHWIDTH        R5, 1   # 0x1d9e
        CVT_SEXT         R4, R1, R3, R5   # 0x1da0
        CHWIDTH_MULTI    42, 0   # 0x1da4
        MOVI             R5, 0   # 0x1da8
        C_MOV            R14, R8   # 0x1dac
        C_BRA            L1dc0   # 0x1dae
L1db0:  CHWIDTH_MULTI    2048, 0   # 0x1db0
        C_ADD            R2, R14   # 0x1db4
        C_ADDI           R5, 1   # 0x1db6
        SETP_NE_NP       P0, R3, R5, R14   # 0x1db8
        BRA_PRED         4, L1ebc   # 0x1dbc
L1dc0:  SETP_LT_U_NPI    P0, R3, R13, 3   # 0x1dc0
        MOVI             R3, 0   # 0x1dc4
        LD_GLOBAL        R1, R15, -40   # 0x1dc8
        LD_GLOBAL        R10, R15, -72   # 0x1dcc
        BRA_PRED         0, L1e76   # 0x1dd0
L1dd4:  C_CHWIDTH        R11, 1   # 0x1dd4
        C_CHWIDTH        R7, 0   # 0x1dd6
        ADD              R6, R2, R3, R2   # 0x1dd8
        C_MOV            R7, R6   # 0x1ddc
        C_SHLI           R7, 2   # 0x1dde
        ADD              R7, R9, R7, R9   # 0x1de0
        C_MOV            R8, R6   # 0x1de4
        C_SHLI           R8, 1   # 0x1de6
        ADD              R8, R12, R8, R12   # 0x1de8
        LD_GLOBAL_IDX    R11, R0, R8, 0, 0   # 0x1dec
        CVT_SEXT         R8, R11, R11, R11   # 0x1df0
        C_CHWIDTH        R11, 0   # 0x1df4
        C_MUL_LO         R8, R4   # 0x1df6
        ST_GLOBAL_IDX    R8, R1, R7, 0, 0   # 0x1df8
        ADDI             R7, R6, 1   # 0x1dfc
        C_MOV            R8, R7   # 0x1e00
        C_SHLI           R8, 2   # 0x1e02
        ADD              R8, R9, R8, R9   # 0x1e04
        C_SHLI           R7, 1   # 0x1e08
        ADD              R7, R12, R7, R12   # 0x1e0a
        C_CHWIDTH        R7, 1   # 0x1e0e
        LD_GLOBAL_IDX    R7, R0, R7, 0, 0   # 0x1e10
        CVT_SEXT         R11, R7, R7, R7   # 0x1e14
        C_CHWIDTH        R7, 0   # 0x1e18
        MUL_LO           R7, R11, R4, R4   # 0x1e1a
        ST_GLOBAL_IDX    R7, R1, R8, 0, 0   # 0x1e1e
        ADDI             R7, R6, 2   # 0x1e22
        C_MOV            R8, R7   # 0x1e26
        C_SHLI           R8, 2   # 0x1e28
        ADD              R8, R9, R8, R9   # 0x1e2a
        C_SHLI           R7, 1   # 0x1e2e
        ADD              R7, R12, R7, R12   # 0x1e30
        C_CHWIDTH        R7, 1   # 0x1e34
        LD_GLOBAL_IDX    R7, R0, R7, 0, 0   # 0x1e36
        CVT_SEXT         R11, R7, R7, R7   # 0x1e3a
        C_CHWIDTH        R7, 0   # 0x1e3e
        MUL_LO           R7, R11, R4, R4   # 0x1e40
        ST_GLOBAL_IDX    R7, R1, R8, 0, 0   # 0x1e44
        C_ADDI           R6, 3   # 0x1e48
        C_MOV            R7, R6   # 0x1e4a
        C_SHLI           R7, 2   # 0x1e4c
        ADD              R7, R9, R7, R9   # 0x1e4e
        C_SHLI           R6, 1   # 0x1e52
        ADD              R6, R12, R6, R12   # 0x1e54
        C_CHWIDTH        R6, 1   # 0x1e58
        LD_GLOBAL_IDX    R6, R0, R6, 0, 0   # 0x1e5a
        CVT_SEXT         R8, R6, R6, R6   # 0x1e5e
        C_CHWIDTH        R6, 0   # 0x1e62
        MUL_LO           R6, R8, R4, R4   # 0x1e64
        ST_GLOBAL_IDX    R6, R1, R7, 0, 0   # 0x1e68
        C_ADDI           R3, 4   # 0x1e6c
        SETP_NE_NP       P0, R6, R10, R3   # 0x1e6e
        BRA_PRED         0, L1dd4   # 0x1e72
L1e76:  LD_GLOBAL        R6, R15, -28   # 0x1e76
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x1e7a
        BRA_PRED         0, L1db0   # 0x1e7e
        C_ADD            R3, R2   # 0x1e82
        LD_GLOBAL        R6, R15, -28   # 0x1e84
L1e88:  C_CHWIDTH        R11, 1   # 0x1e88
        C_CHWIDTH        R7, 0   # 0x1e8a
        C_MOV            R7, R3   # 0x1e8c
        C_SHLI           R7, 2   # 0x1e8e
        ADD              R7, R9, R7, R9   # 0x1e90
        C_MOV            R8, R3   # 0x1e94
        C_SHLI           R8, 1   # 0x1e96
        ADD              R8, R12, R8, R12   # 0x1e98
        LD_GLOBAL_IDX    R11, R0, R8, 0, 0   # 0x1e9c
        CVT_SEXT         R8, R11, R11, R11   # 0x1ea0
        C_MUL_LO         R8, R4   # 0x1ea4
        ST_GLOBAL_IDX    R8, R1, R7, 0, 0   # 0x1ea6
        C_ADDI           R3, 1   # 0x1eaa
        ADDI             R6, R6, -1   # 0x1eac
        SETP_NE_NPI      P0, R7, R6, 0   # 0x1eb0
        BRA_PRED         0, L1e88   # 0x1eb4
        BRA              L1db0   # 0x1eb8
L1ebc:  MOVI             R1, 0   # 0x1ebc
        C_MOV            R8, R1   # 0x1ec0
        MOVI             R11, 10   # 0x1ec2
        MOVI             R5, 0   # 0x1ec6
        ST_GLOBAL        R1, R15, -28   # 0x1eca
        MOVI             R6, 0   # 0x1ece
        MOVI             R4, 0   # 0x1ed2
        C_BRA            L1ef2   # 0x1ed6
L1ed8:  C_MOV            R5, R13   # 0x1ed8
        C_ADD            R5, R14   # 0x1eda
        LD_GLOBAL        R1, R15, -28   # 0x1edc
        C_ADDI           R1, 1   # 0x1ee0
        ST_GLOBAL        R1, R15, -28   # 0x1ee2
        SETP_NE_NP       P0, R2, R1, R14   # 0x1ee6
        LD_GLOBAL        R13, R15, -48   # 0x1eea
        BRA_PRED         4, L200a   # 0x1eee
L1ef2:  SETP_EQ_NPI      P0, R3, R13, 0   # 0x1ef2
        BRA_PRED         0, L1f94   # 0x1ef6
        C_CHWIDTH        R7, 0   # 0x1efa
        MOVI             R7, 0   # 0x1efc
        C_MOV            R3, R6   # 0x1f00
        LD_GLOBAL        R9, R15, -40   # 0x1f02
        LD_GLOBAL        R1, R15, -32   # 0x1f06
        LD_GLOBAL        R1, R15, -36   # 0x1f0a
        LD_GLOBAL        R10, R15, -64   # 0x1f0e
L1f12:  C_CHWIDTH        R8, 1   # 0x1f12
        C_CHWIDTH        R2, 0   # 0x1f14
        ADD              R6, R5, R7, R5   # 0x1f16
        C_SHLI           R6, 2   # 0x1f1a
        MOVI             R1, 10   # 0x1f1c
        LD_GLOBAL        R2, R15, -32   # 0x1f20
        ADD              R11, R6, R2, R6   # 0x1f24
        ADDI             R6, R11, 4   # 0x1f28
        LD_GLOBAL_IDX    R6, R9, R6, 0, 0   # 0x1f2c
        LD_GLOBAL_IDX    R11, R9, R11, 0, 0   # 0x1f30
        SETP_LT_NP       P0, R3, R3, R11   # 0x1f34
        SETP_LT_NP       P1, R3, R11, R6   # 0x1f38
        MOVI             R3, 0   # 0x1f3c
        MOVI             R13, 1   # 0x1f40
        MOV_P            R3, 1, R13, R13, R13   # 0x1f44
        MOVI             R2, 0   # 0x1f48
        MOV_P            R2, 0, R13, R13, R13   # 0x1f4c
        ADD              R4, R11, R4, R11   # 0x1f50
        SETP_LT_NP       P0, R11, R10, R4   # 0x1f54
        MOV_P            R2, 0, R1, R1, R1   # 0x1f58
        C_CHWIDTH        R2, 1   # 0x1f5c
        MOVI             R1, 0   # 0x1f5e
        MOV_P            R4, 0, R1, R1, R1   # 0x1f62
        ADD              R4, R6, R4, R6   # 0x1f66
        SETP_LT_NP       P0, R11, R10, R4   # 0x1f6a
        MOVI             R11, 10   # 0x1f6e
        MOV_P            R3, 0, R11, R11, R11   # 0x1f72
        MOV_P            R4, 0, R1, R1, R1   # 0x1f76
        ADD              R2, R2, R8, R2   # 0x1f7a
        ADD              R8, R3, R2, R3   # 0x1f7e
        C_ADDI           R7, 2   # 0x1f82
        LD_GLOBAL        R1, R15, -36   # 0x1f84
        SETP_NE_NP       P0, R2, R1, R7   # 0x1f88
        C_MOV            R3, R6   # 0x1f8c
        BRA_PRED         0, L1f12   # 0x1f8e
        C_BRA            L1f9e   # 0x1f92
L1f94:  C_CHWIDTH        R7, 0   # 0x1f94
        MOVI             R7, 0   # 0x1f96
        LD_GLOBAL        R1, R15, -32   # 0x1f9a
L1f9e:  C_CHWIDTH        R2, 0   # 0x1f9e
        C_MOV            R13, R5   # 0x1fa0
        MOVI             R1, 0   # 0x1fa2
        LD_GLOBAL        R2, R15, -52   # 0x1fa6
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x1faa
        LD_GLOBAL        R9, R15, -32   # 0x1fae
        LD_GLOBAL        R10, R15, -68   # 0x1fb2
        MOVI             R5, 1   # 0x1fb6
        BRA_PRED         0, L1ed8   # 0x1fba
        C_CHWIDTH        R8, 1   # 0x1fbe
        LD_GLOBAL        R2, R15, -28   # 0x1fc0
        C_MUL_LO         R2, R14   # 0x1fc4
        ADD              R2, R7, R2, R7   # 0x1fc6
        C_SHLI           R2, 2   # 0x1fca
        ADD              R2, R9, R2, R9   # 0x1fcc
        LD_GLOBAL        R3, R15, -40   # 0x1fd0
        LD_GLOBAL_IDX    R2, R3, R2, 0, 0   # 0x1fd4
        SETP_LT_NP       P0, R3, R6, R2   # 0x1fd8
        MOVI             R3, 0   # 0x1fdc
        MOV_P            R3, 0, R5, R5, R5   # 0x1fe0
        ADD              R4, R2, R4, R2   # 0x1fe4
        LD_GLOBAL        R5, R15, -64   # 0x1fe8
        SETP_LT_NP       P0, R6, R5, R4   # 0x1fec
        MOV_P            R4, 0, R1, R1, R1   # 0x1ff0
        MOV_P            R3, 0, R11, R11, R11   # 0x1ff4
        ADD              R8, R3, R8, R3   # 0x1ff8
        C_MOV            R6, R2   # 0x1ffc
        BRA              L1ed8   # 0x1ffe
L2002:  C_MOV            R8, R2   # 0x2002
        C_MOV            R14, R3   # 0x2004
        LD_GLOBAL        R0, R15, -56   # 0x2006
L200a:  C_CHWIDTH        R8, 0   # 0x200a
        ST_GLOBAL        R8, R15, -92   # 0x200c
        LD_GLOBAL        R1, R15, -44   # 0x2010
        LD_GLOBAL        R2, R15, -76   # 0x2014
        OR               R8, R1, R2, R1   # 0x2018
        LD_GLOBAL        R1, R15, -60   # 0x201c
        MOVI             R2, 65535   # 0x2020
        AND              R4, R1, R2, R1   # 0x2024
        MOVI             R1, 0   # 0x2028
        SETP_EQ_NPI      P0, R2, R14, 0   # 0x202c
        ST_GLOBAL        R12, R15, -28   # 0x2030
        BRA_PRED         0, L2266   # 0x2034
        MOVI             R10, 0   # 0x2038
        C_BRA            L2062   # 0x203c
L203e:  CHWIDTH_MULTI    2240, 0   # 0x203e
        C_MOV            R2, R10   # 0x2042
        C_SHLI           R2, 2   # 0x2044
        ADD              R2, R9, R2, R9   # 0x2046
        LD_GLOBAL        R3, R15, -40   # 0x204a
        ST_GLOBAL_IDX    R5, R3, R2, 0, 0   # 0x204e
        C_ADD            R1, R14   # 0x2052
        C_ADDI           R10, 1   # 0x2054
        SETP_NE_NP       P0, R2, R10, R14   # 0x2056
        LD_GLOBAL        R13, R15, -48   # 0x205a
        BRA_PRED         4, L211a   # 0x205e
L2062:  SETP_EQ_NPI      P0, R3, R13, 0   # 0x2062
        BRA_PRED         0, L20d4   # 0x2066
        MOVI             R3, 0   # 0x206a
        MOVI             R5, 0   # 0x206e
        LD_GLOBAL        R0, R15, -36   # 0x2072
        LD_GLOBAL        R13, R15, -56   # 0x2076
L207a:  C_CHWIDTH        R11, 1   # 0x207a
        CHWIDTH_MULTI    192, 0   # 0x207c
        ADD              R6, R1, R3, R1   # 0x2080
        C_SHLI           R6, 1   # 0x2084
        C_ADD            R6, R12   # 0x2086
        C_MOV            R7, R3   # 0x2088
        C_SHLI           R7, 1   # 0x208a
        C_ADD            R7, R4   # 0x208c
        LD_GLOBAL_IDX    R11, R8, R7, 0, 0   # 0x208e
        CVT_SEXT         R2, R11, R11, R11   # 0x2092
        LD_GLOBAL_IDX    R11, R13, R6, 0, 0   # 0x2096
        CVT_SEXT         R12, R11, R11, R11   # 0x209a
        MADLO            R2, R2, R12, R5   # 0x209e
        LD_GLOBAL        R12, R15, -28   # 0x20a2
        ADDI             R5, R6, 2   # 0x20a6
        C_CHWIDTH        R6, 1   # 0x20aa
        LD_GLOBAL_IDX    R6, R13, R5, 0, 0   # 0x20ac
        ADDI             R5, R7, 2   # 0x20b0
        C_CHWIDTH        R7, 1   # 0x20b4
        LD_GLOBAL_IDX    R7, R8, R5, 0, 0   # 0x20b6
        CVT_SEXT         R5, R7, R7, R7   # 0x20ba
        C_CHWIDTH        R7, 0   # 0x20be
        CVT_SEXT         R7, R6, R6, R6   # 0x20c0
        MADLO            R5, R5, R7, R2   # 0x20c4
        C_ADDI           R3, 2   # 0x20c8
        SETP_NE_NP       P0, R2, R0, R3   # 0x20ca
        BRA_PRED         0, L207a   # 0x20ce
        C_BRA            L20e0   # 0x20d2
L20d4:  MOVI             R3, 0   # 0x20d4
        MOVI             R5, 0   # 0x20d8
        LD_GLOBAL        R13, R15, -56   # 0x20dc
L20e0:  LD_GLOBAL        R0, R15, -52   # 0x20e0
        SETP_EQ_NPI      P0, R2, R0, 0   # 0x20e4
        C_MOV            R0, R13   # 0x20e8
        BRA_PRED         0, L203e   # 0x20ea
        CHWIDTH_MULTI    192, 1   # 0x20ee
        MUL_LO           R2, R10, R14, R14   # 0x20f2
        ADD              R2, R3, R2, R3   # 0x20f6
        C_SHLI           R2, 1   # 0x20fa
        ADD              R2, R12, R2, R12   # 0x20fc
        LD_GLOBAL_IDX    R7, R0, R2, 0, 0   # 0x2100
        C_SHLI           R3, 1   # 0x2104
        ADD              R2, R4, R3, R4   # 0x2106
        LD_GLOBAL_IDX    R6, R8, R2, 0, 0   # 0x210a
        CVT_SEXT         R2, R6, R6, R6   # 0x210e
        CVT_SEXT         R3, R7, R7, R7   # 0x2112
        MAD_ACC          R5, R2, R3   # 0x2116
        C_BRA            L203e   # 0x2118
L211a:  MOVI             R1, 0   # 0x211a
        C_MOV            R11, R1   # 0x211e
        MOVI             R6, 0   # 0x2120
        ST_GLOBAL        R1, R15, -60   # 0x2124
        MOVI             R2, 0   # 0x2128
        MOVI             R7, 0   # 0x212c
        C_BRA            L2150   # 0x2130
L2132:  C_MOV            R6, R13   # 0x2132
        C_ADD            R6, R14   # 0x2134
        LD_GLOBAL        R1, R15, -60   # 0x2136
        C_ADDI           R1, 1   # 0x213a
        ST_GLOBAL        R1, R15, -60   # 0x213c
        SETP_NE_NP       P0, R3, R1, R14   # 0x2140
        LD_GLOBAL        R12, R15, -28   # 0x2144
        LD_GLOBAL        R13, R15, -48   # 0x2148
        BRA_PRED         4, L2268   # 0x214c
L2150:  SETP_EQ_NPI      P0, R3, R13, 0   # 0x2150
        ST_GLOBAL        R6, R15, -44   # 0x2154
        MOVI             R5, 0   # 0x2158
        BRA_PRED         0, L21f8   # 0x215c
        C_MOV            R3, R2   # 0x2160
        LD_GLOBAL        R9, R15, -40   # 0x2162
        LD_GLOBAL        R1, R15, -32   # 0x2166
        LD_GLOBAL        R1, R15, -36   # 0x216a
        LD_GLOBAL        R10, R15, -64   # 0x216e
L2172:  CHWIDTH_MULTI    6144, 0   # 0x2172
        LD_GLOBAL        R1, R15, -44   # 0x2176
        ADD              R2, R1, R5, R1   # 0x217a
        C_SHLI           R2, 2   # 0x217e
        C_MOV            R1, R11   # 0x2180
        LD_GLOBAL        R11, R15, -32   # 0x2182
        ADD              R11, R2, R11, R2   # 0x2186
        ADDI             R2, R11, 4   # 0x218a
        LD_GLOBAL_IDX    R2, R9, R2, 0, 0   # 0x218e
        LD_GLOBAL_IDX    R11, R9, R11, 0, 0   # 0x2192
        SETP_LT_NP       P0, R3, R3, R11   # 0x2196
        SETP_LT_NP       P1, R3, R11, R2   # 0x219a
        MOVI             R3, 0   # 0x219e
        MOVI             R13, 1   # 0x21a2
        MOV_P            R3, 1, R13, R13, R13   # 0x21a6
        MOVI             R12, 0   # 0x21aa
        MOV_P            R12, 0, R13, R13, R13   # 0x21ae
        ADD              R7, R11, R7, R11   # 0x21b2
        SETP_LT_NP       P0, R11, R10, R7   # 0x21b6
        MOVI             R6, 10   # 0x21ba
        MOV_P            R12, 0, R6, R6, R6   # 0x21be
        C_CHWIDTH        R12, 1   # 0x21c2
        MOVI             R13, 0   # 0x21c4
        MOV_P            R7, 0, R13, R13, R13   # 0x21c8
        ADD              R7, R2, R7, R2   # 0x21cc
        SETP_LT_NP       P0, R11, R10, R7   # 0x21d0
        C_CHWIDTH        R11, 1   # 0x21d4
        MOV_P            R3, 0, R6, R6, R6   # 0x21d6
        MOV_P            R7, 0, R13, R13, R13   # 0x21da
        ADD              R12, R12, R1, R12   # 0x21de
        ADD              R11, R3, R12, R3   # 0x21e2
        C_ADDI           R5, 2   # 0x21e6
        LD_GLOBAL        R1, R15, -36   # 0x21e8
        SETP_NE_NP       P0, R3, R1, R5   # 0x21ec
        C_MOV            R3, R2   # 0x21f0
        BRA_PRED         0, L2172   # 0x21f2
        C_BRA            L21fc   # 0x21f6
L21f8:  LD_GLOBAL        R1, R15, -32   # 0x21f8
L21fc:  C_CHWIDTH        R12, 0   # 0x21fc
        LD_GLOBAL        R13, R15, -44   # 0x21fe
        MOVI             R12, 10   # 0x2202
        LD_GLOBAL        R3, R15, -52   # 0x2206
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x220a
        LD_GLOBAL        R6, R15, -32   # 0x220e
        LD_GLOBAL        R10, R15, -68   # 0x2212
        MOVI             R1, 0   # 0x2216
        MOVI             R9, 1   # 0x221a
        BRA_PRED         0, L2132   # 0x221e
        C_CHWIDTH        R11, 1   # 0x2222
        LD_GLOBAL        R3, R15, -60   # 0x2224
        C_MUL_LO         R3, R14   # 0x2228
        ADD              R3, R5, R3, R5   # 0x222a
        C_SHLI           R3, 2   # 0x222e
        ADD              R3, R6, R3, R6   # 0x2230
        LD_GLOBAL        R5, R15, -40   # 0x2234
        LD_GLOBAL_IDX    R3, R5, R3, 0, 0   # 0x2238
        SETP_LT_NP       P0, R2, R2, R3   # 0x223c
        MOVI             R2, 0   # 0x2240
        MOV_P            R2, 0, R9, R9, R9   # 0x2244
        ADD              R7, R3, R7, R3   # 0x2248
        LD_GLOBAL        R5, R15, -64   # 0x224c
        SETP_LT_NP       P0, R5, R5, R7   # 0x2250
        MOV_P            R7, 0, R1, R1, R1   # 0x2254
        MOV_P            R2, 0, R12, R12, R12   # 0x2258
        ADD              R11, R2, R11, R2   # 0x225c
        C_MOV            R2, R3   # 0x2260
        BRA              L2132   # 0x2262
L2266:  C_MOV            R11, R1   # 0x2266
L2268:  CHWIDTH_MULTI    2176, 0   # 0x2268
        ST_GLOBAL        R11, R15, -96   # 0x226c
        LD_GLOBAL        R1, R15, -72   # 0x2270
        MOVI             R1, 0   # 0x2274
        SETP_EQ_NPI      P0, R2, R14, 0   # 0x2278
        C_MOV            R2, R14   # 0x227c
        C_SHLI           R2, 1   # 0x227e
        BRA_PRED         0, L2502   # 0x2280
        MOVI             R0, 0   # 0x2284
        C_BRA            L229a   # 0x2288
L228a:  C_ADD            R1, R14   # 0x228a
        LD_GLOBAL        R0, R15, -76   # 0x228c
        C_ADDI           R0, 1   # 0x2290
        SETP_NE_NP       P0, R3, R0, R14   # 0x2292
        BRA_PRED         4, L23a6   # 0x2296
L229a:  ST_GLOBAL        R0, R15, -76   # 0x229a
        C_MUL_LO         R0, R14   # 0x229e
        ST_GLOBAL        R0, R15, -60   # 0x22a0
        MOVI             R0, 0   # 0x22a4
        ST_GLOBAL        R0, R15, -44   # 0x22a8
        C_BRA            L22e2   # 0x22ac
L22ae:  CHWIDTH_MULTI    192, 0   # 0x22ae
        LD_GLOBAL        R0, R15, -60   # 0x22b2
        LD_GLOBAL        R7, R15, -44   # 0x22b6
        ADD              R5, R7, R0, R7   # 0x22ba
        C_SHLI           R5, 2   # 0x22be
        LD_GLOBAL        R6, R15, -32   # 0x22c0
        ADD              R5, R6, R5, R6   # 0x22c4
        LD_GLOBAL        R6, R15, -40   # 0x22c8
        ST_GLOBAL_IDX    R3, R6, R5, 0, 0   # 0x22cc
        C_ADDI           R7, 1   # 0x22d0
        ST_GLOBAL        R7, R15, -44   # 0x22d2
        SETP_NE_NP       P0, R3, R7, R14   # 0x22d6
        LD_GLOBAL        R13, R15, -48   # 0x22da
        BRA_PRED         4, L228a   # 0x22de
L22e2:  SETP_EQ_NPI      P0, R3, R13, 0   # 0x22e2
        MOVI             R11, 0   # 0x22e6
        MOVI             R3, 0   # 0x22ea
        C_MOV            R13, R14   # 0x22ee
        LD_GLOBAL        R14, R15, -28   # 0x22f0
        LD_GLOBAL        R0, R15, -36   # 0x22f4
        LD_GLOBAL        R9, R15, -56   # 0x22f8
        BRA_PRED         0, L235a   # 0x22fc
        LD_GLOBAL        R5, R15, -44   # 0x2300
L2304:  C_CHWIDTH        R7, 0   # 0x2304
        ADD              R12, R1, R11, R1   # 0x2306
        C_SHLI           R12, 1   # 0x230a
        C_ADD            R12, R14   # 0x230c
        C_MOV            R7, R5   # 0x230e
        C_SHLI           R7, 1   # 0x2310
        ADD              R7, R4, R7, R4   # 0x2312
        C_CHWIDTH        R7, 1   # 0x2316
        LD_GLOBAL_IDX    R7, R8, R7, 0, 0   # 0x2318
        CVT_SEXT         R6, R7, R7, R7   # 0x231c
        LD_GLOBAL_IDX    R7, R9, R12, 0, 0   # 0x2320
        CVT_SEXT         R10, R7, R7, R7   # 0x2324
        MAD_ACC          R3, R6, R10   # 0x2328
        ADDI             R6, R12, 2   # 0x232a
        LD_GLOBAL_IDX    R7, R9, R6, 0, 0   # 0x232e
        ADD              R6, R13, R5, R13   # 0x2332
        C_SHLI           R6, 1   # 0x2336
        ADD              R6, R4, R6, R4   # 0x2338
        C_CHWIDTH        R6, 1   # 0x233c
        LD_GLOBAL_IDX    R6, R8, R6, 0, 0   # 0x233e
        CVT_SEXT         R10, R6, R6, R6   # 0x2342
        C_CHWIDTH        R6, 0   # 0x2346
        CVT_SEXT         R6, R7, R7, R7   # 0x2348
        MAD_ACC          R3, R10, R6   # 0x234c
        C_ADD            R5, R2   # 0x234e
        C_ADDI           R11, 2   # 0x2350
        SETP_NE_NP       P0, R6, R0, R11   # 0x2352
        BRA_PRED         0, L2304   # 0x2356
L235a:  LD_GLOBAL        R0, R15, -52   # 0x235a
        SETP_EQ_NPI      P0, R5, R0, 0   # 0x235e
        C_MOV            R14, R13   # 0x2362
        BRA_PRED         0, L22ae   # 0x2364
        C_CHWIDTH        R7, 1   # 0x2368
        LD_GLOBAL        R0, R15, -44   # 0x236a
        MADLO            R5, R11, R14, R0   # 0x236e
        C_SHLI           R5, 1   # 0x2372
        ADD              R5, R4, R5, R4   # 0x2374
        LD_GLOBAL_IDX    R7, R8, R5, 0, 0   # 0x2378
        LD_GLOBAL        R0, R15, -60   # 0x237c
        ADD              R5, R11, R0, R11   # 0x2380
        C_SHLI           R5, 1   # 0x2384
        LD_GLOBAL        R6, R15, -28   # 0x2386
        ADD              R5, R6, R5, R6   # 0x238a
        C_CHWIDTH        R6, 1   # 0x238e
        LD_GLOBAL        R0, R15, -56   # 0x2390
        LD_GLOBAL_IDX    R6, R0, R5, 0, 0   # 0x2394
        CVT_SEXT         R5, R7, R7, R7   # 0x2398
        C_CHWIDTH        R7, 0   # 0x239c
        CVT_SEXT         R7, R6, R6, R6   # 0x239e
        MAD_ACC          R3, R5, R7   # 0x23a2
        C_BRA            L22ae   # 0x23a4
L23a6:  MOVI             R0, 0   # 0x23a6
        C_MOV            R7, R0   # 0x23aa
        MOVI             R1, 0   # 0x23ac
        ST_GLOBAL        R0, R15, -60   # 0x23b0
        MOVI             R5, 0   # 0x23b4
        MOVI             R6, 0   # 0x23b8
        LD_GLOBAL        R0, R15, -68   # 0x23bc
        LD_GLOBAL        R12, R15, -28   # 0x23c0
        LD_GLOBAL        R9, R15, -40   # 0x23c4
        LD_GLOBAL        R0, R15, -56   # 0x23c8
        ST_GLOBAL        R14, R15, -80   # 0x23cc
        C_BRA            L23ec   # 0x23d0
L23d2:  C_MOV            R1, R13   # 0x23d2
        C_ADD            R1, R14   # 0x23d4
        LD_GLOBAL        R3, R15, -60   # 0x23d6
        C_ADDI           R3, 1   # 0x23da
        ST_GLOBAL        R3, R15, -60   # 0x23dc
        SETP_NE_NP       P0, R3, R3, R14   # 0x23e0
        LD_GLOBAL        R13, R15, -48   # 0x23e4
        BRA_PRED         4, L2504   # 0x23e8
L23ec:  SETP_EQ_NPI      P0, R3, R13, 0   # 0x23ec
        ST_GLOBAL        R1, R15, -44   # 0x23f0
        MOVI             R11, 0   # 0x23f4
        BRA_PRED         0, L2492   # 0x23f8
        C_MOV            R3, R5   # 0x23fc
        LD_GLOBAL        R5, R15, -32   # 0x23fe
        LD_GLOBAL        R5, R15, -36   # 0x2402
        LD_GLOBAL        R5, R15, -64   # 0x2406
L240a:  C_CHWIDTH        R7, 0   # 0x240a
        LD_GLOBAL        R1, R15, -44   # 0x240c
        ADD              R5, R1, R11, R1   # 0x2410
        C_SHLI           R5, 2   # 0x2414
        C_MOV            R1, R7   # 0x2416
        LD_GLOBAL        R7, R15, -32   # 0x2418
        ADD              R7, R5, R7, R5   # 0x241c
        ADDI             R5, R7, 4   # 0x2420
        LD_GLOBAL_IDX    R5, R9, R5, 0, 0   # 0x2424
        LD_GLOBAL_IDX    R7, R9, R7, 0, 0   # 0x2428
        SETP_LT_NP       P0, R3, R3, R7   # 0x242c
        SETP_LT_NP       P1, R3, R7, R5   # 0x2430
        MOVI             R3, 0   # 0x2434
        MOVI             R10, 1   # 0x2438
        MOV_P            R3, 1, R10, R10, R10   # 0x243c
        MOVI             R9, 0   # 0x2440
        MOV_P            R9, 0, R10, R10, R10   # 0x2444
        ADD              R6, R7, R6, R7   # 0x2448
        LD_GLOBAL        R14, R15, -64   # 0x244c
        SETP_LT_NP       P0, R7, R14, R6   # 0x2450
        MOVI             R13, 10   # 0x2454
        MOV_P            R9, 0, R13, R13, R13   # 0x2458
        MOVI             R10, 0   # 0x245c
        MOV_P            R6, 0, R10, R10, R10   # 0x2460
        ADD              R6, R5, R6, R5   # 0x2464
        SETP_LT_NP       P0, R7, R14, R6   # 0x2468
        C_CHWIDTH        R7, 1   # 0x246c
        MOV_P            R3, 0, R13, R13, R13   # 0x246e
        MOV_P            R6, 0, R10, R10, R10   # 0x2472
        ADD              R7, R9, R1, R9   # 0x2476
        LD_GLOBAL        R9, R15, -40   # 0x247a
        ADD              R7, R3, R7, R3   # 0x247e
        C_ADDI           R11, 2   # 0x2482
        LD_GLOBAL        R1, R15, -36   # 0x2484
        SETP_NE_NP       P0, R3, R1, R11   # 0x2488
        C_MOV            R3, R5   # 0x248c
        BRA_PRED         0, L240a   # 0x248e
L2492:  LD_GLOBAL        R13, R15, -44   # 0x2492
        LD_GLOBAL        R1, R15, -52   # 0x2496
        SETP_EQ_NPI      P0, R3, R1, 0   # 0x249a
        LD_GLOBAL        R10, R15, -68   # 0x249e
        LD_GLOBAL        R14, R15, -80   # 0x24a2
        BRA_PRED         0, L23d2   # 0x24a6
        C_CHWIDTH        R7, 0   # 0x24aa
        LD_GLOBAL        R1, R15, -60   # 0x24ac
        MUL_LO           R3, R1, R14, R14   # 0x24b0
        ADD              R3, R11, R3, R11   # 0x24b4
        C_SHLI           R3, 2   # 0x24b8
        LD_GLOBAL        R1, R15, -32   # 0x24ba
        ADD              R3, R1, R3, R1   # 0x24be
        LD_GLOBAL_IDX    R3, R9, R3, 0, 0   # 0x24c2
        SETP_LT_NP       P0, R5, R5, R3   # 0x24c6
        MOVI             R5, 0   # 0x24ca
        MOVI             R1, 1   # 0x24ce
        MOV_P            R5, 0, R1, R1, R1   # 0x24d2
        ADD              R6, R3, R6, R3   # 0x24d6
        LD_GLOBAL        R1, R15, -64   # 0x24da
        C_MOV            R11, R7   # 0x24de
        SETP_LT_NP       P0, R7, R1, R6   # 0x24e0
        C_MOV            R7, R11   # 0x24e4
        C_CHWIDTH        R7, 1   # 0x24e6
        MOVI             R1, 0   # 0x24e8
        MOV_P            R6, 0, R1, R1, R1   # 0x24ec
        MOVI             R1, 10   # 0x24f0
        MOV_P            R5, 0, R1, R1, R1   # 0x24f4
        ADD              R7, R5, R7, R5   # 0x24f8
        C_MOV            R5, R3   # 0x24fc
        BRA              L23d2   # 0x24fe
L2502:  C_MOV            R7, R1   # 0x2502
L2504:  C_CHWIDTH        R7, 0   # 0x2504
        ST_GLOBAL        R7, R15, -56   # 0x2506
        MOVI             R1, 0   # 0x250a
        SETP_EQ_NPI      P0, R3, R14, 0   # 0x250e
        BRA_PRED         0, L2760   # 0x2512
        MOVI             R5, 0   # 0x2516
        C_BRA            L252c   # 0x251a
L251c:  C_ADD            R1, R14   # 0x251c
        LD_GLOBAL        R5, R15, -44   # 0x251e
        C_ADDI           R5, 1   # 0x2522
        SETP_NE_NP       P0, R3, R5, R14   # 0x2524
        BRA_PRED         4, L2628   # 0x2528
L252c:  ST_GLOBAL        R5, R15, -44   # 0x252c
        MUL_LO           R6, R5, R14, R14   # 0x2530
        MOVI             R7, 0   # 0x2534
        C_BRA            L255e   # 0x2538
L253a:  ADD              R3, R7, R6, R7   # 0x253a
        C_SHLI           R3, 2   # 0x253e
        LD_GLOBAL        R5, R15, -32   # 0x2540
        ADD              R3, R5, R3, R5   # 0x2544
        LD_GLOBAL        R9, R15, -40   # 0x2548
        ST_GLOBAL_IDX    R11, R9, R3, 0, 0   # 0x254c
        C_ADDI           R7, 1   # 0x2550
        SETP_NE_NP       P0, R3, R7, R14   # 0x2552
        LD_GLOBAL        R13, R15, -48   # 0x2556
        BRA_PRED         4, L251c   # 0x255a
L255e:  SETP_EQ_NPI      P0, R3, R13, 0   # 0x255e
        MOVI             R3, 0   # 0x2562
        MOVI             R11, 0   # 0x2566
        LD_GLOBAL        R13, R15, -36   # 0x256a
        BRA_PRED         0, L25e6   # 0x256e
        C_MOV            R5, R7   # 0x2572
L2574:  ADD              R9, R1, R3, R1   # 0x2574
        C_SHLI           R9, 1   # 0x2578
        C_ADD            R9, R12   # 0x257a
        C_CHWIDTH        R12, 1   # 0x257c
        C_MOV            R10, R5   # 0x257e
        C_SHLI           R10, 1   # 0x2580
        ADD              R10, R4, R10, R4   # 0x2582
        C_CHWIDTH        R10, 1   # 0x2586
        LD_GLOBAL_IDX    R10, R8, R10, 0, 0   # 0x2588
        C_CHWIDTH        R10, 0   # 0x258c
        LD_GLOBAL_IDX    R12, R0, R9, 0, 0   # 0x258e
        C_CHWIDTH        R12, 0   # 0x2592
        C_MUL_LO         R10, R12   # 0x2594
        C_MOV            R12, R10   # 0x2596
        C_SHRI           R12, 5   # 0x2598
        ANDI             R12, R12, 127   # 0x259a
        C_SHRI           R10, 2   # 0x259e
        C_ANDI           R10, 15   # 0x25a0
        MADLO            R10, R10, R12, R11   # 0x25a2
        LD_GLOBAL        R12, R15, -28   # 0x25a6
        C_ADDI           R9, 2   # 0x25aa
        C_CHWIDTH        R9, 1   # 0x25ac
        LD_GLOBAL_IDX    R9, R0, R9, 0, 0   # 0x25ae
        C_CHWIDTH        R9, 0   # 0x25b2
        ADD              R11, R14, R5, R14   # 0x25b4
        C_SHLI           R11, 1   # 0x25b8
        ADD              R11, R4, R11, R4   # 0x25ba
        C_CHWIDTH        R11, 1   # 0x25be
        LD_GLOBAL_IDX    R11, R8, R11, 0, 0   # 0x25c0
        C_CHWIDTH        R11, 0   # 0x25c4
        MUL_LO           R9, R11, R9, R9   # 0x25c6
        C_MOV            R11, R9   # 0x25ca
        C_SHRI           R11, 5   # 0x25cc
        ANDI             R11, R11, 127   # 0x25ce
        C_SHRI           R9, 2   # 0x25d2
        C_ANDI           R9, 15   # 0x25d4
        MADLO            R11, R9, R11, R10   # 0x25d6
        C_ADD            R5, R2   # 0x25da
        C_ADDI           R3, 2   # 0x25dc
        SETP_NE_NP       P0, R9, R13, R3   # 0x25de
        BRA_PRED         0, L2574   # 0x25e2
L25e6:  LD_GLOBAL        R5, R15, -52   # 0x25e6
        SETP_EQ_NPI      P0, R5, R5, 0   # 0x25ea
        BRA_PRED         0, L253a   # 0x25ee
        MADLO            R5, R3, R14, R7   # 0x25f2
        C_SHLI           R5, 1   # 0x25f6
        ADD              R5, R4, R5, R4   # 0x25f8
        C_CHWIDTH        R5, 1   # 0x25fc
        LD_GLOBAL_IDX    R5, R8, R5, 0, 0   # 0x25fe
        C_CHWIDTH        R5, 0   # 0x2602
        C_ADD            R3, R6   # 0x2604
        C_SHLI           R3, 1   # 0x2606
        ADD              R3, R12, R3, R12   # 0x2608
        C_CHWIDTH        R3, 1   # 0x260c
        LD_GLOBAL_IDX    R3, R0, R3, 0, 0   # 0x260e
        C_CHWIDTH        R3, 0   # 0x2612
        MUL_LO           R3, R5, R3, R3   # 0x2614
        C_MOV            R5, R3   # 0x2618
        C_SHRI           R5, 5   # 0x261a
        ANDI             R5, R5, 127   # 0x261c
        C_SHRI           R3, 2   # 0x2620
        C_ANDI           R3, 15   # 0x2622
        MAD_ACC          R11, R3, R5   # 0x2624
        C_BRA            L253a   # 0x2626
L2628:  MOVI             R1, 0   # 0x2628
        C_MOV            R8, R1   # 0x262c
        MOVI             R7, 0   # 0x262e
        ST_GLOBAL        R1, R15, -28   # 0x2632
        MOVI             R2, 0   # 0x2636
        MOVI             R6, 0   # 0x263a
        LD_GLOBAL        R3, R15, -68   # 0x263e
        C_BRA            L265c   # 0x2642
L2644:  C_ADD            R7, R14   # 0x2644
        LD_GLOBAL        R1, R15, -28   # 0x2646
        C_ADDI           R1, 1   # 0x264a
        ST_GLOBAL        R1, R15, -28   # 0x264c
        SETP_NE_NP       P0, R3, R1, R14   # 0x2650
        LD_GLOBAL        R13, R15, -48   # 0x2654
        BRA_PRED         4, L2762   # 0x2658
L265c:  SETP_EQ_NPI      P0, R3, R13, 0   # 0x265c
        BRA_PRED         0, L26f8   # 0x2660
        MOVI             R11, 0   # 0x2664
        C_MOV            R3, R2   # 0x2668
        LD_GLOBAL        R1, R15, -32   # 0x266a
        LD_GLOBAL        R13, R15, -36   # 0x266e
        LD_GLOBAL        R10, R15, -64   # 0x2672
L2676:  C_CHWIDTH        R8, 1   # 0x2676
        ADD              R2, R7, R11, R7   # 0x2678
        C_SHLI           R2, 2   # 0x267c
        C_MOV            R5, R7   # 0x267e
        LD_GLOBAL        R1, R15, -32   # 0x2680
        ADD              R7, R2, R1, R2   # 0x2684
        ADDI             R2, R7, 4   # 0x2688
        LD_GLOBAL_IDX    R2, R9, R2, 0, 0   # 0x268c
        LD_GLOBAL_IDX    R7, R9, R7, 0, 0   # 0x2690
        SETP_LT_NP       P0, R3, R3, R7   # 0x2694
        SETP_LT_NP       P1, R3, R7, R2   # 0x2698
        MOVI             R3, 0   # 0x269c
        MOVI             R1, 1   # 0x26a0
        MOV_P            R3, 1, R1, R1, R1   # 0x26a4
        MOVI             R9, 0   # 0x26a8
        MOV_P            R9, 0, R1, R1, R1   # 0x26ac
        ADD              R6, R7, R6, R7   # 0x26b0
        SETP_LT_NP       P0, R7, R10, R6   # 0x26b4
        MOVI             R4, 10   # 0x26b8
        MOV_P            R9, 0, R4, R4, R4   # 0x26bc
        MOVI             R1, 0   # 0x26c0
        MOV_P            R6, 0, R1, R1, R1   # 0x26c4
        ADD              R6, R2, R6, R2   # 0x26c8
        SETP_LT_NP       P0, R7, R10, R6   # 0x26cc
        C_CHWIDTH        R7, 1   # 0x26d0
        MOV_P            R3, 0, R4, R4, R4   # 0x26d2
        MOV_P            R6, 0, R1, R1, R1   # 0x26d6
        ADD              R7, R9, R8, R9   # 0x26da
        LD_GLOBAL        R9, R15, -40   # 0x26de
        ADD              R8, R3, R7, R3   # 0x26e2
        C_CHWIDTH        R7, 0   # 0x26e6
        C_MOV            R7, R5   # 0x26e8
        C_ADDI           R11, 2   # 0x26ea
        SETP_NE_NP       P0, R3, R13, R11   # 0x26ec
        C_MOV            R3, R2   # 0x26f0
        BRA_PRED         0, L2676   # 0x26f2
        C_BRA            L26fc   # 0x26f6
L26f8:  MOVI             R11, 0   # 0x26f8
L26fc:  MOVI             R13, 10   # 0x26fc
        MOVI             R5, 1   # 0x2700
        MOVI             R1, 0   # 0x2704
        LD_GLOBAL        R3, R15, -52   # 0x2708
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x270c
        LD_GLOBAL        R10, R15, -68   # 0x2710
        BRA_PRED         0, L2644   # 0x2714
        C_CHWIDTH        R8, 1   # 0x2718
        LD_GLOBAL        R3, R15, -28   # 0x271a
        C_MUL_LO         R3, R14   # 0x271e
        ADD              R3, R11, R3, R11   # 0x2720
        C_SHLI           R3, 2   # 0x2724
        LD_GLOBAL        R4, R15, -32   # 0x2726
        ADD              R3, R4, R3, R4   # 0x272a
        LD_GLOBAL_IDX    R3, R9, R3, 0, 0   # 0x272e
        SETP_LT_NP       P0, R2, R2, R3   # 0x2732
        MOVI             R2, 0   # 0x2736
        MOV_P            R2, 0, R5, R5, R5   # 0x273a
        ADD              R6, R3, R6, R3   # 0x273e
        LD_GLOBAL        R4, R15, -64   # 0x2742
        C_MOV            R5, R7   # 0x2746
        SETP_LT_NP       P0, R7, R4, R6   # 0x2748
        C_MOV            R7, R5   # 0x274c
        MOV_P            R6, 0, R1, R1, R1   # 0x274e
        MOV_P            R2, 0, R13, R13, R13   # 0x2752
        ADD              R8, R2, R8, R2   # 0x2756
        C_MOV            R2, R3   # 0x275a
        BRA              L2644   # 0x275c
L2760:  C_MOV            R8, R1   # 0x2760
L2762:  LD_GLOBAL        R1, R15, -88   # 0x2762
        C_MOV            R9, R1   # 0x2766
        SETP_EQ_NPI      P0, R1, R14, 0   # 0x2768
        BRA_PRED         0, L281c   # 0x276c
        MOVI             R1, 0   # 0x2770
        ANDI             R2, R14, 3   # 0x2774
        MOVI             R3, 0   # 0x2778
        C_BRA            L278a   # 0x277c
L277e:  C_ADD            R1, R14   # 0x277e
        C_ADDI           R3, 1   # 0x2780
        SETP_NE_NP       P0, R4, R3, R14   # 0x2782
        BRA_PRED         4, L281c   # 0x2786
L278a:  SETP_LT_U_NPI    P0, R4, R13, 3   # 0x278a
        MOVI             R4, 0   # 0x278e
        LD_GLOBAL        R11, R15, -72   # 0x2792
        BRA_PRED         0, L27ea   # 0x2796
L279a:  C_CHWIDTH        R7, 1   # 0x279a
        ADD              R5, R1, R4, R1   # 0x279c
        C_SHLI           R5, 1   # 0x27a0
        ADD              R5, R12, R5, R12   # 0x27a2
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x27a6
        SUB              R7, R7, R10, R7   # 0x27aa
        ST_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x27ae
        ADDI             R6, R5, 2   # 0x27b2
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27b6
        SUB              R7, R7, R10, R7   # 0x27ba
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27be
        ADDI             R6, R5, 4   # 0x27c2
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27c6
        SUB              R7, R7, R10, R7   # 0x27ca
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x27ce
        C_ADDI           R5, 6   # 0x27d2
        LD_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x27d4
        SUB              R7, R7, R10, R7   # 0x27d8
        ST_GLOBAL_IDX    R7, R0, R5, 0, 0   # 0x27dc
        C_ADDI           R4, 4   # 0x27e0
        SETP_NE_NP       P0, R5, R11, R4   # 0x27e2
        BRA_PRED         0, L279a   # 0x27e6
L27ea:  SETP_EQ_NPI      P0, R5, R2, 0   # 0x27ea
        BRA_PRED         0, L277e   # 0x27ee
        C_ADD            R4, R1   # 0x27f2
        C_MOV            R5, R2   # 0x27f4
L27f6:  C_CHWIDTH        R7, 1   # 0x27f6
        C_MOV            R6, R4   # 0x27f8
        C_SHLI           R6, 1   # 0x27fa
        ADD              R6, R12, R6, R12   # 0x27fc
        LD_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x2800
        SUB              R7, R7, R10, R7   # 0x2804
        ST_GLOBAL_IDX    R7, R0, R6, 0, 0   # 0x2808
        C_ADDI           R4, 1   # 0x280c
        ADDI             R5, R5, -1   # 0x280e
        SETP_NE_NPI      P0, R6, R5, 0   # 0x2812
        BRA_PRED         0, L27f6   # 0x2816
        C_BRA            L277e   # 0x281a
L281c:  CHWIDTH_MULTI    384, 0   # 0x281c
        LD_GLOBAL        R1, R15, -92   # 0x2820
        MOVI             R2, 0   # 0x2824
        CALL             R14, 129235   # 0x2828
        C_MOV            R2, R1   # 0x282c
        LD_GLOBAL        R1, R15, -96   # 0x282e
        CALL             R14, 129230   # 0x2832
        C_MOV            R2, R1   # 0x2836
        LD_GLOBAL        R1, R15, -56   # 0x2838
        CALL             R14, 129225   # 0x283c
        C_MOV            R2, R1   # 0x2840
        C_MOV            R1, R8   # 0x2842
        CALL             R14, 129221   # 0x2844
        C_MOV            R2, R9   # 0x2848
        CALL             R14, 129218   # 0x284a
        LD_GLOBAL        R14, R15, -84   # 0x284e
        LD_GLOBAL        R13, R15, -24   # 0x2852
        LD_GLOBAL        R12, R15, -20   # 0x2856
        LD_GLOBAL        R11, R15, -16   # 0x285a
        LD_GLOBAL        R10, R15, -12   # 0x285e
        LD_GLOBAL        R9, R15, -8   # 0x2862
        LD_GLOBAL        R8, R15, -4   # 0x2866
        C_RET            224   # 0x286a
        C_CHWIDTH        R0, 1   # 0x286c
        XOR              R0, R2, R1, R2   # 0x286e
        C_CHWIDTH        R0, 0   # 0x2872
        C_ANDI           R0, 1   # 0x2874
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2876
        MOVI             R0, 40961   # 0x287a
        SHRI             R2, R2, 1   # 0x287e
        C_MOV            R3, R2   # 0x2882
        C_CHWIDTH        R2, 1   # 0x2884
        XOR              R2, R2, R0, R2   # 0x2886
        C_CHWIDTH        R2, 0   # 0x288a
        MOV_P            R3, 0, R2, R2, R2   # 0x288c
        SHRI             R2, R1, 1   # 0x2890
        C_CHWIDTH        R2, 1   # 0x2894
        XOR              R2, R2, R3, R2   # 0x2896
        C_CHWIDTH        R2, 0   # 0x289a
        C_ANDI           R2, 1   # 0x289c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x289e
        SHRI             R2, R3, 1   # 0x28a2
        C_MOV            R3, R2   # 0x28a6
        C_CHWIDTH        R2, 1   # 0x28a8
        XOR              R2, R2, R0, R2   # 0x28aa
        C_CHWIDTH        R2, 0   # 0x28ae
        MOV_P            R3, 0, R2, R2, R2   # 0x28b0
        SHRI             R2, R1, 2   # 0x28b4
        C_CHWIDTH        R2, 1   # 0x28b8
        XOR              R2, R2, R3, R2   # 0x28ba
        C_CHWIDTH        R2, 0   # 0x28be
        C_ANDI           R2, 1   # 0x28c0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28c2
        SHRI             R2, R3, 1   # 0x28c6
        C_MOV            R3, R2   # 0x28ca
        C_CHWIDTH        R2, 1   # 0x28cc
        XOR              R2, R2, R0, R2   # 0x28ce
        C_CHWIDTH        R2, 0   # 0x28d2
        MOV_P            R3, 0, R2, R2, R2   # 0x28d4
        SHRI             R2, R1, 3   # 0x28d8
        C_CHWIDTH        R2, 1   # 0x28dc
        XOR              R2, R2, R3, R2   # 0x28de
        C_CHWIDTH        R2, 0   # 0x28e2
        C_ANDI           R2, 1   # 0x28e4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28e6
        SHRI             R2, R3, 1   # 0x28ea
        C_MOV            R3, R2   # 0x28ee
        C_CHWIDTH        R2, 1   # 0x28f0
        XOR              R2, R2, R0, R2   # 0x28f2
        C_CHWIDTH        R2, 0   # 0x28f6
        MOV_P            R3, 0, R2, R2, R2   # 0x28f8
        SHRI             R2, R1, 4   # 0x28fc
        C_CHWIDTH        R2, 1   # 0x2900
        XOR              R2, R2, R3, R2   # 0x2902
        C_CHWIDTH        R2, 0   # 0x2906
        C_ANDI           R2, 1   # 0x2908
        SETP_NE_NPI      P0, R2, R2, 0   # 0x290a
        SHRI             R2, R3, 1   # 0x290e
        C_MOV            R3, R2   # 0x2912
        C_CHWIDTH        R2, 1   # 0x2914
        XOR              R2, R2, R0, R2   # 0x2916
        C_CHWIDTH        R2, 0   # 0x291a
        MOV_P            R3, 0, R2, R2, R2   # 0x291c
        SHRI             R2, R1, 5   # 0x2920
        C_CHWIDTH        R2, 1   # 0x2924
        XOR              R2, R2, R3, R2   # 0x2926
        C_CHWIDTH        R2, 0   # 0x292a
        C_ANDI           R2, 1   # 0x292c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x292e
        SHRI             R2, R3, 1   # 0x2932
        C_MOV            R3, R2   # 0x2936
        C_CHWIDTH        R2, 1   # 0x2938
        XOR              R2, R2, R0, R2   # 0x293a
        C_CHWIDTH        R2, 0   # 0x293e
        MOV_P            R3, 0, R2, R2, R2   # 0x2940
        SHRI             R2, R1, 6   # 0x2944
        C_CHWIDTH        R2, 1   # 0x2948
        XOR              R2, R2, R3, R2   # 0x294a
        C_CHWIDTH        R2, 0   # 0x294e
        C_ANDI           R2, 1   # 0x2950
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2952
        SHRI             R2, R3, 1   # 0x2956
        C_MOV            R3, R2   # 0x295a
        C_CHWIDTH        R2, 1   # 0x295c
        XOR              R2, R2, R0, R2   # 0x295e
        C_CHWIDTH        R2, 0   # 0x2962
        MOV_P            R3, 0, R2, R2, R2   # 0x2964
        MOVI             R2, 128   # 0x2968
        C_CHWIDTH        R2, 1   # 0x296c
        AND              R2, R1, R2, R1   # 0x296e
        C_CHWIDTH        R2, 0   # 0x2972
        SHRI             R2, R2, 7   # 0x2974
        ANDI             R4, R3, 1   # 0x2978
        SETP_EQ_NP       P0, R2, R2, R4   # 0x297c
        SHRI             R2, R3, 1   # 0x2980
        C_MOV            R3, R2   # 0x2984
        C_CHWIDTH        R2, 1   # 0x2986
        XOR              R2, R2, R0, R2   # 0x2988
        C_CHWIDTH        R2, 0   # 0x298c
        MOV_P            R2, 0, R3, R3, R3   # 0x298e
        SHRI             R3, R1, 8   # 0x2992
        C_CHWIDTH        R3, 1   # 0x2996
        XOR              R3, R2, R3, R2   # 0x2998
        C_CHWIDTH        R3, 0   # 0x299c
        C_ANDI           R3, 1   # 0x299e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x29a0
        SHRI             R2, R2, 1   # 0x29a4
        C_MOV            R3, R2   # 0x29a8
        C_CHWIDTH        R2, 1   # 0x29aa
        XOR              R2, R2, R0, R2   # 0x29ac
        C_CHWIDTH        R2, 0   # 0x29b0
        MOV_P            R3, 0, R2, R2, R2   # 0x29b2
        SHRI             R2, R1, 9   # 0x29b6
        C_CHWIDTH        R2, 1   # 0x29ba
        XOR              R2, R2, R3, R2   # 0x29bc
        C_CHWIDTH        R2, 0   # 0x29c0
        C_ANDI           R2, 1   # 0x29c2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29c4
        SHRI             R2, R3, 1   # 0x29c8
        C_MOV            R3, R2   # 0x29cc
        C_CHWIDTH        R2, 1   # 0x29ce
        XOR              R2, R2, R0, R2   # 0x29d0
        C_CHWIDTH        R2, 0   # 0x29d4
        MOV_P            R3, 0, R2, R2, R2   # 0x29d6
        SHRI             R2, R1, 10   # 0x29da
        C_CHWIDTH        R2, 1   # 0x29de
        XOR              R2, R2, R3, R2   # 0x29e0
        C_CHWIDTH        R2, 0   # 0x29e4
        C_ANDI           R2, 1   # 0x29e6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29e8
        SHRI             R2, R3, 1   # 0x29ec
        C_MOV            R3, R2   # 0x29f0
        C_CHWIDTH        R2, 1   # 0x29f2
        XOR              R2, R2, R0, R2   # 0x29f4
        C_CHWIDTH        R2, 0   # 0x29f8
        MOV_P            R3, 0, R2, R2, R2   # 0x29fa
        SHRI             R2, R1, 11   # 0x29fe
        C_CHWIDTH        R2, 1   # 0x2a02
        XOR              R2, R2, R3, R2   # 0x2a04
        C_CHWIDTH        R2, 0   # 0x2a08
        C_ANDI           R2, 1   # 0x2a0a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a0c
        SHRI             R2, R3, 1   # 0x2a10
        C_MOV            R3, R2   # 0x2a14
        C_CHWIDTH        R2, 1   # 0x2a16
        XOR              R2, R2, R0, R2   # 0x2a18
        C_CHWIDTH        R2, 0   # 0x2a1c
        MOV_P            R3, 0, R2, R2, R2   # 0x2a1e
        SHRI             R2, R1, 12   # 0x2a22
        C_CHWIDTH        R2, 1   # 0x2a26
        XOR              R2, R2, R3, R2   # 0x2a28
        C_CHWIDTH        R2, 0   # 0x2a2c
        C_ANDI           R2, 1   # 0x2a2e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a30
        SHRI             R2, R3, 1   # 0x2a34
        C_MOV            R3, R2   # 0x2a38
        C_CHWIDTH        R2, 1   # 0x2a3a
        XOR              R2, R2, R0, R2   # 0x2a3c
        C_CHWIDTH        R2, 0   # 0x2a40
        MOV_P            R3, 0, R2, R2, R2   # 0x2a42
        SHRI             R2, R1, 13   # 0x2a46
        C_CHWIDTH        R2, 1   # 0x2a4a
        XOR              R2, R2, R3, R2   # 0x2a4c
        C_CHWIDTH        R2, 0   # 0x2a50
        C_ANDI           R2, 1   # 0x2a52
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a54
        SHRI             R2, R3, 1   # 0x2a58
        C_MOV            R3, R2   # 0x2a5c
        C_CHWIDTH        R2, 1   # 0x2a5e
        XOR              R2, R2, R0, R2   # 0x2a60
        C_CHWIDTH        R2, 0   # 0x2a64
        MOV_P            R3, 0, R2, R2, R2   # 0x2a66
        SHRI             R2, R1, 14   # 0x2a6a
        C_CHWIDTH        R2, 1   # 0x2a6e
        XOR              R2, R2, R3, R2   # 0x2a70
        C_CHWIDTH        R2, 0   # 0x2a74
        C_ANDI           R2, 1   # 0x2a76
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a78
        SHRI             R2, R3, 1   # 0x2a7c
        C_MOV            R3, R2   # 0x2a80
        C_CHWIDTH        R2, 1   # 0x2a82
        XOR              R2, R2, R0, R2   # 0x2a84
        C_CHWIDTH        R0, 1   # 0x2a88
        C_CHWIDTH        R2, 0   # 0x2a8a
        MOV_P            R3, 0, R2, R2, R2   # 0x2a8c
        SHRI             R1, R1, 15   # 0x2a90
        ANDI             R2, R3, 1   # 0x2a94
        SETP_EQ_NP       P0, R1, R1, R2   # 0x2a98
        SHRI             R1, R3, 1   # 0x2a9c
        C_MOV            R2, R1   # 0x2aa0
        XOR              R0, R1, R0, R1   # 0x2aa2
        C_CHWIDTH        R0, 0   # 0x2aa6
        MOV_P            R0, 0, R2, R2, R2   # 0x2aa8
        MOVI             R1, 65535   # 0x2aac
        AND              R1, R0, R1, R0   # 0x2ab0
        C_RET            224   # 0x2ab4
        C_CHWIDTH        R6, 1   # 0x2ab6
        ST_GLOBAL        R8, R15, -112   # 0x2ab8
        ST_GLOBAL        R9, R15, -116   # 0x2abc
        ST_GLOBAL        R10, R15, -120   # 0x2ac0
        ST_GLOBAL        R11, R15, -124   # 0x2ac4
        ST_GLOBAL        R12, R15, -128   # 0x2ac8
        ST_GLOBAL        R13, R15, -132   # 0x2acc
        ST_GLOBAL        R14, R15, -200   # 0x2ad0
        ST_GLOBAL        R2, R15, -148   # 0x2ad4
        C_MOV            R13, R1   # 0x2ad8
        LD_GLOBAL_IDX    R0, R13, R2, 0, 60   # 0x2ada
        SHLI             R0, R0, 16   # 0x2ade
        LD_GLOBAL_IDX    R1, R13, R2, 0, 56   # 0x2ae2
        SHRI             R4, R1, 16   # 0x2ae6
        OR               R8, R0, R4, R0   # 0x2aea
        MOVI             R0, 65535   # 0x2aee
        C_AND            R1, R0   # 0x2af2
        LD_GLOBAL_IDX    R6, R13, R2, 0, 4   # 0x2af4
        C_MOV            R5, R3   # 0x2af8
        CVT_SEXT         R2, R6, R6, R6   # 0x2afa
        SETP_LT_NPI      P0, R2, R2, 1   # 0x2afe
        BRA_PRED         0, L2e3e   # 0x2b02
        CHWIDTH_MULTI    16416, 1   # 0x2b06
        ST_GLOBAL        R3, R15, -144   # 0x2b0a
        MOVI             R2, 0   # 0x2b0e
        ADDI             R14, R6, 255   # 0x2b12
        C_CHWIDTH        R14, 0   # 0x2b16
        ST_GLOBAL        R14, R15, -152   # 0x2b18
        C_MOV            R7, R2   # 0x2b1c
        ST_GLOBAL        R2, R15, -136   # 0x2b1e
        ST_GLOBAL        R2, R15, -140   # 0x2b22
        C_BRA            L2ba2   # 0x2b26
L2b28:  C_CHWIDTH        R12, 1   # 0x2b28
        C_MOV            R4, R8   # 0x2b2a
        C_MOV            R14, R1   # 0x2b2c
        LD_GLOBAL_IDX    R3, R4, R14, 0, 0   # 0x2b2e
        LD_GLOBAL_IDX    R4, R4, R14, 0, 4   # 0x2b32
        SHLI             R4, R4, 16   # 0x2b36
        SHRI             R14, R3, 16   # 0x2b3a
        C_OR             R4, R14   # 0x2b3e
        C_AND            R3, R0   # 0x2b40
        LD_GLOBAL_IDX    R14, R4, R3, 0, 8   # 0x2b42
        LD_GLOBAL_IDX    R3, R4, R3, 0, 12   # 0x2b46
        SHLI             R3, R3, 16   # 0x2b4a
        SHRI             R4, R14, 16   # 0x2b4e
        C_OR             R3, R4   # 0x2b52
        C_CHWIDTH        R3, 1   # 0x2b54
        AND              R4, R14, R0, R14   # 0x2b56
        LD_GLOBAL_IDX    R3, R3, R4, 0, 0   # 0x2b5a
        C_CHWIDTH        R3, 0   # 0x2b5e
        SHRI             R3, R3, 8   # 0x2b60
        MOVI             R4, 1   # 0x2b64
        AND              R12, R3, R4, R3   # 0x2b68
        LD_GLOBAL        R14, R15, -140   # 0x2b6c
        C_CHWIDTH        R14, 1   # 0x2b70
        ADDI             R14, R14, 1   # 0x2b72
        C_CHWIDTH        R14, 0   # 0x2b76
        ST_GLOBAL        R14, R15, -140   # 0x2b78
L2b7c:  C_CHWIDTH        R6, 0   # 0x2b7c
        CHWIDTH_MULTI    172, 1   # 0x2b7e
        ADD              R7, R12, R7, R12   # 0x2b82
        XOR              R3, R5, R0, R5   # 0x2b86
        C_CHWIDTH        R3, 0   # 0x2b8a
        SHRI             R3, R3, 15   # 0x2b8c
        ADD              R5, R5, R3, R5   # 0x2b90
        ADDI             R2, R2, 1   # 0x2b94
        C_CHWIDTH        R2, 0   # 0x2b98
        SETP_NE_NP       P0, R3, R2, R6   # 0x2b9a
        BRA_PRED         4, L2e02   # 0x2b9e
L2ba2:  C_CHWIDTH        R12, 0   # 0x2ba2
        C_MOV            R12, R8   # 0x2ba4
        SHLI             R4, R12, 16   # 0x2ba6
        C_MOV            R10, R1   # 0x2baa
        AND              R14, R4, R10, R4   # 0x2bac
        ADD              R9, R4, R10, R4   # 0x2bb0
        C_OR             R4, R10   # 0x2bb4
        C_ANDN           R4, R9   # 0x2bb6
        OR               R4, R14, R4, R14   # 0x2bb8
        SHRI             R4, R4, 31   # 0x2bbc
        SHRI             R14, R12, 16   # 0x2bc0
        ADD              R4, R14, R4, R14   # 0x2bc4
        OR               R11, R9, R4, R9   # 0x2bc8
        CVT_SEXT         R4, R5, R5, R5   # 0x2bcc
        MOVI48           R3, 4294967295   # 0x2bd0
        SETP_LT_NP       P0, R4, R3, R4   # 0x2bd6
        BRA_PRED         4, L2c3e   # 0x2bda
        MOVI             R9, 0   # 0x2bde
        SETP_EQ_NPI      P0, R4, R11, 0   # 0x2be2
        BRA_PRED         0, L2ca4   # 0x2be6
        C_MOV            R12, R8   # 0x2bea
        C_MOV            R10, R1   # 0x2bec
L2bee:  C_CHWIDTH        R5, 0   # 0x2bee
        LD_GLOBAL_IDX    R4, R12, R10, 0, 8   # 0x2bf0
        LD_GLOBAL_IDX    R14, R12, R10, 0, 12   # 0x2bf4
        SHLI             R14, R14, 16   # 0x2bf8
        SHRI             R3, R4, 16   # 0x2bfc
        OR               R3, R14, R3, R14   # 0x2c00
        C_CHWIDTH        R3, 1   # 0x2c04
        C_AND            R4, R0   # 0x2c06
        LD_GLOBAL_IDX    R3, R3, R4, 0, 2   # 0x2c08
        C_CHWIDTH        R3, 0   # 0x2c0c
        SETP_EQ_NP       P0, R3, R3, R5   # 0x2c0e
        BRA_PRED         0, L2d14   # 0x2c12
        LD_GLOBAL_IDX    R3, R12, R10, 0, 4   # 0x2c16
        LD_GLOBAL_IDX    R4, R12, R10, 0, 0   # 0x2c1a
        SHRI             R14, R4, 16   # 0x2c1e
        SHLI             R10, R3, 16   # 0x2c22
        OR               R12, R10, R14, R10   # 0x2c26
        C_AND            R3, R0   # 0x2c2a
        OR               R3, R4, R3, R4   # 0x2c2c
        AND              R10, R4, R0, R4   # 0x2c30
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c34
        BRA_PRED         4, L2bee   # 0x2c38
        C_BRA            L2ca4   # 0x2c3c
L2c3e:  MOVI             R9, 0   # 0x2c3e
        SETP_EQ_NPI      P0, R4, R11, 0   # 0x2c42
        BRA_PRED         0, L2ca4   # 0x2c46
L2c4a:  LD_GLOBAL_IDX    R3, R12, R10, 0, 8   # 0x2c4a
        LD_GLOBAL_IDX    R4, R12, R10, 0, 12   # 0x2c4e
        SHLI             R4, R4, 16   # 0x2c52
        SHRI             R14, R3, 16   # 0x2c56
        C_OR             R4, R14   # 0x2c5a
        C_CHWIDTH        R14, 1   # 0x2c5c
        C_AND            R3, R0   # 0x2c5e
        LD_GLOBAL_IDX    R14, R4, R3, 0, 0   # 0x2c60
        XOR              R14, R14, R2, R14   # 0x2c64
        MOVI             R3, 255   # 0x2c68
        C_CHWIDTH        R3, 1   # 0x2c6c
        AND              R3, R14, R3, R14   # 0x2c6e
        C_CHWIDTH        R3, 0   # 0x2c72
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c74
        BRA_PRED         0, L2d14   # 0x2c78
        C_CHWIDTH        R14, 0   # 0x2c7c
        LD_GLOBAL_IDX    R3, R12, R10, 0, 4   # 0x2c7e
        LD_GLOBAL_IDX    R4, R12, R10, 0, 0   # 0x2c82
        SHRI             R14, R4, 16   # 0x2c86
        SHLI             R10, R3, 16   # 0x2c8a
        OR               R12, R10, R14, R10   # 0x2c8e
        C_AND            R3, R0   # 0x2c92
        OR               R3, R4, R3, R4   # 0x2c94
        AND              R10, R4, R0, R4   # 0x2c98
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2c9c
        BRA_PRED         0, L2c4a   # 0x2ca0
L2ca4:  MOVI             R10, 0   # 0x2ca4
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2ca8
        BRA_PRED         0, L2d1e   # 0x2cac
L2cb0:  MOVI             R11, 0   # 0x2cb0
        MOVI             R4, 0   # 0x2cb4
L2cb8:  C_CHWIDTH        R14, 0   # 0x2cb8
        C_MOV            R14, R1   # 0x2cba
        C_MOV            R12, R8   # 0x2cbc
        SHLI             R3, R11, 16   # 0x2cbe
        AND              R1, R3, R4, R3   # 0x2cc2
        ADD              R8, R3, R4, R3   # 0x2cc6
        C_OR             R3, R4   # 0x2cca
        C_ANDN           R3, R8   # 0x2ccc
        OR               R3, R1, R3, R1   # 0x2cce
        SHRI             R3, R3, 31   # 0x2cd2
        SHRI             R4, R11, 16   # 0x2cd6
        ADD              R3, R4, R3, R4   # 0x2cda
        LD_GLOBAL_IDX    R4, R12, R14, 0, 0   # 0x2cde
        ST_GLOBAL_IDX    R8, R12, R14, 0, 0   # 0x2ce2
        LD_GLOBAL_IDX    R1, R12, R14, 0, 4   # 0x2ce6
        ST_GLOBAL_IDX    R3, R12, R14, 0, 4   # 0x2cea
        SHRI             R3, R4, 16   # 0x2cee
        SHLI             R11, R1, 16   # 0x2cf2
        OR               R8, R11, R3, R11   # 0x2cf6
        AND              R3, R1, R0, R1   # 0x2cfa
        OR               R3, R4, R3, R4   # 0x2cfe
        AND              R1, R4, R0, R4   # 0x2d02
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d06
        C_MOV            R11, R12   # 0x2d0a
        C_MOV            R4, R14   # 0x2d0c
        BRA_PRED         0, L2cb8   # 0x2d0e
        C_BRA            L2d28   # 0x2d12
L2d14:  C_MOV            R9, R12   # 0x2d14
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2d16
        BRA_PRED         4, L2cb0   # 0x2d1a
L2d1e:  C_CHWIDTH        R14, 0   # 0x2d1e
        MOVI             R12, 0   # 0x2d20
        MOVI             R14, 0   # 0x2d24
L2d28:  C_MOV            R1, R14   # 0x2d28
        C_MOV            R8, R12   # 0x2d2a
        SHLI             R3, R9, 16   # 0x2d2c
        AND              R4, R3, R10, R3   # 0x2d30
        ADD              R14, R3, R10, R3   # 0x2d34
        C_OR             R3, R10   # 0x2d38
        C_ANDN           R3, R14   # 0x2d3a
        OR               R3, R4, R3, R4   # 0x2d3c
        SHRI             R3, R3, 31   # 0x2d40
        SHRI             R4, R9, 16   # 0x2d44
        ADD              R3, R4, R3, R4   # 0x2d48
        OR               R3, R14, R3, R14   # 0x2d4c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d50
        BRA_PRED         4, L2b28   # 0x2d54
        LD_GLOBAL_IDX    R3, R9, R10, 0, 12   # 0x2d58
        SHLI             R3, R3, 16   # 0x2d5c
        LD_GLOBAL_IDX    R4, R9, R10, 0, 8   # 0x2d60
        SHRI             R14, R4, 16   # 0x2d64
        C_OR             R3, R14   # 0x2d68
        C_CHWIDTH        R3, 1   # 0x2d6a
        C_AND            R4, R0   # 0x2d6c
        LD_GLOBAL_IDX    R3, R3, R4, 0, 0   # 0x2d6e
        C_CHWIDTH        R3, 0   # 0x2d72
        LD_GLOBAL_IDX    R14, R9, R10, 0, 4   # 0x2d74
        LD_GLOBAL_IDX    R4, R9, R10, 0, 0   # 0x2d78
        SHRI             R11, R3, 9   # 0x2d7c
        C_CHWIDTH        R3, 1   # 0x2d80
        AND              R3, R3, R11, R3   # 0x2d82
        AND              R11, R14, R0, R14   # 0x2d86
        OR               R11, R4, R11, R4   # 0x2d8a
        MOVI             R12, 1   # 0x2d8e
        C_CHWIDTH        R12, 1   # 0x2d92
        AND              R12, R3, R12, R3   # 0x2d94
        C_CHWIDTH        R3, 0   # 0x2d98
        LD_GLOBAL        R3, R15, -136   # 0x2d9a
        C_CHWIDTH        R3, 1   # 0x2d9e
        ADDI             R3, R3, 1   # 0x2da0
        C_CHWIDTH        R3, 0   # 0x2da4
        ST_GLOBAL        R3, R15, -136   # 0x2da6
        SETP_EQ_NPI      P0, R3, R11, 0   # 0x2daa
        BRA_PRED         0, L2b7c   # 0x2dae
        SHRI             R3, R4, 16   # 0x2db2
        SHLI             R14, R14, 16   # 0x2db6
        OR               R3, R14, R3, R14   # 0x2dba
        C_CHWIDTH        R14, 1   # 0x2dbe
        C_AND            R4, R0   # 0x2dc0
        LD_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x2dc2
        C_CHWIDTH        R14, 0   # 0x2dc6
        LD_GLOBAL_IDX    R11, R3, R4, 0, 0   # 0x2dc8
        ST_GLOBAL_IDX    R11, R9, R10, 0, 0   # 0x2dcc
        ST_GLOBAL_IDX    R14, R9, R10, 0, 4   # 0x2dd0
        C_CHWIDTH        R14, 1   # 0x2dd4
        C_MOV            R10, R8   # 0x2dd6
        C_MOV            R11, R1   # 0x2dd8
        LD_GLOBAL_IDX    R14, R10, R11, 0, 4   # 0x2dda
        C_CHWIDTH        R14, 0   # 0x2dde
        LD_GLOBAL_IDX    R9, R10, R11, 0, 0   # 0x2de0
        ST_GLOBAL_IDX    R9, R3, R4, 0, 0   # 0x2de4
        ST_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x2de8
        SHRI             R14, R3, 16   # 0x2dec
        ST_GLOBAL_IDX    R14, R10, R11, 0, 4   # 0x2df0
        SHLI             R3, R3, 16   # 0x2df4
        C_OR             R3, R4   # 0x2df8
        ST_GLOBAL_IDX    R3, R10, R11, 0, 0   # 0x2dfa
        BRA              L2b7c   # 0x2dfe
L2e02:  CHWIDTH_MULTI    32, 0   # 0x2e02
        C_CHWIDTH        R2, 1   # 0x2e06
        MOVI             R0, 255   # 0x2e08
        LD_GLOBAL        R14, R15, -152   # 0x2e0c
        AND              R2, R14, R0, R14   # 0x2e10
        CHWIDTH_MULTI    4, 0   # 0x2e14
        LD_GLOBAL        R0, R15, -136   # 0x2e18
        SHLI             R0, R0, 2   # 0x2e1c
        LD_GLOBAL        R14, R15, -140   # 0x2e20
        C_CHWIDTH        R14, 1   # 0x2e24
        SUB              R14, R0, R14, R0   # 0x2e26
        C_CHWIDTH        R0, 1   # 0x2e2a
        ADD              R0, R14, R7, R14   # 0x2e2c
        CHWIDTH_MULTI    16513, 0   # 0x2e30
        ST_GLOBAL        R0, R15, -196   # 0x2e34
        LD_GLOBAL        R3, R15, -144   # 0x2e38
        C_BRA            L2e4c   # 0x2e3c
L2e3e:  CHWIDTH_MULTI    64, 0   # 0x2e3e
        MOVI             R0, 0   # 0x2e42
        C_MOV            R2, R0   # 0x2e46
        ST_GLOBAL        R2, R15, -196   # 0x2e48
L2e4c:  CHWIDTH_MULTI    4096, 0   # 0x2e4c
        ST_GLOBAL        R5, R15, -204   # 0x2e50
        C_MOV            R14, R3   # 0x2e54
        C_CHWIDTH        R14, 1   # 0x2e56
        C_MOV            R7, R3   # 0x2e58
        C_CHWIDTH        R7, 1   # 0x2e5a
        C_MOV            R6, R3   # 0x2e5c
        C_CHWIDTH        R6, 1   # 0x2e5e
        CVT_SEXT         R0, R14, R7, R6   # 0x2e60
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2e64
        ST_GLOBAL        R2, R15, -208   # 0x2e68
        BRA_PRED         0, L3402   # 0x2e6c
        CHWIDTH_MULTI    192, 0   # 0x2e70
        MOVI             R0, 1   # 0x2e74
        ST_GLOBAL        R0, R15, -184   # 0x2e78
        MOVI             R12, 65535   # 0x2e7c
        C_MOV            R7, R8   # 0x2e80
        C_MOV            R6, R1   # 0x2e82
        ST_GLOBAL        R13, R15, -172   # 0x2e84
        C_BRA            L2eb8   # 0x2e88
L2e8a:  MOVI             R0, 0   # 0x2e8a
        ST_GLOBAL_IDX    R0, R10, R11, 0, 4   # 0x2e8e
        ST_GLOBAL_IDX    R0, R10, R11, 0, 0   # 0x2e92
        LD_GLOBAL        R0, R15, -184   # 0x2e96
        C_SHLI           R0, 1   # 0x2e9a
        ST_GLOBAL        R0, R15, -184   # 0x2e9c
        LD_GLOBAL        R0, R15, -192   # 0x2ea0
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2ea4
        LD_GLOBAL        R8, R15, -180   # 0x2ea8
        C_MOV            R7, R8   # 0x2eac
        LD_GLOBAL        R9, R15, -176   # 0x2eae
        C_MOV            R6, R9   # 0x2eb2
        BRA_PRED         4, L3408   # 0x2eb4
L2eb8:  MOVI             R5, 0   # 0x2eb8
        MOVI             R10, 0   # 0x2ebc
        MOVI             R11, 0   # 0x2ec0
        MOVI             R0, 0   # 0x2ec4
        ST_GLOBAL        R0, R15, -180   # 0x2ec8
        ST_GLOBAL        R0, R15, -176   # 0x2ecc
        C_BRA            L2ede   # 0x2ed0
L2ed2:  SETP_EQ_NPI      P0, R0, R0, 0   # 0x2ed2
        LD_GLOBAL        R5, R15, -188   # 0x2ed6
        BRA_PRED         0, L2e8a   # 0x2eda
L2ede:  LD_GLOBAL        R4, R15, -184   # 0x2ede
        SETP_LT_NPI      P0, R0, R4, 1   # 0x2ee2
        BRA_PRED         0, L2f24   # 0x2ee6
        MOVI             R2, 0   # 0x2eea
        C_MOV            R0, R7   # 0x2eee
        C_MOV            R1, R6   # 0x2ef0
L2ef2:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x2ef2
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x2ef6
        AND              R0, R3, R12, R3   # 0x2efa
        OR               R0, R1, R0, R1   # 0x2efe
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2f02
        BRA_PRED         4, L2f2e   # 0x2f06
        SHRI             R0, R1, 16   # 0x2f0a
        SHLI             R3, R3, 16   # 0x2f0e
        OR               R0, R3, R0, R3   # 0x2f12
        C_AND            R1, R12   # 0x2f16
        C_ADDI           R2, 1   # 0x2f18
        SETP_EQ_NP       P0, R3, R4, R2   # 0x2f1a
        BRA_PRED         4, L2ef2   # 0x2f1e
        C_BRA            L2f3a   # 0x2f22
L2f24:  MOVI             R4, 0   # 0x2f24
        C_MOV            R0, R7   # 0x2f28
        C_MOV            R1, R6   # 0x2f2a
        C_BRA            L2f3a   # 0x2f2c
L2f2e:  MOVI             R0, 0   # 0x2f2e
        ADDI             R4, R2, 1   # 0x2f32
        MOVI             R1, 0   # 0x2f36
L2f3a:  ST_GLOBAL        R5, R15, -192   # 0x2f3a
        ADDI             R2, R5, 1   # 0x2f3e
        ST_GLOBAL        R2, R15, -188   # 0x2f42
        C_MOV            R9, R7   # 0x2f46
        C_MOV            R8, R6   # 0x2f48
        C_MOV            R7, R0   # 0x2f4a
        C_MOV            R6, R1   # 0x2f4c
        LD_GLOBAL        R0, R15, -184   # 0x2f4e
        ST_GLOBAL        R0, R15, -140   # 0x2f52
        C_BRA            L2f70   # 0x2f56
L2f58:  ST_GLOBAL        R4, R15, -180   # 0x2f58
        ST_GLOBAL        R5, R15, -176   # 0x2f5c
L2f60:  C_MOV            R9, R1   # 0x2f60
        C_MOV            R8, R3   # 0x2f62
        C_MOV            R7, R0   # 0x2f64
        C_MOV            R6, R2   # 0x2f66
        C_MOV            R10, R4   # 0x2f68
        C_MOV            R11, R5   # 0x2f6a
        LD_GLOBAL        R4, R15, -136   # 0x2f6c
L2f70:  MOVI             R0, 0   # 0x2f70
        SETP_LT_NP       P0, R0, R0, R4   # 0x2f74
        BRA_PRED         0, L2fb4   # 0x2f78
        SHLI             R0, R7, 16   # 0x2f7c
        AND              R1, R0, R6, R0   # 0x2f80
        ADD              R2, R0, R6, R0   # 0x2f84
        C_OR             R0, R6   # 0x2f88
        C_ANDN           R0, R2   # 0x2f8a
        OR               R0, R1, R0, R1   # 0x2f8c
        SHRI             R0, R0, 31   # 0x2f90
        SHRI             R1, R7, 16   # 0x2f94
        ADD              R0, R1, R0, R1   # 0x2f98
        OR               R0, R2, R0, R2   # 0x2f9c
        LD_GLOBAL        R1, R15, -140   # 0x2fa0
        SETP_LT_NPI      P0, R1, R1, 1   # 0x2fa4
        BRA_PRED         0, L2ed2   # 0x2fa8
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x2fac
        BRA_PRED         0, L2ed2   # 0x2fb0
L2fb4:  SETP_NE_NPI      P0, R0, R4, 0   # 0x2fb4
        BRA_PRED         4, L30f8   # 0x2fb8
        LD_GLOBAL        R0, R15, -140   # 0x2fbc
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2fc0
        BRA_PRED         0, L3382   # 0x2fc4
        SHLI             R0, R7, 16   # 0x2fc8
        AND              R1, R0, R6, R0   # 0x2fcc
        ADD              R2, R0, R6, R0   # 0x2fd0
        C_OR             R0, R6   # 0x2fd4
        C_ANDN           R0, R2   # 0x2fd6
        OR               R0, R1, R0, R1   # 0x2fd8
        SHRI             R0, R0, 31   # 0x2fdc
        SHRI             R1, R7, 16   # 0x2fe0
        ADD              R0, R1, R0, R1   # 0x2fe4
        OR               R0, R2, R0, R2   # 0x2fe8
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2fec
        BRA_PRED         4, L3382   # 0x2ff0
        C_CHWIDTH        R14, 0   # 0x2ff4
        LD_GLOBAL_IDX    R5, R7, R6, 0, 8   # 0x2ff6
        LD_GLOBAL_IDX    R14, R7, R6, 0, 12   # 0x2ffa
        LD_GLOBAL_IDX    R0, R9, R8, 0, 8   # 0x2ffe
        LD_GLOBAL_IDX    R1, R9, R8, 0, 12   # 0x3002
        SHLI             R1, R1, 16   # 0x3006
        SHRI             R2, R0, 16   # 0x300a
        C_OR             R1, R2   # 0x300e
        AND              R2, R0, R12, R0   # 0x3010
        C_CHWIDTH        R12, 1   # 0x3014
        LD_GLOBAL_IDX    R12, R1, R2, 0, 0   # 0x3016
        MOVI             R0, 128   # 0x301a
        C_CHWIDTH        R0, 1   # 0x301e
        AND              R0, R12, R0, R12   # 0x3020
        C_CHWIDTH        R0, 0   # 0x3024
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3026
        ST_GLOBAL        R4, R15, -136   # 0x302a
        ST_GLOBAL        R6, R15, -144   # 0x302e
        BRA_PRED         4, L311a   # 0x3032
        ST_GLOBAL        R2, R15, -168   # 0x3036
        ST_GLOBAL        R1, R15, -164   # 0x303a
        ST_GLOBAL        R14, R15, -160   # 0x303e
        ST_GLOBAL        R5, R15, -156   # 0x3042
        MOVI             R0, 7   # 0x3046
        C_CHWIDTH        R0, 1   # 0x304a
        AND              R0, R12, R0, R12   # 0x304c
        CHWIDTH_MULTI    4097, 0   # 0x3050
        SHRI             R1, R12, 3   # 0x3054
        C_CHWIDTH        R1, 1   # 0x3058
        MOVI             R2, 15   # 0x305a
        AND              R1, R1, R2, R1   # 0x305e
        C_CHWIDTH        R1, 0   # 0x3062
        MULI             R1, R1, 17   # 0x3064
        C_MOV            R3, R1   # 0x3068
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x306a
        BRA_PRED         0, L312a   # 0x306e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3072
        C_MOV            R5, R12   # 0x3076
        BRA_PRED         0, L316a   # 0x3078
        CHWIDTH_MULTI    48, 1   # 0x307c
        ST_GLOBAL        R7, R15, -152   # 0x3080
        MOVI             R0, 34   # 0x3084
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x3088
        C_CHWIDTH        R0, 1   # 0x308c
        MOVI             R6, 34   # 0x308e
        MOV_P            R6, 0, R3, R3, R3   # 0x3092
        C_MOV            R2, R13   # 0x3096
        LD_GLOBAL        R13, R15, -148   # 0x3098
        LD_GLOBAL_IDX    R0, R2, R13, 0, 96   # 0x309c
        C_CHWIDTH        R0, 0   # 0x30a0
        LD_GLOBAL_IDX    R1, R2, R13, 0, 40   # 0x30a2
        LD_GLOBAL_IDX    R5, R2, R13, 0, 2   # 0x30a6
        C_CHWIDTH        R5, 0   # 0x30aa
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x30ac
        C_CHWIDTH        R4, 0   # 0x30b0
        LD_GLOBAL_IDX    R3, R2, R13, 0, 32   # 0x30b2
        LD_GLOBAL_IDX    R2, R2, R13, 0, 36   # 0x30b6
        ST_GLOBAL        R0, R15, -4   # 0x30ba
        SHLI             R0, R2, 16   # 0x30be
        SHRI             R2, R3, 16   # 0x30c2
        OR               R2, R0, R2, R0   # 0x30c6
        MOVI             R0, 65535   # 0x30ca
        C_AND            R3, R0   # 0x30ce
        CALL             R14, 127167   # 0x30d0
        C_CHWIDTH        R0, 1   # 0x30d4
        C_MOV            R2, R13   # 0x30d6
        LD_GLOBAL        R13, R15, -172   # 0x30d8
        LD_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x30dc
        C_CHWIDTH        R0, 0   # 0x30e0
        C_MOV            R5, R1   # 0x30e2
        SETP_NE_NPI      P0, R0, R0, 0   # 0x30e4
        BRA_PRED         0, L3166   # 0x30e8
        C_MOV            R0, R5   # 0x30ec
        C_CHWIDTH        R0, 1   # 0x30ee
        ST_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x30f0
        C_CHWIDTH        R0, 0   # 0x30f4
        C_BRA            L3166   # 0x30f6
L30f8:  LD_GLOBAL_IDX    R1, R7, R6, 0, 0   # 0x30f8
        LD_GLOBAL_IDX    R0, R7, R6, 0, 4   # 0x30fc
        SHLI             R0, R0, 16   # 0x3100
        SHRI             R2, R1, 16   # 0x3104
        C_OR             R0, R2   # 0x3108
        AND              R2, R1, R12, R1   # 0x310a
        MOVI             R1, 0   # 0x310e
        ST_GLOBAL        R1, R15, -136   # 0x3112
        BRA              L336c   # 0x3116
L311a:  C_CHWIDTH        R3, 1   # 0x311a
        MOVI             R0, 127   # 0x311c
        AND              R3, R12, R0, R12   # 0x3120
        MOVI             R2, 128   # 0x3124
        C_BRA            L31c0   # 0x3128
L312a:  C_CHWIDTH        R4, 1   # 0x312a
        ST_GLOBAL        R7, R15, -152   # 0x312c
        C_MOV            R1, R13   # 0x3130
        LD_GLOBAL        R13, R15, -148   # 0x3132
        LD_GLOBAL_IDX    R4, R1, R13, 0, 96   # 0x3136
        C_CHWIDTH        R4, 0   # 0x313a
        ADDI             R2, R13, 64   # 0x313c
        CALL             R14, 128364   # 0x3140
        C_CHWIDTH        R0, 1   # 0x3144
        C_MOV            R2, R13   # 0x3146
        LD_GLOBAL        R13, R15, -172   # 0x3148
        LD_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x314c
        C_CHWIDTH        R0, 0   # 0x3150
        C_MOV            R5, R1   # 0x3152
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3154
        BRA_PRED         0, L3166   # 0x3158
        C_MOV            R0, R5   # 0x315c
        C_CHWIDTH        R0, 1   # 0x315e
        ST_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x3160
        C_CHWIDTH        R0, 0   # 0x3164
L3166:  LD_GLOBAL        R7, R15, -152   # 0x3166
L316a:  C_CHWIDTH        R2, 1   # 0x316a
        LD_GLOBAL        R6, R15, -148   # 0x316c
        LD_GLOBAL_IDX    R2, R13, R6, 0, 96   # 0x3170
        C_CHWIDTH        R2, 0   # 0x3174
        C_MOV            R1, R5   # 0x3176
        CALL             R14, 129912   # 0x3178
        CHWIDTH_MULTI    16394, 1   # 0x317c
        ST_GLOBAL_IDX    R1, R13, R6, 0, 96   # 0x3180
        C_CHWIDTH        R1, 0   # 0x3184
        MOVI             R0, 127   # 0x3186
        AND              R3, R5, R0, R5   # 0x318a
        MOVI             R0, 65280   # 0x318e
        AND              R14, R12, R0, R12   # 0x3192
        OR               R14, R14, R3, R14   # 0x3196
        MOVI             R2, 128   # 0x319a
        OR               R14, R14, R2, R14   # 0x319e
        LD_GLOBAL        R0, R15, -164   # 0x31a2
        LD_GLOBAL        R1, R15, -168   # 0x31a6
        ST_GLOBAL_IDX    R14, R0, R1, 0, 0   # 0x31aa
        C_CHWIDTH        R14, 0   # 0x31ae
        LD_GLOBAL        R6, R15, -144   # 0x31b0
        LD_GLOBAL        R4, R15, -136   # 0x31b4
        LD_GLOBAL        R5, R15, -156   # 0x31b8
        LD_GLOBAL        R14, R15, -160   # 0x31bc
L31c0:  C_CHWIDTH        R12, 1   # 0x31c0
        SHLI             R0, R14, 16   # 0x31c2
        SHRI             R1, R5, 16   # 0x31c6
        OR               R1, R0, R1, R0   # 0x31ca
        MOVI             R0, 65535   # 0x31ce
        C_AND            R5, R0   # 0x31d2
        C_CHWIDTH        R0, 1   # 0x31d4
        LD_GLOBAL_IDX    R12, R1, R5, 0, 0   # 0x31d6
        AND              R0, R12, R2, R12   # 0x31da
        C_CHWIDTH        R0, 0   # 0x31de
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x31e0
        BRA_PRED         4, L32a8   # 0x31e4
        C_CHWIDTH        R3, 0   # 0x31e8
        ST_GLOBAL        R5, R15, -164   # 0x31ea
        ST_GLOBAL        R1, R15, -160   # 0x31ee
        ST_GLOBAL        R3, R15, -156   # 0x31f2
        MOVI             R0, 7   # 0x31f6
        C_CHWIDTH        R0, 1   # 0x31fa
        AND              R0, R12, R0, R12   # 0x31fc
        CHWIDTH_MULTI    4097, 0   # 0x3200
        SHRI             R1, R12, 3   # 0x3204
        C_CHWIDTH        R1, 1   # 0x3208
        MOVI             R2, 15   # 0x320a
        AND              R1, R1, R2, R1   # 0x320e
        C_CHWIDTH        R1, 0   # 0x3212
        MULI             R1, R1, 17   # 0x3214
        C_MOV            R3, R1   # 0x3218
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x321a
        BRA_PRED         0, L32b4   # 0x321e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3222
        C_MOV            R5, R12   # 0x3226
        BRA_PRED         0, L32f4   # 0x3228
        CHWIDTH_MULTI    48, 1   # 0x322c
        ST_GLOBAL        R7, R15, -152   # 0x3230
        MOVI             R0, 34   # 0x3234
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x3238
        C_CHWIDTH        R0, 1   # 0x323c
        MOVI             R6, 34   # 0x323e
        MOV_P            R6, 0, R3, R3, R3   # 0x3242
        C_MOV            R2, R13   # 0x3246
        LD_GLOBAL        R13, R15, -148   # 0x3248
        LD_GLOBAL_IDX    R0, R2, R13, 0, 96   # 0x324c
        C_CHWIDTH        R0, 0   # 0x3250
        LD_GLOBAL_IDX    R1, R2, R13, 0, 40   # 0x3252
        LD_GLOBAL_IDX    R5, R2, R13, 0, 2   # 0x3256
        C_CHWIDTH        R5, 0   # 0x325a
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x325c
        C_CHWIDTH        R4, 0   # 0x3260
        LD_GLOBAL_IDX    R3, R2, R13, 0, 32   # 0x3262
        LD_GLOBAL_IDX    R2, R2, R13, 0, 36   # 0x3266
        ST_GLOBAL        R0, R15, -4   # 0x326a
        SHLI             R0, R2, 16   # 0x326e
        SHRI             R2, R3, 16   # 0x3272
        OR               R2, R0, R2, R0   # 0x3276
        MOVI             R0, 65535   # 0x327a
        C_AND            R3, R0   # 0x327e
        CALL             R14, 126951   # 0x3280
        C_CHWIDTH        R0, 1   # 0x3284
        C_MOV            R2, R13   # 0x3286
        LD_GLOBAL        R13, R15, -172   # 0x3288
        LD_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x328c
        C_CHWIDTH        R0, 0   # 0x3290
        C_MOV            R5, R1   # 0x3292
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3294
        BRA_PRED         0, L32f0   # 0x3298
        C_MOV            R0, R5   # 0x329c
        C_CHWIDTH        R0, 1   # 0x329e
        ST_GLOBAL_IDX    R0, R13, R2, 0, 102   # 0x32a0
        C_CHWIDTH        R0, 0   # 0x32a4
        C_BRA            L32f0   # 0x32a6
L32a8:  MOVI             R0, 127   # 0x32a8
        C_CHWIDTH        R0, 1   # 0x32ac
        AND              R0, R12, R0, R12   # 0x32ae
        C_BRA            L3346   # 0x32b2
L32b4:  C_CHWIDTH        R4, 1   # 0x32b4
        ST_GLOBAL        R7, R15, -152   # 0x32b6
        C_MOV            R1, R13   # 0x32ba
        LD_GLOBAL        R13, R15, -148   # 0x32bc
        LD_GLOBAL_IDX    R4, R1, R13, 0, 96   # 0x32c0
        C_CHWIDTH        R4, 0   # 0x32c4
        ADDI             R2, R13, 64   # 0x32c6
        CALL             R14, 128167   # 0x32ca
        C_CHWIDTH        R0, 1   # 0x32ce
        C_MOV            R2, R13   # 0x32d0
        LD_GLOBAL        R13, R15, -172   # 0x32d2
        LD_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x32d6
        C_CHWIDTH        R0, 0   # 0x32da
        C_MOV            R5, R1   # 0x32dc
        SETP_NE_NPI      P0, R0, R0, 0   # 0x32de
        BRA_PRED         0, L32f0   # 0x32e2
        C_MOV            R0, R5   # 0x32e6
        C_CHWIDTH        R0, 1   # 0x32e8
        ST_GLOBAL_IDX    R0, R13, R2, 0, 100   # 0x32ea
        C_CHWIDTH        R0, 0   # 0x32ee
L32f0:  LD_GLOBAL        R7, R15, -152   # 0x32f0
L32f4:  C_CHWIDTH        R2, 1   # 0x32f4
        LD_GLOBAL        R6, R15, -148   # 0x32f6
        LD_GLOBAL_IDX    R2, R13, R6, 0, 96   # 0x32fa
        C_CHWIDTH        R2, 0   # 0x32fe
        C_MOV            R1, R5   # 0x3300
        CALL             R14, 129715   # 0x3302
        CHWIDTH_MULTI    16386, 1   # 0x3306
        ST_GLOBAL_IDX    R1, R13, R6, 0, 96   # 0x330a
        C_CHWIDTH        R1, 0   # 0x330e
        MOVI             R0, 127   # 0x3310
        C_CHWIDTH        R0, 1   # 0x3314
        AND              R0, R5, R0, R5   # 0x3316
        MOVI             R1, 65280   # 0x331a
        AND              R14, R12, R1, R12   # 0x331e
        OR               R14, R14, R0, R14   # 0x3322
        MOVI             R1, 128   # 0x3326
        OR               R14, R14, R1, R14   # 0x332a
        LD_GLOBAL        R1, R15, -160   # 0x332e
        LD_GLOBAL        R2, R15, -164   # 0x3332
        ST_GLOBAL_IDX    R14, R1, R2, 0, 0   # 0x3336
        LD_GLOBAL        R6, R15, -144   # 0x333a
        LD_GLOBAL        R4, R15, -136   # 0x333e
        LD_GLOBAL        R3, R15, -156   # 0x3342
L3346:  CHWIDTH_MULTI    4105, 0   # 0x3346
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x334a
        MOVI             R12, 65535   # 0x334e
        BRA_PRED         4, L3382   # 0x3352
        LD_GLOBAL_IDX    R1, R7, R6, 0, 0   # 0x3356
        LD_GLOBAL_IDX    R0, R7, R6, 0, 4   # 0x335a
        SHLI             R0, R0, 16   # 0x335e
        SHRI             R2, R1, 16   # 0x3362
        C_OR             R0, R2   # 0x3366
        AND              R2, R1, R12, R1   # 0x3368
L336c:  LD_GLOBAL        R1, R15, -140   # 0x336c
        ADDI             R1, R1, -1   # 0x3370
        ST_GLOBAL        R1, R15, -140   # 0x3374
        C_MOV            R1, R9   # 0x3378
        C_MOV            R3, R8   # 0x337a
        C_MOV            R4, R7   # 0x337c
        C_MOV            R5, R6   # 0x337e
        C_BRA            L33a8   # 0x3380
L3382:  LD_GLOBAL_IDX    R0, R9, R8, 0, 0   # 0x3382
        LD_GLOBAL_IDX    R1, R9, R8, 0, 4   # 0x3386
        SHLI             R1, R1, 16   # 0x338a
        SHRI             R2, R0, 16   # 0x338e
        C_OR             R1, R2   # 0x3392
        AND              R3, R0, R12, R0   # 0x3394
        ADDI             R4, R4, -1   # 0x3398
        ST_GLOBAL        R4, R15, -136   # 0x339c
        C_MOV            R0, R7   # 0x33a0
        C_MOV            R2, R6   # 0x33a2
        C_MOV            R4, R9   # 0x33a4
        C_MOV            R5, R8   # 0x33a6
L33a8:  C_CHWIDTH        R14, 0   # 0x33a8
        SHLI             R6, R10, 16   # 0x33aa
        AND              R7, R6, R11, R6   # 0x33ae
        ADD              R14, R6, R11, R6   # 0x33b2
        C_OR             R6, R11   # 0x33b6
        C_ANDN           R6, R14   # 0x33b8
        OR               R6, R7, R6, R7   # 0x33ba
        SHRI             R6, R6, 31   # 0x33be
        SHRI             R7, R10, 16   # 0x33c2
        ADD              R6, R7, R6, R7   # 0x33c6
        OR               R6, R14, R6, R14   # 0x33ca
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x33ce
        BRA_PRED         0, L2f58   # 0x33d2
        SHLI             R6, R4, 16   # 0x33d6
        ADD              R7, R6, R5, R6   # 0x33da
        ST_GLOBAL_IDX    R7, R10, R11, 0, 0   # 0x33de
        OR               R14, R6, R5, R6   # 0x33e2
        ANDN             R7, R14, R7, R14   # 0x33e6
        C_AND            R6, R5   # 0x33ea
        C_OR             R6, R7   # 0x33ec
        SHRI             R6, R6, 31   # 0x33ee
        SHRI             R7, R4, 16   # 0x33f2
        ADD              R6, R7, R6, R7   # 0x33f6
        ST_GLOBAL_IDX    R6, R10, R11, 0, 4   # 0x33fa
        BRA              L2f60   # 0x33fe
L3402:  CHWIDTH_MULTI    64, 0   # 0x3402
        C_MOV            R9, R1   # 0x3406
L3408:  CHWIDTH_MULTI    16512, 0   # 0x3408
        LD_GLOBAL_IDX    R1, R8, R9, 0, 0   # 0x340c
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x3410
        SHLI             R0, R0, 16   # 0x3414
        SHRI             R2, R1, 16   # 0x3418
        OR               R3, R0, R2, R0   # 0x341c
        MOVI             R0, 65535   # 0x3420
        AND              R4, R1, R0, R1   # 0x3424
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x3428
        SHLI             R1, R1, 16   # 0x342c
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x3430
        SHRI             R5, R2, 16   # 0x3434
        OR               R6, R1, R5, R1   # 0x3438
        C_CHWIDTH        R5, 1   # 0x343c
        AND              R7, R2, R0, R2   # 0x343e
        LD_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x3442
        C_CHWIDTH        R5, 0   # 0x3446
        LD_GLOBAL_IDX    R2, R6, R7, 0, 8   # 0x3448
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x344c
        ST_GLOBAL_IDX    R2, R3, R4, 0, 8   # 0x3450
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x3454
        ST_GLOBAL_IDX    R5, R3, R4, 0, 12   # 0x3458
        AND              R5, R2, R0, R2   # 0x345c
        ST_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x3460
        C_CHWIDTH        R5, 1   # 0x3464
        ST_GLOBAL_IDX    R1, R6, R7, 0, 8   # 0x3466
        LD_GLOBAL_IDX    R5, R6, R7, 0, 4   # 0x346a
        C_CHWIDTH        R5, 0   # 0x346e
        LD_GLOBAL_IDX    R14, R6, R7, 0, 0   # 0x3470
        ST_GLOBAL_IDX    R14, R3, R4, 0, 0   # 0x3474
        ST_GLOBAL_IDX    R5, R3, R4, 0, 4   # 0x3478
        LD_GLOBAL        R10, R15, -204   # 0x347c
        C_MOV            R4, R10   # 0x3480
        C_CHWIDTH        R4, 1   # 0x3482
        C_MOV            R5, R10   # 0x3484
        C_CHWIDTH        R5, 1   # 0x3486
        C_MOV            R11, R10   # 0x3488
        C_CHWIDTH        R11, 1   # 0x348a
        CVT_SEXT         R3, R4, R5, R11   # 0x348c
        CHWIDTH_MULTI    2096, 0   # 0x3490
        MOVI48           R4, 4294967295   # 0x3494
        SETP_LT_NP       P0, R3, R4, R3   # 0x349a
        MOVI             R3, 0   # 0x349e
        ST_GLOBAL_IDX    R3, R6, R7, 0, 4   # 0x34a2
        ST_GLOBAL_IDX    R3, R6, R7, 0, 0   # 0x34a6
        C_MOV            R13, R8   # 0x34aa
        ST_GLOBAL        R9, R15, -176   # 0x34ac
        BRA_PRED         4, L3500   # 0x34b0
L34b4:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x34b4
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x34b8
        SHLI             R4, R4, 16   # 0x34bc
        SHRI             R5, R3, 16   # 0x34c0
        C_OR             R4, R5   # 0x34c4
        C_AND            R3, R0   # 0x34c6
        C_CHWIDTH        R3, 1   # 0x34c8
        LD_GLOBAL_IDX    R3, R4, R3, 0, 2   # 0x34ca
        C_CHWIDTH        R3, 0   # 0x34ce
        SETP_EQ_NP       P0, R3, R3, R10   # 0x34d0
        BRA_PRED         0, L3558   # 0x34d4
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x34d8
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x34dc
        SHRI             R5, R4, 16   # 0x34e0
        SHLI             R14, R3, 16   # 0x34e4
        OR               R8, R14, R5, R14   # 0x34e8
        C_AND            R3, R0   # 0x34ec
        OR               R3, R4, R3, R4   # 0x34ee
        AND              R9, R4, R0, R4   # 0x34f2
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x34f6
        BRA_PRED         4, L34b4   # 0x34fa
        C_BRA            L3550   # 0x34fe
L3500:  LD_GLOBAL        R10, R15, -208   # 0x3500
L3504:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x3504
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x3508
        SHLI             R4, R4, 16   # 0x350c
        SHRI             R5, R3, 16   # 0x3510
        C_OR             R4, R5   # 0x3514
        C_AND            R3, R0   # 0x3516
        C_CHWIDTH        R3, 2   # 0x3518
        LD_GLOBAL_IDX    R3, R4, R3, 0, 0   # 0x351a
        C_CHWIDTH        R3, 0   # 0x351e
        C_AND            R3, R0   # 0x3520
        SETP_EQ_NP       P0, R3, R3, R10   # 0x3522
        BRA_PRED         0, L3558   # 0x3526
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x352a
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x352e
        SHRI             R5, R4, 16   # 0x3532
        SHLI             R14, R3, 16   # 0x3536
        OR               R8, R14, R5, R14   # 0x353a
        C_AND            R3, R0   # 0x353e
        OR               R3, R4, R3, R4   # 0x3540
        AND              R9, R4, R0, R4   # 0x3544
        SETP_NE_NPI      P0, R3, R3, 0   # 0x3548
        BRA_PRED         0, L3504   # 0x354c
L3550:  MOVI             R8, 0   # 0x3550
        MOVI             R9, 0   # 0x3554
L3558:  SHLI             R2, R2, 16   # 0x3558
        SHRI             R3, R1, 16   # 0x355c
        SHLI             R4, R8, 16   # 0x3560
        AND              R5, R4, R9, R4   # 0x3564
        ADD              R14, R4, R9, R4   # 0x3568
        C_OR             R4, R9   # 0x356c
        C_ANDN           R4, R14   # 0x356e
        OR               R4, R5, R4, R5   # 0x3570
        SHRI             R4, R4, 31   # 0x3574
        SHRI             R5, R8, 16   # 0x3578
        ADD              R4, R5, R4, R5   # 0x357c
        OR               R4, R14, R4, R14   # 0x3580
        SETP_NE_NPI      P0, R4, R4, 0   # 0x3584
        BRA_PRED         0, L35ae   # 0x3588
        C_MOV            R5, R13   # 0x358c
        LD_GLOBAL        R14, R15, -176   # 0x358e
        LD_GLOBAL_IDX    R4, R5, R14, 0, 0   # 0x3592
        LD_GLOBAL_IDX    R5, R5, R14, 0, 4   # 0x3596
        SHLI             R5, R5, 16   # 0x359a
        SHRI             R14, R4, 16   # 0x359e
        OR               R8, R5, R14, R5   # 0x35a2
        MOVI             R5, 65535   # 0x35a6
        AND              R9, R4, R5, R4   # 0x35aa
L35ae:  OR               R10, R2, R3, R2   # 0x35ae
        AND              R11, R1, R0, R1   # 0x35b2
        SHLI             R0, R8, 16   # 0x35b6
        AND              R1, R0, R9, R0   # 0x35ba
        ADD              R2, R0, R9, R0   # 0x35be
        C_OR             R0, R9   # 0x35c2
        C_ANDN           R0, R2   # 0x35c4
        OR               R0, R1, R0, R1   # 0x35c6
        SHRI             R0, R0, 31   # 0x35ca
        SHRI             R1, R8, 16   # 0x35ce
        ADD              R0, R1, R0, R1   # 0x35d2
        OR               R0, R2, R0, R2   # 0x35d6
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x35da
        BRA_PRED         0, L363c   # 0x35de
        C_CHWIDTH        R5, 1   # 0x35e2
        C_MOV            R1, R13   # 0x35e4
        LD_GLOBAL        R2, R15, -176   # 0x35e6
        LD_GLOBAL_IDX    R0, R1, R2, 0, 8   # 0x35ea
        LD_GLOBAL_IDX    R1, R1, R2, 0, 12   # 0x35ee
        SHLI             R1, R1, 16   # 0x35f2
        SHRI             R2, R0, 16   # 0x35f6
        C_OR             R1, R2   # 0x35fa
        MOVI             R12, 65535   # 0x35fc
        C_AND            R0, R12   # 0x3600
        LD_GLOBAL_IDX    R5, R1, R0, 0, 0   # 0x3602
        LD_GLOBAL        R2, R15, -196   # 0x3606
L360a:  C_CHWIDTH        R5, 0   # 0x360a
        C_MOV            R1, R5   # 0x360c
        CALL             R14, 127456   # 0x360e
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x3612
        LD_GLOBAL_IDX    R2, R8, R9, 0, 0   # 0x3616
        SHRI             R3, R2, 16   # 0x361a
        SHLI             R4, R0, 16   # 0x361e
        OR               R8, R4, R3, R4   # 0x3622
        C_AND            R0, R12   # 0x3626
        OR               R0, R2, R0, R2   # 0x3628
        AND              R9, R2, R12, R2   # 0x362c
        C_MOV            R2, R1   # 0x3630
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3632
        BRA_PRED         0, L360a   # 0x3636
        C_BRA            L3640   # 0x363a
L363c:  LD_GLOBAL        R2, R15, -196   # 0x363c
L3640:  C_CHWIDTH        R3, 1   # 0x3640
        ST_GLOBAL        R2, R15, -196   # 0x3642
        LD_GLOBAL        R5, R15, -176   # 0x3646
        LD_GLOBAL_IDX    R1, R13, R5, 0, 0   # 0x364a
        LD_GLOBAL_IDX    R0, R13, R5, 0, 4   # 0x364e
        SHLI             R0, R0, 16   # 0x3652
        SHRI             R2, R1, 16   # 0x3656
        OR               R2, R0, R2, R0   # 0x365a
        MOVI             R0, 65535   # 0x365e
        C_AND            R1, R0   # 0x3662
        LD_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x3664
        C_CHWIDTH        R3, 0   # 0x3668
        LD_GLOBAL_IDX    R4, R2, R1, 0, 8   # 0x366a
        ST_GLOBAL_IDX    R4, R6, R7, 0, 8   # 0x366e
        ST_GLOBAL_IDX    R3, R6, R7, 0, 12   # 0x3672
        SHRI             R3, R10, 16   # 0x3676
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x367a
        SHLI             R3, R10, 16   # 0x367e
        C_OR             R3, R11   # 0x3682
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x3684
        C_CHWIDTH        R3, 1   # 0x3688
        LD_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x368a
        C_CHWIDTH        R3, 0   # 0x368e
        LD_GLOBAL_IDX    R4, R2, R1, 0, 0   # 0x3690
        ST_GLOBAL_IDX    R4, R6, R7, 0, 0   # 0x3694
        ST_GLOBAL_IDX    R3, R6, R7, 0, 4   # 0x3698
        SHLI             R3, R6, 16   # 0x369c
        C_OR             R3, R7   # 0x36a0
        SHRI             R4, R6, 16   # 0x36a2
        ST_GLOBAL_IDX    R4, R2, R1, 0, 4   # 0x36a6
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x36aa
        C_MOV            R1, R13   # 0x36ae
        C_MOV            R13, R5   # 0x36b0
        MOVI             R9, 1   # 0x36b2
        MOVI             R3, 0   # 0x36b6
        C_BRA            L36de   # 0x36ba
L36bc:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x36bc
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x36c0
        C_SHLI           R9, 1   # 0x36c4
        LD_GLOBAL        R1, R15, -144   # 0x36c6
        SETP_NE_NPI      P0, R1, R1, 0   # 0x36ca
        LD_GLOBAL        R4, R15, -136   # 0x36ce
        C_MOV            R1, R4   # 0x36d2
        LD_GLOBAL        R5, R15, -140   # 0x36d4
        C_MOV            R13, R5   # 0x36d8
        BRA_PRED         4, L392a   # 0x36da
L36de:  MOVI             R6, 0   # 0x36de
        MOVI             R2, 0   # 0x36e2
        MOVI             R4, 0   # 0x36e6
        MOVI             R5, 0   # 0x36ea
        ST_GLOBAL        R5, R15, -136   # 0x36ee
        ST_GLOBAL        R5, R15, -140   # 0x36f2
        ST_GLOBAL        R9, R15, -152   # 0x36f6
        C_BRA            L370c   # 0x36fa
L36fc:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x36fc
        LD_GLOBAL        R9, R15, -152   # 0x3700
        LD_GLOBAL        R6, R15, -148   # 0x3704
        BRA_PRED         0, L36bc   # 0x3708
L370c:  ST_GLOBAL        R6, R15, -144   # 0x370c
        SETP_LT_NPI      P0, R5, R9, 1   # 0x3710
        BRA_PRED         0, L3754   # 0x3714
        MOVI             R5, 0   # 0x3718
        C_MOV            R6, R1   # 0x371c
        C_MOV            R7, R13   # 0x371e
L3720:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x3720
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x3724
        AND              R6, R14, R0, R14   # 0x3728
        OR               R6, R7, R6, R7   # 0x372c
        SETP_NE_NPI      P0, R6, R6, 0   # 0x3730
        BRA_PRED         4, L375e   # 0x3734
        SHRI             R6, R7, 16   # 0x3738
        SHLI             R14, R14, 16   # 0x373c
        OR               R6, R14, R6, R14   # 0x3740
        C_AND            R7, R0   # 0x3744
        C_ADDI           R5, 1   # 0x3746
        SETP_EQ_NP       P0, R14, R9, R5   # 0x3748
        BRA_PRED         4, L3720   # 0x374c
        C_MOV            R8, R9   # 0x3750
        C_BRA            L376a   # 0x3752
L3754:  MOVI             R8, 0   # 0x3754
        C_MOV            R6, R1   # 0x3758
        C_MOV            R7, R13   # 0x375a
        C_BRA            L376a   # 0x375c
L375e:  MOVI             R6, 0   # 0x375e
        ADDI             R8, R5, 1   # 0x3762
        MOVI             R7, 0   # 0x3766
L376a:  LD_GLOBAL        R5, R15, -144   # 0x376a
        C_ADDI           R5, 1   # 0x376e
        ST_GLOBAL        R5, R15, -148   # 0x3770
        C_MOV            R5, R1   # 0x3774
        C_MOV            R14, R13   # 0x3776
        C_MOV            R1, R6   # 0x3778
        C_MOV            R13, R7   # 0x377a
        C_BRA            L3790   # 0x377c
L377e:  ST_GLOBAL        R6, R15, -136   # 0x377e
        ST_GLOBAL        R7, R15, -140   # 0x3782
L3786:  C_MOV            R5, R11   # 0x3786
        C_MOV            R14, R10   # 0x3788
        C_MOV            R1, R12   # 0x378a
        C_MOV            R2, R6   # 0x378c
        C_MOV            R4, R7   # 0x378e
L3790:  SETP_LT_NP       P0, R6, R3, R8   # 0x3790
        BRA_PRED         0, L37cc   # 0x3794
        SHLI             R6, R1, 16   # 0x3798
        AND              R7, R6, R13, R6   # 0x379c
        ADD              R10, R6, R13, R6   # 0x37a0
        C_OR             R6, R13   # 0x37a4
        C_ANDN           R6, R10   # 0x37a6
        OR               R6, R7, R6, R7   # 0x37a8
        SHRI             R6, R6, 31   # 0x37ac
        SHRI             R7, R1, 16   # 0x37b0
        ADD              R6, R7, R6, R7   # 0x37b4
        OR               R6, R10, R6, R10   # 0x37b8
        SETP_LT_NPI      P0, R7, R9, 1   # 0x37bc
        BRA_PRED         0, L36fc   # 0x37c0
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x37c4
        BRA_PRED         0, L36fc   # 0x37c8
L37cc:  SETP_NE_NPI      P0, R6, R8, 0   # 0x37cc
        BRA_PRED         4, L38ac   # 0x37d0
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x37d4
        BRA_PRED         0, L3884   # 0x37d8
        SHLI             R6, R1, 16   # 0x37dc
        AND              R7, R6, R13, R6   # 0x37e0
        ADD              R10, R6, R13, R6   # 0x37e4
        C_OR             R6, R13   # 0x37e8
        C_ANDN           R6, R10   # 0x37ea
        OR               R6, R7, R6, R7   # 0x37ec
        SHRI             R6, R6, 31   # 0x37f0
        SHRI             R7, R1, 16   # 0x37f4
        ADD              R6, R7, R6, R7   # 0x37f8
        OR               R6, R10, R6, R10   # 0x37fc
        SETP_NE_NPI      P0, R6, R6, 0   # 0x3800
        BRA_PRED         4, L3884   # 0x3804
        C_CHWIDTH        R12, 2   # 0x3808
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x380a
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x380e
        SHLI             R7, R7, 16   # 0x3812
        SHRI             R10, R6, 16   # 0x3816
        C_OR             R7, R10   # 0x381a
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x381c
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x3820
        C_AND            R6, R0   # 0x3824
        LD_GLOBAL_IDX    R12, R7, R6, 0, 1   # 0x3826
        ST_GLOBAL_IDX    R12, R7, R6, 0, 0   # 0x382a
        C_CHWIDTH        R7, 1   # 0x382e
        C_CHWIDTH        R12, 0   # 0x3830
        SHLI             R11, R11, 16   # 0x3832
        SHRI             R12, R10, 16   # 0x3836
        C_OR             R11, R12   # 0x383a
        C_CHWIDTH        R12, 2   # 0x383c
        C_AND            R10, R0   # 0x383e
        LD_GLOBAL_IDX    R12, R11, R10, 0, 1   # 0x3840
        ST_GLOBAL_IDX    R12, R11, R10, 0, 0   # 0x3844
        LD_GLOBAL_IDX    R7, R7, R6, 0, 2   # 0x3848
        C_CHWIDTH        R6, 1   # 0x384c
        LD_GLOBAL_IDX    R6, R11, R10, 0, 2   # 0x384e
        CVT_SEXT         R10, R6, R6, R6   # 0x3852
        C_CHWIDTH        R6, 0   # 0x3856
        CVT_SEXT         R6, R7, R7, R7   # 0x3858
        SETP_LT_NP       P0, R6, R10, R6   # 0x385c
        BRA_PRED         4, L3884   # 0x3860
        CHWIDTH_MULTI    4224, 0   # 0x3864
        LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x3868
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x386c
        SHLI             R7, R7, 16   # 0x3870
        SHRI             R10, R6, 16   # 0x3874
        OR               R12, R7, R10, R7   # 0x3878
        C_MOV            R7, R13   # 0x387c
        AND              R13, R6, R0, R6   # 0x387e
        C_BRA            L38ca   # 0x3882
L3884:  CHWIDTH_MULTI    4224, 0   # 0x3884
        LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x3888
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x388c
        SHLI             R7, R7, 16   # 0x3890
        SHRI             R10, R6, 16   # 0x3894
        OR               R11, R7, R10, R7   # 0x3898
        AND              R10, R6, R0, R6   # 0x389c
        ADDI             R8, R8, -1   # 0x38a0
        C_MOV            R12, R1   # 0x38a4
        C_MOV            R6, R5   # 0x38a6
        C_MOV            R7, R14   # 0x38a8
        C_BRA            L38d4   # 0x38aa
L38ac:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x38ac
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x38b0
        SHLI             R7, R7, 16   # 0x38b4
        SHRI             R8, R6, 16   # 0x38b8
        OR               R12, R7, R8, R7   # 0x38bc
        C_MOV            R7, R13   # 0x38c0
        AND              R13, R6, R0, R6   # 0x38c2
        MOVI             R8, 0   # 0x38c6
L38ca:  ADDI             R9, R9, -1   # 0x38ca
        C_MOV            R11, R5   # 0x38ce
        C_MOV            R10, R14   # 0x38d0
        C_MOV            R6, R1   # 0x38d2
L38d4:  SHLI             R5, R2, 16   # 0x38d4
        AND              R14, R5, R4, R5   # 0x38d8
        ADD              R1, R5, R4, R5   # 0x38dc
        C_OR             R5, R4   # 0x38e0
        C_ANDN           R5, R1   # 0x38e2
        OR               R5, R14, R5, R14   # 0x38e4
        SHRI             R5, R5, 31   # 0x38e8
        SHRI             R14, R2, 16   # 0x38ec
        ADD              R5, R14, R5, R14   # 0x38f0
        C_OR             R1, R5   # 0x38f4
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x38f6
        BRA_PRED         0, L377e   # 0x38fa
        SHLI             R1, R6, 16   # 0x38fe
        ADD              R5, R1, R7, R1   # 0x3902
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x3906
        OR               R14, R1, R7, R1   # 0x390a
        ANDN             R5, R14, R5, R14   # 0x390e
        C_AND            R1, R7   # 0x3912
        C_OR             R1, R5   # 0x3914
        SHRI             R1, R1, 31   # 0x3916
        SHRI             R5, R6, 16   # 0x391a
        ADD              R1, R5, R1, R5   # 0x391e
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x3922
        BRA              L3786   # 0x3926
L392a:  LD_GLOBAL_IDX    R1, R4, R5, 0, 4   # 0x392a
        LD_GLOBAL_IDX    R0, R4, R5, 0, 0   # 0x392e
        MOVI             R6, 65535   # 0x3932
        AND              R2, R1, R6, R1   # 0x3936
        OR               R2, R0, R2, R0   # 0x393a
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x393e
        BRA_PRED         0, L39a6   # 0x3942
        SHRI             R2, R0, 16   # 0x3946
        SHLI             R1, R1, 16   # 0x394a
        OR               R7, R1, R2, R1   # 0x394e
        AND              R8, R0, R6, R0   # 0x3952
        LD_GLOBAL_IDX    R0, R4, R5, 0, 8   # 0x3956
        LD_GLOBAL_IDX    R1, R4, R5, 0, 12   # 0x395a
        C_CHWIDTH        R5, 1   # 0x395e
        SHLI             R1, R1, 16   # 0x3960
        SHRI             R2, R0, 16   # 0x3964
        C_OR             R1, R2   # 0x3968
        C_AND            R0, R6   # 0x396a
        LD_GLOBAL_IDX    R5, R1, R0, 0, 0   # 0x396c
        LD_GLOBAL        R2, R15, -196   # 0x3970
L3974:  C_CHWIDTH        R5, 0   # 0x3974
        C_MOV            R1, R5   # 0x3976
        CALL             R14, 127019   # 0x3978
        LD_GLOBAL_IDX    R0, R7, R8, 0, 4   # 0x397c
        LD_GLOBAL_IDX    R2, R7, R8, 0, 0   # 0x3980
        SHRI             R3, R2, 16   # 0x3984
        SHLI             R4, R0, 16   # 0x3988
        OR               R7, R4, R3, R4   # 0x398c
        C_AND            R0, R6   # 0x3990
        OR               R0, R2, R0, R2   # 0x3992
        AND              R8, R2, R6, R2   # 0x3996
        C_MOV            R2, R1   # 0x399a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x399c
        BRA_PRED         0, L3974   # 0x39a0
        C_BRA            L39aa   # 0x39a4
L39a6:  LD_GLOBAL        R2, R15, -196   # 0x39a6
L39aa:  C_MOV            R1, R2   # 0x39aa
        LD_GLOBAL        R14, R15, -200   # 0x39ac
        LD_GLOBAL        R13, R15, -132   # 0x39b0
        LD_GLOBAL        R12, R15, -128   # 0x39b4
        LD_GLOBAL        R11, R15, -124   # 0x39b8
        LD_GLOBAL        R10, R15, -120   # 0x39bc
        LD_GLOBAL        R9, R15, -116   # 0x39c0
        LD_GLOBAL        R8, R15, -112   # 0x39c4
        C_RET            224   # 0x39c8
        MOVI             R15, 2   # 0x39ca
        LD_GLOBAL        R15, R15, 24   # 0x39ce
        SRD              R14, 2   # 0x39d2
        C_ADD            R15, R14   # 0x39d4
        MOVI             R8, 2   # 0x39d6
        LD_GLOBAL        R0, R8, 36   # 0x39da
        MOVI             R1, 2000   # 0x39de
        SRD              R2, 0   # 0x39e2
        ST_GLOBAL        R2, R15, -324   # 0x39e4
        MADLO            R3, R2, R1, R0   # 0x39e8
        ADDI             R4, R3, 666   # 0x39ec
        ST_GLOBAL        R4, R15, -328   # 0x39f0
        LD_GLOBAL        R0, R8, 32   # 0x39f4
        SHLI             R1, R0, 16   # 0x39f8
        C_MOV            R9, R0   # 0x39fc
        ADD              R2, R1, R4, R1   # 0x39fe
        OR               R0, R1, R4, R1   # 0x3a02
        C_ANDN           R0, R2   # 0x3a06
        AND              R4, R1, R4, R1   # 0x3a08
        OR               R0, R4, R0, R4   # 0x3a0c
        ADDI             R4, R3, 1332   # 0x3a10
        ADD              R5, R1, R4, R1   # 0x3a14
        OR               R6, R1, R4, R1   # 0x3a18
        C_ANDN           R6, R5   # 0x3a1c
        AND              R4, R1, R4, R1   # 0x3a1e
        C_OR             R4, R6   # 0x3a22
        ADD              R6, R1, R3, R1   # 0x3a24
        OR               R7, R1, R3, R1   # 0x3a28
        C_ANDN           R7, R6   # 0x3a2c
        C_AND            R1, R3   # 0x3a2e
        C_OR             R1, R7   # 0x3a30
        LD_GLOBAL        R7, R8, 48   # 0x3a32
        MOVI             R8, 7   # 0x3a36
        ST_GLOBAL        R8, R15, -272   # 0x3a3a
        ST_GLOBAL        R7, R15, -276   # 0x3a3e
        MOVI             R7, 102   # 0x3a42
        C_MOV            R8, R7   # 0x3a46
        C_CHWIDTH        R8, 1   # 0x3a48
        ST_GLOBAL        R8, R15, -316   # 0x3a4a
        C_CHWIDTH        R8, 0   # 0x3a4e
        ST_GLOBAL        R6, R15, -304   # 0x3a50
        ST_GLOBAL        R6, R15, -312   # 0x3a54
        ST_GLOBAL        R5, R15, -288   # 0x3a58
        ST_GLOBAL        R2, R15, -296   # 0x3a5c
        SHRI             R1, R1, 31   # 0x3a60
        C_MOV            R2, R9   # 0x3a64
        ST_GLOBAL        R2, R15, -332   # 0x3a66
        SHRI             R5, R2, 16   # 0x3a6a
        ADD              R1, R5, R1, R5   # 0x3a6e
        ST_GLOBAL        R1, R15, -300   # 0x3a72
        ST_GLOBAL        R1, R15, -308   # 0x3a76
        SHRI             R1, R4, 31   # 0x3a7a
        ADD              R1, R5, R1, R5   # 0x3a7e
        ST_GLOBAL        R1, R15, -284   # 0x3a82
        SHRI             R0, R0, 31   # 0x3a86
        ADD              R0, R5, R0, R5   # 0x3a8a
        ST_GLOBAL        R0, R15, -292   # 0x3a8e
        MOVI             R0, 0   # 0x3a92
        ST_GLOBAL        R0, R15, -320   # 0x3a96
        MOVI             R0, 666   # 0x3a9a
        ST_GLOBAL        R0, R15, -280   # 0x3a9e
        MOVI             R1, 666   # 0x3aa2
        MOVI             R4, 0   # 0x3aa6
        CALL             R14, 123561   # 0x3aaa
        SHLI             R0, R1, 16   # 0x3aae
        ADD              R3, R0, R2, R0   # 0x3ab2
        OR               R4, R0, R2, R0   # 0x3ab6
        C_ANDN           R4, R3   # 0x3aba
        ST_GLOBAL        R3, R15, -264   # 0x3abc
        C_AND            R0, R2   # 0x3ac0
        C_OR             R0, R4   # 0x3ac2
        SHRI             R0, R0, 31   # 0x3ac4
        SHRI             R1, R1, 16   # 0x3ac8
        ADD              R0, R1, R0, R1   # 0x3acc
        ST_GLOBAL        R0, R15, -260   # 0x3ad0
        MOVI             R0, 65216   # 0x3ad4
        ADDI             R6, R0, 64   # 0x3ad8
        ADDI             R5, R15, -1   # 0x3adc
        MOVI             R1, 666   # 0x3ae0
        LD_GLOBAL        R2, R15, -332   # 0x3ae4
        LD_GLOBAL        R3, R15, -328   # 0x3ae8
        MOVI             R4, 0   # 0x3aec
        CALL             R14, 124710   # 0x3af0
        C_CHWIDTH        R2, 1   # 0x3af4
        MOVI             R0, 65535   # 0x3af6
        LD_GLOBAL        R1, R15, -288   # 0x3afa
        AND              R4, R1, R0, R1   # 0x3afe
        SHRI             R0, R1, 16   # 0x3b02
        LD_GLOBAL        R1, R15, -284   # 0x3b06
        SHLI             R1, R1, 16   # 0x3b0a
        OR               R3, R1, R0, R1   # 0x3b0e
        LD_GLOBAL        R1, R15, -280   # 0x3b12
        LD_GLOBAL        R2, R15, -320   # 0x3b16
        C_CHWIDTH        R2, 0   # 0x3b1a
        CALL             R14, 125065   # 0x3b1c
        MOVI             R1, 0   # 0x3b20
        ST_GLOBAL        R1, R15, -220   # 0x3b24
        ST_GLOBAL        R1, R15, -224   # 0x3b28
        LD_GLOBAL        R0, R15, -276   # 0x3b2c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3b30
        BRA_PRED         0, L3c10   # 0x3b34
        ADDI             R1, R15, -1   # 0x3b38
        MOVI             R8, 1   # 0x3b3c
        MOVI             R2, 65216   # 0x3b40
        MOVI             R3, 1   # 0x3b44
        CALL             R14, 128949   # 0x3b48
        C_CHWIDTH        R2, 1   # 0x3b4c
        LD_GLOBAL        R2, R15, -224   # 0x3b4e
        C_CHWIDTH        R2, 0   # 0x3b52
        CALL             R14, 128650   # 0x3b54
        C_CHWIDTH        R1, 1   # 0x3b58
        ST_GLOBAL        R1, R15, -224   # 0x3b5a
        C_CHWIDTH        R1, 0   # 0x3b5e
        ADDI             R1, R15, -1   # 0x3b60
        MOVI             R2, 65216   # 0x3b64
        MOVI             R3, 65535   # 0x3b68
        CALL             R14, 128931   # 0x3b6c
        C_CHWIDTH        R2, 1   # 0x3b70
        LD_GLOBAL        R2, R15, -224   # 0x3b72
        C_CHWIDTH        R2, 0   # 0x3b76
        CALL             R14, 128632   # 0x3b78
        C_MOV            R14, R1   # 0x3b7c
        C_MOV            R0, R14   # 0x3b7e
        C_CHWIDTH        R0, 1   # 0x3b80
        ST_GLOBAL        R0, R15, -222   # 0x3b82
        C_CHWIDTH        R0, 0   # 0x3b86
        C_MOV            R0, R14   # 0x3b88
        C_CHWIDTH        R0, 1   # 0x3b8a
        ST_GLOBAL        R0, R15, -224   # 0x3b8c
        C_CHWIDTH        R0, 0   # 0x3b90
        LD_GLOBAL        R0, R15, -276   # 0x3b92
        SETP_LT_U_NPI    P0, R0, R0, 2   # 0x3b96
        C_MOV            R13, R14   # 0x3b9a
        BRA_PRED         0, L3c00   # 0x3b9c
L3ba0:  ADDI             R1, R15, -1   # 0x3ba0
        MOVI             R2, 65216   # 0x3ba4
        MOVI             R3, 1   # 0x3ba8
        CALL             R14, 128899   # 0x3bac
        C_CHWIDTH        R2, 1   # 0x3bb0
        LD_GLOBAL        R2, R15, -224   # 0x3bb2
        C_CHWIDTH        R2, 0   # 0x3bb6
        CALL             R14, 128600   # 0x3bb8
        C_CHWIDTH        R1, 1   # 0x3bbc
        ST_GLOBAL        R1, R15, -224   # 0x3bbe
        C_CHWIDTH        R1, 0   # 0x3bc2
        ADDI             R1, R15, -1   # 0x3bc4
        MOVI             R2, 65216   # 0x3bc8
        MOVI             R3, 65535   # 0x3bcc
        CALL             R14, 128881   # 0x3bd0
        C_CHWIDTH        R2, 1   # 0x3bd4
        LD_GLOBAL        R2, R15, -224   # 0x3bd6
        C_CHWIDTH        R2, 0   # 0x3bda
        CALL             R14, 128582   # 0x3bdc
        C_ADDI           R8, 1   # 0x3be0
        LD_GLOBAL        R0, R15, -276   # 0x3be2
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x3be6
        C_MOV            R13, R1   # 0x3bea
        C_MOV            R0, R13   # 0x3bec
        C_CHWIDTH        R0, 1   # 0x3bee
        ST_GLOBAL        R0, R15, -224   # 0x3bf0
        C_CHWIDTH        R0, 0   # 0x3bf4
        BRA_PRED         0, L3ba0   # 0x3bf6
        C_CHWIDTH        R14, 1   # 0x3bfa
        LD_GLOBAL        R14, R15, -222   # 0x3bfc
L3c00:  C_CHWIDTH        R14, 0   # 0x3c00
        CHWIDTH_MULTI    30720, 1   # 0x3c02
        LD_GLOBAL        R12, R15, -218   # 0x3c06
        LD_GLOBAL        R11, R15, -220   # 0x3c0a
        C_BRA            L3c20   # 0x3c0e
L3c10:  C_MOV            R12, R1   # 0x3c10
        C_MOV            R11, R12   # 0x3c12
        C_CHWIDTH        R11, 1   # 0x3c14
        C_MOV            R14, R12   # 0x3c16
        C_CHWIDTH        R14, 1   # 0x3c18
        C_MOV            R13, R12   # 0x3c1a
        CHWIDTH_MULTI    12288, 1   # 0x3c1c
L3c20:  LD_GLOBAL        R1, R15, -324   # 0x3c20
        C_SHLI           R1, 3   # 0x3c24
        MOVI             R0, 2   # 0x3c26
        LD_GLOBAL        R0, R0, 44   # 0x3c2a
        C_ADD            R0, R1   # 0x3c2e
        ST_GLOBAL_SLOT   R13, 1, R0, 0, 0   # 0x3c30
        ADDI             R1, R0, 2   # 0x3c34
        ST_GLOBAL_SLOT   R14, 1, R1, 0, 0   # 0x3c38
        ADDI             R1, R0, 4   # 0x3c3c
        ST_GLOBAL_SLOT   R11, 1, R1, 0, 0   # 0x3c40
        C_ADDI           R0, 6   # 0x3c44
        ST_GLOBAL_SLOT   R12, 1, R0, 0, 0   # 0x3c46
        C_EXIT           0   # 0x3c4a
