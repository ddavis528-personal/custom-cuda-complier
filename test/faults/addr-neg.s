# F-ADDR (O-75): a sum below 0 does not wrap. Window 0, displacement -4:
# every lane's address is -4. Expect FAULT F-ADDR, lanes 0xffffffff, at the
# address as generated, in full (§12.6): 0xfffffffffffffffc.
        MOVI          R3, 0
        LD_GLOBAL     R4, R3, -4
        C_EXIT        0
