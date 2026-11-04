# vadd16_loop-128: test/bench/vadd16_loop.cu, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        CHWIDTH_MULTI    12288, 1   # 0x0000
        MOVI             R8, 2   # 0x0004
        C_LD_GLOBAL      R0, R8   # 0x0008
        SRD              R1, 0   # 0x000a
        SRD              R2, 1   # 0x000c
        MAD_ACC          R1, R2, R0   # 0x000e
        LD_GLOBAL        R2, R8, 52   # 0x0010
        LD_GLOBAL        R3, R8, 48   # 0x0014
        LD_GLOBAL        R4, R8, 44   # 0x0018
        LD_GLOBAL        R5, R8, 40   # 0x001c
        LD_GLOBAL        R6, R8, 36   # 0x0020
        LD_GLOBAL        R7, R8, 32   # 0x0024
        LD_GLOBAL        R8, R8, 56   # 0x0028
        SETP_LE_U_NP     P0, R9, R8, R1   # 0x002c
        BRA_PRED         0, L005e   # 0x0030
L0034:  C_MOV            R9, R1   # 0x0034
        C_SHLI           R9, 1   # 0x0036
        ADD              R10, R4, R9, R4   # 0x0038
        SZ_GLOBAL_LD_U16 R13, R5, R10, 0, 0   # 0x003c
        ADD              R10, R2, R9, R2   # 0x0040
        SZ_GLOBAL_LD_U16 R12, R3, R10, 0, 0   # 0x0044
        ADD              R13, R12, R13, R12   # 0x0048
        ADD              R9, R6, R9, R6   # 0x004c
        SZ_GLOBAL_ST_16  R13, R7, R9, 0, 0   # 0x0050
        C_ADD            R1, R0   # 0x0054
        SETP_LT_U_NP     P0, R9, R1, R8   # 0x0056
        BRA_PRED         0, L0034   # 0x005a
L005e:  C_EXIT           0   # 0x005e
