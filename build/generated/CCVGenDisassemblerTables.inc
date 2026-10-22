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
/* 88 */      MCD::OPC_Decode, 251, 4, 3, // Opcode: SRD
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
/* 55 */      MCD::OPC_FilterValue, 8, 121, 15, 0, // Skip to: 4021
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
/* 108 */     MCD::OPC_FilterValue, 8, 68, 15, 0, // Skip to: 4021
/* 113 */     MCD::OPC_Decode, 245, 3, 9, // Opcode: LG2_F32
/* 117 */     MCD::OPC_FilterValue, 2, 39, 0, 0, // Skip to: 161
/* 122 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 125 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 134
/* 130 */     MCD::OPC_Decode, 142, 4, 9, // Opcode: OR
/* 134 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 143
/* 139 */     MCD::OPC_Decode, 211, 3, 9, // Opcode: FADD_F1
/* 143 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 152
/* 148 */     MCD::OPC_Decode, 152, 3, 9, // Opcode: CVT_F32_S32
/* 152 */     MCD::OPC_FilterValue, 3, 24, 15, 0, // Skip to: 4021
/* 157 */     MCD::OPC_Decode, 158, 3, 10, // Opcode: CVT_SEXT
/* 161 */     MCD::OPC_FilterValue, 3, 39, 0, 0, // Skip to: 205
/* 166 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 169 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 178
/* 174 */     MCD::OPC_Decode, 241, 4, 9, // Opcode: SHR
/* 178 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 187
/* 183 */     MCD::OPC_Decode, 220, 3, 9, // Opcode: FMIN_F1
/* 187 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 196
/* 192 */     MCD::OPC_Decode, 154, 3, 9, // Opcode: CVT_F32_U32
/* 196 */     MCD::OPC_FilterValue, 3, 236, 14, 0, // Skip to: 4021
/* 201 */     MCD::OPC_Decode, 132, 3, 9, // Opcode: CVT_D2_S3_R0
/* 205 */     MCD::OPC_FilterValue, 4, 39, 0, 0, // Skip to: 249
/* 210 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 213 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 222
/* 218 */     MCD::OPC_Decode, 249, 3, 9, // Opcode: MAX_S
/* 222 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 231
/* 227 */     MCD::OPC_Decode, 206, 3, 9, // Opcode: DP4_SS
/* 231 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 240
/* 236 */     MCD::OPC_Decode, 214, 2, 9, // Opcode: CVT_D1_S0_R0
/* 240 */     MCD::OPC_FilterValue, 3, 192, 14, 0, // Skip to: 4021
/* 245 */     MCD::OPC_Decode, 134, 3, 9, // Opcode: CVT_D3_S0_R0
/* 249 */     MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 293
/* 254 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 257 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 266
/* 262 */     MCD::OPC_Decode, 156, 2, 9, // Opcode: ABS
/* 266 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 275
/* 271 */     MCD::OPC_Decode, 201, 3, 9, // Opcode: DP2_BF16
/* 275 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 284
/* 280 */     MCD::OPC_Decode, 222, 2, 9, // Opcode: CVT_D1_S1_R0
/* 284 */     MCD::OPC_FilterValue, 3, 148, 14, 0, // Skip to: 4021
/* 289 */     MCD::OPC_Decode, 140, 3, 9, // Opcode: CVT_D3_S1_R0
/* 293 */     MCD::OPC_FilterValue, 6, 30, 0, 0, // Skip to: 328
/* 298 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 301 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 310
/* 306 */     MCD::OPC_Decode, 180, 2, 9, // Opcode: BREV
/* 310 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 319
/* 315 */     MCD::OPC_Decode, 230, 2, 9, // Opcode: CVT_D1_S2_R0
/* 319 */     MCD::OPC_FilterValue, 3, 113, 14, 0, // Skip to: 4021
/* 324 */     MCD::OPC_Decode, 148, 3, 9, // Opcode: CVT_D3_S2_R0
/* 328 */     MCD::OPC_FilterValue, 7, 104, 14, 0, // Skip to: 4021
/* 333 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 336 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 345
/* 341 */     MCD::OPC_Decode, 238, 2, 9, // Opcode: CVT_D1_S3_R0
/* 345 */     MCD::OPC_FilterValue, 3, 87, 14, 0, // Skip to: 4021
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
/* 397 */     MCD::OPC_FilterValue, 3, 35, 14, 0, // Skip to: 4021
/* 402 */     MCD::OPC_Decode, 247, 2, 11, // Opcode: CVT_D2_S0_R0_P
/* 406 */     MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 441
/* 411 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 414 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 423
/* 419 */     MCD::OPC_Decode, 139, 4, 11, // Opcode: MUL_HI_U_P
/* 423 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 432
/* 428 */     MCD::OPC_Decode, 195, 2, 11, // Opcode: CVT_D0_S1_R0_P
/* 432 */     MCD::OPC_FilterValue, 3, 0, 14, 0, // Skip to: 4021
/* 437 */     MCD::OPC_Decode, 253, 2, 11, // Opcode: CVT_D2_S1_R0_P
/* 441 */     MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 467
/* 446 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 449 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 458
/* 454 */     MCD::OPC_Decode, 145, 4, 11, // Opcode: OR_P
/* 458 */     MCD::OPC_FilterValue, 2, 230, 13, 0, // Skip to: 4021
/* 463 */     MCD::OPC_Decode, 153, 3, 11, // Opcode: CVT_F32_S32_P
/* 467 */     MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 502
/* 472 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 475 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 484
/* 480 */     MCD::OPC_Decode, 244, 4, 11, // Opcode: SHR_P
/* 484 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 493
/* 489 */     MCD::OPC_Decode, 155, 3, 11, // Opcode: CVT_F32_U32_P
/* 493 */     MCD::OPC_FilterValue, 3, 195, 13, 0, // Skip to: 4021
/* 498 */     MCD::OPC_Decode, 133, 3, 11, // Opcode: CVT_D2_S3_R0_P
/* 502 */     MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 537
/* 507 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 510 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 519
/* 515 */     MCD::OPC_Decode, 250, 3, 11, // Opcode: MAX_S_P
/* 519 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 528
/* 524 */     MCD::OPC_Decode, 215, 2, 11, // Opcode: CVT_D1_S0_R0_P
/* 528 */     MCD::OPC_FilterValue, 3, 160, 13, 0, // Skip to: 4021
/* 533 */     MCD::OPC_Decode, 135, 3, 11, // Opcode: CVT_D3_S0_R0_P
/* 537 */     MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 563
/* 542 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 545 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 554
/* 550 */     MCD::OPC_Decode, 223, 2, 11, // Opcode: CVT_D1_S1_R0_P
/* 554 */     MCD::OPC_FilterValue, 3, 134, 13, 0, // Skip to: 4021
/* 559 */     MCD::OPC_Decode, 141, 3, 11, // Opcode: CVT_D3_S1_R0_P
/* 563 */     MCD::OPC_FilterValue, 6, 21, 0, 0, // Skip to: 589
/* 568 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 571 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 580
/* 576 */     MCD::OPC_Decode, 231, 2, 11, // Opcode: CVT_D1_S2_R0_P
/* 580 */     MCD::OPC_FilterValue, 3, 108, 13, 0, // Skip to: 4021
/* 585 */     MCD::OPC_Decode, 149, 3, 11, // Opcode: CVT_D3_S2_R0_P
/* 589 */     MCD::OPC_FilterValue, 7, 99, 13, 0, // Skip to: 4021
/* 594 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 597 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 606
/* 602 */     MCD::OPC_Decode, 239, 2, 11, // Opcode: CVT_D1_S3_R0_P
/* 606 */     MCD::OPC_FilterValue, 3, 82, 13, 0, // Skip to: 4021
/* 611 */     MCD::OPC_Decode, 151, 3, 11, // Opcode: CVT_D3_S3_R0_P
/* 615 */     MCD::OPC_FilterValue, 8, 11, 0, 0, // Skip to: 631
/* 620 */     MCD::OPC_CheckField, 8, 3, 0, 66, 13, 0, // Skip to: 4021
/* 627 */     MCD::OPC_Decode, 164, 2, 12, // Opcode: ADD_PP
/* 631 */     MCD::OPC_FilterValue, 12, 39, 0, 0, // Skip to: 675
/* 636 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 639 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 648
/* 644 */     MCD::OPC_Decode, 158, 2, 13, // Opcode: ADDI
/* 648 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 657
/* 653 */     MCD::OPC_Decode, 143, 4, 13, // Opcode: ORI
/* 657 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 666
/* 662 */     MCD::OPC_Decode, 242, 4, 14, // Opcode: SHRI
/* 666 */     MCD::OPC_FilterValue, 5, 22, 13, 0, // Skip to: 4021
/* 671 */     MCD::OPC_Decode, 147, 4, 15, // Opcode: PACKI
/* 675 */     MCD::OPC_FilterValue, 16, 30, 0, 0, // Skip to: 710
/* 680 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 683 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 692
/* 688 */     MCD::OPC_Decode, 160, 2, 16, // Opcode: ADDI_P
/* 692 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 701
/* 697 */     MCD::OPC_Decode, 144, 4, 16, // Opcode: ORI_P
/* 701 */     MCD::OPC_FilterValue, 3, 243, 12, 0, // Skip to: 4021
/* 706 */     MCD::OPC_Decode, 243, 4, 17, // Opcode: SHRI_P
/* 710 */     MCD::OPC_FilterValue, 20, 11, 0, 0, // Skip to: 726
/* 715 */     MCD::OPC_CheckField, 8, 3, 0, 227, 12, 0, // Skip to: 4021
/* 722 */     MCD::OPC_Decode, 161, 2, 18, // Opcode: ADDI_PP
/* 726 */     MCD::OPC_FilterValue, 24, 77, 0, 0, // Skip to: 808
/* 731 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 734 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 750
/* 739 */     MCD::OPC_CheckField, 23, 4, 0, 203, 12, 0, // Skip to: 4021
/* 746 */     MCD::OPC_Decode, 212, 4, 19, // Opcode: SETP_LT
/* 750 */     MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 766
/* 755 */     MCD::OPC_CheckField, 23, 4, 0, 187, 12, 0, // Skip to: 4021
/* 762 */     MCD::OPC_Decode, 184, 4, 19, // Opcode: SETP_GT
/* 766 */     MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 782
/* 771 */     MCD::OPC_CheckField, 23, 4, 0, 171, 12, 0, // Skip to: 4021
/* 778 */     MCD::OPC_Decode, 194, 4, 19, // Opcode: SETP_GT_U
/* 782 */     MCD::OPC_FilterValue, 3, 162, 12, 0, // Skip to: 4021
/* 787 */     MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 790 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 799
/* 795 */     MCD::OPC_Decode, 161, 4, 19, // Opcode: SETP_EQ_F
/* 799 */     MCD::OPC_FilterValue, 1, 145, 12, 0, // Skip to: 4021
/* 804 */     MCD::OPC_Decode, 162, 4, 19, // Opcode: SETP_EQ_F1
/* 808 */     MCD::OPC_FilterValue, 28, 39, 0, 0, // Skip to: 852
/* 813 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 816 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 825
/* 821 */     MCD::OPC_Decode, 219, 4, 20, // Opcode: SETP_LT_I
/* 825 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 834
/* 830 */     MCD::OPC_Decode, 191, 4, 20, // Opcode: SETP_GT_I
/* 834 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 843
/* 839 */     MCD::OPC_Decode, 195, 4, 20, // Opcode: SETP_GT_U_I
/* 843 */     MCD::OPC_FilterValue, 3, 101, 12, 0, // Skip to: 4021
/* 848 */     MCD::OPC_Decode, 164, 4, 20, // Opcode: SETP_EQ_F_I
/* 852 */     MCD::OPC_FilterValue, 32, 39, 0, 0, // Skip to: 896
/* 857 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 860 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 869
/* 865 */     MCD::OPC_Decode, 229, 3, 13, // Opcode: LD_GLOBAL
/* 869 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 878
/* 874 */     MCD::OPC_Decode, 230, 3, 21, // Opcode: LD_GLOBAL_IDX
/* 878 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 887
/* 883 */     MCD::OPC_Decode, 239, 3, 22, // Opcode: LD_PRED_G
/* 887 */     MCD::OPC_FilterValue, 3, 57, 12, 0, // Skip to: 4021
/* 892 */     MCD::OPC_Decode, 234, 3, 23, // Opcode: LD_GLOBAL_SLOT
/* 896 */     MCD::OPC_FilterValue, 36, 11, 0, 0, // Skip to: 912
/* 901 */     MCD::OPC_CheckField, 8, 3, 0, 41, 12, 0, // Skip to: 4021
/* 908 */     MCD::OPC_Decode, 174, 2, 24, // Opcode: ATOM_ADD_G
/* 912 */     MCD::OPC_FilterValue, 40, 35, 0, 0, // Skip to: 952
/* 917 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 920 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 929
/* 925 */     MCD::OPC_Decode, 178, 2, 25, // Opcode: BRA
/* 929 */     MCD::OPC_FilterValue, 1, 15, 12, 0, // Skip to: 4021
/* 934 */     MCD::OPC_CheckField, 30, 2, 0, 8, 12, 0, // Skip to: 4021
/* 941 */     MCD::OPC_CheckField, 19, 8, 0, 1, 12, 0, // Skip to: 4021
/* 948 */     MCD::OPC_Decode, 177, 2, 26, // Opcode: BAR_WAIT_PHASE
/* 952 */     MCD::OPC_FilterValue, 44, 11, 0, 0, // Skip to: 968
/* 957 */     MCD::OPC_CheckField, 8, 3, 0, 241, 11, 0, // Skip to: 4021
/* 964 */     MCD::OPC_Decode, 131, 4, 27, // Opcode: MOVI
/* 968 */     MCD::OPC_FilterValue, 48, 79, 0, 0, // Skip to: 1052
/* 973 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 976 */     MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 999
/* 981 */     MCD::OPC_CheckField, 30, 2, 0, 217, 11, 0, // Skip to: 4021
/* 988 */     MCD::OPC_CheckField, 24, 3, 0, 210, 11, 0, // Skip to: 4021
/* 995 */     MCD::OPC_Decode, 236, 4, 28, // Opcode: SHFL_IDX
/* 999 */     MCD::OPC_FilterValue, 1, 18, 0, 0, // Skip to: 1022
/* 1004 */    MCD::OPC_CheckField, 22, 5, 0, 194, 11, 0, // Skip to: 4021
/* 1011 */    MCD::OPC_CheckField, 11, 8, 0, 187, 11, 0, // Skip to: 4021
/* 1018 */    MCD::OPC_Decode, 146, 5, 29, // Opcode: VOTE_ANY
/* 1022 */    MCD::OPC_FilterValue, 2, 178, 11, 0, // Skip to: 4021
/* 1027 */    MCD::OPC_CheckField, 30, 2, 0, 171, 11, 0, // Skip to: 4021
/* 1034 */    MCD::OPC_CheckField, 22, 5, 0, 164, 11, 0, // Skip to: 4021
/* 1041 */    MCD::OPC_CheckField, 15, 4, 0, 157, 11, 0, // Skip to: 4021
/* 1048 */    MCD::OPC_Decode, 175, 2, 30, // Opcode: BALLOT
/* 1052 */    MCD::OPC_FilterValue, 52, 11, 0, 0, // Skip to: 1068
/* 1057 */    MCD::OPC_CheckField, 8, 3, 0, 141, 11, 0, // Skip to: 4021
/* 1064 */    MCD::OPC_Decode, 233, 3, 16, // Opcode: LD_GLOBAL_P
/* 1068 */    MCD::OPC_FilterValue, 56, 11, 0, 0, // Skip to: 1084
/* 1073 */    MCD::OPC_CheckField, 26, 6, 0, 125, 11, 0, // Skip to: 4021
/* 1080 */    MCD::OPC_Decode, 183, 2, 31, // Opcode: CHWIDTH_MULTI
/* 1084 */    MCD::OPC_FilterValue, 60, 145, 0, 0, // Skip to: 1234
/* 1089 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1092 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 1125
/* 1097 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1100 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1116
/* 1105 */    MCD::OPC_CheckField, 23, 4, 0, 93, 11, 0, // Skip to: 4021
/* 1112 */    MCD::OPC_Decode, 220, 4, 32, // Opcode: SETP_LT_NP
/* 1116 */    MCD::OPC_FilterValue, 1, 84, 11, 0, // Skip to: 4021
/* 1121 */    MCD::OPC_Decode, 221, 4, 33, // Opcode: SETP_LT_NPI
/* 1125 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 1158
/* 1130 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1133 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1149
/* 1138 */    MCD::OPC_CheckField, 23, 4, 0, 60, 11, 0, // Skip to: 4021
/* 1145 */    MCD::OPC_Decode, 192, 4, 32, // Opcode: SETP_GT_NP
/* 1149 */    MCD::OPC_FilterValue, 1, 51, 11, 0, // Skip to: 4021
/* 1154 */    MCD::OPC_Decode, 193, 4, 33, // Opcode: SETP_GT_NPI
/* 1158 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 1191
/* 1163 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1166 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1182
/* 1171 */    MCD::OPC_CheckField, 23, 4, 0, 27, 11, 0, // Skip to: 4021
/* 1178 */    MCD::OPC_Decode, 196, 4, 32, // Opcode: SETP_GT_U_NP
/* 1182 */    MCD::OPC_FilterValue, 1, 18, 11, 0, // Skip to: 4021
/* 1187 */    MCD::OPC_Decode, 197, 4, 33, // Opcode: SETP_GT_U_NPI
/* 1191 */    MCD::OPC_FilterValue, 3, 9, 11, 0, // Skip to: 4021
/* 1196 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1199 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 1225
/* 1204 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 1207 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1216
/* 1212 */    MCD::OPC_Decode, 165, 4, 32, // Opcode: SETP_EQ_F_NP
/* 1216 */    MCD::OPC_FilterValue, 1, 240, 10, 0, // Skip to: 4021
/* 1221 */    MCD::OPC_Decode, 163, 4, 32, // Opcode: SETP_EQ_F1_NP
/* 1225 */    MCD::OPC_FilterValue, 1, 231, 10, 0, // Skip to: 4021
/* 1230 */    MCD::OPC_Decode, 166, 4, 33, // Opcode: SETP_EQ_F_NPI
/* 1234 */    MCD::OPC_FilterValue, 64, 34, 1, 0, // Skip to: 1529
/* 1239 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1242 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 1295
/* 1247 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1250 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1259
/* 1255 */    MCD::OPC_Decode, 139, 5, 9, // Opcode: SUB
/* 1259 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1268
/* 1264 */    MCD::OPC_Decode, 226, 3, 9, // Opcode: FSUB
/* 1268 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1277
/* 1273 */    MCD::OPC_Decode, 188, 2, 9, // Opcode: CVT_D0_S0_R1
/* 1277 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1286
/* 1282 */    MCD::OPC_Decode, 156, 3, 9, // Opcode: CVT_S32_F32
/* 1286 */    MCD::OPC_FilterValue, 8, 170, 10, 0, // Skip to: 4021
/* 1291 */    MCD::OPC_Decode, 158, 4, 9, // Opcode: RSQRT_F32
/* 1295 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 1348
/* 1300 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1303 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1312
/* 1308 */    MCD::OPC_Decode, 246, 3, 9, // Opcode: MADLO
/* 1312 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1321
/* 1317 */    MCD::OPC_Decode, 217, 3, 9, // Opcode: FMAX
/* 1321 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1330
/* 1326 */    MCD::OPC_Decode, 196, 2, 9, // Opcode: CVT_D0_S1_R1
/* 1330 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1339
/* 1335 */    MCD::OPC_Decode, 254, 2, 9, // Opcode: CVT_D2_S1_R1
/* 1339 */    MCD::OPC_FilterValue, 8, 117, 10, 0, // Skip to: 4021
/* 1344 */    MCD::OPC_Decode, 245, 4, 9, // Opcode: SIN_F32
/* 1348 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 1383
/* 1353 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1356 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1365
/* 1361 */    MCD::OPC_Decode, 147, 5, 9, // Opcode: XOR
/* 1365 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1374
/* 1370 */    MCD::OPC_Decode, 227, 3, 9, // Opcode: FSUB_F1
/* 1374 */    MCD::OPC_FilterValue, 2, 82, 10, 0, // Skip to: 4021
/* 1379 */    MCD::OPC_Decode, 202, 2, 9, // Opcode: CVT_D0_S2_R1
/* 1383 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 1418
/* 1388 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1391 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1400
/* 1396 */    MCD::OPC_Decode, 247, 4, 9, // Opcode: SRA
/* 1400 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1409
/* 1405 */    MCD::OPC_Decode, 218, 3, 9, // Opcode: FMAX_F1
/* 1409 */    MCD::OPC_FilterValue, 2, 47, 10, 0, // Skip to: 4021
/* 1414 */    MCD::OPC_Decode, 208, 2, 9, // Opcode: CVT_D0_S3_R1
/* 1418 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1453
/* 1423 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1426 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1435
/* 1431 */    MCD::OPC_Decode, 252, 3, 9, // Opcode: MAX_U
/* 1435 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1444
/* 1440 */    MCD::OPC_Decode, 216, 2, 9, // Opcode: CVT_D1_S0_R1
/* 1444 */    MCD::OPC_FilterValue, 3, 12, 10, 0, // Skip to: 4021
/* 1449 */    MCD::OPC_Decode, 159, 3, 9, // Opcode: CVT_U32_F32
/* 1453 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 1497
/* 1458 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1461 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1470
/* 1466 */    MCD::OPC_Decode, 141, 4, 9, // Opcode: NEG
/* 1470 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1479
/* 1475 */    MCD::OPC_Decode, 202, 3, 9, // Opcode: DP2_F16
/* 1479 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1488
/* 1484 */    MCD::OPC_Decode, 224, 2, 9, // Opcode: CVT_D1_S1_R1
/* 1488 */    MCD::OPC_FilterValue, 3, 224, 9, 0, // Skip to: 4021
/* 1493 */    MCD::OPC_Decode, 142, 3, 9, // Opcode: CVT_D3_S1_R1
/* 1497 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1513
/* 1502 */    MCD::OPC_CheckField, 27, 5, 2, 208, 9, 0, // Skip to: 4021
/* 1509 */    MCD::OPC_Decode, 232, 2, 9, // Opcode: CVT_D1_S2_R1
/* 1513 */    MCD::OPC_FilterValue, 7, 199, 9, 0, // Skip to: 4021
/* 1518 */    MCD::OPC_CheckField, 27, 5, 2, 192, 9, 0, // Skip to: 4021
/* 1525 */    MCD::OPC_Decode, 240, 2, 9, // Opcode: CVT_D1_S3_R1
/* 1529 */    MCD::OPC_FilterValue, 68, 227, 0, 0, // Skip to: 1761
/* 1534 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1537 */    MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 1581
/* 1542 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1545 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1554
/* 1550 */    MCD::OPC_Decode, 142, 5, 11, // Opcode: SUB_P
/* 1554 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1563
/* 1559 */    MCD::OPC_Decode, 228, 3, 11, // Opcode: FSUB_P
/* 1563 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1572
/* 1568 */    MCD::OPC_Decode, 189, 2, 11, // Opcode: CVT_D0_S0_R1_P
/* 1572 */    MCD::OPC_FilterValue, 3, 140, 9, 0, // Skip to: 4021
/* 1577 */    MCD::OPC_Decode, 157, 3, 11, // Opcode: CVT_S32_F32_P
/* 1581 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 1616
/* 1586 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1589 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1598
/* 1594 */    MCD::OPC_Decode, 247, 3, 11, // Opcode: MADLO_P
/* 1598 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1607
/* 1603 */    MCD::OPC_Decode, 197, 2, 11, // Opcode: CVT_D0_S1_R1_P
/* 1607 */    MCD::OPC_FilterValue, 3, 105, 9, 0, // Skip to: 4021
/* 1612 */    MCD::OPC_Decode, 255, 2, 11, // Opcode: CVT_D2_S1_R1_P
/* 1616 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 1642
/* 1621 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1624 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1633
/* 1629 */    MCD::OPC_Decode, 150, 5, 11, // Opcode: XOR_P
/* 1633 */    MCD::OPC_FilterValue, 2, 79, 9, 0, // Skip to: 4021
/* 1638 */    MCD::OPC_Decode, 203, 2, 11, // Opcode: CVT_D0_S2_R1_P
/* 1642 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 1668
/* 1647 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1650 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1659
/* 1655 */    MCD::OPC_Decode, 250, 4, 11, // Opcode: SRA_P
/* 1659 */    MCD::OPC_FilterValue, 2, 53, 9, 0, // Skip to: 4021
/* 1664 */    MCD::OPC_Decode, 209, 2, 11, // Opcode: CVT_D0_S3_R1_P
/* 1668 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1703
/* 1673 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1676 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1685
/* 1681 */    MCD::OPC_Decode, 253, 3, 11, // Opcode: MAX_U_P
/* 1685 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1694
/* 1690 */    MCD::OPC_Decode, 217, 2, 11, // Opcode: CVT_D1_S0_R1_P
/* 1694 */    MCD::OPC_FilterValue, 3, 18, 9, 0, // Skip to: 4021
/* 1699 */    MCD::OPC_Decode, 160, 3, 11, // Opcode: CVT_U32_F32_P
/* 1703 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 1729
/* 1708 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1711 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1720
/* 1716 */    MCD::OPC_Decode, 225, 2, 11, // Opcode: CVT_D1_S1_R1_P
/* 1720 */    MCD::OPC_FilterValue, 3, 248, 8, 0, // Skip to: 4021
/* 1725 */    MCD::OPC_Decode, 143, 3, 11, // Opcode: CVT_D3_S1_R1_P
/* 1729 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1745
/* 1734 */    MCD::OPC_CheckField, 30, 2, 2, 232, 8, 0, // Skip to: 4021
/* 1741 */    MCD::OPC_Decode, 233, 2, 11, // Opcode: CVT_D1_S2_R1_P
/* 1745 */    MCD::OPC_FilterValue, 7, 223, 8, 0, // Skip to: 4021
/* 1750 */    MCD::OPC_CheckField, 30, 2, 2, 216, 8, 0, // Skip to: 4021
/* 1757 */    MCD::OPC_Decode, 241, 2, 11, // Opcode: CVT_D1_S3_R1_P
/* 1761 */    MCD::OPC_FilterValue, 76, 39, 0, 0, // Skip to: 1805
/* 1766 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1769 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1778
/* 1774 */    MCD::OPC_Decode, 140, 5, 13, // Opcode: SUBI
/* 1778 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1787
/* 1783 */    MCD::OPC_Decode, 148, 5, 13, // Opcode: XORI
/* 1787 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1796
/* 1792 */    MCD::OPC_Decode, 248, 4, 14, // Opcode: SRAI
/* 1796 */    MCD::OPC_FilterValue, 5, 172, 8, 0, // Skip to: 4021
/* 1801 */    MCD::OPC_Decode, 148, 4, 14, // Opcode: PACKI_Z
/* 1805 */    MCD::OPC_FilterValue, 80, 30, 0, 0, // Skip to: 1840
/* 1810 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1813 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1822
/* 1818 */    MCD::OPC_Decode, 141, 5, 16, // Opcode: SUBI_P
/* 1822 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1831
/* 1827 */    MCD::OPC_Decode, 149, 5, 16, // Opcode: XORI_P
/* 1831 */    MCD::OPC_FilterValue, 3, 137, 8, 0, // Skip to: 4021
/* 1836 */    MCD::OPC_Decode, 249, 4, 17, // Opcode: SRAI_P
/* 1840 */    MCD::OPC_FilterValue, 88, 77, 0, 0, // Skip to: 1922
/* 1845 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1848 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1864
/* 1853 */    MCD::OPC_CheckField, 23, 4, 0, 113, 8, 0, // Skip to: 4021
/* 1860 */    MCD::OPC_Decode, 198, 4, 19, // Opcode: SETP_LE
/* 1864 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1880
/* 1869 */    MCD::OPC_CheckField, 23, 4, 0, 97, 8, 0, // Skip to: 4021
/* 1876 */    MCD::OPC_Decode, 170, 4, 19, // Opcode: SETP_GE
/* 1880 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1896
/* 1885 */    MCD::OPC_CheckField, 23, 4, 0, 81, 8, 0, // Skip to: 4021
/* 1892 */    MCD::OPC_Decode, 180, 4, 19, // Opcode: SETP_GE_U
/* 1896 */    MCD::OPC_FilterValue, 3, 72, 8, 0, // Skip to: 4021
/* 1901 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 1904 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1913
/* 1909 */    MCD::OPC_Decode, 227, 4, 19, // Opcode: SETP_NE_F
/* 1913 */    MCD::OPC_FilterValue, 1, 55, 8, 0, // Skip to: 4021
/* 1918 */    MCD::OPC_Decode, 228, 4, 19, // Opcode: SETP_NE_F1
/* 1922 */    MCD::OPC_FilterValue, 92, 39, 0, 0, // Skip to: 1966
/* 1927 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1930 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1939
/* 1935 */    MCD::OPC_Decode, 205, 4, 20, // Opcode: SETP_LE_I
/* 1939 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1948
/* 1944 */    MCD::OPC_Decode, 177, 4, 20, // Opcode: SETP_GE_I
/* 1948 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1957
/* 1953 */    MCD::OPC_Decode, 181, 4, 20, // Opcode: SETP_GE_U_I
/* 1957 */    MCD::OPC_FilterValue, 3, 11, 8, 0, // Skip to: 4021
/* 1962 */    MCD::OPC_Decode, 230, 4, 20, // Opcode: SETP_NE_F_I
/* 1966 */    MCD::OPC_FilterValue, 96, 39, 0, 0, // Skip to: 2010
/* 1971 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1974 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1983
/* 1979 */    MCD::OPC_Decode, 252, 4, 13, // Opcode: ST_GLOBAL
/* 1983 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1992
/* 1988 */    MCD::OPC_Decode, 253, 4, 21, // Opcode: ST_GLOBAL_IDX
/* 1992 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2001
/* 1997 */    MCD::OPC_Decode, 133, 5, 22, // Opcode: ST_PRED_G
/* 2001 */    MCD::OPC_FilterValue, 3, 223, 7, 0, // Skip to: 4021
/* 2006 */    MCD::OPC_Decode, 128, 5, 23, // Opcode: ST_GLOBAL_SLOT
/* 2010 */    MCD::OPC_FilterValue, 104, 11, 0, 0, // Skip to: 2026
/* 2015 */    MCD::OPC_CheckField, 8, 3, 0, 207, 7, 0, // Skip to: 4021
/* 2022 */    MCD::OPC_Decode, 179, 2, 34, // Opcode: BRA_PRED
/* 2026 */    MCD::OPC_FilterValue, 112, 18, 0, 0, // Skip to: 2049
/* 2031 */    MCD::OPC_CheckField, 19, 8, 0, 191, 7, 0, // Skip to: 4021
/* 2038 */    MCD::OPC_CheckField, 8, 7, 2, 184, 7, 0, // Skip to: 4021
/* 2045 */    MCD::OPC_Decode, 144, 5, 35, // Opcode: UNBALLOT
/* 2049 */    MCD::OPC_FilterValue, 124, 145, 0, 0, // Skip to: 2199
/* 2054 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2057 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2090
/* 2062 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2065 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2081
/* 2070 */    MCD::OPC_CheckField, 23, 4, 0, 152, 7, 0, // Skip to: 4021
/* 2077 */    MCD::OPC_Decode, 206, 4, 32, // Opcode: SETP_LE_NP
/* 2081 */    MCD::OPC_FilterValue, 1, 143, 7, 0, // Skip to: 4021
/* 2086 */    MCD::OPC_Decode, 207, 4, 33, // Opcode: SETP_LE_NPI
/* 2090 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2123
/* 2095 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2098 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2114
/* 2103 */    MCD::OPC_CheckField, 23, 4, 0, 119, 7, 0, // Skip to: 4021
/* 2110 */    MCD::OPC_Decode, 178, 4, 32, // Opcode: SETP_GE_NP
/* 2114 */    MCD::OPC_FilterValue, 1, 110, 7, 0, // Skip to: 4021
/* 2119 */    MCD::OPC_Decode, 179, 4, 33, // Opcode: SETP_GE_NPI
/* 2123 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2156
/* 2128 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2131 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2147
/* 2136 */    MCD::OPC_CheckField, 23, 4, 0, 86, 7, 0, // Skip to: 4021
/* 2143 */    MCD::OPC_Decode, 182, 4, 32, // Opcode: SETP_GE_U_NP
/* 2147 */    MCD::OPC_FilterValue, 1, 77, 7, 0, // Skip to: 4021
/* 2152 */    MCD::OPC_Decode, 183, 4, 33, // Opcode: SETP_GE_U_NPI
/* 2156 */    MCD::OPC_FilterValue, 3, 68, 7, 0, // Skip to: 4021
/* 2161 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2164 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 2190
/* 2169 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2172 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2181
/* 2177 */    MCD::OPC_Decode, 231, 4, 32, // Opcode: SETP_NE_F_NP
/* 2181 */    MCD::OPC_FilterValue, 1, 43, 7, 0, // Skip to: 4021
/* 2186 */    MCD::OPC_Decode, 229, 4, 32, // Opcode: SETP_NE_F1_NP
/* 2190 */    MCD::OPC_FilterValue, 1, 34, 7, 0, // Skip to: 4021
/* 2195 */    MCD::OPC_Decode, 232, 4, 33, // Opcode: SETP_NE_F_NPI
/* 2199 */    MCD::OPC_FilterValue, 128, 1, 16, 1, 0, // Skip to: 2477
/* 2205 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2208 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 2261
/* 2213 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2216 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2225
/* 2221 */    MCD::OPC_Decode, 140, 4, 9, // Opcode: MUL_LO
/* 2225 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2234
/* 2230 */    MCD::OPC_Decode, 221, 3, 9, // Opcode: FMUL
/* 2234 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2243
/* 2239 */    MCD::OPC_Decode, 190, 2, 9, // Opcode: CVT_D0_S0_R2
/* 2243 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2252
/* 2248 */    MCD::OPC_Decode, 248, 2, 9, // Opcode: CVT_D2_S0_R2
/* 2252 */    MCD::OPC_FilterValue, 8, 228, 6, 0, // Skip to: 4021
/* 2257 */    MCD::OPC_Decode, 246, 4, 9, // Opcode: SQRT_F32
/* 2261 */    MCD::OPC_FilterValue, 1, 39, 0, 0, // Skip to: 2305
/* 2266 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2269 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2278
/* 2274 */    MCD::OPC_Decode, 224, 3, 9, // Opcode: FNEG_F0
/* 2278 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2287
/* 2283 */    MCD::OPC_Decode, 198, 2, 9, // Opcode: CVT_D0_S1_R2
/* 2287 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2296
/* 2292 */    MCD::OPC_Decode, 128, 3, 9, // Opcode: CVT_D2_S1_R2
/* 2296 */    MCD::OPC_FilterValue, 8, 184, 6, 0, // Skip to: 4021
/* 2301 */    MCD::OPC_Decode, 185, 2, 9, // Opcode: COS_F32
/* 2305 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 2340
/* 2310 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2313 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2322
/* 2318 */    MCD::OPC_Decode, 169, 2, 9, // Opcode: ANDN
/* 2322 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2331
/* 2327 */    MCD::OPC_Decode, 222, 3, 9, // Opcode: FMUL_F1
/* 2331 */    MCD::OPC_FilterValue, 2, 149, 6, 0, // Skip to: 4021
/* 2336 */    MCD::OPC_Decode, 204, 2, 9, // Opcode: CVT_D0_S2_R2
/* 2340 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 2375
/* 2345 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2348 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2357
/* 2353 */    MCD::OPC_Decode, 254, 3, 9, // Opcode: MIN_S
/* 2357 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2366
/* 2362 */    MCD::OPC_Decode, 225, 3, 9, // Opcode: FNEG_F1
/* 2366 */    MCD::OPC_FilterValue, 2, 114, 6, 0, // Skip to: 4021
/* 2371 */    MCD::OPC_Decode, 210, 2, 9, // Opcode: CVT_D0_S3_R2
/* 2375 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 2401
/* 2380 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2383 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2392
/* 2388 */    MCD::OPC_Decode, 218, 2, 9, // Opcode: CVT_D1_S0_R2
/* 2392 */    MCD::OPC_FilterValue, 3, 88, 6, 0, // Skip to: 4021
/* 2397 */    MCD::OPC_Decode, 136, 3, 9, // Opcode: CVT_D3_S0_R2
/* 2401 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 2445
/* 2406 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2409 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2418
/* 2414 */    MCD::OPC_Decode, 152, 4, 9, // Opcode: POPC
/* 2418 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2427
/* 2423 */    MCD::OPC_Decode, 204, 3, 9, // Opcode: DP4_E4M3
/* 2427 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2436
/* 2432 */    MCD::OPC_Decode, 226, 2, 9, // Opcode: CVT_D1_S1_R2
/* 2436 */    MCD::OPC_FilterValue, 3, 44, 6, 0, // Skip to: 4021
/* 2441 */    MCD::OPC_Decode, 144, 3, 9, // Opcode: CVT_D3_S1_R2
/* 2445 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2461
/* 2450 */    MCD::OPC_CheckField, 27, 5, 2, 28, 6, 0, // Skip to: 4021
/* 2457 */    MCD::OPC_Decode, 234, 2, 9, // Opcode: CVT_D1_S2_R2
/* 2461 */    MCD::OPC_FilterValue, 7, 19, 6, 0, // Skip to: 4021
/* 2466 */    MCD::OPC_CheckField, 27, 5, 2, 12, 6, 0, // Skip to: 4021
/* 2473 */    MCD::OPC_Decode, 242, 2, 9, // Opcode: CVT_D1_S3_R2
/* 2477 */    MCD::OPC_FilterValue, 132, 1, 199, 0, 0, // Skip to: 2682
/* 2483 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2486 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 2521
/* 2491 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2494 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2503
/* 2499 */    MCD::OPC_Decode, 223, 3, 11, // Opcode: FMUL_P
/* 2503 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2512
/* 2508 */    MCD::OPC_Decode, 191, 2, 11, // Opcode: CVT_D0_S0_R2_P
/* 2512 */    MCD::OPC_FilterValue, 3, 224, 5, 0, // Skip to: 4021
/* 2517 */    MCD::OPC_Decode, 249, 2, 11, // Opcode: CVT_D2_S0_R2_P
/* 2521 */    MCD::OPC_FilterValue, 1, 21, 0, 0, // Skip to: 2547
/* 2526 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2529 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2538
/* 2534 */    MCD::OPC_Decode, 199, 2, 11, // Opcode: CVT_D0_S1_R2_P
/* 2538 */    MCD::OPC_FilterValue, 3, 198, 5, 0, // Skip to: 4021
/* 2543 */    MCD::OPC_Decode, 129, 3, 11, // Opcode: CVT_D2_S1_R2_P
/* 2547 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2563
/* 2552 */    MCD::OPC_CheckField, 30, 2, 2, 182, 5, 0, // Skip to: 4021
/* 2559 */    MCD::OPC_Decode, 205, 2, 11, // Opcode: CVT_D0_S2_R2_P
/* 2563 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 2589
/* 2568 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2571 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2580
/* 2576 */    MCD::OPC_Decode, 255, 3, 11, // Opcode: MIN_S_P
/* 2580 */    MCD::OPC_FilterValue, 2, 156, 5, 0, // Skip to: 4021
/* 2585 */    MCD::OPC_Decode, 211, 2, 11, // Opcode: CVT_D0_S3_R2_P
/* 2589 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 2624
/* 2594 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2597 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2606
/* 2602 */    MCD::OPC_Decode, 133, 4, 36, // Opcode: MOV_P
/* 2606 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2615
/* 2611 */    MCD::OPC_Decode, 219, 2, 11, // Opcode: CVT_D1_S0_R2_P
/* 2615 */    MCD::OPC_FilterValue, 3, 121, 5, 0, // Skip to: 4021
/* 2620 */    MCD::OPC_Decode, 137, 3, 11, // Opcode: CVT_D3_S0_R2_P
/* 2624 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 2650
/* 2629 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2632 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2641
/* 2637 */    MCD::OPC_Decode, 227, 2, 11, // Opcode: CVT_D1_S1_R2_P
/* 2641 */    MCD::OPC_FilterValue, 3, 95, 5, 0, // Skip to: 4021
/* 2646 */    MCD::OPC_Decode, 145, 3, 11, // Opcode: CVT_D3_S1_R2_P
/* 2650 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2666
/* 2655 */    MCD::OPC_CheckField, 30, 2, 2, 79, 5, 0, // Skip to: 4021
/* 2662 */    MCD::OPC_Decode, 235, 2, 11, // Opcode: CVT_D1_S2_R2_P
/* 2666 */    MCD::OPC_FilterValue, 7, 70, 5, 0, // Skip to: 4021
/* 2671 */    MCD::OPC_CheckField, 30, 2, 2, 63, 5, 0, // Skip to: 4021
/* 2678 */    MCD::OPC_Decode, 243, 2, 11, // Opcode: CVT_D1_S3_R2_P
/* 2682 */    MCD::OPC_FilterValue, 140, 1, 30, 0, 0, // Skip to: 2718
/* 2688 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2691 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2700
/* 2696 */    MCD::OPC_Decode, 134, 4, 13, // Opcode: MULI
/* 2700 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2709
/* 2705 */    MCD::OPC_Decode, 170, 2, 13, // Opcode: ANDNI
/* 2709 */    MCD::OPC_FilterValue, 5, 27, 5, 0, // Skip to: 4021
/* 2714 */    MCD::OPC_Decode, 145, 5, 14, // Opcode: UNPACKI
/* 2718 */    MCD::OPC_FilterValue, 144, 1, 21, 0, 0, // Skip to: 2745
/* 2724 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2727 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2736
/* 2732 */    MCD::OPC_Decode, 135, 4, 16, // Opcode: MULI_P
/* 2736 */    MCD::OPC_FilterValue, 2, 0, 5, 0, // Skip to: 4021
/* 2741 */    MCD::OPC_Decode, 171, 2, 16, // Opcode: ANDNI_P
/* 2745 */    MCD::OPC_FilterValue, 152, 1, 87, 0, 0, // Skip to: 2838
/* 2751 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2754 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2770
/* 2759 */    MCD::OPC_CheckField, 23, 4, 0, 231, 4, 0, // Skip to: 4021
/* 2766 */    MCD::OPC_Decode, 160, 4, 19, // Opcode: SETP_EQ
/* 2770 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 2786
/* 2775 */    MCD::OPC_CheckField, 23, 4, 0, 215, 4, 0, // Skip to: 4021
/* 2782 */    MCD::OPC_Decode, 222, 4, 19, // Opcode: SETP_LT_U
/* 2786 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 2812
/* 2791 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2794 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2803
/* 2799 */    MCD::OPC_Decode, 213, 4, 19, // Opcode: SETP_LT_F
/* 2803 */    MCD::OPC_FilterValue, 1, 189, 4, 0, // Skip to: 4021
/* 2808 */    MCD::OPC_Decode, 214, 4, 19, // Opcode: SETP_LT_F1
/* 2812 */    MCD::OPC_FilterValue, 3, 180, 4, 0, // Skip to: 4021
/* 2817 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2820 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2829
/* 2825 */    MCD::OPC_Decode, 185, 4, 19, // Opcode: SETP_GT_F
/* 2829 */    MCD::OPC_FilterValue, 1, 163, 4, 0, // Skip to: 4021
/* 2834 */    MCD::OPC_Decode, 186, 4, 19, // Opcode: SETP_GT_F1
/* 2838 */    MCD::OPC_FilterValue, 156, 1, 39, 0, 0, // Skip to: 2883
/* 2844 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2847 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2856
/* 2852 */    MCD::OPC_Decode, 167, 4, 20, // Opcode: SETP_EQ_I
/* 2856 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2865
/* 2861 */    MCD::OPC_Decode, 223, 4, 20, // Opcode: SETP_LT_U_I
/* 2865 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2874
/* 2870 */    MCD::OPC_Decode, 216, 4, 20, // Opcode: SETP_LT_F_I
/* 2874 */    MCD::OPC_FilterValue, 3, 118, 4, 0, // Skip to: 4021
/* 2879 */    MCD::OPC_Decode, 188, 4, 20, // Opcode: SETP_GT_F_I
/* 2883 */    MCD::OPC_FilterValue, 160, 1, 30, 0, 0, // Skip to: 2919
/* 2889 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2892 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2901
/* 2897 */    MCD::OPC_Decode, 241, 3, 13, // Opcode: LD_SHARED
/* 2901 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2910
/* 2906 */    MCD::OPC_Decode, 242, 3, 21, // Opcode: LD_SHARED_IDX
/* 2910 */    MCD::OPC_FilterValue, 2, 82, 4, 0, // Skip to: 4021
/* 2915 */    MCD::OPC_Decode, 240, 3, 22, // Opcode: LD_PRED_S
/* 2919 */    MCD::OPC_FilterValue, 168, 1, 11, 0, 0, // Skip to: 2936
/* 2925 */    MCD::OPC_CheckField, 8, 3, 0, 65, 4, 0, // Skip to: 4021
/* 2932 */    MCD::OPC_Decode, 181, 2, 37, // Opcode: CALL
/* 2936 */    MCD::OPC_FilterValue, 188, 1, 155, 0, 0, // Skip to: 3097
/* 2942 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2945 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2978
/* 2950 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2953 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2969
/* 2958 */    MCD::OPC_CheckField, 23, 4, 0, 32, 4, 0, // Skip to: 4021
/* 2965 */    MCD::OPC_Decode, 168, 4, 32, // Opcode: SETP_EQ_NP
/* 2969 */    MCD::OPC_FilterValue, 1, 23, 4, 0, // Skip to: 4021
/* 2974 */    MCD::OPC_Decode, 169, 4, 33, // Opcode: SETP_EQ_NPI
/* 2978 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 3011
/* 2983 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2986 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3002
/* 2991 */    MCD::OPC_CheckField, 23, 4, 0, 255, 3, 0, // Skip to: 4021
/* 2998 */    MCD::OPC_Decode, 224, 4, 32, // Opcode: SETP_LT_U_NP
/* 3002 */    MCD::OPC_FilterValue, 1, 246, 3, 0, // Skip to: 4021
/* 3007 */    MCD::OPC_Decode, 225, 4, 33, // Opcode: SETP_LT_U_NPI
/* 3011 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 3054
/* 3016 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3019 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3045
/* 3024 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3027 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3036
/* 3032 */    MCD::OPC_Decode, 217, 4, 32, // Opcode: SETP_LT_F_NP
/* 3036 */    MCD::OPC_FilterValue, 1, 212, 3, 0, // Skip to: 4021
/* 3041 */    MCD::OPC_Decode, 215, 4, 32, // Opcode: SETP_LT_F1_NP
/* 3045 */    MCD::OPC_FilterValue, 1, 203, 3, 0, // Skip to: 4021
/* 3050 */    MCD::OPC_Decode, 218, 4, 33, // Opcode: SETP_LT_F_NPI
/* 3054 */    MCD::OPC_FilterValue, 3, 194, 3, 0, // Skip to: 4021
/* 3059 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3062 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3088
/* 3067 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3070 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3079
/* 3075 */    MCD::OPC_Decode, 189, 4, 32, // Opcode: SETP_GT_F_NP
/* 3079 */    MCD::OPC_FilterValue, 1, 169, 3, 0, // Skip to: 4021
/* 3084 */    MCD::OPC_Decode, 187, 4, 32, // Opcode: SETP_GT_F1_NP
/* 3088 */    MCD::OPC_FilterValue, 1, 160, 3, 0, // Skip to: 4021
/* 3093 */    MCD::OPC_Decode, 190, 4, 33, // Opcode: SETP_GT_F_NPI
/* 3097 */    MCD::OPC_FilterValue, 192, 1, 25, 1, 0, // Skip to: 3384
/* 3103 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3106 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 3159
/* 3111 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3114 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3123
/* 3119 */    MCD::OPC_Decode, 136, 4, 9, // Opcode: MUL_HI_S
/* 3123 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3132
/* 3128 */    MCD::OPC_Decode, 215, 3, 9, // Opcode: FFMA_F0
/* 3132 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3141
/* 3137 */    MCD::OPC_Decode, 192, 2, 9, // Opcode: CVT_D0_S0_R3
/* 3141 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3150
/* 3146 */    MCD::OPC_Decode, 250, 2, 9, // Opcode: CVT_D2_S0_R3
/* 3150 */    MCD::OPC_FilterValue, 8, 98, 3, 0, // Skip to: 4021
/* 3155 */    MCD::OPC_Decode, 207, 3, 9, // Opcode: EX2_F32
/* 3159 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 3212
/* 3164 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3167 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3176
/* 3172 */    MCD::OPC_Decode, 166, 2, 9, // Opcode: AND
/* 3176 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3185
/* 3181 */    MCD::OPC_Decode, 208, 3, 9, // Opcode: FABS_F0
/* 3185 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3194
/* 3190 */    MCD::OPC_Decode, 200, 2, 9, // Opcode: CVT_D0_S1_R3
/* 3194 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3203
/* 3199 */    MCD::OPC_Decode, 130, 3, 9, // Opcode: CVT_D2_S1_R3
/* 3203 */    MCD::OPC_FilterValue, 8, 45, 3, 0, // Skip to: 4021
/* 3208 */    MCD::OPC_Decode, 157, 4, 9, // Opcode: RCP_U32
/* 3212 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 3247
/* 3217 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3220 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3229
/* 3225 */    MCD::OPC_Decode, 237, 4, 9, // Opcode: SHL
/* 3229 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3238
/* 3234 */    MCD::OPC_Decode, 216, 3, 9, // Opcode: FFMA_F1
/* 3238 */    MCD::OPC_FilterValue, 2, 10, 3, 0, // Skip to: 4021
/* 3243 */    MCD::OPC_Decode, 206, 2, 9, // Opcode: CVT_D0_S2_R3
/* 3247 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 3282
/* 3252 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3255 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3264
/* 3260 */    MCD::OPC_Decode, 129, 4, 9, // Opcode: MIN_U
/* 3264 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3273
/* 3269 */    MCD::OPC_Decode, 209, 3, 9, // Opcode: FABS_F1
/* 3273 */    MCD::OPC_FilterValue, 2, 231, 2, 0, // Skip to: 4021
/* 3278 */    MCD::OPC_Decode, 212, 2, 9, // Opcode: CVT_D0_S3_R3
/* 3282 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 3308
/* 3287 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3290 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3299
/* 3295 */    MCD::OPC_Decode, 220, 2, 9, // Opcode: CVT_D1_S0_R3
/* 3299 */    MCD::OPC_FilterValue, 3, 205, 2, 0, // Skip to: 4021
/* 3304 */    MCD::OPC_Decode, 138, 3, 9, // Opcode: CVT_D3_S0_R3
/* 3308 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 3352
/* 3313 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3316 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3325
/* 3321 */    MCD::OPC_Decode, 184, 2, 9, // Opcode: CLZ
/* 3325 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3334
/* 3330 */    MCD::OPC_Decode, 205, 3, 9, // Opcode: DP4_E5M2
/* 3334 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3343
/* 3339 */    MCD::OPC_Decode, 228, 2, 9, // Opcode: CVT_D1_S1_R3
/* 3343 */    MCD::OPC_FilterValue, 3, 161, 2, 0, // Skip to: 4021
/* 3348 */    MCD::OPC_Decode, 146, 3, 9, // Opcode: CVT_D3_S1_R3
/* 3352 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3368
/* 3357 */    MCD::OPC_CheckField, 27, 5, 2, 145, 2, 0, // Skip to: 4021
/* 3364 */    MCD::OPC_Decode, 236, 2, 9, // Opcode: CVT_D1_S2_R3
/* 3368 */    MCD::OPC_FilterValue, 7, 136, 2, 0, // Skip to: 4021
/* 3373 */    MCD::OPC_CheckField, 27, 5, 2, 129, 2, 0, // Skip to: 4021
/* 3380 */    MCD::OPC_Decode, 244, 2, 9, // Opcode: CVT_D1_S3_R3
/* 3384 */    MCD::OPC_FilterValue, 196, 1, 218, 0, 0, // Skip to: 3608
/* 3390 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3393 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 3428
/* 3398 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3401 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3410
/* 3406 */    MCD::OPC_Decode, 137, 4, 11, // Opcode: MUL_HI_S_P
/* 3410 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3419
/* 3415 */    MCD::OPC_Decode, 193, 2, 11, // Opcode: CVT_D0_S0_R3_P
/* 3419 */    MCD::OPC_FilterValue, 3, 85, 2, 0, // Skip to: 4021
/* 3424 */    MCD::OPC_Decode, 251, 2, 11, // Opcode: CVT_D2_S0_R3_P
/* 3428 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 3463
/* 3433 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3436 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3445
/* 3441 */    MCD::OPC_Decode, 172, 2, 11, // Opcode: AND_P
/* 3445 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3454
/* 3450 */    MCD::OPC_Decode, 201, 2, 11, // Opcode: CVT_D0_S1_R3_P
/* 3454 */    MCD::OPC_FilterValue, 3, 50, 2, 0, // Skip to: 4021
/* 3459 */    MCD::OPC_Decode, 131, 3, 11, // Opcode: CVT_D2_S1_R3_P
/* 3463 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3489
/* 3468 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3471 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3480
/* 3476 */    MCD::OPC_Decode, 240, 4, 11, // Opcode: SHL_P
/* 3480 */    MCD::OPC_FilterValue, 2, 24, 2, 0, // Skip to: 4021
/* 3485 */    MCD::OPC_Decode, 207, 2, 11, // Opcode: CVT_D0_S2_R3_P
/* 3489 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 3515
/* 3494 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3497 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3506
/* 3502 */    MCD::OPC_Decode, 130, 4, 11, // Opcode: MIN_U_P
/* 3506 */    MCD::OPC_FilterValue, 2, 254, 1, 0, // Skip to: 4021
/* 3511 */    MCD::OPC_Decode, 213, 2, 11, // Opcode: CVT_D0_S3_R3_P
/* 3515 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 3550
/* 3520 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3523 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3532
/* 3528 */    MCD::OPC_Decode, 159, 4, 11, // Opcode: SEL
/* 3532 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3541
/* 3537 */    MCD::OPC_Decode, 221, 2, 11, // Opcode: CVT_D1_S0_R3_P
/* 3541 */    MCD::OPC_FilterValue, 3, 219, 1, 0, // Skip to: 4021
/* 3546 */    MCD::OPC_Decode, 139, 3, 11, // Opcode: CVT_D3_S0_R3_P
/* 3550 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 3576
/* 3555 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3558 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3567
/* 3563 */    MCD::OPC_Decode, 229, 2, 11, // Opcode: CVT_D1_S1_R3_P
/* 3567 */    MCD::OPC_FilterValue, 3, 193, 1, 0, // Skip to: 4021
/* 3572 */    MCD::OPC_Decode, 147, 3, 11, // Opcode: CVT_D3_S1_R3_P
/* 3576 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3592
/* 3581 */    MCD::OPC_CheckField, 30, 2, 2, 177, 1, 0, // Skip to: 4021
/* 3588 */    MCD::OPC_Decode, 237, 2, 11, // Opcode: CVT_D1_S2_R3_P
/* 3592 */    MCD::OPC_FilterValue, 7, 168, 1, 0, // Skip to: 4021
/* 3597 */    MCD::OPC_CheckField, 30, 2, 2, 161, 1, 0, // Skip to: 4021
/* 3604 */    MCD::OPC_Decode, 245, 2, 11, // Opcode: CVT_D1_S3_R3_P
/* 3608 */    MCD::OPC_FilterValue, 204, 1, 21, 0, 0, // Skip to: 3635
/* 3614 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3617 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3626
/* 3622 */    MCD::OPC_Decode, 167, 2, 13, // Opcode: ANDI
/* 3626 */    MCD::OPC_FilterValue, 2, 134, 1, 0, // Skip to: 4021
/* 3631 */    MCD::OPC_Decode, 238, 4, 14, // Opcode: SHLI
/* 3635 */    MCD::OPC_FilterValue, 208, 1, 21, 0, 0, // Skip to: 3662
/* 3641 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3644 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3653
/* 3649 */    MCD::OPC_Decode, 168, 2, 16, // Opcode: ANDI_P
/* 3653 */    MCD::OPC_FilterValue, 2, 107, 1, 0, // Skip to: 4021
/* 3658 */    MCD::OPC_Decode, 239, 4, 17, // Opcode: SHLI_P
/* 3662 */    MCD::OPC_FilterValue, 216, 1, 87, 0, 0, // Skip to: 3755
/* 3668 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3671 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3687
/* 3676 */    MCD::OPC_CheckField, 23, 4, 0, 82, 1, 0, // Skip to: 4021
/* 3683 */    MCD::OPC_Decode, 226, 4, 19, // Opcode: SETP_NE
/* 3687 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 3703
/* 3692 */    MCD::OPC_CheckField, 23, 4, 0, 66, 1, 0, // Skip to: 4021
/* 3699 */    MCD::OPC_Decode, 208, 4, 19, // Opcode: SETP_LE_U
/* 3703 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3729
/* 3708 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3711 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3720
/* 3716 */    MCD::OPC_Decode, 199, 4, 19, // Opcode: SETP_LE_F
/* 3720 */    MCD::OPC_FilterValue, 1, 40, 1, 0, // Skip to: 4021
/* 3725 */    MCD::OPC_Decode, 200, 4, 19, // Opcode: SETP_LE_F1
/* 3729 */    MCD::OPC_FilterValue, 3, 31, 1, 0, // Skip to: 4021
/* 3734 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3737 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3746
/* 3742 */    MCD::OPC_Decode, 171, 4, 19, // Opcode: SETP_GE_F
/* 3746 */    MCD::OPC_FilterValue, 1, 14, 1, 0, // Skip to: 4021
/* 3751 */    MCD::OPC_Decode, 172, 4, 19, // Opcode: SETP_GE_F1
/* 3755 */    MCD::OPC_FilterValue, 220, 1, 39, 0, 0, // Skip to: 3800
/* 3761 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3764 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3773
/* 3769 */    MCD::OPC_Decode, 233, 4, 20, // Opcode: SETP_NE_I
/* 3773 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3782
/* 3778 */    MCD::OPC_Decode, 209, 4, 20, // Opcode: SETP_LE_U_I
/* 3782 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3791
/* 3787 */    MCD::OPC_Decode, 202, 4, 20, // Opcode: SETP_LE_F_I
/* 3791 */    MCD::OPC_FilterValue, 3, 225, 0, 0, // Skip to: 4021
/* 3796 */    MCD::OPC_Decode, 174, 4, 20, // Opcode: SETP_GE_F_I
/* 3800 */    MCD::OPC_FilterValue, 224, 1, 30, 0, 0, // Skip to: 3836
/* 3806 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3809 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3818
/* 3814 */    MCD::OPC_Decode, 135, 5, 13, // Opcode: ST_SHARED
/* 3818 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3827
/* 3823 */    MCD::OPC_Decode, 136, 5, 21, // Opcode: ST_SHARED_IDX
/* 3827 */    MCD::OPC_FilterValue, 2, 189, 0, 0, // Skip to: 4021
/* 3832 */    MCD::OPC_Decode, 134, 5, 22, // Opcode: ST_PRED_S
/* 3836 */    MCD::OPC_FilterValue, 232, 1, 18, 0, 0, // Skip to: 3860
/* 3842 */    MCD::OPC_CheckField, 27, 5, 0, 172, 0, 0, // Skip to: 4021
/* 3849 */    MCD::OPC_CheckField, 8, 3, 0, 165, 0, 0, // Skip to: 4021
/* 3856 */    MCD::OPC_Decode, 176, 2, 38, // Opcode: BAR_INIT
/* 3860 */    MCD::OPC_FilterValue, 252, 1, 155, 0, 0, // Skip to: 4021
/* 3866 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3869 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 3902
/* 3874 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3877 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3893
/* 3882 */    MCD::OPC_CheckField, 23, 4, 0, 132, 0, 0, // Skip to: 4021
/* 3889 */    MCD::OPC_Decode, 234, 4, 32, // Opcode: SETP_NE_NP
/* 3893 */    MCD::OPC_FilterValue, 1, 123, 0, 0, // Skip to: 4021
/* 3898 */    MCD::OPC_Decode, 235, 4, 33, // Opcode: SETP_NE_NPI
/* 3902 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 3935
/* 3907 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3910 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3926
/* 3915 */    MCD::OPC_CheckField, 23, 4, 0, 99, 0, 0, // Skip to: 4021
/* 3922 */    MCD::OPC_Decode, 210, 4, 32, // Opcode: SETP_LE_U_NP
/* 3926 */    MCD::OPC_FilterValue, 1, 90, 0, 0, // Skip to: 4021
/* 3931 */    MCD::OPC_Decode, 211, 4, 33, // Opcode: SETP_LE_U_NPI
/* 3935 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 3978
/* 3940 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3943 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3969
/* 3948 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3951 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3960
/* 3956 */    MCD::OPC_Decode, 203, 4, 32, // Opcode: SETP_LE_F_NP
/* 3960 */    MCD::OPC_FilterValue, 1, 56, 0, 0, // Skip to: 4021
/* 3965 */    MCD::OPC_Decode, 201, 4, 32, // Opcode: SETP_LE_F1_NP
/* 3969 */    MCD::OPC_FilterValue, 1, 47, 0, 0, // Skip to: 4021
/* 3974 */    MCD::OPC_Decode, 204, 4, 33, // Opcode: SETP_LE_F_NPI
/* 3978 */    MCD::OPC_FilterValue, 3, 38, 0, 0, // Skip to: 4021
/* 3983 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3986 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 4012
/* 3991 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3994 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4003
/* 3999 */    MCD::OPC_Decode, 175, 4, 32, // Opcode: SETP_GE_F_NP
/* 4003 */    MCD::OPC_FilterValue, 1, 13, 0, 0, // Skip to: 4021
/* 4008 */    MCD::OPC_Decode, 173, 4, 32, // Opcode: SETP_GE_F1_NP
/* 4012 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4021
/* 4017 */    MCD::OPC_Decode, 176, 4, 33, // Opcode: SETP_GE_F_NPI
/* 4021 */    MCD::OPC_Fail,
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
