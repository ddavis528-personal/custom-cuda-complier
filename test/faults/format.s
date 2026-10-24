# F-FORMAT (§12.3): format code 1 names nothing at 32 bits (§4's table), so a
# format-1 operation on 32-bit registers is refused at dispatch, whole issue
# mask, before anything executes.
        MOVI       R1, 1
        FADD_F1    R3, R1, R1, R1
        C_EXIT     0
