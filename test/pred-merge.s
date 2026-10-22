# Predicate transfers under divergence (O-62, O-63; CP-11, IS-18): ld.pred and
# st.pred move only the issuing group's lanes. Lanes 0-15 branch apart from
# 16-31, reload P1 from a word of zeros, and store it to another zero word.
# Expected, in window 9:
#   0x90040  P1 afterwards: lanes 16-31 kept their ones      0xffff0000
#   0x90050  the group's store: only lanes 0-15's bits, zero 0x00000000
# A whole-word ld.pred gives 0 at 0x90040; a whole-word st.pred puts lanes
# 16-31's ones into 0x90050.
        SRD          R1, 0              # lane index
        MOVI48       R3, 9              # frame window, warp-uniform
        SETP_LT_NPI  P0, R14, R1, 16    # lanes 0-15
        POR          P1, 5, 1           # P1 = !P1 | P1: all ones
        BRA_PRED     4, join            # lanes 16-31 skip the reload
        LD_PRED_G    2, R3, -4          # P1 from 0x90000, which is zero
        ST_PRED_G    2, R3, 76          # P1 to 0x90050, lanes 0-15 only
join:   ST_PRED_G    2, R3, 60          # P1 out to 0x90040
        C_EXIT       0
