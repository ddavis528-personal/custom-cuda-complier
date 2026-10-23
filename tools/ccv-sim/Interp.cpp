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
#include "NarrowFP.h"
#include "SfuMath.h"
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

// O-45: the AGU reads a window index straight out of the launch block, so the
// simulator needs the block's address and argument offset -- architectural
// facts under §5.2, not tool configuration.
//
// This is the THIRD copy of these two numbers: CCVLowerKernelArgs.cpp has them
// as the kernel-argument ABI, CCVFrameLowering.cpp has the base again for the
// `.local` window, and now the AGU model needs both. tools/check-launch-abi.sh
// requires all three to agree, because an ABI constant that disagrees with
// itself produces a kernel that reads the wrong argument and nothing that looks
// like a compile error.
static constexpr uint64_t kLaunchBase = 0x20000;
uint64_t launchBlockBase() { return kLaunchBase; }

/// O-69: lane L's byte B of the warp's interleaved spill frame.
uint64_t Interp::localAddr(const Warp &W, uint64_t B, unsigned L) {
  uint64_t LocalBase = Mem.peek32(kLaunchBase + 24);
  return ((LocalBase + LaneContexts) << 16) + (uint64_t(W.WarpCtx) << 22) +
         128 * (B / 4) + 4 * L + B % 4;
}
static constexpr unsigned kOffArgs    = 32;
// Eight, matching the compiler: a slot names a window word and §5.2 puts those
// 8 bytes apart (DA's response CP-4, 2026-10-08). If this disagrees with the
// ISel matcher the oracle reads a different argument than the hardware would,
// which is the one disagreement no kernel test can catch -- hence the fourth
// constant in check-launch-abi.sh.
static constexpr unsigned kSlotStride = 8;

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

/// O-67, the mixed-width rule: a source read at its operation's operating
/// width OpW (the destination's chwidth, or rs0's for a compare) is its raw
/// element at its own width Src, zero-extended or truncated to OpW as a bit
/// field. Never converted. A narrower source's missing bits are zero, not a
/// neighbouring section's (OI-29).
static uint32_t opnd(uint32_t V, uint8_t Src, uint8_t OpW) {
  if (nfp::TestByValue)
    return narrow(V, Src);
  return narrow(V, std::max(Src, OpW));   // the larger code is the narrower
}
/// The same, then read as signed at the operating width.
static uint32_t opndS(uint32_t V, uint8_t Src, uint8_t OpW) {
  if (nfp::TestByValue)
    return sextTo32(V, Src);
  return sextTo32(opnd(V, Src, OpW), OpW);
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
static unsigned baseCompare(unsigned Op);   // defined with the compare map below

static bool isWidthAware(unsigned Op) {
  switch (Op) {
  case CCV::C_CHWIDTH: case CCV::CHWIDTH_MULTI:
  case CCV::ADD: case CCV::SUB: case CCV::AND: case CCV::OR: case CCV::XOR:
  case CCV::MIN_S: case CCV::MIN_U: case CCV::MAX_S: case CCV::MAX_U:
  case CCV::CVT_SEXT:
  case CCV::ADDI: case CCV::MUL_LO:
  case CCV::SUBI: case CCV::MULI: case CCV::ANDI: case CCV::ORI:
  case CCV::XORI: case CCV::ANDNI: case CCV::SHLI: case CCV::SHRI:
  case CCV::SRAI:
  case CCV::LD_GLOBAL: case CCV::ST_GLOBAL:
  case CCV::LD_LOCAL: case CCV::ST_LOCAL:
  case CCV::C_LD_GLOBAL: case CCV::C_ST_GLOBAL:
  case CCV::LD_GLOBAL_IDX: case CCV::ST_GLOBAL_IDX:
  case CCV::LD_GLOBAL_SLOT: case CCV::ST_GLOBAL_SLOT:
  case CCV::LD_SHARED: case CCV::ST_SHARED:
  case CCV::MAD_ACC:
  case CCV::DP2_BF16: case CCV::DP2_F16:
  case CCV::DP4_E4M3: case CCV::DP4_E5M2:
  case CCV::MOVI: case CCV::MOVI48:
  case CCV::C_MOV: case CCV::C_EXIT:
  // Format K's destructive ALU, the points whose uncompressed forms are above:
  // the compressor turns 16-bit `or` into C_OR once i16 code reaches it (the
  // CoreMark-derived port), so these read and write at width the same way.
  case CCV::C_ADD: case CCV::C_SUB: case CCV::C_MUL_LO: case CCV::C_AND:
  case CCV::C_OR: case CCV::C_XOR: case CCV::C_MIN_S: case CCV::C_MIN_U:
  case CCV::C_MAX_S: case CCV::C_MAX_U:
  case CCV::C_ADDI: case CCV::C_SUBI: case CCV::C_ANDI: case CCV::C_ORI:
  case CCV::C_XORI: case CCV::C_SHLI: case CCV::C_SHRI: case CCV::C_SRAI:
  // Predicate logic reads and writes only predicates. Its operands are P
  // numbers, which the guard below would read as GPR numbers, refusing a
  // `pxor p0, ...` whenever r0 happened to be narrow.
  case CCV::PAND: case CCV::POR: case CCV::PXOR: case CCV::PMOV:
  case CCV::PMOV_IMM:
    return true;
  default:
    break;
  }
  // The compares, both formats. Added only once they actually read their
  // operands at the register's width and refuse narrow FP -- a whitelist entry
  // in front of 32-bit-only code is how `ld.shared` came to vouch for itself
  // while calling read32 (F-67, twice).
  switch (baseCompare(Op)) {
  case CCV::SETP_LT: case CCV::SETP_LE: case CCV::SETP_EQ:
  case CCV::SETP_NE: case CCV::SETP_GT: case CCV::SETP_GE:
  case CCV::SETP_LT_U: case CCV::SETP_LE_U:
  case CCV::SETP_GT_U: case CCV::SETP_GE_U:
  case CCV::SETP_LT_F: case CCV::SETP_LE_F: case CCV::SETP_EQ_F:
  case CCV::SETP_NE_F: case CCV::SETP_GT_F: case CCV::SETP_GE_F:
  case CCV::SETP_LT_F1: case CCV::SETP_LE_F1: case CCV::SETP_EQ_F1:
  case CCV::SETP_NE_F1: case CCV::SETP_GT_F1: case CCV::SETP_GE_F1:
    return true;
  default:
    return false;
  }
}

static float bitsToFloat(uint32_t B) { float F; std::memcpy(&F, &B, 4); return F; }
static uint32_t floatToBits(float F) { uint32_t B; std::memcpy(&B, &F, 4); return B; }
static Interp::Result formatFault(uint32_t Mask) {
  Interp::Result F{Interp::Result::Fault, 0};
  F.Cause = "F-FORMAT";
  F.TakenMask = Mask;
  return F;
}
/// An FP32 arithmetic result's bits, a NaN made canonical (O-66): positive,
/// every mantissa bit set, NVIDIA's value, whatever the host produced (x86's
/// default NaN is 0xFFC00000) and whatever payload an operand carried. Moves,
/// fneg, fabs and fmin/fmax's pass-through of a number keep their bits.
static uint32_t fpBits(float F) {
  return std::isnan(F) && !nfp::TestHostNaN ? 0x7fffffffu : floatToBits(F);
}

// ---- CP-6: the FP block and the conversions at every width ---------------
//
// Where an FP instruction keeps its operands, and what it does, for the
// generic path through NarrowFP.h. That path takes every execution that
// touches a register below 32 bits, format code 1, or a conversion without a
// host form below; an FP32-only execution keeps the host paths in the switch,
// so every oracle written before narrow FP is unchanged.
namespace {
struct FpInfo {
  enum Kind { None, Bin, Un, Fma, Cvt } K = None;
  unsigned Base = 0;      // FADD, FSUB, FMUL, FMIN, FMAX, FNEG_F0, FABS_F0, FFMA_F0
  unsigned Code = 0;      // the FP format code, for Bin, Un and Fma
  unsigned Dst = 0, Src = 0, Rnd = 0;   // for Cvt: format codes and rounding
  int D = 0, A = -1, B = -1, C = -1;    // operand indices; C is the addend
  int Qual = -1;          // the predicate qualifier's operand, if predicated
  bool HostForm = false;  // FP32-only executions keep a host path
};

struct CvtRow { unsigned Op, D, S, R; bool Pred; };
const CvtRow CvtTable[] = {
    {CCV::CVT_D0_S0_R0, 0, 0, 0, false}, {CCV::CVT_D0_S0_R0_P, 0, 0, 0, true},
    {CCV::CVT_D0_S0_R1, 0, 0, 1, false}, {CCV::CVT_D0_S0_R1_P, 0, 0, 1, true},
    {CCV::CVT_D0_S0_R2, 0, 0, 2, false}, {CCV::CVT_D0_S0_R2_P, 0, 0, 2, true},
    {CCV::CVT_D0_S0_R3, 0, 0, 3, false}, {CCV::CVT_D0_S0_R3_P, 0, 0, 3, true},
    {CCV::CVT_D0_S1_R0, 0, 1, 0, false}, {CCV::CVT_D0_S1_R0_P, 0, 1, 0, true},
    {CCV::CVT_D0_S1_R1, 0, 1, 1, false}, {CCV::CVT_D0_S1_R1_P, 0, 1, 1, true},
    {CCV::CVT_D0_S1_R2, 0, 1, 2, false}, {CCV::CVT_D0_S1_R2_P, 0, 1, 2, true},
    {CCV::CVT_D0_S1_R3, 0, 1, 3, false}, {CCV::CVT_D0_S1_R3_P, 0, 1, 3, true},
    {CCV::CVT_F32_S32, 0, 2, 0, false}, {CCV::CVT_F32_S32_P, 0, 2, 0, true},
    {CCV::CVT_D0_S2_R1, 0, 2, 1, false}, {CCV::CVT_D0_S2_R1_P, 0, 2, 1, true},
    {CCV::CVT_D0_S2_R2, 0, 2, 2, false}, {CCV::CVT_D0_S2_R2_P, 0, 2, 2, true},
    {CCV::CVT_D0_S2_R3, 0, 2, 3, false}, {CCV::CVT_D0_S2_R3_P, 0, 2, 3, true},
    {CCV::CVT_F32_U32, 0, 3, 0, false}, {CCV::CVT_F32_U32_P, 0, 3, 0, true},
    {CCV::CVT_D0_S3_R1, 0, 3, 1, false}, {CCV::CVT_D0_S3_R1_P, 0, 3, 1, true},
    {CCV::CVT_D0_S3_R2, 0, 3, 2, false}, {CCV::CVT_D0_S3_R2_P, 0, 3, 2, true},
    {CCV::CVT_D0_S3_R3, 0, 3, 3, false}, {CCV::CVT_D0_S3_R3_P, 0, 3, 3, true},
    {CCV::CVT_D1_S0_R0, 1, 0, 0, false}, {CCV::CVT_D1_S0_R0_P, 1, 0, 0, true},
    {CCV::CVT_D1_S0_R1, 1, 0, 1, false}, {CCV::CVT_D1_S0_R1_P, 1, 0, 1, true},
    {CCV::CVT_D1_S0_R2, 1, 0, 2, false}, {CCV::CVT_D1_S0_R2_P, 1, 0, 2, true},
    {CCV::CVT_D1_S0_R3, 1, 0, 3, false}, {CCV::CVT_D1_S0_R3_P, 1, 0, 3, true},
    {CCV::CVT_D1_S1_R0, 1, 1, 0, false}, {CCV::CVT_D1_S1_R0_P, 1, 1, 0, true},
    {CCV::CVT_D1_S1_R1, 1, 1, 1, false}, {CCV::CVT_D1_S1_R1_P, 1, 1, 1, true},
    {CCV::CVT_D1_S1_R2, 1, 1, 2, false}, {CCV::CVT_D1_S1_R2_P, 1, 1, 2, true},
    {CCV::CVT_D1_S1_R3, 1, 1, 3, false}, {CCV::CVT_D1_S1_R3_P, 1, 1, 3, true},
    {CCV::CVT_D1_S2_R0, 1, 2, 0, false}, {CCV::CVT_D1_S2_R0_P, 1, 2, 0, true},
    {CCV::CVT_D1_S2_R1, 1, 2, 1, false}, {CCV::CVT_D1_S2_R1_P, 1, 2, 1, true},
    {CCV::CVT_D1_S2_R2, 1, 2, 2, false}, {CCV::CVT_D1_S2_R2_P, 1, 2, 2, true},
    {CCV::CVT_D1_S2_R3, 1, 2, 3, false}, {CCV::CVT_D1_S2_R3_P, 1, 2, 3, true},
    {CCV::CVT_D1_S3_R0, 1, 3, 0, false}, {CCV::CVT_D1_S3_R0_P, 1, 3, 0, true},
    {CCV::CVT_D1_S3_R1, 1, 3, 1, false}, {CCV::CVT_D1_S3_R1_P, 1, 3, 1, true},
    {CCV::CVT_D1_S3_R2, 1, 3, 2, false}, {CCV::CVT_D1_S3_R2_P, 1, 3, 2, true},
    {CCV::CVT_D1_S3_R3, 1, 3, 3, false}, {CCV::CVT_D1_S3_R3_P, 1, 3, 3, true},
    {CCV::CVT_D2_S0_R0, 2, 0, 0, false}, {CCV::CVT_D2_S0_R0_P, 2, 0, 0, true},
    {CCV::CVT_S32_F32, 2, 0, 1, false}, {CCV::CVT_S32_F32_P, 2, 0, 1, true},
    {CCV::CVT_D2_S0_R2, 2, 0, 2, false}, {CCV::CVT_D2_S0_R2_P, 2, 0, 2, true},
    {CCV::CVT_D2_S0_R3, 2, 0, 3, false}, {CCV::CVT_D2_S0_R3_P, 2, 0, 3, true},
    {CCV::CVT_D2_S1_R0, 2, 1, 0, false}, {CCV::CVT_D2_S1_R0_P, 2, 1, 0, true},
    {CCV::CVT_D2_S1_R1, 2, 1, 1, false}, {CCV::CVT_D2_S1_R1_P, 2, 1, 1, true},
    {CCV::CVT_D2_S1_R2, 2, 1, 2, false}, {CCV::CVT_D2_S1_R2_P, 2, 1, 2, true},
    {CCV::CVT_D2_S1_R3, 2, 1, 3, false}, {CCV::CVT_D2_S1_R3_P, 2, 1, 3, true},
    {CCV::CVT_SEXT, 2, 2, 0, false},
    {CCV::CVT_D2_S3_R0, 2, 3, 0, false}, {CCV::CVT_D2_S3_R0_P, 2, 3, 0, true},
    {CCV::CVT_D3_S0_R0, 3, 0, 0, false}, {CCV::CVT_D3_S0_R0_P, 3, 0, 0, true},
    {CCV::CVT_U32_F32, 3, 0, 1, false}, {CCV::CVT_U32_F32_P, 3, 0, 1, true},
    {CCV::CVT_D3_S0_R2, 3, 0, 2, false}, {CCV::CVT_D3_S0_R2_P, 3, 0, 2, true},
    {CCV::CVT_D3_S0_R3, 3, 0, 3, false}, {CCV::CVT_D3_S0_R3_P, 3, 0, 3, true},
    {CCV::CVT_D3_S1_R0, 3, 1, 0, false}, {CCV::CVT_D3_S1_R0_P, 3, 1, 0, true},
    {CCV::CVT_D3_S1_R1, 3, 1, 1, false}, {CCV::CVT_D3_S1_R1_P, 3, 1, 1, true},
    {CCV::CVT_D3_S1_R2, 3, 1, 2, false}, {CCV::CVT_D3_S1_R2_P, 3, 1, 2, true},
    {CCV::CVT_D3_S1_R3, 3, 1, 3, false}, {CCV::CVT_D3_S1_R3_P, 3, 1, 3, true},
    {CCV::CVT_D3_S2_R0, 3, 2, 0, false}, {CCV::CVT_D3_S2_R0_P, 3, 2, 0, true},
    {CCV::CVT_D3_S3_R0, 3, 3, 0, false}, {CCV::CVT_D3_S3_R0_P, 3, 3, 0, true},
};
} // namespace

static FpInfo fpInfo(unsigned Op) {
  FpInfo I;
  auto bin = [&](unsigned Base, unsigned Code, bool Host) {
    I.K = FpInfo::Bin; I.Base = Base; I.Code = Code; I.D = 0; I.A = 1; I.B = 2;
    I.HostForm = Host;
  };
  switch (Op) {
  case CCV::FADD: bin(CCV::FADD, 0, true); return I;
  case CCV::FSUB: bin(CCV::FSUB, 0, true); return I;
  case CCV::FMUL: bin(CCV::FMUL, 0, true); return I;
  case CCV::FMIN: bin(CCV::FMIN, 0, true); return I;
  case CCV::FMAX: bin(CCV::FMAX, 0, true); return I;
  case CCV::FADD_F1: bin(CCV::FADD, 1, false); return I;
  case CCV::FSUB_F1: bin(CCV::FSUB, 1, false); return I;
  case CCV::FMUL_F1: bin(CCV::FMUL, 1, false); return I;
  case CCV::FMIN_F1: bin(CCV::FMIN, 1, false); return I;
  case CCV::FMAX_F1: bin(CCV::FMAX, 1, false); return I;
  case CCV::FADD_P: case CCV::FSUB_P: case CCV::FMUL_P:
    bin(Op == CCV::FADD_P ? CCV::FADD : Op == CCV::FSUB_P ? CCV::FSUB : CCV::FMUL,
        0, true);
    I.Qual = 1; I.A = 2; I.B = 3;
    return I;
  case CCV::C_FADD: case CCV::C_FMUL: case CCV::C_FMIN: case CCV::C_FMAX:
    bin(Op == CCV::C_FADD ? CCV::FADD : Op == CCV::C_FMUL ? CCV::FMUL
        : Op == CCV::C_FMIN ? CCV::FMIN : CCV::FMAX, 0, true);
    I.A = 0; I.B = 2;                   // destructive: rd op rs
    return I;
  case CCV::FNEG_F0: case CCV::FABS_F0: case CCV::FNEG_F1: case CCV::FABS_F1:
    I.K = FpInfo::Un;
    I.Base = Op == CCV::FNEG_F0 || Op == CCV::FNEG_F1 ? CCV::FNEG_F0 : CCV::FABS_F0;
    I.Code = Op == CCV::FNEG_F1 || Op == CCV::FABS_F1;
    I.D = 0; I.A = 1; I.HostForm = !I.Code;
    return I;
  case CCV::FFMA_F0: case CCV::FFMA_F1:
    I.K = FpInfo::Fma; I.Base = CCV::FFMA_F0; I.Code = Op == CCV::FFMA_F1;
    I.D = 0; I.A = 1; I.B = 2; I.C = 3; I.HostForm = !I.Code;
    return I;
  case CCV::FFMA_ACC_F0: case CCV::FFMA_ACC_F1:
    I.K = FpInfo::Fma; I.Base = CCV::FFMA_F0; I.Code = Op == CCV::FFMA_ACC_F1;
    I.D = 0; I.A = 2; I.B = 3; I.C = 0; I.HostForm = !I.Code;
    return I;
  default:
    break;
  }
  for (const CvtRow &R : CvtTable)
    if (R.Op == Op) {
      I.K = FpInfo::Cvt; I.Dst = R.D; I.Src = R.S; I.Rnd = R.R;
      I.D = 0; I.A = R.Pred ? 2 : 1; I.Qual = R.Pred ? 1 : -1;
      // The four conversions the division sequence uses have FP32 host forms,
      // and sign extension its own case; every other point is generic only.
      I.HostForm = (R.D == 0 && (R.S == 2 || R.S == 3) && R.R == 0) ||
                   ((R.D == 2 || R.D == 3) && R.S == 0 && R.R == 1) ||
                   Op == CCV::CVT_SEXT;
      return I;
    }
  return I;
}

/// One lane of the generic path. X, Y, Z are the operands' elements.
static uint32_t fpLane(const FpInfo &I, uint8_t WD, uint8_t WA, uint8_t WB,
                       uint8_t WC, uint32_t X, uint32_t Y, uint32_t Z) {
  using namespace nfp;
  if (I.K == FpInfo::Cvt) {
    Round R = Round(I.Rnd);
    Value V = I.Src < 2 ? decode(*format(WA, I.Src), X)
                        : fromInt(X, widthBits(WA), I.Src == 2);
    return I.Dst < 2 ? encode(*format(WD, I.Dst), V, R)
                     : toInt(V, widthBits(WD), I.Dst == 2, R);
  }
  // O-67: every source is its raw field at the destination's width, read in
  // the destination's format. Nothing is converted.
  const Format FD = *format(WD, I.Code);
  X = opnd(X, WA, WD);
  if (I.K == FpInfo::Un) {              // a sign-bit operation, NaN included
    uint32_t S = 1u << (FD.Bits - 1);
    return I.Base == CCV::FNEG_F0 ? (X ^ S) : (X & ~S);
  }
  Value A = decode(FD, X);
  Value B = decode(FD, opnd(Y, WB, WD));
  switch (I.K == FpInfo::Fma ? CCV::FFMA_F0 : I.Base) {
  case CCV::FADD: return encode(FD, add(A, B, Round::RN), Round::RN);
  case CCV::FSUB: return encode(FD, add(A, neg(B), Round::RN), Round::RN);
  case CCV::FMUL: return encode(FD, mul(A, B), Round::RN);
  case CCV::FMIN: case CCV::FMAX: {
    // minNum and maxNum (O-56): a NaN operand gives the other operand.
    if (A.K == Value::NaN && B.K == Value::NaN) return FD.NaN;
    if (A.K == Value::NaN) return encode(FD, B, Round::RN);
    if (B.K == Value::NaN) return encode(FD, A, Round::RN);
    int C = compare(A, B);
    bool TakeA = I.Base == CCV::FMIN ? C <= 0 : C >= 0;
    return encode(FD, TakeA ? A : B, Round::RN);
  }
  default: {                            // ffma: one rounding of a*b + c
    Value C = decode(FD, opnd(Z, WC, WD));
    return encode(FD, add(mul(A, B), C, Round::RN), Round::RN);
  }
  }
}

/// §12.3's F-FORMAT: a format code reserved at the width of a register the
/// instruction reads or writes as FP. Integer codes are valid at every width.
static bool formatReserved(const FpInfo &I, const uint8_t *Widths) {
  auto Bad = [](uint8_t W, unsigned Code) {
    return Code < 2 && !nfp::format(W, Code);
  };
  if (I.K == FpInfo::Cvt)
    return Bad(Widths[0], I.Dst) || Bad(Widths[1], I.Src);
  for (int K = 0; K != 4; ++K)
    if (Widths[K] != 0xff && Bad(Widths[K], I.Code))
      return true;
  return false;
}

/// O-44's FP dot products: rs2 (FP32) plus the products of rs0's and rs1's
/// elements, summed exactly and rounded once into FP32 -- normative, since an
/// FP reduction's order is observable. Exact through NarrowFP.h: every product
/// of two 16- or 8-bit elements is exact in 128 bits, and so is their sum.
static uint32_t dpLane(unsigned Op, uint32_t X, uint32_t Y, uint32_t Acc) {
  using namespace nfp;
  unsigned W, Code, N;
  switch (Op) {
  case CCV::DP2_BF16: W = 1, Code = 1, N = 2; break;
  case CCV::DP2_F16:  W = 1, Code = 0, N = 2; break;
  case CCV::DP4_E4M3: W = 2, Code = 0, N = 4; break;
  default:            W = 2, Code = 1, N = 4; break;   // DP4_E5M2
  }
  const Format F = *format(W, Code), F32 = *format(0, 0);
  unsigned Bits = 32 / N;
  Value S = mul(decode(F, X & ((1u << Bits) - 1)), decode(F, Y & ((1u << Bits) - 1)));
  for (unsigned K = 1; K != N; ++K)
    S = add(S, mul(decode(F, (X >> (Bits * K)) & ((1u << Bits) - 1)),
                   decode(F, (Y >> (Bits * K)) & ((1u << Bits) - 1))),
            Round::RN);
  return encode(F32, add(S, decode(F32, Acc), Round::RN), Round::RN);
}

static unsigned fpRelation(unsigned Op, unsigned &Code);
static bool fpCompareElem(unsigned Rel, unsigned Code, uint8_t WA, uint32_t X,
                          uint32_t Y);

bool Interp::evalFp(unsigned Op, const uint8_t Widths[4], uint32_t X,
                    uint32_t Y, uint32_t Z, uint32_t &Out) {
  // An FP compare (O-65): Widths[1] and [2] are rs0's and rs1's, Out is 0 or 1.
  unsigned FCode;
  if (unsigned Rel = fpRelation(Op, FCode)) {
    if (!nfp::format(Widths[1], FCode) || !nfp::format(Widths[2], FCode))
      return false;
    Out = fpCompareElem(Rel, FCode, Widths[1], narrow(X, Widths[1]),
                        opnd(Y, Widths[2], Widths[1]));
    return true;
  }
  // A dot product (O-44): X, Y the packed words, Z the FP32 accumulator.
  if (Op == CCV::DP2_BF16 || Op == CCV::DP2_F16 || Op == CCV::DP4_E4M3 ||
      Op == CCV::DP4_E5M2) {
    Out = dpLane(Op, X, Y, Z);
    return true;
  }
  FpInfo I = fpInfo(Op);
  if (I.K == FpInfo::None)
    return false;
  uint8_t W[4];
  int Ops[4] = {I.D, I.A, I.B, I.C};
  for (int K = 0; K != 4; ++K)
    W[K] = Ops[K] >= 0 ? Widths[K] : 0xff;
  if (formatReserved(I, W))
    return false;
  auto Elem = [](uint32_t V, uint8_t C) { return C == 0xff ? 0 : narrow(V, C); };
  Out = fpLane(I, W[0], W[1], I.B >= 0 ? W[2] : 0, I.C >= 0 ? W[3] : 0,
               Elem(X, W[1]), Elem(Y, W[2]), Elem(Z, W[3]));
  return true;
}

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
  // The FP SFU is approximate, within O-70's bounds. By default the simulator
  // returns the correctly rounded value, from integer arithmetic alone, so an
  // oracle pins no hardware's error and no host's libm (SfuMath.cpp);
  // -sfu-error-ulps returns values at the bound, which is how the IEEE
  // sequences are checked not to depend on it.
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
  case CCV::RCP_F32:   return sfu::evalWithin(sfu::Rcp, X, nfp::SfuErrorUlps);
  case CCV::RSQRT_F32: return sfu::evalWithin(sfu::Rsqrt, X, nfp::SfuErrorUlps);
  case CCV::SQRT_F32:  return sfu::evalWithin(sfu::Sqrt, X, nfp::SfuErrorUlps);
  case CCV::EX2_F32:   return sfu::evalWithin(sfu::Ex2, X, nfp::SfuErrorUlps);
  case CCV::LG2_F32:   return sfu::evalWithin(sfu::Lg2, X, nfp::SfuErrorUlps);
  case CCV::SIN_F32:   return sfu::evalWithin(sfu::Sin, X, nfp::SfuErrorUlps);
  default:             return sfu::evalWithin(sfu::Cos, X, nfp::SfuErrorUlps);
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
  case CCV::MUL_LO: case CCV::C_MUL_LO: return X * Y;
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
  case CCV::FADD: case CCV::C_FADD: return fpBits(X + Y);
  case CCV::FSUB:                   return fpBits(X - Y);
  case CCV::FMUL: case CCV::C_FMUL: return fpBits(X * Y);
  case CCV::FMIN: case CCV::C_FMIN: return fpBits(std::fmin(X, Y));
  case CCV::FMAX: case CCV::C_FMAX: return fpBits(std::fmax(X, Y));
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
#define NP1(x) case CCV::x##_NP: return CCV::x;
  NP1(SETP_LT_F1) NP1(SETP_LE_F1) NP1(SETP_EQ_F1) NP1(SETP_NE_F1)
  NP1(SETP_GT_F1) NP1(SETP_GE_F1)
#undef NP1
  default: return Op;
  }
}

bool Interp::isCompare(unsigned Op) {
  switch (Op) {
#define REL(x) case CCV::x: case CCV::x##_I: case CCV::x##_NP: case CCV::x##_NPI:
  REL(SETP_LT) REL(SETP_LE) REL(SETP_EQ) REL(SETP_NE) REL(SETP_GT) REL(SETP_GE)
  REL(SETP_LT_U) REL(SETP_LE_U) REL(SETP_GT_U) REL(SETP_GE_U)
  REL(SETP_LT_F) REL(SETP_LE_F) REL(SETP_EQ_F) REL(SETP_NE_F)
  REL(SETP_GT_F) REL(SETP_GE_F)
#undef REL
#define REL1(x) case CCV::x: case CCV::x##_NP:
  REL1(SETP_LT_F1) REL1(SETP_LE_F1) REL1(SETP_EQ_F1) REL1(SETP_NE_F1)
  REL1(SETP_GT_F1) REL1(SETP_GE_F1)
#undef REL1
    return true;
  default:
    return false;
  }
}

/// An FP compare's relation, as the format-00 register opcode (SETP_LT_F and
/// so on), and its format code: bit [23] of the register forms (O-65), 0 for
/// the immediate forms. 0 for an integer compare.
static unsigned fpRelation(unsigned Op, unsigned &Code) {
  Code = 0;
  switch (baseCompare(Op)) {
#define R0(x) case CCV::x: case CCV::x##_I: return CCV::x;
  R0(SETP_LT_F) R0(SETP_LE_F) R0(SETP_EQ_F) R0(SETP_NE_F) R0(SETP_GT_F) R0(SETP_GE_F)
#undef R0
#define R1(x) case CCV::x##1: Code = 1; return CCV::x;
  R1(SETP_LT_F) R1(SETP_LE_F) R1(SETP_EQ_F) R1(SETP_NE_F) R1(SETP_GT_F) R1(SETP_GE_F)
#undef R1
  default: return 0;
  }
}

static bool isFloatCompare(unsigned Op) {
  unsigned Code;
  return fpRelation(Op, Code) != 0;
}

/// One lane of an FP compare at any width, through NarrowFP.h: both operands
/// decoded at rs0's width WA in format Code (O-65, O-67). Ordered relations are false
/// on a NaN and ne.f is true, as at 32 bits; -0 equals +0.
static bool fpCompareElem(unsigned Rel, unsigned Code, uint8_t WA, uint32_t X,
                          uint32_t Y) {
  using namespace nfp;
  const Format F = *format(WA, Code);
  Value A = decode(F, X), B = decode(F, Y);
  if (A.K == Value::NaN || B.K == Value::NaN)
    return Rel == CCV::SETP_NE_F;
  int C = A.isZero() && B.isZero() ? 0 : compare(A, B);
  switch (Rel) {
  case CCV::SETP_LT_F: return C < 0;
  case CCV::SETP_LE_F: return C <= 0;
  case CCV::SETP_GT_F: return C > 0;
  case CCV::SETP_GE_F: return C >= 0;
  case CCV::SETP_EQ_F: return C == 0;
  default:             return C != 0;   // ne.f
  }
}

/// Is this compare's integer relation a signed one? It decides how a narrow
/// element reaches the 32-bit comparison: sign-extended, or zero-extended.
/// eq/ne are sign-agnostic and either extension gives the same answer.
static bool isSignedCompare(unsigned Op) {
  switch (baseCompare(Op)) {
  case CCV::SETP_LT: case CCV::SETP_LE: case CCV::SETP_GT: case CCV::SETP_GE:
    return true;
  default:
    return false;
  }
}

/// One compare operand, read at its register's element width. A compare at
/// 16-bit width compares 16-bit elements; the bits above the element are not
/// part of the value and must not reach the relation.
static uint32_t cmpOperand(uint32_t V, uint8_t Code, bool Signed) {
  if (Code == 0)
    return V;
  return Signed ? uint32_t(sextTo32(V, Code)) : narrow(V, Code);
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

  // CurLane lets the memories attribute an F-ALIGN to its lane.
  Mem.AlignLanes = Shared.AlignLanes = 0;
  Mem.RoLanes = 0;
  auto forEachLane = [&](auto &&Fn) {
    for (unsigned L = 0; L != kLanes; ++L)
      if (Mask & (1u << L)) {
        Mem.CurLane = Shared.CurLane = L;
        Fn(L);
      }
  };

  // ---- F-BARRIER (ISA v1.9 O-59): dispatch stage, whole instruction ------
  // A CTA has at most 16 barriers; an ID at or above its allocated count names
  // nothing. The ID is an immediate, so the check is exact at dispatch and
  // independent of the predicate.
  {
    int IdOp = -1;
    switch (Op) {
    case CCV::BAR_INIT: case CCV::C_BAR_ARRIVE: case CCV::C_BAR_WAIT: IdOp = 0; break;
    case CCV::BAR_WAIT_PHASE: IdOp = 1; break;
    default: break;
    }
    if (IdOp >= 0 &&
        (unsigned(MI.getOperand(IdOp).getImm()) & 0x3f) >= BarrierCount) {
      Result F{Result::Fault, 0};
      F.Cause = "F-BARRIER";
      F.TakenMask = Mask;
      return F;
    }
  }

  // ---- F-WIDTH (ISA v1.9 §12.3): dispatch stage, whole instruction --------
  // A memory access whose rdata is at chwidth = 4 names no transfer. Checked
  // from committed width state before anything executes, and independent of
  // the predicate (§12.2), so the lanes reported are the issue mask.
  switch (Op) {
  case CCV::LD_GLOBAL: case CCV::ST_GLOBAL: case CCV::C_LD_GLOBAL:
  case CCV::C_ST_GLOBAL: case CCV::LD_GLOBAL_IDX: case CCV::ST_GLOBAL_IDX:
  case CCV::LD_GLOBAL_SLOT: case CCV::ST_GLOBAL_SLOT: case CCV::LD_SHARED:
  case CCV::ST_SHARED: case CCV::LD_SHARED_IDX: case CCV::ST_SHARED_IDX:
  case CCV::LD_GLOBAL_P: case CCV::LD_LOCAL: case CCV::ST_LOCAL:
    if (MI.getOperand(0).isReg()) {
      unsigned D = regOf(MI, 0);
      if (D < kGPRs && W.ChWidth[D] == 3) {
        Result F{Result::Fault, 0};
        F.Cause = "F-WIDTH";
        F.TakenMask = Mask;
        return F;
      }
    }
    break;
  default:
    break;
  }

  // ---- CP-6: the FP block and the conversions at every width -------------
  // F-FORMAT is dispatch-stage and whole-instruction, like F-WIDTH: a format
  // code reserved at the width of a register read or written as FP.
  const FpInfo Fp = fpInfo(Op);
  bool GenericFp = false;
  uint8_t FpW[4] = {0xff, 0xff, 0xff, 0xff};   // D, A, B, C widths
  if (Fp.K != FpInfo::None) {
    int Ops[4] = {Fp.D, Fp.A, Fp.B, Fp.C};
    bool Narrow = false;
    for (int K = 0; K != 4; ++K)
      if (Ops[K] >= 0) {
        FpW[K] = W.ChWidth[regOf(MI, unsigned(Ops[K]))];
        Narrow |= FpW[K] != 0;
      }
    if (formatReserved(Fp, FpW)) {
      Result F{Result::Fault, 0};
      F.Cause = "F-FORMAT";
      F.TakenMask = Mask;
      return F;
    }
    GenericFp = Narrow || !Fp.HostForm;
  }

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
  if (!isWidthAware(Op) && !GenericFp)
    for (unsigned I = 0, N = MI.getNumOperands(); I != N; ++I)
      if (MI.getOperand(I).isReg()) {
        unsigned R = regOf(MI, I);
        if (R < kGPRs && W.ChWidth[R] != 0)
          return {Result::Unimplemented, 0};
      }

  // The element width this instruction operates at, for O-40's retire-rate
  // model. Taken from the GPR operands themselves rather than from an opcode
  // table here: element width is per-register state (invariant 1), so the
  // registers ARE the authority and a table would be a second opinion about
  // something the machine already knows. Where operands disagree -- a widening
  // conversion, an address register beside narrow data -- the NARROWEST wins,
  // because the narrow slice is the part of the datapath the operation can
  // share. Reported, never acted on: the simulator retires one instruction per
  // step regardless, and the model lives in the benchmark where it can be
  // labelled as a model.
  uint8_t WCode = 0;
  {
    // Operand 1 of either compare form is Format C's materialization
    // destination `rd`, which these semantics never write. It is not data, so
    // its width says nothing about the width this instruction operates at --
    // and the allocator hands the back-edge compare of a narrow loop whichever
    // register is free, which is often a narrow one. Counting it made a 32-bit
    // comparison read as narrow element work once per iteration, and inflated
    // the measured narrow fraction of every loop that has one.
    const bool IsCmp = isCompare(Op);
    for (unsigned I = 0, N = MI.getNumOperands(); I != N; ++I) {
      if (IsCmp && I == 1)
        continue;
      if (MI.getOperand(I).isReg()) {
        unsigned R = regOf(MI, I);
        if (R < kGPRs && W.ChWidth[R] > WCode)
          WCode = W.ChWidth[R];
      }
    }
  }

  if (GenericFp) {
    // Each operand read at its own register's width, the result written at
    // the destination's (§4, invariant 1); a predicated form writes only the
    // lanes its qualifier selects (invariant 10).
    unsigned D = regOf(MI, unsigned(Fp.D));
    unsigned A = Fp.A >= 0 ? regOf(MI, unsigned(Fp.A)) : 0;
    unsigned B = Fp.B >= 0 ? regOf(MI, unsigned(Fp.B)) : 0;
    unsigned C = Fp.C >= 0 ? regOf(MI, unsigned(Fp.C)) : 0;
    uint32_t G = Mask;
    if (Fp.Qual >= 0) {
      G = guardMask(W, uint32_t(MI.getOperand(unsigned(Fp.Qual)).getImm())) & Mask;
      R.Active = G; R.ActiveSet = true;
    }
    Warp In = W;                        // sources as they were, rd may alias
    forEachLane([&](unsigned L) {
      if (!((G >> L) & 1))
        return;
      uint32_t X = narrow(In.GPR[A][L], FpW[1]);
      uint32_t Y = Fp.B >= 0 ? narrow(In.GPR[B][L], FpW[2]) : 0;
      uint32_t Z = Fp.C >= 0 ? narrow(In.GPR[C][L], FpW[3]) : 0;
      uint32_t V = fpLane(Fp, FpW[0], FpW[1], Fp.B >= 0 ? FpW[2] : 0,
                          Fp.C >= 0 ? FpW[3] : 0, X, Y, Z);
      W.GPR[D][L] = writeElem(W.GPR[D][L], V, FpW[0]);
    });
  } else
  switch (Op) {
  // ---- Format F: wide immediate, warp-uniform broadcast (§3) -------------
  case CCV::MOVI:
  case CCV::MOVI48: {
    unsigned D = regOf(MI, 0);
    uint32_t Imm = uint32_t(MI.getOperand(1).getImm());
    // An immediate write lands in the element, like any other write. §1's
    // invariant 1 has no width field on this instruction either -- the
    // destination's `chwidth` decides how much of the immediate survives.
    uint8_t WD = W.ChWidth[D];
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = writeElem(W.GPR[D][L], Imm, WD);
    });
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
    else if (Sel == 2)   // %lanectx: (hardware warp context << 5) | lane (O-64)
      forEachLane([&](unsigned L) { W.GPR[D][L] = (W.WarpCtx << 5) | L; });
    else {
      // Selectors 3-15 are reserved values in a defined field: F-ILLEGAL at
      // decode, whole instruction (ISA v1.9 §12.3).
      Result F{Result::Fault, 0};
      F.Cause = "F-ILLEGAL";
      F.TakenMask = Mask;
      return F;
    }
    break;
  }

  // ---- Format A: integer, two source (§4 points 0-17) --------------------
  // rs2 is unread by these; the selector ties it to rs0 so it costs no live
  // value. The simulator ignores it for the same reason.
  case CCV::ADD: case CCV::SUB: case CCV::AND: case CCV::OR:
  case CCV::XOR: case CCV::ANDN: case CCV::SHL: case CCV::SHR:
  case CCV::SRA: case CCV::MIN_S: case CCV::MIN_U: case CCV::MAX_S:
  case CCV::MAX_U: case CCV::MUL_HI_S: case CCV::MUL_HI_U:
  case CCV::MUL_LO: {
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
      uint32_t X = Signed ? opndS(W.GPR[A][L], WA, WD) : opnd(W.GPR[A][L], WA, WD);
      uint32_t Y = Signed ? opndS(W.GPR[B][L], WB, WD) : opnd(W.GPR[B][L], WB, WD);
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
  // §4 points 48-63: the packed dot product. All three operands are ordinary
  // chwidth=32 registers -- the packing factor is in the OPCODE and nothing
  // outside it observes the packed view, which is what keeps invariant 1
  // intact (§3, and contrast the register-level packing O-13 rejected).
  //
  // Format J's `dp4.acc` is the same operation with the addend fixed at the
  // destination, so it maps onto this rather than repeating the byte loop.
  // O-44's FP packed dot products. §4 makes the rule normative: the products
  // sum EXACTLY and the result rounds ONCE into the accumulator. Integer dp4
  // needed no such rule because its reduction cannot round; this one can, and
  // two implementations rounding differently would show up as a convergence
  // drift rather than as a test failure.
  //
  // Summed in long double, which carries a 64-bit mantissa where FP32 carries
  // 24 and the widest product here needs 22. That is exact for every input
  // whose addends span less than about forty binades. It is NOT exact in the
  // absolute worst case: BF16 has FP32's full exponent range, so a sum of
  // values from 2^-126 to 2^127 would need a few hundred bits, and no
  // fixed-width accumulator delivers that. Stated rather than glossed -- the
  // rule is what the hardware must implement, and this is how far the model
  // checks it.
  case CCV::DP2_BF16:
  case CCV::DP2_F16:
  case CCV::DP4_E4M3:
  case CCV::DP4_E5M2: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2),
             C = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = dpLane(Op, W.GPR[A][L], W.GPR[B][L], W.GPR[C][L]);
    });
    break;
  }

  case CCV::DP4_SS:
  case CCV::DP4_ACC: {
    bool Acc = Op == CCV::DP4_ACC;
    unsigned D = regOf(MI, 0);
    unsigned A = regOf(MI, Acc ? 2 : 1), B = regOf(MI, Acc ? 3 : 2);
    unsigned C = regOf(MI, Acc ? 1 : 3);
    forEachLane([&](unsigned L) {
      // Signed/signed. The other three signedness combinations have §4 points
      // and no encoding in Format J -- two bits of subop cannot carry them.
      int32_t Sum = int32_t(W.GPR[C][L]);
      uint32_t X = W.GPR[A][L], Y = W.GPR[B][L];
      for (unsigned K = 0; K < 4; ++K)
        Sum += int32_t(int8_t(X >> (8 * K))) * int32_t(int8_t(Y >> (8 * K)));
      W.GPR[D][L] = uint32_t(Sum);
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
      W.GPR[D][L] = fpBits(std::fmaf(bitsToFloat(W.GPR[A][L]),
                                          bitsToFloat(W.GPR[B][L]),
                                          bitsToFloat(W.GPR[C][L])));
    });
    break;
  }

  // ---- Format B: register-immediate --------------------------------------
  // ---- Format B: O-41's projection (§3) ---------------------------------
  // Point n is §4 point n with the second source replaced by the immediate, so
  // the semantics are §4's and the only difference is where the second operand
  // comes from. Mapped rather than reimplemented: a second copy of `shl` here
  // would be a place for the two to disagree.
  case CCV::SUBI: case CCV::MULI: case CCV::ANDI: case CCV::ORI:
  case CCV::XORI: case CCV::ANDNI: case CCV::SHLI: case CCV::SHRI:
  case CCV::SRAI: {
    static const auto base = [](unsigned O) -> unsigned {
      switch (O) {
      case CCV::SUBI:  return CCV::SUB;
      case CCV::MULI:  return CCV::MUL_LO;
      case CCV::ANDI:  return CCV::AND;
      case CCV::ORI:   return CCV::OR;
      case CCV::XORI:  return CCV::XOR;
      case CCV::ANDNI: return CCV::ANDN;
      case CCV::SHLI:  return CCV::SHL;
      case CCV::SHRI:  return CCV::SHR;
      default:         return CCV::SRA;
      }
    };
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    unsigned B = base(Op);
    uint32_t Imm = uint32_t(int32_t(MI.getOperand(2).getImm()));
    uint8_t WA = W.ChWidth[A], WD = W.ChWidth[D];
    const bool Signed = B == CCV::SRA;
    forEachLane([&](unsigned L) {
      uint32_t X = Signed ? opndS(W.GPR[A][L], WA, WD) : opnd(W.GPR[A][L], WA, WD);
      W.GPR[D][L] = writeElem(W.GPR[D][L], aluRR(B, X, Imm), WD);
    });
    break;
  }

  // ---- Format B′: O-41's projection under a qualifier (O-33) -------------
  // Operands are (rd, pq, rs0, imm): the qualifier displaces nothing, it takes
  // three of the thirteen immediate bits, which is why the masking pass refuses
  // to rewrite an immediate that no longer fits. Semantics are the unpredicated
  // form's, gated by the guard, so this maps onto the SAME base opcode the
  // Format B case above maps onto -- one place for `shl` to mean what `shl`
  // means.
  case CCV::ADDI_P:  case CCV::SUBI_P: case CCV::MULI_P: case CCV::ANDI_P:
  case CCV::ORI_P:   case CCV::XORI_P: case CCV::ANDNI_P:
  case CCV::SHLI_P:  case CCV::SHRI_P: case CCV::SRAI_P: {
    static const std::pair<unsigned, unsigned> Map[] = {
        {CCV::ADDI_P, CCV::ADD},   {CCV::SUBI_P, CCV::SUB},
        {CCV::MULI_P, CCV::MUL_LO}, {CCV::ANDI_P, CCV::AND},
        {CCV::ORI_P, CCV::OR},     {CCV::XORI_P, CCV::XOR},
        {CCV::ANDNI_P, CCV::ANDN}, {CCV::SHLI_P, CCV::SHL},
        {CCV::SHRI_P, CCV::SHR},   {CCV::SRAI_P, CCV::SRA}};
    unsigned B = 0;
    for (auto [P, Base] : Map) if (P == Op) B = Base;
    unsigned D = regOf(MI, 0), A = regOf(MI, 2);
    uint32_t Imm = uint32_t(int32_t(MI.getOperand(3).getImm()));
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(1).getImm())) & Mask;
    uint8_t WA = W.ChWidth[A], WD = W.ChWidth[D];
    const bool Signed = B == CCV::SRA;
    R.Active = G; R.ActiveSet = true;
    forEachLane([&](unsigned L) {
      // Invariant 10: the lanes the guard excludes keep what they held.
      if (!((G >> L) & 1))
        return;
      uint32_t X = Signed ? opndS(W.GPR[A][L], WA, WD) : opnd(W.GPR[A][L], WA, WD);
      W.GPR[D][L] = writeElem(W.GPR[D][L], aluRR(B, X, Imm), WD);
    });
    break;
  }

  case CCV::ADDI:
  case CCV::ADDI48: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    int32_t Imm = int32_t(MI.getOperand(2).getImm());
    uint8_t WA = W.ChWidth[A], WD = W.ChWidth[D];
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = writeElem(W.GPR[D][L],
                              opnd(W.GPR[A][L], WA, WD) + uint32_t(Imm), WD);
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
  case CCV::SETP_GE_F_I:
  case CCV::SETP_LT_F1: case CCV::SETP_LE_F1: case CCV::SETP_EQ_F1:
  case CCV::SETP_NE_F1: case CCV::SETP_GT_F1: case CCV::SETP_GE_F1: {
    unsigned P = regOf(MI, 0), A = regOf(MI, 3);
    bool Imm = MI.getOperand(4).isImm() && !MI.getOperand(4).isReg();
    unsigned B = Imm ? 0 : regOf(MI, 4);
    int32_t IV = Imm ? int32_t(MI.getOperand(4).getImm()) : 0;
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(2).getImm())) & Mask;
    const bool Sgn = isSignedCompare(Op);
    const uint8_t WA = W.ChWidth[A], WB = Imm ? 0 : W.ChWidth[B];
    unsigned FCode, Rel = fpRelation(Op, FCode);
    if (Rel && (WA || WB || FCode)) {
      // A narrow or format-01 FP compare (O-65). An immediate is read at
      // rs0's width and format.
      const uint8_t WY = Imm ? WA : WB;
      if (!nfp::format(WA, FCode) || !nfp::format(WY, FCode))
        return formatFault(Mask);
      // O-67: rs1's raw field at rs0's width, compared in rs0's format.
      forEachLane([&](unsigned L) {
        if (!((G >> L) & 1)) return;
        uint32_t X = narrow(W.GPR[A][L], WA);
        uint32_t Y = Imm ? narrow(uint32_t(IV), WA) : opnd(W.GPR[B][L], WB, WA);
        bool T = fpCompareElem(Rel, FCode, WA, X, Y);
        W.Pred[P] = (W.Pred[P] & ~(1u << L)) | (uint32_t(T) << L);
      });
      break;
    }
    forEachLane([&](unsigned L) {
      if (!((G >> L) & 1)) return;   // invariant 10: excluded lanes preserved
      uint32_t X = cmpOperand(W.GPR[A][L], WA, Sgn);
      uint32_t Y = Imm ? uint32_t(IV)
                       : Sgn ? opndS(W.GPR[B][L], WB, WA) : opnd(W.GPR[B][L], WB, WA);
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
  case CCV::SETP_GE_F_NPI:
  case CCV::SETP_LT_F1_NP: case CCV::SETP_LE_F1_NP: case CCV::SETP_EQ_F1_NP:
  case CCV::SETP_NE_F1_NP: case CCV::SETP_GT_F1_NP: case CCV::SETP_GE_F1_NP: {
    // Format C" (O-32): no qualifier, so every lane in the issue mask is
    // written. Lanes OUTSIDE the mask are still preserved -- they are at a
    // different PC and may hold a live predicate (invariant 10 applies to the
    // issue mask, not only to a guard).
    unsigned P = regOf(MI, 0), A = regOf(MI, 2);
    bool Imm = !MI.getOperand(3).isReg();
    unsigned B = Imm ? 0 : regOf(MI, 3);
    int32_t IV = Imm ? int32_t(MI.getOperand(3).getImm()) : 0;
    unsigned Base = baseCompare(Op);
    // Operand 1 is Format C's materialization destination `rd`, and nothing
    // here writes it -- the predicate is the result. Its element width is
    // therefore irrelevant to this instruction, which matters because the
    // register allocator hands the back-edge compare of a narrow loop a `rd`
    // the loop body has narrowed, and the compiler no longer spends a `chwidth`
    // restoring a register no one reads (F-87).
    const bool Sgn = isSignedCompare(Op);
    const uint8_t WA = W.ChWidth[A], WB = Imm ? 0 : W.ChWidth[B];
    unsigned FCode, Rel = fpRelation(Op, FCode);
    if (Rel && (WA || WB || FCode)) {
      const uint8_t WY = Imm ? WA : WB;   // as Format C's, above (O-65)
      if (!nfp::format(WA, FCode) || !nfp::format(WY, FCode))
        return formatFault(Mask);
      // O-67: rs1's raw field at rs0's width, compared in rs0's format.
      forEachLane([&](unsigned L) {
        uint32_t X = narrow(W.GPR[A][L], WA);
        uint32_t Y = Imm ? narrow(uint32_t(IV), WA) : opnd(W.GPR[B][L], WB, WA);
        bool T = fpCompareElem(Rel, FCode, WA, X, Y);
        W.Pred[P] = (W.Pred[P] & ~(1u << L)) | (uint32_t(T) << L);
      });
      break;
    }
    forEachLane([&](unsigned L) {
      uint32_t X = cmpOperand(W.GPR[A][L], WA, Sgn);
      uint32_t Y = Imm ? uint32_t(IV)
                       : Sgn ? opndS(W.GPR[B][L], WB, WA) : opnd(W.GPR[B][L], WB, WA);
      bool T = compare(Base, X, Y);
      W.Pred[P] = (W.Pred[P] & ~(1u << L)) | (uint32_t(T) << L);
    });
    break;
  }


  // ---- Format D: load / store --------------------------------------------
  // Format K's memory pair rides the same code: it is Format D with the
  // displacement fixed at zero and no width twin, so everything below -- the
  // transfer size taken from rdata's chwidth included -- is unchanged.
  case CCV::C_LD_GLOBAL:
  case CCV::C_ST_GLOBAL:
  case CCV::LD_GLOBAL:
  case CCV::ST_GLOBAL: {
    bool Compressed = Op == CCV::C_LD_GLOBAL || Op == CCV::C_ST_GLOBAL;
    bool IsLoad = Op == CCV::LD_GLOBAL || Op == CCV::C_LD_GLOBAL;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1);
    int64_t Off = Compressed ? 0 : MI.getOperand(2).getImm();
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
  // §3: ld.pred / st.pred move the predicates a 4-bit MASK names, each a
  // whole warp's 32 bits, one instruction. The frame is positional -- word i
  // of a 16-byte frame holds Pi whatever the mask -- and the address is taken
  // from lane 0's rbase, since a predicate is warp-scoped state (O-19). The
  // backend spills predicates through these; until IS-15 a kernel that did
  // stopped here as unimplemented.
  case CCV::LD_PRED_G:
  case CCV::ST_PRED_G: {
    unsigned PMask = unsigned(MI.getOperand(0).getImm()) & 0xf;
    unsigned Base = regOf(MI, 1);
    uint64_t A = (uint64_t(W.GPR[Base][0]) << kBaseShift) +
                 MI.getOperand(2).getImm();
    Mem.CurLane = 0;
    for (unsigned P = 0; P != kPreds; ++P) {
      if (!(PMask & (1u << P)))
        continue;
      // Checked, so a refused word is logged for the fault record (TI-28).
      // Mem.CurLane is lane 0, whose rbase forms the address.
      if (Op == CCV::LD_PRED_G) {
        // O-62: only the issuing group's lanes take the loaded bits; a lane
        // outside the issue mask is another thread, and keeps its own.
        uint32_t V = Mem.readN(A + 4 * P, 4);
        if (Mem.AlignLanes)
          break;
        W.Pred[P] = (W.Pred[P] & ~Mask) | (V & Mask);
        continue;
      }
      // O-63: only the issuing group's bits, merged into memory's word, so
      // a slot shared by diverged groups is per-lane storage. The read is the
      // merge's, not a load: it is not logged.
      uint32_t Old = Mem.peek32(A + 4 * P);
      Mem.writeN(A + 4 * P, (Old & ~Mask) | (W.Pred[P] & Mask), 4);
      if (Mem.AlignLanes || Mem.RoLanes)
        break;
    }
    // A fault is the whole group's, at the access's address (§3, §12.6):
    // lane 0 forms the address, and the issue mask raises it.
    if (Mem.AlignLanes) Mem.AlignLanes = Mask;
    if (Mem.RoLanes)    Mem.RoLanes = Mask;
    break;
  }
  // ---- O-69: the interleaved spill space -----------------------------------
  // No base register: lane l's byte b of the warp's spill frame is at
  //   ((local_base + CCV_LANE_CONTEXTS) << 16) + (ctx << 22)
  //     + 128 * (b / 4) + 4l + b % 4,
  // local_base being launch-block word 24 and ctx the warp's hardware context
  // (%lanectx >> 5). Word w of every lane's frame is one 128-byte line.
  // Transfer size and alignment are any Format D access's.
  case CCV::LD_LOCAL:
  case CCV::ST_LOCAL: {
    bool IsLoad = Op == CCV::LD_LOCAL;
    unsigned Data = regOf(MI, 0);
    uint64_t B = uint64_t(MI.getOperand(1).getImm());   // operand 0 is rdata
    unsigned Bytes = widthBits(W.ChWidth[Data]) / 8;
    forEachLane([&](unsigned L) {
      uint64_t A = localAddr(W, B, L);
      if (IsLoad) W.GPR[Data][L] =
              writeElem(W.GPR[Data][L], Mem.readN(A, Bytes), W.ChWidth[Data]);
      else        Mem.writeN(A, narrow(W.GPR[Data][L], W.ChWidth[Data]), Bytes);
    });
    break;
  }
  // ld.pred / st.pred in the spill space: warp-scoped, so the lane term is
  // 0, and word i of the 16-byte predicate frame at b is byte b + 4i's word.
  // Merged under divergence exactly as ld.pred / st.pred are (O-62, O-63).
  case CCV::LD_PRED_LOCAL:
  case CCV::ST_PRED_LOCAL: {
    unsigned PMask = unsigned(MI.getOperand(0).getImm()) & 0xf;
    uint64_t B = uint64_t(MI.getOperand(1).getImm());
    Mem.CurLane = 0;
    for (unsigned P = 0; P != kPreds; ++P) {
      if (!(PMask & (1u << P)))
        continue;
      uint64_t A = localAddr(W, B + 4 * P, 0);
      if (Op == CCV::LD_PRED_LOCAL) {
        uint32_t V = Mem.readN(A, 4);
        if (Mem.AlignLanes)
          break;
        W.Pred[P] = (W.Pred[P] & ~Mask) | (V & Mask);
        continue;
      }
      uint32_t Old = Mem.peek32(A);
      Mem.writeN(A, (Old & ~Mask) | (W.Pred[P] & Mask), 4);
      if (Mem.AlignLanes || Mem.RoLanes)
        break;
    }
    if (Mem.AlignLanes) Mem.AlignLanes = Mask;
    if (Mem.RoLanes)    Mem.RoLanes = Mask;
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

  // ---- Format D: launch-slot + index (O-45) ------------------------------
  // The window base is the 32-bit word at launch-block byte offset
  // `kOffArgs + kSlotStride*slot`, which is where a pointer argument's window
  // index sits -- the ABI puts the pointers at the front of the argument area
  // so that slot k is pointer argument k.
  // Everything downstream is the base+index case: same scale rule, same
  // transfer size from `rdata`'s chwidth, same displacement.
  //
  // The read is WARP-UNIFORM by construction -- the launch block is CTA-wide
  // and read-only for the kernel's lifetime (§5.2) -- which is the property
  // that makes it cacheable in hardware and is the entire point of the form.
  case CCV::LD_GLOBAL_SLOT:
  case CCV::ST_GLOBAL_SLOT: {
    bool IsLoad = Op == CCV::LD_GLOBAL_SLOT;
    // Both forms carry (rdata, slot, rindex, scale, disp) in that order -- the
    // store has rdata as a use rather than a def, which does not move it.
    unsigned Data = regOf(MI, 0), Idx = regOf(MI, 2);
    unsigned Slot = unsigned(MI.getOperand(1).getImm());
    unsigned ScaleEn = unsigned(MI.getOperand(3).getImm());
    int64_t Disp = MI.getOperand(4).getImm();
    uint32_t Window = Mem.peek32(kLaunchBase + kOffArgs + kSlotStride * Slot);
    unsigned Sh = ScaleEn ? (2 - W.ChWidth[Data]) : 0;
    unsigned Bytes = widthBits(W.ChWidth[Data]) / 8;
    forEachLane([&](unsigned L) {
      uint64_t A = (uint64_t(Window) << kBaseShift) +
                   (uint64_t(W.GPR[Idx][L]) << Sh) + Disp;
      if (IsLoad)
        W.GPR[Data][L] =
            writeElem(W.GPR[Data][L], Mem.readN(A, Bytes), W.ChWidth[Data]);
      else
        Mem.writeN(A, narrow(W.GPR[Data][L], W.ChWidth[Data]), Bytes);
    });
    break;
  }

  // ---- Format M: atomics (O-72) --------------------------------------------
  // Each executing lane's read-modify-write is atomic and full-width, and
  // returns the old word; lanes apply in ascending order, one of the orders
  // §3 permits for these order-independent operations. The address is Format
  // D's base + index (O-72), scale 2 when enabled: one word, aligned (F-ALIGN).
  // The write is made whatever the operation computes, so a store into
  // read-only memory is F-RO even when nothing would change (O-51).
  case CCV::ATOM_ADD_G:   case CCV::ATOM_ADD_S:
  case CCV::ATOM_MIN_S_G: case CCV::ATOM_MIN_S_S:
  case CCV::ATOM_MIN_U_G: case CCV::ATOM_MIN_U_S:
  case CCV::ATOM_MAX_S_G: case CCV::ATOM_MAX_S_S:
  case CCV::ATOM_MAX_U_G: case CCV::ATOM_MAX_U_S:
  case CCV::ATOM_AND_G:   case CCV::ATOM_AND_S:
  case CCV::ATOM_OR_G:    case CCV::ATOM_OR_S:
  case CCV::ATOM_XOR_G:   case CCV::ATOM_XOR_S:
  case CCV::ATOM_EXCH_G:  case CCV::ATOM_EXCH_S:
  case CCV::CAS_G:        case CCV::CAS_S: {
    const bool Cas = Op == CCV::CAS_G || Op == CCV::CAS_S;
    const bool Sh = Op == CCV::CAS_S || Op == CCV::ATOM_ADD_S ||
                    Op == CCV::ATOM_MIN_S_S || Op == CCV::ATOM_MIN_U_S ||
                    Op == CCV::ATOM_MAX_S_S || Op == CCV::ATOM_MAX_U_S ||
                    Op == CCV::ATOM_AND_S || Op == CCV::ATOM_OR_S ||
                    Op == CCV::ATOM_XOR_S || Op == CCV::ATOM_EXCH_S;
    // RMW: rd, rbase, rindex, scale, disp, rs. CAS: rd, pd, pq, rbase,
    // rindex, scale, disp, rs_cmp, rs_swap.
    const unsigned A0 = Cas ? 3 : 1;
    const unsigned D = regOf(MI, 0), Base = regOf(MI, A0),
                   Idx = regOf(MI, A0 + 1);
    const unsigned Scale = MI.getOperand(A0 + 2).getImm() ? 2 : 0;
    const int64_t Disp = MI.getOperand(A0 + 3).getImm();
    const unsigned S1 = regOf(MI, A0 + 4), S2 = Cas ? regOf(MI, A0 + 5) : 0;
    const unsigned PD = Cas ? regOf(MI, 1) : 0;
    const uint32_t G =
        Cas ? guardMask(W, uint32_t(MI.getOperand(2).getImm())) & Mask : Mask;
    if (Cas) {
      R.Active = G;
      R.ActiveSet = true;
    }
    Memory &M = Sh ? Shared : Mem;
    uint32_t Succ = 0;
    for (unsigned L = 0; L != kLanes; ++L) {
      if (!(G & (1u << L)))
        continue;
      Mem.CurLane = Shared.CurLane = L;
      uint64_t A =
          (nfp::TestAtomNoIndex ? 0 : uint64_t(W.GPR[Idx][L]) << Scale) + Disp;
      A += Sh ? uint64_t(W.GPR[Base][L]) : uint64_t(W.GPR[Base][L]) << kBaseShift;
      const uint32_t Old = M.readN(A, 4), X = W.GPR[S1][L];
      uint32_t New = Old;
      switch (Op) {
      case CCV::ATOM_ADD_G:   case CCV::ATOM_ADD_S:   New = Old + X; break;
      case CCV::ATOM_MIN_S_G: case CCV::ATOM_MIN_S_S:
        New = uint32_t(std::min(int32_t(Old), int32_t(X))); break;
      case CCV::ATOM_MIN_U_G: case CCV::ATOM_MIN_U_S: New = std::min(Old, X); break;
      case CCV::ATOM_MAX_S_G: case CCV::ATOM_MAX_S_S:
        New = uint32_t(std::max(int32_t(Old), int32_t(X))); break;
      case CCV::ATOM_MAX_U_G: case CCV::ATOM_MAX_U_S: New = std::max(Old, X); break;
      case CCV::ATOM_AND_G:   case CCV::ATOM_AND_S:   New = Old & X; break;
      case CCV::ATOM_OR_G:    case CCV::ATOM_OR_S:    New = Old | X; break;
      case CCV::ATOM_XOR_G:   case CCV::ATOM_XOR_S:   New = Old ^ X; break;
      case CCV::ATOM_EXCH_G:  case CCV::ATOM_EXCH_S:  New = X; break;
      default:                                        // CAS
        if (Old == X) {
          New = W.GPR[S2][L];
          Succ |= 1u << L;
        }
        break;
      }
      M.writeN(A, New, 4);
      W.GPR[D][L] = Old;
    }
    if (Cas)
      W.Pred[PD] = (W.Pred[PD] & ~G) | Succ;
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
    // §3 takes transfer size from rdata's chwidth here exactly as it does for
    // .global. These two were on the width-aware list while still calling
    // read32/write32 -- the list is a CLAIM about the code below it, and
    // nothing checked the claim. Same defect as F-67, one address space over.
    unsigned Bytes = widthBits(W.ChWidth[Data]) / 8;
    forEachLane([&](unsigned L) {
      uint64_t A = uint64_t(W.GPR[Base][L]) + Off;   // O-39: base at 32 bits
      if (IsLoad)
        W.GPR[Data][L] =
            writeElem(W.GPR[Data][L], Shared.readN(A, Bytes), W.ChWidth[Data]);
      else
        Shared.writeN(A, narrow(W.GPR[Data][L], W.ChWidth[Data]), Bytes);
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
      // 32-bit only (narrow is refused by the width guard), and through the
      // checked path so a misaligned lane raises F-ALIGN (O-58).
      if (IsLoad) W.GPR[Data][L] = Shared.readN(A, 4);
      else        Shared.writeN(A, W.GPR[Data][L], 4);
    });
    break;
  }

  // ---- Format K: compressed destructive ALU (rd is read and written) ------
  case CCV::C_ADD:   case CCV::C_SUB:   case CCV::C_MUL_LO: case CCV::C_AND:
  case CCV::C_OR:    case CCV::C_XOR:   case CCV::C_ANDN:   case CCV::C_SHL:
  case CCV::C_SHR:   case CCV::C_SRA:   case CCV::C_MIN_S:  case CCV::C_MIN_U:
  case CCV::C_MAX_S: case CCV::C_MAX_U: {
    // At each register's width, as Format A (rd is source and destination).
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    uint8_t WD = W.ChWidth[D], WS = W.ChWidth[Sx];
    bool Signed = Op == CCV::C_MIN_S || Op == CCV::C_MAX_S || Op == CCV::C_SRA;
    forEachLane([&](unsigned L) {
      uint32_t X = Signed ? sextTo32(W.GPR[D][L], WD) : narrow(W.GPR[D][L], WD);
      uint32_t Y = Signed ? opndS(W.GPR[Sx][L], WS, WD) : opnd(W.GPR[Sx][L], WS, WD);
      W.GPR[D][L] = writeElem(W.GPR[D][L], aluRR(Op, X, Y), WD);
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
    uint8_t WD = W.ChWidth[D];
    forEachLane([&](unsigned L) {
      uint32_t X = RR == CCV::C_SRA ? sextTo32(W.GPR[D][L], WD)
                                    : narrow(W.GPR[D][L], WD);
      W.GPR[D][L] = writeElem(W.GPR[D][L], aluRR(RR, X, Imm), WD);
    });
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
      W.GPR[D][L] = fpBits(std::fmaf(bitsToFloat(W.GPR[A][L]),
                                          bitsToFloat(W.GPR[B][L]),
                                          bitsToFloat(W.GPR[D][L])));   // fused, F-63
    });
    break;
  }
  case CCV::MAD_ACC: {
    // §3: "any source/accumulator width combination". This read and wrote all
    // 32 bits regardless, which was invisible while nothing selected it -- the
    // same shape as `ld.shared` vouching for itself in front of a read32
    // (F-67, twice). F-121 gave it a producer, so it is now width-aware and in
    // the width whitelist rather than one of the two.
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), B = regOf(MI, 3);
    uint8_t WA = W.ChWidth[A], WB = W.ChWidth[B], WD = W.ChWidth[D];
    forEachLane([&](unsigned L) {
      uint32_t P = narrow(W.GPR[A][L], WA) * narrow(W.GPR[B][L], WB);
      W.GPR[D][L] = writeElem(W.GPR[D][L], P + narrow(W.GPR[D][L], WD), WD);
    });
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
      // Through the checked path: a misaligned predicated-on lane raises
      // F-ALIGN, a predicated-off one never reaches here (O-58, §12.2).
      W.GPR[Data][L] = Mem.readN((uint64_t(W.GPR[Base][L]) << kBaseShift) + Off, 4);
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
  // call writes the low 32 bits of the next instruction's address -- a code
  // address, not a data address, so invariant 11 is untouched -- into its
  // link register (§3 Format E, v1.8, 3013036), and branches like `bra`. ret jumps each lane to its own
  // lane of rs: PCs are per thread (§1), so after an indirect call lanes can
  // return to different sites, and that is just a divergent branch (F-21;
  // proposals/calling-convention.md §4).
  case CCV::CALL: {
    unsigned D = regOf(MI, 0);
    uint32_t Link = uint32_t(PC + Size);
    forEachLane([&](unsigned L) { W.GPR[D][L] = Link; });
    R.Kind = Result::Branch;
    R.Target = PC + Size + 2 * MI.getOperand(1).getImm();
    break;
  }
  case CCV::C_RET: {
    // rs is in [15:12], the high nibble of the payload. It is not a register
    // operand to the MC layer, so the width guard above cannot see it.
    unsigned S = unsigned(MI.getOperand(0).getImm() >> 4) & 15;
    if (W.ChWidth[S] != 0)
      return {Result::Unimplemented, 0};
    R.Kind = Result::Return;
    R.Target = S;
    break;
  }
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

  // ---- F-ALIGN (O-58): execute stage, per lane ----------------------------
  // The memories refused each misaligned lane's access and recorded it. Lanes
  // outside issue mask and predicate never got that far (§12.2).
  if (uint32_t L = Mem.AlignLanes | Shared.AlignLanes) {
    Result F{Result::Fault, 0};
    F.Cause = "F-ALIGN";
    F.TakenMask = L;
    F.FaultAddr = Mem.AlignLanes ? Mem.AlignAddr : Shared.AlignAddr;
    return F;
  }
  // ---- F-RO (O-51, O-61): execute stage, per lane, after F-ALIGN ---------
  if (Mem.RoLanes) {
    Result F{Result::Fault, 0};
    F.Cause = "F-RO";
    F.TakenMask = Mem.RoLanes;
    F.FaultAddr = Mem.RoAddr;
    return F;
  }
  R.WidthCode = WCode;
  return R;
}
