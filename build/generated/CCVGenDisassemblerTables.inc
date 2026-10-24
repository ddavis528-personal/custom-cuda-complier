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
/* 55 */      MCD::OPC_FilterValue, 8, 99, 16, 0, // Skip to: 4255
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
/* 108 */     MCD::OPC_FilterValue, 8, 46, 16, 0, // Skip to: 4255
/* 113 */     MCD::OPC_Decode, 159, 4, 9, // Opcode: LG2_F32
/* 117 */     MCD::OPC_FilterValue, 2, 39, 0, 0, // Skip to: 161
/* 122 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 125 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 134
/* 130 */     MCD::OPC_Decode, 184, 4, 9, // Opcode: OR
/* 134 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 143
/* 139 */     MCD::OPC_Decode, 245, 3, 9, // Opcode: FADD_F1
/* 143 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 152
/* 148 */     MCD::OPC_Decode, 186, 3, 9, // Opcode: CVT_F32_S32
/* 152 */     MCD::OPC_FilterValue, 3, 2, 16, 0, // Skip to: 4255
/* 157 */     MCD::OPC_Decode, 192, 3, 10, // Opcode: CVT_SEXT
/* 161 */     MCD::OPC_FilterValue, 3, 39, 0, 0, // Skip to: 205
/* 166 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 169 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 178
/* 174 */     MCD::OPC_Decode, 155, 5, 9, // Opcode: SHR
/* 178 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 187
/* 183 */     MCD::OPC_Decode, 128, 4, 9, // Opcode: FMIN_F1
/* 187 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 196
/* 192 */     MCD::OPC_Decode, 188, 3, 9, // Opcode: CVT_F32_U32
/* 196 */     MCD::OPC_FilterValue, 3, 214, 15, 0, // Skip to: 4255
/* 201 */     MCD::OPC_Decode, 166, 3, 9, // Opcode: CVT_D2_S3_R0
/* 205 */     MCD::OPC_FilterValue, 4, 39, 0, 0, // Skip to: 249
/* 210 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 213 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 222
/* 218 */     MCD::OPC_Decode, 163, 4, 9, // Opcode: MAX_S
/* 222 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 231
/* 227 */     MCD::OPC_Decode, 240, 3, 9, // Opcode: DP4_SS
/* 231 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 240
/* 236 */     MCD::OPC_Decode, 247, 2, 9, // Opcode: CVT_D1_S0_R0
/* 240 */     MCD::OPC_FilterValue, 3, 170, 15, 0, // Skip to: 4255
/* 245 */     MCD::OPC_Decode, 168, 3, 9, // Opcode: CVT_D3_S0_R0
/* 249 */     MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 293
/* 254 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 257 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 266
/* 262 */     MCD::OPC_Decode, 160, 2, 9, // Opcode: ABS
/* 266 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 275
/* 271 */     MCD::OPC_Decode, 235, 3, 9, // Opcode: DP2_BF16
/* 275 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 284
/* 280 */     MCD::OPC_Decode, 128, 3, 9, // Opcode: CVT_D1_S1_R0
/* 284 */     MCD::OPC_FilterValue, 3, 126, 15, 0, // Skip to: 4255
/* 289 */     MCD::OPC_Decode, 174, 3, 9, // Opcode: CVT_D3_S1_R0
/* 293 */     MCD::OPC_FilterValue, 6, 30, 0, 0, // Skip to: 328
/* 298 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 301 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 310
/* 306 */     MCD::OPC_Decode, 203, 2, 9, // Opcode: BREV
/* 310 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 319
/* 315 */     MCD::OPC_Decode, 136, 3, 9, // Opcode: CVT_D1_S2_R0
/* 319 */     MCD::OPC_FilterValue, 3, 91, 15, 0, // Skip to: 4255
/* 324 */     MCD::OPC_Decode, 182, 3, 9, // Opcode: CVT_D3_S2_R0
/* 328 */     MCD::OPC_FilterValue, 7, 82, 15, 0, // Skip to: 4255
/* 333 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 336 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 345
/* 341 */     MCD::OPC_Decode, 144, 3, 9, // Opcode: CVT_D1_S3_R0
/* 345 */     MCD::OPC_FilterValue, 3, 65, 15, 0, // Skip to: 4255
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
/* 397 */     MCD::OPC_FilterValue, 3, 13, 15, 0, // Skip to: 4255
/* 402 */     MCD::OPC_Decode, 153, 3, 11, // Opcode: CVT_D2_S0_R0_P
/* 406 */     MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 441
/* 411 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 414 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 423
/* 419 */     MCD::OPC_Decode, 181, 4, 11, // Opcode: MUL_HI_U_P
/* 423 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 432
/* 428 */     MCD::OPC_Decode, 226, 2, 11, // Opcode: CVT_D0_S1_R0_P
/* 432 */     MCD::OPC_FilterValue, 3, 234, 14, 0, // Skip to: 4255
/* 437 */     MCD::OPC_Decode, 159, 3, 11, // Opcode: CVT_D2_S1_R0_P
/* 441 */     MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 467
/* 446 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 449 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 458
/* 454 */     MCD::OPC_Decode, 187, 4, 11, // Opcode: OR_P
/* 458 */     MCD::OPC_FilterValue, 2, 208, 14, 0, // Skip to: 4255
/* 463 */     MCD::OPC_Decode, 187, 3, 11, // Opcode: CVT_F32_S32_P
/* 467 */     MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 502
/* 472 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 475 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 484
/* 480 */     MCD::OPC_Decode, 158, 5, 11, // Opcode: SHR_P
/* 484 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 493
/* 489 */     MCD::OPC_Decode, 189, 3, 11, // Opcode: CVT_F32_U32_P
/* 493 */     MCD::OPC_FilterValue, 3, 173, 14, 0, // Skip to: 4255
/* 498 */     MCD::OPC_Decode, 167, 3, 11, // Opcode: CVT_D2_S3_R0_P
/* 502 */     MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 537
/* 507 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 510 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 519
/* 515 */     MCD::OPC_Decode, 164, 4, 11, // Opcode: MAX_S_P
/* 519 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 528
/* 524 */     MCD::OPC_Decode, 248, 2, 11, // Opcode: CVT_D1_S0_R0_P
/* 528 */     MCD::OPC_FilterValue, 3, 138, 14, 0, // Skip to: 4255
/* 533 */     MCD::OPC_Decode, 169, 3, 11, // Opcode: CVT_D3_S0_R0_P
/* 537 */     MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 563
/* 542 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 545 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 554
/* 550 */     MCD::OPC_Decode, 129, 3, 11, // Opcode: CVT_D1_S1_R0_P
/* 554 */     MCD::OPC_FilterValue, 3, 112, 14, 0, // Skip to: 4255
/* 559 */     MCD::OPC_Decode, 175, 3, 11, // Opcode: CVT_D3_S1_R0_P
/* 563 */     MCD::OPC_FilterValue, 6, 21, 0, 0, // Skip to: 589
/* 568 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 571 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 580
/* 576 */     MCD::OPC_Decode, 137, 3, 11, // Opcode: CVT_D1_S2_R0_P
/* 580 */     MCD::OPC_FilterValue, 3, 86, 14, 0, // Skip to: 4255
/* 585 */     MCD::OPC_Decode, 183, 3, 11, // Opcode: CVT_D3_S2_R0_P
/* 589 */     MCD::OPC_FilterValue, 7, 77, 14, 0, // Skip to: 4255
/* 594 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 597 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 606
/* 602 */     MCD::OPC_Decode, 145, 3, 11, // Opcode: CVT_D1_S3_R0_P
/* 606 */     MCD::OPC_FilterValue, 3, 60, 14, 0, // Skip to: 4255
/* 611 */     MCD::OPC_Decode, 185, 3, 11, // Opcode: CVT_D3_S3_R0_P
/* 615 */     MCD::OPC_FilterValue, 8, 11, 0, 0, // Skip to: 631
/* 620 */     MCD::OPC_CheckField, 8, 3, 0, 44, 14, 0, // Skip to: 4255
/* 627 */     MCD::OPC_Decode, 168, 2, 12, // Opcode: ADD_PP
/* 631 */     MCD::OPC_FilterValue, 12, 39, 0, 0, // Skip to: 675
/* 636 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 639 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 648
/* 644 */     MCD::OPC_Decode, 162, 2, 13, // Opcode: ADDI
/* 648 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 657
/* 653 */     MCD::OPC_Decode, 185, 4, 13, // Opcode: ORI
/* 657 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 666
/* 662 */     MCD::OPC_Decode, 156, 5, 14, // Opcode: SHRI
/* 666 */     MCD::OPC_FilterValue, 5, 0, 14, 0, // Skip to: 4255
/* 671 */     MCD::OPC_Decode, 189, 4, 15, // Opcode: PACKI
/* 675 */     MCD::OPC_FilterValue, 16, 30, 0, 0, // Skip to: 710
/* 680 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 683 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 692
/* 688 */     MCD::OPC_Decode, 164, 2, 16, // Opcode: ADDI_P
/* 692 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 701
/* 697 */     MCD::OPC_Decode, 186, 4, 16, // Opcode: ORI_P
/* 701 */     MCD::OPC_FilterValue, 3, 221, 13, 0, // Skip to: 4255
/* 706 */     MCD::OPC_Decode, 157, 5, 17, // Opcode: SHRI_P
/* 710 */     MCD::OPC_FilterValue, 20, 11, 0, 0, // Skip to: 726
/* 715 */     MCD::OPC_CheckField, 8, 3, 0, 205, 13, 0, // Skip to: 4255
/* 722 */     MCD::OPC_Decode, 165, 2, 18, // Opcode: ADDI_PP
/* 726 */     MCD::OPC_FilterValue, 24, 77, 0, 0, // Skip to: 808
/* 731 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 734 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 750
/* 739 */     MCD::OPC_CheckField, 23, 4, 0, 181, 13, 0, // Skip to: 4255
/* 746 */     MCD::OPC_Decode, 254, 4, 19, // Opcode: SETP_LT
/* 750 */     MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 766
/* 755 */     MCD::OPC_CheckField, 23, 4, 0, 165, 13, 0, // Skip to: 4255
/* 762 */     MCD::OPC_Decode, 226, 4, 19, // Opcode: SETP_GT
/* 766 */     MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 782
/* 771 */     MCD::OPC_CheckField, 23, 4, 0, 149, 13, 0, // Skip to: 4255
/* 778 */     MCD::OPC_Decode, 236, 4, 19, // Opcode: SETP_GT_U
/* 782 */     MCD::OPC_FilterValue, 3, 140, 13, 0, // Skip to: 4255
/* 787 */     MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 790 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 799
/* 795 */     MCD::OPC_Decode, 203, 4, 19, // Opcode: SETP_EQ_F
/* 799 */     MCD::OPC_FilterValue, 1, 123, 13, 0, // Skip to: 4255
/* 804 */     MCD::OPC_Decode, 204, 4, 19, // Opcode: SETP_EQ_F1
/* 808 */     MCD::OPC_FilterValue, 28, 39, 0, 0, // Skip to: 852
/* 813 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 816 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 825
/* 821 */     MCD::OPC_Decode, 133, 5, 20, // Opcode: SETP_LT_I
/* 825 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 834
/* 830 */     MCD::OPC_Decode, 233, 4, 20, // Opcode: SETP_GT_I
/* 834 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 843
/* 839 */     MCD::OPC_Decode, 237, 4, 20, // Opcode: SETP_GT_U_I
/* 843 */     MCD::OPC_FilterValue, 3, 79, 13, 0, // Skip to: 4255
/* 848 */     MCD::OPC_Decode, 206, 4, 20, // Opcode: SETP_EQ_F_I
/* 852 */     MCD::OPC_FilterValue, 32, 48, 0, 0, // Skip to: 905
/* 857 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 860 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 869
/* 865 */     MCD::OPC_Decode, 141, 4, 13, // Opcode: LD_GLOBAL
/* 869 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 878
/* 874 */     MCD::OPC_Decode, 142, 4, 21, // Opcode: LD_GLOBAL_IDX
/* 878 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 887
/* 883 */     MCD::OPC_Decode, 152, 4, 22, // Opcode: LD_PRED_G
/* 887 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 896
/* 892 */     MCD::OPC_Decode, 146, 4, 23, // Opcode: LD_GLOBAL_SLOT
/* 896 */     MCD::OPC_FilterValue, 4, 26, 13, 0, // Skip to: 4255
/* 901 */     MCD::OPC_Decode, 151, 4, 24, // Opcode: LD_LOCAL
/* 905 */     MCD::OPC_FilterValue, 36, 57, 0, 0, // Skip to: 967
/* 910 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 913 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 922
/* 918 */     MCD::OPC_Decode, 180, 2, 25, // Opcode: ATOM_ADD_G
/* 922 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 931
/* 927 */     MCD::OPC_Decode, 188, 2, 25, // Opcode: ATOM_MAX_U_G
/* 931 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 940
/* 936 */     MCD::OPC_Decode, 184, 2, 25, // Opcode: ATOM_EXCH_G
/* 940 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 949
/* 945 */     MCD::OPC_Decode, 181, 2, 25, // Opcode: ATOM_ADD_S
/* 949 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 958
/* 954 */     MCD::OPC_Decode, 189, 2, 25, // Opcode: ATOM_MAX_U_S
/* 958 */     MCD::OPC_FilterValue, 6, 220, 12, 0, // Skip to: 4255
/* 963 */     MCD::OPC_Decode, 185, 2, 25, // Opcode: ATOM_EXCH_S
/* 967 */     MCD::OPC_FilterValue, 40, 35, 0, 0, // Skip to: 1007
/* 972 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 975 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 984
/* 980 */     MCD::OPC_Decode, 201, 2, 26, // Opcode: BRA
/* 984 */     MCD::OPC_FilterValue, 1, 194, 12, 0, // Skip to: 4255
/* 989 */     MCD::OPC_CheckField, 30, 2, 0, 187, 12, 0, // Skip to: 4255
/* 996 */     MCD::OPC_CheckField, 19, 8, 0, 180, 12, 0, // Skip to: 4255
/* 1003 */    MCD::OPC_Decode, 200, 2, 27, // Opcode: BAR_WAIT_PHASE
/* 1007 */    MCD::OPC_FilterValue, 44, 11, 0, 0, // Skip to: 1023
/* 1012 */    MCD::OPC_CheckField, 8, 3, 0, 164, 12, 0, // Skip to: 4255
/* 1019 */    MCD::OPC_Decode, 173, 4, 24, // Opcode: MOVI
/* 1023 */    MCD::OPC_FilterValue, 48, 79, 0, 0, // Skip to: 1107
/* 1028 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1031 */    MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 1054
/* 1036 */    MCD::OPC_CheckField, 30, 2, 0, 140, 12, 0, // Skip to: 4255
/* 1043 */    MCD::OPC_CheckField, 24, 3, 0, 133, 12, 0, // Skip to: 4255
/* 1050 */    MCD::OPC_Decode, 150, 5, 28, // Opcode: SHFL_IDX
/* 1054 */    MCD::OPC_FilterValue, 1, 18, 0, 0, // Skip to: 1077
/* 1059 */    MCD::OPC_CheckField, 22, 5, 0, 117, 12, 0, // Skip to: 4255
/* 1066 */    MCD::OPC_CheckField, 11, 8, 0, 110, 12, 0, // Skip to: 4255
/* 1073 */    MCD::OPC_Decode, 190, 5, 29, // Opcode: VOTE_ANY
/* 1077 */    MCD::OPC_FilterValue, 2, 101, 12, 0, // Skip to: 4255
/* 1082 */    MCD::OPC_CheckField, 30, 2, 0, 94, 12, 0, // Skip to: 4255
/* 1089 */    MCD::OPC_CheckField, 22, 5, 0, 87, 12, 0, // Skip to: 4255
/* 1096 */    MCD::OPC_CheckField, 15, 4, 0, 80, 12, 0, // Skip to: 4255
/* 1103 */    MCD::OPC_Decode, 198, 2, 30, // Opcode: BALLOT
/* 1107 */    MCD::OPC_FilterValue, 52, 11, 0, 0, // Skip to: 1123
/* 1112 */    MCD::OPC_CheckField, 8, 3, 0, 64, 12, 0, // Skip to: 4255
/* 1119 */    MCD::OPC_Decode, 145, 4, 16, // Opcode: LD_GLOBAL_P
/* 1123 */    MCD::OPC_FilterValue, 56, 11, 0, 0, // Skip to: 1139
/* 1128 */    MCD::OPC_CheckField, 26, 6, 0, 48, 12, 0, // Skip to: 4255
/* 1135 */    MCD::OPC_Decode, 207, 2, 31, // Opcode: CHWIDTH_MULTI
/* 1139 */    MCD::OPC_FilterValue, 60, 145, 0, 0, // Skip to: 1289
/* 1144 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1147 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 1180
/* 1152 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1155 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1171
/* 1160 */    MCD::OPC_CheckField, 23, 4, 0, 16, 12, 0, // Skip to: 4255
/* 1167 */    MCD::OPC_Decode, 134, 5, 32, // Opcode: SETP_LT_NP
/* 1171 */    MCD::OPC_FilterValue, 1, 7, 12, 0, // Skip to: 4255
/* 1176 */    MCD::OPC_Decode, 135, 5, 33, // Opcode: SETP_LT_NPI
/* 1180 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 1213
/* 1185 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1188 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1204
/* 1193 */    MCD::OPC_CheckField, 23, 4, 0, 239, 11, 0, // Skip to: 4255
/* 1200 */    MCD::OPC_Decode, 234, 4, 32, // Opcode: SETP_GT_NP
/* 1204 */    MCD::OPC_FilterValue, 1, 230, 11, 0, // Skip to: 4255
/* 1209 */    MCD::OPC_Decode, 235, 4, 33, // Opcode: SETP_GT_NPI
/* 1213 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 1246
/* 1218 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1221 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1237
/* 1226 */    MCD::OPC_CheckField, 23, 4, 0, 206, 11, 0, // Skip to: 4255
/* 1233 */    MCD::OPC_Decode, 238, 4, 32, // Opcode: SETP_GT_U_NP
/* 1237 */    MCD::OPC_FilterValue, 1, 197, 11, 0, // Skip to: 4255
/* 1242 */    MCD::OPC_Decode, 239, 4, 33, // Opcode: SETP_GT_U_NPI
/* 1246 */    MCD::OPC_FilterValue, 3, 188, 11, 0, // Skip to: 4255
/* 1251 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1254 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 1280
/* 1259 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 1262 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1271
/* 1267 */    MCD::OPC_Decode, 207, 4, 32, // Opcode: SETP_EQ_F_NP
/* 1271 */    MCD::OPC_FilterValue, 1, 163, 11, 0, // Skip to: 4255
/* 1276 */    MCD::OPC_Decode, 205, 4, 32, // Opcode: SETP_EQ_F1_NP
/* 1280 */    MCD::OPC_FilterValue, 1, 154, 11, 0, // Skip to: 4255
/* 1285 */    MCD::OPC_Decode, 208, 4, 33, // Opcode: SETP_EQ_F_NPI
/* 1289 */    MCD::OPC_FilterValue, 64, 34, 1, 0, // Skip to: 1584
/* 1294 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1297 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 1350
/* 1302 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1305 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1314
/* 1310 */    MCD::OPC_Decode, 183, 5, 9, // Opcode: SUB
/* 1314 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1323
/* 1319 */    MCD::OPC_Decode, 136, 4, 9, // Opcode: FSUB
/* 1323 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1332
/* 1328 */    MCD::OPC_Decode, 219, 2, 9, // Opcode: CVT_D0_S0_R1
/* 1332 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1341
/* 1337 */    MCD::OPC_Decode, 190, 3, 9, // Opcode: CVT_S32_F32
/* 1341 */    MCD::OPC_FilterValue, 8, 93, 11, 0, // Skip to: 4255
/* 1346 */    MCD::OPC_Decode, 200, 4, 9, // Opcode: RSQRT_F32
/* 1350 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 1403
/* 1355 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1358 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1367
/* 1363 */    MCD::OPC_Decode, 160, 4, 9, // Opcode: MADLO
/* 1367 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1376
/* 1372 */    MCD::OPC_Decode, 253, 3, 9, // Opcode: FMAX
/* 1376 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1385
/* 1381 */    MCD::OPC_Decode, 229, 2, 9, // Opcode: CVT_D0_S1_R1
/* 1385 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1394
/* 1390 */    MCD::OPC_Decode, 160, 3, 9, // Opcode: CVT_D2_S1_R1
/* 1394 */    MCD::OPC_FilterValue, 8, 40, 11, 0, // Skip to: 4255
/* 1399 */    MCD::OPC_Decode, 159, 5, 9, // Opcode: SIN_F32
/* 1403 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 1438
/* 1408 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1411 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1420
/* 1416 */    MCD::OPC_Decode, 191, 5, 9, // Opcode: XOR
/* 1420 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1429
/* 1425 */    MCD::OPC_Decode, 137, 4, 9, // Opcode: FSUB_F1
/* 1429 */    MCD::OPC_FilterValue, 2, 5, 11, 0, // Skip to: 4255
/* 1434 */    MCD::OPC_Decode, 235, 2, 9, // Opcode: CVT_D0_S2_R1
/* 1438 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 1473
/* 1443 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1446 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1455
/* 1451 */    MCD::OPC_Decode, 161, 5, 9, // Opcode: SRA
/* 1455 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1464
/* 1460 */    MCD::OPC_Decode, 254, 3, 9, // Opcode: FMAX_F1
/* 1464 */    MCD::OPC_FilterValue, 2, 226, 10, 0, // Skip to: 4255
/* 1469 */    MCD::OPC_Decode, 241, 2, 9, // Opcode: CVT_D0_S3_R1
/* 1473 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1508
/* 1478 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1481 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1490
/* 1486 */    MCD::OPC_Decode, 166, 4, 9, // Opcode: MAX_U
/* 1490 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1499
/* 1495 */    MCD::OPC_Decode, 250, 2, 9, // Opcode: CVT_D1_S0_R1
/* 1499 */    MCD::OPC_FilterValue, 3, 191, 10, 0, // Skip to: 4255
/* 1504 */    MCD::OPC_Decode, 193, 3, 9, // Opcode: CVT_U32_F32
/* 1508 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 1552
/* 1513 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1516 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1525
/* 1521 */    MCD::OPC_Decode, 183, 4, 9, // Opcode: NEG
/* 1525 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1534
/* 1530 */    MCD::OPC_Decode, 236, 3, 9, // Opcode: DP2_F16
/* 1534 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1543
/* 1539 */    MCD::OPC_Decode, 130, 3, 9, // Opcode: CVT_D1_S1_R1
/* 1543 */    MCD::OPC_FilterValue, 3, 147, 10, 0, // Skip to: 4255
/* 1548 */    MCD::OPC_Decode, 176, 3, 9, // Opcode: CVT_D3_S1_R1
/* 1552 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1568
/* 1557 */    MCD::OPC_CheckField, 27, 5, 2, 131, 10, 0, // Skip to: 4255
/* 1564 */    MCD::OPC_Decode, 138, 3, 9, // Opcode: CVT_D1_S2_R1
/* 1568 */    MCD::OPC_FilterValue, 7, 122, 10, 0, // Skip to: 4255
/* 1573 */    MCD::OPC_CheckField, 27, 5, 2, 115, 10, 0, // Skip to: 4255
/* 1580 */    MCD::OPC_Decode, 146, 3, 9, // Opcode: CVT_D1_S3_R1
/* 1584 */    MCD::OPC_FilterValue, 68, 227, 0, 0, // Skip to: 1816
/* 1589 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1592 */    MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 1636
/* 1597 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1600 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1609
/* 1605 */    MCD::OPC_Decode, 186, 5, 11, // Opcode: SUB_P
/* 1609 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1618
/* 1614 */    MCD::OPC_Decode, 139, 4, 11, // Opcode: FSUB_P
/* 1618 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1627
/* 1623 */    MCD::OPC_Decode, 220, 2, 11, // Opcode: CVT_D0_S0_R1_P
/* 1627 */    MCD::OPC_FilterValue, 3, 63, 10, 0, // Skip to: 4255
/* 1632 */    MCD::OPC_Decode, 191, 3, 11, // Opcode: CVT_S32_F32_P
/* 1636 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 1671
/* 1641 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1644 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1653
/* 1649 */    MCD::OPC_Decode, 161, 4, 11, // Opcode: MADLO_P
/* 1653 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1662
/* 1658 */    MCD::OPC_Decode, 230, 2, 11, // Opcode: CVT_D0_S1_R1_P
/* 1662 */    MCD::OPC_FilterValue, 3, 28, 10, 0, // Skip to: 4255
/* 1667 */    MCD::OPC_Decode, 161, 3, 11, // Opcode: CVT_D2_S1_R1_P
/* 1671 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 1697
/* 1676 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1679 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1688
/* 1684 */    MCD::OPC_Decode, 194, 5, 11, // Opcode: XOR_P
/* 1688 */    MCD::OPC_FilterValue, 2, 2, 10, 0, // Skip to: 4255
/* 1693 */    MCD::OPC_Decode, 236, 2, 11, // Opcode: CVT_D0_S2_R1_P
/* 1697 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 1723
/* 1702 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1705 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1714
/* 1710 */    MCD::OPC_Decode, 164, 5, 11, // Opcode: SRA_P
/* 1714 */    MCD::OPC_FilterValue, 2, 232, 9, 0, // Skip to: 4255
/* 1719 */    MCD::OPC_Decode, 242, 2, 11, // Opcode: CVT_D0_S3_R1_P
/* 1723 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 1758
/* 1728 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1731 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1740
/* 1736 */    MCD::OPC_Decode, 167, 4, 11, // Opcode: MAX_U_P
/* 1740 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1749
/* 1745 */    MCD::OPC_Decode, 251, 2, 11, // Opcode: CVT_D1_S0_R1_P
/* 1749 */    MCD::OPC_FilterValue, 3, 197, 9, 0, // Skip to: 4255
/* 1754 */    MCD::OPC_Decode, 194, 3, 11, // Opcode: CVT_U32_F32_P
/* 1758 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 1784
/* 1763 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1766 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1775
/* 1771 */    MCD::OPC_Decode, 131, 3, 11, // Opcode: CVT_D1_S1_R1_P
/* 1775 */    MCD::OPC_FilterValue, 3, 171, 9, 0, // Skip to: 4255
/* 1780 */    MCD::OPC_Decode, 177, 3, 11, // Opcode: CVT_D3_S1_R1_P
/* 1784 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 1800
/* 1789 */    MCD::OPC_CheckField, 30, 2, 2, 155, 9, 0, // Skip to: 4255
/* 1796 */    MCD::OPC_Decode, 139, 3, 11, // Opcode: CVT_D1_S2_R1_P
/* 1800 */    MCD::OPC_FilterValue, 7, 146, 9, 0, // Skip to: 4255
/* 1805 */    MCD::OPC_CheckField, 30, 2, 2, 139, 9, 0, // Skip to: 4255
/* 1812 */    MCD::OPC_Decode, 147, 3, 11, // Opcode: CVT_D1_S3_R1_P
/* 1816 */    MCD::OPC_FilterValue, 76, 39, 0, 0, // Skip to: 1860
/* 1821 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1824 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1833
/* 1829 */    MCD::OPC_Decode, 184, 5, 13, // Opcode: SUBI
/* 1833 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1842
/* 1838 */    MCD::OPC_Decode, 192, 5, 13, // Opcode: XORI
/* 1842 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1851
/* 1847 */    MCD::OPC_Decode, 162, 5, 14, // Opcode: SRAI
/* 1851 */    MCD::OPC_FilterValue, 5, 95, 9, 0, // Skip to: 4255
/* 1856 */    MCD::OPC_Decode, 190, 4, 14, // Opcode: PACKI_Z
/* 1860 */    MCD::OPC_FilterValue, 80, 30, 0, 0, // Skip to: 1895
/* 1865 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1868 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1877
/* 1873 */    MCD::OPC_Decode, 185, 5, 16, // Opcode: SUBI_P
/* 1877 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1886
/* 1882 */    MCD::OPC_Decode, 193, 5, 16, // Opcode: XORI_P
/* 1886 */    MCD::OPC_FilterValue, 3, 60, 9, 0, // Skip to: 4255
/* 1891 */    MCD::OPC_Decode, 163, 5, 17, // Opcode: SRAI_P
/* 1895 */    MCD::OPC_FilterValue, 88, 77, 0, 0, // Skip to: 1977
/* 1900 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1903 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1919
/* 1908 */    MCD::OPC_CheckField, 23, 4, 0, 36, 9, 0, // Skip to: 4255
/* 1915 */    MCD::OPC_Decode, 240, 4, 19, // Opcode: SETP_LE
/* 1919 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1935
/* 1924 */    MCD::OPC_CheckField, 23, 4, 0, 20, 9, 0, // Skip to: 4255
/* 1931 */    MCD::OPC_Decode, 212, 4, 19, // Opcode: SETP_GE
/* 1935 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1951
/* 1940 */    MCD::OPC_CheckField, 23, 4, 0, 4, 9, 0, // Skip to: 4255
/* 1947 */    MCD::OPC_Decode, 222, 4, 19, // Opcode: SETP_GE_U
/* 1951 */    MCD::OPC_FilterValue, 3, 251, 8, 0, // Skip to: 4255
/* 1956 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 1959 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1968
/* 1964 */    MCD::OPC_Decode, 141, 5, 19, // Opcode: SETP_NE_F
/* 1968 */    MCD::OPC_FilterValue, 1, 234, 8, 0, // Skip to: 4255
/* 1973 */    MCD::OPC_Decode, 142, 5, 19, // Opcode: SETP_NE_F1
/* 1977 */    MCD::OPC_FilterValue, 92, 39, 0, 0, // Skip to: 2021
/* 1982 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1985 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1994
/* 1990 */    MCD::OPC_Decode, 247, 4, 20, // Opcode: SETP_LE_I
/* 1994 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2003
/* 1999 */    MCD::OPC_Decode, 219, 4, 20, // Opcode: SETP_GE_I
/* 2003 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2012
/* 2008 */    MCD::OPC_Decode, 223, 4, 20, // Opcode: SETP_GE_U_I
/* 2012 */    MCD::OPC_FilterValue, 3, 190, 8, 0, // Skip to: 4255
/* 2017 */    MCD::OPC_Decode, 144, 5, 20, // Opcode: SETP_NE_F_I
/* 2021 */    MCD::OPC_FilterValue, 96, 48, 0, 0, // Skip to: 2074
/* 2026 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2029 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2038
/* 2034 */    MCD::OPC_Decode, 166, 5, 13, // Opcode: ST_GLOBAL
/* 2038 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2047
/* 2043 */    MCD::OPC_Decode, 167, 5, 21, // Opcode: ST_GLOBAL_IDX
/* 2047 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2056
/* 2052 */    MCD::OPC_Decode, 176, 5, 22, // Opcode: ST_PRED_G
/* 2056 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2065
/* 2061 */    MCD::OPC_Decode, 170, 5, 23, // Opcode: ST_GLOBAL_SLOT
/* 2065 */    MCD::OPC_FilterValue, 4, 137, 8, 0, // Skip to: 4255
/* 2070 */    MCD::OPC_Decode, 175, 5, 24, // Opcode: ST_LOCAL
/* 2074 */    MCD::OPC_FilterValue, 100, 57, 0, 0, // Skip to: 2136
/* 2079 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2082 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2091
/* 2087 */    MCD::OPC_Decode, 190, 2, 25, // Opcode: ATOM_MIN_S_G
/* 2091 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2100
/* 2096 */    MCD::OPC_Decode, 182, 2, 25, // Opcode: ATOM_AND_G
/* 2100 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2109
/* 2105 */    MCD::OPC_Decode, 178, 2, 25, // Opcode: ATOM_ADD_F_G
/* 2109 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 2118
/* 2114 */    MCD::OPC_Decode, 191, 2, 25, // Opcode: ATOM_MIN_S_S
/* 2118 */    MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 2127
/* 2123 */    MCD::OPC_Decode, 183, 2, 25, // Opcode: ATOM_AND_S
/* 2127 */    MCD::OPC_FilterValue, 6, 75, 8, 0, // Skip to: 4255
/* 2132 */    MCD::OPC_Decode, 179, 2, 25, // Opcode: ATOM_ADD_F_S
/* 2136 */    MCD::OPC_FilterValue, 104, 11, 0, 0, // Skip to: 2152
/* 2141 */    MCD::OPC_CheckField, 8, 3, 0, 59, 8, 0, // Skip to: 4255
/* 2148 */    MCD::OPC_Decode, 202, 2, 34, // Opcode: BRA_PRED
/* 2152 */    MCD::OPC_FilterValue, 112, 18, 0, 0, // Skip to: 2175
/* 2157 */    MCD::OPC_CheckField, 19, 8, 0, 43, 8, 0, // Skip to: 4255
/* 2164 */    MCD::OPC_CheckField, 8, 7, 2, 36, 8, 0, // Skip to: 4255
/* 2171 */    MCD::OPC_Decode, 188, 5, 35, // Opcode: UNBALLOT
/* 2175 */    MCD::OPC_FilterValue, 124, 145, 0, 0, // Skip to: 2325
/* 2180 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2183 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2216
/* 2188 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2191 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2207
/* 2196 */    MCD::OPC_CheckField, 23, 4, 0, 4, 8, 0, // Skip to: 4255
/* 2203 */    MCD::OPC_Decode, 248, 4, 32, // Opcode: SETP_LE_NP
/* 2207 */    MCD::OPC_FilterValue, 1, 251, 7, 0, // Skip to: 4255
/* 2212 */    MCD::OPC_Decode, 249, 4, 33, // Opcode: SETP_LE_NPI
/* 2216 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2249
/* 2221 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2224 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2240
/* 2229 */    MCD::OPC_CheckField, 23, 4, 0, 227, 7, 0, // Skip to: 4255
/* 2236 */    MCD::OPC_Decode, 220, 4, 32, // Opcode: SETP_GE_NP
/* 2240 */    MCD::OPC_FilterValue, 1, 218, 7, 0, // Skip to: 4255
/* 2245 */    MCD::OPC_Decode, 221, 4, 33, // Opcode: SETP_GE_NPI
/* 2249 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2282
/* 2254 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2257 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2273
/* 2262 */    MCD::OPC_CheckField, 23, 4, 0, 194, 7, 0, // Skip to: 4255
/* 2269 */    MCD::OPC_Decode, 224, 4, 32, // Opcode: SETP_GE_U_NP
/* 2273 */    MCD::OPC_FilterValue, 1, 185, 7, 0, // Skip to: 4255
/* 2278 */    MCD::OPC_Decode, 225, 4, 33, // Opcode: SETP_GE_U_NPI
/* 2282 */    MCD::OPC_FilterValue, 3, 176, 7, 0, // Skip to: 4255
/* 2287 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2290 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 2316
/* 2295 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2298 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2307
/* 2303 */    MCD::OPC_Decode, 145, 5, 32, // Opcode: SETP_NE_F_NP
/* 2307 */    MCD::OPC_FilterValue, 1, 151, 7, 0, // Skip to: 4255
/* 2312 */    MCD::OPC_Decode, 143, 5, 32, // Opcode: SETP_NE_F1_NP
/* 2316 */    MCD::OPC_FilterValue, 1, 142, 7, 0, // Skip to: 4255
/* 2321 */    MCD::OPC_Decode, 146, 5, 33, // Opcode: SETP_NE_F_NPI
/* 2325 */    MCD::OPC_FilterValue, 128, 1, 16, 1, 0, // Skip to: 2603
/* 2331 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2334 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 2387
/* 2339 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2342 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2351
/* 2347 */    MCD::OPC_Decode, 182, 4, 9, // Opcode: MUL_LO
/* 2351 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2360
/* 2356 */    MCD::OPC_Decode, 129, 4, 9, // Opcode: FMUL
/* 2360 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2369
/* 2365 */    MCD::OPC_Decode, 221, 2, 9, // Opcode: CVT_D0_S0_R2
/* 2369 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2378
/* 2374 */    MCD::OPC_Decode, 154, 3, 9, // Opcode: CVT_D2_S0_R2
/* 2378 */    MCD::OPC_FilterValue, 8, 80, 7, 0, // Skip to: 4255
/* 2383 */    MCD::OPC_Decode, 160, 5, 9, // Opcode: SQRT_F32
/* 2387 */    MCD::OPC_FilterValue, 1, 39, 0, 0, // Skip to: 2431
/* 2392 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2395 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2404
/* 2400 */    MCD::OPC_Decode, 134, 4, 9, // Opcode: FNEG_F0
/* 2404 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2413
/* 2409 */    MCD::OPC_Decode, 231, 2, 9, // Opcode: CVT_D0_S1_R2
/* 2413 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 2422
/* 2418 */    MCD::OPC_Decode, 162, 3, 9, // Opcode: CVT_D2_S1_R2
/* 2422 */    MCD::OPC_FilterValue, 8, 36, 7, 0, // Skip to: 4255
/* 2427 */    MCD::OPC_Decode, 209, 2, 9, // Opcode: COS_F32
/* 2431 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 2466
/* 2436 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2439 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2448
/* 2444 */    MCD::OPC_Decode, 173, 2, 9, // Opcode: ANDN
/* 2448 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2457
/* 2453 */    MCD::OPC_Decode, 130, 4, 9, // Opcode: FMUL_F1
/* 2457 */    MCD::OPC_FilterValue, 2, 1, 7, 0, // Skip to: 4255
/* 2462 */    MCD::OPC_Decode, 237, 2, 9, // Opcode: CVT_D0_S2_R2
/* 2466 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 2501
/* 2471 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2474 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2483
/* 2479 */    MCD::OPC_Decode, 168, 4, 9, // Opcode: MIN_S
/* 2483 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2492
/* 2488 */    MCD::OPC_Decode, 135, 4, 9, // Opcode: FNEG_F1
/* 2492 */    MCD::OPC_FilterValue, 2, 222, 6, 0, // Skip to: 4255
/* 2497 */    MCD::OPC_Decode, 243, 2, 9, // Opcode: CVT_D0_S3_R2
/* 2501 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 2527
/* 2506 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2509 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2518
/* 2514 */    MCD::OPC_Decode, 252, 2, 9, // Opcode: CVT_D1_S0_R2
/* 2518 */    MCD::OPC_FilterValue, 3, 196, 6, 0, // Skip to: 4255
/* 2523 */    MCD::OPC_Decode, 170, 3, 9, // Opcode: CVT_D3_S0_R2
/* 2527 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 2571
/* 2532 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2535 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2544
/* 2540 */    MCD::OPC_Decode, 194, 4, 9, // Opcode: POPC
/* 2544 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2553
/* 2549 */    MCD::OPC_Decode, 238, 3, 9, // Opcode: DP4_E4M3
/* 2553 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2562
/* 2558 */    MCD::OPC_Decode, 132, 3, 9, // Opcode: CVT_D1_S1_R2
/* 2562 */    MCD::OPC_FilterValue, 3, 152, 6, 0, // Skip to: 4255
/* 2567 */    MCD::OPC_Decode, 178, 3, 9, // Opcode: CVT_D3_S1_R2
/* 2571 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2587
/* 2576 */    MCD::OPC_CheckField, 27, 5, 2, 136, 6, 0, // Skip to: 4255
/* 2583 */    MCD::OPC_Decode, 140, 3, 9, // Opcode: CVT_D1_S2_R2
/* 2587 */    MCD::OPC_FilterValue, 7, 127, 6, 0, // Skip to: 4255
/* 2592 */    MCD::OPC_CheckField, 27, 5, 2, 120, 6, 0, // Skip to: 4255
/* 2599 */    MCD::OPC_Decode, 148, 3, 9, // Opcode: CVT_D1_S3_R2
/* 2603 */    MCD::OPC_FilterValue, 132, 1, 199, 0, 0, // Skip to: 2808
/* 2609 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2612 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 2647
/* 2617 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2620 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2629
/* 2625 */    MCD::OPC_Decode, 132, 4, 11, // Opcode: FMUL_P
/* 2629 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2638
/* 2634 */    MCD::OPC_Decode, 222, 2, 11, // Opcode: CVT_D0_S0_R2_P
/* 2638 */    MCD::OPC_FilterValue, 3, 76, 6, 0, // Skip to: 4255
/* 2643 */    MCD::OPC_Decode, 155, 3, 11, // Opcode: CVT_D2_S0_R2_P
/* 2647 */    MCD::OPC_FilterValue, 1, 21, 0, 0, // Skip to: 2673
/* 2652 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2655 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2664
/* 2660 */    MCD::OPC_Decode, 232, 2, 11, // Opcode: CVT_D0_S1_R2_P
/* 2664 */    MCD::OPC_FilterValue, 3, 50, 6, 0, // Skip to: 4255
/* 2669 */    MCD::OPC_Decode, 163, 3, 11, // Opcode: CVT_D2_S1_R2_P
/* 2673 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2689
/* 2678 */    MCD::OPC_CheckField, 30, 2, 2, 34, 6, 0, // Skip to: 4255
/* 2685 */    MCD::OPC_Decode, 238, 2, 11, // Opcode: CVT_D0_S2_R2_P
/* 2689 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 2715
/* 2694 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2697 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2706
/* 2702 */    MCD::OPC_Decode, 169, 4, 11, // Opcode: MIN_S_P
/* 2706 */    MCD::OPC_FilterValue, 2, 8, 6, 0, // Skip to: 4255
/* 2711 */    MCD::OPC_Decode, 244, 2, 11, // Opcode: CVT_D0_S3_R2_P
/* 2715 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 2750
/* 2720 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2723 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2732
/* 2728 */    MCD::OPC_Decode, 175, 4, 36, // Opcode: MOV_P
/* 2732 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2741
/* 2737 */    MCD::OPC_Decode, 253, 2, 11, // Opcode: CVT_D1_S0_R2_P
/* 2741 */    MCD::OPC_FilterValue, 3, 229, 5, 0, // Skip to: 4255
/* 2746 */    MCD::OPC_Decode, 171, 3, 11, // Opcode: CVT_D3_S0_R2_P
/* 2750 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 2776
/* 2755 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 2758 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2767
/* 2763 */    MCD::OPC_Decode, 133, 3, 11, // Opcode: CVT_D1_S1_R2_P
/* 2767 */    MCD::OPC_FilterValue, 3, 203, 5, 0, // Skip to: 4255
/* 2772 */    MCD::OPC_Decode, 179, 3, 11, // Opcode: CVT_D3_S1_R2_P
/* 2776 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 2792
/* 2781 */    MCD::OPC_CheckField, 30, 2, 2, 187, 5, 0, // Skip to: 4255
/* 2788 */    MCD::OPC_Decode, 141, 3, 11, // Opcode: CVT_D1_S2_R2_P
/* 2792 */    MCD::OPC_FilterValue, 7, 178, 5, 0, // Skip to: 4255
/* 2797 */    MCD::OPC_CheckField, 30, 2, 2, 171, 5, 0, // Skip to: 4255
/* 2804 */    MCD::OPC_Decode, 149, 3, 11, // Opcode: CVT_D1_S3_R2_P
/* 2808 */    MCD::OPC_FilterValue, 140, 1, 30, 0, 0, // Skip to: 2844
/* 2814 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2817 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2826
/* 2822 */    MCD::OPC_Decode, 176, 4, 13, // Opcode: MULI
/* 2826 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2835
/* 2831 */    MCD::OPC_Decode, 174, 2, 13, // Opcode: ANDNI
/* 2835 */    MCD::OPC_FilterValue, 5, 135, 5, 0, // Skip to: 4255
/* 2840 */    MCD::OPC_Decode, 189, 5, 14, // Opcode: UNPACKI
/* 2844 */    MCD::OPC_FilterValue, 144, 1, 21, 0, 0, // Skip to: 2871
/* 2850 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2853 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2862
/* 2858 */    MCD::OPC_Decode, 177, 4, 16, // Opcode: MULI_P
/* 2862 */    MCD::OPC_FilterValue, 2, 108, 5, 0, // Skip to: 4255
/* 2867 */    MCD::OPC_Decode, 175, 2, 16, // Opcode: ANDNI_P
/* 2871 */    MCD::OPC_FilterValue, 152, 1, 87, 0, 0, // Skip to: 2964
/* 2877 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2880 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2896
/* 2885 */    MCD::OPC_CheckField, 23, 4, 0, 83, 5, 0, // Skip to: 4255
/* 2892 */    MCD::OPC_Decode, 202, 4, 19, // Opcode: SETP_EQ
/* 2896 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 2912
/* 2901 */    MCD::OPC_CheckField, 23, 4, 0, 67, 5, 0, // Skip to: 4255
/* 2908 */    MCD::OPC_Decode, 136, 5, 19, // Opcode: SETP_LT_U
/* 2912 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 2938
/* 2917 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2920 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2929
/* 2925 */    MCD::OPC_Decode, 255, 4, 19, // Opcode: SETP_LT_F
/* 2929 */    MCD::OPC_FilterValue, 1, 41, 5, 0, // Skip to: 4255
/* 2934 */    MCD::OPC_Decode, 128, 5, 19, // Opcode: SETP_LT_F1
/* 2938 */    MCD::OPC_FilterValue, 3, 32, 5, 0, // Skip to: 4255
/* 2943 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 2946 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2955
/* 2951 */    MCD::OPC_Decode, 227, 4, 19, // Opcode: SETP_GT_F
/* 2955 */    MCD::OPC_FilterValue, 1, 15, 5, 0, // Skip to: 4255
/* 2960 */    MCD::OPC_Decode, 228, 4, 19, // Opcode: SETP_GT_F1
/* 2964 */    MCD::OPC_FilterValue, 156, 1, 39, 0, 0, // Skip to: 3009
/* 2970 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2973 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2982
/* 2978 */    MCD::OPC_Decode, 209, 4, 20, // Opcode: SETP_EQ_I
/* 2982 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2991
/* 2987 */    MCD::OPC_Decode, 137, 5, 20, // Opcode: SETP_LT_U_I
/* 2991 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3000
/* 2996 */    MCD::OPC_Decode, 130, 5, 20, // Opcode: SETP_LT_F_I
/* 3000 */    MCD::OPC_FilterValue, 3, 226, 4, 0, // Skip to: 4255
/* 3005 */    MCD::OPC_Decode, 230, 4, 20, // Opcode: SETP_GT_F_I
/* 3009 */    MCD::OPC_FilterValue, 160, 1, 39, 0, 0, // Skip to: 3054
/* 3015 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3018 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3027
/* 3023 */    MCD::OPC_Decode, 155, 4, 13, // Opcode: LD_SHARED
/* 3027 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3036
/* 3032 */    MCD::OPC_Decode, 156, 4, 21, // Opcode: LD_SHARED_IDX
/* 3036 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3045
/* 3041 */    MCD::OPC_Decode, 154, 4, 22, // Opcode: LD_PRED_S
/* 3045 */    MCD::OPC_FilterValue, 4, 181, 4, 0, // Skip to: 4255
/* 3050 */    MCD::OPC_Decode, 153, 4, 37, // Opcode: LD_PRED_LOCAL
/* 3054 */    MCD::OPC_FilterValue, 164, 1, 39, 0, 0, // Skip to: 3099
/* 3060 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3063 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3072
/* 3068 */    MCD::OPC_Decode, 192, 2, 25, // Opcode: ATOM_MIN_U_G
/* 3072 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3081
/* 3077 */    MCD::OPC_Decode, 194, 2, 25, // Opcode: ATOM_OR_G
/* 3081 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 3090
/* 3086 */    MCD::OPC_Decode, 193, 2, 25, // Opcode: ATOM_MIN_U_S
/* 3090 */    MCD::OPC_FilterValue, 5, 136, 4, 0, // Skip to: 4255
/* 3095 */    MCD::OPC_Decode, 195, 2, 25, // Opcode: ATOM_OR_S
/* 3099 */    MCD::OPC_FilterValue, 168, 1, 11, 0, 0, // Skip to: 3116
/* 3105 */    MCD::OPC_CheckField, 8, 3, 0, 119, 4, 0, // Skip to: 4255
/* 3112 */    MCD::OPC_Decode, 204, 2, 38, // Opcode: CALL
/* 3116 */    MCD::OPC_FilterValue, 188, 1, 155, 0, 0, // Skip to: 3277
/* 3122 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3125 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 3158
/* 3130 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3133 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3149
/* 3138 */    MCD::OPC_CheckField, 23, 4, 0, 86, 4, 0, // Skip to: 4255
/* 3145 */    MCD::OPC_Decode, 210, 4, 32, // Opcode: SETP_EQ_NP
/* 3149 */    MCD::OPC_FilterValue, 1, 77, 4, 0, // Skip to: 4255
/* 3154 */    MCD::OPC_Decode, 211, 4, 33, // Opcode: SETP_EQ_NPI
/* 3158 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 3191
/* 3163 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3166 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3182
/* 3171 */    MCD::OPC_CheckField, 23, 4, 0, 53, 4, 0, // Skip to: 4255
/* 3178 */    MCD::OPC_Decode, 138, 5, 32, // Opcode: SETP_LT_U_NP
/* 3182 */    MCD::OPC_FilterValue, 1, 44, 4, 0, // Skip to: 4255
/* 3187 */    MCD::OPC_Decode, 139, 5, 33, // Opcode: SETP_LT_U_NPI
/* 3191 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 3234
/* 3196 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3199 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3225
/* 3204 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3207 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3216
/* 3212 */    MCD::OPC_Decode, 131, 5, 32, // Opcode: SETP_LT_F_NP
/* 3216 */    MCD::OPC_FilterValue, 1, 10, 4, 0, // Skip to: 4255
/* 3221 */    MCD::OPC_Decode, 129, 5, 32, // Opcode: SETP_LT_F1_NP
/* 3225 */    MCD::OPC_FilterValue, 1, 1, 4, 0, // Skip to: 4255
/* 3230 */    MCD::OPC_Decode, 132, 5, 33, // Opcode: SETP_LT_F_NPI
/* 3234 */    MCD::OPC_FilterValue, 3, 248, 3, 0, // Skip to: 4255
/* 3239 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 3242 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 3268
/* 3247 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3250 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3259
/* 3255 */    MCD::OPC_Decode, 231, 4, 32, // Opcode: SETP_GT_F_NP
/* 3259 */    MCD::OPC_FilterValue, 1, 223, 3, 0, // Skip to: 4255
/* 3264 */    MCD::OPC_Decode, 229, 4, 32, // Opcode: SETP_GT_F1_NP
/* 3268 */    MCD::OPC_FilterValue, 1, 214, 3, 0, // Skip to: 4255
/* 3273 */    MCD::OPC_Decode, 232, 4, 33, // Opcode: SETP_GT_F_NPI
/* 3277 */    MCD::OPC_FilterValue, 192, 1, 25, 1, 0, // Skip to: 3564
/* 3283 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3286 */    MCD::OPC_FilterValue, 0, 48, 0, 0, // Skip to: 3339
/* 3291 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3294 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3303
/* 3299 */    MCD::OPC_Decode, 178, 4, 9, // Opcode: MUL_HI_S
/* 3303 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3312
/* 3308 */    MCD::OPC_Decode, 251, 3, 9, // Opcode: FFMA_F0
/* 3312 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3321
/* 3317 */    MCD::OPC_Decode, 223, 2, 9, // Opcode: CVT_D0_S0_R3
/* 3321 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3330
/* 3326 */    MCD::OPC_Decode, 156, 3, 9, // Opcode: CVT_D2_S0_R3
/* 3330 */    MCD::OPC_FilterValue, 8, 152, 3, 0, // Skip to: 4255
/* 3335 */    MCD::OPC_Decode, 241, 3, 9, // Opcode: EX2_F32
/* 3339 */    MCD::OPC_FilterValue, 1, 48, 0, 0, // Skip to: 3392
/* 3344 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3347 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3356
/* 3352 */    MCD::OPC_Decode, 170, 2, 9, // Opcode: AND
/* 3356 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3365
/* 3361 */    MCD::OPC_Decode, 242, 3, 9, // Opcode: FABS_F0
/* 3365 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3374
/* 3370 */    MCD::OPC_Decode, 233, 2, 9, // Opcode: CVT_D0_S1_R3
/* 3374 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 3383
/* 3379 */    MCD::OPC_Decode, 164, 3, 9, // Opcode: CVT_D2_S1_R3
/* 3383 */    MCD::OPC_FilterValue, 8, 99, 3, 0, // Skip to: 4255
/* 3388 */    MCD::OPC_Decode, 199, 4, 9, // Opcode: RCP_U32
/* 3392 */    MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 3427
/* 3397 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3400 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3409
/* 3405 */    MCD::OPC_Decode, 151, 5, 9, // Opcode: SHL
/* 3409 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3418
/* 3414 */    MCD::OPC_Decode, 252, 3, 9, // Opcode: FFMA_F1
/* 3418 */    MCD::OPC_FilterValue, 2, 64, 3, 0, // Skip to: 4255
/* 3423 */    MCD::OPC_Decode, 239, 2, 9, // Opcode: CVT_D0_S2_R3
/* 3427 */    MCD::OPC_FilterValue, 3, 30, 0, 0, // Skip to: 3462
/* 3432 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3435 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3444
/* 3440 */    MCD::OPC_Decode, 171, 4, 9, // Opcode: MIN_U
/* 3444 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3453
/* 3449 */    MCD::OPC_Decode, 243, 3, 9, // Opcode: FABS_F1
/* 3453 */    MCD::OPC_FilterValue, 2, 29, 3, 0, // Skip to: 4255
/* 3458 */    MCD::OPC_Decode, 245, 2, 9, // Opcode: CVT_D0_S3_R3
/* 3462 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 3488
/* 3467 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3470 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3479
/* 3475 */    MCD::OPC_Decode, 254, 2, 9, // Opcode: CVT_D1_S0_R3
/* 3479 */    MCD::OPC_FilterValue, 3, 3, 3, 0, // Skip to: 4255
/* 3484 */    MCD::OPC_Decode, 172, 3, 9, // Opcode: CVT_D3_S0_R3
/* 3488 */    MCD::OPC_FilterValue, 5, 39, 0, 0, // Skip to: 3532
/* 3493 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3496 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3505
/* 3501 */    MCD::OPC_Decode, 208, 2, 9, // Opcode: CLZ
/* 3505 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3514
/* 3510 */    MCD::OPC_Decode, 239, 3, 9, // Opcode: DP4_E5M2
/* 3514 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3523
/* 3519 */    MCD::OPC_Decode, 134, 3, 9, // Opcode: CVT_D1_S1_R3
/* 3523 */    MCD::OPC_FilterValue, 3, 215, 2, 0, // Skip to: 4255
/* 3528 */    MCD::OPC_Decode, 180, 3, 9, // Opcode: CVT_D3_S1_R3
/* 3532 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3548
/* 3537 */    MCD::OPC_CheckField, 27, 5, 2, 199, 2, 0, // Skip to: 4255
/* 3544 */    MCD::OPC_Decode, 142, 3, 9, // Opcode: CVT_D1_S2_R3
/* 3548 */    MCD::OPC_FilterValue, 7, 190, 2, 0, // Skip to: 4255
/* 3553 */    MCD::OPC_CheckField, 27, 5, 2, 183, 2, 0, // Skip to: 4255
/* 3560 */    MCD::OPC_Decode, 150, 3, 9, // Opcode: CVT_D1_S3_R3
/* 3564 */    MCD::OPC_FilterValue, 196, 1, 218, 0, 0, // Skip to: 3788
/* 3570 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3573 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 3608
/* 3578 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3581 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3590
/* 3586 */    MCD::OPC_Decode, 179, 4, 11, // Opcode: MUL_HI_S_P
/* 3590 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3599
/* 3595 */    MCD::OPC_Decode, 224, 2, 11, // Opcode: CVT_D0_S0_R3_P
/* 3599 */    MCD::OPC_FilterValue, 3, 139, 2, 0, // Skip to: 4255
/* 3604 */    MCD::OPC_Decode, 157, 3, 11, // Opcode: CVT_D2_S0_R3_P
/* 3608 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 3643
/* 3613 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3616 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3625
/* 3621 */    MCD::OPC_Decode, 176, 2, 11, // Opcode: AND_P
/* 3625 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3634
/* 3630 */    MCD::OPC_Decode, 234, 2, 11, // Opcode: CVT_D0_S1_R3_P
/* 3634 */    MCD::OPC_FilterValue, 3, 104, 2, 0, // Skip to: 4255
/* 3639 */    MCD::OPC_Decode, 165, 3, 11, // Opcode: CVT_D2_S1_R3_P
/* 3643 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3669
/* 3648 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3651 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3660
/* 3656 */    MCD::OPC_Decode, 154, 5, 11, // Opcode: SHL_P
/* 3660 */    MCD::OPC_FilterValue, 2, 78, 2, 0, // Skip to: 4255
/* 3665 */    MCD::OPC_Decode, 240, 2, 11, // Opcode: CVT_D0_S2_R3_P
/* 3669 */    MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 3695
/* 3674 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3677 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3686
/* 3682 */    MCD::OPC_Decode, 172, 4, 11, // Opcode: MIN_U_P
/* 3686 */    MCD::OPC_FilterValue, 2, 52, 2, 0, // Skip to: 4255
/* 3691 */    MCD::OPC_Decode, 246, 2, 11, // Opcode: CVT_D0_S3_R3_P
/* 3695 */    MCD::OPC_FilterValue, 4, 30, 0, 0, // Skip to: 3730
/* 3700 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3703 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3712
/* 3708 */    MCD::OPC_Decode, 201, 4, 11, // Opcode: SEL
/* 3712 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3721
/* 3717 */    MCD::OPC_Decode, 255, 2, 11, // Opcode: CVT_D1_S0_R3_P
/* 3721 */    MCD::OPC_FilterValue, 3, 17, 2, 0, // Skip to: 4255
/* 3726 */    MCD::OPC_Decode, 173, 3, 11, // Opcode: CVT_D3_S0_R3_P
/* 3730 */    MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 3756
/* 3735 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3738 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3747
/* 3743 */    MCD::OPC_Decode, 135, 3, 11, // Opcode: CVT_D1_S1_R3_P
/* 3747 */    MCD::OPC_FilterValue, 3, 247, 1, 0, // Skip to: 4255
/* 3752 */    MCD::OPC_Decode, 181, 3, 11, // Opcode: CVT_D3_S1_R3_P
/* 3756 */    MCD::OPC_FilterValue, 6, 11, 0, 0, // Skip to: 3772
/* 3761 */    MCD::OPC_CheckField, 30, 2, 2, 231, 1, 0, // Skip to: 4255
/* 3768 */    MCD::OPC_Decode, 143, 3, 11, // Opcode: CVT_D1_S2_R3_P
/* 3772 */    MCD::OPC_FilterValue, 7, 222, 1, 0, // Skip to: 4255
/* 3777 */    MCD::OPC_CheckField, 30, 2, 2, 215, 1, 0, // Skip to: 4255
/* 3784 */    MCD::OPC_Decode, 151, 3, 11, // Opcode: CVT_D1_S3_R3_P
/* 3788 */    MCD::OPC_FilterValue, 204, 1, 21, 0, 0, // Skip to: 3815
/* 3794 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3797 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3806
/* 3802 */    MCD::OPC_Decode, 171, 2, 13, // Opcode: ANDI
/* 3806 */    MCD::OPC_FilterValue, 2, 188, 1, 0, // Skip to: 4255
/* 3811 */    MCD::OPC_Decode, 152, 5, 14, // Opcode: SHLI
/* 3815 */    MCD::OPC_FilterValue, 208, 1, 21, 0, 0, // Skip to: 3842
/* 3821 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3824 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3833
/* 3829 */    MCD::OPC_Decode, 172, 2, 16, // Opcode: ANDI_P
/* 3833 */    MCD::OPC_FilterValue, 2, 161, 1, 0, // Skip to: 4255
/* 3838 */    MCD::OPC_Decode, 153, 5, 17, // Opcode: SHLI_P
/* 3842 */    MCD::OPC_FilterValue, 216, 1, 87, 0, 0, // Skip to: 3935
/* 3848 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3851 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 3867
/* 3856 */    MCD::OPC_CheckField, 23, 4, 0, 136, 1, 0, // Skip to: 4255
/* 3863 */    MCD::OPC_Decode, 140, 5, 19, // Opcode: SETP_NE
/* 3867 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 3883
/* 3872 */    MCD::OPC_CheckField, 23, 4, 0, 120, 1, 0, // Skip to: 4255
/* 3879 */    MCD::OPC_Decode, 250, 4, 19, // Opcode: SETP_LE_U
/* 3883 */    MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 3909
/* 3888 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3891 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3900
/* 3896 */    MCD::OPC_Decode, 241, 4, 19, // Opcode: SETP_LE_F
/* 3900 */    MCD::OPC_FilterValue, 1, 94, 1, 0, // Skip to: 4255
/* 3905 */    MCD::OPC_Decode, 242, 4, 19, // Opcode: SETP_LE_F1
/* 3909 */    MCD::OPC_FilterValue, 3, 85, 1, 0, // Skip to: 4255
/* 3914 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 3917 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3926
/* 3922 */    MCD::OPC_Decode, 213, 4, 19, // Opcode: SETP_GE_F
/* 3926 */    MCD::OPC_FilterValue, 1, 68, 1, 0, // Skip to: 4255
/* 3931 */    MCD::OPC_Decode, 214, 4, 19, // Opcode: SETP_GE_F1
/* 3935 */    MCD::OPC_FilterValue, 220, 1, 39, 0, 0, // Skip to: 3980
/* 3941 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3944 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3953
/* 3949 */    MCD::OPC_Decode, 147, 5, 20, // Opcode: SETP_NE_I
/* 3953 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 3962
/* 3958 */    MCD::OPC_Decode, 251, 4, 20, // Opcode: SETP_LE_U_I
/* 3962 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 3971
/* 3967 */    MCD::OPC_Decode, 244, 4, 20, // Opcode: SETP_LE_F_I
/* 3971 */    MCD::OPC_FilterValue, 3, 23, 1, 0, // Skip to: 4255
/* 3976 */    MCD::OPC_Decode, 216, 4, 20, // Opcode: SETP_GE_F_I
/* 3980 */    MCD::OPC_FilterValue, 224, 1, 39, 0, 0, // Skip to: 4025
/* 3986 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 3989 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 3998
/* 3994 */    MCD::OPC_Decode, 179, 5, 13, // Opcode: ST_SHARED
/* 3998 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4007
/* 4003 */    MCD::OPC_Decode, 180, 5, 21, // Opcode: ST_SHARED_IDX
/* 4007 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 4016
/* 4012 */    MCD::OPC_Decode, 178, 5, 22, // Opcode: ST_PRED_S
/* 4016 */    MCD::OPC_FilterValue, 4, 234, 0, 0, // Skip to: 4255
/* 4021 */    MCD::OPC_Decode, 177, 5, 37, // Opcode: ST_PRED_LOCAL
/* 4025 */    MCD::OPC_FilterValue, 228, 1, 39, 0, 0, // Skip to: 4070
/* 4031 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4034 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4043
/* 4039 */    MCD::OPC_Decode, 186, 2, 25, // Opcode: ATOM_MAX_S_G
/* 4043 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4052
/* 4048 */    MCD::OPC_Decode, 196, 2, 25, // Opcode: ATOM_XOR_G
/* 4052 */    MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 4061
/* 4057 */    MCD::OPC_Decode, 187, 2, 25, // Opcode: ATOM_MAX_S_S
/* 4061 */    MCD::OPC_FilterValue, 5, 189, 0, 0, // Skip to: 4255
/* 4066 */    MCD::OPC_Decode, 197, 2, 25, // Opcode: ATOM_XOR_S
/* 4070 */    MCD::OPC_FilterValue, 232, 1, 18, 0, 0, // Skip to: 4094
/* 4076 */    MCD::OPC_CheckField, 27, 5, 0, 172, 0, 0, // Skip to: 4255
/* 4083 */    MCD::OPC_CheckField, 8, 3, 0, 165, 0, 0, // Skip to: 4255
/* 4090 */    MCD::OPC_Decode, 199, 2, 39, // Opcode: BAR_INIT
/* 4094 */    MCD::OPC_FilterValue, 252, 1, 155, 0, 0, // Skip to: 4255
/* 4100 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 4103 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 4136
/* 4108 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4111 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 4127
/* 4116 */    MCD::OPC_CheckField, 23, 4, 0, 132, 0, 0, // Skip to: 4255
/* 4123 */    MCD::OPC_Decode, 148, 5, 32, // Opcode: SETP_NE_NP
/* 4127 */    MCD::OPC_FilterValue, 1, 123, 0, 0, // Skip to: 4255
/* 4132 */    MCD::OPC_Decode, 149, 5, 33, // Opcode: SETP_NE_NPI
/* 4136 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 4169
/* 4141 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4144 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 4160
/* 4149 */    MCD::OPC_CheckField, 23, 4, 0, 99, 0, 0, // Skip to: 4255
/* 4156 */    MCD::OPC_Decode, 252, 4, 32, // Opcode: SETP_LE_U_NP
/* 4160 */    MCD::OPC_FilterValue, 1, 90, 0, 0, // Skip to: 4255
/* 4165 */    MCD::OPC_Decode, 253, 4, 33, // Opcode: SETP_LE_U_NPI
/* 4169 */    MCD::OPC_FilterValue, 2, 38, 0, 0, // Skip to: 4212
/* 4174 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4177 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 4203
/* 4182 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4185 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4194
/* 4190 */    MCD::OPC_Decode, 245, 4, 32, // Opcode: SETP_LE_F_NP
/* 4194 */    MCD::OPC_FilterValue, 1, 56, 0, 0, // Skip to: 4255
/* 4199 */    MCD::OPC_Decode, 243, 4, 32, // Opcode: SETP_LE_F1_NP
/* 4203 */    MCD::OPC_FilterValue, 1, 47, 0, 0, // Skip to: 4255
/* 4208 */    MCD::OPC_Decode, 246, 4, 33, // Opcode: SETP_LE_F_NPI
/* 4212 */    MCD::OPC_FilterValue, 3, 38, 0, 0, // Skip to: 4255
/* 4217 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 4220 */    MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 4246
/* 4225 */    MCD::OPC_ExtractField, 23, 4,  // Inst{26-23} ...
/* 4228 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 4237
/* 4233 */    MCD::OPC_Decode, 217, 4, 32, // Opcode: SETP_GE_F_NP
/* 4237 */    MCD::OPC_FilterValue, 1, 13, 0, 0, // Skip to: 4255
/* 4242 */    MCD::OPC_Decode, 215, 4, 32, // Opcode: SETP_GE_F1_NP
/* 4246 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 4255
/* 4251 */    MCD::OPC_Decode, 218, 4, 33, // Opcode: SETP_GE_F_NPI
/* 4255 */    MCD::OPC_Fail,
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
