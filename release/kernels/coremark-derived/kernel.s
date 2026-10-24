# coremark-derived: test/coremark-derived, compiled; ccv-as source, reassembled
# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base
# (0x1000: function pointers are absolute); the kernel's entry is 0x3bc2.
        ST_LOCAL         R14, 68   # 0x0000
        C_MOV            R14, R3   # 0x0004
        C_MOV            R7, R2   # 0x0006
        MOVI48           R0, 3435973837   # 0x0008
        MUL_HI_U         R9, R1, R0, R1   # 0x000e
        C_SHRI           R9, 4   # 0x0012
        ADDI             R2, R9, -2   # 0x0014
        C_MOV            R0, R2   # 0x0018
        C_SHLI           R0, 4   # 0x001a
        ADD              R10, R14, R0, R14   # 0x001c
        C_MOV            R0, R2   # 0x0020
        SHLI             R5, R7, 16   # 0x0022
        ADD              R13, R5, R10, R5   # 0x0026
        OR               R2, R5, R10, R5   # 0x002a
        C_ANDN           R2, R13   # 0x002e
        AND              R3, R5, R10, R5   # 0x0030
        OR               R2, R3, R2, R3   # 0x0034
        ST_GLOBAL_IDX    R13, R7, R14, 0, 8   # 0x0038
        SHRI             R15, R2, 31   # 0x003c
        SHRI             R6, R7, 16   # 0x0040
        ADD              R8, R6, R15, R6   # 0x0044
        ST_GLOBAL_IDX    R8, R7, R14, 0, 12   # 0x0048
        MOVI             R2, 0   # 0x004c
        ST_GLOBAL_IDX    R2, R7, R14, 0, 4   # 0x0050
        ST_GLOBAL_IDX    R2, R7, R14, 0, 0   # 0x0054
        MOVI             R3, 32896   # 0x0058
        C_CHWIDTH        R3, 1   # 0x005c
        ST_GLOBAL_IDX    R3, R7, R10, 0, 0   # 0x005e
        C_CHWIDTH        R3, 0   # 0x0062
        C_MOV            R3, R2   # 0x0064
        C_CHWIDTH        R3, 1   # 0x0066
        ST_GLOBAL_IDX    R3, R7, R10, 0, 2   # 0x0068
        SETP_LT_U_NPI    P0, R3, R0, 3   # 0x006c
        ST_LOCAL         R10, 16   # 0x0070
        BRA_PRED         0, L00fa   # 0x0074
        C_CHWIDTH        R3, 0   # 0x0078
        ADDI             R3, R14, 16   # 0x007a
        C_MOV            R2, R10   # 0x007e
        ADD              R10, R5, R3, R5   # 0x0080
        OR               R11, R5, R3, R5   # 0x0084
        C_ANDN           R11, R10   # 0x0088
        AND              R12, R5, R3, R5   # 0x008a
        OR               R11, R12, R11, R12   # 0x008e
        MOVI             R12, 0   # 0x0092
        ST_GLOBAL_IDX    R12, R7, R14, 0, 20   # 0x0096
        ST_GLOBAL_IDX    R12, R7, R14, 0, 16   # 0x009a
        ST_GLOBAL_IDX    R10, R7, R14, 0, 0   # 0x009e
        SHRI             R10, R11, 31   # 0x00a2
        ADD              R10, R6, R10, R6   # 0x00a6
        ST_GLOBAL_IDX    R10, R7, R14, 0, 4   # 0x00aa
        ADDI             R10, R2, 4   # 0x00ae
        ADD              R11, R5, R10, R5   # 0x00b2
        ST_GLOBAL_IDX    R11, R7, R14, 0, 24   # 0x00b6
        OR               R12, R5, R10, R5   # 0x00ba
        ANDN             R11, R12, R11, R12   # 0x00be
        AND              R10, R5, R10, R5   # 0x00c2
        C_OR             R10, R11   # 0x00c6
        SHRI             R10, R10, 31   # 0x00c8
        ADD              R10, R6, R10, R6   # 0x00cc
        ST_GLOBAL_IDX    R10, R7, R14, 0, 28   # 0x00d0
        MOVI             R10, 32767   # 0x00d4
        C_CHWIDTH        R10, 1   # 0x00d8
        ST_GLOBAL_IDX    R10, R7, R2, 0, 6   # 0x00da
        C_CHWIDTH        R10, 0   # 0x00de
        MOVI             R10, 65535   # 0x00e0
        C_CHWIDTH        R10, 1   # 0x00e4
        ST_GLOBAL_IDX    R10, R7, R2, 0, 4   # 0x00e6
        C_CHWIDTH        R10, 0   # 0x00ea
        ADDI             R12, R14, 32   # 0x00ec
        ADDI             R10, R2, 8   # 0x00f0
        ST_LOCAL         R7, 12   # 0x00f4
        C_BRA            L010a   # 0x00f8
L00fa:  C_CHWIDTH        R3, 0   # 0x00fa
        ST_LOCAL         R2, 12   # 0x00fc
        ADDI             R12, R14, 16   # 0x0100
        C_ADDI           R10, 4   # 0x0104
        MOVI             R3, 0   # 0x0106
L010a:  C_MOV            R11, R4   # 0x010a
        SETP_EQ_NPI      P0, R4, R0, 0   # 0x010c
        ST_LOCAL         R0, 72   # 0x0110
        BRA_PRED         0, L05f0   # 0x0114
        ST_LOCAL         R11, 32   # 0x0118
        ANDI             R2, R9, 1   # 0x011c
        ADDI             R1, R1, -60   # 0x0120
        SETP_LT_U_NPI    P0, R1, R1, 20   # 0x0124
        C_MOV            R1, R0   # 0x0128
        C_SHLI           R1, 2   # 0x012a
        ST_LOCAL         R1, 20   # 0x012c
        BRA_PRED         4, L0142   # 0x0130
        MOVI             R1, 0   # 0x0134
        C_MOV            R4, R1   # 0x0138
        MOVI             R9, 0   # 0x013a
        BRA              L048a   # 0x013e
L0142:  ST_LOCAL         R2, 76   # 0x0142
        MOVI             R4, 0   # 0x0146
        ANDI             R0, R0, -2   # 0x014a
        ST_LOCAL         R0, 24   # 0x014e
        MOVI             R1, 120   # 0x0152
        C_MOV            R2, R1   # 0x0156
        ST_LOCAL         R2, 44   # 0x0158
        MOVI             R1, 6   # 0x015c
        C_MOV            R2, R1   # 0x0160
        ST_LOCAL         R2, 56   # 0x0162
        MOVI             R1, 32767   # 0x0166
        C_MOV            R2, R1   # 0x016a
        ST_LOCAL         R2, 48   # 0x016c
        MOVI             R1, 1   # 0x0170
        C_MOV            R2, R1   # 0x0174
        ST_LOCAL         R2, 60   # 0x0176
        MOVI             R1, 7   # 0x017a
        C_MOV            R2, R1   # 0x017e
        ST_LOCAL         R2, 64   # 0x0180
        ST_LOCAL         R15, 28   # 0x0184
        ST_LOCAL         R13, 36   # 0x0188
        ST_LOCAL         R8, 40   # 0x018c
        C_BRA            L01a4   # 0x0190
L0192:  C_MOV            R10, R11   # 0x0192
        C_MOV            R12, R9   # 0x0194
L0196:  C_ADDI           R4, 2   # 0x0196
        LD_LOCAL         R0, 24   # 0x0198
        SETP_EQ_NP       P0, R0, R0, R4   # 0x019c
        BRA_PRED         0, L047e   # 0x01a0
L01a4:  ADDI             R9, R12, 16   # 0x01a4
        ADD              R1, R5, R9, R5   # 0x01a8
        SETP_LT_U_NP     P0, R11, R1, R13   # 0x01ac
        OR               R11, R5, R9, R5   # 0x01b0
        ANDN             R1, R11, R1, R11   # 0x01b4
        AND              R11, R5, R9, R5   # 0x01b8
        OR               R1, R11, R1, R11   # 0x01bc
        SHRI             R1, R1, 31   # 0x01c0
        SETP_EQ_NP       P1, R11, R1, R15   # 0x01c4
        ADD              R11, R6, R1, R6   # 0x01c8
        C_MOV            R1, R4   # 0x01cc
        SETP_LT_U_NP     P2, R11, R11, R8   # 0x01ce
        BRA_PRED         2, L01e4   # 0x01d2
        PAND             P0, 1, 0   # 0x01d6
        BRA_PRED         0, L01e4   # 0x01d8
        C_MOV            R11, R10   # 0x01dc
        C_MOV            R9, R12   # 0x01de
        BRA              L030a   # 0x01e0
L01e4:  LD_LOCAL         R0, 16   # 0x01e4
        LD_LOCAL         R2, 20   # 0x01e8
        ADD              R11, R0, R2, R0   # 0x01ec
        ADD              R0, R5, R11, R5   # 0x01f0
        OR               R2, R5, R11, R5   # 0x01f4
        C_ANDN           R2, R0   # 0x01f8
        AND              R11, R5, R11, R5   # 0x01fa
        OR               R2, R11, R2, R11   # 0x01fe
        ADDI             R11, R10, 4   # 0x0202
        ADD              R8, R5, R11, R5   # 0x0206
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x020a
        OR               R0, R5, R11, R5   # 0x020e
        C_ANDN           R0, R8   # 0x0212
        AND              R8, R5, R11, R5   # 0x0214
        OR               R0, R8, R0, R8   # 0x0218
        SHRI             R0, R0, 31   # 0x021c
        SHRI             R2, R2, 31   # 0x0220
        SETP_EQ_NP       P1, R8, R0, R2   # 0x0224
        ADD              R0, R6, R0, R6   # 0x0228
        ADD              R2, R6, R2, R6   # 0x022c
        SETP_LT_U_NP     P2, R0, R0, R2   # 0x0230
        BRA_PRED         2, L0244   # 0x0234
        PAND             P0, 1, 0   # 0x0238
        BRA_PRED         0, L0244   # 0x023a
        C_MOV            R11, R10   # 0x023e
        C_MOV            R9, R12   # 0x0240
        C_BRA            L0300   # 0x0242
L0244:  C_CHWIDTH        R0, 1   # 0x0244
        LD_LOCAL         R2, 32   # 0x0246
        XOR              R0, R1, R2, R1   # 0x024a
        C_CHWIDTH        R0, 0   # 0x024e
        SHLI             R0, R0, 3   # 0x0250
        LD_LOCAL         R2, 44   # 0x0254
        C_CHWIDTH        R2, 1   # 0x0258
        AND              R2, R0, R2, R0   # 0x025a
        LD_LOCAL         R0, 56   # 0x025e
        C_CHWIDTH        R0, 1   # 0x0262
        AND              R0, R1, R0, R1   # 0x0264
        OR               R0, R2, R0, R2   # 0x0268
        CHWIDTH_MULTI    5, 0   # 0x026c
        MULI             R0, R0, 257   # 0x0270
        C_CHWIDTH        R0, 1   # 0x0274
        LD_LOCAL         R13, 12   # 0x0276
        SHLI             R2, R13, 16   # 0x027a
        AND              R8, R2, R3, R2   # 0x027e
        ADD              R15, R2, R3, R2   # 0x0282
        C_OR             R2, R3   # 0x0286
        C_ANDN           R2, R15   # 0x0288
        OR               R2, R8, R2, R8   # 0x028a
        SHRI             R2, R2, 31   # 0x028e
        SHRI             R3, R13, 16   # 0x0292
        ADD              R2, R3, R2, R3   # 0x0296
        ST_GLOBAL_IDX    R15, R7, R12, 0, 0   # 0x029a
        ST_GLOBAL_IDX    R2, R7, R12, 0, 4   # 0x029e
        ADD              R2, R5, R12, R5   # 0x02a2
        OR               R3, R5, R12, R5   # 0x02a6
        C_ANDN           R3, R2   # 0x02aa
        AND              R15, R5, R12, R5   # 0x02ac
        OR               R3, R15, R3, R15   # 0x02b0
        SHRI             R3, R3, 31   # 0x02b4
        ADD              R3, R6, R3, R6   # 0x02b8
        ST_GLOBAL_IDX    R3, R7, R14, 0, 4   # 0x02bc
        ST_GLOBAL_IDX    R2, R7, R14, 0, 0   # 0x02c0
        ADD              R2, R5, R10, R5   # 0x02c4
        OR               R3, R5, R10, R5   # 0x02c8
        C_ANDN           R3, R2   # 0x02cc
        AND              R15, R5, R10, R5   # 0x02ce
        OR               R3, R15, R3, R15   # 0x02d2
        LD_LOCAL         R15, 28   # 0x02d6
        SHRI             R3, R3, 31   # 0x02da
        ADD              R3, R6, R3, R6   # 0x02de
        ST_GLOBAL_IDX    R3, R7, R12, 0, 12   # 0x02e2
        ST_GLOBAL_IDX    R2, R7, R12, 0, 8   # 0x02e6
        LD_LOCAL         R3, 48   # 0x02ea
        C_CHWIDTH        R3, 1   # 0x02ee
        ST_GLOBAL_IDX    R3, R7, R10, 0, 2   # 0x02f0
        C_CHWIDTH        R3, 0   # 0x02f4
        ST_GLOBAL_IDX    R0, R7, R10, 0, 0   # 0x02f6
        ST_LOCAL         R7, 12   # 0x02fa
        C_MOV            R3, R12   # 0x02fe
L0300:  C_CHWIDTH        R0, 0   # 0x0300
        LD_LOCAL         R8, 40   # 0x0302
        LD_LOCAL         R13, 36   # 0x0306
L030a:  ADDI             R12, R9, 16   # 0x030a
        ADD              R0, R5, R12, R5   # 0x030e
        SETP_LT_U_NP     P0, R2, R0, R13   # 0x0312
        OR               R2, R5, R12, R5   # 0x0316
        ANDN             R0, R2, R0, R2   # 0x031a
        AND              R2, R5, R12, R5   # 0x031e
        OR               R0, R2, R0, R2   # 0x0322
        SHRI             R0, R0, 31   # 0x0326
        SETP_EQ_NP       P1, R2, R0, R15   # 0x032a
        ADD              R0, R6, R0, R6   # 0x032e
        SETP_LT_U_NP     P2, R0, R0, R8   # 0x0332
        BRA_PRED         2, L0340   # 0x0336
        PAND             P0, 1, 0   # 0x033a
        BRA_PRED         4, L0192   # 0x033c
L0340:  LD_LOCAL         R0, 16   # 0x0340
        LD_LOCAL         R2, 20   # 0x0344
        C_ADD            R0, R2   # 0x0348
        ADD              R2, R5, R0, R5   # 0x034a
        OR               R15, R5, R0, R5   # 0x034e
        C_ANDN           R15, R2   # 0x0352
        AND              R0, R5, R0, R5   # 0x0354
        C_OR             R0, R15   # 0x0358
        ADDI             R10, R11, 4   # 0x035a
        ADD              R15, R5, R10, R5   # 0x035e
        SETP_LT_U_NP     P0, R2, R15, R2   # 0x0362
        OR               R2, R5, R10, R5   # 0x0366
        C_ANDN           R2, R15   # 0x036a
        AND              R15, R5, R10, R5   # 0x036c
        OR               R2, R15, R2, R15   # 0x0370
        SHRI             R2, R2, 31   # 0x0374
        SHRI             R0, R0, 31   # 0x0378
        SETP_EQ_NP       P1, R15, R2, R0   # 0x037c
        ADD              R2, R6, R2, R6   # 0x0380
        ADD              R0, R6, R0, R6   # 0x0384
        SETP_LT_U_NP     P2, R0, R2, R0   # 0x0388
        BRA_PRED         2, L039c   # 0x038c
        PAND             P0, 1, 0   # 0x0390
        BRA_PRED         0, L039c   # 0x0392
        C_MOV            R10, R11   # 0x0396
        C_MOV            R12, R9   # 0x0398
        C_BRA            L0476   # 0x039a
L039c:  C_CHWIDTH        R0, 1   # 0x039c
        LD_LOCAL         R2, 60   # 0x039e
        C_CHWIDTH        R2, 1   # 0x03a2
        OR               R2, R1, R2, R1   # 0x03a4
        LD_LOCAL         R1, 32   # 0x03a8
        XOR              R0, R2, R1, R2   # 0x03ac
        C_CHWIDTH        R0, 0   # 0x03b0
        LD_LOCAL         R1, 64   # 0x03b2
        AND              R2, R2, R1, R2   # 0x03b6
        SHLI             R0, R0, 3   # 0x03ba
        LD_LOCAL         R1, 44   # 0x03be
        C_CHWIDTH        R1, 1   # 0x03c2
        AND              R1, R0, R1, R0   # 0x03c4
        C_CHWIDTH        R0, 1   # 0x03c8
        OR               R0, R1, R2, R1   # 0x03ca
        CHWIDTH_MULTI    7, 0   # 0x03ce
        MULI             R0, R0, 257   # 0x03d2
        C_MOV            R2, R0   # 0x03d6
        ST_LOCAL         R2, 52   # 0x03d8
        C_MOV            R0, R6   # 0x03dc
        C_MOV            R6, R13   # 0x03de
        C_MOV            R13, R8   # 0x03e0
        LD_LOCAL         R8, 12   # 0x03e2
        SHLI             R1, R8, 16   # 0x03e6
        AND              R2, R1, R3, R1   # 0x03ea
        ADD              R15, R1, R3, R1   # 0x03ee
        C_OR             R1, R3   # 0x03f2
        C_ANDN           R1, R15   # 0x03f4
        OR               R1, R2, R1, R2   # 0x03f6
        SHRI             R1, R1, 31   # 0x03fa
        SHRI             R2, R8, 16   # 0x03fe
        C_MOV            R8, R13   # 0x0402
        C_MOV            R13, R6   # 0x0404
        C_MOV            R6, R0   # 0x0406
        ADD              R1, R2, R1, R2   # 0x0408
        ST_GLOBAL_IDX    R15, R7, R9, 0, 0   # 0x040c
        ST_GLOBAL_IDX    R1, R7, R9, 0, 4   # 0x0410
        ADD              R1, R5, R9, R5   # 0x0414
        OR               R2, R5, R9, R5   # 0x0418
        C_ANDN           R2, R1   # 0x041c
        AND              R3, R5, R9, R5   # 0x041e
        OR               R2, R3, R2, R3   # 0x0422
        SHRI             R2, R2, 31   # 0x0426
        ADD              R2, R6, R2, R6   # 0x042a
        ST_GLOBAL_IDX    R2, R7, R14, 0, 4   # 0x042e
        ST_GLOBAL_IDX    R1, R7, R14, 0, 0   # 0x0432
        ADD              R1, R5, R11, R5   # 0x0436
        OR               R2, R5, R11, R5   # 0x043a
        C_ANDN           R2, R1   # 0x043e
        AND              R3, R5, R11, R5   # 0x0440
        OR               R2, R3, R2, R3   # 0x0444
        SHRI             R2, R2, 31   # 0x0448
        ADD              R2, R6, R2, R6   # 0x044c
        ST_GLOBAL_IDX    R2, R7, R9, 0, 12   # 0x0450
        ST_GLOBAL_IDX    R1, R7, R9, 0, 8   # 0x0454
        LD_LOCAL         R3, 48   # 0x0458
        C_CHWIDTH        R3, 1   # 0x045c
        ST_GLOBAL_IDX    R3, R7, R11, 0, 2   # 0x045e
        C_CHWIDTH        R3, 0   # 0x0462
        LD_LOCAL         R3, 52   # 0x0464
        C_CHWIDTH        R3, 1   # 0x0468
        ST_GLOBAL_IDX    R3, R7, R11, 0, 0   # 0x046a
        C_CHWIDTH        R3, 0   # 0x046e
        ST_LOCAL         R7, 12   # 0x0470
        C_MOV            R3, R9   # 0x0474
L0476:  LD_LOCAL         R15, 28   # 0x0476
        BRA              L0196   # 0x047a
L047e:  C_CHWIDTH        R4, 1   # 0x047e
        LD_LOCAL         R1, 12   # 0x0480
        C_MOV            R9, R3   # 0x0484
        LD_LOCAL         R2, 76   # 0x0486
L048a:  SETP_EQ_NPI      P0, R11, R2, 0   # 0x048a
        LD_LOCAL         R11, 32   # 0x048e
        BRA_PRED         0, L05f6   # 0x0492
        LD_LOCAL         R0, 16   # 0x0496
        LD_LOCAL         R1, 20   # 0x049a
        C_ADD            R0, R1   # 0x049e
        ADD              R1, R5, R0, R5   # 0x04a0
        OR               R9, R5, R0, R5   # 0x04a4
        C_ANDN           R9, R1   # 0x04a8
        AND              R0, R5, R0, R5   # 0x04aa
        C_OR             R0, R9   # 0x04ae
        ADDI             R9, R10, 4   # 0x04b0
        ADD              R11, R5, R9, R5   # 0x04b4
        SETP_LT_U_NP     P0, R1, R11, R1   # 0x04b8
        ST_PRED_LOCAL    1, 16   # 0x04bc
        OR               R1, R5, R9, R5   # 0x04c0
        C_ANDN           R1, R11   # 0x04c4
        AND              R9, R5, R9, R5   # 0x04c6
        OR               R1, R9, R1, R9   # 0x04ca
        SHRI             R1, R1, 31   # 0x04ce
        SHRI             R0, R0, 31   # 0x04d2
        SETP_EQ_NP       P0, R9, R1, R0   # 0x04d6
        ST_PRED_LOCAL    1, 20   # 0x04da
        ADD              R1, R6, R1, R6   # 0x04de
        ADD              R0, R6, R0, R6   # 0x04e2
        SETP_LT_U_NP     P2, R0, R1, R0   # 0x04e6
        ADDI             R0, R12, 16   # 0x04ea
        ADD              R1, R5, R0, R5   # 0x04ee
        C_MOV            R2, R15   # 0x04f2
        SETP_LE_U_NP     P0, R15, R13, R1   # 0x04f4
        OR               R15, R5, R0, R5   # 0x04f8
        ANDN             R1, R15, R1, R15   # 0x04fc
        AND              R0, R5, R0, R5   # 0x0500
        C_OR             R0, R1   # 0x0504
        SHRI             R0, R0, 31   # 0x0506
        SETP_NE_NP       P1, R1, R0, R2   # 0x050a
        POR              P0, 1, 0   # 0x050e
        ADD              R0, R6, R0, R6   # 0x0510
        SETP_LE_U_NP     P1, R0, R8, R0   # 0x0514
        PAND             P0, 1, 0   # 0x0518
        BRA_PRED         0, L0942   # 0x051a
        C_CHWIDTH        R4, 1   # 0x051e
        LD_PRED_LOCAL    1, 16   # 0x0520
        LD_PRED_LOCAL    2, 16   # 0x0524
        PAND             P0, 1, 0   # 0x0528
        POR              P0, 2, 0   # 0x052a
        LD_LOCAL         R11, 32   # 0x052c
        BRA_PRED         4, L05f0   # 0x0530
        LD_LOCAL         R15, 12   # 0x0534
        SHLI             R0, R15, 16   # 0x0538
        AND              R1, R0, R3, R0   # 0x053c
        ADD              R2, R0, R3, R0   # 0x0540
        C_OR             R0, R3   # 0x0544
        C_ANDN           R0, R2   # 0x0546
        OR               R0, R1, R0, R1   # 0x0548
        SHRI             R0, R0, 31   # 0x054c
        SHRI             R1, R15, 16   # 0x0550
        ADD              R0, R1, R0, R1   # 0x0554
        ST_GLOBAL_IDX    R2, R7, R12, 0, 0   # 0x0558
        ST_GLOBAL_IDX    R0, R7, R12, 0, 4   # 0x055c
        ADD              R0, R5, R12, R5   # 0x0560
        OR               R1, R5, R12, R5   # 0x0564
        C_ANDN           R1, R0   # 0x0568
        AND              R2, R5, R12, R5   # 0x056a
        OR               R1, R2, R1, R2   # 0x056e
        SHRI             R1, R1, 31   # 0x0572
        ADD              R1, R6, R1, R6   # 0x0576
        ST_GLOBAL_IDX    R1, R7, R14, 0, 4   # 0x057a
        ST_GLOBAL_IDX    R0, R7, R14, 0, 0   # 0x057e
        ADD              R0, R5, R10, R5   # 0x0582
        OR               R1, R5, R10, R5   # 0x0586
        C_ANDN           R1, R0   # 0x058a
        AND              R2, R5, R10, R5   # 0x058c
        C_CHWIDTH        R5, 1   # 0x0590
        OR               R1, R2, R1, R2   # 0x0592
        SHRI             R1, R1, 31   # 0x0596
        ADD              R1, R6, R1, R6   # 0x059a
        C_CHWIDTH        R6, 1   # 0x059e
        ST_GLOBAL_IDX    R1, R7, R12, 0, 12   # 0x05a0
        ST_GLOBAL_IDX    R0, R7, R12, 0, 8   # 0x05a4
        MOVI             R0, 7   # 0x05a8
        AND              R6, R4, R0, R4   # 0x05ac
        C_CHWIDTH        R0, 1   # 0x05b0
        XOR              R0, R4, R11, R4   # 0x05b2
        C_CHWIDTH        R0, 0   # 0x05b6
        MOVI             R1, 32767   # 0x05b8
        C_CHWIDTH        R1, 1   # 0x05bc
        ST_GLOBAL_IDX    R1, R7, R10, 0, 2   # 0x05be
        C_CHWIDTH        R1, 0   # 0x05c2
        SHLI             R0, R0, 3   # 0x05c4
        MOVI             R1, 120   # 0x05c8
        AND              R5, R0, R1, R0   # 0x05cc
        C_CHWIDTH        R0, 1   # 0x05d0
        OR               R0, R5, R6, R5   # 0x05d2
        CHWIDTH_MULTI    33, 0   # 0x05d6
        MULI             R0, R0, 257   # 0x05da
        C_MOV            R1, R0   # 0x05de
        C_CHWIDTH        R0, 0   # 0x05e0
        C_CHWIDTH        R1, 1   # 0x05e2
        ST_GLOBAL_IDX    R1, R7, R10, 0, 0   # 0x05e4
        C_CHWIDTH        R1, 0   # 0x05e8
        C_MOV            R1, R7   # 0x05ea
        C_MOV            R9, R12   # 0x05ec
        C_BRA            L05f6   # 0x05ee
L05f0:  LD_LOCAL         R1, 12   # 0x05f0
        C_MOV            R9, R3   # 0x05f4
L05f6:  CHWIDTH_MULTI    80, 0   # 0x05f6
        LD_GLOBAL_IDX    R2, R1, R9, 0, 4   # 0x05fa
        LD_GLOBAL_IDX    R0, R1, R9, 0, 0   # 0x05fe
        MOVI             R5, 65535   # 0x0602
        AND              R3, R2, R5, R2   # 0x0606
        OR               R3, R0, R3, R0   # 0x060a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x060e
        BRA_PRED         0, L06bc   # 0x0612
        SHRI             R3, R0, 16   # 0x0616
        SHLI             R2, R2, 16   # 0x061a
        OR               R8, R2, R3, R2   # 0x061e
        AND              R10, R0, R5, R0   # 0x0622
        MOVI48           R0, 3435973837   # 0x0626
        LD_LOCAL         R2, 72   # 0x062c
        MUL_HI_U         R0, R2, R0, R2   # 0x0630
        MOVI             R2, 1   # 0x0634
        C_SHRI           R0, 2   # 0x0638
        MOVI             R3, 16383   # 0x063a
        C_MOV            R6, R3   # 0x063e
        MOVI             R3, 1792   # 0x0640
        C_MOV            R4, R3   # 0x0644
        C_BRA            L068a   # 0x0646
L0648:  LD_GLOBAL_IDX    R8, R1, R9, 0, 8   # 0x0648
        LD_GLOBAL_IDX    R1, R1, R9, 0, 12   # 0x064c
        SHLI             R1, R1, 16   # 0x0650
        SHRI             R9, R8, 16   # 0x0654
        C_OR             R1, R9   # 0x0658
        C_AND            R8, R5   # 0x065a
        ST_GLOBAL_IDX    R13, R1, R8, 0, 2   # 0x065c
        LD_GLOBAL_IDX    R1, R15, R3, 0, 4   # 0x0660
        LD_GLOBAL_IDX    R9, R15, R3, 0, 0   # 0x0664
        SHRI             R8, R9, 16   # 0x0668
        SHLI             R10, R1, 16   # 0x066c
        OR               R8, R10, R8, R10   # 0x0670
        C_AND            R1, R5   # 0x0674
        OR               R1, R9, R1, R9   # 0x0676
        AND              R10, R9, R5, R9   # 0x067a
        SETP_NE_NPI      P0, R1, R1, 0   # 0x067e
        C_MOV            R1, R15   # 0x0682
        C_MOV            R9, R3   # 0x0684
        BRA_PRED         4, L06bc   # 0x0686
L068a:  C_CHWIDTH        R12, 1   # 0x068a
        C_CHWIDTH        R13, 0   # 0x068c
        C_MOV            R3, R10   # 0x068e
        C_MOV            R15, R8   # 0x0690
        C_MOV            R13, R2   # 0x0692
        C_CHWIDTH        R13, 1   # 0x0694
        SETP_LT_U_NP     P0, R8, R2, R0   # 0x0696
        C_ADDI           R2, 1   # 0x069a
        BRA_PRED         0, L0648   # 0x069c
        XOR              R13, R13, R11, R13   # 0x06a0
        AND              R13, R13, R6, R13   # 0x06a4
        C_MOV            R8, R2   # 0x06a8
        C_CHWIDTH        R8, 1   # 0x06aa
        C_CHWIDTH        R8, 0   # 0x06ac
        SHLI             R8, R8, 8   # 0x06ae
        AND              R12, R8, R4, R8   # 0x06b2
        OR               R13, R12, R13, R12   # 0x06b6
        C_BRA            L0648   # 0x06ba
L06bc:  MOVI             R10, 1   # 0x06bc
        MOVI             R6, 0   # 0x06c0
        C_BRA            L06e8   # 0x06c4
L06c6:  ST_GLOBAL_IDX    R6, R4, R1, 0, 4   # 0x06c6
        ST_GLOBAL_IDX    R6, R4, R1, 0, 0   # 0x06ca
        C_SHLI           R10, 1   # 0x06ce
        LD_LOCAL         R0, 20   # 0x06d0
        SETP_NE_NPI      P0, R0, R0, 0   # 0x06d4
        LD_LOCAL         R1, 12   # 0x06d8
        C_MOV            R7, R1   # 0x06dc
        LD_LOCAL         R2, 16   # 0x06de
        C_MOV            R14, R2   # 0x06e2
        BRA_PRED         4, L0938   # 0x06e4
L06e8:  MOVI             R2, 0   # 0x06e8
        MOVI             R4, 0   # 0x06ec
        MOVI             R1, 0   # 0x06f0
        MOVI             R0, 0   # 0x06f4
        ST_LOCAL         R0, 12   # 0x06f8
        ST_LOCAL         R0, 16   # 0x06fc
        ST_LOCAL         R10, 28   # 0x0700
        C_BRA            L0716   # 0x0704
L0706:  SETP_EQ_NPI      P0, R0, R3, 0   # 0x0706
        LD_LOCAL         R10, 28   # 0x070a
        LD_LOCAL         R2, 24   # 0x070e
        BRA_PRED         0, L06c6   # 0x0712
L0716:  ST_LOCAL         R2, 20   # 0x0716
        SETP_LT_NPI      P0, R0, R10, 1   # 0x071a
        BRA_PRED         0, L0760   # 0x071e
        MOVI             R0, 0   # 0x0722
        C_MOV            R3, R7   # 0x0726
        C_MOV            R15, R14   # 0x0728
L072a:  LD_GLOBAL_IDX    R8, R3, R15, 0, 4   # 0x072a
        LD_GLOBAL_IDX    R2, R3, R15, 0, 0   # 0x072e
        AND              R3, R8, R5, R8   # 0x0732
        OR               R3, R2, R3, R2   # 0x0736
        SETP_NE_NPI      P0, R3, R3, 0   # 0x073a
        BRA_PRED         4, L076a   # 0x073e
        SHRI             R3, R2, 16   # 0x0742
        SHLI             R15, R8, 16   # 0x0746
        OR               R3, R15, R3, R15   # 0x074a
        AND              R15, R2, R5, R2   # 0x074e
        C_ADDI           R0, 1   # 0x0752
        SETP_EQ_NP       P0, R2, R10, R0   # 0x0754
        BRA_PRED         4, L072a   # 0x0758
        C_MOV            R9, R10   # 0x075c
        C_BRA            L0776   # 0x075e
L0760:  MOVI             R9, 0   # 0x0760
        C_MOV            R3, R7   # 0x0764
        C_MOV            R15, R14   # 0x0766
        C_BRA            L0776   # 0x0768
L076a:  MOVI             R3, 0   # 0x076a
        ADDI             R9, R0, 1   # 0x076e
        MOVI             R15, 0   # 0x0772
L0776:  LD_LOCAL         R0, 20   # 0x0776
        C_ADDI           R0, 1   # 0x077a
        ST_LOCAL         R0, 24   # 0x077c
        C_MOV            R2, R7   # 0x0780
        C_MOV            R0, R14   # 0x0782
        C_MOV            R7, R3   # 0x0784
        C_MOV            R14, R15   # 0x0786
        C_BRA            L079e   # 0x0788
L078a:  ST_LOCAL         R15, 12   # 0x078a
        ST_LOCAL         R8, 16   # 0x078e
L0792:  C_MOV            R2, R12   # 0x0792
        C_MOV            R0, R11   # 0x0794
        C_MOV            R7, R13   # 0x0796
        C_MOV            R14, R3   # 0x0798
        C_MOV            R4, R15   # 0x079a
        C_MOV            R1, R8   # 0x079c
L079e:  SETP_LT_NP       P0, R3, R6, R9   # 0x079e
        BRA_PRED         0, L07da   # 0x07a2
        SHLI             R3, R7, 16   # 0x07a6
        AND              R15, R3, R14, R3   # 0x07aa
        ADD              R8, R3, R14, R3   # 0x07ae
        C_OR             R3, R14   # 0x07b2
        C_ANDN           R3, R8   # 0x07b4
        OR               R3, R15, R3, R15   # 0x07b6
        SHRI             R3, R3, 31   # 0x07ba
        SHRI             R15, R7, 16   # 0x07be
        ADD              R3, R15, R3, R15   # 0x07c2
        OR               R3, R8, R3, R8   # 0x07c6
        SETP_LT_NPI      P0, R15, R10, 1   # 0x07ca
        BRA_PRED         0, L0706   # 0x07ce
        SETP_EQ_NPI      P0, R15, R3, 0   # 0x07d2
        BRA_PRED         0, L0706   # 0x07d6
L07da:  SETP_NE_NPI      P0, R3, R9, 0   # 0x07da
        BRA_PRED         4, L08b6   # 0x07de
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x07e2
        BRA_PRED         0, L088c   # 0x07e6
        C_CHWIDTH        R12, 2   # 0x07ea
        SHLI             R3, R7, 16   # 0x07ec
        AND              R15, R3, R14, R3   # 0x07f0
        ADD              R8, R3, R14, R3   # 0x07f4
        C_OR             R3, R14   # 0x07f8
        C_ANDN           R3, R8   # 0x07fa
        OR               R3, R15, R3, R15   # 0x07fc
        SHRI             R3, R3, 31   # 0x0800
        SHRI             R15, R7, 16   # 0x0804
        ADD              R3, R15, R3, R15   # 0x0808
        OR               R3, R8, R3, R8   # 0x080c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0810
        BRA_PRED         4, L088c   # 0x0814
        C_CHWIDTH        R13, 1   # 0x0818
        LD_GLOBAL_IDX    R3, R2, R0, 0, 8   # 0x081a
        LD_GLOBAL_IDX    R15, R2, R0, 0, 12   # 0x081e
        SHLI             R15, R15, 16   # 0x0822
        SHRI             R8, R3, 16   # 0x0826
        C_OR             R15, R8   # 0x082a
        LD_GLOBAL_IDX    R8, R7, R14, 0, 8   # 0x082c
        LD_GLOBAL_IDX    R11, R7, R14, 0, 12   # 0x0830
        C_AND            R3, R5   # 0x0834
        LD_GLOBAL_IDX    R12, R15, R3, 0, 1   # 0x0836
        ST_GLOBAL_IDX    R12, R15, R3, 0, 0   # 0x083a
        C_CHWIDTH        R12, 0   # 0x083e
        SHLI             R11, R11, 16   # 0x0840
        SHRI             R12, R8, 16   # 0x0844
        C_OR             R11, R12   # 0x0848
        C_CHWIDTH        R12, 2   # 0x084a
        C_AND            R8, R5   # 0x084c
        LD_GLOBAL_IDX    R12, R11, R8, 0, 1   # 0x084e
        ST_GLOBAL_IDX    R12, R11, R8, 0, 0   # 0x0852
        LD_GLOBAL_IDX    R13, R15, R3, 0, 2   # 0x0856
        C_CHWIDTH        R3, 1   # 0x085a
        LD_GLOBAL_IDX    R3, R11, R8, 0, 2   # 0x085c
        CVT_SEXT         R15, R3, R3, R3   # 0x0860
        C_CHWIDTH        R3, 0   # 0x0864
        CVT_SEXT         R3, R13, R13, R13   # 0x0866
        SETP_LT_NP       P0, R3, R15, R3   # 0x086a
        BRA_PRED         4, L088c   # 0x086e
        C_CHWIDTH        R13, 0   # 0x0872
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x0874
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x0878
        SHLI             R15, R15, 16   # 0x087c
        SHRI             R8, R3, 16   # 0x0880
        OR               R13, R15, R8, R15   # 0x0884
        C_AND            R3, R5   # 0x0888
        C_BRA            L08d2   # 0x088a
L088c:  CHWIDTH_MULTI    12288, 0   # 0x088c
        LD_GLOBAL_IDX    R3, R2, R0, 0, 0   # 0x0890
        LD_GLOBAL_IDX    R15, R2, R0, 0, 4   # 0x0894
        SHLI             R15, R15, 16   # 0x0898
        SHRI             R8, R3, 16   # 0x089c
        OR               R12, R15, R8, R15   # 0x08a0
        AND              R11, R3, R5, R3   # 0x08a4
        ADDI             R9, R9, -1   # 0x08a8
        C_MOV            R13, R7   # 0x08ac
        C_MOV            R3, R14   # 0x08ae
        C_MOV            R15, R2   # 0x08b0
        C_MOV            R8, R0   # 0x08b2
        C_BRA            L08e0   # 0x08b4
L08b6:  C_CHWIDTH        R13, 0   # 0x08b6
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x08b8
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x08bc
        SHLI             R15, R15, 16   # 0x08c0
        SHRI             R8, R3, 16   # 0x08c4
        OR               R13, R15, R8, R15   # 0x08c8
        C_AND            R3, R5   # 0x08cc
        MOVI             R9, 0   # 0x08ce
L08d2:  C_CHWIDTH        R12, 0   # 0x08d2
        ADDI             R10, R10, -1   # 0x08d4
        C_MOV            R12, R2   # 0x08d8
        C_MOV            R11, R0   # 0x08da
        C_MOV            R15, R7   # 0x08dc
        C_MOV            R8, R14   # 0x08de
L08e0:  SHLI             R0, R4, 16   # 0x08e0
        AND              R2, R0, R1, R0   # 0x08e4
        ADD              R7, R0, R1, R0   # 0x08e8
        C_OR             R0, R1   # 0x08ec
        C_ANDN           R0, R7   # 0x08ee
        OR               R0, R2, R0, R2   # 0x08f0
        SHRI             R0, R0, 31   # 0x08f4
        SHRI             R2, R4, 16   # 0x08f8
        ADD              R0, R2, R0, R2   # 0x08fc
        OR               R0, R7, R0, R7   # 0x0900
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x0904
        BRA_PRED         0, L078a   # 0x0908
        SHLI             R0, R15, 16   # 0x090c
        ADD              R2, R0, R8, R0   # 0x0910
        ST_GLOBAL_IDX    R2, R4, R1, 0, 0   # 0x0914
        OR               R7, R0, R8, R0   # 0x0918
        ANDN             R2, R7, R2, R7   # 0x091c
        C_AND            R0, R8   # 0x0920
        C_OR             R0, R2   # 0x0922
        SHRI             R0, R0, 31   # 0x0924
        SHRI             R2, R15, 16   # 0x0928
        ADD              R0, R2, R0, R2   # 0x092c
        ST_GLOBAL_IDX    R0, R4, R1, 0, 4   # 0x0930
        BRA              L0792   # 0x0934
L0938:  CHWIDTH_MULTI    12288, 0   # 0x0938
        LD_LOCAL         R14, 68   # 0x093c
        C_RET            224   # 0x0940
L0942:  LD_LOCAL         R1, 12   # 0x0942
        C_MOV            R9, R3   # 0x0946
        LD_LOCAL         R11, 32   # 0x0948
        BRA              L05f6   # 0x094c
        ST_LOCAL         R14, 48   # 0x0950
        ST_LOCAL         R6, 52   # 0x0954
        ST_LOCAL         R5, 56   # 0x0958
        ST_LOCAL         R3, 28   # 0x095c
        C_MOV            R0, R1   # 0x0960
        MOVI             R7, 1   # 0x0962
        SETP_LT_U_NP     P0, R1, R7, R4   # 0x0966
        MOV_P            R7, 0, R4, R4, R4   # 0x096a
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x096e
        BRA_PRED         0, L0996   # 0x0972
        MOVI48           R9, 4294967295   # 0x0976
        MOVI             R3, 8   # 0x097c
L0980:  ADDI             R4, R9, 2   # 0x0980
        MUL_LO           R4, R3, R4, R4   # 0x0984
        SETP_LT_U_NP     P0, R4, R4, R0   # 0x0988
        C_ADDI           R3, 8   # 0x098c
        C_ADDI           R9, 1   # 0x098e
        BRA_PRED         0, L0980   # 0x0990
        C_BRA            L099c   # 0x0994
L0996:  MOVI48           R9, 4294967295   # 0x0996
L099c:  SHLI             R1, R2, 16   # 0x099c
        LD_LOCAL         R0, 28   # 0x09a0
        ADD              R0, R1, R0, R1   # 0x09a4
        ST_LOCAL         R1, 60   # 0x09a8
        SETP_LT_U_NP     P0, R3, R0, R1   # 0x09ac
        SHRI             R3, R2, 16   # 0x09b0
        ST_LOCAL         R3, 64   # 0x09b4
        ADDI_P           R3, 0, R3, 1   # 0x09b8
        C_NEG            R4, R0   # 0x09bc
        ANDI             R1, R4, 3   # 0x09be
        ST_LOCAL         R1, 36   # 0x09c2
        ADD              R4, R0, R1, R0   # 0x09c6
        SETP_LT_U_NP     P0, R0, R4, R0   # 0x09ca
        ADDI_P           R3, 0, R3, 1   # 0x09ce
        MUL_LO           R1, R9, R9, R9   # 0x09d2
        SHRI             R0, R1, 31   # 0x09d6
        ADD              R0, R3, R0, R3   # 0x09da
        C_SHLI           R1, 1   # 0x09de
        ST_LOCAL         R1, 32   # 0x09e0
        ADD              R3, R4, R1, R4   # 0x09e4
        SETP_LT_U_NP     P0, R3, R3, R4   # 0x09e8
        ADDI_P           R0, 0, R0, 1   # 0x09ec
        SETP_EQ_NPI      P0, R0, R9, 0   # 0x09f0
        BRA_PRED         0, L0b9e   # 0x09f4
        C_CHWIDTH        R0, 1   # 0x09f8
        LD_LOCAL         R1, 28   # 0x09fa
        C_MOV            R14, R1   # 0x09fe
        MOVI             R11, 0   # 0x0a00
        C_MOV            R6, R11   # 0x0a04
        SUB              R0, R6, R14, R6   # 0x0a06
        C_CHWIDTH        R0, 0   # 0x0a0a
        C_ANDI           R0, 3   # 0x0a0c
        ADD              R10, R1, R0, R1   # 0x0a0e
        MOVI             R4, 1   # 0x0a12
        C_MOV            R12, R9   # 0x0a16
        C_SHLI           R12, 1   # 0x0a18
        ANDI             R13, R9, -2   # 0x0a1a
        ANDI             R0, R9, 1   # 0x0a1e
        ST_LOCAL         R0, 16   # 0x0a22
        LD_LOCAL         R0, 32   # 0x0a26
        ADD              R5, R10, R0, R10   # 0x0a2a
        MOVI             R3, 255   # 0x0a2e
        C_MOV            R14, R3   # 0x0a32
        MOVI             R6, 0   # 0x0a34
        ST_LOCAL         R9, 40   # 0x0a38
        ST_LOCAL         R12, 44   # 0x0a3c
        C_BRA            L0a52   # 0x0a40
L0a42:  C_ADD            R5, R12   # 0x0a42
        C_ADD            R10, R12   # 0x0a44
        C_ADD            R11, R9   # 0x0a46
        C_ADDI           R6, 1   # 0x0a48
        SETP_NE_NP       P0, R1, R6, R9   # 0x0a4a
        BRA_PRED         4, L0b9e   # 0x0a4e
L0a52:  SETP_EQ_NPI      P0, R3, R9, 1   # 0x0a52
        BRA_PRED         4, L0a60   # 0x0a56
        MOVI             R8, 0   # 0x0a5a
        C_BRA            L0b30   # 0x0a5e
L0a60:  ST_LOCAL         R6, 24   # 0x0a60
        ST_LOCAL         R11, 20   # 0x0a64
        MOVI             R3, 0   # 0x0a68
        C_MOV            R11, R4   # 0x0a6c
        C_SHLI           R11, 1   # 0x0a6e
        MOVI             R8, 0   # 0x0a70
        MOVI48           R15, 4294901760   # 0x0a74
        ST_LOCAL         R10, 12   # 0x0a7a
L0a7e:  C_MOV            R10, R4   # 0x0a7e
        ADD              R4, R10, R8, R10   # 0x0a80
        MUL_LO           R12, R7, R4, R4   # 0x0a84
        SRAI             R9, R12, 31   # 0x0a88
        SHRI             R9, R9, 16   # 0x0a8c
        MADLO            R7, R7, R4, R9   # 0x0a90
        C_AND            R7, R15   # 0x0a94
        SUB              R7, R12, R7, R12   # 0x0a96
        ADD              R9, R5, R3, R5   # 0x0a9a
        ADD              R12, R4, R7, R4   # 0x0a9e
        C_CHWIDTH        R12, 1   # 0x0aa2
        ST_GLOBAL_IDX    R12, R2, R9, 0, 0   # 0x0aa4
        C_CHWIDTH        R12, 0   # 0x0aa8
        ADDI             R12, R4, 1   # 0x0aaa
        C_MOV            R6, R5   # 0x0aae
        MUL_LO           R5, R7, R12, R12   # 0x0ab0
        SRAI             R1, R5, 31   # 0x0ab4
        SHRI             R1, R1, 16   # 0x0ab8
        MAD_ACC          R1, R7, R12   # 0x0abc
        LD_LOCAL         R0, 12   # 0x0abe
        ADD              R12, R0, R3, R0   # 0x0ac2
        C_MOV            R0, R13   # 0x0ac6
        ADD              R13, R11, R3, R11   # 0x0ac8
        ADD              R7, R13, R7, R13   # 0x0acc
        C_CHWIDTH        R7, 1   # 0x0ad0
        AND              R7, R7, R14, R7   # 0x0ad2
        ST_GLOBAL_IDX    R7, R2, R12, 0, 0   # 0x0ad6
        C_CHWIDTH        R7, 0   # 0x0ada
        C_AND            R1, R15   # 0x0adc
        SUB              R7, R5, R1, R5   # 0x0ade
        C_CHWIDTH        R5, 1   # 0x0ae2
        ADDI             R1, R9, 2   # 0x0ae4
        C_ADD            R4, R7   # 0x0ae8
        ADDI             R5, R4, 1   # 0x0aea
        C_MOV            R4, R10   # 0x0aee
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0af0
        ADD              R1, R13, R7, R13   # 0x0af4
        C_MOV            R13, R0   # 0x0af8
        ADDI             R5, R1, 2   # 0x0afa
        AND              R5, R5, R14, R5   # 0x0afe
        ADDI             R1, R12, 2   # 0x0b02
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0b06
        C_CHWIDTH        R5, 0   # 0x0b0a
        C_MOV            R5, R6   # 0x0b0c
        C_ADDI           R3, 4   # 0x0b0e
        C_ADDI           R8, 2   # 0x0b10
        SETP_NE_NP       P0, R1, R13, R8   # 0x0b12
        BRA_PRED         0, L0a7e   # 0x0b16
        C_ADD            R4, R8   # 0x0b1a
        LD_LOCAL         R9, 40   # 0x0b1c
        LD_LOCAL         R11, 20   # 0x0b20
        LD_LOCAL         R12, 44   # 0x0b24
        LD_LOCAL         R10, 12   # 0x0b28
        LD_LOCAL         R6, 24   # 0x0b2c
L0b30:  LD_LOCAL         R0, 16   # 0x0b30
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0b34
        BRA_PRED         0, L0a42   # 0x0b38
        MUL_LO           R1, R6, R9, R9   # 0x0b3c
        MUL_LO           R3, R7, R4, R4   # 0x0b40
        MOVI48           R0, 4294901760   # 0x0b44
        C_MOV            R15, R4   # 0x0b4a
        SRAI             R4, R3, 31   # 0x0b4c
        SHRI             R4, R4, 16   # 0x0b50
        MAD_ACC          R4, R7, R15   # 0x0b54
        C_AND            R4, R0   # 0x0b56
        SUB              R7, R3, R4, R3   # 0x0b58
        LD_LOCAL         R3, 28   # 0x0b5c
        LD_LOCAL         R4, 36   # 0x0b60
        C_ADD            R3, R4   # 0x0b64
        ADD              R1, R8, R1, R8   # 0x0b66
        C_SHLI           R1, 1   # 0x0b6a
        ADD              R1, R3, R1, R3   # 0x0b6c
        LD_LOCAL         R3, 32   # 0x0b70
        ADD              R3, R1, R3, R1   # 0x0b74
        ADD              R4, R7, R15, R7   # 0x0b78
        C_MOV            R0, R5   # 0x0b7c
        C_MOV            R5, R4   # 0x0b7e
        C_CHWIDTH        R5, 1   # 0x0b80
        ST_GLOBAL_IDX    R5, R2, R3, 0, 0   # 0x0b82
        ADD              R3, R4, R15, R4   # 0x0b86
        C_MOV            R4, R15   # 0x0b8a
        AND              R5, R3, R14, R3   # 0x0b8c
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0b90
        C_CHWIDTH        R5, 0   # 0x0b94
        C_MOV            R5, R0   # 0x0b96
        C_ADDI           R4, 1   # 0x0b98
        BRA              L0a42   # 0x0b9a
L0b9e:  LD_LOCAL         R0, 28   # 0x0b9e
        LD_LOCAL         R1, 36   # 0x0ba2
        C_ADD            R0, R1   # 0x0ba6
        LD_LOCAL         R7, 60   # 0x0ba8
        ADD              R1, R7, R0, R7   # 0x0bac
        OR               R2, R7, R0, R7   # 0x0bb0
        C_ANDN           R2, R1   # 0x0bb4
        AND              R3, R7, R0, R7   # 0x0bb6
        OR               R2, R3, R2, R3   # 0x0bba
        LD_LOCAL         R3, 32   # 0x0bbe
        C_ADD            R0, R3   # 0x0bc2
        ADD              R3, R0, R3, R0   # 0x0bc4
        ADD              R4, R7, R3, R7   # 0x0bc8
        C_NEG            R4, R4   # 0x0bcc
        C_ANDI           R4, 3   # 0x0bce
        C_ADD            R3, R4   # 0x0bd0
        ADD              R4, R7, R0, R7   # 0x0bd2
        OR               R5, R7, R0, R7   # 0x0bd6
        C_ANDN           R5, R4   # 0x0bda
        AND              R0, R7, R0, R7   # 0x0bdc
        C_OR             R0, R5   # 0x0be0
        LD_LOCAL         R5, 52   # 0x0be2
        LD_LOCAL         R6, 56   # 0x0be6
        ST_GLOBAL_IDX    R1, R6, R5, 0, 8   # 0x0bea
        ST_GLOBAL_IDX    R4, R6, R5, 0, 16   # 0x0bee
        SHRI             R1, R2, 31   # 0x0bf2
        LD_LOCAL         R2, 64   # 0x0bf6
        ADD              R1, R2, R1, R2   # 0x0bfa
        ST_GLOBAL_IDX    R1, R6, R5, 0, 12   # 0x0bfe
        SHRI             R0, R0, 31   # 0x0c02
        ADD              R0, R2, R0, R2   # 0x0c06
        ST_GLOBAL_IDX    R0, R6, R5, 0, 20   # 0x0c0a
        ADD              R0, R7, R3, R7   # 0x0c0e
        ST_GLOBAL_IDX    R0, R6, R5, 0, 24   # 0x0c12
        OR               R1, R7, R3, R7   # 0x0c16
        ANDN             R0, R1, R0, R1   # 0x0c1a
        AND              R1, R7, R3, R7   # 0x0c1e
        OR               R0, R1, R0, R1   # 0x0c22
        SHRI             R0, R0, 31   # 0x0c26
        ADD              R0, R2, R0, R2   # 0x0c2a
        ST_GLOBAL_IDX    R0, R6, R5, 0, 28   # 0x0c2e
        ST_GLOBAL_IDX    R9, R6, R5, 0, 0   # 0x0c32
        LD_LOCAL         R14, 48   # 0x0c36
        C_MOV            R1, R9   # 0x0c3a
        C_RET            224   # 0x0c3c
        ST_LOCAL         R14, 12   # 0x0c3e
        MOVI             R0, 0   # 0x0c42
        ST_LOCAL         R1, 16   # 0x0c46
        ADDI             R5, R1, -1   # 0x0c4a
        SETP_LT_U_NPI    P0, R6, R5, 2   # 0x0c4e
        BRA_PRED         0, L0d76   # 0x0c52
        C_CHWIDTH        R2, 1   # 0x0c56
        MOVI             R9, 0   # 0x0c58
        MOVI             R6, 2   # 0x0c5c
        MOVI             R7, 65535   # 0x0c60
        MOVI             R10, 0   # 0x0c64
        MOVI             R8, 0   # 0x0c68
        C_BRA            L0caa   # 0x0c6c
L0c6e:  C_CHWIDTH        R14, 0   # 0x0c6e
        MOVI             R8, 8   # 0x0c70
        MOVI             R9, 96   # 0x0c74
L0c78:  ANDI             R1, R2, 24   # 0x0c78
        ADD              R1, R9, R1, R9   # 0x0c7c
        LD_GLOBAL        R14, R6, 28   # 0x0c80
        LD_GLOBAL_IDX    R15, R14, R1, 0, 0   # 0x0c84
        LD_GLOBAL_IDX    R1, R14, R1, 0, 4   # 0x0c88
        SHLI             R1, R1, 16   # 0x0c8c
        SHRI             R14, R15, 16   # 0x0c90
        OR               R9, R1, R14, R1   # 0x0c94
        AND              R10, R15, R7, R15   # 0x0c98
        ADD              R1, R0, R8, R0   # 0x0c9c
        C_ADDI           R1, 1   # 0x0ca0
        SETP_LT_U_NP     P0, R1, R1, R5   # 0x0ca2
        BRA_PRED         4, L0d76   # 0x0ca6
L0caa:  SETP_EQ_NPI      P0, R11, R8, 0   # 0x0caa
        BRA_PRED         0, L0d2c   # 0x0cae
        SETP_LT_U_NPI    P0, R11, R8, 4   # 0x0cb2
        BRA_PRED         0, L0d1a   # 0x0cb6
        C_CHWIDTH        R14, 2   # 0x0cba
        ADD              R11, R4, R0, R4   # 0x0cbc
        MOVI             R12, 0   # 0x0cc0
L0cc4:  CHWIDTH_MULTI    16386, 2   # 0x0cc4
        ADD              R13, R11, R12, R11   # 0x0cc8
        ADD              R15, R12, R10, R12   # 0x0ccc
        LD_GLOBAL_IDX    R14, R9, R15, 0, 0   # 0x0cd0
        ST_GLOBAL_IDX    R14, R3, R13, 0, 0   # 0x0cd4
        C_CHWIDTH        R14, 0   # 0x0cd8
        ADDI             R14, R15, 1   # 0x0cda
        LD_GLOBAL_IDX    R1, R9, R14, 0, 0   # 0x0cde
        ADDI             R14, R13, 1   # 0x0ce2
        ST_GLOBAL_IDX    R1, R3, R14, 0, 0   # 0x0ce6
        C_CHWIDTH        R14, 2   # 0x0cea
        C_CHWIDTH        R1, 0   # 0x0cec
        ADDI             R1, R15, 2   # 0x0cee
        LD_GLOBAL_IDX    R14, R9, R1, 0, 0   # 0x0cf2
        ADDI             R1, R13, 2   # 0x0cf6
        ST_GLOBAL_IDX    R14, R3, R1, 0, 0   # 0x0cfa
        ADDI             R1, R15, 3   # 0x0cfe
        LD_GLOBAL_IDX    R14, R9, R1, 0, 0   # 0x0d02
        ADDI             R1, R13, 3   # 0x0d06
        ST_GLOBAL_IDX    R14, R3, R1, 0, 0   # 0x0d0a
        C_CHWIDTH        R14, 0   # 0x0d0e
        C_ADDI           R12, 4   # 0x0d10
        SETP_NE_NP       P0, R1, R8, R12   # 0x0d12
        BRA_PRED         0, L0cc4   # 0x0d16
L0d1a:  C_ADD            R0, R8   # 0x0d1a
        ADD              R1, R0, R4, R0   # 0x0d1c
        MOVI             R14, 44   # 0x0d20
        C_CHWIDTH        R14, 2   # 0x0d24
        ST_GLOBAL_IDX    R14, R3, R1, 0, 0   # 0x0d26
        C_ADDI           R0, 1   # 0x0d2a
L0d2c:  C_CHWIDTH        R2, 1   # 0x0d2c
        ADDI             R2, R2, 1   # 0x0d2e
        C_CHWIDTH        R2, 0   # 0x0d32
        ANDI             R10, R2, 7   # 0x0d34
        MOVI             R8, 4   # 0x0d38
        SETP_LT_NP       P0, R1, R8, R10   # 0x0d3c
        BRA_PRED         0, L0d5e   # 0x0d40
        C_CHWIDTH        R14, 0   # 0x0d44
        MOVI             R9, 0   # 0x0d46
        SETP_LT_U_NPI    P0, R1, R10, 3   # 0x0d4a
        BRA_PRED         0, L0c78   # 0x0d4e
        C_CHWIDTH        R14, 0   # 0x0d52
        MOVI             R8, 8   # 0x0d54
        MOVI             R9, 32   # 0x0d58
        C_BRA            L0c78   # 0x0d5c
L0d5e:  ADDI             R1, R10, -5   # 0x0d5e
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x0d62
        BRA_PRED         4, L0c6e   # 0x0d66
        C_CHWIDTH        R14, 0   # 0x0d6a
        MOVI             R8, 8   # 0x0d6c
        MOVI             R9, 64   # 0x0d70
        C_BRA            L0c78   # 0x0d74
L0d76:  LD_LOCAL         R1, 16   # 0x0d76
        SETP_LE_U_NP     P0, R2, R1, R0   # 0x0d7a
        BRA_PRED         0, L0e1e   # 0x0d7e
        SUB              R2, R1, R0, R1   # 0x0d82
        ANDI             R5, R2, 7   # 0x0d86
        SETP_EQ_NPI      P0, R2, R5, 0   # 0x0d8a
        C_MOV            R2, R0   # 0x0d8e
        BRA_PRED         0, L0db2   # 0x0d90
        MOVI             R6, 0   # 0x0d94
        C_CHWIDTH        R6, 2   # 0x0d98
        C_MOV            R2, R0   # 0x0d9a
L0d9c:  ADD              R7, R4, R2, R4   # 0x0d9c
        ST_GLOBAL_IDX    R6, R3, R7, 0, 0   # 0x0da0
        C_ADDI           R2, 1   # 0x0da4
        ADDI             R5, R5, -1   # 0x0da6
        SETP_NE_NPI      P0, R7, R5, 0   # 0x0daa
        BRA_PRED         0, L0d9c   # 0x0dae
L0db2:  C_SUB            R0, R1   # 0x0db2
        MOVI48           R5, 4294967288   # 0x0db4
        SETP_LT_U_NP     P0, R0, R5, R0   # 0x0dba
        BRA_PRED         0, L0e1e   # 0x0dbe
        C_CHWIDTH        R6, 0   # 0x0dc2
        ADDI             R0, R2, 7   # 0x0dc4
        C_NEG            R1, R1   # 0x0dc8
        MOVI             R2, 0   # 0x0dca
        C_CHWIDTH        R2, 2   # 0x0dce
L0dd0:  ADD              R5, R4, R0, R4   # 0x0dd0
        ADDI             R6, R5, -7   # 0x0dd4
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0dd8
        ADDI             R6, R5, -6   # 0x0ddc
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0de0
        ADDI             R6, R5, -5   # 0x0de4
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0de8
        ADDI             R6, R5, -4   # 0x0dec
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0df0
        ADDI             R6, R5, -3   # 0x0df4
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0df8
        ADDI             R6, R5, -2   # 0x0dfc
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0e00
        ADDI             R6, R5, -1   # 0x0e04
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0e08
        ST_GLOBAL_IDX    R2, R3, R5, 0, 0   # 0x0e0c
        C_ADDI           R0, 8   # 0x0e10
        ADD              R5, R1, R0, R1   # 0x0e12
        SETP_NE_NPI      P0, R5, R5, 7   # 0x0e16
        BRA_PRED         0, L0dd0   # 0x0e1a
L0e1e:  CHWIDTH_MULTI    68, 0   # 0x0e1e
        LD_LOCAL         R14, 12   # 0x0e22
        C_RET            224   # 0x0e26
        CHWIDTH_MULTI    12, 1   # 0x0e28
        C_MOV            R0, R1   # 0x0e2c
        C_CHWIDTH        R0, 1   # 0x0e2e
        XOR              R3, R0, R2, R0   # 0x0e30
        CHWIDTH_MULTI    13, 0   # 0x0e34
        C_ANDI           R3, 1   # 0x0e38
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e3a
        MOVI             R3, 40961   # 0x0e3e
        C_MOV            R7, R3   # 0x0e42
        C_CHWIDTH        R3, 1   # 0x0e44
        SHRI             R2, R2, 1   # 0x0e46
        XOR              R3, R2, R7, R2   # 0x0e4a
        C_CHWIDTH        R3, 0   # 0x0e4e
        MOV_P            R2, 0, R3, R3, R3   # 0x0e50
        C_CHWIDTH        R2, 1   # 0x0e54
        SHRI             R3, R0, 1   # 0x0e56
        C_CHWIDTH        R3, 1   # 0x0e5a
        XOR              R3, R3, R2, R3   # 0x0e5c
        CHWIDTH_MULTI    12, 0   # 0x0e60
        C_ANDI           R3, 1   # 0x0e64
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e66
        C_CHWIDTH        R3, 1   # 0x0e6a
        SHRI             R2, R2, 1   # 0x0e6c
        XOR              R3, R2, R7, R2   # 0x0e70
        C_CHWIDTH        R3, 0   # 0x0e74
        MOV_P            R2, 0, R3, R3, R3   # 0x0e76
        C_CHWIDTH        R2, 1   # 0x0e7a
        SHRI             R3, R0, 2   # 0x0e7c
        C_CHWIDTH        R3, 1   # 0x0e80
        XOR              R3, R3, R2, R3   # 0x0e82
        CHWIDTH_MULTI    12, 0   # 0x0e86
        C_ANDI           R3, 1   # 0x0e8a
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e8c
        C_CHWIDTH        R3, 1   # 0x0e90
        SHRI             R2, R2, 1   # 0x0e92
        XOR              R3, R2, R7, R2   # 0x0e96
        C_CHWIDTH        R3, 0   # 0x0e9a
        MOV_P            R2, 0, R3, R3, R3   # 0x0e9c
        C_CHWIDTH        R2, 1   # 0x0ea0
        SHRI             R3, R0, 3   # 0x0ea2
        C_CHWIDTH        R3, 1   # 0x0ea6
        XOR              R3, R3, R2, R3   # 0x0ea8
        CHWIDTH_MULTI    12, 0   # 0x0eac
        C_ANDI           R3, 1   # 0x0eb0
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0eb2
        C_CHWIDTH        R3, 1   # 0x0eb6
        SHRI             R2, R2, 1   # 0x0eb8
        XOR              R3, R2, R7, R2   # 0x0ebc
        C_CHWIDTH        R3, 0   # 0x0ec0
        MOV_P            R2, 0, R3, R3, R3   # 0x0ec2
        C_CHWIDTH        R2, 1   # 0x0ec6
        SHRI             R3, R0, 4   # 0x0ec8
        C_CHWIDTH        R3, 1   # 0x0ecc
        XOR              R3, R3, R2, R3   # 0x0ece
        CHWIDTH_MULTI    12, 0   # 0x0ed2
        C_ANDI           R3, 1   # 0x0ed6
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0ed8
        C_CHWIDTH        R3, 1   # 0x0edc
        SHRI             R2, R2, 1   # 0x0ede
        XOR              R3, R2, R7, R2   # 0x0ee2
        C_CHWIDTH        R3, 0   # 0x0ee6
        MOV_P            R2, 0, R3, R3, R3   # 0x0ee8
        C_CHWIDTH        R2, 1   # 0x0eec
        SHRI             R3, R0, 5   # 0x0eee
        C_CHWIDTH        R3, 1   # 0x0ef2
        XOR              R3, R3, R2, R3   # 0x0ef4
        CHWIDTH_MULTI    12, 0   # 0x0ef8
        C_ANDI           R3, 1   # 0x0efc
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0efe
        C_CHWIDTH        R3, 1   # 0x0f02
        SHRI             R2, R2, 1   # 0x0f04
        XOR              R3, R2, R7, R2   # 0x0f08
        C_CHWIDTH        R3, 0   # 0x0f0c
        MOV_P            R2, 0, R3, R3, R3   # 0x0f0e
        C_CHWIDTH        R2, 1   # 0x0f12
        SHRI             R3, R0, 6   # 0x0f14
        C_CHWIDTH        R3, 1   # 0x0f18
        XOR              R3, R3, R2, R3   # 0x0f1a
        CHWIDTH_MULTI    12, 0   # 0x0f1e
        C_ANDI           R3, 1   # 0x0f22
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f24
        C_CHWIDTH        R3, 1   # 0x0f28
        SHRI             R2, R2, 1   # 0x0f2a
        XOR              R3, R2, R7, R2   # 0x0f2e
        C_CHWIDTH        R3, 0   # 0x0f32
        MOV_P            R2, 0, R3, R3, R3   # 0x0f34
        MOVI             R3, 128   # 0x0f38
        C_MOV            R6, R3   # 0x0f3c
        C_CHWIDTH        R3, 1   # 0x0f3e
        AND              R3, R0, R6, R0   # 0x0f40
        C_CHWIDTH        R3, 0   # 0x0f44
        SHRI             R3, R3, 7   # 0x0f46
        ANDI             R4, R2, 1   # 0x0f4a
        C_CHWIDTH        R2, 1   # 0x0f4e
        C_CHWIDTH        R2, 0   # 0x0f50
        SETP_EQ_NP       P0, R3, R3, R4   # 0x0f52
        C_CHWIDTH        R3, 1   # 0x0f56
        SHRI             R2, R2, 1   # 0x0f58
        XOR              R3, R2, R7, R2   # 0x0f5c
        C_CHWIDTH        R3, 0   # 0x0f60
        MOV_P            R3, 0, R2, R2, R2   # 0x0f62
        C_CHWIDTH        R3, 1   # 0x0f66
        SHRI             R2, R0, 8   # 0x0f68
        C_CHWIDTH        R2, 1   # 0x0f6c
        XOR              R2, R3, R2, R3   # 0x0f6e
        CHWIDTH_MULTI    12, 0   # 0x0f72
        C_ANDI           R2, 1   # 0x0f76
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0f78
        SHRI             R2, R3, 1   # 0x0f7c
        C_CHWIDTH        R3, 1   # 0x0f80
        XOR              R3, R2, R7, R2   # 0x0f82
        C_CHWIDTH        R3, 0   # 0x0f86
        MOV_P            R2, 0, R3, R3, R3   # 0x0f88
        C_CHWIDTH        R2, 1   # 0x0f8c
        SHRI             R3, R0, 9   # 0x0f8e
        C_CHWIDTH        R3, 1   # 0x0f92
        XOR              R3, R3, R2, R3   # 0x0f94
        CHWIDTH_MULTI    12, 0   # 0x0f98
        C_ANDI           R3, 1   # 0x0f9c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f9e
        C_CHWIDTH        R3, 1   # 0x0fa2
        SHRI             R2, R2, 1   # 0x0fa4
        XOR              R3, R2, R7, R2   # 0x0fa8
        C_CHWIDTH        R3, 0   # 0x0fac
        MOV_P            R2, 0, R3, R3, R3   # 0x0fae
        C_CHWIDTH        R2, 1   # 0x0fb2
        SHRI             R3, R0, 10   # 0x0fb4
        C_CHWIDTH        R3, 1   # 0x0fb8
        XOR              R3, R3, R2, R3   # 0x0fba
        CHWIDTH_MULTI    12, 0   # 0x0fbe
        C_ANDI           R3, 1   # 0x0fc2
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fc4
        C_CHWIDTH        R3, 1   # 0x0fc8
        SHRI             R2, R2, 1   # 0x0fca
        XOR              R3, R2, R7, R2   # 0x0fce
        C_CHWIDTH        R3, 0   # 0x0fd2
        MOV_P            R2, 0, R3, R3, R3   # 0x0fd4
        C_CHWIDTH        R2, 1   # 0x0fd8
        SHRI             R3, R0, 11   # 0x0fda
        C_CHWIDTH        R3, 1   # 0x0fde
        XOR              R3, R3, R2, R3   # 0x0fe0
        CHWIDTH_MULTI    12, 0   # 0x0fe4
        C_ANDI           R3, 1   # 0x0fe8
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fea
        C_CHWIDTH        R3, 1   # 0x0fee
        SHRI             R2, R2, 1   # 0x0ff0
        XOR              R3, R2, R7, R2   # 0x0ff4
        C_CHWIDTH        R3, 0   # 0x0ff8
        MOV_P            R2, 0, R3, R3, R3   # 0x0ffa
        C_CHWIDTH        R2, 1   # 0x0ffe
        SHRI             R3, R0, 12   # 0x1000
        C_CHWIDTH        R3, 1   # 0x1004
        XOR              R3, R3, R2, R3   # 0x1006
        CHWIDTH_MULTI    12, 0   # 0x100a
        C_ANDI           R3, 1   # 0x100e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1010
        C_CHWIDTH        R3, 1   # 0x1014
        SHRI             R2, R2, 1   # 0x1016
        XOR              R3, R2, R7, R2   # 0x101a
        C_CHWIDTH        R3, 0   # 0x101e
        MOV_P            R2, 0, R3, R3, R3   # 0x1020
        C_CHWIDTH        R2, 1   # 0x1024
        SHRI             R3, R0, 13   # 0x1026
        C_CHWIDTH        R3, 1   # 0x102a
        XOR              R3, R3, R2, R3   # 0x102c
        CHWIDTH_MULTI    12, 0   # 0x1030
        C_ANDI           R3, 1   # 0x1034
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1036
        C_CHWIDTH        R3, 1   # 0x103a
        SHRI             R2, R2, 1   # 0x103c
        XOR              R3, R2, R7, R2   # 0x1040
        C_CHWIDTH        R3, 0   # 0x1044
        MOV_P            R2, 0, R3, R3, R3   # 0x1046
        C_CHWIDTH        R2, 1   # 0x104a
        SHRI             R3, R0, 14   # 0x104c
        C_CHWIDTH        R3, 1   # 0x1050
        XOR              R3, R3, R2, R3   # 0x1052
        CHWIDTH_MULTI    12, 0   # 0x1056
        C_ANDI           R3, 1   # 0x105a
        SETP_NE_NPI      P0, R3, R3, 0   # 0x105c
        C_CHWIDTH        R3, 1   # 0x1060
        SHRI             R2, R2, 1   # 0x1062
        XOR              R3, R2, R7, R2   # 0x1066
        C_CHWIDTH        R3, 0   # 0x106a
        MOV_P            R2, 0, R3, R3, R3   # 0x106c
        SHRI             R0, R0, 15   # 0x1070
        ANDI             R3, R2, 1   # 0x1074
        C_CHWIDTH        R2, 1   # 0x1078
        C_CHWIDTH        R2, 0   # 0x107a
        SETP_EQ_NP       P0, R0, R0, R3   # 0x107c
        SHRI             R0, R2, 1   # 0x1080
        C_CHWIDTH        R2, 1   # 0x1084
        XOR              R2, R0, R7, R0   # 0x1086
        C_CHWIDTH        R2, 0   # 0x108a
        MOV_P            R2, 0, R0, R0, R0   # 0x108c
        C_CHWIDTH        R2, 1   # 0x1090
        SHRI             R0, R1, 16   # 0x1092
        C_MOV            R5, R0   # 0x1096
        C_CHWIDTH        R0, 1   # 0x1098
        XOR              R0, R2, R5, R2   # 0x109a
        CHWIDTH_MULTI    5, 0   # 0x109e
        C_ANDI           R0, 1   # 0x10a2
        SETP_NE_NPI      P0, R0, R0, 0   # 0x10a4
        SHRI             R0, R2, 1   # 0x10a8
        C_CHWIDTH        R2, 1   # 0x10ac
        XOR              R2, R0, R7, R0   # 0x10ae
        C_CHWIDTH        R2, 0   # 0x10b2
        MOV_P            R0, 0, R2, R2, R2   # 0x10b4
        SHRI             R2, R1, 17   # 0x10b8
        C_XOR            R2, R0   # 0x10bc
        C_CHWIDTH        R0, 1   # 0x10be
        C_CHWIDTH        R0, 0   # 0x10c0
        C_ANDI           R2, 1   # 0x10c2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x10c4
        C_CHWIDTH        R2, 1   # 0x10c8
        SHRI             R0, R0, 1   # 0x10ca
        XOR              R2, R0, R7, R0   # 0x10ce
        C_CHWIDTH        R2, 0   # 0x10d2
        MOV_P            R0, 0, R2, R2, R2   # 0x10d4
        SHRI             R2, R1, 18   # 0x10d8
        C_XOR            R2, R0   # 0x10dc
        C_CHWIDTH        R0, 1   # 0x10de
        C_CHWIDTH        R0, 0   # 0x10e0
        C_ANDI           R2, 1   # 0x10e2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x10e4
        C_CHWIDTH        R2, 1   # 0x10e8
        SHRI             R0, R0, 1   # 0x10ea
        XOR              R2, R0, R7, R0   # 0x10ee
        C_CHWIDTH        R2, 0   # 0x10f2
        MOV_P            R0, 0, R2, R2, R2   # 0x10f4
        SHRI             R2, R1, 19   # 0x10f8
        C_XOR            R2, R0   # 0x10fc
        C_CHWIDTH        R0, 1   # 0x10fe
        C_CHWIDTH        R0, 0   # 0x1100
        C_ANDI           R2, 1   # 0x1102
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1104
        C_CHWIDTH        R2, 1   # 0x1108
        SHRI             R0, R0, 1   # 0x110a
        XOR              R2, R0, R7, R0   # 0x110e
        C_CHWIDTH        R2, 0   # 0x1112
        MOV_P            R0, 0, R2, R2, R2   # 0x1114
        SHRI             R2, R1, 20   # 0x1118
        C_XOR            R2, R0   # 0x111c
        C_CHWIDTH        R0, 1   # 0x111e
        C_CHWIDTH        R0, 0   # 0x1120
        C_ANDI           R2, 1   # 0x1122
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1124
        C_CHWIDTH        R2, 1   # 0x1128
        SHRI             R0, R0, 1   # 0x112a
        XOR              R2, R0, R7, R0   # 0x112e
        C_CHWIDTH        R2, 0   # 0x1132
        MOV_P            R0, 0, R2, R2, R2   # 0x1134
        SHRI             R2, R1, 21   # 0x1138
        C_XOR            R2, R0   # 0x113c
        C_CHWIDTH        R0, 1   # 0x113e
        C_CHWIDTH        R0, 0   # 0x1140
        C_ANDI           R2, 1   # 0x1142
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1144
        C_CHWIDTH        R2, 1   # 0x1148
        SHRI             R0, R0, 1   # 0x114a
        XOR              R2, R0, R7, R0   # 0x114e
        C_CHWIDTH        R2, 0   # 0x1152
        MOV_P            R0, 0, R2, R2, R2   # 0x1154
        SHRI             R2, R1, 22   # 0x1158
        C_XOR            R2, R0   # 0x115c
        C_CHWIDTH        R0, 1   # 0x115e
        C_CHWIDTH        R0, 0   # 0x1160
        C_ANDI           R2, 1   # 0x1162
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1164
        C_CHWIDTH        R2, 1   # 0x1168
        SHRI             R0, R0, 1   # 0x116a
        XOR              R2, R0, R7, R0   # 0x116e
        C_CHWIDTH        R2, 0   # 0x1172
        MOV_P            R0, 0, R2, R2, R2   # 0x1174
        C_CHWIDTH        R2, 1   # 0x1178
        AND              R2, R5, R6, R5   # 0x117a
        C_CHWIDTH        R2, 0   # 0x117e
        SHRI             R2, R2, 7   # 0x1180
        ANDI             R3, R0, 1   # 0x1184
        C_CHWIDTH        R0, 1   # 0x1188
        C_CHWIDTH        R0, 0   # 0x118a
        SETP_EQ_NP       P0, R2, R2, R3   # 0x118c
        C_CHWIDTH        R2, 1   # 0x1190
        SHRI             R0, R0, 1   # 0x1192
        XOR              R2, R0, R7, R0   # 0x1196
        C_CHWIDTH        R2, 0   # 0x119a
        MOV_P            R2, 0, R0, R0, R0   # 0x119c
        SHRI             R0, R1, 24   # 0x11a0
        XOR              R0, R2, R0, R2   # 0x11a4
        C_CHWIDTH        R2, 1   # 0x11a8
        C_CHWIDTH        R2, 0   # 0x11aa
        C_ANDI           R0, 1   # 0x11ac
        SETP_NE_NPI      P0, R0, R0, 0   # 0x11ae
        SHRI             R0, R2, 1   # 0x11b2
        C_CHWIDTH        R2, 1   # 0x11b6
        XOR              R2, R0, R7, R0   # 0x11b8
        C_CHWIDTH        R2, 0   # 0x11bc
        MOV_P            R0, 0, R2, R2, R2   # 0x11be
        SHRI             R2, R1, 25   # 0x11c2
        C_XOR            R2, R0   # 0x11c6
        C_CHWIDTH        R0, 1   # 0x11c8
        C_CHWIDTH        R0, 0   # 0x11ca
        C_ANDI           R2, 1   # 0x11cc
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11ce
        C_CHWIDTH        R2, 1   # 0x11d2
        SHRI             R0, R0, 1   # 0x11d4
        XOR              R2, R0, R7, R0   # 0x11d8
        C_CHWIDTH        R2, 0   # 0x11dc
        MOV_P            R0, 0, R2, R2, R2   # 0x11de
        SHRI             R2, R1, 26   # 0x11e2
        C_XOR            R2, R0   # 0x11e6
        C_CHWIDTH        R0, 1   # 0x11e8
        C_CHWIDTH        R0, 0   # 0x11ea
        C_ANDI           R2, 1   # 0x11ec
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11ee
        C_CHWIDTH        R2, 1   # 0x11f2
        SHRI             R0, R0, 1   # 0x11f4
        XOR              R2, R0, R7, R0   # 0x11f8
        C_CHWIDTH        R2, 0   # 0x11fc
        MOV_P            R0, 0, R2, R2, R2   # 0x11fe
        SHRI             R2, R1, 27   # 0x1202
        C_XOR            R2, R0   # 0x1206
        C_CHWIDTH        R0, 1   # 0x1208
        C_CHWIDTH        R0, 0   # 0x120a
        C_ANDI           R2, 1   # 0x120c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x120e
        C_CHWIDTH        R2, 1   # 0x1212
        SHRI             R0, R0, 1   # 0x1214
        XOR              R2, R0, R7, R0   # 0x1218
        C_CHWIDTH        R2, 0   # 0x121c
        MOV_P            R0, 0, R2, R2, R2   # 0x121e
        SHRI             R2, R1, 28   # 0x1222
        C_XOR            R2, R0   # 0x1226
        C_CHWIDTH        R0, 1   # 0x1228
        C_CHWIDTH        R0, 0   # 0x122a
        C_ANDI           R2, 1   # 0x122c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x122e
        C_CHWIDTH        R2, 1   # 0x1232
        SHRI             R0, R0, 1   # 0x1234
        XOR              R2, R0, R7, R0   # 0x1238
        C_CHWIDTH        R2, 0   # 0x123c
        MOV_P            R0, 0, R2, R2, R2   # 0x123e
        SHRI             R2, R1, 29   # 0x1242
        C_XOR            R2, R0   # 0x1246
        C_CHWIDTH        R0, 1   # 0x1248
        C_CHWIDTH        R0, 0   # 0x124a
        C_ANDI           R2, 1   # 0x124c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x124e
        C_CHWIDTH        R2, 1   # 0x1252
        SHRI             R0, R0, 1   # 0x1254
        XOR              R2, R0, R7, R0   # 0x1258
        C_CHWIDTH        R2, 0   # 0x125c
        MOV_P            R0, 0, R2, R2, R2   # 0x125e
        SHRI             R2, R1, 30   # 0x1262
        C_XOR            R2, R0   # 0x1266
        C_CHWIDTH        R0, 1   # 0x1268
        C_CHWIDTH        R0, 0   # 0x126a
        C_ANDI           R2, 1   # 0x126c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x126e
        C_CHWIDTH        R2, 1   # 0x1272
        SHRI             R0, R0, 1   # 0x1274
        XOR              R2, R0, R7, R0   # 0x1278
        C_CHWIDTH        R2, 0   # 0x127c
        MOV_P            R0, 0, R2, R2, R2   # 0x127e
        SHRI             R1, R1, 31   # 0x1282
        ANDI             R2, R0, 1   # 0x1286
        C_CHWIDTH        R0, 1   # 0x128a
        C_CHWIDTH        R0, 0   # 0x128c
        SETP_EQ_NP       P0, R1, R1, R2   # 0x128e
        C_CHWIDTH        R1, 1   # 0x1292
        SHRI             R0, R0, 1   # 0x1294
        XOR              R1, R0, R7, R0   # 0x1298
        C_CHWIDTH        R1, 0   # 0x129c
        MOV_P            R1, 0, R0, R0, R0   # 0x129e
        MOVI             R0, 65535   # 0x12a2
        C_AND            R1, R0   # 0x12a6
        C_RET            224   # 0x12a8
        MOVI             R15, 2   # 0x12aa
        LD_GLOBAL        R15, R15, 24   # 0x12ae
        SRD              R0, 2   # 0x12b2
        C_ADD            R15, R0   # 0x12b4
        C_CHWIDTH        R0, 2   # 0x12b6
        ST_LOCAL         R8, 60   # 0x12b8
        ST_LOCAL         R9, 64   # 0x12bc
        ST_LOCAL         R10, 68   # 0x12c0
        ST_LOCAL         R11, 72   # 0x12c4
        ST_LOCAL         R12, 76   # 0x12c8
        ST_LOCAL         R13, 80   # 0x12cc
        ST_LOCAL         R14, 44   # 0x12d0
        ST_LOCAL         R5, 52   # 0x12d4
        C_MOV            R13, R3   # 0x12d8
        ST_LOCAL         R1, 36   # 0x12da
        C_CHWIDTH        R1, 1   # 0x12de
        MOVI             R9, 0   # 0x12e0
        ST_GLOBAL        R9, R15, -8   # 0x12e4
        ST_GLOBAL        R9, R15, -12   # 0x12e8
        ST_GLOBAL        R9, R15, -16   # 0x12ec
        ST_GLOBAL        R9, R15, -20   # 0x12f0
        ST_GLOBAL        R9, R15, -24   # 0x12f4
        ST_GLOBAL        R9, R15, -28   # 0x12f8
        ST_GLOBAL        R9, R15, -32   # 0x12fc
        ST_GLOBAL        R9, R15, -36   # 0x1300
        LD_GLOBAL_IDX    R0, R2, R13, 0, 0   # 0x1304
        C_CHWIDTH        R0, 0   # 0x1308
        LD_GLOBAL        R1, R15, -4   # 0x130a
        C_CHWIDTH        R1, 0   # 0x130e
        ST_LOCAL         R1, 48   # 0x1310
        C_MOV            R5, R6   # 0x1314
        C_MOV            R6, R0   # 0x1316
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x1318
        MOVI             R12, 0   # 0x131c
        MOVI             R0, 0   # 0x1320
        ST_LOCAL         R0, 20   # 0x1324
        ST_LOCAL         R0, 16   # 0x1328
        ST_LOCAL         R0, 12   # 0x132c
        ST_LOCAL         R0, 28   # 0x1330
        ST_LOCAL         R0, 24   # 0x1334
        BRA_PRED         0, L15b8   # 0x1338
        ST_LOCAL         R5, 56   # 0x133c
        ST_LOCAL         R4, 40   # 0x1340
        MOVI             R0, 255   # 0x1344
        C_MOV            R14, R0   # 0x1348
        MOVI             R0, 3   # 0x134a
        MOVI             R10, 5   # 0x134e
        MOVI             R1, 223   # 0x1352
        C_MOV            R7, R1   # 0x1356
        ST_LOCAL         R7, 32   # 0x1358
        MOVI             R7, 0   # 0x135c
        MOVI             R1, 0   # 0x1360
        ST_LOCAL         R1, 20   # 0x1364
        ST_LOCAL         R1, 16   # 0x1368
        ST_LOCAL         R1, 12   # 0x136c
        ST_LOCAL         R1, 28   # 0x1370
        ST_LOCAL         R1, 24   # 0x1374
        MOVI             R4, 0   # 0x1378
        C_MOV            R3, R6   # 0x137c
        MOVI             R11, 0   # 0x137e
        C_MOV            R12, R13   # 0x1382
        C_BRA            L1388   # 0x1384
L1386:  C_MOV            R12, R1   # 0x1386
L1388:  C_CHWIDTH        R5, 1   # 0x1388
        AND              R5, R3, R14, R3   # 0x138a
        C_CHWIDTH        R5, 0   # 0x138e
        SETP_NE_NPI      P0, R1, R5, 44   # 0x1390
        ADDI             R1, R12, 1   # 0x1394
        BRA_PRED         0, L13bc   # 0x1398
L139c:  LD_GLOBAL_IDX    R3, R15, R11, 1, -36   # 0x139c
        C_ADDI           R3, 1   # 0x13a0
        ST_GLOBAL_IDX    R3, R15, R11, 1, -36   # 0x13a2
        C_CHWIDTH        R3, 2   # 0x13a6
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x13a8
        C_CHWIDTH        R3, 0   # 0x13ac
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x13ae
        BRA_PRED         0, L15ae   # 0x13b2
        MOVI             R11, 0   # 0x13b6
        C_BRA            L1386   # 0x13ba
L13bc:  SETP_LT_NP       P0, R8, R0, R11   # 0x13bc
        BRA_PRED         4, L13fa   # 0x13c0
        SETP_LT_NP       P0, R8, R10, R11   # 0x13c4
        BRA_PRED         0, L142a   # 0x13c8
        SETP_EQ_NPI      P0, R8, R11, 4   # 0x13cc
        BRA_PRED         0, L14aa   # 0x13d0
        SETP_EQ_NPI      P0, R5, R11, 5   # 0x13d4
        BRA_PRED         4, L1592   # 0x13d8
        LD_LOCAL         R5, 32   # 0x13dc
        C_CHWIDTH        R5, 1   # 0x13e0
        AND              R5, R3, R5, R3   # 0x13e2
        C_CHWIDTH        R5, 0   # 0x13e6
        SETP_NE_NPI      P0, R5, R5, 69   # 0x13e8
        BRA_PRED         0, L1536   # 0x13ec
        MOVI             R11, 3   # 0x13f0
        C_ADDI           R7, 1   # 0x13f4
        BRA              L1592   # 0x13f6
L13fa:  SETP_EQ_NPI      P0, R8, R11, 0   # 0x13fa
        BRA_PRED         0, L146c   # 0x13fe
        SETP_EQ_NPI      P0, R8, R11, 2   # 0x1402
        BRA_PRED         0, L14e0   # 0x1406
        SETP_EQ_NPI      P0, R3, R11, 3   # 0x140a
        BRA_PRED         4, L1592   # 0x140e
        SETP_EQ_NPI      P0, R3, R5, 45   # 0x1412
        BRA_PRED         0, L1422   # 0x1416
        SETP_NE_NPI      P0, R3, R5, 43   # 0x141a
        BRA_PRED         0, L156e   # 0x141e
L1422:  MOVI             R11, 6   # 0x1422
        BRA              L1572   # 0x1426
L142a:  SETP_EQ_NPI      P0, R5, R11, 6   # 0x142a
        BRA_PRED         0, L14b8   # 0x142e
        SETP_EQ_NPI      P0, R5, R11, 7   # 0x1432
        BRA_PRED         4, L1592   # 0x1436
        C_CHWIDTH        R5, 1   # 0x143a
        ADDI             R5, R3, -58   # 0x143c
        C_CHWIDTH        R3, 1   # 0x1440
        AND              R3, R5, R14, R5   # 0x1442
        CHWIDTH_MULTI    40, 0   # 0x1446
        MOVI             R5, 245   # 0x144a
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x144e
        MOVI             R11, 7   # 0x1452
        BRA_PRED         0, L1592   # 0x1456
        MOVI             R11, 1   # 0x145a
        LD_LOCAL         R3, 28   # 0x145e
        C_ADDI           R3, 1   # 0x1462
        ST_LOCAL         R3, 28   # 0x1464
        BRA              L1592   # 0x1468
L146c:  C_CHWIDTH        R3, 1   # 0x146c
        ADDI             R3, R3, -58   # 0x146e
        AND              R3, R3, R14, R3   # 0x1472
        C_CHWIDTH        R3, 0   # 0x1476
        MOVI             R8, 245   # 0x1478
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x147c
        MOVI             R11, 4   # 0x1480
        BRA_PRED         0, L158c   # 0x1484
        MOVI             R11, 2   # 0x1488
        SETP_EQ_NPI      P0, R3, R5, 43   # 0x148c
        BRA_PRED         0, L158c   # 0x1490
        SETP_EQ_NPI      P0, R3, R5, 45   # 0x1494
        BRA_PRED         0, L158c   # 0x1498
        SETP_NE_NPI      P0, R3, R5, 46   # 0x149c
        BRA_PRED         0, L157e   # 0x14a0
        MOVI             R11, 5   # 0x14a4
        C_BRA            L158c   # 0x14a8
L14aa:  SETP_NE_NPI      P0, R5, R5, 46   # 0x14aa
        BRA_PRED         0, L1506   # 0x14ae
        MOVI             R11, 5   # 0x14b2
        C_BRA            L152a   # 0x14b6
L14b8:  C_CHWIDTH        R5, 1   # 0x14b8
        ADDI             R5, R3, -58   # 0x14ba
        C_CHWIDTH        R3, 1   # 0x14be
        AND              R3, R5, R14, R5   # 0x14c0
        CHWIDTH_MULTI    40, 0   # 0x14c4
        MOVI             R5, 246   # 0x14c8
        SETP_LT_U_NP     P0, R3, R3, R5   # 0x14cc
        MOVI             R11, 7   # 0x14d0
        MOVI             R3, 1   # 0x14d4
        MOV_P            R11, 0, R3, R3, R3   # 0x14d8
        C_ADDI           R9, 1   # 0x14dc
        C_BRA            L1592   # 0x14de
L14e0:  C_CHWIDTH        R3, 1   # 0x14e0
        ADDI             R3, R3, -58   # 0x14e2
        AND              R3, R3, R14, R3   # 0x14e6
        C_CHWIDTH        R3, 0   # 0x14ea
        MOVI             R8, 246   # 0x14ec
        SETP_LT_U_NP     P0, R3, R3, R8   # 0x14f0
        BRA_PRED         4, L155e   # 0x14f4
        SETP_EQ_NPI      P0, R3, R5, 46   # 0x14f8
        MOVI             R11, 1   # 0x14fc
        MOV_P            R11, 0, R10, R10, R10   # 0x1500
        C_BRA            L1562   # 0x1504
L1506:  C_CHWIDTH        R5, 1   # 0x1506
        ADDI             R5, R3, -58   # 0x1508
        C_CHWIDTH        R3, 1   # 0x150c
        AND              R3, R5, R14, R5   # 0x150e
        CHWIDTH_MULTI    40, 0   # 0x1512
        MOVI             R5, 245   # 0x1516
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x151a
        MOVI             R11, 4   # 0x151e
        BRA_PRED         0, L1592   # 0x1522
        MOVI             R11, 1   # 0x1526
L152a:  LD_LOCAL         R3, 20   # 0x152a
        C_ADDI           R3, 1   # 0x152e
        ST_LOCAL         R3, 20   # 0x1530
        C_BRA            L1592   # 0x1534
L1536:  C_CHWIDTH        R5, 1   # 0x1536
        ADDI             R5, R3, -58   # 0x1538
        C_CHWIDTH        R3, 1   # 0x153c
        AND              R3, R5, R14, R5   # 0x153e
        CHWIDTH_MULTI    40, 0   # 0x1542
        MOVI             R5, 245   # 0x1546
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x154a
        MOVI             R11, 5   # 0x154e
        BRA_PRED         0, L1592   # 0x1552
        MOVI             R11, 1   # 0x1556
        C_ADDI           R7, 1   # 0x155a
        C_BRA            L1592   # 0x155c
L155e:  MOVI             R11, 4   # 0x155e
L1562:  LD_LOCAL         R3, 12   # 0x1562
        C_ADDI           R3, 1   # 0x1566
        ST_LOCAL         R3, 12   # 0x1568
        C_BRA            L1592   # 0x156c
L156e:  MOVI             R11, 1   # 0x156e
L1572:  LD_LOCAL         R3, 16   # 0x1572
        C_ADDI           R3, 1   # 0x1576
        ST_LOCAL         R3, 16   # 0x1578
        C_BRA            L1592   # 0x157c
L157e:  MOVI             R11, 1   # 0x157e
        LD_LOCAL         R3, 28   # 0x1582
        C_ADDI           R3, 1   # 0x1586
        ST_LOCAL         R3, 28   # 0x1588
L158c:  C_ADDI           R4, 1   # 0x158c
        ST_LOCAL         R4, 24   # 0x158e
L1592:  C_CHWIDTH        R3, 2   # 0x1592
        LD_GLOBAL_IDX    R3, R2, R12, 0, 1   # 0x1594
        C_CHWIDTH        R3, 0   # 0x1598
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x159a
        BRA_PRED         0, L139c   # 0x159e
        SETP_EQ_NPI      P0, R5, R11, 1   # 0x15a2
        BRA_PRED         4, L1386   # 0x15a6
        BRA              L139c   # 0x15aa
L15ae:  C_MOV            R12, R7   # 0x15ae
        LD_LOCAL         R4, 40   # 0x15b0
        LD_LOCAL         R5, 56   # 0x15b4
L15b8:  C_CHWIDTH        R5, 1   # 0x15b8
        LD_LOCAL         R1, 36   # 0x15ba
        SETP_EQ_NPI      P0, R0, R1, 0   # 0x15be
        SHLI             R7, R2, 16   # 0x15c2
        CVT_SEXT         R14, R5, R5, R5   # 0x15c6
        C_CHWIDTH        R5, 0   # 0x15ca
        ADD              R0, R13, R1, R13   # 0x15cc
        SHRI             R5, R2, 16   # 0x15d0
        BRA_PRED         0, L1668   # 0x15d4
        C_MOV            R6, R4   # 0x15d8
        ADD              R3, R13, R7, R13   # 0x15da
        ADD              R1, R14, R7, R14   # 0x15de
        C_ADD            R3, R14   # 0x15e2
        C_NOT            R3, R3   # 0x15e4
        C_MOV            R8, R13   # 0x15e6
L15e8:  C_CHWIDTH        R4, 2   # 0x15e8
        LD_GLOBAL_IDX    R4, R2, R8, 0, 0   # 0x15ea
        C_CHWIDTH        R4, 0   # 0x15ee
        SETP_EQ_NPI      P0, R10, R4, 44   # 0x15f0
        BRA_PRED         0, L160a   # 0x15f4
        C_CHWIDTH        R4, 1   # 0x15f8
        XOR              R4, R4, R6, R4   # 0x15fa
        C_MOV            R10, R4   # 0x15fe
        C_CHWIDTH        R4, 0   # 0x1600
        C_CHWIDTH        R10, 2   # 0x1602
        ST_GLOBAL_IDX    R10, R2, R8, 0, 0   # 0x1604
        C_CHWIDTH        R10, 0   # 0x1608
L160a:  ADD              R4, R14, R8, R14   # 0x160a
        OR               R10, R7, R4, R7   # 0x160e
        C_AND            R10, R3   # 0x1612
        AND              R11, R7, R4, R7   # 0x1614
        OR               R10, R11, R10, R11   # 0x1618
        ADD              R8, R1, R8, R1   # 0x161c
        ADD              R11, R7, R0, R7   # 0x1620
        SETP_LT_U_NP     P0, R8, R8, R11   # 0x1624
        OR               R8, R7, R0, R7   # 0x1628
        C_ANDN           R8, R11   # 0x162c
        AND              R11, R7, R0, R7   # 0x162e
        OR               R8, R11, R8, R11   # 0x1632
        SHRI             R8, R8, 31   # 0x1636
        SHRI             R10, R10, 31   # 0x163a
        SETP_EQ_NP       P1, R11, R10, R8   # 0x163e
        ADD              R8, R5, R8, R5   # 0x1642
        ADD              R10, R5, R10, R5   # 0x1646
        SETP_LT_U_NP     P2, R8, R10, R8   # 0x164a
        C_SUB            R3, R14   # 0x164e
        C_MOV            R8, R4   # 0x1650
        BRA_PRED         2, L15e8   # 0x1652
        PAND             P0, 1, 0   # 0x1656
        C_MOV            R8, R4   # 0x1658
        BRA_PRED         0, L15e8   # 0x165a
        C_CHWIDTH        R1, 2   # 0x165e
        LD_GLOBAL_IDX    R1, R2, R13, 0, 0   # 0x1660
        C_CHWIDTH        R1, 0   # 0x1664
        C_MOV            R6, R1   # 0x1666
L1668:  SETP_EQ_NPI      P0, R1, R6, 0   # 0x1668
        BRA_PRED         0, L18d8   # 0x166c
        ST_LOCAL         R12, 32   # 0x1670
        MOVI             R11, 0   # 0x1674
        MOVI             R1, 255   # 0x1678
        C_MOV            R4, R1   # 0x167c
        MOVI             R10, 3   # 0x167e
        MOVI             R3, 223   # 0x1682
        ST_LOCAL         R3, 40   # 0x1686
        C_MOV            R3, R13   # 0x168a
        C_BRA            L1690   # 0x168c
L168e:  C_MOV            R3, R12   # 0x168e
L1690:  C_CHWIDTH        R8, 1   # 0x1690
        AND              R8, R6, R4, R6   # 0x1692
        C_CHWIDTH        R8, 0   # 0x1696
        SETP_NE_NPI      P0, R12, R8, 44   # 0x1698
        ADDI             R12, R3, 1   # 0x169c
        BRA_PRED         0, L16c8   # 0x16a0
L16a4:  C_CHWIDTH        R3, 2   # 0x16a4
        LD_GLOBAL_IDX    R1, R15, R11, 1, -36   # 0x16a6
        C_ADDI           R1, 1   # 0x16aa
        ST_GLOBAL_IDX    R1, R15, R11, 1, -36   # 0x16ac
        LD_GLOBAL_IDX    R3, R2, R12, 0, 0   # 0x16b0
        C_CHWIDTH        R3, 0   # 0x16b4
        SETP_EQ_NPI      P0, R1, R3, 0   # 0x16b6
        BRA_PRED         0, L18d4   # 0x16ba
        MOVI             R11, 0   # 0x16be
        C_MOV            R6, R3   # 0x16c2
        C_MOV            R3, R12   # 0x16c4
        C_BRA            L1690   # 0x16c6
L16c8:  SETP_LT_NP       P0, R1, R10, R11   # 0x16c8
        BRA_PRED         4, L1708   # 0x16cc
        MOVI             R1, 5   # 0x16d0
        SETP_LT_NP       P0, R1, R1, R11   # 0x16d4
        BRA_PRED         0, L1738   # 0x16d8
        SETP_EQ_NPI      P0, R1, R11, 4   # 0x16dc
        BRA_PRED         0, L17bc   # 0x16e0
        SETP_EQ_NPI      P0, R1, R11, 5   # 0x16e4
        BRA_PRED         4, L18b8   # 0x16e8
        LD_LOCAL         R1, 40   # 0x16ec
        C_CHWIDTH        R1, 1   # 0x16f0
        AND              R1, R6, R1, R6   # 0x16f2
        C_CHWIDTH        R1, 0   # 0x16f6
        SETP_NE_NPI      P0, R1, R1, 69   # 0x16f8
        BRA_PRED         0, L1850   # 0x16fc
        MOVI             R11, 3   # 0x1700
        BRA              L1874   # 0x1704
L1708:  SETP_EQ_NPI      P0, R1, R11, 0   # 0x1708
        BRA_PRED         0, L177a   # 0x170c
        SETP_EQ_NPI      P0, R1, R11, 2   # 0x1710
        BRA_PRED         0, L17f2   # 0x1714
        SETP_EQ_NPI      P0, R1, R11, 3   # 0x1718
        BRA_PRED         4, L18b8   # 0x171c
        SETP_EQ_NPI      P0, R1, R8, 45   # 0x1720
        BRA_PRED         0, L1730   # 0x1724
        SETP_NE_NPI      P0, R1, R8, 43   # 0x1728
        BRA_PRED         0, L1890   # 0x172c
L1730:  MOVI             R11, 6   # 0x1730
        BRA              L1894   # 0x1734
L1738:  SETP_EQ_NPI      P0, R1, R11, 6   # 0x1738
        BRA_PRED         0, L17ca   # 0x173c
        SETP_EQ_NPI      P0, R1, R11, 7   # 0x1740
        BRA_PRED         4, L18b8   # 0x1744
        CHWIDTH_MULTI    66, 1   # 0x1748
        ADDI             R6, R6, -58   # 0x174c
        AND              R1, R6, R4, R6   # 0x1750
        CHWIDTH_MULTI    66, 0   # 0x1754
        MOVI             R6, 245   # 0x1758
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x175c
        MOVI             R11, 7   # 0x1760
        BRA_PRED         0, L18b8   # 0x1764
        MOVI             R11, 1   # 0x1768
        LD_LOCAL         R1, 28   # 0x176c
        C_ADDI           R1, 1   # 0x1770
        ST_LOCAL         R1, 28   # 0x1772
        BRA              L18b8   # 0x1776
L177a:  CHWIDTH_MULTI    66, 1   # 0x177a
        ADDI             R6, R6, -58   # 0x177e
        AND              R1, R6, R4, R6   # 0x1782
        CHWIDTH_MULTI    66, 0   # 0x1786
        MOVI             R6, 245   # 0x178a
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x178e
        MOVI             R11, 4   # 0x1792
        BRA_PRED         0, L18ae   # 0x1796
        MOVI             R11, 2   # 0x179a
        SETP_EQ_NPI      P0, R1, R8, 43   # 0x179e
        BRA_PRED         0, L18ae   # 0x17a2
        SETP_EQ_NPI      P0, R1, R8, 45   # 0x17a6
        BRA_PRED         0, L18ae   # 0x17aa
        SETP_NE_NPI      P0, R1, R8, 46   # 0x17ae
        BRA_PRED         0, L18a0   # 0x17b2
        MOVI             R11, 5   # 0x17b6
        C_BRA            L18ae   # 0x17ba
L17bc:  SETP_NE_NPI      P0, R1, R8, 46   # 0x17bc
        BRA_PRED         0, L1820   # 0x17c0
        MOVI             R11, 5   # 0x17c4
        C_BRA            L1844   # 0x17c8
L17ca:  CHWIDTH_MULTI    66, 1   # 0x17ca
        ADDI             R6, R6, -58   # 0x17ce
        AND              R1, R6, R4, R6   # 0x17d2
        CHWIDTH_MULTI    66, 0   # 0x17d6
        MOVI             R6, 246   # 0x17da
        SETP_LT_U_NP     P0, R1, R1, R6   # 0x17de
        MOVI             R11, 7   # 0x17e2
        MOVI             R1, 1   # 0x17e6
        MOV_P            R11, 0, R1, R1, R1   # 0x17ea
        C_ADDI           R9, 1   # 0x17ee
        C_BRA            L18b8   # 0x17f0
L17f2:  CHWIDTH_MULTI    66, 1   # 0x17f2
        ADDI             R6, R6, -58   # 0x17f6
        AND              R1, R6, R4, R6   # 0x17fa
        CHWIDTH_MULTI    66, 0   # 0x17fe
        MOVI             R6, 246   # 0x1802
        SETP_LT_U_NP     P0, R1, R1, R6   # 0x1806
        BRA_PRED         4, L1880   # 0x180a
        SETP_EQ_NPI      P0, R1, R8, 46   # 0x180e
        MOVI             R11, 1   # 0x1812
        MOVI             R1, 5   # 0x1816
        MOV_P            R11, 0, R1, R1, R1   # 0x181a
        C_BRA            L1884   # 0x181e
L1820:  CHWIDTH_MULTI    66, 1   # 0x1820
        ADDI             R6, R6, -58   # 0x1824
        AND              R1, R6, R4, R6   # 0x1828
        CHWIDTH_MULTI    66, 0   # 0x182c
        MOVI             R6, 245   # 0x1830
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x1834
        MOVI             R11, 4   # 0x1838
        BRA_PRED         0, L18b8   # 0x183c
        MOVI             R11, 1   # 0x1840
L1844:  LD_LOCAL         R1, 20   # 0x1844
        C_ADDI           R1, 1   # 0x1848
        ST_LOCAL         R1, 20   # 0x184a
        C_BRA            L18b8   # 0x184e
L1850:  CHWIDTH_MULTI    66, 1   # 0x1850
        ADDI             R6, R6, -58   # 0x1854
        AND              R1, R6, R4, R6   # 0x1858
        CHWIDTH_MULTI    66, 0   # 0x185c
        MOVI             R6, 245   # 0x1860
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x1864
        MOVI             R11, 5   # 0x1868
        BRA_PRED         0, L18b8   # 0x186c
        MOVI             R11, 1   # 0x1870
L1874:  LD_LOCAL         R1, 32   # 0x1874
        C_ADDI           R1, 1   # 0x1878
        ST_LOCAL         R1, 32   # 0x187a
        C_BRA            L18b8   # 0x187e
L1880:  MOVI             R11, 4   # 0x1880
L1884:  LD_LOCAL         R1, 12   # 0x1884
        C_ADDI           R1, 1   # 0x1888
        ST_LOCAL         R1, 12   # 0x188a
        C_BRA            L18b8   # 0x188e
L1890:  MOVI             R11, 1   # 0x1890
L1894:  LD_LOCAL         R1, 16   # 0x1894
        C_ADDI           R1, 1   # 0x1898
        ST_LOCAL         R1, 16   # 0x189a
        C_BRA            L18b8   # 0x189e
L18a0:  MOVI             R11, 1   # 0x18a0
        LD_LOCAL         R1, 28   # 0x18a4
        C_ADDI           R1, 1   # 0x18a8
        ST_LOCAL         R1, 28   # 0x18aa
L18ae:  LD_LOCAL         R1, 24   # 0x18ae
        C_ADDI           R1, 1   # 0x18b2
        ST_LOCAL         R1, 24   # 0x18b4
L18b8:  C_CHWIDTH        R6, 2   # 0x18b8
        LD_GLOBAL_IDX    R6, R2, R3, 0, 1   # 0x18ba
        C_CHWIDTH        R6, 0   # 0x18be
        SETP_EQ_NPI      P0, R1, R6, 0   # 0x18c0
        BRA_PRED         0, L16a4   # 0x18c4
        SETP_EQ_NPI      P0, R1, R11, 1   # 0x18c8
        BRA_PRED         4, L168e   # 0x18cc
        BRA              L16a4   # 0x18d0
L18d4:  LD_LOCAL         R12, 32   # 0x18d4
L18d8:  LD_LOCAL         R1, 36   # 0x18d8
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x18dc
        BRA_PRED         0, L196c   # 0x18e0
        LD_LOCAL         R1, 52   # 0x18e4
        C_MOV            R6, R1   # 0x18e8
        ADD              R3, R13, R7, R13   # 0x18ea
        ADD              R1, R14, R7, R14   # 0x18ee
        C_ADD            R3, R14   # 0x18f2
        C_NOT            R3, R3   # 0x18f4
L18f6:  C_CHWIDTH        R4, 2   # 0x18f6
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x18f8
        C_CHWIDTH        R4, 0   # 0x18fc
        SETP_EQ_NPI      P0, R8, R4, 44   # 0x18fe
        BRA_PRED         0, L1918   # 0x1902
        C_CHWIDTH        R4, 1   # 0x1906
        XOR              R4, R4, R6, R4   # 0x1908
        C_MOV            R8, R4   # 0x190c
        C_CHWIDTH        R4, 0   # 0x190e
        C_CHWIDTH        R8, 2   # 0x1910
        ST_GLOBAL_IDX    R8, R2, R13, 0, 0   # 0x1912
        C_CHWIDTH        R8, 0   # 0x1916
L1918:  ADD              R4, R14, R13, R14   # 0x1918
        OR               R8, R7, R4, R7   # 0x191c
        C_AND            R8, R3   # 0x1920
        AND              R10, R7, R4, R7   # 0x1922
        OR               R8, R10, R8, R10   # 0x1926
        ADD              R10, R1, R13, R1   # 0x192a
        ADD              R11, R7, R0, R7   # 0x192e
        SETP_LT_U_NP     P0, R10, R10, R11   # 0x1932
        OR               R10, R7, R0, R7   # 0x1936
        C_ANDN           R10, R11   # 0x193a
        AND              R11, R7, R0, R7   # 0x193c
        OR               R10, R11, R10, R11   # 0x1940
        SHRI             R10, R10, 31   # 0x1944
        SHRI             R8, R8, 31   # 0x1948
        SETP_EQ_NP       P1, R11, R8, R10   # 0x194c
        ADD              R10, R5, R10, R5   # 0x1950
        ADD              R8, R5, R8, R5   # 0x1954
        SETP_LT_U_NP     P2, R8, R8, R10   # 0x1958
        C_SUB            R3, R14   # 0x195c
        C_MOV            R13, R4   # 0x195e
        BRA_PRED         2, L18f6   # 0x1960
        PAND             P0, 1, 0   # 0x1964
        C_MOV            R13, R4   # 0x1966
        BRA_PRED         0, L18f6   # 0x1968
L196c:  LD_GLOBAL        R1, R15, -36   # 0x196c
        LD_LOCAL         R2, 48   # 0x1970
        CALL             R14, 129624   # 0x1974
        MOVI             R15, 2   # 0x1978
        LD_GLOBAL        R15, R15, 24   # 0x197c
        SRD              R3, 2   # 0x1980
        C_ADD            R15, R3   # 0x1982
        C_MOV            R2, R1   # 0x1984
        LD_LOCAL         R1, 24   # 0x1986
        CALL             R14, 129613   # 0x198a
        MOVI             R15, 2   # 0x198e
        LD_GLOBAL        R15, R15, 24   # 0x1992
        SRD              R3, 2   # 0x1996
        C_ADD            R15, R3   # 0x1998
        C_MOV            R2, R1   # 0x199a
        LD_GLOBAL        R1, R15, -32   # 0x199c
        CALL             R14, 129602   # 0x19a0
        MOVI             R15, 2   # 0x19a4
        LD_GLOBAL        R15, R15, 24   # 0x19a8
        SRD              R3, 2   # 0x19ac
        C_ADD            R15, R3   # 0x19ae
        C_MOV            R2, R1   # 0x19b0
        LD_LOCAL         R1, 28   # 0x19b2
        CALL             R14, 129591   # 0x19b6
        MOVI             R15, 2   # 0x19ba
        LD_GLOBAL        R15, R15, 24   # 0x19be
        SRD              R3, 2   # 0x19c2
        C_ADD            R15, R3   # 0x19c4
        C_MOV            R2, R1   # 0x19c6
        LD_GLOBAL        R1, R15, -28   # 0x19c8
        CALL             R14, 129580   # 0x19cc
        MOVI             R15, 2   # 0x19d0
        LD_GLOBAL        R15, R15, 24   # 0x19d4
        SRD              R3, 2   # 0x19d8
        C_ADD            R15, R3   # 0x19da
        C_MOV            R2, R1   # 0x19dc
        LD_LOCAL         R1, 12   # 0x19de
        CALL             R14, 129569   # 0x19e2
        MOVI             R15, 2   # 0x19e6
        LD_GLOBAL        R15, R15, 24   # 0x19ea
        SRD              R3, 2   # 0x19ee
        C_ADD            R15, R3   # 0x19f0
        C_MOV            R2, R1   # 0x19f2
        LD_GLOBAL        R1, R15, -24   # 0x19f4
        CALL             R14, 129558   # 0x19f8
        MOVI             R15, 2   # 0x19fc
        LD_GLOBAL        R15, R15, 24   # 0x1a00
        SRD              R3, 2   # 0x1a04
        C_ADD            R15, R3   # 0x1a06
        C_MOV            R2, R1   # 0x1a08
        LD_LOCAL         R1, 16   # 0x1a0a
        CALL             R14, 129547   # 0x1a0e
        MOVI             R15, 2   # 0x1a12
        LD_GLOBAL        R15, R15, 24   # 0x1a16
        SRD              R3, 2   # 0x1a1a
        C_ADD            R15, R3   # 0x1a1c
        C_MOV            R2, R1   # 0x1a1e
        LD_GLOBAL        R1, R15, -20   # 0x1a20
        CALL             R14, 129536   # 0x1a24
        MOVI             R15, 2   # 0x1a28
        LD_GLOBAL        R15, R15, 24   # 0x1a2c
        SRD              R3, 2   # 0x1a30
        C_ADD            R15, R3   # 0x1a32
        C_MOV            R2, R1   # 0x1a34
        LD_LOCAL         R1, 20   # 0x1a36
        CALL             R14, 129525   # 0x1a3a
        MOVI             R15, 2   # 0x1a3e
        LD_GLOBAL        R15, R15, 24   # 0x1a42
        SRD              R3, 2   # 0x1a46
        C_ADD            R15, R3   # 0x1a48
        C_MOV            R2, R1   # 0x1a4a
        LD_GLOBAL        R1, R15, -16   # 0x1a4c
        CALL             R14, 129514   # 0x1a50
        MOVI             R15, 2   # 0x1a54
        LD_GLOBAL        R15, R15, 24   # 0x1a58
        SRD              R3, 2   # 0x1a5c
        C_ADD            R15, R3   # 0x1a5e
        C_MOV            R2, R1   # 0x1a60
        C_MOV            R1, R12   # 0x1a62
        CALL             R14, 129504   # 0x1a64
        MOVI             R15, 2   # 0x1a68
        LD_GLOBAL        R15, R15, 24   # 0x1a6c
        SRD              R3, 2   # 0x1a70
        C_ADD            R15, R3   # 0x1a72
        C_MOV            R2, R1   # 0x1a74
        LD_GLOBAL        R1, R15, -12   # 0x1a76
        CALL             R14, 129493   # 0x1a7a
        MOVI             R15, 2   # 0x1a7e
        LD_GLOBAL        R15, R15, 24   # 0x1a82
        SRD              R3, 2   # 0x1a86
        C_ADD            R15, R3   # 0x1a88
        C_MOV            R2, R1   # 0x1a8a
        C_MOV            R1, R9   # 0x1a8c
        CALL             R14, 129483   # 0x1a8e
        MOVI             R15, 2   # 0x1a92
        LD_GLOBAL        R15, R15, 24   # 0x1a96
        SRD              R3, 2   # 0x1a9a
        C_ADD            R15, R3   # 0x1a9c
        C_MOV            R2, R1   # 0x1a9e
        LD_GLOBAL        R1, R15, -8   # 0x1aa0
        CALL             R14, 129472   # 0x1aa4
        MOVI             R15, 2   # 0x1aa8
        LD_GLOBAL        R15, R15, 24   # 0x1aac
        SRD              R3, 2   # 0x1ab0
        C_ADD            R15, R3   # 0x1ab2
        C_MOV            R2, R1   # 0x1ab4
        MOVI             R1, 0   # 0x1ab6
        CALL             R14, 129461   # 0x1aba
        MOVI             R15, 2   # 0x1abe
        LD_GLOBAL        R15, R15, 24   # 0x1ac2
        SRD              R3, 2   # 0x1ac6
        C_ADD            R15, R3   # 0x1ac8
        LD_LOCAL         R14, 44   # 0x1aca
        LD_LOCAL         R13, 80   # 0x1ace
        LD_LOCAL         R12, 76   # 0x1ad2
        LD_LOCAL         R11, 72   # 0x1ad6
        LD_LOCAL         R10, 68   # 0x1ada
        LD_LOCAL         R9, 64   # 0x1ade
        LD_LOCAL         R8, 60   # 0x1ae2
        C_RET            224   # 0x1ae6
        CHWIDTH_MULTI    7, 1   # 0x1ae8
        XOR              R0, R2, R1, R2   # 0x1aec
        CHWIDTH_MULTI    7, 0   # 0x1af0
        C_ANDI           R0, 1   # 0x1af4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1af6
        MOVI             R0, 40961   # 0x1afa
        C_MOV            R7, R0   # 0x1afe
        SHRI             R0, R2, 1   # 0x1b00
        C_CHWIDTH        R2, 1   # 0x1b04
        XOR              R2, R0, R7, R0   # 0x1b06
        C_CHWIDTH        R2, 0   # 0x1b0a
        MOV_P            R0, 0, R2, R2, R2   # 0x1b0c
        C_CHWIDTH        R0, 1   # 0x1b10
        SHRI             R2, R1, 1   # 0x1b12
        C_CHWIDTH        R2, 1   # 0x1b16
        XOR              R2, R2, R0, R2   # 0x1b18
        CHWIDTH_MULTI    5, 0   # 0x1b1c
        C_ANDI           R2, 1   # 0x1b20
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b22
        C_CHWIDTH        R2, 1   # 0x1b26
        SHRI             R0, R0, 1   # 0x1b28
        XOR              R2, R0, R7, R0   # 0x1b2c
        C_CHWIDTH        R2, 0   # 0x1b30
        MOV_P            R0, 0, R2, R2, R2   # 0x1b32
        C_CHWIDTH        R0, 1   # 0x1b36
        SHRI             R2, R1, 2   # 0x1b38
        C_CHWIDTH        R2, 1   # 0x1b3c
        XOR              R2, R2, R0, R2   # 0x1b3e
        CHWIDTH_MULTI    5, 0   # 0x1b42
        C_ANDI           R2, 1   # 0x1b46
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b48
        C_CHWIDTH        R2, 1   # 0x1b4c
        SHRI             R0, R0, 1   # 0x1b4e
        XOR              R2, R0, R7, R0   # 0x1b52
        C_CHWIDTH        R2, 0   # 0x1b56
        MOV_P            R0, 0, R2, R2, R2   # 0x1b58
        C_CHWIDTH        R0, 1   # 0x1b5c
        SHRI             R2, R1, 3   # 0x1b5e
        C_CHWIDTH        R2, 1   # 0x1b62
        XOR              R2, R2, R0, R2   # 0x1b64
        CHWIDTH_MULTI    5, 0   # 0x1b68
        C_ANDI           R2, 1   # 0x1b6c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b6e
        C_CHWIDTH        R2, 1   # 0x1b72
        SHRI             R0, R0, 1   # 0x1b74
        XOR              R2, R0, R7, R0   # 0x1b78
        C_CHWIDTH        R2, 0   # 0x1b7c
        MOV_P            R0, 0, R2, R2, R2   # 0x1b7e
        C_CHWIDTH        R0, 1   # 0x1b82
        SHRI             R2, R1, 4   # 0x1b84
        C_CHWIDTH        R2, 1   # 0x1b88
        XOR              R2, R2, R0, R2   # 0x1b8a
        CHWIDTH_MULTI    5, 0   # 0x1b8e
        C_ANDI           R2, 1   # 0x1b92
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b94
        C_CHWIDTH        R2, 1   # 0x1b98
        SHRI             R0, R0, 1   # 0x1b9a
        XOR              R2, R0, R7, R0   # 0x1b9e
        C_CHWIDTH        R2, 0   # 0x1ba2
        MOV_P            R0, 0, R2, R2, R2   # 0x1ba4
        C_CHWIDTH        R0, 1   # 0x1ba8
        SHRI             R2, R1, 5   # 0x1baa
        C_CHWIDTH        R2, 1   # 0x1bae
        XOR              R2, R2, R0, R2   # 0x1bb0
        CHWIDTH_MULTI    5, 0   # 0x1bb4
        C_ANDI           R2, 1   # 0x1bb8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bba
        C_CHWIDTH        R2, 1   # 0x1bbe
        SHRI             R0, R0, 1   # 0x1bc0
        XOR              R2, R0, R7, R0   # 0x1bc4
        C_CHWIDTH        R2, 0   # 0x1bc8
        MOV_P            R0, 0, R2, R2, R2   # 0x1bca
        C_CHWIDTH        R0, 1   # 0x1bce
        SHRI             R2, R1, 6   # 0x1bd0
        C_CHWIDTH        R2, 1   # 0x1bd4
        XOR              R2, R2, R0, R2   # 0x1bd6
        CHWIDTH_MULTI    5, 0   # 0x1bda
        C_ANDI           R2, 1   # 0x1bde
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1be0
        C_CHWIDTH        R2, 1   # 0x1be4
        SHRI             R0, R0, 1   # 0x1be6
        XOR              R2, R0, R7, R0   # 0x1bea
        C_CHWIDTH        R2, 0   # 0x1bee
        MOV_P            R0, 0, R2, R2, R2   # 0x1bf0
        MOVI             R2, 128   # 0x1bf4
        C_CHWIDTH        R2, 1   # 0x1bf8
        AND              R2, R1, R2, R1   # 0x1bfa
        C_CHWIDTH        R2, 0   # 0x1bfe
        SHRI             R2, R2, 7   # 0x1c00
        ANDI             R3, R0, 1   # 0x1c04
        C_CHWIDTH        R0, 1   # 0x1c08
        C_CHWIDTH        R0, 0   # 0x1c0a
        SETP_EQ_NP       P0, R2, R2, R3   # 0x1c0c
        C_CHWIDTH        R2, 1   # 0x1c10
        SHRI             R0, R0, 1   # 0x1c12
        XOR              R2, R0, R7, R0   # 0x1c16
        C_CHWIDTH        R2, 0   # 0x1c1a
        MOV_P            R2, 0, R0, R0, R0   # 0x1c1c
        C_CHWIDTH        R2, 1   # 0x1c20
        SHRI             R0, R1, 8   # 0x1c22
        C_CHWIDTH        R0, 1   # 0x1c26
        XOR              R0, R2, R0, R2   # 0x1c28
        CHWIDTH_MULTI    5, 0   # 0x1c2c
        C_ANDI           R0, 1   # 0x1c30
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1c32
        SHRI             R0, R2, 1   # 0x1c36
        C_CHWIDTH        R2, 1   # 0x1c3a
        XOR              R2, R0, R7, R0   # 0x1c3c
        C_CHWIDTH        R2, 0   # 0x1c40
        MOV_P            R0, 0, R2, R2, R2   # 0x1c42
        C_CHWIDTH        R0, 1   # 0x1c46
        SHRI             R2, R1, 9   # 0x1c48
        C_CHWIDTH        R2, 1   # 0x1c4c
        XOR              R2, R2, R0, R2   # 0x1c4e
        CHWIDTH_MULTI    5, 0   # 0x1c52
        C_ANDI           R2, 1   # 0x1c56
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c58
        C_CHWIDTH        R2, 1   # 0x1c5c
        SHRI             R0, R0, 1   # 0x1c5e
        XOR              R2, R0, R7, R0   # 0x1c62
        C_CHWIDTH        R2, 0   # 0x1c66
        MOV_P            R0, 0, R2, R2, R2   # 0x1c68
        C_CHWIDTH        R0, 1   # 0x1c6c
        SHRI             R2, R1, 10   # 0x1c6e
        C_CHWIDTH        R2, 1   # 0x1c72
        XOR              R2, R2, R0, R2   # 0x1c74
        CHWIDTH_MULTI    5, 0   # 0x1c78
        C_ANDI           R2, 1   # 0x1c7c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c7e
        C_CHWIDTH        R2, 1   # 0x1c82
        SHRI             R0, R0, 1   # 0x1c84
        XOR              R2, R0, R7, R0   # 0x1c88
        C_CHWIDTH        R2, 0   # 0x1c8c
        MOV_P            R0, 0, R2, R2, R2   # 0x1c8e
        C_CHWIDTH        R0, 1   # 0x1c92
        SHRI             R2, R1, 11   # 0x1c94
        C_CHWIDTH        R2, 1   # 0x1c98
        XOR              R2, R2, R0, R2   # 0x1c9a
        CHWIDTH_MULTI    5, 0   # 0x1c9e
        C_ANDI           R2, 1   # 0x1ca2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1ca4
        C_CHWIDTH        R2, 1   # 0x1ca8
        SHRI             R0, R0, 1   # 0x1caa
        XOR              R2, R0, R7, R0   # 0x1cae
        C_CHWIDTH        R2, 0   # 0x1cb2
        MOV_P            R0, 0, R2, R2, R2   # 0x1cb4
        C_CHWIDTH        R0, 1   # 0x1cb8
        SHRI             R2, R1, 12   # 0x1cba
        C_CHWIDTH        R2, 1   # 0x1cbe
        XOR              R2, R2, R0, R2   # 0x1cc0
        CHWIDTH_MULTI    5, 0   # 0x1cc4
        C_ANDI           R2, 1   # 0x1cc8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1cca
        C_CHWIDTH        R2, 1   # 0x1cce
        SHRI             R0, R0, 1   # 0x1cd0
        XOR              R2, R0, R7, R0   # 0x1cd4
        C_CHWIDTH        R2, 0   # 0x1cd8
        MOV_P            R0, 0, R2, R2, R2   # 0x1cda
        C_CHWIDTH        R0, 1   # 0x1cde
        SHRI             R2, R1, 13   # 0x1ce0
        C_CHWIDTH        R2, 1   # 0x1ce4
        XOR              R2, R2, R0, R2   # 0x1ce6
        CHWIDTH_MULTI    5, 0   # 0x1cea
        C_ANDI           R2, 1   # 0x1cee
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1cf0
        C_CHWIDTH        R2, 1   # 0x1cf4
        SHRI             R0, R0, 1   # 0x1cf6
        XOR              R2, R0, R7, R0   # 0x1cfa
        C_CHWIDTH        R2, 0   # 0x1cfe
        MOV_P            R0, 0, R2, R2, R2   # 0x1d00
        C_CHWIDTH        R0, 1   # 0x1d04
        SHRI             R2, R1, 14   # 0x1d06
        C_CHWIDTH        R2, 1   # 0x1d0a
        XOR              R2, R2, R0, R2   # 0x1d0c
        CHWIDTH_MULTI    5, 0   # 0x1d10
        C_ANDI           R2, 1   # 0x1d14
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1d16
        C_CHWIDTH        R2, 1   # 0x1d1a
        SHRI             R0, R0, 1   # 0x1d1c
        XOR              R2, R0, R7, R0   # 0x1d20
        C_CHWIDTH        R2, 0   # 0x1d24
        MOV_P            R0, 0, R2, R2, R2   # 0x1d26
        SHRI             R1, R1, 15   # 0x1d2a
        ANDI             R2, R0, 1   # 0x1d2e
        C_CHWIDTH        R0, 1   # 0x1d32
        C_CHWIDTH        R0, 0   # 0x1d34
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1d36
        C_CHWIDTH        R1, 1   # 0x1d3a
        SHRI             R0, R0, 1   # 0x1d3c
        XOR              R1, R0, R7, R0   # 0x1d40
        C_CHWIDTH        R1, 0   # 0x1d44
        MOV_P            R1, 0, R0, R0, R0   # 0x1d46
        MOVI             R0, 65535   # 0x1d4a
        C_AND            R1, R0   # 0x1d4e
        C_RET            224   # 0x1d50
        ST_LOCAL         R8, 72   # 0x1d52
        ST_LOCAL         R9, 76   # 0x1d56
        ST_LOCAL         R10, 80   # 0x1d5a
        ST_LOCAL         R11, 84   # 0x1d5e
        ST_LOCAL         R12, 88   # 0x1d62
        ST_LOCAL         R13, 92   # 0x1d66
        C_MOV            R15, R14   # 0x1d6a
        C_MOV            R8, R4   # 0x1d6c
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x1d6e
        SHLI             R0, R0, 16   # 0x1d72
        ST_LOCAL         R0, 44   # 0x1d76
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x1d7a
        ST_LOCAL         R0, 64   # 0x1d7e
        SHRI             R0, R0, 16   # 0x1d82
        ST_LOCAL         R0, 68   # 0x1d86
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x1d8a
        SHLI             R0, R0, 16   # 0x1d8e
        LD_GLOBAL_IDX    R14, R1, R2, 0, 8   # 0x1d92
        SHRI             R5, R14, 16   # 0x1d96
        C_OR             R0, R5   # 0x1d9a
        LD_GLOBAL_IDX    R5, R1, R2, 0, 28   # 0x1d9c
        SHLI             R5, R5, 16   # 0x1da0
        LD_GLOBAL_IDX    R6, R1, R2, 0, 24   # 0x1da4
        SHRI             R7, R6, 16   # 0x1da8
        OR               R4, R5, R7, R5   # 0x1dac
        ST_LOCAL         R4, 20   # 0x1db0
        MOVI             R4, 65535   # 0x1db4
        AND              R7, R14, R4, R14   # 0x1db8
        C_CHWIDTH        R14, 1   # 0x1dbc
        AND              R4, R6, R4, R6   # 0x1dbe
        ST_LOCAL         R4, 16   # 0x1dc2
        LD_GLOBAL_IDX    R5, R1, R2, 0, 0   # 0x1dc6
        MOVI             R2, 0   # 0x1dca
        MOVI             R1, 61440   # 0x1dce
        C_MOV            R11, R3   # 0x1dd2
        OR               R14, R11, R1, R11   # 0x1dd4
        SETP_EQ_NPI      P0, R1, R5, 0   # 0x1dd8
        ANDI             R12, R5, -2   # 0x1ddc
        ANDI             R1, R5, 1   # 0x1de0
        ST_LOCAL         R1, 28   # 0x1de4
        ADDI             R1, R5, -1   # 0x1de8
        ST_LOCAL         R1, 24   # 0x1dec
        CVT_SEXT         R10, R14, R14, R14   # 0x1df0
        ANDI             R9, R5, -4   # 0x1df4
        ST_LOCAL         R5, 12   # 0x1df8
        ST_LOCAL         R9, 40   # 0x1dfc
        ST_LOCAL         R15, 48   # 0x1e00
        ST_LOCAL         R11, 52   # 0x1e04
        ST_LOCAL         R8, 56   # 0x1e08
        BRA_PRED         0, L20cc   # 0x1e0c
        ANDI             R1, R5, 3   # 0x1e10
        MOVI             R6, 0   # 0x1e14
        C_BRA            L1e2c   # 0x1e18
L1e1a:  C_CHWIDTH        R14, 0   # 0x1e1a
        LD_LOCAL         R3, 12   # 0x1e1c
        C_ADD            R2, R3   # 0x1e20
        C_ADDI           R6, 1   # 0x1e22
        SETP_NE_NP       P0, R3, R6, R3   # 0x1e24
        BRA_PRED         4, L1ec4   # 0x1e28
L1e2c:  CHWIDTH_MULTI    24576, 1   # 0x1e2c
        MOVI             R3, 0   # 0x1e30
        LD_LOCAL         R5, 24   # 0x1e34
        SETP_LT_U_NPI    P0, R5, R5, 3   # 0x1e38
        BRA_PRED         0, L1e92   # 0x1e3c
L1e40:  ADD              R5, R2, R3, R2   # 0x1e40
        C_SHLI           R5, 1   # 0x1e44
        ADD              R5, R7, R5, R7   # 0x1e46
        LD_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e4a
        ADD              R14, R14, R11, R14   # 0x1e4e
        ST_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e52
        C_CHWIDTH        R14, 0   # 0x1e56
        ADDI             R14, R5, 2   # 0x1e58
        LD_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e5c
        ADD              R13, R13, R11, R13   # 0x1e60
        ST_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e64
        ADDI             R14, R5, 4   # 0x1e68
        LD_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e6c
        ADD              R13, R13, R11, R13   # 0x1e70
        ST_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e74
        C_CHWIDTH        R14, 1   # 0x1e78
        C_ADDI           R5, 6   # 0x1e7a
        LD_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e7c
        ADD              R14, R14, R11, R14   # 0x1e80
        ST_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e84
        C_ADDI           R3, 4   # 0x1e88
        SETP_NE_NP       P0, R5, R9, R3   # 0x1e8a
        BRA_PRED         0, L1e40   # 0x1e8e
L1e92:  SETP_EQ_NPI      P0, R5, R1, 0   # 0x1e92
        BRA_PRED         0, L1e1a   # 0x1e96
        C_CHWIDTH        R14, 0   # 0x1e9a
        C_ADD            R3, R2   # 0x1e9c
        C_MOV            R5, R1   # 0x1e9e
L1ea0:  C_MOV            R14, R3   # 0x1ea0
        C_SHLI           R14, 1   # 0x1ea2
        ADD              R14, R7, R14, R7   # 0x1ea4
        LD_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1ea8
        ADD              R13, R13, R11, R13   # 0x1eac
        ST_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1eb0
        C_ADDI           R3, 1   # 0x1eb4
        ADDI             R5, R5, -1   # 0x1eb6
        SETP_NE_NPI      P0, R14, R5, 0   # 0x1eba
        BRA_PRED         0, L1ea0   # 0x1ebe
        C_BRA            L1e1a   # 0x1ec2
L1ec4:  C_CHWIDTH        R11, 1   # 0x1ec4
        MOVI             R2, 0   # 0x1ec6
        CVT_SEXT         R6, R11, R11, R11   # 0x1eca
        C_CHWIDTH        R11, 0   # 0x1ece
        MOVI             R14, 0   # 0x1ed0
        LD_LOCAL         R11, 20   # 0x1ed4
        LD_LOCAL         R15, 16   # 0x1ed8
        ST_LOCAL         R1, 36   # 0x1edc
        C_BRA            L1ef2   # 0x1ee0
L1ee2:  LD_LOCAL         R3, 12   # 0x1ee2
        C_ADD            R2, R3   # 0x1ee6
        C_ADDI           R14, 1   # 0x1ee8
        SETP_NE_NP       P0, R3, R14, R3   # 0x1eea
        BRA_PRED         4, L1fd0   # 0x1eee
L1ef2:  LD_LOCAL         R3, 24   # 0x1ef2
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1ef6
        MOVI             R5, 0   # 0x1efa
        LD_LOCAL         R1, 40   # 0x1efe
        BRA_PRED         0, L1f90   # 0x1f02
L1f06:  ADD              R3, R2, R5, R2   # 0x1f06
        C_MOV            R8, R3   # 0x1f0a
        C_SHLI           R8, 2   # 0x1f0c
        ADD              R8, R15, R8, R15   # 0x1f0e
        C_MOV            R9, R3   # 0x1f12
        C_SHLI           R9, 1   # 0x1f14
        ADD              R9, R7, R9, R7   # 0x1f16
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1f1a
        CVT_SEXT         R9, R13, R13, R13   # 0x1f1e
        C_MUL_LO         R9, R6   # 0x1f22
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1f24
        ADDI             R8, R3, 1   # 0x1f28
        C_MOV            R9, R8   # 0x1f2c
        C_SHLI           R9, 2   # 0x1f2e
        ADD              R9, R15, R9, R15   # 0x1f30
        C_SHLI           R8, 1   # 0x1f34
        ADD              R8, R7, R8, R7   # 0x1f36
        LD_GLOBAL_IDX    R13, R0, R8, 0, 0   # 0x1f3a
        CVT_SEXT         R8, R13, R13, R13   # 0x1f3e
        C_MUL_LO         R8, R6   # 0x1f42
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1f44
        ADDI             R8, R3, 2   # 0x1f48
        C_MOV            R9, R8   # 0x1f4c
        C_SHLI           R9, 2   # 0x1f4e
        ADD              R9, R15, R9, R15   # 0x1f50
        C_SHLI           R8, 1   # 0x1f54
        ADD              R8, R7, R8, R7   # 0x1f56
        LD_GLOBAL_IDX    R13, R0, R8, 0, 0   # 0x1f5a
        CVT_SEXT         R8, R13, R13, R13   # 0x1f5e
        C_MUL_LO         R8, R6   # 0x1f62
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1f64
        C_ADDI           R3, 3   # 0x1f68
        C_MOV            R8, R3   # 0x1f6a
        C_SHLI           R8, 2   # 0x1f6c
        ADD              R8, R15, R8, R15   # 0x1f6e
        C_SHLI           R3, 1   # 0x1f72
        ADD              R3, R7, R3, R7   # 0x1f74
        LD_GLOBAL_IDX    R13, R0, R3, 0, 0   # 0x1f78
        CVT_SEXT         R3, R13, R13, R13   # 0x1f7c
        C_MUL_LO         R3, R6   # 0x1f80
        ST_GLOBAL_IDX    R3, R11, R8, 0, 0   # 0x1f82
        C_ADDI           R5, 4   # 0x1f86
        SETP_NE_NP       P0, R3, R1, R5   # 0x1f88
        BRA_PRED         0, L1f06   # 0x1f8c
L1f90:  LD_LOCAL         R1, 36   # 0x1f90
        SETP_EQ_NPI      P0, R3, R1, 0   # 0x1f94
        BRA_PRED         0, L1ee2   # 0x1f98
        ADD              R3, R5, R2, R5   # 0x1f9c
        C_MOV            R5, R1   # 0x1fa0
L1fa2:  C_MOV            R8, R3   # 0x1fa2
        C_SHLI           R8, 2   # 0x1fa4
        ADD              R8, R15, R8, R15   # 0x1fa6
        C_MOV            R9, R3   # 0x1faa
        C_SHLI           R9, 1   # 0x1fac
        ADD              R9, R7, R9, R7   # 0x1fae
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1fb2
        CVT_SEXT         R9, R13, R13, R13   # 0x1fb6
        C_MUL_LO         R9, R6   # 0x1fba
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1fbc
        C_ADDI           R3, 1   # 0x1fc0
        ADDI             R5, R5, -1   # 0x1fc2
        SETP_NE_NPI      P0, R8, R5, 0   # 0x1fc6
        BRA_PRED         0, L1fa2   # 0x1fca
        C_BRA            L1ee2   # 0x1fce
L1fd0:  C_CHWIDTH        R13, 0   # 0x1fd0
        MOVI             R2, 0   # 0x1fd2
        C_MOV            R5, R2   # 0x1fd6
        MOVI             R14, 10   # 0x1fd8
        MOVI             R13, 0   # 0x1fdc
        MOVI             R6, 0   # 0x1fe0
        MOVI             R1, 0   # 0x1fe4
        MOVI             R8, 0   # 0x1fe8
        C_BRA            L1ffe   # 0x1fec
L1fee:  LD_LOCAL         R3, 12   # 0x1fee
        C_ADD            R13, R3   # 0x1ff2
        C_ADDI           R6, 1   # 0x1ff4
        SETP_NE_NP       P0, R3, R6, R3   # 0x1ff6
        BRA_PRED         4, L20d2   # 0x1ffa
L1ffe:  ST_LOCAL         R6, 36   # 0x1ffe
        LD_LOCAL         R3, 24   # 0x2002
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2006
        BRA_PRED         0, L207c   # 0x200a
        MOVI             R9, 0   # 0x200e
L2012:  C_CHWIDTH        R5, 0   # 0x2012
        ADD              R3, R13, R9, R13   # 0x2014
        C_SHLI           R3, 2   # 0x2018
        C_ADD            R3, R15   # 0x201a
        C_MOV            R6, R5   # 0x201c
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x201e
        SETP_LT_NP       P0, R1, R1, R5   # 0x2022
        MOVI             R15, 0   # 0x2026
        ADDI_P           R15, 0, R15, 1   # 0x202a
        ADD              R8, R5, R8, R5   # 0x202e
        SETP_LT_NP       P0, R1, R10, R8   # 0x2032
        MOV_P            R15, 0, R14, R14, R14   # 0x2036
        MOV_P            R8, 0, R2, R2, R2   # 0x203a
        ADDI             R1, R3, 4   # 0x203e
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x2042
        SETP_LT_NP       P0, R3, R5, R1   # 0x2046
        MOVI             R3, 0   # 0x204a
        ADDI_P           R3, 0, R3, 1   # 0x204e
        ADD              R8, R1, R8, R1   # 0x2052
        SETP_LT_NP       P0, R5, R10, R8   # 0x2056
        C_CHWIDTH        R5, 1   # 0x205a
        MOV_P            R3, 0, R14, R14, R14   # 0x205c
        MOV_P            R8, 0, R2, R2, R2   # 0x2060
        ADD              R5, R15, R6, R15   # 0x2064
        LD_LOCAL         R15, 16   # 0x2068
        ADD              R5, R3, R5, R3   # 0x206c
        C_ADDI           R9, 2   # 0x2070
        SETP_NE_NP       P0, R3, R12, R9   # 0x2072
        BRA_PRED         0, L2012   # 0x2076
        C_BRA            L2080   # 0x207a
L207c:  MOVI             R9, 0   # 0x207c
L2080:  LD_LOCAL         R3, 28   # 0x2080
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2084
        LD_LOCAL         R6, 36   # 0x2088
        BRA_PRED         0, L1fee   # 0x208c
        C_CHWIDTH        R5, 1   # 0x2090
        LD_LOCAL         R3, 12   # 0x2092
        MUL_LO           R3, R6, R3, R3   # 0x2096
        ADD              R3, R9, R3, R9   # 0x209a
        C_SHLI           R3, 2   # 0x209e
        ADD              R3, R15, R3, R15   # 0x20a0
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x20a4
        SETP_LT_NP       P0, R1, R1, R3   # 0x20a8
        ADD              R8, R3, R8, R3   # 0x20ac
        SETP_LT_NP       P1, R1, R10, R8   # 0x20b0
        MOV_P            R8, 1, R2, R2, R2   # 0x20b4
        MOVI             R1, 0   # 0x20b8
        ADDI_P           R1, 0, R1, 1   # 0x20bc
        MOV_P            R1, 1, R14, R14, R14   # 0x20c0
        ADD              R5, R1, R5, R1   # 0x20c4
        C_MOV            R1, R3   # 0x20c8
        C_BRA            L1fee   # 0x20ca
L20cc:  C_MOV            R5, R2   # 0x20cc
        LD_LOCAL         R11, 20   # 0x20ce
L20d2:  C_CHWIDTH        R5, 0   # 0x20d2
        ST_LOCAL         R5, 60   # 0x20d4
        LD_LOCAL         R1, 44   # 0x20d8
        LD_LOCAL         R2, 68   # 0x20dc
        OR               R8, R1, R2, R1   # 0x20e0
        LD_LOCAL         R1, 64   # 0x20e4
        MOVI             R2, 65535   # 0x20e8
        AND              R9, R1, R2, R1   # 0x20ec
        MOVI             R1, 0   # 0x20f0
        LD_LOCAL         R2, 12   # 0x20f4
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x20f8
        ST_LOCAL         R10, 32   # 0x20fc
        BRA_PRED         0, L2308   # 0x2100
        MOVI             R10, 0   # 0x2104
        C_BRA            L212a   # 0x2108
L210a:  C_MOV            R2, R10   # 0x210a
        C_SHLI           R2, 2   # 0x210c
        LD_LOCAL         R3, 16   # 0x210e
        ADD              R2, R3, R2, R3   # 0x2112
        ST_GLOBAL_IDX    R6, R11, R2, 0, 0   # 0x2116
        LD_LOCAL         R2, 12   # 0x211a
        C_ADD            R1, R2   # 0x211e
        C_ADDI           R10, 1   # 0x2120
        SETP_NE_NP       P0, R2, R10, R2   # 0x2122
        BRA_PRED         4, L21d8   # 0x2126
L212a:  C_CHWIDTH        R5, 0   # 0x212a
        LD_LOCAL         R2, 24   # 0x212c
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x2130
        BRA_PRED         0, L2194   # 0x2134
        C_CHWIDTH        R15, 1   # 0x2138
        C_CHWIDTH        R14, 0   # 0x213a
        MOVI             R5, 0   # 0x213c
        MOVI             R6, 0   # 0x2140
L2144:  ADD              R3, R1, R5, R1   # 0x2144
        C_SHLI           R3, 1   # 0x2148
        C_ADD            R3, R7   # 0x214a
        C_MOV            R14, R5   # 0x214c
        C_SHLI           R14, 1   # 0x214e
        C_ADD            R14, R9   # 0x2150
        LD_GLOBAL_IDX    R15, R8, R14, 0, 0   # 0x2152
        CVT_SEXT         R13, R15, R15, R15   # 0x2156
        LD_GLOBAL_IDX    R15, R0, R3, 0, 0   # 0x215a
        CVT_SEXT         R2, R15, R15, R15   # 0x215e
        MADLO            R2, R13, R2, R6   # 0x2162
        C_CHWIDTH        R6, 1   # 0x2166
        C_ADDI           R3, 2   # 0x2168
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x216a
        ADDI             R3, R14, 2   # 0x216e
        C_CHWIDTH        R14, 1   # 0x2172
        LD_GLOBAL_IDX    R14, R8, R3, 0, 0   # 0x2174
        CVT_SEXT         R3, R14, R14, R14   # 0x2178
        C_CHWIDTH        R14, 0   # 0x217c
        CVT_SEXT         R14, R6, R6, R6   # 0x217e
        C_CHWIDTH        R6, 0   # 0x2182
        MADLO            R6, R3, R14, R2   # 0x2184
        C_ADDI           R5, 2   # 0x2188
        SETP_NE_NP       P0, R2, R12, R5   # 0x218a
        BRA_PRED         0, L2144   # 0x218e
        C_BRA            L219c   # 0x2192
L2194:  MOVI             R5, 0   # 0x2194
        MOVI             R6, 0   # 0x2198
L219c:  C_CHWIDTH        R14, 1   # 0x219c
        LD_LOCAL         R2, 28   # 0x219e
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x21a2
        BRA_PRED         0, L210a   # 0x21a6
        LD_LOCAL         R2, 12   # 0x21aa
        MUL_LO           R2, R10, R2, R2   # 0x21ae
        ADD              R2, R5, R2, R5   # 0x21b2
        C_SHLI           R2, 1   # 0x21b6
        ADD              R2, R7, R2, R7   # 0x21b8
        LD_GLOBAL_IDX    R14, R0, R2, 0, 0   # 0x21bc
        C_SHLI           R5, 1   # 0x21c0
        ADD              R2, R9, R5, R9   # 0x21c2
        C_CHWIDTH        R5, 1   # 0x21c6
        LD_GLOBAL_IDX    R5, R8, R2, 0, 0   # 0x21c8
        CVT_SEXT         R2, R5, R5, R5   # 0x21cc
        CVT_SEXT         R3, R14, R14, R14   # 0x21d0
        MAD_ACC          R6, R2, R3   # 0x21d4
        C_BRA            L210a   # 0x21d6
L21d8:  C_CHWIDTH        R5, 0   # 0x21d8
        MOVI             R1, 0   # 0x21da
        C_MOV            R5, R1   # 0x21de
        MOVI             R3, 0   # 0x21e0
        ST_LOCAL         R1, 44   # 0x21e4
        MOVI             R13, 0   # 0x21e8
        MOVI             R4, 10   # 0x21ec
        C_BRA            L220e   # 0x21f0
L21f2:  LD_LOCAL         R2, 12   # 0x21f2
        LD_LOCAL         R3, 36   # 0x21f6
        C_ADD            R3, R2   # 0x21fa
        LD_LOCAL         R6, 44   # 0x21fc
        C_ADDI           R6, 1   # 0x2200
        ST_LOCAL         R6, 44   # 0x2202
        SETP_NE_NP       P0, R2, R6, R2   # 0x2206
        BRA_PRED         4, L230a   # 0x220a
L220e:  ST_LOCAL         R3, 36   # 0x220e
        LD_LOCAL         R2, 24   # 0x2212
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x2216
        BRA_PRED         0, L22a4   # 0x221a
        C_CHWIDTH        R14, 0   # 0x221e
        MOVI             R6, 0   # 0x2220
        LD_LOCAL         R2, 16   # 0x2224
        LD_LOCAL         R14, 32   # 0x2228
        LD_LOCAL         R2, 36   # 0x222c
L2230:  CHWIDTH_MULTI    32800, 0   # 0x2230
        LD_LOCAL         R2, 36   # 0x2234
        ADD              R3, R2, R6, R2   # 0x2238
        C_SHLI           R3, 2   # 0x223c
        LD_LOCAL         R2, 16   # 0x223e
        C_ADD            R3, R2   # 0x2242
        C_MOV            R15, R5   # 0x2244
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x2246
        SETP_LT_NP       P0, R1, R1, R5   # 0x224a
        MOVI             R2, 0   # 0x224e
        ADDI_P           R2, 0, R2, 1   # 0x2252
        ADD              R13, R5, R13, R5   # 0x2256
        SETP_LT_NP       P0, R1, R14, R13   # 0x225a
        MOV_P            R2, 0, R4, R4, R4   # 0x225e
        MOVI             R10, 0   # 0x2262
        MOV_P            R13, 0, R10, R10, R10   # 0x2266
        ADDI             R1, R3, 4   # 0x226a
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x226e
        SETP_LT_NP       P0, R3, R5, R1   # 0x2272
        MOVI             R3, 0   # 0x2276
        ADDI_P           R3, 0, R3, 1   # 0x227a
        ADD              R13, R1, R13, R1   # 0x227e
        SETP_LT_NP       P0, R5, R14, R13   # 0x2282
        C_CHWIDTH        R5, 1   # 0x2286
        MOV_P            R3, 0, R4, R4, R4   # 0x2288
        MOV_P            R13, 0, R10, R10, R10   # 0x228c
        ADD              R5, R2, R15, R2   # 0x2290
        ADD              R5, R3, R5, R3   # 0x2294
        C_ADDI           R6, 2   # 0x2298
        SETP_NE_NP       P0, R2, R12, R6   # 0x229a
        BRA_PRED         0, L2230   # 0x229e
        C_BRA            L22ae   # 0x22a2
L22a4:  C_CHWIDTH        R14, 0   # 0x22a4
        MOVI             R6, 0   # 0x22a6
        LD_LOCAL         R14, 32   # 0x22aa
L22ae:  C_CHWIDTH        R15, 0   # 0x22ae
        LD_LOCAL         R2, 28   # 0x22b0
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x22b4
        MOVI             R15, 0   # 0x22b8
        MOVI             R10, 10   # 0x22bc
        BRA_PRED         0, L21f2   # 0x22c0
        C_CHWIDTH        R5, 1   # 0x22c4
        LD_LOCAL         R2, 44   # 0x22c6
        LD_LOCAL         R3, 12   # 0x22ca
        C_MUL_LO         R2, R3   # 0x22ce
        ADD              R2, R6, R2, R6   # 0x22d0
        C_SHLI           R2, 2   # 0x22d4
        LD_LOCAL         R3, 16   # 0x22d6
        ADD              R2, R3, R2, R3   # 0x22da
        LD_GLOBAL_IDX    R2, R11, R2, 0, 0   # 0x22de
        SETP_LT_NP       P0, R1, R1, R2   # 0x22e2
        ADD              R13, R2, R13, R2   # 0x22e6
        SETP_LT_NP       P1, R1, R14, R13   # 0x22ea
        MOV_P            R13, 1, R15, R15, R15   # 0x22ee
        MOVI             R1, 0   # 0x22f2
        ADDI_P           R1, 0, R1, 1   # 0x22f6
        MOV_P            R1, 1, R10, R10, R10   # 0x22fa
        ADD              R5, R1, R5, R1   # 0x22fe
        C_MOV            R1, R2   # 0x2302
        BRA              L21f2   # 0x2304
L2308:  C_MOV            R5, R1   # 0x2308
L230a:  C_CHWIDTH        R5, 0   # 0x230a
        ST_LOCAL         R5, 64   # 0x230c
        MOVI             R1, 0   # 0x2310
        LD_LOCAL         R3, 12   # 0x2314
        SETP_EQ_NPI      P0, R2, R3, 0   # 0x2318
        C_MOV            R2, R3   # 0x231c
        C_SHLI           R2, 1   # 0x231e
        LD_LOCAL         R3, 40   # 0x2320
        BRA_PRED         0, L257a   # 0x2324
        MOVI             R5, 0   # 0x2328
        LD_LOCAL         R10, 12   # 0x232c
        C_BRA            L2342   # 0x2330
L2332:  C_ADD            R1, R10   # 0x2332
        LD_LOCAL         R5, 44   # 0x2334
        C_ADDI           R5, 1   # 0x2338
        SETP_NE_NP       P0, R3, R5, R10   # 0x233a
        BRA_PRED         4, L2434   # 0x233e
L2342:  ST_LOCAL         R5, 44   # 0x2342
        MUL_LO           R3, R5, R10, R10   # 0x2346
        ST_LOCAL         R3, 36   # 0x234a
        MOVI             R11, 0   # 0x234e
        C_BRA            L237a   # 0x2352
L2354:  C_CHWIDTH        R6, 0   # 0x2354
        LD_LOCAL         R3, 36   # 0x2356
        ADD              R3, R11, R3, R11   # 0x235a
        C_SHLI           R3, 2   # 0x235e
        LD_LOCAL         R6, 16   # 0x2360
        ADD              R3, R6, R3, R6   # 0x2364
        LD_LOCAL         R6, 20   # 0x2368
        ST_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x236c
        C_ADDI           R11, 1   # 0x2370
        SETP_NE_NP       P0, R3, R11, R10   # 0x2372
        BRA_PRED         4, L2332   # 0x2376
L237a:  LD_LOCAL         R3, 24   # 0x237a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x237e
        MOVI             R13, 0   # 0x2382
        MOVI             R5, 0   # 0x2386
        BRA_PRED         0, L23f6   # 0x238a
        C_MOV            R15, R11   # 0x238e
        MOVI             R5, 0   # 0x2390
L2394:  C_CHWIDTH        R14, 0   # 0x2394
        C_CHWIDTH        R10, 1   # 0x2396
        ADD              R6, R1, R13, R1   # 0x2398
        C_SHLI           R6, 1   # 0x239c
        C_ADD            R6, R7   # 0x239e
        C_MOV            R3, R15   # 0x23a0
        C_SHLI           R3, 1   # 0x23a2
        ADD              R3, R9, R3, R9   # 0x23a4
        LD_GLOBAL_IDX    R10, R8, R3, 0, 0   # 0x23a8
        CVT_SEXT         R3, R10, R10, R10   # 0x23ac
        LD_GLOBAL_IDX    R10, R0, R6, 0, 0   # 0x23b0
        CVT_SEXT         R14, R10, R10, R10   # 0x23b4
        C_CHWIDTH        R10, 0   # 0x23b8
        LD_LOCAL         R10, 12   # 0x23ba
        MADLO            R3, R3, R14, R5   # 0x23be
        C_CHWIDTH        R14, 1   # 0x23c2
        ADDI             R5, R6, 2   # 0x23c4
        C_CHWIDTH        R6, 1   # 0x23c8
        LD_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x23ca
        ADD              R5, R10, R15, R10   # 0x23ce
        C_SHLI           R5, 1   # 0x23d2
        ADD              R5, R9, R5, R9   # 0x23d4
        LD_GLOBAL_IDX    R6, R8, R5, 0, 0   # 0x23d8
        CVT_SEXT         R5, R6, R6, R6   # 0x23dc
        C_CHWIDTH        R6, 0   # 0x23e0
        CVT_SEXT         R6, R14, R14, R14   # 0x23e2
        MADLO            R5, R5, R6, R3   # 0x23e6
        C_ADD            R15, R2   # 0x23ea
        C_ADDI           R13, 2   # 0x23ec
        SETP_NE_NP       P0, R3, R12, R13   # 0x23ee
        BRA_PRED         0, L2394   # 0x23f2
L23f6:  LD_LOCAL         R3, 28   # 0x23f6
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x23fa
        BRA_PRED         0, L2354   # 0x23fe
        CHWIDTH_MULTI    16448, 1   # 0x2402
        MADLO            R3, R13, R10, R11   # 0x2406
        C_SHLI           R3, 1   # 0x240a
        ADD              R3, R9, R3, R9   # 0x240c
        LD_GLOBAL_IDX    R14, R8, R3, 0, 0   # 0x2410
        LD_LOCAL         R3, 36   # 0x2414
        ADD              R3, R13, R3, R13   # 0x2418
        C_SHLI           R3, 1   # 0x241c
        ADD              R3, R7, R3, R7   # 0x241e
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x2422
        CVT_SEXT         R3, R14, R14, R14   # 0x2426
        C_CHWIDTH        R14, 0   # 0x242a
        CVT_SEXT         R14, R6, R6, R6   # 0x242c
        MAD_ACC          R5, R3, R14   # 0x2430
        C_BRA            L2354   # 0x2432
L2434:  C_CHWIDTH        R14, 0   # 0x2434
        MOVI             R1, 0   # 0x2436
        C_MOV            R10, R1   # 0x243a
        MOVI             R6, 0   # 0x243c
        ST_LOCAL         R1, 44   # 0x2440
        MOVI             R14, 0   # 0x2444
        LD_LOCAL         R11, 20   # 0x2448
        C_BRA            L246a   # 0x244c
L244e:  LD_LOCAL         R6, 36   # 0x244e
        C_ADD            R6, R5   # 0x2452
        LD_LOCAL         R3, 44   # 0x2454
        C_ADDI           R3, 1   # 0x2458
        ST_LOCAL         R3, 44   # 0x245a
        SETP_NE_NP       P0, R3, R3, R5   # 0x245e
        LD_LOCAL         R3, 40   # 0x2462
        BRA_PRED         4, L257c   # 0x2466
L246a:  ST_LOCAL         R6, 36   # 0x246a
        LD_LOCAL         R3, 24   # 0x246e
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2472
        BRA_PRED         0, L250e   # 0x2476
        MOVI             R13, 0   # 0x247a
        LD_LOCAL         R3, 16   # 0x247e
        LD_LOCAL         R3, 32   # 0x2482
        LD_LOCAL         R3, 36   # 0x2486
L248a:  CHWIDTH_MULTI    1056, 0   # 0x248a
        LD_LOCAL         R3, 36   # 0x248e
        C_ADD            R3, R13   # 0x2492
        C_SHLI           R3, 2   # 0x2494
        LD_LOCAL         R5, 16   # 0x2496
        C_ADD            R3, R5   # 0x249a
        LD_LOCAL         R6, 20   # 0x249c
        LD_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x24a0
        SETP_LT_NP       P0, R1, R1, R5   # 0x24a4
        C_MOV            R15, R10   # 0x24a8
        MOVI             R10, 0   # 0x24aa
        ADDI_P           R10, 0, R10, 1   # 0x24ae
        ADD              R14, R5, R14, R5   # 0x24b2
        LD_LOCAL         R4, 32   # 0x24b6
        SETP_LT_NP       P0, R1, R4, R14   # 0x24ba
        MOVI             R11, 10   # 0x24be
        MOV_P            R10, 0, R11, R11, R11   # 0x24c2
        MOVI             R1, 0   # 0x24c6
        MOV_P            R14, 0, R1, R1, R1   # 0x24ca
        ADDI             R1, R3, 4   # 0x24ce
        LD_GLOBAL_IDX    R1, R6, R1, 0, 0   # 0x24d2
        SETP_LT_NP       P0, R3, R5, R1   # 0x24d6
        MOVI             R3, 0   # 0x24da
        ADDI_P           R3, 0, R3, 1   # 0x24de
        ADD              R14, R1, R14, R1   # 0x24e2
        SETP_LT_NP       P0, R5, R4, R14   # 0x24e6
        C_CHWIDTH        R5, 1   # 0x24ea
        MOV_P            R3, 0, R11, R11, R11   # 0x24ec
        MOVI             R4, 0   # 0x24f0
        MOV_P            R14, 0, R4, R4, R4   # 0x24f4
        ADD              R5, R10, R15, R10   # 0x24f8
        C_CHWIDTH        R10, 1   # 0x24fc
        ADD              R10, R3, R5, R3   # 0x24fe
        C_ADDI           R13, 2   # 0x2502
        SETP_NE_NP       P0, R3, R12, R13   # 0x2504
        BRA_PRED         0, L248a   # 0x2508
        C_BRA            L2512   # 0x250c
L250e:  MOVI             R13, 0   # 0x250e
L2512:  C_CHWIDTH        R5, 0   # 0x2512
        LD_LOCAL         R11, 20   # 0x2514
        LD_LOCAL         R3, 28   # 0x2518
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x251c
        LD_LOCAL         R5, 12   # 0x2520
        MOVI             R15, 0   # 0x2524
        MOVI             R4, 10   # 0x2528
        BRA_PRED         0, L244e   # 0x252c
        C_CHWIDTH        R10, 0   # 0x2530
        LD_LOCAL         R3, 44   # 0x2532
        C_MUL_LO         R3, R5   # 0x2536
        ADD              R3, R13, R3, R13   # 0x2538
        C_SHLI           R3, 2   # 0x253c
        C_MOV            R6, R10   # 0x253e
        LD_LOCAL         R10, 16   # 0x2540
        ADD              R3, R10, R3, R10   # 0x2544
        C_MOV            R10, R6   # 0x2548
        C_CHWIDTH        R10, 1   # 0x254a
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x254c
        SETP_LT_NP       P0, R1, R1, R3   # 0x2550
        ADD              R14, R3, R14, R3   # 0x2554
        LD_LOCAL         R1, 32   # 0x2558
        SETP_LT_NP       P1, R1, R1, R14   # 0x255c
        MOV_P            R14, 1, R15, R15, R15   # 0x2560
        MOVI             R1, 0   # 0x2564
        ADDI_P           R1, 0, R1, 1   # 0x2568
        MOV_P            R1, 1, R4, R4, R4   # 0x256c
        ADD              R10, R1, R10, R1   # 0x2570
        C_MOV            R1, R3   # 0x2574
        BRA              L244e   # 0x2576
L257a:  C_MOV            R10, R1   # 0x257a
L257c:  C_CHWIDTH        R10, 0   # 0x257c
        MOVI             R6, 0   # 0x257e
        LD_LOCAL         R1, 12   # 0x2582
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x2586
        ST_LOCAL         R10, 68   # 0x258a
        BRA_PRED         0, L27d8   # 0x258e
        MOVI             R3, 0   # 0x2592
        LD_LOCAL         R15, 12   # 0x2596
        C_BRA            L25ac   # 0x259a
L259c:  C_ADD            R6, R15   # 0x259c
        LD_LOCAL         R3, 44   # 0x259e
        C_ADDI           R3, 1   # 0x25a2
        SETP_NE_NP       P0, R1, R3, R15   # 0x25a4
        BRA_PRED         4, L26b6   # 0x25a8
L25ac:  ST_LOCAL         R3, 44   # 0x25ac
        MUL_LO           R1, R3, R15, R15   # 0x25b0
        ST_LOCAL         R1, 36   # 0x25b4
        MOVI             R3, 0   # 0x25b8
        C_BRA            L25e6   # 0x25bc
L25be:  LD_LOCAL         R1, 36   # 0x25be
        ADD              R5, R3, R1, R3   # 0x25c2
        C_SHLI           R5, 2   # 0x25c6
        LD_LOCAL         R1, 16   # 0x25c8
        ADD              R5, R1, R5, R1   # 0x25cc
        LD_LOCAL         R11, 20   # 0x25d0
        ST_GLOBAL_IDX    R14, R11, R5, 0, 0   # 0x25d4
        C_ADDI           R3, 1   # 0x25d8
        LD_LOCAL         R15, 12   # 0x25da
        SETP_NE_NP       P0, R5, R3, R15   # 0x25de
        BRA_PRED         4, L259c   # 0x25e2
L25e6:  C_CHWIDTH        R14, 0   # 0x25e6
        LD_LOCAL         R5, 24   # 0x25e8
        SETP_EQ_NPI      P0, R5, R5, 0   # 0x25ec
        MOVI             R5, 0   # 0x25f0
        MOVI             R14, 0   # 0x25f4
        C_MOV            R1, R15   # 0x25f8
        BRA_PRED         0, L266c   # 0x25fa
        C_MOV            R13, R3   # 0x25fe
L2600:  C_CHWIDTH        R15, 1   # 0x2600
        ADD              R10, R6, R5, R6   # 0x2602
        C_SHLI           R10, 1   # 0x2606
        C_ADD            R10, R7   # 0x2608
        C_MOV            R11, R13   # 0x260a
        C_SHLI           R11, 1   # 0x260c
        ADD              R11, R9, R11, R9   # 0x260e
        LD_GLOBAL_IDX    R15, R8, R11, 0, 0   # 0x2612
        C_CHWIDTH        R15, 0   # 0x2616
        C_CHWIDTH        R11, 1   # 0x2618
        LD_GLOBAL_IDX    R11, R0, R10, 0, 0   # 0x261a
        C_CHWIDTH        R11, 0   # 0x261e
        C_MUL_LO         R15, R11   # 0x2620
        C_MOV            R11, R15   # 0x2622
        C_SHRI           R11, 5   # 0x2624
        ANDI             R11, R11, 127   # 0x2626
        C_SHRI           R15, 2   # 0x262a
        C_ANDI           R15, 15   # 0x262c
        MAD_ACC          R14, R15, R11   # 0x262e
        C_CHWIDTH        R11, 1   # 0x2630
        ADDI             R15, R10, 2   # 0x2632
        C_CHWIDTH        R10, 1   # 0x2636
        LD_GLOBAL_IDX    R10, R0, R15, 0, 0   # 0x2638
        C_CHWIDTH        R10, 0   # 0x263c
        ADD              R15, R1, R13, R1   # 0x263e
        C_SHLI           R15, 1   # 0x2642
        ADD              R15, R9, R15, R9   # 0x2644
        LD_GLOBAL_IDX    R11, R8, R15, 0, 0   # 0x2648
        C_CHWIDTH        R11, 0   # 0x264c
        MUL_LO           R15, R11, R10, R10   # 0x264e
        C_MOV            R10, R15   # 0x2652
        C_SHRI           R10, 5   # 0x2654
        ANDI             R10, R10, 127   # 0x2656
        C_SHRI           R15, 2   # 0x265a
        C_ANDI           R15, 15   # 0x265c
        MAD_ACC          R14, R15, R10   # 0x265e
        C_ADD            R13, R2   # 0x2660
        C_ADDI           R5, 2   # 0x2662
        SETP_NE_NP       P0, R15, R12, R5   # 0x2664
        BRA_PRED         0, L2600   # 0x2668
L266c:  LD_LOCAL         R1, 28   # 0x266c
        SETP_EQ_NPI      P0, R15, R1, 0   # 0x2670
        BRA_PRED         0, L25be   # 0x2674
        C_CHWIDTH        R10, 1   # 0x2678
        LD_LOCAL         R1, 12   # 0x267a
        MADLO            R15, R5, R1, R3   # 0x267e
        C_SHLI           R15, 1   # 0x2682
        ADD              R15, R9, R15, R9   # 0x2684
        LD_GLOBAL_IDX    R10, R8, R15, 0, 0   # 0x2688
        C_CHWIDTH        R10, 0   # 0x268c
        C_CHWIDTH        R15, 1   # 0x268e
        LD_LOCAL         R1, 36   # 0x2690
        C_ADD            R5, R1   # 0x2694
        C_SHLI           R5, 1   # 0x2696
        ADD              R5, R7, R5, R7   # 0x2698
        LD_GLOBAL_IDX    R15, R0, R5, 0, 0   # 0x269c
        C_CHWIDTH        R15, 0   # 0x26a0
        MUL_LO           R5, R10, R15, R15   # 0x26a2
        C_MOV            R15, R5   # 0x26a6
        C_SHRI           R15, 5   # 0x26a8
        ANDI             R15, R15, 127   # 0x26aa
        C_SHRI           R5, 2   # 0x26ae
        C_ANDI           R5, 15   # 0x26b0
        MAD_ACC          R14, R5, R15   # 0x26b2
        C_BRA            L25be   # 0x26b4
L26b6:  MOVI             R1, 0   # 0x26b6
        C_MOV            R8, R1   # 0x26ba
        MOVI             R5, 0   # 0x26bc
        ST_LOCAL         R1, 36   # 0x26c0
        MOVI             R13, 0   # 0x26c4
        LD_LOCAL         R10, 32   # 0x26c8
        C_BRA            L26e6   # 0x26cc
L26ce:  C_ADD            R5, R15   # 0x26ce
        LD_LOCAL         R2, 36   # 0x26d0
        C_ADDI           R2, 1   # 0x26d4
        ST_LOCAL         R2, 36   # 0x26d6
        SETP_NE_NP       P0, R3, R2, R15   # 0x26da
        LD_LOCAL         R9, 40   # 0x26de
        BRA_PRED         4, L27dc   # 0x26e2
L26e6:  LD_LOCAL         R3, 24   # 0x26e6
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x26ea
        BRA_PRED         0, L2776   # 0x26ee
        MOVI             R9, 0   # 0x26f2
        LD_LOCAL         R2, 16   # 0x26f6
L26fa:  C_CHWIDTH        R8, 1   # 0x26fa
        ADD              R3, R5, R9, R5   # 0x26fc
        C_SHLI           R3, 2   # 0x2700
        LD_LOCAL         R2, 16   # 0x2702
        C_ADD            R3, R2   # 0x2706
        C_MOV            R14, R5   # 0x2708
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x270a
        SETP_LT_NP       P0, R15, R13, R5   # 0x270e
        MOVI             R15, 0   # 0x2712
        ADDI_P           R15, 0, R15, 1   # 0x2716
        ADD              R1, R5, R1, R5   # 0x271a
        LD_LOCAL         R10, 32   # 0x271e
        SETP_LT_NP       P0, R10, R10, R1   # 0x2722
        LD_LOCAL         R10, 32   # 0x2726
        MOVI             R2, 10   # 0x272a
        MOV_P            R15, 0, R2, R2, R2   # 0x272e
        MOVI             R6, 0   # 0x2732
        MOV_P            R1, 0, R6, R6, R6   # 0x2736
        C_ADDI           R3, 4   # 0x273a
        LD_GLOBAL_IDX    R13, R11, R3, 0, 0   # 0x273c
        SETP_LT_NP       P0, R3, R5, R13   # 0x2740
        MOVI             R3, 0   # 0x2744
        ADDI_P           R3, 0, R3, 1   # 0x2748
        ADD              R1, R13, R1, R13   # 0x274c
        SETP_LT_NP       P0, R5, R10, R1   # 0x2750
        C_CHWIDTH        R5, 1   # 0x2754
        MOV_P            R3, 0, R2, R2, R2   # 0x2756
        MOV_P            R1, 0, R6, R6, R6   # 0x275a
        ADD              R5, R15, R8, R15   # 0x275e
        ADD              R8, R3, R5, R3   # 0x2762
        C_CHWIDTH        R5, 0   # 0x2766
        C_MOV            R5, R14   # 0x2768
        C_ADDI           R9, 2   # 0x276a
        SETP_NE_NP       P0, R3, R12, R9   # 0x276c
        BRA_PRED         0, L26fa   # 0x2770
        C_BRA            L277a   # 0x2774
L2776:  MOVI             R9, 0   # 0x2776
L277a:  MOVI             R6, 10   # 0x277a
        MOVI             R14, 0   # 0x277e
        LD_LOCAL         R2, 28   # 0x2782
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x2786
        LD_LOCAL         R15, 12   # 0x278a
        BRA_PRED         0, L26ce   # 0x278e
        C_CHWIDTH        R8, 1   # 0x2792
        LD_LOCAL         R2, 36   # 0x2794
        MUL_LO           R3, R2, R15, R15   # 0x2798
        ADD              R3, R9, R3, R9   # 0x279c
        C_SHLI           R3, 2   # 0x27a0
        LD_LOCAL         R2, 16   # 0x27a2
        ADD              R3, R2, R3, R2   # 0x27a6
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x27aa
        C_MOV            R2, R5   # 0x27ae
        SETP_LT_NP       P0, R5, R13, R3   # 0x27b0
        ADD              R1, R3, R1, R3   # 0x27b4
        SETP_LT_NP       P1, R5, R10, R1   # 0x27b8
        MOV_P            R1, 1, R14, R14, R14   # 0x27bc
        MOVI             R5, 0   # 0x27c0
        ADDI_P           R5, 0, R5, 1   # 0x27c4
        MOV_P            R5, 1, R6, R6, R6   # 0x27c8
        ADD              R8, R5, R8, R5   # 0x27cc
        C_MOV            R5, R2   # 0x27d0
        C_MOV            R13, R3   # 0x27d2
        BRA              L26ce   # 0x27d4
L27d8:  C_MOV            R8, R6   # 0x27d8
        C_MOV            R9, R3   # 0x27da
L27dc:  LD_LOCAL         R1, 56   # 0x27dc
        C_MOV            R5, R1   # 0x27e0
        C_CHWIDTH        R5, 1   # 0x27e2
        LD_LOCAL         R1, 12   # 0x27e4
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x27e8
        LD_LOCAL         R12, 52   # 0x27ec
        LD_LOCAL         R10, 68   # 0x27f0
        BRA_PRED         0, L28b6   # 0x27f4
        MOVI             R1, 0   # 0x27f8
        LD_LOCAL         R2, 12   # 0x27fc
        C_ANDI           R2, 3   # 0x2800
        MOVI             R6, 0   # 0x2802
        C_BRA            L2818   # 0x2806
L2808:  LD_LOCAL         R3, 12   # 0x2808
        C_ADD            R1, R3   # 0x280c
        C_ADDI           R6, 1   # 0x280e
        SETP_NE_NP       P0, R3, R6, R3   # 0x2810
        BRA_PRED         4, L28b6   # 0x2814
L2818:  LD_LOCAL         R3, 24   # 0x2818
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x281c
        MOVI             R3, 0   # 0x2820
        BRA_PRED         0, L2880   # 0x2824
L2828:  CHWIDTH_MULTI    40960, 1   # 0x2828
        C_CHWIDTH        R14, 0   # 0x282c
        ADD              R14, R1, R3, R1   # 0x282e
        C_SHLI           R14, 1   # 0x2832
        ADD              R14, R7, R14, R7   # 0x2834
        LD_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x2838
        SUB              R15, R15, R12, R15   # 0x283c
        ST_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x2840
        C_CHWIDTH        R15, 0   # 0x2844
        ADDI             R15, R14, 2   # 0x2846
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x284a
        SUB              R13, R13, R12, R13   # 0x284e
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x2852
        ADDI             R15, R14, 4   # 0x2856
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x285a
        SUB              R13, R13, R12, R13   # 0x285e
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x2862
        C_CHWIDTH        R15, 1   # 0x2866
        C_ADDI           R14, 6   # 0x2868
        LD_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x286a
        SUB              R15, R15, R12, R15   # 0x286e
        ST_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x2872
        C_ADDI           R3, 4   # 0x2876
        SETP_NE_NP       P0, R14, R9, R3   # 0x2878
        BRA_PRED         0, L2828   # 0x287c
L2880:  SETP_EQ_NPI      P0, R14, R2, 0   # 0x2880
        BRA_PRED         0, L2808   # 0x2884
        C_CHWIDTH        R14, 0   # 0x2888
        C_ADD            R3, R1   # 0x288a
        C_MOV            R14, R2   # 0x288c
L288e:  C_CHWIDTH        R13, 1   # 0x288e
        C_CHWIDTH        R15, 0   # 0x2890
        C_MOV            R15, R3   # 0x2892
        C_SHLI           R15, 1   # 0x2894
        ADD              R15, R7, R15, R7   # 0x2896
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x289a
        SUB              R13, R13, R12, R13   # 0x289e
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x28a2
        C_ADDI           R3, 1   # 0x28a6
        ADDI             R14, R14, -1   # 0x28a8
        SETP_NE_NPI      P0, R15, R14, 0   # 0x28ac
        BRA_PRED         0, L288e   # 0x28b0
        C_BRA            L2808   # 0x28b4
L28b6:  CHWIDTH_MULTI    57632, 0   # 0x28b6
        LD_LOCAL         R1, 60   # 0x28ba
        MOVI             R2, 0   # 0x28be
        CALL             R14, 129297   # 0x28c2
        C_MOV            R2, R1   # 0x28c6
        LD_LOCAL         R1, 64   # 0x28c8
        CALL             R14, 129292   # 0x28cc
        C_MOV            R2, R1   # 0x28d0
        C_MOV            R1, R10   # 0x28d2
        CALL             R14, 129288   # 0x28d4
        C_MOV            R2, R1   # 0x28d8
        C_MOV            R1, R8   # 0x28da
        CALL             R14, 129284   # 0x28dc
        C_MOV            R2, R5   # 0x28e0
        CALL             R14, 129281   # 0x28e2
        LD_LOCAL         R14, 48   # 0x28e6
        LD_LOCAL         R13, 92   # 0x28ea
        LD_LOCAL         R12, 88   # 0x28ee
        LD_LOCAL         R11, 84   # 0x28f2
        LD_LOCAL         R10, 80   # 0x28f6
        LD_LOCAL         R9, 76   # 0x28fa
        LD_LOCAL         R8, 72   # 0x28fe
        C_RET            224   # 0x2902
        CHWIDTH_MULTI    7, 1   # 0x2904
        XOR              R0, R2, R1, R2   # 0x2908
        CHWIDTH_MULTI    7, 0   # 0x290c
        C_ANDI           R0, 1   # 0x2910
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2912
        MOVI             R0, 40961   # 0x2916
        C_MOV            R7, R0   # 0x291a
        SHRI             R0, R2, 1   # 0x291c
        C_CHWIDTH        R2, 1   # 0x2920
        XOR              R2, R0, R7, R0   # 0x2922
        C_CHWIDTH        R2, 0   # 0x2926
        MOV_P            R0, 0, R2, R2, R2   # 0x2928
        C_CHWIDTH        R0, 1   # 0x292c
        SHRI             R2, R1, 1   # 0x292e
        C_CHWIDTH        R2, 1   # 0x2932
        XOR              R2, R2, R0, R2   # 0x2934
        CHWIDTH_MULTI    5, 0   # 0x2938
        C_ANDI           R2, 1   # 0x293c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x293e
        C_CHWIDTH        R2, 1   # 0x2942
        SHRI             R0, R0, 1   # 0x2944
        XOR              R2, R0, R7, R0   # 0x2948
        C_CHWIDTH        R2, 0   # 0x294c
        MOV_P            R0, 0, R2, R2, R2   # 0x294e
        C_CHWIDTH        R0, 1   # 0x2952
        SHRI             R2, R1, 2   # 0x2954
        C_CHWIDTH        R2, 1   # 0x2958
        XOR              R2, R2, R0, R2   # 0x295a
        CHWIDTH_MULTI    5, 0   # 0x295e
        C_ANDI           R2, 1   # 0x2962
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2964
        C_CHWIDTH        R2, 1   # 0x2968
        SHRI             R0, R0, 1   # 0x296a
        XOR              R2, R0, R7, R0   # 0x296e
        C_CHWIDTH        R2, 0   # 0x2972
        MOV_P            R0, 0, R2, R2, R2   # 0x2974
        C_CHWIDTH        R0, 1   # 0x2978
        SHRI             R2, R1, 3   # 0x297a
        C_CHWIDTH        R2, 1   # 0x297e
        XOR              R2, R2, R0, R2   # 0x2980
        CHWIDTH_MULTI    5, 0   # 0x2984
        C_ANDI           R2, 1   # 0x2988
        SETP_NE_NPI      P0, R2, R2, 0   # 0x298a
        C_CHWIDTH        R2, 1   # 0x298e
        SHRI             R0, R0, 1   # 0x2990
        XOR              R2, R0, R7, R0   # 0x2994
        C_CHWIDTH        R2, 0   # 0x2998
        MOV_P            R0, 0, R2, R2, R2   # 0x299a
        C_CHWIDTH        R0, 1   # 0x299e
        SHRI             R2, R1, 4   # 0x29a0
        C_CHWIDTH        R2, 1   # 0x29a4
        XOR              R2, R2, R0, R2   # 0x29a6
        CHWIDTH_MULTI    5, 0   # 0x29aa
        C_ANDI           R2, 1   # 0x29ae
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29b0
        C_CHWIDTH        R2, 1   # 0x29b4
        SHRI             R0, R0, 1   # 0x29b6
        XOR              R2, R0, R7, R0   # 0x29ba
        C_CHWIDTH        R2, 0   # 0x29be
        MOV_P            R0, 0, R2, R2, R2   # 0x29c0
        C_CHWIDTH        R0, 1   # 0x29c4
        SHRI             R2, R1, 5   # 0x29c6
        C_CHWIDTH        R2, 1   # 0x29ca
        XOR              R2, R2, R0, R2   # 0x29cc
        CHWIDTH_MULTI    5, 0   # 0x29d0
        C_ANDI           R2, 1   # 0x29d4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29d6
        C_CHWIDTH        R2, 1   # 0x29da
        SHRI             R0, R0, 1   # 0x29dc
        XOR              R2, R0, R7, R0   # 0x29e0
        C_CHWIDTH        R2, 0   # 0x29e4
        MOV_P            R0, 0, R2, R2, R2   # 0x29e6
        C_CHWIDTH        R0, 1   # 0x29ea
        SHRI             R2, R1, 6   # 0x29ec
        C_CHWIDTH        R2, 1   # 0x29f0
        XOR              R2, R2, R0, R2   # 0x29f2
        CHWIDTH_MULTI    5, 0   # 0x29f6
        C_ANDI           R2, 1   # 0x29fa
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29fc
        C_CHWIDTH        R2, 1   # 0x2a00
        SHRI             R0, R0, 1   # 0x2a02
        XOR              R2, R0, R7, R0   # 0x2a06
        C_CHWIDTH        R2, 0   # 0x2a0a
        MOV_P            R0, 0, R2, R2, R2   # 0x2a0c
        MOVI             R2, 128   # 0x2a10
        C_CHWIDTH        R2, 1   # 0x2a14
        AND              R2, R1, R2, R1   # 0x2a16
        C_CHWIDTH        R2, 0   # 0x2a1a
        SHRI             R2, R2, 7   # 0x2a1c
        ANDI             R3, R0, 1   # 0x2a20
        C_CHWIDTH        R0, 1   # 0x2a24
        C_CHWIDTH        R0, 0   # 0x2a26
        SETP_EQ_NP       P0, R2, R2, R3   # 0x2a28
        C_CHWIDTH        R2, 1   # 0x2a2c
        SHRI             R0, R0, 1   # 0x2a2e
        XOR              R2, R0, R7, R0   # 0x2a32
        C_CHWIDTH        R2, 0   # 0x2a36
        MOV_P            R2, 0, R0, R0, R0   # 0x2a38
        C_CHWIDTH        R2, 1   # 0x2a3c
        SHRI             R0, R1, 8   # 0x2a3e
        C_CHWIDTH        R0, 1   # 0x2a42
        XOR              R0, R2, R0, R2   # 0x2a44
        CHWIDTH_MULTI    5, 0   # 0x2a48
        C_ANDI           R0, 1   # 0x2a4c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2a4e
        SHRI             R0, R2, 1   # 0x2a52
        C_CHWIDTH        R2, 1   # 0x2a56
        XOR              R2, R0, R7, R0   # 0x2a58
        C_CHWIDTH        R2, 0   # 0x2a5c
        MOV_P            R0, 0, R2, R2, R2   # 0x2a5e
        C_CHWIDTH        R0, 1   # 0x2a62
        SHRI             R2, R1, 9   # 0x2a64
        C_CHWIDTH        R2, 1   # 0x2a68
        XOR              R2, R2, R0, R2   # 0x2a6a
        CHWIDTH_MULTI    5, 0   # 0x2a6e
        C_ANDI           R2, 1   # 0x2a72
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a74
        C_CHWIDTH        R2, 1   # 0x2a78
        SHRI             R0, R0, 1   # 0x2a7a
        XOR              R2, R0, R7, R0   # 0x2a7e
        C_CHWIDTH        R2, 0   # 0x2a82
        MOV_P            R0, 0, R2, R2, R2   # 0x2a84
        C_CHWIDTH        R0, 1   # 0x2a88
        SHRI             R2, R1, 10   # 0x2a8a
        C_CHWIDTH        R2, 1   # 0x2a8e
        XOR              R2, R2, R0, R2   # 0x2a90
        CHWIDTH_MULTI    5, 0   # 0x2a94
        C_ANDI           R2, 1   # 0x2a98
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a9a
        C_CHWIDTH        R2, 1   # 0x2a9e
        SHRI             R0, R0, 1   # 0x2aa0
        XOR              R2, R0, R7, R0   # 0x2aa4
        C_CHWIDTH        R2, 0   # 0x2aa8
        MOV_P            R0, 0, R2, R2, R2   # 0x2aaa
        C_CHWIDTH        R0, 1   # 0x2aae
        SHRI             R2, R1, 11   # 0x2ab0
        C_CHWIDTH        R2, 1   # 0x2ab4
        XOR              R2, R2, R0, R2   # 0x2ab6
        CHWIDTH_MULTI    5, 0   # 0x2aba
        C_ANDI           R2, 1   # 0x2abe
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2ac0
        C_CHWIDTH        R2, 1   # 0x2ac4
        SHRI             R0, R0, 1   # 0x2ac6
        XOR              R2, R0, R7, R0   # 0x2aca
        C_CHWIDTH        R2, 0   # 0x2ace
        MOV_P            R0, 0, R2, R2, R2   # 0x2ad0
        C_CHWIDTH        R0, 1   # 0x2ad4
        SHRI             R2, R1, 12   # 0x2ad6
        C_CHWIDTH        R2, 1   # 0x2ada
        XOR              R2, R2, R0, R2   # 0x2adc
        CHWIDTH_MULTI    5, 0   # 0x2ae0
        C_ANDI           R2, 1   # 0x2ae4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2ae6
        C_CHWIDTH        R2, 1   # 0x2aea
        SHRI             R0, R0, 1   # 0x2aec
        XOR              R2, R0, R7, R0   # 0x2af0
        C_CHWIDTH        R2, 0   # 0x2af4
        MOV_P            R0, 0, R2, R2, R2   # 0x2af6
        C_CHWIDTH        R0, 1   # 0x2afa
        SHRI             R2, R1, 13   # 0x2afc
        C_CHWIDTH        R2, 1   # 0x2b00
        XOR              R2, R2, R0, R2   # 0x2b02
        CHWIDTH_MULTI    5, 0   # 0x2b06
        C_ANDI           R2, 1   # 0x2b0a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2b0c
        C_CHWIDTH        R2, 1   # 0x2b10
        SHRI             R0, R0, 1   # 0x2b12
        XOR              R2, R0, R7, R0   # 0x2b16
        C_CHWIDTH        R2, 0   # 0x2b1a
        MOV_P            R0, 0, R2, R2, R2   # 0x2b1c
        C_CHWIDTH        R0, 1   # 0x2b20
        SHRI             R2, R1, 14   # 0x2b22
        C_CHWIDTH        R2, 1   # 0x2b26
        XOR              R2, R2, R0, R2   # 0x2b28
        CHWIDTH_MULTI    5, 0   # 0x2b2c
        C_ANDI           R2, 1   # 0x2b30
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2b32
        C_CHWIDTH        R2, 1   # 0x2b36
        SHRI             R0, R0, 1   # 0x2b38
        XOR              R2, R0, R7, R0   # 0x2b3c
        C_CHWIDTH        R2, 0   # 0x2b40
        MOV_P            R0, 0, R2, R2, R2   # 0x2b42
        SHRI             R1, R1, 15   # 0x2b46
        ANDI             R2, R0, 1   # 0x2b4a
        C_CHWIDTH        R0, 1   # 0x2b4e
        C_CHWIDTH        R0, 0   # 0x2b50
        SETP_EQ_NP       P0, R1, R1, R2   # 0x2b52
        C_CHWIDTH        R1, 1   # 0x2b56
        SHRI             R0, R0, 1   # 0x2b58
        XOR              R1, R0, R7, R0   # 0x2b5c
        C_CHWIDTH        R1, 0   # 0x2b60
        MOV_P            R1, 0, R0, R0, R0   # 0x2b62
        MOVI             R0, 65535   # 0x2b66
        C_AND            R1, R0   # 0x2b6a
        C_RET            224   # 0x2b6c
        MOVI             R15, 2   # 0x2b6e
        LD_GLOBAL        R15, R15, 24   # 0x2b72
        SRD              R0, 2   # 0x2b76
        C_ADD            R15, R0   # 0x2b78
        ST_LOCAL         R8, 196   # 0x2b7a
        C_CHWIDTH        R8, 1   # 0x2b7e
        ST_LOCAL         R9, 200   # 0x2b80
        ST_LOCAL         R10, 204   # 0x2b84
        ST_LOCAL         R11, 208   # 0x2b88
        ST_LOCAL         R12, 212   # 0x2b8c
        ST_LOCAL         R13, 216   # 0x2b90
        ST_LOCAL         R14, 184   # 0x2b94
        ST_LOCAL         R2, 120   # 0x2b98
        LD_GLOBAL_IDX    R0, R1, R2, 0, 60   # 0x2b9c
        SHLI             R0, R0, 16   # 0x2ba0
        LD_GLOBAL_IDX    R5, R1, R2, 0, 56   # 0x2ba4
        SHRI             R4, R5, 16   # 0x2ba8
        OR               R6, R0, R4, R0   # 0x2bac
        MOVI             R0, 65535   # 0x2bb0
        AND              R7, R5, R0, R5   # 0x2bb4
        ST_LOCAL         R1, 104   # 0x2bb8
        LD_GLOBAL_IDX    R8, R1, R2, 0, 4   # 0x2bbc
        MOVI             R2, 0   # 0x2bc0
        C_MOV            R14, R3   # 0x2bc4
        C_CHWIDTH        R14, 1   # 0x2bc6
        CVT_SEXT         R3, R8, R8, R8   # 0x2bc8
        SETP_LT_NPI      P0, R3, R3, 1   # 0x2bcc
        BRA_PRED         0, L2f26   # 0x2bd0
        C_CHWIDTH        R14, 0   # 0x2bd4
        C_MOV            R12, R7   # 0x2bd6
        C_CHWIDTH        R7, 1   # 0x2bd8
        C_MOV            R1, R6   # 0x2bda
        ADDI             R7, R8, 255   # 0x2bdc
        CHWIDTH_MULTI    384, 0   # 0x2be0
        ST_LOCAL         R7, 128   # 0x2be4
        MOVI             R4, 1   # 0x2be8
        C_MOV            R7, R4   # 0x2bec
        ST_LOCAL         R7, 108   # 0x2bee
        MOVI             R4, 255   # 0x2bf2
        C_MOV            R6, R2   # 0x2bf6
        ST_LOCAL         R2, 96   # 0x2bf8
        ST_LOCAL         R2, 116   # 0x2bfc
        ST_LOCAL         R14, 124   # 0x2c00
        C_MOV            R5, R14   # 0x2c04
        C_CHWIDTH        R5, 1   # 0x2c06
        ST_LOCAL         R8, 100   # 0x2c08
        ST_LOCAL         R4, 112   # 0x2c0c
        C_BRA            L2c94   # 0x2c10
L2c12:  C_CHWIDTH        R11, 1   # 0x2c12
        C_MOV            R7, R1   # 0x2c14
        C_MOV            R4, R12   # 0x2c16
        LD_GLOBAL_IDX    R3, R7, R4, 0, 0   # 0x2c18
        LD_GLOBAL_IDX    R7, R7, R4, 0, 4   # 0x2c1c
        SHLI             R7, R7, 16   # 0x2c20
        SHRI             R14, R3, 16   # 0x2c24
        C_OR             R7, R14   # 0x2c28
        C_AND            R3, R0   # 0x2c2a
        LD_GLOBAL_IDX    R14, R7, R3, 0, 8   # 0x2c2c
        LD_GLOBAL_IDX    R3, R7, R3, 0, 12   # 0x2c30
        SHLI             R3, R3, 16   # 0x2c34
        SHRI             R7, R14, 16   # 0x2c38
        C_OR             R3, R7   # 0x2c3c
        AND              R7, R14, R0, R14   # 0x2c3e
        C_CHWIDTH        R14, 1   # 0x2c42
        LD_GLOBAL_IDX    R14, R3, R7, 0, 0   # 0x2c44
        C_CHWIDTH        R14, 0   # 0x2c48
        SHRI             R3, R14, 8   # 0x2c4a
        LD_LOCAL         R14, 108   # 0x2c4e
        AND              R11, R3, R14, R3   # 0x2c52
        LD_LOCAL         R14, 116   # 0x2c56
        C_CHWIDTH        R14, 1   # 0x2c5a
        ADDI             R14, R14, 1   # 0x2c5c
        C_CHWIDTH        R14, 0   # 0x2c60
        ST_LOCAL         R14, 116   # 0x2c62
L2c66:  CHWIDTH_MULTI    108, 1   # 0x2c66
        ADD              R6, R11, R6, R11   # 0x2c6a
        C_MOV            R14, R0   # 0x2c6e
        XOR              R3, R5, R14, R5   # 0x2c70
        C_CHWIDTH        R3, 0   # 0x2c74
        SHRI             R3, R3, 15   # 0x2c76
        ADD              R5, R5, R3, R5   # 0x2c7a
        ADDI             R2, R2, 1   # 0x2c7e
        C_CHWIDTH        R2, 0   # 0x2c82
        LD_LOCAL         R8, 100   # 0x2c84
        SETP_NE_NP       P0, R3, R2, R8   # 0x2c88
        LD_LOCAL         R4, 112   # 0x2c8c
        BRA_PRED         4, L2eee   # 0x2c90
L2c94:  C_CHWIDTH        R11, 0   # 0x2c94
        C_MOV            R11, R1   # 0x2c96
        SHLI             R7, R11, 16   # 0x2c98
        C_MOV            R9, R12   # 0x2c9c
        AND              R14, R7, R9, R7   # 0x2c9e
        ADD              R8, R7, R9, R7   # 0x2ca2
        C_OR             R7, R9   # 0x2ca6
        C_ANDN           R7, R8   # 0x2ca8
        OR               R7, R14, R7, R14   # 0x2caa
        SHRI             R7, R7, 31   # 0x2cae
        SHRI             R14, R11, 16   # 0x2cb2
        ADD              R7, R14, R7, R14   # 0x2cb6
        OR               R10, R8, R7, R8   # 0x2cba
        CVT_SEXT         R7, R5, R5, R5   # 0x2cbe
        MOVI48           R3, 4294967295   # 0x2cc2
        SETP_LT_NP       P0, R7, R3, R7   # 0x2cc8
        BRA_PRED         4, L2d30   # 0x2ccc
        MOVI             R8, 0   # 0x2cd0
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2cd4
        BRA_PRED         0, L2d92   # 0x2cd8
        C_CHWIDTH        R5, 0   # 0x2cdc
        C_MOV            R11, R1   # 0x2cde
        C_MOV            R9, R12   # 0x2ce0
L2ce2:  LD_GLOBAL_IDX    R7, R11, R9, 0, 8   # 0x2ce2
        LD_GLOBAL_IDX    R14, R11, R9, 0, 12   # 0x2ce6
        SHLI             R14, R14, 16   # 0x2cea
        SHRI             R3, R7, 16   # 0x2cee
        OR               R3, R14, R3, R14   # 0x2cf2
        C_CHWIDTH        R14, 1   # 0x2cf6
        C_AND            R7, R0   # 0x2cf8
        LD_GLOBAL_IDX    R14, R3, R7, 0, 2   # 0x2cfa
        C_CHWIDTH        R14, 0   # 0x2cfe
        SETP_EQ_NP       P0, R3, R14, R5   # 0x2d00
        BRA_PRED         0, L2e00   # 0x2d04
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2d08
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2d0c
        SHRI             R14, R7, 16   # 0x2d10
        SHLI             R9, R3, 16   # 0x2d14
        OR               R11, R9, R14, R9   # 0x2d18
        C_AND            R3, R0   # 0x2d1c
        OR               R3, R7, R3, R7   # 0x2d1e
        AND              R9, R7, R0, R7   # 0x2d22
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2d26
        BRA_PRED         4, L2ce2   # 0x2d2a
        C_BRA            L2d92   # 0x2d2e
L2d30:  MOVI             R8, 0   # 0x2d30
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2d34
        BRA_PRED         0, L2d92   # 0x2d38
L2d3c:  LD_GLOBAL_IDX    R3, R11, R9, 0, 8   # 0x2d3c
        LD_GLOBAL_IDX    R7, R11, R9, 0, 12   # 0x2d40
        SHLI             R7, R7, 16   # 0x2d44
        SHRI             R14, R3, 16   # 0x2d48
        C_OR             R7, R14   # 0x2d4c
        C_CHWIDTH        R14, 1   # 0x2d4e
        C_AND            R3, R0   # 0x2d50
        LD_GLOBAL_IDX    R14, R7, R3, 0, 0   # 0x2d52
        C_CHWIDTH        R3, 1   # 0x2d56
        XOR              R14, R14, R2, R14   # 0x2d58
        AND              R3, R14, R4, R14   # 0x2d5c
        C_CHWIDTH        R3, 0   # 0x2d60
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2d62
        BRA_PRED         0, L2e00   # 0x2d66
        C_CHWIDTH        R14, 0   # 0x2d6a
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2d6c
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2d70
        SHRI             R14, R7, 16   # 0x2d74
        SHLI             R9, R3, 16   # 0x2d78
        OR               R11, R9, R14, R9   # 0x2d7c
        C_AND            R3, R0   # 0x2d80
        OR               R3, R7, R3, R7   # 0x2d82
        AND              R9, R7, R0, R7   # 0x2d86
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d8a
        BRA_PRED         0, L2d3c   # 0x2d8e
L2d92:  MOVI             R9, 0   # 0x2d92
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2d96
        BRA_PRED         0, L2e0c   # 0x2d9a
L2d9e:  MOVI             R10, 0   # 0x2d9e
        MOVI             R14, 0   # 0x2da2
L2da6:  C_MOV            R4, R12   # 0x2da6
        C_MOV            R11, R1   # 0x2da8
        SHLI             R3, R10, 16   # 0x2daa
        AND              R7, R3, R14, R3   # 0x2dae
        ADD              R1, R3, R14, R3   # 0x2db2
        C_OR             R3, R14   # 0x2db6
        C_ANDN           R3, R1   # 0x2db8
        OR               R3, R7, R3, R7   # 0x2dba
        SHRI             R3, R3, 31   # 0x2dbe
        SHRI             R7, R10, 16   # 0x2dc2
        ADD              R3, R7, R3, R7   # 0x2dc6
        LD_GLOBAL_IDX    R7, R11, R4, 0, 0   # 0x2dca
        ST_GLOBAL_IDX    R1, R11, R4, 0, 0   # 0x2dce
        LD_GLOBAL_IDX    R14, R11, R4, 0, 4   # 0x2dd2
        ST_GLOBAL_IDX    R3, R11, R4, 0, 4   # 0x2dd6
        SHRI             R3, R7, 16   # 0x2dda
        SHLI             R10, R14, 16   # 0x2dde
        OR               R1, R10, R3, R10   # 0x2de2
        AND              R3, R14, R0, R14   # 0x2de6
        OR               R3, R7, R3, R7   # 0x2dea
        AND              R12, R7, R0, R7   # 0x2dee
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2df2
        C_MOV            R10, R11   # 0x2df6
        C_MOV            R14, R4   # 0x2df8
        BRA_PRED         0, L2da6   # 0x2dfa
        C_BRA            L2e14   # 0x2dfe
L2e00:  C_CHWIDTH        R14, 0   # 0x2e00
        C_MOV            R8, R11   # 0x2e02
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2e04
        BRA_PRED         4, L2d9e   # 0x2e08
L2e0c:  MOVI             R11, 0   # 0x2e0c
        MOVI             R4, 0   # 0x2e10
L2e14:  C_MOV            R12, R4   # 0x2e14
        C_MOV            R1, R11   # 0x2e16
        SHLI             R3, R8, 16   # 0x2e18
        AND              R7, R3, R9, R3   # 0x2e1c
        ADD              R14, R3, R9, R3   # 0x2e20
        C_OR             R3, R9   # 0x2e24
        C_ANDN           R3, R14   # 0x2e26
        OR               R3, R7, R3, R7   # 0x2e28
        SHRI             R3, R3, 31   # 0x2e2c
        SHRI             R7, R8, 16   # 0x2e30
        ADD              R3, R7, R3, R7   # 0x2e34
        OR               R3, R14, R3, R14   # 0x2e38
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2e3c
        BRA_PRED         4, L2c12   # 0x2e40
        CHWIDTH_MULTI    3072, 1   # 0x2e44
        LD_GLOBAL_IDX    R3, R8, R9, 0, 12   # 0x2e48
        SHLI             R3, R3, 16   # 0x2e4c
        LD_GLOBAL_IDX    R7, R8, R9, 0, 8   # 0x2e50
        SHRI             R14, R7, 16   # 0x2e54
        C_OR             R3, R14   # 0x2e58
        C_AND            R7, R0   # 0x2e5a
        LD_GLOBAL_IDX    R10, R3, R7, 0, 0   # 0x2e5c
        C_CHWIDTH        R10, 0   # 0x2e60
        LD_GLOBAL_IDX    R14, R8, R9, 0, 4   # 0x2e62
        LD_GLOBAL_IDX    R7, R8, R9, 0, 0   # 0x2e66
        SHRI             R3, R10, 9   # 0x2e6a
        C_CHWIDTH        R3, 1   # 0x2e6e
        AND              R3, R10, R3, R10   # 0x2e70
        AND              R10, R14, R0, R14   # 0x2e74
        OR               R10, R7, R10, R7   # 0x2e78
        LD_LOCAL         R4, 108   # 0x2e7c
        AND              R11, R3, R4, R3   # 0x2e80
        C_CHWIDTH        R3, 0   # 0x2e84
        LD_LOCAL         R3, 96   # 0x2e86
        C_CHWIDTH        R3, 1   # 0x2e8a
        ADDI             R3, R3, 1   # 0x2e8c
        C_CHWIDTH        R3, 0   # 0x2e90
        ST_LOCAL         R3, 96   # 0x2e92
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2e96
        BRA_PRED         0, L2c66   # 0x2e9a
        SHRI             R3, R7, 16   # 0x2e9e
        SHLI             R14, R14, 16   # 0x2ea2
        OR               R3, R14, R3, R14   # 0x2ea6
        C_CHWIDTH        R14, 1   # 0x2eaa
        C_AND            R7, R0   # 0x2eac
        LD_GLOBAL_IDX    R14, R3, R7, 0, 4   # 0x2eae
        C_CHWIDTH        R14, 0   # 0x2eb2
        LD_GLOBAL_IDX    R10, R3, R7, 0, 0   # 0x2eb4
        ST_GLOBAL_IDX    R10, R8, R9, 0, 0   # 0x2eb8
        ST_GLOBAL_IDX    R14, R8, R9, 0, 4   # 0x2ebc
        C_CHWIDTH        R14, 1   # 0x2ec0
        C_MOV            R9, R1   # 0x2ec2
        C_MOV            R4, R12   # 0x2ec4
        LD_GLOBAL_IDX    R14, R9, R4, 0, 4   # 0x2ec6
        C_CHWIDTH        R14, 0   # 0x2eca
        LD_GLOBAL_IDX    R8, R9, R4, 0, 0   # 0x2ecc
        ST_GLOBAL_IDX    R8, R3, R7, 0, 0   # 0x2ed0
        ST_GLOBAL_IDX    R14, R3, R7, 0, 4   # 0x2ed4
        SHRI             R14, R3, 16   # 0x2ed8
        ST_GLOBAL_IDX    R14, R9, R4, 0, 4   # 0x2edc
        SHLI             R3, R3, 16   # 0x2ee0
        C_OR             R3, R7   # 0x2ee4
        ST_GLOBAL_IDX    R3, R9, R4, 0, 0   # 0x2ee6
        BRA              L2c66   # 0x2eea
L2eee:  C_CHWIDTH        R5, 0   # 0x2eee
        C_CHWIDTH        R2, 1   # 0x2ef0
        MOVI             R0, 255   # 0x2ef2
        LD_LOCAL         R14, 128   # 0x2ef6
        AND              R2, R14, R0, R14   # 0x2efa
        C_CHWIDTH        R2, 0   # 0x2efe
        LD_LOCAL         R0, 96   # 0x2f00
        SHLI             R0, R0, 2   # 0x2f04
        LD_LOCAL         R14, 116   # 0x2f08
        C_CHWIDTH        R14, 1   # 0x2f0c
        SUB              R14, R0, R14, R0   # 0x2f0e
        C_CHWIDTH        R0, 1   # 0x2f12
        ADD              R0, R14, R6, R14   # 0x2f14
        CHWIDTH_MULTI    16449, 0   # 0x2f18
        C_MOV            R6, R1   # 0x2f1c
        C_MOV            R7, R12   # 0x2f1e
        LD_LOCAL         R14, 124   # 0x2f20
        C_BRA            L2f2c   # 0x2f24
L2f26:  C_CHWIDTH        R14, 0   # 0x2f26
        C_MOV            R5, R14   # 0x2f28
        C_MOV            R0, R2   # 0x2f2a
L2f2c:  C_CHWIDTH        R14, 1   # 0x2f2c
        ST_LOCAL         R5, 188   # 0x2f2e
        ST_LOCAL         R0, 180   # 0x2f32
        CVT_SEXT         R0, R14, R14, R14   # 0x2f36
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2f3a
        ST_LOCAL         R2, 192   # 0x2f3e
        BRA_PRED         0, L35a6   # 0x2f42
        CHWIDTH_MULTI    18432, 0   # 0x2f46
        MOVI             R0, 1   # 0x2f4a
        ST_LOCAL         R0, 168   # 0x2f4e
        MOVI             R12, 65535   # 0x2f52
        MOVI             R0, 128   # 0x2f56
        C_MOV            R14, R0   # 0x2f5a
        ST_LOCAL         R14, 108   # 0x2f5c
        MOVI             R0, 7   # 0x2f60
        C_MOV            R14, R0   # 0x2f64
        ST_LOCAL         R14, 128   # 0x2f66
        MOVI             R0, 15   # 0x2f6a
        C_MOV            R14, R0   # 0x2f6e
        ST_LOCAL         R14, 132   # 0x2f70
        MOVI             R0, 127   # 0x2f74
        C_MOV            R14, R0   # 0x2f78
        ST_LOCAL         R14, 112   # 0x2f7a
        MOVI             R0, 65280   # 0x2f7e
        C_MOV            R14, R0   # 0x2f82
        ST_LOCAL         R14, 136   # 0x2f84
        C_BRA            L2fb8   # 0x2f88
L2f8a:  MOVI             R0, 0   # 0x2f8a
        ST_GLOBAL_IDX    R0, R10, R11, 0, 4   # 0x2f8e
        ST_GLOBAL_IDX    R0, R10, R11, 0, 0   # 0x2f92
        LD_LOCAL         R0, 168   # 0x2f96
        C_SHLI           R0, 1   # 0x2f9a
        ST_LOCAL         R0, 168   # 0x2f9c
        LD_LOCAL         R0, 176   # 0x2fa0
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2fa4
        LD_LOCAL         R8, 164   # 0x2fa8
        C_MOV            R6, R8   # 0x2fac
        LD_LOCAL         R9, 160   # 0x2fae
        C_MOV            R7, R9   # 0x2fb2
        BRA_PRED         4, L35ac   # 0x2fb4
L2fb8:  MOVI             R5, 0   # 0x2fb8
        MOVI             R10, 0   # 0x2fbc
        MOVI             R11, 0   # 0x2fc0
        MOVI             R0, 0   # 0x2fc4
        ST_LOCAL         R0, 164   # 0x2fc8
        ST_LOCAL         R0, 160   # 0x2fcc
        C_BRA            L2fe0   # 0x2fd0
L2fd2:  C_CHWIDTH        R8, 0   # 0x2fd2
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2fd4
        LD_LOCAL         R5, 172   # 0x2fd8
        BRA_PRED         0, L2f8a   # 0x2fdc
L2fe0:  LD_LOCAL         R4, 168   # 0x2fe0
        SETP_LT_NPI      P0, R0, R4, 1   # 0x2fe4
        BRA_PRED         0, L3026   # 0x2fe8
        MOVI             R2, 0   # 0x2fec
        C_MOV            R0, R6   # 0x2ff0
        C_MOV            R1, R7   # 0x2ff2
L2ff4:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x2ff4
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x2ff8
        AND              R0, R3, R12, R3   # 0x2ffc
        OR               R0, R1, R0, R1   # 0x3000
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3004
        BRA_PRED         4, L3030   # 0x3008
        SHRI             R0, R1, 16   # 0x300c
        SHLI             R3, R3, 16   # 0x3010
        OR               R0, R3, R0, R3   # 0x3014
        C_AND            R1, R12   # 0x3018
        C_ADDI           R2, 1   # 0x301a
        SETP_EQ_NP       P0, R3, R4, R2   # 0x301c
        BRA_PRED         4, L2ff4   # 0x3020
        C_BRA            L303c   # 0x3024
L3026:  MOVI             R4, 0   # 0x3026
        C_MOV            R0, R6   # 0x302a
        C_MOV            R1, R7   # 0x302c
        C_BRA            L303c   # 0x302e
L3030:  MOVI             R0, 0   # 0x3030
        ADDI             R4, R2, 1   # 0x3034
        MOVI             R1, 0   # 0x3038
L303c:  ST_LOCAL         R5, 176   # 0x303c
        ADDI             R2, R5, 1   # 0x3040
        ST_LOCAL         R2, 172   # 0x3044
        C_MOV            R9, R6   # 0x3048
        C_MOV            R13, R7   # 0x304a
        C_MOV            R6, R0   # 0x304c
        C_MOV            R7, R1   # 0x304e
        LD_LOCAL         R0, 168   # 0x3050
        ST_LOCAL         R0, 100   # 0x3054
        C_BRA            L3072   # 0x3058
L305a:  ST_LOCAL         R4, 164   # 0x305a
        ST_LOCAL         R5, 160   # 0x305e
L3062:  C_MOV            R9, R1   # 0x3062
        C_MOV            R13, R3   # 0x3064
        C_MOV            R6, R0   # 0x3066
        C_MOV            R7, R2   # 0x3068
        C_MOV            R10, R4   # 0x306a
        C_MOV            R11, R5   # 0x306c
        LD_LOCAL         R4, 96   # 0x306e
L3072:  MOVI             R0, 0   # 0x3072
        SETP_LT_NP       P0, R0, R0, R4   # 0x3076
        BRA_PRED         0, L30b6   # 0x307a
        SHLI             R0, R6, 16   # 0x307e
        AND              R1, R0, R7, R0   # 0x3082
        ADD              R2, R0, R7, R0   # 0x3086
        C_OR             R0, R7   # 0x308a
        C_ANDN           R0, R2   # 0x308c
        OR               R0, R1, R0, R1   # 0x308e
        SHRI             R0, R0, 31   # 0x3092
        SHRI             R1, R6, 16   # 0x3096
        ADD              R0, R1, R0, R1   # 0x309a
        OR               R0, R2, R0, R2   # 0x309e
        LD_LOCAL         R1, 100   # 0x30a2
        SETP_LT_NPI      P0, R1, R1, 1   # 0x30a6
        BRA_PRED         0, L2fd2   # 0x30aa
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x30ae
        BRA_PRED         0, L2fd2   # 0x30b2
L30b6:  SETP_NE_NPI      P0, R0, R4, 0   # 0x30b6
        BRA_PRED         4, L320e   # 0x30ba
        LD_LOCAL         R0, 100   # 0x30be
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x30c2
        BRA_PRED         0, L3244   # 0x30c6
        SHLI             R0, R6, 16   # 0x30ca
        AND              R1, R0, R7, R0   # 0x30ce
        ADD              R2, R0, R7, R0   # 0x30d2
        C_OR             R0, R7   # 0x30d6
        C_ANDN           R0, R2   # 0x30d8
        OR               R0, R1, R0, R1   # 0x30da
        SHRI             R0, R0, 31   # 0x30de
        SHRI             R1, R6, 16   # 0x30e2
        ADD              R0, R1, R0, R1   # 0x30e6
        OR               R0, R2, R0, R2   # 0x30ea
        SETP_NE_NPI      P0, R0, R0, 0   # 0x30ee
        BRA_PRED         4, L3244   # 0x30f2
        LD_GLOBAL_IDX    R3, R6, R7, 0, 8   # 0x30f6
        ST_LOCAL         R7, 116   # 0x30fa
        LD_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x30fe
        LD_GLOBAL_IDX    R0, R9, R13, 0, 8   # 0x3102
        LD_GLOBAL_IDX    R1, R9, R13, 0, 12   # 0x3106
        SHLI             R1, R1, 16   # 0x310a
        SHRI             R2, R0, 16   # 0x310e
        C_OR             R1, R2   # 0x3112
        AND              R2, R0, R12, R0   # 0x3114
        CHWIDTH_MULTI    4097, 1   # 0x3118
        LD_GLOBAL_IDX    R12, R1, R2, 0, 0   # 0x311c
        LD_LOCAL         R7, 108   # 0x3120
        AND              R0, R12, R7, R12   # 0x3124
        C_CHWIDTH        R0, 0   # 0x3128
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x312a
        ST_LOCAL         R4, 96   # 0x312e
        BRA_PRED         4, L326a   # 0x3132
        C_CHWIDTH        R0, 1   # 0x3136
        ST_LOCAL         R2, 152   # 0x3138
        ST_LOCAL         R1, 148   # 0x313c
        ST_LOCAL         R5, 144   # 0x3140
        ST_LOCAL         R3, 140   # 0x3144
        LD_LOCAL         R14, 128   # 0x3148
        AND              R0, R12, R14, R12   # 0x314c
        CHWIDTH_MULTI    4097, 0   # 0x3150
        SHRI             R1, R12, 3   # 0x3154
        C_CHWIDTH        R1, 1   # 0x3158
        LD_LOCAL         R14, 132   # 0x315a
        AND              R1, R1, R14, R1   # 0x315e
        C_CHWIDTH        R1, 0   # 0x3162
        MULI             R1, R1, 17   # 0x3164
        C_MOV            R3, R1   # 0x3168
        C_CHWIDTH        R3, 1   # 0x316a
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x316c
        BRA_PRED         0, L3276   # 0x3170
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3174
        C_MOV            R4, R12   # 0x3178
        BRA_PRED         0, L32c2   # 0x317a
        CHWIDTH_MULTI    48, 1   # 0x317e
        CHWIDTH_MULTI    264, 0   # 0x3182
        ST_LOCAL         R13, 156   # 0x3186
        ST_LOCAL         R6, 124   # 0x318a
        MOVI             R0, 34   # 0x318e
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x3192
        C_CHWIDTH        R0, 1   # 0x3196
        MOVI             R6, 34   # 0x3198
        MOV_P            R6, 0, R3, R3, R3   # 0x319c
        LD_LOCAL         R13, 104   # 0x31a0
        LD_LOCAL         R8, 120   # 0x31a4
        LD_GLOBAL_IDX    R0, R13, R8, 0, 96   # 0x31a8
        C_CHWIDTH        R0, 0   # 0x31ac
        LD_GLOBAL_IDX    R1, R13, R8, 0, 40   # 0x31ae
        LD_GLOBAL_IDX    R5, R13, R8, 0, 2   # 0x31b2
        C_CHWIDTH        R5, 0   # 0x31b6
        LD_GLOBAL_IDX    R4, R13, R8, 0, 0   # 0x31b8
        C_CHWIDTH        R4, 0   # 0x31bc
        LD_GLOBAL_IDX    R3, R13, R8, 0, 32   # 0x31be
        LD_GLOBAL_IDX    R2, R13, R8, 0, 36   # 0x31c2
        ST_GLOBAL        R0, R15, -4   # 0x31c6
        SHLI             R0, R2, 16   # 0x31ca
        SHRI             R2, R3, 16   # 0x31ce
        OR               R2, R0, R2, R0   # 0x31d2
        MOVI             R0, 65535   # 0x31d6
        C_AND            R3, R0   # 0x31da
        CALL             R14, 127077   # 0x31dc
        C_CHWIDTH        R0, 1   # 0x31e0
        MOVI             R15, 2   # 0x31e2
        LD_GLOBAL        R15, R15, 24   # 0x31e6
        SRD              R3, 2   # 0x31ea
        C_ADD            R15, R3   # 0x31ec
        LD_GLOBAL_IDX    R0, R13, R8, 0, 102   # 0x31ee
        C_CHWIDTH        R0, 0   # 0x31f2
        C_MOV            R4, R1   # 0x31f4
        C_CHWIDTH        R4, 1   # 0x31f6
        SETP_NE_NPI      P0, R0, R0, 0   # 0x31f8
        BRA_PRED         0, L3204   # 0x31fc
        ST_GLOBAL_IDX    R4, R13, R8, 0, 102   # 0x3200
L3204:  LD_LOCAL         R6, 124   # 0x3204
        LD_LOCAL         R13, 156   # 0x3208
        C_BRA            L32c2   # 0x320c
L320e:  LD_GLOBAL_IDX    R1, R6, R7, 0, 0   # 0x320e
        LD_GLOBAL_IDX    R0, R6, R7, 0, 4   # 0x3212
        SHLI             R0, R0, 16   # 0x3216
        SHRI             R2, R1, 16   # 0x321a
        C_OR             R0, R2   # 0x321e
        AND              R2, R1, R12, R1   # 0x3220
        MOVI             R1, 0   # 0x3224
        ST_LOCAL         R1, 96   # 0x3228
        LD_LOCAL         R1, 100   # 0x322c
        ADDI             R1, R1, -1   # 0x3230
        ST_LOCAL         R1, 100   # 0x3234
        C_MOV            R1, R9   # 0x3238
        C_MOV            R3, R13   # 0x323a
        C_MOV            R4, R6   # 0x323c
        C_MOV            R5, R7   # 0x323e
        BRA              L354c   # 0x3240
L3244:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x3244
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x3248
        SHLI             R1, R1, 16   # 0x324c
        SHRI             R2, R0, 16   # 0x3250
        C_OR             R1, R2   # 0x3254
        AND              R3, R0, R12, R0   # 0x3256
        ADDI             R4, R4, -1   # 0x325a
        ST_LOCAL         R4, 96   # 0x325e
        C_MOV            R0, R6   # 0x3262
        C_MOV            R2, R7   # 0x3264
        BRA              L3548   # 0x3266
L326a:  C_CHWIDTH        R2, 1   # 0x326a
        LD_LOCAL         R14, 112   # 0x326c
        AND              R2, R12, R14, R12   # 0x3270
        C_BRA            L332a   # 0x3274
L3276:  C_CHWIDTH        R3, 0   # 0x3276
        C_CHWIDTH        R4, 1   # 0x3278
        C_CHWIDTH        R8, 0   # 0x327a
        ST_LOCAL         R6, 124   # 0x327c
        LD_LOCAL         R1, 104   # 0x3280
        LD_LOCAL         R8, 120   # 0x3284
        LD_GLOBAL_IDX    R4, R1, R8, 0, 96   # 0x3288
        C_CHWIDTH        R4, 0   # 0x328c
        ADDI             R2, R8, 64   # 0x328e
        CALL             R14, 128350   # 0x3292
        C_CHWIDTH        R0, 1   # 0x3296
        MOVI             R15, 2   # 0x3298
        LD_GLOBAL        R15, R15, 24   # 0x329c
        SRD              R3, 2   # 0x32a0
        C_ADD            R15, R3   # 0x32a2
        LD_LOCAL         R3, 104   # 0x32a4
        LD_GLOBAL_IDX    R0, R3, R8, 0, 100   # 0x32a8
        C_CHWIDTH        R0, 0   # 0x32ac
        C_MOV            R4, R1   # 0x32ae
        C_CHWIDTH        R4, 1   # 0x32b0
        SETP_NE_NPI      P0, R0, R0, 0   # 0x32b2
        BRA_PRED         0, L32be   # 0x32b6
        ST_GLOBAL_IDX    R4, R3, R8, 0, 100   # 0x32ba
L32be:  LD_LOCAL         R6, 124   # 0x32be
L32c2:  CHWIDTH_MULTI    24, 0   # 0x32c2
        C_CHWIDTH        R2, 1   # 0x32c6
        C_CHWIDTH        R8, 0   # 0x32c8
        LD_LOCAL         R5, 120   # 0x32ca
        LD_LOCAL         R8, 104   # 0x32ce
        LD_GLOBAL_IDX    R2, R8, R5, 0, 96   # 0x32d2
        C_CHWIDTH        R2, 0   # 0x32d6
        C_MOV            R1, R4   # 0x32d8
        CALL             R14, 129811   # 0x32da
        CHWIDTH_MULTI    6, 1   # 0x32de
        MOVI             R15, 2   # 0x32e2
        LD_GLOBAL        R15, R15, 24   # 0x32e6
        SRD              R3, 2   # 0x32ea
        C_ADD            R15, R3   # 0x32ec
        ST_GLOBAL_IDX    R1, R8, R5, 0, 96   # 0x32ee
        C_CHWIDTH        R1, 0   # 0x32f2
        LD_LOCAL         R14, 112   # 0x32f4
        AND              R2, R4, R14, R4   # 0x32f8
        LD_LOCAL         R14, 136   # 0x32fc
        C_CHWIDTH        R14, 1   # 0x3300
        AND              R14, R12, R14, R12   # 0x3302
        OR               R14, R14, R2, R14   # 0x3306
        LD_LOCAL         R7, 108   # 0x330a
        OR               R14, R14, R7, R14   # 0x330e
        LD_LOCAL         R0, 148   # 0x3312
        LD_LOCAL         R1, 152   # 0x3316
        ST_GLOBAL_IDX    R14, R0, R1, 0, 0   # 0x331a
        LD_LOCAL         R4, 96   # 0x331e
        LD_LOCAL         R3, 140   # 0x3322
        LD_LOCAL         R5, 144   # 0x3326
L332a:  C_CHWIDTH        R12, 1   # 0x332a
        SHLI             R0, R5, 16   # 0x332c
        SHRI             R1, R3, 16   # 0x3330
        OR               R1, R0, R1, R0   # 0x3334
        MOVI             R0, 65535   # 0x3338
        C_AND            R3, R0   # 0x333c
        C_CHWIDTH        R0, 1   # 0x333e
        LD_GLOBAL_IDX    R12, R1, R3, 0, 0   # 0x3340
        AND              R0, R12, R7, R12   # 0x3344
        C_CHWIDTH        R0, 0   # 0x3348
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x334a
        BRA_PRED         4, L342a   # 0x334e
        C_CHWIDTH        R0, 1   # 0x3352
        CHWIDTH_MULTI    16388, 0   # 0x3354
        ST_LOCAL         R3, 148   # 0x3358
        ST_LOCAL         R1, 144   # 0x335c
        ST_LOCAL         R2, 140   # 0x3360
        LD_LOCAL         R14, 128   # 0x3364
        AND              R0, R12, R14, R12   # 0x3368
        CHWIDTH_MULTI    4097, 0   # 0x336c
        SHRI             R1, R12, 3   # 0x3370
        C_CHWIDTH        R1, 1   # 0x3374
        LD_LOCAL         R14, 132   # 0x3376
        AND              R1, R1, R14, R1   # 0x337a
        C_CHWIDTH        R1, 0   # 0x337e
        MULI             R1, R1, 17   # 0x3380
        C_MOV            R3, R1   # 0x3384
        C_CHWIDTH        R3, 1   # 0x3386
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x3388
        BRA_PRED         0, L3438   # 0x338c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3390
        C_MOV            R4, R12   # 0x3394
        BRA_PRED         0, L3484   # 0x3396
        CHWIDTH_MULTI    48, 1   # 0x339a
        CHWIDTH_MULTI    264, 0   # 0x339e
        ST_LOCAL         R9, 152   # 0x33a2
        ST_LOCAL         R6, 124   # 0x33a6
        MOVI             R0, 34   # 0x33aa
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x33ae
        C_CHWIDTH        R0, 1   # 0x33b2
        MOVI             R6, 34   # 0x33b4
        MOV_P            R6, 0, R3, R3, R3   # 0x33b8
        LD_LOCAL         R9, 104   # 0x33bc
        LD_LOCAL         R8, 120   # 0x33c0
        LD_GLOBAL_IDX    R0, R9, R8, 0, 96   # 0x33c4
        C_CHWIDTH        R0, 0   # 0x33c8
        LD_GLOBAL_IDX    R1, R9, R8, 0, 40   # 0x33ca
        LD_GLOBAL_IDX    R5, R9, R8, 0, 2   # 0x33ce
        C_CHWIDTH        R5, 0   # 0x33d2
        LD_GLOBAL_IDX    R4, R9, R8, 0, 0   # 0x33d4
        C_CHWIDTH        R4, 0   # 0x33d8
        LD_GLOBAL_IDX    R3, R9, R8, 0, 32   # 0x33da
        LD_GLOBAL_IDX    R2, R9, R8, 0, 36   # 0x33de
        ST_GLOBAL        R0, R15, -4   # 0x33e2
        SHLI             R0, R2, 16   # 0x33e6
        SHRI             R2, R3, 16   # 0x33ea
        OR               R2, R0, R2, R0   # 0x33ee
        MOVI             R0, 65535   # 0x33f2
        C_AND            R3, R0   # 0x33f6
        CALL             R14, 126807   # 0x33f8
        C_CHWIDTH        R0, 1   # 0x33fc
        MOVI             R15, 2   # 0x33fe
        LD_GLOBAL        R15, R15, 24   # 0x3402
        SRD              R3, 2   # 0x3406
        C_ADD            R15, R3   # 0x3408
        LD_GLOBAL_IDX    R0, R9, R8, 0, 102   # 0x340a
        C_CHWIDTH        R0, 0   # 0x340e
        C_MOV            R4, R1   # 0x3410
        C_CHWIDTH        R4, 1   # 0x3412
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3414
        BRA_PRED         0, L3420   # 0x3418
        ST_GLOBAL_IDX    R4, R9, R8, 0, 102   # 0x341c
L3420:  LD_LOCAL         R6, 124   # 0x3420
        LD_LOCAL         R9, 152   # 0x3424
        C_BRA            L3484   # 0x3428
L342a:  C_CHWIDTH        R0, 1   # 0x342a
        C_CHWIDTH        R14, 0   # 0x342c
        LD_LOCAL         R14, 112   # 0x342e
        AND              R0, R12, R14, R12   # 0x3432
        C_BRA            L34e8   # 0x3436
L3438:  C_CHWIDTH        R3, 0   # 0x3438
        C_CHWIDTH        R4, 1   # 0x343a
        C_CHWIDTH        R8, 0   # 0x343c
        ST_LOCAL         R6, 124   # 0x343e
        LD_LOCAL         R1, 104   # 0x3442
        LD_LOCAL         R8, 120   # 0x3446
        LD_GLOBAL_IDX    R4, R1, R8, 0, 96   # 0x344a
        C_CHWIDTH        R4, 0   # 0x344e
        ADDI             R2, R8, 64   # 0x3450
        CALL             R14, 128125   # 0x3454
        C_CHWIDTH        R0, 1   # 0x3458
        MOVI             R15, 2   # 0x345a
        LD_GLOBAL        R15, R15, 24   # 0x345e
        SRD              R3, 2   # 0x3462
        C_ADD            R15, R3   # 0x3464
        LD_LOCAL         R3, 104   # 0x3466
        LD_GLOBAL_IDX    R0, R3, R8, 0, 100   # 0x346a
        C_CHWIDTH        R0, 0   # 0x346e
        C_MOV            R4, R1   # 0x3470
        C_CHWIDTH        R4, 1   # 0x3472
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3474
        BRA_PRED         0, L3480   # 0x3478
        ST_GLOBAL_IDX    R4, R3, R8, 0, 100   # 0x347c
L3480:  LD_LOCAL         R6, 124   # 0x3480
L3484:  CHWIDTH_MULTI    24, 0   # 0x3484
        C_CHWIDTH        R2, 1   # 0x3488
        C_CHWIDTH        R8, 0   # 0x348a
        LD_LOCAL         R5, 120   # 0x348c
        LD_LOCAL         R8, 104   # 0x3490
        LD_GLOBAL_IDX    R2, R8, R5, 0, 96   # 0x3494
        C_CHWIDTH        R2, 0   # 0x3498
        C_MOV            R1, R4   # 0x349a
        CALL             R14, 129586   # 0x349c
        CHWIDTH_MULTI    3, 1   # 0x34a0
        MOVI             R15, 2   # 0x34a4
        LD_GLOBAL        R15, R15, 24   # 0x34a8
        SRD              R3, 2   # 0x34ac
        C_ADD            R15, R3   # 0x34ae
        ST_GLOBAL_IDX    R1, R8, R5, 0, 96   # 0x34b0
        C_CHWIDTH        R1, 0   # 0x34b4
        LD_LOCAL         R14, 112   # 0x34b6
        AND              R0, R4, R14, R4   # 0x34ba
        LD_LOCAL         R14, 136   # 0x34be
        C_CHWIDTH        R14, 1   # 0x34c2
        AND              R14, R12, R14, R12   # 0x34c4
        OR               R14, R14, R0, R14   # 0x34c8
        LD_LOCAL         R7, 108   # 0x34cc
        OR               R14, R14, R7, R14   # 0x34d0
        LD_LOCAL         R1, 144   # 0x34d4
        LD_LOCAL         R2, 148   # 0x34d8
        ST_GLOBAL_IDX    R14, R1, R2, 0, 0   # 0x34dc
        LD_LOCAL         R4, 96   # 0x34e0
        LD_LOCAL         R2, 140   # 0x34e4
L34e8:  CHWIDTH_MULTI    4101, 0   # 0x34e8
        SETP_LT_U_NP     P0, R0, R0, R2   # 0x34ec
        LD_LOCAL         R5, 116   # 0x34f0
        MOVI             R12, 65535   # 0x34f4
        BRA_PRED         4, L3526   # 0x34f8
        LD_GLOBAL_IDX    R1, R6, R5, 0, 0   # 0x34fc
        LD_GLOBAL_IDX    R0, R6, R5, 0, 4   # 0x3500
        SHLI             R0, R0, 16   # 0x3504
        SHRI             R2, R1, 16   # 0x3508
        C_OR             R0, R2   # 0x350c
        AND              R2, R1, R12, R1   # 0x350e
        LD_LOCAL         R1, 100   # 0x3512
        ADDI             R1, R1, -1   # 0x3516
        ST_LOCAL         R1, 100   # 0x351a
        C_MOV            R1, R9   # 0x351e
        C_MOV            R3, R13   # 0x3520
        C_MOV            R4, R6   # 0x3522
        C_BRA            L354c   # 0x3524
L3526:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x3526
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x352a
        SHLI             R1, R1, 16   # 0x352e
        SHRI             R2, R0, 16   # 0x3532
        C_OR             R1, R2   # 0x3536
        AND              R3, R0, R12, R0   # 0x3538
        ADDI             R4, R4, -1   # 0x353c
        ST_LOCAL         R4, 96   # 0x3540
        C_MOV            R0, R6   # 0x3544
        C_MOV            R2, R5   # 0x3546
L3548:  C_MOV            R4, R9   # 0x3548
        C_MOV            R5, R13   # 0x354a
L354c:  C_CHWIDTH        R14, 0   # 0x354c
        SHLI             R6, R10, 16   # 0x354e
        AND              R7, R6, R11, R6   # 0x3552
        ADD              R14, R6, R11, R6   # 0x3556
        C_OR             R6, R11   # 0x355a
        C_ANDN           R6, R14   # 0x355c
        OR               R6, R7, R6, R7   # 0x355e
        SHRI             R6, R6, 31   # 0x3562
        SHRI             R7, R10, 16   # 0x3566
        ADD              R6, R7, R6, R7   # 0x356a
        OR               R6, R14, R6, R14   # 0x356e
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x3572
        BRA_PRED         0, L305a   # 0x3576
        SHLI             R6, R4, 16   # 0x357a
        ADD              R7, R6, R5, R6   # 0x357e
        ST_GLOBAL_IDX    R7, R10, R11, 0, 0   # 0x3582
        OR               R14, R6, R5, R6   # 0x3586
        ANDN             R7, R14, R7, R14   # 0x358a
        C_AND            R6, R5   # 0x358e
        C_OR             R6, R7   # 0x3590
        SHRI             R6, R6, 31   # 0x3592
        SHRI             R7, R4, 16   # 0x3596
        ADD              R6, R7, R6, R7   # 0x359a
        ST_GLOBAL_IDX    R6, R10, R11, 0, 4   # 0x359e
        BRA              L3062   # 0x35a2
L35a6:  C_CHWIDTH        R8, 0   # 0x35a6
        C_MOV            R8, R6   # 0x35a8
        C_MOV            R9, R7   # 0x35aa
L35ac:  CHWIDTH_MULTI    18432, 0   # 0x35ac
        C_CHWIDTH        R7, 1   # 0x35b0
        LD_GLOBAL_IDX    R1, R8, R9, 0, 0   # 0x35b2
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x35b6
        SHLI             R0, R0, 16   # 0x35ba
        SHRI             R2, R1, 16   # 0x35be
        OR               R3, R0, R2, R0   # 0x35c2
        MOVI             R0, 65535   # 0x35c6
        AND              R4, R1, R0, R1   # 0x35ca
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x35ce
        SHLI             R1, R1, 16   # 0x35d2
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x35d6
        SHRI             R5, R2, 16   # 0x35da
        OR               R5, R1, R5, R1   # 0x35de
        AND              R6, R2, R0, R2   # 0x35e2
        LD_GLOBAL_IDX    R7, R5, R6, 0, 12   # 0x35e6
        C_CHWIDTH        R7, 0   # 0x35ea
        LD_GLOBAL_IDX    R2, R5, R6, 0, 8   # 0x35ec
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x35f0
        ST_GLOBAL_IDX    R2, R3, R4, 0, 8   # 0x35f4
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x35f8
        ST_GLOBAL_IDX    R7, R3, R4, 0, 12   # 0x35fc
        AND              R7, R2, R0, R2   # 0x3600
        ST_GLOBAL_IDX    R7, R5, R6, 0, 12   # 0x3604
        C_CHWIDTH        R7, 1   # 0x3608
        ST_GLOBAL_IDX    R1, R5, R6, 0, 8   # 0x360a
        LD_GLOBAL_IDX    R7, R5, R6, 0, 4   # 0x360e
        C_CHWIDTH        R7, 0   # 0x3612
        LD_GLOBAL_IDX    R14, R5, R6, 0, 0   # 0x3614
        ST_GLOBAL_IDX    R14, R3, R4, 0, 0   # 0x3618
        ST_GLOBAL_IDX    R7, R3, R4, 0, 4   # 0x361c
        LD_LOCAL         R10, 188   # 0x3620
        C_MOV            R4, R10   # 0x3624
        C_CHWIDTH        R4, 1   # 0x3626
        C_MOV            R7, R10   # 0x3628
        C_CHWIDTH        R7, 1   # 0x362a
        C_MOV            R11, R10   # 0x362c
        C_CHWIDTH        R11, 1   # 0x362e
        CVT_SEXT         R3, R4, R7, R11   # 0x3630
        CHWIDTH_MULTI    144, 0   # 0x3634
        MOVI48           R4, 4294967295   # 0x3638
        SETP_LT_NP       P0, R3, R4, R3   # 0x363e
        MOVI             R3, 0   # 0x3642
        ST_GLOBAL_IDX    R3, R5, R6, 0, 4   # 0x3646
        ST_GLOBAL_IDX    R3, R5, R6, 0, 0   # 0x364a
        C_MOV            R13, R8   # 0x364e
        ST_LOCAL         R9, 160   # 0x3650
        BRA_PRED         4, L36a4   # 0x3654
L3658:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x3658
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x365c
        SHLI             R4, R4, 16   # 0x3660
        SHRI             R7, R3, 16   # 0x3664
        C_OR             R4, R7   # 0x3668
        C_CHWIDTH        R7, 1   # 0x366a
        C_AND            R3, R0   # 0x366c
        LD_GLOBAL_IDX    R7, R4, R3, 0, 2   # 0x366e
        C_CHWIDTH        R7, 0   # 0x3672
        SETP_EQ_NP       P0, R3, R7, R10   # 0x3674
        BRA_PRED         0, L36fa   # 0x3678
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x367c
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x3680
        SHRI             R7, R4, 16   # 0x3684
        SHLI             R14, R3, 16   # 0x3688
        OR               R8, R14, R7, R14   # 0x368c
        C_AND            R3, R0   # 0x3690
        OR               R3, R4, R3, R4   # 0x3692
        AND              R9, R4, R0, R4   # 0x3696
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x369a
        BRA_PRED         4, L3658   # 0x369e
        C_BRA            L36f2   # 0x36a2
L36a4:  LD_LOCAL         R10, 192   # 0x36a4
L36a8:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x36a8
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x36ac
        SHLI             R4, R4, 16   # 0x36b0
        SHRI             R7, R3, 16   # 0x36b4
        C_OR             R4, R7   # 0x36b8
        C_CHWIDTH        R7, 2   # 0x36ba
        C_AND            R3, R0   # 0x36bc
        LD_GLOBAL_IDX    R7, R4, R3, 0, 0   # 0x36be
        C_CHWIDTH        R7, 0   # 0x36c2
        SETP_EQ_NP       P0, R3, R7, R10   # 0x36c4
        BRA_PRED         0, L36fa   # 0x36c8
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x36cc
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x36d0
        SHRI             R7, R4, 16   # 0x36d4
        SHLI             R14, R3, 16   # 0x36d8
        OR               R8, R14, R7, R14   # 0x36dc
        C_AND            R3, R0   # 0x36e0
        OR               R3, R4, R3, R4   # 0x36e2
        AND              R9, R4, R0, R4   # 0x36e6
        SETP_NE_NPI      P0, R3, R3, 0   # 0x36ea
        BRA_PRED         0, L36a8   # 0x36ee
L36f2:  MOVI             R8, 0   # 0x36f2
        MOVI             R9, 0   # 0x36f6
L36fa:  SHLI             R2, R2, 16   # 0x36fa
        SHRI             R3, R1, 16   # 0x36fe
        SHLI             R4, R8, 16   # 0x3702
        AND              R7, R4, R9, R4   # 0x3706
        ADD              R14, R4, R9, R4   # 0x370a
        C_OR             R4, R9   # 0x370e
        C_ANDN           R4, R14   # 0x3710
        OR               R4, R7, R4, R7   # 0x3712
        SHRI             R4, R4, 31   # 0x3716
        SHRI             R7, R8, 16   # 0x371a
        ADD              R4, R7, R4, R7   # 0x371e
        OR               R4, R14, R4, R14   # 0x3722
        SETP_NE_NPI      P0, R4, R4, 0   # 0x3726
        BRA_PRED         0, L3750   # 0x372a
        C_MOV            R7, R13   # 0x372e
        LD_LOCAL         R14, 160   # 0x3730
        LD_GLOBAL_IDX    R4, R7, R14, 0, 0   # 0x3734
        LD_GLOBAL_IDX    R7, R7, R14, 0, 4   # 0x3738
        SHLI             R7, R7, 16   # 0x373c
        SHRI             R14, R4, 16   # 0x3740
        OR               R8, R7, R14, R7   # 0x3744
        MOVI             R7, 65535   # 0x3748
        AND              R9, R4, R7, R4   # 0x374c
L3750:  C_CHWIDTH        R11, 0   # 0x3750
        OR               R10, R2, R3, R2   # 0x3752
        AND              R11, R1, R0, R1   # 0x3756
        SHLI             R0, R8, 16   # 0x375a
        AND              R1, R0, R9, R0   # 0x375e
        ADD              R2, R0, R9, R0   # 0x3762
        C_OR             R0, R9   # 0x3766
        C_ANDN           R0, R2   # 0x3768
        OR               R0, R1, R0, R1   # 0x376a
        SHRI             R0, R0, 31   # 0x376e
        SHRI             R1, R8, 16   # 0x3772
        ADD              R0, R1, R0, R1   # 0x3776
        OR               R0, R2, R0, R2   # 0x377a
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x377e
        BRA_PRED         0, L37f0   # 0x3782
        C_CHWIDTH        R4, 1   # 0x3786
        C_MOV            R1, R13   # 0x3788
        LD_LOCAL         R2, 160   # 0x378a
        LD_GLOBAL_IDX    R0, R1, R2, 0, 8   # 0x378e
        LD_GLOBAL_IDX    R1, R1, R2, 0, 12   # 0x3792
        SHLI             R1, R1, 16   # 0x3796
        SHRI             R2, R0, 16   # 0x379a
        C_OR             R1, R2   # 0x379e
        MOVI             R12, 65535   # 0x37a0
        C_AND            R0, R12   # 0x37a4
        LD_GLOBAL_IDX    R4, R1, R0, 0, 0   # 0x37a6
        LD_LOCAL         R2, 180   # 0x37aa
L37ae:  CHWIDTH_MULTI    20, 0   # 0x37ae
        C_MOV            R1, R4   # 0x37b2
        CALL             R14, 127384   # 0x37b4
        MOVI             R15, 2   # 0x37b8
        LD_GLOBAL        R15, R15, 24   # 0x37bc
        SRD              R3, 2   # 0x37c0
        C_ADD            R15, R3   # 0x37c2
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x37c4
        LD_GLOBAL_IDX    R2, R8, R9, 0, 0   # 0x37c8
        SHRI             R3, R2, 16   # 0x37cc
        SHLI             R7, R0, 16   # 0x37d0
        OR               R8, R7, R3, R7   # 0x37d4
        C_AND            R0, R12   # 0x37d8
        OR               R0, R2, R0, R2   # 0x37da
        AND              R9, R2, R12, R2   # 0x37de
        C_MOV            R2, R1   # 0x37e2
        C_CHWIDTH        R2, 1   # 0x37e4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x37e6
        BRA_PRED         0, L37ae   # 0x37ea
        C_BRA            L37f4   # 0x37ee
L37f0:  LD_LOCAL         R2, 180   # 0x37f0
L37f4:  C_CHWIDTH        R3, 1   # 0x37f4
        C_CHWIDTH        R2, 0   # 0x37f6
        ST_LOCAL         R2, 180   # 0x37f8
        LD_LOCAL         R7, 160   # 0x37fc
        LD_GLOBAL_IDX    R1, R13, R7, 0, 0   # 0x3800
        LD_GLOBAL_IDX    R0, R13, R7, 0, 4   # 0x3804
        SHLI             R0, R0, 16   # 0x3808
        SHRI             R2, R1, 16   # 0x380c
        OR               R2, R0, R2, R0   # 0x3810
        MOVI             R0, 65535   # 0x3814
        C_AND            R1, R0   # 0x3818
        LD_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x381a
        C_CHWIDTH        R3, 0   # 0x381e
        LD_GLOBAL_IDX    R4, R2, R1, 0, 8   # 0x3820
        ST_GLOBAL_IDX    R4, R5, R6, 0, 8   # 0x3824
        ST_GLOBAL_IDX    R3, R5, R6, 0, 12   # 0x3828
        SHRI             R3, R10, 16   # 0x382c
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x3830
        SHLI             R3, R10, 16   # 0x3834
        C_OR             R3, R11   # 0x3838
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x383a
        C_CHWIDTH        R3, 1   # 0x383e
        LD_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x3840
        C_CHWIDTH        R3, 0   # 0x3844
        LD_GLOBAL_IDX    R4, R2, R1, 0, 0   # 0x3846
        ST_GLOBAL_IDX    R4, R5, R6, 0, 0   # 0x384a
        ST_GLOBAL_IDX    R3, R5, R6, 0, 4   # 0x384e
        SHLI             R3, R5, 16   # 0x3852
        C_OR             R3, R6   # 0x3856
        SHRI             R4, R5, 16   # 0x3858
        ST_GLOBAL_IDX    R4, R2, R1, 0, 4   # 0x385c
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3860
        C_MOV            R1, R13   # 0x3864
        C_MOV            R13, R7   # 0x3866
        MOVI             R9, 1   # 0x3868
        C_BRA            L3890   # 0x386c
L386e:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x386e
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x3872
        C_SHLI           R9, 1   # 0x3876
        LD_LOCAL         R1, 104   # 0x3878
        SETP_NE_NPI      P0, R1, R1, 0   # 0x387c
        LD_LOCAL         R3, 96   # 0x3880
        C_MOV            R1, R3   # 0x3884
        LD_LOCAL         R4, 100   # 0x3886
        C_MOV            R13, R4   # 0x388a
        BRA_PRED         4, L3b12   # 0x388c
L3890:  MOVI             R5, 0   # 0x3890
        MOVI             R2, 0   # 0x3894
        MOVI             R4, 0   # 0x3898
        MOVI             R3, 0   # 0x389c
        ST_LOCAL         R3, 96   # 0x38a0
        ST_LOCAL         R3, 100   # 0x38a4
        ST_LOCAL         R9, 112   # 0x38a8
        C_BRA            L38be   # 0x38ac
L38ae:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x38ae
        LD_LOCAL         R9, 112   # 0x38b2
        LD_LOCAL         R5, 108   # 0x38b6
        BRA_PRED         0, L386e   # 0x38ba
L38be:  ST_LOCAL         R5, 104   # 0x38be
        SETP_LT_NPI      P0, R5, R9, 1   # 0x38c2
        BRA_PRED         0, L3906   # 0x38c6
        MOVI             R5, 0   # 0x38ca
        C_MOV            R6, R1   # 0x38ce
        C_MOV            R7, R13   # 0x38d0
L38d2:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x38d2
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x38d6
        AND              R6, R14, R0, R14   # 0x38da
        OR               R6, R7, R6, R7   # 0x38de
        SETP_NE_NPI      P0, R6, R6, 0   # 0x38e2
        BRA_PRED         4, L3910   # 0x38e6
        SHRI             R6, R7, 16   # 0x38ea
        SHLI             R14, R14, 16   # 0x38ee
        OR               R6, R14, R6, R14   # 0x38f2
        C_AND            R7, R0   # 0x38f6
        C_ADDI           R5, 1   # 0x38f8
        SETP_EQ_NP       P0, R14, R9, R5   # 0x38fa
        BRA_PRED         4, L38d2   # 0x38fe
        C_MOV            R8, R9   # 0x3902
        C_BRA            L391c   # 0x3904
L3906:  MOVI             R8, 0   # 0x3906
        C_MOV            R6, R1   # 0x390a
        C_MOV            R7, R13   # 0x390c
        C_BRA            L391c   # 0x390e
L3910:  MOVI             R6, 0   # 0x3910
        ADDI             R8, R5, 1   # 0x3914
        MOVI             R7, 0   # 0x3918
L391c:  LD_LOCAL         R5, 104   # 0x391c
        C_ADDI           R5, 1   # 0x3920
        ST_LOCAL         R5, 108   # 0x3922
        C_MOV            R5, R1   # 0x3926
        C_MOV            R14, R13   # 0x3928
        C_MOV            R1, R6   # 0x392a
        C_MOV            R13, R7   # 0x392c
        C_BRA            L3942   # 0x392e
L3930:  ST_LOCAL         R6, 96   # 0x3930
        ST_LOCAL         R7, 100   # 0x3934
L3938:  C_MOV            R5, R11   # 0x3938
        C_MOV            R14, R10   # 0x393a
        C_MOV            R1, R12   # 0x393c
        C_MOV            R2, R6   # 0x393e
        C_MOV            R4, R7   # 0x3940
L3942:  SETP_LT_NP       P0, R6, R3, R8   # 0x3942
        BRA_PRED         0, L397e   # 0x3946
        SHLI             R6, R1, 16   # 0x394a
        AND              R7, R6, R13, R6   # 0x394e
        ADD              R10, R6, R13, R6   # 0x3952
        C_OR             R6, R13   # 0x3956
        C_ANDN           R6, R10   # 0x3958
        OR               R6, R7, R6, R7   # 0x395a
        SHRI             R6, R6, 31   # 0x395e
        SHRI             R7, R1, 16   # 0x3962
        ADD              R6, R7, R6, R7   # 0x3966
        OR               R6, R10, R6, R10   # 0x396a
        SETP_LT_NPI      P0, R7, R9, 1   # 0x396e
        BRA_PRED         0, L38ae   # 0x3972
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x3976
        BRA_PRED         0, L38ae   # 0x397a
L397e:  SETP_NE_NPI      P0, R6, R8, 0   # 0x397e
        BRA_PRED         4, L3a42   # 0x3982
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x3986
        BRA_PRED         0, L3a6c   # 0x398a
        SHLI             R6, R1, 16   # 0x398e
        AND              R7, R6, R13, R6   # 0x3992
        ADD              R10, R6, R13, R6   # 0x3996
        C_OR             R6, R13   # 0x399a
        C_ANDN           R6, R10   # 0x399c
        OR               R6, R7, R6, R7   # 0x399e
        SHRI             R6, R6, 31   # 0x39a2
        SHRI             R7, R1, 16   # 0x39a6
        ADD              R6, R7, R6, R7   # 0x39aa
        OR               R6, R10, R6, R10   # 0x39ae
        SETP_NE_NPI      P0, R6, R6, 0   # 0x39b2
        BRA_PRED         4, L3a6c   # 0x39b6
        C_CHWIDTH        R12, 2   # 0x39ba
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x39bc
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x39c0
        SHLI             R7, R7, 16   # 0x39c4
        SHRI             R10, R6, 16   # 0x39c8
        C_OR             R7, R10   # 0x39cc
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x39ce
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x39d2
        C_AND            R6, R0   # 0x39d6
        LD_GLOBAL_IDX    R12, R7, R6, 0, 1   # 0x39d8
        ST_GLOBAL_IDX    R12, R7, R6, 0, 0   # 0x39dc
        C_CHWIDTH        R12, 0   # 0x39e0
        SHLI             R11, R11, 16   # 0x39e2
        SHRI             R12, R10, 16   # 0x39e6
        C_OR             R11, R12   # 0x39ea
        C_CHWIDTH        R12, 2   # 0x39ec
        C_AND            R10, R0   # 0x39ee
        LD_GLOBAL_IDX    R12, R11, R10, 0, 1   # 0x39f0
        ST_GLOBAL_IDX    R12, R11, R10, 0, 0   # 0x39f4
        C_MOV            R3, R13   # 0x39f8
        C_CHWIDTH        R13, 1   # 0x39fa
        LD_GLOBAL_IDX    R13, R7, R6, 0, 2   # 0x39fc
        C_CHWIDTH        R7, 1   # 0x3a00
        LD_GLOBAL_IDX    R7, R11, R10, 0, 2   # 0x3a02
        CVT_SEXT         R6, R7, R7, R7   # 0x3a06
        C_CHWIDTH        R7, 0   # 0x3a0a
        CVT_SEXT         R7, R13, R13, R13   # 0x3a0c
        SETP_LT_NP       P0, R6, R6, R7   # 0x3a10
        BRA_PRED         4, L3a90   # 0x3a14
        CHWIDTH_MULTI    12288, 0   # 0x3a18
        LD_GLOBAL_IDX    R6, R1, R3, 0, 0   # 0x3a1c
        LD_GLOBAL_IDX    R7, R1, R3, 0, 4   # 0x3a20
        SHLI             R7, R7, 16   # 0x3a24
        SHRI             R10, R6, 16   # 0x3a28
        OR               R12, R7, R10, R7   # 0x3a2c
        AND              R13, R6, R0, R6   # 0x3a30
        ADDI             R9, R9, -1   # 0x3a34
        C_MOV            R11, R5   # 0x3a38
        C_MOV            R10, R14   # 0x3a3a
        C_MOV            R6, R1   # 0x3a3c
        C_MOV            R7, R3   # 0x3a3e
        C_BRA            L3ab8   # 0x3a40
L3a42:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x3a42
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x3a46
        SHLI             R7, R7, 16   # 0x3a4a
        SHRI             R8, R6, 16   # 0x3a4e
        OR               R12, R7, R8, R7   # 0x3a52
        C_MOV            R7, R13   # 0x3a56
        AND              R13, R6, R0, R6   # 0x3a58
        MOVI             R8, 0   # 0x3a5c
        ADDI             R9, R9, -1   # 0x3a60
        C_MOV            R11, R5   # 0x3a64
        C_MOV            R10, R14   # 0x3a66
        C_MOV            R6, R1   # 0x3a68
        C_BRA            L3abc   # 0x3a6a
L3a6c:  LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x3a6c
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x3a70
        SHLI             R7, R7, 16   # 0x3a74
        SHRI             R10, R6, 16   # 0x3a78
        OR               R11, R7, R10, R7   # 0x3a7c
        AND              R10, R6, R0, R6   # 0x3a80
        ADDI             R8, R8, -1   # 0x3a84
        C_MOV            R12, R1   # 0x3a88
        C_MOV            R6, R5   # 0x3a8a
        C_MOV            R7, R14   # 0x3a8c
        C_BRA            L3abc   # 0x3a8e
L3a90:  CHWIDTH_MULTI    12288, 0   # 0x3a90
        LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x3a94
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x3a98
        SHLI             R7, R7, 16   # 0x3a9c
        SHRI             R10, R6, 16   # 0x3aa0
        OR               R11, R7, R10, R7   # 0x3aa4
        AND              R10, R6, R0, R6   # 0x3aa8
        ADDI             R8, R8, -1   # 0x3aac
        C_MOV            R12, R1   # 0x3ab0
        C_MOV            R13, R3   # 0x3ab2
        C_MOV            R6, R5   # 0x3ab4
        C_MOV            R7, R14   # 0x3ab6
L3ab8:  MOVI             R3, 0   # 0x3ab8
L3abc:  SHLI             R5, R2, 16   # 0x3abc
        AND              R14, R5, R4, R5   # 0x3ac0
        ADD              R1, R5, R4, R5   # 0x3ac4
        C_OR             R5, R4   # 0x3ac8
        C_ANDN           R5, R1   # 0x3aca
        OR               R5, R14, R5, R14   # 0x3acc
        SHRI             R5, R5, 31   # 0x3ad0
        SHRI             R14, R2, 16   # 0x3ad4
        ADD              R5, R14, R5, R14   # 0x3ad8
        C_OR             R1, R5   # 0x3adc
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x3ade
        BRA_PRED         0, L3930   # 0x3ae2
        SHLI             R1, R6, 16   # 0x3ae6
        ADD              R5, R1, R7, R1   # 0x3aea
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x3aee
        OR               R14, R1, R7, R1   # 0x3af2
        ANDN             R5, R14, R5, R14   # 0x3af6
        C_AND            R1, R7   # 0x3afa
        C_OR             R1, R5   # 0x3afc
        SHRI             R1, R1, 31   # 0x3afe
        SHRI             R5, R6, 16   # 0x3b02
        ADD              R1, R5, R1, R5   # 0x3b06
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x3b0a
        BRA              L3938   # 0x3b0e
L3b12:  LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x3b12
        LD_GLOBAL_IDX    R0, R3, R4, 0, 0   # 0x3b16
        MOVI             R5, 65535   # 0x3b1a
        AND              R2, R1, R5, R1   # 0x3b1e
        OR               R2, R0, R2, R0   # 0x3b22
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x3b26
        BRA_PRED         0, L3b9c   # 0x3b2a
        SHRI             R2, R0, 16   # 0x3b2e
        SHLI             R1, R1, 16   # 0x3b32
        OR               R6, R1, R2, R1   # 0x3b36
        AND              R8, R0, R5, R0   # 0x3b3a
        LD_GLOBAL_IDX    R0, R3, R4, 0, 8   # 0x3b3e
        LD_GLOBAL_IDX    R1, R3, R4, 0, 12   # 0x3b42
        C_CHWIDTH        R4, 1   # 0x3b46
        SHLI             R1, R1, 16   # 0x3b48
        SHRI             R2, R0, 16   # 0x3b4c
        C_OR             R1, R2   # 0x3b50
        C_AND            R0, R5   # 0x3b52
        LD_GLOBAL_IDX    R4, R1, R0, 0, 0   # 0x3b54
        LD_LOCAL         R2, 180   # 0x3b58
L3b5c:  CHWIDTH_MULTI    20, 0   # 0x3b5c
        C_MOV            R1, R4   # 0x3b60
        CALL             R14, 126913   # 0x3b62
        MOVI             R15, 2   # 0x3b66
        LD_GLOBAL        R15, R15, 24   # 0x3b6a
        SRD              R3, 2   # 0x3b6e
        C_ADD            R15, R3   # 0x3b70
        LD_GLOBAL_IDX    R0, R6, R8, 0, 4   # 0x3b72
        LD_GLOBAL_IDX    R2, R6, R8, 0, 0   # 0x3b76
        SHRI             R3, R2, 16   # 0x3b7a
        SHLI             R6, R0, 16   # 0x3b7e
        C_OR             R6, R3   # 0x3b82
        C_AND            R0, R5   # 0x3b84
        OR               R0, R2, R0, R2   # 0x3b86
        AND              R8, R2, R5, R2   # 0x3b8a
        C_MOV            R2, R1   # 0x3b8e
        C_CHWIDTH        R2, 1   # 0x3b90
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3b92
        BRA_PRED         0, L3b5c   # 0x3b96
        C_BRA            L3ba0   # 0x3b9a
L3b9c:  LD_LOCAL         R2, 180   # 0x3b9c
L3ba0:  C_CHWIDTH        R2, 0   # 0x3ba0
        LD_LOCAL         R14, 184   # 0x3ba2
        C_MOV            R1, R2   # 0x3ba6
        LD_LOCAL         R13, 216   # 0x3ba8
        LD_LOCAL         R12, 212   # 0x3bac
        LD_LOCAL         R11, 208   # 0x3bb0
        LD_LOCAL         R10, 204   # 0x3bb4
        LD_LOCAL         R9, 200   # 0x3bb8
        LD_LOCAL         R8, 196   # 0x3bbc
        C_RET            224   # 0x3bc0
        MOVI             R15, 2   # 0x3bc2
        LD_GLOBAL        R15, R15, 24   # 0x3bc6
        SRD              R14, 2   # 0x3bca
        C_ADD            R15, R14   # 0x3bcc
        MOVI             R8, 2   # 0x3bce
        LD_GLOBAL        R0, R8, 36   # 0x3bd2
        MOVI             R1, 2000   # 0x3bd6
        SRD              R2, 0   # 0x3bda
        ST_LOCAL         R2, 220   # 0x3bdc
        MADLO            R3, R2, R1, R0   # 0x3be0
        ADDI             R4, R3, 666   # 0x3be4
        ST_LOCAL         R4, 224   # 0x3be8
        LD_GLOBAL        R0, R8, 32   # 0x3bec
        SHLI             R1, R0, 16   # 0x3bf0
        C_MOV            R9, R0   # 0x3bf4
        ADD              R2, R1, R4, R1   # 0x3bf6
        OR               R0, R1, R4, R1   # 0x3bfa
        C_ANDN           R0, R2   # 0x3bfe
        AND              R4, R1, R4, R1   # 0x3c00
        OR               R0, R4, R0, R4   # 0x3c04
        ADDI             R4, R3, 1332   # 0x3c08
        ADD              R5, R1, R4, R1   # 0x3c0c
        OR               R6, R1, R4, R1   # 0x3c10
        C_ANDN           R6, R5   # 0x3c14
        AND              R4, R1, R4, R1   # 0x3c16
        C_OR             R4, R6   # 0x3c1a
        ADD              R6, R1, R3, R1   # 0x3c1c
        OR               R7, R1, R3, R1   # 0x3c20
        C_ANDN           R7, R6   # 0x3c24
        C_AND            R1, R3   # 0x3c26
        C_OR             R1, R7   # 0x3c28
        LD_GLOBAL        R7, R8, 48   # 0x3c2a
        MOVI             R8, 7   # 0x3c2e
        ST_GLOBAL        R8, R15, -100   # 0x3c32
        ST_GLOBAL        R7, R15, -104   # 0x3c36
        MOVI             R7, 102   # 0x3c3a
        C_MOV            R8, R7   # 0x3c3e
        C_CHWIDTH        R8, 1   # 0x3c40
        ST_GLOBAL        R8, R15, -144   # 0x3c42
        C_CHWIDTH        R8, 0   # 0x3c46
        ST_GLOBAL        R6, R15, -132   # 0x3c48
        ST_GLOBAL        R6, R15, -140   # 0x3c4c
        ST_GLOBAL        R5, R15, -116   # 0x3c50
        ST_GLOBAL        R2, R15, -124   # 0x3c54
        SHRI             R1, R1, 31   # 0x3c58
        C_MOV            R2, R9   # 0x3c5c
        ST_LOCAL         R2, 228   # 0x3c5e
        SHRI             R5, R2, 16   # 0x3c62
        ADD              R1, R5, R1, R5   # 0x3c66
        ST_GLOBAL        R1, R15, -128   # 0x3c6a
        ST_GLOBAL        R1, R15, -136   # 0x3c6e
        SHRI             R1, R4, 31   # 0x3c72
        ADD              R1, R5, R1, R5   # 0x3c76
        ST_GLOBAL        R1, R15, -112   # 0x3c7a
        SHRI             R0, R0, 31   # 0x3c7e
        ADD              R0, R5, R0, R5   # 0x3c82
        ST_GLOBAL        R0, R15, -120   # 0x3c86
        MOVI             R0, 0   # 0x3c8a
        ST_GLOBAL        R0, R15, -148   # 0x3c8e
        MOVI             R0, 666   # 0x3c92
        ST_GLOBAL        R0, R15, -108   # 0x3c96
        MOVI             R1, 666   # 0x3c9a
        MOVI             R4, 0   # 0x3c9e
        CALL             R14, 123309   # 0x3ca2
        MOVI             R15, 2   # 0x3ca6
        LD_GLOBAL        R15, R15, 24   # 0x3caa
        SRD              R3, 2   # 0x3cae
        C_ADD            R15, R3   # 0x3cb0
        SHLI             R0, R1, 16   # 0x3cb2
        ADD              R3, R0, R2, R0   # 0x3cb6
        OR               R4, R0, R2, R0   # 0x3cba
        C_ANDN           R4, R3   # 0x3cbe
        ST_GLOBAL        R3, R15, -92   # 0x3cc0
        C_AND            R0, R2   # 0x3cc4
        C_OR             R0, R4   # 0x3cc6
        SHRI             R0, R0, 31   # 0x3cc8
        SHRI             R1, R1, 16   # 0x3ccc
        ADD              R0, R1, R0, R1   # 0x3cd0
        ST_GLOBAL        R0, R15, -88   # 0x3cd4
        MOVI             R0, 65388   # 0x3cd8
        ADDI             R6, R0, 64   # 0x3cdc
        ADDI             R5, R15, -1   # 0x3ce0
        MOVI             R1, 666   # 0x3ce4
        LD_LOCAL         R2, 228   # 0x3ce8
        LD_LOCAL         R3, 224   # 0x3cec
        MOVI             R4, 0   # 0x3cf0
        CALL             R14, 124460   # 0x3cf4
        C_CHWIDTH        R2, 1   # 0x3cf8
        MOVI             R15, 2   # 0x3cfa
        LD_GLOBAL        R15, R15, 24   # 0x3cfe
        SRD              R3, 2   # 0x3d02
        C_ADD            R15, R3   # 0x3d04
        MOVI             R0, 65535   # 0x3d06
        LD_GLOBAL        R1, R15, -116   # 0x3d0a
        AND              R4, R1, R0, R1   # 0x3d0e
        SHRI             R0, R1, 16   # 0x3d12
        LD_GLOBAL        R1, R15, -112   # 0x3d16
        SHLI             R1, R1, 16   # 0x3d1a
        OR               R3, R1, R0, R1   # 0x3d1e
        LD_GLOBAL        R1, R15, -108   # 0x3d22
        LD_GLOBAL        R2, R15, -148   # 0x3d26
        C_CHWIDTH        R2, 0   # 0x3d2a
        CALL             R14, 124807   # 0x3d2c
        MOVI             R15, 2   # 0x3d30
        LD_GLOBAL        R15, R15, 24   # 0x3d34
        SRD              R3, 2   # 0x3d38
        C_ADD            R15, R3   # 0x3d3a
        MOVI             R1, 0   # 0x3d3c
        ST_GLOBAL        R1, R15, -48   # 0x3d40
        ST_GLOBAL        R1, R15, -52   # 0x3d44
        LD_GLOBAL        R0, R15, -104   # 0x3d48
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3d4c
        BRA_PRED         0, L3e80   # 0x3d50
        ADDI             R1, R15, -1   # 0x3d54
        MOVI             R8, 1   # 0x3d58
        MOVI             R2, 65388   # 0x3d5c
        MOVI             R3, 1   # 0x3d60
        CALL             R14, 128771   # 0x3d64
        C_CHWIDTH        R2, 1   # 0x3d68
        MOVI             R15, 2   # 0x3d6a
        LD_GLOBAL        R15, R15, 24   # 0x3d6e
        SRD              R3, 2   # 0x3d72
        C_ADD            R15, R3   # 0x3d74
        LD_GLOBAL        R2, R15, -52   # 0x3d76
        C_CHWIDTH        R2, 0   # 0x3d7a
        CALL             R14, 128450   # 0x3d7c
        C_CHWIDTH        R1, 1   # 0x3d80
        MOVI             R15, 2   # 0x3d82
        LD_GLOBAL        R15, R15, 24   # 0x3d86
        SRD              R3, 2   # 0x3d8a
        C_ADD            R15, R3   # 0x3d8c
        ST_GLOBAL        R1, R15, -52   # 0x3d8e
        C_CHWIDTH        R1, 0   # 0x3d92
        ADDI             R1, R15, -1   # 0x3d94
        MOVI             R2, 65388   # 0x3d98
        MOVI             R3, 65535   # 0x3d9c
        CALL             R14, 128741   # 0x3da0
        C_CHWIDTH        R2, 1   # 0x3da4
        MOVI             R15, 2   # 0x3da6
        LD_GLOBAL        R15, R15, 24   # 0x3daa
        SRD              R3, 2   # 0x3dae
        C_ADD            R15, R3   # 0x3db0
        LD_GLOBAL        R2, R15, -52   # 0x3db2
        C_CHWIDTH        R2, 0   # 0x3db6
        CALL             R14, 128420   # 0x3db8
        MOVI             R15, 2   # 0x3dbc
        LD_GLOBAL        R15, R15, 24   # 0x3dc0
        SRD              R3, 2   # 0x3dc4
        C_ADD            R15, R3   # 0x3dc6
        C_MOV            R14, R1   # 0x3dc8
        C_CHWIDTH        R14, 1   # 0x3dca
        ST_GLOBAL        R14, R15, -50   # 0x3dcc
        ST_GLOBAL        R14, R15, -52   # 0x3dd0
        C_CHWIDTH        R14, 0   # 0x3dd4
        LD_GLOBAL        R0, R15, -104   # 0x3dd6
        SETP_LT_U_NPI    P0, R0, R0, 2   # 0x3dda
        C_MOV            R13, R14   # 0x3dde
        BRA_PRED         0, L3e72   # 0x3de0
L3de4:  C_CHWIDTH        R13, 0   # 0x3de4
        ADDI             R1, R15, -1   # 0x3de6
        MOVI             R2, 65388   # 0x3dea
        MOVI             R3, 1   # 0x3dee
        CALL             R14, 128700   # 0x3df2
        C_CHWIDTH        R2, 1   # 0x3df6
        MOVI             R15, 2   # 0x3df8
        LD_GLOBAL        R15, R15, 24   # 0x3dfc
        SRD              R3, 2   # 0x3e00
        C_ADD            R15, R3   # 0x3e02
        LD_GLOBAL        R2, R15, -52   # 0x3e04
        C_CHWIDTH        R2, 0   # 0x3e08
        CALL             R14, 128379   # 0x3e0a
        C_CHWIDTH        R1, 1   # 0x3e0e
        MOVI             R15, 2   # 0x3e10
        LD_GLOBAL        R15, R15, 24   # 0x3e14
        SRD              R3, 2   # 0x3e18
        C_ADD            R15, R3   # 0x3e1a
        ST_GLOBAL        R1, R15, -52   # 0x3e1c
        C_CHWIDTH        R1, 0   # 0x3e20
        ADDI             R1, R15, -1   # 0x3e22
        MOVI             R2, 65388   # 0x3e26
        MOVI             R3, 65535   # 0x3e2a
        CALL             R14, 128670   # 0x3e2e
        C_CHWIDTH        R2, 1   # 0x3e32
        MOVI             R15, 2   # 0x3e34
        LD_GLOBAL        R15, R15, 24   # 0x3e38
        SRD              R3, 2   # 0x3e3c
        C_ADD            R15, R3   # 0x3e3e
        LD_GLOBAL        R2, R15, -52   # 0x3e40
        C_CHWIDTH        R2, 0   # 0x3e44
        CALL             R14, 128349   # 0x3e46
        MOVI             R15, 2   # 0x3e4a
        LD_GLOBAL        R15, R15, 24   # 0x3e4e
        SRD              R3, 2   # 0x3e52
        C_ADD            R15, R3   # 0x3e54
        C_ADDI           R8, 1   # 0x3e56
        LD_GLOBAL        R0, R15, -104   # 0x3e58
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x3e5c
        C_MOV            R13, R1   # 0x3e60
        C_CHWIDTH        R13, 1   # 0x3e62
        ST_GLOBAL        R13, R15, -52   # 0x3e64
        BRA_PRED         0, L3de4   # 0x3e68
        C_CHWIDTH        R14, 1   # 0x3e6c
        LD_GLOBAL        R14, R15, -50   # 0x3e6e
L3e72:  CHWIDTH_MULTI    30720, 1   # 0x3e72
        LD_GLOBAL        R12, R15, -46   # 0x3e76
        LD_GLOBAL        R11, R15, -48   # 0x3e7a
        C_BRA            L3e90   # 0x3e7e
L3e80:  C_MOV            R12, R1   # 0x3e80
        C_MOV            R11, R12   # 0x3e82
        C_CHWIDTH        R11, 1   # 0x3e84
        C_MOV            R14, R12   # 0x3e86
        C_CHWIDTH        R14, 1   # 0x3e88
        C_MOV            R13, R12   # 0x3e8a
        CHWIDTH_MULTI    12288, 1   # 0x3e8c
L3e90:  LD_LOCAL         R1, 220   # 0x3e90
        C_SHLI           R1, 3   # 0x3e94
        MOVI             R0, 2   # 0x3e96
        LD_GLOBAL        R0, R0, 44   # 0x3e9a
        C_ADD            R0, R1   # 0x3e9e
        ST_GLOBAL_SLOT   R13, 1, R0, 0, 0   # 0x3ea0
        ADDI             R1, R0, 2   # 0x3ea4
        ST_GLOBAL_SLOT   R14, 1, R1, 0, 0   # 0x3ea8
        ADDI             R1, R0, 4   # 0x3eac
        ST_GLOBAL_SLOT   R11, 1, R1, 0, 0   # 0x3eb0
        C_ADDI           R0, 6   # 0x3eb4
        ST_GLOBAL_SLOT   R12, 1, R0, 0, 0   # 0x3eb6
        C_EXIT           0   # 0x3eba
