# c[i] = a[i] + b[i], the §5.6 aligned shape.
#
# Layout (all allocations 2^16-aligned, so in-window offset is zero and the
# index register carries an element index -- O-7 scaling applies, O-23):
#   launch block 0x20000   a 0x30000   b 0x40000   c 0x50000
# Launch block: +0 ntid.x, +4 n, +8 c.rbase, +12 a.rbase, +16 b.rbase

        POR        P0, 4, 0          # P0 = !P0 | P0 = all-ones, into the
                                     # compare's OWN destination. Format C carries
                                     # a MANDATORY qualifier and there is no
                                     # unpredicated compare, so a true predicate
                                     # has to be manufactured; Format K is never
                                     # predicated, which breaks the cycle. Writing
                                     # it into the compare's destination costs one
                                     # predicate, not two. See O-24 addendum.
        MOVI48     R0, 2             # launch base >> 16
        SRD        R1, 0             # %ctatid
        SRD        R2, 1             # %ctaid
        LD_GLOBAL  R3, R0, 0         # blockDim.x
        MADLO      R1, R2, R3, R1    # i = ctaid*ntid + tid
        LD_GLOBAL  R4, R0, 4         # n
        SETP_LT    P0, R15, 0, R1, R4   # @P0 setp.lt P0, i, n -- self-guarding
        BRA_PRED   4, Lexit          # @!P0 bra Lexit
        LD_GLOBAL  R5, R0, 8         # c.rbase
        LD_GLOBAL  R6, R0, 12        # a.rbase
        LD_GLOBAL  R7, R0, 16        # b.rbase
        LD_GLOBAL_IDX R8, R6, R1, 1, 0   # a[i], scale-enable set
        LD_GLOBAL_IDX R9, R7, R1, 1, 0   # b[i]
        C_ADD      R8, R9            # compressed destructive, rd == rs0
        ST_GLOBAL_IDX R8, R5, R1, 1, 0   # c[i]
Lexit:
        C_EXIT     0
