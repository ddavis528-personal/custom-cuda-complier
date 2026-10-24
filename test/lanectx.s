# srd #2, %lanectx (O-64): (hardware warp context << 5) | lane, which the kernel
# prologue adds to local_base for the lane's frame window. ccv-sim gives warp w
# of the CTA context w. Each live lane stores its %lanectx to word %lanectx of
# window 3. Run with -threads 52 -warp 1: words 32-51 hold 32-51.
        SRD           R1, 2              # %lanectx
        MOVI          R3, 3
        ST_GLOBAL_IDX R1, R3, R1, 1, 0   # [0x30000 + 4 ctx] = ctx
        C_EXIT        0
