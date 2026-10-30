/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Machine Code Emitter                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

uint64_t CCVMCCodeEmitter::getBinaryCodeForInstr(const MCInst &MI,
    SmallVectorImpl<MCFixup> &Fixups,
    const MCSubtargetInfo &STI) const {
  static const uint64_t InstBits[] = {
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(1280),	// ABS
    UINT64_C(0),	// ADD
    UINT64_C(12),	// ADDI
    UINT64_C(15),	// ADDI48
    UINT64_C(16),	// ADDI_P
    UINT64_C(20),	// ADDI_PP
    UINT64_C(12),	// ADDI_W16
    UINT64_C(4),	// ADD_P
    UINT64_C(8),	// ADD_PP
    UINT64_C(0),	// ADD_W16
    UINT64_C(448),	// AND
    UINT64_C(460),	// ANDI
    UINT64_C(464),	// ANDI_P
    UINT64_C(640),	// ANDN
    UINT64_C(652),	// ANDNI
    UINT64_C(656),	// ANDNI_P
    UINT64_C(452),	// AND_P
    UINT64_C(448),	// AND_W16
    UINT64_C(612),	// ATOM_ADD_F_G
    UINT64_C(1636),	// ATOM_ADD_F_S
    UINT64_C(36),	// ATOM_ADD_G
    UINT64_C(1060),	// ATOM_ADD_S
    UINT64_C(356),	// ATOM_AND_G
    UINT64_C(1380),	// ATOM_AND_S
    UINT64_C(548),	// ATOM_EXCH_G
    UINT64_C(1572),	// ATOM_EXCH_S
    UINT64_C(228),	// ATOM_MAX_S_G
    UINT64_C(1252),	// ATOM_MAX_S_S
    UINT64_C(292),	// ATOM_MAX_U_G
    UINT64_C(1316),	// ATOM_MAX_U_S
    UINT64_C(100),	// ATOM_MIN_S_G
    UINT64_C(1124),	// ATOM_MIN_S_S
    UINT64_C(164),	// ATOM_MIN_U_G
    UINT64_C(1188),	// ATOM_MIN_U_S
    UINT64_C(420),	// ATOM_OR_G
    UINT64_C(1444),	// ATOM_OR_S
    UINT64_C(484),	// ATOM_XOR_G
    UINT64_C(1508),	// ATOM_XOR_S
    UINT64_C(560),	// BALLOT
    UINT64_C(232),	// BAR_INIT
    UINT64_C(296),	// BAR_WAIT_PHASE
    UINT64_C(40),	// BRA
    UINT64_C(104),	// BRA_PRED
    UINT64_C(1536),	// BREV
    UINT64_C(168),	// CALL
    UINT64_C(1063),	// CAS_G
    UINT64_C(1127),	// CAS_S
    UINT64_C(56),	// CHWIDTH_MULTI
    UINT64_C(1472),	// CLZ
    UINT64_C(1073742208),	// COS_F32
    UINT64_C(268435456),	// CVT_D0_S0_R0
    UINT64_C(2147483652),	// CVT_D0_S0_R0_P
    UINT64_C(268435456),	// CVT_D0_S0_R0_W16_32
    UINT64_C(268435456),	// CVT_D0_S0_R0_W16_8
    UINT64_C(268435456),	// CVT_D0_S0_R0_W32_16
    UINT64_C(268435456),	// CVT_D0_S0_R0_W32_4
    UINT64_C(268435456),	// CVT_D0_S0_R0_W32_8
    UINT64_C(268435456),	// CVT_D0_S0_R0_W4_32
    UINT64_C(268435456),	// CVT_D0_S0_R0_W8_32
    UINT64_C(268435520),	// CVT_D0_S0_R1
    UINT64_C(2147483716),	// CVT_D0_S0_R1_P
    UINT64_C(268435584),	// CVT_D0_S0_R2
    UINT64_C(2147483780),	// CVT_D0_S0_R2_P
    UINT64_C(268435648),	// CVT_D0_S0_R3
    UINT64_C(2147483844),	// CVT_D0_S0_R3_P
    UINT64_C(268435712),	// CVT_D0_S1_R0
    UINT64_C(2147483908),	// CVT_D0_S1_R0_P
    UINT64_C(268435712),	// CVT_D0_S1_R0_W16_8
    UINT64_C(268435712),	// CVT_D0_S1_R0_W32_8
    UINT64_C(268435776),	// CVT_D0_S1_R1
    UINT64_C(2147483972),	// CVT_D0_S1_R1_P
    UINT64_C(268435840),	// CVT_D0_S1_R2
    UINT64_C(2147484036),	// CVT_D0_S1_R2_P
    UINT64_C(268435904),	// CVT_D0_S1_R3
    UINT64_C(2147484100),	// CVT_D0_S1_R3_P
    UINT64_C(268436032),	// CVT_D0_S2_R1
    UINT64_C(2147484228),	// CVT_D0_S2_R1_P
    UINT64_C(268436096),	// CVT_D0_S2_R2
    UINT64_C(2147484292),	// CVT_D0_S2_R2_P
    UINT64_C(268436160),	// CVT_D0_S2_R3
    UINT64_C(2147484356),	// CVT_D0_S2_R3_P
    UINT64_C(268436288),	// CVT_D0_S3_R1
    UINT64_C(2147484484),	// CVT_D0_S3_R1_P
    UINT64_C(268436352),	// CVT_D0_S3_R2
    UINT64_C(2147484548),	// CVT_D0_S3_R2_P
    UINT64_C(268436416),	// CVT_D0_S3_R3
    UINT64_C(2147484612),	// CVT_D0_S3_R3_P
    UINT64_C(268436480),	// CVT_D1_S0_R0
    UINT64_C(2147484676),	// CVT_D1_S0_R0_P
    UINT64_C(268436480),	// CVT_D1_S0_R0_W8_32
    UINT64_C(268436544),	// CVT_D1_S0_R1
    UINT64_C(2147484740),	// CVT_D1_S0_R1_P
    UINT64_C(268436608),	// CVT_D1_S0_R2
    UINT64_C(2147484804),	// CVT_D1_S0_R2_P
    UINT64_C(268436672),	// CVT_D1_S0_R3
    UINT64_C(2147484868),	// CVT_D1_S0_R3_P
    UINT64_C(268436736),	// CVT_D1_S1_R0
    UINT64_C(2147484932),	// CVT_D1_S1_R0_P
    UINT64_C(268436800),	// CVT_D1_S1_R1
    UINT64_C(2147484996),	// CVT_D1_S1_R1_P
    UINT64_C(268436864),	// CVT_D1_S1_R2
    UINT64_C(2147485060),	// CVT_D1_S1_R2_P
    UINT64_C(268436928),	// CVT_D1_S1_R3
    UINT64_C(2147485124),	// CVT_D1_S1_R3_P
    UINT64_C(268436992),	// CVT_D1_S2_R0
    UINT64_C(2147485188),	// CVT_D1_S2_R0_P
    UINT64_C(268437056),	// CVT_D1_S2_R1
    UINT64_C(2147485252),	// CVT_D1_S2_R1_P
    UINT64_C(268437120),	// CVT_D1_S2_R2
    UINT64_C(2147485316),	// CVT_D1_S2_R2_P
    UINT64_C(268437184),	// CVT_D1_S2_R3
    UINT64_C(2147485380),	// CVT_D1_S2_R3_P
    UINT64_C(268437248),	// CVT_D1_S3_R0
    UINT64_C(2147485444),	// CVT_D1_S3_R0_P
    UINT64_C(268437312),	// CVT_D1_S3_R1
    UINT64_C(2147485508),	// CVT_D1_S3_R1_P
    UINT64_C(268437376),	// CVT_D1_S3_R2
    UINT64_C(2147485572),	// CVT_D1_S3_R2_P
    UINT64_C(268437440),	// CVT_D1_S3_R3
    UINT64_C(2147485636),	// CVT_D1_S3_R3_P
    UINT64_C(402653184),	// CVT_D2_S0_R0
    UINT64_C(3221225476),	// CVT_D2_S0_R0_P
    UINT64_C(402653312),	// CVT_D2_S0_R2
    UINT64_C(3221225604),	// CVT_D2_S0_R2_P
    UINT64_C(402653376),	// CVT_D2_S0_R3
    UINT64_C(3221225668),	// CVT_D2_S0_R3_P
    UINT64_C(402653440),	// CVT_D2_S1_R0
    UINT64_C(3221225732),	// CVT_D2_S1_R0_P
    UINT64_C(402653504),	// CVT_D2_S1_R1
    UINT64_C(3221225796),	// CVT_D2_S1_R1_P
    UINT64_C(402653568),	// CVT_D2_S1_R2
    UINT64_C(3221225860),	// CVT_D2_S1_R2_P
    UINT64_C(402653632),	// CVT_D2_S1_R3
    UINT64_C(3221225924),	// CVT_D2_S1_R3_P
    UINT64_C(402653952),	// CVT_D2_S3_R0
    UINT64_C(3221226244),	// CVT_D2_S3_R0_P
    UINT64_C(402654208),	// CVT_D3_S0_R0
    UINT64_C(3221226500),	// CVT_D3_S0_R0_P
    UINT64_C(402654336),	// CVT_D3_S0_R2
    UINT64_C(3221226628),	// CVT_D3_S0_R2_P
    UINT64_C(402654400),	// CVT_D3_S0_R3
    UINT64_C(3221226692),	// CVT_D3_S0_R3_P
    UINT64_C(402654464),	// CVT_D3_S1_R0
    UINT64_C(3221226756),	// CVT_D3_S1_R0_P
    UINT64_C(402654528),	// CVT_D3_S1_R1
    UINT64_C(3221226820),	// CVT_D3_S1_R1_P
    UINT64_C(402654592),	// CVT_D3_S1_R2
    UINT64_C(3221226884),	// CVT_D3_S1_R2_P
    UINT64_C(402654656),	// CVT_D3_S1_R3
    UINT64_C(3221226948),	// CVT_D3_S1_R3_P
    UINT64_C(402654720),	// CVT_D3_S2_R0
    UINT64_C(3221227012),	// CVT_D3_S2_R0_P
    UINT64_C(402654976),	// CVT_D3_S3_R0
    UINT64_C(3221227268),	// CVT_D3_S3_R0_P
    UINT64_C(268435968),	// CVT_F32_S32
    UINT64_C(2147484164),	// CVT_F32_S32_P
    UINT64_C(268436224),	// CVT_F32_U32
    UINT64_C(2147484420),	// CVT_F32_U32_P
    UINT64_C(402653248),	// CVT_S32_F32
    UINT64_C(3221225540),	// CVT_S32_F32_P
    UINT64_C(402653696),	// CVT_SEXT
    UINT64_C(402654272),	// CVT_U32_F32
    UINT64_C(3221226564),	// CVT_U32_F32_P
    UINT64_C(70),	// C_ABS
    UINT64_C(2),	// C_ADD
    UINT64_C(130),	// C_ADDI
    UINT64_C(14),	// C_AND
    UINT64_C(138),	// C_ANDI
    UINT64_C(26),	// C_ANDN
    UINT64_C(206),	// C_BAR_ARRIVE
    UINT64_C(210),	// C_BAR_WAIT
    UINT64_C(198),	// C_BRA
    UINT64_C(194),	// C_CHWIDTH
    UINT64_C(218),	// C_EXIT
    UINT64_C(74),	// C_FADD
    UINT64_C(226),	// C_FENCE
    UINT64_C(94),	// C_FMAX
    UINT64_C(90),	// C_FMIN
    UINT64_C(82),	// C_FMUL
    UINT64_C(98),	// C_LD_GLOBAL
    UINT64_C(50),	// C_MAX_S
    UINT64_C(54),	// C_MAX_U
    UINT64_C(42),	// C_MIN_S
    UINT64_C(46),	// C_MIN_U
    UINT64_C(58),	// C_MOV
    UINT64_C(10),	// C_MUL_LO
    UINT64_C(62),	// C_NEG
    UINT64_C(66),	// C_NOT
    UINT64_C(18),	// C_OR
    UINT64_C(142),	// C_ORI
    UINT64_C(222),	// C_RECONV
    UINT64_C(214),	// C_RET
    UINT64_C(30),	// C_SHL
    UINT64_C(150),	// C_SHLI
    UINT64_C(34),	// C_SHR
    UINT64_C(154),	// C_SHRI
    UINT64_C(38),	// C_SRA
    UINT64_C(158),	// C_SRAI
    UINT64_C(102),	// C_ST_GLOBAL
    UINT64_C(6),	// C_SUB
    UINT64_C(134),	// C_SUBI
    UINT64_C(22),	// C_XOR
    UINT64_C(146),	// C_XORI
    UINT64_C(134219008),	// DP2_BF16
    UINT64_C(134219072),	// DP2_F16
    UINT64_C(9),	// DP4_ACC
    UINT64_C(134219136),	// DP4_E4M3
    UINT64_C(134219200),	// DP4_E5M2
    UINT64_C(134218752),	// DP4_SS
    UINT64_C(1073742016),	// EX2_F32
    UINT64_C(134218176),	// FABS_F0
    UINT64_C(134218688),	// FABS_F1
    UINT64_C(134217728),	// FADD
    UINT64_C(134218240),	// FADD_F1
    UINT64_C(134218240),	// FADD_F1_W8
    UINT64_C(1073741828),	// FADD_P
    UINT64_C(134217728),	// FADD_W8
    UINT64_C(1),	// FFMA_ACC_F0
    UINT64_C(5),	// FFMA_ACC_F1
    UINT64_C(134217920),	// FFMA_F0
    UINT64_C(134218432),	// FFMA_F1
    UINT64_C(134218048),	// FMAX
    UINT64_C(134218560),	// FMAX_F1
    UINT64_C(134217984),	// FMIN
    UINT64_C(134218496),	// FMIN_F1
    UINT64_C(134217856),	// FMUL
    UINT64_C(134218368),	// FMUL_F1
    UINT64_C(134218368),	// FMUL_F1_W8
    UINT64_C(1073741956),	// FMUL_P
    UINT64_C(134217856),	// FMUL_W8
    UINT64_C(134218112),	// FNEG_F0
    UINT64_C(134218624),	// FNEG_F1
    UINT64_C(134217792),	// FSUB
    UINT64_C(134218304),	// FSUB_F1
    UINT64_C(134218304),	// FSUB_F1_W8
    UINT64_C(1073741892),	// FSUB_P
    UINT64_C(134217792),	// FSUB_W8
    UINT64_C(32),	// LD_GLOBAL
    UINT64_C(288),	// LD_GLOBAL_IDX
    UINT64_C(288),	// LD_GLOBAL_IDX_W16
    UINT64_C(288),	// LD_GLOBAL_IDX_W8
    UINT64_C(52),	// LD_GLOBAL_P
    UINT64_C(800),	// LD_GLOBAL_SLOT
    UINT64_C(800),	// LD_GLOBAL_SLOT_W16
    UINT64_C(800),	// LD_GLOBAL_SLOT_W8
    UINT64_C(32),	// LD_GLOBAL_W16
    UINT64_C(32),	// LD_GLOBAL_W8
    UINT64_C(1056),	// LD_LOCAL
    UINT64_C(544),	// LD_PRED_G
    UINT64_C(1184),	// LD_PRED_LOCAL
    UINT64_C(672),	// LD_PRED_S
    UINT64_C(160),	// LD_SHARED
    UINT64_C(416),	// LD_SHARED_IDX
    UINT64_C(160),	// LD_SHARED_W16
    UINT64_C(160),	// LD_SHARED_W8
    UINT64_C(1073742080),	// LG2_F32
    UINT64_C(320),	// MADLO
    UINT64_C(324),	// MADLO_P
    UINT64_C(13),	// MAD_ACC
    UINT64_C(1024),	// MAX_S
    UINT64_C(1028),	// MAX_S_P
    UINT64_C(1024),	// MAX_S_W16
    UINT64_C(1088),	// MAX_U
    UINT64_C(1092),	// MAX_U_P
    UINT64_C(896),	// MIN_S
    UINT64_C(900),	// MIN_S_P
    UINT64_C(896),	// MIN_S_W16
    UINT64_C(960),	// MIN_U
    UINT64_C(964),	// MIN_U_P
    UINT64_C(44),	// MOVI
    UINT64_C(47),	// MOVI48
    UINT64_C(1156),	// MOV_P
    UINT64_C(140),	// MULI
    UINT64_C(144),	// MULI_P
    UINT64_C(192),	// MUL_HI_S
    UINT64_C(196),	// MUL_HI_S_P
    UINT64_C(256),	// MUL_HI_U
    UINT64_C(260),	// MUL_HI_U_P
    UINT64_C(128),	// MUL_LO
    UINT64_C(1344),	// NEG
    UINT64_C(512),	// OR
    UINT64_C(524),	// ORI
    UINT64_C(528),	// ORI_P
    UINT64_C(516),	// OR_P
    UINT64_C(512),	// OR_W16
    UINT64_C(1292),	// PACKI
    UINT64_C(1356),	// PACKI_Z
    UINT64_C(242),	// PAND
    UINT64_C(254),	// PMOV
    UINT64_C(123),	// PMOV_IMM
    UINT64_C(1408),	// POPC
    UINT64_C(246),	// POR
    UINT64_C(250),	// PXOR
    UINT64_C(1073741824),	// RCP_F32
    UINT64_C(8589934599),	// RCP_F32_P
    UINT64_C(1073742272),	// RCP_U32
    UINT64_C(1073741888),	// RSQRT_F32
    UINT64_C(1220),	// SEL
    UINT64_C(152),	// SETP_EQ
    UINT64_C(792),	// SETP_EQ_F
    UINT64_C(8389400),	// SETP_EQ_F1
    UINT64_C(8389436),	// SETP_EQ_F1_NP
    UINT64_C(796),	// SETP_EQ_F_I
    UINT64_C(828),	// SETP_EQ_F_NP
    UINT64_C(134218556),	// SETP_EQ_F_NPI
    UINT64_C(156),	// SETP_EQ_I
    UINT64_C(188),	// SETP_EQ_NP
    UINT64_C(134217916),	// SETP_EQ_NPI
    UINT64_C(344),	// SETP_GE
    UINT64_C(984),	// SETP_GE_F
    UINT64_C(8389592),	// SETP_GE_F1
    UINT64_C(8389628),	// SETP_GE_F1_NP
    UINT64_C(988),	// SETP_GE_F_I
    UINT64_C(1020),	// SETP_GE_F_NP
    UINT64_C(134218748),	// SETP_GE_F_NPI
    UINT64_C(348),	// SETP_GE_I
    UINT64_C(380),	// SETP_GE_NP
    UINT64_C(134218108),	// SETP_GE_NPI
    UINT64_C(600),	// SETP_GE_U
    UINT64_C(604),	// SETP_GE_U_I
    UINT64_C(636),	// SETP_GE_U_NP
    UINT64_C(134218364),	// SETP_GE_U_NPI
    UINT64_C(280),	// SETP_GT
    UINT64_C(920),	// SETP_GT_F
    UINT64_C(8389528),	// SETP_GT_F1
    UINT64_C(8389564),	// SETP_GT_F1_NP
    UINT64_C(924),	// SETP_GT_F_I
    UINT64_C(956),	// SETP_GT_F_NP
    UINT64_C(134218684),	// SETP_GT_F_NPI
    UINT64_C(284),	// SETP_GT_I
    UINT64_C(316),	// SETP_GT_NP
    UINT64_C(134218044),	// SETP_GT_NPI
    UINT64_C(536),	// SETP_GT_U
    UINT64_C(540),	// SETP_GT_U_I
    UINT64_C(572),	// SETP_GT_U_NP
    UINT64_C(134218300),	// SETP_GT_U_NPI
    UINT64_C(88),	// SETP_LE
    UINT64_C(728),	// SETP_LE_F
    UINT64_C(8389336),	// SETP_LE_F1
    UINT64_C(8389372),	// SETP_LE_F1_NP
    UINT64_C(732),	// SETP_LE_F_I
    UINT64_C(764),	// SETP_LE_F_NP
    UINT64_C(134218492),	// SETP_LE_F_NPI
    UINT64_C(92),	// SETP_LE_I
    UINT64_C(124),	// SETP_LE_NP
    UINT64_C(134217852),	// SETP_LE_NPI
    UINT64_C(472),	// SETP_LE_U
    UINT64_C(476),	// SETP_LE_U_I
    UINT64_C(508),	// SETP_LE_U_NP
    UINT64_C(134218236),	// SETP_LE_U_NPI
    UINT64_C(24),	// SETP_LT
    UINT64_C(664),	// SETP_LT_F
    UINT64_C(8389272),	// SETP_LT_F1
    UINT64_C(8389308),	// SETP_LT_F1_NP
    UINT64_C(668),	// SETP_LT_F_I
    UINT64_C(700),	// SETP_LT_F_NP
    UINT64_C(134218428),	// SETP_LT_F_NPI
    UINT64_C(28),	// SETP_LT_I
    UINT64_C(60),	// SETP_LT_NP
    UINT64_C(134217788),	// SETP_LT_NPI
    UINT64_C(408),	// SETP_LT_U
    UINT64_C(412),	// SETP_LT_U_I
    UINT64_C(444),	// SETP_LT_U_NP
    UINT64_C(134218172),	// SETP_LT_U_NPI
    UINT64_C(216),	// SETP_NE
    UINT64_C(856),	// SETP_NE_F
    UINT64_C(8389464),	// SETP_NE_F1
    UINT64_C(8389500),	// SETP_NE_F1_NP
    UINT64_C(860),	// SETP_NE_F_I
    UINT64_C(892),	// SETP_NE_F_NP
    UINT64_C(134218620),	// SETP_NE_F_NPI
    UINT64_C(220),	// SETP_NE_I
    UINT64_C(252),	// SETP_NE_NP
    UINT64_C(134217980),	// SETP_NE_NPI
    UINT64_C(48),	// SHFL_IDX
    UINT64_C(704),	// SHL
    UINT64_C(716),	// SHLI
    UINT64_C(720),	// SHLI_P
    UINT64_C(708),	// SHL_P
    UINT64_C(768),	// SHR
    UINT64_C(780),	// SHRI
    UINT64_C(784),	// SHRI_P
    UINT64_C(772),	// SHR_P
    UINT64_C(1073742144),	// SIN_F32
    UINT64_C(1073741952),	// SQRT_F32
    UINT64_C(832),	// SRA
    UINT64_C(844),	// SRAI
    UINT64_C(848),	// SRAI_P
    UINT64_C(836),	// SRA_P
    UINT64_C(114),	// SRD
    UINT64_C(96),	// ST_GLOBAL
    UINT64_C(352),	// ST_GLOBAL_IDX
    UINT64_C(352),	// ST_GLOBAL_IDX_W16
    UINT64_C(352),	// ST_GLOBAL_IDX_W8
    UINT64_C(864),	// ST_GLOBAL_SLOT
    UINT64_C(864),	// ST_GLOBAL_SLOT_W16
    UINT64_C(864),	// ST_GLOBAL_SLOT_W8
    UINT64_C(96),	// ST_GLOBAL_W16
    UINT64_C(96),	// ST_GLOBAL_W8
    UINT64_C(1120),	// ST_LOCAL
    UINT64_C(608),	// ST_PRED_G
    UINT64_C(1248),	// ST_PRED_LOCAL
    UINT64_C(736),	// ST_PRED_S
    UINT64_C(224),	// ST_SHARED
    UINT64_C(480),	// ST_SHARED_IDX
    UINT64_C(224),	// ST_SHARED_W16
    UINT64_C(224),	// ST_SHARED_W8
    UINT64_C(64),	// SUB
    UINT64_C(76),	// SUBI
    UINT64_C(80),	// SUBI_P
    UINT64_C(68),	// SUB_P
    UINT64_C(64),	// SUB_W16
    UINT64_C(1504),	// SZ_GLOBAL_LD_S16
    UINT64_C(1504),	// SZ_GLOBAL_LD_S16_W16
    UINT64_C(1376),	// SZ_GLOBAL_LD_S8
    UINT64_C(1376),	// SZ_GLOBAL_LD_S8_W16
    UINT64_C(1440),	// SZ_GLOBAL_LD_U16
    UINT64_C(1440),	// SZ_GLOBAL_LD_U16_W16
    UINT64_C(1312),	// SZ_GLOBAL_LD_U8
    UINT64_C(1312),	// SZ_GLOBAL_LD_U8_W16
    UINT64_C(1632),	// SZ_GLOBAL_ST_16
    UINT64_C(1632),	// SZ_GLOBAL_ST_16_W16
    UINT64_C(1568),	// SZ_GLOBAL_ST_8
    UINT64_C(1568),	// SZ_GLOBAL_ST_8_W16
    UINT64_C(1888),	// SZ_SHARED_LD_S16
    UINT64_C(1760),	// SZ_SHARED_LD_S8
    UINT64_C(1824),	// SZ_SHARED_LD_U16
    UINT64_C(1696),	// SZ_SHARED_LD_U8
    UINT64_C(2016),	// SZ_SHARED_ST_16
    UINT64_C(1952),	// SZ_SHARED_ST_8
    UINT64_C(624),	// UNBALLOT
    UINT64_C(1420),	// UNPACKI
    UINT64_C(304),	// VOTE_ANY
    UINT64_C(576),	// XOR
    UINT64_C(588),	// XORI
    UINT64_C(592),	// XORI_P
    UINT64_C(580),	// XOR_P
    UINT64_C(576),	// XOR_W16
    UINT64_C(0)
  };
  const unsigned opcode = MI.getOpcode();
  uint64_t Value = InstBits[opcode];
  uint64_t op = 0;
  (void)op;  // suppress warning
  switch (opcode) {
    case CCV::BAR_INIT: {
      // op: barid
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(63);
      op <<= 11;
      Value |= op;
      // op: count
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(1023);
      op <<= 17;
      Value |= op;
      break;
    }
    case CCV::BAR_WAIT_PHASE: {
      // op: barid
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(63);
      op <<= 11;
      Value |= op;
      // op: ps
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 17;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      break;
    }
    case CCV::BRA_PRED: {
      // op: off
      op = getBranch18OpValue(MI, 1, Fixups, STI);
      Value |= (op & UINT64_C(196608)) << 14;
      Value |= (op & UINT64_C(65535)) << 11;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      break;
    }
    case CCV::BRA: {
      // op: off
      op = getBranch21OpValue(MI, 0, Fixups, STI);
      op &= UINT64_C(2097151);
      op <<= 11;
      Value |= op;
      break;
    }
    case CCV::C_BRA: {
      // op: off
      op = getBranch8OpValue(MI, 0, Fixups, STI);
      op &= UINT64_C(255);
      op <<= 8;
      Value |= op;
      break;
    }
    case CCV::C_BAR_ARRIVE:
    case CCV::C_BAR_WAIT:
    case CCV::C_EXIT:
    case CCV::C_FENCE:
    case CCV::C_RECONV:
    case CCV::C_RET: {
      // op: payload
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(255);
      op <<= 8;
      Value |= op;
      break;
    }
    case CCV::PMOV_IMM: {
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 8;
      Value |= op;
      // op: lanemask
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(4294967295);
      op <<= 16;
      Value |= op;
      break;
    }
    case CCV::PAND:
    case CCV::PMOV:
    case CCV::POR:
    case CCV::PXOR: {
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 8;
      Value |= op;
      // op: ps0
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 10;
      Value |= op;
      // op: ps1
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 13;
      Value |= op;
      break;
    }
    case CCV::VOTE_ANY: {
      // op: ps
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 19;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      break;
    }
    case CCV::MOVI: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(131071);
      op <<= 15;
      Value |= op;
      break;
    }
    case CCV::MOVI48: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(8589934591);
      op <<= 15;
      Value |= op;
      break;
    }
    case CCV::CALL: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: off
      op = getCall17OpValue(MI, 1, Fixups, STI);
      op &= UINT64_C(131071);
      op <<= 15;
      Value |= op;
      break;
    }
    case CCV::BALLOT: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: ps
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 19;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      break;
    }
    case CCV::ATOM_ADD_F_G:
    case CCV::ATOM_ADD_F_S:
    case CCV::ATOM_ADD_G:
    case CCV::ATOM_ADD_S:
    case CCV::ATOM_AND_G:
    case CCV::ATOM_AND_S:
    case CCV::ATOM_EXCH_G:
    case CCV::ATOM_EXCH_S:
    case CCV::ATOM_MAX_S_G:
    case CCV::ATOM_MAX_S_S:
    case CCV::ATOM_MAX_U_G:
    case CCV::ATOM_MAX_U_S:
    case CCV::ATOM_MIN_S_G:
    case CCV::ATOM_MIN_S_S:
    case CCV::ATOM_MIN_U_G:
    case CCV::ATOM_MIN_U_S:
    case CCV::ATOM_OR_G:
    case CCV::ATOM_OR_S:
    case CCV::ATOM_XOR_G:
    case CCV::ATOM_XOR_S: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rbase
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(5), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: rindex
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 23;
      Value |= op;
      // op: scale
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(1);
      op <<= 27;
      Value |= op;
      // op: disp
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 28;
      Value |= op;
      break;
    }
    case CCV::CAS_G:
    case CCV::CAS_S: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rbase
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(7), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(8), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 23;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      // op: rindex
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 32;
      Value |= op;
      // op: scale
      op = getMachineOpValue(MI, MI.getOperand(5), Fixups, STI);
      op &= UINT64_C(1);
      op <<= 36;
      Value |= op;
      // op: disp
      op = getMachineOpValue(MI, MI.getOperand(6), Fixups, STI);
      op &= UINT64_C(2047);
      op <<= 37;
      Value |= op;
      break;
    }
    case CCV::ADDI48: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(536870911);
      op <<= 19;
      Value |= op;
      break;
    }
    case CCV::ADDI:
    case CCV::ADDI_W16:
    case CCV::ANDI:
    case CCV::ANDNI:
    case CCV::MULI:
    case CCV::ORI:
    case CCV::PACKI_Z:
    case CCV::SHLI:
    case CCV::SHRI:
    case CCV::SRAI:
    case CCV::SUBI:
    case CCV::UNPACKI:
    case CCV::XORI: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(8191);
      op <<= 19;
      Value |= op;
      break;
    }
    case CCV::ABS:
    case CCV::ADD:
    case CCV::ADD_W16:
    case CCV::AND:
    case CCV::ANDN:
    case CCV::AND_W16:
    case CCV::BREV:
    case CCV::CLZ:
    case CCV::COS_F32:
    case CCV::CVT_D0_S0_R0:
    case CCV::CVT_D0_S0_R0_W4_32:
    case CCV::CVT_D0_S0_R0_W8_32:
    case CCV::CVT_D0_S0_R0_W16_8:
    case CCV::CVT_D0_S0_R0_W16_32:
    case CCV::CVT_D0_S0_R0_W32_4:
    case CCV::CVT_D0_S0_R0_W32_8:
    case CCV::CVT_D0_S0_R0_W32_16:
    case CCV::CVT_D0_S0_R1:
    case CCV::CVT_D0_S0_R2:
    case CCV::CVT_D0_S0_R3:
    case CCV::CVT_D0_S1_R0:
    case CCV::CVT_D0_S1_R0_W16_8:
    case CCV::CVT_D0_S1_R0_W32_8:
    case CCV::CVT_D0_S1_R1:
    case CCV::CVT_D0_S1_R2:
    case CCV::CVT_D0_S1_R3:
    case CCV::CVT_D0_S2_R1:
    case CCV::CVT_D0_S2_R2:
    case CCV::CVT_D0_S2_R3:
    case CCV::CVT_D0_S3_R1:
    case CCV::CVT_D0_S3_R2:
    case CCV::CVT_D0_S3_R3:
    case CCV::CVT_D1_S0_R0:
    case CCV::CVT_D1_S0_R0_W8_32:
    case CCV::CVT_D1_S0_R1:
    case CCV::CVT_D1_S0_R2:
    case CCV::CVT_D1_S0_R3:
    case CCV::CVT_D1_S1_R0:
    case CCV::CVT_D1_S1_R1:
    case CCV::CVT_D1_S1_R2:
    case CCV::CVT_D1_S1_R3:
    case CCV::CVT_D1_S2_R0:
    case CCV::CVT_D1_S2_R1:
    case CCV::CVT_D1_S2_R2:
    case CCV::CVT_D1_S2_R3:
    case CCV::CVT_D1_S3_R0:
    case CCV::CVT_D1_S3_R1:
    case CCV::CVT_D1_S3_R2:
    case CCV::CVT_D1_S3_R3:
    case CCV::CVT_D2_S0_R0:
    case CCV::CVT_D2_S0_R2:
    case CCV::CVT_D2_S0_R3:
    case CCV::CVT_D2_S1_R0:
    case CCV::CVT_D2_S1_R1:
    case CCV::CVT_D2_S1_R2:
    case CCV::CVT_D2_S1_R3:
    case CCV::CVT_D2_S3_R0:
    case CCV::CVT_D3_S0_R0:
    case CCV::CVT_D3_S0_R2:
    case CCV::CVT_D3_S0_R3:
    case CCV::CVT_D3_S1_R0:
    case CCV::CVT_D3_S1_R1:
    case CCV::CVT_D3_S1_R2:
    case CCV::CVT_D3_S1_R3:
    case CCV::CVT_D3_S2_R0:
    case CCV::CVT_D3_S3_R0:
    case CCV::CVT_F32_S32:
    case CCV::CVT_F32_U32:
    case CCV::CVT_S32_F32:
    case CCV::CVT_SEXT:
    case CCV::CVT_U32_F32:
    case CCV::DP2_BF16:
    case CCV::DP2_F16:
    case CCV::DP4_E4M3:
    case CCV::DP4_E5M2:
    case CCV::DP4_SS:
    case CCV::EX2_F32:
    case CCV::FABS_F0:
    case CCV::FABS_F1:
    case CCV::FADD:
    case CCV::FADD_F1:
    case CCV::FADD_F1_W8:
    case CCV::FADD_W8:
    case CCV::FFMA_F0:
    case CCV::FFMA_F1:
    case CCV::FMAX:
    case CCV::FMAX_F1:
    case CCV::FMIN:
    case CCV::FMIN_F1:
    case CCV::FMUL:
    case CCV::FMUL_F1:
    case CCV::FMUL_F1_W8:
    case CCV::FMUL_W8:
    case CCV::FNEG_F0:
    case CCV::FNEG_F1:
    case CCV::FSUB:
    case CCV::FSUB_F1:
    case CCV::FSUB_F1_W8:
    case CCV::FSUB_W8:
    case CCV::LG2_F32:
    case CCV::MADLO:
    case CCV::MAX_S:
    case CCV::MAX_S_W16:
    case CCV::MAX_U:
    case CCV::MIN_S:
    case CCV::MIN_S_W16:
    case CCV::MIN_U:
    case CCV::MUL_HI_S:
    case CCV::MUL_HI_U:
    case CCV::MUL_LO:
    case CCV::NEG:
    case CCV::OR:
    case CCV::OR_W16:
    case CCV::POPC:
    case CCV::RCP_F32:
    case CCV::RCP_U32:
    case CCV::RSQRT_F32:
    case CCV::SHL:
    case CCV::SHR:
    case CCV::SIN_F32:
    case CCV::SQRT_F32:
    case CCV::SRA:
    case CCV::SUB:
    case CCV::SUB_W16:
    case CCV::XOR:
    case CCV::XOR_W16: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 23;
      Value |= op;
      break;
    }
    case CCV::PACKI: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(8191);
      op <<= 19;
      Value |= op;
      break;
    }
    case CCV::SHFL_IDX: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: lane
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(31);
      op <<= 19;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      break;
    }
    case CCV::ADDI_P:
    case CCV::ANDI_P:
    case CCV::ANDNI_P:
    case CCV::MULI_P:
    case CCV::ORI_P:
    case CCV::SHLI_P:
    case CCV::SHRI_P:
    case CCV::SRAI_P:
    case CCV::SUBI_P:
    case CCV::XORI_P: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      Value |= (op & UINT64_C(768)) << 22;
      Value |= (op & UINT64_C(255)) << 19;
      break;
    }
    case CCV::ADD_P:
    case CCV::AND_P:
    case CCV::CVT_D0_S0_R0_P:
    case CCV::CVT_D0_S0_R1_P:
    case CCV::CVT_D0_S0_R2_P:
    case CCV::CVT_D0_S0_R3_P:
    case CCV::CVT_D0_S1_R0_P:
    case CCV::CVT_D0_S1_R1_P:
    case CCV::CVT_D0_S1_R2_P:
    case CCV::CVT_D0_S1_R3_P:
    case CCV::CVT_D0_S2_R1_P:
    case CCV::CVT_D0_S2_R2_P:
    case CCV::CVT_D0_S2_R3_P:
    case CCV::CVT_D0_S3_R1_P:
    case CCV::CVT_D0_S3_R2_P:
    case CCV::CVT_D0_S3_R3_P:
    case CCV::CVT_D1_S0_R0_P:
    case CCV::CVT_D1_S0_R1_P:
    case CCV::CVT_D1_S0_R2_P:
    case CCV::CVT_D1_S0_R3_P:
    case CCV::CVT_D1_S1_R0_P:
    case CCV::CVT_D1_S1_R1_P:
    case CCV::CVT_D1_S1_R2_P:
    case CCV::CVT_D1_S1_R3_P:
    case CCV::CVT_D1_S2_R0_P:
    case CCV::CVT_D1_S2_R1_P:
    case CCV::CVT_D1_S2_R2_P:
    case CCV::CVT_D1_S2_R3_P:
    case CCV::CVT_D1_S3_R0_P:
    case CCV::CVT_D1_S3_R1_P:
    case CCV::CVT_D1_S3_R2_P:
    case CCV::CVT_D1_S3_R3_P:
    case CCV::CVT_D2_S0_R0_P:
    case CCV::CVT_D2_S0_R2_P:
    case CCV::CVT_D2_S0_R3_P:
    case CCV::CVT_D2_S1_R0_P:
    case CCV::CVT_D2_S1_R1_P:
    case CCV::CVT_D2_S1_R2_P:
    case CCV::CVT_D2_S1_R3_P:
    case CCV::CVT_D2_S3_R0_P:
    case CCV::CVT_D3_S0_R0_P:
    case CCV::CVT_D3_S0_R2_P:
    case CCV::CVT_D3_S0_R3_P:
    case CCV::CVT_D3_S1_R0_P:
    case CCV::CVT_D3_S1_R1_P:
    case CCV::CVT_D3_S1_R2_P:
    case CCV::CVT_D3_S1_R3_P:
    case CCV::CVT_D3_S2_R0_P:
    case CCV::CVT_D3_S3_R0_P:
    case CCV::CVT_F32_S32_P:
    case CCV::CVT_F32_U32_P:
    case CCV::CVT_S32_F32_P:
    case CCV::CVT_U32_F32_P:
    case CCV::FADD_P:
    case CCV::FMUL_P:
    case CCV::FSUB_P:
    case CCV::MADLO_P:
    case CCV::MAX_S_P:
    case CCV::MAX_U_P:
    case CCV::MIN_S_P:
    case CCV::MIN_U_P:
    case CCV::MUL_HI_S_P:
    case CCV::MUL_HI_U_P:
    case CCV::OR_P:
    case CCV::RCP_F32_P:
    case CCV::SEL:
    case CCV::SHL_P:
    case CCV::SHR_P:
    case CCV::SRA_P:
    case CCV::SUB_P:
    case CCV::XOR_P: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 23;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      break;
    }
    case CCV::ADDI_PP: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(255);
      op <<= 19;
      Value |= op;
      break;
    }
    case CCV::MOV_P: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(5), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 23;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      break;
    }
    case CCV::ADD_PP: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: rs2
      op = getMachineOpValue(MI, MI.getOperand(5), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 23;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      break;
    }
    case CCV::DP4_ACC:
    case CCV::FFMA_ACC_F0:
    case CCV::FFMA_ACC_F1:
    case CCV::MAD_ACC: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 4;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 8;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 12;
      Value |= op;
      break;
    }
    case CCV::C_ADDI:
    case CCV::C_ANDI:
    case CCV::C_ORI:
    case CCV::C_SHLI:
    case CCV::C_SHRI:
    case CCV::C_SRAI:
    case CCV::C_SUBI:
    case CCV::C_XORI: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 8;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 12;
      Value |= op;
      break;
    }
    case CCV::C_LD_GLOBAL:
    case CCV::C_ST_GLOBAL: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 8;
      Value |= op;
      // op: rbase
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 12;
      Value |= op;
      break;
    }
    case CCV::C_ABS:
    case CCV::C_MOV:
    case CCV::C_NEG:
    case CCV::C_NOT: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 8;
      Value |= op;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 12;
      Value |= op;
      break;
    }
    case CCV::C_ADD:
    case CCV::C_AND:
    case CCV::C_ANDN:
    case CCV::C_FADD:
    case CCV::C_FMAX:
    case CCV::C_FMIN:
    case CCV::C_FMUL:
    case CCV::C_MAX_S:
    case CCV::C_MAX_U:
    case CCV::C_MIN_S:
    case CCV::C_MIN_U:
    case CCV::C_MUL_LO:
    case CCV::C_OR:
    case CCV::C_SHL:
    case CCV::C_SHR:
    case CCV::C_SRA:
    case CCV::C_SUB:
    case CCV::C_XOR: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 8;
      Value |= op;
      // op: rs
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 12;
      Value |= op;
      break;
    }
    case CCV::SRD: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 8;
      Value |= op;
      // op: sel
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 12;
      Value |= op;
      break;
    }
    case CCV::C_CHWIDTH: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 8;
      Value |= op;
      // op: width
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 12;
      Value |= op;
      break;
    }
    case CCV::SETP_EQ_F_NPI:
    case CCV::SETP_EQ_NPI:
    case CCV::SETP_GE_F_NPI:
    case CCV::SETP_GE_NPI:
    case CCV::SETP_GE_U_NPI:
    case CCV::SETP_GT_F_NPI:
    case CCV::SETP_GT_NPI:
    case CCV::SETP_GT_U_NPI:
    case CCV::SETP_LE_F_NPI:
    case CCV::SETP_LE_NPI:
    case CCV::SETP_LE_U_NPI:
    case CCV::SETP_LT_F_NPI:
    case CCV::SETP_LT_NPI:
    case CCV::SETP_LT_U_NPI:
    case CCV::SETP_NE_F_NPI:
    case CCV::SETP_NE_NPI: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(255);
      op <<= 19;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      break;
    }
    case CCV::SETP_EQ_F1_NP:
    case CCV::SETP_EQ_F_NP:
    case CCV::SETP_EQ_NP:
    case CCV::SETP_GE_F1_NP:
    case CCV::SETP_GE_F_NP:
    case CCV::SETP_GE_NP:
    case CCV::SETP_GE_U_NP:
    case CCV::SETP_GT_F1_NP:
    case CCV::SETP_GT_F_NP:
    case CCV::SETP_GT_NP:
    case CCV::SETP_GT_U_NP:
    case CCV::SETP_LE_F1_NP:
    case CCV::SETP_LE_F_NP:
    case CCV::SETP_LE_NP:
    case CCV::SETP_LE_U_NP:
    case CCV::SETP_LT_F1_NP:
    case CCV::SETP_LT_F_NP:
    case CCV::SETP_LT_NP:
    case CCV::SETP_LT_U_NP:
    case CCV::SETP_NE_F1_NP:
    case CCV::SETP_NE_F_NP:
    case CCV::SETP_NE_NP: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      break;
    }
    case CCV::SETP_EQ_F_I:
    case CCV::SETP_EQ_I:
    case CCV::SETP_GE_F_I:
    case CCV::SETP_GE_I:
    case CCV::SETP_GE_U_I:
    case CCV::SETP_GT_F_I:
    case CCV::SETP_GT_I:
    case CCV::SETP_GT_U_I:
    case CCV::SETP_LE_F_I:
    case CCV::SETP_LE_I:
    case CCV::SETP_LE_U_I:
    case CCV::SETP_LT_F_I:
    case CCV::SETP_LT_I:
    case CCV::SETP_LT_U_I:
    case CCV::SETP_NE_F_I:
    case CCV::SETP_NE_I: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(255);
      op <<= 19;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      break;
    }
    case CCV::SETP_EQ:
    case CCV::SETP_EQ_F:
    case CCV::SETP_EQ_F1:
    case CCV::SETP_GE:
    case CCV::SETP_GE_F:
    case CCV::SETP_GE_F1:
    case CCV::SETP_GE_U:
    case CCV::SETP_GT:
    case CCV::SETP_GT_F:
    case CCV::SETP_GT_F1:
    case CCV::SETP_GT_U:
    case CCV::SETP_LE:
    case CCV::SETP_LE_F:
    case CCV::SETP_LE_F1:
    case CCV::SETP_LE_U:
    case CCV::SETP_LT:
    case CCV::SETP_LT_F:
    case CCV::SETP_LT_F1:
    case CCV::SETP_LT_U:
    case CCV::SETP_NE:
    case CCV::SETP_NE_F:
    case CCV::SETP_NE_F1: {
      // op: rd
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rs1
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      break;
    }
    case CCV::LD_LOCAL:
    case CCV::LD_PRED_LOCAL:
    case CCV::ST_LOCAL:
    case CCV::ST_PRED_LOCAL: {
      // op: rdata
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: off
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(131071);
      op <<= 15;
      Value |= op;
      break;
    }
    case CCV::LD_GLOBAL:
    case CCV::LD_GLOBAL_W8:
    case CCV::LD_GLOBAL_W16:
    case CCV::LD_PRED_G:
    case CCV::LD_PRED_S:
    case CCV::LD_SHARED:
    case CCV::LD_SHARED_W8:
    case CCV::LD_SHARED_W16:
    case CCV::ST_GLOBAL:
    case CCV::ST_GLOBAL_W8:
    case CCV::ST_GLOBAL_W16:
    case CCV::ST_PRED_G:
    case CCV::ST_PRED_S:
    case CCV::ST_SHARED:
    case CCV::ST_SHARED_W8:
    case CCV::ST_SHARED_W16: {
      // op: rdata
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rbase
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: off
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(8191);
      op <<= 19;
      Value |= op;
      break;
    }
    case CCV::LD_GLOBAL_IDX:
    case CCV::LD_GLOBAL_IDX_W8:
    case CCV::LD_GLOBAL_IDX_W16:
    case CCV::LD_SHARED_IDX:
    case CCV::ST_GLOBAL_IDX:
    case CCV::ST_GLOBAL_IDX_W8:
    case CCV::ST_GLOBAL_IDX_W16:
    case CCV::ST_SHARED_IDX:
    case CCV::SZ_GLOBAL_LD_S8:
    case CCV::SZ_GLOBAL_LD_S8_W16:
    case CCV::SZ_GLOBAL_LD_S16:
    case CCV::SZ_GLOBAL_LD_S16_W16:
    case CCV::SZ_GLOBAL_LD_U8:
    case CCV::SZ_GLOBAL_LD_U8_W16:
    case CCV::SZ_GLOBAL_LD_U16:
    case CCV::SZ_GLOBAL_LD_U16_W16:
    case CCV::SZ_GLOBAL_ST_8:
    case CCV::SZ_GLOBAL_ST_8_W16:
    case CCV::SZ_GLOBAL_ST_16:
    case CCV::SZ_GLOBAL_ST_16_W16:
    case CCV::SZ_SHARED_LD_S8:
    case CCV::SZ_SHARED_LD_S16:
    case CCV::SZ_SHARED_LD_U8:
    case CCV::SZ_SHARED_LD_U16:
    case CCV::SZ_SHARED_ST_8:
    case CCV::SZ_SHARED_ST_16: {
      // op: rdata
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rbase
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rindex
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: scale
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(1);
      op <<= 23;
      Value |= op;
      // op: disp
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(255);
      op <<= 24;
      Value |= op;
      break;
    }
    case CCV::LD_GLOBAL_P: {
      // op: rdata
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: rbase
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: off
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      Value |= (op & UINT64_C(768)) << 22;
      Value |= (op & UINT64_C(255)) << 19;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      break;
    }
    case CCV::LD_GLOBAL_SLOT:
    case CCV::LD_GLOBAL_SLOT_W8:
    case CCV::LD_GLOBAL_SLOT_W16:
    case CCV::ST_GLOBAL_SLOT:
    case CCV::ST_GLOBAL_SLOT_W8:
    case CCV::ST_GLOBAL_SLOT_W16: {
      // op: rdata
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 11;
      Value |= op;
      // op: slot
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: rindex
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 19;
      Value |= op;
      // op: scale
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      op &= UINT64_C(1);
      op <<= 23;
      Value |= op;
      // op: disp
      op = getMachineOpValue(MI, MI.getOperand(4), Fixups, STI);
      op &= UINT64_C(255);
      op <<= 24;
      Value |= op;
      break;
    }
    case CCV::CHWIDTH_MULTI: {
      // op: regmask
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(65535);
      op <<= 8;
      Value |= op;
      // op: width
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 24;
      Value |= op;
      break;
    }
    case CCV::UNBALLOT: {
      // op: rs0
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      op &= UINT64_C(15);
      op <<= 15;
      Value |= op;
      // op: pq
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      op &= UINT64_C(7);
      op <<= 27;
      Value |= op;
      // op: pd
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      op &= UINT64_C(3);
      op <<= 30;
      Value |= op;
      break;
    }
  default:
    std::string msg;
    raw_string_ostream Msg(msg);
    Msg << "Not supported instr: " << MI;
    report_fatal_error(Msg.str().c_str());
  }
  return Value;
}

#ifdef GET_OPERAND_BIT_OFFSET
#undef GET_OPERAND_BIT_OFFSET

uint32_t CCVMCCodeEmitter::getOperandBitOffset(const MCInst &MI,
    unsigned OpNum,
    const MCSubtargetInfo &STI) const {
  switch (MI.getOpcode()) {
    case CCV::BAR_INIT: {
      switch (OpNum) {
      case 0:
        // op: barid
        return 11;
      case 1:
        // op: count
        return 17;
      }
      break;
    }
    case CCV::BRA: {
      switch (OpNum) {
      case 0:
        // op: off
        return 11;
      }
      break;
    }
    case CCV::C_BRA: {
      switch (OpNum) {
      case 0:
        // op: off
        return 8;
      }
      break;
    }
    case CCV::C_BAR_ARRIVE:
    case CCV::C_BAR_WAIT:
    case CCV::C_EXIT:
    case CCV::C_FENCE:
    case CCV::C_RECONV:
    case CCV::C_RET: {
      switch (OpNum) {
      case 0:
        // op: payload
        return 8;
      }
      break;
    }
    case CCV::PMOV_IMM: {
      switch (OpNum) {
      case 0:
        // op: pd
        return 8;
      case 1:
        // op: lanemask
        return 16;
      }
      break;
    }
    case CCV::PAND:
    case CCV::PMOV:
    case CCV::POR:
    case CCV::PXOR: {
      switch (OpNum) {
      case 0:
        // op: pd
        return 8;
      case 1:
        // op: ps0
        return 10;
      case 2:
        // op: ps1
        return 13;
      }
      break;
    }
    case CCV::MOVI:
    case CCV::MOVI48: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 1:
        // op: imm
        return 15;
      }
      break;
    }
    case CCV::CALL: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 1:
        // op: off
        return 15;
      }
      break;
    }
    case CCV::ATOM_ADD_F_G:
    case CCV::ATOM_ADD_F_S:
    case CCV::ATOM_ADD_G:
    case CCV::ATOM_ADD_S:
    case CCV::ATOM_AND_G:
    case CCV::ATOM_AND_S:
    case CCV::ATOM_EXCH_G:
    case CCV::ATOM_EXCH_S:
    case CCV::ATOM_MAX_S_G:
    case CCV::ATOM_MAX_S_S:
    case CCV::ATOM_MAX_U_G:
    case CCV::ATOM_MAX_U_S:
    case CCV::ATOM_MIN_S_G:
    case CCV::ATOM_MIN_S_S:
    case CCV::ATOM_MIN_U_G:
    case CCV::ATOM_MIN_U_S:
    case CCV::ATOM_OR_G:
    case CCV::ATOM_OR_S:
    case CCV::ATOM_XOR_G:
    case CCV::ATOM_XOR_S: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 1:
        // op: rbase
        return 15;
      case 5:
        // op: rs1
        return 19;
      case 2:
        // op: rindex
        return 23;
      case 3:
        // op: scale
        return 27;
      case 4:
        // op: disp
        return 28;
      }
      break;
    }
    case CCV::ADDI:
    case CCV::ADDI48:
    case CCV::ADDI_W16:
    case CCV::ANDI:
    case CCV::ANDNI:
    case CCV::MULI:
    case CCV::ORI:
    case CCV::PACKI_Z:
    case CCV::SHLI:
    case CCV::SHRI:
    case CCV::SRAI:
    case CCV::SUBI:
    case CCV::UNPACKI:
    case CCV::XORI: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 1:
        // op: rs0
        return 15;
      case 2:
        // op: imm
        return 19;
      }
      break;
    }
    case CCV::ABS:
    case CCV::ADD:
    case CCV::ADD_W16:
    case CCV::AND:
    case CCV::ANDN:
    case CCV::AND_W16:
    case CCV::BREV:
    case CCV::CLZ:
    case CCV::COS_F32:
    case CCV::CVT_D0_S0_R0:
    case CCV::CVT_D0_S0_R0_W4_32:
    case CCV::CVT_D0_S0_R0_W8_32:
    case CCV::CVT_D0_S0_R0_W16_8:
    case CCV::CVT_D0_S0_R0_W16_32:
    case CCV::CVT_D0_S0_R0_W32_4:
    case CCV::CVT_D0_S0_R0_W32_8:
    case CCV::CVT_D0_S0_R0_W32_16:
    case CCV::CVT_D0_S0_R1:
    case CCV::CVT_D0_S0_R2:
    case CCV::CVT_D0_S0_R3:
    case CCV::CVT_D0_S1_R0:
    case CCV::CVT_D0_S1_R0_W16_8:
    case CCV::CVT_D0_S1_R0_W32_8:
    case CCV::CVT_D0_S1_R1:
    case CCV::CVT_D0_S1_R2:
    case CCV::CVT_D0_S1_R3:
    case CCV::CVT_D0_S2_R1:
    case CCV::CVT_D0_S2_R2:
    case CCV::CVT_D0_S2_R3:
    case CCV::CVT_D0_S3_R1:
    case CCV::CVT_D0_S3_R2:
    case CCV::CVT_D0_S3_R3:
    case CCV::CVT_D1_S0_R0:
    case CCV::CVT_D1_S0_R0_W8_32:
    case CCV::CVT_D1_S0_R1:
    case CCV::CVT_D1_S0_R2:
    case CCV::CVT_D1_S0_R3:
    case CCV::CVT_D1_S1_R0:
    case CCV::CVT_D1_S1_R1:
    case CCV::CVT_D1_S1_R2:
    case CCV::CVT_D1_S1_R3:
    case CCV::CVT_D1_S2_R0:
    case CCV::CVT_D1_S2_R1:
    case CCV::CVT_D1_S2_R2:
    case CCV::CVT_D1_S2_R3:
    case CCV::CVT_D1_S3_R0:
    case CCV::CVT_D1_S3_R1:
    case CCV::CVT_D1_S3_R2:
    case CCV::CVT_D1_S3_R3:
    case CCV::CVT_D2_S0_R0:
    case CCV::CVT_D2_S0_R2:
    case CCV::CVT_D2_S0_R3:
    case CCV::CVT_D2_S1_R0:
    case CCV::CVT_D2_S1_R1:
    case CCV::CVT_D2_S1_R2:
    case CCV::CVT_D2_S1_R3:
    case CCV::CVT_D2_S3_R0:
    case CCV::CVT_D3_S0_R0:
    case CCV::CVT_D3_S0_R2:
    case CCV::CVT_D3_S0_R3:
    case CCV::CVT_D3_S1_R0:
    case CCV::CVT_D3_S1_R1:
    case CCV::CVT_D3_S1_R2:
    case CCV::CVT_D3_S1_R3:
    case CCV::CVT_D3_S2_R0:
    case CCV::CVT_D3_S3_R0:
    case CCV::CVT_F32_S32:
    case CCV::CVT_F32_U32:
    case CCV::CVT_S32_F32:
    case CCV::CVT_SEXT:
    case CCV::CVT_U32_F32:
    case CCV::DP2_BF16:
    case CCV::DP2_F16:
    case CCV::DP4_E4M3:
    case CCV::DP4_E5M2:
    case CCV::DP4_SS:
    case CCV::EX2_F32:
    case CCV::FABS_F0:
    case CCV::FABS_F1:
    case CCV::FADD:
    case CCV::FADD_F1:
    case CCV::FADD_F1_W8:
    case CCV::FADD_W8:
    case CCV::FFMA_F0:
    case CCV::FFMA_F1:
    case CCV::FMAX:
    case CCV::FMAX_F1:
    case CCV::FMIN:
    case CCV::FMIN_F1:
    case CCV::FMUL:
    case CCV::FMUL_F1:
    case CCV::FMUL_F1_W8:
    case CCV::FMUL_W8:
    case CCV::FNEG_F0:
    case CCV::FNEG_F1:
    case CCV::FSUB:
    case CCV::FSUB_F1:
    case CCV::FSUB_F1_W8:
    case CCV::FSUB_W8:
    case CCV::LG2_F32:
    case CCV::MADLO:
    case CCV::MAX_S:
    case CCV::MAX_S_W16:
    case CCV::MAX_U:
    case CCV::MIN_S:
    case CCV::MIN_S_W16:
    case CCV::MIN_U:
    case CCV::MUL_HI_S:
    case CCV::MUL_HI_U:
    case CCV::MUL_LO:
    case CCV::NEG:
    case CCV::OR:
    case CCV::OR_W16:
    case CCV::POPC:
    case CCV::RCP_F32:
    case CCV::RCP_U32:
    case CCV::RSQRT_F32:
    case CCV::SHL:
    case CCV::SHR:
    case CCV::SIN_F32:
    case CCV::SQRT_F32:
    case CCV::SRA:
    case CCV::SUB:
    case CCV::SUB_W16:
    case CCV::XOR:
    case CCV::XOR_W16: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 1:
        // op: rs0
        return 15;
      case 2:
        // op: rs1
        return 19;
      case 3:
        // op: rs2
        return 23;
      }
      break;
    }
    case CCV::BALLOT: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 2:
        // op: ps
        return 19;
      case 1:
        // op: pq
        return 27;
      }
      break;
    }
    case CCV::ADDI_P:
    case CCV::ANDI_P:
    case CCV::ANDNI_P:
    case CCV::MULI_P:
    case CCV::ORI_P:
    case CCV::SHLI_P:
    case CCV::SHRI_P:
    case CCV::SRAI_P:
    case CCV::SUBI_P:
    case CCV::XORI_P: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 2:
        // op: rs0
        return 15;
      case 1:
        // op: pq
        return 27;
      case 3:
        // op: imm
        return 19;
      }
      break;
    }
    case CCV::PACKI: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 2:
        // op: rs0
        return 15;
      case 3:
        // op: imm
        return 19;
      }
      break;
    }
    case CCV::SHFL_IDX: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 2:
        // op: rs0
        return 15;
      case 3:
        // op: lane
        return 19;
      case 1:
        // op: pq
        return 27;
      }
      break;
    }
    case CCV::ADD_P:
    case CCV::AND_P:
    case CCV::CVT_D0_S0_R0_P:
    case CCV::CVT_D0_S0_R1_P:
    case CCV::CVT_D0_S0_R2_P:
    case CCV::CVT_D0_S0_R3_P:
    case CCV::CVT_D0_S1_R0_P:
    case CCV::CVT_D0_S1_R1_P:
    case CCV::CVT_D0_S1_R2_P:
    case CCV::CVT_D0_S1_R3_P:
    case CCV::CVT_D0_S2_R1_P:
    case CCV::CVT_D0_S2_R2_P:
    case CCV::CVT_D0_S2_R3_P:
    case CCV::CVT_D0_S3_R1_P:
    case CCV::CVT_D0_S3_R2_P:
    case CCV::CVT_D0_S3_R3_P:
    case CCV::CVT_D1_S0_R0_P:
    case CCV::CVT_D1_S0_R1_P:
    case CCV::CVT_D1_S0_R2_P:
    case CCV::CVT_D1_S0_R3_P:
    case CCV::CVT_D1_S1_R0_P:
    case CCV::CVT_D1_S1_R1_P:
    case CCV::CVT_D1_S1_R2_P:
    case CCV::CVT_D1_S1_R3_P:
    case CCV::CVT_D1_S2_R0_P:
    case CCV::CVT_D1_S2_R1_P:
    case CCV::CVT_D1_S2_R2_P:
    case CCV::CVT_D1_S2_R3_P:
    case CCV::CVT_D1_S3_R0_P:
    case CCV::CVT_D1_S3_R1_P:
    case CCV::CVT_D1_S3_R2_P:
    case CCV::CVT_D1_S3_R3_P:
    case CCV::CVT_D2_S0_R0_P:
    case CCV::CVT_D2_S0_R2_P:
    case CCV::CVT_D2_S0_R3_P:
    case CCV::CVT_D2_S1_R0_P:
    case CCV::CVT_D2_S1_R1_P:
    case CCV::CVT_D2_S1_R2_P:
    case CCV::CVT_D2_S1_R3_P:
    case CCV::CVT_D2_S3_R0_P:
    case CCV::CVT_D3_S0_R0_P:
    case CCV::CVT_D3_S0_R2_P:
    case CCV::CVT_D3_S0_R3_P:
    case CCV::CVT_D3_S1_R0_P:
    case CCV::CVT_D3_S1_R1_P:
    case CCV::CVT_D3_S1_R2_P:
    case CCV::CVT_D3_S1_R3_P:
    case CCV::CVT_D3_S2_R0_P:
    case CCV::CVT_D3_S3_R0_P:
    case CCV::CVT_F32_S32_P:
    case CCV::CVT_F32_U32_P:
    case CCV::CVT_S32_F32_P:
    case CCV::CVT_U32_F32_P:
    case CCV::FADD_P:
    case CCV::FMUL_P:
    case CCV::FSUB_P:
    case CCV::MADLO_P:
    case CCV::MAX_S_P:
    case CCV::MAX_U_P:
    case CCV::MIN_S_P:
    case CCV::MIN_U_P:
    case CCV::MUL_HI_S_P:
    case CCV::MUL_HI_U_P:
    case CCV::OR_P:
    case CCV::RCP_F32_P:
    case CCV::SEL:
    case CCV::SHL_P:
    case CCV::SHR_P:
    case CCV::SRA_P:
    case CCV::SUB_P:
    case CCV::XOR_P: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 2:
        // op: rs0
        return 15;
      case 3:
        // op: rs1
        return 19;
      case 4:
        // op: rs2
        return 23;
      case 1:
        // op: pq
        return 27;
      }
      break;
    }
    case CCV::CAS_G:
    case CCV::CAS_S: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 3:
        // op: rbase
        return 15;
      case 7:
        // op: rs1
        return 19;
      case 8:
        // op: rs2
        return 23;
      case 2:
        // op: pq
        return 27;
      case 1:
        // op: pd
        return 30;
      case 4:
        // op: rindex
        return 32;
      case 5:
        // op: scale
        return 36;
      case 6:
        // op: disp
        return 37;
      }
      break;
    }
    case CCV::ADDI_PP: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 3:
        // op: rs0
        return 15;
      case 2:
        // op: pq
        return 27;
      case 1:
        // op: pd
        return 30;
      case 4:
        // op: imm
        return 19;
      }
      break;
    }
    case CCV::ADD_PP: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 3:
        // op: rs0
        return 15;
      case 4:
        // op: rs1
        return 19;
      case 5:
        // op: rs2
        return 23;
      case 2:
        // op: pq
        return 27;
      case 1:
        // op: pd
        return 30;
      }
      break;
    }
    case CCV::MOV_P: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 11;
      case 3:
        // op: rs0
        return 15;
      case 4:
        // op: rs1
        return 19;
      case 5:
        // op: rs2
        return 23;
      case 2:
        // op: pq
        return 27;
      }
      break;
    }
    case CCV::DP4_ACC:
    case CCV::FFMA_ACC_F0:
    case CCV::FFMA_ACC_F1:
    case CCV::MAD_ACC: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 4;
      case 2:
        // op: rs0
        return 8;
      case 3:
        // op: rs1
        return 12;
      }
      break;
    }
    case CCV::C_LD_GLOBAL:
    case CCV::C_ST_GLOBAL: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 8;
      case 1:
        // op: rbase
        return 12;
      }
      break;
    }
    case CCV::C_ABS:
    case CCV::C_MOV:
    case CCV::C_NEG:
    case CCV::C_NOT: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 8;
      case 1:
        // op: rs
        return 12;
      }
      break;
    }
    case CCV::SRD: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 8;
      case 1:
        // op: sel
        return 12;
      }
      break;
    }
    case CCV::C_CHWIDTH: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 8;
      case 1:
        // op: width
        return 12;
      }
      break;
    }
    case CCV::C_ADDI:
    case CCV::C_ANDI:
    case CCV::C_ORI:
    case CCV::C_SHLI:
    case CCV::C_SHRI:
    case CCV::C_SRAI:
    case CCV::C_SUBI:
    case CCV::C_XORI: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 8;
      case 2:
        // op: imm
        return 12;
      }
      break;
    }
    case CCV::C_ADD:
    case CCV::C_AND:
    case CCV::C_ANDN:
    case CCV::C_FADD:
    case CCV::C_FMAX:
    case CCV::C_FMIN:
    case CCV::C_FMUL:
    case CCV::C_MAX_S:
    case CCV::C_MAX_U:
    case CCV::C_MIN_S:
    case CCV::C_MIN_U:
    case CCV::C_MUL_LO:
    case CCV::C_OR:
    case CCV::C_SHL:
    case CCV::C_SHR:
    case CCV::C_SRA:
    case CCV::C_SUB:
    case CCV::C_XOR: {
      switch (OpNum) {
      case 0:
        // op: rd
        return 8;
      case 2:
        // op: rs
        return 12;
      }
      break;
    }
    case CCV::LD_LOCAL:
    case CCV::LD_PRED_LOCAL:
    case CCV::ST_LOCAL:
    case CCV::ST_PRED_LOCAL: {
      switch (OpNum) {
      case 0:
        // op: rdata
        return 11;
      case 1:
        // op: off
        return 15;
      }
      break;
    }
    case CCV::LD_GLOBAL:
    case CCV::LD_GLOBAL_W8:
    case CCV::LD_GLOBAL_W16:
    case CCV::LD_PRED_G:
    case CCV::LD_PRED_S:
    case CCV::LD_SHARED:
    case CCV::LD_SHARED_W8:
    case CCV::LD_SHARED_W16:
    case CCV::ST_GLOBAL:
    case CCV::ST_GLOBAL_W8:
    case CCV::ST_GLOBAL_W16:
    case CCV::ST_PRED_G:
    case CCV::ST_PRED_S:
    case CCV::ST_SHARED:
    case CCV::ST_SHARED_W8:
    case CCV::ST_SHARED_W16: {
      switch (OpNum) {
      case 0:
        // op: rdata
        return 11;
      case 1:
        // op: rbase
        return 15;
      case 2:
        // op: off
        return 19;
      }
      break;
    }
    case CCV::LD_GLOBAL_IDX:
    case CCV::LD_GLOBAL_IDX_W8:
    case CCV::LD_GLOBAL_IDX_W16:
    case CCV::LD_SHARED_IDX:
    case CCV::ST_GLOBAL_IDX:
    case CCV::ST_GLOBAL_IDX_W8:
    case CCV::ST_GLOBAL_IDX_W16:
    case CCV::ST_SHARED_IDX:
    case CCV::SZ_GLOBAL_LD_S8:
    case CCV::SZ_GLOBAL_LD_S8_W16:
    case CCV::SZ_GLOBAL_LD_S16:
    case CCV::SZ_GLOBAL_LD_S16_W16:
    case CCV::SZ_GLOBAL_LD_U8:
    case CCV::SZ_GLOBAL_LD_U8_W16:
    case CCV::SZ_GLOBAL_LD_U16:
    case CCV::SZ_GLOBAL_LD_U16_W16:
    case CCV::SZ_GLOBAL_ST_8:
    case CCV::SZ_GLOBAL_ST_8_W16:
    case CCV::SZ_GLOBAL_ST_16:
    case CCV::SZ_GLOBAL_ST_16_W16:
    case CCV::SZ_SHARED_LD_S8:
    case CCV::SZ_SHARED_LD_S16:
    case CCV::SZ_SHARED_LD_U8:
    case CCV::SZ_SHARED_LD_U16:
    case CCV::SZ_SHARED_ST_8:
    case CCV::SZ_SHARED_ST_16: {
      switch (OpNum) {
      case 0:
        // op: rdata
        return 11;
      case 1:
        // op: rbase
        return 15;
      case 2:
        // op: rindex
        return 19;
      case 3:
        // op: scale
        return 23;
      case 4:
        // op: disp
        return 24;
      }
      break;
    }
    case CCV::LD_GLOBAL_SLOT:
    case CCV::LD_GLOBAL_SLOT_W8:
    case CCV::LD_GLOBAL_SLOT_W16:
    case CCV::ST_GLOBAL_SLOT:
    case CCV::ST_GLOBAL_SLOT_W8:
    case CCV::ST_GLOBAL_SLOT_W16: {
      switch (OpNum) {
      case 0:
        // op: rdata
        return 11;
      case 1:
        // op: slot
        return 15;
      case 2:
        // op: rindex
        return 19;
      case 3:
        // op: scale
        return 23;
      case 4:
        // op: disp
        return 24;
      }
      break;
    }
    case CCV::LD_GLOBAL_P: {
      switch (OpNum) {
      case 0:
        // op: rdata
        return 11;
      case 2:
        // op: rbase
        return 15;
      case 3:
        // op: off
        return 19;
      case 1:
        // op: pq
        return 27;
      }
      break;
    }
    case CCV::CHWIDTH_MULTI: {
      switch (OpNum) {
      case 0:
        // op: regmask
        return 8;
      case 1:
        // op: width
        return 24;
      }
      break;
    }
    case CCV::BAR_WAIT_PHASE: {
      switch (OpNum) {
      case 1:
        // op: barid
        return 11;
      case 2:
        // op: ps
        return 17;
      case 0:
        // op: pq
        return 27;
      }
      break;
    }
    case CCV::BRA_PRED: {
      switch (OpNum) {
      case 1:
        // op: off
        return 11;
      case 0:
        // op: pq
        return 27;
      }
      break;
    }
    case CCV::SETP_EQ_F_NPI:
    case CCV::SETP_EQ_NPI:
    case CCV::SETP_GE_F_NPI:
    case CCV::SETP_GE_NPI:
    case CCV::SETP_GE_U_NPI:
    case CCV::SETP_GT_F_NPI:
    case CCV::SETP_GT_NPI:
    case CCV::SETP_GT_U_NPI:
    case CCV::SETP_LE_F_NPI:
    case CCV::SETP_LE_NPI:
    case CCV::SETP_LE_U_NPI:
    case CCV::SETP_LT_F_NPI:
    case CCV::SETP_LT_NPI:
    case CCV::SETP_LT_U_NPI:
    case CCV::SETP_NE_F_NPI:
    case CCV::SETP_NE_NPI: {
      switch (OpNum) {
      case 1:
        // op: rd
        return 11;
      case 2:
        // op: rs0
        return 15;
      case 3:
        // op: imm
        return 19;
      case 0:
        // op: pd
        return 30;
      }
      break;
    }
    case CCV::SETP_EQ_F1_NP:
    case CCV::SETP_EQ_F_NP:
    case CCV::SETP_EQ_NP:
    case CCV::SETP_GE_F1_NP:
    case CCV::SETP_GE_F_NP:
    case CCV::SETP_GE_NP:
    case CCV::SETP_GE_U_NP:
    case CCV::SETP_GT_F1_NP:
    case CCV::SETP_GT_F_NP:
    case CCV::SETP_GT_NP:
    case CCV::SETP_GT_U_NP:
    case CCV::SETP_LE_F1_NP:
    case CCV::SETP_LE_F_NP:
    case CCV::SETP_LE_NP:
    case CCV::SETP_LE_U_NP:
    case CCV::SETP_LT_F1_NP:
    case CCV::SETP_LT_F_NP:
    case CCV::SETP_LT_NP:
    case CCV::SETP_LT_U_NP:
    case CCV::SETP_NE_F1_NP:
    case CCV::SETP_NE_F_NP:
    case CCV::SETP_NE_NP: {
      switch (OpNum) {
      case 1:
        // op: rd
        return 11;
      case 2:
        // op: rs0
        return 15;
      case 3:
        // op: rs1
        return 19;
      case 0:
        // op: pd
        return 30;
      }
      break;
    }
    case CCV::SETP_EQ_F_I:
    case CCV::SETP_EQ_I:
    case CCV::SETP_GE_F_I:
    case CCV::SETP_GE_I:
    case CCV::SETP_GE_U_I:
    case CCV::SETP_GT_F_I:
    case CCV::SETP_GT_I:
    case CCV::SETP_GT_U_I:
    case CCV::SETP_LE_F_I:
    case CCV::SETP_LE_I:
    case CCV::SETP_LE_U_I:
    case CCV::SETP_LT_F_I:
    case CCV::SETP_LT_I:
    case CCV::SETP_LT_U_I:
    case CCV::SETP_NE_F_I:
    case CCV::SETP_NE_I: {
      switch (OpNum) {
      case 1:
        // op: rd
        return 11;
      case 3:
        // op: rs0
        return 15;
      case 4:
        // op: imm
        return 19;
      case 2:
        // op: pq
        return 27;
      case 0:
        // op: pd
        return 30;
      }
      break;
    }
    case CCV::SETP_EQ:
    case CCV::SETP_EQ_F:
    case CCV::SETP_EQ_F1:
    case CCV::SETP_GE:
    case CCV::SETP_GE_F:
    case CCV::SETP_GE_F1:
    case CCV::SETP_GE_U:
    case CCV::SETP_GT:
    case CCV::SETP_GT_F:
    case CCV::SETP_GT_F1:
    case CCV::SETP_GT_U:
    case CCV::SETP_LE:
    case CCV::SETP_LE_F:
    case CCV::SETP_LE_F1:
    case CCV::SETP_LE_U:
    case CCV::SETP_LT:
    case CCV::SETP_LT_F:
    case CCV::SETP_LT_F1:
    case CCV::SETP_LT_U:
    case CCV::SETP_NE:
    case CCV::SETP_NE_F:
    case CCV::SETP_NE_F1: {
      switch (OpNum) {
      case 1:
        // op: rd
        return 11;
      case 3:
        // op: rs0
        return 15;
      case 4:
        // op: rs1
        return 19;
      case 2:
        // op: pq
        return 27;
      case 0:
        // op: pd
        return 30;
      }
      break;
    }
    case CCV::VOTE_ANY: {
      switch (OpNum) {
      case 2:
        // op: ps
        return 19;
      case 1:
        // op: pq
        return 27;
      case 0:
        // op: pd
        return 30;
      }
      break;
    }
    case CCV::UNBALLOT: {
      switch (OpNum) {
      case 2:
        // op: rs0
        return 15;
      case 1:
        // op: pq
        return 27;
      case 0:
        // op: pd
        return 30;
      }
      break;
    }
  }
  std::string msg;
  raw_string_ostream Msg(msg);
  Msg << "Not supported instr[opcode]: " << MI << "[" << OpNum << "]";
  report_fatal_error(Msg.str().c_str());
}

#endif // GET_OPERAND_BIT_OFFSET

