# chwidth: per-register element width, exercised end to end (F-3).
#
# Four things this pins that nothing else does:
#   - `chwidth` REINTERPRETS a register rather than converting it (§3).
#   - transfer size follows rdata's chwidth (§3): a 16-bit load moves two bytes.
#   - arithmetic wraps at the element width, not at 32.
#   - WIDENING A NARROW REGISTER YIELDS UNSPECIFIED HIGH BITS. §1 says a narrow
#     register is "a narrower physical slice of a row", so the bits above the
#     element are not written while narrow and the specification never says what
#     a later widening finds. The simulator preserves the prior contents, which
#     makes the hazard visible instead of handing out convenient zeros. F-65.
#
# Data window 0x30000. Inputs at +0/+2 as 16-bit; results at +16 and +32.
        MOVI48     R0, 3             # .global window 3 -> byte address 0x30000
        MOVI48     R2, 4023233417    # 0xEFBEADC9 into R2 while it is still 32-bit
        C_CHWIDTH  R2, 1             # R2 is now 16-bit: the top half is now
                                     # outside the register
        C_CHWIDTH  R3, 1
        LD_GLOBAL  R2, R0, 0         # two bytes -- writes the element only
        LD_GLOBAL  R3, R0, 2         # two bytes
        ADD        R2, R2, R3, R2    # wraps at 16 bits (rs2 unread)
        ST_GLOBAL  R2, R0, 16        # two bytes: the 16-bit answer
        C_CHWIDTH  R2, 0             # widen: the top half comes back, and what
                                     # it holds is not specified by the ISA
        ST_GLOBAL  R2, R0, 32        # four bytes -- shows the stale top half
        C_EXIT     0
