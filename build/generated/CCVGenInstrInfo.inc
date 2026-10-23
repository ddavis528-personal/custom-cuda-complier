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
    PSEUDO_LD_PRED	= 276,
    PSEUDO_NARROW	= 277,
    PSEUDO_PAND	= 278,
    PSEUDO_PMOV	= 279,
    PSEUDO_POR	= 280,
    PSEUDO_PXOR	= 281,
    PSEUDO_RET	= 282,
    PSEUDO_ST_PRED	= 283,
    ABS	= 284,
    ADD	= 285,
    ADDI	= 286,
    ADDI48	= 287,
    ADDI_P	= 288,
    ADDI_PP	= 289,
    ADDI_W16	= 290,
    ADD_P	= 291,
    ADD_PP	= 292,
    ADD_W16	= 293,
    AND	= 294,
    ANDI	= 295,
    ANDI_P	= 296,
    ANDN	= 297,
    ANDNI	= 298,
    ANDNI_P	= 299,
    AND_P	= 300,
    AND_W16	= 301,
    ATOM_ADD_G	= 302,
    BALLOT	= 303,
    BAR_INIT	= 304,
    BAR_WAIT_PHASE	= 305,
    BRA	= 306,
    BRA_PRED	= 307,
    BREV	= 308,
    CALL	= 309,
    CAS_G	= 310,
    CHWIDTH_MULTI	= 311,
    CLZ	= 312,
    COS_F32	= 313,
    CVT_D0_S0_R0	= 314,
    CVT_D0_S0_R0_P	= 315,
    CVT_D0_S0_R0_W16_32	= 316,
    CVT_D0_S0_R0_W16_8	= 317,
    CVT_D0_S0_R0_W32_16	= 318,
    CVT_D0_S0_R0_W32_8	= 319,
    CVT_D0_S0_R0_W8_32	= 320,
    CVT_D0_S0_R1	= 321,
    CVT_D0_S0_R1_P	= 322,
    CVT_D0_S0_R2	= 323,
    CVT_D0_S0_R2_P	= 324,
    CVT_D0_S0_R3	= 325,
    CVT_D0_S0_R3_P	= 326,
    CVT_D0_S1_R0	= 327,
    CVT_D0_S1_R0_P	= 328,
    CVT_D0_S1_R0_W16_8	= 329,
    CVT_D0_S1_R0_W32_8	= 330,
    CVT_D0_S1_R1	= 331,
    CVT_D0_S1_R1_P	= 332,
    CVT_D0_S1_R2	= 333,
    CVT_D0_S1_R2_P	= 334,
    CVT_D0_S1_R3	= 335,
    CVT_D0_S1_R3_P	= 336,
    CVT_D0_S2_R1	= 337,
    CVT_D0_S2_R1_P	= 338,
    CVT_D0_S2_R2	= 339,
    CVT_D0_S2_R2_P	= 340,
    CVT_D0_S2_R3	= 341,
    CVT_D0_S2_R3_P	= 342,
    CVT_D0_S3_R1	= 343,
    CVT_D0_S3_R1_P	= 344,
    CVT_D0_S3_R2	= 345,
    CVT_D0_S3_R2_P	= 346,
    CVT_D0_S3_R3	= 347,
    CVT_D0_S3_R3_P	= 348,
    CVT_D1_S0_R0	= 349,
    CVT_D1_S0_R0_P	= 350,
    CVT_D1_S0_R0_W8_32	= 351,
    CVT_D1_S0_R1	= 352,
    CVT_D1_S0_R1_P	= 353,
    CVT_D1_S0_R2	= 354,
    CVT_D1_S0_R2_P	= 355,
    CVT_D1_S0_R3	= 356,
    CVT_D1_S0_R3_P	= 357,
    CVT_D1_S1_R0	= 358,
    CVT_D1_S1_R0_P	= 359,
    CVT_D1_S1_R1	= 360,
    CVT_D1_S1_R1_P	= 361,
    CVT_D1_S1_R2	= 362,
    CVT_D1_S1_R2_P	= 363,
    CVT_D1_S1_R3	= 364,
    CVT_D1_S1_R3_P	= 365,
    CVT_D1_S2_R0	= 366,
    CVT_D1_S2_R0_P	= 367,
    CVT_D1_S2_R1	= 368,
    CVT_D1_S2_R1_P	= 369,
    CVT_D1_S2_R2	= 370,
    CVT_D1_S2_R2_P	= 371,
    CVT_D1_S2_R3	= 372,
    CVT_D1_S2_R3_P	= 373,
    CVT_D1_S3_R0	= 374,
    CVT_D1_S3_R0_P	= 375,
    CVT_D1_S3_R1	= 376,
    CVT_D1_S3_R1_P	= 377,
    CVT_D1_S3_R2	= 378,
    CVT_D1_S3_R2_P	= 379,
    CVT_D1_S3_R3	= 380,
    CVT_D1_S3_R3_P	= 381,
    CVT_D2_S0_R0	= 382,
    CVT_D2_S0_R0_P	= 383,
    CVT_D2_S0_R2	= 384,
    CVT_D2_S0_R2_P	= 385,
    CVT_D2_S0_R3	= 386,
    CVT_D2_S0_R3_P	= 387,
    CVT_D2_S1_R0	= 388,
    CVT_D2_S1_R0_P	= 389,
    CVT_D2_S1_R1	= 390,
    CVT_D2_S1_R1_P	= 391,
    CVT_D2_S1_R2	= 392,
    CVT_D2_S1_R2_P	= 393,
    CVT_D2_S1_R3	= 394,
    CVT_D2_S1_R3_P	= 395,
    CVT_D2_S3_R0	= 396,
    CVT_D2_S3_R0_P	= 397,
    CVT_D3_S0_R0	= 398,
    CVT_D3_S0_R0_P	= 399,
    CVT_D3_S0_R2	= 400,
    CVT_D3_S0_R2_P	= 401,
    CVT_D3_S0_R3	= 402,
    CVT_D3_S0_R3_P	= 403,
    CVT_D3_S1_R0	= 404,
    CVT_D3_S1_R0_P	= 405,
    CVT_D3_S1_R1	= 406,
    CVT_D3_S1_R1_P	= 407,
    CVT_D3_S1_R2	= 408,
    CVT_D3_S1_R2_P	= 409,
    CVT_D3_S1_R3	= 410,
    CVT_D3_S1_R3_P	= 411,
    CVT_D3_S2_R0	= 412,
    CVT_D3_S2_R0_P	= 413,
    CVT_D3_S3_R0	= 414,
    CVT_D3_S3_R0_P	= 415,
    CVT_F32_S32	= 416,
    CVT_F32_S32_P	= 417,
    CVT_F32_U32	= 418,
    CVT_F32_U32_P	= 419,
    CVT_S32_F32	= 420,
    CVT_S32_F32_P	= 421,
    CVT_SEXT	= 422,
    CVT_U32_F32	= 423,
    CVT_U32_F32_P	= 424,
    C_ABS	= 425,
    C_ADD	= 426,
    C_ADDI	= 427,
    C_AND	= 428,
    C_ANDI	= 429,
    C_ANDN	= 430,
    C_BAR_ARRIVE	= 431,
    C_BAR_WAIT	= 432,
    C_BRA	= 433,
    C_CHWIDTH	= 434,
    C_EXIT	= 435,
    C_FADD	= 436,
    C_FENCE	= 437,
    C_FMAX	= 438,
    C_FMIN	= 439,
    C_FMUL	= 440,
    C_LD_GLOBAL	= 441,
    C_MAX_S	= 442,
    C_MAX_U	= 443,
    C_MIN_S	= 444,
    C_MIN_U	= 445,
    C_MOV	= 446,
    C_MUL_LO	= 447,
    C_NEG	= 448,
    C_NOT	= 449,
    C_OR	= 450,
    C_ORI	= 451,
    C_RECONV	= 452,
    C_RET	= 453,
    C_SHL	= 454,
    C_SHLI	= 455,
    C_SHR	= 456,
    C_SHRI	= 457,
    C_SRA	= 458,
    C_SRAI	= 459,
    C_ST_GLOBAL	= 460,
    C_SUB	= 461,
    C_SUBI	= 462,
    C_XOR	= 463,
    C_XORI	= 464,
    DP2_BF16	= 465,
    DP2_F16	= 466,
    DP4_ACC	= 467,
    DP4_E4M3	= 468,
    DP4_E5M2	= 469,
    DP4_SS	= 470,
    EX2_F32	= 471,
    FABS_F0	= 472,
    FABS_F1	= 473,
    FADD	= 474,
    FADD_F1	= 475,
    FADD_P	= 476,
    FFMA_ACC_F0	= 477,
    FFMA_ACC_F1	= 478,
    FFMA_F0	= 479,
    FFMA_F1	= 480,
    FMAX	= 481,
    FMAX_F1	= 482,
    FMIN	= 483,
    FMIN_F1	= 484,
    FMUL	= 485,
    FMUL_F1	= 486,
    FMUL_P	= 487,
    FNEG_F0	= 488,
    FNEG_F1	= 489,
    FSUB	= 490,
    FSUB_F1	= 491,
    FSUB_P	= 492,
    LD_GLOBAL	= 493,
    LD_GLOBAL_IDX	= 494,
    LD_GLOBAL_IDX_W16	= 495,
    LD_GLOBAL_IDX_W8	= 496,
    LD_GLOBAL_P	= 497,
    LD_GLOBAL_SLOT	= 498,
    LD_GLOBAL_SLOT_W16	= 499,
    LD_GLOBAL_SLOT_W8	= 500,
    LD_GLOBAL_W16	= 501,
    LD_GLOBAL_W8	= 502,
    LD_PRED_G	= 503,
    LD_PRED_S	= 504,
    LD_SHARED	= 505,
    LD_SHARED_IDX	= 506,
    LD_SHARED_W16	= 507,
    LD_SHARED_W8	= 508,
    LG2_F32	= 509,
    MADLO	= 510,
    MADLO_P	= 511,
    MAD_ACC	= 512,
    MAX_S	= 513,
    MAX_S_P	= 514,
    MAX_S_W16	= 515,
    MAX_U	= 516,
    MAX_U_P	= 517,
    MIN_S	= 518,
    MIN_S_P	= 519,
    MIN_S_W16	= 520,
    MIN_U	= 521,
    MIN_U_P	= 522,
    MOVI	= 523,
    MOVI48	= 524,
    MOV_P	= 525,
    MULI	= 526,
    MULI_P	= 527,
    MUL_HI_S	= 528,
    MUL_HI_S_P	= 529,
    MUL_HI_U	= 530,
    MUL_HI_U_P	= 531,
    MUL_LO	= 532,
    NEG	= 533,
    OR	= 534,
    ORI	= 535,
    ORI_P	= 536,
    OR_P	= 537,
    OR_W16	= 538,
    PACKI	= 539,
    PACKI_Z	= 540,
    PAND	= 541,
    PMOV	= 542,
    PMOV_IMM	= 543,
    POPC	= 544,
    POR	= 545,
    PXOR	= 546,
    RCP_F32	= 547,
    RCP_F32_P	= 548,
    RCP_U32	= 549,
    RSQRT_F32	= 550,
    SEL	= 551,
    SETP_EQ	= 552,
    SETP_EQ_F	= 553,
    SETP_EQ_F1	= 554,
    SETP_EQ_F1_NP	= 555,
    SETP_EQ_F_I	= 556,
    SETP_EQ_F_NP	= 557,
    SETP_EQ_F_NPI	= 558,
    SETP_EQ_I	= 559,
    SETP_EQ_NP	= 560,
    SETP_EQ_NPI	= 561,
    SETP_GE	= 562,
    SETP_GE_F	= 563,
    SETP_GE_F1	= 564,
    SETP_GE_F1_NP	= 565,
    SETP_GE_F_I	= 566,
    SETP_GE_F_NP	= 567,
    SETP_GE_F_NPI	= 568,
    SETP_GE_I	= 569,
    SETP_GE_NP	= 570,
    SETP_GE_NPI	= 571,
    SETP_GE_U	= 572,
    SETP_GE_U_I	= 573,
    SETP_GE_U_NP	= 574,
    SETP_GE_U_NPI	= 575,
    SETP_GT	= 576,
    SETP_GT_F	= 577,
    SETP_GT_F1	= 578,
    SETP_GT_F1_NP	= 579,
    SETP_GT_F_I	= 580,
    SETP_GT_F_NP	= 581,
    SETP_GT_F_NPI	= 582,
    SETP_GT_I	= 583,
    SETP_GT_NP	= 584,
    SETP_GT_NPI	= 585,
    SETP_GT_U	= 586,
    SETP_GT_U_I	= 587,
    SETP_GT_U_NP	= 588,
    SETP_GT_U_NPI	= 589,
    SETP_LE	= 590,
    SETP_LE_F	= 591,
    SETP_LE_F1	= 592,
    SETP_LE_F1_NP	= 593,
    SETP_LE_F_I	= 594,
    SETP_LE_F_NP	= 595,
    SETP_LE_F_NPI	= 596,
    SETP_LE_I	= 597,
    SETP_LE_NP	= 598,
    SETP_LE_NPI	= 599,
    SETP_LE_U	= 600,
    SETP_LE_U_I	= 601,
    SETP_LE_U_NP	= 602,
    SETP_LE_U_NPI	= 603,
    SETP_LT	= 604,
    SETP_LT_F	= 605,
    SETP_LT_F1	= 606,
    SETP_LT_F1_NP	= 607,
    SETP_LT_F_I	= 608,
    SETP_LT_F_NP	= 609,
    SETP_LT_F_NPI	= 610,
    SETP_LT_I	= 611,
    SETP_LT_NP	= 612,
    SETP_LT_NPI	= 613,
    SETP_LT_U	= 614,
    SETP_LT_U_I	= 615,
    SETP_LT_U_NP	= 616,
    SETP_LT_U_NPI	= 617,
    SETP_NE	= 618,
    SETP_NE_F	= 619,
    SETP_NE_F1	= 620,
    SETP_NE_F1_NP	= 621,
    SETP_NE_F_I	= 622,
    SETP_NE_F_NP	= 623,
    SETP_NE_F_NPI	= 624,
    SETP_NE_I	= 625,
    SETP_NE_NP	= 626,
    SETP_NE_NPI	= 627,
    SHFL_IDX	= 628,
    SHL	= 629,
    SHLI	= 630,
    SHLI_P	= 631,
    SHL_P	= 632,
    SHR	= 633,
    SHRI	= 634,
    SHRI_P	= 635,
    SHR_P	= 636,
    SIN_F32	= 637,
    SQRT_F32	= 638,
    SRA	= 639,
    SRAI	= 640,
    SRAI_P	= 641,
    SRA_P	= 642,
    SRD	= 643,
    ST_GLOBAL	= 644,
    ST_GLOBAL_IDX	= 645,
    ST_GLOBAL_IDX_W16	= 646,
    ST_GLOBAL_IDX_W8	= 647,
    ST_GLOBAL_SLOT	= 648,
    ST_GLOBAL_SLOT_W16	= 649,
    ST_GLOBAL_SLOT_W8	= 650,
    ST_GLOBAL_W16	= 651,
    ST_GLOBAL_W8	= 652,
    ST_PRED_G	= 653,
    ST_PRED_S	= 654,
    ST_SHARED	= 655,
    ST_SHARED_IDX	= 656,
    ST_SHARED_W16	= 657,
    ST_SHARED_W8	= 658,
    SUB	= 659,
    SUBI	= 660,
    SUBI_P	= 661,
    SUB_P	= 662,
    SUB_W16	= 663,
    UNBALLOT	= 664,
    UNPACKI	= 665,
    VOTE_ANY	= 666,
    XOR	= 667,
    XORI	= 668,
    XORI_P	= 669,
    XOR_P	= 670,
    XOR_W16	= 671,
    INSTRUCTION_LIST_END = 672
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
  MCInstrDesc Insts[672];
  static_assert(alignof(MCInstrDesc) >= alignof(MCOperandInfo), "Unwanted padding between Insts and OperandInfo");
  MCOperandInfo OperandInfo[321];
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
    { 671,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #671 = XOR_W16
    { 670,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #670 = XOR_P
    { 669,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #669 = XORI_P
    { 668,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #668 = XORI
    { 667,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #667 = XOR
    { 666,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	318,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #666 = VOTE_ANY
    { 665,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #665 = UNPACKI
    { 664,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	315,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #664 = UNBALLOT
    { 663,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #663 = SUB_W16
    { 662,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #662 = SUB_P
    { 661,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #661 = SUBI_P
    { 660,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #660 = SUBI
    { 659,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #659 = SUB
    { 658,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #658 = ST_SHARED_W8
    { 657,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	273,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #657 = ST_SHARED_W16
    { 656,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #656 = ST_SHARED_IDX
    { 655,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #655 = ST_SHARED
    { 654,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #654 = ST_PRED_S
    { 653,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #653 = ST_PRED_G
    { 652,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #652 = ST_GLOBAL_W8
    { 651,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	273,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #651 = ST_GLOBAL_W16
    { 650,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #650 = ST_GLOBAL_SLOT_W8
    { 649,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #649 = ST_GLOBAL_SLOT_W16
    { 648,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #648 = ST_GLOBAL_SLOT
    { 647,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #647 = ST_GLOBAL_IDX_W8
    { 646,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	248,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #646 = ST_GLOBAL_IDX_W16
    { 645,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #645 = ST_GLOBAL_IDX
    { 644,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #644 = ST_GLOBAL
    { 643,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #643 = SRD
    { 642,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #642 = SRA_P
    { 641,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #641 = SRAI_P
    { 640,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #640 = SRAI
    { 639,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #639 = SRA
    { 638,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #638 = SQRT_F32
    { 637,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #637 = SIN_F32
    { 636,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #636 = SHR_P
    { 635,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #635 = SHRI_P
    { 634,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #634 = SHRI
    { 633,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #633 = SHR
    { 632,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #632 = SHL_P
    { 631,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #631 = SHLI_P
    { 630,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #630 = SHLI
    { 629,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #629 = SHL
    { 628,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #628 = SHFL_IDX
    { 627,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #627 = SETP_NE_NPI
    { 626,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #626 = SETP_NE_NP
    { 625,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #625 = SETP_NE_I
    { 624,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #624 = SETP_NE_F_NPI
    { 623,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #623 = SETP_NE_F_NP
    { 622,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #622 = SETP_NE_F_I
    { 621,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #621 = SETP_NE_F1_NP
    { 620,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #620 = SETP_NE_F1
    { 619,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #619 = SETP_NE_F
    { 618,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #618 = SETP_NE
    { 617,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #617 = SETP_LT_U_NPI
    { 616,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #616 = SETP_LT_U_NP
    { 615,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #615 = SETP_LT_U_I
    { 614,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #614 = SETP_LT_U
    { 613,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #613 = SETP_LT_NPI
    { 612,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #612 = SETP_LT_NP
    { 611,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #611 = SETP_LT_I
    { 610,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #610 = SETP_LT_F_NPI
    { 609,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #609 = SETP_LT_F_NP
    { 608,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #608 = SETP_LT_F_I
    { 607,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #607 = SETP_LT_F1_NP
    { 606,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #606 = SETP_LT_F1
    { 605,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #605 = SETP_LT_F
    { 604,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #604 = SETP_LT
    { 603,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #603 = SETP_LE_U_NPI
    { 602,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #602 = SETP_LE_U_NP
    { 601,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #601 = SETP_LE_U_I
    { 600,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #600 = SETP_LE_U
    { 599,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #599 = SETP_LE_NPI
    { 598,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #598 = SETP_LE_NP
    { 597,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #597 = SETP_LE_I
    { 596,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #596 = SETP_LE_F_NPI
    { 595,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #595 = SETP_LE_F_NP
    { 594,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #594 = SETP_LE_F_I
    { 593,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #593 = SETP_LE_F1_NP
    { 592,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #592 = SETP_LE_F1
    { 591,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #591 = SETP_LE_F
    { 590,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #590 = SETP_LE
    { 589,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #589 = SETP_GT_U_NPI
    { 588,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #588 = SETP_GT_U_NP
    { 587,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #587 = SETP_GT_U_I
    { 586,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #586 = SETP_GT_U
    { 585,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #585 = SETP_GT_NPI
    { 584,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #584 = SETP_GT_NP
    { 583,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #583 = SETP_GT_I
    { 582,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #582 = SETP_GT_F_NPI
    { 581,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #581 = SETP_GT_F_NP
    { 580,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #580 = SETP_GT_F_I
    { 579,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #579 = SETP_GT_F1_NP
    { 578,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #578 = SETP_GT_F1
    { 577,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #577 = SETP_GT_F
    { 576,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #576 = SETP_GT
    { 575,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #575 = SETP_GE_U_NPI
    { 574,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #574 = SETP_GE_U_NP
    { 573,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #573 = SETP_GE_U_I
    { 572,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #572 = SETP_GE_U
    { 571,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #571 = SETP_GE_NPI
    { 570,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #570 = SETP_GE_NP
    { 569,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #569 = SETP_GE_I
    { 568,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #568 = SETP_GE_F_NPI
    { 567,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #567 = SETP_GE_F_NP
    { 566,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #566 = SETP_GE_F_I
    { 565,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #565 = SETP_GE_F1_NP
    { 564,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #564 = SETP_GE_F1
    { 563,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #563 = SETP_GE_F
    { 562,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #562 = SETP_GE
    { 561,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #561 = SETP_EQ_NPI
    { 560,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #560 = SETP_EQ_NP
    { 559,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #559 = SETP_EQ_I
    { 558,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #558 = SETP_EQ_F_NPI
    { 557,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #557 = SETP_EQ_F_NP
    { 556,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	306,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #556 = SETP_EQ_F_I
    { 555,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #555 = SETP_EQ_F1_NP
    { 554,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #554 = SETP_EQ_F1
    { 553,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #553 = SETP_EQ_F
    { 552,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #552 = SETP_EQ
    { 551,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #551 = SEL
    { 550,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #550 = RSQRT_F32
    { 549,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #549 = RCP_U32
    { 548,	5,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #548 = RCP_F32_P
    { 547,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #547 = RCP_F32
    { 546,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	292,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #546 = PXOR
    { 545,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	292,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #545 = POR
    { 544,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #544 = POPC
    { 543,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #543 = PMOV_IMM
    { 542,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	292,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #542 = PMOV
    { 541,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	292,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #541 = PAND
    { 540,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #540 = PACKI_Z
    { 539,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	288,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #539 = PACKI
    { 538,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #538 = OR_W16
    { 537,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #537 = OR_P
    { 536,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #536 = ORI_P
    { 535,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #535 = ORI
    { 534,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #534 = OR
    { 533,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #533 = NEG
    { 532,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #532 = MUL_LO
    { 531,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #531 = MUL_HI_U_P
    { 530,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #530 = MUL_HI_U
    { 529,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #529 = MUL_HI_S_P
    { 528,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #528 = MUL_HI_S
    { 527,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #527 = MULI_P
    { 526,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #526 = MULI
    { 525,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	282,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #525 = MOV_P
    { 524,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #524 = MOVI48
    { 523,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #523 = MOVI
    { 522,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #522 = MIN_U_P
    { 521,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #521 = MIN_U
    { 520,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #520 = MIN_S_W16
    { 519,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #519 = MIN_S_P
    { 518,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #518 = MIN_S
    { 517,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #517 = MAX_U_P
    { 516,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #516 = MAX_U
    { 515,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #515 = MAX_S_W16
    { 514,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #514 = MAX_S_P
    { 513,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #513 = MAX_S
    { 512,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	239,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #512 = MAD_ACC
    { 511,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #511 = MADLO_P
    { 510,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #510 = MADLO
    { 509,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #509 = LG2_F32
    { 508,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #508 = LD_SHARED_W8
    { 507,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	273,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #507 = LD_SHARED_W16
    { 506,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #506 = LD_SHARED_IDX
    { 505,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #505 = LD_SHARED
    { 504,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #504 = LD_PRED_S
    { 503,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #503 = LD_PRED_G
    { 502,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #502 = LD_GLOBAL_W8
    { 501,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	273,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #501 = LD_GLOBAL_W16
    { 500,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	268,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #500 = LD_GLOBAL_SLOT_W8
    { 499,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #499 = LD_GLOBAL_SLOT_W16
    { 498,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #498 = LD_GLOBAL_SLOT
    { 497,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #497 = LD_GLOBAL_P
    { 496,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #496 = LD_GLOBAL_IDX_W8
    { 495,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	248,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #495 = LD_GLOBAL_IDX_W16
    { 494,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #494 = LD_GLOBAL_IDX
    { 493,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #493 = LD_GLOBAL
    { 492,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #492 = FSUB_P
    { 491,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #491 = FSUB_F1
    { 490,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #490 = FSUB
    { 489,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #489 = FNEG_F1
    { 488,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #488 = FNEG_F0
    { 487,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #487 = FMUL_P
    { 486,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #486 = FMUL_F1
    { 485,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #485 = FMUL
    { 484,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #484 = FMIN_F1
    { 483,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #483 = FMIN
    { 482,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #482 = FMAX_F1
    { 481,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #481 = FMAX
    { 480,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #480 = FFMA_F1
    { 479,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #479 = FFMA_F0
    { 478,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	239,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #478 = FFMA_ACC_F1
    { 477,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	239,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #477 = FFMA_ACC_F0
    { 476,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #476 = FADD_P
    { 475,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #475 = FADD_F1
    { 474,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #474 = FADD
    { 473,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #473 = FABS_F1
    { 472,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #472 = FABS_F0
    { 471,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #471 = EX2_F32
    { 470,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #470 = DP4_SS
    { 469,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #469 = DP4_E5M2
    { 468,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #468 = DP4_E4M3
    { 467,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	239,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #467 = DP4_ACC
    { 466,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #466 = DP2_F16
    { 465,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #465 = DP2_BF16
    { 464,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #464 = C_XORI
    { 463,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #463 = C_XOR
    { 462,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #462 = C_SUBI
    { 461,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #461 = C_SUB
    { 460,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #460 = C_ST_GLOBAL
    { 459,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #459 = C_SRAI
    { 458,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #458 = C_SRA
    { 457,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #457 = C_SHRI
    { 456,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #456 = C_SHR
    { 455,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #455 = C_SHLI
    { 454,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #454 = C_SHL
    { 453,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #453 = C_RET
    { 452,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #452 = C_RECONV
    { 451,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #451 = C_ORI
    { 450,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #450 = C_OR
    { 449,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #449 = C_NOT
    { 448,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #448 = C_NEG
    { 447,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #447 = C_MUL_LO
    { 446,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #446 = C_MOV
    { 445,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #445 = C_MIN_U
    { 444,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #444 = C_MIN_S
    { 443,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #443 = C_MAX_U
    { 442,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #442 = C_MAX_S
    { 441,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #441 = C_LD_GLOBAL
    { 440,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #440 = C_FMUL
    { 439,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #439 = C_FMIN
    { 438,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #438 = C_FMAX
    { 437,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #437 = C_FENCE
    { 436,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #436 = C_FADD
    { 435,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #435 = C_EXIT
    { 434,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #434 = C_CHWIDTH
    { 433,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #433 = C_BRA
    { 432,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #432 = C_BAR_WAIT
    { 431,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #431 = C_BAR_ARRIVE
    { 430,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #430 = C_ANDN
    { 429,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #429 = C_ANDI
    { 428,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #428 = C_AND
    { 427,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	236,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #427 = C_ADDI
    { 426,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #426 = C_ADD
    { 425,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #425 = C_ABS
    { 424,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #424 = CVT_U32_F32_P
    { 423,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #423 = CVT_U32_F32
    { 422,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	221,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #422 = CVT_SEXT
    { 421,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #421 = CVT_S32_F32_P
    { 420,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #420 = CVT_S32_F32
    { 419,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #419 = CVT_F32_U32_P
    { 418,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #418 = CVT_F32_U32
    { 417,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #417 = CVT_F32_S32_P
    { 416,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #416 = CVT_F32_S32
    { 415,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #415 = CVT_D3_S3_R0_P
    { 414,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #414 = CVT_D3_S3_R0
    { 413,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #413 = CVT_D3_S2_R0_P
    { 412,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #412 = CVT_D3_S2_R0
    { 411,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #411 = CVT_D3_S1_R3_P
    { 410,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #410 = CVT_D3_S1_R3
    { 409,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #409 = CVT_D3_S1_R2_P
    { 408,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #408 = CVT_D3_S1_R2
    { 407,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #407 = CVT_D3_S1_R1_P
    { 406,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #406 = CVT_D3_S1_R1
    { 405,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #405 = CVT_D3_S1_R0_P
    { 404,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #404 = CVT_D3_S1_R0
    { 403,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #403 = CVT_D3_S0_R3_P
    { 402,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #402 = CVT_D3_S0_R3
    { 401,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #401 = CVT_D3_S0_R2_P
    { 400,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #400 = CVT_D3_S0_R2
    { 399,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #399 = CVT_D3_S0_R0_P
    { 398,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #398 = CVT_D3_S0_R0
    { 397,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #397 = CVT_D2_S3_R0_P
    { 396,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #396 = CVT_D2_S3_R0
    { 395,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #395 = CVT_D2_S1_R3_P
    { 394,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #394 = CVT_D2_S1_R3
    { 393,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #393 = CVT_D2_S1_R2_P
    { 392,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #392 = CVT_D2_S1_R2
    { 391,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #391 = CVT_D2_S1_R1_P
    { 390,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #390 = CVT_D2_S1_R1
    { 389,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #389 = CVT_D2_S1_R0_P
    { 388,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #388 = CVT_D2_S1_R0
    { 387,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #387 = CVT_D2_S0_R3_P
    { 386,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #386 = CVT_D2_S0_R3
    { 385,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #385 = CVT_D2_S0_R2_P
    { 384,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #384 = CVT_D2_S0_R2
    { 383,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #383 = CVT_D2_S0_R0_P
    { 382,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #382 = CVT_D2_S0_R0
    { 381,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #381 = CVT_D1_S3_R3_P
    { 380,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #380 = CVT_D1_S3_R3
    { 379,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #379 = CVT_D1_S3_R2_P
    { 378,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #378 = CVT_D1_S3_R2
    { 377,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #377 = CVT_D1_S3_R1_P
    { 376,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #376 = CVT_D1_S3_R1
    { 375,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #375 = CVT_D1_S3_R0_P
    { 374,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #374 = CVT_D1_S3_R0
    { 373,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #373 = CVT_D1_S2_R3_P
    { 372,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #372 = CVT_D1_S2_R3
    { 371,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #371 = CVT_D1_S2_R2_P
    { 370,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #370 = CVT_D1_S2_R2
    { 369,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #369 = CVT_D1_S2_R1_P
    { 368,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #368 = CVT_D1_S2_R1
    { 367,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #367 = CVT_D1_S2_R0_P
    { 366,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #366 = CVT_D1_S2_R0
    { 365,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #365 = CVT_D1_S1_R3_P
    { 364,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #364 = CVT_D1_S1_R3
    { 363,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #363 = CVT_D1_S1_R2_P
    { 362,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #362 = CVT_D1_S1_R2
    { 361,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #361 = CVT_D1_S1_R1_P
    { 360,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #360 = CVT_D1_S1_R1
    { 359,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #359 = CVT_D1_S1_R0_P
    { 358,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #358 = CVT_D1_S1_R0
    { 357,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #357 = CVT_D1_S0_R3_P
    { 356,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #356 = CVT_D1_S0_R3
    { 355,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #355 = CVT_D1_S0_R2_P
    { 354,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #354 = CVT_D1_S0_R2
    { 353,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #353 = CVT_D1_S0_R1_P
    { 352,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #352 = CVT_D1_S0_R1
    { 351,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	229,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #351 = CVT_D1_S0_R0_W8_32
    { 350,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #350 = CVT_D1_S0_R0_P
    { 349,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #349 = CVT_D1_S0_R0
    { 348,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #348 = CVT_D0_S3_R3_P
    { 347,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #347 = CVT_D0_S3_R3
    { 346,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #346 = CVT_D0_S3_R2_P
    { 345,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #345 = CVT_D0_S3_R2
    { 344,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #344 = CVT_D0_S3_R1_P
    { 343,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #343 = CVT_D0_S3_R1
    { 342,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #342 = CVT_D0_S2_R3_P
    { 341,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #341 = CVT_D0_S2_R3
    { 340,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #340 = CVT_D0_S2_R2_P
    { 339,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #339 = CVT_D0_S2_R2
    { 338,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #338 = CVT_D0_S2_R1_P
    { 337,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #337 = CVT_D0_S2_R1
    { 336,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #336 = CVT_D0_S1_R3_P
    { 335,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #335 = CVT_D0_S1_R3
    { 334,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #334 = CVT_D0_S1_R2_P
    { 333,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #333 = CVT_D0_S1_R2
    { 332,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #332 = CVT_D0_S1_R1_P
    { 331,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #331 = CVT_D0_S1_R1
    { 330,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	225,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #330 = CVT_D0_S1_R0_W32_8
    { 329,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #329 = CVT_D0_S1_R0_W16_8
    { 328,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #328 = CVT_D0_S1_R0_P
    { 327,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #327 = CVT_D0_S1_R0
    { 326,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #326 = CVT_D0_S0_R3_P
    { 325,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #325 = CVT_D0_S0_R3
    { 324,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #324 = CVT_D0_S0_R2_P
    { 323,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #323 = CVT_D0_S0_R2
    { 322,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #322 = CVT_D0_S0_R1_P
    { 321,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #321 = CVT_D0_S0_R1
    { 320,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	229,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #320 = CVT_D0_S0_R0_W8_32
    { 319,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	225,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #319 = CVT_D0_S0_R0_W32_8
    { 318,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	221,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #318 = CVT_D0_S0_R0_W32_16
    { 317,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #317 = CVT_D0_S0_R0_W16_8
    { 316,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #316 = CVT_D0_S0_R0_W16_32
    { 315,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #315 = CVT_D0_S0_R0_P
    { 314,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #314 = CVT_D0_S0_R0
    { 313,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #313 = COS_F32
    { 312,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #312 = CLZ
    { 311,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #311 = CHWIDTH_MULTI
    { 310,	7,	2,	6,	0,	0,	0,	CCVImpOpBase + 0,	206,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #310 = CAS_G
    { 309,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #309 = CALL
    { 308,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #308 = BREV
    { 307,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	202,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #307 = BRA_PRED
    { 306,	1,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #306 = BRA
    { 305,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	199,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #305 = BAR_WAIT_PHASE
    { 304,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #304 = BAR_INIT
    { 303,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	196,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #303 = BALLOT
    { 302,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	192,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #302 = ATOM_ADD_G
    { 301,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #301 = AND_W16
    { 300,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #300 = AND_P
    { 299,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #299 = ANDNI_P
    { 298,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #298 = ANDNI
    { 297,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #297 = ANDN
    { 296,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #296 = ANDI_P
    { 295,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #295 = ANDI
    { 294,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #294 = AND
    { 293,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #293 = ADD_W16
    { 292,	6,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #292 = ADD_PP
    { 291,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #291 = ADD_P
    { 290,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	174,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #290 = ADDI_W16
    { 289,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	169,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #289 = ADDI_PP
    { 288,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #288 = ADDI_P
    { 287,	3,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #287 = ADDI48
    { 286,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #286 = ADDI
    { 285,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #285 = ADD
    { 284,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #284 = ABS
    { 283,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #283 = PSEUDO_ST_PRED
    { 282,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #282 = PSEUDO_RET
    { 281,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	150,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #281 = PSEUDO_PXOR
    { 280,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	150,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #280 = PSEUDO_POR
    { 279,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	153,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #279 = PSEUDO_PMOV
    { 278,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	150,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #278 = PSEUDO_PAND
    { 277,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #277 = PSEUDO_NARROW
    { 276,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #276 = PSEUDO_LD_PRED
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
    /* 145 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 148 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 150 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 153 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 157 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 158 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 162 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 165 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 169 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 174 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 177 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 182 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 188 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 192 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 196 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 199 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 202 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 204 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 206 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 213 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 217 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 221 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 225 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 229 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 233 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 236 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 239 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 243 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 248 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 253 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 258 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 263 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 268 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 273 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 276 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 279 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 282 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 288 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 292 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 295 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 297 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 302 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 306 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 311 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 315 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 318 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
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
  /* 601 */ "CVT_D0_S0_R0_W16_32\0"
  /* 621 */ "CVT_D0_S0_R0_W8_32\0"
  /* 640 */ "CVT_D1_S0_R0_W8_32\0"
  /* 659 */ "G_FLOG2\0"
  /* 667 */ "DP4_E5M2\0"
  /* 676 */ "G_FEXP2\0"
  /* 684 */ "CVT_D0_S0_R2\0"
  /* 697 */ "CVT_D1_S0_R2\0"
  /* 710 */ "CVT_D2_S0_R2\0"
  /* 723 */ "CVT_D3_S0_R2\0"
  /* 736 */ "CVT_D0_S1_R2\0"
  /* 749 */ "CVT_D1_S1_R2\0"
  /* 762 */ "CVT_D2_S1_R2\0"
  /* 775 */ "CVT_D3_S1_R2\0"
  /* 788 */ "CVT_D0_S2_R2\0"
  /* 801 */ "CVT_D1_S2_R2\0"
  /* 814 */ "CVT_D0_S3_R2\0"
  /* 827 */ "CVT_D1_S3_R2\0"
  /* 840 */ "DP4_E4M3\0"
  /* 849 */ "CVT_D0_S0_R3\0"
  /* 862 */ "CVT_D1_S0_R3\0"
  /* 875 */ "CVT_D2_S0_R3\0"
  /* 888 */ "CVT_D3_S0_R3\0"
  /* 901 */ "CVT_D0_S1_R3\0"
  /* 914 */ "CVT_D1_S1_R3\0"
  /* 927 */ "CVT_D2_S1_R3\0"
  /* 940 */ "CVT_D3_S1_R3\0"
  /* 953 */ "CVT_D0_S2_R3\0"
  /* 966 */ "CVT_D1_S2_R3\0"
  /* 979 */ "CVT_D0_S3_R3\0"
  /* 992 */ "CVT_D1_S3_R3\0"
  /* 1005 */ "DP2_BF16\0"
  /* 1014 */ "DP2_F16\0"
  /* 1022 */ "SUB_W16\0"
  /* 1030 */ "ADD_W16\0"
  /* 1038 */ "LD_SHARED_W16\0"
  /* 1052 */ "ST_SHARED_W16\0"
  /* 1066 */ "AND_W16\0"
  /* 1074 */ "ADDI_W16\0"
  /* 1083 */ "LD_GLOBAL_W16\0"
  /* 1097 */ "ST_GLOBAL_W16\0"
  /* 1111 */ "XOR_W16\0"
  /* 1119 */ "MIN_S_W16\0"
  /* 1129 */ "MAX_S_W16\0"
  /* 1139 */ "LD_GLOBAL_SLOT_W16\0"
  /* 1158 */ "ST_GLOBAL_SLOT_W16\0"
  /* 1177 */ "LD_GLOBAL_IDX_W16\0"
  /* 1195 */ "ST_GLOBAL_IDX_W16\0"
  /* 1213 */ "CVT_D0_S0_R0_W32_16\0"
  /* 1233 */ "ADDI48\0"
  /* 1240 */ "MOVI48\0"
  /* 1247 */ "LD_SHARED_W8\0"
  /* 1260 */ "ST_SHARED_W8\0"
  /* 1273 */ "LD_GLOBAL_W8\0"
  /* 1286 */ "ST_GLOBAL_W8\0"
  /* 1299 */ "LD_GLOBAL_SLOT_W8\0"
  /* 1317 */ "ST_GLOBAL_SLOT_W8\0"
  /* 1335 */ "LD_GLOBAL_IDX_W8\0"
  /* 1352 */ "ST_GLOBAL_IDX_W8\0"
  /* 1369 */ "CVT_D0_S0_R0_W32_8\0"
  /* 1388 */ "CVT_D0_S1_R0_W32_8\0"
  /* 1407 */ "CVT_D0_S0_R0_W16_8\0"
  /* 1426 */ "CVT_D0_S1_R0_W16_8\0"
  /* 1445 */ "G_FMA\0"
  /* 1451 */ "G_STRICT_FMA\0"
  /* 1464 */ "C_BRA\0"
  /* 1470 */ "C_SRA\0"
  /* 1476 */ "G_FSUB\0"
  /* 1483 */ "G_STRICT_FSUB\0"
  /* 1497 */ "G_ATOMICRMW_FSUB\0"
  /* 1514 */ "C_SUB\0"
  /* 1520 */ "G_SUB\0"
  /* 1526 */ "G_ATOMICRMW_SUB\0"
  /* 1542 */ "DP4_ACC\0"
  /* 1550 */ "MAD_ACC\0"
  /* 1558 */ "G_INTRINSIC\0"
  /* 1570 */ "G_FPTRUNC\0"
  /* 1580 */ "G_INTRINSIC_TRUNC\0"
  /* 1598 */ "G_TRUNC\0"
  /* 1606 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 1627 */ "G_DYN_STACKALLOC\0"
  /* 1644 */ "POPC\0"
  /* 1649 */ "G_FMAD\0"
  /* 1656 */ "G_INDEXED_SEXTLOAD\0"
  /* 1675 */ "G_SEXTLOAD\0"
  /* 1686 */ "G_INDEXED_ZEXTLOAD\0"
  /* 1705 */ "G_ZEXTLOAD\0"
  /* 1716 */ "G_INDEXED_LOAD\0"
  /* 1731 */ "G_LOAD\0"
  /* 1738 */ "C_FADD\0"
  /* 1745 */ "G_VECREDUCE_FADD\0"
  /* 1762 */ "G_FADD\0"
  /* 1769 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 1790 */ "G_STRICT_FADD\0"
  /* 1804 */ "G_ATOMICRMW_FADD\0"
  /* 1821 */ "C_ADD\0"
  /* 1827 */ "G_VECREDUCE_ADD\0"
  /* 1843 */ "G_ADD\0"
  /* 1849 */ "G_PTR_ADD\0"
  /* 1859 */ "G_ATOMICRMW_ADD\0"
  /* 1875 */ "LD_SHARED\0"
  /* 1885 */ "ST_SHARED\0"
  /* 1895 */ "PSEUDO_BRA_PRED\0"
  /* 1911 */ "PSEUDO_LD_PRED\0"
  /* 1926 */ "PSEUDO_ST_PRED\0"
  /* 1941 */ "G_ATOMICRMW_NAND\0"
  /* 1958 */ "PSEUDO_PAND\0"
  /* 1970 */ "C_AND\0"
  /* 1976 */ "G_VECREDUCE_AND\0"
  /* 1992 */ "G_AND\0"
  /* 1998 */ "G_ATOMICRMW_AND\0"
  /* 2014 */ "LIFETIME_END\0"
  /* 2027 */ "G_BRCOND\0"
  /* 2036 */ "G_LLROUND\0"
  /* 2046 */ "G_LROUND\0"
  /* 2055 */ "G_INTRINSIC_ROUND\0"
  /* 2073 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 2099 */ "LOAD_STACK_GUARD\0"
  /* 2116 */ "SRD\0"
  /* 2120 */ "PSEUDO_PROBE\0"
  /* 2133 */ "G_SSUBE\0"
  /* 2141 */ "G_USUBE\0"
  /* 2149 */ "C_FENCE\0"
  /* 2157 */ "G_FENCE\0"
  /* 2165 */ "ARITH_FENCE\0"
  /* 2177 */ "REG_SEQUENCE\0"
  /* 2190 */ "G_SADDE\0"
  /* 2198 */ "G_UADDE\0"
  /* 2206 */ "G_GET_FPMODE\0"
  /* 2219 */ "G_RESET_FPMODE\0"
  /* 2234 */ "G_SET_FPMODE\0"
  /* 2247 */ "G_FMINNUM_IEEE\0"
  /* 2262 */ "G_FMAXNUM_IEEE\0"
  /* 2277 */ "SETP_GE\0"
  /* 2285 */ "G_JUMP_TABLE\0"
  /* 2298 */ "BUNDLE\0"
  /* 2305 */ "SETP_LE\0"
  /* 2313 */ "G_MEMCPY_INLINE\0"
  /* 2329 */ "SETP_NE\0"
  /* 2337 */ "LOCAL_ESCAPE\0"
  /* 2350 */ "G_STACKRESTORE\0"
  /* 2365 */ "G_INDEXED_STORE\0"
  /* 2381 */ "G_STORE\0"
  /* 2389 */ "BAR_WAIT_PHASE\0"
  /* 2404 */ "G_BITREVERSE\0"
  /* 2417 */ "DBG_VALUE\0"
  /* 2427 */ "G_GLOBAL_VALUE\0"
  /* 2442 */ "G_STACKSAVE\0"
  /* 2454 */ "C_BAR_ARRIVE\0"
  /* 2467 */ "G_MEMMOVE\0"
  /* 2477 */ "G_FREEZE\0"
  /* 2486 */ "G_FCANONICALIZE\0"
  /* 2502 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 2520 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 2538 */ "G_IMPLICIT_DEF\0"
  /* 2553 */ "DBG_INSTR_REF\0"
  /* 2567 */ "SETP_GE_F\0"
  /* 2577 */ "SETP_LE_F\0"
  /* 2587 */ "SETP_NE_F\0"
  /* 2597 */ "SETP_EQ_F\0"
  /* 2607 */ "SETP_GT_F\0"
  /* 2617 */ "SETP_LT_F\0"
  /* 2627 */ "G_FNEG\0"
  /* 2634 */ "C_NEG\0"
  /* 2640 */ "EXTRACT_SUBREG\0"
  /* 2655 */ "INSERT_SUBREG\0"
  /* 2669 */ "G_SEXT_INREG\0"
  /* 2682 */ "SUBREG_TO_REG\0"
  /* 2696 */ "G_ATOMIC_CMPXCHG\0"
  /* 2713 */ "G_ATOMICRMW_XCHG\0"
  /* 2730 */ "G_FLOG\0"
  /* 2737 */ "G_VAARG\0"
  /* 2745 */ "PREALLOCATED_ARG\0"
  /* 2762 */ "ATOM_ADD_G\0"
  /* 2773 */ "LD_PRED_G\0"
  /* 2783 */ "ST_PRED_G\0"
  /* 2793 */ "CAS_G\0"
  /* 2799 */ "G_PREFETCH\0"
  /* 2810 */ "G_SMULH\0"
  /* 2818 */ "G_UMULH\0"
  /* 2826 */ "C_CHWIDTH\0"
  /* 2836 */ "C_SRAI\0"
  /* 2843 */ "C_SUBI\0"
  /* 2850 */ "C_ADDI\0"
  /* 2857 */ "C_ANDI\0"
  /* 2864 */ "DBG_PHI\0"
  /* 2872 */ "UNPACKI\0"
  /* 2880 */ "C_SHLI\0"
  /* 2887 */ "MULI\0"
  /* 2892 */ "ANDNI\0"
  /* 2898 */ "SETP_GE_NPI\0"
  /* 2910 */ "SETP_LE_NPI\0"
  /* 2922 */ "SETP_NE_NPI\0"
  /* 2934 */ "SETP_GE_F_NPI\0"
  /* 2948 */ "SETP_LE_F_NPI\0"
  /* 2962 */ "SETP_NE_F_NPI\0"
  /* 2976 */ "SETP_EQ_F_NPI\0"
  /* 2990 */ "SETP_GT_F_NPI\0"
  /* 3004 */ "SETP_LT_F_NPI\0"
  /* 3018 */ "SETP_EQ_NPI\0"
  /* 3030 */ "SETP_GT_NPI\0"
  /* 3042 */ "SETP_LT_NPI\0"
  /* 3054 */ "SETP_GE_U_NPI\0"
  /* 3068 */ "SETP_LE_U_NPI\0"
  /* 3082 */ "SETP_GT_U_NPI\0"
  /* 3096 */ "SETP_LT_U_NPI\0"
  /* 3110 */ "C_SHRI\0"
  /* 3117 */ "C_XORI\0"
  /* 3124 */ "C_ORI\0"
  /* 3130 */ "G_FPTOSI\0"
  /* 3139 */ "CHWIDTH_MULTI\0"
  /* 3153 */ "G_FPTOUI\0"
  /* 3162 */ "MOVI\0"
  /* 3167 */ "G_FPOWI\0"
  /* 3175 */ "SETP_GE_I\0"
  /* 3185 */ "SETP_LE_I\0"
  /* 3195 */ "SETP_NE_I\0"
  /* 3205 */ "SETP_GE_F_I\0"
  /* 3217 */ "SETP_LE_F_I\0"
  /* 3229 */ "SETP_NE_F_I\0"
  /* 3241 */ "SETP_EQ_F_I\0"
  /* 3253 */ "SETP_GT_F_I\0"
  /* 3265 */ "SETP_LT_F_I\0"
  /* 3277 */ "SETP_EQ_I\0"
  /* 3287 */ "SETP_GT_I\0"
  /* 3297 */ "SETP_LT_I\0"
  /* 3307 */ "SETP_GE_U_I\0"
  /* 3319 */ "SETP_LE_U_I\0"
  /* 3331 */ "SETP_GT_U_I\0"
  /* 3343 */ "SETP_LT_U_I\0"
  /* 3355 */ "G_PTRMASK\0"
  /* 3365 */ "C_LD_GLOBAL\0"
  /* 3377 */ "C_ST_GLOBAL\0"
  /* 3389 */ "GC_LABEL\0"
  /* 3398 */ "DBG_LABEL\0"
  /* 3408 */ "EH_LABEL\0"
  /* 3417 */ "ANNOTATION_LABEL\0"
  /* 3434 */ "ICALL_BRANCH_FUNNEL\0"
  /* 3454 */ "SEL\0"
  /* 3458 */ "G_FSHL\0"
  /* 3465 */ "C_SHL\0"
  /* 3471 */ "G_SHL\0"
  /* 3477 */ "G_FCEIL\0"
  /* 3485 */ "PATCHABLE_TAIL_CALL\0"
  /* 3505 */ "PSEUDO_CALL\0"
  /* 3517 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 3544 */ "PATCHABLE_EVENT_CALL\0"
  /* 3565 */ "FENTRY_CALL\0"
  /* 3577 */ "KILL\0"
  /* 3582 */ "G_CONSTANT_POOL\0"
  /* 3598 */ "G_ROTL\0"
  /* 3605 */ "C_FMUL\0"
  /* 3612 */ "G_VECREDUCE_FMUL\0"
  /* 3629 */ "G_FMUL\0"
  /* 3636 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 3657 */ "G_STRICT_FMUL\0"
  /* 3671 */ "G_VECREDUCE_MUL\0"
  /* 3687 */ "G_MUL\0"
  /* 3693 */ "G_FREM\0"
  /* 3700 */ "G_STRICT_FREM\0"
  /* 3714 */ "G_SREM\0"
  /* 3721 */ "G_UREM\0"
  /* 3728 */ "G_SDIVREM\0"
  /* 3738 */ "G_UDIVREM\0"
  /* 3748 */ "PMOV_IMM\0"
  /* 3757 */ "INLINEASM\0"
  /* 3767 */ "G_VECREDUCE_FMINIMUM\0"
  /* 3788 */ "G_FMINIMUM\0"
  /* 3799 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 3820 */ "G_FMAXIMUM\0"
  /* 3831 */ "G_FMINNUM\0"
  /* 3841 */ "G_FMAXNUM\0"
  /* 3851 */ "C_ANDN\0"
  /* 3858 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 3880 */ "G_ASSERT_ALIGN\0"
  /* 3895 */ "G_FCOPYSIGN\0"
  /* 3907 */ "C_FMIN\0"
  /* 3914 */ "G_VECREDUCE_FMIN\0"
  /* 3931 */ "G_ATOMICRMW_FMIN\0"
  /* 3948 */ "G_VECREDUCE_SMIN\0"
  /* 3965 */ "G_SMIN\0"
  /* 3972 */ "G_VECREDUCE_UMIN\0"
  /* 3989 */ "G_UMIN\0"
  /* 3996 */ "G_ATOMICRMW_UMIN\0"
  /* 4013 */ "G_ATOMICRMW_MIN\0"
  /* 4029 */ "G_FSIN\0"
  /* 4036 */ "CFI_INSTRUCTION\0"
  /* 4052 */ "ADJCALLSTACKDOWN\0"
  /* 4069 */ "G_SSUBO\0"
  /* 4077 */ "G_USUBO\0"
  /* 4085 */ "G_SADDO\0"
  /* 4093 */ "G_UADDO\0"
  /* 4101 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 4123 */ "MADLO\0"
  /* 4129 */ "G_SMULO\0"
  /* 4137 */ "G_UMULO\0"
  /* 4145 */ "C_MUL_LO\0"
  /* 4154 */ "G_BZERO\0"
  /* 4162 */ "STACKMAP\0"
  /* 4171 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 4193 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 4215 */ "G_BSWAP\0"
  /* 4223 */ "G_SITOFP\0"
  /* 4232 */ "G_UITOFP\0"
  /* 4241 */ "G_FCMP\0"
  /* 4248 */ "G_ICMP\0"
  /* 4255 */ "SETP_GE_F1_NP\0"
  /* 4269 */ "SETP_LE_F1_NP\0"
  /* 4283 */ "SETP_NE_F1_NP\0"
  /* 4297 */ "SETP_EQ_F1_NP\0"
  /* 4311 */ "SETP_GT_F1_NP\0"
  /* 4325 */ "SETP_LT_F1_NP\0"
  /* 4339 */ "SETP_GE_NP\0"
  /* 4350 */ "SETP_LE_NP\0"
  /* 4361 */ "SETP_NE_NP\0"
  /* 4372 */ "SETP_GE_F_NP\0"
  /* 4385 */ "SETP_LE_F_NP\0"
  /* 4398 */ "SETP_NE_F_NP\0"
  /* 4411 */ "SETP_EQ_F_NP\0"
  /* 4424 */ "SETP_GT_F_NP\0"
  /* 4437 */ "SETP_LT_F_NP\0"
  /* 4450 */ "SETP_EQ_NP\0"
  /* 4461 */ "SETP_GT_NP\0"
  /* 4472 */ "SETP_LT_NP\0"
  /* 4483 */ "SETP_GE_U_NP\0"
  /* 4496 */ "SETP_LE_U_NP\0"
  /* 4509 */ "SETP_GT_U_NP\0"
  /* 4522 */ "SETP_LT_U_NP\0"
  /* 4535 */ "G_CTPOP\0"
  /* 4543 */ "PATCHABLE_OP\0"
  /* 4556 */ "FAULTING_OP\0"
  /* 4568 */ "ADD_PP\0"
  /* 4575 */ "ADDI_PP\0"
  /* 4583 */ "ADJCALLSTACKUP\0"
  /* 4598 */ "PREALLOCATED_SETUP\0"
  /* 4617 */ "G_FLDEXP\0"
  /* 4626 */ "G_STRICT_FLDEXP\0"
  /* 4642 */ "G_FEXP\0"
  /* 4649 */ "G_FFREXP\0"
  /* 4658 */ "CVT_D0_S0_R0_P\0"
  /* 4673 */ "CVT_D1_S0_R0_P\0"
  /* 4688 */ "CVT_D2_S0_R0_P\0"
  /* 4703 */ "CVT_D3_S0_R0_P\0"
  /* 4718 */ "CVT_D0_S1_R0_P\0"
  /* 4733 */ "CVT_D1_S1_R0_P\0"
  /* 4748 */ "CVT_D2_S1_R0_P\0"
  /* 4763 */ "CVT_D3_S1_R0_P\0"
  /* 4778 */ "CVT_D1_S2_R0_P\0"
  /* 4793 */ "CVT_D3_S2_R0_P\0"
  /* 4808 */ "CVT_D1_S3_R0_P\0"
  /* 4823 */ "CVT_D2_S3_R0_P\0"
  /* 4838 */ "CVT_D3_S3_R0_P\0"
  /* 4853 */ "CVT_D0_S0_R1_P\0"
  /* 4868 */ "CVT_D1_S0_R1_P\0"
  /* 4883 */ "CVT_D0_S1_R1_P\0"
  /* 4898 */ "CVT_D1_S1_R1_P\0"
  /* 4913 */ "CVT_D2_S1_R1_P\0"
  /* 4928 */ "CVT_D3_S1_R1_P\0"
  /* 4943 */ "CVT_D0_S2_R1_P\0"
  /* 4958 */ "CVT_D1_S2_R1_P\0"
  /* 4973 */ "CVT_D0_S3_R1_P\0"
  /* 4988 */ "CVT_D1_S3_R1_P\0"
  /* 5003 */ "CVT_S32_F32_P\0"
  /* 5017 */ "CVT_U32_F32_P\0"
  /* 5031 */ "RCP_F32_P\0"
  /* 5041 */ "CVT_F32_S32_P\0"
  /* 5055 */ "CVT_F32_U32_P\0"
  /* 5069 */ "CVT_D0_S0_R2_P\0"
  /* 5084 */ "CVT_D1_S0_R2_P\0"
  /* 5099 */ "CVT_D2_S0_R2_P\0"
  /* 5114 */ "CVT_D3_S0_R2_P\0"
  /* 5129 */ "CVT_D0_S1_R2_P\0"
  /* 5144 */ "CVT_D1_S1_R2_P\0"
  /* 5159 */ "CVT_D2_S1_R2_P\0"
  /* 5174 */ "CVT_D3_S1_R2_P\0"
  /* 5189 */ "CVT_D0_S2_R2_P\0"
  /* 5204 */ "CVT_D1_S2_R2_P\0"
  /* 5219 */ "CVT_D0_S3_R2_P\0"
  /* 5234 */ "CVT_D1_S3_R2_P\0"
  /* 5249 */ "CVT_D0_S0_R3_P\0"
  /* 5264 */ "CVT_D1_S0_R3_P\0"
  /* 5279 */ "CVT_D2_S0_R3_P\0"
  /* 5294 */ "CVT_D3_S0_R3_P\0"
  /* 5309 */ "CVT_D0_S1_R3_P\0"
  /* 5324 */ "CVT_D1_S1_R3_P\0"
  /* 5339 */ "CVT_D2_S1_R3_P\0"
  /* 5354 */ "CVT_D3_S1_R3_P\0"
  /* 5369 */ "CVT_D0_S2_R3_P\0"
  /* 5384 */ "CVT_D1_S2_R3_P\0"
  /* 5399 */ "CVT_D0_S3_R3_P\0"
  /* 5414 */ "CVT_D1_S3_R3_P\0"
  /* 5429 */ "SRA_P\0"
  /* 5435 */ "FSUB_P\0"
  /* 5442 */ "FADD_P\0"
  /* 5449 */ "AND_P\0"
  /* 5455 */ "SRAI_P\0"
  /* 5462 */ "SUBI_P\0"
  /* 5469 */ "ADDI_P\0"
  /* 5476 */ "ANDI_P\0"
  /* 5483 */ "SHLI_P\0"
  /* 5490 */ "MULI_P\0"
  /* 5497 */ "ANDNI_P\0"
  /* 5505 */ "SHRI_P\0"
  /* 5512 */ "XORI_P\0"
  /* 5519 */ "LD_GLOBAL_P\0"
  /* 5531 */ "SHL_P\0"
  /* 5537 */ "FMUL_P\0"
  /* 5544 */ "MADLO_P\0"
  /* 5552 */ "SHR_P\0"
  /* 5558 */ "XOR_P\0"
  /* 5564 */ "MUL_HI_S_P\0"
  /* 5575 */ "MIN_S_P\0"
  /* 5583 */ "MAX_S_P\0"
  /* 5591 */ "MUL_HI_U_P\0"
  /* 5602 */ "MIN_U_P\0"
  /* 5610 */ "MAX_U_P\0"
  /* 5618 */ "MOV_P\0"
  /* 5624 */ "SETP_EQ\0"
  /* 5632 */ "G_BR\0"
  /* 5637 */ "INLINEASM_BR\0"
  /* 5650 */ "G_BLOCK_ADDR\0"
  /* 5663 */ "MEMBARRIER\0"
  /* 5674 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 5698 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 5723 */ "G_READCYCLECOUNTER\0"
  /* 5742 */ "G_READ_REGISTER\0"
  /* 5758 */ "G_WRITE_REGISTER\0"
  /* 5775 */ "G_ASHR\0"
  /* 5782 */ "G_FSHR\0"
  /* 5789 */ "G_LSHR\0"
  /* 5796 */ "C_SHR\0"
  /* 5802 */ "G_FFLOOR\0"
  /* 5811 */ "PSEUDO_POR\0"
  /* 5822 */ "G_BUILD_VECTOR\0"
  /* 5837 */ "G_SHUFFLE_VECTOR\0"
  /* 5854 */ "PSEUDO_PXOR\0"
  /* 5866 */ "C_XOR\0"
  /* 5872 */ "G_VECREDUCE_XOR\0"
  /* 5888 */ "G_XOR\0"
  /* 5894 */ "G_ATOMICRMW_XOR\0"
  /* 5910 */ "C_OR\0"
  /* 5915 */ "G_VECREDUCE_OR\0"
  /* 5930 */ "G_OR\0"
  /* 5935 */ "G_ATOMICRMW_OR\0"
  /* 5950 */ "G_ROTR\0"
  /* 5957 */ "G_INTTOPTR\0"
  /* 5968 */ "G_FABS\0"
  /* 5975 */ "C_ABS\0"
  /* 5981 */ "G_ABS\0"
  /* 5987 */ "G_UNMERGE_VALUES\0"
  /* 6004 */ "G_MERGE_VALUES\0"
  /* 6019 */ "G_FCOS\0"
  /* 6026 */ "G_CONCAT_VECTORS\0"
  /* 6043 */ "COPY_TO_REGCLASS\0"
  /* 6060 */ "G_IS_FPCLASS\0"
  /* 6073 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 6103 */ "DP4_SS\0"
  /* 6110 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 6137 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 6175 */ "LD_PRED_S\0"
  /* 6185 */ "ST_PRED_S\0"
  /* 6195 */ "MUL_HI_S\0"
  /* 6204 */ "C_MIN_S\0"
  /* 6212 */ "C_MAX_S\0"
  /* 6220 */ "G_SSUBSAT\0"
  /* 6230 */ "G_USUBSAT\0"
  /* 6240 */ "G_SADDSAT\0"
  /* 6250 */ "G_UADDSAT\0"
  /* 6260 */ "G_SSHLSAT\0"
  /* 6270 */ "G_USHLSAT\0"
  /* 6280 */ "G_SMULFIXSAT\0"
  /* 6293 */ "G_UMULFIXSAT\0"
  /* 6306 */ "G_SDIVFIXSAT\0"
  /* 6319 */ "G_UDIVFIXSAT\0"
  /* 6332 */ "G_EXTRACT\0"
  /* 6342 */ "G_SELECT\0"
  /* 6351 */ "G_BRINDIRECT\0"
  /* 6364 */ "C_RET\0"
  /* 6370 */ "PATCHABLE_RET\0"
  /* 6384 */ "PSEUDO_RET\0"
  /* 6395 */ "G_MEMSET\0"
  /* 6404 */ "SETP_GT\0"
  /* 6412 */ "C_BAR_WAIT\0"
  /* 6423 */ "BAR_INIT\0"
  /* 6432 */ "C_EXIT\0"
  /* 6439 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 6463 */ "G_BRJT\0"
  /* 6470 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 6491 */ "G_INSERT_VECTOR_ELT\0"
  /* 6511 */ "SETP_LT\0"
  /* 6519 */ "G_FCONSTANT\0"
  /* 6531 */ "G_CONSTANT\0"
  /* 6542 */ "G_INTRINSIC_CONVERGENT\0"
  /* 6565 */ "STATEPOINT\0"
  /* 6576 */ "PATCHPOINT\0"
  /* 6587 */ "G_PTRTOINT\0"
  /* 6598 */ "G_FRINT\0"
  /* 6606 */ "G_INTRINSIC_LRINT\0"
  /* 6624 */ "G_FNEARBYINT\0"
  /* 6637 */ "UNBALLOT\0"
  /* 6646 */ "LD_GLOBAL_SLOT\0"
  /* 6661 */ "ST_GLOBAL_SLOT\0"
  /* 6676 */ "C_NOT\0"
  /* 6682 */ "G_VASTART\0"
  /* 6692 */ "LIFETIME_START\0"
  /* 6707 */ "G_INVOKE_REGION_START\0"
  /* 6729 */ "G_INSERT\0"
  /* 6738 */ "G_FSQRT\0"
  /* 6746 */ "G_STRICT_FSQRT\0"
  /* 6761 */ "PSEUDO_BCAST\0"
  /* 6774 */ "G_BITCAST\0"
  /* 6784 */ "G_ADDRSPACE_CAST\0"
  /* 6801 */ "DBG_VALUE_LIST\0"
  /* 6816 */ "G_FPEXT\0"
  /* 6824 */ "G_SEXT\0"
  /* 6831 */ "G_ASSERT_SEXT\0"
  /* 6845 */ "CVT_SEXT\0"
  /* 6854 */ "G_ANYEXT\0"
  /* 6863 */ "G_ZEXT\0"
  /* 6870 */ "G_ASSERT_ZEXT\0"
  /* 6884 */ "SETP_GE_U\0"
  /* 6894 */ "SETP_LE_U\0"
  /* 6904 */ "MUL_HI_U\0"
  /* 6913 */ "C_MIN_U\0"
  /* 6921 */ "SETP_GT_U\0"
  /* 6931 */ "SETP_LT_U\0"
  /* 6941 */ "C_MAX_U\0"
  /* 6949 */ "BREV\0"
  /* 6954 */ "G_FDIV\0"
  /* 6961 */ "G_STRICT_FDIV\0"
  /* 6975 */ "G_SDIV\0"
  /* 6982 */ "G_UDIV\0"
  /* 6989 */ "G_GET_FPENV\0"
  /* 7001 */ "G_RESET_FPENV\0"
  /* 7015 */ "G_SET_FPENV\0"
  /* 7027 */ "C_RECONV\0"
  /* 7036 */ "PSEUDO_PMOV\0"
  /* 7048 */ "C_MOV\0"
  /* 7054 */ "G_FPOW\0"
  /* 7061 */ "PSEUDO_NARROW\0"
  /* 7075 */ "C_FMAX\0"
  /* 7082 */ "G_VECREDUCE_FMAX\0"
  /* 7099 */ "G_ATOMICRMW_FMAX\0"
  /* 7116 */ "G_VECREDUCE_SMAX\0"
  /* 7133 */ "G_SMAX\0"
  /* 7140 */ "G_VECREDUCE_UMAX\0"
  /* 7157 */ "G_UMAX\0"
  /* 7164 */ "G_ATOMICRMW_UMAX\0"
  /* 7181 */ "G_ATOMICRMW_MAX\0"
  /* 7197 */ "LD_SHARED_IDX\0"
  /* 7211 */ "ST_SHARED_IDX\0"
  /* 7225 */ "LD_GLOBAL_IDX\0"
  /* 7239 */ "ST_GLOBAL_IDX\0"
  /* 7253 */ "SHFL_IDX\0"
  /* 7262 */ "G_FRAME_INDEX\0"
  /* 7276 */ "G_SBFX\0"
  /* 7283 */ "G_UBFX\0"
  /* 7290 */ "G_SMULFIX\0"
  /* 7300 */ "G_UMULFIX\0"
  /* 7310 */ "G_SDIVFIX\0"
  /* 7320 */ "G_UDIVFIX\0"
  /* 7330 */ "VOTE_ANY\0"
  /* 7339 */ "G_MEMCPY\0"
  /* 7348 */ "COPY\0"
  /* 7353 */ "CLZ\0"
  /* 7357 */ "G_CTLZ\0"
  /* 7364 */ "G_CTTZ\0"
  /* 7371 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    2868U, 3757U, 5637U, 4036U, 3408U, 3389U, 3417U, 3577U, 
    2640U, 2655U, 2540U, 2682U, 6043U, 2417U, 6801U, 2553U, 
    2864U, 3398U, 2177U, 7348U, 2298U, 6692U, 2014U, 2120U, 
    2165U, 4162U, 3565U, 6576U, 2099U, 4598U, 2745U, 6565U, 
    2337U, 4556U, 4543U, 5698U, 6370U, 6439U, 3485U, 3544U, 
    3517U, 3434U, 5663U, 4101U, 6831U, 6870U, 3880U, 1843U, 
    1520U, 3687U, 6975U, 6982U, 3714U, 3721U, 3728U, 3738U, 
    1992U, 5930U, 5888U, 2538U, 2866U, 7262U, 2427U, 3582U, 
    6332U, 5987U, 6729U, 6004U, 5822U, 1606U, 6026U, 6587U, 
    5957U, 6774U, 2477U, 5674U, 2073U, 1580U, 2055U, 6606U, 
    3858U, 5723U, 1731U, 1675U, 1705U, 1716U, 1656U, 1686U, 
    2381U, 2365U, 6073U, 2696U, 2713U, 1859U, 1526U, 1998U, 
    1941U, 5935U, 5894U, 7181U, 4013U, 7164U, 3996U, 1804U, 
    1497U, 7099U, 3931U, 4193U, 4171U, 2157U, 2799U, 2027U, 
    6351U, 6707U, 1558U, 6110U, 6542U, 6137U, 6854U, 1598U, 
    6531U, 6519U, 6682U, 2737U, 6824U, 2669U, 6863U, 3471U, 
    5789U, 5775U, 3458U, 5782U, 5950U, 3598U, 4248U, 4241U, 
    6342U, 4093U, 2198U, 4077U, 2141U, 4085U, 2190U, 4069U, 
    2133U, 4137U, 4129U, 2818U, 2810U, 6250U, 6240U, 6230U, 
    6220U, 6270U, 6260U, 7290U, 7300U, 6280U, 6293U, 7310U, 
    7320U, 6306U, 6319U, 1762U, 1476U, 3629U, 1445U, 1649U, 
    6954U, 3693U, 7054U, 3167U, 4642U, 676U, 9U, 2730U, 
    659U, 0U, 4617U, 4649U, 2627U, 6816U, 1570U, 3130U, 
    3153U, 4223U, 4232U, 5968U, 3895U, 6060U, 2486U, 3831U, 
    3841U, 2247U, 2262U, 3788U, 3820U, 6989U, 7015U, 7001U, 
    2206U, 2234U, 2219U, 1849U, 3355U, 3965U, 7133U, 3989U, 
    7157U, 5981U, 2046U, 2036U, 5632U, 6463U, 6491U, 6470U, 
    5837U, 7364U, 2520U, 7357U, 2502U, 4535U, 4215U, 2404U, 
    3477U, 6019U, 4029U, 6738U, 5802U, 6598U, 6624U, 6784U, 
    5650U, 2285U, 1627U, 2442U, 2350U, 1790U, 1483U, 3657U, 
    6961U, 3700U, 1451U, 6746U, 4626U, 5742U, 5758U, 7339U, 
    2313U, 2467U, 6395U, 4154U, 1769U, 3636U, 1745U, 3612U, 
    7082U, 3914U, 3799U, 3767U, 1827U, 3671U, 1976U, 5915U, 
    5872U, 7116U, 3948U, 7140U, 3972U, 7276U, 7283U, 4052U, 
    4583U, 6761U, 1895U, 3505U, 1911U, 7061U, 1958U, 7036U, 
    5811U, 5854U, 6384U, 1926U, 5971U, 1741U, 2852U, 1233U, 
    5469U, 4575U, 1074U, 5443U, 4568U, 1030U, 1954U, 2859U, 
    5476U, 3853U, 2892U, 5497U, 5449U, 1066U, 2762U, 6639U, 
    6423U, 2389U, 1466U, 1902U, 6949U, 3500U, 2793U, 3139U, 
    7353U, 551U, 54U, 4658U, 601U, 1407U, 1213U, 1369U, 
    621U, 365U, 4853U, 684U, 5069U, 849U, 5249U, 106U, 
    4718U, 1426U, 1388U, 391U, 4883U, 736U, 5129U, 901U, 
    5309U, 443U, 4943U, 788U, 5189U, 953U, 5369U, 469U, 
    4973U, 814U, 5219U, 979U, 5399U, 67U, 4673U, 640U, 
    378U, 4868U, 697U, 5084U, 862U, 5264U, 119U, 4733U, 
    404U, 4898U, 749U, 5144U, 914U, 5324U, 158U, 4778U, 
    456U, 4958U, 801U, 5204U, 966U, 5384U, 184U, 4808U, 
    482U, 4988U, 827U, 5234U, 992U, 5414U, 80U, 4688U, 
    710U, 5099U, 875U, 5279U, 132U, 4748U, 417U, 4913U, 
    762U, 5159U, 927U, 5339U, 197U, 4823U, 93U, 4703U, 
    723U, 5114U, 888U, 5294U, 145U, 4763U, 430U, 4928U, 
    775U, 5174U, 940U, 5354U, 171U, 4793U, 210U, 4838U, 
    569U, 5041U, 581U, 5055U, 495U, 5003U, 6845U, 507U, 
    5017U, 5975U, 1821U, 2850U, 1970U, 2857U, 3851U, 2454U, 
    6412U, 1464U, 2826U, 6432U, 1738U, 2149U, 7075U, 3907U, 
    3605U, 3365U, 6212U, 6941U, 6204U, 6913U, 7048U, 4145U, 
    2634U, 6676U, 5910U, 3124U, 7027U, 6364U, 3465U, 2880U, 
    5796U, 3110U, 1470U, 2836U, 3377U, 1514U, 2843U, 5866U, 
    3117U, 1005U, 1014U, 1542U, 840U, 667U, 6103U, 527U, 
    46U, 327U, 1740U, 251U, 5442U, 26U, 239U, 18U, 
    223U, 7077U, 357U, 3909U, 308U, 3607U, 300U, 5537U, 
    38U, 292U, 1478U, 231U, 5435U, 3367U, 7225U, 1177U, 
    1335U, 5519U, 6646U, 1139U, 1299U, 1083U, 1273U, 2773U, 
    6175U, 1875U, 7197U, 1038U, 1247U, 519U, 4123U, 5544U, 
    1550U, 6214U, 5583U, 1129U, 6943U, 5610U, 6206U, 5575U, 
    1119U, 6915U, 5602U, 3162U, 1240U, 5618U, 2887U, 5490U, 
    6195U, 5564U, 6904U, 5591U, 4147U, 2630U, 5808U, 3120U, 
    5513U, 5559U, 1112U, 2874U, 7371U, 1965U, 7043U, 3748U, 
    1644U, 5818U, 5861U, 543U, 5031U, 593U, 559U, 3454U, 
    5624U, 2597U, 316U, 4297U, 3241U, 4411U, 2976U, 3277U, 
    4450U, 3018U, 2277U, 2567U, 259U, 4255U, 3205U, 4372U, 
    2934U, 3175U, 4339U, 2898U, 6884U, 3307U, 4483U, 3054U, 
    6404U, 2607U, 335U, 4311U, 3253U, 4424U, 2990U, 3287U, 
    4461U, 3030U, 6921U, 3331U, 4509U, 3082U, 2305U, 2577U, 
    270U, 4269U, 3217U, 4385U, 2948U, 3185U, 4350U, 2910U, 
    6894U, 3319U, 4496U, 3068U, 6511U, 2617U, 346U, 4325U, 
    3265U, 4437U, 3004U, 3297U, 4472U, 3042U, 6931U, 3343U, 
    4522U, 3096U, 2329U, 2587U, 281U, 4283U, 3229U, 4398U, 
    2962U, 3195U, 4361U, 2922U, 7253U, 3461U, 2882U, 5483U, 
    5531U, 5778U, 3112U, 5505U, 5552U, 535U, 560U, 1472U, 
    2838U, 5455U, 5429U, 2116U, 3379U, 7239U, 1195U, 1352U, 
    6661U, 1158U, 1317U, 1097U, 1286U, 2783U, 6185U, 1885U, 
    7211U, 1052U, 1260U, 1479U, 2845U, 5462U, 5436U, 1022U, 
    6637U, 2872U, 7330U, 5862U, 3119U, 5512U, 5558U, 1111U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 672);
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
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 672);
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
  simm8 = 21,
  simm9 = 22,
  simm10 = 23,
  simm13 = 24,
  simm16 = 25,
  simm17 = 26,
  simm18 = 27,
  simm21 = 28,
  srdsel = 29,
  type0 = 30,
  type1 = 31,
  type2 = 32,
  type3 = 33,
  type4 = 34,
  type5 = 35,
  uimm2 = 36,
  uimm3 = 37,
  uimm4 = 38,
  uimm5 = 39,
  uimm6 = 40,
  uimm8 = 41,
  uimm10 = 42,
  uimm16 = 43,
  uimm17 = 44,
  uimm29 = 45,
  uimm32 = 46,
  uimm33 = 47,
  untyped_imm_0 = 48,
  GPR = 49,
  GPR8 = 50,
  GPR16 = 51,
  PR = 52,
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
    /* PSEUDO_LD_PRED */
    675,
    /* PSEUDO_NARROW */
    678,
    /* PSEUDO_PAND */
    680,
    /* PSEUDO_PMOV */
    683,
    /* PSEUDO_POR */
    687,
    /* PSEUDO_PXOR */
    690,
    /* PSEUDO_RET */
    693,
    /* PSEUDO_ST_PRED */
    694,
    /* ABS */
    697,
    /* ADD */
    701,
    /* ADDI */
    705,
    /* ADDI48 */
    708,
    /* ADDI_P */
    711,
    /* ADDI_PP */
    715,
    /* ADDI_W16 */
    720,
    /* ADD_P */
    723,
    /* ADD_PP */
    728,
    /* ADD_W16 */
    734,
    /* AND */
    738,
    /* ANDI */
    742,
    /* ANDI_P */
    745,
    /* ANDN */
    749,
    /* ANDNI */
    753,
    /* ANDNI_P */
    756,
    /* AND_P */
    760,
    /* AND_W16 */
    765,
    /* ATOM_ADD_G */
    769,
    /* BALLOT */
    773,
    /* BAR_INIT */
    776,
    /* BAR_WAIT_PHASE */
    778,
    /* BRA */
    781,
    /* BRA_PRED */
    782,
    /* BREV */
    784,
    /* CALL */
    788,
    /* CAS_G */
    790,
    /* CHWIDTH_MULTI */
    797,
    /* CLZ */
    799,
    /* COS_F32 */
    803,
    /* CVT_D0_S0_R0 */
    807,
    /* CVT_D0_S0_R0_P */
    811,
    /* CVT_D0_S0_R0_W16_32 */
    816,
    /* CVT_D0_S0_R0_W16_8 */
    820,
    /* CVT_D0_S0_R0_W32_16 */
    824,
    /* CVT_D0_S0_R0_W32_8 */
    828,
    /* CVT_D0_S0_R0_W8_32 */
    832,
    /* CVT_D0_S0_R1 */
    836,
    /* CVT_D0_S0_R1_P */
    840,
    /* CVT_D0_S0_R2 */
    845,
    /* CVT_D0_S0_R2_P */
    849,
    /* CVT_D0_S0_R3 */
    854,
    /* CVT_D0_S0_R3_P */
    858,
    /* CVT_D0_S1_R0 */
    863,
    /* CVT_D0_S1_R0_P */
    867,
    /* CVT_D0_S1_R0_W16_8 */
    872,
    /* CVT_D0_S1_R0_W32_8 */
    876,
    /* CVT_D0_S1_R1 */
    880,
    /* CVT_D0_S1_R1_P */
    884,
    /* CVT_D0_S1_R2 */
    889,
    /* CVT_D0_S1_R2_P */
    893,
    /* CVT_D0_S1_R3 */
    898,
    /* CVT_D0_S1_R3_P */
    902,
    /* CVT_D0_S2_R1 */
    907,
    /* CVT_D0_S2_R1_P */
    911,
    /* CVT_D0_S2_R2 */
    916,
    /* CVT_D0_S2_R2_P */
    920,
    /* CVT_D0_S2_R3 */
    925,
    /* CVT_D0_S2_R3_P */
    929,
    /* CVT_D0_S3_R1 */
    934,
    /* CVT_D0_S3_R1_P */
    938,
    /* CVT_D0_S3_R2 */
    943,
    /* CVT_D0_S3_R2_P */
    947,
    /* CVT_D0_S3_R3 */
    952,
    /* CVT_D0_S3_R3_P */
    956,
    /* CVT_D1_S0_R0 */
    961,
    /* CVT_D1_S0_R0_P */
    965,
    /* CVT_D1_S0_R0_W8_32 */
    970,
    /* CVT_D1_S0_R1 */
    974,
    /* CVT_D1_S0_R1_P */
    978,
    /* CVT_D1_S0_R2 */
    983,
    /* CVT_D1_S0_R2_P */
    987,
    /* CVT_D1_S0_R3 */
    992,
    /* CVT_D1_S0_R3_P */
    996,
    /* CVT_D1_S1_R0 */
    1001,
    /* CVT_D1_S1_R0_P */
    1005,
    /* CVT_D1_S1_R1 */
    1010,
    /* CVT_D1_S1_R1_P */
    1014,
    /* CVT_D1_S1_R2 */
    1019,
    /* CVT_D1_S1_R2_P */
    1023,
    /* CVT_D1_S1_R3 */
    1028,
    /* CVT_D1_S1_R3_P */
    1032,
    /* CVT_D1_S2_R0 */
    1037,
    /* CVT_D1_S2_R0_P */
    1041,
    /* CVT_D1_S2_R1 */
    1046,
    /* CVT_D1_S2_R1_P */
    1050,
    /* CVT_D1_S2_R2 */
    1055,
    /* CVT_D1_S2_R2_P */
    1059,
    /* CVT_D1_S2_R3 */
    1064,
    /* CVT_D1_S2_R3_P */
    1068,
    /* CVT_D1_S3_R0 */
    1073,
    /* CVT_D1_S3_R0_P */
    1077,
    /* CVT_D1_S3_R1 */
    1082,
    /* CVT_D1_S3_R1_P */
    1086,
    /* CVT_D1_S3_R2 */
    1091,
    /* CVT_D1_S3_R2_P */
    1095,
    /* CVT_D1_S3_R3 */
    1100,
    /* CVT_D1_S3_R3_P */
    1104,
    /* CVT_D2_S0_R0 */
    1109,
    /* CVT_D2_S0_R0_P */
    1113,
    /* CVT_D2_S0_R2 */
    1118,
    /* CVT_D2_S0_R2_P */
    1122,
    /* CVT_D2_S0_R3 */
    1127,
    /* CVT_D2_S0_R3_P */
    1131,
    /* CVT_D2_S1_R0 */
    1136,
    /* CVT_D2_S1_R0_P */
    1140,
    /* CVT_D2_S1_R1 */
    1145,
    /* CVT_D2_S1_R1_P */
    1149,
    /* CVT_D2_S1_R2 */
    1154,
    /* CVT_D2_S1_R2_P */
    1158,
    /* CVT_D2_S1_R3 */
    1163,
    /* CVT_D2_S1_R3_P */
    1167,
    /* CVT_D2_S3_R0 */
    1172,
    /* CVT_D2_S3_R0_P */
    1176,
    /* CVT_D3_S0_R0 */
    1181,
    /* CVT_D3_S0_R0_P */
    1185,
    /* CVT_D3_S0_R2 */
    1190,
    /* CVT_D3_S0_R2_P */
    1194,
    /* CVT_D3_S0_R3 */
    1199,
    /* CVT_D3_S0_R3_P */
    1203,
    /* CVT_D3_S1_R0 */
    1208,
    /* CVT_D3_S1_R0_P */
    1212,
    /* CVT_D3_S1_R1 */
    1217,
    /* CVT_D3_S1_R1_P */
    1221,
    /* CVT_D3_S1_R2 */
    1226,
    /* CVT_D3_S1_R2_P */
    1230,
    /* CVT_D3_S1_R3 */
    1235,
    /* CVT_D3_S1_R3_P */
    1239,
    /* CVT_D3_S2_R0 */
    1244,
    /* CVT_D3_S2_R0_P */
    1248,
    /* CVT_D3_S3_R0 */
    1253,
    /* CVT_D3_S3_R0_P */
    1257,
    /* CVT_F32_S32 */
    1262,
    /* CVT_F32_S32_P */
    1266,
    /* CVT_F32_U32 */
    1271,
    /* CVT_F32_U32_P */
    1275,
    /* CVT_S32_F32 */
    1280,
    /* CVT_S32_F32_P */
    1284,
    /* CVT_SEXT */
    1289,
    /* CVT_U32_F32 */
    1293,
    /* CVT_U32_F32_P */
    1297,
    /* C_ABS */
    1302,
    /* C_ADD */
    1304,
    /* C_ADDI */
    1307,
    /* C_AND */
    1310,
    /* C_ANDI */
    1313,
    /* C_ANDN */
    1316,
    /* C_BAR_ARRIVE */
    1319,
    /* C_BAR_WAIT */
    1320,
    /* C_BRA */
    1321,
    /* C_CHWIDTH */
    1322,
    /* C_EXIT */
    1324,
    /* C_FADD */
    1325,
    /* C_FENCE */
    1328,
    /* C_FMAX */
    1329,
    /* C_FMIN */
    1332,
    /* C_FMUL */
    1335,
    /* C_LD_GLOBAL */
    1338,
    /* C_MAX_S */
    1340,
    /* C_MAX_U */
    1343,
    /* C_MIN_S */
    1346,
    /* C_MIN_U */
    1349,
    /* C_MOV */
    1352,
    /* C_MUL_LO */
    1354,
    /* C_NEG */
    1357,
    /* C_NOT */
    1359,
    /* C_OR */
    1361,
    /* C_ORI */
    1364,
    /* C_RECONV */
    1367,
    /* C_RET */
    1368,
    /* C_SHL */
    1369,
    /* C_SHLI */
    1372,
    /* C_SHR */
    1375,
    /* C_SHRI */
    1378,
    /* C_SRA */
    1381,
    /* C_SRAI */
    1384,
    /* C_ST_GLOBAL */
    1387,
    /* C_SUB */
    1389,
    /* C_SUBI */
    1392,
    /* C_XOR */
    1395,
    /* C_XORI */
    1398,
    /* DP2_BF16 */
    1401,
    /* DP2_F16 */
    1405,
    /* DP4_ACC */
    1409,
    /* DP4_E4M3 */
    1413,
    /* DP4_E5M2 */
    1417,
    /* DP4_SS */
    1421,
    /* EX2_F32 */
    1425,
    /* FABS_F0 */
    1429,
    /* FABS_F1 */
    1433,
    /* FADD */
    1437,
    /* FADD_F1 */
    1441,
    /* FADD_P */
    1445,
    /* FFMA_ACC_F0 */
    1450,
    /* FFMA_ACC_F1 */
    1454,
    /* FFMA_F0 */
    1458,
    /* FFMA_F1 */
    1462,
    /* FMAX */
    1466,
    /* FMAX_F1 */
    1470,
    /* FMIN */
    1474,
    /* FMIN_F1 */
    1478,
    /* FMUL */
    1482,
    /* FMUL_F1 */
    1486,
    /* FMUL_P */
    1490,
    /* FNEG_F0 */
    1495,
    /* FNEG_F1 */
    1499,
    /* FSUB */
    1503,
    /* FSUB_F1 */
    1507,
    /* FSUB_P */
    1511,
    /* LD_GLOBAL */
    1516,
    /* LD_GLOBAL_IDX */
    1519,
    /* LD_GLOBAL_IDX_W16 */
    1524,
    /* LD_GLOBAL_IDX_W8 */
    1529,
    /* LD_GLOBAL_P */
    1534,
    /* LD_GLOBAL_SLOT */
    1538,
    /* LD_GLOBAL_SLOT_W16 */
    1543,
    /* LD_GLOBAL_SLOT_W8 */
    1548,
    /* LD_GLOBAL_W16 */
    1553,
    /* LD_GLOBAL_W8 */
    1556,
    /* LD_PRED_G */
    1559,
    /* LD_PRED_S */
    1562,
    /* LD_SHARED */
    1565,
    /* LD_SHARED_IDX */
    1568,
    /* LD_SHARED_W16 */
    1573,
    /* LD_SHARED_W8 */
    1576,
    /* LG2_F32 */
    1579,
    /* MADLO */
    1583,
    /* MADLO_P */
    1587,
    /* MAD_ACC */
    1592,
    /* MAX_S */
    1596,
    /* MAX_S_P */
    1600,
    /* MAX_S_W16 */
    1605,
    /* MAX_U */
    1609,
    /* MAX_U_P */
    1613,
    /* MIN_S */
    1618,
    /* MIN_S_P */
    1622,
    /* MIN_S_W16 */
    1627,
    /* MIN_U */
    1631,
    /* MIN_U_P */
    1635,
    /* MOVI */
    1640,
    /* MOVI48 */
    1642,
    /* MOV_P */
    1644,
    /* MULI */
    1650,
    /* MULI_P */
    1653,
    /* MUL_HI_S */
    1657,
    /* MUL_HI_S_P */
    1661,
    /* MUL_HI_U */
    1666,
    /* MUL_HI_U_P */
    1670,
    /* MUL_LO */
    1675,
    /* NEG */
    1679,
    /* OR */
    1683,
    /* ORI */
    1687,
    /* ORI_P */
    1690,
    /* OR_P */
    1694,
    /* OR_W16 */
    1699,
    /* PACKI */
    1703,
    /* PACKI_Z */
    1707,
    /* PAND */
    1710,
    /* PMOV */
    1713,
    /* PMOV_IMM */
    1716,
    /* POPC */
    1718,
    /* POR */
    1722,
    /* PXOR */
    1725,
    /* RCP_F32 */
    1728,
    /* RCP_F32_P */
    1732,
    /* RCP_U32 */
    1737,
    /* RSQRT_F32 */
    1741,
    /* SEL */
    1745,
    /* SETP_EQ */
    1750,
    /* SETP_EQ_F */
    1755,
    /* SETP_EQ_F1 */
    1760,
    /* SETP_EQ_F1_NP */
    1765,
    /* SETP_EQ_F_I */
    1769,
    /* SETP_EQ_F_NP */
    1774,
    /* SETP_EQ_F_NPI */
    1778,
    /* SETP_EQ_I */
    1782,
    /* SETP_EQ_NP */
    1787,
    /* SETP_EQ_NPI */
    1791,
    /* SETP_GE */
    1795,
    /* SETP_GE_F */
    1800,
    /* SETP_GE_F1 */
    1805,
    /* SETP_GE_F1_NP */
    1810,
    /* SETP_GE_F_I */
    1814,
    /* SETP_GE_F_NP */
    1819,
    /* SETP_GE_F_NPI */
    1823,
    /* SETP_GE_I */
    1827,
    /* SETP_GE_NP */
    1832,
    /* SETP_GE_NPI */
    1836,
    /* SETP_GE_U */
    1840,
    /* SETP_GE_U_I */
    1845,
    /* SETP_GE_U_NP */
    1850,
    /* SETP_GE_U_NPI */
    1854,
    /* SETP_GT */
    1858,
    /* SETP_GT_F */
    1863,
    /* SETP_GT_F1 */
    1868,
    /* SETP_GT_F1_NP */
    1873,
    /* SETP_GT_F_I */
    1877,
    /* SETP_GT_F_NP */
    1882,
    /* SETP_GT_F_NPI */
    1886,
    /* SETP_GT_I */
    1890,
    /* SETP_GT_NP */
    1895,
    /* SETP_GT_NPI */
    1899,
    /* SETP_GT_U */
    1903,
    /* SETP_GT_U_I */
    1908,
    /* SETP_GT_U_NP */
    1913,
    /* SETP_GT_U_NPI */
    1917,
    /* SETP_LE */
    1921,
    /* SETP_LE_F */
    1926,
    /* SETP_LE_F1 */
    1931,
    /* SETP_LE_F1_NP */
    1936,
    /* SETP_LE_F_I */
    1940,
    /* SETP_LE_F_NP */
    1945,
    /* SETP_LE_F_NPI */
    1949,
    /* SETP_LE_I */
    1953,
    /* SETP_LE_NP */
    1958,
    /* SETP_LE_NPI */
    1962,
    /* SETP_LE_U */
    1966,
    /* SETP_LE_U_I */
    1971,
    /* SETP_LE_U_NP */
    1976,
    /* SETP_LE_U_NPI */
    1980,
    /* SETP_LT */
    1984,
    /* SETP_LT_F */
    1989,
    /* SETP_LT_F1 */
    1994,
    /* SETP_LT_F1_NP */
    1999,
    /* SETP_LT_F_I */
    2003,
    /* SETP_LT_F_NP */
    2008,
    /* SETP_LT_F_NPI */
    2012,
    /* SETP_LT_I */
    2016,
    /* SETP_LT_NP */
    2021,
    /* SETP_LT_NPI */
    2025,
    /* SETP_LT_U */
    2029,
    /* SETP_LT_U_I */
    2034,
    /* SETP_LT_U_NP */
    2039,
    /* SETP_LT_U_NPI */
    2043,
    /* SETP_NE */
    2047,
    /* SETP_NE_F */
    2052,
    /* SETP_NE_F1 */
    2057,
    /* SETP_NE_F1_NP */
    2062,
    /* SETP_NE_F_I */
    2066,
    /* SETP_NE_F_NP */
    2071,
    /* SETP_NE_F_NPI */
    2075,
    /* SETP_NE_I */
    2079,
    /* SETP_NE_NP */
    2084,
    /* SETP_NE_NPI */
    2088,
    /* SHFL_IDX */
    2092,
    /* SHL */
    2096,
    /* SHLI */
    2100,
    /* SHLI_P */
    2103,
    /* SHL_P */
    2107,
    /* SHR */
    2112,
    /* SHRI */
    2116,
    /* SHRI_P */
    2119,
    /* SHR_P */
    2123,
    /* SIN_F32 */
    2128,
    /* SQRT_F32 */
    2132,
    /* SRA */
    2136,
    /* SRAI */
    2140,
    /* SRAI_P */
    2143,
    /* SRA_P */
    2147,
    /* SRD */
    2152,
    /* ST_GLOBAL */
    2154,
    /* ST_GLOBAL_IDX */
    2157,
    /* ST_GLOBAL_IDX_W16 */
    2162,
    /* ST_GLOBAL_IDX_W8 */
    2167,
    /* ST_GLOBAL_SLOT */
    2172,
    /* ST_GLOBAL_SLOT_W16 */
    2177,
    /* ST_GLOBAL_SLOT_W8 */
    2182,
    /* ST_GLOBAL_W16 */
    2187,
    /* ST_GLOBAL_W8 */
    2190,
    /* ST_PRED_G */
    2193,
    /* ST_PRED_S */
    2196,
    /* ST_SHARED */
    2199,
    /* ST_SHARED_IDX */
    2202,
    /* ST_SHARED_W16 */
    2207,
    /* ST_SHARED_W8 */
    2210,
    /* SUB */
    2213,
    /* SUBI */
    2217,
    /* SUBI_P */
    2220,
    /* SUB_P */
    2224,
    /* SUB_W16 */
    2229,
    /* UNBALLOT */
    2233,
    /* UNPACKI */
    2236,
    /* VOTE_ANY */
    2239,
    /* XOR */
    2242,
    /* XORI */
    2246,
    /* XORI_P */
    2249,
    /* XOR_P */
    2253,
    /* XOR_W16 */
    2258,
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
    /* PSEUDO_LD_PRED */
    PR, GPR, simm13, 
    /* PSEUDO_NARROW */
    GPR, GPR, 
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
    GPR, GPR, GPR, simm9, 
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
    GPR, PR, pqual, GPR, GPR, GPR, simm16, 
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
    /* CVT_D0_S0_R0_W32_8 */
    GPR, GPR8, GPR8, GPR8, 
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
    /* FADD_P */
    GPR, pqual, GPR, GPR, GPR, 
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
    /* FMUL_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* FNEG_F0 */
    GPR, GPR, GPR, GPR, 
    /* FNEG_F1 */
    GPR, GPR, GPR, GPR, 
    /* FSUB */
    GPR, GPR, GPR, GPR, 
    /* FSUB_F1 */
    GPR, GPR, GPR, GPR, 
    /* FSUB_P */
    GPR, pqual, GPR, GPR, GPR, 
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
    /* LD_PRED_G */
    pmask4, GPR, simm13, 
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
    /* ST_PRED_G */
    pmask4, GPR, simm13, 
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
    CEFBS_None, // PSEUDO_LD_PRED = 276
    CEFBS_None, // PSEUDO_NARROW = 277
    CEFBS_None, // PSEUDO_PAND = 278
    CEFBS_None, // PSEUDO_PMOV = 279
    CEFBS_None, // PSEUDO_POR = 280
    CEFBS_None, // PSEUDO_PXOR = 281
    CEFBS_None, // PSEUDO_RET = 282
    CEFBS_None, // PSEUDO_ST_PRED = 283
    CEFBS_None, // ABS = 284
    CEFBS_None, // ADD = 285
    CEFBS_None, // ADDI = 286
    CEFBS_None, // ADDI48 = 287
    CEFBS_None, // ADDI_P = 288
    CEFBS_None, // ADDI_PP = 289
    CEFBS_None, // ADDI_W16 = 290
    CEFBS_None, // ADD_P = 291
    CEFBS_None, // ADD_PP = 292
    CEFBS_None, // ADD_W16 = 293
    CEFBS_None, // AND = 294
    CEFBS_None, // ANDI = 295
    CEFBS_None, // ANDI_P = 296
    CEFBS_None, // ANDN = 297
    CEFBS_None, // ANDNI = 298
    CEFBS_None, // ANDNI_P = 299
    CEFBS_None, // AND_P = 300
    CEFBS_None, // AND_W16 = 301
    CEFBS_None, // ATOM_ADD_G = 302
    CEFBS_None, // BALLOT = 303
    CEFBS_None, // BAR_INIT = 304
    CEFBS_None, // BAR_WAIT_PHASE = 305
    CEFBS_None, // BRA = 306
    CEFBS_None, // BRA_PRED = 307
    CEFBS_None, // BREV = 308
    CEFBS_None, // CALL = 309
    CEFBS_None, // CAS_G = 310
    CEFBS_None, // CHWIDTH_MULTI = 311
    CEFBS_None, // CLZ = 312
    CEFBS_None, // COS_F32 = 313
    CEFBS_None, // CVT_D0_S0_R0 = 314
    CEFBS_None, // CVT_D0_S0_R0_P = 315
    CEFBS_None, // CVT_D0_S0_R0_W16_32 = 316
    CEFBS_None, // CVT_D0_S0_R0_W16_8 = 317
    CEFBS_None, // CVT_D0_S0_R0_W32_16 = 318
    CEFBS_None, // CVT_D0_S0_R0_W32_8 = 319
    CEFBS_None, // CVT_D0_S0_R0_W8_32 = 320
    CEFBS_None, // CVT_D0_S0_R1 = 321
    CEFBS_None, // CVT_D0_S0_R1_P = 322
    CEFBS_None, // CVT_D0_S0_R2 = 323
    CEFBS_None, // CVT_D0_S0_R2_P = 324
    CEFBS_None, // CVT_D0_S0_R3 = 325
    CEFBS_None, // CVT_D0_S0_R3_P = 326
    CEFBS_None, // CVT_D0_S1_R0 = 327
    CEFBS_None, // CVT_D0_S1_R0_P = 328
    CEFBS_None, // CVT_D0_S1_R0_W16_8 = 329
    CEFBS_None, // CVT_D0_S1_R0_W32_8 = 330
    CEFBS_None, // CVT_D0_S1_R1 = 331
    CEFBS_None, // CVT_D0_S1_R1_P = 332
    CEFBS_None, // CVT_D0_S1_R2 = 333
    CEFBS_None, // CVT_D0_S1_R2_P = 334
    CEFBS_None, // CVT_D0_S1_R3 = 335
    CEFBS_None, // CVT_D0_S1_R3_P = 336
    CEFBS_None, // CVT_D0_S2_R1 = 337
    CEFBS_None, // CVT_D0_S2_R1_P = 338
    CEFBS_None, // CVT_D0_S2_R2 = 339
    CEFBS_None, // CVT_D0_S2_R2_P = 340
    CEFBS_None, // CVT_D0_S2_R3 = 341
    CEFBS_None, // CVT_D0_S2_R3_P = 342
    CEFBS_None, // CVT_D0_S3_R1 = 343
    CEFBS_None, // CVT_D0_S3_R1_P = 344
    CEFBS_None, // CVT_D0_S3_R2 = 345
    CEFBS_None, // CVT_D0_S3_R2_P = 346
    CEFBS_None, // CVT_D0_S3_R3 = 347
    CEFBS_None, // CVT_D0_S3_R3_P = 348
    CEFBS_None, // CVT_D1_S0_R0 = 349
    CEFBS_None, // CVT_D1_S0_R0_P = 350
    CEFBS_None, // CVT_D1_S0_R0_W8_32 = 351
    CEFBS_None, // CVT_D1_S0_R1 = 352
    CEFBS_None, // CVT_D1_S0_R1_P = 353
    CEFBS_None, // CVT_D1_S0_R2 = 354
    CEFBS_None, // CVT_D1_S0_R2_P = 355
    CEFBS_None, // CVT_D1_S0_R3 = 356
    CEFBS_None, // CVT_D1_S0_R3_P = 357
    CEFBS_None, // CVT_D1_S1_R0 = 358
    CEFBS_None, // CVT_D1_S1_R0_P = 359
    CEFBS_None, // CVT_D1_S1_R1 = 360
    CEFBS_None, // CVT_D1_S1_R1_P = 361
    CEFBS_None, // CVT_D1_S1_R2 = 362
    CEFBS_None, // CVT_D1_S1_R2_P = 363
    CEFBS_None, // CVT_D1_S1_R3 = 364
    CEFBS_None, // CVT_D1_S1_R3_P = 365
    CEFBS_None, // CVT_D1_S2_R0 = 366
    CEFBS_None, // CVT_D1_S2_R0_P = 367
    CEFBS_None, // CVT_D1_S2_R1 = 368
    CEFBS_None, // CVT_D1_S2_R1_P = 369
    CEFBS_None, // CVT_D1_S2_R2 = 370
    CEFBS_None, // CVT_D1_S2_R2_P = 371
    CEFBS_None, // CVT_D1_S2_R3 = 372
    CEFBS_None, // CVT_D1_S2_R3_P = 373
    CEFBS_None, // CVT_D1_S3_R0 = 374
    CEFBS_None, // CVT_D1_S3_R0_P = 375
    CEFBS_None, // CVT_D1_S3_R1 = 376
    CEFBS_None, // CVT_D1_S3_R1_P = 377
    CEFBS_None, // CVT_D1_S3_R2 = 378
    CEFBS_None, // CVT_D1_S3_R2_P = 379
    CEFBS_None, // CVT_D1_S3_R3 = 380
    CEFBS_None, // CVT_D1_S3_R3_P = 381
    CEFBS_None, // CVT_D2_S0_R0 = 382
    CEFBS_None, // CVT_D2_S0_R0_P = 383
    CEFBS_None, // CVT_D2_S0_R2 = 384
    CEFBS_None, // CVT_D2_S0_R2_P = 385
    CEFBS_None, // CVT_D2_S0_R3 = 386
    CEFBS_None, // CVT_D2_S0_R3_P = 387
    CEFBS_None, // CVT_D2_S1_R0 = 388
    CEFBS_None, // CVT_D2_S1_R0_P = 389
    CEFBS_None, // CVT_D2_S1_R1 = 390
    CEFBS_None, // CVT_D2_S1_R1_P = 391
    CEFBS_None, // CVT_D2_S1_R2 = 392
    CEFBS_None, // CVT_D2_S1_R2_P = 393
    CEFBS_None, // CVT_D2_S1_R3 = 394
    CEFBS_None, // CVT_D2_S1_R3_P = 395
    CEFBS_None, // CVT_D2_S3_R0 = 396
    CEFBS_None, // CVT_D2_S3_R0_P = 397
    CEFBS_None, // CVT_D3_S0_R0 = 398
    CEFBS_None, // CVT_D3_S0_R0_P = 399
    CEFBS_None, // CVT_D3_S0_R2 = 400
    CEFBS_None, // CVT_D3_S0_R2_P = 401
    CEFBS_None, // CVT_D3_S0_R3 = 402
    CEFBS_None, // CVT_D3_S0_R3_P = 403
    CEFBS_None, // CVT_D3_S1_R0 = 404
    CEFBS_None, // CVT_D3_S1_R0_P = 405
    CEFBS_None, // CVT_D3_S1_R1 = 406
    CEFBS_None, // CVT_D3_S1_R1_P = 407
    CEFBS_None, // CVT_D3_S1_R2 = 408
    CEFBS_None, // CVT_D3_S1_R2_P = 409
    CEFBS_None, // CVT_D3_S1_R3 = 410
    CEFBS_None, // CVT_D3_S1_R3_P = 411
    CEFBS_None, // CVT_D3_S2_R0 = 412
    CEFBS_None, // CVT_D3_S2_R0_P = 413
    CEFBS_None, // CVT_D3_S3_R0 = 414
    CEFBS_None, // CVT_D3_S3_R0_P = 415
    CEFBS_None, // CVT_F32_S32 = 416
    CEFBS_None, // CVT_F32_S32_P = 417
    CEFBS_None, // CVT_F32_U32 = 418
    CEFBS_None, // CVT_F32_U32_P = 419
    CEFBS_None, // CVT_S32_F32 = 420
    CEFBS_None, // CVT_S32_F32_P = 421
    CEFBS_None, // CVT_SEXT = 422
    CEFBS_None, // CVT_U32_F32 = 423
    CEFBS_None, // CVT_U32_F32_P = 424
    CEFBS_None, // C_ABS = 425
    CEFBS_None, // C_ADD = 426
    CEFBS_None, // C_ADDI = 427
    CEFBS_None, // C_AND = 428
    CEFBS_None, // C_ANDI = 429
    CEFBS_None, // C_ANDN = 430
    CEFBS_None, // C_BAR_ARRIVE = 431
    CEFBS_None, // C_BAR_WAIT = 432
    CEFBS_None, // C_BRA = 433
    CEFBS_None, // C_CHWIDTH = 434
    CEFBS_None, // C_EXIT = 435
    CEFBS_None, // C_FADD = 436
    CEFBS_None, // C_FENCE = 437
    CEFBS_None, // C_FMAX = 438
    CEFBS_None, // C_FMIN = 439
    CEFBS_None, // C_FMUL = 440
    CEFBS_None, // C_LD_GLOBAL = 441
    CEFBS_None, // C_MAX_S = 442
    CEFBS_None, // C_MAX_U = 443
    CEFBS_None, // C_MIN_S = 444
    CEFBS_None, // C_MIN_U = 445
    CEFBS_None, // C_MOV = 446
    CEFBS_None, // C_MUL_LO = 447
    CEFBS_None, // C_NEG = 448
    CEFBS_None, // C_NOT = 449
    CEFBS_None, // C_OR = 450
    CEFBS_None, // C_ORI = 451
    CEFBS_None, // C_RECONV = 452
    CEFBS_None, // C_RET = 453
    CEFBS_None, // C_SHL = 454
    CEFBS_None, // C_SHLI = 455
    CEFBS_None, // C_SHR = 456
    CEFBS_None, // C_SHRI = 457
    CEFBS_None, // C_SRA = 458
    CEFBS_None, // C_SRAI = 459
    CEFBS_None, // C_ST_GLOBAL = 460
    CEFBS_None, // C_SUB = 461
    CEFBS_None, // C_SUBI = 462
    CEFBS_None, // C_XOR = 463
    CEFBS_None, // C_XORI = 464
    CEFBS_None, // DP2_BF16 = 465
    CEFBS_None, // DP2_F16 = 466
    CEFBS_None, // DP4_ACC = 467
    CEFBS_None, // DP4_E4M3 = 468
    CEFBS_None, // DP4_E5M2 = 469
    CEFBS_None, // DP4_SS = 470
    CEFBS_None, // EX2_F32 = 471
    CEFBS_None, // FABS_F0 = 472
    CEFBS_None, // FABS_F1 = 473
    CEFBS_None, // FADD = 474
    CEFBS_None, // FADD_F1 = 475
    CEFBS_None, // FADD_P = 476
    CEFBS_None, // FFMA_ACC_F0 = 477
    CEFBS_None, // FFMA_ACC_F1 = 478
    CEFBS_None, // FFMA_F0 = 479
    CEFBS_None, // FFMA_F1 = 480
    CEFBS_None, // FMAX = 481
    CEFBS_None, // FMAX_F1 = 482
    CEFBS_None, // FMIN = 483
    CEFBS_None, // FMIN_F1 = 484
    CEFBS_None, // FMUL = 485
    CEFBS_None, // FMUL_F1 = 486
    CEFBS_None, // FMUL_P = 487
    CEFBS_None, // FNEG_F0 = 488
    CEFBS_None, // FNEG_F1 = 489
    CEFBS_None, // FSUB = 490
    CEFBS_None, // FSUB_F1 = 491
    CEFBS_None, // FSUB_P = 492
    CEFBS_None, // LD_GLOBAL = 493
    CEFBS_None, // LD_GLOBAL_IDX = 494
    CEFBS_None, // LD_GLOBAL_IDX_W16 = 495
    CEFBS_None, // LD_GLOBAL_IDX_W8 = 496
    CEFBS_None, // LD_GLOBAL_P = 497
    CEFBS_None, // LD_GLOBAL_SLOT = 498
    CEFBS_None, // LD_GLOBAL_SLOT_W16 = 499
    CEFBS_None, // LD_GLOBAL_SLOT_W8 = 500
    CEFBS_None, // LD_GLOBAL_W16 = 501
    CEFBS_None, // LD_GLOBAL_W8 = 502
    CEFBS_None, // LD_PRED_G = 503
    CEFBS_None, // LD_PRED_S = 504
    CEFBS_None, // LD_SHARED = 505
    CEFBS_None, // LD_SHARED_IDX = 506
    CEFBS_None, // LD_SHARED_W16 = 507
    CEFBS_None, // LD_SHARED_W8 = 508
    CEFBS_None, // LG2_F32 = 509
    CEFBS_None, // MADLO = 510
    CEFBS_None, // MADLO_P = 511
    CEFBS_None, // MAD_ACC = 512
    CEFBS_None, // MAX_S = 513
    CEFBS_None, // MAX_S_P = 514
    CEFBS_None, // MAX_S_W16 = 515
    CEFBS_None, // MAX_U = 516
    CEFBS_None, // MAX_U_P = 517
    CEFBS_None, // MIN_S = 518
    CEFBS_None, // MIN_S_P = 519
    CEFBS_None, // MIN_S_W16 = 520
    CEFBS_None, // MIN_U = 521
    CEFBS_None, // MIN_U_P = 522
    CEFBS_None, // MOVI = 523
    CEFBS_None, // MOVI48 = 524
    CEFBS_None, // MOV_P = 525
    CEFBS_None, // MULI = 526
    CEFBS_None, // MULI_P = 527
    CEFBS_None, // MUL_HI_S = 528
    CEFBS_None, // MUL_HI_S_P = 529
    CEFBS_None, // MUL_HI_U = 530
    CEFBS_None, // MUL_HI_U_P = 531
    CEFBS_None, // MUL_LO = 532
    CEFBS_None, // NEG = 533
    CEFBS_None, // OR = 534
    CEFBS_None, // ORI = 535
    CEFBS_None, // ORI_P = 536
    CEFBS_None, // OR_P = 537
    CEFBS_None, // OR_W16 = 538
    CEFBS_None, // PACKI = 539
    CEFBS_None, // PACKI_Z = 540
    CEFBS_None, // PAND = 541
    CEFBS_None, // PMOV = 542
    CEFBS_None, // PMOV_IMM = 543
    CEFBS_None, // POPC = 544
    CEFBS_None, // POR = 545
    CEFBS_None, // PXOR = 546
    CEFBS_None, // RCP_F32 = 547
    CEFBS_None, // RCP_F32_P = 548
    CEFBS_None, // RCP_U32 = 549
    CEFBS_None, // RSQRT_F32 = 550
    CEFBS_None, // SEL = 551
    CEFBS_None, // SETP_EQ = 552
    CEFBS_None, // SETP_EQ_F = 553
    CEFBS_None, // SETP_EQ_F1 = 554
    CEFBS_None, // SETP_EQ_F1_NP = 555
    CEFBS_None, // SETP_EQ_F_I = 556
    CEFBS_None, // SETP_EQ_F_NP = 557
    CEFBS_None, // SETP_EQ_F_NPI = 558
    CEFBS_None, // SETP_EQ_I = 559
    CEFBS_None, // SETP_EQ_NP = 560
    CEFBS_None, // SETP_EQ_NPI = 561
    CEFBS_None, // SETP_GE = 562
    CEFBS_None, // SETP_GE_F = 563
    CEFBS_None, // SETP_GE_F1 = 564
    CEFBS_None, // SETP_GE_F1_NP = 565
    CEFBS_None, // SETP_GE_F_I = 566
    CEFBS_None, // SETP_GE_F_NP = 567
    CEFBS_None, // SETP_GE_F_NPI = 568
    CEFBS_None, // SETP_GE_I = 569
    CEFBS_None, // SETP_GE_NP = 570
    CEFBS_None, // SETP_GE_NPI = 571
    CEFBS_None, // SETP_GE_U = 572
    CEFBS_None, // SETP_GE_U_I = 573
    CEFBS_None, // SETP_GE_U_NP = 574
    CEFBS_None, // SETP_GE_U_NPI = 575
    CEFBS_None, // SETP_GT = 576
    CEFBS_None, // SETP_GT_F = 577
    CEFBS_None, // SETP_GT_F1 = 578
    CEFBS_None, // SETP_GT_F1_NP = 579
    CEFBS_None, // SETP_GT_F_I = 580
    CEFBS_None, // SETP_GT_F_NP = 581
    CEFBS_None, // SETP_GT_F_NPI = 582
    CEFBS_None, // SETP_GT_I = 583
    CEFBS_None, // SETP_GT_NP = 584
    CEFBS_None, // SETP_GT_NPI = 585
    CEFBS_None, // SETP_GT_U = 586
    CEFBS_None, // SETP_GT_U_I = 587
    CEFBS_None, // SETP_GT_U_NP = 588
    CEFBS_None, // SETP_GT_U_NPI = 589
    CEFBS_None, // SETP_LE = 590
    CEFBS_None, // SETP_LE_F = 591
    CEFBS_None, // SETP_LE_F1 = 592
    CEFBS_None, // SETP_LE_F1_NP = 593
    CEFBS_None, // SETP_LE_F_I = 594
    CEFBS_None, // SETP_LE_F_NP = 595
    CEFBS_None, // SETP_LE_F_NPI = 596
    CEFBS_None, // SETP_LE_I = 597
    CEFBS_None, // SETP_LE_NP = 598
    CEFBS_None, // SETP_LE_NPI = 599
    CEFBS_None, // SETP_LE_U = 600
    CEFBS_None, // SETP_LE_U_I = 601
    CEFBS_None, // SETP_LE_U_NP = 602
    CEFBS_None, // SETP_LE_U_NPI = 603
    CEFBS_None, // SETP_LT = 604
    CEFBS_None, // SETP_LT_F = 605
    CEFBS_None, // SETP_LT_F1 = 606
    CEFBS_None, // SETP_LT_F1_NP = 607
    CEFBS_None, // SETP_LT_F_I = 608
    CEFBS_None, // SETP_LT_F_NP = 609
    CEFBS_None, // SETP_LT_F_NPI = 610
    CEFBS_None, // SETP_LT_I = 611
    CEFBS_None, // SETP_LT_NP = 612
    CEFBS_None, // SETP_LT_NPI = 613
    CEFBS_None, // SETP_LT_U = 614
    CEFBS_None, // SETP_LT_U_I = 615
    CEFBS_None, // SETP_LT_U_NP = 616
    CEFBS_None, // SETP_LT_U_NPI = 617
    CEFBS_None, // SETP_NE = 618
    CEFBS_None, // SETP_NE_F = 619
    CEFBS_None, // SETP_NE_F1 = 620
    CEFBS_None, // SETP_NE_F1_NP = 621
    CEFBS_None, // SETP_NE_F_I = 622
    CEFBS_None, // SETP_NE_F_NP = 623
    CEFBS_None, // SETP_NE_F_NPI = 624
    CEFBS_None, // SETP_NE_I = 625
    CEFBS_None, // SETP_NE_NP = 626
    CEFBS_None, // SETP_NE_NPI = 627
    CEFBS_None, // SHFL_IDX = 628
    CEFBS_None, // SHL = 629
    CEFBS_None, // SHLI = 630
    CEFBS_None, // SHLI_P = 631
    CEFBS_None, // SHL_P = 632
    CEFBS_None, // SHR = 633
    CEFBS_None, // SHRI = 634
    CEFBS_None, // SHRI_P = 635
    CEFBS_None, // SHR_P = 636
    CEFBS_None, // SIN_F32 = 637
    CEFBS_None, // SQRT_F32 = 638
    CEFBS_None, // SRA = 639
    CEFBS_None, // SRAI = 640
    CEFBS_None, // SRAI_P = 641
    CEFBS_None, // SRA_P = 642
    CEFBS_None, // SRD = 643
    CEFBS_None, // ST_GLOBAL = 644
    CEFBS_None, // ST_GLOBAL_IDX = 645
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 646
    CEFBS_None, // ST_GLOBAL_IDX_W8 = 647
    CEFBS_None, // ST_GLOBAL_SLOT = 648
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 649
    CEFBS_None, // ST_GLOBAL_SLOT_W8 = 650
    CEFBS_None, // ST_GLOBAL_W16 = 651
    CEFBS_None, // ST_GLOBAL_W8 = 652
    CEFBS_None, // ST_PRED_G = 653
    CEFBS_None, // ST_PRED_S = 654
    CEFBS_None, // ST_SHARED = 655
    CEFBS_None, // ST_SHARED_IDX = 656
    CEFBS_None, // ST_SHARED_W16 = 657
    CEFBS_None, // ST_SHARED_W8 = 658
    CEFBS_None, // SUB = 659
    CEFBS_None, // SUBI = 660
    CEFBS_None, // SUBI_P = 661
    CEFBS_None, // SUB_P = 662
    CEFBS_None, // SUB_W16 = 663
    CEFBS_None, // UNBALLOT = 664
    CEFBS_None, // UNPACKI = 665
    CEFBS_None, // VOTE_ANY = 666
    CEFBS_None, // XOR = 667
    CEFBS_None, // XORI = 668
    CEFBS_None, // XORI_P = 669
    CEFBS_None, // XOR_P = 670
    CEFBS_None, // XOR_W16 = 671
  };

  assert(Opcode < 672);
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

