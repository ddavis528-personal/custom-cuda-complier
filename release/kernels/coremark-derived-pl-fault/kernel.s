# coremark-derived-pl-fault: test/coremark-derived -DCCV_SEED_PER_LANE, compiled with
# -ccv-test-i16-legal so that it FAULTS (O-81's negative kernel); ccv-as
# source, reassembled byte for byte by tools/ccv-dis.py --check. Load at
# ccv-sim's -code-base (0x1000); the kernel's entry is 0x3aa8.
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
        SZ_GLOBAL_ST_16  R3, R7, R10, 0, 0   # 0x005e
        C_CHWIDTH        R3, 0   # 0x0062
        C_MOV            R3, R2   # 0x0064
        C_CHWIDTH        R3, 1   # 0x0066
        SZ_GLOBAL_ST_16  R3, R7, R10, 0, 2   # 0x0068
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
        SZ_GLOBAL_ST_16  R10, R7, R2, 0, 6   # 0x00da
        C_CHWIDTH        R10, 0   # 0x00de
        MOVI             R10, 65535   # 0x00e0
        C_CHWIDTH        R10, 1   # 0x00e4
        SZ_GLOBAL_ST_16  R10, R7, R2, 0, 4   # 0x00e6
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
        SZ_GLOBAL_ST_16  R3, R7, R10, 0, 2   # 0x02f0
        C_CHWIDTH        R3, 0   # 0x02f4
        SZ_GLOBAL_ST_16  R0, R7, R10, 0, 0   # 0x02f6
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
        SZ_GLOBAL_ST_16  R3, R7, R11, 0, 2   # 0x045e
        C_CHWIDTH        R3, 0   # 0x0462
        LD_LOCAL         R3, 52   # 0x0464
        C_CHWIDTH        R3, 1   # 0x0468
        SZ_GLOBAL_ST_16  R3, R7, R11, 0, 0   # 0x046a
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
        BRA_PRED         0, L093e   # 0x051a
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
        SZ_GLOBAL_ST_16  R1, R7, R10, 0, 2   # 0x05be
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
        SZ_GLOBAL_ST_16  R1, R7, R10, 0, 0   # 0x05e4
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
        SZ_GLOBAL_ST_16  R13, R1, R8, 0, 2   # 0x065c
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
        BRA_PRED         4, L0934   # 0x06e4
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
        BRA_PRED         4, L08b2   # 0x07de
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x07e2
        BRA_PRED         0, L0888   # 0x07e6
        C_CHWIDTH        R12, 0   # 0x07ea
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
        BRA_PRED         4, L0888   # 0x0814
        C_CHWIDTH        R13, 1   # 0x0818
        LD_GLOBAL_IDX    R3, R2, R0, 0, 8   # 0x081a
        LD_GLOBAL_IDX    R15, R2, R0, 0, 12   # 0x081e
        SHLI             R15, R15, 16   # 0x0822
        SHRI             R8, R3, 16   # 0x0826
        C_OR             R15, R8   # 0x082a
        LD_GLOBAL_IDX    R8, R7, R14, 0, 8   # 0x082c
        LD_GLOBAL_IDX    R11, R7, R14, 0, 12   # 0x0830
        C_AND            R3, R5   # 0x0834
        SZ_GLOBAL_LD_U8  R13, R15, R3, 0, 1   # 0x0836
        SZ_GLOBAL_ST_8   R13, R15, R3, 0, 0   # 0x083a
        SHLI             R11, R11, 16   # 0x083e
        SHRI             R12, R8, 16   # 0x0842
        C_OR             R11, R12   # 0x0846
        C_AND            R8, R5   # 0x0848
        SZ_GLOBAL_LD_U8  R13, R11, R8, 0, 1   # 0x084a
        SZ_GLOBAL_ST_8   R13, R11, R8, 0, 0   # 0x084e
        SZ_GLOBAL_LD_U16 R13, R15, R3, 0, 2   # 0x0852
        C_CHWIDTH        R3, 1   # 0x0856
        SZ_GLOBAL_LD_U16 R3, R11, R8, 0, 2   # 0x0858
        CVT_SEXT         R15, R3, R3, R3   # 0x085c
        C_CHWIDTH        R3, 0   # 0x0860
        CVT_SEXT         R3, R13, R13, R13   # 0x0862
        SETP_LT_NP       P0, R3, R15, R3   # 0x0866
        BRA_PRED         4, L0888   # 0x086a
        C_CHWIDTH        R13, 0   # 0x086e
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x0870
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x0874
        SHLI             R15, R15, 16   # 0x0878
        SHRI             R8, R3, 16   # 0x087c
        OR               R13, R15, R8, R15   # 0x0880
        C_AND            R3, R5   # 0x0884
        C_BRA            L08ce   # 0x0886
L0888:  CHWIDTH_MULTI    12288, 0   # 0x0888
        LD_GLOBAL_IDX    R3, R2, R0, 0, 0   # 0x088c
        LD_GLOBAL_IDX    R15, R2, R0, 0, 4   # 0x0890
        SHLI             R15, R15, 16   # 0x0894
        SHRI             R8, R3, 16   # 0x0898
        OR               R12, R15, R8, R15   # 0x089c
        AND              R11, R3, R5, R3   # 0x08a0
        ADDI             R9, R9, -1   # 0x08a4
        C_MOV            R13, R7   # 0x08a8
        C_MOV            R3, R14   # 0x08aa
        C_MOV            R15, R2   # 0x08ac
        C_MOV            R8, R0   # 0x08ae
        C_BRA            L08dc   # 0x08b0
L08b2:  C_CHWIDTH        R13, 0   # 0x08b2
        LD_GLOBAL_IDX    R3, R7, R14, 0, 0   # 0x08b4
        LD_GLOBAL_IDX    R15, R7, R14, 0, 4   # 0x08b8
        SHLI             R15, R15, 16   # 0x08bc
        SHRI             R8, R3, 16   # 0x08c0
        OR               R13, R15, R8, R15   # 0x08c4
        C_AND            R3, R5   # 0x08c8
        MOVI             R9, 0   # 0x08ca
L08ce:  C_CHWIDTH        R12, 0   # 0x08ce
        ADDI             R10, R10, -1   # 0x08d0
        C_MOV            R12, R2   # 0x08d4
        C_MOV            R11, R0   # 0x08d6
        C_MOV            R15, R7   # 0x08d8
        C_MOV            R8, R14   # 0x08da
L08dc:  SHLI             R0, R4, 16   # 0x08dc
        AND              R2, R0, R1, R0   # 0x08e0
        ADD              R7, R0, R1, R0   # 0x08e4
        C_OR             R0, R1   # 0x08e8
        C_ANDN           R0, R7   # 0x08ea
        OR               R0, R2, R0, R2   # 0x08ec
        SHRI             R0, R0, 31   # 0x08f0
        SHRI             R2, R4, 16   # 0x08f4
        ADD              R0, R2, R0, R2   # 0x08f8
        OR               R0, R7, R0, R7   # 0x08fc
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x0900
        BRA_PRED         0, L078a   # 0x0904
        SHLI             R0, R15, 16   # 0x0908
        ADD              R2, R0, R8, R0   # 0x090c
        ST_GLOBAL_IDX    R2, R4, R1, 0, 0   # 0x0910
        OR               R7, R0, R8, R0   # 0x0914
        ANDN             R2, R7, R2, R7   # 0x0918
        C_AND            R0, R8   # 0x091c
        C_OR             R0, R2   # 0x091e
        SHRI             R0, R0, 31   # 0x0920
        SHRI             R2, R15, 16   # 0x0924
        ADD              R0, R2, R0, R2   # 0x0928
        ST_GLOBAL_IDX    R0, R4, R1, 0, 4   # 0x092c
        BRA              L0792   # 0x0930
L0934:  CHWIDTH_MULTI    12288, 0   # 0x0934
        LD_LOCAL         R14, 68   # 0x0938
        C_RET            224   # 0x093c
L093e:  LD_LOCAL         R1, 12   # 0x093e
        C_MOV            R9, R3   # 0x0942
        LD_LOCAL         R11, 32   # 0x0944
        BRA              L05f6   # 0x0948
        ST_LOCAL         R14, 44   # 0x094c
        ST_LOCAL         R6, 48   # 0x0950
        ST_LOCAL         R5, 52   # 0x0954
        ST_LOCAL         R3, 24   # 0x0958
        C_MOV            R0, R1   # 0x095c
        MOVI             R7, 1   # 0x095e
        SETP_LT_U_NP     P0, R1, R7, R4   # 0x0962
        MOV_P            R7, 0, R4, R4, R4   # 0x0966
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x096a
        BRA_PRED         0, L0992   # 0x096e
        MOVI48           R9, 4294967295   # 0x0972
        MOVI             R3, 8   # 0x0978
L097c:  ADDI             R4, R9, 2   # 0x097c
        MUL_LO           R4, R3, R4, R4   # 0x0980
        SETP_LT_U_NP     P0, R4, R4, R0   # 0x0984
        C_ADDI           R3, 8   # 0x0988
        C_ADDI           R9, 1   # 0x098a
        BRA_PRED         0, L097c   # 0x098c
        C_BRA            L0998   # 0x0990
L0992:  MOVI48           R9, 4294967295   # 0x0992
L0998:  SHLI             R1, R2, 16   # 0x0998
        LD_LOCAL         R0, 24   # 0x099c
        ADD              R0, R1, R0, R1   # 0x09a0
        ST_LOCAL         R1, 56   # 0x09a4
        SETP_LT_U_NP     P0, R3, R0, R1   # 0x09a8
        SHRI             R3, R2, 16   # 0x09ac
        ST_LOCAL         R3, 60   # 0x09b0
        ADDI_P           R3, 0, R3, 1   # 0x09b4
        C_NEG            R4, R0   # 0x09b8
        ANDI             R1, R4, 3   # 0x09ba
        ST_LOCAL         R1, 32   # 0x09be
        ADD              R4, R0, R1, R0   # 0x09c2
        SETP_LT_U_NP     P0, R0, R4, R0   # 0x09c6
        ADDI_P           R3, 0, R3, 1   # 0x09ca
        MUL_LO           R1, R9, R9, R9   # 0x09ce
        SHRI             R0, R1, 31   # 0x09d2
        ADD              R0, R3, R0, R3   # 0x09d6
        C_SHLI           R1, 1   # 0x09da
        ST_LOCAL         R1, 28   # 0x09dc
        ADD              R3, R4, R1, R4   # 0x09e0
        SETP_LT_U_NP     P0, R3, R3, R4   # 0x09e4
        ADDI_P           R0, 0, R0, 1   # 0x09e8
        SETP_EQ_NPI      P0, R0, R9, 0   # 0x09ec
        BRA_PRED         0, L0b82   # 0x09f0
        C_CHWIDTH        R0, 1   # 0x09f4
        LD_LOCAL         R1, 24   # 0x09f6
        C_MOV            R14, R1   # 0x09fa
        MOVI             R11, 0   # 0x09fc
        C_MOV            R6, R11   # 0x0a00
        SUB              R0, R6, R14, R6   # 0x0a02
        C_CHWIDTH        R0, 0   # 0x0a06
        C_ANDI           R0, 3   # 0x0a08
        ADD              R10, R1, R0, R1   # 0x0a0a
        MOVI             R15, 1   # 0x0a0e
        C_MOV            R12, R9   # 0x0a12
        C_SHLI           R12, 1   # 0x0a14
        ANDI             R13, R9, -2   # 0x0a16
        ANDI             R0, R9, 1   # 0x0a1a
        ST_LOCAL         R0, 12   # 0x0a1e
        LD_LOCAL         R0, 28   # 0x0a22
        ADD              R14, R10, R0, R10   # 0x0a26
        MOVI48           R0, 4294901760   # 0x0a2a
        MOVI             R3, 255   # 0x0a30
        C_MOV            R6, R3   # 0x0a34
        MOVI             R4, 0   # 0x0a36
        ST_LOCAL         R9, 36   # 0x0a3a
        ST_LOCAL         R12, 40   # 0x0a3e
        C_BRA            L0a56   # 0x0a42
L0a44:  C_CHWIDTH        R5, 0   # 0x0a44
        C_ADD            R14, R12   # 0x0a46
        C_ADD            R10, R12   # 0x0a48
        C_ADD            R11, R9   # 0x0a4a
        C_ADDI           R4, 1   # 0x0a4c
        SETP_NE_NP       P0, R1, R4, R9   # 0x0a4e
        BRA_PRED         4, L0b82   # 0x0a52
L0a56:  SETP_EQ_NPI      P0, R3, R9, 1   # 0x0a56
        BRA_PRED         4, L0a64   # 0x0a5a
        MOVI             R8, 0   # 0x0a5e
        C_BRA            L0b1a   # 0x0a62
L0a64:  ST_LOCAL         R4, 20   # 0x0a64
        ST_LOCAL         R11, 16   # 0x0a68
        MOVI             R3, 0   # 0x0a6c
        C_MOV            R11, R15   # 0x0a70
        C_SHLI           R11, 1   # 0x0a72
        MOVI             R8, 0   # 0x0a74
L0a78:  C_CHWIDTH        R5, 0   # 0x0a78
        ADD              R4, R15, R8, R15   # 0x0a7a
        MUL_LO           R12, R7, R4, R4   # 0x0a7e
        SRAI             R9, R12, 31   # 0x0a82
        SHRI             R9, R9, 16   # 0x0a86
        MADLO            R7, R7, R4, R9   # 0x0a8a
        C_AND            R7, R0   # 0x0a8e
        SUB              R7, R12, R7, R12   # 0x0a90
        ADD              R9, R14, R3, R14   # 0x0a94
        ADD              R12, R4, R7, R4   # 0x0a98
        SZ_GLOBAL_ST_16  R12, R2, R9, 0, 0   # 0x0a9c
        ADD              R12, R10, R3, R10   # 0x0aa0
        ADD              R5, R11, R3, R11   # 0x0aa4
        ADD              R1, R5, R7, R5   # 0x0aa8
        C_CHWIDTH        R1, 1   # 0x0aac
        AND              R1, R1, R6, R1   # 0x0aae
        SZ_GLOBAL_ST_16  R1, R2, R12, 0, 0   # 0x0ab2
        C_CHWIDTH        R1, 0   # 0x0ab6
        ADDI             R1, R4, 1   # 0x0ab8
        MUL_LO           R4, R7, R1, R1   # 0x0abc
        C_MOV            R0, R13   # 0x0ac0
        SRAI             R13, R4, 31   # 0x0ac2
        SHRI             R13, R13, 16   # 0x0ac6
        MADLO            R7, R7, R1, R13   # 0x0aca
        C_MOV            R13, R0   # 0x0ace
        MOVI48           R0, 4294901760   # 0x0ad0
        C_AND            R7, R0   # 0x0ad6
        SUB              R7, R4, R7, R4   # 0x0ad8
        ADDI             R4, R9, 2   # 0x0adc
        C_ADD            R1, R7   # 0x0ae0
        SZ_GLOBAL_ST_16  R1, R2, R4, 0, 0   # 0x0ae2
        ADD              R1, R5, R7, R5   # 0x0ae6
        C_CHWIDTH        R5, 1   # 0x0aea
        ADDI             R5, R1, 2   # 0x0aec
        AND              R5, R5, R6, R5   # 0x0af0
        ADDI             R1, R12, 2   # 0x0af4
        SZ_GLOBAL_ST_16  R5, R2, R1, 0, 0   # 0x0af8
        C_ADDI           R3, 4   # 0x0afc
        C_ADDI           R8, 2   # 0x0afe
        SETP_NE_NP       P0, R1, R13, R8   # 0x0b00
        BRA_PRED         0, L0a78   # 0x0b04
        C_ADD            R15, R8   # 0x0b08
        LD_LOCAL         R9, 36   # 0x0b0a
        LD_LOCAL         R11, 16   # 0x0b0e
        LD_LOCAL         R12, 40   # 0x0b12
        LD_LOCAL         R4, 20   # 0x0b16
L0b1a:  C_CHWIDTH        R5, 0   # 0x0b1a
        LD_LOCAL         R0, 12   # 0x0b1c
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x0b20
        MOVI48           R0, 4294901760   # 0x0b24
        BRA_PRED         0, L0a44   # 0x0b2a
        MUL_LO           R1, R4, R9, R9   # 0x0b2e
        MUL_LO           R3, R7, R15, R15   # 0x0b32
        C_MOV            R5, R4   # 0x0b36
        SRAI             R4, R3, 31   # 0x0b38
        SHRI             R4, R4, 16   # 0x0b3c
        MAD_ACC          R4, R7, R15   # 0x0b40
        C_AND            R4, R0   # 0x0b42
        SUB              R7, R3, R4, R3   # 0x0b44
        LD_LOCAL         R3, 24   # 0x0b48
        LD_LOCAL         R4, 32   # 0x0b4c
        C_ADD            R3, R4   # 0x0b50
        ADD              R1, R8, R1, R8   # 0x0b52
        C_SHLI           R1, 1   # 0x0b56
        ADD              R1, R3, R1, R3   # 0x0b58
        LD_LOCAL         R3, 28   # 0x0b5c
        ADD              R3, R1, R3, R1   # 0x0b60
        ADD              R4, R7, R15, R7   # 0x0b64
        SZ_GLOBAL_ST_16  R4, R2, R3, 0, 0   # 0x0b68
        ADD              R3, R4, R15, R4   # 0x0b6c
        C_MOV            R4, R5   # 0x0b70
        C_CHWIDTH        R5, 1   # 0x0b72
        AND              R5, R3, R6, R3   # 0x0b74
        SZ_GLOBAL_ST_16  R5, R2, R1, 0, 0   # 0x0b78
        C_ADDI           R15, 1   # 0x0b7c
        BRA              L0a44   # 0x0b7e
L0b82:  LD_LOCAL         R0, 24   # 0x0b82
        LD_LOCAL         R1, 32   # 0x0b86
        C_ADD            R0, R1   # 0x0b8a
        LD_LOCAL         R7, 56   # 0x0b8c
        ADD              R1, R7, R0, R7   # 0x0b90
        OR               R2, R7, R0, R7   # 0x0b94
        C_ANDN           R2, R1   # 0x0b98
        AND              R3, R7, R0, R7   # 0x0b9a
        OR               R2, R3, R2, R3   # 0x0b9e
        LD_LOCAL         R3, 28   # 0x0ba2
        C_ADD            R0, R3   # 0x0ba6
        ADD              R3, R0, R3, R0   # 0x0ba8
        ADD              R4, R7, R3, R7   # 0x0bac
        C_NEG            R4, R4   # 0x0bb0
        C_ANDI           R4, 3   # 0x0bb2
        C_ADD            R3, R4   # 0x0bb4
        ADD              R4, R7, R0, R7   # 0x0bb6
        OR               R5, R7, R0, R7   # 0x0bba
        C_ANDN           R5, R4   # 0x0bbe
        AND              R0, R7, R0, R7   # 0x0bc0
        C_OR             R0, R5   # 0x0bc4
        LD_LOCAL         R5, 48   # 0x0bc6
        LD_LOCAL         R6, 52   # 0x0bca
        ST_GLOBAL_IDX    R1, R6, R5, 0, 8   # 0x0bce
        ST_GLOBAL_IDX    R4, R6, R5, 0, 16   # 0x0bd2
        SHRI             R1, R2, 31   # 0x0bd6
        LD_LOCAL         R2, 60   # 0x0bda
        ADD              R1, R2, R1, R2   # 0x0bde
        ST_GLOBAL_IDX    R1, R6, R5, 0, 12   # 0x0be2
        SHRI             R0, R0, 31   # 0x0be6
        ADD              R0, R2, R0, R2   # 0x0bea
        ST_GLOBAL_IDX    R0, R6, R5, 0, 20   # 0x0bee
        ADD              R0, R7, R3, R7   # 0x0bf2
        ST_GLOBAL_IDX    R0, R6, R5, 0, 24   # 0x0bf6
        OR               R1, R7, R3, R7   # 0x0bfa
        ANDN             R0, R1, R0, R1   # 0x0bfe
        AND              R1, R7, R3, R7   # 0x0c02
        OR               R0, R1, R0, R1   # 0x0c06
        SHRI             R0, R0, 31   # 0x0c0a
        ADD              R0, R2, R0, R2   # 0x0c0e
        ST_GLOBAL_IDX    R0, R6, R5, 0, 28   # 0x0c12
        ST_GLOBAL_IDX    R9, R6, R5, 0, 0   # 0x0c16
        LD_LOCAL         R14, 44   # 0x0c1a
        C_MOV            R1, R9   # 0x0c1e
        C_RET            224   # 0x0c20
        ST_LOCAL         R14, 12   # 0x0c22
        MOVI             R0, 0   # 0x0c26
        ST_LOCAL         R1, 16   # 0x0c2a
        ADDI             R5, R1, -1   # 0x0c2e
        SETP_LT_U_NPI    P0, R6, R5, 2   # 0x0c32
        BRA_PRED         0, L0d42   # 0x0c36
        C_CHWIDTH        R2, 1   # 0x0c3a
        MOVI             R9, 0   # 0x0c3c
        MOVI             R6, 2   # 0x0c40
        MOVI             R7, 65535   # 0x0c44
        MOVI             R10, 0   # 0x0c48
        MOVI             R8, 0   # 0x0c4c
        C_BRA            L0c8c   # 0x0c50
L0c52:  MOVI             R8, 8   # 0x0c52
        MOVI             R9, 96   # 0x0c56
L0c5a:  ANDI             R1, R2, 24   # 0x0c5a
        ADD              R1, R9, R1, R9   # 0x0c5e
        LD_GLOBAL        R14, R6, 28   # 0x0c62
        LD_GLOBAL_IDX    R15, R14, R1, 0, 0   # 0x0c66
        LD_GLOBAL_IDX    R1, R14, R1, 0, 4   # 0x0c6a
        SHLI             R1, R1, 16   # 0x0c6e
        SHRI             R14, R15, 16   # 0x0c72
        OR               R9, R1, R14, R1   # 0x0c76
        AND              R10, R15, R7, R15   # 0x0c7a
        ADD              R1, R0, R8, R0   # 0x0c7e
        C_ADDI           R1, 1   # 0x0c82
        SETP_LT_U_NP     P0, R1, R1, R5   # 0x0c84
        BRA_PRED         4, L0d42   # 0x0c88
L0c8c:  SETP_EQ_NPI      P0, R11, R8, 0   # 0x0c8c
        BRA_PRED         0, L0cfe   # 0x0c90
        SETP_LT_U_NPI    P0, R11, R8, 4   # 0x0c94
        BRA_PRED         0, L0cee   # 0x0c98
        ADD              R11, R4, R0, R4   # 0x0c9c
        MOVI             R12, 0   # 0x0ca0
L0ca4:  ADD              R13, R11, R12, R11   # 0x0ca4
        ADD              R15, R12, R10, R12   # 0x0ca8
        SZ_GLOBAL_LD_U8  R14, R9, R15, 0, 0   # 0x0cac
        SZ_GLOBAL_ST_8   R14, R3, R13, 0, 0   # 0x0cb0
        ADDI             R14, R15, 1   # 0x0cb4
        SZ_GLOBAL_LD_U8  R14, R9, R14, 0, 0   # 0x0cb8
        ADDI             R1, R13, 1   # 0x0cbc
        SZ_GLOBAL_ST_8   R14, R3, R1, 0, 0   # 0x0cc0
        ADDI             R1, R15, 2   # 0x0cc4
        SZ_GLOBAL_LD_U8  R1, R9, R1, 0, 0   # 0x0cc8
        ADDI             R14, R13, 2   # 0x0ccc
        SZ_GLOBAL_ST_8   R1, R3, R14, 0, 0   # 0x0cd0
        ADDI             R1, R15, 3   # 0x0cd4
        SZ_GLOBAL_LD_U8  R1, R9, R1, 0, 0   # 0x0cd8
        ADDI             R14, R13, 3   # 0x0cdc
        SZ_GLOBAL_ST_8   R1, R3, R14, 0, 0   # 0x0ce0
        C_ADDI           R12, 4   # 0x0ce4
        SETP_NE_NP       P0, R1, R8, R12   # 0x0ce6
        BRA_PRED         0, L0ca4   # 0x0cea
L0cee:  C_ADD            R0, R8   # 0x0cee
        ADD              R1, R0, R4, R0   # 0x0cf0
        MOVI             R14, 44   # 0x0cf4
        SZ_GLOBAL_ST_8   R14, R3, R1, 0, 0   # 0x0cf8
        C_ADDI           R0, 1   # 0x0cfc
L0cfe:  C_CHWIDTH        R2, 1   # 0x0cfe
        ADDI             R2, R2, 1   # 0x0d00
        C_CHWIDTH        R2, 0   # 0x0d04
        ANDI             R10, R2, 7   # 0x0d06
        MOVI             R8, 4   # 0x0d0a
        SETP_LT_NP       P0, R1, R8, R10   # 0x0d0e
        BRA_PRED         0, L0d2c   # 0x0d12
        MOVI             R9, 0   # 0x0d16
        SETP_LT_U_NPI    P0, R1, R10, 3   # 0x0d1a
        BRA_PRED         0, L0c5a   # 0x0d1e
        MOVI             R8, 8   # 0x0d22
        MOVI             R9, 32   # 0x0d26
        C_BRA            L0c5a   # 0x0d2a
L0d2c:  ADDI             R1, R10, -5   # 0x0d2c
        SETP_LT_U_NPI    P0, R1, R1, 2   # 0x0d30
        BRA_PRED         4, L0c52   # 0x0d34
        MOVI             R8, 8   # 0x0d38
        MOVI             R9, 64   # 0x0d3c
        C_BRA            L0c5a   # 0x0d40
L0d42:  LD_LOCAL         R1, 16   # 0x0d42
        SETP_LE_U_NP     P0, R2, R1, R0   # 0x0d46
        BRA_PRED         0, L0de4   # 0x0d4a
        SUB              R2, R1, R0, R1   # 0x0d4e
        ANDI             R5, R2, 7   # 0x0d52
        SETP_EQ_NPI      P0, R2, R5, 0   # 0x0d56
        C_MOV            R2, R0   # 0x0d5a
        BRA_PRED         0, L0d7c   # 0x0d5c
        MOVI             R6, 0   # 0x0d60
        C_MOV            R2, R0   # 0x0d64
L0d66:  ADD              R7, R4, R2, R4   # 0x0d66
        SZ_GLOBAL_ST_8   R6, R3, R7, 0, 0   # 0x0d6a
        C_ADDI           R2, 1   # 0x0d6e
        ADDI             R5, R5, -1   # 0x0d70
        SETP_NE_NPI      P0, R7, R5, 0   # 0x0d74
        BRA_PRED         0, L0d66   # 0x0d78
L0d7c:  C_SUB            R0, R1   # 0x0d7c
        MOVI48           R5, 4294967288   # 0x0d7e
        SETP_LT_U_NP     P0, R0, R5, R0   # 0x0d84
        BRA_PRED         0, L0de4   # 0x0d88
        ADDI             R0, R2, 7   # 0x0d8c
        C_NEG            R1, R1   # 0x0d90
        MOVI             R2, 0   # 0x0d92
L0d96:  ADD              R5, R4, R0, R4   # 0x0d96
        ADDI             R6, R5, -7   # 0x0d9a
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0d9e
        ADDI             R6, R5, -6   # 0x0da2
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0da6
        ADDI             R6, R5, -5   # 0x0daa
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0dae
        ADDI             R6, R5, -4   # 0x0db2
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0db6
        ADDI             R6, R5, -3   # 0x0dba
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0dbe
        ADDI             R6, R5, -2   # 0x0dc2
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0dc6
        ADDI             R6, R5, -1   # 0x0dca
        SZ_GLOBAL_ST_8   R2, R3, R6, 0, 0   # 0x0dce
        SZ_GLOBAL_ST_8   R2, R3, R5, 0, 0   # 0x0dd2
        C_ADDI           R0, 8   # 0x0dd6
        ADD              R5, R1, R0, R1   # 0x0dd8
        SETP_NE_NPI      P0, R5, R5, 7   # 0x0ddc
        BRA_PRED         0, L0d96   # 0x0de0
L0de4:  LD_LOCAL         R14, 12   # 0x0de4
        C_RET            224   # 0x0de8
        CHWIDTH_MULTI    12, 1   # 0x0dea
        C_MOV            R0, R1   # 0x0dee
        C_CHWIDTH        R0, 1   # 0x0df0
        XOR              R3, R0, R2, R0   # 0x0df2
        CHWIDTH_MULTI    13, 0   # 0x0df6
        C_ANDI           R3, 1   # 0x0dfa
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0dfc
        MOVI             R3, 40961   # 0x0e00
        C_MOV            R7, R3   # 0x0e04
        C_CHWIDTH        R3, 1   # 0x0e06
        SHRI             R2, R2, 1   # 0x0e08
        XOR              R3, R2, R7, R2   # 0x0e0c
        C_CHWIDTH        R3, 0   # 0x0e10
        MOV_P            R2, 0, R3, R3, R3   # 0x0e12
        C_CHWIDTH        R2, 1   # 0x0e16
        SHRI             R3, R0, 1   # 0x0e18
        C_CHWIDTH        R3, 1   # 0x0e1c
        XOR              R3, R3, R2, R3   # 0x0e1e
        CHWIDTH_MULTI    12, 0   # 0x0e22
        C_ANDI           R3, 1   # 0x0e26
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e28
        C_CHWIDTH        R3, 1   # 0x0e2c
        SHRI             R2, R2, 1   # 0x0e2e
        XOR              R3, R2, R7, R2   # 0x0e32
        C_CHWIDTH        R3, 0   # 0x0e36
        MOV_P            R2, 0, R3, R3, R3   # 0x0e38
        C_CHWIDTH        R2, 1   # 0x0e3c
        SHRI             R3, R0, 2   # 0x0e3e
        C_CHWIDTH        R3, 1   # 0x0e42
        XOR              R3, R3, R2, R3   # 0x0e44
        CHWIDTH_MULTI    12, 0   # 0x0e48
        C_ANDI           R3, 1   # 0x0e4c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e4e
        C_CHWIDTH        R3, 1   # 0x0e52
        SHRI             R2, R2, 1   # 0x0e54
        XOR              R3, R2, R7, R2   # 0x0e58
        C_CHWIDTH        R3, 0   # 0x0e5c
        MOV_P            R2, 0, R3, R3, R3   # 0x0e5e
        C_CHWIDTH        R2, 1   # 0x0e62
        SHRI             R3, R0, 3   # 0x0e64
        C_CHWIDTH        R3, 1   # 0x0e68
        XOR              R3, R3, R2, R3   # 0x0e6a
        CHWIDTH_MULTI    12, 0   # 0x0e6e
        C_ANDI           R3, 1   # 0x0e72
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e74
        C_CHWIDTH        R3, 1   # 0x0e78
        SHRI             R2, R2, 1   # 0x0e7a
        XOR              R3, R2, R7, R2   # 0x0e7e
        C_CHWIDTH        R3, 0   # 0x0e82
        MOV_P            R2, 0, R3, R3, R3   # 0x0e84
        C_CHWIDTH        R2, 1   # 0x0e88
        SHRI             R3, R0, 4   # 0x0e8a
        C_CHWIDTH        R3, 1   # 0x0e8e
        XOR              R3, R3, R2, R3   # 0x0e90
        CHWIDTH_MULTI    12, 0   # 0x0e94
        C_ANDI           R3, 1   # 0x0e98
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0e9a
        C_CHWIDTH        R3, 1   # 0x0e9e
        SHRI             R2, R2, 1   # 0x0ea0
        XOR              R3, R2, R7, R2   # 0x0ea4
        C_CHWIDTH        R3, 0   # 0x0ea8
        MOV_P            R2, 0, R3, R3, R3   # 0x0eaa
        C_CHWIDTH        R2, 1   # 0x0eae
        SHRI             R3, R0, 5   # 0x0eb0
        C_CHWIDTH        R3, 1   # 0x0eb4
        XOR              R3, R3, R2, R3   # 0x0eb6
        CHWIDTH_MULTI    12, 0   # 0x0eba
        C_ANDI           R3, 1   # 0x0ebe
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0ec0
        C_CHWIDTH        R3, 1   # 0x0ec4
        SHRI             R2, R2, 1   # 0x0ec6
        XOR              R3, R2, R7, R2   # 0x0eca
        C_CHWIDTH        R3, 0   # 0x0ece
        MOV_P            R2, 0, R3, R3, R3   # 0x0ed0
        C_CHWIDTH        R2, 1   # 0x0ed4
        SHRI             R3, R0, 6   # 0x0ed6
        C_CHWIDTH        R3, 1   # 0x0eda
        XOR              R3, R3, R2, R3   # 0x0edc
        CHWIDTH_MULTI    12, 0   # 0x0ee0
        C_ANDI           R3, 1   # 0x0ee4
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0ee6
        C_CHWIDTH        R3, 1   # 0x0eea
        SHRI             R2, R2, 1   # 0x0eec
        XOR              R3, R2, R7, R2   # 0x0ef0
        C_CHWIDTH        R3, 0   # 0x0ef4
        MOV_P            R2, 0, R3, R3, R3   # 0x0ef6
        MOVI             R3, 128   # 0x0efa
        C_MOV            R6, R3   # 0x0efe
        C_CHWIDTH        R3, 1   # 0x0f00
        AND              R3, R0, R6, R0   # 0x0f02
        C_CHWIDTH        R3, 0   # 0x0f06
        SHRI             R3, R3, 7   # 0x0f08
        ANDI             R4, R2, 1   # 0x0f0c
        C_CHWIDTH        R2, 1   # 0x0f10
        C_CHWIDTH        R2, 0   # 0x0f12
        SETP_EQ_NP       P0, R3, R3, R4   # 0x0f14
        C_CHWIDTH        R3, 1   # 0x0f18
        SHRI             R2, R2, 1   # 0x0f1a
        XOR              R3, R2, R7, R2   # 0x0f1e
        C_CHWIDTH        R3, 0   # 0x0f22
        MOV_P            R3, 0, R2, R2, R2   # 0x0f24
        C_CHWIDTH        R3, 1   # 0x0f28
        SHRI             R2, R0, 8   # 0x0f2a
        C_CHWIDTH        R2, 1   # 0x0f2e
        XOR              R2, R3, R2, R3   # 0x0f30
        CHWIDTH_MULTI    12, 0   # 0x0f34
        C_ANDI           R2, 1   # 0x0f38
        SETP_NE_NPI      P0, R2, R2, 0   # 0x0f3a
        SHRI             R2, R3, 1   # 0x0f3e
        C_CHWIDTH        R3, 1   # 0x0f42
        XOR              R3, R2, R7, R2   # 0x0f44
        C_CHWIDTH        R3, 0   # 0x0f48
        MOV_P            R2, 0, R3, R3, R3   # 0x0f4a
        C_CHWIDTH        R2, 1   # 0x0f4e
        SHRI             R3, R0, 9   # 0x0f50
        C_CHWIDTH        R3, 1   # 0x0f54
        XOR              R3, R3, R2, R3   # 0x0f56
        CHWIDTH_MULTI    12, 0   # 0x0f5a
        C_ANDI           R3, 1   # 0x0f5e
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f60
        C_CHWIDTH        R3, 1   # 0x0f64
        SHRI             R2, R2, 1   # 0x0f66
        XOR              R3, R2, R7, R2   # 0x0f6a
        C_CHWIDTH        R3, 0   # 0x0f6e
        MOV_P            R2, 0, R3, R3, R3   # 0x0f70
        C_CHWIDTH        R2, 1   # 0x0f74
        SHRI             R3, R0, 10   # 0x0f76
        C_CHWIDTH        R3, 1   # 0x0f7a
        XOR              R3, R3, R2, R3   # 0x0f7c
        CHWIDTH_MULTI    12, 0   # 0x0f80
        C_ANDI           R3, 1   # 0x0f84
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0f86
        C_CHWIDTH        R3, 1   # 0x0f8a
        SHRI             R2, R2, 1   # 0x0f8c
        XOR              R3, R2, R7, R2   # 0x0f90
        C_CHWIDTH        R3, 0   # 0x0f94
        MOV_P            R2, 0, R3, R3, R3   # 0x0f96
        C_CHWIDTH        R2, 1   # 0x0f9a
        SHRI             R3, R0, 11   # 0x0f9c
        C_CHWIDTH        R3, 1   # 0x0fa0
        XOR              R3, R3, R2, R3   # 0x0fa2
        CHWIDTH_MULTI    12, 0   # 0x0fa6
        C_ANDI           R3, 1   # 0x0faa
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fac
        C_CHWIDTH        R3, 1   # 0x0fb0
        SHRI             R2, R2, 1   # 0x0fb2
        XOR              R3, R2, R7, R2   # 0x0fb6
        C_CHWIDTH        R3, 0   # 0x0fba
        MOV_P            R2, 0, R3, R3, R3   # 0x0fbc
        C_CHWIDTH        R2, 1   # 0x0fc0
        SHRI             R3, R0, 12   # 0x0fc2
        C_CHWIDTH        R3, 1   # 0x0fc6
        XOR              R3, R3, R2, R3   # 0x0fc8
        CHWIDTH_MULTI    12, 0   # 0x0fcc
        C_ANDI           R3, 1   # 0x0fd0
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0fd2
        C_CHWIDTH        R3, 1   # 0x0fd6
        SHRI             R2, R2, 1   # 0x0fd8
        XOR              R3, R2, R7, R2   # 0x0fdc
        C_CHWIDTH        R3, 0   # 0x0fe0
        MOV_P            R2, 0, R3, R3, R3   # 0x0fe2
        C_CHWIDTH        R2, 1   # 0x0fe6
        SHRI             R3, R0, 13   # 0x0fe8
        C_CHWIDTH        R3, 1   # 0x0fec
        XOR              R3, R3, R2, R3   # 0x0fee
        CHWIDTH_MULTI    12, 0   # 0x0ff2
        C_ANDI           R3, 1   # 0x0ff6
        SETP_NE_NPI      P0, R3, R3, 0   # 0x0ff8
        C_CHWIDTH        R3, 1   # 0x0ffc
        SHRI             R2, R2, 1   # 0x0ffe
        XOR              R3, R2, R7, R2   # 0x1002
        C_CHWIDTH        R3, 0   # 0x1006
        MOV_P            R2, 0, R3, R3, R3   # 0x1008
        C_CHWIDTH        R2, 1   # 0x100c
        SHRI             R3, R0, 14   # 0x100e
        C_CHWIDTH        R3, 1   # 0x1012
        XOR              R3, R3, R2, R3   # 0x1014
        CHWIDTH_MULTI    12, 0   # 0x1018
        C_ANDI           R3, 1   # 0x101c
        SETP_NE_NPI      P0, R3, R3, 0   # 0x101e
        C_CHWIDTH        R3, 1   # 0x1022
        SHRI             R2, R2, 1   # 0x1024
        XOR              R3, R2, R7, R2   # 0x1028
        C_CHWIDTH        R3, 0   # 0x102c
        MOV_P            R2, 0, R3, R3, R3   # 0x102e
        SHRI             R0, R0, 15   # 0x1032
        ANDI             R3, R2, 1   # 0x1036
        C_CHWIDTH        R2, 1   # 0x103a
        C_CHWIDTH        R2, 0   # 0x103c
        SETP_EQ_NP       P0, R0, R0, R3   # 0x103e
        SHRI             R0, R2, 1   # 0x1042
        C_CHWIDTH        R2, 1   # 0x1046
        XOR              R2, R0, R7, R0   # 0x1048
        C_CHWIDTH        R2, 0   # 0x104c
        MOV_P            R2, 0, R0, R0, R0   # 0x104e
        C_CHWIDTH        R2, 1   # 0x1052
        SHRI             R0, R1, 16   # 0x1054
        C_MOV            R5, R0   # 0x1058
        C_CHWIDTH        R0, 1   # 0x105a
        XOR              R0, R2, R5, R2   # 0x105c
        CHWIDTH_MULTI    5, 0   # 0x1060
        C_ANDI           R0, 1   # 0x1064
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1066
        SHRI             R0, R2, 1   # 0x106a
        C_CHWIDTH        R2, 1   # 0x106e
        XOR              R2, R0, R7, R0   # 0x1070
        C_CHWIDTH        R2, 0   # 0x1074
        MOV_P            R0, 0, R2, R2, R2   # 0x1076
        SHRI             R2, R1, 17   # 0x107a
        C_XOR            R2, R0   # 0x107e
        C_CHWIDTH        R0, 1   # 0x1080
        C_CHWIDTH        R0, 0   # 0x1082
        C_ANDI           R2, 1   # 0x1084
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1086
        C_CHWIDTH        R2, 1   # 0x108a
        SHRI             R0, R0, 1   # 0x108c
        XOR              R2, R0, R7, R0   # 0x1090
        C_CHWIDTH        R2, 0   # 0x1094
        MOV_P            R0, 0, R2, R2, R2   # 0x1096
        SHRI             R2, R1, 18   # 0x109a
        C_XOR            R2, R0   # 0x109e
        C_CHWIDTH        R0, 1   # 0x10a0
        C_CHWIDTH        R0, 0   # 0x10a2
        C_ANDI           R2, 1   # 0x10a4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x10a6
        C_CHWIDTH        R2, 1   # 0x10aa
        SHRI             R0, R0, 1   # 0x10ac
        XOR              R2, R0, R7, R0   # 0x10b0
        C_CHWIDTH        R2, 0   # 0x10b4
        MOV_P            R0, 0, R2, R2, R2   # 0x10b6
        SHRI             R2, R1, 19   # 0x10ba
        C_XOR            R2, R0   # 0x10be
        C_CHWIDTH        R0, 1   # 0x10c0
        C_CHWIDTH        R0, 0   # 0x10c2
        C_ANDI           R2, 1   # 0x10c4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x10c6
        C_CHWIDTH        R2, 1   # 0x10ca
        SHRI             R0, R0, 1   # 0x10cc
        XOR              R2, R0, R7, R0   # 0x10d0
        C_CHWIDTH        R2, 0   # 0x10d4
        MOV_P            R0, 0, R2, R2, R2   # 0x10d6
        SHRI             R2, R1, 20   # 0x10da
        C_XOR            R2, R0   # 0x10de
        C_CHWIDTH        R0, 1   # 0x10e0
        C_CHWIDTH        R0, 0   # 0x10e2
        C_ANDI           R2, 1   # 0x10e4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x10e6
        C_CHWIDTH        R2, 1   # 0x10ea
        SHRI             R0, R0, 1   # 0x10ec
        XOR              R2, R0, R7, R0   # 0x10f0
        C_CHWIDTH        R2, 0   # 0x10f4
        MOV_P            R0, 0, R2, R2, R2   # 0x10f6
        SHRI             R2, R1, 21   # 0x10fa
        C_XOR            R2, R0   # 0x10fe
        C_CHWIDTH        R0, 1   # 0x1100
        C_CHWIDTH        R0, 0   # 0x1102
        C_ANDI           R2, 1   # 0x1104
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1106
        C_CHWIDTH        R2, 1   # 0x110a
        SHRI             R0, R0, 1   # 0x110c
        XOR              R2, R0, R7, R0   # 0x1110
        C_CHWIDTH        R2, 0   # 0x1114
        MOV_P            R0, 0, R2, R2, R2   # 0x1116
        SHRI             R2, R1, 22   # 0x111a
        C_XOR            R2, R0   # 0x111e
        C_CHWIDTH        R0, 1   # 0x1120
        C_CHWIDTH        R0, 0   # 0x1122
        C_ANDI           R2, 1   # 0x1124
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1126
        C_CHWIDTH        R2, 1   # 0x112a
        SHRI             R0, R0, 1   # 0x112c
        XOR              R2, R0, R7, R0   # 0x1130
        C_CHWIDTH        R2, 0   # 0x1134
        MOV_P            R0, 0, R2, R2, R2   # 0x1136
        C_CHWIDTH        R2, 1   # 0x113a
        AND              R2, R5, R6, R5   # 0x113c
        C_CHWIDTH        R2, 0   # 0x1140
        SHRI             R2, R2, 7   # 0x1142
        ANDI             R3, R0, 1   # 0x1146
        C_CHWIDTH        R0, 1   # 0x114a
        C_CHWIDTH        R0, 0   # 0x114c
        SETP_EQ_NP       P0, R2, R2, R3   # 0x114e
        C_CHWIDTH        R2, 1   # 0x1152
        SHRI             R0, R0, 1   # 0x1154
        XOR              R2, R0, R7, R0   # 0x1158
        C_CHWIDTH        R2, 0   # 0x115c
        MOV_P            R2, 0, R0, R0, R0   # 0x115e
        SHRI             R0, R1, 24   # 0x1162
        XOR              R0, R2, R0, R2   # 0x1166
        C_CHWIDTH        R2, 1   # 0x116a
        C_CHWIDTH        R2, 0   # 0x116c
        C_ANDI           R0, 1   # 0x116e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1170
        SHRI             R0, R2, 1   # 0x1174
        C_CHWIDTH        R2, 1   # 0x1178
        XOR              R2, R0, R7, R0   # 0x117a
        C_CHWIDTH        R2, 0   # 0x117e
        MOV_P            R0, 0, R2, R2, R2   # 0x1180
        SHRI             R2, R1, 25   # 0x1184
        C_XOR            R2, R0   # 0x1188
        C_CHWIDTH        R0, 1   # 0x118a
        C_CHWIDTH        R0, 0   # 0x118c
        C_ANDI           R2, 1   # 0x118e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1190
        C_CHWIDTH        R2, 1   # 0x1194
        SHRI             R0, R0, 1   # 0x1196
        XOR              R2, R0, R7, R0   # 0x119a
        C_CHWIDTH        R2, 0   # 0x119e
        MOV_P            R0, 0, R2, R2, R2   # 0x11a0
        SHRI             R2, R1, 26   # 0x11a4
        C_XOR            R2, R0   # 0x11a8
        C_CHWIDTH        R0, 1   # 0x11aa
        C_CHWIDTH        R0, 0   # 0x11ac
        C_ANDI           R2, 1   # 0x11ae
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11b0
        C_CHWIDTH        R2, 1   # 0x11b4
        SHRI             R0, R0, 1   # 0x11b6
        XOR              R2, R0, R7, R0   # 0x11ba
        C_CHWIDTH        R2, 0   # 0x11be
        MOV_P            R0, 0, R2, R2, R2   # 0x11c0
        SHRI             R2, R1, 27   # 0x11c4
        C_XOR            R2, R0   # 0x11c8
        C_CHWIDTH        R0, 1   # 0x11ca
        C_CHWIDTH        R0, 0   # 0x11cc
        C_ANDI           R2, 1   # 0x11ce
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11d0
        C_CHWIDTH        R2, 1   # 0x11d4
        SHRI             R0, R0, 1   # 0x11d6
        XOR              R2, R0, R7, R0   # 0x11da
        C_CHWIDTH        R2, 0   # 0x11de
        MOV_P            R0, 0, R2, R2, R2   # 0x11e0
        SHRI             R2, R1, 28   # 0x11e4
        C_XOR            R2, R0   # 0x11e8
        C_CHWIDTH        R0, 1   # 0x11ea
        C_CHWIDTH        R0, 0   # 0x11ec
        C_ANDI           R2, 1   # 0x11ee
        SETP_NE_NPI      P0, R2, R2, 0   # 0x11f0
        C_CHWIDTH        R2, 1   # 0x11f4
        SHRI             R0, R0, 1   # 0x11f6
        XOR              R2, R0, R7, R0   # 0x11fa
        C_CHWIDTH        R2, 0   # 0x11fe
        MOV_P            R0, 0, R2, R2, R2   # 0x1200
        SHRI             R2, R1, 29   # 0x1204
        C_XOR            R2, R0   # 0x1208
        C_CHWIDTH        R0, 1   # 0x120a
        C_CHWIDTH        R0, 0   # 0x120c
        C_ANDI           R2, 1   # 0x120e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1210
        C_CHWIDTH        R2, 1   # 0x1214
        SHRI             R0, R0, 1   # 0x1216
        XOR              R2, R0, R7, R0   # 0x121a
        C_CHWIDTH        R2, 0   # 0x121e
        MOV_P            R0, 0, R2, R2, R2   # 0x1220
        SHRI             R2, R1, 30   # 0x1224
        C_XOR            R2, R0   # 0x1228
        C_CHWIDTH        R0, 1   # 0x122a
        C_CHWIDTH        R0, 0   # 0x122c
        C_ANDI           R2, 1   # 0x122e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1230
        C_CHWIDTH        R2, 1   # 0x1234
        SHRI             R0, R0, 1   # 0x1236
        XOR              R2, R0, R7, R0   # 0x123a
        C_CHWIDTH        R2, 0   # 0x123e
        MOV_P            R0, 0, R2, R2, R2   # 0x1240
        SHRI             R1, R1, 31   # 0x1244
        ANDI             R2, R0, 1   # 0x1248
        C_CHWIDTH        R0, 1   # 0x124c
        C_CHWIDTH        R0, 0   # 0x124e
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1250
        C_CHWIDTH        R1, 1   # 0x1254
        SHRI             R0, R0, 1   # 0x1256
        XOR              R1, R0, R7, R0   # 0x125a
        C_CHWIDTH        R1, 0   # 0x125e
        MOV_P            R1, 0, R0, R0, R0   # 0x1260
        MOVI             R0, 65535   # 0x1264
        C_AND            R1, R0   # 0x1268
        C_RET            224   # 0x126a
        MOVI             R15, 2   # 0x126c
        LD_GLOBAL        R15, R15, 24   # 0x1270
        SRD              R0, 2   # 0x1274
        C_ADD            R15, R0   # 0x1276
        ST_LOCAL         R8, 60   # 0x1278
        ST_LOCAL         R9, 64   # 0x127c
        ST_LOCAL         R10, 68   # 0x1280
        ST_LOCAL         R11, 72   # 0x1284
        ST_LOCAL         R12, 76   # 0x1288
        ST_LOCAL         R13, 80   # 0x128c
        ST_LOCAL         R14, 44   # 0x1290
        ST_LOCAL         R5, 52   # 0x1294
        C_MOV            R13, R3   # 0x1298
        C_CHWIDTH        R3, 1   # 0x129a
        ST_LOCAL         R1, 36   # 0x129c
        ADDI             R0, R15, -1   # 0x12a0
        MOVI             R1, 65532   # 0x12a4
        SZ_GLOBAL_LD_U16 R3, R0, R1, 0, 0   # 0x12a8
        C_CHWIDTH        R3, 0   # 0x12ac
        ST_LOCAL         R3, 48   # 0x12ae
        MOVI             R9, 0   # 0x12b2
        ST_GLOBAL        R9, R15, -8   # 0x12b6
        ST_GLOBAL        R9, R15, -12   # 0x12ba
        ST_GLOBAL        R9, R15, -16   # 0x12be
        ST_GLOBAL        R9, R15, -20   # 0x12c2
        ST_GLOBAL        R9, R15, -24   # 0x12c6
        ST_GLOBAL        R9, R15, -28   # 0x12ca
        ST_GLOBAL        R9, R15, -32   # 0x12ce
        ST_GLOBAL        R9, R15, -36   # 0x12d2
        SZ_GLOBAL_LD_U8  R0, R2, R13, 0, 0   # 0x12d6
        C_MOV            R5, R6   # 0x12da
        C_MOV            R6, R0   # 0x12dc
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x12de
        MOVI             R12, 0   # 0x12e2
        MOVI             R0, 0   # 0x12e6
        ST_LOCAL         R0, 20   # 0x12ea
        ST_LOCAL         R0, 16   # 0x12ee
        ST_LOCAL         R0, 12   # 0x12f2
        ST_LOCAL         R0, 28   # 0x12f6
        ST_LOCAL         R0, 24   # 0x12fa
        BRA_PRED         0, L1576   # 0x12fe
        ST_LOCAL         R5, 56   # 0x1302
        ST_LOCAL         R4, 40   # 0x1306
        MOVI             R0, 255   # 0x130a
        C_MOV            R14, R0   # 0x130e
        MOVI             R0, 3   # 0x1310
        MOVI             R10, 5   # 0x1314
        MOVI             R1, 223   # 0x1318
        C_MOV            R7, R1   # 0x131c
        ST_LOCAL         R7, 32   # 0x131e
        MOVI             R7, 0   # 0x1322
        MOVI             R1, 0   # 0x1326
        ST_LOCAL         R1, 20   # 0x132a
        ST_LOCAL         R1, 16   # 0x132e
        ST_LOCAL         R1, 12   # 0x1332
        ST_LOCAL         R1, 28   # 0x1336
        ST_LOCAL         R1, 24   # 0x133a
        MOVI             R4, 0   # 0x133e
        C_MOV            R3, R6   # 0x1342
        MOVI             R11, 0   # 0x1344
        C_MOV            R12, R13   # 0x1348
        C_BRA            L134e   # 0x134a
L134c:  C_MOV            R12, R1   # 0x134c
L134e:  C_CHWIDTH        R5, 1   # 0x134e
        AND              R5, R3, R14, R3   # 0x1350
        C_CHWIDTH        R5, 0   # 0x1354
        SETP_NE_NPI      P0, R1, R5, 44   # 0x1356
        ADDI             R1, R12, 1   # 0x135a
        BRA_PRED         0, L137e   # 0x135e
L1362:  LD_GLOBAL_IDX    R3, R15, R11, 1, -36   # 0x1362
        C_ADDI           R3, 1   # 0x1366
        ST_GLOBAL_IDX    R3, R15, R11, 1, -36   # 0x1368
        SZ_GLOBAL_LD_U8  R3, R2, R1, 0, 0   # 0x136c
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x1370
        BRA_PRED         0, L156c   # 0x1374
        MOVI             R11, 0   # 0x1378
        C_BRA            L134c   # 0x137c
L137e:  SETP_LT_NP       P0, R8, R0, R11   # 0x137e
        BRA_PRED         4, L13bc   # 0x1382
        SETP_LT_NP       P0, R8, R10, R11   # 0x1386
        BRA_PRED         0, L13ec   # 0x138a
        SETP_EQ_NPI      P0, R8, R11, 4   # 0x138e
        BRA_PRED         0, L146c   # 0x1392
        SETP_EQ_NPI      P0, R5, R11, 5   # 0x1396
        BRA_PRED         4, L1554   # 0x139a
        LD_LOCAL         R5, 32   # 0x139e
        C_CHWIDTH        R5, 1   # 0x13a2
        AND              R5, R3, R5, R3   # 0x13a4
        C_CHWIDTH        R5, 0   # 0x13a8
        SETP_NE_NPI      P0, R5, R5, 69   # 0x13aa
        BRA_PRED         0, L14f8   # 0x13ae
        MOVI             R11, 3   # 0x13b2
        C_ADDI           R7, 1   # 0x13b6
        BRA              L1554   # 0x13b8
L13bc:  SETP_EQ_NPI      P0, R8, R11, 0   # 0x13bc
        BRA_PRED         0, L142e   # 0x13c0
        SETP_EQ_NPI      P0, R8, R11, 2   # 0x13c4
        BRA_PRED         0, L14a2   # 0x13c8
        SETP_EQ_NPI      P0, R3, R11, 3   # 0x13cc
        BRA_PRED         4, L1554   # 0x13d0
        SETP_EQ_NPI      P0, R3, R5, 45   # 0x13d4
        BRA_PRED         0, L13e4   # 0x13d8
        SETP_NE_NPI      P0, R3, R5, 43   # 0x13dc
        BRA_PRED         0, L1530   # 0x13e0
L13e4:  MOVI             R11, 6   # 0x13e4
        BRA              L1534   # 0x13e8
L13ec:  SETP_EQ_NPI      P0, R5, R11, 6   # 0x13ec
        BRA_PRED         0, L147a   # 0x13f0
        SETP_EQ_NPI      P0, R5, R11, 7   # 0x13f4
        BRA_PRED         4, L1554   # 0x13f8
        C_CHWIDTH        R5, 1   # 0x13fc
        ADDI             R5, R3, -58   # 0x13fe
        C_CHWIDTH        R3, 1   # 0x1402
        AND              R3, R5, R14, R5   # 0x1404
        CHWIDTH_MULTI    40, 0   # 0x1408
        MOVI             R5, 245   # 0x140c
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x1410
        MOVI             R11, 7   # 0x1414
        BRA_PRED         0, L1554   # 0x1418
        MOVI             R11, 1   # 0x141c
        LD_LOCAL         R3, 28   # 0x1420
        C_ADDI           R3, 1   # 0x1424
        ST_LOCAL         R3, 28   # 0x1426
        BRA              L1554   # 0x142a
L142e:  C_CHWIDTH        R3, 1   # 0x142e
        ADDI             R3, R3, -58   # 0x1430
        AND              R3, R3, R14, R3   # 0x1434
        C_CHWIDTH        R3, 0   # 0x1438
        MOVI             R8, 245   # 0x143a
        SETP_LT_U_NP     P0, R3, R8, R3   # 0x143e
        MOVI             R11, 4   # 0x1442
        BRA_PRED         0, L154e   # 0x1446
        MOVI             R11, 2   # 0x144a
        SETP_EQ_NPI      P0, R3, R5, 43   # 0x144e
        BRA_PRED         0, L154e   # 0x1452
        SETP_EQ_NPI      P0, R3, R5, 45   # 0x1456
        BRA_PRED         0, L154e   # 0x145a
        SETP_NE_NPI      P0, R3, R5, 46   # 0x145e
        BRA_PRED         0, L1540   # 0x1462
        MOVI             R11, 5   # 0x1466
        C_BRA            L154e   # 0x146a
L146c:  SETP_NE_NPI      P0, R5, R5, 46   # 0x146c
        BRA_PRED         0, L14c8   # 0x1470
        MOVI             R11, 5   # 0x1474
        C_BRA            L14ec   # 0x1478
L147a:  C_CHWIDTH        R5, 1   # 0x147a
        ADDI             R5, R3, -58   # 0x147c
        C_CHWIDTH        R3, 1   # 0x1480
        AND              R3, R5, R14, R5   # 0x1482
        CHWIDTH_MULTI    40, 0   # 0x1486
        MOVI             R5, 246   # 0x148a
        SETP_LT_U_NP     P0, R3, R3, R5   # 0x148e
        MOVI             R11, 7   # 0x1492
        MOVI             R3, 1   # 0x1496
        MOV_P            R11, 0, R3, R3, R3   # 0x149a
        C_ADDI           R9, 1   # 0x149e
        C_BRA            L1554   # 0x14a0
L14a2:  C_CHWIDTH        R3, 1   # 0x14a2
        ADDI             R3, R3, -58   # 0x14a4
        AND              R3, R3, R14, R3   # 0x14a8
        C_CHWIDTH        R3, 0   # 0x14ac
        MOVI             R8, 246   # 0x14ae
        SETP_LT_U_NP     P0, R3, R3, R8   # 0x14b2
        BRA_PRED         4, L1520   # 0x14b6
        SETP_EQ_NPI      P0, R3, R5, 46   # 0x14ba
        MOVI             R11, 1   # 0x14be
        MOV_P            R11, 0, R10, R10, R10   # 0x14c2
        C_BRA            L1524   # 0x14c6
L14c8:  C_CHWIDTH        R5, 1   # 0x14c8
        ADDI             R5, R3, -58   # 0x14ca
        C_CHWIDTH        R3, 1   # 0x14ce
        AND              R3, R5, R14, R5   # 0x14d0
        CHWIDTH_MULTI    40, 0   # 0x14d4
        MOVI             R5, 245   # 0x14d8
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x14dc
        MOVI             R11, 4   # 0x14e0
        BRA_PRED         0, L1554   # 0x14e4
        MOVI             R11, 1   # 0x14e8
L14ec:  LD_LOCAL         R3, 20   # 0x14ec
        C_ADDI           R3, 1   # 0x14f0
        ST_LOCAL         R3, 20   # 0x14f2
        C_BRA            L1554   # 0x14f6
L14f8:  C_CHWIDTH        R5, 1   # 0x14f8
        ADDI             R5, R3, -58   # 0x14fa
        C_CHWIDTH        R3, 1   # 0x14fe
        AND              R3, R5, R14, R5   # 0x1500
        CHWIDTH_MULTI    40, 0   # 0x1504
        MOVI             R5, 245   # 0x1508
        SETP_LT_U_NP     P0, R3, R5, R3   # 0x150c
        MOVI             R11, 5   # 0x1510
        BRA_PRED         0, L1554   # 0x1514
        MOVI             R11, 1   # 0x1518
        C_ADDI           R7, 1   # 0x151c
        C_BRA            L1554   # 0x151e
L1520:  MOVI             R11, 4   # 0x1520
L1524:  LD_LOCAL         R3, 12   # 0x1524
        C_ADDI           R3, 1   # 0x1528
        ST_LOCAL         R3, 12   # 0x152a
        C_BRA            L1554   # 0x152e
L1530:  MOVI             R11, 1   # 0x1530
L1534:  LD_LOCAL         R3, 16   # 0x1534
        C_ADDI           R3, 1   # 0x1538
        ST_LOCAL         R3, 16   # 0x153a
        C_BRA            L1554   # 0x153e
L1540:  MOVI             R11, 1   # 0x1540
        LD_LOCAL         R3, 28   # 0x1544
        C_ADDI           R3, 1   # 0x1548
        ST_LOCAL         R3, 28   # 0x154a
L154e:  C_ADDI           R4, 1   # 0x154e
        ST_LOCAL         R4, 24   # 0x1550
L1554:  SZ_GLOBAL_LD_U8  R3, R2, R12, 0, 1   # 0x1554
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x1558
        BRA_PRED         0, L1362   # 0x155c
        SETP_EQ_NPI      P0, R5, R11, 1   # 0x1560
        BRA_PRED         4, L134c   # 0x1564
        BRA              L1362   # 0x1568
L156c:  C_MOV            R12, R7   # 0x156c
        LD_LOCAL         R4, 40   # 0x156e
        LD_LOCAL         R5, 56   # 0x1572
L1576:  C_CHWIDTH        R5, 1   # 0x1576
        LD_LOCAL         R1, 36   # 0x1578
        SETP_EQ_NPI      P0, R0, R1, 0   # 0x157c
        SHLI             R7, R2, 16   # 0x1580
        CVT_SEXT         R14, R5, R5, R5   # 0x1584
        C_CHWIDTH        R5, 0   # 0x1588
        ADD              R0, R13, R1, R13   # 0x158a
        SHRI             R5, R2, 16   # 0x158e
        BRA_PRED         0, L161a   # 0x1592
        C_MOV            R6, R4   # 0x1596
        ADD              R3, R13, R7, R13   # 0x1598
        ADD              R1, R14, R7, R14   # 0x159c
        C_ADD            R3, R14   # 0x15a0
        C_NOT            R3, R3   # 0x15a2
        C_MOV            R8, R13   # 0x15a4
L15a6:  SZ_GLOBAL_LD_U8  R4, R2, R8, 0, 0   # 0x15a6
        SETP_EQ_NPI      P0, R10, R4, 44   # 0x15aa
        BRA_PRED         0, L15be   # 0x15ae
        C_CHWIDTH        R4, 1   # 0x15b2
        XOR              R4, R4, R6, R4   # 0x15b4
        C_CHWIDTH        R4, 0   # 0x15b8
        SZ_GLOBAL_ST_8   R4, R2, R8, 0, 0   # 0x15ba
L15be:  ADD              R4, R14, R8, R14   # 0x15be
        OR               R10, R7, R4, R7   # 0x15c2
        C_AND            R10, R3   # 0x15c6
        AND              R11, R7, R4, R7   # 0x15c8
        OR               R10, R11, R10, R11   # 0x15cc
        ADD              R8, R1, R8, R1   # 0x15d0
        ADD              R11, R7, R0, R7   # 0x15d4
        SETP_LT_U_NP     P0, R8, R8, R11   # 0x15d8
        OR               R8, R7, R0, R7   # 0x15dc
        C_ANDN           R8, R11   # 0x15e0
        AND              R11, R7, R0, R7   # 0x15e2
        OR               R8, R11, R8, R11   # 0x15e6
        SHRI             R8, R8, 31   # 0x15ea
        SHRI             R10, R10, 31   # 0x15ee
        SETP_EQ_NP       P1, R11, R10, R8   # 0x15f2
        ADD              R8, R5, R8, R5   # 0x15f6
        ADD              R10, R5, R10, R5   # 0x15fa
        SETP_LT_U_NP     P2, R8, R10, R8   # 0x15fe
        C_SUB            R3, R14   # 0x1602
        C_MOV            R8, R4   # 0x1604
        BRA_PRED         2, L15a6   # 0x1606
        PAND             P0, 1, 0   # 0x160a
        C_MOV            R8, R4   # 0x160c
        BRA_PRED         0, L15a6   # 0x160e
        C_CHWIDTH        R6, 1   # 0x1612
        SZ_GLOBAL_LD_U8  R6, R2, R13, 0, 0   # 0x1614
        C_CHWIDTH        R6, 0   # 0x1618
L161a:  SETP_EQ_NPI      P0, R1, R6, 0   # 0x161a
        BRA_PRED         0, L1880   # 0x161e
        ST_LOCAL         R12, 32   # 0x1622
        MOVI             R11, 0   # 0x1626
        MOVI             R1, 255   # 0x162a
        C_MOV            R4, R1   # 0x162e
        MOVI             R10, 3   # 0x1630
        MOVI             R3, 223   # 0x1634
        ST_LOCAL         R3, 40   # 0x1638
        C_MOV            R3, R13   # 0x163c
        C_BRA            L1644   # 0x163e
L1640:  C_MOV            R6, R3   # 0x1640
        C_MOV            R3, R12   # 0x1642
L1644:  C_CHWIDTH        R8, 1   # 0x1644
        AND              R8, R6, R4, R6   # 0x1646
        C_CHWIDTH        R8, 0   # 0x164a
        SETP_NE_NPI      P0, R12, R8, 44   # 0x164c
        ADDI             R12, R3, 1   # 0x1650
        BRA_PRED         0, L1674   # 0x1654
L1658:  LD_GLOBAL_IDX    R1, R15, R11, 1, -36   # 0x1658
        C_ADDI           R1, 1   # 0x165c
        ST_GLOBAL_IDX    R1, R15, R11, 1, -36   # 0x165e
        SZ_GLOBAL_LD_U8  R3, R2, R12, 0, 0   # 0x1662
        SETP_EQ_NPI      P0, R1, R3, 0   # 0x1666
        BRA_PRED         0, L187c   # 0x166a
        MOVI             R11, 0   # 0x166e
        C_BRA            L1640   # 0x1672
L1674:  SETP_LT_NP       P0, R1, R10, R11   # 0x1674
        BRA_PRED         4, L16b4   # 0x1678
        MOVI             R1, 5   # 0x167c
        SETP_LT_NP       P0, R1, R1, R11   # 0x1680
        BRA_PRED         0, L16e4   # 0x1684
        SETP_EQ_NPI      P0, R1, R11, 4   # 0x1688
        BRA_PRED         0, L1768   # 0x168c
        SETP_EQ_NPI      P0, R1, R11, 5   # 0x1690
        BRA_PRED         4, L1864   # 0x1694
        LD_LOCAL         R1, 40   # 0x1698
        C_CHWIDTH        R1, 1   # 0x169c
        AND              R1, R6, R1, R6   # 0x169e
        C_CHWIDTH        R1, 0   # 0x16a2
        SETP_NE_NPI      P0, R1, R1, 69   # 0x16a4
        BRA_PRED         0, L17fc   # 0x16a8
        MOVI             R11, 3   # 0x16ac
        BRA              L1820   # 0x16b0
L16b4:  SETP_EQ_NPI      P0, R1, R11, 0   # 0x16b4
        BRA_PRED         0, L1726   # 0x16b8
        SETP_EQ_NPI      P0, R1, R11, 2   # 0x16bc
        BRA_PRED         0, L179e   # 0x16c0
        SETP_EQ_NPI      P0, R1, R11, 3   # 0x16c4
        BRA_PRED         4, L1864   # 0x16c8
        SETP_EQ_NPI      P0, R1, R8, 45   # 0x16cc
        BRA_PRED         0, L16dc   # 0x16d0
        SETP_NE_NPI      P0, R1, R8, 43   # 0x16d4
        BRA_PRED         0, L183c   # 0x16d8
L16dc:  MOVI             R11, 6   # 0x16dc
        BRA              L1840   # 0x16e0
L16e4:  SETP_EQ_NPI      P0, R1, R11, 6   # 0x16e4
        BRA_PRED         0, L1776   # 0x16e8
        SETP_EQ_NPI      P0, R1, R11, 7   # 0x16ec
        BRA_PRED         4, L1864   # 0x16f0
        CHWIDTH_MULTI    66, 1   # 0x16f4
        ADDI             R6, R6, -58   # 0x16f8
        AND              R1, R6, R4, R6   # 0x16fc
        CHWIDTH_MULTI    66, 0   # 0x1700
        MOVI             R6, 245   # 0x1704
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x1708
        MOVI             R11, 7   # 0x170c
        BRA_PRED         0, L1864   # 0x1710
        MOVI             R11, 1   # 0x1714
        LD_LOCAL         R1, 28   # 0x1718
        C_ADDI           R1, 1   # 0x171c
        ST_LOCAL         R1, 28   # 0x171e
        BRA              L1864   # 0x1722
L1726:  CHWIDTH_MULTI    66, 1   # 0x1726
        ADDI             R6, R6, -58   # 0x172a
        AND              R1, R6, R4, R6   # 0x172e
        CHWIDTH_MULTI    66, 0   # 0x1732
        MOVI             R6, 245   # 0x1736
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x173a
        MOVI             R11, 4   # 0x173e
        BRA_PRED         0, L185a   # 0x1742
        MOVI             R11, 2   # 0x1746
        SETP_EQ_NPI      P0, R1, R8, 43   # 0x174a
        BRA_PRED         0, L185a   # 0x174e
        SETP_EQ_NPI      P0, R1, R8, 45   # 0x1752
        BRA_PRED         0, L185a   # 0x1756
        SETP_NE_NPI      P0, R1, R8, 46   # 0x175a
        BRA_PRED         0, L184c   # 0x175e
        MOVI             R11, 5   # 0x1762
        C_BRA            L185a   # 0x1766
L1768:  SETP_NE_NPI      P0, R1, R8, 46   # 0x1768
        BRA_PRED         0, L17cc   # 0x176c
        MOVI             R11, 5   # 0x1770
        C_BRA            L17f0   # 0x1774
L1776:  CHWIDTH_MULTI    66, 1   # 0x1776
        ADDI             R6, R6, -58   # 0x177a
        AND              R1, R6, R4, R6   # 0x177e
        CHWIDTH_MULTI    66, 0   # 0x1782
        MOVI             R6, 246   # 0x1786
        SETP_LT_U_NP     P0, R1, R1, R6   # 0x178a
        MOVI             R11, 7   # 0x178e
        MOVI             R1, 1   # 0x1792
        MOV_P            R11, 0, R1, R1, R1   # 0x1796
        C_ADDI           R9, 1   # 0x179a
        C_BRA            L1864   # 0x179c
L179e:  CHWIDTH_MULTI    66, 1   # 0x179e
        ADDI             R6, R6, -58   # 0x17a2
        AND              R1, R6, R4, R6   # 0x17a6
        CHWIDTH_MULTI    66, 0   # 0x17aa
        MOVI             R6, 246   # 0x17ae
        SETP_LT_U_NP     P0, R1, R1, R6   # 0x17b2
        BRA_PRED         4, L182c   # 0x17b6
        SETP_EQ_NPI      P0, R1, R8, 46   # 0x17ba
        MOVI             R11, 1   # 0x17be
        MOVI             R1, 5   # 0x17c2
        MOV_P            R11, 0, R1, R1, R1   # 0x17c6
        C_BRA            L1830   # 0x17ca
L17cc:  CHWIDTH_MULTI    66, 1   # 0x17cc
        ADDI             R6, R6, -58   # 0x17d0
        AND              R1, R6, R4, R6   # 0x17d4
        CHWIDTH_MULTI    66, 0   # 0x17d8
        MOVI             R6, 245   # 0x17dc
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x17e0
        MOVI             R11, 4   # 0x17e4
        BRA_PRED         0, L1864   # 0x17e8
        MOVI             R11, 1   # 0x17ec
L17f0:  LD_LOCAL         R1, 20   # 0x17f0
        C_ADDI           R1, 1   # 0x17f4
        ST_LOCAL         R1, 20   # 0x17f6
        C_BRA            L1864   # 0x17fa
L17fc:  CHWIDTH_MULTI    66, 1   # 0x17fc
        ADDI             R6, R6, -58   # 0x1800
        AND              R1, R6, R4, R6   # 0x1804
        CHWIDTH_MULTI    66, 0   # 0x1808
        MOVI             R6, 245   # 0x180c
        SETP_LT_U_NP     P0, R1, R6, R1   # 0x1810
        MOVI             R11, 5   # 0x1814
        BRA_PRED         0, L1864   # 0x1818
        MOVI             R11, 1   # 0x181c
L1820:  LD_LOCAL         R1, 32   # 0x1820
        C_ADDI           R1, 1   # 0x1824
        ST_LOCAL         R1, 32   # 0x1826
        C_BRA            L1864   # 0x182a
L182c:  MOVI             R11, 4   # 0x182c
L1830:  LD_LOCAL         R1, 12   # 0x1830
        C_ADDI           R1, 1   # 0x1834
        ST_LOCAL         R1, 12   # 0x1836
        C_BRA            L1864   # 0x183a
L183c:  MOVI             R11, 1   # 0x183c
L1840:  LD_LOCAL         R1, 16   # 0x1840
        C_ADDI           R1, 1   # 0x1844
        ST_LOCAL         R1, 16   # 0x1846
        C_BRA            L1864   # 0x184a
L184c:  MOVI             R11, 1   # 0x184c
        LD_LOCAL         R1, 28   # 0x1850
        C_ADDI           R1, 1   # 0x1854
        ST_LOCAL         R1, 28   # 0x1856
L185a:  LD_LOCAL         R1, 24   # 0x185a
        C_ADDI           R1, 1   # 0x185e
        ST_LOCAL         R1, 24   # 0x1860
L1864:  SZ_GLOBAL_LD_U8  R3, R2, R3, 0, 1   # 0x1864
        SETP_EQ_NPI      P0, R1, R3, 0   # 0x1868
        BRA_PRED         0, L1658   # 0x186c
        SETP_EQ_NPI      P0, R1, R11, 1   # 0x1870
        BRA_PRED         4, L1640   # 0x1874
        BRA              L1658   # 0x1878
L187c:  LD_LOCAL         R12, 32   # 0x187c
L1880:  LD_LOCAL         R1, 36   # 0x1880
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x1884
        BRA_PRED         0, L190a   # 0x1888
        LD_LOCAL         R1, 52   # 0x188c
        C_MOV            R6, R1   # 0x1890
        ADD              R3, R13, R7, R13   # 0x1892
        ADD              R1, R14, R7, R14   # 0x1896
        C_ADD            R3, R14   # 0x189a
        C_NOT            R3, R3   # 0x189c
L189e:  SZ_GLOBAL_LD_U8  R4, R2, R13, 0, 0   # 0x189e
        SETP_EQ_NPI      P0, R8, R4, 44   # 0x18a2
        BRA_PRED         0, L18b6   # 0x18a6
        C_CHWIDTH        R4, 1   # 0x18aa
        XOR              R4, R4, R6, R4   # 0x18ac
        C_CHWIDTH        R4, 0   # 0x18b0
        SZ_GLOBAL_ST_8   R4, R2, R13, 0, 0   # 0x18b2
L18b6:  ADD              R4, R14, R13, R14   # 0x18b6
        OR               R8, R7, R4, R7   # 0x18ba
        C_AND            R8, R3   # 0x18be
        AND              R10, R7, R4, R7   # 0x18c0
        OR               R8, R10, R8, R10   # 0x18c4
        ADD              R10, R1, R13, R1   # 0x18c8
        ADD              R11, R7, R0, R7   # 0x18cc
        SETP_LT_U_NP     P0, R10, R10, R11   # 0x18d0
        OR               R10, R7, R0, R7   # 0x18d4
        C_ANDN           R10, R11   # 0x18d8
        AND              R11, R7, R0, R7   # 0x18da
        OR               R10, R11, R10, R11   # 0x18de
        SHRI             R10, R10, 31   # 0x18e2
        SHRI             R8, R8, 31   # 0x18e6
        SETP_EQ_NP       P1, R11, R8, R10   # 0x18ea
        ADD              R10, R5, R10, R5   # 0x18ee
        ADD              R8, R5, R8, R5   # 0x18f2
        SETP_LT_U_NP     P2, R8, R8, R10   # 0x18f6
        C_SUB            R3, R14   # 0x18fa
        C_MOV            R13, R4   # 0x18fc
        BRA_PRED         2, L189e   # 0x18fe
        PAND             P0, 1, 0   # 0x1902
        C_MOV            R13, R4   # 0x1904
        BRA_PRED         0, L189e   # 0x1906
L190a:  LD_GLOBAL        R1, R15, -36   # 0x190a
        LD_LOCAL         R2, 48   # 0x190e
        CALL             R14, 129642   # 0x1912
        MOVI             R15, 2   # 0x1916
        LD_GLOBAL        R15, R15, 24   # 0x191a
        SRD              R3, 2   # 0x191e
        C_ADD            R15, R3   # 0x1920
        C_MOV            R2, R1   # 0x1922
        LD_LOCAL         R1, 24   # 0x1924
        CALL             R14, 129631   # 0x1928
        MOVI             R15, 2   # 0x192c
        LD_GLOBAL        R15, R15, 24   # 0x1930
        SRD              R3, 2   # 0x1934
        C_ADD            R15, R3   # 0x1936
        C_MOV            R2, R1   # 0x1938
        LD_GLOBAL        R1, R15, -32   # 0x193a
        CALL             R14, 129620   # 0x193e
        MOVI             R15, 2   # 0x1942
        LD_GLOBAL        R15, R15, 24   # 0x1946
        SRD              R3, 2   # 0x194a
        C_ADD            R15, R3   # 0x194c
        C_MOV            R2, R1   # 0x194e
        LD_LOCAL         R1, 28   # 0x1950
        CALL             R14, 129609   # 0x1954
        MOVI             R15, 2   # 0x1958
        LD_GLOBAL        R15, R15, 24   # 0x195c
        SRD              R3, 2   # 0x1960
        C_ADD            R15, R3   # 0x1962
        C_MOV            R2, R1   # 0x1964
        LD_GLOBAL        R1, R15, -28   # 0x1966
        CALL             R14, 129598   # 0x196a
        MOVI             R15, 2   # 0x196e
        LD_GLOBAL        R15, R15, 24   # 0x1972
        SRD              R3, 2   # 0x1976
        C_ADD            R15, R3   # 0x1978
        C_MOV            R2, R1   # 0x197a
        LD_LOCAL         R1, 12   # 0x197c
        CALL             R14, 129587   # 0x1980
        MOVI             R15, 2   # 0x1984
        LD_GLOBAL        R15, R15, 24   # 0x1988
        SRD              R3, 2   # 0x198c
        C_ADD            R15, R3   # 0x198e
        C_MOV            R2, R1   # 0x1990
        LD_GLOBAL        R1, R15, -24   # 0x1992
        CALL             R14, 129576   # 0x1996
        MOVI             R15, 2   # 0x199a
        LD_GLOBAL        R15, R15, 24   # 0x199e
        SRD              R3, 2   # 0x19a2
        C_ADD            R15, R3   # 0x19a4
        C_MOV            R2, R1   # 0x19a6
        LD_LOCAL         R1, 16   # 0x19a8
        CALL             R14, 129565   # 0x19ac
        MOVI             R15, 2   # 0x19b0
        LD_GLOBAL        R15, R15, 24   # 0x19b4
        SRD              R3, 2   # 0x19b8
        C_ADD            R15, R3   # 0x19ba
        C_MOV            R2, R1   # 0x19bc
        LD_GLOBAL        R1, R15, -20   # 0x19be
        CALL             R14, 129554   # 0x19c2
        MOVI             R15, 2   # 0x19c6
        LD_GLOBAL        R15, R15, 24   # 0x19ca
        SRD              R3, 2   # 0x19ce
        C_ADD            R15, R3   # 0x19d0
        C_MOV            R2, R1   # 0x19d2
        LD_LOCAL         R1, 20   # 0x19d4
        CALL             R14, 129543   # 0x19d8
        MOVI             R15, 2   # 0x19dc
        LD_GLOBAL        R15, R15, 24   # 0x19e0
        SRD              R3, 2   # 0x19e4
        C_ADD            R15, R3   # 0x19e6
        C_MOV            R2, R1   # 0x19e8
        LD_GLOBAL        R1, R15, -16   # 0x19ea
        CALL             R14, 129532   # 0x19ee
        MOVI             R15, 2   # 0x19f2
        LD_GLOBAL        R15, R15, 24   # 0x19f6
        SRD              R3, 2   # 0x19fa
        C_ADD            R15, R3   # 0x19fc
        C_MOV            R2, R1   # 0x19fe
        C_MOV            R1, R12   # 0x1a00
        CALL             R14, 129522   # 0x1a02
        MOVI             R15, 2   # 0x1a06
        LD_GLOBAL        R15, R15, 24   # 0x1a0a
        SRD              R3, 2   # 0x1a0e
        C_ADD            R15, R3   # 0x1a10
        C_MOV            R2, R1   # 0x1a12
        LD_GLOBAL        R1, R15, -12   # 0x1a14
        CALL             R14, 129511   # 0x1a18
        MOVI             R15, 2   # 0x1a1c
        LD_GLOBAL        R15, R15, 24   # 0x1a20
        SRD              R3, 2   # 0x1a24
        C_ADD            R15, R3   # 0x1a26
        C_MOV            R2, R1   # 0x1a28
        C_MOV            R1, R9   # 0x1a2a
        CALL             R14, 129501   # 0x1a2c
        MOVI             R15, 2   # 0x1a30
        LD_GLOBAL        R15, R15, 24   # 0x1a34
        SRD              R3, 2   # 0x1a38
        C_ADD            R15, R3   # 0x1a3a
        C_MOV            R2, R1   # 0x1a3c
        LD_GLOBAL        R1, R15, -8   # 0x1a3e
        CALL             R14, 129490   # 0x1a42
        MOVI             R15, 2   # 0x1a46
        LD_GLOBAL        R15, R15, 24   # 0x1a4a
        SRD              R3, 2   # 0x1a4e
        C_ADD            R15, R3   # 0x1a50
        C_MOV            R2, R1   # 0x1a52
        MOVI             R1, 0   # 0x1a54
        CALL             R14, 129479   # 0x1a58
        MOVI             R15, 2   # 0x1a5c
        LD_GLOBAL        R15, R15, 24   # 0x1a60
        SRD              R3, 2   # 0x1a64
        C_ADD            R15, R3   # 0x1a66
        LD_LOCAL         R14, 44   # 0x1a68
        LD_LOCAL         R13, 80   # 0x1a6c
        LD_LOCAL         R12, 76   # 0x1a70
        LD_LOCAL         R11, 72   # 0x1a74
        LD_LOCAL         R10, 68   # 0x1a78
        LD_LOCAL         R9, 64   # 0x1a7c
        LD_LOCAL         R8, 60   # 0x1a80
        C_RET            224   # 0x1a84
        CHWIDTH_MULTI    7, 1   # 0x1a86
        XOR              R0, R2, R1, R2   # 0x1a8a
        CHWIDTH_MULTI    7, 0   # 0x1a8e
        C_ANDI           R0, 1   # 0x1a92
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1a94
        MOVI             R0, 40961   # 0x1a98
        C_MOV            R7, R0   # 0x1a9c
        SHRI             R0, R2, 1   # 0x1a9e
        C_CHWIDTH        R2, 1   # 0x1aa2
        XOR              R2, R0, R7, R0   # 0x1aa4
        C_CHWIDTH        R2, 0   # 0x1aa8
        MOV_P            R0, 0, R2, R2, R2   # 0x1aaa
        C_CHWIDTH        R0, 1   # 0x1aae
        SHRI             R2, R1, 1   # 0x1ab0
        C_CHWIDTH        R2, 1   # 0x1ab4
        XOR              R2, R2, R0, R2   # 0x1ab6
        CHWIDTH_MULTI    5, 0   # 0x1aba
        C_ANDI           R2, 1   # 0x1abe
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1ac0
        C_CHWIDTH        R2, 1   # 0x1ac4
        SHRI             R0, R0, 1   # 0x1ac6
        XOR              R2, R0, R7, R0   # 0x1aca
        C_CHWIDTH        R2, 0   # 0x1ace
        MOV_P            R0, 0, R2, R2, R2   # 0x1ad0
        C_CHWIDTH        R0, 1   # 0x1ad4
        SHRI             R2, R1, 2   # 0x1ad6
        C_CHWIDTH        R2, 1   # 0x1ada
        XOR              R2, R2, R0, R2   # 0x1adc
        CHWIDTH_MULTI    5, 0   # 0x1ae0
        C_ANDI           R2, 1   # 0x1ae4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1ae6
        C_CHWIDTH        R2, 1   # 0x1aea
        SHRI             R0, R0, 1   # 0x1aec
        XOR              R2, R0, R7, R0   # 0x1af0
        C_CHWIDTH        R2, 0   # 0x1af4
        MOV_P            R0, 0, R2, R2, R2   # 0x1af6
        C_CHWIDTH        R0, 1   # 0x1afa
        SHRI             R2, R1, 3   # 0x1afc
        C_CHWIDTH        R2, 1   # 0x1b00
        XOR              R2, R2, R0, R2   # 0x1b02
        CHWIDTH_MULTI    5, 0   # 0x1b06
        C_ANDI           R2, 1   # 0x1b0a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b0c
        C_CHWIDTH        R2, 1   # 0x1b10
        SHRI             R0, R0, 1   # 0x1b12
        XOR              R2, R0, R7, R0   # 0x1b16
        C_CHWIDTH        R2, 0   # 0x1b1a
        MOV_P            R0, 0, R2, R2, R2   # 0x1b1c
        C_CHWIDTH        R0, 1   # 0x1b20
        SHRI             R2, R1, 4   # 0x1b22
        C_CHWIDTH        R2, 1   # 0x1b26
        XOR              R2, R2, R0, R2   # 0x1b28
        CHWIDTH_MULTI    5, 0   # 0x1b2c
        C_ANDI           R2, 1   # 0x1b30
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b32
        C_CHWIDTH        R2, 1   # 0x1b36
        SHRI             R0, R0, 1   # 0x1b38
        XOR              R2, R0, R7, R0   # 0x1b3c
        C_CHWIDTH        R2, 0   # 0x1b40
        MOV_P            R0, 0, R2, R2, R2   # 0x1b42
        C_CHWIDTH        R0, 1   # 0x1b46
        SHRI             R2, R1, 5   # 0x1b48
        C_CHWIDTH        R2, 1   # 0x1b4c
        XOR              R2, R2, R0, R2   # 0x1b4e
        CHWIDTH_MULTI    5, 0   # 0x1b52
        C_ANDI           R2, 1   # 0x1b56
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b58
        C_CHWIDTH        R2, 1   # 0x1b5c
        SHRI             R0, R0, 1   # 0x1b5e
        XOR              R2, R0, R7, R0   # 0x1b62
        C_CHWIDTH        R2, 0   # 0x1b66
        MOV_P            R0, 0, R2, R2, R2   # 0x1b68
        C_CHWIDTH        R0, 1   # 0x1b6c
        SHRI             R2, R1, 6   # 0x1b6e
        C_CHWIDTH        R2, 1   # 0x1b72
        XOR              R2, R2, R0, R2   # 0x1b74
        CHWIDTH_MULTI    5, 0   # 0x1b78
        C_ANDI           R2, 1   # 0x1b7c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b7e
        C_CHWIDTH        R2, 1   # 0x1b82
        SHRI             R0, R0, 1   # 0x1b84
        XOR              R2, R0, R7, R0   # 0x1b88
        C_CHWIDTH        R2, 0   # 0x1b8c
        MOV_P            R0, 0, R2, R2, R2   # 0x1b8e
        MOVI             R2, 128   # 0x1b92
        C_CHWIDTH        R2, 1   # 0x1b96
        AND              R2, R1, R2, R1   # 0x1b98
        C_CHWIDTH        R2, 0   # 0x1b9c
        SHRI             R2, R2, 7   # 0x1b9e
        ANDI             R3, R0, 1   # 0x1ba2
        C_CHWIDTH        R0, 1   # 0x1ba6
        C_CHWIDTH        R0, 0   # 0x1ba8
        SETP_EQ_NP       P0, R2, R2, R3   # 0x1baa
        C_CHWIDTH        R2, 1   # 0x1bae
        SHRI             R0, R0, 1   # 0x1bb0
        XOR              R2, R0, R7, R0   # 0x1bb4
        C_CHWIDTH        R2, 0   # 0x1bb8
        MOV_P            R2, 0, R0, R0, R0   # 0x1bba
        C_CHWIDTH        R2, 1   # 0x1bbe
        SHRI             R0, R1, 8   # 0x1bc0
        C_CHWIDTH        R0, 1   # 0x1bc4
        XOR              R0, R2, R0, R2   # 0x1bc6
        CHWIDTH_MULTI    5, 0   # 0x1bca
        C_ANDI           R0, 1   # 0x1bce
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1bd0
        SHRI             R0, R2, 1   # 0x1bd4
        C_CHWIDTH        R2, 1   # 0x1bd8
        XOR              R2, R0, R7, R0   # 0x1bda
        C_CHWIDTH        R2, 0   # 0x1bde
        MOV_P            R0, 0, R2, R2, R2   # 0x1be0
        C_CHWIDTH        R0, 1   # 0x1be4
        SHRI             R2, R1, 9   # 0x1be6
        C_CHWIDTH        R2, 1   # 0x1bea
        XOR              R2, R2, R0, R2   # 0x1bec
        CHWIDTH_MULTI    5, 0   # 0x1bf0
        C_ANDI           R2, 1   # 0x1bf4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bf6
        C_CHWIDTH        R2, 1   # 0x1bfa
        SHRI             R0, R0, 1   # 0x1bfc
        XOR              R2, R0, R7, R0   # 0x1c00
        C_CHWIDTH        R2, 0   # 0x1c04
        MOV_P            R0, 0, R2, R2, R2   # 0x1c06
        C_CHWIDTH        R0, 1   # 0x1c0a
        SHRI             R2, R1, 10   # 0x1c0c
        C_CHWIDTH        R2, 1   # 0x1c10
        XOR              R2, R2, R0, R2   # 0x1c12
        CHWIDTH_MULTI    5, 0   # 0x1c16
        C_ANDI           R2, 1   # 0x1c1a
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c1c
        C_CHWIDTH        R2, 1   # 0x1c20
        SHRI             R0, R0, 1   # 0x1c22
        XOR              R2, R0, R7, R0   # 0x1c26
        C_CHWIDTH        R2, 0   # 0x1c2a
        MOV_P            R0, 0, R2, R2, R2   # 0x1c2c
        C_CHWIDTH        R0, 1   # 0x1c30
        SHRI             R2, R1, 11   # 0x1c32
        C_CHWIDTH        R2, 1   # 0x1c36
        XOR              R2, R2, R0, R2   # 0x1c38
        CHWIDTH_MULTI    5, 0   # 0x1c3c
        C_ANDI           R2, 1   # 0x1c40
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c42
        C_CHWIDTH        R2, 1   # 0x1c46
        SHRI             R0, R0, 1   # 0x1c48
        XOR              R2, R0, R7, R0   # 0x1c4c
        C_CHWIDTH        R2, 0   # 0x1c50
        MOV_P            R0, 0, R2, R2, R2   # 0x1c52
        C_CHWIDTH        R0, 1   # 0x1c56
        SHRI             R2, R1, 12   # 0x1c58
        C_CHWIDTH        R2, 1   # 0x1c5c
        XOR              R2, R2, R0, R2   # 0x1c5e
        CHWIDTH_MULTI    5, 0   # 0x1c62
        C_ANDI           R2, 1   # 0x1c66
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c68
        C_CHWIDTH        R2, 1   # 0x1c6c
        SHRI             R0, R0, 1   # 0x1c6e
        XOR              R2, R0, R7, R0   # 0x1c72
        C_CHWIDTH        R2, 0   # 0x1c76
        MOV_P            R0, 0, R2, R2, R2   # 0x1c78
        C_CHWIDTH        R0, 1   # 0x1c7c
        SHRI             R2, R1, 13   # 0x1c7e
        C_CHWIDTH        R2, 1   # 0x1c82
        XOR              R2, R2, R0, R2   # 0x1c84
        CHWIDTH_MULTI    5, 0   # 0x1c88
        C_ANDI           R2, 1   # 0x1c8c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c8e
        C_CHWIDTH        R2, 1   # 0x1c92
        SHRI             R0, R0, 1   # 0x1c94
        XOR              R2, R0, R7, R0   # 0x1c98
        C_CHWIDTH        R2, 0   # 0x1c9c
        MOV_P            R0, 0, R2, R2, R2   # 0x1c9e
        C_CHWIDTH        R0, 1   # 0x1ca2
        SHRI             R2, R1, 14   # 0x1ca4
        C_CHWIDTH        R2, 1   # 0x1ca8
        XOR              R2, R2, R0, R2   # 0x1caa
        CHWIDTH_MULTI    5, 0   # 0x1cae
        C_ANDI           R2, 1   # 0x1cb2
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1cb4
        C_CHWIDTH        R2, 1   # 0x1cb8
        SHRI             R0, R0, 1   # 0x1cba
        XOR              R2, R0, R7, R0   # 0x1cbe
        C_CHWIDTH        R2, 0   # 0x1cc2
        MOV_P            R0, 0, R2, R2, R2   # 0x1cc4
        SHRI             R1, R1, 15   # 0x1cc8
        ANDI             R2, R0, 1   # 0x1ccc
        C_CHWIDTH        R0, 1   # 0x1cd0
        C_CHWIDTH        R0, 0   # 0x1cd2
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1cd4
        C_CHWIDTH        R1, 1   # 0x1cd8
        SHRI             R0, R0, 1   # 0x1cda
        XOR              R1, R0, R7, R0   # 0x1cde
        C_CHWIDTH        R1, 0   # 0x1ce2
        MOV_P            R1, 0, R0, R0, R0   # 0x1ce4
        MOVI             R0, 65535   # 0x1ce8
        C_AND            R1, R0   # 0x1cec
        C_RET            224   # 0x1cee
        ST_LOCAL         R8, 72   # 0x1cf0
        ST_LOCAL         R9, 76   # 0x1cf4
        ST_LOCAL         R10, 80   # 0x1cf8
        ST_LOCAL         R11, 84   # 0x1cfc
        ST_LOCAL         R12, 88   # 0x1d00
        ST_LOCAL         R13, 92   # 0x1d04
        C_MOV            R15, R14   # 0x1d08
        C_MOV            R8, R4   # 0x1d0a
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x1d0c
        SHLI             R9, R0, 16   # 0x1d10
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x1d14
        ST_LOCAL         R0, 48   # 0x1d18
        SHRI             R0, R0, 16   # 0x1d1c
        ST_LOCAL         R0, 68   # 0x1d20
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x1d24
        SHLI             R0, R0, 16   # 0x1d28
        LD_GLOBAL_IDX    R14, R1, R2, 0, 8   # 0x1d2c
        SHRI             R5, R14, 16   # 0x1d30
        C_OR             R0, R5   # 0x1d34
        LD_GLOBAL_IDX    R5, R1, R2, 0, 28   # 0x1d36
        SHLI             R5, R5, 16   # 0x1d3a
        LD_GLOBAL_IDX    R6, R1, R2, 0, 24   # 0x1d3e
        SHRI             R7, R6, 16   # 0x1d42
        OR               R4, R5, R7, R5   # 0x1d46
        ST_LOCAL         R4, 20   # 0x1d4a
        MOVI             R4, 65535   # 0x1d4e
        AND              R7, R14, R4, R14   # 0x1d52
        C_CHWIDTH        R14, 1   # 0x1d56
        AND              R4, R6, R4, R6   # 0x1d58
        ST_LOCAL         R4, 16   # 0x1d5c
        LD_GLOBAL_IDX    R5, R1, R2, 0, 0   # 0x1d60
        MOVI             R2, 0   # 0x1d64
        MOVI             R1, 61440   # 0x1d68
        C_MOV            R11, R3   # 0x1d6c
        OR               R14, R11, R1, R11   # 0x1d6e
        SETP_EQ_NPI      P0, R1, R5, 0   # 0x1d72
        ANDI             R12, R5, -2   # 0x1d76
        ANDI             R1, R5, 1   # 0x1d7a
        ST_LOCAL         R1, 32   # 0x1d7e
        ADDI             R1, R5, -1   # 0x1d82
        ST_LOCAL         R1, 28   # 0x1d86
        CVT_SEXT         R6, R14, R14, R14   # 0x1d8a
        ANDI             R10, R5, -4   # 0x1d8e
        ST_LOCAL         R5, 12   # 0x1d92
        ST_LOCAL         R10, 40   # 0x1d96
        ST_LOCAL         R15, 52   # 0x1d9a
        ST_LOCAL         R11, 56   # 0x1d9e
        ST_LOCAL         R8, 60   # 0x1da2
        ST_LOCAL         R6, 24   # 0x1da6
        ST_LOCAL         R9, 44   # 0x1daa
        BRA_PRED         0, L207e   # 0x1dae
        ANDI             R1, R5, 3   # 0x1db2
        MOVI             R6, 0   # 0x1db6
        C_BRA            L1dce   # 0x1dba
L1dbc:  C_CHWIDTH        R14, 0   # 0x1dbc
        LD_LOCAL         R3, 12   # 0x1dbe
        C_ADD            R2, R3   # 0x1dc2
        C_ADDI           R6, 1   # 0x1dc4
        SETP_NE_NP       P0, R3, R6, R3   # 0x1dc6
        BRA_PRED         4, L1e66   # 0x1dca
L1dce:  CHWIDTH_MULTI    24576, 1   # 0x1dce
        MOVI             R3, 0   # 0x1dd2
        LD_LOCAL         R5, 28   # 0x1dd6
        SETP_LT_U_NPI    P0, R5, R5, 3   # 0x1dda
        BRA_PRED         0, L1e34   # 0x1dde
L1de2:  ADD              R5, R2, R3, R2   # 0x1de2
        C_SHLI           R5, 1   # 0x1de6
        ADD              R5, R7, R5, R7   # 0x1de8
        SZ_GLOBAL_LD_U16 R14, R0, R5, 0, 0   # 0x1dec
        ADD              R14, R14, R11, R14   # 0x1df0
        SZ_GLOBAL_ST_16  R14, R0, R5, 0, 0   # 0x1df4
        C_CHWIDTH        R14, 0   # 0x1df8
        ADDI             R14, R5, 2   # 0x1dfa
        SZ_GLOBAL_LD_U16 R13, R0, R14, 0, 0   # 0x1dfe
        ADD              R13, R13, R11, R13   # 0x1e02
        SZ_GLOBAL_ST_16  R13, R0, R14, 0, 0   # 0x1e06
        ADDI             R14, R5, 4   # 0x1e0a
        SZ_GLOBAL_LD_U16 R13, R0, R14, 0, 0   # 0x1e0e
        ADD              R13, R13, R11, R13   # 0x1e12
        SZ_GLOBAL_ST_16  R13, R0, R14, 0, 0   # 0x1e16
        C_CHWIDTH        R14, 1   # 0x1e1a
        C_ADDI           R5, 6   # 0x1e1c
        SZ_GLOBAL_LD_U16 R14, R0, R5, 0, 0   # 0x1e1e
        ADD              R14, R14, R11, R14   # 0x1e22
        SZ_GLOBAL_ST_16  R14, R0, R5, 0, 0   # 0x1e26
        C_ADDI           R3, 4   # 0x1e2a
        SETP_NE_NP       P0, R5, R10, R3   # 0x1e2c
        BRA_PRED         0, L1de2   # 0x1e30
L1e34:  SETP_EQ_NPI      P0, R5, R1, 0   # 0x1e34
        BRA_PRED         0, L1dbc   # 0x1e38
        C_CHWIDTH        R14, 0   # 0x1e3c
        C_ADD            R3, R2   # 0x1e3e
        C_MOV            R5, R1   # 0x1e40
L1e42:  C_MOV            R14, R3   # 0x1e42
        C_SHLI           R14, 1   # 0x1e44
        ADD              R14, R7, R14, R7   # 0x1e46
        SZ_GLOBAL_LD_U16 R13, R0, R14, 0, 0   # 0x1e4a
        ADD              R13, R13, R11, R13   # 0x1e4e
        SZ_GLOBAL_ST_16  R13, R0, R14, 0, 0   # 0x1e52
        C_ADDI           R3, 1   # 0x1e56
        ADDI             R5, R5, -1   # 0x1e58
        SETP_NE_NPI      P0, R14, R5, 0   # 0x1e5c
        BRA_PRED         0, L1e42   # 0x1e60
        C_BRA            L1dbc   # 0x1e64
L1e66:  C_CHWIDTH        R11, 1   # 0x1e66
        MOVI             R2, 0   # 0x1e68
        CVT_SEXT         R6, R11, R11, R11   # 0x1e6c
        C_CHWIDTH        R11, 0   # 0x1e70
        MOVI             R14, 0   # 0x1e72
        LD_LOCAL         R11, 20   # 0x1e76
        LD_LOCAL         R15, 16   # 0x1e7a
        C_BRA            L1e90   # 0x1e7e
L1e80:  LD_LOCAL         R3, 12   # 0x1e80
        C_ADD            R2, R3   # 0x1e84
        C_ADDI           R14, 1   # 0x1e86
        SETP_NE_NP       P0, R3, R14, R3   # 0x1e88
        BRA_PRED         4, L1f52   # 0x1e8c
L1e90:  LD_LOCAL         R3, 28   # 0x1e90
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1e94
        MOVI             R5, 0   # 0x1e98
        BRA_PRED         0, L1f1a   # 0x1e9c
L1ea0:  ADD              R3, R2, R5, R2   # 0x1ea0
        C_MOV            R8, R3   # 0x1ea4
        C_SHLI           R8, 2   # 0x1ea6
        ADD              R8, R15, R8, R15   # 0x1ea8
        C_MOV            R9, R3   # 0x1eac
        C_SHLI           R9, 1   # 0x1eae
        ADD              R9, R7, R9, R7   # 0x1eb0
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1eb4
        C_MUL_LO         R9, R6   # 0x1eb8
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1eba
        ADDI             R8, R3, 1   # 0x1ebe
        C_MOV            R9, R8   # 0x1ec2
        C_SHLI           R9, 2   # 0x1ec4
        ADD              R9, R15, R9, R15   # 0x1ec6
        C_SHLI           R8, 1   # 0x1eca
        ADD              R8, R7, R8, R7   # 0x1ecc
        SZ_GLOBAL_LD_S16 R8, R0, R8, 0, 0   # 0x1ed0
        C_MUL_LO         R8, R6   # 0x1ed4
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1ed6
        ADDI             R8, R3, 2   # 0x1eda
        C_MOV            R9, R8   # 0x1ede
        C_SHLI           R9, 2   # 0x1ee0
        ADD              R9, R15, R9, R15   # 0x1ee2
        C_SHLI           R8, 1   # 0x1ee6
        ADD              R8, R7, R8, R7   # 0x1ee8
        SZ_GLOBAL_LD_S16 R8, R0, R8, 0, 0   # 0x1eec
        C_MUL_LO         R8, R6   # 0x1ef0
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1ef2
        C_ADDI           R3, 3   # 0x1ef6
        C_MOV            R8, R3   # 0x1ef8
        C_SHLI           R8, 2   # 0x1efa
        ADD              R8, R15, R8, R15   # 0x1efc
        C_SHLI           R3, 1   # 0x1f00
        ADD              R3, R7, R3, R7   # 0x1f02
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x1f06
        C_MUL_LO         R3, R6   # 0x1f0a
        ST_GLOBAL_IDX    R3, R11, R8, 0, 0   # 0x1f0c
        C_ADDI           R5, 4   # 0x1f10
        SETP_NE_NP       P0, R3, R10, R5   # 0x1f12
        BRA_PRED         0, L1ea0   # 0x1f16
L1f1a:  SETP_EQ_NPI      P0, R3, R1, 0   # 0x1f1a
        BRA_PRED         0, L1e80   # 0x1f1e
        ADD              R3, R5, R2, R5   # 0x1f22
        C_MOV            R5, R1   # 0x1f26
L1f28:  C_MOV            R8, R3   # 0x1f28
        C_SHLI           R8, 2   # 0x1f2a
        ADD              R8, R15, R8, R15   # 0x1f2c
        C_MOV            R9, R3   # 0x1f30
        C_SHLI           R9, 1   # 0x1f32
        ADD              R9, R7, R9, R7   # 0x1f34
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1f38
        C_MUL_LO         R9, R6   # 0x1f3c
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1f3e
        C_ADDI           R3, 1   # 0x1f42
        ADDI             R5, R5, -1   # 0x1f44
        SETP_NE_NPI      P0, R8, R5, 0   # 0x1f48
        BRA_PRED         0, L1f28   # 0x1f4c
        C_BRA            L1e80   # 0x1f50
L1f52:  C_CHWIDTH        R13, 0   # 0x1f52
        MOVI             R1, 0   # 0x1f54
        C_MOV            R15, R1   # 0x1f58
        MOVI             R5, 0   # 0x1f5a
        MOVI             R13, 0   # 0x1f5e
        MOVI             R1, 0   # 0x1f62
        MOVI             R8, 0   # 0x1f66
        C_BRA            L1f80   # 0x1f6a
L1f6c:  LD_LOCAL         R3, 12   # 0x1f6c
        C_ADD            R5, R3   # 0x1f70
        C_ADDI           R13, 1   # 0x1f72
        SETP_NE_NP       P0, R3, R13, R3   # 0x1f74
        LD_LOCAL         R10, 40   # 0x1f78
        BRA_PRED         4, L2084   # 0x1f7c
L1f80:  ST_LOCAL         R13, 36   # 0x1f80
        LD_LOCAL         R3, 28   # 0x1f84
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1f88
        BRA_PRED         0, L2016   # 0x1f8c
        MOVI             R9, 0   # 0x1f90
        LD_LOCAL         R2, 16   # 0x1f94
        LD_LOCAL         R2, 24   # 0x1f98
L1f9c:  C_CHWIDTH        R15, 0   # 0x1f9c
        ADD              R3, R5, R9, R5   # 0x1f9e
        C_SHLI           R3, 2   # 0x1fa2
        LD_LOCAL         R6, 16   # 0x1fa4
        C_ADD            R3, R6   # 0x1fa8
        C_MOV            R14, R5   # 0x1faa
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x1fac
        SETP_LT_NP       P0, R1, R1, R5   # 0x1fb0
        C_MOV            R10, R15   # 0x1fb4
        MOVI             R15, 0   # 0x1fb6
        ADDI_P           R15, 0, R15, 1   # 0x1fba
        ADD              R8, R5, R8, R5   # 0x1fbe
        SETP_LT_NP       P0, R1, R2, R8   # 0x1fc2
        MOVI             R6, 10   # 0x1fc6
        MOV_P            R15, 0, R6, R6, R6   # 0x1fca
        MOVI             R13, 0   # 0x1fce
        MOV_P            R8, 0, R13, R13, R13   # 0x1fd2
        ADDI             R1, R3, 4   # 0x1fd6
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x1fda
        SETP_LT_NP       P0, R3, R5, R1   # 0x1fde
        MOVI             R3, 0   # 0x1fe2
        ADDI_P           R3, 0, R3, 1   # 0x1fe6
        ADD              R8, R1, R8, R1   # 0x1fea
        SETP_LT_NP       P0, R5, R2, R8   # 0x1fee
        C_CHWIDTH        R5, 1   # 0x1ff2
        MOV_P            R3, 0, R6, R6, R6   # 0x1ff4
        MOV_P            R8, 0, R13, R13, R13   # 0x1ff8
        ADD              R5, R15, R10, R15   # 0x1ffc
        C_CHWIDTH        R15, 1   # 0x2000
        ADD              R15, R3, R5, R3   # 0x2002
        C_CHWIDTH        R5, 0   # 0x2006
        C_MOV            R5, R14   # 0x2008
        C_ADDI           R9, 2   # 0x200a
        SETP_NE_NP       P0, R3, R12, R9   # 0x200c
        BRA_PRED         0, L1f9c   # 0x2010
        C_BRA            L201e   # 0x2014
L2016:  MOVI             R9, 0   # 0x2016
        LD_LOCAL         R2, 24   # 0x201a
L201e:  LD_LOCAL         R3, 32   # 0x201e
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2022
        C_MOV            R6, R2   # 0x2026
        MOVI             R2, 0   # 0x2028
        MOVI             R14, 10   # 0x202c
        LD_LOCAL         R13, 36   # 0x2030
        BRA_PRED         0, L1f6c   # 0x2034
        C_CHWIDTH        R15, 1   # 0x2038
        LD_LOCAL         R3, 12   # 0x203a
        MUL_LO           R3, R13, R3, R3   # 0x203e
        ADD              R3, R9, R3, R9   # 0x2042
        C_SHLI           R3, 2   # 0x2046
        C_MOV            R9, R5   # 0x2048
        LD_LOCAL         R5, 16   # 0x204a
        ADD              R3, R5, R3, R5   # 0x204e
        C_MOV            R5, R9   # 0x2052
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x2054
        SETP_LT_NP       P0, R1, R1, R3   # 0x2058
        ADD              R8, R3, R8, R3   # 0x205c
        SETP_LT_NP       P1, R1, R6, R8   # 0x2060
        MOV_P            R8, 1, R2, R2, R2   # 0x2064
        MOVI             R1, 0   # 0x2068
        ADDI_P           R1, 0, R1, 1   # 0x206c
        MOV_P            R1, 1, R14, R14, R14   # 0x2070
        ADD              R15, R1, R15, R1   # 0x2074
        C_MOV            R1, R3   # 0x2078
        BRA              L1f6c   # 0x207a
L207e:  C_MOV            R15, R2   # 0x207e
        LD_LOCAL         R11, 20   # 0x2080
L2084:  C_CHWIDTH        R15, 0   # 0x2084
        LD_LOCAL         R1, 44   # 0x2086
        LD_LOCAL         R2, 68   # 0x208a
        OR               R8, R1, R2, R1   # 0x208e
        LD_LOCAL         R1, 48   # 0x2092
        MOVI             R2, 65535   # 0x2096
        AND              R9, R1, R2, R1   # 0x209a
        MOVI             R1, 0   # 0x209e
        LD_LOCAL         R2, 12   # 0x20a2
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x20a6
        ST_LOCAL         R15, 64   # 0x20aa
        BRA_PRED         0, L228c   # 0x20ae
        MOVI             R2, 0   # 0x20b2
        C_BRA            L20d8   # 0x20b6
L20b8:  C_MOV            R3, R2   # 0x20b8
        C_SHLI           R3, 2   # 0x20ba
        LD_LOCAL         R6, 16   # 0x20bc
        ADD              R3, R6, R3, R6   # 0x20c0
        ST_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x20c4
        LD_LOCAL         R3, 12   # 0x20c8
        C_ADD            R1, R3   # 0x20cc
        C_ADDI           R2, 1   # 0x20ce
        SETP_NE_NP       P0, R3, R2, R3   # 0x20d0
        BRA_PRED         4, L215a   # 0x20d4
L20d8:  LD_LOCAL         R3, 28   # 0x20d8
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x20dc
        BRA_PRED         0, L2120   # 0x20e0
        C_CHWIDTH        R14, 0   # 0x20e4
        MOVI             R3, 0   # 0x20e6
        MOVI             R5, 0   # 0x20ea
L20ee:  ADD              R6, R1, R3, R1   # 0x20ee
        C_SHLI           R6, 1   # 0x20f2
        C_ADD            R6, R7   # 0x20f4
        C_MOV            R14, R3   # 0x20f6
        C_SHLI           R14, 1   # 0x20f8
        C_ADD            R14, R9   # 0x20fa
        SZ_GLOBAL_LD_S16 R15, R8, R14, 0, 0   # 0x20fc
        SZ_GLOBAL_LD_S16 R13, R0, R6, 0, 0   # 0x2100
        MAD_ACC          R5, R15, R13   # 0x2104
        C_ADDI           R14, 2   # 0x2106
        SZ_GLOBAL_LD_S16 R14, R8, R14, 0, 0   # 0x2108
        C_ADDI           R6, 2   # 0x210c
        SZ_GLOBAL_LD_S16 R6, R0, R6, 0, 0   # 0x210e
        MAD_ACC          R5, R14, R6   # 0x2112
        C_ADDI           R3, 2   # 0x2114
        SETP_NE_NP       P0, R6, R12, R3   # 0x2116
        BRA_PRED         0, L20ee   # 0x211a
        C_BRA            L2128   # 0x211e
L2120:  MOVI             R3, 0   # 0x2120
        MOVI             R5, 0   # 0x2124
L2128:  C_CHWIDTH        R14, 0   # 0x2128
        LD_LOCAL         R6, 32   # 0x212a
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x212e
        BRA_PRED         0, L20b8   # 0x2132
        LD_LOCAL         R4, 12   # 0x2136
        MUL_LO           R6, R2, R4, R4   # 0x213a
        C_MOV            R14, R3   # 0x213e
        C_SHLI           R14, 1   # 0x2140
        ADD              R14, R9, R14, R9   # 0x2142
        SZ_GLOBAL_LD_S16 R14, R8, R14, 0, 0   # 0x2146
        C_ADD            R3, R6   # 0x214a
        C_SHLI           R3, 1   # 0x214c
        ADD              R3, R7, R3, R7   # 0x214e
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x2152
        MAD_ACC          R5, R14, R3   # 0x2156
        C_BRA            L20b8   # 0x2158
L215a:  MOVI             R1, 0   # 0x215a
        C_MOV            R5, R1   # 0x215e
        MOVI             R3, 0   # 0x2160
        ST_LOCAL         R1, 44   # 0x2164
        MOVI             R13, 0   # 0x2168
        C_BRA            L218a   # 0x216c
L216e:  LD_LOCAL         R2, 12   # 0x216e
        LD_LOCAL         R3, 36   # 0x2172
        C_ADD            R3, R2   # 0x2176
        LD_LOCAL         R6, 44   # 0x2178
        C_ADDI           R6, 1   # 0x217c
        ST_LOCAL         R6, 44   # 0x217e
        SETP_NE_NP       P0, R2, R6, R2   # 0x2182
        BRA_PRED         4, L228e   # 0x2186
L218a:  ST_LOCAL         R3, 36   # 0x218a
        LD_LOCAL         R2, 28   # 0x218e
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x2192
        BRA_PRED         0, L2224   # 0x2196
        MOVI             R6, 0   # 0x219a
        LD_LOCAL         R2, 16   # 0x219e
        LD_LOCAL         R2, 24   # 0x21a2
        LD_LOCAL         R2, 36   # 0x21a6
L21aa:  C_CHWIDTH        R5, 0   # 0x21aa
        LD_LOCAL         R2, 36   # 0x21ac
        ADD              R3, R2, R6, R2   # 0x21b0
        C_SHLI           R3, 2   # 0x21b4
        LD_LOCAL         R2, 16   # 0x21b6
        C_ADD            R3, R2   # 0x21ba
        C_MOV            R15, R5   # 0x21bc
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x21be
        SETP_LT_NP       P0, R1, R1, R5   # 0x21c2
        MOVI             R2, 0   # 0x21c6
        ADDI_P           R2, 0, R2, 1   # 0x21ca
        ADD              R13, R5, R13, R5   # 0x21ce
        LD_LOCAL         R4, 24   # 0x21d2
        SETP_LT_NP       P0, R1, R4, R13   # 0x21d6
        MOVI             R14, 10   # 0x21da
        MOV_P            R2, 0, R14, R14, R14   # 0x21de
        MOVI             R10, 0   # 0x21e2
        MOV_P            R13, 0, R10, R10, R10   # 0x21e6
        ADDI             R1, R3, 4   # 0x21ea
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x21ee
        SETP_LT_NP       P0, R3, R5, R1   # 0x21f2
        MOVI             R3, 0   # 0x21f6
        ADDI_P           R3, 0, R3, 1   # 0x21fa
        ADD              R13, R1, R13, R1   # 0x21fe
        SETP_LT_NP       P0, R5, R4, R13   # 0x2202
        C_CHWIDTH        R5, 1   # 0x2206
        MOV_P            R3, 0, R14, R14, R14   # 0x2208
        MOV_P            R13, 0, R10, R10, R10   # 0x220c
        ADD              R5, R2, R15, R2   # 0x2210
        ADD              R5, R3, R5, R3   # 0x2214
        C_ADDI           R6, 2   # 0x2218
        SETP_NE_NP       P0, R2, R12, R6   # 0x221a
        BRA_PRED         0, L21aa   # 0x221e
        C_BRA            L222c   # 0x2222
L2224:  MOVI             R6, 0   # 0x2224
        LD_LOCAL         R2, 24   # 0x2228
L222c:  LD_LOCAL         R2, 32   # 0x222c
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x2230
        LD_LOCAL         R14, 24   # 0x2234
        LD_LOCAL         R10, 40   # 0x2238
        MOVI             R15, 0   # 0x223c
        BRA_PRED         0, L216e   # 0x2240
        C_CHWIDTH        R5, 1   # 0x2244
        LD_LOCAL         R2, 44   # 0x2246
        LD_LOCAL         R3, 12   # 0x224a
        C_MUL_LO         R2, R3   # 0x224e
        ADD              R2, R6, R2, R6   # 0x2250
        C_SHLI           R2, 2   # 0x2254
        LD_LOCAL         R3, 16   # 0x2256
        ADD              R2, R3, R2, R3   # 0x225a
        LD_GLOBAL_IDX    R2, R11, R2, 0, 0   # 0x225e
        SETP_LT_NP       P0, R1, R1, R2   # 0x2262
        ADD              R13, R2, R13, R2   # 0x2266
        SETP_LT_NP       P1, R1, R14, R13   # 0x226a
        MOV_P            R13, 1, R15, R15, R15   # 0x226e
        MOVI             R1, 0   # 0x2272
        ADDI_P           R1, 0, R1, 1   # 0x2276
        MOVI             R3, 10   # 0x227a
        MOV_P            R1, 1, R3, R3, R3   # 0x227e
        ADD              R5, R1, R5, R1   # 0x2282
        C_MOV            R1, R2   # 0x2286
        BRA              L216e   # 0x2288
L228c:  C_MOV            R5, R1   # 0x228c
L228e:  C_CHWIDTH        R5, 0   # 0x228e
        ST_LOCAL         R5, 68   # 0x2290
        MOVI             R1, 0   # 0x2294
        LD_LOCAL         R3, 12   # 0x2298
        SETP_EQ_NPI      P0, R2, R3, 0   # 0x229c
        C_MOV            R2, R3   # 0x22a0
        C_SHLI           R2, 1   # 0x22a2
        BRA_PRED         0, L24da   # 0x22a4
        C_CHWIDTH        R14, 0   # 0x22a8
        MOVI             R5, 0   # 0x22aa
        LD_LOCAL         R10, 12   # 0x22ae
        C_BRA            L22c4   # 0x22b2
L22b4:  C_ADD            R1, R10   # 0x22b4
        LD_LOCAL         R5, 36   # 0x22b6
        C_ADDI           R5, 1   # 0x22ba
        SETP_NE_NP       P0, R3, R5, R10   # 0x22bc
        BRA_PRED         4, L237c   # 0x22c0
L22c4:  ST_LOCAL         R5, 36   # 0x22c4
        MUL_LO           R14, R5, R10, R10   # 0x22c8
        MOVI             R11, 0   # 0x22cc
        C_BRA            L22f2   # 0x22d0
L22d2:  ADD              R3, R11, R14, R11   # 0x22d2
        C_SHLI           R3, 2   # 0x22d6
        LD_LOCAL         R6, 16   # 0x22d8
        ADD              R3, R6, R3, R6   # 0x22dc
        LD_LOCAL         R6, 20   # 0x22e0
        ST_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x22e4
        C_ADDI           R11, 1   # 0x22e8
        SETP_NE_NP       P0, R3, R11, R10   # 0x22ea
        BRA_PRED         4, L22b4   # 0x22ee
L22f2:  LD_LOCAL         R3, 28   # 0x22f2
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x22f6
        MOVI             R13, 0   # 0x22fa
        MOVI             R5, 0   # 0x22fe
        BRA_PRED         0, L2350   # 0x2302
        C_MOV            R15, R11   # 0x2306
        MOVI             R5, 0   # 0x2308
L230c:  ADD              R6, R1, R13, R1   # 0x230c
        C_SHLI           R6, 1   # 0x2310
        C_ADD            R6, R7   # 0x2312
        C_MOV            R3, R15   # 0x2314
        C_SHLI           R3, 1   # 0x2316
        ADD              R3, R9, R3, R9   # 0x2318
        SZ_GLOBAL_LD_S16 R3, R8, R3, 0, 0   # 0x231c
        SZ_GLOBAL_LD_S16 R10, R0, R6, 0, 0   # 0x2320
        MADLO            R3, R3, R10, R5   # 0x2324
        LD_LOCAL         R10, 12   # 0x2328
        ADD              R5, R10, R15, R10   # 0x232c
        C_SHLI           R5, 1   # 0x2330
        ADD              R5, R9, R5, R9   # 0x2332
        SZ_GLOBAL_LD_S16 R5, R8, R5, 0, 0   # 0x2336
        C_ADDI           R6, 2   # 0x233a
        SZ_GLOBAL_LD_S16 R6, R0, R6, 0, 0   # 0x233c
        MADLO            R5, R5, R6, R3   # 0x2340
        C_ADD            R15, R2   # 0x2344
        C_ADDI           R13, 2   # 0x2346
        SETP_NE_NP       P0, R3, R12, R13   # 0x2348
        BRA_PRED         0, L230c   # 0x234c
L2350:  LD_LOCAL         R3, 32   # 0x2350
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2354
        BRA_PRED         0, L22d2   # 0x2358
        MADLO            R3, R13, R10, R11   # 0x235c
        C_SHLI           R3, 1   # 0x2360
        ADD              R3, R9, R3, R9   # 0x2362
        SZ_GLOBAL_LD_S16 R3, R8, R3, 0, 0   # 0x2366
        ADD              R6, R13, R14, R13   # 0x236a
        C_SHLI           R6, 1   # 0x236e
        ADD              R6, R7, R6, R7   # 0x2370
        SZ_GLOBAL_LD_S16 R6, R0, R6, 0, 0   # 0x2374
        MAD_ACC          R5, R3, R6   # 0x2378
        C_BRA            L22d2   # 0x237a
L237c:  MOVI             R1, 0   # 0x237c
        ST_LOCAL         R1, 44   # 0x2380
        MOVI             R6, 0   # 0x2384
        MOVI             R11, 0   # 0x2388
        MOVI             R1, 0   # 0x238c
        MOVI             R14, 0   # 0x2390
        LD_LOCAL         R5, 20   # 0x2394
        C_BRA            L23b2   # 0x2398
L239a:  LD_LOCAL         R6, 36   # 0x239a
        C_ADD            R6, R5   # 0x239e
        C_ADDI           R11, 1   # 0x23a0
        SETP_NE_NP       P0, R3, R11, R5   # 0x23a2
        LD_LOCAL         R10, 40   # 0x23a6
        LD_LOCAL         R5, 20   # 0x23aa
        BRA_PRED         4, L24de   # 0x23ae
L23b2:  ST_LOCAL         R11, 48   # 0x23b2
        ST_LOCAL         R6, 36   # 0x23b6
        LD_LOCAL         R3, 28   # 0x23ba
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x23be
        BRA_PRED         0, L245a   # 0x23c2
        MOVI             R13, 0   # 0x23c6
        LD_LOCAL         R3, 16   # 0x23ca
        LD_LOCAL         R3, 24   # 0x23ce
        LD_LOCAL         R15, 44   # 0x23d2
        C_CHWIDTH        R15, 1   # 0x23d6
        LD_LOCAL         R3, 36   # 0x23d8
L23dc:  C_CHWIDTH        R5, 0   # 0x23dc
        LD_LOCAL         R3, 36   # 0x23de
        C_ADD            R3, R13   # 0x23e2
        C_SHLI           R3, 2   # 0x23e4
        LD_LOCAL         R5, 16   # 0x23e6
        C_ADD            R3, R5   # 0x23ea
        LD_LOCAL         R4, 20   # 0x23ec
        LD_GLOBAL_IDX    R5, R4, R3, 0, 0   # 0x23f0
        SETP_LT_NP       P0, R1, R1, R5   # 0x23f4
        MOVI             R10, 0   # 0x23f8
        ADDI_P           R10, 0, R10, 1   # 0x23fc
        ADD              R14, R5, R14, R5   # 0x2400
        LD_LOCAL         R11, 24   # 0x2404
        SETP_LT_NP       P0, R1, R11, R14   # 0x2408
        MOVI             R1, 10   # 0x240c
        MOV_P            R10, 0, R1, R1, R1   # 0x2410
        MOVI             R6, 0   # 0x2414
        MOV_P            R14, 0, R6, R6, R6   # 0x2418
        ADDI             R1, R3, 4   # 0x241c
        LD_GLOBAL_IDX    R1, R4, R1, 0, 0   # 0x2420
        SETP_LT_NP       P0, R3, R5, R1   # 0x2424
        MOVI             R3, 0   # 0x2428
        ADDI_P           R3, 0, R3, 1   # 0x242c
        ADD              R14, R1, R14, R1   # 0x2430
        SETP_LT_NP       P0, R5, R11, R14   # 0x2434
        C_CHWIDTH        R5, 1   # 0x2438
        MOVI             R4, 10   # 0x243a
        MOV_P            R3, 0, R4, R4, R4   # 0x243e
        MOV_P            R14, 0, R6, R6, R6   # 0x2442
        ADD              R5, R10, R15, R10   # 0x2446
        ADD              R15, R3, R5, R3   # 0x244a
        C_ADDI           R13, 2   # 0x244e
        SETP_NE_NP       P0, R3, R12, R13   # 0x2450
        BRA_PRED         0, L23dc   # 0x2454
        C_BRA            L2462   # 0x2458
L245a:  MOVI             R13, 0   # 0x245a
        LD_LOCAL         R15, 44   # 0x245e
L2462:  CHWIDTH_MULTI    32800, 0   # 0x2462
        LD_LOCAL         R3, 20   # 0x2466
        ST_LOCAL         R15, 44   # 0x246a
        LD_LOCAL         R3, 32   # 0x246e
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2472
        LD_LOCAL         R5, 12   # 0x2476
        MOVI             R6, 0   # 0x247a
        MOVI             R15, 10   # 0x247e
        LD_LOCAL         R11, 48   # 0x2482
        BRA_PRED         0, L239a   # 0x2486
        MUL_LO           R3, R11, R5, R5   # 0x248a
        ADD              R3, R13, R3, R13   # 0x248e
        C_SHLI           R3, 2   # 0x2492
        LD_LOCAL         R10, 16   # 0x2494
        ADD              R3, R10, R3, R10   # 0x2498
        LD_LOCAL         R10, 20   # 0x249c
        LD_GLOBAL_IDX    R3, R10, R3, 0, 0   # 0x24a0
        SETP_LT_NP       P0, R1, R1, R3   # 0x24a4
        ADD              R14, R3, R14, R3   # 0x24a8
        LD_LOCAL         R1, 24   # 0x24ac
        SETP_LT_NP       P1, R1, R1, R14   # 0x24b0
        MOV_P            R14, 1, R6, R6, R6   # 0x24b4
        MOVI             R1, 0   # 0x24b8
        ADDI_P           R1, 0, R1, 1   # 0x24bc
        MOV_P            R1, 1, R15, R15, R15   # 0x24c0
        LD_LOCAL         R6, 44   # 0x24c4
        C_CHWIDTH        R6, 1   # 0x24c8
        ADD              R6, R1, R6, R1   # 0x24ca
        C_CHWIDTH        R6, 0   # 0x24ce
        ST_LOCAL         R6, 44   # 0x24d0
        C_MOV            R1, R3   # 0x24d4
        BRA              L239a   # 0x24d6
L24da:  ST_LOCAL         R1, 44   # 0x24da
L24de:  MOVI             R6, 0   # 0x24de
        LD_LOCAL         R1, 12   # 0x24e2
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x24e6
        BRA_PRED         0, L2714   # 0x24ea
        MOVI             R3, 0   # 0x24ee
        LD_LOCAL         R10, 12   # 0x24f2
        C_BRA            L2508   # 0x24f6
L24f8:  C_ADD            R6, R10   # 0x24f8
        LD_LOCAL         R3, 48   # 0x24fa
        C_ADDI           R3, 1   # 0x24fe
        SETP_NE_NP       P0, R1, R3, R10   # 0x2500
        BRA_PRED         4, L25f2   # 0x2504
L2508:  ST_LOCAL         R3, 48   # 0x2508
        MUL_LO           R1, R3, R10, R10   # 0x250c
        ST_LOCAL         R1, 36   # 0x2510
        MOVI             R3, 0   # 0x2514
        C_BRA            L253e   # 0x2518
L251a:  LD_LOCAL         R1, 36   # 0x251a
        ADD              R5, R3, R1, R3   # 0x251e
        C_SHLI           R5, 2   # 0x2522
        LD_LOCAL         R1, 16   # 0x2524
        ADD              R5, R1, R5, R1   # 0x2528
        LD_LOCAL         R11, 20   # 0x252c
        ST_GLOBAL_IDX    R14, R11, R5, 0, 0   # 0x2530
        C_ADDI           R3, 1   # 0x2534
        SETP_NE_NP       P0, R5, R3, R10   # 0x2536
        BRA_PRED         4, L24f8   # 0x253a
L253e:  C_CHWIDTH        R14, 0   # 0x253e
        LD_LOCAL         R5, 28   # 0x2540
        SETP_EQ_NPI      P0, R5, R5, 0   # 0x2544
        MOVI             R5, 0   # 0x2548
        MOVI             R14, 0   # 0x254c
        C_MOV            R1, R10   # 0x2550
        BRA_PRED         0, L25b2   # 0x2552
        C_MOV            R13, R3   # 0x2556
L2558:  ADD              R10, R6, R5, R6   # 0x2558
        C_SHLI           R10, 1   # 0x255c
        C_ADD            R10, R7   # 0x255e
        C_MOV            R11, R13   # 0x2560
        C_SHLI           R11, 1   # 0x2562
        ADD              R11, R9, R11, R9   # 0x2564
        SZ_GLOBAL_LD_U16 R11, R8, R11, 0, 0   # 0x2568
        SZ_GLOBAL_LD_U16 R15, R0, R10, 0, 0   # 0x256c
        MUL_LO           R15, R11, R15, R15   # 0x2570
        C_MOV            R11, R15   # 0x2574
        C_SHRI           R11, 5   # 0x2576
        ANDI             R11, R11, 127   # 0x2578
        C_SHRI           R15, 2   # 0x257c
        C_ANDI           R15, 15   # 0x257e
        MAD_ACC          R14, R15, R11   # 0x2580
        ADD              R15, R1, R13, R1   # 0x2582
        C_SHLI           R15, 1   # 0x2586
        ADD              R15, R9, R15, R9   # 0x2588
        SZ_GLOBAL_LD_U16 R15, R8, R15, 0, 0   # 0x258c
        C_ADDI           R10, 2   # 0x2590
        SZ_GLOBAL_LD_U16 R10, R0, R10, 0, 0   # 0x2592
        C_MUL_LO         R15, R10   # 0x2596
        C_MOV            R10, R15   # 0x2598
        C_SHRI           R10, 5   # 0x259a
        ANDI             R10, R10, 127   # 0x259c
        C_SHRI           R15, 2   # 0x25a0
        C_ANDI           R15, 15   # 0x25a2
        MAD_ACC          R14, R15, R10   # 0x25a4
        C_ADD            R13, R2   # 0x25a6
        C_ADDI           R5, 2   # 0x25a8
        SETP_NE_NP       P0, R15, R12, R5   # 0x25aa
        BRA_PRED         0, L2558   # 0x25ae
L25b2:  LD_LOCAL         R15, 32   # 0x25b2
        SETP_EQ_NPI      P0, R15, R15, 0   # 0x25b6
        C_MOV            R10, R1   # 0x25ba
        BRA_PRED         0, L251a   # 0x25bc
        MADLO            R15, R5, R10, R3   # 0x25c0
        C_SHLI           R15, 1   # 0x25c4
        ADD              R15, R9, R15, R9   # 0x25c6
        SZ_GLOBAL_LD_U16 R15, R8, R15, 0, 0   # 0x25ca
        LD_LOCAL         R1, 36   # 0x25ce
        C_ADD            R5, R1   # 0x25d2
        C_SHLI           R5, 1   # 0x25d4
        ADD              R5, R7, R5, R7   # 0x25d6
        SZ_GLOBAL_LD_U16 R5, R0, R5, 0, 0   # 0x25da
        MUL_LO           R5, R15, R5, R5   # 0x25de
        C_MOV            R15, R5   # 0x25e2
        C_SHRI           R15, 5   # 0x25e4
        ANDI             R15, R15, 127   # 0x25e6
        C_SHRI           R5, 2   # 0x25ea
        C_ANDI           R5, 15   # 0x25ec
        MAD_ACC          R14, R5, R15   # 0x25ee
        C_BRA            L251a   # 0x25f0
L25f2:  MOVI             R1, 0   # 0x25f2
        C_MOV            R8, R1   # 0x25f6
        MOVI             R5, 0   # 0x25f8
        ST_LOCAL         R1, 36   # 0x25fc
        MOVI             R13, 0   # 0x2600
        LD_LOCAL         R10, 24   # 0x2604
        C_BRA            L2622   # 0x2608
L260a:  C_ADD            R5, R15   # 0x260a
        LD_LOCAL         R2, 36   # 0x260c
        C_ADDI           R2, 1   # 0x2610
        ST_LOCAL         R2, 36   # 0x2612
        SETP_NE_NP       P0, R3, R2, R15   # 0x2616
        LD_LOCAL         R9, 40   # 0x261a
        BRA_PRED         4, L2718   # 0x261e
L2622:  LD_LOCAL         R3, 28   # 0x2622
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2626
        BRA_PRED         0, L26b2   # 0x262a
        MOVI             R9, 0   # 0x262e
        LD_LOCAL         R2, 16   # 0x2632
L2636:  C_CHWIDTH        R8, 1   # 0x2636
        ADD              R3, R5, R9, R5   # 0x2638
        C_SHLI           R3, 2   # 0x263c
        LD_LOCAL         R2, 16   # 0x263e
        C_ADD            R3, R2   # 0x2642
        C_MOV            R14, R5   # 0x2644
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x2646
        SETP_LT_NP       P0, R15, R13, R5   # 0x264a
        MOVI             R15, 0   # 0x264e
        ADDI_P           R15, 0, R15, 1   # 0x2652
        ADD              R1, R5, R1, R5   # 0x2656
        LD_LOCAL         R10, 24   # 0x265a
        SETP_LT_NP       P0, R10, R10, R1   # 0x265e
        LD_LOCAL         R10, 24   # 0x2662
        MOVI             R2, 10   # 0x2666
        MOV_P            R15, 0, R2, R2, R2   # 0x266a
        MOVI             R6, 0   # 0x266e
        MOV_P            R1, 0, R6, R6, R6   # 0x2672
        C_ADDI           R3, 4   # 0x2676
        LD_GLOBAL_IDX    R13, R11, R3, 0, 0   # 0x2678
        SETP_LT_NP       P0, R3, R5, R13   # 0x267c
        MOVI             R3, 0   # 0x2680
        ADDI_P           R3, 0, R3, 1   # 0x2684
        ADD              R1, R13, R1, R13   # 0x2688
        SETP_LT_NP       P0, R5, R10, R1   # 0x268c
        C_CHWIDTH        R5, 1   # 0x2690
        MOV_P            R3, 0, R2, R2, R2   # 0x2692
        MOV_P            R1, 0, R6, R6, R6   # 0x2696
        ADD              R5, R15, R8, R15   # 0x269a
        ADD              R8, R3, R5, R3   # 0x269e
        C_CHWIDTH        R5, 0   # 0x26a2
        C_MOV            R5, R14   # 0x26a4
        C_ADDI           R9, 2   # 0x26a6
        SETP_NE_NP       P0, R3, R12, R9   # 0x26a8
        BRA_PRED         0, L2636   # 0x26ac
        C_BRA            L26b6   # 0x26b0
L26b2:  MOVI             R9, 0   # 0x26b2
L26b6:  MOVI             R6, 10   # 0x26b6
        MOVI             R14, 0   # 0x26ba
        LD_LOCAL         R2, 32   # 0x26be
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x26c2
        LD_LOCAL         R15, 12   # 0x26c6
        BRA_PRED         0, L260a   # 0x26ca
        C_CHWIDTH        R8, 1   # 0x26ce
        LD_LOCAL         R2, 36   # 0x26d0
        MUL_LO           R3, R2, R15, R15   # 0x26d4
        ADD              R3, R9, R3, R9   # 0x26d8
        C_SHLI           R3, 2   # 0x26dc
        LD_LOCAL         R2, 16   # 0x26de
        ADD              R3, R2, R3, R2   # 0x26e2
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x26e6
        C_MOV            R2, R5   # 0x26ea
        SETP_LT_NP       P0, R5, R13, R3   # 0x26ec
        ADD              R1, R3, R1, R3   # 0x26f0
        SETP_LT_NP       P1, R5, R10, R1   # 0x26f4
        MOV_P            R1, 1, R14, R14, R14   # 0x26f8
        MOVI             R5, 0   # 0x26fc
        ADDI_P           R5, 0, R5, 1   # 0x2700
        MOV_P            R5, 1, R6, R6, R6   # 0x2704
        ADD              R8, R5, R8, R5   # 0x2708
        C_MOV            R5, R2   # 0x270c
        C_MOV            R13, R3   # 0x270e
        BRA              L260a   # 0x2710
L2714:  C_MOV            R8, R6   # 0x2714
        C_MOV            R9, R10   # 0x2716
L2718:  LD_LOCAL         R1, 60   # 0x2718
        C_MOV            R5, R1   # 0x271c
        C_CHWIDTH        R5, 1   # 0x271e
        LD_LOCAL         R1, 12   # 0x2720
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x2724
        LD_LOCAL         R12, 56   # 0x2728
        LD_LOCAL         R10, 44   # 0x272c
        BRA_PRED         0, L27f2   # 0x2730
        MOVI             R1, 0   # 0x2734
        LD_LOCAL         R2, 12   # 0x2738
        C_ANDI           R2, 3   # 0x273c
        MOVI             R6, 0   # 0x273e
        C_BRA            L2754   # 0x2742
L2744:  LD_LOCAL         R3, 12   # 0x2744
        C_ADD            R1, R3   # 0x2748
        C_ADDI           R6, 1   # 0x274a
        SETP_NE_NP       P0, R3, R6, R3   # 0x274c
        BRA_PRED         4, L27f2   # 0x2750
L2754:  LD_LOCAL         R3, 28   # 0x2754
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x2758
        MOVI             R3, 0   # 0x275c
        BRA_PRED         0, L27bc   # 0x2760
L2764:  CHWIDTH_MULTI    40960, 1   # 0x2764
        C_CHWIDTH        R14, 0   # 0x2768
        ADD              R14, R1, R3, R1   # 0x276a
        C_SHLI           R14, 1   # 0x276e
        ADD              R14, R7, R14, R7   # 0x2770
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x2774
        SUB              R15, R15, R12, R15   # 0x2778
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x277c
        C_CHWIDTH        R15, 0   # 0x2780
        ADDI             R15, R14, 2   # 0x2782
        SZ_GLOBAL_LD_U16 R13, R0, R15, 0, 0   # 0x2786
        SUB              R13, R13, R12, R13   # 0x278a
        SZ_GLOBAL_ST_16  R13, R0, R15, 0, 0   # 0x278e
        ADDI             R15, R14, 4   # 0x2792
        SZ_GLOBAL_LD_U16 R13, R0, R15, 0, 0   # 0x2796
        SUB              R13, R13, R12, R13   # 0x279a
        SZ_GLOBAL_ST_16  R13, R0, R15, 0, 0   # 0x279e
        C_CHWIDTH        R15, 1   # 0x27a2
        C_ADDI           R14, 6   # 0x27a4
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x27a6
        SUB              R15, R15, R12, R15   # 0x27aa
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x27ae
        C_ADDI           R3, 4   # 0x27b2
        SETP_NE_NP       P0, R14, R9, R3   # 0x27b4
        BRA_PRED         0, L2764   # 0x27b8
L27bc:  SETP_EQ_NPI      P0, R14, R2, 0   # 0x27bc
        BRA_PRED         0, L2744   # 0x27c0
        C_CHWIDTH        R14, 0   # 0x27c4
        C_ADD            R3, R1   # 0x27c6
        C_MOV            R14, R2   # 0x27c8
L27ca:  C_CHWIDTH        R13, 1   # 0x27ca
        C_CHWIDTH        R15, 0   # 0x27cc
        C_MOV            R15, R3   # 0x27ce
        C_SHLI           R15, 1   # 0x27d0
        ADD              R15, R7, R15, R7   # 0x27d2
        SZ_GLOBAL_LD_U16 R13, R0, R15, 0, 0   # 0x27d6
        SUB              R13, R13, R12, R13   # 0x27da
        SZ_GLOBAL_ST_16  R13, R0, R15, 0, 0   # 0x27de
        C_ADDI           R3, 1   # 0x27e2
        ADDI             R14, R14, -1   # 0x27e4
        SETP_NE_NPI      P0, R15, R14, 0   # 0x27e8
        BRA_PRED         0, L27ca   # 0x27ec
        C_BRA            L2744   # 0x27f0
L27f2:  CHWIDTH_MULTI    57632, 0   # 0x27f2
        LD_LOCAL         R1, 64   # 0x27f6
        MOVI             R2, 0   # 0x27fa
        CALL             R14, 129346   # 0x27fe
        C_MOV            R2, R1   # 0x2802
        LD_LOCAL         R1, 68   # 0x2804
        CALL             R14, 129341   # 0x2808
        C_MOV            R2, R1   # 0x280c
        C_MOV            R1, R10   # 0x280e
        CALL             R14, 129337   # 0x2810
        C_MOV            R2, R1   # 0x2814
        C_MOV            R1, R8   # 0x2816
        CALL             R14, 129333   # 0x2818
        C_MOV            R2, R5   # 0x281c
        CALL             R14, 129330   # 0x281e
        LD_LOCAL         R14, 52   # 0x2822
        LD_LOCAL         R13, 92   # 0x2826
        LD_LOCAL         R12, 88   # 0x282a
        LD_LOCAL         R11, 84   # 0x282e
        LD_LOCAL         R10, 80   # 0x2832
        LD_LOCAL         R9, 76   # 0x2836
        LD_LOCAL         R8, 72   # 0x283a
        C_RET            224   # 0x283e
        CHWIDTH_MULTI    7, 1   # 0x2840
        XOR              R0, R2, R1, R2   # 0x2844
        CHWIDTH_MULTI    7, 0   # 0x2848
        C_ANDI           R0, 1   # 0x284c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x284e
        MOVI             R0, 40961   # 0x2852
        C_MOV            R7, R0   # 0x2856
        SHRI             R0, R2, 1   # 0x2858
        C_CHWIDTH        R2, 1   # 0x285c
        XOR              R2, R0, R7, R0   # 0x285e
        C_CHWIDTH        R2, 0   # 0x2862
        MOV_P            R0, 0, R2, R2, R2   # 0x2864
        C_CHWIDTH        R0, 1   # 0x2868
        SHRI             R2, R1, 1   # 0x286a
        C_CHWIDTH        R2, 1   # 0x286e
        XOR              R2, R2, R0, R2   # 0x2870
        CHWIDTH_MULTI    5, 0   # 0x2874
        C_ANDI           R2, 1   # 0x2878
        SETP_NE_NPI      P0, R2, R2, 0   # 0x287a
        C_CHWIDTH        R2, 1   # 0x287e
        SHRI             R0, R0, 1   # 0x2880
        XOR              R2, R0, R7, R0   # 0x2884
        C_CHWIDTH        R2, 0   # 0x2888
        MOV_P            R0, 0, R2, R2, R2   # 0x288a
        C_CHWIDTH        R0, 1   # 0x288e
        SHRI             R2, R1, 2   # 0x2890
        C_CHWIDTH        R2, 1   # 0x2894
        XOR              R2, R2, R0, R2   # 0x2896
        CHWIDTH_MULTI    5, 0   # 0x289a
        C_ANDI           R2, 1   # 0x289e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28a0
        C_CHWIDTH        R2, 1   # 0x28a4
        SHRI             R0, R0, 1   # 0x28a6
        XOR              R2, R0, R7, R0   # 0x28aa
        C_CHWIDTH        R2, 0   # 0x28ae
        MOV_P            R0, 0, R2, R2, R2   # 0x28b0
        C_CHWIDTH        R0, 1   # 0x28b4
        SHRI             R2, R1, 3   # 0x28b6
        C_CHWIDTH        R2, 1   # 0x28ba
        XOR              R2, R2, R0, R2   # 0x28bc
        CHWIDTH_MULTI    5, 0   # 0x28c0
        C_ANDI           R2, 1   # 0x28c4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28c6
        C_CHWIDTH        R2, 1   # 0x28ca
        SHRI             R0, R0, 1   # 0x28cc
        XOR              R2, R0, R7, R0   # 0x28d0
        C_CHWIDTH        R2, 0   # 0x28d4
        MOV_P            R0, 0, R2, R2, R2   # 0x28d6
        C_CHWIDTH        R0, 1   # 0x28da
        SHRI             R2, R1, 4   # 0x28dc
        C_CHWIDTH        R2, 1   # 0x28e0
        XOR              R2, R2, R0, R2   # 0x28e2
        CHWIDTH_MULTI    5, 0   # 0x28e6
        C_ANDI           R2, 1   # 0x28ea
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28ec
        C_CHWIDTH        R2, 1   # 0x28f0
        SHRI             R0, R0, 1   # 0x28f2
        XOR              R2, R0, R7, R0   # 0x28f6
        C_CHWIDTH        R2, 0   # 0x28fa
        MOV_P            R0, 0, R2, R2, R2   # 0x28fc
        C_CHWIDTH        R0, 1   # 0x2900
        SHRI             R2, R1, 5   # 0x2902
        C_CHWIDTH        R2, 1   # 0x2906
        XOR              R2, R2, R0, R2   # 0x2908
        CHWIDTH_MULTI    5, 0   # 0x290c
        C_ANDI           R2, 1   # 0x2910
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2912
        C_CHWIDTH        R2, 1   # 0x2916
        SHRI             R0, R0, 1   # 0x2918
        XOR              R2, R0, R7, R0   # 0x291c
        C_CHWIDTH        R2, 0   # 0x2920
        MOV_P            R0, 0, R2, R2, R2   # 0x2922
        C_CHWIDTH        R0, 1   # 0x2926
        SHRI             R2, R1, 6   # 0x2928
        C_CHWIDTH        R2, 1   # 0x292c
        XOR              R2, R2, R0, R2   # 0x292e
        CHWIDTH_MULTI    5, 0   # 0x2932
        C_ANDI           R2, 1   # 0x2936
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2938
        C_CHWIDTH        R2, 1   # 0x293c
        SHRI             R0, R0, 1   # 0x293e
        XOR              R2, R0, R7, R0   # 0x2942
        C_CHWIDTH        R2, 0   # 0x2946
        MOV_P            R0, 0, R2, R2, R2   # 0x2948
        MOVI             R2, 128   # 0x294c
        C_CHWIDTH        R2, 1   # 0x2950
        AND              R2, R1, R2, R1   # 0x2952
        C_CHWIDTH        R2, 0   # 0x2956
        SHRI             R2, R2, 7   # 0x2958
        ANDI             R3, R0, 1   # 0x295c
        C_CHWIDTH        R0, 1   # 0x2960
        C_CHWIDTH        R0, 0   # 0x2962
        SETP_EQ_NP       P0, R2, R2, R3   # 0x2964
        C_CHWIDTH        R2, 1   # 0x2968
        SHRI             R0, R0, 1   # 0x296a
        XOR              R2, R0, R7, R0   # 0x296e
        C_CHWIDTH        R2, 0   # 0x2972
        MOV_P            R2, 0, R0, R0, R0   # 0x2974
        C_CHWIDTH        R2, 1   # 0x2978
        SHRI             R0, R1, 8   # 0x297a
        C_CHWIDTH        R0, 1   # 0x297e
        XOR              R0, R2, R0, R2   # 0x2980
        CHWIDTH_MULTI    5, 0   # 0x2984
        C_ANDI           R0, 1   # 0x2988
        SETP_NE_NPI      P0, R0, R0, 0   # 0x298a
        SHRI             R0, R2, 1   # 0x298e
        C_CHWIDTH        R2, 1   # 0x2992
        XOR              R2, R0, R7, R0   # 0x2994
        C_CHWIDTH        R2, 0   # 0x2998
        MOV_P            R0, 0, R2, R2, R2   # 0x299a
        C_CHWIDTH        R0, 1   # 0x299e
        SHRI             R2, R1, 9   # 0x29a0
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
        SHRI             R2, R1, 10   # 0x29c6
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
        SHRI             R2, R1, 11   # 0x29ec
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
        C_CHWIDTH        R0, 1   # 0x2a10
        SHRI             R2, R1, 12   # 0x2a12
        C_CHWIDTH        R2, 1   # 0x2a16
        XOR              R2, R2, R0, R2   # 0x2a18
        CHWIDTH_MULTI    5, 0   # 0x2a1c
        C_ANDI           R2, 1   # 0x2a20
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a22
        C_CHWIDTH        R2, 1   # 0x2a26
        SHRI             R0, R0, 1   # 0x2a28
        XOR              R2, R0, R7, R0   # 0x2a2c
        C_CHWIDTH        R2, 0   # 0x2a30
        MOV_P            R0, 0, R2, R2, R2   # 0x2a32
        C_CHWIDTH        R0, 1   # 0x2a36
        SHRI             R2, R1, 13   # 0x2a38
        C_CHWIDTH        R2, 1   # 0x2a3c
        XOR              R2, R2, R0, R2   # 0x2a3e
        CHWIDTH_MULTI    5, 0   # 0x2a42
        C_ANDI           R2, 1   # 0x2a46
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a48
        C_CHWIDTH        R2, 1   # 0x2a4c
        SHRI             R0, R0, 1   # 0x2a4e
        XOR              R2, R0, R7, R0   # 0x2a52
        C_CHWIDTH        R2, 0   # 0x2a56
        MOV_P            R0, 0, R2, R2, R2   # 0x2a58
        C_CHWIDTH        R0, 1   # 0x2a5c
        SHRI             R2, R1, 14   # 0x2a5e
        C_CHWIDTH        R2, 1   # 0x2a62
        XOR              R2, R2, R0, R2   # 0x2a64
        CHWIDTH_MULTI    5, 0   # 0x2a68
        C_ANDI           R2, 1   # 0x2a6c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a6e
        C_CHWIDTH        R2, 1   # 0x2a72
        SHRI             R0, R0, 1   # 0x2a74
        XOR              R2, R0, R7, R0   # 0x2a78
        C_CHWIDTH        R2, 0   # 0x2a7c
        MOV_P            R0, 0, R2, R2, R2   # 0x2a7e
        SHRI             R1, R1, 15   # 0x2a82
        ANDI             R2, R0, 1   # 0x2a86
        C_CHWIDTH        R0, 1   # 0x2a8a
        C_CHWIDTH        R0, 0   # 0x2a8c
        SETP_EQ_NP       P0, R1, R1, R2   # 0x2a8e
        C_CHWIDTH        R1, 1   # 0x2a92
        SHRI             R0, R0, 1   # 0x2a94
        XOR              R1, R0, R7, R0   # 0x2a98
        C_CHWIDTH        R1, 0   # 0x2a9c
        MOV_P            R1, 0, R0, R0, R0   # 0x2a9e
        MOVI             R0, 65535   # 0x2aa2
        C_AND            R1, R0   # 0x2aa6
        C_RET            224   # 0x2aa8
        MOVI             R15, 2   # 0x2aaa
        LD_GLOBAL        R15, R15, 24   # 0x2aae
        SRD              R0, 2   # 0x2ab2
        C_ADD            R15, R0   # 0x2ab4
        ST_LOCAL         R8, 196   # 0x2ab6
        C_CHWIDTH        R8, 1   # 0x2aba
        ST_LOCAL         R9, 200   # 0x2abc
        ST_LOCAL         R10, 204   # 0x2ac0
        ST_LOCAL         R11, 208   # 0x2ac4
        ST_LOCAL         R12, 212   # 0x2ac8
        ST_LOCAL         R13, 216   # 0x2acc
        ST_LOCAL         R14, 184   # 0x2ad0
        ST_LOCAL         R2, 120   # 0x2ad4
        LD_GLOBAL_IDX    R0, R1, R2, 0, 60   # 0x2ad8
        SHLI             R0, R0, 16   # 0x2adc
        LD_GLOBAL_IDX    R5, R1, R2, 0, 56   # 0x2ae0
        SHRI             R4, R5, 16   # 0x2ae4
        OR               R6, R0, R4, R0   # 0x2ae8
        MOVI             R0, 65535   # 0x2aec
        AND              R7, R5, R0, R5   # 0x2af0
        ST_LOCAL         R1, 104   # 0x2af4
        SZ_GLOBAL_LD_U16 R8, R1, R2, 0, 4   # 0x2af8
        MOVI             R2, 0   # 0x2afc
        C_MOV            R14, R3   # 0x2b00
        C_CHWIDTH        R14, 1   # 0x2b02
        CVT_SEXT         R3, R8, R8, R8   # 0x2b04
        SETP_LT_NPI      P0, R3, R3, 1   # 0x2b08
        BRA_PRED         0, L2e5a   # 0x2b0c
        C_CHWIDTH        R14, 0   # 0x2b10
        C_MOV            R12, R7   # 0x2b12
        C_CHWIDTH        R7, 1   # 0x2b14
        C_MOV            R1, R6   # 0x2b16
        ADDI             R7, R8, 255   # 0x2b18
        CHWIDTH_MULTI    384, 0   # 0x2b1c
        ST_LOCAL         R7, 128   # 0x2b20
        MOVI             R4, 1   # 0x2b24
        C_MOV            R7, R4   # 0x2b28
        ST_LOCAL         R7, 108   # 0x2b2a
        MOVI             R4, 255   # 0x2b2e
        C_MOV            R6, R2   # 0x2b32
        ST_LOCAL         R2, 96   # 0x2b34
        ST_LOCAL         R2, 116   # 0x2b38
        ST_LOCAL         R14, 124   # 0x2b3c
        C_MOV            R5, R14   # 0x2b40
        C_CHWIDTH        R5, 1   # 0x2b42
        ST_LOCAL         R8, 100   # 0x2b44
        ST_LOCAL         R4, 112   # 0x2b48
        C_BRA            L2bd0   # 0x2b4c
L2b4e:  C_CHWIDTH        R11, 1   # 0x2b4e
        C_MOV            R7, R1   # 0x2b50
        C_MOV            R4, R12   # 0x2b52
        LD_GLOBAL_IDX    R3, R7, R4, 0, 0   # 0x2b54
        LD_GLOBAL_IDX    R7, R7, R4, 0, 4   # 0x2b58
        SHLI             R7, R7, 16   # 0x2b5c
        SHRI             R14, R3, 16   # 0x2b60
        C_OR             R7, R14   # 0x2b64
        C_AND            R3, R0   # 0x2b66
        LD_GLOBAL_IDX    R14, R7, R3, 0, 8   # 0x2b68
        LD_GLOBAL_IDX    R3, R7, R3, 0, 12   # 0x2b6c
        SHLI             R3, R3, 16   # 0x2b70
        SHRI             R7, R14, 16   # 0x2b74
        C_OR             R3, R7   # 0x2b78
        AND              R7, R14, R0, R14   # 0x2b7a
        C_CHWIDTH        R14, 1   # 0x2b7e
        SZ_GLOBAL_LD_U16 R14, R3, R7, 0, 0   # 0x2b80
        C_CHWIDTH        R14, 0   # 0x2b84
        SHRI             R3, R14, 8   # 0x2b86
        LD_LOCAL         R14, 108   # 0x2b8a
        AND              R11, R3, R14, R3   # 0x2b8e
        LD_LOCAL         R14, 116   # 0x2b92
        C_CHWIDTH        R14, 1   # 0x2b96
        ADDI             R14, R14, 1   # 0x2b98
        C_CHWIDTH        R14, 0   # 0x2b9c
        ST_LOCAL         R14, 116   # 0x2b9e
L2ba2:  CHWIDTH_MULTI    108, 1   # 0x2ba2
        ADD              R6, R11, R6, R11   # 0x2ba6
        C_MOV            R14, R0   # 0x2baa
        XOR              R3, R5, R14, R5   # 0x2bac
        C_CHWIDTH        R3, 0   # 0x2bb0
        SHRI             R3, R3, 15   # 0x2bb2
        ADD              R5, R5, R3, R5   # 0x2bb6
        ADDI             R2, R2, 1   # 0x2bba
        C_CHWIDTH        R2, 0   # 0x2bbe
        LD_LOCAL         R8, 100   # 0x2bc0
        SETP_NE_NP       P0, R3, R2, R8   # 0x2bc4
        LD_LOCAL         R4, 112   # 0x2bc8
        BRA_PRED         4, L2e22   # 0x2bcc
L2bd0:  C_CHWIDTH        R11, 0   # 0x2bd0
        C_MOV            R11, R1   # 0x2bd2
        SHLI             R7, R11, 16   # 0x2bd4
        C_MOV            R9, R12   # 0x2bd8
        AND              R14, R7, R9, R7   # 0x2bda
        ADD              R8, R7, R9, R7   # 0x2bde
        C_OR             R7, R9   # 0x2be2
        C_ANDN           R7, R8   # 0x2be4
        OR               R7, R14, R7, R14   # 0x2be6
        SHRI             R7, R7, 31   # 0x2bea
        SHRI             R14, R11, 16   # 0x2bee
        ADD              R7, R14, R7, R14   # 0x2bf2
        OR               R10, R8, R7, R8   # 0x2bf6
        CVT_SEXT         R7, R5, R5, R5   # 0x2bfa
        MOVI48           R3, 4294967295   # 0x2bfe
        SETP_LT_NP       P0, R7, R3, R7   # 0x2c04
        BRA_PRED         4, L2c6c   # 0x2c08
        MOVI             R8, 0   # 0x2c0c
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2c10
        BRA_PRED         0, L2cce   # 0x2c14
        C_CHWIDTH        R5, 0   # 0x2c18
        C_MOV            R11, R1   # 0x2c1a
        C_MOV            R9, R12   # 0x2c1c
L2c1e:  LD_GLOBAL_IDX    R7, R11, R9, 0, 8   # 0x2c1e
        LD_GLOBAL_IDX    R14, R11, R9, 0, 12   # 0x2c22
        SHLI             R14, R14, 16   # 0x2c26
        SHRI             R3, R7, 16   # 0x2c2a
        OR               R3, R14, R3, R14   # 0x2c2e
        C_CHWIDTH        R14, 1   # 0x2c32
        C_AND            R7, R0   # 0x2c34
        SZ_GLOBAL_LD_U16 R14, R3, R7, 0, 2   # 0x2c36
        C_CHWIDTH        R14, 0   # 0x2c3a
        SETP_EQ_NP       P0, R3, R14, R5   # 0x2c3c
        BRA_PRED         0, L2d3c   # 0x2c40
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2c44
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2c48
        SHRI             R14, R7, 16   # 0x2c4c
        SHLI             R9, R3, 16   # 0x2c50
        OR               R11, R9, R14, R9   # 0x2c54
        C_AND            R3, R0   # 0x2c58
        OR               R3, R7, R3, R7   # 0x2c5a
        AND              R9, R7, R0, R7   # 0x2c5e
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c62
        BRA_PRED         4, L2c1e   # 0x2c66
        C_BRA            L2cce   # 0x2c6a
L2c6c:  MOVI             R8, 0   # 0x2c6c
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2c70
        BRA_PRED         0, L2cce   # 0x2c74
L2c78:  LD_GLOBAL_IDX    R3, R11, R9, 0, 8   # 0x2c78
        LD_GLOBAL_IDX    R7, R11, R9, 0, 12   # 0x2c7c
        SHLI             R7, R7, 16   # 0x2c80
        SHRI             R14, R3, 16   # 0x2c84
        C_OR             R7, R14   # 0x2c88
        C_CHWIDTH        R14, 1   # 0x2c8a
        C_AND            R3, R0   # 0x2c8c
        SZ_GLOBAL_LD_U16 R14, R7, R3, 0, 0   # 0x2c8e
        C_CHWIDTH        R3, 1   # 0x2c92
        XOR              R14, R14, R2, R14   # 0x2c94
        AND              R3, R14, R4, R14   # 0x2c98
        C_CHWIDTH        R3, 0   # 0x2c9c
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c9e
        BRA_PRED         0, L2d3c   # 0x2ca2
        C_CHWIDTH        R14, 0   # 0x2ca6
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2ca8
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2cac
        SHRI             R14, R7, 16   # 0x2cb0
        SHLI             R9, R3, 16   # 0x2cb4
        OR               R11, R9, R14, R9   # 0x2cb8
        C_AND            R3, R0   # 0x2cbc
        OR               R3, R7, R3, R7   # 0x2cbe
        AND              R9, R7, R0, R7   # 0x2cc2
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2cc6
        BRA_PRED         0, L2c78   # 0x2cca
L2cce:  MOVI             R9, 0   # 0x2cce
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2cd2
        BRA_PRED         0, L2d48   # 0x2cd6
L2cda:  MOVI             R10, 0   # 0x2cda
        MOVI             R14, 0   # 0x2cde
L2ce2:  C_MOV            R4, R12   # 0x2ce2
        C_MOV            R11, R1   # 0x2ce4
        SHLI             R3, R10, 16   # 0x2ce6
        AND              R7, R3, R14, R3   # 0x2cea
        ADD              R1, R3, R14, R3   # 0x2cee
        C_OR             R3, R14   # 0x2cf2
        C_ANDN           R3, R1   # 0x2cf4
        OR               R3, R7, R3, R7   # 0x2cf6
        SHRI             R3, R3, 31   # 0x2cfa
        SHRI             R7, R10, 16   # 0x2cfe
        ADD              R3, R7, R3, R7   # 0x2d02
        LD_GLOBAL_IDX    R7, R11, R4, 0, 0   # 0x2d06
        ST_GLOBAL_IDX    R1, R11, R4, 0, 0   # 0x2d0a
        LD_GLOBAL_IDX    R14, R11, R4, 0, 4   # 0x2d0e
        ST_GLOBAL_IDX    R3, R11, R4, 0, 4   # 0x2d12
        SHRI             R3, R7, 16   # 0x2d16
        SHLI             R10, R14, 16   # 0x2d1a
        OR               R1, R10, R3, R10   # 0x2d1e
        AND              R3, R14, R0, R14   # 0x2d22
        OR               R3, R7, R3, R7   # 0x2d26
        AND              R12, R7, R0, R7   # 0x2d2a
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d2e
        C_MOV            R10, R11   # 0x2d32
        C_MOV            R14, R4   # 0x2d34
        BRA_PRED         0, L2ce2   # 0x2d36
        C_BRA            L2d50   # 0x2d3a
L2d3c:  C_CHWIDTH        R14, 0   # 0x2d3c
        C_MOV            R8, R11   # 0x2d3e
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2d40
        BRA_PRED         4, L2cda   # 0x2d44
L2d48:  MOVI             R11, 0   # 0x2d48
        MOVI             R4, 0   # 0x2d4c
L2d50:  C_MOV            R12, R4   # 0x2d50
        C_MOV            R1, R11   # 0x2d52
        SHLI             R3, R8, 16   # 0x2d54
        AND              R7, R3, R9, R3   # 0x2d58
        ADD              R14, R3, R9, R3   # 0x2d5c
        C_OR             R3, R9   # 0x2d60
        C_ANDN           R3, R14   # 0x2d62
        OR               R3, R7, R3, R7   # 0x2d64
        SHRI             R3, R3, 31   # 0x2d68
        SHRI             R7, R8, 16   # 0x2d6c
        ADD              R3, R7, R3, R7   # 0x2d70
        OR               R3, R14, R3, R14   # 0x2d74
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d78
        BRA_PRED         4, L2b4e   # 0x2d7c
        CHWIDTH_MULTI    3072, 1   # 0x2d80
        LD_GLOBAL_IDX    R3, R8, R9, 0, 12   # 0x2d84
        SHLI             R3, R3, 16   # 0x2d88
        LD_GLOBAL_IDX    R7, R8, R9, 0, 8   # 0x2d8c
        SHRI             R14, R7, 16   # 0x2d90
        C_OR             R3, R14   # 0x2d94
        C_AND            R7, R0   # 0x2d96
        SZ_GLOBAL_LD_U16 R10, R3, R7, 0, 0   # 0x2d98
        C_CHWIDTH        R10, 0   # 0x2d9c
        LD_GLOBAL_IDX    R14, R8, R9, 0, 4   # 0x2d9e
        LD_GLOBAL_IDX    R7, R8, R9, 0, 0   # 0x2da2
        SHRI             R3, R10, 9   # 0x2da6
        C_CHWIDTH        R3, 1   # 0x2daa
        AND              R3, R10, R3, R10   # 0x2dac
        AND              R10, R14, R0, R14   # 0x2db0
        OR               R10, R7, R10, R7   # 0x2db4
        LD_LOCAL         R4, 108   # 0x2db8
        AND              R11, R3, R4, R3   # 0x2dbc
        C_CHWIDTH        R3, 0   # 0x2dc0
        LD_LOCAL         R3, 96   # 0x2dc2
        C_CHWIDTH        R3, 1   # 0x2dc6
        ADDI             R3, R3, 1   # 0x2dc8
        C_CHWIDTH        R3, 0   # 0x2dcc
        ST_LOCAL         R3, 96   # 0x2dce
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2dd2
        BRA_PRED         0, L2ba2   # 0x2dd6
        SHRI             R3, R7, 16   # 0x2dda
        SHLI             R14, R14, 16   # 0x2dde
        OR               R3, R14, R3, R14   # 0x2de2
        C_AND            R7, R0   # 0x2de6
        LD_GLOBAL_IDX    R14, R3, R7, 0, 0   # 0x2de8
        SZ_GLOBAL_LD_U16 R10, R3, R7, 0, 4   # 0x2dec
        ST_GLOBAL_IDX    R10, R8, R9, 0, 4   # 0x2df0
        ST_GLOBAL_IDX    R14, R8, R9, 0, 0   # 0x2df4
        C_MOV            R9, R1   # 0x2df8
        C_MOV            R4, R12   # 0x2dfa
        LD_GLOBAL_IDX    R14, R9, R4, 0, 0   # 0x2dfc
        SZ_GLOBAL_LD_U16 R8, R9, R4, 0, 4   # 0x2e00
        ST_GLOBAL_IDX    R8, R3, R7, 0, 4   # 0x2e04
        ST_GLOBAL_IDX    R14, R3, R7, 0, 0   # 0x2e08
        SHRI             R14, R3, 16   # 0x2e0c
        ST_GLOBAL_IDX    R14, R9, R4, 0, 4   # 0x2e10
        SHLI             R3, R3, 16   # 0x2e14
        C_OR             R3, R7   # 0x2e18
        ST_GLOBAL_IDX    R3, R9, R4, 0, 0   # 0x2e1a
        BRA              L2ba2   # 0x2e1e
L2e22:  C_CHWIDTH        R5, 0   # 0x2e22
        C_CHWIDTH        R2, 1   # 0x2e24
        MOVI             R0, 255   # 0x2e26
        LD_LOCAL         R14, 128   # 0x2e2a
        AND              R2, R14, R0, R14   # 0x2e2e
        C_CHWIDTH        R2, 0   # 0x2e32
        LD_LOCAL         R0, 96   # 0x2e34
        SHLI             R0, R0, 2   # 0x2e38
        LD_LOCAL         R14, 116   # 0x2e3c
        C_CHWIDTH        R14, 1   # 0x2e40
        SUB              R14, R0, R14, R0   # 0x2e42
        C_CHWIDTH        R0, 1   # 0x2e46
        ADD              R0, R14, R6, R14   # 0x2e48
        CHWIDTH_MULTI    16449, 0   # 0x2e4c
        C_MOV            R6, R1   # 0x2e50
        C_MOV            R7, R12   # 0x2e52
        LD_LOCAL         R14, 124   # 0x2e54
        C_BRA            L2e60   # 0x2e58
L2e5a:  C_CHWIDTH        R14, 0   # 0x2e5a
        C_MOV            R5, R14   # 0x2e5c
        C_MOV            R0, R2   # 0x2e5e
L2e60:  C_CHWIDTH        R14, 1   # 0x2e60
        ST_LOCAL         R5, 188   # 0x2e62
        ST_LOCAL         R0, 180   # 0x2e66
        CVT_SEXT         R0, R14, R14, R14   # 0x2e6a
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2e6e
        ST_LOCAL         R2, 192   # 0x2e72
        BRA_PRED         0, L34a6   # 0x2e76
        CHWIDTH_MULTI    18432, 0   # 0x2e7a
        MOVI             R0, 1   # 0x2e7e
        ST_LOCAL         R0, 168   # 0x2e82
        MOVI             R12, 65535   # 0x2e86
        MOVI             R0, 128   # 0x2e8a
        C_MOV            R14, R0   # 0x2e8e
        ST_LOCAL         R14, 108   # 0x2e90
        MOVI             R0, 7   # 0x2e94
        C_MOV            R14, R0   # 0x2e98
        ST_LOCAL         R14, 128   # 0x2e9a
        MOVI             R0, 15   # 0x2e9e
        C_MOV            R14, R0   # 0x2ea2
        ST_LOCAL         R14, 132   # 0x2ea4
        MOVI             R0, 127   # 0x2ea8
        C_MOV            R14, R0   # 0x2eac
        ST_LOCAL         R14, 112   # 0x2eae
        MOVI             R0, 65280   # 0x2eb2
        C_MOV            R14, R0   # 0x2eb6
        ST_LOCAL         R14, 136   # 0x2eb8
        C_BRA            L2eec   # 0x2ebc
L2ebe:  MOVI             R0, 0   # 0x2ebe
        ST_GLOBAL_IDX    R0, R10, R11, 0, 4   # 0x2ec2
        ST_GLOBAL_IDX    R0, R10, R11, 0, 0   # 0x2ec6
        LD_LOCAL         R0, 168   # 0x2eca
        C_SHLI           R0, 1   # 0x2ece
        ST_LOCAL         R0, 168   # 0x2ed0
        LD_LOCAL         R0, 176   # 0x2ed4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2ed8
        LD_LOCAL         R8, 164   # 0x2edc
        C_MOV            R6, R8   # 0x2ee0
        LD_LOCAL         R9, 160   # 0x2ee2
        C_MOV            R7, R9   # 0x2ee6
        BRA_PRED         4, L34ac   # 0x2ee8
L2eec:  MOVI             R5, 0   # 0x2eec
        MOVI             R10, 0   # 0x2ef0
        MOVI             R11, 0   # 0x2ef4
        MOVI             R0, 0   # 0x2ef8
        ST_LOCAL         R0, 164   # 0x2efc
        ST_LOCAL         R0, 160   # 0x2f00
        C_BRA            L2f14   # 0x2f04
L2f06:  C_CHWIDTH        R8, 0   # 0x2f06
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2f08
        LD_LOCAL         R5, 172   # 0x2f0c
        BRA_PRED         0, L2ebe   # 0x2f10
L2f14:  LD_LOCAL         R4, 168   # 0x2f14
        SETP_LT_NPI      P0, R0, R4, 1   # 0x2f18
        BRA_PRED         0, L2f5a   # 0x2f1c
        MOVI             R2, 0   # 0x2f20
        C_MOV            R0, R6   # 0x2f24
        C_MOV            R1, R7   # 0x2f26
L2f28:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x2f28
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x2f2c
        AND              R0, R3, R12, R3   # 0x2f30
        OR               R0, R1, R0, R1   # 0x2f34
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2f38
        BRA_PRED         4, L2f64   # 0x2f3c
        SHRI             R0, R1, 16   # 0x2f40
        SHLI             R3, R3, 16   # 0x2f44
        OR               R0, R3, R0, R3   # 0x2f48
        C_AND            R1, R12   # 0x2f4c
        C_ADDI           R2, 1   # 0x2f4e
        SETP_EQ_NP       P0, R3, R4, R2   # 0x2f50
        BRA_PRED         4, L2f28   # 0x2f54
        C_BRA            L2f70   # 0x2f58
L2f5a:  MOVI             R4, 0   # 0x2f5a
        C_MOV            R0, R6   # 0x2f5e
        C_MOV            R1, R7   # 0x2f60
        C_BRA            L2f70   # 0x2f62
L2f64:  MOVI             R0, 0   # 0x2f64
        ADDI             R4, R2, 1   # 0x2f68
        MOVI             R1, 0   # 0x2f6c
L2f70:  ST_LOCAL         R5, 176   # 0x2f70
        ADDI             R2, R5, 1   # 0x2f74
        ST_LOCAL         R2, 172   # 0x2f78
        C_MOV            R9, R6   # 0x2f7c
        C_MOV            R13, R7   # 0x2f7e
        C_MOV            R6, R0   # 0x2f80
        C_MOV            R7, R1   # 0x2f82
        LD_LOCAL         R0, 168   # 0x2f84
        ST_LOCAL         R0, 100   # 0x2f88
        C_BRA            L2fa6   # 0x2f8c
L2f8e:  ST_LOCAL         R4, 164   # 0x2f8e
        ST_LOCAL         R5, 160   # 0x2f92
L2f96:  C_MOV            R9, R1   # 0x2f96
        C_MOV            R13, R3   # 0x2f98
        C_MOV            R6, R0   # 0x2f9a
        C_MOV            R7, R2   # 0x2f9c
        C_MOV            R10, R4   # 0x2f9e
        C_MOV            R11, R5   # 0x2fa0
        LD_LOCAL         R4, 96   # 0x2fa2
L2fa6:  MOVI             R0, 0   # 0x2fa6
        SETP_LT_NP       P0, R0, R0, R4   # 0x2faa
        BRA_PRED         0, L2fea   # 0x2fae
        SHLI             R0, R6, 16   # 0x2fb2
        AND              R1, R0, R7, R0   # 0x2fb6
        ADD              R2, R0, R7, R0   # 0x2fba
        C_OR             R0, R7   # 0x2fbe
        C_ANDN           R0, R2   # 0x2fc0
        OR               R0, R1, R0, R1   # 0x2fc2
        SHRI             R0, R0, 31   # 0x2fc6
        SHRI             R1, R6, 16   # 0x2fca
        ADD              R0, R1, R0, R1   # 0x2fce
        OR               R0, R2, R0, R2   # 0x2fd2
        LD_LOCAL         R1, 100   # 0x2fd6
        SETP_LT_NPI      P0, R1, R1, 1   # 0x2fda
        BRA_PRED         0, L2f06   # 0x2fde
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x2fe2
        BRA_PRED         0, L2f06   # 0x2fe6
L2fea:  SETP_NE_NPI      P0, R0, R4, 0   # 0x2fea
        BRA_PRED         4, L3136   # 0x2fee
        LD_LOCAL         R0, 100   # 0x2ff2
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2ff6
        BRA_PRED         0, L316c   # 0x2ffa
        SHLI             R0, R6, 16   # 0x2ffe
        AND              R1, R0, R7, R0   # 0x3002
        ADD              R2, R0, R7, R0   # 0x3006
        C_OR             R0, R7   # 0x300a
        C_ANDN           R0, R2   # 0x300c
        OR               R0, R1, R0, R1   # 0x300e
        SHRI             R0, R0, 31   # 0x3012
        SHRI             R1, R6, 16   # 0x3016
        ADD              R0, R1, R0, R1   # 0x301a
        OR               R0, R2, R0, R2   # 0x301e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3022
        BRA_PRED         4, L316c   # 0x3026
        LD_GLOBAL_IDX    R3, R6, R7, 0, 8   # 0x302a
        ST_LOCAL         R7, 116   # 0x302e
        LD_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x3032
        LD_GLOBAL_IDX    R0, R9, R13, 0, 8   # 0x3036
        LD_GLOBAL_IDX    R1, R9, R13, 0, 12   # 0x303a
        SHLI             R1, R1, 16   # 0x303e
        SHRI             R2, R0, 16   # 0x3042
        C_OR             R1, R2   # 0x3046
        AND              R2, R0, R12, R0   # 0x3048
        CHWIDTH_MULTI    4097, 1   # 0x304c
        SZ_GLOBAL_LD_U16 R12, R1, R2, 0, 0   # 0x3050
        LD_LOCAL         R7, 108   # 0x3054
        AND              R0, R12, R7, R12   # 0x3058
        C_CHWIDTH        R0, 0   # 0x305c
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x305e
        ST_LOCAL         R4, 96   # 0x3062
        BRA_PRED         4, L3192   # 0x3066
        C_CHWIDTH        R0, 1   # 0x306a
        ST_LOCAL         R2, 152   # 0x306c
        ST_LOCAL         R1, 148   # 0x3070
        ST_LOCAL         R5, 144   # 0x3074
        ST_LOCAL         R3, 140   # 0x3078
        LD_LOCAL         R14, 128   # 0x307c
        AND              R0, R12, R14, R12   # 0x3080
        CHWIDTH_MULTI    4097, 0   # 0x3084
        SHRI             R1, R12, 3   # 0x3088
        C_CHWIDTH        R1, 1   # 0x308c
        LD_LOCAL         R14, 132   # 0x308e
        AND              R1, R1, R14, R1   # 0x3092
        C_CHWIDTH        R1, 0   # 0x3096
        MULI             R1, R1, 17   # 0x3098
        C_MOV            R3, R1   # 0x309c
        C_CHWIDTH        R3, 1   # 0x309e
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x30a0
        BRA_PRED         0, L319e   # 0x30a4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x30a8
        C_MOV            R4, R12   # 0x30ac
        BRA_PRED         0, L31e6   # 0x30ae
        CHWIDTH_MULTI    264, 0   # 0x30b2
        ST_LOCAL         R13, 156   # 0x30b6
        ST_LOCAL         R6, 124   # 0x30ba
        MOVI             R0, 34   # 0x30be
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x30c2
        MOVI             R6, 34   # 0x30c6
        MOV_P            R6, 0, R3, R3, R3   # 0x30ca
        LD_LOCAL         R13, 104   # 0x30ce
        LD_LOCAL         R8, 120   # 0x30d2
        SZ_GLOBAL_LD_U16 R5, R13, R8, 0, 2   # 0x30d6
        SZ_GLOBAL_LD_U16 R4, R13, R8, 0, 0   # 0x30da
        LD_GLOBAL_IDX    R1, R13, R8, 0, 40   # 0x30de
        LD_GLOBAL_IDX    R0, R13, R8, 0, 32   # 0x30e2
        LD_GLOBAL_IDX    R2, R13, R8, 0, 36   # 0x30e6
        SZ_GLOBAL_LD_U16 R3, R13, R8, 0, 96   # 0x30ea
        ST_GLOBAL        R3, R15, -4   # 0x30ee
        SHLI             R2, R2, 16   # 0x30f2
        SHRI             R3, R0, 16   # 0x30f6
        C_OR             R2, R3   # 0x30fa
        MOVI             R3, 65535   # 0x30fc
        AND              R3, R0, R3, R0   # 0x3100
        CALL             R14, 127154   # 0x3104
        C_CHWIDTH        R0, 1   # 0x3108
        MOVI             R15, 2   # 0x310a
        LD_GLOBAL        R15, R15, 24   # 0x310e
        SRD              R3, 2   # 0x3112
        C_ADD            R15, R3   # 0x3114
        SZ_GLOBAL_LD_U16 R0, R13, R8, 0, 102   # 0x3116
        C_CHWIDTH        R0, 0   # 0x311a
        C_MOV            R4, R1   # 0x311c
        C_CHWIDTH        R4, 1   # 0x311e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3120
        BRA_PRED         0, L312c   # 0x3124
        SZ_GLOBAL_ST_16  R4, R13, R8, 0, 102   # 0x3128
L312c:  LD_LOCAL         R6, 124   # 0x312c
        LD_LOCAL         R13, 156   # 0x3130
        C_BRA            L31e6   # 0x3134
L3136:  LD_GLOBAL_IDX    R1, R6, R7, 0, 0   # 0x3136
        LD_GLOBAL_IDX    R0, R6, R7, 0, 4   # 0x313a
        SHLI             R0, R0, 16   # 0x313e
        SHRI             R2, R1, 16   # 0x3142
        C_OR             R0, R2   # 0x3146
        AND              R2, R1, R12, R1   # 0x3148
        MOVI             R1, 0   # 0x314c
        ST_LOCAL         R1, 96   # 0x3150
        LD_LOCAL         R1, 100   # 0x3154
        ADDI             R1, R1, -1   # 0x3158
        ST_LOCAL         R1, 100   # 0x315c
        C_MOV            R1, R9   # 0x3160
        C_MOV            R3, R13   # 0x3162
        C_MOV            R4, R6   # 0x3164
        C_MOV            R5, R7   # 0x3166
        BRA              L344c   # 0x3168
L316c:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x316c
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x3170
        SHLI             R1, R1, 16   # 0x3174
        SHRI             R2, R0, 16   # 0x3178
        C_OR             R1, R2   # 0x317c
        AND              R3, R0, R12, R0   # 0x317e
        ADDI             R4, R4, -1   # 0x3182
        ST_LOCAL         R4, 96   # 0x3186
        C_MOV            R0, R6   # 0x318a
        C_MOV            R2, R7   # 0x318c
        BRA              L3448   # 0x318e
L3192:  C_CHWIDTH        R2, 1   # 0x3192
        LD_LOCAL         R14, 112   # 0x3194
        AND              R2, R12, R14, R12   # 0x3198
        C_BRA            L3244   # 0x319c
L319e:  CHWIDTH_MULTI    264, 0   # 0x319e
        ST_LOCAL         R6, 124   # 0x31a2
        LD_LOCAL         R1, 104   # 0x31a6
        LD_LOCAL         R8, 120   # 0x31aa
        SZ_GLOBAL_LD_U16 R4, R1, R8, 0, 96   # 0x31ae
        ADDI             R2, R8, 64   # 0x31b2
        CALL             R14, 128411   # 0x31b6
        C_CHWIDTH        R0, 1   # 0x31ba
        MOVI             R15, 2   # 0x31bc
        LD_GLOBAL        R15, R15, 24   # 0x31c0
        SRD              R3, 2   # 0x31c4
        C_ADD            R15, R3   # 0x31c6
        LD_LOCAL         R3, 104   # 0x31c8
        SZ_GLOBAL_LD_U16 R0, R3, R8, 0, 100   # 0x31cc
        C_CHWIDTH        R0, 0   # 0x31d0
        C_MOV            R4, R1   # 0x31d2
        C_CHWIDTH        R4, 1   # 0x31d4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x31d6
        BRA_PRED         0, L31e2   # 0x31da
        SZ_GLOBAL_ST_16  R4, R3, R8, 0, 100   # 0x31de
L31e2:  LD_LOCAL         R6, 124   # 0x31e2
L31e6:  CHWIDTH_MULTI    280, 0   # 0x31e6
        LD_LOCAL         R5, 120   # 0x31ea
        LD_LOCAL         R8, 104   # 0x31ee
        SZ_GLOBAL_LD_U16 R2, R8, R5, 0, 96   # 0x31f2
        C_MOV            R1, R4   # 0x31f6
        CALL             R14, 129826   # 0x31f8
        C_CHWIDTH        R2, 1   # 0x31fc
        MOVI             R15, 2   # 0x31fe
        LD_GLOBAL        R15, R15, 24   # 0x3202
        SRD              R3, 2   # 0x3206
        C_ADD            R15, R3   # 0x3208
        SZ_GLOBAL_ST_16  R1, R8, R5, 0, 96   # 0x320a
        LD_LOCAL         R14, 112   # 0x320e
        AND              R2, R4, R14, R4   # 0x3212
        LD_LOCAL         R14, 136   # 0x3216
        C_CHWIDTH        R14, 1   # 0x321a
        AND              R14, R12, R14, R12   # 0x321c
        OR               R14, R14, R2, R14   # 0x3220
        LD_LOCAL         R7, 108   # 0x3224
        OR               R14, R14, R7, R14   # 0x3228
        LD_LOCAL         R0, 148   # 0x322c
        LD_LOCAL         R1, 152   # 0x3230
        SZ_GLOBAL_ST_16  R14, R0, R1, 0, 0   # 0x3234
        LD_LOCAL         R4, 96   # 0x3238
        LD_LOCAL         R3, 140   # 0x323c
        LD_LOCAL         R5, 144   # 0x3240
L3244:  C_CHWIDTH        R12, 1   # 0x3244
        SHLI             R0, R5, 16   # 0x3246
        SHRI             R1, R3, 16   # 0x324a
        OR               R1, R0, R1, R0   # 0x324e
        MOVI             R0, 65535   # 0x3252
        C_AND            R3, R0   # 0x3256
        C_CHWIDTH        R0, 1   # 0x3258
        SZ_GLOBAL_LD_U16 R12, R1, R3, 0, 0   # 0x325a
        AND              R0, R12, R7, R12   # 0x325e
        C_CHWIDTH        R0, 0   # 0x3262
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3264
        BRA_PRED         4, L3338   # 0x3268
        C_CHWIDTH        R0, 1   # 0x326c
        CHWIDTH_MULTI    16388, 0   # 0x326e
        ST_LOCAL         R3, 148   # 0x3272
        ST_LOCAL         R1, 144   # 0x3276
        ST_LOCAL         R2, 140   # 0x327a
        LD_LOCAL         R14, 128   # 0x327e
        AND              R0, R12, R14, R12   # 0x3282
        CHWIDTH_MULTI    4097, 0   # 0x3286
        SHRI             R1, R12, 3   # 0x328a
        C_CHWIDTH        R1, 1   # 0x328e
        LD_LOCAL         R14, 132   # 0x3290
        AND              R1, R1, R14, R1   # 0x3294
        C_CHWIDTH        R1, 0   # 0x3298
        MULI             R1, R1, 17   # 0x329a
        C_MOV            R3, R1   # 0x329e
        C_CHWIDTH        R3, 1   # 0x32a0
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x32a2
        BRA_PRED         0, L3346   # 0x32a6
        SETP_NE_NPI      P0, R0, R0, 0   # 0x32aa
        C_MOV            R4, R12   # 0x32ae
        BRA_PRED         0, L338e   # 0x32b0
        CHWIDTH_MULTI    264, 0   # 0x32b4
        ST_LOCAL         R9, 152   # 0x32b8
        ST_LOCAL         R6, 124   # 0x32bc
        MOVI             R0, 34   # 0x32c0
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x32c4
        MOVI             R6, 34   # 0x32c8
        MOV_P            R6, 0, R3, R3, R3   # 0x32cc
        LD_LOCAL         R9, 104   # 0x32d0
        LD_LOCAL         R8, 120   # 0x32d4
        SZ_GLOBAL_LD_U16 R5, R9, R8, 0, 2   # 0x32d8
        SZ_GLOBAL_LD_U16 R4, R9, R8, 0, 0   # 0x32dc
        LD_GLOBAL_IDX    R1, R9, R8, 0, 40   # 0x32e0
        LD_GLOBAL_IDX    R0, R9, R8, 0, 32   # 0x32e4
        LD_GLOBAL_IDX    R2, R9, R8, 0, 36   # 0x32e8
        SZ_GLOBAL_LD_U16 R3, R9, R8, 0, 96   # 0x32ec
        ST_GLOBAL        R3, R15, -4   # 0x32f0
        SHLI             R2, R2, 16   # 0x32f4
        SHRI             R3, R0, 16   # 0x32f8
        C_OR             R2, R3   # 0x32fc
        MOVI             R3, 65535   # 0x32fe
        AND              R3, R0, R3, R0   # 0x3302
        CALL             R14, 126897   # 0x3306
        C_CHWIDTH        R0, 1   # 0x330a
        MOVI             R15, 2   # 0x330c
        LD_GLOBAL        R15, R15, 24   # 0x3310
        SRD              R3, 2   # 0x3314
        C_ADD            R15, R3   # 0x3316
        SZ_GLOBAL_LD_U16 R0, R9, R8, 0, 102   # 0x3318
        C_CHWIDTH        R0, 0   # 0x331c
        C_MOV            R4, R1   # 0x331e
        C_CHWIDTH        R4, 1   # 0x3320
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3322
        BRA_PRED         0, L332e   # 0x3326
        SZ_GLOBAL_ST_16  R4, R9, R8, 0, 102   # 0x332a
L332e:  LD_LOCAL         R6, 124   # 0x332e
        LD_LOCAL         R9, 152   # 0x3332
        C_BRA            L338e   # 0x3336
L3338:  C_CHWIDTH        R0, 1   # 0x3338
        C_CHWIDTH        R14, 0   # 0x333a
        LD_LOCAL         R14, 112   # 0x333c
        AND              R0, R12, R14, R12   # 0x3340
        C_BRA            L33e8   # 0x3344
L3346:  CHWIDTH_MULTI    264, 0   # 0x3346
        ST_LOCAL         R6, 124   # 0x334a
        LD_LOCAL         R1, 104   # 0x334e
        LD_LOCAL         R8, 120   # 0x3352
        SZ_GLOBAL_LD_U16 R4, R1, R8, 0, 96   # 0x3356
        ADDI             R2, R8, 64   # 0x335a
        CALL             R14, 128199   # 0x335e
        C_CHWIDTH        R0, 1   # 0x3362
        MOVI             R15, 2   # 0x3364
        LD_GLOBAL        R15, R15, 24   # 0x3368
        SRD              R3, 2   # 0x336c
        C_ADD            R15, R3   # 0x336e
        LD_LOCAL         R3, 104   # 0x3370
        SZ_GLOBAL_LD_U16 R0, R3, R8, 0, 100   # 0x3374
        C_CHWIDTH        R0, 0   # 0x3378
        C_MOV            R4, R1   # 0x337a
        C_CHWIDTH        R4, 1   # 0x337c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x337e
        BRA_PRED         0, L338a   # 0x3382
        SZ_GLOBAL_ST_16  R4, R3, R8, 0, 100   # 0x3386
L338a:  LD_LOCAL         R6, 124   # 0x338a
L338e:  CHWIDTH_MULTI    280, 0   # 0x338e
        LD_LOCAL         R5, 120   # 0x3392
        LD_LOCAL         R8, 104   # 0x3396
        SZ_GLOBAL_LD_U16 R2, R8, R5, 0, 96   # 0x339a
        C_MOV            R1, R4   # 0x339e
        CALL             R14, 129614   # 0x33a0
        C_CHWIDTH        R0, 1   # 0x33a4
        MOVI             R15, 2   # 0x33a6
        LD_GLOBAL        R15, R15, 24   # 0x33aa
        SRD              R3, 2   # 0x33ae
        C_ADD            R15, R3   # 0x33b0
        SZ_GLOBAL_ST_16  R1, R8, R5, 0, 96   # 0x33b2
        LD_LOCAL         R14, 112   # 0x33b6
        AND              R0, R4, R14, R4   # 0x33ba
        LD_LOCAL         R14, 136   # 0x33be
        C_CHWIDTH        R14, 1   # 0x33c2
        AND              R14, R12, R14, R12   # 0x33c4
        OR               R14, R14, R0, R14   # 0x33c8
        LD_LOCAL         R7, 108   # 0x33cc
        OR               R14, R14, R7, R14   # 0x33d0
        LD_LOCAL         R1, 144   # 0x33d4
        LD_LOCAL         R2, 148   # 0x33d8
        SZ_GLOBAL_ST_16  R14, R1, R2, 0, 0   # 0x33dc
        LD_LOCAL         R4, 96   # 0x33e0
        LD_LOCAL         R2, 140   # 0x33e4
L33e8:  CHWIDTH_MULTI    4101, 0   # 0x33e8
        SETP_LT_U_NP     P0, R0, R0, R2   # 0x33ec
        LD_LOCAL         R5, 116   # 0x33f0
        MOVI             R12, 65535   # 0x33f4
        BRA_PRED         4, L3426   # 0x33f8
        LD_GLOBAL_IDX    R1, R6, R5, 0, 0   # 0x33fc
        LD_GLOBAL_IDX    R0, R6, R5, 0, 4   # 0x3400
        SHLI             R0, R0, 16   # 0x3404
        SHRI             R2, R1, 16   # 0x3408
        C_OR             R0, R2   # 0x340c
        AND              R2, R1, R12, R1   # 0x340e
        LD_LOCAL         R1, 100   # 0x3412
        ADDI             R1, R1, -1   # 0x3416
        ST_LOCAL         R1, 100   # 0x341a
        C_MOV            R1, R9   # 0x341e
        C_MOV            R3, R13   # 0x3420
        C_MOV            R4, R6   # 0x3422
        C_BRA            L344c   # 0x3424
L3426:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x3426
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x342a
        SHLI             R1, R1, 16   # 0x342e
        SHRI             R2, R0, 16   # 0x3432
        C_OR             R1, R2   # 0x3436
        AND              R3, R0, R12, R0   # 0x3438
        ADDI             R4, R4, -1   # 0x343c
        ST_LOCAL         R4, 96   # 0x3440
        C_MOV            R0, R6   # 0x3444
        C_MOV            R2, R5   # 0x3446
L3448:  C_MOV            R4, R9   # 0x3448
        C_MOV            R5, R13   # 0x344a
L344c:  C_CHWIDTH        R14, 0   # 0x344c
        SHLI             R6, R10, 16   # 0x344e
        AND              R7, R6, R11, R6   # 0x3452
        ADD              R14, R6, R11, R6   # 0x3456
        C_OR             R6, R11   # 0x345a
        C_ANDN           R6, R14   # 0x345c
        OR               R6, R7, R6, R7   # 0x345e
        SHRI             R6, R6, 31   # 0x3462
        SHRI             R7, R10, 16   # 0x3466
        ADD              R6, R7, R6, R7   # 0x346a
        OR               R6, R14, R6, R14   # 0x346e
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x3472
        BRA_PRED         0, L2f8e   # 0x3476
        SHLI             R6, R4, 16   # 0x347a
        ADD              R7, R6, R5, R6   # 0x347e
        ST_GLOBAL_IDX    R7, R10, R11, 0, 0   # 0x3482
        OR               R14, R6, R5, R6   # 0x3486
        ANDN             R7, R14, R7, R14   # 0x348a
        C_AND            R6, R5   # 0x348e
        C_OR             R6, R7   # 0x3490
        SHRI             R6, R6, 31   # 0x3492
        SHRI             R7, R4, 16   # 0x3496
        ADD              R6, R7, R6, R7   # 0x349a
        ST_GLOBAL_IDX    R6, R10, R11, 0, 4   # 0x349e
        BRA              L2f96   # 0x34a2
L34a6:  C_CHWIDTH        R8, 0   # 0x34a6
        C_MOV            R8, R6   # 0x34a8
        C_MOV            R9, R7   # 0x34aa
L34ac:  CHWIDTH_MULTI    18432, 0   # 0x34ac
        LD_GLOBAL_IDX    R1, R8, R9, 0, 0   # 0x34b0
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x34b4
        SHLI             R0, R0, 16   # 0x34b8
        SHRI             R2, R1, 16   # 0x34bc
        OR               R3, R0, R2, R0   # 0x34c0
        MOVI             R0, 65535   # 0x34c4
        AND              R4, R1, R0, R1   # 0x34c8
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x34cc
        SHLI             R1, R1, 16   # 0x34d0
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x34d4
        SHRI             R5, R2, 16   # 0x34d8
        OR               R5, R1, R5, R1   # 0x34dc
        AND              R6, R2, R0, R2   # 0x34e0
        LD_GLOBAL_IDX    R7, R5, R6, 0, 8   # 0x34e4
        SZ_GLOBAL_LD_U16 R1, R5, R6, 0, 12   # 0x34e8
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x34ec
        ST_GLOBAL_IDX    R1, R3, R4, 0, 12   # 0x34f0
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x34f4
        ST_GLOBAL_IDX    R7, R3, R4, 0, 8   # 0x34f8
        AND              R7, R2, R0, R2   # 0x34fc
        ST_GLOBAL_IDX    R7, R5, R6, 0, 12   # 0x3500
        ST_GLOBAL_IDX    R1, R5, R6, 0, 8   # 0x3504
        LD_GLOBAL_IDX    R7, R5, R6, 0, 0   # 0x3508
        SZ_GLOBAL_LD_U16 R14, R5, R6, 0, 4   # 0x350c
        ST_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x3510
        ST_GLOBAL_IDX    R7, R3, R4, 0, 0   # 0x3514
        LD_LOCAL         R10, 188   # 0x3518
        C_MOV            R4, R10   # 0x351c
        C_CHWIDTH        R4, 1   # 0x351e
        C_MOV            R7, R10   # 0x3520
        C_CHWIDTH        R7, 1   # 0x3522
        C_MOV            R11, R10   # 0x3524
        C_CHWIDTH        R11, 1   # 0x3526
        CVT_SEXT         R3, R4, R7, R11   # 0x3528
        CHWIDTH_MULTI    144, 0   # 0x352c
        MOVI48           R4, 4294967295   # 0x3530
        SETP_LT_NP       P0, R3, R4, R3   # 0x3536
        MOVI             R3, 0   # 0x353a
        ST_GLOBAL_IDX    R3, R5, R6, 0, 4   # 0x353e
        ST_GLOBAL_IDX    R3, R5, R6, 0, 0   # 0x3542
        C_MOV            R13, R8   # 0x3546
        ST_LOCAL         R9, 160   # 0x3548
        BRA_PRED         4, L359c   # 0x354c
L3550:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x3550
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x3554
        SHLI             R4, R4, 16   # 0x3558
        SHRI             R7, R3, 16   # 0x355c
        C_OR             R4, R7   # 0x3560
        C_CHWIDTH        R7, 1   # 0x3562
        C_AND            R3, R0   # 0x3564
        SZ_GLOBAL_LD_U16 R7, R4, R3, 0, 2   # 0x3566
        C_CHWIDTH        R7, 0   # 0x356a
        SETP_EQ_NP       P0, R3, R7, R10   # 0x356c
        BRA_PRED         0, L35f2   # 0x3570
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x3574
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x3578
        SHRI             R7, R4, 16   # 0x357c
        SHLI             R14, R3, 16   # 0x3580
        OR               R8, R14, R7, R14   # 0x3584
        C_AND            R3, R0   # 0x3588
        OR               R3, R4, R3, R4   # 0x358a
        AND              R9, R4, R0, R4   # 0x358e
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x3592
        BRA_PRED         4, L3550   # 0x3596
        C_BRA            L35ea   # 0x359a
L359c:  LD_LOCAL         R10, 192   # 0x359c
L35a0:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x35a0
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x35a4
        SHLI             R4, R4, 16   # 0x35a8
        SHRI             R7, R3, 16   # 0x35ac
        C_OR             R4, R7   # 0x35b0
        C_CHWIDTH        R7, 1   # 0x35b2
        C_AND            R3, R0   # 0x35b4
        SZ_GLOBAL_LD_U8  R7, R4, R3, 0, 0   # 0x35b6
        C_CHWIDTH        R7, 0   # 0x35ba
        SETP_EQ_NP       P0, R3, R7, R10   # 0x35bc
        BRA_PRED         0, L35f2   # 0x35c0
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x35c4
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x35c8
        SHRI             R7, R4, 16   # 0x35cc
        SHLI             R14, R3, 16   # 0x35d0
        OR               R8, R14, R7, R14   # 0x35d4
        C_AND            R3, R0   # 0x35d8
        OR               R3, R4, R3, R4   # 0x35da
        AND              R9, R4, R0, R4   # 0x35de
        SETP_NE_NPI      P0, R3, R3, 0   # 0x35e2
        BRA_PRED         0, L35a0   # 0x35e6
L35ea:  MOVI             R8, 0   # 0x35ea
        MOVI             R9, 0   # 0x35ee
L35f2:  SHLI             R2, R2, 16   # 0x35f2
        SHRI             R3, R1, 16   # 0x35f6
        SHLI             R4, R8, 16   # 0x35fa
        AND              R7, R4, R9, R4   # 0x35fe
        ADD              R14, R4, R9, R4   # 0x3602
        C_OR             R4, R9   # 0x3606
        C_ANDN           R4, R14   # 0x3608
        OR               R4, R7, R4, R7   # 0x360a
        SHRI             R4, R4, 31   # 0x360e
        SHRI             R7, R8, 16   # 0x3612
        ADD              R4, R7, R4, R7   # 0x3616
        OR               R4, R14, R4, R14   # 0x361a
        SETP_NE_NPI      P0, R4, R4, 0   # 0x361e
        BRA_PRED         0, L3648   # 0x3622
        C_MOV            R7, R13   # 0x3626
        LD_LOCAL         R14, 160   # 0x3628
        LD_GLOBAL_IDX    R4, R7, R14, 0, 0   # 0x362c
        LD_GLOBAL_IDX    R7, R7, R14, 0, 4   # 0x3630
        SHLI             R7, R7, 16   # 0x3634
        SHRI             R14, R4, 16   # 0x3638
        OR               R8, R7, R14, R7   # 0x363c
        MOVI             R7, 65535   # 0x3640
        AND              R9, R4, R7, R4   # 0x3644
L3648:  C_CHWIDTH        R11, 0   # 0x3648
        OR               R10, R2, R3, R2   # 0x364a
        AND              R11, R1, R0, R1   # 0x364e
        SHLI             R0, R8, 16   # 0x3652
        AND              R1, R0, R9, R0   # 0x3656
        ADD              R2, R0, R9, R0   # 0x365a
        C_OR             R0, R9   # 0x365e
        C_ANDN           R0, R2   # 0x3660
        OR               R0, R1, R0, R1   # 0x3662
        SHRI             R0, R0, 31   # 0x3666
        SHRI             R1, R8, 16   # 0x366a
        ADD              R0, R1, R0, R1   # 0x366e
        OR               R0, R2, R0, R2   # 0x3672
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3676
        BRA_PRED         0, L36e8   # 0x367a
        C_CHWIDTH        R4, 1   # 0x367e
        C_MOV            R1, R13   # 0x3680
        LD_LOCAL         R2, 160   # 0x3682
        LD_GLOBAL_IDX    R0, R1, R2, 0, 8   # 0x3686
        LD_GLOBAL_IDX    R1, R1, R2, 0, 12   # 0x368a
        SHLI             R1, R1, 16   # 0x368e
        SHRI             R2, R0, 16   # 0x3692
        C_OR             R1, R2   # 0x3696
        MOVI             R12, 65535   # 0x3698
        C_AND            R0, R12   # 0x369c
        SZ_GLOBAL_LD_U16 R4, R1, R0, 0, 0   # 0x369e
        LD_LOCAL         R2, 180   # 0x36a2
L36a6:  CHWIDTH_MULTI    20, 0   # 0x36a6
        C_MOV            R1, R4   # 0x36aa
        CALL             R14, 127467   # 0x36ac
        MOVI             R15, 2   # 0x36b0
        LD_GLOBAL        R15, R15, 24   # 0x36b4
        SRD              R3, 2   # 0x36b8
        C_ADD            R15, R3   # 0x36ba
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x36bc
        LD_GLOBAL_IDX    R2, R8, R9, 0, 0   # 0x36c0
        SHRI             R3, R2, 16   # 0x36c4
        SHLI             R7, R0, 16   # 0x36c8
        OR               R8, R7, R3, R7   # 0x36cc
        C_AND            R0, R12   # 0x36d0
        OR               R0, R2, R0, R2   # 0x36d2
        AND              R9, R2, R12, R2   # 0x36d6
        C_MOV            R2, R1   # 0x36da
        C_CHWIDTH        R2, 1   # 0x36dc
        SETP_NE_NPI      P0, R0, R0, 0   # 0x36de
        BRA_PRED         0, L36a6   # 0x36e2
        C_BRA            L36ec   # 0x36e6
L36e8:  LD_LOCAL         R2, 180   # 0x36e8
L36ec:  C_CHWIDTH        R2, 0   # 0x36ec
        ST_LOCAL         R2, 180   # 0x36ee
        LD_LOCAL         R7, 160   # 0x36f2
        LD_GLOBAL_IDX    R1, R13, R7, 0, 0   # 0x36f6
        LD_GLOBAL_IDX    R0, R13, R7, 0, 4   # 0x36fa
        SHLI             R0, R0, 16   # 0x36fe
        SHRI             R2, R1, 16   # 0x3702
        OR               R2, R0, R2, R0   # 0x3706
        MOVI             R0, 65535   # 0x370a
        C_AND            R1, R0   # 0x370e
        LD_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x3710
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 12   # 0x3714
        ST_GLOBAL_IDX    R4, R5, R6, 0, 12   # 0x3718
        ST_GLOBAL_IDX    R3, R5, R6, 0, 8   # 0x371c
        SHRI             R3, R10, 16   # 0x3720
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x3724
        SHLI             R3, R10, 16   # 0x3728
        C_OR             R3, R11   # 0x372c
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x372e
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3732
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 4   # 0x3736
        ST_GLOBAL_IDX    R4, R5, R6, 0, 4   # 0x373a
        ST_GLOBAL_IDX    R3, R5, R6, 0, 0   # 0x373e
        SHRI             R3, R5, 16   # 0x3742
        ST_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x3746
        SHLI             R3, R5, 16   # 0x374a
        C_OR             R3, R6   # 0x374e
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3750
        C_MOV            R1, R13   # 0x3754
        C_MOV            R13, R7   # 0x3756
        MOVI             R9, 1   # 0x3758
        C_BRA            L3780   # 0x375c
L375e:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x375e
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x3762
        C_SHLI           R9, 1   # 0x3766
        LD_LOCAL         R1, 104   # 0x3768
        SETP_NE_NPI      P0, R1, R1, 0   # 0x376c
        LD_LOCAL         R3, 96   # 0x3770
        C_MOV            R1, R3   # 0x3774
        LD_LOCAL         R4, 100   # 0x3776
        C_MOV            R13, R4   # 0x377a
        BRA_PRED         4, L39f8   # 0x377c
L3780:  MOVI             R5, 0   # 0x3780
        MOVI             R2, 0   # 0x3784
        MOVI             R4, 0   # 0x3788
        MOVI             R3, 0   # 0x378c
        ST_LOCAL         R3, 96   # 0x3790
        ST_LOCAL         R3, 100   # 0x3794
        ST_LOCAL         R9, 112   # 0x3798
        C_BRA            L37ae   # 0x379c
L379e:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x379e
        LD_LOCAL         R9, 112   # 0x37a2
        LD_LOCAL         R5, 108   # 0x37a6
        BRA_PRED         0, L375e   # 0x37aa
L37ae:  ST_LOCAL         R5, 104   # 0x37ae
        SETP_LT_NPI      P0, R5, R9, 1   # 0x37b2
        BRA_PRED         0, L37f6   # 0x37b6
        MOVI             R5, 0   # 0x37ba
        C_MOV            R6, R1   # 0x37be
        C_MOV            R7, R13   # 0x37c0
L37c2:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x37c2
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x37c6
        AND              R6, R14, R0, R14   # 0x37ca
        OR               R6, R7, R6, R7   # 0x37ce
        SETP_NE_NPI      P0, R6, R6, 0   # 0x37d2
        BRA_PRED         4, L3800   # 0x37d6
        SHRI             R6, R7, 16   # 0x37da
        SHLI             R14, R14, 16   # 0x37de
        OR               R6, R14, R6, R14   # 0x37e2
        C_AND            R7, R0   # 0x37e6
        C_ADDI           R5, 1   # 0x37e8
        SETP_EQ_NP       P0, R14, R9, R5   # 0x37ea
        BRA_PRED         4, L37c2   # 0x37ee
        C_MOV            R8, R9   # 0x37f2
        C_BRA            L380c   # 0x37f4
L37f6:  MOVI             R8, 0   # 0x37f6
        C_MOV            R6, R1   # 0x37fa
        C_MOV            R7, R13   # 0x37fc
        C_BRA            L380c   # 0x37fe
L3800:  MOVI             R6, 0   # 0x3800
        ADDI             R8, R5, 1   # 0x3804
        MOVI             R7, 0   # 0x3808
L380c:  LD_LOCAL         R5, 104   # 0x380c
        C_ADDI           R5, 1   # 0x3810
        ST_LOCAL         R5, 108   # 0x3812
        C_MOV            R5, R1   # 0x3816
        C_MOV            R14, R13   # 0x3818
        C_MOV            R1, R6   # 0x381a
        C_MOV            R13, R7   # 0x381c
        C_BRA            L3832   # 0x381e
L3820:  ST_LOCAL         R6, 96   # 0x3820
        ST_LOCAL         R7, 100   # 0x3824
L3828:  C_MOV            R5, R11   # 0x3828
        C_MOV            R14, R10   # 0x382a
        C_MOV            R1, R12   # 0x382c
        C_MOV            R2, R6   # 0x382e
        C_MOV            R4, R7   # 0x3830
L3832:  SETP_LT_NP       P0, R6, R3, R8   # 0x3832
        BRA_PRED         0, L386e   # 0x3836
        SHLI             R6, R1, 16   # 0x383a
        AND              R7, R6, R13, R6   # 0x383e
        ADD              R10, R6, R13, R6   # 0x3842
        C_OR             R6, R13   # 0x3846
        C_ANDN           R6, R10   # 0x3848
        OR               R6, R7, R6, R7   # 0x384a
        SHRI             R6, R6, 31   # 0x384e
        SHRI             R7, R1, 16   # 0x3852
        ADD              R6, R7, R6, R7   # 0x3856
        OR               R6, R10, R6, R10   # 0x385a
        SETP_LT_NPI      P0, R7, R9, 1   # 0x385e
        BRA_PRED         0, L379e   # 0x3862
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x3866
        BRA_PRED         0, L379e   # 0x386a
L386e:  SETP_NE_NPI      P0, R6, R8, 0   # 0x386e
        BRA_PRED         4, L392a   # 0x3872
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x3876
        BRA_PRED         0, L3954   # 0x387a
        SHLI             R6, R1, 16   # 0x387e
        AND              R7, R6, R13, R6   # 0x3882
        ADD              R10, R6, R13, R6   # 0x3886
        C_OR             R6, R13   # 0x388a
        C_ANDN           R6, R10   # 0x388c
        OR               R6, R7, R6, R7   # 0x388e
        SHRI             R6, R6, 31   # 0x3892
        SHRI             R7, R1, 16   # 0x3896
        ADD              R6, R7, R6, R7   # 0x389a
        OR               R6, R10, R6, R10   # 0x389e
        SETP_NE_NPI      P0, R6, R6, 0   # 0x38a2
        BRA_PRED         4, L3954   # 0x38a6
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x38aa
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x38ae
        SHLI             R7, R7, 16   # 0x38b2
        SHRI             R10, R6, 16   # 0x38b6
        C_OR             R7, R10   # 0x38ba
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x38bc
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x38c0
        C_AND            R6, R0   # 0x38c4
        C_MOV            R3, R13   # 0x38c6
        C_CHWIDTH        R13, 1   # 0x38c8
        SZ_GLOBAL_LD_U8  R13, R7, R6, 0, 1   # 0x38ca
        SZ_GLOBAL_ST_8   R13, R7, R6, 0, 0   # 0x38ce
        SHLI             R11, R11, 16   # 0x38d2
        SHRI             R12, R10, 16   # 0x38d6
        C_OR             R11, R12   # 0x38da
        C_AND            R10, R0   # 0x38dc
        SZ_GLOBAL_LD_U8  R13, R11, R10, 0, 1   # 0x38de
        SZ_GLOBAL_ST_8   R13, R11, R10, 0, 0   # 0x38e2
        SZ_GLOBAL_LD_U16 R13, R7, R6, 0, 2   # 0x38e6
        C_CHWIDTH        R7, 1   # 0x38ea
        SZ_GLOBAL_LD_U16 R7, R11, R10, 0, 2   # 0x38ec
        CVT_SEXT         R6, R7, R7, R7   # 0x38f0
        C_CHWIDTH        R7, 0   # 0x38f4
        CVT_SEXT         R7, R13, R13, R13   # 0x38f6
        SETP_LT_NP       P0, R6, R6, R7   # 0x38fa
        BRA_PRED         4, L3978   # 0x38fe
        C_CHWIDTH        R13, 0   # 0x3902
        LD_GLOBAL_IDX    R6, R1, R3, 0, 0   # 0x3904
        LD_GLOBAL_IDX    R7, R1, R3, 0, 4   # 0x3908
        SHLI             R7, R7, 16   # 0x390c
        SHRI             R10, R6, 16   # 0x3910
        OR               R12, R7, R10, R7   # 0x3914
        AND              R13, R6, R0, R6   # 0x3918
        ADDI             R9, R9, -1   # 0x391c
        C_MOV            R11, R5   # 0x3920
        C_MOV            R10, R14   # 0x3922
        C_MOV            R6, R1   # 0x3924
        C_MOV            R7, R3   # 0x3926
        C_BRA            L399e   # 0x3928
L392a:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x392a
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x392e
        SHLI             R7, R7, 16   # 0x3932
        SHRI             R8, R6, 16   # 0x3936
        OR               R12, R7, R8, R7   # 0x393a
        C_MOV            R7, R13   # 0x393e
        AND              R13, R6, R0, R6   # 0x3940
        MOVI             R8, 0   # 0x3944
        ADDI             R9, R9, -1   # 0x3948
        C_MOV            R11, R5   # 0x394c
        C_MOV            R10, R14   # 0x394e
        C_MOV            R6, R1   # 0x3950
        C_BRA            L39a2   # 0x3952
L3954:  LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x3954
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x3958
        SHLI             R7, R7, 16   # 0x395c
        SHRI             R10, R6, 16   # 0x3960
        OR               R11, R7, R10, R7   # 0x3964
        AND              R10, R6, R0, R6   # 0x3968
        ADDI             R8, R8, -1   # 0x396c
        C_MOV            R12, R1   # 0x3970
        C_MOV            R6, R5   # 0x3972
        C_MOV            R7, R14   # 0x3974
        C_BRA            L39a2   # 0x3976
L3978:  C_CHWIDTH        R13, 0   # 0x3978
        LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x397a
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x397e
        SHLI             R7, R7, 16   # 0x3982
        SHRI             R10, R6, 16   # 0x3986
        OR               R11, R7, R10, R7   # 0x398a
        AND              R10, R6, R0, R6   # 0x398e
        ADDI             R8, R8, -1   # 0x3992
        C_MOV            R12, R1   # 0x3996
        C_MOV            R13, R3   # 0x3998
        C_MOV            R6, R5   # 0x399a
        C_MOV            R7, R14   # 0x399c
L399e:  MOVI             R3, 0   # 0x399e
L39a2:  SHLI             R5, R2, 16   # 0x39a2
        AND              R14, R5, R4, R5   # 0x39a6
        ADD              R1, R5, R4, R5   # 0x39aa
        C_OR             R5, R4   # 0x39ae
        C_ANDN           R5, R1   # 0x39b0
        OR               R5, R14, R5, R14   # 0x39b2
        SHRI             R5, R5, 31   # 0x39b6
        SHRI             R14, R2, 16   # 0x39ba
        ADD              R5, R14, R5, R14   # 0x39be
        C_OR             R1, R5   # 0x39c2
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x39c4
        BRA_PRED         0, L3820   # 0x39c8
        SHLI             R1, R6, 16   # 0x39cc
        ADD              R5, R1, R7, R1   # 0x39d0
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x39d4
        OR               R14, R1, R7, R1   # 0x39d8
        ANDN             R5, R14, R5, R14   # 0x39dc
        C_AND            R1, R7   # 0x39e0
        C_OR             R1, R5   # 0x39e2
        SHRI             R1, R1, 31   # 0x39e4
        SHRI             R5, R6, 16   # 0x39e8
        ADD              R1, R5, R1, R5   # 0x39ec
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x39f0
        BRA              L3828   # 0x39f4
L39f8:  LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x39f8
        LD_GLOBAL_IDX    R0, R3, R4, 0, 0   # 0x39fc
        MOVI             R5, 65535   # 0x3a00
        AND              R2, R1, R5, R1   # 0x3a04
        OR               R2, R0, R2, R0   # 0x3a08
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x3a0c
        BRA_PRED         0, L3a82   # 0x3a10
        SHRI             R2, R0, 16   # 0x3a14
        SHLI             R1, R1, 16   # 0x3a18
        OR               R6, R1, R2, R1   # 0x3a1c
        AND              R8, R0, R5, R0   # 0x3a20
        LD_GLOBAL_IDX    R0, R3, R4, 0, 8   # 0x3a24
        LD_GLOBAL_IDX    R1, R3, R4, 0, 12   # 0x3a28
        C_CHWIDTH        R4, 1   # 0x3a2c
        SHLI             R1, R1, 16   # 0x3a2e
        SHRI             R2, R0, 16   # 0x3a32
        C_OR             R1, R2   # 0x3a36
        C_AND            R0, R5   # 0x3a38
        SZ_GLOBAL_LD_U16 R4, R1, R0, 0, 0   # 0x3a3a
        LD_LOCAL         R2, 180   # 0x3a3e
L3a42:  CHWIDTH_MULTI    20, 0   # 0x3a42
        C_MOV            R1, R4   # 0x3a46
        CALL             R14, 127005   # 0x3a48
        MOVI             R15, 2   # 0x3a4c
        LD_GLOBAL        R15, R15, 24   # 0x3a50
        SRD              R3, 2   # 0x3a54
        C_ADD            R15, R3   # 0x3a56
        LD_GLOBAL_IDX    R0, R6, R8, 0, 4   # 0x3a58
        LD_GLOBAL_IDX    R2, R6, R8, 0, 0   # 0x3a5c
        SHRI             R3, R2, 16   # 0x3a60
        SHLI             R6, R0, 16   # 0x3a64
        C_OR             R6, R3   # 0x3a68
        C_AND            R0, R5   # 0x3a6a
        OR               R0, R2, R0, R2   # 0x3a6c
        AND              R8, R2, R5, R2   # 0x3a70
        C_MOV            R2, R1   # 0x3a74
        C_CHWIDTH        R2, 1   # 0x3a76
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3a78
        BRA_PRED         0, L3a42   # 0x3a7c
        C_BRA            L3a86   # 0x3a80
L3a82:  LD_LOCAL         R2, 180   # 0x3a82
L3a86:  C_CHWIDTH        R2, 0   # 0x3a86
        LD_LOCAL         R14, 184   # 0x3a88
        C_MOV            R1, R2   # 0x3a8c
        LD_LOCAL         R13, 216   # 0x3a8e
        LD_LOCAL         R12, 212   # 0x3a92
        LD_LOCAL         R11, 208   # 0x3a96
        LD_LOCAL         R10, 204   # 0x3a9a
        LD_LOCAL         R9, 200   # 0x3a9e
        LD_LOCAL         R8, 196   # 0x3aa2
        C_RET            224   # 0x3aa6
        MOVI             R15, 2   # 0x3aa8
        LD_GLOBAL        R15, R15, 24   # 0x3aac
        SRD              R14, 2   # 0x3ab0
        C_ADD            R15, R14   # 0x3ab2
        MOVI             R0, 2   # 0x3ab4
        LD_GLOBAL        R1, R0, 44   # 0x3ab8
        ST_LOCAL         R1, 228   # 0x3abc
        LD_GLOBAL        R1, R0, 40   # 0x3ac0
        ST_LOCAL         R1, 224   # 0x3ac4
        LD_GLOBAL        R1, R0, 48   # 0x3ac8
        LD_GLOBAL        R8, R0, 32   # 0x3acc
        LD_GLOBAL        R0, R0, 36   # 0x3ad0
        ADDI             R4, R15, -1   # 0x3ad4
        MOVI             R2, 102   # 0x3ad8
        C_CHWIDTH        R2, 1   # 0x3adc
        MOVI             R3, 65388   # 0x3ade
        C_ADDI           R3, 4   # 0x3ae2
        MOVI             R10, 65388   # 0x3ae4
        SZ_GLOBAL_ST_16  R2, R4, R3, 0, 0   # 0x3ae8
        C_CHWIDTH        R2, 0   # 0x3aec
        C_MOV            R11, R4   # 0x3aee
        MOVI             R2, 2000   # 0x3af0
        SRD              R12, 0   # 0x3af4
        MADLO            R3, R12, R2, R0   # 0x3af6
        ADDI             R2, R3, 1332   # 0x3afa
        SHLI             R0, R8, 16   # 0x3afe
        ADD              R4, R0, R2, R0   # 0x3b02
        OR               R5, R0, R2, R0   # 0x3b06
        C_ANDN           R5, R4   # 0x3b0a
        AND              R2, R0, R2, R0   # 0x3b0c
        OR               R9, R2, R5, R2   # 0x3b10
        ADD              R5, R0, R3, R0   # 0x3b14
        OR               R6, R0, R3, R0   # 0x3b18
        C_ANDN           R6, R5   # 0x3b1c
        AND              R7, R0, R3, R0   # 0x3b1e
        OR               R6, R7, R6, R7   # 0x3b22
        ADDI             R7, R10, 2   # 0x3b26
        MOVI             R2, 0   # 0x3b2a
        C_MOV            R14, R2   # 0x3b2e
        ST_LOCAL         R14, 232   # 0x3b30
        C_MOV            R2, R14   # 0x3b34
        C_CHWIDTH        R2, 1   # 0x3b36
        SZ_GLOBAL_ST_16  R2, R11, R7, 0, 0   # 0x3b38
        C_CHWIDTH        R2, 0   # 0x3b3c
        ST_LOCAL         R11, 236   # 0x3b3e
        MOVI             R7, 7   # 0x3b42
        ST_GLOBAL        R7, R15, -100   # 0x3b46
        ST_GLOBAL        R1, R15, -104   # 0x3b4a
        ST_GLOBAL        R5, R15, -132   # 0x3b4e
        ST_GLOBAL        R5, R15, -140   # 0x3b52
        ST_GLOBAL        R4, R15, -116   # 0x3b56
        ADDI             R2, R3, 666   # 0x3b5a
        ADD              R1, R0, R2, R0   # 0x3b5e
        OR               R4, R0, R2, R0   # 0x3b62
        C_MOV            R7, R2   # 0x3b66
        ST_LOCAL         R7, 240   # 0x3b68
        C_ANDN           R4, R1   # 0x3b6c
        ST_GLOBAL        R1, R15, -124   # 0x3b6e
        SHRI             R1, R6, 31   # 0x3b72
        C_MOV            R2, R8   # 0x3b76
        ST_LOCAL         R2, 244   # 0x3b78
        SHRI             R5, R2, 16   # 0x3b7c
        ADD              R1, R5, R1, R5   # 0x3b80
        ST_GLOBAL        R1, R15, -128   # 0x3b84
        ST_GLOBAL        R1, R15, -136   # 0x3b88
        SHRI             R1, R9, 31   # 0x3b8c
        ADD              R1, R5, R1, R5   # 0x3b90
        ST_GLOBAL        R1, R15, -112   # 0x3b94
        C_AND            R0, R7   # 0x3b98
        C_OR             R0, R4   # 0x3b9a
        SHRI             R0, R0, 31   # 0x3b9c
        ADD              R0, R5, R0, R5   # 0x3ba0
        ST_GLOBAL        R0, R15, -120   # 0x3ba4
        C_MOV            R4, R12   # 0x3ba8
        ST_LOCAL         R4, 220   # 0x3baa
        SZ_GLOBAL_ST_16  R4, R11, R10, 0, 0   # 0x3bae
        MOVI             R0, 666   # 0x3bb2
        ST_GLOBAL        R0, R15, -108   # 0x3bb6
        MOVI             R1, 666   # 0x3bba
        CALL             R14, 123423   # 0x3bbe
        MOVI             R15, 2   # 0x3bc2
        LD_GLOBAL        R15, R15, 24   # 0x3bc6
        SRD              R3, 2   # 0x3bca
        C_ADD            R15, R3   # 0x3bcc
        SHLI             R0, R1, 16   # 0x3bce
        ADD              R3, R0, R2, R0   # 0x3bd2
        OR               R4, R0, R2, R0   # 0x3bd6
        C_ANDN           R4, R3   # 0x3bda
        ST_GLOBAL        R3, R15, -92   # 0x3bdc
        C_AND            R0, R2   # 0x3be0
        C_OR             R0, R4   # 0x3be2
        SHRI             R0, R0, 31   # 0x3be4
        SHRI             R1, R1, 16   # 0x3be8
        ADD              R0, R1, R0, R1   # 0x3bec
        ST_GLOBAL        R0, R15, -88   # 0x3bf0
        LD_LOCAL         R0, 220   # 0x3bf4
        SHLI             R0, R0, 16   # 0x3bf8
        SRAI             R4, R0, 16   # 0x3bfc
        ADDI             R5, R15, -1   # 0x3c00
        MOVI             R0, 65388   # 0x3c04
        ADDI             R6, R0, 64   # 0x3c08
        MOVI             R1, 666   # 0x3c0c
        LD_LOCAL         R2, 244   # 0x3c10
        LD_LOCAL         R3, 240   # 0x3c14
        CALL             R14, 124568   # 0x3c18
        MOVI             R15, 2   # 0x3c1c
        LD_GLOBAL        R15, R15, 24   # 0x3c20
        SRD              R3, 2   # 0x3c24
        C_ADD            R15, R3   # 0x3c26
        LD_LOCAL         R0, 236   # 0x3c28
        MOVI             R1, 65388   # 0x3c2c
        SZ_GLOBAL_LD_U16 R2, R0, R1, 0, 0   # 0x3c30
        MOVI             R0, 65535   # 0x3c34
        LD_GLOBAL        R1, R15, -116   # 0x3c38
        AND              R4, R1, R0, R1   # 0x3c3c
        SHRI             R0, R1, 16   # 0x3c40
        LD_GLOBAL        R1, R15, -112   # 0x3c44
        SHLI             R1, R1, 16   # 0x3c48
        OR               R3, R1, R0, R1   # 0x3c4c
        LD_GLOBAL        R1, R15, -108   # 0x3c50
        CALL             R14, 124901   # 0x3c54
        MOVI             R15, 2   # 0x3c58
        LD_GLOBAL        R15, R15, 24   # 0x3c5c
        SRD              R3, 2   # 0x3c60
        C_ADD            R15, R3   # 0x3c62
        LD_LOCAL         R11, 232   # 0x3c64
        MOVI             R0, 0   # 0x3c68
        ST_GLOBAL        R0, R15, -48   # 0x3c6c
        ST_GLOBAL        R0, R15, -52   # 0x3c70
        LD_GLOBAL        R0, R15, -104   # 0x3c74
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3c78
        C_MOV            R12, R11   # 0x3c7c
        C_CHWIDTH        R12, 1   # 0x3c7e
        C_MOV            R13, R11   # 0x3c80
        C_CHWIDTH        R13, 1   # 0x3c82
        C_MOV            R14, R11   # 0x3c84
        CHWIDTH_MULTI    18432, 1   # 0x3c86
        BRA_PRED         0, L3dd8   # 0x3c8a
        CHWIDTH_MULTI    30720, 0   # 0x3c8e
        ADDI             R8, R15, -1   # 0x3c92
        MOVI             R9, 1   # 0x3c96
        C_MOV            R1, R8   # 0x3c9a
        MOVI             R2, 65388   # 0x3c9c
        MOVI             R3, 1   # 0x3ca0
        CALL             R14, 128769   # 0x3ca4
        MOVI             R15, 2   # 0x3ca8
        LD_GLOBAL        R15, R15, 24   # 0x3cac
        SRD              R3, 2   # 0x3cb0
        C_ADD            R15, R3   # 0x3cb2
        MOVI             R11, 65388   # 0x3cb4
        ADDI             R10, R11, 96   # 0x3cb8
        SZ_GLOBAL_LD_U16 R2, R8, R10, 0, 0   # 0x3cbc
        CALL             R14, 128446   # 0x3cc0
        MOVI             R15, 2   # 0x3cc4
        LD_GLOBAL        R15, R15, 24   # 0x3cc8
        SRD              R3, 2   # 0x3ccc
        C_ADD            R15, R3   # 0x3cce
        SZ_GLOBAL_ST_16  R1, R8, R10, 0, 0   # 0x3cd0
        ADDI             R1, R15, -1   # 0x3cd4
        MOVI             R2, 65388   # 0x3cd8
        MOVI             R3, 65535   # 0x3cdc
        CALL             R14, 128739   # 0x3ce0
        MOVI             R15, 2   # 0x3ce4
        LD_GLOBAL        R15, R15, 24   # 0x3ce8
        SRD              R3, 2   # 0x3cec
        C_ADD            R15, R3   # 0x3cee
        SZ_GLOBAL_LD_U16 R2, R8, R10, 0, 0   # 0x3cf0
        CALL             R14, 128420   # 0x3cf4
        MOVI             R15, 2   # 0x3cf8
        LD_GLOBAL        R15, R15, 24   # 0x3cfc
        SRD              R3, 2   # 0x3d00
        C_ADD            R15, R3   # 0x3d02
        ADDI             R0, R11, 98   # 0x3d04
        C_MOV            R13, R1   # 0x3d08
        C_CHWIDTH        R13, 1   # 0x3d0a
        SZ_GLOBAL_ST_16  R13, R8, R0, 0, 0   # 0x3d0c
        SZ_GLOBAL_ST_16  R13, R8, R10, 0, 0   # 0x3d10
        C_CHWIDTH        R13, 0   # 0x3d14
        LD_GLOBAL        R0, R15, -104   # 0x3d16
        SETP_LT_U_NPI    P0, R0, R0, 2   # 0x3d1a
        C_MOV            R14, R13   # 0x3d1e
        BRA_PRED         0, L3dbc   # 0x3d20
        MOVI             R0, 65388   # 0x3d24
        ADDI             R10, R0, 96   # 0x3d28
L3d2c:  C_CHWIDTH        R14, 0   # 0x3d2c
        ADDI             R8, R15, -1   # 0x3d2e
        C_MOV            R1, R8   # 0x3d32
        MOVI             R2, 65388   # 0x3d34
        MOVI             R3, 1   # 0x3d38
        CALL             R14, 128693   # 0x3d3c
        MOVI             R15, 2   # 0x3d40
        LD_GLOBAL        R15, R15, 24   # 0x3d44
        SRD              R3, 2   # 0x3d48
        C_ADD            R15, R3   # 0x3d4a
        SZ_GLOBAL_LD_U16 R2, R8, R10, 0, 0   # 0x3d4c
        CALL             R14, 128374   # 0x3d50
        MOVI             R15, 2   # 0x3d54
        LD_GLOBAL        R15, R15, 24   # 0x3d58
        SRD              R3, 2   # 0x3d5c
        C_ADD            R15, R3   # 0x3d5e
        SZ_GLOBAL_ST_16  R1, R8, R10, 0, 0   # 0x3d60
        ADDI             R1, R15, -1   # 0x3d64
        MOVI             R2, 65388   # 0x3d68
        MOVI             R3, 65535   # 0x3d6c
        CALL             R14, 128667   # 0x3d70
        MOVI             R15, 2   # 0x3d74
        LD_GLOBAL        R15, R15, 24   # 0x3d78
        SRD              R3, 2   # 0x3d7c
        C_ADD            R15, R3   # 0x3d7e
        SZ_GLOBAL_LD_U16 R2, R8, R10, 0, 0   # 0x3d80
        CALL             R14, 128348   # 0x3d84
        MOVI             R15, 2   # 0x3d88
        LD_GLOBAL        R15, R15, 24   # 0x3d8c
        SRD              R3, 2   # 0x3d90
        C_ADD            R15, R3   # 0x3d92
        C_MOV            R14, R1   # 0x3d94
        C_CHWIDTH        R14, 1   # 0x3d96
        SZ_GLOBAL_ST_16  R14, R8, R10, 0, 0   # 0x3d98
        C_ADDI           R9, 1   # 0x3d9c
        LD_GLOBAL        R0, R15, -104   # 0x3d9e
        SETP_LT_U_NP     P0, R0, R9, R0   # 0x3da2
        BRA_PRED         0, L3d2c   # 0x3da6
        C_CHWIDTH        R13, 1   # 0x3daa
        MOVI             R0, 65388   # 0x3dac
        ADDI             R0, R0, 98   # 0x3db0
        ADDI             R1, R15, -1   # 0x3db4
        SZ_GLOBAL_LD_U16 R13, R1, R0, 0, 0   # 0x3db8
L3dbc:  CHWIDTH_MULTI    30720, 1   # 0x3dbc
        ADDI             R0, R15, -1   # 0x3dc0
        MOVI             R1, 65388   # 0x3dc4
        ADDI             R2, R1, 102   # 0x3dc8
        SZ_GLOBAL_LD_U16 R11, R0, R2, 0, 0   # 0x3dcc
        ADDI             R1, R1, 100   # 0x3dd0
        SZ_GLOBAL_LD_U16 R12, R0, R1, 0, 0   # 0x3dd4
L3dd8:  LD_LOCAL         R1, 220   # 0x3dd8
        C_SHLI           R1, 3   # 0x3ddc
        LD_LOCAL         R0, 228   # 0x3dde
        C_ADD            R0, R1   # 0x3de2
        LD_LOCAL         R2, 224   # 0x3de4
        SZ_GLOBAL_ST_16  R14, R2, R0, 0, 0   # 0x3de8
        ADDI             R1, R0, 2   # 0x3dec
        SZ_GLOBAL_ST_16  R13, R2, R1, 0, 0   # 0x3df0
        ADDI             R1, R0, 4   # 0x3df4
        SZ_GLOBAL_ST_16  R12, R2, R1, 0, 0   # 0x3df8
        C_ADDI           R0, 6   # 0x3dfc
        SZ_GLOBAL_ST_16  R11, R2, R0, 0, 0   # 0x3dfe
        C_EXIT           0   # 0x3e02
