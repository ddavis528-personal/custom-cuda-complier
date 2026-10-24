# O-69's interleaved spill space, executed. Run with -poke 0x20018=256 (local
# base window 256) and -context 2: the space starts at window 256 + 1024
# (CCV_LANE_CONTEXTS) = 0x5000000, and context 2's frame 8 MiB above it.
#   st.local of lane l's (l + 100) at b = 8: byte 0x5800000 + 128*2 + 4l
#   reloaded, plus 1, to the result window 9 at 4l           (l + 101)
#   a 16-bit store of 0xBEEF at b = 6: the high half of lane l's word 1 cell
#   P1 = lanes 0-15, through st.pred.local at b = 16 (word 1 of its frame,
#   P1's, is b = 20: line 5, lane-0 cell) and back with ld.pred.local into P1
#   after P1 was cleared: lanes 0-15 then store 7 to window 9 at 128 + 4l
        MOVI48     R9, 9               # result window
        SRD        R1, 0               # lane l
        ADDI       R2, R1, 100
        ST_LOCAL   R2, 8
        LD_LOCAL   R3, 8
        ADDI       R3, R3, 1
        ST_GLOBAL_IDX R3, R9, R1, 1, 0
        MOVI       R4, 48879           # 0xBEEF
        C_CHWIDTH  R4, 1
        ST_LOCAL   R4, 6
        C_CHWIDTH  R4, 0
        SETP_LT_NPI P1, R14, R1, 16    # lanes 0-15
        ST_PRED_LOCAL 2, 16
        SETP_LT_NPI P1, R14, R1, 0     # cleared
        LD_PRED_LOCAL 2, 16
        MOVI       R5, 7
        MOVI       R6, 0
        MOV_P      R6, 1, R5, R5, R5   # @P1: lanes 0-15
        ADDI       R7, R1, 32
        ST_GLOBAL_IDX R6, R9, R7, 1, 0
        C_EXIT     0
