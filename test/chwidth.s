# chwidth: per-register element width, exercised end to end (F-3).
#
# Four things this pins that nothing else does:
#   - `chwidth` REINTERPRETS a register rather than converting it (§3).
#   - transfer size follows rdata's chwidth (§3): a 16-bit load moves two bytes.
#   - arithmetic wraps at the element width, not at 32.
#   - WIDENING A NARROW REGISTER YIELDS ZEROS, AND THAT IS A SECURITY
#     REQUIREMENT (O-38). §1 says a narrow register is "a narrower physical
#     slice of a row", so the bits above the element hold whatever last
#     occupied that slice. On a GPU the register file is partitioned between
#     resident warps and reused across kernel launches without clearing, so
#     handing those bits back is a cross-context read. R2 is loaded with
#     0xEFBEADC9 while wide and narrowed; if the widening at the end ever
#     produces 0xEFBExxxx instead of 0x0000xxxx, the machine is leaking.
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
        C_CHWIDTH  R2, 0             # widen: the exposed bits must be CLEARED,
                                     # not whatever was in that slice before
        ST_GLOBAL  R2, R0, 32        # four bytes -- must be 0x0000BEF2

# --- narrow .shared, same contract (§3): transfer size from rdata's chwidth.
# Shared memory starts zeroed, so a 16-bit store at offset 0 must leave the
# halfword at offset 2 alone. Reading the whole word back at 32 bits shows
# both halves at once.
        MOVI48     R5, 0             # shared base
        C_CHWIDTH  R6, 1             # R6 is 16-bit
        MOVI       R6, 43981         # 0xABCD -- narrow write, low half only
        ST_SHARED  R6, R5, 0         # two bytes
        C_CHWIDTH  R7, 0             # R7 stays 32-bit
        LD_SHARED  R7, R5, 0         # four bytes: 0x0000ABCD if the store was
                                     # two bytes, 0xABCDABCD-ish if it was four
        ST_GLOBAL  R7, R0, 48
        C_EXIT     0
