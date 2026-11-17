# colwalk-p2k: test/cuda/colwalk.cu -DPITCH_KIB=2, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        SRD              R0, 0   # 0x0000
        MOVI             R1, 2   # 0x0002
        LD_GLOBAL        R3, R1, 44   # 0x0006
        LD_GLOBAL        R2, R1, 48   # 0x000a
        SETP_LT_NPI      P0, R4, R2, 1   # 0x000e
        C_SHLI           R0, 2   # 0x0012
        BRA_PRED         0, L00c2   # 0x0014
        ADD              R5, R3, R0, R3   # 0x0018
        MOVI             R4, 0   # 0x001c
        MOVI             R3, 0   # 0x0020
        ADDI48           R5, R5, 14336   # 0x0024
        MOVI48           R6, 4294952960   # 0x002a
        MOVI48           R7, 4294955008   # 0x0030
        MOVI48           R8, 4294957056   # 0x0036
        MOVI48           R9, 4294959104   # 0x003c
        MOVI48           R10, 4294961152   # 0x0042
L0048:  MOVI48           R11, 4294967288   # 0x0048
        MOVI             R12, 0   # 0x004e
        C_MOV            R13, R5   # 0x0052
L0054:  ADD              R14, R13, R6, R13   # 0x0054
        LD_GLOBAL_SLOT   R14, 1, R14, 0, 0   # 0x0058
        C_FADD           R3, R14   # 0x005c
        ADD              R14, R13, R7, R13   # 0x005e
        LD_GLOBAL_SLOT   R14, 1, R14, 0, 0   # 0x0062
        C_FADD           R3, R14   # 0x0066
        ADD              R14, R13, R8, R13   # 0x0068
        LD_GLOBAL_SLOT   R14, 1, R14, 0, 0   # 0x006c
        C_FADD           R3, R14   # 0x0070
        ADD              R14, R13, R9, R13   # 0x0072
        LD_GLOBAL_SLOT   R14, 1, R14, 0, 0   # 0x0076
        C_FADD           R3, R14   # 0x007a
        ADD              R14, R13, R10, R13   # 0x007c
        LD_GLOBAL_SLOT   R14, 1, R14, 0, 0   # 0x0080
        C_FADD           R3, R14   # 0x0084
        ADDI             R14, R13, -4096   # 0x0086
        LD_GLOBAL_SLOT   R14, 1, R14, 0, 0   # 0x008a
        C_FADD           R3, R14   # 0x008e
        ADDI             R14, R13, -2048   # 0x0090
        LD_GLOBAL_SLOT   R14, 1, R14, 0, 0   # 0x0094
        C_FADD           R3, R14   # 0x0098
        LD_GLOBAL_SLOT   R14, 1, R13, 0, 0   # 0x009a
        C_FADD           R3, R14   # 0x009e
        ADDI48           R12, R12, 4096   # 0x00a0
        ADDI48           R13, R13, 16384   # 0x00a6
        C_ADDI           R11, 8   # 0x00ac
        SETP_LT_U_NPI    P0, R14, R11, 56   # 0x00ae
        BRA_PRED         0, L0054   # 0x00b2
        C_ADDI           R4, 1   # 0x00b6
        SETP_EQ_NP       P0, R11, R4, R2   # 0x00b8
        BRA_PRED         4, L0048   # 0x00bc
        C_BRA            L00c6   # 0x00c0
L00c2:  MOVI             R3, 0   # 0x00c2
L00c6:  LD_GLOBAL        R1, R1, 36   # 0x00c6
        ADD              R0, R1, R0, R1   # 0x00ca
        ST_GLOBAL_SLOT   R3, 0, R0, 0, 0   # 0x00ce
        C_EXIT           0   # 0x00d2
