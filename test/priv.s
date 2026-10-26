# O-83: interleaved per-thread memory. Run with -lane-contexts 1024 and
# -poke 0x20018=256 (local_base), so W = 256 + 3*1024 = 3328 and warp
# context 0's region starts at window W + 1, 0xD010000.
#   (1) Every lane stores lane + 100 at logical byte 8 of the run and loads it
#       back: each gets its own value. Its cell is at 0xD010000 + 128*2 + 4*lane.
#   (2) A halfword store of lane + 100 at logical byte 14 lands in the upper
#       half of the lane's cell at 0xD010000 + 128*3 + 4*lane.
#   (3) The decision is the lowest issuing lane's: lane 0 holds W in R11 and
#       lanes 1-31 hold window 10, and only lanes 1-31 store through R11. So
#       the store is ordinary, and lane l writes lane + 100 to window 10.
# Results: (1)'s loads at window 9, a word a lane.
        SRD          R1, 0              # lane
        MOVI         R2, 2              # the launch window
        LD_GLOBAL    R3, R2, 24         # local_base
        SRD          R4, 3              # %privoff
        ADD          R5, R3, R4, R3     # W
        MOVI48       R9, 9              # result window
        SHLI         R7, R1, 2          # lane * 4
        ADDI         R6, R1, 100
        MOVI         R8, 8
        ST_GLOBAL_IDX R6, R5, R8, 0, 0
        LD_GLOBAL_IDX R10, R5, R8, 0, 0
        ST_GLOBAL_IDX R10, R9, R7, 0, 0
        MOVI         R8, 14
        SZ_GLOBAL_ST_16 R6, R5, R8, 0, 0
        MOVI         R11, 10
        SETP_EQ_NPI  P0, R14, R1, 0     # lane 0
        BRA_PRED     4, l1              # lanes 1-31 skip
        ADDI         R11, R5, 0         # lane 0: R11 = W
l1:     SETP_EQ_NPI  P1, R14, R1, 0
        BRA_PRED     1, done            # lane 0 skips the store
        ST_GLOBAL_IDX R6, R11, R7, 0, 0
done:   C_EXIT       0
