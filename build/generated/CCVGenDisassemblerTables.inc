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
/* 8 */       MCD::OPC_Decode, 238, 2, 0, // Opcode: FFMA_ACC_F0
/* 12 */      MCD::OPC_FilterValue, 2, 136, 0, 0, // Skip to: 153
/* 17 */      MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 20 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 29
/* 25 */      MCD::OPC_Decode, 189, 2, 1, // Opcode: C_ADD
/* 29 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 38
/* 34 */      MCD::OPC_Decode, 213, 2, 1, // Opcode: C_OR
/* 38 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 47
/* 43 */      MCD::OPC_Decode, 219, 2, 1, // Opcode: C_SHR
/* 47 */      MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 56
/* 52 */      MCD::OPC_Decode, 205, 2, 1, // Opcode: C_MAX_S
/* 56 */      MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 65
/* 61 */      MCD::OPC_Decode, 212, 2, 2, // Opcode: C_NOT
/* 65 */      MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 203, 2, 1, // Opcode: C_FMUL
/* 74 */      MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 83
/* 79 */      MCD::OPC_Decode, 204, 2, 2, // Opcode: C_LD_GLOBAL
/* 83 */      MCD::OPC_FilterValue, 7, 4, 0, 0, // Skip to: 92
/* 88 */      MCD::OPC_Decode, 254, 3, 3, // Opcode: SRD
/* 92 */      MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 101
/* 97 */      MCD::OPC_Decode, 190, 2, 4, // Opcode: C_ADDI
/* 101 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 110
/* 106 */     MCD::OPC_Decode, 227, 2, 4, // Opcode: C_XORI
/* 110 */     MCD::OPC_FilterValue, 12, 11, 0, 0, // Skip to: 126
/* 115 */     MCD::OPC_CheckField, 14, 2, 0, 105, 1, 0, // Skip to: 483
/* 122 */     MCD::OPC_Decode, 197, 2, 5, // Opcode: C_CHWIDTH
/* 126 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 135
/* 131 */     MCD::OPC_Decode, 195, 2, 6, // Opcode: C_BAR_WAIT
/* 135 */     MCD::OPC_FilterValue, 14, 4, 0, 0, // Skip to: 144
/* 140 */     MCD::OPC_Decode, 200, 2, 6, // Opcode: C_FENCE
/* 144 */     MCD::OPC_FilterValue, 15, 78, 1, 0, // Skip to: 483
/* 149 */     MCD::OPC_Decode, 164, 3, 7, // Opcode: PAND
/* 153 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 162
/* 158 */     MCD::OPC_Decode, 239, 2, 0, // Opcode: FFMA_ACC_F1
/* 162 */     MCD::OPC_FilterValue, 6, 102, 0, 0, // Skip to: 269
/* 167 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 170 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 179
/* 175 */     MCD::OPC_Decode, 224, 2, 1, // Opcode: C_SUB
/* 179 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 188
/* 184 */     MCD::OPC_Decode, 226, 2, 1, // Opcode: C_XOR
/* 188 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 197
/* 193 */     MCD::OPC_Decode, 221, 2, 1, // Opcode: C_SRA
/* 197 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 206
/* 202 */     MCD::OPC_Decode, 206, 2, 1, // Opcode: C_MAX_U
/* 206 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 215
/* 211 */     MCD::OPC_Decode, 188, 2, 2, // Opcode: C_ABS
/* 215 */     MCD::OPC_FilterValue, 6, 4, 0, 0, // Skip to: 224
/* 220 */     MCD::OPC_Decode, 223, 2, 2, // Opcode: C_ST_GLOBAL
/* 224 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 233
/* 229 */     MCD::OPC_Decode, 225, 2, 4, // Opcode: C_SUBI
/* 233 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 242
/* 238 */     MCD::OPC_Decode, 218, 2, 4, // Opcode: C_SHLI
/* 242 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 251
/* 247 */     MCD::OPC_Decode, 196, 2, 8, // Opcode: C_BRA
/* 251 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 260
/* 256 */     MCD::OPC_Decode, 216, 2, 6, // Opcode: C_RET
/* 260 */     MCD::OPC_FilterValue, 15, 218, 0, 0, // Skip to: 483
/* 265 */     MCD::OPC_Decode, 168, 3, 7, // Opcode: POR
/* 269 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 278
/* 274 */     MCD::OPC_Decode, 230, 2, 0, // Opcode: DP4_ACC
/* 278 */     MCD::OPC_FilterValue, 10, 93, 0, 0, // Skip to: 376
/* 283 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 286 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 295
/* 291 */     MCD::OPC_Decode, 210, 2, 1, // Opcode: C_MUL_LO
/* 295 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 304
/* 300 */     MCD::OPC_Decode, 193, 2, 1, // Opcode: C_ANDN
/* 304 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 313
/* 309 */     MCD::OPC_Decode, 207, 2, 1, // Opcode: C_MIN_S
/* 313 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 322
/* 318 */     MCD::OPC_Decode, 209, 2, 2, // Opcode: C_MOV
/* 322 */     MCD::OPC_FilterValue, 4, 4, 0, 0, // Skip to: 331
/* 327 */     MCD::OPC_Decode, 199, 2, 1, // Opcode: C_FADD
/* 331 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 340
/* 336 */     MCD::OPC_Decode, 202, 2, 1, // Opcode: C_FMIN
/* 340 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 349
/* 345 */     MCD::OPC_Decode, 192, 2, 4, // Opcode: C_ANDI
/* 349 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 358
/* 354 */     MCD::OPC_Decode, 220, 2, 4, // Opcode: C_SHRI
/* 358 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 367
/* 363 */     MCD::OPC_Decode, 198, 2, 6, // Opcode: C_EXIT
/* 367 */     MCD::OPC_FilterValue, 15, 111, 0, 0, // Skip to: 483
/* 372 */     MCD::OPC_Decode, 169, 3, 7, // Opcode: PXOR
/* 376 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 385
/* 381 */     MCD::OPC_Decode, 135, 3, 0, // Opcode: MAD_ACC
/* 385 */     MCD::OPC_FilterValue, 14, 93, 0, 0, // Skip to: 483
/* 390 */     MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 393 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 402
/* 398 */     MCD::OPC_Decode, 191, 2, 1, // Opcode: C_AND
/* 402 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 411
/* 407 */     MCD::OPC_Decode, 217, 2, 1, // Opcode: C_SHL
/* 411 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 420
/* 416 */     MCD::OPC_Decode, 208, 2, 1, // Opcode: C_MIN_U
/* 420 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 429
/* 425 */     MCD::OPC_Decode, 211, 2, 2, // Opcode: C_NEG
/* 429 */     MCD::OPC_FilterValue, 5, 4, 0, 0, // Skip to: 438
/* 434 */     MCD::OPC_Decode, 201, 2, 1, // Opcode: C_FMAX
/* 438 */     MCD::OPC_FilterValue, 8, 4, 0, 0, // Skip to: 447
/* 443 */     MCD::OPC_Decode, 214, 2, 4, // Opcode: C_ORI
/* 447 */     MCD::OPC_FilterValue, 9, 4, 0, 0, // Skip to: 456
/* 452 */     MCD::OPC_Decode, 222, 2, 4, // Opcode: C_SRAI
/* 456 */     MCD::OPC_FilterValue, 12, 4, 0, 0, // Skip to: 465
/* 461 */     MCD::OPC_Decode, 194, 2, 6, // Opcode: C_BAR_ARRIVE
/* 465 */     MCD::OPC_FilterValue, 13, 4, 0, 0, // Skip to: 474
/* 470 */     MCD::OPC_Decode, 215, 2, 6, // Opcode: C_RECONV
/* 474 */     MCD::OPC_FilterValue, 15, 4, 0, 0, // Skip to: 483
/* 479 */     MCD::OPC_Decode, 165, 3, 7, // Opcode: PMOV
/* 483 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable32[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 3 */       MCD::OPC_FilterValue, 0, 202, 0, 0, // Skip to: 210
/* 8 */       MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 11 */      MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 46
/* 16 */      MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 19 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 28
/* 24 */      MCD::OPC_Decode, 150, 2, 9, // Opcode: ADD
/* 28 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 37
/* 33 */      MCD::OPC_Decode, 236, 2, 9, // Opcode: FADD
/* 37 */      MCD::OPC_FilterValue, 8, 190, 10, 0, // Skip to: 2792
/* 42 */      MCD::OPC_Decode, 170, 3, 9, // Opcode: RCP_F32
/* 46 */      MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 81
/* 51 */      MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 54 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 63
/* 59 */      MCD::OPC_Decode, 153, 3, 9, // Opcode: MUL_HI_U
/* 63 */      MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 72
/* 68 */      MCD::OPC_Decode, 242, 2, 9, // Opcode: FMIN
/* 72 */      MCD::OPC_FilterValue, 8, 155, 10, 0, // Skip to: 2792
/* 77 */      MCD::OPC_Decode, 132, 3, 9, // Opcode: LG2_F32
/* 81 */      MCD::OPC_FilterValue, 2, 30, 0, 0, // Skip to: 116
/* 86 */      MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 89 */      MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 98
/* 94 */      MCD::OPC_Decode, 157, 3, 9, // Opcode: OR
/* 98 */      MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 107
/* 103 */     MCD::OPC_Decode, 179, 2, 9, // Opcode: CVT_F32_S32
/* 107 */     MCD::OPC_FilterValue, 3, 120, 10, 0, // Skip to: 2792
/* 112 */     MCD::OPC_Decode, 185, 2, 10, // Opcode: CVT_SEXT
/* 116 */     MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 142
/* 121 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 124 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 133
/* 129 */     MCD::OPC_Decode, 244, 3, 9, // Opcode: SHR
/* 133 */     MCD::OPC_FilterValue, 2, 94, 10, 0, // Skip to: 2792
/* 138 */     MCD::OPC_Decode, 181, 2, 9, // Opcode: CVT_F32_U32
/* 142 */     MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 168
/* 147 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 150 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 159
/* 155 */     MCD::OPC_Decode, 136, 3, 9, // Opcode: MAX_S
/* 159 */     MCD::OPC_FilterValue, 1, 68, 10, 0, // Skip to: 2792
/* 164 */     MCD::OPC_Decode, 233, 2, 9, // Opcode: DP4_SS
/* 168 */     MCD::OPC_FilterValue, 5, 21, 0, 0, // Skip to: 194
/* 173 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 176 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 185
/* 181 */     MCD::OPC_Decode, 149, 2, 9, // Opcode: ABS
/* 185 */     MCD::OPC_FilterValue, 1, 42, 10, 0, // Skip to: 2792
/* 190 */     MCD::OPC_Decode, 228, 2, 9, // Opcode: DP2_BF16
/* 194 */     MCD::OPC_FilterValue, 6, 33, 10, 0, // Skip to: 2792
/* 199 */     MCD::OPC_CheckField, 27, 5, 0, 26, 10, 0, // Skip to: 2792
/* 206 */     MCD::OPC_Decode, 173, 2, 9, // Opcode: BREV
/* 210 */     MCD::OPC_FilterValue, 4, 113, 0, 0, // Skip to: 328
/* 215 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 218 */     MCD::OPC_FilterValue, 0, 21, 0, 0, // Skip to: 244
/* 223 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 226 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 235
/* 231 */     MCD::OPC_Decode, 156, 2, 11, // Opcode: ADD_P
/* 235 */     MCD::OPC_FilterValue, 1, 248, 9, 0, // Skip to: 2792
/* 240 */     MCD::OPC_Decode, 237, 2, 11, // Opcode: FADD_P
/* 244 */     MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 260
/* 249 */     MCD::OPC_CheckField, 30, 2, 0, 232, 9, 0, // Skip to: 2792
/* 256 */     MCD::OPC_Decode, 154, 3, 11, // Opcode: MUL_HI_U_P
/* 260 */     MCD::OPC_FilterValue, 2, 21, 0, 0, // Skip to: 286
/* 265 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 268 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 277
/* 273 */     MCD::OPC_Decode, 160, 3, 11, // Opcode: OR_P
/* 277 */     MCD::OPC_FilterValue, 2, 206, 9, 0, // Skip to: 2792
/* 282 */     MCD::OPC_Decode, 180, 2, 11, // Opcode: CVT_F32_S32_P
/* 286 */     MCD::OPC_FilterValue, 3, 21, 0, 0, // Skip to: 312
/* 291 */     MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 294 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 303
/* 299 */     MCD::OPC_Decode, 247, 3, 11, // Opcode: SHR_P
/* 303 */     MCD::OPC_FilterValue, 2, 180, 9, 0, // Skip to: 2792
/* 308 */     MCD::OPC_Decode, 182, 2, 11, // Opcode: CVT_F32_U32_P
/* 312 */     MCD::OPC_FilterValue, 4, 171, 9, 0, // Skip to: 2792
/* 317 */     MCD::OPC_CheckField, 30, 2, 0, 164, 9, 0, // Skip to: 2792
/* 324 */     MCD::OPC_Decode, 137, 3, 11, // Opcode: MAX_S_P
/* 328 */     MCD::OPC_FilterValue, 8, 11, 0, 0, // Skip to: 344
/* 333 */     MCD::OPC_CheckField, 8, 3, 0, 148, 9, 0, // Skip to: 2792
/* 340 */     MCD::OPC_Decode, 157, 2, 12, // Opcode: ADD_PP
/* 344 */     MCD::OPC_FilterValue, 12, 39, 0, 0, // Skip to: 388
/* 349 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 352 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 361
/* 357 */     MCD::OPC_Decode, 151, 2, 13, // Opcode: ADDI
/* 361 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 370
/* 366 */     MCD::OPC_Decode, 158, 3, 13, // Opcode: ORI
/* 370 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 379
/* 375 */     MCD::OPC_Decode, 245, 3, 14, // Opcode: SHRI
/* 379 */     MCD::OPC_FilterValue, 5, 104, 9, 0, // Skip to: 2792
/* 384 */     MCD::OPC_Decode, 162, 3, 15, // Opcode: PACKI
/* 388 */     MCD::OPC_FilterValue, 16, 30, 0, 0, // Skip to: 423
/* 393 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 396 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 405
/* 401 */     MCD::OPC_Decode, 153, 2, 16, // Opcode: ADDI_P
/* 405 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 414
/* 410 */     MCD::OPC_Decode, 159, 3, 16, // Opcode: ORI_P
/* 414 */     MCD::OPC_FilterValue, 3, 69, 9, 0, // Skip to: 2792
/* 419 */     MCD::OPC_Decode, 246, 3, 17, // Opcode: SHRI_P
/* 423 */     MCD::OPC_FilterValue, 20, 11, 0, 0, // Skip to: 439
/* 428 */     MCD::OPC_CheckField, 8, 3, 0, 53, 9, 0, // Skip to: 2792
/* 435 */     MCD::OPC_Decode, 154, 2, 18, // Opcode: ADDI_PP
/* 439 */     MCD::OPC_FilterValue, 24, 67, 0, 0, // Skip to: 511
/* 444 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 447 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 463
/* 452 */     MCD::OPC_CheckField, 23, 4, 0, 29, 9, 0, // Skip to: 2792
/* 459 */     MCD::OPC_Decode, 219, 3, 19, // Opcode: SETP_LT
/* 463 */     MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 479
/* 468 */     MCD::OPC_CheckField, 23, 4, 0, 13, 9, 0, // Skip to: 2792
/* 475 */     MCD::OPC_Decode, 195, 3, 19, // Opcode: SETP_GT
/* 479 */     MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 495
/* 484 */     MCD::OPC_CheckField, 23, 4, 0, 253, 8, 0, // Skip to: 2792
/* 491 */     MCD::OPC_Decode, 203, 3, 19, // Opcode: SETP_GT_U
/* 495 */     MCD::OPC_FilterValue, 3, 244, 8, 0, // Skip to: 2792
/* 500 */     MCD::OPC_CheckField, 23, 4, 0, 237, 8, 0, // Skip to: 2792
/* 507 */     MCD::OPC_Decode, 176, 3, 19, // Opcode: SETP_EQ_F
/* 511 */     MCD::OPC_FilterValue, 28, 39, 0, 0, // Skip to: 555
/* 516 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 519 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 528
/* 524 */     MCD::OPC_Decode, 224, 3, 20, // Opcode: SETP_LT_I
/* 528 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 537
/* 533 */     MCD::OPC_Decode, 200, 3, 20, // Opcode: SETP_GT_I
/* 537 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 546
/* 542 */     MCD::OPC_Decode, 204, 3, 20, // Opcode: SETP_GT_U_I
/* 546 */     MCD::OPC_FilterValue, 3, 193, 8, 0, // Skip to: 2792
/* 551 */     MCD::OPC_Decode, 177, 3, 20, // Opcode: SETP_EQ_F_I
/* 555 */     MCD::OPC_FilterValue, 32, 39, 0, 0, // Skip to: 599
/* 560 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 563 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 572
/* 568 */     MCD::OPC_Decode, 248, 2, 13, // Opcode: LD_GLOBAL
/* 572 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 581
/* 577 */     MCD::OPC_Decode, 249, 2, 21, // Opcode: LD_GLOBAL_IDX
/* 581 */     MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 590
/* 586 */     MCD::OPC_Decode, 255, 2, 22, // Opcode: LD_PRED_G
/* 590 */     MCD::OPC_FilterValue, 3, 149, 8, 0, // Skip to: 2792
/* 595 */     MCD::OPC_Decode, 252, 2, 23, // Opcode: LD_GLOBAL_SLOT
/* 599 */     MCD::OPC_FilterValue, 36, 11, 0, 0, // Skip to: 615
/* 604 */     MCD::OPC_CheckField, 8, 3, 0, 133, 8, 0, // Skip to: 2792
/* 611 */     MCD::OPC_Decode, 167, 2, 24, // Opcode: ATOM_ADD_G
/* 615 */     MCD::OPC_FilterValue, 40, 35, 0, 0, // Skip to: 655
/* 620 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 623 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 632
/* 628 */     MCD::OPC_Decode, 171, 2, 25, // Opcode: BRA
/* 632 */     MCD::OPC_FilterValue, 1, 107, 8, 0, // Skip to: 2792
/* 637 */     MCD::OPC_CheckField, 30, 2, 0, 100, 8, 0, // Skip to: 2792
/* 644 */     MCD::OPC_CheckField, 19, 8, 0, 93, 8, 0, // Skip to: 2792
/* 651 */     MCD::OPC_Decode, 170, 2, 26, // Opcode: BAR_WAIT_PHASE
/* 655 */     MCD::OPC_FilterValue, 44, 11, 0, 0, // Skip to: 671
/* 660 */     MCD::OPC_CheckField, 8, 3, 0, 77, 8, 0, // Skip to: 2792
/* 667 */     MCD::OPC_Decode, 146, 3, 27, // Opcode: MOVI
/* 671 */     MCD::OPC_FilterValue, 48, 79, 0, 0, // Skip to: 755
/* 676 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 679 */     MCD::OPC_FilterValue, 0, 18, 0, 0, // Skip to: 702
/* 684 */     MCD::OPC_CheckField, 30, 2, 0, 53, 8, 0, // Skip to: 2792
/* 691 */     MCD::OPC_CheckField, 24, 3, 0, 46, 8, 0, // Skip to: 2792
/* 698 */     MCD::OPC_Decode, 239, 3, 28, // Opcode: SHFL_IDX
/* 702 */     MCD::OPC_FilterValue, 1, 18, 0, 0, // Skip to: 725
/* 707 */     MCD::OPC_CheckField, 22, 5, 0, 30, 8, 0, // Skip to: 2792
/* 714 */     MCD::OPC_CheckField, 11, 8, 0, 23, 8, 0, // Skip to: 2792
/* 721 */     MCD::OPC_Decode, 145, 4, 29, // Opcode: VOTE_ANY
/* 725 */     MCD::OPC_FilterValue, 2, 14, 8, 0, // Skip to: 2792
/* 730 */     MCD::OPC_CheckField, 30, 2, 0, 7, 8, 0, // Skip to: 2792
/* 737 */     MCD::OPC_CheckField, 22, 5, 0, 0, 8, 0, // Skip to: 2792
/* 744 */     MCD::OPC_CheckField, 15, 4, 0, 249, 7, 0, // Skip to: 2792
/* 751 */     MCD::OPC_Decode, 168, 2, 30, // Opcode: BALLOT
/* 755 */     MCD::OPC_FilterValue, 52, 11, 0, 0, // Skip to: 771
/* 760 */     MCD::OPC_CheckField, 8, 3, 0, 233, 7, 0, // Skip to: 2792
/* 767 */     MCD::OPC_Decode, 251, 2, 16, // Opcode: LD_GLOBAL_P
/* 771 */     MCD::OPC_FilterValue, 56, 11, 0, 0, // Skip to: 787
/* 776 */     MCD::OPC_CheckField, 26, 6, 0, 217, 7, 0, // Skip to: 2792
/* 783 */     MCD::OPC_Decode, 176, 2, 31, // Opcode: CHWIDTH_MULTI
/* 787 */     MCD::OPC_FilterValue, 60, 135, 0, 0, // Skip to: 927
/* 792 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 795 */     MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 828
/* 800 */     MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 803 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 819
/* 808 */     MCD::OPC_CheckField, 23, 4, 0, 185, 7, 0, // Skip to: 2792
/* 815 */     MCD::OPC_Decode, 225, 3, 32, // Opcode: SETP_LT_NP
/* 819 */     MCD::OPC_FilterValue, 1, 176, 7, 0, // Skip to: 2792
/* 824 */     MCD::OPC_Decode, 226, 3, 33, // Opcode: SETP_LT_NPI
/* 828 */     MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 861
/* 833 */     MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 836 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 852
/* 841 */     MCD::OPC_CheckField, 23, 4, 0, 152, 7, 0, // Skip to: 2792
/* 848 */     MCD::OPC_Decode, 201, 3, 32, // Opcode: SETP_GT_NP
/* 852 */     MCD::OPC_FilterValue, 1, 143, 7, 0, // Skip to: 2792
/* 857 */     MCD::OPC_Decode, 202, 3, 33, // Opcode: SETP_GT_NPI
/* 861 */     MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 894
/* 866 */     MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 869 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 885
/* 874 */     MCD::OPC_CheckField, 23, 4, 0, 119, 7, 0, // Skip to: 2792
/* 881 */     MCD::OPC_Decode, 205, 3, 32, // Opcode: SETP_GT_U_NP
/* 885 */     MCD::OPC_FilterValue, 1, 110, 7, 0, // Skip to: 2792
/* 890 */     MCD::OPC_Decode, 206, 3, 33, // Opcode: SETP_GT_U_NPI
/* 894 */     MCD::OPC_FilterValue, 3, 101, 7, 0, // Skip to: 2792
/* 899 */     MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 902 */     MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 918
/* 907 */     MCD::OPC_CheckField, 23, 4, 0, 86, 7, 0, // Skip to: 2792
/* 914 */     MCD::OPC_Decode, 178, 3, 32, // Opcode: SETP_EQ_F_NP
/* 918 */     MCD::OPC_FilterValue, 1, 77, 7, 0, // Skip to: 2792
/* 923 */     MCD::OPC_Decode, 179, 3, 33, // Opcode: SETP_EQ_F_NPI
/* 927 */     MCD::OPC_FilterValue, 64, 166, 0, 0, // Skip to: 1098
/* 932 */     MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 935 */     MCD::OPC_FilterValue, 0, 39, 0, 0, // Skip to: 979
/* 940 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 943 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 952
/* 948 */     MCD::OPC_Decode, 138, 4, 9, // Opcode: SUB
/* 952 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 961
/* 957 */     MCD::OPC_Decode, 246, 2, 9, // Opcode: FSUB
/* 961 */     MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 970
/* 966 */     MCD::OPC_Decode, 183, 2, 9, // Opcode: CVT_S32_F32
/* 970 */     MCD::OPC_FilterValue, 8, 25, 7, 0, // Skip to: 2792
/* 975 */     MCD::OPC_Decode, 173, 3, 9, // Opcode: RSQRT_F32
/* 979 */     MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 1014
/* 984 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 987 */     MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 996
/* 992 */     MCD::OPC_Decode, 133, 3, 9, // Opcode: MADLO
/* 996 */     MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1005
/* 1001 */    MCD::OPC_Decode, 241, 2, 9, // Opcode: FMAX
/* 1005 */    MCD::OPC_FilterValue, 8, 246, 6, 0, // Skip to: 2792
/* 1010 */    MCD::OPC_Decode, 248, 3, 9, // Opcode: SIN_F32
/* 1014 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1030
/* 1019 */    MCD::OPC_CheckField, 27, 5, 0, 230, 6, 0, // Skip to: 2792
/* 1026 */    MCD::OPC_Decode, 146, 4, 9, // Opcode: XOR
/* 1030 */    MCD::OPC_FilterValue, 3, 11, 0, 0, // Skip to: 1046
/* 1035 */    MCD::OPC_CheckField, 27, 5, 0, 214, 6, 0, // Skip to: 2792
/* 1042 */    MCD::OPC_Decode, 250, 3, 9, // Opcode: SRA
/* 1046 */    MCD::OPC_FilterValue, 4, 21, 0, 0, // Skip to: 1072
/* 1051 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1054 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1063
/* 1059 */    MCD::OPC_Decode, 139, 3, 9, // Opcode: MAX_U
/* 1063 */    MCD::OPC_FilterValue, 3, 188, 6, 0, // Skip to: 2792
/* 1068 */    MCD::OPC_Decode, 186, 2, 9, // Opcode: CVT_U32_F32
/* 1072 */    MCD::OPC_FilterValue, 5, 179, 6, 0, // Skip to: 2792
/* 1077 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1080 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1089
/* 1085 */    MCD::OPC_Decode, 156, 3, 9, // Opcode: NEG
/* 1089 */    MCD::OPC_FilterValue, 1, 162, 6, 0, // Skip to: 2792
/* 1094 */    MCD::OPC_Decode, 229, 2, 9, // Opcode: DP2_F16
/* 1098 */    MCD::OPC_FilterValue, 68, 112, 0, 0, // Skip to: 1215
/* 1103 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1106 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 1141
/* 1111 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1114 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1123
/* 1119 */    MCD::OPC_Decode, 141, 4, 11, // Opcode: SUB_P
/* 1123 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1132
/* 1128 */    MCD::OPC_Decode, 247, 2, 11, // Opcode: FSUB_P
/* 1132 */    MCD::OPC_FilterValue, 3, 119, 6, 0, // Skip to: 2792
/* 1137 */    MCD::OPC_Decode, 184, 2, 11, // Opcode: CVT_S32_F32_P
/* 1141 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1157
/* 1146 */    MCD::OPC_CheckField, 30, 2, 0, 103, 6, 0, // Skip to: 2792
/* 1153 */    MCD::OPC_Decode, 134, 3, 11, // Opcode: MADLO_P
/* 1157 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1173
/* 1162 */    MCD::OPC_CheckField, 30, 2, 0, 87, 6, 0, // Skip to: 2792
/* 1169 */    MCD::OPC_Decode, 149, 4, 11, // Opcode: XOR_P
/* 1173 */    MCD::OPC_FilterValue, 3, 11, 0, 0, // Skip to: 1189
/* 1178 */    MCD::OPC_CheckField, 30, 2, 0, 71, 6, 0, // Skip to: 2792
/* 1185 */    MCD::OPC_Decode, 253, 3, 11, // Opcode: SRA_P
/* 1189 */    MCD::OPC_FilterValue, 4, 62, 6, 0, // Skip to: 2792
/* 1194 */    MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 1197 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1206
/* 1202 */    MCD::OPC_Decode, 140, 3, 11, // Opcode: MAX_U_P
/* 1206 */    MCD::OPC_FilterValue, 3, 45, 6, 0, // Skip to: 2792
/* 1211 */    MCD::OPC_Decode, 187, 2, 11, // Opcode: CVT_U32_F32_P
/* 1215 */    MCD::OPC_FilterValue, 76, 39, 0, 0, // Skip to: 1259
/* 1220 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1223 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1232
/* 1228 */    MCD::OPC_Decode, 139, 4, 13, // Opcode: SUBI
/* 1232 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1241
/* 1237 */    MCD::OPC_Decode, 147, 4, 13, // Opcode: XORI
/* 1241 */    MCD::OPC_FilterValue, 3, 4, 0, 0, // Skip to: 1250
/* 1246 */    MCD::OPC_Decode, 251, 3, 14, // Opcode: SRAI
/* 1250 */    MCD::OPC_FilterValue, 5, 1, 6, 0, // Skip to: 2792
/* 1255 */    MCD::OPC_Decode, 163, 3, 14, // Opcode: PACKI_Z
/* 1259 */    MCD::OPC_FilterValue, 80, 30, 0, 0, // Skip to: 1294
/* 1264 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1267 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1276
/* 1272 */    MCD::OPC_Decode, 140, 4, 16, // Opcode: SUBI_P
/* 1276 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1285
/* 1281 */    MCD::OPC_Decode, 148, 4, 16, // Opcode: XORI_P
/* 1285 */    MCD::OPC_FilterValue, 3, 222, 5, 0, // Skip to: 2792
/* 1290 */    MCD::OPC_Decode, 252, 3, 17, // Opcode: SRAI_P
/* 1294 */    MCD::OPC_FilterValue, 88, 67, 0, 0, // Skip to: 1366
/* 1299 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1302 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1318
/* 1307 */    MCD::OPC_CheckField, 23, 4, 0, 198, 5, 0, // Skip to: 2792
/* 1314 */    MCD::OPC_Decode, 207, 3, 19, // Opcode: SETP_LE
/* 1318 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1334
/* 1323 */    MCD::OPC_CheckField, 23, 4, 0, 182, 5, 0, // Skip to: 2792
/* 1330 */    MCD::OPC_Decode, 183, 3, 19, // Opcode: SETP_GE
/* 1334 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1350
/* 1339 */    MCD::OPC_CheckField, 23, 4, 0, 166, 5, 0, // Skip to: 2792
/* 1346 */    MCD::OPC_Decode, 191, 3, 19, // Opcode: SETP_GE_U
/* 1350 */    MCD::OPC_FilterValue, 3, 157, 5, 0, // Skip to: 2792
/* 1355 */    MCD::OPC_CheckField, 23, 4, 0, 150, 5, 0, // Skip to: 2792
/* 1362 */    MCD::OPC_Decode, 232, 3, 19, // Opcode: SETP_NE_F
/* 1366 */    MCD::OPC_FilterValue, 92, 39, 0, 0, // Skip to: 1410
/* 1371 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1374 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1383
/* 1379 */    MCD::OPC_Decode, 212, 3, 20, // Opcode: SETP_LE_I
/* 1383 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1392
/* 1388 */    MCD::OPC_Decode, 188, 3, 20, // Opcode: SETP_GE_I
/* 1392 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1401
/* 1397 */    MCD::OPC_Decode, 192, 3, 20, // Opcode: SETP_GE_U_I
/* 1401 */    MCD::OPC_FilterValue, 3, 106, 5, 0, // Skip to: 2792
/* 1406 */    MCD::OPC_Decode, 233, 3, 20, // Opcode: SETP_NE_F_I
/* 1410 */    MCD::OPC_FilterValue, 96, 39, 0, 0, // Skip to: 1454
/* 1415 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1418 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1427
/* 1423 */    MCD::OPC_Decode, 255, 3, 13, // Opcode: ST_GLOBAL
/* 1427 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1436
/* 1432 */    MCD::OPC_Decode, 128, 4, 21, // Opcode: ST_GLOBAL_IDX
/* 1436 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1445
/* 1441 */    MCD::OPC_Decode, 133, 4, 22, // Opcode: ST_PRED_G
/* 1445 */    MCD::OPC_FilterValue, 3, 62, 5, 0, // Skip to: 2792
/* 1450 */    MCD::OPC_Decode, 130, 4, 23, // Opcode: ST_GLOBAL_SLOT
/* 1454 */    MCD::OPC_FilterValue, 104, 11, 0, 0, // Skip to: 1470
/* 1459 */    MCD::OPC_CheckField, 8, 3, 0, 46, 5, 0, // Skip to: 2792
/* 1466 */    MCD::OPC_Decode, 172, 2, 34, // Opcode: BRA_PRED
/* 1470 */    MCD::OPC_FilterValue, 112, 18, 0, 0, // Skip to: 1493
/* 1475 */    MCD::OPC_CheckField, 19, 8, 0, 30, 5, 0, // Skip to: 2792
/* 1482 */    MCD::OPC_CheckField, 8, 7, 2, 23, 5, 0, // Skip to: 2792
/* 1489 */    MCD::OPC_Decode, 143, 4, 35, // Opcode: UNBALLOT
/* 1493 */    MCD::OPC_FilterValue, 124, 135, 0, 0, // Skip to: 1633
/* 1498 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1501 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 1534
/* 1506 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1509 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1525
/* 1514 */    MCD::OPC_CheckField, 23, 4, 0, 247, 4, 0, // Skip to: 2792
/* 1521 */    MCD::OPC_Decode, 213, 3, 32, // Opcode: SETP_LE_NP
/* 1525 */    MCD::OPC_FilterValue, 1, 238, 4, 0, // Skip to: 2792
/* 1530 */    MCD::OPC_Decode, 214, 3, 33, // Opcode: SETP_LE_NPI
/* 1534 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 1567
/* 1539 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1542 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1558
/* 1547 */    MCD::OPC_CheckField, 23, 4, 0, 214, 4, 0, // Skip to: 2792
/* 1554 */    MCD::OPC_Decode, 189, 3, 32, // Opcode: SETP_GE_NP
/* 1558 */    MCD::OPC_FilterValue, 1, 205, 4, 0, // Skip to: 2792
/* 1563 */    MCD::OPC_Decode, 190, 3, 33, // Opcode: SETP_GE_NPI
/* 1567 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 1600
/* 1572 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1575 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1591
/* 1580 */    MCD::OPC_CheckField, 23, 4, 0, 181, 4, 0, // Skip to: 2792
/* 1587 */    MCD::OPC_Decode, 193, 3, 32, // Opcode: SETP_GE_U_NP
/* 1591 */    MCD::OPC_FilterValue, 1, 172, 4, 0, // Skip to: 2792
/* 1596 */    MCD::OPC_Decode, 194, 3, 33, // Opcode: SETP_GE_U_NPI
/* 1600 */    MCD::OPC_FilterValue, 3, 163, 4, 0, // Skip to: 2792
/* 1605 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 1608 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1624
/* 1613 */    MCD::OPC_CheckField, 23, 4, 0, 148, 4, 0, // Skip to: 2792
/* 1620 */    MCD::OPC_Decode, 234, 3, 32, // Opcode: SETP_NE_F_NP
/* 1624 */    MCD::OPC_FilterValue, 1, 139, 4, 0, // Skip to: 2792
/* 1629 */    MCD::OPC_Decode, 235, 3, 33, // Opcode: SETP_NE_F_NPI
/* 1633 */    MCD::OPC_FilterValue, 128, 1, 122, 0, 0, // Skip to: 1761
/* 1639 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1642 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 1677
/* 1647 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1650 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1659
/* 1655 */    MCD::OPC_Decode, 155, 3, 9, // Opcode: MUL_LO
/* 1659 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1668
/* 1664 */    MCD::OPC_Decode, 243, 2, 9, // Opcode: FMUL
/* 1668 */    MCD::OPC_FilterValue, 8, 95, 4, 0, // Skip to: 2792
/* 1673 */    MCD::OPC_Decode, 249, 3, 9, // Opcode: SQRT_F32
/* 1677 */    MCD::OPC_FilterValue, 1, 21, 0, 0, // Skip to: 1703
/* 1682 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1685 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1694
/* 1690 */    MCD::OPC_Decode, 245, 2, 9, // Opcode: FNEG_F0
/* 1694 */    MCD::OPC_FilterValue, 8, 69, 4, 0, // Skip to: 2792
/* 1699 */    MCD::OPC_Decode, 178, 2, 9, // Opcode: COS_F32
/* 1703 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1719
/* 1708 */    MCD::OPC_CheckField, 27, 5, 0, 53, 4, 0, // Skip to: 2792
/* 1715 */    MCD::OPC_Decode, 162, 2, 9, // Opcode: ANDN
/* 1719 */    MCD::OPC_FilterValue, 3, 11, 0, 0, // Skip to: 1735
/* 1724 */    MCD::OPC_CheckField, 27, 5, 0, 37, 4, 0, // Skip to: 2792
/* 1731 */    MCD::OPC_Decode, 141, 3, 9, // Opcode: MIN_S
/* 1735 */    MCD::OPC_FilterValue, 5, 28, 4, 0, // Skip to: 2792
/* 1740 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 1743 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1752
/* 1748 */    MCD::OPC_Decode, 167, 3, 9, // Opcode: POPC
/* 1752 */    MCD::OPC_FilterValue, 1, 11, 4, 0, // Skip to: 2792
/* 1757 */    MCD::OPC_Decode, 231, 2, 9, // Opcode: DP4_E4M3
/* 1761 */    MCD::OPC_FilterValue, 132, 1, 51, 0, 0, // Skip to: 1818
/* 1767 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1770 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1786
/* 1775 */    MCD::OPC_CheckField, 30, 2, 1, 242, 3, 0, // Skip to: 2792
/* 1782 */    MCD::OPC_Decode, 244, 2, 11, // Opcode: FMUL_P
/* 1786 */    MCD::OPC_FilterValue, 3, 11, 0, 0, // Skip to: 1802
/* 1791 */    MCD::OPC_CheckField, 30, 2, 0, 226, 3, 0, // Skip to: 2792
/* 1798 */    MCD::OPC_Decode, 142, 3, 11, // Opcode: MIN_S_P
/* 1802 */    MCD::OPC_FilterValue, 4, 217, 3, 0, // Skip to: 2792
/* 1807 */    MCD::OPC_CheckField, 30, 2, 0, 210, 3, 0, // Skip to: 2792
/* 1814 */    MCD::OPC_Decode, 148, 3, 36, // Opcode: MOV_P
/* 1818 */    MCD::OPC_FilterValue, 140, 1, 30, 0, 0, // Skip to: 1854
/* 1824 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1827 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1836
/* 1832 */    MCD::OPC_Decode, 149, 3, 13, // Opcode: MULI
/* 1836 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1845
/* 1841 */    MCD::OPC_Decode, 163, 2, 13, // Opcode: ANDNI
/* 1845 */    MCD::OPC_FilterValue, 5, 174, 3, 0, // Skip to: 2792
/* 1850 */    MCD::OPC_Decode, 144, 4, 14, // Opcode: UNPACKI
/* 1854 */    MCD::OPC_FilterValue, 144, 1, 21, 0, 0, // Skip to: 1881
/* 1860 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1863 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1872
/* 1868 */    MCD::OPC_Decode, 150, 3, 16, // Opcode: MULI_P
/* 1872 */    MCD::OPC_FilterValue, 2, 147, 3, 0, // Skip to: 2792
/* 1877 */    MCD::OPC_Decode, 164, 2, 16, // Opcode: ANDNI_P
/* 1881 */    MCD::OPC_FilterValue, 152, 1, 67, 0, 0, // Skip to: 1954
/* 1887 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1890 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 1906
/* 1895 */    MCD::OPC_CheckField, 23, 4, 0, 122, 3, 0, // Skip to: 2792
/* 1902 */    MCD::OPC_Decode, 175, 3, 19, // Opcode: SETP_EQ
/* 1906 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 1922
/* 1911 */    MCD::OPC_CheckField, 23, 4, 0, 106, 3, 0, // Skip to: 2792
/* 1918 */    MCD::OPC_Decode, 227, 3, 19, // Opcode: SETP_LT_U
/* 1922 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 1938
/* 1927 */    MCD::OPC_CheckField, 23, 4, 0, 90, 3, 0, // Skip to: 2792
/* 1934 */    MCD::OPC_Decode, 220, 3, 19, // Opcode: SETP_LT_F
/* 1938 */    MCD::OPC_FilterValue, 3, 81, 3, 0, // Skip to: 2792
/* 1943 */    MCD::OPC_CheckField, 23, 4, 0, 74, 3, 0, // Skip to: 2792
/* 1950 */    MCD::OPC_Decode, 196, 3, 19, // Opcode: SETP_GT_F
/* 1954 */    MCD::OPC_FilterValue, 156, 1, 39, 0, 0, // Skip to: 1999
/* 1960 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1963 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 1972
/* 1968 */    MCD::OPC_Decode, 180, 3, 20, // Opcode: SETP_EQ_I
/* 1972 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 1981
/* 1977 */    MCD::OPC_Decode, 228, 3, 20, // Opcode: SETP_LT_U_I
/* 1981 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 1990
/* 1986 */    MCD::OPC_Decode, 221, 3, 20, // Opcode: SETP_LT_F_I
/* 1990 */    MCD::OPC_FilterValue, 3, 29, 3, 0, // Skip to: 2792
/* 1995 */    MCD::OPC_Decode, 197, 3, 20, // Opcode: SETP_GT_F_I
/* 1999 */    MCD::OPC_FilterValue, 160, 1, 30, 0, 0, // Skip to: 2035
/* 2005 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2008 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2017
/* 2013 */    MCD::OPC_Decode, 129, 3, 13, // Opcode: LD_SHARED
/* 2017 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2026
/* 2022 */    MCD::OPC_Decode, 130, 3, 21, // Opcode: LD_SHARED_IDX
/* 2026 */    MCD::OPC_FilterValue, 2, 249, 2, 0, // Skip to: 2792
/* 2031 */    MCD::OPC_Decode, 128, 3, 22, // Opcode: LD_PRED_S
/* 2035 */    MCD::OPC_FilterValue, 168, 1, 11, 0, 0, // Skip to: 2052
/* 2041 */    MCD::OPC_CheckField, 8, 3, 0, 232, 2, 0, // Skip to: 2792
/* 2048 */    MCD::OPC_Decode, 174, 2, 37, // Opcode: CALL
/* 2052 */    MCD::OPC_FilterValue, 188, 1, 135, 0, 0, // Skip to: 2193
/* 2058 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2061 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2094
/* 2066 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2069 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2085
/* 2074 */    MCD::OPC_CheckField, 23, 4, 0, 199, 2, 0, // Skip to: 2792
/* 2081 */    MCD::OPC_Decode, 181, 3, 32, // Opcode: SETP_EQ_NP
/* 2085 */    MCD::OPC_FilterValue, 1, 190, 2, 0, // Skip to: 2792
/* 2090 */    MCD::OPC_Decode, 182, 3, 33, // Opcode: SETP_EQ_NPI
/* 2094 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2127
/* 2099 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2102 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2118
/* 2107 */    MCD::OPC_CheckField, 23, 4, 0, 166, 2, 0, // Skip to: 2792
/* 2114 */    MCD::OPC_Decode, 229, 3, 32, // Opcode: SETP_LT_U_NP
/* 2118 */    MCD::OPC_FilterValue, 1, 157, 2, 0, // Skip to: 2792
/* 2123 */    MCD::OPC_Decode, 230, 3, 33, // Opcode: SETP_LT_U_NPI
/* 2127 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2160
/* 2132 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2135 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2151
/* 2140 */    MCD::OPC_CheckField, 23, 4, 0, 133, 2, 0, // Skip to: 2792
/* 2147 */    MCD::OPC_Decode, 222, 3, 32, // Opcode: SETP_LT_F_NP
/* 2151 */    MCD::OPC_FilterValue, 1, 124, 2, 0, // Skip to: 2792
/* 2156 */    MCD::OPC_Decode, 223, 3, 33, // Opcode: SETP_LT_F_NPI
/* 2160 */    MCD::OPC_FilterValue, 3, 115, 2, 0, // Skip to: 2792
/* 2165 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2168 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2184
/* 2173 */    MCD::OPC_CheckField, 23, 4, 0, 100, 2, 0, // Skip to: 2792
/* 2180 */    MCD::OPC_Decode, 198, 3, 32, // Opcode: SETP_GT_F_NP
/* 2184 */    MCD::OPC_FilterValue, 1, 91, 2, 0, // Skip to: 2792
/* 2189 */    MCD::OPC_Decode, 199, 3, 33, // Opcode: SETP_GT_F_NPI
/* 2193 */    MCD::OPC_FilterValue, 192, 1, 131, 0, 0, // Skip to: 2330
/* 2199 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2202 */    MCD::OPC_FilterValue, 0, 30, 0, 0, // Skip to: 2237
/* 2207 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2210 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2219
/* 2215 */    MCD::OPC_Decode, 151, 3, 9, // Opcode: MUL_HI_S
/* 2219 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2228
/* 2224 */    MCD::OPC_Decode, 240, 2, 9, // Opcode: FFMA_F0
/* 2228 */    MCD::OPC_FilterValue, 8, 47, 2, 0, // Skip to: 2792
/* 2233 */    MCD::OPC_Decode, 234, 2, 9, // Opcode: EX2_F32
/* 2237 */    MCD::OPC_FilterValue, 1, 30, 0, 0, // Skip to: 2272
/* 2242 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2245 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2254
/* 2250 */    MCD::OPC_Decode, 159, 2, 9, // Opcode: AND
/* 2254 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2263
/* 2259 */    MCD::OPC_Decode, 235, 2, 9, // Opcode: FABS_F0
/* 2263 */    MCD::OPC_FilterValue, 8, 12, 2, 0, // Skip to: 2792
/* 2268 */    MCD::OPC_Decode, 172, 3, 9, // Opcode: RCP_U32
/* 2272 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2288
/* 2277 */    MCD::OPC_CheckField, 27, 5, 0, 252, 1, 0, // Skip to: 2792
/* 2284 */    MCD::OPC_Decode, 240, 3, 9, // Opcode: SHL
/* 2288 */    MCD::OPC_FilterValue, 3, 11, 0, 0, // Skip to: 2304
/* 2293 */    MCD::OPC_CheckField, 27, 5, 0, 236, 1, 0, // Skip to: 2792
/* 2300 */    MCD::OPC_Decode, 144, 3, 9, // Opcode: MIN_U
/* 2304 */    MCD::OPC_FilterValue, 5, 227, 1, 0, // Skip to: 2792
/* 2309 */    MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 2312 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2321
/* 2317 */    MCD::OPC_Decode, 177, 2, 9, // Opcode: CLZ
/* 2321 */    MCD::OPC_FilterValue, 1, 210, 1, 0, // Skip to: 2792
/* 2326 */    MCD::OPC_Decode, 232, 2, 9, // Opcode: DP4_E5M2
/* 2330 */    MCD::OPC_FilterValue, 196, 1, 83, 0, 0, // Skip to: 2419
/* 2336 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2339 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2355
/* 2344 */    MCD::OPC_CheckField, 30, 2, 0, 185, 1, 0, // Skip to: 2792
/* 2351 */    MCD::OPC_Decode, 152, 3, 11, // Opcode: MUL_HI_S_P
/* 2355 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 2371
/* 2360 */    MCD::OPC_CheckField, 30, 2, 0, 169, 1, 0, // Skip to: 2792
/* 2367 */    MCD::OPC_Decode, 165, 2, 11, // Opcode: AND_P
/* 2371 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2387
/* 2376 */    MCD::OPC_CheckField, 30, 2, 0, 153, 1, 0, // Skip to: 2792
/* 2383 */    MCD::OPC_Decode, 243, 3, 11, // Opcode: SHL_P
/* 2387 */    MCD::OPC_FilterValue, 3, 11, 0, 0, // Skip to: 2403
/* 2392 */    MCD::OPC_CheckField, 30, 2, 0, 137, 1, 0, // Skip to: 2792
/* 2399 */    MCD::OPC_Decode, 145, 3, 11, // Opcode: MIN_U_P
/* 2403 */    MCD::OPC_FilterValue, 4, 128, 1, 0, // Skip to: 2792
/* 2408 */    MCD::OPC_CheckField, 30, 2, 0, 121, 1, 0, // Skip to: 2792
/* 2415 */    MCD::OPC_Decode, 174, 3, 11, // Opcode: SEL
/* 2419 */    MCD::OPC_FilterValue, 204, 1, 21, 0, 0, // Skip to: 2446
/* 2425 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2428 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2437
/* 2433 */    MCD::OPC_Decode, 160, 2, 13, // Opcode: ANDI
/* 2437 */    MCD::OPC_FilterValue, 2, 94, 1, 0, // Skip to: 2792
/* 2442 */    MCD::OPC_Decode, 241, 3, 14, // Opcode: SHLI
/* 2446 */    MCD::OPC_FilterValue, 208, 1, 21, 0, 0, // Skip to: 2473
/* 2452 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2455 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2464
/* 2460 */    MCD::OPC_Decode, 161, 2, 16, // Opcode: ANDI_P
/* 2464 */    MCD::OPC_FilterValue, 2, 67, 1, 0, // Skip to: 2792
/* 2469 */    MCD::OPC_Decode, 242, 3, 17, // Opcode: SHLI_P
/* 2473 */    MCD::OPC_FilterValue, 216, 1, 67, 0, 0, // Skip to: 2546
/* 2479 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2482 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2498
/* 2487 */    MCD::OPC_CheckField, 23, 4, 0, 42, 1, 0, // Skip to: 2792
/* 2494 */    MCD::OPC_Decode, 231, 3, 19, // Opcode: SETP_NE
/* 2498 */    MCD::OPC_FilterValue, 1, 11, 0, 0, // Skip to: 2514
/* 2503 */    MCD::OPC_CheckField, 23, 4, 0, 26, 1, 0, // Skip to: 2792
/* 2510 */    MCD::OPC_Decode, 215, 3, 19, // Opcode: SETP_LE_U
/* 2514 */    MCD::OPC_FilterValue, 2, 11, 0, 0, // Skip to: 2530
/* 2519 */    MCD::OPC_CheckField, 23, 4, 0, 10, 1, 0, // Skip to: 2792
/* 2526 */    MCD::OPC_Decode, 208, 3, 19, // Opcode: SETP_LE_F
/* 2530 */    MCD::OPC_FilterValue, 3, 1, 1, 0, // Skip to: 2792
/* 2535 */    MCD::OPC_CheckField, 23, 4, 0, 250, 0, 0, // Skip to: 2792
/* 2542 */    MCD::OPC_Decode, 184, 3, 19, // Opcode: SETP_GE_F
/* 2546 */    MCD::OPC_FilterValue, 220, 1, 39, 0, 0, // Skip to: 2591
/* 2552 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2555 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2564
/* 2560 */    MCD::OPC_Decode, 236, 3, 20, // Opcode: SETP_NE_I
/* 2564 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2573
/* 2569 */    MCD::OPC_Decode, 216, 3, 20, // Opcode: SETP_LE_U_I
/* 2573 */    MCD::OPC_FilterValue, 2, 4, 0, 0, // Skip to: 2582
/* 2578 */    MCD::OPC_Decode, 209, 3, 20, // Opcode: SETP_LE_F_I
/* 2582 */    MCD::OPC_FilterValue, 3, 205, 0, 0, // Skip to: 2792
/* 2587 */    MCD::OPC_Decode, 185, 3, 20, // Opcode: SETP_GE_F_I
/* 2591 */    MCD::OPC_FilterValue, 224, 1, 30, 0, 0, // Skip to: 2627
/* 2597 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2600 */    MCD::OPC_FilterValue, 0, 4, 0, 0, // Skip to: 2609
/* 2605 */    MCD::OPC_Decode, 135, 4, 13, // Opcode: ST_SHARED
/* 2609 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2618
/* 2614 */    MCD::OPC_Decode, 136, 4, 21, // Opcode: ST_SHARED_IDX
/* 2618 */    MCD::OPC_FilterValue, 2, 169, 0, 0, // Skip to: 2792
/* 2623 */    MCD::OPC_Decode, 134, 4, 22, // Opcode: ST_PRED_S
/* 2627 */    MCD::OPC_FilterValue, 232, 1, 18, 0, 0, // Skip to: 2651
/* 2633 */    MCD::OPC_CheckField, 27, 5, 0, 152, 0, 0, // Skip to: 2792
/* 2640 */    MCD::OPC_CheckField, 8, 3, 0, 145, 0, 0, // Skip to: 2792
/* 2647 */    MCD::OPC_Decode, 169, 2, 38, // Opcode: BAR_INIT
/* 2651 */    MCD::OPC_FilterValue, 252, 1, 135, 0, 0, // Skip to: 2792
/* 2657 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 2660 */    MCD::OPC_FilterValue, 0, 28, 0, 0, // Skip to: 2693
/* 2665 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2668 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2684
/* 2673 */    MCD::OPC_CheckField, 23, 4, 0, 112, 0, 0, // Skip to: 2792
/* 2680 */    MCD::OPC_Decode, 237, 3, 32, // Opcode: SETP_NE_NP
/* 2684 */    MCD::OPC_FilterValue, 1, 103, 0, 0, // Skip to: 2792
/* 2689 */    MCD::OPC_Decode, 238, 3, 33, // Opcode: SETP_NE_NPI
/* 2693 */    MCD::OPC_FilterValue, 1, 28, 0, 0, // Skip to: 2726
/* 2698 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2701 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2717
/* 2706 */    MCD::OPC_CheckField, 23, 4, 0, 79, 0, 0, // Skip to: 2792
/* 2713 */    MCD::OPC_Decode, 217, 3, 32, // Opcode: SETP_LE_U_NP
/* 2717 */    MCD::OPC_FilterValue, 1, 70, 0, 0, // Skip to: 2792
/* 2722 */    MCD::OPC_Decode, 218, 3, 33, // Opcode: SETP_LE_U_NPI
/* 2726 */    MCD::OPC_FilterValue, 2, 28, 0, 0, // Skip to: 2759
/* 2731 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2734 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2750
/* 2739 */    MCD::OPC_CheckField, 23, 4, 0, 46, 0, 0, // Skip to: 2792
/* 2746 */    MCD::OPC_Decode, 210, 3, 32, // Opcode: SETP_LE_F_NP
/* 2750 */    MCD::OPC_FilterValue, 1, 37, 0, 0, // Skip to: 2792
/* 2755 */    MCD::OPC_Decode, 211, 3, 33, // Opcode: SETP_LE_F_NPI
/* 2759 */    MCD::OPC_FilterValue, 3, 28, 0, 0, // Skip to: 2792
/* 2764 */    MCD::OPC_ExtractField, 27, 3,  // Inst{29-27} ...
/* 2767 */    MCD::OPC_FilterValue, 0, 11, 0, 0, // Skip to: 2783
/* 2772 */    MCD::OPC_CheckField, 23, 4, 0, 13, 0, 0, // Skip to: 2792
/* 2779 */    MCD::OPC_Decode, 186, 3, 32, // Opcode: SETP_GE_F_NP
/* 2783 */    MCD::OPC_FilterValue, 1, 4, 0, 0, // Skip to: 2792
/* 2788 */    MCD::OPC_Decode, 187, 3, 33, // Opcode: SETP_GE_F_NPI
/* 2792 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable48[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 3 */       MCD::OPC_FilterValue, 7, 18, 0, 0, // Skip to: 26
/* 8 */       MCD::OPC_CheckField, 30, 18, 8, 75, 0, 0, // Skip to: 90
/* 15 */      MCD::OPC_CheckField, 8, 3, 0, 68, 0, 0, // Skip to: 90
/* 22 */      MCD::OPC_Decode, 171, 3, 11, // Opcode: RCP_F32_P
/* 26 */      MCD::OPC_FilterValue, 15, 11, 0, 0, // Skip to: 42
/* 31 */      MCD::OPC_CheckField, 8, 3, 0, 52, 0, 0, // Skip to: 90
/* 38 */      MCD::OPC_Decode, 152, 2, 39, // Opcode: ADDI48
/* 42 */      MCD::OPC_FilterValue, 39, 11, 0, 0, // Skip to: 58
/* 47 */      MCD::OPC_CheckField, 8, 3, 4, 36, 0, 0, // Skip to: 90
/* 54 */      MCD::OPC_Decode, 175, 2, 40, // Opcode: CAS_G
/* 58 */      MCD::OPC_FilterValue, 47, 11, 0, 0, // Skip to: 74
/* 63 */      MCD::OPC_CheckField, 8, 3, 0, 20, 0, 0, // Skip to: 90
/* 70 */      MCD::OPC_Decode, 147, 3, 41, // Opcode: MOVI48
/* 74 */      MCD::OPC_FilterValue, 123, 11, 0, 0, // Skip to: 90
/* 79 */      MCD::OPC_CheckField, 10, 6, 0, 4, 0, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 166, 3, 42, // Opcode: PMOV_IMM
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
