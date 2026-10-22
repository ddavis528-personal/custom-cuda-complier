# F-RO is per lane and gated (§12.2): lanes 0-15 branch past the store, so
# only lanes 16-31 execute it. Expect FAULT F-RO, lanes 0xffff0000, at
# 0x50000 (lane 16's, the lowest that executes it).
        SRD           R1, 0
        SETP_LT_NPI   P0, R14, R1, 16
        BRA_PRED      0, done
        MOVI48        R3, 5
        MOVI          R4, 77
        ST_GLOBAL     R4, R3, 0
done:   C_EXIT        0
