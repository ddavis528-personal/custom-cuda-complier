//===-- Interp.cpp - CCV instruction semantics ---------------------------===//
//
// Decoding is not re-implemented here: the simulator drives the disassembler
// that gen-disassembler produces, so this file is semantics only. That is the
// division roadmap F-6 settled on -- the encoder and decoder check each other
// through the round trip, and the simulator checks what the instructions
// actually compute.
//
//===----------------------------------------------------------------------===//

#include "Interp.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/ADT/bit.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/ErrorHandling.h"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <utility>

using namespace llvm;
using namespace ccv;

// §5.1: for .global the AGU computes (rbase << 16) + (rindex << scale) + disp.
// The shift is a property of the address space, not a field. 48 bits exist only
// here -- no register holds more than 32 (invariant 11).
static constexpr unsigned kBaseShift = 16;

static uint32_t regOf(const MCInst &MI, unsigned I) {
  unsigned R = MI.getOperand(I).getReg();
  if (R >= CCV::R0 && R <= CCV::R15)
    return R - CCV::R0;
  return R - CCV::P0; // predicate namespace is separate (invariant 5)
}

/// A predicate qualifier is a 2-bit address plus a negate bit (§1).
static uint32_t guardMask(const Warp &W, uint32_t Q) {
  uint32_t P = W.Pred[Q & 3];
  return (Q & 4) ? ~P : P;
}

/// Bits addressed at a width code: 00 = 32, 01 = 16, 10 = 8, 11 = 4 (§1).
static unsigned widthBits(uint8_t Code) { return 32u >> Code; }

/// A lane's element at the register's current width.
///
/// §1: "Narrow registers occupy a narrower physical slice of a row." The bits
/// above the element are not part of the register at that width, so reading
/// them is meaningless and writing them is not a thing the machine does. The
/// simulator keeps a full uint32_t per lane and masks, which is the same
/// architecture with more storage.
/// A lane's element sign-extended to 32 bits, for the signed operations. A
/// 16-bit -1 is 0x0000FFFF in the register and must reach a 32-bit comparator
/// as 0xFFFFFFFF.
static uint32_t sextTo32(uint32_t V, uint8_t Code) {
  unsigned N = 32u >> Code;
  if (N >= 32)
    return V;
  uint32_t M = 1u << (N - 1);
  return ((V & ((1u << N) - 1)) ^ M) - M;
}

static uint32_t narrow(uint32_t V, uint8_t Code) {
  unsigned N = widthBits(Code);
  return N >= 32 ? V : (V & ((1u << N) - 1));
}

/// Write an element without disturbing the bits above it.
///
/// §1 says a narrow register "occupies a narrower physical slice of a row", so
/// the bits above the element are not part of the register at that width --
/// the machine does not write them, and what a later widening finds there is
/// NOT SPECIFIED anywhere in the document. See F-65.
///
/// Zeroing them would be the convenient choice and would let a kernel depend on
/// zeros the hardware never promised. Preserving them is both closer to a
/// narrower slice of a row and adversarial in the right direction: a program
/// that widens a narrow register and expects zeros sees the old contents
/// instead, deterministically, and fails in the simulator rather than in
/// silicon. Same reasoning as `rcp.u32`'s worst-case seed (O-35).
/// Change a register's element width, clearing the bits a widening exposes.
///
/// **Widening must yield zeros, and this is a hardware requirement rather than
/// a convenience** (O-38, resolving F-65). §1 makes a narrow register "a
/// narrower physical slice of a row", so the bits above the element hold
/// whatever last occupied that slice -- and on a GPU the register file is
/// partitioned between resident warps and reused across kernel launches
/// without clearing. Handing those bits back on a width change is a
/// cross-context read: another warp's data, or the previous kernel's.
///
/// So the newly exposed bits are cleared. The simulator did the opposite at
/// first, on the reasoning that stale bits stop software depending on zeros it
/// was never promised. That reasoning is right in general and wrong here: it
/// optimises against a correctness mistake at the cost of an information leak,
/// and those are not the same size of problem.
static void setWidth(Warp &W, unsigned R, uint8_t NewCode) {
  uint8_t Old = W.ChWidth[R];
  if (NewCode < Old) {                       // smaller code = wider element
    uint32_t Keep = (1u << widthBits(Old)) - 1;
    for (unsigned L = 0; L != kLanes; ++L)
      W.GPR[R][L] &= Keep;
  }
  W.ChWidth[R] = NewCode;
}

static uint32_t writeElem(uint32_t Old, uint32_t V, uint8_t Code) {
  unsigned N = widthBits(Code);
  if (N >= 32)
    return V;
  uint32_t M = (1u << N) - 1;
  return (Old & ~M) | (V & M);
}

/// Opcodes whose semantics below read and write their operands at the
/// register's current width. Everything else is 32-bit-only and the guard in
/// step() stops it rather than letting it compute the wrong thing.
static bool isWidthAware(unsigned Op) {
  switch (Op) {
  case CCV::C_CHWIDTH: case CCV::CHWIDTH_MULTI:
  case CCV::ADD: case CCV::SUB: case CCV::AND: case CCV::OR: case CCV::XOR:
  case CCV::MIN_S: case CCV::MIN_U: case CCV::MAX_S: case CCV::MAX_U:
  case CCV::CVT_SEXT:
  case CCV::ADDI: case CCV::LD_GLOBAL: case CCV::ST_GLOBAL:
  case CCV::LD_GLOBAL_IDX: case CCV::ST_GLOBAL_IDX:
  case CCV::LD_SHARED: case CCV::ST_SHARED:
  case CCV::C_MOV: case CCV::C_EXIT:
    return true;
  default:
    return false;
  }
}

static float bitsToFloat(uint32_t B) { float F; std::memcpy(&F, &B, 4); return F; }
static uint32_t floatToBits(float F) { uint32_t B; std::memcpy(&B, &F, 4); return B; }

/// One lane of a conversion or SFU operation. Lifted out of the dispatch so the
/// Format A′ twins O-34 made possible share the semantics rather than copying
/// them -- a predicated instruction that rounds differently from its base would
/// be invisible until it produced a wrong answer in one lane.
static uint32_t cvtSfuLane(unsigned Op, uint32_t X) {
  float F = bitsToFloat(X);
  switch (Op) {
  case CCV::CVT_F32_S32: return floatToBits(float(int32_t(X)));
  case CCV::CVT_F32_U32: return floatToBits(float(X));
  // Toward zero, and out-of-range saturates rather than trapping -- the same
  // contract §4 gives width mismatches: deterministic garbage, no interlock.
  case CCV::CVT_S32_F32:
    return uint32_t(F >= 2147483647.0f    ? INT32_MAX
                    : F <= -2147483648.0f ? INT32_MIN
                    : std::isnan(F)       ? 0
                                          : int32_t(F));
  case CCV::CVT_U32_F32:
    return F >= 4294967295.0f ? UINT32_MAX
           : (F <= 0.0f || std::isnan(F)) ? 0u
                                          : uint32_t(F);
  // The SFU is specified as correctly-rounded here. Real units are approximate,
  // and the division sequence is written not to depend on more than ~1 ulp --
  // but simulating an approximation would make results unreproducible without
  // pinning a specific hardware's error, which does not exist yet. See O-31.
  // O-35. The simulator returns the WORST value the contract permits, not the
  // exact one.
  //
  // Modelling an exact reciprocal here would let the division sequence pass
  // while depending on precision the hardware never promised -- the checker
  // would be green because it was not looking, which this project has now been
  // caught by five times. Returning the low end of the legal interval means
  // tools/check-div.sh tests the BOUND: if anyone shortens the sequence below
  // what 16 bits supports, it fails immediately rather than in silicon.
  case CCV::RCP_U32: {
    if (X == 0)
      return 0xFFFFFFFFu;                    // udiv by zero is poison anyway
    uint64_t Exact = std::min<uint64_t>((1ull << 32) / X, 0xFFFFFFFFull);
    return uint32_t((Exact * ((1u << 16) - 1)) >> 16);   // exact*(1 - 2^-16)
  }
  case CCV::RCP_F32:   return floatToBits(1.0f / F);
  case CCV::RSQRT_F32: return floatToBits(1.0f / std::sqrt(F));
  case CCV::SQRT_F32:  return floatToBits(std::sqrt(F));
  case CCV::EX2_F32:   return floatToBits(std::exp2f(F));
  case CCV::LG2_F32:   return floatToBits(std::log2f(F));
  case CCV::SIN_F32:   return floatToBits(std::sin(F));
  default:             return floatToBits(std::cos(F));
  }
}



/// Two-source integer ALU, shared by Format A (points 0-17) and Format K's
/// compressed forms, which are the same operations at a different length.
static uint32_t aluRR(unsigned Op, uint32_t X, uint32_t Y) {
  switch (Op) {
  case CCV::ADD:   case CCV::C_ADD:    return X + Y;
  case CCV::SUB:   case CCV::C_SUB:    return X - Y;
  case CCV::AND:   case CCV::C_AND:    return X & Y;
  case CCV::OR:    case CCV::C_OR:     return X | Y;
  case CCV::XOR:   case CCV::C_XOR:    return X ^ Y;
  case CCV::ANDN:  case CCV::C_ANDN:   return X & ~Y;
  case CCV::SHL:   case CCV::C_SHL:    return X << (Y & 31);
  case CCV::SHR:   case CCV::C_SHR:    return X >> (Y & 31);
  case CCV::SRA:   case CCV::C_SRA:    return uint32_t(int32_t(X) >> (Y & 31));
  case CCV::MIN_S: case CCV::C_MIN_S:  return std::min(int32_t(X), int32_t(Y));
  case CCV::MIN_U: case CCV::C_MIN_U:  return std::min(X, Y);
  case CCV::MAX_S: case CCV::C_MAX_S:  return std::max(int32_t(X), int32_t(Y));
  case CCV::MAX_U: case CCV::C_MAX_U:  return std::max(X, Y);
  case CCV::C_MUL_LO:                  return X * Y;
  case CCV::MUL_HI_S:
    return uint32_t((int64_t(int32_t(X)) * int64_t(int32_t(Y))) >> 32);
  case CCV::MUL_HI_U:
    return uint32_t((uint64_t(X) * uint64_t(Y)) >> 32);
  }
  llvm_unreachable("not a two-source integer ALU opcode");
}

static uint32_t aluR(unsigned Op, uint32_t X) {
  switch (Op) {
  case CCV::NEG:  case CCV::C_NEG: return uint32_t(-int32_t(X));
  case CCV::C_NOT:                 return ~X;
  case CCV::ABS:  case CCV::C_ABS:
    return int32_t(X) < 0 ? uint32_t(-int32_t(X)) : X;
  case CCV::POPC: return llvm::popcount(X);
  case CCV::CLZ:  return X ? llvm::countl_zero(X) : 32;
  case CCV::BREV: return llvm::reverseBits<uint32_t>(X);
  }
  llvm_unreachable("not a one-source integer ALU opcode");
}

static uint32_t fpRR(unsigned Op, uint32_t XB, uint32_t YB) {
  float X = bitsToFloat(XB), Y = bitsToFloat(YB);
  switch (Op) {
  case CCV::FADD: case CCV::C_FADD: return floatToBits(X + Y);
  case CCV::FSUB:                   return floatToBits(X - Y);
  case CCV::FMUL: case CCV::C_FMUL: return floatToBits(X * Y);
  case CCV::FMIN: case CCV::C_FMIN: return floatToBits(std::fmin(X, Y));
  case CCV::FMAX: case CCV::C_FMAX: return floatToBits(std::fmax(X, Y));
  }
  llvm_unreachable("not a floating-point ALU opcode");
}

/// The §3 compare map, register and immediate forms alike -- O-26 makes them one
/// opcode map, so they are one function here. Integer eq/ne are sign-agnostic
/// and shared between the signed and unsigned classes, which is why the map
/// needs 16 points rather than 18.
/// Fold an unpredicated (Format C") opcode onto its predicated twin. O-26 made
/// the opcode map shared, so a mnemonic is one relation in all three formats
/// and the semantics table does not need three copies.
static unsigned baseCompare(unsigned Op) {
  switch (Op) {
#define NP(x) case CCV::x##_NP: case CCV::x##_NPI: return CCV::x;
  NP(SETP_LT) NP(SETP_LE) NP(SETP_EQ) NP(SETP_NE) NP(SETP_GT) NP(SETP_GE)
  NP(SETP_LT_U) NP(SETP_LE_U) NP(SETP_GT_U) NP(SETP_GE_U)
  NP(SETP_LT_F) NP(SETP_LE_F) NP(SETP_EQ_F) NP(SETP_NE_F)
  NP(SETP_GT_F) NP(SETP_GE_F)
#undef NP
  default: return Op;
  }
}

static bool compare(unsigned Op, uint32_t XB, uint32_t YB) {
  int32_t SX = int32_t(XB), SY = int32_t(YB);
  float FX = bitsToFloat(XB), FY = bitsToFloat(YB);
  switch (Op) {
  case CCV::SETP_LT:   case CCV::SETP_LT_I:   return SX <  SY;
  case CCV::SETP_LE:   case CCV::SETP_LE_I:   return SX <= SY;
  case CCV::SETP_GT:   case CCV::SETP_GT_I:   return SX >  SY;
  case CCV::SETP_GE:   case CCV::SETP_GE_I:   return SX >= SY;
  case CCV::SETP_EQ:   case CCV::SETP_EQ_I:   return XB == YB;
  case CCV::SETP_NE:   case CCV::SETP_NE_I:   return XB != YB;
  case CCV::SETP_LT_U: case CCV::SETP_LT_U_I: return XB <  YB;
  case CCV::SETP_LE_U: case CCV::SETP_LE_U_I: return XB <= YB;
  case CCV::SETP_GT_U: case CCV::SETP_GT_U_I: return XB >  YB;
  case CCV::SETP_GE_U: case CCV::SETP_GE_U_I: return XB >= YB;
  // Ordered relations: false if either operand is NaN, which C++ gives for
  // free. eq.f is ordered-equal; ne.f is its exact complement, so it is TRUE
  // for NaN -- that pairing is what makes C's float != one instruction (O-26).
  case CCV::SETP_LT_F: case CCV::SETP_LT_F_I: return FX <  FY;
  case CCV::SETP_LE_F: case CCV::SETP_LE_F_I: return FX <= FY;
  case CCV::SETP_GT_F: case CCV::SETP_GT_F_I: return FX >  FY;
  case CCV::SETP_GE_F: case CCV::SETP_GE_F_I: return FX >= FY;
  case CCV::SETP_EQ_F: case CCV::SETP_EQ_F_I: return FX == FY;
  case CCV::SETP_NE_F: case CCV::SETP_NE_F_I: return !(FX == FY);
  }
  llvm_unreachable("not a compare opcode");
}

Interp::Result Interp::step(Warp &W, const MCInst &MI, uint32_t Mask,
                            uint64_t PC, unsigned Size) {
  Result R{Result::Advance, 0};
  const unsigned Op = MI.getOpcode();

  auto forEachLane = [&](auto &&Fn) {
    for (unsigned L = 0; L != kLanes; ++L)
      if (Mask & (1u << L))
        Fn(L);
  };

  // ---- Width-awareness guard (F-3) --------------------------------------
  //
  // Element width is per-register state (invariant 1), so EVERY instruction
  // reading a GPR has to know the width of what it is reading. Most of the
  // semantics below were written when 32 was the only width and read a lane as
  // a bare uint32_t.
  //
  // Rather than let those run and quietly produce 32-bit answers for 16-bit
  // data, an instruction that has not been made width-aware refuses to execute
  // when any GPR it touches is narrow. "Unimplemented" is a stop that names
  // itself; a silent wrong answer is what this project has been bitten by
  // repeatedly, and narrow-width arithmetic is exactly where it would not show.
  if (!isWidthAware(Op))
    for (unsigned I = 0, N = MI.getNumOperands(); I != N; ++I)
      if (MI.getOperand(I).isReg()) {
        unsigned R = regOf(MI, I);
        if (R < kGPRs && W.ChWidth[R] != 0)
          return {Result::Unimplemented, 0};
      }

  switch (Op) {
  // ---- Format F: wide immediate, warp-uniform broadcast (§3) -------------
  case CCV::MOVI:
  case CCV::MOVI48: {
    unsigned D = regOf(MI, 0);
    uint32_t Imm = uint32_t(MI.getOperand(1).getImm());
    forEachLane([&](unsigned L) { W.GPR[D][L] = Imm; });
    break;
  }

  // ---- Format K: srd -- the identity primitive (§5.3) --------------------
  case CCV::SRD: {
    unsigned D = regOf(MI, 0);
    uint32_t Sel = uint32_t(MI.getOperand(1).getImm());
    if (Sel == 0)        // %ctatid: per-lane, the only lane-varying source
      forEachLane([&](unsigned L) { W.GPR[D][L] = W.CtaTid[L]; });
    else if (Sel == 1)   // %ctaid: broadcast
      forEachLane([&](unsigned L) { W.GPR[D][L] = W.CtaId; });
    else
      return {Result::Unimplemented, 0};
    break;
  }

  // ---- Format A: integer, two source (§4 points 0-17) --------------------
  // rs2 is unread by these; the selector ties it to rs0 so it costs no live
  // value. The simulator ignores it for the same reason.
  case CCV::ADD: case CCV::SUB: case CCV::AND: case CCV::OR:
  case CCV::XOR: case CCV::ANDN: case CCV::SHL: case CCV::SHR:
  case CCV::SRA: case CCV::MIN_S: case CCV::MIN_U: case CCV::MAX_S:
  case CCV::MAX_U: case CCV::MUL_HI_S: case CCV::MUL_HI_U: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2);
    // Operands are read AT THEIR REGISTER'S WIDTH and the result is written at
    // the destination's. Narrowing on read rather than on write is what makes
    // `chwidth` a reinterpretation (§3): a register narrowed after being
    // written wide sees only its element, with no instruction in between.
    //
    // Signed operations still need the element sign-extended to 32 before the
    // 32-bit helper sees it, or min.s on 16-bit data compares as unsigned.
    uint8_t WA = W.ChWidth[A], WB = W.ChWidth[B], WD = W.ChWidth[D];
    bool Signed = Op == CCV::MIN_S || Op == CCV::MAX_S || Op == CCV::SRA ||
                  Op == CCV::MUL_HI_S;
    forEachLane([&](unsigned L) {
      uint32_t X = Signed ? sextTo32(W.GPR[A][L], WA) : narrow(W.GPR[A][L], WA);
      uint32_t Y = Signed ? sextTo32(W.GPR[B][L], WB) : narrow(W.GPR[B][L], WB);
      W.GPR[D][L] = writeElem(W.GPR[D][L], aluRR(Op, X, Y), WD);
    });
    break;
  }

  // ---- Format A: integer, one source (§4 points 20-24) -------------------
  case CCV::NEG: case CCV::ABS: case CCV::POPC:
  case CCV::CLZ: case CCV::BREV: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    forEachLane([&](unsigned L) { W.GPR[D][L] = aluR(Op, W.GPR[A][L]); });
    break;
  }

  // §4 point 19. Unlike every other predicated instruction, `sel` writes rd in
  // every lane -- the qualifier picks the source rather than gating the write.
  case CCV::SEL: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), B = regOf(MI, 3);
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm()));
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = ((G >> L) & 1) ? W.GPR[A][L] : W.GPR[B][L];
    });
    break;
  }

  // ---- §4 64-127: conversions, and 256+: SFU (O-31, relocated by O-34) ----
  case CCV::CVT_F32_S32: case CCV::CVT_F32_U32:
  case CCV::CVT_S32_F32: case CCV::CVT_U32_F32:
  case CCV::RCP_F32: case CCV::RSQRT_F32: case CCV::SQRT_F32:
  case CCV::EX2_F32: case CCV::LG2_F32: case CCV::SIN_F32: case CCV::COS_F32:
  case CCV::RCP_U32: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    forEachLane([&](unsigned L) { W.GPR[D][L] = cvtSfuLane(Op, W.GPR[A][L]); });
    break;
  }

  // Format A′ twins. O-34 put conversions inside A′'s 7-bit reach, so the
  // division sequence's two `cvt`s can be masked to lane 0. The SFU is still
  // at 256+ and has no predicated form, which is what is left of F-56.
  case CCV::CVT_F32_S32_P: case CCV::CVT_F32_U32_P:
  case CCV::CVT_S32_F32_P: case CCV::CVT_U32_F32_P:
  case CCV::RCP_F32_P: {          // 48-bit Format A′ sibling, O-37
    static const std::pair<unsigned, unsigned> Map[] = {
        {CCV::CVT_F32_S32_P, CCV::CVT_F32_S32},
        {CCV::CVT_F32_U32_P, CCV::CVT_F32_U32},
        {CCV::CVT_S32_F32_P, CCV::CVT_S32_F32},
        {CCV::CVT_U32_F32_P, CCV::CVT_U32_F32},
        {CCV::RCP_F32_P,     CCV::RCP_F32}};
    unsigned Base = 0;
    for (auto [P, B] : Map) if (P == Op) Base = B;
    unsigned D = regOf(MI, 0), A = regOf(MI, 2);
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm())) & Mask;
    R.Active = G; R.ActiveSet = true;
    forEachLane([&](unsigned L) {
      if ((G >> L) & 1)                 // invariant 10: excluded lanes preserved
        W.GPR[D][L] = cvtSfuLane(Base, W.GPR[A][L]);
    });
    break;
  }

  case CCV::MADLO: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2), C = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = W.GPR[A][L] * W.GPR[B][L] + W.GPR[C][L];
    });
    break;
  }

  // ---- Format A: floating point (§4 points 32-63, format code 0 = FP32) ---
  case CCV::FADD: case CCV::FSUB: case CCV::FMUL:
  case CCV::FMIN: case CCV::FMAX: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = fpRR(Op, W.GPR[A][L], W.GPR[B][L]);
    });
    break;
  }
  case CCV::FNEG_F0: case CCV::FABS_F0: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    forEachLane([&](unsigned L) {
      float X = bitsToFloat(W.GPR[A][L]);
      W.GPR[D][L] = floatToBits(Op == CCV::FNEG_F0 ? -X : std::fabs(X));
    });
    break;
  }
  case CCV::FFMA_F0: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2), C = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      // std::fmaf, not `a * b + c`. The F in `ffma` is FUSED: one rounding of
      // the exact product-plus-addend, not a rounded product plus a rounded
      // sum. It was written unfused when the instruction was added and nothing
      // noticed, because nothing depended on the fusion until the software
      // fp32 divide -- whose correct rounding rests entirely on the residual
      // `fma(-b, q, a)` being exact. 164 of 2048 divisions came out 1 ulp
      // wrong against a model that was right. See F-63.
      W.GPR[D][L] = floatToBits(std::fmaf(bitsToFloat(W.GPR[A][L]),
                                          bitsToFloat(W.GPR[B][L]),
                                          bitsToFloat(W.GPR[C][L])));
    });
    break;
  }

  // ---- Format B: register-immediate --------------------------------------
  case CCV::ADDI:
  case CCV::ADDI48: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    int32_t Imm = int32_t(MI.getOperand(2).getImm());
    uint8_t WA = W.ChWidth[A], WD = W.ChWidth[D];
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = writeElem(W.GPR[D][L],
                              narrow(W.GPR[A][L], WA) + uint32_t(Imm), WD);
    });
    break;
  }

  // ---- Format C / C': compare, writes one bit per lane -------------------
  // Operands are (pd, rd, pq, rs0, rs1|imm). rd is always allocated and the
  // opcode selects whether it is written (§3); none of these write it.
  case CCV::SETP_LT:   case CCV::SETP_LE:   case CCV::SETP_EQ:
  case CCV::SETP_NE:   case CCV::SETP_GT:   case CCV::SETP_GE:
  case CCV::SETP_LT_U: case CCV::SETP_LE_U: case CCV::SETP_GT_U:
  case CCV::SETP_GE_U: case CCV::SETP_LT_F: case CCV::SETP_LE_F:
  case CCV::SETP_EQ_F: case CCV::SETP_NE_F: case CCV::SETP_GT_F:
  case CCV::SETP_GE_F:
  case CCV::SETP_LT_I:   case CCV::SETP_LE_I:   case CCV::SETP_EQ_I:
  case CCV::SETP_NE_I:   case CCV::SETP_GT_I:   case CCV::SETP_GE_I:
  case CCV::SETP_LT_U_I: case CCV::SETP_LE_U_I: case CCV::SETP_GT_U_I:
  case CCV::SETP_GE_U_I: case CCV::SETP_LT_F_I: case CCV::SETP_LE_F_I:
  case CCV::SETP_EQ_F_I: case CCV::SETP_NE_F_I: case CCV::SETP_GT_F_I:
  case CCV::SETP_GE_F_I: {
    unsigned P = regOf(MI, 0), A = regOf(MI, 3);
    bool Imm = MI.getOperand(4).isImm() && !MI.getOperand(4).isReg();
    unsigned B = Imm ? 0 : regOf(MI, 4);
    int32_t IV = Imm ? int32_t(MI.getOperand(4).getImm()) : 0;
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(2).getImm())) & Mask;
    forEachLane([&](unsigned L) {
      if (!((G >> L) & 1)) return;   // invariant 10: excluded lanes preserved
      uint32_t X = W.GPR[A][L];
      uint32_t Y = Imm ? uint32_t(IV) : W.GPR[B][L];
      bool T = compare(Op, X, Y);
      W.Pred[P] = (W.Pred[P] & ~(1u << L)) | (uint32_t(T) << L);
    });
    break;
  }

  case CCV::SETP_LT_NP:   case CCV::SETP_LE_NP:   case CCV::SETP_EQ_NP:
  case CCV::SETP_NE_NP:   case CCV::SETP_GT_NP:   case CCV::SETP_GE_NP:
  case CCV::SETP_LT_U_NP: case CCV::SETP_LE_U_NP: case CCV::SETP_GT_U_NP:
  case CCV::SETP_GE_U_NP: case CCV::SETP_LT_F_NP: case CCV::SETP_LE_F_NP:
  case CCV::SETP_EQ_F_NP: case CCV::SETP_NE_F_NP: case CCV::SETP_GT_F_NP:
  case CCV::SETP_GE_F_NP:
  case CCV::SETP_LT_NPI:   case CCV::SETP_LE_NPI:   case CCV::SETP_EQ_NPI:
  case CCV::SETP_NE_NPI:   case CCV::SETP_GT_NPI:   case CCV::SETP_GE_NPI:
  case CCV::SETP_LT_U_NPI: case CCV::SETP_LE_U_NPI: case CCV::SETP_GT_U_NPI:
  case CCV::SETP_GE_U_NPI: case CCV::SETP_LT_F_NPI: case CCV::SETP_LE_F_NPI:
  case CCV::SETP_EQ_F_NPI: case CCV::SETP_NE_F_NPI: case CCV::SETP_GT_F_NPI:
  case CCV::SETP_GE_F_NPI: {
    // Format C" (O-32): no qualifier, so every lane in the issue mask is
    // written. Lanes OUTSIDE the mask are still preserved -- they are at a
    // different PC and may hold a live predicate (invariant 10 applies to the
    // issue mask, not only to a guard).
    unsigned P = regOf(MI, 0), A = regOf(MI, 2);
    bool Imm = !MI.getOperand(3).isReg();
    unsigned B = Imm ? 0 : regOf(MI, 3);
    int32_t IV = Imm ? int32_t(MI.getOperand(3).getImm()) : 0;
    unsigned Base = baseCompare(Op);
    forEachLane([&](unsigned L) {
      uint32_t X = W.GPR[A][L];
      uint32_t Y = Imm ? uint32_t(IV) : W.GPR[B][L];
      bool T = compare(Base, X, Y);
      W.Pred[P] = (W.Pred[P] & ~(1u << L)) | (uint32_t(T) << L);
    });
    break;
  }


  // ---- Format D: load / store --------------------------------------------
  case CCV::LD_GLOBAL:
  case CCV::ST_GLOBAL: {
    bool IsLoad = Op == CCV::LD_GLOBAL;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1);
    int64_t Off = MI.getOperand(2).getImm();
    // §3: transfer size comes from rdata's chwidth. A narrow load reads only
    // its element's bytes, which is the whole point -- a 16-bit kernel moves
    // half the memory traffic of a 32-bit one.
    unsigned Bytes = widthBits(W.ChWidth[Data]) / 8;
    forEachLane([&](unsigned L) {
      uint64_t A = (uint64_t(W.GPR[Base][L]) << kBaseShift) + Off;
      if (IsLoad) W.GPR[Data][L] =
              writeElem(W.GPR[Data][L], Mem.readN(A, Bytes), W.ChWidth[Data]);
      else        Mem.writeN(A, narrow(W.GPR[Data][L], W.ChWidth[Data]), Bytes);
    });
    break;
  }
  case CCV::LD_GLOBAL_IDX:
  case CCV::ST_GLOBAL_IDX: {
    bool IsLoad = Op == CCV::LD_GLOBAL_IDX;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1), Idx = regOf(MI, 2);
    // O-7: scale is log2(element size) from rdata's chwidth when enabled, so
    // an element index addresses correctly at any width. It only fires when
    // the in-window offset is zero -- see O-23.
    unsigned ScaleEn = unsigned(MI.getOperand(3).getImm());
    int64_t Disp = MI.getOperand(4).getImm();
    // O-39: `rbase` and `rindex` are read at 32 bits whatever their own
    // `chwidth`. They are address components, and invariant 11 keeps addresses
    // out of the element-width model entirely -- only `rdata` is narrow, which
    // is also where §3 takes the scale and the transfer size from.
    unsigned Sh = ScaleEn ? (2 - W.ChWidth[Data]) : 0;
    unsigned Bytes = widthBits(W.ChWidth[Data]) / 8;
    forEachLane([&](unsigned L) {
      uint64_t A = (uint64_t(W.GPR[Base][L]) << kBaseShift) +
                   (uint64_t(W.GPR[Idx][L]) << Sh) + Disp;
      if (IsLoad)
        W.GPR[Data][L] =
            writeElem(W.GPR[Data][L], Mem.readN(A, Bytes), W.ChWidth[Data]);
      else
        Mem.writeN(A, narrow(W.GPR[Data][L], W.ChWidth[Data]), Bytes);
    });
    break;
  }

  // ---- Format D: shared memory -------------------------------------------
  // §5.1: `.shared` does not shift. The AGU computes rbase + (rindex << scale)
  // + disp -- a plain three-input add against a separate flat 32-bit space.
  case CCV::LD_SHARED:
  case CCV::ST_SHARED: {
    bool IsLoad = Op == CCV::LD_SHARED;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1);
    int64_t Off = MI.getOperand(2).getImm();
    forEachLane([&](unsigned L) {
      uint64_t A = uint64_t(W.GPR[Base][L]) + Off;
      if (IsLoad) W.GPR[Data][L] = Shared.read32(A);
      else        Shared.write32(A, W.GPR[Data][L]);
    });
    break;
  }
  case CCV::LD_SHARED_IDX:
  case CCV::ST_SHARED_IDX: {
    bool IsLoad = Op == CCV::LD_SHARED_IDX;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1), Idx = regOf(MI, 2);
    unsigned ScaleEn = unsigned(MI.getOperand(3).getImm());
    int64_t Disp = MI.getOperand(4).getImm();
    // O-7 fires unconditionally for .shared: there is no in-window offset to
    // fold into the index, which is the whole of why it does not fire for
    // unaligned .global (O-23).
    unsigned Sh = ScaleEn ? (2 - W.ChWidth[Data]) : 0;
    forEachLane([&](unsigned L) {
      uint64_t A = uint64_t(W.GPR[Base][L]) + (uint64_t(W.GPR[Idx][L]) << Sh) + Disp;
      if (IsLoad) W.GPR[Data][L] = Shared.read32(A);
      else        Shared.write32(A, W.GPR[Data][L]);
    });
    break;
  }

  // ---- Format K: compressed destructive ALU (rd is read and written) ------
  case CCV::C_ADD:   case CCV::C_SUB:   case CCV::C_MUL_LO: case CCV::C_AND:
  case CCV::C_OR:    case CCV::C_XOR:   case CCV::C_ANDN:   case CCV::C_SHL:
  case CCV::C_SHR:   case CCV::C_SRA:   case CCV::C_MIN_S:  case CCV::C_MIN_U:
  case CCV::C_MAX_S: case CCV::C_MAX_U: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = aluRR(Op, W.GPR[D][L], W.GPR[Sx][L]);
    });
    break;
  }
  case CCV::C_FADD: case CCV::C_FMUL: case CCV::C_FMIN: case CCV::C_FMAX: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = fpRR(Op, W.GPR[D][L], W.GPR[Sx][L]);
    });
    break;
  }
  case CCV::C_ADDI: case CCV::C_SUBI: case CCV::C_ANDI: case CCV::C_ORI:
  case CCV::C_XORI: case CCV::C_SHLI: case CCV::C_SHRI: case CCV::C_SRAI: {
    // The reg-imm points mirror the reg-reg operation, so reuse it. The 4-bit
    // immediate is unsigned (§3).
    static const std::pair<unsigned, unsigned> Map[] = {
        {CCV::C_ADDI, CCV::C_ADD}, {CCV::C_SUBI, CCV::C_SUB},
        {CCV::C_ANDI, CCV::C_AND}, {CCV::C_ORI,  CCV::C_OR},
        {CCV::C_XORI, CCV::C_XOR}, {CCV::C_SHLI, CCV::C_SHL},
        {CCV::C_SHRI, CCV::C_SHR}, {CCV::C_SRAI, CCV::C_SRA}};
    unsigned RR = 0;
    for (auto [I, O] : Map) if (I == Op) RR = O;
    unsigned D = regOf(MI, 0);
    uint32_t Imm = uint32_t(MI.getOperand(2).getImm());
    forEachLane([&](unsigned L) { W.GPR[D][L] = aluRR(RR, W.GPR[D][L], Imm); });
    break;
  }
  case CCV::C_NEG: case CCV::C_NOT: case CCV::C_ABS: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 1);
    forEachLane([&](unsigned L) { W.GPR[D][L] = aluR(Op, W.GPR[Sx][L]); });
    break;
  }
  case CCV::C_MOV: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 1);
    forEachLane([&](unsigned L) { W.GPR[D][L] = W.GPR[Sx][L]; });
    break;
  }

  // ---- Format J: compressed accumulate (rd read and written) -------------
  case CCV::FFMA_ACC_F0: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), B = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = floatToBits(std::fmaf(bitsToFloat(W.GPR[A][L]),
                                          bitsToFloat(W.GPR[B][L]),
                                          bitsToFloat(W.GPR[D][L])));   // fused, F-63
    });
    break;
  }
  case CCV::MAD_ACC: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), B = regOf(MI, 3);
    forEachLane([&](unsigned L) { W.GPR[D][L] += W.GPR[A][L] * W.GPR[B][L]; });
    break;
  }

  // ---- Format I: pmov -- the only constant-to-predicate path (O-14) ------
  case CCV::PMOV_IMM: {
    unsigned D = regOf(MI, 0);
    uint32_t LaneMask = uint32_t(MI.getOperand(1).getImm());
    // Unpredicated and not gated by the issue mask: §3 writes bit n of the
    // immediate to lane n's predicate bit, for all 32 lanes. That is what makes
    // it usable to CREATE a mask -- a value gated by the current mask could not
    // widen one.
    W.Pred[D] = LaneMask;
    break;
  }

  // ---- Format G: shuffle -------------------------------------------------
  case CCV::SHFL_IDX: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 2);
    uint32_t Lane = uint32_t(MI.getOperand(3).getImm()) & 31;
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm())) & Mask;
    R.Active = G; R.ActiveSet = true;
    // The source lane is read whether or not it is ACTIVE. A shuffle reads the
    // register file across lanes; being masked off stops a lane writing, not
    // its register being readable. O-33's broadcast depends on exactly this:
    // lane 0 computes the value and is then excluded from the shuffle that
    // distributes it.
    uint32_t Src = W.GPR[A][Lane];
    forEachLane([&](unsigned L) {
      if ((G >> L) & 1)
        W.GPR[D][L] = Src;
    });
    break;
  }

  // ---- Format D′: predicated load (O-33) ---------------------------------
  case CCV::LD_GLOBAL_P: {
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 2);
    int64_t Off = MI.getOperand(3).getImm();
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm())) & Mask;
    R.Active = G; R.ActiveSet = true;
    forEachLane([&](unsigned L) {
      if (!((G >> L) & 1))
        return;                  // invariant 10: excluded lanes preserved
      W.GPR[Data][L] = Mem.read32((uint64_t(W.GPR[Base][L]) << kBaseShift) + Off);
    });
    break;
  }

  // ---- Format A′: predicated ALU (O-33) ----------------------------------
  case CCV::ADD_P: case CCV::SUB_P: case CCV::AND_P: case CCV::OR_P:
  case CCV::XOR_P: case CCV::SHL_P: case CCV::SHR_P: case CCV::SRA_P:
  case CCV::MIN_S_P: case CCV::MIN_U_P: case CCV::MAX_S_P: case CCV::MAX_U_P:
  case CCV::MUL_HI_S_P: case CCV::MUL_HI_U_P: {
    static const std::pair<unsigned, unsigned> Map[] = {
        {CCV::ADD_P, CCV::ADD}, {CCV::SUB_P, CCV::SUB}, {CCV::AND_P, CCV::AND},
        {CCV::OR_P, CCV::OR},   {CCV::XOR_P, CCV::XOR}, {CCV::SHL_P, CCV::SHL},
        {CCV::SHR_P, CCV::SHR}, {CCV::SRA_P, CCV::SRA},
        {CCV::MIN_S_P, CCV::MIN_S}, {CCV::MIN_U_P, CCV::MIN_U},
        {CCV::MAX_S_P, CCV::MAX_S}, {CCV::MAX_U_P, CCV::MAX_U},
        {CCV::MUL_HI_S_P, CCV::MUL_HI_S}, {CCV::MUL_HI_U_P, CCV::MUL_HI_U}};
    unsigned Base = 0;
    for (auto [P, B] : Map) if (P == Op) Base = B;
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), Bx = regOf(MI, 3);
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm())) & Mask;
    R.Active = G; R.ActiveSet = true;
    forEachLane([&](unsigned L) {
      // Invariant 10: a predicated write preserves the lanes the guard
      // excludes. That is what lets the masked region leave lanes 1-31 holding
      // whatever they held, to be overwritten by the broadcast.
      if ((G >> L) & 1)
        W.GPR[D][L] = aluRR(Base, W.GPR[A][L], W.GPR[Bx][L]);
    });
    break;
  }
  // §4 point 18 under a qualifier. Two-address: rd is tied to the false arm,
  // so invariant 10 -- a predicated write preserves the lanes the guard
  // excludes -- IS the false arm. Nothing writes it and no lane activates for
  // it. That is the whole reason a select does not need `sel` here (F-58).
  case CCV::MOV_P: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 3);
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(2).getImm())) & Mask;
    R.Active = G; R.ActiveSet = true;
    forEachLane([&](unsigned L) {
      if ((G >> L) & 1)
        W.GPR[D][L] = W.GPR[A][L];
    });
    break;
  }
  case CCV::FADD_P: case CCV::FSUB_P: case CCV::FMUL_P: {
    unsigned Base = Op == CCV::FADD_P ? CCV::FADD
                  : Op == CCV::FSUB_P ? CCV::FSUB : CCV::FMUL;
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), Bx = regOf(MI, 3);
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm())) & Mask;
    R.Active = G; R.ActiveSet = true;
    forEachLane([&](unsigned L) {
      if ((G >> L) & 1)
        W.GPR[D][L] = fpRR(Base, W.GPR[A][L], W.GPR[Bx][L]);
    });
    break;
  }
  case CCV::MADLO_P: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), Bx = regOf(MI, 3),
             C = regOf(MI, 4);
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm())) & Mask;
    R.Active = G; R.ActiveSet = true;
    forEachLane([&](unsigned L) {
      if ((G >> L) & 1)
        W.GPR[D][L] = W.GPR[A][L] * W.GPR[Bx][L] + W.GPR[C][L];
    });
    break;
  }

  // §4 point 104: both format codes are "signed integer" and the widths come
  // from the registers' `chwidth`, so this one opcode is s8→s32, s16→s32 and
  // s4→s32 alike. It is `sext`, and the reason `sext` is one instruction where
  // the obvious lowering is three (O-34, O-38, F-66).
  case CCV::CVT_SEXT: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    uint8_t WA = W.ChWidth[A], WD = W.ChWidth[D];
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = writeElem(W.GPR[D][L], sextTo32(W.GPR[A][L], WA), WD);
    });
    break;
  }

  // ---- Width state (§1, invariant 1; F-3) --------------------------------
  //
  // These are the only instructions that change how every other instruction
  // reads its operands. `chwidth` REINTERPRETS the register's existing contents
  // rather than converting them -- §3 is explicit, and it is why the operation
  // drains in-flight dependents. So the bits do not move: what changes is how
  // many of them are the element.
  case CCV::C_CHWIDTH: {
    unsigned D = regOf(MI, 0);
    setWidth(W, D, uint8_t(MI.getOperand(1).getImm() & 3));
    break;
  }
  case CCV::CHWIDTH_MULTI: {
    uint32_t Mask32 = uint32_t(MI.getOperand(0).getImm());
    uint8_t Code = uint8_t(MI.getOperand(1).getImm() & 3);
    for (unsigned R = 0; R != kGPRs; ++R)
      if ((Mask32 >> R) & 1)
        setWidth(W, R, Code);
    break;
  }

  // ---- Format K: predicate logic (O-20) ----------------------------------
  case CCV::PAND:
  case CCV::POR:
  case CCV::PXOR: {
    unsigned D = regOf(MI, 0);
    uint32_t Q0 = uint32_t(MI.getOperand(1).getImm());
    uint32_t Q1 = uint32_t(MI.getOperand(2).getImm());
    // Both sources carry a 2-bit address plus a negate bit, in the same shape
    // as the predicate qualifier.
    uint32_t A = W.Pred[Q0 & 3], B = W.Pred[Q1 & 3];
    if (Q0 & 4) A = ~A;
    if (Q1 & 4) B = ~B;
    uint32_t V = Op == CCV::PAND ? (A & B) : Op == CCV::POR ? (A | B) : (A ^ B);
    W.Pred[D] = (W.Pred[D] & ~Mask) | (V & Mask);
    break;
  }

  // ---- Format E / K: control flow ----------------------------------------
  case CCV::BRA:
  case CCV::C_BRA:
    // Same semantics at both lengths; Size differs, and the offset is in
    // halfwords from the instruction after this one (§3). Which of the two the
    // assembler picked is a layout question (F-28), invisible here.
    R.Kind = Result::Branch;
    R.Target = PC + Size + 2 * MI.getOperand(0).getImm();
    break;
  case CCV::BRA_PRED: {
    uint32_t Q = uint32_t(MI.getOperand(0).getImm());
    uint32_t P = W.Pred[Q & 3];
    if (Q & 4) P = ~P;
    R.Kind = Result::BranchPred;
    R.Target = PC + Size + 2 * MI.getOperand(1).getImm();
    R.TakenMask = P & Mask;
    break;
  }
  // ---- Barriers (O-12, O-27) ---------------------------------------------
  // With per-thread PCs (§1) a barrier is a real synchronisation point between
  // the lanes of one warp, not a formality: lanes reach it at different times
  // and the ones that arrive early have to block. That is why this needs a
  // stall rather than being a no-op on a single-warp simulator.
  case CCV::BAR_INIT:
    // The expected arrival count is configuration for the table entry. Here
    // every active lane is expected, so there is nothing to record.
    break;

  case CCV::C_BAR_ARRIVE: {
    unsigned Id = unsigned(MI.getOperand(0).getImm()) & 0x3f;
    auto &B = W.Bar[Id];
    forEachLane([&](unsigned L) { B.ArrivalEpoch[L] = B.Epoch; });
    B.Arrived |= Mask;
    // Runnable lanes are what the barrier waits for. A lane blocked at THIS
    // barrier is already accounted for; one that has exited never arrives.
    if ((B.Arrived & W.Active) == W.Active) {
      B.Arrived = 0;
      ++B.Epoch;                       // the arrivals retire together
      // Wake everything blocked. A woken lane re-executes its `bar.wait`,
      // which either lets it through (its arrival has now retired) or blocks
      // it again on a different barrier -- so this is correct without
      // tracking which barrier each lane is parked on.
      W.Stalled = 0;
    }
    break;
  }

  case CCV::C_BAR_WAIT: {
    // O-27: the epoch is tracked in hardware, so the wait carries no phase and
    // means "wait until the arrival I just made has retired".
    unsigned Id = unsigned(MI.getOperand(0).getImm()) & 0x3f;
    auto &B = W.Bar[Id];
    uint32_t Blocked = 0;
    forEachLane([&](unsigned L) {
      if (B.Epoch <= B.ArrivalEpoch[L])
        Blocked |= 1u << L;
    });
    if (Blocked) {
      W.Stalled |= Blocked;
      R.Kind = Result::Stall;
      R.TakenMask = Blocked;           // the lanes that did NOT get through
    }
    break;
  }

  case CCV::BAR_WAIT_PHASE: {
    // O-27's explicit form: wait for a named phase rather than for your own
    // arrival. This is what a pipelined producer/consumer needs, where a warp
    // waits on a barrier it did not arrive at.
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(0).getImm())) & Mask;
    unsigned Id = unsigned(MI.getOperand(1).getImm()) & 0x3f;
    unsigned Ps = unsigned(MI.getOperand(2).getImm()) & 3;
    auto &B = W.Bar[Id];
    uint32_t Blocked = 0;
    forEachLane([&](unsigned L) {
      if (!((G >> L) & 1)) return;     // guarded off: not waiting
      unsigned Want = (W.Pred[Ps] >> L) & 1;
      if ((B.Epoch & 1) != Want)
        Blocked |= 1u << L;
    });
    if (Blocked) {
      W.Stalled |= Blocked;
      R.Kind = Result::Stall;
      R.TakenMask = Blocked;
    }
    break;
  }

  case CCV::C_FENCE:
    // Ordering only. A functional simulator with one warp and no store buffer
    // has nothing to order, but it must not be "unimplemented" -- the compiler
    // emits fences around every barrier and atomic sequence (§3).
    break;

  case CCV::C_EXIT:
    R.Kind = Result::Exit;
    break;

  default:
    return {Result::Unimplemented, 0};
  }
  return R;
}
