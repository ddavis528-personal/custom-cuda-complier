# A fault on st.pred is the whole issuing group's (§3, ISA 46a1643): the access
# is one warp-scoped word at lane 0's address, so the record's lanes are the
# issue mask and its address the access's. Lanes 16-31 store P0 into the launch
# window, which is read-only (O-61); lane 0 forms the address but did not
# issue. Expect lanes ffff0000 at 0x20040, not lane 0 alone.
        SRD          R1, 0              # lane index
        MOVI         R3, 2              # the launch window
        SETP_LT_NPI  P0, R14, R1, 16    # lanes 0-15
        BRA_PRED     0, done            # lanes 0-15 leave
        ST_PRED_G    1, R3, 64          # P0 to 0x20040
done:   C_EXIT       0
