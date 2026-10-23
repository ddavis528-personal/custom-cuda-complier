# The FP SFU's values, executed (O-70): correctly rounded by default, from
# integer arithmetic alone (tools/ccv-sim/SfuMath.cpp). Each result is a word in
# window 9 (0x90000), in this order; the expected bits are mpmath's, at 400 bits:
#   +0   rcp(40400000) = 3eaaaaab
#   +4   rsqrt(40400000) = 3f13cd3a
#   +8   sqrt(40000000) = 3fb504f3
#   +12  ex2(3f000000) = 3fb504f3
#   +16  ex2(c30c8000) = 0000016a
#   +20  lg2(40400000) = 3fcae00d
#   +24  lg2(3f800001) = 3438aa3a
#   +28  sin(40400000) = 3e1081c3
#   +32  sin(40490fdb) = b3bbbd2e
#   +36  sin(7149f2ca) = bf4a89b0
#   +40  cos(40490fdb) = bf800000
#   +44  cos(3727c5ac) = 3f800000
        MOVI48     R9, 9               # result window
        MOVI48     R1, 1077936128        # 0x40400000
        RCP_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 0
        MOVI48     R1, 1077936128        # 0x40400000
        RSQRT_F32  R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 4
        MOVI48     R1, 1073741824        # 0x40000000
        SQRT_F32   R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 8
        MOVI48     R1, 1056964608        # 0x3f000000
        EX2_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 12
        MOVI48     R1, 3272376320        # 0xc30c8000
        EX2_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 16
        MOVI48     R1, 1077936128        # 0x40400000
        LG2_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 20
        MOVI48     R1, 1065353217        # 0x3f800001
        LG2_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 24
        MOVI48     R1, 1077936128        # 0x40400000
        SIN_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 28
        MOVI48     R1, 1078530011        # 0x40490fdb
        SIN_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 32
        MOVI48     R1, 1900671690        # 0x7149f2ca
        SIN_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 36
        MOVI48     R1, 1078530011        # 0x40490fdb
        COS_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 40
        MOVI48     R1, 925353388         # 0x3727c5ac
        COS_F32    R2, R1, R1, R1
        ST_GLOBAL  R2, R9, 44
        C_EXIT     0
