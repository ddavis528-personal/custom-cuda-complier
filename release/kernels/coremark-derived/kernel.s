# coremark-derived: test/coremark-derived, compiled; ccv-as source, reassembled
# byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's -code-base
# (0x1000: function pointers are absolute); the kernel's entry is 0x3b94.
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
        BRA_PRED         0, L0944   # 0x051a
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
        BRA_PRED         4, L093a   # 0x06e4
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
        BRA_PRED         4, L08b8   # 0x07de
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x07e2
        BRA_PRED         0, L088e   # 0x07e6
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
        BRA_PRED         4, L088e   # 0x0814
        LD_GLOBAL_IDX    R3, R2, R0, 0, 8   # 0x0818
        LD_GLOBAL_IDX    R15, R2, R0, 0, 12   # 0x081c
        SHLI             R15, R15, 16   # 0x0820
        SHRI             R8, R3, 16   # 0x0824
        C_OR             R15, R8   # 0x0828
        LD_GLOBAL_IDX    R8, R7, R14, 0, 8   # 0x082a
        LD_GLOBAL_IDX    R11, R7, R14, 0, 12   # 0x082e
        C_AND            R3, R5   # 0x0832
        LD_GLOBAL_IDX    R12, R15, R3, 0, 1   # 0x0834
        ST_GLOBAL_IDX    R12, R15, R3, 0, 0   # 0x0838
        C_CHWIDTH        R3, 1   # 0x083c
        C_CHWIDTH        R12, 0   # 0x083e
        SHLI             R11, R11, 16   # 0x0840
        SHRI             R12, R8, 16   # 0x0844
        C_OR             R11, R12   # 0x0848
        C_CHWIDTH        R12, 2   # 0x084a
        C_AND            R8, R5   # 0x084c
        LD_GLOBAL_IDX    R12, R11, R8, 0, 1   # 0x084e
        ST_GLOBAL_IDX    R12, R11, R8, 0, 0   # 0x0852
        LD_GLOBAL_IDX    R3, R15, R3, 0, 2   # 0x0856
        C_CHWIDTH        R15, 1   # 0x085a
        LD_GLOBAL_IDX    R15, R11, R8, 0, 2   # 0x085c
        CVT_SEXT         R8, R15, R15, R15   # 0x0860
        C_CHWIDTH        R15, 0   # 0x0864
        CVT_SEXT         R15, R3, R3, R3   # 0x0866
        SETP_LT_NP       P0, R3, R8, R15   # 0x086a
        BRA_PRED         4, L088e   # 0x086e
        CHWIDTH_MULTI    8200, 0   # 0x0872
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x0876
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x087a
        SHLI             R15, R15, 16   # 0x087e
        SHRI             R8, R3, 16   # 0x0882
        OR               R13, R15, R8, R15   # 0x0886
        C_AND            R3, R5   # 0x088a
        C_BRA            L08d4   # 0x088c
L088e:  CHWIDTH_MULTI    12296, 0   # 0x088e
        LD_GLOBAL_IDX    R3, R2, R0, 0, 0   # 0x0892
        LD_GLOBAL_IDX    R15, R2, R0, 0, 4   # 0x0896
        SHLI             R15, R15, 16   # 0x089a
        SHRI             R8, R3, 16   # 0x089e
        OR               R12, R15, R8, R15   # 0x08a2
        AND              R11, R3, R5, R3   # 0x08a6
        ADDI             R9, R9, -1   # 0x08aa
        C_MOV            R13, R7   # 0x08ae
        C_MOV            R3, R14   # 0x08b0
        C_MOV            R15, R2   # 0x08b2
        C_MOV            R8, R0   # 0x08b4
        C_BRA            L08e2   # 0x08b6
L08b8:  C_CHWIDTH        R13, 0   # 0x08b8
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x08ba
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x08be
        SHLI             R15, R15, 16   # 0x08c2
        SHRI             R8, R3, 16   # 0x08c6
        OR               R13, R15, R8, R15   # 0x08ca
        C_AND            R3, R5   # 0x08ce
        MOVI             R9, 0   # 0x08d0
L08d4:  C_CHWIDTH        R12, 0   # 0x08d4
        ADDI             R10, R10, -1   # 0x08d6
        C_MOV            R12, R2   # 0x08da
        C_MOV            R11, R0   # 0x08dc
        C_MOV            R15, R7   # 0x08de
        C_MOV            R8, R14   # 0x08e0
L08e2:  SHLI             R0, R4, 16   # 0x08e2
        AND              R2, R0, R1, R0   # 0x08e6
        ADD              R7, R0, R1, R0   # 0x08ea
        C_OR             R0, R1   # 0x08ee
        C_ANDN           R0, R7   # 0x08f0
        OR               R0, R2, R0, R2   # 0x08f2
        SHRI             R0, R0, 31   # 0x08f6
        SHRI             R2, R4, 16   # 0x08fa
        ADD              R0, R2, R0, R2   # 0x08fe
        OR               R0, R7, R0, R7   # 0x0902
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x0906
        BRA_PRED         0, L078a   # 0x090a
        SHLI             R0, R15, 16   # 0x090e
        ADD              R2, R0, R8, R0   # 0x0912
        ST_GLOBAL_IDX    R2, R4, R1, 0, 0   # 0x0916
        OR               R7, R0, R8, R0   # 0x091a
        ANDN             R2, R7, R2, R7   # 0x091e
        C_AND            R0, R8   # 0x0922
        C_OR             R0, R2   # 0x0924
        SHRI             R0, R0, 31   # 0x0926
        SHRI             R2, R15, 16   # 0x092a
        ADD              R0, R2, R0, R2   # 0x092e
        ST_GLOBAL_IDX    R0, R4, R1, 0, 4   # 0x0932
        BRA              L0792   # 0x0936
L093a:  CHWIDTH_MULTI    12288, 0   # 0x093a
        LD_LOCAL         R14, 68   # 0x093e
        C_RET            224   # 0x0942
L0944:  LD_LOCAL         R1, 12   # 0x0944
        C_MOV            R9, R3   # 0x0948
        LD_LOCAL         R11, 32   # 0x094a
        BRA              L05f6   # 0x094e
        ST_LOCAL         R14, 48   # 0x0952
        ST_LOCAL         R6, 52   # 0x0956
        ST_LOCAL         R5, 56   # 0x095a
        ST_LOCAL         R3, 28   # 0x095e
        C_MOV            R0, R1   # 0x0962
        MOVI             R7, 1   # 0x0964
        SETP_LT_U_NP     P0, R1, R7, R4   # 0x0968
        MOV_P            R7, 0, R4, R4, R4   # 0x096c
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0970
        BRA_PRED         0, L0998   # 0x0974
        MOVI48           R9, 4294967295   # 0x0978
        MOVI             R3, 8   # 0x097e
L0982:  ADDI             R4, R9, 2   # 0x0982
        MUL_LO           R4, R3, R4, R4   # 0x0986
        SETP_LT_U_NP     P0, R4, R4, R0   # 0x098a
        C_ADDI           R3, 8   # 0x098e
        C_ADDI           R9, 1   # 0x0990
        BRA_PRED         0, L0982   # 0x0992
        C_BRA            L099e   # 0x0996
L0998:  MOVI48           R9, 4294967295   # 0x0998
L099e:  SHLI             R1, R2, 16   # 0x099e
        LD_LOCAL         R0, 28   # 0x09a2
        ADD              R0, R1, R0, R1   # 0x09a6
        ST_LOCAL         R1, 60   # 0x09aa
        SETP_LT_U_NP     P0, R3, R0, R1   # 0x09ae
        SHRI             R3, R2, 16   # 0x09b2
        ST_LOCAL         R3, 64   # 0x09b6
        ADDI_P           R3, 0, R3, 1   # 0x09ba
        C_NEG            R4, R0   # 0x09be
        ANDI             R1, R4, 3   # 0x09c0
        ST_LOCAL         R1, 36   # 0x09c4
        ADD              R4, R0, R1, R0   # 0x09c8
        SETP_LT_U_NP     P0, R0, R4, R0   # 0x09cc
        ADDI_P           R3, 0, R3, 1   # 0x09d0
        MUL_LO           R1, R9, R9, R9   # 0x09d4
        SHRI             R0, R1, 31   # 0x09d8
        ADD              R0, R3, R0, R3   # 0x09dc
        C_SHLI           R1, 1   # 0x09e0
        ST_LOCAL         R1, 32   # 0x09e2
        ADD              R3, R4, R1, R4   # 0x09e6
        SETP_LT_U_NP     P0, R3, R3, R4   # 0x09ea
        ADDI_P           R0, 0, R0, 1   # 0x09ee
        SETP_EQ_NPI      P0, R0, R9, 0   # 0x09f2
        BRA_PRED         0, L0ba0   # 0x09f6
        C_CHWIDTH        R0, 1   # 0x09fa
        LD_LOCAL         R1, 28   # 0x09fc
        C_MOV            R14, R1   # 0x0a00
        MOVI             R11, 0   # 0x0a02
        C_MOV            R6, R11   # 0x0a06
        SUB              R0, R6, R14, R6   # 0x0a08
        C_CHWIDTH        R0, 0   # 0x0a0c
        C_ANDI           R0, 3   # 0x0a0e
        ADD              R10, R1, R0, R1   # 0x0a10
        MOVI             R4, 1   # 0x0a14
        C_MOV            R12, R9   # 0x0a18
        C_SHLI           R12, 1   # 0x0a1a
        ANDI             R13, R9, -2   # 0x0a1c
        ANDI             R0, R9, 1   # 0x0a20
        ST_LOCAL         R0, 16   # 0x0a24
        LD_LOCAL         R0, 32   # 0x0a28
        ADD              R5, R10, R0, R10   # 0x0a2c
        MOVI             R3, 255   # 0x0a30
        C_MOV            R14, R3   # 0x0a34
        MOVI             R6, 0   # 0x0a36
        ST_LOCAL         R9, 40   # 0x0a3a
        ST_LOCAL         R12, 44   # 0x0a3e
        C_BRA            L0a54   # 0x0a42
L0a44:  C_ADD            R5, R12   # 0x0a44
        C_ADD            R10, R12   # 0x0a46
        C_ADD            R11, R9   # 0x0a48
        C_ADDI           R6, 1   # 0x0a4a
        SETP_NE_NP       P0, R1, R6, R9   # 0x0a4c
        BRA_PRED         4, L0ba0   # 0x0a50
L0a54:  SETP_EQ_NPI      P0, R3, R9, 1   # 0x0a54
        BRA_PRED         4, L0a62   # 0x0a58
        MOVI             R8, 0   # 0x0a5c
        C_BRA            L0b32   # 0x0a60
L0a62:  ST_LOCAL         R6, 24   # 0x0a62
        ST_LOCAL         R11, 20   # 0x0a66
        MOVI             R3, 0   # 0x0a6a
        C_MOV            R11, R4   # 0x0a6e
        C_SHLI           R11, 1   # 0x0a70
        MOVI             R8, 0   # 0x0a72
        MOVI48           R15, 4294901760   # 0x0a76
        ST_LOCAL         R10, 12   # 0x0a7c
L0a80:  C_MOV            R10, R4   # 0x0a80
        ADD              R4, R10, R8, R10   # 0x0a82
        MUL_LO           R12, R7, R4, R4   # 0x0a86
        SRAI             R9, R12, 31   # 0x0a8a
        SHRI             R9, R9, 16   # 0x0a8e
        MADLO            R7, R7, R4, R9   # 0x0a92
        C_AND            R7, R15   # 0x0a96
        SUB              R7, R12, R7, R12   # 0x0a98
        ADD              R9, R5, R3, R5   # 0x0a9c
        ADD              R12, R4, R7, R4   # 0x0aa0
        C_CHWIDTH        R12, 1   # 0x0aa4
        ST_GLOBAL_IDX    R12, R2, R9, 0, 0   # 0x0aa6
        C_CHWIDTH        R12, 0   # 0x0aaa
        ADDI             R12, R4, 1   # 0x0aac
        C_MOV            R6, R5   # 0x0ab0
        MUL_LO           R5, R7, R12, R12   # 0x0ab2
        SRAI             R1, R5, 31   # 0x0ab6
        SHRI             R1, R1, 16   # 0x0aba
        MAD_ACC          R1, R7, R12   # 0x0abe
        LD_LOCAL         R0, 12   # 0x0ac0
        ADD              R12, R0, R3, R0   # 0x0ac4
        C_MOV            R0, R13   # 0x0ac8
        ADD              R13, R11, R3, R11   # 0x0aca
        ADD              R7, R13, R7, R13   # 0x0ace
        C_CHWIDTH        R7, 1   # 0x0ad2
        AND              R7, R7, R14, R7   # 0x0ad4
        ST_GLOBAL_IDX    R7, R2, R12, 0, 0   # 0x0ad8
        C_CHWIDTH        R7, 0   # 0x0adc
        C_AND            R1, R15   # 0x0ade
        SUB              R7, R5, R1, R5   # 0x0ae0
        C_CHWIDTH        R5, 1   # 0x0ae4
        ADDI             R1, R9, 2   # 0x0ae6
        C_ADD            R4, R7   # 0x0aea
        ADDI             R5, R4, 1   # 0x0aec
        C_MOV            R4, R10   # 0x0af0
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0af2
        ADD              R1, R13, R7, R13   # 0x0af6
        C_MOV            R13, R0   # 0x0afa
        ADDI             R5, R1, 2   # 0x0afc
        AND              R5, R5, R14, R5   # 0x0b00
        ADDI             R1, R12, 2   # 0x0b04
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0b08
        C_CHWIDTH        R5, 0   # 0x0b0c
        C_MOV            R5, R6   # 0x0b0e
        C_ADDI           R3, 4   # 0x0b10
        C_ADDI           R8, 2   # 0x0b12
        SETP_NE_NP       P0, R1, R13, R8   # 0x0b14
        BRA_PRED         0, L0a80   # 0x0b18
        C_ADD            R4, R8   # 0x0b1c
        LD_LOCAL         R9, 40   # 0x0b1e
        LD_LOCAL         R11, 20   # 0x0b22
        LD_LOCAL         R12, 44   # 0x0b26
        LD_LOCAL         R10, 12   # 0x0b2a
        LD_LOCAL         R6, 24   # 0x0b2e
L0b32:  LD_LOCAL         R0, 16   # 0x0b32
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0b36
        BRA_PRED         0, L0a44   # 0x0b3a
        MUL_LO           R1, R6, R9, R9   # 0x0b3e
        MUL_LO           R3, R7, R4, R4   # 0x0b42
        MOVI48           R0, 4294901760   # 0x0b46
        C_MOV            R15, R4   # 0x0b4c
        SRAI             R4, R3, 31   # 0x0b4e
        SHRI             R4, R4, 16   # 0x0b52
        MAD_ACC          R4, R7, R15   # 0x0b56
        C_AND            R4, R0   # 0x0b58
        SUB              R7, R3, R4, R3   # 0x0b5a
        LD_LOCAL         R3, 28   # 0x0b5e
        LD_LOCAL         R4, 36   # 0x0b62
        C_ADD            R3, R4   # 0x0b66
        ADD              R1, R8, R1, R8   # 0x0b68
        C_SHLI           R1, 1   # 0x0b6c
        ADD              R1, R3, R1, R3   # 0x0b6e
        LD_LOCAL         R3, 32   # 0x0b72
        ADD              R3, R1, R3, R1   # 0x0b76
        ADD              R4, R7, R15, R7   # 0x0b7a
        C_MOV            R0, R5   # 0x0b7e
        C_MOV            R5, R4   # 0x0b80
        C_CHWIDTH        R5, 1   # 0x0b82
        ST_GLOBAL_IDX    R5, R2, R3, 0, 0   # 0x0b84
        ADD              R3, R4, R15, R4   # 0x0b88
        C_MOV            R4, R15   # 0x0b8c
        AND              R5, R3, R14, R3   # 0x0b8e
        ST_GLOBAL_IDX    R5, R2, R1, 0, 0   # 0x0b92
        C_CHWIDTH        R5, 0   # 0x0b96
        C_MOV            R5, R0   # 0x0b98
        C_ADDI           R4, 1   # 0x0b9a
        BRA              L0a44   # 0x0b9c
L0ba0:  LD_LOCAL         R0, 28   # 0x0ba0
        LD_LOCAL         R1, 36   # 0x0ba4
        C_ADD            R0, R1   # 0x0ba8
        LD_LOCAL         R7, 60   # 0x0baa
        ADD              R1, R7, R0, R7   # 0x0bae
        OR               R2, R7, R0, R7   # 0x0bb2
        C_ANDN           R2, R1   # 0x0bb6
        AND              R3, R7, R0, R7   # 0x0bb8
        OR               R2, R3, R2, R3   # 0x0bbc
        LD_LOCAL         R3, 32   # 0x0bc0
        C_ADD            R0, R3   # 0x0bc4
        ADD              R3, R0, R3, R0   # 0x0bc6
        ADD              R4, R7, R3, R7   # 0x0bca
        C_NEG            R4, R4   # 0x0bce
        C_ANDI           R4, 3   # 0x0bd0
        C_ADD            R3, R4   # 0x0bd2
        ADD              R4, R7, R0, R7   # 0x0bd4
        OR               R5, R7, R0, R7   # 0x0bd8
        C_ANDN           R5, R4   # 0x0bdc
        AND              R0, R7, R0, R7   # 0x0bde
        C_OR             R0, R5   # 0x0be2
        LD_LOCAL         R5, 52   # 0x0be4
        LD_LOCAL         R6, 56   # 0x0be8
        ST_GLOBAL_IDX    R1, R6, R5, 0, 8   # 0x0bec
        ST_GLOBAL_IDX    R4, R6, R5, 0, 16   # 0x0bf0
        SHRI             R1, R2, 31   # 0x0bf4
        LD_LOCAL         R2, 64   # 0x0bf8
        ADD              R1, R2, R1, R2   # 0x0bfc
        ST_GLOBAL_IDX    R1, R6, R5, 0, 12   # 0x0c00
        SHRI             R0, R0, 31   # 0x0c04
        ADD              R0, R2, R0, R2   # 0x0c08
        ST_GLOBAL_IDX    R0, R6, R5, 0, 20   # 0x0c0c
        ADD              R0, R7, R3, R7   # 0x0c10
        ST_GLOBAL_IDX    R0, R6, R5, 0, 24   # 0x0c14
        OR               R1, R7, R3, R7   # 0x0c18
        ANDN             R0, R1, R0, R1   # 0x0c1c
        AND              R1, R7, R3, R7   # 0x0c20
        OR               R0, R1, R0, R1   # 0x0c24
        SHRI             R0, R0, 31   # 0x0c28
        ADD              R0, R2, R0, R2   # 0x0c2c
        ST_GLOBAL_IDX    R0, R6, R5, 0, 28   # 0x0c30
        ST_GLOBAL_IDX    R9, R6, R5, 0, 0   # 0x0c34
        LD_LOCAL         R14, 48   # 0x0c38
        C_MOV            R1, R9   # 0x0c3c
        C_RET            224   # 0x0c3e
        ST_LOCAL         R14, 12   # 0x0c40
        MOVI             R0, 0   # 0x0c44
        ST_LOCAL         R1, 16   # 0x0c48
        ADDI             R5, R1, -1   # 0x0c4c
        SETP_LT_U_NPI    P0, R6, R5, 2   # 0x0c50
        BRA_PRED         0, L0d7a   # 0x0c54
        C_CHWIDTH        R2, 1   # 0x0c58
        MOVI             R9, 0   # 0x0c5a
        MOVI             R6, 2   # 0x0c5e
        MOVI             R7, 65535   # 0x0c62
        MOVI             R10, 0   # 0x0c66
        MOVI             R8, 0   # 0x0c6a
        C_BRA            L0cac   # 0x0c6e
L0c70:  C_CHWIDTH        R14, 0   # 0x0c70
        MOVI             R8, 8   # 0x0c72
        MOVI             R9, 96   # 0x0c76
L0c7a:  ANDI             R1, R2, 24   # 0x0c7a
        ADD              R1, R9, R1, R9   # 0x0c7e
        LD_GLOBAL        R14, R6, 28   # 0x0c82
        LD_GLOBAL_IDX    R15, R14, R1, 0, 0   # 0x0c86
        LD_GLOBAL_IDX    R1, R14, R1, 0, 4   # 0x0c8a
        SHLI             R1, R1, 16   # 0x0c8e
        SHRI             R14, R15, 16   # 0x0c92
        OR               R9, R1, R14, R1   # 0x0c96
        AND              R10, R15, R7, R15   # 0x0c9a
        ADD              R1, R0, R8, R0   # 0x0c9e
        C_ADDI           R1, 1   # 0x0ca2
        SETP_LT_U_NP     P0, R1, R1, R5   # 0x0ca4
        BRA_PRED         4, L0d7a   # 0x0ca8
L0cac:  SETP_EQ_NPI      P0, R11, R8, 0   # 0x0cac
        BRA_PRED         0, L0d30   # 0x0cb0
        SETP_LT_U_NPI    P0, R11, R8, 4   # 0x0cb4
        BRA_PRED         0, L0d1e   # 0x0cb8
        ADD              R11, R4, R0, R4   # 0x0cbc
        MOVI             R12, 0   # 0x0cc0
L0cc4:  C_CHWIDTH        R14, 2   # 0x0cc4
        ADD              R13, R11, R12, R11   # 0x0cc6
        ADD              R15, R12, R10, R12   # 0x0cca
        LD_GLOBAL_IDX    R14, R9, R15, 0, 0   # 0x0cce
        ST_GLOBAL_IDX    R14, R3, R13, 0, 0   # 0x0cd2
        C_CHWIDTH        R14, 0   # 0x0cd6
        ADDI             R14, R15, 1   # 0x0cd8
        C_CHWIDTH        R14, 2   # 0x0cdc
        LD_GLOBAL_IDX    R14, R9, R14, 0, 0   # 0x0cde
        ADDI             R1, R13, 1   # 0x0ce2
        ST_GLOBAL_IDX    R14, R3, R1, 0, 0   # 0x0ce6
        C_CHWIDTH        R14, 0   # 0x0cea
        ADDI             R1, R15, 2   # 0x0cec
        C_CHWIDTH        R1, 2   # 0x0cf0
        LD_GLOBAL_IDX    R1, R9, R1, 0, 0   # 0x0cf2
        ADDI             R14, R13, 2   # 0x0cf6
        ST_GLOBAL_IDX    R1, R3, R14, 0, 0   # 0x0cfa
        C_CHWIDTH        R1, 0   # 0x0cfe
        ADDI             R1, R15, 3   # 0x0d00
        C_CHWIDTH        R1, 2   # 0x0d04
        LD_GLOBAL_IDX    R1, R9, R1, 0, 0   # 0x0d06
        ADDI             R14, R13, 3   # 0x0d0a
        ST_GLOBAL_IDX    R1, R3, R14, 0, 0   # 0x0d0e
        C_ADDI           R12, 4   # 0x0d12
        SETP_NE_NP       P0, R1, R8, R12   # 0x0d14
        C_CHWIDTH        R1, 0   # 0x0d18
        BRA_PRED         0, L0cc4   # 0x0d1a
L0d1e:  C_ADD            R0, R8   # 0x0d1e
        ADD              R1, R0, R4, R0   # 0x0d20
        MOVI             R14, 44   # 0x0d24
        C_CHWIDTH        R14, 2   # 0x0d28
        ST_GLOBAL_IDX    R14, R3, R1, 0, 0   # 0x0d2a
        C_ADDI           R0, 1   # 0x0d2e
L0d30:  C_CHWIDTH        R2, 1   # 0x0d30
        ADDI             R2, R2, 1   # 0x0d32
        C_CHWIDTH        R2, 0   # 0x0d36
        ANDI             R10, R2, 7   # 0x0d38
        MOVI             R8, 4   # 0x0d3c
        SETP_LT_NP       P0, R1, R8, R10   # 0x0d40
        BRA_PRED         0, L0d62   # 0x0d44
        C_CHWIDTH        R14, 0   # 0x0d48
        MOVI             R9, 0   # 0x0d4a
        SETP_LT_U_NPI    P0, R1, R10, 3   # 0x0d4e
        BRA_PRED         0, L0c7a   # 0x0d52
        C_CHWIDTH        R14, 0   # 0x0d56
        MOVI             R8, 8   # 0x0d58
        MOVI             R9, 32   # 0x0d5c
        C_BRA            L0c7a   # 0x0d60
L0d62:  ADDI             R1, R10, -5   # 0x0d62
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x0d66
        BRA_PRED         4, L0c70   # 0x0d6a
        C_CHWIDTH        R14, 0   # 0x0d6e
        MOVI             R8, 8   # 0x0d70
        MOVI             R9, 64   # 0x0d74
        C_BRA            L0c7a   # 0x0d78
L0d7a:  LD_LOCAL         R1, 16   # 0x0d7a
        SETP_LE_U_NP     P0, R2, R1, R0   # 0x0d7e
        BRA_PRED         0, L0e22   # 0x0d82
        SUB              R2, R1, R0, R1   # 0x0d86
        ANDI             R5, R2, 7   # 0x0d8a
        SETP_EQ_NPI      P0, R2, R5, 0   # 0x0d8e
        C_MOV            R2, R0   # 0x0d92
        BRA_PRED         0, L0db6   # 0x0d94
        MOVI             R6, 0   # 0x0d98
        C_CHWIDTH        R6, 2   # 0x0d9c
        C_MOV            R2, R0   # 0x0d9e
L0da0:  ADD              R7, R4, R2, R4   # 0x0da0
        ST_GLOBAL_IDX    R6, R3, R7, 0, 0   # 0x0da4
        C_ADDI           R2, 1   # 0x0da8
        ADDI             R5, R5, -1   # 0x0daa
        SETP_NE_NPI      P0, R7, R5, 0   # 0x0dae
        BRA_PRED         0, L0da0   # 0x0db2
L0db6:  C_SUB            R0, R1   # 0x0db6
        MOVI48           R5, 4294967288   # 0x0db8
        SETP_LT_U_NP     P0, R0, R5, R0   # 0x0dbe
        BRA_PRED         0, L0e22   # 0x0dc2
        C_CHWIDTH        R6, 0   # 0x0dc6
        ADDI             R0, R2, 7   # 0x0dc8
        C_NEG            R1, R1   # 0x0dcc
        MOVI             R2, 0   # 0x0dce
        C_CHWIDTH        R2, 2   # 0x0dd2
L0dd4:  ADD              R5, R4, R0, R4   # 0x0dd4
        ADDI             R6, R5, -7   # 0x0dd8
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0ddc
        ADDI             R6, R5, -6   # 0x0de0
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0de4
        ADDI             R6, R5, -5   # 0x0de8
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0dec
        ADDI             R6, R5, -4   # 0x0df0
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0df4
        ADDI             R6, R5, -3   # 0x0df8
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0dfc
        ADDI             R6, R5, -2   # 0x0e00
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0e04
        ADDI             R6, R5, -1   # 0x0e08
        ST_GLOBAL_IDX    R2, R3, R6, 0, 0   # 0x0e0c
        ST_GLOBAL_IDX    R2, R3, R5, 0, 0   # 0x0e10
        C_ADDI           R0, 8   # 0x0e14
        ADD              R5, R1, R0, R1   # 0x0e16
        SETP_NE_NPI      P0, R5, R5, 7   # 0x0e1a
        BRA_PRED         0, L0dd4   # 0x0e1e
L0e22:  CHWIDTH_MULTI    68, 0   # 0x0e22
        LD_LOCAL         R14, 12   # 0x0e26
        C_RET            224   # 0x0e2a
        CHWIDTH_MULTI    12, 1   # 0x0e2c
        C_MOV            R0, R1   # 0x0e30
        C_CHWIDTH        R0, 1   # 0x0e32
        XOR              R3, R0, R2, R0   # 0x0e34
        CHWIDTH_MULTI    13, 0   # 0x0e38
        C_ANDI           R3, 1   # 0x0e3c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e3e
        MOVI             R3, 40961   # 0x0e42
        C_MOV            R7, R3   # 0x0e46
        C_CHWIDTH        R3, 1   # 0x0e48
        SHRI             R2, R2, 1   # 0x0e4a
        XOR              R3, R2, R7, R2   # 0x0e4e
        C_CHWIDTH        R3, 0   # 0x0e52
        MOV_P            R2, 0, R3, R3, R3   # 0x0e54
        C_CHWIDTH        R2, 1   # 0x0e58
        SHRI             R3, R0, 1   # 0x0e5a
        C_CHWIDTH        R3, 1   # 0x0e5e
        XOR              R3, R3, R2, R3   # 0x0e60
        CHWIDTH_MULTI    12, 0   # 0x0e64
        C_ANDI           R3, 1   # 0x0e68
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e6a
        C_CHWIDTH        R3, 1   # 0x0e6e
        SHRI             R2, R2, 1   # 0x0e70
        XOR              R3, R2, R7, R2   # 0x0e74
        C_CHWIDTH        R3, 0   # 0x0e78
        MOV_P            R2, 0, R3, R3, R3   # 0x0e7a
        C_CHWIDTH        R2, 1   # 0x0e7e
        SHRI             R3, R0, 2   # 0x0e80
        C_CHWIDTH        R3, 1   # 0x0e84
        XOR              R3, R3, R2, R3   # 0x0e86
        CHWIDTH_MULTI    12, 0   # 0x0e8a
        C_ANDI           R3, 1   # 0x0e8e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e90
        C_CHWIDTH        R3, 1   # 0x0e94
        SHRI             R2, R2, 1   # 0x0e96
        XOR              R3, R2, R7, R2   # 0x0e9a
        C_CHWIDTH        R3, 0   # 0x0e9e
        MOV_P            R2, 0, R3, R3, R3   # 0x0ea0
        C_CHWIDTH        R2, 1   # 0x0ea4
        SHRI             R3, R0, 3   # 0x0ea6
        C_CHWIDTH        R3, 1   # 0x0eaa
        XOR              R3, R3, R2, R3   # 0x0eac
        CHWIDTH_MULTI    12, 0   # 0x0eb0
        C_ANDI           R3, 1   # 0x0eb4
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0eb6
        C_CHWIDTH        R3, 1   # 0x0eba
        SHRI             R2, R2, 1   # 0x0ebc
        XOR              R3, R2, R7, R2   # 0x0ec0
        C_CHWIDTH        R3, 0   # 0x0ec4
        MOV_P            R2, 0, R3, R3, R3   # 0x0ec6
        C_CHWIDTH        R2, 1   # 0x0eca
        SHRI             R3, R0, 4   # 0x0ecc
        C_CHWIDTH        R3, 1   # 0x0ed0
        XOR              R3, R3, R2, R3   # 0x0ed2
        CHWIDTH_MULTI    12, 0   # 0x0ed6
        C_ANDI           R3, 1   # 0x0eda
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0edc
        C_CHWIDTH        R3, 1   # 0x0ee0
        SHRI             R2, R2, 1   # 0x0ee2
        XOR              R3, R2, R7, R2   # 0x0ee6
        C_CHWIDTH        R3, 0   # 0x0eea
        MOV_P            R2, 0, R3, R3, R3   # 0x0eec
        C_CHWIDTH        R2, 1   # 0x0ef0
        SHRI             R3, R0, 5   # 0x0ef2
        C_CHWIDTH        R3, 1   # 0x0ef6
        XOR              R3, R3, R2, R3   # 0x0ef8
        CHWIDTH_MULTI    12, 0   # 0x0efc
        C_ANDI           R3, 1   # 0x0f00
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f02
        C_CHWIDTH        R3, 1   # 0x0f06
        SHRI             R2, R2, 1   # 0x0f08
        XOR              R3, R2, R7, R2   # 0x0f0c
        C_CHWIDTH        R3, 0   # 0x0f10
        MOV_P            R2, 0, R3, R3, R3   # 0x0f12
        C_CHWIDTH        R2, 1   # 0x0f16
        SHRI             R3, R0, 6   # 0x0f18
        C_CHWIDTH        R3, 1   # 0x0f1c
        XOR              R3, R3, R2, R3   # 0x0f1e
        CHWIDTH_MULTI    12, 0   # 0x0f22
        C_ANDI           R3, 1   # 0x0f26
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f28
        C_CHWIDTH        R3, 1   # 0x0f2c
        SHRI             R2, R2, 1   # 0x0f2e
        XOR              R3, R2, R7, R2   # 0x0f32
        C_CHWIDTH        R3, 0   # 0x0f36
        MOV_P            R2, 0, R3, R3, R3   # 0x0f38
        MOVI             R3, 128   # 0x0f3c
        C_MOV            R6, R3   # 0x0f40
        C_CHWIDTH        R3, 1   # 0x0f42
        AND              R3, R0, R6, R0   # 0x0f44
        C_CHWIDTH        R3, 0   # 0x0f48
        SHRI             R3, R3, 7   # 0x0f4a
        ANDI             R4, R2, 1   # 0x0f4e
        C_CHWIDTH        R2, 1   # 0x0f52
        C_CHWIDTH        R2, 0   # 0x0f54
        SETP_EQ_NP       P0, R3, R3, R4   # 0x0f56
        C_CHWIDTH        R3, 1   # 0x0f5a
        SHRI             R2, R2, 1   # 0x0f5c
        XOR              R3, R2, R7, R2   # 0x0f60
        C_CHWIDTH        R3, 0   # 0x0f64
        MOV_P            R3, 0, R2, R2, R2   # 0x0f66
        C_CHWIDTH        R3, 1   # 0x0f6a
        SHRI             R2, R0, 8   # 0x0f6c
        C_CHWIDTH        R2, 1   # 0x0f70
        XOR              R2, R3, R2, R3   # 0x0f72
        CHWIDTH_MULTI    12, 0   # 0x0f76
        C_ANDI           R2, 1   # 0x0f7a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0f7c
        SHRI             R2, R3, 1   # 0x0f80
        C_CHWIDTH        R3, 1   # 0x0f84
        XOR              R3, R2, R7, R2   # 0x0f86
        C_CHWIDTH        R3, 0   # 0x0f8a
        MOV_P            R2, 0, R3, R3, R3   # 0x0f8c
        C_CHWIDTH        R2, 1   # 0x0f90
        SHRI             R3, R0, 9   # 0x0f92
        C_CHWIDTH        R3, 1   # 0x0f96
        XOR              R3, R3, R2, R3   # 0x0f98
        CHWIDTH_MULTI    12, 0   # 0x0f9c
        C_ANDI           R3, 1   # 0x0fa0
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fa2
        C_CHWIDTH        R3, 1   # 0x0fa6
        SHRI             R2, R2, 1   # 0x0fa8
        XOR              R3, R2, R7, R2   # 0x0fac
        C_CHWIDTH        R3, 0   # 0x0fb0
        MOV_P            R2, 0, R3, R3, R3   # 0x0fb2
        C_CHWIDTH        R2, 1   # 0x0fb6
        SHRI             R3, R0, 10   # 0x0fb8
        C_CHWIDTH        R3, 1   # 0x0fbc
        XOR              R3, R3, R2, R3   # 0x0fbe
        CHWIDTH_MULTI    12, 0   # 0x0fc2
        C_ANDI           R3, 1   # 0x0fc6
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fc8
        C_CHWIDTH        R3, 1   # 0x0fcc
        SHRI             R2, R2, 1   # 0x0fce
        XOR              R3, R2, R7, R2   # 0x0fd2
        C_CHWIDTH        R3, 0   # 0x0fd6
        MOV_P            R2, 0, R3, R3, R3   # 0x0fd8
        C_CHWIDTH        R2, 1   # 0x0fdc
        SHRI             R3, R0, 11   # 0x0fde
        C_CHWIDTH        R3, 1   # 0x0fe2
        XOR              R3, R3, R2, R3   # 0x0fe4
        CHWIDTH_MULTI    12, 0   # 0x0fe8
        C_ANDI           R3, 1   # 0x0fec
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fee
        C_CHWIDTH        R3, 1   # 0x0ff2
        SHRI             R2, R2, 1   # 0x0ff4
        XOR              R3, R2, R7, R2   # 0x0ff8
        C_CHWIDTH        R3, 0   # 0x0ffc
        MOV_P            R2, 0, R3, R3, R3   # 0x0ffe
        C_CHWIDTH        R2, 1   # 0x1002
        SHRI             R3, R0, 12   # 0x1004
        C_CHWIDTH        R3, 1   # 0x1008
        XOR              R3, R3, R2, R3   # 0x100a
        CHWIDTH_MULTI    12, 0   # 0x100e
        C_ANDI           R3, 1   # 0x1012
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1014
        C_CHWIDTH        R3, 1   # 0x1018
        SHRI             R2, R2, 1   # 0x101a
        XOR              R3, R2, R7, R2   # 0x101e
        C_CHWIDTH        R3, 0   # 0x1022
        MOV_P            R2, 0, R3, R3, R3   # 0x1024
        C_CHWIDTH        R2, 1   # 0x1028
        SHRI             R3, R0, 13   # 0x102a
        C_CHWIDTH        R3, 1   # 0x102e
        XOR              R3, R3, R2, R3   # 0x1030
        CHWIDTH_MULTI    12, 0   # 0x1034
        C_ANDI           R3, 1   # 0x1038
        SETP_NE_NPI      P0, R3, R3, 0   # 0x103a
        C_CHWIDTH        R3, 1   # 0x103e
        SHRI             R2, R2, 1   # 0x1040
        XOR              R3, R2, R7, R2   # 0x1044
        C_CHWIDTH        R3, 0   # 0x1048
        MOV_P            R2, 0, R3, R3, R3   # 0x104a
        C_CHWIDTH        R2, 1   # 0x104e
        SHRI             R3, R0, 14   # 0x1050
        C_CHWIDTH        R3, 1   # 0x1054
        XOR              R3, R3, R2, R3   # 0x1056
        CHWIDTH_MULTI    12, 0   # 0x105a
        C_ANDI           R3, 1   # 0x105e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x1060
        C_CHWIDTH        R3, 1   # 0x1064
        SHRI             R2, R2, 1   # 0x1066
        XOR              R3, R2, R7, R2   # 0x106a
        C_CHWIDTH        R3, 0   # 0x106e
        MOV_P            R2, 0, R3, R3, R3   # 0x1070
        SHRI             R0, R0, 15   # 0x1074
        ANDI             R3, R2, 1   # 0x1078
        C_CHWIDTH        R2, 1   # 0x107c
        C_CHWIDTH        R2, 0   # 0x107e
        SETP_EQ_NP       P0, R0, R0, R3   # 0x1080
        SHRI             R0, R2, 1   # 0x1084
        C_CHWIDTH        R2, 1   # 0x1088
        XOR              R2, R0, R7, R0   # 0x108a
        C_CHWIDTH        R2, 0   # 0x108e
        MOV_P            R2, 0, R0, R0, R0   # 0x1090
        C_CHWIDTH        R2, 1   # 0x1094
        SHRI             R0, R1, 16   # 0x1096
        C_MOV            R5, R0   # 0x109a
        C_CHWIDTH        R0, 1   # 0x109c
        XOR              R0, R2, R5, R2   # 0x109e
        CHWIDTH_MULTI    5, 0   # 0x10a2
        C_ANDI           R0, 1   # 0x10a6
        SETP_NE_NPI      P0, R0, R0, 0   # 0x10a8
        SHRI             R0, R2, 1   # 0x10ac
        C_CHWIDTH        R2, 1   # 0x10b0
        XOR              R2, R0, R7, R0   # 0x10b2
        C_CHWIDTH        R2, 0   # 0x10b6
        MOV_P            R0, 0, R2, R2, R2   # 0x10b8
        SHRI             R2, R1, 17   # 0x10bc
        C_XOR            R2, R0   # 0x10c0
        C_CHWIDTH        R0, 1   # 0x10c2
        C_CHWIDTH        R0, 0   # 0x10c4
        C_ANDI           R2, 1   # 0x10c6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x10c8
        C_CHWIDTH        R2, 1   # 0x10cc
        SHRI             R0, R0, 1   # 0x10ce
        XOR              R2, R0, R7, R0   # 0x10d2
        C_CHWIDTH        R2, 0   # 0x10d6
        MOV_P            R0, 0, R2, R2, R2   # 0x10d8
        SHRI             R2, R1, 18   # 0x10dc
        C_XOR            R2, R0   # 0x10e0
        C_CHWIDTH        R0, 1   # 0x10e2
        C_CHWIDTH        R0, 0   # 0x10e4
        C_ANDI           R2, 1   # 0x10e6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x10e8
        C_CHWIDTH        R2, 1   # 0x10ec
        SHRI             R0, R0, 1   # 0x10ee
        XOR              R2, R0, R7, R0   # 0x10f2
        C_CHWIDTH        R2, 0   # 0x10f6
        MOV_P            R0, 0, R2, R2, R2   # 0x10f8
        SHRI             R2, R1, 19   # 0x10fc
        C_XOR            R2, R0   # 0x1100
        C_CHWIDTH        R0, 1   # 0x1102
        C_CHWIDTH        R0, 0   # 0x1104
        C_ANDI           R2, 1   # 0x1106
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1108
        C_CHWIDTH        R2, 1   # 0x110c
        SHRI             R0, R0, 1   # 0x110e
        XOR              R2, R0, R7, R0   # 0x1112
        C_CHWIDTH        R2, 0   # 0x1116
        MOV_P            R0, 0, R2, R2, R2   # 0x1118
        SHRI             R2, R1, 20   # 0x111c
        C_XOR            R2, R0   # 0x1120
        C_CHWIDTH        R0, 1   # 0x1122
        C_CHWIDTH        R0, 0   # 0x1124
        C_ANDI           R2, 1   # 0x1126
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1128
        C_CHWIDTH        R2, 1   # 0x112c
        SHRI             R0, R0, 1   # 0x112e
        XOR              R2, R0, R7, R0   # 0x1132
        C_CHWIDTH        R2, 0   # 0x1136
        MOV_P            R0, 0, R2, R2, R2   # 0x1138
        SHRI             R2, R1, 21   # 0x113c
        C_XOR            R2, R0   # 0x1140
        C_CHWIDTH        R0, 1   # 0x1142
        C_CHWIDTH        R0, 0   # 0x1144
        C_ANDI           R2, 1   # 0x1146
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1148
        C_CHWIDTH        R2, 1   # 0x114c
        SHRI             R0, R0, 1   # 0x114e
        XOR              R2, R0, R7, R0   # 0x1152
        C_CHWIDTH        R2, 0   # 0x1156
        MOV_P            R0, 0, R2, R2, R2   # 0x1158
        SHRI             R2, R1, 22   # 0x115c
        C_XOR            R2, R0   # 0x1160
        C_CHWIDTH        R0, 1   # 0x1162
        C_CHWIDTH        R0, 0   # 0x1164
        C_ANDI           R2, 1   # 0x1166
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1168
        C_CHWIDTH        R2, 1   # 0x116c
        SHRI             R0, R0, 1   # 0x116e
        XOR              R2, R0, R7, R0   # 0x1172
        C_CHWIDTH        R2, 0   # 0x1176
        MOV_P            R0, 0, R2, R2, R2   # 0x1178
        C_CHWIDTH        R2, 1   # 0x117c
        AND              R2, R5, R6, R5   # 0x117e
        C_CHWIDTH        R2, 0   # 0x1182
        SHRI             R2, R2, 7   # 0x1184
        ANDI             R3, R0, 1   # 0x1188
        C_CHWIDTH        R0, 1   # 0x118c
        C_CHWIDTH        R0, 0   # 0x118e
        SETP_EQ_NP       P0, R2, R2, R3   # 0x1190
        C_CHWIDTH        R2, 1   # 0x1194
        SHRI             R0, R0, 1   # 0x1196
        XOR              R2, R0, R7, R0   # 0x119a
        C_CHWIDTH        R2, 0   # 0x119e
        MOV_P            R2, 0, R0, R0, R0   # 0x11a0
        SHRI             R0, R1, 24   # 0x11a4
        XOR              R0, R2, R0, R2   # 0x11a8
        C_CHWIDTH        R2, 1   # 0x11ac
        C_CHWIDTH        R2, 0   # 0x11ae
        C_ANDI           R0, 1   # 0x11b0
        SETP_NE_NPI      P0, R0, R0, 0   # 0x11b2
        SHRI             R0, R2, 1   # 0x11b6
        C_CHWIDTH        R2, 1   # 0x11ba
        XOR              R2, R0, R7, R0   # 0x11bc
        C_CHWIDTH        R2, 0   # 0x11c0
        MOV_P            R0, 0, R2, R2, R2   # 0x11c2
        SHRI             R2, R1, 25   # 0x11c6
        C_XOR            R2, R0   # 0x11ca
        C_CHWIDTH        R0, 1   # 0x11cc
        C_CHWIDTH        R0, 0   # 0x11ce
        C_ANDI           R2, 1   # 0x11d0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11d2
        C_CHWIDTH        R2, 1   # 0x11d6
        SHRI             R0, R0, 1   # 0x11d8
        XOR              R2, R0, R7, R0   # 0x11dc
        C_CHWIDTH        R2, 0   # 0x11e0
        MOV_P            R0, 0, R2, R2, R2   # 0x11e2
        SHRI             R2, R1, 26   # 0x11e6
        C_XOR            R2, R0   # 0x11ea
        C_CHWIDTH        R0, 1   # 0x11ec
        C_CHWIDTH        R0, 0   # 0x11ee
        C_ANDI           R2, 1   # 0x11f0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11f2
        C_CHWIDTH        R2, 1   # 0x11f6
        SHRI             R0, R0, 1   # 0x11f8
        XOR              R2, R0, R7, R0   # 0x11fc
        C_CHWIDTH        R2, 0   # 0x1200
        MOV_P            R0, 0, R2, R2, R2   # 0x1202
        SHRI             R2, R1, 27   # 0x1206
        C_XOR            R2, R0   # 0x120a
        C_CHWIDTH        R0, 1   # 0x120c
        C_CHWIDTH        R0, 0   # 0x120e
        C_ANDI           R2, 1   # 0x1210
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1212
        C_CHWIDTH        R2, 1   # 0x1216
        SHRI             R0, R0, 1   # 0x1218
        XOR              R2, R0, R7, R0   # 0x121c
        C_CHWIDTH        R2, 0   # 0x1220
        MOV_P            R0, 0, R2, R2, R2   # 0x1222
        SHRI             R2, R1, 28   # 0x1226
        C_XOR            R2, R0   # 0x122a
        C_CHWIDTH        R0, 1   # 0x122c
        C_CHWIDTH        R0, 0   # 0x122e
        C_ANDI           R2, 1   # 0x1230
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1232
        C_CHWIDTH        R2, 1   # 0x1236
        SHRI             R0, R0, 1   # 0x1238
        XOR              R2, R0, R7, R0   # 0x123c
        C_CHWIDTH        R2, 0   # 0x1240
        MOV_P            R0, 0, R2, R2, R2   # 0x1242
        SHRI             R2, R1, 29   # 0x1246
        C_XOR            R2, R0   # 0x124a
        C_CHWIDTH        R0, 1   # 0x124c
        C_CHWIDTH        R0, 0   # 0x124e
        C_ANDI           R2, 1   # 0x1250
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1252
        C_CHWIDTH        R2, 1   # 0x1256
        SHRI             R0, R0, 1   # 0x1258
        XOR              R2, R0, R7, R0   # 0x125c
        C_CHWIDTH        R2, 0   # 0x1260
        MOV_P            R0, 0, R2, R2, R2   # 0x1262
        SHRI             R2, R1, 30   # 0x1266
        C_XOR            R2, R0   # 0x126a
        C_CHWIDTH        R0, 1   # 0x126c
        C_CHWIDTH        R0, 0   # 0x126e
        C_ANDI           R2, 1   # 0x1270
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1272
        C_CHWIDTH        R2, 1   # 0x1276
        SHRI             R0, R0, 1   # 0x1278
        XOR              R2, R0, R7, R0   # 0x127c
        C_CHWIDTH        R2, 0   # 0x1280
        MOV_P            R0, 0, R2, R2, R2   # 0x1282
        SHRI             R1, R1, 31   # 0x1286
        ANDI             R2, R0, 1   # 0x128a
        C_CHWIDTH        R0, 1   # 0x128e
        C_CHWIDTH        R0, 0   # 0x1290
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1292
        C_CHWIDTH        R1, 1   # 0x1296
        SHRI             R0, R0, 1   # 0x1298
        XOR              R1, R0, R7, R0   # 0x129c
        C_CHWIDTH        R1, 0   # 0x12a0
        MOV_P            R1, 0, R0, R0, R0   # 0x12a2
        MOVI             R0, 65535   # 0x12a6
        C_AND            R1, R0   # 0x12aa
        C_RET            224   # 0x12ac
        MOVI             R15, 2   # 0x12ae
        LD_GLOBAL        R15, R15, 24   # 0x12b2
        SRD              R0, 2   # 0x12b6
        C_ADD            R15, R0   # 0x12b8
        C_CHWIDTH        R0, 2   # 0x12ba
        ST_LOCAL         R8, 60   # 0x12bc
        ST_LOCAL         R9, 64   # 0x12c0
        ST_LOCAL         R10, 68   # 0x12c4
        ST_LOCAL         R11, 72   # 0x12c8
        ST_LOCAL         R12, 76   # 0x12cc
        ST_LOCAL         R13, 80   # 0x12d0
        ST_LOCAL         R14, 44   # 0x12d4
        ST_LOCAL         R5, 52   # 0x12d8
        C_MOV            R13, R3   # 0x12dc
        ST_LOCAL         R1, 36   # 0x12de
        C_CHWIDTH        R1, 1   # 0x12e2
        MOVI             R9, 0   # 0x12e4
        ST_GLOBAL        R9, R15, -8   # 0x12e8
        ST_GLOBAL        R9, R15, -12   # 0x12ec
        ST_GLOBAL        R9, R15, -16   # 0x12f0
        ST_GLOBAL        R9, R15, -20   # 0x12f4
        ST_GLOBAL        R9, R15, -24   # 0x12f8
        ST_GLOBAL        R9, R15, -28   # 0x12fc
        ST_GLOBAL        R9, R15, -32   # 0x1300
        ST_GLOBAL        R9, R15, -36   # 0x1304
        LD_GLOBAL_IDX    R0, R2, R13, 0, 0   # 0x1308
        C_CHWIDTH        R0, 0   # 0x130c
        LD_GLOBAL        R1, R15, -4   # 0x130e
        C_CHWIDTH        R1, 0   # 0x1312
        ST_LOCAL         R1, 48   # 0x1314
        C_MOV            R5, R6   # 0x1318
        C_MOV            R6, R0   # 0x131a
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x131c
        MOVI             R12, 0   # 0x1320
        MOVI             R0, 0   # 0x1324
        ST_LOCAL         R0, 20   # 0x1328
        ST_LOCAL         R0, 16   # 0x132c
        ST_LOCAL         R0, 12   # 0x1330
        ST_LOCAL         R0, 28   # 0x1334
        ST_LOCAL         R0, 24   # 0x1338
        BRA_PRED         0, L15bc   # 0x133c
        ST_LOCAL         R5, 56   # 0x1340
        ST_LOCAL         R4, 40   # 0x1344
        MOVI             R0, 255   # 0x1348
        C_MOV            R14, R0   # 0x134c
        MOVI             R0, 3   # 0x134e
        MOVI             R10, 5   # 0x1352
        MOVI             R1, 223   # 0x1356
        C_MOV            R7, R1   # 0x135a
        ST_LOCAL         R7, 32   # 0x135c
        MOVI             R7, 0   # 0x1360
        MOVI             R1, 0   # 0x1364
        ST_LOCAL         R1, 20   # 0x1368
        ST_LOCAL         R1, 16   # 0x136c
        ST_LOCAL         R1, 12   # 0x1370
        ST_LOCAL         R1, 28   # 0x1374
        ST_LOCAL         R1, 24   # 0x1378
        MOVI             R4, 0   # 0x137c
        C_MOV            R3, R6   # 0x1380
        MOVI             R11, 0   # 0x1382
        C_MOV            R12, R13   # 0x1386
        C_BRA            L138c   # 0x1388
L138a:  C_MOV            R12, R1   # 0x138a
L138c:  C_CHWIDTH        R5, 1   # 0x138c
        AND              R5, R3, R14, R3   # 0x138e
        C_CHWIDTH        R5, 0   # 0x1392
        SETP_NE_NPI      P0, R1, R5, 44   # 0x1394
        ADDI             R1, R12, 1   # 0x1398
        BRA_PRED         0, L13c0   # 0x139c
L13a0:  LD_GLOBAL_IDX    R3, R15, R11, 1, -36   # 0x13a0
        C_ADDI           R3, 1   # 0x13a4
        ST_GLOBAL_IDX    R3, R15, R11, 1, -36   # 0x13a6
        C_CHWIDTH        R3, 2   # 0x13aa
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x13ac
        C_CHWIDTH        R3, 0   # 0x13b0
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x13b2
        BRA_PRED         0, L15b2   # 0x13b6
        MOVI             R11, 0   # 0x13ba
        C_BRA            L138a   # 0x13be
L13c0:  SETP_LT_NP       P0, R8, R0, R11   # 0x13c0
        BRA_PRED         4, L13fe   # 0x13c4
        SETP_LT_NP       P0, R8, R10, R11   # 0x13c8
        BRA_PRED         0, L142e   # 0x13cc
        SETP_EQ_NPI      P0, R8, R11, 4   # 0x13d0
        BRA_PRED         0, L14ae   # 0x13d4
        SETP_EQ_NPI      P0, R5, R11, 5   # 0x13d8
        BRA_PRED         4, L1596   # 0x13dc
        LD_LOCAL         R5, 32   # 0x13e0
        C_CHWIDTH        R5, 1   # 0x13e4
        AND              R5, R3, R5, R3   # 0x13e6
        C_CHWIDTH        R5, 0   # 0x13ea
        SETP_NE_NPI      P0, R5, R5, 69   # 0x13ec
        BRA_PRED         0, L153a   # 0x13f0
        MOVI             R11, 3   # 0x13f4
        C_ADDI           R7, 1   # 0x13f8
        BRA              L1596   # 0x13fa
L13fe:  SETP_EQ_NPI      P0, R8, R11, 0   # 0x13fe
        BRA_PRED         0, L1470   # 0x1402
        SETP_EQ_NPI      P0, R8, R11, 2   # 0x1406
        BRA_PRED         0, L14e4   # 0x140a
        SETP_EQ_NPI      P0, R3, R11, 3   # 0x140e
        BRA_PRED         4, L1596   # 0x1412
        SETP_EQ_NPI      P0, R3, R5, 45   # 0x1416
        BRA_PRED         0, L1426   # 0x141a
        SETP_NE_NPI      P0, R3, R5, 43   # 0x141e
        BRA_PRED         0, L1572   # 0x1422
L1426:  MOVI             R11, 6   # 0x1426
        BRA              L1576   # 0x142a
L142e:  SETP_EQ_NPI      P0, R5, R11, 6   # 0x142e
        BRA_PRED         0, L14bc   # 0x1432
        SETP_EQ_NPI      P0, R5, R11, 7   # 0x1436
        BRA_PRED         4, L1596   # 0x143a
        C_CHWIDTH        R5, 1   # 0x143e
        ADDI             R5, R3, -58   # 0x1440
        C_CHWIDTH        R3, 1   # 0x1444
        AND              R3, R5, R14, R5   # 0x1446
        CHWIDTH_MULTI    40, 0   # 0x144a
        MOVI             R5, 245   # 0x144e
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x1452
        MOVI             R11, 7   # 0x1456
        BRA_PRED         0, L1596   # 0x145a
        MOVI             R11, 1   # 0x145e
        LD_LOCAL         R3, 28   # 0x1462
        C_ADDI           R3, 1   # 0x1466
        ST_LOCAL         R3, 28   # 0x1468
        BRA              L1596   # 0x146c
L1470:  C_CHWIDTH        R3, 1   # 0x1470
        ADDI             R3, R3, -58   # 0x1472
        AND              R3, R3, R14, R3   # 0x1476
        C_CHWIDTH        R3, 0   # 0x147a
        MOVI             R8, 245   # 0x147c
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x1480
        MOVI             R11, 4   # 0x1484
        BRA_PRED         0, L1590   # 0x1488
        MOVI             R11, 2   # 0x148c
        SETP_EQ_NPI      P0, R3, R5, 43   # 0x1490
        BRA_PRED         0, L1590   # 0x1494
        SETP_EQ_NPI      P0, R3, R5, 45   # 0x1498
        BRA_PRED         0, L1590   # 0x149c
        SETP_NE_NPI      P0, R3, R5, 46   # 0x14a0
        BRA_PRED         0, L1582   # 0x14a4
        MOVI             R11, 5   # 0x14a8
        C_BRA            L1590   # 0x14ac
L14ae:  SETP_NE_NPI      P0, R5, R5, 46   # 0x14ae
        BRA_PRED         0, L150a   # 0x14b2
        MOVI             R11, 5   # 0x14b6
        C_BRA            L152e   # 0x14ba
L14bc:  C_CHWIDTH        R5, 1   # 0x14bc
        ADDI             R5, R3, -58   # 0x14be
        C_CHWIDTH        R3, 1   # 0x14c2
        AND              R3, R5, R14, R5   # 0x14c4
        CHWIDTH_MULTI    40, 0   # 0x14c8
        MOVI             R5, 246   # 0x14cc
        SETP_LT_U_NP     P0, R3, R3, R5   # 0x14d0
        MOVI             R11, 7   # 0x14d4
        MOVI             R3, 1   # 0x14d8
        MOV_P            R11, 0, R3, R3, R3   # 0x14dc
        C_ADDI           R9, 1   # 0x14e0
        C_BRA            L1596   # 0x14e2
L14e4:  C_CHWIDTH        R3, 1   # 0x14e4
        ADDI             R3, R3, -58   # 0x14e6
        AND              R3, R3, R14, R3   # 0x14ea
        C_CHWIDTH        R3, 0   # 0x14ee
        MOVI             R8, 246   # 0x14f0
        SETP_LT_U_NP     P0, R3, R3, R8   # 0x14f4
        BRA_PRED         4, L1562   # 0x14f8
        SETP_EQ_NPI      P0, R3, R5, 46   # 0x14fc
        MOVI             R11, 1   # 0x1500
        MOV_P            R11, 0, R10, R10, R10   # 0x1504
        C_BRA            L1566   # 0x1508
L150a:  C_CHWIDTH        R5, 1   # 0x150a
        ADDI             R5, R3, -58   # 0x150c
        C_CHWIDTH        R3, 1   # 0x1510
        AND              R3, R5, R14, R5   # 0x1512
        CHWIDTH_MULTI    40, 0   # 0x1516
        MOVI             R5, 245   # 0x151a
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x151e
        MOVI             R11, 4   # 0x1522
        BRA_PRED         0, L1596   # 0x1526
        MOVI             R11, 1   # 0x152a
L152e:  LD_LOCAL         R3, 20   # 0x152e
        C_ADDI           R3, 1   # 0x1532
        ST_LOCAL         R3, 20   # 0x1534
        C_BRA            L1596   # 0x1538
L153a:  C_CHWIDTH        R5, 1   # 0x153a
        ADDI             R5, R3, -58   # 0x153c
        C_CHWIDTH        R3, 1   # 0x1540
        AND              R3, R5, R14, R5   # 0x1542
        CHWIDTH_MULTI    40, 0   # 0x1546
        MOVI             R5, 245   # 0x154a
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x154e
        MOVI             R11, 5   # 0x1552
        BRA_PRED         0, L1596   # 0x1556
        MOVI             R11, 1   # 0x155a
        C_ADDI           R7, 1   # 0x155e
        C_BRA            L1596   # 0x1560
L1562:  MOVI             R11, 4   # 0x1562
L1566:  LD_LOCAL         R3, 12   # 0x1566
        C_ADDI           R3, 1   # 0x156a
        ST_LOCAL         R3, 12   # 0x156c
        C_BRA            L1596   # 0x1570
L1572:  MOVI             R11, 1   # 0x1572
L1576:  LD_LOCAL         R3, 16   # 0x1576
        C_ADDI           R3, 1   # 0x157a
        ST_LOCAL         R3, 16   # 0x157c
        C_BRA            L1596   # 0x1580
L1582:  MOVI             R11, 1   # 0x1582
        LD_LOCAL         R3, 28   # 0x1586
        C_ADDI           R3, 1   # 0x158a
        ST_LOCAL         R3, 28   # 0x158c
L1590:  C_ADDI           R4, 1   # 0x1590
        ST_LOCAL         R4, 24   # 0x1592
L1596:  C_CHWIDTH        R3, 2   # 0x1596
        LD_GLOBAL_IDX    R3, R2, R12, 0, 1   # 0x1598
        C_CHWIDTH        R3, 0   # 0x159c
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x159e
        BRA_PRED         0, L13a0   # 0x15a2
        SETP_EQ_NPI      P0, R5, R11, 1   # 0x15a6
        BRA_PRED         4, L138a   # 0x15aa
        BRA              L13a0   # 0x15ae
L15b2:  C_MOV            R12, R7   # 0x15b2
        LD_LOCAL         R4, 40   # 0x15b4
        LD_LOCAL         R5, 56   # 0x15b8
L15bc:  C_CHWIDTH        R5, 1   # 0x15bc
        LD_LOCAL         R1, 36   # 0x15be
        SETP_EQ_NPI      P0, R0, R1, 0   # 0x15c2
        SHLI             R7, R2, 16   # 0x15c6
        CVT_SEXT         R14, R5, R5, R5   # 0x15ca
        C_CHWIDTH        R5, 0   # 0x15ce
        ADD              R0, R13, R1, R13   # 0x15d0
        SHRI             R5, R2, 16   # 0x15d4
        BRA_PRED         0, L166c   # 0x15d8
        C_MOV            R6, R4   # 0x15dc
        ADD              R3, R13, R7, R13   # 0x15de
        ADD              R1, R14, R7, R14   # 0x15e2
        C_ADD            R3, R14   # 0x15e6
        C_NOT            R3, R3   # 0x15e8
        C_MOV            R8, R13   # 0x15ea
L15ec:  C_CHWIDTH        R4, 2   # 0x15ec
        LD_GLOBAL_IDX    R4, R2, R8, 0, 0   # 0x15ee
        C_CHWIDTH        R4, 0   # 0x15f2
        SETP_EQ_NPI      P0, R10, R4, 44   # 0x15f4
        BRA_PRED         0, L160e   # 0x15f8
        C_CHWIDTH        R4, 1   # 0x15fc
        XOR              R4, R4, R6, R4   # 0x15fe
        C_MOV            R10, R4   # 0x1602
        C_CHWIDTH        R4, 0   # 0x1604
        C_CHWIDTH        R10, 2   # 0x1606
        ST_GLOBAL_IDX    R10, R2, R8, 0, 0   # 0x1608
        C_CHWIDTH        R10, 0   # 0x160c
L160e:  ADD              R4, R14, R8, R14   # 0x160e
        OR               R10, R7, R4, R7   # 0x1612
        C_AND            R10, R3   # 0x1616
        AND              R11, R7, R4, R7   # 0x1618
        OR               R10, R11, R10, R11   # 0x161c
        ADD              R8, R1, R8, R1   # 0x1620
        ADD              R11, R7, R0, R7   # 0x1624
        SETP_LT_U_NP     P0, R8, R8, R11   # 0x1628
        OR               R8, R7, R0, R7   # 0x162c
        C_ANDN           R8, R11   # 0x1630
        AND              R11, R7, R0, R7   # 0x1632
        OR               R8, R11, R8, R11   # 0x1636
        SHRI             R8, R8, 31   # 0x163a
        SHRI             R10, R10, 31   # 0x163e
        SETP_EQ_NP       P1, R11, R10, R8   # 0x1642
        ADD              R8, R5, R8, R5   # 0x1646
        ADD              R10, R5, R10, R5   # 0x164a
        SETP_LT_U_NP     P2, R8, R10, R8   # 0x164e
        C_SUB            R3, R14   # 0x1652
        C_MOV            R8, R4   # 0x1654
        BRA_PRED         2, L15ec   # 0x1656
        PAND             P0, 1, 0   # 0x165a
        C_MOV            R8, R4   # 0x165c
        BRA_PRED         0, L15ec   # 0x165e
        C_CHWIDTH        R1, 2   # 0x1662
        LD_GLOBAL_IDX    R1, R2, R13, 0, 0   # 0x1664
        C_CHWIDTH        R1, 0   # 0x1668
        C_MOV            R6, R1   # 0x166a
L166c:  SETP_EQ_NPI      P0, R1, R6, 0   # 0x166c
        BRA_PRED         0, L18da   # 0x1670
        ST_LOCAL         R12, 32   # 0x1674
        MOVI             R11, 0   # 0x1678
        MOVI             R1, 255   # 0x167c
        C_MOV            R4, R1   # 0x1680
        MOVI             R10, 3   # 0x1682
        MOVI             R3, 223   # 0x1686
        ST_LOCAL         R3, 40   # 0x168a
        C_MOV            R3, R13   # 0x168e
        C_BRA            L1696   # 0x1690
L1692:  C_MOV            R6, R3   # 0x1692
        C_MOV            R3, R12   # 0x1694
L1696:  C_CHWIDTH        R8, 1   # 0x1696
        AND              R8, R6, R4, R6   # 0x1698
        C_CHWIDTH        R8, 0   # 0x169c
        SETP_NE_NPI      P0, R12, R8, 44   # 0x169e
        ADDI             R12, R3, 1   # 0x16a2
        BRA_PRED         0, L16ca   # 0x16a6
L16aa:  C_CHWIDTH        R3, 2   # 0x16aa
        LD_GLOBAL_IDX    R1, R15, R11, 1, -36   # 0x16ac
        C_ADDI           R1, 1   # 0x16b0
        ST_GLOBAL_IDX    R1, R15, R11, 1, -36   # 0x16b2
        LD_GLOBAL_IDX    R3, R2, R12, 0, 0   # 0x16b6
        C_CHWIDTH        R3, 0   # 0x16ba
        SETP_EQ_NPI      P0, R1, R3, 0   # 0x16bc
        BRA_PRED         0, L18d6   # 0x16c0
        MOVI             R11, 0   # 0x16c4
        C_BRA            L1692   # 0x16c8
L16ca:  SETP_LT_NP       P0, R1, R10, R11   # 0x16ca
        BRA_PRED         4, L170a   # 0x16ce
        MOVI             R1, 5   # 0x16d2
        SETP_LT_NP       P0, R1, R1, R11   # 0x16d6
        BRA_PRED         0, L173a   # 0x16da
        SETP_EQ_NPI      P0, R1, R11, 4   # 0x16de
        BRA_PRED         0, L17be   # 0x16e2
        SETP_EQ_NPI      P0, R1, R11, 5   # 0x16e6
        BRA_PRED         4, L18ba   # 0x16ea
        LD_LOCAL         R1, 40   # 0x16ee
        C_CHWIDTH        R1, 1   # 0x16f2
        AND              R1, R6, R1, R6   # 0x16f4
        C_CHWIDTH        R1, 0   # 0x16f8
        SETP_NE_NPI      P0, R1, R1, 69   # 0x16fa
        BRA_PRED         0, L1852   # 0x16fe
        MOVI             R11, 3   # 0x1702
        BRA              L1876   # 0x1706
L170a:  SETP_EQ_NPI      P0, R1, R11, 0   # 0x170a
        BRA_PRED         0, L177c   # 0x170e
        SETP_EQ_NPI      P0, R1, R11, 2   # 0x1712
        BRA_PRED         0, L17f4   # 0x1716
        SETP_EQ_NPI      P0, R1, R11, 3   # 0x171a
        BRA_PRED         4, L18ba   # 0x171e
        SETP_EQ_NPI      P0, R1, R8, 45   # 0x1722
        BRA_PRED         0, L1732   # 0x1726
        SETP_NE_NPI      P0, R1, R8, 43   # 0x172a
        BRA_PRED         0, L1892   # 0x172e
L1732:  MOVI             R11, 6   # 0x1732
        BRA              L1896   # 0x1736
L173a:  SETP_EQ_NPI      P0, R1, R11, 6   # 0x173a
        BRA_PRED         0, L17cc   # 0x173e
        SETP_EQ_NPI      P0, R1, R11, 7   # 0x1742
        BRA_PRED         4, L18ba   # 0x1746
        CHWIDTH_MULTI    66, 1   # 0x174a
        ADDI             R6, R6, -58   # 0x174e
        AND              R1, R6, R4, R6   # 0x1752
        CHWIDTH_MULTI    66, 0   # 0x1756
        MOVI             R6, 245   # 0x175a
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x175e
        MOVI             R11, 7   # 0x1762
        BRA_PRED         0, L18ba   # 0x1766
        MOVI             R11, 1   # 0x176a
        LD_LOCAL         R1, 28   # 0x176e
        C_ADDI           R1, 1   # 0x1772
        ST_LOCAL         R1, 28   # 0x1774
        BRA              L18ba   # 0x1778
L177c:  CHWIDTH_MULTI    66, 1   # 0x177c
        ADDI             R6, R6, -58   # 0x1780
        AND              R1, R6, R4, R6   # 0x1784
        CHWIDTH_MULTI    66, 0   # 0x1788
        MOVI             R6, 245   # 0x178c
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x1790
        MOVI             R11, 4   # 0x1794
        BRA_PRED         0, L18b0   # 0x1798
        MOVI             R11, 2   # 0x179c
        SETP_EQ_NPI      P0, R1, R8, 43   # 0x17a0
        BRA_PRED         0, L18b0   # 0x17a4
        SETP_EQ_NPI      P0, R1, R8, 45   # 0x17a8
        BRA_PRED         0, L18b0   # 0x17ac
        SETP_NE_NPI      P0, R1, R8, 46   # 0x17b0
        BRA_PRED         0, L18a2   # 0x17b4
        MOVI             R11, 5   # 0x17b8
        C_BRA            L18b0   # 0x17bc
L17be:  SETP_NE_NPI      P0, R1, R8, 46   # 0x17be
        BRA_PRED         0, L1822   # 0x17c2
        MOVI             R11, 5   # 0x17c6
        C_BRA            L1846   # 0x17ca
L17cc:  CHWIDTH_MULTI    66, 1   # 0x17cc
        ADDI             R6, R6, -58   # 0x17d0
        AND              R1, R6, R4, R6   # 0x17d4
        CHWIDTH_MULTI    66, 0   # 0x17d8
        MOVI             R6, 246   # 0x17dc
        SETP_LT_U_NP     P0, R1, R1, R6   # 0x17e0
        MOVI             R11, 7   # 0x17e4
        MOVI             R1, 1   # 0x17e8
        MOV_P            R11, 0, R1, R1, R1   # 0x17ec
        C_ADDI           R9, 1   # 0x17f0
        C_BRA            L18ba   # 0x17f2
L17f4:  CHWIDTH_MULTI    66, 1   # 0x17f4
        ADDI             R6, R6, -58   # 0x17f8
        AND              R1, R6, R4, R6   # 0x17fc
        CHWIDTH_MULTI    66, 0   # 0x1800
        MOVI             R6, 246   # 0x1804
        SETP_LT_U_NP     P0, R1, R1, R6   # 0x1808
        BRA_PRED         4, L1882   # 0x180c
        SETP_EQ_NPI      P0, R1, R8, 46   # 0x1810
        MOVI             R11, 1   # 0x1814
        MOVI             R1, 5   # 0x1818
        MOV_P            R11, 0, R1, R1, R1   # 0x181c
        C_BRA            L1886   # 0x1820
L1822:  CHWIDTH_MULTI    66, 1   # 0x1822
        ADDI             R6, R6, -58   # 0x1826
        AND              R1, R6, R4, R6   # 0x182a
        CHWIDTH_MULTI    66, 0   # 0x182e
        MOVI             R6, 245   # 0x1832
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x1836
        MOVI             R11, 4   # 0x183a
        BRA_PRED         0, L18ba   # 0x183e
        MOVI             R11, 1   # 0x1842
L1846:  LD_LOCAL         R1, 20   # 0x1846
        C_ADDI           R1, 1   # 0x184a
        ST_LOCAL         R1, 20   # 0x184c
        C_BRA            L18ba   # 0x1850
L1852:  CHWIDTH_MULTI    66, 1   # 0x1852
        ADDI             R6, R6, -58   # 0x1856
        AND              R1, R6, R4, R6   # 0x185a
        CHWIDTH_MULTI    66, 0   # 0x185e
        MOVI             R6, 245   # 0x1862
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x1866
        MOVI             R11, 5   # 0x186a
        BRA_PRED         0, L18ba   # 0x186e
        MOVI             R11, 1   # 0x1872
L1876:  LD_LOCAL         R1, 32   # 0x1876
        C_ADDI           R1, 1   # 0x187a
        ST_LOCAL         R1, 32   # 0x187c
        C_BRA            L18ba   # 0x1880
L1882:  MOVI             R11, 4   # 0x1882
L1886:  LD_LOCAL         R1, 12   # 0x1886
        C_ADDI           R1, 1   # 0x188a
        ST_LOCAL         R1, 12   # 0x188c
        C_BRA            L18ba   # 0x1890
L1892:  MOVI             R11, 1   # 0x1892
L1896:  LD_LOCAL         R1, 16   # 0x1896
        C_ADDI           R1, 1   # 0x189a
        ST_LOCAL         R1, 16   # 0x189c
        C_BRA            L18ba   # 0x18a0
L18a2:  MOVI             R11, 1   # 0x18a2
        LD_LOCAL         R1, 28   # 0x18a6
        C_ADDI           R1, 1   # 0x18aa
        ST_LOCAL         R1, 28   # 0x18ac
L18b0:  LD_LOCAL         R1, 24   # 0x18b0
        C_ADDI           R1, 1   # 0x18b4
        ST_LOCAL         R1, 24   # 0x18b6
L18ba:  C_CHWIDTH        R3, 2   # 0x18ba
        LD_GLOBAL_IDX    R3, R2, R3, 0, 1   # 0x18bc
        C_CHWIDTH        R3, 0   # 0x18c0
        SETP_EQ_NPI      P0, R1, R3, 0   # 0x18c2
        BRA_PRED         0, L16aa   # 0x18c6
        SETP_EQ_NPI      P0, R1, R11, 1   # 0x18ca
        BRA_PRED         4, L1692   # 0x18ce
        BRA              L16aa   # 0x18d2
L18d6:  LD_LOCAL         R12, 32   # 0x18d6
L18da:  LD_LOCAL         R1, 36   # 0x18da
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x18de
        BRA_PRED         0, L196e   # 0x18e2
        LD_LOCAL         R1, 52   # 0x18e6
        C_MOV            R6, R1   # 0x18ea
        ADD              R3, R13, R7, R13   # 0x18ec
        ADD              R1, R14, R7, R14   # 0x18f0
        C_ADD            R3, R14   # 0x18f4
        C_NOT            R3, R3   # 0x18f6
L18f8:  C_CHWIDTH        R4, 2   # 0x18f8
        LD_GLOBAL_IDX    R4, R2, R13, 0, 0   # 0x18fa
        C_CHWIDTH        R4, 0   # 0x18fe
        SETP_EQ_NPI      P0, R8, R4, 44   # 0x1900
        BRA_PRED         0, L191a   # 0x1904
        C_CHWIDTH        R4, 1   # 0x1908
        XOR              R4, R4, R6, R4   # 0x190a
        C_MOV            R8, R4   # 0x190e
        C_CHWIDTH        R4, 0   # 0x1910
        C_CHWIDTH        R8, 2   # 0x1912
        ST_GLOBAL_IDX    R8, R2, R13, 0, 0   # 0x1914
        C_CHWIDTH        R8, 0   # 0x1918
L191a:  ADD              R4, R14, R13, R14   # 0x191a
        OR               R8, R7, R4, R7   # 0x191e
        C_AND            R8, R3   # 0x1922
        AND              R10, R7, R4, R7   # 0x1924
        OR               R8, R10, R8, R10   # 0x1928
        ADD              R10, R1, R13, R1   # 0x192c
        ADD              R11, R7, R0, R7   # 0x1930
        SETP_LT_U_NP     P0, R10, R10, R11   # 0x1934
        OR               R10, R7, R0, R7   # 0x1938
        C_ANDN           R10, R11   # 0x193c
        AND              R11, R7, R0, R7   # 0x193e
        OR               R10, R11, R10, R11   # 0x1942
        SHRI             R10, R10, 31   # 0x1946
        SHRI             R8, R8, 31   # 0x194a
        SETP_EQ_NP       P1, R11, R8, R10   # 0x194e
        ADD              R10, R5, R10, R5   # 0x1952
        ADD              R8, R5, R8, R5   # 0x1956
        SETP_LT_U_NP     P2, R8, R8, R10   # 0x195a
        C_SUB            R3, R14   # 0x195e
        C_MOV            R13, R4   # 0x1960
        BRA_PRED         2, L18f8   # 0x1962
        PAND             P0, 1, 0   # 0x1966
        C_MOV            R13, R4   # 0x1968
        BRA_PRED         0, L18f8   # 0x196a
L196e:  LD_GLOBAL        R1, R15, -36   # 0x196e
        LD_LOCAL         R2, 48   # 0x1972
        CALL             R14, 129625   # 0x1976
        MOVI             R15, 2   # 0x197a
        LD_GLOBAL        R15, R15, 24   # 0x197e
        SRD              R3, 2   # 0x1982
        C_ADD            R15, R3   # 0x1984
        C_MOV            R2, R1   # 0x1986
        LD_LOCAL         R1, 24   # 0x1988
        CALL             R14, 129614   # 0x198c
        MOVI             R15, 2   # 0x1990
        LD_GLOBAL        R15, R15, 24   # 0x1994
        SRD              R3, 2   # 0x1998
        C_ADD            R15, R3   # 0x199a
        C_MOV            R2, R1   # 0x199c
        LD_GLOBAL        R1, R15, -32   # 0x199e
        CALL             R14, 129603   # 0x19a2
        MOVI             R15, 2   # 0x19a6
        LD_GLOBAL        R15, R15, 24   # 0x19aa
        SRD              R3, 2   # 0x19ae
        C_ADD            R15, R3   # 0x19b0
        C_MOV            R2, R1   # 0x19b2
        LD_LOCAL         R1, 28   # 0x19b4
        CALL             R14, 129592   # 0x19b8
        MOVI             R15, 2   # 0x19bc
        LD_GLOBAL        R15, R15, 24   # 0x19c0
        SRD              R3, 2   # 0x19c4
        C_ADD            R15, R3   # 0x19c6
        C_MOV            R2, R1   # 0x19c8
        LD_GLOBAL        R1, R15, -28   # 0x19ca
        CALL             R14, 129581   # 0x19ce
        MOVI             R15, 2   # 0x19d2
        LD_GLOBAL        R15, R15, 24   # 0x19d6
        SRD              R3, 2   # 0x19da
        C_ADD            R15, R3   # 0x19dc
        C_MOV            R2, R1   # 0x19de
        LD_LOCAL         R1, 12   # 0x19e0
        CALL             R14, 129570   # 0x19e4
        MOVI             R15, 2   # 0x19e8
        LD_GLOBAL        R15, R15, 24   # 0x19ec
        SRD              R3, 2   # 0x19f0
        C_ADD            R15, R3   # 0x19f2
        C_MOV            R2, R1   # 0x19f4
        LD_GLOBAL        R1, R15, -24   # 0x19f6
        CALL             R14, 129559   # 0x19fa
        MOVI             R15, 2   # 0x19fe
        LD_GLOBAL        R15, R15, 24   # 0x1a02
        SRD              R3, 2   # 0x1a06
        C_ADD            R15, R3   # 0x1a08
        C_MOV            R2, R1   # 0x1a0a
        LD_LOCAL         R1, 16   # 0x1a0c
        CALL             R14, 129548   # 0x1a10
        MOVI             R15, 2   # 0x1a14
        LD_GLOBAL        R15, R15, 24   # 0x1a18
        SRD              R3, 2   # 0x1a1c
        C_ADD            R15, R3   # 0x1a1e
        C_MOV            R2, R1   # 0x1a20
        LD_GLOBAL        R1, R15, -20   # 0x1a22
        CALL             R14, 129537   # 0x1a26
        MOVI             R15, 2   # 0x1a2a
        LD_GLOBAL        R15, R15, 24   # 0x1a2e
        SRD              R3, 2   # 0x1a32
        C_ADD            R15, R3   # 0x1a34
        C_MOV            R2, R1   # 0x1a36
        LD_LOCAL         R1, 20   # 0x1a38
        CALL             R14, 129526   # 0x1a3c
        MOVI             R15, 2   # 0x1a40
        LD_GLOBAL        R15, R15, 24   # 0x1a44
        SRD              R3, 2   # 0x1a48
        C_ADD            R15, R3   # 0x1a4a
        C_MOV            R2, R1   # 0x1a4c
        LD_GLOBAL        R1, R15, -16   # 0x1a4e
        CALL             R14, 129515   # 0x1a52
        MOVI             R15, 2   # 0x1a56
        LD_GLOBAL        R15, R15, 24   # 0x1a5a
        SRD              R3, 2   # 0x1a5e
        C_ADD            R15, R3   # 0x1a60
        C_MOV            R2, R1   # 0x1a62
        C_MOV            R1, R12   # 0x1a64
        CALL             R14, 129505   # 0x1a66
        MOVI             R15, 2   # 0x1a6a
        LD_GLOBAL        R15, R15, 24   # 0x1a6e
        SRD              R3, 2   # 0x1a72
        C_ADD            R15, R3   # 0x1a74
        C_MOV            R2, R1   # 0x1a76
        LD_GLOBAL        R1, R15, -12   # 0x1a78
        CALL             R14, 129494   # 0x1a7c
        MOVI             R15, 2   # 0x1a80
        LD_GLOBAL        R15, R15, 24   # 0x1a84
        SRD              R3, 2   # 0x1a88
        C_ADD            R15, R3   # 0x1a8a
        C_MOV            R2, R1   # 0x1a8c
        C_MOV            R1, R9   # 0x1a8e
        CALL             R14, 129484   # 0x1a90
        MOVI             R15, 2   # 0x1a94
        LD_GLOBAL        R15, R15, 24   # 0x1a98
        SRD              R3, 2   # 0x1a9c
        C_ADD            R15, R3   # 0x1a9e
        C_MOV            R2, R1   # 0x1aa0
        LD_GLOBAL        R1, R15, -8   # 0x1aa2
        CALL             R14, 129473   # 0x1aa6
        MOVI             R15, 2   # 0x1aaa
        LD_GLOBAL        R15, R15, 24   # 0x1aae
        SRD              R3, 2   # 0x1ab2
        C_ADD            R15, R3   # 0x1ab4
        C_MOV            R2, R1   # 0x1ab6
        MOVI             R1, 0   # 0x1ab8
        CALL             R14, 129462   # 0x1abc
        MOVI             R15, 2   # 0x1ac0
        LD_GLOBAL        R15, R15, 24   # 0x1ac4
        SRD              R3, 2   # 0x1ac8
        C_ADD            R15, R3   # 0x1aca
        LD_LOCAL         R14, 44   # 0x1acc
        LD_LOCAL         R13, 80   # 0x1ad0
        LD_LOCAL         R12, 76   # 0x1ad4
        LD_LOCAL         R11, 72   # 0x1ad8
        LD_LOCAL         R10, 68   # 0x1adc
        LD_LOCAL         R9, 64   # 0x1ae0
        LD_LOCAL         R8, 60   # 0x1ae4
        C_RET            224   # 0x1ae8
        CHWIDTH_MULTI    7, 1   # 0x1aea
        XOR              R0, R2, R1, R2   # 0x1aee
        CHWIDTH_MULTI    7, 0   # 0x1af2
        C_ANDI           R0, 1   # 0x1af6
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1af8
        MOVI             R0, 40961   # 0x1afc
        C_MOV            R7, R0   # 0x1b00
        SHRI             R0, R2, 1   # 0x1b02
        C_CHWIDTH        R2, 1   # 0x1b06
        XOR              R2, R0, R7, R0   # 0x1b08
        C_CHWIDTH        R2, 0   # 0x1b0c
        MOV_P            R0, 0, R2, R2, R2   # 0x1b0e
        C_CHWIDTH        R0, 1   # 0x1b12
        SHRI             R2, R1, 1   # 0x1b14
        C_CHWIDTH        R2, 1   # 0x1b18
        XOR              R2, R2, R0, R2   # 0x1b1a
        CHWIDTH_MULTI    5, 0   # 0x1b1e
        C_ANDI           R2, 1   # 0x1b22
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b24
        C_CHWIDTH        R2, 1   # 0x1b28
        SHRI             R0, R0, 1   # 0x1b2a
        XOR              R2, R0, R7, R0   # 0x1b2e
        C_CHWIDTH        R2, 0   # 0x1b32
        MOV_P            R0, 0, R2, R2, R2   # 0x1b34
        C_CHWIDTH        R0, 1   # 0x1b38
        SHRI             R2, R1, 2   # 0x1b3a
        C_CHWIDTH        R2, 1   # 0x1b3e
        XOR              R2, R2, R0, R2   # 0x1b40
        CHWIDTH_MULTI    5, 0   # 0x1b44
        C_ANDI           R2, 1   # 0x1b48
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b4a
        C_CHWIDTH        R2, 1   # 0x1b4e
        SHRI             R0, R0, 1   # 0x1b50
        XOR              R2, R0, R7, R0   # 0x1b54
        C_CHWIDTH        R2, 0   # 0x1b58
        MOV_P            R0, 0, R2, R2, R2   # 0x1b5a
        C_CHWIDTH        R0, 1   # 0x1b5e
        SHRI             R2, R1, 3   # 0x1b60
        C_CHWIDTH        R2, 1   # 0x1b64
        XOR              R2, R2, R0, R2   # 0x1b66
        CHWIDTH_MULTI    5, 0   # 0x1b6a
        C_ANDI           R2, 1   # 0x1b6e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b70
        C_CHWIDTH        R2, 1   # 0x1b74
        SHRI             R0, R0, 1   # 0x1b76
        XOR              R2, R0, R7, R0   # 0x1b7a
        C_CHWIDTH        R2, 0   # 0x1b7e
        MOV_P            R0, 0, R2, R2, R2   # 0x1b80
        C_CHWIDTH        R0, 1   # 0x1b84
        SHRI             R2, R1, 4   # 0x1b86
        C_CHWIDTH        R2, 1   # 0x1b8a
        XOR              R2, R2, R0, R2   # 0x1b8c
        CHWIDTH_MULTI    5, 0   # 0x1b90
        C_ANDI           R2, 1   # 0x1b94
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b96
        C_CHWIDTH        R2, 1   # 0x1b9a
        SHRI             R0, R0, 1   # 0x1b9c
        XOR              R2, R0, R7, R0   # 0x1ba0
        C_CHWIDTH        R2, 0   # 0x1ba4
        MOV_P            R0, 0, R2, R2, R2   # 0x1ba6
        C_CHWIDTH        R0, 1   # 0x1baa
        SHRI             R2, R1, 5   # 0x1bac
        C_CHWIDTH        R2, 1   # 0x1bb0
        XOR              R2, R2, R0, R2   # 0x1bb2
        CHWIDTH_MULTI    5, 0   # 0x1bb6
        C_ANDI           R2, 1   # 0x1bba
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bbc
        C_CHWIDTH        R2, 1   # 0x1bc0
        SHRI             R0, R0, 1   # 0x1bc2
        XOR              R2, R0, R7, R0   # 0x1bc6
        C_CHWIDTH        R2, 0   # 0x1bca
        MOV_P            R0, 0, R2, R2, R2   # 0x1bcc
        C_CHWIDTH        R0, 1   # 0x1bd0
        SHRI             R2, R1, 6   # 0x1bd2
        C_CHWIDTH        R2, 1   # 0x1bd6
        XOR              R2, R2, R0, R2   # 0x1bd8
        CHWIDTH_MULTI    5, 0   # 0x1bdc
        C_ANDI           R2, 1   # 0x1be0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1be2
        C_CHWIDTH        R2, 1   # 0x1be6
        SHRI             R0, R0, 1   # 0x1be8
        XOR              R2, R0, R7, R0   # 0x1bec
        C_CHWIDTH        R2, 0   # 0x1bf0
        MOV_P            R0, 0, R2, R2, R2   # 0x1bf2
        MOVI             R2, 128   # 0x1bf6
        C_CHWIDTH        R2, 1   # 0x1bfa
        AND              R2, R1, R2, R1   # 0x1bfc
        C_CHWIDTH        R2, 0   # 0x1c00
        SHRI             R2, R2, 7   # 0x1c02
        ANDI             R3, R0, 1   # 0x1c06
        C_CHWIDTH        R0, 1   # 0x1c0a
        C_CHWIDTH        R0, 0   # 0x1c0c
        SETP_EQ_NP       P0, R2, R2, R3   # 0x1c0e
        C_CHWIDTH        R2, 1   # 0x1c12
        SHRI             R0, R0, 1   # 0x1c14
        XOR              R2, R0, R7, R0   # 0x1c18
        C_CHWIDTH        R2, 0   # 0x1c1c
        MOV_P            R2, 0, R0, R0, R0   # 0x1c1e
        C_CHWIDTH        R2, 1   # 0x1c22
        SHRI             R0, R1, 8   # 0x1c24
        C_CHWIDTH        R0, 1   # 0x1c28
        XOR              R0, R2, R0, R2   # 0x1c2a
        CHWIDTH_MULTI    5, 0   # 0x1c2e
        C_ANDI           R0, 1   # 0x1c32
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1c34
        SHRI             R0, R2, 1   # 0x1c38
        C_CHWIDTH        R2, 1   # 0x1c3c
        XOR              R2, R0, R7, R0   # 0x1c3e
        C_CHWIDTH        R2, 0   # 0x1c42
        MOV_P            R0, 0, R2, R2, R2   # 0x1c44
        C_CHWIDTH        R0, 1   # 0x1c48
        SHRI             R2, R1, 9   # 0x1c4a
        C_CHWIDTH        R2, 1   # 0x1c4e
        XOR              R2, R2, R0, R2   # 0x1c50
        CHWIDTH_MULTI    5, 0   # 0x1c54
        C_ANDI           R2, 1   # 0x1c58
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c5a
        C_CHWIDTH        R2, 1   # 0x1c5e
        SHRI             R0, R0, 1   # 0x1c60
        XOR              R2, R0, R7, R0   # 0x1c64
        C_CHWIDTH        R2, 0   # 0x1c68
        MOV_P            R0, 0, R2, R2, R2   # 0x1c6a
        C_CHWIDTH        R0, 1   # 0x1c6e
        SHRI             R2, R1, 10   # 0x1c70
        C_CHWIDTH        R2, 1   # 0x1c74
        XOR              R2, R2, R0, R2   # 0x1c76
        CHWIDTH_MULTI    5, 0   # 0x1c7a
        C_ANDI           R2, 1   # 0x1c7e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c80
        C_CHWIDTH        R2, 1   # 0x1c84
        SHRI             R0, R0, 1   # 0x1c86
        XOR              R2, R0, R7, R0   # 0x1c8a
        C_CHWIDTH        R2, 0   # 0x1c8e
        MOV_P            R0, 0, R2, R2, R2   # 0x1c90
        C_CHWIDTH        R0, 1   # 0x1c94
        SHRI             R2, R1, 11   # 0x1c96
        C_CHWIDTH        R2, 1   # 0x1c9a
        XOR              R2, R2, R0, R2   # 0x1c9c
        CHWIDTH_MULTI    5, 0   # 0x1ca0
        C_ANDI           R2, 1   # 0x1ca4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1ca6
        C_CHWIDTH        R2, 1   # 0x1caa
        SHRI             R0, R0, 1   # 0x1cac
        XOR              R2, R0, R7, R0   # 0x1cb0
        C_CHWIDTH        R2, 0   # 0x1cb4
        MOV_P            R0, 0, R2, R2, R2   # 0x1cb6
        C_CHWIDTH        R0, 1   # 0x1cba
        SHRI             R2, R1, 12   # 0x1cbc
        C_CHWIDTH        R2, 1   # 0x1cc0
        XOR              R2, R2, R0, R2   # 0x1cc2
        CHWIDTH_MULTI    5, 0   # 0x1cc6
        C_ANDI           R2, 1   # 0x1cca
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1ccc
        C_CHWIDTH        R2, 1   # 0x1cd0
        SHRI             R0, R0, 1   # 0x1cd2
        XOR              R2, R0, R7, R0   # 0x1cd6
        C_CHWIDTH        R2, 0   # 0x1cda
        MOV_P            R0, 0, R2, R2, R2   # 0x1cdc
        C_CHWIDTH        R0, 1   # 0x1ce0
        SHRI             R2, R1, 13   # 0x1ce2
        C_CHWIDTH        R2, 1   # 0x1ce6
        XOR              R2, R2, R0, R2   # 0x1ce8
        CHWIDTH_MULTI    5, 0   # 0x1cec
        C_ANDI           R2, 1   # 0x1cf0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1cf2
        C_CHWIDTH        R2, 1   # 0x1cf6
        SHRI             R0, R0, 1   # 0x1cf8
        XOR              R2, R0, R7, R0   # 0x1cfc
        C_CHWIDTH        R2, 0   # 0x1d00
        MOV_P            R0, 0, R2, R2, R2   # 0x1d02
        C_CHWIDTH        R0, 1   # 0x1d06
        SHRI             R2, R1, 14   # 0x1d08
        C_CHWIDTH        R2, 1   # 0x1d0c
        XOR              R2, R2, R0, R2   # 0x1d0e
        CHWIDTH_MULTI    5, 0   # 0x1d12
        C_ANDI           R2, 1   # 0x1d16
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1d18
        C_CHWIDTH        R2, 1   # 0x1d1c
        SHRI             R0, R0, 1   # 0x1d1e
        XOR              R2, R0, R7, R0   # 0x1d22
        C_CHWIDTH        R2, 0   # 0x1d26
        MOV_P            R0, 0, R2, R2, R2   # 0x1d28
        SHRI             R1, R1, 15   # 0x1d2c
        ANDI             R2, R0, 1   # 0x1d30
        C_CHWIDTH        R0, 1   # 0x1d34
        C_CHWIDTH        R0, 0   # 0x1d36
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1d38
        C_CHWIDTH        R1, 1   # 0x1d3c
        SHRI             R0, R0, 1   # 0x1d3e
        XOR              R1, R0, R7, R0   # 0x1d42
        C_CHWIDTH        R1, 0   # 0x1d46
        MOV_P            R1, 0, R0, R0, R0   # 0x1d48
        MOVI             R0, 65535   # 0x1d4c
        C_AND            R1, R0   # 0x1d50
        C_RET            224   # 0x1d52
        ST_LOCAL         R8, 72   # 0x1d54
        ST_LOCAL         R9, 76   # 0x1d58
        ST_LOCAL         R10, 80   # 0x1d5c
        ST_LOCAL         R11, 84   # 0x1d60
        ST_LOCAL         R12, 88   # 0x1d64
        ST_LOCAL         R13, 92   # 0x1d68
        C_MOV            R15, R14   # 0x1d6c
        C_MOV            R8, R4   # 0x1d6e
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x1d70
        SHLI             R0, R0, 16   # 0x1d74
        ST_LOCAL         R0, 44   # 0x1d78
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x1d7c
        ST_LOCAL         R0, 64   # 0x1d80
        SHRI             R0, R0, 16   # 0x1d84
        ST_LOCAL         R0, 68   # 0x1d88
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x1d8c
        SHLI             R0, R0, 16   # 0x1d90
        LD_GLOBAL_IDX    R14, R1, R2, 0, 8   # 0x1d94
        SHRI             R5, R14, 16   # 0x1d98
        C_OR             R0, R5   # 0x1d9c
        LD_GLOBAL_IDX    R5, R1, R2, 0, 28   # 0x1d9e
        SHLI             R5, R5, 16   # 0x1da2
        LD_GLOBAL_IDX    R6, R1, R2, 0, 24   # 0x1da6
        SHRI             R7, R6, 16   # 0x1daa
        OR               R4, R5, R7, R5   # 0x1dae
        ST_LOCAL         R4, 20   # 0x1db2
        MOVI             R4, 65535   # 0x1db6
        AND              R7, R14, R4, R14   # 0x1dba
        C_CHWIDTH        R14, 1   # 0x1dbe
        AND              R4, R6, R4, R6   # 0x1dc0
        ST_LOCAL         R4, 16   # 0x1dc4
        LD_GLOBAL_IDX    R5, R1, R2, 0, 0   # 0x1dc8
        MOVI             R2, 0   # 0x1dcc
        MOVI             R1, 61440   # 0x1dd0
        C_MOV            R11, R3   # 0x1dd4
        OR               R14, R11, R1, R11   # 0x1dd6
        SETP_EQ_NPI      P0, R1, R5, 0   # 0x1dda
        ANDI             R12, R5, -2   # 0x1dde
        ANDI             R1, R5, 1   # 0x1de2
        ST_LOCAL         R1, 28   # 0x1de6
        ADDI             R1, R5, -1   # 0x1dea
        ST_LOCAL         R1, 24   # 0x1dee
        CVT_SEXT         R10, R14, R14, R14   # 0x1df2
        ANDI             R9, R5, -4   # 0x1df6
        ST_LOCAL         R5, 12   # 0x1dfa
        ST_LOCAL         R9, 40   # 0x1dfe
        ST_LOCAL         R15, 48   # 0x1e02
        ST_LOCAL         R11, 52   # 0x1e06
        ST_LOCAL         R8, 56   # 0x1e0a
        BRA_PRED         0, L20d4   # 0x1e0e
        ANDI             R1, R5, 3   # 0x1e12
        MOVI             R6, 0   # 0x1e16
        C_BRA            L1e2e   # 0x1e1a
L1e1c:  C_CHWIDTH        R14, 0   # 0x1e1c
        LD_LOCAL         R3, 12   # 0x1e1e
        C_ADD            R2, R3   # 0x1e22
        C_ADDI           R6, 1   # 0x1e24
        SETP_NE_NP       P0, R3, R6, R3   # 0x1e26
        BRA_PRED         4, L1ec6   # 0x1e2a
L1e2e:  CHWIDTH_MULTI    24576, 1   # 0x1e2e
        MOVI             R3, 0   # 0x1e32
        LD_LOCAL         R5, 24   # 0x1e36
        SETP_LT_U_NPI    P0, R5, R5, 3   # 0x1e3a
        BRA_PRED         0, L1e94   # 0x1e3e
L1e42:  ADD              R5, R2, R3, R2   # 0x1e42
        C_SHLI           R5, 1   # 0x1e46
        ADD              R5, R7, R5, R7   # 0x1e48
        LD_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e4c
        ADD              R14, R14, R11, R14   # 0x1e50
        ST_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e54
        C_CHWIDTH        R14, 0   # 0x1e58
        ADDI             R14, R5, 2   # 0x1e5a
        LD_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e5e
        ADD              R13, R13, R11, R13   # 0x1e62
        ST_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e66
        ADDI             R14, R5, 4   # 0x1e6a
        LD_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e6e
        ADD              R13, R13, R11, R13   # 0x1e72
        ST_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1e76
        C_CHWIDTH        R14, 1   # 0x1e7a
        C_ADDI           R5, 6   # 0x1e7c
        LD_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e7e
        ADD              R14, R14, R11, R14   # 0x1e82
        ST_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x1e86
        C_ADDI           R3, 4   # 0x1e8a
        SETP_NE_NP       P0, R5, R9, R3   # 0x1e8c
        BRA_PRED         0, L1e42   # 0x1e90
L1e94:  SETP_EQ_NPI      P0, R5, R1, 0   # 0x1e94
        BRA_PRED         0, L1e1c   # 0x1e98
        C_CHWIDTH        R14, 0   # 0x1e9c
        C_ADD            R3, R2   # 0x1e9e
        C_MOV            R5, R1   # 0x1ea0
L1ea2:  C_MOV            R14, R3   # 0x1ea2
        C_SHLI           R14, 1   # 0x1ea4
        ADD              R14, R7, R14, R7   # 0x1ea6
        LD_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1eaa
        ADD              R13, R13, R11, R13   # 0x1eae
        ST_GLOBAL_IDX    R13, R0, R14, 0, 0   # 0x1eb2
        C_ADDI           R3, 1   # 0x1eb6
        ADDI             R5, R5, -1   # 0x1eb8
        SETP_NE_NPI      P0, R14, R5, 0   # 0x1ebc
        BRA_PRED         0, L1ea2   # 0x1ec0
        C_BRA            L1e1c   # 0x1ec4
L1ec6:  C_CHWIDTH        R11, 1   # 0x1ec6
        MOVI             R2, 0   # 0x1ec8
        CVT_SEXT         R6, R11, R11, R11   # 0x1ecc
        C_CHWIDTH        R11, 0   # 0x1ed0
        MOVI             R14, 0   # 0x1ed2
        LD_LOCAL         R11, 20   # 0x1ed6
        LD_LOCAL         R15, 16   # 0x1eda
        ST_LOCAL         R1, 36   # 0x1ede
        C_BRA            L1ef4   # 0x1ee2
L1ee4:  LD_LOCAL         R3, 12   # 0x1ee4
        C_ADD            R2, R3   # 0x1ee8
        C_ADDI           R14, 1   # 0x1eea
        SETP_NE_NP       P0, R3, R14, R3   # 0x1eec
        BRA_PRED         4, L1fd8   # 0x1ef0
L1ef4:  LD_LOCAL         R3, 24   # 0x1ef4
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1ef8
        MOVI             R5, 0   # 0x1efc
        LD_LOCAL         R1, 40   # 0x1f00
        BRA_PRED         0, L1f98   # 0x1f04
L1f08:  ADD              R3, R2, R5, R2   # 0x1f08
        C_MOV            R8, R3   # 0x1f0c
        C_SHLI           R8, 2   # 0x1f0e
        ADD              R8, R15, R8, R15   # 0x1f10
        C_MOV            R9, R3   # 0x1f14
        C_SHLI           R9, 1   # 0x1f16
        ADD              R9, R7, R9, R7   # 0x1f18
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1f1c
        CVT_SEXT         R9, R13, R13, R13   # 0x1f20
        C_MUL_LO         R9, R6   # 0x1f24
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1f26
        ADDI             R8, R3, 1   # 0x1f2a
        C_MOV            R9, R8   # 0x1f2e
        C_SHLI           R9, 2   # 0x1f30
        ADD              R9, R15, R9, R15   # 0x1f32
        C_SHLI           R8, 1   # 0x1f36
        ADD              R8, R7, R8, R7   # 0x1f38
        LD_GLOBAL_IDX    R13, R0, R8, 0, 0   # 0x1f3c
        CVT_SEXT         R8, R13, R13, R13   # 0x1f40
        C_MUL_LO         R8, R6   # 0x1f44
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1f46
        ADDI             R8, R3, 2   # 0x1f4a
        C_MOV            R9, R8   # 0x1f4e
        C_SHLI           R9, 2   # 0x1f50
        ADD              R9, R15, R9, R15   # 0x1f52
        C_SHLI           R8, 1   # 0x1f56
        ADD              R8, R7, R8, R7   # 0x1f58
        LD_GLOBAL_IDX    R13, R0, R8, 0, 0   # 0x1f5c
        CVT_SEXT         R8, R13, R13, R13   # 0x1f60
        C_MUL_LO         R8, R6   # 0x1f64
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1f66
        C_ADDI           R3, 3   # 0x1f6a
        C_MOV            R8, R3   # 0x1f6c
        C_SHLI           R8, 2   # 0x1f6e
        ADD              R8, R15, R8, R15   # 0x1f70
        C_SHLI           R3, 1   # 0x1f74
        ADD              R3, R7, R3, R7   # 0x1f76
        C_CHWIDTH        R3, 1   # 0x1f7a
        LD_GLOBAL_IDX    R3, R0, R3, 0, 0   # 0x1f7c
        CVT_SEXT         R9, R3, R3, R3   # 0x1f80
        C_CHWIDTH        R3, 0   # 0x1f84
        MUL_LO           R3, R9, R6, R6   # 0x1f86
        ST_GLOBAL_IDX    R3, R11, R8, 0, 0   # 0x1f8a
        C_ADDI           R5, 4   # 0x1f8e
        SETP_NE_NP       P0, R3, R1, R5   # 0x1f90
        BRA_PRED         0, L1f08   # 0x1f94
L1f98:  LD_LOCAL         R1, 36   # 0x1f98
        SETP_EQ_NPI      P0, R3, R1, 0   # 0x1f9c
        BRA_PRED         0, L1ee4   # 0x1fa0
        ADD              R3, R5, R2, R5   # 0x1fa4
        C_MOV            R5, R1   # 0x1fa8
L1faa:  C_MOV            R8, R3   # 0x1faa
        C_SHLI           R8, 2   # 0x1fac
        ADD              R8, R15, R8, R15   # 0x1fae
        C_MOV            R9, R3   # 0x1fb2
        C_SHLI           R9, 1   # 0x1fb4
        ADD              R9, R7, R9, R7   # 0x1fb6
        LD_GLOBAL_IDX    R13, R0, R9, 0, 0   # 0x1fba
        CVT_SEXT         R9, R13, R13, R13   # 0x1fbe
        C_MUL_LO         R9, R6   # 0x1fc2
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1fc4
        C_ADDI           R3, 1   # 0x1fc8
        ADDI             R5, R5, -1   # 0x1fca
        SETP_NE_NPI      P0, R8, R5, 0   # 0x1fce
        BRA_PRED         0, L1faa   # 0x1fd2
        C_BRA            L1ee4   # 0x1fd6
L1fd8:  C_CHWIDTH        R13, 0   # 0x1fd8
        MOVI             R2, 0   # 0x1fda
        C_MOV            R5, R2   # 0x1fde
        MOVI             R14, 10   # 0x1fe0
        MOVI             R13, 0   # 0x1fe4
        MOVI             R6, 0   # 0x1fe8
        MOVI             R1, 0   # 0x1fec
        MOVI             R8, 0   # 0x1ff0
        C_BRA            L2006   # 0x1ff4
L1ff6:  LD_LOCAL         R3, 12   # 0x1ff6
        C_ADD            R13, R3   # 0x1ffa
        C_ADDI           R6, 1   # 0x1ffc
        SETP_NE_NP       P0, R3, R6, R3   # 0x1ffe
        BRA_PRED         4, L20da   # 0x2002
L2006:  ST_LOCAL         R6, 36   # 0x2006
        LD_LOCAL         R3, 24   # 0x200a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x200e
        BRA_PRED         0, L2084   # 0x2012
        MOVI             R9, 0   # 0x2016
L201a:  C_CHWIDTH        R5, 0   # 0x201a
        ADD              R3, R13, R9, R13   # 0x201c
        C_SHLI           R3, 2   # 0x2020
        C_ADD            R3, R15   # 0x2022
        C_MOV            R6, R5   # 0x2024
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x2026
        SETP_LT_NP       P0, R1, R1, R5   # 0x202a
        MOVI             R15, 0   # 0x202e
        ADDI_P           R15, 0, R15, 1   # 0x2032
        ADD              R8, R5, R8, R5   # 0x2036
        SETP_LT_NP       P0, R1, R10, R8   # 0x203a
        MOV_P            R15, 0, R14, R14, R14   # 0x203e
        MOV_P            R8, 0, R2, R2, R2   # 0x2042
        ADDI             R1, R3, 4   # 0x2046
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x204a
        SETP_LT_NP       P0, R3, R5, R1   # 0x204e
        MOVI             R3, 0   # 0x2052
        ADDI_P           R3, 0, R3, 1   # 0x2056
        ADD              R8, R1, R8, R1   # 0x205a
        SETP_LT_NP       P0, R5, R10, R8   # 0x205e
        C_CHWIDTH        R5, 1   # 0x2062
        MOV_P            R3, 0, R14, R14, R14   # 0x2064
        MOV_P            R8, 0, R2, R2, R2   # 0x2068
        ADD              R5, R15, R6, R15   # 0x206c
        LD_LOCAL         R15, 16   # 0x2070
        ADD              R5, R3, R5, R3   # 0x2074
        C_ADDI           R9, 2   # 0x2078
        SETP_NE_NP       P0, R3, R12, R9   # 0x207a
        BRA_PRED         0, L201a   # 0x207e
        C_BRA            L2088   # 0x2082
L2084:  MOVI             R9, 0   # 0x2084
L2088:  LD_LOCAL         R3, 28   # 0x2088
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x208c
        LD_LOCAL         R6, 36   # 0x2090
        BRA_PRED         0, L1ff6   # 0x2094
        C_CHWIDTH        R5, 1   # 0x2098
        LD_LOCAL         R3, 12   # 0x209a
        MUL_LO           R3, R6, R3, R3   # 0x209e
        ADD              R3, R9, R3, R9   # 0x20a2
        C_SHLI           R3, 2   # 0x20a6
        ADD              R3, R15, R3, R15   # 0x20a8
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x20ac
        SETP_LT_NP       P0, R1, R1, R3   # 0x20b0
        ADD              R8, R3, R8, R3   # 0x20b4
        SETP_LT_NP       P1, R1, R10, R8   # 0x20b8
        MOV_P            R8, 1, R2, R2, R2   # 0x20bc
        MOVI             R1, 0   # 0x20c0
        ADDI_P           R1, 0, R1, 1   # 0x20c4
        MOV_P            R1, 1, R14, R14, R14   # 0x20c8
        ADD              R5, R1, R5, R1   # 0x20cc
        C_MOV            R1, R3   # 0x20d0
        C_BRA            L1ff6   # 0x20d2
L20d4:  C_MOV            R5, R2   # 0x20d4
        LD_LOCAL         R11, 20   # 0x20d6
L20da:  C_CHWIDTH        R5, 0   # 0x20da
        ST_LOCAL         R5, 60   # 0x20dc
        LD_LOCAL         R1, 44   # 0x20e0
        LD_LOCAL         R2, 68   # 0x20e4
        OR               R8, R1, R2, R1   # 0x20e8
        LD_LOCAL         R1, 64   # 0x20ec
        MOVI             R2, 65535   # 0x20f0
        AND              R9, R1, R2, R1   # 0x20f4
        MOVI             R1, 0   # 0x20f8
        LD_LOCAL         R2, 12   # 0x20fc
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x2100
        ST_LOCAL         R10, 32   # 0x2104
        BRA_PRED         0, L2310   # 0x2108
        MOVI             R10, 0   # 0x210c
        C_BRA            L2132   # 0x2110
L2112:  C_MOV            R2, R10   # 0x2112
        C_SHLI           R2, 2   # 0x2114
        LD_LOCAL         R3, 16   # 0x2116
        ADD              R2, R3, R2, R3   # 0x211a
        ST_GLOBAL_IDX    R6, R11, R2, 0, 0   # 0x211e
        LD_LOCAL         R2, 12   # 0x2122
        C_ADD            R1, R2   # 0x2126
        C_ADDI           R10, 1   # 0x2128
        SETP_NE_NP       P0, R2, R10, R2   # 0x212a
        BRA_PRED         4, L21e0   # 0x212e
L2132:  C_CHWIDTH        R5, 0   # 0x2132
        LD_LOCAL         R2, 24   # 0x2134
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x2138
        BRA_PRED         0, L219c   # 0x213c
        C_CHWIDTH        R15, 1   # 0x2140
        C_CHWIDTH        R14, 0   # 0x2142
        MOVI             R5, 0   # 0x2144
        MOVI             R6, 0   # 0x2148
L214c:  ADD              R3, R1, R5, R1   # 0x214c
        C_SHLI           R3, 1   # 0x2150
        C_ADD            R3, R7   # 0x2152
        C_MOV            R14, R5   # 0x2154
        C_SHLI           R14, 1   # 0x2156
        C_ADD            R14, R9   # 0x2158
        LD_GLOBAL_IDX    R15, R8, R14, 0, 0   # 0x215a
        CVT_SEXT         R13, R15, R15, R15   # 0x215e
        LD_GLOBAL_IDX    R15, R0, R3, 0, 0   # 0x2162
        CVT_SEXT         R2, R15, R15, R15   # 0x2166
        MADLO            R2, R13, R2, R6   # 0x216a
        C_CHWIDTH        R6, 1   # 0x216e
        C_ADDI           R3, 2   # 0x2170
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x2172
        ADDI             R3, R14, 2   # 0x2176
        C_CHWIDTH        R14, 1   # 0x217a
        LD_GLOBAL_IDX    R14, R8, R3, 0, 0   # 0x217c
        CVT_SEXT         R3, R14, R14, R14   # 0x2180
        C_CHWIDTH        R14, 0   # 0x2184
        CVT_SEXT         R14, R6, R6, R6   # 0x2186
        C_CHWIDTH        R6, 0   # 0x218a
        MADLO            R6, R3, R14, R2   # 0x218c
        C_ADDI           R5, 2   # 0x2190
        SETP_NE_NP       P0, R2, R12, R5   # 0x2192
        BRA_PRED         0, L214c   # 0x2196
        C_BRA            L21a4   # 0x219a
L219c:  MOVI             R5, 0   # 0x219c
        MOVI             R6, 0   # 0x21a0
L21a4:  C_CHWIDTH        R14, 1   # 0x21a4
        LD_LOCAL         R2, 28   # 0x21a6
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x21aa
        BRA_PRED         0, L2112   # 0x21ae
        LD_LOCAL         R2, 12   # 0x21b2
        MUL_LO           R2, R10, R2, R2   # 0x21b6
        ADD              R2, R5, R2, R5   # 0x21ba
        C_SHLI           R2, 1   # 0x21be
        ADD              R2, R7, R2, R7   # 0x21c0
        LD_GLOBAL_IDX    R14, R0, R2, 0, 0   # 0x21c4
        C_SHLI           R5, 1   # 0x21c8
        ADD              R2, R9, R5, R9   # 0x21ca
        C_CHWIDTH        R5, 1   # 0x21ce
        LD_GLOBAL_IDX    R5, R8, R2, 0, 0   # 0x21d0
        CVT_SEXT         R2, R5, R5, R5   # 0x21d4
        CVT_SEXT         R3, R14, R14, R14   # 0x21d8
        MAD_ACC          R6, R2, R3   # 0x21dc
        C_BRA            L2112   # 0x21de
L21e0:  C_CHWIDTH        R5, 0   # 0x21e0
        MOVI             R1, 0   # 0x21e2
        C_MOV            R5, R1   # 0x21e6
        MOVI             R3, 0   # 0x21e8
        ST_LOCAL         R1, 44   # 0x21ec
        MOVI             R13, 0   # 0x21f0
        MOVI             R4, 10   # 0x21f4
        C_BRA            L2216   # 0x21f8
L21fa:  LD_LOCAL         R2, 12   # 0x21fa
        LD_LOCAL         R3, 36   # 0x21fe
        C_ADD            R3, R2   # 0x2202
        LD_LOCAL         R6, 44   # 0x2204
        C_ADDI           R6, 1   # 0x2208
        ST_LOCAL         R6, 44   # 0x220a
        SETP_NE_NP       P0, R2, R6, R2   # 0x220e
        BRA_PRED         4, L2312   # 0x2212
L2216:  ST_LOCAL         R3, 36   # 0x2216
        LD_LOCAL         R2, 24   # 0x221a
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x221e
        BRA_PRED         0, L22ac   # 0x2222
        C_CHWIDTH        R14, 0   # 0x2226
        MOVI             R6, 0   # 0x2228
        LD_LOCAL         R2, 16   # 0x222c
        LD_LOCAL         R14, 32   # 0x2230
        LD_LOCAL         R2, 36   # 0x2234
L2238:  CHWIDTH_MULTI    32800, 0   # 0x2238
        LD_LOCAL         R2, 36   # 0x223c
        ADD              R3, R2, R6, R2   # 0x2240
        C_SHLI           R3, 2   # 0x2244
        LD_LOCAL         R2, 16   # 0x2246
        C_ADD            R3, R2   # 0x224a
        C_MOV            R15, R5   # 0x224c
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x224e
        SETP_LT_NP       P0, R1, R1, R5   # 0x2252
        MOVI             R2, 0   # 0x2256
        ADDI_P           R2, 0, R2, 1   # 0x225a
        ADD              R13, R5, R13, R5   # 0x225e
        SETP_LT_NP       P0, R1, R14, R13   # 0x2262
        MOV_P            R2, 0, R4, R4, R4   # 0x2266
        MOVI             R10, 0   # 0x226a
        MOV_P            R13, 0, R10, R10, R10   # 0x226e
        ADDI             R1, R3, 4   # 0x2272
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x2276
        SETP_LT_NP       P0, R3, R5, R1   # 0x227a
        MOVI             R3, 0   # 0x227e
        ADDI_P           R3, 0, R3, 1   # 0x2282
        ADD              R13, R1, R13, R1   # 0x2286
        SETP_LT_NP       P0, R5, R14, R13   # 0x228a
        C_CHWIDTH        R5, 1   # 0x228e
        MOV_P            R3, 0, R4, R4, R4   # 0x2290
        MOV_P            R13, 0, R10, R10, R10   # 0x2294
        ADD              R5, R2, R15, R2   # 0x2298
        ADD              R5, R3, R5, R3   # 0x229c
        C_ADDI           R6, 2   # 0x22a0
        SETP_NE_NP       P0, R2, R12, R6   # 0x22a2
        BRA_PRED         0, L2238   # 0x22a6
        C_BRA            L22b6   # 0x22aa
L22ac:  C_CHWIDTH        R14, 0   # 0x22ac
        MOVI             R6, 0   # 0x22ae
        LD_LOCAL         R14, 32   # 0x22b2
L22b6:  C_CHWIDTH        R15, 0   # 0x22b6
        LD_LOCAL         R2, 28   # 0x22b8
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x22bc
        MOVI             R15, 0   # 0x22c0
        MOVI             R10, 10   # 0x22c4
        BRA_PRED         0, L21fa   # 0x22c8
        C_CHWIDTH        R5, 1   # 0x22cc
        LD_LOCAL         R2, 44   # 0x22ce
        LD_LOCAL         R3, 12   # 0x22d2
        C_MUL_LO         R2, R3   # 0x22d6
        ADD              R2, R6, R2, R6   # 0x22d8
        C_SHLI           R2, 2   # 0x22dc
        LD_LOCAL         R3, 16   # 0x22de
        ADD              R2, R3, R2, R3   # 0x22e2
        LD_GLOBAL_IDX    R2, R11, R2, 0, 0   # 0x22e6
        SETP_LT_NP       P0, R1, R1, R2   # 0x22ea
        ADD              R13, R2, R13, R2   # 0x22ee
        SETP_LT_NP       P1, R1, R14, R13   # 0x22f2
        MOV_P            R13, 1, R15, R15, R15   # 0x22f6
        MOVI             R1, 0   # 0x22fa
        ADDI_P           R1, 0, R1, 1   # 0x22fe
        MOV_P            R1, 1, R10, R10, R10   # 0x2302
        ADD              R5, R1, R5, R1   # 0x2306
        C_MOV            R1, R2   # 0x230a
        BRA              L21fa   # 0x230c
L2310:  C_MOV            R5, R1   # 0x2310
L2312:  C_CHWIDTH        R5, 0   # 0x2312
        ST_LOCAL         R5, 64   # 0x2314
        MOVI             R1, 0   # 0x2318
        LD_LOCAL         R3, 12   # 0x231c
        SETP_EQ_NPI      P0, R2, R3, 0   # 0x2320
        C_MOV            R2, R3   # 0x2324
        C_SHLI           R2, 1   # 0x2326
        LD_LOCAL         R3, 40   # 0x2328
        BRA_PRED         0, L2582   # 0x232c
        MOVI             R5, 0   # 0x2330
        LD_LOCAL         R10, 12   # 0x2334
        C_BRA            L234a   # 0x2338
L233a:  C_ADD            R1, R10   # 0x233a
        LD_LOCAL         R5, 44   # 0x233c
        C_ADDI           R5, 1   # 0x2340
        SETP_NE_NP       P0, R3, R5, R10   # 0x2342
        BRA_PRED         4, L243c   # 0x2346
L234a:  ST_LOCAL         R5, 44   # 0x234a
        MUL_LO           R3, R5, R10, R10   # 0x234e
        ST_LOCAL         R3, 36   # 0x2352
        MOVI             R11, 0   # 0x2356
        C_BRA            L2382   # 0x235a
L235c:  C_CHWIDTH        R6, 0   # 0x235c
        LD_LOCAL         R3, 36   # 0x235e
        ADD              R3, R11, R3, R11   # 0x2362
        C_SHLI           R3, 2   # 0x2366
        LD_LOCAL         R6, 16   # 0x2368
        ADD              R3, R6, R3, R6   # 0x236c
        LD_LOCAL         R6, 20   # 0x2370
        ST_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x2374
        C_ADDI           R11, 1   # 0x2378
        SETP_NE_NP       P0, R3, R11, R10   # 0x237a
        BRA_PRED         4, L233a   # 0x237e
L2382:  LD_LOCAL         R3, 24   # 0x2382
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2386
        MOVI             R13, 0   # 0x238a
        MOVI             R5, 0   # 0x238e
        BRA_PRED         0, L23fe   # 0x2392
        C_MOV            R15, R11   # 0x2396
        MOVI             R5, 0   # 0x2398
L239c:  C_CHWIDTH        R14, 0   # 0x239c
        ADD              R6, R1, R13, R1   # 0x239e
        C_SHLI           R6, 1   # 0x23a2
        C_ADD            R6, R7   # 0x23a4
        C_MOV            R3, R15   # 0x23a6
        C_SHLI           R3, 1   # 0x23a8
        ADD              R3, R9, R3, R9   # 0x23aa
        C_CHWIDTH        R3, 1   # 0x23ae
        LD_GLOBAL_IDX    R3, R8, R3, 0, 0   # 0x23b0
        CVT_SEXT         R10, R3, R3, R3   # 0x23b4
        LD_GLOBAL_IDX    R3, R0, R6, 0, 0   # 0x23b8
        CVT_SEXT         R14, R3, R3, R3   # 0x23bc
        C_CHWIDTH        R3, 0   # 0x23c0
        MADLO            R3, R10, R14, R5   # 0x23c2
        C_CHWIDTH        R14, 1   # 0x23c6
        LD_LOCAL         R10, 12   # 0x23c8
        ADDI             R5, R6, 2   # 0x23cc
        C_CHWIDTH        R6, 1   # 0x23d0
        LD_GLOBAL_IDX    R14, R0, R5, 0, 0   # 0x23d2
        ADD              R5, R10, R15, R10   # 0x23d6
        C_SHLI           R5, 1   # 0x23da
        ADD              R5, R9, R5, R9   # 0x23dc
        LD_GLOBAL_IDX    R6, R8, R5, 0, 0   # 0x23e0
        CVT_SEXT         R5, R6, R6, R6   # 0x23e4
        C_CHWIDTH        R6, 0   # 0x23e8
        CVT_SEXT         R6, R14, R14, R14   # 0x23ea
        MADLO            R5, R5, R6, R3   # 0x23ee
        C_ADD            R15, R2   # 0x23f2
        C_ADDI           R13, 2   # 0x23f4
        SETP_NE_NP       P0, R3, R12, R13   # 0x23f6
        BRA_PRED         0, L239c   # 0x23fa
L23fe:  LD_LOCAL         R3, 28   # 0x23fe
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2402
        BRA_PRED         0, L235c   # 0x2406
        CHWIDTH_MULTI    16448, 1   # 0x240a
        MADLO            R3, R13, R10, R11   # 0x240e
        C_SHLI           R3, 1   # 0x2412
        ADD              R3, R9, R3, R9   # 0x2414
        LD_GLOBAL_IDX    R14, R8, R3, 0, 0   # 0x2418
        LD_LOCAL         R3, 36   # 0x241c
        ADD              R3, R13, R3, R13   # 0x2420
        C_SHLI           R3, 1   # 0x2424
        ADD              R3, R7, R3, R7   # 0x2426
        LD_GLOBAL_IDX    R6, R0, R3, 0, 0   # 0x242a
        CVT_SEXT         R3, R14, R14, R14   # 0x242e
        C_CHWIDTH        R14, 0   # 0x2432
        CVT_SEXT         R14, R6, R6, R6   # 0x2434
        MAD_ACC          R5, R3, R14   # 0x2438
        C_BRA            L235c   # 0x243a
L243c:  C_CHWIDTH        R14, 0   # 0x243c
        MOVI             R1, 0   # 0x243e
        C_MOV            R10, R1   # 0x2442
        MOVI             R6, 0   # 0x2444
        ST_LOCAL         R1, 44   # 0x2448
        MOVI             R14, 0   # 0x244c
        LD_LOCAL         R11, 20   # 0x2450
        C_BRA            L2472   # 0x2454
L2456:  LD_LOCAL         R6, 36   # 0x2456
        C_ADD            R6, R5   # 0x245a
        LD_LOCAL         R3, 44   # 0x245c
        C_ADDI           R3, 1   # 0x2460
        ST_LOCAL         R3, 44   # 0x2462
        SETP_NE_NP       P0, R3, R3, R5   # 0x2466
        LD_LOCAL         R3, 40   # 0x246a
        BRA_PRED         4, L2584   # 0x246e
L2472:  ST_LOCAL         R6, 36   # 0x2472
        LD_LOCAL         R3, 24   # 0x2476
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x247a
        BRA_PRED         0, L2516   # 0x247e
        MOVI             R13, 0   # 0x2482
        LD_LOCAL         R3, 16   # 0x2486
        LD_LOCAL         R3, 32   # 0x248a
        LD_LOCAL         R3, 36   # 0x248e
L2492:  CHWIDTH_MULTI    1056, 0   # 0x2492
        LD_LOCAL         R3, 36   # 0x2496
        C_ADD            R3, R13   # 0x249a
        C_SHLI           R3, 2   # 0x249c
        LD_LOCAL         R5, 16   # 0x249e
        C_ADD            R3, R5   # 0x24a2
        LD_LOCAL         R6, 20   # 0x24a4
        LD_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x24a8
        SETP_LT_NP       P0, R1, R1, R5   # 0x24ac
        C_MOV            R15, R10   # 0x24b0
        MOVI             R10, 0   # 0x24b2
        ADDI_P           R10, 0, R10, 1   # 0x24b6
        ADD              R14, R5, R14, R5   # 0x24ba
        LD_LOCAL         R4, 32   # 0x24be
        SETP_LT_NP       P0, R1, R4, R14   # 0x24c2
        MOVI             R11, 10   # 0x24c6
        MOV_P            R10, 0, R11, R11, R11   # 0x24ca
        MOVI             R1, 0   # 0x24ce
        MOV_P            R14, 0, R1, R1, R1   # 0x24d2
        ADDI             R1, R3, 4   # 0x24d6
        LD_GLOBAL_IDX    R1, R6, R1, 0, 0   # 0x24da
        SETP_LT_NP       P0, R3, R5, R1   # 0x24de
        MOVI             R3, 0   # 0x24e2
        ADDI_P           R3, 0, R3, 1   # 0x24e6
        ADD              R14, R1, R14, R1   # 0x24ea
        SETP_LT_NP       P0, R5, R4, R14   # 0x24ee
        C_CHWIDTH        R5, 1   # 0x24f2
        MOV_P            R3, 0, R11, R11, R11   # 0x24f4
        MOVI             R4, 0   # 0x24f8
        MOV_P            R14, 0, R4, R4, R4   # 0x24fc
        ADD              R5, R10, R15, R10   # 0x2500
        C_CHWIDTH        R10, 1   # 0x2504
        ADD              R10, R3, R5, R3   # 0x2506
        C_ADDI           R13, 2   # 0x250a
        SETP_NE_NP       P0, R3, R12, R13   # 0x250c
        BRA_PRED         0, L2492   # 0x2510
        C_BRA            L251a   # 0x2514
L2516:  MOVI             R13, 0   # 0x2516
L251a:  C_CHWIDTH        R5, 0   # 0x251a
        LD_LOCAL         R11, 20   # 0x251c
        LD_LOCAL         R3, 28   # 0x2520
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2524
        LD_LOCAL         R5, 12   # 0x2528
        MOVI             R15, 0   # 0x252c
        MOVI             R4, 10   # 0x2530
        BRA_PRED         0, L2456   # 0x2534
        C_CHWIDTH        R10, 0   # 0x2538
        LD_LOCAL         R3, 44   # 0x253a
        C_MUL_LO         R3, R5   # 0x253e
        ADD              R3, R13, R3, R13   # 0x2540
        C_SHLI           R3, 2   # 0x2544
        C_MOV            R6, R10   # 0x2546
        LD_LOCAL         R10, 16   # 0x2548
        ADD              R3, R10, R3, R10   # 0x254c
        C_MOV            R10, R6   # 0x2550
        C_CHWIDTH        R10, 1   # 0x2552
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x2554
        SETP_LT_NP       P0, R1, R1, R3   # 0x2558
        ADD              R14, R3, R14, R3   # 0x255c
        LD_LOCAL         R1, 32   # 0x2560
        SETP_LT_NP       P1, R1, R1, R14   # 0x2564
        MOV_P            R14, 1, R15, R15, R15   # 0x2568
        MOVI             R1, 0   # 0x256c
        ADDI_P           R1, 0, R1, 1   # 0x2570
        MOV_P            R1, 1, R4, R4, R4   # 0x2574
        ADD              R10, R1, R10, R1   # 0x2578
        C_MOV            R1, R3   # 0x257c
        BRA              L2456   # 0x257e
L2582:  C_MOV            R10, R1   # 0x2582
L2584:  C_CHWIDTH        R10, 0   # 0x2584
        ST_LOCAL         R10, 68   # 0x2586
        MOVI             R6, 0   # 0x258a
        LD_LOCAL         R1, 12   # 0x258e
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x2592
        BRA_PRED         0, L27dc   # 0x2596
        MOVI             R3, 0   # 0x259a
        LD_LOCAL         R10, 12   # 0x259e
        C_BRA            L25b4   # 0x25a2
L25a4:  C_ADD            R6, R10   # 0x25a4
        LD_LOCAL         R3, 44   # 0x25a6
        C_ADDI           R3, 1   # 0x25aa
        SETP_NE_NP       P0, R1, R3, R10   # 0x25ac
        BRA_PRED         4, L26ba   # 0x25b0
L25b4:  ST_LOCAL         R3, 44   # 0x25b4
        MUL_LO           R1, R3, R10, R10   # 0x25b8
        ST_LOCAL         R1, 36   # 0x25bc
        MOVI             R3, 0   # 0x25c0
        C_BRA            L25ea   # 0x25c4
L25c6:  LD_LOCAL         R1, 36   # 0x25c6
        ADD              R5, R3, R1, R3   # 0x25ca
        C_SHLI           R5, 2   # 0x25ce
        LD_LOCAL         R15, 16   # 0x25d0
        ADD              R5, R15, R5, R15   # 0x25d4
        LD_LOCAL         R11, 20   # 0x25d8
        ST_GLOBAL_IDX    R14, R11, R5, 0, 0   # 0x25dc
        C_ADDI           R3, 1   # 0x25e0
        SETP_NE_NP       P0, R5, R3, R10   # 0x25e2
        BRA_PRED         4, L25a4   # 0x25e6
L25ea:  C_CHWIDTH        R14, 0   # 0x25ea
        LD_LOCAL         R5, 24   # 0x25ec
        SETP_EQ_NPI      P0, R5, R5, 0   # 0x25f0
        MOVI             R5, 0   # 0x25f4
        MOVI             R14, 0   # 0x25f8
        C_MOV            R1, R10   # 0x25fc
        BRA_PRED         0, L2672   # 0x25fe
        C_MOV            R13, R3   # 0x2602
L2604:  C_CHWIDTH        R15, 1   # 0x2604
        ADD              R10, R6, R5, R6   # 0x2606
        C_SHLI           R10, 1   # 0x260a
        C_ADD            R10, R7   # 0x260c
        C_MOV            R11, R13   # 0x260e
        C_SHLI           R11, 1   # 0x2610
        ADD              R11, R9, R11, R9   # 0x2612
        C_CHWIDTH        R11, 1   # 0x2616
        LD_GLOBAL_IDX    R11, R8, R11, 0, 0   # 0x2618
        C_CHWIDTH        R11, 0   # 0x261c
        LD_GLOBAL_IDX    R15, R0, R10, 0, 0   # 0x261e
        C_CHWIDTH        R15, 0   # 0x2622
        MUL_LO           R15, R11, R15, R15   # 0x2624
        C_MOV            R11, R15   # 0x2628
        C_SHRI           R11, 5   # 0x262a
        ANDI             R11, R11, 127   # 0x262c
        C_SHRI           R15, 2   # 0x2630
        C_ANDI           R15, 15   # 0x2632
        MAD_ACC          R14, R15, R11   # 0x2634
        ADDI             R15, R10, 2   # 0x2636
        C_CHWIDTH        R15, 1   # 0x263a
        LD_GLOBAL_IDX    R15, R0, R15, 0, 0   # 0x263c
        C_CHWIDTH        R15, 0   # 0x2640
        ADD              R10, R1, R13, R1   # 0x2642
        C_SHLI           R10, 1   # 0x2646
        ADD              R10, R9, R10, R9   # 0x2648
        C_CHWIDTH        R10, 1   # 0x264c
        LD_GLOBAL_IDX    R10, R8, R10, 0, 0   # 0x264e
        C_CHWIDTH        R10, 0   # 0x2652
        MUL_LO           R15, R10, R15, R15   # 0x2654
        C_MOV            R10, R15   # 0x2658
        C_SHRI           R10, 5   # 0x265a
        ANDI             R10, R10, 127   # 0x265c
        C_SHRI           R15, 2   # 0x2660
        C_ANDI           R15, 15   # 0x2662
        MAD_ACC          R14, R15, R10   # 0x2664
        C_ADD            R13, R2   # 0x2666
        C_ADDI           R5, 2   # 0x2668
        SETP_NE_NP       P0, R15, R12, R5   # 0x266a
        BRA_PRED         0, L2604   # 0x266e
L2672:  LD_LOCAL         R15, 28   # 0x2672
        SETP_EQ_NPI      P0, R15, R15, 0   # 0x2676
        C_MOV            R10, R1   # 0x267a
        BRA_PRED         0, L25c6   # 0x267c
        MADLO            R15, R5, R10, R3   # 0x2680
        C_SHLI           R15, 1   # 0x2684
        ADD              R15, R9, R15, R9   # 0x2686
        C_CHWIDTH        R15, 1   # 0x268a
        LD_GLOBAL_IDX    R15, R8, R15, 0, 0   # 0x268c
        C_CHWIDTH        R15, 0   # 0x2690
        LD_LOCAL         R1, 36   # 0x2692
        C_ADD            R5, R1   # 0x2696
        C_SHLI           R5, 1   # 0x2698
        ADD              R5, R7, R5, R7   # 0x269a
        C_CHWIDTH        R5, 1   # 0x269e
        LD_GLOBAL_IDX    R5, R0, R5, 0, 0   # 0x26a0
        C_CHWIDTH        R5, 0   # 0x26a4
        MUL_LO           R5, R15, R5, R5   # 0x26a6
        C_MOV            R15, R5   # 0x26aa
        C_SHRI           R15, 5   # 0x26ac
        ANDI             R15, R15, 127   # 0x26ae
        C_SHRI           R5, 2   # 0x26b2
        C_ANDI           R5, 15   # 0x26b4
        MAD_ACC          R14, R5, R15   # 0x26b6
        C_BRA            L25c6   # 0x26b8
L26ba:  MOVI             R1, 0   # 0x26ba
        C_MOV            R8, R1   # 0x26be
        MOVI             R5, 0   # 0x26c0
        ST_LOCAL         R1, 36   # 0x26c4
        MOVI             R13, 0   # 0x26c8
        LD_LOCAL         R10, 32   # 0x26cc
        C_BRA            L26ee   # 0x26d0
L26d2:  C_ADD            R5, R15   # 0x26d2
        LD_LOCAL         R2, 36   # 0x26d4
        C_ADDI           R2, 1   # 0x26d8
        ST_LOCAL         R2, 36   # 0x26da
        SETP_NE_NP       P0, R3, R2, R15   # 0x26de
        LD_LOCAL         R9, 40   # 0x26e2
        LD_LOCAL         R15, 16   # 0x26e6
        BRA_PRED         4, L27e0   # 0x26ea
L26ee:  LD_LOCAL         R3, 24   # 0x26ee
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x26f2
        BRA_PRED         0, L277a   # 0x26f6
        MOVI             R9, 0   # 0x26fa
L26fe:  C_CHWIDTH        R8, 1   # 0x26fe
        ADD              R3, R5, R9, R5   # 0x2700
        C_SHLI           R3, 2   # 0x2704
        LD_LOCAL         R2, 16   # 0x2706
        C_ADD            R3, R2   # 0x270a
        C_MOV            R14, R5   # 0x270c
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x270e
        SETP_LT_NP       P0, R15, R13, R5   # 0x2712
        MOVI             R15, 0   # 0x2716
        ADDI_P           R15, 0, R15, 1   # 0x271a
        ADD              R1, R5, R1, R5   # 0x271e
        LD_LOCAL         R10, 32   # 0x2722
        SETP_LT_NP       P0, R10, R10, R1   # 0x2726
        LD_LOCAL         R10, 32   # 0x272a
        MOVI             R2, 10   # 0x272e
        MOV_P            R15, 0, R2, R2, R2   # 0x2732
        MOVI             R6, 0   # 0x2736
        MOV_P            R1, 0, R6, R6, R6   # 0x273a
        C_ADDI           R3, 4   # 0x273e
        LD_GLOBAL_IDX    R13, R11, R3, 0, 0   # 0x2740
        SETP_LT_NP       P0, R3, R5, R13   # 0x2744
        MOVI             R3, 0   # 0x2748
        ADDI_P           R3, 0, R3, 1   # 0x274c
        ADD              R1, R13, R1, R13   # 0x2750
        SETP_LT_NP       P0, R5, R10, R1   # 0x2754
        C_CHWIDTH        R5, 1   # 0x2758
        MOV_P            R3, 0, R2, R2, R2   # 0x275a
        MOV_P            R1, 0, R6, R6, R6   # 0x275e
        ADD              R5, R15, R8, R15   # 0x2762
        ADD              R8, R3, R5, R3   # 0x2766
        C_CHWIDTH        R5, 0   # 0x276a
        C_MOV            R5, R14   # 0x276c
        C_ADDI           R9, 2   # 0x276e
        SETP_NE_NP       P0, R3, R12, R9   # 0x2770
        BRA_PRED         0, L26fe   # 0x2774
        C_BRA            L277e   # 0x2778
L277a:  MOVI             R9, 0   # 0x277a
L277e:  MOVI             R6, 10   # 0x277e
        MOVI             R14, 0   # 0x2782
        LD_LOCAL         R2, 28   # 0x2786
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x278a
        LD_LOCAL         R15, 12   # 0x278e
        BRA_PRED         0, L26d2   # 0x2792
        C_CHWIDTH        R8, 1   # 0x2796
        LD_LOCAL         R2, 36   # 0x2798
        MUL_LO           R3, R2, R15, R15   # 0x279c
        ADD              R3, R9, R3, R9   # 0x27a0
        C_SHLI           R3, 2   # 0x27a4
        LD_LOCAL         R2, 16   # 0x27a6
        ADD              R3, R2, R3, R2   # 0x27aa
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x27ae
        C_MOV            R2, R5   # 0x27b2
        SETP_LT_NP       P0, R5, R13, R3   # 0x27b4
        ADD              R1, R3, R1, R3   # 0x27b8
        SETP_LT_NP       P1, R5, R10, R1   # 0x27bc
        MOV_P            R1, 1, R14, R14, R14   # 0x27c0
        MOVI             R5, 0   # 0x27c4
        ADDI_P           R5, 0, R5, 1   # 0x27c8
        MOV_P            R5, 1, R6, R6, R6   # 0x27cc
        ADD              R8, R5, R8, R5   # 0x27d0
        C_MOV            R5, R2   # 0x27d4
        C_MOV            R13, R3   # 0x27d6
        BRA              L26d2   # 0x27d8
L27dc:  C_MOV            R8, R6   # 0x27dc
        C_MOV            R9, R3   # 0x27de
L27e0:  LD_LOCAL         R1, 56   # 0x27e0
        C_MOV            R5, R1   # 0x27e4
        C_CHWIDTH        R5, 1   # 0x27e6
        LD_LOCAL         R1, 12   # 0x27e8
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x27ec
        LD_LOCAL         R12, 52   # 0x27f0
        LD_LOCAL         R10, 68   # 0x27f4
        BRA_PRED         0, L28ba   # 0x27f8
        MOVI             R1, 0   # 0x27fc
        LD_LOCAL         R2, 12   # 0x2800
        C_ANDI           R2, 3   # 0x2804
        MOVI             R6, 0   # 0x2806
        C_BRA            L281c   # 0x280a
L280c:  LD_LOCAL         R3, 12   # 0x280c
        C_ADD            R1, R3   # 0x2810
        C_ADDI           R6, 1   # 0x2812
        SETP_NE_NP       P0, R3, R6, R3   # 0x2814
        BRA_PRED         4, L28ba   # 0x2818
L281c:  LD_LOCAL         R3, 24   # 0x281c
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x2820
        MOVI             R3, 0   # 0x2824
        BRA_PRED         0, L2884   # 0x2828
L282c:  CHWIDTH_MULTI    40960, 1   # 0x282c
        C_CHWIDTH        R14, 0   # 0x2830
        ADD              R14, R1, R3, R1   # 0x2832
        C_SHLI           R14, 1   # 0x2836
        ADD              R14, R7, R14, R7   # 0x2838
        LD_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x283c
        SUB              R15, R15, R12, R15   # 0x2840
        ST_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x2844
        C_CHWIDTH        R15, 0   # 0x2848
        ADDI             R15, R14, 2   # 0x284a
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x284e
        SUB              R13, R13, R12, R13   # 0x2852
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x2856
        ADDI             R15, R14, 4   # 0x285a
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x285e
        SUB              R13, R13, R12, R13   # 0x2862
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x2866
        C_CHWIDTH        R15, 1   # 0x286a
        C_ADDI           R14, 6   # 0x286c
        LD_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x286e
        SUB              R15, R15, R12, R15   # 0x2872
        ST_GLOBAL_IDX    R15, R0, R14, 0, 0   # 0x2876
        C_ADDI           R3, 4   # 0x287a
        SETP_NE_NP       P0, R14, R9, R3   # 0x287c
        BRA_PRED         0, L282c   # 0x2880
L2884:  SETP_EQ_NPI      P0, R14, R2, 0   # 0x2884
        BRA_PRED         0, L280c   # 0x2888
        C_CHWIDTH        R14, 0   # 0x288c
        C_ADD            R3, R1   # 0x288e
        C_MOV            R14, R2   # 0x2890
L2892:  C_CHWIDTH        R13, 1   # 0x2892
        C_CHWIDTH        R15, 0   # 0x2894
        C_MOV            R15, R3   # 0x2896
        C_SHLI           R15, 1   # 0x2898
        ADD              R15, R7, R15, R7   # 0x289a
        LD_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x289e
        SUB              R13, R13, R12, R13   # 0x28a2
        ST_GLOBAL_IDX    R13, R0, R15, 0, 0   # 0x28a6
        C_ADDI           R3, 1   # 0x28aa
        ADDI             R14, R14, -1   # 0x28ac
        SETP_NE_NPI      P0, R15, R14, 0   # 0x28b0
        BRA_PRED         0, L2892   # 0x28b4
        C_BRA            L280c   # 0x28b8
L28ba:  CHWIDTH_MULTI    57632, 0   # 0x28ba
        LD_LOCAL         R1, 60   # 0x28be
        MOVI             R2, 0   # 0x28c2
        CALL             R14, 129296   # 0x28c6
        C_MOV            R2, R1   # 0x28ca
        LD_LOCAL         R1, 64   # 0x28cc
        CALL             R14, 129291   # 0x28d0
        C_MOV            R2, R1   # 0x28d4
        C_MOV            R1, R10   # 0x28d6
        CALL             R14, 129287   # 0x28d8
        C_MOV            R2, R1   # 0x28dc
        C_MOV            R1, R8   # 0x28de
        CALL             R14, 129283   # 0x28e0
        C_MOV            R2, R5   # 0x28e4
        CALL             R14, 129280   # 0x28e6
        LD_LOCAL         R14, 48   # 0x28ea
        LD_LOCAL         R13, 92   # 0x28ee
        LD_LOCAL         R12, 88   # 0x28f2
        LD_LOCAL         R11, 84   # 0x28f6
        LD_LOCAL         R10, 80   # 0x28fa
        LD_LOCAL         R9, 76   # 0x28fe
        LD_LOCAL         R8, 72   # 0x2902
        C_RET            224   # 0x2906
        CHWIDTH_MULTI    7, 1   # 0x2908
        XOR              R0, R2, R1, R2   # 0x290c
        CHWIDTH_MULTI    7, 0   # 0x2910
        C_ANDI           R0, 1   # 0x2914
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2916
        MOVI             R0, 40961   # 0x291a
        C_MOV            R7, R0   # 0x291e
        SHRI             R0, R2, 1   # 0x2920
        C_CHWIDTH        R2, 1   # 0x2924
        XOR              R2, R0, R7, R0   # 0x2926
        C_CHWIDTH        R2, 0   # 0x292a
        MOV_P            R0, 0, R2, R2, R2   # 0x292c
        C_CHWIDTH        R0, 1   # 0x2930
        SHRI             R2, R1, 1   # 0x2932
        C_CHWIDTH        R2, 1   # 0x2936
        XOR              R2, R2, R0, R2   # 0x2938
        CHWIDTH_MULTI    5, 0   # 0x293c
        C_ANDI           R2, 1   # 0x2940
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2942
        C_CHWIDTH        R2, 1   # 0x2946
        SHRI             R0, R0, 1   # 0x2948
        XOR              R2, R0, R7, R0   # 0x294c
        C_CHWIDTH        R2, 0   # 0x2950
        MOV_P            R0, 0, R2, R2, R2   # 0x2952
        C_CHWIDTH        R0, 1   # 0x2956
        SHRI             R2, R1, 2   # 0x2958
        C_CHWIDTH        R2, 1   # 0x295c
        XOR              R2, R2, R0, R2   # 0x295e
        CHWIDTH_MULTI    5, 0   # 0x2962
        C_ANDI           R2, 1   # 0x2966
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2968
        C_CHWIDTH        R2, 1   # 0x296c
        SHRI             R0, R0, 1   # 0x296e
        XOR              R2, R0, R7, R0   # 0x2972
        C_CHWIDTH        R2, 0   # 0x2976
        MOV_P            R0, 0, R2, R2, R2   # 0x2978
        C_CHWIDTH        R0, 1   # 0x297c
        SHRI             R2, R1, 3   # 0x297e
        C_CHWIDTH        R2, 1   # 0x2982
        XOR              R2, R2, R0, R2   # 0x2984
        CHWIDTH_MULTI    5, 0   # 0x2988
        C_ANDI           R2, 1   # 0x298c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x298e
        C_CHWIDTH        R2, 1   # 0x2992
        SHRI             R0, R0, 1   # 0x2994
        XOR              R2, R0, R7, R0   # 0x2998
        C_CHWIDTH        R2, 0   # 0x299c
        MOV_P            R0, 0, R2, R2, R2   # 0x299e
        C_CHWIDTH        R0, 1   # 0x29a2
        SHRI             R2, R1, 4   # 0x29a4
        C_CHWIDTH        R2, 1   # 0x29a8
        XOR              R2, R2, R0, R2   # 0x29aa
        CHWIDTH_MULTI    5, 0   # 0x29ae
        C_ANDI           R2, 1   # 0x29b2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29b4
        C_CHWIDTH        R2, 1   # 0x29b8
        SHRI             R0, R0, 1   # 0x29ba
        XOR              R2, R0, R7, R0   # 0x29be
        C_CHWIDTH        R2, 0   # 0x29c2
        MOV_P            R0, 0, R2, R2, R2   # 0x29c4
        C_CHWIDTH        R0, 1   # 0x29c8
        SHRI             R2, R1, 5   # 0x29ca
        C_CHWIDTH        R2, 1   # 0x29ce
        XOR              R2, R2, R0, R2   # 0x29d0
        CHWIDTH_MULTI    5, 0   # 0x29d4
        C_ANDI           R2, 1   # 0x29d8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29da
        C_CHWIDTH        R2, 1   # 0x29de
        SHRI             R0, R0, 1   # 0x29e0
        XOR              R2, R0, R7, R0   # 0x29e4
        C_CHWIDTH        R2, 0   # 0x29e8
        MOV_P            R0, 0, R2, R2, R2   # 0x29ea
        C_CHWIDTH        R0, 1   # 0x29ee
        SHRI             R2, R1, 6   # 0x29f0
        C_CHWIDTH        R2, 1   # 0x29f4
        XOR              R2, R2, R0, R2   # 0x29f6
        CHWIDTH_MULTI    5, 0   # 0x29fa
        C_ANDI           R2, 1   # 0x29fe
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a00
        C_CHWIDTH        R2, 1   # 0x2a04
        SHRI             R0, R0, 1   # 0x2a06
        XOR              R2, R0, R7, R0   # 0x2a0a
        C_CHWIDTH        R2, 0   # 0x2a0e
        MOV_P            R0, 0, R2, R2, R2   # 0x2a10
        MOVI             R2, 128   # 0x2a14
        C_CHWIDTH        R2, 1   # 0x2a18
        AND              R2, R1, R2, R1   # 0x2a1a
        C_CHWIDTH        R2, 0   # 0x2a1e
        SHRI             R2, R2, 7   # 0x2a20
        ANDI             R3, R0, 1   # 0x2a24
        C_CHWIDTH        R0, 1   # 0x2a28
        C_CHWIDTH        R0, 0   # 0x2a2a
        SETP_EQ_NP       P0, R2, R2, R3   # 0x2a2c
        C_CHWIDTH        R2, 1   # 0x2a30
        SHRI             R0, R0, 1   # 0x2a32
        XOR              R2, R0, R7, R0   # 0x2a36
        C_CHWIDTH        R2, 0   # 0x2a3a
        MOV_P            R2, 0, R0, R0, R0   # 0x2a3c
        C_CHWIDTH        R2, 1   # 0x2a40
        SHRI             R0, R1, 8   # 0x2a42
        C_CHWIDTH        R0, 1   # 0x2a46
        XOR              R0, R2, R0, R2   # 0x2a48
        CHWIDTH_MULTI    5, 0   # 0x2a4c
        C_ANDI           R0, 1   # 0x2a50
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2a52
        SHRI             R0, R2, 1   # 0x2a56
        C_CHWIDTH        R2, 1   # 0x2a5a
        XOR              R2, R0, R7, R0   # 0x2a5c
        C_CHWIDTH        R2, 0   # 0x2a60
        MOV_P            R0, 0, R2, R2, R2   # 0x2a62
        C_CHWIDTH        R0, 1   # 0x2a66
        SHRI             R2, R1, 9   # 0x2a68
        C_CHWIDTH        R2, 1   # 0x2a6c
        XOR              R2, R2, R0, R2   # 0x2a6e
        CHWIDTH_MULTI    5, 0   # 0x2a72
        C_ANDI           R2, 1   # 0x2a76
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a78
        C_CHWIDTH        R2, 1   # 0x2a7c
        SHRI             R0, R0, 1   # 0x2a7e
        XOR              R2, R0, R7, R0   # 0x2a82
        C_CHWIDTH        R2, 0   # 0x2a86
        MOV_P            R0, 0, R2, R2, R2   # 0x2a88
        C_CHWIDTH        R0, 1   # 0x2a8c
        SHRI             R2, R1, 10   # 0x2a8e
        C_CHWIDTH        R2, 1   # 0x2a92
        XOR              R2, R2, R0, R2   # 0x2a94
        CHWIDTH_MULTI    5, 0   # 0x2a98
        C_ANDI           R2, 1   # 0x2a9c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a9e
        C_CHWIDTH        R2, 1   # 0x2aa2
        SHRI             R0, R0, 1   # 0x2aa4
        XOR              R2, R0, R7, R0   # 0x2aa8
        C_CHWIDTH        R2, 0   # 0x2aac
        MOV_P            R0, 0, R2, R2, R2   # 0x2aae
        C_CHWIDTH        R0, 1   # 0x2ab2
        SHRI             R2, R1, 11   # 0x2ab4
        C_CHWIDTH        R2, 1   # 0x2ab8
        XOR              R2, R2, R0, R2   # 0x2aba
        CHWIDTH_MULTI    5, 0   # 0x2abe
        C_ANDI           R2, 1   # 0x2ac2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2ac4
        C_CHWIDTH        R2, 1   # 0x2ac8
        SHRI             R0, R0, 1   # 0x2aca
        XOR              R2, R0, R7, R0   # 0x2ace
        C_CHWIDTH        R2, 0   # 0x2ad2
        MOV_P            R0, 0, R2, R2, R2   # 0x2ad4
        C_CHWIDTH        R0, 1   # 0x2ad8
        SHRI             R2, R1, 12   # 0x2ada
        C_CHWIDTH        R2, 1   # 0x2ade
        XOR              R2, R2, R0, R2   # 0x2ae0
        CHWIDTH_MULTI    5, 0   # 0x2ae4
        C_ANDI           R2, 1   # 0x2ae8
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2aea
        C_CHWIDTH        R2, 1   # 0x2aee
        SHRI             R0, R0, 1   # 0x2af0
        XOR              R2, R0, R7, R0   # 0x2af4
        C_CHWIDTH        R2, 0   # 0x2af8
        MOV_P            R0, 0, R2, R2, R2   # 0x2afa
        C_CHWIDTH        R0, 1   # 0x2afe
        SHRI             R2, R1, 13   # 0x2b00
        C_CHWIDTH        R2, 1   # 0x2b04
        XOR              R2, R2, R0, R2   # 0x2b06
        CHWIDTH_MULTI    5, 0   # 0x2b0a
        C_ANDI           R2, 1   # 0x2b0e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2b10
        C_CHWIDTH        R2, 1   # 0x2b14
        SHRI             R0, R0, 1   # 0x2b16
        XOR              R2, R0, R7, R0   # 0x2b1a
        C_CHWIDTH        R2, 0   # 0x2b1e
        MOV_P            R0, 0, R2, R2, R2   # 0x2b20
        C_CHWIDTH        R0, 1   # 0x2b24
        SHRI             R2, R1, 14   # 0x2b26
        C_CHWIDTH        R2, 1   # 0x2b2a
        XOR              R2, R2, R0, R2   # 0x2b2c
        CHWIDTH_MULTI    5, 0   # 0x2b30
        C_ANDI           R2, 1   # 0x2b34
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2b36
        C_CHWIDTH        R2, 1   # 0x2b3a
        SHRI             R0, R0, 1   # 0x2b3c
        XOR              R2, R0, R7, R0   # 0x2b40
        C_CHWIDTH        R2, 0   # 0x2b44
        MOV_P            R0, 0, R2, R2, R2   # 0x2b46
        SHRI             R1, R1, 15   # 0x2b4a
        ANDI             R2, R0, 1   # 0x2b4e
        C_CHWIDTH        R0, 1   # 0x2b52
        C_CHWIDTH        R0, 0   # 0x2b54
        SETP_EQ_NP       P0, R1, R1, R2   # 0x2b56
        C_CHWIDTH        R1, 1   # 0x2b5a
        SHRI             R0, R0, 1   # 0x2b5c
        XOR              R1, R0, R7, R0   # 0x2b60
        C_CHWIDTH        R1, 0   # 0x2b64
        MOV_P            R1, 0, R0, R0, R0   # 0x2b66
        MOVI             R0, 65535   # 0x2b6a
        C_AND            R1, R0   # 0x2b6e
        C_RET            224   # 0x2b70
        MOVI             R15, 2   # 0x2b72
        LD_GLOBAL        R15, R15, 24   # 0x2b76
        SRD              R0, 2   # 0x2b7a
        C_ADD            R15, R0   # 0x2b7c
        ST_LOCAL         R8, 196   # 0x2b7e
        C_CHWIDTH        R8, 1   # 0x2b82
        ST_LOCAL         R9, 200   # 0x2b84
        ST_LOCAL         R10, 204   # 0x2b88
        ST_LOCAL         R11, 208   # 0x2b8c
        ST_LOCAL         R12, 212   # 0x2b90
        ST_LOCAL         R13, 216   # 0x2b94
        ST_LOCAL         R14, 184   # 0x2b98
        ST_LOCAL         R2, 120   # 0x2b9c
        LD_GLOBAL_IDX    R0, R1, R2, 0, 60   # 0x2ba0
        SHLI             R0, R0, 16   # 0x2ba4
        LD_GLOBAL_IDX    R5, R1, R2, 0, 56   # 0x2ba8
        SHRI             R4, R5, 16   # 0x2bac
        OR               R6, R0, R4, R0   # 0x2bb0
        MOVI             R0, 65535   # 0x2bb4
        AND              R7, R5, R0, R5   # 0x2bb8
        ST_LOCAL         R1, 104   # 0x2bbc
        LD_GLOBAL_IDX    R8, R1, R2, 0, 4   # 0x2bc0
        MOVI             R2, 0   # 0x2bc4
        C_MOV            R14, R3   # 0x2bc8
        C_CHWIDTH        R14, 1   # 0x2bca
        CVT_SEXT         R3, R8, R8, R8   # 0x2bcc
        SETP_LT_NPI      P0, R3, R3, 1   # 0x2bd0
        BRA_PRED         0, L2f2a   # 0x2bd4
        C_CHWIDTH        R14, 0   # 0x2bd8
        C_MOV            R12, R7   # 0x2bda
        C_CHWIDTH        R7, 1   # 0x2bdc
        C_MOV            R1, R6   # 0x2bde
        ADDI             R7, R8, 255   # 0x2be0
        CHWIDTH_MULTI    384, 0   # 0x2be4
        ST_LOCAL         R7, 128   # 0x2be8
        MOVI             R4, 1   # 0x2bec
        C_MOV            R7, R4   # 0x2bf0
        ST_LOCAL         R7, 108   # 0x2bf2
        MOVI             R4, 255   # 0x2bf6
        C_MOV            R6, R2   # 0x2bfa
        ST_LOCAL         R2, 96   # 0x2bfc
        ST_LOCAL         R2, 116   # 0x2c00
        ST_LOCAL         R14, 124   # 0x2c04
        C_MOV            R5, R14   # 0x2c08
        C_CHWIDTH        R5, 1   # 0x2c0a
        ST_LOCAL         R8, 100   # 0x2c0c
        ST_LOCAL         R4, 112   # 0x2c10
        C_BRA            L2c98   # 0x2c14
L2c16:  C_CHWIDTH        R11, 1   # 0x2c16
        C_MOV            R7, R1   # 0x2c18
        C_MOV            R4, R12   # 0x2c1a
        LD_GLOBAL_IDX    R3, R7, R4, 0, 0   # 0x2c1c
        LD_GLOBAL_IDX    R7, R7, R4, 0, 4   # 0x2c20
        SHLI             R7, R7, 16   # 0x2c24
        SHRI             R14, R3, 16   # 0x2c28
        C_OR             R7, R14   # 0x2c2c
        C_AND            R3, R0   # 0x2c2e
        LD_GLOBAL_IDX    R14, R7, R3, 0, 8   # 0x2c30
        LD_GLOBAL_IDX    R3, R7, R3, 0, 12   # 0x2c34
        SHLI             R3, R3, 16   # 0x2c38
        SHRI             R7, R14, 16   # 0x2c3c
        C_OR             R3, R7   # 0x2c40
        C_CHWIDTH        R3, 1   # 0x2c42
        AND              R7, R14, R0, R14   # 0x2c44
        LD_GLOBAL_IDX    R3, R3, R7, 0, 0   # 0x2c48
        C_CHWIDTH        R3, 0   # 0x2c4c
        SHRI             R3, R3, 8   # 0x2c4e
        LD_LOCAL         R14, 108   # 0x2c52
        AND              R11, R3, R14, R3   # 0x2c56
        LD_LOCAL         R14, 116   # 0x2c5a
        C_CHWIDTH        R14, 1   # 0x2c5e
        ADDI             R14, R14, 1   # 0x2c60
        C_CHWIDTH        R14, 0   # 0x2c64
        ST_LOCAL         R14, 116   # 0x2c66
L2c6a:  CHWIDTH_MULTI    108, 1   # 0x2c6a
        ADD              R6, R11, R6, R11   # 0x2c6e
        C_MOV            R14, R0   # 0x2c72
        XOR              R3, R5, R14, R5   # 0x2c74
        C_CHWIDTH        R3, 0   # 0x2c78
        SHRI             R3, R3, 15   # 0x2c7a
        ADD              R5, R5, R3, R5   # 0x2c7e
        ADDI             R2, R2, 1   # 0x2c82
        C_CHWIDTH        R2, 0   # 0x2c86
        LD_LOCAL         R8, 100   # 0x2c88
        SETP_NE_NP       P0, R3, R2, R8   # 0x2c8c
        LD_LOCAL         R4, 112   # 0x2c90
        BRA_PRED         4, L2ef2   # 0x2c94
L2c98:  C_CHWIDTH        R11, 0   # 0x2c98
        C_MOV            R11, R1   # 0x2c9a
        SHLI             R7, R11, 16   # 0x2c9c
        C_MOV            R9, R12   # 0x2ca0
        AND              R14, R7, R9, R7   # 0x2ca2
        ADD              R8, R7, R9, R7   # 0x2ca6
        C_OR             R7, R9   # 0x2caa
        C_ANDN           R7, R8   # 0x2cac
        OR               R7, R14, R7, R14   # 0x2cae
        SHRI             R7, R7, 31   # 0x2cb2
        SHRI             R14, R11, 16   # 0x2cb6
        ADD              R7, R14, R7, R14   # 0x2cba
        OR               R10, R8, R7, R8   # 0x2cbe
        CVT_SEXT         R7, R5, R5, R5   # 0x2cc2
        MOVI48           R3, 4294967295   # 0x2cc6
        SETP_LT_NP       P0, R7, R3, R7   # 0x2ccc
        BRA_PRED         4, L2d34   # 0x2cd0
        MOVI             R8, 0   # 0x2cd4
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2cd8
        BRA_PRED         0, L2d96   # 0x2cdc
        C_CHWIDTH        R5, 0   # 0x2ce0
        C_MOV            R11, R1   # 0x2ce2
        C_MOV            R9, R12   # 0x2ce4
L2ce6:  LD_GLOBAL_IDX    R7, R11, R9, 0, 8   # 0x2ce6
        LD_GLOBAL_IDX    R14, R11, R9, 0, 12   # 0x2cea
        SHLI             R14, R14, 16   # 0x2cee
        SHRI             R3, R7, 16   # 0x2cf2
        OR               R3, R14, R3, R14   # 0x2cf6
        C_CHWIDTH        R3, 1   # 0x2cfa
        C_AND            R7, R0   # 0x2cfc
        LD_GLOBAL_IDX    R3, R3, R7, 0, 2   # 0x2cfe
        C_CHWIDTH        R3, 0   # 0x2d02
        SETP_EQ_NP       P0, R3, R3, R5   # 0x2d04
        BRA_PRED         0, L2e04   # 0x2d08
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2d0c
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2d10
        SHRI             R14, R7, 16   # 0x2d14
        SHLI             R9, R3, 16   # 0x2d18
        OR               R11, R9, R14, R9   # 0x2d1c
        C_AND            R3, R0   # 0x2d20
        OR               R3, R7, R3, R7   # 0x2d22
        AND              R9, R7, R0, R7   # 0x2d26
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2d2a
        BRA_PRED         4, L2ce6   # 0x2d2e
        C_BRA            L2d96   # 0x2d32
L2d34:  MOVI             R8, 0   # 0x2d34
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2d38
        BRA_PRED         0, L2d96   # 0x2d3c
L2d40:  LD_GLOBAL_IDX    R3, R11, R9, 0, 8   # 0x2d40
        LD_GLOBAL_IDX    R7, R11, R9, 0, 12   # 0x2d44
        SHLI             R7, R7, 16   # 0x2d48
        SHRI             R14, R3, 16   # 0x2d4c
        C_OR             R7, R14   # 0x2d50
        C_CHWIDTH        R14, 1   # 0x2d52
        C_AND            R3, R0   # 0x2d54
        LD_GLOBAL_IDX    R14, R7, R3, 0, 0   # 0x2d56
        C_CHWIDTH        R3, 1   # 0x2d5a
        XOR              R14, R14, R2, R14   # 0x2d5c
        AND              R3, R14, R4, R14   # 0x2d60
        C_CHWIDTH        R3, 0   # 0x2d64
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2d66
        BRA_PRED         0, L2e04   # 0x2d6a
        C_CHWIDTH        R14, 0   # 0x2d6e
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2d70
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2d74
        SHRI             R14, R7, 16   # 0x2d78
        SHLI             R9, R3, 16   # 0x2d7c
        OR               R11, R9, R14, R9   # 0x2d80
        C_AND            R3, R0   # 0x2d84
        OR               R3, R7, R3, R7   # 0x2d86
        AND              R9, R7, R0, R7   # 0x2d8a
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d8e
        BRA_PRED         0, L2d40   # 0x2d92
L2d96:  MOVI             R9, 0   # 0x2d96
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2d9a
        BRA_PRED         0, L2e10   # 0x2d9e
L2da2:  MOVI             R10, 0   # 0x2da2
        MOVI             R14, 0   # 0x2da6
L2daa:  C_MOV            R4, R12   # 0x2daa
        C_MOV            R11, R1   # 0x2dac
        SHLI             R3, R10, 16   # 0x2dae
        AND              R7, R3, R14, R3   # 0x2db2
        ADD              R1, R3, R14, R3   # 0x2db6
        C_OR             R3, R14   # 0x2dba
        C_ANDN           R3, R1   # 0x2dbc
        OR               R3, R7, R3, R7   # 0x2dbe
        SHRI             R3, R3, 31   # 0x2dc2
        SHRI             R7, R10, 16   # 0x2dc6
        ADD              R3, R7, R3, R7   # 0x2dca
        LD_GLOBAL_IDX    R7, R11, R4, 0, 0   # 0x2dce
        ST_GLOBAL_IDX    R1, R11, R4, 0, 0   # 0x2dd2
        LD_GLOBAL_IDX    R14, R11, R4, 0, 4   # 0x2dd6
        ST_GLOBAL_IDX    R3, R11, R4, 0, 4   # 0x2dda
        SHRI             R3, R7, 16   # 0x2dde
        SHLI             R10, R14, 16   # 0x2de2
        OR               R1, R10, R3, R10   # 0x2de6
        AND              R3, R14, R0, R14   # 0x2dea
        OR               R3, R7, R3, R7   # 0x2dee
        AND              R12, R7, R0, R7   # 0x2df2
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2df6
        C_MOV            R10, R11   # 0x2dfa
        C_MOV            R14, R4   # 0x2dfc
        BRA_PRED         0, L2daa   # 0x2dfe
        C_BRA            L2e18   # 0x2e02
L2e04:  C_CHWIDTH        R14, 0   # 0x2e04
        C_MOV            R8, R11   # 0x2e06
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2e08
        BRA_PRED         4, L2da2   # 0x2e0c
L2e10:  MOVI             R11, 0   # 0x2e10
        MOVI             R4, 0   # 0x2e14
L2e18:  C_MOV            R12, R4   # 0x2e18
        C_MOV            R1, R11   # 0x2e1a
        SHLI             R3, R8, 16   # 0x2e1c
        AND              R7, R3, R9, R3   # 0x2e20
        ADD              R14, R3, R9, R3   # 0x2e24
        C_OR             R3, R9   # 0x2e28
        C_ANDN           R3, R14   # 0x2e2a
        OR               R3, R7, R3, R7   # 0x2e2c
        SHRI             R3, R3, 31   # 0x2e30
        SHRI             R7, R8, 16   # 0x2e34
        ADD              R3, R7, R3, R7   # 0x2e38
        OR               R3, R14, R3, R14   # 0x2e3c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2e40
        BRA_PRED         4, L2c16   # 0x2e44
        C_CHWIDTH        R11, 1   # 0x2e48
        LD_GLOBAL_IDX    R3, R8, R9, 0, 12   # 0x2e4a
        SHLI             R3, R3, 16   # 0x2e4e
        LD_GLOBAL_IDX    R7, R8, R9, 0, 8   # 0x2e52
        SHRI             R14, R7, 16   # 0x2e56
        C_OR             R3, R14   # 0x2e5a
        C_CHWIDTH        R3, 1   # 0x2e5c
        C_AND            R7, R0   # 0x2e5e
        LD_GLOBAL_IDX    R3, R3, R7, 0, 0   # 0x2e60
        C_CHWIDTH        R3, 0   # 0x2e64
        LD_GLOBAL_IDX    R14, R8, R9, 0, 4   # 0x2e66
        LD_GLOBAL_IDX    R7, R8, R9, 0, 0   # 0x2e6a
        SHRI             R10, R3, 9   # 0x2e6e
        C_CHWIDTH        R3, 1   # 0x2e72
        AND              R3, R3, R10, R3   # 0x2e74
        AND              R10, R14, R0, R14   # 0x2e78
        OR               R10, R7, R10, R7   # 0x2e7c
        LD_LOCAL         R4, 108   # 0x2e80
        AND              R11, R3, R4, R3   # 0x2e84
        C_CHWIDTH        R3, 0   # 0x2e88
        LD_LOCAL         R3, 96   # 0x2e8a
        C_CHWIDTH        R3, 1   # 0x2e8e
        ADDI             R3, R3, 1   # 0x2e90
        C_CHWIDTH        R3, 0   # 0x2e94
        ST_LOCAL         R3, 96   # 0x2e96
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2e9a
        BRA_PRED         0, L2c6a   # 0x2e9e
        SHRI             R3, R7, 16   # 0x2ea2
        SHLI             R14, R14, 16   # 0x2ea6
        OR               R3, R14, R3, R14   # 0x2eaa
        C_CHWIDTH        R14, 1   # 0x2eae
        C_AND            R7, R0   # 0x2eb0
        LD_GLOBAL_IDX    R14, R3, R7, 0, 4   # 0x2eb2
        C_CHWIDTH        R14, 0   # 0x2eb6
        LD_GLOBAL_IDX    R10, R3, R7, 0, 0   # 0x2eb8
        ST_GLOBAL_IDX    R10, R8, R9, 0, 0   # 0x2ebc
        ST_GLOBAL_IDX    R14, R8, R9, 0, 4   # 0x2ec0
        C_CHWIDTH        R14, 1   # 0x2ec4
        C_MOV            R9, R1   # 0x2ec6
        C_MOV            R4, R12   # 0x2ec8
        LD_GLOBAL_IDX    R14, R9, R4, 0, 4   # 0x2eca
        C_CHWIDTH        R14, 0   # 0x2ece
        LD_GLOBAL_IDX    R8, R9, R4, 0, 0   # 0x2ed0
        ST_GLOBAL_IDX    R8, R3, R7, 0, 0   # 0x2ed4
        ST_GLOBAL_IDX    R14, R3, R7, 0, 4   # 0x2ed8
        SHRI             R14, R3, 16   # 0x2edc
        ST_GLOBAL_IDX    R14, R9, R4, 0, 4   # 0x2ee0
        SHLI             R3, R3, 16   # 0x2ee4
        C_OR             R3, R7   # 0x2ee8
        ST_GLOBAL_IDX    R3, R9, R4, 0, 0   # 0x2eea
        BRA              L2c6a   # 0x2eee
L2ef2:  C_CHWIDTH        R5, 0   # 0x2ef2
        C_CHWIDTH        R2, 1   # 0x2ef4
        MOVI             R0, 255   # 0x2ef6
        LD_LOCAL         R14, 128   # 0x2efa
        AND              R2, R14, R0, R14   # 0x2efe
        C_CHWIDTH        R2, 0   # 0x2f02
        LD_LOCAL         R0, 96   # 0x2f04
        SHLI             R0, R0, 2   # 0x2f08
        LD_LOCAL         R14, 116   # 0x2f0c
        C_CHWIDTH        R14, 1   # 0x2f10
        SUB              R14, R0, R14, R0   # 0x2f12
        C_CHWIDTH        R0, 1   # 0x2f16
        ADD              R0, R14, R6, R14   # 0x2f18
        CHWIDTH_MULTI    16449, 0   # 0x2f1c
        C_MOV            R6, R1   # 0x2f20
        C_MOV            R7, R12   # 0x2f22
        LD_LOCAL         R14, 124   # 0x2f24
        C_BRA            L2f30   # 0x2f28
L2f2a:  C_CHWIDTH        R14, 0   # 0x2f2a
        C_MOV            R5, R14   # 0x2f2c
        C_MOV            R0, R2   # 0x2f2e
L2f30:  C_CHWIDTH        R14, 1   # 0x2f30
        ST_LOCAL         R5, 188   # 0x2f32
        ST_LOCAL         R0, 180   # 0x2f36
        CVT_SEXT         R0, R14, R14, R14   # 0x2f3a
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2f3e
        ST_LOCAL         R2, 192   # 0x2f42
        BRA_PRED         0, L35aa   # 0x2f46
        CHWIDTH_MULTI    18432, 0   # 0x2f4a
        MOVI             R0, 1   # 0x2f4e
        ST_LOCAL         R0, 168   # 0x2f52
        MOVI             R12, 65535   # 0x2f56
        MOVI             R0, 128   # 0x2f5a
        C_MOV            R14, R0   # 0x2f5e
        ST_LOCAL         R14, 108   # 0x2f60
        MOVI             R0, 7   # 0x2f64
        C_MOV            R14, R0   # 0x2f68
        ST_LOCAL         R14, 128   # 0x2f6a
        MOVI             R0, 15   # 0x2f6e
        C_MOV            R14, R0   # 0x2f72
        ST_LOCAL         R14, 132   # 0x2f74
        MOVI             R0, 127   # 0x2f78
        C_MOV            R14, R0   # 0x2f7c
        ST_LOCAL         R14, 112   # 0x2f7e
        MOVI             R0, 65280   # 0x2f82
        C_MOV            R14, R0   # 0x2f86
        ST_LOCAL         R14, 136   # 0x2f88
        C_BRA            L2fbc   # 0x2f8c
L2f8e:  MOVI             R0, 0   # 0x2f8e
        ST_GLOBAL_IDX    R0, R10, R11, 0, 4   # 0x2f92
        ST_GLOBAL_IDX    R0, R10, R11, 0, 0   # 0x2f96
        LD_LOCAL         R0, 168   # 0x2f9a
        C_SHLI           R0, 1   # 0x2f9e
        ST_LOCAL         R0, 168   # 0x2fa0
        LD_LOCAL         R0, 176   # 0x2fa4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2fa8
        LD_LOCAL         R8, 164   # 0x2fac
        C_MOV            R6, R8   # 0x2fb0
        LD_LOCAL         R9, 160   # 0x2fb2
        C_MOV            R7, R9   # 0x2fb6
        BRA_PRED         4, L35b0   # 0x2fb8
L2fbc:  MOVI             R5, 0   # 0x2fbc
        MOVI             R10, 0   # 0x2fc0
        MOVI             R11, 0   # 0x2fc4
        MOVI             R0, 0   # 0x2fc8
        ST_LOCAL         R0, 164   # 0x2fcc
        ST_LOCAL         R0, 160   # 0x2fd0
        C_BRA            L2fe4   # 0x2fd4
L2fd6:  C_CHWIDTH        R8, 0   # 0x2fd6
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2fd8
        LD_LOCAL         R5, 172   # 0x2fdc
        BRA_PRED         0, L2f8e   # 0x2fe0
L2fe4:  LD_LOCAL         R4, 168   # 0x2fe4
        SETP_LT_NPI      P0, R0, R4, 1   # 0x2fe8
        BRA_PRED         0, L302a   # 0x2fec
        MOVI             R2, 0   # 0x2ff0
        C_MOV            R0, R6   # 0x2ff4
        C_MOV            R1, R7   # 0x2ff6
L2ff8:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x2ff8
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x2ffc
        AND              R0, R3, R12, R3   # 0x3000
        OR               R0, R1, R0, R1   # 0x3004
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3008
        BRA_PRED         4, L3034   # 0x300c
        SHRI             R0, R1, 16   # 0x3010
        SHLI             R3, R3, 16   # 0x3014
        OR               R0, R3, R0, R3   # 0x3018
        C_AND            R1, R12   # 0x301c
        C_ADDI           R2, 1   # 0x301e
        SETP_EQ_NP       P0, R3, R4, R2   # 0x3020
        BRA_PRED         4, L2ff8   # 0x3024
        C_BRA            L3040   # 0x3028
L302a:  MOVI             R4, 0   # 0x302a
        C_MOV            R0, R6   # 0x302e
        C_MOV            R1, R7   # 0x3030
        C_BRA            L3040   # 0x3032
L3034:  MOVI             R0, 0   # 0x3034
        ADDI             R4, R2, 1   # 0x3038
        MOVI             R1, 0   # 0x303c
L3040:  ST_LOCAL         R5, 176   # 0x3040
        ADDI             R2, R5, 1   # 0x3044
        ST_LOCAL         R2, 172   # 0x3048
        C_MOV            R9, R6   # 0x304c
        C_MOV            R13, R7   # 0x304e
        C_MOV            R6, R0   # 0x3050
        C_MOV            R7, R1   # 0x3052
        LD_LOCAL         R0, 168   # 0x3054
        ST_LOCAL         R0, 100   # 0x3058
        C_BRA            L3076   # 0x305c
L305e:  ST_LOCAL         R4, 164   # 0x305e
        ST_LOCAL         R5, 160   # 0x3062
L3066:  C_MOV            R9, R1   # 0x3066
        C_MOV            R13, R3   # 0x3068
        C_MOV            R6, R0   # 0x306a
        C_MOV            R7, R2   # 0x306c
        C_MOV            R10, R4   # 0x306e
        C_MOV            R11, R5   # 0x3070
        LD_LOCAL         R4, 96   # 0x3072
L3076:  MOVI             R0, 0   # 0x3076
        SETP_LT_NP       P0, R0, R0, R4   # 0x307a
        BRA_PRED         0, L30ba   # 0x307e
        SHLI             R0, R6, 16   # 0x3082
        AND              R1, R0, R7, R0   # 0x3086
        ADD              R2, R0, R7, R0   # 0x308a
        C_OR             R0, R7   # 0x308e
        C_ANDN           R0, R2   # 0x3090
        OR               R0, R1, R0, R1   # 0x3092
        SHRI             R0, R0, 31   # 0x3096
        SHRI             R1, R6, 16   # 0x309a
        ADD              R0, R1, R0, R1   # 0x309e
        OR               R0, R2, R0, R2   # 0x30a2
        LD_LOCAL         R1, 100   # 0x30a6
        SETP_LT_NPI      P0, R1, R1, 1   # 0x30aa
        BRA_PRED         0, L2fd6   # 0x30ae
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x30b2
        BRA_PRED         0, L2fd6   # 0x30b6
L30ba:  SETP_NE_NPI      P0, R0, R4, 0   # 0x30ba
        BRA_PRED         4, L3212   # 0x30be
        LD_LOCAL         R0, 100   # 0x30c2
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x30c6
        BRA_PRED         0, L3248   # 0x30ca
        SHLI             R0, R6, 16   # 0x30ce
        AND              R1, R0, R7, R0   # 0x30d2
        ADD              R2, R0, R7, R0   # 0x30d6
        C_OR             R0, R7   # 0x30da
        C_ANDN           R0, R2   # 0x30dc
        OR               R0, R1, R0, R1   # 0x30de
        SHRI             R0, R0, 31   # 0x30e2
        SHRI             R1, R6, 16   # 0x30e6
        ADD              R0, R1, R0, R1   # 0x30ea
        OR               R0, R2, R0, R2   # 0x30ee
        SETP_NE_NPI      P0, R0, R0, 0   # 0x30f2
        BRA_PRED         4, L3248   # 0x30f6
        LD_GLOBAL_IDX    R3, R6, R7, 0, 8   # 0x30fa
        ST_LOCAL         R7, 116   # 0x30fe
        LD_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x3102
        LD_GLOBAL_IDX    R0, R9, R13, 0, 8   # 0x3106
        LD_GLOBAL_IDX    R1, R9, R13, 0, 12   # 0x310a
        SHLI             R1, R1, 16   # 0x310e
        SHRI             R2, R0, 16   # 0x3112
        C_OR             R1, R2   # 0x3116
        AND              R2, R0, R12, R0   # 0x3118
        CHWIDTH_MULTI    4097, 1   # 0x311c
        LD_GLOBAL_IDX    R12, R1, R2, 0, 0   # 0x3120
        LD_LOCAL         R7, 108   # 0x3124
        AND              R0, R12, R7, R12   # 0x3128
        C_CHWIDTH        R0, 0   # 0x312c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x312e
        ST_LOCAL         R4, 96   # 0x3132
        BRA_PRED         4, L326e   # 0x3136
        C_CHWIDTH        R0, 1   # 0x313a
        ST_LOCAL         R2, 152   # 0x313c
        ST_LOCAL         R1, 148   # 0x3140
        ST_LOCAL         R5, 144   # 0x3144
        ST_LOCAL         R3, 140   # 0x3148
        LD_LOCAL         R14, 128   # 0x314c
        AND              R0, R12, R14, R12   # 0x3150
        CHWIDTH_MULTI    4097, 0   # 0x3154
        SHRI             R1, R12, 3   # 0x3158
        C_CHWIDTH        R1, 1   # 0x315c
        LD_LOCAL         R14, 132   # 0x315e
        AND              R1, R1, R14, R1   # 0x3162
        C_CHWIDTH        R1, 0   # 0x3166
        MULI             R1, R1, 17   # 0x3168
        C_MOV            R3, R1   # 0x316c
        C_CHWIDTH        R3, 1   # 0x316e
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x3170
        BRA_PRED         0, L327a   # 0x3174
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3178
        C_MOV            R4, R12   # 0x317c
        BRA_PRED         0, L32c6   # 0x317e
        CHWIDTH_MULTI    48, 1   # 0x3182
        CHWIDTH_MULTI    264, 0   # 0x3186
        ST_LOCAL         R13, 156   # 0x318a
        ST_LOCAL         R6, 124   # 0x318e
        MOVI             R0, 34   # 0x3192
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x3196
        C_CHWIDTH        R0, 1   # 0x319a
        MOVI             R6, 34   # 0x319c
        MOV_P            R6, 0, R3, R3, R3   # 0x31a0
        LD_LOCAL         R13, 104   # 0x31a4
        LD_LOCAL         R8, 120   # 0x31a8
        LD_GLOBAL_IDX    R0, R13, R8, 0, 96   # 0x31ac
        C_CHWIDTH        R0, 0   # 0x31b0
        LD_GLOBAL_IDX    R1, R13, R8, 0, 40   # 0x31b2
        LD_GLOBAL_IDX    R5, R13, R8, 0, 2   # 0x31b6
        C_CHWIDTH        R5, 0   # 0x31ba
        LD_GLOBAL_IDX    R4, R13, R8, 0, 0   # 0x31bc
        C_CHWIDTH        R4, 0   # 0x31c0
        LD_GLOBAL_IDX    R3, R13, R8, 0, 32   # 0x31c2
        LD_GLOBAL_IDX    R2, R13, R8, 0, 36   # 0x31c6
        ST_GLOBAL        R0, R15, -4   # 0x31ca
        SHLI             R0, R2, 16   # 0x31ce
        SHRI             R2, R3, 16   # 0x31d2
        OR               R2, R0, R2, R0   # 0x31d6
        MOVI             R0, 65535   # 0x31da
        C_AND            R3, R0   # 0x31de
        CALL             R14, 127077   # 0x31e0
        C_CHWIDTH        R0, 1   # 0x31e4
        MOVI             R15, 2   # 0x31e6
        LD_GLOBAL        R15, R15, 24   # 0x31ea
        SRD              R3, 2   # 0x31ee
        C_ADD            R15, R3   # 0x31f0
        LD_GLOBAL_IDX    R0, R13, R8, 0, 102   # 0x31f2
        C_CHWIDTH        R0, 0   # 0x31f6
        C_MOV            R4, R1   # 0x31f8
        C_CHWIDTH        R4, 1   # 0x31fa
        SETP_NE_NPI      P0, R0, R0, 0   # 0x31fc
        BRA_PRED         0, L3208   # 0x3200
        ST_GLOBAL_IDX    R4, R13, R8, 0, 102   # 0x3204
L3208:  LD_LOCAL         R6, 124   # 0x3208
        LD_LOCAL         R13, 156   # 0x320c
        C_BRA            L32c6   # 0x3210
L3212:  LD_GLOBAL_IDX    R1, R6, R7, 0, 0   # 0x3212
        LD_GLOBAL_IDX    R0, R6, R7, 0, 4   # 0x3216
        SHLI             R0, R0, 16   # 0x321a
        SHRI             R2, R1, 16   # 0x321e
        C_OR             R0, R2   # 0x3222
        AND              R2, R1, R12, R1   # 0x3224
        MOVI             R1, 0   # 0x3228
        ST_LOCAL         R1, 96   # 0x322c
        LD_LOCAL         R1, 100   # 0x3230
        ADDI             R1, R1, -1   # 0x3234
        ST_LOCAL         R1, 100   # 0x3238
        C_MOV            R1, R9   # 0x323c
        C_MOV            R3, R13   # 0x323e
        C_MOV            R4, R6   # 0x3240
        C_MOV            R5, R7   # 0x3242
        BRA              L3550   # 0x3244
L3248:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x3248
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x324c
        SHLI             R1, R1, 16   # 0x3250
        SHRI             R2, R0, 16   # 0x3254
        C_OR             R1, R2   # 0x3258
        AND              R3, R0, R12, R0   # 0x325a
        ADDI             R4, R4, -1   # 0x325e
        ST_LOCAL         R4, 96   # 0x3262
        C_MOV            R0, R6   # 0x3266
        C_MOV            R2, R7   # 0x3268
        BRA              L354c   # 0x326a
L326e:  C_CHWIDTH        R2, 1   # 0x326e
        LD_LOCAL         R14, 112   # 0x3270
        AND              R2, R12, R14, R12   # 0x3274
        C_BRA            L332e   # 0x3278
L327a:  C_CHWIDTH        R3, 0   # 0x327a
        C_CHWIDTH        R4, 1   # 0x327c
        C_CHWIDTH        R8, 0   # 0x327e
        ST_LOCAL         R6, 124   # 0x3280
        LD_LOCAL         R1, 104   # 0x3284
        LD_LOCAL         R8, 120   # 0x3288
        LD_GLOBAL_IDX    R4, R1, R8, 0, 96   # 0x328c
        C_CHWIDTH        R4, 0   # 0x3290
        ADDI             R2, R8, 64   # 0x3292
        CALL             R14, 128349   # 0x3296
        C_CHWIDTH        R0, 1   # 0x329a
        MOVI             R15, 2   # 0x329c
        LD_GLOBAL        R15, R15, 24   # 0x32a0
        SRD              R3, 2   # 0x32a4
        C_ADD            R15, R3   # 0x32a6
        LD_LOCAL         R3, 104   # 0x32a8
        LD_GLOBAL_IDX    R0, R3, R8, 0, 100   # 0x32ac
        C_CHWIDTH        R0, 0   # 0x32b0
        C_MOV            R4, R1   # 0x32b2
        C_CHWIDTH        R4, 1   # 0x32b4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x32b6
        BRA_PRED         0, L32c2   # 0x32ba
        ST_GLOBAL_IDX    R4, R3, R8, 0, 100   # 0x32be
L32c2:  LD_LOCAL         R6, 124   # 0x32c2
L32c6:  CHWIDTH_MULTI    24, 0   # 0x32c6
        C_CHWIDTH        R2, 1   # 0x32ca
        C_CHWIDTH        R8, 0   # 0x32cc
        LD_LOCAL         R5, 120   # 0x32ce
        LD_LOCAL         R8, 104   # 0x32d2
        LD_GLOBAL_IDX    R2, R8, R5, 0, 96   # 0x32d6
        C_CHWIDTH        R2, 0   # 0x32da
        C_MOV            R1, R4   # 0x32dc
        CALL             R14, 129811   # 0x32de
        CHWIDTH_MULTI    6, 1   # 0x32e2
        MOVI             R15, 2   # 0x32e6
        LD_GLOBAL        R15, R15, 24   # 0x32ea
        SRD              R3, 2   # 0x32ee
        C_ADD            R15, R3   # 0x32f0
        ST_GLOBAL_IDX    R1, R8, R5, 0, 96   # 0x32f2
        C_CHWIDTH        R1, 0   # 0x32f6
        LD_LOCAL         R14, 112   # 0x32f8
        AND              R2, R4, R14, R4   # 0x32fc
        LD_LOCAL         R14, 136   # 0x3300
        C_CHWIDTH        R14, 1   # 0x3304
        AND              R14, R12, R14, R12   # 0x3306
        OR               R14, R14, R2, R14   # 0x330a
        LD_LOCAL         R7, 108   # 0x330e
        OR               R14, R14, R7, R14   # 0x3312
        LD_LOCAL         R0, 148   # 0x3316
        LD_LOCAL         R1, 152   # 0x331a
        ST_GLOBAL_IDX    R14, R0, R1, 0, 0   # 0x331e
        LD_LOCAL         R4, 96   # 0x3322
        LD_LOCAL         R3, 140   # 0x3326
        LD_LOCAL         R5, 144   # 0x332a
L332e:  C_CHWIDTH        R12, 1   # 0x332e
        SHLI             R0, R5, 16   # 0x3330
        SHRI             R1, R3, 16   # 0x3334
        OR               R1, R0, R1, R0   # 0x3338
        MOVI             R0, 65535   # 0x333c
        C_AND            R3, R0   # 0x3340
        C_CHWIDTH        R0, 1   # 0x3342
        LD_GLOBAL_IDX    R12, R1, R3, 0, 0   # 0x3344
        AND              R0, R12, R7, R12   # 0x3348
        C_CHWIDTH        R0, 0   # 0x334c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x334e
        BRA_PRED         4, L342e   # 0x3352
        C_CHWIDTH        R0, 1   # 0x3356
        CHWIDTH_MULTI    16388, 0   # 0x3358
        ST_LOCAL         R3, 148   # 0x335c
        ST_LOCAL         R1, 144   # 0x3360
        ST_LOCAL         R2, 140   # 0x3364
        LD_LOCAL         R14, 128   # 0x3368
        AND              R0, R12, R14, R12   # 0x336c
        CHWIDTH_MULTI    4097, 0   # 0x3370
        SHRI             R1, R12, 3   # 0x3374
        C_CHWIDTH        R1, 1   # 0x3378
        LD_LOCAL         R14, 132   # 0x337a
        AND              R1, R1, R14, R1   # 0x337e
        C_CHWIDTH        R1, 0   # 0x3382
        MULI             R1, R1, 17   # 0x3384
        C_MOV            R3, R1   # 0x3388
        C_CHWIDTH        R3, 1   # 0x338a
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x338c
        BRA_PRED         0, L343c   # 0x3390
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3394
        C_MOV            R4, R12   # 0x3398
        BRA_PRED         0, L3488   # 0x339a
        CHWIDTH_MULTI    48, 1   # 0x339e
        CHWIDTH_MULTI    264, 0   # 0x33a2
        ST_LOCAL         R9, 152   # 0x33a6
        ST_LOCAL         R6, 124   # 0x33aa
        MOVI             R0, 34   # 0x33ae
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x33b2
        C_CHWIDTH        R0, 1   # 0x33b6
        MOVI             R6, 34   # 0x33b8
        MOV_P            R6, 0, R3, R3, R3   # 0x33bc
        LD_LOCAL         R9, 104   # 0x33c0
        LD_LOCAL         R8, 120   # 0x33c4
        LD_GLOBAL_IDX    R0, R9, R8, 0, 96   # 0x33c8
        C_CHWIDTH        R0, 0   # 0x33cc
        LD_GLOBAL_IDX    R1, R9, R8, 0, 40   # 0x33ce
        LD_GLOBAL_IDX    R5, R9, R8, 0, 2   # 0x33d2
        C_CHWIDTH        R5, 0   # 0x33d6
        LD_GLOBAL_IDX    R4, R9, R8, 0, 0   # 0x33d8
        C_CHWIDTH        R4, 0   # 0x33dc
        LD_GLOBAL_IDX    R3, R9, R8, 0, 32   # 0x33de
        LD_GLOBAL_IDX    R2, R9, R8, 0, 36   # 0x33e2
        ST_GLOBAL        R0, R15, -4   # 0x33e6
        SHLI             R0, R2, 16   # 0x33ea
        SHRI             R2, R3, 16   # 0x33ee
        OR               R2, R0, R2, R0   # 0x33f2
        MOVI             R0, 65535   # 0x33f6
        C_AND            R3, R0   # 0x33fa
        CALL             R14, 126807   # 0x33fc
        C_CHWIDTH        R0, 1   # 0x3400
        MOVI             R15, 2   # 0x3402
        LD_GLOBAL        R15, R15, 24   # 0x3406
        SRD              R3, 2   # 0x340a
        C_ADD            R15, R3   # 0x340c
        LD_GLOBAL_IDX    R0, R9, R8, 0, 102   # 0x340e
        C_CHWIDTH        R0, 0   # 0x3412
        C_MOV            R4, R1   # 0x3414
        C_CHWIDTH        R4, 1   # 0x3416
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3418
        BRA_PRED         0, L3424   # 0x341c
        ST_GLOBAL_IDX    R4, R9, R8, 0, 102   # 0x3420
L3424:  LD_LOCAL         R6, 124   # 0x3424
        LD_LOCAL         R9, 152   # 0x3428
        C_BRA            L3488   # 0x342c
L342e:  C_CHWIDTH        R0, 1   # 0x342e
        C_CHWIDTH        R14, 0   # 0x3430
        LD_LOCAL         R14, 112   # 0x3432
        AND              R0, R12, R14, R12   # 0x3436
        C_BRA            L34ec   # 0x343a
L343c:  C_CHWIDTH        R3, 0   # 0x343c
        C_CHWIDTH        R4, 1   # 0x343e
        C_CHWIDTH        R8, 0   # 0x3440
        ST_LOCAL         R6, 124   # 0x3442
        LD_LOCAL         R1, 104   # 0x3446
        LD_LOCAL         R8, 120   # 0x344a
        LD_GLOBAL_IDX    R4, R1, R8, 0, 96   # 0x344e
        C_CHWIDTH        R4, 0   # 0x3452
        ADDI             R2, R8, 64   # 0x3454
        CALL             R14, 128124   # 0x3458
        C_CHWIDTH        R0, 1   # 0x345c
        MOVI             R15, 2   # 0x345e
        LD_GLOBAL        R15, R15, 24   # 0x3462
        SRD              R3, 2   # 0x3466
        C_ADD            R15, R3   # 0x3468
        LD_LOCAL         R3, 104   # 0x346a
        LD_GLOBAL_IDX    R0, R3, R8, 0, 100   # 0x346e
        C_CHWIDTH        R0, 0   # 0x3472
        C_MOV            R4, R1   # 0x3474
        C_CHWIDTH        R4, 1   # 0x3476
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3478
        BRA_PRED         0, L3484   # 0x347c
        ST_GLOBAL_IDX    R4, R3, R8, 0, 100   # 0x3480
L3484:  LD_LOCAL         R6, 124   # 0x3484
L3488:  CHWIDTH_MULTI    24, 0   # 0x3488
        C_CHWIDTH        R2, 1   # 0x348c
        C_CHWIDTH        R8, 0   # 0x348e
        LD_LOCAL         R5, 120   # 0x3490
        LD_LOCAL         R8, 104   # 0x3494
        LD_GLOBAL_IDX    R2, R8, R5, 0, 96   # 0x3498
        C_CHWIDTH        R2, 0   # 0x349c
        C_MOV            R1, R4   # 0x349e
        CALL             R14, 129586   # 0x34a0
        CHWIDTH_MULTI    3, 1   # 0x34a4
        MOVI             R15, 2   # 0x34a8
        LD_GLOBAL        R15, R15, 24   # 0x34ac
        SRD              R3, 2   # 0x34b0
        C_ADD            R15, R3   # 0x34b2
        ST_GLOBAL_IDX    R1, R8, R5, 0, 96   # 0x34b4
        C_CHWIDTH        R1, 0   # 0x34b8
        LD_LOCAL         R14, 112   # 0x34ba
        AND              R0, R4, R14, R4   # 0x34be
        LD_LOCAL         R14, 136   # 0x34c2
        C_CHWIDTH        R14, 1   # 0x34c6
        AND              R14, R12, R14, R12   # 0x34c8
        OR               R14, R14, R0, R14   # 0x34cc
        LD_LOCAL         R7, 108   # 0x34d0
        OR               R14, R14, R7, R14   # 0x34d4
        LD_LOCAL         R1, 144   # 0x34d8
        LD_LOCAL         R2, 148   # 0x34dc
        ST_GLOBAL_IDX    R14, R1, R2, 0, 0   # 0x34e0
        LD_LOCAL         R4, 96   # 0x34e4
        LD_LOCAL         R2, 140   # 0x34e8
L34ec:  CHWIDTH_MULTI    4101, 0   # 0x34ec
        SETP_LT_U_NP     P0, R0, R0, R2   # 0x34f0
        LD_LOCAL         R5, 116   # 0x34f4
        MOVI             R12, 65535   # 0x34f8
        BRA_PRED         4, L352a   # 0x34fc
        LD_GLOBAL_IDX    R1, R6, R5, 0, 0   # 0x3500
        LD_GLOBAL_IDX    R0, R6, R5, 0, 4   # 0x3504
        SHLI             R0, R0, 16   # 0x3508
        SHRI             R2, R1, 16   # 0x350c
        C_OR             R0, R2   # 0x3510
        AND              R2, R1, R12, R1   # 0x3512
        LD_LOCAL         R1, 100   # 0x3516
        ADDI             R1, R1, -1   # 0x351a
        ST_LOCAL         R1, 100   # 0x351e
        C_MOV            R1, R9   # 0x3522
        C_MOV            R3, R13   # 0x3524
        C_MOV            R4, R6   # 0x3526
        C_BRA            L3550   # 0x3528
L352a:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x352a
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x352e
        SHLI             R1, R1, 16   # 0x3532
        SHRI             R2, R0, 16   # 0x3536
        C_OR             R1, R2   # 0x353a
        AND              R3, R0, R12, R0   # 0x353c
        ADDI             R4, R4, -1   # 0x3540
        ST_LOCAL         R4, 96   # 0x3544
        C_MOV            R0, R6   # 0x3548
        C_MOV            R2, R5   # 0x354a
L354c:  C_MOV            R4, R9   # 0x354c
        C_MOV            R5, R13   # 0x354e
L3550:  C_CHWIDTH        R14, 0   # 0x3550
        SHLI             R6, R10, 16   # 0x3552
        AND              R7, R6, R11, R6   # 0x3556
        ADD              R14, R6, R11, R6   # 0x355a
        C_OR             R6, R11   # 0x355e
        C_ANDN           R6, R14   # 0x3560
        OR               R6, R7, R6, R7   # 0x3562
        SHRI             R6, R6, 31   # 0x3566
        SHRI             R7, R10, 16   # 0x356a
        ADD              R6, R7, R6, R7   # 0x356e
        OR               R6, R14, R6, R14   # 0x3572
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x3576
        BRA_PRED         0, L305e   # 0x357a
        SHLI             R6, R4, 16   # 0x357e
        ADD              R7, R6, R5, R6   # 0x3582
        ST_GLOBAL_IDX    R7, R10, R11, 0, 0   # 0x3586
        OR               R14, R6, R5, R6   # 0x358a
        ANDN             R7, R14, R7, R14   # 0x358e
        C_AND            R6, R5   # 0x3592
        C_OR             R6, R7   # 0x3594
        SHRI             R6, R6, 31   # 0x3596
        SHRI             R7, R4, 16   # 0x359a
        ADD              R6, R7, R6, R7   # 0x359e
        ST_GLOBAL_IDX    R6, R10, R11, 0, 4   # 0x35a2
        BRA              L3066   # 0x35a6
L35aa:  C_CHWIDTH        R8, 0   # 0x35aa
        C_MOV            R8, R6   # 0x35ac
        C_MOV            R9, R7   # 0x35ae
L35b0:  CHWIDTH_MULTI    18432, 0   # 0x35b0
        C_CHWIDTH        R7, 1   # 0x35b4
        LD_GLOBAL_IDX    R1, R8, R9, 0, 0   # 0x35b6
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x35ba
        SHLI             R0, R0, 16   # 0x35be
        SHRI             R2, R1, 16   # 0x35c2
        OR               R3, R0, R2, R0   # 0x35c6
        MOVI             R0, 65535   # 0x35ca
        AND              R4, R1, R0, R1   # 0x35ce
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x35d2
        SHLI             R1, R1, 16   # 0x35d6
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x35da
        SHRI             R5, R2, 16   # 0x35de
        OR               R5, R1, R5, R1   # 0x35e2
        AND              R6, R2, R0, R2   # 0x35e6
        LD_GLOBAL_IDX    R7, R5, R6, 0, 12   # 0x35ea
        C_CHWIDTH        R7, 0   # 0x35ee
        LD_GLOBAL_IDX    R2, R5, R6, 0, 8   # 0x35f0
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x35f4
        ST_GLOBAL_IDX    R2, R3, R4, 0, 8   # 0x35f8
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x35fc
        ST_GLOBAL_IDX    R7, R3, R4, 0, 12   # 0x3600
        AND              R7, R2, R0, R2   # 0x3604
        ST_GLOBAL_IDX    R7, R5, R6, 0, 12   # 0x3608
        C_CHWIDTH        R7, 1   # 0x360c
        ST_GLOBAL_IDX    R1, R5, R6, 0, 8   # 0x360e
        LD_GLOBAL_IDX    R7, R5, R6, 0, 4   # 0x3612
        C_CHWIDTH        R7, 0   # 0x3616
        LD_GLOBAL_IDX    R14, R5, R6, 0, 0   # 0x3618
        ST_GLOBAL_IDX    R14, R3, R4, 0, 0   # 0x361c
        ST_GLOBAL_IDX    R7, R3, R4, 0, 4   # 0x3620
        LD_LOCAL         R10, 188   # 0x3624
        C_MOV            R4, R10   # 0x3628
        C_CHWIDTH        R4, 1   # 0x362a
        C_MOV            R7, R10   # 0x362c
        C_CHWIDTH        R7, 1   # 0x362e
        C_MOV            R11, R10   # 0x3630
        C_CHWIDTH        R11, 1   # 0x3632
        CVT_SEXT         R3, R4, R7, R11   # 0x3634
        CHWIDTH_MULTI    144, 0   # 0x3638
        MOVI48           R4, 4294967295   # 0x363c
        SETP_LT_NP       P0, R3, R4, R3   # 0x3642
        MOVI             R3, 0   # 0x3646
        ST_GLOBAL_IDX    R3, R5, R6, 0, 4   # 0x364a
        ST_GLOBAL_IDX    R3, R5, R6, 0, 0   # 0x364e
        C_MOV            R13, R8   # 0x3652
        ST_LOCAL         R9, 160   # 0x3654
        BRA_PRED         4, L36a8   # 0x3658
L365c:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x365c
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x3660
        SHLI             R4, R4, 16   # 0x3664
        SHRI             R7, R3, 16   # 0x3668
        C_OR             R4, R7   # 0x366c
        C_AND            R3, R0   # 0x366e
        C_CHWIDTH        R3, 1   # 0x3670
        LD_GLOBAL_IDX    R3, R4, R3, 0, 2   # 0x3672
        C_CHWIDTH        R3, 0   # 0x3676
        SETP_EQ_NP       P0, R3, R3, R10   # 0x3678
        BRA_PRED         0, L36fe   # 0x367c
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x3680
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x3684
        SHRI             R7, R4, 16   # 0x3688
        SHLI             R14, R3, 16   # 0x368c
        OR               R8, R14, R7, R14   # 0x3690
        C_AND            R3, R0   # 0x3694
        OR               R3, R4, R3, R4   # 0x3696
        AND              R9, R4, R0, R4   # 0x369a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x369e
        BRA_PRED         4, L365c   # 0x36a2
        C_BRA            L36f6   # 0x36a6
L36a8:  LD_LOCAL         R10, 192   # 0x36a8
L36ac:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x36ac
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x36b0
        SHLI             R4, R4, 16   # 0x36b4
        SHRI             R7, R3, 16   # 0x36b8
        C_OR             R4, R7   # 0x36bc
        C_AND            R3, R0   # 0x36be
        C_CHWIDTH        R3, 2   # 0x36c0
        LD_GLOBAL_IDX    R3, R4, R3, 0, 0   # 0x36c2
        C_CHWIDTH        R3, 0   # 0x36c6
        SETP_EQ_NP       P0, R3, R3, R10   # 0x36c8
        BRA_PRED         0, L36fe   # 0x36cc
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x36d0
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x36d4
        SHRI             R7, R4, 16   # 0x36d8
        SHLI             R14, R3, 16   # 0x36dc
        OR               R8, R14, R7, R14   # 0x36e0
        C_AND            R3, R0   # 0x36e4
        OR               R3, R4, R3, R4   # 0x36e6
        AND              R9, R4, R0, R4   # 0x36ea
        SETP_NE_NPI      P0, R3, R3, 0   # 0x36ee
        BRA_PRED         0, L36ac   # 0x36f2
L36f6:  MOVI             R8, 0   # 0x36f6
        MOVI             R9, 0   # 0x36fa
L36fe:  SHLI             R2, R2, 16   # 0x36fe
        SHRI             R3, R1, 16   # 0x3702
        SHLI             R4, R8, 16   # 0x3706
        AND              R7, R4, R9, R4   # 0x370a
        ADD              R14, R4, R9, R4   # 0x370e
        C_OR             R4, R9   # 0x3712
        C_ANDN           R4, R14   # 0x3714
        OR               R4, R7, R4, R7   # 0x3716
        SHRI             R4, R4, 31   # 0x371a
        SHRI             R7, R8, 16   # 0x371e
        ADD              R4, R7, R4, R7   # 0x3722
        OR               R4, R14, R4, R14   # 0x3726
        SETP_NE_NPI      P0, R4, R4, 0   # 0x372a
        BRA_PRED         0, L3754   # 0x372e
        C_MOV            R7, R13   # 0x3732
        LD_LOCAL         R14, 160   # 0x3734
        LD_GLOBAL_IDX    R4, R7, R14, 0, 0   # 0x3738
        LD_GLOBAL_IDX    R7, R7, R14, 0, 4   # 0x373c
        SHLI             R7, R7, 16   # 0x3740
        SHRI             R14, R4, 16   # 0x3744
        OR               R8, R7, R14, R7   # 0x3748
        MOVI             R7, 65535   # 0x374c
        AND              R9, R4, R7, R4   # 0x3750
L3754:  C_CHWIDTH        R11, 0   # 0x3754
        OR               R10, R2, R3, R2   # 0x3756
        AND              R11, R1, R0, R1   # 0x375a
        SHLI             R0, R8, 16   # 0x375e
        AND              R1, R0, R9, R0   # 0x3762
        ADD              R2, R0, R9, R0   # 0x3766
        C_OR             R0, R9   # 0x376a
        C_ANDN           R0, R2   # 0x376c
        OR               R0, R1, R0, R1   # 0x376e
        SHRI             R0, R0, 31   # 0x3772
        SHRI             R1, R8, 16   # 0x3776
        ADD              R0, R1, R0, R1   # 0x377a
        OR               R0, R2, R0, R2   # 0x377e
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3782
        BRA_PRED         0, L37f4   # 0x3786
        C_CHWIDTH        R4, 1   # 0x378a
        C_MOV            R1, R13   # 0x378c
        LD_LOCAL         R2, 160   # 0x378e
        LD_GLOBAL_IDX    R0, R1, R2, 0, 8   # 0x3792
        LD_GLOBAL_IDX    R1, R1, R2, 0, 12   # 0x3796
        SHLI             R1, R1, 16   # 0x379a
        SHRI             R2, R0, 16   # 0x379e
        C_OR             R1, R2   # 0x37a2
        MOVI             R12, 65535   # 0x37a4
        C_AND            R0, R12   # 0x37a8
        LD_GLOBAL_IDX    R4, R1, R0, 0, 0   # 0x37aa
        LD_LOCAL         R2, 180   # 0x37ae
L37b2:  CHWIDTH_MULTI    20, 0   # 0x37b2
        C_MOV            R1, R4   # 0x37b6
        CALL             R14, 127383   # 0x37b8
        MOVI             R15, 2   # 0x37bc
        LD_GLOBAL        R15, R15, 24   # 0x37c0
        SRD              R3, 2   # 0x37c4
        C_ADD            R15, R3   # 0x37c6
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x37c8
        LD_GLOBAL_IDX    R2, R8, R9, 0, 0   # 0x37cc
        SHRI             R3, R2, 16   # 0x37d0
        SHLI             R7, R0, 16   # 0x37d4
        OR               R8, R7, R3, R7   # 0x37d8
        C_AND            R0, R12   # 0x37dc
        OR               R0, R2, R0, R2   # 0x37de
        AND              R9, R2, R12, R2   # 0x37e2
        C_MOV            R2, R1   # 0x37e6
        C_CHWIDTH        R2, 1   # 0x37e8
        SETP_NE_NPI      P0, R0, R0, 0   # 0x37ea
        BRA_PRED         0, L37b2   # 0x37ee
        C_BRA            L37f8   # 0x37f2
L37f4:  LD_LOCAL         R2, 180   # 0x37f4
L37f8:  C_CHWIDTH        R3, 1   # 0x37f8
        C_CHWIDTH        R2, 0   # 0x37fa
        ST_LOCAL         R2, 180   # 0x37fc
        LD_LOCAL         R7, 160   # 0x3800
        LD_GLOBAL_IDX    R1, R13, R7, 0, 0   # 0x3804
        LD_GLOBAL_IDX    R0, R13, R7, 0, 4   # 0x3808
        SHLI             R0, R0, 16   # 0x380c
        SHRI             R2, R1, 16   # 0x3810
        OR               R2, R0, R2, R0   # 0x3814
        MOVI             R0, 65535   # 0x3818
        C_AND            R1, R0   # 0x381c
        LD_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x381e
        C_CHWIDTH        R3, 0   # 0x3822
        LD_GLOBAL_IDX    R4, R2, R1, 0, 8   # 0x3824
        ST_GLOBAL_IDX    R4, R5, R6, 0, 8   # 0x3828
        ST_GLOBAL_IDX    R3, R5, R6, 0, 12   # 0x382c
        SHRI             R3, R10, 16   # 0x3830
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x3834
        SHLI             R3, R10, 16   # 0x3838
        C_OR             R3, R11   # 0x383c
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x383e
        C_CHWIDTH        R3, 1   # 0x3842
        LD_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x3844
        C_CHWIDTH        R3, 0   # 0x3848
        LD_GLOBAL_IDX    R4, R2, R1, 0, 0   # 0x384a
        ST_GLOBAL_IDX    R4, R5, R6, 0, 0   # 0x384e
        ST_GLOBAL_IDX    R3, R5, R6, 0, 4   # 0x3852
        SHLI             R3, R5, 16   # 0x3856
        C_OR             R3, R6   # 0x385a
        SHRI             R4, R5, 16   # 0x385c
        ST_GLOBAL_IDX    R4, R2, R1, 0, 4   # 0x3860
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3864
        C_MOV            R1, R13   # 0x3868
        C_MOV            R13, R7   # 0x386a
        MOVI             R9, 1   # 0x386c
        MOVI             R3, 0   # 0x3870
        C_BRA            L3898   # 0x3874
L3876:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x3876
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x387a
        C_SHLI           R9, 1   # 0x387e
        LD_LOCAL         R1, 104   # 0x3880
        SETP_NE_NPI      P0, R1, R1, 0   # 0x3884
        LD_LOCAL         R4, 96   # 0x3888
        C_MOV            R1, R4   # 0x388c
        LD_LOCAL         R7, 100   # 0x388e
        C_MOV            R13, R7   # 0x3892
        BRA_PRED         4, L3ae4   # 0x3894
L3898:  MOVI             R6, 0   # 0x3898
        MOVI             R2, 0   # 0x389c
        MOVI             R4, 0   # 0x38a0
        MOVI             R5, 0   # 0x38a4
        ST_LOCAL         R5, 96   # 0x38a8
        ST_LOCAL         R5, 100   # 0x38ac
        ST_LOCAL         R9, 112   # 0x38b0
        C_BRA            L38c6   # 0x38b4
L38b6:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x38b6
        LD_LOCAL         R9, 112   # 0x38ba
        LD_LOCAL         R6, 108   # 0x38be
        BRA_PRED         0, L3876   # 0x38c2
L38c6:  ST_LOCAL         R6, 104   # 0x38c6
        SETP_LT_NPI      P0, R5, R9, 1   # 0x38ca
        BRA_PRED         0, L390e   # 0x38ce
        MOVI             R5, 0   # 0x38d2
        C_MOV            R6, R1   # 0x38d6
        C_MOV            R7, R13   # 0x38d8
L38da:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x38da
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x38de
        AND              R6, R14, R0, R14   # 0x38e2
        OR               R6, R7, R6, R7   # 0x38e6
        SETP_NE_NPI      P0, R6, R6, 0   # 0x38ea
        BRA_PRED         4, L3918   # 0x38ee
        SHRI             R6, R7, 16   # 0x38f2
        SHLI             R14, R14, 16   # 0x38f6
        OR               R6, R14, R6, R14   # 0x38fa
        C_AND            R7, R0   # 0x38fe
        C_ADDI           R5, 1   # 0x3900
        SETP_EQ_NP       P0, R14, R9, R5   # 0x3902
        BRA_PRED         4, L38da   # 0x3906
        C_MOV            R8, R9   # 0x390a
        C_BRA            L3924   # 0x390c
L390e:  MOVI             R8, 0   # 0x390e
        C_MOV            R6, R1   # 0x3912
        C_MOV            R7, R13   # 0x3914
        C_BRA            L3924   # 0x3916
L3918:  MOVI             R6, 0   # 0x3918
        ADDI             R8, R5, 1   # 0x391c
        MOVI             R7, 0   # 0x3920
L3924:  LD_LOCAL         R5, 104   # 0x3924
        C_ADDI           R5, 1   # 0x3928
        ST_LOCAL         R5, 108   # 0x392a
        C_MOV            R5, R1   # 0x392e
        C_MOV            R14, R13   # 0x3930
        C_MOV            R1, R6   # 0x3932
        C_MOV            R13, R7   # 0x3934
        C_BRA            L394a   # 0x3936
L3938:  ST_LOCAL         R6, 96   # 0x3938
        ST_LOCAL         R7, 100   # 0x393c
L3940:  C_MOV            R5, R11   # 0x3940
        C_MOV            R14, R10   # 0x3942
        C_MOV            R1, R12   # 0x3944
        C_MOV            R2, R6   # 0x3946
        C_MOV            R4, R7   # 0x3948
L394a:  SETP_LT_NP       P0, R6, R3, R8   # 0x394a
        BRA_PRED         0, L3986   # 0x394e
        SHLI             R6, R1, 16   # 0x3952
        AND              R7, R6, R13, R6   # 0x3956
        ADD              R10, R6, R13, R6   # 0x395a
        C_OR             R6, R13   # 0x395e
        C_ANDN           R6, R10   # 0x3960
        OR               R6, R7, R6, R7   # 0x3962
        SHRI             R6, R6, 31   # 0x3966
        SHRI             R7, R1, 16   # 0x396a
        ADD              R6, R7, R6, R7   # 0x396e
        OR               R6, R10, R6, R10   # 0x3972
        SETP_LT_NPI      P0, R7, R9, 1   # 0x3976
        BRA_PRED         0, L38b6   # 0x397a
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x397e
        BRA_PRED         0, L38b6   # 0x3982
L3986:  SETP_NE_NPI      P0, R6, R8, 0   # 0x3986
        BRA_PRED         4, L3a66   # 0x398a
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x398e
        BRA_PRED         0, L3a3e   # 0x3992
        SHLI             R6, R1, 16   # 0x3996
        AND              R7, R6, R13, R6   # 0x399a
        ADD              R10, R6, R13, R6   # 0x399e
        C_OR             R6, R13   # 0x39a2
        C_ANDN           R6, R10   # 0x39a4
        OR               R6, R7, R6, R7   # 0x39a6
        SHRI             R6, R6, 31   # 0x39aa
        SHRI             R7, R1, 16   # 0x39ae
        ADD              R6, R7, R6, R7   # 0x39b2
        OR               R6, R10, R6, R10   # 0x39b6
        SETP_NE_NPI      P0, R6, R6, 0   # 0x39ba
        BRA_PRED         4, L3a3e   # 0x39be
        C_CHWIDTH        R12, 2   # 0x39c2
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x39c4
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x39c8
        SHLI             R7, R7, 16   # 0x39cc
        SHRI             R10, R6, 16   # 0x39d0
        C_OR             R7, R10   # 0x39d4
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x39d6
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x39da
        C_AND            R6, R0   # 0x39de
        LD_GLOBAL_IDX    R12, R7, R6, 0, 1   # 0x39e0
        ST_GLOBAL_IDX    R12, R7, R6, 0, 0   # 0x39e4
        C_CHWIDTH        R7, 1   # 0x39e8
        C_CHWIDTH        R12, 0   # 0x39ea
        SHLI             R11, R11, 16   # 0x39ec
        SHRI             R12, R10, 16   # 0x39f0
        C_OR             R11, R12   # 0x39f4
        C_CHWIDTH        R12, 2   # 0x39f6
        C_AND            R10, R0   # 0x39f8
        LD_GLOBAL_IDX    R12, R11, R10, 0, 1   # 0x39fa
        ST_GLOBAL_IDX    R12, R11, R10, 0, 0   # 0x39fe
        LD_GLOBAL_IDX    R7, R7, R6, 0, 2   # 0x3a02
        C_CHWIDTH        R6, 1   # 0x3a06
        LD_GLOBAL_IDX    R6, R11, R10, 0, 2   # 0x3a08
        CVT_SEXT         R10, R6, R6, R6   # 0x3a0c
        C_CHWIDTH        R6, 0   # 0x3a10
        CVT_SEXT         R6, R7, R7, R7   # 0x3a12
        SETP_LT_NP       P0, R6, R10, R6   # 0x3a16
        BRA_PRED         4, L3a3e   # 0x3a1a
        CHWIDTH_MULTI    4224, 0   # 0x3a1e
        LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x3a22
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x3a26
        SHLI             R7, R7, 16   # 0x3a2a
        SHRI             R10, R6, 16   # 0x3a2e
        OR               R12, R7, R10, R7   # 0x3a32
        C_MOV            R7, R13   # 0x3a36
        AND              R13, R6, R0, R6   # 0x3a38
        C_BRA            L3a84   # 0x3a3c
L3a3e:  CHWIDTH_MULTI    4224, 0   # 0x3a3e
        LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x3a42
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x3a46
        SHLI             R7, R7, 16   # 0x3a4a
        SHRI             R10, R6, 16   # 0x3a4e
        OR               R11, R7, R10, R7   # 0x3a52
        AND              R10, R6, R0, R6   # 0x3a56
        ADDI             R8, R8, -1   # 0x3a5a
        C_MOV            R12, R1   # 0x3a5e
        C_MOV            R6, R5   # 0x3a60
        C_MOV            R7, R14   # 0x3a62
        C_BRA            L3a8e   # 0x3a64
L3a66:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x3a66
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x3a6a
        SHLI             R7, R7, 16   # 0x3a6e
        SHRI             R8, R6, 16   # 0x3a72
        OR               R12, R7, R8, R7   # 0x3a76
        C_MOV            R7, R13   # 0x3a7a
        AND              R13, R6, R0, R6   # 0x3a7c
        MOVI             R8, 0   # 0x3a80
L3a84:  ADDI             R9, R9, -1   # 0x3a84
        C_MOV            R11, R5   # 0x3a88
        C_MOV            R10, R14   # 0x3a8a
        C_MOV            R6, R1   # 0x3a8c
L3a8e:  SHLI             R5, R2, 16   # 0x3a8e
        AND              R14, R5, R4, R5   # 0x3a92
        ADD              R1, R5, R4, R5   # 0x3a96
        C_OR             R5, R4   # 0x3a9a
        C_ANDN           R5, R1   # 0x3a9c
        OR               R5, R14, R5, R14   # 0x3a9e
        SHRI             R5, R5, 31   # 0x3aa2
        SHRI             R14, R2, 16   # 0x3aa6
        ADD              R5, R14, R5, R14   # 0x3aaa
        C_OR             R1, R5   # 0x3aae
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x3ab0
        BRA_PRED         0, L3938   # 0x3ab4
        SHLI             R1, R6, 16   # 0x3ab8
        ADD              R5, R1, R7, R1   # 0x3abc
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x3ac0
        OR               R14, R1, R7, R1   # 0x3ac4
        ANDN             R5, R14, R5, R14   # 0x3ac8
        C_AND            R1, R7   # 0x3acc
        C_OR             R1, R5   # 0x3ace
        SHRI             R1, R1, 31   # 0x3ad0
        SHRI             R5, R6, 16   # 0x3ad4
        ADD              R1, R5, R1, R5   # 0x3ad8
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x3adc
        BRA              L3940   # 0x3ae0
L3ae4:  LD_GLOBAL_IDX    R1, R4, R7, 0, 4   # 0x3ae4
        LD_GLOBAL_IDX    R0, R4, R7, 0, 0   # 0x3ae8
        MOVI             R5, 65535   # 0x3aec
        AND              R2, R1, R5, R1   # 0x3af0
        OR               R2, R0, R2, R0   # 0x3af4
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x3af8
        BRA_PRED         0, L3b6e   # 0x3afc
        SHRI             R2, R0, 16   # 0x3b00
        SHLI             R1, R1, 16   # 0x3b04
        OR               R6, R1, R2, R1   # 0x3b08
        AND              R8, R0, R5, R0   # 0x3b0c
        LD_GLOBAL_IDX    R0, R4, R7, 0, 8   # 0x3b10
        LD_GLOBAL_IDX    R1, R4, R7, 0, 12   # 0x3b14
        C_CHWIDTH        R4, 1   # 0x3b18
        SHLI             R1, R1, 16   # 0x3b1a
        SHRI             R2, R0, 16   # 0x3b1e
        C_OR             R1, R2   # 0x3b22
        C_AND            R0, R5   # 0x3b24
        LD_GLOBAL_IDX    R4, R1, R0, 0, 0   # 0x3b26
        LD_LOCAL         R2, 180   # 0x3b2a
L3b2e:  CHWIDTH_MULTI    20, 0   # 0x3b2e
        C_MOV            R1, R4   # 0x3b32
        CALL             R14, 126937   # 0x3b34
        MOVI             R15, 2   # 0x3b38
        LD_GLOBAL        R15, R15, 24   # 0x3b3c
        SRD              R3, 2   # 0x3b40
        C_ADD            R15, R3   # 0x3b42
        LD_GLOBAL_IDX    R0, R6, R8, 0, 4   # 0x3b44
        LD_GLOBAL_IDX    R2, R6, R8, 0, 0   # 0x3b48
        SHRI             R3, R2, 16   # 0x3b4c
        SHLI             R6, R0, 16   # 0x3b50
        C_OR             R6, R3   # 0x3b54
        C_AND            R0, R5   # 0x3b56
        OR               R0, R2, R0, R2   # 0x3b58
        AND              R8, R2, R5, R2   # 0x3b5c
        C_MOV            R2, R1   # 0x3b60
        C_CHWIDTH        R2, 1   # 0x3b62
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3b64
        BRA_PRED         0, L3b2e   # 0x3b68
        C_BRA            L3b72   # 0x3b6c
L3b6e:  LD_LOCAL         R2, 180   # 0x3b6e
L3b72:  C_CHWIDTH        R2, 0   # 0x3b72
        LD_LOCAL         R14, 184   # 0x3b74
        C_MOV            R1, R2   # 0x3b78
        LD_LOCAL         R13, 216   # 0x3b7a
        LD_LOCAL         R12, 212   # 0x3b7e
        LD_LOCAL         R11, 208   # 0x3b82
        LD_LOCAL         R10, 204   # 0x3b86
        LD_LOCAL         R9, 200   # 0x3b8a
        LD_LOCAL         R8, 196   # 0x3b8e
        C_RET            224   # 0x3b92
        MOVI             R15, 2   # 0x3b94
        LD_GLOBAL        R15, R15, 24   # 0x3b98
        SRD              R14, 2   # 0x3b9c
        C_ADD            R15, R14   # 0x3b9e
        MOVI             R8, 2   # 0x3ba0
        LD_GLOBAL        R0, R8, 36   # 0x3ba4
        MOVI             R1, 2000   # 0x3ba8
        SRD              R2, 0   # 0x3bac
        ST_LOCAL         R2, 220   # 0x3bae
        MADLO            R3, R2, R1, R0   # 0x3bb2
        ADDI             R4, R3, 666   # 0x3bb6
        ST_LOCAL         R4, 224   # 0x3bba
        LD_GLOBAL        R0, R8, 32   # 0x3bbe
        SHLI             R1, R0, 16   # 0x3bc2
        C_MOV            R9, R0   # 0x3bc6
        ADD              R2, R1, R4, R1   # 0x3bc8
        OR               R0, R1, R4, R1   # 0x3bcc
        C_ANDN           R0, R2   # 0x3bd0
        AND              R4, R1, R4, R1   # 0x3bd2
        OR               R0, R4, R0, R4   # 0x3bd6
        ADDI             R4, R3, 1332   # 0x3bda
        ADD              R5, R1, R4, R1   # 0x3bde
        OR               R6, R1, R4, R1   # 0x3be2
        C_ANDN           R6, R5   # 0x3be6
        AND              R4, R1, R4, R1   # 0x3be8
        C_OR             R4, R6   # 0x3bec
        ADD              R6, R1, R3, R1   # 0x3bee
        OR               R7, R1, R3, R1   # 0x3bf2
        C_ANDN           R7, R6   # 0x3bf6
        C_AND            R1, R3   # 0x3bf8
        C_OR             R1, R7   # 0x3bfa
        LD_GLOBAL        R7, R8, 48   # 0x3bfc
        MOVI             R8, 7   # 0x3c00
        ST_GLOBAL        R8, R15, -100   # 0x3c04
        ST_GLOBAL        R7, R15, -104   # 0x3c08
        MOVI             R7, 102   # 0x3c0c
        C_MOV            R8, R7   # 0x3c10
        C_CHWIDTH        R8, 1   # 0x3c12
        ST_GLOBAL        R8, R15, -144   # 0x3c14
        C_CHWIDTH        R8, 0   # 0x3c18
        ST_GLOBAL        R6, R15, -132   # 0x3c1a
        ST_GLOBAL        R6, R15, -140   # 0x3c1e
        ST_GLOBAL        R5, R15, -116   # 0x3c22
        ST_GLOBAL        R2, R15, -124   # 0x3c26
        SHRI             R1, R1, 31   # 0x3c2a
        C_MOV            R2, R9   # 0x3c2e
        ST_LOCAL         R2, 228   # 0x3c30
        SHRI             R5, R2, 16   # 0x3c34
        ADD              R1, R5, R1, R5   # 0x3c38
        ST_GLOBAL        R1, R15, -128   # 0x3c3c
        ST_GLOBAL        R1, R15, -136   # 0x3c40
        SHRI             R1, R4, 31   # 0x3c44
        ADD              R1, R5, R1, R5   # 0x3c48
        ST_GLOBAL        R1, R15, -112   # 0x3c4c
        SHRI             R0, R0, 31   # 0x3c50
        ADD              R0, R5, R0, R5   # 0x3c54
        ST_GLOBAL        R0, R15, -120   # 0x3c58
        MOVI             R0, 0   # 0x3c5c
        ST_GLOBAL        R0, R15, -148   # 0x3c60
        MOVI             R0, 666   # 0x3c64
        ST_GLOBAL        R0, R15, -108   # 0x3c68
        MOVI             R1, 666   # 0x3c6c
        MOVI             R4, 0   # 0x3c70
        CALL             R14, 123332   # 0x3c74
        MOVI             R15, 2   # 0x3c78
        LD_GLOBAL        R15, R15, 24   # 0x3c7c
        SRD              R3, 2   # 0x3c80
        C_ADD            R15, R3   # 0x3c82
        SHLI             R0, R1, 16   # 0x3c84
        ADD              R3, R0, R2, R0   # 0x3c88
        OR               R4, R0, R2, R0   # 0x3c8c
        C_ANDN           R4, R3   # 0x3c90
        ST_GLOBAL        R3, R15, -92   # 0x3c92
        C_AND            R0, R2   # 0x3c96
        C_OR             R0, R4   # 0x3c98
        SHRI             R0, R0, 31   # 0x3c9a
        SHRI             R1, R1, 16   # 0x3c9e
        ADD              R0, R1, R0, R1   # 0x3ca2
        ST_GLOBAL        R0, R15, -88   # 0x3ca6
        MOVI             R0, 65388   # 0x3caa
        ADDI             R6, R0, 64   # 0x3cae
        ADDI             R5, R15, -1   # 0x3cb2
        MOVI             R1, 666   # 0x3cb6
        LD_LOCAL         R2, 228   # 0x3cba
        LD_LOCAL         R3, 224   # 0x3cbe
        MOVI             R4, 0   # 0x3cc2
        CALL             R14, 124484   # 0x3cc6
        C_CHWIDTH        R2, 1   # 0x3cca
        MOVI             R15, 2   # 0x3ccc
        LD_GLOBAL        R15, R15, 24   # 0x3cd0
        SRD              R3, 2   # 0x3cd4
        C_ADD            R15, R3   # 0x3cd6
        MOVI             R0, 65535   # 0x3cd8
        LD_GLOBAL        R1, R15, -116   # 0x3cdc
        AND              R4, R1, R0, R1   # 0x3ce0
        SHRI             R0, R1, 16   # 0x3ce4
        LD_GLOBAL        R1, R15, -112   # 0x3ce8
        SHLI             R1, R1, 16   # 0x3cec
        OR               R3, R1, R0, R1   # 0x3cf0
        LD_GLOBAL        R1, R15, -108   # 0x3cf4
        LD_GLOBAL        R2, R15, -148   # 0x3cf8
        C_CHWIDTH        R2, 0   # 0x3cfc
        CALL             R14, 124831   # 0x3cfe
        MOVI             R15, 2   # 0x3d02
        LD_GLOBAL        R15, R15, 24   # 0x3d06
        SRD              R3, 2   # 0x3d0a
        C_ADD            R15, R3   # 0x3d0c
        MOVI             R1, 0   # 0x3d0e
        ST_GLOBAL        R1, R15, -48   # 0x3d12
        ST_GLOBAL        R1, R15, -52   # 0x3d16
        LD_GLOBAL        R0, R15, -104   # 0x3d1a
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3d1e
        BRA_PRED         0, L3e52   # 0x3d22
        ADDI             R1, R15, -1   # 0x3d26
        MOVI             R8, 1   # 0x3d2a
        MOVI             R2, 65388   # 0x3d2e
        MOVI             R3, 1   # 0x3d32
        CALL             R14, 128796   # 0x3d36
        C_CHWIDTH        R2, 1   # 0x3d3a
        MOVI             R15, 2   # 0x3d3c
        LD_GLOBAL        R15, R15, 24   # 0x3d40
        SRD              R3, 2   # 0x3d44
        C_ADD            R15, R3   # 0x3d46
        LD_GLOBAL        R2, R15, -52   # 0x3d48
        C_CHWIDTH        R2, 0   # 0x3d4c
        CALL             R14, 128475   # 0x3d4e
        C_CHWIDTH        R1, 1   # 0x3d52
        MOVI             R15, 2   # 0x3d54
        LD_GLOBAL        R15, R15, 24   # 0x3d58
        SRD              R3, 2   # 0x3d5c
        C_ADD            R15, R3   # 0x3d5e
        ST_GLOBAL        R1, R15, -52   # 0x3d60
        C_CHWIDTH        R1, 0   # 0x3d64
        ADDI             R1, R15, -1   # 0x3d66
        MOVI             R2, 65388   # 0x3d6a
        MOVI             R3, 65535   # 0x3d6e
        CALL             R14, 128766   # 0x3d72
        C_CHWIDTH        R2, 1   # 0x3d76
        MOVI             R15, 2   # 0x3d78
        LD_GLOBAL        R15, R15, 24   # 0x3d7c
        SRD              R3, 2   # 0x3d80
        C_ADD            R15, R3   # 0x3d82
        LD_GLOBAL        R2, R15, -52   # 0x3d84
        C_CHWIDTH        R2, 0   # 0x3d88
        CALL             R14, 128445   # 0x3d8a
        MOVI             R15, 2   # 0x3d8e
        LD_GLOBAL        R15, R15, 24   # 0x3d92
        SRD              R3, 2   # 0x3d96
        C_ADD            R15, R3   # 0x3d98
        C_MOV            R14, R1   # 0x3d9a
        C_CHWIDTH        R14, 1   # 0x3d9c
        ST_GLOBAL        R14, R15, -50   # 0x3d9e
        ST_GLOBAL        R14, R15, -52   # 0x3da2
        C_CHWIDTH        R14, 0   # 0x3da6
        LD_GLOBAL        R0, R15, -104   # 0x3da8
        SETP_LT_U_NPI    P0, R0, R0, 2   # 0x3dac
        C_MOV            R13, R14   # 0x3db0
        BRA_PRED         0, L3e44   # 0x3db2
L3db6:  C_CHWIDTH        R13, 0   # 0x3db6
        ADDI             R1, R15, -1   # 0x3db8
        MOVI             R2, 65388   # 0x3dbc
        MOVI             R3, 1   # 0x3dc0
        CALL             R14, 128725   # 0x3dc4
        C_CHWIDTH        R2, 1   # 0x3dc8
        MOVI             R15, 2   # 0x3dca
        LD_GLOBAL        R15, R15, 24   # 0x3dce
        SRD              R3, 2   # 0x3dd2
        C_ADD            R15, R3   # 0x3dd4
        LD_GLOBAL        R2, R15, -52   # 0x3dd6
        C_CHWIDTH        R2, 0   # 0x3dda
        CALL             R14, 128404   # 0x3ddc
        C_CHWIDTH        R1, 1   # 0x3de0
        MOVI             R15, 2   # 0x3de2
        LD_GLOBAL        R15, R15, 24   # 0x3de6
        SRD              R3, 2   # 0x3dea
        C_ADD            R15, R3   # 0x3dec
        ST_GLOBAL        R1, R15, -52   # 0x3dee
        C_CHWIDTH        R1, 0   # 0x3df2
        ADDI             R1, R15, -1   # 0x3df4
        MOVI             R2, 65388   # 0x3df8
        MOVI             R3, 65535   # 0x3dfc
        CALL             R14, 128695   # 0x3e00
        C_CHWIDTH        R2, 1   # 0x3e04
        MOVI             R15, 2   # 0x3e06
        LD_GLOBAL        R15, R15, 24   # 0x3e0a
        SRD              R3, 2   # 0x3e0e
        C_ADD            R15, R3   # 0x3e10
        LD_GLOBAL        R2, R15, -52   # 0x3e12
        C_CHWIDTH        R2, 0   # 0x3e16
        CALL             R14, 128374   # 0x3e18
        MOVI             R15, 2   # 0x3e1c
        LD_GLOBAL        R15, R15, 24   # 0x3e20
        SRD              R3, 2   # 0x3e24
        C_ADD            R15, R3   # 0x3e26
        C_ADDI           R8, 1   # 0x3e28
        LD_GLOBAL        R0, R15, -104   # 0x3e2a
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x3e2e
        C_MOV            R13, R1   # 0x3e32
        C_CHWIDTH        R13, 1   # 0x3e34
        ST_GLOBAL        R13, R15, -52   # 0x3e36
        BRA_PRED         0, L3db6   # 0x3e3a
        C_CHWIDTH        R14, 1   # 0x3e3e
        LD_GLOBAL        R14, R15, -50   # 0x3e40
L3e44:  CHWIDTH_MULTI    30720, 1   # 0x3e44
        LD_GLOBAL        R12, R15, -46   # 0x3e48
        LD_GLOBAL        R11, R15, -48   # 0x3e4c
        C_BRA            L3e62   # 0x3e50
L3e52:  C_MOV            R12, R1   # 0x3e52
        C_MOV            R11, R12   # 0x3e54
        C_CHWIDTH        R11, 1   # 0x3e56
        C_MOV            R14, R12   # 0x3e58
        C_CHWIDTH        R14, 1   # 0x3e5a
        C_MOV            R13, R12   # 0x3e5c
        CHWIDTH_MULTI    12288, 1   # 0x3e5e
L3e62:  LD_LOCAL         R1, 220   # 0x3e62
        C_SHLI           R1, 3   # 0x3e66
        MOVI             R0, 2   # 0x3e68
        LD_GLOBAL        R0, R0, 44   # 0x3e6c
        C_ADD            R0, R1   # 0x3e70
        ST_GLOBAL_SLOT   R13, 1, R0, 0, 0   # 0x3e72
        ADDI             R1, R0, 2   # 0x3e76
        ST_GLOBAL_SLOT   R14, 1, R1, 0, 0   # 0x3e7a
        ADDI             R1, R0, 4   # 0x3e7e
        ST_GLOBAL_SLOT   R11, 1, R1, 0, 0   # 0x3e82
        C_ADDI           R0, 6   # 0x3e86
        ST_GLOBAL_SLOT   R12, 1, R0, 0, 0   # 0x3e88
        C_EXIT           0   # 0x3e8c
