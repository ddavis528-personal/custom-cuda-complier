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
    PSEUDO_PRIVCHECK	= 284,
    PSEUDO_PRIVFLOOR	= 285,
    PSEUDO_PXOR	= 286,
    PSEUDO_RET	= 287,
    PSEUDO_ST_PRED	= 288,
    PSEUDO_TRUNC16	= 289,
    ABS	= 290,
    ADD	= 291,
    ADDI	= 292,
    ADDI48	= 293,
    ADDI_P	= 294,
    ADDI_PP	= 295,
    ADDI_W16	= 296,
    ADD_P	= 297,
    ADD_PP	= 298,
    ADD_W16	= 299,
    AND	= 300,
    ANDI	= 301,
    ANDI_P	= 302,
    ANDN	= 303,
    ANDNI	= 304,
    ANDNI_P	= 305,
    AND_P	= 306,
    AND_W16	= 307,
    ATOM_ADD_F_G	= 308,
    ATOM_ADD_F_S	= 309,
    ATOM_ADD_G	= 310,
    ATOM_ADD_S	= 311,
    ATOM_AND_G	= 312,
    ATOM_AND_S	= 313,
    ATOM_EXCH_G	= 314,
    ATOM_EXCH_S	= 315,
    ATOM_MAX_S_G	= 316,
    ATOM_MAX_S_S	= 317,
    ATOM_MAX_U_G	= 318,
    ATOM_MAX_U_S	= 319,
    ATOM_MIN_S_G	= 320,
    ATOM_MIN_S_S	= 321,
    ATOM_MIN_U_G	= 322,
    ATOM_MIN_U_S	= 323,
    ATOM_OR_G	= 324,
    ATOM_OR_S	= 325,
    ATOM_XOR_G	= 326,
    ATOM_XOR_S	= 327,
    BALLOT	= 328,
    BAR_INIT	= 329,
    BAR_WAIT_PHASE	= 330,
    BRA	= 331,
    BRA_PRED	= 332,
    BREV	= 333,
    CALL	= 334,
    CAS_G	= 335,
    CAS_S	= 336,
    CHWIDTH_MULTI	= 337,
    CLZ	= 338,
    COS_F32	= 339,
    CVT_D0_S0_R0	= 340,
    CVT_D0_S0_R0_P	= 341,
    CVT_D0_S0_R0_W16_32	= 342,
    CVT_D0_S0_R0_W16_8	= 343,
    CVT_D0_S0_R0_W32_16	= 344,
    CVT_D0_S0_R0_W32_4	= 345,
    CVT_D0_S0_R0_W32_8	= 346,
    CVT_D0_S0_R0_W4_32	= 347,
    CVT_D0_S0_R0_W8_32	= 348,
    CVT_D0_S0_R1	= 349,
    CVT_D0_S0_R1_P	= 350,
    CVT_D0_S0_R2	= 351,
    CVT_D0_S0_R2_P	= 352,
    CVT_D0_S0_R3	= 353,
    CVT_D0_S0_R3_P	= 354,
    CVT_D0_S1_R0	= 355,
    CVT_D0_S1_R0_P	= 356,
    CVT_D0_S1_R0_W16_8	= 357,
    CVT_D0_S1_R0_W32_8	= 358,
    CVT_D0_S1_R1	= 359,
    CVT_D0_S1_R1_P	= 360,
    CVT_D0_S1_R2	= 361,
    CVT_D0_S1_R2_P	= 362,
    CVT_D0_S1_R3	= 363,
    CVT_D0_S1_R3_P	= 364,
    CVT_D0_S2_R1	= 365,
    CVT_D0_S2_R1_P	= 366,
    CVT_D0_S2_R2	= 367,
    CVT_D0_S2_R2_P	= 368,
    CVT_D0_S2_R3	= 369,
    CVT_D0_S2_R3_P	= 370,
    CVT_D0_S3_R1	= 371,
    CVT_D0_S3_R1_P	= 372,
    CVT_D0_S3_R2	= 373,
    CVT_D0_S3_R2_P	= 374,
    CVT_D0_S3_R3	= 375,
    CVT_D0_S3_R3_P	= 376,
    CVT_D1_S0_R0	= 377,
    CVT_D1_S0_R0_P	= 378,
    CVT_D1_S0_R0_W8_32	= 379,
    CVT_D1_S0_R1	= 380,
    CVT_D1_S0_R1_P	= 381,
    CVT_D1_S0_R2	= 382,
    CVT_D1_S0_R2_P	= 383,
    CVT_D1_S0_R3	= 384,
    CVT_D1_S0_R3_P	= 385,
    CVT_D1_S1_R0	= 386,
    CVT_D1_S1_R0_P	= 387,
    CVT_D1_S1_R1	= 388,
    CVT_D1_S1_R1_P	= 389,
    CVT_D1_S1_R2	= 390,
    CVT_D1_S1_R2_P	= 391,
    CVT_D1_S1_R3	= 392,
    CVT_D1_S1_R3_P	= 393,
    CVT_D1_S2_R0	= 394,
    CVT_D1_S2_R0_P	= 395,
    CVT_D1_S2_R1	= 396,
    CVT_D1_S2_R1_P	= 397,
    CVT_D1_S2_R2	= 398,
    CVT_D1_S2_R2_P	= 399,
    CVT_D1_S2_R3	= 400,
    CVT_D1_S2_R3_P	= 401,
    CVT_D1_S3_R0	= 402,
    CVT_D1_S3_R0_P	= 403,
    CVT_D1_S3_R1	= 404,
    CVT_D1_S3_R1_P	= 405,
    CVT_D1_S3_R2	= 406,
    CVT_D1_S3_R2_P	= 407,
    CVT_D1_S3_R3	= 408,
    CVT_D1_S3_R3_P	= 409,
    CVT_D2_S0_R0	= 410,
    CVT_D2_S0_R0_P	= 411,
    CVT_D2_S0_R2	= 412,
    CVT_D2_S0_R2_P	= 413,
    CVT_D2_S0_R3	= 414,
    CVT_D2_S0_R3_P	= 415,
    CVT_D2_S1_R0	= 416,
    CVT_D2_S1_R0_P	= 417,
    CVT_D2_S1_R1	= 418,
    CVT_D2_S1_R1_P	= 419,
    CVT_D2_S1_R2	= 420,
    CVT_D2_S1_R2_P	= 421,
    CVT_D2_S1_R3	= 422,
    CVT_D2_S1_R3_P	= 423,
    CVT_D2_S3_R0	= 424,
    CVT_D2_S3_R0_P	= 425,
    CVT_D3_S0_R0	= 426,
    CVT_D3_S0_R0_P	= 427,
    CVT_D3_S0_R2	= 428,
    CVT_D3_S0_R2_P	= 429,
    CVT_D3_S0_R3	= 430,
    CVT_D3_S0_R3_P	= 431,
    CVT_D3_S1_R0	= 432,
    CVT_D3_S1_R0_P	= 433,
    CVT_D3_S1_R1	= 434,
    CVT_D3_S1_R1_P	= 435,
    CVT_D3_S1_R2	= 436,
    CVT_D3_S1_R2_P	= 437,
    CVT_D3_S1_R3	= 438,
    CVT_D3_S1_R3_P	= 439,
    CVT_D3_S2_R0	= 440,
    CVT_D3_S2_R0_P	= 441,
    CVT_D3_S3_R0	= 442,
    CVT_D3_S3_R0_P	= 443,
    CVT_F32_S32	= 444,
    CVT_F32_S32_P	= 445,
    CVT_F32_U32	= 446,
    CVT_F32_U32_P	= 447,
    CVT_S32_F32	= 448,
    CVT_S32_F32_P	= 449,
    CVT_SEXT	= 450,
    CVT_U32_F32	= 451,
    CVT_U32_F32_P	= 452,
    C_ABS	= 453,
    C_ADD	= 454,
    C_ADDI	= 455,
    C_AND	= 456,
    C_ANDI	= 457,
    C_ANDN	= 458,
    C_BAR_ARRIVE	= 459,
    C_BAR_WAIT	= 460,
    C_BRA	= 461,
    C_CHWIDTH	= 462,
    C_EXIT	= 463,
    C_FADD	= 464,
    C_FENCE	= 465,
    C_FMAX	= 466,
    C_FMIN	= 467,
    C_FMUL	= 468,
    C_LD_GLOBAL	= 469,
    C_MAX_S	= 470,
    C_MAX_U	= 471,
    C_MIN_S	= 472,
    C_MIN_U	= 473,
    C_MOV	= 474,
    C_MUL_LO	= 475,
    C_NEG	= 476,
    C_NOT	= 477,
    C_OR	= 478,
    C_ORI	= 479,
    C_RECONV	= 480,
    C_RET	= 481,
    C_SHL	= 482,
    C_SHLI	= 483,
    C_SHR	= 484,
    C_SHRI	= 485,
    C_SRA	= 486,
    C_SRAI	= 487,
    C_ST_GLOBAL	= 488,
    C_SUB	= 489,
    C_SUBI	= 490,
    C_XOR	= 491,
    C_XORI	= 492,
    DP2_BF16	= 493,
    DP2_F16	= 494,
    DP4_ACC	= 495,
    DP4_E4M3	= 496,
    DP4_E5M2	= 497,
    DP4_SS	= 498,
    EX2_F32	= 499,
    FABS_F0	= 500,
    FABS_F1	= 501,
    FADD	= 502,
    FADD_F1	= 503,
    FADD_F1_W8	= 504,
    FADD_P	= 505,
    FADD_W8	= 506,
    FFMA_ACC_F0	= 507,
    FFMA_ACC_F1	= 508,
    FFMA_F0	= 509,
    FFMA_F1	= 510,
    FMAX	= 511,
    FMAX_F1	= 512,
    FMIN	= 513,
    FMIN_F1	= 514,
    FMUL	= 515,
    FMUL_F1	= 516,
    FMUL_F1_W8	= 517,
    FMUL_P	= 518,
    FMUL_W8	= 519,
    FNEG_F0	= 520,
    FNEG_F1	= 521,
    FSUB	= 522,
    FSUB_F1	= 523,
    FSUB_F1_W8	= 524,
    FSUB_P	= 525,
    FSUB_W8	= 526,
    LD_GLOBAL	= 527,
    LD_GLOBAL_IDX	= 528,
    LD_GLOBAL_IDX_W16	= 529,
    LD_GLOBAL_IDX_W8	= 530,
    LD_GLOBAL_P	= 531,
    LD_GLOBAL_SLOT	= 532,
    LD_GLOBAL_SLOT_W16	= 533,
    LD_GLOBAL_SLOT_W8	= 534,
    LD_GLOBAL_W16	= 535,
    LD_GLOBAL_W8	= 536,
    LD_LOCAL	= 537,
    LD_PRED_G	= 538,
    LD_PRED_LOCAL	= 539,
    LD_PRED_S	= 540,
    LD_SHARED	= 541,
    LD_SHARED_IDX	= 542,
    LD_SHARED_W16	= 543,
    LD_SHARED_W8	= 544,
    LG2_F32	= 545,
    MADLO	= 546,
    MADLO_P	= 547,
    MAD_ACC	= 548,
    MAX_S	= 549,
    MAX_S_P	= 550,
    MAX_S_W16	= 551,
    MAX_U	= 552,
    MAX_U_P	= 553,
    MIN_S	= 554,
    MIN_S_P	= 555,
    MIN_S_W16	= 556,
    MIN_U	= 557,
    MIN_U_P	= 558,
    MOVI	= 559,
    MOVI48	= 560,
    MOV_P	= 561,
    MULI	= 562,
    MULI_P	= 563,
    MUL_HI_S	= 564,
    MUL_HI_S_P	= 565,
    MUL_HI_U	= 566,
    MUL_HI_U_P	= 567,
    MUL_LO	= 568,
    NEG	= 569,
    OR	= 570,
    ORI	= 571,
    ORI_P	= 572,
    OR_P	= 573,
    OR_W16	= 574,
    PACKI	= 575,
    PACKI_Z	= 576,
    PAND	= 577,
    PMOV	= 578,
    PMOV_IMM	= 579,
    POPC	= 580,
    POR	= 581,
    PXOR	= 582,
    RCP_F32	= 583,
    RCP_F32_P	= 584,
    RCP_U32	= 585,
    RSQRT_F32	= 586,
    SEL	= 587,
    SETP_EQ	= 588,
    SETP_EQ_F	= 589,
    SETP_EQ_F1	= 590,
    SETP_EQ_F1_NP	= 591,
    SETP_EQ_F_I	= 592,
    SETP_EQ_F_NP	= 593,
    SETP_EQ_F_NPI	= 594,
    SETP_EQ_I	= 595,
    SETP_EQ_NP	= 596,
    SETP_EQ_NPI	= 597,
    SETP_GE	= 598,
    SETP_GE_F	= 599,
    SETP_GE_F1	= 600,
    SETP_GE_F1_NP	= 601,
    SETP_GE_F_I	= 602,
    SETP_GE_F_NP	= 603,
    SETP_GE_F_NPI	= 604,
    SETP_GE_I	= 605,
    SETP_GE_NP	= 606,
    SETP_GE_NPI	= 607,
    SETP_GE_U	= 608,
    SETP_GE_U_I	= 609,
    SETP_GE_U_NP	= 610,
    SETP_GE_U_NPI	= 611,
    SETP_GT	= 612,
    SETP_GT_F	= 613,
    SETP_GT_F1	= 614,
    SETP_GT_F1_NP	= 615,
    SETP_GT_F_I	= 616,
    SETP_GT_F_NP	= 617,
    SETP_GT_F_NPI	= 618,
    SETP_GT_I	= 619,
    SETP_GT_NP	= 620,
    SETP_GT_NPI	= 621,
    SETP_GT_U	= 622,
    SETP_GT_U_I	= 623,
    SETP_GT_U_NP	= 624,
    SETP_GT_U_NPI	= 625,
    SETP_LE	= 626,
    SETP_LE_F	= 627,
    SETP_LE_F1	= 628,
    SETP_LE_F1_NP	= 629,
    SETP_LE_F_I	= 630,
    SETP_LE_F_NP	= 631,
    SETP_LE_F_NPI	= 632,
    SETP_LE_I	= 633,
    SETP_LE_NP	= 634,
    SETP_LE_NPI	= 635,
    SETP_LE_U	= 636,
    SETP_LE_U_I	= 637,
    SETP_LE_U_NP	= 638,
    SETP_LE_U_NPI	= 639,
    SETP_LT	= 640,
    SETP_LT_F	= 641,
    SETP_LT_F1	= 642,
    SETP_LT_F1_NP	= 643,
    SETP_LT_F_I	= 644,
    SETP_LT_F_NP	= 645,
    SETP_LT_F_NPI	= 646,
    SETP_LT_I	= 647,
    SETP_LT_NP	= 648,
    SETP_LT_NPI	= 649,
    SETP_LT_U	= 650,
    SETP_LT_U_I	= 651,
    SETP_LT_U_NP	= 652,
    SETP_LT_U_NPI	= 653,
    SETP_NE	= 654,
    SETP_NE_F	= 655,
    SETP_NE_F1	= 656,
    SETP_NE_F1_NP	= 657,
    SETP_NE_F_I	= 658,
    SETP_NE_F_NP	= 659,
    SETP_NE_F_NPI	= 660,
    SETP_NE_I	= 661,
    SETP_NE_NP	= 662,
    SETP_NE_NPI	= 663,
    SHFL_IDX	= 664,
    SHL	= 665,
    SHLI	= 666,
    SHLI_P	= 667,
    SHL_P	= 668,
    SHR	= 669,
    SHRI	= 670,
    SHRI_P	= 671,
    SHR_P	= 672,
    SIN_F32	= 673,
    SQRT_F32	= 674,
    SRA	= 675,
    SRAI	= 676,
    SRAI_P	= 677,
    SRA_P	= 678,
    SRD	= 679,
    ST_GLOBAL	= 680,
    ST_GLOBAL_IDX	= 681,
    ST_GLOBAL_IDX_W16	= 682,
    ST_GLOBAL_IDX_W8	= 683,
    ST_GLOBAL_SLOT	= 684,
    ST_GLOBAL_SLOT_W16	= 685,
    ST_GLOBAL_SLOT_W8	= 686,
    ST_GLOBAL_W16	= 687,
    ST_GLOBAL_W8	= 688,
    ST_LOCAL	= 689,
    ST_PRED_G	= 690,
    ST_PRED_LOCAL	= 691,
    ST_PRED_S	= 692,
    ST_SHARED	= 693,
    ST_SHARED_IDX	= 694,
    ST_SHARED_W16	= 695,
    ST_SHARED_W8	= 696,
    SUB	= 697,
    SUBI	= 698,
    SUBI_P	= 699,
    SUB_P	= 700,
    SUB_W16	= 701,
    SZ_GLOBAL_LD_S16	= 702,
    SZ_GLOBAL_LD_S16_W16	= 703,
    SZ_GLOBAL_LD_S8	= 704,
    SZ_GLOBAL_LD_S8_W16	= 705,
    SZ_GLOBAL_LD_U16	= 706,
    SZ_GLOBAL_LD_U16_W16	= 707,
    SZ_GLOBAL_LD_U8	= 708,
    SZ_GLOBAL_LD_U8_W16	= 709,
    SZ_GLOBAL_ST_16	= 710,
    SZ_GLOBAL_ST_16_W16	= 711,
    SZ_GLOBAL_ST_8	= 712,
    SZ_GLOBAL_ST_8_W16	= 713,
    SZ_SHARED_LD_S16	= 714,
    SZ_SHARED_LD_S8	= 715,
    SZ_SHARED_LD_U16	= 716,
    SZ_SHARED_LD_U8	= 717,
    SZ_SHARED_ST_16	= 718,
    SZ_SHARED_ST_8	= 719,
    UNBALLOT	= 720,
    UNPACKI	= 721,
    VOTE_ANY	= 722,
    XOR	= 723,
    XORI	= 724,
    XORI_P	= 725,
    XOR_P	= 726,
    XOR_W16	= 727,
    INSTRUCTION_LIST_END = 728
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
  MCInstrDesc Insts[728];
  static_assert(alignof(MCInstrDesc) >= alignof(MCOperandInfo), "Unwanted padding between Insts and OperandInfo");
  MCOperandInfo OperandInfo[358];
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
    { 727,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #727 = XOR_W16
    { 726,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #726 = XOR_P
    { 725,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #725 = XORI_P
    { 724,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #724 = XORI
    { 723,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #723 = XOR
    { 722,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	355,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #722 = VOTE_ANY
    { 721,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #721 = UNPACKI
    { 720,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	352,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #720 = UNBALLOT
    { 719,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #719 = SZ_SHARED_ST_8
    { 718,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #718 = SZ_SHARED_ST_16
    { 717,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #717 = SZ_SHARED_LD_U8
    { 716,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #716 = SZ_SHARED_LD_U16
    { 715,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #715 = SZ_SHARED_LD_S8
    { 714,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #714 = SZ_SHARED_LD_S16
    { 713,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #713 = SZ_GLOBAL_ST_8_W16
    { 712,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #712 = SZ_GLOBAL_ST_8
    { 711,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #711 = SZ_GLOBAL_ST_16_W16
    { 710,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #710 = SZ_GLOBAL_ST_16
    { 709,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #709 = SZ_GLOBAL_LD_U8_W16
    { 708,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #708 = SZ_GLOBAL_LD_U8
    { 707,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #707 = SZ_GLOBAL_LD_U16_W16
    { 706,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #706 = SZ_GLOBAL_LD_U16
    { 705,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #705 = SZ_GLOBAL_LD_S8_W16
    { 704,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #704 = SZ_GLOBAL_LD_S8
    { 703,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #703 = SZ_GLOBAL_LD_S16_W16
    { 702,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #702 = SZ_GLOBAL_LD_S16
    { 701,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #701 = SUB_W16
    { 700,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #700 = SUB_P
    { 699,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #699 = SUBI_P
    { 698,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #698 = SUBI
    { 697,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #697 = SUB
    { 696,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #696 = ST_SHARED_W8
    { 695,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #695 = ST_SHARED_W16
    { 694,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #694 = ST_SHARED_IDX
    { 693,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #693 = ST_SHARED
    { 692,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	314,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #692 = ST_PRED_S
    { 691,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	317,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #691 = ST_PRED_LOCAL
    { 690,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	314,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #690 = ST_PRED_G
    { 689,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #689 = ST_LOCAL
    { 688,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #688 = ST_GLOBAL_W8
    { 687,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #687 = ST_GLOBAL_W16
    { 686,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	303,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #686 = ST_GLOBAL_SLOT_W8
    { 685,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	298,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #685 = ST_GLOBAL_SLOT_W16
    { 684,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	293,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #684 = ST_GLOBAL_SLOT
    { 683,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	288,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #683 = ST_GLOBAL_IDX_W8
    { 682,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #682 = ST_GLOBAL_IDX_W16
    { 681,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #681 = ST_GLOBAL_IDX
    { 680,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #680 = ST_GLOBAL
    { 679,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #679 = SRD
    { 678,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #678 = SRA_P
    { 677,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #677 = SRAI_P
    { 676,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #676 = SRAI
    { 675,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #675 = SRA
    { 674,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #674 = SQRT_F32
    { 673,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #673 = SIN_F32
    { 672,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #672 = SHR_P
    { 671,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #671 = SHRI_P
    { 670,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #670 = SHRI
    { 669,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #669 = SHR
    { 668,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #668 = SHL_P
    { 667,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #667 = SHLI_P
    { 666,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #666 = SHLI
    { 665,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #665 = SHL
    { 664,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #664 = SHFL_IDX
    { 663,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #663 = SETP_NE_NPI
    { 662,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #662 = SETP_NE_NP
    { 661,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #661 = SETP_NE_I
    { 660,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #660 = SETP_NE_F_NPI
    { 659,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #659 = SETP_NE_F_NP
    { 658,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #658 = SETP_NE_F_I
    { 657,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #657 = SETP_NE_F1_NP
    { 656,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #656 = SETP_NE_F1
    { 655,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #655 = SETP_NE_F
    { 654,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #654 = SETP_NE
    { 653,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #653 = SETP_LT_U_NPI
    { 652,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #652 = SETP_LT_U_NP
    { 651,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #651 = SETP_LT_U_I
    { 650,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #650 = SETP_LT_U
    { 649,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #649 = SETP_LT_NPI
    { 648,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #648 = SETP_LT_NP
    { 647,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #647 = SETP_LT_I
    { 646,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #646 = SETP_LT_F_NPI
    { 645,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #645 = SETP_LT_F_NP
    { 644,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #644 = SETP_LT_F_I
    { 643,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #643 = SETP_LT_F1_NP
    { 642,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #642 = SETP_LT_F1
    { 641,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #641 = SETP_LT_F
    { 640,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #640 = SETP_LT
    { 639,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #639 = SETP_LE_U_NPI
    { 638,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #638 = SETP_LE_U_NP
    { 637,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #637 = SETP_LE_U_I
    { 636,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #636 = SETP_LE_U
    { 635,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #635 = SETP_LE_NPI
    { 634,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #634 = SETP_LE_NP
    { 633,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #633 = SETP_LE_I
    { 632,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #632 = SETP_LE_F_NPI
    { 631,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #631 = SETP_LE_F_NP
    { 630,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #630 = SETP_LE_F_I
    { 629,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #629 = SETP_LE_F1_NP
    { 628,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #628 = SETP_LE_F1
    { 627,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #627 = SETP_LE_F
    { 626,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #626 = SETP_LE
    { 625,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #625 = SETP_GT_U_NPI
    { 624,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #624 = SETP_GT_U_NP
    { 623,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #623 = SETP_GT_U_I
    { 622,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #622 = SETP_GT_U
    { 621,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #621 = SETP_GT_NPI
    { 620,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #620 = SETP_GT_NP
    { 619,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #619 = SETP_GT_I
    { 618,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #618 = SETP_GT_F_NPI
    { 617,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #617 = SETP_GT_F_NP
    { 616,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #616 = SETP_GT_F_I
    { 615,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #615 = SETP_GT_F1_NP
    { 614,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #614 = SETP_GT_F1
    { 613,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #613 = SETP_GT_F
    { 612,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #612 = SETP_GT
    { 611,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #611 = SETP_GE_U_NPI
    { 610,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #610 = SETP_GE_U_NP
    { 609,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #609 = SETP_GE_U_I
    { 608,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #608 = SETP_GE_U
    { 607,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #607 = SETP_GE_NPI
    { 606,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #606 = SETP_GE_NP
    { 605,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #605 = SETP_GE_I
    { 604,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #604 = SETP_GE_F_NPI
    { 603,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #603 = SETP_GE_F_NP
    { 602,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #602 = SETP_GE_F_I
    { 601,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #601 = SETP_GE_F1_NP
    { 600,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #600 = SETP_GE_F1
    { 599,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #599 = SETP_GE_F
    { 598,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #598 = SETP_GE
    { 597,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #597 = SETP_EQ_NPI
    { 596,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #596 = SETP_EQ_NP
    { 595,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #595 = SETP_EQ_I
    { 594,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	348,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #594 = SETP_EQ_F_NPI
    { 593,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #593 = SETP_EQ_F_NP
    { 592,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	343,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #592 = SETP_EQ_F_I
    { 591,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	339,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #591 = SETP_EQ_F1_NP
    { 590,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #590 = SETP_EQ_F1
    { 589,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #589 = SETP_EQ_F
    { 588,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	334,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #588 = SETP_EQ
    { 587,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #587 = SEL
    { 586,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #586 = RSQRT_F32
    { 585,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #585 = RCP_U32
    { 584,	5,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #584 = RCP_F32_P
    { 583,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #583 = RCP_F32
    { 582,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #582 = PXOR
    { 581,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #581 = POR
    { 580,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #580 = POPC
    { 579,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	332,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #579 = PMOV_IMM
    { 578,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #578 = PMOV
    { 577,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	329,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #577 = PAND
    { 576,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #576 = PACKI_Z
    { 575,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	325,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #575 = PACKI
    { 574,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #574 = OR_W16
    { 573,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #573 = OR_P
    { 572,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #572 = ORI_P
    { 571,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #571 = ORI
    { 570,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #570 = OR
    { 569,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #569 = NEG
    { 568,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #568 = MUL_LO
    { 567,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #567 = MUL_HI_U_P
    { 566,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #566 = MUL_HI_U
    { 565,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #565 = MUL_HI_S_P
    { 564,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #564 = MUL_HI_S
    { 563,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #563 = MULI_P
    { 562,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #562 = MULI
    { 561,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	319,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #561 = MOV_P
    { 560,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #560 = MOVI48
    { 559,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #559 = MOVI
    { 558,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #558 = MIN_U_P
    { 557,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #557 = MIN_U
    { 556,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #556 = MIN_S_W16
    { 555,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #555 = MIN_S_P
    { 554,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #554 = MIN_S
    { 553,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #553 = MAX_U_P
    { 552,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #552 = MAX_U
    { 551,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #551 = MAX_S_W16
    { 550,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #550 = MAX_S_P
    { 549,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #549 = MAX_S
    { 548,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	270,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #548 = MAD_ACC
    { 547,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #547 = MADLO_P
    { 546,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #546 = MADLO
    { 545,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #545 = LG2_F32
    { 544,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #544 = LD_SHARED_W8
    { 543,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #543 = LD_SHARED_W16
    { 542,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #542 = LD_SHARED_IDX
    { 541,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #541 = LD_SHARED
    { 540,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	314,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #540 = LD_PRED_S
    { 539,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	317,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #539 = LD_PRED_LOCAL
    { 538,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	314,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #538 = LD_PRED_G
    { 537,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #537 = LD_LOCAL
    { 536,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	311,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #536 = LD_GLOBAL_W8
    { 535,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	308,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #535 = LD_GLOBAL_W16
    { 534,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	303,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #534 = LD_GLOBAL_SLOT_W8
    { 533,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	298,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #533 = LD_GLOBAL_SLOT_W16
    { 532,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	293,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #532 = LD_GLOBAL_SLOT
    { 531,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #531 = LD_GLOBAL_P
    { 530,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	288,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #530 = LD_GLOBAL_IDX_W8
    { 529,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	283,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #529 = LD_GLOBAL_IDX_W16
    { 528,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #528 = LD_GLOBAL_IDX
    { 527,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #527 = LD_GLOBAL
    { 526,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #526 = FSUB_W8
    { 525,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #525 = FSUB_P
    { 524,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #524 = FSUB_F1_W8
    { 523,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #523 = FSUB_F1
    { 522,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #522 = FSUB
    { 521,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #521 = FNEG_F1
    { 520,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #520 = FNEG_F0
    { 519,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #519 = FMUL_W8
    { 518,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #518 = FMUL_P
    { 517,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #517 = FMUL_F1_W8
    { 516,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #516 = FMUL_F1
    { 515,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #515 = FMUL
    { 514,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #514 = FMIN_F1
    { 513,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #513 = FMIN
    { 512,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #512 = FMAX_F1
    { 511,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #511 = FMAX
    { 510,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #510 = FFMA_F1
    { 509,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #509 = FFMA_F0
    { 508,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	270,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #508 = FFMA_ACC_F1
    { 507,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	270,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #507 = FFMA_ACC_F0
    { 506,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #506 = FADD_W8
    { 505,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #505 = FADD_P
    { 504,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #504 = FADD_F1_W8
    { 503,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #503 = FADD_F1
    { 502,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #502 = FADD
    { 501,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #501 = FABS_F1
    { 500,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #500 = FABS_F0
    { 499,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #499 = EX2_F32
    { 498,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #498 = DP4_SS
    { 497,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #497 = DP4_E5M2
    { 496,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #496 = DP4_E4M3
    { 495,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	270,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #495 = DP4_ACC
    { 494,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #494 = DP2_F16
    { 493,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #493 = DP2_BF16
    { 492,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #492 = C_XORI
    { 491,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #491 = C_XOR
    { 490,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #490 = C_SUBI
    { 489,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #489 = C_SUB
    { 488,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	262,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #488 = C_ST_GLOBAL
    { 487,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #487 = C_SRAI
    { 486,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #486 = C_SRA
    { 485,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #485 = C_SHRI
    { 484,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #484 = C_SHR
    { 483,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #483 = C_SHLI
    { 482,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #482 = C_SHL
    { 481,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #481 = C_RET
    { 480,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #480 = C_RECONV
    { 479,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #479 = C_ORI
    { 478,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #478 = C_OR
    { 477,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	262,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #477 = C_NOT
    { 476,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	262,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #476 = C_NEG
    { 475,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #475 = C_MUL_LO
    { 474,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	262,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #474 = C_MOV
    { 473,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #473 = C_MIN_U
    { 472,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #472 = C_MIN_S
    { 471,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #471 = C_MAX_U
    { 470,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #470 = C_MAX_S
    { 469,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	262,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #469 = C_LD_GLOBAL
    { 468,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #468 = C_FMUL
    { 467,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #467 = C_FMIN
    { 466,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #466 = C_FMAX
    { 465,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #465 = C_FENCE
    { 464,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #464 = C_FADD
    { 463,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #463 = C_EXIT
    { 462,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #462 = C_CHWIDTH
    { 461,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #461 = C_BRA
    { 460,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #460 = C_BAR_WAIT
    { 459,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #459 = C_BAR_ARRIVE
    { 458,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #458 = C_ANDN
    { 457,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #457 = C_ANDI
    { 456,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #456 = C_AND
    { 455,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	267,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #455 = C_ADDI
    { 454,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #454 = C_ADD
    { 453,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	262,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #453 = C_ABS
    { 452,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #452 = CVT_U32_F32_P
    { 451,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #451 = CVT_U32_F32
    { 450,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #450 = CVT_SEXT
    { 449,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #449 = CVT_S32_F32_P
    { 448,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #448 = CVT_S32_F32
    { 447,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #447 = CVT_F32_U32_P
    { 446,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #446 = CVT_F32_U32
    { 445,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #445 = CVT_F32_S32_P
    { 444,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #444 = CVT_F32_S32
    { 443,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #443 = CVT_D3_S3_R0_P
    { 442,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #442 = CVT_D3_S3_R0
    { 441,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #441 = CVT_D3_S2_R0_P
    { 440,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #440 = CVT_D3_S2_R0
    { 439,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #439 = CVT_D3_S1_R3_P
    { 438,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #438 = CVT_D3_S1_R3
    { 437,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #437 = CVT_D3_S1_R2_P
    { 436,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #436 = CVT_D3_S1_R2
    { 435,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #435 = CVT_D3_S1_R1_P
    { 434,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #434 = CVT_D3_S1_R1
    { 433,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #433 = CVT_D3_S1_R0_P
    { 432,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #432 = CVT_D3_S1_R0
    { 431,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #431 = CVT_D3_S0_R3_P
    { 430,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #430 = CVT_D3_S0_R3
    { 429,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #429 = CVT_D3_S0_R2_P
    { 428,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #428 = CVT_D3_S0_R2
    { 427,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #427 = CVT_D3_S0_R0_P
    { 426,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #426 = CVT_D3_S0_R0
    { 425,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #425 = CVT_D2_S3_R0_P
    { 424,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #424 = CVT_D2_S3_R0
    { 423,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #423 = CVT_D2_S1_R3_P
    { 422,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #422 = CVT_D2_S1_R3
    { 421,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #421 = CVT_D2_S1_R2_P
    { 420,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #420 = CVT_D2_S1_R2
    { 419,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #419 = CVT_D2_S1_R1_P
    { 418,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #418 = CVT_D2_S1_R1
    { 417,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #417 = CVT_D2_S1_R0_P
    { 416,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #416 = CVT_D2_S1_R0
    { 415,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #415 = CVT_D2_S0_R3_P
    { 414,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #414 = CVT_D2_S0_R3
    { 413,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #413 = CVT_D2_S0_R2_P
    { 412,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #412 = CVT_D2_S0_R2
    { 411,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #411 = CVT_D2_S0_R0_P
    { 410,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #410 = CVT_D2_S0_R0
    { 409,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #409 = CVT_D1_S3_R3_P
    { 408,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #408 = CVT_D1_S3_R3
    { 407,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #407 = CVT_D1_S3_R2_P
    { 406,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #406 = CVT_D1_S3_R2
    { 405,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #405 = CVT_D1_S3_R1_P
    { 404,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #404 = CVT_D1_S3_R1
    { 403,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #403 = CVT_D1_S3_R0_P
    { 402,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #402 = CVT_D1_S3_R0
    { 401,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #401 = CVT_D1_S2_R3_P
    { 400,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #400 = CVT_D1_S2_R3
    { 399,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #399 = CVT_D1_S2_R2_P
    { 398,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #398 = CVT_D1_S2_R2
    { 397,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #397 = CVT_D1_S2_R1_P
    { 396,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #396 = CVT_D1_S2_R1
    { 395,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #395 = CVT_D1_S2_R0_P
    { 394,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #394 = CVT_D1_S2_R0
    { 393,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #393 = CVT_D1_S1_R3_P
    { 392,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #392 = CVT_D1_S1_R3
    { 391,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #391 = CVT_D1_S1_R2_P
    { 390,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #390 = CVT_D1_S1_R2
    { 389,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #389 = CVT_D1_S1_R1_P
    { 388,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #388 = CVT_D1_S1_R1
    { 387,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #387 = CVT_D1_S1_R0_P
    { 386,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #386 = CVT_D1_S1_R0
    { 385,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #385 = CVT_D1_S0_R3_P
    { 384,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #384 = CVT_D1_S0_R3
    { 383,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #383 = CVT_D1_S0_R2_P
    { 382,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #382 = CVT_D1_S0_R2
    { 381,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #381 = CVT_D1_S0_R1_P
    { 380,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #380 = CVT_D1_S0_R1
    { 379,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #379 = CVT_D1_S0_R0_W8_32
    { 378,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #378 = CVT_D1_S0_R0_P
    { 377,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #377 = CVT_D1_S0_R0
    { 376,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #376 = CVT_D0_S3_R3_P
    { 375,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #375 = CVT_D0_S3_R3
    { 374,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #374 = CVT_D0_S3_R2_P
    { 373,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #373 = CVT_D0_S3_R2
    { 372,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #372 = CVT_D0_S3_R1_P
    { 371,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #371 = CVT_D0_S3_R1
    { 370,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #370 = CVT_D0_S2_R3_P
    { 369,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #369 = CVT_D0_S2_R3
    { 368,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #368 = CVT_D0_S2_R2_P
    { 367,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #367 = CVT_D0_S2_R2
    { 366,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #366 = CVT_D0_S2_R1_P
    { 365,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #365 = CVT_D0_S2_R1
    { 364,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #364 = CVT_D0_S1_R3_P
    { 363,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #363 = CVT_D0_S1_R3
    { 362,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #362 = CVT_D0_S1_R2_P
    { 361,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #361 = CVT_D0_S1_R2
    { 360,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #360 = CVT_D0_S1_R1_P
    { 359,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #359 = CVT_D0_S1_R1
    { 358,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #358 = CVT_D0_S1_R0_W32_8
    { 357,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	238,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #357 = CVT_D0_S1_R0_W16_8
    { 356,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #356 = CVT_D0_S1_R0_P
    { 355,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #355 = CVT_D0_S1_R0
    { 354,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #354 = CVT_D0_S0_R3_P
    { 353,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #353 = CVT_D0_S0_R3
    { 352,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #352 = CVT_D0_S0_R2_P
    { 351,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #351 = CVT_D0_S0_R2
    { 350,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #350 = CVT_D0_S0_R1_P
    { 349,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #349 = CVT_D0_S0_R1
    { 348,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	258,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #348 = CVT_D0_S0_R0_W8_32
    { 347,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	254,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #347 = CVT_D0_S0_R0_W4_32
    { 346,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	250,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #346 = CVT_D0_S0_R0_W32_8
    { 345,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #345 = CVT_D0_S0_R0_W32_4
    { 344,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #344 = CVT_D0_S0_R0_W32_16
    { 343,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	238,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #343 = CVT_D0_S0_R0_W16_8
    { 342,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	234,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #342 = CVT_D0_S0_R0_W16_32
    { 341,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #341 = CVT_D0_S0_R0_P
    { 340,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #340 = CVT_D0_S0_R0
    { 339,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #339 = COS_F32
    { 338,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #338 = CLZ
    { 337,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #337 = CHWIDTH_MULTI
    { 336,	9,	2,	6,	0,	0,	0,	CCVImpOpBase + 0,	225,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #336 = CAS_S
    { 335,	9,	2,	6,	0,	0,	0,	CCVImpOpBase + 0,	225,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #335 = CAS_G
    { 334,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #334 = CALL
    { 333,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #333 = BREV
    { 332,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	221,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #332 = BRA_PRED
    { 331,	1,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #331 = BRA
    { 330,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	218,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #330 = BAR_WAIT_PHASE
    { 329,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #329 = BAR_INIT
    { 328,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	215,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #328 = BALLOT
    { 327,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #327 = ATOM_XOR_S
    { 326,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #326 = ATOM_XOR_G
    { 325,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #325 = ATOM_OR_S
    { 324,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #324 = ATOM_OR_G
    { 323,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #323 = ATOM_MIN_U_S
    { 322,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #322 = ATOM_MIN_U_G
    { 321,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #321 = ATOM_MIN_S_S
    { 320,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #320 = ATOM_MIN_S_G
    { 319,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #319 = ATOM_MAX_U_S
    { 318,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #318 = ATOM_MAX_U_G
    { 317,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #317 = ATOM_MAX_S_S
    { 316,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #316 = ATOM_MAX_S_G
    { 315,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #315 = ATOM_EXCH_S
    { 314,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #314 = ATOM_EXCH_G
    { 313,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #313 = ATOM_AND_S
    { 312,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #312 = ATOM_AND_G
    { 311,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #311 = ATOM_ADD_S
    { 310,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #310 = ATOM_ADD_G
    { 309,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #309 = ATOM_ADD_F_S
    { 308,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	209,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #308 = ATOM_ADD_F_G
    { 307,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #307 = AND_W16
    { 306,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #306 = AND_P
    { 305,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #305 = ANDNI_P
    { 304,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #304 = ANDNI
    { 303,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #303 = ANDN
    { 302,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #302 = ANDI_P
    { 301,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #301 = ANDI
    { 300,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #300 = AND
    { 299,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	205,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #299 = ADD_W16
    { 298,	6,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	199,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #298 = ADD_PP
    { 297,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #297 = ADD_P
    { 296,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	191,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #296 = ADDI_W16
    { 295,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #295 = ADDI_PP
    { 294,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #294 = ADDI_P
    { 293,	3,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #293 = ADDI48
    { 292,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	179,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #292 = ADDI
    { 291,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #291 = ADD
    { 290,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #290 = ABS
    { 289,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	172,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #289 = PSEUDO_TRUNC16
    { 288,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	154,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #288 = PSEUDO_ST_PRED
    { 287,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #287 = PSEUDO_RET
    { 286,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	164,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #286 = PSEUDO_PXOR
    { 285,	1,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #285 = PSEUDO_PRIVFLOOR
    { 284,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	1,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #284 = PSEUDO_PRIVCHECK
    { 283,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	164,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #283 = PSEUDO_POR
    { 282,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	167,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #282 = PSEUDO_PMOV
    { 281,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	164,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #281 = PSEUDO_PAND
    { 280,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #280 = PSEUDO_PADDI
    { 279,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	157,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #279 = PSEUDO_NARROW
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
    /* 157 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 160 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 164 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 167 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 171 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 172 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 175 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 179 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 182 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 186 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 191 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 194 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 199 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 205 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 209 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 215 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 218 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 221 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 223 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 225 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 234 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 238 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 242 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 246 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 250 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 254 */ { CCV::GPR4RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 258 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 262 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 264 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 267 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 270 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 274 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 278 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 283 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 288 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 293 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 298 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 303 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 308 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 311 */ { CCV::GPR8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 314 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 317 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 319 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 325 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 329 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 332 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 334 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 339 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 343 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 348 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 352 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 355 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
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
  /* 1043 */ "PSEUDO_TRUNC16\0"
  /* 1058 */ "DP2_BF16\0"
  /* 1067 */ "DP2_F16\0"
  /* 1075 */ "SZ_SHARED_LD_S16\0"
  /* 1092 */ "SZ_GLOBAL_LD_S16\0"
  /* 1109 */ "SZ_SHARED_LD_U16\0"
  /* 1126 */ "SZ_GLOBAL_LD_U16\0"
  /* 1143 */ "SZ_GLOBAL_LD_S16_W16\0"
  /* 1164 */ "SZ_GLOBAL_LD_U16_W16\0"
  /* 1185 */ "SZ_GLOBAL_ST_16_W16\0"
  /* 1205 */ "SZ_GLOBAL_LD_S8_W16\0"
  /* 1225 */ "SZ_GLOBAL_LD_U8_W16\0"
  /* 1245 */ "SZ_GLOBAL_ST_8_W16\0"
  /* 1264 */ "SUB_W16\0"
  /* 1272 */ "ADD_W16\0"
  /* 1280 */ "LD_SHARED_W16\0"
  /* 1294 */ "ST_SHARED_W16\0"
  /* 1308 */ "AND_W16\0"
  /* 1316 */ "ADDI_W16\0"
  /* 1325 */ "LD_GLOBAL_W16\0"
  /* 1339 */ "ST_GLOBAL_W16\0"
  /* 1353 */ "XOR_W16\0"
  /* 1361 */ "MIN_S_W16\0"
  /* 1371 */ "MAX_S_W16\0"
  /* 1381 */ "LD_GLOBAL_SLOT_W16\0"
  /* 1400 */ "ST_GLOBAL_SLOT_W16\0"
  /* 1419 */ "LD_GLOBAL_IDX_W16\0"
  /* 1437 */ "ST_GLOBAL_IDX_W16\0"
  /* 1455 */ "CVT_D0_S0_R0_W32_16\0"
  /* 1475 */ "SZ_SHARED_ST_16\0"
  /* 1491 */ "SZ_GLOBAL_ST_16\0"
  /* 1507 */ "ADDI48\0"
  /* 1514 */ "MOVI48\0"
  /* 1521 */ "SZ_SHARED_LD_S8\0"
  /* 1537 */ "SZ_GLOBAL_LD_S8\0"
  /* 1553 */ "SZ_SHARED_LD_U8\0"
  /* 1569 */ "SZ_GLOBAL_LD_U8\0"
  /* 1585 */ "FSUB_F1_W8\0"
  /* 1596 */ "FADD_F1_W8\0"
  /* 1607 */ "FMUL_F1_W8\0"
  /* 1618 */ "FSUB_W8\0"
  /* 1626 */ "FADD_W8\0"
  /* 1634 */ "LD_SHARED_W8\0"
  /* 1647 */ "ST_SHARED_W8\0"
  /* 1660 */ "LD_GLOBAL_W8\0"
  /* 1673 */ "ST_GLOBAL_W8\0"
  /* 1686 */ "FMUL_W8\0"
  /* 1694 */ "LD_GLOBAL_SLOT_W8\0"
  /* 1712 */ "ST_GLOBAL_SLOT_W8\0"
  /* 1730 */ "LD_GLOBAL_IDX_W8\0"
  /* 1747 */ "ST_GLOBAL_IDX_W8\0"
  /* 1764 */ "CVT_D0_S0_R0_W32_8\0"
  /* 1783 */ "CVT_D0_S1_R0_W32_8\0"
  /* 1802 */ "CVT_D0_S0_R0_W16_8\0"
  /* 1821 */ "CVT_D0_S1_R0_W16_8\0"
  /* 1840 */ "SZ_SHARED_ST_8\0"
  /* 1855 */ "SZ_GLOBAL_ST_8\0"
  /* 1870 */ "G_FMA\0"
  /* 1876 */ "G_STRICT_FMA\0"
  /* 1889 */ "C_BRA\0"
  /* 1895 */ "C_SRA\0"
  /* 1901 */ "G_FSUB\0"
  /* 1908 */ "G_STRICT_FSUB\0"
  /* 1922 */ "G_ATOMICRMW_FSUB\0"
  /* 1939 */ "C_SUB\0"
  /* 1945 */ "G_SUB\0"
  /* 1951 */ "G_ATOMICRMW_SUB\0"
  /* 1967 */ "DP4_ACC\0"
  /* 1975 */ "MAD_ACC\0"
  /* 1983 */ "G_INTRINSIC\0"
  /* 1995 */ "G_FPTRUNC\0"
  /* 2005 */ "G_INTRINSIC_TRUNC\0"
  /* 2023 */ "G_TRUNC\0"
  /* 2031 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 2052 */ "G_DYN_STACKALLOC\0"
  /* 2069 */ "POPC\0"
  /* 2074 */ "G_FMAD\0"
  /* 2081 */ "G_INDEXED_SEXTLOAD\0"
  /* 2100 */ "G_SEXTLOAD\0"
  /* 2111 */ "G_INDEXED_ZEXTLOAD\0"
  /* 2130 */ "G_ZEXTLOAD\0"
  /* 2141 */ "G_INDEXED_LOAD\0"
  /* 2156 */ "G_LOAD\0"
  /* 2163 */ "C_FADD\0"
  /* 2170 */ "G_VECREDUCE_FADD\0"
  /* 2187 */ "G_FADD\0"
  /* 2194 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 2215 */ "G_STRICT_FADD\0"
  /* 2229 */ "G_ATOMICRMW_FADD\0"
  /* 2246 */ "C_ADD\0"
  /* 2252 */ "G_VECREDUCE_ADD\0"
  /* 2268 */ "G_ADD\0"
  /* 2274 */ "G_PTR_ADD\0"
  /* 2284 */ "G_ATOMICRMW_ADD\0"
  /* 2300 */ "LD_SHARED\0"
  /* 2310 */ "ST_SHARED\0"
  /* 2320 */ "PSEUDO_BRA_PRED\0"
  /* 2336 */ "PSEUDO_LD_PRED\0"
  /* 2351 */ "PSEUDO_ST_PRED\0"
  /* 2366 */ "G_ATOMICRMW_NAND\0"
  /* 2383 */ "PSEUDO_PAND\0"
  /* 2395 */ "C_AND\0"
  /* 2401 */ "G_VECREDUCE_AND\0"
  /* 2417 */ "G_AND\0"
  /* 2423 */ "G_ATOMICRMW_AND\0"
  /* 2439 */ "LIFETIME_END\0"
  /* 2452 */ "G_BRCOND\0"
  /* 2461 */ "G_LLROUND\0"
  /* 2471 */ "G_LROUND\0"
  /* 2480 */ "G_INTRINSIC_ROUND\0"
  /* 2498 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 2524 */ "LOAD_STACK_GUARD\0"
  /* 2541 */ "SRD\0"
  /* 2545 */ "PSEUDO_PROBE\0"
  /* 2558 */ "G_SSUBE\0"
  /* 2566 */ "G_USUBE\0"
  /* 2574 */ "C_FENCE\0"
  /* 2582 */ "G_FENCE\0"
  /* 2590 */ "ARITH_FENCE\0"
  /* 2602 */ "REG_SEQUENCE\0"
  /* 2615 */ "G_SADDE\0"
  /* 2623 */ "G_UADDE\0"
  /* 2631 */ "G_GET_FPMODE\0"
  /* 2644 */ "G_RESET_FPMODE\0"
  /* 2659 */ "G_SET_FPMODE\0"
  /* 2672 */ "G_FMINNUM_IEEE\0"
  /* 2687 */ "G_FMAXNUM_IEEE\0"
  /* 2702 */ "SETP_GE\0"
  /* 2710 */ "G_JUMP_TABLE\0"
  /* 2723 */ "BUNDLE\0"
  /* 2730 */ "SETP_LE\0"
  /* 2738 */ "G_MEMCPY_INLINE\0"
  /* 2754 */ "SETP_NE\0"
  /* 2762 */ "LOCAL_ESCAPE\0"
  /* 2775 */ "G_STACKRESTORE\0"
  /* 2790 */ "G_INDEXED_STORE\0"
  /* 2806 */ "G_STORE\0"
  /* 2814 */ "BAR_WAIT_PHASE\0"
  /* 2829 */ "G_BITREVERSE\0"
  /* 2842 */ "DBG_VALUE\0"
  /* 2852 */ "G_GLOBAL_VALUE\0"
  /* 2867 */ "G_STACKSAVE\0"
  /* 2879 */ "C_BAR_ARRIVE\0"
  /* 2892 */ "G_MEMMOVE\0"
  /* 2902 */ "G_FREEZE\0"
  /* 2911 */ "G_FCANONICALIZE\0"
  /* 2927 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 2945 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 2963 */ "G_IMPLICIT_DEF\0"
  /* 2978 */ "DBG_INSTR_REF\0"
  /* 2992 */ "SETP_GE_F\0"
  /* 3002 */ "SETP_LE_F\0"
  /* 3012 */ "SETP_NE_F\0"
  /* 3022 */ "SETP_EQ_F\0"
  /* 3032 */ "SETP_GT_F\0"
  /* 3042 */ "SETP_LT_F\0"
  /* 3052 */ "G_FNEG\0"
  /* 3059 */ "C_NEG\0"
  /* 3065 */ "EXTRACT_SUBREG\0"
  /* 3080 */ "INSERT_SUBREG\0"
  /* 3094 */ "G_SEXT_INREG\0"
  /* 3107 */ "SUBREG_TO_REG\0"
  /* 3121 */ "G_ATOMIC_CMPXCHG\0"
  /* 3138 */ "G_ATOMICRMW_XCHG\0"
  /* 3155 */ "G_FLOG\0"
  /* 3162 */ "G_VAARG\0"
  /* 3170 */ "PREALLOCATED_ARG\0"
  /* 3187 */ "ATOM_ADD_G\0"
  /* 3198 */ "LD_PRED_G\0"
  /* 3208 */ "ST_PRED_G\0"
  /* 3218 */ "ATOM_AND_G\0"
  /* 3229 */ "ATOM_ADD_F_G\0"
  /* 3242 */ "ATOM_EXCH_G\0"
  /* 3254 */ "ATOM_XOR_G\0"
  /* 3265 */ "ATOM_OR_G\0"
  /* 3275 */ "PSEUDO_CAS_G\0"
  /* 3288 */ "ATOM_MIN_S_G\0"
  /* 3301 */ "ATOM_MAX_S_G\0"
  /* 3314 */ "ATOM_MIN_U_G\0"
  /* 3327 */ "ATOM_MAX_U_G\0"
  /* 3340 */ "G_PREFETCH\0"
  /* 3351 */ "G_SMULH\0"
  /* 3359 */ "G_UMULH\0"
  /* 3367 */ "C_CHWIDTH\0"
  /* 3377 */ "C_SRAI\0"
  /* 3384 */ "C_SUBI\0"
  /* 3391 */ "PSEUDO_PADDI\0"
  /* 3404 */ "C_ADDI\0"
  /* 3411 */ "C_ANDI\0"
  /* 3418 */ "DBG_PHI\0"
  /* 3426 */ "UNPACKI\0"
  /* 3434 */ "C_SHLI\0"
  /* 3441 */ "MULI\0"
  /* 3446 */ "ANDNI\0"
  /* 3452 */ "SETP_GE_NPI\0"
  /* 3464 */ "SETP_LE_NPI\0"
  /* 3476 */ "SETP_NE_NPI\0"
  /* 3488 */ "SETP_GE_F_NPI\0"
  /* 3502 */ "SETP_LE_F_NPI\0"
  /* 3516 */ "SETP_NE_F_NPI\0"
  /* 3530 */ "SETP_EQ_F_NPI\0"
  /* 3544 */ "SETP_GT_F_NPI\0"
  /* 3558 */ "SETP_LT_F_NPI\0"
  /* 3572 */ "SETP_EQ_NPI\0"
  /* 3584 */ "SETP_GT_NPI\0"
  /* 3596 */ "SETP_LT_NPI\0"
  /* 3608 */ "SETP_GE_U_NPI\0"
  /* 3622 */ "SETP_LE_U_NPI\0"
  /* 3636 */ "SETP_GT_U_NPI\0"
  /* 3650 */ "SETP_LT_U_NPI\0"
  /* 3664 */ "C_SHRI\0"
  /* 3671 */ "C_XORI\0"
  /* 3678 */ "C_ORI\0"
  /* 3684 */ "G_FPTOSI\0"
  /* 3693 */ "CHWIDTH_MULTI\0"
  /* 3707 */ "G_FPTOUI\0"
  /* 3716 */ "MOVI\0"
  /* 3721 */ "G_FPOWI\0"
  /* 3729 */ "SETP_GE_I\0"
  /* 3739 */ "SETP_LE_I\0"
  /* 3749 */ "SETP_NE_I\0"
  /* 3759 */ "SETP_GE_F_I\0"
  /* 3771 */ "SETP_LE_F_I\0"
  /* 3783 */ "SETP_NE_F_I\0"
  /* 3795 */ "SETP_EQ_F_I\0"
  /* 3807 */ "SETP_GT_F_I\0"
  /* 3819 */ "SETP_LT_F_I\0"
  /* 3831 */ "SETP_EQ_I\0"
  /* 3841 */ "SETP_GT_I\0"
  /* 3851 */ "SETP_LT_I\0"
  /* 3861 */ "SETP_GE_U_I\0"
  /* 3873 */ "SETP_LE_U_I\0"
  /* 3885 */ "SETP_GT_U_I\0"
  /* 3897 */ "SETP_LT_U_I\0"
  /* 3909 */ "PSEUDO_PRIVCHECK\0"
  /* 3926 */ "G_PTRMASK\0"
  /* 3936 */ "C_LD_GLOBAL\0"
  /* 3948 */ "C_ST_GLOBAL\0"
  /* 3960 */ "LD_PRED_LOCAL\0"
  /* 3974 */ "ST_PRED_LOCAL\0"
  /* 3988 */ "LD_LOCAL\0"
  /* 3997 */ "ST_LOCAL\0"
  /* 4006 */ "GC_LABEL\0"
  /* 4015 */ "DBG_LABEL\0"
  /* 4025 */ "EH_LABEL\0"
  /* 4034 */ "ANNOTATION_LABEL\0"
  /* 4051 */ "ICALL_BRANCH_FUNNEL\0"
  /* 4071 */ "SEL\0"
  /* 4075 */ "G_FSHL\0"
  /* 4082 */ "C_SHL\0"
  /* 4088 */ "G_SHL\0"
  /* 4094 */ "G_FCEIL\0"
  /* 4102 */ "PATCHABLE_TAIL_CALL\0"
  /* 4122 */ "PSEUDO_CALL\0"
  /* 4134 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 4161 */ "PATCHABLE_EVENT_CALL\0"
  /* 4182 */ "FENTRY_CALL\0"
  /* 4194 */ "KILL\0"
  /* 4199 */ "G_CONSTANT_POOL\0"
  /* 4215 */ "G_ROTL\0"
  /* 4222 */ "C_FMUL\0"
  /* 4229 */ "G_VECREDUCE_FMUL\0"
  /* 4246 */ "G_FMUL\0"
  /* 4253 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 4274 */ "G_STRICT_FMUL\0"
  /* 4288 */ "G_VECREDUCE_MUL\0"
  /* 4304 */ "G_MUL\0"
  /* 4310 */ "G_FREM\0"
  /* 4317 */ "G_STRICT_FREM\0"
  /* 4331 */ "G_SREM\0"
  /* 4338 */ "G_UREM\0"
  /* 4345 */ "G_SDIVREM\0"
  /* 4355 */ "G_UDIVREM\0"
  /* 4365 */ "PMOV_IMM\0"
  /* 4374 */ "INLINEASM\0"
  /* 4384 */ "G_VECREDUCE_FMINIMUM\0"
  /* 4405 */ "G_FMINIMUM\0"
  /* 4416 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 4437 */ "G_FMAXIMUM\0"
  /* 4448 */ "G_FMINNUM\0"
  /* 4458 */ "G_FMAXNUM\0"
  /* 4468 */ "C_ANDN\0"
  /* 4475 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 4497 */ "G_ASSERT_ALIGN\0"
  /* 4512 */ "G_FCOPYSIGN\0"
  /* 4524 */ "C_FMIN\0"
  /* 4531 */ "G_VECREDUCE_FMIN\0"
  /* 4548 */ "G_ATOMICRMW_FMIN\0"
  /* 4565 */ "G_VECREDUCE_SMIN\0"
  /* 4582 */ "G_SMIN\0"
  /* 4589 */ "G_VECREDUCE_UMIN\0"
  /* 4606 */ "G_UMIN\0"
  /* 4613 */ "G_ATOMICRMW_UMIN\0"
  /* 4630 */ "G_ATOMICRMW_MIN\0"
  /* 4646 */ "G_FSIN\0"
  /* 4653 */ "CFI_INSTRUCTION\0"
  /* 4669 */ "ADJCALLSTACKDOWN\0"
  /* 4686 */ "G_SSUBO\0"
  /* 4694 */ "G_USUBO\0"
  /* 4702 */ "G_SADDO\0"
  /* 4710 */ "G_UADDO\0"
  /* 4718 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 4740 */ "MADLO\0"
  /* 4746 */ "G_SMULO\0"
  /* 4754 */ "G_UMULO\0"
  /* 4762 */ "C_MUL_LO\0"
  /* 4771 */ "G_BZERO\0"
  /* 4779 */ "STACKMAP\0"
  /* 4788 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 4810 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 4832 */ "G_BSWAP\0"
  /* 4840 */ "G_SITOFP\0"
  /* 4849 */ "G_UITOFP\0"
  /* 4858 */ "G_FCMP\0"
  /* 4865 */ "G_ICMP\0"
  /* 4872 */ "SETP_GE_F1_NP\0"
  /* 4886 */ "SETP_LE_F1_NP\0"
  /* 4900 */ "SETP_NE_F1_NP\0"
  /* 4914 */ "SETP_EQ_F1_NP\0"
  /* 4928 */ "SETP_GT_F1_NP\0"
  /* 4942 */ "SETP_LT_F1_NP\0"
  /* 4956 */ "SETP_GE_NP\0"
  /* 4967 */ "SETP_LE_NP\0"
  /* 4978 */ "SETP_NE_NP\0"
  /* 4989 */ "SETP_GE_F_NP\0"
  /* 5002 */ "SETP_LE_F_NP\0"
  /* 5015 */ "SETP_NE_F_NP\0"
  /* 5028 */ "SETP_EQ_F_NP\0"
  /* 5041 */ "SETP_GT_F_NP\0"
  /* 5054 */ "SETP_LT_F_NP\0"
  /* 5067 */ "SETP_EQ_NP\0"
  /* 5078 */ "SETP_GT_NP\0"
  /* 5089 */ "SETP_LT_NP\0"
  /* 5100 */ "SETP_GE_U_NP\0"
  /* 5113 */ "SETP_LE_U_NP\0"
  /* 5126 */ "SETP_GT_U_NP\0"
  /* 5139 */ "SETP_LT_U_NP\0"
  /* 5152 */ "G_CTPOP\0"
  /* 5160 */ "PATCHABLE_OP\0"
  /* 5173 */ "FAULTING_OP\0"
  /* 5185 */ "ADD_PP\0"
  /* 5192 */ "ADDI_PP\0"
  /* 5200 */ "ADJCALLSTACKUP\0"
  /* 5215 */ "PREALLOCATED_SETUP\0"
  /* 5234 */ "G_FLDEXP\0"
  /* 5243 */ "G_STRICT_FLDEXP\0"
  /* 5259 */ "G_FEXP\0"
  /* 5266 */ "G_FFREXP\0"
  /* 5275 */ "CVT_D0_S0_R0_P\0"
  /* 5290 */ "CVT_D1_S0_R0_P\0"
  /* 5305 */ "CVT_D2_S0_R0_P\0"
  /* 5320 */ "CVT_D3_S0_R0_P\0"
  /* 5335 */ "CVT_D0_S1_R0_P\0"
  /* 5350 */ "CVT_D1_S1_R0_P\0"
  /* 5365 */ "CVT_D2_S1_R0_P\0"
  /* 5380 */ "CVT_D3_S1_R0_P\0"
  /* 5395 */ "CVT_D1_S2_R0_P\0"
  /* 5410 */ "CVT_D3_S2_R0_P\0"
  /* 5425 */ "CVT_D1_S3_R0_P\0"
  /* 5440 */ "CVT_D2_S3_R0_P\0"
  /* 5455 */ "CVT_D3_S3_R0_P\0"
  /* 5470 */ "CVT_D0_S0_R1_P\0"
  /* 5485 */ "CVT_D1_S0_R1_P\0"
  /* 5500 */ "CVT_D0_S1_R1_P\0"
  /* 5515 */ "CVT_D1_S1_R1_P\0"
  /* 5530 */ "CVT_D2_S1_R1_P\0"
  /* 5545 */ "CVT_D3_S1_R1_P\0"
  /* 5560 */ "CVT_D0_S2_R1_P\0"
  /* 5575 */ "CVT_D1_S2_R1_P\0"
  /* 5590 */ "CVT_D0_S3_R1_P\0"
  /* 5605 */ "CVT_D1_S3_R1_P\0"
  /* 5620 */ "CVT_S32_F32_P\0"
  /* 5634 */ "CVT_U32_F32_P\0"
  /* 5648 */ "RCP_F32_P\0"
  /* 5658 */ "CVT_F32_S32_P\0"
  /* 5672 */ "CVT_F32_U32_P\0"
  /* 5686 */ "CVT_D0_S0_R2_P\0"
  /* 5701 */ "CVT_D1_S0_R2_P\0"
  /* 5716 */ "CVT_D2_S0_R2_P\0"
  /* 5731 */ "CVT_D3_S0_R2_P\0"
  /* 5746 */ "CVT_D0_S1_R2_P\0"
  /* 5761 */ "CVT_D1_S1_R2_P\0"
  /* 5776 */ "CVT_D2_S1_R2_P\0"
  /* 5791 */ "CVT_D3_S1_R2_P\0"
  /* 5806 */ "CVT_D0_S2_R2_P\0"
  /* 5821 */ "CVT_D1_S2_R2_P\0"
  /* 5836 */ "CVT_D0_S3_R2_P\0"
  /* 5851 */ "CVT_D1_S3_R2_P\0"
  /* 5866 */ "CVT_D0_S0_R3_P\0"
  /* 5881 */ "CVT_D1_S0_R3_P\0"
  /* 5896 */ "CVT_D2_S0_R3_P\0"
  /* 5911 */ "CVT_D3_S0_R3_P\0"
  /* 5926 */ "CVT_D0_S1_R3_P\0"
  /* 5941 */ "CVT_D1_S1_R3_P\0"
  /* 5956 */ "CVT_D2_S1_R3_P\0"
  /* 5971 */ "CVT_D3_S1_R3_P\0"
  /* 5986 */ "CVT_D0_S2_R3_P\0"
  /* 6001 */ "CVT_D1_S2_R3_P\0"
  /* 6016 */ "CVT_D0_S3_R3_P\0"
  /* 6031 */ "CVT_D1_S3_R3_P\0"
  /* 6046 */ "SRA_P\0"
  /* 6052 */ "FSUB_P\0"
  /* 6059 */ "FADD_P\0"
  /* 6066 */ "AND_P\0"
  /* 6072 */ "SRAI_P\0"
  /* 6079 */ "SUBI_P\0"
  /* 6086 */ "ADDI_P\0"
  /* 6093 */ "ANDI_P\0"
  /* 6100 */ "SHLI_P\0"
  /* 6107 */ "MULI_P\0"
  /* 6114 */ "ANDNI_P\0"
  /* 6122 */ "SHRI_P\0"
  /* 6129 */ "XORI_P\0"
  /* 6136 */ "LD_GLOBAL_P\0"
  /* 6148 */ "SHL_P\0"
  /* 6154 */ "FMUL_P\0"
  /* 6161 */ "MADLO_P\0"
  /* 6169 */ "SHR_P\0"
  /* 6175 */ "XOR_P\0"
  /* 6181 */ "MUL_HI_S_P\0"
  /* 6192 */ "MIN_S_P\0"
  /* 6200 */ "MAX_S_P\0"
  /* 6208 */ "MUL_HI_U_P\0"
  /* 6219 */ "MIN_U_P\0"
  /* 6227 */ "MAX_U_P\0"
  /* 6235 */ "MOV_P\0"
  /* 6241 */ "SETP_EQ\0"
  /* 6249 */ "G_BR\0"
  /* 6254 */ "INLINEASM_BR\0"
  /* 6267 */ "G_BLOCK_ADDR\0"
  /* 6280 */ "MEMBARRIER\0"
  /* 6291 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 6315 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 6340 */ "G_READCYCLECOUNTER\0"
  /* 6359 */ "G_READ_REGISTER\0"
  /* 6375 */ "G_WRITE_REGISTER\0"
  /* 6392 */ "G_ASHR\0"
  /* 6399 */ "G_FSHR\0"
  /* 6406 */ "G_LSHR\0"
  /* 6413 */ "C_SHR\0"
  /* 6419 */ "G_FFLOOR\0"
  /* 6428 */ "PSEUDO_PRIVFLOOR\0"
  /* 6445 */ "PSEUDO_POR\0"
  /* 6456 */ "G_BUILD_VECTOR\0"
  /* 6471 */ "G_SHUFFLE_VECTOR\0"
  /* 6488 */ "PSEUDO_PXOR\0"
  /* 6500 */ "C_XOR\0"
  /* 6506 */ "G_VECREDUCE_XOR\0"
  /* 6522 */ "G_XOR\0"
  /* 6528 */ "G_ATOMICRMW_XOR\0"
  /* 6544 */ "C_OR\0"
  /* 6549 */ "G_VECREDUCE_OR\0"
  /* 6564 */ "G_OR\0"
  /* 6569 */ "G_ATOMICRMW_OR\0"
  /* 6584 */ "G_ROTR\0"
  /* 6591 */ "G_INTTOPTR\0"
  /* 6602 */ "G_FABS\0"
  /* 6609 */ "C_ABS\0"
  /* 6615 */ "G_ABS\0"
  /* 6621 */ "G_UNMERGE_VALUES\0"
  /* 6638 */ "G_MERGE_VALUES\0"
  /* 6653 */ "G_FCOS\0"
  /* 6660 */ "G_CONCAT_VECTORS\0"
  /* 6677 */ "COPY_TO_REGCLASS\0"
  /* 6694 */ "G_IS_FPCLASS\0"
  /* 6707 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 6737 */ "DP4_SS\0"
  /* 6744 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 6771 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 6809 */ "ATOM_ADD_S\0"
  /* 6820 */ "LD_PRED_S\0"
  /* 6830 */ "ST_PRED_S\0"
  /* 6840 */ "ATOM_AND_S\0"
  /* 6851 */ "ATOM_ADD_F_S\0"
  /* 6864 */ "ATOM_EXCH_S\0"
  /* 6876 */ "MUL_HI_S\0"
  /* 6885 */ "C_MIN_S\0"
  /* 6893 */ "ATOM_XOR_S\0"
  /* 6904 */ "ATOM_OR_S\0"
  /* 6914 */ "PSEUDO_CAS_S\0"
  /* 6927 */ "ATOM_MIN_S_S\0"
  /* 6940 */ "ATOM_MAX_S_S\0"
  /* 6953 */ "ATOM_MIN_U_S\0"
  /* 6966 */ "ATOM_MAX_U_S\0"
  /* 6979 */ "C_MAX_S\0"
  /* 6987 */ "G_SSUBSAT\0"
  /* 6997 */ "G_USUBSAT\0"
  /* 7007 */ "G_SADDSAT\0"
  /* 7017 */ "G_UADDSAT\0"
  /* 7027 */ "G_SSHLSAT\0"
  /* 7037 */ "G_USHLSAT\0"
  /* 7047 */ "G_SMULFIXSAT\0"
  /* 7060 */ "G_UMULFIXSAT\0"
  /* 7073 */ "G_SDIVFIXSAT\0"
  /* 7086 */ "G_UDIVFIXSAT\0"
  /* 7099 */ "G_EXTRACT\0"
  /* 7109 */ "G_SELECT\0"
  /* 7118 */ "G_BRINDIRECT\0"
  /* 7131 */ "C_RET\0"
  /* 7137 */ "PATCHABLE_RET\0"
  /* 7151 */ "PSEUDO_RET\0"
  /* 7162 */ "G_MEMSET\0"
  /* 7171 */ "SETP_GT\0"
  /* 7179 */ "C_BAR_WAIT\0"
  /* 7190 */ "BAR_INIT\0"
  /* 7199 */ "C_EXIT\0"
  /* 7206 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 7230 */ "G_BRJT\0"
  /* 7237 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 7258 */ "G_INSERT_VECTOR_ELT\0"
  /* 7278 */ "SETP_LT\0"
  /* 7286 */ "G_FCONSTANT\0"
  /* 7298 */ "G_CONSTANT\0"
  /* 7309 */ "G_INTRINSIC_CONVERGENT\0"
  /* 7332 */ "STATEPOINT\0"
  /* 7343 */ "PATCHPOINT\0"
  /* 7354 */ "G_PTRTOINT\0"
  /* 7365 */ "G_FRINT\0"
  /* 7373 */ "G_INTRINSIC_LRINT\0"
  /* 7391 */ "G_FNEARBYINT\0"
  /* 7404 */ "UNBALLOT\0"
  /* 7413 */ "LD_GLOBAL_SLOT\0"
  /* 7428 */ "ST_GLOBAL_SLOT\0"
  /* 7443 */ "C_NOT\0"
  /* 7449 */ "G_VASTART\0"
  /* 7459 */ "LIFETIME_START\0"
  /* 7474 */ "G_INVOKE_REGION_START\0"
  /* 7496 */ "G_INSERT\0"
  /* 7505 */ "G_FSQRT\0"
  /* 7513 */ "G_STRICT_FSQRT\0"
  /* 7528 */ "PSEUDO_BCAST\0"
  /* 7541 */ "G_BITCAST\0"
  /* 7551 */ "G_ADDRSPACE_CAST\0"
  /* 7568 */ "DBG_VALUE_LIST\0"
  /* 7583 */ "G_FPEXT\0"
  /* 7591 */ "G_SEXT\0"
  /* 7598 */ "G_ASSERT_SEXT\0"
  /* 7612 */ "CVT_SEXT\0"
  /* 7621 */ "G_ANYEXT\0"
  /* 7630 */ "G_ZEXT\0"
  /* 7637 */ "G_ASSERT_ZEXT\0"
  /* 7651 */ "SETP_GE_U\0"
  /* 7661 */ "SETP_LE_U\0"
  /* 7671 */ "MUL_HI_U\0"
  /* 7680 */ "C_MIN_U\0"
  /* 7688 */ "SETP_GT_U\0"
  /* 7698 */ "SETP_LT_U\0"
  /* 7708 */ "C_MAX_U\0"
  /* 7716 */ "BREV\0"
  /* 7721 */ "G_FDIV\0"
  /* 7728 */ "G_STRICT_FDIV\0"
  /* 7742 */ "G_SDIV\0"
  /* 7749 */ "G_UDIV\0"
  /* 7756 */ "G_GET_FPENV\0"
  /* 7768 */ "G_RESET_FPENV\0"
  /* 7782 */ "G_SET_FPENV\0"
  /* 7794 */ "C_RECONV\0"
  /* 7803 */ "PSEUDO_PMOV\0"
  /* 7815 */ "C_MOV\0"
  /* 7821 */ "G_FPOW\0"
  /* 7828 */ "PSEUDO_NARROW\0"
  /* 7842 */ "C_FMAX\0"
  /* 7849 */ "G_VECREDUCE_FMAX\0"
  /* 7866 */ "G_ATOMICRMW_FMAX\0"
  /* 7883 */ "G_VECREDUCE_SMAX\0"
  /* 7900 */ "G_SMAX\0"
  /* 7907 */ "G_VECREDUCE_UMAX\0"
  /* 7924 */ "G_UMAX\0"
  /* 7931 */ "G_ATOMICRMW_UMAX\0"
  /* 7948 */ "G_ATOMICRMW_MAX\0"
  /* 7964 */ "LD_SHARED_IDX\0"
  /* 7978 */ "ST_SHARED_IDX\0"
  /* 7992 */ "LD_GLOBAL_IDX\0"
  /* 8006 */ "ST_GLOBAL_IDX\0"
  /* 8020 */ "SHFL_IDX\0"
  /* 8029 */ "G_FRAME_INDEX\0"
  /* 8043 */ "G_SBFX\0"
  /* 8050 */ "G_UBFX\0"
  /* 8057 */ "G_SMULFIX\0"
  /* 8067 */ "G_UMULFIX\0"
  /* 8077 */ "G_SDIVFIX\0"
  /* 8087 */ "G_UDIVFIX\0"
  /* 8097 */ "VOTE_ANY\0"
  /* 8106 */ "G_MEMCPY\0"
  /* 8115 */ "COPY\0"
  /* 8120 */ "CLZ\0"
  /* 8124 */ "G_CTLZ\0"
  /* 8131 */ "G_CTTZ\0"
  /* 8138 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    3422U, 4374U, 6254U, 4653U, 4025U, 4006U, 4034U, 4194U, 
    3065U, 3080U, 2965U, 3107U, 6677U, 2842U, 7568U, 2978U, 
    3418U, 4015U, 2602U, 8115U, 2723U, 7459U, 2439U, 2545U, 
    2590U, 4779U, 4182U, 7343U, 2524U, 5215U, 3170U, 7332U, 
    2762U, 5173U, 5160U, 6315U, 7137U, 7206U, 4102U, 4161U, 
    4134U, 4051U, 6280U, 4718U, 7598U, 7637U, 4497U, 2268U, 
    1945U, 4304U, 7742U, 7749U, 4331U, 4338U, 4345U, 4355U, 
    2417U, 6564U, 6522U, 2963U, 3420U, 8029U, 2852U, 4199U, 
    7099U, 6621U, 7496U, 6638U, 6456U, 2031U, 6660U, 7354U, 
    6591U, 7541U, 2902U, 6291U, 2498U, 2005U, 2480U, 7373U, 
    4475U, 6340U, 2156U, 2100U, 2130U, 2141U, 2081U, 2111U, 
    2806U, 2790U, 6707U, 3121U, 3138U, 2284U, 1951U, 2423U, 
    2366U, 6569U, 6528U, 7948U, 4630U, 7931U, 4613U, 2229U, 
    1922U, 7866U, 4548U, 4810U, 4788U, 2582U, 3340U, 2452U, 
    7118U, 7474U, 1983U, 6744U, 7309U, 6771U, 7621U, 2023U, 
    7298U, 7286U, 7449U, 3162U, 7591U, 3094U, 7630U, 4088U, 
    6406U, 6392U, 4075U, 6399U, 6584U, 4215U, 4865U, 4858U, 
    7109U, 4710U, 2623U, 4694U, 2566U, 4702U, 2615U, 4686U, 
    2558U, 4754U, 4746U, 3359U, 3351U, 7017U, 7007U, 6997U, 
    6987U, 7037U, 7027U, 8057U, 8067U, 7047U, 7060U, 8077U, 
    8087U, 7073U, 7086U, 2187U, 1901U, 4246U, 1870U, 2074U, 
    7721U, 4310U, 7821U, 3721U, 5259U, 695U, 9U, 3155U, 
    678U, 0U, 5234U, 5266U, 3052U, 7583U, 1995U, 3684U, 
    3707U, 4840U, 4849U, 6602U, 4512U, 6694U, 2911U, 4448U, 
    4458U, 2672U, 2687U, 4405U, 4437U, 7756U, 7782U, 7768U, 
    2631U, 2659U, 2644U, 2274U, 3926U, 4582U, 7900U, 4606U, 
    7924U, 6615U, 2471U, 2461U, 6249U, 7230U, 7258U, 7237U, 
    6471U, 8131U, 2945U, 8124U, 2927U, 5152U, 4832U, 2829U, 
    4094U, 6653U, 4646U, 7505U, 6419U, 7365U, 7391U, 7551U, 
    6267U, 2710U, 2052U, 2867U, 2775U, 2215U, 1908U, 4274U, 
    7728U, 4317U, 1876U, 7513U, 5243U, 6359U, 6375U, 8106U, 
    2738U, 2892U, 7162U, 4771U, 2194U, 4253U, 2170U, 4229U, 
    7849U, 4531U, 4416U, 4384U, 2252U, 4288U, 2401U, 6549U, 
    6506U, 7883U, 4565U, 7907U, 4589U, 8043U, 8050U, 4669U, 
    5200U, 7528U, 2320U, 4122U, 3275U, 6914U, 2336U, 7828U, 
    3391U, 2383U, 7803U, 6445U, 3909U, 6428U, 6488U, 7151U, 
    2351U, 1043U, 6605U, 2166U, 3399U, 1507U, 6086U, 5192U, 
    1316U, 6060U, 5185U, 1272U, 2379U, 3413U, 6093U, 4470U, 
    3446U, 6114U, 6066U, 1308U, 3229U, 6851U, 3187U, 6809U, 
    3218U, 6840U, 3242U, 6864U, 3301U, 6940U, 3327U, 6966U, 
    3288U, 6927U, 3314U, 6953U, 3265U, 6904U, 3254U, 6893U, 
    7406U, 7190U, 2814U, 1891U, 2327U, 7716U, 4117U, 3282U, 
    6921U, 3693U, 8120U, 551U, 54U, 5275U, 620U, 1802U, 
    1455U, 1024U, 1764U, 601U, 640U, 365U, 5470U, 703U, 
    5686U, 868U, 5866U, 106U, 5335U, 1821U, 1783U, 391U, 
    5500U, 755U, 5746U, 920U, 5926U, 443U, 5560U, 807U, 
    5806U, 972U, 5986U, 469U, 5590U, 833U, 5836U, 998U, 
    6016U, 67U, 5290U, 659U, 378U, 5485U, 716U, 5701U, 
    881U, 5881U, 119U, 5350U, 404U, 5515U, 768U, 5761U, 
    933U, 5941U, 158U, 5395U, 456U, 5575U, 820U, 5821U, 
    985U, 6001U, 184U, 5425U, 482U, 5605U, 846U, 5851U, 
    1011U, 6031U, 80U, 5305U, 729U, 5716U, 894U, 5896U, 
    132U, 5365U, 417U, 5530U, 781U, 5776U, 946U, 5956U, 
    197U, 5440U, 93U, 5320U, 742U, 5731U, 907U, 5911U, 
    145U, 5380U, 430U, 5545U, 794U, 5791U, 959U, 5971U, 
    171U, 5410U, 210U, 5455U, 569U, 5658U, 581U, 5672U, 
    495U, 5620U, 7612U, 507U, 5634U, 6609U, 2246U, 3404U, 
    2395U, 3411U, 4468U, 2879U, 7179U, 1889U, 3367U, 7199U, 
    2163U, 2574U, 7842U, 4524U, 4222U, 3936U, 6979U, 7708U, 
    6885U, 7680U, 7815U, 4762U, 3059U, 7443U, 6544U, 3678U, 
    7794U, 7131U, 4082U, 3434U, 6413U, 3664U, 1895U, 3377U, 
    3948U, 1939U, 3384U, 6500U, 3671U, 1058U, 1067U, 1967U, 
    859U, 686U, 6737U, 527U, 46U, 327U, 2165U, 251U, 
    1596U, 6059U, 1626U, 26U, 239U, 18U, 223U, 7844U, 
    357U, 4526U, 308U, 4224U, 300U, 1607U, 6154U, 1686U, 
    38U, 292U, 1903U, 231U, 1585U, 6052U, 1618U, 3938U, 
    7992U, 1419U, 1730U, 6136U, 7413U, 1381U, 1694U, 1325U, 
    1660U, 3988U, 3198U, 3960U, 6820U, 2300U, 7964U, 1280U, 
    1634U, 519U, 4740U, 6161U, 1975U, 6981U, 6200U, 1371U, 
    7710U, 6227U, 6887U, 6192U, 1361U, 7682U, 6219U, 3716U, 
    1514U, 6235U, 3441U, 6107U, 6876U, 6181U, 7671U, 6208U, 
    4764U, 3055U, 6425U, 3674U, 6130U, 6176U, 1354U, 3428U, 
    8138U, 2390U, 7810U, 4365U, 2069U, 6452U, 6495U, 543U, 
    5648U, 593U, 559U, 4071U, 6241U, 3022U, 316U, 4914U, 
    3795U, 5028U, 3530U, 3831U, 5067U, 3572U, 2702U, 2992U, 
    259U, 4872U, 3759U, 4989U, 3488U, 3729U, 4956U, 3452U, 
    7651U, 3861U, 5100U, 3608U, 7171U, 3032U, 335U, 4928U, 
    3807U, 5041U, 3544U, 3841U, 5078U, 3584U, 7688U, 3885U, 
    5126U, 3636U, 2730U, 3002U, 270U, 4886U, 3771U, 5002U, 
    3502U, 3739U, 4967U, 3464U, 7661U, 3873U, 5113U, 3622U, 
    7278U, 3042U, 346U, 4942U, 3819U, 5054U, 3558U, 3851U, 
    5089U, 3596U, 7698U, 3897U, 5139U, 3650U, 2754U, 3012U, 
    281U, 4900U, 3783U, 5015U, 3516U, 3749U, 4978U, 3476U, 
    8020U, 4078U, 3436U, 6100U, 6148U, 6395U, 3666U, 6122U, 
    6169U, 535U, 560U, 1897U, 3379U, 6072U, 6046U, 2541U, 
    3950U, 8006U, 1437U, 1747U, 7428U, 1400U, 1712U, 1339U, 
    1673U, 3997U, 3208U, 3974U, 6830U, 2310U, 7978U, 1294U, 
    1647U, 1904U, 3386U, 6079U, 6053U, 1264U, 1092U, 1143U, 
    1537U, 1205U, 1126U, 1164U, 1569U, 1225U, 1491U, 1185U, 
    1855U, 1245U, 1075U, 1521U, 1109U, 1553U, 1475U, 1840U, 
    7404U, 3426U, 8097U, 6496U, 3673U, 6129U, 6175U, 1353U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 728);
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
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 728);
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
    699,
    /* PSEUDO_PAND */
    703,
    /* PSEUDO_PMOV */
    706,
    /* PSEUDO_POR */
    710,
    /* PSEUDO_PRIVCHECK */
    713,
    /* PSEUDO_PRIVFLOOR */
    714,
    /* PSEUDO_PXOR */
    715,
    /* PSEUDO_RET */
    718,
    /* PSEUDO_ST_PRED */
    719,
    /* PSEUDO_TRUNC16 */
    722,
    /* ABS */
    725,
    /* ADD */
    729,
    /* ADDI */
    733,
    /* ADDI48 */
    736,
    /* ADDI_P */
    739,
    /* ADDI_PP */
    743,
    /* ADDI_W16 */
    748,
    /* ADD_P */
    751,
    /* ADD_PP */
    756,
    /* ADD_W16 */
    762,
    /* AND */
    766,
    /* ANDI */
    770,
    /* ANDI_P */
    773,
    /* ANDN */
    777,
    /* ANDNI */
    781,
    /* ANDNI_P */
    784,
    /* AND_P */
    788,
    /* AND_W16 */
    793,
    /* ATOM_ADD_F_G */
    797,
    /* ATOM_ADD_F_S */
    803,
    /* ATOM_ADD_G */
    809,
    /* ATOM_ADD_S */
    815,
    /* ATOM_AND_G */
    821,
    /* ATOM_AND_S */
    827,
    /* ATOM_EXCH_G */
    833,
    /* ATOM_EXCH_S */
    839,
    /* ATOM_MAX_S_G */
    845,
    /* ATOM_MAX_S_S */
    851,
    /* ATOM_MAX_U_G */
    857,
    /* ATOM_MAX_U_S */
    863,
    /* ATOM_MIN_S_G */
    869,
    /* ATOM_MIN_S_S */
    875,
    /* ATOM_MIN_U_G */
    881,
    /* ATOM_MIN_U_S */
    887,
    /* ATOM_OR_G */
    893,
    /* ATOM_OR_S */
    899,
    /* ATOM_XOR_G */
    905,
    /* ATOM_XOR_S */
    911,
    /* BALLOT */
    917,
    /* BAR_INIT */
    920,
    /* BAR_WAIT_PHASE */
    922,
    /* BRA */
    925,
    /* BRA_PRED */
    926,
    /* BREV */
    928,
    /* CALL */
    932,
    /* CAS_G */
    934,
    /* CAS_S */
    943,
    /* CHWIDTH_MULTI */
    952,
    /* CLZ */
    954,
    /* COS_F32 */
    958,
    /* CVT_D0_S0_R0 */
    962,
    /* CVT_D0_S0_R0_P */
    966,
    /* CVT_D0_S0_R0_W16_32 */
    971,
    /* CVT_D0_S0_R0_W16_8 */
    975,
    /* CVT_D0_S0_R0_W32_16 */
    979,
    /* CVT_D0_S0_R0_W32_4 */
    983,
    /* CVT_D0_S0_R0_W32_8 */
    987,
    /* CVT_D0_S0_R0_W4_32 */
    991,
    /* CVT_D0_S0_R0_W8_32 */
    995,
    /* CVT_D0_S0_R1 */
    999,
    /* CVT_D0_S0_R1_P */
    1003,
    /* CVT_D0_S0_R2 */
    1008,
    /* CVT_D0_S0_R2_P */
    1012,
    /* CVT_D0_S0_R3 */
    1017,
    /* CVT_D0_S0_R3_P */
    1021,
    /* CVT_D0_S1_R0 */
    1026,
    /* CVT_D0_S1_R0_P */
    1030,
    /* CVT_D0_S1_R0_W16_8 */
    1035,
    /* CVT_D0_S1_R0_W32_8 */
    1039,
    /* CVT_D0_S1_R1 */
    1043,
    /* CVT_D0_S1_R1_P */
    1047,
    /* CVT_D0_S1_R2 */
    1052,
    /* CVT_D0_S1_R2_P */
    1056,
    /* CVT_D0_S1_R3 */
    1061,
    /* CVT_D0_S1_R3_P */
    1065,
    /* CVT_D0_S2_R1 */
    1070,
    /* CVT_D0_S2_R1_P */
    1074,
    /* CVT_D0_S2_R2 */
    1079,
    /* CVT_D0_S2_R2_P */
    1083,
    /* CVT_D0_S2_R3 */
    1088,
    /* CVT_D0_S2_R3_P */
    1092,
    /* CVT_D0_S3_R1 */
    1097,
    /* CVT_D0_S3_R1_P */
    1101,
    /* CVT_D0_S3_R2 */
    1106,
    /* CVT_D0_S3_R2_P */
    1110,
    /* CVT_D0_S3_R3 */
    1115,
    /* CVT_D0_S3_R3_P */
    1119,
    /* CVT_D1_S0_R0 */
    1124,
    /* CVT_D1_S0_R0_P */
    1128,
    /* CVT_D1_S0_R0_W8_32 */
    1133,
    /* CVT_D1_S0_R1 */
    1137,
    /* CVT_D1_S0_R1_P */
    1141,
    /* CVT_D1_S0_R2 */
    1146,
    /* CVT_D1_S0_R2_P */
    1150,
    /* CVT_D1_S0_R3 */
    1155,
    /* CVT_D1_S0_R3_P */
    1159,
    /* CVT_D1_S1_R0 */
    1164,
    /* CVT_D1_S1_R0_P */
    1168,
    /* CVT_D1_S1_R1 */
    1173,
    /* CVT_D1_S1_R1_P */
    1177,
    /* CVT_D1_S1_R2 */
    1182,
    /* CVT_D1_S1_R2_P */
    1186,
    /* CVT_D1_S1_R3 */
    1191,
    /* CVT_D1_S1_R3_P */
    1195,
    /* CVT_D1_S2_R0 */
    1200,
    /* CVT_D1_S2_R0_P */
    1204,
    /* CVT_D1_S2_R1 */
    1209,
    /* CVT_D1_S2_R1_P */
    1213,
    /* CVT_D1_S2_R2 */
    1218,
    /* CVT_D1_S2_R2_P */
    1222,
    /* CVT_D1_S2_R3 */
    1227,
    /* CVT_D1_S2_R3_P */
    1231,
    /* CVT_D1_S3_R0 */
    1236,
    /* CVT_D1_S3_R0_P */
    1240,
    /* CVT_D1_S3_R1 */
    1245,
    /* CVT_D1_S3_R1_P */
    1249,
    /* CVT_D1_S3_R2 */
    1254,
    /* CVT_D1_S3_R2_P */
    1258,
    /* CVT_D1_S3_R3 */
    1263,
    /* CVT_D1_S3_R3_P */
    1267,
    /* CVT_D2_S0_R0 */
    1272,
    /* CVT_D2_S0_R0_P */
    1276,
    /* CVT_D2_S0_R2 */
    1281,
    /* CVT_D2_S0_R2_P */
    1285,
    /* CVT_D2_S0_R3 */
    1290,
    /* CVT_D2_S0_R3_P */
    1294,
    /* CVT_D2_S1_R0 */
    1299,
    /* CVT_D2_S1_R0_P */
    1303,
    /* CVT_D2_S1_R1 */
    1308,
    /* CVT_D2_S1_R1_P */
    1312,
    /* CVT_D2_S1_R2 */
    1317,
    /* CVT_D2_S1_R2_P */
    1321,
    /* CVT_D2_S1_R3 */
    1326,
    /* CVT_D2_S1_R3_P */
    1330,
    /* CVT_D2_S3_R0 */
    1335,
    /* CVT_D2_S3_R0_P */
    1339,
    /* CVT_D3_S0_R0 */
    1344,
    /* CVT_D3_S0_R0_P */
    1348,
    /* CVT_D3_S0_R2 */
    1353,
    /* CVT_D3_S0_R2_P */
    1357,
    /* CVT_D3_S0_R3 */
    1362,
    /* CVT_D3_S0_R3_P */
    1366,
    /* CVT_D3_S1_R0 */
    1371,
    /* CVT_D3_S1_R0_P */
    1375,
    /* CVT_D3_S1_R1 */
    1380,
    /* CVT_D3_S1_R1_P */
    1384,
    /* CVT_D3_S1_R2 */
    1389,
    /* CVT_D3_S1_R2_P */
    1393,
    /* CVT_D3_S1_R3 */
    1398,
    /* CVT_D3_S1_R3_P */
    1402,
    /* CVT_D3_S2_R0 */
    1407,
    /* CVT_D3_S2_R0_P */
    1411,
    /* CVT_D3_S3_R0 */
    1416,
    /* CVT_D3_S3_R0_P */
    1420,
    /* CVT_F32_S32 */
    1425,
    /* CVT_F32_S32_P */
    1429,
    /* CVT_F32_U32 */
    1434,
    /* CVT_F32_U32_P */
    1438,
    /* CVT_S32_F32 */
    1443,
    /* CVT_S32_F32_P */
    1447,
    /* CVT_SEXT */
    1452,
    /* CVT_U32_F32 */
    1456,
    /* CVT_U32_F32_P */
    1460,
    /* C_ABS */
    1465,
    /* C_ADD */
    1467,
    /* C_ADDI */
    1470,
    /* C_AND */
    1473,
    /* C_ANDI */
    1476,
    /* C_ANDN */
    1479,
    /* C_BAR_ARRIVE */
    1482,
    /* C_BAR_WAIT */
    1483,
    /* C_BRA */
    1484,
    /* C_CHWIDTH */
    1485,
    /* C_EXIT */
    1487,
    /* C_FADD */
    1488,
    /* C_FENCE */
    1491,
    /* C_FMAX */
    1492,
    /* C_FMIN */
    1495,
    /* C_FMUL */
    1498,
    /* C_LD_GLOBAL */
    1501,
    /* C_MAX_S */
    1503,
    /* C_MAX_U */
    1506,
    /* C_MIN_S */
    1509,
    /* C_MIN_U */
    1512,
    /* C_MOV */
    1515,
    /* C_MUL_LO */
    1517,
    /* C_NEG */
    1520,
    /* C_NOT */
    1522,
    /* C_OR */
    1524,
    /* C_ORI */
    1527,
    /* C_RECONV */
    1530,
    /* C_RET */
    1531,
    /* C_SHL */
    1532,
    /* C_SHLI */
    1535,
    /* C_SHR */
    1538,
    /* C_SHRI */
    1541,
    /* C_SRA */
    1544,
    /* C_SRAI */
    1547,
    /* C_ST_GLOBAL */
    1550,
    /* C_SUB */
    1552,
    /* C_SUBI */
    1555,
    /* C_XOR */
    1558,
    /* C_XORI */
    1561,
    /* DP2_BF16 */
    1564,
    /* DP2_F16 */
    1568,
    /* DP4_ACC */
    1572,
    /* DP4_E4M3 */
    1576,
    /* DP4_E5M2 */
    1580,
    /* DP4_SS */
    1584,
    /* EX2_F32 */
    1588,
    /* FABS_F0 */
    1592,
    /* FABS_F1 */
    1596,
    /* FADD */
    1600,
    /* FADD_F1 */
    1604,
    /* FADD_F1_W8 */
    1608,
    /* FADD_P */
    1612,
    /* FADD_W8 */
    1617,
    /* FFMA_ACC_F0 */
    1621,
    /* FFMA_ACC_F1 */
    1625,
    /* FFMA_F0 */
    1629,
    /* FFMA_F1 */
    1633,
    /* FMAX */
    1637,
    /* FMAX_F1 */
    1641,
    /* FMIN */
    1645,
    /* FMIN_F1 */
    1649,
    /* FMUL */
    1653,
    /* FMUL_F1 */
    1657,
    /* FMUL_F1_W8 */
    1661,
    /* FMUL_P */
    1665,
    /* FMUL_W8 */
    1670,
    /* FNEG_F0 */
    1674,
    /* FNEG_F1 */
    1678,
    /* FSUB */
    1682,
    /* FSUB_F1 */
    1686,
    /* FSUB_F1_W8 */
    1690,
    /* FSUB_P */
    1694,
    /* FSUB_W8 */
    1699,
    /* LD_GLOBAL */
    1703,
    /* LD_GLOBAL_IDX */
    1706,
    /* LD_GLOBAL_IDX_W16 */
    1711,
    /* LD_GLOBAL_IDX_W8 */
    1716,
    /* LD_GLOBAL_P */
    1721,
    /* LD_GLOBAL_SLOT */
    1725,
    /* LD_GLOBAL_SLOT_W16 */
    1730,
    /* LD_GLOBAL_SLOT_W8 */
    1735,
    /* LD_GLOBAL_W16 */
    1740,
    /* LD_GLOBAL_W8 */
    1743,
    /* LD_LOCAL */
    1746,
    /* LD_PRED_G */
    1748,
    /* LD_PRED_LOCAL */
    1751,
    /* LD_PRED_S */
    1753,
    /* LD_SHARED */
    1756,
    /* LD_SHARED_IDX */
    1759,
    /* LD_SHARED_W16 */
    1764,
    /* LD_SHARED_W8 */
    1767,
    /* LG2_F32 */
    1770,
    /* MADLO */
    1774,
    /* MADLO_P */
    1778,
    /* MAD_ACC */
    1783,
    /* MAX_S */
    1787,
    /* MAX_S_P */
    1791,
    /* MAX_S_W16 */
    1796,
    /* MAX_U */
    1800,
    /* MAX_U_P */
    1804,
    /* MIN_S */
    1809,
    /* MIN_S_P */
    1813,
    /* MIN_S_W16 */
    1818,
    /* MIN_U */
    1822,
    /* MIN_U_P */
    1826,
    /* MOVI */
    1831,
    /* MOVI48 */
    1833,
    /* MOV_P */
    1835,
    /* MULI */
    1841,
    /* MULI_P */
    1844,
    /* MUL_HI_S */
    1848,
    /* MUL_HI_S_P */
    1852,
    /* MUL_HI_U */
    1857,
    /* MUL_HI_U_P */
    1861,
    /* MUL_LO */
    1866,
    /* NEG */
    1870,
    /* OR */
    1874,
    /* ORI */
    1878,
    /* ORI_P */
    1881,
    /* OR_P */
    1885,
    /* OR_W16 */
    1890,
    /* PACKI */
    1894,
    /* PACKI_Z */
    1898,
    /* PAND */
    1901,
    /* PMOV */
    1904,
    /* PMOV_IMM */
    1907,
    /* POPC */
    1909,
    /* POR */
    1913,
    /* PXOR */
    1916,
    /* RCP_F32 */
    1919,
    /* RCP_F32_P */
    1923,
    /* RCP_U32 */
    1928,
    /* RSQRT_F32 */
    1932,
    /* SEL */
    1936,
    /* SETP_EQ */
    1941,
    /* SETP_EQ_F */
    1946,
    /* SETP_EQ_F1 */
    1951,
    /* SETP_EQ_F1_NP */
    1956,
    /* SETP_EQ_F_I */
    1960,
    /* SETP_EQ_F_NP */
    1965,
    /* SETP_EQ_F_NPI */
    1969,
    /* SETP_EQ_I */
    1973,
    /* SETP_EQ_NP */
    1978,
    /* SETP_EQ_NPI */
    1982,
    /* SETP_GE */
    1986,
    /* SETP_GE_F */
    1991,
    /* SETP_GE_F1 */
    1996,
    /* SETP_GE_F1_NP */
    2001,
    /* SETP_GE_F_I */
    2005,
    /* SETP_GE_F_NP */
    2010,
    /* SETP_GE_F_NPI */
    2014,
    /* SETP_GE_I */
    2018,
    /* SETP_GE_NP */
    2023,
    /* SETP_GE_NPI */
    2027,
    /* SETP_GE_U */
    2031,
    /* SETP_GE_U_I */
    2036,
    /* SETP_GE_U_NP */
    2041,
    /* SETP_GE_U_NPI */
    2045,
    /* SETP_GT */
    2049,
    /* SETP_GT_F */
    2054,
    /* SETP_GT_F1 */
    2059,
    /* SETP_GT_F1_NP */
    2064,
    /* SETP_GT_F_I */
    2068,
    /* SETP_GT_F_NP */
    2073,
    /* SETP_GT_F_NPI */
    2077,
    /* SETP_GT_I */
    2081,
    /* SETP_GT_NP */
    2086,
    /* SETP_GT_NPI */
    2090,
    /* SETP_GT_U */
    2094,
    /* SETP_GT_U_I */
    2099,
    /* SETP_GT_U_NP */
    2104,
    /* SETP_GT_U_NPI */
    2108,
    /* SETP_LE */
    2112,
    /* SETP_LE_F */
    2117,
    /* SETP_LE_F1 */
    2122,
    /* SETP_LE_F1_NP */
    2127,
    /* SETP_LE_F_I */
    2131,
    /* SETP_LE_F_NP */
    2136,
    /* SETP_LE_F_NPI */
    2140,
    /* SETP_LE_I */
    2144,
    /* SETP_LE_NP */
    2149,
    /* SETP_LE_NPI */
    2153,
    /* SETP_LE_U */
    2157,
    /* SETP_LE_U_I */
    2162,
    /* SETP_LE_U_NP */
    2167,
    /* SETP_LE_U_NPI */
    2171,
    /* SETP_LT */
    2175,
    /* SETP_LT_F */
    2180,
    /* SETP_LT_F1 */
    2185,
    /* SETP_LT_F1_NP */
    2190,
    /* SETP_LT_F_I */
    2194,
    /* SETP_LT_F_NP */
    2199,
    /* SETP_LT_F_NPI */
    2203,
    /* SETP_LT_I */
    2207,
    /* SETP_LT_NP */
    2212,
    /* SETP_LT_NPI */
    2216,
    /* SETP_LT_U */
    2220,
    /* SETP_LT_U_I */
    2225,
    /* SETP_LT_U_NP */
    2230,
    /* SETP_LT_U_NPI */
    2234,
    /* SETP_NE */
    2238,
    /* SETP_NE_F */
    2243,
    /* SETP_NE_F1 */
    2248,
    /* SETP_NE_F1_NP */
    2253,
    /* SETP_NE_F_I */
    2257,
    /* SETP_NE_F_NP */
    2262,
    /* SETP_NE_F_NPI */
    2266,
    /* SETP_NE_I */
    2270,
    /* SETP_NE_NP */
    2275,
    /* SETP_NE_NPI */
    2279,
    /* SHFL_IDX */
    2283,
    /* SHL */
    2287,
    /* SHLI */
    2291,
    /* SHLI_P */
    2294,
    /* SHL_P */
    2298,
    /* SHR */
    2303,
    /* SHRI */
    2307,
    /* SHRI_P */
    2310,
    /* SHR_P */
    2314,
    /* SIN_F32 */
    2319,
    /* SQRT_F32 */
    2323,
    /* SRA */
    2327,
    /* SRAI */
    2331,
    /* SRAI_P */
    2334,
    /* SRA_P */
    2338,
    /* SRD */
    2343,
    /* ST_GLOBAL */
    2345,
    /* ST_GLOBAL_IDX */
    2348,
    /* ST_GLOBAL_IDX_W16 */
    2353,
    /* ST_GLOBAL_IDX_W8 */
    2358,
    /* ST_GLOBAL_SLOT */
    2363,
    /* ST_GLOBAL_SLOT_W16 */
    2368,
    /* ST_GLOBAL_SLOT_W8 */
    2373,
    /* ST_GLOBAL_W16 */
    2378,
    /* ST_GLOBAL_W8 */
    2381,
    /* ST_LOCAL */
    2384,
    /* ST_PRED_G */
    2386,
    /* ST_PRED_LOCAL */
    2389,
    /* ST_PRED_S */
    2391,
    /* ST_SHARED */
    2394,
    /* ST_SHARED_IDX */
    2397,
    /* ST_SHARED_W16 */
    2402,
    /* ST_SHARED_W8 */
    2405,
    /* SUB */
    2408,
    /* SUBI */
    2412,
    /* SUBI_P */
    2415,
    /* SUB_P */
    2419,
    /* SUB_W16 */
    2424,
    /* SZ_GLOBAL_LD_S16 */
    2428,
    /* SZ_GLOBAL_LD_S16_W16 */
    2433,
    /* SZ_GLOBAL_LD_S8 */
    2438,
    /* SZ_GLOBAL_LD_S8_W16 */
    2443,
    /* SZ_GLOBAL_LD_U16 */
    2448,
    /* SZ_GLOBAL_LD_U16_W16 */
    2453,
    /* SZ_GLOBAL_LD_U8 */
    2458,
    /* SZ_GLOBAL_LD_U8_W16 */
    2463,
    /* SZ_GLOBAL_ST_16 */
    2468,
    /* SZ_GLOBAL_ST_16_W16 */
    2473,
    /* SZ_GLOBAL_ST_8 */
    2478,
    /* SZ_GLOBAL_ST_8_W16 */
    2483,
    /* SZ_SHARED_LD_S16 */
    2488,
    /* SZ_SHARED_LD_S8 */
    2493,
    /* SZ_SHARED_LD_U16 */
    2498,
    /* SZ_SHARED_LD_U8 */
    2503,
    /* SZ_SHARED_ST_16 */
    2508,
    /* SZ_SHARED_ST_8 */
    2513,
    /* UNBALLOT */
    2518,
    /* UNPACKI */
    2521,
    /* VOTE_ANY */
    2524,
    /* XOR */
    2527,
    /* XORI */
    2531,
    /* XORI_P */
    2534,
    /* XOR_P */
    2538,
    /* XOR_W16 */
    2543,
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
    GPR, GPR, i32imm, 
    /* PSEUDO_PADDI */
    GPR, GPR, PR, simm10, 
    /* PSEUDO_PAND */
    PR, PR, PR, 
    /* PSEUDO_PMOV */
    GPR, GPR, PR, GPR, 
    /* PSEUDO_POR */
    PR, PR, PR, 
    /* PSEUDO_PRIVCHECK */
    i32imm, 
    /* PSEUDO_PRIVFLOOR */
    GPR, 
    /* PSEUDO_PXOR */
    PR, PR, PR, 
    /* PSEUDO_RET */
    GPR, 
    /* PSEUDO_ST_PRED */
    PR, GPR, simm13, 
    /* PSEUDO_TRUNC16 */
    GPR16, GPR, i32imm, 
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
    /* ATOM_ADD_F_G */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
    /* ATOM_ADD_F_S */
    GPR, GPR, GPR, uimm2, simm4, GPR, 
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
    /* SZ_GLOBAL_LD_S16 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_LD_S16_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_LD_S8 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_LD_S8_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_LD_U16 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_LD_U16_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_LD_U8 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_LD_U8_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_ST_16 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_ST_16_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_ST_8 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_GLOBAL_ST_8_W16 */
    GPR16, GPR, GPR, uimm2, simm8, 
    /* SZ_SHARED_LD_S16 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_SHARED_LD_S8 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_SHARED_LD_U16 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_SHARED_LD_U8 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_SHARED_ST_16 */
    GPR, GPR, GPR, uimm2, simm8, 
    /* SZ_SHARED_ST_8 */
    GPR, GPR, GPR, uimm2, simm8, 
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
    CEFBS_None, // PSEUDO_PRIVCHECK = 284
    CEFBS_None, // PSEUDO_PRIVFLOOR = 285
    CEFBS_None, // PSEUDO_PXOR = 286
    CEFBS_None, // PSEUDO_RET = 287
    CEFBS_None, // PSEUDO_ST_PRED = 288
    CEFBS_None, // PSEUDO_TRUNC16 = 289
    CEFBS_None, // ABS = 290
    CEFBS_None, // ADD = 291
    CEFBS_None, // ADDI = 292
    CEFBS_None, // ADDI48 = 293
    CEFBS_None, // ADDI_P = 294
    CEFBS_None, // ADDI_PP = 295
    CEFBS_None, // ADDI_W16 = 296
    CEFBS_None, // ADD_P = 297
    CEFBS_None, // ADD_PP = 298
    CEFBS_None, // ADD_W16 = 299
    CEFBS_None, // AND = 300
    CEFBS_None, // ANDI = 301
    CEFBS_None, // ANDI_P = 302
    CEFBS_None, // ANDN = 303
    CEFBS_None, // ANDNI = 304
    CEFBS_None, // ANDNI_P = 305
    CEFBS_None, // AND_P = 306
    CEFBS_None, // AND_W16 = 307
    CEFBS_None, // ATOM_ADD_F_G = 308
    CEFBS_None, // ATOM_ADD_F_S = 309
    CEFBS_None, // ATOM_ADD_G = 310
    CEFBS_None, // ATOM_ADD_S = 311
    CEFBS_None, // ATOM_AND_G = 312
    CEFBS_None, // ATOM_AND_S = 313
    CEFBS_None, // ATOM_EXCH_G = 314
    CEFBS_None, // ATOM_EXCH_S = 315
    CEFBS_None, // ATOM_MAX_S_G = 316
    CEFBS_None, // ATOM_MAX_S_S = 317
    CEFBS_None, // ATOM_MAX_U_G = 318
    CEFBS_None, // ATOM_MAX_U_S = 319
    CEFBS_None, // ATOM_MIN_S_G = 320
    CEFBS_None, // ATOM_MIN_S_S = 321
    CEFBS_None, // ATOM_MIN_U_G = 322
    CEFBS_None, // ATOM_MIN_U_S = 323
    CEFBS_None, // ATOM_OR_G = 324
    CEFBS_None, // ATOM_OR_S = 325
    CEFBS_None, // ATOM_XOR_G = 326
    CEFBS_None, // ATOM_XOR_S = 327
    CEFBS_None, // BALLOT = 328
    CEFBS_None, // BAR_INIT = 329
    CEFBS_None, // BAR_WAIT_PHASE = 330
    CEFBS_None, // BRA = 331
    CEFBS_None, // BRA_PRED = 332
    CEFBS_None, // BREV = 333
    CEFBS_None, // CALL = 334
    CEFBS_None, // CAS_G = 335
    CEFBS_None, // CAS_S = 336
    CEFBS_None, // CHWIDTH_MULTI = 337
    CEFBS_None, // CLZ = 338
    CEFBS_None, // COS_F32 = 339
    CEFBS_None, // CVT_D0_S0_R0 = 340
    CEFBS_None, // CVT_D0_S0_R0_P = 341
    CEFBS_None, // CVT_D0_S0_R0_W16_32 = 342
    CEFBS_None, // CVT_D0_S0_R0_W16_8 = 343
    CEFBS_None, // CVT_D0_S0_R0_W32_16 = 344
    CEFBS_None, // CVT_D0_S0_R0_W32_4 = 345
    CEFBS_None, // CVT_D0_S0_R0_W32_8 = 346
    CEFBS_None, // CVT_D0_S0_R0_W4_32 = 347
    CEFBS_None, // CVT_D0_S0_R0_W8_32 = 348
    CEFBS_None, // CVT_D0_S0_R1 = 349
    CEFBS_None, // CVT_D0_S0_R1_P = 350
    CEFBS_None, // CVT_D0_S0_R2 = 351
    CEFBS_None, // CVT_D0_S0_R2_P = 352
    CEFBS_None, // CVT_D0_S0_R3 = 353
    CEFBS_None, // CVT_D0_S0_R3_P = 354
    CEFBS_None, // CVT_D0_S1_R0 = 355
    CEFBS_None, // CVT_D0_S1_R0_P = 356
    CEFBS_None, // CVT_D0_S1_R0_W16_8 = 357
    CEFBS_None, // CVT_D0_S1_R0_W32_8 = 358
    CEFBS_None, // CVT_D0_S1_R1 = 359
    CEFBS_None, // CVT_D0_S1_R1_P = 360
    CEFBS_None, // CVT_D0_S1_R2 = 361
    CEFBS_None, // CVT_D0_S1_R2_P = 362
    CEFBS_None, // CVT_D0_S1_R3 = 363
    CEFBS_None, // CVT_D0_S1_R3_P = 364
    CEFBS_None, // CVT_D0_S2_R1 = 365
    CEFBS_None, // CVT_D0_S2_R1_P = 366
    CEFBS_None, // CVT_D0_S2_R2 = 367
    CEFBS_None, // CVT_D0_S2_R2_P = 368
    CEFBS_None, // CVT_D0_S2_R3 = 369
    CEFBS_None, // CVT_D0_S2_R3_P = 370
    CEFBS_None, // CVT_D0_S3_R1 = 371
    CEFBS_None, // CVT_D0_S3_R1_P = 372
    CEFBS_None, // CVT_D0_S3_R2 = 373
    CEFBS_None, // CVT_D0_S3_R2_P = 374
    CEFBS_None, // CVT_D0_S3_R3 = 375
    CEFBS_None, // CVT_D0_S3_R3_P = 376
    CEFBS_None, // CVT_D1_S0_R0 = 377
    CEFBS_None, // CVT_D1_S0_R0_P = 378
    CEFBS_None, // CVT_D1_S0_R0_W8_32 = 379
    CEFBS_None, // CVT_D1_S0_R1 = 380
    CEFBS_None, // CVT_D1_S0_R1_P = 381
    CEFBS_None, // CVT_D1_S0_R2 = 382
    CEFBS_None, // CVT_D1_S0_R2_P = 383
    CEFBS_None, // CVT_D1_S0_R3 = 384
    CEFBS_None, // CVT_D1_S0_R3_P = 385
    CEFBS_None, // CVT_D1_S1_R0 = 386
    CEFBS_None, // CVT_D1_S1_R0_P = 387
    CEFBS_None, // CVT_D1_S1_R1 = 388
    CEFBS_None, // CVT_D1_S1_R1_P = 389
    CEFBS_None, // CVT_D1_S1_R2 = 390
    CEFBS_None, // CVT_D1_S1_R2_P = 391
    CEFBS_None, // CVT_D1_S1_R3 = 392
    CEFBS_None, // CVT_D1_S1_R3_P = 393
    CEFBS_None, // CVT_D1_S2_R0 = 394
    CEFBS_None, // CVT_D1_S2_R0_P = 395
    CEFBS_None, // CVT_D1_S2_R1 = 396
    CEFBS_None, // CVT_D1_S2_R1_P = 397
    CEFBS_None, // CVT_D1_S2_R2 = 398
    CEFBS_None, // CVT_D1_S2_R2_P = 399
    CEFBS_None, // CVT_D1_S2_R3 = 400
    CEFBS_None, // CVT_D1_S2_R3_P = 401
    CEFBS_None, // CVT_D1_S3_R0 = 402
    CEFBS_None, // CVT_D1_S3_R0_P = 403
    CEFBS_None, // CVT_D1_S3_R1 = 404
    CEFBS_None, // CVT_D1_S3_R1_P = 405
    CEFBS_None, // CVT_D1_S3_R2 = 406
    CEFBS_None, // CVT_D1_S3_R2_P = 407
    CEFBS_None, // CVT_D1_S3_R3 = 408
    CEFBS_None, // CVT_D1_S3_R3_P = 409
    CEFBS_None, // CVT_D2_S0_R0 = 410
    CEFBS_None, // CVT_D2_S0_R0_P = 411
    CEFBS_None, // CVT_D2_S0_R2 = 412
    CEFBS_None, // CVT_D2_S0_R2_P = 413
    CEFBS_None, // CVT_D2_S0_R3 = 414
    CEFBS_None, // CVT_D2_S0_R3_P = 415
    CEFBS_None, // CVT_D2_S1_R0 = 416
    CEFBS_None, // CVT_D2_S1_R0_P = 417
    CEFBS_None, // CVT_D2_S1_R1 = 418
    CEFBS_None, // CVT_D2_S1_R1_P = 419
    CEFBS_None, // CVT_D2_S1_R2 = 420
    CEFBS_None, // CVT_D2_S1_R2_P = 421
    CEFBS_None, // CVT_D2_S1_R3 = 422
    CEFBS_None, // CVT_D2_S1_R3_P = 423
    CEFBS_None, // CVT_D2_S3_R0 = 424
    CEFBS_None, // CVT_D2_S3_R0_P = 425
    CEFBS_None, // CVT_D3_S0_R0 = 426
    CEFBS_None, // CVT_D3_S0_R0_P = 427
    CEFBS_None, // CVT_D3_S0_R2 = 428
    CEFBS_None, // CVT_D3_S0_R2_P = 429
    CEFBS_None, // CVT_D3_S0_R3 = 430
    CEFBS_None, // CVT_D3_S0_R3_P = 431
    CEFBS_None, // CVT_D3_S1_R0 = 432
    CEFBS_None, // CVT_D3_S1_R0_P = 433
    CEFBS_None, // CVT_D3_S1_R1 = 434
    CEFBS_None, // CVT_D3_S1_R1_P = 435
    CEFBS_None, // CVT_D3_S1_R2 = 436
    CEFBS_None, // CVT_D3_S1_R2_P = 437
    CEFBS_None, // CVT_D3_S1_R3 = 438
    CEFBS_None, // CVT_D3_S1_R3_P = 439
    CEFBS_None, // CVT_D3_S2_R0 = 440
    CEFBS_None, // CVT_D3_S2_R0_P = 441
    CEFBS_None, // CVT_D3_S3_R0 = 442
    CEFBS_None, // CVT_D3_S3_R0_P = 443
    CEFBS_None, // CVT_F32_S32 = 444
    CEFBS_None, // CVT_F32_S32_P = 445
    CEFBS_None, // CVT_F32_U32 = 446
    CEFBS_None, // CVT_F32_U32_P = 447
    CEFBS_None, // CVT_S32_F32 = 448
    CEFBS_None, // CVT_S32_F32_P = 449
    CEFBS_None, // CVT_SEXT = 450
    CEFBS_None, // CVT_U32_F32 = 451
    CEFBS_None, // CVT_U32_F32_P = 452
    CEFBS_None, // C_ABS = 453
    CEFBS_None, // C_ADD = 454
    CEFBS_None, // C_ADDI = 455
    CEFBS_None, // C_AND = 456
    CEFBS_None, // C_ANDI = 457
    CEFBS_None, // C_ANDN = 458
    CEFBS_None, // C_BAR_ARRIVE = 459
    CEFBS_None, // C_BAR_WAIT = 460
    CEFBS_None, // C_BRA = 461
    CEFBS_None, // C_CHWIDTH = 462
    CEFBS_None, // C_EXIT = 463
    CEFBS_None, // C_FADD = 464
    CEFBS_None, // C_FENCE = 465
    CEFBS_None, // C_FMAX = 466
    CEFBS_None, // C_FMIN = 467
    CEFBS_None, // C_FMUL = 468
    CEFBS_None, // C_LD_GLOBAL = 469
    CEFBS_None, // C_MAX_S = 470
    CEFBS_None, // C_MAX_U = 471
    CEFBS_None, // C_MIN_S = 472
    CEFBS_None, // C_MIN_U = 473
    CEFBS_None, // C_MOV = 474
    CEFBS_None, // C_MUL_LO = 475
    CEFBS_None, // C_NEG = 476
    CEFBS_None, // C_NOT = 477
    CEFBS_None, // C_OR = 478
    CEFBS_None, // C_ORI = 479
    CEFBS_None, // C_RECONV = 480
    CEFBS_None, // C_RET = 481
    CEFBS_None, // C_SHL = 482
    CEFBS_None, // C_SHLI = 483
    CEFBS_None, // C_SHR = 484
    CEFBS_None, // C_SHRI = 485
    CEFBS_None, // C_SRA = 486
    CEFBS_None, // C_SRAI = 487
    CEFBS_None, // C_ST_GLOBAL = 488
    CEFBS_None, // C_SUB = 489
    CEFBS_None, // C_SUBI = 490
    CEFBS_None, // C_XOR = 491
    CEFBS_None, // C_XORI = 492
    CEFBS_None, // DP2_BF16 = 493
    CEFBS_None, // DP2_F16 = 494
    CEFBS_None, // DP4_ACC = 495
    CEFBS_None, // DP4_E4M3 = 496
    CEFBS_None, // DP4_E5M2 = 497
    CEFBS_None, // DP4_SS = 498
    CEFBS_None, // EX2_F32 = 499
    CEFBS_None, // FABS_F0 = 500
    CEFBS_None, // FABS_F1 = 501
    CEFBS_None, // FADD = 502
    CEFBS_None, // FADD_F1 = 503
    CEFBS_None, // FADD_F1_W8 = 504
    CEFBS_None, // FADD_P = 505
    CEFBS_None, // FADD_W8 = 506
    CEFBS_None, // FFMA_ACC_F0 = 507
    CEFBS_None, // FFMA_ACC_F1 = 508
    CEFBS_None, // FFMA_F0 = 509
    CEFBS_None, // FFMA_F1 = 510
    CEFBS_None, // FMAX = 511
    CEFBS_None, // FMAX_F1 = 512
    CEFBS_None, // FMIN = 513
    CEFBS_None, // FMIN_F1 = 514
    CEFBS_None, // FMUL = 515
    CEFBS_None, // FMUL_F1 = 516
    CEFBS_None, // FMUL_F1_W8 = 517
    CEFBS_None, // FMUL_P = 518
    CEFBS_None, // FMUL_W8 = 519
    CEFBS_None, // FNEG_F0 = 520
    CEFBS_None, // FNEG_F1 = 521
    CEFBS_None, // FSUB = 522
    CEFBS_None, // FSUB_F1 = 523
    CEFBS_None, // FSUB_F1_W8 = 524
    CEFBS_None, // FSUB_P = 525
    CEFBS_None, // FSUB_W8 = 526
    CEFBS_None, // LD_GLOBAL = 527
    CEFBS_None, // LD_GLOBAL_IDX = 528
    CEFBS_None, // LD_GLOBAL_IDX_W16 = 529
    CEFBS_None, // LD_GLOBAL_IDX_W8 = 530
    CEFBS_None, // LD_GLOBAL_P = 531
    CEFBS_None, // LD_GLOBAL_SLOT = 532
    CEFBS_None, // LD_GLOBAL_SLOT_W16 = 533
    CEFBS_None, // LD_GLOBAL_SLOT_W8 = 534
    CEFBS_None, // LD_GLOBAL_W16 = 535
    CEFBS_None, // LD_GLOBAL_W8 = 536
    CEFBS_None, // LD_LOCAL = 537
    CEFBS_None, // LD_PRED_G = 538
    CEFBS_None, // LD_PRED_LOCAL = 539
    CEFBS_None, // LD_PRED_S = 540
    CEFBS_None, // LD_SHARED = 541
    CEFBS_None, // LD_SHARED_IDX = 542
    CEFBS_None, // LD_SHARED_W16 = 543
    CEFBS_None, // LD_SHARED_W8 = 544
    CEFBS_None, // LG2_F32 = 545
    CEFBS_None, // MADLO = 546
    CEFBS_None, // MADLO_P = 547
    CEFBS_None, // MAD_ACC = 548
    CEFBS_None, // MAX_S = 549
    CEFBS_None, // MAX_S_P = 550
    CEFBS_None, // MAX_S_W16 = 551
    CEFBS_None, // MAX_U = 552
    CEFBS_None, // MAX_U_P = 553
    CEFBS_None, // MIN_S = 554
    CEFBS_None, // MIN_S_P = 555
    CEFBS_None, // MIN_S_W16 = 556
    CEFBS_None, // MIN_U = 557
    CEFBS_None, // MIN_U_P = 558
    CEFBS_None, // MOVI = 559
    CEFBS_None, // MOVI48 = 560
    CEFBS_None, // MOV_P = 561
    CEFBS_None, // MULI = 562
    CEFBS_None, // MULI_P = 563
    CEFBS_None, // MUL_HI_S = 564
    CEFBS_None, // MUL_HI_S_P = 565
    CEFBS_None, // MUL_HI_U = 566
    CEFBS_None, // MUL_HI_U_P = 567
    CEFBS_None, // MUL_LO = 568
    CEFBS_None, // NEG = 569
    CEFBS_None, // OR = 570
    CEFBS_None, // ORI = 571
    CEFBS_None, // ORI_P = 572
    CEFBS_None, // OR_P = 573
    CEFBS_None, // OR_W16 = 574
    CEFBS_None, // PACKI = 575
    CEFBS_None, // PACKI_Z = 576
    CEFBS_None, // PAND = 577
    CEFBS_None, // PMOV = 578
    CEFBS_None, // PMOV_IMM = 579
    CEFBS_None, // POPC = 580
    CEFBS_None, // POR = 581
    CEFBS_None, // PXOR = 582
    CEFBS_None, // RCP_F32 = 583
    CEFBS_None, // RCP_F32_P = 584
    CEFBS_None, // RCP_U32 = 585
    CEFBS_None, // RSQRT_F32 = 586
    CEFBS_None, // SEL = 587
    CEFBS_None, // SETP_EQ = 588
    CEFBS_None, // SETP_EQ_F = 589
    CEFBS_None, // SETP_EQ_F1 = 590
    CEFBS_None, // SETP_EQ_F1_NP = 591
    CEFBS_None, // SETP_EQ_F_I = 592
    CEFBS_None, // SETP_EQ_F_NP = 593
    CEFBS_None, // SETP_EQ_F_NPI = 594
    CEFBS_None, // SETP_EQ_I = 595
    CEFBS_None, // SETP_EQ_NP = 596
    CEFBS_None, // SETP_EQ_NPI = 597
    CEFBS_None, // SETP_GE = 598
    CEFBS_None, // SETP_GE_F = 599
    CEFBS_None, // SETP_GE_F1 = 600
    CEFBS_None, // SETP_GE_F1_NP = 601
    CEFBS_None, // SETP_GE_F_I = 602
    CEFBS_None, // SETP_GE_F_NP = 603
    CEFBS_None, // SETP_GE_F_NPI = 604
    CEFBS_None, // SETP_GE_I = 605
    CEFBS_None, // SETP_GE_NP = 606
    CEFBS_None, // SETP_GE_NPI = 607
    CEFBS_None, // SETP_GE_U = 608
    CEFBS_None, // SETP_GE_U_I = 609
    CEFBS_None, // SETP_GE_U_NP = 610
    CEFBS_None, // SETP_GE_U_NPI = 611
    CEFBS_None, // SETP_GT = 612
    CEFBS_None, // SETP_GT_F = 613
    CEFBS_None, // SETP_GT_F1 = 614
    CEFBS_None, // SETP_GT_F1_NP = 615
    CEFBS_None, // SETP_GT_F_I = 616
    CEFBS_None, // SETP_GT_F_NP = 617
    CEFBS_None, // SETP_GT_F_NPI = 618
    CEFBS_None, // SETP_GT_I = 619
    CEFBS_None, // SETP_GT_NP = 620
    CEFBS_None, // SETP_GT_NPI = 621
    CEFBS_None, // SETP_GT_U = 622
    CEFBS_None, // SETP_GT_U_I = 623
    CEFBS_None, // SETP_GT_U_NP = 624
    CEFBS_None, // SETP_GT_U_NPI = 625
    CEFBS_None, // SETP_LE = 626
    CEFBS_None, // SETP_LE_F = 627
    CEFBS_None, // SETP_LE_F1 = 628
    CEFBS_None, // SETP_LE_F1_NP = 629
    CEFBS_None, // SETP_LE_F_I = 630
    CEFBS_None, // SETP_LE_F_NP = 631
    CEFBS_None, // SETP_LE_F_NPI = 632
    CEFBS_None, // SETP_LE_I = 633
    CEFBS_None, // SETP_LE_NP = 634
    CEFBS_None, // SETP_LE_NPI = 635
    CEFBS_None, // SETP_LE_U = 636
    CEFBS_None, // SETP_LE_U_I = 637
    CEFBS_None, // SETP_LE_U_NP = 638
    CEFBS_None, // SETP_LE_U_NPI = 639
    CEFBS_None, // SETP_LT = 640
    CEFBS_None, // SETP_LT_F = 641
    CEFBS_None, // SETP_LT_F1 = 642
    CEFBS_None, // SETP_LT_F1_NP = 643
    CEFBS_None, // SETP_LT_F_I = 644
    CEFBS_None, // SETP_LT_F_NP = 645
    CEFBS_None, // SETP_LT_F_NPI = 646
    CEFBS_None, // SETP_LT_I = 647
    CEFBS_None, // SETP_LT_NP = 648
    CEFBS_None, // SETP_LT_NPI = 649
    CEFBS_None, // SETP_LT_U = 650
    CEFBS_None, // SETP_LT_U_I = 651
    CEFBS_None, // SETP_LT_U_NP = 652
    CEFBS_None, // SETP_LT_U_NPI = 653
    CEFBS_None, // SETP_NE = 654
    CEFBS_None, // SETP_NE_F = 655
    CEFBS_None, // SETP_NE_F1 = 656
    CEFBS_None, // SETP_NE_F1_NP = 657
    CEFBS_None, // SETP_NE_F_I = 658
    CEFBS_None, // SETP_NE_F_NP = 659
    CEFBS_None, // SETP_NE_F_NPI = 660
    CEFBS_None, // SETP_NE_I = 661
    CEFBS_None, // SETP_NE_NP = 662
    CEFBS_None, // SETP_NE_NPI = 663
    CEFBS_None, // SHFL_IDX = 664
    CEFBS_None, // SHL = 665
    CEFBS_None, // SHLI = 666
    CEFBS_None, // SHLI_P = 667
    CEFBS_None, // SHL_P = 668
    CEFBS_None, // SHR = 669
    CEFBS_None, // SHRI = 670
    CEFBS_None, // SHRI_P = 671
    CEFBS_None, // SHR_P = 672
    CEFBS_None, // SIN_F32 = 673
    CEFBS_None, // SQRT_F32 = 674
    CEFBS_None, // SRA = 675
    CEFBS_None, // SRAI = 676
    CEFBS_None, // SRAI_P = 677
    CEFBS_None, // SRA_P = 678
    CEFBS_None, // SRD = 679
    CEFBS_None, // ST_GLOBAL = 680
    CEFBS_None, // ST_GLOBAL_IDX = 681
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 682
    CEFBS_None, // ST_GLOBAL_IDX_W8 = 683
    CEFBS_None, // ST_GLOBAL_SLOT = 684
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 685
    CEFBS_None, // ST_GLOBAL_SLOT_W8 = 686
    CEFBS_None, // ST_GLOBAL_W16 = 687
    CEFBS_None, // ST_GLOBAL_W8 = 688
    CEFBS_None, // ST_LOCAL = 689
    CEFBS_None, // ST_PRED_G = 690
    CEFBS_None, // ST_PRED_LOCAL = 691
    CEFBS_None, // ST_PRED_S = 692
    CEFBS_None, // ST_SHARED = 693
    CEFBS_None, // ST_SHARED_IDX = 694
    CEFBS_None, // ST_SHARED_W16 = 695
    CEFBS_None, // ST_SHARED_W8 = 696
    CEFBS_None, // SUB = 697
    CEFBS_None, // SUBI = 698
    CEFBS_None, // SUBI_P = 699
    CEFBS_None, // SUB_P = 700
    CEFBS_None, // SUB_W16 = 701
    CEFBS_None, // SZ_GLOBAL_LD_S16 = 702
    CEFBS_None, // SZ_GLOBAL_LD_S16_W16 = 703
    CEFBS_None, // SZ_GLOBAL_LD_S8 = 704
    CEFBS_None, // SZ_GLOBAL_LD_S8_W16 = 705
    CEFBS_None, // SZ_GLOBAL_LD_U16 = 706
    CEFBS_None, // SZ_GLOBAL_LD_U16_W16 = 707
    CEFBS_None, // SZ_GLOBAL_LD_U8 = 708
    CEFBS_None, // SZ_GLOBAL_LD_U8_W16 = 709
    CEFBS_None, // SZ_GLOBAL_ST_16 = 710
    CEFBS_None, // SZ_GLOBAL_ST_16_W16 = 711
    CEFBS_None, // SZ_GLOBAL_ST_8 = 712
    CEFBS_None, // SZ_GLOBAL_ST_8_W16 = 713
    CEFBS_None, // SZ_SHARED_LD_S16 = 714
    CEFBS_None, // SZ_SHARED_LD_S8 = 715
    CEFBS_None, // SZ_SHARED_LD_U16 = 716
    CEFBS_None, // SZ_SHARED_LD_U8 = 717
    CEFBS_None, // SZ_SHARED_ST_16 = 718
    CEFBS_None, // SZ_SHARED_ST_8 = 719
    CEFBS_None, // UNBALLOT = 720
    CEFBS_None, // UNPACKI = 721
    CEFBS_None, // VOTE_ANY = 722
    CEFBS_None, // XOR = 723
    CEFBS_None, // XORI = 724
    CEFBS_None, // XORI_P = 725
    CEFBS_None, // XOR_P = 726
    CEFBS_None, // XOR_W16 = 727
  };

  assert(Opcode < 728);
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

