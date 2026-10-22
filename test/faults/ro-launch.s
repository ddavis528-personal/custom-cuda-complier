# The whole launch window is read-only (§5.2, O-61): a store to window 2,
# here 0x20040 past any launch-block word a test pokes, raises F-RO with no
# .const range set at all. Expect every lane at 0x20040.
        MOVI          R3, 2
        MOVI          R4, 77
        ST_GLOBAL     R4, R3, 64
        C_EXIT        0
