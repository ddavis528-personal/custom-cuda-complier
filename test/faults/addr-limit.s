# F-ADDR's control: the last word below 2^48 is mapped. Every lane stores 77
# to 2^48 - 4 (window 0xFFFFFFFF, byte 0xFFFC); no fault, and it lands.
        MOVI48        R3, 4294967295
        MOVI48        R6, 65532
        MOVI          R4, 77
        ST_GLOBAL_IDX R4, R3, R6, 0, 0
        C_EXIT        0
