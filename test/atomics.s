# Format M atomics, executed (O-72): the base + index address, the RMW forms
# on .global and .shared, and CAS with its success predicate. 32 lanes; R1 is
# the lane's index. Results:
#   window 9  (0x90000): +0 the add counter, +4 max.s, +8 min.u, +12 xor
#   window 8  (0x80000): lane l's old value from the add, at +4l
#   window 10 (0xA0000): lane l's word, exchanged for 3l, at +4l
#   window 12 (0xC0000): lane l's old value from the exchange, at +4l
#   window 11 (0xB0000): lane l's CAS success as 0/1, at +4l; at +0x100, the
#                        shared word after CAS and or
        PMOV_IMM   P3, 1
        SRD        R1, 0               # lane index
        MOVI       R0, 0
        MOVI       R9, 9
        MOVI       R8, 8
        MOVI       R10, 10
        MOVI       R11, 11
        MOVI       R12, 12
        MOVI       R2, 1
        # add: every lane adds 1 to one word; lane l sees l (ascending order)
        ATOM_ADD_G R3, R9, R0, 0, 0, R2
        ST_GLOBAL_IDX R3, R8, R1, 1, 0
        # max.s of l - 16 over -100 is 15, at +4 (displacement)
        ADDI       R4, R1, -16
        ATOM_MAX_S_G R5, R9, R0, 0, 4, R4
        # min.u of l + 5 over 1000 is 5, at +8 (index 2, scaled)
        MOVI       R7, 2
        ADDI       R4, R1, 5
        ATOM_MIN_U_G R5, R9, R7, 1, 0, R4
        # xor of 1 << (l mod 8) at +12 (index 9, displacement 3): each bit is
        # flipped four times, so 0x5A stays 0x5A
        MOVI       R7, 9
        ANDI       R4, R1, 7
        SHL        R5, R2, R4, R2
        ATOM_XOR_G R6, R9, R7, 0, 3, R5
        # exch at a computed element: lane l's word for 3l, scaled index
        MULI       R4, R1, 3
        ATOM_EXCH_G R6, R10, R1, 1, 0, R4
        ST_GLOBAL_IDX R6, R12, R1, 1, 0
        # CAS on .shared word 0: 0 -> l + 1, so only lane 0 sees 0 and succeeds
        ADDI       R4, R1, 1
        CAS_S      R6, P1, 3, R0, R0, 0, 0, R0, R4
        MOVI       R5, 0
        ADDI_P     R5, 1, R5, 1
        ST_GLOBAL_IDX R5, R11, R1, 1, 0
        # or of 1 << l into the same word: 1 | every bit
        SHL        R5, R2, R1, R2
        ATOM_OR_S  R6, R0, R0, 0, 0, R5
        LD_SHARED  R5, R0, 0
        ST_GLOBAL  R5, R11, 256
        C_EXIT     0
