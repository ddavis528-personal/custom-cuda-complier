# colwalk-p16k: test/cuda/colwalk.cu -DPITCH_KIB=16, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        SRD              R0, 0   # 0x0000
        MOVI             R1, 2   # 0x0002
        LD_GLOBAL        R3, R1, 44   # 0x0006
        LD_GLOBAL        R2, R1, 48   # 0x000a
        SETP_LT_NPI      P0, R4, R2, 1   # 0x000e
        C_SHLI           R0, 2   # 0x0012
        BRA_PRED         0, L00ce   # 0x0014
        ADD              R5, R3, R0, R3   # 0x0018
        MOVI             R4, 0   # 0x001c
        MOVI             R3, 0   # 0x0020
        ADDI48           R5, R5, 114688   # 0x0024
        MOVI48           R6, 4294852608   # 0x002a
        MOVI48           R7, 4294868992   # 0x0030
        MOVI48           R8, 4294885376   # 0x0036
        MOVI48           R9, 4294901760   # 0x003c
        MOVI48           R10, 4294918144   # 0x0042
        MOVI48           R11, 4294934528   # 0x0048
        MOVI48           R12, 4294950912   # 0x004e
L0054:  MOVI48           R13, 4294967288   # 0x0054
        MOVI             R14, 0   # 0x005a
        C_MOV            R15, R5   # 0x005e
L0060:  ADD              R1, R15, R6, R15   # 0x0060
        LD_GLOBAL_SLOT   R1, 1, R1, 0, 0   # 0x0064
        C_FADD           R3, R1   # 0x0068
        ADD              R1, R15, R7, R15   # 0x006a
        LD_GLOBAL_SLOT   R1, 1, R1, 0, 0   # 0x006e
        C_FADD           R3, R1   # 0x0072
        ADD              R1, R15, R8, R15   # 0x0074
        LD_GLOBAL_SLOT   R1, 1, R1, 0, 0   # 0x0078
        C_FADD           R3, R1   # 0x007c
        ADD              R1, R15, R9, R15   # 0x007e
        LD_GLOBAL_SLOT   R1, 1, R1, 0, 0   # 0x0082
        C_FADD           R3, R1   # 0x0086
        ADD              R1, R15, R10, R15   # 0x0088
        LD_GLOBAL_SLOT   R1, 1, R1, 0, 0   # 0x008c
        C_FADD           R3, R1   # 0x0090
        ADD              R1, R15, R11, R15   # 0x0092
        LD_GLOBAL_SLOT   R1, 1, R1, 0, 0   # 0x0096
        C_FADD           R3, R1   # 0x009a
        ADD              R1, R15, R12, R15   # 0x009c
        LD_GLOBAL_SLOT   R1, 1, R1, 0, 0   # 0x00a0
        C_FADD           R3, R1   # 0x00a4
        LD_GLOBAL_SLOT   R1, 1, R15, 0, 0   # 0x00a6
        C_FADD           R3, R1   # 0x00aa
        ADDI48           R14, R14, 32768   # 0x00ac
        ADDI48           R15, R15, 131072   # 0x00b2
        C_ADDI           R13, 8   # 0x00b8
        SETP_LT_U_NPI    P0, R1, R13, 56   # 0x00ba
        BRA_PRED         0, L0060   # 0x00be
        C_ADDI           R4, 1   # 0x00c2
        SETP_EQ_NP       P0, R13, R4, R2   # 0x00c4
        BRA_PRED         4, L0054   # 0x00c8
        C_BRA            L00d2   # 0x00cc
L00ce:  MOVI             R3, 0   # 0x00ce
L00d2:  MOVI             R1, 2   # 0x00d2
        LD_GLOBAL        R1, R1, 36   # 0x00d6
        ADD              R0, R1, R0, R1   # 0x00da
        ST_GLOBAL_SLOT   R3, 0, R0, 0, 0   # 0x00de
        C_EXIT           0   # 0x00e2
