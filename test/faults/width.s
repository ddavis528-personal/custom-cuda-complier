# F-WIDTH is a dispatch fault (§12.3): a memory access whose rdata is at
# chwidth = 4. Dispatch faults ignore the predicate (§12.2), so it fires even
# with P0 false in every lane, reporting the whole issue mask.
        SRD          R1, 0
        MOVI48       R3, 5
        SETP_LT_NPI  P0, R14, R1, 0
        C_CHWIDTH    R4, 3
        LD_GLOBAL_P  R4, 0, R3, 0
        C_EXIT       0
