# One warp of a CTA of several (TI-29): -warp=w makes lane L thread 32w + L,
# with lanes [0, min(32, T - 32w)) live. Each live lane stores its thread index
# to word tid of window 3. Run with -threads 52 -warp 1: words 32-51 hold 32-51,
# and word 52, lane 20's had it run, keeps its poked value.
        SRD           R1, 0              # %ctatid: the thread's index in its CTA
        MOVI          R3, 3
        ST_GLOBAL_IDX R1, R3, R1, 1, 0   # [0x30000 + 4 tid] = tid
        C_EXIT        0
