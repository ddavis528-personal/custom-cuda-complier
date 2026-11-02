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
/* 8 */       MCD::OPC_Decode, 251, 3, 0, // Opcode: FFMA_ACC_F0
/* 12 */      MCD::OPC_FilterValue, 2, 136, 0, 0, // Skip to: 153
/* 17 */      MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 20 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 29
/* 25 */      MCD::OPC_Decode, 198, 3, 1, // Opcode: C_ADD
/* 29 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 38
/* 34 */      MCD::OPC_Decode, 222, 3, 1, // Opcode: C_OR
/* 38 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 47
/* 43 */      MCD::OPC_Decode, 228, 3, 1, // Opcode: C_SHR
/* 47 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 56
/* 52 */      MCD::OPC_Decode, 214, 3, 1, // Opcode: C_MAX_S
/* 56 */      MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 65
/* 61 */      MCD::OPC_Decode, 221, 3, 2, // Opcode: C_NOT
/* 65 */      MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 212, 3, 1, // Opcode: C_FMUL
/* 74 */      MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 83
/* 79 */      MCD::OPC_Decode, 213, 3, 2, // Opcode: C_LD_GLOBAL
/* 83 */      MCD::OPC_FilterValue, 7, 4, 0, 0, // Skip to: 92
/* 88 */      MCD::OPC_Decode, 174, 5, 3, // Opcode: SRD
/* 92 */      MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 101
/* 97 */      MCD::OPC_Decode, 199, 3, 4, // Opcode: C_ADDI
/* 101 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 110
/* 106 */     MCD::OPC_Decode, 236, 3, 4, // Opcode: C_XORI
/* 110 */     MCD::OPC_FilterValue, 12, 11, 0, 0, // Skip to: 126
/* 115 */     MCD::OPC_CheckField, 14, 2, 0, 105, 1, 0, // Skip to: 483
/* 122 */     MCD::OPC_Decode, 206, 3, 5, // Opcode: C_CHWIDTH
/* 126 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 135
/* 131 */     MCD::OPC_Decode, 204, 3, 6, // Opcode: C_BAR_WAIT
/* 135 */     MCD::OPC_FilterValue, 14, 4, 0, 0, // Skip to: 144
/* 140 */     MCD::OPC_Decode, 209, 3, 6, // Opcode: C_FENCE
/* 144 */     MCD::OPC_FilterValue, 15, 78, 1, 0, // Skip to: 483
/* 149 */     MCD::OPC_Decode, 193, 4, 7, // Opcode: PAND
/* 153 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 162
/* 158 */     MCD::OPC_Decode, 252, 3, 0, // Opcode: FFMA_ACC_F1
/* 162 */     MCD::OPC_FilterValue, 6, 102, 0, 0, // Skip to: 269
/* 167 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 170 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 179
/* 175 */     MCD::OPC_Decode, 233, 3, 1, // Opcode: C_SUB
/* 179 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 188
/* 184 */     MCD::OPC_Decode, 235, 3, 1, // Opcode: C_XOR
/* 188 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 197
/* 193 */     MCD::OPC_Decode, 230, 3, 1, // Opcode: C_SRA
/* 197 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 206
/* 202 */     MCD::OPC_Decode, 215, 3, 1, // Opcode: C_MAX_U
/* 206 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 215
/* 211 */     MCD::OPC_Decode, 197, 3, 2, // Opcode: C_ABS
/* 215 */     MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 224
/* 220 */     MCD::OPC_Decode, 232, 3, 2, // Opcode: C_ST_GLOBAL
/* 224 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 233
/* 229 */     MCD::OPC_Decode, 234, 3, 4, // Opcode: C_SUBI
/* 233 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 242
/* 238 */     MCD::OPC_Decode, 227, 3, 4, // Opcode: C_SHLI
/* 242 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 251
/* 247 */     MCD::OPC_Decode, 205, 3, 8, // Opcode: C_BRA
/* 251 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 260
/* 256 */     MCD::OPC_Decode, 225, 3, 6, // Opcode: C_RET
/* 260 */     MCD::OPC_FilterValue, 15, 218, 0, 0, // Skip to: 483
/* 265 */     MCD::OPC_Decode, 197, 4, 7, // Opcode: POR
/* 269 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 278
/* 274 */     MCD::OPC_Decode, 239, 3, 0, // Opcode: DP4_ACC
/* 278 */     MCD::OPC_FilterValue, 10, 93, 0, 0, // Skip to: 376
/* 283 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 286 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 295
/* 291 */     MCD::OPC_Decode, 219, 3, 1, // Opcode: C_MUL_LO
/* 295 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 304
/* 300 */     MCD::OPC_Decode, 202, 3, 1, // Opcode: C_ANDN
/* 304 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 313
/* 309 */     MCD::OPC_Decode, 216, 3, 1, // Opcode: C_MIN_S
/* 313 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 322
/* 318 */     MCD::OPC_Decode, 218, 3, 2, // Opcode: C_MOV
/* 322 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 331
/* 327 */     MCD::OPC_Decode, 208, 3, 1, // Opcode: C_FADD
/* 331 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 340
/* 336 */     MCD::OPC_Decode, 211, 3, 1, // Opcode: C_FMIN
/* 340 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 349
/* 345 */     MCD::OPC_Decode, 201, 3, 4, // Opcode: C_ANDI
/* 349 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 358
/* 354 */     MCD::OPC_Decode, 229, 3, 4, // Opcode: C_SHRI
/* 358 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 367
/* 363 */     MCD::OPC_Decode, 207, 3, 6, // Opcode: C_EXIT
/* 367 */     MCD::OPC_FilterValue, 15, 111, 0, 0, // Skip to: 483
/* 372 */     MCD::OPC_Decode, 198, 4, 7, // Opcode: PXOR
/* 376 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 385
/* 381 */     MCD::OPC_Decode, 164, 4, 0, // Opcode: MAD_ACC
/* 385 */     MCD::OPC_FilterValue, 14, 93, 0, 0, // Skip to: 483
/* 390 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 393 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 402
/* 398 */     MCD::OPC_Decode, 200, 3, 1, // Opcode: C_AND
/* 402 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 411
/* 407 */     MCD::OPC_Decode, 226, 3, 1, // Opcode: C_SHL
/* 411 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 420
/* 416 */     MCD::OPC_Decode, 217, 3, 1, // Opcode: C_MIN_U
/* 420 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 429
/* 425 */     MCD::OPC_Decode, 220, 3, 2, // Opcode: C_NEG
/* 429 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 438
/* 434 */     MCD::OPC_Decode, 210, 3, 1, // Opcode: C_FMAX
/* 438 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 447
/* 443 */     MCD::OPC_Decode, 223, 3, 4, // Opcode: C_ORI
/* 447 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 456
/* 452 */     MCD::OPC_Decode, 231, 3, 4, // Opcode: C_SRAI
/* 456 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 465
/* 461 */     MCD::OPC_Decode, 203, 3, 6, // Opcode: C_BAR_ARRIVE
/* 465 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 474
/* 470 */     MCD::OPC_Decode, 224, 3, 6, // Opcode: C_RECONV
/* 474 */     MCD::OPC_FilterValue, 15, 4, 0, 0, // Skip to: 483
/* 479 */     MCD::OPC_Decode, 194, 4, 7, // Opcode: PMOV
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
/* 24 */      MCD::OPC_Decode, 163, 2, 9, // Opcode: ADD
/* 28 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 37
/* 33 */      MCD::OPC_Decode, 246, 3, 9, // Opcode: FADD
/* 37 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 46
/* 42 */      MCD::OPC_Decode, 212, 2, 9, // Opcode: CVT_D0_S0_R0
/* 46 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 55
/* 51 */      MCD::OPC_Decode, 154, 3, 9, // Opcode: CVT_D2_S0_R0
/* 55 */      MCD::OPC_FilterValue, 8, 161, 17, 0, // Skip to: 4573
/* 60 */      MCD::OPC_Decode, 199, 4, 9, // Opcode: RCP_F32
/* 64 */      MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 117
/* 69 */      MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 72 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 81
/* 77 */      MCD::OPC_Decode, 182, 4, 9, // Opcode: MUL_HI_U
/* 81 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 129, 4, 9, // Opcode: FMIN
/* 90 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 99
/* 95 */      MCD::OPC_Decode, 227, 2, 9, // Opcode: CVT_D0_S1_R0
/* 99 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 108
/* 104 */     MCD::OPC_Decode, 160, 3, 9, // Opcode: CVT_D2_S1_R0
/* 108 */     MCD::OPC_FilterValue, 8, 108, 17, 0, // Skip to: 4573
/* 113 */     MCD::OPC_Decode, 161, 4, 9, // Opcode: LG2_F32
/* 117 */     MCD::OPC_FilterValue, 2, 39, 0, 0, // Skip to: 161
/* 122 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 125 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 134
/* 130 */     MCD::OPC_Decode, 186, 4, 9, // Opcode: OR
/* 134 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 143
/* 139 */     MCD::OPC_Decode, 247, 3, 9, // Opcode: FADD_F1
/* 143 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 152
/* 148 */     MCD::OPC_Decode, 188, 3, 9, // Opcode: CVT_F32_S32
/* 152 */     MCD::OPC_FilterValue, 3, 64, 17, 0, // Skip to: 4573
/* 157 */     MCD::OPC_Decode, 194, 3, 10, // Opcode: CVT_SEXT
/* 161 */     MCD::OPC_FilterValue, 3, 39, 0, 0, // Skip to: 205
/* 166 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 169 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 178
/* 174 */     MCD::OPC_Decode, 164, 5, 9, // Opcode: SHR
/* 178 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 187
/* 183 */     MCD::OPC_Decode, 130, 4, 9, // Opcode: FMIN_F1
/* 187 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 196
/* 192 */     MCD::OPC_Decode, 190, 3, 9, // Opcode: CVT_F32_U32
/* 196 */     MCD::OPC_FilterValue, 3, 20, 17, 0, // Skip to: 4573
/* 201 */     MCD::OPC_Decode, 168, 3, 9, // Opcode: CVT_D2_S3_R0
/* 205 */     MCD::OPC_FilterValue, 4, 39, 0, 0, // Skip to: 249
/* 210 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 213 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 222
/* 218 */     MCD::OPC_Decode, 165, 4, 9, // Opcode: MAX_S
/* 222 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 231
/* 227 */     MCD::OPC_Decode, 242, 3, 9, // Opcode: DP4_SS
/* 231 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 240
/* 236 */     MCD::OPC_Decode, 249, 2, 9, // Opcode: CVT_D1_S0_R0
/* 240 */     MCD::OPC_FilterValue, 3, 232, 16, 0, // Skip to: 4573
/* 245 */     MCD::OPC_Decode, 170, 3, 9, // Opcode: CVT_D3_S0_R0
/* 249 */     MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 293
/* 254 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 257 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 266
/* 262 */     MCD::OPC_Decode, 162, 2, 9, // Opcode: ABS
/* 266 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 275
/* 271 */     MCD::OPC_Decode, 237, 3, 9, // Opcode: DP2_BF16
/* 275 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 284
/* 280 */     MCD::OPC_Decode, 130, 3, 9, // Opcode: CVT_D1_S1_R0
/* 284 */     MCD::OPC_FilterValue, 3, 188, 16, 0, // Skip to: 4573
/* 289 */     MCD::OPC_Decode, 176, 3, 9, // Opcode: CVT_D3_S1_R0
/* 293 */     MCD::OPC_FilterValue, 6, 30, 0, 0, // Skip to: 328
/* 298 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 301 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 310
/* 306 */     MCD::OPC_Decode, 205, 2, 9, // Opcode: BREV
/* 310 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 319
/* 315 */     MCD::OPC_Decode, 138, 3, 9, // Opcode: CVT_D1_S2_R0
/* 319 */     MCD::OPC_FilterValue, 3, 153, 16, 0, // Skip to: 4573
/* 324 */     MCD::OPC_Decode, 184, 3, 9, // Opcode: CVT_D3_S2_R0
/* 328 */     MCD::OPC_FilterValue, 7, 144, 16, 0, // Skip to: 4573
/* 333 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 336 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 345
/* 341 */     MCD::OPC_Decode, 146, 3, 9, // Opcode: CVT_D1_S3_R0
/* 345 */     MCD::OPC_FilterValue, 3, 127, 16, 0, // Skip to: 4573
/* 350 */     MCD::OPC_Decode, 186, 3, 9, // Opcode: CVT_D3_S3_R0
/* 354 */     MCD::OPC_FilterValue, 4, 0, 1, 0, // Skip to: 615
/* 359 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 362 */     MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 406
/* 367 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 370 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 379
/* 375 */     MCD::OPC_Decode, 169, 2, 11, // Opcode: ADD_P
/* 379 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 388
/* 384 */     MCD::OPC_Decode, 249, 3, 11, // Opcode: FADD_P
/* 388 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 397
/* 393 */     MCD::OPC_Decode, 213, 2, 11, // Opcode: CVT_D0_S0_R0_P
/* 397 */     MCD::OPC_FilterValue, 3, 75, 16, 0, // Skip to: 4573
/* 402 */     MCD::OPC_Decode, 155, 3, 11, // Opcode: CVT_D2_S0_R0_P
/* 406 */     MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 441
/* 411 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 414 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 423
/* 419 */     MCD::OPC_Decode, 183, 4, 11, // Opcode: MUL_HI_U_P
/* 423 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 432
/* 428 */     MCD::OPC_Decode, 228, 2, 11, // Opcode: CVT_D0_S1_R0_P
/* 432 */     MCD::OPC_FilterValue, 3, 40, 16, 0, // Skip to: 4573
/* 437 */     MCD::OPC_Decode, 161, 3, 11, // Opcode: CVT_D2_S1_R0_P
/* 441 */     MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 467
/* 446 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 449 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 458
/* 454 */     MCD::OPC_Decode, 189, 4, 11, // Opcode: OR_P
/* 458 */     MCD::OPC_FilterValue, 2, 14, 16, 0, // Skip to: 4573
/* 463 */     MCD::OPC_Decode, 189, 3, 11, // Opcode: CVT_F32_S32_P
/* 467 */     MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 502
/* 472 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 475 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 484
/* 480 */     MCD::OPC_Decode, 167, 5, 11, // Opcode: SHR_P
/* 484 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 493
/* 489 */     MCD::OPC_Decode, 191, 3, 11, // Opcode: CVT_F32_U32_P
/* 493 */     MCD::OPC_FilterValue, 3, 235, 15, 0, // Skip to: 4573
/* 498 */     MCD::OPC_Decode, 169, 3, 11, // Opcode: CVT_D2_S3_R0_P
/* 502 */     MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 537
/* 507 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 510 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 519
/* 515 */     MCD::OPC_Decode, 166, 4, 11, // Opcode: MAX_S_P
/* 519 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 528
/* 524 */     MCD::OPC_Decode, 250, 2, 11, // Opcode: CVT_D1_S0_R0_P
/* 528 */     MCD::OPC_FilterValue, 3, 200, 15, 0, // Skip to: 4573
/* 533 */     MCD::OPC_Decode, 171, 3, 11, // Opcode: CVT_D3_S0_R0_P
/* 537 */     MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 563
/* 542 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 545 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 554
/* 550 */     MCD::OPC_Decode, 131, 3, 11, // Opcode: CVT_D1_S1_R0_P
/* 554 */     MCD::OPC_FilterValue, 3, 174, 15, 0, // Skip to: 4573
/* 559 */     MCD::OPC_Decode, 177, 3, 11, // Opcode: CVT_D3_S1_R0_P
/* 563 */     MCD::OPC_FilterValue, 6, 21, 0, 0, // Skip to: 589
/* 568 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 571 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 580
/* 576 */     MCD::OPC_Decode, 139, 3, 11, // Opcode: CVT_D1_S2_R0_P
/* 580 */     MCD::OPC_FilterValue, 3, 148, 15, 0, // Skip to: 4573
/* 585 */     MCD::OPC_Decode, 185, 3, 11, // Opcode: CVT_D3_S2_R0_P
/* 589 */     MCD::OPC_FilterValue, 7, 139, 15, 0, // Skip to: 4573
/* 594 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 597 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 606
/* 602 */     MCD::OPC_Decode, 147, 3, 11, // Opcode: CVT_D1_S3_R0_P
/* 606 */     MCD::OPC_FilterValue, 3, 122, 15, 0, // Skip to: 4573
/* 611 */     MCD::OPC_Decode, 187, 3, 11, // Opcode: CVT_D3_S3_R0_P
/* 615 */     MCD::OPC_FilterValue, 8, 11, 0, 0, // Skip to: 631
/* 620 */     MCD::OPC_CheckField, 8, 3, 0, 106, 15, 0, // Skip to: 4573
/* 627 */     MCD::OPC_Decode, 170, 2, 12, // Opcode: ADD_PP
/* 631 */     MCD::OPC_FilterValue, 12, 39, 0, 0, // Skip to: 675
/* 636 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 639 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 648
/* 644 */     MCD::OPC_Decode, 164, 2, 13, // Opcode: ADDI
/* 648 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 657
/* 653 */     MCD::OPC_Decode, 187, 4, 13, // Opcode: ORI
/* 657 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 666
/* 662 */     MCD::OPC_Decode, 165, 5, 14, // Opcode: SHRI
/* 666 */     MCD::OPC_FilterValue, 5, 62, 15, 0, // Skip to: 4573
/* 671 */     MCD::OPC_Decode, 191, 4, 15, // Opcode: PACKI
/* 675 */     MCD::OPC_FilterValue, 16, 30, 0, 0, // Skip to: 710
/* 680 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 683 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 692
/* 688 */     MCD::OPC_Decode, 166, 2, 16, // Opcode: ADDI_P
/* 692 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 701
/* 697 */     MCD::OPC_Decode, 188, 4, 16, // Opcode: ORI_P
/* 701 */     MCD::OPC_FilterValue, 3, 27, 15, 0, // Skip to: 4573
/* 706 */     MCD::OPC_Decode, 166, 5, 17, // Opcode: SHRI_P
/* 710 */     MCD::OPC_FilterValue, 20, 11, 0, 0, // Skip to: 726
/* 715 */     MCD::OPC_CheckField, 8, 3, 0, 11, 15, 0, // Skip to: 4573
/* 722 */     MCD::OPC_Decode, 167, 2, 18, // Opcode: ADDI_PP
/* 726 */     MCD::OPC_FilterValue, 24, 77, 0, 0, // Skip to: 808
/* 731 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 734 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 750
/* 739 */     MCD::OPC_CheckField, 23, 4, 0, 243, 14, 0, // Skip to: 4573
/* 746 */     MCD::OPC_Decode, 128, 5, 19, // Opcode: SETP_LT
/* 750 */     MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 766
/* 755 */     MCD::OPC_CheckField, 23, 4, 0, 227, 14, 0, // Skip to: 4573
/* 762 */     MCD::OPC_Decode, 228, 4, 19, // Opcode: SETP_GT
/* 766 */     MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 782
/* 771 */     MCD::OPC_CheckField, 23, 4, 0, 211, 14, 0, // Skip to: 4573
/* 778 */     MCD::OPC_Decode, 238, 4, 19, // Opcode: SETP_GT_U
/* 782 */     MCD::OPC_FilterValue, 3, 202, 14, 0, // Skip to: 4573
/* 787 */     MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 790 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 799
/* 795 */     MCD::OPC_Decode, 205, 4, 19, // Opcode: SETP_EQ_F
/* 799 */     MCD::OPC_FilterValue, 1, 185, 14, 0, // Skip to: 4573
/* 804 */     MCD::OPC_Decode, 206, 4, 19, // Opcode: SETP_EQ_F1
/* 808 */     MCD::OPC_FilterValue, 28, 39, 0, 0, // Skip to: 852
/* 813 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 816 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 825
/* 821 */     MCD::OPC_Decode, 135, 5, 20, // Opcode: SETP_LT_I
/* 825 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 834
/* 830 */     MCD::OPC_Decode, 235, 4, 20, // Opcode: SETP_GT_I
/* 834 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 843
/* 839 */     MCD::OPC_Decode, 239, 4, 20, // Opcode: SETP_GT_U_I
/* 843 */     MCD::OPC_FilterValue, 3, 141, 14, 0, // Skip to: 4573
/* 848 */     MCD::OPC_Decode, 208, 4, 20, // Opcode: SETP_EQ_F_I
/* 852 */     MCD::OPC_FilterValue, 32, 75, 0, 0, // Skip to: 932
/* 857 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 860 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 869
/* 865 */     MCD::OPC_Decode, 143, 4, 13, // Opcode: LD_GLOBAL
/* 869 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 878
/* 874 */     MCD::OPC_Decode, 144, 4, 21, // Opcode: LD_GLOBAL_IDX
/* 878 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 887
/* 883 */     MCD::OPC_Decode, 154, 4, 22, // Opcode: LD_PRED_G
/* 887 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 896
/* 892 */     MCD::OPC_Decode, 148, 4, 23, // Opcode: LD_GLOBAL_SLOT
/* 896 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 905
/* 901 */     MCD::OPC_Decode, 153, 4, 24, // Opcode: LD_LOCAL
/* 905 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 914
/* 910 */     MCD::OPC_Decode, 203, 5, 21, // Opcode: SZ_GLOBAL_LD_U8
/* 914 */     MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 923
/* 919 */     MCD::OPC_Decode, 207, 5, 21, // Opcode: SZ_GLOBAL_ST_8
/* 923 */     MCD::OPC_FilterValue, 7, 61, 14, 0, // Skip to: 4573
/* 928 */     MCD::OPC_Decode, 211, 5, 21, // Opcode: SZ_SHARED_LD_U16
/* 932 */     MCD::OPC_FilterValue, 36, 57, 0, 0, // Skip to: 994
/* 937 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 940 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 949
/* 945 */     MCD::OPC_Decode, 182, 2, 25, // Opcode: ATOM_ADD_G
/* 949 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 958
/* 954 */     MCD::OPC_Decode, 190, 2, 25, // Opcode: ATOM_MAX_U_G
/* 958 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 967
/* 963 */     MCD::OPC_Decode, 186, 2, 25, // Opcode: ATOM_EXCH_G
/* 967 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 976
/* 972 */     MCD::OPC_Decode, 183, 2, 25, // Opcode: ATOM_ADD_S
/* 976 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 985
/* 981 */     MCD::OPC_Decode, 191, 2, 25, // Opcode: ATOM_MAX_U_S
/* 985 */     MCD::OPC_FilterValue, 6, 255, 13, 0, // Skip to: 4573
/* 990 */     MCD::OPC_Decode, 187, 2, 25, // Opcode: ATOM_EXCH_S
/* 994 */     MCD::OPC_FilterValue, 40, 35, 0, 0, // Skip to: 1034
/* 999 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1002 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1011
/* 1007 */    MCD::OPC_Decode, 203, 2, 26, // Opcode: BRA
/* 1011 */    MCD::OPC_FilterValue, 1, 229, 13, 0, // Skip to: 4573
/* 1016 */    MCD::OPC_CheckField, 30, 2, 0, 222, 13, 0, // Skip to: 4573
/* 1023 */    MCD::OPC_CheckField, 19, 8, 0, 215, 13, 0, // Skip to: 4573
/* 1030 */    MCD::OPC_Decode, 202, 2, 27, // Opcode: BAR_WAIT_PHASE
/* 1034 */    MCD::OPC_FilterValue, 44, 11, 0, 0, // Skip to: 1050
/* 1039 */    MCD::OPC_CheckField, 8, 3, 0, 199, 13, 0, // Skip to: 4573
/* 1046 */    MCD::OPC_Decode, 175, 4, 24, // Opcode: MOVI
/* 1050 */    MCD::OPC_FilterValue, 48, 102, 0, 0, // Skip to: 1157
/* 1055 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1058 */    MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 1081
/* 1063 */    MCD::OPC_CheckField, 30, 2, 0, 175, 13, 0, // Skip to: 4573
/* 1070 */    MCD::OPC_CheckField, 24, 3, 0, 168, 13, 0, // Skip to: 4573
/* 1077 */    MCD::OPC_Decode, 156, 5, 28, // Opcode: SHFL_IDX
/* 1081 */    MCD::OPC_FilterValue, 1, 18, 0, 0, // Skip to: 1104
/* 1086 */    MCD::OPC_CheckField, 22, 5, 0, 152, 13, 0, // Skip to: 4573
/* 1093 */    MCD::OPC_CheckField, 11, 8, 0, 145, 13, 0, // Skip to: 4573
/* 1100 */    MCD::OPC_Decode, 218, 5, 29, // Opcode: VOTE_ANY
/* 1104 */    MCD::OPC_FilterValue, 2, 25, 0, 0, // Skip to: 1134
/* 1109 */    MCD::OPC_CheckField, 30, 2, 0, 129, 13, 0, // Skip to: 4573
/* 1116 */    MCD::OPC_CheckField, 22, 5, 0, 122, 13, 0, // Skip to: 4573
/* 1123 */    MCD::OPC_CheckField, 15, 4, 0, 115, 13, 0, // Skip to: 4573
/* 1130 */    MCD::OPC_Decode, 200, 2, 30, // Opcode: BALLOT
/* 1134 */    MCD::OPC_FilterValue, 4, 106, 13, 0, // Skip to: 4573
/* 1139 */    MCD::OPC_CheckField, 30, 2, 0, 99, 13, 0, // Skip to: 4573
/* 1146 */    MCD::OPC_CheckField, 23, 4, 0, 92, 13, 0, // Skip to: 4573
/* 1153 */    MCD::OPC_Decode, 157, 5, 31, // Opcode: SHFL_IDX_R
/* 1157 */    MCD::OPC_FilterValue, 52, 11, 0, 0, // Skip to: 1173
/* 1162 */    MCD::OPC_CheckField, 8, 3, 0, 76, 13, 0, // Skip to: 4573
/* 1169 */    MCD::OPC_Decode, 147, 4, 16, // Opcode: LD_GLOBAL_P
/* 1173 */    MCD::OPC_FilterValue, 56, 11, 0, 0, // Skip to: 1189
/* 1178 */    MCD::OPC_CheckField, 26, 6, 0, 60, 13, 0, // Skip to: 4573
/* 1185 */    MCD::OPC_Decode, 209, 2, 32, // Opcode: CHWIDTH_MULTI
/* 1189 */    MCD::OPC_FilterValue, 60, 145, 0, 0, // Skip to: 1339
/* 1194 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1197 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 1230
/* 1202 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1205 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1221
/* 1210 */    MCD::OPC_CheckField, 23, 4, 0, 28, 13, 0, // Skip to: 4573
/* 1217 */    MCD::OPC_Decode, 136, 5, 33, // Opcode: SETP_LT_NP
/* 1221 */    MCD::OPC_FilterValue, 1, 19, 13, 0, // Skip to: 4573
/* 1226 */    MCD::OPC_Decode, 137, 5, 34, // Opcode: SETP_LT_NPI
/* 1230 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 1263
/* 1235 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1238 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1254
/* 1243 */    MCD::OPC_CheckField, 23, 4, 0, 251, 12, 0, // Skip to: 4573
/* 1250 */    MCD::OPC_Decode, 236, 4, 33, // Opcode: SETP_GT_NP
/* 1254 */    MCD::OPC_FilterValue, 1, 242, 12, 0, // Skip to: 4573
/* 1259 */    MCD::OPC_Decode, 237, 4, 34, // Opcode: SETP_GT_NPI
/* 1263 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 1296
/* 1268 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1271 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1287
/* 1276 */    MCD::OPC_CheckField, 23, 4, 0, 218, 12, 0, // Skip to: 4573
/* 1283 */    MCD::OPC_Decode, 240, 4, 33, // Opcode: SETP_GT_U_NP
/* 1287 */    MCD::OPC_FilterValue, 1, 209, 12, 0, // Skip to: 4573
/* 1292 */    MCD::OPC_Decode, 241, 4, 34, // Opcode: SETP_GT_U_NPI
/* 1296 */    MCD::OPC_FilterValue, 3, 200, 12, 0, // Skip to: 4573
/* 1301 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1304 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 1330
/* 1309 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 1312 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1321
/* 1317 */    MCD::OPC_Decode, 209, 4, 33, // Opcode: SETP_EQ_F_NP
/* 1321 */    MCD::OPC_FilterValue, 1, 175, 12, 0, // Skip to: 4573
/* 1326 */    MCD::OPC_Decode, 207, 4, 33, // Opcode: SETP_EQ_F1_NP
/* 1330 */    MCD::OPC_FilterValue, 1, 166, 12, 0, // Skip to: 4573
/* 1335 */    MCD::OPC_Decode, 210, 4, 34, // Opcode: SETP_EQ_F_NPI
/* 1339 */    MCD::OPC_FilterValue, 64, 34, 1, 0, // Skip to: 1634
/* 1344 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1347 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 1400
/* 1352 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1355 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1364
/* 1360 */    MCD::OPC_Decode, 192, 5, 9, // Opcode: SUB
/* 1364 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1373
/* 1369 */    MCD::OPC_Decode, 138, 4, 9, // Opcode: FSUB
/* 1373 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1382
/* 1378 */    MCD::OPC_Decode, 221, 2, 9, // Opcode: CVT_D0_S0_R1
/* 1382 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1391
/* 1387 */    MCD::OPC_Decode, 192, 3, 9, // Opcode: CVT_S32_F32
/* 1391 */    MCD::OPC_FilterValue, 8, 105, 12, 0, // Skip to: 4573
/* 1396 */    MCD::OPC_Decode, 202, 4, 9, // Opcode: RSQRT_F32
/* 1400 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 1453
/* 1405 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1408 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1417
/* 1413 */    MCD::OPC_Decode, 162, 4, 9, // Opcode: MADLO
/* 1417 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1426
/* 1422 */    MCD::OPC_Decode, 255, 3, 9, // Opcode: FMAX
/* 1426 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1435
/* 1431 */    MCD::OPC_Decode, 231, 2, 9, // Opcode: CVT_D0_S1_R1
/* 1435 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1444
/* 1440 */    MCD::OPC_Decode, 162, 3, 9, // Opcode: CVT_D2_S1_R1
/* 1444 */    MCD::OPC_FilterValue, 8, 52, 12, 0, // Skip to: 4573
/* 1449 */    MCD::OPC_Decode, 168, 5, 9, // Opcode: SIN_F32
/* 1453 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 1488
/* 1458 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1461 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1470
/* 1466 */    MCD::OPC_Decode, 219, 5, 9, // Opcode: XOR
/* 1470 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1479
/* 1475 */    MCD::OPC_Decode, 139, 4, 9, // Opcode: FSUB_F1
/* 1479 */    MCD::OPC_FilterValue, 2, 17, 12, 0, // Skip to: 4573
/* 1484 */    MCD::OPC_Decode, 237, 2, 9, // Opcode: CVT_D0_S2_R1
/* 1488 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 1523
/* 1493 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1496 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1505
/* 1501 */    MCD::OPC_Decode, 170, 5, 9, // Opcode: SRA
/* 1505 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1514
/* 1510 */    MCD::OPC_Decode, 128, 4, 9, // Opcode: FMAX_F1
/* 1514 */    MCD::OPC_FilterValue, 2, 238, 11, 0, // Skip to: 4573
/* 1519 */    MCD::OPC_Decode, 243, 2, 9, // Opcode: CVT_D0_S3_R1
/* 1523 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1558
/* 1528 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1531 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1540
/* 1536 */    MCD::OPC_Decode, 168, 4, 9, // Opcode: MAX_U
/* 1540 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1549
/* 1545 */    MCD::OPC_Decode, 252, 2, 9, // Opcode: CVT_D1_S0_R1
/* 1549 */    MCD::OPC_FilterValue, 3, 203, 11, 0, // Skip to: 4573
/* 1554 */    MCD::OPC_Decode, 195, 3, 9, // Opcode: CVT_U32_F32
/* 1558 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 1602
/* 1563 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1566 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1575
/* 1571 */    MCD::OPC_Decode, 185, 4, 9, // Opcode: NEG
/* 1575 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1584
/* 1580 */    MCD::OPC_Decode, 238, 3, 9, // Opcode: DP2_F16
/* 1584 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1593
/* 1589 */    MCD::OPC_Decode, 132, 3, 9, // Opcode: CVT_D1_S1_R1
/* 1593 */    MCD::OPC_FilterValue, 3, 159, 11, 0, // Skip to: 4573
/* 1598 */    MCD::OPC_Decode, 178, 3, 9, // Opcode: CVT_D3_S1_R1
/* 1602 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1618
/* 1607 */    MCD::OPC_CheckField, 27, 5, 2, 143, 11, 0, // Skip to: 4573
/* 1614 */    MCD::OPC_Decode, 140, 3, 9, // Opcode: CVT_D1_S2_R1
/* 1618 */    MCD::OPC_FilterValue, 7, 134, 11, 0, // Skip to: 4573
/* 1623 */    MCD::OPC_CheckField, 27, 5, 2, 127, 11, 0, // Skip to: 4573
/* 1630 */    MCD::OPC_Decode, 148, 3, 9, // Opcode: CVT_D1_S3_R1
/* 1634 */    MCD::OPC_FilterValue, 68, 227, 0, 0, // Skip to: 1866
/* 1639 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1642 */    MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 1686
/* 1647 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1650 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1659
/* 1655 */    MCD::OPC_Decode, 195, 5, 11, // Opcode: SUB_P
/* 1659 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1668
/* 1664 */    MCD::OPC_Decode, 141, 4, 11, // Opcode: FSUB_P
/* 1668 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1677
/* 1673 */    MCD::OPC_Decode, 222, 2, 11, // Opcode: CVT_D0_S0_R1_P
/* 1677 */    MCD::OPC_FilterValue, 3, 75, 11, 0, // Skip to: 4573
/* 1682 */    MCD::OPC_Decode, 193, 3, 11, // Opcode: CVT_S32_F32_P
/* 1686 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 1721
/* 1691 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1694 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1703
/* 1699 */    MCD::OPC_Decode, 163, 4, 11, // Opcode: MADLO_P
/* 1703 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1712
/* 1708 */    MCD::OPC_Decode, 232, 2, 11, // Opcode: CVT_D0_S1_R1_P
/* 1712 */    MCD::OPC_FilterValue, 3, 40, 11, 0, // Skip to: 4573
/* 1717 */    MCD::OPC_Decode, 163, 3, 11, // Opcode: CVT_D2_S1_R1_P
/* 1721 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 1747
/* 1726 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1729 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1738
/* 1734 */    MCD::OPC_Decode, 222, 5, 11, // Opcode: XOR_P
/* 1738 */    MCD::OPC_FilterValue, 2, 14, 11, 0, // Skip to: 4573
/* 1743 */    MCD::OPC_Decode, 238, 2, 11, // Opcode: CVT_D0_S2_R1_P
/* 1747 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 1773
/* 1752 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1755 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1764
/* 1760 */    MCD::OPC_Decode, 173, 5, 11, // Opcode: SRA_P
/* 1764 */    MCD::OPC_FilterValue, 2, 244, 10, 0, // Skip to: 4573
/* 1769 */    MCD::OPC_Decode, 244, 2, 11, // Opcode: CVT_D0_S3_R1_P
/* 1773 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1808
/* 1778 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1781 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1790
/* 1786 */    MCD::OPC_Decode, 169, 4, 11, // Opcode: MAX_U_P
/* 1790 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1799
/* 1795 */    MCD::OPC_Decode, 253, 2, 11, // Opcode: CVT_D1_S0_R1_P
/* 1799 */    MCD::OPC_FilterValue, 3, 209, 10, 0, // Skip to: 4573
/* 1804 */    MCD::OPC_Decode, 196, 3, 11, // Opcode: CVT_U32_F32_P
/* 1808 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 1834
/* 1813 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1816 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1825
/* 1821 */    MCD::OPC_Decode, 133, 3, 11, // Opcode: CVT_D1_S1_R1_P
/* 1825 */    MCD::OPC_FilterValue, 3, 183, 10, 0, // Skip to: 4573
/* 1830 */    MCD::OPC_Decode, 179, 3, 11, // Opcode: CVT_D3_S1_R1_P
/* 1834 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1850
/* 1839 */    MCD::OPC_CheckField, 30, 2, 2, 167, 10, 0, // Skip to: 4573
/* 1846 */    MCD::OPC_Decode, 141, 3, 11, // Opcode: CVT_D1_S2_R1_P
/* 1850 */    MCD::OPC_FilterValue, 7, 158, 10, 0, // Skip to: 4573
/* 1855 */    MCD::OPC_CheckField, 30, 2, 2, 151, 10, 0, // Skip to: 4573
/* 1862 */    MCD::OPC_Decode, 149, 3, 11, // Opcode: CVT_D1_S3_R1_P
/* 1866 */    MCD::OPC_FilterValue, 76, 39, 0, 0, // Skip to: 1910
/* 1871 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1874 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1883
/* 1879 */    MCD::OPC_Decode, 193, 5, 13, // Opcode: SUBI
/* 1883 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1892
/* 1888 */    MCD::OPC_Decode, 220, 5, 13, // Opcode: XORI
/* 1892 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1901
/* 1897 */    MCD::OPC_Decode, 171, 5, 14, // Opcode: SRAI
/* 1901 */    MCD::OPC_FilterValue, 5, 107, 10, 0, // Skip to: 4573
/* 1906 */    MCD::OPC_Decode, 192, 4, 14, // Opcode: PACKI_Z
/* 1910 */    MCD::OPC_FilterValue, 80, 30, 0, 0, // Skip to: 1945
/* 1915 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1918 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1927
/* 1923 */    MCD::OPC_Decode, 194, 5, 16, // Opcode: SUBI_P
/* 1927 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1936
/* 1932 */    MCD::OPC_Decode, 221, 5, 16, // Opcode: XORI_P
/* 1936 */    MCD::OPC_FilterValue, 3, 72, 10, 0, // Skip to: 4573
/* 1941 */    MCD::OPC_Decode, 172, 5, 17, // Opcode: SRAI_P
/* 1945 */    MCD::OPC_FilterValue, 88, 77, 0, 0, // Skip to: 2027
/* 1950 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1953 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1969
/* 1958 */    MCD::OPC_CheckField, 23, 4, 0, 48, 10, 0, // Skip to: 4573
/* 1965 */    MCD::OPC_Decode, 242, 4, 19, // Opcode: SETP_LE
/* 1969 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1985
/* 1974 */    MCD::OPC_CheckField, 23, 4, 0, 32, 10, 0, // Skip to: 4573
/* 1981 */    MCD::OPC_Decode, 214, 4, 19, // Opcode: SETP_GE
/* 1985 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2001
/* 1990 */    MCD::OPC_CheckField, 23, 4, 0, 16, 10, 0, // Skip to: 4573
/* 1997 */    MCD::OPC_Decode, 224, 4, 19, // Opcode: SETP_GE_U
/* 2001 */    MCD::OPC_FilterValue, 3, 7, 10, 0, // Skip to: 4573
/* 2006 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2009 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2018
/* 2014 */    MCD::OPC_Decode, 143, 5, 19, // Opcode: SETP_NE_F
/* 2018 */    MCD::OPC_FilterValue, 1, 246, 9, 0, // Skip to: 4573
/* 2023 */    MCD::OPC_Decode, 144, 5, 19, // Opcode: SETP_NE_F1
/* 2027 */    MCD::OPC_FilterValue, 92, 39, 0, 0, // Skip to: 2071
/* 2032 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2035 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2044
/* 2040 */    MCD::OPC_Decode, 249, 4, 20, // Opcode: SETP_LE_I
/* 2044 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2053
/* 2049 */    MCD::OPC_Decode, 221, 4, 20, // Opcode: SETP_GE_I
/* 2053 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2062
/* 2058 */    MCD::OPC_Decode, 225, 4, 20, // Opcode: SETP_GE_U_I
/* 2062 */    MCD::OPC_FilterValue, 3, 202, 9, 0, // Skip to: 4573
/* 2067 */    MCD::OPC_Decode, 146, 5, 20, // Opcode: SETP_NE_F_I
/* 2071 */    MCD::OPC_FilterValue, 96, 75, 0, 0, // Skip to: 2151
/* 2076 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2079 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2088
/* 2084 */    MCD::OPC_Decode, 175, 5, 13, // Opcode: ST_GLOBAL
/* 2088 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2097
/* 2093 */    MCD::OPC_Decode, 176, 5, 21, // Opcode: ST_GLOBAL_IDX
/* 2097 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2106
/* 2102 */    MCD::OPC_Decode, 185, 5, 22, // Opcode: ST_PRED_G
/* 2106 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2115
/* 2111 */    MCD::OPC_Decode, 179, 5, 23, // Opcode: ST_GLOBAL_SLOT
/* 2115 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 2124
/* 2120 */    MCD::OPC_Decode, 184, 5, 24, // Opcode: ST_LOCAL
/* 2124 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 2133
/* 2129 */    MCD::OPC_Decode, 199, 5, 21, // Opcode: SZ_GLOBAL_LD_S8
/* 2133 */    MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 2142
/* 2138 */    MCD::OPC_Decode, 205, 5, 21, // Opcode: SZ_GLOBAL_ST_16
/* 2142 */    MCD::OPC_FilterValue, 7, 122, 9, 0, // Skip to: 4573
/* 2147 */    MCD::OPC_Decode, 209, 5, 21, // Opcode: SZ_SHARED_LD_S16
/* 2151 */    MCD::OPC_FilterValue, 100, 57, 0, 0, // Skip to: 2213
/* 2156 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2159 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2168
/* 2164 */    MCD::OPC_Decode, 192, 2, 25, // Opcode: ATOM_MIN_S_G
/* 2168 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2177
/* 2173 */    MCD::OPC_Decode, 184, 2, 25, // Opcode: ATOM_AND_G
/* 2177 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2186
/* 2182 */    MCD::OPC_Decode, 180, 2, 25, // Opcode: ATOM_ADD_F_G
/* 2186 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 2195
/* 2191 */    MCD::OPC_Decode, 193, 2, 25, // Opcode: ATOM_MIN_S_S
/* 2195 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 2204
/* 2200 */    MCD::OPC_Decode, 185, 2, 25, // Opcode: ATOM_AND_S
/* 2204 */    MCD::OPC_FilterValue, 6, 60, 9, 0, // Skip to: 4573
/* 2209 */    MCD::OPC_Decode, 181, 2, 25, // Opcode: ATOM_ADD_F_S
/* 2213 */    MCD::OPC_FilterValue, 104, 11, 0, 0, // Skip to: 2229
/* 2218 */    MCD::OPC_CheckField, 8, 3, 0, 44, 9, 0, // Skip to: 4573
/* 2225 */    MCD::OPC_Decode, 204, 2, 35, // Opcode: BRA_PRED
/* 2229 */    MCD::OPC_FilterValue, 112, 95, 0, 0, // Skip to: 2329
/* 2234 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2237 */    MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 2260
/* 2242 */    MCD::OPC_CheckField, 30, 2, 0, 20, 9, 0, // Skip to: 4573
/* 2249 */    MCD::OPC_CheckField, 24, 3, 0, 13, 9, 0, // Skip to: 4573
/* 2256 */    MCD::OPC_Decode, 158, 5, 28, // Opcode: SHFL_UP
/* 2260 */    MCD::OPC_FilterValue, 1, 18, 0, 0, // Skip to: 2283
/* 2265 */    MCD::OPC_CheckField, 22, 5, 0, 253, 8, 0, // Skip to: 4573
/* 2272 */    MCD::OPC_CheckField, 11, 8, 0, 246, 8, 0, // Skip to: 4573
/* 2279 */    MCD::OPC_Decode, 217, 5, 29, // Opcode: VOTE_ALL
/* 2283 */    MCD::OPC_FilterValue, 2, 18, 0, 0, // Skip to: 2306
/* 2288 */    MCD::OPC_CheckField, 19, 8, 0, 230, 8, 0, // Skip to: 4573
/* 2295 */    MCD::OPC_CheckField, 11, 4, 0, 223, 8, 0, // Skip to: 4573
/* 2302 */    MCD::OPC_Decode, 215, 5, 36, // Opcode: UNBALLOT
/* 2306 */    MCD::OPC_FilterValue, 4, 214, 8, 0, // Skip to: 4573
/* 2311 */    MCD::OPC_CheckField, 30, 2, 0, 207, 8, 0, // Skip to: 4573
/* 2318 */    MCD::OPC_CheckField, 23, 4, 0, 200, 8, 0, // Skip to: 4573
/* 2325 */    MCD::OPC_Decode, 159, 5, 31, // Opcode: SHFL_UP_R
/* 2329 */    MCD::OPC_FilterValue, 124, 145, 0, 0, // Skip to: 2479
/* 2334 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2337 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2370
/* 2342 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2345 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2361
/* 2350 */    MCD::OPC_CheckField, 23, 4, 0, 168, 8, 0, // Skip to: 4573
/* 2357 */    MCD::OPC_Decode, 250, 4, 33, // Opcode: SETP_LE_NP
/* 2361 */    MCD::OPC_FilterValue, 1, 159, 8, 0, // Skip to: 4573
/* 2366 */    MCD::OPC_Decode, 251, 4, 34, // Opcode: SETP_LE_NPI
/* 2370 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2403
/* 2375 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2378 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2394
/* 2383 */    MCD::OPC_CheckField, 23, 4, 0, 135, 8, 0, // Skip to: 4573
/* 2390 */    MCD::OPC_Decode, 222, 4, 33, // Opcode: SETP_GE_NP
/* 2394 */    MCD::OPC_FilterValue, 1, 126, 8, 0, // Skip to: 4573
/* 2399 */    MCD::OPC_Decode, 223, 4, 34, // Opcode: SETP_GE_NPI
/* 2403 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2436
/* 2408 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2411 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2427
/* 2416 */    MCD::OPC_CheckField, 23, 4, 0, 102, 8, 0, // Skip to: 4573
/* 2423 */    MCD::OPC_Decode, 226, 4, 33, // Opcode: SETP_GE_U_NP
/* 2427 */    MCD::OPC_FilterValue, 1, 93, 8, 0, // Skip to: 4573
/* 2432 */    MCD::OPC_Decode, 227, 4, 34, // Opcode: SETP_GE_U_NPI
/* 2436 */    MCD::OPC_FilterValue, 3, 84, 8, 0, // Skip to: 4573
/* 2441 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2444 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 2470
/* 2449 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2452 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2461
/* 2457 */    MCD::OPC_Decode, 147, 5, 33, // Opcode: SETP_NE_F_NP
/* 2461 */    MCD::OPC_FilterValue, 1, 59, 8, 0, // Skip to: 4573
/* 2466 */    MCD::OPC_Decode, 145, 5, 33, // Opcode: SETP_NE_F1_NP
/* 2470 */    MCD::OPC_FilterValue, 1, 50, 8, 0, // Skip to: 4573
/* 2475 */    MCD::OPC_Decode, 148, 5, 34, // Opcode: SETP_NE_F_NPI
/* 2479 */    MCD::OPC_FilterValue, 128, 1, 16, 1, 0, // Skip to: 2757
/* 2485 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2488 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 2541
/* 2493 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2496 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2505
/* 2501 */    MCD::OPC_Decode, 184, 4, 9, // Opcode: MUL_LO
/* 2505 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2514
/* 2510 */    MCD::OPC_Decode, 131, 4, 9, // Opcode: FMUL
/* 2514 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2523
/* 2519 */    MCD::OPC_Decode, 223, 2, 9, // Opcode: CVT_D0_S0_R2
/* 2523 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2532
/* 2528 */    MCD::OPC_Decode, 156, 3, 9, // Opcode: CVT_D2_S0_R2
/* 2532 */    MCD::OPC_FilterValue, 8, 244, 7, 0, // Skip to: 4573
/* 2537 */    MCD::OPC_Decode, 169, 5, 9, // Opcode: SQRT_F32
/* 2541 */    MCD::OPC_FilterValue, 1, 39, 0, 0, // Skip to: 2585
/* 2546 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2549 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2558
/* 2554 */    MCD::OPC_Decode, 136, 4, 9, // Opcode: FNEG_F0
/* 2558 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2567
/* 2563 */    MCD::OPC_Decode, 233, 2, 9, // Opcode: CVT_D0_S1_R2
/* 2567 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2576
/* 2572 */    MCD::OPC_Decode, 164, 3, 9, // Opcode: CVT_D2_S1_R2
/* 2576 */    MCD::OPC_FilterValue, 8, 200, 7, 0, // Skip to: 4573
/* 2581 */    MCD::OPC_Decode, 211, 2, 9, // Opcode: COS_F32
/* 2585 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 2620
/* 2590 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2593 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2602
/* 2598 */    MCD::OPC_Decode, 175, 2, 9, // Opcode: ANDN
/* 2602 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2611
/* 2607 */    MCD::OPC_Decode, 132, 4, 9, // Opcode: FMUL_F1
/* 2611 */    MCD::OPC_FilterValue, 2, 165, 7, 0, // Skip to: 4573
/* 2616 */    MCD::OPC_Decode, 239, 2, 9, // Opcode: CVT_D0_S2_R2
/* 2620 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 2655
/* 2625 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2628 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2637
/* 2633 */    MCD::OPC_Decode, 170, 4, 9, // Opcode: MIN_S
/* 2637 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2646
/* 2642 */    MCD::OPC_Decode, 137, 4, 9, // Opcode: FNEG_F1
/* 2646 */    MCD::OPC_FilterValue, 2, 130, 7, 0, // Skip to: 4573
/* 2651 */    MCD::OPC_Decode, 245, 2, 9, // Opcode: CVT_D0_S3_R2
/* 2655 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 2681
/* 2660 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2663 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2672
/* 2668 */    MCD::OPC_Decode, 254, 2, 9, // Opcode: CVT_D1_S0_R2
/* 2672 */    MCD::OPC_FilterValue, 3, 104, 7, 0, // Skip to: 4573
/* 2677 */    MCD::OPC_Decode, 172, 3, 9, // Opcode: CVT_D3_S0_R2
/* 2681 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 2725
/* 2686 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2689 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2698
/* 2694 */    MCD::OPC_Decode, 196, 4, 9, // Opcode: POPC
/* 2698 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2707
/* 2703 */    MCD::OPC_Decode, 240, 3, 9, // Opcode: DP4_E4M3
/* 2707 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2716
/* 2712 */    MCD::OPC_Decode, 134, 3, 9, // Opcode: CVT_D1_S1_R2
/* 2716 */    MCD::OPC_FilterValue, 3, 60, 7, 0, // Skip to: 4573
/* 2721 */    MCD::OPC_Decode, 180, 3, 9, // Opcode: CVT_D3_S1_R2
/* 2725 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2741
/* 2730 */    MCD::OPC_CheckField, 27, 5, 2, 44, 7, 0, // Skip to: 4573
/* 2737 */    MCD::OPC_Decode, 142, 3, 9, // Opcode: CVT_D1_S2_R2
/* 2741 */    MCD::OPC_FilterValue, 7, 35, 7, 0, // Skip to: 4573
/* 2746 */    MCD::OPC_CheckField, 27, 5, 2, 28, 7, 0, // Skip to: 4573
/* 2753 */    MCD::OPC_Decode, 150, 3, 9, // Opcode: CVT_D1_S3_R2
/* 2757 */    MCD::OPC_FilterValue, 132, 1, 199, 0, 0, // Skip to: 2962
/* 2763 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2766 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 2801
/* 2771 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2774 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2783
/* 2779 */    MCD::OPC_Decode, 134, 4, 11, // Opcode: FMUL_P
/* 2783 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2792
/* 2788 */    MCD::OPC_Decode, 224, 2, 11, // Opcode: CVT_D0_S0_R2_P
/* 2792 */    MCD::OPC_FilterValue, 3, 240, 6, 0, // Skip to: 4573
/* 2797 */    MCD::OPC_Decode, 157, 3, 11, // Opcode: CVT_D2_S0_R2_P
/* 2801 */    MCD::OPC_FilterValue, 1, 21, 0, 0, // Skip to: 2827
/* 2806 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2809 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2818
/* 2814 */    MCD::OPC_Decode, 234, 2, 11, // Opcode: CVT_D0_S1_R2_P
/* 2818 */    MCD::OPC_FilterValue, 3, 214, 6, 0, // Skip to: 4573
/* 2823 */    MCD::OPC_Decode, 165, 3, 11, // Opcode: CVT_D2_S1_R2_P
/* 2827 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2843
/* 2832 */    MCD::OPC_CheckField, 30, 2, 2, 198, 6, 0, // Skip to: 4573
/* 2839 */    MCD::OPC_Decode, 240, 2, 11, // Opcode: CVT_D0_S2_R2_P
/* 2843 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 2869
/* 2848 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2851 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2860
/* 2856 */    MCD::OPC_Decode, 171, 4, 11, // Opcode: MIN_S_P
/* 2860 */    MCD::OPC_FilterValue, 2, 172, 6, 0, // Skip to: 4573
/* 2865 */    MCD::OPC_Decode, 246, 2, 11, // Opcode: CVT_D0_S3_R2_P
/* 2869 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 2904
/* 2874 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2877 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2886
/* 2882 */    MCD::OPC_Decode, 177, 4, 37, // Opcode: MOV_P
/* 2886 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2895
/* 2891 */    MCD::OPC_Decode, 255, 2, 11, // Opcode: CVT_D1_S0_R2_P
/* 2895 */    MCD::OPC_FilterValue, 3, 137, 6, 0, // Skip to: 4573
/* 2900 */    MCD::OPC_Decode, 173, 3, 11, // Opcode: CVT_D3_S0_R2_P
/* 2904 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 2930
/* 2909 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2912 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2921
/* 2917 */    MCD::OPC_Decode, 135, 3, 11, // Opcode: CVT_D1_S1_R2_P
/* 2921 */    MCD::OPC_FilterValue, 3, 111, 6, 0, // Skip to: 4573
/* 2926 */    MCD::OPC_Decode, 181, 3, 11, // Opcode: CVT_D3_S1_R2_P
/* 2930 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2946
/* 2935 */    MCD::OPC_CheckField, 30, 2, 2, 95, 6, 0, // Skip to: 4573
/* 2942 */    MCD::OPC_Decode, 143, 3, 11, // Opcode: CVT_D1_S2_R2_P
/* 2946 */    MCD::OPC_FilterValue, 7, 86, 6, 0, // Skip to: 4573
/* 2951 */    MCD::OPC_CheckField, 30, 2, 2, 79, 6, 0, // Skip to: 4573
/* 2958 */    MCD::OPC_Decode, 151, 3, 11, // Opcode: CVT_D1_S3_R2_P
/* 2962 */    MCD::OPC_FilterValue, 140, 1, 30, 0, 0, // Skip to: 2998
/* 2968 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2971 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2980
/* 2976 */    MCD::OPC_Decode, 178, 4, 13, // Opcode: MULI
/* 2980 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2989
/* 2985 */    MCD::OPC_Decode, 176, 2, 13, // Opcode: ANDNI
/* 2989 */    MCD::OPC_FilterValue, 5, 43, 6, 0, // Skip to: 4573
/* 2994 */    MCD::OPC_Decode, 216, 5, 14, // Opcode: UNPACKI
/* 2998 */    MCD::OPC_FilterValue, 144, 1, 21, 0, 0, // Skip to: 3025
/* 3004 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3007 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3016
/* 3012 */    MCD::OPC_Decode, 179, 4, 16, // Opcode: MULI_P
/* 3016 */    MCD::OPC_FilterValue, 2, 16, 6, 0, // Skip to: 4573
/* 3021 */    MCD::OPC_Decode, 177, 2, 16, // Opcode: ANDNI_P
/* 3025 */    MCD::OPC_FilterValue, 152, 1, 87, 0, 0, // Skip to: 3118
/* 3031 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3034 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3050
/* 3039 */    MCD::OPC_CheckField, 23, 4, 0, 247, 5, 0, // Skip to: 4573
/* 3046 */    MCD::OPC_Decode, 204, 4, 19, // Opcode: SETP_EQ
/* 3050 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 3066
/* 3055 */    MCD::OPC_CheckField, 23, 4, 0, 231, 5, 0, // Skip to: 4573
/* 3062 */    MCD::OPC_Decode, 138, 5, 19, // Opcode: SETP_LT_U
/* 3066 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3092
/* 3071 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3074 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3083
/* 3079 */    MCD::OPC_Decode, 129, 5, 19, // Opcode: SETP_LT_F
/* 3083 */    MCD::OPC_FilterValue, 1, 205, 5, 0, // Skip to: 4573
/* 3088 */    MCD::OPC_Decode, 130, 5, 19, // Opcode: SETP_LT_F1
/* 3092 */    MCD::OPC_FilterValue, 3, 196, 5, 0, // Skip to: 4573
/* 3097 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3100 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3109
/* 3105 */    MCD::OPC_Decode, 229, 4, 19, // Opcode: SETP_GT_F
/* 3109 */    MCD::OPC_FilterValue, 1, 179, 5, 0, // Skip to: 4573
/* 3114 */    MCD::OPC_Decode, 230, 4, 19, // Opcode: SETP_GT_F1
/* 3118 */    MCD::OPC_FilterValue, 156, 1, 39, 0, 0, // Skip to: 3163
/* 3124 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3127 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3136
/* 3132 */    MCD::OPC_Decode, 211, 4, 20, // Opcode: SETP_EQ_I
/* 3136 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3145
/* 3141 */    MCD::OPC_Decode, 139, 5, 20, // Opcode: SETP_LT_U_I
/* 3145 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3154
/* 3150 */    MCD::OPC_Decode, 132, 5, 20, // Opcode: SETP_LT_F_I
/* 3154 */    MCD::OPC_FilterValue, 3, 134, 5, 0, // Skip to: 4573
/* 3159 */    MCD::OPC_Decode, 232, 4, 20, // Opcode: SETP_GT_F_I
/* 3163 */    MCD::OPC_FilterValue, 160, 1, 66, 0, 0, // Skip to: 3235
/* 3169 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3172 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3181
/* 3177 */    MCD::OPC_Decode, 157, 4, 13, // Opcode: LD_SHARED
/* 3181 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3190
/* 3186 */    MCD::OPC_Decode, 158, 4, 21, // Opcode: LD_SHARED_IDX
/* 3190 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3199
/* 3195 */    MCD::OPC_Decode, 156, 4, 22, // Opcode: LD_PRED_S
/* 3199 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 3208
/* 3204 */    MCD::OPC_Decode, 155, 4, 38, // Opcode: LD_PRED_LOCAL
/* 3208 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 3217
/* 3213 */    MCD::OPC_Decode, 201, 5, 21, // Opcode: SZ_GLOBAL_LD_U16
/* 3217 */    MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 3226
/* 3222 */    MCD::OPC_Decode, 212, 5, 21, // Opcode: SZ_SHARED_LD_U8
/* 3226 */    MCD::OPC_FilterValue, 7, 62, 5, 0, // Skip to: 4573
/* 3231 */    MCD::OPC_Decode, 214, 5, 21, // Opcode: SZ_SHARED_ST_8
/* 3235 */    MCD::OPC_FilterValue, 164, 1, 39, 0, 0, // Skip to: 3280
/* 3241 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3244 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3253
/* 3249 */    MCD::OPC_Decode, 194, 2, 25, // Opcode: ATOM_MIN_U_G
/* 3253 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3262
/* 3258 */    MCD::OPC_Decode, 196, 2, 25, // Opcode: ATOM_OR_G
/* 3262 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 3271
/* 3267 */    MCD::OPC_Decode, 195, 2, 25, // Opcode: ATOM_MIN_U_S
/* 3271 */    MCD::OPC_FilterValue, 5, 17, 5, 0, // Skip to: 4573
/* 3276 */    MCD::OPC_Decode, 197, 2, 25, // Opcode: ATOM_OR_S
/* 3280 */    MCD::OPC_FilterValue, 168, 1, 11, 0, 0, // Skip to: 3297
/* 3286 */    MCD::OPC_CheckField, 8, 3, 0, 0, 5, 0, // Skip to: 4573
/* 3293 */    MCD::OPC_Decode, 206, 2, 39, // Opcode: CALL
/* 3297 */    MCD::OPC_FilterValue, 176, 1, 49, 0, 0, // Skip to: 3352
/* 3303 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3306 */    MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 3329
/* 3311 */    MCD::OPC_CheckField, 30, 2, 0, 231, 4, 0, // Skip to: 4573
/* 3318 */    MCD::OPC_CheckField, 24, 3, 0, 224, 4, 0, // Skip to: 4573
/* 3325 */    MCD::OPC_Decode, 154, 5, 28, // Opcode: SHFL_DOWN
/* 3329 */    MCD::OPC_FilterValue, 4, 215, 4, 0, // Skip to: 4573
/* 3334 */    MCD::OPC_CheckField, 30, 2, 0, 208, 4, 0, // Skip to: 4573
/* 3341 */    MCD::OPC_CheckField, 23, 4, 0, 201, 4, 0, // Skip to: 4573
/* 3348 */    MCD::OPC_Decode, 155, 5, 31, // Opcode: SHFL_DOWN_R
/* 3352 */    MCD::OPC_FilterValue, 188, 1, 155, 0, 0, // Skip to: 3513
/* 3358 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3361 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 3394
/* 3366 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3369 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3385
/* 3374 */    MCD::OPC_CheckField, 23, 4, 0, 168, 4, 0, // Skip to: 4573
/* 3381 */    MCD::OPC_Decode, 212, 4, 33, // Opcode: SETP_EQ_NP
/* 3385 */    MCD::OPC_FilterValue, 1, 159, 4, 0, // Skip to: 4573
/* 3390 */    MCD::OPC_Decode, 213, 4, 34, // Opcode: SETP_EQ_NPI
/* 3394 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 3427
/* 3399 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3402 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3418
/* 3407 */    MCD::OPC_CheckField, 23, 4, 0, 135, 4, 0, // Skip to: 4573
/* 3414 */    MCD::OPC_Decode, 140, 5, 33, // Opcode: SETP_LT_U_NP
/* 3418 */    MCD::OPC_FilterValue, 1, 126, 4, 0, // Skip to: 4573
/* 3423 */    MCD::OPC_Decode, 141, 5, 34, // Opcode: SETP_LT_U_NPI
/* 3427 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 3470
/* 3432 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3435 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3461
/* 3440 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3443 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3452
/* 3448 */    MCD::OPC_Decode, 133, 5, 33, // Opcode: SETP_LT_F_NP
/* 3452 */    MCD::OPC_FilterValue, 1, 92, 4, 0, // Skip to: 4573
/* 3457 */    MCD::OPC_Decode, 131, 5, 33, // Opcode: SETP_LT_F1_NP
/* 3461 */    MCD::OPC_FilterValue, 1, 83, 4, 0, // Skip to: 4573
/* 3466 */    MCD::OPC_Decode, 134, 5, 34, // Opcode: SETP_LT_F_NPI
/* 3470 */    MCD::OPC_FilterValue, 3, 74, 4, 0, // Skip to: 4573
/* 3475 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3478 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3504
/* 3483 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3486 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3495
/* 3491 */    MCD::OPC_Decode, 233, 4, 33, // Opcode: SETP_GT_F_NP
/* 3495 */    MCD::OPC_FilterValue, 1, 49, 4, 0, // Skip to: 4573
/* 3500 */    MCD::OPC_Decode, 231, 4, 33, // Opcode: SETP_GT_F1_NP
/* 3504 */    MCD::OPC_FilterValue, 1, 40, 4, 0, // Skip to: 4573
/* 3509 */    MCD::OPC_Decode, 234, 4, 34, // Opcode: SETP_GT_F_NPI
/* 3513 */    MCD::OPC_FilterValue, 192, 1, 25, 1, 0, // Skip to: 3800
/* 3519 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3522 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 3575
/* 3527 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3530 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3539
/* 3535 */    MCD::OPC_Decode, 180, 4, 9, // Opcode: MUL_HI_S
/* 3539 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3548
/* 3544 */    MCD::OPC_Decode, 253, 3, 9, // Opcode: FFMA_F0
/* 3548 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3557
/* 3553 */    MCD::OPC_Decode, 225, 2, 9, // Opcode: CVT_D0_S0_R3
/* 3557 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3566
/* 3562 */    MCD::OPC_Decode, 158, 3, 9, // Opcode: CVT_D2_S0_R3
/* 3566 */    MCD::OPC_FilterValue, 8, 234, 3, 0, // Skip to: 4573
/* 3571 */    MCD::OPC_Decode, 243, 3, 9, // Opcode: EX2_F32
/* 3575 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 3628
/* 3580 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3583 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3592
/* 3588 */    MCD::OPC_Decode, 172, 2, 9, // Opcode: AND
/* 3592 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3601
/* 3597 */    MCD::OPC_Decode, 244, 3, 9, // Opcode: FABS_F0
/* 3601 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3610
/* 3606 */    MCD::OPC_Decode, 235, 2, 9, // Opcode: CVT_D0_S1_R3
/* 3610 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3619
/* 3615 */    MCD::OPC_Decode, 166, 3, 9, // Opcode: CVT_D2_S1_R3
/* 3619 */    MCD::OPC_FilterValue, 8, 181, 3, 0, // Skip to: 4573
/* 3624 */    MCD::OPC_Decode, 201, 4, 9, // Opcode: RCP_U32
/* 3628 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 3663
/* 3633 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3636 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3645
/* 3641 */    MCD::OPC_Decode, 160, 5, 9, // Opcode: SHL
/* 3645 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3654
/* 3650 */    MCD::OPC_Decode, 254, 3, 9, // Opcode: FFMA_F1
/* 3654 */    MCD::OPC_FilterValue, 2, 146, 3, 0, // Skip to: 4573
/* 3659 */    MCD::OPC_Decode, 241, 2, 9, // Opcode: CVT_D0_S2_R3
/* 3663 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 3698
/* 3668 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3671 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3680
/* 3676 */    MCD::OPC_Decode, 173, 4, 9, // Opcode: MIN_U
/* 3680 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3689
/* 3685 */    MCD::OPC_Decode, 245, 3, 9, // Opcode: FABS_F1
/* 3689 */    MCD::OPC_FilterValue, 2, 111, 3, 0, // Skip to: 4573
/* 3694 */    MCD::OPC_Decode, 247, 2, 9, // Opcode: CVT_D0_S3_R3
/* 3698 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 3724
/* 3703 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3706 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3715
/* 3711 */    MCD::OPC_Decode, 128, 3, 9, // Opcode: CVT_D1_S0_R3
/* 3715 */    MCD::OPC_FilterValue, 3, 85, 3, 0, // Skip to: 4573
/* 3720 */    MCD::OPC_Decode, 174, 3, 9, // Opcode: CVT_D3_S0_R3
/* 3724 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 3768
/* 3729 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3732 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3741
/* 3737 */    MCD::OPC_Decode, 210, 2, 9, // Opcode: CLZ
/* 3741 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3750
/* 3746 */    MCD::OPC_Decode, 241, 3, 9, // Opcode: DP4_E5M2
/* 3750 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3759
/* 3755 */    MCD::OPC_Decode, 136, 3, 9, // Opcode: CVT_D1_S1_R3
/* 3759 */    MCD::OPC_FilterValue, 3, 41, 3, 0, // Skip to: 4573
/* 3764 */    MCD::OPC_Decode, 182, 3, 9, // Opcode: CVT_D3_S1_R3
/* 3768 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3784
/* 3773 */    MCD::OPC_CheckField, 27, 5, 2, 25, 3, 0, // Skip to: 4573
/* 3780 */    MCD::OPC_Decode, 144, 3, 9, // Opcode: CVT_D1_S2_R3
/* 3784 */    MCD::OPC_FilterValue, 7, 16, 3, 0, // Skip to: 4573
/* 3789 */    MCD::OPC_CheckField, 27, 5, 2, 9, 3, 0, // Skip to: 4573
/* 3796 */    MCD::OPC_Decode, 152, 3, 9, // Opcode: CVT_D1_S3_R3
/* 3800 */    MCD::OPC_FilterValue, 196, 1, 218, 0, 0, // Skip to: 4024
/* 3806 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3809 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 3844
/* 3814 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3817 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3826
/* 3822 */    MCD::OPC_Decode, 181, 4, 11, // Opcode: MUL_HI_S_P
/* 3826 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3835
/* 3831 */    MCD::OPC_Decode, 226, 2, 11, // Opcode: CVT_D0_S0_R3_P
/* 3835 */    MCD::OPC_FilterValue, 3, 221, 2, 0, // Skip to: 4573
/* 3840 */    MCD::OPC_Decode, 159, 3, 11, // Opcode: CVT_D2_S0_R3_P
/* 3844 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 3879
/* 3849 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3852 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3861
/* 3857 */    MCD::OPC_Decode, 178, 2, 11, // Opcode: AND_P
/* 3861 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3870
/* 3866 */    MCD::OPC_Decode, 236, 2, 11, // Opcode: CVT_D0_S1_R3_P
/* 3870 */    MCD::OPC_FilterValue, 3, 186, 2, 0, // Skip to: 4573
/* 3875 */    MCD::OPC_Decode, 167, 3, 11, // Opcode: CVT_D2_S1_R3_P
/* 3879 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3905
/* 3884 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3887 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3896
/* 3892 */    MCD::OPC_Decode, 163, 5, 11, // Opcode: SHL_P
/* 3896 */    MCD::OPC_FilterValue, 2, 160, 2, 0, // Skip to: 4573
/* 3901 */    MCD::OPC_Decode, 242, 2, 11, // Opcode: CVT_D0_S2_R3_P
/* 3905 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 3931
/* 3910 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3913 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3922
/* 3918 */    MCD::OPC_Decode, 174, 4, 11, // Opcode: MIN_U_P
/* 3922 */    MCD::OPC_FilterValue, 2, 134, 2, 0, // Skip to: 4573
/* 3927 */    MCD::OPC_Decode, 248, 2, 11, // Opcode: CVT_D0_S3_R3_P
/* 3931 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 3966
/* 3936 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3939 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3948
/* 3944 */    MCD::OPC_Decode, 203, 4, 11, // Opcode: SEL
/* 3948 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3957
/* 3953 */    MCD::OPC_Decode, 129, 3, 11, // Opcode: CVT_D1_S0_R3_P
/* 3957 */    MCD::OPC_FilterValue, 3, 99, 2, 0, // Skip to: 4573
/* 3962 */    MCD::OPC_Decode, 175, 3, 11, // Opcode: CVT_D3_S0_R3_P
/* 3966 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 3992
/* 3971 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3974 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3983
/* 3979 */    MCD::OPC_Decode, 137, 3, 11, // Opcode: CVT_D1_S1_R3_P
/* 3983 */    MCD::OPC_FilterValue, 3, 73, 2, 0, // Skip to: 4573
/* 3988 */    MCD::OPC_Decode, 183, 3, 11, // Opcode: CVT_D3_S1_R3_P
/* 3992 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 4008
/* 3997 */    MCD::OPC_CheckField, 30, 2, 2, 57, 2, 0, // Skip to: 4573
/* 4004 */    MCD::OPC_Decode, 145, 3, 11, // Opcode: CVT_D1_S2_R3_P
/* 4008 */    MCD::OPC_FilterValue, 7, 48, 2, 0, // Skip to: 4573
/* 4013 */    MCD::OPC_CheckField, 30, 2, 2, 41, 2, 0, // Skip to: 4573
/* 4020 */    MCD::OPC_Decode, 153, 3, 11, // Opcode: CVT_D1_S3_R3_P
/* 4024 */    MCD::OPC_FilterValue, 204, 1, 21, 0, 0, // Skip to: 4051
/* 4030 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4033 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4042
/* 4038 */    MCD::OPC_Decode, 173, 2, 13, // Opcode: ANDI
/* 4042 */    MCD::OPC_FilterValue, 2, 14, 2, 0, // Skip to: 4573
/* 4047 */    MCD::OPC_Decode, 161, 5, 14, // Opcode: SHLI
/* 4051 */    MCD::OPC_FilterValue, 208, 1, 21, 0, 0, // Skip to: 4078
/* 4057 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4060 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4069
/* 4065 */    MCD::OPC_Decode, 174, 2, 16, // Opcode: ANDI_P
/* 4069 */    MCD::OPC_FilterValue, 2, 243, 1, 0, // Skip to: 4573
/* 4074 */    MCD::OPC_Decode, 162, 5, 17, // Opcode: SHLI_P
/* 4078 */    MCD::OPC_FilterValue, 216, 1, 87, 0, 0, // Skip to: 4171
/* 4084 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4087 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 4103
/* 4092 */    MCD::OPC_CheckField, 23, 4, 0, 218, 1, 0, // Skip to: 4573
/* 4099 */    MCD::OPC_Decode, 142, 5, 19, // Opcode: SETP_NE
/* 4103 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 4119
/* 4108 */    MCD::OPC_CheckField, 23, 4, 0, 202, 1, 0, // Skip to: 4573
/* 4115 */    MCD::OPC_Decode, 252, 4, 19, // Opcode: SETP_LE_U
/* 4119 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 4145
/* 4124 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4127 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4136
/* 4132 */    MCD::OPC_Decode, 243, 4, 19, // Opcode: SETP_LE_F
/* 4136 */    MCD::OPC_FilterValue, 1, 176, 1, 0, // Skip to: 4573
/* 4141 */    MCD::OPC_Decode, 244, 4, 19, // Opcode: SETP_LE_F1
/* 4145 */    MCD::OPC_FilterValue, 3, 167, 1, 0, // Skip to: 4573
/* 4150 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4153 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4162
/* 4158 */    MCD::OPC_Decode, 215, 4, 19, // Opcode: SETP_GE_F
/* 4162 */    MCD::OPC_FilterValue, 1, 150, 1, 0, // Skip to: 4573
/* 4167 */    MCD::OPC_Decode, 216, 4, 19, // Opcode: SETP_GE_F1
/* 4171 */    MCD::OPC_FilterValue, 220, 1, 39, 0, 0, // Skip to: 4216
/* 4177 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4180 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4189
/* 4185 */    MCD::OPC_Decode, 149, 5, 20, // Opcode: SETP_NE_I
/* 4189 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4198
/* 4194 */    MCD::OPC_Decode, 253, 4, 20, // Opcode: SETP_LE_U_I
/* 4198 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 4207
/* 4203 */    MCD::OPC_Decode, 246, 4, 20, // Opcode: SETP_LE_F_I
/* 4207 */    MCD::OPC_FilterValue, 3, 105, 1, 0, // Skip to: 4573
/* 4212 */    MCD::OPC_Decode, 218, 4, 20, // Opcode: SETP_GE_F_I
/* 4216 */    MCD::OPC_FilterValue, 224, 1, 66, 0, 0, // Skip to: 4288
/* 4222 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4225 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4234
/* 4230 */    MCD::OPC_Decode, 188, 5, 13, // Opcode: ST_SHARED
/* 4234 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4243
/* 4239 */    MCD::OPC_Decode, 189, 5, 21, // Opcode: ST_SHARED_IDX
/* 4243 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 4252
/* 4248 */    MCD::OPC_Decode, 187, 5, 22, // Opcode: ST_PRED_S
/* 4252 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 4261
/* 4257 */    MCD::OPC_Decode, 186, 5, 38, // Opcode: ST_PRED_LOCAL
/* 4261 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 4270
/* 4266 */    MCD::OPC_Decode, 197, 5, 21, // Opcode: SZ_GLOBAL_LD_S16
/* 4270 */    MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 4279
/* 4275 */    MCD::OPC_Decode, 210, 5, 21, // Opcode: SZ_SHARED_LD_S8
/* 4279 */    MCD::OPC_FilterValue, 7, 33, 1, 0, // Skip to: 4573
/* 4284 */    MCD::OPC_Decode, 213, 5, 21, // Opcode: SZ_SHARED_ST_16
/* 4288 */    MCD::OPC_FilterValue, 228, 1, 39, 0, 0, // Skip to: 4333
/* 4294 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4297 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4306
/* 4302 */    MCD::OPC_Decode, 188, 2, 25, // Opcode: ATOM_MAX_S_G
/* 4306 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4315
/* 4311 */    MCD::OPC_Decode, 198, 2, 25, // Opcode: ATOM_XOR_G
/* 4315 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 4324
/* 4320 */    MCD::OPC_Decode, 189, 2, 25, // Opcode: ATOM_MAX_S_S
/* 4324 */    MCD::OPC_FilterValue, 5, 244, 0, 0, // Skip to: 4573
/* 4329 */    MCD::OPC_Decode, 199, 2, 25, // Opcode: ATOM_XOR_S
/* 4333 */    MCD::OPC_FilterValue, 232, 1, 18, 0, 0, // Skip to: 4357
/* 4339 */    MCD::OPC_CheckField, 27, 5, 0, 227, 0, 0, // Skip to: 4573
/* 4346 */    MCD::OPC_CheckField, 8, 3, 0, 220, 0, 0, // Skip to: 4573
/* 4353 */    MCD::OPC_Decode, 201, 2, 40, // Opcode: BAR_INIT
/* 4357 */    MCD::OPC_FilterValue, 240, 1, 49, 0, 0, // Skip to: 4412
/* 4363 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4366 */    MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 4389
/* 4371 */    MCD::OPC_CheckField, 30, 2, 0, 195, 0, 0, // Skip to: 4573
/* 4378 */    MCD::OPC_CheckField, 24, 3, 0, 188, 0, 0, // Skip to: 4573
/* 4385 */    MCD::OPC_Decode, 152, 5, 28, // Opcode: SHFL_BFLY
/* 4389 */    MCD::OPC_FilterValue, 4, 179, 0, 0, // Skip to: 4573
/* 4394 */    MCD::OPC_CheckField, 30, 2, 0, 172, 0, 0, // Skip to: 4573
/* 4401 */    MCD::OPC_CheckField, 23, 4, 0, 165, 0, 0, // Skip to: 4573
/* 4408 */    MCD::OPC_Decode, 153, 5, 31, // Opcode: SHFL_BFLY_R
/* 4412 */    MCD::OPC_FilterValue, 252, 1, 155, 0, 0, // Skip to: 4573
/* 4418 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4421 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 4454
/* 4426 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4429 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 4445
/* 4434 */    MCD::OPC_CheckField, 23, 4, 0, 132, 0, 0, // Skip to: 4573
/* 4441 */    MCD::OPC_Decode, 150, 5, 33, // Opcode: SETP_NE_NP
/* 4445 */    MCD::OPC_FilterValue, 1, 123, 0, 0, // Skip to: 4573
/* 4450 */    MCD::OPC_Decode, 151, 5, 34, // Opcode: SETP_NE_NPI
/* 4454 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 4487
/* 4459 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4462 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 4478
/* 4467 */    MCD::OPC_CheckField, 23, 4, 0, 99, 0, 0, // Skip to: 4573
/* 4474 */    MCD::OPC_Decode, 254, 4, 33, // Opcode: SETP_LE_U_NP
/* 4478 */    MCD::OPC_FilterValue, 1, 90, 0, 0, // Skip to: 4573
/* 4483 */    MCD::OPC_Decode, 255, 4, 34, // Opcode: SETP_LE_U_NPI
/* 4487 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 4530
/* 4492 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4495 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 4521
/* 4500 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4503 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4512
/* 4508 */    MCD::OPC_Decode, 247, 4, 33, // Opcode: SETP_LE_F_NP
/* 4512 */    MCD::OPC_FilterValue, 1, 56, 0, 0, // Skip to: 4573
/* 4517 */    MCD::OPC_Decode, 245, 4, 33, // Opcode: SETP_LE_F1_NP
/* 4521 */    MCD::OPC_FilterValue, 1, 47, 0, 0, // Skip to: 4573
/* 4526 */    MCD::OPC_Decode, 248, 4, 34, // Opcode: SETP_LE_F_NPI
/* 4530 */    MCD::OPC_FilterValue, 3, 38, 0, 0, // Skip to: 4573
/* 4535 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4538 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 4564
/* 4543 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4546 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4555
/* 4551 */    MCD::OPC_Decode, 219, 4, 33, // Opcode: SETP_GE_F_NP
/* 4555 */    MCD::OPC_FilterValue, 1, 13, 0, 0, // Skip to: 4573
/* 4560 */    MCD::OPC_Decode, 217, 4, 33, // Opcode: SETP_GE_F1_NP
/* 4564 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4573
/* 4569 */    MCD::OPC_Decode, 220, 4, 34, // Opcode: SETP_GE_F_NPI
/* 4573 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable48[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 3 */       MCD::OPC_FilterValue, 7, 18, 0, 0, // Skip to: 26
/* 8 */       MCD::OPC_CheckField, 30, 18, 8, 91, 0, 0, // Skip to: 106
/* 15 */      MCD::OPC_CheckField, 8, 3, 0, 84, 0, 0, // Skip to: 106
/* 22 */      MCD::OPC_Decode, 200, 4, 11, // Opcode: RCP_F32_P
/* 26 */      MCD::OPC_FilterValue, 15, 11, 0, 0, // Skip to: 42
/* 31 */      MCD::OPC_CheckField, 8, 3, 0, 68, 0, 0, // Skip to: 106
/* 38 */      MCD::OPC_Decode, 165, 2, 41, // Opcode: ADDI48
/* 42 */      MCD::OPC_FilterValue, 39, 11, 0, 0, // Skip to: 58
/* 47 */      MCD::OPC_CheckField, 8, 3, 4, 52, 0, 0, // Skip to: 106
/* 54 */      MCD::OPC_Decode, 207, 2, 42, // Opcode: CAS_G
/* 58 */      MCD::OPC_FilterValue, 47, 11, 0, 0, // Skip to: 74
/* 63 */      MCD::OPC_CheckField, 8, 3, 0, 36, 0, 0, // Skip to: 106
/* 70 */      MCD::OPC_Decode, 176, 4, 43, // Opcode: MOVI48
/* 74 */      MCD::OPC_FilterValue, 103, 11, 0, 0, // Skip to: 90
/* 79 */      MCD::OPC_CheckField, 8, 3, 4, 20, 0, 0, // Skip to: 106
/* 86 */      MCD::OPC_Decode, 208, 2, 42, // Opcode: CAS_S
/* 90 */      MCD::OPC_FilterValue, 123, 11, 0, 0, // Skip to: 106
/* 95 */      MCD::OPC_CheckField, 10, 6, 0, 4, 0, 0, // Skip to: 106
/* 102 */     MCD::OPC_Decode, 195, 4, 44, // Opcode: PMOV_IMM
/* 106 */     MCD::OPC_Fail,
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
    tmp = fieldFromInstruction(insn, 15, 17);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 25:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 28, 4);
    if (!Check(S, decodeSImm<4>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 26:
    tmp = fieldFromInstruction(insn, 11, 21);
    if (!Check(S, decodeSImm<21>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 17, 2);
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
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 32:
    tmp = fieldFromInstruction(insn, 8, 16);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 24, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 33:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 34:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 8);
    if (!Check(S, decodeSImm<8>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 35:
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = 0x0;
    insertBits(tmp, fieldFromInstruction(insn, 11, 16), 0, 16);
    insertBits(tmp, fieldFromInstruction(insn, 30, 2), 16, 2);
    if (!Check(S, decodeSImm<18>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 36:
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 37:
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
  case 38:
    tmp = fieldFromInstruction(insn, 11, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 17);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 17);
    if (!Check(S, decodeSImm<17>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 11, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 17, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 41:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 29);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 42:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 30, 2);
    if (!Check(S, DecodePRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 27, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 32, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 36, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 37, 11);
    if (!Check(S, decodeSImm<11>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 23, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 43:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 33);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 44:
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
