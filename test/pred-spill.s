# ld.pred / st.pred (§3, O-19; IS-15): the 16-byte frame is positional -- word
# i holds Pi whatever the mask -- and each predicate is a whole warp's 32 bits,
# addressed through lane 0's rbase. Expected, in window 9 (0x90000):
#   +64, +68, +72   P0, P1, P2 stored together:   0xff, 0xffff, 0xffffff
#   +32             P1 alone, disp 28 = 32 - 4*1:  0xffff  (the backend's form)
#   +56             P1 clobbered to all ones:     0xffffffff
#   +48             P1 after the reload from +32: 0xffff
        SRD          R1, 0              # lane index
        MOVI48       R3, 9              # frame window, warp-uniform
        SETP_LT_NPI  P0, R14, R1, 8     # lanes 0-7
        SETP_LT_NPI  P1, R14, R1, 16    # lanes 0-15
        SETP_LT_NPI  P2, R14, R1, 24    # lanes 0-23
        ST_PRED_G    7, R3, 64
        ST_PRED_G    2, R3, 28
        POR          P1, 5, 1           # P1 = !P1 | P1: all ones (clobbered)
        ST_PRED_G    2, R3, 52          # +56 shows the clobber took: 0xffffffff
        LD_PRED_G    2, R3, 28          # P1 back from +32
        ST_PRED_G    2, R3, 44          # and out to +48
        C_EXIT       0
