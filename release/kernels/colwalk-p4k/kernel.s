# colwalk-p4k: test/cuda/colwalk.cu -DPITCH_KIB=4, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        SRD              R0, 0   # 0x0000
        MOVI             R1, 2   # 0x0002
        LD_GLOBAL        R3, R1, 44   # 0x0006
        LD_GLOBAL        R2, R1, 48   # 0x000a
        SETP_LT_NPI      P0, R4, R2, 1   # 0x000e
        C_SHLI           R0, 2   # 0x0012
        BRA_PRED         0, L00c8   # 0x0014
        ADD              R5, R3, R0, R3   # 0x0018
        MOVI             R4, 0   # 0x001c
        MOVI             R3, 0   # 0x0020
        ADDI48           R5, R5, 28672   # 0x0024
        MOVI48           R6, 4294938624   # 0x002a
        MOVI48           R7, 4294942720   # 0x0030
        MOVI48           R8, 4294946816   # 0x0036
        MOVI48           R9, 4294950912   # 0x003c
        MOVI48           R10, 4294955008   # 0x0042
        MOVI48           R11, 4294959104   # 0x0048
L004e:  MOVI48           R12, 4294967288   # 0x004e
        MOVI             R13, 0   # 0x0054
        C_MOV            R14, R5   # 0x0058
L005a:  ADD              R15, R14, R6, R14   # 0x005a
        LD_GLOBAL_SLOT   R15, 1, R15, 0, 0   # 0x005e
        C_FADD           R3, R15   # 0x0062
        ADD              R15, R14, R7, R14   # 0x0064
        LD_GLOBAL_SLOT   R15, 1, R15, 0, 0   # 0x0068
        C_FADD           R3, R15   # 0x006c
        ADD              R15, R14, R8, R14   # 0x006e
        LD_GLOBAL_SLOT   R15, 1, R15, 0, 0   # 0x0072
        C_FADD           R3, R15   # 0x0076
        ADD              R15, R14, R9, R14   # 0x0078
        LD_GLOBAL_SLOT   R15, 1, R15, 0, 0   # 0x007c
        C_FADD           R3, R15   # 0x0080
        ADD              R15, R14, R10, R14   # 0x0082
        LD_GLOBAL_SLOT   R15, 1, R15, 0, 0   # 0x0086
        C_FADD           R3, R15   # 0x008a
        ADD              R15, R14, R11, R14   # 0x008c
        LD_GLOBAL_SLOT   R15, 1, R15, 0, 0   # 0x0090
        C_FADD           R3, R15   # 0x0094
        ADDI             R15, R14, -4096   # 0x0096
        LD_GLOBAL_SLOT   R15, 1, R15, 0, 0   # 0x009a
        C_FADD           R3, R15   # 0x009e
        LD_GLOBAL_SLOT   R15, 1, R14, 0, 0   # 0x00a0
        C_FADD           R3, R15   # 0x00a4
        ADDI48           R13, R13, 8192   # 0x00a6
        ADDI48           R14, R14, 32768   # 0x00ac
        C_ADDI           R12, 8   # 0x00b2
        SETP_LT_U_NPI    P0, R15, R12, 56   # 0x00b4
        BRA_PRED         0, L005a   # 0x00b8
        C_ADDI           R4, 1   # 0x00bc
        SETP_EQ_NP       P0, R12, R4, R2   # 0x00be
        BRA_PRED         4, L004e   # 0x00c2
        C_BRA            L00cc   # 0x00c6
L00c8:  MOVI             R3, 0   # 0x00c8
L00cc:  LD_GLOBAL        R1, R1, 36   # 0x00cc
        ADD              R0, R1, R0, R1   # 0x00d0
        ST_GLOBAL_SLOT   R3, 0, R0, 0, 0   # 0x00d4
        C_EXIT           0   # 0x00d8
