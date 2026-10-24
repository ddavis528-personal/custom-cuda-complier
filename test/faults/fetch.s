# F-FETCH (§12.3, §3 Format E): ret to an odd offset. The image loads at 0x1000.
        MOVI         R5, 0x1001
        C_RET        80                 # ret R5
        C_EXIT       0
