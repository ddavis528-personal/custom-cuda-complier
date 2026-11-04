# vadd16-128: test/bench/vadd16.cu, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        CHWIDTH_MULTI    12288, 1   # 0x0000
        MOVI             R0, 2   # 0x0004
        C_LD_GLOBAL      R1, R0   # 0x0008
        SRD              R2, 0   # 0x000a
        SRD              R3, 1   # 0x000c
        MADLO            R1, R3, R1, R2   # 0x000e
        LD_GLOBAL        R2, R0, 56   # 0x0012
        SETP_LE_U_NP     P0, R2, R2, R1   # 0x0016
        BRA_PRED         0, L0050   # 0x001a
        C_SHLI           R1, 1   # 0x001e
        LD_GLOBAL        R2, R0, 44   # 0x0020
        C_ADD            R2, R1   # 0x0024
        LD_GLOBAL        R3, R0, 40   # 0x0026
        SZ_GLOBAL_LD_U16 R13, R3, R2, 0, 0   # 0x002a
        LD_GLOBAL        R2, R0, 52   # 0x002e
        C_ADD            R2, R1   # 0x0032
        LD_GLOBAL        R3, R0, 48   # 0x0034
        SZ_GLOBAL_LD_U16 R12, R3, R2, 0, 0   # 0x0038
        ADD              R13, R12, R13, R12   # 0x003c
        LD_GLOBAL        R2, R0, 36   # 0x0040
        ADD              R1, R2, R1, R2   # 0x0044
        LD_GLOBAL        R0, R0, 32   # 0x0048
        SZ_GLOBAL_ST_16  R13, R0, R1, 0, 0   # 0x004c
L0050:  C_EXIT           0   # 0x0050
