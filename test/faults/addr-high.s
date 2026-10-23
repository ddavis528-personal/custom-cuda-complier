# F-ADDR (O-75): a .global address is the exact sum, and one at or above 2^48
# maps nothing. The window 0xFFFFFFFF starts at 2^48 - 2^16; lane l indexes
# byte 2^16 - 64 + 4l of it, so lanes 0-15 are below 2^48 and lanes 16-31 at
# or above it. Expect FAULT F-ADDR, lanes 0xffff0000, at 2^48 (lane 16's),
# and nothing stored: lanes 0-15's words keep their pokes.
        SRD           R1, 0
        MOVI48        R3, 4294967295
        SHLI          R1, R1, 2
        ADDI48        R6, R1, 65472
        MOVI          R4, 77
        ST_GLOBAL_IDX R4, R3, R6, 0, 0
        C_EXIT        0
