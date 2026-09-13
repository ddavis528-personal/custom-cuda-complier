//===-- Interp.cpp - CCG instruction semantics ---------------------------===//
//
// Decoding is not re-implemented here: the simulator drives the disassembler
// that gen-disassembler produces, so this file is semantics only. That is the
// division roadmap F-6 settled on -- the encoder and decoder check each other
// through the round trip, and the simulator checks what the instructions
// actually compute.
//
//===----------------------------------------------------------------------===//

#include "Interp.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/ADT/bit.h"
#include "llvm/Support/MathExtras.h"
#include "llvm/Support/ErrorHandling.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <utility>

using namespace llvm;
using namespace ccg;

// §5.1: for .global the AGU computes (rbase << 16) + (rindex << scale) + disp.
// The shift is a property of the address space, not a field. 48 bits exist only
// here -- no register holds more than 32 (invariant 11).
static constexpr unsigned kBaseShift = 16;

static uint32_t regOf(const MCInst &MI, unsigned I) {
  unsigned R = MI.getOperand(I).getReg();
  if (R >= CCG::R0 && R <= CCG::R15)
    return R - CCG::R0;
  return R - CCG::P0; // predicate namespace is separate (invariant 5)
}

/// A predicate qualifier is a 2-bit address plus a negate bit (§1).
static uint32_t guardMask(const Warp &W, uint32_t Q) {
  uint32_t P = W.Pred[Q & 3];
  return (Q & 4) ? ~P : P;
}

static float bitsToFloat(uint32_t B) { float F; std::memcpy(&F, &B, 4); return F; }
static uint32_t floatToBits(float F) { uint32_t B; std::memcpy(&B, &F, 4); return B; }

/// Two-source integer ALU, shared by Format A (points 0-17) and Format K's
/// compressed forms, which are the same operations at a different length.
static uint32_t aluRR(unsigned Op, uint32_t X, uint32_t Y) {
  switch (Op) {
  case CCG::ADD:   case CCG::C_ADD:    return X + Y;
  case CCG::SUB:   case CCG::C_SUB:    return X - Y;
  case CCG::AND:   case CCG::C_AND:    return X & Y;
  case CCG::OR:    case CCG::C_OR:     return X | Y;
  case CCG::XOR:   case CCG::C_XOR:    return X ^ Y;
  case CCG::ANDN:  case CCG::C_ANDN:   return X & ~Y;
  case CCG::SHL:   case CCG::C_SHL:    return X << (Y & 31);
  case CCG::SHR:   case CCG::C_SHR:    return X >> (Y & 31);
  case CCG::SRA:   case CCG::C_SRA:    return uint32_t(int32_t(X) >> (Y & 31));
  case CCG::MIN_S: case CCG::C_MIN_S:  return std::min(int32_t(X), int32_t(Y));
  case CCG::MIN_U: case CCG::C_MIN_U:  return std::min(X, Y);
  case CCG::MAX_S: case CCG::C_MAX_S:  return std::max(int32_t(X), int32_t(Y));
  case CCG::MAX_U: case CCG::C_MAX_U:  return std::max(X, Y);
  case CCG::C_MUL_LO:                  return X * Y;
  case CCG::MUL_HI_S:
    return uint32_t((int64_t(int32_t(X)) * int64_t(int32_t(Y))) >> 32);
  case CCG::MUL_HI_U:
    return uint32_t((uint64_t(X) * uint64_t(Y)) >> 32);
  }
  llvm_unreachable("not a two-source integer ALU opcode");
}

static uint32_t aluR(unsigned Op, uint32_t X) {
  switch (Op) {
  case CCG::NEG:  case CCG::C_NEG: return uint32_t(-int32_t(X));
  case CCG::C_NOT:                 return ~X;
  case CCG::ABS:  case CCG::C_ABS:
    return int32_t(X) < 0 ? uint32_t(-int32_t(X)) : X;
  case CCG::POPC: return llvm::popcount(X);
  case CCG::CLZ:  return X ? llvm::countl_zero(X) : 32;
  case CCG::BREV: return llvm::reverseBits<uint32_t>(X);
  }
  llvm_unreachable("not a one-source integer ALU opcode");
}

static uint32_t fpRR(unsigned Op, uint32_t XB, uint32_t YB) {
  float X = bitsToFloat(XB), Y = bitsToFloat(YB);
  switch (Op) {
  case CCG::FADD: case CCG::C_FADD: return floatToBits(X + Y);
  case CCG::FSUB:                   return floatToBits(X - Y);
  case CCG::FMUL: case CCG::C_FMUL: return floatToBits(X * Y);
  case CCG::FMIN: case CCG::C_FMIN: return floatToBits(std::fmin(X, Y));
  case CCG::FMAX: case CCG::C_FMAX: return floatToBits(std::fmax(X, Y));
  }
  llvm_unreachable("not a floating-point ALU opcode");
}

/// The §3 compare map, register and immediate forms alike -- O-26 makes them one
/// opcode map, so they are one function here. Integer eq/ne are sign-agnostic
/// and shared between the signed and unsigned classes, which is why the map
/// needs 16 points rather than 18.
static bool compare(unsigned Op, uint32_t XB, uint32_t YB) {
  int32_t SX = int32_t(XB), SY = int32_t(YB);
  float FX = bitsToFloat(XB), FY = bitsToFloat(YB);
  switch (Op) {
  case CCG::SETP_LT:   case CCG::SETP_LT_I:   return SX <  SY;
  case CCG::SETP_LE:   case CCG::SETP_LE_I:   return SX <= SY;
  case CCG::SETP_GT:   case CCG::SETP_GT_I:   return SX >  SY;
  case CCG::SETP_GE:   case CCG::SETP_GE_I:   return SX >= SY;
  case CCG::SETP_EQ:   case CCG::SETP_EQ_I:   return XB == YB;
  case CCG::SETP_NE:   case CCG::SETP_NE_I:   return XB != YB;
  case CCG::SETP_LT_U: case CCG::SETP_LT_U_I: return XB <  YB;
  case CCG::SETP_LE_U: case CCG::SETP_LE_U_I: return XB <= YB;
  case CCG::SETP_GT_U: case CCG::SETP_GT_U_I: return XB >  YB;
  case CCG::SETP_GE_U: case CCG::SETP_GE_U_I: return XB >= YB;
  // Ordered relations: false if either operand is NaN, which C++ gives for
  // free. eq.f is ordered-equal; ne.f is its exact complement, so it is TRUE
  // for NaN -- that pairing is what makes C's float != one instruction (O-26).
  case CCG::SETP_LT_F: case CCG::SETP_LT_F_I: return FX <  FY;
  case CCG::SETP_LE_F: case CCG::SETP_LE_F_I: return FX <= FY;
  case CCG::SETP_GT_F: case CCG::SETP_GT_F_I: return FX >  FY;
  case CCG::SETP_GE_F: case CCG::SETP_GE_F_I: return FX >= FY;
  case CCG::SETP_EQ_F: case CCG::SETP_EQ_F_I: return FX == FY;
  case CCG::SETP_NE_F: case CCG::SETP_NE_F_I: return !(FX == FY);
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

  switch (Op) {
  // ---- Format F: wide immediate, warp-uniform broadcast (§3) -------------
  case CCG::MOVI:
  case CCG::MOVI48: {
    unsigned D = regOf(MI, 0);
    uint32_t Imm = uint32_t(MI.getOperand(1).getImm());
    forEachLane([&](unsigned L) { W.GPR[D][L] = Imm; });
    break;
  }

  // ---- Format K: srd -- the identity primitive (§5.3) --------------------
  case CCG::SRD: {
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
  case CCG::ADD: case CCG::SUB: case CCG::AND: case CCG::OR:
  case CCG::XOR: case CCG::ANDN: case CCG::SHL: case CCG::SHR:
  case CCG::SRA: case CCG::MIN_S: case CCG::MIN_U: case CCG::MAX_S:
  case CCG::MAX_U: case CCG::MUL_HI_S: case CCG::MUL_HI_U: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = aluRR(Op, W.GPR[A][L], W.GPR[B][L]);
    });
    break;
  }

  // ---- Format A: integer, one source (§4 points 20-24) -------------------
  case CCG::NEG: case CCG::ABS: case CCG::POPC:
  case CCG::CLZ: case CCG::BREV: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    forEachLane([&](unsigned L) { W.GPR[D][L] = aluR(Op, W.GPR[A][L]); });
    break;
  }

  case CCG::MADLO: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2), C = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = W.GPR[A][L] * W.GPR[B][L] + W.GPR[C][L];
    });
    break;
  }

  // ---- Format A: floating point (§4 points 32-63, format code 0 = FP32) ---
  case CCG::FADD: case CCG::FSUB: case CCG::FMUL:
  case CCG::FMIN: case CCG::FMAX: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = fpRR(Op, W.GPR[A][L], W.GPR[B][L]);
    });
    break;
  }
  case CCG::FNEG_F0: case CCG::FABS_F0: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    forEachLane([&](unsigned L) {
      float X = bitsToFloat(W.GPR[A][L]);
      W.GPR[D][L] = floatToBits(Op == CCG::FNEG_F0 ? -X : std::fabs(X));
    });
    break;
  }
  case CCG::FFMA_F0: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2), C = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = floatToBits(bitsToFloat(W.GPR[A][L]) * bitsToFloat(W.GPR[B][L]) +
                                bitsToFloat(W.GPR[C][L]));
    });
    break;
  }

  // ---- Format B: register-immediate --------------------------------------
  case CCG::ADDI:
  case CCG::ADDI48: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1);
    int32_t Imm = int32_t(MI.getOperand(2).getImm());
    forEachLane([&](unsigned L) { W.GPR[D][L] = W.GPR[A][L] + Imm; });
    break;
  }

  // ---- Format C / C': compare, writes one bit per lane -------------------
  // Operands are (pd, rd, pq, rs0, rs1|imm). rd is always allocated and the
  // opcode selects whether it is written (§3); none of these write it.
  case CCG::SETP_LT:   case CCG::SETP_LE:   case CCG::SETP_EQ:
  case CCG::SETP_NE:   case CCG::SETP_GT:   case CCG::SETP_GE:
  case CCG::SETP_LT_U: case CCG::SETP_LE_U: case CCG::SETP_GT_U:
  case CCG::SETP_GE_U: case CCG::SETP_LT_F: case CCG::SETP_LE_F:
  case CCG::SETP_EQ_F: case CCG::SETP_NE_F: case CCG::SETP_GT_F:
  case CCG::SETP_GE_F:
  case CCG::SETP_LT_I:   case CCG::SETP_LE_I:   case CCG::SETP_EQ_I:
  case CCG::SETP_NE_I:   case CCG::SETP_GT_I:   case CCG::SETP_GE_I:
  case CCG::SETP_LT_U_I: case CCG::SETP_LE_U_I: case CCG::SETP_GT_U_I:
  case CCG::SETP_GE_U_I: case CCG::SETP_LT_F_I: case CCG::SETP_LE_F_I:
  case CCG::SETP_EQ_F_I: case CCG::SETP_NE_F_I: case CCG::SETP_GT_F_I:
  case CCG::SETP_GE_F_I: {
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

  // ---- Format D: load / store --------------------------------------------
  case CCG::LD_GLOBAL:
  case CCG::ST_GLOBAL: {
    bool IsLoad = Op == CCG::LD_GLOBAL;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1);
    int64_t Off = MI.getOperand(2).getImm();
    forEachLane([&](unsigned L) {
      uint64_t A = (uint64_t(W.GPR[Base][L]) << kBaseShift) + Off;
      if (IsLoad) W.GPR[Data][L] = Mem.read32(A);
      else        Mem.write32(A, W.GPR[Data][L]);
    });
    break;
  }
  case CCG::LD_GLOBAL_IDX:
  case CCG::ST_GLOBAL_IDX: {
    bool IsLoad = Op == CCG::LD_GLOBAL_IDX;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1), Idx = regOf(MI, 2);
    // O-7: scale is log2(element size) from rdata's chwidth when enabled, so
    // an element index addresses correctly at any width. It only fires when
    // the in-window offset is zero -- see O-23.
    unsigned ScaleEn = unsigned(MI.getOperand(3).getImm());
    int64_t Disp = MI.getOperand(4).getImm();
    unsigned Sh = ScaleEn ? (2 - W.ChWidth[Data]) : 0;
    forEachLane([&](unsigned L) {
      uint64_t A = (uint64_t(W.GPR[Base][L]) << kBaseShift) +
                   (uint64_t(W.GPR[Idx][L]) << Sh) + Disp;
      if (IsLoad) W.GPR[Data][L] = Mem.read32(A);
      else        Mem.write32(A, W.GPR[Data][L]);
    });
    break;
  }

  // ---- Format D: shared memory -------------------------------------------
  // §5.1: `.shared` does not shift. The AGU computes rbase + (rindex << scale)
  // + disp -- a plain three-input add against a separate flat 32-bit space.
  case CCG::LD_SHARED:
  case CCG::ST_SHARED: {
    bool IsLoad = Op == CCG::LD_SHARED;
    unsigned Data = regOf(MI, 0), Base = regOf(MI, 1);
    int64_t Off = MI.getOperand(2).getImm();
    forEachLane([&](unsigned L) {
      uint64_t A = uint64_t(W.GPR[Base][L]) + Off;
      if (IsLoad) W.GPR[Data][L] = Shared.read32(A);
      else        Shared.write32(A, W.GPR[Data][L]);
    });
    break;
  }
  case CCG::LD_SHARED_IDX:
  case CCG::ST_SHARED_IDX: {
    bool IsLoad = Op == CCG::LD_SHARED_IDX;
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
  case CCG::C_ADD:   case CCG::C_SUB:   case CCG::C_MUL_LO: case CCG::C_AND:
  case CCG::C_OR:    case CCG::C_XOR:   case CCG::C_ANDN:   case CCG::C_SHL:
  case CCG::C_SHR:   case CCG::C_SRA:   case CCG::C_MIN_S:  case CCG::C_MIN_U:
  case CCG::C_MAX_S: case CCG::C_MAX_U: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = aluRR(Op, W.GPR[D][L], W.GPR[Sx][L]);
    });
    break;
  }
  case CCG::C_FADD: case CCG::C_FMUL: case CCG::C_FMIN: case CCG::C_FMAX: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = fpRR(Op, W.GPR[D][L], W.GPR[Sx][L]);
    });
    break;
  }
  case CCG::C_ADDI: case CCG::C_SUBI: case CCG::C_ANDI: case CCG::C_ORI:
  case CCG::C_XORI: case CCG::C_SHLI: case CCG::C_SHRI: case CCG::C_SRAI: {
    // The reg-imm points mirror the reg-reg operation, so reuse it. The 4-bit
    // immediate is unsigned (§3).
    static const std::pair<unsigned, unsigned> Map[] = {
        {CCG::C_ADDI, CCG::C_ADD}, {CCG::C_SUBI, CCG::C_SUB},
        {CCG::C_ANDI, CCG::C_AND}, {CCG::C_ORI,  CCG::C_OR},
        {CCG::C_XORI, CCG::C_XOR}, {CCG::C_SHLI, CCG::C_SHL},
        {CCG::C_SHRI, CCG::C_SHR}, {CCG::C_SRAI, CCG::C_SRA}};
    unsigned RR = 0;
    for (auto [I, O] : Map) if (I == Op) RR = O;
    unsigned D = regOf(MI, 0);
    uint32_t Imm = uint32_t(MI.getOperand(2).getImm());
    forEachLane([&](unsigned L) { W.GPR[D][L] = aluRR(RR, W.GPR[D][L], Imm); });
    break;
  }
  case CCG::C_NEG: case CCG::C_NOT: case CCG::C_ABS: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 1);
    forEachLane([&](unsigned L) { W.GPR[D][L] = aluR(Op, W.GPR[Sx][L]); });
    break;
  }
  case CCG::C_MOV: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 1);
    forEachLane([&](unsigned L) { W.GPR[D][L] = W.GPR[Sx][L]; });
    break;
  }

  // ---- Format J: compressed accumulate (rd read and written) -------------
  case CCG::FFMA_ACC_F0: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), B = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = floatToBits(bitsToFloat(W.GPR[A][L]) * bitsToFloat(W.GPR[B][L]) +
                                bitsToFloat(W.GPR[D][L]));
    });
    break;
  }
  case CCG::MAD_ACC: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 2), B = regOf(MI, 3);
    forEachLane([&](unsigned L) { W.GPR[D][L] += W.GPR[A][L] * W.GPR[B][L]; });
    break;
  }

  // ---- Format K: predicate logic (O-20) ----------------------------------
  case CCG::PAND:
  case CCG::POR:
  case CCG::PXOR: {
    unsigned D = regOf(MI, 0);
    uint32_t Q0 = uint32_t(MI.getOperand(1).getImm());
    uint32_t Q1 = uint32_t(MI.getOperand(2).getImm());
    // Both sources carry a 2-bit address plus a negate bit, in the same shape
    // as the predicate qualifier.
    uint32_t A = W.Pred[Q0 & 3], B = W.Pred[Q1 & 3];
    if (Q0 & 4) A = ~A;
    if (Q1 & 4) B = ~B;
    uint32_t V = Op == CCG::PAND ? (A & B) : Op == CCG::POR ? (A | B) : (A ^ B);
    W.Pred[D] = (W.Pred[D] & ~Mask) | (V & Mask);
    break;
  }

  // ---- Format E / K: control flow ----------------------------------------
  case CCG::BRA:
    R.Kind = Result::Branch;
    R.Target = PC + Size + 2 * MI.getOperand(0).getImm();
    break;
  case CCG::BRA_PRED: {
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
  case CCG::BAR_INIT:
    // The expected arrival count is configuration for the table entry. Here
    // every active lane is expected, so there is nothing to record.
    break;

  case CCG::C_BAR_ARRIVE: {
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

  case CCG::C_BAR_WAIT: {
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

  case CCG::BAR_WAIT_PHASE: {
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

  case CCG::C_FENCE:
    // Ordering only. A functional simulator with one warp and no store buffer
    // has nothing to order, but it must not be "unimplemented" -- the compiler
    // emits fences around every barrier and atomic sequence (§3).
    break;

  case CCG::C_EXIT:
    R.Kind = Result::Exit;
    break;

  default:
    return {Result::Unimplemented, 0};
  }
  return R;
}
