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
/* 8 */       MCD::OPC_Decode, 249, 3, 0, // Opcode: FFMA_ACC_F0
/* 12 */      MCD::OPC_FilterValue, 2, 136, 0, 0, // Skip to: 153
/* 17 */      MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 20 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 29
/* 25 */      MCD::OPC_Decode, 196, 3, 1, // Opcode: C_ADD
/* 29 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 38
/* 34 */      MCD::OPC_Decode, 220, 3, 1, // Opcode: C_OR
/* 38 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 47
/* 43 */      MCD::OPC_Decode, 226, 3, 1, // Opcode: C_SHR
/* 47 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 56
/* 52 */      MCD::OPC_Decode, 212, 3, 1, // Opcode: C_MAX_S
/* 56 */      MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 65
/* 61 */      MCD::OPC_Decode, 219, 3, 2, // Opcode: C_NOT
/* 65 */      MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 210, 3, 1, // Opcode: C_FMUL
/* 74 */      MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 83
/* 79 */      MCD::OPC_Decode, 211, 3, 2, // Opcode: C_LD_GLOBAL
/* 83 */      MCD::OPC_FilterValue, 7, 4, 0, 0, // Skip to: 92
/* 88 */      MCD::OPC_Decode, 165, 5, 3, // Opcode: SRD
/* 92 */      MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 101
/* 97 */      MCD::OPC_Decode, 197, 3, 4, // Opcode: C_ADDI
/* 101 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 110
/* 106 */     MCD::OPC_Decode, 234, 3, 4, // Opcode: C_XORI
/* 110 */     MCD::OPC_FilterValue, 12, 11, 0, 0, // Skip to: 126
/* 115 */     MCD::OPC_CheckField, 14, 2, 0, 105, 1, 0, // Skip to: 483
/* 122 */     MCD::OPC_Decode, 204, 3, 5, // Opcode: C_CHWIDTH
/* 126 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 135
/* 131 */     MCD::OPC_Decode, 202, 3, 6, // Opcode: C_BAR_WAIT
/* 135 */     MCD::OPC_FilterValue, 14, 4, 0, 0, // Skip to: 144
/* 140 */     MCD::OPC_Decode, 207, 3, 6, // Opcode: C_FENCE
/* 144 */     MCD::OPC_FilterValue, 15, 78, 1, 0, // Skip to: 483
/* 149 */     MCD::OPC_Decode, 191, 4, 7, // Opcode: PAND
/* 153 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 162
/* 158 */     MCD::OPC_Decode, 250, 3, 0, // Opcode: FFMA_ACC_F1
/* 162 */     MCD::OPC_FilterValue, 6, 102, 0, 0, // Skip to: 269
/* 167 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 170 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 179
/* 175 */     MCD::OPC_Decode, 231, 3, 1, // Opcode: C_SUB
/* 179 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 188
/* 184 */     MCD::OPC_Decode, 233, 3, 1, // Opcode: C_XOR
/* 188 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 197
/* 193 */     MCD::OPC_Decode, 228, 3, 1, // Opcode: C_SRA
/* 197 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 206
/* 202 */     MCD::OPC_Decode, 213, 3, 1, // Opcode: C_MAX_U
/* 206 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 215
/* 211 */     MCD::OPC_Decode, 195, 3, 2, // Opcode: C_ABS
/* 215 */     MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 224
/* 220 */     MCD::OPC_Decode, 230, 3, 2, // Opcode: C_ST_GLOBAL
/* 224 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 233
/* 229 */     MCD::OPC_Decode, 232, 3, 4, // Opcode: C_SUBI
/* 233 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 242
/* 238 */     MCD::OPC_Decode, 225, 3, 4, // Opcode: C_SHLI
/* 242 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 251
/* 247 */     MCD::OPC_Decode, 203, 3, 8, // Opcode: C_BRA
/* 251 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 260
/* 256 */     MCD::OPC_Decode, 223, 3, 6, // Opcode: C_RET
/* 260 */     MCD::OPC_FilterValue, 15, 218, 0, 0, // Skip to: 483
/* 265 */     MCD::OPC_Decode, 195, 4, 7, // Opcode: POR
/* 269 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 278
/* 274 */     MCD::OPC_Decode, 237, 3, 0, // Opcode: DP4_ACC
/* 278 */     MCD::OPC_FilterValue, 10, 93, 0, 0, // Skip to: 376
/* 283 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 286 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 295
/* 291 */     MCD::OPC_Decode, 217, 3, 1, // Opcode: C_MUL_LO
/* 295 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 304
/* 300 */     MCD::OPC_Decode, 200, 3, 1, // Opcode: C_ANDN
/* 304 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 313
/* 309 */     MCD::OPC_Decode, 214, 3, 1, // Opcode: C_MIN_S
/* 313 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 322
/* 318 */     MCD::OPC_Decode, 216, 3, 2, // Opcode: C_MOV
/* 322 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 331
/* 327 */     MCD::OPC_Decode, 206, 3, 1, // Opcode: C_FADD
/* 331 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 340
/* 336 */     MCD::OPC_Decode, 209, 3, 1, // Opcode: C_FMIN
/* 340 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 349
/* 345 */     MCD::OPC_Decode, 199, 3, 4, // Opcode: C_ANDI
/* 349 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 358
/* 354 */     MCD::OPC_Decode, 227, 3, 4, // Opcode: C_SHRI
/* 358 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 367
/* 363 */     MCD::OPC_Decode, 205, 3, 6, // Opcode: C_EXIT
/* 367 */     MCD::OPC_FilterValue, 15, 111, 0, 0, // Skip to: 483
/* 372 */     MCD::OPC_Decode, 196, 4, 7, // Opcode: PXOR
/* 376 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 385
/* 381 */     MCD::OPC_Decode, 162, 4, 0, // Opcode: MAD_ACC
/* 385 */     MCD::OPC_FilterValue, 14, 93, 0, 0, // Skip to: 483
/* 390 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 393 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 402
/* 398 */     MCD::OPC_Decode, 198, 3, 1, // Opcode: C_AND
/* 402 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 411
/* 407 */     MCD::OPC_Decode, 224, 3, 1, // Opcode: C_SHL
/* 411 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 420
/* 416 */     MCD::OPC_Decode, 215, 3, 1, // Opcode: C_MIN_U
/* 420 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 429
/* 425 */     MCD::OPC_Decode, 218, 3, 2, // Opcode: C_NEG
/* 429 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 438
/* 434 */     MCD::OPC_Decode, 208, 3, 1, // Opcode: C_FMAX
/* 438 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 447
/* 443 */     MCD::OPC_Decode, 221, 3, 4, // Opcode: C_ORI
/* 447 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 456
/* 452 */     MCD::OPC_Decode, 229, 3, 4, // Opcode: C_SRAI
/* 456 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 465
/* 461 */     MCD::OPC_Decode, 201, 3, 6, // Opcode: C_BAR_ARRIVE
/* 465 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 474
/* 470 */     MCD::OPC_Decode, 222, 3, 6, // Opcode: C_RECONV
/* 474 */     MCD::OPC_FilterValue, 15, 4, 0, 0, // Skip to: 483
/* 479 */     MCD::OPC_Decode, 192, 4, 7, // Opcode: PMOV
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
/* 24 */      MCD::OPC_Decode, 161, 2, 9, // Opcode: ADD
/* 28 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 37
/* 33 */      MCD::OPC_Decode, 244, 3, 9, // Opcode: FADD
/* 37 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 46
/* 42 */      MCD::OPC_Decode, 210, 2, 9, // Opcode: CVT_D0_S0_R0
/* 46 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 55
/* 51 */      MCD::OPC_Decode, 152, 3, 9, // Opcode: CVT_D2_S0_R0
/* 55 */      MCD::OPC_FilterValue, 8, 207, 16, 0, // Skip to: 4363
/* 60 */      MCD::OPC_Decode, 197, 4, 9, // Opcode: RCP_F32
/* 64 */      MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 117
/* 69 */      MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 72 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 81
/* 77 */      MCD::OPC_Decode, 180, 4, 9, // Opcode: MUL_HI_U
/* 81 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 255, 3, 9, // Opcode: FMIN
/* 90 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 99
/* 95 */      MCD::OPC_Decode, 225, 2, 9, // Opcode: CVT_D0_S1_R0
/* 99 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 108
/* 104 */     MCD::OPC_Decode, 158, 3, 9, // Opcode: CVT_D2_S1_R0
/* 108 */     MCD::OPC_FilterValue, 8, 154, 16, 0, // Skip to: 4363
/* 113 */     MCD::OPC_Decode, 159, 4, 9, // Opcode: LG2_F32
/* 117 */     MCD::OPC_FilterValue, 2, 39, 0, 0, // Skip to: 161
/* 122 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 125 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 134
/* 130 */     MCD::OPC_Decode, 184, 4, 9, // Opcode: OR
/* 134 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 143
/* 139 */     MCD::OPC_Decode, 245, 3, 9, // Opcode: FADD_F1
/* 143 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 152
/* 148 */     MCD::OPC_Decode, 186, 3, 9, // Opcode: CVT_F32_S32
/* 152 */     MCD::OPC_FilterValue, 3, 110, 16, 0, // Skip to: 4363
/* 157 */     MCD::OPC_Decode, 192, 3, 10, // Opcode: CVT_SEXT
/* 161 */     MCD::OPC_FilterValue, 3, 39, 0, 0, // Skip to: 205
/* 166 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 169 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 178
/* 174 */     MCD::OPC_Decode, 155, 5, 9, // Opcode: SHR
/* 178 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 187
/* 183 */     MCD::OPC_Decode, 128, 4, 9, // Opcode: FMIN_F1
/* 187 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 196
/* 192 */     MCD::OPC_Decode, 188, 3, 9, // Opcode: CVT_F32_U32
/* 196 */     MCD::OPC_FilterValue, 3, 66, 16, 0, // Skip to: 4363
/* 201 */     MCD::OPC_Decode, 166, 3, 9, // Opcode: CVT_D2_S3_R0
/* 205 */     MCD::OPC_FilterValue, 4, 39, 0, 0, // Skip to: 249
/* 210 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 213 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 222
/* 218 */     MCD::OPC_Decode, 163, 4, 9, // Opcode: MAX_S
/* 222 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 231
/* 227 */     MCD::OPC_Decode, 240, 3, 9, // Opcode: DP4_SS
/* 231 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 240
/* 236 */     MCD::OPC_Decode, 247, 2, 9, // Opcode: CVT_D1_S0_R0
/* 240 */     MCD::OPC_FilterValue, 3, 22, 16, 0, // Skip to: 4363
/* 245 */     MCD::OPC_Decode, 168, 3, 9, // Opcode: CVT_D3_S0_R0
/* 249 */     MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 293
/* 254 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 257 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 266
/* 262 */     MCD::OPC_Decode, 160, 2, 9, // Opcode: ABS
/* 266 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 275
/* 271 */     MCD::OPC_Decode, 235, 3, 9, // Opcode: DP2_BF16
/* 275 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 284
/* 280 */     MCD::OPC_Decode, 128, 3, 9, // Opcode: CVT_D1_S1_R0
/* 284 */     MCD::OPC_FilterValue, 3, 234, 15, 0, // Skip to: 4363
/* 289 */     MCD::OPC_Decode, 174, 3, 9, // Opcode: CVT_D3_S1_R0
/* 293 */     MCD::OPC_FilterValue, 6, 30, 0, 0, // Skip to: 328
/* 298 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 301 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 310
/* 306 */     MCD::OPC_Decode, 203, 2, 9, // Opcode: BREV
/* 310 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 319
/* 315 */     MCD::OPC_Decode, 136, 3, 9, // Opcode: CVT_D1_S2_R0
/* 319 */     MCD::OPC_FilterValue, 3, 199, 15, 0, // Skip to: 4363
/* 324 */     MCD::OPC_Decode, 182, 3, 9, // Opcode: CVT_D3_S2_R0
/* 328 */     MCD::OPC_FilterValue, 7, 190, 15, 0, // Skip to: 4363
/* 333 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 336 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 345
/* 341 */     MCD::OPC_Decode, 144, 3, 9, // Opcode: CVT_D1_S3_R0
/* 345 */     MCD::OPC_FilterValue, 3, 173, 15, 0, // Skip to: 4363
/* 350 */     MCD::OPC_Decode, 184, 3, 9, // Opcode: CVT_D3_S3_R0
/* 354 */     MCD::OPC_FilterValue, 4, 0, 1, 0, // Skip to: 615
/* 359 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 362 */     MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 406
/* 367 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 370 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 379
/* 375 */     MCD::OPC_Decode, 167, 2, 11, // Opcode: ADD_P
/* 379 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 388
/* 384 */     MCD::OPC_Decode, 247, 3, 11, // Opcode: FADD_P
/* 388 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 397
/* 393 */     MCD::OPC_Decode, 211, 2, 11, // Opcode: CVT_D0_S0_R0_P
/* 397 */     MCD::OPC_FilterValue, 3, 121, 15, 0, // Skip to: 4363
/* 402 */     MCD::OPC_Decode, 153, 3, 11, // Opcode: CVT_D2_S0_R0_P
/* 406 */     MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 441
/* 411 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 414 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 423
/* 419 */     MCD::OPC_Decode, 181, 4, 11, // Opcode: MUL_HI_U_P
/* 423 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 432
/* 428 */     MCD::OPC_Decode, 226, 2, 11, // Opcode: CVT_D0_S1_R0_P
/* 432 */     MCD::OPC_FilterValue, 3, 86, 15, 0, // Skip to: 4363
/* 437 */     MCD::OPC_Decode, 159, 3, 11, // Opcode: CVT_D2_S1_R0_P
/* 441 */     MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 467
/* 446 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 449 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 458
/* 454 */     MCD::OPC_Decode, 187, 4, 11, // Opcode: OR_P
/* 458 */     MCD::OPC_FilterValue, 2, 60, 15, 0, // Skip to: 4363
/* 463 */     MCD::OPC_Decode, 187, 3, 11, // Opcode: CVT_F32_S32_P
/* 467 */     MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 502
/* 472 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 475 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 484
/* 480 */     MCD::OPC_Decode, 158, 5, 11, // Opcode: SHR_P
/* 484 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 493
/* 489 */     MCD::OPC_Decode, 189, 3, 11, // Opcode: CVT_F32_U32_P
/* 493 */     MCD::OPC_FilterValue, 3, 25, 15, 0, // Skip to: 4363
/* 498 */     MCD::OPC_Decode, 167, 3, 11, // Opcode: CVT_D2_S3_R0_P
/* 502 */     MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 537
/* 507 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 510 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 519
/* 515 */     MCD::OPC_Decode, 164, 4, 11, // Opcode: MAX_S_P
/* 519 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 528
/* 524 */     MCD::OPC_Decode, 248, 2, 11, // Opcode: CVT_D1_S0_R0_P
/* 528 */     MCD::OPC_FilterValue, 3, 246, 14, 0, // Skip to: 4363
/* 533 */     MCD::OPC_Decode, 169, 3, 11, // Opcode: CVT_D3_S0_R0_P
/* 537 */     MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 563
/* 542 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 545 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 554
/* 550 */     MCD::OPC_Decode, 129, 3, 11, // Opcode: CVT_D1_S1_R0_P
/* 554 */     MCD::OPC_FilterValue, 3, 220, 14, 0, // Skip to: 4363
/* 559 */     MCD::OPC_Decode, 175, 3, 11, // Opcode: CVT_D3_S1_R0_P
/* 563 */     MCD::OPC_FilterValue, 6, 21, 0, 0, // Skip to: 589
/* 568 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 571 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 580
/* 576 */     MCD::OPC_Decode, 137, 3, 11, // Opcode: CVT_D1_S2_R0_P
/* 580 */     MCD::OPC_FilterValue, 3, 194, 14, 0, // Skip to: 4363
/* 585 */     MCD::OPC_Decode, 183, 3, 11, // Opcode: CVT_D3_S2_R0_P
/* 589 */     MCD::OPC_FilterValue, 7, 185, 14, 0, // Skip to: 4363
/* 594 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 597 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 606
/* 602 */     MCD::OPC_Decode, 145, 3, 11, // Opcode: CVT_D1_S3_R0_P
/* 606 */     MCD::OPC_FilterValue, 3, 168, 14, 0, // Skip to: 4363
/* 611 */     MCD::OPC_Decode, 185, 3, 11, // Opcode: CVT_D3_S3_R0_P
/* 615 */     MCD::OPC_FilterValue, 8, 11, 0, 0, // Skip to: 631
/* 620 */     MCD::OPC_CheckField, 8, 3, 0, 152, 14, 0, // Skip to: 4363
/* 627 */     MCD::OPC_Decode, 168, 2, 12, // Opcode: ADD_PP
/* 631 */     MCD::OPC_FilterValue, 12, 39, 0, 0, // Skip to: 675
/* 636 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 639 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 648
/* 644 */     MCD::OPC_Decode, 162, 2, 13, // Opcode: ADDI
/* 648 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 657
/* 653 */     MCD::OPC_Decode, 185, 4, 13, // Opcode: ORI
/* 657 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 666
/* 662 */     MCD::OPC_Decode, 156, 5, 14, // Opcode: SHRI
/* 666 */     MCD::OPC_FilterValue, 5, 108, 14, 0, // Skip to: 4363
/* 671 */     MCD::OPC_Decode, 189, 4, 15, // Opcode: PACKI
/* 675 */     MCD::OPC_FilterValue, 16, 30, 0, 0, // Skip to: 710
/* 680 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 683 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 692
/* 688 */     MCD::OPC_Decode, 164, 2, 16, // Opcode: ADDI_P
/* 692 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 701
/* 697 */     MCD::OPC_Decode, 186, 4, 16, // Opcode: ORI_P
/* 701 */     MCD::OPC_FilterValue, 3, 73, 14, 0, // Skip to: 4363
/* 706 */     MCD::OPC_Decode, 157, 5, 17, // Opcode: SHRI_P
/* 710 */     MCD::OPC_FilterValue, 20, 11, 0, 0, // Skip to: 726
/* 715 */     MCD::OPC_CheckField, 8, 3, 0, 57, 14, 0, // Skip to: 4363
/* 722 */     MCD::OPC_Decode, 165, 2, 18, // Opcode: ADDI_PP
/* 726 */     MCD::OPC_FilterValue, 24, 77, 0, 0, // Skip to: 808
/* 731 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 734 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 750
/* 739 */     MCD::OPC_CheckField, 23, 4, 0, 33, 14, 0, // Skip to: 4363
/* 746 */     MCD::OPC_Decode, 254, 4, 19, // Opcode: SETP_LT
/* 750 */     MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 766
/* 755 */     MCD::OPC_CheckField, 23, 4, 0, 17, 14, 0, // Skip to: 4363
/* 762 */     MCD::OPC_Decode, 226, 4, 19, // Opcode: SETP_GT
/* 766 */     MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 782
/* 771 */     MCD::OPC_CheckField, 23, 4, 0, 1, 14, 0, // Skip to: 4363
/* 778 */     MCD::OPC_Decode, 236, 4, 19, // Opcode: SETP_GT_U
/* 782 */     MCD::OPC_FilterValue, 3, 248, 13, 0, // Skip to: 4363
/* 787 */     MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 790 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 799
/* 795 */     MCD::OPC_Decode, 203, 4, 19, // Opcode: SETP_EQ_F
/* 799 */     MCD::OPC_FilterValue, 1, 231, 13, 0, // Skip to: 4363
/* 804 */     MCD::OPC_Decode, 204, 4, 19, // Opcode: SETP_EQ_F1
/* 808 */     MCD::OPC_FilterValue, 28, 39, 0, 0, // Skip to: 852
/* 813 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 816 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 825
/* 821 */     MCD::OPC_Decode, 133, 5, 20, // Opcode: SETP_LT_I
/* 825 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 834
/* 830 */     MCD::OPC_Decode, 233, 4, 20, // Opcode: SETP_GT_I
/* 834 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 843
/* 839 */     MCD::OPC_Decode, 237, 4, 20, // Opcode: SETP_GT_U_I
/* 843 */     MCD::OPC_FilterValue, 3, 187, 13, 0, // Skip to: 4363
/* 848 */     MCD::OPC_Decode, 206, 4, 20, // Opcode: SETP_EQ_F_I
/* 852 */     MCD::OPC_FilterValue, 32, 75, 0, 0, // Skip to: 932
/* 857 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 860 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 869
/* 865 */     MCD::OPC_Decode, 141, 4, 13, // Opcode: LD_GLOBAL
/* 869 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 878
/* 874 */     MCD::OPC_Decode, 142, 4, 21, // Opcode: LD_GLOBAL_IDX
/* 878 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 887
/* 883 */     MCD::OPC_Decode, 152, 4, 22, // Opcode: LD_PRED_G
/* 887 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 896
/* 892 */     MCD::OPC_Decode, 146, 4, 23, // Opcode: LD_GLOBAL_SLOT
/* 896 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 905
/* 901 */     MCD::OPC_Decode, 151, 4, 24, // Opcode: LD_LOCAL
/* 905 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 914
/* 910 */     MCD::OPC_Decode, 194, 5, 21, // Opcode: SZ_GLOBAL_LD_U8
/* 914 */     MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 923
/* 919 */     MCD::OPC_Decode, 198, 5, 21, // Opcode: SZ_GLOBAL_ST_8
/* 923 */     MCD::OPC_FilterValue, 7, 107, 13, 0, // Skip to: 4363
/* 928 */     MCD::OPC_Decode, 202, 5, 21, // Opcode: SZ_SHARED_LD_U16
/* 932 */     MCD::OPC_FilterValue, 36, 57, 0, 0, // Skip to: 994
/* 937 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 940 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 949
/* 945 */     MCD::OPC_Decode, 180, 2, 25, // Opcode: ATOM_ADD_G
/* 949 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 958
/* 954 */     MCD::OPC_Decode, 188, 2, 25, // Opcode: ATOM_MAX_U_G
/* 958 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 967
/* 963 */     MCD::OPC_Decode, 184, 2, 25, // Opcode: ATOM_EXCH_G
/* 967 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 976
/* 972 */     MCD::OPC_Decode, 181, 2, 25, // Opcode: ATOM_ADD_S
/* 976 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 985
/* 981 */     MCD::OPC_Decode, 189, 2, 25, // Opcode: ATOM_MAX_U_S
/* 985 */     MCD::OPC_FilterValue, 6, 45, 13, 0, // Skip to: 4363
/* 990 */     MCD::OPC_Decode, 185, 2, 25, // Opcode: ATOM_EXCH_S
/* 994 */     MCD::OPC_FilterValue, 40, 35, 0, 0, // Skip to: 1034
/* 999 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1002 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1011
/* 1007 */    MCD::OPC_Decode, 201, 2, 26, // Opcode: BRA
/* 1011 */    MCD::OPC_FilterValue, 1, 19, 13, 0, // Skip to: 4363
/* 1016 */    MCD::OPC_CheckField, 30, 2, 0, 12, 13, 0, // Skip to: 4363
/* 1023 */    MCD::OPC_CheckField, 19, 8, 0, 5, 13, 0, // Skip to: 4363
/* 1030 */    MCD::OPC_Decode, 200, 2, 27, // Opcode: BAR_WAIT_PHASE
/* 1034 */    MCD::OPC_FilterValue, 44, 11, 0, 0, // Skip to: 1050
/* 1039 */    MCD::OPC_CheckField, 8, 3, 0, 245, 12, 0, // Skip to: 4363
/* 1046 */    MCD::OPC_Decode, 173, 4, 24, // Opcode: MOVI
/* 1050 */    MCD::OPC_FilterValue, 48, 79, 0, 0, // Skip to: 1134
/* 1055 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1058 */    MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 1081
/* 1063 */    MCD::OPC_CheckField, 30, 2, 0, 221, 12, 0, // Skip to: 4363
/* 1070 */    MCD::OPC_CheckField, 24, 3, 0, 214, 12, 0, // Skip to: 4363
/* 1077 */    MCD::OPC_Decode, 150, 5, 28, // Opcode: SHFL_IDX
/* 1081 */    MCD::OPC_FilterValue, 1, 18, 0, 0, // Skip to: 1104
/* 1086 */    MCD::OPC_CheckField, 22, 5, 0, 198, 12, 0, // Skip to: 4363
/* 1093 */    MCD::OPC_CheckField, 11, 8, 0, 191, 12, 0, // Skip to: 4363
/* 1100 */    MCD::OPC_Decode, 208, 5, 29, // Opcode: VOTE_ANY
/* 1104 */    MCD::OPC_FilterValue, 2, 182, 12, 0, // Skip to: 4363
/* 1109 */    MCD::OPC_CheckField, 30, 2, 0, 175, 12, 0, // Skip to: 4363
/* 1116 */    MCD::OPC_CheckField, 22, 5, 0, 168, 12, 0, // Skip to: 4363
/* 1123 */    MCD::OPC_CheckField, 15, 4, 0, 161, 12, 0, // Skip to: 4363
/* 1130 */    MCD::OPC_Decode, 198, 2, 30, // Opcode: BALLOT
/* 1134 */    MCD::OPC_FilterValue, 52, 11, 0, 0, // Skip to: 1150
/* 1139 */    MCD::OPC_CheckField, 8, 3, 0, 145, 12, 0, // Skip to: 4363
/* 1146 */    MCD::OPC_Decode, 145, 4, 16, // Opcode: LD_GLOBAL_P
/* 1150 */    MCD::OPC_FilterValue, 56, 11, 0, 0, // Skip to: 1166
/* 1155 */    MCD::OPC_CheckField, 26, 6, 0, 129, 12, 0, // Skip to: 4363
/* 1162 */    MCD::OPC_Decode, 207, 2, 31, // Opcode: CHWIDTH_MULTI
/* 1166 */    MCD::OPC_FilterValue, 60, 145, 0, 0, // Skip to: 1316
/* 1171 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1174 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 1207
/* 1179 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1182 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1198
/* 1187 */    MCD::OPC_CheckField, 23, 4, 0, 97, 12, 0, // Skip to: 4363
/* 1194 */    MCD::OPC_Decode, 134, 5, 32, // Opcode: SETP_LT_NP
/* 1198 */    MCD::OPC_FilterValue, 1, 88, 12, 0, // Skip to: 4363
/* 1203 */    MCD::OPC_Decode, 135, 5, 33, // Opcode: SETP_LT_NPI
/* 1207 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 1240
/* 1212 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1215 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1231
/* 1220 */    MCD::OPC_CheckField, 23, 4, 0, 64, 12, 0, // Skip to: 4363
/* 1227 */    MCD::OPC_Decode, 234, 4, 32, // Opcode: SETP_GT_NP
/* 1231 */    MCD::OPC_FilterValue, 1, 55, 12, 0, // Skip to: 4363
/* 1236 */    MCD::OPC_Decode, 235, 4, 33, // Opcode: SETP_GT_NPI
/* 1240 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 1273
/* 1245 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1248 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1264
/* 1253 */    MCD::OPC_CheckField, 23, 4, 0, 31, 12, 0, // Skip to: 4363
/* 1260 */    MCD::OPC_Decode, 238, 4, 32, // Opcode: SETP_GT_U_NP
/* 1264 */    MCD::OPC_FilterValue, 1, 22, 12, 0, // Skip to: 4363
/* 1269 */    MCD::OPC_Decode, 239, 4, 33, // Opcode: SETP_GT_U_NPI
/* 1273 */    MCD::OPC_FilterValue, 3, 13, 12, 0, // Skip to: 4363
/* 1278 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1281 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 1307
/* 1286 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 1289 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1298
/* 1294 */    MCD::OPC_Decode, 207, 4, 32, // Opcode: SETP_EQ_F_NP
/* 1298 */    MCD::OPC_FilterValue, 1, 244, 11, 0, // Skip to: 4363
/* 1303 */    MCD::OPC_Decode, 205, 4, 32, // Opcode: SETP_EQ_F1_NP
/* 1307 */    MCD::OPC_FilterValue, 1, 235, 11, 0, // Skip to: 4363
/* 1312 */    MCD::OPC_Decode, 208, 4, 33, // Opcode: SETP_EQ_F_NPI
/* 1316 */    MCD::OPC_FilterValue, 64, 34, 1, 0, // Skip to: 1611
/* 1321 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1324 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 1377
/* 1329 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1332 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1341
/* 1337 */    MCD::OPC_Decode, 183, 5, 9, // Opcode: SUB
/* 1341 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1350
/* 1346 */    MCD::OPC_Decode, 136, 4, 9, // Opcode: FSUB
/* 1350 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1359
/* 1355 */    MCD::OPC_Decode, 219, 2, 9, // Opcode: CVT_D0_S0_R1
/* 1359 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1368
/* 1364 */    MCD::OPC_Decode, 190, 3, 9, // Opcode: CVT_S32_F32
/* 1368 */    MCD::OPC_FilterValue, 8, 174, 11, 0, // Skip to: 4363
/* 1373 */    MCD::OPC_Decode, 200, 4, 9, // Opcode: RSQRT_F32
/* 1377 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 1430
/* 1382 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1385 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1394
/* 1390 */    MCD::OPC_Decode, 160, 4, 9, // Opcode: MADLO
/* 1394 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1403
/* 1399 */    MCD::OPC_Decode, 253, 3, 9, // Opcode: FMAX
/* 1403 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1412
/* 1408 */    MCD::OPC_Decode, 229, 2, 9, // Opcode: CVT_D0_S1_R1
/* 1412 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1421
/* 1417 */    MCD::OPC_Decode, 160, 3, 9, // Opcode: CVT_D2_S1_R1
/* 1421 */    MCD::OPC_FilterValue, 8, 121, 11, 0, // Skip to: 4363
/* 1426 */    MCD::OPC_Decode, 159, 5, 9, // Opcode: SIN_F32
/* 1430 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 1465
/* 1435 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1438 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1447
/* 1443 */    MCD::OPC_Decode, 209, 5, 9, // Opcode: XOR
/* 1447 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1456
/* 1452 */    MCD::OPC_Decode, 137, 4, 9, // Opcode: FSUB_F1
/* 1456 */    MCD::OPC_FilterValue, 2, 86, 11, 0, // Skip to: 4363
/* 1461 */    MCD::OPC_Decode, 235, 2, 9, // Opcode: CVT_D0_S2_R1
/* 1465 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 1500
/* 1470 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1473 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1482
/* 1478 */    MCD::OPC_Decode, 161, 5, 9, // Opcode: SRA
/* 1482 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1491
/* 1487 */    MCD::OPC_Decode, 254, 3, 9, // Opcode: FMAX_F1
/* 1491 */    MCD::OPC_FilterValue, 2, 51, 11, 0, // Skip to: 4363
/* 1496 */    MCD::OPC_Decode, 241, 2, 9, // Opcode: CVT_D0_S3_R1
/* 1500 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1535
/* 1505 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1508 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1517
/* 1513 */    MCD::OPC_Decode, 166, 4, 9, // Opcode: MAX_U
/* 1517 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1526
/* 1522 */    MCD::OPC_Decode, 250, 2, 9, // Opcode: CVT_D1_S0_R1
/* 1526 */    MCD::OPC_FilterValue, 3, 16, 11, 0, // Skip to: 4363
/* 1531 */    MCD::OPC_Decode, 193, 3, 9, // Opcode: CVT_U32_F32
/* 1535 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 1579
/* 1540 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1543 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1552
/* 1548 */    MCD::OPC_Decode, 183, 4, 9, // Opcode: NEG
/* 1552 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1561
/* 1557 */    MCD::OPC_Decode, 236, 3, 9, // Opcode: DP2_F16
/* 1561 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1570
/* 1566 */    MCD::OPC_Decode, 130, 3, 9, // Opcode: CVT_D1_S1_R1
/* 1570 */    MCD::OPC_FilterValue, 3, 228, 10, 0, // Skip to: 4363
/* 1575 */    MCD::OPC_Decode, 176, 3, 9, // Opcode: CVT_D3_S1_R1
/* 1579 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1595
/* 1584 */    MCD::OPC_CheckField, 27, 5, 2, 212, 10, 0, // Skip to: 4363
/* 1591 */    MCD::OPC_Decode, 138, 3, 9, // Opcode: CVT_D1_S2_R1
/* 1595 */    MCD::OPC_FilterValue, 7, 203, 10, 0, // Skip to: 4363
/* 1600 */    MCD::OPC_CheckField, 27, 5, 2, 196, 10, 0, // Skip to: 4363
/* 1607 */    MCD::OPC_Decode, 146, 3, 9, // Opcode: CVT_D1_S3_R1
/* 1611 */    MCD::OPC_FilterValue, 68, 227, 0, 0, // Skip to: 1843
/* 1616 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1619 */    MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 1663
/* 1624 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1627 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1636
/* 1632 */    MCD::OPC_Decode, 186, 5, 11, // Opcode: SUB_P
/* 1636 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1645
/* 1641 */    MCD::OPC_Decode, 139, 4, 11, // Opcode: FSUB_P
/* 1645 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1654
/* 1650 */    MCD::OPC_Decode, 220, 2, 11, // Opcode: CVT_D0_S0_R1_P
/* 1654 */    MCD::OPC_FilterValue, 3, 144, 10, 0, // Skip to: 4363
/* 1659 */    MCD::OPC_Decode, 191, 3, 11, // Opcode: CVT_S32_F32_P
/* 1663 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 1698
/* 1668 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1671 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1680
/* 1676 */    MCD::OPC_Decode, 161, 4, 11, // Opcode: MADLO_P
/* 1680 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1689
/* 1685 */    MCD::OPC_Decode, 230, 2, 11, // Opcode: CVT_D0_S1_R1_P
/* 1689 */    MCD::OPC_FilterValue, 3, 109, 10, 0, // Skip to: 4363
/* 1694 */    MCD::OPC_Decode, 161, 3, 11, // Opcode: CVT_D2_S1_R1_P
/* 1698 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 1724
/* 1703 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1706 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1715
/* 1711 */    MCD::OPC_Decode, 212, 5, 11, // Opcode: XOR_P
/* 1715 */    MCD::OPC_FilterValue, 2, 83, 10, 0, // Skip to: 4363
/* 1720 */    MCD::OPC_Decode, 236, 2, 11, // Opcode: CVT_D0_S2_R1_P
/* 1724 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 1750
/* 1729 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1732 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1741
/* 1737 */    MCD::OPC_Decode, 164, 5, 11, // Opcode: SRA_P
/* 1741 */    MCD::OPC_FilterValue, 2, 57, 10, 0, // Skip to: 4363
/* 1746 */    MCD::OPC_Decode, 242, 2, 11, // Opcode: CVT_D0_S3_R1_P
/* 1750 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1785
/* 1755 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1758 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1767
/* 1763 */    MCD::OPC_Decode, 167, 4, 11, // Opcode: MAX_U_P
/* 1767 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1776
/* 1772 */    MCD::OPC_Decode, 251, 2, 11, // Opcode: CVT_D1_S0_R1_P
/* 1776 */    MCD::OPC_FilterValue, 3, 22, 10, 0, // Skip to: 4363
/* 1781 */    MCD::OPC_Decode, 194, 3, 11, // Opcode: CVT_U32_F32_P
/* 1785 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 1811
/* 1790 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1793 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1802
/* 1798 */    MCD::OPC_Decode, 131, 3, 11, // Opcode: CVT_D1_S1_R1_P
/* 1802 */    MCD::OPC_FilterValue, 3, 252, 9, 0, // Skip to: 4363
/* 1807 */    MCD::OPC_Decode, 177, 3, 11, // Opcode: CVT_D3_S1_R1_P
/* 1811 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1827
/* 1816 */    MCD::OPC_CheckField, 30, 2, 2, 236, 9, 0, // Skip to: 4363
/* 1823 */    MCD::OPC_Decode, 139, 3, 11, // Opcode: CVT_D1_S2_R1_P
/* 1827 */    MCD::OPC_FilterValue, 7, 227, 9, 0, // Skip to: 4363
/* 1832 */    MCD::OPC_CheckField, 30, 2, 2, 220, 9, 0, // Skip to: 4363
/* 1839 */    MCD::OPC_Decode, 147, 3, 11, // Opcode: CVT_D1_S3_R1_P
/* 1843 */    MCD::OPC_FilterValue, 76, 39, 0, 0, // Skip to: 1887
/* 1848 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1851 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1860
/* 1856 */    MCD::OPC_Decode, 184, 5, 13, // Opcode: SUBI
/* 1860 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1869
/* 1865 */    MCD::OPC_Decode, 210, 5, 13, // Opcode: XORI
/* 1869 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1878
/* 1874 */    MCD::OPC_Decode, 162, 5, 14, // Opcode: SRAI
/* 1878 */    MCD::OPC_FilterValue, 5, 176, 9, 0, // Skip to: 4363
/* 1883 */    MCD::OPC_Decode, 190, 4, 14, // Opcode: PACKI_Z
/* 1887 */    MCD::OPC_FilterValue, 80, 30, 0, 0, // Skip to: 1922
/* 1892 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1895 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1904
/* 1900 */    MCD::OPC_Decode, 185, 5, 16, // Opcode: SUBI_P
/* 1904 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1913
/* 1909 */    MCD::OPC_Decode, 211, 5, 16, // Opcode: XORI_P
/* 1913 */    MCD::OPC_FilterValue, 3, 141, 9, 0, // Skip to: 4363
/* 1918 */    MCD::OPC_Decode, 163, 5, 17, // Opcode: SRAI_P
/* 1922 */    MCD::OPC_FilterValue, 88, 77, 0, 0, // Skip to: 2004
/* 1927 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1930 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1946
/* 1935 */    MCD::OPC_CheckField, 23, 4, 0, 117, 9, 0, // Skip to: 4363
/* 1942 */    MCD::OPC_Decode, 240, 4, 19, // Opcode: SETP_LE
/* 1946 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1962
/* 1951 */    MCD::OPC_CheckField, 23, 4, 0, 101, 9, 0, // Skip to: 4363
/* 1958 */    MCD::OPC_Decode, 212, 4, 19, // Opcode: SETP_GE
/* 1962 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1978
/* 1967 */    MCD::OPC_CheckField, 23, 4, 0, 85, 9, 0, // Skip to: 4363
/* 1974 */    MCD::OPC_Decode, 222, 4, 19, // Opcode: SETP_GE_U
/* 1978 */    MCD::OPC_FilterValue, 3, 76, 9, 0, // Skip to: 4363
/* 1983 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 1986 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1995
/* 1991 */    MCD::OPC_Decode, 141, 5, 19, // Opcode: SETP_NE_F
/* 1995 */    MCD::OPC_FilterValue, 1, 59, 9, 0, // Skip to: 4363
/* 2000 */    MCD::OPC_Decode, 142, 5, 19, // Opcode: SETP_NE_F1
/* 2004 */    MCD::OPC_FilterValue, 92, 39, 0, 0, // Skip to: 2048
/* 2009 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2012 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2021
/* 2017 */    MCD::OPC_Decode, 247, 4, 20, // Opcode: SETP_LE_I
/* 2021 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2030
/* 2026 */    MCD::OPC_Decode, 219, 4, 20, // Opcode: SETP_GE_I
/* 2030 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2039
/* 2035 */    MCD::OPC_Decode, 223, 4, 20, // Opcode: SETP_GE_U_I
/* 2039 */    MCD::OPC_FilterValue, 3, 15, 9, 0, // Skip to: 4363
/* 2044 */    MCD::OPC_Decode, 144, 5, 20, // Opcode: SETP_NE_F_I
/* 2048 */    MCD::OPC_FilterValue, 96, 75, 0, 0, // Skip to: 2128
/* 2053 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2056 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2065
/* 2061 */    MCD::OPC_Decode, 166, 5, 13, // Opcode: ST_GLOBAL
/* 2065 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2074
/* 2070 */    MCD::OPC_Decode, 167, 5, 21, // Opcode: ST_GLOBAL_IDX
/* 2074 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2083
/* 2079 */    MCD::OPC_Decode, 176, 5, 22, // Opcode: ST_PRED_G
/* 2083 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2092
/* 2088 */    MCD::OPC_Decode, 170, 5, 23, // Opcode: ST_GLOBAL_SLOT
/* 2092 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 2101
/* 2097 */    MCD::OPC_Decode, 175, 5, 24, // Opcode: ST_LOCAL
/* 2101 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 2110
/* 2106 */    MCD::OPC_Decode, 190, 5, 21, // Opcode: SZ_GLOBAL_LD_S8
/* 2110 */    MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 2119
/* 2115 */    MCD::OPC_Decode, 196, 5, 21, // Opcode: SZ_GLOBAL_ST_16
/* 2119 */    MCD::OPC_FilterValue, 7, 191, 8, 0, // Skip to: 4363
/* 2124 */    MCD::OPC_Decode, 200, 5, 21, // Opcode: SZ_SHARED_LD_S16
/* 2128 */    MCD::OPC_FilterValue, 100, 57, 0, 0, // Skip to: 2190
/* 2133 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2136 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2145
/* 2141 */    MCD::OPC_Decode, 190, 2, 25, // Opcode: ATOM_MIN_S_G
/* 2145 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2154
/* 2150 */    MCD::OPC_Decode, 182, 2, 25, // Opcode: ATOM_AND_G
/* 2154 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2163
/* 2159 */    MCD::OPC_Decode, 178, 2, 25, // Opcode: ATOM_ADD_F_G
/* 2163 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 2172
/* 2168 */    MCD::OPC_Decode, 191, 2, 25, // Opcode: ATOM_MIN_S_S
/* 2172 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 2181
/* 2177 */    MCD::OPC_Decode, 183, 2, 25, // Opcode: ATOM_AND_S
/* 2181 */    MCD::OPC_FilterValue, 6, 129, 8, 0, // Skip to: 4363
/* 2186 */    MCD::OPC_Decode, 179, 2, 25, // Opcode: ATOM_ADD_F_S
/* 2190 */    MCD::OPC_FilterValue, 104, 11, 0, 0, // Skip to: 2206
/* 2195 */    MCD::OPC_CheckField, 8, 3, 0, 113, 8, 0, // Skip to: 4363
/* 2202 */    MCD::OPC_Decode, 202, 2, 34, // Opcode: BRA_PRED
/* 2206 */    MCD::OPC_FilterValue, 112, 18, 0, 0, // Skip to: 2229
/* 2211 */    MCD::OPC_CheckField, 19, 8, 0, 97, 8, 0, // Skip to: 4363
/* 2218 */    MCD::OPC_CheckField, 8, 7, 2, 90, 8, 0, // Skip to: 4363
/* 2225 */    MCD::OPC_Decode, 206, 5, 35, // Opcode: UNBALLOT
/* 2229 */    MCD::OPC_FilterValue, 124, 145, 0, 0, // Skip to: 2379
/* 2234 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2237 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2270
/* 2242 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2245 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2261
/* 2250 */    MCD::OPC_CheckField, 23, 4, 0, 58, 8, 0, // Skip to: 4363
/* 2257 */    MCD::OPC_Decode, 248, 4, 32, // Opcode: SETP_LE_NP
/* 2261 */    MCD::OPC_FilterValue, 1, 49, 8, 0, // Skip to: 4363
/* 2266 */    MCD::OPC_Decode, 249, 4, 33, // Opcode: SETP_LE_NPI
/* 2270 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2303
/* 2275 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2278 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2294
/* 2283 */    MCD::OPC_CheckField, 23, 4, 0, 25, 8, 0, // Skip to: 4363
/* 2290 */    MCD::OPC_Decode, 220, 4, 32, // Opcode: SETP_GE_NP
/* 2294 */    MCD::OPC_FilterValue, 1, 16, 8, 0, // Skip to: 4363
/* 2299 */    MCD::OPC_Decode, 221, 4, 33, // Opcode: SETP_GE_NPI
/* 2303 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2336
/* 2308 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2311 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2327
/* 2316 */    MCD::OPC_CheckField, 23, 4, 0, 248, 7, 0, // Skip to: 4363
/* 2323 */    MCD::OPC_Decode, 224, 4, 32, // Opcode: SETP_GE_U_NP
/* 2327 */    MCD::OPC_FilterValue, 1, 239, 7, 0, // Skip to: 4363
/* 2332 */    MCD::OPC_Decode, 225, 4, 33, // Opcode: SETP_GE_U_NPI
/* 2336 */    MCD::OPC_FilterValue, 3, 230, 7, 0, // Skip to: 4363
/* 2341 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2344 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 2370
/* 2349 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2352 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2361
/* 2357 */    MCD::OPC_Decode, 145, 5, 32, // Opcode: SETP_NE_F_NP
/* 2361 */    MCD::OPC_FilterValue, 1, 205, 7, 0, // Skip to: 4363
/* 2366 */    MCD::OPC_Decode, 143, 5, 32, // Opcode: SETP_NE_F1_NP
/* 2370 */    MCD::OPC_FilterValue, 1, 196, 7, 0, // Skip to: 4363
/* 2375 */    MCD::OPC_Decode, 146, 5, 33, // Opcode: SETP_NE_F_NPI
/* 2379 */    MCD::OPC_FilterValue, 128, 1, 16, 1, 0, // Skip to: 2657
/* 2385 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2388 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 2441
/* 2393 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2396 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2405
/* 2401 */    MCD::OPC_Decode, 182, 4, 9, // Opcode: MUL_LO
/* 2405 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2414
/* 2410 */    MCD::OPC_Decode, 129, 4, 9, // Opcode: FMUL
/* 2414 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2423
/* 2419 */    MCD::OPC_Decode, 221, 2, 9, // Opcode: CVT_D0_S0_R2
/* 2423 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2432
/* 2428 */    MCD::OPC_Decode, 154, 3, 9, // Opcode: CVT_D2_S0_R2
/* 2432 */    MCD::OPC_FilterValue, 8, 134, 7, 0, // Skip to: 4363
/* 2437 */    MCD::OPC_Decode, 160, 5, 9, // Opcode: SQRT_F32
/* 2441 */    MCD::OPC_FilterValue, 1, 39, 0, 0, // Skip to: 2485
/* 2446 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2449 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2458
/* 2454 */    MCD::OPC_Decode, 134, 4, 9, // Opcode: FNEG_F0
/* 2458 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2467
/* 2463 */    MCD::OPC_Decode, 231, 2, 9, // Opcode: CVT_D0_S1_R2
/* 2467 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2476
/* 2472 */    MCD::OPC_Decode, 162, 3, 9, // Opcode: CVT_D2_S1_R2
/* 2476 */    MCD::OPC_FilterValue, 8, 90, 7, 0, // Skip to: 4363
/* 2481 */    MCD::OPC_Decode, 209, 2, 9, // Opcode: COS_F32
/* 2485 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 2520
/* 2490 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2493 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2502
/* 2498 */    MCD::OPC_Decode, 173, 2, 9, // Opcode: ANDN
/* 2502 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2511
/* 2507 */    MCD::OPC_Decode, 130, 4, 9, // Opcode: FMUL_F1
/* 2511 */    MCD::OPC_FilterValue, 2, 55, 7, 0, // Skip to: 4363
/* 2516 */    MCD::OPC_Decode, 237, 2, 9, // Opcode: CVT_D0_S2_R2
/* 2520 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 2555
/* 2525 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2528 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2537
/* 2533 */    MCD::OPC_Decode, 168, 4, 9, // Opcode: MIN_S
/* 2537 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2546
/* 2542 */    MCD::OPC_Decode, 135, 4, 9, // Opcode: FNEG_F1
/* 2546 */    MCD::OPC_FilterValue, 2, 20, 7, 0, // Skip to: 4363
/* 2551 */    MCD::OPC_Decode, 243, 2, 9, // Opcode: CVT_D0_S3_R2
/* 2555 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 2581
/* 2560 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2563 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2572
/* 2568 */    MCD::OPC_Decode, 252, 2, 9, // Opcode: CVT_D1_S0_R2
/* 2572 */    MCD::OPC_FilterValue, 3, 250, 6, 0, // Skip to: 4363
/* 2577 */    MCD::OPC_Decode, 170, 3, 9, // Opcode: CVT_D3_S0_R2
/* 2581 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 2625
/* 2586 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2589 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2598
/* 2594 */    MCD::OPC_Decode, 194, 4, 9, // Opcode: POPC
/* 2598 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2607
/* 2603 */    MCD::OPC_Decode, 238, 3, 9, // Opcode: DP4_E4M3
/* 2607 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2616
/* 2612 */    MCD::OPC_Decode, 132, 3, 9, // Opcode: CVT_D1_S1_R2
/* 2616 */    MCD::OPC_FilterValue, 3, 206, 6, 0, // Skip to: 4363
/* 2621 */    MCD::OPC_Decode, 178, 3, 9, // Opcode: CVT_D3_S1_R2
/* 2625 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2641
/* 2630 */    MCD::OPC_CheckField, 27, 5, 2, 190, 6, 0, // Skip to: 4363
/* 2637 */    MCD::OPC_Decode, 140, 3, 9, // Opcode: CVT_D1_S2_R2
/* 2641 */    MCD::OPC_FilterValue, 7, 181, 6, 0, // Skip to: 4363
/* 2646 */    MCD::OPC_CheckField, 27, 5, 2, 174, 6, 0, // Skip to: 4363
/* 2653 */    MCD::OPC_Decode, 148, 3, 9, // Opcode: CVT_D1_S3_R2
/* 2657 */    MCD::OPC_FilterValue, 132, 1, 199, 0, 0, // Skip to: 2862
/* 2663 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2666 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 2701
/* 2671 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2674 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2683
/* 2679 */    MCD::OPC_Decode, 132, 4, 11, // Opcode: FMUL_P
/* 2683 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2692
/* 2688 */    MCD::OPC_Decode, 222, 2, 11, // Opcode: CVT_D0_S0_R2_P
/* 2692 */    MCD::OPC_FilterValue, 3, 130, 6, 0, // Skip to: 4363
/* 2697 */    MCD::OPC_Decode, 155, 3, 11, // Opcode: CVT_D2_S0_R2_P
/* 2701 */    MCD::OPC_FilterValue, 1, 21, 0, 0, // Skip to: 2727
/* 2706 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2709 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2718
/* 2714 */    MCD::OPC_Decode, 232, 2, 11, // Opcode: CVT_D0_S1_R2_P
/* 2718 */    MCD::OPC_FilterValue, 3, 104, 6, 0, // Skip to: 4363
/* 2723 */    MCD::OPC_Decode, 163, 3, 11, // Opcode: CVT_D2_S1_R2_P
/* 2727 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2743
/* 2732 */    MCD::OPC_CheckField, 30, 2, 2, 88, 6, 0, // Skip to: 4363
/* 2739 */    MCD::OPC_Decode, 238, 2, 11, // Opcode: CVT_D0_S2_R2_P
/* 2743 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 2769
/* 2748 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2751 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2760
/* 2756 */    MCD::OPC_Decode, 169, 4, 11, // Opcode: MIN_S_P
/* 2760 */    MCD::OPC_FilterValue, 2, 62, 6, 0, // Skip to: 4363
/* 2765 */    MCD::OPC_Decode, 244, 2, 11, // Opcode: CVT_D0_S3_R2_P
/* 2769 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 2804
/* 2774 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2777 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2786
/* 2782 */    MCD::OPC_Decode, 175, 4, 36, // Opcode: MOV_P
/* 2786 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2795
/* 2791 */    MCD::OPC_Decode, 253, 2, 11, // Opcode: CVT_D1_S0_R2_P
/* 2795 */    MCD::OPC_FilterValue, 3, 27, 6, 0, // Skip to: 4363
/* 2800 */    MCD::OPC_Decode, 171, 3, 11, // Opcode: CVT_D3_S0_R2_P
/* 2804 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 2830
/* 2809 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2812 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2821
/* 2817 */    MCD::OPC_Decode, 133, 3, 11, // Opcode: CVT_D1_S1_R2_P
/* 2821 */    MCD::OPC_FilterValue, 3, 1, 6, 0, // Skip to: 4363
/* 2826 */    MCD::OPC_Decode, 179, 3, 11, // Opcode: CVT_D3_S1_R2_P
/* 2830 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2846
/* 2835 */    MCD::OPC_CheckField, 30, 2, 2, 241, 5, 0, // Skip to: 4363
/* 2842 */    MCD::OPC_Decode, 141, 3, 11, // Opcode: CVT_D1_S2_R2_P
/* 2846 */    MCD::OPC_FilterValue, 7, 232, 5, 0, // Skip to: 4363
/* 2851 */    MCD::OPC_CheckField, 30, 2, 2, 225, 5, 0, // Skip to: 4363
/* 2858 */    MCD::OPC_Decode, 149, 3, 11, // Opcode: CVT_D1_S3_R2_P
/* 2862 */    MCD::OPC_FilterValue, 140, 1, 30, 0, 0, // Skip to: 2898
/* 2868 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2871 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2880
/* 2876 */    MCD::OPC_Decode, 176, 4, 13, // Opcode: MULI
/* 2880 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2889
/* 2885 */    MCD::OPC_Decode, 174, 2, 13, // Opcode: ANDNI
/* 2889 */    MCD::OPC_FilterValue, 5, 189, 5, 0, // Skip to: 4363
/* 2894 */    MCD::OPC_Decode, 207, 5, 14, // Opcode: UNPACKI
/* 2898 */    MCD::OPC_FilterValue, 144, 1, 21, 0, 0, // Skip to: 2925
/* 2904 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2907 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2916
/* 2912 */    MCD::OPC_Decode, 177, 4, 16, // Opcode: MULI_P
/* 2916 */    MCD::OPC_FilterValue, 2, 162, 5, 0, // Skip to: 4363
/* 2921 */    MCD::OPC_Decode, 175, 2, 16, // Opcode: ANDNI_P
/* 2925 */    MCD::OPC_FilterValue, 152, 1, 87, 0, 0, // Skip to: 3018
/* 2931 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2934 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2950
/* 2939 */    MCD::OPC_CheckField, 23, 4, 0, 137, 5, 0, // Skip to: 4363
/* 2946 */    MCD::OPC_Decode, 202, 4, 19, // Opcode: SETP_EQ
/* 2950 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 2966
/* 2955 */    MCD::OPC_CheckField, 23, 4, 0, 121, 5, 0, // Skip to: 4363
/* 2962 */    MCD::OPC_Decode, 136, 5, 19, // Opcode: SETP_LT_U
/* 2966 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 2992
/* 2971 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2974 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2983
/* 2979 */    MCD::OPC_Decode, 255, 4, 19, // Opcode: SETP_LT_F
/* 2983 */    MCD::OPC_FilterValue, 1, 95, 5, 0, // Skip to: 4363
/* 2988 */    MCD::OPC_Decode, 128, 5, 19, // Opcode: SETP_LT_F1
/* 2992 */    MCD::OPC_FilterValue, 3, 86, 5, 0, // Skip to: 4363
/* 2997 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3000 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3009
/* 3005 */    MCD::OPC_Decode, 227, 4, 19, // Opcode: SETP_GT_F
/* 3009 */    MCD::OPC_FilterValue, 1, 69, 5, 0, // Skip to: 4363
/* 3014 */    MCD::OPC_Decode, 228, 4, 19, // Opcode: SETP_GT_F1
/* 3018 */    MCD::OPC_FilterValue, 156, 1, 39, 0, 0, // Skip to: 3063
/* 3024 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3027 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3036
/* 3032 */    MCD::OPC_Decode, 209, 4, 20, // Opcode: SETP_EQ_I
/* 3036 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3045
/* 3041 */    MCD::OPC_Decode, 137, 5, 20, // Opcode: SETP_LT_U_I
/* 3045 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3054
/* 3050 */    MCD::OPC_Decode, 130, 5, 20, // Opcode: SETP_LT_F_I
/* 3054 */    MCD::OPC_FilterValue, 3, 24, 5, 0, // Skip to: 4363
/* 3059 */    MCD::OPC_Decode, 230, 4, 20, // Opcode: SETP_GT_F_I
/* 3063 */    MCD::OPC_FilterValue, 160, 1, 66, 0, 0, // Skip to: 3135
/* 3069 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3072 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3081
/* 3077 */    MCD::OPC_Decode, 155, 4, 13, // Opcode: LD_SHARED
/* 3081 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3090
/* 3086 */    MCD::OPC_Decode, 156, 4, 21, // Opcode: LD_SHARED_IDX
/* 3090 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3099
/* 3095 */    MCD::OPC_Decode, 154, 4, 22, // Opcode: LD_PRED_S
/* 3099 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 3108
/* 3104 */    MCD::OPC_Decode, 153, 4, 37, // Opcode: LD_PRED_LOCAL
/* 3108 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 3117
/* 3113 */    MCD::OPC_Decode, 192, 5, 21, // Opcode: SZ_GLOBAL_LD_U16
/* 3117 */    MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 3126
/* 3122 */    MCD::OPC_Decode, 203, 5, 21, // Opcode: SZ_SHARED_LD_U8
/* 3126 */    MCD::OPC_FilterValue, 7, 208, 4, 0, // Skip to: 4363
/* 3131 */    MCD::OPC_Decode, 205, 5, 21, // Opcode: SZ_SHARED_ST_8
/* 3135 */    MCD::OPC_FilterValue, 164, 1, 39, 0, 0, // Skip to: 3180
/* 3141 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3144 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3153
/* 3149 */    MCD::OPC_Decode, 192, 2, 25, // Opcode: ATOM_MIN_U_G
/* 3153 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3162
/* 3158 */    MCD::OPC_Decode, 194, 2, 25, // Opcode: ATOM_OR_G
/* 3162 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 3171
/* 3167 */    MCD::OPC_Decode, 193, 2, 25, // Opcode: ATOM_MIN_U_S
/* 3171 */    MCD::OPC_FilterValue, 5, 163, 4, 0, // Skip to: 4363
/* 3176 */    MCD::OPC_Decode, 195, 2, 25, // Opcode: ATOM_OR_S
/* 3180 */    MCD::OPC_FilterValue, 168, 1, 11, 0, 0, // Skip to: 3197
/* 3186 */    MCD::OPC_CheckField, 8, 3, 0, 146, 4, 0, // Skip to: 4363
/* 3193 */    MCD::OPC_Decode, 204, 2, 38, // Opcode: CALL
/* 3197 */    MCD::OPC_FilterValue, 188, 1, 155, 0, 0, // Skip to: 3358
/* 3203 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3206 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 3239
/* 3211 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3214 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3230
/* 3219 */    MCD::OPC_CheckField, 23, 4, 0, 113, 4, 0, // Skip to: 4363
/* 3226 */    MCD::OPC_Decode, 210, 4, 32, // Opcode: SETP_EQ_NP
/* 3230 */    MCD::OPC_FilterValue, 1, 104, 4, 0, // Skip to: 4363
/* 3235 */    MCD::OPC_Decode, 211, 4, 33, // Opcode: SETP_EQ_NPI
/* 3239 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 3272
/* 3244 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3247 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3263
/* 3252 */    MCD::OPC_CheckField, 23, 4, 0, 80, 4, 0, // Skip to: 4363
/* 3259 */    MCD::OPC_Decode, 138, 5, 32, // Opcode: SETP_LT_U_NP
/* 3263 */    MCD::OPC_FilterValue, 1, 71, 4, 0, // Skip to: 4363
/* 3268 */    MCD::OPC_Decode, 139, 5, 33, // Opcode: SETP_LT_U_NPI
/* 3272 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 3315
/* 3277 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3280 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3306
/* 3285 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3288 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3297
/* 3293 */    MCD::OPC_Decode, 131, 5, 32, // Opcode: SETP_LT_F_NP
/* 3297 */    MCD::OPC_FilterValue, 1, 37, 4, 0, // Skip to: 4363
/* 3302 */    MCD::OPC_Decode, 129, 5, 32, // Opcode: SETP_LT_F1_NP
/* 3306 */    MCD::OPC_FilterValue, 1, 28, 4, 0, // Skip to: 4363
/* 3311 */    MCD::OPC_Decode, 132, 5, 33, // Opcode: SETP_LT_F_NPI
/* 3315 */    MCD::OPC_FilterValue, 3, 19, 4, 0, // Skip to: 4363
/* 3320 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3323 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3349
/* 3328 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3331 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3340
/* 3336 */    MCD::OPC_Decode, 231, 4, 32, // Opcode: SETP_GT_F_NP
/* 3340 */    MCD::OPC_FilterValue, 1, 250, 3, 0, // Skip to: 4363
/* 3345 */    MCD::OPC_Decode, 229, 4, 32, // Opcode: SETP_GT_F1_NP
/* 3349 */    MCD::OPC_FilterValue, 1, 241, 3, 0, // Skip to: 4363
/* 3354 */    MCD::OPC_Decode, 232, 4, 33, // Opcode: SETP_GT_F_NPI
/* 3358 */    MCD::OPC_FilterValue, 192, 1, 25, 1, 0, // Skip to: 3645
/* 3364 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3367 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 3420
/* 3372 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3375 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3384
/* 3380 */    MCD::OPC_Decode, 178, 4, 9, // Opcode: MUL_HI_S
/* 3384 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3393
/* 3389 */    MCD::OPC_Decode, 251, 3, 9, // Opcode: FFMA_F0
/* 3393 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3402
/* 3398 */    MCD::OPC_Decode, 223, 2, 9, // Opcode: CVT_D0_S0_R3
/* 3402 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3411
/* 3407 */    MCD::OPC_Decode, 156, 3, 9, // Opcode: CVT_D2_S0_R3
/* 3411 */    MCD::OPC_FilterValue, 8, 179, 3, 0, // Skip to: 4363
/* 3416 */    MCD::OPC_Decode, 241, 3, 9, // Opcode: EX2_F32
/* 3420 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 3473
/* 3425 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3428 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3437
/* 3433 */    MCD::OPC_Decode, 170, 2, 9, // Opcode: AND
/* 3437 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3446
/* 3442 */    MCD::OPC_Decode, 242, 3, 9, // Opcode: FABS_F0
/* 3446 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3455
/* 3451 */    MCD::OPC_Decode, 233, 2, 9, // Opcode: CVT_D0_S1_R3
/* 3455 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3464
/* 3460 */    MCD::OPC_Decode, 164, 3, 9, // Opcode: CVT_D2_S1_R3
/* 3464 */    MCD::OPC_FilterValue, 8, 126, 3, 0, // Skip to: 4363
/* 3469 */    MCD::OPC_Decode, 199, 4, 9, // Opcode: RCP_U32
/* 3473 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 3508
/* 3478 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3481 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3490
/* 3486 */    MCD::OPC_Decode, 151, 5, 9, // Opcode: SHL
/* 3490 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3499
/* 3495 */    MCD::OPC_Decode, 252, 3, 9, // Opcode: FFMA_F1
/* 3499 */    MCD::OPC_FilterValue, 2, 91, 3, 0, // Skip to: 4363
/* 3504 */    MCD::OPC_Decode, 239, 2, 9, // Opcode: CVT_D0_S2_R3
/* 3508 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 3543
/* 3513 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3516 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3525
/* 3521 */    MCD::OPC_Decode, 171, 4, 9, // Opcode: MIN_U
/* 3525 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3534
/* 3530 */    MCD::OPC_Decode, 243, 3, 9, // Opcode: FABS_F1
/* 3534 */    MCD::OPC_FilterValue, 2, 56, 3, 0, // Skip to: 4363
/* 3539 */    MCD::OPC_Decode, 245, 2, 9, // Opcode: CVT_D0_S3_R3
/* 3543 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 3569
/* 3548 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3551 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3560
/* 3556 */    MCD::OPC_Decode, 254, 2, 9, // Opcode: CVT_D1_S0_R3
/* 3560 */    MCD::OPC_FilterValue, 3, 30, 3, 0, // Skip to: 4363
/* 3565 */    MCD::OPC_Decode, 172, 3, 9, // Opcode: CVT_D3_S0_R3
/* 3569 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 3613
/* 3574 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3577 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3586
/* 3582 */    MCD::OPC_Decode, 208, 2, 9, // Opcode: CLZ
/* 3586 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3595
/* 3591 */    MCD::OPC_Decode, 239, 3, 9, // Opcode: DP4_E5M2
/* 3595 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3604
/* 3600 */    MCD::OPC_Decode, 134, 3, 9, // Opcode: CVT_D1_S1_R3
/* 3604 */    MCD::OPC_FilterValue, 3, 242, 2, 0, // Skip to: 4363
/* 3609 */    MCD::OPC_Decode, 180, 3, 9, // Opcode: CVT_D3_S1_R3
/* 3613 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3629
/* 3618 */    MCD::OPC_CheckField, 27, 5, 2, 226, 2, 0, // Skip to: 4363
/* 3625 */    MCD::OPC_Decode, 142, 3, 9, // Opcode: CVT_D1_S2_R3
/* 3629 */    MCD::OPC_FilterValue, 7, 217, 2, 0, // Skip to: 4363
/* 3634 */    MCD::OPC_CheckField, 27, 5, 2, 210, 2, 0, // Skip to: 4363
/* 3641 */    MCD::OPC_Decode, 150, 3, 9, // Opcode: CVT_D1_S3_R3
/* 3645 */    MCD::OPC_FilterValue, 196, 1, 218, 0, 0, // Skip to: 3869
/* 3651 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3654 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 3689
/* 3659 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3662 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3671
/* 3667 */    MCD::OPC_Decode, 179, 4, 11, // Opcode: MUL_HI_S_P
/* 3671 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3680
/* 3676 */    MCD::OPC_Decode, 224, 2, 11, // Opcode: CVT_D0_S0_R3_P
/* 3680 */    MCD::OPC_FilterValue, 3, 166, 2, 0, // Skip to: 4363
/* 3685 */    MCD::OPC_Decode, 157, 3, 11, // Opcode: CVT_D2_S0_R3_P
/* 3689 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 3724
/* 3694 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3697 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3706
/* 3702 */    MCD::OPC_Decode, 176, 2, 11, // Opcode: AND_P
/* 3706 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3715
/* 3711 */    MCD::OPC_Decode, 234, 2, 11, // Opcode: CVT_D0_S1_R3_P
/* 3715 */    MCD::OPC_FilterValue, 3, 131, 2, 0, // Skip to: 4363
/* 3720 */    MCD::OPC_Decode, 165, 3, 11, // Opcode: CVT_D2_S1_R3_P
/* 3724 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3750
/* 3729 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3732 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3741
/* 3737 */    MCD::OPC_Decode, 154, 5, 11, // Opcode: SHL_P
/* 3741 */    MCD::OPC_FilterValue, 2, 105, 2, 0, // Skip to: 4363
/* 3746 */    MCD::OPC_Decode, 240, 2, 11, // Opcode: CVT_D0_S2_R3_P
/* 3750 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 3776
/* 3755 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3758 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3767
/* 3763 */    MCD::OPC_Decode, 172, 4, 11, // Opcode: MIN_U_P
/* 3767 */    MCD::OPC_FilterValue, 2, 79, 2, 0, // Skip to: 4363
/* 3772 */    MCD::OPC_Decode, 246, 2, 11, // Opcode: CVT_D0_S3_R3_P
/* 3776 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 3811
/* 3781 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3784 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3793
/* 3789 */    MCD::OPC_Decode, 201, 4, 11, // Opcode: SEL
/* 3793 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3802
/* 3798 */    MCD::OPC_Decode, 255, 2, 11, // Opcode: CVT_D1_S0_R3_P
/* 3802 */    MCD::OPC_FilterValue, 3, 44, 2, 0, // Skip to: 4363
/* 3807 */    MCD::OPC_Decode, 173, 3, 11, // Opcode: CVT_D3_S0_R3_P
/* 3811 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 3837
/* 3816 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3819 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3828
/* 3824 */    MCD::OPC_Decode, 135, 3, 11, // Opcode: CVT_D1_S1_R3_P
/* 3828 */    MCD::OPC_FilterValue, 3, 18, 2, 0, // Skip to: 4363
/* 3833 */    MCD::OPC_Decode, 181, 3, 11, // Opcode: CVT_D3_S1_R3_P
/* 3837 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3853
/* 3842 */    MCD::OPC_CheckField, 30, 2, 2, 2, 2, 0, // Skip to: 4363
/* 3849 */    MCD::OPC_Decode, 143, 3, 11, // Opcode: CVT_D1_S2_R3_P
/* 3853 */    MCD::OPC_FilterValue, 7, 249, 1, 0, // Skip to: 4363
/* 3858 */    MCD::OPC_CheckField, 30, 2, 2, 242, 1, 0, // Skip to: 4363
/* 3865 */    MCD::OPC_Decode, 151, 3, 11, // Opcode: CVT_D1_S3_R3_P
/* 3869 */    MCD::OPC_FilterValue, 204, 1, 21, 0, 0, // Skip to: 3896
/* 3875 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3878 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3887
/* 3883 */    MCD::OPC_Decode, 171, 2, 13, // Opcode: ANDI
/* 3887 */    MCD::OPC_FilterValue, 2, 215, 1, 0, // Skip to: 4363
/* 3892 */    MCD::OPC_Decode, 152, 5, 14, // Opcode: SHLI
/* 3896 */    MCD::OPC_FilterValue, 208, 1, 21, 0, 0, // Skip to: 3923
/* 3902 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3905 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3914
/* 3910 */    MCD::OPC_Decode, 172, 2, 16, // Opcode: ANDI_P
/* 3914 */    MCD::OPC_FilterValue, 2, 188, 1, 0, // Skip to: 4363
/* 3919 */    MCD::OPC_Decode, 153, 5, 17, // Opcode: SHLI_P
/* 3923 */    MCD::OPC_FilterValue, 216, 1, 87, 0, 0, // Skip to: 4016
/* 3929 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3932 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3948
/* 3937 */    MCD::OPC_CheckField, 23, 4, 0, 163, 1, 0, // Skip to: 4363
/* 3944 */    MCD::OPC_Decode, 140, 5, 19, // Opcode: SETP_NE
/* 3948 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 3964
/* 3953 */    MCD::OPC_CheckField, 23, 4, 0, 147, 1, 0, // Skip to: 4363
/* 3960 */    MCD::OPC_Decode, 250, 4, 19, // Opcode: SETP_LE_U
/* 3964 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3990
/* 3969 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3972 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3981
/* 3977 */    MCD::OPC_Decode, 241, 4, 19, // Opcode: SETP_LE_F
/* 3981 */    MCD::OPC_FilterValue, 1, 121, 1, 0, // Skip to: 4363
/* 3986 */    MCD::OPC_Decode, 242, 4, 19, // Opcode: SETP_LE_F1
/* 3990 */    MCD::OPC_FilterValue, 3, 112, 1, 0, // Skip to: 4363
/* 3995 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3998 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4007
/* 4003 */    MCD::OPC_Decode, 213, 4, 19, // Opcode: SETP_GE_F
/* 4007 */    MCD::OPC_FilterValue, 1, 95, 1, 0, // Skip to: 4363
/* 4012 */    MCD::OPC_Decode, 214, 4, 19, // Opcode: SETP_GE_F1
/* 4016 */    MCD::OPC_FilterValue, 220, 1, 39, 0, 0, // Skip to: 4061
/* 4022 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4025 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4034
/* 4030 */    MCD::OPC_Decode, 147, 5, 20, // Opcode: SETP_NE_I
/* 4034 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4043
/* 4039 */    MCD::OPC_Decode, 251, 4, 20, // Opcode: SETP_LE_U_I
/* 4043 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 4052
/* 4048 */    MCD::OPC_Decode, 244, 4, 20, // Opcode: SETP_LE_F_I
/* 4052 */    MCD::OPC_FilterValue, 3, 50, 1, 0, // Skip to: 4363
/* 4057 */    MCD::OPC_Decode, 216, 4, 20, // Opcode: SETP_GE_F_I
/* 4061 */    MCD::OPC_FilterValue, 224, 1, 66, 0, 0, // Skip to: 4133
/* 4067 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4070 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4079
/* 4075 */    MCD::OPC_Decode, 179, 5, 13, // Opcode: ST_SHARED
/* 4079 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4088
/* 4084 */    MCD::OPC_Decode, 180, 5, 21, // Opcode: ST_SHARED_IDX
/* 4088 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 4097
/* 4093 */    MCD::OPC_Decode, 178, 5, 22, // Opcode: ST_PRED_S
/* 4097 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 4106
/* 4102 */    MCD::OPC_Decode, 177, 5, 37, // Opcode: ST_PRED_LOCAL
/* 4106 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 4115
/* 4111 */    MCD::OPC_Decode, 188, 5, 21, // Opcode: SZ_GLOBAL_LD_S16
/* 4115 */    MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 4124
/* 4120 */    MCD::OPC_Decode, 201, 5, 21, // Opcode: SZ_SHARED_LD_S8
/* 4124 */    MCD::OPC_FilterValue, 7, 234, 0, 0, // Skip to: 4363
/* 4129 */    MCD::OPC_Decode, 204, 5, 21, // Opcode: SZ_SHARED_ST_16
/* 4133 */    MCD::OPC_FilterValue, 228, 1, 39, 0, 0, // Skip to: 4178
/* 4139 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4142 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4151
/* 4147 */    MCD::OPC_Decode, 186, 2, 25, // Opcode: ATOM_MAX_S_G
/* 4151 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4160
/* 4156 */    MCD::OPC_Decode, 196, 2, 25, // Opcode: ATOM_XOR_G
/* 4160 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 4169
/* 4165 */    MCD::OPC_Decode, 187, 2, 25, // Opcode: ATOM_MAX_S_S
/* 4169 */    MCD::OPC_FilterValue, 5, 189, 0, 0, // Skip to: 4363
/* 4174 */    MCD::OPC_Decode, 197, 2, 25, // Opcode: ATOM_XOR_S
/* 4178 */    MCD::OPC_FilterValue, 232, 1, 18, 0, 0, // Skip to: 4202
/* 4184 */    MCD::OPC_CheckField, 27, 5, 0, 172, 0, 0, // Skip to: 4363
/* 4191 */    MCD::OPC_CheckField, 8, 3, 0, 165, 0, 0, // Skip to: 4363
/* 4198 */    MCD::OPC_Decode, 199, 2, 39, // Opcode: BAR_INIT
/* 4202 */    MCD::OPC_FilterValue, 252, 1, 155, 0, 0, // Skip to: 4363
/* 4208 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4211 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 4244
/* 4216 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4219 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 4235
/* 4224 */    MCD::OPC_CheckField, 23, 4, 0, 132, 0, 0, // Skip to: 4363
/* 4231 */    MCD::OPC_Decode, 148, 5, 32, // Opcode: SETP_NE_NP
/* 4235 */    MCD::OPC_FilterValue, 1, 123, 0, 0, // Skip to: 4363
/* 4240 */    MCD::OPC_Decode, 149, 5, 33, // Opcode: SETP_NE_NPI
/* 4244 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 4277
/* 4249 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4252 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 4268
/* 4257 */    MCD::OPC_CheckField, 23, 4, 0, 99, 0, 0, // Skip to: 4363
/* 4264 */    MCD::OPC_Decode, 252, 4, 32, // Opcode: SETP_LE_U_NP
/* 4268 */    MCD::OPC_FilterValue, 1, 90, 0, 0, // Skip to: 4363
/* 4273 */    MCD::OPC_Decode, 253, 4, 33, // Opcode: SETP_LE_U_NPI
/* 4277 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 4320
/* 4282 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4285 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 4311
/* 4290 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4293 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4302
/* 4298 */    MCD::OPC_Decode, 245, 4, 32, // Opcode: SETP_LE_F_NP
/* 4302 */    MCD::OPC_FilterValue, 1, 56, 0, 0, // Skip to: 4363
/* 4307 */    MCD::OPC_Decode, 243, 4, 32, // Opcode: SETP_LE_F1_NP
/* 4311 */    MCD::OPC_FilterValue, 1, 47, 0, 0, // Skip to: 4363
/* 4316 */    MCD::OPC_Decode, 246, 4, 33, // Opcode: SETP_LE_F_NPI
/* 4320 */    MCD::OPC_FilterValue, 3, 38, 0, 0, // Skip to: 4363
/* 4325 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4328 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 4354
/* 4333 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4336 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4345
/* 4341 */    MCD::OPC_Decode, 217, 4, 32, // Opcode: SETP_GE_F_NP
/* 4345 */    MCD::OPC_FilterValue, 1, 13, 0, 0, // Skip to: 4363
/* 4350 */    MCD::OPC_Decode, 215, 4, 32, // Opcode: SETP_GE_F1_NP
/* 4354 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4363
/* 4359 */    MCD::OPC_Decode, 218, 4, 33, // Opcode: SETP_GE_F_NPI
/* 4363 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable48[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 3 */       MCD::OPC_FilterValue, 7, 18, 0, 0, // Skip to: 26
/* 8 */       MCD::OPC_CheckField, 30, 18, 8, 91, 0, 0, // Skip to: 106
/* 15 */      MCD::OPC_CheckField, 8, 3, 0, 84, 0, 0, // Skip to: 106
/* 22 */      MCD::OPC_Decode, 198, 4, 11, // Opcode: RCP_F32_P
/* 26 */      MCD::OPC_FilterValue, 15, 11, 0, 0, // Skip to: 42
/* 31 */      MCD::OPC_CheckField, 8, 3, 0, 68, 0, 0, // Skip to: 106
/* 38 */      MCD::OPC_Decode, 163, 2, 40, // Opcode: ADDI48
/* 42 */      MCD::OPC_FilterValue, 39, 11, 0, 0, // Skip to: 58
/* 47 */      MCD::OPC_CheckField, 8, 3, 4, 52, 0, 0, // Skip to: 106
/* 54 */      MCD::OPC_Decode, 205, 2, 41, // Opcode: CAS_G
/* 58 */      MCD::OPC_FilterValue, 47, 11, 0, 0, // Skip to: 74
/* 63 */      MCD::OPC_CheckField, 8, 3, 0, 36, 0, 0, // Skip to: 106
/* 70 */      MCD::OPC_Decode, 174, 4, 42, // Opcode: MOVI48
/* 74 */      MCD::OPC_FilterValue, 103, 11, 0, 0, // Skip to: 90
/* 79 */      MCD::OPC_CheckField, 8, 3, 4, 20, 0, 0, // Skip to: 106
/* 86 */      MCD::OPC_Decode, 206, 2, 41, // Opcode: CAS_S
/* 90 */      MCD::OPC_FilterValue, 123, 11, 0, 0, // Skip to: 106
/* 95 */      MCD::OPC_CheckField, 10, 6, 0, 4, 0, 0, // Skip to: 106
/* 102 */     MCD::OPC_Decode, 193, 4, 43, // Opcode: PMOV_IMM
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
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 15, 17);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 38:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 17);
    if (!Check(S, decodeSImm<17>(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 11, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 17, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 19, 29);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 41:
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
  case 42:
    tmp = fieldFromInstruction(insn, 11, 4);
    if (!Check(S, DecodeGPRRegisterClass(MI, tmp, Address, Decoder))) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 33);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 43:
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
