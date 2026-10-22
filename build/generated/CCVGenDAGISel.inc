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
/*     0*/ OPC_SwitchOpcode /*49 cases */, 114, TARGET_VAL(ISD::ADD),// ->118
/*     4*/  OPC_Scope, 48, /*->54*/ // 3 children in Scope
/*     6*/   OPC_RecordChild0, // #0 = $a
/*     7*/   OPC_RecordChild1, // #1 = $i
/*     8*/   OPC_MoveChild1,
/*     9*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    12*/   OPC_Scope, 11, /*->25*/ // 3 children in Scope
/*    14*/    OPC_CheckPredicate6,  // Predicate_simm13_imm
/*    15*/    OPC_MoveParent,
/*    16*/    OPC_CheckTypeI32,
/*    17*/    OPC_EmitConvertToTarget1,
/*    18*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 17
              // Dst: (ADDI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*    25*/   /*Scope*/ 12, /*->38*/
/*    26*/    OPC_CheckPredicate, 9, // Predicate_uimm29_imm
/*    28*/    OPC_MoveParent,
/*    29*/    OPC_CheckTypeI32,
/*    30*/    OPC_EmitConvertToTarget1,
/*    31*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::ADDI48),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm29_imm>>:$i) - Complexity = 12
              // Dst: (ADDI48:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*    38*/   /*Scope*/ 14, /*->53*/
/*    39*/    OPC_CheckPredicate6,  // Predicate_simm13_imm16
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
/*   118*/ /*SwitchOpcode*/ 61|128,2/*317*/, TARGET_VAL(ISD::LOAD),// ->439
/*   122*/  OPC_RecordMemRef,
/*   123*/  OPC_RecordNode, // #0 = 'ld' chained node
/*   124*/  OPC_Scope, 6|128,1/*134*/, /*->261*/ // 4 children in Scope
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
/*   145*/    OPC_CheckPredicate3,  // Predicate_unindexedload
/*   146*/    OPC_CheckPredicate4,  // Predicate_load
/*   147*/    OPC_CheckPredicate5,  // Predicate_ld_shared
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
/*   177*/    OPC_CheckPredicate3,  // Predicate_unindexedload
/*   178*/    OPC_CheckPredicate4,  // Predicate_load
/*   179*/    OPC_CheckPredicate5,  // Predicate_ld_shared
/*   180*/    OPC_CheckTypeI32,
/*   181*/    OPC_EmitMergeInputChains1_0,
/*   182*/    OPC_EmitInteger32, 2, 
/*   184*/    OPC_EmitInteger32, 0, 
/*   186*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 4/*#Ops*/, 2, 1, 3, 4, 
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   196*/   /*Scope*/ 63, /*->260*/
/*   197*/    OPC_RecordChild0, // #1 = $rbase
/*   198*/    OPC_RecordChild1, // #2 = $off
/*   199*/    OPC_Scope, 36, /*->237*/ // 2 children in Scope
/*   201*/     OPC_MoveChild1,
/*   202*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   205*/     OPC_MoveParent,
/*   206*/     OPC_CheckTypeI32,
/*   207*/     OPC_MoveParent,
/*   208*/     OPC_CheckPredicate3,  // Predicate_unindexedload
/*   209*/     OPC_CheckPredicate4,  // Predicate_load
/*   210*/     OPC_CheckPredicate5,  // Predicate_ld_shared
/*   211*/     OPC_SwitchType /*2 cases */, 10, MVT::i32,// ->224
/*   214*/      OPC_EmitMergeInputChains1_0,
/*   215*/      OPC_EmitConvertToTarget2,
/*   216*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i32, 2/*#Ops*/, 1, 3, 
                // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
                // Dst: (LD_SHARED:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   224*/     /*SwitchType*/ 10, MVT::i16,// ->236
/*   226*/      OPC_EmitMergeInputChains1_0,
/*   227*/      OPC_EmitConvertToTarget2,
/*   228*/      OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                    MVT::i16, 2/*#Ops*/, 1, 3, 
                // Src: (ld:{ *:[i16] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
                // Dst: (LD_SHARED_W16:{ *:[i16] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   236*/     0, // EndSwitchType
/*   237*/    /*Scope*/ 21, /*->259*/
/*   238*/     OPC_CheckTypeI32,
/*   239*/     OPC_MoveParent,
/*   240*/     OPC_CheckPredicate3,  // Predicate_unindexedload
/*   241*/     OPC_CheckPredicate4,  // Predicate_load
/*   242*/     OPC_CheckPredicate5,  // Predicate_ld_shared
/*   243*/     OPC_CheckTypeI32,
/*   244*/     OPC_EmitMergeInputChains1_0,
/*   245*/     OPC_EmitInteger32, 0, 
/*   247*/     OPC_EmitInteger32, 0, 
/*   249*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 7
               // Dst: (LD_SHARED_IDX:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   259*/    0, /*End of Scope*/
/*   260*/   0, /*End of Scope*/
/*   261*/  /*Scope*/ 33, /*->295*/
/*   262*/   OPC_RecordChild1, // #1 = $rbase
/*   263*/   OPC_CheckChild1TypeI32,
/*   264*/   OPC_CheckPredicate3,  // Predicate_unindexedload
/*   265*/   OPC_CheckPredicate4,  // Predicate_load
/*   266*/   OPC_CheckPredicate5,  // Predicate_ld_shared
/*   267*/   OPC_SwitchType /*2 cases */, 11, MVT::i32,// ->281
/*   270*/    OPC_EmitMergeInputChains1_0,
/*   271*/    OPC_EmitInteger32, 0, 
/*   273*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (ld:{ *:[i32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
              // Dst: (LD_SHARED:{ *:[i32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   281*/   /*SwitchType*/ 11, MVT::i16,// ->294
/*   283*/    OPC_EmitMergeInputChains1_0,
/*   284*/    OPC_EmitInteger32, 0, 
/*   286*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::i16, 2/*#Ops*/, 1, 2, 
              // Src: (ld:{ *:[i16] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
              // Dst: (LD_SHARED_W16:{ *:[i16] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   294*/   0, // EndSwitchType
/*   295*/  /*Scope*/ 123, /*->419*/
/*   296*/   OPC_MoveChild1,
/*   297*/   OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   300*/   OPC_Scope, 32, /*->334*/ // 3 children in Scope
/*   302*/    OPC_RecordChild0, // #1 = $rbase
/*   303*/    OPC_MoveChild1,
/*   304*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   307*/    OPC_RecordChild0, // #2 = $ri
/*   308*/    OPC_CheckChild1Integer, 4, 
/*   310*/    OPC_CheckChild1TypeI32,
/*   311*/    OPC_MoveParent,
/*   312*/    OPC_CheckTypeI32,
/*   313*/    OPC_MoveParent,
/*   314*/    OPC_CheckPredicate3,  // Predicate_unindexedload
/*   315*/    OPC_CheckPredicate4,  // Predicate_load
/*   316*/    OPC_CheckPredicate5,  // Predicate_ld_shared
/*   317*/    OPC_CheckType, MVT::f32,
/*   319*/    OPC_EmitMergeInputChains1_0,
/*   320*/    OPC_EmitInteger32, 2, 
/*   322*/    OPC_EmitInteger32, 0, 
/*   324*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::f32, 4/*#Ops*/, 1, 2, 3, 4, 
              // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   334*/   /*Scope*/ 32, /*->367*/
/*   335*/    OPC_MoveChild0,
/*   336*/    OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   339*/    OPC_RecordChild0, // #1 = $ri
/*   340*/    OPC_CheckChild1Integer, 4, 
/*   342*/    OPC_CheckChild1TypeI32,
/*   343*/    OPC_MoveParent,
/*   344*/    OPC_RecordChild1, // #2 = $rbase
/*   345*/    OPC_CheckTypeI32,
/*   346*/    OPC_MoveParent,
/*   347*/    OPC_CheckPredicate3,  // Predicate_unindexedload
/*   348*/    OPC_CheckPredicate4,  // Predicate_load
/*   349*/    OPC_CheckPredicate5,  // Predicate_ld_shared
/*   350*/    OPC_CheckType, MVT::f32,
/*   352*/    OPC_EmitMergeInputChains1_0,
/*   353*/    OPC_EmitInteger32, 2, 
/*   355*/    OPC_EmitInteger32, 0, 
/*   357*/    OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                  MVT::f32, 4/*#Ops*/, 2, 1, 3, 4, 
              // Src: (ld:{ *:[f32] } (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 15
              // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   367*/   /*Scope*/ 50, /*->418*/
/*   368*/    OPC_RecordChild0, // #1 = $rbase
/*   369*/    OPC_RecordChild1, // #2 = $off
/*   370*/    OPC_Scope, 22, /*->394*/ // 2 children in Scope
/*   372*/     OPC_MoveChild1,
/*   373*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   376*/     OPC_MoveParent,
/*   377*/     OPC_CheckTypeI32,
/*   378*/     OPC_MoveParent,
/*   379*/     OPC_CheckPredicate3,  // Predicate_unindexedload
/*   380*/     OPC_CheckPredicate4,  // Predicate_load
/*   381*/     OPC_CheckPredicate5,  // Predicate_ld_shared
/*   382*/     OPC_CheckType, MVT::f32,
/*   384*/     OPC_EmitMergeInputChains1_0,
/*   385*/     OPC_EmitConvertToTarget2,
/*   386*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::f32, 2/*#Ops*/, 1, 3, 
               // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 10
               // Dst: (LD_SHARED:{ *:[f32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   394*/    /*Scope*/ 22, /*->417*/
/*   395*/     OPC_CheckTypeI32,
/*   396*/     OPC_MoveParent,
/*   397*/     OPC_CheckPredicate3,  // Predicate_unindexedload
/*   398*/     OPC_CheckPredicate4,  // Predicate_load
/*   399*/     OPC_CheckPredicate5,  // Predicate_ld_shared
/*   400*/     OPC_CheckType, MVT::f32,
/*   402*/     OPC_EmitMergeInputChains1_0,
/*   403*/     OPC_EmitInteger32, 0, 
/*   405*/     OPC_EmitInteger32, 0, 
/*   407*/     OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::f32, 4/*#Ops*/, 1, 2, 3, 4, 
               // Src: (ld:{ *:[f32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 7
               // Dst: (LD_SHARED_IDX:{ *:[f32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   417*/    0, /*End of Scope*/
/*   418*/   0, /*End of Scope*/
/*   419*/  /*Scope*/ 18, /*->438*/
/*   420*/   OPC_RecordChild1, // #1 = $rbase
/*   421*/   OPC_CheckChild1TypeI32,
/*   422*/   OPC_CheckPredicate3,  // Predicate_unindexedload
/*   423*/   OPC_CheckPredicate4,  // Predicate_load
/*   424*/   OPC_CheckPredicate5,  // Predicate_ld_shared
/*   425*/   OPC_CheckType, MVT::f32,
/*   427*/   OPC_EmitMergeInputChains1_0,
/*   428*/   OPC_EmitInteger32, 0, 
/*   430*/   OPC_MorphNodeTo1, TARGET_VAL(CCV::LD_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                 MVT::f32, 2/*#Ops*/, 1, 2, 
             // Src: (ld:{ *:[f32] } GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_ld_shared>> - Complexity = 4
             // Dst: (LD_SHARED:{ *:[f32] } GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   438*/  0, /*End of Scope*/
/*   439*/ /*SwitchOpcode*/ 75|128,2/*331*/, TARGET_VAL(ISD::STORE),// ->774
/*   443*/  OPC_RecordMemRef,
/*   444*/  OPC_RecordNode, // #0 = 'st' chained node
/*   445*/  OPC_RecordChild1, // #1 = $v
/*   446*/  OPC_Scope, 8|128,1/*136*/, /*->585*/ // 3 children in Scope
/*   449*/   OPC_CheckChild1TypeI32,
/*   450*/   OPC_Scope, 115, /*->567*/ // 2 children in Scope
/*   452*/    OPC_MoveChild2,
/*   453*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   456*/    OPC_Scope, 30, /*->488*/ // 3 children in Scope
/*   458*/     OPC_RecordChild0, // #2 = $rbase
/*   459*/     OPC_MoveChild1,
/*   460*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   463*/     OPC_RecordChild0, // #3 = $ri
/*   464*/     OPC_CheckChild1Integer, 4, 
/*   466*/     OPC_CheckChild1TypeI32,
/*   467*/     OPC_MoveParent,
/*   468*/     OPC_CheckTypeI32,
/*   469*/     OPC_MoveParent,
/*   470*/     OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   471*/     OPC_CheckPredicate1,  // Predicate_store
/*   472*/     OPC_CheckPredicate2,  // Predicate_st_shared
/*   473*/     OPC_EmitMergeInputChains1_0,
/*   474*/     OPC_EmitInteger32, 2, 
/*   476*/     OPC_EmitInteger32, 0, 
/*   478*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   488*/    /*Scope*/ 30, /*->519*/
/*   489*/     OPC_MoveChild0,
/*   490*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   493*/     OPC_RecordChild0, // #2 = $ri
/*   494*/     OPC_CheckChild1Integer, 4, 
/*   496*/     OPC_CheckChild1TypeI32,
/*   497*/     OPC_MoveParent,
/*   498*/     OPC_RecordChild1, // #3 = $rbase
/*   499*/     OPC_CheckTypeI32,
/*   500*/     OPC_MoveParent,
/*   501*/     OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   502*/     OPC_CheckPredicate1,  // Predicate_store
/*   503*/     OPC_CheckPredicate2,  // Predicate_st_shared
/*   504*/     OPC_EmitMergeInputChains1_0,
/*   505*/     OPC_EmitInteger32, 2, 
/*   507*/     OPC_EmitInteger32, 0, 
/*   509*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 3, 2, 4, 5, 
               // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   519*/    /*Scope*/ 46, /*->566*/
/*   520*/     OPC_RecordChild0, // #2 = $rbase
/*   521*/     OPC_RecordChild1, // #3 = $off
/*   522*/     OPC_Scope, 20, /*->544*/ // 2 children in Scope
/*   524*/      OPC_MoveChild1,
/*   525*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   528*/      OPC_MoveParent,
/*   529*/      OPC_CheckTypeI32,
/*   530*/      OPC_MoveParent,
/*   531*/      OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   532*/      OPC_CheckPredicate1,  // Predicate_store
/*   533*/      OPC_CheckPredicate2,  // Predicate_st_shared
/*   534*/      OPC_EmitMergeInputChains1_0,
/*   535*/      OPC_EmitConvertToTarget3,
/*   536*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 1, 2, 4, 
                // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                // Dst: (ST_SHARED GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   544*/     /*Scope*/ 20, /*->565*/
/*   545*/      OPC_CheckTypeI32,
/*   546*/      OPC_MoveParent,
/*   547*/      OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   548*/      OPC_CheckPredicate1,  // Predicate_store
/*   549*/      OPC_CheckPredicate2,  // Predicate_st_shared
/*   550*/      OPC_EmitMergeInputChains1_0,
/*   551*/      OPC_EmitInteger32, 0, 
/*   553*/      OPC_EmitInteger32, 0, 
/*   555*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                    5/*#Ops*/, 1, 2, 3, 4, 5, 
                // Src: (st i32:{ *:[i32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 7
                // Dst: (ST_SHARED_IDX GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   565*/     0, /*End of Scope*/
/*   566*/    0, /*End of Scope*/
/*   567*/   /*Scope*/ 16, /*->584*/
/*   568*/    OPC_RecordChild2, // #2 = $rbase
/*   569*/    OPC_CheckChild2TypeI32,
/*   570*/    OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   571*/    OPC_CheckPredicate1,  // Predicate_store
/*   572*/    OPC_CheckPredicate2,  // Predicate_st_shared
/*   573*/    OPC_EmitMergeInputChains1_0,
/*   574*/    OPC_EmitInteger32, 0, 
/*   576*/    OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                  3/*#Ops*/, 1, 2, 3, 
              // Src: (st i32:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
              // Dst: (ST_SHARED GPR:{ *:[i32] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   584*/   0, /*End of Scope*/
/*   585*/  /*Scope*/ 9|128,1/*137*/, /*->724*/
/*   587*/   OPC_CheckChild1Type, MVT::f32,
/*   589*/   OPC_Scope, 115, /*->706*/ // 2 children in Scope
/*   591*/    OPC_MoveChild2,
/*   592*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   595*/    OPC_Scope, 30, /*->627*/ // 3 children in Scope
/*   597*/     OPC_RecordChild0, // #2 = $rbase
/*   598*/     OPC_MoveChild1,
/*   599*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   602*/     OPC_RecordChild0, // #3 = $ri
/*   603*/     OPC_CheckChild1Integer, 4, 
/*   605*/     OPC_CheckChild1TypeI32,
/*   606*/     OPC_MoveParent,
/*   607*/     OPC_CheckTypeI32,
/*   608*/     OPC_MoveParent,
/*   609*/     OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   610*/     OPC_CheckPredicate1,  // Predicate_store
/*   611*/     OPC_CheckPredicate2,  // Predicate_st_shared
/*   612*/     OPC_EmitMergeInputChains1_0,
/*   613*/     OPC_EmitInteger32, 2, 
/*   615*/     OPC_EmitInteger32, 0, 
/*   617*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 2, 3, 4, 5, 
               // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] })))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   627*/    /*Scope*/ 30, /*->658*/
/*   628*/     OPC_MoveChild0,
/*   629*/     OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*   632*/     OPC_RecordChild0, // #2 = $ri
/*   633*/     OPC_CheckChild1Integer, 4, 
/*   635*/     OPC_CheckChild1TypeI32,
/*   636*/     OPC_MoveParent,
/*   637*/     OPC_RecordChild1, // #3 = $rbase
/*   638*/     OPC_CheckTypeI32,
/*   639*/     OPC_MoveParent,
/*   640*/     OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   641*/     OPC_CheckPredicate1,  // Predicate_store
/*   642*/     OPC_CheckPredicate2,  // Predicate_st_shared
/*   643*/     OPC_EmitMergeInputChains1_0,
/*   644*/     OPC_EmitInteger32, 2, 
/*   646*/     OPC_EmitInteger32, 0, 
/*   648*/     OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                   5/*#Ops*/, 1, 3, 2, 4, 5, 
               // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } (shl:{ *:[i32] } GPR:{ *:[i32] }:$ri, 2:{ *:[i32] }), GPR:{ *:[i32] }:$rbase))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 15
               // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 1:{ *:[i32] }, 0:{ *:[i32] })
/*   658*/    /*Scope*/ 46, /*->705*/
/*   659*/     OPC_RecordChild0, // #2 = $rbase
/*   660*/     OPC_RecordChild1, // #3 = $off
/*   661*/     OPC_Scope, 20, /*->683*/ // 2 children in Scope
/*   663*/      OPC_MoveChild1,
/*   664*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   667*/      OPC_MoveParent,
/*   668*/      OPC_CheckTypeI32,
/*   669*/      OPC_MoveParent,
/*   670*/      OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   671*/      OPC_CheckPredicate1,  // Predicate_store
/*   672*/      OPC_CheckPredicate2,  // Predicate_st_shared
/*   673*/      OPC_EmitMergeInputChains1_0,
/*   674*/      OPC_EmitConvertToTarget3,
/*   675*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, 1, 2, 4, 
                // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
                // Dst: (ST_SHARED GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   683*/     /*Scope*/ 20, /*->704*/
/*   684*/      OPC_CheckTypeI32,
/*   685*/      OPC_MoveParent,
/*   686*/      OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   687*/      OPC_CheckPredicate1,  // Predicate_store
/*   688*/      OPC_CheckPredicate2,  // Predicate_st_shared
/*   689*/      OPC_EmitMergeInputChains1_0,
/*   690*/      OPC_EmitInteger32, 0, 
/*   692*/      OPC_EmitInteger32, 0, 
/*   694*/      OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_IDX), 0|OPFL_Chain|OPFL_MemRefs,
                    5/*#Ops*/, 1, 2, 3, 4, 5, 
                // Src: (st f32:{ *:[f32] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 7
                // Dst: (ST_SHARED_IDX GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, GPR:{ *:[i32] }:$ri, 0:{ *:[i32] }, 0:{ *:[i32] })
/*   704*/     0, /*End of Scope*/
/*   705*/    0, /*End of Scope*/
/*   706*/   /*Scope*/ 16, /*->723*/
/*   707*/    OPC_RecordChild2, // #2 = $rbase
/*   708*/    OPC_CheckChild2TypeI32,
/*   709*/    OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   710*/    OPC_CheckPredicate1,  // Predicate_store
/*   711*/    OPC_CheckPredicate2,  // Predicate_st_shared
/*   712*/    OPC_EmitMergeInputChains1_0,
/*   713*/    OPC_EmitInteger32, 0, 
/*   715*/    OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED), 0|OPFL_Chain|OPFL_MemRefs,
                  3/*#Ops*/, 1, 2, 3, 
              // Src: (st f32:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
              // Dst: (ST_SHARED GPR:{ *:[f32] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   723*/   0, /*End of Scope*/
/*   724*/  /*Scope*/ 48, /*->773*/
/*   725*/   OPC_CheckChild1Type, MVT::i16,
/*   727*/   OPC_Scope, 26, /*->755*/ // 2 children in Scope
/*   729*/    OPC_MoveChild2,
/*   730*/    OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*   733*/    OPC_RecordChild0, // #2 = $rbase
/*   734*/    OPC_RecordChild1, // #3 = $off
/*   735*/    OPC_MoveChild1,
/*   736*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   739*/    OPC_MoveParent,
/*   740*/    OPC_CheckTypeI32,
/*   741*/    OPC_MoveParent,
/*   742*/    OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   743*/    OPC_CheckPredicate1,  // Predicate_store
/*   744*/    OPC_CheckPredicate2,  // Predicate_st_shared
/*   745*/    OPC_EmitMergeInputChains1_0,
/*   746*/    OPC_EmitConvertToTarget3,
/*   747*/    OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                  3/*#Ops*/, 1, 2, 4, 
              // Src: (st GPR16:{ *:[i16] }:$v, (add:{ *:[i32] } GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 10
              // Dst: (ST_SHARED_W16 GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase, (imm:{ *:[i32] }):$off)
/*   755*/   /*Scope*/ 16, /*->772*/
/*   756*/    OPC_RecordChild2, // #2 = $rbase
/*   757*/    OPC_CheckChild2TypeI32,
/*   758*/    OPC_CheckPredicate0,  // Predicate_unindexedstore
/*   759*/    OPC_CheckPredicate1,  // Predicate_store
/*   760*/    OPC_CheckPredicate2,  // Predicate_st_shared
/*   761*/    OPC_EmitMergeInputChains1_0,
/*   762*/    OPC_EmitInteger32, 0, 
/*   764*/    OPC_MorphNodeTo0, TARGET_VAL(CCV::ST_SHARED_W16), 0|OPFL_Chain|OPFL_MemRefs,
                  3/*#Ops*/, 1, 2, 3, 
              // Src: (st GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_st_shared>> - Complexity = 4
              // Dst: (ST_SHARED_W16 GPR16:{ *:[i16] }:$v, GPR:{ *:[i32] }:$rbase, 0:{ *:[i32] })
/*   772*/   0, /*End of Scope*/
/*   773*/  0, /*End of Scope*/
/*   774*/ /*SwitchOpcode*/ 76, TARGET_VAL(ISD::Constant),// ->853
/*   777*/  OPC_Scope, 11, /*->790*/ // 4 children in Scope
/*   779*/   OPC_RecordNode, // #0 = $i
/*   780*/   OPC_CheckPredicate, 10, // Predicate_uimm17_imm
/*   782*/   OPC_CheckTypeI32,
/*   783*/   OPC_EmitConvertToTarget0,
/*   784*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                 MVT::i32, 1/*#Ops*/, 1, 
             // Src: (imm:{ *:[i32] })<<P:Predicate_uimm17_imm>>:$i - Complexity = 14
             // Dst: (MOVI:{ *:[i32] } (imm:{ *:[i32] }):$i)
/*   790*/  /*Scope*/ 16, /*->807*/
/*   791*/   OPC_CheckInteger, 3, 
/*   793*/   OPC_CheckType, MVT::i1,
/*   795*/   OPC_EmitInteger32, 126|128,127|128,127|128,127|128,31/*8589934590*/, 
/*   801*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                 MVT::i1, 1/*#Ops*/, 0, 
             // Src: -1:{ *:[i1] } - Complexity = 5
             // Dst: (PMOV_IMM:{ *:[i1] } 4294967295:{ *:[i32] })
/*   807*/  /*Scope*/ 12, /*->820*/
/*   808*/   OPC_CheckInteger, 0, 
/*   810*/   OPC_CheckType, MVT::i1,
/*   812*/   OPC_EmitInteger32, 0, 
/*   814*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                 MVT::i1, 1/*#Ops*/, 0, 
             // Src: 0:{ *:[i1] } - Complexity = 5
             // Dst: (PMOV_IMM:{ *:[i1] } 0:{ *:[i32] })
/*   820*/  /*Scope*/ 31, /*->852*/
/*   821*/   OPC_RecordNode, // #0 = $i
/*   822*/   OPC_SwitchType /*2 cases */, 9, MVT::i32,// ->834
/*   825*/    OPC_EmitNodeXForm, 1, 0, // imm_bits32
/*   828*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                  MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:{ *:[i32] }):$i - Complexity = 3
              // Dst: (MOVI48:{ *:[i32] } (imm_bits32:{ *:[i32] } ?:{ *:[i32] }:$i))
/*   834*/   /*SwitchType*/ 15, MVT::i16,// ->851
/*   836*/    OPC_EmitNodeXForm, 2, 0, // imm16_bits
/*   839*/    OPC_EmitNode1None, TARGET_VAL(CCV::MOVI),
                  MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*   845*/    OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                  MVT::i16, 1/*#Ops*/, 2, 
              // Src: (imm:{ *:[i16] }):$i - Complexity = 3
              // Dst: (COPY:{ *:[i16] } (MOVI:{ *:[i32] } (imm16_bits:{ *:[i32] } ?:{ *:[i16] }:$i)))
/*   851*/   0, // EndSwitchType
/*   852*/  0, /*End of Scope*/
/*   853*/ /*SwitchOpcode*/ 110, TARGET_VAL(ISD::AND),// ->966
/*   856*/  OPC_Scope, 18, /*->876*/ // 3 children in Scope
/*   858*/   OPC_RecordChild0, // #0 = $a
/*   859*/   OPC_MoveChild1,
/*   860*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*   863*/   OPC_RecordChild0, // #1 = $b
/*   864*/   OPC_CheckChild1Integer, 3, 
/*   866*/   OPC_MoveParent,
/*   867*/   OPC_CheckTypeI32,
/*   868*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] })) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   876*/  /*Scope*/ 18, /*->895*/
/*   877*/   OPC_MoveChild0,
/*   878*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*   881*/   OPC_RecordChild0, // #0 = $b
/*   882*/   OPC_CheckChild1Integer, 3, 
/*   884*/   OPC_MoveParent,
/*   885*/   OPC_RecordChild1, // #1 = $a
/*   886*/   OPC_CheckTypeI32,
/*   887*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 1, 0, 1, 
             // Src: (and:{ *:[i32] } (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] }), GPR:{ *:[i32] }:$a) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   895*/  /*Scope*/ 69, /*->965*/
/*   896*/   OPC_RecordChild0, // #0 = $a
/*   897*/   OPC_RecordChild1, // #1 = $i
/*   898*/   OPC_Scope, 33, /*->933*/ // 4 children in Scope
/*   900*/    OPC_MoveChild1,
/*   901*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   904*/    OPC_Scope, 14, /*->920*/ // 2 children in Scope
/*   906*/     OPC_CheckPredicate, 11, // Predicate_simm13_not_imm
/*   908*/     OPC_MoveParent,
/*   909*/     OPC_CheckTypeI32,
/*   910*/     OPC_EmitNodeXForm, 3, 1, // imm_not
/*   913*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDNI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_not_imm>>:$i) - Complexity = 7
               // Dst: (ANDNI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm_not:{ *:[i32] } ?:{ *:[i32] }:$i))
/*   920*/    /*Scope*/ 11, /*->932*/
/*   921*/     OPC_CheckPredicate6,  // Predicate_simm13_imm
/*   922*/     OPC_MoveParent,
/*   923*/     OPC_CheckTypeI32,
/*   924*/     OPC_EmitConvertToTarget1,
/*   925*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
               // Dst: (ANDI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*   932*/    0, /*End of Scope*/
/*   933*/   /*Scope*/ 9, /*->943*/
/*   934*/    OPC_CheckTypeI32,
/*   935*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (AND:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   943*/   /*Scope*/ 9, /*->953*/
/*   944*/    OPC_CheckType, MVT::i1,
/*   946*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PAND),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (and:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PAND:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*   953*/   /*Scope*/ 10, /*->964*/
/*   954*/    OPC_CheckType, MVT::i16,
/*   956*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (AND_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*   964*/   0, /*End of Scope*/
/*   965*/  0, /*End of Scope*/
/*   966*/ /*SwitchOpcode*/ 20, TARGET_VAL(ISD::CALLSEQ_START),// ->989
/*   969*/  OPC_RecordNode, // #0 = 'callseq_start' chained node
/*   970*/  OPC_RecordChild1, // #1 = $a
/*   971*/  OPC_MoveChild1,
/*   972*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*   975*/  OPC_MoveSibling2,
/*   976*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*   979*/  OPC_RecordNode, // #2 = $b
/*   980*/  OPC_MoveParent,
/*   981*/  OPC_EmitMergeInputChains1_0,
/*   982*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                2/*#Ops*/, 1, 2, 
            // Src: (callseq_start (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b) - Complexity = 9
            // Dst: (ADJCALLSTACKDOWN (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b)
/*   989*/ /*SwitchOpcode*/ 21, TARGET_VAL(ISD::CALLSEQ_END),// ->1013
/*   992*/  OPC_RecordNode, // #0 = 'callseq_end' chained node
/*   993*/  OPC_CaptureGlueInput,
/*   994*/  OPC_RecordChild1, // #1 = $a
/*   995*/  OPC_MoveChild1,
/*   996*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*   999*/  OPC_MoveSibling2,
/*  1000*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*  1003*/  OPC_RecordNode, // #2 = $b
/*  1004*/  OPC_MoveParent,
/*  1005*/  OPC_EmitMergeInputChains1_0,
/*  1006*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b) - Complexity = 9
            // Dst: (ADJCALLSTACKUP (timm:{ *:[i32] }):$a, (timm:{ *:[i32] }):$b)
/*  1013*/ /*SwitchOpcode*/ 57, TARGET_VAL(ISD::SUB),// ->1073
/*  1016*/  OPC_Scope, 12, /*->1030*/ // 2 children in Scope
/*  1018*/   OPC_CheckChild0Integer, 0, 
/*  1020*/   OPC_RecordChild1, // #0 = $a
/*  1021*/   OPC_CheckTypeI32,
/*  1022*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::NEG),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (sub:{ *:[i32] } 0:{ *:[i32] }, GPR:{ *:[i32] }:$a) - Complexity = 8
             // Dst: (NEG:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1030*/  /*Scope*/ 41, /*->1072*/
/*  1031*/   OPC_RecordChild0, // #0 = $a
/*  1032*/   OPC_RecordChild1, // #1 = $i
/*  1033*/   OPC_Scope, 15, /*->1050*/ // 3 children in Scope
/*  1035*/    OPC_MoveChild1,
/*  1036*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1039*/    OPC_CheckPredicate6,  // Predicate_simm13_imm
/*  1040*/    OPC_MoveParent,
/*  1041*/    OPC_CheckTypeI32,
/*  1042*/    OPC_EmitConvertToTarget1,
/*  1043*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUBI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (SUBI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1050*/   /*Scope*/ 9, /*->1060*/
/*  1051*/    OPC_CheckTypeI32,
/*  1052*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (SUB:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1060*/   /*Scope*/ 10, /*->1071*/
/*  1061*/    OPC_CheckType, MVT::i16,
/*  1063*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (SUB_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1071*/   0, /*End of Scope*/
/*  1072*/  0, /*End of Scope*/
/*  1073*/ /*SwitchOpcode*/ 64, TARGET_VAL(ISD::XOR),// ->1140
/*  1076*/  OPC_RecordChild0, // #0 = $a
/*  1077*/  OPC_Scope, 9, /*->1088*/ // 2 children in Scope
/*  1079*/   OPC_CheckChild1Integer, 3, 
/*  1081*/   OPC_CheckTypeI32,
/*  1082*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_NOT),
                 MVT::i32, 1/*#Ops*/, 0, 
             // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, -1:{ *:[i32] }) - Complexity = 8
             // Dst: (C_NOT:{ *:[i32] } GPR:{ *:[i32] }:$a)
/*  1088*/  /*Scope*/ 50, /*->1139*/
/*  1089*/   OPC_RecordChild1, // #1 = $i
/*  1090*/   OPC_Scope, 15, /*->1107*/ // 4 children in Scope
/*  1092*/    OPC_MoveChild1,
/*  1093*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1096*/    OPC_CheckPredicate6,  // Predicate_simm13_imm
/*  1097*/    OPC_MoveParent,
/*  1098*/    OPC_CheckTypeI32,
/*  1099*/    OPC_EmitConvertToTarget1,
/*  1100*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XORI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (XORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1107*/   /*Scope*/ 9, /*->1117*/
/*  1108*/    OPC_CheckTypeI32,
/*  1109*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (XOR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1117*/   /*Scope*/ 9, /*->1127*/
/*  1118*/    OPC_CheckType, MVT::i1,
/*  1120*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PXOR),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (xor:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PXOR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  1127*/   /*Scope*/ 10, /*->1138*/
/*  1128*/    OPC_CheckType, MVT::i16,
/*  1130*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (XOR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1138*/   0, /*End of Scope*/
/*  1139*/  0, /*End of Scope*/
/*  1140*/ /*SwitchOpcode*/ 48, TARGET_VAL(ISD::SHL),// ->1191
/*  1143*/  OPC_RecordChild0, // #0 = $a
/*  1144*/  OPC_RecordChild1, // #1 = $i
/*  1145*/  OPC_Scope, 32, /*->1179*/ // 2 children in Scope
/*  1147*/   OPC_MoveChild1,
/*  1148*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1151*/   OPC_CheckTypeI32,
/*  1152*/   OPC_Scope, 11, /*->1165*/ // 2 children in Scope
/*  1154*/    OPC_CheckPredicate7,  // Predicate_uimm4_imm
/*  1155*/    OPC_MoveParent,
/*  1156*/    OPC_CheckTypeI32,
/*  1157*/    OPC_EmitConvertToTarget1,
/*  1158*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHLI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1165*/   /*Scope*/ 12, /*->1178*/
/*  1166*/    OPC_CheckPredicate, 8, // Predicate_uimm5_imm
/*  1168*/    OPC_MoveParent,
/*  1169*/    OPC_CheckTypeI32,
/*  1170*/    OPC_EmitConvertToTarget1,
/*  1171*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHLI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1178*/   0, /*End of Scope*/
/*  1179*/  /*Scope*/ 10, /*->1190*/
/*  1180*/   OPC_CheckChild1TypeI32,
/*  1181*/   OPC_CheckTypeI32,
/*  1182*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHL),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SHL:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1190*/  0, /*End of Scope*/
/*  1191*/ /*SwitchOpcode*/ 48, TARGET_VAL(ISD::SRL),// ->1242
/*  1194*/  OPC_RecordChild0, // #0 = $a
/*  1195*/  OPC_RecordChild1, // #1 = $i
/*  1196*/  OPC_Scope, 32, /*->1230*/ // 2 children in Scope
/*  1198*/   OPC_MoveChild1,
/*  1199*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1202*/   OPC_CheckTypeI32,
/*  1203*/   OPC_Scope, 11, /*->1216*/ // 2 children in Scope
/*  1205*/    OPC_CheckPredicate7,  // Predicate_uimm4_imm
/*  1206*/    OPC_MoveParent,
/*  1207*/    OPC_CheckTypeI32,
/*  1208*/    OPC_EmitConvertToTarget1,
/*  1209*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHRI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1216*/   /*Scope*/ 12, /*->1229*/
/*  1217*/    OPC_CheckPredicate, 8, // Predicate_uimm5_imm
/*  1219*/    OPC_MoveParent,
/*  1220*/    OPC_CheckTypeI32,
/*  1221*/    OPC_EmitConvertToTarget1,
/*  1222*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHRI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1229*/   0, /*End of Scope*/
/*  1230*/  /*Scope*/ 10, /*->1241*/
/*  1231*/   OPC_CheckChild1TypeI32,
/*  1232*/   OPC_CheckTypeI32,
/*  1233*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHR),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SHR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1241*/  0, /*End of Scope*/
/*  1242*/ /*SwitchOpcode*/ 48, TARGET_VAL(ISD::SRA),// ->1293
/*  1245*/  OPC_RecordChild0, // #0 = $a
/*  1246*/  OPC_RecordChild1, // #1 = $i
/*  1247*/  OPC_Scope, 32, /*->1281*/ // 2 children in Scope
/*  1249*/   OPC_MoveChild1,
/*  1250*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1253*/   OPC_CheckTypeI32,
/*  1254*/   OPC_Scope, 11, /*->1267*/ // 2 children in Scope
/*  1256*/    OPC_CheckPredicate7,  // Predicate_uimm4_imm
/*  1257*/    OPC_MoveParent,
/*  1258*/    OPC_CheckTypeI32,
/*  1259*/    OPC_EmitConvertToTarget1,
/*  1260*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SRAI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1267*/   /*Scope*/ 12, /*->1280*/
/*  1268*/    OPC_CheckPredicate, 8, // Predicate_uimm5_imm
/*  1270*/    OPC_MoveParent,
/*  1271*/    OPC_CheckTypeI32,
/*  1272*/    OPC_EmitConvertToTarget1,
/*  1273*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRAI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1280*/   0, /*End of Scope*/
/*  1281*/  /*Scope*/ 10, /*->1292*/
/*  1282*/   OPC_CheckChild1TypeI32,
/*  1283*/   OPC_CheckTypeI32,
/*  1284*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRA),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SRA:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1292*/  0, /*End of Scope*/
/*  1293*/ /*SwitchOpcode*/ 30, TARGET_VAL(ISD::MUL),// ->1326
/*  1296*/  OPC_RecordChild0, // #0 = $a
/*  1297*/  OPC_RecordChild1, // #1 = $i
/*  1298*/  OPC_Scope, 15, /*->1315*/ // 2 children in Scope
/*  1300*/   OPC_MoveChild1,
/*  1301*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1304*/   OPC_CheckPredicate6,  // Predicate_simm13_imm
/*  1305*/   OPC_MoveParent,
/*  1306*/   OPC_CheckTypeI32,
/*  1307*/   OPC_EmitConvertToTarget1,
/*  1308*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MULI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (MULI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1315*/  /*Scope*/ 9, /*->1325*/
/*  1316*/   OPC_CheckTypeI32,
/*  1317*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_LO),
                 MVT::i32, 3/*#Ops*/, 0, 1, 1, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MUL_LO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$b)
/*  1325*/  0, /*End of Scope*/
/*  1326*/ /*SwitchOpcode*/ 51, TARGET_VAL(ISD::OR),// ->1380
/*  1329*/  OPC_RecordChild0, // #0 = $a
/*  1330*/  OPC_RecordChild1, // #1 = $i
/*  1331*/  OPC_Scope, 15, /*->1348*/ // 4 children in Scope
/*  1333*/   OPC_MoveChild1,
/*  1334*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1337*/   OPC_CheckPredicate6,  // Predicate_simm13_imm
/*  1338*/   OPC_MoveParent,
/*  1339*/   OPC_CheckTypeI32,
/*  1340*/   OPC_EmitConvertToTarget1,
/*  1341*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ORI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (ORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1348*/  /*Scope*/ 9, /*->1358*/
/*  1349*/   OPC_CheckTypeI32,
/*  1350*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (OR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1358*/  /*Scope*/ 9, /*->1368*/
/*  1359*/   OPC_CheckType, MVT::i1,
/*  1361*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_POR),
                 MVT::i1, 2/*#Ops*/, 0, 1, 
             // Src: (or:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
             // Dst: (PSEUDO_POR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  1368*/  /*Scope*/ 10, /*->1379*/
/*  1369*/   OPC_CheckType, MVT::i16,
/*  1371*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (OR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1379*/  0, /*End of Scope*/
/*  1380*/ /*SwitchOpcode*/ 15, TARGET_VAL(CCVISD::CALL),// ->1398
/*  1383*/  OPC_RecordNode, // #0 = 'ccv_call' chained node
/*  1384*/  OPC_CaptureGlueInput,
/*  1385*/  OPC_RecordChild1, // #1 = $f
/*  1386*/  OPC_MoveChild1,
/*  1387*/  OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*  1390*/  OPC_MoveParent,
/*  1391*/  OPC_EmitMergeInputChains1_0,
/*  1392*/  OPC_MorphNodeTo0, TARGET_VAL(CCV::PSEUDO_CALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                1/*#Ops*/, 1, 
            // Src: (ccv_call (tglobaladdr:{ *:[i32] }):$f) - Complexity = 6
            // Dst: (PSEUDO_CALL (tglobaladdr:{ *:[i32] }):$f)
/*  1398*/ /*SwitchOpcode*/ 16, TARGET_VAL(ISD::BITCAST),// ->1417
/*  1401*/  OPC_RecordChild0, // #0 = $a
/*  1402*/  OPC_SwitchType /*2 cases */, 5, MVT::i32,// ->1410
/*  1405*/   OPC_CheckChild0Type, MVT::f32,
/*  1407*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[i32] }:$a
/*  1410*/  /*SwitchType*/ 4, MVT::f32,// ->1416
/*  1412*/   OPC_CheckChild0TypeI32,
/*  1413*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[f32] }:$a
/*  1416*/  0, // EndSwitchType
/*  1417*/ /*SwitchOpcode*/ 13, TARGET_VAL(ISD::BR),// ->1433
/*  1420*/  OPC_RecordNode, // #0 = 'br' chained node
/*  1421*/  OPC_RecordChild1, // #1 = $t
/*  1422*/  OPC_MoveChild1,
/*  1423*/  OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*  1426*/  OPC_MoveParent,
/*  1427*/  OPC_EmitMergeInputChains1_0,
/*  1428*/  OPC_MorphNodeTo0Chain, TARGET_VAL(CCV::C_BRA),
                1/*#Ops*/, 1, 
            // Src: (br (bb:{ *:[Other] }):$t) - Complexity = 3
            // Dst: (C_BRA (bb:{ *:[Other] }):$t)
/*  1433*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMIN),// ->1460
/*  1436*/  OPC_RecordChild0, // #0 = $a
/*  1437*/  OPC_RecordChild1, // #1 = $b
/*  1438*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->1449
/*  1441*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MIN_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1449*/  /*SwitchType*/ 8, MVT::i16,// ->1459
/*  1451*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MIN_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1459*/  0, // EndSwitchType
/*  1460*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMIN),// ->1474
/*  1463*/  OPC_RecordChild0, // #0 = $a
/*  1464*/  OPC_RecordChild1, // #1 = $b
/*  1465*/  OPC_CheckTypeI32,
/*  1466*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MIN_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1474*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMAX),// ->1501
/*  1477*/  OPC_RecordChild0, // #0 = $a
/*  1478*/  OPC_RecordChild1, // #1 = $b
/*  1479*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->1490
/*  1482*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MAX_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1490*/  /*SwitchType*/ 8, MVT::i16,// ->1500
/*  1492*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MAX_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1500*/  0, // EndSwitchType
/*  1501*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMAX),// ->1515
/*  1504*/  OPC_RecordChild0, // #0 = $a
/*  1505*/  OPC_RecordChild1, // #1 = $b
/*  1506*/  OPC_CheckTypeI32,
/*  1507*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MAX_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1515*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHS),// ->1529
/*  1518*/  OPC_RecordChild0, // #0 = $a
/*  1519*/  OPC_RecordChild1, // #1 = $b
/*  1520*/  OPC_CheckTypeI32,
/*  1521*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_S),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhs:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1529*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHU),// ->1543
/*  1532*/  OPC_RecordChild0, // #0 = $a
/*  1533*/  OPC_RecordChild1, // #1 = $b
/*  1534*/  OPC_CheckTypeI32,
/*  1535*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhu:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1543*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTPOP),// ->1557
/*  1546*/  OPC_RecordChild0, // #0 = $a
/*  1547*/  OPC_CheckChild0TypeI32,
/*  1548*/  OPC_CheckTypeI32,
/*  1549*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::POPC),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctpop:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (POPC:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1557*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTLZ),// ->1571
/*  1560*/  OPC_RecordChild0, // #0 = $a
/*  1561*/  OPC_CheckChild0TypeI32,
/*  1562*/  OPC_CheckTypeI32,
/*  1563*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CLZ),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctlz:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CLZ:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1571*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::BITREVERSE),// ->1584
/*  1574*/  OPC_RecordChild0, // #0 = $a
/*  1575*/  OPC_CheckTypeI32,
/*  1576*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::BREV),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (bitreverse:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (BREV:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1584*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ABS),// ->1597
/*  1587*/  OPC_RecordChild0, // #0 = $a
/*  1588*/  OPC_CheckTypeI32,
/*  1589*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::ABS),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (abs:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (ABS:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1597*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_SINT),// ->1610
/*  1600*/  OPC_RecordChild0, // #0 = $a
/*  1601*/  OPC_CheckTypeI32,
/*  1602*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_S32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_sint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_S32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1610*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_UINT),// ->1623
/*  1613*/  OPC_RecordChild0, // #0 = $a
/*  1614*/  OPC_CheckTypeI32,
/*  1615*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_U32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_uint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_U32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1623*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::TRUNCATE),// ->1635
/*  1626*/  OPC_RecordChild0, // #0 = $a
/*  1627*/  OPC_CheckType, MVT::i16,
/*  1629*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i16, 1/*#Ops*/, 0, 
            // Src: (trunc:{ *:[i16] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i16] } GPR:{ *:[i32] }:$a)
/*  1635*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ZERO_EXTEND),// ->1648
/*  1638*/  OPC_RecordChild0, // #0 = $a
/*  1639*/  OPC_CheckChild0Type, MVT::i16,
/*  1641*/  OPC_CheckTypeI32,
/*  1642*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i32, 1/*#Ops*/, 0, 
            // Src: (zext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i32] } GPR16:{ *:[i16] }:$a)
/*  1648*/ /*SwitchOpcode*/ 12, TARGET_VAL(ISD::SIGN_EXTEND),// ->1663
/*  1651*/  OPC_RecordChild0, // #0 = $a
/*  1652*/  OPC_CheckChild0Type, MVT::i16,
/*  1654*/  OPC_CheckTypeI32,
/*  1655*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_SEXT),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (CVT_SEXT:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a)
/*  1663*/ /*SwitchOpcode*/ 40, TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->1706
/*  1666*/  OPC_RecordChild0, // #0 = $a
/*  1667*/  OPC_MoveChild1,
/*  1668*/  OPC_CheckValueType, MVT::i16,
/*  1670*/  OPC_MoveParent,
/*  1671*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  1673*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 1,  // Results = #2
/*  1680*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  1682*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 3,  // Results = #4
/*  1689*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  1691*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 5,  // Results = #6
/*  1698*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_SEXT),
                MVT::i32, 3/*#Ops*/, 2, 4, 6, 
            // Src: (sext_inreg:{ *:[i32] } GPR:{ *:[i32] }:$a, i16:{ *:[Other] }) - Complexity = 3
            // Dst: (CVT_SEXT:{ *:[i32] } (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }), (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }), (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }))
/*  1706*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::ConstantFP),// ->1734
/*  1709*/  OPC_RecordNode, // #0 = $i
/*  1710*/  OPC_Scope, 11, /*->1723*/ // 2 children in Scope
/*  1712*/   OPC_CheckPredicate, 12, // Predicate_fpimm_small
/*  1714*/   OPC_EmitNodeXForm, 4, 0, // fpimm_bits
/*  1717*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] })<<P:Predicate_fpimm_small>>:$i - Complexity = 14
             // Dst: (MOVI:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  1723*/  /*Scope*/ 9, /*->1733*/
/*  1724*/   OPC_EmitNodeXForm, 4, 0, // fpimm_bits
/*  1727*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] }):$i - Complexity = 3
             // Dst: (MOVI48:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  1733*/  0, /*End of Scope*/
/*  1734*/ /*SwitchOpcode*/ 41, TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->1778
/*  1737*/  OPC_Scope, 12, /*->1751*/ // 3 children in Scope
/*  1739*/   OPC_CheckChild0Integer, 12|128,127/*16268*/, 
/*  1742*/   OPC_RecordChild1, // #0 = $a
/*  1743*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::RSQRT_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8134:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (RSQRT_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1751*/  /*Scope*/ 12, /*->1764*/
/*  1752*/   OPC_CheckChild0Integer, 102|128,127/*16358*/, 
/*  1755*/   OPC_RecordChild1, // #0 = $a
/*  1756*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SIN_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 8179:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (SIN_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1764*/  /*Scope*/ 12, /*->1777*/
/*  1765*/   OPC_CheckChild0Integer, 96|128,118/*15200*/, 
/*  1768*/   OPC_RecordChild1, // #0 = $a
/*  1769*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::COS_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (intrinsic_wo_chain:{ *:[f32] } 7600:{ *:[iPTR] }, GPR:{ *:[f32] }:$a) - Complexity = 8
             // Dst: (COS_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1777*/  0, /*End of Scope*/
/*  1778*/ /*SwitchOpcode*/ 56, TARGET_VAL(ISD::FDIV),// ->1837
/*  1781*/  OPC_MoveChild0,
/*  1782*/  OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*  1785*/  OPC_Scope, 12, /*->1799*/ // 2 children in Scope
/*  1787*/   OPC_CheckPredicate, 13, // Predicate_fpimm_one
/*  1789*/   OPC_MoveParent,
/*  1790*/   OPC_RecordChild1, // #0 = $a
/*  1791*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::f32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (fdiv:{ *:[f32] } (fpimm:{ *:[f32] })<<P:Predicate_fpimm_one>>, GPR:{ *:[f32] }:$a) - Complexity = 7
             // Dst: (RCP_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1799*/  /*Scope*/ 36, /*->1836*/
/*  1800*/   OPC_CheckPredicate, 14, // Predicate_fpimm_minus_one
/*  1802*/   OPC_MoveParent,
/*  1803*/   OPC_RecordChild1, // #0 = $a
/*  1804*/   OPC_EmitNode1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #1
/*  1812*/   OPC_EmitNode1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #2
/*  1820*/   OPC_EmitNode1None, TARGET_VAL(CCV::RCP_F32),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0,  // Results = #3
/*  1828*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::FNEG_F0),
                 MVT::f32, 3/*#Ops*/, 1, 2, 3, 
             // Src: (fdiv:{ *:[f32] } (fpimm:{ *:[f32] })<<P:Predicate_fpimm_minus_one>>, GPR:{ *:[f32] }:$a) - Complexity = 7
             // Dst: (FNEG_F0:{ *:[f32] } (RCP_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a), (RCP_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a), (RCP_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a))
/*  1836*/  0, /*End of Scope*/
/*  1837*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FADD),// ->1849
/*  1840*/  OPC_RecordChild0, // #0 = $a
/*  1841*/  OPC_RecordChild1, // #1 = $b
/*  1842*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FADD),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fadd:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FADD:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1849*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMUL),// ->1861
/*  1852*/  OPC_RecordChild0, // #0 = $a
/*  1853*/  OPC_RecordChild1, // #1 = $b
/*  1854*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMUL),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmul:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMUL:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1861*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FSUB),// ->1874
/*  1864*/  OPC_RecordChild0, // #0 = $a
/*  1865*/  OPC_RecordChild1, // #1 = $b
/*  1866*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FSUB),
                MVT::f32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (fsub:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (FSUB:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$a)
/*  1874*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMINNUM),// ->1886
/*  1877*/  OPC_RecordChild0, // #0 = $a
/*  1878*/  OPC_RecordChild1, // #1 = $b
/*  1879*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMIN),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fminnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMIN:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1886*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMAXNUM),// ->1898
/*  1889*/  OPC_RecordChild0, // #0 = $a
/*  1890*/  OPC_RecordChild1, // #1 = $b
/*  1891*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMAX),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmaxnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMAX:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1898*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FNEG),// ->1910
/*  1901*/  OPC_RecordChild0, // #0 = $a
/*  1902*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FNEG_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fneg:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FNEG_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1910*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FABS),// ->1922
/*  1913*/  OPC_RecordChild0, // #0 = $a
/*  1914*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FABS_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fabs:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FABS_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1922*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::FMA),// ->1936
/*  1925*/  OPC_RecordChild0, // #0 = $a
/*  1926*/  OPC_RecordChild1, // #1 = $b
/*  1927*/  OPC_RecordChild2, // #2 = $c
/*  1928*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FFMA_F0),
                MVT::f32, 3/*#Ops*/, 0, 1, 2, 
            // Src: (fma:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c) - Complexity = 3
            // Dst: (FFMA_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c)
/*  1936*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::SINT_TO_FP),// ->1949
/*  1939*/  OPC_RecordChild0, // #0 = $a
/*  1940*/  OPC_CheckChild0TypeI32,
/*  1941*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_S32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_S32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1949*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::UINT_TO_FP),// ->1962
/*  1952*/  OPC_RecordChild0, // #0 = $a
/*  1953*/  OPC_CheckChild0TypeI32,
/*  1954*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_U32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (uint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_U32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1962*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FSQRT),// ->1974
/*  1965*/  OPC_RecordChild0, // #0 = $a
/*  1966*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::SQRT_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fsqrt:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (SQRT_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1974*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FEXP2),// ->1986
/*  1977*/  OPC_RecordChild0, // #0 = $a
/*  1978*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::EX2_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fexp2:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (EX2_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1986*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FLOG2),// ->1998
/*  1989*/  OPC_RecordChild0, // #0 = $a
/*  1990*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::LG2_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (flog2:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (LG2_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1998*/ 0, // EndSwitchOpcode
    0
  }; // Total Array size is 2000 bytes

  // Opcode Histogram:
  // #OPC_Scope                                = 35
  // #OPC_RecordNode                           = 11
  // #OPC_RecordChild                          = 114
  // #OPC_RecordMemRef                         = 2
  // #OPC_CaptureGlueInput                     = 2
  // #OPC_MoveChild                            = 37
  // #OPC_MoveSibling                          = 2
  // #OPC_MoveParent                           = 56
  // #OPC_CheckSame                            = 0
  // #OPC_CheckChildSame                       = 0
  // #OPC_CheckPatternPredicate                = 0
  // #OPC_CheckPredicate                       = 85
  // #OPC_CheckOpcode                          = 38
  // #OPC_SwitchOpcode                         = 1
  // #OPC_CheckType                            = 80
  // #OPC_SwitchType                           = 7
  // #OPC_CheckChildType                       = 27
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
  // #OPC_EmitInteger                          = 32
  // #OPC_EmitStringInteger                    = 3
  // #OPC_EmitRegister                         = 0
  // #OPC_EmitConvertToTarget                  = 20
  // #OPC_EmitMergeInputChains                 = 28
  // #OPC_EmitCopyToReg                        = 0
  // #OPC_EmitNode                             = 7
  // #OPC_EmitNodeXForm                        = 6
  // #OPC_CompleteMatch                        = 2
  // #OPC_MorphNodeTo                          = 109

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
    // Predicate_unindexedstore
    SDNode *N = Node;
    (void)N;
if (cast<StoreSDNode>(N)->getAddressingMode() != ISD::UNINDEXED) return false;
return true;

  }
  case 1: {
    // Predicate_store
    SDNode *N = Node;
    (void)N;
 if (cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 2: {
    // Predicate_st_shared
    SDNode *N = Node;
    (void)N;

  return cast<StoreSDNode>(N)->getAddressSpace() == 3;

  }
  case 3: {
    // Predicate_unindexedload
    SDNode *N = Node;
    (void)N;
if (cast<LoadSDNode>(N)->getAddressingMode() != ISD::UNINDEXED) return false;
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
    // Predicate_ld_shared
    SDNode *N = Node;
    (void)N;

  return cast<LoadSDNode>(N)->getAddressSpace() == 3;

  }
  case 6: {
    // Predicate_simm13_imm
    // Predicate_simm13_imm16
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return isInt<13>(Imm); 
  }
  case 7: {
    // Predicate_uimm4_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < 16; 
  }
  case 8: {
    // Predicate_uimm5_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < 32; 
  }
  case 9: {
    // Predicate_uimm29_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && isUInt<29>(Imm); 
  }
  case 10: {
    // Predicate_uimm17_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
 return Imm >= 0 && Imm < (1 << 17); 
  }
  case 11: {
    // Predicate_simm13_not_imm
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

  return !isInt<13>(Imm) && isInt<13>(~Imm);

  }
  case 12: {
    // Predicate_fpimm_small
    auto *N = cast<ConstantFPSDNode>(Node);
    (void)N;

  return N->getValueAPF().bitcastToAPInt().getZExtValue() < (1u << 17);

  }
  case 13: {
    // Predicate_fpimm_one
    auto *N = cast<ConstantFPSDNode>(Node);
    (void)N;
 return N->isExactlyValue(1.0); 
  }
  case 14: {
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
