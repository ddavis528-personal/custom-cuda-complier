# Every format length, to prove the assembler and the generated decoder agree.
MOVI48     R0, 0x12345         # 48-bit Format F
SRD        R1, 0               # 16-bit Format K
ADD        R2, R3, R4, R5      # 32-bit Format A
C_FADD     R6, R7              # 16-bit Format K, destructive
LD_GLOBAL  R8, R9, 100         # 32-bit Format D
C_EXIT     0
