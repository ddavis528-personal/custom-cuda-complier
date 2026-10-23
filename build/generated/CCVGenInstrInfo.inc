/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Instruction Enum Values and Descriptors                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_INSTRINFO_ENUM
#undef GET_INSTRINFO_ENUM
namespace llvm {

namespace CCV {
  enum {
    PHI	= 0,
    INLINEASM	= 1,
    INLINEASM_BR	= 2,
    CFI_INSTRUCTION	= 3,
    EH_LABEL	= 4,
    GC_LABEL	= 5,
    ANNOTATION_LABEL	= 6,
    KILL	= 7,
    EXTRACT_SUBREG	= 8,
    INSERT_SUBREG	= 9,
    IMPLICIT_DEF	= 10,
    SUBREG_TO_REG	= 11,
    COPY_TO_REGCLASS	= 12,
    DBG_VALUE	= 13,
    DBG_VALUE_LIST	= 14,
    DBG_INSTR_REF	= 15,
    DBG_PHI	= 16,
    DBG_LABEL	= 17,
    REG_SEQUENCE	= 18,
    COPY	= 19,
    BUNDLE	= 20,
    LIFETIME_START	= 21,
    LIFETIME_END	= 22,
    PSEUDO_PROBE	= 23,
    ARITH_FENCE	= 24,
    STACKMAP	= 25,
    FENTRY_CALL	= 26,
    PATCHPOINT	= 27,
    LOAD_STACK_GUARD	= 28,
    PREALLOCATED_SETUP	= 29,
    PREALLOCATED_ARG	= 30,
    STATEPOINT	= 31,
    LOCAL_ESCAPE	= 32,
    FAULTING_OP	= 33,
    PATCHABLE_OP	= 34,
    PATCHABLE_FUNCTION_ENTER	= 35,
    PATCHABLE_RET	= 36,
    PATCHABLE_FUNCTION_EXIT	= 37,
    PATCHABLE_TAIL_CALL	= 38,
    PATCHABLE_EVENT_CALL	= 39,
    PATCHABLE_TYPED_EVENT_CALL	= 40,
    ICALL_BRANCH_FUNNEL	= 41,
    MEMBARRIER	= 42,
    JUMP_TABLE_DEBUG_INFO	= 43,
    G_ASSERT_SEXT	= 44,
    G_ASSERT_ZEXT	= 45,
    G_ASSERT_ALIGN	= 46,
    G_ADD	= 47,
    G_SUB	= 48,
    G_MUL	= 49,
    G_SDIV	= 50,
    G_UDIV	= 51,
    G_SREM	= 52,
    G_UREM	= 53,
    G_SDIVREM	= 54,
    G_UDIVREM	= 55,
    G_AND	= 56,
    G_OR	= 57,
    G_XOR	= 58,
    G_IMPLICIT_DEF	= 59,
    G_PHI	= 60,
    G_FRAME_INDEX	= 61,
    G_GLOBAL_VALUE	= 62,
    G_CONSTANT_POOL	= 63,
    G_EXTRACT	= 64,
    G_UNMERGE_VALUES	= 65,
    G_INSERT	= 66,
    G_MERGE_VALUES	= 67,
    G_BUILD_VECTOR	= 68,
    G_BUILD_VECTOR_TRUNC	= 69,
    G_CONCAT_VECTORS	= 70,
    G_PTRTOINT	= 71,
    G_INTTOPTR	= 72,
    G_BITCAST	= 73,
    G_FREEZE	= 74,
    G_CONSTANT_FOLD_BARRIER	= 75,
    G_INTRINSIC_FPTRUNC_ROUND	= 76,
    G_INTRINSIC_TRUNC	= 77,
    G_INTRINSIC_ROUND	= 78,
    G_INTRINSIC_LRINT	= 79,
    G_INTRINSIC_ROUNDEVEN	= 80,
    G_READCYCLECOUNTER	= 81,
    G_LOAD	= 82,
    G_SEXTLOAD	= 83,
    G_ZEXTLOAD	= 84,
    G_INDEXED_LOAD	= 85,
    G_INDEXED_SEXTLOAD	= 86,
    G_INDEXED_ZEXTLOAD	= 87,
    G_STORE	= 88,
    G_INDEXED_STORE	= 89,
    G_ATOMIC_CMPXCHG_WITH_SUCCESS	= 90,
    G_ATOMIC_CMPXCHG	= 91,
    G_ATOMICRMW_XCHG	= 92,
    G_ATOMICRMW_ADD	= 93,
    G_ATOMICRMW_SUB	= 94,
    G_ATOMICRMW_AND	= 95,
    G_ATOMICRMW_NAND	= 96,
    G_ATOMICRMW_OR	= 97,
    G_ATOMICRMW_XOR	= 98,
    G_ATOMICRMW_MAX	= 99,
    G_ATOMICRMW_MIN	= 100,
    G_ATOMICRMW_UMAX	= 101,
    G_ATOMICRMW_UMIN	= 102,
    G_ATOMICRMW_FADD	= 103,
    G_ATOMICRMW_FSUB	= 104,
    G_ATOMICRMW_FMAX	= 105,
    G_ATOMICRMW_FMIN	= 106,
    G_ATOMICRMW_UINC_WRAP	= 107,
    G_ATOMICRMW_UDEC_WRAP	= 108,
    G_FENCE	= 109,
    G_PREFETCH	= 110,
    G_BRCOND	= 111,
    G_BRINDIRECT	= 112,
    G_INVOKE_REGION_START	= 113,
    G_INTRINSIC	= 114,
    G_INTRINSIC_W_SIDE_EFFECTS	= 115,
    G_INTRINSIC_CONVERGENT	= 116,
    G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS	= 117,
    G_ANYEXT	= 118,
    G_TRUNC	= 119,
    G_CONSTANT	= 120,
    G_FCONSTANT	= 121,
    G_VASTART	= 122,
    G_VAARG	= 123,
    G_SEXT	= 124,
    G_SEXT_INREG	= 125,
    G_ZEXT	= 126,
    G_SHL	= 127,
    G_LSHR	= 128,
    G_ASHR	= 129,
    G_FSHL	= 130,
    G_FSHR	= 131,
    G_ROTR	= 132,
    G_ROTL	= 133,
    G_ICMP	= 134,
    G_FCMP	= 135,
    G_SELECT	= 136,
    G_UADDO	= 137,
    G_UADDE	= 138,
    G_USUBO	= 139,
    G_USUBE	= 140,
    G_SADDO	= 141,
    G_SADDE	= 142,
    G_SSUBO	= 143,
    G_SSUBE	= 144,
    G_UMULO	= 145,
    G_SMULO	= 146,
    G_UMULH	= 147,
    G_SMULH	= 148,
    G_UADDSAT	= 149,
    G_SADDSAT	= 150,
    G_USUBSAT	= 151,
    G_SSUBSAT	= 152,
    G_USHLSAT	= 153,
    G_SSHLSAT	= 154,
    G_SMULFIX	= 155,
    G_UMULFIX	= 156,
    G_SMULFIXSAT	= 157,
    G_UMULFIXSAT	= 158,
    G_SDIVFIX	= 159,
    G_UDIVFIX	= 160,
    G_SDIVFIXSAT	= 161,
    G_UDIVFIXSAT	= 162,
    G_FADD	= 163,
    G_FSUB	= 164,
    G_FMUL	= 165,
    G_FMA	= 166,
    G_FMAD	= 167,
    G_FDIV	= 168,
    G_FREM	= 169,
    G_FPOW	= 170,
    G_FPOWI	= 171,
    G_FEXP	= 172,
    G_FEXP2	= 173,
    G_FEXP10	= 174,
    G_FLOG	= 175,
    G_FLOG2	= 176,
    G_FLOG10	= 177,
    G_FLDEXP	= 178,
    G_FFREXP	= 179,
    G_FNEG	= 180,
    G_FPEXT	= 181,
    G_FPTRUNC	= 182,
    G_FPTOSI	= 183,
    G_FPTOUI	= 184,
    G_SITOFP	= 185,
    G_UITOFP	= 186,
    G_FABS	= 187,
    G_FCOPYSIGN	= 188,
    G_IS_FPCLASS	= 189,
    G_FCANONICALIZE	= 190,
    G_FMINNUM	= 191,
    G_FMAXNUM	= 192,
    G_FMINNUM_IEEE	= 193,
    G_FMAXNUM_IEEE	= 194,
    G_FMINIMUM	= 195,
    G_FMAXIMUM	= 196,
    G_GET_FPENV	= 197,
    G_SET_FPENV	= 198,
    G_RESET_FPENV	= 199,
    G_GET_FPMODE	= 200,
    G_SET_FPMODE	= 201,
    G_RESET_FPMODE	= 202,
    G_PTR_ADD	= 203,
    G_PTRMASK	= 204,
    G_SMIN	= 205,
    G_SMAX	= 206,
    G_UMIN	= 207,
    G_UMAX	= 208,
    G_ABS	= 209,
    G_LROUND	= 210,
    G_LLROUND	= 211,
    G_BR	= 212,
    G_BRJT	= 213,
    G_INSERT_VECTOR_ELT	= 214,
    G_EXTRACT_VECTOR_ELT	= 215,
    G_SHUFFLE_VECTOR	= 216,
    G_CTTZ	= 217,
    G_CTTZ_ZERO_UNDEF	= 218,
    G_CTLZ	= 219,
    G_CTLZ_ZERO_UNDEF	= 220,
    G_CTPOP	= 221,
    G_BSWAP	= 222,
    G_BITREVERSE	= 223,
    G_FCEIL	= 224,
    G_FCOS	= 225,
    G_FSIN	= 226,
    G_FSQRT	= 227,
    G_FFLOOR	= 228,
    G_FRINT	= 229,
    G_FNEARBYINT	= 230,
    G_ADDRSPACE_CAST	= 231,
    G_BLOCK_ADDR	= 232,
    G_JUMP_TABLE	= 233,
    G_DYN_STACKALLOC	= 234,
    G_STACKSAVE	= 235,
    G_STACKRESTORE	= 236,
    G_STRICT_FADD	= 237,
    G_STRICT_FSUB	= 238,
    G_STRICT_FMUL	= 239,
    G_STRICT_FDIV	= 240,
    G_STRICT_FREM	= 241,
    G_STRICT_FMA	= 242,
    G_STRICT_FSQRT	= 243,
    G_STRICT_FLDEXP	= 244,
    G_READ_REGISTER	= 245,
    G_WRITE_REGISTER	= 246,
    G_MEMCPY	= 247,
    G_MEMCPY_INLINE	= 248,
    G_MEMMOVE	= 249,
    G_MEMSET	= 250,
    G_BZERO	= 251,
    G_VECREDUCE_SEQ_FADD	= 252,
    G_VECREDUCE_SEQ_FMUL	= 253,
    G_VECREDUCE_FADD	= 254,
    G_VECREDUCE_FMUL	= 255,
    G_VECREDUCE_FMAX	= 256,
    G_VECREDUCE_FMIN	= 257,
    G_VECREDUCE_FMAXIMUM	= 258,
    G_VECREDUCE_FMINIMUM	= 259,
    G_VECREDUCE_ADD	= 260,
    G_VECREDUCE_MUL	= 261,
    G_VECREDUCE_AND	= 262,
    G_VECREDUCE_OR	= 263,
    G_VECREDUCE_XOR	= 264,
    G_VECREDUCE_SMAX	= 265,
    G_VECREDUCE_SMIN	= 266,
    G_VECREDUCE_UMAX	= 267,
    G_VECREDUCE_UMIN	= 268,
    G_SBFX	= 269,
    G_UBFX	= 270,
    ADJCALLSTACKDOWN	= 271,
    ADJCALLSTACKUP	= 272,
    PSEUDO_BCAST	= 273,
    PSEUDO_BRA_PRED	= 274,
    PSEUDO_CALL	= 275,
    PSEUDO_CAS_G	= 276,
    PSEUDO_CAS_S	= 277,
    PSEUDO_LD_PRED	= 278,
    PSEUDO_NARROW	= 279,
    PSEUDO_PADDI	= 280,
    PSEUDO_PAND	= 281,
    PSEUDO_PMOV	= 282,
    PSEUDO_POR	= 283,
    PSEUDO_PXOR	= 284,
    PSEUDO_RET	= 285,
    PSEUDO_ST_PRED	= 286,
    ABS	= 287,
    ADD	= 288,
    ADDI	= 289,
    ADDI48	= 290,
    ADDI_P	= 291,
    ADDI_PP	= 292,
    ADDI_W16	= 293,
    ADD_P	= 294,
    ADD_PP	= 295,
    ADD_W16	= 296,
    AND	= 297,
    ANDI	= 298,
    ANDI_P	= 299,
    ANDN	= 300,
    ANDNI	= 301,
    ANDNI_P	= 302,
    AND_P	= 303,
    AND_W16	= 304,
    ATOM_ADD_G	= 305,
    ATOM_ADD_S	= 306,
    ATOM_AND_G	= 307,
    ATOM_AND_S	= 308,
    ATOM_EXCH_G	= 309,
    ATOM_EXCH_S	= 310,
    ATOM_MAX_S_G	= 311,
    ATOM_MAX_S_S	= 312,
    ATOM_MAX_U_G	= 313,
    ATOM_MAX_U_S	= 314,
    ATOM_MIN_S_G	= 315,
    ATOM_MIN_S_S	= 316,
    ATOM_MIN_U_G	= 317,
    ATOM_MIN_U_S	= 318,
    ATOM_OR_G	= 319,
    ATOM_OR_S	= 320,
    ATOM_XOR_G	= 321,
    ATOM_XOR_S	= 322,
    BALLOT	= 323,
    BAR_INIT	= 324,
    BAR_WAIT_PHASE	= 325,
    BRA	= 326,
    BRA_PRED	= 327,
    BREV	= 328,
    CALL	= 329,
    CAS_G	= 330,
    CAS_S	= 331,
    CHWIDTH_MULTI	= 332,
    CLZ	= 333,
    COS_F32	= 334,
    CVT_D0_S0_R0	= 335,
    CVT_D0_S0_R0_P	= 336,
    CVT_D0_S0_R0_W16_32	= 337,
    CVT_D0_S0_R0_W16_8	= 338,
    CVT_D0_S0_R0_W32_16	= 339,
    CVT_D0_S0_R0_W32_4	= 340,
    CVT_D0_S0_R0_W32_8	= 341,
    CVT_D0_S0_R0_W4_32	= 342,
    CVT_D0_S0_R0_W8_32	= 343,
    CVT_D0_S0_R1	= 344,
    CVT_D0_S0_R1_P	= 345,
    CVT_D0_S0_R2	= 346,
    CVT_D0_S0_R2_P	= 347,
    CVT_D0_S0_R3	= 348,
    CVT_D0_S0_R3_P	= 349,
    CVT_D0_S1_R0	= 350,
    CVT_D0_S1_R0_P	= 351,
    CVT_D0_S1_R0_W16_8	= 352,
    CVT_D0_S1_R0_W32_8	= 353,
    CVT_D0_S1_R1	= 354,
    CVT_D0_S1_R1_P	= 355,
    CVT_D0_S1_R2	= 356,
    CVT_D0_S1_R2_P	= 357,
    CVT_D0_S1_R3	= 358,
    CVT_D0_S1_R3_P	= 359,
    CVT_D0_S2_R1	= 360,
    CVT_D0_S2_R1_P	= 361,
    CVT_D0_S2_R2	= 362,
    CVT_D0_S2_R2_P	= 363,
    CVT_D0_S2_R3	= 364,
    CVT_D0_S2_R3_P	= 365,
    CVT_D0_S3_R1	= 366,
    CVT_D0_S3_R1_P	= 367,
    CVT_D0_S3_R2	= 368,
    CVT_D0_S3_R2_P	= 369,
    CVT_D0_S3_R3	= 370,
    CVT_D0_S3_R3_P	= 371,
    CVT_D1_S0_R0	= 372,
    CVT_D1_S0_R0_P	= 373,
    CVT_D1_S0_R0_W8_32	= 374,
    CVT_D1_S0_R1	= 375,
    CVT_D1_S0_R1_P	= 376,
    CVT_D1_S0_R2	= 377,
    CVT_D1_S0_R2_P	= 378,
    CVT_D1_S0_R3	= 379,
    CVT_D1_S0_R3_P	= 380,
    CVT_D1_S1_R0	= 381,
    CVT_D1_S1_R0_P	= 382,
    CVT_D1_S1_R1	= 383,
    CVT_D1_S1_R1_P	= 384,
    CVT_D1_S1_R2	= 385,
    CVT_D1_S1_R2_P	= 386,
    CVT_D1_S1_R3	= 387,
    CVT_D1_S1_R3_P	= 388,
    CVT_D1_S2_R0	= 389,
    CVT_D1_S2_R0_P	= 390,
    CVT_D1_S2_R1	= 391,
    CVT_D1_S2_R1_P	= 392,
    CVT_D1_S2_R2	= 393,
    CVT_D1_S2_R2_P	= 394,
    CVT_D1_S2_R3	= 395,
    CVT_D1_S2_R3_P	= 396,
    CVT_D1_S3_R0	= 397,
    CVT_D1_S3_R0_P	= 398,
    CVT_D1_S3_R1	= 399,
    CVT_D1_S3_R1_P	= 400,
    CVT_D1_S3_R2	= 401,
    CVT_D1_S3_R2_P	= 402,
    CVT_D1_S3_R3	= 403,
    CVT_D1_S3_R3_P	= 404,
    CVT_D2_S0_R0	= 405,
    CVT_D2_S0_R0_P	= 406,
    CVT_D2_S0_R2	= 407,
    CVT_D2_S0_R2_P	= 408,
    CVT_D2_S0_R3	= 409,
    CVT_D2_S0_R3_P	= 410,
    CVT_D2_S1_R0	= 411,
    CVT_D2_S1_R0_P	= 412,
    CVT_D2_S1_R1	= 413,
    CVT_D2_S1_R1_P	= 414,
    CVT_D2_S1_R2	= 415,
    CVT_D2_S1_R2_P	= 416,
    CVT_D2_S1_R3	= 417,
    CVT_D2_S1_R3_P	= 418,
    CVT_D2_S3_R0	= 419,
    CVT_D2_S3_R0_P	= 420,
    CVT_D3_S0_R0	= 421,
    CVT_D3_S0_R0_P	= 422,
    CVT_D3_S0_R2	= 423,
    CVT_D3_S0_R2_P	= 424,
    CVT_D3_S0_R3	= 425,
    CVT_D3_S0_R3_P	= 426,
    CVT_D3_S1_R0	= 427,
    CVT_D3_S1_R0_P	= 428,
    CVT_D3_S1_R1	= 429,
    CVT_D3_S1_R1_P	= 430,
    CVT_D3_S1_R2	= 431,
    CVT_D3_S1_R2_P	= 432,
    CVT_D3_S1_R3	= 433,
    CVT_D3_S1_R3_P	= 434,
    CVT_D3_S2_R0	= 435,
    CVT_D3_S2_R0_P	= 436,
    CVT_D3_S3_R0	= 437,
    CVT_D3_S3_R0_P	= 438,
    CVT_F32_S32	= 439,
    CVT_F32_S32_P	= 440,
    CVT_F32_U32	= 441,
    CVT_F32_U32_P	= 442,
    CVT_S32_F32	= 443,
    CVT_S32_F32_P	= 444,
    CVT_SEXT	= 445,
    CVT_U32_F32	= 446,
    CVT_U32_F32_P	= 447,
    C_ABS	= 448,
    C_ADD	= 449,
    C_ADDI	= 450,
    C_AND	= 451,
    C_ANDI	= 452,
    C_ANDN	= 453,
    C_BAR_ARRIVE	= 454,
    C_BAR_WAIT	= 455,
    C_BRA	= 456,
    C_CHWIDTH	= 457,
    C_EXIT	= 458,
    C_FADD	= 459,
    C_FENCE	= 460,
    C_FMAX	= 461,
    C_FMIN	= 462,
    C_FMUL	= 463,
    C_LD_GLOBAL	= 464,
    C_MAX_S	= 465,
    C_MAX_U	= 466,
    C_MIN_S	= 467,
    C_MIN_U	= 468,
    C_MOV	= 469,
    C_MUL_LO	= 470,
    C_NEG	= 471,
    C_NOT	= 472,
    C_OR	= 473,
    C_ORI	= 474,
    C_RECONV	= 475,
    C_RET	= 476,
    C_SHL	= 477,
    C_SHLI	= 478,
    C_SHR	= 479,
    C_SHRI	= 480,
    C_SRA	= 481,
    C_SRAI	= 482,
    C_ST_GLOBAL	= 483,
    C_SUB	= 484,
    C_SUBI	= 485,
    C_XOR	= 486,
    C_XORI	= 487,
    DP2_BF16	= 488,
    DP2_F16	= 489,
    DP4_ACC	= 490,
    DP4_E4M3	= 491,
    DP4_E5M2	= 492,
    DP4_SS	= 493,
    EX2_F32	= 494,
    FABS_F0	= 495,
    FABS_F1	= 496,
    FADD	= 497,
    FADD_F1	= 498,
    FADD_F1_W8	= 499,
    FADD_P	= 500,
    FADD_W8	= 501,
    FFMA_ACC_F0	= 502,
    FFMA_ACC_F1	= 503,
    FFMA_F0	= 504,
    FFMA_F1	= 505,
    FMAX	= 506,
    FMAX_F1	= 507,
    FMIN	= 508,
    FMIN_F1	= 509,
    FMUL	= 510,
    FMUL_F1	= 511,
    FMUL_F1_W8	= 512,
    FMUL_P	= 513,
    FMUL_W8	= 514,
    FNEG_F0	= 515,
    FNEG_F1	= 516,
    FSUB	= 517,
    FSUB_F1	= 518,
    FSUB_F1_W8	= 519,
    FSUB_P	= 520,
    FSUB_W8	= 521,
    LD_GLOBAL	= 522,
    LD_GLOBAL_IDX	= 523,
    LD_GLOBAL_IDX_W16	= 524,
    LD_GLOBAL_IDX_W8	= 525,
    LD_GLOBAL_P	= 526,
    LD_GLOBAL_SLOT	= 527,
    LD_GLOBAL_SLOT_W16	= 528,
    LD_GLOBAL_SLOT_W8	= 529,
    LD_GLOBAL_W16	= 530,
    LD_GLOBAL_W8	= 531,
    LD_LOCAL	= 532,
    LD_PRED_G	= 533,
    LD_PRED_LOCAL	= 534,
    LD_PRED_S	= 535,
    LD_SHARED	= 536,
    LD_SHARED_IDX	= 537,
    LD_SHARED_W16	= 538,
    LD_SHARED_W8	= 539,
    LG2_F32	= 540,
    MADLO	= 541,
    MADLO_P	= 542,
    MAD_ACC	= 543,
    MAX_S	= 544,
    MAX_S_P	= 545,
    MAX_S_W16	= 546,
    MAX_U	= 547,
    MAX_U_P	= 548,
    MIN_S	= 549,
    MIN_S_P	= 550,
    MIN_S_W16	= 551,
    MIN_U	= 552,
    MIN_U_P	= 553,
    MOVI	= 554,
    MOVI48	= 555,
    MOV_P	= 556,
    MULI	= 557,
    MULI_P	= 558,
    MUL_HI_S	= 559,
    MUL_HI_S_P	= 560,
    MUL_HI_U	= 561,
    MUL_HI_U_P	= 562,
    MUL_LO	= 563,
    NEG	= 564,
    OR	= 565,
    ORI	= 566,
    ORI_P	= 567,
    OR_P	= 568,
    OR_W16	= 569,
    PACKI	= 570,
    PACKI_Z	= 571,
    PAND	= 572,
    PMOV	= 573,
    PMOV_IMM	= 574,
    POPC	= 575,
    POR	= 576,
    PXOR	= 577,
    RCP_F32	= 578,
    RCP_F32_P	= 579,
    RCP_U32	= 580,
    RSQRT_F32	= 581,
    SEL	= 582,
    SETP_EQ	= 583,
    SETP_EQ_F	= 584,
    SETP_EQ_F1	= 585,
    SETP_EQ_F1_NP	= 586,
    SETP_EQ_F_I	= 587,
    SETP_EQ_F_NP	= 588,
    SETP_EQ_F_NPI	= 589,
    SETP_EQ_I	= 590,
    SETP_EQ_NP	= 591,
    SETP_EQ_NPI	= 592,
    SETP_GE	= 593,
    SETP_GE_F	= 594,
    SETP_GE_F1	= 595,
    SETP_GE_F1_NP	= 596,
    SETP_GE_F_I	= 597,
    SETP_GE_F_NP	= 598,
    SETP_GE_F_NPI	= 599,
    SETP_GE_I	= 600,
    SETP_GE_NP	= 601,
    SETP_GE_NPI	= 602,
    SETP_GE_U	= 603,
    SETP_GE_U_I	= 604,
    SETP_GE_U_NP	= 605,
    SETP_GE_U_NPI	= 606,
    SETP_GT	= 607,
    SETP_GT_F	= 608,
    SETP_GT_F1	= 609,
    SETP_GT_F1_NP	= 610,
    SETP_GT_F_I	= 611,
    SETP_GT_F_NP	= 612,
    SETP_GT_F_NPI	= 613,
    SETP_GT_I	= 614,
    SETP_GT_NP	= 615,
    SETP_GT_NPI	= 616,
    SETP_GT_U	= 617,
    SETP_GT_U_I	= 618,
    SETP_GT_U_NP	= 619,
    SETP_GT_U_NPI	= 620,
    SETP_LE	= 621,
    SETP_LE_F	= 622,
    SETP_LE_F1	= 623,
    SETP_LE_F1_NP	= 624,
    SETP_LE_F_I	= 625,
    SETP_LE_F_NP	= 626,
    SETP_LE_F_NPI	= 627,
    SETP_LE_I	= 628,
    SETP_LE_NP	= 629,
    SETP_LE_NPI	= 630,
    SETP_LE_U	= 631,
    SETP_LE_U_I	= 632,
    SETP_LE_U_NP	= 633,
    SETP_LE_U_NPI	= 634,
    SETP_LT	= 635,
    SETP_LT_F	= 636,
    SETP_LT_F1	= 637,
    SETP_LT_F1_NP	= 638,
    SETP_LT_F_I	= 639,
    SETP_LT_F_NP	= 640,
    SETP_LT_F_NPI	= 641,
    SETP_LT_I	= 642,
    SETP_LT_NP	= 643,
    SETP_LT_NPI	= 644,
    SETP_LT_U	= 645,
    SETP_LT_U_I	= 646,
    SETP_LT_U_NP	= 647,
    SETP_LT_U_NPI	= 648,
    SETP_NE	= 649,
    SETP_NE_F	= 650,
    SETP_NE_F1	= 651,
    SETP_NE_F1_NP	= 652,
    SETP_NE_F_I	= 653,
    SETP_NE_F_NP	= 654,
    SETP_NE_F_NPI	= 655,
    SETP_NE_I	= 656,
    SETP_NE_NP	= 657,
    SETP_NE_NPI	= 658,
    SHFL_IDX	= 659,
    SHL	= 660,
    SHLI	= 661,
    SHLI_P	= 662,
    SHL_P	= 663,
    SHR	= 664,
    SHRI	= 665,
    SHRI_P	= 666,
    SHR_P	= 667,
    SIN_F32	= 668,
    SQRT_F32	= 669,
    SRA	= 670,
    SRAI	= 671,
    SRAI_P	= 672,
    SRA_P	= 673,
    SRD	= 674,
    ST_GLOBAL	= 675,
    ST_GLOBAL_IDX	= 676,
    ST_GLOBAL_IDX_W16	= 677,
    ST_GLOBAL_IDX_W8	= 678,
    ST_GLOBAL_SLOT	= 679,
    ST_GLOBAL_SLOT_W16	= 680,
    ST_GLOBAL_SLOT_W8	= 681,
    ST_GLOBAL_W16	= 682,
    ST_GLOBAL_W8	= 683,
    ST_LOCAL	= 684,
    ST_PRED_G	= 685,
    ST_PRED_LOCAL	= 686,
    ST_PRED_S	= 687,
    ST_SHARED	= 688,
    ST_SHARED_IDX	= 689,
    ST_SHARED_W16	= 690,
    ST_SHARED_W8	= 691,
    SUB	= 692,
    SUBI	= 693,
    SUBI_P	= 694,
    SUB_P	= 695,
    SUB_W16	= 696,
    UNBALLOT	= 697,
    UNPACKI	= 698,
    VOTE_ANY	= 699,
    XOR	= 700,
    XORI	= 701,
    XORI_P	= 702,
    XOR_P	= 703,
    XOR_W16	= 704,
    INSTRUCTION_LIST_END = 705
  };

} // end namespace CCV
} // end namespace llvm
#endif // GET_INSTRINFO_ENUM

#ifdef GET_INSTRINFO_SCHED_ENUM
#undef GET_INSTRINFO_SCHED_ENUM
namespace llvm {

namespace CCV {
namespace Sched {
  enum {
    NoInstrModel	= 0,
    SCHED_LIST_END = 1
  };
} // end namespace Sched
} // end namespace CCV
} // end namespace llvm
#endif // GET_INSTRINFO_SCHED_ENUM

#if defined(GET_INSTRINFO_MC_DESC) || defined(GET_INSTRINFO_CTOR_DTOR)
namespace llvm {

struct CCVInstrTable {
  MCInstrDesc Insts[705];
  static_assert(alignof(MCInstrDesc) >= alignof(MCOperandInfo), "Unwanted padding between Insts and OperandInfo");
  MCOperandInfo OperandInfo[352];
  static_assert(alignof(MCOperandInfo) >= alignof(MCPhysReg), "Unwanted padding between OperandInfo and ImplicitOps");
  MCPhysReg ImplicitOps[1];
};

} // end namespace llvm
#endif // defined(GET_INSTRINFO_MC_DESC) || defined(GET_INSTRINFO_CTOR_DTOR)

#ifdef GET_INSTRINFO_MC_DESC
#undef GET_INSTRINFO_MC_DESC
namespace llvm {

static_assert(sizeof(MCOperandInfo) % sizeof(MCPhysReg) == 0);
static constexpr unsigned CCVImpOpBase = sizeof CCVInstrTable::OperandInfo / (sizeof(MCPhysReg));

extern const CCVInstrTable CCVDescs = {
  {
    { 704,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #704 = XOR_W16
    { 703,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #703 = XOR_P
    { 702,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #702 = XORI_P
    { 701,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #701 = XORI
    { 700,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #700 = XOR
    { 699,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	349,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #699 = VOTE_ANY
    { 698,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #698 = UNPACKI
    { 697,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	346,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #697 = UNBALLOT
    { 696,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #696 = SUB_W16
    { 695,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #695 = SUB_P
    { 694,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #694 = SUBI_P
    { 693,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #693 = SUBI
    { 692,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #692 = SUB
    { 691,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	305,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #691 = ST_SHARED_W8
    { 690,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #690 = ST_SHARED_W16
    { 689,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	272,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #689 = ST_SHARED_IDX
    { 688,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #688 = ST_SHARED
    { 687,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #687 = ST_PRED_S
    { 686,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #686 = ST_PRED_LOCAL
    { 685,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #685 = ST_PRED_G
    { 684,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #684 = ST_LOCAL
    { 683,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	305,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #683 = ST_GLOBAL_W8
    { 682,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #682 = ST_GLOBAL_W16
    { 681,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #681 = ST_GLOBAL_SLOT_W8
    { 680,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	292,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #680 = ST_GLOBAL_SLOT_W16
    { 679,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	287,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #679 = ST_GLOBAL_SLOT
    { 678,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	282,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #678 = ST_GLOBAL_IDX_W8
    { 677,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	277,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #677 = ST_GLOBAL_IDX_W16
    { 676,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	272,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #676 = ST_GLOBAL_IDX
    { 675,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #675 = ST_GLOBAL
    { 674,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #674 = SRD
    { 673,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #673 = SRA_P
    { 672,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #672 = SRAI_P
    { 671,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #671 = SRAI
    { 670,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #670 = SRA
    { 669,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #669 = SQRT_F32
    { 668,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #668 = SIN_F32
    { 667,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #667 = SHR_P
    { 666,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #666 = SHRI_P
    { 665,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #665 = SHRI
    { 664,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #664 = SHR
    { 663,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #663 = SHL_P
    { 662,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #662 = SHLI_P
    { 661,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #661 = SHLI
    { 660,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #660 = SHL
    { 659,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #659 = SHFL_IDX
    { 658,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #658 = SETP_NE_NPI
    { 657,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #657 = SETP_NE_NP
    { 656,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #656 = SETP_NE_I
    { 655,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #655 = SETP_NE_F_NPI
    { 654,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #654 = SETP_NE_F_NP
    { 653,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #653 = SETP_NE_F_I
    { 652,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #652 = SETP_NE_F1_NP
    { 651,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #651 = SETP_NE_F1
    { 650,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #650 = SETP_NE_F
    { 649,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #649 = SETP_NE
    { 648,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #648 = SETP_LT_U_NPI
    { 647,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #647 = SETP_LT_U_NP
    { 646,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #646 = SETP_LT_U_I
    { 645,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #645 = SETP_LT_U
    { 644,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #644 = SETP_LT_NPI
    { 643,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #643 = SETP_LT_NP
    { 642,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #642 = SETP_LT_I
    { 641,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #641 = SETP_LT_F_NPI
    { 640,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #640 = SETP_LT_F_NP
    { 639,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #639 = SETP_LT_F_I
    { 638,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #638 = SETP_LT_F1_NP
    { 637,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #637 = SETP_LT_F1
    { 636,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #636 = SETP_LT_F
    { 635,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #635 = SETP_LT
    { 634,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #634 = SETP_LE_U_NPI
    { 633,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #633 = SETP_LE_U_NP
    { 632,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #632 = SETP_LE_U_I
    { 631,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #631 = SETP_LE_U
    { 630,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #630 = SETP_LE_NPI
    { 629,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #629 = SETP_LE_NP
    { 628,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #628 = SETP_LE_I
    { 627,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #627 = SETP_LE_F_NPI
    { 626,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #626 = SETP_LE_F_NP
    { 625,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #625 = SETP_LE_F_I
    { 624,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #624 = SETP_LE_F1_NP
    { 623,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #623 = SETP_LE_F1
    { 622,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #622 = SETP_LE_F
    { 621,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #621 = SETP_LE
    { 620,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #620 = SETP_GT_U_NPI
    { 619,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #619 = SETP_GT_U_NP
    { 618,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #618 = SETP_GT_U_I
    { 617,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #617 = SETP_GT_U
    { 616,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #616 = SETP_GT_NPI
    { 615,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #615 = SETP_GT_NP
    { 614,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #614 = SETP_GT_I
    { 613,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #613 = SETP_GT_F_NPI
    { 612,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #612 = SETP_GT_F_NP
    { 611,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #611 = SETP_GT_F_I
    { 610,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #610 = SETP_GT_F1_NP
    { 609,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #609 = SETP_GT_F1
    { 608,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #608 = SETP_GT_F
    { 607,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #607 = SETP_GT
    { 606,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #606 = SETP_GE_U_NPI
    { 605,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #605 = SETP_GE_U_NP
    { 604,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #604 = SETP_GE_U_I
    { 603,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #603 = SETP_GE_U
    { 602,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #602 = SETP_GE_NPI
    { 601,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #601 = SETP_GE_NP
    { 600,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #600 = SETP_GE_I
    { 599,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #599 = SETP_GE_F_NPI
    { 598,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #598 = SETP_GE_F_NP
    { 597,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #597 = SETP_GE_F_I
    { 596,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #596 = SETP_GE_F1_NP
    { 595,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #595 = SETP_GE_F1
    { 594,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #594 = SETP_GE_F
    { 593,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #593 = SETP_GE
    { 592,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #592 = SETP_EQ_NPI
    { 591,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #591 = SETP_EQ_NP
    { 590,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #590 = SETP_EQ_I
    { 589,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	342,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #589 = SETP_EQ_F_NPI
    { 588,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #588 = SETP_EQ_F_NP
    { 587,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	337,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #587 = SETP_EQ_F_I
    { 586,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	333,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #586 = SETP_EQ_F1_NP
    { 585,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #585 = SETP_EQ_F1
    { 584,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #584 = SETP_EQ_F
    { 583,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	328,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #583 = SETP_EQ
    { 582,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #582 = SEL
    { 581,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #581 = RSQRT_F32
    { 580,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #580 = RCP_U32
    { 579,	5,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #579 = RCP_F32_P
    { 578,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #578 = RCP_F32
    { 577,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	323,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #577 = PXOR
    { 576,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	323,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #576 = POR
    { 575,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #575 = POPC
    { 574,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	326,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #574 = PMOV_IMM
    { 573,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	323,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #573 = PMOV
    { 572,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	323,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #572 = PAND
    { 571,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #571 = PACKI_Z
    { 570,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	319,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #570 = PACKI
    { 569,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #569 = OR_W16
    { 568,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #568 = OR_P
    { 567,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #567 = ORI_P
    { 566,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #566 = ORI
    { 565,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #565 = OR
    { 564,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #564 = NEG
    { 563,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #563 = MUL_LO
    { 562,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #562 = MUL_HI_U_P
    { 561,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #561 = MUL_HI_U
    { 560,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #560 = MUL_HI_S_P
    { 559,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #559 = MUL_HI_S
    { 558,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #558 = MULI_P
    { 557,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #557 = MULI
    { 556,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	313,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #556 = MOV_P
    { 555,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #555 = MOVI48
    { 554,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #554 = MOVI
    { 553,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #553 = MIN_U_P
    { 552,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #552 = MIN_U
    { 551,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #551 = MIN_S_W16
    { 550,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #550 = MIN_S_P
    { 549,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #549 = MIN_S
    { 548,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #548 = MAX_U_P
    { 547,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #547 = MAX_U
    { 546,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #546 = MAX_S_W16
    { 545,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #545 = MAX_S_P
    { 544,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #544 = MAX_S
    { 543,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #543 = MAD_ACC
    { 542,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #542 = MADLO_P
    { 541,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #541 = MADLO
    { 540,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #540 = LG2_F32
    { 539,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	305,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #539 = LD_SHARED_W8
    { 538,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #538 = LD_SHARED_W16
    { 537,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	272,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #537 = LD_SHARED_IDX
    { 536,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #536 = LD_SHARED
    { 535,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #535 = LD_PRED_S
    { 534,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #534 = LD_PRED_LOCAL
    { 533,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #533 = LD_PRED_G
    { 532,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #532 = LD_LOCAL
    { 531,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	305,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #531 = LD_GLOBAL_W8
    { 530,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #530 = LD_GLOBAL_W16
    { 529,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #529 = LD_GLOBAL_SLOT_W8
    { 528,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	292,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #528 = LD_GLOBAL_SLOT_W16
    { 527,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	287,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #527 = LD_GLOBAL_SLOT
    { 526,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #526 = LD_GLOBAL_P
    { 525,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	282,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #525 = LD_GLOBAL_IDX_W8
    { 524,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	277,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #524 = LD_GLOBAL_IDX_W16
    { 523,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	272,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #523 = LD_GLOBAL_IDX
    { 522,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #522 = LD_GLOBAL
    { 521,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #521 = FSUB_W8
    { 520,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #520 = FSUB_P
    { 519,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #519 = FSUB_F1_W8
    { 518,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #518 = FSUB_F1
    { 517,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #517 = FSUB
    { 516,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #516 = FNEG_F1
    { 515,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #515 = FNEG_F0
    { 514,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #514 = FMUL_W8
    { 513,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #513 = FMUL_P
    { 512,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #512 = FMUL_F1_W8
    { 511,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #511 = FMUL_F1
    { 510,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #510 = FMUL
    { 509,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #509 = FMIN_F1
    { 508,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #508 = FMIN
    { 507,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #507 = FMAX_F1
    { 506,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #506 = FMAX
    { 505,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #505 = FFMA_F1
    { 504,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #504 = FFMA_F0
    { 503,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #503 = FFMA_ACC_F1
    { 502,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #502 = FFMA_ACC_F0
    { 501,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #501 = FADD_W8
    { 500,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #500 = FADD_P
    { 499,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #499 = FADD_F1_W8
    { 498,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #498 = FADD_F1
    { 497,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #497 = FADD
    { 496,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #496 = FABS_F1
    { 495,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #495 = FABS_F0
    { 494,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #494 = EX2_F32
    { 493,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #493 = DP4_SS
    { 492,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #492 = DP4_E5M2
    { 491,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #491 = DP4_E4M3
    { 490,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #490 = DP4_ACC
    { 489,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #489 = DP2_F16
    { 488,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #488 = DP2_BF16
    { 487,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #487 = C_XORI
    { 486,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #486 = C_XOR
    { 485,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #485 = C_SUBI
    { 484,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #484 = C_SUB
    { 483,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #483 = C_ST_GLOBAL
    { 482,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #482 = C_SRAI
    { 481,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #481 = C_SRA
    { 480,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #480 = C_SHRI
    { 479,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #479 = C_SHR
    { 478,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #478 = C_SHLI
    { 477,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #477 = C_SHL
    { 476,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #476 = C_RET
    { 475,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #475 = C_RECONV
    { 474,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #474 = C_ORI
    { 473,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #473 = C_OR
    { 472,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #472 = C_NOT
    { 471,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #471 = C_NEG
    { 470,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #470 = C_MUL_LO
    { 469,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #469 = C_MOV
    { 468,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #468 = C_MIN_U
    { 467,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #467 = C_MIN_S
    { 466,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #466 = C_MAX_U
    { 465,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #465 = C_MAX_S
    { 464,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #464 = C_LD_GLOBAL
    { 463,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #463 = C_FMUL
    { 462,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #462 = C_FMIN
    { 461,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #461 = C_FMAX
    { 460,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #460 = C_FENCE
    { 459,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #459 = C_FADD
    { 458,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #458 = C_EXIT
    { 457,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #457 = C_CHWIDTH
    { 456,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #456 = C_BRA
    { 455,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #455 = C_BAR_WAIT
    { 454,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #454 = C_BAR_ARRIVE
    { 453,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #453 = C_ANDN
    { 452,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #452 = C_ANDI
    { 451,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #451 = C_AND
    { 450,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	261,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #450 = C_ADDI
    { 449,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #449 = C_ADD
    { 448,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #448 = C_ABS
    { 447,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #447 = CVT_U32_F32_P
    { 446,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #446 = CVT_U32_F32
    { 445,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	238,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #445 = CVT_SEXT
    { 444,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #444 = CVT_S32_F32_P
    { 443,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #443 = CVT_S32_F32
    { 442,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #442 = CVT_F32_U32_P
    { 441,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #441 = CVT_F32_U32
    { 440,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #440 = CVT_F32_S32_P
    { 439,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #439 = CVT_F32_S32
    { 438,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #438 = CVT_D3_S3_R0_P
    { 437,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #437 = CVT_D3_S3_R0
    { 436,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #436 = CVT_D3_S2_R0_P
    { 435,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #435 = CVT_D3_S2_R0
    { 434,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #434 = CVT_D3_S1_R3_P
    { 433,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #433 = CVT_D3_S1_R3
    { 432,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #432 = CVT_D3_S1_R2_P
    { 431,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #431 = CVT_D3_S1_R2
    { 430,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #430 = CVT_D3_S1_R1_P
    { 429,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #429 = CVT_D3_S1_R1
    { 428,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #428 = CVT_D3_S1_R0_P
    { 427,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #427 = CVT_D3_S1_R0
    { 426,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #426 = CVT_D3_S0_R3_P
    { 425,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #425 = CVT_D3_S0_R3
    { 424,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #424 = CVT_D3_S0_R2_P
    { 423,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #423 = CVT_D3_S0_R2
    { 422,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #422 = CVT_D3_S0_R0_P
    { 421,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #421 = CVT_D3_S0_R0
    { 420,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #420 = CVT_D2_S3_R0_P
    { 419,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #419 = CVT_D2_S3_R0
    { 418,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #418 = CVT_D2_S1_R3_P
    { 417,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #417 = CVT_D2_S1_R3
    { 416,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #416 = CVT_D2_S1_R2_P
    { 415,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #415 = CVT_D2_S1_R2
    { 414,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #414 = CVT_D2_S1_R1_P
    { 413,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #413 = CVT_D2_S1_R1
    { 412,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #412 = CVT_D2_S1_R0_P
    { 411,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #411 = CVT_D2_S1_R0
    { 410,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #410 = CVT_D2_S0_R3_P
    { 409,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #409 = CVT_D2_S0_R3
    { 408,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #408 = CVT_D2_S0_R2_P
    { 407,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #407 = CVT_D2_S0_R2
    { 406,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #406 = CVT_D2_S0_R0_P
    { 405,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #405 = CVT_D2_S0_R0
    { 404,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #404 = CVT_D1_S3_R3_P
    { 403,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #403 = CVT_D1_S3_R3
    { 402,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #402 = CVT_D1_S3_R2_P
    { 401,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #401 = CVT_D1_S3_R2
    { 400,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #400 = CVT_D1_S3_R1_P
    { 399,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #399 = CVT_D1_S3_R1
    { 398,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #398 = CVT_D1_S3_R0_P
    { 397,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #397 = CVT_D1_S3_R0
    { 396,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #396 = CVT_D1_S2_R3_P
    { 395,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #395 = CVT_D1_S2_R3
    { 394,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #394 = CVT_D1_S2_R2_P
    { 393,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #393 = CVT_D1_S2_R2
    { 392,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #392 = CVT_D1_S2_R1_P
    { 391,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #391 = CVT_D1_S2_R1
    { 390,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #390 = CVT_D1_S2_R0_P
    { 389,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #389 = CVT_D1_S2_R0
    { 388,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #388 = CVT_D1_S1_R3_P
    { 387,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #387 = CVT_D1_S1_R3
    { 386,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #386 = CVT_D1_S1_R2_P
    { 385,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #385 = CVT_D1_S1_R2
    { 384,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #384 = CVT_D1_S1_R1_P
    { 383,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #383 = CVT_D1_S1_R1
    { 382,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #382 = CVT_D1_S1_R0_P
    { 381,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #381 = CVT_D1_S1_R0
    { 380,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #380 = CVT_D1_S0_R3_P
    { 379,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #379 = CVT_D1_S0_R3
    { 378,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #378 = CVT_D1_S0_R2_P
    { 377,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #377 = CVT_D1_S0_R2
    { 376,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #376 = CVT_D1_S0_R1_P
    { 375,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #375 = CVT_D1_S0_R1
    { 374,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	254,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #374 = CVT_D1_S0_R0_W8_32
    { 373,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #373 = CVT_D1_S0_R0_P
    { 372,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #372 = CVT_D1_S0_R0
    { 371,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #371 = CVT_D0_S3_R3_P
    { 370,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #370 = CVT_D0_S3_R3
    { 369,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #369 = CVT_D0_S3_R2_P
    { 368,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #368 = CVT_D0_S3_R2
    { 367,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #367 = CVT_D0_S3_R1_P
    { 366,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #366 = CVT_D0_S3_R1
    { 365,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #365 = CVT_D0_S2_R3_P
    { 364,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #364 = CVT_D0_S2_R3
    { 363,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #363 = CVT_D0_S2_R2_P
    { 362,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #362 = CVT_D0_S2_R2
    { 361,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #361 = CVT_D0_S2_R1_P
    { 360,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #360 = CVT_D0_S2_R1
    { 359,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #359 = CVT_D0_S1_R3_P
    { 358,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #358 = CVT_D0_S1_R3
    { 357,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #357 = CVT_D0_S1_R2_P
    { 356,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #356 = CVT_D0_S1_R2
    { 355,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #355 = CVT_D0_S1_R1_P
    { 354,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #354 = CVT_D0_S1_R1
    { 353,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #353 = CVT_D0_S1_R0_W32_8
    { 352,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	234,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #352 = CVT_D0_S1_R0_W16_8
    { 351,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #351 = CVT_D0_S1_R0_P
    { 350,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #350 = CVT_D0_S1_R0
    { 349,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #349 = CVT_D0_S0_R3_P
    { 348,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #348 = CVT_D0_S0_R3
    { 347,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #347 = CVT_D0_S0_R2_P
    { 346,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #346 = CVT_D0_S0_R2
    { 345,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #345 = CVT_D0_S0_R1_P
    { 344,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #344 = CVT_D0_S0_R1
    { 343,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	254,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #343 = CVT_D0_S0_R0_W8_32
    { 342,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #342 = CVT_D0_S0_R0_W4_32
    { 341,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #341 = CVT_D0_S0_R0_W32_8
    { 340,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #340 = CVT_D0_S0_R0_W32_4
    { 339,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	238,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #339 = CVT_D0_S0_R0_W32_16
    { 338,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	234,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #338 = CVT_D0_S0_R0_W16_8
    { 337,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	230,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #337 = CVT_D0_S0_R0_W16_32
    { 336,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #336 = CVT_D0_S0_R0_P
    { 335,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #335 = CVT_D0_S0_R0
    { 334,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #334 = COS_F32
    { 333,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #333 = CLZ
    { 332,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #332 = CHWIDTH_MULTI
    { 331,	9,	2,	6,	0,	0,	0,	CCVImpOpBase + 0,	221,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #331 = CAS_S
    { 330,	9,	2,	6,	0,	0,	0,	CCVImpOpBase + 0,	221,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #330 = CAS_G
    { 329,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #329 = CALL
    { 328,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #328 = BREV
    { 327,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #327 = BRA_PRED
    { 326,	1,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #326 = BRA
    { 325,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	214,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #325 = BAR_WAIT_PHASE
    { 324,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #324 = BAR_INIT
    { 323,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #323 = BALLOT
    { 322,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #322 = ATOM_XOR_S
    { 321,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #321 = ATOM_XOR_G
    { 320,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #320 = ATOM_OR_S
    { 319,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #319 = ATOM_OR_G
    { 318,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #318 = ATOM_MIN_U_S
    { 317,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #317 = ATOM_MIN_U_G
    { 316,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #316 = ATOM_MIN_S_S
    { 315,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #315 = ATOM_MIN_S_G
    { 314,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #314 = ATOM_MAX_U_S
    { 313,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #313 = ATOM_MAX_U_G
    { 312,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #312 = ATOM_MAX_S_S
    { 311,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #311 = ATOM_MAX_S_G
    { 310,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #310 = ATOM_EXCH_S
    { 309,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #309 = ATOM_EXCH_G
    { 308,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #308 = ATOM_AND_S
    { 307,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #307 = ATOM_AND_G
    { 306,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #306 = ATOM_ADD_S
    { 305,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #305 = ATOM_ADD_G
    { 304,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #304 = AND_W16
    { 303,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #303 = AND_P
    { 302,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #302 = ANDNI_P
    { 301,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #301 = ANDNI
    { 300,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #300 = ANDN
    { 299,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #299 = ANDI_P
    { 298,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #298 = ANDI
    { 297,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #297 = AND
    { 296,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #296 = ADD_W16
    { 295,	6,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	195,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #295 = ADD_PP
    { 294,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #294 = ADD_P
    { 293,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	187,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #293 = ADDI_W16
    { 292,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #292 = ADDI_PP
    { 291,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #291 = ADDI_P
    { 290,	3,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #290 = ADDI48
    { 289,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #289 = ADDI
    { 288,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #288 = ADD
    { 287,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #287 = ABS
    { 286,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	154,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #286 = PSEUDO_ST_PRED
    { 285,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	170,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #285 = PSEUDO_RET
    { 284,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #284 = PSEUDO_PXOR
    { 283,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #283 = PSEUDO_POR
    { 282,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	166,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #282 = PSEUDO_PMOV
    { 281,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #281 = PSEUDO_PAND
    { 280,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #280 = PSEUDO_PADDI
    { 279,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #279 = PSEUDO_NARROW
    { 278,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	154,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #278 = PSEUDO_LD_PRED
    { 277,	9,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #277 = PSEUDO_CAS_S
    { 276,	9,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #276 = PSEUDO_CAS_G
    { 275,	1,	0,	0,	0,	0,	1,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #275 = PSEUDO_CALL
    { 274,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	142,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #274 = PSEUDO_BRA_PRED
    { 273,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	140,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #273 = PSEUDO_BCAST
    { 272,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	21,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #272 = ADJCALLSTACKUP
    { 271,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	21,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #271 = ADJCALLSTACKDOWN
    { 270,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	136,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #270 = G_UBFX
    { 269,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	136,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #269 = G_SBFX
    { 268,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #268 = G_VECREDUCE_UMIN
    { 267,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #267 = G_VECREDUCE_UMAX
    { 266,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #266 = G_VECREDUCE_SMIN
    { 265,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #265 = G_VECREDUCE_SMAX
    { 264,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #264 = G_VECREDUCE_XOR
    { 263,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #263 = G_VECREDUCE_OR
    { 262,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #262 = G_VECREDUCE_AND
    { 261,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #261 = G_VECREDUCE_MUL
    { 260,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #260 = G_VECREDUCE_ADD
    { 259,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #259 = G_VECREDUCE_FMINIMUM
    { 258,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #258 = G_VECREDUCE_FMAXIMUM
    { 257,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #257 = G_VECREDUCE_FMIN
    { 256,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #256 = G_VECREDUCE_FMAX
    { 255,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #255 = G_VECREDUCE_FMUL
    { 254,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #254 = G_VECREDUCE_FADD
    { 253,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	123,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #253 = G_VECREDUCE_SEQ_FMUL
    { 252,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	123,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #252 = G_VECREDUCE_SEQ_FADD
    { 251,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	53,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #251 = G_BZERO
    { 250,	4,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	132,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #250 = G_MEMSET
    { 249,	4,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	132,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #249 = G_MEMMOVE
    { 248,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	123,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #248 = G_MEMCPY_INLINE
    { 247,	4,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	132,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #247 = G_MEMCPY
    { 246,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	130,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq)|(1ULL<<MCID::Convergent), 0x0ULL },  // Inst #246 = G_WRITE_REGISTER
    { 245,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq)|(1ULL<<MCID::Convergent), 0x0ULL },  // Inst #245 = G_READ_REGISTER
    { 244,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #244 = G_STRICT_FLDEXP
    { 243,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #243 = G_STRICT_FSQRT
    { 242,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	46,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #242 = G_STRICT_FMA
    { 241,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #241 = G_STRICT_FREM
    { 240,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #240 = G_STRICT_FDIV
    { 239,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #239 = G_STRICT_FMUL
    { 238,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #238 = G_STRICT_FSUB
    { 237,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #237 = G_STRICT_FADD
    { 236,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #236 = G_STACKRESTORE
    { 235,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #235 = G_STACKSAVE
    { 234,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	64,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #234 = G_DYN_STACKALLOC
    { 233,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #233 = G_JUMP_TABLE
    { 232,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #232 = G_BLOCK_ADDR
    { 231,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #231 = G_ADDRSPACE_CAST
    { 230,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #230 = G_FNEARBYINT
    { 229,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #229 = G_FRINT
    { 228,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #228 = G_FFLOOR
    { 227,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #227 = G_FSQRT
    { 226,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #226 = G_FSIN
    { 225,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #225 = G_FCOS
    { 224,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #224 = G_FCEIL
    { 223,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #223 = G_BITREVERSE
    { 222,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #222 = G_BSWAP
    { 221,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #221 = G_CTPOP
    { 220,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #220 = G_CTLZ_ZERO_UNDEF
    { 219,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #219 = G_CTLZ
    { 218,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #218 = G_CTTZ_ZERO_UNDEF
    { 217,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #217 = G_CTTZ
    { 216,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	126,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #216 = G_SHUFFLE_VECTOR
    { 215,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	123,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #215 = G_EXTRACT_VECTOR_ELT
    { 214,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	119,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #214 = G_INSERT_VECTOR_ELT
    { 213,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	116,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #213 = G_BRJT
    { 212,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #212 = G_BR
    { 211,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #211 = G_LLROUND
    { 210,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #210 = G_LROUND
    { 209,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #209 = G_ABS
    { 208,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #208 = G_UMAX
    { 207,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #207 = G_UMIN
    { 206,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #206 = G_SMAX
    { 205,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #205 = G_SMIN
    { 204,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #204 = G_PTRMASK
    { 203,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #203 = G_PTR_ADD
    { 202,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #202 = G_RESET_FPMODE
    { 201,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #201 = G_SET_FPMODE
    { 200,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #200 = G_GET_FPMODE
    { 199,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #199 = G_RESET_FPENV
    { 198,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #198 = G_SET_FPENV
    { 197,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #197 = G_GET_FPENV
    { 196,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #196 = G_FMAXIMUM
    { 195,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #195 = G_FMINIMUM
    { 194,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #194 = G_FMAXNUM_IEEE
    { 193,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #193 = G_FMINNUM_IEEE
    { 192,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #192 = G_FMAXNUM
    { 191,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #191 = G_FMINNUM
    { 190,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #190 = G_FCANONICALIZE
    { 189,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	93,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #189 = G_IS_FPCLASS
    { 188,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #188 = G_FCOPYSIGN
    { 187,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #187 = G_FABS
    { 186,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #186 = G_UITOFP
    { 185,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #185 = G_SITOFP
    { 184,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #184 = G_FPTOUI
    { 183,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #183 = G_FPTOSI
    { 182,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #182 = G_FPTRUNC
    { 181,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #181 = G_FPEXT
    { 180,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #180 = G_FNEG
    { 179,	3,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #179 = G_FFREXP
    { 178,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #178 = G_FLDEXP
    { 177,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #177 = G_FLOG10
    { 176,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #176 = G_FLOG2
    { 175,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #175 = G_FLOG
    { 174,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #174 = G_FEXP10
    { 173,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #173 = G_FEXP2
    { 172,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #172 = G_FEXP
    { 171,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #171 = G_FPOWI
    { 170,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #170 = G_FPOW
    { 169,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #169 = G_FREM
    { 168,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #168 = G_FDIV
    { 167,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	46,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #167 = G_FMAD
    { 166,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	46,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #166 = G_FMA
    { 165,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #165 = G_FMUL
    { 164,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #164 = G_FSUB
    { 163,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #163 = G_FADD
    { 162,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #162 = G_UDIVFIXSAT
    { 161,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #161 = G_SDIVFIXSAT
    { 160,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #160 = G_UDIVFIX
    { 159,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #159 = G_SDIVFIX
    { 158,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #158 = G_UMULFIXSAT
    { 157,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #157 = G_SMULFIXSAT
    { 156,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #156 = G_UMULFIX
    { 155,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	112,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #155 = G_SMULFIX
    { 154,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #154 = G_SSHLSAT
    { 153,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #153 = G_USHLSAT
    { 152,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #152 = G_SSUBSAT
    { 151,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #151 = G_USUBSAT
    { 150,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #150 = G_SADDSAT
    { 149,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #149 = G_UADDSAT
    { 148,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #148 = G_SMULH
    { 147,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #147 = G_UMULH
    { 146,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #146 = G_SMULO
    { 145,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #145 = G_UMULO
    { 144,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	107,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #144 = G_SSUBE
    { 143,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #143 = G_SSUBO
    { 142,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	107,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #142 = G_SADDE
    { 141,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #141 = G_SADDO
    { 140,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	107,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #140 = G_USUBE
    { 139,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #139 = G_USUBO
    { 138,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	107,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #138 = G_UADDE
    { 137,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #137 = G_UADDO
    { 136,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #136 = G_SELECT
    { 135,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	103,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #135 = G_FCMP
    { 134,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	103,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #134 = G_ICMP
    { 133,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #133 = G_ROTL
    { 132,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #132 = G_ROTR
    { 131,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	99,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #131 = G_FSHR
    { 130,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	99,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #130 = G_FSHL
    { 129,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #129 = G_ASHR
    { 128,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #128 = G_LSHR
    { 127,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	96,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #127 = G_SHL
    { 126,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #126 = G_ZEXT
    { 125,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	40,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #125 = G_SEXT_INREG
    { 124,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #124 = G_SEXT
    { 123,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	93,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #123 = G_VAARG
    { 122,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #122 = G_VASTART
    { 121,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #121 = G_FCONSTANT
    { 120,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #120 = G_CONSTANT
    { 119,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #119 = G_TRUNC
    { 118,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #118 = G_ANYEXT
    { 117,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq)|(1ULL<<MCID::Convergent), 0x0ULL },  // Inst #117 = G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS
    { 116,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq)|(1ULL<<MCID::Convergent), 0x0ULL },  // Inst #116 = G_INTRINSIC_CONVERGENT
    { 115,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #115 = G_INTRINSIC_W_SIDE_EFFECTS
    { 114,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #114 = G_INTRINSIC
    { 113,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #113 = G_INVOKE_REGION_START
    { 112,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #112 = G_BRINDIRECT
    { 111,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #111 = G_BRCOND
    { 110,	4,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	89,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #110 = G_PREFETCH
    { 109,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	21,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #109 = G_FENCE
    { 108,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #108 = G_ATOMICRMW_UDEC_WRAP
    { 107,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #107 = G_ATOMICRMW_UINC_WRAP
    { 106,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #106 = G_ATOMICRMW_FMIN
    { 105,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #105 = G_ATOMICRMW_FMAX
    { 104,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #104 = G_ATOMICRMW_FSUB
    { 103,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #103 = G_ATOMICRMW_FADD
    { 102,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #102 = G_ATOMICRMW_UMIN
    { 101,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #101 = G_ATOMICRMW_UMAX
    { 100,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #100 = G_ATOMICRMW_MIN
    { 99,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #99 = G_ATOMICRMW_MAX
    { 98,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #98 = G_ATOMICRMW_XOR
    { 97,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #97 = G_ATOMICRMW_OR
    { 96,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #96 = G_ATOMICRMW_NAND
    { 95,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #95 = G_ATOMICRMW_AND
    { 94,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #94 = G_ATOMICRMW_SUB
    { 93,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #93 = G_ATOMICRMW_ADD
    { 92,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	86,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #92 = G_ATOMICRMW_XCHG
    { 91,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	82,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #91 = G_ATOMIC_CMPXCHG
    { 90,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	77,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #90 = G_ATOMIC_CMPXCHG_WITH_SUCCESS
    { 89,	5,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	72,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #89 = G_INDEXED_STORE
    { 88,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #88 = G_STORE
    { 87,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	67,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #87 = G_INDEXED_ZEXTLOAD
    { 86,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	67,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #86 = G_INDEXED_SEXTLOAD
    { 85,	5,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	67,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #85 = G_INDEXED_LOAD
    { 84,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #84 = G_ZEXTLOAD
    { 83,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #83 = G_SEXTLOAD
    { 82,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #82 = G_LOAD
    { 81,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #81 = G_READCYCLECOUNTER
    { 80,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #80 = G_INTRINSIC_ROUNDEVEN
    { 79,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #79 = G_INTRINSIC_LRINT
    { 78,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #78 = G_INTRINSIC_ROUND
    { 77,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #77 = G_INTRINSIC_TRUNC
    { 76,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	64,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #76 = G_INTRINSIC_FPTRUNC_ROUND
    { 75,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #75 = G_CONSTANT_FOLD_BARRIER
    { 74,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	62,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #74 = G_FREEZE
    { 73,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #73 = G_BITCAST
    { 72,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #72 = G_INTTOPTR
    { 71,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #71 = G_PTRTOINT
    { 70,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #70 = G_CONCAT_VECTORS
    { 69,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #69 = G_BUILD_VECTOR_TRUNC
    { 68,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #68 = G_BUILD_VECTOR
    { 67,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #67 = G_MERGE_VALUES
    { 66,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	58,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #66 = G_INSERT
    { 65,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	56,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #65 = G_UNMERGE_VALUES
    { 64,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	53,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #64 = G_EXTRACT
    { 63,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #63 = G_CONSTANT_POOL
    { 62,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #62 = G_GLOBAL_VALUE
    { 61,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	51,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #61 = G_FRAME_INDEX
    { 60,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #60 = G_PHI
    { 59,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	50,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #59 = G_IMPLICIT_DEF
    { 58,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #58 = G_XOR
    { 57,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #57 = G_OR
    { 56,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #56 = G_AND
    { 55,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	46,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #55 = G_UDIVREM
    { 54,	4,	2,	0,	0,	0,	0,	CCVImpOpBase + 0,	46,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #54 = G_SDIVREM
    { 53,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #53 = G_UREM
    { 52,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #52 = G_SREM
    { 51,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #51 = G_UDIV
    { 50,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #50 = G_SDIV
    { 49,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #49 = G_MUL
    { 48,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #48 = G_SUB
    { 47,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	43,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #47 = G_ADD
    { 46,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	40,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #46 = G_ASSERT_ALIGN
    { 45,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	40,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #45 = G_ASSERT_ZEXT
    { 44,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	40,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #44 = G_ASSERT_SEXT
    { 43,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #43 = JUMP_TABLE_DEBUG_INFO
    { 42,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #42 = MEMBARRIER
    { 41,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #41 = ICALL_BRANCH_FUNNEL
    { 40,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	37,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #40 = PATCHABLE_TYPED_EVENT_CALL
    { 39,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	35,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #39 = PATCHABLE_EVENT_CALL
    { 38,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #38 = PATCHABLE_TAIL_CALL
    { 37,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #37 = PATCHABLE_FUNCTION_EXIT
    { 36,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #36 = PATCHABLE_RET
    { 35,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #35 = PATCHABLE_FUNCTION_ENTER
    { 34,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #34 = PATCHABLE_OP
    { 33,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #33 = FAULTING_OP
    { 32,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	33,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #32 = LOCAL_ESCAPE
    { 31,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #31 = STATEPOINT
    { 30,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	30,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #30 = PREALLOCATED_ARG
    { 29,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #29 = PREALLOCATED_SETUP
    { 28,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	29,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #28 = LOAD_STACK_GUARD
    { 27,	6,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	23,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #27 = PATCHPOINT
    { 26,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #26 = FENTRY_CALL
    { 25,	2,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	21,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #25 = STACKMAP
    { 24,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	19,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #24 = ARITH_FENCE
    { 23,	4,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	15,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #23 = PSEUDO_PROBE
    { 22,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #22 = LIFETIME_END
    { 21,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #21 = LIFETIME_START
    { 20,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #20 = BUNDLE
    { 19,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #19 = COPY
    { 18,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #18 = REG_SEQUENCE
    { 17,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #17 = DBG_LABEL
    { 16,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #16 = DBG_PHI
    { 15,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #15 = DBG_INSTR_REF
    { 14,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #14 = DBG_VALUE_LIST
    { 13,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #13 = DBG_VALUE
    { 12,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	2,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #12 = COPY_TO_REGCLASS
    { 11,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	9,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #11 = SUBREG_TO_REG
    { 10,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #10 = IMPLICIT_DEF
    { 9,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	5,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #9 = INSERT_SUBREG
    { 8,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	2,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #8 = EXTRACT_SUBREG
    { 7,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #7 = KILL
    { 6,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::NotDuplicable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #6 = ANNOTATION_LABEL
    { 5,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::NotDuplicable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #5 = GC_LABEL
    { 4,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::NotDuplicable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #4 = EH_LABEL
    { 3,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::NotDuplicable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #3 = CFI_INSTRUCTION
    { 2,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #2 = INLINEASM_BR
    { 1,	0,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #1 = INLINEASM
    { 0,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #0 = PHI
  }, {
    /* 0 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 1 */
    /* 1 */ { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 2 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 5 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 9 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 13 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 15 */ { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 19 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, MCOI_TIED_TO(0) },
    /* 21 */ { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 23 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 29 */ { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 },
    /* 30 */ { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 33 */ { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 35 */ { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 37 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 40 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 43 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 46 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 50 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 51 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 53 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 56 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 58 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 62 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 64 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 67 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 72 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 77 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 82 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 86 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 89 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 93 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 96 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 99 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 103 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 107 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 112 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 116 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 119 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 },
    /* 123 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 },
    /* 126 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 130 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 132 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 136 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 140 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) },
    /* 142 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 145 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 154 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 157 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 159 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 163 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 166 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 170 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 171 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 175 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 178 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 182 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 187 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 190 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 195 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 201 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 205 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 211 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 214 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 217 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 219 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 221 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 230 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 234 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 238 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 242 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 246 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 250 */ { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 254 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 258 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 261 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 264 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 268 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 272 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 277 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 282 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 287 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 292 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 297 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 302 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 305 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 308 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 311 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 313 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 319 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 323 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 326 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 328 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 333 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 337 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 342 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 346 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 349 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
  }, {
    /* 0 */
    /* 0 */ CCV::R14,
  }
};


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char CCVInstrNameData[] = {
  /* 0 */ "G_FLOG10\0"
  /* 9 */ "G_FEXP10\0"
  /* 18 */ "FFMA_F0\0"
  /* 26 */ "FFMA_ACC_F0\0"
  /* 38 */ "FNEG_F0\0"
  /* 46 */ "FABS_F0\0"
  /* 54 */ "CVT_D0_S0_R0\0"
  /* 67 */ "CVT_D1_S0_R0\0"
  /* 80 */ "CVT_D2_S0_R0\0"
  /* 93 */ "CVT_D3_S0_R0\0"
  /* 106 */ "CVT_D0_S1_R0\0"
  /* 119 */ "CVT_D1_S1_R0\0"
  /* 132 */ "CVT_D2_S1_R0\0"
  /* 145 */ "CVT_D3_S1_R0\0"
  /* 158 */ "CVT_D1_S2_R0\0"
  /* 171 */ "CVT_D3_S2_R0\0"
  /* 184 */ "CVT_D1_S3_R0\0"
  /* 197 */ "CVT_D2_S3_R0\0"
  /* 210 */ "CVT_D3_S3_R0\0"
  /* 223 */ "FFMA_F1\0"
  /* 231 */ "FSUB_F1\0"
  /* 239 */ "FFMA_ACC_F1\0"
  /* 251 */ "FADD_F1\0"
  /* 259 */ "SETP_GE_F1\0"
  /* 270 */ "SETP_LE_F1\0"
  /* 281 */ "SETP_NE_F1\0"
  /* 292 */ "FNEG_F1\0"
  /* 300 */ "FMUL_F1\0"
  /* 308 */ "FMIN_F1\0"
  /* 316 */ "SETP_EQ_F1\0"
  /* 327 */ "FABS_F1\0"
  /* 335 */ "SETP_GT_F1\0"
  /* 346 */ "SETP_LT_F1\0"
  /* 357 */ "FMAX_F1\0"
  /* 365 */ "CVT_D0_S0_R1\0"
  /* 378 */ "CVT_D1_S0_R1\0"
  /* 391 */ "CVT_D0_S1_R1\0"
  /* 404 */ "CVT_D1_S1_R1\0"
  /* 417 */ "CVT_D2_S1_R1\0"
  /* 430 */ "CVT_D3_S1_R1\0"
  /* 443 */ "CVT_D0_S2_R1\0"
  /* 456 */ "CVT_D1_S2_R1\0"
  /* 469 */ "CVT_D0_S3_R1\0"
  /* 482 */ "CVT_D1_S3_R1\0"
  /* 495 */ "CVT_S32_F32\0"
  /* 507 */ "CVT_U32_F32\0"
  /* 519 */ "LG2_F32\0"
  /* 527 */ "EX2_F32\0"
  /* 535 */ "SIN_F32\0"
  /* 543 */ "RCP_F32\0"
  /* 551 */ "COS_F32\0"
  /* 559 */ "RSQRT_F32\0"
  /* 569 */ "CVT_F32_S32\0"
  /* 581 */ "CVT_F32_U32\0"
  /* 593 */ "RCP_U32\0"
  /* 601 */ "CVT_D0_S0_R0_W4_32\0"
  /* 620 */ "CVT_D0_S0_R0_W16_32\0"
  /* 640 */ "CVT_D0_S0_R0_W8_32\0"
  /* 659 */ "CVT_D1_S0_R0_W8_32\0"
  /* 678 */ "G_FLOG2\0"
  /* 686 */ "DP4_E5M2\0"
  /* 695 */ "G_FEXP2\0"
  /* 703 */ "CVT_D0_S0_R2\0"
  /* 716 */ "CVT_D1_S0_R2\0"
  /* 729 */ "CVT_D2_S0_R2\0"
  /* 742 */ "CVT_D3_S0_R2\0"
  /* 755 */ "CVT_D0_S1_R2\0"
  /* 768 */ "CVT_D1_S1_R2\0"
  /* 781 */ "CVT_D2_S1_R2\0"
  /* 794 */ "CVT_D3_S1_R2\0"
  /* 807 */ "CVT_D0_S2_R2\0"
  /* 820 */ "CVT_D1_S2_R2\0"
  /* 833 */ "CVT_D0_S3_R2\0"
  /* 846 */ "CVT_D1_S3_R2\0"
  /* 859 */ "DP4_E4M3\0"
  /* 868 */ "CVT_D0_S0_R3\0"
  /* 881 */ "CVT_D1_S0_R3\0"
  /* 894 */ "CVT_D2_S0_R3\0"
  /* 907 */ "CVT_D3_S0_R3\0"
  /* 920 */ "CVT_D0_S1_R3\0"
  /* 933 */ "CVT_D1_S1_R3\0"
  /* 946 */ "CVT_D2_S1_R3\0"
  /* 959 */ "CVT_D3_S1_R3\0"
  /* 972 */ "CVT_D0_S2_R3\0"
  /* 985 */ "CVT_D1_S2_R3\0"
  /* 998 */ "CVT_D0_S3_R3\0"
  /* 1011 */ "CVT_D1_S3_R3\0"
  /* 1024 */ "CVT_D0_S0_R0_W32_4\0"
  /* 1043 */ "DP2_BF16\0"
  /* 1052 */ "DP2_F16\0"
  /* 1060 */ "SUB_W16\0"
  /* 1068 */ "ADD_W16\0"
  /* 1076 */ "LD_SHARED_W16\0"
  /* 1090 */ "ST_SHARED_W16\0"
  /* 1104 */ "AND_W16\0"
  /* 1112 */ "ADDI_W16\0"
  /* 1121 */ "LD_GLOBAL_W16\0"
  /* 1135 */ "ST_GLOBAL_W16\0"
  /* 1149 */ "XOR_W16\0"
  /* 1157 */ "MIN_S_W16\0"
  /* 1167 */ "MAX_S_W16\0"
  /* 1177 */ "LD_GLOBAL_SLOT_W16\0"
  /* 1196 */ "ST_GLOBAL_SLOT_W16\0"
  /* 1215 */ "LD_GLOBAL_IDX_W16\0"
  /* 1233 */ "ST_GLOBAL_IDX_W16\0"
  /* 1251 */ "CVT_D0_S0_R0_W32_16\0"
  /* 1271 */ "ADDI48\0"
  /* 1278 */ "MOVI48\0"
  /* 1285 */ "FSUB_F1_W8\0"
  /* 1296 */ "FADD_F1_W8\0"
  /* 1307 */ "FMUL_F1_W8\0"
  /* 1318 */ "FSUB_W8\0"
  /* 1326 */ "FADD_W8\0"
  /* 1334 */ "LD_SHARED_W8\0"
  /* 1347 */ "ST_SHARED_W8\0"
  /* 1360 */ "LD_GLOBAL_W8\0"
  /* 1373 */ "ST_GLOBAL_W8\0"
  /* 1386 */ "FMUL_W8\0"
  /* 1394 */ "LD_GLOBAL_SLOT_W8\0"
  /* 1412 */ "ST_GLOBAL_SLOT_W8\0"
  /* 1430 */ "LD_GLOBAL_IDX_W8\0"
  /* 1447 */ "ST_GLOBAL_IDX_W8\0"
  /* 1464 */ "CVT_D0_S0_R0_W32_8\0"
  /* 1483 */ "CVT_D0_S1_R0_W32_8\0"
  /* 1502 */ "CVT_D0_S0_R0_W16_8\0"
  /* 1521 */ "CVT_D0_S1_R0_W16_8\0"
  /* 1540 */ "G_FMA\0"
  /* 1546 */ "G_STRICT_FMA\0"
  /* 1559 */ "C_BRA\0"
  /* 1565 */ "C_SRA\0"
  /* 1571 */ "G_FSUB\0"
  /* 1578 */ "G_STRICT_FSUB\0"
  /* 1592 */ "G_ATOMICRMW_FSUB\0"
  /* 1609 */ "C_SUB\0"
  /* 1615 */ "G_SUB\0"
  /* 1621 */ "G_ATOMICRMW_SUB\0"
  /* 1637 */ "DP4_ACC\0"
  /* 1645 */ "MAD_ACC\0"
  /* 1653 */ "G_INTRINSIC\0"
  /* 1665 */ "G_FPTRUNC\0"
  /* 1675 */ "G_INTRINSIC_TRUNC\0"
  /* 1693 */ "G_TRUNC\0"
  /* 1701 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 1722 */ "G_DYN_STACKALLOC\0"
  /* 1739 */ "POPC\0"
  /* 1744 */ "G_FMAD\0"
  /* 1751 */ "G_INDEXED_SEXTLOAD\0"
  /* 1770 */ "G_SEXTLOAD\0"
  /* 1781 */ "G_INDEXED_ZEXTLOAD\0"
  /* 1800 */ "G_ZEXTLOAD\0"
  /* 1811 */ "G_INDEXED_LOAD\0"
  /* 1826 */ "G_LOAD\0"
  /* 1833 */ "C_FADD\0"
  /* 1840 */ "G_VECREDUCE_FADD\0"
  /* 1857 */ "G_FADD\0"
  /* 1864 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 1885 */ "G_STRICT_FADD\0"
  /* 1899 */ "G_ATOMICRMW_FADD\0"
  /* 1916 */ "C_ADD\0"
  /* 1922 */ "G_VECREDUCE_ADD\0"
  /* 1938 */ "G_ADD\0"
  /* 1944 */ "G_PTR_ADD\0"
  /* 1954 */ "G_ATOMICRMW_ADD\0"
  /* 1970 */ "LD_SHARED\0"
  /* 1980 */ "ST_SHARED\0"
  /* 1990 */ "PSEUDO_BRA_PRED\0"
  /* 2006 */ "PSEUDO_LD_PRED\0"
  /* 2021 */ "PSEUDO_ST_PRED\0"
  /* 2036 */ "G_ATOMICRMW_NAND\0"
  /* 2053 */ "PSEUDO_PAND\0"
  /* 2065 */ "C_AND\0"
  /* 2071 */ "G_VECREDUCE_AND\0"
  /* 2087 */ "G_AND\0"
  /* 2093 */ "G_ATOMICRMW_AND\0"
  /* 2109 */ "LIFETIME_END\0"
  /* 2122 */ "G_BRCOND\0"
  /* 2131 */ "G_LLROUND\0"
  /* 2141 */ "G_LROUND\0"
  /* 2150 */ "G_INTRINSIC_ROUND\0"
  /* 2168 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 2194 */ "LOAD_STACK_GUARD\0"
  /* 2211 */ "SRD\0"
  /* 2215 */ "PSEUDO_PROBE\0"
  /* 2228 */ "G_SSUBE\0"
  /* 2236 */ "G_USUBE\0"
  /* 2244 */ "C_FENCE\0"
  /* 2252 */ "G_FENCE\0"
  /* 2260 */ "ARITH_FENCE\0"
  /* 2272 */ "REG_SEQUENCE\0"
  /* 2285 */ "G_SADDE\0"
  /* 2293 */ "G_UADDE\0"
  /* 2301 */ "G_GET_FPMODE\0"
  /* 2314 */ "G_RESET_FPMODE\0"
  /* 2329 */ "G_SET_FPMODE\0"
  /* 2342 */ "G_FMINNUM_IEEE\0"
  /* 2357 */ "G_FMAXNUM_IEEE\0"
  /* 2372 */ "SETP_GE\0"
  /* 2380 */ "G_JUMP_TABLE\0"
  /* 2393 */ "BUNDLE\0"
  /* 2400 */ "SETP_LE\0"
  /* 2408 */ "G_MEMCPY_INLINE\0"
  /* 2424 */ "SETP_NE\0"
  /* 2432 */ "LOCAL_ESCAPE\0"
  /* 2445 */ "G_STACKRESTORE\0"
  /* 2460 */ "G_INDEXED_STORE\0"
  /* 2476 */ "G_STORE\0"
  /* 2484 */ "BAR_WAIT_PHASE\0"
  /* 2499 */ "G_BITREVERSE\0"
  /* 2512 */ "DBG_VALUE\0"
  /* 2522 */ "G_GLOBAL_VALUE\0"
  /* 2537 */ "G_STACKSAVE\0"
  /* 2549 */ "C_BAR_ARRIVE\0"
  /* 2562 */ "G_MEMMOVE\0"
  /* 2572 */ "G_FREEZE\0"
  /* 2581 */ "G_FCANONICALIZE\0"
  /* 2597 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 2615 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 2633 */ "G_IMPLICIT_DEF\0"
  /* 2648 */ "DBG_INSTR_REF\0"
  /* 2662 */ "SETP_GE_F\0"
  /* 2672 */ "SETP_LE_F\0"
  /* 2682 */ "SETP_NE_F\0"
  /* 2692 */ "SETP_EQ_F\0"
  /* 2702 */ "SETP_GT_F\0"
  /* 2712 */ "SETP_LT_F\0"
  /* 2722 */ "G_FNEG\0"
  /* 2729 */ "C_NEG\0"
  /* 2735 */ "EXTRACT_SUBREG\0"
  /* 2750 */ "INSERT_SUBREG\0"
  /* 2764 */ "G_SEXT_INREG\0"
  /* 2777 */ "SUBREG_TO_REG\0"
  /* 2791 */ "G_ATOMIC_CMPXCHG\0"
  /* 2808 */ "G_ATOMICRMW_XCHG\0"
  /* 2825 */ "G_FLOG\0"
  /* 2832 */ "G_VAARG\0"
  /* 2840 */ "PREALLOCATED_ARG\0"
  /* 2857 */ "ATOM_ADD_G\0"
  /* 2868 */ "LD_PRED_G\0"
  /* 2878 */ "ST_PRED_G\0"
  /* 2888 */ "ATOM_AND_G\0"
  /* 2899 */ "ATOM_EXCH_G\0"
  /* 2911 */ "ATOM_XOR_G\0"
  /* 2922 */ "ATOM_OR_G\0"
  /* 2932 */ "PSEUDO_CAS_G\0"
  /* 2945 */ "ATOM_MIN_S_G\0"
  /* 2958 */ "ATOM_MAX_S_G\0"
  /* 2971 */ "ATOM_MIN_U_G\0"
  /* 2984 */ "ATOM_MAX_U_G\0"
  /* 2997 */ "G_PREFETCH\0"
  /* 3008 */ "G_SMULH\0"
  /* 3016 */ "G_UMULH\0"
  /* 3024 */ "C_CHWIDTH\0"
  /* 3034 */ "C_SRAI\0"
  /* 3041 */ "C_SUBI\0"
  /* 3048 */ "PSEUDO_PADDI\0"
  /* 3061 */ "C_ADDI\0"
  /* 3068 */ "C_ANDI\0"
  /* 3075 */ "DBG_PHI\0"
  /* 3083 */ "UNPACKI\0"
  /* 3091 */ "C_SHLI\0"
  /* 3098 */ "MULI\0"
  /* 3103 */ "ANDNI\0"
  /* 3109 */ "SETP_GE_NPI\0"
  /* 3121 */ "SETP_LE_NPI\0"
  /* 3133 */ "SETP_NE_NPI\0"
  /* 3145 */ "SETP_GE_F_NPI\0"
  /* 3159 */ "SETP_LE_F_NPI\0"
  /* 3173 */ "SETP_NE_F_NPI\0"
  /* 3187 */ "SETP_EQ_F_NPI\0"
  /* 3201 */ "SETP_GT_F_NPI\0"
  /* 3215 */ "SETP_LT_F_NPI\0"
  /* 3229 */ "SETP_EQ_NPI\0"
  /* 3241 */ "SETP_GT_NPI\0"
  /* 3253 */ "SETP_LT_NPI\0"
  /* 3265 */ "SETP_GE_U_NPI\0"
  /* 3279 */ "SETP_LE_U_NPI\0"
  /* 3293 */ "SETP_GT_U_NPI\0"
  /* 3307 */ "SETP_LT_U_NPI\0"
  /* 3321 */ "C_SHRI\0"
  /* 3328 */ "C_XORI\0"
  /* 3335 */ "C_ORI\0"
  /* 3341 */ "G_FPTOSI\0"
  /* 3350 */ "CHWIDTH_MULTI\0"
  /* 3364 */ "G_FPTOUI\0"
  /* 3373 */ "MOVI\0"
  /* 3378 */ "G_FPOWI\0"
  /* 3386 */ "SETP_GE_I\0"
  /* 3396 */ "SETP_LE_I\0"
  /* 3406 */ "SETP_NE_I\0"
  /* 3416 */ "SETP_GE_F_I\0"
  /* 3428 */ "SETP_LE_F_I\0"
  /* 3440 */ "SETP_NE_F_I\0"
  /* 3452 */ "SETP_EQ_F_I\0"
  /* 3464 */ "SETP_GT_F_I\0"
  /* 3476 */ "SETP_LT_F_I\0"
  /* 3488 */ "SETP_EQ_I\0"
  /* 3498 */ "SETP_GT_I\0"
  /* 3508 */ "SETP_LT_I\0"
  /* 3518 */ "SETP_GE_U_I\0"
  /* 3530 */ "SETP_LE_U_I\0"
  /* 3542 */ "SETP_GT_U_I\0"
  /* 3554 */ "SETP_LT_U_I\0"
  /* 3566 */ "G_PTRMASK\0"
  /* 3576 */ "C_LD_GLOBAL\0"
  /* 3588 */ "C_ST_GLOBAL\0"
  /* 3600 */ "LD_PRED_LOCAL\0"
  /* 3614 */ "ST_PRED_LOCAL\0"
  /* 3628 */ "LD_LOCAL\0"
  /* 3637 */ "ST_LOCAL\0"
  /* 3646 */ "GC_LABEL\0"
  /* 3655 */ "DBG_LABEL\0"
  /* 3665 */ "EH_LABEL\0"
  /* 3674 */ "ANNOTATION_LABEL\0"
  /* 3691 */ "ICALL_BRANCH_FUNNEL\0"
  /* 3711 */ "SEL\0"
  /* 3715 */ "G_FSHL\0"
  /* 3722 */ "C_SHL\0"
  /* 3728 */ "G_SHL\0"
  /* 3734 */ "G_FCEIL\0"
  /* 3742 */ "PATCHABLE_TAIL_CALL\0"
  /* 3762 */ "PSEUDO_CALL\0"
  /* 3774 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 3801 */ "PATCHABLE_EVENT_CALL\0"
  /* 3822 */ "FENTRY_CALL\0"
  /* 3834 */ "KILL\0"
  /* 3839 */ "G_CONSTANT_POOL\0"
  /* 3855 */ "G_ROTL\0"
  /* 3862 */ "C_FMUL\0"
  /* 3869 */ "G_VECREDUCE_FMUL\0"
  /* 3886 */ "G_FMUL\0"
  /* 3893 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 3914 */ "G_STRICT_FMUL\0"
  /* 3928 */ "G_VECREDUCE_MUL\0"
  /* 3944 */ "G_MUL\0"
  /* 3950 */ "G_FREM\0"
  /* 3957 */ "G_STRICT_FREM\0"
  /* 3971 */ "G_SREM\0"
  /* 3978 */ "G_UREM\0"
  /* 3985 */ "G_SDIVREM\0"
  /* 3995 */ "G_UDIVREM\0"
  /* 4005 */ "PMOV_IMM\0"
  /* 4014 */ "INLINEASM\0"
  /* 4024 */ "G_VECREDUCE_FMINIMUM\0"
  /* 4045 */ "G_FMINIMUM\0"
  /* 4056 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 4077 */ "G_FMAXIMUM\0"
  /* 4088 */ "G_FMINNUM\0"
  /* 4098 */ "G_FMAXNUM\0"
  /* 4108 */ "C_ANDN\0"
  /* 4115 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 4137 */ "G_ASSERT_ALIGN\0"
  /* 4152 */ "G_FCOPYSIGN\0"
  /* 4164 */ "C_FMIN\0"
  /* 4171 */ "G_VECREDUCE_FMIN\0"
  /* 4188 */ "G_ATOMICRMW_FMIN\0"
  /* 4205 */ "G_VECREDUCE_SMIN\0"
  /* 4222 */ "G_SMIN\0"
  /* 4229 */ "G_VECREDUCE_UMIN\0"
  /* 4246 */ "G_UMIN\0"
  /* 4253 */ "G_ATOMICRMW_UMIN\0"
  /* 4270 */ "G_ATOMICRMW_MIN\0"
  /* 4286 */ "G_FSIN\0"
  /* 4293 */ "CFI_INSTRUCTION\0"
  /* 4309 */ "ADJCALLSTACKDOWN\0"
  /* 4326 */ "G_SSUBO\0"
  /* 4334 */ "G_USUBO\0"
  /* 4342 */ "G_SADDO\0"
  /* 4350 */ "G_UADDO\0"
  /* 4358 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 4380 */ "MADLO\0"
  /* 4386 */ "G_SMULO\0"
  /* 4394 */ "G_UMULO\0"
  /* 4402 */ "C_MUL_LO\0"
  /* 4411 */ "G_BZERO\0"
  /* 4419 */ "STACKMAP\0"
  /* 4428 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 4450 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 4472 */ "G_BSWAP\0"
  /* 4480 */ "G_SITOFP\0"
  /* 4489 */ "G_UITOFP\0"
  /* 4498 */ "G_FCMP\0"
  /* 4505 */ "G_ICMP\0"
  /* 4512 */ "SETP_GE_F1_NP\0"
  /* 4526 */ "SETP_LE_F1_NP\0"
  /* 4540 */ "SETP_NE_F1_NP\0"
  /* 4554 */ "SETP_EQ_F1_NP\0"
  /* 4568 */ "SETP_GT_F1_NP\0"
  /* 4582 */ "SETP_LT_F1_NP\0"
  /* 4596 */ "SETP_GE_NP\0"
  /* 4607 */ "SETP_LE_NP\0"
  /* 4618 */ "SETP_NE_NP\0"
  /* 4629 */ "SETP_GE_F_NP\0"
  /* 4642 */ "SETP_LE_F_NP\0"
  /* 4655 */ "SETP_NE_F_NP\0"
  /* 4668 */ "SETP_EQ_F_NP\0"
  /* 4681 */ "SETP_GT_F_NP\0"
  /* 4694 */ "SETP_LT_F_NP\0"
  /* 4707 */ "SETP_EQ_NP\0"
  /* 4718 */ "SETP_GT_NP\0"
  /* 4729 */ "SETP_LT_NP\0"
  /* 4740 */ "SETP_GE_U_NP\0"
  /* 4753 */ "SETP_LE_U_NP\0"
  /* 4766 */ "SETP_GT_U_NP\0"
  /* 4779 */ "SETP_LT_U_NP\0"
  /* 4792 */ "G_CTPOP\0"
  /* 4800 */ "PATCHABLE_OP\0"
  /* 4813 */ "FAULTING_OP\0"
  /* 4825 */ "ADD_PP\0"
  /* 4832 */ "ADDI_PP\0"
  /* 4840 */ "ADJCALLSTACKUP\0"
  /* 4855 */ "PREALLOCATED_SETUP\0"
  /* 4874 */ "G_FLDEXP\0"
  /* 4883 */ "G_STRICT_FLDEXP\0"
  /* 4899 */ "G_FEXP\0"
  /* 4906 */ "G_FFREXP\0"
  /* 4915 */ "CVT_D0_S0_R0_P\0"
  /* 4930 */ "CVT_D1_S0_R0_P\0"
  /* 4945 */ "CVT_D2_S0_R0_P\0"
  /* 4960 */ "CVT_D3_S0_R0_P\0"
  /* 4975 */ "CVT_D0_S1_R0_P\0"
  /* 4990 */ "CVT_D1_S1_R0_P\0"
  /* 5005 */ "CVT_D2_S1_R0_P\0"
  /* 5020 */ "CVT_D3_S1_R0_P\0"
  /* 5035 */ "CVT_D1_S2_R0_P\0"
  /* 5050 */ "CVT_D3_S2_R0_P\0"
  /* 5065 */ "CVT_D1_S3_R0_P\0"
  /* 5080 */ "CVT_D2_S3_R0_P\0"
  /* 5095 */ "CVT_D3_S3_R0_P\0"
  /* 5110 */ "CVT_D0_S0_R1_P\0"
  /* 5125 */ "CVT_D1_S0_R1_P\0"
  /* 5140 */ "CVT_D0_S1_R1_P\0"
  /* 5155 */ "CVT_D1_S1_R1_P\0"
  /* 5170 */ "CVT_D2_S1_R1_P\0"
  /* 5185 */ "CVT_D3_S1_R1_P\0"
  /* 5200 */ "CVT_D0_S2_R1_P\0"
  /* 5215 */ "CVT_D1_S2_R1_P\0"
  /* 5230 */ "CVT_D0_S3_R1_P\0"
  /* 5245 */ "CVT_D1_S3_R1_P\0"
  /* 5260 */ "CVT_S32_F32_P\0"
  /* 5274 */ "CVT_U32_F32_P\0"
  /* 5288 */ "RCP_F32_P\0"
  /* 5298 */ "CVT_F32_S32_P\0"
  /* 5312 */ "CVT_F32_U32_P\0"
  /* 5326 */ "CVT_D0_S0_R2_P\0"
  /* 5341 */ "CVT_D1_S0_R2_P\0"
  /* 5356 */ "CVT_D2_S0_R2_P\0"
  /* 5371 */ "CVT_D3_S0_R2_P\0"
  /* 5386 */ "CVT_D0_S1_R2_P\0"
  /* 5401 */ "CVT_D1_S1_R2_P\0"
  /* 5416 */ "CVT_D2_S1_R2_P\0"
  /* 5431 */ "CVT_D3_S1_R2_P\0"
  /* 5446 */ "CVT_D0_S2_R2_P\0"
  /* 5461 */ "CVT_D1_S2_R2_P\0"
  /* 5476 */ "CVT_D0_S3_R2_P\0"
  /* 5491 */ "CVT_D1_S3_R2_P\0"
  /* 5506 */ "CVT_D0_S0_R3_P\0"
  /* 5521 */ "CVT_D1_S0_R3_P\0"
  /* 5536 */ "CVT_D2_S0_R3_P\0"
  /* 5551 */ "CVT_D3_S0_R3_P\0"
  /* 5566 */ "CVT_D0_S1_R3_P\0"
  /* 5581 */ "CVT_D1_S1_R3_P\0"
  /* 5596 */ "CVT_D2_S1_R3_P\0"
  /* 5611 */ "CVT_D3_S1_R3_P\0"
  /* 5626 */ "CVT_D0_S2_R3_P\0"
  /* 5641 */ "CVT_D1_S2_R3_P\0"
  /* 5656 */ "CVT_D0_S3_R3_P\0"
  /* 5671 */ "CVT_D1_S3_R3_P\0"
  /* 5686 */ "SRA_P\0"
  /* 5692 */ "FSUB_P\0"
  /* 5699 */ "FADD_P\0"
  /* 5706 */ "AND_P\0"
  /* 5712 */ "SRAI_P\0"
  /* 5719 */ "SUBI_P\0"
  /* 5726 */ "ADDI_P\0"
  /* 5733 */ "ANDI_P\0"
  /* 5740 */ "SHLI_P\0"
  /* 5747 */ "MULI_P\0"
  /* 5754 */ "ANDNI_P\0"
  /* 5762 */ "SHRI_P\0"
  /* 5769 */ "XORI_P\0"
  /* 5776 */ "LD_GLOBAL_P\0"
  /* 5788 */ "SHL_P\0"
  /* 5794 */ "FMUL_P\0"
  /* 5801 */ "MADLO_P\0"
  /* 5809 */ "SHR_P\0"
  /* 5815 */ "XOR_P\0"
  /* 5821 */ "MUL_HI_S_P\0"
  /* 5832 */ "MIN_S_P\0"
  /* 5840 */ "MAX_S_P\0"
  /* 5848 */ "MUL_HI_U_P\0"
  /* 5859 */ "MIN_U_P\0"
  /* 5867 */ "MAX_U_P\0"
  /* 5875 */ "MOV_P\0"
  /* 5881 */ "SETP_EQ\0"
  /* 5889 */ "G_BR\0"
  /* 5894 */ "INLINEASM_BR\0"
  /* 5907 */ "G_BLOCK_ADDR\0"
  /* 5920 */ "MEMBARRIER\0"
  /* 5931 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 5955 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 5980 */ "G_READCYCLECOUNTER\0"
  /* 5999 */ "G_READ_REGISTER\0"
  /* 6015 */ "G_WRITE_REGISTER\0"
  /* 6032 */ "G_ASHR\0"
  /* 6039 */ "G_FSHR\0"
  /* 6046 */ "G_LSHR\0"
  /* 6053 */ "C_SHR\0"
  /* 6059 */ "G_FFLOOR\0"
  /* 6068 */ "PSEUDO_POR\0"
  /* 6079 */ "G_BUILD_VECTOR\0"
  /* 6094 */ "G_SHUFFLE_VECTOR\0"
  /* 6111 */ "PSEUDO_PXOR\0"
  /* 6123 */ "C_XOR\0"
  /* 6129 */ "G_VECREDUCE_XOR\0"
  /* 6145 */ "G_XOR\0"
  /* 6151 */ "G_ATOMICRMW_XOR\0"
  /* 6167 */ "C_OR\0"
  /* 6172 */ "G_VECREDUCE_OR\0"
  /* 6187 */ "G_OR\0"
  /* 6192 */ "G_ATOMICRMW_OR\0"
  /* 6207 */ "G_ROTR\0"
  /* 6214 */ "G_INTTOPTR\0"
  /* 6225 */ "G_FABS\0"
  /* 6232 */ "C_ABS\0"
  /* 6238 */ "G_ABS\0"
  /* 6244 */ "G_UNMERGE_VALUES\0"
  /* 6261 */ "G_MERGE_VALUES\0"
  /* 6276 */ "G_FCOS\0"
  /* 6283 */ "G_CONCAT_VECTORS\0"
  /* 6300 */ "COPY_TO_REGCLASS\0"
  /* 6317 */ "G_IS_FPCLASS\0"
  /* 6330 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 6360 */ "DP4_SS\0"
  /* 6367 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 6394 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 6432 */ "ATOM_ADD_S\0"
  /* 6443 */ "LD_PRED_S\0"
  /* 6453 */ "ST_PRED_S\0"
  /* 6463 */ "ATOM_AND_S\0"
  /* 6474 */ "ATOM_EXCH_S\0"
  /* 6486 */ "MUL_HI_S\0"
  /* 6495 */ "C_MIN_S\0"
  /* 6503 */ "ATOM_XOR_S\0"
  /* 6514 */ "ATOM_OR_S\0"
  /* 6524 */ "PSEUDO_CAS_S\0"
  /* 6537 */ "ATOM_MIN_S_S\0"
  /* 6550 */ "ATOM_MAX_S_S\0"
  /* 6563 */ "ATOM_MIN_U_S\0"
  /* 6576 */ "ATOM_MAX_U_S\0"
  /* 6589 */ "C_MAX_S\0"
  /* 6597 */ "G_SSUBSAT\0"
  /* 6607 */ "G_USUBSAT\0"
  /* 6617 */ "G_SADDSAT\0"
  /* 6627 */ "G_UADDSAT\0"
  /* 6637 */ "G_SSHLSAT\0"
  /* 6647 */ "G_USHLSAT\0"
  /* 6657 */ "G_SMULFIXSAT\0"
  /* 6670 */ "G_UMULFIXSAT\0"
  /* 6683 */ "G_SDIVFIXSAT\0"
  /* 6696 */ "G_UDIVFIXSAT\0"
  /* 6709 */ "G_EXTRACT\0"
  /* 6719 */ "G_SELECT\0"
  /* 6728 */ "G_BRINDIRECT\0"
  /* 6741 */ "C_RET\0"
  /* 6747 */ "PATCHABLE_RET\0"
  /* 6761 */ "PSEUDO_RET\0"
  /* 6772 */ "G_MEMSET\0"
  /* 6781 */ "SETP_GT\0"
  /* 6789 */ "C_BAR_WAIT\0"
  /* 6800 */ "BAR_INIT\0"
  /* 6809 */ "C_EXIT\0"
  /* 6816 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 6840 */ "G_BRJT\0"
  /* 6847 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 6868 */ "G_INSERT_VECTOR_ELT\0"
  /* 6888 */ "SETP_LT\0"
  /* 6896 */ "G_FCONSTANT\0"
  /* 6908 */ "G_CONSTANT\0"
  /* 6919 */ "G_INTRINSIC_CONVERGENT\0"
  /* 6942 */ "STATEPOINT\0"
  /* 6953 */ "PATCHPOINT\0"
  /* 6964 */ "G_PTRTOINT\0"
  /* 6975 */ "G_FRINT\0"
  /* 6983 */ "G_INTRINSIC_LRINT\0"
  /* 7001 */ "G_FNEARBYINT\0"
  /* 7014 */ "UNBALLOT\0"
  /* 7023 */ "LD_GLOBAL_SLOT\0"
  /* 7038 */ "ST_GLOBAL_SLOT\0"
  /* 7053 */ "C_NOT\0"
  /* 7059 */ "G_VASTART\0"
  /* 7069 */ "LIFETIME_START\0"
  /* 7084 */ "G_INVOKE_REGION_START\0"
  /* 7106 */ "G_INSERT\0"
  /* 7115 */ "G_FSQRT\0"
  /* 7123 */ "G_STRICT_FSQRT\0"
  /* 7138 */ "PSEUDO_BCAST\0"
  /* 7151 */ "G_BITCAST\0"
  /* 7161 */ "G_ADDRSPACE_CAST\0"
  /* 7178 */ "DBG_VALUE_LIST\0"
  /* 7193 */ "G_FPEXT\0"
  /* 7201 */ "G_SEXT\0"
  /* 7208 */ "G_ASSERT_SEXT\0"
  /* 7222 */ "CVT_SEXT\0"
  /* 7231 */ "G_ANYEXT\0"
  /* 7240 */ "G_ZEXT\0"
  /* 7247 */ "G_ASSERT_ZEXT\0"
  /* 7261 */ "SETP_GE_U\0"
  /* 7271 */ "SETP_LE_U\0"
  /* 7281 */ "MUL_HI_U\0"
  /* 7290 */ "C_MIN_U\0"
  /* 7298 */ "SETP_GT_U\0"
  /* 7308 */ "SETP_LT_U\0"
  /* 7318 */ "C_MAX_U\0"
  /* 7326 */ "BREV\0"
  /* 7331 */ "G_FDIV\0"
  /* 7338 */ "G_STRICT_FDIV\0"
  /* 7352 */ "G_SDIV\0"
  /* 7359 */ "G_UDIV\0"
  /* 7366 */ "G_GET_FPENV\0"
  /* 7378 */ "G_RESET_FPENV\0"
  /* 7392 */ "G_SET_FPENV\0"
  /* 7404 */ "C_RECONV\0"
  /* 7413 */ "PSEUDO_PMOV\0"
  /* 7425 */ "C_MOV\0"
  /* 7431 */ "G_FPOW\0"
  /* 7438 */ "PSEUDO_NARROW\0"
  /* 7452 */ "C_FMAX\0"
  /* 7459 */ "G_VECREDUCE_FMAX\0"
  /* 7476 */ "G_ATOMICRMW_FMAX\0"
  /* 7493 */ "G_VECREDUCE_SMAX\0"
  /* 7510 */ "G_SMAX\0"
  /* 7517 */ "G_VECREDUCE_UMAX\0"
  /* 7534 */ "G_UMAX\0"
  /* 7541 */ "G_ATOMICRMW_UMAX\0"
  /* 7558 */ "G_ATOMICRMW_MAX\0"
  /* 7574 */ "LD_SHARED_IDX\0"
  /* 7588 */ "ST_SHARED_IDX\0"
  /* 7602 */ "LD_GLOBAL_IDX\0"
  /* 7616 */ "ST_GLOBAL_IDX\0"
  /* 7630 */ "SHFL_IDX\0"
  /* 7639 */ "G_FRAME_INDEX\0"
  /* 7653 */ "G_SBFX\0"
  /* 7660 */ "G_UBFX\0"
  /* 7667 */ "G_SMULFIX\0"
  /* 7677 */ "G_UMULFIX\0"
  /* 7687 */ "G_SDIVFIX\0"
  /* 7697 */ "G_UDIVFIX\0"
  /* 7707 */ "VOTE_ANY\0"
  /* 7716 */ "G_MEMCPY\0"
  /* 7725 */ "COPY\0"
  /* 7730 */ "CLZ\0"
  /* 7734 */ "G_CTLZ\0"
  /* 7741 */ "G_CTTZ\0"
  /* 7748 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    3079U, 4014U, 5894U, 4293U, 3665U, 3646U, 3674U, 3834U, 
    2735U, 2750U, 2635U, 2777U, 6300U, 2512U, 7178U, 2648U, 
    3075U, 3655U, 2272U, 7725U, 2393U, 7069U, 2109U, 2215U, 
    2260U, 4419U, 3822U, 6953U, 2194U, 4855U, 2840U, 6942U, 
    2432U, 4813U, 4800U, 5955U, 6747U, 6816U, 3742U, 3801U, 
    3774U, 3691U, 5920U, 4358U, 7208U, 7247U, 4137U, 1938U, 
    1615U, 3944U, 7352U, 7359U, 3971U, 3978U, 3985U, 3995U, 
    2087U, 6187U, 6145U, 2633U, 3077U, 7639U, 2522U, 3839U, 
    6709U, 6244U, 7106U, 6261U, 6079U, 1701U, 6283U, 6964U, 
    6214U, 7151U, 2572U, 5931U, 2168U, 1675U, 2150U, 6983U, 
    4115U, 5980U, 1826U, 1770U, 1800U, 1811U, 1751U, 1781U, 
    2476U, 2460U, 6330U, 2791U, 2808U, 1954U, 1621U, 2093U, 
    2036U, 6192U, 6151U, 7558U, 4270U, 7541U, 4253U, 1899U, 
    1592U, 7476U, 4188U, 4450U, 4428U, 2252U, 2997U, 2122U, 
    6728U, 7084U, 1653U, 6367U, 6919U, 6394U, 7231U, 1693U, 
    6908U, 6896U, 7059U, 2832U, 7201U, 2764U, 7240U, 3728U, 
    6046U, 6032U, 3715U, 6039U, 6207U, 3855U, 4505U, 4498U, 
    6719U, 4350U, 2293U, 4334U, 2236U, 4342U, 2285U, 4326U, 
    2228U, 4394U, 4386U, 3016U, 3008U, 6627U, 6617U, 6607U, 
    6597U, 6647U, 6637U, 7667U, 7677U, 6657U, 6670U, 7687U, 
    7697U, 6683U, 6696U, 1857U, 1571U, 3886U, 1540U, 1744U, 
    7331U, 3950U, 7431U, 3378U, 4899U, 695U, 9U, 2825U, 
    678U, 0U, 4874U, 4906U, 2722U, 7193U, 1665U, 3341U, 
    3364U, 4480U, 4489U, 6225U, 4152U, 6317U, 2581U, 4088U, 
    4098U, 2342U, 2357U, 4045U, 4077U, 7366U, 7392U, 7378U, 
    2301U, 2329U, 2314U, 1944U, 3566U, 4222U, 7510U, 4246U, 
    7534U, 6238U, 2141U, 2131U, 5889U, 6840U, 6868U, 6847U, 
    6094U, 7741U, 2615U, 7734U, 2597U, 4792U, 4472U, 2499U, 
    3734U, 6276U, 4286U, 7115U, 6059U, 6975U, 7001U, 7161U, 
    5907U, 2380U, 1722U, 2537U, 2445U, 1885U, 1578U, 3914U, 
    7338U, 3957U, 1546U, 7123U, 4883U, 5999U, 6015U, 7716U, 
    2408U, 2562U, 6772U, 4411U, 1864U, 3893U, 1840U, 3869U, 
    7459U, 4171U, 4056U, 4024U, 1922U, 3928U, 2071U, 6172U, 
    6129U, 7493U, 4205U, 7517U, 4229U, 7653U, 7660U, 4309U, 
    4840U, 7138U, 1990U, 3762U, 2932U, 6524U, 2006U, 7438U, 
    3048U, 2053U, 7413U, 6068U, 6111U, 6761U, 2021U, 6228U, 
    1836U, 3056U, 1271U, 5726U, 4832U, 1112U, 5700U, 4825U, 
    1068U, 2049U, 3070U, 5733U, 4110U, 3103U, 5754U, 5706U, 
    1104U, 2857U, 6432U, 2888U, 6463U, 2899U, 6474U, 2958U, 
    6550U, 2984U, 6576U, 2945U, 6537U, 2971U, 6563U, 2922U, 
    6514U, 2911U, 6503U, 7016U, 6800U, 2484U, 1561U, 1997U, 
    7326U, 3757U, 2939U, 6531U, 3350U, 7730U, 551U, 54U, 
    4915U, 620U, 1502U, 1251U, 1024U, 1464U, 601U, 640U, 
    365U, 5110U, 703U, 5326U, 868U, 5506U, 106U, 4975U, 
    1521U, 1483U, 391U, 5140U, 755U, 5386U, 920U, 5566U, 
    443U, 5200U, 807U, 5446U, 972U, 5626U, 469U, 5230U, 
    833U, 5476U, 998U, 5656U, 67U, 4930U, 659U, 378U, 
    5125U, 716U, 5341U, 881U, 5521U, 119U, 4990U, 404U, 
    5155U, 768U, 5401U, 933U, 5581U, 158U, 5035U, 456U, 
    5215U, 820U, 5461U, 985U, 5641U, 184U, 5065U, 482U, 
    5245U, 846U, 5491U, 1011U, 5671U, 80U, 4945U, 729U, 
    5356U, 894U, 5536U, 132U, 5005U, 417U, 5170U, 781U, 
    5416U, 946U, 5596U, 197U, 5080U, 93U, 4960U, 742U, 
    5371U, 907U, 5551U, 145U, 5020U, 430U, 5185U, 794U, 
    5431U, 959U, 5611U, 171U, 5050U, 210U, 5095U, 569U, 
    5298U, 581U, 5312U, 495U, 5260U, 7222U, 507U, 5274U, 
    6232U, 1916U, 3061U, 2065U, 3068U, 4108U, 2549U, 6789U, 
    1559U, 3024U, 6809U, 1833U, 2244U, 7452U, 4164U, 3862U, 
    3576U, 6589U, 7318U, 6495U, 7290U, 7425U, 4402U, 2729U, 
    7053U, 6167U, 3335U, 7404U, 6741U, 3722U, 3091U, 6053U, 
    3321U, 1565U, 3034U, 3588U, 1609U, 3041U, 6123U, 3328U, 
    1043U, 1052U, 1637U, 859U, 686U, 6360U, 527U, 46U, 
    327U, 1835U, 251U, 1296U, 5699U, 1326U, 26U, 239U, 
    18U, 223U, 7454U, 357U, 4166U, 308U, 3864U, 300U, 
    1307U, 5794U, 1386U, 38U, 292U, 1573U, 231U, 1285U, 
    5692U, 1318U, 3578U, 7602U, 1215U, 1430U, 5776U, 7023U, 
    1177U, 1394U, 1121U, 1360U, 3628U, 2868U, 3600U, 6443U, 
    1970U, 7574U, 1076U, 1334U, 519U, 4380U, 5801U, 1645U, 
    6591U, 5840U, 1167U, 7320U, 5867U, 6497U, 5832U, 1157U, 
    7292U, 5859U, 3373U, 1278U, 5875U, 3098U, 5747U, 6486U, 
    5821U, 7281U, 5848U, 4404U, 2725U, 6065U, 3331U, 5770U, 
    5816U, 1150U, 3085U, 7748U, 2060U, 7420U, 4005U, 1739U, 
    6075U, 6118U, 543U, 5288U, 593U, 559U, 3711U, 5881U, 
    2692U, 316U, 4554U, 3452U, 4668U, 3187U, 3488U, 4707U, 
    3229U, 2372U, 2662U, 259U, 4512U, 3416U, 4629U, 3145U, 
    3386U, 4596U, 3109U, 7261U, 3518U, 4740U, 3265U, 6781U, 
    2702U, 335U, 4568U, 3464U, 4681U, 3201U, 3498U, 4718U, 
    3241U, 7298U, 3542U, 4766U, 3293U, 2400U, 2672U, 270U, 
    4526U, 3428U, 4642U, 3159U, 3396U, 4607U, 3121U, 7271U, 
    3530U, 4753U, 3279U, 6888U, 2712U, 346U, 4582U, 3476U, 
    4694U, 3215U, 3508U, 4729U, 3253U, 7308U, 3554U, 4779U, 
    3307U, 2424U, 2682U, 281U, 4540U, 3440U, 4655U, 3173U, 
    3406U, 4618U, 3133U, 7630U, 3718U, 3093U, 5740U, 5788U, 
    6035U, 3323U, 5762U, 5809U, 535U, 560U, 1567U, 3036U, 
    5712U, 5686U, 2211U, 3590U, 7616U, 1233U, 1447U, 7038U, 
    1196U, 1412U, 1135U, 1373U, 3637U, 2878U, 3614U, 6453U, 
    1980U, 7588U, 1090U, 1347U, 1574U, 3043U, 5719U, 5693U, 
    1060U, 7014U, 3083U, 7707U, 6119U, 3330U, 5769U, 5815U, 
    1149U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 705);
}

} // end namespace llvm
#endif // GET_INSTRINFO_MC_DESC

#ifdef GET_INSTRINFO_HEADER
#undef GET_INSTRINFO_HEADER
namespace llvm {
struct CCVGenInstrInfo : public TargetInstrInfo {
  explicit CCVGenInstrInfo(unsigned CFSetupOpcode = ~0u, unsigned CFDestroyOpcode = ~0u, unsigned CatchRetOpcode = ~0u, unsigned ReturnOpcode = ~0u);
  ~CCVGenInstrInfo() override = default;

};
} // end namespace llvm
#endif // GET_INSTRINFO_HEADER

#ifdef GET_INSTRINFO_HELPER_DECLS
#undef GET_INSTRINFO_HELPER_DECLS


#endif // GET_INSTRINFO_HELPER_DECLS

#ifdef GET_INSTRINFO_HELPERS
#undef GET_INSTRINFO_HELPERS

#endif // GET_INSTRINFO_HELPERS

#ifdef GET_INSTRINFO_CTOR_DTOR
#undef GET_INSTRINFO_CTOR_DTOR
namespace llvm {
extern const CCVInstrTable CCVDescs;
extern const unsigned CCVInstrNameIndices[];
extern const char CCVInstrNameData[];
CCVGenInstrInfo::CCVGenInstrInfo(unsigned CFSetupOpcode, unsigned CFDestroyOpcode, unsigned CatchRetOpcode, unsigned ReturnOpcode)
  : TargetInstrInfo(CFSetupOpcode, CFDestroyOpcode, CatchRetOpcode, ReturnOpcode) {
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 705);
}
} // end namespace llvm
#endif // GET_INSTRINFO_CTOR_DTOR

#ifdef GET_INSTRINFO_OPERAND_ENUM
#undef GET_INSTRINFO_OPERAND_ENUM
namespace llvm {
namespace CCV {
namespace OpName {
enum {
  OPERAND_LAST
};
} // end namespace OpName
} // end namespace CCV
} // end namespace llvm
#endif //GET_INSTRINFO_OPERAND_ENUM

#ifdef GET_INSTRINFO_NAMED_OPS
#undef GET_INSTRINFO_NAMED_OPS
namespace llvm {
namespace CCV {
LLVM_READONLY
int16_t getNamedOperandIdx(uint16_t Opcode, uint16_t NamedIdx) {
  return -1;
}
} // end namespace CCV
} // end namespace llvm
#endif //GET_INSTRINFO_NAMED_OPS

#ifdef GET_INSTRINFO_OPERAND_TYPES_ENUM
#undef GET_INSTRINFO_OPERAND_TYPES_ENUM
namespace llvm {
namespace CCV {
namespace OpTypes {
enum OperandType {
  brtarget8 = 0,
  brtarget18 = 1,
  brtarget21 = 2,
  calltarget17 = 3,
  f32imm = 4,
  f64imm = 5,
  i1imm = 6,
  i8imm = 7,
  i16imm = 8,
  i32imm = 9,
  i64imm = 10,
  pidx2 = 11,
  pmask4 = 12,
  pqual = 13,
  psrc = 14,
  ptype0 = 15,
  ptype1 = 16,
  ptype2 = 17,
  ptype3 = 18,
  ptype4 = 19,
  ptype5 = 20,
  simm4 = 21,
  simm8 = 22,
  simm9 = 23,
  simm10 = 24,
  simm11 = 25,
  simm13 = 26,
  simm16 = 27,
  simm17 = 28,
  simm18 = 29,
  simm21 = 30,
  srdsel = 31,
  type0 = 32,
  type1 = 33,
  type2 = 34,
  type3 = 35,
  type4 = 36,
  type5 = 37,
  uimm2 = 38,
  uimm3 = 39,
  uimm4 = 40,
  uimm5 = 41,
  uimm6 = 42,
  uimm8 = 43,
  uimm10 = 44,
  uimm16 = 45,
  uimm17 = 46,
  uimm29 = 47,
  uimm32 = 48,
  uimm33 = 49,
  untyped_imm_0 = 50,
  GPR = 51,
  GPR4 = 52,
  GPR8 = 53,
  GPR16 = 54,
  PR = 55,
  OPERAND_TYPE_LIST_END
};
} // end namespace OpTypes
} // end namespace CCV
} // end namespace llvm
#endif // GET_INSTRINFO_OPERAND_TYPES_ENUM

#ifdef GET_INSTRINFO_OPERAND_TYPE
#undef GET_INSTRINFO_OPERAND_TYPE
namespace llvm {
namespace CCV {
LLVM_READONLY
static int getOperandType(uint16_t Opcode, uint16_t OpIdx) {
  static const uint16_t Offsets[] = {
    /* PHI */
    0,
    /* INLINEASM */
    1,
    /* INLINEASM_BR */
    1,
    /* CFI_INSTRUCTION */
    1,
    /* EH_LABEL */
    2,
    /* GC_LABEL */
    3,
    /* ANNOTATION_LABEL */
    4,
    /* KILL */
    5,
    /* EXTRACT_SUBREG */
    5,
    /* INSERT_SUBREG */
    8,
    /* IMPLICIT_DEF */
    12,
    /* SUBREG_TO_REG */
    13,
    /* COPY_TO_REGCLASS */
    17,
    /* DBG_VALUE */
    20,
    /* DBG_VALUE_LIST */
    20,
    /* DBG_INSTR_REF */
    20,
    /* DBG_PHI */
    20,
    /* DBG_LABEL */
    20,
    /* REG_SEQUENCE */
    21,
    /* COPY */
    23,
    /* BUNDLE */
    25,
    /* LIFETIME_START */
    25,
    /* LIFETIME_END */
    26,
    /* PSEUDO_PROBE */
    27,
    /* ARITH_FENCE */
    31,
    /* STACKMAP */
    33,
    /* FENTRY_CALL */
    35,
    /* PATCHPOINT */
    35,
    /* LOAD_STACK_GUARD */
    41,
    /* PREALLOCATED_SETUP */
    42,
    /* PREALLOCATED_ARG */
    43,
    /* STATEPOINT */
    46,
    /* LOCAL_ESCAPE */
    46,
    /* FAULTING_OP */
    48,
    /* PATCHABLE_OP */
    49,
    /* PATCHABLE_FUNCTION_ENTER */
    49,
    /* PATCHABLE_RET */
    49,
    /* PATCHABLE_FUNCTION_EXIT */
    49,
    /* PATCHABLE_TAIL_CALL */
    49,
    /* PATCHABLE_EVENT_CALL */
    49,
    /* PATCHABLE_TYPED_EVENT_CALL */
    51,
    /* ICALL_BRANCH_FUNNEL */
    54,
    /* MEMBARRIER */
    54,
    /* JUMP_TABLE_DEBUG_INFO */
    54,
    /* G_ASSERT_SEXT */
    55,
    /* G_ASSERT_ZEXT */
    58,
    /* G_ASSERT_ALIGN */
    61,
    /* G_ADD */
    64,
    /* G_SUB */
    67,
    /* G_MUL */
    70,
    /* G_SDIV */
    73,
    /* G_UDIV */
    76,
    /* G_SREM */
    79,
    /* G_UREM */
    82,
    /* G_SDIVREM */
    85,
    /* G_UDIVREM */
    89,
    /* G_AND */
    93,
    /* G_OR */
    96,
    /* G_XOR */
    99,
    /* G_IMPLICIT_DEF */
    102,
    /* G_PHI */
    103,
    /* G_FRAME_INDEX */
    104,
    /* G_GLOBAL_VALUE */
    106,
    /* G_CONSTANT_POOL */
    108,
    /* G_EXTRACT */
    110,
    /* G_UNMERGE_VALUES */
    113,
    /* G_INSERT */
    115,
    /* G_MERGE_VALUES */
    119,
    /* G_BUILD_VECTOR */
    121,
    /* G_BUILD_VECTOR_TRUNC */
    123,
    /* G_CONCAT_VECTORS */
    125,
    /* G_PTRTOINT */
    127,
    /* G_INTTOPTR */
    129,
    /* G_BITCAST */
    131,
    /* G_FREEZE */
    133,
    /* G_CONSTANT_FOLD_BARRIER */
    135,
    /* G_INTRINSIC_FPTRUNC_ROUND */
    137,
    /* G_INTRINSIC_TRUNC */
    140,
    /* G_INTRINSIC_ROUND */
    142,
    /* G_INTRINSIC_LRINT */
    144,
    /* G_INTRINSIC_ROUNDEVEN */
    146,
    /* G_READCYCLECOUNTER */
    148,
    /* G_LOAD */
    149,
    /* G_SEXTLOAD */
    151,
    /* G_ZEXTLOAD */
    153,
    /* G_INDEXED_LOAD */
    155,
    /* G_INDEXED_SEXTLOAD */
    160,
    /* G_INDEXED_ZEXTLOAD */
    165,
    /* G_STORE */
    170,
    /* G_INDEXED_STORE */
    172,
    /* G_ATOMIC_CMPXCHG_WITH_SUCCESS */
    177,
    /* G_ATOMIC_CMPXCHG */
    182,
    /* G_ATOMICRMW_XCHG */
    186,
    /* G_ATOMICRMW_ADD */
    189,
    /* G_ATOMICRMW_SUB */
    192,
    /* G_ATOMICRMW_AND */
    195,
    /* G_ATOMICRMW_NAND */
    198,
    /* G_ATOMICRMW_OR */
    201,
    /* G_ATOMICRMW_XOR */
    204,
    /* G_ATOMICRMW_MAX */
    207,
    /* G_ATOMICRMW_MIN */
    210,
    /* G_ATOMICRMW_UMAX */
    213,
    /* G_ATOMICRMW_UMIN */
    216,
    /* G_ATOMICRMW_FADD */
    219,
    /* G_ATOMICRMW_FSUB */
    222,
    /* G_ATOMICRMW_FMAX */
    225,
    /* G_ATOMICRMW_FMIN */
    228,
    /* G_ATOMICRMW_UINC_WRAP */
    231,
    /* G_ATOMICRMW_UDEC_WRAP */
    234,
    /* G_FENCE */
    237,
    /* G_PREFETCH */
    239,
    /* G_BRCOND */
    243,
    /* G_BRINDIRECT */
    245,
    /* G_INVOKE_REGION_START */
    246,
    /* G_INTRINSIC */
    246,
    /* G_INTRINSIC_W_SIDE_EFFECTS */
    247,
    /* G_INTRINSIC_CONVERGENT */
    248,
    /* G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS */
    249,
    /* G_ANYEXT */
    250,
    /* G_TRUNC */
    252,
    /* G_CONSTANT */
    254,
    /* G_FCONSTANT */
    256,
    /* G_VASTART */
    258,
    /* G_VAARG */
    259,
    /* G_SEXT */
    262,
    /* G_SEXT_INREG */
    264,
    /* G_ZEXT */
    267,
    /* G_SHL */
    269,
    /* G_LSHR */
    272,
    /* G_ASHR */
    275,
    /* G_FSHL */
    278,
    /* G_FSHR */
    282,
    /* G_ROTR */
    286,
    /* G_ROTL */
    289,
    /* G_ICMP */
    292,
    /* G_FCMP */
    296,
    /* G_SELECT */
    300,
    /* G_UADDO */
    304,
    /* G_UADDE */
    308,
    /* G_USUBO */
    313,
    /* G_USUBE */
    317,
    /* G_SADDO */
    322,
    /* G_SADDE */
    326,
    /* G_SSUBO */
    331,
    /* G_SSUBE */
    335,
    /* G_UMULO */
    340,
    /* G_SMULO */
    344,
    /* G_UMULH */
    348,
    /* G_SMULH */
    351,
    /* G_UADDSAT */
    354,
    /* G_SADDSAT */
    357,
    /* G_USUBSAT */
    360,
    /* G_SSUBSAT */
    363,
    /* G_USHLSAT */
    366,
    /* G_SSHLSAT */
    369,
    /* G_SMULFIX */
    372,
    /* G_UMULFIX */
    376,
    /* G_SMULFIXSAT */
    380,
    /* G_UMULFIXSAT */
    384,
    /* G_SDIVFIX */
    388,
    /* G_UDIVFIX */
    392,
    /* G_SDIVFIXSAT */
    396,
    /* G_UDIVFIXSAT */
    400,
    /* G_FADD */
    404,
    /* G_FSUB */
    407,
    /* G_FMUL */
    410,
    /* G_FMA */
    413,
    /* G_FMAD */
    417,
    /* G_FDIV */
    421,
    /* G_FREM */
    424,
    /* G_FPOW */
    427,
    /* G_FPOWI */
    430,
    /* G_FEXP */
    433,
    /* G_FEXP2 */
    435,
    /* G_FEXP10 */
    437,
    /* G_FLOG */
    439,
    /* G_FLOG2 */
    441,
    /* G_FLOG10 */
    443,
    /* G_FLDEXP */
    445,
    /* G_FFREXP */
    448,
    /* G_FNEG */
    451,
    /* G_FPEXT */
    453,
    /* G_FPTRUNC */
    455,
    /* G_FPTOSI */
    457,
    /* G_FPTOUI */
    459,
    /* G_SITOFP */
    461,
    /* G_UITOFP */
    463,
    /* G_FABS */
    465,
    /* G_FCOPYSIGN */
    467,
    /* G_IS_FPCLASS */
    470,
    /* G_FCANONICALIZE */
    473,
    /* G_FMINNUM */
    475,
    /* G_FMAXNUM */
    478,
    /* G_FMINNUM_IEEE */
    481,
    /* G_FMAXNUM_IEEE */
    484,
    /* G_FMINIMUM */
    487,
    /* G_FMAXIMUM */
    490,
    /* G_GET_FPENV */
    493,
    /* G_SET_FPENV */
    494,
    /* G_RESET_FPENV */
    495,
    /* G_GET_FPMODE */
    495,
    /* G_SET_FPMODE */
    496,
    /* G_RESET_FPMODE */
    497,
    /* G_PTR_ADD */
    497,
    /* G_PTRMASK */
    500,
    /* G_SMIN */
    503,
    /* G_SMAX */
    506,
    /* G_UMIN */
    509,
    /* G_UMAX */
    512,
    /* G_ABS */
    515,
    /* G_LROUND */
    517,
    /* G_LLROUND */
    519,
    /* G_BR */
    521,
    /* G_BRJT */
    522,
    /* G_INSERT_VECTOR_ELT */
    525,
    /* G_EXTRACT_VECTOR_ELT */
    529,
    /* G_SHUFFLE_VECTOR */
    532,
    /* G_CTTZ */
    536,
    /* G_CTTZ_ZERO_UNDEF */
    538,
    /* G_CTLZ */
    540,
    /* G_CTLZ_ZERO_UNDEF */
    542,
    /* G_CTPOP */
    544,
    /* G_BSWAP */
    546,
    /* G_BITREVERSE */
    548,
    /* G_FCEIL */
    550,
    /* G_FCOS */
    552,
    /* G_FSIN */
    554,
    /* G_FSQRT */
    556,
    /* G_FFLOOR */
    558,
    /* G_FRINT */
    560,
    /* G_FNEARBYINT */
    562,
    /* G_ADDRSPACE_CAST */
    564,
    /* G_BLOCK_ADDR */
    566,
    /* G_JUMP_TABLE */
    568,
    /* G_DYN_STACKALLOC */
    570,
    /* G_STACKSAVE */
    573,
    /* G_STACKRESTORE */
    574,
    /* G_STRICT_FADD */
    575,
    /* G_STRICT_FSUB */
    578,
    /* G_STRICT_FMUL */
    581,
    /* G_STRICT_FDIV */
    584,
    /* G_STRICT_FREM */
    587,
    /* G_STRICT_FMA */
    590,
    /* G_STRICT_FSQRT */
    594,
    /* G_STRICT_FLDEXP */
    596,
    /* G_READ_REGISTER */
    599,
    /* G_WRITE_REGISTER */
    601,
    /* G_MEMCPY */
    603,
    /* G_MEMCPY_INLINE */
    607,
    /* G_MEMMOVE */
    610,
    /* G_MEMSET */
    614,
    /* G_BZERO */
    618,
    /* G_VECREDUCE_SEQ_FADD */
    621,
    /* G_VECREDUCE_SEQ_FMUL */
    624,
    /* G_VECREDUCE_FADD */
    627,
    /* G_VECREDUCE_FMUL */
    629,
    /* G_VECREDUCE_FMAX */
    631,
    /* G_VECREDUCE_FMIN */
    633,
    /* G_VECREDUCE_FMAXIMUM */
    635,
    /* G_VECREDUCE_FMINIMUM */
    637,
    /* G_VECREDUCE_ADD */
    639,
    /* G_VECREDUCE_MUL */
    641,
    /* G_VECREDUCE_AND */
    643,
    /* G_VECREDUCE_OR */
    645,
    /* G_VECREDUCE_XOR */
    647,
    /* G_VECREDUCE_SMAX */
    649,
    /* G_VECREDUCE_SMIN */
    651,
    /* G_VECREDUCE_UMAX */
    653,
    /* G_VECREDUCE_UMIN */
    655,
    /* G_SBFX */
    657,
    /* G_UBFX */
    661,
    /* ADJCALLSTACKDOWN */
    665,
    /* ADJCALLSTACKUP */
    667,
    /* PSEUDO_BCAST */
    669,
    /* PSEUDO_BRA_PRED */
    671,
    /* PSEUDO_CALL */
    674,
    /* PSEUDO_CAS_G */
    675,
    /* PSEUDO_CAS_S */
    684,
    /* PSEUDO_LD_PRED */
    693,
    /* PSEUDO_NARROW */
    696,
    /* PSEUDO_PADDI */
    698,
    /* PSEUDO_PAND */
    702,
    /* PSEUDO_PMOV */
    705,
    /* PSEUDO_POR */
    709,
    /* PSEUDO_PXOR */
    712,
    /* PSEUDO_RET */
    715,
    /* PSEUDO_ST_PRED */
    716,
    /* ABS */
    719,
    /* ADD */
    723,
    /* ADDI */
    727,
    /* ADDI48 */
    730,
    /* ADDI_P */
    733,
    /* ADDI_PP */
    737,
    /* ADDI_W16 */
    742,
    /* ADD_P */
    745,
    /* ADD_PP */
    750,
    /* ADD_W16 */
    756,
    /* AND */
    760,
    /* ANDI */
    764,
    /* ANDI_P */
    767,
    /* ANDN */
    771,
    /* ANDNI */
    775,
    /* ANDNI_P */
    778,
    /* AND_P */
    782,
    /* AND_W16 */
    787,
    /* ATOM_ADD_G */
    791,
    /* ATOM_ADD_S */
    797,
    /* ATOM_AND_G */
    803,
    /* ATOM_AND_S */
    809,
    /* ATOM_EXCH_G */
    815,
    /* ATOM_EXCH_S */
    821,
    /* ATOM_MAX_S_G */
    827,
    /* ATOM_MAX_S_S */
    833,
    /* ATOM_MAX_U_G */
    839,
    /* ATOM_MAX_U_S */
    845,
    /* ATOM_MIN_S_G */
    851,
    /* ATOM_MIN_S_S */
    857,
    /* ATOM_MIN_U_G */
    863,
    /* ATOM_MIN_U_S */
    869,
    /* ATOM_OR_G */
    875,
    /* ATOM_OR_S */
    881,
    /* ATOM_XOR_G */
    887,
    /* ATOM_XOR_S */
    893,
    /* BALLOT */
    899,
    /* BAR_INIT */
    902,
    /* BAR_WAIT_PHASE */
    904,
    /* BRA */
    907,
    /* BRA_PRED */
    908,
    /* BREV */
    910,
    /* CALL */
    914,
    /* CAS_G */
    916,
    /* CAS_S */
    925,
    /* CHWIDTH_MULTI */
    934,
    /* CLZ */
    936,
    /* COS_F32 */
    940,
    /* CVT_D0_S0_R0 */
    944,
    /* CVT_D0_S0_R0_P */
    948,
    /* CVT_D0_S0_R0_W16_32 */
    953,
    /* CVT_D0_S0_R0_W16_8 */
    957,
    /* CVT_D0_S0_R0_W32_16 */
    961,
    /* CVT_D0_S0_R0_W32_4 */
    965,
    /* CVT_D0_S0_R0_W32_8 */
    969,
    /* CVT_D0_S0_R0_W4_32 */
    973,
    /* CVT_D0_S0_R0_W8_32 */
    977,
    /* CVT_D0_S0_R1 */
    981,
    /* CVT_D0_S0_R1_P */
    985,
    /* CVT_D0_S0_R2 */
    990,
    /* CVT_D0_S0_R2_P */
    994,
    /* CVT_D0_S0_R3 */
    999,
    /* CVT_D0_S0_R3_P */
    1003,
    /* CVT_D0_S1_R0 */
    1008,
    /* CVT_D0_S1_R0_P */
    1012,
    /* CVT_D0_S1_R0_W16_8 */
    1017,
    /* CVT_D0_S1_R0_W32_8 */
    1021,
    /* CVT_D0_S1_R1 */
    1025,
    /* CVT_D0_S1_R1_P */
    1029,
    /* CVT_D0_S1_R2 */
    1034,
    /* CVT_D0_S1_R2_P */
    1038,
    /* CVT_D0_S1_R3 */
    1043,
    /* CVT_D0_S1_R3_P */
    1047,
    /* CVT_D0_S2_R1 */
    1052,
    /* CVT_D0_S2_R1_P */
    1056,
    /* CVT_D0_S2_R2 */
    1061,
    /* CVT_D0_S2_R2_P */
    1065,
    /* CVT_D0_S2_R3 */
    1070,
    /* CVT_D0_S2_R3_P */
    1074,
    /* CVT_D0_S3_R1 */
    1079,
    /* CVT_D0_S3_R1_P */
    1083,
    /* CVT_D0_S3_R2 */
    1088,
    /* CVT_D0_S3_R2_P */
    1092,
    /* CVT_D0_S3_R3 */
    1097,
    /* CVT_D0_S3_R3_P */
    1101,
    /* CVT_D1_S0_R0 */
    1106,
    /* CVT_D1_S0_R0_P */
    1110,
    /* CVT_D1_S0_R0_W8_32 */
    1115,
    /* CVT_D1_S0_R1 */
    1119,
    /* CVT_D1_S0_R1_P */
    1123,
    /* CVT_D1_S0_R2 */
    1128,
    /* CVT_D1_S0_R2_P */
    1132,
    /* CVT_D1_S0_R3 */
    1137,
    /* CVT_D1_S0_R3_P */
    1141,
    /* CVT_D1_S1_R0 */
    1146,
    /* CVT_D1_S1_R0_P */
    1150,
    /* CVT_D1_S1_R1 */
    1155,
    /* CVT_D1_S1_R1_P */
    1159,
    /* CVT_D1_S1_R2 */
    1164,
    /* CVT_D1_S1_R2_P */
    1168,
    /* CVT_D1_S1_R3 */
    1173,
    /* CVT_D1_S1_R3_P */
    1177,
    /* CVT_D1_S2_R0 */
    1182,
    /* CVT_D1_S2_R0_P */
    1186,
    /* CVT_D1_S2_R1 */
    1191,
    /* CVT_D1_S2_R1_P */
    1195,
    /* CVT_D1_S2_R2 */
    1200,
    /* CVT_D1_S2_R2_P */
    1204,
    /* CVT_D1_S2_R3 */
    1209,
    /* CVT_D1_S2_R3_P */
    1213,
    /* CVT_D1_S3_R0 */
    1218,
    /* CVT_D1_S3_R0_P */
    1222,
    /* CVT_D1_S3_R1 */
    1227,
    /* CVT_D1_S3_R1_P */
    1231,
    /* CVT_D1_S3_R2 */
    1236,
    /* CVT_D1_S3_R2_P */
    1240,
    /* CVT_D1_S3_R3 */
    1245,
    /* CVT_D1_S3_R3_P */
    1249,
    /* CVT_D2_S0_R0 */
    1254,
    /* CVT_D2_S0_R0_P */
    1258,
    /* CVT_D2_S0_R2 */
    1263,
    /* CVT_D2_S0_R2_P */
    1267,
    /* CVT_D2_S0_R3 */
    1272,
    /* CVT_D2_S0_R3_P */
    1276,
    /* CVT_D2_S1_R0 */
    1281,
    /* CVT_D2_S1_R0_P */
    1285,
    /* CVT_D2_S1_R1 */
    1290,
    /* CVT_D2_S1_R1_P */
    1294,
    /* CVT_D2_S1_R2 */
    1299,
    /* CVT_D2_S1_R2_P */
    1303,
    /* CVT_D2_S1_R3 */
    1308,
    /* CVT_D2_S1_R3_P */
    1312,
    /* CVT_D2_S3_R0 */
    1317,
    /* CVT_D2_S3_R0_P */
    1321,
    /* CVT_D3_S0_R0 */
    1326,
    /* CVT_D3_S0_R0_P */
    1330,
    /* CVT_D3_S0_R2 */
    1335,
    /* CVT_D3_S0_R2_P */
    1339,
    /* CVT_D3_S0_R3 */
    1344,
    /* CVT_D3_S0_R3_P */
    1348,
    /* CVT_D3_S1_R0 */
    1353,
    /* CVT_D3_S1_R0_P */
    1357,
    /* CVT_D3_S1_R1 */
    1362,
    /* CVT_D3_S1_R1_P */
    1366,
    /* CVT_D3_S1_R2 */
    1371,
    /* CVT_D3_S1_R2_P */
    1375,
    /* CVT_D3_S1_R3 */
    1380,
    /* CVT_D3_S1_R3_P */
    1384,
    /* CVT_D3_S2_R0 */
    1389,
    /* CVT_D3_S2_R0_P */
    1393,
    /* CVT_D3_S3_R0 */
    1398,
    /* CVT_D3_S3_R0_P */
    1402,
    /* CVT_F32_S32 */
    1407,
    /* CVT_F32_S32_P */
    1411,
    /* CVT_F32_U32 */
    1416,
    /* CVT_F32_U32_P */
    1420,
    /* CVT_S32_F32 */
    1425,
    /* CVT_S32_F32_P */
    1429,
    /* CVT_SEXT */
    1434,
    /* CVT_U32_F32 */
    1438,
    /* CVT_U32_F32_P */
    1442,
    /* C_ABS */
    1447,
    /* C_ADD */
    1449,
    /* C_ADDI */
    1452,
    /* C_AND */
    1455,
    /* C_ANDI */
    1458,
    /* C_ANDN */
    1461,
    /* C_BAR_ARRIVE */
    1464,
    /* C_BAR_WAIT */
    1465,
    /* C_BRA */
    1466,
    /* C_CHWIDTH */
    1467,
    /* C_EXIT */
    1469,
    /* C_FADD */
    1470,
    /* C_FENCE */
    1473,
    /* C_FMAX */
    1474,
    /* C_FMIN */
    1477,
    /* C_FMUL */
    1480,
    /* C_LD_GLOBAL */
    1483,
    /* C_MAX_S */
    1485,
    /* C_MAX_U */
    1488,
    /* C_MIN_S */
    1491,
    /* C_MIN_U */
    1494,
    /* C_MOV */
    1497,
    /* C_MUL_LO */
    1499,
    /* C_NEG */
    1502,
    /* C_NOT */
    1504,
    /* C_OR */
    1506,
    /* C_ORI */
    1509,
    /* C_RECONV */
    1512,
    /* C_RET */
    1513,
    /* C_SHL */
    1514,
    /* C_SHLI */
    1517,
    /* C_SHR */
    1520,
    /* C_SHRI */
    1523,
    /* C_SRA */
    1526,
    /* C_SRAI */
    1529,
    /* C_ST_GLOBAL */
    1532,
    /* C_SUB */
    1534,
    /* C_SUBI */
    1537,
    /* C_XOR */
    1540,
    /* C_XORI */
    1543,
    /* DP2_BF16 */
    1546,
    /* DP2_F16 */
    1550,
    /* DP4_ACC */
    1554,
    /* DP4_E4M3 */
    1558,
    /* DP4_E5M2 */
    1562,
    /* DP4_SS */
    1566,
    /* EX2_F32 */
    1570,
    /* FABS_F0 */
    1574,
    /* FABS_F1 */
    1578,
    /* FADD */
    1582,
    /* FADD_F1 */
    1586,
    /* FADD_F1_W8 */
    1590,
    /* FADD_P */
    1594,
    /* FADD_W8 */
    1599,
    /* FFMA_ACC_F0 */
    1603,
    /* FFMA_ACC_F1 */
    1607,
    /* FFMA_F0 */
    1611,
    /* FFMA_F1 */
    1615,
    /* FMAX */
    1619,
    /* FMAX_F1 */
    1623,
    /* FMIN */
    1627,
    /* FMIN_F1 */
    1631,
    /* FMUL */
    1635,
    /* FMUL_F1 */
    1639,
    /* FMUL_F1_W8 */
    1643,
    /* FMUL_P */
    1647,
    /* FMUL_W8 */
    1652,
    /* FNEG_F0 */
    1656,
    /* FNEG_F1 */
    1660,
    /* FSUB */
    1664,
    /* FSUB_F1 */
    1668,
    /* FSUB_F1_W8 */
    1672,
    /* FSUB_P */
    1676,
    /* FSUB_W8 */
    1681,
    /* LD_GLOBAL */
    1685,
    /* LD_GLOBAL_IDX */
    1688,
    /* LD_GLOBAL_IDX_W16 */
    1693,
    /* LD_GLOBAL_IDX_W8 */
    1698,
    /* LD_GLOBAL_P */
    1703,
    /* LD_GLOBAL_SLOT */
    1707,
    /* LD_GLOBAL_SLOT_W16 */
    1712,
    /* LD_GLOBAL_SLOT_W8 */
    1717,
    /* LD_GLOBAL_W16 */
    1722,
    /* LD_GLOBAL_W8 */
    1725,
    /* LD_LOCAL */
    1728,
    /* LD_PRED_G */
    1730,
    /* LD_PRED_LOCAL */
    1733,
    /* LD_PRED_S */
    1735,
    /* LD_SHARED */
    1738,
    /* LD_SHARED_IDX */
    1741,
    /* LD_SHARED_W16 */
    1746,
    /* LD_SHARED_W8 */
    1749,
    /* LG2_F32 */
    1752,
    /* MADLO */
    1756,
    /* MADLO_P */
    1760,
    /* MAD_ACC */
    1765,
    /* MAX_S */
    1769,
    /* MAX_S_P */
    1773,
    /* MAX_S_W16 */
    1778,
    /* MAX_U */
    1782,
    /* MAX_U_P */
    1786,
    /* MIN_S */
    1791,
    /* MIN_S_P */
    1795,
    /* MIN_S_W16 */
    1800,
    /* MIN_U */
    1804,
    /* MIN_U_P */
    1808,
    /* MOVI */
    1813,
    /* MOVI48 */
    1815,
    /* MOV_P */
    1817,
    /* MULI */
    1823,
    /* MULI_P */
    1826,
    /* MUL_HI_S */
    1830,
    /* MUL_HI_S_P */
    1834,
    /* MUL_HI_U */
    1839,
    /* MUL_HI_U_P */
    1843,
    /* MUL_LO */
    1848,
    /* NEG */
    1852,
    /* OR */
    1856,
    /* ORI */
    1860,
    /* ORI_P */
    1863,
    /* OR_P */
    1867,
    /* OR_W16 */
    1872,
    /* PACKI */
    1876,
    /* PACKI_Z */
    1880,
    /* PAND */
    1883,
    /* PMOV */
    1886,
    /* PMOV_IMM */
    1889,
    /* POPC */
    1891,
    /* POR */
    1895,
    /* PXOR */
    1898,
    /* RCP_F32 */
    1901,
    /* RCP_F32_P */
    1905,
    /* RCP_U32 */
    1910,
    /* RSQRT_F32 */
    1914,
    /* SEL */
    1918,
    /* SETP_EQ */
    1923,
    /* SETP_EQ_F */
    1928,
    /* SETP_EQ_F1 */
    1933,
    /* SETP_EQ_F1_NP */
    1938,
    /* SETP_EQ_F_I */
    1942,
    /* SETP_EQ_F_NP */
    1947,
    /* SETP_EQ_F_NPI */
    1951,
    /* SETP_EQ_I */
    1955,
    /* SETP_EQ_NP */
    1960,
    /* SETP_EQ_NPI */
    1964,
    /* SETP_GE */
    1968,
    /* SETP_GE_F */
    1973,
    /* SETP_GE_F1 */
    1978,
    /* SETP_GE_F1_NP */
    1983,
    /* SETP_GE_F_I */
    1987,
    /* SETP_GE_F_NP */
    1992,
    /* SETP_GE_F_NPI */
    1996,
    /* SETP_GE_I */
    2000,
    /* SETP_GE_NP */
    2005,
    /* SETP_GE_NPI */
    2009,
    /* SETP_GE_U */
    2013,
    /* SETP_GE_U_I */
    2018,
    /* SETP_GE_U_NP */
    2023,
    /* SETP_GE_U_NPI */
    2027,
    /* SETP_GT */
    2031,
    /* SETP_GT_F */
    2036,
    /* SETP_GT_F1 */
    2041,
    /* SETP_GT_F1_NP */
    2046,
    /* SETP_GT_F_I */
    2050,
    /* SETP_GT_F_NP */
    2055,
    /* SETP_GT_F_NPI */
    2059,
    /* SETP_GT_I */
    2063,
    /* SETP_GT_NP */
    2068,
    /* SETP_GT_NPI */
    2072,
    /* SETP_GT_U */
    2076,
    /* SETP_GT_U_I */
    2081,
    /* SETP_GT_U_NP */
    2086,
    /* SETP_GT_U_NPI */
    2090,
    /* SETP_LE */
    2094,
    /* SETP_LE_F */
    2099,
    /* SETP_LE_F1 */
    2104,
    /* SETP_LE_F1_NP */
    2109,
    /* SETP_LE_F_I */
    2113,
    /* SETP_LE_F_NP */
    2118,
    /* SETP_LE_F_NPI */
    2122,
    /* SETP_LE_I */
    2126,
    /* SETP_LE_NP */
    2131,
    /* SETP_LE_NPI */
    2135,
    /* SETP_LE_U */
    2139,
    /* SETP_LE_U_I */
    2144,
    /* SETP_LE_U_NP */
    2149,
    /* SETP_LE_U_NPI */
    2153,
    /* SETP_LT */
    2157,
    /* SETP_LT_F */
    2162,
    /* SETP_LT_F1 */
    2167,
    /* SETP_LT_F1_NP */
    2172,
    /* SETP_LT_F_I */
    2176,
    /* SETP_LT_F_NP */
    2181,
    /* SETP_LT_F_NPI */
    2185,
    /* SETP_LT_I */
    2189,
    /* SETP_LT_NP */
    2194,
    /* SETP_LT_NPI */
    2198,
    /* SETP_LT_U */
    2202,
    /* SETP_LT_U_I */
    2207,
    /* SETP_LT_U_NP */
    2212,
    /* SETP_LT_U_NPI */
    2216,
    /* SETP_NE */
    2220,
    /* SETP_NE_F */
    2225,
    /* SETP_NE_F1 */
    2230,
    /* SETP_NE_F1_NP */
    2235,
    /* SETP_NE_F_I */
    2239,
    /* SETP_NE_F_NP */
    2244,
    /* SETP_NE_F_NPI */
    2248,
    /* SETP_NE_I */
    2252,
    /* SETP_NE_NP */
    2257,
    /* SETP_NE_NPI */
    2261,
    /* SHFL_IDX */
    2265,
    /* SHL */
    2269,
    /* SHLI */
    2273,
    /* SHLI_P */
    2276,
    /* SHL_P */
    2280,
    /* SHR */
    2285,
    /* SHRI */
    2289,
    /* SHRI_P */
    2292,
    /* SHR_P */
    2296,
    /* SIN_F32 */
    2301,
    /* SQRT_F32 */
    2305,
    /* SRA */
    2309,
    /* SRAI */
    2313,
    /* SRAI_P */
    2316,
    /* SRA_P */
    2320,
    /* SRD */
    2325,
    /* ST_GLOBAL */
    2327,
    /* ST_GLOBAL_IDX */
    2330,
    /* ST_GLOBAL_IDX_W16 */
    2335,
    /* ST_GLOBAL_IDX_W8 */
    2340,
    /* ST_GLOBAL_SLOT */
    2345,
    /* ST_GLOBAL_SLOT_W16 */
    2350,
    /* ST_GLOBAL_SLOT_W8 */
    2355,
    /* ST_GLOBAL_W16 */
    2360,
    /* ST_GLOBAL_W8 */
    2363,
    /* ST_LOCAL */
    2366,
    /* ST_PRED_G */
    2368,
    /* ST_PRED_LOCAL */
    2371,
    /* ST_PRED_S */
    2373,
    /* ST_SHARED */
    2376,
    /* ST_SHARED_IDX */
    2379,
    /* ST_SHARED_W16 */
    2384,
    /* ST_SHARED_W8 */
    2387,
    /* SUB */
    2390,
    /* SUBI */
    2394,
    /* SUBI_P */
    2397,
    /* SUB_P */
    2401,
    /* SUB_W16 */
    2406,
    /* UNBALLOT */
    2410,
    /* UNPACKI */
    2413,
    /* VOTE_ANY */
    2416,
    /* XOR */
    2419,
    /* XORI */
    2423,
    /* XORI_P */
    2426,
    /* XOR_P */
    2430,
    /* XOR_W16 */
    2435,
  };

  using namespace OpTypes;
  static const int8_t OpcodeOperandTypes[] = {
    
    /* PHI */
    -1, 
    /* INLINEASM */
    /* INLINEASM_BR */
    /* CFI_INSTRUCTION */
    i32imm, 
    /* EH_LABEL */
    i32imm, 
    /* GC_LABEL */
    i32imm, 
    /* ANNOTATION_LABEL */
    i32imm, 
    /* KILL */
    /* EXTRACT_SUBREG */
    -1, -1, i32imm, 
    /* INSERT_SUBREG */
    -1, -1, -1, i32imm, 
    /* IMPLICIT_DEF */
    -1, 
    /* SUBREG_TO_REG */
    -1, -1, -1, i32imm, 
    /* COPY_TO_REGCLASS */
    -1, -1, i32imm, 
    /* DBG_VALUE */
    /* DBG_VALUE_LIST */
    /* DBG_INSTR_REF */
    /* DBG_PHI */
    /* DBG_LABEL */
    -1, 
    /* REG_SEQUENCE */
    -1, -1, 
    /* COPY */
    -1, -1, 
    /* BUNDLE */
    /* LIFETIME_START */
    i32imm, 
    /* LIFETIME_END */
    i32imm, 
    /* PSEUDO_PROBE */
    i64imm, i64imm, i8imm, i32imm, 
    /* ARITH_FENCE */
    -1, -1, 
    /* STACKMAP */
    i64imm, i32imm, 
    /* FENTRY_CALL */
    /* PATCHPOINT */
    -1, i64imm, i32imm, -1, i32imm, i32imm, 
    /* LOAD_STACK_GUARD */
    -1, 
    /* PREALLOCATED_SETUP */
    i32imm, 
    /* PREALLOCATED_ARG */
    -1, i32imm, i32imm, 
    /* STATEPOINT */
    /* LOCAL_ESCAPE */
    -1, i32imm, 
    /* FAULTING_OP */
    -1, 
    /* PATCHABLE_OP */
    /* PATCHABLE_FUNCTION_ENTER */
    /* PATCHABLE_RET */
    /* PATCHABLE_FUNCTION_EXIT */
    /* PATCHABLE_TAIL_CALL */
    /* PATCHABLE_EVENT_CALL */
    -1, -1, 
    /* PATCHABLE_TYPED_EVENT_CALL */
    -1, -1, -1, 
    /* ICALL_BRANCH_FUNNEL */
    /* MEMBARRIER */
    /* JUMP_TABLE_DEBUG_INFO */
    i64imm, 
    /* G_ASSERT_SEXT */
    type0, type0, untyped_imm_0, 
    /* G_ASSERT_ZEXT */
    type0, type0, untyped_imm_0, 
    /* G_ASSERT_ALIGN */
    type0, type0, untyped_imm_0, 
    /* G_ADD */
    type0, type0, type0, 
    /* G_SUB */
    type0, type0, type0, 
    /* G_MUL */
    type0, type0, type0, 
    /* G_SDIV */
    type0, type0, type0, 
    /* G_UDIV */
    type0, type0, type0, 
    /* G_SREM */
    type0, type0, type0, 
    /* G_UREM */
    type0, type0, type0, 
    /* G_SDIVREM */
    type0, type0, type0, type0, 
    /* G_UDIVREM */
    type0, type0, type0, type0, 
    /* G_AND */
    type0, type0, type0, 
    /* G_OR */
    type0, type0, type0, 
    /* G_XOR */
    type0, type0, type0, 
    /* G_IMPLICIT_DEF */
    type0, 
    /* G_PHI */
    type0, 
    /* G_FRAME_INDEX */
    type0, -1, 
    /* G_GLOBAL_VALUE */
    type0, -1, 
    /* G_CONSTANT_POOL */
    type0, -1, 
    /* G_EXTRACT */
    type0, type1, untyped_imm_0, 
    /* G_UNMERGE_VALUES */
    type0, type1, 
    /* G_INSERT */
    type0, type0, type1, untyped_imm_0, 
    /* G_MERGE_VALUES */
    type0, type1, 
    /* G_BUILD_VECTOR */
    type0, type1, 
    /* G_BUILD_VECTOR_TRUNC */
    type0, type1, 
    /* G_CONCAT_VECTORS */
    type0, type1, 
    /* G_PTRTOINT */
    type0, type1, 
    /* G_INTTOPTR */
    type0, type1, 
    /* G_BITCAST */
    type0, type1, 
    /* G_FREEZE */
    type0, type0, 
    /* G_CONSTANT_FOLD_BARRIER */
    type0, type0, 
    /* G_INTRINSIC_FPTRUNC_ROUND */
    type0, type1, i32imm, 
    /* G_INTRINSIC_TRUNC */
    type0, type0, 
    /* G_INTRINSIC_ROUND */
    type0, type0, 
    /* G_INTRINSIC_LRINT */
    type0, type1, 
    /* G_INTRINSIC_ROUNDEVEN */
    type0, type0, 
    /* G_READCYCLECOUNTER */
    type0, 
    /* G_LOAD */
    type0, ptype1, 
    /* G_SEXTLOAD */
    type0, ptype1, 
    /* G_ZEXTLOAD */
    type0, ptype1, 
    /* G_INDEXED_LOAD */
    type0, ptype1, ptype1, type2, -1, 
    /* G_INDEXED_SEXTLOAD */
    type0, ptype1, ptype1, type2, -1, 
    /* G_INDEXED_ZEXTLOAD */
    type0, ptype1, ptype1, type2, -1, 
    /* G_STORE */
    type0, ptype1, 
    /* G_INDEXED_STORE */
    ptype0, type1, ptype0, ptype2, -1, 
    /* G_ATOMIC_CMPXCHG_WITH_SUCCESS */
    type0, type1, type2, type0, type0, 
    /* G_ATOMIC_CMPXCHG */
    type0, ptype1, type0, type0, 
    /* G_ATOMICRMW_XCHG */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_ADD */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_SUB */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_AND */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_NAND */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_OR */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_XOR */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_MAX */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_MIN */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_UMAX */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_UMIN */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_FADD */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_FSUB */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_FMAX */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_FMIN */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_UINC_WRAP */
    type0, ptype1, type0, 
    /* G_ATOMICRMW_UDEC_WRAP */
    type0, ptype1, type0, 
    /* G_FENCE */
    i32imm, i32imm, 
    /* G_PREFETCH */
    ptype0, i32imm, i32imm, i32imm, 
    /* G_BRCOND */
    type0, -1, 
    /* G_BRINDIRECT */
    type0, 
    /* G_INVOKE_REGION_START */
    /* G_INTRINSIC */
    -1, 
    /* G_INTRINSIC_W_SIDE_EFFECTS */
    -1, 
    /* G_INTRINSIC_CONVERGENT */
    -1, 
    /* G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS */
    -1, 
    /* G_ANYEXT */
    type0, type1, 
    /* G_TRUNC */
    type0, type1, 
    /* G_CONSTANT */
    type0, -1, 
    /* G_FCONSTANT */
    type0, -1, 
    /* G_VASTART */
    type0, 
    /* G_VAARG */
    type0, type1, -1, 
    /* G_SEXT */
    type0, type1, 
    /* G_SEXT_INREG */
    type0, type0, untyped_imm_0, 
    /* G_ZEXT */
    type0, type1, 
    /* G_SHL */
    type0, type0, type1, 
    /* G_LSHR */
    type0, type0, type1, 
    /* G_ASHR */
    type0, type0, type1, 
    /* G_FSHL */
    type0, type0, type0, type1, 
    /* G_FSHR */
    type0, type0, type0, type1, 
    /* G_ROTR */
    type0, type0, type1, 
    /* G_ROTL */
    type0, type0, type1, 
    /* G_ICMP */
    type0, -1, type1, type1, 
    /* G_FCMP */
    type0, -1, type1, type1, 
    /* G_SELECT */
    type0, type1, type0, type0, 
    /* G_UADDO */
    type0, type1, type0, type0, 
    /* G_UADDE */
    type0, type1, type0, type0, type1, 
    /* G_USUBO */
    type0, type1, type0, type0, 
    /* G_USUBE */
    type0, type1, type0, type0, type1, 
    /* G_SADDO */
    type0, type1, type0, type0, 
    /* G_SADDE */
    type0, type1, type0, type0, type1, 
    /* G_SSUBO */
    type0, type1, type0, type0, 
    /* G_SSUBE */
    type0, type1, type0, type0, type1, 
    /* G_UMULO */
    type0, type1, type0, type0, 
    /* G_SMULO */
    type0, type1, type0, type0, 
    /* G_UMULH */
    type0, type0, type0, 
    /* G_SMULH */
    type0, type0, type0, 
    /* G_UADDSAT */
    type0, type0, type0, 
    /* G_SADDSAT */
    type0, type0, type0, 
    /* G_USUBSAT */
    type0, type0, type0, 
    /* G_SSUBSAT */
    type0, type0, type0, 
    /* G_USHLSAT */
    type0, type0, type1, 
    /* G_SSHLSAT */
    type0, type0, type1, 
    /* G_SMULFIX */
    type0, type0, type0, untyped_imm_0, 
    /* G_UMULFIX */
    type0, type0, type0, untyped_imm_0, 
    /* G_SMULFIXSAT */
    type0, type0, type0, untyped_imm_0, 
    /* G_UMULFIXSAT */
    type0, type0, type0, untyped_imm_0, 
    /* G_SDIVFIX */
    type0, type0, type0, untyped_imm_0, 
    /* G_UDIVFIX */
    type0, type0, type0, untyped_imm_0, 
    /* G_SDIVFIXSAT */
    type0, type0, type0, untyped_imm_0, 
    /* G_UDIVFIXSAT */
    type0, type0, type0, untyped_imm_0, 
    /* G_FADD */
    type0, type0, type0, 
    /* G_FSUB */
    type0, type0, type0, 
    /* G_FMUL */
    type0, type0, type0, 
    /* G_FMA */
    type0, type0, type0, type0, 
    /* G_FMAD */
    type0, type0, type0, type0, 
    /* G_FDIV */
    type0, type0, type0, 
    /* G_FREM */
    type0, type0, type0, 
    /* G_FPOW */
    type0, type0, type0, 
    /* G_FPOWI */
    type0, type0, type1, 
    /* G_FEXP */
    type0, type0, 
    /* G_FEXP2 */
    type0, type0, 
    /* G_FEXP10 */
    type0, type0, 
    /* G_FLOG */
    type0, type0, 
    /* G_FLOG2 */
    type0, type0, 
    /* G_FLOG10 */
    type0, type0, 
    /* G_FLDEXP */
    type0, type0, type1, 
    /* G_FFREXP */
    type0, type1, type0, 
    /* G_FNEG */
    type0, type0, 
    /* G_FPEXT */
    type0, type1, 
    /* G_FPTRUNC */
    type0, type1, 
    /* G_FPTOSI */
    type0, type1, 
    /* G_FPTOUI */
    type0, type1, 
    /* G_SITOFP */
    type0, type1, 
    /* G_UITOFP */
    type0, type1, 
    /* G_FABS */
    type0, type0, 
    /* G_FCOPYSIGN */
    type0, type0, type1, 
    /* G_IS_FPCLASS */
    type0, type1, -1, 
    /* G_FCANONICALIZE */
    type0, type0, 
    /* G_FMINNUM */
    type0, type0, type0, 
    /* G_FMAXNUM */
    type0, type0, type0, 
    /* G_FMINNUM_IEEE */
    type0, type0, type0, 
    /* G_FMAXNUM_IEEE */
    type0, type0, type0, 
    /* G_FMINIMUM */
    type0, type0, type0, 
    /* G_FMAXIMUM */
    type0, type0, type0, 
    /* G_GET_FPENV */
    type0, 
    /* G_SET_FPENV */
    type0, 
    /* G_RESET_FPENV */
    /* G_GET_FPMODE */
    type0, 
    /* G_SET_FPMODE */
    type0, 
    /* G_RESET_FPMODE */
    /* G_PTR_ADD */
    ptype0, ptype0, type1, 
    /* G_PTRMASK */
    ptype0, ptype0, type1, 
    /* G_SMIN */
    type0, type0, type0, 
    /* G_SMAX */
    type0, type0, type0, 
    /* G_UMIN */
    type0, type0, type0, 
    /* G_UMAX */
    type0, type0, type0, 
    /* G_ABS */
    type0, type0, 
    /* G_LROUND */
    type0, type1, 
    /* G_LLROUND */
    type0, type1, 
    /* G_BR */
    -1, 
    /* G_BRJT */
    ptype0, -1, type1, 
    /* G_INSERT_VECTOR_ELT */
    type0, type0, type1, type2, 
    /* G_EXTRACT_VECTOR_ELT */
    type0, type1, type2, 
    /* G_SHUFFLE_VECTOR */
    type0, type1, type1, -1, 
    /* G_CTTZ */
    type0, type1, 
    /* G_CTTZ_ZERO_UNDEF */
    type0, type1, 
    /* G_CTLZ */
    type0, type1, 
    /* G_CTLZ_ZERO_UNDEF */
    type0, type1, 
    /* G_CTPOP */
    type0, type1, 
    /* G_BSWAP */
    type0, type0, 
    /* G_BITREVERSE */
    type0, type0, 
    /* G_FCEIL */
    type0, type0, 
    /* G_FCOS */
    type0, type0, 
    /* G_FSIN */
    type0, type0, 
    /* G_FSQRT */
    type0, type0, 
    /* G_FFLOOR */
    type0, type0, 
    /* G_FRINT */
    type0, type0, 
    /* G_FNEARBYINT */
    type0, type0, 
    /* G_ADDRSPACE_CAST */
    type0, type1, 
    /* G_BLOCK_ADDR */
    type0, -1, 
    /* G_JUMP_TABLE */
    type0, -1, 
    /* G_DYN_STACKALLOC */
    ptype0, type1, i32imm, 
    /* G_STACKSAVE */
    ptype0, 
    /* G_STACKRESTORE */
    ptype0, 
    /* G_STRICT_FADD */
    type0, type0, type0, 
    /* G_STRICT_FSUB */
    type0, type0, type0, 
    /* G_STRICT_FMUL */
    type0, type0, type0, 
    /* G_STRICT_FDIV */
    type0, type0, type0, 
    /* G_STRICT_FREM */
    type0, type0, type0, 
    /* G_STRICT_FMA */
    type0, type0, type0, type0, 
    /* G_STRICT_FSQRT */
    type0, type0, 
    /* G_STRICT_FLDEXP */
    type0, type0, type1, 
    /* G_READ_REGISTER */
    type0, -1, 
    /* G_WRITE_REGISTER */
    -1, type0, 
    /* G_MEMCPY */
    ptype0, ptype1, type2, untyped_imm_0, 
    /* G_MEMCPY_INLINE */
    ptype0, ptype1, type2, 
    /* G_MEMMOVE */
    ptype0, ptype1, type2, untyped_imm_0, 
    /* G_MEMSET */
    ptype0, type1, type2, untyped_imm_0, 
    /* G_BZERO */
    ptype0, type1, untyped_imm_0, 
    /* G_VECREDUCE_SEQ_FADD */
    type0, type1, type2, 
    /* G_VECREDUCE_SEQ_FMUL */
    type0, type1, type2, 
    /* G_VECREDUCE_FADD */
    type0, type1, 
    /* G_VECREDUCE_FMUL */
    type0, type1, 
    /* G_VECREDUCE_FMAX */
    type0, type1, 
    /* G_VECREDUCE_FMIN */
    type0, type1, 
    /* G_VECREDUCE_FMAXIMUM */
    type0, type1, 
    /* G_VECREDUCE_FMINIMUM */
    type0, type1, 
    /* G_VECREDUCE_ADD */
    type0, type1, 
    /* G_VECREDUCE_MUL */
    type0, type1, 
    /* G_VECREDUCE_AND */
    type0, type1, 
    /* G_VECREDUCE_OR */
    type0, type1, 
    /* G_VECREDUCE_XOR */
    type0, type1, 
    /* G_VECREDUCE_SMAX */
    type0, type1, 
    /* G_VECREDUCE_SMIN */
    type0, type1, 
    /* G_VECREDUCE_UMAX */
    type0, type1, 
    /* G_VECREDUCE_UMIN */
    type0, type1, 
    /* G_SBFX */
    type0, type0, type1, type1, 
    /* G_UBFX */
    type0, type0, type1, type1, 
    /* ADJCALLSTACKDOWN */
    i32imm, i32imm, 
    /* ADJCALLSTACKUP */
    i32imm, i32imm, 
    /* PSEUDO_BCAST */
    GPR, GPR, 
    /* PSEUDO_BRA_PRED */
    PR, i32imm, brtarget18, 
    /* PSEUDO_CALL */
    calltarget17, 
    /* PSEUDO_CAS_G */
    GPR, PR, PR, GPR, GPR, uimm2, simm11, GPR, GPR, 
    /* PSEUDO_CAS_S */
    GPR, PR, PR, GPR, GPR, uimm2, simm11, GPR, GPR, 
    /* PSEUDO_LD_PRED */
    PR, GPR, simm13, 
    /* PSEUDO_NARROW */
    GPR, GPR, 
    /* PSEUDO_PADDI */
    GPR, GPR, PR, simm10, 
    /* PSEUDO_PAND */
    PR, PR, PR, 
    /* PSEUDO_PMOV */
    GPR, GPR, PR, GPR, 
    /* PSEUDO_POR */
    PR, PR, PR, 
    /* PSEUDO_PXOR */
    PR, PR, PR, 
    /* PSEUDO_RET */
    GPR, 
    /* PSEUDO_ST_PRED */
    PR, GPR, simm13, 
    /* ABS */
    GPR, GPR, GPR, GPR, 
    /* ADD */
    GPR, GPR, GPR, GPR, 
    /* ADDI */
    GPR, GPR, simm13, 
    /* ADDI48 */
    GPR, GPR, uimm29, 
    /* ADDI_P */
    GPR, pqual, GPR, simm10, 
    /* ADDI_PP */
    GPR, PR, pqual, GPR, simm8, 
    /* ADDI_W16 */
    GPR16, GPR16, simm13, 
    /* ADD_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* ADD_PP */
    GPR, PR, pqual, GPR, GPR, GPR, 
    /* ADD_W16 */
    GPR16, GPR16, GPR16, GPR16, 
    /* AND */
    GPR, GPR, GPR, GPR, 
    /* ANDI */
    GPR, GPR, simm13, 
    /* ANDI_P */
    GPR, pqual, GPR, simm10, 
    /* ANDN */
    GPR, GPR, GPR, GPR, 
    /* ANDNI */
    GPR, GPR, simm13, 
    /* ANDNI_P */
    GPR, pqual, GPR, simm10, 
    /* AND_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* AND_W16 */
    GPR16, GPR16, GPR16, GPR16, 
    /* ATOM_ADD_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_ADD_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_AND_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_AND_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_EXCH_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_EXCH_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MAX_S_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MAX_S_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MAX_U_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MAX_U_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MIN_S_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MIN_S_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MIN_U_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_MIN_U_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_OR_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_OR_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_XOR_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_XOR_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* BALLOT */
    GPR, pqual, psrc, 
    /* BAR_INIT */
    uimm6, uimm10, 
    /* BAR_WAIT_PHASE */
    pqual, uimm6, pidx2, 
    /* BRA */
    brtarget21, 
    /* BRA_PRED */
    pqual, brtarget18, 
    /* BREV */
    GPR, GPR, GPR, GPR, 
    /* CALL */
    GPR, calltarget17, 
    /* CAS_G */
    GPR, PR, pqual, GPR, GPR, uimm2, simm11, GPR, GPR, 
    /* CAS_S */
    GPR, PR, pqual, GPR, GPR, uimm2, simm11, GPR, GPR, 
    /* CHWIDTH_MULTI */
    uimm16, uimm2, 
    /* CLZ */
    GPR, GPR, GPR, GPR, 
    /* COS_F32 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S0_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S0_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S0_R0_W16_32 */
    GPR16, GPR, GPR, GPR, 
    /* CVT_D0_S0_R0_W16_8 */
    GPR16, GPR8, GPR8, GPR8, 
    /* CVT_D0_S0_R0_W32_16 */
    GPR, GPR16, GPR16, GPR16, 
    /* CVT_D0_S0_R0_W32_4 */
    GPR, GPR4, GPR4, GPR4, 
    /* CVT_D0_S0_R0_W32_8 */
    GPR, GPR8, GPR8, GPR8, 
    /* CVT_D0_S0_R0_W4_32 */
    GPR4, GPR, GPR, GPR, 
    /* CVT_D0_S0_R0_W8_32 */
    GPR8, GPR, GPR, GPR, 
    /* CVT_D0_S0_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S0_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S0_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S0_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S0_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S0_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S1_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S1_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S1_R0_W16_8 */
    GPR16, GPR8, GPR8, GPR8, 
    /* CVT_D0_S1_R0_W32_8 */
    GPR, GPR8, GPR8, GPR8, 
    /* CVT_D0_S1_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S1_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S1_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S1_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S1_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S1_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S2_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S2_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S2_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S2_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S2_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S2_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S3_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S3_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S3_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S3_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D0_S3_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D0_S3_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S0_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S0_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S0_R0_W8_32 */
    GPR8, GPR, GPR, GPR, 
    /* CVT_D1_S0_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S0_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S0_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S0_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S0_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S0_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S1_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S1_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S1_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S1_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S1_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S1_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S1_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S1_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S2_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S2_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S2_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S2_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S2_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S2_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S2_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S2_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S3_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S3_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S3_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S3_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S3_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S3_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D1_S3_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D1_S3_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S0_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S0_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S0_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S0_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S0_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S0_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S1_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S1_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S1_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S1_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S1_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S1_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S1_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S1_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D2_S3_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D2_S3_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S0_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S0_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S0_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S0_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S0_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S0_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S1_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S1_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S1_R1 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S1_R1_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S1_R2 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S1_R2_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S1_R3 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S1_R3_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S2_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S2_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_D3_S3_R0 */
    GPR, GPR, GPR, GPR, 
    /* CVT_D3_S3_R0_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_F32_S32 */
    GPR, GPR, GPR, GPR, 
    /* CVT_F32_S32_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_F32_U32 */
    GPR, GPR, GPR, GPR, 
    /* CVT_F32_U32_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_S32_F32 */
    GPR, GPR, GPR, GPR, 
    /* CVT_S32_F32_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* CVT_SEXT */
    GPR, GPR16, GPR16, GPR16, 
    /* CVT_U32_F32 */
    GPR, GPR, GPR, GPR, 
    /* CVT_U32_F32_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* C_ABS */
    GPR, GPR, 
    /* C_ADD */
    GPR, GPR, GPR, 
    /* C_ADDI */
    GPR, GPR, uimm4, 
    /* C_AND */
    GPR, GPR, GPR, 
    /* C_ANDI */
    GPR, GPR, uimm4, 
    /* C_ANDN */
    GPR, GPR, GPR, 
    /* C_BAR_ARRIVE */
    uimm8, 
    /* C_BAR_WAIT */
    uimm8, 
    /* C_BRA */
    brtarget8, 
    /* C_CHWIDTH */
    GPR, uimm2, 
    /* C_EXIT */
    uimm8, 
    /* C_FADD */
    GPR, GPR, GPR, 
    /* C_FENCE */
    uimm8, 
    /* C_FMAX */
    GPR, GPR, GPR, 
    /* C_FMIN */
    GPR, GPR, GPR, 
    /* C_FMUL */
    GPR, GPR, GPR, 
    /* C_LD_GLOBAL */
    GPR, GPR, 
    /* C_MAX_S */
    GPR, GPR, GPR, 
    /* C_MAX_U */
    GPR, GPR, GPR, 
    /* C_MIN_S */
    GPR, GPR, GPR, 
    /* C_MIN_U */
    GPR, GPR, GPR, 
    /* C_MOV */
    GPR, GPR, 
    /* C_MUL_LO */
    GPR, GPR, GPR, 
    /* C_NEG */
    GPR, GPR, 
    /* C_NOT */
    GPR, GPR, 
    /* C_OR */
    GPR, GPR, GPR, 
    /* C_ORI */
    GPR, GPR, uimm4, 
    /* C_RECONV */
    uimm8, 
    /* C_RET */
    uimm8, 
    /* C_SHL */
    GPR, GPR, GPR, 
    /* C_SHLI */
    GPR, GPR, uimm4, 
    /* C_SHR */
    GPR, GPR, GPR, 
    /* C_SHRI */
    GPR, GPR, uimm4, 
    /* C_SRA */
    GPR, GPR, GPR, 
    /* C_SRAI */
    GPR, GPR, uimm4, 
    /* C_ST_GLOBAL */
    GPR, GPR, 
    /* C_SUB */
    GPR, GPR, GPR, 
    /* C_SUBI */
    GPR, GPR, uimm4, 
    /* C_XOR */
    GPR, GPR, GPR, 
    /* C_XORI */
    GPR, GPR, uimm4, 
    /* DP2_BF16 */
    GPR, GPR, GPR, GPR, 
    /* DP2_F16 */
    GPR, GPR, GPR, GPR, 
    /* DP4_ACC */
    GPR, GPR, GPR, GPR, 
    /* DP4_E4M3 */
    GPR, GPR, GPR, GPR, 
    /* DP4_E5M2 */
    GPR, GPR, GPR, GPR, 
    /* DP4_SS */
    GPR, GPR, GPR, GPR, 
    /* EX2_F32 */
    GPR, GPR, GPR, GPR, 
    /* FABS_F0 */
    GPR, GPR, GPR, GPR, 
    /* FABS_F1 */
    GPR, GPR, GPR, GPR, 
    /* FADD */
    GPR, GPR, GPR, GPR, 
    /* FADD_F1 */
    GPR, GPR, GPR, GPR, 
    /* FADD_F1_W8 */
    GPR8, GPR8, GPR8, GPR8, 
    /* FADD_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* FADD_W8 */
    GPR8, GPR8, GPR8, GPR8, 
    /* FFMA_ACC_F0 */
    GPR, GPR, GPR, GPR, 
    /* FFMA_ACC_F1 */
    GPR, GPR, GPR, GPR, 
    /* FFMA_F0 */
    GPR, GPR, GPR, GPR, 
    /* FFMA_F1 */
    GPR, GPR, GPR, GPR, 
    /* FMAX */
    GPR, GPR, GPR, GPR, 
    /* FMAX_F1 */
    GPR, GPR, GPR, GPR, 
    /* FMIN */
    GPR, GPR, GPR, GPR, 
    /* FMIN_F1 */
    GPR, GPR, GPR, GPR, 
    /* FMUL */
    GPR, GPR, GPR, GPR, 
    /* FMUL_F1 */
    GPR, GPR, GPR, GPR, 
    /* FMUL_F1_W8 */
    GPR8, GPR8, GPR8, GPR8, 
    /* FMUL_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* FMUL_W8 */
    GPR8, GPR8, GPR8, GPR8, 
    /* FNEG_F0 */
    GPR, GPR, GPR, GPR, 
    /* FNEG_F1 */
    GPR, GPR, GPR, GPR, 
    /* FSUB */
    GPR, GPR, GPR, GPR, 
    /* FSUB_F1 */
    GPR, GPR, GPR, GPR, 
    /* FSUB_F1_W8 */
    GPR8, GPR8, GPR8, GPR8, 
    /* FSUB_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* FSUB_W8 */
    GPR8, GPR8, GPR8, GPR8, 
    /* LD_GLOBAL */
    GPR, GPR, simm13, 
    /* LD_GLOBAL_IDX */
    GPR, GPR, GPR, uimm2, simm8, 
    /* LD_GLOBAL_IDX_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* LD_GLOBAL_IDX_W8 */
    GPR8, GPR, GPR, uimm2, simm8, 
    /* LD_GLOBAL_P */
    GPR, pqual, GPR, simm10, 
    /* LD_GLOBAL_SLOT */
    GPR, uimm4, GPR, uimm2, simm8, 
    /* LD_GLOBAL_SLOT_W16 */
    GPR16, uimm4, GPR, uimm2, simm8, 
    /* LD_GLOBAL_SLOT_W8 */
    GPR8, uimm4, GPR, uimm2, simm8, 
    /* LD_GLOBAL_W16 */
    GPR16, GPR, simm13, 
    /* LD_GLOBAL_W8 */
    GPR8, GPR, simm13, 
    /* LD_LOCAL */
    GPR, uimm17, 
    /* LD_PRED_G */
    pmask4, GPR, simm13, 
    /* LD_PRED_LOCAL */
    pmask4, uimm17, 
    /* LD_PRED_S */
    pmask4, GPR, simm13, 
    /* LD_SHARED */
    GPR, GPR, simm13, 
    /* LD_SHARED_IDX */
    GPR, GPR, GPR, uimm2, simm8, 
    /* LD_SHARED_W16 */
    GPR16, GPR, simm13, 
    /* LD_SHARED_W8 */
    GPR8, GPR, simm13, 
    /* LG2_F32 */
    GPR, GPR, GPR, GPR, 
    /* MADLO */
    GPR, GPR, GPR, GPR, 
    /* MADLO_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* MAD_ACC */
    GPR, GPR, GPR, GPR, 
    /* MAX_S */
    GPR, GPR, GPR, GPR, 
    /* MAX_S_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* MAX_S_W16 */
    GPR16, GPR16, GPR16, GPR16, 
    /* MAX_U */
    GPR, GPR, GPR, GPR, 
    /* MAX_U_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* MIN_S */
    GPR, GPR, GPR, GPR, 
    /* MIN_S_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* MIN_S_W16 */
    GPR16, GPR16, GPR16, GPR16, 
    /* MIN_U */
    GPR, GPR, GPR, GPR, 
    /* MIN_U_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* MOVI */
    GPR, uimm17, 
    /* MOVI48 */
    GPR, uimm33, 
    /* MOV_P */
    GPR, GPR, pqual, GPR, GPR, GPR, 
    /* MULI */
    GPR, GPR, simm13, 
    /* MULI_P */
    GPR, pqual, GPR, simm10, 
    /* MUL_HI_S */
    GPR, GPR, GPR, GPR, 
    /* MUL_HI_S_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* MUL_HI_U */
    GPR, GPR, GPR, GPR, 
    /* MUL_HI_U_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* MUL_LO */
    GPR, GPR, GPR, GPR, 
    /* NEG */
    GPR, GPR, GPR, GPR, 
    /* OR */
    GPR, GPR, GPR, GPR, 
    /* ORI */
    GPR, GPR, simm13, 
    /* ORI_P */
    GPR, pqual, GPR, simm10, 
    /* OR_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* OR_W16 */
    GPR16, GPR16, GPR16, GPR16, 
    /* PACKI */
    GPR, GPR, GPR, uimm3, 
    /* PACKI_Z */
    GPR, GPR, uimm3, 
    /* PAND */
    PR, psrc, psrc, 
    /* PMOV */
    PR, psrc, psrc, 
    /* PMOV_IMM */
    PR, uimm32, 
    /* POPC */
    GPR, GPR, GPR, GPR, 
    /* POR */
    PR, psrc, psrc, 
    /* PXOR */
    PR, psrc, psrc, 
    /* RCP_F32 */
    GPR, GPR, GPR, GPR, 
    /* RCP_F32_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* RCP_U32 */
    GPR, GPR, GPR, GPR, 
    /* RSQRT_F32 */
    GPR, GPR, GPR, GPR, 
    /* SEL */
    GPR, pqual, GPR, GPR, GPR, 
    /* SETP_EQ */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_EQ_F */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_EQ_F1 */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_EQ_F1_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_EQ_F_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_EQ_F_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_EQ_F_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_EQ_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_EQ_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_EQ_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_GE */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GE_F */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GE_F1 */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GE_F1_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GE_F_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_GE_F_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GE_F_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_GE_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_GE_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GE_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_GE_U */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GE_U_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_GE_U_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GE_U_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_GT */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GT_F */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GT_F1 */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GT_F1_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GT_F_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_GT_F_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GT_F_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_GT_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_GT_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GT_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_GT_U */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_GT_U_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_GT_U_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_GT_U_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_LE */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LE_F */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LE_F1 */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LE_F1_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LE_F_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_LE_F_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LE_F_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_LE_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_LE_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LE_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_LE_U */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LE_U_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_LE_U_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LE_U_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_LT */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LT_F */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LT_F1 */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LT_F1_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LT_F_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_LT_F_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LT_F_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_LT_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_LT_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LT_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_LT_U */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_LT_U_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_LT_U_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_LT_U_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_NE */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_NE_F */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_NE_F1 */
    PR, GPR, pqual, GPR, GPR, 
    /* SETP_NE_F1_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_NE_F_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_NE_F_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_NE_F_NPI */
    PR, GPR, GPR, simm8, 
    /* SETP_NE_I */
    PR, GPR, pqual, GPR, simm8, 
    /* SETP_NE_NP */
    PR, GPR, GPR, GPR, 
    /* SETP_NE_NPI */
    PR, GPR, GPR, simm8, 
    /* SHFL_IDX */
    GPR, pqual, GPR, uimm5, 
    /* SHL */
    GPR, GPR, GPR, GPR, 
    /* SHLI */
    GPR, GPR, uimm5, 
    /* SHLI_P */
    GPR, pqual, GPR, uimm5, 
    /* SHL_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* SHR */
    GPR, GPR, GPR, GPR, 
    /* SHRI */
    GPR, GPR, uimm5, 
    /* SHRI_P */
    GPR, pqual, GPR, uimm5, 
    /* SHR_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* SIN_F32 */
    GPR, GPR, GPR, GPR, 
    /* SQRT_F32 */
    GPR, GPR, GPR, GPR, 
    /* SRA */
    GPR, GPR, GPR, GPR, 
    /* SRAI */
    GPR, GPR, uimm5, 
    /* SRAI_P */
    GPR, pqual, GPR, uimm5, 
    /* SRA_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* SRD */
    GPR, srdsel, 
    /* ST_GLOBAL */
    GPR, GPR, simm13, 
    /* ST_GLOBAL_IDX */
    GPR, GPR, GPR, uimm2, simm8, 
    /* ST_GLOBAL_IDX_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* ST_GLOBAL_IDX_W8 */
    GPR8, GPR, GPR, uimm2, simm8, 
    /* ST_GLOBAL_SLOT */
    GPR, uimm4, GPR, uimm2, simm8, 
    /* ST_GLOBAL_SLOT_W16 */
    GPR16, uimm4, GPR, uimm2, simm8, 
    /* ST_GLOBAL_SLOT_W8 */
    GPR8, uimm4, GPR, uimm2, simm8, 
    /* ST_GLOBAL_W16 */
    GPR16, GPR, simm13, 
    /* ST_GLOBAL_W8 */
    GPR8, GPR, simm13, 
    /* ST_LOCAL */
    GPR, uimm17, 
    /* ST_PRED_G */
    pmask4, GPR, simm13, 
    /* ST_PRED_LOCAL */
    pmask4, uimm17, 
    /* ST_PRED_S */
    pmask4, GPR, simm13, 
    /* ST_SHARED */
    GPR, GPR, simm13, 
    /* ST_SHARED_IDX */
    GPR, GPR, GPR, uimm2, simm8, 
    /* ST_SHARED_W16 */
    GPR16, GPR, simm13, 
    /* ST_SHARED_W8 */
    GPR8, GPR, simm13, 
    /* SUB */
    GPR, GPR, GPR, GPR, 
    /* SUBI */
    GPR, GPR, simm13, 
    /* SUBI_P */
    GPR, pqual, GPR, simm10, 
    /* SUB_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* SUB_W16 */
    GPR16, GPR16, GPR16, GPR16, 
    /* UNBALLOT */
    PR, pqual, GPR, 
    /* UNPACKI */
    GPR, GPR, uimm3, 
    /* VOTE_ANY */
    PR, pqual, psrc, 
    /* XOR */
    GPR, GPR, GPR, GPR, 
    /* XORI */
    GPR, GPR, simm13, 
    /* XORI_P */
    GPR, pqual, GPR, simm10, 
    /* XOR_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* XOR_W16 */
    GPR16, GPR16, GPR16, GPR16, 
  };
  return OpcodeOperandTypes[Offsets[Opcode] + OpIdx];
}
} // end namespace CCV
} // end namespace llvm
#endif // GET_INSTRINFO_OPERAND_TYPE

#ifdef GET_INSTRINFO_MEM_OPERAND_SIZE
#undef GET_INSTRINFO_MEM_OPERAND_SIZE
namespace llvm {
namespace CCV {
LLVM_READONLY
static int getMemOperandSize(int OpType) {
  switch (OpType) {
  default: return 0;
  }
}
} // end namespace CCV
} // end namespace llvm
#endif // GET_INSTRINFO_MEM_OPERAND_SIZE

#ifdef GET_INSTRINFO_LOGICAL_OPERAND_SIZE_MAP
#undef GET_INSTRINFO_LOGICAL_OPERAND_SIZE_MAP
namespace llvm {
namespace CCV {
LLVM_READONLY static unsigned
getLogicalOperandSize(uint16_t Opcode, uint16_t LogicalOpIdx) {
  return LogicalOpIdx;
}
LLVM_READONLY static inline unsigned
getLogicalOperandIdx(uint16_t Opcode, uint16_t LogicalOpIdx) {
  auto S = 0U;
  for (auto i = 0U; i < LogicalOpIdx; ++i)
    S += getLogicalOperandSize(Opcode, i);
  return S;
}
} // end namespace CCV
} // end namespace llvm
#endif // GET_INSTRINFO_LOGICAL_OPERAND_SIZE_MAP

#ifdef GET_INSTRINFO_LOGICAL_OPERAND_TYPE_MAP
#undef GET_INSTRINFO_LOGICAL_OPERAND_TYPE_MAP
namespace llvm {
namespace CCV {
LLVM_READONLY static int
getLogicalOperandType(uint16_t Opcode, uint16_t LogicalOpIdx) {
  return -1;
}
} // end namespace CCV
} // end namespace llvm
#endif // GET_INSTRINFO_LOGICAL_OPERAND_TYPE_MAP

#ifdef GET_INSTRINFO_MC_HELPER_DECLS
#undef GET_INSTRINFO_MC_HELPER_DECLS

namespace llvm {
class MCInst;
class FeatureBitset;

namespace CCV_MC {

void verifyInstructionPredicates(unsigned Opcode, const FeatureBitset &Features);

} // end namespace CCV_MC
} // end namespace llvm

#endif // GET_INSTRINFO_MC_HELPER_DECLS

#ifdef GET_INSTRINFO_MC_HELPERS
#undef GET_INSTRINFO_MC_HELPERS

namespace llvm {
namespace CCV_MC {

} // end namespace CCV_MC
} // end namespace llvm

#endif // GET_GENISTRINFO_MC_HELPERS

#if (defined(ENABLE_INSTR_PREDICATE_VERIFIER) && !defined(NDEBUG)) ||\
    defined(GET_AVAILABLE_OPCODE_CHECKER)
#define GET_COMPUTE_FEATURES
#endif
#ifdef GET_COMPUTE_FEATURES
#undef GET_COMPUTE_FEATURES
namespace llvm {
namespace CCV_MC {

// Bits for subtarget features that participate in instruction matching.
enum SubtargetFeatureBits : uint8_t {
};

inline FeatureBitset computeAvailableFeatures(const FeatureBitset &FB) {
  FeatureBitset Features;
  return Features;
}

inline FeatureBitset computeRequiredFeatures(unsigned Opcode) {
  enum : uint8_t {
    CEFBS_None,
  };

  static constexpr FeatureBitset FeatureBitsets[] = {
    {}, // CEFBS_None
  };
  static constexpr uint8_t RequiredFeaturesRefs[] = {
    CEFBS_None, // PHI = 0
    CEFBS_None, // INLINEASM = 1
    CEFBS_None, // INLINEASM_BR = 2
    CEFBS_None, // CFI_INSTRUCTION = 3
    CEFBS_None, // EH_LABEL = 4
    CEFBS_None, // GC_LABEL = 5
    CEFBS_None, // ANNOTATION_LABEL = 6
    CEFBS_None, // KILL = 7
    CEFBS_None, // EXTRACT_SUBREG = 8
    CEFBS_None, // INSERT_SUBREG = 9
    CEFBS_None, // IMPLICIT_DEF = 10
    CEFBS_None, // SUBREG_TO_REG = 11
    CEFBS_None, // COPY_TO_REGCLASS = 12
    CEFBS_None, // DBG_VALUE = 13
    CEFBS_None, // DBG_VALUE_LIST = 14
    CEFBS_None, // DBG_INSTR_REF = 15
    CEFBS_None, // DBG_PHI = 16
    CEFBS_None, // DBG_LABEL = 17
    CEFBS_None, // REG_SEQUENCE = 18
    CEFBS_None, // COPY = 19
    CEFBS_None, // BUNDLE = 20
    CEFBS_None, // LIFETIME_START = 21
    CEFBS_None, // LIFETIME_END = 22
    CEFBS_None, // PSEUDO_PROBE = 23
    CEFBS_None, // ARITH_FENCE = 24
    CEFBS_None, // STACKMAP = 25
    CEFBS_None, // FENTRY_CALL = 26
    CEFBS_None, // PATCHPOINT = 27
    CEFBS_None, // LOAD_STACK_GUARD = 28
    CEFBS_None, // PREALLOCATED_SETUP = 29
    CEFBS_None, // PREALLOCATED_ARG = 30
    CEFBS_None, // STATEPOINT = 31
    CEFBS_None, // LOCAL_ESCAPE = 32
    CEFBS_None, // FAULTING_OP = 33
    CEFBS_None, // PATCHABLE_OP = 34
    CEFBS_None, // PATCHABLE_FUNCTION_ENTER = 35
    CEFBS_None, // PATCHABLE_RET = 36
    CEFBS_None, // PATCHABLE_FUNCTION_EXIT = 37
    CEFBS_None, // PATCHABLE_TAIL_CALL = 38
    CEFBS_None, // PATCHABLE_EVENT_CALL = 39
    CEFBS_None, // PATCHABLE_TYPED_EVENT_CALL = 40
    CEFBS_None, // ICALL_BRANCH_FUNNEL = 41
    CEFBS_None, // MEMBARRIER = 42
    CEFBS_None, // JUMP_TABLE_DEBUG_INFO = 43
    CEFBS_None, // G_ASSERT_SEXT = 44
    CEFBS_None, // G_ASSERT_ZEXT = 45
    CEFBS_None, // G_ASSERT_ALIGN = 46
    CEFBS_None, // G_ADD = 47
    CEFBS_None, // G_SUB = 48
    CEFBS_None, // G_MUL = 49
    CEFBS_None, // G_SDIV = 50
    CEFBS_None, // G_UDIV = 51
    CEFBS_None, // G_SREM = 52
    CEFBS_None, // G_UREM = 53
    CEFBS_None, // G_SDIVREM = 54
    CEFBS_None, // G_UDIVREM = 55
    CEFBS_None, // G_AND = 56
    CEFBS_None, // G_OR = 57
    CEFBS_None, // G_XOR = 58
    CEFBS_None, // G_IMPLICIT_DEF = 59
    CEFBS_None, // G_PHI = 60
    CEFBS_None, // G_FRAME_INDEX = 61
    CEFBS_None, // G_GLOBAL_VALUE = 62
    CEFBS_None, // G_CONSTANT_POOL = 63
    CEFBS_None, // G_EXTRACT = 64
    CEFBS_None, // G_UNMERGE_VALUES = 65
    CEFBS_None, // G_INSERT = 66
    CEFBS_None, // G_MERGE_VALUES = 67
    CEFBS_None, // G_BUILD_VECTOR = 68
    CEFBS_None, // G_BUILD_VECTOR_TRUNC = 69
    CEFBS_None, // G_CONCAT_VECTORS = 70
    CEFBS_None, // G_PTRTOINT = 71
    CEFBS_None, // G_INTTOPTR = 72
    CEFBS_None, // G_BITCAST = 73
    CEFBS_None, // G_FREEZE = 74
    CEFBS_None, // G_CONSTANT_FOLD_BARRIER = 75
    CEFBS_None, // G_INTRINSIC_FPTRUNC_ROUND = 76
    CEFBS_None, // G_INTRINSIC_TRUNC = 77
    CEFBS_None, // G_INTRINSIC_ROUND = 78
    CEFBS_None, // G_INTRINSIC_LRINT = 79
    CEFBS_None, // G_INTRINSIC_ROUNDEVEN = 80
    CEFBS_None, // G_READCYCLECOUNTER = 81
    CEFBS_None, // G_LOAD = 82
    CEFBS_None, // G_SEXTLOAD = 83
    CEFBS_None, // G_ZEXTLOAD = 84
    CEFBS_None, // G_INDEXED_LOAD = 85
    CEFBS_None, // G_INDEXED_SEXTLOAD = 86
    CEFBS_None, // G_INDEXED_ZEXTLOAD = 87
    CEFBS_None, // G_STORE = 88
    CEFBS_None, // G_INDEXED_STORE = 89
    CEFBS_None, // G_ATOMIC_CMPXCHG_WITH_SUCCESS = 90
    CEFBS_None, // G_ATOMIC_CMPXCHG = 91
    CEFBS_None, // G_ATOMICRMW_XCHG = 92
    CEFBS_None, // G_ATOMICRMW_ADD = 93
    CEFBS_None, // G_ATOMICRMW_SUB = 94
    CEFBS_None, // G_ATOMICRMW_AND = 95
    CEFBS_None, // G_ATOMICRMW_NAND = 96
    CEFBS_None, // G_ATOMICRMW_OR = 97
    CEFBS_None, // G_ATOMICRMW_XOR = 98
    CEFBS_None, // G_ATOMICRMW_MAX = 99
    CEFBS_None, // G_ATOMICRMW_MIN = 100
    CEFBS_None, // G_ATOMICRMW_UMAX = 101
    CEFBS_None, // G_ATOMICRMW_UMIN = 102
    CEFBS_None, // G_ATOMICRMW_FADD = 103
    CEFBS_None, // G_ATOMICRMW_FSUB = 104
    CEFBS_None, // G_ATOMICRMW_FMAX = 105
    CEFBS_None, // G_ATOMICRMW_FMIN = 106
    CEFBS_None, // G_ATOMICRMW_UINC_WRAP = 107
    CEFBS_None, // G_ATOMICRMW_UDEC_WRAP = 108
    CEFBS_None, // G_FENCE = 109
    CEFBS_None, // G_PREFETCH = 110
    CEFBS_None, // G_BRCOND = 111
    CEFBS_None, // G_BRINDIRECT = 112
    CEFBS_None, // G_INVOKE_REGION_START = 113
    CEFBS_None, // G_INTRINSIC = 114
    CEFBS_None, // G_INTRINSIC_W_SIDE_EFFECTS = 115
    CEFBS_None, // G_INTRINSIC_CONVERGENT = 116
    CEFBS_None, // G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS = 117
    CEFBS_None, // G_ANYEXT = 118
    CEFBS_None, // G_TRUNC = 119
    CEFBS_None, // G_CONSTANT = 120
    CEFBS_None, // G_FCONSTANT = 121
    CEFBS_None, // G_VASTART = 122
    CEFBS_None, // G_VAARG = 123
    CEFBS_None, // G_SEXT = 124
    CEFBS_None, // G_SEXT_INREG = 125
    CEFBS_None, // G_ZEXT = 126
    CEFBS_None, // G_SHL = 127
    CEFBS_None, // G_LSHR = 128
    CEFBS_None, // G_ASHR = 129
    CEFBS_None, // G_FSHL = 130
    CEFBS_None, // G_FSHR = 131
    CEFBS_None, // G_ROTR = 132
    CEFBS_None, // G_ROTL = 133
    CEFBS_None, // G_ICMP = 134
    CEFBS_None, // G_FCMP = 135
    CEFBS_None, // G_SELECT = 136
    CEFBS_None, // G_UADDO = 137
    CEFBS_None, // G_UADDE = 138
    CEFBS_None, // G_USUBO = 139
    CEFBS_None, // G_USUBE = 140
    CEFBS_None, // G_SADDO = 141
    CEFBS_None, // G_SADDE = 142
    CEFBS_None, // G_SSUBO = 143
    CEFBS_None, // G_SSUBE = 144
    CEFBS_None, // G_UMULO = 145
    CEFBS_None, // G_SMULO = 146
    CEFBS_None, // G_UMULH = 147
    CEFBS_None, // G_SMULH = 148
    CEFBS_None, // G_UADDSAT = 149
    CEFBS_None, // G_SADDSAT = 150
    CEFBS_None, // G_USUBSAT = 151
    CEFBS_None, // G_SSUBSAT = 152
    CEFBS_None, // G_USHLSAT = 153
    CEFBS_None, // G_SSHLSAT = 154
    CEFBS_None, // G_SMULFIX = 155
    CEFBS_None, // G_UMULFIX = 156
    CEFBS_None, // G_SMULFIXSAT = 157
    CEFBS_None, // G_UMULFIXSAT = 158
    CEFBS_None, // G_SDIVFIX = 159
    CEFBS_None, // G_UDIVFIX = 160
    CEFBS_None, // G_SDIVFIXSAT = 161
    CEFBS_None, // G_UDIVFIXSAT = 162
    CEFBS_None, // G_FADD = 163
    CEFBS_None, // G_FSUB = 164
    CEFBS_None, // G_FMUL = 165
    CEFBS_None, // G_FMA = 166
    CEFBS_None, // G_FMAD = 167
    CEFBS_None, // G_FDIV = 168
    CEFBS_None, // G_FREM = 169
    CEFBS_None, // G_FPOW = 170
    CEFBS_None, // G_FPOWI = 171
    CEFBS_None, // G_FEXP = 172
    CEFBS_None, // G_FEXP2 = 173
    CEFBS_None, // G_FEXP10 = 174
    CEFBS_None, // G_FLOG = 175
    CEFBS_None, // G_FLOG2 = 176
    CEFBS_None, // G_FLOG10 = 177
    CEFBS_None, // G_FLDEXP = 178
    CEFBS_None, // G_FFREXP = 179
    CEFBS_None, // G_FNEG = 180
    CEFBS_None, // G_FPEXT = 181
    CEFBS_None, // G_FPTRUNC = 182
    CEFBS_None, // G_FPTOSI = 183
    CEFBS_None, // G_FPTOUI = 184
    CEFBS_None, // G_SITOFP = 185
    CEFBS_None, // G_UITOFP = 186
    CEFBS_None, // G_FABS = 187
    CEFBS_None, // G_FCOPYSIGN = 188
    CEFBS_None, // G_IS_FPCLASS = 189
    CEFBS_None, // G_FCANONICALIZE = 190
    CEFBS_None, // G_FMINNUM = 191
    CEFBS_None, // G_FMAXNUM = 192
    CEFBS_None, // G_FMINNUM_IEEE = 193
    CEFBS_None, // G_FMAXNUM_IEEE = 194
    CEFBS_None, // G_FMINIMUM = 195
    CEFBS_None, // G_FMAXIMUM = 196
    CEFBS_None, // G_GET_FPENV = 197
    CEFBS_None, // G_SET_FPENV = 198
    CEFBS_None, // G_RESET_FPENV = 199
    CEFBS_None, // G_GET_FPMODE = 200
    CEFBS_None, // G_SET_FPMODE = 201
    CEFBS_None, // G_RESET_FPMODE = 202
    CEFBS_None, // G_PTR_ADD = 203
    CEFBS_None, // G_PTRMASK = 204
    CEFBS_None, // G_SMIN = 205
    CEFBS_None, // G_SMAX = 206
    CEFBS_None, // G_UMIN = 207
    CEFBS_None, // G_UMAX = 208
    CEFBS_None, // G_ABS = 209
    CEFBS_None, // G_LROUND = 210
    CEFBS_None, // G_LLROUND = 211
    CEFBS_None, // G_BR = 212
    CEFBS_None, // G_BRJT = 213
    CEFBS_None, // G_INSERT_VECTOR_ELT = 214
    CEFBS_None, // G_EXTRACT_VECTOR_ELT = 215
    CEFBS_None, // G_SHUFFLE_VECTOR = 216
    CEFBS_None, // G_CTTZ = 217
    CEFBS_None, // G_CTTZ_ZERO_UNDEF = 218
    CEFBS_None, // G_CTLZ = 219
    CEFBS_None, // G_CTLZ_ZERO_UNDEF = 220
    CEFBS_None, // G_CTPOP = 221
    CEFBS_None, // G_BSWAP = 222
    CEFBS_None, // G_BITREVERSE = 223
    CEFBS_None, // G_FCEIL = 224
    CEFBS_None, // G_FCOS = 225
    CEFBS_None, // G_FSIN = 226
    CEFBS_None, // G_FSQRT = 227
    CEFBS_None, // G_FFLOOR = 228
    CEFBS_None, // G_FRINT = 229
    CEFBS_None, // G_FNEARBYINT = 230
    CEFBS_None, // G_ADDRSPACE_CAST = 231
    CEFBS_None, // G_BLOCK_ADDR = 232
    CEFBS_None, // G_JUMP_TABLE = 233
    CEFBS_None, // G_DYN_STACKALLOC = 234
    CEFBS_None, // G_STACKSAVE = 235
    CEFBS_None, // G_STACKRESTORE = 236
    CEFBS_None, // G_STRICT_FADD = 237
    CEFBS_None, // G_STRICT_FSUB = 238
    CEFBS_None, // G_STRICT_FMUL = 239
    CEFBS_None, // G_STRICT_FDIV = 240
    CEFBS_None, // G_STRICT_FREM = 241
    CEFBS_None, // G_STRICT_FMA = 242
    CEFBS_None, // G_STRICT_FSQRT = 243
    CEFBS_None, // G_STRICT_FLDEXP = 244
    CEFBS_None, // G_READ_REGISTER = 245
    CEFBS_None, // G_WRITE_REGISTER = 246
    CEFBS_None, // G_MEMCPY = 247
    CEFBS_None, // G_MEMCPY_INLINE = 248
    CEFBS_None, // G_MEMMOVE = 249
    CEFBS_None, // G_MEMSET = 250
    CEFBS_None, // G_BZERO = 251
    CEFBS_None, // G_VECREDUCE_SEQ_FADD = 252
    CEFBS_None, // G_VECREDUCE_SEQ_FMUL = 253
    CEFBS_None, // G_VECREDUCE_FADD = 254
    CEFBS_None, // G_VECREDUCE_FMUL = 255
    CEFBS_None, // G_VECREDUCE_FMAX = 256
    CEFBS_None, // G_VECREDUCE_FMIN = 257
    CEFBS_None, // G_VECREDUCE_FMAXIMUM = 258
    CEFBS_None, // G_VECREDUCE_FMINIMUM = 259
    CEFBS_None, // G_VECREDUCE_ADD = 260
    CEFBS_None, // G_VECREDUCE_MUL = 261
    CEFBS_None, // G_VECREDUCE_AND = 262
    CEFBS_None, // G_VECREDUCE_OR = 263
    CEFBS_None, // G_VECREDUCE_XOR = 264
    CEFBS_None, // G_VECREDUCE_SMAX = 265
    CEFBS_None, // G_VECREDUCE_SMIN = 266
    CEFBS_None, // G_VECREDUCE_UMAX = 267
    CEFBS_None, // G_VECREDUCE_UMIN = 268
    CEFBS_None, // G_SBFX = 269
    CEFBS_None, // G_UBFX = 270
    CEFBS_None, // ADJCALLSTACKDOWN = 271
    CEFBS_None, // ADJCALLSTACKUP = 272
    CEFBS_None, // PSEUDO_BCAST = 273
    CEFBS_None, // PSEUDO_BRA_PRED = 274
    CEFBS_None, // PSEUDO_CALL = 275
    CEFBS_None, // PSEUDO_CAS_G = 276
    CEFBS_None, // PSEUDO_CAS_S = 277
    CEFBS_None, // PSEUDO_LD_PRED = 278
    CEFBS_None, // PSEUDO_NARROW = 279
    CEFBS_None, // PSEUDO_PADDI = 280
    CEFBS_None, // PSEUDO_PAND = 281
    CEFBS_None, // PSEUDO_PMOV = 282
    CEFBS_None, // PSEUDO_POR = 283
    CEFBS_None, // PSEUDO_PXOR = 284
    CEFBS_None, // PSEUDO_RET = 285
    CEFBS_None, // PSEUDO_ST_PRED = 286
    CEFBS_None, // ABS = 287
    CEFBS_None, // ADD = 288
    CEFBS_None, // ADDI = 289
    CEFBS_None, // ADDI48 = 290
    CEFBS_None, // ADDI_P = 291
    CEFBS_None, // ADDI_PP = 292
    CEFBS_None, // ADDI_W16 = 293
    CEFBS_None, // ADD_P = 294
    CEFBS_None, // ADD_PP = 295
    CEFBS_None, // ADD_W16 = 296
    CEFBS_None, // AND = 297
    CEFBS_None, // ANDI = 298
    CEFBS_None, // ANDI_P = 299
    CEFBS_None, // ANDN = 300
    CEFBS_None, // ANDNI = 301
    CEFBS_None, // ANDNI_P = 302
    CEFBS_None, // AND_P = 303
    CEFBS_None, // AND_W16 = 304
    CEFBS_None, // ATOM_ADD_G = 305
    CEFBS_None, // ATOM_ADD_S = 306
    CEFBS_None, // ATOM_AND_G = 307
    CEFBS_None, // ATOM_AND_S = 308
    CEFBS_None, // ATOM_EXCH_G = 309
    CEFBS_None, // ATOM_EXCH_S = 310
    CEFBS_None, // ATOM_MAX_S_G = 311
    CEFBS_None, // ATOM_MAX_S_S = 312
    CEFBS_None, // ATOM_MAX_U_G = 313
    CEFBS_None, // ATOM_MAX_U_S = 314
    CEFBS_None, // ATOM_MIN_S_G = 315
    CEFBS_None, // ATOM_MIN_S_S = 316
    CEFBS_None, // ATOM_MIN_U_G = 317
    CEFBS_None, // ATOM_MIN_U_S = 318
    CEFBS_None, // ATOM_OR_G = 319
    CEFBS_None, // ATOM_OR_S = 320
    CEFBS_None, // ATOM_XOR_G = 321
    CEFBS_None, // ATOM_XOR_S = 322
    CEFBS_None, // BALLOT = 323
    CEFBS_None, // BAR_INIT = 324
    CEFBS_None, // BAR_WAIT_PHASE = 325
    CEFBS_None, // BRA = 326
    CEFBS_None, // BRA_PRED = 327
    CEFBS_None, // BREV = 328
    CEFBS_None, // CALL = 329
    CEFBS_None, // CAS_G = 330
    CEFBS_None, // CAS_S = 331
    CEFBS_None, // CHWIDTH_MULTI = 332
    CEFBS_None, // CLZ = 333
    CEFBS_None, // COS_F32 = 334
    CEFBS_None, // CVT_D0_S0_R0 = 335
    CEFBS_None, // CVT_D0_S0_R0_P = 336
    CEFBS_None, // CVT_D0_S0_R0_W16_32 = 337
    CEFBS_None, // CVT_D0_S0_R0_W16_8 = 338
    CEFBS_None, // CVT_D0_S0_R0_W32_16 = 339
    CEFBS_None, // CVT_D0_S0_R0_W32_4 = 340
    CEFBS_None, // CVT_D0_S0_R0_W32_8 = 341
    CEFBS_None, // CVT_D0_S0_R0_W4_32 = 342
    CEFBS_None, // CVT_D0_S0_R0_W8_32 = 343
    CEFBS_None, // CVT_D0_S0_R1 = 344
    CEFBS_None, // CVT_D0_S0_R1_P = 345
    CEFBS_None, // CVT_D0_S0_R2 = 346
    CEFBS_None, // CVT_D0_S0_R2_P = 347
    CEFBS_None, // CVT_D0_S0_R3 = 348
    CEFBS_None, // CVT_D0_S0_R3_P = 349
    CEFBS_None, // CVT_D0_S1_R0 = 350
    CEFBS_None, // CVT_D0_S1_R0_P = 351
    CEFBS_None, // CVT_D0_S1_R0_W16_8 = 352
    CEFBS_None, // CVT_D0_S1_R0_W32_8 = 353
    CEFBS_None, // CVT_D0_S1_R1 = 354
    CEFBS_None, // CVT_D0_S1_R1_P = 355
    CEFBS_None, // CVT_D0_S1_R2 = 356
    CEFBS_None, // CVT_D0_S1_R2_P = 357
    CEFBS_None, // CVT_D0_S1_R3 = 358
    CEFBS_None, // CVT_D0_S1_R3_P = 359
    CEFBS_None, // CVT_D0_S2_R1 = 360
    CEFBS_None, // CVT_D0_S2_R1_P = 361
    CEFBS_None, // CVT_D0_S2_R2 = 362
    CEFBS_None, // CVT_D0_S2_R2_P = 363
    CEFBS_None, // CVT_D0_S2_R3 = 364
    CEFBS_None, // CVT_D0_S2_R3_P = 365
    CEFBS_None, // CVT_D0_S3_R1 = 366
    CEFBS_None, // CVT_D0_S3_R1_P = 367
    CEFBS_None, // CVT_D0_S3_R2 = 368
    CEFBS_None, // CVT_D0_S3_R2_P = 369
    CEFBS_None, // CVT_D0_S3_R3 = 370
    CEFBS_None, // CVT_D0_S3_R3_P = 371
    CEFBS_None, // CVT_D1_S0_R0 = 372
    CEFBS_None, // CVT_D1_S0_R0_P = 373
    CEFBS_None, // CVT_D1_S0_R0_W8_32 = 374
    CEFBS_None, // CVT_D1_S0_R1 = 375
    CEFBS_None, // CVT_D1_S0_R1_P = 376
    CEFBS_None, // CVT_D1_S0_R2 = 377
    CEFBS_None, // CVT_D1_S0_R2_P = 378
    CEFBS_None, // CVT_D1_S0_R3 = 379
    CEFBS_None, // CVT_D1_S0_R3_P = 380
    CEFBS_None, // CVT_D1_S1_R0 = 381
    CEFBS_None, // CVT_D1_S1_R0_P = 382
    CEFBS_None, // CVT_D1_S1_R1 = 383
    CEFBS_None, // CVT_D1_S1_R1_P = 384
    CEFBS_None, // CVT_D1_S1_R2 = 385
    CEFBS_None, // CVT_D1_S1_R2_P = 386
    CEFBS_None, // CVT_D1_S1_R3 = 387
    CEFBS_None, // CVT_D1_S1_R3_P = 388
    CEFBS_None, // CVT_D1_S2_R0 = 389
    CEFBS_None, // CVT_D1_S2_R0_P = 390
    CEFBS_None, // CVT_D1_S2_R1 = 391
    CEFBS_None, // CVT_D1_S2_R1_P = 392
    CEFBS_None, // CVT_D1_S2_R2 = 393
    CEFBS_None, // CVT_D1_S2_R2_P = 394
    CEFBS_None, // CVT_D1_S2_R3 = 395
    CEFBS_None, // CVT_D1_S2_R3_P = 396
    CEFBS_None, // CVT_D1_S3_R0 = 397
    CEFBS_None, // CVT_D1_S3_R0_P = 398
    CEFBS_None, // CVT_D1_S3_R1 = 399
    CEFBS_None, // CVT_D1_S3_R1_P = 400
    CEFBS_None, // CVT_D1_S3_R2 = 401
    CEFBS_None, // CVT_D1_S3_R2_P = 402
    CEFBS_None, // CVT_D1_S3_R3 = 403
    CEFBS_None, // CVT_D1_S3_R3_P = 404
    CEFBS_None, // CVT_D2_S0_R0 = 405
    CEFBS_None, // CVT_D2_S0_R0_P = 406
    CEFBS_None, // CVT_D2_S0_R2 = 407
    CEFBS_None, // CVT_D2_S0_R2_P = 408
    CEFBS_None, // CVT_D2_S0_R3 = 409
    CEFBS_None, // CVT_D2_S0_R3_P = 410
    CEFBS_None, // CVT_D2_S1_R0 = 411
    CEFBS_None, // CVT_D2_S1_R0_P = 412
    CEFBS_None, // CVT_D2_S1_R1 = 413
    CEFBS_None, // CVT_D2_S1_R1_P = 414
    CEFBS_None, // CVT_D2_S1_R2 = 415
    CEFBS_None, // CVT_D2_S1_R2_P = 416
    CEFBS_None, // CVT_D2_S1_R3 = 417
    CEFBS_None, // CVT_D2_S1_R3_P = 418
    CEFBS_None, // CVT_D2_S3_R0 = 419
    CEFBS_None, // CVT_D2_S3_R0_P = 420
    CEFBS_None, // CVT_D3_S0_R0 = 421
    CEFBS_None, // CVT_D3_S0_R0_P = 422
    CEFBS_None, // CVT_D3_S0_R2 = 423
    CEFBS_None, // CVT_D3_S0_R2_P = 424
    CEFBS_None, // CVT_D3_S0_R3 = 425
    CEFBS_None, // CVT_D3_S0_R3_P = 426
    CEFBS_None, // CVT_D3_S1_R0 = 427
    CEFBS_None, // CVT_D3_S1_R0_P = 428
    CEFBS_None, // CVT_D3_S1_R1 = 429
    CEFBS_None, // CVT_D3_S1_R1_P = 430
    CEFBS_None, // CVT_D3_S1_R2 = 431
    CEFBS_None, // CVT_D3_S1_R2_P = 432
    CEFBS_None, // CVT_D3_S1_R3 = 433
    CEFBS_None, // CVT_D3_S1_R3_P = 434
    CEFBS_None, // CVT_D3_S2_R0 = 435
    CEFBS_None, // CVT_D3_S2_R0_P = 436
    CEFBS_None, // CVT_D3_S3_R0 = 437
    CEFBS_None, // CVT_D3_S3_R0_P = 438
    CEFBS_None, // CVT_F32_S32 = 439
    CEFBS_None, // CVT_F32_S32_P = 440
    CEFBS_None, // CVT_F32_U32 = 441
    CEFBS_None, // CVT_F32_U32_P = 442
    CEFBS_None, // CVT_S32_F32 = 443
    CEFBS_None, // CVT_S32_F32_P = 444
    CEFBS_None, // CVT_SEXT = 445
    CEFBS_None, // CVT_U32_F32 = 446
    CEFBS_None, // CVT_U32_F32_P = 447
    CEFBS_None, // C_ABS = 448
    CEFBS_None, // C_ADD = 449
    CEFBS_None, // C_ADDI = 450
    CEFBS_None, // C_AND = 451
    CEFBS_None, // C_ANDI = 452
    CEFBS_None, // C_ANDN = 453
    CEFBS_None, // C_BAR_ARRIVE = 454
    CEFBS_None, // C_BAR_WAIT = 455
    CEFBS_None, // C_BRA = 456
    CEFBS_None, // C_CHWIDTH = 457
    CEFBS_None, // C_EXIT = 458
    CEFBS_None, // C_FADD = 459
    CEFBS_None, // C_FENCE = 460
    CEFBS_None, // C_FMAX = 461
    CEFBS_None, // C_FMIN = 462
    CEFBS_None, // C_FMUL = 463
    CEFBS_None, // C_LD_GLOBAL = 464
    CEFBS_None, // C_MAX_S = 465
    CEFBS_None, // C_MAX_U = 466
    CEFBS_None, // C_MIN_S = 467
    CEFBS_None, // C_MIN_U = 468
    CEFBS_None, // C_MOV = 469
    CEFBS_None, // C_MUL_LO = 470
    CEFBS_None, // C_NEG = 471
    CEFBS_None, // C_NOT = 472
    CEFBS_None, // C_OR = 473
    CEFBS_None, // C_ORI = 474
    CEFBS_None, // C_RECONV = 475
    CEFBS_None, // C_RET = 476
    CEFBS_None, // C_SHL = 477
    CEFBS_None, // C_SHLI = 478
    CEFBS_None, // C_SHR = 479
    CEFBS_None, // C_SHRI = 480
    CEFBS_None, // C_SRA = 481
    CEFBS_None, // C_SRAI = 482
    CEFBS_None, // C_ST_GLOBAL = 483
    CEFBS_None, // C_SUB = 484
    CEFBS_None, // C_SUBI = 485
    CEFBS_None, // C_XOR = 486
    CEFBS_None, // C_XORI = 487
    CEFBS_None, // DP2_BF16 = 488
    CEFBS_None, // DP2_F16 = 489
    CEFBS_None, // DP4_ACC = 490
    CEFBS_None, // DP4_E4M3 = 491
    CEFBS_None, // DP4_E5M2 = 492
    CEFBS_None, // DP4_SS = 493
    CEFBS_None, // EX2_F32 = 494
    CEFBS_None, // FABS_F0 = 495
    CEFBS_None, // FABS_F1 = 496
    CEFBS_None, // FADD = 497
    CEFBS_None, // FADD_F1 = 498
    CEFBS_None, // FADD_F1_W8 = 499
    CEFBS_None, // FADD_P = 500
    CEFBS_None, // FADD_W8 = 501
    CEFBS_None, // FFMA_ACC_F0 = 502
    CEFBS_None, // FFMA_ACC_F1 = 503
    CEFBS_None, // FFMA_F0 = 504
    CEFBS_None, // FFMA_F1 = 505
    CEFBS_None, // FMAX = 506
    CEFBS_None, // FMAX_F1 = 507
    CEFBS_None, // FMIN = 508
    CEFBS_None, // FMIN_F1 = 509
    CEFBS_None, // FMUL = 510
    CEFBS_None, // FMUL_F1 = 511
    CEFBS_None, // FMUL_F1_W8 = 512
    CEFBS_None, // FMUL_P = 513
    CEFBS_None, // FMUL_W8 = 514
    CEFBS_None, // FNEG_F0 = 515
    CEFBS_None, // FNEG_F1 = 516
    CEFBS_None, // FSUB = 517
    CEFBS_None, // FSUB_F1 = 518
    CEFBS_None, // FSUB_F1_W8 = 519
    CEFBS_None, // FSUB_P = 520
    CEFBS_None, // FSUB_W8 = 521
    CEFBS_None, // LD_GLOBAL = 522
    CEFBS_None, // LD_GLOBAL_IDX = 523
    CEFBS_None, // LD_GLOBAL_IDX_W16 = 524
    CEFBS_None, // LD_GLOBAL_IDX_W8 = 525
    CEFBS_None, // LD_GLOBAL_P = 526
    CEFBS_None, // LD_GLOBAL_SLOT = 527
    CEFBS_None, // LD_GLOBAL_SLOT_W16 = 528
    CEFBS_None, // LD_GLOBAL_SLOT_W8 = 529
    CEFBS_None, // LD_GLOBAL_W16 = 530
    CEFBS_None, // LD_GLOBAL_W8 = 531
    CEFBS_None, // LD_LOCAL = 532
    CEFBS_None, // LD_PRED_G = 533
    CEFBS_None, // LD_PRED_LOCAL = 534
    CEFBS_None, // LD_PRED_S = 535
    CEFBS_None, // LD_SHARED = 536
    CEFBS_None, // LD_SHARED_IDX = 537
    CEFBS_None, // LD_SHARED_W16 = 538
    CEFBS_None, // LD_SHARED_W8 = 539
    CEFBS_None, // LG2_F32 = 540
    CEFBS_None, // MADLO = 541
    CEFBS_None, // MADLO_P = 542
    CEFBS_None, // MAD_ACC = 543
    CEFBS_None, // MAX_S = 544
    CEFBS_None, // MAX_S_P = 545
    CEFBS_None, // MAX_S_W16 = 546
    CEFBS_None, // MAX_U = 547
    CEFBS_None, // MAX_U_P = 548
    CEFBS_None, // MIN_S = 549
    CEFBS_None, // MIN_S_P = 550
    CEFBS_None, // MIN_S_W16 = 551
    CEFBS_None, // MIN_U = 552
    CEFBS_None, // MIN_U_P = 553
    CEFBS_None, // MOVI = 554
    CEFBS_None, // MOVI48 = 555
    CEFBS_None, // MOV_P = 556
    CEFBS_None, // MULI = 557
    CEFBS_None, // MULI_P = 558
    CEFBS_None, // MUL_HI_S = 559
    CEFBS_None, // MUL_HI_S_P = 560
    CEFBS_None, // MUL_HI_U = 561
    CEFBS_None, // MUL_HI_U_P = 562
    CEFBS_None, // MUL_LO = 563
    CEFBS_None, // NEG = 564
    CEFBS_None, // OR = 565
    CEFBS_None, // ORI = 566
    CEFBS_None, // ORI_P = 567
    CEFBS_None, // OR_P = 568
    CEFBS_None, // OR_W16 = 569
    CEFBS_None, // PACKI = 570
    CEFBS_None, // PACKI_Z = 571
    CEFBS_None, // PAND = 572
    CEFBS_None, // PMOV = 573
    CEFBS_None, // PMOV_IMM = 574
    CEFBS_None, // POPC = 575
    CEFBS_None, // POR = 576
    CEFBS_None, // PXOR = 577
    CEFBS_None, // RCP_F32 = 578
    CEFBS_None, // RCP_F32_P = 579
    CEFBS_None, // RCP_U32 = 580
    CEFBS_None, // RSQRT_F32 = 581
    CEFBS_None, // SEL = 582
    CEFBS_None, // SETP_EQ = 583
    CEFBS_None, // SETP_EQ_F = 584
    CEFBS_None, // SETP_EQ_F1 = 585
    CEFBS_None, // SETP_EQ_F1_NP = 586
    CEFBS_None, // SETP_EQ_F_I = 587
    CEFBS_None, // SETP_EQ_F_NP = 588
    CEFBS_None, // SETP_EQ_F_NPI = 589
    CEFBS_None, // SETP_EQ_I = 590
    CEFBS_None, // SETP_EQ_NP = 591
    CEFBS_None, // SETP_EQ_NPI = 592
    CEFBS_None, // SETP_GE = 593
    CEFBS_None, // SETP_GE_F = 594
    CEFBS_None, // SETP_GE_F1 = 595
    CEFBS_None, // SETP_GE_F1_NP = 596
    CEFBS_None, // SETP_GE_F_I = 597
    CEFBS_None, // SETP_GE_F_NP = 598
    CEFBS_None, // SETP_GE_F_NPI = 599
    CEFBS_None, // SETP_GE_I = 600
    CEFBS_None, // SETP_GE_NP = 601
    CEFBS_None, // SETP_GE_NPI = 602
    CEFBS_None, // SETP_GE_U = 603
    CEFBS_None, // SETP_GE_U_I = 604
    CEFBS_None, // SETP_GE_U_NP = 605
    CEFBS_None, // SETP_GE_U_NPI = 606
    CEFBS_None, // SETP_GT = 607
    CEFBS_None, // SETP_GT_F = 608
    CEFBS_None, // SETP_GT_F1 = 609
    CEFBS_None, // SETP_GT_F1_NP = 610
    CEFBS_None, // SETP_GT_F_I = 611
    CEFBS_None, // SETP_GT_F_NP = 612
    CEFBS_None, // SETP_GT_F_NPI = 613
    CEFBS_None, // SETP_GT_I = 614
    CEFBS_None, // SETP_GT_NP = 615
    CEFBS_None, // SETP_GT_NPI = 616
    CEFBS_None, // SETP_GT_U = 617
    CEFBS_None, // SETP_GT_U_I = 618
    CEFBS_None, // SETP_GT_U_NP = 619
    CEFBS_None, // SETP_GT_U_NPI = 620
    CEFBS_None, // SETP_LE = 621
    CEFBS_None, // SETP_LE_F = 622
    CEFBS_None, // SETP_LE_F1 = 623
    CEFBS_None, // SETP_LE_F1_NP = 624
    CEFBS_None, // SETP_LE_F_I = 625
    CEFBS_None, // SETP_LE_F_NP = 626
    CEFBS_None, // SETP_LE_F_NPI = 627
    CEFBS_None, // SETP_LE_I = 628
    CEFBS_None, // SETP_LE_NP = 629
    CEFBS_None, // SETP_LE_NPI = 630
    CEFBS_None, // SETP_LE_U = 631
    CEFBS_None, // SETP_LE_U_I = 632
    CEFBS_None, // SETP_LE_U_NP = 633
    CEFBS_None, // SETP_LE_U_NPI = 634
    CEFBS_None, // SETP_LT = 635
    CEFBS_None, // SETP_LT_F = 636
    CEFBS_None, // SETP_LT_F1 = 637
    CEFBS_None, // SETP_LT_F1_NP = 638
    CEFBS_None, // SETP_LT_F_I = 639
    CEFBS_None, // SETP_LT_F_NP = 640
    CEFBS_None, // SETP_LT_F_NPI = 641
    CEFBS_None, // SETP_LT_I = 642
    CEFBS_None, // SETP_LT_NP = 643
    CEFBS_None, // SETP_LT_NPI = 644
    CEFBS_None, // SETP_LT_U = 645
    CEFBS_None, // SETP_LT_U_I = 646
    CEFBS_None, // SETP_LT_U_NP = 647
    CEFBS_None, // SETP_LT_U_NPI = 648
    CEFBS_None, // SETP_NE = 649
    CEFBS_None, // SETP_NE_F = 650
    CEFBS_None, // SETP_NE_F1 = 651
    CEFBS_None, // SETP_NE_F1_NP = 652
    CEFBS_None, // SETP_NE_F_I = 653
    CEFBS_None, // SETP_NE_F_NP = 654
    CEFBS_None, // SETP_NE_F_NPI = 655
    CEFBS_None, // SETP_NE_I = 656
    CEFBS_None, // SETP_NE_NP = 657
    CEFBS_None, // SETP_NE_NPI = 658
    CEFBS_None, // SHFL_IDX = 659
    CEFBS_None, // SHL = 660
    CEFBS_None, // SHLI = 661
    CEFBS_None, // SHLI_P = 662
    CEFBS_None, // SHL_P = 663
    CEFBS_None, // SHR = 664
    CEFBS_None, // SHRI = 665
    CEFBS_None, // SHRI_P = 666
    CEFBS_None, // SHR_P = 667
    CEFBS_None, // SIN_F32 = 668
    CEFBS_None, // SQRT_F32 = 669
    CEFBS_None, // SRA = 670
    CEFBS_None, // SRAI = 671
    CEFBS_None, // SRAI_P = 672
    CEFBS_None, // SRA_P = 673
    CEFBS_None, // SRD = 674
    CEFBS_None, // ST_GLOBAL = 675
    CEFBS_None, // ST_GLOBAL_IDX = 676
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 677
    CEFBS_None, // ST_GLOBAL_IDX_W8 = 678
    CEFBS_None, // ST_GLOBAL_SLOT = 679
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 680
    CEFBS_None, // ST_GLOBAL_SLOT_W8 = 681
    CEFBS_None, // ST_GLOBAL_W16 = 682
    CEFBS_None, // ST_GLOBAL_W8 = 683
    CEFBS_None, // ST_LOCAL = 684
    CEFBS_None, // ST_PRED_G = 685
    CEFBS_None, // ST_PRED_LOCAL = 686
    CEFBS_None, // ST_PRED_S = 687
    CEFBS_None, // ST_SHARED = 688
    CEFBS_None, // ST_SHARED_IDX = 689
    CEFBS_None, // ST_SHARED_W16 = 690
    CEFBS_None, // ST_SHARED_W8 = 691
    CEFBS_None, // SUB = 692
    CEFBS_None, // SUBI = 693
    CEFBS_None, // SUBI_P = 694
    CEFBS_None, // SUB_P = 695
    CEFBS_None, // SUB_W16 = 696
    CEFBS_None, // UNBALLOT = 697
    CEFBS_None, // UNPACKI = 698
    CEFBS_None, // VOTE_ANY = 699
    CEFBS_None, // XOR = 700
    CEFBS_None, // XORI = 701
    CEFBS_None, // XORI_P = 702
    CEFBS_None, // XOR_P = 703
    CEFBS_None, // XOR_W16 = 704
  };

  assert(Opcode < 705);
  return FeatureBitsets[RequiredFeaturesRefs[Opcode]];
}

} // end namespace CCV_MC
} // end namespace llvm
#endif // GET_COMPUTE_FEATURES

#ifdef GET_AVAILABLE_OPCODE_CHECKER
#undef GET_AVAILABLE_OPCODE_CHECKER
namespace llvm {
namespace CCV_MC {
bool isOpcodeAvailable(unsigned Opcode, const FeatureBitset &Features) {
  FeatureBitset AvailableFeatures = computeAvailableFeatures(Features);
  FeatureBitset RequiredFeatures = computeRequiredFeatures(Opcode);
  FeatureBitset MissingFeatures =
      (AvailableFeatures & RequiredFeatures) ^
      RequiredFeatures;
  return !MissingFeatures.any();
}
} // end namespace CCV_MC
} // end namespace llvm
#endif // GET_AVAILABLE_OPCODE_CHECKER

#ifdef ENABLE_INSTR_PREDICATE_VERIFIER
#undef ENABLE_INSTR_PREDICATE_VERIFIER
#include <sstream>

namespace llvm {
namespace CCV_MC {

#ifndef NDEBUG
static const char *SubtargetFeatureNames[] = {
  nullptr
};

#endif // NDEBUG

void verifyInstructionPredicates(
    unsigned Opcode, const FeatureBitset &Features) {
#ifndef NDEBUG
  FeatureBitset AvailableFeatures = computeAvailableFeatures(Features);
  FeatureBitset RequiredFeatures = computeRequiredFeatures(Opcode);
  FeatureBitset MissingFeatures =
      (AvailableFeatures & RequiredFeatures) ^
      RequiredFeatures;
  if (MissingFeatures.any()) {
    std::ostringstream Msg;
    Msg << "Attempting to emit " << &CCVInstrNameData[CCVInstrNameIndices[Opcode]]
        << " instruction but the ";
    for (unsigned i = 0, e = MissingFeatures.size(); i != e; ++i)
      if (MissingFeatures.test(i))
        Msg << SubtargetFeatureNames[i] << " ";
    Msg << "predicate(s) are not met";
    report_fatal_error(Msg.str().c_str());
  }
#endif // NDEBUG
}
} // end namespace CCV_MC
} // end namespace llvm
#endif // ENABLE_INSTR_PREDICATE_VERIFIER

