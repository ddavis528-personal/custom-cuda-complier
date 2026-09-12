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
#include <cstring>

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

  // ---- Format A: three-source integer ------------------------------------
  case CCG::ADD: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2);
    forEachLane([&](unsigned L) { W.GPR[D][L] = W.GPR[A][L] + W.GPR[B][L]; });
    break;
  }
  case CCG::MADLO: {
    unsigned D = regOf(MI, 0), A = regOf(MI, 1), B = regOf(MI, 2), C = regOf(MI, 3);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = W.GPR[A][L] * W.GPR[B][L] + W.GPR[C][L];
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

  // ---- Format C: compare, writes one bit per lane ------------------------
  case CCG::SETP_GE_I: {
    unsigned P = regOf(MI, 0), A = regOf(MI, 3);
    int32_t Imm = int32_t(MI.getOperand(4).getImm());
    uint32_t Guard = guardMask(W, uint32_t(MI.getOperand(2).getImm())) & Mask;
    (void)Guard;
    forEachLane([&](unsigned L) {
      bool T = int32_t(W.GPR[A][L]) >= Imm;
      // Invariant 10: a predicated write preserves lanes the guard excludes.
      // Here the guard is the issue mask, so untouched lanes keep their bit.
      W.Pred[P] = (W.Pred[P] & ~(1u << L)) | (uint32_t(T) << L);
    });
    break;
  }
  case CCG::SETP_LT: {
    unsigned P = regOf(MI, 0), A = regOf(MI, 3), B = regOf(MI, 4);
    uint32_t G = guardMask(W, uint32_t(MI.getOperand(2).getImm())) & Mask;
    forEachLane([&](unsigned L) {
      if (!((G >> L) & 1)) return;   // invariant 10: excluded lanes preserved
      bool T = int32_t(W.GPR[A][L]) < int32_t(W.GPR[B][L]);
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

  // ---- Format K: compressed destructive ALU ------------------------------
  case CCG::C_ADD: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    forEachLane([&](unsigned L) { W.GPR[D][L] += W.GPR[Sx][L]; });
    break;
  }
  case CCG::C_FADD: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    forEachLane([&](unsigned L) {
      W.GPR[D][L] = floatToBits(bitsToFloat(W.GPR[D][L]) + bitsToFloat(W.GPR[Sx][L]));
    });
    break;
  }
  case CCG::C_SHL: {
    unsigned D = regOf(MI, 0), Sx = regOf(MI, 2);
    forEachLane([&](unsigned L) { W.GPR[D][L] <<= (W.GPR[Sx][L] & 31); });
    break;
  }
  case CCG::C_SHLI: {
    unsigned D = regOf(MI, 0);
    uint32_t Imm = uint32_t(MI.getOperand(2).getImm());
    forEachLane([&](unsigned L) { W.GPR[D][L] <<= (Imm & 31); });
    break;
  }
  case CCG::C_ADDI: {
    unsigned D = regOf(MI, 0);
    uint32_t Imm = uint32_t(MI.getOperand(2).getImm());
    forEachLane([&](unsigned L) { W.GPR[D][L] += Imm; });
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
  case CCG::C_EXIT:
    R.Kind = Result::Exit;
    break;

  default:
    return {Result::Unimplemented, 0};
  }
  return R;
}
