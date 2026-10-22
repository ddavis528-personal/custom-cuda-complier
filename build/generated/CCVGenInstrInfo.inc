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
    PSEUDO_PAND	= 277,
    PSEUDO_PMOV	= 278,
    PSEUDO_POR	= 279,
    PSEUDO_PXOR	= 280,
    PSEUDO_RET	= 281,
    PSEUDO_ST_PRED	= 282,
    ABS	= 283,
    ADD	= 284,
    ADDI	= 285,
    ADDI48	= 286,
    ADDI_P	= 287,
    ADDI_PP	= 288,
    ADDI_W16	= 289,
    ADD_P	= 290,
    ADD_PP	= 291,
    ADD_W16	= 292,
    AND	= 293,
    ANDI	= 294,
    ANDI_P	= 295,
    ANDN	= 296,
    ANDNI	= 297,
    ANDNI_P	= 298,
    AND_P	= 299,
    AND_W16	= 300,
    ATOM_ADD_G	= 301,
    BALLOT	= 302,
    BAR_INIT	= 303,
    BAR_WAIT_PHASE	= 304,
    BRA	= 305,
    BRA_PRED	= 306,
    BREV	= 307,
    CALL	= 308,
    CAS_G	= 309,
    CHWIDTH_MULTI	= 310,
    CLZ	= 311,
    COS_F32	= 312,
    CVT_F32_S32	= 313,
    CVT_F32_S32_P	= 314,
    CVT_F32_U32	= 315,
    CVT_F32_U32_P	= 316,
    CVT_S32_F32	= 317,
    CVT_S32_F32_P	= 318,
    CVT_SEXT	= 319,
    CVT_U32_F32	= 320,
    CVT_U32_F32_P	= 321,
    C_ABS	= 322,
    C_ADD	= 323,
    C_ADDI	= 324,
    C_AND	= 325,
    C_ANDI	= 326,
    C_ANDN	= 327,
    C_BAR_ARRIVE	= 328,
    C_BAR_WAIT	= 329,
    C_BRA	= 330,
    C_CHWIDTH	= 331,
    C_EXIT	= 332,
    C_FADD	= 333,
    C_FENCE	= 334,
    C_FMAX	= 335,
    C_FMIN	= 336,
    C_FMUL	= 337,
    C_LD_GLOBAL	= 338,
    C_MAX_S	= 339,
    C_MAX_U	= 340,
    C_MIN_S	= 341,
    C_MIN_U	= 342,
    C_MOV	= 343,
    C_MUL_LO	= 344,
    C_NEG	= 345,
    C_NOT	= 346,
    C_OR	= 347,
    C_ORI	= 348,
    C_RECONV	= 349,
    C_RET	= 350,
    C_SHL	= 351,
    C_SHLI	= 352,
    C_SHR	= 353,
    C_SHRI	= 354,
    C_SRA	= 355,
    C_SRAI	= 356,
    C_ST_GLOBAL	= 357,
    C_SUB	= 358,
    C_SUBI	= 359,
    C_XOR	= 360,
    C_XORI	= 361,
    DP2_BF16	= 362,
    DP2_F16	= 363,
    DP4_ACC	= 364,
    DP4_E4M3	= 365,
    DP4_E5M2	= 366,
    DP4_SS	= 367,
    EX2_F32	= 368,
    FABS_F0	= 369,
    FADD	= 370,
    FADD_P	= 371,
    FFMA_ACC_F0	= 372,
    FFMA_ACC_F1	= 373,
    FFMA_F0	= 374,
    FMAX	= 375,
    FMIN	= 376,
    FMUL	= 377,
    FMUL_P	= 378,
    FNEG_F0	= 379,
    FSUB	= 380,
    FSUB_P	= 381,
    LD_GLOBAL	= 382,
    LD_GLOBAL_IDX	= 383,
    LD_GLOBAL_IDX_W16	= 384,
    LD_GLOBAL_IDX_W8	= 385,
    LD_GLOBAL_P	= 386,
    LD_GLOBAL_SLOT	= 387,
    LD_GLOBAL_SLOT_W16	= 388,
    LD_GLOBAL_SLOT_W8	= 389,
    LD_GLOBAL_W16	= 390,
    LD_GLOBAL_W8	= 391,
    LD_PRED_G	= 392,
    LD_PRED_S	= 393,
    LD_SHARED	= 394,
    LD_SHARED_IDX	= 395,
    LD_SHARED_W16	= 396,
    LD_SHARED_W8	= 397,
    LG2_F32	= 398,
    MADLO	= 399,
    MADLO_P	= 400,
    MAD_ACC	= 401,
    MAX_S	= 402,
    MAX_S_P	= 403,
    MAX_S_W16	= 404,
    MAX_U	= 405,
    MAX_U_P	= 406,
    MIN_S	= 407,
    MIN_S_P	= 408,
    MIN_S_W16	= 409,
    MIN_U	= 410,
    MIN_U_P	= 411,
    MOVI	= 412,
    MOVI48	= 413,
    MOV_P	= 414,
    MULI	= 415,
    MULI_P	= 416,
    MUL_HI_S	= 417,
    MUL_HI_S_P	= 418,
    MUL_HI_U	= 419,
    MUL_HI_U_P	= 420,
    MUL_LO	= 421,
    NEG	= 422,
    OR	= 423,
    ORI	= 424,
    ORI_P	= 425,
    OR_P	= 426,
    OR_W16	= 427,
    PACKI	= 428,
    PACKI_Z	= 429,
    PAND	= 430,
    PMOV	= 431,
    PMOV_IMM	= 432,
    POPC	= 433,
    POR	= 434,
    PXOR	= 435,
    RCP_F32	= 436,
    RCP_F32_P	= 437,
    RCP_U32	= 438,
    RSQRT_F32	= 439,
    SEL	= 440,
    SETP_EQ	= 441,
    SETP_EQ_F	= 442,
    SETP_EQ_F_I	= 443,
    SETP_EQ_F_NP	= 444,
    SETP_EQ_F_NPI	= 445,
    SETP_EQ_I	= 446,
    SETP_EQ_NP	= 447,
    SETP_EQ_NPI	= 448,
    SETP_GE	= 449,
    SETP_GE_F	= 450,
    SETP_GE_F_I	= 451,
    SETP_GE_F_NP	= 452,
    SETP_GE_F_NPI	= 453,
    SETP_GE_I	= 454,
    SETP_GE_NP	= 455,
    SETP_GE_NPI	= 456,
    SETP_GE_U	= 457,
    SETP_GE_U_I	= 458,
    SETP_GE_U_NP	= 459,
    SETP_GE_U_NPI	= 460,
    SETP_GT	= 461,
    SETP_GT_F	= 462,
    SETP_GT_F_I	= 463,
    SETP_GT_F_NP	= 464,
    SETP_GT_F_NPI	= 465,
    SETP_GT_I	= 466,
    SETP_GT_NP	= 467,
    SETP_GT_NPI	= 468,
    SETP_GT_U	= 469,
    SETP_GT_U_I	= 470,
    SETP_GT_U_NP	= 471,
    SETP_GT_U_NPI	= 472,
    SETP_LE	= 473,
    SETP_LE_F	= 474,
    SETP_LE_F_I	= 475,
    SETP_LE_F_NP	= 476,
    SETP_LE_F_NPI	= 477,
    SETP_LE_I	= 478,
    SETP_LE_NP	= 479,
    SETP_LE_NPI	= 480,
    SETP_LE_U	= 481,
    SETP_LE_U_I	= 482,
    SETP_LE_U_NP	= 483,
    SETP_LE_U_NPI	= 484,
    SETP_LT	= 485,
    SETP_LT_F	= 486,
    SETP_LT_F_I	= 487,
    SETP_LT_F_NP	= 488,
    SETP_LT_F_NPI	= 489,
    SETP_LT_I	= 490,
    SETP_LT_NP	= 491,
    SETP_LT_NPI	= 492,
    SETP_LT_U	= 493,
    SETP_LT_U_I	= 494,
    SETP_LT_U_NP	= 495,
    SETP_LT_U_NPI	= 496,
    SETP_NE	= 497,
    SETP_NE_F	= 498,
    SETP_NE_F_I	= 499,
    SETP_NE_F_NP	= 500,
    SETP_NE_F_NPI	= 501,
    SETP_NE_I	= 502,
    SETP_NE_NP	= 503,
    SETP_NE_NPI	= 504,
    SHFL_IDX	= 505,
    SHL	= 506,
    SHLI	= 507,
    SHLI_P	= 508,
    SHL_P	= 509,
    SHR	= 510,
    SHRI	= 511,
    SHRI_P	= 512,
    SHR_P	= 513,
    SIN_F32	= 514,
    SQRT_F32	= 515,
    SRA	= 516,
    SRAI	= 517,
    SRAI_P	= 518,
    SRA_P	= 519,
    SRD	= 520,
    ST_GLOBAL	= 521,
    ST_GLOBAL_IDX	= 522,
    ST_GLOBAL_IDX_W16	= 523,
    ST_GLOBAL_IDX_W8	= 524,
    ST_GLOBAL_SLOT	= 525,
    ST_GLOBAL_SLOT_W16	= 526,
    ST_GLOBAL_SLOT_W8	= 527,
    ST_GLOBAL_W16	= 528,
    ST_GLOBAL_W8	= 529,
    ST_PRED_G	= 530,
    ST_PRED_S	= 531,
    ST_SHARED	= 532,
    ST_SHARED_IDX	= 533,
    ST_SHARED_W16	= 534,
    ST_SHARED_W8	= 535,
    SUB	= 536,
    SUBI	= 537,
    SUBI_P	= 538,
    SUB_P	= 539,
    SUB_W16	= 540,
    UNBALLOT	= 541,
    UNPACKI	= 542,
    VOTE_ANY	= 543,
    XOR	= 544,
    XORI	= 545,
    XORI_P	= 546,
    XOR_P	= 547,
    XOR_W16	= 548,
    INSTRUCTION_LIST_END = 549
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
  MCInstrDesc Insts[549];
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
    { 548,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #548 = XOR_W16
    { 547,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #547 = XOR_P
    { 546,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #546 = XORI_P
    { 545,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #545 = XORI
    { 544,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #544 = XOR
    { 543,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	302,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #543 = VOTE_ANY
    { 542,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #542 = UNPACKI
    { 541,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	299,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #541 = UNBALLOT
    { 540,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #540 = SUB_W16
    { 539,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #539 = SUB_P
    { 538,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #538 = SUBI_P
    { 537,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #537 = SUBI
    { 536,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #536 = SUB
    { 535,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #535 = ST_SHARED_W8
    { 534,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #534 = ST_SHARED_W16
    { 533,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #533 = ST_SHARED_IDX
    { 532,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #532 = ST_SHARED
    { 531,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #531 = ST_PRED_S
    { 530,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #530 = ST_PRED_G
    { 529,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #529 = ST_GLOBAL_W8
    { 528,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #528 = ST_GLOBAL_W16
    { 527,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	252,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #527 = ST_GLOBAL_SLOT_W8
    { 526,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	247,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #526 = ST_GLOBAL_SLOT_W16
    { 525,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #525 = ST_GLOBAL_SLOT
    { 524,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	237,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #524 = ST_GLOBAL_IDX_W8
    { 523,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	232,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #523 = ST_GLOBAL_IDX_W16
    { 522,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #522 = ST_GLOBAL_IDX
    { 521,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #521 = ST_GLOBAL
    { 520,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	202,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #520 = SRD
    { 519,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #519 = SRA_P
    { 518,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #518 = SRAI_P
    { 517,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #517 = SRAI
    { 516,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #516 = SRA
    { 515,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #515 = SQRT_F32
    { 514,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #514 = SIN_F32
    { 513,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #513 = SHR_P
    { 512,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #512 = SHRI_P
    { 511,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #511 = SHRI
    { 510,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #510 = SHR
    { 509,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #509 = SHL_P
    { 508,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #508 = SHLI_P
    { 507,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #507 = SHLI
    { 506,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #506 = SHL
    { 505,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #505 = SHFL_IDX
    { 504,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #504 = SETP_NE_NPI
    { 503,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #503 = SETP_NE_NP
    { 502,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #502 = SETP_NE_I
    { 501,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #501 = SETP_NE_F_NPI
    { 500,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #500 = SETP_NE_F_NP
    { 499,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #499 = SETP_NE_F_I
    { 498,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #498 = SETP_NE_F
    { 497,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #497 = SETP_NE
    { 496,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #496 = SETP_LT_U_NPI
    { 495,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #495 = SETP_LT_U_NP
    { 494,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #494 = SETP_LT_U_I
    { 493,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #493 = SETP_LT_U
    { 492,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #492 = SETP_LT_NPI
    { 491,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #491 = SETP_LT_NP
    { 490,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #490 = SETP_LT_I
    { 489,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #489 = SETP_LT_F_NPI
    { 488,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #488 = SETP_LT_F_NP
    { 487,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #487 = SETP_LT_F_I
    { 486,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #486 = SETP_LT_F
    { 485,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #485 = SETP_LT
    { 484,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #484 = SETP_LE_U_NPI
    { 483,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #483 = SETP_LE_U_NP
    { 482,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #482 = SETP_LE_U_I
    { 481,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #481 = SETP_LE_U
    { 480,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #480 = SETP_LE_NPI
    { 479,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #479 = SETP_LE_NP
    { 478,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #478 = SETP_LE_I
    { 477,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #477 = SETP_LE_F_NPI
    { 476,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #476 = SETP_LE_F_NP
    { 475,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #475 = SETP_LE_F_I
    { 474,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #474 = SETP_LE_F
    { 473,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #473 = SETP_LE
    { 472,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #472 = SETP_GT_U_NPI
    { 471,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #471 = SETP_GT_U_NP
    { 470,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #470 = SETP_GT_U_I
    { 469,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #469 = SETP_GT_U
    { 468,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #468 = SETP_GT_NPI
    { 467,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #467 = SETP_GT_NP
    { 466,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #466 = SETP_GT_I
    { 465,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #465 = SETP_GT_F_NPI
    { 464,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #464 = SETP_GT_F_NP
    { 463,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #463 = SETP_GT_F_I
    { 462,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #462 = SETP_GT_F
    { 461,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #461 = SETP_GT
    { 460,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #460 = SETP_GE_U_NPI
    { 459,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #459 = SETP_GE_U_NP
    { 458,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #458 = SETP_GE_U_I
    { 457,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #457 = SETP_GE_U
    { 456,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #456 = SETP_GE_NPI
    { 455,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #455 = SETP_GE_NP
    { 454,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #454 = SETP_GE_I
    { 453,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #453 = SETP_GE_F_NPI
    { 452,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #452 = SETP_GE_F_NP
    { 451,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #451 = SETP_GE_F_I
    { 450,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #450 = SETP_GE_F
    { 449,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #449 = SETP_GE
    { 448,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #448 = SETP_EQ_NPI
    { 447,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #447 = SETP_EQ_NP
    { 446,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #446 = SETP_EQ_I
    { 445,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	295,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #445 = SETP_EQ_F_NPI
    { 444,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	291,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #444 = SETP_EQ_F_NP
    { 443,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	286,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #443 = SETP_EQ_F_I
    { 442,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #442 = SETP_EQ_F
    { 441,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	281,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #441 = SETP_EQ
    { 440,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #440 = SEL
    { 439,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #439 = RSQRT_F32
    { 438,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #438 = RCP_U32
    { 437,	5,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #437 = RCP_F32_P
    { 436,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #436 = RCP_F32
    { 435,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #435 = PXOR
    { 434,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #434 = POR
    { 433,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #433 = POPC
    { 432,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	279,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #432 = PMOV_IMM
    { 431,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #431 = PMOV
    { 430,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	276,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #430 = PAND
    { 429,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #429 = PACKI_Z
    { 428,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	272,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #428 = PACKI
    { 427,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #427 = OR_W16
    { 426,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #426 = OR_P
    { 425,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #425 = ORI_P
    { 424,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #424 = ORI
    { 423,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #423 = OR
    { 422,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #422 = NEG
    { 421,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #421 = MUL_LO
    { 420,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #420 = MUL_HI_U_P
    { 419,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #419 = MUL_HI_U
    { 418,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #418 = MUL_HI_S_P
    { 417,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #417 = MUL_HI_S
    { 416,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #416 = MULI_P
    { 415,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #415 = MULI
    { 414,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	266,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #414 = MOV_P
    { 413,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	202,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #413 = MOVI48
    { 412,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	202,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #412 = MOVI
    { 411,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #411 = MIN_U_P
    { 410,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #410 = MIN_U
    { 409,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #409 = MIN_S_W16
    { 408,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #408 = MIN_S_P
    { 407,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #407 = MIN_S
    { 406,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #406 = MAX_U_P
    { 405,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #405 = MAX_U
    { 404,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #404 = MAX_S_W16
    { 403,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #403 = MAX_S_P
    { 402,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #402 = MAX_S
    { 401,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #401 = MAD_ACC
    { 400,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #400 = MADLO_P
    { 399,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #399 = MADLO
    { 398,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #398 = LG2_F32
    { 397,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #397 = LD_SHARED_W8
    { 396,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #396 = LD_SHARED_W16
    { 395,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #395 = LD_SHARED_IDX
    { 394,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #394 = LD_SHARED
    { 393,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #393 = LD_PRED_S
    { 392,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	263,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #392 = LD_PRED_G
    { 391,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	260,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #391 = LD_GLOBAL_W8
    { 390,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	257,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #390 = LD_GLOBAL_W16
    { 389,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	252,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #389 = LD_GLOBAL_SLOT_W8
    { 388,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	247,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #388 = LD_GLOBAL_SLOT_W16
    { 387,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	242,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #387 = LD_GLOBAL_SLOT
    { 386,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #386 = LD_GLOBAL_P
    { 385,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	237,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #385 = LD_GLOBAL_IDX_W8
    { 384,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	232,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #384 = LD_GLOBAL_IDX_W16
    { 383,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	227,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #383 = LD_GLOBAL_IDX
    { 382,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #382 = LD_GLOBAL
    { 381,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #381 = FSUB_P
    { 380,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #380 = FSUB
    { 379,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #379 = FNEG_F0
    { 378,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #378 = FMUL_P
    { 377,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #377 = FMUL
    { 376,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #376 = FMIN
    { 375,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #375 = FMAX
    { 374,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #374 = FFMA_F0
    { 373,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #373 = FFMA_ACC_F1
    { 372,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #372 = FFMA_ACC_F0
    { 371,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #371 = FADD_P
    { 370,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #370 = FADD
    { 369,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #369 = FABS_F0
    { 368,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #368 = EX2_F32
    { 367,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #367 = DP4_SS
    { 366,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #366 = DP4_E5M2
    { 365,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #365 = DP4_E4M3
    { 364,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #364 = DP4_ACC
    { 363,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #363 = DP2_F16
    { 362,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #362 = DP2_BF16
    { 361,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #361 = C_XORI
    { 360,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #360 = C_XOR
    { 359,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #359 = C_SUBI
    { 358,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #358 = C_SUB
    { 357,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	215,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #357 = C_ST_GLOBAL
    { 356,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #356 = C_SRAI
    { 355,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #355 = C_SRA
    { 354,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #354 = C_SHRI
    { 353,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #353 = C_SHR
    { 352,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #352 = C_SHLI
    { 351,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #351 = C_SHL
    { 350,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #350 = C_RET
    { 349,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #349 = C_RECONV
    { 348,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #348 = C_ORI
    { 347,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #347 = C_OR
    { 346,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	215,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #346 = C_NOT
    { 345,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	215,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #345 = C_NEG
    { 344,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #344 = C_MUL_LO
    { 343,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	215,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #343 = C_MOV
    { 342,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #342 = C_MIN_U
    { 341,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #341 = C_MIN_S
    { 340,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #340 = C_MAX_U
    { 339,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #339 = C_MAX_S
    { 338,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	215,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #338 = C_LD_GLOBAL
    { 337,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #337 = C_FMUL
    { 336,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #336 = C_FMIN
    { 335,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #335 = C_FMAX
    { 334,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #334 = C_FENCE
    { 333,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #333 = C_FADD
    { 332,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #332 = C_EXIT
    { 331,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	202,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #331 = C_CHWIDTH
    { 330,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #330 = C_BRA
    { 329,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #329 = C_BAR_WAIT
    { 328,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #328 = C_BAR_ARRIVE
    { 327,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #327 = C_ANDN
    { 326,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #326 = C_ANDI
    { 325,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #325 = C_AND
    { 324,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	220,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #324 = C_ADDI
    { 323,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	217,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #323 = C_ADD
    { 322,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	215,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #322 = C_ABS
    { 321,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #321 = CVT_U32_F32_P
    { 320,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #320 = CVT_U32_F32
    { 319,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #319 = CVT_SEXT
    { 318,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #318 = CVT_S32_F32_P
    { 317,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #317 = CVT_S32_F32
    { 316,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #316 = CVT_F32_U32_P
    { 315,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #315 = CVT_F32_U32
    { 314,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #314 = CVT_F32_S32_P
    { 313,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #313 = CVT_F32_S32
    { 312,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #312 = COS_F32
    { 311,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #311 = CLZ
    { 310,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #310 = CHWIDTH_MULTI
    { 309,	7,	2,	6,	0,	0,	0,	CCVImpOpBase + 0,	204,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #309 = CAS_G
    { 308,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	202,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #308 = CALL
    { 307,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #307 = BREV
    { 306,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	200,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #306 = BRA_PRED
    { 305,	1,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #305 = BRA
    { 304,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	197,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #304 = BAR_WAIT_PHASE
    { 303,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #303 = BAR_INIT
    { 302,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	194,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #302 = BALLOT
    { 301,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #301 = ATOM_ADD_G
    { 300,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #300 = AND_W16
    { 299,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #299 = AND_P
    { 298,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #298 = ANDNI_P
    { 297,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #297 = ANDNI
    { 296,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #296 = ANDN
    { 295,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #295 = ANDI_P
    { 294,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #294 = ANDI
    { 293,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #293 = AND
    { 292,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #292 = ADD_W16
    { 291,	6,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	180,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #291 = ADD_PP
    { 290,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	175,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #290 = ADD_P
    { 289,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	172,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #289 = ADDI_W16
    { 288,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	167,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #288 = ADDI_PP
    { 287,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #287 = ADDI_P
    { 286,	3,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #286 = ADDI48
    { 285,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	160,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #285 = ADDI
    { 284,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #284 = ADD
    { 283,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #283 = ABS
    { 282,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #282 = PSEUDO_ST_PRED
    { 281,	1,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	155,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #281 = PSEUDO_RET
    { 280,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #280 = PSEUDO_PXOR
    { 279,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #279 = PSEUDO_POR
    { 278,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	151,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #278 = PSEUDO_PMOV
    { 277,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #277 = PSEUDO_PAND
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
    /* 148 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 151 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 155 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 156 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 160 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 163 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 167 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 172 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 175 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 180 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 186 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 190 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 194 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 197 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 200 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 202 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 204 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 211 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 215 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
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
  /* 54 */ "FFMA_ACC_F1\0"
  /* 66 */ "CVT_S32_F32\0"
  /* 78 */ "CVT_U32_F32\0"
  /* 90 */ "LG2_F32\0"
  /* 98 */ "EX2_F32\0"
  /* 106 */ "SIN_F32\0"
  /* 114 */ "RCP_F32\0"
  /* 122 */ "COS_F32\0"
  /* 130 */ "RSQRT_F32\0"
  /* 140 */ "CVT_F32_S32\0"
  /* 152 */ "CVT_F32_U32\0"
  /* 164 */ "RCP_U32\0"
  /* 172 */ "G_FLOG2\0"
  /* 180 */ "DP4_E5M2\0"
  /* 189 */ "G_FEXP2\0"
  /* 197 */ "DP4_E4M3\0"
  /* 206 */ "DP2_BF16\0"
  /* 215 */ "DP2_F16\0"
  /* 223 */ "SUB_W16\0"
  /* 231 */ "ADD_W16\0"
  /* 239 */ "LD_SHARED_W16\0"
  /* 253 */ "ST_SHARED_W16\0"
  /* 267 */ "AND_W16\0"
  /* 275 */ "ADDI_W16\0"
  /* 284 */ "LD_GLOBAL_W16\0"
  /* 298 */ "ST_GLOBAL_W16\0"
  /* 312 */ "XOR_W16\0"
  /* 320 */ "MIN_S_W16\0"
  /* 330 */ "MAX_S_W16\0"
  /* 340 */ "LD_GLOBAL_SLOT_W16\0"
  /* 359 */ "ST_GLOBAL_SLOT_W16\0"
  /* 378 */ "LD_GLOBAL_IDX_W16\0"
  /* 396 */ "ST_GLOBAL_IDX_W16\0"
  /* 414 */ "ADDI48\0"
  /* 421 */ "MOVI48\0"
  /* 428 */ "LD_SHARED_W8\0"
  /* 441 */ "ST_SHARED_W8\0"
  /* 454 */ "LD_GLOBAL_W8\0"
  /* 467 */ "ST_GLOBAL_W8\0"
  /* 480 */ "LD_GLOBAL_SLOT_W8\0"
  /* 498 */ "ST_GLOBAL_SLOT_W8\0"
  /* 516 */ "LD_GLOBAL_IDX_W8\0"
  /* 533 */ "ST_GLOBAL_IDX_W8\0"
  /* 550 */ "G_FMA\0"
  /* 556 */ "G_STRICT_FMA\0"
  /* 569 */ "C_BRA\0"
  /* 575 */ "C_SRA\0"
  /* 581 */ "G_FSUB\0"
  /* 588 */ "G_STRICT_FSUB\0"
  /* 602 */ "G_ATOMICRMW_FSUB\0"
  /* 619 */ "C_SUB\0"
  /* 625 */ "G_SUB\0"
  /* 631 */ "G_ATOMICRMW_SUB\0"
  /* 647 */ "DP4_ACC\0"
  /* 655 */ "MAD_ACC\0"
  /* 663 */ "G_INTRINSIC\0"
  /* 675 */ "G_FPTRUNC\0"
  /* 685 */ "G_INTRINSIC_TRUNC\0"
  /* 703 */ "G_TRUNC\0"
  /* 711 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 732 */ "G_DYN_STACKALLOC\0"
  /* 749 */ "POPC\0"
  /* 754 */ "G_FMAD\0"
  /* 761 */ "G_INDEXED_SEXTLOAD\0"
  /* 780 */ "G_SEXTLOAD\0"
  /* 791 */ "G_INDEXED_ZEXTLOAD\0"
  /* 810 */ "G_ZEXTLOAD\0"
  /* 821 */ "G_INDEXED_LOAD\0"
  /* 836 */ "G_LOAD\0"
  /* 843 */ "C_FADD\0"
  /* 850 */ "G_VECREDUCE_FADD\0"
  /* 867 */ "G_FADD\0"
  /* 874 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 895 */ "G_STRICT_FADD\0"
  /* 909 */ "G_ATOMICRMW_FADD\0"
  /* 926 */ "C_ADD\0"
  /* 932 */ "G_VECREDUCE_ADD\0"
  /* 948 */ "G_ADD\0"
  /* 954 */ "G_PTR_ADD\0"
  /* 964 */ "G_ATOMICRMW_ADD\0"
  /* 980 */ "LD_SHARED\0"
  /* 990 */ "ST_SHARED\0"
  /* 1000 */ "PSEUDO_BRA_PRED\0"
  /* 1016 */ "PSEUDO_LD_PRED\0"
  /* 1031 */ "PSEUDO_ST_PRED\0"
  /* 1046 */ "G_ATOMICRMW_NAND\0"
  /* 1063 */ "PSEUDO_PAND\0"
  /* 1075 */ "C_AND\0"
  /* 1081 */ "G_VECREDUCE_AND\0"
  /* 1097 */ "G_AND\0"
  /* 1103 */ "G_ATOMICRMW_AND\0"
  /* 1119 */ "LIFETIME_END\0"
  /* 1132 */ "G_BRCOND\0"
  /* 1141 */ "G_LLROUND\0"
  /* 1151 */ "G_LROUND\0"
  /* 1160 */ "G_INTRINSIC_ROUND\0"
  /* 1178 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 1204 */ "LOAD_STACK_GUARD\0"
  /* 1221 */ "SRD\0"
  /* 1225 */ "PSEUDO_PROBE\0"
  /* 1238 */ "G_SSUBE\0"
  /* 1246 */ "G_USUBE\0"
  /* 1254 */ "C_FENCE\0"
  /* 1262 */ "G_FENCE\0"
  /* 1270 */ "ARITH_FENCE\0"
  /* 1282 */ "REG_SEQUENCE\0"
  /* 1295 */ "G_SADDE\0"
  /* 1303 */ "G_UADDE\0"
  /* 1311 */ "G_GET_FPMODE\0"
  /* 1324 */ "G_RESET_FPMODE\0"
  /* 1339 */ "G_SET_FPMODE\0"
  /* 1352 */ "G_FMINNUM_IEEE\0"
  /* 1367 */ "G_FMAXNUM_IEEE\0"
  /* 1382 */ "SETP_GE\0"
  /* 1390 */ "G_JUMP_TABLE\0"
  /* 1403 */ "BUNDLE\0"
  /* 1410 */ "SETP_LE\0"
  /* 1418 */ "G_MEMCPY_INLINE\0"
  /* 1434 */ "SETP_NE\0"
  /* 1442 */ "LOCAL_ESCAPE\0"
  /* 1455 */ "G_STACKRESTORE\0"
  /* 1470 */ "G_INDEXED_STORE\0"
  /* 1486 */ "G_STORE\0"
  /* 1494 */ "BAR_WAIT_PHASE\0"
  /* 1509 */ "G_BITREVERSE\0"
  /* 1522 */ "DBG_VALUE\0"
  /* 1532 */ "G_GLOBAL_VALUE\0"
  /* 1547 */ "G_STACKSAVE\0"
  /* 1559 */ "C_BAR_ARRIVE\0"
  /* 1572 */ "G_MEMMOVE\0"
  /* 1582 */ "G_FREEZE\0"
  /* 1591 */ "G_FCANONICALIZE\0"
  /* 1607 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 1625 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 1643 */ "G_IMPLICIT_DEF\0"
  /* 1658 */ "DBG_INSTR_REF\0"
  /* 1672 */ "SETP_GE_F\0"
  /* 1682 */ "SETP_LE_F\0"
  /* 1692 */ "SETP_NE_F\0"
  /* 1702 */ "SETP_EQ_F\0"
  /* 1712 */ "SETP_GT_F\0"
  /* 1722 */ "SETP_LT_F\0"
  /* 1732 */ "G_FNEG\0"
  /* 1739 */ "C_NEG\0"
  /* 1745 */ "EXTRACT_SUBREG\0"
  /* 1760 */ "INSERT_SUBREG\0"
  /* 1774 */ "G_SEXT_INREG\0"
  /* 1787 */ "SUBREG_TO_REG\0"
  /* 1801 */ "G_ATOMIC_CMPXCHG\0"
  /* 1818 */ "G_ATOMICRMW_XCHG\0"
  /* 1835 */ "G_FLOG\0"
  /* 1842 */ "G_VAARG\0"
  /* 1850 */ "PREALLOCATED_ARG\0"
  /* 1867 */ "ATOM_ADD_G\0"
  /* 1878 */ "LD_PRED_G\0"
  /* 1888 */ "ST_PRED_G\0"
  /* 1898 */ "CAS_G\0"
  /* 1904 */ "G_PREFETCH\0"
  /* 1915 */ "G_SMULH\0"
  /* 1923 */ "G_UMULH\0"
  /* 1931 */ "C_CHWIDTH\0"
  /* 1941 */ "C_SRAI\0"
  /* 1948 */ "C_SUBI\0"
  /* 1955 */ "C_ADDI\0"
  /* 1962 */ "C_ANDI\0"
  /* 1969 */ "DBG_PHI\0"
  /* 1977 */ "UNPACKI\0"
  /* 1985 */ "C_SHLI\0"
  /* 1992 */ "MULI\0"
  /* 1997 */ "ANDNI\0"
  /* 2003 */ "SETP_GE_NPI\0"
  /* 2015 */ "SETP_LE_NPI\0"
  /* 2027 */ "SETP_NE_NPI\0"
  /* 2039 */ "SETP_GE_F_NPI\0"
  /* 2053 */ "SETP_LE_F_NPI\0"
  /* 2067 */ "SETP_NE_F_NPI\0"
  /* 2081 */ "SETP_EQ_F_NPI\0"
  /* 2095 */ "SETP_GT_F_NPI\0"
  /* 2109 */ "SETP_LT_F_NPI\0"
  /* 2123 */ "SETP_EQ_NPI\0"
  /* 2135 */ "SETP_GT_NPI\0"
  /* 2147 */ "SETP_LT_NPI\0"
  /* 2159 */ "SETP_GE_U_NPI\0"
  /* 2173 */ "SETP_LE_U_NPI\0"
  /* 2187 */ "SETP_GT_U_NPI\0"
  /* 2201 */ "SETP_LT_U_NPI\0"
  /* 2215 */ "C_SHRI\0"
  /* 2222 */ "C_XORI\0"
  /* 2229 */ "C_ORI\0"
  /* 2235 */ "G_FPTOSI\0"
  /* 2244 */ "CHWIDTH_MULTI\0"
  /* 2258 */ "G_FPTOUI\0"
  /* 2267 */ "MOVI\0"
  /* 2272 */ "G_FPOWI\0"
  /* 2280 */ "SETP_GE_I\0"
  /* 2290 */ "SETP_LE_I\0"
  /* 2300 */ "SETP_NE_I\0"
  /* 2310 */ "SETP_GE_F_I\0"
  /* 2322 */ "SETP_LE_F_I\0"
  /* 2334 */ "SETP_NE_F_I\0"
  /* 2346 */ "SETP_EQ_F_I\0"
  /* 2358 */ "SETP_GT_F_I\0"
  /* 2370 */ "SETP_LT_F_I\0"
  /* 2382 */ "SETP_EQ_I\0"
  /* 2392 */ "SETP_GT_I\0"
  /* 2402 */ "SETP_LT_I\0"
  /* 2412 */ "SETP_GE_U_I\0"
  /* 2424 */ "SETP_LE_U_I\0"
  /* 2436 */ "SETP_GT_U_I\0"
  /* 2448 */ "SETP_LT_U_I\0"
  /* 2460 */ "G_PTRMASK\0"
  /* 2470 */ "C_LD_GLOBAL\0"
  /* 2482 */ "C_ST_GLOBAL\0"
  /* 2494 */ "GC_LABEL\0"
  /* 2503 */ "DBG_LABEL\0"
  /* 2513 */ "EH_LABEL\0"
  /* 2522 */ "ANNOTATION_LABEL\0"
  /* 2539 */ "ICALL_BRANCH_FUNNEL\0"
  /* 2559 */ "SEL\0"
  /* 2563 */ "G_FSHL\0"
  /* 2570 */ "C_SHL\0"
  /* 2576 */ "G_SHL\0"
  /* 2582 */ "G_FCEIL\0"
  /* 2590 */ "PATCHABLE_TAIL_CALL\0"
  /* 2610 */ "PSEUDO_CALL\0"
  /* 2622 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 2649 */ "PATCHABLE_EVENT_CALL\0"
  /* 2670 */ "FENTRY_CALL\0"
  /* 2682 */ "KILL\0"
  /* 2687 */ "G_CONSTANT_POOL\0"
  /* 2703 */ "G_ROTL\0"
  /* 2710 */ "C_FMUL\0"
  /* 2717 */ "G_VECREDUCE_FMUL\0"
  /* 2734 */ "G_FMUL\0"
  /* 2741 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 2762 */ "G_STRICT_FMUL\0"
  /* 2776 */ "G_VECREDUCE_MUL\0"
  /* 2792 */ "G_MUL\0"
  /* 2798 */ "G_FREM\0"
  /* 2805 */ "G_STRICT_FREM\0"
  /* 2819 */ "G_SREM\0"
  /* 2826 */ "G_UREM\0"
  /* 2833 */ "G_SDIVREM\0"
  /* 2843 */ "G_UDIVREM\0"
  /* 2853 */ "PMOV_IMM\0"
  /* 2862 */ "INLINEASM\0"
  /* 2872 */ "G_VECREDUCE_FMINIMUM\0"
  /* 2893 */ "G_FMINIMUM\0"
  /* 2904 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 2925 */ "G_FMAXIMUM\0"
  /* 2936 */ "G_FMINNUM\0"
  /* 2946 */ "G_FMAXNUM\0"
  /* 2956 */ "C_ANDN\0"
  /* 2963 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 2985 */ "G_ASSERT_ALIGN\0"
  /* 3000 */ "G_FCOPYSIGN\0"
  /* 3012 */ "C_FMIN\0"
  /* 3019 */ "G_VECREDUCE_FMIN\0"
  /* 3036 */ "G_ATOMICRMW_FMIN\0"
  /* 3053 */ "G_VECREDUCE_SMIN\0"
  /* 3070 */ "G_SMIN\0"
  /* 3077 */ "G_VECREDUCE_UMIN\0"
  /* 3094 */ "G_UMIN\0"
  /* 3101 */ "G_ATOMICRMW_UMIN\0"
  /* 3118 */ "G_ATOMICRMW_MIN\0"
  /* 3134 */ "G_FSIN\0"
  /* 3141 */ "CFI_INSTRUCTION\0"
  /* 3157 */ "ADJCALLSTACKDOWN\0"
  /* 3174 */ "G_SSUBO\0"
  /* 3182 */ "G_USUBO\0"
  /* 3190 */ "G_SADDO\0"
  /* 3198 */ "G_UADDO\0"
  /* 3206 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 3228 */ "MADLO\0"
  /* 3234 */ "G_SMULO\0"
  /* 3242 */ "G_UMULO\0"
  /* 3250 */ "C_MUL_LO\0"
  /* 3259 */ "G_BZERO\0"
  /* 3267 */ "STACKMAP\0"
  /* 3276 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 3298 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 3320 */ "G_BSWAP\0"
  /* 3328 */ "G_SITOFP\0"
  /* 3337 */ "G_UITOFP\0"
  /* 3346 */ "G_FCMP\0"
  /* 3353 */ "G_ICMP\0"
  /* 3360 */ "SETP_GE_NP\0"
  /* 3371 */ "SETP_LE_NP\0"
  /* 3382 */ "SETP_NE_NP\0"
  /* 3393 */ "SETP_GE_F_NP\0"
  /* 3406 */ "SETP_LE_F_NP\0"
  /* 3419 */ "SETP_NE_F_NP\0"
  /* 3432 */ "SETP_EQ_F_NP\0"
  /* 3445 */ "SETP_GT_F_NP\0"
  /* 3458 */ "SETP_LT_F_NP\0"
  /* 3471 */ "SETP_EQ_NP\0"
  /* 3482 */ "SETP_GT_NP\0"
  /* 3493 */ "SETP_LT_NP\0"
  /* 3504 */ "SETP_GE_U_NP\0"
  /* 3517 */ "SETP_LE_U_NP\0"
  /* 3530 */ "SETP_GT_U_NP\0"
  /* 3543 */ "SETP_LT_U_NP\0"
  /* 3556 */ "G_CTPOP\0"
  /* 3564 */ "PATCHABLE_OP\0"
  /* 3577 */ "FAULTING_OP\0"
  /* 3589 */ "ADD_PP\0"
  /* 3596 */ "ADDI_PP\0"
  /* 3604 */ "ADJCALLSTACKUP\0"
  /* 3619 */ "PREALLOCATED_SETUP\0"
  /* 3638 */ "G_FLDEXP\0"
  /* 3647 */ "G_STRICT_FLDEXP\0"
  /* 3663 */ "G_FEXP\0"
  /* 3670 */ "G_FFREXP\0"
  /* 3679 */ "CVT_S32_F32_P\0"
  /* 3693 */ "CVT_U32_F32_P\0"
  /* 3707 */ "RCP_F32_P\0"
  /* 3717 */ "CVT_F32_S32_P\0"
  /* 3731 */ "CVT_F32_U32_P\0"
  /* 3745 */ "SRA_P\0"
  /* 3751 */ "FSUB_P\0"
  /* 3758 */ "FADD_P\0"
  /* 3765 */ "AND_P\0"
  /* 3771 */ "SRAI_P\0"
  /* 3778 */ "SUBI_P\0"
  /* 3785 */ "ADDI_P\0"
  /* 3792 */ "ANDI_P\0"
  /* 3799 */ "SHLI_P\0"
  /* 3806 */ "MULI_P\0"
  /* 3813 */ "ANDNI_P\0"
  /* 3821 */ "SHRI_P\0"
  /* 3828 */ "XORI_P\0"
  /* 3835 */ "LD_GLOBAL_P\0"
  /* 3847 */ "SHL_P\0"
  /* 3853 */ "FMUL_P\0"
  /* 3860 */ "MADLO_P\0"
  /* 3868 */ "SHR_P\0"
  /* 3874 */ "XOR_P\0"
  /* 3880 */ "MUL_HI_S_P\0"
  /* 3891 */ "MIN_S_P\0"
  /* 3899 */ "MAX_S_P\0"
  /* 3907 */ "MUL_HI_U_P\0"
  /* 3918 */ "MIN_U_P\0"
  /* 3926 */ "MAX_U_P\0"
  /* 3934 */ "MOV_P\0"
  /* 3940 */ "SETP_EQ\0"
  /* 3948 */ "G_BR\0"
  /* 3953 */ "INLINEASM_BR\0"
  /* 3966 */ "G_BLOCK_ADDR\0"
  /* 3979 */ "MEMBARRIER\0"
  /* 3990 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 4014 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 4039 */ "G_READCYCLECOUNTER\0"
  /* 4058 */ "G_READ_REGISTER\0"
  /* 4074 */ "G_WRITE_REGISTER\0"
  /* 4091 */ "G_ASHR\0"
  /* 4098 */ "G_FSHR\0"
  /* 4105 */ "G_LSHR\0"
  /* 4112 */ "C_SHR\0"
  /* 4118 */ "G_FFLOOR\0"
  /* 4127 */ "PSEUDO_POR\0"
  /* 4138 */ "G_BUILD_VECTOR\0"
  /* 4153 */ "G_SHUFFLE_VECTOR\0"
  /* 4170 */ "PSEUDO_PXOR\0"
  /* 4182 */ "C_XOR\0"
  /* 4188 */ "G_VECREDUCE_XOR\0"
  /* 4204 */ "G_XOR\0"
  /* 4210 */ "G_ATOMICRMW_XOR\0"
  /* 4226 */ "C_OR\0"
  /* 4231 */ "G_VECREDUCE_OR\0"
  /* 4246 */ "G_OR\0"
  /* 4251 */ "G_ATOMICRMW_OR\0"
  /* 4266 */ "G_ROTR\0"
  /* 4273 */ "G_INTTOPTR\0"
  /* 4284 */ "G_FABS\0"
  /* 4291 */ "C_ABS\0"
  /* 4297 */ "G_ABS\0"
  /* 4303 */ "G_UNMERGE_VALUES\0"
  /* 4320 */ "G_MERGE_VALUES\0"
  /* 4335 */ "G_FCOS\0"
  /* 4342 */ "G_CONCAT_VECTORS\0"
  /* 4359 */ "COPY_TO_REGCLASS\0"
  /* 4376 */ "G_IS_FPCLASS\0"
  /* 4389 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 4419 */ "DP4_SS\0"
  /* 4426 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 4453 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 4491 */ "LD_PRED_S\0"
  /* 4501 */ "ST_PRED_S\0"
  /* 4511 */ "MUL_HI_S\0"
  /* 4520 */ "C_MIN_S\0"
  /* 4528 */ "C_MAX_S\0"
  /* 4536 */ "G_SSUBSAT\0"
  /* 4546 */ "G_USUBSAT\0"
  /* 4556 */ "G_SADDSAT\0"
  /* 4566 */ "G_UADDSAT\0"
  /* 4576 */ "G_SSHLSAT\0"
  /* 4586 */ "G_USHLSAT\0"
  /* 4596 */ "G_SMULFIXSAT\0"
  /* 4609 */ "G_UMULFIXSAT\0"
  /* 4622 */ "G_SDIVFIXSAT\0"
  /* 4635 */ "G_UDIVFIXSAT\0"
  /* 4648 */ "G_EXTRACT\0"
  /* 4658 */ "G_SELECT\0"
  /* 4667 */ "G_BRINDIRECT\0"
  /* 4680 */ "C_RET\0"
  /* 4686 */ "PATCHABLE_RET\0"
  /* 4700 */ "PSEUDO_RET\0"
  /* 4711 */ "G_MEMSET\0"
  /* 4720 */ "SETP_GT\0"
  /* 4728 */ "C_BAR_WAIT\0"
  /* 4739 */ "BAR_INIT\0"
  /* 4748 */ "C_EXIT\0"
  /* 4755 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 4779 */ "G_BRJT\0"
  /* 4786 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 4807 */ "G_INSERT_VECTOR_ELT\0"
  /* 4827 */ "SETP_LT\0"
  /* 4835 */ "G_FCONSTANT\0"
  /* 4847 */ "G_CONSTANT\0"
  /* 4858 */ "G_INTRINSIC_CONVERGENT\0"
  /* 4881 */ "STATEPOINT\0"
  /* 4892 */ "PATCHPOINT\0"
  /* 4903 */ "G_PTRTOINT\0"
  /* 4914 */ "G_FRINT\0"
  /* 4922 */ "G_INTRINSIC_LRINT\0"
  /* 4940 */ "G_FNEARBYINT\0"
  /* 4953 */ "UNBALLOT\0"
  /* 4962 */ "LD_GLOBAL_SLOT\0"
  /* 4977 */ "ST_GLOBAL_SLOT\0"
  /* 4992 */ "C_NOT\0"
  /* 4998 */ "G_VASTART\0"
  /* 5008 */ "LIFETIME_START\0"
  /* 5023 */ "G_INVOKE_REGION_START\0"
  /* 5045 */ "G_INSERT\0"
  /* 5054 */ "G_FSQRT\0"
  /* 5062 */ "G_STRICT_FSQRT\0"
  /* 5077 */ "PSEUDO_BCAST\0"
  /* 5090 */ "G_BITCAST\0"
  /* 5100 */ "G_ADDRSPACE_CAST\0"
  /* 5117 */ "DBG_VALUE_LIST\0"
  /* 5132 */ "G_FPEXT\0"
  /* 5140 */ "G_SEXT\0"
  /* 5147 */ "G_ASSERT_SEXT\0"
  /* 5161 */ "CVT_SEXT\0"
  /* 5170 */ "G_ANYEXT\0"
  /* 5179 */ "G_ZEXT\0"
  /* 5186 */ "G_ASSERT_ZEXT\0"
  /* 5200 */ "SETP_GE_U\0"
  /* 5210 */ "SETP_LE_U\0"
  /* 5220 */ "MUL_HI_U\0"
  /* 5229 */ "C_MIN_U\0"
  /* 5237 */ "SETP_GT_U\0"
  /* 5247 */ "SETP_LT_U\0"
  /* 5257 */ "C_MAX_U\0"
  /* 5265 */ "BREV\0"
  /* 5270 */ "G_FDIV\0"
  /* 5277 */ "G_STRICT_FDIV\0"
  /* 5291 */ "G_SDIV\0"
  /* 5298 */ "G_UDIV\0"
  /* 5305 */ "G_GET_FPENV\0"
  /* 5317 */ "G_RESET_FPENV\0"
  /* 5331 */ "G_SET_FPENV\0"
  /* 5343 */ "C_RECONV\0"
  /* 5352 */ "PSEUDO_PMOV\0"
  /* 5364 */ "C_MOV\0"
  /* 5370 */ "G_FPOW\0"
  /* 5377 */ "C_FMAX\0"
  /* 5384 */ "G_VECREDUCE_FMAX\0"
  /* 5401 */ "G_ATOMICRMW_FMAX\0"
  /* 5418 */ "G_VECREDUCE_SMAX\0"
  /* 5435 */ "G_SMAX\0"
  /* 5442 */ "G_VECREDUCE_UMAX\0"
  /* 5459 */ "G_UMAX\0"
  /* 5466 */ "G_ATOMICRMW_UMAX\0"
  /* 5483 */ "G_ATOMICRMW_MAX\0"
  /* 5499 */ "LD_SHARED_IDX\0"
  /* 5513 */ "ST_SHARED_IDX\0"
  /* 5527 */ "LD_GLOBAL_IDX\0"
  /* 5541 */ "ST_GLOBAL_IDX\0"
  /* 5555 */ "SHFL_IDX\0"
  /* 5564 */ "G_FRAME_INDEX\0"
  /* 5578 */ "G_SBFX\0"
  /* 5585 */ "G_UBFX\0"
  /* 5592 */ "G_SMULFIX\0"
  /* 5602 */ "G_UMULFIX\0"
  /* 5612 */ "G_SDIVFIX\0"
  /* 5622 */ "G_UDIVFIX\0"
  /* 5632 */ "VOTE_ANY\0"
  /* 5641 */ "G_MEMCPY\0"
  /* 5650 */ "COPY\0"
  /* 5655 */ "CLZ\0"
  /* 5659 */ "G_CTLZ\0"
  /* 5666 */ "G_CTTZ\0"
  /* 5673 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    1973U, 2862U, 3953U, 3141U, 2513U, 2494U, 2522U, 2682U, 
    1745U, 1760U, 1645U, 1787U, 4359U, 1522U, 5117U, 1658U, 
    1969U, 2503U, 1282U, 5650U, 1403U, 5008U, 1119U, 1225U, 
    1270U, 3267U, 2670U, 4892U, 1204U, 3619U, 1850U, 4881U, 
    1442U, 3577U, 3564U, 4014U, 4686U, 4755U, 2590U, 2649U, 
    2622U, 2539U, 3979U, 3206U, 5147U, 5186U, 2985U, 948U, 
    625U, 2792U, 5291U, 5298U, 2819U, 2826U, 2833U, 2843U, 
    1097U, 4246U, 4204U, 1643U, 1971U, 5564U, 1532U, 2687U, 
    4648U, 4303U, 5045U, 4320U, 4138U, 711U, 4342U, 4903U, 
    4273U, 5090U, 1582U, 3990U, 1178U, 685U, 1160U, 4922U, 
    2963U, 4039U, 836U, 780U, 810U, 821U, 761U, 791U, 
    1486U, 1470U, 4389U, 1801U, 1818U, 964U, 631U, 1103U, 
    1046U, 4251U, 4210U, 5483U, 3118U, 5466U, 3101U, 909U, 
    602U, 5401U, 3036U, 3298U, 3276U, 1262U, 1904U, 1132U, 
    4667U, 5023U, 663U, 4426U, 4858U, 4453U, 5170U, 703U, 
    4847U, 4835U, 4998U, 1842U, 5140U, 1774U, 5179U, 2576U, 
    4105U, 4091U, 2563U, 4098U, 4266U, 2703U, 3353U, 3346U, 
    4658U, 3198U, 1303U, 3182U, 1246U, 3190U, 1295U, 3174U, 
    1238U, 3242U, 3234U, 1923U, 1915U, 4566U, 4556U, 4546U, 
    4536U, 4586U, 4576U, 5592U, 5602U, 4596U, 4609U, 5612U, 
    5622U, 4622U, 4635U, 867U, 581U, 2734U, 550U, 754U, 
    5270U, 2798U, 5370U, 2272U, 3663U, 189U, 9U, 1835U, 
    172U, 0U, 3638U, 3670U, 1732U, 5132U, 675U, 2235U, 
    2258U, 3328U, 3337U, 4284U, 3000U, 4376U, 1591U, 2936U, 
    2946U, 1352U, 1367U, 2893U, 2925U, 5305U, 5331U, 5317U, 
    1311U, 1339U, 1324U, 954U, 2460U, 3070U, 5435U, 3094U, 
    5459U, 4297U, 1151U, 1141U, 3948U, 4779U, 4807U, 4786U, 
    4153U, 5666U, 1625U, 5659U, 1607U, 3556U, 3320U, 1509U, 
    2582U, 4335U, 3134U, 5054U, 4118U, 4914U, 4940U, 5100U, 
    3966U, 1390U, 732U, 1547U, 1455U, 895U, 588U, 2762U, 
    5277U, 2805U, 556U, 5062U, 3647U, 4058U, 4074U, 5641U, 
    1418U, 1572U, 4711U, 3259U, 874U, 2741U, 850U, 2717U, 
    5384U, 3019U, 2904U, 2872U, 932U, 2776U, 1081U, 4231U, 
    4188U, 5418U, 3053U, 5442U, 3077U, 5578U, 5585U, 3157U, 
    3604U, 5077U, 1000U, 2610U, 1016U, 1063U, 5352U, 4127U, 
    4170U, 4700U, 1031U, 4287U, 846U, 1957U, 414U, 3785U, 
    3596U, 275U, 3759U, 3589U, 231U, 1059U, 1964U, 3792U, 
    2958U, 1997U, 3813U, 3765U, 267U, 1867U, 4955U, 4739U, 
    1494U, 571U, 1007U, 5265U, 2605U, 1898U, 2244U, 5655U, 
    122U, 140U, 3717U, 152U, 3731U, 66U, 3679U, 5161U, 
    78U, 3693U, 4291U, 926U, 1955U, 1075U, 1962U, 2956U, 
    1559U, 4728U, 569U, 1931U, 4748U, 843U, 1254U, 5377U, 
    3012U, 2710U, 2470U, 4528U, 5257U, 4520U, 5229U, 5364U, 
    3250U, 1739U, 4992U, 4226U, 2229U, 5343U, 4680U, 2570U, 
    1985U, 4112U, 2215U, 575U, 1941U, 2482U, 619U, 1948U, 
    4182U, 2222U, 206U, 215U, 647U, 197U, 180U, 4419U, 
    98U, 46U, 845U, 3758U, 26U, 54U, 18U, 5379U, 
    3014U, 2712U, 3853U, 38U, 583U, 3751U, 2472U, 5527U, 
    378U, 516U, 3835U, 4962U, 340U, 480U, 284U, 454U, 
    1878U, 4491U, 980U, 5499U, 239U, 428U, 90U, 3228U, 
    3860U, 655U, 4530U, 3899U, 330U, 5259U, 3926U, 4522U, 
    3891U, 320U, 5231U, 3918U, 2267U, 421U, 3934U, 1992U, 
    3806U, 4511U, 3880U, 5220U, 3907U, 3252U, 1735U, 4124U, 
    2225U, 3829U, 3875U, 313U, 1979U, 5673U, 1070U, 5359U, 
    2853U, 749U, 4134U, 4177U, 114U, 3707U, 164U, 130U, 
    2559U, 3940U, 1702U, 2346U, 3432U, 2081U, 2382U, 3471U, 
    2123U, 1382U, 1672U, 2310U, 3393U, 2039U, 2280U, 3360U, 
    2003U, 5200U, 2412U, 3504U, 2159U, 4720U, 1712U, 2358U, 
    3445U, 2095U, 2392U, 3482U, 2135U, 5237U, 2436U, 3530U, 
    2187U, 1410U, 1682U, 2322U, 3406U, 2053U, 2290U, 3371U, 
    2015U, 5210U, 2424U, 3517U, 2173U, 4827U, 1722U, 2370U, 
    3458U, 2109U, 2402U, 3493U, 2147U, 5247U, 2448U, 3543U, 
    2201U, 1434U, 1692U, 2334U, 3419U, 2067U, 2300U, 3382U, 
    2027U, 5555U, 2566U, 1987U, 3799U, 3847U, 4094U, 2217U, 
    3821U, 3868U, 106U, 131U, 577U, 1943U, 3771U, 3745U, 
    1221U, 2484U, 5541U, 396U, 533U, 4977U, 359U, 498U, 
    298U, 467U, 1888U, 4501U, 990U, 5513U, 253U, 441U, 
    584U, 1950U, 3778U, 3752U, 223U, 4953U, 1977U, 5632U, 
    4178U, 2224U, 3828U, 3874U, 312U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 549);
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
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 549);
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
    /* PSEUDO_PAND */
    678,
    /* PSEUDO_PMOV */
    681,
    /* PSEUDO_POR */
    685,
    /* PSEUDO_PXOR */
    688,
    /* PSEUDO_RET */
    691,
    /* PSEUDO_ST_PRED */
    692,
    /* ABS */
    695,
    /* ADD */
    699,
    /* ADDI */
    703,
    /* ADDI48 */
    706,
    /* ADDI_P */
    709,
    /* ADDI_PP */
    713,
    /* ADDI_W16 */
    718,
    /* ADD_P */
    721,
    /* ADD_PP */
    726,
    /* ADD_W16 */
    732,
    /* AND */
    736,
    /* ANDI */
    740,
    /* ANDI_P */
    743,
    /* ANDN */
    747,
    /* ANDNI */
    751,
    /* ANDNI_P */
    754,
    /* AND_P */
    758,
    /* AND_W16 */
    763,
    /* ATOM_ADD_G */
    767,
    /* BALLOT */
    771,
    /* BAR_INIT */
    774,
    /* BAR_WAIT_PHASE */
    776,
    /* BRA */
    779,
    /* BRA_PRED */
    780,
    /* BREV */
    782,
    /* CALL */
    786,
    /* CAS_G */
    788,
    /* CHWIDTH_MULTI */
    795,
    /* CLZ */
    797,
    /* COS_F32 */
    801,
    /* CVT_F32_S32 */
    805,
    /* CVT_F32_S32_P */
    809,
    /* CVT_F32_U32 */
    814,
    /* CVT_F32_U32_P */
    818,
    /* CVT_S32_F32 */
    823,
    /* CVT_S32_F32_P */
    827,
    /* CVT_SEXT */
    832,
    /* CVT_U32_F32 */
    836,
    /* CVT_U32_F32_P */
    840,
    /* C_ABS */
    845,
    /* C_ADD */
    847,
    /* C_ADDI */
    850,
    /* C_AND */
    853,
    /* C_ANDI */
    856,
    /* C_ANDN */
    859,
    /* C_BAR_ARRIVE */
    862,
    /* C_BAR_WAIT */
    863,
    /* C_BRA */
    864,
    /* C_CHWIDTH */
    865,
    /* C_EXIT */
    867,
    /* C_FADD */
    868,
    /* C_FENCE */
    871,
    /* C_FMAX */
    872,
    /* C_FMIN */
    875,
    /* C_FMUL */
    878,
    /* C_LD_GLOBAL */
    881,
    /* C_MAX_S */
    883,
    /* C_MAX_U */
    886,
    /* C_MIN_S */
    889,
    /* C_MIN_U */
    892,
    /* C_MOV */
    895,
    /* C_MUL_LO */
    897,
    /* C_NEG */
    900,
    /* C_NOT */
    902,
    /* C_OR */
    904,
    /* C_ORI */
    907,
    /* C_RECONV */
    910,
    /* C_RET */
    911,
    /* C_SHL */
    912,
    /* C_SHLI */
    915,
    /* C_SHR */
    918,
    /* C_SHRI */
    921,
    /* C_SRA */
    924,
    /* C_SRAI */
    927,
    /* C_ST_GLOBAL */
    930,
    /* C_SUB */
    932,
    /* C_SUBI */
    935,
    /* C_XOR */
    938,
    /* C_XORI */
    941,
    /* DP2_BF16 */
    944,
    /* DP2_F16 */
    948,
    /* DP4_ACC */
    952,
    /* DP4_E4M3 */
    956,
    /* DP4_E5M2 */
    960,
    /* DP4_SS */
    964,
    /* EX2_F32 */
    968,
    /* FABS_F0 */
    972,
    /* FADD */
    976,
    /* FADD_P */
    980,
    /* FFMA_ACC_F0 */
    985,
    /* FFMA_ACC_F1 */
    989,
    /* FFMA_F0 */
    993,
    /* FMAX */
    997,
    /* FMIN */
    1001,
    /* FMUL */
    1005,
    /* FMUL_P */
    1009,
    /* FNEG_F0 */
    1014,
    /* FSUB */
    1018,
    /* FSUB_P */
    1022,
    /* LD_GLOBAL */
    1027,
    /* LD_GLOBAL_IDX */
    1030,
    /* LD_GLOBAL_IDX_W16 */
    1035,
    /* LD_GLOBAL_IDX_W8 */
    1040,
    /* LD_GLOBAL_P */
    1045,
    /* LD_GLOBAL_SLOT */
    1049,
    /* LD_GLOBAL_SLOT_W16 */
    1054,
    /* LD_GLOBAL_SLOT_W8 */
    1059,
    /* LD_GLOBAL_W16 */
    1064,
    /* LD_GLOBAL_W8 */
    1067,
    /* LD_PRED_G */
    1070,
    /* LD_PRED_S */
    1073,
    /* LD_SHARED */
    1076,
    /* LD_SHARED_IDX */
    1079,
    /* LD_SHARED_W16 */
    1084,
    /* LD_SHARED_W8 */
    1087,
    /* LG2_F32 */
    1090,
    /* MADLO */
    1094,
    /* MADLO_P */
    1098,
    /* MAD_ACC */
    1103,
    /* MAX_S */
    1107,
    /* MAX_S_P */
    1111,
    /* MAX_S_W16 */
    1116,
    /* MAX_U */
    1120,
    /* MAX_U_P */
    1124,
    /* MIN_S */
    1129,
    /* MIN_S_P */
    1133,
    /* MIN_S_W16 */
    1138,
    /* MIN_U */
    1142,
    /* MIN_U_P */
    1146,
    /* MOVI */
    1151,
    /* MOVI48 */
    1153,
    /* MOV_P */
    1155,
    /* MULI */
    1161,
    /* MULI_P */
    1164,
    /* MUL_HI_S */
    1168,
    /* MUL_HI_S_P */
    1172,
    /* MUL_HI_U */
    1177,
    /* MUL_HI_U_P */
    1181,
    /* MUL_LO */
    1186,
    /* NEG */
    1190,
    /* OR */
    1194,
    /* ORI */
    1198,
    /* ORI_P */
    1201,
    /* OR_P */
    1205,
    /* OR_W16 */
    1210,
    /* PACKI */
    1214,
    /* PACKI_Z */
    1218,
    /* PAND */
    1221,
    /* PMOV */
    1224,
    /* PMOV_IMM */
    1227,
    /* POPC */
    1229,
    /* POR */
    1233,
    /* PXOR */
    1236,
    /* RCP_F32 */
    1239,
    /* RCP_F32_P */
    1243,
    /* RCP_U32 */
    1248,
    /* RSQRT_F32 */
    1252,
    /* SEL */
    1256,
    /* SETP_EQ */
    1261,
    /* SETP_EQ_F */
    1266,
    /* SETP_EQ_F_I */
    1271,
    /* SETP_EQ_F_NP */
    1276,
    /* SETP_EQ_F_NPI */
    1280,
    /* SETP_EQ_I */
    1284,
    /* SETP_EQ_NP */
    1289,
    /* SETP_EQ_NPI */
    1293,
    /* SETP_GE */
    1297,
    /* SETP_GE_F */
    1302,
    /* SETP_GE_F_I */
    1307,
    /* SETP_GE_F_NP */
    1312,
    /* SETP_GE_F_NPI */
    1316,
    /* SETP_GE_I */
    1320,
    /* SETP_GE_NP */
    1325,
    /* SETP_GE_NPI */
    1329,
    /* SETP_GE_U */
    1333,
    /* SETP_GE_U_I */
    1338,
    /* SETP_GE_U_NP */
    1343,
    /* SETP_GE_U_NPI */
    1347,
    /* SETP_GT */
    1351,
    /* SETP_GT_F */
    1356,
    /* SETP_GT_F_I */
    1361,
    /* SETP_GT_F_NP */
    1366,
    /* SETP_GT_F_NPI */
    1370,
    /* SETP_GT_I */
    1374,
    /* SETP_GT_NP */
    1379,
    /* SETP_GT_NPI */
    1383,
    /* SETP_GT_U */
    1387,
    /* SETP_GT_U_I */
    1392,
    /* SETP_GT_U_NP */
    1397,
    /* SETP_GT_U_NPI */
    1401,
    /* SETP_LE */
    1405,
    /* SETP_LE_F */
    1410,
    /* SETP_LE_F_I */
    1415,
    /* SETP_LE_F_NP */
    1420,
    /* SETP_LE_F_NPI */
    1424,
    /* SETP_LE_I */
    1428,
    /* SETP_LE_NP */
    1433,
    /* SETP_LE_NPI */
    1437,
    /* SETP_LE_U */
    1441,
    /* SETP_LE_U_I */
    1446,
    /* SETP_LE_U_NP */
    1451,
    /* SETP_LE_U_NPI */
    1455,
    /* SETP_LT */
    1459,
    /* SETP_LT_F */
    1464,
    /* SETP_LT_F_I */
    1469,
    /* SETP_LT_F_NP */
    1474,
    /* SETP_LT_F_NPI */
    1478,
    /* SETP_LT_I */
    1482,
    /* SETP_LT_NP */
    1487,
    /* SETP_LT_NPI */
    1491,
    /* SETP_LT_U */
    1495,
    /* SETP_LT_U_I */
    1500,
    /* SETP_LT_U_NP */
    1505,
    /* SETP_LT_U_NPI */
    1509,
    /* SETP_NE */
    1513,
    /* SETP_NE_F */
    1518,
    /* SETP_NE_F_I */
    1523,
    /* SETP_NE_F_NP */
    1528,
    /* SETP_NE_F_NPI */
    1532,
    /* SETP_NE_I */
    1536,
    /* SETP_NE_NP */
    1541,
    /* SETP_NE_NPI */
    1545,
    /* SHFL_IDX */
    1549,
    /* SHL */
    1553,
    /* SHLI */
    1557,
    /* SHLI_P */
    1560,
    /* SHL_P */
    1564,
    /* SHR */
    1569,
    /* SHRI */
    1573,
    /* SHRI_P */
    1576,
    /* SHR_P */
    1580,
    /* SIN_F32 */
    1585,
    /* SQRT_F32 */
    1589,
    /* SRA */
    1593,
    /* SRAI */
    1597,
    /* SRAI_P */
    1600,
    /* SRA_P */
    1604,
    /* SRD */
    1609,
    /* ST_GLOBAL */
    1611,
    /* ST_GLOBAL_IDX */
    1614,
    /* ST_GLOBAL_IDX_W16 */
    1619,
    /* ST_GLOBAL_IDX_W8 */
    1624,
    /* ST_GLOBAL_SLOT */
    1629,
    /* ST_GLOBAL_SLOT_W16 */
    1634,
    /* ST_GLOBAL_SLOT_W8 */
    1639,
    /* ST_GLOBAL_W16 */
    1644,
    /* ST_GLOBAL_W8 */
    1647,
    /* ST_PRED_G */
    1650,
    /* ST_PRED_S */
    1653,
    /* ST_SHARED */
    1656,
    /* ST_SHARED_IDX */
    1659,
    /* ST_SHARED_W16 */
    1664,
    /* ST_SHARED_W8 */
    1667,
    /* SUB */
    1670,
    /* SUBI */
    1674,
    /* SUBI_P */
    1677,
    /* SUB_P */
    1681,
    /* SUB_W16 */
    1686,
    /* UNBALLOT */
    1690,
    /* UNPACKI */
    1693,
    /* VOTE_ANY */
    1696,
    /* XOR */
    1699,
    /* XORI */
    1703,
    /* XORI_P */
    1706,
    /* XOR_P */
    1710,
    /* XOR_W16 */
    1715,
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
    /* FADD */
    GPR, GPR, GPR, GPR, 
    /* FADD_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* FFMA_ACC_F0 */
    GPR, GPR, GPR, GPR, 
    /* FFMA_ACC_F1 */
    GPR, GPR, GPR, GPR, 
    /* FFMA_F0 */
    GPR, GPR, GPR, GPR, 
    /* FMAX */
    GPR, GPR, GPR, GPR, 
    /* FMIN */
    GPR, GPR, GPR, GPR, 
    /* FMUL */
    GPR, GPR, GPR, GPR, 
    /* FMUL_P */
    GPR, pqual, GPR, GPR, GPR, 
    /* FNEG_F0 */
    GPR, GPR, GPR, GPR, 
    /* FSUB */
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
    CEFBS_None, // PSEUDO_PAND = 277
    CEFBS_None, // PSEUDO_PMOV = 278
    CEFBS_None, // PSEUDO_POR = 279
    CEFBS_None, // PSEUDO_PXOR = 280
    CEFBS_None, // PSEUDO_RET = 281
    CEFBS_None, // PSEUDO_ST_PRED = 282
    CEFBS_None, // ABS = 283
    CEFBS_None, // ADD = 284
    CEFBS_None, // ADDI = 285
    CEFBS_None, // ADDI48 = 286
    CEFBS_None, // ADDI_P = 287
    CEFBS_None, // ADDI_PP = 288
    CEFBS_None, // ADDI_W16 = 289
    CEFBS_None, // ADD_P = 290
    CEFBS_None, // ADD_PP = 291
    CEFBS_None, // ADD_W16 = 292
    CEFBS_None, // AND = 293
    CEFBS_None, // ANDI = 294
    CEFBS_None, // ANDI_P = 295
    CEFBS_None, // ANDN = 296
    CEFBS_None, // ANDNI = 297
    CEFBS_None, // ANDNI_P = 298
    CEFBS_None, // AND_P = 299
    CEFBS_None, // AND_W16 = 300
    CEFBS_None, // ATOM_ADD_G = 301
    CEFBS_None, // BALLOT = 302
    CEFBS_None, // BAR_INIT = 303
    CEFBS_None, // BAR_WAIT_PHASE = 304
    CEFBS_None, // BRA = 305
    CEFBS_None, // BRA_PRED = 306
    CEFBS_None, // BREV = 307
    CEFBS_None, // CALL = 308
    CEFBS_None, // CAS_G = 309
    CEFBS_None, // CHWIDTH_MULTI = 310
    CEFBS_None, // CLZ = 311
    CEFBS_None, // COS_F32 = 312
    CEFBS_None, // CVT_F32_S32 = 313
    CEFBS_None, // CVT_F32_S32_P = 314
    CEFBS_None, // CVT_F32_U32 = 315
    CEFBS_None, // CVT_F32_U32_P = 316
    CEFBS_None, // CVT_S32_F32 = 317
    CEFBS_None, // CVT_S32_F32_P = 318
    CEFBS_None, // CVT_SEXT = 319
    CEFBS_None, // CVT_U32_F32 = 320
    CEFBS_None, // CVT_U32_F32_P = 321
    CEFBS_None, // C_ABS = 322
    CEFBS_None, // C_ADD = 323
    CEFBS_None, // C_ADDI = 324
    CEFBS_None, // C_AND = 325
    CEFBS_None, // C_ANDI = 326
    CEFBS_None, // C_ANDN = 327
    CEFBS_None, // C_BAR_ARRIVE = 328
    CEFBS_None, // C_BAR_WAIT = 329
    CEFBS_None, // C_BRA = 330
    CEFBS_None, // C_CHWIDTH = 331
    CEFBS_None, // C_EXIT = 332
    CEFBS_None, // C_FADD = 333
    CEFBS_None, // C_FENCE = 334
    CEFBS_None, // C_FMAX = 335
    CEFBS_None, // C_FMIN = 336
    CEFBS_None, // C_FMUL = 337
    CEFBS_None, // C_LD_GLOBAL = 338
    CEFBS_None, // C_MAX_S = 339
    CEFBS_None, // C_MAX_U = 340
    CEFBS_None, // C_MIN_S = 341
    CEFBS_None, // C_MIN_U = 342
    CEFBS_None, // C_MOV = 343
    CEFBS_None, // C_MUL_LO = 344
    CEFBS_None, // C_NEG = 345
    CEFBS_None, // C_NOT = 346
    CEFBS_None, // C_OR = 347
    CEFBS_None, // C_ORI = 348
    CEFBS_None, // C_RECONV = 349
    CEFBS_None, // C_RET = 350
    CEFBS_None, // C_SHL = 351
    CEFBS_None, // C_SHLI = 352
    CEFBS_None, // C_SHR = 353
    CEFBS_None, // C_SHRI = 354
    CEFBS_None, // C_SRA = 355
    CEFBS_None, // C_SRAI = 356
    CEFBS_None, // C_ST_GLOBAL = 357
    CEFBS_None, // C_SUB = 358
    CEFBS_None, // C_SUBI = 359
    CEFBS_None, // C_XOR = 360
    CEFBS_None, // C_XORI = 361
    CEFBS_None, // DP2_BF16 = 362
    CEFBS_None, // DP2_F16 = 363
    CEFBS_None, // DP4_ACC = 364
    CEFBS_None, // DP4_E4M3 = 365
    CEFBS_None, // DP4_E5M2 = 366
    CEFBS_None, // DP4_SS = 367
    CEFBS_None, // EX2_F32 = 368
    CEFBS_None, // FABS_F0 = 369
    CEFBS_None, // FADD = 370
    CEFBS_None, // FADD_P = 371
    CEFBS_None, // FFMA_ACC_F0 = 372
    CEFBS_None, // FFMA_ACC_F1 = 373
    CEFBS_None, // FFMA_F0 = 374
    CEFBS_None, // FMAX = 375
    CEFBS_None, // FMIN = 376
    CEFBS_None, // FMUL = 377
    CEFBS_None, // FMUL_P = 378
    CEFBS_None, // FNEG_F0 = 379
    CEFBS_None, // FSUB = 380
    CEFBS_None, // FSUB_P = 381
    CEFBS_None, // LD_GLOBAL = 382
    CEFBS_None, // LD_GLOBAL_IDX = 383
    CEFBS_None, // LD_GLOBAL_IDX_W16 = 384
    CEFBS_None, // LD_GLOBAL_IDX_W8 = 385
    CEFBS_None, // LD_GLOBAL_P = 386
    CEFBS_None, // LD_GLOBAL_SLOT = 387
    CEFBS_None, // LD_GLOBAL_SLOT_W16 = 388
    CEFBS_None, // LD_GLOBAL_SLOT_W8 = 389
    CEFBS_None, // LD_GLOBAL_W16 = 390
    CEFBS_None, // LD_GLOBAL_W8 = 391
    CEFBS_None, // LD_PRED_G = 392
    CEFBS_None, // LD_PRED_S = 393
    CEFBS_None, // LD_SHARED = 394
    CEFBS_None, // LD_SHARED_IDX = 395
    CEFBS_None, // LD_SHARED_W16 = 396
    CEFBS_None, // LD_SHARED_W8 = 397
    CEFBS_None, // LG2_F32 = 398
    CEFBS_None, // MADLO = 399
    CEFBS_None, // MADLO_P = 400
    CEFBS_None, // MAD_ACC = 401
    CEFBS_None, // MAX_S = 402
    CEFBS_None, // MAX_S_P = 403
    CEFBS_None, // MAX_S_W16 = 404
    CEFBS_None, // MAX_U = 405
    CEFBS_None, // MAX_U_P = 406
    CEFBS_None, // MIN_S = 407
    CEFBS_None, // MIN_S_P = 408
    CEFBS_None, // MIN_S_W16 = 409
    CEFBS_None, // MIN_U = 410
    CEFBS_None, // MIN_U_P = 411
    CEFBS_None, // MOVI = 412
    CEFBS_None, // MOVI48 = 413
    CEFBS_None, // MOV_P = 414
    CEFBS_None, // MULI = 415
    CEFBS_None, // MULI_P = 416
    CEFBS_None, // MUL_HI_S = 417
    CEFBS_None, // MUL_HI_S_P = 418
    CEFBS_None, // MUL_HI_U = 419
    CEFBS_None, // MUL_HI_U_P = 420
    CEFBS_None, // MUL_LO = 421
    CEFBS_None, // NEG = 422
    CEFBS_None, // OR = 423
    CEFBS_None, // ORI = 424
    CEFBS_None, // ORI_P = 425
    CEFBS_None, // OR_P = 426
    CEFBS_None, // OR_W16 = 427
    CEFBS_None, // PACKI = 428
    CEFBS_None, // PACKI_Z = 429
    CEFBS_None, // PAND = 430
    CEFBS_None, // PMOV = 431
    CEFBS_None, // PMOV_IMM = 432
    CEFBS_None, // POPC = 433
    CEFBS_None, // POR = 434
    CEFBS_None, // PXOR = 435
    CEFBS_None, // RCP_F32 = 436
    CEFBS_None, // RCP_F32_P = 437
    CEFBS_None, // RCP_U32 = 438
    CEFBS_None, // RSQRT_F32 = 439
    CEFBS_None, // SEL = 440
    CEFBS_None, // SETP_EQ = 441
    CEFBS_None, // SETP_EQ_F = 442
    CEFBS_None, // SETP_EQ_F_I = 443
    CEFBS_None, // SETP_EQ_F_NP = 444
    CEFBS_None, // SETP_EQ_F_NPI = 445
    CEFBS_None, // SETP_EQ_I = 446
    CEFBS_None, // SETP_EQ_NP = 447
    CEFBS_None, // SETP_EQ_NPI = 448
    CEFBS_None, // SETP_GE = 449
    CEFBS_None, // SETP_GE_F = 450
    CEFBS_None, // SETP_GE_F_I = 451
    CEFBS_None, // SETP_GE_F_NP = 452
    CEFBS_None, // SETP_GE_F_NPI = 453
    CEFBS_None, // SETP_GE_I = 454
    CEFBS_None, // SETP_GE_NP = 455
    CEFBS_None, // SETP_GE_NPI = 456
    CEFBS_None, // SETP_GE_U = 457
    CEFBS_None, // SETP_GE_U_I = 458
    CEFBS_None, // SETP_GE_U_NP = 459
    CEFBS_None, // SETP_GE_U_NPI = 460
    CEFBS_None, // SETP_GT = 461
    CEFBS_None, // SETP_GT_F = 462
    CEFBS_None, // SETP_GT_F_I = 463
    CEFBS_None, // SETP_GT_F_NP = 464
    CEFBS_None, // SETP_GT_F_NPI = 465
    CEFBS_None, // SETP_GT_I = 466
    CEFBS_None, // SETP_GT_NP = 467
    CEFBS_None, // SETP_GT_NPI = 468
    CEFBS_None, // SETP_GT_U = 469
    CEFBS_None, // SETP_GT_U_I = 470
    CEFBS_None, // SETP_GT_U_NP = 471
    CEFBS_None, // SETP_GT_U_NPI = 472
    CEFBS_None, // SETP_LE = 473
    CEFBS_None, // SETP_LE_F = 474
    CEFBS_None, // SETP_LE_F_I = 475
    CEFBS_None, // SETP_LE_F_NP = 476
    CEFBS_None, // SETP_LE_F_NPI = 477
    CEFBS_None, // SETP_LE_I = 478
    CEFBS_None, // SETP_LE_NP = 479
    CEFBS_None, // SETP_LE_NPI = 480
    CEFBS_None, // SETP_LE_U = 481
    CEFBS_None, // SETP_LE_U_I = 482
    CEFBS_None, // SETP_LE_U_NP = 483
    CEFBS_None, // SETP_LE_U_NPI = 484
    CEFBS_None, // SETP_LT = 485
    CEFBS_None, // SETP_LT_F = 486
    CEFBS_None, // SETP_LT_F_I = 487
    CEFBS_None, // SETP_LT_F_NP = 488
    CEFBS_None, // SETP_LT_F_NPI = 489
    CEFBS_None, // SETP_LT_I = 490
    CEFBS_None, // SETP_LT_NP = 491
    CEFBS_None, // SETP_LT_NPI = 492
    CEFBS_None, // SETP_LT_U = 493
    CEFBS_None, // SETP_LT_U_I = 494
    CEFBS_None, // SETP_LT_U_NP = 495
    CEFBS_None, // SETP_LT_U_NPI = 496
    CEFBS_None, // SETP_NE = 497
    CEFBS_None, // SETP_NE_F = 498
    CEFBS_None, // SETP_NE_F_I = 499
    CEFBS_None, // SETP_NE_F_NP = 500
    CEFBS_None, // SETP_NE_F_NPI = 501
    CEFBS_None, // SETP_NE_I = 502
    CEFBS_None, // SETP_NE_NP = 503
    CEFBS_None, // SETP_NE_NPI = 504
    CEFBS_None, // SHFL_IDX = 505
    CEFBS_None, // SHL = 506
    CEFBS_None, // SHLI = 507
    CEFBS_None, // SHLI_P = 508
    CEFBS_None, // SHL_P = 509
    CEFBS_None, // SHR = 510
    CEFBS_None, // SHRI = 511
    CEFBS_None, // SHRI_P = 512
    CEFBS_None, // SHR_P = 513
    CEFBS_None, // SIN_F32 = 514
    CEFBS_None, // SQRT_F32 = 515
    CEFBS_None, // SRA = 516
    CEFBS_None, // SRAI = 517
    CEFBS_None, // SRAI_P = 518
    CEFBS_None, // SRA_P = 519
    CEFBS_None, // SRD = 520
    CEFBS_None, // ST_GLOBAL = 521
    CEFBS_None, // ST_GLOBAL_IDX = 522
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 523
    CEFBS_None, // ST_GLOBAL_IDX_W8 = 524
    CEFBS_None, // ST_GLOBAL_SLOT = 525
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 526
    CEFBS_None, // ST_GLOBAL_SLOT_W8 = 527
    CEFBS_None, // ST_GLOBAL_W16 = 528
    CEFBS_None, // ST_GLOBAL_W8 = 529
    CEFBS_None, // ST_PRED_G = 530
    CEFBS_None, // ST_PRED_S = 531
    CEFBS_None, // ST_SHARED = 532
    CEFBS_None, // ST_SHARED_IDX = 533
    CEFBS_None, // ST_SHARED_W16 = 534
    CEFBS_None, // ST_SHARED_W8 = 535
    CEFBS_None, // SUB = 536
    CEFBS_None, // SUBI = 537
    CEFBS_None, // SUBI_P = 538
    CEFBS_None, // SUB_P = 539
    CEFBS_None, // SUB_W16 = 540
    CEFBS_None, // UNBALLOT = 541
    CEFBS_None, // UNPACKI = 542
    CEFBS_None, // VOTE_ANY = 543
    CEFBS_None, // XOR = 544
    CEFBS_None, // XORI = 545
    CEFBS_None, // XORI_P = 546
    CEFBS_None, // XOR_P = 547
    CEFBS_None, // XOR_W16 = 548
  };

  assert(Opcode < 549);
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

