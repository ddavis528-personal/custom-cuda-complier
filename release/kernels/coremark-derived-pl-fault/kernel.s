# coremark-derived-pl-fault: test/coremark-derived -DCCV_SEED_PER_LANE, compiled with
# -ccv-test-i16-legal so that it FAULTS (O-81's negative kernel); ccv-as
# source, reassembled byte for byte by tools/ccv-dis.py --check. Load at
# ccv-sim's -code-base (0x1000); the kernel's entry is 0x3a8e.
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
        SRD              R0, 3   # 0x1274
        C_ADD            R15, R0   # 0x1276
        ST_LOCAL         R8, 64   # 0x1278
        ST_LOCAL         R9, 68   # 0x127c
        ST_LOCAL         R10, 72   # 0x1280
        ST_LOCAL         R11, 76   # 0x1284
        ST_LOCAL         R12, 80   # 0x1288
        ST_LOCAL         R13, 84   # 0x128c
        ST_LOCAL         R14, 44   # 0x1290
        ST_LOCAL         R5, 52   # 0x1294
        C_MOV            R13, R3   # 0x1298
        C_MOV            R0, R2   # 0x129a
        C_CHWIDTH        R2, 1   # 0x129c
        ST_LOCAL         R1, 36   # 0x129e
        MOVI             R1, 32   # 0x12a2
        SZ_GLOBAL_LD_U16 R2, R15, R1, 0, 0   # 0x12a6
        C_CHWIDTH        R2, 0   # 0x12aa
        ST_LOCAL         R2, 48   # 0x12ac
        MOVI             R9, 0   # 0x12b0
        ST_GLOBAL        R9, R15, 28   # 0x12b4
        ST_GLOBAL        R9, R15, 24   # 0x12b8
        ST_GLOBAL        R9, R15, 20   # 0x12bc
        ST_GLOBAL        R9, R15, 16   # 0x12c0
        ST_GLOBAL        R9, R15, 12   # 0x12c4
        ST_GLOBAL        R9, R15, 8   # 0x12c8
        ST_GLOBAL        R9, R15, 4   # 0x12cc
        C_ST_GLOBAL      R9, R15   # 0x12d0
        SZ_GLOBAL_LD_U8  R1, R0, R13, 0, 0   # 0x12d2
        C_MOV            R8, R1   # 0x12d6
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x12d8
        MOVI             R1, 0   # 0x12dc
        ST_LOCAL         R1, 20   # 0x12e0
        ST_LOCAL         R1, 24   # 0x12e4
        ST_LOCAL         R1, 16   # 0x12e8
        ST_LOCAL         R1, 12   # 0x12ec
        ST_LOCAL         R1, 32   # 0x12f0
        ST_LOCAL         R1, 28   # 0x12f4
        BRA_PRED         0, L1566   # 0x12f8
        ST_LOCAL         R6, 60   # 0x12fc
        ST_LOCAL         R4, 56   # 0x1300
        MOVI             R1, 255   # 0x1304
        C_MOV            R14, R1   # 0x1308
        MOVI             R7, 3   # 0x130a
        MOVI             R10, 245   # 0x130e
        MOVI             R2, 5   # 0x1312
        MOVI             R1, 223   # 0x1316
        C_MOV            R6, R1   # 0x131a
        ST_LOCAL         R6, 40   # 0x131c
        MOVI             R1, 0   # 0x1320
        ST_LOCAL         R1, 20   # 0x1324
        ST_LOCAL         R1, 24   # 0x1328
        ST_LOCAL         R1, 16   # 0x132c
        ST_LOCAL         R1, 12   # 0x1330
        ST_LOCAL         R1, 32   # 0x1334
        ST_LOCAL         R1, 28   # 0x1338
        C_MOV            R6, R8   # 0x133c
        MOVI             R11, 0   # 0x133e
        C_MOV            R3, R13   # 0x1342
        C_BRA            L134a   # 0x1344
L1346:  C_MOV            R6, R3   # 0x1346
        C_MOV            R3, R4   # 0x1348
L134a:  C_CHWIDTH        R5, 1   # 0x134a
        AND              R5, R6, R14, R6   # 0x134c
        C_CHWIDTH        R5, 0   # 0x1350
        SETP_NE_NPI      P0, R4, R5, 44   # 0x1352
        ADDI             R4, R3, 1   # 0x1356
        BRA_PRED         0, L137e   # 0x135a
L135e:  C_CHWIDTH        R6, 0   # 0x135e
        LD_GLOBAL_IDX    R3, R15, R11, 1, 0   # 0x1360
        C_ADDI           R3, 1   # 0x1364
        ST_GLOBAL_IDX    R3, R15, R11, 1, 0   # 0x1366
        SZ_GLOBAL_LD_U8  R3, R0, R4, 0, 0   # 0x136a
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x136e
        BRA_PRED         0, L155e   # 0x1372
        C_CHWIDTH        R6, 0   # 0x1376
        MOVI             R11, 0   # 0x1378
        C_BRA            L1346   # 0x137c
L137e:  SETP_LT_NP       P0, R12, R7, R11   # 0x137e
        BRA_PRED         4, L13ba   # 0x1382
        SETP_LT_NP       P0, R12, R2, R11   # 0x1386
        BRA_PRED         0, L13ea   # 0x138a
        SETP_EQ_NPI      P0, R12, R11, 4   # 0x138e
        BRA_PRED         0, L1460   # 0x1392
        SETP_EQ_NPI      P0, R5, R11, 5   # 0x1396
        BRA_PRED         4, L1544   # 0x139a
        LD_LOCAL         R5, 40   # 0x139e
        C_CHWIDTH        R5, 1   # 0x13a2
        AND              R5, R6, R5, R6   # 0x13a4
        C_CHWIDTH        R5, 0   # 0x13a8
        SETP_NE_NPI      P0, R5, R5, 69   # 0x13aa
        BRA_PRED         0, L14e6   # 0x13ae
        MOVI             R11, 3   # 0x13b2
        BRA              L1504   # 0x13b6
L13ba:  SETP_EQ_NPI      P0, R12, R11, 0   # 0x13ba
        BRA_PRED         0, L1426   # 0x13be
        SETP_EQ_NPI      P0, R12, R11, 2   # 0x13c2
        BRA_PRED         0, L1496   # 0x13c6
        SETP_EQ_NPI      P0, R6, R11, 3   # 0x13ca
        BRA_PRED         4, L1544   # 0x13ce
        SETP_EQ_NPI      P0, R6, R5, 45   # 0x13d2
        BRA_PRED         0, L13e2   # 0x13d6
        SETP_NE_NPI      P0, R5, R5, 43   # 0x13da
        BRA_PRED         0, L1520   # 0x13de
L13e2:  MOVI             R11, 6   # 0x13e2
        BRA              L1524   # 0x13e6
L13ea:  SETP_EQ_NPI      P0, R5, R11, 6   # 0x13ea
        BRA_PRED         0, L146e   # 0x13ee
        SETP_EQ_NPI      P0, R5, R11, 7   # 0x13f2
        BRA_PRED         4, L1544   # 0x13f6
        CHWIDTH_MULTI    96, 1   # 0x13fa
        ADDI             R6, R6, -58   # 0x13fe
        AND              R5, R6, R14, R6   # 0x1402
        C_CHWIDTH        R5, 0   # 0x1406
        SETP_LT_U_NP     P0, R5, R10, R5   # 0x1408
        MOVI             R11, 7   # 0x140c
        BRA_PRED         0, L1544   # 0x1410
        MOVI             R11, 1   # 0x1414
        LD_LOCAL         R5, 32   # 0x1418
        C_ADDI           R5, 1   # 0x141c
        ST_LOCAL         R5, 32   # 0x141e
        BRA              L1544   # 0x1422
L1426:  C_CHWIDTH        R6, 1   # 0x1426
        ADDI             R6, R6, -58   # 0x1428
        AND              R6, R6, R14, R6   # 0x142c
        C_CHWIDTH        R6, 0   # 0x1430
        SETP_LT_U_NP     P0, R6, R10, R6   # 0x1432
        MOVI             R11, 4   # 0x1436
        BRA_PRED         0, L153e   # 0x143a
        MOVI             R11, 2   # 0x143e
        SETP_EQ_NPI      P0, R6, R5, 43   # 0x1442
        BRA_PRED         0, L153e   # 0x1446
        SETP_EQ_NPI      P0, R6, R5, 45   # 0x144a
        BRA_PRED         0, L153e   # 0x144e
        SETP_NE_NPI      P0, R5, R5, 46   # 0x1452
        BRA_PRED         0, L1530   # 0x1456
        MOVI             R11, 5   # 0x145a
        C_BRA            L153e   # 0x145e
L1460:  SETP_NE_NPI      P0, R5, R5, 46   # 0x1460
        BRA_PRED         0, L14bc   # 0x1464
        MOVI             R11, 5   # 0x1468
        C_BRA            L14da   # 0x146c
L146e:  CHWIDTH_MULTI    96, 1   # 0x146e
        ADDI             R6, R6, -58   # 0x1472
        AND              R5, R6, R14, R6   # 0x1476
        CHWIDTH_MULTI    96, 0   # 0x147a
        MOVI             R6, 246   # 0x147e
        SETP_LT_U_NP     P0, R5, R5, R6   # 0x1482
        MOVI             R11, 7   # 0x1486
        MOVI             R5, 1   # 0x148a
        MOV_P            R11, 0, R5, R5, R5   # 0x148e
        C_ADDI           R9, 1   # 0x1492
        C_BRA            L1544   # 0x1494
L1496:  C_CHWIDTH        R6, 1   # 0x1496
        ADDI             R6, R6, -58   # 0x1498
        AND              R6, R6, R14, R6   # 0x149c
        C_CHWIDTH        R6, 0   # 0x14a0
        MOVI             R11, 246   # 0x14a2
        SETP_LT_U_NP     P0, R6, R6, R11   # 0x14a6
        BRA_PRED         4, L1510   # 0x14aa
        SETP_EQ_NPI      P0, R5, R5, 46   # 0x14ae
        MOVI             R11, 1   # 0x14b2
        MOV_P            R11, 0, R2, R2, R2   # 0x14b6
        C_BRA            L1514   # 0x14ba
L14bc:  CHWIDTH_MULTI    96, 1   # 0x14bc
        ADDI             R6, R6, -58   # 0x14c0
        AND              R5, R6, R14, R6   # 0x14c4
        C_CHWIDTH        R5, 0   # 0x14c8
        SETP_LT_U_NP     P0, R5, R10, R5   # 0x14ca
        MOVI             R11, 4   # 0x14ce
        BRA_PRED         0, L1544   # 0x14d2
        MOVI             R11, 1   # 0x14d6
L14da:  LD_LOCAL         R5, 24   # 0x14da
        C_ADDI           R5, 1   # 0x14de
        ST_LOCAL         R5, 24   # 0x14e0
        C_BRA            L1544   # 0x14e4
L14e6:  CHWIDTH_MULTI    96, 1   # 0x14e6
        ADDI             R6, R6, -58   # 0x14ea
        AND              R5, R6, R14, R6   # 0x14ee
        C_CHWIDTH        R5, 0   # 0x14f2
        SETP_LT_U_NP     P0, R5, R10, R5   # 0x14f4
        MOVI             R11, 5   # 0x14f8
        BRA_PRED         0, L1544   # 0x14fc
        MOVI             R11, 1   # 0x1500
L1504:  LD_LOCAL         R5, 20   # 0x1504
        C_ADDI           R5, 1   # 0x1508
        ST_LOCAL         R5, 20   # 0x150a
        C_BRA            L1544   # 0x150e
L1510:  MOVI             R11, 4   # 0x1510
L1514:  LD_LOCAL         R5, 12   # 0x1514
        C_ADDI           R5, 1   # 0x1518
        ST_LOCAL         R5, 12   # 0x151a
        C_BRA            L1544   # 0x151e
L1520:  MOVI             R11, 1   # 0x1520
L1524:  LD_LOCAL         R5, 16   # 0x1524
        C_ADDI           R5, 1   # 0x1528
        ST_LOCAL         R5, 16   # 0x152a
        C_BRA            L1544   # 0x152e
L1530:  MOVI             R11, 1   # 0x1530
        LD_LOCAL         R5, 32   # 0x1534
        C_ADDI           R5, 1   # 0x1538
        ST_LOCAL         R5, 32   # 0x153a
L153e:  C_ADDI           R1, 1   # 0x153e
        ST_LOCAL         R1, 28   # 0x1540
L1544:  SZ_GLOBAL_LD_U8  R3, R0, R3, 0, 1   # 0x1544
        SETP_EQ_NPI      P0, R5, R3, 0   # 0x1548
        BRA_PRED         0, L135e   # 0x154c
        C_CHWIDTH        R6, 0   # 0x1550
        SETP_EQ_NPI      P0, R5, R11, 1   # 0x1552
        BRA_PRED         4, L1346   # 0x1556
        BRA              L135e   # 0x155a
L155e:  LD_LOCAL         R4, 56   # 0x155e
        LD_LOCAL         R6, 60   # 0x1562
L1566:  C_CHWIDTH        R6, 1   # 0x1566
        LD_LOCAL         R2, 36   # 0x1568
        SETP_EQ_NPI      P0, R1, R2, 0   # 0x156c
        SHLI             R7, R0, 16   # 0x1570
        CVT_SEXT         R14, R6, R6, R6   # 0x1574
        ADD              R10, R13, R2, R13   # 0x1578
        SHRI             R11, R0, 16   # 0x157c
        BRA_PRED         0, L160a   # 0x1580
        C_CHWIDTH        R6, 0   # 0x1584
        C_MOV            R6, R4   # 0x1586
        ADD              R2, R13, R7, R13   # 0x1588
        ADD              R1, R14, R7, R14   # 0x158c
        C_ADD            R2, R14   # 0x1590
        C_NOT            R2, R2   # 0x1592
        C_MOV            R4, R13   # 0x1594
L1596:  SZ_GLOBAL_LD_U8  R3, R0, R4, 0, 0   # 0x1596
        SETP_EQ_NPI      P0, R5, R3, 44   # 0x159a
        BRA_PRED         0, L15ae   # 0x159e
        C_CHWIDTH        R3, 1   # 0x15a2
        XOR              R3, R3, R6, R3   # 0x15a4
        C_CHWIDTH        R3, 0   # 0x15a8
        SZ_GLOBAL_ST_8   R3, R0, R4, 0, 0   # 0x15aa
L15ae:  ADD              R3, R14, R4, R14   # 0x15ae
        OR               R5, R7, R3, R7   # 0x15b2
        C_AND            R5, R2   # 0x15b6
        AND              R8, R7, R3, R7   # 0x15b8
        OR               R5, R8, R5, R8   # 0x15bc
        ADD              R4, R1, R4, R1   # 0x15c0
        ADD              R8, R7, R10, R7   # 0x15c4
        SETP_LT_U_NP     P0, R4, R4, R8   # 0x15c8
        OR               R4, R7, R10, R7   # 0x15cc
        C_ANDN           R4, R8   # 0x15d0
        AND              R8, R7, R10, R7   # 0x15d2
        OR               R4, R8, R4, R8   # 0x15d6
        SHRI             R4, R4, 31   # 0x15da
        SHRI             R5, R5, 31   # 0x15de
        SETP_EQ_NP       P1, R8, R5, R4   # 0x15e2
        ADD              R4, R11, R4, R11   # 0x15e6
        ADD              R5, R11, R5, R11   # 0x15ea
        SETP_LT_U_NP     P2, R4, R5, R4   # 0x15ee
        C_SUB            R2, R14   # 0x15f2
        C_MOV            R4, R3   # 0x15f4
        BRA_PRED         2, L1596   # 0x15f6
        PAND             P0, 1, 0   # 0x15fa
        C_MOV            R4, R3   # 0x15fc
        BRA_PRED         0, L1596   # 0x15fe
        C_CHWIDTH        R8, 1   # 0x1602
        SZ_GLOBAL_LD_U8  R8, R0, R13, 0, 0   # 0x1604
        C_CHWIDTH        R8, 0   # 0x1608
L160a:  C_CHWIDTH        R6, 0   # 0x160a
        SETP_EQ_NPI      P0, R1, R8, 0   # 0x160c
        BRA_PRED         0, L1864   # 0x1610
        MOVI             R1, 0   # 0x1614
        MOVI             R2, 255   # 0x1618
        C_MOV            R4, R2   # 0x161c
        MOVI             R12, 3   # 0x161e
        MOVI             R3, 223   # 0x1622
        C_MOV            R6, R3   # 0x1626
        ST_LOCAL         R6, 40   # 0x1628
        C_MOV            R3, R13   # 0x162c
        C_BRA            L1634   # 0x162e
L1630:  C_MOV            R8, R3   # 0x1630
        C_MOV            R3, R5   # 0x1632
L1634:  C_CHWIDTH        R6, 1   # 0x1634
        AND              R6, R8, R4, R8   # 0x1636
        C_CHWIDTH        R6, 0   # 0x163a
        SETP_NE_NPI      P0, R5, R6, 44   # 0x163c
        ADDI             R5, R3, 1   # 0x1640
        BRA_PRED         0, L1664   # 0x1644
L1648:  LD_GLOBAL_IDX    R2, R15, R1, 1, 0   # 0x1648
        C_ADDI           R2, 1   # 0x164c
        ST_GLOBAL_IDX    R2, R15, R1, 1, 0   # 0x164e
        SZ_GLOBAL_LD_U8  R3, R0, R5, 0, 0   # 0x1652
        SETP_EQ_NPI      P0, R1, R3, 0   # 0x1656
        BRA_PRED         0, L1864   # 0x165a
        MOVI             R1, 0   # 0x165e
        C_BRA            L1630   # 0x1662
L1664:  SETP_LT_NP       P0, R2, R12, R1   # 0x1664
        BRA_PRED         4, L16a4   # 0x1668
        MOVI             R2, 5   # 0x166c
        SETP_LT_NP       P0, R2, R2, R1   # 0x1670
        BRA_PRED         0, L16d4   # 0x1674
        SETP_EQ_NPI      P0, R2, R1, 4   # 0x1678
        BRA_PRED         0, L1756   # 0x167c
        SETP_EQ_NPI      P0, R2, R1, 5   # 0x1680
        BRA_PRED         4, L184c   # 0x1684
        C_CHWIDTH        R1, 1   # 0x1688
        LD_LOCAL         R6, 40   # 0x168a
        AND              R1, R8, R6, R8   # 0x168e
        C_CHWIDTH        R1, 0   # 0x1692
        SETP_NE_NPI      P0, R1, R1, 69   # 0x1694
        BRA_PRED         0, L17e6   # 0x1698
        MOVI             R1, 3   # 0x169c
        BRA              L1808   # 0x16a0
L16a4:  SETP_EQ_NPI      P0, R2, R1, 0   # 0x16a4
        BRA_PRED         0, L1714   # 0x16a8
        SETP_EQ_NPI      P0, R2, R1, 2   # 0x16ac
        BRA_PRED         0, L178a   # 0x16b0
        SETP_EQ_NPI      P0, R2, R1, 3   # 0x16b4
        BRA_PRED         4, L184c   # 0x16b8
        SETP_EQ_NPI      P0, R1, R6, 45   # 0x16bc
        BRA_PRED         0, L16cc   # 0x16c0
        SETP_NE_NPI      P0, R1, R6, 43   # 0x16c4
        BRA_PRED         0, L1824   # 0x16c8
L16cc:  MOVI             R1, 6   # 0x16cc
        BRA              L1828   # 0x16d0
L16d4:  SETP_EQ_NPI      P0, R2, R1, 6   # 0x16d4
        BRA_PRED         0, L1764   # 0x16d8
        SETP_EQ_NPI      P0, R2, R1, 7   # 0x16dc
        BRA_PRED         4, L184c   # 0x16e0
        CHWIDTH_MULTI    66, 1   # 0x16e4
        ADDI             R6, R8, -58   # 0x16e8
        AND              R1, R6, R4, R6   # 0x16ec
        C_CHWIDTH        R1, 0   # 0x16f0
        MOVI             R2, 245   # 0x16f2
        SETP_LT_U_NP     P0, R1, R2, R1   # 0x16f6
        MOVI             R1, 7   # 0x16fa
        BRA_PRED         0, L184c   # 0x16fe
        MOVI             R1, 1   # 0x1702
        LD_LOCAL         R2, 32   # 0x1706
        C_ADDI           R2, 1   # 0x170a
        ST_LOCAL         R2, 32   # 0x170c
        BRA              L184c   # 0x1710
L1714:  CHWIDTH_MULTI    6, 1   # 0x1714
        ADDI             R2, R8, -58   # 0x1718
        AND              R1, R2, R4, R2   # 0x171c
        CHWIDTH_MULTI    6, 0   # 0x1720
        MOVI             R2, 245   # 0x1724
        SETP_LT_U_NP     P0, R1, R2, R1   # 0x1728
        MOVI             R1, 4   # 0x172c
        BRA_PRED         0, L1842   # 0x1730
        MOVI             R1, 2   # 0x1734
        SETP_EQ_NPI      P0, R2, R6, 43   # 0x1738
        BRA_PRED         0, L1842   # 0x173c
        SETP_EQ_NPI      P0, R2, R6, 45   # 0x1740
        BRA_PRED         0, L1842   # 0x1744
        SETP_NE_NPI      P0, R1, R6, 46   # 0x1748
        BRA_PRED         0, L1834   # 0x174c
        MOVI             R1, 5   # 0x1750
        C_BRA            L1842   # 0x1754
L1756:  SETP_NE_NPI      P0, R1, R6, 46   # 0x1756
        BRA_PRED         0, L17b8   # 0x175a
        MOVI             R1, 5   # 0x175e
        C_BRA            L17da   # 0x1762
L1764:  CHWIDTH_MULTI    66, 1   # 0x1764
        ADDI             R6, R8, -58   # 0x1768
        AND              R1, R6, R4, R6   # 0x176c
        C_CHWIDTH        R1, 0   # 0x1770
        MOVI             R2, 246   # 0x1772
        SETP_LT_U_NP     P0, R1, R1, R2   # 0x1776
        MOVI             R1, 7   # 0x177a
        MOVI             R2, 1   # 0x177e
        MOV_P            R1, 0, R2, R2, R2   # 0x1782
        C_ADDI           R9, 1   # 0x1786
        C_BRA            L184c   # 0x1788
L178a:  CHWIDTH_MULTI    6, 1   # 0x178a
        ADDI             R2, R8, -58   # 0x178e
        AND              R1, R2, R4, R2   # 0x1792
        CHWIDTH_MULTI    6, 0   # 0x1796
        MOVI             R2, 246   # 0x179a
        SETP_LT_U_NP     P0, R1, R1, R2   # 0x179e
        BRA_PRED         4, L1814   # 0x17a2
        SETP_EQ_NPI      P0, R1, R6, 46   # 0x17a6
        MOVI             R1, 1   # 0x17aa
        MOVI             R2, 5   # 0x17ae
        MOV_P            R1, 0, R2, R2, R2   # 0x17b2
        C_BRA            L1818   # 0x17b6
L17b8:  CHWIDTH_MULTI    66, 1   # 0x17b8
        ADDI             R6, R8, -58   # 0x17bc
        AND              R1, R6, R4, R6   # 0x17c0
        C_CHWIDTH        R1, 0   # 0x17c4
        MOVI             R2, 245   # 0x17c6
        SETP_LT_U_NP     P0, R1, R2, R1   # 0x17ca
        MOVI             R1, 4   # 0x17ce
        BRA_PRED         0, L184c   # 0x17d2
        MOVI             R1, 1   # 0x17d6
L17da:  LD_LOCAL         R2, 24   # 0x17da
        C_ADDI           R2, 1   # 0x17de
        ST_LOCAL         R2, 24   # 0x17e0
        C_BRA            L184c   # 0x17e4
L17e6:  CHWIDTH_MULTI    66, 1   # 0x17e6
        ADDI             R6, R8, -58   # 0x17ea
        AND              R1, R6, R4, R6   # 0x17ee
        C_CHWIDTH        R1, 0   # 0x17f2
        MOVI             R2, 245   # 0x17f4
        SETP_LT_U_NP     P0, R1, R2, R1   # 0x17f8
        MOVI             R1, 5   # 0x17fc
        BRA_PRED         0, L184c   # 0x1800
        MOVI             R1, 1   # 0x1804
L1808:  LD_LOCAL         R2, 20   # 0x1808
        C_ADDI           R2, 1   # 0x180c
        ST_LOCAL         R2, 20   # 0x180e
        C_BRA            L184c   # 0x1812
L1814:  MOVI             R1, 4   # 0x1814
L1818:  LD_LOCAL         R2, 12   # 0x1818
        C_ADDI           R2, 1   # 0x181c
        ST_LOCAL         R2, 12   # 0x181e
        C_BRA            L184c   # 0x1822
L1824:  MOVI             R1, 1   # 0x1824
L1828:  LD_LOCAL         R2, 16   # 0x1828
        C_ADDI           R2, 1   # 0x182c
        ST_LOCAL         R2, 16   # 0x182e
        C_BRA            L184c   # 0x1832
L1834:  MOVI             R1, 1   # 0x1834
        LD_LOCAL         R2, 32   # 0x1838
        C_ADDI           R2, 1   # 0x183c
        ST_LOCAL         R2, 32   # 0x183e
L1842:  LD_LOCAL         R2, 28   # 0x1842
        C_ADDI           R2, 1   # 0x1846
        ST_LOCAL         R2, 28   # 0x1848
L184c:  SZ_GLOBAL_LD_U8  R3, R0, R3, 0, 1   # 0x184c
        SETP_EQ_NPI      P0, R2, R3, 0   # 0x1850
        BRA_PRED         0, L1648   # 0x1854
        SETP_EQ_NPI      P0, R2, R1, 1   # 0x1858
        BRA_PRED         4, L1630   # 0x185c
        BRA              L1648   # 0x1860
L1864:  C_CHWIDTH        R6, 0   # 0x1864
        LD_LOCAL         R1, 36   # 0x1866
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x186a
        BRA_PRED         0, L18f0   # 0x186e
        LD_LOCAL         R1, 52   # 0x1872
        C_MOV            R6, R1   # 0x1876
        ADD              R2, R13, R7, R13   # 0x1878
        ADD              R1, R14, R7, R14   # 0x187c
        C_ADD            R2, R14   # 0x1880
        C_NOT            R2, R2   # 0x1882
L1884:  SZ_GLOBAL_LD_U8  R3, R0, R13, 0, 0   # 0x1884
        SETP_EQ_NPI      P0, R4, R3, 44   # 0x1888
        BRA_PRED         0, L189c   # 0x188c
        C_CHWIDTH        R3, 1   # 0x1890
        XOR              R3, R3, R6, R3   # 0x1892
        C_CHWIDTH        R3, 0   # 0x1896
        SZ_GLOBAL_ST_8   R3, R0, R13, 0, 0   # 0x1898
L189c:  ADD              R3, R14, R13, R14   # 0x189c
        OR               R4, R7, R3, R7   # 0x18a0
        C_AND            R4, R2   # 0x18a4
        AND              R5, R7, R3, R7   # 0x18a6
        OR               R4, R5, R4, R5   # 0x18aa
        ADD              R5, R1, R13, R1   # 0x18ae
        ADD              R8, R7, R10, R7   # 0x18b2
        SETP_LT_U_NP     P0, R5, R5, R8   # 0x18b6
        OR               R5, R7, R10, R7   # 0x18ba
        C_ANDN           R5, R8   # 0x18be
        AND              R8, R7, R10, R7   # 0x18c0
        OR               R5, R8, R5, R8   # 0x18c4
        SHRI             R5, R5, 31   # 0x18c8
        SHRI             R4, R4, 31   # 0x18cc
        SETP_EQ_NP       P1, R8, R4, R5   # 0x18d0
        ADD              R5, R11, R5, R11   # 0x18d4
        ADD              R4, R11, R4, R11   # 0x18d8
        SETP_LT_U_NP     P2, R4, R4, R5   # 0x18dc
        C_SUB            R2, R14   # 0x18e0
        C_MOV            R13, R3   # 0x18e2
        BRA_PRED         2, L1884   # 0x18e4
        PAND             P0, 1, 0   # 0x18e8
        C_MOV            R13, R3   # 0x18ea
        BRA_PRED         0, L1884   # 0x18ec
L18f0:  C_LD_GLOBAL      R1, R15   # 0x18f0
        LD_LOCAL         R2, 48   # 0x18f2
        CALL             R14, 129656   # 0x18f6
        MOVI             R15, 2   # 0x18fa
        LD_GLOBAL        R15, R15, 24   # 0x18fe
        SRD              R3, 3   # 0x1902
        C_ADD            R15, R3   # 0x1904
        C_MOV            R2, R1   # 0x1906
        LD_LOCAL         R1, 28   # 0x1908
        CALL             R14, 129645   # 0x190c
        MOVI             R15, 2   # 0x1910
        LD_GLOBAL        R15, R15, 24   # 0x1914
        SRD              R3, 3   # 0x1918
        C_ADD            R15, R3   # 0x191a
        C_MOV            R2, R1   # 0x191c
        LD_GLOBAL        R1, R15, 4   # 0x191e
        CALL             R14, 129634   # 0x1922
        MOVI             R15, 2   # 0x1926
        LD_GLOBAL        R15, R15, 24   # 0x192a
        SRD              R3, 3   # 0x192e
        C_ADD            R15, R3   # 0x1930
        C_MOV            R2, R1   # 0x1932
        LD_LOCAL         R1, 32   # 0x1934
        CALL             R14, 129623   # 0x1938
        MOVI             R15, 2   # 0x193c
        LD_GLOBAL        R15, R15, 24   # 0x1940
        SRD              R3, 3   # 0x1944
        C_ADD            R15, R3   # 0x1946
        C_MOV            R2, R1   # 0x1948
        LD_GLOBAL        R1, R15, 8   # 0x194a
        CALL             R14, 129612   # 0x194e
        MOVI             R15, 2   # 0x1952
        LD_GLOBAL        R15, R15, 24   # 0x1956
        SRD              R3, 3   # 0x195a
        C_ADD            R15, R3   # 0x195c
        C_MOV            R2, R1   # 0x195e
        LD_LOCAL         R1, 12   # 0x1960
        CALL             R14, 129601   # 0x1964
        MOVI             R15, 2   # 0x1968
        LD_GLOBAL        R15, R15, 24   # 0x196c
        SRD              R3, 3   # 0x1970
        C_ADD            R15, R3   # 0x1972
        C_MOV            R2, R1   # 0x1974
        LD_GLOBAL        R1, R15, 12   # 0x1976
        CALL             R14, 129590   # 0x197a
        MOVI             R15, 2   # 0x197e
        LD_GLOBAL        R15, R15, 24   # 0x1982
        SRD              R3, 3   # 0x1986
        C_ADD            R15, R3   # 0x1988
        C_MOV            R2, R1   # 0x198a
        LD_LOCAL         R1, 16   # 0x198c
        CALL             R14, 129579   # 0x1990
        MOVI             R15, 2   # 0x1994
        LD_GLOBAL        R15, R15, 24   # 0x1998
        SRD              R3, 3   # 0x199c
        C_ADD            R15, R3   # 0x199e
        C_MOV            R2, R1   # 0x19a0
        LD_GLOBAL        R1, R15, 16   # 0x19a2
        CALL             R14, 129568   # 0x19a6
        MOVI             R15, 2   # 0x19aa
        LD_GLOBAL        R15, R15, 24   # 0x19ae
        SRD              R3, 3   # 0x19b2
        C_ADD            R15, R3   # 0x19b4
        C_MOV            R2, R1   # 0x19b6
        LD_LOCAL         R1, 24   # 0x19b8
        CALL             R14, 129557   # 0x19bc
        MOVI             R15, 2   # 0x19c0
        LD_GLOBAL        R15, R15, 24   # 0x19c4
        SRD              R3, 3   # 0x19c8
        C_ADD            R15, R3   # 0x19ca
        C_MOV            R2, R1   # 0x19cc
        LD_GLOBAL        R1, R15, 20   # 0x19ce
        CALL             R14, 129546   # 0x19d2
        MOVI             R15, 2   # 0x19d6
        LD_GLOBAL        R15, R15, 24   # 0x19da
        SRD              R3, 3   # 0x19de
        C_ADD            R15, R3   # 0x19e0
        C_MOV            R2, R1   # 0x19e2
        LD_LOCAL         R1, 20   # 0x19e4
        CALL             R14, 129535   # 0x19e8
        MOVI             R15, 2   # 0x19ec
        LD_GLOBAL        R15, R15, 24   # 0x19f0
        SRD              R3, 3   # 0x19f4
        C_ADD            R15, R3   # 0x19f6
        C_MOV            R2, R1   # 0x19f8
        LD_GLOBAL        R1, R15, 24   # 0x19fa
        CALL             R14, 129524   # 0x19fe
        MOVI             R15, 2   # 0x1a02
        LD_GLOBAL        R15, R15, 24   # 0x1a06
        SRD              R3, 3   # 0x1a0a
        C_ADD            R15, R3   # 0x1a0c
        C_MOV            R2, R1   # 0x1a0e
        C_MOV            R1, R9   # 0x1a10
        CALL             R14, 129514   # 0x1a12
        MOVI             R15, 2   # 0x1a16
        LD_GLOBAL        R15, R15, 24   # 0x1a1a
        SRD              R3, 3   # 0x1a1e
        C_ADD            R15, R3   # 0x1a20
        C_MOV            R2, R1   # 0x1a22
        LD_GLOBAL        R1, R15, 28   # 0x1a24
        CALL             R14, 129503   # 0x1a28
        MOVI             R15, 2   # 0x1a2c
        LD_GLOBAL        R15, R15, 24   # 0x1a30
        SRD              R3, 3   # 0x1a34
        C_ADD            R15, R3   # 0x1a36
        C_MOV            R2, R1   # 0x1a38
        MOVI             R1, 0   # 0x1a3a
        CALL             R14, 129492   # 0x1a3e
        MOVI             R15, 2   # 0x1a42
        LD_GLOBAL        R15, R15, 24   # 0x1a46
        SRD              R3, 3   # 0x1a4a
        C_ADD            R15, R3   # 0x1a4c
        LD_LOCAL         R14, 44   # 0x1a4e
        LD_LOCAL         R13, 84   # 0x1a52
        LD_LOCAL         R12, 80   # 0x1a56
        LD_LOCAL         R11, 76   # 0x1a5a
        LD_LOCAL         R10, 72   # 0x1a5e
        LD_LOCAL         R9, 68   # 0x1a62
        LD_LOCAL         R8, 64   # 0x1a66
        C_RET            224   # 0x1a6a
        CHWIDTH_MULTI    7, 1   # 0x1a6c
        XOR              R0, R2, R1, R2   # 0x1a70
        CHWIDTH_MULTI    7, 0   # 0x1a74
        C_ANDI           R0, 1   # 0x1a78
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1a7a
        MOVI             R0, 40961   # 0x1a7e
        C_MOV            R7, R0   # 0x1a82
        SHRI             R0, R2, 1   # 0x1a84
        C_CHWIDTH        R2, 1   # 0x1a88
        XOR              R2, R0, R7, R0   # 0x1a8a
        C_CHWIDTH        R2, 0   # 0x1a8e
        MOV_P            R0, 0, R2, R2, R2   # 0x1a90
        C_CHWIDTH        R0, 1   # 0x1a94
        SHRI             R2, R1, 1   # 0x1a96
        C_CHWIDTH        R2, 1   # 0x1a9a
        XOR              R2, R2, R0, R2   # 0x1a9c
        CHWIDTH_MULTI    5, 0   # 0x1aa0
        C_ANDI           R2, 1   # 0x1aa4
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1aa6
        C_CHWIDTH        R2, 1   # 0x1aaa
        SHRI             R0, R0, 1   # 0x1aac
        XOR              R2, R0, R7, R0   # 0x1ab0
        C_CHWIDTH        R2, 0   # 0x1ab4
        MOV_P            R0, 0, R2, R2, R2   # 0x1ab6
        C_CHWIDTH        R0, 1   # 0x1aba
        SHRI             R2, R1, 2   # 0x1abc
        C_CHWIDTH        R2, 1   # 0x1ac0
        XOR              R2, R2, R0, R2   # 0x1ac2
        CHWIDTH_MULTI    5, 0   # 0x1ac6
        C_ANDI           R2, 1   # 0x1aca
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1acc
        C_CHWIDTH        R2, 1   # 0x1ad0
        SHRI             R0, R0, 1   # 0x1ad2
        XOR              R2, R0, R7, R0   # 0x1ad6
        C_CHWIDTH        R2, 0   # 0x1ada
        MOV_P            R0, 0, R2, R2, R2   # 0x1adc
        C_CHWIDTH        R0, 1   # 0x1ae0
        SHRI             R2, R1, 3   # 0x1ae2
        C_CHWIDTH        R2, 1   # 0x1ae6
        XOR              R2, R2, R0, R2   # 0x1ae8
        CHWIDTH_MULTI    5, 0   # 0x1aec
        C_ANDI           R2, 1   # 0x1af0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1af2
        C_CHWIDTH        R2, 1   # 0x1af6
        SHRI             R0, R0, 1   # 0x1af8
        XOR              R2, R0, R7, R0   # 0x1afc
        C_CHWIDTH        R2, 0   # 0x1b00
        MOV_P            R0, 0, R2, R2, R2   # 0x1b02
        C_CHWIDTH        R0, 1   # 0x1b06
        SHRI             R2, R1, 4   # 0x1b08
        C_CHWIDTH        R2, 1   # 0x1b0c
        XOR              R2, R2, R0, R2   # 0x1b0e
        CHWIDTH_MULTI    5, 0   # 0x1b12
        C_ANDI           R2, 1   # 0x1b16
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b18
        C_CHWIDTH        R2, 1   # 0x1b1c
        SHRI             R0, R0, 1   # 0x1b1e
        XOR              R2, R0, R7, R0   # 0x1b22
        C_CHWIDTH        R2, 0   # 0x1b26
        MOV_P            R0, 0, R2, R2, R2   # 0x1b28
        C_CHWIDTH        R0, 1   # 0x1b2c
        SHRI             R2, R1, 5   # 0x1b2e
        C_CHWIDTH        R2, 1   # 0x1b32
        XOR              R2, R2, R0, R2   # 0x1b34
        CHWIDTH_MULTI    5, 0   # 0x1b38
        C_ANDI           R2, 1   # 0x1b3c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b3e
        C_CHWIDTH        R2, 1   # 0x1b42
        SHRI             R0, R0, 1   # 0x1b44
        XOR              R2, R0, R7, R0   # 0x1b48
        C_CHWIDTH        R2, 0   # 0x1b4c
        MOV_P            R0, 0, R2, R2, R2   # 0x1b4e
        C_CHWIDTH        R0, 1   # 0x1b52
        SHRI             R2, R1, 6   # 0x1b54
        C_CHWIDTH        R2, 1   # 0x1b58
        XOR              R2, R2, R0, R2   # 0x1b5a
        CHWIDTH_MULTI    5, 0   # 0x1b5e
        C_ANDI           R2, 1   # 0x1b62
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1b64
        C_CHWIDTH        R2, 1   # 0x1b68
        SHRI             R0, R0, 1   # 0x1b6a
        XOR              R2, R0, R7, R0   # 0x1b6e
        C_CHWIDTH        R2, 0   # 0x1b72
        MOV_P            R0, 0, R2, R2, R2   # 0x1b74
        MOVI             R2, 128   # 0x1b78
        C_CHWIDTH        R2, 1   # 0x1b7c
        AND              R2, R1, R2, R1   # 0x1b7e
        C_CHWIDTH        R2, 0   # 0x1b82
        SHRI             R2, R2, 7   # 0x1b84
        ANDI             R3, R0, 1   # 0x1b88
        C_CHWIDTH        R0, 1   # 0x1b8c
        C_CHWIDTH        R0, 0   # 0x1b8e
        SETP_EQ_NP       P0, R2, R2, R3   # 0x1b90
        C_CHWIDTH        R2, 1   # 0x1b94
        SHRI             R0, R0, 1   # 0x1b96
        XOR              R2, R0, R7, R0   # 0x1b9a
        C_CHWIDTH        R2, 0   # 0x1b9e
        MOV_P            R2, 0, R0, R0, R0   # 0x1ba0
        C_CHWIDTH        R2, 1   # 0x1ba4
        SHRI             R0, R1, 8   # 0x1ba6
        C_CHWIDTH        R0, 1   # 0x1baa
        XOR              R0, R2, R0, R2   # 0x1bac
        CHWIDTH_MULTI    5, 0   # 0x1bb0
        C_ANDI           R0, 1   # 0x1bb4
        SETP_NE_NPI      P0, R0, R0, 0   # 0x1bb6
        SHRI             R0, R2, 1   # 0x1bba
        C_CHWIDTH        R2, 1   # 0x1bbe
        XOR              R2, R0, R7, R0   # 0x1bc0
        C_CHWIDTH        R2, 0   # 0x1bc4
        MOV_P            R0, 0, R2, R2, R2   # 0x1bc6
        C_CHWIDTH        R0, 1   # 0x1bca
        SHRI             R2, R1, 9   # 0x1bcc
        C_CHWIDTH        R2, 1   # 0x1bd0
        XOR              R2, R2, R0, R2   # 0x1bd2
        CHWIDTH_MULTI    5, 0   # 0x1bd6
        C_ANDI           R2, 1   # 0x1bda
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1bdc
        C_CHWIDTH        R2, 1   # 0x1be0
        SHRI             R0, R0, 1   # 0x1be2
        XOR              R2, R0, R7, R0   # 0x1be6
        C_CHWIDTH        R2, 0   # 0x1bea
        MOV_P            R0, 0, R2, R2, R2   # 0x1bec
        C_CHWIDTH        R0, 1   # 0x1bf0
        SHRI             R2, R1, 10   # 0x1bf2
        C_CHWIDTH        R2, 1   # 0x1bf6
        XOR              R2, R2, R0, R2   # 0x1bf8
        CHWIDTH_MULTI    5, 0   # 0x1bfc
        C_ANDI           R2, 1   # 0x1c00
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c02
        C_CHWIDTH        R2, 1   # 0x1c06
        SHRI             R0, R0, 1   # 0x1c08
        XOR              R2, R0, R7, R0   # 0x1c0c
        C_CHWIDTH        R2, 0   # 0x1c10
        MOV_P            R0, 0, R2, R2, R2   # 0x1c12
        C_CHWIDTH        R0, 1   # 0x1c16
        SHRI             R2, R1, 11   # 0x1c18
        C_CHWIDTH        R2, 1   # 0x1c1c
        XOR              R2, R2, R0, R2   # 0x1c1e
        CHWIDTH_MULTI    5, 0   # 0x1c22
        C_ANDI           R2, 1   # 0x1c26
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c28
        C_CHWIDTH        R2, 1   # 0x1c2c
        SHRI             R0, R0, 1   # 0x1c2e
        XOR              R2, R0, R7, R0   # 0x1c32
        C_CHWIDTH        R2, 0   # 0x1c36
        MOV_P            R0, 0, R2, R2, R2   # 0x1c38
        C_CHWIDTH        R0, 1   # 0x1c3c
        SHRI             R2, R1, 12   # 0x1c3e
        C_CHWIDTH        R2, 1   # 0x1c42
        XOR              R2, R2, R0, R2   # 0x1c44
        CHWIDTH_MULTI    5, 0   # 0x1c48
        C_ANDI           R2, 1   # 0x1c4c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c4e
        C_CHWIDTH        R2, 1   # 0x1c52
        SHRI             R0, R0, 1   # 0x1c54
        XOR              R2, R0, R7, R0   # 0x1c58
        C_CHWIDTH        R2, 0   # 0x1c5c
        MOV_P            R0, 0, R2, R2, R2   # 0x1c5e
        C_CHWIDTH        R0, 1   # 0x1c62
        SHRI             R2, R1, 13   # 0x1c64
        C_CHWIDTH        R2, 1   # 0x1c68
        XOR              R2, R2, R0, R2   # 0x1c6a
        CHWIDTH_MULTI    5, 0   # 0x1c6e
        C_ANDI           R2, 1   # 0x1c72
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c74
        C_CHWIDTH        R2, 1   # 0x1c78
        SHRI             R0, R0, 1   # 0x1c7a
        XOR              R2, R0, R7, R0   # 0x1c7e
        C_CHWIDTH        R2, 0   # 0x1c82
        MOV_P            R0, 0, R2, R2, R2   # 0x1c84
        C_CHWIDTH        R0, 1   # 0x1c88
        SHRI             R2, R1, 14   # 0x1c8a
        C_CHWIDTH        R2, 1   # 0x1c8e
        XOR              R2, R2, R0, R2   # 0x1c90
        CHWIDTH_MULTI    5, 0   # 0x1c94
        C_ANDI           R2, 1   # 0x1c98
        SETP_NE_NPI      P0, R2, R2, 0   # 0x1c9a
        C_CHWIDTH        R2, 1   # 0x1c9e
        SHRI             R0, R0, 1   # 0x1ca0
        XOR              R2, R0, R7, R0   # 0x1ca4
        C_CHWIDTH        R2, 0   # 0x1ca8
        MOV_P            R0, 0, R2, R2, R2   # 0x1caa
        SHRI             R1, R1, 15   # 0x1cae
        ANDI             R2, R0, 1   # 0x1cb2
        C_CHWIDTH        R0, 1   # 0x1cb6
        C_CHWIDTH        R0, 0   # 0x1cb8
        SETP_EQ_NP       P0, R1, R1, R2   # 0x1cba
        C_CHWIDTH        R1, 1   # 0x1cbe
        SHRI             R0, R0, 1   # 0x1cc0
        XOR              R1, R0, R7, R0   # 0x1cc4
        C_CHWIDTH        R1, 0   # 0x1cc8
        MOV_P            R1, 0, R0, R0, R0   # 0x1cca
        MOVI             R0, 65535   # 0x1cce
        C_AND            R1, R0   # 0x1cd2
        C_RET            224   # 0x1cd4
        ST_LOCAL         R8, 72   # 0x1cd6
        ST_LOCAL         R9, 76   # 0x1cda
        ST_LOCAL         R10, 80   # 0x1cde
        ST_LOCAL         R11, 84   # 0x1ce2
        ST_LOCAL         R12, 88   # 0x1ce6
        ST_LOCAL         R13, 92   # 0x1cea
        C_MOV            R15, R14   # 0x1cee
        C_MOV            R8, R4   # 0x1cf0
        LD_GLOBAL_IDX    R0, R1, R2, 0, 20   # 0x1cf2
        SHLI             R9, R0, 16   # 0x1cf6
        LD_GLOBAL_IDX    R0, R1, R2, 0, 16   # 0x1cfa
        ST_LOCAL         R0, 48   # 0x1cfe
        SHRI             R0, R0, 16   # 0x1d02
        ST_LOCAL         R0, 68   # 0x1d06
        LD_GLOBAL_IDX    R0, R1, R2, 0, 12   # 0x1d0a
        SHLI             R0, R0, 16   # 0x1d0e
        LD_GLOBAL_IDX    R14, R1, R2, 0, 8   # 0x1d12
        SHRI             R5, R14, 16   # 0x1d16
        C_OR             R0, R5   # 0x1d1a
        LD_GLOBAL_IDX    R5, R1, R2, 0, 28   # 0x1d1c
        SHLI             R5, R5, 16   # 0x1d20
        LD_GLOBAL_IDX    R6, R1, R2, 0, 24   # 0x1d24
        SHRI             R7, R6, 16   # 0x1d28
        OR               R4, R5, R7, R5   # 0x1d2c
        ST_LOCAL         R4, 20   # 0x1d30
        MOVI             R4, 65535   # 0x1d34
        AND              R7, R14, R4, R14   # 0x1d38
        C_CHWIDTH        R14, 1   # 0x1d3c
        AND              R4, R6, R4, R6   # 0x1d3e
        ST_LOCAL         R4, 16   # 0x1d42
        LD_GLOBAL_IDX    R5, R1, R2, 0, 0   # 0x1d46
        MOVI             R2, 0   # 0x1d4a
        MOVI             R1, 61440   # 0x1d4e
        C_MOV            R11, R3   # 0x1d52
        OR               R14, R11, R1, R11   # 0x1d54
        SETP_EQ_NPI      P0, R1, R5, 0   # 0x1d58
        ANDI             R12, R5, -2   # 0x1d5c
        ANDI             R1, R5, 1   # 0x1d60
        ST_LOCAL         R1, 32   # 0x1d64
        ADDI             R1, R5, -1   # 0x1d68
        ST_LOCAL         R1, 28   # 0x1d6c
        CVT_SEXT         R6, R14, R14, R14   # 0x1d70
        ANDI             R10, R5, -4   # 0x1d74
        ST_LOCAL         R5, 12   # 0x1d78
        ST_LOCAL         R10, 40   # 0x1d7c
        ST_LOCAL         R15, 52   # 0x1d80
        ST_LOCAL         R11, 56   # 0x1d84
        ST_LOCAL         R8, 60   # 0x1d88
        ST_LOCAL         R6, 24   # 0x1d8c
        ST_LOCAL         R9, 44   # 0x1d90
        BRA_PRED         0, L2064   # 0x1d94
        ANDI             R1, R5, 3   # 0x1d98
        MOVI             R6, 0   # 0x1d9c
        C_BRA            L1db4   # 0x1da0
L1da2:  C_CHWIDTH        R14, 0   # 0x1da2
        LD_LOCAL         R3, 12   # 0x1da4
        C_ADD            R2, R3   # 0x1da8
        C_ADDI           R6, 1   # 0x1daa
        SETP_NE_NP       P0, R3, R6, R3   # 0x1dac
        BRA_PRED         4, L1e4c   # 0x1db0
L1db4:  CHWIDTH_MULTI    24576, 1   # 0x1db4
        MOVI             R3, 0   # 0x1db8
        LD_LOCAL         R5, 28   # 0x1dbc
        SETP_LT_U_NPI    P0, R5, R5, 3   # 0x1dc0
        BRA_PRED         0, L1e1a   # 0x1dc4
L1dc8:  ADD              R5, R2, R3, R2   # 0x1dc8
        C_SHLI           R5, 1   # 0x1dcc
        ADD              R5, R7, R5, R7   # 0x1dce
        SZ_GLOBAL_LD_U16 R14, R0, R5, 0, 0   # 0x1dd2
        ADD              R14, R14, R11, R14   # 0x1dd6
        SZ_GLOBAL_ST_16  R14, R0, R5, 0, 0   # 0x1dda
        C_CHWIDTH        R14, 0   # 0x1dde
        ADDI             R14, R5, 2   # 0x1de0
        SZ_GLOBAL_LD_U16 R13, R0, R14, 0, 0   # 0x1de4
        ADD              R13, R13, R11, R13   # 0x1de8
        SZ_GLOBAL_ST_16  R13, R0, R14, 0, 0   # 0x1dec
        ADDI             R14, R5, 4   # 0x1df0
        SZ_GLOBAL_LD_U16 R13, R0, R14, 0, 0   # 0x1df4
        ADD              R13, R13, R11, R13   # 0x1df8
        SZ_GLOBAL_ST_16  R13, R0, R14, 0, 0   # 0x1dfc
        C_CHWIDTH        R14, 1   # 0x1e00
        C_ADDI           R5, 6   # 0x1e02
        SZ_GLOBAL_LD_U16 R14, R0, R5, 0, 0   # 0x1e04
        ADD              R14, R14, R11, R14   # 0x1e08
        SZ_GLOBAL_ST_16  R14, R0, R5, 0, 0   # 0x1e0c
        C_ADDI           R3, 4   # 0x1e10
        SETP_NE_NP       P0, R5, R10, R3   # 0x1e12
        BRA_PRED         0, L1dc8   # 0x1e16
L1e1a:  SETP_EQ_NPI      P0, R5, R1, 0   # 0x1e1a
        BRA_PRED         0, L1da2   # 0x1e1e
        C_CHWIDTH        R14, 0   # 0x1e22
        C_ADD            R3, R2   # 0x1e24
        C_MOV            R5, R1   # 0x1e26
L1e28:  C_MOV            R14, R3   # 0x1e28
        C_SHLI           R14, 1   # 0x1e2a
        ADD              R14, R7, R14, R7   # 0x1e2c
        SZ_GLOBAL_LD_U16 R13, R0, R14, 0, 0   # 0x1e30
        ADD              R13, R13, R11, R13   # 0x1e34
        SZ_GLOBAL_ST_16  R13, R0, R14, 0, 0   # 0x1e38
        C_ADDI           R3, 1   # 0x1e3c
        ADDI             R5, R5, -1   # 0x1e3e
        SETP_NE_NPI      P0, R14, R5, 0   # 0x1e42
        BRA_PRED         0, L1e28   # 0x1e46
        C_BRA            L1da2   # 0x1e4a
L1e4c:  C_CHWIDTH        R11, 1   # 0x1e4c
        MOVI             R2, 0   # 0x1e4e
        CVT_SEXT         R6, R11, R11, R11   # 0x1e52
        C_CHWIDTH        R11, 0   # 0x1e56
        MOVI             R14, 0   # 0x1e58
        LD_LOCAL         R11, 20   # 0x1e5c
        LD_LOCAL         R15, 16   # 0x1e60
        C_BRA            L1e76   # 0x1e64
L1e66:  LD_LOCAL         R3, 12   # 0x1e66
        C_ADD            R2, R3   # 0x1e6a
        C_ADDI           R14, 1   # 0x1e6c
        SETP_NE_NP       P0, R3, R14, R3   # 0x1e6e
        BRA_PRED         4, L1f38   # 0x1e72
L1e76:  LD_LOCAL         R3, 28   # 0x1e76
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x1e7a
        MOVI             R5, 0   # 0x1e7e
        BRA_PRED         0, L1f00   # 0x1e82
L1e86:  ADD              R3, R2, R5, R2   # 0x1e86
        C_MOV            R8, R3   # 0x1e8a
        C_SHLI           R8, 2   # 0x1e8c
        ADD              R8, R15, R8, R15   # 0x1e8e
        C_MOV            R9, R3   # 0x1e92
        C_SHLI           R9, 1   # 0x1e94
        ADD              R9, R7, R9, R7   # 0x1e96
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1e9a
        C_MUL_LO         R9, R6   # 0x1e9e
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1ea0
        ADDI             R8, R3, 1   # 0x1ea4
        C_MOV            R9, R8   # 0x1ea8
        C_SHLI           R9, 2   # 0x1eaa
        ADD              R9, R15, R9, R15   # 0x1eac
        C_SHLI           R8, 1   # 0x1eb0
        ADD              R8, R7, R8, R7   # 0x1eb2
        SZ_GLOBAL_LD_S16 R8, R0, R8, 0, 0   # 0x1eb6
        C_MUL_LO         R8, R6   # 0x1eba
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1ebc
        ADDI             R8, R3, 2   # 0x1ec0
        C_MOV            R9, R8   # 0x1ec4
        C_SHLI           R9, 2   # 0x1ec6
        ADD              R9, R15, R9, R15   # 0x1ec8
        C_SHLI           R8, 1   # 0x1ecc
        ADD              R8, R7, R8, R7   # 0x1ece
        SZ_GLOBAL_LD_S16 R8, R0, R8, 0, 0   # 0x1ed2
        C_MUL_LO         R8, R6   # 0x1ed6
        ST_GLOBAL_IDX    R8, R11, R9, 0, 0   # 0x1ed8
        C_ADDI           R3, 3   # 0x1edc
        C_MOV            R8, R3   # 0x1ede
        C_SHLI           R8, 2   # 0x1ee0
        ADD              R8, R15, R8, R15   # 0x1ee2
        C_SHLI           R3, 1   # 0x1ee6
        ADD              R3, R7, R3, R7   # 0x1ee8
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x1eec
        C_MUL_LO         R3, R6   # 0x1ef0
        ST_GLOBAL_IDX    R3, R11, R8, 0, 0   # 0x1ef2
        C_ADDI           R5, 4   # 0x1ef6
        SETP_NE_NP       P0, R3, R10, R5   # 0x1ef8
        BRA_PRED         0, L1e86   # 0x1efc
L1f00:  SETP_EQ_NPI      P0, R3, R1, 0   # 0x1f00
        BRA_PRED         0, L1e66   # 0x1f04
        ADD              R3, R5, R2, R5   # 0x1f08
        C_MOV            R5, R1   # 0x1f0c
L1f0e:  C_MOV            R8, R3   # 0x1f0e
        C_SHLI           R8, 2   # 0x1f10
        ADD              R8, R15, R8, R15   # 0x1f12
        C_MOV            R9, R3   # 0x1f16
        C_SHLI           R9, 1   # 0x1f18
        ADD              R9, R7, R9, R7   # 0x1f1a
        SZ_GLOBAL_LD_S16 R9, R0, R9, 0, 0   # 0x1f1e
        C_MUL_LO         R9, R6   # 0x1f22
        ST_GLOBAL_IDX    R9, R11, R8, 0, 0   # 0x1f24
        C_ADDI           R3, 1   # 0x1f28
        ADDI             R5, R5, -1   # 0x1f2a
        SETP_NE_NPI      P0, R8, R5, 0   # 0x1f2e
        BRA_PRED         0, L1f0e   # 0x1f32
        C_BRA            L1e66   # 0x1f36
L1f38:  C_CHWIDTH        R13, 0   # 0x1f38
        MOVI             R1, 0   # 0x1f3a
        C_MOV            R15, R1   # 0x1f3e
        MOVI             R5, 0   # 0x1f40
        MOVI             R13, 0   # 0x1f44
        MOVI             R1, 0   # 0x1f48
        MOVI             R8, 0   # 0x1f4c
        C_BRA            L1f66   # 0x1f50
L1f52:  LD_LOCAL         R3, 12   # 0x1f52
        C_ADD            R5, R3   # 0x1f56
        C_ADDI           R13, 1   # 0x1f58
        SETP_NE_NP       P0, R3, R13, R3   # 0x1f5a
        LD_LOCAL         R10, 40   # 0x1f5e
        BRA_PRED         4, L206a   # 0x1f62
L1f66:  ST_LOCAL         R13, 36   # 0x1f66
        LD_LOCAL         R3, 28   # 0x1f6a
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x1f6e
        BRA_PRED         0, L1ffc   # 0x1f72
        MOVI             R9, 0   # 0x1f76
        LD_LOCAL         R2, 16   # 0x1f7a
        LD_LOCAL         R2, 24   # 0x1f7e
L1f82:  C_CHWIDTH        R15, 0   # 0x1f82
        ADD              R3, R5, R9, R5   # 0x1f84
        C_SHLI           R3, 2   # 0x1f88
        LD_LOCAL         R6, 16   # 0x1f8a
        C_ADD            R3, R6   # 0x1f8e
        C_MOV            R14, R5   # 0x1f90
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x1f92
        SETP_LT_NP       P0, R1, R1, R5   # 0x1f96
        C_MOV            R10, R15   # 0x1f9a
        MOVI             R15, 0   # 0x1f9c
        ADDI_P           R15, 0, R15, 1   # 0x1fa0
        ADD              R8, R5, R8, R5   # 0x1fa4
        SETP_LT_NP       P0, R1, R2, R8   # 0x1fa8
        MOVI             R6, 10   # 0x1fac
        MOV_P            R15, 0, R6, R6, R6   # 0x1fb0
        MOVI             R13, 0   # 0x1fb4
        MOV_P            R8, 0, R13, R13, R13   # 0x1fb8
        ADDI             R1, R3, 4   # 0x1fbc
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x1fc0
        SETP_LT_NP       P0, R3, R5, R1   # 0x1fc4
        MOVI             R3, 0   # 0x1fc8
        ADDI_P           R3, 0, R3, 1   # 0x1fcc
        ADD              R8, R1, R8, R1   # 0x1fd0
        SETP_LT_NP       P0, R5, R2, R8   # 0x1fd4
        C_CHWIDTH        R5, 1   # 0x1fd8
        MOV_P            R3, 0, R6, R6, R6   # 0x1fda
        MOV_P            R8, 0, R13, R13, R13   # 0x1fde
        ADD              R5, R15, R10, R15   # 0x1fe2
        C_CHWIDTH        R15, 1   # 0x1fe6
        ADD              R15, R3, R5, R3   # 0x1fe8
        C_CHWIDTH        R5, 0   # 0x1fec
        C_MOV            R5, R14   # 0x1fee
        C_ADDI           R9, 2   # 0x1ff0
        SETP_NE_NP       P0, R3, R12, R9   # 0x1ff2
        BRA_PRED         0, L1f82   # 0x1ff6
        C_BRA            L2004   # 0x1ffa
L1ffc:  MOVI             R9, 0   # 0x1ffc
        LD_LOCAL         R2, 24   # 0x2000
L2004:  LD_LOCAL         R3, 32   # 0x2004
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2008
        C_MOV            R6, R2   # 0x200c
        MOVI             R2, 0   # 0x200e
        MOVI             R14, 10   # 0x2012
        LD_LOCAL         R13, 36   # 0x2016
        BRA_PRED         0, L1f52   # 0x201a
        C_CHWIDTH        R15, 1   # 0x201e
        LD_LOCAL         R3, 12   # 0x2020
        MUL_LO           R3, R13, R3, R3   # 0x2024
        ADD              R3, R9, R3, R9   # 0x2028
        C_SHLI           R3, 2   # 0x202c
        C_MOV            R9, R5   # 0x202e
        LD_LOCAL         R5, 16   # 0x2030
        ADD              R3, R5, R3, R5   # 0x2034
        C_MOV            R5, R9   # 0x2038
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x203a
        SETP_LT_NP       P0, R1, R1, R3   # 0x203e
        ADD              R8, R3, R8, R3   # 0x2042
        SETP_LT_NP       P1, R1, R6, R8   # 0x2046
        MOV_P            R8, 1, R2, R2, R2   # 0x204a
        MOVI             R1, 0   # 0x204e
        ADDI_P           R1, 0, R1, 1   # 0x2052
        MOV_P            R1, 1, R14, R14, R14   # 0x2056
        ADD              R15, R1, R15, R1   # 0x205a
        C_MOV            R1, R3   # 0x205e
        BRA              L1f52   # 0x2060
L2064:  C_MOV            R15, R2   # 0x2064
        LD_LOCAL         R11, 20   # 0x2066
L206a:  C_CHWIDTH        R15, 0   # 0x206a
        LD_LOCAL         R1, 44   # 0x206c
        LD_LOCAL         R2, 68   # 0x2070
        OR               R8, R1, R2, R1   # 0x2074
        LD_LOCAL         R1, 48   # 0x2078
        MOVI             R2, 65535   # 0x207c
        AND              R9, R1, R2, R1   # 0x2080
        MOVI             R1, 0   # 0x2084
        LD_LOCAL         R2, 12   # 0x2088
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x208c
        ST_LOCAL         R15, 64   # 0x2090
        BRA_PRED         0, L2272   # 0x2094
        MOVI             R2, 0   # 0x2098
        C_BRA            L20be   # 0x209c
L209e:  C_MOV            R3, R2   # 0x209e
        C_SHLI           R3, 2   # 0x20a0
        LD_LOCAL         R6, 16   # 0x20a2
        ADD              R3, R6, R3, R6   # 0x20a6
        ST_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x20aa
        LD_LOCAL         R3, 12   # 0x20ae
        C_ADD            R1, R3   # 0x20b2
        C_ADDI           R2, 1   # 0x20b4
        SETP_NE_NP       P0, R3, R2, R3   # 0x20b6
        BRA_PRED         4, L2140   # 0x20ba
L20be:  LD_LOCAL         R3, 28   # 0x20be
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x20c2
        BRA_PRED         0, L2106   # 0x20c6
        C_CHWIDTH        R14, 0   # 0x20ca
        MOVI             R3, 0   # 0x20cc
        MOVI             R5, 0   # 0x20d0
L20d4:  ADD              R6, R1, R3, R1   # 0x20d4
        C_SHLI           R6, 1   # 0x20d8
        C_ADD            R6, R7   # 0x20da
        C_MOV            R14, R3   # 0x20dc
        C_SHLI           R14, 1   # 0x20de
        C_ADD            R14, R9   # 0x20e0
        SZ_GLOBAL_LD_S16 R15, R8, R14, 0, 0   # 0x20e2
        SZ_GLOBAL_LD_S16 R13, R0, R6, 0, 0   # 0x20e6
        MAD_ACC          R5, R15, R13   # 0x20ea
        C_ADDI           R14, 2   # 0x20ec
        SZ_GLOBAL_LD_S16 R14, R8, R14, 0, 0   # 0x20ee
        C_ADDI           R6, 2   # 0x20f2
        SZ_GLOBAL_LD_S16 R6, R0, R6, 0, 0   # 0x20f4
        MAD_ACC          R5, R14, R6   # 0x20f8
        C_ADDI           R3, 2   # 0x20fa
        SETP_NE_NP       P0, R6, R12, R3   # 0x20fc
        BRA_PRED         0, L20d4   # 0x2100
        C_BRA            L210e   # 0x2104
L2106:  MOVI             R3, 0   # 0x2106
        MOVI             R5, 0   # 0x210a
L210e:  C_CHWIDTH        R14, 0   # 0x210e
        LD_LOCAL         R6, 32   # 0x2110
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x2114
        BRA_PRED         0, L209e   # 0x2118
        LD_LOCAL         R4, 12   # 0x211c
        MUL_LO           R6, R2, R4, R4   # 0x2120
        C_MOV            R14, R3   # 0x2124
        C_SHLI           R14, 1   # 0x2126
        ADD              R14, R9, R14, R9   # 0x2128
        SZ_GLOBAL_LD_S16 R14, R8, R14, 0, 0   # 0x212c
        C_ADD            R3, R6   # 0x2130
        C_SHLI           R3, 1   # 0x2132
        ADD              R3, R7, R3, R7   # 0x2134
        SZ_GLOBAL_LD_S16 R3, R0, R3, 0, 0   # 0x2138
        MAD_ACC          R5, R14, R3   # 0x213c
        C_BRA            L209e   # 0x213e
L2140:  MOVI             R1, 0   # 0x2140
        C_MOV            R5, R1   # 0x2144
        MOVI             R3, 0   # 0x2146
        ST_LOCAL         R1, 44   # 0x214a
        MOVI             R13, 0   # 0x214e
        C_BRA            L2170   # 0x2152
L2154:  LD_LOCAL         R2, 12   # 0x2154
        LD_LOCAL         R3, 36   # 0x2158
        C_ADD            R3, R2   # 0x215c
        LD_LOCAL         R6, 44   # 0x215e
        C_ADDI           R6, 1   # 0x2162
        ST_LOCAL         R6, 44   # 0x2164
        SETP_NE_NP       P0, R2, R6, R2   # 0x2168
        BRA_PRED         4, L2274   # 0x216c
L2170:  ST_LOCAL         R3, 36   # 0x2170
        LD_LOCAL         R2, 28   # 0x2174
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x2178
        BRA_PRED         0, L220a   # 0x217c
        MOVI             R6, 0   # 0x2180
        LD_LOCAL         R2, 16   # 0x2184
        LD_LOCAL         R2, 24   # 0x2188
        LD_LOCAL         R2, 36   # 0x218c
L2190:  C_CHWIDTH        R5, 0   # 0x2190
        LD_LOCAL         R2, 36   # 0x2192
        ADD              R3, R2, R6, R2   # 0x2196
        C_SHLI           R3, 2   # 0x219a
        LD_LOCAL         R2, 16   # 0x219c
        C_ADD            R3, R2   # 0x21a0
        C_MOV            R15, R5   # 0x21a2
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x21a4
        SETP_LT_NP       P0, R1, R1, R5   # 0x21a8
        MOVI             R2, 0   # 0x21ac
        ADDI_P           R2, 0, R2, 1   # 0x21b0
        ADD              R13, R5, R13, R5   # 0x21b4
        LD_LOCAL         R4, 24   # 0x21b8
        SETP_LT_NP       P0, R1, R4, R13   # 0x21bc
        MOVI             R14, 10   # 0x21c0
        MOV_P            R2, 0, R14, R14, R14   # 0x21c4
        MOVI             R10, 0   # 0x21c8
        MOV_P            R13, 0, R10, R10, R10   # 0x21cc
        ADDI             R1, R3, 4   # 0x21d0
        LD_GLOBAL_IDX    R1, R11, R1, 0, 0   # 0x21d4
        SETP_LT_NP       P0, R3, R5, R1   # 0x21d8
        MOVI             R3, 0   # 0x21dc
        ADDI_P           R3, 0, R3, 1   # 0x21e0
        ADD              R13, R1, R13, R1   # 0x21e4
        SETP_LT_NP       P0, R5, R4, R13   # 0x21e8
        C_CHWIDTH        R5, 1   # 0x21ec
        MOV_P            R3, 0, R14, R14, R14   # 0x21ee
        MOV_P            R13, 0, R10, R10, R10   # 0x21f2
        ADD              R5, R2, R15, R2   # 0x21f6
        ADD              R5, R3, R5, R3   # 0x21fa
        C_ADDI           R6, 2   # 0x21fe
        SETP_NE_NP       P0, R2, R12, R6   # 0x2200
        BRA_PRED         0, L2190   # 0x2204
        C_BRA            L2212   # 0x2208
L220a:  MOVI             R6, 0   # 0x220a
        LD_LOCAL         R2, 24   # 0x220e
L2212:  LD_LOCAL         R2, 32   # 0x2212
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x2216
        LD_LOCAL         R14, 24   # 0x221a
        LD_LOCAL         R10, 40   # 0x221e
        MOVI             R15, 0   # 0x2222
        BRA_PRED         0, L2154   # 0x2226
        C_CHWIDTH        R5, 1   # 0x222a
        LD_LOCAL         R2, 44   # 0x222c
        LD_LOCAL         R3, 12   # 0x2230
        C_MUL_LO         R2, R3   # 0x2234
        ADD              R2, R6, R2, R6   # 0x2236
        C_SHLI           R2, 2   # 0x223a
        LD_LOCAL         R3, 16   # 0x223c
        ADD              R2, R3, R2, R3   # 0x2240
        LD_GLOBAL_IDX    R2, R11, R2, 0, 0   # 0x2244
        SETP_LT_NP       P0, R1, R1, R2   # 0x2248
        ADD              R13, R2, R13, R2   # 0x224c
        SETP_LT_NP       P1, R1, R14, R13   # 0x2250
        MOV_P            R13, 1, R15, R15, R15   # 0x2254
        MOVI             R1, 0   # 0x2258
        ADDI_P           R1, 0, R1, 1   # 0x225c
        MOVI             R3, 10   # 0x2260
        MOV_P            R1, 1, R3, R3, R3   # 0x2264
        ADD              R5, R1, R5, R1   # 0x2268
        C_MOV            R1, R2   # 0x226c
        BRA              L2154   # 0x226e
L2272:  C_MOV            R5, R1   # 0x2272
L2274:  C_CHWIDTH        R5, 0   # 0x2274
        ST_LOCAL         R5, 68   # 0x2276
        MOVI             R1, 0   # 0x227a
        LD_LOCAL         R3, 12   # 0x227e
        SETP_EQ_NPI      P0, R2, R3, 0   # 0x2282
        C_MOV            R2, R3   # 0x2286
        C_SHLI           R2, 1   # 0x2288
        BRA_PRED         0, L24c0   # 0x228a
        C_CHWIDTH        R14, 0   # 0x228e
        MOVI             R5, 0   # 0x2290
        LD_LOCAL         R10, 12   # 0x2294
        C_BRA            L22aa   # 0x2298
L229a:  C_ADD            R1, R10   # 0x229a
        LD_LOCAL         R5, 36   # 0x229c
        C_ADDI           R5, 1   # 0x22a0
        SETP_NE_NP       P0, R3, R5, R10   # 0x22a2
        BRA_PRED         4, L2362   # 0x22a6
L22aa:  ST_LOCAL         R5, 36   # 0x22aa
        MUL_LO           R14, R5, R10, R10   # 0x22ae
        MOVI             R11, 0   # 0x22b2
        C_BRA            L22d8   # 0x22b6
L22b8:  ADD              R3, R11, R14, R11   # 0x22b8
        C_SHLI           R3, 2   # 0x22bc
        LD_LOCAL         R6, 16   # 0x22be
        ADD              R3, R6, R3, R6   # 0x22c2
        LD_LOCAL         R6, 20   # 0x22c6
        ST_GLOBAL_IDX    R5, R6, R3, 0, 0   # 0x22ca
        C_ADDI           R11, 1   # 0x22ce
        SETP_NE_NP       P0, R3, R11, R10   # 0x22d0
        BRA_PRED         4, L229a   # 0x22d4
L22d8:  LD_LOCAL         R3, 28   # 0x22d8
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x22dc
        MOVI             R13, 0   # 0x22e0
        MOVI             R5, 0   # 0x22e4
        BRA_PRED         0, L2336   # 0x22e8
        C_MOV            R15, R11   # 0x22ec
        MOVI             R5, 0   # 0x22ee
L22f2:  ADD              R6, R1, R13, R1   # 0x22f2
        C_SHLI           R6, 1   # 0x22f6
        C_ADD            R6, R7   # 0x22f8
        C_MOV            R3, R15   # 0x22fa
        C_SHLI           R3, 1   # 0x22fc
        ADD              R3, R9, R3, R9   # 0x22fe
        SZ_GLOBAL_LD_S16 R3, R8, R3, 0, 0   # 0x2302
        SZ_GLOBAL_LD_S16 R10, R0, R6, 0, 0   # 0x2306
        MADLO            R3, R3, R10, R5   # 0x230a
        LD_LOCAL         R10, 12   # 0x230e
        ADD              R5, R10, R15, R10   # 0x2312
        C_SHLI           R5, 1   # 0x2316
        ADD              R5, R9, R5, R9   # 0x2318
        SZ_GLOBAL_LD_S16 R5, R8, R5, 0, 0   # 0x231c
        C_ADDI           R6, 2   # 0x2320
        SZ_GLOBAL_LD_S16 R6, R0, R6, 0, 0   # 0x2322
        MADLO            R5, R5, R6, R3   # 0x2326
        C_ADD            R15, R2   # 0x232a
        C_ADDI           R13, 2   # 0x232c
        SETP_NE_NP       P0, R3, R12, R13   # 0x232e
        BRA_PRED         0, L22f2   # 0x2332
L2336:  LD_LOCAL         R3, 32   # 0x2336
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x233a
        BRA_PRED         0, L22b8   # 0x233e
        MADLO            R3, R13, R10, R11   # 0x2342
        C_SHLI           R3, 1   # 0x2346
        ADD              R3, R9, R3, R9   # 0x2348
        SZ_GLOBAL_LD_S16 R3, R8, R3, 0, 0   # 0x234c
        ADD              R6, R13, R14, R13   # 0x2350
        C_SHLI           R6, 1   # 0x2354
        ADD              R6, R7, R6, R7   # 0x2356
        SZ_GLOBAL_LD_S16 R6, R0, R6, 0, 0   # 0x235a
        MAD_ACC          R5, R3, R6   # 0x235e
        C_BRA            L22b8   # 0x2360
L2362:  MOVI             R1, 0   # 0x2362
        ST_LOCAL         R1, 44   # 0x2366
        MOVI             R6, 0   # 0x236a
        MOVI             R11, 0   # 0x236e
        MOVI             R1, 0   # 0x2372
        MOVI             R14, 0   # 0x2376
        LD_LOCAL         R5, 20   # 0x237a
        C_BRA            L2398   # 0x237e
L2380:  LD_LOCAL         R6, 36   # 0x2380
        C_ADD            R6, R5   # 0x2384
        C_ADDI           R11, 1   # 0x2386
        SETP_NE_NP       P0, R3, R11, R5   # 0x2388
        LD_LOCAL         R10, 40   # 0x238c
        LD_LOCAL         R5, 20   # 0x2390
        BRA_PRED         4, L24c4   # 0x2394
L2398:  ST_LOCAL         R11, 48   # 0x2398
        ST_LOCAL         R6, 36   # 0x239c
        LD_LOCAL         R3, 28   # 0x23a0
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x23a4
        BRA_PRED         0, L2440   # 0x23a8
        MOVI             R13, 0   # 0x23ac
        LD_LOCAL         R3, 16   # 0x23b0
        LD_LOCAL         R3, 24   # 0x23b4
        LD_LOCAL         R15, 44   # 0x23b8
        C_CHWIDTH        R15, 1   # 0x23bc
        LD_LOCAL         R3, 36   # 0x23be
L23c2:  C_CHWIDTH        R5, 0   # 0x23c2
        LD_LOCAL         R3, 36   # 0x23c4
        C_ADD            R3, R13   # 0x23c8
        C_SHLI           R3, 2   # 0x23ca
        LD_LOCAL         R5, 16   # 0x23cc
        C_ADD            R3, R5   # 0x23d0
        LD_LOCAL         R4, 20   # 0x23d2
        LD_GLOBAL_IDX    R5, R4, R3, 0, 0   # 0x23d6
        SETP_LT_NP       P0, R1, R1, R5   # 0x23da
        MOVI             R10, 0   # 0x23de
        ADDI_P           R10, 0, R10, 1   # 0x23e2
        ADD              R14, R5, R14, R5   # 0x23e6
        LD_LOCAL         R11, 24   # 0x23ea
        SETP_LT_NP       P0, R1, R11, R14   # 0x23ee
        MOVI             R1, 10   # 0x23f2
        MOV_P            R10, 0, R1, R1, R1   # 0x23f6
        MOVI             R6, 0   # 0x23fa
        MOV_P            R14, 0, R6, R6, R6   # 0x23fe
        ADDI             R1, R3, 4   # 0x2402
        LD_GLOBAL_IDX    R1, R4, R1, 0, 0   # 0x2406
        SETP_LT_NP       P0, R3, R5, R1   # 0x240a
        MOVI             R3, 0   # 0x240e
        ADDI_P           R3, 0, R3, 1   # 0x2412
        ADD              R14, R1, R14, R1   # 0x2416
        SETP_LT_NP       P0, R5, R11, R14   # 0x241a
        C_CHWIDTH        R5, 1   # 0x241e
        MOVI             R4, 10   # 0x2420
        MOV_P            R3, 0, R4, R4, R4   # 0x2424
        MOV_P            R14, 0, R6, R6, R6   # 0x2428
        ADD              R5, R10, R15, R10   # 0x242c
        ADD              R15, R3, R5, R3   # 0x2430
        C_ADDI           R13, 2   # 0x2434
        SETP_NE_NP       P0, R3, R12, R13   # 0x2436
        BRA_PRED         0, L23c2   # 0x243a
        C_BRA            L2448   # 0x243e
L2440:  MOVI             R13, 0   # 0x2440
        LD_LOCAL         R15, 44   # 0x2444
L2448:  CHWIDTH_MULTI    32800, 0   # 0x2448
        LD_LOCAL         R3, 20   # 0x244c
        ST_LOCAL         R15, 44   # 0x2450
        LD_LOCAL         R3, 32   # 0x2454
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2458
        LD_LOCAL         R5, 12   # 0x245c
        MOVI             R6, 0   # 0x2460
        MOVI             R15, 10   # 0x2464
        LD_LOCAL         R11, 48   # 0x2468
        BRA_PRED         0, L2380   # 0x246c
        MUL_LO           R3, R11, R5, R5   # 0x2470
        ADD              R3, R13, R3, R13   # 0x2474
        C_SHLI           R3, 2   # 0x2478
        LD_LOCAL         R10, 16   # 0x247a
        ADD              R3, R10, R3, R10   # 0x247e
        LD_LOCAL         R10, 20   # 0x2482
        LD_GLOBAL_IDX    R3, R10, R3, 0, 0   # 0x2486
        SETP_LT_NP       P0, R1, R1, R3   # 0x248a
        ADD              R14, R3, R14, R3   # 0x248e
        LD_LOCAL         R1, 24   # 0x2492
        SETP_LT_NP       P1, R1, R1, R14   # 0x2496
        MOV_P            R14, 1, R6, R6, R6   # 0x249a
        MOVI             R1, 0   # 0x249e
        ADDI_P           R1, 0, R1, 1   # 0x24a2
        MOV_P            R1, 1, R15, R15, R15   # 0x24a6
        LD_LOCAL         R6, 44   # 0x24aa
        C_CHWIDTH        R6, 1   # 0x24ae
        ADD              R6, R1, R6, R1   # 0x24b0
        C_CHWIDTH        R6, 0   # 0x24b4
        ST_LOCAL         R6, 44   # 0x24b6
        C_MOV            R1, R3   # 0x24ba
        BRA              L2380   # 0x24bc
L24c0:  ST_LOCAL         R1, 44   # 0x24c0
L24c4:  MOVI             R6, 0   # 0x24c4
        LD_LOCAL         R1, 12   # 0x24c8
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x24cc
        BRA_PRED         0, L26fa   # 0x24d0
        MOVI             R3, 0   # 0x24d4
        LD_LOCAL         R10, 12   # 0x24d8
        C_BRA            L24ee   # 0x24dc
L24de:  C_ADD            R6, R10   # 0x24de
        LD_LOCAL         R3, 48   # 0x24e0
        C_ADDI           R3, 1   # 0x24e4
        SETP_NE_NP       P0, R1, R3, R10   # 0x24e6
        BRA_PRED         4, L25d8   # 0x24ea
L24ee:  ST_LOCAL         R3, 48   # 0x24ee
        MUL_LO           R1, R3, R10, R10   # 0x24f2
        ST_LOCAL         R1, 36   # 0x24f6
        MOVI             R3, 0   # 0x24fa
        C_BRA            L2524   # 0x24fe
L2500:  LD_LOCAL         R1, 36   # 0x2500
        ADD              R5, R3, R1, R3   # 0x2504
        C_SHLI           R5, 2   # 0x2508
        LD_LOCAL         R1, 16   # 0x250a
        ADD              R5, R1, R5, R1   # 0x250e
        LD_LOCAL         R11, 20   # 0x2512
        ST_GLOBAL_IDX    R14, R11, R5, 0, 0   # 0x2516
        C_ADDI           R3, 1   # 0x251a
        SETP_NE_NP       P0, R5, R3, R10   # 0x251c
        BRA_PRED         4, L24de   # 0x2520
L2524:  C_CHWIDTH        R14, 0   # 0x2524
        LD_LOCAL         R5, 28   # 0x2526
        SETP_EQ_NPI      P0, R5, R5, 0   # 0x252a
        MOVI             R5, 0   # 0x252e
        MOVI             R14, 0   # 0x2532
        C_MOV            R1, R10   # 0x2536
        BRA_PRED         0, L2598   # 0x2538
        C_MOV            R13, R3   # 0x253c
L253e:  ADD              R10, R6, R5, R6   # 0x253e
        C_SHLI           R10, 1   # 0x2542
        C_ADD            R10, R7   # 0x2544
        C_MOV            R11, R13   # 0x2546
        C_SHLI           R11, 1   # 0x2548
        ADD              R11, R9, R11, R9   # 0x254a
        SZ_GLOBAL_LD_U16 R11, R8, R11, 0, 0   # 0x254e
        SZ_GLOBAL_LD_U16 R15, R0, R10, 0, 0   # 0x2552
        MUL_LO           R15, R11, R15, R15   # 0x2556
        C_MOV            R11, R15   # 0x255a
        C_SHRI           R11, 5   # 0x255c
        ANDI             R11, R11, 127   # 0x255e
        C_SHRI           R15, 2   # 0x2562
        C_ANDI           R15, 15   # 0x2564
        MAD_ACC          R14, R15, R11   # 0x2566
        ADD              R15, R1, R13, R1   # 0x2568
        C_SHLI           R15, 1   # 0x256c
        ADD              R15, R9, R15, R9   # 0x256e
        SZ_GLOBAL_LD_U16 R15, R8, R15, 0, 0   # 0x2572
        C_ADDI           R10, 2   # 0x2576
        SZ_GLOBAL_LD_U16 R10, R0, R10, 0, 0   # 0x2578
        C_MUL_LO         R15, R10   # 0x257c
        C_MOV            R10, R15   # 0x257e
        C_SHRI           R10, 5   # 0x2580
        ANDI             R10, R10, 127   # 0x2582
        C_SHRI           R15, 2   # 0x2586
        C_ANDI           R15, 15   # 0x2588
        MAD_ACC          R14, R15, R10   # 0x258a
        C_ADD            R13, R2   # 0x258c
        C_ADDI           R5, 2   # 0x258e
        SETP_NE_NP       P0, R15, R12, R5   # 0x2590
        BRA_PRED         0, L253e   # 0x2594
L2598:  LD_LOCAL         R15, 32   # 0x2598
        SETP_EQ_NPI      P0, R15, R15, 0   # 0x259c
        C_MOV            R10, R1   # 0x25a0
        BRA_PRED         0, L2500   # 0x25a2
        MADLO            R15, R5, R10, R3   # 0x25a6
        C_SHLI           R15, 1   # 0x25aa
        ADD              R15, R9, R15, R9   # 0x25ac
        SZ_GLOBAL_LD_U16 R15, R8, R15, 0, 0   # 0x25b0
        LD_LOCAL         R1, 36   # 0x25b4
        C_ADD            R5, R1   # 0x25b8
        C_SHLI           R5, 1   # 0x25ba
        ADD              R5, R7, R5, R7   # 0x25bc
        SZ_GLOBAL_LD_U16 R5, R0, R5, 0, 0   # 0x25c0
        MUL_LO           R5, R15, R5, R5   # 0x25c4
        C_MOV            R15, R5   # 0x25c8
        C_SHRI           R15, 5   # 0x25ca
        ANDI             R15, R15, 127   # 0x25cc
        C_SHRI           R5, 2   # 0x25d0
        C_ANDI           R5, 15   # 0x25d2
        MAD_ACC          R14, R5, R15   # 0x25d4
        C_BRA            L2500   # 0x25d6
L25d8:  MOVI             R1, 0   # 0x25d8
        C_MOV            R8, R1   # 0x25dc
        MOVI             R5, 0   # 0x25de
        ST_LOCAL         R1, 36   # 0x25e2
        MOVI             R13, 0   # 0x25e6
        LD_LOCAL         R10, 24   # 0x25ea
        C_BRA            L2608   # 0x25ee
L25f0:  C_ADD            R5, R15   # 0x25f0
        LD_LOCAL         R2, 36   # 0x25f2
        C_ADDI           R2, 1   # 0x25f6
        ST_LOCAL         R2, 36   # 0x25f8
        SETP_NE_NP       P0, R3, R2, R15   # 0x25fc
        LD_LOCAL         R9, 40   # 0x2600
        BRA_PRED         4, L26fe   # 0x2604
L2608:  LD_LOCAL         R3, 28   # 0x2608
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x260c
        BRA_PRED         0, L2698   # 0x2610
        MOVI             R9, 0   # 0x2614
        LD_LOCAL         R2, 16   # 0x2618
L261c:  C_CHWIDTH        R8, 1   # 0x261c
        ADD              R3, R5, R9, R5   # 0x261e
        C_SHLI           R3, 2   # 0x2622
        LD_LOCAL         R2, 16   # 0x2624
        C_ADD            R3, R2   # 0x2628
        C_MOV            R14, R5   # 0x262a
        LD_GLOBAL_IDX    R5, R11, R3, 0, 0   # 0x262c
        SETP_LT_NP       P0, R15, R13, R5   # 0x2630
        MOVI             R15, 0   # 0x2634
        ADDI_P           R15, 0, R15, 1   # 0x2638
        ADD              R1, R5, R1, R5   # 0x263c
        LD_LOCAL         R10, 24   # 0x2640
        SETP_LT_NP       P0, R10, R10, R1   # 0x2644
        LD_LOCAL         R10, 24   # 0x2648
        MOVI             R2, 10   # 0x264c
        MOV_P            R15, 0, R2, R2, R2   # 0x2650
        MOVI             R6, 0   # 0x2654
        MOV_P            R1, 0, R6, R6, R6   # 0x2658
        C_ADDI           R3, 4   # 0x265c
        LD_GLOBAL_IDX    R13, R11, R3, 0, 0   # 0x265e
        SETP_LT_NP       P0, R3, R5, R13   # 0x2662
        MOVI             R3, 0   # 0x2666
        ADDI_P           R3, 0, R3, 1   # 0x266a
        ADD              R1, R13, R1, R13   # 0x266e
        SETP_LT_NP       P0, R5, R10, R1   # 0x2672
        C_CHWIDTH        R5, 1   # 0x2676
        MOV_P            R3, 0, R2, R2, R2   # 0x2678
        MOV_P            R1, 0, R6, R6, R6   # 0x267c
        ADD              R5, R15, R8, R15   # 0x2680
        ADD              R8, R3, R5, R3   # 0x2684
        C_CHWIDTH        R5, 0   # 0x2688
        C_MOV            R5, R14   # 0x268a
        C_ADDI           R9, 2   # 0x268c
        SETP_NE_NP       P0, R3, R12, R9   # 0x268e
        BRA_PRED         0, L261c   # 0x2692
        C_BRA            L269c   # 0x2696
L2698:  MOVI             R9, 0   # 0x2698
L269c:  MOVI             R6, 10   # 0x269c
        MOVI             R14, 0   # 0x26a0
        LD_LOCAL         R2, 32   # 0x26a4
        SETP_EQ_NPI      P0, R3, R2, 0   # 0x26a8
        LD_LOCAL         R15, 12   # 0x26ac
        BRA_PRED         0, L25f0   # 0x26b0
        C_CHWIDTH        R8, 1   # 0x26b4
        LD_LOCAL         R2, 36   # 0x26b6
        MUL_LO           R3, R2, R15, R15   # 0x26ba
        ADD              R3, R9, R3, R9   # 0x26be
        C_SHLI           R3, 2   # 0x26c2
        LD_LOCAL         R2, 16   # 0x26c4
        ADD              R3, R2, R3, R2   # 0x26c8
        LD_GLOBAL_IDX    R3, R11, R3, 0, 0   # 0x26cc
        C_MOV            R2, R5   # 0x26d0
        SETP_LT_NP       P0, R5, R13, R3   # 0x26d2
        ADD              R1, R3, R1, R3   # 0x26d6
        SETP_LT_NP       P1, R5, R10, R1   # 0x26da
        MOV_P            R1, 1, R14, R14, R14   # 0x26de
        MOVI             R5, 0   # 0x26e2
        ADDI_P           R5, 0, R5, 1   # 0x26e6
        MOV_P            R5, 1, R6, R6, R6   # 0x26ea
        ADD              R8, R5, R8, R5   # 0x26ee
        C_MOV            R5, R2   # 0x26f2
        C_MOV            R13, R3   # 0x26f4
        BRA              L25f0   # 0x26f6
L26fa:  C_MOV            R8, R6   # 0x26fa
        C_MOV            R9, R10   # 0x26fc
L26fe:  LD_LOCAL         R1, 60   # 0x26fe
        C_MOV            R5, R1   # 0x2702
        C_CHWIDTH        R5, 1   # 0x2704
        LD_LOCAL         R1, 12   # 0x2706
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x270a
        LD_LOCAL         R12, 56   # 0x270e
        LD_LOCAL         R10, 44   # 0x2712
        BRA_PRED         0, L27d8   # 0x2716
        MOVI             R1, 0   # 0x271a
        LD_LOCAL         R2, 12   # 0x271e
        C_ANDI           R2, 3   # 0x2722
        MOVI             R6, 0   # 0x2724
        C_BRA            L273a   # 0x2728
L272a:  LD_LOCAL         R3, 12   # 0x272a
        C_ADD            R1, R3   # 0x272e
        C_ADDI           R6, 1   # 0x2730
        SETP_NE_NP       P0, R3, R6, R3   # 0x2732
        BRA_PRED         4, L27d8   # 0x2736
L273a:  LD_LOCAL         R3, 28   # 0x273a
        SETP_LT_U_NPI    P0, R3, R3, 3   # 0x273e
        MOVI             R3, 0   # 0x2742
        BRA_PRED         0, L27a2   # 0x2746
L274a:  CHWIDTH_MULTI    40960, 1   # 0x274a
        C_CHWIDTH        R14, 0   # 0x274e
        ADD              R14, R1, R3, R1   # 0x2750
        C_SHLI           R14, 1   # 0x2754
        ADD              R14, R7, R14, R7   # 0x2756
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x275a
        SUB              R15, R15, R12, R15   # 0x275e
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x2762
        C_CHWIDTH        R15, 0   # 0x2766
        ADDI             R15, R14, 2   # 0x2768
        SZ_GLOBAL_LD_U16 R13, R0, R15, 0, 0   # 0x276c
        SUB              R13, R13, R12, R13   # 0x2770
        SZ_GLOBAL_ST_16  R13, R0, R15, 0, 0   # 0x2774
        ADDI             R15, R14, 4   # 0x2778
        SZ_GLOBAL_LD_U16 R13, R0, R15, 0, 0   # 0x277c
        SUB              R13, R13, R12, R13   # 0x2780
        SZ_GLOBAL_ST_16  R13, R0, R15, 0, 0   # 0x2784
        C_CHWIDTH        R15, 1   # 0x2788
        C_ADDI           R14, 6   # 0x278a
        SZ_GLOBAL_LD_U16 R15, R0, R14, 0, 0   # 0x278c
        SUB              R15, R15, R12, R15   # 0x2790
        SZ_GLOBAL_ST_16  R15, R0, R14, 0, 0   # 0x2794
        C_ADDI           R3, 4   # 0x2798
        SETP_NE_NP       P0, R14, R9, R3   # 0x279a
        BRA_PRED         0, L274a   # 0x279e
L27a2:  SETP_EQ_NPI      P0, R14, R2, 0   # 0x27a2
        BRA_PRED         0, L272a   # 0x27a6
        C_CHWIDTH        R14, 0   # 0x27aa
        C_ADD            R3, R1   # 0x27ac
        C_MOV            R14, R2   # 0x27ae
L27b0:  C_CHWIDTH        R13, 1   # 0x27b0
        C_CHWIDTH        R15, 0   # 0x27b2
        C_MOV            R15, R3   # 0x27b4
        C_SHLI           R15, 1   # 0x27b6
        ADD              R15, R7, R15, R7   # 0x27b8
        SZ_GLOBAL_LD_U16 R13, R0, R15, 0, 0   # 0x27bc
        SUB              R13, R13, R12, R13   # 0x27c0
        SZ_GLOBAL_ST_16  R13, R0, R15, 0, 0   # 0x27c4
        C_ADDI           R3, 1   # 0x27c8
        ADDI             R14, R14, -1   # 0x27ca
        SETP_NE_NPI      P0, R15, R14, 0   # 0x27ce
        BRA_PRED         0, L27b0   # 0x27d2
        C_BRA            L272a   # 0x27d6
L27d8:  CHWIDTH_MULTI    57632, 0   # 0x27d8
        LD_LOCAL         R1, 64   # 0x27dc
        MOVI             R2, 0   # 0x27e0
        CALL             R14, 129346   # 0x27e4
        C_MOV            R2, R1   # 0x27e8
        LD_LOCAL         R1, 68   # 0x27ea
        CALL             R14, 129341   # 0x27ee
        C_MOV            R2, R1   # 0x27f2
        C_MOV            R1, R10   # 0x27f4
        CALL             R14, 129337   # 0x27f6
        C_MOV            R2, R1   # 0x27fa
        C_MOV            R1, R8   # 0x27fc
        CALL             R14, 129333   # 0x27fe
        C_MOV            R2, R5   # 0x2802
        CALL             R14, 129330   # 0x2804
        LD_LOCAL         R14, 52   # 0x2808
        LD_LOCAL         R13, 92   # 0x280c
        LD_LOCAL         R12, 88   # 0x2810
        LD_LOCAL         R11, 84   # 0x2814
        LD_LOCAL         R10, 80   # 0x2818
        LD_LOCAL         R9, 76   # 0x281c
        LD_LOCAL         R8, 72   # 0x2820
        C_RET            224   # 0x2824
        CHWIDTH_MULTI    7, 1   # 0x2826
        XOR              R0, R2, R1, R2   # 0x282a
        CHWIDTH_MULTI    7, 0   # 0x282e
        C_ANDI           R0, 1   # 0x2832
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2834
        MOVI             R0, 40961   # 0x2838
        C_MOV            R7, R0   # 0x283c
        SHRI             R0, R2, 1   # 0x283e
        C_CHWIDTH        R2, 1   # 0x2842
        XOR              R2, R0, R7, R0   # 0x2844
        C_CHWIDTH        R2, 0   # 0x2848
        MOV_P            R0, 0, R2, R2, R2   # 0x284a
        C_CHWIDTH        R0, 1   # 0x284e
        SHRI             R2, R1, 1   # 0x2850
        C_CHWIDTH        R2, 1   # 0x2854
        XOR              R2, R2, R0, R2   # 0x2856
        CHWIDTH_MULTI    5, 0   # 0x285a
        C_ANDI           R2, 1   # 0x285e
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2860
        C_CHWIDTH        R2, 1   # 0x2864
        SHRI             R0, R0, 1   # 0x2866
        XOR              R2, R0, R7, R0   # 0x286a
        C_CHWIDTH        R2, 0   # 0x286e
        MOV_P            R0, 0, R2, R2, R2   # 0x2870
        C_CHWIDTH        R0, 1   # 0x2874
        SHRI             R2, R1, 2   # 0x2876
        C_CHWIDTH        R2, 1   # 0x287a
        XOR              R2, R2, R0, R2   # 0x287c
        CHWIDTH_MULTI    5, 0   # 0x2880
        C_ANDI           R2, 1   # 0x2884
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2886
        C_CHWIDTH        R2, 1   # 0x288a
        SHRI             R0, R0, 1   # 0x288c
        XOR              R2, R0, R7, R0   # 0x2890
        C_CHWIDTH        R2, 0   # 0x2894
        MOV_P            R0, 0, R2, R2, R2   # 0x2896
        C_CHWIDTH        R0, 1   # 0x289a
        SHRI             R2, R1, 3   # 0x289c
        C_CHWIDTH        R2, 1   # 0x28a0
        XOR              R2, R2, R0, R2   # 0x28a2
        CHWIDTH_MULTI    5, 0   # 0x28a6
        C_ANDI           R2, 1   # 0x28aa
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28ac
        C_CHWIDTH        R2, 1   # 0x28b0
        SHRI             R0, R0, 1   # 0x28b2
        XOR              R2, R0, R7, R0   # 0x28b6
        C_CHWIDTH        R2, 0   # 0x28ba
        MOV_P            R0, 0, R2, R2, R2   # 0x28bc
        C_CHWIDTH        R0, 1   # 0x28c0
        SHRI             R2, R1, 4   # 0x28c2
        C_CHWIDTH        R2, 1   # 0x28c6
        XOR              R2, R2, R0, R2   # 0x28c8
        CHWIDTH_MULTI    5, 0   # 0x28cc
        C_ANDI           R2, 1   # 0x28d0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28d2
        C_CHWIDTH        R2, 1   # 0x28d6
        SHRI             R0, R0, 1   # 0x28d8
        XOR              R2, R0, R7, R0   # 0x28dc
        C_CHWIDTH        R2, 0   # 0x28e0
        MOV_P            R0, 0, R2, R2, R2   # 0x28e2
        C_CHWIDTH        R0, 1   # 0x28e6
        SHRI             R2, R1, 5   # 0x28e8
        C_CHWIDTH        R2, 1   # 0x28ec
        XOR              R2, R2, R0, R2   # 0x28ee
        CHWIDTH_MULTI    5, 0   # 0x28f2
        C_ANDI           R2, 1   # 0x28f6
        SETP_NE_NPI      P0, R2, R2, 0   # 0x28f8
        C_CHWIDTH        R2, 1   # 0x28fc
        SHRI             R0, R0, 1   # 0x28fe
        XOR              R2, R0, R7, R0   # 0x2902
        C_CHWIDTH        R2, 0   # 0x2906
        MOV_P            R0, 0, R2, R2, R2   # 0x2908
        C_CHWIDTH        R0, 1   # 0x290c
        SHRI             R2, R1, 6   # 0x290e
        C_CHWIDTH        R2, 1   # 0x2912
        XOR              R2, R2, R0, R2   # 0x2914
        CHWIDTH_MULTI    5, 0   # 0x2918
        C_ANDI           R2, 1   # 0x291c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x291e
        C_CHWIDTH        R2, 1   # 0x2922
        SHRI             R0, R0, 1   # 0x2924
        XOR              R2, R0, R7, R0   # 0x2928
        C_CHWIDTH        R2, 0   # 0x292c
        MOV_P            R0, 0, R2, R2, R2   # 0x292e
        MOVI             R2, 128   # 0x2932
        C_CHWIDTH        R2, 1   # 0x2936
        AND              R2, R1, R2, R1   # 0x2938
        C_CHWIDTH        R2, 0   # 0x293c
        SHRI             R2, R2, 7   # 0x293e
        ANDI             R3, R0, 1   # 0x2942
        C_CHWIDTH        R0, 1   # 0x2946
        C_CHWIDTH        R0, 0   # 0x2948
        SETP_EQ_NP       P0, R2, R2, R3   # 0x294a
        C_CHWIDTH        R2, 1   # 0x294e
        SHRI             R0, R0, 1   # 0x2950
        XOR              R2, R0, R7, R0   # 0x2954
        C_CHWIDTH        R2, 0   # 0x2958
        MOV_P            R2, 0, R0, R0, R0   # 0x295a
        C_CHWIDTH        R2, 1   # 0x295e
        SHRI             R0, R1, 8   # 0x2960
        C_CHWIDTH        R0, 1   # 0x2964
        XOR              R0, R2, R0, R2   # 0x2966
        CHWIDTH_MULTI    5, 0   # 0x296a
        C_ANDI           R0, 1   # 0x296e
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2970
        SHRI             R0, R2, 1   # 0x2974
        C_CHWIDTH        R2, 1   # 0x2978
        XOR              R2, R0, R7, R0   # 0x297a
        C_CHWIDTH        R2, 0   # 0x297e
        MOV_P            R0, 0, R2, R2, R2   # 0x2980
        C_CHWIDTH        R0, 1   # 0x2984
        SHRI             R2, R1, 9   # 0x2986
        C_CHWIDTH        R2, 1   # 0x298a
        XOR              R2, R2, R0, R2   # 0x298c
        CHWIDTH_MULTI    5, 0   # 0x2990
        C_ANDI           R2, 1   # 0x2994
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2996
        C_CHWIDTH        R2, 1   # 0x299a
        SHRI             R0, R0, 1   # 0x299c
        XOR              R2, R0, R7, R0   # 0x29a0
        C_CHWIDTH        R2, 0   # 0x29a4
        MOV_P            R0, 0, R2, R2, R2   # 0x29a6
        C_CHWIDTH        R0, 1   # 0x29aa
        SHRI             R2, R1, 10   # 0x29ac
        C_CHWIDTH        R2, 1   # 0x29b0
        XOR              R2, R2, R0, R2   # 0x29b2
        CHWIDTH_MULTI    5, 0   # 0x29b6
        C_ANDI           R2, 1   # 0x29ba
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29bc
        C_CHWIDTH        R2, 1   # 0x29c0
        SHRI             R0, R0, 1   # 0x29c2
        XOR              R2, R0, R7, R0   # 0x29c6
        C_CHWIDTH        R2, 0   # 0x29ca
        MOV_P            R0, 0, R2, R2, R2   # 0x29cc
        C_CHWIDTH        R0, 1   # 0x29d0
        SHRI             R2, R1, 11   # 0x29d2
        C_CHWIDTH        R2, 1   # 0x29d6
        XOR              R2, R2, R0, R2   # 0x29d8
        CHWIDTH_MULTI    5, 0   # 0x29dc
        C_ANDI           R2, 1   # 0x29e0
        SETP_NE_NPI      P0, R2, R2, 0   # 0x29e2
        C_CHWIDTH        R2, 1   # 0x29e6
        SHRI             R0, R0, 1   # 0x29e8
        XOR              R2, R0, R7, R0   # 0x29ec
        C_CHWIDTH        R2, 0   # 0x29f0
        MOV_P            R0, 0, R2, R2, R2   # 0x29f2
        C_CHWIDTH        R0, 1   # 0x29f6
        SHRI             R2, R1, 12   # 0x29f8
        C_CHWIDTH        R2, 1   # 0x29fc
        XOR              R2, R2, R0, R2   # 0x29fe
        CHWIDTH_MULTI    5, 0   # 0x2a02
        C_ANDI           R2, 1   # 0x2a06
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a08
        C_CHWIDTH        R2, 1   # 0x2a0c
        SHRI             R0, R0, 1   # 0x2a0e
        XOR              R2, R0, R7, R0   # 0x2a12
        C_CHWIDTH        R2, 0   # 0x2a16
        MOV_P            R0, 0, R2, R2, R2   # 0x2a18
        C_CHWIDTH        R0, 1   # 0x2a1c
        SHRI             R2, R1, 13   # 0x2a1e
        C_CHWIDTH        R2, 1   # 0x2a22
        XOR              R2, R2, R0, R2   # 0x2a24
        CHWIDTH_MULTI    5, 0   # 0x2a28
        C_ANDI           R2, 1   # 0x2a2c
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a2e
        C_CHWIDTH        R2, 1   # 0x2a32
        SHRI             R0, R0, 1   # 0x2a34
        XOR              R2, R0, R7, R0   # 0x2a38
        C_CHWIDTH        R2, 0   # 0x2a3c
        MOV_P            R0, 0, R2, R2, R2   # 0x2a3e
        C_CHWIDTH        R0, 1   # 0x2a42
        SHRI             R2, R1, 14   # 0x2a44
        C_CHWIDTH        R2, 1   # 0x2a48
        XOR              R2, R2, R0, R2   # 0x2a4a
        CHWIDTH_MULTI    5, 0   # 0x2a4e
        C_ANDI           R2, 1   # 0x2a52
        SETP_NE_NPI      P0, R2, R2, 0   # 0x2a54
        C_CHWIDTH        R2, 1   # 0x2a58
        SHRI             R0, R0, 1   # 0x2a5a
        XOR              R2, R0, R7, R0   # 0x2a5e
        C_CHWIDTH        R2, 0   # 0x2a62
        MOV_P            R0, 0, R2, R2, R2   # 0x2a64
        SHRI             R1, R1, 15   # 0x2a68
        ANDI             R2, R0, 1   # 0x2a6c
        C_CHWIDTH        R0, 1   # 0x2a70
        C_CHWIDTH        R0, 0   # 0x2a72
        SETP_EQ_NP       P0, R1, R1, R2   # 0x2a74
        C_CHWIDTH        R1, 1   # 0x2a78
        SHRI             R0, R0, 1   # 0x2a7a
        XOR              R1, R0, R7, R0   # 0x2a7e
        C_CHWIDTH        R1, 0   # 0x2a82
        MOV_P            R1, 0, R0, R0, R0   # 0x2a84
        MOVI             R0, 65535   # 0x2a88
        C_AND            R1, R0   # 0x2a8c
        C_RET            224   # 0x2a8e
        MOVI             R15, 2   # 0x2a90
        LD_GLOBAL        R15, R15, 24   # 0x2a94
        SRD              R0, 3   # 0x2a98
        C_ADD            R15, R0   # 0x2a9a
        ST_LOCAL         R8, 196   # 0x2a9c
        C_CHWIDTH        R8, 1   # 0x2aa0
        ST_LOCAL         R9, 200   # 0x2aa2
        ST_LOCAL         R10, 204   # 0x2aa6
        ST_LOCAL         R11, 208   # 0x2aaa
        ST_LOCAL         R12, 212   # 0x2aae
        ST_LOCAL         R13, 216   # 0x2ab2
        ST_LOCAL         R14, 184   # 0x2ab6
        ST_LOCAL         R2, 120   # 0x2aba
        LD_GLOBAL_IDX    R0, R1, R2, 0, 60   # 0x2abe
        SHLI             R0, R0, 16   # 0x2ac2
        LD_GLOBAL_IDX    R5, R1, R2, 0, 56   # 0x2ac6
        SHRI             R4, R5, 16   # 0x2aca
        OR               R6, R0, R4, R0   # 0x2ace
        MOVI             R0, 65535   # 0x2ad2
        AND              R7, R5, R0, R5   # 0x2ad6
        ST_LOCAL         R1, 104   # 0x2ada
        SZ_GLOBAL_LD_U16 R8, R1, R2, 0, 4   # 0x2ade
        MOVI             R2, 0   # 0x2ae2
        C_MOV            R14, R3   # 0x2ae6
        C_CHWIDTH        R14, 1   # 0x2ae8
        CVT_SEXT         R3, R8, R8, R8   # 0x2aea
        SETP_LT_NPI      P0, R3, R3, 1   # 0x2aee
        BRA_PRED         0, L2e40   # 0x2af2
        C_CHWIDTH        R14, 0   # 0x2af6
        C_MOV            R12, R7   # 0x2af8
        C_CHWIDTH        R7, 1   # 0x2afa
        C_MOV            R1, R6   # 0x2afc
        ADDI             R7, R8, 255   # 0x2afe
        CHWIDTH_MULTI    384, 0   # 0x2b02
        ST_LOCAL         R7, 128   # 0x2b06
        MOVI             R4, 1   # 0x2b0a
        C_MOV            R7, R4   # 0x2b0e
        ST_LOCAL         R7, 108   # 0x2b10
        MOVI             R4, 255   # 0x2b14
        C_MOV            R6, R2   # 0x2b18
        ST_LOCAL         R2, 96   # 0x2b1a
        ST_LOCAL         R2, 116   # 0x2b1e
        ST_LOCAL         R14, 124   # 0x2b22
        C_MOV            R5, R14   # 0x2b26
        C_CHWIDTH        R5, 1   # 0x2b28
        ST_LOCAL         R8, 100   # 0x2b2a
        ST_LOCAL         R4, 112   # 0x2b2e
        C_BRA            L2bb6   # 0x2b32
L2b34:  C_CHWIDTH        R11, 1   # 0x2b34
        C_MOV            R7, R1   # 0x2b36
        C_MOV            R4, R12   # 0x2b38
        LD_GLOBAL_IDX    R3, R7, R4, 0, 0   # 0x2b3a
        LD_GLOBAL_IDX    R7, R7, R4, 0, 4   # 0x2b3e
        SHLI             R7, R7, 16   # 0x2b42
        SHRI             R14, R3, 16   # 0x2b46
        C_OR             R7, R14   # 0x2b4a
        C_AND            R3, R0   # 0x2b4c
        LD_GLOBAL_IDX    R14, R7, R3, 0, 8   # 0x2b4e
        LD_GLOBAL_IDX    R3, R7, R3, 0, 12   # 0x2b52
        SHLI             R3, R3, 16   # 0x2b56
        SHRI             R7, R14, 16   # 0x2b5a
        C_OR             R3, R7   # 0x2b5e
        AND              R7, R14, R0, R14   # 0x2b60
        C_CHWIDTH        R14, 1   # 0x2b64
        SZ_GLOBAL_LD_U16 R14, R3, R7, 0, 0   # 0x2b66
        C_CHWIDTH        R14, 0   # 0x2b6a
        SHRI             R3, R14, 8   # 0x2b6c
        LD_LOCAL         R14, 108   # 0x2b70
        AND              R11, R3, R14, R3   # 0x2b74
        LD_LOCAL         R14, 116   # 0x2b78
        C_CHWIDTH        R14, 1   # 0x2b7c
        ADDI             R14, R14, 1   # 0x2b7e
        C_CHWIDTH        R14, 0   # 0x2b82
        ST_LOCAL         R14, 116   # 0x2b84
L2b88:  CHWIDTH_MULTI    108, 1   # 0x2b88
        ADD              R6, R11, R6, R11   # 0x2b8c
        C_MOV            R14, R0   # 0x2b90
        XOR              R3, R5, R14, R5   # 0x2b92
        C_CHWIDTH        R3, 0   # 0x2b96
        SHRI             R3, R3, 15   # 0x2b98
        ADD              R5, R5, R3, R5   # 0x2b9c
        ADDI             R2, R2, 1   # 0x2ba0
        C_CHWIDTH        R2, 0   # 0x2ba4
        LD_LOCAL         R8, 100   # 0x2ba6
        SETP_NE_NP       P0, R3, R2, R8   # 0x2baa
        LD_LOCAL         R4, 112   # 0x2bae
        BRA_PRED         4, L2e08   # 0x2bb2
L2bb6:  C_CHWIDTH        R11, 0   # 0x2bb6
        C_MOV            R11, R1   # 0x2bb8
        SHLI             R7, R11, 16   # 0x2bba
        C_MOV            R9, R12   # 0x2bbe
        AND              R14, R7, R9, R7   # 0x2bc0
        ADD              R8, R7, R9, R7   # 0x2bc4
        C_OR             R7, R9   # 0x2bc8
        C_ANDN           R7, R8   # 0x2bca
        OR               R7, R14, R7, R14   # 0x2bcc
        SHRI             R7, R7, 31   # 0x2bd0
        SHRI             R14, R11, 16   # 0x2bd4
        ADD              R7, R14, R7, R14   # 0x2bd8
        OR               R10, R8, R7, R8   # 0x2bdc
        CVT_SEXT         R7, R5, R5, R5   # 0x2be0
        MOVI48           R3, 4294967295   # 0x2be4
        SETP_LT_NP       P0, R7, R3, R7   # 0x2bea
        BRA_PRED         4, L2c52   # 0x2bee
        MOVI             R8, 0   # 0x2bf2
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2bf6
        BRA_PRED         0, L2cb4   # 0x2bfa
        C_CHWIDTH        R5, 0   # 0x2bfe
        C_MOV            R11, R1   # 0x2c00
        C_MOV            R9, R12   # 0x2c02
L2c04:  LD_GLOBAL_IDX    R7, R11, R9, 0, 8   # 0x2c04
        LD_GLOBAL_IDX    R14, R11, R9, 0, 12   # 0x2c08
        SHLI             R14, R14, 16   # 0x2c0c
        SHRI             R3, R7, 16   # 0x2c10
        OR               R3, R14, R3, R14   # 0x2c14
        C_CHWIDTH        R14, 1   # 0x2c18
        C_AND            R7, R0   # 0x2c1a
        SZ_GLOBAL_LD_U16 R14, R3, R7, 0, 2   # 0x2c1c
        C_CHWIDTH        R14, 0   # 0x2c20
        SETP_EQ_NP       P0, R3, R14, R5   # 0x2c22
        BRA_PRED         0, L2d22   # 0x2c26
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2c2a
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2c2e
        SHRI             R14, R7, 16   # 0x2c32
        SHLI             R9, R3, 16   # 0x2c36
        OR               R11, R9, R14, R9   # 0x2c3a
        C_AND            R3, R0   # 0x2c3e
        OR               R3, R7, R3, R7   # 0x2c40
        AND              R9, R7, R0, R7   # 0x2c44
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c48
        BRA_PRED         4, L2c04   # 0x2c4c
        C_BRA            L2cb4   # 0x2c50
L2c52:  MOVI             R8, 0   # 0x2c52
        SETP_EQ_NPI      P0, R7, R10, 0   # 0x2c56
        BRA_PRED         0, L2cb4   # 0x2c5a
L2c5e:  LD_GLOBAL_IDX    R3, R11, R9, 0, 8   # 0x2c5e
        LD_GLOBAL_IDX    R7, R11, R9, 0, 12   # 0x2c62
        SHLI             R7, R7, 16   # 0x2c66
        SHRI             R14, R3, 16   # 0x2c6a
        C_OR             R7, R14   # 0x2c6e
        C_CHWIDTH        R14, 1   # 0x2c70
        C_AND            R3, R0   # 0x2c72
        SZ_GLOBAL_LD_U16 R14, R7, R3, 0, 0   # 0x2c74
        C_CHWIDTH        R3, 1   # 0x2c78
        XOR              R14, R14, R2, R14   # 0x2c7a
        AND              R3, R14, R4, R14   # 0x2c7e
        C_CHWIDTH        R3, 0   # 0x2c82
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x2c84
        BRA_PRED         0, L2d22   # 0x2c88
        C_CHWIDTH        R14, 0   # 0x2c8c
        LD_GLOBAL_IDX    R3, R11, R9, 0, 4   # 0x2c8e
        LD_GLOBAL_IDX    R7, R11, R9, 0, 0   # 0x2c92
        SHRI             R14, R7, 16   # 0x2c96
        SHLI             R9, R3, 16   # 0x2c9a
        OR               R11, R9, R14, R9   # 0x2c9e
        C_AND            R3, R0   # 0x2ca2
        OR               R3, R7, R3, R7   # 0x2ca4
        AND              R9, R7, R0, R7   # 0x2ca8
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2cac
        BRA_PRED         0, L2c5e   # 0x2cb0
L2cb4:  MOVI             R9, 0   # 0x2cb4
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2cb8
        BRA_PRED         0, L2d2e   # 0x2cbc
L2cc0:  MOVI             R10, 0   # 0x2cc0
        MOVI             R14, 0   # 0x2cc4
L2cc8:  C_MOV            R4, R12   # 0x2cc8
        C_MOV            R11, R1   # 0x2cca
        SHLI             R3, R10, 16   # 0x2ccc
        AND              R7, R3, R14, R3   # 0x2cd0
        ADD              R1, R3, R14, R3   # 0x2cd4
        C_OR             R3, R14   # 0x2cd8
        C_ANDN           R3, R1   # 0x2cda
        OR               R3, R7, R3, R7   # 0x2cdc
        SHRI             R3, R3, 31   # 0x2ce0
        SHRI             R7, R10, 16   # 0x2ce4
        ADD              R3, R7, R3, R7   # 0x2ce8
        LD_GLOBAL_IDX    R7, R11, R4, 0, 0   # 0x2cec
        ST_GLOBAL_IDX    R1, R11, R4, 0, 0   # 0x2cf0
        LD_GLOBAL_IDX    R14, R11, R4, 0, 4   # 0x2cf4
        ST_GLOBAL_IDX    R3, R11, R4, 0, 4   # 0x2cf8
        SHRI             R3, R7, 16   # 0x2cfc
        SHLI             R10, R14, 16   # 0x2d00
        OR               R1, R10, R3, R10   # 0x2d04
        AND              R3, R14, R0, R14   # 0x2d08
        OR               R3, R7, R3, R7   # 0x2d0c
        AND              R12, R7, R0, R7   # 0x2d10
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d14
        C_MOV            R10, R11   # 0x2d18
        C_MOV            R14, R4   # 0x2d1a
        BRA_PRED         0, L2cc8   # 0x2d1c
        C_BRA            L2d36   # 0x2d20
L2d22:  C_CHWIDTH        R14, 0   # 0x2d22
        C_MOV            R8, R11   # 0x2d24
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2d26
        BRA_PRED         4, L2cc0   # 0x2d2a
L2d2e:  MOVI             R11, 0   # 0x2d2e
        MOVI             R4, 0   # 0x2d32
L2d36:  C_MOV            R12, R4   # 0x2d36
        C_MOV            R1, R11   # 0x2d38
        SHLI             R3, R8, 16   # 0x2d3a
        AND              R7, R3, R9, R3   # 0x2d3e
        ADD              R14, R3, R9, R3   # 0x2d42
        C_OR             R3, R9   # 0x2d46
        C_ANDN           R3, R14   # 0x2d48
        OR               R3, R7, R3, R7   # 0x2d4a
        SHRI             R3, R3, 31   # 0x2d4e
        SHRI             R7, R8, 16   # 0x2d52
        ADD              R3, R7, R3, R7   # 0x2d56
        OR               R3, R14, R3, R14   # 0x2d5a
        SETP_NE_NPI      P0, R3, R3, 0   # 0x2d5e
        BRA_PRED         4, L2b34   # 0x2d62
        CHWIDTH_MULTI    3072, 1   # 0x2d66
        LD_GLOBAL_IDX    R3, R8, R9, 0, 12   # 0x2d6a
        SHLI             R3, R3, 16   # 0x2d6e
        LD_GLOBAL_IDX    R7, R8, R9, 0, 8   # 0x2d72
        SHRI             R14, R7, 16   # 0x2d76
        C_OR             R3, R14   # 0x2d7a
        C_AND            R7, R0   # 0x2d7c
        SZ_GLOBAL_LD_U16 R10, R3, R7, 0, 0   # 0x2d7e
        C_CHWIDTH        R10, 0   # 0x2d82
        LD_GLOBAL_IDX    R14, R8, R9, 0, 4   # 0x2d84
        LD_GLOBAL_IDX    R7, R8, R9, 0, 0   # 0x2d88
        SHRI             R3, R10, 9   # 0x2d8c
        C_CHWIDTH        R3, 1   # 0x2d90
        AND              R3, R10, R3, R10   # 0x2d92
        AND              R10, R14, R0, R14   # 0x2d96
        OR               R10, R7, R10, R7   # 0x2d9a
        LD_LOCAL         R4, 108   # 0x2d9e
        AND              R11, R3, R4, R3   # 0x2da2
        C_CHWIDTH        R3, 0   # 0x2da6
        LD_LOCAL         R3, 96   # 0x2da8
        C_CHWIDTH        R3, 1   # 0x2dac
        ADDI             R3, R3, 1   # 0x2dae
        C_CHWIDTH        R3, 0   # 0x2db2
        ST_LOCAL         R3, 96   # 0x2db4
        SETP_EQ_NPI      P0, R3, R10, 0   # 0x2db8
        BRA_PRED         0, L2b88   # 0x2dbc
        SHRI             R3, R7, 16   # 0x2dc0
        SHLI             R14, R14, 16   # 0x2dc4
        OR               R3, R14, R3, R14   # 0x2dc8
        C_AND            R7, R0   # 0x2dcc
        LD_GLOBAL_IDX    R14, R3, R7, 0, 0   # 0x2dce
        SZ_GLOBAL_LD_U16 R10, R3, R7, 0, 4   # 0x2dd2
        ST_GLOBAL_IDX    R10, R8, R9, 0, 4   # 0x2dd6
        ST_GLOBAL_IDX    R14, R8, R9, 0, 0   # 0x2dda
        C_MOV            R9, R1   # 0x2dde
        C_MOV            R4, R12   # 0x2de0
        LD_GLOBAL_IDX    R14, R9, R4, 0, 0   # 0x2de2
        SZ_GLOBAL_LD_U16 R8, R9, R4, 0, 4   # 0x2de6
        ST_GLOBAL_IDX    R8, R3, R7, 0, 4   # 0x2dea
        ST_GLOBAL_IDX    R14, R3, R7, 0, 0   # 0x2dee
        SHRI             R14, R3, 16   # 0x2df2
        ST_GLOBAL_IDX    R14, R9, R4, 0, 4   # 0x2df6
        SHLI             R3, R3, 16   # 0x2dfa
        C_OR             R3, R7   # 0x2dfe
        ST_GLOBAL_IDX    R3, R9, R4, 0, 0   # 0x2e00
        BRA              L2b88   # 0x2e04
L2e08:  C_CHWIDTH        R5, 0   # 0x2e08
        C_CHWIDTH        R2, 1   # 0x2e0a
        MOVI             R0, 255   # 0x2e0c
        LD_LOCAL         R14, 128   # 0x2e10
        AND              R2, R14, R0, R14   # 0x2e14
        C_CHWIDTH        R2, 0   # 0x2e18
        LD_LOCAL         R0, 96   # 0x2e1a
        SHLI             R0, R0, 2   # 0x2e1e
        LD_LOCAL         R14, 116   # 0x2e22
        C_CHWIDTH        R14, 1   # 0x2e26
        SUB              R14, R0, R14, R0   # 0x2e28
        C_CHWIDTH        R0, 1   # 0x2e2c
        ADD              R0, R14, R6, R14   # 0x2e2e
        CHWIDTH_MULTI    16449, 0   # 0x2e32
        C_MOV            R6, R1   # 0x2e36
        C_MOV            R7, R12   # 0x2e38
        LD_LOCAL         R14, 124   # 0x2e3a
        C_BRA            L2e46   # 0x2e3e
L2e40:  C_CHWIDTH        R14, 0   # 0x2e40
        C_MOV            R5, R14   # 0x2e42
        C_MOV            R0, R2   # 0x2e44
L2e46:  C_CHWIDTH        R14, 1   # 0x2e46
        ST_LOCAL         R5, 188   # 0x2e48
        ST_LOCAL         R0, 180   # 0x2e4c
        CVT_SEXT         R0, R14, R14, R14   # 0x2e50
        SETP_LT_NPI      P0, R0, R0, 1   # 0x2e54
        ST_LOCAL         R2, 192   # 0x2e58
        BRA_PRED         0, L348c   # 0x2e5c
        CHWIDTH_MULTI    18432, 0   # 0x2e60
        MOVI             R0, 1   # 0x2e64
        ST_LOCAL         R0, 168   # 0x2e68
        MOVI             R12, 65535   # 0x2e6c
        MOVI             R0, 128   # 0x2e70
        C_MOV            R14, R0   # 0x2e74
        ST_LOCAL         R14, 108   # 0x2e76
        MOVI             R0, 7   # 0x2e7a
        C_MOV            R14, R0   # 0x2e7e
        ST_LOCAL         R14, 128   # 0x2e80
        MOVI             R0, 15   # 0x2e84
        C_MOV            R14, R0   # 0x2e88
        ST_LOCAL         R14, 132   # 0x2e8a
        MOVI             R0, 127   # 0x2e8e
        C_MOV            R14, R0   # 0x2e92
        ST_LOCAL         R14, 112   # 0x2e94
        MOVI             R0, 65280   # 0x2e98
        C_MOV            R14, R0   # 0x2e9c
        ST_LOCAL         R14, 136   # 0x2e9e
        C_BRA            L2ed2   # 0x2ea2
L2ea4:  MOVI             R0, 0   # 0x2ea4
        ST_GLOBAL_IDX    R0, R10, R11, 0, 4   # 0x2ea8
        ST_GLOBAL_IDX    R0, R10, R11, 0, 0   # 0x2eac
        LD_LOCAL         R0, 168   # 0x2eb0
        C_SHLI           R0, 1   # 0x2eb4
        ST_LOCAL         R0, 168   # 0x2eb6
        LD_LOCAL         R0, 176   # 0x2eba
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2ebe
        LD_LOCAL         R8, 164   # 0x2ec2
        C_MOV            R6, R8   # 0x2ec6
        LD_LOCAL         R9, 160   # 0x2ec8
        C_MOV            R7, R9   # 0x2ecc
        BRA_PRED         4, L3492   # 0x2ece
L2ed2:  MOVI             R5, 0   # 0x2ed2
        MOVI             R10, 0   # 0x2ed6
        MOVI             R11, 0   # 0x2eda
        MOVI             R0, 0   # 0x2ede
        ST_LOCAL         R0, 164   # 0x2ee2
        ST_LOCAL         R0, 160   # 0x2ee6
        C_BRA            L2efa   # 0x2eea
L2eec:  C_CHWIDTH        R8, 0   # 0x2eec
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2eee
        LD_LOCAL         R5, 172   # 0x2ef2
        BRA_PRED         0, L2ea4   # 0x2ef6
L2efa:  LD_LOCAL         R4, 168   # 0x2efa
        SETP_LT_NPI      P0, R0, R4, 1   # 0x2efe
        BRA_PRED         0, L2f40   # 0x2f02
        MOVI             R2, 0   # 0x2f06
        C_MOV            R0, R6   # 0x2f0a
        C_MOV            R1, R7   # 0x2f0c
L2f0e:  LD_GLOBAL_IDX    R3, R0, R1, 0, 4   # 0x2f0e
        LD_GLOBAL_IDX    R1, R0, R1, 0, 0   # 0x2f12
        AND              R0, R3, R12, R3   # 0x2f16
        OR               R0, R1, R0, R1   # 0x2f1a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x2f1e
        BRA_PRED         4, L2f4a   # 0x2f22
        SHRI             R0, R1, 16   # 0x2f26
        SHLI             R3, R3, 16   # 0x2f2a
        OR               R0, R3, R0, R3   # 0x2f2e
        C_AND            R1, R12   # 0x2f32
        C_ADDI           R2, 1   # 0x2f34
        SETP_EQ_NP       P0, R3, R4, R2   # 0x2f36
        BRA_PRED         4, L2f0e   # 0x2f3a
        C_BRA            L2f56   # 0x2f3e
L2f40:  MOVI             R4, 0   # 0x2f40
        C_MOV            R0, R6   # 0x2f44
        C_MOV            R1, R7   # 0x2f46
        C_BRA            L2f56   # 0x2f48
L2f4a:  MOVI             R0, 0   # 0x2f4a
        ADDI             R4, R2, 1   # 0x2f4e
        MOVI             R1, 0   # 0x2f52
L2f56:  ST_LOCAL         R5, 176   # 0x2f56
        ADDI             R2, R5, 1   # 0x2f5a
        ST_LOCAL         R2, 172   # 0x2f5e
        C_MOV            R9, R6   # 0x2f62
        C_MOV            R13, R7   # 0x2f64
        C_MOV            R6, R0   # 0x2f66
        C_MOV            R7, R1   # 0x2f68
        LD_LOCAL         R0, 168   # 0x2f6a
        ST_LOCAL         R0, 100   # 0x2f6e
        C_BRA            L2f8c   # 0x2f72
L2f74:  ST_LOCAL         R4, 164   # 0x2f74
        ST_LOCAL         R5, 160   # 0x2f78
L2f7c:  C_MOV            R9, R1   # 0x2f7c
        C_MOV            R13, R3   # 0x2f7e
        C_MOV            R6, R0   # 0x2f80
        C_MOV            R7, R2   # 0x2f82
        C_MOV            R10, R4   # 0x2f84
        C_MOV            R11, R5   # 0x2f86
        LD_LOCAL         R4, 96   # 0x2f88
L2f8c:  MOVI             R0, 0   # 0x2f8c
        SETP_LT_NP       P0, R0, R0, R4   # 0x2f90
        BRA_PRED         0, L2fd0   # 0x2f94
        SHLI             R0, R6, 16   # 0x2f98
        AND              R1, R0, R7, R0   # 0x2f9c
        ADD              R2, R0, R7, R0   # 0x2fa0
        C_OR             R0, R7   # 0x2fa4
        C_ANDN           R0, R2   # 0x2fa6
        OR               R0, R1, R0, R1   # 0x2fa8
        SHRI             R0, R0, 31   # 0x2fac
        SHRI             R1, R6, 16   # 0x2fb0
        ADD              R0, R1, R0, R1   # 0x2fb4
        OR               R0, R2, R0, R2   # 0x2fb8
        LD_LOCAL         R1, 100   # 0x2fbc
        SETP_LT_NPI      P0, R1, R1, 1   # 0x2fc0
        BRA_PRED         0, L2eec   # 0x2fc4
        SETP_EQ_NPI      P0, R1, R0, 0   # 0x2fc8
        BRA_PRED         0, L2eec   # 0x2fcc
L2fd0:  SETP_NE_NPI      P0, R0, R4, 0   # 0x2fd0
        BRA_PRED         4, L311c   # 0x2fd4
        LD_LOCAL         R0, 100   # 0x2fd8
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x2fdc
        BRA_PRED         0, L3152   # 0x2fe0
        SHLI             R0, R6, 16   # 0x2fe4
        AND              R1, R0, R7, R0   # 0x2fe8
        ADD              R2, R0, R7, R0   # 0x2fec
        C_OR             R0, R7   # 0x2ff0
        C_ANDN           R0, R2   # 0x2ff2
        OR               R0, R1, R0, R1   # 0x2ff4
        SHRI             R0, R0, 31   # 0x2ff8
        SHRI             R1, R6, 16   # 0x2ffc
        ADD              R0, R1, R0, R1   # 0x3000
        OR               R0, R2, R0, R2   # 0x3004
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3008
        BRA_PRED         4, L3152   # 0x300c
        LD_GLOBAL_IDX    R3, R6, R7, 0, 8   # 0x3010
        ST_LOCAL         R7, 116   # 0x3014
        LD_GLOBAL_IDX    R5, R6, R7, 0, 12   # 0x3018
        LD_GLOBAL_IDX    R0, R9, R13, 0, 8   # 0x301c
        LD_GLOBAL_IDX    R1, R9, R13, 0, 12   # 0x3020
        SHLI             R1, R1, 16   # 0x3024
        SHRI             R2, R0, 16   # 0x3028
        C_OR             R1, R2   # 0x302c
        AND              R2, R0, R12, R0   # 0x302e
        CHWIDTH_MULTI    4097, 1   # 0x3032
        SZ_GLOBAL_LD_U16 R12, R1, R2, 0, 0   # 0x3036
        LD_LOCAL         R7, 108   # 0x303a
        AND              R0, R12, R7, R12   # 0x303e
        C_CHWIDTH        R0, 0   # 0x3042
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3044
        ST_LOCAL         R4, 96   # 0x3048
        BRA_PRED         4, L3178   # 0x304c
        C_CHWIDTH        R0, 1   # 0x3050
        ST_LOCAL         R2, 152   # 0x3052
        ST_LOCAL         R1, 148   # 0x3056
        ST_LOCAL         R5, 144   # 0x305a
        ST_LOCAL         R3, 140   # 0x305e
        LD_LOCAL         R14, 128   # 0x3062
        AND              R0, R12, R14, R12   # 0x3066
        CHWIDTH_MULTI    4097, 0   # 0x306a
        SHRI             R1, R12, 3   # 0x306e
        C_CHWIDTH        R1, 1   # 0x3072
        LD_LOCAL         R14, 132   # 0x3074
        AND              R1, R1, R14, R1   # 0x3078
        C_CHWIDTH        R1, 0   # 0x307c
        MULI             R1, R1, 17   # 0x307e
        C_MOV            R3, R1   # 0x3082
        C_CHWIDTH        R3, 1   # 0x3084
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x3086
        BRA_PRED         0, L3184   # 0x308a
        SETP_NE_NPI      P0, R0, R0, 0   # 0x308e
        C_MOV            R4, R12   # 0x3092
        BRA_PRED         0, L31cc   # 0x3094
        CHWIDTH_MULTI    264, 0   # 0x3098
        ST_LOCAL         R13, 156   # 0x309c
        ST_LOCAL         R6, 124   # 0x30a0
        MOVI             R0, 34   # 0x30a4
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x30a8
        MOVI             R6, 34   # 0x30ac
        MOV_P            R6, 0, R3, R3, R3   # 0x30b0
        LD_LOCAL         R13, 104   # 0x30b4
        LD_LOCAL         R8, 120   # 0x30b8
        SZ_GLOBAL_LD_U16 R5, R13, R8, 0, 2   # 0x30bc
        SZ_GLOBAL_LD_U16 R4, R13, R8, 0, 0   # 0x30c0
        LD_GLOBAL_IDX    R1, R13, R8, 0, 40   # 0x30c4
        LD_GLOBAL_IDX    R0, R13, R8, 0, 32   # 0x30c8
        LD_GLOBAL_IDX    R2, R13, R8, 0, 36   # 0x30cc
        SZ_GLOBAL_LD_U16 R3, R13, R8, 0, 96   # 0x30d0
        ST_GLOBAL        R3, R15, 32   # 0x30d4
        SHLI             R2, R2, 16   # 0x30d8
        SHRI             R3, R0, 16   # 0x30dc
        C_OR             R2, R3   # 0x30e0
        MOVI             R3, 65535   # 0x30e2
        AND              R3, R0, R3, R0   # 0x30e6
        CALL             R14, 127167   # 0x30ea
        C_CHWIDTH        R0, 1   # 0x30ee
        MOVI             R15, 2   # 0x30f0
        LD_GLOBAL        R15, R15, 24   # 0x30f4
        SRD              R3, 3   # 0x30f8
        C_ADD            R15, R3   # 0x30fa
        SZ_GLOBAL_LD_U16 R0, R13, R8, 0, 102   # 0x30fc
        C_CHWIDTH        R0, 0   # 0x3100
        C_MOV            R4, R1   # 0x3102
        C_CHWIDTH        R4, 1   # 0x3104
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3106
        BRA_PRED         0, L3112   # 0x310a
        SZ_GLOBAL_ST_16  R4, R13, R8, 0, 102   # 0x310e
L3112:  LD_LOCAL         R6, 124   # 0x3112
        LD_LOCAL         R13, 156   # 0x3116
        C_BRA            L31cc   # 0x311a
L311c:  LD_GLOBAL_IDX    R1, R6, R7, 0, 0   # 0x311c
        LD_GLOBAL_IDX    R0, R6, R7, 0, 4   # 0x3120
        SHLI             R0, R0, 16   # 0x3124
        SHRI             R2, R1, 16   # 0x3128
        C_OR             R0, R2   # 0x312c
        AND              R2, R1, R12, R1   # 0x312e
        MOVI             R1, 0   # 0x3132
        ST_LOCAL         R1, 96   # 0x3136
        LD_LOCAL         R1, 100   # 0x313a
        ADDI             R1, R1, -1   # 0x313e
        ST_LOCAL         R1, 100   # 0x3142
        C_MOV            R1, R9   # 0x3146
        C_MOV            R3, R13   # 0x3148
        C_MOV            R4, R6   # 0x314a
        C_MOV            R5, R7   # 0x314c
        BRA              L3432   # 0x314e
L3152:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x3152
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x3156
        SHLI             R1, R1, 16   # 0x315a
        SHRI             R2, R0, 16   # 0x315e
        C_OR             R1, R2   # 0x3162
        AND              R3, R0, R12, R0   # 0x3164
        ADDI             R4, R4, -1   # 0x3168
        ST_LOCAL         R4, 96   # 0x316c
        C_MOV            R0, R6   # 0x3170
        C_MOV            R2, R7   # 0x3172
        BRA              L342e   # 0x3174
L3178:  C_CHWIDTH        R2, 1   # 0x3178
        LD_LOCAL         R14, 112   # 0x317a
        AND              R2, R12, R14, R12   # 0x317e
        C_BRA            L322a   # 0x3182
L3184:  CHWIDTH_MULTI    264, 0   # 0x3184
        ST_LOCAL         R6, 124   # 0x3188
        LD_LOCAL         R1, 104   # 0x318c
        LD_LOCAL         R8, 120   # 0x3190
        SZ_GLOBAL_LD_U16 R4, R1, R8, 0, 96   # 0x3194
        ADDI             R2, R8, 64   # 0x3198
        CALL             R14, 128411   # 0x319c
        C_CHWIDTH        R0, 1   # 0x31a0
        MOVI             R15, 2   # 0x31a2
        LD_GLOBAL        R15, R15, 24   # 0x31a6
        SRD              R3, 3   # 0x31aa
        C_ADD            R15, R3   # 0x31ac
        LD_LOCAL         R3, 104   # 0x31ae
        SZ_GLOBAL_LD_U16 R0, R3, R8, 0, 100   # 0x31b2
        C_CHWIDTH        R0, 0   # 0x31b6
        C_MOV            R4, R1   # 0x31b8
        C_CHWIDTH        R4, 1   # 0x31ba
        SETP_NE_NPI      P0, R0, R0, 0   # 0x31bc
        BRA_PRED         0, L31c8   # 0x31c0
        SZ_GLOBAL_ST_16  R4, R3, R8, 0, 100   # 0x31c4
L31c8:  LD_LOCAL         R6, 124   # 0x31c8
L31cc:  CHWIDTH_MULTI    280, 0   # 0x31cc
        LD_LOCAL         R5, 120   # 0x31d0
        LD_LOCAL         R8, 104   # 0x31d4
        SZ_GLOBAL_LD_U16 R2, R8, R5, 0, 96   # 0x31d8
        C_MOV            R1, R4   # 0x31dc
        CALL             R14, 129826   # 0x31de
        C_CHWIDTH        R2, 1   # 0x31e2
        MOVI             R15, 2   # 0x31e4
        LD_GLOBAL        R15, R15, 24   # 0x31e8
        SRD              R3, 3   # 0x31ec
        C_ADD            R15, R3   # 0x31ee
        SZ_GLOBAL_ST_16  R1, R8, R5, 0, 96   # 0x31f0
        LD_LOCAL         R14, 112   # 0x31f4
        AND              R2, R4, R14, R4   # 0x31f8
        LD_LOCAL         R14, 136   # 0x31fc
        C_CHWIDTH        R14, 1   # 0x3200
        AND              R14, R12, R14, R12   # 0x3202
        OR               R14, R14, R2, R14   # 0x3206
        LD_LOCAL         R7, 108   # 0x320a
        OR               R14, R14, R7, R14   # 0x320e
        LD_LOCAL         R0, 148   # 0x3212
        LD_LOCAL         R1, 152   # 0x3216
        SZ_GLOBAL_ST_16  R14, R0, R1, 0, 0   # 0x321a
        LD_LOCAL         R4, 96   # 0x321e
        LD_LOCAL         R3, 140   # 0x3222
        LD_LOCAL         R5, 144   # 0x3226
L322a:  C_CHWIDTH        R12, 1   # 0x322a
        SHLI             R0, R5, 16   # 0x322c
        SHRI             R1, R3, 16   # 0x3230
        OR               R1, R0, R1, R0   # 0x3234
        MOVI             R0, 65535   # 0x3238
        C_AND            R3, R0   # 0x323c
        C_CHWIDTH        R0, 1   # 0x323e
        SZ_GLOBAL_LD_U16 R12, R1, R3, 0, 0   # 0x3240
        AND              R0, R12, R7, R12   # 0x3244
        C_CHWIDTH        R0, 0   # 0x3248
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x324a
        BRA_PRED         4, L331e   # 0x324e
        C_CHWIDTH        R0, 1   # 0x3252
        CHWIDTH_MULTI    16388, 0   # 0x3254
        ST_LOCAL         R3, 148   # 0x3258
        ST_LOCAL         R1, 144   # 0x325c
        ST_LOCAL         R2, 140   # 0x3260
        LD_LOCAL         R14, 128   # 0x3264
        AND              R0, R12, R14, R12   # 0x3268
        CHWIDTH_MULTI    4097, 0   # 0x326c
        SHRI             R1, R12, 3   # 0x3270
        C_CHWIDTH        R1, 1   # 0x3274
        LD_LOCAL         R14, 132   # 0x3276
        AND              R1, R1, R14, R1   # 0x327a
        C_CHWIDTH        R1, 0   # 0x327e
        MULI             R1, R1, 17   # 0x3280
        C_MOV            R3, R1   # 0x3284
        C_CHWIDTH        R3, 1   # 0x3286
        SETP_EQ_NPI      P0, R1, R0, 1   # 0x3288
        BRA_PRED         0, L332c   # 0x328c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3290
        C_MOV            R4, R12   # 0x3294
        BRA_PRED         0, L3374   # 0x3296
        CHWIDTH_MULTI    264, 0   # 0x329a
        ST_LOCAL         R9, 152   # 0x329e
        ST_LOCAL         R6, 124   # 0x32a2
        MOVI             R0, 34   # 0x32a6
        SETP_LT_U_NP     P0, R0, R0, R3   # 0x32aa
        MOVI             R6, 34   # 0x32ae
        MOV_P            R6, 0, R3, R3, R3   # 0x32b2
        LD_LOCAL         R9, 104   # 0x32b6
        LD_LOCAL         R8, 120   # 0x32ba
        SZ_GLOBAL_LD_U16 R5, R9, R8, 0, 2   # 0x32be
        SZ_GLOBAL_LD_U16 R4, R9, R8, 0, 0   # 0x32c2
        LD_GLOBAL_IDX    R1, R9, R8, 0, 40   # 0x32c6
        LD_GLOBAL_IDX    R0, R9, R8, 0, 32   # 0x32ca
        LD_GLOBAL_IDX    R2, R9, R8, 0, 36   # 0x32ce
        SZ_GLOBAL_LD_U16 R3, R9, R8, 0, 96   # 0x32d2
        ST_GLOBAL        R3, R15, 32   # 0x32d6
        SHLI             R2, R2, 16   # 0x32da
        SHRI             R3, R0, 16   # 0x32de
        C_OR             R2, R3   # 0x32e2
        MOVI             R3, 65535   # 0x32e4
        AND              R3, R0, R3, R0   # 0x32e8
        CALL             R14, 126910   # 0x32ec
        C_CHWIDTH        R0, 1   # 0x32f0
        MOVI             R15, 2   # 0x32f2
        LD_GLOBAL        R15, R15, 24   # 0x32f6
        SRD              R3, 3   # 0x32fa
        C_ADD            R15, R3   # 0x32fc
        SZ_GLOBAL_LD_U16 R0, R9, R8, 0, 102   # 0x32fe
        C_CHWIDTH        R0, 0   # 0x3302
        C_MOV            R4, R1   # 0x3304
        C_CHWIDTH        R4, 1   # 0x3306
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3308
        BRA_PRED         0, L3314   # 0x330c
        SZ_GLOBAL_ST_16  R4, R9, R8, 0, 102   # 0x3310
L3314:  LD_LOCAL         R6, 124   # 0x3314
        LD_LOCAL         R9, 152   # 0x3318
        C_BRA            L3374   # 0x331c
L331e:  C_CHWIDTH        R0, 1   # 0x331e
        C_CHWIDTH        R14, 0   # 0x3320
        LD_LOCAL         R14, 112   # 0x3322
        AND              R0, R12, R14, R12   # 0x3326
        C_BRA            L33ce   # 0x332a
L332c:  CHWIDTH_MULTI    264, 0   # 0x332c
        ST_LOCAL         R6, 124   # 0x3330
        LD_LOCAL         R1, 104   # 0x3334
        LD_LOCAL         R8, 120   # 0x3338
        SZ_GLOBAL_LD_U16 R4, R1, R8, 0, 96   # 0x333c
        ADDI             R2, R8, 64   # 0x3340
        CALL             R14, 128199   # 0x3344
        C_CHWIDTH        R0, 1   # 0x3348
        MOVI             R15, 2   # 0x334a
        LD_GLOBAL        R15, R15, 24   # 0x334e
        SRD              R3, 3   # 0x3352
        C_ADD            R15, R3   # 0x3354
        LD_LOCAL         R3, 104   # 0x3356
        SZ_GLOBAL_LD_U16 R0, R3, R8, 0, 100   # 0x335a
        C_CHWIDTH        R0, 0   # 0x335e
        C_MOV            R4, R1   # 0x3360
        C_CHWIDTH        R4, 1   # 0x3362
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3364
        BRA_PRED         0, L3370   # 0x3368
        SZ_GLOBAL_ST_16  R4, R3, R8, 0, 100   # 0x336c
L3370:  LD_LOCAL         R6, 124   # 0x3370
L3374:  CHWIDTH_MULTI    280, 0   # 0x3374
        LD_LOCAL         R5, 120   # 0x3378
        LD_LOCAL         R8, 104   # 0x337c
        SZ_GLOBAL_LD_U16 R2, R8, R5, 0, 96   # 0x3380
        C_MOV            R1, R4   # 0x3384
        CALL             R14, 129614   # 0x3386
        C_CHWIDTH        R0, 1   # 0x338a
        MOVI             R15, 2   # 0x338c
        LD_GLOBAL        R15, R15, 24   # 0x3390
        SRD              R3, 3   # 0x3394
        C_ADD            R15, R3   # 0x3396
        SZ_GLOBAL_ST_16  R1, R8, R5, 0, 96   # 0x3398
        LD_LOCAL         R14, 112   # 0x339c
        AND              R0, R4, R14, R4   # 0x33a0
        LD_LOCAL         R14, 136   # 0x33a4
        C_CHWIDTH        R14, 1   # 0x33a8
        AND              R14, R12, R14, R12   # 0x33aa
        OR               R14, R14, R0, R14   # 0x33ae
        LD_LOCAL         R7, 108   # 0x33b2
        OR               R14, R14, R7, R14   # 0x33b6
        LD_LOCAL         R1, 144   # 0x33ba
        LD_LOCAL         R2, 148   # 0x33be
        SZ_GLOBAL_ST_16  R14, R1, R2, 0, 0   # 0x33c2
        LD_LOCAL         R4, 96   # 0x33c6
        LD_LOCAL         R2, 140   # 0x33ca
L33ce:  CHWIDTH_MULTI    4101, 0   # 0x33ce
        SETP_LT_U_NP     P0, R0, R0, R2   # 0x33d2
        LD_LOCAL         R5, 116   # 0x33d6
        MOVI             R12, 65535   # 0x33da
        BRA_PRED         4, L340c   # 0x33de
        LD_GLOBAL_IDX    R1, R6, R5, 0, 0   # 0x33e2
        LD_GLOBAL_IDX    R0, R6, R5, 0, 4   # 0x33e6
        SHLI             R0, R0, 16   # 0x33ea
        SHRI             R2, R1, 16   # 0x33ee
        C_OR             R0, R2   # 0x33f2
        AND              R2, R1, R12, R1   # 0x33f4
        LD_LOCAL         R1, 100   # 0x33f8
        ADDI             R1, R1, -1   # 0x33fc
        ST_LOCAL         R1, 100   # 0x3400
        C_MOV            R1, R9   # 0x3404
        C_MOV            R3, R13   # 0x3406
        C_MOV            R4, R6   # 0x3408
        C_BRA            L3432   # 0x340a
L340c:  LD_GLOBAL_IDX    R0, R9, R13, 0, 0   # 0x340c
        LD_GLOBAL_IDX    R1, R9, R13, 0, 4   # 0x3410
        SHLI             R1, R1, 16   # 0x3414
        SHRI             R2, R0, 16   # 0x3418
        C_OR             R1, R2   # 0x341c
        AND              R3, R0, R12, R0   # 0x341e
        ADDI             R4, R4, -1   # 0x3422
        ST_LOCAL         R4, 96   # 0x3426
        C_MOV            R0, R6   # 0x342a
        C_MOV            R2, R5   # 0x342c
L342e:  C_MOV            R4, R9   # 0x342e
        C_MOV            R5, R13   # 0x3430
L3432:  C_CHWIDTH        R14, 0   # 0x3432
        SHLI             R6, R10, 16   # 0x3434
        AND              R7, R6, R11, R6   # 0x3438
        ADD              R14, R6, R11, R6   # 0x343c
        C_OR             R6, R11   # 0x3440
        C_ANDN           R6, R14   # 0x3442
        OR               R6, R7, R6, R7   # 0x3444
        SHRI             R6, R6, 31   # 0x3448
        SHRI             R7, R10, 16   # 0x344c
        ADD              R6, R7, R6, R7   # 0x3450
        OR               R6, R14, R6, R14   # 0x3454
        SETP_EQ_NPI      P0, R6, R6, 0   # 0x3458
        BRA_PRED         0, L2f74   # 0x345c
        SHLI             R6, R4, 16   # 0x3460
        ADD              R7, R6, R5, R6   # 0x3464
        ST_GLOBAL_IDX    R7, R10, R11, 0, 0   # 0x3468
        OR               R14, R6, R5, R6   # 0x346c
        ANDN             R7, R14, R7, R14   # 0x3470
        C_AND            R6, R5   # 0x3474
        C_OR             R6, R7   # 0x3476
        SHRI             R6, R6, 31   # 0x3478
        SHRI             R7, R4, 16   # 0x347c
        ADD              R6, R7, R6, R7   # 0x3480
        ST_GLOBAL_IDX    R6, R10, R11, 0, 4   # 0x3484
        BRA              L2f7c   # 0x3488
L348c:  C_CHWIDTH        R8, 0   # 0x348c
        C_MOV            R8, R6   # 0x348e
        C_MOV            R9, R7   # 0x3490
L3492:  CHWIDTH_MULTI    18432, 0   # 0x3492
        LD_GLOBAL_IDX    R1, R8, R9, 0, 0   # 0x3496
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x349a
        SHLI             R0, R0, 16   # 0x349e
        SHRI             R2, R1, 16   # 0x34a2
        OR               R3, R0, R2, R0   # 0x34a6
        MOVI             R0, 65535   # 0x34aa
        AND              R4, R1, R0, R1   # 0x34ae
        LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x34b2
        SHLI             R1, R1, 16   # 0x34b6
        LD_GLOBAL_IDX    R2, R3, R4, 0, 0   # 0x34ba
        SHRI             R5, R2, 16   # 0x34be
        OR               R5, R1, R5, R1   # 0x34c2
        AND              R6, R2, R0, R2   # 0x34c6
        LD_GLOBAL_IDX    R7, R5, R6, 0, 8   # 0x34ca
        SZ_GLOBAL_LD_U16 R1, R5, R6, 0, 12   # 0x34ce
        LD_GLOBAL_IDX    R2, R3, R4, 0, 12   # 0x34d2
        ST_GLOBAL_IDX    R1, R3, R4, 0, 12   # 0x34d6
        LD_GLOBAL_IDX    R1, R3, R4, 0, 8   # 0x34da
        ST_GLOBAL_IDX    R7, R3, R4, 0, 8   # 0x34de
        AND              R7, R2, R0, R2   # 0x34e2
        ST_GLOBAL_IDX    R7, R5, R6, 0, 12   # 0x34e6
        ST_GLOBAL_IDX    R1, R5, R6, 0, 8   # 0x34ea
        LD_GLOBAL_IDX    R7, R5, R6, 0, 0   # 0x34ee
        SZ_GLOBAL_LD_U16 R14, R5, R6, 0, 4   # 0x34f2
        ST_GLOBAL_IDX    R14, R3, R4, 0, 4   # 0x34f6
        ST_GLOBAL_IDX    R7, R3, R4, 0, 0   # 0x34fa
        LD_LOCAL         R10, 188   # 0x34fe
        C_MOV            R4, R10   # 0x3502
        C_CHWIDTH        R4, 1   # 0x3504
        C_MOV            R7, R10   # 0x3506
        C_CHWIDTH        R7, 1   # 0x3508
        C_MOV            R11, R10   # 0x350a
        C_CHWIDTH        R11, 1   # 0x350c
        CVT_SEXT         R3, R4, R7, R11   # 0x350e
        CHWIDTH_MULTI    144, 0   # 0x3512
        MOVI48           R4, 4294967295   # 0x3516
        SETP_LT_NP       P0, R3, R4, R3   # 0x351c
        MOVI             R3, 0   # 0x3520
        ST_GLOBAL_IDX    R3, R5, R6, 0, 4   # 0x3524
        ST_GLOBAL_IDX    R3, R5, R6, 0, 0   # 0x3528
        C_MOV            R13, R8   # 0x352c
        ST_LOCAL         R9, 160   # 0x352e
        BRA_PRED         4, L3582   # 0x3532
L3536:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x3536
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x353a
        SHLI             R4, R4, 16   # 0x353e
        SHRI             R7, R3, 16   # 0x3542
        C_OR             R4, R7   # 0x3546
        C_CHWIDTH        R7, 1   # 0x3548
        C_AND            R3, R0   # 0x354a
        SZ_GLOBAL_LD_U16 R7, R4, R3, 0, 2   # 0x354c
        C_CHWIDTH        R7, 0   # 0x3550
        SETP_EQ_NP       P0, R3, R7, R10   # 0x3552
        BRA_PRED         0, L35d8   # 0x3556
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x355a
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x355e
        SHRI             R7, R4, 16   # 0x3562
        SHLI             R14, R3, 16   # 0x3566
        OR               R8, R14, R7, R14   # 0x356a
        C_AND            R3, R0   # 0x356e
        OR               R3, R4, R3, R4   # 0x3570
        AND              R9, R4, R0, R4   # 0x3574
        SETP_EQ_NPI      P0, R3, R3, 0   # 0x3578
        BRA_PRED         4, L3536   # 0x357c
        C_BRA            L35d0   # 0x3580
L3582:  LD_LOCAL         R10, 192   # 0x3582
L3586:  LD_GLOBAL_IDX    R3, R8, R9, 0, 8   # 0x3586
        LD_GLOBAL_IDX    R4, R8, R9, 0, 12   # 0x358a
        SHLI             R4, R4, 16   # 0x358e
        SHRI             R7, R3, 16   # 0x3592
        C_OR             R4, R7   # 0x3596
        C_CHWIDTH        R7, 1   # 0x3598
        C_AND            R3, R0   # 0x359a
        SZ_GLOBAL_LD_U8  R7, R4, R3, 0, 0   # 0x359c
        C_CHWIDTH        R7, 0   # 0x35a0
        SETP_EQ_NP       P0, R3, R7, R10   # 0x35a2
        BRA_PRED         0, L35d8   # 0x35a6
        LD_GLOBAL_IDX    R3, R8, R9, 0, 4   # 0x35aa
        LD_GLOBAL_IDX    R4, R8, R9, 0, 0   # 0x35ae
        SHRI             R7, R4, 16   # 0x35b2
        SHLI             R14, R3, 16   # 0x35b6
        OR               R8, R14, R7, R14   # 0x35ba
        C_AND            R3, R0   # 0x35be
        OR               R3, R4, R3, R4   # 0x35c0
        AND              R9, R4, R0, R4   # 0x35c4
        SETP_NE_NPI      P0, R3, R3, 0   # 0x35c8
        BRA_PRED         0, L3586   # 0x35cc
L35d0:  MOVI             R8, 0   # 0x35d0
        MOVI             R9, 0   # 0x35d4
L35d8:  SHLI             R2, R2, 16   # 0x35d8
        SHRI             R3, R1, 16   # 0x35dc
        SHLI             R4, R8, 16   # 0x35e0
        AND              R7, R4, R9, R4   # 0x35e4
        ADD              R14, R4, R9, R4   # 0x35e8
        C_OR             R4, R9   # 0x35ec
        C_ANDN           R4, R14   # 0x35ee
        OR               R4, R7, R4, R7   # 0x35f0
        SHRI             R4, R4, 31   # 0x35f4
        SHRI             R7, R8, 16   # 0x35f8
        ADD              R4, R7, R4, R7   # 0x35fc
        OR               R4, R14, R4, R14   # 0x3600
        SETP_NE_NPI      P0, R4, R4, 0   # 0x3604
        BRA_PRED         0, L362e   # 0x3608
        C_MOV            R7, R13   # 0x360c
        LD_LOCAL         R14, 160   # 0x360e
        LD_GLOBAL_IDX    R4, R7, R14, 0, 0   # 0x3612
        LD_GLOBAL_IDX    R7, R7, R14, 0, 4   # 0x3616
        SHLI             R7, R7, 16   # 0x361a
        SHRI             R14, R4, 16   # 0x361e
        OR               R8, R7, R14, R7   # 0x3622
        MOVI             R7, 65535   # 0x3626
        AND              R9, R4, R7, R4   # 0x362a
L362e:  C_CHWIDTH        R11, 0   # 0x362e
        OR               R10, R2, R3, R2   # 0x3630
        AND              R11, R1, R0, R1   # 0x3634
        SHLI             R0, R8, 16   # 0x3638
        AND              R1, R0, R9, R0   # 0x363c
        ADD              R2, R0, R9, R0   # 0x3640
        C_OR             R0, R9   # 0x3644
        C_ANDN           R0, R2   # 0x3646
        OR               R0, R1, R0, R1   # 0x3648
        SHRI             R0, R0, 31   # 0x364c
        SHRI             R1, R8, 16   # 0x3650
        ADD              R0, R1, R0, R1   # 0x3654
        OR               R0, R2, R0, R2   # 0x3658
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x365c
        BRA_PRED         0, L36ce   # 0x3660
        C_CHWIDTH        R4, 1   # 0x3664
        C_MOV            R1, R13   # 0x3666
        LD_LOCAL         R2, 160   # 0x3668
        LD_GLOBAL_IDX    R0, R1, R2, 0, 8   # 0x366c
        LD_GLOBAL_IDX    R1, R1, R2, 0, 12   # 0x3670
        SHLI             R1, R1, 16   # 0x3674
        SHRI             R2, R0, 16   # 0x3678
        C_OR             R1, R2   # 0x367c
        MOVI             R12, 65535   # 0x367e
        C_AND            R0, R12   # 0x3682
        SZ_GLOBAL_LD_U16 R4, R1, R0, 0, 0   # 0x3684
        LD_LOCAL         R2, 180   # 0x3688
L368c:  CHWIDTH_MULTI    20, 0   # 0x368c
        C_MOV            R1, R4   # 0x3690
        CALL             R14, 127467   # 0x3692
        MOVI             R15, 2   # 0x3696
        LD_GLOBAL        R15, R15, 24   # 0x369a
        SRD              R3, 3   # 0x369e
        C_ADD            R15, R3   # 0x36a0
        LD_GLOBAL_IDX    R0, R8, R9, 0, 4   # 0x36a2
        LD_GLOBAL_IDX    R2, R8, R9, 0, 0   # 0x36a6
        SHRI             R3, R2, 16   # 0x36aa
        SHLI             R7, R0, 16   # 0x36ae
        OR               R8, R7, R3, R7   # 0x36b2
        C_AND            R0, R12   # 0x36b6
        OR               R0, R2, R0, R2   # 0x36b8
        AND              R9, R2, R12, R2   # 0x36bc
        C_MOV            R2, R1   # 0x36c0
        C_CHWIDTH        R2, 1   # 0x36c2
        SETP_NE_NPI      P0, R0, R0, 0   # 0x36c4
        BRA_PRED         0, L368c   # 0x36c8
        C_BRA            L36d2   # 0x36cc
L36ce:  LD_LOCAL         R2, 180   # 0x36ce
L36d2:  C_CHWIDTH        R2, 0   # 0x36d2
        ST_LOCAL         R2, 180   # 0x36d4
        LD_LOCAL         R7, 160   # 0x36d8
        LD_GLOBAL_IDX    R1, R13, R7, 0, 0   # 0x36dc
        LD_GLOBAL_IDX    R0, R13, R7, 0, 4   # 0x36e0
        SHLI             R0, R0, 16   # 0x36e4
        SHRI             R2, R1, 16   # 0x36e8
        OR               R2, R0, R2, R0   # 0x36ec
        MOVI             R0, 65535   # 0x36f0
        C_AND            R1, R0   # 0x36f4
        LD_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x36f6
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 12   # 0x36fa
        ST_GLOBAL_IDX    R4, R5, R6, 0, 12   # 0x36fe
        ST_GLOBAL_IDX    R3, R5, R6, 0, 8   # 0x3702
        SHRI             R3, R10, 16   # 0x3706
        ST_GLOBAL_IDX    R3, R2, R1, 0, 12   # 0x370a
        SHLI             R3, R10, 16   # 0x370e
        C_OR             R3, R11   # 0x3712
        ST_GLOBAL_IDX    R3, R2, R1, 0, 8   # 0x3714
        LD_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3718
        SZ_GLOBAL_LD_U16 R4, R2, R1, 0, 4   # 0x371c
        ST_GLOBAL_IDX    R4, R5, R6, 0, 4   # 0x3720
        ST_GLOBAL_IDX    R3, R5, R6, 0, 0   # 0x3724
        SHRI             R3, R5, 16   # 0x3728
        ST_GLOBAL_IDX    R3, R2, R1, 0, 4   # 0x372c
        SHLI             R3, R5, 16   # 0x3730
        C_OR             R3, R6   # 0x3734
        ST_GLOBAL_IDX    R3, R2, R1, 0, 0   # 0x3736
        C_MOV            R1, R13   # 0x373a
        C_MOV            R13, R7   # 0x373c
        MOVI             R9, 1   # 0x373e
        C_BRA            L3766   # 0x3742
L3744:  ST_GLOBAL_IDX    R3, R2, R4, 0, 4   # 0x3744
        ST_GLOBAL_IDX    R3, R2, R4, 0, 0   # 0x3748
        C_SHLI           R9, 1   # 0x374c
        LD_LOCAL         R1, 104   # 0x374e
        SETP_NE_NPI      P0, R1, R1, 0   # 0x3752
        LD_LOCAL         R3, 96   # 0x3756
        C_MOV            R1, R3   # 0x375a
        LD_LOCAL         R4, 100   # 0x375c
        C_MOV            R13, R4   # 0x3760
        BRA_PRED         4, L39de   # 0x3762
L3766:  MOVI             R5, 0   # 0x3766
        MOVI             R2, 0   # 0x376a
        MOVI             R4, 0   # 0x376e
        MOVI             R3, 0   # 0x3772
        ST_LOCAL         R3, 96   # 0x3776
        ST_LOCAL         R3, 100   # 0x377a
        ST_LOCAL         R9, 112   # 0x377e
        C_BRA            L3794   # 0x3782
L3784:  SETP_EQ_NPI      P0, R5, R6, 0   # 0x3784
        LD_LOCAL         R9, 112   # 0x3788
        LD_LOCAL         R5, 108   # 0x378c
        BRA_PRED         0, L3744   # 0x3790
L3794:  ST_LOCAL         R5, 104   # 0x3794
        SETP_LT_NPI      P0, R5, R9, 1   # 0x3798
        BRA_PRED         0, L37dc   # 0x379c
        MOVI             R5, 0   # 0x37a0
        C_MOV            R6, R1   # 0x37a4
        C_MOV            R7, R13   # 0x37a6
L37a8:  LD_GLOBAL_IDX    R14, R6, R7, 0, 4   # 0x37a8
        LD_GLOBAL_IDX    R7, R6, R7, 0, 0   # 0x37ac
        AND              R6, R14, R0, R14   # 0x37b0
        OR               R6, R7, R6, R7   # 0x37b4
        SETP_NE_NPI      P0, R6, R6, 0   # 0x37b8
        BRA_PRED         4, L37e6   # 0x37bc
        SHRI             R6, R7, 16   # 0x37c0
        SHLI             R14, R14, 16   # 0x37c4
        OR               R6, R14, R6, R14   # 0x37c8
        C_AND            R7, R0   # 0x37cc
        C_ADDI           R5, 1   # 0x37ce
        SETP_EQ_NP       P0, R14, R9, R5   # 0x37d0
        BRA_PRED         4, L37a8   # 0x37d4
        C_MOV            R8, R9   # 0x37d8
        C_BRA            L37f2   # 0x37da
L37dc:  MOVI             R8, 0   # 0x37dc
        C_MOV            R6, R1   # 0x37e0
        C_MOV            R7, R13   # 0x37e2
        C_BRA            L37f2   # 0x37e4
L37e6:  MOVI             R6, 0   # 0x37e6
        ADDI             R8, R5, 1   # 0x37ea
        MOVI             R7, 0   # 0x37ee
L37f2:  LD_LOCAL         R5, 104   # 0x37f2
        C_ADDI           R5, 1   # 0x37f6
        ST_LOCAL         R5, 108   # 0x37f8
        C_MOV            R5, R1   # 0x37fc
        C_MOV            R14, R13   # 0x37fe
        C_MOV            R1, R6   # 0x3800
        C_MOV            R13, R7   # 0x3802
        C_BRA            L3818   # 0x3804
L3806:  ST_LOCAL         R6, 96   # 0x3806
        ST_LOCAL         R7, 100   # 0x380a
L380e:  C_MOV            R5, R11   # 0x380e
        C_MOV            R14, R10   # 0x3810
        C_MOV            R1, R12   # 0x3812
        C_MOV            R2, R6   # 0x3814
        C_MOV            R4, R7   # 0x3816
L3818:  SETP_LT_NP       P0, R6, R3, R8   # 0x3818
        BRA_PRED         0, L3854   # 0x381c
        SHLI             R6, R1, 16   # 0x3820
        AND              R7, R6, R13, R6   # 0x3824
        ADD              R10, R6, R13, R6   # 0x3828
        C_OR             R6, R13   # 0x382c
        C_ANDN           R6, R10   # 0x382e
        OR               R6, R7, R6, R7   # 0x3830
        SHRI             R6, R6, 31   # 0x3834
        SHRI             R7, R1, 16   # 0x3838
        ADD              R6, R7, R6, R7   # 0x383c
        OR               R6, R10, R6, R10   # 0x3840
        SETP_LT_NPI      P0, R7, R9, 1   # 0x3844
        BRA_PRED         0, L3784   # 0x3848
        SETP_EQ_NPI      P0, R7, R6, 0   # 0x384c
        BRA_PRED         0, L3784   # 0x3850
L3854:  SETP_NE_NPI      P0, R6, R8, 0   # 0x3854
        BRA_PRED         4, L3910   # 0x3858
        SETP_EQ_NPI      P0, R6, R9, 0   # 0x385c
        BRA_PRED         0, L393a   # 0x3860
        SHLI             R6, R1, 16   # 0x3864
        AND              R7, R6, R13, R6   # 0x3868
        ADD              R10, R6, R13, R6   # 0x386c
        C_OR             R6, R13   # 0x3870
        C_ANDN           R6, R10   # 0x3872
        OR               R6, R7, R6, R7   # 0x3874
        SHRI             R6, R6, 31   # 0x3878
        SHRI             R7, R1, 16   # 0x387c
        ADD              R6, R7, R6, R7   # 0x3880
        OR               R6, R10, R6, R10   # 0x3884
        SETP_NE_NPI      P0, R6, R6, 0   # 0x3888
        BRA_PRED         4, L393a   # 0x388c
        LD_GLOBAL_IDX    R6, R5, R14, 0, 8   # 0x3890
        LD_GLOBAL_IDX    R7, R5, R14, 0, 12   # 0x3894
        SHLI             R7, R7, 16   # 0x3898
        SHRI             R10, R6, 16   # 0x389c
        C_OR             R7, R10   # 0x38a0
        LD_GLOBAL_IDX    R10, R1, R13, 0, 8   # 0x38a2
        LD_GLOBAL_IDX    R11, R1, R13, 0, 12   # 0x38a6
        C_AND            R6, R0   # 0x38aa
        C_MOV            R3, R13   # 0x38ac
        C_CHWIDTH        R13, 1   # 0x38ae
        SZ_GLOBAL_LD_U8  R13, R7, R6, 0, 1   # 0x38b0
        SZ_GLOBAL_ST_8   R13, R7, R6, 0, 0   # 0x38b4
        SHLI             R11, R11, 16   # 0x38b8
        SHRI             R12, R10, 16   # 0x38bc
        C_OR             R11, R12   # 0x38c0
        C_AND            R10, R0   # 0x38c2
        SZ_GLOBAL_LD_U8  R13, R11, R10, 0, 1   # 0x38c4
        SZ_GLOBAL_ST_8   R13, R11, R10, 0, 0   # 0x38c8
        SZ_GLOBAL_LD_U16 R13, R7, R6, 0, 2   # 0x38cc
        C_CHWIDTH        R7, 1   # 0x38d0
        SZ_GLOBAL_LD_U16 R7, R11, R10, 0, 2   # 0x38d2
        CVT_SEXT         R6, R7, R7, R7   # 0x38d6
        C_CHWIDTH        R7, 0   # 0x38da
        CVT_SEXT         R7, R13, R13, R13   # 0x38dc
        SETP_LT_NP       P0, R6, R6, R7   # 0x38e0
        BRA_PRED         4, L395e   # 0x38e4
        C_CHWIDTH        R13, 0   # 0x38e8
        LD_GLOBAL_IDX    R6, R1, R3, 0, 0   # 0x38ea
        LD_GLOBAL_IDX    R7, R1, R3, 0, 4   # 0x38ee
        SHLI             R7, R7, 16   # 0x38f2
        SHRI             R10, R6, 16   # 0x38f6
        OR               R12, R7, R10, R7   # 0x38fa
        AND              R13, R6, R0, R6   # 0x38fe
        ADDI             R9, R9, -1   # 0x3902
        C_MOV            R11, R5   # 0x3906
        C_MOV            R10, R14   # 0x3908
        C_MOV            R6, R1   # 0x390a
        C_MOV            R7, R3   # 0x390c
        C_BRA            L3984   # 0x390e
L3910:  LD_GLOBAL_IDX    R6, R1, R13, 0, 0   # 0x3910
        LD_GLOBAL_IDX    R7, R1, R13, 0, 4   # 0x3914
        SHLI             R7, R7, 16   # 0x3918
        SHRI             R8, R6, 16   # 0x391c
        OR               R12, R7, R8, R7   # 0x3920
        C_MOV            R7, R13   # 0x3924
        AND              R13, R6, R0, R6   # 0x3926
        MOVI             R8, 0   # 0x392a
        ADDI             R9, R9, -1   # 0x392e
        C_MOV            R11, R5   # 0x3932
        C_MOV            R10, R14   # 0x3934
        C_MOV            R6, R1   # 0x3936
        C_BRA            L3988   # 0x3938
L393a:  LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x393a
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x393e
        SHLI             R7, R7, 16   # 0x3942
        SHRI             R10, R6, 16   # 0x3946
        OR               R11, R7, R10, R7   # 0x394a
        AND              R10, R6, R0, R6   # 0x394e
        ADDI             R8, R8, -1   # 0x3952
        C_MOV            R12, R1   # 0x3956
        C_MOV            R6, R5   # 0x3958
        C_MOV            R7, R14   # 0x395a
        C_BRA            L3988   # 0x395c
L395e:  C_CHWIDTH        R13, 0   # 0x395e
        LD_GLOBAL_IDX    R6, R5, R14, 0, 0   # 0x3960
        LD_GLOBAL_IDX    R7, R5, R14, 0, 4   # 0x3964
        SHLI             R7, R7, 16   # 0x3968
        SHRI             R10, R6, 16   # 0x396c
        OR               R11, R7, R10, R7   # 0x3970
        AND              R10, R6, R0, R6   # 0x3974
        ADDI             R8, R8, -1   # 0x3978
        C_MOV            R12, R1   # 0x397c
        C_MOV            R13, R3   # 0x397e
        C_MOV            R6, R5   # 0x3980
        C_MOV            R7, R14   # 0x3982
L3984:  MOVI             R3, 0   # 0x3984
L3988:  SHLI             R5, R2, 16   # 0x3988
        AND              R14, R5, R4, R5   # 0x398c
        ADD              R1, R5, R4, R5   # 0x3990
        C_OR             R5, R4   # 0x3994
        C_ANDN           R5, R1   # 0x3996
        OR               R5, R14, R5, R14   # 0x3998
        SHRI             R5, R5, 31   # 0x399c
        SHRI             R14, R2, 16   # 0x39a0
        ADD              R5, R14, R5, R14   # 0x39a4
        C_OR             R1, R5   # 0x39a8
        SETP_EQ_NPI      P0, R1, R1, 0   # 0x39aa
        BRA_PRED         0, L3806   # 0x39ae
        SHLI             R1, R6, 16   # 0x39b2
        ADD              R5, R1, R7, R1   # 0x39b6
        ST_GLOBAL_IDX    R5, R2, R4, 0, 0   # 0x39ba
        OR               R14, R1, R7, R1   # 0x39be
        ANDN             R5, R14, R5, R14   # 0x39c2
        C_AND            R1, R7   # 0x39c6
        C_OR             R1, R5   # 0x39c8
        SHRI             R1, R1, 31   # 0x39ca
        SHRI             R5, R6, 16   # 0x39ce
        ADD              R1, R5, R1, R5   # 0x39d2
        ST_GLOBAL_IDX    R1, R2, R4, 0, 4   # 0x39d6
        BRA              L380e   # 0x39da
L39de:  LD_GLOBAL_IDX    R1, R3, R4, 0, 4   # 0x39de
        LD_GLOBAL_IDX    R0, R3, R4, 0, 0   # 0x39e2
        MOVI             R5, 65535   # 0x39e6
        AND              R2, R1, R5, R1   # 0x39ea
        OR               R2, R0, R2, R0   # 0x39ee
        SETP_EQ_NPI      P0, R2, R2, 0   # 0x39f2
        BRA_PRED         0, L3a68   # 0x39f6
        SHRI             R2, R0, 16   # 0x39fa
        SHLI             R1, R1, 16   # 0x39fe
        OR               R6, R1, R2, R1   # 0x3a02
        AND              R8, R0, R5, R0   # 0x3a06
        LD_GLOBAL_IDX    R0, R3, R4, 0, 8   # 0x3a0a
        LD_GLOBAL_IDX    R1, R3, R4, 0, 12   # 0x3a0e
        C_CHWIDTH        R4, 1   # 0x3a12
        SHLI             R1, R1, 16   # 0x3a14
        SHRI             R2, R0, 16   # 0x3a18
        C_OR             R1, R2   # 0x3a1c
        C_AND            R0, R5   # 0x3a1e
        SZ_GLOBAL_LD_U16 R4, R1, R0, 0, 0   # 0x3a20
        LD_LOCAL         R2, 180   # 0x3a24
L3a28:  CHWIDTH_MULTI    20, 0   # 0x3a28
        C_MOV            R1, R4   # 0x3a2c
        CALL             R14, 127005   # 0x3a2e
        MOVI             R15, 2   # 0x3a32
        LD_GLOBAL        R15, R15, 24   # 0x3a36
        SRD              R3, 3   # 0x3a3a
        C_ADD            R15, R3   # 0x3a3c
        LD_GLOBAL_IDX    R0, R6, R8, 0, 4   # 0x3a3e
        LD_GLOBAL_IDX    R2, R6, R8, 0, 0   # 0x3a42
        SHRI             R3, R2, 16   # 0x3a46
        SHLI             R6, R0, 16   # 0x3a4a
        C_OR             R6, R3   # 0x3a4e
        C_AND            R0, R5   # 0x3a50
        OR               R0, R2, R0, R2   # 0x3a52
        AND              R8, R2, R5, R2   # 0x3a56
        C_MOV            R2, R1   # 0x3a5a
        C_CHWIDTH        R2, 1   # 0x3a5c
        SETP_NE_NPI      P0, R0, R0, 0   # 0x3a5e
        BRA_PRED         0, L3a28   # 0x3a62
        C_BRA            L3a6c   # 0x3a66
L3a68:  LD_LOCAL         R2, 180   # 0x3a68
L3a6c:  C_CHWIDTH        R2, 0   # 0x3a6c
        LD_LOCAL         R14, 184   # 0x3a6e
        C_MOV            R1, R2   # 0x3a72
        LD_LOCAL         R13, 216   # 0x3a74
        LD_LOCAL         R12, 212   # 0x3a78
        LD_LOCAL         R11, 208   # 0x3a7c
        LD_LOCAL         R10, 204   # 0x3a80
        LD_LOCAL         R9, 200   # 0x3a84
        LD_LOCAL         R8, 196   # 0x3a88
        C_RET            224   # 0x3a8c
        MOVI             R15, 2   # 0x3a8e
        LD_GLOBAL        R15, R15, 24   # 0x3a92
        SRD              R14, 3   # 0x3a96
        C_ADD            R15, R14   # 0x3a98
        MOVI             R0, 2   # 0x3a9a
        LD_GLOBAL        R1, R0, 44   # 0x3a9e
        ST_LOCAL         R1, 228   # 0x3aa2
        LD_GLOBAL        R1, R0, 40   # 0x3aa6
        ST_LOCAL         R1, 224   # 0x3aaa
        LD_GLOBAL        R1, R0, 48   # 0x3aae
        LD_GLOBAL        R8, R0, 32   # 0x3ab2
        LD_GLOBAL        R0, R0, 36   # 0x3ab6
        MOVI             R2, 102   # 0x3aba
        C_CHWIDTH        R2, 1   # 0x3abe
        MOVI             R3, 36   # 0x3ac0
        C_ADDI           R3, 4   # 0x3ac4
        MOVI             R10, 36   # 0x3ac6
        SZ_GLOBAL_ST_16  R2, R15, R3, 0, 0   # 0x3aca
        C_CHWIDTH        R2, 0   # 0x3ace
        MOVI             R2, 2000   # 0x3ad0
        SRD              R11, 0   # 0x3ad4
        MADLO            R3, R11, R2, R0   # 0x3ad6
        ADDI             R2, R3, 1332   # 0x3ada
        SHLI             R0, R8, 16   # 0x3ade
        ADD              R4, R0, R2, R0   # 0x3ae2
        OR               R5, R0, R2, R0   # 0x3ae6
        C_ANDN           R5, R4   # 0x3aea
        AND              R2, R0, R2, R0   # 0x3aec
        OR               R9, R2, R5, R2   # 0x3af0
        ADD              R5, R0, R3, R0   # 0x3af4
        OR               R6, R0, R3, R0   # 0x3af8
        C_ANDN           R6, R5   # 0x3afc
        AND              R7, R0, R3, R0   # 0x3afe
        OR               R6, R7, R6, R7   # 0x3b02
        ADDI             R7, R10, 2   # 0x3b06
        MOVI             R2, 0   # 0x3b0a
        C_MOV            R14, R2   # 0x3b0e
        ST_LOCAL         R14, 232   # 0x3b10
        C_MOV            R2, R14   # 0x3b14
        C_CHWIDTH        R2, 1   # 0x3b16
        SZ_GLOBAL_ST_16  R2, R15, R7, 0, 0   # 0x3b18
        C_CHWIDTH        R2, 0   # 0x3b1c
        MOVI             R7, 7   # 0x3b1e
        ST_GLOBAL        R7, R15, 84   # 0x3b22
        ST_GLOBAL        R1, R15, 80   # 0x3b26
        ST_GLOBAL        R5, R15, 52   # 0x3b2a
        ST_GLOBAL        R5, R15, 44   # 0x3b2e
        ST_GLOBAL        R4, R15, 68   # 0x3b32
        ADDI             R2, R3, 666   # 0x3b36
        ADD              R1, R0, R2, R0   # 0x3b3a
        OR               R4, R0, R2, R0   # 0x3b3e
        C_MOV            R7, R2   # 0x3b42
        ST_LOCAL         R7, 236   # 0x3b44
        C_ANDN           R4, R1   # 0x3b48
        ST_GLOBAL        R1, R15, 60   # 0x3b4a
        SHRI             R1, R6, 31   # 0x3b4e
        C_MOV            R2, R8   # 0x3b52
        ST_LOCAL         R2, 240   # 0x3b54
        SHRI             R5, R2, 16   # 0x3b58
        ADD              R1, R5, R1, R5   # 0x3b5c
        ST_GLOBAL        R1, R15, 56   # 0x3b60
        ST_GLOBAL        R1, R15, 48   # 0x3b64
        SHRI             R1, R9, 31   # 0x3b68
        ADD              R1, R5, R1, R5   # 0x3b6c
        ST_GLOBAL        R1, R15, 72   # 0x3b70
        C_AND            R0, R7   # 0x3b74
        C_OR             R0, R4   # 0x3b76
        SHRI             R0, R0, 31   # 0x3b78
        ADD              R0, R5, R0, R5   # 0x3b7c
        ST_GLOBAL        R0, R15, 64   # 0x3b80
        C_MOV            R4, R11   # 0x3b84
        ST_LOCAL         R4, 220   # 0x3b86
        SZ_GLOBAL_ST_16  R4, R15, R10, 0, 0   # 0x3b8a
        MOVI             R0, 666   # 0x3b8e
        ST_GLOBAL        R0, R15, 76   # 0x3b92
        MOVI             R1, 666   # 0x3b96
        CALL             R14, 123441   # 0x3b9a
        MOVI             R15, 2   # 0x3b9e
        LD_GLOBAL        R15, R15, 24   # 0x3ba2
        SRD              R3, 3   # 0x3ba6
        C_ADD            R15, R3   # 0x3ba8
        SHLI             R0, R1, 16   # 0x3baa
        ADD              R3, R0, R2, R0   # 0x3bae
        OR               R4, R0, R2, R0   # 0x3bb2
        C_ANDN           R4, R3   # 0x3bb6
        ST_GLOBAL        R3, R15, 92   # 0x3bb8
        C_AND            R0, R2   # 0x3bbc
        C_OR             R0, R4   # 0x3bbe
        SHRI             R0, R0, 31   # 0x3bc0
        SHRI             R1, R1, 16   # 0x3bc4
        ADD              R0, R1, R0, R1   # 0x3bc8
        ST_GLOBAL        R0, R15, 96   # 0x3bcc
        LD_LOCAL         R0, 220   # 0x3bd0
        SHLI             R0, R0, 16   # 0x3bd4
        SRAI             R4, R0, 16   # 0x3bd8
        MOVI             R0, 36   # 0x3bdc
        ADDI             R6, R0, 64   # 0x3be0
        MOVI             R1, 666   # 0x3be4
        LD_LOCAL         R2, 240   # 0x3be8
        LD_LOCAL         R3, 236   # 0x3bec
        C_MOV            R5, R15   # 0x3bf0
        CALL             R14, 124587   # 0x3bf2
        MOVI             R15, 2   # 0x3bf6
        LD_GLOBAL        R15, R15, 24   # 0x3bfa
        SRD              R3, 3   # 0x3bfe
        C_ADD            R15, R3   # 0x3c00
        MOVI             R0, 36   # 0x3c02
        SZ_GLOBAL_LD_U16 R2, R15, R0, 0, 0   # 0x3c06
        MOVI             R0, 65535   # 0x3c0a
        LD_GLOBAL        R1, R15, 68   # 0x3c0e
        AND              R4, R1, R0, R1   # 0x3c12
        SHRI             R0, R1, 16   # 0x3c16
        LD_GLOBAL        R1, R15, 72   # 0x3c1a
        SHLI             R1, R1, 16   # 0x3c1e
        OR               R3, R1, R0, R1   # 0x3c22
        LD_GLOBAL        R1, R15, 76   # 0x3c26
        CALL             R14, 124922   # 0x3c2a
        MOVI             R15, 2   # 0x3c2e
        LD_GLOBAL        R15, R15, 24   # 0x3c32
        SRD              R3, 3   # 0x3c36
        C_ADD            R15, R3   # 0x3c38
        LD_LOCAL         R11, 232   # 0x3c3a
        MOVI             R0, 0   # 0x3c3e
        ST_GLOBAL        R0, R15, 136   # 0x3c42
        ST_GLOBAL        R0, R15, 132   # 0x3c46
        LD_GLOBAL        R0, R15, 80   # 0x3c4a
        SETP_EQ_NPI      P0, R0, R0, 0   # 0x3c4e
        C_MOV            R12, R11   # 0x3c52
        C_CHWIDTH        R12, 1   # 0x3c54
        C_MOV            R13, R11   # 0x3c56
        C_CHWIDTH        R13, 1   # 0x3c58
        C_MOV            R14, R11   # 0x3c5a
        CHWIDTH_MULTI    18432, 1   # 0x3c5c
        BRA_PRED         0, L3d9a   # 0x3c60
        CHWIDTH_MULTI    30720, 0   # 0x3c64
        MOVI             R8, 1   # 0x3c68
        C_MOV            R1, R15   # 0x3c6c
        MOVI             R2, 36   # 0x3c6e
        MOVI             R3, 1   # 0x3c72
        CALL             R14, 128779   # 0x3c76
        MOVI             R15, 2   # 0x3c7a
        LD_GLOBAL        R15, R15, 24   # 0x3c7e
        SRD              R3, 3   # 0x3c82
        C_ADD            R15, R3   # 0x3c84
        MOVI             R10, 36   # 0x3c86
        ADDI             R9, R10, 96   # 0x3c8a
        SZ_GLOBAL_LD_U16 R2, R15, R9, 0, 0   # 0x3c8e
        CALL             R14, 128456   # 0x3c92
        MOVI             R15, 2   # 0x3c96
        LD_GLOBAL        R15, R15, 24   # 0x3c9a
        SRD              R3, 3   # 0x3c9e
        C_ADD            R15, R3   # 0x3ca0
        SZ_GLOBAL_ST_16  R1, R15, R9, 0, 0   # 0x3ca2
        C_MOV            R1, R15   # 0x3ca6
        MOVI             R2, 36   # 0x3ca8
        MOVI             R3, 65535   # 0x3cac
        CALL             R14, 128750   # 0x3cb0
        MOVI             R15, 2   # 0x3cb4
        LD_GLOBAL        R15, R15, 24   # 0x3cb8
        SRD              R3, 3   # 0x3cbc
        C_ADD            R15, R3   # 0x3cbe
        SZ_GLOBAL_LD_U16 R2, R15, R9, 0, 0   # 0x3cc0
        CALL             R14, 128431   # 0x3cc4
        MOVI             R15, 2   # 0x3cc8
        LD_GLOBAL        R15, R15, 24   # 0x3ccc
        SRD              R3, 3   # 0x3cd0
        C_ADD            R15, R3   # 0x3cd2
        ADDI             R0, R10, 98   # 0x3cd4
        C_MOV            R13, R1   # 0x3cd8
        C_CHWIDTH        R13, 1   # 0x3cda
        SZ_GLOBAL_ST_16  R13, R15, R0, 0, 0   # 0x3cdc
        SZ_GLOBAL_ST_16  R13, R15, R9, 0, 0   # 0x3ce0
        C_CHWIDTH        R13, 0   # 0x3ce4
        LD_GLOBAL        R0, R15, 80   # 0x3ce6
        SETP_LT_U_NPI    P0, R0, R0, 2   # 0x3cea
        C_MOV            R14, R13   # 0x3cee
        BRA_PRED         0, L3d82   # 0x3cf0
        MOVI             R0, 36   # 0x3cf4
        ADDI             R9, R0, 96   # 0x3cf8
L3cfc:  C_CHWIDTH        R14, 0   # 0x3cfc
        C_MOV            R1, R15   # 0x3cfe
        MOVI             R2, 36   # 0x3d00
        MOVI             R3, 1   # 0x3d04
        CALL             R14, 128706   # 0x3d08
        MOVI             R15, 2   # 0x3d0c
        LD_GLOBAL        R15, R15, 24   # 0x3d10
        SRD              R3, 3   # 0x3d14
        C_ADD            R15, R3   # 0x3d16
        SZ_GLOBAL_LD_U16 R2, R15, R9, 0, 0   # 0x3d18
        CALL             R14, 128387   # 0x3d1c
        MOVI             R15, 2   # 0x3d20
        LD_GLOBAL        R15, R15, 24   # 0x3d24
        SRD              R3, 3   # 0x3d28
        C_ADD            R15, R3   # 0x3d2a
        SZ_GLOBAL_ST_16  R1, R15, R9, 0, 0   # 0x3d2c
        C_MOV            R1, R15   # 0x3d30
        MOVI             R2, 36   # 0x3d32
        MOVI             R3, 65535   # 0x3d36
        CALL             R14, 128681   # 0x3d3a
        MOVI             R15, 2   # 0x3d3e
        LD_GLOBAL        R15, R15, 24   # 0x3d42
        SRD              R3, 3   # 0x3d46
        C_ADD            R15, R3   # 0x3d48
        SZ_GLOBAL_LD_U16 R2, R15, R9, 0, 0   # 0x3d4a
        CALL             R14, 128362   # 0x3d4e
        MOVI             R15, 2   # 0x3d52
        LD_GLOBAL        R15, R15, 24   # 0x3d56
        SRD              R3, 3   # 0x3d5a
        C_ADD            R15, R3   # 0x3d5c
        C_MOV            R14, R1   # 0x3d5e
        C_CHWIDTH        R14, 1   # 0x3d60
        SZ_GLOBAL_ST_16  R14, R15, R9, 0, 0   # 0x3d62
        C_ADDI           R8, 1   # 0x3d66
        LD_GLOBAL        R0, R15, 80   # 0x3d68
        SETP_LT_U_NP     P0, R0, R8, R0   # 0x3d6c
        BRA_PRED         0, L3cfc   # 0x3d70
        C_CHWIDTH        R13, 1   # 0x3d74
        MOVI             R0, 36   # 0x3d76
        ADDI             R0, R0, 98   # 0x3d7a
        SZ_GLOBAL_LD_U16 R13, R15, R0, 0, 0   # 0x3d7e
L3d82:  CHWIDTH_MULTI    30720, 1   # 0x3d82
        MOVI             R0, 36   # 0x3d86
        ADDI             R1, R0, 102   # 0x3d8a
        SZ_GLOBAL_LD_U16 R11, R15, R1, 0, 0   # 0x3d8e
        ADDI             R0, R0, 100   # 0x3d92
        SZ_GLOBAL_LD_U16 R12, R15, R0, 0, 0   # 0x3d96
L3d9a:  LD_LOCAL         R1, 220   # 0x3d9a
        C_SHLI           R1, 3   # 0x3d9e
        LD_LOCAL         R0, 228   # 0x3da0
        C_ADD            R0, R1   # 0x3da4
        LD_LOCAL         R2, 224   # 0x3da6
        SZ_GLOBAL_ST_16  R14, R2, R0, 0, 0   # 0x3daa
        ADDI             R1, R0, 2   # 0x3dae
        SZ_GLOBAL_ST_16  R13, R2, R1, 0, 0   # 0x3db2
        ADDI             R1, R0, 4   # 0x3db6
        SZ_GLOBAL_ST_16  R12, R2, R1, 0, 0   # 0x3dba
        C_ADDI           R0, 6   # 0x3dbe
        SZ_GLOBAL_ST_16  R11, R2, R0, 0, 0   # 0x3dc0
        C_EXIT           0   # 0x3dc4
