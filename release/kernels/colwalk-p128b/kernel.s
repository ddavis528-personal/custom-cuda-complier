# colwalk-p128b: test/cuda/colwalk.cu -DPITCH_BYTES=128, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        SRD              R0, 0   # 0x0000
        MOVI             R1, 2   # 0x0002
        LD_GLOBAL        R3, R1, 44   # 0x0006
        LD_GLOBAL        R2, R1, 48   # 0x000a
        SETP_LT_NPI      P0, R4, R2, 1   # 0x000e
        C_SHLI           R0, 2   # 0x0012
        BRA_PRED         0, L009e   # 0x0014
        ADD              R5, R3, R0, R3   # 0x0018
        MOVI             R4, 0   # 0x001c
        MOVI             R3, 0   # 0x0020
        ADDI             R5, R5, 896   # 0x0024
L0028:  MOVI48           R6, 4294967288   # 0x0028
        MOVI             R7, 0   # 0x002e
        C_MOV            R8, R5   # 0x0032
L0034:  ADDI             R9, R8, -896   # 0x0034
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x0038
        C_FADD           R3, R9   # 0x003c
        ADDI             R9, R8, -768   # 0x003e
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x0042
        C_FADD           R3, R9   # 0x0046
        ADDI             R9, R8, -640   # 0x0048
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x004c
        C_FADD           R3, R9   # 0x0050
        ADDI             R9, R8, -512   # 0x0052
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x0056
        C_FADD           R3, R9   # 0x005a
        ADDI             R9, R8, -384   # 0x005c
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x0060
        C_FADD           R3, R9   # 0x0064
        ADDI             R9, R8, -256   # 0x0066
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x006a
        C_FADD           R3, R9   # 0x006e
        ADDI             R9, R8, -128   # 0x0070
        LD_GLOBAL_SLOT   R9, 1, R9, 0, 0   # 0x0074
        C_FADD           R3, R9   # 0x0078
        LD_GLOBAL_SLOT   R9, 1, R8, 0, 0   # 0x007a
        C_FADD           R3, R9   # 0x007e
        ADDI             R7, R7, 256   # 0x0080
        ADDI             R8, R8, 1024   # 0x0084
        C_ADDI           R6, 8   # 0x0088
        SETP_LT_U_NPI    P0, R9, R6, 56   # 0x008a
        BRA_PRED         0, L0034   # 0x008e
        C_ADDI           R4, 1   # 0x0092
        SETP_EQ_NP       P0, R6, R4, R2   # 0x0094
        BRA_PRED         4, L0028   # 0x0098
        C_BRA            L00a2   # 0x009c
L009e:  MOVI             R3, 0   # 0x009e
L00a2:  LD_GLOBAL        R1, R1, 36   # 0x00a2
        ADD              R0, R1, R0, R1   # 0x00a6
        ST_GLOBAL_SLOT   R3, 0, R0, 0, 0   # 0x00aa
        C_EXIT           0   # 0x00ae
