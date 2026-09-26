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
    PSEUDO_BCAST	= 271,
    PSEUDO_BRA_PRED	= 272,
    PSEUDO_PAND	= 273,
    PSEUDO_PMOV	= 274,
    PSEUDO_POR	= 275,
    PSEUDO_PXOR	= 276,
    ABS	= 277,
    ADD	= 278,
    ADDI	= 279,
    ADDI48	= 280,
    ADDI_P	= 281,
    ADDI_PP	= 282,
    ADDI_W16	= 283,
    ADD_P	= 284,
    ADD_PP	= 285,
    ADD_W16	= 286,
    AND	= 287,
    ANDI	= 288,
    ANDI_P	= 289,
    ANDN	= 290,
    ANDNI	= 291,
    ANDNI_P	= 292,
    AND_P	= 293,
    AND_W16	= 294,
    ATOM_ADD_G	= 295,
    BALLOT	= 296,
    BAR_INIT	= 297,
    BAR_WAIT_PHASE	= 298,
    BRA	= 299,
    BRA_PRED	= 300,
    BREV	= 301,
    CALL	= 302,
    CAS_G	= 303,
    CHWIDTH_MULTI	= 304,
    CLZ	= 305,
    COS_F32	= 306,
    CVT_F32_S32	= 307,
    CVT_F32_S32_P	= 308,
    CVT_F32_U32	= 309,
    CVT_F32_U32_P	= 310,
    CVT_S32_F32	= 311,
    CVT_S32_F32_P	= 312,
    CVT_SEXT	= 313,
    CVT_U32_F32	= 314,
    CVT_U32_F32_P	= 315,
    C_ABS	= 316,
    C_ADD	= 317,
    C_ADDI	= 318,
    C_AND	= 319,
    C_ANDI	= 320,
    C_ANDN	= 321,
    C_BAR_ARRIVE	= 322,
    C_BAR_WAIT	= 323,
    C_BRA	= 324,
    C_CHWIDTH	= 325,
    C_EXIT	= 326,
    C_FADD	= 327,
    C_FENCE	= 328,
    C_FMAX	= 329,
    C_FMIN	= 330,
    C_FMUL	= 331,
    C_LD_GLOBAL	= 332,
    C_MAX_S	= 333,
    C_MAX_U	= 334,
    C_MIN_S	= 335,
    C_MIN_U	= 336,
    C_MOV	= 337,
    C_MUL_LO	= 338,
    C_NEG	= 339,
    C_NOT	= 340,
    C_OR	= 341,
    C_ORI	= 342,
    C_RECONV	= 343,
    C_RET	= 344,
    C_SHL	= 345,
    C_SHLI	= 346,
    C_SHR	= 347,
    C_SHRI	= 348,
    C_SRA	= 349,
    C_SRAI	= 350,
    C_ST_GLOBAL	= 351,
    C_SUB	= 352,
    C_SUBI	= 353,
    C_XOR	= 354,
    C_XORI	= 355,
    DP2_BF16	= 356,
    DP2_F16	= 357,
    DP4_ACC	= 358,
    DP4_E4M3	= 359,
    DP4_E5M2	= 360,
    DP4_SS	= 361,
    EX2_F32	= 362,
    FABS_F0	= 363,
    FADD	= 364,
    FADD_P	= 365,
    FFMA_ACC_F0	= 366,
    FFMA_ACC_F1	= 367,
    FFMA_F0	= 368,
    FMAX	= 369,
    FMIN	= 370,
    FMUL	= 371,
    FMUL_P	= 372,
    FNEG_F0	= 373,
    FSUB	= 374,
    FSUB_P	= 375,
    LD_GLOBAL	= 376,
    LD_GLOBAL_IDX	= 377,
    LD_GLOBAL_IDX_W16	= 378,
    LD_GLOBAL_P	= 379,
    LD_GLOBAL_SLOT	= 380,
    LD_GLOBAL_SLOT_W16	= 381,
    LD_GLOBAL_W16	= 382,
    LD_PRED_G	= 383,
    LD_PRED_S	= 384,
    LD_SHARED	= 385,
    LD_SHARED_IDX	= 386,
    LD_SHARED_W16	= 387,
    LG2_F32	= 388,
    MADLO	= 389,
    MADLO_P	= 390,
    MAD_ACC	= 391,
    MAX_S	= 392,
    MAX_S_P	= 393,
    MAX_S_W16	= 394,
    MAX_U	= 395,
    MAX_U_P	= 396,
    MIN_S	= 397,
    MIN_S_P	= 398,
    MIN_S_W16	= 399,
    MIN_U	= 400,
    MIN_U_P	= 401,
    MOVI	= 402,
    MOVI48	= 403,
    MOV_P	= 404,
    MULI	= 405,
    MULI_P	= 406,
    MUL_HI_S	= 407,
    MUL_HI_S_P	= 408,
    MUL_HI_U	= 409,
    MUL_HI_U_P	= 410,
    MUL_LO	= 411,
    NEG	= 412,
    OR	= 413,
    ORI	= 414,
    ORI_P	= 415,
    OR_P	= 416,
    OR_W16	= 417,
    PACKI	= 418,
    PACKI_Z	= 419,
    PAND	= 420,
    PMOV	= 421,
    PMOV_IMM	= 422,
    POPC	= 423,
    POR	= 424,
    PXOR	= 425,
    RCP_F32	= 426,
    RCP_F32_P	= 427,
    RCP_U32	= 428,
    RSQRT_F32	= 429,
    SEL	= 430,
    SETP_EQ	= 431,
    SETP_EQ_F	= 432,
    SETP_EQ_F_I	= 433,
    SETP_EQ_F_NP	= 434,
    SETP_EQ_F_NPI	= 435,
    SETP_EQ_I	= 436,
    SETP_EQ_NP	= 437,
    SETP_EQ_NPI	= 438,
    SETP_GE	= 439,
    SETP_GE_F	= 440,
    SETP_GE_F_I	= 441,
    SETP_GE_F_NP	= 442,
    SETP_GE_F_NPI	= 443,
    SETP_GE_I	= 444,
    SETP_GE_NP	= 445,
    SETP_GE_NPI	= 446,
    SETP_GE_U	= 447,
    SETP_GE_U_I	= 448,
    SETP_GE_U_NP	= 449,
    SETP_GE_U_NPI	= 450,
    SETP_GT	= 451,
    SETP_GT_F	= 452,
    SETP_GT_F_I	= 453,
    SETP_GT_F_NP	= 454,
    SETP_GT_F_NPI	= 455,
    SETP_GT_I	= 456,
    SETP_GT_NP	= 457,
    SETP_GT_NPI	= 458,
    SETP_GT_U	= 459,
    SETP_GT_U_I	= 460,
    SETP_GT_U_NP	= 461,
    SETP_GT_U_NPI	= 462,
    SETP_LE	= 463,
    SETP_LE_F	= 464,
    SETP_LE_F_I	= 465,
    SETP_LE_F_NP	= 466,
    SETP_LE_F_NPI	= 467,
    SETP_LE_I	= 468,
    SETP_LE_NP	= 469,
    SETP_LE_NPI	= 470,
    SETP_LE_U	= 471,
    SETP_LE_U_I	= 472,
    SETP_LE_U_NP	= 473,
    SETP_LE_U_NPI	= 474,
    SETP_LT	= 475,
    SETP_LT_F	= 476,
    SETP_LT_F_I	= 477,
    SETP_LT_F_NP	= 478,
    SETP_LT_F_NPI	= 479,
    SETP_LT_I	= 480,
    SETP_LT_NP	= 481,
    SETP_LT_NPI	= 482,
    SETP_LT_U	= 483,
    SETP_LT_U_I	= 484,
    SETP_LT_U_NP	= 485,
    SETP_LT_U_NPI	= 486,
    SETP_NE	= 487,
    SETP_NE_F	= 488,
    SETP_NE_F_I	= 489,
    SETP_NE_F_NP	= 490,
    SETP_NE_F_NPI	= 491,
    SETP_NE_I	= 492,
    SETP_NE_NP	= 493,
    SETP_NE_NPI	= 494,
    SHFL_IDX	= 495,
    SHL	= 496,
    SHLI	= 497,
    SHLI_P	= 498,
    SHL_P	= 499,
    SHR	= 500,
    SHRI	= 501,
    SHRI_P	= 502,
    SHR_P	= 503,
    SIN_F32	= 504,
    SQRT_F32	= 505,
    SRA	= 506,
    SRAI	= 507,
    SRAI_P	= 508,
    SRA_P	= 509,
    SRD	= 510,
    ST_GLOBAL	= 511,
    ST_GLOBAL_IDX	= 512,
    ST_GLOBAL_IDX_W16	= 513,
    ST_GLOBAL_SLOT	= 514,
    ST_GLOBAL_SLOT_W16	= 515,
    ST_GLOBAL_W16	= 516,
    ST_PRED_G	= 517,
    ST_PRED_S	= 518,
    ST_SHARED	= 519,
    ST_SHARED_IDX	= 520,
    ST_SHARED_W16	= 521,
    SUB	= 522,
    SUBI	= 523,
    SUBI_P	= 524,
    SUB_P	= 525,
    SUB_W16	= 526,
    UNBALLOT	= 527,
    UNPACKI	= 528,
    VOTE_ANY	= 529,
    XOR	= 530,
    XORI	= 531,
    XORI_P	= 532,
    XOR_P	= 533,
    XOR_W16	= 534,
    INSTRUCTION_LIST_END = 535
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
  MCInstrDesc Insts[535];
  static_assert(alignof(MCInstrDesc) >= alignof(MCOperandInfo), "Unwanted padding between Insts and OperandInfo");
  MCOperandInfo OperandInfo[288];
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
    { 534,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #534 = XOR_W16
    { 533,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #533 = XOR_P
    { 532,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #532 = XORI_P
    { 531,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #531 = XORI
    { 530,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #530 = XOR
    { 529,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	285,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #529 = VOTE_ANY
    { 528,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #528 = UNPACKI
    { 527,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	282,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #527 = UNBALLOT
    { 526,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #526 = SUB_W16
    { 525,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #525 = SUB_P
    { 524,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #524 = SUBI_P
    { 523,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #523 = SUBI
    { 522,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #522 = SUB
    { 521,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #521 = ST_SHARED_W16
    { 520,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #520 = ST_SHARED_IDX
    { 519,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #519 = ST_SHARED
    { 518,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #518 = ST_PRED_S
    { 517,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #517 = ST_PRED_G
    { 516,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #516 = ST_GLOBAL_W16
    { 515,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	238,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #515 = ST_GLOBAL_SLOT_W16
    { 514,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #514 = ST_GLOBAL_SLOT
    { 513,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	228,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #513 = ST_GLOBAL_IDX_W16
    { 512,	5,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #512 = ST_GLOBAL_IDX
    { 511,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #511 = ST_GLOBAL
    { 510,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	198,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #510 = SRD
    { 509,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #509 = SRA_P
    { 508,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #508 = SRAI_P
    { 507,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #507 = SRAI
    { 506,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #506 = SRA
    { 505,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #505 = SQRT_F32
    { 504,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #504 = SIN_F32
    { 503,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #503 = SHR_P
    { 502,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #502 = SHRI_P
    { 501,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #501 = SHRI
    { 500,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #500 = SHR
    { 499,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #499 = SHL_P
    { 498,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #498 = SHLI_P
    { 497,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #497 = SHLI
    { 496,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #496 = SHL
    { 495,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #495 = SHFL_IDX
    { 494,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #494 = SETP_NE_NPI
    { 493,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #493 = SETP_NE_NP
    { 492,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #492 = SETP_NE_I
    { 491,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #491 = SETP_NE_F_NPI
    { 490,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #490 = SETP_NE_F_NP
    { 489,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #489 = SETP_NE_F_I
    { 488,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #488 = SETP_NE_F
    { 487,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #487 = SETP_NE
    { 486,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #486 = SETP_LT_U_NPI
    { 485,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #485 = SETP_LT_U_NP
    { 484,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #484 = SETP_LT_U_I
    { 483,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #483 = SETP_LT_U
    { 482,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #482 = SETP_LT_NPI
    { 481,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #481 = SETP_LT_NP
    { 480,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #480 = SETP_LT_I
    { 479,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #479 = SETP_LT_F_NPI
    { 478,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #478 = SETP_LT_F_NP
    { 477,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #477 = SETP_LT_F_I
    { 476,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #476 = SETP_LT_F
    { 475,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #475 = SETP_LT
    { 474,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #474 = SETP_LE_U_NPI
    { 473,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #473 = SETP_LE_U_NP
    { 472,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #472 = SETP_LE_U_I
    { 471,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #471 = SETP_LE_U
    { 470,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #470 = SETP_LE_NPI
    { 469,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #469 = SETP_LE_NP
    { 468,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #468 = SETP_LE_I
    { 467,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #467 = SETP_LE_F_NPI
    { 466,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #466 = SETP_LE_F_NP
    { 465,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #465 = SETP_LE_F_I
    { 464,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #464 = SETP_LE_F
    { 463,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #463 = SETP_LE
    { 462,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #462 = SETP_GT_U_NPI
    { 461,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #461 = SETP_GT_U_NP
    { 460,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #460 = SETP_GT_U_I
    { 459,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #459 = SETP_GT_U
    { 458,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #458 = SETP_GT_NPI
    { 457,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #457 = SETP_GT_NP
    { 456,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #456 = SETP_GT_I
    { 455,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #455 = SETP_GT_F_NPI
    { 454,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #454 = SETP_GT_F_NP
    { 453,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #453 = SETP_GT_F_I
    { 452,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #452 = SETP_GT_F
    { 451,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #451 = SETP_GT
    { 450,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #450 = SETP_GE_U_NPI
    { 449,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #449 = SETP_GE_U_NP
    { 448,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #448 = SETP_GE_U_I
    { 447,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #447 = SETP_GE_U
    { 446,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #446 = SETP_GE_NPI
    { 445,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #445 = SETP_GE_NP
    { 444,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #444 = SETP_GE_I
    { 443,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #443 = SETP_GE_F_NPI
    { 442,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #442 = SETP_GE_F_NP
    { 441,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #441 = SETP_GE_F_I
    { 440,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #440 = SETP_GE_F
    { 439,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #439 = SETP_GE
    { 438,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #438 = SETP_EQ_NPI
    { 437,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #437 = SETP_EQ_NP
    { 436,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #436 = SETP_EQ_I
    { 435,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	278,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #435 = SETP_EQ_F_NPI
    { 434,	4,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	274,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #434 = SETP_EQ_F_NP
    { 433,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	269,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #433 = SETP_EQ_F_I
    { 432,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #432 = SETP_EQ_F
    { 431,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	264,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #431 = SETP_EQ
    { 430,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #430 = SEL
    { 429,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #429 = RSQRT_F32
    { 428,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #428 = RCP_U32
    { 427,	5,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #427 = RCP_F32_P
    { 426,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #426 = RCP_F32
    { 425,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	259,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #425 = PXOR
    { 424,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	259,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #424 = POR
    { 423,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #423 = POPC
    { 422,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	262,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #422 = PMOV_IMM
    { 421,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	259,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #421 = PMOV
    { 420,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	259,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #420 = PAND
    { 419,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #419 = PACKI_Z
    { 418,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	255,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #418 = PACKI
    { 417,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #417 = OR_W16
    { 416,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #416 = OR_P
    { 415,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #415 = ORI_P
    { 414,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #414 = ORI
    { 413,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #413 = OR
    { 412,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #412 = NEG
    { 411,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #411 = MUL_LO
    { 410,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #410 = MUL_HI_U_P
    { 409,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #409 = MUL_HI_U
    { 408,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #408 = MUL_HI_S_P
    { 407,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #407 = MUL_HI_S
    { 406,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #406 = MULI_P
    { 405,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #405 = MULI
    { 404,	6,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	249,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #404 = MOV_P
    { 403,	2,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	198,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #403 = MOVI48
    { 402,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	198,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #402 = MOVI
    { 401,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #401 = MIN_U_P
    { 400,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #400 = MIN_U
    { 399,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #399 = MIN_S_W16
    { 398,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #398 = MIN_S_P
    { 397,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #397 = MIN_S
    { 396,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #396 = MAX_U_P
    { 395,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #395 = MAX_U
    { 394,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #394 = MAX_S_W16
    { 393,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #393 = MAX_S_P
    { 392,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #392 = MAX_S
    { 391,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #391 = MAD_ACC
    { 390,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #390 = MADLO_P
    { 389,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #389 = MADLO
    { 388,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #388 = LG2_F32
    { 387,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #387 = LD_SHARED_W16
    { 386,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #386 = LD_SHARED_IDX
    { 385,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #385 = LD_SHARED
    { 384,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #384 = LD_PRED_S
    { 383,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	246,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #383 = LD_PRED_G
    { 382,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	243,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #382 = LD_GLOBAL_W16
    { 381,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	238,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #381 = LD_GLOBAL_SLOT_W16
    { 380,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	233,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #380 = LD_GLOBAL_SLOT
    { 379,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #379 = LD_GLOBAL_P
    { 378,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	228,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #378 = LD_GLOBAL_IDX_W16
    { 377,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	223,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #377 = LD_GLOBAL_IDX
    { 376,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #376 = LD_GLOBAL
    { 375,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #375 = FSUB_P
    { 374,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #374 = FSUB
    { 373,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #373 = FNEG_F0
    { 372,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #372 = FMUL_P
    { 371,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #371 = FMUL
    { 370,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #370 = FMIN
    { 369,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #369 = FMAX
    { 368,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #368 = FFMA_F0
    { 367,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #367 = FFMA_ACC_F1
    { 366,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #366 = FFMA_ACC_F0
    { 365,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #365 = FADD_P
    { 364,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #364 = FADD
    { 363,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #363 = FABS_F0
    { 362,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #362 = EX2_F32
    { 361,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #361 = DP4_SS
    { 360,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #360 = DP4_E5M2
    { 359,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #359 = DP4_E4M3
    { 358,	4,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	219,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #358 = DP4_ACC
    { 357,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #357 = DP2_F16
    { 356,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #356 = DP2_BF16
    { 355,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #355 = C_XORI
    { 354,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #354 = C_XOR
    { 353,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #353 = C_SUBI
    { 352,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #352 = C_SUB
    { 351,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #351 = C_ST_GLOBAL
    { 350,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #350 = C_SRAI
    { 349,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #349 = C_SRA
    { 348,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #348 = C_SHRI
    { 347,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #347 = C_SHR
    { 346,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #346 = C_SHLI
    { 345,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #345 = C_SHL
    { 344,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #344 = C_RET
    { 343,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #343 = C_RECONV
    { 342,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #342 = C_ORI
    { 341,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #341 = C_OR
    { 340,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #340 = C_NOT
    { 339,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #339 = C_NEG
    { 338,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #338 = C_MUL_LO
    { 337,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #337 = C_MOV
    { 336,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #336 = C_MIN_U
    { 335,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #335 = C_MIN_S
    { 334,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #334 = C_MAX_U
    { 333,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #333 = C_MAX_S
    { 332,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #332 = C_LD_GLOBAL
    { 331,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #331 = C_FMUL
    { 330,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #330 = C_FMIN
    { 329,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #329 = C_FMAX
    { 328,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #328 = C_FENCE
    { 327,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #327 = C_FADD
    { 326,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #326 = C_EXIT
    { 325,	2,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	198,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #325 = C_CHWIDTH
    { 324,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #324 = C_BRA
    { 323,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #323 = C_BAR_WAIT
    { 322,	1,	0,	2,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #322 = C_BAR_ARRIVE
    { 321,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #321 = C_ANDN
    { 320,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #320 = C_ANDI
    { 319,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #319 = C_AND
    { 318,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	216,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #318 = C_ADDI
    { 317,	3,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	213,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #317 = C_ADD
    { 316,	2,	1,	2,	0,	0,	0,	CCVImpOpBase + 0,	211,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #316 = C_ABS
    { 315,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #315 = CVT_U32_F32_P
    { 314,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #314 = CVT_U32_F32
    { 313,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	207,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #313 = CVT_SEXT
    { 312,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #312 = CVT_S32_F32_P
    { 311,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #311 = CVT_S32_F32
    { 310,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #310 = CVT_F32_U32_P
    { 309,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #309 = CVT_F32_U32
    { 308,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #308 = CVT_F32_S32_P
    { 307,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #307 = CVT_F32_S32
    { 306,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #306 = COS_F32
    { 305,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #305 = CLZ
    { 304,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #304 = CHWIDTH_MULTI
    { 303,	7,	2,	6,	0,	0,	0,	CCVImpOpBase + 0,	200,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #303 = CAS_G
    { 302,	2,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	198,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #302 = CALL
    { 301,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #301 = BREV
    { 300,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	196,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #300 = BRA_PRED
    { 299,	1,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #299 = BRA
    { 298,	3,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	193,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #298 = BAR_WAIT_PHASE
    { 297,	2,	0,	4,	0,	0,	0,	CCVImpOpBase + 0,	13,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #297 = BAR_INIT
    { 296,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	190,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #296 = BALLOT
    { 295,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	186,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #295 = ATOM_ADD_G
    { 294,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #294 = AND_W16
    { 293,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #293 = AND_P
    { 292,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #292 = ANDNI_P
    { 291,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #291 = ANDNI
    { 290,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #290 = ANDN
    { 289,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #289 = ANDI_P
    { 288,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #288 = ANDI
    { 287,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #287 = AND
    { 286,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	182,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #286 = ADD_W16
    { 285,	6,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	176,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #285 = ADD_PP
    { 284,	5,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	171,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #284 = ADD_P
    { 283,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	168,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #283 = ADDI_W16
    { 282,	5,	2,	4,	0,	0,	0,	CCVImpOpBase + 0,	163,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #282 = ADDI_PP
    { 281,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	159,	0|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #281 = ADDI_P
    { 280,	3,	1,	6,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #280 = ADDI48
    { 279,	3,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	156,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #279 = ADDI
    { 278,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #278 = ADD
    { 277,	4,	1,	4,	0,	0,	0,	CCVImpOpBase + 0,	152,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #277 = ABS
    { 276,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #276 = PSEUDO_PXOR
    { 275,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #275 = PSEUDO_POR
    { 274,	4,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	148,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #274 = PSEUDO_PMOV
    { 273,	3,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	145,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #273 = PSEUDO_PAND
    { 272,	3,	0,	0,	0,	0,	0,	CCVImpOpBase + 0,	142,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #272 = PSEUDO_BRA_PRED
    { 271,	2,	1,	0,	0,	0,	0,	CCVImpOpBase + 0,	140,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL },  // Inst #271 = PSEUDO_BCAST
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
    /* 145 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 148 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 152 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 156 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 159 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 163 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 168 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 171 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 176 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 182 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 186 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 190 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 193 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 196 */ { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 198 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 200 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 207 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_EARLY_CLOBBER }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 211 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 213 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 216 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 219 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 223 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 228 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 233 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 238 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 243 */ { CCV::GPR16RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 246 */ { -1, 0, CCVOp::OPERAND_PMASK4, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 249 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 255 */ { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, MCOI_TIED_TO(0) }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 259 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
    /* 262 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 264 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 269 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 274 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 278 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 282 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { CCV::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 285 */ { CCV::PRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, CCVOp::OPERAND_PQUAL, 0 }, { -1, 0, CCVOp::OPERAND_PSRC, 0 },
  }, {
    /* 0 */
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
  /* 428 */ "G_FMA\0"
  /* 434 */ "G_STRICT_FMA\0"
  /* 447 */ "C_BRA\0"
  /* 453 */ "C_SRA\0"
  /* 459 */ "G_FSUB\0"
  /* 466 */ "G_STRICT_FSUB\0"
  /* 480 */ "G_ATOMICRMW_FSUB\0"
  /* 497 */ "C_SUB\0"
  /* 503 */ "G_SUB\0"
  /* 509 */ "G_ATOMICRMW_SUB\0"
  /* 525 */ "DP4_ACC\0"
  /* 533 */ "MAD_ACC\0"
  /* 541 */ "G_INTRINSIC\0"
  /* 553 */ "G_FPTRUNC\0"
  /* 563 */ "G_INTRINSIC_TRUNC\0"
  /* 581 */ "G_TRUNC\0"
  /* 589 */ "G_BUILD_VECTOR_TRUNC\0"
  /* 610 */ "G_DYN_STACKALLOC\0"
  /* 627 */ "POPC\0"
  /* 632 */ "G_FMAD\0"
  /* 639 */ "G_INDEXED_SEXTLOAD\0"
  /* 658 */ "G_SEXTLOAD\0"
  /* 669 */ "G_INDEXED_ZEXTLOAD\0"
  /* 688 */ "G_ZEXTLOAD\0"
  /* 699 */ "G_INDEXED_LOAD\0"
  /* 714 */ "G_LOAD\0"
  /* 721 */ "C_FADD\0"
  /* 728 */ "G_VECREDUCE_FADD\0"
  /* 745 */ "G_FADD\0"
  /* 752 */ "G_VECREDUCE_SEQ_FADD\0"
  /* 773 */ "G_STRICT_FADD\0"
  /* 787 */ "G_ATOMICRMW_FADD\0"
  /* 804 */ "C_ADD\0"
  /* 810 */ "G_VECREDUCE_ADD\0"
  /* 826 */ "G_ADD\0"
  /* 832 */ "G_PTR_ADD\0"
  /* 842 */ "G_ATOMICRMW_ADD\0"
  /* 858 */ "LD_SHARED\0"
  /* 868 */ "ST_SHARED\0"
  /* 878 */ "PSEUDO_BRA_PRED\0"
  /* 894 */ "G_ATOMICRMW_NAND\0"
  /* 911 */ "PSEUDO_PAND\0"
  /* 923 */ "C_AND\0"
  /* 929 */ "G_VECREDUCE_AND\0"
  /* 945 */ "G_AND\0"
  /* 951 */ "G_ATOMICRMW_AND\0"
  /* 967 */ "LIFETIME_END\0"
  /* 980 */ "G_BRCOND\0"
  /* 989 */ "G_LLROUND\0"
  /* 999 */ "G_LROUND\0"
  /* 1008 */ "G_INTRINSIC_ROUND\0"
  /* 1026 */ "G_INTRINSIC_FPTRUNC_ROUND\0"
  /* 1052 */ "LOAD_STACK_GUARD\0"
  /* 1069 */ "SRD\0"
  /* 1073 */ "PSEUDO_PROBE\0"
  /* 1086 */ "G_SSUBE\0"
  /* 1094 */ "G_USUBE\0"
  /* 1102 */ "C_FENCE\0"
  /* 1110 */ "G_FENCE\0"
  /* 1118 */ "ARITH_FENCE\0"
  /* 1130 */ "REG_SEQUENCE\0"
  /* 1143 */ "G_SADDE\0"
  /* 1151 */ "G_UADDE\0"
  /* 1159 */ "G_GET_FPMODE\0"
  /* 1172 */ "G_RESET_FPMODE\0"
  /* 1187 */ "G_SET_FPMODE\0"
  /* 1200 */ "G_FMINNUM_IEEE\0"
  /* 1215 */ "G_FMAXNUM_IEEE\0"
  /* 1230 */ "SETP_GE\0"
  /* 1238 */ "G_JUMP_TABLE\0"
  /* 1251 */ "BUNDLE\0"
  /* 1258 */ "SETP_LE\0"
  /* 1266 */ "G_MEMCPY_INLINE\0"
  /* 1282 */ "SETP_NE\0"
  /* 1290 */ "LOCAL_ESCAPE\0"
  /* 1303 */ "G_STACKRESTORE\0"
  /* 1318 */ "G_INDEXED_STORE\0"
  /* 1334 */ "G_STORE\0"
  /* 1342 */ "BAR_WAIT_PHASE\0"
  /* 1357 */ "G_BITREVERSE\0"
  /* 1370 */ "DBG_VALUE\0"
  /* 1380 */ "G_GLOBAL_VALUE\0"
  /* 1395 */ "G_STACKSAVE\0"
  /* 1407 */ "C_BAR_ARRIVE\0"
  /* 1420 */ "G_MEMMOVE\0"
  /* 1430 */ "G_FREEZE\0"
  /* 1439 */ "G_FCANONICALIZE\0"
  /* 1455 */ "G_CTLZ_ZERO_UNDEF\0"
  /* 1473 */ "G_CTTZ_ZERO_UNDEF\0"
  /* 1491 */ "G_IMPLICIT_DEF\0"
  /* 1506 */ "DBG_INSTR_REF\0"
  /* 1520 */ "SETP_GE_F\0"
  /* 1530 */ "SETP_LE_F\0"
  /* 1540 */ "SETP_NE_F\0"
  /* 1550 */ "SETP_EQ_F\0"
  /* 1560 */ "SETP_GT_F\0"
  /* 1570 */ "SETP_LT_F\0"
  /* 1580 */ "G_FNEG\0"
  /* 1587 */ "C_NEG\0"
  /* 1593 */ "EXTRACT_SUBREG\0"
  /* 1608 */ "INSERT_SUBREG\0"
  /* 1622 */ "G_SEXT_INREG\0"
  /* 1635 */ "SUBREG_TO_REG\0"
  /* 1649 */ "G_ATOMIC_CMPXCHG\0"
  /* 1666 */ "G_ATOMICRMW_XCHG\0"
  /* 1683 */ "G_FLOG\0"
  /* 1690 */ "G_VAARG\0"
  /* 1698 */ "PREALLOCATED_ARG\0"
  /* 1715 */ "ATOM_ADD_G\0"
  /* 1726 */ "LD_PRED_G\0"
  /* 1736 */ "ST_PRED_G\0"
  /* 1746 */ "CAS_G\0"
  /* 1752 */ "G_PREFETCH\0"
  /* 1763 */ "G_SMULH\0"
  /* 1771 */ "G_UMULH\0"
  /* 1779 */ "C_CHWIDTH\0"
  /* 1789 */ "C_SRAI\0"
  /* 1796 */ "C_SUBI\0"
  /* 1803 */ "C_ADDI\0"
  /* 1810 */ "C_ANDI\0"
  /* 1817 */ "DBG_PHI\0"
  /* 1825 */ "UNPACKI\0"
  /* 1833 */ "C_SHLI\0"
  /* 1840 */ "MULI\0"
  /* 1845 */ "ANDNI\0"
  /* 1851 */ "SETP_GE_NPI\0"
  /* 1863 */ "SETP_LE_NPI\0"
  /* 1875 */ "SETP_NE_NPI\0"
  /* 1887 */ "SETP_GE_F_NPI\0"
  /* 1901 */ "SETP_LE_F_NPI\0"
  /* 1915 */ "SETP_NE_F_NPI\0"
  /* 1929 */ "SETP_EQ_F_NPI\0"
  /* 1943 */ "SETP_GT_F_NPI\0"
  /* 1957 */ "SETP_LT_F_NPI\0"
  /* 1971 */ "SETP_EQ_NPI\0"
  /* 1983 */ "SETP_GT_NPI\0"
  /* 1995 */ "SETP_LT_NPI\0"
  /* 2007 */ "SETP_GE_U_NPI\0"
  /* 2021 */ "SETP_LE_U_NPI\0"
  /* 2035 */ "SETP_GT_U_NPI\0"
  /* 2049 */ "SETP_LT_U_NPI\0"
  /* 2063 */ "C_SHRI\0"
  /* 2070 */ "C_XORI\0"
  /* 2077 */ "C_ORI\0"
  /* 2083 */ "G_FPTOSI\0"
  /* 2092 */ "CHWIDTH_MULTI\0"
  /* 2106 */ "G_FPTOUI\0"
  /* 2115 */ "MOVI\0"
  /* 2120 */ "G_FPOWI\0"
  /* 2128 */ "SETP_GE_I\0"
  /* 2138 */ "SETP_LE_I\0"
  /* 2148 */ "SETP_NE_I\0"
  /* 2158 */ "SETP_GE_F_I\0"
  /* 2170 */ "SETP_LE_F_I\0"
  /* 2182 */ "SETP_NE_F_I\0"
  /* 2194 */ "SETP_EQ_F_I\0"
  /* 2206 */ "SETP_GT_F_I\0"
  /* 2218 */ "SETP_LT_F_I\0"
  /* 2230 */ "SETP_EQ_I\0"
  /* 2240 */ "SETP_GT_I\0"
  /* 2250 */ "SETP_LT_I\0"
  /* 2260 */ "SETP_GE_U_I\0"
  /* 2272 */ "SETP_LE_U_I\0"
  /* 2284 */ "SETP_GT_U_I\0"
  /* 2296 */ "SETP_LT_U_I\0"
  /* 2308 */ "G_PTRMASK\0"
  /* 2318 */ "C_LD_GLOBAL\0"
  /* 2330 */ "C_ST_GLOBAL\0"
  /* 2342 */ "GC_LABEL\0"
  /* 2351 */ "DBG_LABEL\0"
  /* 2361 */ "EH_LABEL\0"
  /* 2370 */ "ANNOTATION_LABEL\0"
  /* 2387 */ "ICALL_BRANCH_FUNNEL\0"
  /* 2407 */ "SEL\0"
  /* 2411 */ "G_FSHL\0"
  /* 2418 */ "C_SHL\0"
  /* 2424 */ "G_SHL\0"
  /* 2430 */ "G_FCEIL\0"
  /* 2438 */ "PATCHABLE_TAIL_CALL\0"
  /* 2458 */ "PATCHABLE_TYPED_EVENT_CALL\0"
  /* 2485 */ "PATCHABLE_EVENT_CALL\0"
  /* 2506 */ "FENTRY_CALL\0"
  /* 2518 */ "KILL\0"
  /* 2523 */ "G_CONSTANT_POOL\0"
  /* 2539 */ "G_ROTL\0"
  /* 2546 */ "C_FMUL\0"
  /* 2553 */ "G_VECREDUCE_FMUL\0"
  /* 2570 */ "G_FMUL\0"
  /* 2577 */ "G_VECREDUCE_SEQ_FMUL\0"
  /* 2598 */ "G_STRICT_FMUL\0"
  /* 2612 */ "G_VECREDUCE_MUL\0"
  /* 2628 */ "G_MUL\0"
  /* 2634 */ "G_FREM\0"
  /* 2641 */ "G_STRICT_FREM\0"
  /* 2655 */ "G_SREM\0"
  /* 2662 */ "G_UREM\0"
  /* 2669 */ "G_SDIVREM\0"
  /* 2679 */ "G_UDIVREM\0"
  /* 2689 */ "PMOV_IMM\0"
  /* 2698 */ "INLINEASM\0"
  /* 2708 */ "G_VECREDUCE_FMINIMUM\0"
  /* 2729 */ "G_FMINIMUM\0"
  /* 2740 */ "G_VECREDUCE_FMAXIMUM\0"
  /* 2761 */ "G_FMAXIMUM\0"
  /* 2772 */ "G_FMINNUM\0"
  /* 2782 */ "G_FMAXNUM\0"
  /* 2792 */ "C_ANDN\0"
  /* 2799 */ "G_INTRINSIC_ROUNDEVEN\0"
  /* 2821 */ "G_ASSERT_ALIGN\0"
  /* 2836 */ "G_FCOPYSIGN\0"
  /* 2848 */ "C_FMIN\0"
  /* 2855 */ "G_VECREDUCE_FMIN\0"
  /* 2872 */ "G_ATOMICRMW_FMIN\0"
  /* 2889 */ "G_VECREDUCE_SMIN\0"
  /* 2906 */ "G_SMIN\0"
  /* 2913 */ "G_VECREDUCE_UMIN\0"
  /* 2930 */ "G_UMIN\0"
  /* 2937 */ "G_ATOMICRMW_UMIN\0"
  /* 2954 */ "G_ATOMICRMW_MIN\0"
  /* 2970 */ "G_FSIN\0"
  /* 2977 */ "CFI_INSTRUCTION\0"
  /* 2993 */ "G_SSUBO\0"
  /* 3001 */ "G_USUBO\0"
  /* 3009 */ "G_SADDO\0"
  /* 3017 */ "G_UADDO\0"
  /* 3025 */ "JUMP_TABLE_DEBUG_INFO\0"
  /* 3047 */ "MADLO\0"
  /* 3053 */ "G_SMULO\0"
  /* 3061 */ "G_UMULO\0"
  /* 3069 */ "C_MUL_LO\0"
  /* 3078 */ "G_BZERO\0"
  /* 3086 */ "STACKMAP\0"
  /* 3095 */ "G_ATOMICRMW_UDEC_WRAP\0"
  /* 3117 */ "G_ATOMICRMW_UINC_WRAP\0"
  /* 3139 */ "G_BSWAP\0"
  /* 3147 */ "G_SITOFP\0"
  /* 3156 */ "G_UITOFP\0"
  /* 3165 */ "G_FCMP\0"
  /* 3172 */ "G_ICMP\0"
  /* 3179 */ "SETP_GE_NP\0"
  /* 3190 */ "SETP_LE_NP\0"
  /* 3201 */ "SETP_NE_NP\0"
  /* 3212 */ "SETP_GE_F_NP\0"
  /* 3225 */ "SETP_LE_F_NP\0"
  /* 3238 */ "SETP_NE_F_NP\0"
  /* 3251 */ "SETP_EQ_F_NP\0"
  /* 3264 */ "SETP_GT_F_NP\0"
  /* 3277 */ "SETP_LT_F_NP\0"
  /* 3290 */ "SETP_EQ_NP\0"
  /* 3301 */ "SETP_GT_NP\0"
  /* 3312 */ "SETP_LT_NP\0"
  /* 3323 */ "SETP_GE_U_NP\0"
  /* 3336 */ "SETP_LE_U_NP\0"
  /* 3349 */ "SETP_GT_U_NP\0"
  /* 3362 */ "SETP_LT_U_NP\0"
  /* 3375 */ "G_CTPOP\0"
  /* 3383 */ "PATCHABLE_OP\0"
  /* 3396 */ "FAULTING_OP\0"
  /* 3408 */ "ADD_PP\0"
  /* 3415 */ "ADDI_PP\0"
  /* 3423 */ "PREALLOCATED_SETUP\0"
  /* 3442 */ "G_FLDEXP\0"
  /* 3451 */ "G_STRICT_FLDEXP\0"
  /* 3467 */ "G_FEXP\0"
  /* 3474 */ "G_FFREXP\0"
  /* 3483 */ "CVT_S32_F32_P\0"
  /* 3497 */ "CVT_U32_F32_P\0"
  /* 3511 */ "RCP_F32_P\0"
  /* 3521 */ "CVT_F32_S32_P\0"
  /* 3535 */ "CVT_F32_U32_P\0"
  /* 3549 */ "SRA_P\0"
  /* 3555 */ "FSUB_P\0"
  /* 3562 */ "FADD_P\0"
  /* 3569 */ "AND_P\0"
  /* 3575 */ "SRAI_P\0"
  /* 3582 */ "SUBI_P\0"
  /* 3589 */ "ADDI_P\0"
  /* 3596 */ "ANDI_P\0"
  /* 3603 */ "SHLI_P\0"
  /* 3610 */ "MULI_P\0"
  /* 3617 */ "ANDNI_P\0"
  /* 3625 */ "SHRI_P\0"
  /* 3632 */ "XORI_P\0"
  /* 3639 */ "LD_GLOBAL_P\0"
  /* 3651 */ "SHL_P\0"
  /* 3657 */ "FMUL_P\0"
  /* 3664 */ "MADLO_P\0"
  /* 3672 */ "SHR_P\0"
  /* 3678 */ "XOR_P\0"
  /* 3684 */ "MUL_HI_S_P\0"
  /* 3695 */ "MIN_S_P\0"
  /* 3703 */ "MAX_S_P\0"
  /* 3711 */ "MUL_HI_U_P\0"
  /* 3722 */ "MIN_U_P\0"
  /* 3730 */ "MAX_U_P\0"
  /* 3738 */ "MOV_P\0"
  /* 3744 */ "SETP_EQ\0"
  /* 3752 */ "G_BR\0"
  /* 3757 */ "INLINEASM_BR\0"
  /* 3770 */ "G_BLOCK_ADDR\0"
  /* 3783 */ "MEMBARRIER\0"
  /* 3794 */ "G_CONSTANT_FOLD_BARRIER\0"
  /* 3818 */ "PATCHABLE_FUNCTION_ENTER\0"
  /* 3843 */ "G_READCYCLECOUNTER\0"
  /* 3862 */ "G_READ_REGISTER\0"
  /* 3878 */ "G_WRITE_REGISTER\0"
  /* 3895 */ "G_ASHR\0"
  /* 3902 */ "G_FSHR\0"
  /* 3909 */ "G_LSHR\0"
  /* 3916 */ "C_SHR\0"
  /* 3922 */ "G_FFLOOR\0"
  /* 3931 */ "PSEUDO_POR\0"
  /* 3942 */ "G_BUILD_VECTOR\0"
  /* 3957 */ "G_SHUFFLE_VECTOR\0"
  /* 3974 */ "PSEUDO_PXOR\0"
  /* 3986 */ "C_XOR\0"
  /* 3992 */ "G_VECREDUCE_XOR\0"
  /* 4008 */ "G_XOR\0"
  /* 4014 */ "G_ATOMICRMW_XOR\0"
  /* 4030 */ "C_OR\0"
  /* 4035 */ "G_VECREDUCE_OR\0"
  /* 4050 */ "G_OR\0"
  /* 4055 */ "G_ATOMICRMW_OR\0"
  /* 4070 */ "G_ROTR\0"
  /* 4077 */ "G_INTTOPTR\0"
  /* 4088 */ "G_FABS\0"
  /* 4095 */ "C_ABS\0"
  /* 4101 */ "G_ABS\0"
  /* 4107 */ "G_UNMERGE_VALUES\0"
  /* 4124 */ "G_MERGE_VALUES\0"
  /* 4139 */ "G_FCOS\0"
  /* 4146 */ "G_CONCAT_VECTORS\0"
  /* 4163 */ "COPY_TO_REGCLASS\0"
  /* 4180 */ "G_IS_FPCLASS\0"
  /* 4193 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\0"
  /* 4223 */ "DP4_SS\0"
  /* 4230 */ "G_INTRINSIC_W_SIDE_EFFECTS\0"
  /* 4257 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\0"
  /* 4295 */ "LD_PRED_S\0"
  /* 4305 */ "ST_PRED_S\0"
  /* 4315 */ "MUL_HI_S\0"
  /* 4324 */ "C_MIN_S\0"
  /* 4332 */ "C_MAX_S\0"
  /* 4340 */ "G_SSUBSAT\0"
  /* 4350 */ "G_USUBSAT\0"
  /* 4360 */ "G_SADDSAT\0"
  /* 4370 */ "G_UADDSAT\0"
  /* 4380 */ "G_SSHLSAT\0"
  /* 4390 */ "G_USHLSAT\0"
  /* 4400 */ "G_SMULFIXSAT\0"
  /* 4413 */ "G_UMULFIXSAT\0"
  /* 4426 */ "G_SDIVFIXSAT\0"
  /* 4439 */ "G_UDIVFIXSAT\0"
  /* 4452 */ "G_EXTRACT\0"
  /* 4462 */ "G_SELECT\0"
  /* 4471 */ "G_BRINDIRECT\0"
  /* 4484 */ "C_RET\0"
  /* 4490 */ "PATCHABLE_RET\0"
  /* 4504 */ "G_MEMSET\0"
  /* 4513 */ "SETP_GT\0"
  /* 4521 */ "C_BAR_WAIT\0"
  /* 4532 */ "BAR_INIT\0"
  /* 4541 */ "C_EXIT\0"
  /* 4548 */ "PATCHABLE_FUNCTION_EXIT\0"
  /* 4572 */ "G_BRJT\0"
  /* 4579 */ "G_EXTRACT_VECTOR_ELT\0"
  /* 4600 */ "G_INSERT_VECTOR_ELT\0"
  /* 4620 */ "SETP_LT\0"
  /* 4628 */ "G_FCONSTANT\0"
  /* 4640 */ "G_CONSTANT\0"
  /* 4651 */ "G_INTRINSIC_CONVERGENT\0"
  /* 4674 */ "STATEPOINT\0"
  /* 4685 */ "PATCHPOINT\0"
  /* 4696 */ "G_PTRTOINT\0"
  /* 4707 */ "G_FRINT\0"
  /* 4715 */ "G_INTRINSIC_LRINT\0"
  /* 4733 */ "G_FNEARBYINT\0"
  /* 4746 */ "UNBALLOT\0"
  /* 4755 */ "LD_GLOBAL_SLOT\0"
  /* 4770 */ "ST_GLOBAL_SLOT\0"
  /* 4785 */ "C_NOT\0"
  /* 4791 */ "G_VASTART\0"
  /* 4801 */ "LIFETIME_START\0"
  /* 4816 */ "G_INVOKE_REGION_START\0"
  /* 4838 */ "G_INSERT\0"
  /* 4847 */ "G_FSQRT\0"
  /* 4855 */ "G_STRICT_FSQRT\0"
  /* 4870 */ "PSEUDO_BCAST\0"
  /* 4883 */ "G_BITCAST\0"
  /* 4893 */ "G_ADDRSPACE_CAST\0"
  /* 4910 */ "DBG_VALUE_LIST\0"
  /* 4925 */ "G_FPEXT\0"
  /* 4933 */ "G_SEXT\0"
  /* 4940 */ "G_ASSERT_SEXT\0"
  /* 4954 */ "CVT_SEXT\0"
  /* 4963 */ "G_ANYEXT\0"
  /* 4972 */ "G_ZEXT\0"
  /* 4979 */ "G_ASSERT_ZEXT\0"
  /* 4993 */ "SETP_GE_U\0"
  /* 5003 */ "SETP_LE_U\0"
  /* 5013 */ "MUL_HI_U\0"
  /* 5022 */ "C_MIN_U\0"
  /* 5030 */ "SETP_GT_U\0"
  /* 5040 */ "SETP_LT_U\0"
  /* 5050 */ "C_MAX_U\0"
  /* 5058 */ "BREV\0"
  /* 5063 */ "G_FDIV\0"
  /* 5070 */ "G_STRICT_FDIV\0"
  /* 5084 */ "G_SDIV\0"
  /* 5091 */ "G_UDIV\0"
  /* 5098 */ "G_GET_FPENV\0"
  /* 5110 */ "G_RESET_FPENV\0"
  /* 5124 */ "G_SET_FPENV\0"
  /* 5136 */ "C_RECONV\0"
  /* 5145 */ "PSEUDO_PMOV\0"
  /* 5157 */ "C_MOV\0"
  /* 5163 */ "G_FPOW\0"
  /* 5170 */ "C_FMAX\0"
  /* 5177 */ "G_VECREDUCE_FMAX\0"
  /* 5194 */ "G_ATOMICRMW_FMAX\0"
  /* 5211 */ "G_VECREDUCE_SMAX\0"
  /* 5228 */ "G_SMAX\0"
  /* 5235 */ "G_VECREDUCE_UMAX\0"
  /* 5252 */ "G_UMAX\0"
  /* 5259 */ "G_ATOMICRMW_UMAX\0"
  /* 5276 */ "G_ATOMICRMW_MAX\0"
  /* 5292 */ "LD_SHARED_IDX\0"
  /* 5306 */ "ST_SHARED_IDX\0"
  /* 5320 */ "LD_GLOBAL_IDX\0"
  /* 5334 */ "ST_GLOBAL_IDX\0"
  /* 5348 */ "SHFL_IDX\0"
  /* 5357 */ "G_FRAME_INDEX\0"
  /* 5371 */ "G_SBFX\0"
  /* 5378 */ "G_UBFX\0"
  /* 5385 */ "G_SMULFIX\0"
  /* 5395 */ "G_UMULFIX\0"
  /* 5405 */ "G_SDIVFIX\0"
  /* 5415 */ "G_UDIVFIX\0"
  /* 5425 */ "VOTE_ANY\0"
  /* 5434 */ "G_MEMCPY\0"
  /* 5443 */ "COPY\0"
  /* 5448 */ "CLZ\0"
  /* 5452 */ "G_CTLZ\0"
  /* 5459 */ "G_CTTZ\0"
  /* 5466 */ "PACKI_Z\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned CCVInstrNameIndices[] = {
    1821U, 2698U, 3757U, 2977U, 2361U, 2342U, 2370U, 2518U, 
    1593U, 1608U, 1493U, 1635U, 4163U, 1370U, 4910U, 1506U, 
    1817U, 2351U, 1130U, 5443U, 1251U, 4801U, 967U, 1073U, 
    1118U, 3086U, 2506U, 4685U, 1052U, 3423U, 1698U, 4674U, 
    1290U, 3396U, 3383U, 3818U, 4490U, 4548U, 2438U, 2485U, 
    2458U, 2387U, 3783U, 3025U, 4940U, 4979U, 2821U, 826U, 
    503U, 2628U, 5084U, 5091U, 2655U, 2662U, 2669U, 2679U, 
    945U, 4050U, 4008U, 1491U, 1819U, 5357U, 1380U, 2523U, 
    4452U, 4107U, 4838U, 4124U, 3942U, 589U, 4146U, 4696U, 
    4077U, 4883U, 1430U, 3794U, 1026U, 563U, 1008U, 4715U, 
    2799U, 3843U, 714U, 658U, 688U, 699U, 639U, 669U, 
    1334U, 1318U, 4193U, 1649U, 1666U, 842U, 509U, 951U, 
    894U, 4055U, 4014U, 5276U, 2954U, 5259U, 2937U, 787U, 
    480U, 5194U, 2872U, 3117U, 3095U, 1110U, 1752U, 980U, 
    4471U, 4816U, 541U, 4230U, 4651U, 4257U, 4963U, 581U, 
    4640U, 4628U, 4791U, 1690U, 4933U, 1622U, 4972U, 2424U, 
    3909U, 3895U, 2411U, 3902U, 4070U, 2539U, 3172U, 3165U, 
    4462U, 3017U, 1151U, 3001U, 1094U, 3009U, 1143U, 2993U, 
    1086U, 3061U, 3053U, 1771U, 1763U, 4370U, 4360U, 4350U, 
    4340U, 4390U, 4380U, 5385U, 5395U, 4400U, 4413U, 5405U, 
    5415U, 4426U, 4439U, 745U, 459U, 2570U, 428U, 632U, 
    5063U, 2634U, 5163U, 2120U, 3467U, 189U, 9U, 1683U, 
    172U, 0U, 3442U, 3474U, 1580U, 4925U, 553U, 2083U, 
    2106U, 3147U, 3156U, 4088U, 2836U, 4180U, 1439U, 2772U, 
    2782U, 1200U, 1215U, 2729U, 2761U, 5098U, 5124U, 5110U, 
    1159U, 1187U, 1172U, 832U, 2308U, 2906U, 5228U, 2930U, 
    5252U, 4101U, 999U, 989U, 3752U, 4572U, 4600U, 4579U, 
    3957U, 5459U, 1473U, 5452U, 1455U, 3375U, 3139U, 1357U, 
    2430U, 4139U, 2970U, 4847U, 3922U, 4707U, 4733U, 4893U, 
    3770U, 1238U, 610U, 1395U, 1303U, 773U, 466U, 2598U, 
    5070U, 2641U, 434U, 4855U, 3451U, 3862U, 3878U, 5434U, 
    1266U, 1420U, 4504U, 3078U, 752U, 2577U, 728U, 2553U, 
    5177U, 2855U, 2740U, 2708U, 810U, 2612U, 929U, 4035U, 
    3992U, 5211U, 2889U, 5235U, 2913U, 5371U, 5378U, 4870U, 
    878U, 911U, 5145U, 3931U, 3974U, 4091U, 724U, 1805U, 
    414U, 3589U, 3415U, 275U, 3563U, 3408U, 231U, 907U, 
    1812U, 3596U, 2794U, 1845U, 3617U, 3569U, 267U, 1715U, 
    4748U, 4532U, 1342U, 449U, 885U, 5058U, 2453U, 1746U, 
    2092U, 5448U, 122U, 140U, 3521U, 152U, 3535U, 66U, 
    3483U, 4954U, 78U, 3497U, 4095U, 804U, 1803U, 923U, 
    1810U, 2792U, 1407U, 4521U, 447U, 1779U, 4541U, 721U, 
    1102U, 5170U, 2848U, 2546U, 2318U, 4332U, 5050U, 4324U, 
    5022U, 5157U, 3069U, 1587U, 4785U, 4030U, 2077U, 5136U, 
    4484U, 2418U, 1833U, 3916U, 2063U, 453U, 1789U, 2330U, 
    497U, 1796U, 3986U, 2070U, 206U, 215U, 525U, 197U, 
    180U, 4223U, 98U, 46U, 723U, 3562U, 26U, 54U, 
    18U, 5172U, 2850U, 2548U, 3657U, 38U, 461U, 3555U, 
    2320U, 5320U, 378U, 3639U, 4755U, 340U, 284U, 1726U, 
    4295U, 858U, 5292U, 239U, 90U, 3047U, 3664U, 533U, 
    4334U, 3703U, 330U, 5052U, 3730U, 4326U, 3695U, 320U, 
    5024U, 3722U, 2115U, 421U, 3738U, 1840U, 3610U, 4315U, 
    3684U, 5013U, 3711U, 3071U, 1583U, 3928U, 2073U, 3633U, 
    3679U, 313U, 1827U, 5466U, 918U, 5152U, 2689U, 627U, 
    3938U, 3981U, 114U, 3511U, 164U, 130U, 2407U, 3744U, 
    1550U, 2194U, 3251U, 1929U, 2230U, 3290U, 1971U, 1230U, 
    1520U, 2158U, 3212U, 1887U, 2128U, 3179U, 1851U, 4993U, 
    2260U, 3323U, 2007U, 4513U, 1560U, 2206U, 3264U, 1943U, 
    2240U, 3301U, 1983U, 5030U, 2284U, 3349U, 2035U, 1258U, 
    1530U, 2170U, 3225U, 1901U, 2138U, 3190U, 1863U, 5003U, 
    2272U, 3336U, 2021U, 4620U, 1570U, 2218U, 3277U, 1957U, 
    2250U, 3312U, 1995U, 5040U, 2296U, 3362U, 2049U, 1282U, 
    1540U, 2182U, 3238U, 1915U, 2148U, 3201U, 1875U, 5348U, 
    2414U, 1835U, 3603U, 3651U, 3898U, 2065U, 3625U, 3672U, 
    106U, 131U, 455U, 1791U, 3575U, 3549U, 1069U, 2332U, 
    5334U, 396U, 4770U, 359U, 298U, 1736U, 4305U, 868U, 
    5306U, 253U, 462U, 1798U, 3582U, 3556U, 223U, 4746U, 
    1825U, 5425U, 3982U, 2072U, 3632U, 3678U, 312U, 
};

static inline void InitCCVMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 535);
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
  InitMCInstrInfo(CCVDescs.Insts, CCVInstrNameIndices, CCVInstrNameData, nullptr, nullptr, 535);
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
  f32imm = 3,
  f64imm = 4,
  i1imm = 5,
  i8imm = 6,
  i16imm = 7,
  i32imm = 8,
  i64imm = 9,
  pidx2 = 10,
  pmask4 = 11,
  pqual = 12,
  psrc = 13,
  ptype0 = 14,
  ptype1 = 15,
  ptype2 = 16,
  ptype3 = 17,
  ptype4 = 18,
  ptype5 = 19,
  simm8 = 20,
  simm9 = 21,
  simm10 = 22,
  simm13 = 23,
  simm16 = 24,
  simm17 = 25,
  simm18 = 26,
  simm21 = 27,
  srdsel = 28,
  type0 = 29,
  type1 = 30,
  type2 = 31,
  type3 = 32,
  type4 = 33,
  type5 = 34,
  uimm2 = 35,
  uimm3 = 36,
  uimm4 = 37,
  uimm5 = 38,
  uimm6 = 39,
  uimm8 = 40,
  uimm10 = 41,
  uimm16 = 42,
  uimm17 = 43,
  uimm29 = 44,
  uimm32 = 45,
  uimm33 = 46,
  untyped_imm_0 = 47,
  GPR = 48,
  GPR16 = 49,
  PR = 50,
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
    /* PSEUDO_BCAST */
    665,
    /* PSEUDO_BRA_PRED */
    667,
    /* PSEUDO_PAND */
    670,
    /* PSEUDO_PMOV */
    673,
    /* PSEUDO_POR */
    677,
    /* PSEUDO_PXOR */
    680,
    /* ABS */
    683,
    /* ADD */
    687,
    /* ADDI */
    691,
    /* ADDI48 */
    694,
    /* ADDI_P */
    697,
    /* ADDI_PP */
    701,
    /* ADDI_W16 */
    706,
    /* ADD_P */
    709,
    /* ADD_PP */
    714,
    /* ADD_W16 */
    720,
    /* AND */
    724,
    /* ANDI */
    728,
    /* ANDI_P */
    731,
    /* ANDN */
    735,
    /* ANDNI */
    739,
    /* ANDNI_P */
    742,
    /* AND_P */
    746,
    /* AND_W16 */
    751,
    /* ATOM_ADD_G */
    755,
    /* BALLOT */
    759,
    /* BAR_INIT */
    762,
    /* BAR_WAIT_PHASE */
    764,
    /* BRA */
    767,
    /* BRA_PRED */
    768,
    /* BREV */
    770,
    /* CALL */
    774,
    /* CAS_G */
    776,
    /* CHWIDTH_MULTI */
    783,
    /* CLZ */
    785,
    /* COS_F32 */
    789,
    /* CVT_F32_S32 */
    793,
    /* CVT_F32_S32_P */
    797,
    /* CVT_F32_U32 */
    802,
    /* CVT_F32_U32_P */
    806,
    /* CVT_S32_F32 */
    811,
    /* CVT_S32_F32_P */
    815,
    /* CVT_SEXT */
    820,
    /* CVT_U32_F32 */
    824,
    /* CVT_U32_F32_P */
    828,
    /* C_ABS */
    833,
    /* C_ADD */
    835,
    /* C_ADDI */
    838,
    /* C_AND */
    841,
    /* C_ANDI */
    844,
    /* C_ANDN */
    847,
    /* C_BAR_ARRIVE */
    850,
    /* C_BAR_WAIT */
    851,
    /* C_BRA */
    852,
    /* C_CHWIDTH */
    853,
    /* C_EXIT */
    855,
    /* C_FADD */
    856,
    /* C_FENCE */
    859,
    /* C_FMAX */
    860,
    /* C_FMIN */
    863,
    /* C_FMUL */
    866,
    /* C_LD_GLOBAL */
    869,
    /* C_MAX_S */
    871,
    /* C_MAX_U */
    874,
    /* C_MIN_S */
    877,
    /* C_MIN_U */
    880,
    /* C_MOV */
    883,
    /* C_MUL_LO */
    885,
    /* C_NEG */
    888,
    /* C_NOT */
    890,
    /* C_OR */
    892,
    /* C_ORI */
    895,
    /* C_RECONV */
    898,
    /* C_RET */
    899,
    /* C_SHL */
    900,
    /* C_SHLI */
    903,
    /* C_SHR */
    906,
    /* C_SHRI */
    909,
    /* C_SRA */
    912,
    /* C_SRAI */
    915,
    /* C_ST_GLOBAL */
    918,
    /* C_SUB */
    920,
    /* C_SUBI */
    923,
    /* C_XOR */
    926,
    /* C_XORI */
    929,
    /* DP2_BF16 */
    932,
    /* DP2_F16 */
    936,
    /* DP4_ACC */
    940,
    /* DP4_E4M3 */
    944,
    /* DP4_E5M2 */
    948,
    /* DP4_SS */
    952,
    /* EX2_F32 */
    956,
    /* FABS_F0 */
    960,
    /* FADD */
    964,
    /* FADD_P */
    968,
    /* FFMA_ACC_F0 */
    973,
    /* FFMA_ACC_F1 */
    977,
    /* FFMA_F0 */
    981,
    /* FMAX */
    985,
    /* FMIN */
    989,
    /* FMUL */
    993,
    /* FMUL_P */
    997,
    /* FNEG_F0 */
    1002,
    /* FSUB */
    1006,
    /* FSUB_P */
    1010,
    /* LD_GLOBAL */
    1015,
    /* LD_GLOBAL_IDX */
    1018,
    /* LD_GLOBAL_IDX_W16 */
    1023,
    /* LD_GLOBAL_P */
    1028,
    /* LD_GLOBAL_SLOT */
    1032,
    /* LD_GLOBAL_SLOT_W16 */
    1037,
    /* LD_GLOBAL_W16 */
    1042,
    /* LD_PRED_G */
    1045,
    /* LD_PRED_S */
    1048,
    /* LD_SHARED */
    1051,
    /* LD_SHARED_IDX */
    1054,
    /* LD_SHARED_W16 */
    1059,
    /* LG2_F32 */
    1062,
    /* MADLO */
    1066,
    /* MADLO_P */
    1070,
    /* MAD_ACC */
    1075,
    /* MAX_S */
    1079,
    /* MAX_S_P */
    1083,
    /* MAX_S_W16 */
    1088,
    /* MAX_U */
    1092,
    /* MAX_U_P */
    1096,
    /* MIN_S */
    1101,
    /* MIN_S_P */
    1105,
    /* MIN_S_W16 */
    1110,
    /* MIN_U */
    1114,
    /* MIN_U_P */
    1118,
    /* MOVI */
    1123,
    /* MOVI48 */
    1125,
    /* MOV_P */
    1127,
    /* MULI */
    1133,
    /* MULI_P */
    1136,
    /* MUL_HI_S */
    1140,
    /* MUL_HI_S_P */
    1144,
    /* MUL_HI_U */
    1149,
    /* MUL_HI_U_P */
    1153,
    /* MUL_LO */
    1158,
    /* NEG */
    1162,
    /* OR */
    1166,
    /* ORI */
    1170,
    /* ORI_P */
    1173,
    /* OR_P */
    1177,
    /* OR_W16 */
    1182,
    /* PACKI */
    1186,
    /* PACKI_Z */
    1190,
    /* PAND */
    1193,
    /* PMOV */
    1196,
    /* PMOV_IMM */
    1199,
    /* POPC */
    1201,
    /* POR */
    1205,
    /* PXOR */
    1208,
    /* RCP_F32 */
    1211,
    /* RCP_F32_P */
    1215,
    /* RCP_U32 */
    1220,
    /* RSQRT_F32 */
    1224,
    /* SEL */
    1228,
    /* SETP_EQ */
    1233,
    /* SETP_EQ_F */
    1238,
    /* SETP_EQ_F_I */
    1243,
    /* SETP_EQ_F_NP */
    1248,
    /* SETP_EQ_F_NPI */
    1252,
    /* SETP_EQ_I */
    1256,
    /* SETP_EQ_NP */
    1261,
    /* SETP_EQ_NPI */
    1265,
    /* SETP_GE */
    1269,
    /* SETP_GE_F */
    1274,
    /* SETP_GE_F_I */
    1279,
    /* SETP_GE_F_NP */
    1284,
    /* SETP_GE_F_NPI */
    1288,
    /* SETP_GE_I */
    1292,
    /* SETP_GE_NP */
    1297,
    /* SETP_GE_NPI */
    1301,
    /* SETP_GE_U */
    1305,
    /* SETP_GE_U_I */
    1310,
    /* SETP_GE_U_NP */
    1315,
    /* SETP_GE_U_NPI */
    1319,
    /* SETP_GT */
    1323,
    /* SETP_GT_F */
    1328,
    /* SETP_GT_F_I */
    1333,
    /* SETP_GT_F_NP */
    1338,
    /* SETP_GT_F_NPI */
    1342,
    /* SETP_GT_I */
    1346,
    /* SETP_GT_NP */
    1351,
    /* SETP_GT_NPI */
    1355,
    /* SETP_GT_U */
    1359,
    /* SETP_GT_U_I */
    1364,
    /* SETP_GT_U_NP */
    1369,
    /* SETP_GT_U_NPI */
    1373,
    /* SETP_LE */
    1377,
    /* SETP_LE_F */
    1382,
    /* SETP_LE_F_I */
    1387,
    /* SETP_LE_F_NP */
    1392,
    /* SETP_LE_F_NPI */
    1396,
    /* SETP_LE_I */
    1400,
    /* SETP_LE_NP */
    1405,
    /* SETP_LE_NPI */
    1409,
    /* SETP_LE_U */
    1413,
    /* SETP_LE_U_I */
    1418,
    /* SETP_LE_U_NP */
    1423,
    /* SETP_LE_U_NPI */
    1427,
    /* SETP_LT */
    1431,
    /* SETP_LT_F */
    1436,
    /* SETP_LT_F_I */
    1441,
    /* SETP_LT_F_NP */
    1446,
    /* SETP_LT_F_NPI */
    1450,
    /* SETP_LT_I */
    1454,
    /* SETP_LT_NP */
    1459,
    /* SETP_LT_NPI */
    1463,
    /* SETP_LT_U */
    1467,
    /* SETP_LT_U_I */
    1472,
    /* SETP_LT_U_NP */
    1477,
    /* SETP_LT_U_NPI */
    1481,
    /* SETP_NE */
    1485,
    /* SETP_NE_F */
    1490,
    /* SETP_NE_F_I */
    1495,
    /* SETP_NE_F_NP */
    1500,
    /* SETP_NE_F_NPI */
    1504,
    /* SETP_NE_I */
    1508,
    /* SETP_NE_NP */
    1513,
    /* SETP_NE_NPI */
    1517,
    /* SHFL_IDX */
    1521,
    /* SHL */
    1525,
    /* SHLI */
    1529,
    /* SHLI_P */
    1532,
    /* SHL_P */
    1536,
    /* SHR */
    1541,
    /* SHRI */
    1545,
    /* SHRI_P */
    1548,
    /* SHR_P */
    1552,
    /* SIN_F32 */
    1557,
    /* SQRT_F32 */
    1561,
    /* SRA */
    1565,
    /* SRAI */
    1569,
    /* SRAI_P */
    1572,
    /* SRA_P */
    1576,
    /* SRD */
    1581,
    /* ST_GLOBAL */
    1583,
    /* ST_GLOBAL_IDX */
    1586,
    /* ST_GLOBAL_IDX_W16 */
    1591,
    /* ST_GLOBAL_SLOT */
    1596,
    /* ST_GLOBAL_SLOT_W16 */
    1601,
    /* ST_GLOBAL_W16 */
    1606,
    /* ST_PRED_G */
    1609,
    /* ST_PRED_S */
    1612,
    /* ST_SHARED */
    1615,
    /* ST_SHARED_IDX */
    1618,
    /* ST_SHARED_W16 */
    1623,
    /* SUB */
    1626,
    /* SUBI */
    1630,
    /* SUBI_P */
    1633,
    /* SUB_P */
    1637,
    /* SUB_W16 */
    1642,
    /* UNBALLOT */
    1646,
    /* UNPACKI */
    1649,
    /* VOTE_ANY */
    1652,
    /* XOR */
    1655,
    /* XORI */
    1659,
    /* XORI_P */
    1662,
    /* XOR_P */
    1666,
    /* XOR_W16 */
    1671,
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
    /* PSEUDO_BCAST */
    GPR, GPR, 
    /* PSEUDO_BRA_PRED */
    PR, i32imm, brtarget18, 
    /* PSEUDO_PAND */
    PR, PR, PR, 
    /* PSEUDO_PMOV */
    GPR, GPR, PR, GPR, 
    /* PSEUDO_POR */
    PR, PR, PR, 
    /* PSEUDO_PXOR */
    PR, PR, PR, 
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
    GPR, simm17, 
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
    /* LD_GLOBAL_P */
    GPR, pqual, GPR, simm10, 
    /* LD_GLOBAL_SLOT */
    GPR, uimm4, GPR, uimm2, simm8, 
    /* LD_GLOBAL_SLOT_W16 */
    GPR16, uimm4, GPR, uimm2, simm8, 
    /* LD_GLOBAL_W16 */
    GPR16, GPR, simm13, 
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
    /* ST_GLOBAL_SLOT */
    GPR, uimm4, GPR, uimm2, simm8, 
    /* ST_GLOBAL_SLOT_W16 */
    GPR16, uimm4, GPR, uimm2, simm8, 
    /* ST_GLOBAL_W16 */
    GPR16, GPR, simm13, 
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
    CEFBS_None, // PSEUDO_BCAST = 271
    CEFBS_None, // PSEUDO_BRA_PRED = 272
    CEFBS_None, // PSEUDO_PAND = 273
    CEFBS_None, // PSEUDO_PMOV = 274
    CEFBS_None, // PSEUDO_POR = 275
    CEFBS_None, // PSEUDO_PXOR = 276
    CEFBS_None, // ABS = 277
    CEFBS_None, // ADD = 278
    CEFBS_None, // ADDI = 279
    CEFBS_None, // ADDI48 = 280
    CEFBS_None, // ADDI_P = 281
    CEFBS_None, // ADDI_PP = 282
    CEFBS_None, // ADDI_W16 = 283
    CEFBS_None, // ADD_P = 284
    CEFBS_None, // ADD_PP = 285
    CEFBS_None, // ADD_W16 = 286
    CEFBS_None, // AND = 287
    CEFBS_None, // ANDI = 288
    CEFBS_None, // ANDI_P = 289
    CEFBS_None, // ANDN = 290
    CEFBS_None, // ANDNI = 291
    CEFBS_None, // ANDNI_P = 292
    CEFBS_None, // AND_P = 293
    CEFBS_None, // AND_W16 = 294
    CEFBS_None, // ATOM_ADD_G = 295
    CEFBS_None, // BALLOT = 296
    CEFBS_None, // BAR_INIT = 297
    CEFBS_None, // BAR_WAIT_PHASE = 298
    CEFBS_None, // BRA = 299
    CEFBS_None, // BRA_PRED = 300
    CEFBS_None, // BREV = 301
    CEFBS_None, // CALL = 302
    CEFBS_None, // CAS_G = 303
    CEFBS_None, // CHWIDTH_MULTI = 304
    CEFBS_None, // CLZ = 305
    CEFBS_None, // COS_F32 = 306
    CEFBS_None, // CVT_F32_S32 = 307
    CEFBS_None, // CVT_F32_S32_P = 308
    CEFBS_None, // CVT_F32_U32 = 309
    CEFBS_None, // CVT_F32_U32_P = 310
    CEFBS_None, // CVT_S32_F32 = 311
    CEFBS_None, // CVT_S32_F32_P = 312
    CEFBS_None, // CVT_SEXT = 313
    CEFBS_None, // CVT_U32_F32 = 314
    CEFBS_None, // CVT_U32_F32_P = 315
    CEFBS_None, // C_ABS = 316
    CEFBS_None, // C_ADD = 317
    CEFBS_None, // C_ADDI = 318
    CEFBS_None, // C_AND = 319
    CEFBS_None, // C_ANDI = 320
    CEFBS_None, // C_ANDN = 321
    CEFBS_None, // C_BAR_ARRIVE = 322
    CEFBS_None, // C_BAR_WAIT = 323
    CEFBS_None, // C_BRA = 324
    CEFBS_None, // C_CHWIDTH = 325
    CEFBS_None, // C_EXIT = 326
    CEFBS_None, // C_FADD = 327
    CEFBS_None, // C_FENCE = 328
    CEFBS_None, // C_FMAX = 329
    CEFBS_None, // C_FMIN = 330
    CEFBS_None, // C_FMUL = 331
    CEFBS_None, // C_LD_GLOBAL = 332
    CEFBS_None, // C_MAX_S = 333
    CEFBS_None, // C_MAX_U = 334
    CEFBS_None, // C_MIN_S = 335
    CEFBS_None, // C_MIN_U = 336
    CEFBS_None, // C_MOV = 337
    CEFBS_None, // C_MUL_LO = 338
    CEFBS_None, // C_NEG = 339
    CEFBS_None, // C_NOT = 340
    CEFBS_None, // C_OR = 341
    CEFBS_None, // C_ORI = 342
    CEFBS_None, // C_RECONV = 343
    CEFBS_None, // C_RET = 344
    CEFBS_None, // C_SHL = 345
    CEFBS_None, // C_SHLI = 346
    CEFBS_None, // C_SHR = 347
    CEFBS_None, // C_SHRI = 348
    CEFBS_None, // C_SRA = 349
    CEFBS_None, // C_SRAI = 350
    CEFBS_None, // C_ST_GLOBAL = 351
    CEFBS_None, // C_SUB = 352
    CEFBS_None, // C_SUBI = 353
    CEFBS_None, // C_XOR = 354
    CEFBS_None, // C_XORI = 355
    CEFBS_None, // DP2_BF16 = 356
    CEFBS_None, // DP2_F16 = 357
    CEFBS_None, // DP4_ACC = 358
    CEFBS_None, // DP4_E4M3 = 359
    CEFBS_None, // DP4_E5M2 = 360
    CEFBS_None, // DP4_SS = 361
    CEFBS_None, // EX2_F32 = 362
    CEFBS_None, // FABS_F0 = 363
    CEFBS_None, // FADD = 364
    CEFBS_None, // FADD_P = 365
    CEFBS_None, // FFMA_ACC_F0 = 366
    CEFBS_None, // FFMA_ACC_F1 = 367
    CEFBS_None, // FFMA_F0 = 368
    CEFBS_None, // FMAX = 369
    CEFBS_None, // FMIN = 370
    CEFBS_None, // FMUL = 371
    CEFBS_None, // FMUL_P = 372
    CEFBS_None, // FNEG_F0 = 373
    CEFBS_None, // FSUB = 374
    CEFBS_None, // FSUB_P = 375
    CEFBS_None, // LD_GLOBAL = 376
    CEFBS_None, // LD_GLOBAL_IDX = 377
    CEFBS_None, // LD_GLOBAL_IDX_W16 = 378
    CEFBS_None, // LD_GLOBAL_P = 379
    CEFBS_None, // LD_GLOBAL_SLOT = 380
    CEFBS_None, // LD_GLOBAL_SLOT_W16 = 381
    CEFBS_None, // LD_GLOBAL_W16 = 382
    CEFBS_None, // LD_PRED_G = 383
    CEFBS_None, // LD_PRED_S = 384
    CEFBS_None, // LD_SHARED = 385
    CEFBS_None, // LD_SHARED_IDX = 386
    CEFBS_None, // LD_SHARED_W16 = 387
    CEFBS_None, // LG2_F32 = 388
    CEFBS_None, // MADLO = 389
    CEFBS_None, // MADLO_P = 390
    CEFBS_None, // MAD_ACC = 391
    CEFBS_None, // MAX_S = 392
    CEFBS_None, // MAX_S_P = 393
    CEFBS_None, // MAX_S_W16 = 394
    CEFBS_None, // MAX_U = 395
    CEFBS_None, // MAX_U_P = 396
    CEFBS_None, // MIN_S = 397
    CEFBS_None, // MIN_S_P = 398
    CEFBS_None, // MIN_S_W16 = 399
    CEFBS_None, // MIN_U = 400
    CEFBS_None, // MIN_U_P = 401
    CEFBS_None, // MOVI = 402
    CEFBS_None, // MOVI48 = 403
    CEFBS_None, // MOV_P = 404
    CEFBS_None, // MULI = 405
    CEFBS_None, // MULI_P = 406
    CEFBS_None, // MUL_HI_S = 407
    CEFBS_None, // MUL_HI_S_P = 408
    CEFBS_None, // MUL_HI_U = 409
    CEFBS_None, // MUL_HI_U_P = 410
    CEFBS_None, // MUL_LO = 411
    CEFBS_None, // NEG = 412
    CEFBS_None, // OR = 413
    CEFBS_None, // ORI = 414
    CEFBS_None, // ORI_P = 415
    CEFBS_None, // OR_P = 416
    CEFBS_None, // OR_W16 = 417
    CEFBS_None, // PACKI = 418
    CEFBS_None, // PACKI_Z = 419
    CEFBS_None, // PAND = 420
    CEFBS_None, // PMOV = 421
    CEFBS_None, // PMOV_IMM = 422
    CEFBS_None, // POPC = 423
    CEFBS_None, // POR = 424
    CEFBS_None, // PXOR = 425
    CEFBS_None, // RCP_F32 = 426
    CEFBS_None, // RCP_F32_P = 427
    CEFBS_None, // RCP_U32 = 428
    CEFBS_None, // RSQRT_F32 = 429
    CEFBS_None, // SEL = 430
    CEFBS_None, // SETP_EQ = 431
    CEFBS_None, // SETP_EQ_F = 432
    CEFBS_None, // SETP_EQ_F_I = 433
    CEFBS_None, // SETP_EQ_F_NP = 434
    CEFBS_None, // SETP_EQ_F_NPI = 435
    CEFBS_None, // SETP_EQ_I = 436
    CEFBS_None, // SETP_EQ_NP = 437
    CEFBS_None, // SETP_EQ_NPI = 438
    CEFBS_None, // SETP_GE = 439
    CEFBS_None, // SETP_GE_F = 440
    CEFBS_None, // SETP_GE_F_I = 441
    CEFBS_None, // SETP_GE_F_NP = 442
    CEFBS_None, // SETP_GE_F_NPI = 443
    CEFBS_None, // SETP_GE_I = 444
    CEFBS_None, // SETP_GE_NP = 445
    CEFBS_None, // SETP_GE_NPI = 446
    CEFBS_None, // SETP_GE_U = 447
    CEFBS_None, // SETP_GE_U_I = 448
    CEFBS_None, // SETP_GE_U_NP = 449
    CEFBS_None, // SETP_GE_U_NPI = 450
    CEFBS_None, // SETP_GT = 451
    CEFBS_None, // SETP_GT_F = 452
    CEFBS_None, // SETP_GT_F_I = 453
    CEFBS_None, // SETP_GT_F_NP = 454
    CEFBS_None, // SETP_GT_F_NPI = 455
    CEFBS_None, // SETP_GT_I = 456
    CEFBS_None, // SETP_GT_NP = 457
    CEFBS_None, // SETP_GT_NPI = 458
    CEFBS_None, // SETP_GT_U = 459
    CEFBS_None, // SETP_GT_U_I = 460
    CEFBS_None, // SETP_GT_U_NP = 461
    CEFBS_None, // SETP_GT_U_NPI = 462
    CEFBS_None, // SETP_LE = 463
    CEFBS_None, // SETP_LE_F = 464
    CEFBS_None, // SETP_LE_F_I = 465
    CEFBS_None, // SETP_LE_F_NP = 466
    CEFBS_None, // SETP_LE_F_NPI = 467
    CEFBS_None, // SETP_LE_I = 468
    CEFBS_None, // SETP_LE_NP = 469
    CEFBS_None, // SETP_LE_NPI = 470
    CEFBS_None, // SETP_LE_U = 471
    CEFBS_None, // SETP_LE_U_I = 472
    CEFBS_None, // SETP_LE_U_NP = 473
    CEFBS_None, // SETP_LE_U_NPI = 474
    CEFBS_None, // SETP_LT = 475
    CEFBS_None, // SETP_LT_F = 476
    CEFBS_None, // SETP_LT_F_I = 477
    CEFBS_None, // SETP_LT_F_NP = 478
    CEFBS_None, // SETP_LT_F_NPI = 479
    CEFBS_None, // SETP_LT_I = 480
    CEFBS_None, // SETP_LT_NP = 481
    CEFBS_None, // SETP_LT_NPI = 482
    CEFBS_None, // SETP_LT_U = 483
    CEFBS_None, // SETP_LT_U_I = 484
    CEFBS_None, // SETP_LT_U_NP = 485
    CEFBS_None, // SETP_LT_U_NPI = 486
    CEFBS_None, // SETP_NE = 487
    CEFBS_None, // SETP_NE_F = 488
    CEFBS_None, // SETP_NE_F_I = 489
    CEFBS_None, // SETP_NE_F_NP = 490
    CEFBS_None, // SETP_NE_F_NPI = 491
    CEFBS_None, // SETP_NE_I = 492
    CEFBS_None, // SETP_NE_NP = 493
    CEFBS_None, // SETP_NE_NPI = 494
    CEFBS_None, // SHFL_IDX = 495
    CEFBS_None, // SHL = 496
    CEFBS_None, // SHLI = 497
    CEFBS_None, // SHLI_P = 498
    CEFBS_None, // SHL_P = 499
    CEFBS_None, // SHR = 500
    CEFBS_None, // SHRI = 501
    CEFBS_None, // SHRI_P = 502
    CEFBS_None, // SHR_P = 503
    CEFBS_None, // SIN_F32 = 504
    CEFBS_None, // SQRT_F32 = 505
    CEFBS_None, // SRA = 506
    CEFBS_None, // SRAI = 507
    CEFBS_None, // SRAI_P = 508
    CEFBS_None, // SRA_P = 509
    CEFBS_None, // SRD = 510
    CEFBS_None, // ST_GLOBAL = 511
    CEFBS_None, // ST_GLOBAL_IDX = 512
    CEFBS_None, // ST_GLOBAL_IDX_W16 = 513
    CEFBS_None, // ST_GLOBAL_SLOT = 514
    CEFBS_None, // ST_GLOBAL_SLOT_W16 = 515
    CEFBS_None, // ST_GLOBAL_W16 = 516
    CEFBS_None, // ST_PRED_G = 517
    CEFBS_None, // ST_PRED_S = 518
    CEFBS_None, // ST_SHARED = 519
    CEFBS_None, // ST_SHARED_IDX = 520
    CEFBS_None, // ST_SHARED_W16 = 521
    CEFBS_None, // SUB = 522
    CEFBS_None, // SUBI = 523
    CEFBS_None, // SUBI_P = 524
    CEFBS_None, // SUB_P = 525
    CEFBS_None, // SUB_W16 = 526
    CEFBS_None, // UNBALLOT = 527
    CEFBS_None, // UNPACKI = 528
    CEFBS_None, // VOTE_ANY = 529
    CEFBS_None, // XOR = 530
    CEFBS_None, // XORI = 531
    CEFBS_None, // XORI_P = 532
    CEFBS_None, // XOR_P = 533
    CEFBS_None, // XOR_W16 = 534
  };

  assert(Opcode < 535);
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

