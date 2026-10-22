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
    CVT_D0_S0_R1	= 316,
    CVT_D0_S0_R1_P	= 317,
    CVT_D0_S0_R2	= 318,
    CVT_D0_S0_R2_P	= 319,
    CVT_D0_S0_R3	= 320,
    CVT_D0_S0_R3_P	= 321,
    CVT_D0_S1_R0	= 322,
    CVT_D0_S1_R0_P	= 323,
    CVT_D0_S1_R1	= 324,
    CVT_D0_S1_R1_P	= 325,
    CVT_D0_S1_R2	= 326,
    CVT_D0_S1_R2_P	= 327,
    CVT_D0_S1_R3	= 328,
    CVT_D0_S1_R3_P	= 329,
    CVT_D0_S2_R1	= 330,
    CVT_D0_S2_R1_P	= 331,
    CVT_D0_S2_R2	= 332,
    CVT_D0_S2_R2_P	= 333,
    CVT_D0_S2_R3	= 334,
    CVT_D0_S2_R3_P	= 335,
    CVT_D0_S3_R1	= 336,
    CVT_D0_S3_R1_P	= 337,
    CVT_D0_S3_R2	= 338,
    CVT_D0_S3_R2_P	= 339,
    CVT_D0_S3_R3	= 340,
    CVT_D0_S3_R3_P	= 341,
    CVT_D1_S0_R0	= 342,
    CVT_D1_S0_R0_P	= 343,
    CVT_D1_S0_R1	= 344,
    CVT_D1_S0_R1_P	= 345,
    CVT_D1_S0_R2	= 346,
    CVT_D1_S0_R2_P	= 347,
    CVT_D1_S0_R3	= 348,
    CVT_D1_S0_R3_P	= 349,
    CVT_D1_S1_R0	= 350,
    CVT_D1_S1_R0_P	= 351,
    CVT_D1_S1_R1	= 352,
    CVT_D1_S1_R1_P	= 353,
    CVT_D1_S1_R2	= 354,
    CVT_D1_S1_R2_P	= 355,
    CVT_D1_S1_R3	= 356,
    CVT_D1_S1_R3_P	= 357,
    CVT_D1_S2_R0	= 358,
    CVT_D1_S2_R0_P	= 359,
    CVT_D1_S2_R1	= 360,
    CVT_D1_S2_R1_P	= 361,
    CVT_D1_S2_R2	= 362,
    CVT_D1_S2_R2_P	= 363,
    CVT_D1_S2_R3	= 364,
    CVT_D1_S2_R3_P	= 365,
    CVT_D1_S3_R0	= 366,
    CVT_D1_S3_R0_P	= 367,
    CVT_D1_S3_R1	= 368,
    CVT_D1_S3_R1_P	= 369,
    CVT_D1_S3_R2	= 370,
    CVT_D1_S3_R2_P	= 371,
    CVT_D1_S3_R3	= 372,
    CVT_D1_S3_R3_P	= 373,
    CVT_D2_S0_R0	= 374,
    CVT_D2_S0_R0_P	= 375,
    CVT_D2_S0_R2	= 376,
    CVT_D2_S0_R2_P	= 377,
    CVT_D2_S0_R3	= 378,
    CVT_D2_S0_R3_P	= 379,
    CVT_D2_S1_R0	= 380,
    CVT_D2_S1_R0_P	= 381,
    CVT_D2_S1_R1	= 382,
    CVT_D2_S1_R1_P	= 383,
    CVT_D2_S1_R2	= 384,
    CVT_D2_S1_R2_P	= 385,
    CVT_D2_S1_R3	= 386,
    CVT_D2_S1_R3_P	= 387,
    CVT_D2_S3_R0	= 388,
    CVT_D2_S3_R0_P	= 389,
    CVT_D3_S0_R0	= 390,
    CVT_D3_S0_R0_P	= 391,
    CVT_D3_S0_R2	= 392,
    CVT_D3_S0_R2_P	= 393,
    CVT_D3_S0_R3	= 394,
    CVT_D3_S0_R3_P	= 395,
    CVT_D3_S1_R0	= 396,
    CVT_D3_S1_R0_P	= 397,
    CVT_D3_S1_R1	= 398,
    CVT_D3_S1_R1_P	= 399,
    CVT_D3_S1_R2	= 400,
    CVT_D3_S1_R2_P	= 401,
    CVT_D3_S1_R3	= 402,
    CVT_D3_S1_R3_P	= 403,
    CVT_D3_S2_R0	= 404,
    CVT_D3_S2_R0_P	= 405,
    CVT_D3_S3_R0	= 406,
    CVT_D3_S3_R0_P	= 407,
    CVT_F32_S32	= 408,
    CVT_F32_S32_P	= 409,
    CVT_F32_U32	= 410,
    CVT_F32_U32_P	= 411,
    CVT_S32_F32	= 412,
    CVT_S32_F32_P	= 413,
    CVT_SEXT	= 414,
    CVT_U32_F32	= 415,
    CVT_U32_F32_P	= 416,
    C_ABS	= 417,
    C_ADD	= 418,
    C_ADDI	= 419,
    C_AND	= 420,
    C_ANDI	= 421,
    C_ANDN	= 422,
    C_BAR_ARRIVE	= 423,
    C_BAR_WAIT	= 424,
    C_BRA	= 425,
    C_CHWIDTH	= 426,
    C_EXIT	= 427,
    C_FADD	= 428,
    C_FENCE	= 429,
    C_FMAX	= 430,
    C_FMIN	= 431,
    C_FMUL	= 432,
    C_LD_GLOBAL	= 433,
    C_MAX_S	= 434,
    C_MAX_U	= 435,
    C_MIN_S	= 436,
    C_MIN_U	= 437,
    C_MOV	= 438,
    C_MUL_LO	= 439,
    C_NEG	= 440,
    C_NOT	= 441,
    C_OR	= 442,
    C_ORI	= 443,
    C_RECONV	= 444,
    C_RET	= 445,
    C_SHL	= 446,
    C_SHLI	= 447,
    C_SHR	= 448,
    C_SHRI	= 449,
    C_SRA	= 450,
    C_SRAI	= 451,
    C_ST_GLOBAL	= 452,
    C_SUB	= 453,
    C_SUBI	= 454,
    C_XOR	= 455,
    C_XORI	= 456,
    DP2_BF16	= 457,
    DP2_F16	= 458,
    DP4_ACC	= 459,
    DP4_E4M3	= 460,
    DP4_E5M2	= 461,
    DP4_SS	= 462,
    EX2_F32	= 463,
    FABS_F0	= 464,
    FABS_F1	= 465,
    FADD	= 466,
    FADD_F1	= 467,
    FADD_P	= 468,
    FFMA_ACC_F0	= 469,
    FFMA_ACC_F1	= 470,
    FFMA_F0	= 471,
    FFMA_F1	= 472,
    FMAX	= 473,
    FMAX_F1	= 474,
    FMIN	= 475,
    FMIN_F1	= 476,
    FMUL	= 477,
    FMUL_F1	= 478,
    FMUL_P	= 479,
    FNEG_F0	= 480,
    FNEG_F1	= 481,
    FSUB	= 482,
    FSUB_F1	= 483,
    FSUB_P	= 484,
    LD_GLOBAL	= 485,
    LD_GLOBAL_IDX	= 486,
    LD_GLOBAL_IDX_W16	= 487,
    LD_GLOBAL_IDX_W8	= 488,
    LD_GLOBAL_P	= 489,
    LD_GLOBAL_SLOT	= 490,
    LD_GLOBAL_SLOT_W16	= 491,
    LD_GLOBAL_SLOT_W8	= 492,
    LD_GLOBAL_W16	= 493,
    LD_GLOBAL_W8	= 494,
    LD_PRED_G	= 495,
    LD_PRED_S	= 496,
    LD_SHARED	= 497,
    LD_SHARED_IDX	= 498,
    LD_SHARED_W16	= 499,
    LD_SHARED_W8	= 500,
    LG2_F32	= 501,
    MADLO	= 502,
    MADLO_P	= 503,
    MAD_ACC	= 504,
    MAX_S	= 505,
    MAX_S_P	= 506,
    MAX_S_W16	= 507,
    MAX_U	= 508,
    MAX_U_P	= 509,
    MIN_S	= 510,
    MIN_S_P	= 511,
    MIN_S_W16	= 512,
    MIN_U	= 513,
    MIN_U_P	= 514,
    MOVI	= 515,
    MOVI48	= 516,
    MOV_P	= 517,
    MULI	= 518,
    MULI_P	= 519,
    MUL_HI_S	= 520,
    MUL_HI_S_P	= 521,
    MUL_HI_U	= 522,
    MUL_HI_U_P	= 523,
    MUL_LO	= 524,
    NEG	= 525,
    OR	= 526,
    ORI	= 527,
    ORI_P	= 528,
    OR_P	= 529,
    OR_W16	= 530,
    PACKI	= 531,
    PACKI_Z	= 532,
    PAND	= 533,
    PMOV	= 534,
    PMOV_IMM	= 535,
    POPC	= 536,
    POR	= 537,
    PXOR	= 538,
    RCP_F32	= 539,
    RCP_F32_P	= 540,
    RCP_U32	= 541,
    RSQRT_F32	= 542,
    SEL	= 543,
    SETP_EQ	= 544,
    SETP_EQ_F	= 545,
    SETP_EQ_F1	= 546,
    SETP_EQ_F1_NP	= 547,
    SETP_EQ_F_I	= 548,
    SETP_EQ_F_NP	= 549,
    SETP_EQ_F_NPI	= 550,
    SETP_EQ_I	= 551,
    SETP_EQ_NP	= 552,
    SETP_EQ_NPI	= 553,
    SETP_GE	= 554,
    SETP_GE_F	= 555,
    SETP_GE_F1	= 556,
    SETP_GE_F1_NP	= 557,
    SETP_GE_F_I	= 558,
    SETP_GE_F_NP	= 559,
    SETP_GE_F_NPI	= 560,
    SETP_GE_I	= 561,
    SETP_GE_NP	= 562,
    SETP_GE_NPI	= 563,
    SETP_GE_U	= 564,
    SETP_GE_U_I	= 565,
    SETP_GE_U_NP	= 566,
    SETP_GE_U_NPI	= 567,
    SETP_GT	= 568,
    SETP_GT_F	= 569,
    SETP_GT_F1	= 570,
    SETP_GT_F1_NP	= 571,
    SETP_GT_F_I	= 572,
    SETP_GT_F_NP	= 573,
    SETP_GT_F_NPI	= 574,
    SETP_GT_I	= 575,
    SETP_GT_NP	= 576,
    SETP_GT_NPI	= 577,
    SETP_GT_U	= 578,
    SETP_GT_U_I	= 579,
    SETP_GT_U_NP	= 580,
    SETP_GT_U_NPI	= 581,
    SETP_LE	= 582,
    SETP_LE_F	= 583,
    SETP_LE_F1	= 584,
    SETP_LE_F1_NP	= 585,
    SETP_LE_F_I	= 586,
    SETP_LE_F_NP	= 587,
    SETP_LE_F_NPI	= 588,
    SETP_LE_I	= 589,
    SETP_LE_NP	= 590,
    SETP_LE_NPI	= 591,
    SETP_LE_U	= 592,
    SETP_LE_U_I	= 593,
    SETP_LE_U_NP	= 594,
    SETP_LE_U_NPI	= 595,
    SETP_LT	= 596,
    SETP_LT_F	= 597,
    SETP_LT_F1	= 598,
    SETP_LT_F1_NP	= 599,
    SETP_LT_F_I	= 600,
    SETP_LT_F_NP	= 601,
    SETP_LT_F_NPI	= 602,
    SETP_LT_I	= 603,
    SETP_LT_NP	= 604,
    SETP_LT_NPI	= 605,
    SETP_LT_U	= 606,
    SETP_LT_U_I	= 607,
    SETP_LT_U_NP	= 608,
    SETP_LT_U_NPI	= 609,
    SETP_NE	= 610,
    SETP_NE_F	= 611,
    SETP_NE_F1	= 612,
    SETP_NE_F1_NP	= 613,
    SETP_NE_F_I	= 614,
    SETP_NE_F_NP	= 615,
    SETP_NE_F_NPI	= 616,
    SETP_NE_I	= 617,
    SETP_NE_NP	= 618,
    SETP_NE_NPI	= 619,
    SHFL_IDX	= 620,
    SHL	= 621,
    SHLI	= 622,
    SHLI_P	= 623,
    SHL_P	= 624,
    SHR	= 625,
    SHRI	= 626,
    SHRI_P	= 627,
    SHR_P	= 628,
    SIN_F32	= 629,
    SQRT_F32	= 630,
    SRA	= 631,
    SRAI	= 632,
    SRAI_P	= 633,
    SRA_P	= 634,
    SRD	= 635,
    ST_GLOBAL	= 636,
    ST_GLOBAL_IDX	= 637,
    ST_GLOBAL_IDX_W16	= 638,
    ST_GLOBAL_IDX_W8	= 639,
    ST_GLOBAL_SLOT	= 640,
    ST_GLOBAL_SLOT_W16	= 641,
    ST_GLOBAL_SLOT_W8	= 642,
    ST_GLOBAL_W16	= 643,
    ST_GLOBAL_W8	= 644,
    ST_PRED_G	= 645,
    ST_PRED_S	= 646,
    ST_SHARED	= 647,
    ST_SHARED_IDX	= 648,
    ST_SHARED_W16	= 649,
    ST_SHARED_W8	= 650,
    SUB	= 651,
    SUBI	= 652,
    SUBI_P	= 653,
    SUB_P	= 654,
    SUB_W16	= 655,
    UNBALLOT	= 656,
    UNPACKI	= 657,
    VOTE_ANY	= 658,
    XOR	= 659,
    XORI	= 660,
    XORI_P	= 661,
    XOR_P	= 662,
    XOR_W16	= 663,
    INSTRUCTION_LIST_END = 664
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
  MCInstrDesc Insts[664];
  static_assert(alignof(MCInstrDesc) >= alignof(MCOperandInfo), "Unwanted padding between Insts and OperandInfo");
  MCOperandInfo OperandInfo[305];
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
    { 663,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #663 = XOR_W16
    { 662,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #662 = XOR_P
    { 661,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #661 = XORI_P
    { 660,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #660 = XORI
    { 659,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #659 = XOR
    { 658,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #658 = VOTE_ANY
    { 657,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #657 = UNPACKI
    { 656,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	299,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #656 = UNBALLOT
    { 655,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #655 = SUB_W16
    { 654,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #654 = SUB_P
    { 653,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #653 = SUBI_P
    { 652,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #652 = SUBI
    { 651,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #651 = SUB
    { 650,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #650 = ST_SHARED_W8
    { 649,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #649 = ST_SHARED_W16
    { 648,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #648 = ST_SHARED_IDX
    { 647,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #647 = ST_SHARED
    { 646,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #646 = ST_PRED_S
    { 645,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #645 = ST_PRED_G
    { 644,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #644 = ST_GLOBAL_W8
    { 643,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #643 = ST_GLOBAL_W16
    { 642,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	252,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #642 = ST_GLOBAL_SLOT_W8
    { 641,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	247,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #641 = ST_GLOBAL_SLOT_W16
    { 640,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #640 = ST_GLOBAL_SLOT
    { 639,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	237,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #639 = ST_GLOBAL_IDX_W8
    { 638,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	232,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #638 = ST_GLOBAL_IDX_W16
    { 637,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #637 = ST_GLOBAL_IDX
    { 636,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #636 = ST_GLOBAL
    { 635,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #635 = SRD
    { 634,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #634 = SRA_P
    { 633,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #633 = SRAI_P
    { 632,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #632 = SRAI
    { 631,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #631 = SRA
    { 630,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #630 = SQRT_F32
    { 629,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #629 = SIN_F32
    { 628,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #628 = SHR_P
    { 627,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #627 = SHRI_P
    { 626,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #626 = SHRI
    { 625,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #625 = SHR
    { 624,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #624 = SHL_P
    { 623,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #623 = SHLI_P
    { 622,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #622 = SHLI
    { 621,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #621 = SHL
    { 620,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #620 = SHFL_IDX
    { 619,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #619 = SETP_NE_NPI
    { 618,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #618 = SETP_NE_NP
    { 617,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #617 = SETP_NE_I
    { 616,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #616 = SETP_NE_F_NPI
    { 615,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #615 = SETP_NE_F_NP
    { 614,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #614 = SETP_NE_F_I
    { 613,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #613 = SETP_NE_F1_NP
    { 612,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #612 = SETP_NE_F1
    { 611,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #611 = SETP_NE_F
    { 610,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #610 = SETP_NE
    { 609,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #609 = SETP_LT_U_NPI
    { 608,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #608 = SETP_LT_U_NP
    { 607,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #607 = SETP_LT_U_I
    { 606,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #606 = SETP_LT_U
    { 605,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #605 = SETP_LT_NPI
    { 604,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #604 = SETP_LT_NP
    { 603,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #603 = SETP_LT_I
    { 602,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #602 = SETP_LT_F_NPI
    { 601,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #601 = SETP_LT_F_NP
    { 600,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #600 = SETP_LT_F_I
    { 599,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #599 = SETP_LT_F1_NP
    { 598,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #598 = SETP_LT_F1
    { 597,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #597 = SETP_LT_F
    { 596,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #596 = SETP_LT
    { 595,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #595 = SETP_LE_U_NPI
    { 594,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #594 = SETP_LE_U_NP
    { 593,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #593 = SETP_LE_U_I
    { 592,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #592 = SETP_LE_U
    { 591,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #591 = SETP_LE_NPI
    { 590,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #590 = SETP_LE_NP
    { 589,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #589 = SETP_LE_I
    { 588,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #588 = SETP_LE_F_NPI
    { 587,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #587 = SETP_LE_F_NP
    { 586,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #586 = SETP_LE_F_I
    { 585,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #585 = SETP_LE_F1_NP
    { 584,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #584 = SETP_LE_F1
    { 583,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #583 = SETP_LE_F
    { 582,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #582 = SETP_LE
    { 581,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #581 = SETP_GT_U_NPI
    { 580,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #580 = SETP_GT_U_NP
    { 579,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #579 = SETP_GT_U_I
    { 578,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #578 = SETP_GT_U
    { 577,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #577 = SETP_GT_NPI
    { 576,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #576 = SETP_GT_NP
    { 575,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #575 = SETP_GT_I
    { 574,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #574 = SETP_GT_F_NPI
    { 573,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #573 = SETP_GT_F_NP
    { 572,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #572 = SETP_GT_F_I
    { 571,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #571 = SETP_GT_F1_NP
    { 570,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #570 = SETP_GT_F1
    { 569,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #569 = SETP_GT_F
    { 568,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #568 = SETP_GT
    { 567,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #567 = SETP_GE_U_NPI
    { 566,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #566 = SETP_GE_U_NP
    { 565,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #565 = SETP_GE_U_I
    { 564,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #564 = SETP_GE_U
    { 563,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #563 = SETP_GE_NPI
    { 562,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #562 = SETP_GE_NP
    { 561,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #561 = SETP_GE_I
    { 560,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #560 = SETP_GE_F_NPI
    { 559,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #559 = SETP_GE_F_NP
    { 558,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #558 = SETP_GE_F_I
    { 557,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #557 = SETP_GE_F1_NP
    { 556,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #556 = SETP_GE_F1
    { 555,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #555 = SETP_GE_F
    { 554,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #554 = SETP_GE
    { 553,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #553 = SETP_EQ_NPI
    { 552,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #552 = SETP_EQ_NP
    { 551,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #551 = SETP_EQ_I
    { 550,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #550 = SETP_EQ_F_NPI
    { 549,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #549 = SETP_EQ_F_NP
    { 548,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	290,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #548 = SETP_EQ_F_I
    { 547,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #547 = SETP_EQ_F1_NP
    { 546,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #546 = SETP_EQ_F1
    { 545,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #545 = SETP_EQ_F
    { 544,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #544 = SETP_EQ
    { 543,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #543 = SEL
    { 542,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #542 = RSQRT_F32
    { 541,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #541 = RCP_U32
    { 540,	5,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #540 = RCP_F32_P
    { 539,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #539 = RCP_F32
    { 538,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #538 = PXOR
    { 537,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #537 = POR
    { 536,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #536 = POPC
    { 535,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #535 = PMOV_IMM
    { 534,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #534 = PMOV
    { 533,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #533 = PAND
    { 532,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #532 = PACKI_Z
    { 531,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	272,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #531 = PACKI
    { 530,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #530 = OR_W16
    { 529,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #529 = OR_P
    { 528,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #528 = ORI_P
    { 527,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #527 = ORI
    { 526,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #526 = OR
    { 525,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #525 = NEG
    { 524,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #524 = MUL_LO
    { 523,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #523 = MUL_HI_U_P
    { 522,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #522 = MUL_HI_U
    { 521,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #521 = MUL_HI_S_P
    { 520,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #520 = MUL_HI_S
    { 519,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #519 = MULI_P
    { 518,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #518 = MULI
    { 517,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	266,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #517 = MOV_P
    { 516,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #516 = MOVI48
    { 515,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #515 = MOVI
    { 514,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #514 = MIN_U_P
    { 513,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #513 = MIN_U
    { 512,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #512 = MIN_S_W16
    { 511,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #511 = MIN_S_P
    { 510,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #510 = MIN_S
    { 509,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #509 = MAX_U_P
    { 508,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #508 = MAX_U
    { 507,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #507 = MAX_S_W16
    { 506,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #506 = MAX_S_P
    { 505,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #505 = MAX_S
    { 504,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #504 = MAD_ACC
    { 503,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #503 = MADLO_P
    { 502,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #502 = MADLO
    { 501,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #501 = LG2_F32
    { 500,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #500 = LD_SHARED_W8
    { 499,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #499 = LD_SHARED_W16
    { 498,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #498 = LD_SHARED_IDX
    { 497,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #497 = LD_SHARED
    { 496,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #496 = LD_PRED_S
    { 495,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #495 = LD_PRED_G
    { 494,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #494 = LD_GLOBAL_W8
    { 493,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #493 = LD_GLOBAL_W16
    { 492,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	252,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #492 = LD_GLOBAL_SLOT_W8
    { 491,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	247,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #491 = LD_GLOBAL_SLOT_W16
    { 490,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #490 = LD_GLOBAL_SLOT
    { 489,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #489 = LD_GLOBAL_P
    { 488,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	237,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #488 = LD_GLOBAL_IDX_W8
    { 487,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	232,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #487 = LD_GLOBAL_IDX_W16
    { 486,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #486 = LD_GLOBAL_IDX
    { 485,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #485 = LD_GLOBAL
    { 484,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #484 = FSUB_P
    { 483,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #483 = FSUB_F1
    { 482,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #482 = FSUB
    { 481,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #481 = FNEG_F1
    { 480,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #480 = FNEG_F0
    { 479,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #479 = FMUL_P
    { 478,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #478 = FMUL_F1
    { 477,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #477 = FMUL
    { 476,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #476 = FMIN_F1
    { 475,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #475 = FMIN
    { 474,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #474 = FMAX_F1
    { 473,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #473 = FMAX
    { 472,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #472 = FFMA_F1
    { 471,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #471 = FFMA_F0
    { 470,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #470 = FFMA_ACC_F1
    { 469,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #469 = FFMA_ACC_F0
    { 468,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #468 = FADD_P
    { 467,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #467 = FADD_F1
    { 466,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #466 = FADD
    { 465,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #465 = FABS_F1
    { 464,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #464 = FABS_F0
    { 463,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #463 = EX2_F32
    { 462,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #462 = DP4_SS
    { 461,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #461 = DP4_E5M2
    { 460,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #460 = DP4_E4M3
    { 459,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #459 = DP4_ACC
    { 458,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #458 = DP2_F16
    { 457,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #457 = DP2_BF16
    { 456,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #456 = C_XORI
    { 455,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #455 = C_XOR
    { 454,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #454 = C_SUBI
    { 453,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #453 = C_SUB
    { 452,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #452 = C_ST_GLOBAL
    { 451,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #451 = C_SRAI
    { 450,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #450 = C_SRA
    { 449,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #449 = C_SHRI
    { 448,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #448 = C_SHR
    { 447,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #447 = C_SHLI
    { 446,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #446 = C_SHL
    { 445,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #445 = C_RET
    { 444,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #444 = C_RECONV
    { 443,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #443 = C_ORI
    { 442,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #442 = C_OR
    { 441,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #441 = C_NOT
    { 440,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #440 = C_NEG
    { 439,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #439 = C_MUL_LO
    { 438,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #438 = C_MOV
    { 437,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #437 = C_MIN_U
    { 436,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #436 = C_MIN_S
    { 435,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #435 = C_MAX_U
    { 434,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #434 = C_MAX_S
    { 433,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #433 = C_LD_GLOBAL
    { 432,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #432 = C_FMUL
    { 431,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #431 = C_FMIN
    { 430,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #430 = C_FMAX
    { 429,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #429 = C_FENCE
    { 428,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #428 = C_FADD
    { 427,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #427 = C_EXIT
    { 426,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #426 = C_CHWIDTH
    { 425,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #425 = C_BRA
    { 424,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #424 = C_BAR_WAIT
    { 423,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #423 = C_BAR_ARRIVE
    { 422,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #422 = C_ANDN
    { 421,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #421 = C_ANDI
    { 420,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #420 = C_AND
    { 419,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #419 = C_ADDI
    { 418,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #418 = C_ADD
    { 417,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #417 = C_ABS
    { 416,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #416 = CVT_U32_F32_P
    { 415,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #415 = CVT_U32_F32
    { 414,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #414 = CVT_SEXT
    { 413,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #413 = CVT_S32_F32_P
    { 412,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #412 = CVT_S32_F32
    { 411,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #411 = CVT_F32_U32_P
    { 410,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #410 = CVT_F32_U32
    { 409,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #409 = CVT_F32_S32_P
    { 408,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #408 = CVT_F32_S32
    { 407,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #407 = CVT_D3_S3_R0_P
    { 406,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #406 = CVT_D3_S3_R0
    { 405,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #405 = CVT_D3_S2_R0_P
    { 404,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #404 = CVT_D3_S2_R0
    { 403,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #403 = CVT_D3_S1_R3_P
    { 402,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #402 = CVT_D3_S1_R3
    { 401,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #401 = CVT_D3_S1_R2_P
    { 400,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #400 = CVT_D3_S1_R2
    { 399,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #399 = CVT_D3_S1_R1_P
    { 398,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #398 = CVT_D3_S1_R1
    { 397,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #397 = CVT_D3_S1_R0_P
    { 396,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #396 = CVT_D3_S1_R0
    { 395,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #395 = CVT_D3_S0_R3_P
    { 394,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #394 = CVT_D3_S0_R3
    { 393,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #393 = CVT_D3_S0_R2_P
    { 392,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #392 = CVT_D3_S0_R2
    { 391,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #391 = CVT_D3_S0_R0_P
    { 390,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #390 = CVT_D3_S0_R0
    { 389,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #389 = CVT_D2_S3_R0_P
    { 388,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #388 = CVT_D2_S3_R0
    { 387,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #387 = CVT_D2_S1_R3_P
    { 386,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #386 = CVT_D2_S1_R3
    { 385,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #385 = CVT_D2_S1_R2_P
    { 384,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #384 = CVT_D2_S1_R2
    { 383,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #383 = CVT_D2_S1_R1_P
    { 382,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #382 = CVT_D2_S1_R1
    { 381,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #381 = CVT_D2_S1_R0_P
    { 380,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #380 = CVT_D2_S1_R0
    { 379,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #379 = CVT_D2_S0_R3_P
    { 378,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #378 = CVT_D2_S0_R3
    { 377,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #377 = CVT_D2_S0_R2_P
    { 376,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #376 = CVT_D2_S0_R2
    { 375,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #375 = CVT_D2_S0_R0_P
    { 374,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #374 = CVT_D2_S0_R0
    { 373,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #373 = CVT_D1_S3_R3_P
    { 372,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #372 = CVT_D1_S3_R3
    { 371,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #371 = CVT_D1_S3_R2_P
    { 370,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #370 = CVT_D1_S3_R2
    { 369,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #369 = CVT_D1_S3_R1_P
    { 368,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #368 = CVT_D1_S3_R1
    { 367,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #367 = CVT_D1_S3_R0_P
    { 366,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #366 = CVT_D1_S3_R0
    { 365,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #365 = CVT_D1_S2_R3_P
    { 364,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #364 = CVT_D1_S2_R3
    { 363,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #363 = CVT_D1_S2_R2_P
    { 362,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #362 = CVT_D1_S2_R2
    { 361,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #361 = CVT_D1_S2_R1_P
    { 360,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #360 = CVT_D1_S2_R1
    { 359,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #359 = CVT_D1_S2_R0_P
    { 358,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #358 = CVT_D1_S2_R0
    { 357,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #357 = CVT_D1_S1_R3_P
    { 356,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #356 = CVT_D1_S1_R3
    { 355,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #355 = CVT_D1_S1_R2_P
    { 354,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #354 = CVT_D1_S1_R2
    { 353,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #353 = CVT_D1_S1_R1_P
    { 352,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #352 = CVT_D1_S1_R1
    { 351,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #351 = CVT_D1_S1_R0_P
    { 350,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #350 = CVT_D1_S1_R0
    { 349,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #349 = CVT_D1_S0_R3_P
    { 348,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #348 = CVT_D1_S0_R3
    { 347,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #347 = CVT_D1_S0_R2_P
    { 346,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #346 = CVT_D1_S0_R2
    { 345,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #345 = CVT_D1_S0_R1_P
    { 344,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #344 = CVT_D1_S0_R1
    { 343,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #343 = CVT_D1_S0_R0_P
    { 342,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #342 = CVT_D1_S0_R0
    { 341,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #341 = CVT_D0_S3_R3_P
    { 340,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #340 = CVT_D0_S3_R3
    { 339,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #339 = CVT_D0_S3_R2_P
    { 338,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #338 = CVT_D0_S3_R2
    { 337,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #337 = CVT_D0_S3_R1_P
    { 336,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #336 = CVT_D0_S3_R1
    { 335,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #335 = CVT_D0_S2_R3_P
    { 334,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #334 = CVT_D0_S2_R3
    { 333,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #333 = CVT_D0_S2_R2_P
    { 332,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #332 = CVT_D0_S2_R2
    { 331,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #331 = CVT_D0_S2_R1_P
    { 330,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #330 = CVT_D0_S2_R1
    { 329,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #329 = CVT_D0_S1_R3_P
    { 328,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #328 = CVT_D0_S1_R3
    { 327,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #327 = CVT_D0_S1_R2_P
    { 326,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #326 = CVT_D0_S1_R2
    { 325,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #325 = CVT_D0_S1_R1_P
    { 324,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #324 = CVT_D0_S1_R1
    { 323,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #323 = CVT_D0_S1_R0_P
    { 322,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #322 = CVT_D0_S1_R0
    { 321,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #321 = CVT_D0_S0_R3_P
    { 320,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #320 = CVT_D0_S0_R3
    { 319,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #319 = CVT_D0_S0_R2_P
    { 318,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #318 = CVT_D0_S0_R2
    { 317,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #317 = CVT_D0_S0_R1_P
    { 316,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #316 = CVT_D0_S0_R1
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
    /* 213 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 217 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 220 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 223 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 227 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 232 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 237 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 242 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 247 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 252 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 257 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 260 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 263 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 266 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 272 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 276 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 279 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 281 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 286 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 290 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 295 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 299 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 302 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
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
  /* 601 */ "G_FLOG2\0"
  /* 609 */ "DP4_E5M2\0"
  /* 618 */ "G_FEXP2\0"
  /* 626 */ "CVT_D0_S0_R2\0"
  /* 639 */ "CVT_D1_S0_R2\0"
  /* 652 */ "CVT_D2_S0_R2\0"
  /* 665 */ "CVT_D3_S0_R2\0"
  /* 678 */ "CVT_D0_S1_R2\0"
  /* 691 */ "CVT_D1_S1_R2\0"
  /* 704 */ "CVT_D2_S1_R2\0"
  /* 717 */ "CVT_D3_S1_R2\0"
  /* 730 */ "CVT_D0_S2_R2\0"
  /* 743 */ "CVT_D1_S2_R2\0"
  /* 756 */ "CVT_D0_S3_R2\0"
  /* 769 */ "CVT_D1_S3_R2\0"
  /* 782 */ "DP4_E4M3\0"
  /* 791 */ "CVT_D0_S0_R3\0"
  /* 804 */ "CVT_D1_S0_R3\0"
  /* 817 */ "CVT_D2_S0_R3\0"
  /* 830 */ "CVT_D3_S0_R3\0"
  /* 843 */ "CVT_D0_S1_R3\0"
  /* 856 */ "CVT_D1_S1_R3\0"
  /* 869 */ "CVT_D2_S1_R3\0"
  /* 882 */ "CVT_D3_S1_R3\0"
  /* 895 */ "CVT_D0_S2_R3\0"
  /* 908 */ "CVT_D1_S2_R3\0"
  /* 921 */ "CVT_D0_S3_R3\0"
  /* 934 */ "CVT_D1_S3_R3\0"
  /* 947 */ "DP2_BF16\0"
  /* 956 */ "DP2_F16\0"
  /* 964 */ "SUB_W16\0"
  /* 972 */ "ADD_W16\0"
  /* 980 */ "LD_SHARED_W16\0"
  /* 994 */ "ST_SHARED_W16\0"
  /* 1008 */ "AND_W16\0"
  /* 1016 */ "ADDI_W16\0"
  /* 1025 */ "LD_GLOBAL_W16\0"
  /* 1039 */ "ST_GLOBAL_W16\0"
  /* 1053 */ "XOR_W16\0"
  /* 1061 */ "MIN_S_W16\0"
  /* 1071 */ "MAX_S_W16\0"
  /* 1081 */ "LD_GLOBAL_SLOT_W16\0"
  /* 1100 */ "ST_GLOBAL_SLOT_W16\0"
  /* 1119 */ "LD_GLOBAL_IDX_W16\0"
  /* 1137 */ "ST_GLOBAL_IDX_W16\0"
  /* 1155 */ "ADDI48\0"
  /* 1162 */ "MOVI48\0"
  /* 1169 */ "LD_SHARED_W8\0"
  /* 1182 */ "ST_SHARED_W8\0"
  /* 1195 */ "LD_GLOBAL_W8\0"
  /* 1208 */ "ST_GLOBAL_W8\0"
  /* 1221 */ "LD_GLOBAL_SLOT_W8\0"
  /* 1239 */ "ST_GLOBAL_SLOT_W8\0"
  /* 1257 */ "LD_GLOBAL_IDX_W8\0"
  /* 1274 */ "ST_GLOBAL_IDX_W8\0"
  /* 1291 */ "G_FMA\0"
  /* 1297 */ "G_STRICT_FMA\0"
  /* 1310 */ "C_BRA\0"
  /* 1316 */ "C_SRA\0"
  /* 1322 */ "G_FSUB\0"
  /* 1329 */ "G_STRICT_FSUB\0"
  /* 1343 */ "G_ATOMICRMW_FSUB\0"
  /* 1360 */ "C_SUB\0"
  /* 1366 */ "G_SUB\0"
  /* 1372 */ "G_ATOMICRMW_SUB\0"
  /* 1388 */ "DP4_ACC\0"
  /* 1396 */ "MAD_ACC\0"
  /* 1404 */ "G_INTRINSIC\0"
  /* 1416 */ "G_FPTRUNC\0"
  /* 1426 */ "G_INTRINSIC_TRUNC\0"
  /* 1444 */ "G_TRUNC\0"
  /* 1452 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 1473 */ "G_DYN_STACKALLOC\0"
  /* 1490 */ "POPC\0"
  /* 1495 */ "G_FMAD\0"
  /* 1502 */ "G_INDEXED_SEXTLOAD\0"
  /* 1521 */ "G_SEXTLOAD\0"
  /* 1532 */ "G_INDEXED_ZEXTLOAD\0"
  /* 1551 */ "G_ZEXTLOAD\0"
  /* 1562 */ "G_INDEXED_LOAD\0"
  /* 1577 */ "G_LOAD\0"
  /* 1584 */ "C_FADD\0"
  /* 1591 */ "G_VECREDUCE_FADD\0"
  /* 1608 */ "G_FADD\0"
  /* 1615 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 1636 */ "G_STRICT_FADD\0"
  /* 1650 */ "G_ATOMICRMW_FADD\0"
  /* 1667 */ "C_ADD\0"
  /* 1673 */ "G_VECREDUCE_ADD\0"
  /* 1689 */ "G_ADD\0"
  /* 1695 */ "G_PTR_ADD\0"
  /* 1705 */ "G_ATOMICRMW_ADD\0"
  /* 1721 */ "LD_SHARED\0"
  /* 1731 */ "ST_SHARED\0"
  /* 1741 */ "PSEUDO_BRA_PRED\0"
  /* 1757 */ "PSEUDO_LD_PRED\0"
  /* 1772 */ "PSEUDO_ST_PRED\0"
  /* 1787 */ "G_ATOMICRMW_NAND\0"
  /* 1804 */ "PSEUDO_PAND\0"
  /* 1816 */ "C_AND\0"
  /* 1822 */ "G_VECREDUCE_AND\0"
  /* 1838 */ "G_AND\0"
  /* 1844 */ "G_ATOMICRMW_AND\0"
  /* 1860 */ "LIFETIME_END\0"
  /* 1873 */ "G_BRCOND\0"
  /* 1882 */ "G_LLROUND\0"
  /* 1892 */ "G_LROUND\0"
  /* 1901 */ "G_INTRINSIC_ROUND\0"
  /* 1919 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 1945 */ "LOAD_STACK_GUARD\0"
  /* 1962 */ "SRD\0"
  /* 1966 */ "PSEUDO_PROBE\0"
  /* 1979 */ "G_SSUBE\0"
  /* 1987 */ "G_USUBE\0"
  /* 1995 */ "C_FENCE\0"
  /* 2003 */ "G_FENCE\0"
  /* 2011 */ "ARITH_FENCE\0"
  /* 2023 */ "REG_SEQUENCE\0"
  /* 2036 */ "G_SADDE\0"
  /* 2044 */ "G_UADDE\0"
  /* 2052 */ "G_GET_FPMODE\0"
  /* 2065 */ "G_RESET_FPMODE\0"
  /* 2080 */ "G_SET_FPMODE\0"
  /* 2093 */ "G_FMINNUM_IEEE\0"
  /* 2108 */ "G_FMAXNUM_IEEE\0"
  /* 2123 */ "SETP_GE\0"
  /* 2131 */ "G_JUMP_TABLE\0"
  /* 2144 */ "BUNDLE\0"
  /* 2151 */ "SETP_LE\0"
  /* 2159 */ "G_MEMCPY_INLINE\0"
  /* 2175 */ "SETP_NE\0"
  /* 2183 */ "LOCAL_ESCAPE\0"
  /* 2196 */ "G_STACKRESTORE\0"
  /* 2211 */ "G_INDEXED_STORE\0"
  /* 2227 */ "G_STORE\0"
  /* 2235 */ "BAR_WAIT_PHASE\0"
  /* 2250 */ "G_BITREVERSE\0"
  /* 2263 */ "DBG_VALUE\0"
  /* 2273 */ "G_GLOBAL_VALUE\0"
  /* 2288 */ "G_STACKSAVE\0"
  /* 2300 */ "C_BAR_ARRIVE\0"
  /* 2313 */ "G_MEMMOVE\0"
  /* 2323 */ "G_FREEZE\0"
  /* 2332 */ "G_FCANONICALIZE\0"
  /* 2348 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 2366 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 2384 */ "G_IMPLICIT_DEF\0"
  /* 2399 */ "DBG_INSTR_REF\0"
  /* 2413 */ "SETP_GE_F\0"
  /* 2423 */ "SETP_LE_F\0"
  /* 2433 */ "SETP_NE_F\0"
  /* 2443 */ "SETP_EQ_F\0"
  /* 2453 */ "SETP_GT_F\0"
  /* 2463 */ "SETP_LT_F\0"
  /* 2473 */ "G_FNEG\0"
  /* 2480 */ "C_NEG\0"
  /* 2486 */ "EXTRACT_SUBREG\0"
  /* 2501 */ "INSERT_SUBREG\0"
  /* 2515 */ "G_SEXT_INREG\0"
  /* 2528 */ "SUBREG_TO_REG\0"
  /* 2542 */ "G_ATOMIC_CMPXCHG\0"
  /* 2559 */ "G_ATOMICRMW_XCHG\0"
  /* 2576 */ "G_FLOG\0"
  /* 2583 */ "G_VAARG\0"
  /* 2591 */ "PREALLOCATED_ARG\0"
  /* 2608 */ "ATOM_ADD_G\0"
  /* 2619 */ "LD_PRED_G\0"
  /* 2629 */ "ST_PRED_G\0"
  /* 2639 */ "CAS_G\0"
  /* 2645 */ "G_PREFETCH\0"
  /* 2656 */ "G_SMULH\0"
  /* 2664 */ "G_UMULH\0"
  /* 2672 */ "C_CHWIDTH\0"
  /* 2682 */ "C_SRAI\0"
  /* 2689 */ "C_SUBI\0"
  /* 2696 */ "C_ADDI\0"
  /* 2703 */ "C_ANDI\0"
  /* 2710 */ "DBG_PHI\0"
  /* 2718 */ "UNPACKI\0"
  /* 2726 */ "C_SHLI\0"
  /* 2733 */ "MULI\0"
  /* 2738 */ "ANDNI\0"
  /* 2744 */ "SETP_GE_NPI\0"
  /* 2756 */ "SETP_LE_NPI\0"
  /* 2768 */ "SETP_NE_NPI\0"
  /* 2780 */ "SETP_GE_F_NPI\0"
  /* 2794 */ "SETP_LE_F_NPI\0"
  /* 2808 */ "SETP_NE_F_NPI\0"
  /* 2822 */ "SETP_EQ_F_NPI\0"
  /* 2836 */ "SETP_GT_F_NPI\0"
  /* 2850 */ "SETP_LT_F_NPI\0"
  /* 2864 */ "SETP_EQ_NPI\0"
  /* 2876 */ "SETP_GT_NPI\0"
  /* 2888 */ "SETP_LT_NPI\0"
  /* 2900 */ "SETP_GE_U_NPI\0"
  /* 2914 */ "SETP_LE_U_NPI\0"
  /* 2928 */ "SETP_GT_U_NPI\0"
  /* 2942 */ "SETP_LT_U_NPI\0"
  /* 2956 */ "C_SHRI\0"
  /* 2963 */ "C_XORI\0"
  /* 2970 */ "C_ORI\0"
  /* 2976 */ "G_FPTOSI\0"
  /* 2985 */ "CHWIDTH_MULTI\0"
  /* 2999 */ "G_FPTOUI\0"
  /* 3008 */ "MOVI\0"
  /* 3013 */ "G_FPOWI\0"
  /* 3021 */ "SETP_GE_I\0"
  /* 3031 */ "SETP_LE_I\0"
  /* 3041 */ "SETP_NE_I\0"
  /* 3051 */ "SETP_GE_F_I\0"
  /* 3063 */ "SETP_LE_F_I\0"
  /* 3075 */ "SETP_NE_F_I\0"
  /* 3087 */ "SETP_EQ_F_I\0"
  /* 3099 */ "SETP_GT_F_I\0"
  /* 3111 */ "SETP_LT_F_I\0"
  /* 3123 */ "SETP_EQ_I\0"
  /* 3133 */ "SETP_GT_I\0"
  /* 3143 */ "SETP_LT_I\0"
  /* 3153 */ "SETP_GE_U_I\0"
  /* 3165 */ "SETP_LE_U_I\0"
  /* 3177 */ "SETP_GT_U_I\0"
  /* 3189 */ "SETP_LT_U_I\0"
  /* 3201 */ "G_PTRMASK\0"
  /* 3211 */ "C_LD_GLOBAL\0"
  /* 3223 */ "C_ST_GLOBAL\0"
  /* 3235 */ "GC_LABEL\0"
  /* 3244 */ "DBG_LABEL\0"
  /* 3254 */ "EH_LABEL\0"
  /* 3263 */ "ANNOTATION_LABEL\0"
  /* 3280 */ "ICALL_BRANCH_FUNNEL\0"
  /* 3300 */ "SEL\0"
  /* 3304 */ "G_FSHL\0"
  /* 3311 */ "C_SHL\0"
  /* 3317 */ "G_SHL\0"
  /* 3323 */ "G_FCEIL\0"
  /* 3331 */ "PATCHABLE_TAIL_CALL\0"
  /* 3351 */ "PSEUDO_CALL\0"
  /* 3363 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 3390 */ "PATCHABLE_EVENT_CALL\0"
  /* 3411 */ "FENTRY_CALL\0"
  /* 3423 */ "KILL\0"
  /* 3428 */ "G_CONSTANT_POOL\0"
  /* 3444 */ "G_ROTL\0"
  /* 3451 */ "C_FMUL\0"
  /* 3458 */ "G_VECREDUCE_FMUL\0"
  /* 3475 */ "G_FMUL\0"
  /* 3482 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 3503 */ "G_STRICT_FMUL\0"
  /* 3517 */ "G_VECREDUCE_MUL\0"
  /* 3533 */ "G_MUL\0"
  /* 3539 */ "G_FREM\0"
  /* 3546 */ "G_STRICT_FREM\0"
  /* 3560 */ "G_SREM\0"
  /* 3567 */ "G_UREM\0"
  /* 3574 */ "G_SDIVREM\0"
  /* 3584 */ "G_UDIVREM\0"
  /* 3594 */ "PMOV_IMM\0"
  /* 3603 */ "INLINEASM\0"
  /* 3613 */ "G_VECREDUCE_FMINIMUM\0"
  /* 3634 */ "G_FMINIMUM\0"
  /* 3645 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 3666 */ "G_FMAXIMUM\0"
  /* 3677 */ "G_FMINNUM\0"
  /* 3687 */ "G_FMAXNUM\0"
  /* 3697 */ "C_ANDN\0"
  /* 3704 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 3726 */ "G_ASSERT_ALIGN\0"
  /* 3741 */ "G_FCOPYSIGN\0"
  /* 3753 */ "C_FMIN\0"
  /* 3760 */ "G_VECREDUCE_FMIN\0"
  /* 3777 */ "G_ATOMICRMW_FMIN\0"
  /* 3794 */ "G_VECREDUCE_SMIN\0"
  /* 3811 */ "G_SMIN\0"
  /* 3818 */ "G_VECREDUCE_UMIN\0"
  /* 3835 */ "G_UMIN\0"
  /* 3842 */ "G_ATOMICRMW_UMIN\0"
  /* 3859 */ "G_ATOMICRMW_MIN\0"
  /* 3875 */ "G_FSIN\0"
  /* 3882 */ "CFI_INSTRUCTION\0"
  /* 3898 */ "ADJCALLSTACKDOWN\0"
  /* 3915 */ "G_SSUBO\0"
  /* 3923 */ "G_USUBO\0"
  /* 3931 */ "G_SADDO\0"
  /* 3939 */ "G_UADDO\0"
  /* 3947 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 3969 */ "MADLO\0"
  /* 3975 */ "G_SMULO\0"
  /* 3983 */ "G_UMULO\0"
  /* 3991 */ "C_MUL_LO\0"
  /* 4000 */ "G_BZERO\0"
  /* 4008 */ "STACKMAP\0"
  /* 4017 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 4039 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 4061 */ "G_BSWAP\0"
  /* 4069 */ "G_SITOFP\0"
  /* 4078 */ "G_UITOFP\0"
  /* 4087 */ "G_FCMP\0"
  /* 4094 */ "G_ICMP\0"
  /* 4101 */ "SETP_GE_F1_NP\0"
  /* 4115 */ "SETP_LE_F1_NP\0"
  /* 4129 */ "SETP_NE_F1_NP\0"
  /* 4143 */ "SETP_EQ_F1_NP\0"
  /* 4157 */ "SETP_GT_F1_NP\0"
  /* 4171 */ "SETP_LT_F1_NP\0"
  /* 4185 */ "SETP_GE_NP\0"
  /* 4196 */ "SETP_LE_NP\0"
  /* 4207 */ "SETP_NE_NP\0"
  /* 4218 */ "SETP_GE_F_NP\0"
  /* 4231 */ "SETP_LE_F_NP\0"
  /* 4244 */ "SETP_NE_F_NP\0"
  /* 4257 */ "SETP_EQ_F_NP\0"
  /* 4270 */ "SETP_GT_F_NP\0"
  /* 4283 */ "SETP_LT_F_NP\0"
  /* 4296 */ "SETP_EQ_NP\0"
  /* 4307 */ "SETP_GT_NP\0"
  /* 4318 */ "SETP_LT_NP\0"
  /* 4329 */ "SETP_GE_U_NP\0"
  /* 4342 */ "SETP_LE_U_NP\0"
  /* 4355 */ "SETP_GT_U_NP\0"
  /* 4368 */ "SETP_LT_U_NP\0"
  /* 4381 */ "G_CTPOP\0"
  /* 4389 */ "PATCHABLE_OP\0"
  /* 4402 */ "FAULTING_OP\0"
  /* 4414 */ "ADD_PP\0"
  /* 4421 */ "ADDI_PP\0"
  /* 4429 */ "ADJCALLSTACKUP\0"
  /* 4444 */ "PREALLOCATED_SETUP\0"
  /* 4463 */ "G_FLDEXP\0"
  /* 4472 */ "G_STRICT_FLDEXP\0"
  /* 4488 */ "G_FEXP\0"
  /* 4495 */ "G_FFREXP\0"
  /* 4504 */ "CVT_D0_S0_R0_P\0"
  /* 4519 */ "CVT_D1_S0_R0_P\0"
  /* 4534 */ "CVT_D2_S0_R0_P\0"
  /* 4549 */ "CVT_D3_S0_R0_P\0"
  /* 4564 */ "CVT_D0_S1_R0_P\0"
  /* 4579 */ "CVT_D1_S1_R0_P\0"
  /* 4594 */ "CVT_D2_S1_R0_P\0"
  /* 4609 */ "CVT_D3_S1_R0_P\0"
  /* 4624 */ "CVT_D1_S2_R0_P\0"
  /* 4639 */ "CVT_D3_S2_R0_P\0"
  /* 4654 */ "CVT_D1_S3_R0_P\0"
  /* 4669 */ "CVT_D2_S3_R0_P\0"
  /* 4684 */ "CVT_D3_S3_R0_P\0"
  /* 4699 */ "CVT_D0_S0_R1_P\0"
  /* 4714 */ "CVT_D1_S0_R1_P\0"
  /* 4729 */ "CVT_D0_S1_R1_P\0"
  /* 4744 */ "CVT_D1_S1_R1_P\0"
  /* 4759 */ "CVT_D2_S1_R1_P\0"
  /* 4774 */ "CVT_D3_S1_R1_P\0"
  /* 4789 */ "CVT_D0_S2_R1_P\0"
  /* 4804 */ "CVT_D1_S2_R1_P\0"
  /* 4819 */ "CVT_D0_S3_R1_P\0"
  /* 4834 */ "CVT_D1_S3_R1_P\0"
  /* 4849 */ "CVT_S32_F32_P\0"
  /* 4863 */ "CVT_U32_F32_P\0"
  /* 4877 */ "RCP_F32_P\0"
  /* 4887 */ "CVT_F32_S32_P\0"
  /* 4901 */ "CVT_F32_U32_P\0"
  /* 4915 */ "CVT_D0_S0_R2_P\0"
  /* 4930 */ "CVT_D1_S0_R2_P\0"
  /* 4945 */ "CVT_D2_S0_R2_P\0"
  /* 4960 */ "CVT_D3_S0_R2_P\0"
  /* 4975 */ "CVT_D0_S1_R2_P\0"
  /* 4990 */ "CVT_D1_S1_R2_P\0"
  /* 5005 */ "CVT_D2_S1_R2_P\0"
  /* 5020 */ "CVT_D3_S1_R2_P\0"
  /* 5035 */ "CVT_D0_S2_R2_P\0"
  /* 5050 */ "CVT_D1_S2_R2_P\0"
  /* 5065 */ "CVT_D0_S3_R2_P\0"
  /* 5080 */ "CVT_D1_S3_R2_P\0"
  /* 5095 */ "CVT_D0_S0_R3_P\0"
  /* 5110 */ "CVT_D1_S0_R3_P\0"
  /* 5125 */ "CVT_D2_S0_R3_P\0"
  /* 5140 */ "CVT_D3_S0_R3_P\0"
  /* 5155 */ "CVT_D0_S1_R3_P\0"
  /* 5170 */ "CVT_D1_S1_R3_P\0"
  /* 5185 */ "CVT_D2_S1_R3_P\0"
  /* 5200 */ "CVT_D3_S1_R3_P\0"
  /* 5215 */ "CVT_D0_S2_R3_P\0"
  /* 5230 */ "CVT_D1_S2_R3_P\0"
  /* 5245 */ "CVT_D0_S3_R3_P\0"
  /* 5260 */ "CVT_D1_S3_R3_P\0"
  /* 5275 */ "SRA_P\0"
  /* 5281 */ "FSUB_P\0"
  /* 5288 */ "FADD_P\0"
  /* 5295 */ "AND_P\0"
  /* 5301 */ "SRAI_P\0"
  /* 5308 */ "SUBI_P\0"
  /* 5315 */ "ADDI_P\0"
  /* 5322 */ "ANDI_P\0"
  /* 5329 */ "SHLI_P\0"
  /* 5336 */ "MULI_P\0"
  /* 5343 */ "ANDNI_P\0"
  /* 5351 */ "SHRI_P\0"
  /* 5358 */ "XORI_P\0"
  /* 5365 */ "LD_GLOBAL_P\0"
  /* 5377 */ "SHL_P\0"
  /* 5383 */ "FMUL_P\0"
  /* 5390 */ "MADLO_P\0"
  /* 5398 */ "SHR_P\0"
  /* 5404 */ "XOR_P\0"
  /* 5410 */ "MUL_HI_S_P\0"
  /* 5421 */ "MIN_S_P\0"
  /* 5429 */ "MAX_S_P\0"
  /* 5437 */ "MUL_HI_U_P\0"
  /* 5448 */ "MIN_U_P\0"
  /* 5456 */ "MAX_U_P\0"
  /* 5464 */ "MOV_P\0"
  /* 5470 */ "SETP_EQ\0"
  /* 5478 */ "G_BR\0"
  /* 5483 */ "INLINEASM_BR\0"
  /* 5496 */ "G_BLOCK_ADDR\0"
  /* 5509 */ "MEMBARRIER\0"
  /* 5520 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 5544 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 5569 */ "G_READCYCLECOUNTER\0"
  /* 5588 */ "G_READ_REGISTER\0"
  /* 5604 */ "G_WRITE_REGISTER\0"
  /* 5621 */ "G_ASHR\0"
  /* 5628 */ "G_FSHR\0"
  /* 5635 */ "G_LSHR\0"
  /* 5642 */ "C_SHR\0"
  /* 5648 */ "G_FFLOOR\0"
  /* 5657 */ "PSEUDO_POR\0"
  /* 5668 */ "G_BUILD_VECTOR\0"
  /* 5683 */ "G_SHUFFLE_VECTOR\0"
  /* 5700 */ "PSEUDO_PXOR\0"
  /* 5712 */ "C_XOR\0"
  /* 5718 */ "G_VECREDUCE_XOR\0"
  /* 5734 */ "G_XOR\0"
  /* 5740 */ "G_ATOMICRMW_XOR\0"
  /* 5756 */ "C_OR\0"
  /* 5761 */ "G_VECREDUCE_OR\0"
  /* 5776 */ "G_OR\0"
  /* 5781 */ "G_ATOMICRMW_OR\0"
  /* 5796 */ "G_ROTR\0"
  /* 5803 */ "G_INTTOPTR\0"
  /* 5814 */ "G_FABS\0"
  /* 5821 */ "C_ABS\0"
  /* 5827 */ "G_ABS\0"
  /* 5833 */ "G_UNMERGE_VALUES\0"
  /* 5850 */ "G_MERGE_VALUES\0"
  /* 5865 */ "G_FCOS\0"
  /* 5872 */ "G_CONCAT_VECTORS\0"
  /* 5889 */ "COPY_TO_REGCLASS\0"
  /* 5906 */ "G_IS_FPCLASS\0"
  /* 5919 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 5949 */ "DP4_SS\0"
  /* 5956 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 5983 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 6021 */ "LD_PRED_S\0"
  /* 6031 */ "ST_PRED_S\0"
  /* 6041 */ "MUL_HI_S\0"
  /* 6050 */ "C_MIN_S\0"
  /* 6058 */ "C_MAX_S\0"
  /* 6066 */ "G_SSUBSAT\0"
  /* 6076 */ "G_USUBSAT\0"
  /* 6086 */ "G_SADDSAT\0"
  /* 6096 */ "G_UADDSAT\0"
  /* 6106 */ "G_SSHLSAT\0"
  /* 6116 */ "G_USHLSAT\0"
  /* 6126 */ "G_SMULFIXSAT\0"
  /* 6139 */ "G_UMULFIXSAT\0"
  /* 6152 */ "G_SDIVFIXSAT\0"
  /* 6165 */ "G_UDIVFIXSAT\0"
  /* 6178 */ "G_EXTRACT\0"
  /* 6188 */ "G_SELECT\0"
  /* 6197 */ "G_BRINDIRECT\0"
  /* 6210 */ "C_RET\0"
  /* 6216 */ "PATCHABLE_RET\0"
  /* 6230 */ "PSEUDO_RET\0"
  /* 6241 */ "G_MEMSET\0"
  /* 6250 */ "SETP_GT\0"
  /* 6258 */ "C_BAR_WAIT\0"
  /* 6269 */ "BAR_INIT\0"
  /* 6278 */ "C_EXIT\0"
  /* 6285 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 6309 */ "G_BRJT\0"
  /* 6316 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 6337 */ "G_INSERT_VECTOR_ELT\0"
  /* 6357 */ "SETP_LT\0"
  /* 6365 */ "G_FCONSTANT\0"
  /* 6377 */ "G_CONSTANT\0"
  /* 6388 */ "G_INTRINSIC_CONVERGENT\0"
  /* 6411 */ "STATEPOINT\0"
  /* 6422 */ "PATCHPOINT\0"
  /* 6433 */ "G_PTRTOINT\0"
  /* 6444 */ "G_FRINT\0"
  /* 6452 */ "G_INTRINSIC_LRINT\0"
  /* 6470 */ "G_FNEARBYINT\0"
  /* 6483 */ "UNBALLOT\0"
  /* 6492 */ "LD_GLOBAL_SLOT\0"
  /* 6507 */ "ST_GLOBAL_SLOT\0"
  /* 6522 */ "C_NOT\0"
  /* 6528 */ "G_VASTART\0"
  /* 6538 */ "LIFETIME_START\0"
  /* 6553 */ "G_INVOKE_REGION_START\0"
  /* 6575 */ "G_INSERT\0"
  /* 6584 */ "G_FSQRT\0"
  /* 6592 */ "G_STRICT_FSQRT\0"
  /* 6607 */ "PSEUDO_BCAST\0"
  /* 6620 */ "G_BITCAST\0"
  /* 6630 */ "G_ADDRSPACE_CAST\0"
  /* 6647 */ "DBG_VALUE_LIST\0"
  /* 6662 */ "G_FPEXT\0"
  /* 6670 */ "G_SEXT\0"
  /* 6677 */ "G_ASSERT_SEXT\0"
  /* 6691 */ "CVT_SEXT\0"
  /* 6700 */ "G_ANYEXT\0"
  /* 6709 */ "G_ZEXT\0"
  /* 6716 */ "G_ASSERT_ZEXT\0"
  /* 6730 */ "SETP_GE_U\0"
  /* 6740 */ "SETP_LE_U\0"
  /* 6750 */ "MUL_HI_U\0"
  /* 6759 */ "C_MIN_U\0"
  /* 6767 */ "SETP_GT_U\0"
  /* 6777 */ "SETP_LT_U\0"
  /* 6787 */ "C_MAX_U\0"
  /* 6795 */ "BREV\0"
  /* 6800 */ "G_FDIV\0"
  /* 6807 */ "G_STRICT_FDIV\0"
  /* 6821 */ "G_SDIV\0"
  /* 6828 */ "G_UDIV\0"
  /* 6835 */ "G_GET_FPENV\0"
  /* 6847 */ "G_RESET_FPENV\0"
  /* 6861 */ "G_SET_FPENV\0"
  /* 6873 */ "C_RECONV\0"
  /* 6882 */ "PSEUDO_PMOV\0"
  /* 6894 */ "C_MOV\0"
  /* 6900 */ "G_FPOW\0"
  /* 6907 */ "PSEUDO_NARROW\0"
  /* 6921 */ "C_FMAX\0"
  /* 6928 */ "G_VECREDUCE_FMAX\0"
  /* 6945 */ "G_ATOMICRMW_FMAX\0"
  /* 6962 */ "G_VECREDUCE_SMAX\0"
  /* 6979 */ "G_SMAX\0"
  /* 6986 */ "G_VECREDUCE_UMAX\0"
  /* 7003 */ "G_UMAX\0"
  /* 7010 */ "G_ATOMICRMW_UMAX\0"
  /* 7027 */ "G_ATOMICRMW_MAX\0"
  /* 7043 */ "LD_SHARED_IDX\0"
  /* 7057 */ "ST_SHARED_IDX\0"
  /* 7071 */ "LD_GLOBAL_IDX\0"
  /* 7085 */ "ST_GLOBAL_IDX\0"
  /* 7099 */ "SHFL_IDX\0"
  /* 7108 */ "G_FRAME_INDEX\0"
  /* 7122 */ "G_SBFX\0"
  /* 7129 */ "G_UBFX\0"
  /* 7136 */ "G_SMULFIX\0"
  /* 7146 */ "G_UMULFIX\0"
  /* 7156 */ "G_SDIVFIX\0"
  /* 7166 */ "G_UDIVFIX\0"
  /* 7176 */ "VOTE_ANY\0"
  /* 7185 */ "G_MEMCPY\0"
  /* 7194 */ "COPY\0"
  /* 7199 */ "CLZ\0"
  /* 7203 */ "G_CTLZ\0"
  /* 7210 */ "G_CTTZ\0"
  /* 7217 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    2714U, 3603U, 5483U, 3882U, 3254U, 3235U, 3263U, 3423U, 
    2486U, 2501U, 2386U, 2528U, 5889U, 2263U, 6647U, 2399U, 
    2710U, 3244U, 2023U, 7194U, 2144U, 6538U, 1860U, 1966U, 
    2011U, 4008U, 3411U, 6422U, 1945U, 4444U, 2591U, 6411U, 
    2183U, 4402U, 4389U, 5544U, 6216U, 6285U, 3331U, 3390U, 
    3363U, 3280U, 5509U, 3947U, 6677U, 6716U, 3726U, 1689U, 
    1366U, 3533U, 6821U, 6828U, 3560U, 3567U, 3574U, 3584U, 
    1838U, 5776U, 5734U, 2384U, 2712U, 7108U, 2273U, 3428U, 
    6178U, 5833U, 6575U, 5850U, 5668U, 1452U, 5872U, 6433U, 
    5803U, 6620U, 2323U, 5520U, 1919U, 1426U, 1901U, 6452U, 
    3704U, 5569U, 1577U, 1521U, 1551U, 1562U, 1502U, 1532U, 
    2227U, 2211U, 5919U, 2542U, 2559U, 1705U, 1372U, 1844U, 
    1787U, 5781U, 5740U, 7027U, 3859U, 7010U, 3842U, 1650U, 
    1343U, 6945U, 3777U, 4039U, 4017U, 2003U, 2645U, 1873U, 
    6197U, 6553U, 1404U, 5956U, 6388U, 5983U, 6700U, 1444U, 
    6377U, 6365U, 6528U, 2583U, 6670U, 2515U, 6709U, 3317U, 
    5635U, 5621U, 3304U, 5628U, 5796U, 3444U, 4094U, 4087U, 
    6188U, 3939U, 2044U, 3923U, 1987U, 3931U, 2036U, 3915U, 
    1979U, 3983U, 3975U, 2664U, 2656U, 6096U, 6086U, 6076U, 
    6066U, 6116U, 6106U, 7136U, 7146U, 6126U, 6139U, 7156U, 
    7166U, 6152U, 6165U, 1608U, 1322U, 3475U, 1291U, 1495U, 
    6800U, 3539U, 6900U, 3013U, 4488U, 618U, 9U, 2576U, 
    601U, 0U, 4463U, 4495U, 2473U, 6662U, 1416U, 2976U, 
    2999U, 4069U, 4078U, 5814U, 3741U, 5906U, 2332U, 3677U, 
    3687U, 2093U, 2108U, 3634U, 3666U, 6835U, 6861U, 6847U, 
    2052U, 2080U, 2065U, 1695U, 3201U, 3811U, 6979U, 3835U, 
    7003U, 5827U, 1892U, 1882U, 5478U, 6309U, 6337U, 6316U, 
    5683U, 7210U, 2366U, 7203U, 2348U, 4381U, 4061U, 2250U, 
    3323U, 5865U, 3875U, 6584U, 5648U, 6444U, 6470U, 6630U, 
    5496U, 2131U, 1473U, 2288U, 2196U, 1636U, 1329U, 3503U, 
    6807U, 3546U, 1297U, 6592U, 4472U, 5588U, 5604U, 7185U, 
    2159U, 2313U, 6241U, 4000U, 1615U, 3482U, 1591U, 3458U, 
    6928U, 3760U, 3645U, 3613U, 1673U, 3517U, 1822U, 5761U, 
    5718U, 6962U, 3794U, 6986U, 3818U, 7122U, 7129U, 3898U, 
    4429U, 6607U, 1741U, 3351U, 1757U, 6907U, 1804U, 6882U, 
    5657U, 5700U, 6230U, 1772U, 5817U, 1587U, 2698U, 1155U, 
    5315U, 4421U, 1016U, 5289U, 4414U, 972U, 1800U, 2705U, 
    5322U, 3699U, 2738U, 5343U, 5295U, 1008U, 2608U, 6485U, 
    6269U, 2235U, 1312U, 1748U, 6795U, 3346U, 2639U, 2985U, 
    7199U, 551U, 54U, 4504U, 365U, 4699U, 626U, 4915U, 
    791U, 5095U, 106U, 4564U, 391U, 4729U, 678U, 4975U, 
    843U, 5155U, 443U, 4789U, 730U, 5035U, 895U, 5215U, 
    469U, 4819U, 756U, 5065U, 921U, 5245U, 67U, 4519U, 
    378U, 4714U, 639U, 4930U, 804U, 5110U, 119U, 4579U, 
    404U, 4744U, 691U, 4990U, 856U, 5170U, 158U, 4624U, 
    456U, 4804U, 743U, 5050U, 908U, 5230U, 184U, 4654U, 
    482U, 4834U, 769U, 5080U, 934U, 5260U, 80U, 4534U, 
    652U, 4945U, 817U, 5125U, 132U, 4594U, 417U, 4759U, 
    704U, 5005U, 869U, 5185U, 197U, 4669U, 93U, 4549U, 
    665U, 4960U, 830U, 5140U, 145U, 4609U, 430U, 4774U, 
    717U, 5020U, 882U, 5200U, 171U, 4639U, 210U, 4684U, 
    569U, 4887U, 581U, 4901U, 495U, 4849U, 6691U, 507U, 
    4863U, 5821U, 1667U, 2696U, 1816U, 2703U, 3697U, 2300U, 
    6258U, 1310U, 2672U, 6278U, 1584U, 1995U, 6921U, 3753U, 
    3451U, 3211U, 6058U, 6787U, 6050U, 6759U, 6894U, 3991U, 
    2480U, 6522U, 5756U, 2970U, 6873U, 6210U, 3311U, 2726U, 
    5642U, 2956U, 1316U, 2682U, 3223U, 1360U, 2689U, 5712U, 
    2963U, 947U, 956U, 1388U, 782U, 609U, 5949U, 527U, 
    46U, 327U, 1586U, 251U, 5288U, 26U, 239U, 18U, 
    223U, 6923U, 357U, 3755U, 308U, 3453U, 300U, 5383U, 
    38U, 292U, 1324U, 231U, 5281U, 3213U, 7071U, 1119U, 
    1257U, 5365U, 6492U, 1081U, 1221U, 1025U, 1195U, 2619U, 
    6021U, 1721U, 7043U, 980U, 1169U, 519U, 3969U, 5390U, 
    1396U, 6060U, 5429U, 1071U, 6789U, 5456U, 6052U, 5421U, 
    1061U, 6761U, 5448U, 3008U, 1162U, 5464U, 2733U, 5336U, 
    6041U, 5410U, 6750U, 5437U, 3993U, 2476U, 5654U, 2966U, 
    5359U, 5405U, 1054U, 2720U, 7217U, 1811U, 6889U, 3594U, 
    1490U, 5664U, 5707U, 543U, 4877U, 593U, 559U, 3300U, 
    5470U, 2443U, 316U, 4143U, 3087U, 4257U, 2822U, 3123U, 
    4296U, 2864U, 2123U, 2413U, 259U, 4101U, 3051U, 4218U, 
    2780U, 3021U, 4185U, 2744U, 6730U, 3153U, 4329U, 2900U, 
    6250U, 2453U, 335U, 4157U, 3099U, 4270U, 2836U, 3133U, 
    4307U, 2876U, 6767U, 3177U, 4355U, 2928U, 2151U, 2423U, 
    270U, 4115U, 3063U, 4231U, 2794U, 3031U, 4196U, 2756U, 
    6740U, 3165U, 4342U, 2914U, 6357U, 2463U, 346U, 4171U, 
    3111U, 4283U, 2850U, 3143U, 4318U, 2888U, 6777U, 3189U, 
    4368U, 2942U, 2175U, 2433U, 281U, 4129U, 3075U, 4244U, 
    2808U, 3041U, 4207U, 2768U, 7099U, 3307U, 2728U, 5329U, 
    5377U, 5624U, 2958U, 5351U, 5398U, 535U, 560U, 1318U, 
    2684U, 5301U, 5275U, 1962U, 3225U, 7085U, 1137U, 1274U, 
    6507U, 1100U, 1239U, 1039U, 1208U, 2629U, 6031U, 1731U, 
    7057U, 994U, 1182U, 1325U, 2691U, 5308U, 5282U, 964U, 
    6483U, 2718U, 7176U, 5708U, 2965U, 5358U, 5404U, 1053U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 664);
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
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 664);
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
    /* CVT_D0_S0_R1 */
    816,
    /* CVT_D0_S0_R1_P */
    820,
    /* CVT_D0_S0_R2 */
    825,
    /* CVT_D0_S0_R2_P */
    829,
    /* CVT_D0_S0_R3 */
    834,
    /* CVT_D0_S0_R3_P */
    838,
    /* CVT_D0_S1_R0 */
    843,
    /* CVT_D0_S1_R0_P */
    847,
    /* CVT_D0_S1_R1 */
    852,
    /* CVT_D0_S1_R1_P */
    856,
    /* CVT_D0_S1_R2 */
    861,
    /* CVT_D0_S1_R2_P */
    865,
    /* CVT_D0_S1_R3 */
    870,
    /* CVT_D0_S1_R3_P */
    874,
    /* CVT_D0_S2_R1 */
    879,
    /* CVT_D0_S2_R1_P */
    883,
    /* CVT_D0_S2_R2 */
    888,
    /* CVT_D0_S2_R2_P */
    892,
    /* CVT_D0_S2_R3 */
    897,
    /* CVT_D0_S2_R3_P */
    901,
    /* CVT_D0_S3_R1 */
    906,
    /* CVT_D0_S3_R1_P */
    910,
    /* CVT_D0_S3_R2 */
    915,
    /* CVT_D0_S3_R2_P */
    919,
    /* CVT_D0_S3_R3 */
    924,
    /* CVT_D0_S3_R3_P */
    928,
    /* CVT_D1_S0_R0 */
    933,
    /* CVT_D1_S0_R0_P */
    937,
    /* CVT_D1_S0_R1 */
    942,
    /* CVT_D1_S0_R1_P */
    946,
    /* CVT_D1_S0_R2 */
    951,
    /* CVT_D1_S0_R2_P */
    955,
    /* CVT_D1_S0_R3 */
    960,
    /* CVT_D1_S0_R3_P */
    964,
    /* CVT_D1_S1_R0 */
    969,
    /* CVT_D1_S1_R0_P */
    973,
    /* CVT_D1_S1_R1 */
    978,
    /* CVT_D1_S1_R1_P */
    982,
    /* CVT_D1_S1_R2 */
    987,
    /* CVT_D1_S1_R2_P */
    991,
    /* CVT_D1_S1_R3 */
    996,
    /* CVT_D1_S1_R3_P */
    1000,
    /* CVT_D1_S2_R0 */
    1005,
    /* CVT_D1_S2_R0_P */
    1009,
    /* CVT_D1_S2_R1 */
    1014,
    /* CVT_D1_S2_R1_P */
    1018,
    /* CVT_D1_S2_R2 */
    1023,
    /* CVT_D1_S2_R2_P */
    1027,
    /* CVT_D1_S2_R3 */
    1032,
    /* CVT_D1_S2_R3_P */
    1036,
    /* CVT_D1_S3_R0 */
    1041,
    /* CVT_D1_S3_R0_P */
    1045,
    /* CVT_D1_S3_R1 */
    1050,
    /* CVT_D1_S3_R1_P */
    1054,
    /* CVT_D1_S3_R2 */
    1059,
    /* CVT_D1_S3_R2_P */
    1063,
    /* CVT_D1_S3_R3 */
    1068,
    /* CVT_D1_S3_R3_P */
    1072,
    /* CVT_D2_S0_R0 */
    1077,
    /* CVT_D2_S0_R0_P */
    1081,
    /* CVT_D2_S0_R2 */
    1086,
    /* CVT_D2_S0_R2_P */
    1090,
    /* CVT_D2_S0_R3 */
    1095,
    /* CVT_D2_S0_R3_P */
    1099,
    /* CVT_D2_S1_R0 */
    1104,
    /* CVT_D2_S1_R0_P */
    1108,
    /* CVT_D2_S1_R1 */
    1113,
    /* CVT_D2_S1_R1_P */
    1117,
    /* CVT_D2_S1_R2 */
    1122,
    /* CVT_D2_S1_R2_P */
    1126,
    /* CVT_D2_S1_R3 */
    1131,
    /* CVT_D2_S1_R3_P */
    1135,
    /* CVT_D2_S3_R0 */
    1140,
    /* CVT_D2_S3_R0_P */
    1144,
    /* CVT_D3_S0_R0 */
    1149,
    /* CVT_D3_S0_R0_P */
    1153,
    /* CVT_D3_S0_R2 */
    1158,
    /* CVT_D3_S0_R2_P */
    1162,
    /* CVT_D3_S0_R3 */
    1167,
    /* CVT_D3_S0_R3_P */
    1171,
    /* CVT_D3_S1_R0 */
    1176,
    /* CVT_D3_S1_R0_P */
    1180,
    /* CVT_D3_S1_R1 */
    1185,
    /* CVT_D3_S1_R1_P */
    1189,
    /* CVT_D3_S1_R2 */
    1194,
    /* CVT_D3_S1_R2_P */
    1198,
    /* CVT_D3_S1_R3 */
    1203,
    /* CVT_D3_S1_R3_P */
    1207,
    /* CVT_D3_S2_R0 */
    1212,
    /* CVT_D3_S2_R0_P */
    1216,
    /* CVT_D3_S3_R0 */
    1221,
    /* CVT_D3_S3_R0_P */
    1225,
    /* CVT_F32_S32 */
    1230,
    /* CVT_F32_S32_P */
    1234,
    /* CVT_F32_U32 */
    1239,
    /* CVT_F32_U32_P */
    1243,
    /* CVT_S32_F32 */
    1248,
    /* CVT_S32_F32_P */
    1252,
    /* CVT_SEXT */
    1257,
    /* CVT_U32_F32 */
    1261,
    /* CVT_U32_F32_P */
    1265,
    /* C_ABS */
    1270,
    /* C_ADD */
    1272,
    /* C_ADDI */
    1275,
    /* C_AND */
    1278,
    /* C_ANDI */
    1281,
    /* C_ANDN */
    1284,
    /* C_BAR_ARRIVE */
    1287,
    /* C_BAR_WAIT */
    1288,
    /* C_BRA */
    1289,
    /* C_CHWIDTH */
    1290,
    /* C_EXIT */
    1292,
    /* C_FADD */
    1293,
    /* C_FENCE */
    1296,
    /* C_FMAX */
    1297,
    /* C_FMIN */
    1300,
    /* C_FMUL */
    1303,
    /* C_LD_GLOBAL */
    1306,
    /* C_MAX_S */
    1308,
    /* C_MAX_U */
    1311,
    /* C_MIN_S */
    1314,
    /* C_MIN_U */
    1317,
    /* C_MOV */
    1320,
    /* C_MUL_LO */
    1322,
    /* C_NEG */
    1325,
    /* C_NOT */
    1327,
    /* C_OR */
    1329,
    /* C_ORI */
    1332,
    /* C_RECONV */
    1335,
    /* C_RET */
    1336,
    /* C_SHL */
    1337,
    /* C_SHLI */
    1340,
    /* C_SHR */
    1343,
    /* C_SHRI */
    1346,
    /* C_SRA */
    1349,
    /* C_SRAI */
    1352,
    /* C_ST_GLOBAL */
    1355,
    /* C_SUB */
    1357,
    /* C_SUBI */
    1360,
    /* C_XOR */
    1363,
    /* C_XORI */
    1366,
    /* DP2_BF16 */
    1369,
    /* DP2_F16 */
    1373,
    /* DP4_ACC */
    1377,
    /* DP4_E4M3 */
    1381,
    /* DP4_E5M2 */
    1385,
    /* DP4_SS */
    1389,
    /* EX2_F32 */
    1393,
    /* FABS_F0 */
    1397,
    /* FABS_F1 */
    1401,
    /* FADD */
    1405,
    /* FADD_F1 */
    1409,
    /* FADD_P */
    1413,
    /* FFMA_ACC_F0 */
    1418,
    /* FFMA_ACC_F1 */
    1422,
    /* FFMA_F0 */
    1426,
    /* FFMA_F1 */
    1430,
    /* FMAX */
    1434,
    /* FMAX_F1 */
    1438,
    /* FMIN */
    1442,
    /* FMIN_F1 */
    1446,
    /* FMUL */
    1450,
    /* FMUL_F1 */
    1454,
    /* FMUL_P */
    1458,
    /* FNEG_F0 */
    1463,
    /* FNEG_F1 */
    1467,
    /* FSUB */
    1471,
    /* FSUB_F1 */
    1475,
    /* FSUB_P */
    1479,
    /* LD_GLOBAL */
    1484,
    /* LD_GLOBAL_IDX */
    1487,
    /* LD_GLOBAL_IDX_W16 */
    1492,
    /* LD_GLOBAL_IDX_W8 */
    1497,
    /* LD_GLOBAL_P */
    1502,
    /* LD_GLOBAL_SLOT */
    1506,
    /* LD_GLOBAL_SLOT_W16 */
    1511,
    /* LD_GLOBAL_SLOT_W8 */
    1516,
    /* LD_GLOBAL_W16 */
    1521,
    /* LD_GLOBAL_W8 */
    1524,
    /* LD_PRED_G */
    1527,
    /* LD_PRED_S */
    1530,
    /* LD_SHARED */
    1533,
    /* LD_SHARED_IDX */
    1536,
    /* LD_SHARED_W16 */
    1541,
    /* LD_SHARED_W8 */
    1544,
    /* LG2_F32 */
    1547,
    /* MADLO */
    1551,
    /* MADLO_P */
    1555,
    /* MAD_ACC */
    1560,
    /* MAX_S */
    1564,
    /* MAX_S_P */
    1568,
    /* MAX_S_W16 */
    1573,
    /* MAX_U */
    1577,
    /* MAX_U_P */
    1581,
    /* MIN_S */
    1586,
    /* MIN_S_P */
    1590,
    /* MIN_S_W16 */
    1595,
    /* MIN_U */
    1599,
    /* MIN_U_P */
    1603,
    /* MOVI */
    1608,
    /* MOVI48 */
    1610,
    /* MOV_P */
    1612,
    /* MULI */
    1618,
    /* MULI_P */
    1621,
    /* MUL_HI_S */
    1625,
    /* MUL_HI_S_P */
    1629,
    /* MUL_HI_U */
    1634,
    /* MUL_HI_U_P */
    1638,
    /* MUL_LO */
    1643,
    /* NEG */
    1647,
    /* OR */
    1651,
    /* ORI */
    1655,
    /* ORI_P */
    1658,
    /* OR_P */
    1662,
    /* OR_W16 */
    1667,
    /* PACKI */
    1671,
    /* PACKI_Z */
    1675,
    /* PAND */
    1678,
    /* PMOV */
    1681,
    /* PMOV_IMM */
    1684,
    /* POPC */
    1686,
    /* POR */
    1690,
    /* PXOR */
    1693,
    /* RCP_F32 */
    1696,
    /* RCP_F32_P */
    1700,
    /* RCP_U32 */
    1705,
    /* RSQRT_F32 */
    1709,
    /* SEL */
    1713,
    /* SETP_EQ */
    1718,
    /* SETP_EQ_F */
    1723,
    /* SETP_EQ_F1 */
    1728,
    /* SETP_EQ_F1_NP */
    1733,
    /* SETP_EQ_F_I */
    1737,
    /* SETP_EQ_F_NP */
    1742,
    /* SETP_EQ_F_NPI */
    1746,
    /* SETP_EQ_I */
    1750,
    /* SETP_EQ_NP */
    1755,
    /* SETP_EQ_NPI */
    1759,
    /* SETP_GE */
    1763,
    /* SETP_GE_F */
    1768,
    /* SETP_GE_F1 */
    1773,
    /* SETP_GE_F1_NP */
    1778,
    /* SETP_GE_F_I */
    1782,
    /* SETP_GE_F_NP */
    1787,
    /* SETP_GE_F_NPI */
    1791,
    /* SETP_GE_I */
    1795,
    /* SETP_GE_NP */
    1800,
    /* SETP_GE_NPI */
    1804,
    /* SETP_GE_U */
    1808,
    /* SETP_GE_U_I */
    1813,
    /* SETP_GE_U_NP */
    1818,
    /* SETP_GE_U_NPI */
    1822,
    /* SETP_GT */
    1826,
    /* SETP_GT_F */
    1831,
    /* SETP_GT_F1 */
    1836,
    /* SETP_GT_F1_NP */
    1841,
    /* SETP_GT_F_I */
    1845,
    /* SETP_GT_F_NP */
    1850,
    /* SETP_GT_F_NPI */
    1854,
    /* SETP_GT_I */
    1858,
    /* SETP_GT_NP */
    1863,
    /* SETP_GT_NPI */
    1867,
    /* SETP_GT_U */
    1871,
    /* SETP_GT_U_I */
    1876,
    /* SETP_GT_U_NP */
    1881,
    /* SETP_GT_U_NPI */
    1885,
    /* SETP_LE */
    1889,
    /* SETP_LE_F */
    1894,
    /* SETP_LE_F1 */
    1899,
    /* SETP_LE_F1_NP */
    1904,
    /* SETP_LE_F_I */
    1908,
    /* SETP_LE_F_NP */
    1913,
    /* SETP_LE_F_NPI */
    1917,
    /* SETP_LE_I */
    1921,
    /* SETP_LE_NP */
    1926,
    /* SETP_LE_NPI */
    1930,
    /* SETP_LE_U */
    1934,
    /* SETP_LE_U_I */
    1939,
    /* SETP_LE_U_NP */
    1944,
    /* SETP_LE_U_NPI */
    1948,
    /* SETP_LT */
    1952,
    /* SETP_LT_F */
    1957,
    /* SETP_LT_F1 */
    1962,
    /* SETP_LT_F1_NP */
    1967,
    /* SETP_LT_F_I */
    1971,
    /* SETP_LT_F_NP */
    1976,
    /* SETP_LT_F_NPI */
    1980,
    /* SETP_LT_I */
    1984,
    /* SETP_LT_NP */
    1989,
    /* SETP_LT_NPI */
    1993,
    /* SETP_LT_U */
    1997,
    /* SETP_LT_U_I */
    2002,
    /* SETP_LT_U_NP */
    2007,
    /* SETP_LT_U_NPI */
    2011,
    /* SETP_NE */
    2015,
    /* SETP_NE_F */
    2020,
    /* SETP_NE_F1 */
    2025,
    /* SETP_NE_F1_NP */
    2030,
    /* SETP_NE_F_I */
    2034,
    /* SETP_NE_F_NP */
    2039,
    /* SETP_NE_F_NPI */
    2043,
    /* SETP_NE_I */
    2047,
    /* SETP_NE_NP */
    2052,
    /* SETP_NE_NPI */
    2056,
    /* SHFL_IDX */
    2060,
    /* SHL */
    2064,
    /* SHLI */
    2068,
    /* SHLI_P */
    2071,
    /* SHL_P */
    2075,
    /* SHR */
    2080,
    /* SHRI */
    2084,
    /* SHRI_P */
    2087,
    /* SHR_P */
    2091,
    /* SIN_F32 */
    2096,
    /* SQRT_F32 */
    2100,
    /* SRA */
    2104,
    /* SRAI */
    2108,
    /* SRAI_P */
    2111,
    /* SRA_P */
    2115,
    /* SRD */
    2120,
    /* ST_GLOBAL */
    2122,
    /* ST_GLOBAL_IDX */
    2125,
    /* ST_GLOBAL_IDX_W16 */
    2130,
    /* ST_GLOBAL_IDX_W8 */
    2135,
    /* ST_GLOBAL_SLOT */
    2140,
    /* ST_GLOBAL_SLOT_W16 */
    2145,
    /* ST_GLOBAL_SLOT_W8 */
    2150,
    /* ST_GLOBAL_W16 */
    2155,
    /* ST_GLOBAL_W8 */
    2158,
    /* ST_PRED_G */
    2161,
    /* ST_PRED_S */
    2164,
    /* ST_SHARED */
    2167,
    /* ST_SHARED_IDX */
    2170,
    /* ST_SHARED_W16 */
    2175,
    /* ST_SHARED_W8 */
    2178,
    /* SUB */
    2181,
    /* SUBI */
    2185,
    /* SUBI_P */
    2188,
    /* SUB_P */
    2192,
    /* SUB_W16 */
    2197,
    /* UNBALLOT */
    2201,
    /* UNPACKI */
    2204,
    /* VOTE_ANY */
    2207,
    /* XOR */
    2210,
    /* XORI */
    2214,
    /* XORI_P */
    2217,
    /* XOR_P */
    2221,
    /* XOR_W16 */
    2226,
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
    CEFBS_None, // CVT_D0_S0_R1 = 316
    CEFBS_None, // CVT_D0_S0_R1_P = 317
    CEFBS_None, // CVT_D0_S0_R2 = 318
    CEFBS_None, // CVT_D0_S0_R2_P = 319
    CEFBS_None, // CVT_D0_S0_R3 = 320
    CEFBS_None, // CVT_D0_S0_R3_P = 321
    CEFBS_None, // CVT_D0_S1_R0 = 322
    CEFBS_None, // CVT_D0_S1_R0_P = 323
    CEFBS_None, // CVT_D0_S1_R1 = 324
    CEFBS_None, // CVT_D0_S1_R1_P = 325
    CEFBS_None, // CVT_D0_S1_R2 = 326
    CEFBS_None, // CVT_D0_S1_R2_P = 327
    CEFBS_None, // CVT_D0_S1_R3 = 328
    CEFBS_None, // CVT_D0_S1_R3_P = 329
    CEFBS_None, // CVT_D0_S2_R1 = 330
    CEFBS_None, // CVT_D0_S2_R1_P = 331
    CEFBS_None, // CVT_D0_S2_R2 = 332
    CEFBS_None, // CVT_D0_S2_R2_P = 333
    CEFBS_None, // CVT_D0_S2_R3 = 334
    CEFBS_None, // CVT_D0_S2_R3_P = 335
    CEFBS_None, // CVT_D0_S3_R1 = 336
    CEFBS_None, // CVT_D0_S3_R1_P = 337
    CEFBS_None, // CVT_D0_S3_R2 = 338
    CEFBS_None, // CVT_D0_S3_R2_P = 339
    CEFBS_None, // CVT_D0_S3_R3 = 340
    CEFBS_None, // CVT_D0_S3_R3_P = 341
    CEFBS_None, // CVT_D1_S0_R0 = 342
    CEFBS_None, // CVT_D1_S0_R0_P = 343
    CEFBS_None, // CVT_D1_S0_R1 = 344
    CEFBS_None, // CVT_D1_S0_R1_P = 345
    CEFBS_None, // CVT_D1_S0_R2 = 346
    CEFBS_None, // CVT_D1_S0_R2_P = 347
    CEFBS_None, // CVT_D1_S0_R3 = 348
    CEFBS_None, // CVT_D1_S0_R3_P = 349
    CEFBS_None, // CVT_D1_S1_R0 = 350
    CEFBS_None, // CVT_D1_S1_R0_P = 351
    CEFBS_None, // CVT_D1_S1_R1 = 352
    CEFBS_None, // CVT_D1_S1_R1_P = 353
    CEFBS_None, // CVT_D1_S1_R2 = 354
    CEFBS_None, // CVT_D1_S1_R2_P = 355
    CEFBS_None, // CVT_D1_S1_R3 = 356
    CEFBS_None, // CVT_D1_S1_R3_P = 357
    CEFBS_None, // CVT_D1_S2_R0 = 358
    CEFBS_None, // CVT_D1_S2_R0_P = 359
    CEFBS_None, // CVT_D1_S2_R1 = 360
    CEFBS_None, // CVT_D1_S2_R1_P = 361
    CEFBS_None, // CVT_D1_S2_R2 = 362
    CEFBS_None, // CVT_D1_S2_R2_P = 363
    CEFBS_None, // CVT_D1_S2_R3 = 364
    CEFBS_None, // CVT_D1_S2_R3_P = 365
    CEFBS_None, // CVT_D1_S3_R0 = 366
    CEFBS_None, // CVT_D1_S3_R0_P = 367
    CEFBS_None, // CVT_D1_S3_R1 = 368
    CEFBS_None, // CVT_D1_S3_R1_P = 369
    CEFBS_None, // CVT_D1_S3_R2 = 370
    CEFBS_None, // CVT_D1_S3_R2_P = 371
    CEFBS_None, // CVT_D1_S3_R3 = 372
    CEFBS_None, // CVT_D1_S3_R3_P = 373
    CEFBS_None, // CVT_D2_S0_R0 = 374
    CEFBS_None, // CVT_D2_S0_R0_P = 375
    CEFBS_None, // CVT_D2_S0_R2 = 376
    CEFBS_None, // CVT_D2_S0_R2_P = 377
    CEFBS_None, // CVT_D2_S0_R3 = 378
    CEFBS_None, // CVT_D2_S0_R3_P = 379
    CEFBS_None, // CVT_D2_S1_R0 = 380
    CEFBS_None, // CVT_D2_S1_R0_P = 381
    CEFBS_None, // CVT_D2_S1_R1 = 382
    CEFBS_None, // CVT_D2_S1_R1_P = 383
    CEFBS_None, // CVT_D2_S1_R2 = 384
    CEFBS_None, // CVT_D2_S1_R2_P = 385
    CEFBS_None, // CVT_D2_S1_R3 = 386
    CEFBS_None, // CVT_D2_S1_R3_P = 387
    CEFBS_None, // CVT_D2_S3_R0 = 388
    CEFBS_None, // CVT_D2_S3_R0_P = 389
    CEFBS_None, // CVT_D3_S0_R0 = 390
    CEFBS_None, // CVT_D3_S0_R0_P = 391
    CEFBS_None, // CVT_D3_S0_R2 = 392
    CEFBS_None, // CVT_D3_S0_R2_P = 393
    CEFBS_None, // CVT_D3_S0_R3 = 394
    CEFBS_None, // CVT_D3_S0_R3_P = 395
    CEFBS_None, // CVT_D3_S1_R0 = 396
    CEFBS_None, // CVT_D3_S1_R0_P = 397
    CEFBS_None, // CVT_D3_S1_R1 = 398
    CEFBS_None, // CVT_D3_S1_R1_P = 399
    CEFBS_None, // CVT_D3_S1_R2 = 400
    CEFBS_None, // CVT_D3_S1_R2_P = 401
    CEFBS_None, // CVT_D3_S1_R3 = 402
    CEFBS_None, // CVT_D3_S1_R3_P = 403
    CEFBS_None, // CVT_D3_S2_R0 = 404
    CEFBS_None, // CVT_D3_S2_R0_P = 405
    CEFBS_None, // CVT_D3_S3_R0 = 406
    CEFBS_None, // CVT_D3_S3_R0_P = 407
    CEFBS_None, // CVT_F32_S32 = 408
    CEFBS_None, // CVT_F32_S32_P = 409
    CEFBS_None, // CVT_F32_U32 = 410
    CEFBS_None, // CVT_F32_U32_P = 411
    CEFBS_None, // CVT_S32_F32 = 412
    CEFBS_None, // CVT_S32_F32_P = 413
    CEFBS_None, // CVT_SEXT = 414
    CEFBS_None, // CVT_U32_F32 = 415
    CEFBS_None, // CVT_U32_F32_P = 416
    CEFBS_None, // C_ABS = 417
    CEFBS_None, // C_ADD = 418
    CEFBS_None, // C_ADDI = 419
    CEFBS_None, // C_AND = 420
    CEFBS_None, // C_ANDI = 421
    CEFBS_None, // C_ANDN = 422
    CEFBS_None, // C_BAR_ARRIVE = 423
    CEFBS_None, // C_BAR_WAIT = 424
    CEFBS_None, // C_BRA = 425
    CEFBS_None, // C_CHWIDTH = 426
    CEFBS_None, // C_EXIT = 427
    CEFBS_None, // C_FADD = 428
    CEFBS_None, // C_FENCE = 429
    CEFBS_None, // C_FMAX = 430
    CEFBS_None, // C_FMIN = 431
    CEFBS_None, // C_FMUL = 432
    CEFBS_None, // C_LD_GLOBAL = 433
    CEFBS_None, // C_MAX_S = 434
    CEFBS_None, // C_MAX_U = 435
    CEFBS_None, // C_MIN_S = 436
    CEFBS_None, // C_MIN_U = 437
    CEFBS_None, // C_MOV = 438
    CEFBS_None, // C_MUL_LO = 439
    CEFBS_None, // C_NEG = 440
    CEFBS_None, // C_NOT = 441
    CEFBS_None, // C_OR = 442
    CEFBS_None, // C_ORI = 443
    CEFBS_None, // C_RECONV = 444
    CEFBS_None, // C_RET = 445
    CEFBS_None, // C_SHL = 446
    CEFBS_None, // C_SHLI = 447
    CEFBS_None, // C_SHR = 448
    CEFBS_None, // C_SHRI = 449
    CEFBS_None, // C_SRA = 450
    CEFBS_None, // C_SRAI = 451
    CEFBS_None, // C_ST_GLOBAL = 452
    CEFBS_None, // C_SUB = 453
    CEFBS_None, // C_SUBI = 454
    CEFBS_None, // C_XOR = 455
    CEFBS_None, // C_XORI = 456
    CEFBS_None, // DP2_BF16 = 457
    CEFBS_None, // DP2_F16 = 458
    CEFBS_None, // DP4_ACC = 459
    CEFBS_None, // DP4_E4M3 = 460
    CEFBS_None, // DP4_E5M2 = 461
    CEFBS_None, // DP4_SS = 462
    CEFBS_None, // EX2_F32 = 463
    CEFBS_None, // FABS_F0 = 464
    CEFBS_None, // FABS_F1 = 465
    CEFBS_None, // FADD = 466
    CEFBS_None, // FADD_F1 = 467
    CEFBS_None, // FADD_P = 468
    CEFBS_None, // FFMA_ACC_F0 = 469
    CEFBS_None, // FFMA_ACC_F1 = 470
    CEFBS_None, // FFMA_F0 = 471
    CEFBS_None, // FFMA_F1 = 472
    CEFBS_None, // FMAX = 473
    CEFBS_None, // FMAX_F1 = 474
    CEFBS_None, // FMIN = 475
    CEFBS_None, // FMIN_F1 = 476
    CEFBS_None, // FMUL = 477
    CEFBS_None, // FMUL_F1 = 478
    CEFBS_None, // FMUL_P = 479
    CEFBS_None, // FNEG_F0 = 480
    CEFBS_None, // FNEG_F1 = 481
    CEFBS_None, // FSUB = 482
    CEFBS_None, // FSUB_F1 = 483
    CEFBS_None, // FSUB_P = 484
    CEFBS_None, // LD_GLOBAL = 485
    CEFBS_None, // LD_GLOBAL_IDX = 486
    CEFBS_None, // LD_GLOBAL_IDX_W16 = 487
    CEFBS_None, // LD_GLOBAL_IDX_W8 = 488
    CEFBS_None, // LD_GLOBAL_P = 489
    CEFBS_None, // LD_GLOBAL_SLOT = 490
    CEFBS_None, // LD_GLOBAL_SLOT_W16 = 491
    CEFBS_None, // LD_GLOBAL_SLOT_W8 = 492
    CEFBS_None, // LD_GLOBAL_W16 = 493
    CEFBS_None, // LD_GLOBAL_W8 = 494
    CEFBS_None, // LD_PRED_G = 495
    CEFBS_None, // LD_PRED_S = 496
    CEFBS_None, // LD_SHARED = 497
    CEFBS_None, // LD_SHARED_IDX = 498
    CEFBS_None, // LD_SHARED_W16 = 499
    CEFBS_None, // LD_SHARED_W8 = 500
    CEFBS_None, // LG2_F32 = 501
    CEFBS_None, // MADLO = 502
    CEFBS_None, // MADLO_P = 503
    CEFBS_None, // MAD_ACC = 504
    CEFBS_None, // MAX_S = 505
    CEFBS_None, // MAX_S_P = 506
    CEFBS_None, // MAX_S_W16 = 507
    CEFBS_None, // MAX_U = 508
    CEFBS_None, // MAX_U_P = 509
    CEFBS_None, // MIN_S = 510
    CEFBS_None, // MIN_S_P = 511
    CEFBS_None, // MIN_S_W16 = 512
    CEFBS_None, // MIN_U = 513
    CEFBS_None, // MIN_U_P = 514
    CEFBS_None, // MOVI = 515
    CEFBS_None, // MOVI48 = 516
    CEFBS_None, // MOV_P = 517
    CEFBS_None, // MULI = 518
    CEFBS_None, // MULI_P = 519
    CEFBS_None, // MUL_HI_S = 520
    CEFBS_None, // MUL_HI_S_P = 521
    CEFBS_None, // MUL_HI_U = 522
    CEFBS_None, // MUL_HI_U_P = 523
    CEFBS_None, // MUL_LO = 524
    CEFBS_None, // NEG = 525
    CEFBS_None, // OR = 526
    CEFBS_None, // ORI = 527
    CEFBS_None, // ORI_P = 528
    CEFBS_None, // OR_P = 529
    CEFBS_None, // OR_W16 = 530
    CEFBS_None, // PACKI = 531
    CEFBS_None, // PACKI_Z = 532
    CEFBS_None, // PAND = 533
    CEFBS_None, // PMOV = 534
    CEFBS_None, // PMOV_IMM = 535
    CEFBS_None, // POPC = 536
    CEFBS_None, // POR = 537
    CEFBS_None, // PXOR = 538
    CEFBS_None, // RCP_F32 = 539
    CEFBS_None, // RCP_F32_P = 540
    CEFBS_None, // RCP_U32 = 541
    CEFBS_None, // RSQRT_F32 = 542
    CEFBS_None, // SEL = 543
    CEFBS_None, // SETP_EQ = 544
    CEFBS_None, // SETP_EQ_F = 545
    CEFBS_None, // SETP_EQ_F1 = 546
    CEFBS_None, // SETP_EQ_F1_NP = 547
    CEFBS_None, // SETP_EQ_F_I = 548
    CEFBS_None, // SETP_EQ_F_NP = 549
    CEFBS_None, // SETP_EQ_F_NPI = 550
    CEFBS_None, // SETP_EQ_I = 551
    CEFBS_None, // SETP_EQ_NP = 552
    CEFBS_None, // SETP_EQ_NPI = 553
    CEFBS_None, // SETP_GE = 554
    CEFBS_None, // SETP_GE_F = 555
    CEFBS_None, // SETP_GE_F1 = 556
    CEFBS_None, // SETP_GE_F1_NP = 557
    CEFBS_None, // SETP_GE_F_I = 558
    CEFBS_None, // SETP_GE_F_NP = 559
    CEFBS_None, // SETP_GE_F_NPI = 560
    CEFBS_None, // SETP_GE_I = 561
    CEFBS_None, // SETP_GE_NP = 562
    CEFBS_None, // SETP_GE_NPI = 563
    CEFBS_None, // SETP_GE_U = 564
    CEFBS_None, // SETP_GE_U_I = 565
    CEFBS_None, // SETP_GE_U_NP = 566
    CEFBS_None, // SETP_GE_U_NPI = 567
    CEFBS_None, // SETP_GT = 568
    CEFBS_None, // SETP_GT_F = 569
    CEFBS_None, // SETP_GT_F1 = 570
    CEFBS_None, // SETP_GT_F1_NP = 571
    CEFBS_None, // SETP_GT_F_I = 572
    CEFBS_None, // SETP_GT_F_NP = 573
    CEFBS_None, // SETP_GT_F_NPI = 574
    CEFBS_None, // SETP_GT_I = 575
    CEFBS_None, // SETP_GT_NP = 576
    CEFBS_None, // SETP_GT_NPI = 577
    CEFBS_None, // SETP_GT_U = 578
    CEFBS_None, // SETP_GT_U_I = 579
    CEFBS_None, // SETP_GT_U_NP = 580
    CEFBS_None, // SETP_GT_U_NPI = 581
    CEFBS_None, // SETP_LE = 582
    CEFBS_None, // SETP_LE_F = 583
    CEFBS_None, // SETP_LE_F1 = 584
    CEFBS_None, // SETP_LE_F1_NP = 585
    CEFBS_None, // SETP_LE_F_I = 586
    CEFBS_None, // SETP_LE_F_NP = 587
    CEFBS_None, // SETP_LE_F_NPI = 588
    CEFBS_None, // SETP_LE_I = 589
    CEFBS_None, // SETP_LE_NP = 590
    CEFBS_None, // SETP_LE_NPI = 591
    CEFBS_None, // SETP_LE_U = 592
    CEFBS_None, // SETP_LE_U_I = 593
    CEFBS_None, // SETP_LE_U_NP = 594
    CEFBS_None, // SETP_LE_U_NPI = 595
    CEFBS_None, // SETP_LT = 596
    CEFBS_None, // SETP_LT_F = 597
    CEFBS_None, // SETP_LT_F1 = 598
    CEFBS_None, // SETP_LT_F1_NP = 599
    CEFBS_None, // SETP_LT_F_I = 600
    CEFBS_None, // SETP_LT_F_NP = 601
    CEFBS_None, // SETP_LT_F_NPI = 602
    CEFBS_None, // SETP_LT_I = 603
    CEFBS_None, // SETP_LT_NP = 604
    CEFBS_None, // SETP_LT_NPI = 605
    CEFBS_None, // SETP_LT_U = 606
    CEFBS_None, // SETP_LT_U_I = 607
    CEFBS_None, // SETP_LT_U_NP = 608
    CEFBS_None, // SETP_LT_U_NPI = 609
    CEFBS_None, // SETP_NE = 610
    CEFBS_None, // SETP_NE_F = 611
    CEFBS_None, // SETP_NE_F1 = 612
    CEFBS_None, // SETP_NE_F1_NP = 613
    CEFBS_None, // SETP_NE_F_I = 614
    CEFBS_None, // SETP_NE_F_NP = 615
    CEFBS_None, // SETP_NE_F_NPI = 616
    CEFBS_None, // SETP_NE_I = 617
    CEFBS_None, // SETP_NE_NP = 618
    CEFBS_None, // SETP_NE_NPI = 619
    CEFBS_None, // SHFL_IDX = 620
    CEFBS_None, // SHL = 621
    CEFBS_None, // SHLI = 622
    CEFBS_None, // SHLI_P = 623
    CEFBS_None, // SHL_P = 624
    CEFBS_None, // SHR = 625
    CEFBS_None, // SHRI = 626
    CEFBS_None, // SHRI_P = 627
    CEFBS_None, // SHR_P = 628
    CEFBS_None, // SIN_F32 = 629
    CEFBS_None, // SQRT_F32 = 630
    CEFBS_None, // SRA = 631
    CEFBS_None, // SRAI = 632
    CEFBS_None, // SRAI_P = 633
    CEFBS_None, // SRA_P = 634
    CEFBS_None, // SRD = 635
    CEFBS_None, // ST_GLOBAL = 636
    CEFBS_None, // ST_GLOBAL_IDX = 637
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 638
    CEFBS_None, // ST_GLOBAL_IDX_W8 = 639
    CEFBS_None, // ST_GLOBAL_SLOT = 640
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 641
    CEFBS_None, // ST_GLOBAL_SLOT_W8 = 642
    CEFBS_None, // ST_GLOBAL_W16 = 643
    CEFBS_None, // ST_GLOBAL_W8 = 644
    CEFBS_None, // ST_PRED_G = 645
    CEFBS_None, // ST_PRED_S = 646
    CEFBS_None, // ST_SHARED = 647
    CEFBS_None, // ST_SHARED_IDX = 648
    CEFBS_None, // ST_SHARED_W16 = 649
    CEFBS_None, // ST_SHARED_W8 = 650
    CEFBS_None, // SUB = 651
    CEFBS_None, // SUBI = 652
    CEFBS_None, // SUBI_P = 653
    CEFBS_None, // SUB_P = 654
    CEFBS_None, // SUB_W16 = 655
    CEFBS_None, // UNBALLOT = 656
    CEFBS_None, // UNPACKI = 657
    CEFBS_None, // VOTE_ANY = 658
    CEFBS_None, // XOR = 659
    CEFBS_None, // XORI = 660
    CEFBS_None, // XORI_P = 661
    CEFBS_None, // XOR_P = 662
    CEFBS_None, // XOR_W16 = 663
  };

  assert(Opcode < 664);
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

