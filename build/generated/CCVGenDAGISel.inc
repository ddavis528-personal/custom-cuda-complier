/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* DAG Instruction Selector for the CCV target                                *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

// *** NOTE: This file is #included into the middle of the target
// *** instruction selector class.  These functions are really methods.

// If GET_DAGISEL_DECL is #defined with any value, only function
// declarations will be included when this file is included.
// If GET_DAGISEL_BODY is #defined, its value should be the name of
// the instruction selector class. Function bodies will be emitted
// and each function's name will be qualified with the name of the
// class.
//
// When neither of the GET_DAGISEL* macros is defined, the functions
// are emitted inline.

#if defined(GET_DAGISEL_DECL) && defined(GET_DAGISEL_BODY)
#error GET_DAGISEL_DECL and GET_DAGISEL_BODY cannot be both defined, undef both for inline definitions
#endif

#ifdef GET_DAGISEL_BODY
#define LOCAL_DAGISEL_STRINGIZE(X) LOCAL_DAGISEL_STRINGIZE_(X)
#define LOCAL_DAGISEL_STRINGIZE_(X) #X
static_assert(sizeof(LOCAL_DAGISEL_STRINGIZE(GET_DAGISEL_BODY)) > 1,
   "GET_DAGISEL_BODY is empty: it should be defined with the class name");
#undef LOCAL_DAGISEL_STRINGIZE_
#undef LOCAL_DAGISEL_STRINGIZE
#endif

#if !defined(GET_DAGISEL_DECL) && !defined(GET_DAGISEL_BODY)
#define DAGISEL_INLINE 1
#else
#define DAGISEL_INLINE 0
#endif

#if !DAGISEL_INLINE
#define DAGISEL_CLASS_COLONCOLON GET_DAGISEL_BODY ::
#else
#define DAGISEL_CLASS_COLONCOLON
#endif

#ifdef GET_DAGISEL_DECL
void SelectCode(SDNode *N);
#endif
#if defined(GET_DAGISEL_BODY) || DAGISEL_INLINE
void DAGISEL_CLASS_COLONCOLON SelectCode(SDNode *N)
{
  // Some target values are emitted as 2 bytes, TARGET_VAL handles
  // this.
  #define TARGET_VAL(X) X & 255, unsigned(X) >> 8
  static const unsigned char MatcherTable[] = {
/*     0*/ OPC_SwitchOpcode /*48 cases */, 41|128,7/*937*/, TARGET_VAL(ISD::LOAD),// ->942
/*     5*/  OPC_RecordMemRef,
/*     6*/  OPC_RecordNode, // #0 = 'ld' chained node
/*     7*/  OPC_Scope, 38|128,1/*166*/, /*->176*/ // 6 children in Scope
/*    10*/   OPC_MoveChild1,
/*    11*/   OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*    14*/   OPC_RecordChild0, // #1 = $rbase
/*    15*/   OPC_RecordChild1, // #2 = $ri
/*    16*/   OPC_CheckTypeI32,
/*    17*/   OPC_MoveParent,
/*    18*/   OPC_CheckPredicate6,  // Predicate_unindexedload
/*    19*/   OPC_SwitchType /*2 cases */, 125, MVT::i32,// ->147
/*    22*/    OPC_Scope, 19, /*->43*/ // 6 children in Scope
/*    24*/     OPC_CheckPredicate, 9, // Predicate_extload
/*    26*/     OPC_CheckPredicate3,  // Predicate_extloadi8
/*    27*/     OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*    28*/     OPC_EmitMergeInputChains1_0,
/*    29*/     OPC_EmitInteger32, 0, 
/*    31*/     OPC_EmitInteger32, 0, 
/*    33*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 107
               // Dst: (SZ_SHARED_LD_U8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*    43*/    /*Scope*/ 19, /*->63*/
/*    44*/     OPC_CheckPredicate, 10, // Predicate_zextload
/*    46*/     OPC_CheckPredicate3,  // Predicate_zextloadi8
/*    47*/     OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*    48*/     OPC_EmitMergeInputChains1_0,
/*    49*/     OPC_EmitInteger32, 0, 
/*    51*/     OPC_EmitInteger32, 0, 
/*    53*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 107
               // Dst: (SZ_SHARED_LD_U8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*    63*/    /*Scope*/ 19, /*->83*/
/*    64*/     OPC_CheckPredicate, 11, // Predicate_sextload
/*    66*/     OPC_CheckPredicate3,  // Predicate_sextloadi8
/*    67*/     OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*    68*/     OPC_EmitMergeInputChains1_0,
/*    69*/     OPC_EmitInteger32, 0, 
/*    71*/     OPC_EmitInteger32, 0, 
/*    73*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_S8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 107
               // Dst: (SZ_SHARED_LD_S8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*    83*/    /*Scope*/ 20, /*->104*/
/*    84*/     OPC_CheckPredicate, 9, // Predicate_extload
/*    86*/     OPC_CheckPredicate, 13, // Predicate_extloadi16
/*    88*/     OPC_CheckPredicate0,  // Predicate_anonymous_7398
/*    89*/     OPC_EmitMergeInputChains1_0,
/*    90*/     OPC_EmitInteger32, 0, 
/*    92*/     OPC_EmitInteger32, 0, 
/*    94*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U16), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>><<P:Predicate_anonymous_7398>> - Complexity = 107
               // Dst: (SZ_SHARED_LD_U16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   104*/    /*Scope*/ 20, /*->125*/
/*   105*/     OPC_CheckPredicate, 10, // Predicate_zextload
/*   107*/     OPC_CheckPredicate, 13, // Predicate_zextloadi16
/*   109*/     OPC_CheckPredicate0,  // Predicate_anonymous_7399
/*   110*/     OPC_EmitMergeInputChains1_0,
/*   111*/     OPC_EmitInteger32, 0, 
/*   113*/     OPC_EmitInteger32, 0, 
/*   115*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U16), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>><<P:Predicate_anonymous_7399>> - Complexity = 107
               // Dst: (SZ_SHARED_LD_U16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   125*/    /*Scope*/ 20, /*->146*/
/*   126*/     OPC_CheckPredicate, 11, // Predicate_sextload
/*   128*/     OPC_CheckPredicate, 13, // Predicate_sextloadi16
/*   130*/     OPC_CheckPredicate0,  // Predicate_anonymous_7405
/*   131*/     OPC_EmitMergeInputChains1_0,
/*   132*/     OPC_EmitInteger32, 0, 
/*   134*/     OPC_EmitInteger32, 0, 
/*   136*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_S16), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_anonymous_7405>> - Complexity = 107
               // Dst: (SZ_SHARED_LD_S16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   146*/    0, /*End of Scope*/
/*   147*/   /*SwitchType*/ 26, MVT::i16,// ->175
/*   149*/    OPC_CheckPredicate4,  // Predicate_load
/*   150*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   151*/    OPC_EmitMergeInputChains1_0,
/*   152*/    OPC_EmitInteger32, 0, 
/*   154*/    OPC_EmitInteger32, 0, 
/*   156*/    OPC_EmitNode1, TARGET_VAL(CCV::SZ_SHARED_LD_U16), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 4/*#Ops*/, 1, 2, 3, 4,  // Results = #5
/*   166*/    OPC_EmitInteger32, 0, 
/*   168*/    OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                  MVT::i16, 2/*#Ops*/, 5, 6, 
              // Src: (ld:{ *:[i16] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 107
              // Dst: (PSEUDO_TRUNC16:{ *:[i16] } (SZ_SHARED_LD_U16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] }), 0:{ *:[i32] })
/*   175*/   0, // EndSwitchType
/*   176*/  /*Scope*/ 89|128,1/*217*/, /*->395*/
/*   178*/   OPC_RecordChild1, // #1 = $rbase
/*   179*/   OPC_CheckChild1TypeI32,
/*   180*/   OPC_CheckPredicate6,  // Predicate_unindexedload
/*   181*/   OPC_SwitchType /*2 cases */, 45|128,1/*173*/, MVT::i32,// ->358
/*   185*/    OPC_Scope, 27, /*->214*/ // 6 children in Scope
/*   187*/     OPC_CheckPredicate, 9, // Predicate_extload
/*   189*/     OPC_CheckPredicate3,  // Predicate_extloadi8
/*   190*/     OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*   191*/     OPC_EmitMergeInputChains1_0,
/*   192*/     OPC_EmitInteger32, 0, 
/*   194*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*   200*/     OPC_EmitInteger32, 0, 
/*   202*/     OPC_EmitInteger32, 0, 
/*   204*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 3, 4, 5, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 104
               // Dst: (SZ_SHARED_LD_U8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*   214*/    /*Scope*/ 27, /*->242*/
/*   215*/     OPC_CheckPredicate, 10, // Predicate_zextload
/*   217*/     OPC_CheckPredicate3,  // Predicate_zextloadi8
/*   218*/     OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*   219*/     OPC_EmitMergeInputChains1_0,
/*   220*/     OPC_EmitInteger32, 0, 
/*   222*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*   228*/     OPC_EmitInteger32, 0, 
/*   230*/     OPC_EmitInteger32, 0, 
/*   232*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 3, 4, 5, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 104
               // Dst: (SZ_SHARED_LD_U8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*   242*/    /*Scope*/ 27, /*->270*/
/*   243*/     OPC_CheckPredicate, 11, // Predicate_sextload
/*   245*/     OPC_CheckPredicate3,  // Predicate_sextloadi8
/*   246*/     OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*   247*/     OPC_EmitMergeInputChains1_0,
/*   248*/     OPC_EmitInteger32, 0, 
/*   250*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*   256*/     OPC_EmitInteger32, 0, 
/*   258*/     OPC_EmitInteger32, 0, 
/*   260*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_S8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 3, 4, 5, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 104
               // Dst: (SZ_SHARED_LD_S8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*   270*/    /*Scope*/ 28, /*->299*/
/*   271*/     OPC_CheckPredicate, 9, // Predicate_extload
/*   273*/     OPC_CheckPredicate, 13, // Predicate_extloadi16
/*   275*/     OPC_CheckPredicate0,  // Predicate_anonymous_7398
/*   276*/     OPC_EmitMergeInputChains1_0,
/*   277*/     OPC_EmitInteger32, 0, 
/*   279*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*   285*/     OPC_EmitInteger32, 0, 
/*   287*/     OPC_EmitInteger32, 0, 
/*   289*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U16), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 3, 4, 5, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>><<P:Predicate_anonymous_7398>> - Complexity = 104
               // Dst: (SZ_SHARED_LD_U16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*   299*/    /*Scope*/ 28, /*->328*/
/*   300*/     OPC_CheckPredicate, 10, // Predicate_zextload
/*   302*/     OPC_CheckPredicate, 13, // Predicate_zextloadi16
/*   304*/     OPC_CheckPredicate0,  // Predicate_anonymous_7399
/*   305*/     OPC_EmitMergeInputChains1_0,
/*   306*/     OPC_EmitInteger32, 0, 
/*   308*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*   314*/     OPC_EmitInteger32, 0, 
/*   316*/     OPC_EmitInteger32, 0, 
/*   318*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_U16), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 3, 4, 5, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>><<P:Predicate_anonymous_7399>> - Complexity = 104
               // Dst: (SZ_SHARED_LD_U16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*   328*/    /*Scope*/ 28, /*->357*/
/*   329*/     OPC_CheckPredicate, 11, // Predicate_sextload
/*   331*/     OPC_CheckPredicate, 13, // Predicate_sextloadi16
/*   333*/     OPC_CheckPredicate0,  // Predicate_anonymous_7405
/*   334*/     OPC_EmitMergeInputChains1_0,
/*   335*/     OPC_EmitInteger32, 0, 
/*   337*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*   343*/     OPC_EmitInteger32, 0, 
/*   345*/     OPC_EmitInteger32, 0, 
/*   347*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::SZ_SHARED_LD_S16), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 3, 4, 5, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_anonymous_7405>> - Complexity = 104
               // Dst: (SZ_SHARED_LD_S16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*   357*/    0, /*End of Scope*/
/*   358*/   /*SwitchType*/ 34, MVT::i16,// ->394
/*   360*/    OPC_CheckPredicate4,  // Predicate_load
/*   361*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   362*/    OPC_EmitMergeInputChains1_0,
/*   363*/    OPC_EmitInteger32, 0, 
/*   365*/    OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                  MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*   371*/    OPC_EmitInteger32, 0, 
/*   373*/    OPC_EmitInteger32, 0, 
/*   375*/    OPC_EmitNode1, TARGET_VAL(CCV::SZ_SHARED_LD_U16), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 4/*#Ops*/, 1, 3, 4, 5,  // Results = #6
/*   385*/    OPC_EmitInteger32, 0, 
/*   387*/    OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                  MVT::i16, 2/*#Ops*/, 6, 7, 
              // Src: (ld:{ *:[i16] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 104
              // Dst: (PSEUDO_TRUNC16:{ *:[i16] } (SZ_SHARED_LD_U16:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] }), 0:{ *:[i32] })
/*   394*/   0, // EndSwitchType
/*   395*/  /*Scope*/ 40|128,2/*296*/, /*->693*/
/*   397*/   OPC_MoveChild1,
/*   398*/   OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   401*/   OPC_Scope, 31, /*->434*/ // 3 children in Scope
/*   403*/    OPC_RecordChild0, // #1 = $rbase
/*   404*/    OPC_MoveChild1,
/*   405*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   408*/    OPC_RecordChild0, // #2 = $ri
/*   409*/    OPC_CheckChild1Integer, 4, 
/*   411*/    OPC_CheckChild1TypeI32,
/*   412*/    OPC_MoveParent,
/*   413*/    OPC_CheckTypeI32,
/*   414*/    OPC_MoveParent,
/*   415*/    OPC_CheckPredicate6,  // Predicate_unindexedload
/*   416*/    OPC_CheckPredicate4,  // Predicate_load
/*   417*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   418*/    OPC_CheckTypeI32,
/*   419*/    OPC_EmitMergeInputChains1_0,
/*   420*/    OPC_EmitInteger32, 2, 
/*   422*/    OPC_EmitInteger32, 0, 
/*   424*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   434*/   /*Scope*/ 31, /*->466*/
/*   435*/    OPC_MoveChild0,
/*   436*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   439*/    OPC_RecordChild0, // #1 = $ri
/*   440*/    OPC_CheckChild1Integer, 4, 
/*   442*/    OPC_CheckChild1TypeI32,
/*   443*/    OPC_MoveParent,
/*   444*/    OPC_RecordChild1, // #2 = $rbase
/*   445*/    OPC_CheckTypeI32,
/*   446*/    OPC_MoveParent,
/*   447*/    OPC_CheckPredicate6,  // Predicate_unindexedload
/*   448*/    OPC_CheckPredicate4,  // Predicate_load
/*   449*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   450*/    OPC_CheckTypeI32,
/*   451*/    OPC_EmitMergeInputChains1_0,
/*   452*/    OPC_EmitInteger32, 2, 
/*   454*/    OPC_EmitInteger32, 0, 
/*   456*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 4/*#Ops*/, 2, 1, 3, 4, 
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   466*/   /*Scope*/ 96|128,1/*224*/, /*->692*/
/*   468*/    OPC_RecordChild0, // #1 = $rbase
/*   469*/    OPC_RecordChild1, // #2 = $off
/*   470*/    OPC_Scope, 104, /*->576*/ // 2 children in Scope
/*   472*/     OPC_MoveChild1,
/*   473*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   476*/     OPC_MoveParent,
/*   477*/     OPC_CheckTypeI32,
/*   478*/     OPC_MoveParent,
/*   479*/     OPC_CheckPredicate6,  // Predicate_unindexedload
/*   480*/     OPC_SwitchType /*2 cases */, 78, MVT::i32,// ->561
/*   483*/      OPC_Scope, 12, /*->497*/ // 4 children in Scope
/*   485*/       OPC_CheckPredicate4,  // Predicate_load
/*   486*/       OPC_CheckPredicate0,  // Predicate_ld_shared
/*   487*/       OPC_EmitMergeInputChains1_0,
/*   488*/       OPC_EmitConvertToTarget2,
/*   489*/       OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
                 // Dst: (LD_SHARED:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   497*/      /*Scope*/ 14, /*->512*/
/*   498*/       OPC_CheckPredicate, 9, // Predicate_extload
/*   500*/       OPC_CheckPredicate3,  // Predicate_extloadi8
/*   501*/       OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*   502*/       OPC_EmitMergeInputChains1_0,
/*   503*/       OPC_EmitConvertToTarget2,
/*   504*/       OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 10
                 // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   512*/      /*Scope*/ 14, /*->527*/
/*   513*/       OPC_CheckPredicate, 10, // Predicate_zextload
/*   515*/       OPC_CheckPredicate3,  // Predicate_zextloadi8
/*   516*/       OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*   517*/       OPC_EmitMergeInputChains1_0,
/*   518*/       OPC_EmitConvertToTarget2,
/*   519*/       OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 10
                 // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   527*/      /*Scope*/ 32, /*->560*/
/*   528*/       OPC_CheckPredicate, 11, // Predicate_sextload
/*   530*/       OPC_CheckPredicate3,  // Predicate_sextloadi8
/*   531*/       OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*   532*/       OPC_EmitMergeInputChains1_0,
/*   533*/       OPC_EmitConvertToTarget2,
/*   534*/       OPC_EmitNode1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*   542*/       OPC_EmitInteger32, 48, 
/*   544*/       OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                     MVT::i32, 2/*#Ops*/, 4, 5,  // Results = #6
/*   551*/       OPC_EmitInteger32, 48, 
/*   553*/       OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::SRAI),
                     MVT::i32, 2/*#Ops*/, 6, 7, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 10
                 // Dst: (SRAI:{ *:[i32] } (SHLI:{ *:[i32] } (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off), 24:{ *:[i32] }), 24:{ *:[i32] })
/*   560*/      0, /*End of Scope*/
/*   561*/     /*SwitchType*/ 12, MVT::i16,// ->575
/*   563*/      OPC_CheckPredicate4,  // Predicate_load
/*   564*/      OPC_CheckPredicate0,  // Predicate_ld_shared
/*   565*/      OPC_EmitMergeInputChains1_0,
/*   566*/      OPC_EmitConvertToTarget2,
/*   567*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i16, 2/*#Ops*/, 1, 3, 
                // Src: (ld:{ *:[i16] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
                // Dst: (LD_SHARED_W16:{ *:[i16] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   575*/     0, // EndSwitchType
/*   576*/    /*Scope*/ 114, /*->691*/
/*   577*/     OPC_CheckTypeI32,
/*   578*/     OPC_MoveParent,
/*   579*/     OPC_CheckPredicate6,  // Predicate_unindexedload
/*   580*/     OPC_CheckTypeI32,
/*   581*/     OPC_Scope, 17, /*->600*/ // 4 children in Scope
/*   583*/      OPC_CheckPredicate4,  // Predicate_load
/*   584*/      OPC_CheckPredicate0,  // Predicate_ld_shared
/*   585*/      OPC_EmitMergeInputChains1_0,
/*   586*/      OPC_EmitInteger32, 0, 
/*   588*/      OPC_EmitInteger32, 0, 
/*   590*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 7
                // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   600*/     /*Scope*/ 23, /*->624*/
/*   601*/      OPC_CheckPredicate, 9, // Predicate_extload
/*   603*/      OPC_CheckPredicate3,  // Predicate_extloadi8
/*   604*/      OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*   605*/      OPC_EmitMergeInputChains1_0,
/*   606*/      OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                    MVT::i32, 3/*#Ops*/, 1, 2, 1,  // Results = #3
/*   614*/      OPC_EmitInteger32, 0, 
/*   616*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 2/*#Ops*/, 3, 4, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 7
                // Dst: (LD_SHARED_W8:{ *:[i32] } (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*   624*/     /*Scope*/ 23, /*->648*/
/*   625*/      OPC_CheckPredicate, 10, // Predicate_zextload
/*   627*/      OPC_CheckPredicate3,  // Predicate_zextloadi8
/*   628*/      OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*   629*/      OPC_EmitMergeInputChains1_0,
/*   630*/      OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                    MVT::i32, 3/*#Ops*/, 1, 2, 1,  // Results = #3
/*   638*/      OPC_EmitInteger32, 0, 
/*   640*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 2/*#Ops*/, 3, 4, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 7
                // Dst: (LD_SHARED_W8:{ *:[i32] } (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*   648*/     /*Scope*/ 41, /*->690*/
/*   649*/      OPC_CheckPredicate, 11, // Predicate_sextload
/*   651*/      OPC_CheckPredicate3,  // Predicate_sextloadi8
/*   652*/      OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*   653*/      OPC_EmitMergeInputChains1_0,
/*   654*/      OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                    MVT::i32, 3/*#Ops*/, 1, 2, 1,  // Results = #3
/*   662*/      OPC_EmitInteger32, 0, 
/*   664*/      OPC_EmitNode1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*   672*/      OPC_EmitInteger32, 48, 
/*   674*/      OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                    MVT::i32, 2/*#Ops*/, 5, 6,  // Results = #7
/*   681*/      OPC_EmitInteger32, 48, 
/*   683*/      OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::SRAI),
                    MVT::i32, 2/*#Ops*/, 7, 8, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 7
                // Dst: (SRAI:{ *:[i32] } (SHLI:{ *:[i32] } (LD_SHARED_W8:{ *:[i32] } (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] }), 24:{ *:[i32] }), 24:{ *:[i32] })
/*   690*/     0, /*End of Scope*/
/*   691*/    0, /*End of Scope*/
/*   692*/   0, /*End of Scope*/
/*   693*/  /*Scope*/ 104, /*->798*/
/*   694*/   OPC_RecordChild1, // #1 = $rbase
/*   695*/   OPC_CheckChild1TypeI32,
/*   696*/   OPC_CheckPredicate6,  // Predicate_unindexedload
/*   697*/   OPC_SwitchType /*2 cases */, 82, MVT::i32,// ->782
/*   700*/    OPC_Scope, 13, /*->715*/ // 4 children in Scope
/*   702*/     OPC_CheckPredicate4,  // Predicate_load
/*   703*/     OPC_CheckPredicate0,  // Predicate_ld_shared
/*   704*/     OPC_EmitMergeInputChains1_0,
/*   705*/     OPC_EmitInteger32, 0, 
/*   707*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
               // Dst: (LD_SHARED:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   715*/    /*Scope*/ 15, /*->731*/
/*   716*/     OPC_CheckPredicate, 9, // Predicate_extload
/*   718*/     OPC_CheckPredicate3,  // Predicate_extloadi8
/*   719*/     OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*   720*/     OPC_EmitMergeInputChains1_0,
/*   721*/     OPC_EmitInteger32, 0, 
/*   723*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 4
               // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   731*/    /*Scope*/ 15, /*->747*/
/*   732*/     OPC_CheckPredicate, 10, // Predicate_zextload
/*   734*/     OPC_CheckPredicate3,  // Predicate_zextloadi8
/*   735*/     OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*   736*/     OPC_EmitMergeInputChains1_0,
/*   737*/     OPC_EmitInteger32, 0, 
/*   739*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 4
               // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   747*/    /*Scope*/ 33, /*->781*/
/*   748*/     OPC_CheckPredicate, 11, // Predicate_sextload
/*   750*/     OPC_CheckPredicate3,  // Predicate_sextloadi8
/*   751*/     OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*   752*/     OPC_EmitMergeInputChains1_0,
/*   753*/     OPC_EmitInteger32, 0, 
/*   755*/     OPC_EmitNode1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*   763*/     OPC_EmitInteger32, 48, 
/*   765*/     OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                   MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*   772*/     OPC_EmitInteger32, 48, 
/*   774*/     OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::SRAI),
                   MVT::i32, 2/*#Ops*/, 5, 6, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 4
               // Dst: (SRAI:{ *:[i32] } (SHLI:{ *:[i32] } (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] }), 24:{ *:[i32] }), 24:{ *:[i32] })
/*   781*/    0, /*End of Scope*/
/*   782*/   /*SwitchType*/ 13, MVT::i16,// ->797
/*   784*/    OPC_CheckPredicate4,  // Predicate_load
/*   785*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   786*/    OPC_EmitMergeInputChains1_0,
/*   787*/    OPC_EmitInteger32, 0, 
/*   789*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i16, 2/*#Ops*/, 1, 2, 
              // Src: (ld:{ *:[i16] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
              // Dst: (LD_SHARED_W16:{ *:[i16] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   797*/   0, // EndSwitchType
/*   798*/  /*Scope*/ 123, /*->922*/
/*   799*/   OPC_MoveChild1,
/*   800*/   OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   803*/   OPC_Scope, 32, /*->837*/ // 3 children in Scope
/*   805*/    OPC_RecordChild0, // #1 = $rbase
/*   806*/    OPC_MoveChild1,
/*   807*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   810*/    OPC_RecordChild0, // #2 = $ri
/*   811*/    OPC_CheckChild1Integer, 4, 
/*   813*/    OPC_CheckChild1TypeI32,
/*   814*/    OPC_MoveParent,
/*   815*/    OPC_CheckTypeI32,
/*   816*/    OPC_MoveParent,
/*   817*/    OPC_CheckPredicate6,  // Predicate_unindexedload
/*   818*/    OPC_CheckPredicate4,  // Predicate_load
/*   819*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   820*/    OPC_CheckType, MVT::f32,
/*   822*/    OPC_EmitMergeInputChains1_0,
/*   823*/    OPC_EmitInteger32, 2, 
/*   825*/    OPC_EmitInteger32, 0, 
/*   827*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::f32, 4/*#Ops*/, 1, 2, 3, 4, 
              // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   837*/   /*Scope*/ 32, /*->870*/
/*   838*/    OPC_MoveChild0,
/*   839*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   842*/    OPC_RecordChild0, // #1 = $ri
/*   843*/    OPC_CheckChild1Integer, 4, 
/*   845*/    OPC_CheckChild1TypeI32,
/*   846*/    OPC_MoveParent,
/*   847*/    OPC_RecordChild1, // #2 = $rbase
/*   848*/    OPC_CheckTypeI32,
/*   849*/    OPC_MoveParent,
/*   850*/    OPC_CheckPredicate6,  // Predicate_unindexedload
/*   851*/    OPC_CheckPredicate4,  // Predicate_load
/*   852*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   853*/    OPC_CheckType, MVT::f32,
/*   855*/    OPC_EmitMergeInputChains1_0,
/*   856*/    OPC_EmitInteger32, 2, 
/*   858*/    OPC_EmitInteger32, 0, 
/*   860*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::f32, 4/*#Ops*/, 2, 1, 3, 4, 
              // Src: (ld:{ *:[f32] } (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   870*/   /*Scope*/ 50, /*->921*/
/*   871*/    OPC_RecordChild0, // #1 = $rbase
/*   872*/    OPC_RecordChild1, // #2 = $off
/*   873*/    OPC_Scope, 22, /*->897*/ // 2 children in Scope
/*   875*/     OPC_MoveChild1,
/*   876*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   879*/     OPC_MoveParent,
/*   880*/     OPC_CheckTypeI32,
/*   881*/     OPC_MoveParent,
/*   882*/     OPC_CheckPredicate6,  // Predicate_unindexedload
/*   883*/     OPC_CheckPredicate4,  // Predicate_load
/*   884*/     OPC_CheckPredicate0,  // Predicate_ld_shared
/*   885*/     OPC_CheckType, MVT::f32,
/*   887*/     OPC_EmitMergeInputChains1_0,
/*   888*/     OPC_EmitConvertToTarget2,
/*   889*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::f32, 2/*#Ops*/, 1, 3, 
               // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
               // Dst: (LD_SHARED:{ *:[f32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   897*/    /*Scope*/ 22, /*->920*/
/*   898*/     OPC_CheckTypeI32,
/*   899*/     OPC_MoveParent,
/*   900*/     OPC_CheckPredicate6,  // Predicate_unindexedload
/*   901*/     OPC_CheckPredicate4,  // Predicate_load
/*   902*/     OPC_CheckPredicate0,  // Predicate_ld_shared
/*   903*/     OPC_CheckType, MVT::f32,
/*   905*/     OPC_EmitMergeInputChains1_0,
/*   906*/     OPC_EmitInteger32, 0, 
/*   908*/     OPC_EmitInteger32, 0, 
/*   910*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::f32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 7
               // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   920*/    0, /*End of Scope*/
/*   921*/   0, /*End of Scope*/
/*   922*/  /*Scope*/ 18, /*->941*/
/*   923*/   OPC_RecordChild1, // #1 = $rbase
/*   924*/   OPC_CheckChild1TypeI32,
/*   925*/   OPC_CheckPredicate6,  // Predicate_unindexedload
/*   926*/   OPC_CheckPredicate4,  // Predicate_load
/*   927*/   OPC_CheckPredicate0,  // Predicate_ld_shared
/*   928*/   OPC_CheckType, MVT::f32,
/*   930*/   OPC_EmitMergeInputChains1_0,
/*   931*/   OPC_EmitInteger32, 0, 
/*   933*/   OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                 MVT::f32, 2/*#Ops*/, 1, 2, 
             // Src: (ld:{ *:[f32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
             // Dst: (LD_SHARED:{ *:[f32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   941*/  0, /*End of Scope*/
/*   942*/ /*SwitchOpcode*/ 8|128,6/*776*/, TARGET_VAL(ISD::STORE),// ->1722
/*   946*/  OPC_RecordMemRef,
/*   947*/  OPC_RecordNode, // #0 = 'st' chained node
/*   948*/  OPC_RecordChild1, // #1 = $v
/*   949*/  OPC_Scope, 84|128,2/*340*/, /*->1292*/ // 3 children in Scope
/*   952*/   OPC_CheckChild1TypeI32,
/*   953*/   OPC_Scope, 50, /*->1005*/ // 4 children in Scope
/*   955*/    OPC_MoveChild2,
/*   956*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   959*/    OPC_RecordChild0, // #2 = $rbase
/*   960*/    OPC_RecordChild1, // #3 = $ri
/*   961*/    OPC_CheckTypeI32,
/*   962*/    OPC_MoveParent,
/*   963*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   964*/    OPC_CheckPredicate7,  // Predicate_truncstore
/*   965*/    OPC_Scope, 18, /*->985*/ // 2 children in Scope
/*   967*/     OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*   969*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*   970*/     OPC_EmitMergeInputChains1_0,
/*   971*/     OPC_EmitInteger32, 0, 
/*   973*/     OPC_EmitInteger32, 0, 
/*   975*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_8), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st GPR:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 107
               // Dst: (SZ_SHARED_ST_8 GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   985*/    /*Scope*/ 18, /*->1004*/
/*   986*/     OPC_CheckPredicate, 16, // Predicate_truncstorei16
/*   988*/     OPC_CheckPredicate1,  // Predicate_anonymous_7408
/*   989*/     OPC_EmitMergeInputChains1_0,
/*   990*/     OPC_EmitInteger32, 0, 
/*   992*/     OPC_EmitInteger32, 0, 
/*   994*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_16), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st GPR:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_anonymous_7408>> - Complexity = 107
               // Dst: (SZ_SHARED_ST_16 GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1004*/    0, /*End of Scope*/
/*  1005*/   /*Scope*/ 60, /*->1066*/
/*  1006*/    OPC_RecordChild2, // #2 = $rbase
/*  1007*/    OPC_CheckChild2TypeI32,
/*  1008*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1009*/    OPC_CheckPredicate7,  // Predicate_truncstore
/*  1010*/    OPC_Scope, 26, /*->1038*/ // 2 children in Scope
/*  1012*/     OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1014*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1015*/     OPC_EmitMergeInputChains1_0,
/*  1016*/     OPC_EmitInteger32, 0, 
/*  1018*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*  1024*/     OPC_EmitInteger32, 0, 
/*  1026*/     OPC_EmitInteger32, 0, 
/*  1028*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_8), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 4, 5, 6, 
               // Src: (st GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 104
               // Dst: (SZ_SHARED_ST_8 GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1038*/    /*Scope*/ 26, /*->1065*/
/*  1039*/     OPC_CheckPredicate, 16, // Predicate_truncstorei16
/*  1041*/     OPC_CheckPredicate1,  // Predicate_anonymous_7408
/*  1042*/     OPC_EmitMergeInputChains1_0,
/*  1043*/     OPC_EmitInteger32, 0, 
/*  1045*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*  1051*/     OPC_EmitInteger32, 0, 
/*  1053*/     OPC_EmitInteger32, 0, 
/*  1055*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_16), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 4, 5, 6, 
               // Src: (st GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_anonymous_7408>> - Complexity = 104
               // Dst: (SZ_SHARED_ST_16 GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1065*/    0, /*End of Scope*/
/*  1066*/   /*Scope*/ 50|128,1/*178*/, /*->1246*/
/*  1068*/    OPC_MoveChild2,
/*  1069*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*  1072*/    OPC_Scope, 30, /*->1104*/ // 3 children in Scope
/*  1074*/     OPC_RecordChild0, // #2 = $rbase
/*  1075*/     OPC_MoveChild1,
/*  1076*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*  1079*/     OPC_RecordChild0, // #3 = $ri
/*  1080*/     OPC_CheckChild1Integer, 4, 
/*  1082*/     OPC_CheckChild1TypeI32,
/*  1083*/     OPC_MoveParent,
/*  1084*/     OPC_CheckTypeI32,
/*  1085*/     OPC_MoveParent,
/*  1086*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1087*/     OPC_CheckPredicate5,  // Predicate_store
/*  1088*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1089*/     OPC_EmitMergeInputChains1_0,
/*  1090*/     OPC_EmitInteger32, 2, 
/*  1092*/     OPC_EmitInteger32, 0, 
/*  1094*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*  1104*/    /*Scope*/ 30, /*->1135*/
/*  1105*/     OPC_MoveChild0,
/*  1106*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*  1109*/     OPC_RecordChild0, // #2 = $ri
/*  1110*/     OPC_CheckChild1Integer, 4, 
/*  1112*/     OPC_CheckChild1TypeI32,
/*  1113*/     OPC_MoveParent,
/*  1114*/     OPC_RecordChild1, // #3 = $rbase
/*  1115*/     OPC_CheckTypeI32,
/*  1116*/     OPC_MoveParent,
/*  1117*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1118*/     OPC_CheckPredicate5,  // Predicate_store
/*  1119*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1120*/     OPC_EmitMergeInputChains1_0,
/*  1121*/     OPC_EmitInteger32, 2, 
/*  1123*/     OPC_EmitInteger32, 0, 
/*  1125*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 3, 2, 4, 5, 
               // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*  1135*/    /*Scope*/ 109, /*->1245*/
/*  1136*/     OPC_RecordChild0, // #2 = $rbase
/*  1137*/     OPC_RecordChild1, // #3 = $off
/*  1138*/     OPC_Scope, 47, /*->1187*/ // 2 children in Scope
/*  1140*/      OPC_MoveChild1,
/*  1141*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1144*/      OPC_MoveParent,
/*  1145*/      OPC_CheckTypeI32,
/*  1146*/      OPC_MoveParent,
/*  1147*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1148*/      OPC_Scope, 12, /*->1162*/ // 2 children in Scope
/*  1150*/       OPC_CheckPredicate5,  // Predicate_store
/*  1151*/       OPC_CheckPredicate1,  // Predicate_st_shared
/*  1152*/       OPC_EmitMergeInputChains1_0,
/*  1153*/       OPC_EmitConvertToTarget3,
/*  1154*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                     3/*#Ops*/, 1, 2, 4, 
                 // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                 // Dst: (ST_SHARED GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1162*/      /*Scope*/ 23, /*->1186*/
/*  1163*/       OPC_CheckPredicate7,  // Predicate_truncstore
/*  1164*/       OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1166*/       OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1167*/       OPC_EmitMergeInputChains1_0,
/*  1168*/       OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1170*/       OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                     MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1177*/       OPC_EmitConvertToTarget3,
/*  1178*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     3/*#Ops*/, 5, 2, 6, 
                 // Src: (st GPR:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 10
                 // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR:{ *:[i32] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1186*/      0, /*End of Scope*/
/*  1187*/     /*Scope*/ 56, /*->1244*/
/*  1188*/      OPC_CheckTypeI32,
/*  1189*/      OPC_MoveParent,
/*  1190*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1191*/      OPC_Scope, 17, /*->1210*/ // 2 children in Scope
/*  1193*/       OPC_CheckPredicate5,  // Predicate_store
/*  1194*/       OPC_CheckPredicate1,  // Predicate_st_shared
/*  1195*/       OPC_EmitMergeInputChains1_0,
/*  1196*/       OPC_EmitInteger32, 0, 
/*  1198*/       OPC_EmitInteger32, 0, 
/*  1200*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                     5/*#Ops*/, 1, 2, 3, 4, 5, 
                 // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 7
                 // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1210*/      /*Scope*/ 32, /*->1243*/
/*  1211*/       OPC_CheckPredicate7,  // Predicate_truncstore
/*  1212*/       OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1214*/       OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1215*/       OPC_EmitMergeInputChains1_0,
/*  1216*/       OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1218*/       OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                     MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1225*/       OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                     MVT::i32, 3/*#Ops*/, 2, 3, 2,  // Results = #6
/*  1233*/       OPC_EmitInteger32, 0, 
/*  1235*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     3/*#Ops*/, 5, 6, 7, 
                 // Src: (st GPR:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 7
                 // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR:{ *:[i32] }:$v, GPR8:{ *:[i32] }), (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*  1243*/      0, /*End of Scope*/
/*  1244*/     0, /*End of Scope*/
/*  1245*/    0, /*End of Scope*/
/*  1246*/   /*Scope*/ 44, /*->1291*/
/*  1247*/    OPC_RecordChild2, // #2 = $rbase
/*  1248*/    OPC_CheckChild2TypeI32,
/*  1249*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1250*/    OPC_Scope, 13, /*->1265*/ // 2 children in Scope
/*  1252*/     OPC_CheckPredicate5,  // Predicate_store
/*  1253*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1254*/     OPC_EmitMergeInputChains1_0,
/*  1255*/     OPC_EmitInteger32, 0, 
/*  1257*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 1, 2, 3, 
               // Src: (st i32:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
               // Dst: (ST_SHARED GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1265*/    /*Scope*/ 24, /*->1290*/
/*  1266*/     OPC_CheckPredicate7,  // Predicate_truncstore
/*  1267*/     OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1269*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1270*/     OPC_EmitMergeInputChains1_0,
/*  1271*/     OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1273*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*  1280*/     OPC_EmitInteger32, 0, 
/*  1282*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 4, 2, 5, 
               // Src: (st GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 4
               // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR:{ *:[i32] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1290*/    0, /*End of Scope*/
/*  1291*/   0, /*End of Scope*/
/*  1292*/  /*Scope*/ 32|128,2/*288*/, /*->1582*/
/*  1294*/   OPC_CheckChild1Type, MVT::i16,
/*  1296*/   OPC_Scope, 67, /*->1365*/ // 4 children in Scope
/*  1298*/    OPC_MoveChild2,
/*  1299*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*  1302*/    OPC_RecordChild0, // #2 = $rbase
/*  1303*/    OPC_RecordChild1, // #3 = $ri
/*  1304*/    OPC_CheckTypeI32,
/*  1305*/    OPC_MoveParent,
/*  1306*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1307*/    OPC_Scope, 28, /*->1337*/ // 2 children in Scope
/*  1309*/     OPC_CheckPredicate7,  // Predicate_truncstore
/*  1310*/     OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1312*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1313*/     OPC_EmitMergeInputChains1_0,
/*  1314*/     OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  1316*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1323*/     OPC_EmitInteger32, 0, 
/*  1325*/     OPC_EmitInteger32, 0, 
/*  1327*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_8), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 5, 2, 3, 6, 7, 
               // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 107
               // Dst: (SZ_SHARED_ST_8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1337*/    /*Scope*/ 26, /*->1364*/
/*  1338*/     OPC_CheckPredicate5,  // Predicate_store
/*  1339*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1340*/     OPC_EmitMergeInputChains1_0,
/*  1341*/     OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  1343*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1350*/     OPC_EmitInteger32, 0, 
/*  1352*/     OPC_EmitInteger32, 0, 
/*  1354*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_16), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 5, 2, 3, 6, 7, 
               // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 107
               // Dst: (SZ_SHARED_ST_16 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1364*/    0, /*End of Scope*/
/*  1365*/   /*Scope*/ 77, /*->1443*/
/*  1366*/    OPC_RecordChild2, // #2 = $rbase
/*  1367*/    OPC_CheckChild2TypeI32,
/*  1368*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1369*/    OPC_Scope, 36, /*->1407*/ // 2 children in Scope
/*  1371*/     OPC_CheckPredicate7,  // Predicate_truncstore
/*  1372*/     OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1374*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1375*/     OPC_EmitMergeInputChains1_0,
/*  1376*/     OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  1378*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*  1385*/     OPC_EmitInteger32, 0, 
/*  1387*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 5,  // Results = #6
/*  1393*/     OPC_EmitInteger32, 0, 
/*  1395*/     OPC_EmitInteger32, 0, 
/*  1397*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_8), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 4, 2, 6, 7, 8, 
               // Src: (st GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 104
               // Dst: (SZ_SHARED_ST_8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1407*/    /*Scope*/ 34, /*->1442*/
/*  1408*/     OPC_CheckPredicate5,  // Predicate_store
/*  1409*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1410*/     OPC_EmitMergeInputChains1_0,
/*  1411*/     OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  1413*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*  1420*/     OPC_EmitInteger32, 0, 
/*  1422*/     OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                   MVT::i32, 1/*#Ops*/, 5,  // Results = #6
/*  1428*/     OPC_EmitInteger32, 0, 
/*  1430*/     OPC_EmitInteger32, 0, 
/*  1432*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::SZ_SHARED_ST_16), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 4, 2, 6, 7, 8, 
               // Src: (st GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 104
               // Dst: (SZ_SHARED_ST_16 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, (MOVI:{ *:[i32] } 0:{ *:[i32] }), 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1442*/    0, /*End of Scope*/
/*  1443*/   /*Scope*/ 92, /*->1536*/
/*  1444*/    OPC_MoveChild2,
/*  1445*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*  1448*/    OPC_RecordChild0, // #2 = $rbase
/*  1449*/    OPC_RecordChild1, // #3 = $off
/*  1450*/    OPC_Scope, 47, /*->1499*/ // 2 children in Scope
/*  1452*/     OPC_MoveChild1,
/*  1453*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1456*/     OPC_MoveParent,
/*  1457*/     OPC_CheckTypeI32,
/*  1458*/     OPC_MoveParent,
/*  1459*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1460*/     OPC_Scope, 12, /*->1474*/ // 2 children in Scope
/*  1462*/      OPC_CheckPredicate5,  // Predicate_store
/*  1463*/      OPC_CheckPredicate1,  // Predicate_st_shared
/*  1464*/      OPC_EmitMergeInputChains1_0,
/*  1465*/      OPC_EmitConvertToTarget3,
/*  1466*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 1, 2, 4, 
                // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                // Dst: (ST_SHARED_W16 GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1474*/     /*Scope*/ 23, /*->1498*/
/*  1475*/      OPC_CheckPredicate7,  // Predicate_truncstore
/*  1476*/      OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1478*/      OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1479*/      OPC_EmitMergeInputChains1_0,
/*  1480*/      OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1482*/      OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                    MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1489*/      OPC_EmitConvertToTarget3,
/*  1490*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 5, 2, 6, 
                // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 10
                // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1498*/     0, /*End of Scope*/
/*  1499*/    /*Scope*/ 35, /*->1535*/
/*  1500*/     OPC_CheckTypeI32,
/*  1501*/     OPC_MoveParent,
/*  1502*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1503*/     OPC_CheckPredicate7,  // Predicate_truncstore
/*  1504*/     OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1506*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1507*/     OPC_EmitMergeInputChains1_0,
/*  1508*/     OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1510*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1517*/     OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                   MVT::i32, 3/*#Ops*/, 2, 3, 2,  // Results = #6
/*  1525*/     OPC_EmitInteger32, 0, 
/*  1527*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 5, 6, 7, 
               // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 7
               // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR8:{ *:[i32] }), (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*  1535*/    0, /*End of Scope*/
/*  1536*/   /*Scope*/ 44, /*->1581*/
/*  1537*/    OPC_RecordChild2, // #2 = $rbase
/*  1538*/    OPC_CheckChild2TypeI32,
/*  1539*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1540*/    OPC_Scope, 13, /*->1555*/ // 2 children in Scope
/*  1542*/     OPC_CheckPredicate5,  // Predicate_store
/*  1543*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1544*/     OPC_EmitMergeInputChains1_0,
/*  1545*/     OPC_EmitInteger32, 0, 
/*  1547*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 1, 2, 3, 
               // Src: (st GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
               // Dst: (ST_SHARED_W16 GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1555*/    /*Scope*/ 24, /*->1580*/
/*  1556*/     OPC_CheckPredicate7,  // Predicate_truncstore
/*  1557*/     OPC_CheckPredicate, 8, // Predicate_truncstorei8
/*  1559*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1560*/     OPC_EmitMergeInputChains1_0,
/*  1561*/     OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1563*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*  1570*/     OPC_EmitInteger32, 0, 
/*  1572*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 4, 2, 5, 
               // Src: (st GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 4
               // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1580*/    0, /*End of Scope*/
/*  1581*/   0, /*End of Scope*/
/*  1582*/  /*Scope*/ 9|128,1/*137*/, /*->1721*/
/*  1584*/   OPC_CheckChild1Type, MVT::f32,
/*  1586*/   OPC_Scope, 115, /*->1703*/ // 2 children in Scope
/*  1588*/    OPC_MoveChild2,
/*  1589*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*  1592*/    OPC_Scope, 30, /*->1624*/ // 3 children in Scope
/*  1594*/     OPC_RecordChild0, // #2 = $rbase
/*  1595*/     OPC_MoveChild1,
/*  1596*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*  1599*/     OPC_RecordChild0, // #3 = $ri
/*  1600*/     OPC_CheckChild1Integer, 4, 
/*  1602*/     OPC_CheckChild1TypeI32,
/*  1603*/     OPC_MoveParent,
/*  1604*/     OPC_CheckTypeI32,
/*  1605*/     OPC_MoveParent,
/*  1606*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1607*/     OPC_CheckPredicate5,  // Predicate_store
/*  1608*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1609*/     OPC_EmitMergeInputChains1_0,
/*  1610*/     OPC_EmitInteger32, 2, 
/*  1612*/     OPC_EmitInteger32, 0, 
/*  1614*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*  1624*/    /*Scope*/ 30, /*->1655*/
/*  1625*/     OPC_MoveChild0,
/*  1626*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*  1629*/     OPC_RecordChild0, // #2 = $ri
/*  1630*/     OPC_CheckChild1Integer, 4, 
/*  1632*/     OPC_CheckChild1TypeI32,
/*  1633*/     OPC_MoveParent,
/*  1634*/     OPC_RecordChild1, // #3 = $rbase
/*  1635*/     OPC_CheckTypeI32,
/*  1636*/     OPC_MoveParent,
/*  1637*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1638*/     OPC_CheckPredicate5,  // Predicate_store
/*  1639*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1640*/     OPC_EmitMergeInputChains1_0,
/*  1641*/     OPC_EmitInteger32, 2, 
/*  1643*/     OPC_EmitInteger32, 0, 
/*  1645*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 3, 2, 4, 5, 
               // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*  1655*/    /*Scope*/ 46, /*->1702*/
/*  1656*/     OPC_RecordChild0, // #2 = $rbase
/*  1657*/     OPC_RecordChild1, // #3 = $off
/*  1658*/     OPC_Scope, 20, /*->1680*/ // 2 children in Scope
/*  1660*/      OPC_MoveChild1,
/*  1661*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1664*/      OPC_MoveParent,
/*  1665*/      OPC_CheckTypeI32,
/*  1666*/      OPC_MoveParent,
/*  1667*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1668*/      OPC_CheckPredicate5,  // Predicate_store
/*  1669*/      OPC_CheckPredicate1,  // Predicate_st_shared
/*  1670*/      OPC_EmitMergeInputChains1_0,
/*  1671*/      OPC_EmitConvertToTarget3,
/*  1672*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 1, 2, 4, 
                // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                // Dst: (ST_SHARED GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1680*/     /*Scope*/ 20, /*->1701*/
/*  1681*/      OPC_CheckTypeI32,
/*  1682*/      OPC_MoveParent,
/*  1683*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1684*/      OPC_CheckPredicate5,  // Predicate_store
/*  1685*/      OPC_CheckPredicate1,  // Predicate_st_shared
/*  1686*/      OPC_EmitMergeInputChains1_0,
/*  1687*/      OPC_EmitInteger32, 0, 
/*  1689*/      OPC_EmitInteger32, 0, 
/*  1691*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                    5/*#Ops*/, 1, 2, 3, 4, 5, 
                // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 7
                // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1701*/     0, /*End of Scope*/
/*  1702*/    0, /*End of Scope*/
/*  1703*/   /*Scope*/ 16, /*->1720*/
/*  1704*/    OPC_RecordChild2, // #2 = $rbase
/*  1705*/    OPC_CheckChild2TypeI32,
/*  1706*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1707*/    OPC_CheckPredicate5,  // Predicate_store
/*  1708*/    OPC_CheckPredicate1,  // Predicate_st_shared
/*  1709*/    OPC_EmitMergeInputChains1_0,
/*  1710*/    OPC_EmitInteger32, 0, 
/*  1712*/    OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                  3/*#Ops*/, 1, 2, 3, 
              // Src: (st f32:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
              // Dst: (ST_SHARED GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1720*/   0, /*End of Scope*/
/*  1721*/  0, /*End of Scope*/
/*  1722*/ /*SwitchOpcode*/ 116, TARGET_VAL(ISD::ADD),// ->1841
/*  1725*/  OPC_Scope, 50, /*->1777*/ // 3 children in Scope
/*  1727*/   OPC_RecordChild0, // #0 = $a
/*  1728*/   OPC_RecordChild1, // #1 = $i
/*  1729*/   OPC_MoveChild1,
/*  1730*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1733*/   OPC_Scope, 12, /*->1747*/ // 3 children in Scope
/*  1735*/    OPC_CheckPredicate, 12, // Predicate_simm13_imm
/*  1737*/    OPC_MoveParent,
/*  1738*/    OPC_CheckTypeI32,
/*  1739*/    OPC_EmitConvertToTarget1,
/*  1740*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 17
              // Dst: (ADDI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1747*/   /*Scope*/ 12, /*->1760*/
/*  1748*/    OPC_CheckPredicate, 17, // Predicate_uimm29_imm
/*  1750*/    OPC_MoveParent,
/*  1751*/    OPC_CheckTypeI32,
/*  1752*/    OPC_EmitConvertToTarget1,
/*  1753*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI48),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm29_imm>>:$i) - Complexity = 12
              // Dst: (ADDI48:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1760*/   /*Scope*/ 15, /*->1776*/
/*  1761*/    OPC_CheckPredicate, 12, // Predicate_simm13_imm16
/*  1763*/    OPC_MoveParent,
/*  1764*/    OPC_CheckType, MVT::i16,
/*  1766*/    OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*  1769*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI_W16),
                  MVT::i16, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i16] } GPR16:{ *:[i16] }:$a, (imm:{ *:[i16] })<<P:Predicate_simm13_imm16>>:$i) - Complexity = 7
              // Dst: (ADDI_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, (as_i32imm:{ *:[i32] } ?:{ *:[i16] }:$i))
/*  1776*/   0, /*End of Scope*/
/*  1777*/  /*Scope*/ 17, /*->1795*/
/*  1778*/   OPC_MoveChild0,
/*  1779*/   OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*  1782*/   OPC_RecordChild0, // #0 = $a
/*  1783*/   OPC_RecordChild1, // #1 = $b
/*  1784*/   OPC_MoveParent,
/*  1785*/   OPC_RecordChild1, // #2 = $c
/*  1786*/   OPC_CheckTypeI32,
/*  1787*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MADLO),
                 MVT::i32, 3/*#Ops*/, 0, 1, 2, 
             // Src: (add:{ *:[i32] } (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b), GPR:{ *:[i32] }:$c) - Complexity = 6
             // Dst: (MADLO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$c)
/*  1795*/  /*Scope*/ 44, /*->1840*/
/*  1796*/   OPC_RecordChild0, // #0 = $c
/*  1797*/   OPC_Scope, 16, /*->1815*/ // 2 children in Scope
/*  1799*/    OPC_MoveChild1,
/*  1800*/    OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*  1803*/    OPC_RecordChild0, // #1 = $a
/*  1804*/    OPC_RecordChild1, // #2 = $b
/*  1805*/    OPC_MoveParent,
/*  1806*/    OPC_CheckTypeI32,
/*  1807*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::MADLO),
                  MVT::i32, 3/*#Ops*/, 1, 2, 0, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$c, (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b)) - Complexity = 6
              // Dst: (MADLO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$c)
/*  1815*/   /*Scope*/ 23, /*->1839*/
/*  1816*/    OPC_RecordChild1, // #1 = $b
/*  1817*/    OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->1828
/*  1820*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADD),
                   MVT::i32, 3/*#Ops*/, 0, 1, 0, 
               // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
               // Dst: (ADD:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1828*/    /*SwitchType*/ 8, MVT::i16,// ->1838
/*  1830*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADD_W16),
                   MVT::i16, 3/*#Ops*/, 0, 1, 0, 
               // Src: (add:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
               // Dst: (ADD_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1838*/    0, // EndSwitchType
/*  1839*/   0, /*End of Scope*/
/*  1840*/  0, /*End of Scope*/
/*  1841*/ /*SwitchOpcode*/ 79, TARGET_VAL(ISD::Constant),// ->1923
/*  1844*/  OPC_Scope, 11, /*->1857*/ // 4 children in Scope
/*  1846*/   OPC_RecordNode, // #0 = $i
/*  1847*/   OPC_CheckPredicate, 18, // Predicate_uimm17_imm
/*  1849*/   OPC_CheckTypeI32,
/*  1850*/   OPC_EmitConvertToTarget0,
/*  1851*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                 MVT::i32, 1/*#Ops*/, 1, 
             // Src: (imm:{ *:[i32] })<<P:Predicate_uimm17_imm>>:$i - Complexity = 14
             // Dst: (MOVI:{ *:[i32] } (imm:{ *:[i32] }):$i)
/*  1857*/  /*Scope*/ 16, /*->1874*/
/*  1858*/   OPC_CheckInteger, 3, 
/*  1860*/   OPC_CheckType, MVT::i1,
/*  1862*/   OPC_EmitInteger32, 126|128,127|128,127|128,127|128,31/*8589934590*/, 
/*  1868*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                 MVT::i1, 1/*#Ops*/, 0, 
             // Src: -1:{ *:[i1] } - Complexity = 5
             // Dst: (PMOV_IMM:{ *:[i1] } 4294967295:{ *:[i32] })
/*  1874*/  /*Scope*/ 12, /*->1887*/
/*  1875*/   OPC_CheckInteger, 0, 
/*  1877*/   OPC_CheckType, MVT::i1,
/*  1879*/   OPC_EmitInteger32, 0, 
/*  1881*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                 MVT::i1, 1/*#Ops*/, 0, 
             // Src: 0:{ *:[i1] } - Complexity = 5
             // Dst: (PMOV_IMM:{ *:[i1] } 0:{ *:[i32] })
/*  1887*/  /*Scope*/ 34, /*->1922*/
/*  1888*/   OPC_RecordNode, // #0 = $i
/*  1889*/   OPC_SwitchType /*2 cases */, 9, MVT::i32,// ->1901
/*  1892*/    OPC_EmitNodeXForm, 1, 0, // imm_bits32
/*  1895*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                  MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:{ *:[i32] }):$i - Complexity = 3
              // Dst: (MOVI48:{ *:[i32] } (imm_bits32:{ *:[i32] } ?:{ *:[i32] }:$i))
/*  1901*/   /*SwitchType*/ 18, MVT::i16,// ->1921
/*  1903*/    OPC_EmitNodeXForm, 2, 0, // imm16_bits
/*  1906*/    OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                  MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*  1912*/    OPC_EmitInteger32, 0, 
/*  1914*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                  MVT::i16, 2/*#Ops*/, 2, 3, 
              // Src: (imm:{ *:[i16] }):$i - Complexity = 3
              // Dst: (PSEUDO_TRUNC16:{ *:[i16] } (MOVI:{ *:[i32] } (imm16_bits:{ *:[i32] } ?:{ *:[i16] }:$i)), 0:{ *:[i32] })
/*  1921*/   0, // EndSwitchType
/*  1922*/  0, /*End of Scope*/
/*  1923*/ /*SwitchOpcode*/ 111, TARGET_VAL(ISD::AND),// ->2037
/*  1926*/  OPC_Scope, 18, /*->1946*/ // 3 children in Scope
/*  1928*/   OPC_RecordChild0, // #0 = $a
/*  1929*/   OPC_MoveChild1,
/*  1930*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*  1933*/   OPC_RecordChild0, // #1 = $b
/*  1934*/   OPC_CheckChild1Integer, 3, 
/*  1936*/   OPC_MoveParent,
/*  1937*/   OPC_CheckTypeI32,
/*  1938*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] })) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1946*/  /*Scope*/ 18, /*->1965*/
/*  1947*/   OPC_MoveChild0,
/*  1948*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*  1951*/   OPC_RecordChild0, // #0 = $b
/*  1952*/   OPC_CheckChild1Integer, 3, 
/*  1954*/   OPC_MoveParent,
/*  1955*/   OPC_RecordChild1, // #1 = $a
/*  1956*/   OPC_CheckTypeI32,
/*  1957*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 1, 0, 1, 
             // Src: (and:{ *:[i32] } (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] }), GPR:{ *:[i32] }:$a) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1965*/  /*Scope*/ 70, /*->2036*/
/*  1966*/   OPC_RecordChild0, // #0 = $a
/*  1967*/   OPC_RecordChild1, // #1 = $i
/*  1968*/   OPC_Scope, 34, /*->2004*/ // 4 children in Scope
/*  1970*/    OPC_MoveChild1,
/*  1971*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1974*/    OPC_Scope, 14, /*->1990*/ // 2 children in Scope
/*  1976*/     OPC_CheckPredicate, 19, // Predicate_simm13_not_imm
/*  1978*/     OPC_MoveParent,
/*  1979*/     OPC_CheckTypeI32,
/*  1980*/     OPC_EmitNodeXForm, 3, 1, // imm_not
/*  1983*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDNI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_not_imm>>:$i) - Complexity = 7
               // Dst: (ANDNI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm_not:{ *:[i32] } ?:{ *:[i32] }:$i))
/*  1990*/    /*Scope*/ 12, /*->2003*/
/*  1991*/     OPC_CheckPredicate, 12, // Predicate_simm13_imm
/*  1993*/     OPC_MoveParent,
/*  1994*/     OPC_CheckTypeI32,
/*  1995*/     OPC_EmitConvertToTarget1,
/*  1996*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
               // Dst: (ANDI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2003*/    0, /*End of Scope*/
/*  2004*/   /*Scope*/ 9, /*->2014*/
/*  2005*/    OPC_CheckTypeI32,
/*  2006*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (AND:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2014*/   /*Scope*/ 9, /*->2024*/
/*  2015*/    OPC_CheckType, MVT::i1,
/*  2017*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PAND),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (and:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PAND:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  2024*/   /*Scope*/ 10, /*->2035*/
/*  2025*/    OPC_CheckType, MVT::i16,
/*  2027*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (AND_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  2035*/   0, /*End of Scope*/
/*  2036*/  0, /*End of Scope*/
/*  2037*/ /*SwitchOpcode*/ 20, TARGET_VAL(ISD::CALLSEQ_START),// ->2060
/*  2040*/  OPC_RecordNode, // #0 = 'callseq_start' chained node
/*  2041*/  OPC_RecordChild1, // #1 = $a
/*  2042*/  OPC_MoveChild1,
/*  2043*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  2046*/  OPC_MoveSibling2,
/*  2047*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  2050*/  OPC_RecordNode, // #2 = $b
/*  2051*/  OPC_MoveParent,
/*  2052*/  OPC_EmitMergeInputChains1_0,
/*  2053*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                2/*#Ops*/, 1, 2, 
            // Src: (callseq_start (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b) - Complexity = 9
            // Dst: (ADJCALLSTACKDOWN (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b)
/*  2060*/ /*SwitchOpcode*/ 21, TARGET_VAL(ISD::CALLSEQ_END),// ->2084
/*  2063*/  OPC_RecordNode, // #0 = 'callseq_end' chained node
/*  2064*/  OPC_CaptureGlueInput,
/*  2065*/  OPC_RecordChild1, // #1 = $a
/*  2066*/  OPC_MoveChild1,
/*  2067*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  2070*/  OPC_MoveSibling2,
/*  2071*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  2074*/  OPC_RecordNode, // #2 = $b
/*  2075*/  OPC_MoveParent,
/*  2076*/  OPC_EmitMergeInputChains1_0,
/*  2077*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b) - Complexity = 9
            // Dst: (ADJCALLSTACKUP (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b)
/*  2084*/ /*SwitchOpcode*/ 58, TARGET_VAL(ISD::SUB),// ->2145
/*  2087*/  OPC_Scope, 12, /*->2101*/ // 2 children in Scope
/*  2089*/   OPC_CheckChild0Integer, 0, 
/*  2091*/   OPC_RecordChild1, // #0 = $a
/*  2092*/   OPC_CheckTypeI32,
/*  2093*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::NEG),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (sub:{ *:[i32] } 0:{ *:[i32] }, GPR:{ *:[i32] }:$a) - Complexity = 8
             // Dst: (NEG:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2101*/  /*Scope*/ 42, /*->2144*/
/*  2102*/   OPC_RecordChild0, // #0 = $a
/*  2103*/   OPC_RecordChild1, // #1 = $i
/*  2104*/   OPC_Scope, 16, /*->2122*/ // 3 children in Scope
/*  2106*/    OPC_MoveChild1,
/*  2107*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  2110*/    OPC_CheckPredicate, 12, // Predicate_simm13_imm
/*  2112*/    OPC_MoveParent,
/*  2113*/    OPC_CheckTypeI32,
/*  2114*/    OPC_EmitConvertToTarget1,
/*  2115*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUBI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (SUBI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2122*/   /*Scope*/ 9, /*->2132*/
/*  2123*/    OPC_CheckTypeI32,
/*  2124*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (SUB:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2132*/   /*Scope*/ 10, /*->2143*/
/*  2133*/    OPC_CheckType, MVT::i16,
/*  2135*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (SUB_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  2143*/   0, /*End of Scope*/
/*  2144*/  0, /*End of Scope*/
/*  2145*/ /*SwitchOpcode*/ 65, TARGET_VAL(ISD::XOR),// ->2213
/*  2148*/  OPC_RecordChild0, // #0 = $a
/*  2149*/  OPC_Scope, 9, /*->2160*/ // 2 children in Scope
/*  2151*/   OPC_CheckChild1Integer, 3, 
/*  2153*/   OPC_CheckTypeI32,
/*  2154*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_NOT),
                 MVT::i32, 1/*#Ops*/, 0, 
             // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, -1:{ *:[i32] }) - Complexity = 8
             // Dst: (C_NOT:{ *:[i32] } GPR:{ *:[i32] }:$a)
/*  2160*/  /*Scope*/ 51, /*->2212*/
/*  2161*/   OPC_RecordChild1, // #1 = $i
/*  2162*/   OPC_Scope, 16, /*->2180*/ // 4 children in Scope
/*  2164*/    OPC_MoveChild1,
/*  2165*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  2168*/    OPC_CheckPredicate, 12, // Predicate_simm13_imm
/*  2170*/    OPC_MoveParent,
/*  2171*/    OPC_CheckTypeI32,
/*  2172*/    OPC_EmitConvertToTarget1,
/*  2173*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XORI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (XORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2180*/   /*Scope*/ 9, /*->2190*/
/*  2181*/    OPC_CheckTypeI32,
/*  2182*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (XOR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2190*/   /*Scope*/ 9, /*->2200*/
/*  2191*/    OPC_CheckType, MVT::i1,
/*  2193*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PXOR),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (xor:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PXOR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  2200*/   /*Scope*/ 10, /*->2211*/
/*  2201*/    OPC_CheckType, MVT::i16,
/*  2203*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (XOR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  2211*/   0, /*End of Scope*/
/*  2212*/  0, /*End of Scope*/
/*  2213*/ /*SwitchOpcode*/ 120, TARGET_VAL(ISD::SHL),// ->2336
/*  2216*/  OPC_RecordChild0, // #0 = $a
/*  2217*/  OPC_RecordChild1, // #1 = $i
/*  2218*/  OPC_Scope, 64, /*->2284*/ // 2 children in Scope
/*  2220*/   OPC_MoveChild1,
/*  2221*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  2224*/   OPC_CheckTypeI32,
/*  2225*/   OPC_Scope, 12, /*->2239*/ // 2 children in Scope
/*  2227*/    OPC_CheckPredicate, 14, // Predicate_uimm4_imm
/*  2229*/    OPC_MoveParent,
/*  2230*/    OPC_CheckTypeI32,
/*  2231*/    OPC_EmitConvertToTarget1,
/*  2232*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHLI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2239*/   /*Scope*/ 43, /*->2283*/
/*  2240*/    OPC_CheckPredicate, 15, // Predicate_uimm5_imm
/*  2242*/    OPC_MoveParent,
/*  2243*/    OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2254
/*  2246*/     OPC_EmitConvertToTarget1,
/*  2247*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHLI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
               // Dst: (SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2254*/    /*SwitchType*/ 26, MVT::i16,// ->2282
/*  2256*/     OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  2258*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*  2265*/     OPC_EmitConvertToTarget1,
/*  2266*/     OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                   MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*  2273*/     OPC_EmitInteger32, 2, 
/*  2275*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                   MVT::i16, 2/*#Ops*/, 5, 6, 
               // Src: (shl:{ *:[i16] } GPR16:{ *:[i16] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
               // Dst: (PSEUDO_TRUNC16:{ *:[i16] } (SHLI:{ *:[i32] } (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] }), (imm:{ *:[i32] }):$i), 1:{ *:[i32] })
/*  2282*/    0, // EndSwitchType
/*  2283*/   0, /*End of Scope*/
/*  2284*/  /*Scope*/ 50, /*->2335*/
/*  2285*/   OPC_CheckChild1TypeI32,
/*  2286*/   OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2297
/*  2289*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHL),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (SHL:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2297*/   /*SwitchType*/ 35, MVT::i16,// ->2334
/*  2299*/    OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  2301*/    OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                  MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*  2308*/    OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  2310*/    OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                  MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*  2317*/    OPC_EmitNode1None, TARGET_VAL(CCV::SHL),
                  MVT::i32, 3/*#Ops*/, 3, 1, 5,  // Results = #6
/*  2325*/    OPC_EmitInteger32, 2, 
/*  2327*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                  MVT::i16, 2/*#Ops*/, 6, 7, 
              // Src: (shl:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (PSEUDO_TRUNC16:{ *:[i16] } (SHL:{ *:[i32] } (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] }), GPR:{ *:[i32] }:$b, (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] })), 1:{ *:[i32] })
/*  2334*/   0, // EndSwitchType
/*  2335*/  0, /*End of Scope*/
/*  2336*/ /*SwitchOpcode*/ 120, TARGET_VAL(ISD::SRL),// ->2459
/*  2339*/  OPC_RecordChild0, // #0 = $a
/*  2340*/  OPC_RecordChild1, // #1 = $i
/*  2341*/  OPC_Scope, 64, /*->2407*/ // 2 children in Scope
/*  2343*/   OPC_MoveChild1,
/*  2344*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  2347*/   OPC_CheckTypeI32,
/*  2348*/   OPC_Scope, 12, /*->2362*/ // 2 children in Scope
/*  2350*/    OPC_CheckPredicate, 14, // Predicate_uimm4_imm
/*  2352*/    OPC_MoveParent,
/*  2353*/    OPC_CheckTypeI32,
/*  2354*/    OPC_EmitConvertToTarget1,
/*  2355*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHRI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2362*/   /*Scope*/ 43, /*->2406*/
/*  2363*/    OPC_CheckPredicate, 15, // Predicate_uimm5_imm
/*  2365*/    OPC_MoveParent,
/*  2366*/    OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2377
/*  2369*/     OPC_EmitConvertToTarget1,
/*  2370*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHRI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
               // Dst: (SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2377*/    /*SwitchType*/ 26, MVT::i16,// ->2405
/*  2379*/     OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  2381*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*  2388*/     OPC_EmitConvertToTarget1,
/*  2389*/     OPC_EmitNode1None, TARGET_VAL(CCV::SHRI),
                   MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*  2396*/     OPC_EmitInteger32, 0, 
/*  2398*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                   MVT::i16, 2/*#Ops*/, 5, 6, 
               // Src: (srl:{ *:[i16] } GPR16:{ *:[i16] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
               // Dst: (PSEUDO_TRUNC16:{ *:[i16] } (SHRI:{ *:[i32] } (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] }), (imm:{ *:[i32] }):$i), 0:{ *:[i32] })
/*  2405*/    0, // EndSwitchType
/*  2406*/   0, /*End of Scope*/
/*  2407*/  /*Scope*/ 50, /*->2458*/
/*  2408*/   OPC_CheckChild1TypeI32,
/*  2409*/   OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2420
/*  2412*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHR),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (SHR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2420*/   /*SwitchType*/ 35, MVT::i16,// ->2457
/*  2422*/    OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  2424*/    OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                  MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*  2431*/    OPC_EmitStringInteger32, CCV::GPRRegClassID,
/*  2433*/    OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                  MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*  2440*/    OPC_EmitNode1None, TARGET_VAL(CCV::SHR),
                  MVT::i32, 3/*#Ops*/, 3, 1, 5,  // Results = #6
/*  2448*/    OPC_EmitInteger32, 0, 
/*  2450*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                  MVT::i16, 2/*#Ops*/, 6, 7, 
              // Src: (srl:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (PSEUDO_TRUNC16:{ *:[i16] } (SHR:{ *:[i32] } (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] }), GPR:{ *:[i32] }:$b, (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] })), 0:{ *:[i32] })
/*  2457*/   0, // EndSwitchType
/*  2458*/  0, /*End of Scope*/
/*  2459*/ /*SwitchOpcode*/ 117, TARGET_VAL(ISD::SRA),// ->2579
/*  2462*/  OPC_RecordChild0, // #0 = $a
/*  2463*/  OPC_RecordChild1, // #1 = $i
/*  2464*/  OPC_Scope, 63, /*->2529*/ // 2 children in Scope
/*  2466*/   OPC_MoveChild1,
/*  2467*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  2470*/   OPC_CheckTypeI32,
/*  2471*/   OPC_Scope, 12, /*->2485*/ // 2 children in Scope
/*  2473*/    OPC_CheckPredicate, 14, // Predicate_uimm4_imm
/*  2475*/    OPC_MoveParent,
/*  2476*/    OPC_CheckTypeI32,
/*  2477*/    OPC_EmitConvertToTarget1,
/*  2478*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SRAI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2485*/   /*Scope*/ 42, /*->2528*/
/*  2486*/    OPC_CheckPredicate, 15, // Predicate_uimm5_imm
/*  2488*/    OPC_MoveParent,
/*  2489*/    OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2500
/*  2492*/     OPC_EmitConvertToTarget1,
/*  2493*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRAI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
               // Dst: (SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2500*/    /*SwitchType*/ 25, MVT::i16,// ->2527
/*  2502*/     OPC_EmitNode1None, TARGET_VAL(CCV::CVT_SEXT),
                   MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #2
/*  2510*/     OPC_EmitConvertToTarget1,
/*  2511*/     OPC_EmitNode1None, TARGET_VAL(CCV::SRAI),
                   MVT::i32, 2/*#Ops*/, 2, 3,  // Results = #4
/*  2518*/     OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  2520*/     OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i16, 2/*#Ops*/, 4, 5, 
               // Src: (sra:{ *:[i16] } GPR16:{ *:[i16] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
               // Dst: (COPY_TO_REGCLASS:{ *:[i16] } (SRAI:{ *:[i32] } (CVT_SEXT:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a), (imm:{ *:[i32] }):$i), GPR16:{ *:[i32] })
/*  2527*/    0, // EndSwitchType
/*  2528*/   0, /*End of Scope*/
/*  2529*/  /*Scope*/ 48, /*->2578*/
/*  2530*/   OPC_CheckChild1TypeI32,
/*  2531*/   OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2542
/*  2534*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRA),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (SRA:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2542*/   /*SwitchType*/ 33, MVT::i16,// ->2577
/*  2544*/    OPC_EmitNode1None, TARGET_VAL(CCV::CVT_SEXT),
                  MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #2
/*  2552*/    OPC_EmitNode1None, TARGET_VAL(CCV::CVT_SEXT),
                  MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #3
/*  2560*/    OPC_EmitNode1None, TARGET_VAL(CCV::SRA),
                  MVT::i32, 3/*#Ops*/, 2, 1, 3,  // Results = #4
/*  2568*/    OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  2570*/    OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                  MVT::i16, 2/*#Ops*/, 4, 5, 
              // Src: (sra:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (COPY_TO_REGCLASS:{ *:[i16] } (SRA:{ *:[i32] } (CVT_SEXT:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a), GPR:{ *:[i32] }:$b, (CVT_SEXT:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a)), GPR16:{ *:[i32] })
/*  2577*/   0, // EndSwitchType
/*  2578*/  0, /*End of Scope*/
/*  2579*/ /*SwitchOpcode*/ 31, TARGET_VAL(ISD::MUL),// ->2613
/*  2582*/  OPC_RecordChild0, // #0 = $a
/*  2583*/  OPC_RecordChild1, // #1 = $i
/*  2584*/  OPC_Scope, 16, /*->2602*/ // 2 children in Scope
/*  2586*/   OPC_MoveChild1,
/*  2587*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  2590*/   OPC_CheckPredicate, 12, // Predicate_simm13_imm
/*  2592*/   OPC_MoveParent,
/*  2593*/   OPC_CheckTypeI32,
/*  2594*/   OPC_EmitConvertToTarget1,
/*  2595*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MULI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (MULI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2602*/  /*Scope*/ 9, /*->2612*/
/*  2603*/   OPC_CheckTypeI32,
/*  2604*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_LO),
                 MVT::i32, 3/*#Ops*/, 0, 1, 1, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MUL_LO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$b)
/*  2612*/  0, /*End of Scope*/
/*  2613*/ /*SwitchOpcode*/ 52, TARGET_VAL(ISD::OR),// ->2668
/*  2616*/  OPC_RecordChild0, // #0 = $a
/*  2617*/  OPC_RecordChild1, // #1 = $i
/*  2618*/  OPC_Scope, 16, /*->2636*/ // 4 children in Scope
/*  2620*/   OPC_MoveChild1,
/*  2621*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  2624*/   OPC_CheckPredicate, 12, // Predicate_simm13_imm
/*  2626*/   OPC_MoveParent,
/*  2627*/   OPC_CheckTypeI32,
/*  2628*/   OPC_EmitConvertToTarget1,
/*  2629*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ORI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (ORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  2636*/  /*Scope*/ 9, /*->2646*/
/*  2637*/   OPC_CheckTypeI32,
/*  2638*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (OR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2646*/  /*Scope*/ 9, /*->2656*/
/*  2647*/   OPC_CheckType, MVT::i1,
/*  2649*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_POR),
                 MVT::i1, 2/*#Ops*/, 0, 1, 
             // Src: (or:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
             // Dst: (PSEUDO_POR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  2656*/  /*Scope*/ 10, /*->2667*/
/*  2657*/   OPC_CheckType, MVT::i16,
/*  2659*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (OR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  2667*/  0, /*End of Scope*/
/*  2668*/ /*SwitchOpcode*/ 15, TARGET_VAL(CCVISD::CALL),// ->2686
/*  2671*/  OPC_RecordNode, // #0 = 'ccv_call' chained node
/*  2672*/  OPC_CaptureGlueInput,
/*  2673*/  OPC_RecordChild1, // #1 = $f
/*  2674*/  OPC_MoveChild1,
/*  2675*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*  2678*/  OPC_MoveParent,
/*  2679*/  OPC_EmitMergeInputChains1_0,
/*  2680*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::PSEUDO_CALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                1/*#Ops*/, 1, 
            // Src: (ccv_call (tglobaladdr:{ *:[i32] }):$f) - Complexity = 6
            // Dst: (PSEUDO_CALL (tglobaladdr:{ *:[i32] }):$f)
/*  2686*/ /*SwitchOpcode*/ 16, TARGET_VAL(ISD::BITCAST),// ->2705
/*  2689*/  OPC_RecordChild0, // #0 = $a
/*  2690*/  OPC_SwitchType /*2 cases */, 5, MVT::i32,// ->2698
/*  2693*/   OPC_CheckChild0Type, MVT::f32,
/*  2695*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[i32] }:$a
/*  2698*/  /*SwitchType*/ 4, MVT::f32,// ->2704
/*  2700*/   OPC_CheckChild0TypeI32,
/*  2701*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[f32] }:$a
/*  2704*/  0, // EndSwitchType
/*  2705*/ /*SwitchOpcode*/ 13, TARGET_VAL(ISD::BR),// ->2721
/*  2708*/  OPC_RecordNode, // #0 = 'br' chained node
/*  2709*/  OPC_RecordChild1, // #1 = $t
/*  2710*/  OPC_MoveChild1,
/*  2711*/  OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*  2714*/  OPC_MoveParent,
/*  2715*/  OPC_EmitMergeInputChains1_0,
/*  2716*/  OPC_MorphNodeTo0Chain, TARGET_VAL(CCV::C_BRA),
                1/*#Ops*/, 1, 
            // Src: (br (bb:{ *:[Other] }):$t) - Complexity = 3
            // Dst: (C_BRA (bb:{ *:[Other] }):$t)
/*  2721*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMIN),// ->2748
/*  2724*/  OPC_RecordChild0, // #0 = $a
/*  2725*/  OPC_RecordChild1, // #1 = $b
/*  2726*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2737
/*  2729*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MIN_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2737*/  /*SwitchType*/ 8, MVT::i16,// ->2747
/*  2739*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MIN_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  2747*/  0, // EndSwitchType
/*  2748*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMIN),// ->2762
/*  2751*/  OPC_RecordChild0, // #0 = $a
/*  2752*/  OPC_RecordChild1, // #1 = $b
/*  2753*/  OPC_CheckTypeI32,
/*  2754*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MIN_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2762*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMAX),// ->2789
/*  2765*/  OPC_RecordChild0, // #0 = $a
/*  2766*/  OPC_RecordChild1, // #1 = $b
/*  2767*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->2778
/*  2770*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MAX_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2778*/  /*SwitchType*/ 8, MVT::i16,// ->2788
/*  2780*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MAX_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  2788*/  0, // EndSwitchType
/*  2789*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMAX),// ->2803
/*  2792*/  OPC_RecordChild0, // #0 = $a
/*  2793*/  OPC_RecordChild1, // #1 = $b
/*  2794*/  OPC_CheckTypeI32,
/*  2795*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MAX_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2803*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHS),// ->2817
/*  2806*/  OPC_RecordChild0, // #0 = $a
/*  2807*/  OPC_RecordChild1, // #1 = $b
/*  2808*/  OPC_CheckTypeI32,
/*  2809*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_S),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhs:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2817*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHU),// ->2831
/*  2820*/  OPC_RecordChild0, // #0 = $a
/*  2821*/  OPC_RecordChild1, // #1 = $b
/*  2822*/  OPC_CheckTypeI32,
/*  2823*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhu:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  2831*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTPOP),// ->2845
/*  2834*/  OPC_RecordChild0, // #0 = $a
/*  2835*/  OPC_CheckChild0TypeI32,
/*  2836*/  OPC_CheckTypeI32,
/*  2837*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::POPC),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctpop:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (POPC:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2845*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTLZ),// ->2859
/*  2848*/  OPC_RecordChild0, // #0 = $a
/*  2849*/  OPC_CheckChild0TypeI32,
/*  2850*/  OPC_CheckTypeI32,
/*  2851*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CLZ),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctlz:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CLZ:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2859*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::BITREVERSE),// ->2872
/*  2862*/  OPC_RecordChild0, // #0 = $a
/*  2863*/  OPC_CheckTypeI32,
/*  2864*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::BREV),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (bitreverse:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (BREV:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2872*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ABS),// ->2885
/*  2875*/  OPC_RecordChild0, // #0 = $a
/*  2876*/  OPC_CheckTypeI32,
/*  2877*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::ABS),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (abs:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (ABS:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2885*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_SINT),// ->2898
/*  2888*/  OPC_RecordChild0, // #0 = $a
/*  2889*/  OPC_CheckTypeI32,
/*  2890*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_S32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_sint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_S32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2898*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_UINT),// ->2911
/*  2901*/  OPC_RecordChild0, // #0 = $a
/*  2902*/  OPC_CheckTypeI32,
/*  2903*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_U32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_uint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_U32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2911*/ /*SwitchOpcode*/ 12, TARGET_VAL(ISD::TRUNCATE),// ->2926
/*  2914*/  OPC_RecordChild0, // #0 = $a
/*  2915*/  OPC_CheckType, MVT::i16,
/*  2917*/  OPC_EmitInteger32, 2, 
/*  2919*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_TRUNC16),
                MVT::i16, 2/*#Ops*/, 0, 1, 
            // Src: (trunc:{ *:[i16] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (PSEUDO_TRUNC16:{ *:[i16] } GPR:{ *:[i32] }:$a, 1:{ *:[i32] })
/*  2926*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ZERO_EXTEND),// ->2939
/*  2929*/  OPC_RecordChild0, // #0 = $a
/*  2930*/  OPC_CheckChild0Type, MVT::i16,
/*  2932*/  OPC_CheckTypeI32,
/*  2933*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i32, 1/*#Ops*/, 0, 
            // Src: (zext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i32] } GPR16:{ *:[i16] }:$a)
/*  2939*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ANY_EXTEND),// ->2952
/*  2942*/  OPC_RecordChild0, // #0 = $a
/*  2943*/  OPC_CheckChild0Type, MVT::i16,
/*  2945*/  OPC_CheckTypeI32,
/*  2946*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i32, 1/*#Ops*/, 0, 
            // Src: (anyext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i32] } GPR16:{ *:[i16] }:$a)
/*  2952*/ /*SwitchOpcode*/ 12, TARGET_VAL(ISD::SIGN_EXTEND),// ->2967
/*  2955*/  OPC_RecordChild0, // #0 = $a
/*  2956*/  OPC_CheckChild0Type, MVT::i16,
/*  2958*/  OPC_CheckTypeI32,
/*  2959*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_SEXT),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (CVT_SEXT:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a)
/*  2967*/ /*SwitchOpcode*/ 23, TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->2993
/*  2970*/  OPC_RecordChild0, // #0 = $a
/*  2971*/  OPC_MoveChild1,
/*  2972*/  OPC_CheckValueType, MVT::i16,
/*  2974*/  OPC_MoveParent,
/*  2975*/  OPC_EmitInteger32, 32, 
/*  2977*/  OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*  2984*/  OPC_EmitInteger32, 32, 
/*  2986*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRAI),
                MVT::i32, 2/*#Ops*/, 2, 3, 
            // Src: (sext_inreg:{ *:[i32] } GPR:{ *:[i32] }:$a, i16:{ *:[Other] }) - Complexity = 3
            // Dst: (SRAI:{ *:[i32] } (SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, 16:{ *:[i32] }), 16:{ *:[i32] })
/*  2993*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::ConstantFP),// ->3021
/*  2996*/  OPC_RecordNode, // #0 = $i
/*  2997*/  OPC_Scope, 11, /*->3010*/ // 2 children in Scope
/*  2999*/   OPC_CheckPredicate, 20, // Predicate_fpimm_small
/*  3001*/   OPC_EmitNodeXForm, 4, 0, // fpimm_bits
/*  3004*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] })<<P:Predicate_fpimm_small>>:$i - Complexity = 14
             // Dst: (MOVI:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  3010*/  /*Scope*/ 9, /*->3020*/
/*  3011*/   OPC_EmitNodeXForm, 4, 0, // fpimm_bits
/*  3014*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] }):$i - Complexity = 3
             // Dst: (MOVI48:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  3020*/  0, /*End of Scope*/
/*  3021*/ /*SwitchOpcode*/ 67, TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->3091
/*  3024*/  OPC_Scope, 12, /*->3038*/ // 5 children in Scope
/*  3026*/   OPC_CheckChild0Integer, 42|128,125/*16042*/, 
/*  3029*/   OPC_RecordChild1, // #0 = $a
/*  3030*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8021:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (RCP_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3038*/  /*Scope*/ 12, /*->3051*/
/*  3039*/   OPC_CheckChild0Integer, 106|128,127/*16362*/, 
/*  3042*/   OPC_RecordChild1, // #0 = $a
/*  3043*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SQRT_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8181:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (SQRT_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3051*/  /*Scope*/ 12, /*->3064*/
/*  3052*/   OPC_CheckChild0Integer, 12|128,127/*16268*/, 
/*  3055*/   OPC_RecordChild1, // #0 = $a
/*  3056*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::RSQRT_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8134:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (RSQRT_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3064*/  /*Scope*/ 12, /*->3077*/
/*  3065*/   OPC_CheckChild0Integer, 102|128,127/*16358*/, 
/*  3068*/   OPC_RecordChild1, // #0 = $a
/*  3069*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SIN_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8179:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (SIN_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3077*/  /*Scope*/ 12, /*->3090*/
/*  3078*/   OPC_CheckChild0Integer, 96|128,118/*15200*/, 
/*  3081*/   OPC_RecordChild1, // #0 = $a
/*  3082*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::COS_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 7600:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (COS_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3090*/  0, /*End of Scope*/
/*  3091*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FADD),// ->3103
/*  3094*/  OPC_RecordChild0, // #0 = $a
/*  3095*/  OPC_RecordChild1, // #1 = $b
/*  3096*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FADD),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fadd:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FADD:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  3103*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMUL),// ->3115
/*  3106*/  OPC_RecordChild0, // #0 = $a
/*  3107*/  OPC_RecordChild1, // #1 = $b
/*  3108*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMUL),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmul:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMUL:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  3115*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FSUB),// ->3128
/*  3118*/  OPC_RecordChild0, // #0 = $a
/*  3119*/  OPC_RecordChild1, // #1 = $b
/*  3120*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FSUB),
                MVT::f32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (fsub:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (FSUB:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$a)
/*  3128*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMINNUM),// ->3140
/*  3131*/  OPC_RecordChild0, // #0 = $a
/*  3132*/  OPC_RecordChild1, // #1 = $b
/*  3133*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMIN),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fminnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMIN:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  3140*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMAXNUM),// ->3152
/*  3143*/  OPC_RecordChild0, // #0 = $a
/*  3144*/  OPC_RecordChild1, // #1 = $b
/*  3145*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMAX),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmaxnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMAX:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  3152*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FNEG),// ->3164
/*  3155*/  OPC_RecordChild0, // #0 = $a
/*  3156*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FNEG_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fneg:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FNEG_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3164*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FABS),// ->3176
/*  3167*/  OPC_RecordChild0, // #0 = $a
/*  3168*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FABS_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fabs:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FABS_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3176*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::FMA),// ->3190
/*  3179*/  OPC_RecordChild0, // #0 = $a
/*  3180*/  OPC_RecordChild1, // #1 = $b
/*  3181*/  OPC_RecordChild2, // #2 = $c
/*  3182*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FFMA_F0),
                MVT::f32, 3/*#Ops*/, 0, 1, 2, 
            // Src: (fma:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c) - Complexity = 3
            // Dst: (FFMA_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c)
/*  3190*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::SINT_TO_FP),// ->3203
/*  3193*/  OPC_RecordChild0, // #0 = $a
/*  3194*/  OPC_CheckChild0TypeI32,
/*  3195*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_S32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_S32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  3203*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::UINT_TO_FP),// ->3216
/*  3206*/  OPC_RecordChild0, // #0 = $a
/*  3207*/  OPC_CheckChild0TypeI32,
/*  3208*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_U32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (uint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_U32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  3216*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FEXP2),// ->3228
/*  3219*/  OPC_RecordChild0, // #0 = $a
/*  3220*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::EX2_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fexp2:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (EX2_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3228*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FLOG2),// ->3240
/*  3231*/  OPC_RecordChild0, // #0 = $a
/*  3232*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::LG2_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (flog2:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (LG2_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  3240*/ 0, // EndSwitchOpcode
    0
  }; // Total Array size is 3242 bytes

  // Opcode Histogram:
  // #OPC_Scope                                = 49
  // #OPC_RecordNode                           = 11
  // #OPC_RecordChild                          = 123
  // #OPC_RecordMemRef                         = 2
  // #OPC_CaptureGlueInput                     = 2
  // #OPC_MoveChild                            = 39
  // #OPC_MoveSibling                          = 2
  // #OPC_MoveParent                           = 58
  // #OPC_CheckSame                            = 0
  // #OPC_CheckChildSame                       = 0
  // #OPC_CheckPatternPredicate                = 0
  // #OPC_CheckPredicate                       = 199
  // #OPC_CheckOpcode                          = 40
  // #OPC_SwitchOpcode                         = 1
  // #OPC_CheckType                            = 79
  // #OPC_SwitchType                           = 15
  // #OPC_CheckChildType                       = 31
  // #OPC_CheckInteger                         = 2
  // #OPC_CheckChildInteger                    = 17
  // #OPC_CheckCondCode                        = 0
  // #OPC_CheckChild2CondCode                  = 0
  // #OPC_CheckValueType                       = 1
  // #OPC_CheckComplexPat                      = 0
  // #OPC_CheckAndImm                          = 0
  // #OPC_CheckOrImm                           = 0
  // #OPC_CheckImmAllOnesV                     = 0
  // #OPC_CheckImmAllZerosV                    = 0
  // #OPC_CheckFoldableChainNode               = 0
  // #OPC_EmitInteger                          = 113
  // #OPC_EmitStringInteger                    = 18
  // #OPC_EmitRegister                         = 0
  // #OPC_EmitConvertToTarget                  = 28
  // #OPC_EmitMergeInputChains                 = 65
  // #OPC_EmitCopyToReg                        = 0
  // #OPC_EmitNode                             = 51
  // #OPC_EmitNodeXForm                        = 6
  // #OPC_CompleteMatch                        = 2
  // #OPC_MorphNodeTo                          = 152

  #undef TARGET_VAL
  SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}
#endif // GET_DAGISEL_BODY

#ifdef GET_DAGISEL_DECL
bool CheckNodePredicate(SDNode *Node, unsigned PredNo) const override;
#endif
#if defined(GET_DAGISEL_BODY) || DAGISEL_INLINE
bool DAGISEL_CLASS_COLONCOLON CheckNodePredicate(SDNode *Node, unsigned PredNo) const
#if DAGISEL_INLINE
  override
#endif
{
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: {
    // Predicate_anonymous_7398
    // Predicate_anonymous_7399
    // Predicate_anonymous_7405
    // Predicate_ld_shared
    // Predicate_ld_shared_s8
    // Predicate_ld_shared_u8
    // Predicate_ld_shared_z8
    SDNode *N = Node;
    (void)N;

  return cast<LoadSDNode>(N)->getAddressSpace() == 3;

  }
  case 1: {
    // Predicate_anonymous_7408
    // Predicate_st_shared
    // Predicate_st_shared_8
    SDNode *N = Node;
    (void)N;

  return cast<StoreSDNode>(N)->getAddressSpace() == 3;

  }
  case 2: {
    // Predicate_unindexedstore
    SDNode *N = Node;
    (void)N;
if (cast<StoreSDNode>(N)->getAddressingMode() != ISD::UNINDEXED) return false;
return true;

  }
  case 3: {
    // Predicate_extloadi8
    // Predicate_sextloadi8
    // Predicate_zextloadi8
    SDNode *N = Node;
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i8) return false;
return true;

  }
  case 4: {
    // Predicate_load
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::NON_EXTLOAD) return false;
return true;

  }
  case 5: {
    // Predicate_store
    SDNode *N = Node;
    (void)N;
 if (cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 6: {
    // Predicate_unindexedload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getAddressingMode() != ISD::UNINDEXED) return false;
return true;

  }
  case 7: {
    // Predicate_truncstore
    SDNode *N = Node;
    (void)N;
 if (!cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 8: {
    // Predicate_truncstorei8
    SDNode *N = Node;
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i8) return false;
 if (!cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 9: {
    // Predicate_extload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::EXTLOAD) return false;
return true;

  }
  case 10: {
    // Predicate_zextload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::ZEXTLOAD) return false;
return true;

  }
  case 11: {
    // Predicate_sextload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::SEXTLOAD) return false;
return true;

  }
  case 12: {
    // Predicate_simm13_imm
    // Predicate_simm13_imm16
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return isInt<13>(Imm); 
  }
  case 13: {
    // Predicate_extloadi16
    // Predicate_sextloadi16
    // Predicate_zextloadi16
    SDNode *N = Node;
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i16) return false;
return true;

  }
  case 14: {
    // Predicate_uimm4_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < 16; 
  }
  case 15: {
    // Predicate_uimm5_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < 32; 
  }
  case 16: {
    // Predicate_truncstorei16
    SDNode *N = Node;
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i16) return false;
 if (!cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 17: {
    // Predicate_uimm29_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && isUInt<29>(Imm); 
  }
  case 18: {
    // Predicate_uimm17_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < (1 << 17); 
  }
  case 19: {
    // Predicate_simm13_not_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

  return !isInt<13>(Imm) && isInt<13>(~Imm);

  }
  case 20: {
    // Predicate_fpimm_small
    auto *N = cast<ConstantFPSDNode>(Node);
    (void)N;

  return N->getValueAPF().bitcastToAPInt().getZExtValue() < (1u << 17);

  }
  }
}
#endif // GET_DAGISEL_BODY

#ifdef GET_DAGISEL_DECL
SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) override;
#endif
#if defined(GET_DAGISEL_BODY) || DAGISEL_INLINE
SDValue DAGISEL_CLASS_COLONCOLON RunSDNodeXForm(SDValue V, unsigned XFormNo)
#if DAGISEL_INLINE
  override
#endif
{
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // as_i32imm
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getSExtValue(), SDLoc(N), MVT::i32);

  }
  case 1: {  // imm_bits32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // i64, not i32: a 32-bit target constant is carried to the MachineOperand
  // sign-extended, which is the whole problem. The field is 33 bits and the
  // value is a 32-bit pattern, so it must arrive zero-extended.
  return CurDAG->getTargetConstant(N->getZExtValue() & 0xFFFFFFFFull, SDLoc(N),
                                   MVT::i64);

  }
  case 2: {  // imm16_bits
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getZExtValue() & 0xFFFF, SDLoc(N), MVT::i32);

  }
  case 3: {  // imm_not
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(~N->getSExtValue(), SDLoc(N), MVT::i32);

  }
  case 4: {  // fpimm_bits
    ConstantFPSDNode *N = cast<ConstantFPSDNode>(V.getNode());

  // i64 for the same reason imm_bits32 gives, and it was missing here: a 32-bit
  // target constant reaches the MachineOperand SIGN-extended, so any float whose
  // sign bit is set arrived as a negative 64-bit value and failed MOVI48's
  // unsigned 33-bit field check -- which is a hard compiler error, not a
  // miscompile. **Every negative float constant was unencodable**, and nothing
  // noticed because not one kernel in the tree had ever written one. F-144.
  return CurDAG->getTargetConstant(
      N->getValueAPF().bitcastToAPInt().getZExtValue(), SDLoc(N), MVT::i64);

  }
  }
}
#endif // GET_DAGISEL_BODY


#ifdef DAGISEL_INLINE
#undef DAGISEL_INLINE
#endif
#ifdef DAGISEL_CLASS_COLONCOLON
#undef DAGISEL_CLASS_COLONCOLON
#endif
#ifdef GET_DAGISEL_DECL
#undef GET_DAGISEL_DECL
#endif
#ifdef GET_DAGISEL_BODY
#undef GET_DAGISEL_BODY
#endif
