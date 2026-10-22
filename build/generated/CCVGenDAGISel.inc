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
/*     0*/ OPC_SwitchOpcode /*50 cases */, 114, TARGET_VAL(ISD::ADD),// ->118
/*     4*/  OPC_Scope, 48, /*->54*/ // 3 children in Scope
/*     6*/   OPC_RecordChild0, // #0 = $a
/*     7*/   OPC_RecordChild1, // #1 = $i
/*     8*/   OPC_MoveChild1,
/*     9*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    12*/   OPC_Scope, 11, /*->25*/ // 3 children in Scope
/*    14*/    OPC_CheckPredicate7,  // Predicate_simm13_imm
/*    15*/    OPC_MoveParent,
/*    16*/    OPC_CheckTypeI32,
/*    17*/    OPC_EmitConvertToTarget1,
/*    18*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 17
              // Dst: (ADDI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*    25*/   /*Scope*/ 12, /*->38*/
/*    26*/    OPC_CheckPredicate, 15, // Predicate_uimm29_imm
/*    28*/    OPC_MoveParent,
/*    29*/    OPC_CheckTypeI32,
/*    30*/    OPC_EmitConvertToTarget1,
/*    31*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI48),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm29_imm>>:$i) - Complexity = 12
              // Dst: (ADDI48:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*    38*/   /*Scope*/ 14, /*->53*/
/*    39*/    OPC_CheckPredicate7,  // Predicate_simm13_imm16
/*    40*/    OPC_MoveParent,
/*    41*/    OPC_CheckType, MVT::i16,
/*    43*/    OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*    46*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI_W16),
                  MVT::i16, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i16] } GPR16:{ *:[i16] }:$a, (imm:{ *:[i16] })<<P:Predicate_simm13_imm16>>:$i) - Complexity = 7
              // Dst: (ADDI_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, (as_i32imm:{ *:[i32] } ?:{ *:[i16] }:$i))
/*    53*/   0, /*End of Scope*/
/*    54*/  /*Scope*/ 17, /*->72*/
/*    55*/   OPC_MoveChild0,
/*    56*/   OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*    59*/   OPC_RecordChild0, // #0 = $a
/*    60*/   OPC_RecordChild1, // #1 = $b
/*    61*/   OPC_MoveParent,
/*    62*/   OPC_RecordChild1, // #2 = $c
/*    63*/   OPC_CheckTypeI32,
/*    64*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MADLO),
                 MVT::i32, 3/*#Ops*/, 0, 1, 2, 
             // Src: (add:{ *:[i32] } (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b), GPR:{ *:[i32] }:$c) - Complexity = 6
             // Dst: (MADLO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$c)
/*    72*/  /*Scope*/ 44, /*->117*/
/*    73*/   OPC_RecordChild0, // #0 = $c
/*    74*/   OPC_Scope, 16, /*->92*/ // 2 children in Scope
/*    76*/    OPC_MoveChild1,
/*    77*/    OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*    80*/    OPC_RecordChild0, // #1 = $a
/*    81*/    OPC_RecordChild1, // #2 = $b
/*    82*/    OPC_MoveParent,
/*    83*/    OPC_CheckTypeI32,
/*    84*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::MADLO),
                  MVT::i32, 3/*#Ops*/, 1, 2, 0, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$c, (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b)) - Complexity = 6
              // Dst: (MADLO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$c)
/*    92*/   /*Scope*/ 23, /*->116*/
/*    93*/    OPC_RecordChild1, // #1 = $b
/*    94*/    OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->105
/*    97*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADD),
                   MVT::i32, 3/*#Ops*/, 0, 1, 0, 
               // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
               // Dst: (ADD:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   105*/    /*SwitchType*/ 8, MVT::i16,// ->115
/*   107*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADD_W16),
                   MVT::i16, 3/*#Ops*/, 0, 1, 0, 
               // Src: (add:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
               // Dst: (ADD_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*   115*/    0, // EndSwitchType
/*   116*/   0, /*End of Scope*/
/*   117*/  0, /*End of Scope*/
/*   118*/ /*SwitchOpcode*/ 38|128,4/*550*/, TARGET_VAL(ISD::LOAD),// ->672
/*   122*/  OPC_RecordMemRef,
/*   123*/  OPC_RecordNode, // #0 = 'ld' chained node
/*   124*/  OPC_Scope, 40|128,2/*296*/, /*->423*/ // 4 children in Scope
/*   127*/   OPC_MoveChild1,
/*   128*/   OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   131*/   OPC_Scope, 31, /*->164*/ // 3 children in Scope
/*   133*/    OPC_RecordChild0, // #1 = $rbase
/*   134*/    OPC_MoveChild1,
/*   135*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   138*/    OPC_RecordChild0, // #2 = $ri
/*   139*/    OPC_CheckChild1Integer, 4, 
/*   141*/    OPC_CheckChild1TypeI32,
/*   142*/    OPC_MoveParent,
/*   143*/    OPC_CheckTypeI32,
/*   144*/    OPC_MoveParent,
/*   145*/    OPC_CheckPredicate5,  // Predicate_unindexedload
/*   146*/    OPC_CheckPredicate3,  // Predicate_load
/*   147*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   148*/    OPC_CheckTypeI32,
/*   149*/    OPC_EmitMergeInputChains1_0,
/*   150*/    OPC_EmitInteger32, 2, 
/*   152*/    OPC_EmitInteger32, 0, 
/*   154*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   164*/   /*Scope*/ 31, /*->196*/
/*   165*/    OPC_MoveChild0,
/*   166*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   169*/    OPC_RecordChild0, // #1 = $ri
/*   170*/    OPC_CheckChild1Integer, 4, 
/*   172*/    OPC_CheckChild1TypeI32,
/*   173*/    OPC_MoveParent,
/*   174*/    OPC_RecordChild1, // #2 = $rbase
/*   175*/    OPC_CheckTypeI32,
/*   176*/    OPC_MoveParent,
/*   177*/    OPC_CheckPredicate5,  // Predicate_unindexedload
/*   178*/    OPC_CheckPredicate3,  // Predicate_load
/*   179*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   180*/    OPC_CheckTypeI32,
/*   181*/    OPC_EmitMergeInputChains1_0,
/*   182*/    OPC_EmitInteger32, 2, 
/*   184*/    OPC_EmitInteger32, 0, 
/*   186*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 4/*#Ops*/, 2, 1, 3, 4, 
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   196*/   /*Scope*/ 96|128,1/*224*/, /*->422*/
/*   198*/    OPC_RecordChild0, // #1 = $rbase
/*   199*/    OPC_RecordChild1, // #2 = $off
/*   200*/    OPC_Scope, 104, /*->306*/ // 2 children in Scope
/*   202*/     OPC_MoveChild1,
/*   203*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   206*/     OPC_MoveParent,
/*   207*/     OPC_CheckTypeI32,
/*   208*/     OPC_MoveParent,
/*   209*/     OPC_CheckPredicate5,  // Predicate_unindexedload
/*   210*/     OPC_SwitchType /*2 cases */, 78, MVT::i32,// ->291
/*   213*/      OPC_Scope, 12, /*->227*/ // 4 children in Scope
/*   215*/       OPC_CheckPredicate3,  // Predicate_load
/*   216*/       OPC_CheckPredicate0,  // Predicate_ld_shared
/*   217*/       OPC_EmitMergeInputChains1_0,
/*   218*/       OPC_EmitConvertToTarget2,
/*   219*/       OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
                 // Dst: (LD_SHARED:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   227*/      /*Scope*/ 14, /*->242*/
/*   228*/       OPC_CheckPredicate, 10, // Predicate_extload
/*   230*/       OPC_CheckPredicate6,  // Predicate_extloadi8
/*   231*/       OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*   232*/       OPC_EmitMergeInputChains1_0,
/*   233*/       OPC_EmitConvertToTarget2,
/*   234*/       OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 10
                 // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   242*/      /*Scope*/ 14, /*->257*/
/*   243*/       OPC_CheckPredicate, 11, // Predicate_zextload
/*   245*/       OPC_CheckPredicate6,  // Predicate_zextloadi8
/*   246*/       OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*   247*/       OPC_EmitMergeInputChains1_0,
/*   248*/       OPC_EmitConvertToTarget2,
/*   249*/       OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 10
                 // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   257*/      /*Scope*/ 32, /*->290*/
/*   258*/       OPC_CheckPredicate, 12, // Predicate_sextload
/*   260*/       OPC_CheckPredicate6,  // Predicate_sextloadi8
/*   261*/       OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*   262*/       OPC_EmitMergeInputChains1_0,
/*   263*/       OPC_EmitConvertToTarget2,
/*   264*/       OPC_EmitNode1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*   272*/       OPC_EmitInteger32, 48, 
/*   274*/       OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                     MVT::i32, 2/*#Ops*/, 4, 5,  // Results = #6
/*   281*/       OPC_EmitInteger32, 48, 
/*   283*/       OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::SRAI),
                     MVT::i32, 2/*#Ops*/, 6, 7, 
                 // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 10
                 // Dst: (SRAI:{ *:[i32] } (SHLI:{ *:[i32] } (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off), 24:{ *:[i32] }), 24:{ *:[i32] })
/*   290*/      0, /*End of Scope*/
/*   291*/     /*SwitchType*/ 12, MVT::i16,// ->305
/*   293*/      OPC_CheckPredicate3,  // Predicate_load
/*   294*/      OPC_CheckPredicate0,  // Predicate_ld_shared
/*   295*/      OPC_EmitMergeInputChains1_0,
/*   296*/      OPC_EmitConvertToTarget2,
/*   297*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i16, 2/*#Ops*/, 1, 3, 
                // Src: (ld:{ *:[i16] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
                // Dst: (LD_SHARED_W16:{ *:[i16] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   305*/     0, // EndSwitchType
/*   306*/    /*Scope*/ 114, /*->421*/
/*   307*/     OPC_CheckTypeI32,
/*   308*/     OPC_MoveParent,
/*   309*/     OPC_CheckPredicate5,  // Predicate_unindexedload
/*   310*/     OPC_CheckTypeI32,
/*   311*/     OPC_Scope, 17, /*->330*/ // 4 children in Scope
/*   313*/      OPC_CheckPredicate3,  // Predicate_load
/*   314*/      OPC_CheckPredicate0,  // Predicate_ld_shared
/*   315*/      OPC_EmitMergeInputChains1_0,
/*   316*/      OPC_EmitInteger32, 0, 
/*   318*/      OPC_EmitInteger32, 0, 
/*   320*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 7
                // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   330*/     /*Scope*/ 23, /*->354*/
/*   331*/      OPC_CheckPredicate, 10, // Predicate_extload
/*   333*/      OPC_CheckPredicate6,  // Predicate_extloadi8
/*   334*/      OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*   335*/      OPC_EmitMergeInputChains1_0,
/*   336*/      OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                    MVT::i32, 3/*#Ops*/, 1, 2, 1,  // Results = #3
/*   344*/      OPC_EmitInteger32, 0, 
/*   346*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 2/*#Ops*/, 3, 4, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 7
                // Dst: (LD_SHARED_W8:{ *:[i32] } (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*   354*/     /*Scope*/ 23, /*->378*/
/*   355*/      OPC_CheckPredicate, 11, // Predicate_zextload
/*   357*/      OPC_CheckPredicate6,  // Predicate_zextloadi8
/*   358*/      OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*   359*/      OPC_EmitMergeInputChains1_0,
/*   360*/      OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                    MVT::i32, 3/*#Ops*/, 1, 2, 1,  // Results = #3
/*   368*/      OPC_EmitInteger32, 0, 
/*   370*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 2/*#Ops*/, 3, 4, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 7
                // Dst: (LD_SHARED_W8:{ *:[i32] } (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*   378*/     /*Scope*/ 41, /*->420*/
/*   379*/      OPC_CheckPredicate, 12, // Predicate_sextload
/*   381*/      OPC_CheckPredicate6,  // Predicate_sextloadi8
/*   382*/      OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*   383*/      OPC_EmitMergeInputChains1_0,
/*   384*/      OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                    MVT::i32, 3/*#Ops*/, 1, 2, 1,  // Results = #3
/*   392*/      OPC_EmitInteger32, 0, 
/*   394*/      OPC_EmitNode1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*   402*/      OPC_EmitInteger32, 48, 
/*   404*/      OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                    MVT::i32, 2/*#Ops*/, 5, 6,  // Results = #7
/*   411*/      OPC_EmitInteger32, 48, 
/*   413*/      OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::SRAI),
                    MVT::i32, 2/*#Ops*/, 7, 8, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 7
                // Dst: (SRAI:{ *:[i32] } (SHLI:{ *:[i32] } (LD_SHARED_W8:{ *:[i32] } (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] }), 24:{ *:[i32] }), 24:{ *:[i32] })
/*   420*/     0, /*End of Scope*/
/*   421*/    0, /*End of Scope*/
/*   422*/   0, /*End of Scope*/
/*   423*/  /*Scope*/ 104, /*->528*/
/*   424*/   OPC_RecordChild1, // #1 = $rbase
/*   425*/   OPC_CheckChild1TypeI32,
/*   426*/   OPC_CheckPredicate5,  // Predicate_unindexedload
/*   427*/   OPC_SwitchType /*2 cases */, 82, MVT::i32,// ->512
/*   430*/    OPC_Scope, 13, /*->445*/ // 4 children in Scope
/*   432*/     OPC_CheckPredicate3,  // Predicate_load
/*   433*/     OPC_CheckPredicate0,  // Predicate_ld_shared
/*   434*/     OPC_EmitMergeInputChains1_0,
/*   435*/     OPC_EmitInteger32, 0, 
/*   437*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
               // Dst: (LD_SHARED:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   445*/    /*Scope*/ 15, /*->461*/
/*   446*/     OPC_CheckPredicate, 10, // Predicate_extload
/*   448*/     OPC_CheckPredicate6,  // Predicate_extloadi8
/*   449*/     OPC_CheckPredicate0,  // Predicate_ld_shared_u8
/*   450*/     OPC_EmitMergeInputChains1_0,
/*   451*/     OPC_EmitInteger32, 0, 
/*   453*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>><<P:Predicate_ld_shared_u8>> - Complexity = 4
               // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   461*/    /*Scope*/ 15, /*->477*/
/*   462*/     OPC_CheckPredicate, 11, // Predicate_zextload
/*   464*/     OPC_CheckPredicate6,  // Predicate_zextloadi8
/*   465*/     OPC_CheckPredicate0,  // Predicate_ld_shared_z8
/*   466*/     OPC_EmitMergeInputChains1_0,
/*   467*/     OPC_EmitInteger32, 0, 
/*   469*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>><<P:Predicate_ld_shared_z8>> - Complexity = 4
               // Dst: (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   477*/    /*Scope*/ 33, /*->511*/
/*   478*/     OPC_CheckPredicate, 12, // Predicate_sextload
/*   480*/     OPC_CheckPredicate6,  // Predicate_sextloadi8
/*   481*/     OPC_CheckPredicate0,  // Predicate_ld_shared_s8
/*   482*/     OPC_EmitMergeInputChains1_0,
/*   483*/     OPC_EmitInteger32, 0, 
/*   485*/     OPC_EmitNode1, TARGET_VAL(CCV::LD_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*   493*/     OPC_EmitInteger32, 48, 
/*   495*/     OPC_EmitNode1None, TARGET_VAL(CCV::SHLI),
                   MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*   502*/     OPC_EmitInteger32, 48, 
/*   504*/     OPC_MorphNodeTo1Chain, TARGET_VAL(CCV::SRAI),
                   MVT::i32, 2/*#Ops*/, 5, 6, 
               // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_ld_shared_s8>> - Complexity = 4
               // Dst: (SRAI:{ *:[i32] } (SHLI:{ *:[i32] } (LD_SHARED_W8:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] }), 24:{ *:[i32] }), 24:{ *:[i32] })
/*   511*/    0, /*End of Scope*/
/*   512*/   /*SwitchType*/ 13, MVT::i16,// ->527
/*   514*/    OPC_CheckPredicate3,  // Predicate_load
/*   515*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   516*/    OPC_EmitMergeInputChains1_0,
/*   517*/    OPC_EmitInteger32, 0, 
/*   519*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i16, 2/*#Ops*/, 1, 2, 
              // Src: (ld:{ *:[i16] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
              // Dst: (LD_SHARED_W16:{ *:[i16] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   527*/   0, // EndSwitchType
/*   528*/  /*Scope*/ 123, /*->652*/
/*   529*/   OPC_MoveChild1,
/*   530*/   OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   533*/   OPC_Scope, 32, /*->567*/ // 3 children in Scope
/*   535*/    OPC_RecordChild0, // #1 = $rbase
/*   536*/    OPC_MoveChild1,
/*   537*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   540*/    OPC_RecordChild0, // #2 = $ri
/*   541*/    OPC_CheckChild1Integer, 4, 
/*   543*/    OPC_CheckChild1TypeI32,
/*   544*/    OPC_MoveParent,
/*   545*/    OPC_CheckTypeI32,
/*   546*/    OPC_MoveParent,
/*   547*/    OPC_CheckPredicate5,  // Predicate_unindexedload
/*   548*/    OPC_CheckPredicate3,  // Predicate_load
/*   549*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   550*/    OPC_CheckType, MVT::f32,
/*   552*/    OPC_EmitMergeInputChains1_0,
/*   553*/    OPC_EmitInteger32, 2, 
/*   555*/    OPC_EmitInteger32, 0, 
/*   557*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::f32, 4/*#Ops*/, 1, 2, 3, 4, 
              // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   567*/   /*Scope*/ 32, /*->600*/
/*   568*/    OPC_MoveChild0,
/*   569*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   572*/    OPC_RecordChild0, // #1 = $ri
/*   573*/    OPC_CheckChild1Integer, 4, 
/*   575*/    OPC_CheckChild1TypeI32,
/*   576*/    OPC_MoveParent,
/*   577*/    OPC_RecordChild1, // #2 = $rbase
/*   578*/    OPC_CheckTypeI32,
/*   579*/    OPC_MoveParent,
/*   580*/    OPC_CheckPredicate5,  // Predicate_unindexedload
/*   581*/    OPC_CheckPredicate3,  // Predicate_load
/*   582*/    OPC_CheckPredicate0,  // Predicate_ld_shared
/*   583*/    OPC_CheckType, MVT::f32,
/*   585*/    OPC_EmitMergeInputChains1_0,
/*   586*/    OPC_EmitInteger32, 2, 
/*   588*/    OPC_EmitInteger32, 0, 
/*   590*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::f32, 4/*#Ops*/, 2, 1, 3, 4, 
              // Src: (ld:{ *:[f32] } (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   600*/   /*Scope*/ 50, /*->651*/
/*   601*/    OPC_RecordChild0, // #1 = $rbase
/*   602*/    OPC_RecordChild1, // #2 = $off
/*   603*/    OPC_Scope, 22, /*->627*/ // 2 children in Scope
/*   605*/     OPC_MoveChild1,
/*   606*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   609*/     OPC_MoveParent,
/*   610*/     OPC_CheckTypeI32,
/*   611*/     OPC_MoveParent,
/*   612*/     OPC_CheckPredicate5,  // Predicate_unindexedload
/*   613*/     OPC_CheckPredicate3,  // Predicate_load
/*   614*/     OPC_CheckPredicate0,  // Predicate_ld_shared
/*   615*/     OPC_CheckType, MVT::f32,
/*   617*/     OPC_EmitMergeInputChains1_0,
/*   618*/     OPC_EmitConvertToTarget2,
/*   619*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::f32, 2/*#Ops*/, 1, 3, 
               // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
               // Dst: (LD_SHARED:{ *:[f32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   627*/    /*Scope*/ 22, /*->650*/
/*   628*/     OPC_CheckTypeI32,
/*   629*/     OPC_MoveParent,
/*   630*/     OPC_CheckPredicate5,  // Predicate_unindexedload
/*   631*/     OPC_CheckPredicate3,  // Predicate_load
/*   632*/     OPC_CheckPredicate0,  // Predicate_ld_shared
/*   633*/     OPC_CheckType, MVT::f32,
/*   635*/     OPC_EmitMergeInputChains1_0,
/*   636*/     OPC_EmitInteger32, 0, 
/*   638*/     OPC_EmitInteger32, 0, 
/*   640*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::f32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 7
               // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   650*/    0, /*End of Scope*/
/*   651*/   0, /*End of Scope*/
/*   652*/  /*Scope*/ 18, /*->671*/
/*   653*/   OPC_RecordChild1, // #1 = $rbase
/*   654*/   OPC_CheckChild1TypeI32,
/*   655*/   OPC_CheckPredicate5,  // Predicate_unindexedload
/*   656*/   OPC_CheckPredicate3,  // Predicate_load
/*   657*/   OPC_CheckPredicate0,  // Predicate_ld_shared
/*   658*/   OPC_CheckType, MVT::f32,
/*   660*/   OPC_EmitMergeInputChains1_0,
/*   661*/   OPC_EmitInteger32, 0, 
/*   663*/   OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                 MVT::f32, 2/*#Ops*/, 1, 2, 
             // Src: (ld:{ *:[f32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
             // Dst: (LD_SHARED:{ *:[f32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   671*/  0, /*End of Scope*/
/*   672*/ /*SwitchOpcode*/ 12|128,4/*524*/, TARGET_VAL(ISD::STORE),// ->1200
/*   676*/  OPC_RecordMemRef,
/*   677*/  OPC_RecordNode, // #0 = 'st' chained node
/*   678*/  OPC_RecordChild1, // #1 = $v
/*   679*/  OPC_Scope, 103|128,1/*231*/, /*->913*/ // 3 children in Scope
/*   682*/   OPC_CheckChild1TypeI32,
/*   683*/   OPC_Scope, 52|128,1/*180*/, /*->866*/ // 2 children in Scope
/*   686*/    OPC_MoveChild2,
/*   687*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   690*/    OPC_Scope, 30, /*->722*/ // 3 children in Scope
/*   692*/     OPC_RecordChild0, // #2 = $rbase
/*   693*/     OPC_MoveChild1,
/*   694*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   697*/     OPC_RecordChild0, // #3 = $ri
/*   698*/     OPC_CheckChild1Integer, 4, 
/*   700*/     OPC_CheckChild1TypeI32,
/*   701*/     OPC_MoveParent,
/*   702*/     OPC_CheckTypeI32,
/*   703*/     OPC_MoveParent,
/*   704*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   705*/     OPC_CheckPredicate4,  // Predicate_store
/*   706*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*   707*/     OPC_EmitMergeInputChains1_0,
/*   708*/     OPC_EmitInteger32, 2, 
/*   710*/     OPC_EmitInteger32, 0, 
/*   712*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   722*/    /*Scope*/ 30, /*->753*/
/*   723*/     OPC_MoveChild0,
/*   724*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   727*/     OPC_RecordChild0, // #2 = $ri
/*   728*/     OPC_CheckChild1Integer, 4, 
/*   730*/     OPC_CheckChild1TypeI32,
/*   731*/     OPC_MoveParent,
/*   732*/     OPC_RecordChild1, // #3 = $rbase
/*   733*/     OPC_CheckTypeI32,
/*   734*/     OPC_MoveParent,
/*   735*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   736*/     OPC_CheckPredicate4,  // Predicate_store
/*   737*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*   738*/     OPC_EmitMergeInputChains1_0,
/*   739*/     OPC_EmitInteger32, 2, 
/*   741*/     OPC_EmitInteger32, 0, 
/*   743*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 3, 2, 4, 5, 
               // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   753*/    /*Scope*/ 111, /*->865*/
/*   754*/     OPC_RecordChild0, // #2 = $rbase
/*   755*/     OPC_RecordChild1, // #3 = $off
/*   756*/     OPC_Scope, 48, /*->806*/ // 2 children in Scope
/*   758*/      OPC_MoveChild1,
/*   759*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   762*/      OPC_MoveParent,
/*   763*/      OPC_CheckTypeI32,
/*   764*/      OPC_MoveParent,
/*   765*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   766*/      OPC_Scope, 12, /*->780*/ // 2 children in Scope
/*   768*/       OPC_CheckPredicate4,  // Predicate_store
/*   769*/       OPC_CheckPredicate1,  // Predicate_st_shared
/*   770*/       OPC_EmitMergeInputChains1_0,
/*   771*/       OPC_EmitConvertToTarget3,
/*   772*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                     3/*#Ops*/, 1, 2, 4, 
                 // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                 // Dst: (ST_SHARED GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   780*/      /*Scope*/ 24, /*->805*/
/*   781*/       OPC_CheckPredicate, 8, // Predicate_truncstore
/*   783*/       OPC_CheckPredicate, 9, // Predicate_truncstorei8
/*   785*/       OPC_CheckPredicate1,  // Predicate_st_shared_8
/*   786*/       OPC_EmitMergeInputChains1_0,
/*   787*/       OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*   789*/       OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                     MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*   796*/       OPC_EmitConvertToTarget3,
/*   797*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     3/*#Ops*/, 5, 2, 6, 
                 // Src: (st GPR:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 10
                 // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR:{ *:[i32] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   805*/      0, /*End of Scope*/
/*   806*/     /*Scope*/ 57, /*->864*/
/*   807*/      OPC_CheckTypeI32,
/*   808*/      OPC_MoveParent,
/*   809*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   810*/      OPC_Scope, 17, /*->829*/ // 2 children in Scope
/*   812*/       OPC_CheckPredicate4,  // Predicate_store
/*   813*/       OPC_CheckPredicate1,  // Predicate_st_shared
/*   814*/       OPC_EmitMergeInputChains1_0,
/*   815*/       OPC_EmitInteger32, 0, 
/*   817*/       OPC_EmitInteger32, 0, 
/*   819*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                     5/*#Ops*/, 1, 2, 3, 4, 5, 
                 // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 7
                 // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   829*/      /*Scope*/ 33, /*->863*/
/*   830*/       OPC_CheckPredicate, 8, // Predicate_truncstore
/*   832*/       OPC_CheckPredicate, 9, // Predicate_truncstorei8
/*   834*/       OPC_CheckPredicate1,  // Predicate_st_shared_8
/*   835*/       OPC_EmitMergeInputChains1_0,
/*   836*/       OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*   838*/       OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                     MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*   845*/       OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                     MVT::i32, 3/*#Ops*/, 2, 3, 2,  // Results = #6
/*   853*/       OPC_EmitInteger32, 0, 
/*   855*/       OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                     3/*#Ops*/, 5, 6, 7, 
                 // Src: (st GPR:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 7
                 // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR:{ *:[i32] }:$v, GPR8:{ *:[i32] }), (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*   863*/      0, /*End of Scope*/
/*   864*/     0, /*End of Scope*/
/*   865*/    0, /*End of Scope*/
/*   866*/   /*Scope*/ 45, /*->912*/
/*   867*/    OPC_RecordChild2, // #2 = $rbase
/*   868*/    OPC_CheckChild2TypeI32,
/*   869*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   870*/    OPC_Scope, 13, /*->885*/ // 2 children in Scope
/*   872*/     OPC_CheckPredicate4,  // Predicate_store
/*   873*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*   874*/     OPC_EmitMergeInputChains1_0,
/*   875*/     OPC_EmitInteger32, 0, 
/*   877*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 1, 2, 3, 
               // Src: (st i32:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
               // Dst: (ST_SHARED GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   885*/    /*Scope*/ 25, /*->911*/
/*   886*/     OPC_CheckPredicate, 8, // Predicate_truncstore
/*   888*/     OPC_CheckPredicate, 9, // Predicate_truncstorei8
/*   890*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*   891*/     OPC_EmitMergeInputChains1_0,
/*   892*/     OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*   894*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*   901*/     OPC_EmitInteger32, 0, 
/*   903*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 4, 2, 5, 
               // Src: (st GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 4
               // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR:{ *:[i32] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   911*/    0, /*End of Scope*/
/*   912*/   0, /*End of Scope*/
/*   913*/  /*Scope*/ 9|128,1/*137*/, /*->1052*/
/*   915*/   OPC_CheckChild1Type, MVT::f32,
/*   917*/   OPC_Scope, 115, /*->1034*/ // 2 children in Scope
/*   919*/    OPC_MoveChild2,
/*   920*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   923*/    OPC_Scope, 30, /*->955*/ // 3 children in Scope
/*   925*/     OPC_RecordChild0, // #2 = $rbase
/*   926*/     OPC_MoveChild1,
/*   927*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   930*/     OPC_RecordChild0, // #3 = $ri
/*   931*/     OPC_CheckChild1Integer, 4, 
/*   933*/     OPC_CheckChild1TypeI32,
/*   934*/     OPC_MoveParent,
/*   935*/     OPC_CheckTypeI32,
/*   936*/     OPC_MoveParent,
/*   937*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   938*/     OPC_CheckPredicate4,  // Predicate_store
/*   939*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*   940*/     OPC_EmitMergeInputChains1_0,
/*   941*/     OPC_EmitInteger32, 2, 
/*   943*/     OPC_EmitInteger32, 0, 
/*   945*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   955*/    /*Scope*/ 30, /*->986*/
/*   956*/     OPC_MoveChild0,
/*   957*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   960*/     OPC_RecordChild0, // #2 = $ri
/*   961*/     OPC_CheckChild1Integer, 4, 
/*   963*/     OPC_CheckChild1TypeI32,
/*   964*/     OPC_MoveParent,
/*   965*/     OPC_RecordChild1, // #3 = $rbase
/*   966*/     OPC_CheckTypeI32,
/*   967*/     OPC_MoveParent,
/*   968*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   969*/     OPC_CheckPredicate4,  // Predicate_store
/*   970*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*   971*/     OPC_EmitMergeInputChains1_0,
/*   972*/     OPC_EmitInteger32, 2, 
/*   974*/     OPC_EmitInteger32, 0, 
/*   976*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 3, 2, 4, 5, 
               // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   986*/    /*Scope*/ 46, /*->1033*/
/*   987*/     OPC_RecordChild0, // #2 = $rbase
/*   988*/     OPC_RecordChild1, // #3 = $off
/*   989*/     OPC_Scope, 20, /*->1011*/ // 2 children in Scope
/*   991*/      OPC_MoveChild1,
/*   992*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   995*/      OPC_MoveParent,
/*   996*/      OPC_CheckTypeI32,
/*   997*/      OPC_MoveParent,
/*   998*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*   999*/      OPC_CheckPredicate4,  // Predicate_store
/*  1000*/      OPC_CheckPredicate1,  // Predicate_st_shared
/*  1001*/      OPC_EmitMergeInputChains1_0,
/*  1002*/      OPC_EmitConvertToTarget3,
/*  1003*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 1, 2, 4, 
                // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                // Dst: (ST_SHARED GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1011*/     /*Scope*/ 20, /*->1032*/
/*  1012*/      OPC_CheckTypeI32,
/*  1013*/      OPC_MoveParent,
/*  1014*/      OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1015*/      OPC_CheckPredicate4,  // Predicate_store
/*  1016*/      OPC_CheckPredicate1,  // Predicate_st_shared
/*  1017*/      OPC_EmitMergeInputChains1_0,
/*  1018*/      OPC_EmitInteger32, 0, 
/*  1020*/      OPC_EmitInteger32, 0, 
/*  1022*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                    5/*#Ops*/, 1, 2, 3, 4, 5, 
                // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 7
                // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*  1032*/     0, /*End of Scope*/
/*  1033*/    0, /*End of Scope*/
/*  1034*/   /*Scope*/ 16, /*->1051*/
/*  1035*/    OPC_RecordChild2, // #2 = $rbase
/*  1036*/    OPC_CheckChild2TypeI32,
/*  1037*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1038*/    OPC_CheckPredicate4,  // Predicate_store
/*  1039*/    OPC_CheckPredicate1,  // Predicate_st_shared
/*  1040*/    OPC_EmitMergeInputChains1_0,
/*  1041*/    OPC_EmitInteger32, 0, 
/*  1043*/    OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                  3/*#Ops*/, 1, 2, 3, 
              // Src: (st f32:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
              // Dst: (ST_SHARED GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1051*/   0, /*End of Scope*/
/*  1052*/  /*Scope*/ 17|128,1/*145*/, /*->1199*/
/*  1054*/   OPC_CheckChild1Type, MVT::i16,
/*  1056*/   OPC_Scope, 94, /*->1152*/ // 2 children in Scope
/*  1058*/    OPC_MoveChild2,
/*  1059*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*  1062*/    OPC_RecordChild0, // #2 = $rbase
/*  1063*/    OPC_RecordChild1, // #3 = $off
/*  1064*/    OPC_Scope, 48, /*->1114*/ // 2 children in Scope
/*  1066*/     OPC_MoveChild1,
/*  1067*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1070*/     OPC_MoveParent,
/*  1071*/     OPC_CheckTypeI32,
/*  1072*/     OPC_MoveParent,
/*  1073*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1074*/     OPC_Scope, 12, /*->1088*/ // 2 children in Scope
/*  1076*/      OPC_CheckPredicate4,  // Predicate_store
/*  1077*/      OPC_CheckPredicate1,  // Predicate_st_shared
/*  1078*/      OPC_EmitMergeInputChains1_0,
/*  1079*/      OPC_EmitConvertToTarget3,
/*  1080*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 1, 2, 4, 
                // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                // Dst: (ST_SHARED_W16 GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1088*/     /*Scope*/ 24, /*->1113*/
/*  1089*/      OPC_CheckPredicate, 8, // Predicate_truncstore
/*  1091*/      OPC_CheckPredicate, 9, // Predicate_truncstorei8
/*  1093*/      OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1094*/      OPC_EmitMergeInputChains1_0,
/*  1095*/      OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1097*/      OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                    MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1104*/      OPC_EmitConvertToTarget3,
/*  1105*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 5, 2, 6, 
                // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 10
                // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*  1113*/     0, /*End of Scope*/
/*  1114*/    /*Scope*/ 36, /*->1151*/
/*  1115*/     OPC_CheckTypeI32,
/*  1116*/     OPC_MoveParent,
/*  1117*/     OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1118*/     OPC_CheckPredicate, 8, // Predicate_truncstore
/*  1120*/     OPC_CheckPredicate, 9, // Predicate_truncstorei8
/*  1122*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1123*/     OPC_EmitMergeInputChains1_0,
/*  1124*/     OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1126*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*  1133*/     OPC_EmitNode1None, TARGET_VAL(CCV::ADD),
                   MVT::i32, 3/*#Ops*/, 2, 3, 2,  // Results = #6
/*  1141*/     OPC_EmitInteger32, 0, 
/*  1143*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 5, 6, 7, 
               // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 7
               // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR8:{ *:[i32] }), (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, GPR:{ *:[i32] }:$rbase), 0:{ *:[i32] })
/*  1151*/    0, /*End of Scope*/
/*  1152*/   /*Scope*/ 45, /*->1198*/
/*  1153*/    OPC_RecordChild2, // #2 = $rbase
/*  1154*/    OPC_CheckChild2TypeI32,
/*  1155*/    OPC_CheckPredicate2,  // Predicate_unindexedstore
/*  1156*/    OPC_Scope, 13, /*->1171*/ // 2 children in Scope
/*  1158*/     OPC_CheckPredicate4,  // Predicate_store
/*  1159*/     OPC_CheckPredicate1,  // Predicate_st_shared
/*  1160*/     OPC_EmitMergeInputChains1_0,
/*  1161*/     OPC_EmitInteger32, 0, 
/*  1163*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 1, 2, 3, 
               // Src: (st GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
               // Dst: (ST_SHARED_W16 GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1171*/    /*Scope*/ 25, /*->1197*/
/*  1172*/     OPC_CheckPredicate, 8, // Predicate_truncstore
/*  1174*/     OPC_CheckPredicate, 9, // Predicate_truncstorei8
/*  1176*/     OPC_CheckPredicate1,  // Predicate_st_shared_8
/*  1177*/     OPC_EmitMergeInputChains1_0,
/*  1178*/     OPC_EmitStringInteger32, CCV::GPR8RegClassID,
/*  1180*/     OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                   MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*  1187*/     OPC_EmitInteger32, 0, 
/*  1189*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W8), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, 4, 2, 5, 
               // Src: (st GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_st_shared_8>> - Complexity = 4
               // Dst: (ST_SHARED_W8 (COPY_TO_REGCLASS:{ *:[i32] } GPR16:{ *:[i16] }:$v, GPR8:{ *:[i32] }), GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*  1197*/    0, /*End of Scope*/
/*  1198*/   0, /*End of Scope*/
/*  1199*/  0, /*End of Scope*/
/*  1200*/ /*SwitchOpcode*/ 76, TARGET_VAL(ISD::Constant),// ->1279
/*  1203*/  OPC_Scope, 11, /*->1216*/ // 4 children in Scope
/*  1205*/   OPC_RecordNode, // #0 = $i
/*  1206*/   OPC_CheckPredicate, 16, // Predicate_uimm17_imm
/*  1208*/   OPC_CheckTypeI32,
/*  1209*/   OPC_EmitConvertToTarget0,
/*  1210*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                 MVT::i32, 1/*#Ops*/, 1, 
             // Src: (imm:{ *:[i32] })<<P:Predicate_uimm17_imm>>:$i - Complexity = 14
             // Dst: (MOVI:{ *:[i32] } (imm:{ *:[i32] }):$i)
/*  1216*/  /*Scope*/ 16, /*->1233*/
/*  1217*/   OPC_CheckInteger, 3, 
/*  1219*/   OPC_CheckType, MVT::i1,
/*  1221*/   OPC_EmitInteger32, 126|128,127|128,127|128,127|128,31/*8589934590*/, 
/*  1227*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                 MVT::i1, 1/*#Ops*/, 0, 
             // Src: -1:{ *:[i1] } - Complexity = 5
             // Dst: (PMOV_IMM:{ *:[i1] } 4294967295:{ *:[i32] })
/*  1233*/  /*Scope*/ 12, /*->1246*/
/*  1234*/   OPC_CheckInteger, 0, 
/*  1236*/   OPC_CheckType, MVT::i1,
/*  1238*/   OPC_EmitInteger32, 0, 
/*  1240*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                 MVT::i1, 1/*#Ops*/, 0, 
             // Src: 0:{ *:[i1] } - Complexity = 5
             // Dst: (PMOV_IMM:{ *:[i1] } 0:{ *:[i32] })
/*  1246*/  /*Scope*/ 31, /*->1278*/
/*  1247*/   OPC_RecordNode, // #0 = $i
/*  1248*/   OPC_SwitchType /*2 cases */, 9, MVT::i32,// ->1260
/*  1251*/    OPC_EmitNodeXForm, 1, 0, // imm_bits32
/*  1254*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                  MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:{ *:[i32] }):$i - Complexity = 3
              // Dst: (MOVI48:{ *:[i32] } (imm_bits32:{ *:[i32] } ?:{ *:[i32] }:$i))
/*  1260*/   /*SwitchType*/ 15, MVT::i16,// ->1277
/*  1262*/    OPC_EmitNodeXForm, 2, 0, // imm16_bits
/*  1265*/    OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                  MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*  1271*/    OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                  MVT::i16, 1/*#Ops*/, 2, 
              // Src: (imm:{ *:[i16] }):$i - Complexity = 3
              // Dst: (COPY:{ *:[i16] } (MOVI:{ *:[i32] } (imm16_bits:{ *:[i32] } ?:{ *:[i16] }:$i)))
/*  1277*/   0, // EndSwitchType
/*  1278*/  0, /*End of Scope*/
/*  1279*/ /*SwitchOpcode*/ 110, TARGET_VAL(ISD::AND),// ->1392
/*  1282*/  OPC_Scope, 18, /*->1302*/ // 3 children in Scope
/*  1284*/   OPC_RecordChild0, // #0 = $a
/*  1285*/   OPC_MoveChild1,
/*  1286*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*  1289*/   OPC_RecordChild0, // #1 = $b
/*  1290*/   OPC_CheckChild1Integer, 3, 
/*  1292*/   OPC_MoveParent,
/*  1293*/   OPC_CheckTypeI32,
/*  1294*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] })) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1302*/  /*Scope*/ 18, /*->1321*/
/*  1303*/   OPC_MoveChild0,
/*  1304*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*  1307*/   OPC_RecordChild0, // #0 = $b
/*  1308*/   OPC_CheckChild1Integer, 3, 
/*  1310*/   OPC_MoveParent,
/*  1311*/   OPC_RecordChild1, // #1 = $a
/*  1312*/   OPC_CheckTypeI32,
/*  1313*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 1, 0, 1, 
             // Src: (and:{ *:[i32] } (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] }), GPR:{ *:[i32] }:$a) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1321*/  /*Scope*/ 69, /*->1391*/
/*  1322*/   OPC_RecordChild0, // #0 = $a
/*  1323*/   OPC_RecordChild1, // #1 = $i
/*  1324*/   OPC_Scope, 33, /*->1359*/ // 4 children in Scope
/*  1326*/    OPC_MoveChild1,
/*  1327*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1330*/    OPC_Scope, 14, /*->1346*/ // 2 children in Scope
/*  1332*/     OPC_CheckPredicate, 17, // Predicate_simm13_not_imm
/*  1334*/     OPC_MoveParent,
/*  1335*/     OPC_CheckTypeI32,
/*  1336*/     OPC_EmitNodeXForm, 3, 1, // imm_not
/*  1339*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDNI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_not_imm>>:$i) - Complexity = 7
               // Dst: (ANDNI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm_not:{ *:[i32] } ?:{ *:[i32] }:$i))
/*  1346*/    /*Scope*/ 11, /*->1358*/
/*  1347*/     OPC_CheckPredicate7,  // Predicate_simm13_imm
/*  1348*/     OPC_MoveParent,
/*  1349*/     OPC_CheckTypeI32,
/*  1350*/     OPC_EmitConvertToTarget1,
/*  1351*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
               // Dst: (ANDI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1358*/    0, /*End of Scope*/
/*  1359*/   /*Scope*/ 9, /*->1369*/
/*  1360*/    OPC_CheckTypeI32,
/*  1361*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (AND:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1369*/   /*Scope*/ 9, /*->1379*/
/*  1370*/    OPC_CheckType, MVT::i1,
/*  1372*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PAND),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (and:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PAND:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  1379*/   /*Scope*/ 10, /*->1390*/
/*  1380*/    OPC_CheckType, MVT::i16,
/*  1382*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (AND_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1390*/   0, /*End of Scope*/
/*  1391*/  0, /*End of Scope*/
/*  1392*/ /*SwitchOpcode*/ 20, TARGET_VAL(ISD::CALLSEQ_START),// ->1415
/*  1395*/  OPC_RecordNode, // #0 = 'callseq_start' chained node
/*  1396*/  OPC_RecordChild1, // #1 = $a
/*  1397*/  OPC_MoveChild1,
/*  1398*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  1401*/  OPC_MoveSibling2,
/*  1402*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  1405*/  OPC_RecordNode, // #2 = $b
/*  1406*/  OPC_MoveParent,
/*  1407*/  OPC_EmitMergeInputChains1_0,
/*  1408*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                2/*#Ops*/, 1, 2, 
            // Src: (callseq_start (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b) - Complexity = 9
            // Dst: (ADJCALLSTACKDOWN (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b)
/*  1415*/ /*SwitchOpcode*/ 21, TARGET_VAL(ISD::CALLSEQ_END),// ->1439
/*  1418*/  OPC_RecordNode, // #0 = 'callseq_end' chained node
/*  1419*/  OPC_CaptureGlueInput,
/*  1420*/  OPC_RecordChild1, // #1 = $a
/*  1421*/  OPC_MoveChild1,
/*  1422*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  1425*/  OPC_MoveSibling2,
/*  1426*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  1429*/  OPC_RecordNode, // #2 = $b
/*  1430*/  OPC_MoveParent,
/*  1431*/  OPC_EmitMergeInputChains1_0,
/*  1432*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b) - Complexity = 9
            // Dst: (ADJCALLSTACKUP (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b)
/*  1439*/ /*SwitchOpcode*/ 57, TARGET_VAL(ISD::SUB),// ->1499
/*  1442*/  OPC_Scope, 12, /*->1456*/ // 2 children in Scope
/*  1444*/   OPC_CheckChild0Integer, 0, 
/*  1446*/   OPC_RecordChild1, // #0 = $a
/*  1447*/   OPC_CheckTypeI32,
/*  1448*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::NEG),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (sub:{ *:[i32] } 0:{ *:[i32] }, GPR:{ *:[i32] }:$a) - Complexity = 8
             // Dst: (NEG:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1456*/  /*Scope*/ 41, /*->1498*/
/*  1457*/   OPC_RecordChild0, // #0 = $a
/*  1458*/   OPC_RecordChild1, // #1 = $i
/*  1459*/   OPC_Scope, 15, /*->1476*/ // 3 children in Scope
/*  1461*/    OPC_MoveChild1,
/*  1462*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1465*/    OPC_CheckPredicate7,  // Predicate_simm13_imm
/*  1466*/    OPC_MoveParent,
/*  1467*/    OPC_CheckTypeI32,
/*  1468*/    OPC_EmitConvertToTarget1,
/*  1469*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUBI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (SUBI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1476*/   /*Scope*/ 9, /*->1486*/
/*  1477*/    OPC_CheckTypeI32,
/*  1478*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (SUB:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1486*/   /*Scope*/ 10, /*->1497*/
/*  1487*/    OPC_CheckType, MVT::i16,
/*  1489*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (SUB_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1497*/   0, /*End of Scope*/
/*  1498*/  0, /*End of Scope*/
/*  1499*/ /*SwitchOpcode*/ 64, TARGET_VAL(ISD::XOR),// ->1566
/*  1502*/  OPC_RecordChild0, // #0 = $a
/*  1503*/  OPC_Scope, 9, /*->1514*/ // 2 children in Scope
/*  1505*/   OPC_CheckChild1Integer, 3, 
/*  1507*/   OPC_CheckTypeI32,
/*  1508*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_NOT),
                 MVT::i32, 1/*#Ops*/, 0, 
             // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, -1:{ *:[i32] }) - Complexity = 8
             // Dst: (C_NOT:{ *:[i32] } GPR:{ *:[i32] }:$a)
/*  1514*/  /*Scope*/ 50, /*->1565*/
/*  1515*/   OPC_RecordChild1, // #1 = $i
/*  1516*/   OPC_Scope, 15, /*->1533*/ // 4 children in Scope
/*  1518*/    OPC_MoveChild1,
/*  1519*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1522*/    OPC_CheckPredicate7,  // Predicate_simm13_imm
/*  1523*/    OPC_MoveParent,
/*  1524*/    OPC_CheckTypeI32,
/*  1525*/    OPC_EmitConvertToTarget1,
/*  1526*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XORI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (XORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1533*/   /*Scope*/ 9, /*->1543*/
/*  1534*/    OPC_CheckTypeI32,
/*  1535*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (XOR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1543*/   /*Scope*/ 9, /*->1553*/
/*  1544*/    OPC_CheckType, MVT::i1,
/*  1546*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PXOR),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (xor:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PXOR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  1553*/   /*Scope*/ 10, /*->1564*/
/*  1554*/    OPC_CheckType, MVT::i16,
/*  1556*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (XOR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1564*/   0, /*End of Scope*/
/*  1565*/  0, /*End of Scope*/
/*  1566*/ /*SwitchOpcode*/ 49, TARGET_VAL(ISD::SHL),// ->1618
/*  1569*/  OPC_RecordChild0, // #0 = $a
/*  1570*/  OPC_RecordChild1, // #1 = $i
/*  1571*/  OPC_Scope, 33, /*->1606*/ // 2 children in Scope
/*  1573*/   OPC_MoveChild1,
/*  1574*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1577*/   OPC_CheckTypeI32,
/*  1578*/   OPC_Scope, 12, /*->1592*/ // 2 children in Scope
/*  1580*/    OPC_CheckPredicate, 13, // Predicate_uimm4_imm
/*  1582*/    OPC_MoveParent,
/*  1583*/    OPC_CheckTypeI32,
/*  1584*/    OPC_EmitConvertToTarget1,
/*  1585*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHLI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1592*/   /*Scope*/ 12, /*->1605*/
/*  1593*/    OPC_CheckPredicate, 14, // Predicate_uimm5_imm
/*  1595*/    OPC_MoveParent,
/*  1596*/    OPC_CheckTypeI32,
/*  1597*/    OPC_EmitConvertToTarget1,
/*  1598*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHLI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1605*/   0, /*End of Scope*/
/*  1606*/  /*Scope*/ 10, /*->1617*/
/*  1607*/   OPC_CheckChild1TypeI32,
/*  1608*/   OPC_CheckTypeI32,
/*  1609*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHL),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SHL:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1617*/  0, /*End of Scope*/
/*  1618*/ /*SwitchOpcode*/ 49, TARGET_VAL(ISD::SRL),// ->1670
/*  1621*/  OPC_RecordChild0, // #0 = $a
/*  1622*/  OPC_RecordChild1, // #1 = $i
/*  1623*/  OPC_Scope, 33, /*->1658*/ // 2 children in Scope
/*  1625*/   OPC_MoveChild1,
/*  1626*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1629*/   OPC_CheckTypeI32,
/*  1630*/   OPC_Scope, 12, /*->1644*/ // 2 children in Scope
/*  1632*/    OPC_CheckPredicate, 13, // Predicate_uimm4_imm
/*  1634*/    OPC_MoveParent,
/*  1635*/    OPC_CheckTypeI32,
/*  1636*/    OPC_EmitConvertToTarget1,
/*  1637*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHRI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1644*/   /*Scope*/ 12, /*->1657*/
/*  1645*/    OPC_CheckPredicate, 14, // Predicate_uimm5_imm
/*  1647*/    OPC_MoveParent,
/*  1648*/    OPC_CheckTypeI32,
/*  1649*/    OPC_EmitConvertToTarget1,
/*  1650*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHRI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1657*/   0, /*End of Scope*/
/*  1658*/  /*Scope*/ 10, /*->1669*/
/*  1659*/   OPC_CheckChild1TypeI32,
/*  1660*/   OPC_CheckTypeI32,
/*  1661*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHR),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SHR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1669*/  0, /*End of Scope*/
/*  1670*/ /*SwitchOpcode*/ 49, TARGET_VAL(ISD::SRA),// ->1722
/*  1673*/  OPC_RecordChild0, // #0 = $a
/*  1674*/  OPC_RecordChild1, // #1 = $i
/*  1675*/  OPC_Scope, 33, /*->1710*/ // 2 children in Scope
/*  1677*/   OPC_MoveChild1,
/*  1678*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1681*/   OPC_CheckTypeI32,
/*  1682*/   OPC_Scope, 12, /*->1696*/ // 2 children in Scope
/*  1684*/    OPC_CheckPredicate, 13, // Predicate_uimm4_imm
/*  1686*/    OPC_MoveParent,
/*  1687*/    OPC_CheckTypeI32,
/*  1688*/    OPC_EmitConvertToTarget1,
/*  1689*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SRAI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1696*/   /*Scope*/ 12, /*->1709*/
/*  1697*/    OPC_CheckPredicate, 14, // Predicate_uimm5_imm
/*  1699*/    OPC_MoveParent,
/*  1700*/    OPC_CheckTypeI32,
/*  1701*/    OPC_EmitConvertToTarget1,
/*  1702*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRAI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1709*/   0, /*End of Scope*/
/*  1710*/  /*Scope*/ 10, /*->1721*/
/*  1711*/   OPC_CheckChild1TypeI32,
/*  1712*/   OPC_CheckTypeI32,
/*  1713*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRA),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SRA:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1721*/  0, /*End of Scope*/
/*  1722*/ /*SwitchOpcode*/ 30, TARGET_VAL(ISD::MUL),// ->1755
/*  1725*/  OPC_RecordChild0, // #0 = $a
/*  1726*/  OPC_RecordChild1, // #1 = $i
/*  1727*/  OPC_Scope, 15, /*->1744*/ // 2 children in Scope
/*  1729*/   OPC_MoveChild1,
/*  1730*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1733*/   OPC_CheckPredicate7,  // Predicate_simm13_imm
/*  1734*/   OPC_MoveParent,
/*  1735*/   OPC_CheckTypeI32,
/*  1736*/   OPC_EmitConvertToTarget1,
/*  1737*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MULI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (MULI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1744*/  /*Scope*/ 9, /*->1754*/
/*  1745*/   OPC_CheckTypeI32,
/*  1746*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_LO),
                 MVT::i32, 3/*#Ops*/, 0, 1, 1, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MUL_LO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$b)
/*  1754*/  0, /*End of Scope*/
/*  1755*/ /*SwitchOpcode*/ 51, TARGET_VAL(ISD::OR),// ->1809
/*  1758*/  OPC_RecordChild0, // #0 = $a
/*  1759*/  OPC_RecordChild1, // #1 = $i
/*  1760*/  OPC_Scope, 15, /*->1777*/ // 4 children in Scope
/*  1762*/   OPC_MoveChild1,
/*  1763*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1766*/   OPC_CheckPredicate7,  // Predicate_simm13_imm
/*  1767*/   OPC_MoveParent,
/*  1768*/   OPC_CheckTypeI32,
/*  1769*/   OPC_EmitConvertToTarget1,
/*  1770*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ORI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (ORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1777*/  /*Scope*/ 9, /*->1787*/
/*  1778*/   OPC_CheckTypeI32,
/*  1779*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (OR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1787*/  /*Scope*/ 9, /*->1797*/
/*  1788*/   OPC_CheckType, MVT::i1,
/*  1790*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_POR),
                 MVT::i1, 2/*#Ops*/, 0, 1, 
             // Src: (or:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
             // Dst: (PSEUDO_POR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  1797*/  /*Scope*/ 10, /*->1808*/
/*  1798*/   OPC_CheckType, MVT::i16,
/*  1800*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (OR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1808*/  0, /*End of Scope*/
/*  1809*/ /*SwitchOpcode*/ 15, TARGET_VAL(CCVISD::CALL),// ->1827
/*  1812*/  OPC_RecordNode, // #0 = 'ccv_call' chained node
/*  1813*/  OPC_CaptureGlueInput,
/*  1814*/  OPC_RecordChild1, // #1 = $f
/*  1815*/  OPC_MoveChild1,
/*  1816*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*  1819*/  OPC_MoveParent,
/*  1820*/  OPC_EmitMergeInputChains1_0,
/*  1821*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::PSEUDO_CALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                1/*#Ops*/, 1, 
            // Src: (ccv_call (tglobaladdr:{ *:[i32] }):$f) - Complexity = 6
            // Dst: (PSEUDO_CALL (tglobaladdr:{ *:[i32] }):$f)
/*  1827*/ /*SwitchOpcode*/ 16, TARGET_VAL(ISD::BITCAST),// ->1846
/*  1830*/  OPC_RecordChild0, // #0 = $a
/*  1831*/  OPC_SwitchType /*2 cases */, 5, MVT::i32,// ->1839
/*  1834*/   OPC_CheckChild0Type, MVT::f32,
/*  1836*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[i32] }:$a
/*  1839*/  /*SwitchType*/ 4, MVT::f32,// ->1845
/*  1841*/   OPC_CheckChild0TypeI32,
/*  1842*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[f32] }:$a
/*  1845*/  0, // EndSwitchType
/*  1846*/ /*SwitchOpcode*/ 13, TARGET_VAL(ISD::BR),// ->1862
/*  1849*/  OPC_RecordNode, // #0 = 'br' chained node
/*  1850*/  OPC_RecordChild1, // #1 = $t
/*  1851*/  OPC_MoveChild1,
/*  1852*/  OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*  1855*/  OPC_MoveParent,
/*  1856*/  OPC_EmitMergeInputChains1_0,
/*  1857*/  OPC_MorphNodeTo0Chain, TARGET_VAL(CCV::C_BRA),
                1/*#Ops*/, 1, 
            // Src: (br (bb:{ *:[Other] }):$t) - Complexity = 3
            // Dst: (C_BRA (bb:{ *:[Other] }):$t)
/*  1862*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMIN),// ->1889
/*  1865*/  OPC_RecordChild0, // #0 = $a
/*  1866*/  OPC_RecordChild1, // #1 = $b
/*  1867*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->1878
/*  1870*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MIN_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1878*/  /*SwitchType*/ 8, MVT::i16,// ->1888
/*  1880*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MIN_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1888*/  0, // EndSwitchType
/*  1889*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMIN),// ->1903
/*  1892*/  OPC_RecordChild0, // #0 = $a
/*  1893*/  OPC_RecordChild1, // #1 = $b
/*  1894*/  OPC_CheckTypeI32,
/*  1895*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MIN_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1903*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMAX),// ->1930
/*  1906*/  OPC_RecordChild0, // #0 = $a
/*  1907*/  OPC_RecordChild1, // #1 = $b
/*  1908*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->1919
/*  1911*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MAX_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1919*/  /*SwitchType*/ 8, MVT::i16,// ->1929
/*  1921*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MAX_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1929*/  0, // EndSwitchType
/*  1930*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMAX),// ->1944
/*  1933*/  OPC_RecordChild0, // #0 = $a
/*  1934*/  OPC_RecordChild1, // #1 = $b
/*  1935*/  OPC_CheckTypeI32,
/*  1936*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MAX_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1944*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHS),// ->1958
/*  1947*/  OPC_RecordChild0, // #0 = $a
/*  1948*/  OPC_RecordChild1, // #1 = $b
/*  1949*/  OPC_CheckTypeI32,
/*  1950*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_S),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhs:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1958*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHU),// ->1972
/*  1961*/  OPC_RecordChild0, // #0 = $a
/*  1962*/  OPC_RecordChild1, // #1 = $b
/*  1963*/  OPC_CheckTypeI32,
/*  1964*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhu:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1972*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTPOP),// ->1986
/*  1975*/  OPC_RecordChild0, // #0 = $a
/*  1976*/  OPC_CheckChild0TypeI32,
/*  1977*/  OPC_CheckTypeI32,
/*  1978*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::POPC),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctpop:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (POPC:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1986*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTLZ),// ->2000
/*  1989*/  OPC_RecordChild0, // #0 = $a
/*  1990*/  OPC_CheckChild0TypeI32,
/*  1991*/  OPC_CheckTypeI32,
/*  1992*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CLZ),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctlz:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CLZ:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2000*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::BITREVERSE),// ->2013
/*  2003*/  OPC_RecordChild0, // #0 = $a
/*  2004*/  OPC_CheckTypeI32,
/*  2005*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::BREV),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (bitreverse:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (BREV:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2013*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ABS),// ->2026
/*  2016*/  OPC_RecordChild0, // #0 = $a
/*  2017*/  OPC_CheckTypeI32,
/*  2018*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::ABS),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (abs:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (ABS:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2026*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_SINT),// ->2039
/*  2029*/  OPC_RecordChild0, // #0 = $a
/*  2030*/  OPC_CheckTypeI32,
/*  2031*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_S32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_sint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_S32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2039*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_UINT),// ->2052
/*  2042*/  OPC_RecordChild0, // #0 = $a
/*  2043*/  OPC_CheckTypeI32,
/*  2044*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_U32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_uint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_U32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2052*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::TRUNCATE),// ->2064
/*  2055*/  OPC_RecordChild0, // #0 = $a
/*  2056*/  OPC_CheckType, MVT::i16,
/*  2058*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i16, 1/*#Ops*/, 0, 
            // Src: (trunc:{ *:[i16] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i16] } GPR:{ *:[i32] }:$a)
/*  2064*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ZERO_EXTEND),// ->2077
/*  2067*/  OPC_RecordChild0, // #0 = $a
/*  2068*/  OPC_CheckChild0Type, MVT::i16,
/*  2070*/  OPC_CheckTypeI32,
/*  2071*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i32, 1/*#Ops*/, 0, 
            // Src: (zext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i32] } GPR16:{ *:[i16] }:$a)
/*  2077*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ANY_EXTEND),// ->2090
/*  2080*/  OPC_RecordChild0, // #0 = $a
/*  2081*/  OPC_CheckChild0Type, MVT::i16,
/*  2083*/  OPC_CheckTypeI32,
/*  2084*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i32, 1/*#Ops*/, 0, 
            // Src: (anyext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i32] } GPR16:{ *:[i16] }:$a)
/*  2090*/ /*SwitchOpcode*/ 12, TARGET_VAL(ISD::SIGN_EXTEND),// ->2105
/*  2093*/  OPC_RecordChild0, // #0 = $a
/*  2094*/  OPC_CheckChild0Type, MVT::i16,
/*  2096*/  OPC_CheckTypeI32,
/*  2097*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_SEXT),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (CVT_SEXT:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a)
/*  2105*/ /*SwitchOpcode*/ 40, TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->2148
/*  2108*/  OPC_RecordChild0, // #0 = $a
/*  2109*/  OPC_MoveChild1,
/*  2110*/  OPC_CheckValueType, MVT::i16,
/*  2112*/  OPC_MoveParent,
/*  2113*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  2115*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 1,  // Results = #2
/*  2122*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  2124*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 3,  // Results = #4
/*  2131*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  2133*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 5,  // Results = #6
/*  2140*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_SEXT),
                MVT::i32, 3/*#Ops*/, 2, 4, 6, 
            // Src: (sext_inreg:{ *:[i32] } GPR:{ *:[i32] }:$a, i16:{ *:[Other] }) - Complexity = 3
            // Dst: (CVT_SEXT:{ *:[i32] } (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }), (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }), (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }))
/*  2148*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::ConstantFP),// ->2176
/*  2151*/  OPC_RecordNode, // #0 = $i
/*  2152*/  OPC_Scope, 11, /*->2165*/ // 2 children in Scope
/*  2154*/   OPC_CheckPredicate, 18, // Predicate_fpimm_small
/*  2156*/   OPC_EmitNodeXForm, 4, 0, // fpimm_bits
/*  2159*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] })<<P:Predicate_fpimm_small>>:$i - Complexity = 14
             // Dst: (MOVI:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  2165*/  /*Scope*/ 9, /*->2175*/
/*  2166*/   OPC_EmitNodeXForm, 4, 0, // fpimm_bits
/*  2169*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] }):$i - Complexity = 3
             // Dst: (MOVI48:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  2175*/  0, /*End of Scope*/
/*  2176*/ /*SwitchOpcode*/ 41, TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->2220
/*  2179*/  OPC_Scope, 12, /*->2193*/ // 3 children in Scope
/*  2181*/   OPC_CheckChild0Integer, 12|128,127/*16268*/, 
/*  2184*/   OPC_RecordChild1, // #0 = $a
/*  2185*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::RSQRT_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8134:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (RSQRT_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2193*/  /*Scope*/ 12, /*->2206*/
/*  2194*/   OPC_CheckChild0Integer, 102|128,127/*16358*/, 
/*  2197*/   OPC_RecordChild1, // #0 = $a
/*  2198*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SIN_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8179:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (SIN_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2206*/  /*Scope*/ 12, /*->2219*/
/*  2207*/   OPC_CheckChild0Integer, 96|128,118/*15200*/, 
/*  2210*/   OPC_RecordChild1, // #0 = $a
/*  2211*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::COS_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 7600:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (COS_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2219*/  0, /*End of Scope*/
/*  2220*/ /*SwitchOpcode*/ 56, TARGET_VAL(ISD::FDIV),// ->2279
/*  2223*/  OPC_MoveChild0,
/*  2224*/  OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*  2227*/  OPC_Scope, 12, /*->2241*/ // 2 children in Scope
/*  2229*/   OPC_CheckPredicate, 19, // Predicate_fpimm_one
/*  2231*/   OPC_MoveParent,
/*  2232*/   OPC_RecordChild1, // #0 = $a
/*  2233*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (fdiv:{ *:[f32] } (fpimm:{ *:[f32] })<<P:Predicate_fpimm_one>>, GPR:{ *:[f32] }:$a) - Complexity = 7
             // Dst: (RCP_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2241*/  /*Scope*/ 36, /*->2278*/
/*  2242*/   OPC_CheckPredicate, 20, // Predicate_fpimm_minus_one
/*  2244*/   OPC_MoveParent,
/*  2245*/   OPC_RecordChild1, // #0 = $a
/*  2246*/   OPC_EmitNode1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #1
/*  2254*/   OPC_EmitNode1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #2
/*  2262*/   OPC_EmitNode1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #3
/*  2270*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::FNEG_F0),
                 MVT::f32, 3/*#Ops*/, 1, 2, 3, 
             // Src: (fdiv:{ *:[f32] } (fpimm:{ *:[f32] })<<P:Predicate_fpimm_minus_one>>, GPR:{ *:[f32] }:$a) - Complexity = 7
             // Dst: (FNEG_F0:{ *:[f32] } (RCP_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a), (RCP_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a), (RCP_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a))
/*  2278*/  0, /*End of Scope*/
/*  2279*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FADD),// ->2291
/*  2282*/  OPC_RecordChild0, // #0 = $a
/*  2283*/  OPC_RecordChild1, // #1 = $b
/*  2284*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FADD),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fadd:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FADD:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  2291*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMUL),// ->2303
/*  2294*/  OPC_RecordChild0, // #0 = $a
/*  2295*/  OPC_RecordChild1, // #1 = $b
/*  2296*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMUL),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmul:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMUL:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  2303*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FSUB),// ->2316
/*  2306*/  OPC_RecordChild0, // #0 = $a
/*  2307*/  OPC_RecordChild1, // #1 = $b
/*  2308*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FSUB),
                MVT::f32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (fsub:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (FSUB:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$a)
/*  2316*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMINNUM),// ->2328
/*  2319*/  OPC_RecordChild0, // #0 = $a
/*  2320*/  OPC_RecordChild1, // #1 = $b
/*  2321*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMIN),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fminnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMIN:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  2328*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMAXNUM),// ->2340
/*  2331*/  OPC_RecordChild0, // #0 = $a
/*  2332*/  OPC_RecordChild1, // #1 = $b
/*  2333*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMAX),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmaxnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMAX:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  2340*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FNEG),// ->2352
/*  2343*/  OPC_RecordChild0, // #0 = $a
/*  2344*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FNEG_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fneg:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FNEG_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2352*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FABS),// ->2364
/*  2355*/  OPC_RecordChild0, // #0 = $a
/*  2356*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FABS_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fabs:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FABS_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2364*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::FMA),// ->2378
/*  2367*/  OPC_RecordChild0, // #0 = $a
/*  2368*/  OPC_RecordChild1, // #1 = $b
/*  2369*/  OPC_RecordChild2, // #2 = $c
/*  2370*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FFMA_F0),
                MVT::f32, 3/*#Ops*/, 0, 1, 2, 
            // Src: (fma:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c) - Complexity = 3
            // Dst: (FFMA_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c)
/*  2378*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::SINT_TO_FP),// ->2391
/*  2381*/  OPC_RecordChild0, // #0 = $a
/*  2382*/  OPC_CheckChild0TypeI32,
/*  2383*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_S32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_S32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2391*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::UINT_TO_FP),// ->2404
/*  2394*/  OPC_RecordChild0, // #0 = $a
/*  2395*/  OPC_CheckChild0TypeI32,
/*  2396*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_U32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (uint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_U32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  2404*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FSQRT),// ->2416
/*  2407*/  OPC_RecordChild0, // #0 = $a
/*  2408*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::SQRT_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fsqrt:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (SQRT_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2416*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FEXP2),// ->2428
/*  2419*/  OPC_RecordChild0, // #0 = $a
/*  2420*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::EX2_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fexp2:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (EX2_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2428*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FLOG2),// ->2440
/*  2431*/  OPC_RecordChild0, // #0 = $a
/*  2432*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::LG2_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (flog2:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (LG2_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  2440*/ 0, // EndSwitchOpcode
    0
  }; // Total Array size is 2442 bytes

  // Opcode Histogram:
  // #OPC_Scope                                = 44
  // #OPC_RecordNode                           = 11
  // #OPC_RecordChild                          = 115
  // #OPC_RecordMemRef                         = 2
  // #OPC_CaptureGlueInput                     = 2
  // #OPC_MoveChild                            = 37
  // #OPC_MoveSibling                          = 2
  // #OPC_MoveParent                           = 57
  // #OPC_CheckSame                            = 0
  // #OPC_CheckChildSame                       = 0
  // #OPC_CheckPatternPredicate                = 0
  // #OPC_CheckPredicate                       = 135
  // #OPC_CheckOpcode                          = 38
  // #OPC_SwitchOpcode                         = 1
  // #OPC_CheckType                            = 82
  // #OPC_SwitchType                           = 7
  // #OPC_CheckChildType                       = 28
  // #OPC_CheckInteger                         = 2
  // #OPC_CheckChildInteger                    = 15
  // #OPC_CheckCondCode                        = 0
  // #OPC_CheckChild2CondCode                  = 0
  // #OPC_CheckValueType                       = 1
  // #OPC_CheckComplexPat                      = 0
  // #OPC_CheckAndImm                          = 0
  // #OPC_CheckOrImm                           = 0
  // #OPC_CheckImmAllOnesV                     = 0
  // #OPC_CheckImmAllZerosV                    = 0
  // #OPC_CheckFoldableChainNode               = 0
  // #OPC_EmitInteger                          = 48
  // #OPC_EmitStringInteger                    = 9
  // #OPC_EmitRegister                         = 0
  // #OPC_EmitConvertToTarget                  = 25
  // #OPC_EmitMergeInputChains                 = 43
  // #OPC_EmitCopyToReg                        = 0
  // #OPC_EmitNode                             = 24
  // #OPC_EmitNodeXForm                        = 6
  // #OPC_CompleteMatch                        = 2
  // #OPC_MorphNodeTo                          = 125

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
    // Predicate_ld_shared
    // Predicate_ld_shared_s8
    // Predicate_ld_shared_u8
    // Predicate_ld_shared_z8
    SDNode *N = Node;
    (void)N;

  return cast<LoadSDNode>(N)->getAddressSpace() == 3;

  }
  case 1: {
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
    // Predicate_load
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::NON_EXTLOAD) return false;
return true;

  }
  case 4: {
    // Predicate_store
    SDNode *N = Node;
    (void)N;
 if (cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 5: {
    // Predicate_unindexedload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getAddressingMode() != ISD::UNINDEXED) return false;
return true;

  }
  case 6: {
    // Predicate_extloadi8
    // Predicate_sextloadi8
    // Predicate_zextloadi8
    SDNode *N = Node;
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i8) return false;
return true;

  }
  case 7: {
    // Predicate_simm13_imm
    // Predicate_simm13_imm16
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return isInt<13>(Imm); 
  }
  case 8: {
    // Predicate_truncstore
    SDNode *N = Node;
    (void)N;
 if (!cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 9: {
    // Predicate_truncstorei8
    SDNode *N = Node;
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i8) return false;
 if (!cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 10: {
    // Predicate_extload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::EXTLOAD) return false;
return true;

  }
  case 11: {
    // Predicate_zextload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::ZEXTLOAD) return false;
return true;

  }
  case 12: {
    // Predicate_sextload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::SEXTLOAD) return false;
return true;

  }
  case 13: {
    // Predicate_uimm4_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < 16; 
  }
  case 14: {
    // Predicate_uimm5_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < 32; 
  }
  case 15: {
    // Predicate_uimm29_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && isUInt<29>(Imm); 
  }
  case 16: {
    // Predicate_uimm17_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < (1 << 17); 
  }
  case 17: {
    // Predicate_simm13_not_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

  return !isInt<13>(Imm) && isInt<13>(~Imm);

  }
  case 18: {
    // Predicate_fpimm_small
    auto *N = cast<ConstantFPSDNode>(Node);
    (void)N;

  return N->getValueAPF().bitcastToAPInt().getZExtValue() < (1u << 17);

  }
  case 19: {
    // Predicate_fpimm_one
    auto *N = cast<ConstantFPSDNode>(Node);
    (void)N;
 return N->isExactlyValue(1.0); 
  }
  case 20: {
    // Predicate_fpimm_minus_one
    auto *N = cast<ConstantFPSDNode>(Node);
    (void)N;
 return N->isExactlyValue(-1.0); 
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
