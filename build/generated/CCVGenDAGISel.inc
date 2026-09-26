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
/*     0*/ OPC_SwitchOpcode /*43 cases */, 114, TARGET_VAL(ISD::ADD),// ->118
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
/*   774*/ /*SwitchOpcode*/ 57, TARGET_VAL(ISD::Constant),// ->834
/*   777*/  OPC_SwitchType /*2 cases */, 23, MVT::i32,// ->803
/*   780*/   OPC_RecordNode, // #0 = $i
/*   781*/   OPC_Scope, 9, /*->792*/ // 2 children in Scope
/*   783*/    OPC_CheckPredicate, 10, // Predicate_uimm17_imm
/*   785*/    OPC_EmitConvertToTarget0,
/*   786*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                  MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:{ *:[i32] })<<P:Predicate_uimm17_imm>>:$i - Complexity = 14
              // Dst: (MOVI:{ *:[i32] } (imm:{ *:[i32] }):$i)
/*   792*/   /*Scope*/ 9, /*->802*/
/*   793*/    OPC_EmitNodeXForm, 1, 0, // imm_bits32
/*   796*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                  MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:{ *:[i32] }):$i - Complexity = 3
              // Dst: (MOVI48:{ *:[i32] } (imm_bits32:{ *:[i32] } ?:{ *:[i32] }:$i))
/*   802*/   0, /*End of Scope*/
/*   803*/  /*SwitchType*/ 28, MVT::i1,// ->833
/*   805*/   OPC_Scope, 14, /*->821*/ // 2 children in Scope
/*   807*/    OPC_CheckInteger, 3, 
/*   809*/    OPC_EmitInteger32, 126|128,127|128,127|128,127|128,31/*8589934590*/, 
/*   815*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                  MVT::i1, 1/*#Ops*/, 0, 
              // Src: -1:{ *:[i1] } - Complexity = 5
              // Dst: (PMOV_IMM:{ *:[i1] } 4294967295:{ *:[i32] })
/*   821*/   /*Scope*/ 10, /*->832*/
/*   822*/    OPC_CheckInteger, 0, 
/*   824*/    OPC_EmitInteger32, 0, 
/*   826*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PMOV_IMM),
                  MVT::i1, 1/*#Ops*/, 0, 
              // Src: 0:{ *:[i1] } - Complexity = 5
              // Dst: (PMOV_IMM:{ *:[i1] } 0:{ *:[i32] })
/*   832*/   0, /*End of Scope*/
/*   833*/  0, // EndSwitchType
/*   834*/ /*SwitchOpcode*/ 110, TARGET_VAL(ISD::AND),// ->947
/*   837*/  OPC_Scope, 18, /*->857*/ // 3 children in Scope
/*   839*/   OPC_RecordChild0, // #0 = $a
/*   840*/   OPC_MoveChild1,
/*   841*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*   844*/   OPC_RecordChild0, // #1 = $b
/*   845*/   OPC_CheckChild1Integer, 3, 
/*   847*/   OPC_MoveParent,
/*   848*/   OPC_CheckTypeI32,
/*   849*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] })) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   857*/  /*Scope*/ 18, /*->876*/
/*   858*/   OPC_MoveChild0,
/*   859*/   OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*   862*/   OPC_RecordChild0, // #0 = $b
/*   863*/   OPC_CheckChild1Integer, 3, 
/*   865*/   OPC_MoveParent,
/*   866*/   OPC_RecordChild1, // #1 = $a
/*   867*/   OPC_CheckTypeI32,
/*   868*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDN),
                 MVT::i32, 3/*#Ops*/, 1, 0, 1, 
             // Src: (and:{ *:[i32] } (xor:{ *:[i32] } GPR:{ *:[i32] }:$b, -1:{ *:[i32] }), GPR:{ *:[i32] }:$a) - Complexity = 11
             // Dst: (ANDN:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   876*/  /*Scope*/ 69, /*->946*/
/*   877*/   OPC_RecordChild0, // #0 = $a
/*   878*/   OPC_RecordChild1, // #1 = $i
/*   879*/   OPC_Scope, 33, /*->914*/ // 4 children in Scope
/*   881*/    OPC_MoveChild1,
/*   882*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   885*/    OPC_Scope, 14, /*->901*/ // 2 children in Scope
/*   887*/     OPC_CheckPredicate, 11, // Predicate_simm13_not_imm
/*   889*/     OPC_MoveParent,
/*   890*/     OPC_CheckTypeI32,
/*   891*/     OPC_EmitNodeXForm, 2, 1, // imm_not
/*   894*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDNI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_not_imm>>:$i) - Complexity = 7
               // Dst: (ANDNI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm_not:{ *:[i32] } ?:{ *:[i32] }:$i))
/*   901*/    /*Scope*/ 11, /*->913*/
/*   902*/     OPC_CheckPredicate6,  // Predicate_simm13_imm
/*   903*/     OPC_MoveParent,
/*   904*/     OPC_CheckTypeI32,
/*   905*/     OPC_EmitConvertToTarget1,
/*   906*/     OPC_MorphNodeTo1None, TARGET_VAL(CCV::ANDI),
                   MVT::i32, 2/*#Ops*/, 0, 2, 
               // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
               // Dst: (ANDI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*   913*/    0, /*End of Scope*/
/*   914*/   /*Scope*/ 9, /*->924*/
/*   915*/    OPC_CheckTypeI32,
/*   916*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (AND:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   924*/   /*Scope*/ 9, /*->934*/
/*   925*/    OPC_CheckType, MVT::i1,
/*   927*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PAND),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (and:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PAND:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*   934*/   /*Scope*/ 10, /*->945*/
/*   935*/    OPC_CheckType, MVT::i16,
/*   937*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::AND_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (and:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (AND_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*   945*/   0, /*End of Scope*/
/*   946*/  0, /*End of Scope*/
/*   947*/ /*SwitchOpcode*/ 57, TARGET_VAL(ISD::SUB),// ->1007
/*   950*/  OPC_Scope, 12, /*->964*/ // 2 children in Scope
/*   952*/   OPC_CheckChild0Integer, 0, 
/*   954*/   OPC_RecordChild1, // #0 = $a
/*   955*/   OPC_CheckTypeI32,
/*   956*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::NEG),
                 MVT::i32, 3/*#Ops*/, 0, 0, 0, 
             // Src: (sub:{ *:[i32] } 0:{ *:[i32] }, GPR:{ *:[i32] }:$a) - Complexity = 8
             // Dst: (NEG:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*   964*/  /*Scope*/ 41, /*->1006*/
/*   965*/   OPC_RecordChild0, // #0 = $a
/*   966*/   OPC_RecordChild1, // #1 = $i
/*   967*/   OPC_Scope, 15, /*->984*/ // 3 children in Scope
/*   969*/    OPC_MoveChild1,
/*   970*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*   973*/    OPC_CheckPredicate6,  // Predicate_simm13_imm
/*   974*/    OPC_MoveParent,
/*   975*/    OPC_CheckTypeI32,
/*   976*/    OPC_EmitConvertToTarget1,
/*   977*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUBI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (SUBI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*   984*/   /*Scope*/ 9, /*->994*/
/*   985*/    OPC_CheckTypeI32,
/*   986*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (SUB:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*   994*/   /*Scope*/ 10, /*->1005*/
/*   995*/    OPC_CheckType, MVT::i16,
/*   997*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SUB_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (sub:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (SUB_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1005*/   0, /*End of Scope*/
/*  1006*/  0, /*End of Scope*/
/*  1007*/ /*SwitchOpcode*/ 64, TARGET_VAL(ISD::XOR),// ->1074
/*  1010*/  OPC_RecordChild0, // #0 = $a
/*  1011*/  OPC_Scope, 9, /*->1022*/ // 2 children in Scope
/*  1013*/   OPC_CheckChild1Integer, 3, 
/*  1015*/   OPC_CheckTypeI32,
/*  1016*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_NOT),
                 MVT::i32, 1/*#Ops*/, 0, 
             // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, -1:{ *:[i32] }) - Complexity = 8
             // Dst: (C_NOT:{ *:[i32] } GPR:{ *:[i32] }:$a)
/*  1022*/  /*Scope*/ 50, /*->1073*/
/*  1023*/   OPC_RecordChild1, // #1 = $i
/*  1024*/   OPC_Scope, 15, /*->1041*/ // 4 children in Scope
/*  1026*/    OPC_MoveChild1,
/*  1027*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1030*/    OPC_CheckPredicate6,  // Predicate_simm13_imm
/*  1031*/    OPC_MoveParent,
/*  1032*/    OPC_CheckTypeI32,
/*  1033*/    OPC_EmitConvertToTarget1,
/*  1034*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XORI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
              // Dst: (XORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1041*/   /*Scope*/ 9, /*->1051*/
/*  1042*/    OPC_CheckTypeI32,
/*  1043*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR),
                  MVT::i32, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
              // Dst: (XOR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1051*/   /*Scope*/ 9, /*->1061*/
/*  1052*/    OPC_CheckType, MVT::i1,
/*  1054*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_PXOR),
                  MVT::i1, 2/*#Ops*/, 0, 1, 
              // Src: (xor:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
              // Dst: (PSEUDO_PXOR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  1061*/   /*Scope*/ 10, /*->1072*/
/*  1062*/    OPC_CheckType, MVT::i16,
/*  1064*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::XOR_W16),
                  MVT::i16, 3/*#Ops*/, 0, 1, 0, 
              // Src: (xor:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
              // Dst: (XOR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1072*/   0, /*End of Scope*/
/*  1073*/  0, /*End of Scope*/
/*  1074*/ /*SwitchOpcode*/ 48, TARGET_VAL(ISD::SHL),// ->1125
/*  1077*/  OPC_RecordChild0, // #0 = $a
/*  1078*/  OPC_RecordChild1, // #1 = $i
/*  1079*/  OPC_Scope, 32, /*->1113*/ // 2 children in Scope
/*  1081*/   OPC_MoveChild1,
/*  1082*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1085*/   OPC_CheckTypeI32,
/*  1086*/   OPC_Scope, 11, /*->1099*/ // 2 children in Scope
/*  1088*/    OPC_CheckPredicate7,  // Predicate_uimm4_imm
/*  1089*/    OPC_MoveParent,
/*  1090*/    OPC_CheckTypeI32,
/*  1091*/    OPC_EmitConvertToTarget1,
/*  1092*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHLI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1099*/   /*Scope*/ 12, /*->1112*/
/*  1100*/    OPC_CheckPredicate, 8, // Predicate_uimm5_imm
/*  1102*/    OPC_MoveParent,
/*  1103*/    OPC_CheckTypeI32,
/*  1104*/    OPC_EmitConvertToTarget1,
/*  1105*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHLI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SHLI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1112*/   0, /*End of Scope*/
/*  1113*/  /*Scope*/ 10, /*->1124*/
/*  1114*/   OPC_CheckChild1TypeI32,
/*  1115*/   OPC_CheckTypeI32,
/*  1116*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHL),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SHL:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1124*/  0, /*End of Scope*/
/*  1125*/ /*SwitchOpcode*/ 48, TARGET_VAL(ISD::SRL),// ->1176
/*  1128*/  OPC_RecordChild0, // #0 = $a
/*  1129*/  OPC_RecordChild1, // #1 = $i
/*  1130*/  OPC_Scope, 32, /*->1164*/ // 2 children in Scope
/*  1132*/   OPC_MoveChild1,
/*  1133*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1136*/   OPC_CheckTypeI32,
/*  1137*/   OPC_Scope, 11, /*->1150*/ // 2 children in Scope
/*  1139*/    OPC_CheckPredicate7,  // Predicate_uimm4_imm
/*  1140*/    OPC_MoveParent,
/*  1141*/    OPC_CheckTypeI32,
/*  1142*/    OPC_EmitConvertToTarget1,
/*  1143*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SHRI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1150*/   /*Scope*/ 12, /*->1163*/
/*  1151*/    OPC_CheckPredicate, 8, // Predicate_uimm5_imm
/*  1153*/    OPC_MoveParent,
/*  1154*/    OPC_CheckTypeI32,
/*  1155*/    OPC_EmitConvertToTarget1,
/*  1156*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHRI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SHRI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1163*/   0, /*End of Scope*/
/*  1164*/  /*Scope*/ 10, /*->1175*/
/*  1165*/   OPC_CheckChild1TypeI32,
/*  1166*/   OPC_CheckTypeI32,
/*  1167*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SHR),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SHR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1175*/  0, /*End of Scope*/
/*  1176*/ /*SwitchOpcode*/ 48, TARGET_VAL(ISD::SRA),// ->1227
/*  1179*/  OPC_RecordChild0, // #0 = $a
/*  1180*/  OPC_RecordChild1, // #1 = $i
/*  1181*/  OPC_Scope, 32, /*->1215*/ // 2 children in Scope
/*  1183*/   OPC_MoveChild1,
/*  1184*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1187*/   OPC_CheckTypeI32,
/*  1188*/   OPC_Scope, 11, /*->1201*/ // 2 children in Scope
/*  1190*/    OPC_CheckPredicate7,  // Predicate_uimm4_imm
/*  1191*/    OPC_MoveParent,
/*  1192*/    OPC_CheckTypeI32,
/*  1193*/    OPC_EmitConvertToTarget1,
/*  1194*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_SRAI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm4_imm>>:$i) - Complexity = 7
              // Dst: (C_SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1201*/   /*Scope*/ 12, /*->1214*/
/*  1202*/    OPC_CheckPredicate, 8, // Predicate_uimm5_imm
/*  1204*/    OPC_MoveParent,
/*  1205*/    OPC_CheckTypeI32,
/*  1206*/    OPC_EmitConvertToTarget1,
/*  1207*/    OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRAI),
                  MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_uimm5_imm>>:$i) - Complexity = 7
              // Dst: (SRAI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1214*/   0, /*End of Scope*/
/*  1215*/  /*Scope*/ 10, /*->1226*/
/*  1216*/   OPC_CheckChild1TypeI32,
/*  1217*/   OPC_CheckTypeI32,
/*  1218*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::SRA),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (SRA:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1226*/  0, /*End of Scope*/
/*  1227*/ /*SwitchOpcode*/ 30, TARGET_VAL(ISD::MUL),// ->1260
/*  1230*/  OPC_RecordChild0, // #0 = $a
/*  1231*/  OPC_RecordChild1, // #1 = $i
/*  1232*/  OPC_Scope, 15, /*->1249*/ // 2 children in Scope
/*  1234*/   OPC_MoveChild1,
/*  1235*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1238*/   OPC_CheckPredicate6,  // Predicate_simm13_imm
/*  1239*/   OPC_MoveParent,
/*  1240*/   OPC_CheckTypeI32,
/*  1241*/   OPC_EmitConvertToTarget1,
/*  1242*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MULI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (MULI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1249*/  /*Scope*/ 9, /*->1259*/
/*  1250*/   OPC_CheckTypeI32,
/*  1251*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_LO),
                 MVT::i32, 3/*#Ops*/, 0, 1, 1, 
             // Src: (mul:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MUL_LO:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$b)
/*  1259*/  0, /*End of Scope*/
/*  1260*/ /*SwitchOpcode*/ 51, TARGET_VAL(ISD::OR),// ->1314
/*  1263*/  OPC_RecordChild0, // #0 = $a
/*  1264*/  OPC_RecordChild1, // #1 = $i
/*  1265*/  OPC_Scope, 15, /*->1282*/ // 4 children in Scope
/*  1267*/   OPC_MoveChild1,
/*  1268*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*  1271*/   OPC_CheckPredicate6,  // Predicate_simm13_imm
/*  1272*/   OPC_MoveParent,
/*  1273*/   OPC_CheckTypeI32,
/*  1274*/   OPC_EmitConvertToTarget1,
/*  1275*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::ORI),
                 MVT::i32, 2/*#Ops*/, 0, 2, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] })<<P:Predicate_simm13_imm>>:$i) - Complexity = 7
             // Dst: (ORI:{ *:[i32] } GPR:{ *:[i32] }:$a, (imm:{ *:[i32] }):$i)
/*  1282*/  /*Scope*/ 9, /*->1292*/
/*  1283*/   OPC_CheckTypeI32,
/*  1284*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (OR:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1292*/  /*Scope*/ 9, /*->1302*/
/*  1293*/   OPC_CheckType, MVT::i1,
/*  1295*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::PSEUDO_POR),
                 MVT::i1, 2/*#Ops*/, 0, 1, 
             // Src: (or:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b) - Complexity = 3
             // Dst: (PSEUDO_POR:{ *:[i1] } PR:{ *:[i1] }:$a, PR:{ *:[i1] }:$b)
/*  1302*/  /*Scope*/ 10, /*->1313*/
/*  1303*/   OPC_CheckType, MVT::i16,
/*  1305*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::OR_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (or:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (OR_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1313*/  0, /*End of Scope*/
/*  1314*/ /*SwitchOpcode*/ 16, TARGET_VAL(ISD::BITCAST),// ->1333
/*  1317*/  OPC_RecordChild0, // #0 = $a
/*  1318*/  OPC_SwitchType /*2 cases */, 5, MVT::i32,// ->1326
/*  1321*/   OPC_CheckChild0Type, MVT::f32,
/*  1323*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[i32] }:$a
/*  1326*/  /*SwitchType*/ 4, MVT::f32,// ->1332
/*  1328*/   OPC_CheckChild0TypeI32,
/*  1329*/   OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
              // Dst: GPR:{ *:[f32] }:$a
/*  1332*/  0, // EndSwitchType
/*  1333*/ /*SwitchOpcode*/ 13, TARGET_VAL(ISD::BR),// ->1349
/*  1336*/  OPC_RecordNode, // #0 = 'br' chained node
/*  1337*/  OPC_RecordChild1, // #1 = $t
/*  1338*/  OPC_MoveChild1,
/*  1339*/  OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*  1342*/  OPC_MoveParent,
/*  1343*/  OPC_EmitMergeInputChains1_0,
/*  1344*/  OPC_MorphNodeTo0Chain, TARGET_VAL(CCV::C_BRA),
                1/*#Ops*/, 1, 
            // Src: (br (bb:{ *:[Other] }):$t) - Complexity = 3
            // Dst: (C_BRA (bb:{ *:[Other] }):$t)
/*  1349*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMIN),// ->1376
/*  1352*/  OPC_RecordChild0, // #0 = $a
/*  1353*/  OPC_RecordChild1, // #1 = $b
/*  1354*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->1365
/*  1357*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MIN_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1365*/  /*SwitchType*/ 8, MVT::i16,// ->1375
/*  1367*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smin:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MIN_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1375*/  0, // EndSwitchType
/*  1376*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMIN),// ->1390
/*  1379*/  OPC_RecordChild0, // #0 = $a
/*  1380*/  OPC_RecordChild1, // #1 = $b
/*  1381*/  OPC_CheckTypeI32,
/*  1382*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MIN_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umin:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MIN_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1390*/ /*SwitchOpcode*/ 24, TARGET_VAL(ISD::SMAX),// ->1417
/*  1393*/  OPC_RecordChild0, // #0 = $a
/*  1394*/  OPC_RecordChild1, // #1 = $b
/*  1395*/  OPC_SwitchType /*2 cases */, 8, MVT::i32,// ->1406
/*  1398*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S),
                 MVT::i32, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
             // Dst: (MAX_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1406*/  /*SwitchType*/ 8, MVT::i16,// ->1416
/*  1408*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_S_W16),
                 MVT::i16, 3/*#Ops*/, 0, 1, 0, 
             // Src: (smax:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b) - Complexity = 3
             // Dst: (MAX_S_W16:{ *:[i16] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$b, GPR16:{ *:[i16] }:$a)
/*  1416*/  0, // EndSwitchType
/*  1417*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UMAX),// ->1431
/*  1420*/  OPC_RecordChild0, // #0 = $a
/*  1421*/  OPC_RecordChild1, // #1 = $b
/*  1422*/  OPC_CheckTypeI32,
/*  1423*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MAX_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (umax:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MAX_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1431*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHS),// ->1445
/*  1434*/  OPC_RecordChild0, // #0 = $a
/*  1435*/  OPC_RecordChild1, // #1 = $b
/*  1436*/  OPC_CheckTypeI32,
/*  1437*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_S),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhs:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_S:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1445*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MULHU),// ->1459
/*  1448*/  OPC_RecordChild0, // #0 = $a
/*  1449*/  OPC_RecordChild1, // #1 = $b
/*  1450*/  OPC_CheckTypeI32,
/*  1451*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::MUL_HI_U),
                MVT::i32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (mulhu:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b) - Complexity = 3
            // Dst: (MUL_HI_U:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$b, GPR:{ *:[i32] }:$a)
/*  1459*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTPOP),// ->1473
/*  1462*/  OPC_RecordChild0, // #0 = $a
/*  1463*/  OPC_CheckChild0TypeI32,
/*  1464*/  OPC_CheckTypeI32,
/*  1465*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::POPC),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctpop:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (POPC:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1473*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::CTLZ),// ->1487
/*  1476*/  OPC_RecordChild0, // #0 = $a
/*  1477*/  OPC_CheckChild0TypeI32,
/*  1478*/  OPC_CheckTypeI32,
/*  1479*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CLZ),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (ctlz:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CLZ:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1487*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::BITREVERSE),// ->1500
/*  1490*/  OPC_RecordChild0, // #0 = $a
/*  1491*/  OPC_CheckTypeI32,
/*  1492*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::BREV),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (bitreverse:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (BREV:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1500*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ABS),// ->1513
/*  1503*/  OPC_RecordChild0, // #0 = $a
/*  1504*/  OPC_CheckTypeI32,
/*  1505*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::ABS),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (abs:{ *:[i32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (ABS:{ *:[i32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1513*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_SINT),// ->1526
/*  1516*/  OPC_RecordChild0, // #0 = $a
/*  1517*/  OPC_CheckTypeI32,
/*  1518*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_S32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_sint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_S32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1526*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FP_TO_UINT),// ->1539
/*  1529*/  OPC_RecordChild0, // #0 = $a
/*  1530*/  OPC_CheckTypeI32,
/*  1531*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_U32_F32),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fp_to_uint:{ *:[i32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (CVT_U32_F32:{ *:[i32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1539*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::TRUNCATE),// ->1551
/*  1542*/  OPC_RecordChild0, // #0 = $a
/*  1543*/  OPC_CheckType, MVT::i16,
/*  1545*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i16, 1/*#Ops*/, 0, 
            // Src: (trunc:{ *:[i16] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i16] } GPR:{ *:[i32] }:$a)
/*  1551*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::ZERO_EXTEND),// ->1564
/*  1554*/  OPC_RecordChild0, // #0 = $a
/*  1555*/  OPC_CheckChild0Type, MVT::i16,
/*  1557*/  OPC_CheckTypeI32,
/*  1558*/  OPC_MorphNodeTo1None, TARGET_VAL(TargetOpcode::COPY),
                MVT::i32, 1/*#Ops*/, 0, 
            // Src: (zext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (COPY:{ *:[i32] } GPR16:{ *:[i16] }:$a)
/*  1564*/ /*SwitchOpcode*/ 12, TARGET_VAL(ISD::SIGN_EXTEND),// ->1579
/*  1567*/  OPC_RecordChild0, // #0 = $a
/*  1568*/  OPC_CheckChild0Type, MVT::i16,
/*  1570*/  OPC_CheckTypeI32,
/*  1571*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_SEXT),
                MVT::i32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sext:{ *:[i32] } GPR16:{ *:[i16] }:$a) - Complexity = 3
            // Dst: (CVT_SEXT:{ *:[i32] } GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a, GPR16:{ *:[i16] }:$a)
/*  1579*/ /*SwitchOpcode*/ 40, TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->1622
/*  1582*/  OPC_RecordChild0, // #0 = $a
/*  1583*/  OPC_MoveChild1,
/*  1584*/  OPC_CheckValueType, MVT::i16,
/*  1586*/  OPC_MoveParent,
/*  1587*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  1589*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 1,  // Results = #2
/*  1596*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  1598*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 3,  // Results = #4
/*  1605*/  OPC_EmitStringInteger32, CCV::GPR16RegClassID,
/*  1607*/  OPC_EmitNode1None, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS),
                MVT::i16, 2/*#Ops*/, 0, 5,  // Results = #6
/*  1614*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_SEXT),
                MVT::i32, 3/*#Ops*/, 2, 4, 6, 
            // Src: (sext_inreg:{ *:[i32] } GPR:{ *:[i32] }:$a, i16:{ *:[Other] }) - Complexity = 3
            // Dst: (CVT_SEXT:{ *:[i32] } (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }), (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }), (COPY_TO_REGCLASS:{ *:[i16] } GPR:{ *:[i32] }:$a, GPR16:{ *:[i32] }))
/*  1622*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::ConstantFP),// ->1650
/*  1625*/  OPC_RecordNode, // #0 = $i
/*  1626*/  OPC_Scope, 11, /*->1639*/ // 2 children in Scope
/*  1628*/   OPC_CheckPredicate, 12, // Predicate_fpimm_small
/*  1630*/   OPC_EmitNodeXForm, 3, 0, // fpimm_bits
/*  1633*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] })<<P:Predicate_fpimm_small>>:$i - Complexity = 14
             // Dst: (MOVI:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  1639*/  /*Scope*/ 9, /*->1649*/
/*  1640*/   OPC_EmitNodeXForm, 3, 0, // fpimm_bits
/*  1643*/   OPC_MorphNodeTo1None, TARGET_VAL(CCV::MOVI48),
                 MVT::f32, 1/*#Ops*/, 1, 
             // Src: (fpimm:{ *:[f32] }):$i - Complexity = 3
             // Dst: (MOVI48:{ *:[f32] } (fpimm_bits:{ *:[i32] } ?:{ *:[f32] }:$i))
/*  1649*/  0, /*End of Scope*/
/*  1650*/ /*SwitchOpcode*/ 16, TARGET_VAL(ISD::FDIV),// ->1669
/*  1653*/  OPC_MoveChild0,
/*  1654*/  OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*  1657*/  OPC_CheckPredicate, 13, // Predicate_fpimm_one
/*  1659*/  OPC_MoveParent,
/*  1660*/  OPC_RecordChild1, // #0 = $a
/*  1661*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::RCP_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fdiv:{ *:[f32] } (fpimm:{ *:[f32] })<<P:Predicate_fpimm_one>>, GPR:{ *:[f32] }:$a) - Complexity = 7
            // Dst: (RCP_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1669*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FADD),// ->1681
/*  1672*/  OPC_RecordChild0, // #0 = $a
/*  1673*/  OPC_RecordChild1, // #1 = $b
/*  1674*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FADD),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fadd:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FADD:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1681*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMUL),// ->1693
/*  1684*/  OPC_RecordChild0, // #0 = $a
/*  1685*/  OPC_RecordChild1, // #1 = $b
/*  1686*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMUL),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmul:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMUL:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1693*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::FSUB),// ->1706
/*  1696*/  OPC_RecordChild0, // #0 = $a
/*  1697*/  OPC_RecordChild1, // #1 = $b
/*  1698*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FSUB),
                MVT::f32, 3/*#Ops*/, 0, 1, 0, 
            // Src: (fsub:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (FSUB:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$a)
/*  1706*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMINNUM),// ->1718
/*  1709*/  OPC_RecordChild0, // #0 = $a
/*  1710*/  OPC_RecordChild1, // #1 = $b
/*  1711*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMIN),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fminnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMIN:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1718*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FMAXNUM),// ->1730
/*  1721*/  OPC_RecordChild0, // #0 = $a
/*  1722*/  OPC_RecordChild1, // #1 = $b
/*  1723*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::C_FMAX),
                MVT::f32, 2/*#Ops*/, 0, 1, 
            // Src: (fmaxnum:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b) - Complexity = 3
            // Dst: (C_FMAX:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b)
/*  1730*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FNEG),// ->1742
/*  1733*/  OPC_RecordChild0, // #0 = $a
/*  1734*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FNEG_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fneg:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FNEG_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1742*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FABS),// ->1754
/*  1745*/  OPC_RecordChild0, // #0 = $a
/*  1746*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FABS_F0),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fabs:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (FABS_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1754*/ /*SwitchOpcode*/ 11, TARGET_VAL(ISD::FMA),// ->1768
/*  1757*/  OPC_RecordChild0, // #0 = $a
/*  1758*/  OPC_RecordChild1, // #1 = $b
/*  1759*/  OPC_RecordChild2, // #2 = $c
/*  1760*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::FFMA_F0),
                MVT::f32, 3/*#Ops*/, 0, 1, 2, 
            // Src: (fma:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c) - Complexity = 3
            // Dst: (FFMA_F0:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$b, GPR:{ *:[f32] }:$c)
/*  1768*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::SINT_TO_FP),// ->1781
/*  1771*/  OPC_RecordChild0, // #0 = $a
/*  1772*/  OPC_CheckChild0TypeI32,
/*  1773*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_S32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (sint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_S32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1781*/ /*SwitchOpcode*/ 10, TARGET_VAL(ISD::UINT_TO_FP),// ->1794
/*  1784*/  OPC_RecordChild0, // #0 = $a
/*  1785*/  OPC_CheckChild0TypeI32,
/*  1786*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::CVT_F32_U32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (uint_to_fp:{ *:[f32] } GPR:{ *:[i32] }:$a) - Complexity = 3
            // Dst: (CVT_F32_U32:{ *:[f32] } GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a, GPR:{ *:[i32] }:$a)
/*  1794*/ /*SwitchOpcode*/ 9, TARGET_VAL(ISD::FSQRT),// ->1806
/*  1797*/  OPC_RecordChild0, // #0 = $a
/*  1798*/  OPC_MorphNodeTo1None, TARGET_VAL(CCV::SQRT_F32),
                MVT::f32, 3/*#Ops*/, 0, 0, 0, 
            // Src: (fsqrt:{ *:[f32] } GPR:{ *:[f32] }:$a) - Complexity = 3
            // Dst: (SQRT_F32:{ *:[f32] } GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a, GPR:{ *:[f32] }:$a)
/*  1806*/ 0, // EndSwitchOpcode
    0
  }; // Total Array size is 1808 bytes

  // Opcode Histogram:
  // #OPC_Scope                                = 34
  // #OPC_RecordNode                           = 5
  // #OPC_RecordChild                          = 105
  // #OPC_RecordMemRef                         = 2
  // #OPC_CaptureGlueInput                     = 0
  // #OPC_MoveChild                            = 34
  // #OPC_MoveSibling                          = 0
  // #OPC_MoveParent                           = 52
  // #OPC_CheckSame                            = 0
  // #OPC_CheckChildSame                       = 0
  // #OPC_CheckPatternPredicate                = 0
  // #OPC_CheckPredicate                       = 84
  // #OPC_CheckOpcode                          = 33
  // #OPC_SwitchOpcode                         = 1
  // #OPC_CheckType                            = 77
  // #OPC_SwitchType                           = 7
  // #OPC_CheckChildType                       = 27
  // #OPC_CheckInteger                         = 2
  // #OPC_CheckChildInteger                    = 12
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
  // #OPC_EmitMergeInputChains                 = 25
  // #OPC_EmitCopyToReg                        = 0
  // #OPC_EmitNode                             = 3
  // #OPC_EmitNodeXForm                        = 5
  // #OPC_CompleteMatch                        = 2
  // #OPC_MorphNodeTo                          = 99

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
  case 2: {  // imm_not
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(~N->getSExtValue(), SDLoc(N), MVT::i32);

  }
  case 3: {  // fpimm_bits
    ConstantFPSDNode *N = cast<ConstantFPSDNode>(V.getNode());

  return CurDAG->getTargetConstant(
      N->getValueAPF().bitcastToAPInt().getZExtValue(), SDLoc(N), MVT::i32);

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
