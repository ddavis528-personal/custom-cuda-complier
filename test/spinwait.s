# test/cuda/spinwait.cu as the backend compiles it, in ccv-as syntax, so the
# core's skeleton can assemble it (IS-17, O-60). tools/check-spinwait.sh
# requires it to assemble to the same bytes as the compiled .text.
#
# Launch block: flag at slot 0 (window at 0x20020, roffset 0x20024), out at
# slot 1 (0x20028, 0x2002c). Lane 0 spins at `spin` on the flag; lane 1 sets
# it at `release`, a higher PC. Under strict lowest-PC-first this hangs; under
# O-60's fairness it ends with out[0] = 1, out[1] = 7 and the flag 1.
        MOVI           R1, 2
        LD_GLOBAL      R0, R1, 36            # flag.roffset
        SRD            R2, 0                 # lane
        SETP_EQ_NPI    P0, R3, R2, 1
        BRA_PRED       0, release            # lane 1
        SETP_NE_NPI    P0, R1, R2, 0
        BRA_PRED       0, done               # lanes 2-31
        MOVI           R1, 1
spin:   ADDI           R1, R1, -1
        LD_GLOBAL_SLOT R2, 0, R0, 0, 0       # the flag
        SETP_EQ_NPI    P0, R2, R2, 0
        BRA_PRED       0, spin
        SETP_EQ_NPI    P0, R0, R1, 0
        MOVI           R0, 2
        MOVI           R1, 1
        MOV_P          R1, 0, R0, R0, R0
        LD_GLOBAL      R0, R0, 44            # out.roffset
        ST_GLOBAL_SLOT R1, 1, R0, 0, 0       # out[0]
        C_EXIT         0
release: LD_GLOBAL     R1, R1, 44            # out.roffset
        MOVI           R2, 7
        ST_GLOBAL_SLOT R2, 1, R1, 0, 4       # out[1]
        MOVI           R1, 1
        ST_GLOBAL_SLOT R1, 0, R0, 0, 0       # flag = 1
done:   C_EXIT         0
