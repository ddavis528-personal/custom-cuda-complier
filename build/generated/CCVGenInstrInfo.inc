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
    CVT_D0_S0_R0_W32_8	= 340,
    CVT_D0_S0_R0_W8_32	= 341,
    CVT_D0_S0_R1	= 342,
    CVT_D0_S0_R1_P	= 343,
    CVT_D0_S0_R2	= 344,
    CVT_D0_S0_R2_P	= 345,
    CVT_D0_S0_R3	= 346,
    CVT_D0_S0_R3_P	= 347,
    CVT_D0_S1_R0	= 348,
    CVT_D0_S1_R0_P	= 349,
    CVT_D0_S1_R0_W16_8	= 350,
    CVT_D0_S1_R0_W32_8	= 351,
    CVT_D0_S1_R1	= 352,
    CVT_D0_S1_R1_P	= 353,
    CVT_D0_S1_R2	= 354,
    CVT_D0_S1_R2_P	= 355,
    CVT_D0_S1_R3	= 356,
    CVT_D0_S1_R3_P	= 357,
    CVT_D0_S2_R1	= 358,
    CVT_D0_S2_R1_P	= 359,
    CVT_D0_S2_R2	= 360,
    CVT_D0_S2_R2_P	= 361,
    CVT_D0_S2_R3	= 362,
    CVT_D0_S2_R3_P	= 363,
    CVT_D0_S3_R1	= 364,
    CVT_D0_S3_R1_P	= 365,
    CVT_D0_S3_R2	= 366,
    CVT_D0_S3_R2_P	= 367,
    CVT_D0_S3_R3	= 368,
    CVT_D0_S3_R3_P	= 369,
    CVT_D1_S0_R0	= 370,
    CVT_D1_S0_R0_P	= 371,
    CVT_D1_S0_R0_W8_32	= 372,
    CVT_D1_S0_R1	= 373,
    CVT_D1_S0_R1_P	= 374,
    CVT_D1_S0_R2	= 375,
    CVT_D1_S0_R2_P	= 376,
    CVT_D1_S0_R3	= 377,
    CVT_D1_S0_R3_P	= 378,
    CVT_D1_S1_R0	= 379,
    CVT_D1_S1_R0_P	= 380,
    CVT_D1_S1_R1	= 381,
    CVT_D1_S1_R1_P	= 382,
    CVT_D1_S1_R2	= 383,
    CVT_D1_S1_R2_P	= 384,
    CVT_D1_S1_R3	= 385,
    CVT_D1_S1_R3_P	= 386,
    CVT_D1_S2_R0	= 387,
    CVT_D1_S2_R0_P	= 388,
    CVT_D1_S2_R1	= 389,
    CVT_D1_S2_R1_P	= 390,
    CVT_D1_S2_R2	= 391,
    CVT_D1_S2_R2_P	= 392,
    CVT_D1_S2_R3	= 393,
    CVT_D1_S2_R3_P	= 394,
    CVT_D1_S3_R0	= 395,
    CVT_D1_S3_R0_P	= 396,
    CVT_D1_S3_R1	= 397,
    CVT_D1_S3_R1_P	= 398,
    CVT_D1_S3_R2	= 399,
    CVT_D1_S3_R2_P	= 400,
    CVT_D1_S3_R3	= 401,
    CVT_D1_S3_R3_P	= 402,
    CVT_D2_S0_R0	= 403,
    CVT_D2_S0_R0_P	= 404,
    CVT_D2_S0_R2	= 405,
    CVT_D2_S0_R2_P	= 406,
    CVT_D2_S0_R3	= 407,
    CVT_D2_S0_R3_P	= 408,
    CVT_D2_S1_R0	= 409,
    CVT_D2_S1_R0_P	= 410,
    CVT_D2_S1_R1	= 411,
    CVT_D2_S1_R1_P	= 412,
    CVT_D2_S1_R2	= 413,
    CVT_D2_S1_R2_P	= 414,
    CVT_D2_S1_R3	= 415,
    CVT_D2_S1_R3_P	= 416,
    CVT_D2_S3_R0	= 417,
    CVT_D2_S3_R0_P	= 418,
    CVT_D3_S0_R0	= 419,
    CVT_D3_S0_R0_P	= 420,
    CVT_D3_S0_R2	= 421,
    CVT_D3_S0_R2_P	= 422,
    CVT_D3_S0_R3	= 423,
    CVT_D3_S0_R3_P	= 424,
    CVT_D3_S1_R0	= 425,
    CVT_D3_S1_R0_P	= 426,
    CVT_D3_S1_R1	= 427,
    CVT_D3_S1_R1_P	= 428,
    CVT_D3_S1_R2	= 429,
    CVT_D3_S1_R2_P	= 430,
    CVT_D3_S1_R3	= 431,
    CVT_D3_S1_R3_P	= 432,
    CVT_D3_S2_R0	= 433,
    CVT_D3_S2_R0_P	= 434,
    CVT_D3_S3_R0	= 435,
    CVT_D3_S3_R0_P	= 436,
    CVT_F32_S32	= 437,
    CVT_F32_S32_P	= 438,
    CVT_F32_U32	= 439,
    CVT_F32_U32_P	= 440,
    CVT_S32_F32	= 441,
    CVT_S32_F32_P	= 442,
    CVT_SEXT	= 443,
    CVT_U32_F32	= 444,
    CVT_U32_F32_P	= 445,
    C_ABS	= 446,
    C_ADD	= 447,
    C_ADDI	= 448,
    C_AND	= 449,
    C_ANDI	= 450,
    C_ANDN	= 451,
    C_BAR_ARRIVE	= 452,
    C_BAR_WAIT	= 453,
    C_BRA	= 454,
    C_CHWIDTH	= 455,
    C_EXIT	= 456,
    C_FADD	= 457,
    C_FENCE	= 458,
    C_FMAX	= 459,
    C_FMIN	= 460,
    C_FMUL	= 461,
    C_LD_GLOBAL	= 462,
    C_MAX_S	= 463,
    C_MAX_U	= 464,
    C_MIN_S	= 465,
    C_MIN_U	= 466,
    C_MOV	= 467,
    C_MUL_LO	= 468,
    C_NEG	= 469,
    C_NOT	= 470,
    C_OR	= 471,
    C_ORI	= 472,
    C_RECONV	= 473,
    C_RET	= 474,
    C_SHL	= 475,
    C_SHLI	= 476,
    C_SHR	= 477,
    C_SHRI	= 478,
    C_SRA	= 479,
    C_SRAI	= 480,
    C_ST_GLOBAL	= 481,
    C_SUB	= 482,
    C_SUBI	= 483,
    C_XOR	= 484,
    C_XORI	= 485,
    DP2_BF16	= 486,
    DP2_F16	= 487,
    DP4_ACC	= 488,
    DP4_E4M3	= 489,
    DP4_E5M2	= 490,
    DP4_SS	= 491,
    EX2_F32	= 492,
    FABS_F0	= 493,
    FABS_F1	= 494,
    FADD	= 495,
    FADD_F1	= 496,
    FADD_F1_W8	= 497,
    FADD_P	= 498,
    FADD_W8	= 499,
    FFMA_ACC_F0	= 500,
    FFMA_ACC_F1	= 501,
    FFMA_F0	= 502,
    FFMA_F1	= 503,
    FMAX	= 504,
    FMAX_F1	= 505,
    FMIN	= 506,
    FMIN_F1	= 507,
    FMUL	= 508,
    FMUL_F1	= 509,
    FMUL_F1_W8	= 510,
    FMUL_P	= 511,
    FMUL_W8	= 512,
    FNEG_F0	= 513,
    FNEG_F1	= 514,
    FSUB	= 515,
    FSUB_F1	= 516,
    FSUB_F1_W8	= 517,
    FSUB_P	= 518,
    FSUB_W8	= 519,
    LD_GLOBAL	= 520,
    LD_GLOBAL_IDX	= 521,
    LD_GLOBAL_IDX_W16	= 522,
    LD_GLOBAL_IDX_W8	= 523,
    LD_GLOBAL_P	= 524,
    LD_GLOBAL_SLOT	= 525,
    LD_GLOBAL_SLOT_W16	= 526,
    LD_GLOBAL_SLOT_W8	= 527,
    LD_GLOBAL_W16	= 528,
    LD_GLOBAL_W8	= 529,
    LD_LOCAL	= 530,
    LD_PRED_G	= 531,
    LD_PRED_LOCAL	= 532,
    LD_PRED_S	= 533,
    LD_SHARED	= 534,
    LD_SHARED_IDX	= 535,
    LD_SHARED_W16	= 536,
    LD_SHARED_W8	= 537,
    LG2_F32	= 538,
    MADLO	= 539,
    MADLO_P	= 540,
    MAD_ACC	= 541,
    MAX_S	= 542,
    MAX_S_P	= 543,
    MAX_S_W16	= 544,
    MAX_U	= 545,
    MAX_U_P	= 546,
    MIN_S	= 547,
    MIN_S_P	= 548,
    MIN_S_W16	= 549,
    MIN_U	= 550,
    MIN_U_P	= 551,
    MOVI	= 552,
    MOVI48	= 553,
    MOV_P	= 554,
    MULI	= 555,
    MULI_P	= 556,
    MUL_HI_S	= 557,
    MUL_HI_S_P	= 558,
    MUL_HI_U	= 559,
    MUL_HI_U_P	= 560,
    MUL_LO	= 561,
    NEG	= 562,
    OR	= 563,
    ORI	= 564,
    ORI_P	= 565,
    OR_P	= 566,
    OR_W16	= 567,
    PACKI	= 568,
    PACKI_Z	= 569,
    PAND	= 570,
    PMOV	= 571,
    PMOV_IMM	= 572,
    POPC	= 573,
    POR	= 574,
    PXOR	= 575,
    RCP_F32	= 576,
    RCP_F32_P	= 577,
    RCP_U32	= 578,
    RSQRT_F32	= 579,
    SEL	= 580,
    SETP_EQ	= 581,
    SETP_EQ_F	= 582,
    SETP_EQ_F1	= 583,
    SETP_EQ_F1_NP	= 584,
    SETP_EQ_F_I	= 585,
    SETP_EQ_F_NP	= 586,
    SETP_EQ_F_NPI	= 587,
    SETP_EQ_I	= 588,
    SETP_EQ_NP	= 589,
    SETP_EQ_NPI	= 590,
    SETP_GE	= 591,
    SETP_GE_F	= 592,
    SETP_GE_F1	= 593,
    SETP_GE_F1_NP	= 594,
    SETP_GE_F_I	= 595,
    SETP_GE_F_NP	= 596,
    SETP_GE_F_NPI	= 597,
    SETP_GE_I	= 598,
    SETP_GE_NP	= 599,
    SETP_GE_NPI	= 600,
    SETP_GE_U	= 601,
    SETP_GE_U_I	= 602,
    SETP_GE_U_NP	= 603,
    SETP_GE_U_NPI	= 604,
    SETP_GT	= 605,
    SETP_GT_F	= 606,
    SETP_GT_F1	= 607,
    SETP_GT_F1_NP	= 608,
    SETP_GT_F_I	= 609,
    SETP_GT_F_NP	= 610,
    SETP_GT_F_NPI	= 611,
    SETP_GT_I	= 612,
    SETP_GT_NP	= 613,
    SETP_GT_NPI	= 614,
    SETP_GT_U	= 615,
    SETP_GT_U_I	= 616,
    SETP_GT_U_NP	= 617,
    SETP_GT_U_NPI	= 618,
    SETP_LE	= 619,
    SETP_LE_F	= 620,
    SETP_LE_F1	= 621,
    SETP_LE_F1_NP	= 622,
    SETP_LE_F_I	= 623,
    SETP_LE_F_NP	= 624,
    SETP_LE_F_NPI	= 625,
    SETP_LE_I	= 626,
    SETP_LE_NP	= 627,
    SETP_LE_NPI	= 628,
    SETP_LE_U	= 629,
    SETP_LE_U_I	= 630,
    SETP_LE_U_NP	= 631,
    SETP_LE_U_NPI	= 632,
    SETP_LT	= 633,
    SETP_LT_F	= 634,
    SETP_LT_F1	= 635,
    SETP_LT_F1_NP	= 636,
    SETP_LT_F_I	= 637,
    SETP_LT_F_NP	= 638,
    SETP_LT_F_NPI	= 639,
    SETP_LT_I	= 640,
    SETP_LT_NP	= 641,
    SETP_LT_NPI	= 642,
    SETP_LT_U	= 643,
    SETP_LT_U_I	= 644,
    SETP_LT_U_NP	= 645,
    SETP_LT_U_NPI	= 646,
    SETP_NE	= 647,
    SETP_NE_F	= 648,
    SETP_NE_F1	= 649,
    SETP_NE_F1_NP	= 650,
    SETP_NE_F_I	= 651,
    SETP_NE_F_NP	= 652,
    SETP_NE_F_NPI	= 653,
    SETP_NE_I	= 654,
    SETP_NE_NP	= 655,
    SETP_NE_NPI	= 656,
    SHFL_IDX	= 657,
    SHL	= 658,
    SHLI	= 659,
    SHLI_P	= 660,
    SHL_P	= 661,
    SHR	= 662,
    SHRI	= 663,
    SHRI_P	= 664,
    SHR_P	= 665,
    SIN_F32	= 666,
    SQRT_F32	= 667,
    SRA	= 668,
    SRAI	= 669,
    SRAI_P	= 670,
    SRA_P	= 671,
    SRD	= 672,
    ST_GLOBAL	= 673,
    ST_GLOBAL_IDX	= 674,
    ST_GLOBAL_IDX_W16	= 675,
    ST_GLOBAL_IDX_W8	= 676,
    ST_GLOBAL_SLOT	= 677,
    ST_GLOBAL_SLOT_W16	= 678,
    ST_GLOBAL_SLOT_W8	= 679,
    ST_GLOBAL_W16	= 680,
    ST_GLOBAL_W8	= 681,
    ST_LOCAL	= 682,
    ST_PRED_G	= 683,
    ST_PRED_LOCAL	= 684,
    ST_PRED_S	= 685,
    ST_SHARED	= 686,
    ST_SHARED_IDX	= 687,
    ST_SHARED_W16	= 688,
    ST_SHARED_W8	= 689,
    SUB	= 690,
    SUBI	= 691,
    SUBI_P	= 692,
    SUB_P	= 693,
    SUB_W16	= 694,
    UNBALLOT	= 695,
    UNPACKI	= 696,
    VOTE_ANY	= 697,
    XOR	= 698,
    XORI	= 699,
    XORI_P	= 700,
    XOR_P	= 701,
    XOR_W16	= 702,
    INSTRUCTION_LIST_END = 703
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
  MCInstrDesc Insts[703];
  static_assert(alignof(MCInstrDesc) >= alignof(MCOperandInfo), "Unwanted padding between Insts and OperandInfo");
  MCOperandInfo OperandInfo[344];
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
    { 702,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #702 = XOR_W16
    { 701,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #701 = XOR_P
    { 700,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #700 = XORI_P
    { 699,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #699 = XORI
    { 698,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #698 = XOR
    { 697,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	341,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #697 = VOTE_ANY
    { 696,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #696 = UNPACKI
    { 695,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	338,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #695 = UNBALLOT
    { 694,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #694 = SUB_W16
    { 693,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #693 = SUB_P
    { 692,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #692 = SUBI_P
    { 691,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #691 = SUBI
    { 690,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #690 = SUB
    { 689,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #689 = ST_SHARED_W8
    { 688,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	294,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #688 = ST_SHARED_W16
    { 687,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #687 = ST_SHARED_IDX
    { 686,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #686 = ST_SHARED
    { 685,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	300,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #685 = ST_PRED_S
    { 684,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	303,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #684 = ST_PRED_LOCAL
    { 683,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	300,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #683 = ST_PRED_G
    { 682,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #682 = ST_LOCAL
    { 681,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #681 = ST_GLOBAL_W8
    { 680,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	294,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #680 = ST_GLOBAL_W16
    { 679,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	289,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #679 = ST_GLOBAL_SLOT_W8
    { 678,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	284,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #678 = ST_GLOBAL_SLOT_W16
    { 677,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #677 = ST_GLOBAL_SLOT
    { 676,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #676 = ST_GLOBAL_IDX_W8
    { 675,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #675 = ST_GLOBAL_IDX_W16
    { 674,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #674 = ST_GLOBAL_IDX
    { 673,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #673 = ST_GLOBAL
    { 672,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #672 = SRD
    { 671,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #671 = SRA_P
    { 670,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #670 = SRAI_P
    { 669,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #669 = SRAI
    { 668,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #668 = SRA
    { 667,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #667 = SQRT_F32
    { 666,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #666 = SIN_F32
    { 665,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #665 = SHR_P
    { 664,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #664 = SHRI_P
    { 663,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #663 = SHRI
    { 662,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #662 = SHR
    { 661,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #661 = SHL_P
    { 660,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #660 = SHLI_P
    { 659,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #659 = SHLI
    { 658,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #658 = SHL
    { 657,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #657 = SHFL_IDX
    { 656,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #656 = SETP_NE_NPI
    { 655,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #655 = SETP_NE_NP
    { 654,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #654 = SETP_NE_I
    { 653,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #653 = SETP_NE_F_NPI
    { 652,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #652 = SETP_NE_F_NP
    { 651,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #651 = SETP_NE_F_I
    { 650,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #650 = SETP_NE_F1_NP
    { 649,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #649 = SETP_NE_F1
    { 648,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #648 = SETP_NE_F
    { 647,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #647 = SETP_NE
    { 646,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #646 = SETP_LT_U_NPI
    { 645,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #645 = SETP_LT_U_NP
    { 644,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #644 = SETP_LT_U_I
    { 643,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #643 = SETP_LT_U
    { 642,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #642 = SETP_LT_NPI
    { 641,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #641 = SETP_LT_NP
    { 640,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #640 = SETP_LT_I
    { 639,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #639 = SETP_LT_F_NPI
    { 638,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #638 = SETP_LT_F_NP
    { 637,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #637 = SETP_LT_F_I
    { 636,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #636 = SETP_LT_F1_NP
    { 635,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #635 = SETP_LT_F1
    { 634,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #634 = SETP_LT_F
    { 633,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #633 = SETP_LT
    { 632,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #632 = SETP_LE_U_NPI
    { 631,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #631 = SETP_LE_U_NP
    { 630,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #630 = SETP_LE_U_I
    { 629,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #629 = SETP_LE_U
    { 628,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #628 = SETP_LE_NPI
    { 627,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #627 = SETP_LE_NP
    { 626,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #626 = SETP_LE_I
    { 625,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #625 = SETP_LE_F_NPI
    { 624,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #624 = SETP_LE_F_NP
    { 623,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #623 = SETP_LE_F_I
    { 622,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #622 = SETP_LE_F1_NP
    { 621,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #621 = SETP_LE_F1
    { 620,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #620 = SETP_LE_F
    { 619,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #619 = SETP_LE
    { 618,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #618 = SETP_GT_U_NPI
    { 617,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #617 = SETP_GT_U_NP
    { 616,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #616 = SETP_GT_U_I
    { 615,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #615 = SETP_GT_U
    { 614,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #614 = SETP_GT_NPI
    { 613,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #613 = SETP_GT_NP
    { 612,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #612 = SETP_GT_I
    { 611,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #611 = SETP_GT_F_NPI
    { 610,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #610 = SETP_GT_F_NP
    { 609,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #609 = SETP_GT_F_I
    { 608,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #608 = SETP_GT_F1_NP
    { 607,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #607 = SETP_GT_F1
    { 606,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #606 = SETP_GT_F
    { 605,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #605 = SETP_GT
    { 604,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #604 = SETP_GE_U_NPI
    { 603,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #603 = SETP_GE_U_NP
    { 602,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #602 = SETP_GE_U_I
    { 601,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #601 = SETP_GE_U
    { 600,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #600 = SETP_GE_NPI
    { 599,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #599 = SETP_GE_NP
    { 598,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #598 = SETP_GE_I
    { 597,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #597 = SETP_GE_F_NPI
    { 596,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #596 = SETP_GE_F_NP
    { 595,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #595 = SETP_GE_F_I
    { 594,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #594 = SETP_GE_F1_NP
    { 593,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #593 = SETP_GE_F1
    { 592,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #592 = SETP_GE_F
    { 591,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #591 = SETP_GE
    { 590,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #590 = SETP_EQ_NPI
    { 589,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #589 = SETP_EQ_NP
    { 588,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #588 = SETP_EQ_I
    { 587,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #587 = SETP_EQ_F_NPI
    { 586,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #586 = SETP_EQ_F_NP
    { 585,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #585 = SETP_EQ_F_I
    { 584,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #584 = SETP_EQ_F1_NP
    { 583,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #583 = SETP_EQ_F1
    { 582,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #582 = SETP_EQ_F
    { 581,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	320,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #581 = SETP_EQ
    { 580,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #580 = SEL
    { 579,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #579 = RSQRT_F32
    { 578,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #578 = RCP_U32
    { 577,	5,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #577 = RCP_F32_P
    { 576,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #576 = RCP_F32
    { 575,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	315,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #575 = PXOR
    { 574,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	315,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #574 = POR
    { 573,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #573 = POPC
    { 572,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	318,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #572 = PMOV_IMM
    { 571,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	315,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #571 = PMOV
    { 570,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	315,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #570 = PAND
    { 569,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #569 = PACKI_Z
    { 568,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #568 = PACKI
    { 567,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #567 = OR_W16
    { 566,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #566 = OR_P
    { 565,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #565 = ORI_P
    { 564,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #564 = ORI
    { 563,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #563 = OR
    { 562,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #562 = NEG
    { 561,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #561 = MUL_LO
    { 560,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #560 = MUL_HI_U_P
    { 559,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #559 = MUL_HI_U
    { 558,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #558 = MUL_HI_S_P
    { 557,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #557 = MUL_HI_S
    { 556,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #556 = MULI_P
    { 555,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #555 = MULI
    { 554,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	305,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #554 = MOV_P
    { 553,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #553 = MOVI48
    { 552,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #552 = MOVI
    { 551,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #551 = MIN_U_P
    { 550,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #550 = MIN_U
    { 549,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #549 = MIN_S_W16
    { 548,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #548 = MIN_S_P
    { 547,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #547 = MIN_S
    { 546,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #546 = MAX_U_P
    { 545,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #545 = MAX_U
    { 544,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	201,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #544 = MAX_S_W16
    { 543,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #543 = MAX_S_P
    { 542,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #542 = MAX_S
    { 541,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	256,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #541 = MAD_ACC
    { 540,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #540 = MADLO_P
    { 539,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #539 = MADLO
    { 538,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #538 = LG2_F32
    { 537,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #537 = LD_SHARED_W8
    { 536,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	294,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #536 = LD_SHARED_W16
    { 535,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #535 = LD_SHARED_IDX
    { 534,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #534 = LD_SHARED
    { 533,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	300,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #533 = LD_PRED_S
    { 532,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	303,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #532 = LD_PRED_LOCAL
    { 531,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	300,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #531 = LD_PRED_G
    { 530,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #530 = LD_LOCAL
    { 529,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	297,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #529 = LD_GLOBAL_W8
    { 528,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	294,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #528 = LD_GLOBAL_W16
    { 527,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	289,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #527 = LD_GLOBAL_SLOT_W8
    { 526,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	284,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #526 = LD_GLOBAL_SLOT_W16
    { 525,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #525 = LD_GLOBAL_SLOT
    { 524,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	178,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #524 = LD_GLOBAL_P
    { 523,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #523 = LD_GLOBAL_IDX_W8
    { 522,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #522 = LD_GLOBAL_IDX_W16
    { 521,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #521 = LD_GLOBAL_IDX
    { 520,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #520 = LD_GLOBAL
    { 519,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #519 = FSUB_W8
    { 518,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #518 = FSUB_P
    { 517,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #517 = FSUB_F1_W8
    { 516,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #516 = FSUB_F1
    { 515,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #515 = FSUB
    { 514,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #514 = FNEG_F1
    { 513,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #513 = FNEG_F0
    { 512,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #512 = FMUL_W8
    { 511,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #511 = FMUL_P
    { 510,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #510 = FMUL_F1_W8
    { 509,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #509 = FMUL_F1
    { 508,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #508 = FMUL
    { 507,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #507 = FMIN_F1
    { 506,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #506 = FMIN
    { 505,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #505 = FMAX_F1
    { 504,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #504 = FMAX
    { 503,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #503 = FFMA_F1
    { 502,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #502 = FFMA_F0
    { 501,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	256,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #501 = FFMA_ACC_F1
    { 500,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	256,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #500 = FFMA_ACC_F0
    { 499,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #499 = FADD_W8
    { 498,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #498 = FADD_P
    { 497,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #497 = FADD_F1_W8
    { 496,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #496 = FADD_F1
    { 495,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #495 = FADD
    { 494,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #494 = FABS_F1
    { 493,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #493 = FABS_F0
    { 492,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #492 = EX2_F32
    { 491,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #491 = DP4_SS
    { 490,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #490 = DP4_E5M2
    { 489,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #489 = DP4_E4M3
    { 488,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	256,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #488 = DP4_ACC
    { 487,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #487 = DP2_F16
    { 486,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #486 = DP2_BF16
    { 485,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #485 = C_XORI
    { 484,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #484 = C_XOR
    { 483,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #483 = C_SUBI
    { 482,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #482 = C_SUB
    { 481,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #481 = C_ST_GLOBAL
    { 480,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #480 = C_SRAI
    { 479,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #479 = C_SRA
    { 478,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #478 = C_SHRI
    { 477,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #477 = C_SHR
    { 476,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #476 = C_SHLI
    { 475,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #475 = C_SHL
    { 474,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #474 = C_RET
    { 473,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #473 = C_RECONV
    { 472,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #472 = C_ORI
    { 471,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #471 = C_OR
    { 470,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #470 = C_NOT
    { 469,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #469 = C_NEG
    { 468,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #468 = C_MUL_LO
    { 467,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #467 = C_MOV
    { 466,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #466 = C_MIN_U
    { 465,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #465 = C_MIN_S
    { 464,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #464 = C_MAX_U
    { 463,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #463 = C_MAX_S
    { 462,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #462 = C_LD_GLOBAL
    { 461,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #461 = C_FMUL
    { 460,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #460 = C_FMIN
    { 459,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #459 = C_FMAX
    { 458,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #458 = C_FENCE
    { 457,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #457 = C_FADD
    { 456,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #456 = C_EXIT
    { 455,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #455 = C_CHWIDTH
    { 454,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #454 = C_BRA
    { 453,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #453 = C_BAR_WAIT
    { 452,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #452 = C_BAR_ARRIVE
    { 451,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #451 = C_ANDN
    { 450,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #450 = C_ANDI
    { 449,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #449 = C_AND
    { 448,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	253,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #448 = C_ADDI
    { 447,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #447 = C_ADD
    { 446,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #446 = C_ABS
    { 445,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #445 = CVT_U32_F32_P
    { 444,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #444 = CVT_U32_F32
    { 443,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	238,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #443 = CVT_SEXT
    { 442,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #442 = CVT_S32_F32_P
    { 441,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #441 = CVT_S32_F32
    { 440,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #440 = CVT_F32_U32_P
    { 439,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #439 = CVT_F32_U32
    { 438,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #438 = CVT_F32_S32_P
    { 437,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #437 = CVT_F32_S32
    { 436,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #436 = CVT_D3_S3_R0_P
    { 435,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #435 = CVT_D3_S3_R0
    { 434,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #434 = CVT_D3_S2_R0_P
    { 433,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #433 = CVT_D3_S2_R0
    { 432,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #432 = CVT_D3_S1_R3_P
    { 431,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #431 = CVT_D3_S1_R3
    { 430,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #430 = CVT_D3_S1_R2_P
    { 429,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #429 = CVT_D3_S1_R2
    { 428,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #428 = CVT_D3_S1_R1_P
    { 427,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #427 = CVT_D3_S1_R1
    { 426,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #426 = CVT_D3_S1_R0_P
    { 425,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #425 = CVT_D3_S1_R0
    { 424,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #424 = CVT_D3_S0_R3_P
    { 423,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #423 = CVT_D3_S0_R3
    { 422,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #422 = CVT_D3_S0_R2_P
    { 421,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #421 = CVT_D3_S0_R2
    { 420,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #420 = CVT_D3_S0_R0_P
    { 419,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #419 = CVT_D3_S0_R0
    { 418,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #418 = CVT_D2_S3_R0_P
    { 417,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #417 = CVT_D2_S3_R0
    { 416,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #416 = CVT_D2_S1_R3_P
    { 415,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #415 = CVT_D2_S1_R3
    { 414,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #414 = CVT_D2_S1_R2_P
    { 413,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #413 = CVT_D2_S1_R2
    { 412,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #412 = CVT_D2_S1_R1_P
    { 411,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #411 = CVT_D2_S1_R1
    { 410,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #410 = CVT_D2_S1_R0_P
    { 409,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #409 = CVT_D2_S1_R0
    { 408,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #408 = CVT_D2_S0_R3_P
    { 407,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #407 = CVT_D2_S0_R3
    { 406,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #406 = CVT_D2_S0_R2_P
    { 405,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #405 = CVT_D2_S0_R2
    { 404,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #404 = CVT_D2_S0_R0_P
    { 403,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #403 = CVT_D2_S0_R0
    { 402,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #402 = CVT_D1_S3_R3_P
    { 401,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #401 = CVT_D1_S3_R3
    { 400,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #400 = CVT_D1_S3_R2_P
    { 399,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #399 = CVT_D1_S3_R2
    { 398,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #398 = CVT_D1_S3_R1_P
    { 397,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #397 = CVT_D1_S3_R1
    { 396,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #396 = CVT_D1_S3_R0_P
    { 395,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #395 = CVT_D1_S3_R0
    { 394,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #394 = CVT_D1_S2_R3_P
    { 393,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #393 = CVT_D1_S2_R3
    { 392,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #392 = CVT_D1_S2_R2_P
    { 391,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #391 = CVT_D1_S2_R2
    { 390,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #390 = CVT_D1_S2_R1_P
    { 389,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #389 = CVT_D1_S2_R1
    { 388,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #388 = CVT_D1_S2_R0_P
    { 387,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #387 = CVT_D1_S2_R0
    { 386,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #386 = CVT_D1_S1_R3_P
    { 385,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #385 = CVT_D1_S1_R3
    { 384,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #384 = CVT_D1_S1_R2_P
    { 383,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #383 = CVT_D1_S1_R2
    { 382,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #382 = CVT_D1_S1_R1_P
    { 381,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #381 = CVT_D1_S1_R1
    { 380,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #380 = CVT_D1_S1_R0_P
    { 379,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #379 = CVT_D1_S1_R0
    { 378,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #378 = CVT_D1_S0_R3_P
    { 377,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #377 = CVT_D1_S0_R3
    { 376,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #376 = CVT_D1_S0_R2_P
    { 375,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #375 = CVT_D1_S0_R2
    { 374,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #374 = CVT_D1_S0_R1_P
    { 373,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #373 = CVT_D1_S0_R1
    { 372,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #372 = CVT_D1_S0_R0_W8_32
    { 371,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #371 = CVT_D1_S0_R0_P
    { 370,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #370 = CVT_D1_S0_R0
    { 369,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #369 = CVT_D0_S3_R3_P
    { 368,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #368 = CVT_D0_S3_R3
    { 367,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #367 = CVT_D0_S3_R2_P
    { 366,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #366 = CVT_D0_S3_R2
    { 365,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #365 = CVT_D0_S3_R1_P
    { 364,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #364 = CVT_D0_S3_R1
    { 363,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #363 = CVT_D0_S2_R3_P
    { 362,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #362 = CVT_D0_S2_R3
    { 361,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #361 = CVT_D0_S2_R2_P
    { 360,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #360 = CVT_D0_S2_R2
    { 359,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #359 = CVT_D0_S2_R1_P
    { 358,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #358 = CVT_D0_S2_R1
    { 357,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #357 = CVT_D0_S1_R3_P
    { 356,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #356 = CVT_D0_S1_R3
    { 355,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #355 = CVT_D0_S1_R2_P
    { 354,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #354 = CVT_D0_S1_R2
    { 353,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #353 = CVT_D0_S1_R1_P
    { 352,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #352 = CVT_D0_S1_R1
    { 351,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #351 = CVT_D0_S1_R0_W32_8
    { 350,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	234,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #350 = CVT_D0_S1_R0_W16_8
    { 349,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #349 = CVT_D0_S1_R0_P
    { 348,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #348 = CVT_D0_S1_R0
    { 347,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #347 = CVT_D0_S0_R3_P
    { 346,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #346 = CVT_D0_S0_R3
    { 345,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #345 = CVT_D0_S0_R2_P
    { 344,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #344 = CVT_D0_S0_R2
    { 343,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #343 = CVT_D0_S0_R1_P
    { 342,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #342 = CVT_D0_S0_R1
    { 341,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #341 = CVT_D0_S0_R0_W8_32
    { 340,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #340 = CVT_D0_S0_R0_W32_8
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
    /* 242 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 246 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 250 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 253 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 256 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 260 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 264 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 269 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 274 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 279 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 284 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 289 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 294 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 297 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 300 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 303 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 305 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 311 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 315 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 318 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 320 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 325 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 329 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 334 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 338 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 341 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
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
  /* 1247 */ "FSUB_F1_W8\0"
  /* 1258 */ "FADD_F1_W8\0"
  /* 1269 */ "FMUL_F1_W8\0"
  /* 1280 */ "FSUB_W8\0"
  /* 1288 */ "FADD_W8\0"
  /* 1296 */ "LD_SHARED_W8\0"
  /* 1309 */ "ST_SHARED_W8\0"
  /* 1322 */ "LD_GLOBAL_W8\0"
  /* 1335 */ "ST_GLOBAL_W8\0"
  /* 1348 */ "FMUL_W8\0"
  /* 1356 */ "LD_GLOBAL_SLOT_W8\0"
  /* 1374 */ "ST_GLOBAL_SLOT_W8\0"
  /* 1392 */ "LD_GLOBAL_IDX_W8\0"
  /* 1409 */ "ST_GLOBAL_IDX_W8\0"
  /* 1426 */ "CVT_D0_S0_R0_W32_8\0"
  /* 1445 */ "CVT_D0_S1_R0_W32_8\0"
  /* 1464 */ "CVT_D0_S0_R0_W16_8\0"
  /* 1483 */ "CVT_D0_S1_R0_W16_8\0"
  /* 1502 */ "G_FMA\0"
  /* 1508 */ "G_STRICT_FMA\0"
  /* 1521 */ "C_BRA\0"
  /* 1527 */ "C_SRA\0"
  /* 1533 */ "G_FSUB\0"
  /* 1540 */ "G_STRICT_FSUB\0"
  /* 1554 */ "G_ATOMICRMW_FSUB\0"
  /* 1571 */ "C_SUB\0"
  /* 1577 */ "G_SUB\0"
  /* 1583 */ "G_ATOMICRMW_SUB\0"
  /* 1599 */ "DP4_ACC\0"
  /* 1607 */ "MAD_ACC\0"
  /* 1615 */ "G_INTRINSIC\0"
  /* 1627 */ "G_FPTRUNC\0"
  /* 1637 */ "G_INTRINSIC_TRUNC\0"
  /* 1655 */ "G_TRUNC\0"
  /* 1663 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 1684 */ "G_DYN_STACKALLOC\0"
  /* 1701 */ "POPC\0"
  /* 1706 */ "G_FMAD\0"
  /* 1713 */ "G_INDEXED_SEXTLOAD\0"
  /* 1732 */ "G_SEXTLOAD\0"
  /* 1743 */ "G_INDEXED_ZEXTLOAD\0"
  /* 1762 */ "G_ZEXTLOAD\0"
  /* 1773 */ "G_INDEXED_LOAD\0"
  /* 1788 */ "G_LOAD\0"
  /* 1795 */ "C_FADD\0"
  /* 1802 */ "G_VECREDUCE_FADD\0"
  /* 1819 */ "G_FADD\0"
  /* 1826 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 1847 */ "G_STRICT_FADD\0"
  /* 1861 */ "G_ATOMICRMW_FADD\0"
  /* 1878 */ "C_ADD\0"
  /* 1884 */ "G_VECREDUCE_ADD\0"
  /* 1900 */ "G_ADD\0"
  /* 1906 */ "G_PTR_ADD\0"
  /* 1916 */ "G_ATOMICRMW_ADD\0"
  /* 1932 */ "LD_SHARED\0"
  /* 1942 */ "ST_SHARED\0"
  /* 1952 */ "PSEUDO_BRA_PRED\0"
  /* 1968 */ "PSEUDO_LD_PRED\0"
  /* 1983 */ "PSEUDO_ST_PRED\0"
  /* 1998 */ "G_ATOMICRMW_NAND\0"
  /* 2015 */ "PSEUDO_PAND\0"
  /* 2027 */ "C_AND\0"
  /* 2033 */ "G_VECREDUCE_AND\0"
  /* 2049 */ "G_AND\0"
  /* 2055 */ "G_ATOMICRMW_AND\0"
  /* 2071 */ "LIFETIME_END\0"
  /* 2084 */ "G_BRCOND\0"
  /* 2093 */ "G_LLROUND\0"
  /* 2103 */ "G_LROUND\0"
  /* 2112 */ "G_INTRINSIC_ROUND\0"
  /* 2130 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 2156 */ "LOAD_STACK_GUARD\0"
  /* 2173 */ "SRD\0"
  /* 2177 */ "PSEUDO_PROBE\0"
  /* 2190 */ "G_SSUBE\0"
  /* 2198 */ "G_USUBE\0"
  /* 2206 */ "C_FENCE\0"
  /* 2214 */ "G_FENCE\0"
  /* 2222 */ "ARITH_FENCE\0"
  /* 2234 */ "REG_SEQUENCE\0"
  /* 2247 */ "G_SADDE\0"
  /* 2255 */ "G_UADDE\0"
  /* 2263 */ "G_GET_FPMODE\0"
  /* 2276 */ "G_RESET_FPMODE\0"
  /* 2291 */ "G_SET_FPMODE\0"
  /* 2304 */ "G_FMINNUM_IEEE\0"
  /* 2319 */ "G_FMAXNUM_IEEE\0"
  /* 2334 */ "SETP_GE\0"
  /* 2342 */ "G_JUMP_TABLE\0"
  /* 2355 */ "BUNDLE\0"
  /* 2362 */ "SETP_LE\0"
  /* 2370 */ "G_MEMCPY_INLINE\0"
  /* 2386 */ "SETP_NE\0"
  /* 2394 */ "LOCAL_ESCAPE\0"
  /* 2407 */ "G_STACKRESTORE\0"
  /* 2422 */ "G_INDEXED_STORE\0"
  /* 2438 */ "G_STORE\0"
  /* 2446 */ "BAR_WAIT_PHASE\0"
  /* 2461 */ "G_BITREVERSE\0"
  /* 2474 */ "DBG_VALUE\0"
  /* 2484 */ "G_GLOBAL_VALUE\0"
  /* 2499 */ "G_STACKSAVE\0"
  /* 2511 */ "C_BAR_ARRIVE\0"
  /* 2524 */ "G_MEMMOVE\0"
  /* 2534 */ "G_FREEZE\0"
  /* 2543 */ "G_FCANONICALIZE\0"
  /* 2559 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 2577 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 2595 */ "G_IMPLICIT_DEF\0"
  /* 2610 */ "DBG_INSTR_REF\0"
  /* 2624 */ "SETP_GE_F\0"
  /* 2634 */ "SETP_LE_F\0"
  /* 2644 */ "SETP_NE_F\0"
  /* 2654 */ "SETP_EQ_F\0"
  /* 2664 */ "SETP_GT_F\0"
  /* 2674 */ "SETP_LT_F\0"
  /* 2684 */ "G_FNEG\0"
  /* 2691 */ "C_NEG\0"
  /* 2697 */ "EXTRACT_SUBREG\0"
  /* 2712 */ "INSERT_SUBREG\0"
  /* 2726 */ "G_SEXT_INREG\0"
  /* 2739 */ "SUBREG_TO_REG\0"
  /* 2753 */ "G_ATOMIC_CMPXCHG\0"
  /* 2770 */ "G_ATOMICRMW_XCHG\0"
  /* 2787 */ "G_FLOG\0"
  /* 2794 */ "G_VAARG\0"
  /* 2802 */ "PREALLOCATED_ARG\0"
  /* 2819 */ "ATOM_ADD_G\0"
  /* 2830 */ "LD_PRED_G\0"
  /* 2840 */ "ST_PRED_G\0"
  /* 2850 */ "ATOM_AND_G\0"
  /* 2861 */ "ATOM_EXCH_G\0"
  /* 2873 */ "ATOM_XOR_G\0"
  /* 2884 */ "ATOM_OR_G\0"
  /* 2894 */ "PSEUDO_CAS_G\0"
  /* 2907 */ "ATOM_MIN_S_G\0"
  /* 2920 */ "ATOM_MAX_S_G\0"
  /* 2933 */ "ATOM_MIN_U_G\0"
  /* 2946 */ "ATOM_MAX_U_G\0"
  /* 2959 */ "G_PREFETCH\0"
  /* 2970 */ "G_SMULH\0"
  /* 2978 */ "G_UMULH\0"
  /* 2986 */ "C_CHWIDTH\0"
  /* 2996 */ "C_SRAI\0"
  /* 3003 */ "C_SUBI\0"
  /* 3010 */ "PSEUDO_PADDI\0"
  /* 3023 */ "C_ADDI\0"
  /* 3030 */ "C_ANDI\0"
  /* 3037 */ "DBG_PHI\0"
  /* 3045 */ "UNPACKI\0"
  /* 3053 */ "C_SHLI\0"
  /* 3060 */ "MULI\0"
  /* 3065 */ "ANDNI\0"
  /* 3071 */ "SETP_GE_NPI\0"
  /* 3083 */ "SETP_LE_NPI\0"
  /* 3095 */ "SETP_NE_NPI\0"
  /* 3107 */ "SETP_GE_F_NPI\0"
  /* 3121 */ "SETP_LE_F_NPI\0"
  /* 3135 */ "SETP_NE_F_NPI\0"
  /* 3149 */ "SETP_EQ_F_NPI\0"
  /* 3163 */ "SETP_GT_F_NPI\0"
  /* 3177 */ "SETP_LT_F_NPI\0"
  /* 3191 */ "SETP_EQ_NPI\0"
  /* 3203 */ "SETP_GT_NPI\0"
  /* 3215 */ "SETP_LT_NPI\0"
  /* 3227 */ "SETP_GE_U_NPI\0"
  /* 3241 */ "SETP_LE_U_NPI\0"
  /* 3255 */ "SETP_GT_U_NPI\0"
  /* 3269 */ "SETP_LT_U_NPI\0"
  /* 3283 */ "C_SHRI\0"
  /* 3290 */ "C_XORI\0"
  /* 3297 */ "C_ORI\0"
  /* 3303 */ "G_FPTOSI\0"
  /* 3312 */ "CHWIDTH_MULTI\0"
  /* 3326 */ "G_FPTOUI\0"
  /* 3335 */ "MOVI\0"
  /* 3340 */ "G_FPOWI\0"
  /* 3348 */ "SETP_GE_I\0"
  /* 3358 */ "SETP_LE_I\0"
  /* 3368 */ "SETP_NE_I\0"
  /* 3378 */ "SETP_GE_F_I\0"
  /* 3390 */ "SETP_LE_F_I\0"
  /* 3402 */ "SETP_NE_F_I\0"
  /* 3414 */ "SETP_EQ_F_I\0"
  /* 3426 */ "SETP_GT_F_I\0"
  /* 3438 */ "SETP_LT_F_I\0"
  /* 3450 */ "SETP_EQ_I\0"
  /* 3460 */ "SETP_GT_I\0"
  /* 3470 */ "SETP_LT_I\0"
  /* 3480 */ "SETP_GE_U_I\0"
  /* 3492 */ "SETP_LE_U_I\0"
  /* 3504 */ "SETP_GT_U_I\0"
  /* 3516 */ "SETP_LT_U_I\0"
  /* 3528 */ "G_PTRMASK\0"
  /* 3538 */ "C_LD_GLOBAL\0"
  /* 3550 */ "C_ST_GLOBAL\0"
  /* 3562 */ "LD_PRED_LOCAL\0"
  /* 3576 */ "ST_PRED_LOCAL\0"
  /* 3590 */ "LD_LOCAL\0"
  /* 3599 */ "ST_LOCAL\0"
  /* 3608 */ "GC_LABEL\0"
  /* 3617 */ "DBG_LABEL\0"
  /* 3627 */ "EH_LABEL\0"
  /* 3636 */ "ANNOTATION_LABEL\0"
  /* 3653 */ "ICALL_BRANCH_FUNNEL\0"
  /* 3673 */ "SEL\0"
  /* 3677 */ "G_FSHL\0"
  /* 3684 */ "C_SHL\0"
  /* 3690 */ "G_SHL\0"
  /* 3696 */ "G_FCEIL\0"
  /* 3704 */ "PATCHABLE_TAIL_CALL\0"
  /* 3724 */ "PSEUDO_CALL\0"
  /* 3736 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 3763 */ "PATCHABLE_EVENT_CALL\0"
  /* 3784 */ "FENTRY_CALL\0"
  /* 3796 */ "KILL\0"
  /* 3801 */ "G_CONSTANT_POOL\0"
  /* 3817 */ "G_ROTL\0"
  /* 3824 */ "C_FMUL\0"
  /* 3831 */ "G_VECREDUCE_FMUL\0"
  /* 3848 */ "G_FMUL\0"
  /* 3855 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 3876 */ "G_STRICT_FMUL\0"
  /* 3890 */ "G_VECREDUCE_MUL\0"
  /* 3906 */ "G_MUL\0"
  /* 3912 */ "G_FREM\0"
  /* 3919 */ "G_STRICT_FREM\0"
  /* 3933 */ "G_SREM\0"
  /* 3940 */ "G_UREM\0"
  /* 3947 */ "G_SDIVREM\0"
  /* 3957 */ "G_UDIVREM\0"
  /* 3967 */ "PMOV_IMM\0"
  /* 3976 */ "INLINEASM\0"
  /* 3986 */ "G_VECREDUCE_FMINIMUM\0"
  /* 4007 */ "G_FMINIMUM\0"
  /* 4018 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 4039 */ "G_FMAXIMUM\0"
  /* 4050 */ "G_FMINNUM\0"
  /* 4060 */ "G_FMAXNUM\0"
  /* 4070 */ "C_ANDN\0"
  /* 4077 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 4099 */ "G_ASSERT_ALIGN\0"
  /* 4114 */ "G_FCOPYSIGN\0"
  /* 4126 */ "C_FMIN\0"
  /* 4133 */ "G_VECREDUCE_FMIN\0"
  /* 4150 */ "G_ATOMICRMW_FMIN\0"
  /* 4167 */ "G_VECREDUCE_SMIN\0"
  /* 4184 */ "G_SMIN\0"
  /* 4191 */ "G_VECREDUCE_UMIN\0"
  /* 4208 */ "G_UMIN\0"
  /* 4215 */ "G_ATOMICRMW_UMIN\0"
  /* 4232 */ "G_ATOMICRMW_MIN\0"
  /* 4248 */ "G_FSIN\0"
  /* 4255 */ "CFI_INSTRUCTION\0"
  /* 4271 */ "ADJCALLSTACKDOWN\0"
  /* 4288 */ "G_SSUBO\0"
  /* 4296 */ "G_USUBO\0"
  /* 4304 */ "G_SADDO\0"
  /* 4312 */ "G_UADDO\0"
  /* 4320 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 4342 */ "MADLO\0"
  /* 4348 */ "G_SMULO\0"
  /* 4356 */ "G_UMULO\0"
  /* 4364 */ "C_MUL_LO\0"
  /* 4373 */ "G_BZERO\0"
  /* 4381 */ "STACKMAP\0"
  /* 4390 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 4412 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 4434 */ "G_BSWAP\0"
  /* 4442 */ "G_SITOFP\0"
  /* 4451 */ "G_UITOFP\0"
  /* 4460 */ "G_FCMP\0"
  /* 4467 */ "G_ICMP\0"
  /* 4474 */ "SETP_GE_F1_NP\0"
  /* 4488 */ "SETP_LE_F1_NP\0"
  /* 4502 */ "SETP_NE_F1_NP\0"
  /* 4516 */ "SETP_EQ_F1_NP\0"
  /* 4530 */ "SETP_GT_F1_NP\0"
  /* 4544 */ "SETP_LT_F1_NP\0"
  /* 4558 */ "SETP_GE_NP\0"
  /* 4569 */ "SETP_LE_NP\0"
  /* 4580 */ "SETP_NE_NP\0"
  /* 4591 */ "SETP_GE_F_NP\0"
  /* 4604 */ "SETP_LE_F_NP\0"
  /* 4617 */ "SETP_NE_F_NP\0"
  /* 4630 */ "SETP_EQ_F_NP\0"
  /* 4643 */ "SETP_GT_F_NP\0"
  /* 4656 */ "SETP_LT_F_NP\0"
  /* 4669 */ "SETP_EQ_NP\0"
  /* 4680 */ "SETP_GT_NP\0"
  /* 4691 */ "SETP_LT_NP\0"
  /* 4702 */ "SETP_GE_U_NP\0"
  /* 4715 */ "SETP_LE_U_NP\0"
  /* 4728 */ "SETP_GT_U_NP\0"
  /* 4741 */ "SETP_LT_U_NP\0"
  /* 4754 */ "G_CTPOP\0"
  /* 4762 */ "PATCHABLE_OP\0"
  /* 4775 */ "FAULTING_OP\0"
  /* 4787 */ "ADD_PP\0"
  /* 4794 */ "ADDI_PP\0"
  /* 4802 */ "ADJCALLSTACKUP\0"
  /* 4817 */ "PREALLOCATED_SETUP\0"
  /* 4836 */ "G_FLDEXP\0"
  /* 4845 */ "G_STRICT_FLDEXP\0"
  /* 4861 */ "G_FEXP\0"
  /* 4868 */ "G_FFREXP\0"
  /* 4877 */ "CVT_D0_S0_R0_P\0"
  /* 4892 */ "CVT_D1_S0_R0_P\0"
  /* 4907 */ "CVT_D2_S0_R0_P\0"
  /* 4922 */ "CVT_D3_S0_R0_P\0"
  /* 4937 */ "CVT_D0_S1_R0_P\0"
  /* 4952 */ "CVT_D1_S1_R0_P\0"
  /* 4967 */ "CVT_D2_S1_R0_P\0"
  /* 4982 */ "CVT_D3_S1_R0_P\0"
  /* 4997 */ "CVT_D1_S2_R0_P\0"
  /* 5012 */ "CVT_D3_S2_R0_P\0"
  /* 5027 */ "CVT_D1_S3_R0_P\0"
  /* 5042 */ "CVT_D2_S3_R0_P\0"
  /* 5057 */ "CVT_D3_S3_R0_P\0"
  /* 5072 */ "CVT_D0_S0_R1_P\0"
  /* 5087 */ "CVT_D1_S0_R1_P\0"
  /* 5102 */ "CVT_D0_S1_R1_P\0"
  /* 5117 */ "CVT_D1_S1_R1_P\0"
  /* 5132 */ "CVT_D2_S1_R1_P\0"
  /* 5147 */ "CVT_D3_S1_R1_P\0"
  /* 5162 */ "CVT_D0_S2_R1_P\0"
  /* 5177 */ "CVT_D1_S2_R1_P\0"
  /* 5192 */ "CVT_D0_S3_R1_P\0"
  /* 5207 */ "CVT_D1_S3_R1_P\0"
  /* 5222 */ "CVT_S32_F32_P\0"
  /* 5236 */ "CVT_U32_F32_P\0"
  /* 5250 */ "RCP_F32_P\0"
  /* 5260 */ "CVT_F32_S32_P\0"
  /* 5274 */ "CVT_F32_U32_P\0"
  /* 5288 */ "CVT_D0_S0_R2_P\0"
  /* 5303 */ "CVT_D1_S0_R2_P\0"
  /* 5318 */ "CVT_D2_S0_R2_P\0"
  /* 5333 */ "CVT_D3_S0_R2_P\0"
  /* 5348 */ "CVT_D0_S1_R2_P\0"
  /* 5363 */ "CVT_D1_S1_R2_P\0"
  /* 5378 */ "CVT_D2_S1_R2_P\0"
  /* 5393 */ "CVT_D3_S1_R2_P\0"
  /* 5408 */ "CVT_D0_S2_R2_P\0"
  /* 5423 */ "CVT_D1_S2_R2_P\0"
  /* 5438 */ "CVT_D0_S3_R2_P\0"
  /* 5453 */ "CVT_D1_S3_R2_P\0"
  /* 5468 */ "CVT_D0_S0_R3_P\0"
  /* 5483 */ "CVT_D1_S0_R3_P\0"
  /* 5498 */ "CVT_D2_S0_R3_P\0"
  /* 5513 */ "CVT_D3_S0_R3_P\0"
  /* 5528 */ "CVT_D0_S1_R3_P\0"
  /* 5543 */ "CVT_D1_S1_R3_P\0"
  /* 5558 */ "CVT_D2_S1_R3_P\0"
  /* 5573 */ "CVT_D3_S1_R3_P\0"
  /* 5588 */ "CVT_D0_S2_R3_P\0"
  /* 5603 */ "CVT_D1_S2_R3_P\0"
  /* 5618 */ "CVT_D0_S3_R3_P\0"
  /* 5633 */ "CVT_D1_S3_R3_P\0"
  /* 5648 */ "SRA_P\0"
  /* 5654 */ "FSUB_P\0"
  /* 5661 */ "FADD_P\0"
  /* 5668 */ "AND_P\0"
  /* 5674 */ "SRAI_P\0"
  /* 5681 */ "SUBI_P\0"
  /* 5688 */ "ADDI_P\0"
  /* 5695 */ "ANDI_P\0"
  /* 5702 */ "SHLI_P\0"
  /* 5709 */ "MULI_P\0"
  /* 5716 */ "ANDNI_P\0"
  /* 5724 */ "SHRI_P\0"
  /* 5731 */ "XORI_P\0"
  /* 5738 */ "LD_GLOBAL_P\0"
  /* 5750 */ "SHL_P\0"
  /* 5756 */ "FMUL_P\0"
  /* 5763 */ "MADLO_P\0"
  /* 5771 */ "SHR_P\0"
  /* 5777 */ "XOR_P\0"
  /* 5783 */ "MUL_HI_S_P\0"
  /* 5794 */ "MIN_S_P\0"
  /* 5802 */ "MAX_S_P\0"
  /* 5810 */ "MUL_HI_U_P\0"
  /* 5821 */ "MIN_U_P\0"
  /* 5829 */ "MAX_U_P\0"
  /* 5837 */ "MOV_P\0"
  /* 5843 */ "SETP_EQ\0"
  /* 5851 */ "G_BR\0"
  /* 5856 */ "INLINEASM_BR\0"
  /* 5869 */ "G_BLOCK_ADDR\0"
  /* 5882 */ "MEMBARRIER\0"
  /* 5893 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 5917 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 5942 */ "G_READCYCLECOUNTER\0"
  /* 5961 */ "G_READ_REGISTER\0"
  /* 5977 */ "G_WRITE_REGISTER\0"
  /* 5994 */ "G_ASHR\0"
  /* 6001 */ "G_FSHR\0"
  /* 6008 */ "G_LSHR\0"
  /* 6015 */ "C_SHR\0"
  /* 6021 */ "G_FFLOOR\0"
  /* 6030 */ "PSEUDO_POR\0"
  /* 6041 */ "G_BUILD_VECTOR\0"
  /* 6056 */ "G_SHUFFLE_VECTOR\0"
  /* 6073 */ "PSEUDO_PXOR\0"
  /* 6085 */ "C_XOR\0"
  /* 6091 */ "G_VECREDUCE_XOR\0"
  /* 6107 */ "G_XOR\0"
  /* 6113 */ "G_ATOMICRMW_XOR\0"
  /* 6129 */ "C_OR\0"
  /* 6134 */ "G_VECREDUCE_OR\0"
  /* 6149 */ "G_OR\0"
  /* 6154 */ "G_ATOMICRMW_OR\0"
  /* 6169 */ "G_ROTR\0"
  /* 6176 */ "G_INTTOPTR\0"
  /* 6187 */ "G_FABS\0"
  /* 6194 */ "C_ABS\0"
  /* 6200 */ "G_ABS\0"
  /* 6206 */ "G_UNMERGE_VALUES\0"
  /* 6223 */ "G_MERGE_VALUES\0"
  /* 6238 */ "G_FCOS\0"
  /* 6245 */ "G_CONCAT_VECTORS\0"
  /* 6262 */ "COPY_TO_REGCLASS\0"
  /* 6279 */ "G_IS_FPCLASS\0"
  /* 6292 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 6322 */ "DP4_SS\0"
  /* 6329 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 6356 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 6394 */ "ATOM_ADD_S\0"
  /* 6405 */ "LD_PRED_S\0"
  /* 6415 */ "ST_PRED_S\0"
  /* 6425 */ "ATOM_AND_S\0"
  /* 6436 */ "ATOM_EXCH_S\0"
  /* 6448 */ "MUL_HI_S\0"
  /* 6457 */ "C_MIN_S\0"
  /* 6465 */ "ATOM_XOR_S\0"
  /* 6476 */ "ATOM_OR_S\0"
  /* 6486 */ "PSEUDO_CAS_S\0"
  /* 6499 */ "ATOM_MIN_S_S\0"
  /* 6512 */ "ATOM_MAX_S_S\0"
  /* 6525 */ "ATOM_MIN_U_S\0"
  /* 6538 */ "ATOM_MAX_U_S\0"
  /* 6551 */ "C_MAX_S\0"
  /* 6559 */ "G_SSUBSAT\0"
  /* 6569 */ "G_USUBSAT\0"
  /* 6579 */ "G_SADDSAT\0"
  /* 6589 */ "G_UADDSAT\0"
  /* 6599 */ "G_SSHLSAT\0"
  /* 6609 */ "G_USHLSAT\0"
  /* 6619 */ "G_SMULFIXSAT\0"
  /* 6632 */ "G_UMULFIXSAT\0"
  /* 6645 */ "G_SDIVFIXSAT\0"
  /* 6658 */ "G_UDIVFIXSAT\0"
  /* 6671 */ "G_EXTRACT\0"
  /* 6681 */ "G_SELECT\0"
  /* 6690 */ "G_BRINDIRECT\0"
  /* 6703 */ "C_RET\0"
  /* 6709 */ "PATCHABLE_RET\0"
  /* 6723 */ "PSEUDO_RET\0"
  /* 6734 */ "G_MEMSET\0"
  /* 6743 */ "SETP_GT\0"
  /* 6751 */ "C_BAR_WAIT\0"
  /* 6762 */ "BAR_INIT\0"
  /* 6771 */ "C_EXIT\0"
  /* 6778 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 6802 */ "G_BRJT\0"
  /* 6809 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 6830 */ "G_INSERT_VECTOR_ELT\0"
  /* 6850 */ "SETP_LT\0"
  /* 6858 */ "G_FCONSTANT\0"
  /* 6870 */ "G_CONSTANT\0"
  /* 6881 */ "G_INTRINSIC_CONVERGENT\0"
  /* 6904 */ "STATEPOINT\0"
  /* 6915 */ "PATCHPOINT\0"
  /* 6926 */ "G_PTRTOINT\0"
  /* 6937 */ "G_FRINT\0"
  /* 6945 */ "G_INTRINSIC_LRINT\0"
  /* 6963 */ "G_FNEARBYINT\0"
  /* 6976 */ "UNBALLOT\0"
  /* 6985 */ "LD_GLOBAL_SLOT\0"
  /* 7000 */ "ST_GLOBAL_SLOT\0"
  /* 7015 */ "C_NOT\0"
  /* 7021 */ "G_VASTART\0"
  /* 7031 */ "LIFETIME_START\0"
  /* 7046 */ "G_INVOKE_REGION_START\0"
  /* 7068 */ "G_INSERT\0"
  /* 7077 */ "G_FSQRT\0"
  /* 7085 */ "G_STRICT_FSQRT\0"
  /* 7100 */ "PSEUDO_BCAST\0"
  /* 7113 */ "G_BITCAST\0"
  /* 7123 */ "G_ADDRSPACE_CAST\0"
  /* 7140 */ "DBG_VALUE_LIST\0"
  /* 7155 */ "G_FPEXT\0"
  /* 7163 */ "G_SEXT\0"
  /* 7170 */ "G_ASSERT_SEXT\0"
  /* 7184 */ "CVT_SEXT\0"
  /* 7193 */ "G_ANYEXT\0"
  /* 7202 */ "G_ZEXT\0"
  /* 7209 */ "G_ASSERT_ZEXT\0"
  /* 7223 */ "SETP_GE_U\0"
  /* 7233 */ "SETP_LE_U\0"
  /* 7243 */ "MUL_HI_U\0"
  /* 7252 */ "C_MIN_U\0"
  /* 7260 */ "SETP_GT_U\0"
  /* 7270 */ "SETP_LT_U\0"
  /* 7280 */ "C_MAX_U\0"
  /* 7288 */ "BREV\0"
  /* 7293 */ "G_FDIV\0"
  /* 7300 */ "G_STRICT_FDIV\0"
  /* 7314 */ "G_SDIV\0"
  /* 7321 */ "G_UDIV\0"
  /* 7328 */ "G_GET_FPENV\0"
  /* 7340 */ "G_RESET_FPENV\0"
  /* 7354 */ "G_SET_FPENV\0"
  /* 7366 */ "C_RECONV\0"
  /* 7375 */ "PSEUDO_PMOV\0"
  /* 7387 */ "C_MOV\0"
  /* 7393 */ "G_FPOW\0"
  /* 7400 */ "PSEUDO_NARROW\0"
  /* 7414 */ "C_FMAX\0"
  /* 7421 */ "G_VECREDUCE_FMAX\0"
  /* 7438 */ "G_ATOMICRMW_FMAX\0"
  /* 7455 */ "G_VECREDUCE_SMAX\0"
  /* 7472 */ "G_SMAX\0"
  /* 7479 */ "G_VECREDUCE_UMAX\0"
  /* 7496 */ "G_UMAX\0"
  /* 7503 */ "G_ATOMICRMW_UMAX\0"
  /* 7520 */ "G_ATOMICRMW_MAX\0"
  /* 7536 */ "LD_SHARED_IDX\0"
  /* 7550 */ "ST_SHARED_IDX\0"
  /* 7564 */ "LD_GLOBAL_IDX\0"
  /* 7578 */ "ST_GLOBAL_IDX\0"
  /* 7592 */ "SHFL_IDX\0"
  /* 7601 */ "G_FRAME_INDEX\0"
  /* 7615 */ "G_SBFX\0"
  /* 7622 */ "G_UBFX\0"
  /* 7629 */ "G_SMULFIX\0"
  /* 7639 */ "G_UMULFIX\0"
  /* 7649 */ "G_SDIVFIX\0"
  /* 7659 */ "G_UDIVFIX\0"
  /* 7669 */ "VOTE_ANY\0"
  /* 7678 */ "G_MEMCPY\0"
  /* 7687 */ "COPY\0"
  /* 7692 */ "CLZ\0"
  /* 7696 */ "G_CTLZ\0"
  /* 7703 */ "G_CTTZ\0"
  /* 7710 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    3041U, 3976U, 5856U, 4255U, 3627U, 3608U, 3636U, 3796U, 
    2697U, 2712U, 2597U, 2739U, 6262U, 2474U, 7140U, 2610U, 
    3037U, 3617U, 2234U, 7687U, 2355U, 7031U, 2071U, 2177U, 
    2222U, 4381U, 3784U, 6915U, 2156U, 4817U, 2802U, 6904U, 
    2394U, 4775U, 4762U, 5917U, 6709U, 6778U, 3704U, 3763U, 
    3736U, 3653U, 5882U, 4320U, 7170U, 7209U, 4099U, 1900U, 
    1577U, 3906U, 7314U, 7321U, 3933U, 3940U, 3947U, 3957U, 
    2049U, 6149U, 6107U, 2595U, 3039U, 7601U, 2484U, 3801U, 
    6671U, 6206U, 7068U, 6223U, 6041U, 1663U, 6245U, 6926U, 
    6176U, 7113U, 2534U, 5893U, 2130U, 1637U, 2112U, 6945U, 
    4077U, 5942U, 1788U, 1732U, 1762U, 1773U, 1713U, 1743U, 
    2438U, 2422U, 6292U, 2753U, 2770U, 1916U, 1583U, 2055U, 
    1998U, 6154U, 6113U, 7520U, 4232U, 7503U, 4215U, 1861U, 
    1554U, 7438U, 4150U, 4412U, 4390U, 2214U, 2959U, 2084U, 
    6690U, 7046U, 1615U, 6329U, 6881U, 6356U, 7193U, 1655U, 
    6870U, 6858U, 7021U, 2794U, 7163U, 2726U, 7202U, 3690U, 
    6008U, 5994U, 3677U, 6001U, 6169U, 3817U, 4467U, 4460U, 
    6681U, 4312U, 2255U, 4296U, 2198U, 4304U, 2247U, 4288U, 
    2190U, 4356U, 4348U, 2978U, 2970U, 6589U, 6579U, 6569U, 
    6559U, 6609U, 6599U, 7629U, 7639U, 6619U, 6632U, 7649U, 
    7659U, 6645U, 6658U, 1819U, 1533U, 3848U, 1502U, 1706U, 
    7293U, 3912U, 7393U, 3340U, 4861U, 676U, 9U, 2787U, 
    659U, 0U, 4836U, 4868U, 2684U, 7155U, 1627U, 3303U, 
    3326U, 4442U, 4451U, 6187U, 4114U, 6279U, 2543U, 4050U, 
    4060U, 2304U, 2319U, 4007U, 4039U, 7328U, 7354U, 7340U, 
    2263U, 2291U, 2276U, 1906U, 3528U, 4184U, 7472U, 4208U, 
    7496U, 6200U, 2103U, 2093U, 5851U, 6802U, 6830U, 6809U, 
    6056U, 7703U, 2577U, 7696U, 2559U, 4754U, 4434U, 2461U, 
    3696U, 6238U, 4248U, 7077U, 6021U, 6937U, 6963U, 7123U, 
    5869U, 2342U, 1684U, 2499U, 2407U, 1847U, 1540U, 3876U, 
    7300U, 3919U, 1508U, 7085U, 4845U, 5961U, 5977U, 7678U, 
    2370U, 2524U, 6734U, 4373U, 1826U, 3855U, 1802U, 3831U, 
    7421U, 4133U, 4018U, 3986U, 1884U, 3890U, 2033U, 6134U, 
    6091U, 7455U, 4167U, 7479U, 4191U, 7615U, 7622U, 4271U, 
    4802U, 7100U, 1952U, 3724U, 2894U, 6486U, 1968U, 7400U, 
    3010U, 2015U, 7375U, 6030U, 6073U, 6723U, 1983U, 6190U, 
    1798U, 3018U, 1233U, 5688U, 4794U, 1074U, 5662U, 4787U, 
    1030U, 2011U, 3032U, 5695U, 4072U, 3065U, 5716U, 5668U, 
    1066U, 2819U, 6394U, 2850U, 6425U, 2861U, 6436U, 2920U, 
    6512U, 2946U, 6538U, 2907U, 6499U, 2933U, 6525U, 2884U, 
    6476U, 2873U, 6465U, 6978U, 6762U, 2446U, 1523U, 1959U, 
    7288U, 3719U, 2901U, 6493U, 3312U, 7692U, 551U, 54U, 
    4877U, 601U, 1464U, 1213U, 1426U, 621U, 365U, 5072U, 
    684U, 5288U, 849U, 5468U, 106U, 4937U, 1483U, 1445U, 
    391U, 5102U, 736U, 5348U, 901U, 5528U, 443U, 5162U, 
    788U, 5408U, 953U, 5588U, 469U, 5192U, 814U, 5438U, 
    979U, 5618U, 67U, 4892U, 640U, 378U, 5087U, 697U, 
    5303U, 862U, 5483U, 119U, 4952U, 404U, 5117U, 749U, 
    5363U, 914U, 5543U, 158U, 4997U, 456U, 5177U, 801U, 
    5423U, 966U, 5603U, 184U, 5027U, 482U, 5207U, 827U, 
    5453U, 992U, 5633U, 80U, 4907U, 710U, 5318U, 875U, 
    5498U, 132U, 4967U, 417U, 5132U, 762U, 5378U, 927U, 
    5558U, 197U, 5042U, 93U, 4922U, 723U, 5333U, 888U, 
    5513U, 145U, 4982U, 430U, 5147U, 775U, 5393U, 940U, 
    5573U, 171U, 5012U, 210U, 5057U, 569U, 5260U, 581U, 
    5274U, 495U, 5222U, 7184U, 507U, 5236U, 6194U, 1878U, 
    3023U, 2027U, 3030U, 4070U, 2511U, 6751U, 1521U, 2986U, 
    6771U, 1795U, 2206U, 7414U, 4126U, 3824U, 3538U, 6551U, 
    7280U, 6457U, 7252U, 7387U, 4364U, 2691U, 7015U, 6129U, 
    3297U, 7366U, 6703U, 3684U, 3053U, 6015U, 3283U, 1527U, 
    2996U, 3550U, 1571U, 3003U, 6085U, 3290U, 1005U, 1014U, 
    1599U, 840U, 667U, 6322U, 527U, 46U, 327U, 1797U, 
    251U, 1258U, 5661U, 1288U, 26U, 239U, 18U, 223U, 
    7416U, 357U, 4128U, 308U, 3826U, 300U, 1269U, 5756U, 
    1348U, 38U, 292U, 1535U, 231U, 1247U, 5654U, 1280U, 
    3540U, 7564U, 1177U, 1392U, 5738U, 6985U, 1139U, 1356U, 
    1083U, 1322U, 3590U, 2830U, 3562U, 6405U, 1932U, 7536U, 
    1038U, 1296U, 519U, 4342U, 5763U, 1607U, 6553U, 5802U, 
    1129U, 7282U, 5829U, 6459U, 5794U, 1119U, 7254U, 5821U, 
    3335U, 1240U, 5837U, 3060U, 5709U, 6448U, 5783U, 7243U, 
    5810U, 4366U, 2687U, 6027U, 3293U, 5732U, 5778U, 1112U, 
    3047U, 7710U, 2022U, 7382U, 3967U, 1701U, 6037U, 6080U, 
    543U, 5250U, 593U, 559U, 3673U, 5843U, 2654U, 316U, 
    4516U, 3414U, 4630U, 3149U, 3450U, 4669U, 3191U, 2334U, 
    2624U, 259U, 4474U, 3378U, 4591U, 3107U, 3348U, 4558U, 
    3071U, 7223U, 3480U, 4702U, 3227U, 6743U, 2664U, 335U, 
    4530U, 3426U, 4643U, 3163U, 3460U, 4680U, 3203U, 7260U, 
    3504U, 4728U, 3255U, 2362U, 2634U, 270U, 4488U, 3390U, 
    4604U, 3121U, 3358U, 4569U, 3083U, 7233U, 3492U, 4715U, 
    3241U, 6850U, 2674U, 346U, 4544U, 3438U, 4656U, 3177U, 
    3470U, 4691U, 3215U, 7270U, 3516U, 4741U, 3269U, 2386U, 
    2644U, 281U, 4502U, 3402U, 4617U, 3135U, 3368U, 4580U, 
    3095U, 7592U, 3680U, 3055U, 5702U, 5750U, 5997U, 3285U, 
    5724U, 5771U, 535U, 560U, 1529U, 2998U, 5674U, 5648U, 
    2173U, 3552U, 7578U, 1195U, 1409U, 7000U, 1158U, 1374U, 
    1097U, 1335U, 3599U, 2840U, 3576U, 6415U, 1942U, 7550U, 
    1052U, 1309U, 1536U, 3005U, 5681U, 5655U, 1022U, 6976U, 
    3045U, 7669U, 6081U, 3292U, 5731U, 5777U, 1111U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 703);
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
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 703);
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
  GPR8 = 52,
  GPR16 = 53,
  PR = 54,
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
    /* CVT_D0_S0_R0_W32_8 */
    965,
    /* CVT_D0_S0_R0_W8_32 */
    969,
    /* CVT_D0_S0_R1 */
    973,
    /* CVT_D0_S0_R1_P */
    977,
    /* CVT_D0_S0_R2 */
    982,
    /* CVT_D0_S0_R2_P */
    986,
    /* CVT_D0_S0_R3 */
    991,
    /* CVT_D0_S0_R3_P */
    995,
    /* CVT_D0_S1_R0 */
    1000,
    /* CVT_D0_S1_R0_P */
    1004,
    /* CVT_D0_S1_R0_W16_8 */
    1009,
    /* CVT_D0_S1_R0_W32_8 */
    1013,
    /* CVT_D0_S1_R1 */
    1017,
    /* CVT_D0_S1_R1_P */
    1021,
    /* CVT_D0_S1_R2 */
    1026,
    /* CVT_D0_S1_R2_P */
    1030,
    /* CVT_D0_S1_R3 */
    1035,
    /* CVT_D0_S1_R3_P */
    1039,
    /* CVT_D0_S2_R1 */
    1044,
    /* CVT_D0_S2_R1_P */
    1048,
    /* CVT_D0_S2_R2 */
    1053,
    /* CVT_D0_S2_R2_P */
    1057,
    /* CVT_D0_S2_R3 */
    1062,
    /* CVT_D0_S2_R3_P */
    1066,
    /* CVT_D0_S3_R1 */
    1071,
    /* CVT_D0_S3_R1_P */
    1075,
    /* CVT_D0_S3_R2 */
    1080,
    /* CVT_D0_S3_R2_P */
    1084,
    /* CVT_D0_S3_R3 */
    1089,
    /* CVT_D0_S3_R3_P */
    1093,
    /* CVT_D1_S0_R0 */
    1098,
    /* CVT_D1_S0_R0_P */
    1102,
    /* CVT_D1_S0_R0_W8_32 */
    1107,
    /* CVT_D1_S0_R1 */
    1111,
    /* CVT_D1_S0_R1_P */
    1115,
    /* CVT_D1_S0_R2 */
    1120,
    /* CVT_D1_S0_R2_P */
    1124,
    /* CVT_D1_S0_R3 */
    1129,
    /* CVT_D1_S0_R3_P */
    1133,
    /* CVT_D1_S1_R0 */
    1138,
    /* CVT_D1_S1_R0_P */
    1142,
    /* CVT_D1_S1_R1 */
    1147,
    /* CVT_D1_S1_R1_P */
    1151,
    /* CVT_D1_S1_R2 */
    1156,
    /* CVT_D1_S1_R2_P */
    1160,
    /* CVT_D1_S1_R3 */
    1165,
    /* CVT_D1_S1_R3_P */
    1169,
    /* CVT_D1_S2_R0 */
    1174,
    /* CVT_D1_S2_R0_P */
    1178,
    /* CVT_D1_S2_R1 */
    1183,
    /* CVT_D1_S2_R1_P */
    1187,
    /* CVT_D1_S2_R2 */
    1192,
    /* CVT_D1_S2_R2_P */
    1196,
    /* CVT_D1_S2_R3 */
    1201,
    /* CVT_D1_S2_R3_P */
    1205,
    /* CVT_D1_S3_R0 */
    1210,
    /* CVT_D1_S3_R0_P */
    1214,
    /* CVT_D1_S3_R1 */
    1219,
    /* CVT_D1_S3_R1_P */
    1223,
    /* CVT_D1_S3_R2 */
    1228,
    /* CVT_D1_S3_R2_P */
    1232,
    /* CVT_D1_S3_R3 */
    1237,
    /* CVT_D1_S3_R3_P */
    1241,
    /* CVT_D2_S0_R0 */
    1246,
    /* CVT_D2_S0_R0_P */
    1250,
    /* CVT_D2_S0_R2 */
    1255,
    /* CVT_D2_S0_R2_P */
    1259,
    /* CVT_D2_S0_R3 */
    1264,
    /* CVT_D2_S0_R3_P */
    1268,
    /* CVT_D2_S1_R0 */
    1273,
    /* CVT_D2_S1_R0_P */
    1277,
    /* CVT_D2_S1_R1 */
    1282,
    /* CVT_D2_S1_R1_P */
    1286,
    /* CVT_D2_S1_R2 */
    1291,
    /* CVT_D2_S1_R2_P */
    1295,
    /* CVT_D2_S1_R3 */
    1300,
    /* CVT_D2_S1_R3_P */
    1304,
    /* CVT_D2_S3_R0 */
    1309,
    /* CVT_D2_S3_R0_P */
    1313,
    /* CVT_D3_S0_R0 */
    1318,
    /* CVT_D3_S0_R0_P */
    1322,
    /* CVT_D3_S0_R2 */
    1327,
    /* CVT_D3_S0_R2_P */
    1331,
    /* CVT_D3_S0_R3 */
    1336,
    /* CVT_D3_S0_R3_P */
    1340,
    /* CVT_D3_S1_R0 */
    1345,
    /* CVT_D3_S1_R0_P */
    1349,
    /* CVT_D3_S1_R1 */
    1354,
    /* CVT_D3_S1_R1_P */
    1358,
    /* CVT_D3_S1_R2 */
    1363,
    /* CVT_D3_S1_R2_P */
    1367,
    /* CVT_D3_S1_R3 */
    1372,
    /* CVT_D3_S1_R3_P */
    1376,
    /* CVT_D3_S2_R0 */
    1381,
    /* CVT_D3_S2_R0_P */
    1385,
    /* CVT_D3_S3_R0 */
    1390,
    /* CVT_D3_S3_R0_P */
    1394,
    /* CVT_F32_S32 */
    1399,
    /* CVT_F32_S32_P */
    1403,
    /* CVT_F32_U32 */
    1408,
    /* CVT_F32_U32_P */
    1412,
    /* CVT_S32_F32 */
    1417,
    /* CVT_S32_F32_P */
    1421,
    /* CVT_SEXT */
    1426,
    /* CVT_U32_F32 */
    1430,
    /* CVT_U32_F32_P */
    1434,
    /* C_ABS */
    1439,
    /* C_ADD */
    1441,
    /* C_ADDI */
    1444,
    /* C_AND */
    1447,
    /* C_ANDI */
    1450,
    /* C_ANDN */
    1453,
    /* C_BAR_ARRIVE */
    1456,
    /* C_BAR_WAIT */
    1457,
    /* C_BRA */
    1458,
    /* C_CHWIDTH */
    1459,
    /* C_EXIT */
    1461,
    /* C_FADD */
    1462,
    /* C_FENCE */
    1465,
    /* C_FMAX */
    1466,
    /* C_FMIN */
    1469,
    /* C_FMUL */
    1472,
    /* C_LD_GLOBAL */
    1475,
    /* C_MAX_S */
    1477,
    /* C_MAX_U */
    1480,
    /* C_MIN_S */
    1483,
    /* C_MIN_U */
    1486,
    /* C_MOV */
    1489,
    /* C_MUL_LO */
    1491,
    /* C_NEG */
    1494,
    /* C_NOT */
    1496,
    /* C_OR */
    1498,
    /* C_ORI */
    1501,
    /* C_RECONV */
    1504,
    /* C_RET */
    1505,
    /* C_SHL */
    1506,
    /* C_SHLI */
    1509,
    /* C_SHR */
    1512,
    /* C_SHRI */
    1515,
    /* C_SRA */
    1518,
    /* C_SRAI */
    1521,
    /* C_ST_GLOBAL */
    1524,
    /* C_SUB */
    1526,
    /* C_SUBI */
    1529,
    /* C_XOR */
    1532,
    /* C_XORI */
    1535,
    /* DP2_BF16 */
    1538,
    /* DP2_F16 */
    1542,
    /* DP4_ACC */
    1546,
    /* DP4_E4M3 */
    1550,
    /* DP4_E5M2 */
    1554,
    /* DP4_SS */
    1558,
    /* EX2_F32 */
    1562,
    /* FABS_F0 */
    1566,
    /* FABS_F1 */
    1570,
    /* FADD */
    1574,
    /* FADD_F1 */
    1578,
    /* FADD_F1_W8 */
    1582,
    /* FADD_P */
    1586,
    /* FADD_W8 */
    1591,
    /* FFMA_ACC_F0 */
    1595,
    /* FFMA_ACC_F1 */
    1599,
    /* FFMA_F0 */
    1603,
    /* FFMA_F1 */
    1607,
    /* FMAX */
    1611,
    /* FMAX_F1 */
    1615,
    /* FMIN */
    1619,
    /* FMIN_F1 */
    1623,
    /* FMUL */
    1627,
    /* FMUL_F1 */
    1631,
    /* FMUL_F1_W8 */
    1635,
    /* FMUL_P */
    1639,
    /* FMUL_W8 */
    1644,
    /* FNEG_F0 */
    1648,
    /* FNEG_F1 */
    1652,
    /* FSUB */
    1656,
    /* FSUB_F1 */
    1660,
    /* FSUB_F1_W8 */
    1664,
    /* FSUB_P */
    1668,
    /* FSUB_W8 */
    1673,
    /* LD_GLOBAL */
    1677,
    /* LD_GLOBAL_IDX */
    1680,
    /* LD_GLOBAL_IDX_W16 */
    1685,
    /* LD_GLOBAL_IDX_W8 */
    1690,
    /* LD_GLOBAL_P */
    1695,
    /* LD_GLOBAL_SLOT */
    1699,
    /* LD_GLOBAL_SLOT_W16 */
    1704,
    /* LD_GLOBAL_SLOT_W8 */
    1709,
    /* LD_GLOBAL_W16 */
    1714,
    /* LD_GLOBAL_W8 */
    1717,
    /* LD_LOCAL */
    1720,
    /* LD_PRED_G */
    1722,
    /* LD_PRED_LOCAL */
    1725,
    /* LD_PRED_S */
    1727,
    /* LD_SHARED */
    1730,
    /* LD_SHARED_IDX */
    1733,
    /* LD_SHARED_W16 */
    1738,
    /* LD_SHARED_W8 */
    1741,
    /* LG2_F32 */
    1744,
    /* MADLO */
    1748,
    /* MADLO_P */
    1752,
    /* MAD_ACC */
    1757,
    /* MAX_S */
    1761,
    /* MAX_S_P */
    1765,
    /* MAX_S_W16 */
    1770,
    /* MAX_U */
    1774,
    /* MAX_U_P */
    1778,
    /* MIN_S */
    1783,
    /* MIN_S_P */
    1787,
    /* MIN_S_W16 */
    1792,
    /* MIN_U */
    1796,
    /* MIN_U_P */
    1800,
    /* MOVI */
    1805,
    /* MOVI48 */
    1807,
    /* MOV_P */
    1809,
    /* MULI */
    1815,
    /* MULI_P */
    1818,
    /* MUL_HI_S */
    1822,
    /* MUL_HI_S_P */
    1826,
    /* MUL_HI_U */
    1831,
    /* MUL_HI_U_P */
    1835,
    /* MUL_LO */
    1840,
    /* NEG */
    1844,
    /* OR */
    1848,
    /* ORI */
    1852,
    /* ORI_P */
    1855,
    /* OR_P */
    1859,
    /* OR_W16 */
    1864,
    /* PACKI */
    1868,
    /* PACKI_Z */
    1872,
    /* PAND */
    1875,
    /* PMOV */
    1878,
    /* PMOV_IMM */
    1881,
    /* POPC */
    1883,
    /* POR */
    1887,
    /* PXOR */
    1890,
    /* RCP_F32 */
    1893,
    /* RCP_F32_P */
    1897,
    /* RCP_U32 */
    1902,
    /* RSQRT_F32 */
    1906,
    /* SEL */
    1910,
    /* SETP_EQ */
    1915,
    /* SETP_EQ_F */
    1920,
    /* SETP_EQ_F1 */
    1925,
    /* SETP_EQ_F1_NP */
    1930,
    /* SETP_EQ_F_I */
    1934,
    /* SETP_EQ_F_NP */
    1939,
    /* SETP_EQ_F_NPI */
    1943,
    /* SETP_EQ_I */
    1947,
    /* SETP_EQ_NP */
    1952,
    /* SETP_EQ_NPI */
    1956,
    /* SETP_GE */
    1960,
    /* SETP_GE_F */
    1965,
    /* SETP_GE_F1 */
    1970,
    /* SETP_GE_F1_NP */
    1975,
    /* SETP_GE_F_I */
    1979,
    /* SETP_GE_F_NP */
    1984,
    /* SETP_GE_F_NPI */
    1988,
    /* SETP_GE_I */
    1992,
    /* SETP_GE_NP */
    1997,
    /* SETP_GE_NPI */
    2001,
    /* SETP_GE_U */
    2005,
    /* SETP_GE_U_I */
    2010,
    /* SETP_GE_U_NP */
    2015,
    /* SETP_GE_U_NPI */
    2019,
    /* SETP_GT */
    2023,
    /* SETP_GT_F */
    2028,
    /* SETP_GT_F1 */
    2033,
    /* SETP_GT_F1_NP */
    2038,
    /* SETP_GT_F_I */
    2042,
    /* SETP_GT_F_NP */
    2047,
    /* SETP_GT_F_NPI */
    2051,
    /* SETP_GT_I */
    2055,
    /* SETP_GT_NP */
    2060,
    /* SETP_GT_NPI */
    2064,
    /* SETP_GT_U */
    2068,
    /* SETP_GT_U_I */
    2073,
    /* SETP_GT_U_NP */
    2078,
    /* SETP_GT_U_NPI */
    2082,
    /* SETP_LE */
    2086,
    /* SETP_LE_F */
    2091,
    /* SETP_LE_F1 */
    2096,
    /* SETP_LE_F1_NP */
    2101,
    /* SETP_LE_F_I */
    2105,
    /* SETP_LE_F_NP */
    2110,
    /* SETP_LE_F_NPI */
    2114,
    /* SETP_LE_I */
    2118,
    /* SETP_LE_NP */
    2123,
    /* SETP_LE_NPI */
    2127,
    /* SETP_LE_U */
    2131,
    /* SETP_LE_U_I */
    2136,
    /* SETP_LE_U_NP */
    2141,
    /* SETP_LE_U_NPI */
    2145,
    /* SETP_LT */
    2149,
    /* SETP_LT_F */
    2154,
    /* SETP_LT_F1 */
    2159,
    /* SETP_LT_F1_NP */
    2164,
    /* SETP_LT_F_I */
    2168,
    /* SETP_LT_F_NP */
    2173,
    /* SETP_LT_F_NPI */
    2177,
    /* SETP_LT_I */
    2181,
    /* SETP_LT_NP */
    2186,
    /* SETP_LT_NPI */
    2190,
    /* SETP_LT_U */
    2194,
    /* SETP_LT_U_I */
    2199,
    /* SETP_LT_U_NP */
    2204,
    /* SETP_LT_U_NPI */
    2208,
    /* SETP_NE */
    2212,
    /* SETP_NE_F */
    2217,
    /* SETP_NE_F1 */
    2222,
    /* SETP_NE_F1_NP */
    2227,
    /* SETP_NE_F_I */
    2231,
    /* SETP_NE_F_NP */
    2236,
    /* SETP_NE_F_NPI */
    2240,
    /* SETP_NE_I */
    2244,
    /* SETP_NE_NP */
    2249,
    /* SETP_NE_NPI */
    2253,
    /* SHFL_IDX */
    2257,
    /* SHL */
    2261,
    /* SHLI */
    2265,
    /* SHLI_P */
    2268,
    /* SHL_P */
    2272,
    /* SHR */
    2277,
    /* SHRI */
    2281,
    /* SHRI_P */
    2284,
    /* SHR_P */
    2288,
    /* SIN_F32 */
    2293,
    /* SQRT_F32 */
    2297,
    /* SRA */
    2301,
    /* SRAI */
    2305,
    /* SRAI_P */
    2308,
    /* SRA_P */
    2312,
    /* SRD */
    2317,
    /* ST_GLOBAL */
    2319,
    /* ST_GLOBAL_IDX */
    2322,
    /* ST_GLOBAL_IDX_W16 */
    2327,
    /* ST_GLOBAL_IDX_W8 */
    2332,
    /* ST_GLOBAL_SLOT */
    2337,
    /* ST_GLOBAL_SLOT_W16 */
    2342,
    /* ST_GLOBAL_SLOT_W8 */
    2347,
    /* ST_GLOBAL_W16 */
    2352,
    /* ST_GLOBAL_W8 */
    2355,
    /* ST_LOCAL */
    2358,
    /* ST_PRED_G */
    2360,
    /* ST_PRED_LOCAL */
    2363,
    /* ST_PRED_S */
    2365,
    /* ST_SHARED */
    2368,
    /* ST_SHARED_IDX */
    2371,
    /* ST_SHARED_W16 */
    2376,
    /* ST_SHARED_W8 */
    2379,
    /* SUB */
    2382,
    /* SUBI */
    2386,
    /* SUBI_P */
    2389,
    /* SUB_P */
    2393,
    /* SUB_W16 */
    2398,
    /* UNBALLOT */
    2402,
    /* UNPACKI */
    2405,
    /* VOTE_ANY */
    2408,
    /* XOR */
    2411,
    /* XORI */
    2415,
    /* XORI_P */
    2418,
    /* XOR_P */
    2422,
    /* XOR_W16 */
    2427,
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
    CEFBS_None, // CVT_D0_S0_R0_W32_8 = 340
    CEFBS_None, // CVT_D0_S0_R0_W8_32 = 341
    CEFBS_None, // CVT_D0_S0_R1 = 342
    CEFBS_None, // CVT_D0_S0_R1_P = 343
    CEFBS_None, // CVT_D0_S0_R2 = 344
    CEFBS_None, // CVT_D0_S0_R2_P = 345
    CEFBS_None, // CVT_D0_S0_R3 = 346
    CEFBS_None, // CVT_D0_S0_R3_P = 347
    CEFBS_None, // CVT_D0_S1_R0 = 348
    CEFBS_None, // CVT_D0_S1_R0_P = 349
    CEFBS_None, // CVT_D0_S1_R0_W16_8 = 350
    CEFBS_None, // CVT_D0_S1_R0_W32_8 = 351
    CEFBS_None, // CVT_D0_S1_R1 = 352
    CEFBS_None, // CVT_D0_S1_R1_P = 353
    CEFBS_None, // CVT_D0_S1_R2 = 354
    CEFBS_None, // CVT_D0_S1_R2_P = 355
    CEFBS_None, // CVT_D0_S1_R3 = 356
    CEFBS_None, // CVT_D0_S1_R3_P = 357
    CEFBS_None, // CVT_D0_S2_R1 = 358
    CEFBS_None, // CVT_D0_S2_R1_P = 359
    CEFBS_None, // CVT_D0_S2_R2 = 360
    CEFBS_None, // CVT_D0_S2_R2_P = 361
    CEFBS_None, // CVT_D0_S2_R3 = 362
    CEFBS_None, // CVT_D0_S2_R3_P = 363
    CEFBS_None, // CVT_D0_S3_R1 = 364
    CEFBS_None, // CVT_D0_S3_R1_P = 365
    CEFBS_None, // CVT_D0_S3_R2 = 366
    CEFBS_None, // CVT_D0_S3_R2_P = 367
    CEFBS_None, // CVT_D0_S3_R3 = 368
    CEFBS_None, // CVT_D0_S3_R3_P = 369
    CEFBS_None, // CVT_D1_S0_R0 = 370
    CEFBS_None, // CVT_D1_S0_R0_P = 371
    CEFBS_None, // CVT_D1_S0_R0_W8_32 = 372
    CEFBS_None, // CVT_D1_S0_R1 = 373
    CEFBS_None, // CVT_D1_S0_R1_P = 374
    CEFBS_None, // CVT_D1_S0_R2 = 375
    CEFBS_None, // CVT_D1_S0_R2_P = 376
    CEFBS_None, // CVT_D1_S0_R3 = 377
    CEFBS_None, // CVT_D1_S0_R3_P = 378
    CEFBS_None, // CVT_D1_S1_R0 = 379
    CEFBS_None, // CVT_D1_S1_R0_P = 380
    CEFBS_None, // CVT_D1_S1_R1 = 381
    CEFBS_None, // CVT_D1_S1_R1_P = 382
    CEFBS_None, // CVT_D1_S1_R2 = 383
    CEFBS_None, // CVT_D1_S1_R2_P = 384
    CEFBS_None, // CVT_D1_S1_R3 = 385
    CEFBS_None, // CVT_D1_S1_R3_P = 386
    CEFBS_None, // CVT_D1_S2_R0 = 387
    CEFBS_None, // CVT_D1_S2_R0_P = 388
    CEFBS_None, // CVT_D1_S2_R1 = 389
    CEFBS_None, // CVT_D1_S2_R1_P = 390
    CEFBS_None, // CVT_D1_S2_R2 = 391
    CEFBS_None, // CVT_D1_S2_R2_P = 392
    CEFBS_None, // CVT_D1_S2_R3 = 393
    CEFBS_None, // CVT_D1_S2_R3_P = 394
    CEFBS_None, // CVT_D1_S3_R0 = 395
    CEFBS_None, // CVT_D1_S3_R0_P = 396
    CEFBS_None, // CVT_D1_S3_R1 = 397
    CEFBS_None, // CVT_D1_S3_R1_P = 398
    CEFBS_None, // CVT_D1_S3_R2 = 399
    CEFBS_None, // CVT_D1_S3_R2_P = 400
    CEFBS_None, // CVT_D1_S3_R3 = 401
    CEFBS_None, // CVT_D1_S3_R3_P = 402
    CEFBS_None, // CVT_D2_S0_R0 = 403
    CEFBS_None, // CVT_D2_S0_R0_P = 404
    CEFBS_None, // CVT_D2_S0_R2 = 405
    CEFBS_None, // CVT_D2_S0_R2_P = 406
    CEFBS_None, // CVT_D2_S0_R3 = 407
    CEFBS_None, // CVT_D2_S0_R3_P = 408
    CEFBS_None, // CVT_D2_S1_R0 = 409
    CEFBS_None, // CVT_D2_S1_R0_P = 410
    CEFBS_None, // CVT_D2_S1_R1 = 411
    CEFBS_None, // CVT_D2_S1_R1_P = 412
    CEFBS_None, // CVT_D2_S1_R2 = 413
    CEFBS_None, // CVT_D2_S1_R2_P = 414
    CEFBS_None, // CVT_D2_S1_R3 = 415
    CEFBS_None, // CVT_D2_S1_R3_P = 416
    CEFBS_None, // CVT_D2_S3_R0 = 417
    CEFBS_None, // CVT_D2_S3_R0_P = 418
    CEFBS_None, // CVT_D3_S0_R0 = 419
    CEFBS_None, // CVT_D3_S0_R0_P = 420
    CEFBS_None, // CVT_D3_S0_R2 = 421
    CEFBS_None, // CVT_D3_S0_R2_P = 422
    CEFBS_None, // CVT_D3_S0_R3 = 423
    CEFBS_None, // CVT_D3_S0_R3_P = 424
    CEFBS_None, // CVT_D3_S1_R0 = 425
    CEFBS_None, // CVT_D3_S1_R0_P = 426
    CEFBS_None, // CVT_D3_S1_R1 = 427
    CEFBS_None, // CVT_D3_S1_R1_P = 428
    CEFBS_None, // CVT_D3_S1_R2 = 429
    CEFBS_None, // CVT_D3_S1_R2_P = 430
    CEFBS_None, // CVT_D3_S1_R3 = 431
    CEFBS_None, // CVT_D3_S1_R3_P = 432
    CEFBS_None, // CVT_D3_S2_R0 = 433
    CEFBS_None, // CVT_D3_S2_R0_P = 434
    CEFBS_None, // CVT_D3_S3_R0 = 435
    CEFBS_None, // CVT_D3_S3_R0_P = 436
    CEFBS_None, // CVT_F32_S32 = 437
    CEFBS_None, // CVT_F32_S32_P = 438
    CEFBS_None, // CVT_F32_U32 = 439
    CEFBS_None, // CVT_F32_U32_P = 440
    CEFBS_None, // CVT_S32_F32 = 441
    CEFBS_None, // CVT_S32_F32_P = 442
    CEFBS_None, // CVT_SEXT = 443
    CEFBS_None, // CVT_U32_F32 = 444
    CEFBS_None, // CVT_U32_F32_P = 445
    CEFBS_None, // C_ABS = 446
    CEFBS_None, // C_ADD = 447
    CEFBS_None, // C_ADDI = 448
    CEFBS_None, // C_AND = 449
    CEFBS_None, // C_ANDI = 450
    CEFBS_None, // C_ANDN = 451
    CEFBS_None, // C_BAR_ARRIVE = 452
    CEFBS_None, // C_BAR_WAIT = 453
    CEFBS_None, // C_BRA = 454
    CEFBS_None, // C_CHWIDTH = 455
    CEFBS_None, // C_EXIT = 456
    CEFBS_None, // C_FADD = 457
    CEFBS_None, // C_FENCE = 458
    CEFBS_None, // C_FMAX = 459
    CEFBS_None, // C_FMIN = 460
    CEFBS_None, // C_FMUL = 461
    CEFBS_None, // C_LD_GLOBAL = 462
    CEFBS_None, // C_MAX_S = 463
    CEFBS_None, // C_MAX_U = 464
    CEFBS_None, // C_MIN_S = 465
    CEFBS_None, // C_MIN_U = 466
    CEFBS_None, // C_MOV = 467
    CEFBS_None, // C_MUL_LO = 468
    CEFBS_None, // C_NEG = 469
    CEFBS_None, // C_NOT = 470
    CEFBS_None, // C_OR = 471
    CEFBS_None, // C_ORI = 472
    CEFBS_None, // C_RECONV = 473
    CEFBS_None, // C_RET = 474
    CEFBS_None, // C_SHL = 475
    CEFBS_None, // C_SHLI = 476
    CEFBS_None, // C_SHR = 477
    CEFBS_None, // C_SHRI = 478
    CEFBS_None, // C_SRA = 479
    CEFBS_None, // C_SRAI = 480
    CEFBS_None, // C_ST_GLOBAL = 481
    CEFBS_None, // C_SUB = 482
    CEFBS_None, // C_SUBI = 483
    CEFBS_None, // C_XOR = 484
    CEFBS_None, // C_XORI = 485
    CEFBS_None, // DP2_BF16 = 486
    CEFBS_None, // DP2_F16 = 487
    CEFBS_None, // DP4_ACC = 488
    CEFBS_None, // DP4_E4M3 = 489
    CEFBS_None, // DP4_E5M2 = 490
    CEFBS_None, // DP4_SS = 491
    CEFBS_None, // EX2_F32 = 492
    CEFBS_None, // FABS_F0 = 493
    CEFBS_None, // FABS_F1 = 494
    CEFBS_None, // FADD = 495
    CEFBS_None, // FADD_F1 = 496
    CEFBS_None, // FADD_F1_W8 = 497
    CEFBS_None, // FADD_P = 498
    CEFBS_None, // FADD_W8 = 499
    CEFBS_None, // FFMA_ACC_F0 = 500
    CEFBS_None, // FFMA_ACC_F1 = 501
    CEFBS_None, // FFMA_F0 = 502
    CEFBS_None, // FFMA_F1 = 503
    CEFBS_None, // FMAX = 504
    CEFBS_None, // FMAX_F1 = 505
    CEFBS_None, // FMIN = 506
    CEFBS_None, // FMIN_F1 = 507
    CEFBS_None, // FMUL = 508
    CEFBS_None, // FMUL_F1 = 509
    CEFBS_None, // FMUL_F1_W8 = 510
    CEFBS_None, // FMUL_P = 511
    CEFBS_None, // FMUL_W8 = 512
    CEFBS_None, // FNEG_F0 = 513
    CEFBS_None, // FNEG_F1 = 514
    CEFBS_None, // FSUB = 515
    CEFBS_None, // FSUB_F1 = 516
    CEFBS_None, // FSUB_F1_W8 = 517
    CEFBS_None, // FSUB_P = 518
    CEFBS_None, // FSUB_W8 = 519
    CEFBS_None, // LD_GLOBAL = 520
    CEFBS_None, // LD_GLOBAL_IDX = 521
    CEFBS_None, // LD_GLOBAL_IDX_W16 = 522
    CEFBS_None, // LD_GLOBAL_IDX_W8 = 523
    CEFBS_None, // LD_GLOBAL_P = 524
    CEFBS_None, // LD_GLOBAL_SLOT = 525
    CEFBS_None, // LD_GLOBAL_SLOT_W16 = 526
    CEFBS_None, // LD_GLOBAL_SLOT_W8 = 527
    CEFBS_None, // LD_GLOBAL_W16 = 528
    CEFBS_None, // LD_GLOBAL_W8 = 529
    CEFBS_None, // LD_LOCAL = 530
    CEFBS_None, // LD_PRED_G = 531
    CEFBS_None, // LD_PRED_LOCAL = 532
    CEFBS_None, // LD_PRED_S = 533
    CEFBS_None, // LD_SHARED = 534
    CEFBS_None, // LD_SHARED_IDX = 535
    CEFBS_None, // LD_SHARED_W16 = 536
    CEFBS_None, // LD_SHARED_W8 = 537
    CEFBS_None, // LG2_F32 = 538
    CEFBS_None, // MADLO = 539
    CEFBS_None, // MADLO_P = 540
    CEFBS_None, // MAD_ACC = 541
    CEFBS_None, // MAX_S = 542
    CEFBS_None, // MAX_S_P = 543
    CEFBS_None, // MAX_S_W16 = 544
    CEFBS_None, // MAX_U = 545
    CEFBS_None, // MAX_U_P = 546
    CEFBS_None, // MIN_S = 547
    CEFBS_None, // MIN_S_P = 548
    CEFBS_None, // MIN_S_W16 = 549
    CEFBS_None, // MIN_U = 550
    CEFBS_None, // MIN_U_P = 551
    CEFBS_None, // MOVI = 552
    CEFBS_None, // MOVI48 = 553
    CEFBS_None, // MOV_P = 554
    CEFBS_None, // MULI = 555
    CEFBS_None, // MULI_P = 556
    CEFBS_None, // MUL_HI_S = 557
    CEFBS_None, // MUL_HI_S_P = 558
    CEFBS_None, // MUL_HI_U = 559
    CEFBS_None, // MUL_HI_U_P = 560
    CEFBS_None, // MUL_LO = 561
    CEFBS_None, // NEG = 562
    CEFBS_None, // OR = 563
    CEFBS_None, // ORI = 564
    CEFBS_None, // ORI_P = 565
    CEFBS_None, // OR_P = 566
    CEFBS_None, // OR_W16 = 567
    CEFBS_None, // PACKI = 568
    CEFBS_None, // PACKI_Z = 569
    CEFBS_None, // PAND = 570
    CEFBS_None, // PMOV = 571
    CEFBS_None, // PMOV_IMM = 572
    CEFBS_None, // POPC = 573
    CEFBS_None, // POR = 574
    CEFBS_None, // PXOR = 575
    CEFBS_None, // RCP_F32 = 576
    CEFBS_None, // RCP_F32_P = 577
    CEFBS_None, // RCP_U32 = 578
    CEFBS_None, // RSQRT_F32 = 579
    CEFBS_None, // SEL = 580
    CEFBS_None, // SETP_EQ = 581
    CEFBS_None, // SETP_EQ_F = 582
    CEFBS_None, // SETP_EQ_F1 = 583
    CEFBS_None, // SETP_EQ_F1_NP = 584
    CEFBS_None, // SETP_EQ_F_I = 585
    CEFBS_None, // SETP_EQ_F_NP = 586
    CEFBS_None, // SETP_EQ_F_NPI = 587
    CEFBS_None, // SETP_EQ_I = 588
    CEFBS_None, // SETP_EQ_NP = 589
    CEFBS_None, // SETP_EQ_NPI = 590
    CEFBS_None, // SETP_GE = 591
    CEFBS_None, // SETP_GE_F = 592
    CEFBS_None, // SETP_GE_F1 = 593
    CEFBS_None, // SETP_GE_F1_NP = 594
    CEFBS_None, // SETP_GE_F_I = 595
    CEFBS_None, // SETP_GE_F_NP = 596
    CEFBS_None, // SETP_GE_F_NPI = 597
    CEFBS_None, // SETP_GE_I = 598
    CEFBS_None, // SETP_GE_NP = 599
    CEFBS_None, // SETP_GE_NPI = 600
    CEFBS_None, // SETP_GE_U = 601
    CEFBS_None, // SETP_GE_U_I = 602
    CEFBS_None, // SETP_GE_U_NP = 603
    CEFBS_None, // SETP_GE_U_NPI = 604
    CEFBS_None, // SETP_GT = 605
    CEFBS_None, // SETP_GT_F = 606
    CEFBS_None, // SETP_GT_F1 = 607
    CEFBS_None, // SETP_GT_F1_NP = 608
    CEFBS_None, // SETP_GT_F_I = 609
    CEFBS_None, // SETP_GT_F_NP = 610
    CEFBS_None, // SETP_GT_F_NPI = 611
    CEFBS_None, // SETP_GT_I = 612
    CEFBS_None, // SETP_GT_NP = 613
    CEFBS_None, // SETP_GT_NPI = 614
    CEFBS_None, // SETP_GT_U = 615
    CEFBS_None, // SETP_GT_U_I = 616
    CEFBS_None, // SETP_GT_U_NP = 617
    CEFBS_None, // SETP_GT_U_NPI = 618
    CEFBS_None, // SETP_LE = 619
    CEFBS_None, // SETP_LE_F = 620
    CEFBS_None, // SETP_LE_F1 = 621
    CEFBS_None, // SETP_LE_F1_NP = 622
    CEFBS_None, // SETP_LE_F_I = 623
    CEFBS_None, // SETP_LE_F_NP = 624
    CEFBS_None, // SETP_LE_F_NPI = 625
    CEFBS_None, // SETP_LE_I = 626
    CEFBS_None, // SETP_LE_NP = 627
    CEFBS_None, // SETP_LE_NPI = 628
    CEFBS_None, // SETP_LE_U = 629
    CEFBS_None, // SETP_LE_U_I = 630
    CEFBS_None, // SETP_LE_U_NP = 631
    CEFBS_None, // SETP_LE_U_NPI = 632
    CEFBS_None, // SETP_LT = 633
    CEFBS_None, // SETP_LT_F = 634
    CEFBS_None, // SETP_LT_F1 = 635
    CEFBS_None, // SETP_LT_F1_NP = 636
    CEFBS_None, // SETP_LT_F_I = 637
    CEFBS_None, // SETP_LT_F_NP = 638
    CEFBS_None, // SETP_LT_F_NPI = 639
    CEFBS_None, // SETP_LT_I = 640
    CEFBS_None, // SETP_LT_NP = 641
    CEFBS_None, // SETP_LT_NPI = 642
    CEFBS_None, // SETP_LT_U = 643
    CEFBS_None, // SETP_LT_U_I = 644
    CEFBS_None, // SETP_LT_U_NP = 645
    CEFBS_None, // SETP_LT_U_NPI = 646
    CEFBS_None, // SETP_NE = 647
    CEFBS_None, // SETP_NE_F = 648
    CEFBS_None, // SETP_NE_F1 = 649
    CEFBS_None, // SETP_NE_F1_NP = 650
    CEFBS_None, // SETP_NE_F_I = 651
    CEFBS_None, // SETP_NE_F_NP = 652
    CEFBS_None, // SETP_NE_F_NPI = 653
    CEFBS_None, // SETP_NE_I = 654
    CEFBS_None, // SETP_NE_NP = 655
    CEFBS_None, // SETP_NE_NPI = 656
    CEFBS_None, // SHFL_IDX = 657
    CEFBS_None, // SHL = 658
    CEFBS_None, // SHLI = 659
    CEFBS_None, // SHLI_P = 660
    CEFBS_None, // SHL_P = 661
    CEFBS_None, // SHR = 662
    CEFBS_None, // SHRI = 663
    CEFBS_None, // SHRI_P = 664
    CEFBS_None, // SHR_P = 665
    CEFBS_None, // SIN_F32 = 666
    CEFBS_None, // SQRT_F32 = 667
    CEFBS_None, // SRA = 668
    CEFBS_None, // SRAI = 669
    CEFBS_None, // SRAI_P = 670
    CEFBS_None, // SRA_P = 671
    CEFBS_None, // SRD = 672
    CEFBS_None, // ST_GLOBAL = 673
    CEFBS_None, // ST_GLOBAL_IDX = 674
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 675
    CEFBS_None, // ST_GLOBAL_IDX_W8 = 676
    CEFBS_None, // ST_GLOBAL_SLOT = 677
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 678
    CEFBS_None, // ST_GLOBAL_SLOT_W8 = 679
    CEFBS_None, // ST_GLOBAL_W16 = 680
    CEFBS_None, // ST_GLOBAL_W8 = 681
    CEFBS_None, // ST_LOCAL = 682
    CEFBS_None, // ST_PRED_G = 683
    CEFBS_None, // ST_PRED_LOCAL = 684
    CEFBS_None, // ST_PRED_S = 685
    CEFBS_None, // ST_SHARED = 686
    CEFBS_None, // ST_SHARED_IDX = 687
    CEFBS_None, // ST_SHARED_W16 = 688
    CEFBS_None, // ST_SHARED_W8 = 689
    CEFBS_None, // SUB = 690
    CEFBS_None, // SUBI = 691
    CEFBS_None, // SUBI_P = 692
    CEFBS_None, // SUB_P = 693
    CEFBS_None, // SUB_W16 = 694
    CEFBS_None, // UNBALLOT = 695
    CEFBS_None, // UNPACKI = 696
    CEFBS_None, // VOTE_ANY = 697
    CEFBS_None, // XOR = 698
    CEFBS_None, // XORI = 699
    CEFBS_None, // XORI_P = 700
    CEFBS_None, // XOR_P = 701
    CEFBS_None, // XOR_W16 = 702
  };

  assert(Opcode < 703);
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

