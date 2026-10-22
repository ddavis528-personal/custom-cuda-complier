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
    SETP_EQ_F_I	= 546,
    SETP_EQ_F_NP	= 547,
    SETP_EQ_F_NPI	= 548,
    SETP_EQ_I	= 549,
    SETP_EQ_NP	= 550,
    SETP_EQ_NPI	= 551,
    SETP_GE	= 552,
    SETP_GE_F	= 553,
    SETP_GE_F_I	= 554,
    SETP_GE_F_NP	= 555,
    SETP_GE_F_NPI	= 556,
    SETP_GE_I	= 557,
    SETP_GE_NP	= 558,
    SETP_GE_NPI	= 559,
    SETP_GE_U	= 560,
    SETP_GE_U_I	= 561,
    SETP_GE_U_NP	= 562,
    SETP_GE_U_NPI	= 563,
    SETP_GT	= 564,
    SETP_GT_F	= 565,
    SETP_GT_F_I	= 566,
    SETP_GT_F_NP	= 567,
    SETP_GT_F_NPI	= 568,
    SETP_GT_I	= 569,
    SETP_GT_NP	= 570,
    SETP_GT_NPI	= 571,
    SETP_GT_U	= 572,
    SETP_GT_U_I	= 573,
    SETP_GT_U_NP	= 574,
    SETP_GT_U_NPI	= 575,
    SETP_LE	= 576,
    SETP_LE_F	= 577,
    SETP_LE_F_I	= 578,
    SETP_LE_F_NP	= 579,
    SETP_LE_F_NPI	= 580,
    SETP_LE_I	= 581,
    SETP_LE_NP	= 582,
    SETP_LE_NPI	= 583,
    SETP_LE_U	= 584,
    SETP_LE_U_I	= 585,
    SETP_LE_U_NP	= 586,
    SETP_LE_U_NPI	= 587,
    SETP_LT	= 588,
    SETP_LT_F	= 589,
    SETP_LT_F_I	= 590,
    SETP_LT_F_NP	= 591,
    SETP_LT_F_NPI	= 592,
    SETP_LT_I	= 593,
    SETP_LT_NP	= 594,
    SETP_LT_NPI	= 595,
    SETP_LT_U	= 596,
    SETP_LT_U_I	= 597,
    SETP_LT_U_NP	= 598,
    SETP_LT_U_NPI	= 599,
    SETP_NE	= 600,
    SETP_NE_F	= 601,
    SETP_NE_F_I	= 602,
    SETP_NE_F_NP	= 603,
    SETP_NE_F_NPI	= 604,
    SETP_NE_I	= 605,
    SETP_NE_NP	= 606,
    SETP_NE_NPI	= 607,
    SHFL_IDX	= 608,
    SHL	= 609,
    SHLI	= 610,
    SHLI_P	= 611,
    SHL_P	= 612,
    SHR	= 613,
    SHRI	= 614,
    SHRI_P	= 615,
    SHR_P	= 616,
    SIN_F32	= 617,
    SQRT_F32	= 618,
    SRA	= 619,
    SRAI	= 620,
    SRAI_P	= 621,
    SRA_P	= 622,
    SRD	= 623,
    ST_GLOBAL	= 624,
    ST_GLOBAL_IDX	= 625,
    ST_GLOBAL_IDX_W16	= 626,
    ST_GLOBAL_IDX_W8	= 627,
    ST_GLOBAL_SLOT	= 628,
    ST_GLOBAL_SLOT_W16	= 629,
    ST_GLOBAL_SLOT_W8	= 630,
    ST_GLOBAL_W16	= 631,
    ST_GLOBAL_W8	= 632,
    ST_PRED_G	= 633,
    ST_PRED_S	= 634,
    ST_SHARED	= 635,
    ST_SHARED_IDX	= 636,
    ST_SHARED_W16	= 637,
    ST_SHARED_W8	= 638,
    SUB	= 639,
    SUBI	= 640,
    SUBI_P	= 641,
    SUB_P	= 642,
    SUB_W16	= 643,
    UNBALLOT	= 644,
    UNPACKI	= 645,
    VOTE_ANY	= 646,
    XOR	= 647,
    XORI	= 648,
    XORI_P	= 649,
    XOR_P	= 650,
    XOR_W16	= 651,
    INSTRUCTION_LIST_END = 652
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
  MCInstrDesc Insts[652];
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
    { 651,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #651 = XOR_W16
    { 650,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #650 = XOR_P
    { 649,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #649 = XORI_P
    { 648,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #648 = XORI
    { 647,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #647 = XOR
    { 646,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #646 = VOTE_ANY
    { 645,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #645 = UNPACKI
    { 644,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	299,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #644 = UNBALLOT
    { 643,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	188,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #643 = SUB_W16
    { 642,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #642 = SUB_P
    { 641,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #641 = SUBI_P
    { 640,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #640 = SUBI
    { 639,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #639 = SUB
    { 638,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #638 = ST_SHARED_W8
    { 637,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #637 = ST_SHARED_W16
    { 636,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #636 = ST_SHARED_IDX
    { 635,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #635 = ST_SHARED
    { 634,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #634 = ST_PRED_S
    { 633,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #633 = ST_PRED_G
    { 632,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #632 = ST_GLOBAL_W8
    { 631,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #631 = ST_GLOBAL_W16
    { 630,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	252,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #630 = ST_GLOBAL_SLOT_W8
    { 629,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	247,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #629 = ST_GLOBAL_SLOT_W16
    { 628,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #628 = ST_GLOBAL_SLOT
    { 627,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	237,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #627 = ST_GLOBAL_IDX_W8
    { 626,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	232,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #626 = ST_GLOBAL_IDX_W16
    { 625,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #625 = ST_GLOBAL_IDX
    { 624,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #624 = ST_GLOBAL
    { 623,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #623 = SRD
    { 622,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #622 = SRA_P
    { 621,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #621 = SRAI_P
    { 620,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #620 = SRAI
    { 619,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #619 = SRA
    { 618,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #618 = SQRT_F32
    { 617,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #617 = SIN_F32
    { 616,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #616 = SHR_P
    { 615,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #615 = SHRI_P
    { 614,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #614 = SHRI
    { 613,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #613 = SHR
    { 612,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	177,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #612 = SHL_P
    { 611,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #611 = SHLI_P
    { 610,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	162,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #610 = SHLI
    { 609,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	158,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #609 = SHL
    { 608,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	165,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #608 = SHFL_IDX
    { 607,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #607 = SETP_NE_NPI
    { 606,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #606 = SETP_NE_NP
    { 605,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #605 = SETP_NE_I
    { 604,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #604 = SETP_NE_F_NPI
    { 603,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #603 = SETP_NE_F_NP
    { 602,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #602 = SETP_NE_F_I
    { 601,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #601 = SETP_NE_F
    { 600,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #600 = SETP_NE
    { 599,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #599 = SETP_LT_U_NPI
    { 598,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #598 = SETP_LT_U_NP
    { 597,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #597 = SETP_LT_U_I
    { 596,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #596 = SETP_LT_U
    { 595,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #595 = SETP_LT_NPI
    { 594,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #594 = SETP_LT_NP
    { 593,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #593 = SETP_LT_I
    { 592,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #592 = SETP_LT_F_NPI
    { 591,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #591 = SETP_LT_F_NP
    { 590,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #590 = SETP_LT_F_I
    { 589,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #589 = SETP_LT_F
    { 588,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #588 = SETP_LT
    { 587,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #587 = SETP_LE_U_NPI
    { 586,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #586 = SETP_LE_U_NP
    { 585,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #585 = SETP_LE_U_I
    { 584,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #584 = SETP_LE_U
    { 583,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #583 = SETP_LE_NPI
    { 582,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #582 = SETP_LE_NP
    { 581,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #581 = SETP_LE_I
    { 580,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #580 = SETP_LE_F_NPI
    { 579,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #579 = SETP_LE_F_NP
    { 578,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #578 = SETP_LE_F_I
    { 577,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #577 = SETP_LE_F
    { 576,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #576 = SETP_LE
    { 575,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #575 = SETP_GT_U_NPI
    { 574,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #574 = SETP_GT_U_NP
    { 573,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #573 = SETP_GT_U_I
    { 572,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #572 = SETP_GT_U
    { 571,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #571 = SETP_GT_NPI
    { 570,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #570 = SETP_GT_NP
    { 569,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #569 = SETP_GT_I
    { 568,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #568 = SETP_GT_F_NPI
    { 567,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #567 = SETP_GT_F_NP
    { 566,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #566 = SETP_GT_F_I
    { 565,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #565 = SETP_GT_F
    { 564,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #564 = SETP_GT
    { 563,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #563 = SETP_GE_U_NPI
    { 562,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #562 = SETP_GE_U_NP
    { 561,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #561 = SETP_GE_U_I
    { 560,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #560 = SETP_GE_U
    { 559,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #559 = SETP_GE_NPI
    { 558,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #558 = SETP_GE_NP
    { 557,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #557 = SETP_GE_I
    { 556,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #556 = SETP_GE_F_NPI
    { 555,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #555 = SETP_GE_F_NP
    { 554,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #554 = SETP_GE_F_I
    { 553,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #553 = SETP_GE_F
    { 552,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #552 = SETP_GE
    { 551,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #551 = SETP_EQ_NPI
    { 550,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #550 = SETP_EQ_NP
    { 549,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #549 = SETP_EQ_I
    { 548,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #548 = SETP_EQ_F_NPI
    { 547,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #547 = SETP_EQ_F_NP
    { 546,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #546 = SETP_EQ_F_I
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
    /* 286 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 291 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
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
  /* 259 */ "FNEG_F1\0"
  /* 267 */ "FMUL_F1\0"
  /* 275 */ "FMIN_F1\0"
  /* 283 */ "FABS_F1\0"
  /* 291 */ "FMAX_F1\0"
  /* 299 */ "CVT_D0_S0_R1\0"
  /* 312 */ "CVT_D1_S0_R1\0"
  /* 325 */ "CVT_D0_S1_R1\0"
  /* 338 */ "CVT_D1_S1_R1\0"
  /* 351 */ "CVT_D2_S1_R1\0"
  /* 364 */ "CVT_D3_S1_R1\0"
  /* 377 */ "CVT_D0_S2_R1\0"
  /* 390 */ "CVT_D1_S2_R1\0"
  /* 403 */ "CVT_D0_S3_R1\0"
  /* 416 */ "CVT_D1_S3_R1\0"
  /* 429 */ "CVT_S32_F32\0"
  /* 441 */ "CVT_U32_F32\0"
  /* 453 */ "LG2_F32\0"
  /* 461 */ "EX2_F32\0"
  /* 469 */ "SIN_F32\0"
  /* 477 */ "RCP_F32\0"
  /* 485 */ "COS_F32\0"
  /* 493 */ "RSQRT_F32\0"
  /* 503 */ "CVT_F32_S32\0"
  /* 515 */ "CVT_F32_U32\0"
  /* 527 */ "RCP_U32\0"
  /* 535 */ "G_FLOG2\0"
  /* 543 */ "DP4_E5M2\0"
  /* 552 */ "G_FEXP2\0"
  /* 560 */ "CVT_D0_S0_R2\0"
  /* 573 */ "CVT_D1_S0_R2\0"
  /* 586 */ "CVT_D2_S0_R2\0"
  /* 599 */ "CVT_D3_S0_R2\0"
  /* 612 */ "CVT_D0_S1_R2\0"
  /* 625 */ "CVT_D1_S1_R2\0"
  /* 638 */ "CVT_D2_S1_R2\0"
  /* 651 */ "CVT_D3_S1_R2\0"
  /* 664 */ "CVT_D0_S2_R2\0"
  /* 677 */ "CVT_D1_S2_R2\0"
  /* 690 */ "CVT_D0_S3_R2\0"
  /* 703 */ "CVT_D1_S3_R2\0"
  /* 716 */ "DP4_E4M3\0"
  /* 725 */ "CVT_D0_S0_R3\0"
  /* 738 */ "CVT_D1_S0_R3\0"
  /* 751 */ "CVT_D2_S0_R3\0"
  /* 764 */ "CVT_D3_S0_R3\0"
  /* 777 */ "CVT_D0_S1_R3\0"
  /* 790 */ "CVT_D1_S1_R3\0"
  /* 803 */ "CVT_D2_S1_R3\0"
  /* 816 */ "CVT_D3_S1_R3\0"
  /* 829 */ "CVT_D0_S2_R3\0"
  /* 842 */ "CVT_D1_S2_R3\0"
  /* 855 */ "CVT_D0_S3_R3\0"
  /* 868 */ "CVT_D1_S3_R3\0"
  /* 881 */ "DP2_BF16\0"
  /* 890 */ "DP2_F16\0"
  /* 898 */ "SUB_W16\0"
  /* 906 */ "ADD_W16\0"
  /* 914 */ "LD_SHARED_W16\0"
  /* 928 */ "ST_SHARED_W16\0"
  /* 942 */ "AND_W16\0"
  /* 950 */ "ADDI_W16\0"
  /* 959 */ "LD_GLOBAL_W16\0"
  /* 973 */ "ST_GLOBAL_W16\0"
  /* 987 */ "XOR_W16\0"
  /* 995 */ "MIN_S_W16\0"
  /* 1005 */ "MAX_S_W16\0"
  /* 1015 */ "LD_GLOBAL_SLOT_W16\0"
  /* 1034 */ "ST_GLOBAL_SLOT_W16\0"
  /* 1053 */ "LD_GLOBAL_IDX_W16\0"
  /* 1071 */ "ST_GLOBAL_IDX_W16\0"
  /* 1089 */ "ADDI48\0"
  /* 1096 */ "MOVI48\0"
  /* 1103 */ "LD_SHARED_W8\0"
  /* 1116 */ "ST_SHARED_W8\0"
  /* 1129 */ "LD_GLOBAL_W8\0"
  /* 1142 */ "ST_GLOBAL_W8\0"
  /* 1155 */ "LD_GLOBAL_SLOT_W8\0"
  /* 1173 */ "ST_GLOBAL_SLOT_W8\0"
  /* 1191 */ "LD_GLOBAL_IDX_W8\0"
  /* 1208 */ "ST_GLOBAL_IDX_W8\0"
  /* 1225 */ "G_FMA\0"
  /* 1231 */ "G_STRICT_FMA\0"
  /* 1244 */ "C_BRA\0"
  /* 1250 */ "C_SRA\0"
  /* 1256 */ "G_FSUB\0"
  /* 1263 */ "G_STRICT_FSUB\0"
  /* 1277 */ "G_ATOMICRMW_FSUB\0"
  /* 1294 */ "C_SUB\0"
  /* 1300 */ "G_SUB\0"
  /* 1306 */ "G_ATOMICRMW_SUB\0"
  /* 1322 */ "DP4_ACC\0"
  /* 1330 */ "MAD_ACC\0"
  /* 1338 */ "G_INTRINSIC\0"
  /* 1350 */ "G_FPTRUNC\0"
  /* 1360 */ "G_INTRINSIC_TRUNC\0"
  /* 1378 */ "G_TRUNC\0"
  /* 1386 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 1407 */ "G_DYN_STACKALLOC\0"
  /* 1424 */ "POPC\0"
  /* 1429 */ "G_FMAD\0"
  /* 1436 */ "G_INDEXED_SEXTLOAD\0"
  /* 1455 */ "G_SEXTLOAD\0"
  /* 1466 */ "G_INDEXED_ZEXTLOAD\0"
  /* 1485 */ "G_ZEXTLOAD\0"
  /* 1496 */ "G_INDEXED_LOAD\0"
  /* 1511 */ "G_LOAD\0"
  /* 1518 */ "C_FADD\0"
  /* 1525 */ "G_VECREDUCE_FADD\0"
  /* 1542 */ "G_FADD\0"
  /* 1549 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 1570 */ "G_STRICT_FADD\0"
  /* 1584 */ "G_ATOMICRMW_FADD\0"
  /* 1601 */ "C_ADD\0"
  /* 1607 */ "G_VECREDUCE_ADD\0"
  /* 1623 */ "G_ADD\0"
  /* 1629 */ "G_PTR_ADD\0"
  /* 1639 */ "G_ATOMICRMW_ADD\0"
  /* 1655 */ "LD_SHARED\0"
  /* 1665 */ "ST_SHARED\0"
  /* 1675 */ "PSEUDO_BRA_PRED\0"
  /* 1691 */ "PSEUDO_LD_PRED\0"
  /* 1706 */ "PSEUDO_ST_PRED\0"
  /* 1721 */ "G_ATOMICRMW_NAND\0"
  /* 1738 */ "PSEUDO_PAND\0"
  /* 1750 */ "C_AND\0"
  /* 1756 */ "G_VECREDUCE_AND\0"
  /* 1772 */ "G_AND\0"
  /* 1778 */ "G_ATOMICRMW_AND\0"
  /* 1794 */ "LIFETIME_END\0"
  /* 1807 */ "G_BRCOND\0"
  /* 1816 */ "G_LLROUND\0"
  /* 1826 */ "G_LROUND\0"
  /* 1835 */ "G_INTRINSIC_ROUND\0"
  /* 1853 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 1879 */ "LOAD_STACK_GUARD\0"
  /* 1896 */ "SRD\0"
  /* 1900 */ "PSEUDO_PROBE\0"
  /* 1913 */ "G_SSUBE\0"
  /* 1921 */ "G_USUBE\0"
  /* 1929 */ "C_FENCE\0"
  /* 1937 */ "G_FENCE\0"
  /* 1945 */ "ARITH_FENCE\0"
  /* 1957 */ "REG_SEQUENCE\0"
  /* 1970 */ "G_SADDE\0"
  /* 1978 */ "G_UADDE\0"
  /* 1986 */ "G_GET_FPMODE\0"
  /* 1999 */ "G_RESET_FPMODE\0"
  /* 2014 */ "G_SET_FPMODE\0"
  /* 2027 */ "G_FMINNUM_IEEE\0"
  /* 2042 */ "G_FMAXNUM_IEEE\0"
  /* 2057 */ "SETP_GE\0"
  /* 2065 */ "G_JUMP_TABLE\0"
  /* 2078 */ "BUNDLE\0"
  /* 2085 */ "SETP_LE\0"
  /* 2093 */ "G_MEMCPY_INLINE\0"
  /* 2109 */ "SETP_NE\0"
  /* 2117 */ "LOCAL_ESCAPE\0"
  /* 2130 */ "G_STACKRESTORE\0"
  /* 2145 */ "G_INDEXED_STORE\0"
  /* 2161 */ "G_STORE\0"
  /* 2169 */ "BAR_WAIT_PHASE\0"
  /* 2184 */ "G_BITREVERSE\0"
  /* 2197 */ "DBG_VALUE\0"
  /* 2207 */ "G_GLOBAL_VALUE\0"
  /* 2222 */ "G_STACKSAVE\0"
  /* 2234 */ "C_BAR_ARRIVE\0"
  /* 2247 */ "G_MEMMOVE\0"
  /* 2257 */ "G_FREEZE\0"
  /* 2266 */ "G_FCANONICALIZE\0"
  /* 2282 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 2300 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 2318 */ "G_IMPLICIT_DEF\0"
  /* 2333 */ "DBG_INSTR_REF\0"
  /* 2347 */ "SETP_GE_F\0"
  /* 2357 */ "SETP_LE_F\0"
  /* 2367 */ "SETP_NE_F\0"
  /* 2377 */ "SETP_EQ_F\0"
  /* 2387 */ "SETP_GT_F\0"
  /* 2397 */ "SETP_LT_F\0"
  /* 2407 */ "G_FNEG\0"
  /* 2414 */ "C_NEG\0"
  /* 2420 */ "EXTRACT_SUBREG\0"
  /* 2435 */ "INSERT_SUBREG\0"
  /* 2449 */ "G_SEXT_INREG\0"
  /* 2462 */ "SUBREG_TO_REG\0"
  /* 2476 */ "G_ATOMIC_CMPXCHG\0"
  /* 2493 */ "G_ATOMICRMW_XCHG\0"
  /* 2510 */ "G_FLOG\0"
  /* 2517 */ "G_VAARG\0"
  /* 2525 */ "PREALLOCATED_ARG\0"
  /* 2542 */ "ATOM_ADD_G\0"
  /* 2553 */ "LD_PRED_G\0"
  /* 2563 */ "ST_PRED_G\0"
  /* 2573 */ "CAS_G\0"
  /* 2579 */ "G_PREFETCH\0"
  /* 2590 */ "G_SMULH\0"
  /* 2598 */ "G_UMULH\0"
  /* 2606 */ "C_CHWIDTH\0"
  /* 2616 */ "C_SRAI\0"
  /* 2623 */ "C_SUBI\0"
  /* 2630 */ "C_ADDI\0"
  /* 2637 */ "C_ANDI\0"
  /* 2644 */ "DBG_PHI\0"
  /* 2652 */ "UNPACKI\0"
  /* 2660 */ "C_SHLI\0"
  /* 2667 */ "MULI\0"
  /* 2672 */ "ANDNI\0"
  /* 2678 */ "SETP_GE_NPI\0"
  /* 2690 */ "SETP_LE_NPI\0"
  /* 2702 */ "SETP_NE_NPI\0"
  /* 2714 */ "SETP_GE_F_NPI\0"
  /* 2728 */ "SETP_LE_F_NPI\0"
  /* 2742 */ "SETP_NE_F_NPI\0"
  /* 2756 */ "SETP_EQ_F_NPI\0"
  /* 2770 */ "SETP_GT_F_NPI\0"
  /* 2784 */ "SETP_LT_F_NPI\0"
  /* 2798 */ "SETP_EQ_NPI\0"
  /* 2810 */ "SETP_GT_NPI\0"
  /* 2822 */ "SETP_LT_NPI\0"
  /* 2834 */ "SETP_GE_U_NPI\0"
  /* 2848 */ "SETP_LE_U_NPI\0"
  /* 2862 */ "SETP_GT_U_NPI\0"
  /* 2876 */ "SETP_LT_U_NPI\0"
  /* 2890 */ "C_SHRI\0"
  /* 2897 */ "C_XORI\0"
  /* 2904 */ "C_ORI\0"
  /* 2910 */ "G_FPTOSI\0"
  /* 2919 */ "CHWIDTH_MULTI\0"
  /* 2933 */ "G_FPTOUI\0"
  /* 2942 */ "MOVI\0"
  /* 2947 */ "G_FPOWI\0"
  /* 2955 */ "SETP_GE_I\0"
  /* 2965 */ "SETP_LE_I\0"
  /* 2975 */ "SETP_NE_I\0"
  /* 2985 */ "SETP_GE_F_I\0"
  /* 2997 */ "SETP_LE_F_I\0"
  /* 3009 */ "SETP_NE_F_I\0"
  /* 3021 */ "SETP_EQ_F_I\0"
  /* 3033 */ "SETP_GT_F_I\0"
  /* 3045 */ "SETP_LT_F_I\0"
  /* 3057 */ "SETP_EQ_I\0"
  /* 3067 */ "SETP_GT_I\0"
  /* 3077 */ "SETP_LT_I\0"
  /* 3087 */ "SETP_GE_U_I\0"
  /* 3099 */ "SETP_LE_U_I\0"
  /* 3111 */ "SETP_GT_U_I\0"
  /* 3123 */ "SETP_LT_U_I\0"
  /* 3135 */ "G_PTRMASK\0"
  /* 3145 */ "C_LD_GLOBAL\0"
  /* 3157 */ "C_ST_GLOBAL\0"
  /* 3169 */ "GC_LABEL\0"
  /* 3178 */ "DBG_LABEL\0"
  /* 3188 */ "EH_LABEL\0"
  /* 3197 */ "ANNOTATION_LABEL\0"
  /* 3214 */ "ICALL_BRANCH_FUNNEL\0"
  /* 3234 */ "SEL\0"
  /* 3238 */ "G_FSHL\0"
  /* 3245 */ "C_SHL\0"
  /* 3251 */ "G_SHL\0"
  /* 3257 */ "G_FCEIL\0"
  /* 3265 */ "PATCHABLE_TAIL_CALL\0"
  /* 3285 */ "PSEUDO_CALL\0"
  /* 3297 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 3324 */ "PATCHABLE_EVENT_CALL\0"
  /* 3345 */ "FENTRY_CALL\0"
  /* 3357 */ "KILL\0"
  /* 3362 */ "G_CONSTANT_POOL\0"
  /* 3378 */ "G_ROTL\0"
  /* 3385 */ "C_FMUL\0"
  /* 3392 */ "G_VECREDUCE_FMUL\0"
  /* 3409 */ "G_FMUL\0"
  /* 3416 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 3437 */ "G_STRICT_FMUL\0"
  /* 3451 */ "G_VECREDUCE_MUL\0"
  /* 3467 */ "G_MUL\0"
  /* 3473 */ "G_FREM\0"
  /* 3480 */ "G_STRICT_FREM\0"
  /* 3494 */ "G_SREM\0"
  /* 3501 */ "G_UREM\0"
  /* 3508 */ "G_SDIVREM\0"
  /* 3518 */ "G_UDIVREM\0"
  /* 3528 */ "PMOV_IMM\0"
  /* 3537 */ "INLINEASM\0"
  /* 3547 */ "G_VECREDUCE_FMINIMUM\0"
  /* 3568 */ "G_FMINIMUM\0"
  /* 3579 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 3600 */ "G_FMAXIMUM\0"
  /* 3611 */ "G_FMINNUM\0"
  /* 3621 */ "G_FMAXNUM\0"
  /* 3631 */ "C_ANDN\0"
  /* 3638 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 3660 */ "G_ASSERT_ALIGN\0"
  /* 3675 */ "G_FCOPYSIGN\0"
  /* 3687 */ "C_FMIN\0"
  /* 3694 */ "G_VECREDUCE_FMIN\0"
  /* 3711 */ "G_ATOMICRMW_FMIN\0"
  /* 3728 */ "G_VECREDUCE_SMIN\0"
  /* 3745 */ "G_SMIN\0"
  /* 3752 */ "G_VECREDUCE_UMIN\0"
  /* 3769 */ "G_UMIN\0"
  /* 3776 */ "G_ATOMICRMW_UMIN\0"
  /* 3793 */ "G_ATOMICRMW_MIN\0"
  /* 3809 */ "G_FSIN\0"
  /* 3816 */ "CFI_INSTRUCTION\0"
  /* 3832 */ "ADJCALLSTACKDOWN\0"
  /* 3849 */ "G_SSUBO\0"
  /* 3857 */ "G_USUBO\0"
  /* 3865 */ "G_SADDO\0"
  /* 3873 */ "G_UADDO\0"
  /* 3881 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 3903 */ "MADLO\0"
  /* 3909 */ "G_SMULO\0"
  /* 3917 */ "G_UMULO\0"
  /* 3925 */ "C_MUL_LO\0"
  /* 3934 */ "G_BZERO\0"
  /* 3942 */ "STACKMAP\0"
  /* 3951 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 3973 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 3995 */ "G_BSWAP\0"
  /* 4003 */ "G_SITOFP\0"
  /* 4012 */ "G_UITOFP\0"
  /* 4021 */ "G_FCMP\0"
  /* 4028 */ "G_ICMP\0"
  /* 4035 */ "SETP_GE_NP\0"
  /* 4046 */ "SETP_LE_NP\0"
  /* 4057 */ "SETP_NE_NP\0"
  /* 4068 */ "SETP_GE_F_NP\0"
  /* 4081 */ "SETP_LE_F_NP\0"
  /* 4094 */ "SETP_NE_F_NP\0"
  /* 4107 */ "SETP_EQ_F_NP\0"
  /* 4120 */ "SETP_GT_F_NP\0"
  /* 4133 */ "SETP_LT_F_NP\0"
  /* 4146 */ "SETP_EQ_NP\0"
  /* 4157 */ "SETP_GT_NP\0"
  /* 4168 */ "SETP_LT_NP\0"
  /* 4179 */ "SETP_GE_U_NP\0"
  /* 4192 */ "SETP_LE_U_NP\0"
  /* 4205 */ "SETP_GT_U_NP\0"
  /* 4218 */ "SETP_LT_U_NP\0"
  /* 4231 */ "G_CTPOP\0"
  /* 4239 */ "PATCHABLE_OP\0"
  /* 4252 */ "FAULTING_OP\0"
  /* 4264 */ "ADD_PP\0"
  /* 4271 */ "ADDI_PP\0"
  /* 4279 */ "ADJCALLSTACKUP\0"
  /* 4294 */ "PREALLOCATED_SETUP\0"
  /* 4313 */ "G_FLDEXP\0"
  /* 4322 */ "G_STRICT_FLDEXP\0"
  /* 4338 */ "G_FEXP\0"
  /* 4345 */ "G_FFREXP\0"
  /* 4354 */ "CVT_D0_S0_R0_P\0"
  /* 4369 */ "CVT_D1_S0_R0_P\0"
  /* 4384 */ "CVT_D2_S0_R0_P\0"
  /* 4399 */ "CVT_D3_S0_R0_P\0"
  /* 4414 */ "CVT_D0_S1_R0_P\0"
  /* 4429 */ "CVT_D1_S1_R0_P\0"
  /* 4444 */ "CVT_D2_S1_R0_P\0"
  /* 4459 */ "CVT_D3_S1_R0_P\0"
  /* 4474 */ "CVT_D1_S2_R0_P\0"
  /* 4489 */ "CVT_D3_S2_R0_P\0"
  /* 4504 */ "CVT_D1_S3_R0_P\0"
  /* 4519 */ "CVT_D2_S3_R0_P\0"
  /* 4534 */ "CVT_D3_S3_R0_P\0"
  /* 4549 */ "CVT_D0_S0_R1_P\0"
  /* 4564 */ "CVT_D1_S0_R1_P\0"
  /* 4579 */ "CVT_D0_S1_R1_P\0"
  /* 4594 */ "CVT_D1_S1_R1_P\0"
  /* 4609 */ "CVT_D2_S1_R1_P\0"
  /* 4624 */ "CVT_D3_S1_R1_P\0"
  /* 4639 */ "CVT_D0_S2_R1_P\0"
  /* 4654 */ "CVT_D1_S2_R1_P\0"
  /* 4669 */ "CVT_D0_S3_R1_P\0"
  /* 4684 */ "CVT_D1_S3_R1_P\0"
  /* 4699 */ "CVT_S32_F32_P\0"
  /* 4713 */ "CVT_U32_F32_P\0"
  /* 4727 */ "RCP_F32_P\0"
  /* 4737 */ "CVT_F32_S32_P\0"
  /* 4751 */ "CVT_F32_U32_P\0"
  /* 4765 */ "CVT_D0_S0_R2_P\0"
  /* 4780 */ "CVT_D1_S0_R2_P\0"
  /* 4795 */ "CVT_D2_S0_R2_P\0"
  /* 4810 */ "CVT_D3_S0_R2_P\0"
  /* 4825 */ "CVT_D0_S1_R2_P\0"
  /* 4840 */ "CVT_D1_S1_R2_P\0"
  /* 4855 */ "CVT_D2_S1_R2_P\0"
  /* 4870 */ "CVT_D3_S1_R2_P\0"
  /* 4885 */ "CVT_D0_S2_R2_P\0"
  /* 4900 */ "CVT_D1_S2_R2_P\0"
  /* 4915 */ "CVT_D0_S3_R2_P\0"
  /* 4930 */ "CVT_D1_S3_R2_P\0"
  /* 4945 */ "CVT_D0_S0_R3_P\0"
  /* 4960 */ "CVT_D1_S0_R3_P\0"
  /* 4975 */ "CVT_D2_S0_R3_P\0"
  /* 4990 */ "CVT_D3_S0_R3_P\0"
  /* 5005 */ "CVT_D0_S1_R3_P\0"
  /* 5020 */ "CVT_D1_S1_R3_P\0"
  /* 5035 */ "CVT_D2_S1_R3_P\0"
  /* 5050 */ "CVT_D3_S1_R3_P\0"
  /* 5065 */ "CVT_D0_S2_R3_P\0"
  /* 5080 */ "CVT_D1_S2_R3_P\0"
  /* 5095 */ "CVT_D0_S3_R3_P\0"
  /* 5110 */ "CVT_D1_S3_R3_P\0"
  /* 5125 */ "SRA_P\0"
  /* 5131 */ "FSUB_P\0"
  /* 5138 */ "FADD_P\0"
  /* 5145 */ "AND_P\0"
  /* 5151 */ "SRAI_P\0"
  /* 5158 */ "SUBI_P\0"
  /* 5165 */ "ADDI_P\0"
  /* 5172 */ "ANDI_P\0"
  /* 5179 */ "SHLI_P\0"
  /* 5186 */ "MULI_P\0"
  /* 5193 */ "ANDNI_P\0"
  /* 5201 */ "SHRI_P\0"
  /* 5208 */ "XORI_P\0"
  /* 5215 */ "LD_GLOBAL_P\0"
  /* 5227 */ "SHL_P\0"
  /* 5233 */ "FMUL_P\0"
  /* 5240 */ "MADLO_P\0"
  /* 5248 */ "SHR_P\0"
  /* 5254 */ "XOR_P\0"
  /* 5260 */ "MUL_HI_S_P\0"
  /* 5271 */ "MIN_S_P\0"
  /* 5279 */ "MAX_S_P\0"
  /* 5287 */ "MUL_HI_U_P\0"
  /* 5298 */ "MIN_U_P\0"
  /* 5306 */ "MAX_U_P\0"
  /* 5314 */ "MOV_P\0"
  /* 5320 */ "SETP_EQ\0"
  /* 5328 */ "G_BR\0"
  /* 5333 */ "INLINEASM_BR\0"
  /* 5346 */ "G_BLOCK_ADDR\0"
  /* 5359 */ "MEMBARRIER\0"
  /* 5370 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 5394 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 5419 */ "G_READCYCLECOUNTER\0"
  /* 5438 */ "G_READ_REGISTER\0"
  /* 5454 */ "G_WRITE_REGISTER\0"
  /* 5471 */ "G_ASHR\0"
  /* 5478 */ "G_FSHR\0"
  /* 5485 */ "G_LSHR\0"
  /* 5492 */ "C_SHR\0"
  /* 5498 */ "G_FFLOOR\0"
  /* 5507 */ "PSEUDO_POR\0"
  /* 5518 */ "G_BUILD_VECTOR\0"
  /* 5533 */ "G_SHUFFLE_VECTOR\0"
  /* 5550 */ "PSEUDO_PXOR\0"
  /* 5562 */ "C_XOR\0"
  /* 5568 */ "G_VECREDUCE_XOR\0"
  /* 5584 */ "G_XOR\0"
  /* 5590 */ "G_ATOMICRMW_XOR\0"
  /* 5606 */ "C_OR\0"
  /* 5611 */ "G_VECREDUCE_OR\0"
  /* 5626 */ "G_OR\0"
  /* 5631 */ "G_ATOMICRMW_OR\0"
  /* 5646 */ "G_ROTR\0"
  /* 5653 */ "G_INTTOPTR\0"
  /* 5664 */ "G_FABS\0"
  /* 5671 */ "C_ABS\0"
  /* 5677 */ "G_ABS\0"
  /* 5683 */ "G_UNMERGE_VALUES\0"
  /* 5700 */ "G_MERGE_VALUES\0"
  /* 5715 */ "G_FCOS\0"
  /* 5722 */ "G_CONCAT_VECTORS\0"
  /* 5739 */ "COPY_TO_REGCLASS\0"
  /* 5756 */ "G_IS_FPCLASS\0"
  /* 5769 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 5799 */ "DP4_SS\0"
  /* 5806 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 5833 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 5871 */ "LD_PRED_S\0"
  /* 5881 */ "ST_PRED_S\0"
  /* 5891 */ "MUL_HI_S\0"
  /* 5900 */ "C_MIN_S\0"
  /* 5908 */ "C_MAX_S\0"
  /* 5916 */ "G_SSUBSAT\0"
  /* 5926 */ "G_USUBSAT\0"
  /* 5936 */ "G_SADDSAT\0"
  /* 5946 */ "G_UADDSAT\0"
  /* 5956 */ "G_SSHLSAT\0"
  /* 5966 */ "G_USHLSAT\0"
  /* 5976 */ "G_SMULFIXSAT\0"
  /* 5989 */ "G_UMULFIXSAT\0"
  /* 6002 */ "G_SDIVFIXSAT\0"
  /* 6015 */ "G_UDIVFIXSAT\0"
  /* 6028 */ "G_EXTRACT\0"
  /* 6038 */ "G_SELECT\0"
  /* 6047 */ "G_BRINDIRECT\0"
  /* 6060 */ "C_RET\0"
  /* 6066 */ "PATCHABLE_RET\0"
  /* 6080 */ "PSEUDO_RET\0"
  /* 6091 */ "G_MEMSET\0"
  /* 6100 */ "SETP_GT\0"
  /* 6108 */ "C_BAR_WAIT\0"
  /* 6119 */ "BAR_INIT\0"
  /* 6128 */ "C_EXIT\0"
  /* 6135 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 6159 */ "G_BRJT\0"
  /* 6166 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 6187 */ "G_INSERT_VECTOR_ELT\0"
  /* 6207 */ "SETP_LT\0"
  /* 6215 */ "G_FCONSTANT\0"
  /* 6227 */ "G_CONSTANT\0"
  /* 6238 */ "G_INTRINSIC_CONVERGENT\0"
  /* 6261 */ "STATEPOINT\0"
  /* 6272 */ "PATCHPOINT\0"
  /* 6283 */ "G_PTRTOINT\0"
  /* 6294 */ "G_FRINT\0"
  /* 6302 */ "G_INTRINSIC_LRINT\0"
  /* 6320 */ "G_FNEARBYINT\0"
  /* 6333 */ "UNBALLOT\0"
  /* 6342 */ "LD_GLOBAL_SLOT\0"
  /* 6357 */ "ST_GLOBAL_SLOT\0"
  /* 6372 */ "C_NOT\0"
  /* 6378 */ "G_VASTART\0"
  /* 6388 */ "LIFETIME_START\0"
  /* 6403 */ "G_INVOKE_REGION_START\0"
  /* 6425 */ "G_INSERT\0"
  /* 6434 */ "G_FSQRT\0"
  /* 6442 */ "G_STRICT_FSQRT\0"
  /* 6457 */ "PSEUDO_BCAST\0"
  /* 6470 */ "G_BITCAST\0"
  /* 6480 */ "G_ADDRSPACE_CAST\0"
  /* 6497 */ "DBG_VALUE_LIST\0"
  /* 6512 */ "G_FPEXT\0"
  /* 6520 */ "G_SEXT\0"
  /* 6527 */ "G_ASSERT_SEXT\0"
  /* 6541 */ "CVT_SEXT\0"
  /* 6550 */ "G_ANYEXT\0"
  /* 6559 */ "G_ZEXT\0"
  /* 6566 */ "G_ASSERT_ZEXT\0"
  /* 6580 */ "SETP_GE_U\0"
  /* 6590 */ "SETP_LE_U\0"
  /* 6600 */ "MUL_HI_U\0"
  /* 6609 */ "C_MIN_U\0"
  /* 6617 */ "SETP_GT_U\0"
  /* 6627 */ "SETP_LT_U\0"
  /* 6637 */ "C_MAX_U\0"
  /* 6645 */ "BREV\0"
  /* 6650 */ "G_FDIV\0"
  /* 6657 */ "G_STRICT_FDIV\0"
  /* 6671 */ "G_SDIV\0"
  /* 6678 */ "G_UDIV\0"
  /* 6685 */ "G_GET_FPENV\0"
  /* 6697 */ "G_RESET_FPENV\0"
  /* 6711 */ "G_SET_FPENV\0"
  /* 6723 */ "C_RECONV\0"
  /* 6732 */ "PSEUDO_PMOV\0"
  /* 6744 */ "C_MOV\0"
  /* 6750 */ "G_FPOW\0"
  /* 6757 */ "PSEUDO_NARROW\0"
  /* 6771 */ "C_FMAX\0"
  /* 6778 */ "G_VECREDUCE_FMAX\0"
  /* 6795 */ "G_ATOMICRMW_FMAX\0"
  /* 6812 */ "G_VECREDUCE_SMAX\0"
  /* 6829 */ "G_SMAX\0"
  /* 6836 */ "G_VECREDUCE_UMAX\0"
  /* 6853 */ "G_UMAX\0"
  /* 6860 */ "G_ATOMICRMW_UMAX\0"
  /* 6877 */ "G_ATOMICRMW_MAX\0"
  /* 6893 */ "LD_SHARED_IDX\0"
  /* 6907 */ "ST_SHARED_IDX\0"
  /* 6921 */ "LD_GLOBAL_IDX\0"
  /* 6935 */ "ST_GLOBAL_IDX\0"
  /* 6949 */ "SHFL_IDX\0"
  /* 6958 */ "G_FRAME_INDEX\0"
  /* 6972 */ "G_SBFX\0"
  /* 6979 */ "G_UBFX\0"
  /* 6986 */ "G_SMULFIX\0"
  /* 6996 */ "G_UMULFIX\0"
  /* 7006 */ "G_SDIVFIX\0"
  /* 7016 */ "G_UDIVFIX\0"
  /* 7026 */ "VOTE_ANY\0"
  /* 7035 */ "G_MEMCPY\0"
  /* 7044 */ "COPY\0"
  /* 7049 */ "CLZ\0"
  /* 7053 */ "G_CTLZ\0"
  /* 7060 */ "G_CTTZ\0"
  /* 7067 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    2648U, 3537U, 5333U, 3816U, 3188U, 3169U, 3197U, 3357U, 
    2420U, 2435U, 2320U, 2462U, 5739U, 2197U, 6497U, 2333U, 
    2644U, 3178U, 1957U, 7044U, 2078U, 6388U, 1794U, 1900U, 
    1945U, 3942U, 3345U, 6272U, 1879U, 4294U, 2525U, 6261U, 
    2117U, 4252U, 4239U, 5394U, 6066U, 6135U, 3265U, 3324U, 
    3297U, 3214U, 5359U, 3881U, 6527U, 6566U, 3660U, 1623U, 
    1300U, 3467U, 6671U, 6678U, 3494U, 3501U, 3508U, 3518U, 
    1772U, 5626U, 5584U, 2318U, 2646U, 6958U, 2207U, 3362U, 
    6028U, 5683U, 6425U, 5700U, 5518U, 1386U, 5722U, 6283U, 
    5653U, 6470U, 2257U, 5370U, 1853U, 1360U, 1835U, 6302U, 
    3638U, 5419U, 1511U, 1455U, 1485U, 1496U, 1436U, 1466U, 
    2161U, 2145U, 5769U, 2476U, 2493U, 1639U, 1306U, 1778U, 
    1721U, 5631U, 5590U, 6877U, 3793U, 6860U, 3776U, 1584U, 
    1277U, 6795U, 3711U, 3973U, 3951U, 1937U, 2579U, 1807U, 
    6047U, 6403U, 1338U, 5806U, 6238U, 5833U, 6550U, 1378U, 
    6227U, 6215U, 6378U, 2517U, 6520U, 2449U, 6559U, 3251U, 
    5485U, 5471U, 3238U, 5478U, 5646U, 3378U, 4028U, 4021U, 
    6038U, 3873U, 1978U, 3857U, 1921U, 3865U, 1970U, 3849U, 
    1913U, 3917U, 3909U, 2598U, 2590U, 5946U, 5936U, 5926U, 
    5916U, 5966U, 5956U, 6986U, 6996U, 5976U, 5989U, 7006U, 
    7016U, 6002U, 6015U, 1542U, 1256U, 3409U, 1225U, 1429U, 
    6650U, 3473U, 6750U, 2947U, 4338U, 552U, 9U, 2510U, 
    535U, 0U, 4313U, 4345U, 2407U, 6512U, 1350U, 2910U, 
    2933U, 4003U, 4012U, 5664U, 3675U, 5756U, 2266U, 3611U, 
    3621U, 2027U, 2042U, 3568U, 3600U, 6685U, 6711U, 6697U, 
    1986U, 2014U, 1999U, 1629U, 3135U, 3745U, 6829U, 3769U, 
    6853U, 5677U, 1826U, 1816U, 5328U, 6159U, 6187U, 6166U, 
    5533U, 7060U, 2300U, 7053U, 2282U, 4231U, 3995U, 2184U, 
    3257U, 5715U, 3809U, 6434U, 5498U, 6294U, 6320U, 6480U, 
    5346U, 2065U, 1407U, 2222U, 2130U, 1570U, 1263U, 3437U, 
    6657U, 3480U, 1231U, 6442U, 4322U, 5438U, 5454U, 7035U, 
    2093U, 2247U, 6091U, 3934U, 1549U, 3416U, 1525U, 3392U, 
    6778U, 3694U, 3579U, 3547U, 1607U, 3451U, 1756U, 5611U, 
    5568U, 6812U, 3728U, 6836U, 3752U, 6972U, 6979U, 3832U, 
    4279U, 6457U, 1675U, 3285U, 1691U, 6757U, 1738U, 6732U, 
    5507U, 5550U, 6080U, 1706U, 5667U, 1521U, 2632U, 1089U, 
    5165U, 4271U, 950U, 5139U, 4264U, 906U, 1734U, 2639U, 
    5172U, 3633U, 2672U, 5193U, 5145U, 942U, 2542U, 6335U, 
    6119U, 2169U, 1246U, 1682U, 6645U, 3280U, 2573U, 2919U, 
    7049U, 485U, 54U, 4354U, 299U, 4549U, 560U, 4765U, 
    725U, 4945U, 106U, 4414U, 325U, 4579U, 612U, 4825U, 
    777U, 5005U, 377U, 4639U, 664U, 4885U, 829U, 5065U, 
    403U, 4669U, 690U, 4915U, 855U, 5095U, 67U, 4369U, 
    312U, 4564U, 573U, 4780U, 738U, 4960U, 119U, 4429U, 
    338U, 4594U, 625U, 4840U, 790U, 5020U, 158U, 4474U, 
    390U, 4654U, 677U, 4900U, 842U, 5080U, 184U, 4504U, 
    416U, 4684U, 703U, 4930U, 868U, 5110U, 80U, 4384U, 
    586U, 4795U, 751U, 4975U, 132U, 4444U, 351U, 4609U, 
    638U, 4855U, 803U, 5035U, 197U, 4519U, 93U, 4399U, 
    599U, 4810U, 764U, 4990U, 145U, 4459U, 364U, 4624U, 
    651U, 4870U, 816U, 5050U, 171U, 4489U, 210U, 4534U, 
    503U, 4737U, 515U, 4751U, 429U, 4699U, 6541U, 441U, 
    4713U, 5671U, 1601U, 2630U, 1750U, 2637U, 3631U, 2234U, 
    6108U, 1244U, 2606U, 6128U, 1518U, 1929U, 6771U, 3687U, 
    3385U, 3145U, 5908U, 6637U, 5900U, 6609U, 6744U, 3925U, 
    2414U, 6372U, 5606U, 2904U, 6723U, 6060U, 3245U, 2660U, 
    5492U, 2890U, 1250U, 2616U, 3157U, 1294U, 2623U, 5562U, 
    2897U, 881U, 890U, 1322U, 716U, 543U, 5799U, 461U, 
    46U, 283U, 1520U, 251U, 5138U, 26U, 239U, 18U, 
    223U, 6773U, 291U, 3689U, 275U, 3387U, 267U, 5233U, 
    38U, 259U, 1258U, 231U, 5131U, 3147U, 6921U, 1053U, 
    1191U, 5215U, 6342U, 1015U, 1155U, 959U, 1129U, 2553U, 
    5871U, 1655U, 6893U, 914U, 1103U, 453U, 3903U, 5240U, 
    1330U, 5910U, 5279U, 1005U, 6639U, 5306U, 5902U, 5271U, 
    995U, 6611U, 5298U, 2942U, 1096U, 5314U, 2667U, 5186U, 
    5891U, 5260U, 6600U, 5287U, 3927U, 2410U, 5504U, 2900U, 
    5209U, 5255U, 988U, 2654U, 7067U, 1745U, 6739U, 3528U, 
    1424U, 5514U, 5557U, 477U, 4727U, 527U, 493U, 3234U, 
    5320U, 2377U, 3021U, 4107U, 2756U, 3057U, 4146U, 2798U, 
    2057U, 2347U, 2985U, 4068U, 2714U, 2955U, 4035U, 2678U, 
    6580U, 3087U, 4179U, 2834U, 6100U, 2387U, 3033U, 4120U, 
    2770U, 3067U, 4157U, 2810U, 6617U, 3111U, 4205U, 2862U, 
    2085U, 2357U, 2997U, 4081U, 2728U, 2965U, 4046U, 2690U, 
    6590U, 3099U, 4192U, 2848U, 6207U, 2397U, 3045U, 4133U, 
    2784U, 3077U, 4168U, 2822U, 6627U, 3123U, 4218U, 2876U, 
    2109U, 2367U, 3009U, 4094U, 2742U, 2975U, 4057U, 2702U, 
    6949U, 3241U, 2662U, 5179U, 5227U, 5474U, 2892U, 5201U, 
    5248U, 469U, 494U, 1252U, 2618U, 5151U, 5125U, 1896U, 
    3159U, 6935U, 1071U, 1208U, 6357U, 1034U, 1173U, 973U, 
    1142U, 2563U, 5881U, 1665U, 6907U, 928U, 1116U, 1259U, 
    2625U, 5158U, 5132U, 898U, 6333U, 2652U, 7026U, 5558U, 
    2899U, 5208U, 5254U, 987U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 652);
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
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 652);
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
    /* SETP_EQ_F_I */
    1728,
    /* SETP_EQ_F_NP */
    1733,
    /* SETP_EQ_F_NPI */
    1737,
    /* SETP_EQ_I */
    1741,
    /* SETP_EQ_NP */
    1746,
    /* SETP_EQ_NPI */
    1750,
    /* SETP_GE */
    1754,
    /* SETP_GE_F */
    1759,
    /* SETP_GE_F_I */
    1764,
    /* SETP_GE_F_NP */
    1769,
    /* SETP_GE_F_NPI */
    1773,
    /* SETP_GE_I */
    1777,
    /* SETP_GE_NP */
    1782,
    /* SETP_GE_NPI */
    1786,
    /* SETP_GE_U */
    1790,
    /* SETP_GE_U_I */
    1795,
    /* SETP_GE_U_NP */
    1800,
    /* SETP_GE_U_NPI */
    1804,
    /* SETP_GT */
    1808,
    /* SETP_GT_F */
    1813,
    /* SETP_GT_F_I */
    1818,
    /* SETP_GT_F_NP */
    1823,
    /* SETP_GT_F_NPI */
    1827,
    /* SETP_GT_I */
    1831,
    /* SETP_GT_NP */
    1836,
    /* SETP_GT_NPI */
    1840,
    /* SETP_GT_U */
    1844,
    /* SETP_GT_U_I */
    1849,
    /* SETP_GT_U_NP */
    1854,
    /* SETP_GT_U_NPI */
    1858,
    /* SETP_LE */
    1862,
    /* SETP_LE_F */
    1867,
    /* SETP_LE_F_I */
    1872,
    /* SETP_LE_F_NP */
    1877,
    /* SETP_LE_F_NPI */
    1881,
    /* SETP_LE_I */
    1885,
    /* SETP_LE_NP */
    1890,
    /* SETP_LE_NPI */
    1894,
    /* SETP_LE_U */
    1898,
    /* SETP_LE_U_I */
    1903,
    /* SETP_LE_U_NP */
    1908,
    /* SETP_LE_U_NPI */
    1912,
    /* SETP_LT */
    1916,
    /* SETP_LT_F */
    1921,
    /* SETP_LT_F_I */
    1926,
    /* SETP_LT_F_NP */
    1931,
    /* SETP_LT_F_NPI */
    1935,
    /* SETP_LT_I */
    1939,
    /* SETP_LT_NP */
    1944,
    /* SETP_LT_NPI */
    1948,
    /* SETP_LT_U */
    1952,
    /* SETP_LT_U_I */
    1957,
    /* SETP_LT_U_NP */
    1962,
    /* SETP_LT_U_NPI */
    1966,
    /* SETP_NE */
    1970,
    /* SETP_NE_F */
    1975,
    /* SETP_NE_F_I */
    1980,
    /* SETP_NE_F_NP */
    1985,
    /* SETP_NE_F_NPI */
    1989,
    /* SETP_NE_I */
    1993,
    /* SETP_NE_NP */
    1998,
    /* SETP_NE_NPI */
    2002,
    /* SHFL_IDX */
    2006,
    /* SHL */
    2010,
    /* SHLI */
    2014,
    /* SHLI_P */
    2017,
    /* SHL_P */
    2021,
    /* SHR */
    2026,
    /* SHRI */
    2030,
    /* SHRI_P */
    2033,
    /* SHR_P */
    2037,
    /* SIN_F32 */
    2042,
    /* SQRT_F32 */
    2046,
    /* SRA */
    2050,
    /* SRAI */
    2054,
    /* SRAI_P */
    2057,
    /* SRA_P */
    2061,
    /* SRD */
    2066,
    /* ST_GLOBAL */
    2068,
    /* ST_GLOBAL_IDX */
    2071,
    /* ST_GLOBAL_IDX_W16 */
    2076,
    /* ST_GLOBAL_IDX_W8 */
    2081,
    /* ST_GLOBAL_SLOT */
    2086,
    /* ST_GLOBAL_SLOT_W16 */
    2091,
    /* ST_GLOBAL_SLOT_W8 */
    2096,
    /* ST_GLOBAL_W16 */
    2101,
    /* ST_GLOBAL_W8 */
    2104,
    /* ST_PRED_G */
    2107,
    /* ST_PRED_S */
    2110,
    /* ST_SHARED */
    2113,
    /* ST_SHARED_IDX */
    2116,
    /* ST_SHARED_W16 */
    2121,
    /* ST_SHARED_W8 */
    2124,
    /* SUB */
    2127,
    /* SUBI */
    2131,
    /* SUBI_P */
    2134,
    /* SUB_P */
    2138,
    /* SUB_W16 */
    2143,
    /* UNBALLOT */
    2147,
    /* UNPACKI */
    2150,
    /* VOTE_ANY */
    2153,
    /* XOR */
    2156,
    /* XORI */
    2160,
    /* XORI_P */
    2163,
    /* XOR_P */
    2167,
    /* XOR_W16 */
    2172,
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
    CEFBS_None, // SETP_EQ_F_I = 546
    CEFBS_None, // SETP_EQ_F_NP = 547
    CEFBS_None, // SETP_EQ_F_NPI = 548
    CEFBS_None, // SETP_EQ_I = 549
    CEFBS_None, // SETP_EQ_NP = 550
    CEFBS_None, // SETP_EQ_NPI = 551
    CEFBS_None, // SETP_GE = 552
    CEFBS_None, // SETP_GE_F = 553
    CEFBS_None, // SETP_GE_F_I = 554
    CEFBS_None, // SETP_GE_F_NP = 555
    CEFBS_None, // SETP_GE_F_NPI = 556
    CEFBS_None, // SETP_GE_I = 557
    CEFBS_None, // SETP_GE_NP = 558
    CEFBS_None, // SETP_GE_NPI = 559
    CEFBS_None, // SETP_GE_U = 560
    CEFBS_None, // SETP_GE_U_I = 561
    CEFBS_None, // SETP_GE_U_NP = 562
    CEFBS_None, // SETP_GE_U_NPI = 563
    CEFBS_None, // SETP_GT = 564
    CEFBS_None, // SETP_GT_F = 565
    CEFBS_None, // SETP_GT_F_I = 566
    CEFBS_None, // SETP_GT_F_NP = 567
    CEFBS_None, // SETP_GT_F_NPI = 568
    CEFBS_None, // SETP_GT_I = 569
    CEFBS_None, // SETP_GT_NP = 570
    CEFBS_None, // SETP_GT_NPI = 571
    CEFBS_None, // SETP_GT_U = 572
    CEFBS_None, // SETP_GT_U_I = 573
    CEFBS_None, // SETP_GT_U_NP = 574
    CEFBS_None, // SETP_GT_U_NPI = 575
    CEFBS_None, // SETP_LE = 576
    CEFBS_None, // SETP_LE_F = 577
    CEFBS_None, // SETP_LE_F_I = 578
    CEFBS_None, // SETP_LE_F_NP = 579
    CEFBS_None, // SETP_LE_F_NPI = 580
    CEFBS_None, // SETP_LE_I = 581
    CEFBS_None, // SETP_LE_NP = 582
    CEFBS_None, // SETP_LE_NPI = 583
    CEFBS_None, // SETP_LE_U = 584
    CEFBS_None, // SETP_LE_U_I = 585
    CEFBS_None, // SETP_LE_U_NP = 586
    CEFBS_None, // SETP_LE_U_NPI = 587
    CEFBS_None, // SETP_LT = 588
    CEFBS_None, // SETP_LT_F = 589
    CEFBS_None, // SETP_LT_F_I = 590
    CEFBS_None, // SETP_LT_F_NP = 591
    CEFBS_None, // SETP_LT_F_NPI = 592
    CEFBS_None, // SETP_LT_I = 593
    CEFBS_None, // SETP_LT_NP = 594
    CEFBS_None, // SETP_LT_NPI = 595
    CEFBS_None, // SETP_LT_U = 596
    CEFBS_None, // SETP_LT_U_I = 597
    CEFBS_None, // SETP_LT_U_NP = 598
    CEFBS_None, // SETP_LT_U_NPI = 599
    CEFBS_None, // SETP_NE = 600
    CEFBS_None, // SETP_NE_F = 601
    CEFBS_None, // SETP_NE_F_I = 602
    CEFBS_None, // SETP_NE_F_NP = 603
    CEFBS_None, // SETP_NE_F_NPI = 604
    CEFBS_None, // SETP_NE_I = 605
    CEFBS_None, // SETP_NE_NP = 606
    CEFBS_None, // SETP_NE_NPI = 607
    CEFBS_None, // SHFL_IDX = 608
    CEFBS_None, // SHL = 609
    CEFBS_None, // SHLI = 610
    CEFBS_None, // SHLI_P = 611
    CEFBS_None, // SHL_P = 612
    CEFBS_None, // SHR = 613
    CEFBS_None, // SHRI = 614
    CEFBS_None, // SHRI_P = 615
    CEFBS_None, // SHR_P = 616
    CEFBS_None, // SIN_F32 = 617
    CEFBS_None, // SQRT_F32 = 618
    CEFBS_None, // SRA = 619
    CEFBS_None, // SRAI = 620
    CEFBS_None, // SRAI_P = 621
    CEFBS_None, // SRA_P = 622
    CEFBS_None, // SRD = 623
    CEFBS_None, // ST_GLOBAL = 624
    CEFBS_None, // ST_GLOBAL_IDX = 625
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 626
    CEFBS_None, // ST_GLOBAL_IDX_W8 = 627
    CEFBS_None, // ST_GLOBAL_SLOT = 628
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 629
    CEFBS_None, // ST_GLOBAL_SLOT_W8 = 630
    CEFBS_None, // ST_GLOBAL_W16 = 631
    CEFBS_None, // ST_GLOBAL_W8 = 632
    CEFBS_None, // ST_PRED_G = 633
    CEFBS_None, // ST_PRED_S = 634
    CEFBS_None, // ST_SHARED = 635
    CEFBS_None, // ST_SHARED_IDX = 636
    CEFBS_None, // ST_SHARED_W16 = 637
    CEFBS_None, // ST_SHARED_W8 = 638
    CEFBS_None, // SUB = 639
    CEFBS_None, // SUBI = 640
    CEFBS_None, // SUBI_P = 641
    CEFBS_None, // SUB_P = 642
    CEFBS_None, // SUB_W16 = 643
    CEFBS_None, // UNBALLOT = 644
    CEFBS_None, // UNPACKI = 645
    CEFBS_None, // VOTE_ANY = 646
    CEFBS_None, // XOR = 647
    CEFBS_None, // XORI = 648
    CEFBS_None, // XORI_P = 649
    CEFBS_None, // XOR_P = 650
    CEFBS_None, // XOR_W16 = 651
  };

  assert(Opcode < 652);
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

