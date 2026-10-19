# call and ret (F-21): a value-returning call, a two-deep chain on two link
# registers, and an indirect call whose lanes return from different callees.
# Results land at 0x50000 (direct), 0x60000 (nested), 0x70000 (indirect),
# one word per lane, and at 0x80000 the link value itself, which must be the
# byte address of the instruction after the call.
        SRD        R2, 0                # lane
        C_MOV      R1, R2
        CALL       R14, triple1         # R1 = 3*lane + 1
after1: MOVI48     R3, 5
        ST_GLOBAL_IDX R1, R3, R2, 1, 0
        MOVI48     R3, 8
        ST_GLOBAL_IDX R14, R3, R2, 1, 0 # the link value
        C_MOV      R1, R2
        CALL       R13, outer           # R1 = 3*lane + 1 + 100
        MOVI48     R3, 6
        ST_GLOBAL_IDX R1, R3, R2, 1, 0
        ANDI       R5, R2, 1            # odd lanes -> plus7, even -> triple1
        MOVI       R6, @plus7-@triple1
        MUL_LO     R5, R5, R6, R5
        MOVI       R6, @triple1
        ADD        R5, R5, R6, R5       # per-lane target
        C_MOV      R1, R2
        CALL       R14, stub            # indirect: link in R14, then ret R5
        MOVI48     R3, 7
        ST_GLOBAL_IDX R1, R3, R2, 1, 0
        C_EXIT     0
stub:   C_RET      80                   # ret R5
outer:  CALL       R14, triple1         # nested: outer's own link is in R13
        ADDI       R1, R1, 100
        C_RET      208                  # ret R13
triple1: MULI      R1, R1, 3
        ADDI       R1, R1, 1
        C_RET      224                  # ret R14
plus7:  ADDI       R1, R1, 7
        C_RET      224
