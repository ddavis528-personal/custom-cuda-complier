# Loads are unaffected by F-RO: every lane reads the .const range and the
# kernel runs to its end.
        MOVI48        R3, 5
        LD_GLOBAL     R4, R3, 0
        C_EXIT        0
