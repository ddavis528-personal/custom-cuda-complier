/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*  * CCV Disassembler                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/LEB128.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/TargetParser/SubtargetFeature.h"
#include <assert.h>

namespace llvm {

// Helper functions for extracting fields from encoded instructions.
// InsnType must either be integral or an APInt-like object that must:
// * be default-constructible and copy-constructible
// * be constructible from an APInt (this can be private)
// * Support insertBits(bits, startBit, numBits)
// * Support extractBitsAsZExtValue(numBits, startBit)
// * Support the ~, &, ==, and != operators with other objects of the same type
// * Support the != and bitwise & with uint64_t
// * Support put (<<) to raw_ostream&
template <typename InsnType>
#if defined(_MSC_VER) && !defined(__clang__)
__declspec(noinline)
#endif
static std::enable_if_t<std::is_integral<InsnType>::value, InsnType>
fieldFromInstruction(const InsnType &insn, unsigned startBit,
                     unsigned numBits) {
  assert(startBit + numBits <= 64 && "Cannot support >64-bit extractions!");
  assert(startBit + numBits <= (sizeof(InsnType) * 8) &&
         "Instruction field out of bounds!");
  InsnType fieldMask;
  if (numBits == sizeof(InsnType) * 8)
    fieldMask = (InsnType)(-1LL);
  else
    fieldMask = (((InsnType)1 << numBits) - 1) << startBit;
  return (insn & fieldMask) >> startBit;
}

template <typename InsnType>
static std::enable_if_t<!std::is_integral<InsnType>::value, uint64_t>
fieldFromInstruction(const InsnType &insn, unsigned startBit,
                     unsigned numBits) {
  return insn.extractBitsAsZExtValue(numBits, startBit);
}

// Helper function for inserting bits extracted from an encoded instruction into
// a field.
template <typename InsnType>
static std::enable_if_t<std::is_integral<InsnType>::value>
insertBits(InsnType &field, InsnType bits, unsigned startBit, unsigned numBits) {
  assert(startBit + numBits <= sizeof field * 8);
  field |= (InsnType)bits << startBit;
}

template <typename InsnType>
static std::enable_if_t<!std::is_integral<InsnType>::value>
insertBits(InsnType &field, uint64_t bits, unsigned startBit, unsigned numBits) {
  field.insertBits(bits, startBit, numBits);
}

static bool Check(DecodeStatus &Out, DecodeStatus In) {
  Out = static_cast<DecodeStatus>(Out & In);
  return Out != MCDisassembler::Fail;
}

static const uint8_t DecoderTable16[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 3 */       MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 12
/* 8 */       MCD::OPC_Decode, 213, 3, 0, // Opcode: FFMA_ACC_F0
/* 12 */      MCD::OPC_FilterValue, 2, 136, 0, 0, // Skip to: 153
/* 17 */      MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 20 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 29
/* 25 */      MCD::OPC_Decode, 162, 3, 1, // Opcode: C_ADD
/* 29 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 38
/* 34 */      MCD::OPC_Decode, 186, 3, 1, // Opcode: C_OR
/* 38 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 47
/* 43 */      MCD::OPC_Decode, 192, 3, 1, // Opcode: C_SHR
/* 47 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 56
/* 52 */      MCD::OPC_Decode, 178, 3, 1, // Opcode: C_MAX_S
/* 56 */      MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 65
/* 61 */      MCD::OPC_Decode, 185, 3, 2, // Opcode: C_NOT
/* 65 */      MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 176, 3, 1, // Opcode: C_FMUL
/* 74 */      MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 83
/* 79 */      MCD::OPC_Decode, 177, 3, 2, // Opcode: C_LD_GLOBAL
/* 83 */      MCD::OPC_FilterValue, 7, 4, 0, 0, // Skip to: 92
/* 88 */      MCD::OPC_Decode, 239, 4, 3, // Opcode: SRD
/* 92 */      MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 101
/* 97 */      MCD::OPC_Decode, 163, 3, 4, // Opcode: C_ADDI
/* 101 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 110
/* 106 */     MCD::OPC_Decode, 200, 3, 4, // Opcode: C_XORI
/* 110 */     MCD::OPC_FilterValue, 12, 11, 0, 0, // Skip to: 126
/* 115 */     MCD::OPC_CheckField, 14, 2, 0, 105, 1, 0, // Skip to: 483
/* 122 */     MCD::OPC_Decode, 170, 3, 5, // Opcode: C_CHWIDTH
/* 126 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 135
/* 131 */     MCD::OPC_Decode, 168, 3, 6, // Opcode: C_BAR_WAIT
/* 135 */     MCD::OPC_FilterValue, 14, 4, 0, 0, // Skip to: 144
/* 140 */     MCD::OPC_Decode, 173, 3, 6, // Opcode: C_FENCE
/* 144 */     MCD::OPC_FilterValue, 15, 78, 1, 0, // Skip to: 483
/* 149 */     MCD::OPC_Decode, 149, 4, 7, // Opcode: PAND
/* 153 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 162
/* 158 */     MCD::OPC_Decode, 214, 3, 0, // Opcode: FFMA_ACC_F1
/* 162 */     MCD::OPC_FilterValue, 6, 102, 0, 0, // Skip to: 269
/* 167 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 170 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 179
/* 175 */     MCD::OPC_Decode, 197, 3, 1, // Opcode: C_SUB
/* 179 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 188
/* 184 */     MCD::OPC_Decode, 199, 3, 1, // Opcode: C_XOR
/* 188 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 197
/* 193 */     MCD::OPC_Decode, 194, 3, 1, // Opcode: C_SRA
/* 197 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 206
/* 202 */     MCD::OPC_Decode, 179, 3, 1, // Opcode: C_MAX_U
/* 206 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 215
/* 211 */     MCD::OPC_Decode, 161, 3, 2, // Opcode: C_ABS
/* 215 */     MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 224
/* 220 */     MCD::OPC_Decode, 196, 3, 2, // Opcode: C_ST_GLOBAL
/* 224 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 233
/* 229 */     MCD::OPC_Decode, 198, 3, 4, // Opcode: C_SUBI
/* 233 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 242
/* 238 */     MCD::OPC_Decode, 191, 3, 4, // Opcode: C_SHLI
/* 242 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 251
/* 247 */     MCD::OPC_Decode, 169, 3, 8, // Opcode: C_BRA
/* 251 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 260
/* 256 */     MCD::OPC_Decode, 189, 3, 6, // Opcode: C_RET
/* 260 */     MCD::OPC_FilterValue, 15, 218, 0, 0, // Skip to: 483
/* 265 */     MCD::OPC_Decode, 153, 4, 7, // Opcode: POR
/* 269 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 278
/* 274 */     MCD::OPC_Decode, 203, 3, 0, // Opcode: DP4_ACC
/* 278 */     MCD::OPC_FilterValue, 10, 93, 0, 0, // Skip to: 376
/* 283 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 286 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 295
/* 291 */     MCD::OPC_Decode, 183, 3, 1, // Opcode: C_MUL_LO
/* 295 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 304
/* 300 */     MCD::OPC_Decode, 166, 3, 1, // Opcode: C_ANDN
/* 304 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 313
/* 309 */     MCD::OPC_Decode, 180, 3, 1, // Opcode: C_MIN_S
/* 313 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 322
/* 318 */     MCD::OPC_Decode, 182, 3, 2, // Opcode: C_MOV
/* 322 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 331
/* 327 */     MCD::OPC_Decode, 172, 3, 1, // Opcode: C_FADD
/* 331 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 340
/* 336 */     MCD::OPC_Decode, 175, 3, 1, // Opcode: C_FMIN
/* 340 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 349
/* 345 */     MCD::OPC_Decode, 165, 3, 4, // Opcode: C_ANDI
/* 349 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 358
/* 354 */     MCD::OPC_Decode, 193, 3, 4, // Opcode: C_SHRI
/* 358 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 367
/* 363 */     MCD::OPC_Decode, 171, 3, 6, // Opcode: C_EXIT
/* 367 */     MCD::OPC_FilterValue, 15, 111, 0, 0, // Skip to: 483
/* 372 */     MCD::OPC_Decode, 154, 4, 7, // Opcode: PXOR
/* 376 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 385
/* 381 */     MCD::OPC_Decode, 248, 3, 0, // Opcode: MAD_ACC
/* 385 */     MCD::OPC_FilterValue, 14, 93, 0, 0, // Skip to: 483
/* 390 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 393 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 402
/* 398 */     MCD::OPC_Decode, 164, 3, 1, // Opcode: C_AND
/* 402 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 411
/* 407 */     MCD::OPC_Decode, 190, 3, 1, // Opcode: C_SHL
/* 411 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 420
/* 416 */     MCD::OPC_Decode, 181, 3, 1, // Opcode: C_MIN_U
/* 420 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 429
/* 425 */     MCD::OPC_Decode, 184, 3, 2, // Opcode: C_NEG
/* 429 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 438
/* 434 */     MCD::OPC_Decode, 174, 3, 1, // Opcode: C_FMAX
/* 438 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 447
/* 443 */     MCD::OPC_Decode, 187, 3, 4, // Opcode: C_ORI
/* 447 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 456
/* 452 */     MCD::OPC_Decode, 195, 3, 4, // Opcode: C_SRAI
/* 456 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 465
/* 461 */     MCD::OPC_Decode, 167, 3, 6, // Opcode: C_BAR_ARRIVE
/* 465 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 474
/* 470 */     MCD::OPC_Decode, 188, 3, 6, // Opcode: C_RECONV
/* 474 */     MCD::OPC_FilterValue, 15, 4, 0, 0, // Skip to: 483
/* 479 */     MCD::OPC_Decode, 150, 4, 7, // Opcode: PMOV
/* 483 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable32[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 3 */       MCD::OPC_FilterValue, 0, 90, 1, 0, // Skip to: 354
/* 8 */       MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 11 */      MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 64
/* 16 */      MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 19 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 28
/* 24 */      MCD::OPC_Decode, 157, 2, 9, // Opcode: ADD
/* 28 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 37
/* 33 */      MCD::OPC_Decode, 210, 3, 9, // Opcode: FADD
/* 37 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 46
/* 42 */      MCD::OPC_Decode, 186, 2, 9, // Opcode: CVT_D0_S0_R0
/* 46 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 55
/* 51 */      MCD::OPC_Decode, 246, 2, 9, // Opcode: CVT_D2_S0_R0
/* 55 */      MCD::OPC_FilterValue, 8, 1, 15, 0, // Skip to: 3901
/* 60 */      MCD::OPC_Decode, 155, 4, 9, // Opcode: RCP_F32
/* 64 */      MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 117
/* 69 */      MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 72 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 81
/* 77 */      MCD::OPC_Decode, 138, 4, 9, // Opcode: MUL_HI_U
/* 81 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 219, 3, 9, // Opcode: FMIN
/* 90 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 99
/* 95 */      MCD::OPC_Decode, 194, 2, 9, // Opcode: CVT_D0_S1_R0
/* 99 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 108
/* 104 */     MCD::OPC_Decode, 252, 2, 9, // Opcode: CVT_D2_S1_R0
/* 108 */     MCD::OPC_FilterValue, 8, 204, 14, 0, // Skip to: 3901
/* 113 */     MCD::OPC_Decode, 245, 3, 9, // Opcode: LG2_F32
/* 117 */     MCD::OPC_FilterValue, 2, 39, 0, 0, // Skip to: 161
/* 122 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 125 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 134
/* 130 */     MCD::OPC_Decode, 142, 4, 9, // Opcode: OR
/* 134 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 143
/* 139 */     MCD::OPC_Decode, 211, 3, 9, // Opcode: FADD_F1
/* 143 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 152
/* 148 */     MCD::OPC_Decode, 152, 3, 9, // Opcode: CVT_F32_S32
/* 152 */     MCD::OPC_FilterValue, 3, 160, 14, 0, // Skip to: 3901
/* 157 */     MCD::OPC_Decode, 158, 3, 10, // Opcode: CVT_SEXT
/* 161 */     MCD::OPC_FilterValue, 3, 39, 0, 0, // Skip to: 205
/* 166 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 169 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 178
/* 174 */     MCD::OPC_Decode, 229, 4, 9, // Opcode: SHR
/* 178 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 187
/* 183 */     MCD::OPC_Decode, 220, 3, 9, // Opcode: FMIN_F1
/* 187 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 196
/* 192 */     MCD::OPC_Decode, 154, 3, 9, // Opcode: CVT_F32_U32
/* 196 */     MCD::OPC_FilterValue, 3, 116, 14, 0, // Skip to: 3901
/* 201 */     MCD::OPC_Decode, 132, 3, 9, // Opcode: CVT_D2_S3_R0
/* 205 */     MCD::OPC_FilterValue, 4, 39, 0, 0, // Skip to: 249
/* 210 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 213 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 222
/* 218 */     MCD::OPC_Decode, 249, 3, 9, // Opcode: MAX_S
/* 222 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 231
/* 227 */     MCD::OPC_Decode, 206, 3, 9, // Opcode: DP4_SS
/* 231 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 240
/* 236 */     MCD::OPC_Decode, 214, 2, 9, // Opcode: CVT_D1_S0_R0
/* 240 */     MCD::OPC_FilterValue, 3, 72, 14, 0, // Skip to: 3901
/* 245 */     MCD::OPC_Decode, 134, 3, 9, // Opcode: CVT_D3_S0_R0
/* 249 */     MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 293
/* 254 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 257 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 266
/* 262 */     MCD::OPC_Decode, 156, 2, 9, // Opcode: ABS
/* 266 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 275
/* 271 */     MCD::OPC_Decode, 201, 3, 9, // Opcode: DP2_BF16
/* 275 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 284
/* 280 */     MCD::OPC_Decode, 222, 2, 9, // Opcode: CVT_D1_S1_R0
/* 284 */     MCD::OPC_FilterValue, 3, 28, 14, 0, // Skip to: 3901
/* 289 */     MCD::OPC_Decode, 140, 3, 9, // Opcode: CVT_D3_S1_R0
/* 293 */     MCD::OPC_FilterValue, 6, 30, 0, 0, // Skip to: 328
/* 298 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 301 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 310
/* 306 */     MCD::OPC_Decode, 180, 2, 9, // Opcode: BREV
/* 310 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 319
/* 315 */     MCD::OPC_Decode, 230, 2, 9, // Opcode: CVT_D1_S2_R0
/* 319 */     MCD::OPC_FilterValue, 3, 249, 13, 0, // Skip to: 3901
/* 324 */     MCD::OPC_Decode, 148, 3, 9, // Opcode: CVT_D3_S2_R0
/* 328 */     MCD::OPC_FilterValue, 7, 240, 13, 0, // Skip to: 3901
/* 333 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 336 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 345
/* 341 */     MCD::OPC_Decode, 238, 2, 9, // Opcode: CVT_D1_S3_R0
/* 345 */     MCD::OPC_FilterValue, 3, 223, 13, 0, // Skip to: 3901
/* 350 */     MCD::OPC_Decode, 150, 3, 9, // Opcode: CVT_D3_S3_R0
/* 354 */     MCD::OPC_FilterValue, 4, 0, 1, 0, // Skip to: 615
/* 359 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 362 */     MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 406
/* 367 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 370 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 379
/* 375 */     MCD::OPC_Decode, 163, 2, 11, // Opcode: ADD_P
/* 379 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 388
/* 384 */     MCD::OPC_Decode, 212, 3, 11, // Opcode: FADD_P
/* 388 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 397
/* 393 */     MCD::OPC_Decode, 187, 2, 11, // Opcode: CVT_D0_S0_R0_P
/* 397 */     MCD::OPC_FilterValue, 3, 171, 13, 0, // Skip to: 3901
/* 402 */     MCD::OPC_Decode, 247, 2, 11, // Opcode: CVT_D2_S0_R0_P
/* 406 */     MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 441
/* 411 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 414 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 423
/* 419 */     MCD::OPC_Decode, 139, 4, 11, // Opcode: MUL_HI_U_P
/* 423 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 432
/* 428 */     MCD::OPC_Decode, 195, 2, 11, // Opcode: CVT_D0_S1_R0_P
/* 432 */     MCD::OPC_FilterValue, 3, 136, 13, 0, // Skip to: 3901
/* 437 */     MCD::OPC_Decode, 253, 2, 11, // Opcode: CVT_D2_S1_R0_P
/* 441 */     MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 467
/* 446 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 449 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 458
/* 454 */     MCD::OPC_Decode, 145, 4, 11, // Opcode: OR_P
/* 458 */     MCD::OPC_FilterValue, 2, 110, 13, 0, // Skip to: 3901
/* 463 */     MCD::OPC_Decode, 153, 3, 11, // Opcode: CVT_F32_S32_P
/* 467 */     MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 502
/* 472 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 475 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 484
/* 480 */     MCD::OPC_Decode, 232, 4, 11, // Opcode: SHR_P
/* 484 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 493
/* 489 */     MCD::OPC_Decode, 155, 3, 11, // Opcode: CVT_F32_U32_P
/* 493 */     MCD::OPC_FilterValue, 3, 75, 13, 0, // Skip to: 3901
/* 498 */     MCD::OPC_Decode, 133, 3, 11, // Opcode: CVT_D2_S3_R0_P
/* 502 */     MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 537
/* 507 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 510 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 519
/* 515 */     MCD::OPC_Decode, 250, 3, 11, // Opcode: MAX_S_P
/* 519 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 528
/* 524 */     MCD::OPC_Decode, 215, 2, 11, // Opcode: CVT_D1_S0_R0_P
/* 528 */     MCD::OPC_FilterValue, 3, 40, 13, 0, // Skip to: 3901
/* 533 */     MCD::OPC_Decode, 135, 3, 11, // Opcode: CVT_D3_S0_R0_P
/* 537 */     MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 563
/* 542 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 545 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 554
/* 550 */     MCD::OPC_Decode, 223, 2, 11, // Opcode: CVT_D1_S1_R0_P
/* 554 */     MCD::OPC_FilterValue, 3, 14, 13, 0, // Skip to: 3901
/* 559 */     MCD::OPC_Decode, 141, 3, 11, // Opcode: CVT_D3_S1_R0_P
/* 563 */     MCD::OPC_FilterValue, 6, 21, 0, 0, // Skip to: 589
/* 568 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 571 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 580
/* 576 */     MCD::OPC_Decode, 231, 2, 11, // Opcode: CVT_D1_S2_R0_P
/* 580 */     MCD::OPC_FilterValue, 3, 244, 12, 0, // Skip to: 3901
/* 585 */     MCD::OPC_Decode, 149, 3, 11, // Opcode: CVT_D3_S2_R0_P
/* 589 */     MCD::OPC_FilterValue, 7, 235, 12, 0, // Skip to: 3901
/* 594 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 597 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 606
/* 602 */     MCD::OPC_Decode, 239, 2, 11, // Opcode: CVT_D1_S3_R0_P
/* 606 */     MCD::OPC_FilterValue, 3, 218, 12, 0, // Skip to: 3901
/* 611 */     MCD::OPC_Decode, 151, 3, 11, // Opcode: CVT_D3_S3_R0_P
/* 615 */     MCD::OPC_FilterValue, 8, 11, 0, 0, // Skip to: 631
/* 620 */     MCD::OPC_CheckField, 8, 3, 0, 202, 12, 0, // Skip to: 3901
/* 627 */     MCD::OPC_Decode, 164, 2, 12, // Opcode: ADD_PP
/* 631 */     MCD::OPC_FilterValue, 12, 39, 0, 0, // Skip to: 675
/* 636 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 639 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 648
/* 644 */     MCD::OPC_Decode, 158, 2, 13, // Opcode: ADDI
/* 648 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 657
/* 653 */     MCD::OPC_Decode, 143, 4, 13, // Opcode: ORI
/* 657 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 666
/* 662 */     MCD::OPC_Decode, 230, 4, 14, // Opcode: SHRI
/* 666 */     MCD::OPC_FilterValue, 5, 158, 12, 0, // Skip to: 3901
/* 671 */     MCD::OPC_Decode, 147, 4, 15, // Opcode: PACKI
/* 675 */     MCD::OPC_FilterValue, 16, 30, 0, 0, // Skip to: 710
/* 680 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 683 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 692
/* 688 */     MCD::OPC_Decode, 160, 2, 16, // Opcode: ADDI_P
/* 692 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 701
/* 697 */     MCD::OPC_Decode, 144, 4, 16, // Opcode: ORI_P
/* 701 */     MCD::OPC_FilterValue, 3, 123, 12, 0, // Skip to: 3901
/* 706 */     MCD::OPC_Decode, 231, 4, 17, // Opcode: SHRI_P
/* 710 */     MCD::OPC_FilterValue, 20, 11, 0, 0, // Skip to: 726
/* 715 */     MCD::OPC_CheckField, 8, 3, 0, 107, 12, 0, // Skip to: 3901
/* 722 */     MCD::OPC_Decode, 161, 2, 18, // Opcode: ADDI_PP
/* 726 */     MCD::OPC_FilterValue, 24, 67, 0, 0, // Skip to: 798
/* 731 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 734 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 750
/* 739 */     MCD::OPC_CheckField, 23, 4, 0, 83, 12, 0, // Skip to: 3901
/* 746 */     MCD::OPC_Decode, 204, 4, 19, // Opcode: SETP_LT
/* 750 */     MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 766
/* 755 */     MCD::OPC_CheckField, 23, 4, 0, 67, 12, 0, // Skip to: 3901
/* 762 */     MCD::OPC_Decode, 180, 4, 19, // Opcode: SETP_GT
/* 766 */     MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 782
/* 771 */     MCD::OPC_CheckField, 23, 4, 0, 51, 12, 0, // Skip to: 3901
/* 778 */     MCD::OPC_Decode, 188, 4, 19, // Opcode: SETP_GT_U
/* 782 */     MCD::OPC_FilterValue, 3, 42, 12, 0, // Skip to: 3901
/* 787 */     MCD::OPC_CheckField, 23, 4, 0, 35, 12, 0, // Skip to: 3901
/* 794 */     MCD::OPC_Decode, 161, 4, 19, // Opcode: SETP_EQ_F
/* 798 */     MCD::OPC_FilterValue, 28, 39, 0, 0, // Skip to: 842
/* 803 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 806 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 815
/* 811 */     MCD::OPC_Decode, 209, 4, 20, // Opcode: SETP_LT_I
/* 815 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 824
/* 820 */     MCD::OPC_Decode, 185, 4, 20, // Opcode: SETP_GT_I
/* 824 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 833
/* 829 */     MCD::OPC_Decode, 189, 4, 20, // Opcode: SETP_GT_U_I
/* 833 */     MCD::OPC_FilterValue, 3, 247, 11, 0, // Skip to: 3901
/* 838 */     MCD::OPC_Decode, 162, 4, 20, // Opcode: SETP_EQ_F_I
/* 842 */     MCD::OPC_FilterValue, 32, 39, 0, 0, // Skip to: 886
/* 847 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 850 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 859
/* 855 */     MCD::OPC_Decode, 229, 3, 13, // Opcode: LD_GLOBAL
/* 859 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 868
/* 864 */     MCD::OPC_Decode, 230, 3, 21, // Opcode: LD_GLOBAL_IDX
/* 868 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 877
/* 873 */     MCD::OPC_Decode, 239, 3, 22, // Opcode: LD_PRED_G
/* 877 */     MCD::OPC_FilterValue, 3, 203, 11, 0, // Skip to: 3901
/* 882 */     MCD::OPC_Decode, 234, 3, 23, // Opcode: LD_GLOBAL_SLOT
/* 886 */     MCD::OPC_FilterValue, 36, 11, 0, 0, // Skip to: 902
/* 891 */     MCD::OPC_CheckField, 8, 3, 0, 187, 11, 0, // Skip to: 3901
/* 898 */     MCD::OPC_Decode, 174, 2, 24, // Opcode: ATOM_ADD_G
/* 902 */     MCD::OPC_FilterValue, 40, 35, 0, 0, // Skip to: 942
/* 907 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 910 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 919
/* 915 */     MCD::OPC_Decode, 178, 2, 25, // Opcode: BRA
/* 919 */     MCD::OPC_FilterValue, 1, 161, 11, 0, // Skip to: 3901
/* 924 */     MCD::OPC_CheckField, 30, 2, 0, 154, 11, 0, // Skip to: 3901
/* 931 */     MCD::OPC_CheckField, 19, 8, 0, 147, 11, 0, // Skip to: 3901
/* 938 */     MCD::OPC_Decode, 177, 2, 26, // Opcode: BAR_WAIT_PHASE
/* 942 */     MCD::OPC_FilterValue, 44, 11, 0, 0, // Skip to: 958
/* 947 */     MCD::OPC_CheckField, 8, 3, 0, 131, 11, 0, // Skip to: 3901
/* 954 */     MCD::OPC_Decode, 131, 4, 27, // Opcode: MOVI
/* 958 */     MCD::OPC_FilterValue, 48, 79, 0, 0, // Skip to: 1042
/* 963 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 966 */     MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 989
/* 971 */     MCD::OPC_CheckField, 30, 2, 0, 107, 11, 0, // Skip to: 3901
/* 978 */     MCD::OPC_CheckField, 24, 3, 0, 100, 11, 0, // Skip to: 3901
/* 985 */     MCD::OPC_Decode, 224, 4, 28, // Opcode: SHFL_IDX
/* 989 */     MCD::OPC_FilterValue, 1, 18, 0, 0, // Skip to: 1012
/* 994 */     MCD::OPC_CheckField, 22, 5, 0, 84, 11, 0, // Skip to: 3901
/* 1001 */    MCD::OPC_CheckField, 11, 8, 0, 77, 11, 0, // Skip to: 3901
/* 1008 */    MCD::OPC_Decode, 134, 5, 29, // Opcode: VOTE_ANY
/* 1012 */    MCD::OPC_FilterValue, 2, 68, 11, 0, // Skip to: 3901
/* 1017 */    MCD::OPC_CheckField, 30, 2, 0, 61, 11, 0, // Skip to: 3901
/* 1024 */    MCD::OPC_CheckField, 22, 5, 0, 54, 11, 0, // Skip to: 3901
/* 1031 */    MCD::OPC_CheckField, 15, 4, 0, 47, 11, 0, // Skip to: 3901
/* 1038 */    MCD::OPC_Decode, 175, 2, 30, // Opcode: BALLOT
/* 1042 */    MCD::OPC_FilterValue, 52, 11, 0, 0, // Skip to: 1058
/* 1047 */    MCD::OPC_CheckField, 8, 3, 0, 31, 11, 0, // Skip to: 3901
/* 1054 */    MCD::OPC_Decode, 233, 3, 16, // Opcode: LD_GLOBAL_P
/* 1058 */    MCD::OPC_FilterValue, 56, 11, 0, 0, // Skip to: 1074
/* 1063 */    MCD::OPC_CheckField, 26, 6, 0, 15, 11, 0, // Skip to: 3901
/* 1070 */    MCD::OPC_Decode, 183, 2, 31, // Opcode: CHWIDTH_MULTI
/* 1074 */    MCD::OPC_FilterValue, 60, 135, 0, 0, // Skip to: 1214
/* 1079 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1082 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 1115
/* 1087 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1090 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1106
/* 1095 */    MCD::OPC_CheckField, 23, 4, 0, 239, 10, 0, // Skip to: 3901
/* 1102 */    MCD::OPC_Decode, 210, 4, 32, // Opcode: SETP_LT_NP
/* 1106 */    MCD::OPC_FilterValue, 1, 230, 10, 0, // Skip to: 3901
/* 1111 */    MCD::OPC_Decode, 211, 4, 33, // Opcode: SETP_LT_NPI
/* 1115 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 1148
/* 1120 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1123 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1139
/* 1128 */    MCD::OPC_CheckField, 23, 4, 0, 206, 10, 0, // Skip to: 3901
/* 1135 */    MCD::OPC_Decode, 186, 4, 32, // Opcode: SETP_GT_NP
/* 1139 */    MCD::OPC_FilterValue, 1, 197, 10, 0, // Skip to: 3901
/* 1144 */    MCD::OPC_Decode, 187, 4, 33, // Opcode: SETP_GT_NPI
/* 1148 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 1181
/* 1153 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1156 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1172
/* 1161 */    MCD::OPC_CheckField, 23, 4, 0, 173, 10, 0, // Skip to: 3901
/* 1168 */    MCD::OPC_Decode, 190, 4, 32, // Opcode: SETP_GT_U_NP
/* 1172 */    MCD::OPC_FilterValue, 1, 164, 10, 0, // Skip to: 3901
/* 1177 */    MCD::OPC_Decode, 191, 4, 33, // Opcode: SETP_GT_U_NPI
/* 1181 */    MCD::OPC_FilterValue, 3, 155, 10, 0, // Skip to: 3901
/* 1186 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1189 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1205
/* 1194 */    MCD::OPC_CheckField, 23, 4, 0, 140, 10, 0, // Skip to: 3901
/* 1201 */    MCD::OPC_Decode, 163, 4, 32, // Opcode: SETP_EQ_F_NP
/* 1205 */    MCD::OPC_FilterValue, 1, 131, 10, 0, // Skip to: 3901
/* 1210 */    MCD::OPC_Decode, 164, 4, 33, // Opcode: SETP_EQ_F_NPI
/* 1214 */    MCD::OPC_FilterValue, 64, 34, 1, 0, // Skip to: 1509
/* 1219 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1222 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 1275
/* 1227 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1230 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1239
/* 1235 */    MCD::OPC_Decode, 255, 4, 9, // Opcode: SUB
/* 1239 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1248
/* 1244 */    MCD::OPC_Decode, 226, 3, 9, // Opcode: FSUB
/* 1248 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1257
/* 1253 */    MCD::OPC_Decode, 188, 2, 9, // Opcode: CVT_D0_S0_R1
/* 1257 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1266
/* 1262 */    MCD::OPC_Decode, 156, 3, 9, // Opcode: CVT_S32_F32
/* 1266 */    MCD::OPC_FilterValue, 8, 70, 10, 0, // Skip to: 3901
/* 1271 */    MCD::OPC_Decode, 158, 4, 9, // Opcode: RSQRT_F32
/* 1275 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 1328
/* 1280 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1283 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1292
/* 1288 */    MCD::OPC_Decode, 246, 3, 9, // Opcode: MADLO
/* 1292 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1301
/* 1297 */    MCD::OPC_Decode, 217, 3, 9, // Opcode: FMAX
/* 1301 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1310
/* 1306 */    MCD::OPC_Decode, 196, 2, 9, // Opcode: CVT_D0_S1_R1
/* 1310 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1319
/* 1315 */    MCD::OPC_Decode, 254, 2, 9, // Opcode: CVT_D2_S1_R1
/* 1319 */    MCD::OPC_FilterValue, 8, 17, 10, 0, // Skip to: 3901
/* 1324 */    MCD::OPC_Decode, 233, 4, 9, // Opcode: SIN_F32
/* 1328 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 1363
/* 1333 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1336 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1345
/* 1341 */    MCD::OPC_Decode, 135, 5, 9, // Opcode: XOR
/* 1345 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1354
/* 1350 */    MCD::OPC_Decode, 227, 3, 9, // Opcode: FSUB_F1
/* 1354 */    MCD::OPC_FilterValue, 2, 238, 9, 0, // Skip to: 3901
/* 1359 */    MCD::OPC_Decode, 202, 2, 9, // Opcode: CVT_D0_S2_R1
/* 1363 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 1398
/* 1368 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1371 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1380
/* 1376 */    MCD::OPC_Decode, 235, 4, 9, // Opcode: SRA
/* 1380 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1389
/* 1385 */    MCD::OPC_Decode, 218, 3, 9, // Opcode: FMAX_F1
/* 1389 */    MCD::OPC_FilterValue, 2, 203, 9, 0, // Skip to: 3901
/* 1394 */    MCD::OPC_Decode, 208, 2, 9, // Opcode: CVT_D0_S3_R1
/* 1398 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1433
/* 1403 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1406 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1415
/* 1411 */    MCD::OPC_Decode, 252, 3, 9, // Opcode: MAX_U
/* 1415 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1424
/* 1420 */    MCD::OPC_Decode, 216, 2, 9, // Opcode: CVT_D1_S0_R1
/* 1424 */    MCD::OPC_FilterValue, 3, 168, 9, 0, // Skip to: 3901
/* 1429 */    MCD::OPC_Decode, 159, 3, 9, // Opcode: CVT_U32_F32
/* 1433 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 1477
/* 1438 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1441 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1450
/* 1446 */    MCD::OPC_Decode, 141, 4, 9, // Opcode: NEG
/* 1450 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1459
/* 1455 */    MCD::OPC_Decode, 202, 3, 9, // Opcode: DP2_F16
/* 1459 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1468
/* 1464 */    MCD::OPC_Decode, 224, 2, 9, // Opcode: CVT_D1_S1_R1
/* 1468 */    MCD::OPC_FilterValue, 3, 124, 9, 0, // Skip to: 3901
/* 1473 */    MCD::OPC_Decode, 142, 3, 9, // Opcode: CVT_D3_S1_R1
/* 1477 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1493
/* 1482 */    MCD::OPC_CheckField, 27, 5, 2, 108, 9, 0, // Skip to: 3901
/* 1489 */    MCD::OPC_Decode, 232, 2, 9, // Opcode: CVT_D1_S2_R1
/* 1493 */    MCD::OPC_FilterValue, 7, 99, 9, 0, // Skip to: 3901
/* 1498 */    MCD::OPC_CheckField, 27, 5, 2, 92, 9, 0, // Skip to: 3901
/* 1505 */    MCD::OPC_Decode, 240, 2, 9, // Opcode: CVT_D1_S3_R1
/* 1509 */    MCD::OPC_FilterValue, 68, 227, 0, 0, // Skip to: 1741
/* 1514 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1517 */    MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 1561
/* 1522 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1525 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1534
/* 1530 */    MCD::OPC_Decode, 130, 5, 11, // Opcode: SUB_P
/* 1534 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1543
/* 1539 */    MCD::OPC_Decode, 228, 3, 11, // Opcode: FSUB_P
/* 1543 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1552
/* 1548 */    MCD::OPC_Decode, 189, 2, 11, // Opcode: CVT_D0_S0_R1_P
/* 1552 */    MCD::OPC_FilterValue, 3, 40, 9, 0, // Skip to: 3901
/* 1557 */    MCD::OPC_Decode, 157, 3, 11, // Opcode: CVT_S32_F32_P
/* 1561 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 1596
/* 1566 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1569 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1578
/* 1574 */    MCD::OPC_Decode, 247, 3, 11, // Opcode: MADLO_P
/* 1578 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1587
/* 1583 */    MCD::OPC_Decode, 197, 2, 11, // Opcode: CVT_D0_S1_R1_P
/* 1587 */    MCD::OPC_FilterValue, 3, 5, 9, 0, // Skip to: 3901
/* 1592 */    MCD::OPC_Decode, 255, 2, 11, // Opcode: CVT_D2_S1_R1_P
/* 1596 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 1622
/* 1601 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1604 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1613
/* 1609 */    MCD::OPC_Decode, 138, 5, 11, // Opcode: XOR_P
/* 1613 */    MCD::OPC_FilterValue, 2, 235, 8, 0, // Skip to: 3901
/* 1618 */    MCD::OPC_Decode, 203, 2, 11, // Opcode: CVT_D0_S2_R1_P
/* 1622 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 1648
/* 1627 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1630 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1639
/* 1635 */    MCD::OPC_Decode, 238, 4, 11, // Opcode: SRA_P
/* 1639 */    MCD::OPC_FilterValue, 2, 209, 8, 0, // Skip to: 3901
/* 1644 */    MCD::OPC_Decode, 209, 2, 11, // Opcode: CVT_D0_S3_R1_P
/* 1648 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1683
/* 1653 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1656 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1665
/* 1661 */    MCD::OPC_Decode, 253, 3, 11, // Opcode: MAX_U_P
/* 1665 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1674
/* 1670 */    MCD::OPC_Decode, 217, 2, 11, // Opcode: CVT_D1_S0_R1_P
/* 1674 */    MCD::OPC_FilterValue, 3, 174, 8, 0, // Skip to: 3901
/* 1679 */    MCD::OPC_Decode, 160, 3, 11, // Opcode: CVT_U32_F32_P
/* 1683 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 1709
/* 1688 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1691 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1700
/* 1696 */    MCD::OPC_Decode, 225, 2, 11, // Opcode: CVT_D1_S1_R1_P
/* 1700 */    MCD::OPC_FilterValue, 3, 148, 8, 0, // Skip to: 3901
/* 1705 */    MCD::OPC_Decode, 143, 3, 11, // Opcode: CVT_D3_S1_R1_P
/* 1709 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1725
/* 1714 */    MCD::OPC_CheckField, 30, 2, 2, 132, 8, 0, // Skip to: 3901
/* 1721 */    MCD::OPC_Decode, 233, 2, 11, // Opcode: CVT_D1_S2_R1_P
/* 1725 */    MCD::OPC_FilterValue, 7, 123, 8, 0, // Skip to: 3901
/* 1730 */    MCD::OPC_CheckField, 30, 2, 2, 116, 8, 0, // Skip to: 3901
/* 1737 */    MCD::OPC_Decode, 241, 2, 11, // Opcode: CVT_D1_S3_R1_P
/* 1741 */    MCD::OPC_FilterValue, 76, 39, 0, 0, // Skip to: 1785
/* 1746 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1749 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1758
/* 1754 */    MCD::OPC_Decode, 128, 5, 13, // Opcode: SUBI
/* 1758 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1767
/* 1763 */    MCD::OPC_Decode, 136, 5, 13, // Opcode: XORI
/* 1767 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1776
/* 1772 */    MCD::OPC_Decode, 236, 4, 14, // Opcode: SRAI
/* 1776 */    MCD::OPC_FilterValue, 5, 72, 8, 0, // Skip to: 3901
/* 1781 */    MCD::OPC_Decode, 148, 4, 14, // Opcode: PACKI_Z
/* 1785 */    MCD::OPC_FilterValue, 80, 30, 0, 0, // Skip to: 1820
/* 1790 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1793 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1802
/* 1798 */    MCD::OPC_Decode, 129, 5, 16, // Opcode: SUBI_P
/* 1802 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1811
/* 1807 */    MCD::OPC_Decode, 137, 5, 16, // Opcode: XORI_P
/* 1811 */    MCD::OPC_FilterValue, 3, 37, 8, 0, // Skip to: 3901
/* 1816 */    MCD::OPC_Decode, 237, 4, 17, // Opcode: SRAI_P
/* 1820 */    MCD::OPC_FilterValue, 88, 67, 0, 0, // Skip to: 1892
/* 1825 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1828 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1844
/* 1833 */    MCD::OPC_CheckField, 23, 4, 0, 13, 8, 0, // Skip to: 3901
/* 1840 */    MCD::OPC_Decode, 192, 4, 19, // Opcode: SETP_LE
/* 1844 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1860
/* 1849 */    MCD::OPC_CheckField, 23, 4, 0, 253, 7, 0, // Skip to: 3901
/* 1856 */    MCD::OPC_Decode, 168, 4, 19, // Opcode: SETP_GE
/* 1860 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1876
/* 1865 */    MCD::OPC_CheckField, 23, 4, 0, 237, 7, 0, // Skip to: 3901
/* 1872 */    MCD::OPC_Decode, 176, 4, 19, // Opcode: SETP_GE_U
/* 1876 */    MCD::OPC_FilterValue, 3, 228, 7, 0, // Skip to: 3901
/* 1881 */    MCD::OPC_CheckField, 23, 4, 0, 221, 7, 0, // Skip to: 3901
/* 1888 */    MCD::OPC_Decode, 217, 4, 19, // Opcode: SETP_NE_F
/* 1892 */    MCD::OPC_FilterValue, 92, 39, 0, 0, // Skip to: 1936
/* 1897 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1900 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1909
/* 1905 */    MCD::OPC_Decode, 197, 4, 20, // Opcode: SETP_LE_I
/* 1909 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1918
/* 1914 */    MCD::OPC_Decode, 173, 4, 20, // Opcode: SETP_GE_I
/* 1918 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1927
/* 1923 */    MCD::OPC_Decode, 177, 4, 20, // Opcode: SETP_GE_U_I
/* 1927 */    MCD::OPC_FilterValue, 3, 177, 7, 0, // Skip to: 3901
/* 1932 */    MCD::OPC_Decode, 218, 4, 20, // Opcode: SETP_NE_F_I
/* 1936 */    MCD::OPC_FilterValue, 96, 39, 0, 0, // Skip to: 1980
/* 1941 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1944 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1953
/* 1949 */    MCD::OPC_Decode, 240, 4, 13, // Opcode: ST_GLOBAL
/* 1953 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1962
/* 1958 */    MCD::OPC_Decode, 241, 4, 21, // Opcode: ST_GLOBAL_IDX
/* 1962 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1971
/* 1967 */    MCD::OPC_Decode, 249, 4, 22, // Opcode: ST_PRED_G
/* 1971 */    MCD::OPC_FilterValue, 3, 133, 7, 0, // Skip to: 3901
/* 1976 */    MCD::OPC_Decode, 244, 4, 23, // Opcode: ST_GLOBAL_SLOT
/* 1980 */    MCD::OPC_FilterValue, 104, 11, 0, 0, // Skip to: 1996
/* 1985 */    MCD::OPC_CheckField, 8, 3, 0, 117, 7, 0, // Skip to: 3901
/* 1992 */    MCD::OPC_Decode, 179, 2, 34, // Opcode: BRA_PRED
/* 1996 */    MCD::OPC_FilterValue, 112, 18, 0, 0, // Skip to: 2019
/* 2001 */    MCD::OPC_CheckField, 19, 8, 0, 101, 7, 0, // Skip to: 3901
/* 2008 */    MCD::OPC_CheckField, 8, 7, 2, 94, 7, 0, // Skip to: 3901
/* 2015 */    MCD::OPC_Decode, 132, 5, 35, // Opcode: UNBALLOT
/* 2019 */    MCD::OPC_FilterValue, 124, 135, 0, 0, // Skip to: 2159
/* 2024 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2027 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2060
/* 2032 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2035 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2051
/* 2040 */    MCD::OPC_CheckField, 23, 4, 0, 62, 7, 0, // Skip to: 3901
/* 2047 */    MCD::OPC_Decode, 198, 4, 32, // Opcode: SETP_LE_NP
/* 2051 */    MCD::OPC_FilterValue, 1, 53, 7, 0, // Skip to: 3901
/* 2056 */    MCD::OPC_Decode, 199, 4, 33, // Opcode: SETP_LE_NPI
/* 2060 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2093
/* 2065 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2068 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2084
/* 2073 */    MCD::OPC_CheckField, 23, 4, 0, 29, 7, 0, // Skip to: 3901
/* 2080 */    MCD::OPC_Decode, 174, 4, 32, // Opcode: SETP_GE_NP
/* 2084 */    MCD::OPC_FilterValue, 1, 20, 7, 0, // Skip to: 3901
/* 2089 */    MCD::OPC_Decode, 175, 4, 33, // Opcode: SETP_GE_NPI
/* 2093 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2126
/* 2098 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2101 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2117
/* 2106 */    MCD::OPC_CheckField, 23, 4, 0, 252, 6, 0, // Skip to: 3901
/* 2113 */    MCD::OPC_Decode, 178, 4, 32, // Opcode: SETP_GE_U_NP
/* 2117 */    MCD::OPC_FilterValue, 1, 243, 6, 0, // Skip to: 3901
/* 2122 */    MCD::OPC_Decode, 179, 4, 33, // Opcode: SETP_GE_U_NPI
/* 2126 */    MCD::OPC_FilterValue, 3, 234, 6, 0, // Skip to: 3901
/* 2131 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2134 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2150
/* 2139 */    MCD::OPC_CheckField, 23, 4, 0, 219, 6, 0, // Skip to: 3901
/* 2146 */    MCD::OPC_Decode, 219, 4, 32, // Opcode: SETP_NE_F_NP
/* 2150 */    MCD::OPC_FilterValue, 1, 210, 6, 0, // Skip to: 3901
/* 2155 */    MCD::OPC_Decode, 220, 4, 33, // Opcode: SETP_NE_F_NPI
/* 2159 */    MCD::OPC_FilterValue, 128, 1, 16, 1, 0, // Skip to: 2437
/* 2165 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2168 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 2221
/* 2173 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2176 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2185
/* 2181 */    MCD::OPC_Decode, 140, 4, 9, // Opcode: MUL_LO
/* 2185 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2194
/* 2190 */    MCD::OPC_Decode, 221, 3, 9, // Opcode: FMUL
/* 2194 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2203
/* 2199 */    MCD::OPC_Decode, 190, 2, 9, // Opcode: CVT_D0_S0_R2
/* 2203 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2212
/* 2208 */    MCD::OPC_Decode, 248, 2, 9, // Opcode: CVT_D2_S0_R2
/* 2212 */    MCD::OPC_FilterValue, 8, 148, 6, 0, // Skip to: 3901
/* 2217 */    MCD::OPC_Decode, 234, 4, 9, // Opcode: SQRT_F32
/* 2221 */    MCD::OPC_FilterValue, 1, 39, 0, 0, // Skip to: 2265
/* 2226 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2229 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2238
/* 2234 */    MCD::OPC_Decode, 224, 3, 9, // Opcode: FNEG_F0
/* 2238 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2247
/* 2243 */    MCD::OPC_Decode, 198, 2, 9, // Opcode: CVT_D0_S1_R2
/* 2247 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2256
/* 2252 */    MCD::OPC_Decode, 128, 3, 9, // Opcode: CVT_D2_S1_R2
/* 2256 */    MCD::OPC_FilterValue, 8, 104, 6, 0, // Skip to: 3901
/* 2261 */    MCD::OPC_Decode, 185, 2, 9, // Opcode: COS_F32
/* 2265 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 2300
/* 2270 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2273 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2282
/* 2278 */    MCD::OPC_Decode, 169, 2, 9, // Opcode: ANDN
/* 2282 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2291
/* 2287 */    MCD::OPC_Decode, 222, 3, 9, // Opcode: FMUL_F1
/* 2291 */    MCD::OPC_FilterValue, 2, 69, 6, 0, // Skip to: 3901
/* 2296 */    MCD::OPC_Decode, 204, 2, 9, // Opcode: CVT_D0_S2_R2
/* 2300 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 2335
/* 2305 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2308 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2317
/* 2313 */    MCD::OPC_Decode, 254, 3, 9, // Opcode: MIN_S
/* 2317 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2326
/* 2322 */    MCD::OPC_Decode, 225, 3, 9, // Opcode: FNEG_F1
/* 2326 */    MCD::OPC_FilterValue, 2, 34, 6, 0, // Skip to: 3901
/* 2331 */    MCD::OPC_Decode, 210, 2, 9, // Opcode: CVT_D0_S3_R2
/* 2335 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 2361
/* 2340 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2343 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2352
/* 2348 */    MCD::OPC_Decode, 218, 2, 9, // Opcode: CVT_D1_S0_R2
/* 2352 */    MCD::OPC_FilterValue, 3, 8, 6, 0, // Skip to: 3901
/* 2357 */    MCD::OPC_Decode, 136, 3, 9, // Opcode: CVT_D3_S0_R2
/* 2361 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 2405
/* 2366 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2369 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2378
/* 2374 */    MCD::OPC_Decode, 152, 4, 9, // Opcode: POPC
/* 2378 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2387
/* 2383 */    MCD::OPC_Decode, 204, 3, 9, // Opcode: DP4_E4M3
/* 2387 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2396
/* 2392 */    MCD::OPC_Decode, 226, 2, 9, // Opcode: CVT_D1_S1_R2
/* 2396 */    MCD::OPC_FilterValue, 3, 220, 5, 0, // Skip to: 3901
/* 2401 */    MCD::OPC_Decode, 144, 3, 9, // Opcode: CVT_D3_S1_R2
/* 2405 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2421
/* 2410 */    MCD::OPC_CheckField, 27, 5, 2, 204, 5, 0, // Skip to: 3901
/* 2417 */    MCD::OPC_Decode, 234, 2, 9, // Opcode: CVT_D1_S2_R2
/* 2421 */    MCD::OPC_FilterValue, 7, 195, 5, 0, // Skip to: 3901
/* 2426 */    MCD::OPC_CheckField, 27, 5, 2, 188, 5, 0, // Skip to: 3901
/* 2433 */    MCD::OPC_Decode, 242, 2, 9, // Opcode: CVT_D1_S3_R2
/* 2437 */    MCD::OPC_FilterValue, 132, 1, 199, 0, 0, // Skip to: 2642
/* 2443 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2446 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 2481
/* 2451 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2454 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2463
/* 2459 */    MCD::OPC_Decode, 223, 3, 11, // Opcode: FMUL_P
/* 2463 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2472
/* 2468 */    MCD::OPC_Decode, 191, 2, 11, // Opcode: CVT_D0_S0_R2_P
/* 2472 */    MCD::OPC_FilterValue, 3, 144, 5, 0, // Skip to: 3901
/* 2477 */    MCD::OPC_Decode, 249, 2, 11, // Opcode: CVT_D2_S0_R2_P
/* 2481 */    MCD::OPC_FilterValue, 1, 21, 0, 0, // Skip to: 2507
/* 2486 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2489 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2498
/* 2494 */    MCD::OPC_Decode, 199, 2, 11, // Opcode: CVT_D0_S1_R2_P
/* 2498 */    MCD::OPC_FilterValue, 3, 118, 5, 0, // Skip to: 3901
/* 2503 */    MCD::OPC_Decode, 129, 3, 11, // Opcode: CVT_D2_S1_R2_P
/* 2507 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2523
/* 2512 */    MCD::OPC_CheckField, 30, 2, 2, 102, 5, 0, // Skip to: 3901
/* 2519 */    MCD::OPC_Decode, 205, 2, 11, // Opcode: CVT_D0_S2_R2_P
/* 2523 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 2549
/* 2528 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2531 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2540
/* 2536 */    MCD::OPC_Decode, 255, 3, 11, // Opcode: MIN_S_P
/* 2540 */    MCD::OPC_FilterValue, 2, 76, 5, 0, // Skip to: 3901
/* 2545 */    MCD::OPC_Decode, 211, 2, 11, // Opcode: CVT_D0_S3_R2_P
/* 2549 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 2584
/* 2554 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2557 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2566
/* 2562 */    MCD::OPC_Decode, 133, 4, 36, // Opcode: MOV_P
/* 2566 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2575
/* 2571 */    MCD::OPC_Decode, 219, 2, 11, // Opcode: CVT_D1_S0_R2_P
/* 2575 */    MCD::OPC_FilterValue, 3, 41, 5, 0, // Skip to: 3901
/* 2580 */    MCD::OPC_Decode, 137, 3, 11, // Opcode: CVT_D3_S0_R2_P
/* 2584 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 2610
/* 2589 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2592 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2601
/* 2597 */    MCD::OPC_Decode, 227, 2, 11, // Opcode: CVT_D1_S1_R2_P
/* 2601 */    MCD::OPC_FilterValue, 3, 15, 5, 0, // Skip to: 3901
/* 2606 */    MCD::OPC_Decode, 145, 3, 11, // Opcode: CVT_D3_S1_R2_P
/* 2610 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2626
/* 2615 */    MCD::OPC_CheckField, 30, 2, 2, 255, 4, 0, // Skip to: 3901
/* 2622 */    MCD::OPC_Decode, 235, 2, 11, // Opcode: CVT_D1_S2_R2_P
/* 2626 */    MCD::OPC_FilterValue, 7, 246, 4, 0, // Skip to: 3901
/* 2631 */    MCD::OPC_CheckField, 30, 2, 2, 239, 4, 0, // Skip to: 3901
/* 2638 */    MCD::OPC_Decode, 243, 2, 11, // Opcode: CVT_D1_S3_R2_P
/* 2642 */    MCD::OPC_FilterValue, 140, 1, 30, 0, 0, // Skip to: 2678
/* 2648 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2651 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2660
/* 2656 */    MCD::OPC_Decode, 134, 4, 13, // Opcode: MULI
/* 2660 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2669
/* 2665 */    MCD::OPC_Decode, 170, 2, 13, // Opcode: ANDNI
/* 2669 */    MCD::OPC_FilterValue, 5, 203, 4, 0, // Skip to: 3901
/* 2674 */    MCD::OPC_Decode, 133, 5, 14, // Opcode: UNPACKI
/* 2678 */    MCD::OPC_FilterValue, 144, 1, 21, 0, 0, // Skip to: 2705
/* 2684 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2687 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2696
/* 2692 */    MCD::OPC_Decode, 135, 4, 16, // Opcode: MULI_P
/* 2696 */    MCD::OPC_FilterValue, 2, 176, 4, 0, // Skip to: 3901
/* 2701 */    MCD::OPC_Decode, 171, 2, 16, // Opcode: ANDNI_P
/* 2705 */    MCD::OPC_FilterValue, 152, 1, 67, 0, 0, // Skip to: 2778
/* 2711 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2714 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2730
/* 2719 */    MCD::OPC_CheckField, 23, 4, 0, 151, 4, 0, // Skip to: 3901
/* 2726 */    MCD::OPC_Decode, 160, 4, 19, // Opcode: SETP_EQ
/* 2730 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 2746
/* 2735 */    MCD::OPC_CheckField, 23, 4, 0, 135, 4, 0, // Skip to: 3901
/* 2742 */    MCD::OPC_Decode, 212, 4, 19, // Opcode: SETP_LT_U
/* 2746 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2762
/* 2751 */    MCD::OPC_CheckField, 23, 4, 0, 119, 4, 0, // Skip to: 3901
/* 2758 */    MCD::OPC_Decode, 205, 4, 19, // Opcode: SETP_LT_F
/* 2762 */    MCD::OPC_FilterValue, 3, 110, 4, 0, // Skip to: 3901
/* 2767 */    MCD::OPC_CheckField, 23, 4, 0, 103, 4, 0, // Skip to: 3901
/* 2774 */    MCD::OPC_Decode, 181, 4, 19, // Opcode: SETP_GT_F
/* 2778 */    MCD::OPC_FilterValue, 156, 1, 39, 0, 0, // Skip to: 2823
/* 2784 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2787 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2796
/* 2792 */    MCD::OPC_Decode, 165, 4, 20, // Opcode: SETP_EQ_I
/* 2796 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2805
/* 2801 */    MCD::OPC_Decode, 213, 4, 20, // Opcode: SETP_LT_U_I
/* 2805 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2814
/* 2810 */    MCD::OPC_Decode, 206, 4, 20, // Opcode: SETP_LT_F_I
/* 2814 */    MCD::OPC_FilterValue, 3, 58, 4, 0, // Skip to: 3901
/* 2819 */    MCD::OPC_Decode, 182, 4, 20, // Opcode: SETP_GT_F_I
/* 2823 */    MCD::OPC_FilterValue, 160, 1, 30, 0, 0, // Skip to: 2859
/* 2829 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2832 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2841
/* 2837 */    MCD::OPC_Decode, 241, 3, 13, // Opcode: LD_SHARED
/* 2841 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2850
/* 2846 */    MCD::OPC_Decode, 242, 3, 21, // Opcode: LD_SHARED_IDX
/* 2850 */    MCD::OPC_FilterValue, 2, 22, 4, 0, // Skip to: 3901
/* 2855 */    MCD::OPC_Decode, 240, 3, 22, // Opcode: LD_PRED_S
/* 2859 */    MCD::OPC_FilterValue, 168, 1, 11, 0, 0, // Skip to: 2876
/* 2865 */    MCD::OPC_CheckField, 8, 3, 0, 5, 4, 0, // Skip to: 3901
/* 2872 */    MCD::OPC_Decode, 181, 2, 37, // Opcode: CALL
/* 2876 */    MCD::OPC_FilterValue, 188, 1, 135, 0, 0, // Skip to: 3017
/* 2882 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2885 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2918
/* 2890 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2893 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2909
/* 2898 */    MCD::OPC_CheckField, 23, 4, 0, 228, 3, 0, // Skip to: 3901
/* 2905 */    MCD::OPC_Decode, 166, 4, 32, // Opcode: SETP_EQ_NP
/* 2909 */    MCD::OPC_FilterValue, 1, 219, 3, 0, // Skip to: 3901
/* 2914 */    MCD::OPC_Decode, 167, 4, 33, // Opcode: SETP_EQ_NPI
/* 2918 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2951
/* 2923 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2926 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2942
/* 2931 */    MCD::OPC_CheckField, 23, 4, 0, 195, 3, 0, // Skip to: 3901
/* 2938 */    MCD::OPC_Decode, 214, 4, 32, // Opcode: SETP_LT_U_NP
/* 2942 */    MCD::OPC_FilterValue, 1, 186, 3, 0, // Skip to: 3901
/* 2947 */    MCD::OPC_Decode, 215, 4, 33, // Opcode: SETP_LT_U_NPI
/* 2951 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2984
/* 2956 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2959 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2975
/* 2964 */    MCD::OPC_CheckField, 23, 4, 0, 162, 3, 0, // Skip to: 3901
/* 2971 */    MCD::OPC_Decode, 207, 4, 32, // Opcode: SETP_LT_F_NP
/* 2975 */    MCD::OPC_FilterValue, 1, 153, 3, 0, // Skip to: 3901
/* 2980 */    MCD::OPC_Decode, 208, 4, 33, // Opcode: SETP_LT_F_NPI
/* 2984 */    MCD::OPC_FilterValue, 3, 144, 3, 0, // Skip to: 3901
/* 2989 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2992 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3008
/* 2997 */    MCD::OPC_CheckField, 23, 4, 0, 129, 3, 0, // Skip to: 3901
/* 3004 */    MCD::OPC_Decode, 183, 4, 32, // Opcode: SETP_GT_F_NP
/* 3008 */    MCD::OPC_FilterValue, 1, 120, 3, 0, // Skip to: 3901
/* 3013 */    MCD::OPC_Decode, 184, 4, 33, // Opcode: SETP_GT_F_NPI
/* 3017 */    MCD::OPC_FilterValue, 192, 1, 25, 1, 0, // Skip to: 3304
/* 3023 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3026 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 3079
/* 3031 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3034 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3043
/* 3039 */    MCD::OPC_Decode, 136, 4, 9, // Opcode: MUL_HI_S
/* 3043 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3052
/* 3048 */    MCD::OPC_Decode, 215, 3, 9, // Opcode: FFMA_F0
/* 3052 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3061
/* 3057 */    MCD::OPC_Decode, 192, 2, 9, // Opcode: CVT_D0_S0_R3
/* 3061 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3070
/* 3066 */    MCD::OPC_Decode, 250, 2, 9, // Opcode: CVT_D2_S0_R3
/* 3070 */    MCD::OPC_FilterValue, 8, 58, 3, 0, // Skip to: 3901
/* 3075 */    MCD::OPC_Decode, 207, 3, 9, // Opcode: EX2_F32
/* 3079 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 3132
/* 3084 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3087 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3096
/* 3092 */    MCD::OPC_Decode, 166, 2, 9, // Opcode: AND
/* 3096 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3105
/* 3101 */    MCD::OPC_Decode, 208, 3, 9, // Opcode: FABS_F0
/* 3105 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3114
/* 3110 */    MCD::OPC_Decode, 200, 2, 9, // Opcode: CVT_D0_S1_R3
/* 3114 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3123
/* 3119 */    MCD::OPC_Decode, 130, 3, 9, // Opcode: CVT_D2_S1_R3
/* 3123 */    MCD::OPC_FilterValue, 8, 5, 3, 0, // Skip to: 3901
/* 3128 */    MCD::OPC_Decode, 157, 4, 9, // Opcode: RCP_U32
/* 3132 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 3167
/* 3137 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3140 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3149
/* 3145 */    MCD::OPC_Decode, 225, 4, 9, // Opcode: SHL
/* 3149 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3158
/* 3154 */    MCD::OPC_Decode, 216, 3, 9, // Opcode: FFMA_F1
/* 3158 */    MCD::OPC_FilterValue, 2, 226, 2, 0, // Skip to: 3901
/* 3163 */    MCD::OPC_Decode, 206, 2, 9, // Opcode: CVT_D0_S2_R3
/* 3167 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 3202
/* 3172 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3175 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3184
/* 3180 */    MCD::OPC_Decode, 129, 4, 9, // Opcode: MIN_U
/* 3184 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3193
/* 3189 */    MCD::OPC_Decode, 209, 3, 9, // Opcode: FABS_F1
/* 3193 */    MCD::OPC_FilterValue, 2, 191, 2, 0, // Skip to: 3901
/* 3198 */    MCD::OPC_Decode, 212, 2, 9, // Opcode: CVT_D0_S3_R3
/* 3202 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 3228
/* 3207 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3210 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3219
/* 3215 */    MCD::OPC_Decode, 220, 2, 9, // Opcode: CVT_D1_S0_R3
/* 3219 */    MCD::OPC_FilterValue, 3, 165, 2, 0, // Skip to: 3901
/* 3224 */    MCD::OPC_Decode, 138, 3, 9, // Opcode: CVT_D3_S0_R3
/* 3228 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 3272
/* 3233 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3236 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3245
/* 3241 */    MCD::OPC_Decode, 184, 2, 9, // Opcode: CLZ
/* 3245 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3254
/* 3250 */    MCD::OPC_Decode, 205, 3, 9, // Opcode: DP4_E5M2
/* 3254 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3263
/* 3259 */    MCD::OPC_Decode, 228, 2, 9, // Opcode: CVT_D1_S1_R3
/* 3263 */    MCD::OPC_FilterValue, 3, 121, 2, 0, // Skip to: 3901
/* 3268 */    MCD::OPC_Decode, 146, 3, 9, // Opcode: CVT_D3_S1_R3
/* 3272 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3288
/* 3277 */    MCD::OPC_CheckField, 27, 5, 2, 105, 2, 0, // Skip to: 3901
/* 3284 */    MCD::OPC_Decode, 236, 2, 9, // Opcode: CVT_D1_S2_R3
/* 3288 */    MCD::OPC_FilterValue, 7, 96, 2, 0, // Skip to: 3901
/* 3293 */    MCD::OPC_CheckField, 27, 5, 2, 89, 2, 0, // Skip to: 3901
/* 3300 */    MCD::OPC_Decode, 244, 2, 9, // Opcode: CVT_D1_S3_R3
/* 3304 */    MCD::OPC_FilterValue, 196, 1, 218, 0, 0, // Skip to: 3528
/* 3310 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3313 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 3348
/* 3318 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3321 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3330
/* 3326 */    MCD::OPC_Decode, 137, 4, 11, // Opcode: MUL_HI_S_P
/* 3330 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3339
/* 3335 */    MCD::OPC_Decode, 193, 2, 11, // Opcode: CVT_D0_S0_R3_P
/* 3339 */    MCD::OPC_FilterValue, 3, 45, 2, 0, // Skip to: 3901
/* 3344 */    MCD::OPC_Decode, 251, 2, 11, // Opcode: CVT_D2_S0_R3_P
/* 3348 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 3383
/* 3353 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3356 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3365
/* 3361 */    MCD::OPC_Decode, 172, 2, 11, // Opcode: AND_P
/* 3365 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3374
/* 3370 */    MCD::OPC_Decode, 201, 2, 11, // Opcode: CVT_D0_S1_R3_P
/* 3374 */    MCD::OPC_FilterValue, 3, 10, 2, 0, // Skip to: 3901
/* 3379 */    MCD::OPC_Decode, 131, 3, 11, // Opcode: CVT_D2_S1_R3_P
/* 3383 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3409
/* 3388 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3391 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3400
/* 3396 */    MCD::OPC_Decode, 228, 4, 11, // Opcode: SHL_P
/* 3400 */    MCD::OPC_FilterValue, 2, 240, 1, 0, // Skip to: 3901
/* 3405 */    MCD::OPC_Decode, 207, 2, 11, // Opcode: CVT_D0_S2_R3_P
/* 3409 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 3435
/* 3414 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3417 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3426
/* 3422 */    MCD::OPC_Decode, 130, 4, 11, // Opcode: MIN_U_P
/* 3426 */    MCD::OPC_FilterValue, 2, 214, 1, 0, // Skip to: 3901
/* 3431 */    MCD::OPC_Decode, 213, 2, 11, // Opcode: CVT_D0_S3_R3_P
/* 3435 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 3470
/* 3440 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3443 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3452
/* 3448 */    MCD::OPC_Decode, 159, 4, 11, // Opcode: SEL
/* 3452 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3461
/* 3457 */    MCD::OPC_Decode, 221, 2, 11, // Opcode: CVT_D1_S0_R3_P
/* 3461 */    MCD::OPC_FilterValue, 3, 179, 1, 0, // Skip to: 3901
/* 3466 */    MCD::OPC_Decode, 139, 3, 11, // Opcode: CVT_D3_S0_R3_P
/* 3470 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 3496
/* 3475 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3478 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3487
/* 3483 */    MCD::OPC_Decode, 229, 2, 11, // Opcode: CVT_D1_S1_R3_P
/* 3487 */    MCD::OPC_FilterValue, 3, 153, 1, 0, // Skip to: 3901
/* 3492 */    MCD::OPC_Decode, 147, 3, 11, // Opcode: CVT_D3_S1_R3_P
/* 3496 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3512
/* 3501 */    MCD::OPC_CheckField, 30, 2, 2, 137, 1, 0, // Skip to: 3901
/* 3508 */    MCD::OPC_Decode, 237, 2, 11, // Opcode: CVT_D1_S2_R3_P
/* 3512 */    MCD::OPC_FilterValue, 7, 128, 1, 0, // Skip to: 3901
/* 3517 */    MCD::OPC_CheckField, 30, 2, 2, 121, 1, 0, // Skip to: 3901
/* 3524 */    MCD::OPC_Decode, 245, 2, 11, // Opcode: CVT_D1_S3_R3_P
/* 3528 */    MCD::OPC_FilterValue, 204, 1, 21, 0, 0, // Skip to: 3555
/* 3534 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3537 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3546
/* 3542 */    MCD::OPC_Decode, 167, 2, 13, // Opcode: ANDI
/* 3546 */    MCD::OPC_FilterValue, 2, 94, 1, 0, // Skip to: 3901
/* 3551 */    MCD::OPC_Decode, 226, 4, 14, // Opcode: SHLI
/* 3555 */    MCD::OPC_FilterValue, 208, 1, 21, 0, 0, // Skip to: 3582
/* 3561 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3564 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3573
/* 3569 */    MCD::OPC_Decode, 168, 2, 16, // Opcode: ANDI_P
/* 3573 */    MCD::OPC_FilterValue, 2, 67, 1, 0, // Skip to: 3901
/* 3578 */    MCD::OPC_Decode, 227, 4, 17, // Opcode: SHLI_P
/* 3582 */    MCD::OPC_FilterValue, 216, 1, 67, 0, 0, // Skip to: 3655
/* 3588 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3591 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3607
/* 3596 */    MCD::OPC_CheckField, 23, 4, 0, 42, 1, 0, // Skip to: 3901
/* 3603 */    MCD::OPC_Decode, 216, 4, 19, // Opcode: SETP_NE
/* 3607 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 3623
/* 3612 */    MCD::OPC_CheckField, 23, 4, 0, 26, 1, 0, // Skip to: 3901
/* 3619 */    MCD::OPC_Decode, 200, 4, 19, // Opcode: SETP_LE_U
/* 3623 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 3639
/* 3628 */    MCD::OPC_CheckField, 23, 4, 0, 10, 1, 0, // Skip to: 3901
/* 3635 */    MCD::OPC_Decode, 193, 4, 19, // Opcode: SETP_LE_F
/* 3639 */    MCD::OPC_FilterValue, 3, 1, 1, 0, // Skip to: 3901
/* 3644 */    MCD::OPC_CheckField, 23, 4, 0, 250, 0, 0, // Skip to: 3901
/* 3651 */    MCD::OPC_Decode, 169, 4, 19, // Opcode: SETP_GE_F
/* 3655 */    MCD::OPC_FilterValue, 220, 1, 39, 0, 0, // Skip to: 3700
/* 3661 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3664 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3673
/* 3669 */    MCD::OPC_Decode, 221, 4, 20, // Opcode: SETP_NE_I
/* 3673 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3682
/* 3678 */    MCD::OPC_Decode, 201, 4, 20, // Opcode: SETP_LE_U_I
/* 3682 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3691
/* 3687 */    MCD::OPC_Decode, 194, 4, 20, // Opcode: SETP_LE_F_I
/* 3691 */    MCD::OPC_FilterValue, 3, 205, 0, 0, // Skip to: 3901
/* 3696 */    MCD::OPC_Decode, 170, 4, 20, // Opcode: SETP_GE_F_I
/* 3700 */    MCD::OPC_FilterValue, 224, 1, 30, 0, 0, // Skip to: 3736
/* 3706 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3709 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3718
/* 3714 */    MCD::OPC_Decode, 251, 4, 13, // Opcode: ST_SHARED
/* 3718 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3727
/* 3723 */    MCD::OPC_Decode, 252, 4, 21, // Opcode: ST_SHARED_IDX
/* 3727 */    MCD::OPC_FilterValue, 2, 169, 0, 0, // Skip to: 3901
/* 3732 */    MCD::OPC_Decode, 250, 4, 22, // Opcode: ST_PRED_S
/* 3736 */    MCD::OPC_FilterValue, 232, 1, 18, 0, 0, // Skip to: 3760
/* 3742 */    MCD::OPC_CheckField, 27, 5, 0, 152, 0, 0, // Skip to: 3901
/* 3749 */    MCD::OPC_CheckField, 8, 3, 0, 145, 0, 0, // Skip to: 3901
/* 3756 */    MCD::OPC_Decode, 176, 2, 38, // Opcode: BAR_INIT
/* 3760 */    MCD::OPC_FilterValue, 252, 1, 135, 0, 0, // Skip to: 3901
/* 3766 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3769 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 3802
/* 3774 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3777 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3793
/* 3782 */    MCD::OPC_CheckField, 23, 4, 0, 112, 0, 0, // Skip to: 3901
/* 3789 */    MCD::OPC_Decode, 222, 4, 32, // Opcode: SETP_NE_NP
/* 3793 */    MCD::OPC_FilterValue, 1, 103, 0, 0, // Skip to: 3901
/* 3798 */    MCD::OPC_Decode, 223, 4, 33, // Opcode: SETP_NE_NPI
/* 3802 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 3835
/* 3807 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3810 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3826
/* 3815 */    MCD::OPC_CheckField, 23, 4, 0, 79, 0, 0, // Skip to: 3901
/* 3822 */    MCD::OPC_Decode, 202, 4, 32, // Opcode: SETP_LE_U_NP
/* 3826 */    MCD::OPC_FilterValue, 1, 70, 0, 0, // Skip to: 3901
/* 3831 */    MCD::OPC_Decode, 203, 4, 33, // Opcode: SETP_LE_U_NPI
/* 3835 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 3868
/* 3840 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3843 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3859
/* 3848 */    MCD::OPC_CheckField, 23, 4, 0, 46, 0, 0, // Skip to: 3901
/* 3855 */    MCD::OPC_Decode, 195, 4, 32, // Opcode: SETP_LE_F_NP
/* 3859 */    MCD::OPC_FilterValue, 1, 37, 0, 0, // Skip to: 3901
/* 3864 */    MCD::OPC_Decode, 196, 4, 33, // Opcode: SETP_LE_F_NPI
/* 3868 */    MCD::OPC_FilterValue, 3, 28, 0, 0, // Skip to: 3901
/* 3873 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3876 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3892
/* 3881 */    MCD::OPC_CheckField, 23, 4, 0, 13, 0, 0, // Skip to: 3901
/* 3888 */    MCD::OPC_Decode, 171, 4, 32, // Opcode: SETP_GE_F_NP
/* 3892 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3901
/* 3897 */    MCD::OPC_Decode, 172, 4, 33, // Opcode: SETP_GE_F_NPI
/* 3901 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable48[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 3 */       MCD::OPC_FilterValue, 7, 18, 0, 0, // Skip to: 26
/* 8 */       MCD::OPC_CheckField, 30, 18, 8, 75, 0, 0, // Skip to: 90
/* 15 */      MCD::OPC_CheckField, 8, 3, 0, 68, 0, 0, // Skip to: 90
/* 22 */      MCD::OPC_Decode, 156, 4, 11, // Opcode: RCP_F32_P
/* 26 */      MCD::OPC_FilterValue, 15, 11, 0, 0, // Skip to: 42
/* 31 */      MCD::OPC_CheckField, 8, 3, 0, 52, 0, 0, // Skip to: 90
/* 38 */      MCD::OPC_Decode, 159, 2, 39, // Opcode: ADDI48
/* 42 */      MCD::OPC_FilterValue, 39, 11, 0, 0, // Skip to: 58
/* 47 */      MCD::OPC_CheckField, 8, 3, 4, 36, 0, 0, // Skip to: 90
/* 54 */      MCD::OPC_Decode, 182, 2, 40, // Opcode: CAS_G
/* 58 */      MCD::OPC_FilterValue, 47, 11, 0, 0, // Skip to: 74
/* 63 */      MCD::OPC_CheckField, 8, 3, 0, 20, 0, 0, // Skip to: 90
/* 70 */      MCD::OPC_Decode, 132, 4, 41, // Opcode: MOVI48
/* 74 */      MCD::OPC_FilterValue, 123, 11, 0, 0, // Skip to: 90
/* 79 */      MCD::OPC_CheckField, 10, 6, 0, 4, 0, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 151, 4, 42, // Opcode: PMOV_IMM
/* 90 */      MCD::OPC_Fail,
  0
};

static bool checkDecoderPredicate(unsigned Idx, const FeatureBitset &Bits) {
  llvm_unreachable("Invalid index!");
}

template <typename InsnType>
static DecodeStatus decodeToMCInst(DecodeStatus S, unsigned Idx, InsnType insn, MCInst &MI,
                                   uint64_t Address, const MCDisassembler *Decoder, bool &DecodeComplete) {
  DecodeComplete = true;
  using TmpType = std::conditional_t<std::is_integral<InsnType>::value, InsnType, uint64_t>;
  TmpType tmp;
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 1:
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 2:
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 3:
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 4:
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 5:
    tmp = fieldFromInstruction(insn, 8, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 6:
    tmp = fieldFromInstruction(insn, 8, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 7:
    tmp = fieldFromInstruction(insn, 8, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 10, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 13, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 8:
    tmp = fieldFromInstruction(insn, 8, 8);
    if (!Check(S, decodeSImm<8>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 9:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 10:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPR16RegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPR16RegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPR16RegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 11:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 12:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 13:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 13);
    if (!Check(S, decodeSImm<13>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 14:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 13);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 15:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 13);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 16:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = 0x0;
    insertBits(tmp, fieldFromInstruction(insn, 19, 8), 0, 8);
    insertBits(tmp, fieldFromInstruction(insn, 30, 2), 8, 2);
    if (!Check(S, decodeSImm<10>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 17:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = 0x0;
    insertBits(tmp, fieldFromInstruction(insn, 19, 8), 0, 8);
    insertBits(tmp, fieldFromInstruction(insn, 30, 2), 8, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 18:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 8);
    if (!Check(S, decodeSImm<8>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 19:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 20:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 8);
    if (!Check(S, decodeSImm<8>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 21:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 24, 8);
    if (!Check(S, decodeSImm<8>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 22:
    tmp = fieldFromInstruction(insn, 11, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 13);
    if (!Check(S, decodeSImm<13>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 23:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 24, 8);
    if (!Check(S, decodeSImm<8>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 24:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 9);
    if (!Check(S, decodeSImm<9>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 25:
    tmp = fieldFromInstruction(insn, 11, 21);
    if (!Check(S, decodeSImm<21>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 26:
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 17, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 17);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 28:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 29:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 19, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 30:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 19, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 31:
    tmp = fieldFromInstruction(insn, 8, 16);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 24, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 32:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 33:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 8);
    if (!Check(S, decodeSImm<8>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 34:
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = 0x0;
    insertBits(tmp, fieldFromInstruction(insn, 11, 16), 0, 16);
    insertBits(tmp, fieldFromInstruction(insn, 30, 2), 16, 2);
    if (!Check(S, decodeSImm<18>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 35:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 36:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 37:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 17);
    if (!Check(S, decodeSImm<17>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 38:
    tmp = fieldFromInstruction(insn, 11, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 17, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 29);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 32, 16);
    if (!Check(S, decodeSImm<16>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 41:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 33);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 42:
    tmp = fieldFromInstruction(insn, 8, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 32);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  }
}

template <typename InsnType>
static DecodeStatus decodeInstruction(const uint8_t DecodeTable[], MCInst &MI,
                                      InsnType insn, uint64_t Address,
                                      const MCDisassembler *DisAsm,
                                      const MCSubtargetInfo &STI) {
  const FeatureBitset &Bits = STI.getFeatureBits();

  const uint8_t *Ptr = DecodeTable;
  uint64_t CurFieldValue = 0;
  DecodeStatus S = MCDisassembler::Success;
  while (true) {
    ptrdiff_t Loc = Ptr - DecodeTable;
    switch (*Ptr) {
    default:
      errs() << Loc << ": Unexpected decode table opcode!\n";
      return MCDisassembler::Fail;
    case MCD::OPC_ExtractField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      ++Ptr;
      CurFieldValue = fieldFromInstruction(insn, Start, Len);
      LLVM_DEBUG(dbgs() << Loc << ": OPC_ExtractField(" << Start << ", "
                   << Len << "): " << CurFieldValue << "\n");
      break;
    }
    case MCD::OPC_FilterValue: {
      // Decode the field value.
      unsigned Len;
      uint64_t Val = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 24-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;
      NumToSkip |= (*Ptr++) << 16;

      // Perform the filter operation.
      if (Val != CurFieldValue)
        Ptr += NumToSkip;
      LLVM_DEBUG(dbgs() << Loc << ": OPC_FilterValue(" << Val << ", " << NumToSkip
                   << "): " << ((Val != CurFieldValue) ? "FAIL:" : "PASS:")
                   << " continuing at " << (Ptr - DecodeTable) << "\n");

      break;
    }
    case MCD::OPC_CheckField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      uint64_t FieldValue = fieldFromInstruction(insn, Start, Len);
      // Decode the field value.
      unsigned PtrLen = 0;
      uint64_t ExpectedValue = decodeULEB128(++Ptr, &PtrLen);
      Ptr += PtrLen;
      // NumToSkip is a plain 24-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;
      NumToSkip |= (*Ptr++) << 16;

      // If the actual and expected values don't match, skip.
      if (ExpectedValue != FieldValue)
        Ptr += NumToSkip;
      LLVM_DEBUG(dbgs() << Loc << ": OPC_CheckField(" << Start << ", "
                   << Len << ", " << ExpectedValue << ", " << NumToSkip
                   << "): FieldValue = " << FieldValue << ", ExpectedValue = "
                   << ExpectedValue << ": "
                   << ((ExpectedValue == FieldValue) ? "PASS\n" : "FAIL\n"));
      break;
    }
    case MCD::OPC_CheckPredicate: {
      unsigned Len;
      // Decode the Predicate Index value.
      unsigned PIdx = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 24-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;
      NumToSkip |= (*Ptr++) << 16;
      // Check the predicate.
      bool Pred;
      if (!(Pred = checkDecoderPredicate(PIdx, Bits)))
        Ptr += NumToSkip;
      (void)Pred;
      LLVM_DEBUG(dbgs() << Loc << ": OPC_CheckPredicate(" << PIdx << "): "
            << (Pred ? "PASS\n" : "FAIL\n"));

      break;
    }
    case MCD::OPC_Decode: {
      unsigned Len;
      // Decode the Opcode value.
      unsigned Opc = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      unsigned DecodeIdx = decodeULEB128(Ptr, &Len);
      Ptr += Len;

      MI.clear();
      MI.setOpcode(Opc);
      bool DecodeComplete;
      S = decodeToMCInst(S, DecodeIdx, insn, MI, Address, DisAsm, DecodeComplete);
      assert(DecodeComplete);

      LLVM_DEBUG(dbgs() << Loc << ": OPC_Decode: opcode " << Opc
                   << ", using decoder " << DecodeIdx << ": "
                   << (S != MCDisassembler::Fail ? "PASS" : "FAIL") << "\n");
      return S;
    }
    case MCD::OPC_TryDecode: {
      unsigned Len;
      // Decode the Opcode value.
      unsigned Opc = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      unsigned DecodeIdx = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 24-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;
      NumToSkip |= (*Ptr++) << 16;

      // Perform the decode operation.
      MCInst TmpMI;
      TmpMI.setOpcode(Opc);
      bool DecodeComplete;
      S = decodeToMCInst(S, DecodeIdx, insn, TmpMI, Address, DisAsm, DecodeComplete);
      LLVM_DEBUG(dbgs() << Loc << ": OPC_TryDecode: opcode " << Opc
                   << ", using decoder " << DecodeIdx << ": ");

      if (DecodeComplete) {
        // Decoding complete.
        LLVM_DEBUG(dbgs() << (S != MCDisassembler::Fail ? "PASS" : "FAIL") << "\n");
        MI = TmpMI;
        return S;
      } else {
        assert(S == MCDisassembler::Fail);
        // If the decoding was incomplete, skip.
        Ptr += NumToSkip;
        LLVM_DEBUG(dbgs() << "FAIL: continuing at " << (Ptr - DecodeTable) << "\n");
        // Reset decode status. This also drops a SoftFail status that could be
        // set before the decode attempt.
        S = MCDisassembler::Success;
      }
      break;
    }
    case MCD::OPC_SoftFail: {
      // Decode the mask values.
      unsigned Len;
      uint64_t PositiveMask = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      uint64_t NegativeMask = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      bool Fail = (insn & PositiveMask) != 0 || (~insn & NegativeMask) != 0;
      if (Fail)
        S = MCDisassembler::SoftFail;
      LLVM_DEBUG(dbgs() << Loc << ": OPC_SoftFail: " << (Fail ? "FAIL\n" : "PASS\n"));
      break;
    }
    case MCD::OPC_Fail: {
      LLVM_DEBUG(dbgs() << Loc << ": OPC_Fail\n");
      return MCDisassembler::Fail;
    }
    }
  }
  llvm_unreachable("bogosity detected in disassembler state machine!");
}


} // end namespace llvm
