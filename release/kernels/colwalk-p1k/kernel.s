# colwalk-p1k: test/cuda/colwalk.cu -DPITCH_KIB=1, compiled; ccv-as source,
# reassembled byte for byte by tools/ccv-dis.py --check. Load at ccv-sim's
# -code-base; entry at offset 0.
        SRD              R0, 0   # 0x0000
        MOVI             R1, 2   # 0x0002
        LD_GLOBAL        R3, R1, 44   # 0x0006
        LD_GLOBAL        R2, R1, 48   # 0x000a
        SETP_LT_NPI      P0, R4, R2, 1   # 0x000e
        C_SHLI           R0, 2   # 0x0012
        BRA_PRED         0, L00b4   # 0x0014
        ADD              R5, R3, R0, R3   # 0x0018
        MOVI             R4, 0   # 0x001c
        MOVI             R3, 0   # 0x0020
        ADDI48           R5, R5, 7168   # 0x0024
        MOVI48           R6, 4294960128   # 0x002a
        MOVI48           R7, 4294961152   # 0x0030
        MOVI48           R8, 4294962176   # 0x0036
L003c:  MOVI48           R9, 4294967288   # 0x003c
        MOVI             R10, 0   # 0x0042
        C_MOV            R11, R5   # 0x0046
L0048:  ADD              R12, R11, R6, R11   # 0x0048
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x004c
        C_FADD           R3, R12   # 0x0050
        ADD              R12, R11, R7, R11   # 0x0052
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0056
        C_FADD           R3, R12   # 0x005a
        ADD              R12, R11, R8, R11   # 0x005c
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0060
        C_FADD           R3, R12   # 0x0064
        ADDI             R12, R11, -4096   # 0x0066
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x006a
        C_FADD           R3, R12   # 0x006e
        ADDI             R12, R11, -3072   # 0x0070
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0074
        C_FADD           R3, R12   # 0x0078
        ADDI             R12, R11, -2048   # 0x007a
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x007e
        C_FADD           R3, R12   # 0x0082
        ADDI             R12, R11, -1024   # 0x0084
        LD_GLOBAL_SLOT   R12, 1, R12, 0, 0   # 0x0088
        C_FADD           R3, R12   # 0x008c
        LD_GLOBAL_SLOT   R12, 1, R11, 0, 0   # 0x008e
        C_FADD           R3, R12   # 0x0092
        ADDI             R10, R10, 2048   # 0x0094
        ADDI48           R11, R11, 8192   # 0x0098
        C_ADDI           R9, 8   # 0x009e
        SETP_LT_U_NPI    P0, R12, R9, 56   # 0x00a0
        BRA_PRED         0, L0048   # 0x00a4
        C_ADDI           R4, 1   # 0x00a8
        SETP_EQ_NP       P0, R9, R4, R2   # 0x00aa
        BRA_PRED         4, L003c   # 0x00ae
        C_BRA            L00b8   # 0x00b2
L00b4:  MOVI             R3, 0   # 0x00b4
L00b8:  LD_GLOBAL        R1, R1, 36   # 0x00b8
        ADD              R0, R1, R0, R1   # 0x00bc
        ST_GLOBAL_SLOT   R3, 0, R0, 0, 0   # 0x00c0
        C_EXIT           0   # 0x00c4
