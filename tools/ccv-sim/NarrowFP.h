//===-- NarrowFP.h - the FP formats of §4, exactly -------------------------===//
//
// CP-6. Every FP operation and conversion at a register width where §4's format
// table names something other than FP32 alone: FP16 and BF16 at 16 bits, E4M3 and
// E5M2 at 8 (OCP OFP8 1.0), E2M1 at 4 (OCP MX 1.0), and FP32 whenever it meets
// one of them. The rules are §4's (O-53, O-56):
//
//   - round as the instruction says (arithmetic: to nearest even), subnormals
//     kept as inputs and as results;
//   - at 16 and 32 bits IEEE 754: overflow to +-Inf under round-to-nearest, NaN
//     from an invalid operation;
//   - at 8 and 4 bits saturate: a result whose magnitude exceeds the format's
//     maximum, an infinite one included, is +-max finite (448, 57344, 6); a NaN
//     gives S.1111.111 for E4M3 and a quiet NaN for E5M2, and E2M1, which has
//     none, gives +6.
//
// A value is decoded exactly to sign x integer x 2^e, the arithmetic is exact in
// 128 bits with a sticky bit below, and one routine rounds it into any format.
// Nothing goes through a host float, so there is no double rounding to argue
// about: the ffma at 16 bits is one rounding of the exact a*b+c.
//
// The NaN a computation produces is the format's canonical NaN (O-66):
// positive, every mantissa bit set, NVIDIA's values -- FP32 0x7FFFFFFF, FP16
// and BF16 0x7FFF, E4M3 and E5M2 0x7F -- and no operand payload propagates.
//
//===----------------------------------------------------------------------===//
#ifndef CCV_SIM_NARROWFP_H
#define CCV_SIM_NARROWFP_H

#include <algorithm>
#include <cstdint>
#include <optional>
#include <utility>

namespace nfp {

enum class Round { RN = 0, RZ = 1, RM = 2, RP = 3 };

/// Mutation controls for tools/check-narrow-fp.py, set by ccv-sim's
/// -ccv-test-fp-ftz (flush subnormal results to zero) and
/// -ccv-test-fp-no-saturate (narrow overflow gives NaN, the rule O-56 rejected),
/// and for run-tests.sh's fp-canon, -ccv-test-fp-host-nan (FP32 NaN results
/// from host arithmetic, the rule O-66 replaced), and for mixed-width.s,
/// -ccv-test-mixed-by-value (integer sources extended at their own width, the
/// reading O-67 replaced).
inline bool TestFtz = false, TestNoSaturate = false, TestHostNaN = false,
            TestByValue = false;

struct Format {
  unsigned Bits, ExpBits, ManBits;
  int Bias;
  enum Special { IEEE, E4M3, None } Spec;
  bool Saturates;            // 8 and 4 bits (O-56)
  uint32_t NaN;              // what an invalid result encodes as
};

/// §4's table: the format a register at width code W (0 = 32, 1 = 16, 2 = 8,
/// 3 = 4) holds under FP format code C, or nothing where the code is reserved
/// at that width -- F-FORMAT.
inline std::optional<Format> format(uint8_t W, unsigned C) {
  switch (W * 2 + C) {
  case 0: return Format{32, 8, 23, 127, Format::IEEE, false, 0x7fffffffu}; // FP32
  case 2: return Format{16, 5, 10, 15, Format::IEEE, false, 0x7fffu};      // FP16
  case 3: return Format{16, 8, 7, 127, Format::IEEE, false, 0x7fffu};      // BF16
  case 4: return Format{8, 4, 3, 7, Format::E4M3, true, 0x7fu};            // E4M3
  case 5: return Format{8, 5, 2, 15, Format::IEEE, true, 0x7fu};           // E5M2
  case 6: return Format{4, 2, 1, 1, Format::None, true, 0x7u};             // E2M1: +6
  default: return std::nullopt;
  }
}

using u128 = unsigned __int128;

/// sign x M x 2^E, plus Sticky: the true magnitude lies strictly between
/// M x 2^E and (M + 1) x 2^E. Exact when Sticky is clear.
struct Value {
  enum Kind { Finite, Inf, NaN } K = Finite;
  bool Neg = false;
  u128 M = 0;
  int E = 0;
  bool Sticky = false;
  bool isZero() const { return K == Finite && M == 0 && !Sticky; }
};

inline Value decode(const Format &F, uint32_t Bits) {
  Value V;
  V.Neg = (Bits >> (F.Bits - 1)) & 1;
  uint32_t Exp = (Bits >> F.ManBits) & ((1u << F.ExpBits) - 1);
  uint32_t Man = Bits & ((1u << F.ManBits) - 1);
  uint32_t ExpMax = (1u << F.ExpBits) - 1;
  if (F.Spec == Format::IEEE && Exp == ExpMax) {
    V.K = Man ? Value::NaN : Value::Inf;
    return V;
  }
  if (F.Spec == Format::E4M3 && Exp == ExpMax && Man == (1u << F.ManBits) - 1) {
    V.K = Value::NaN;
    return V;
  }
  if (Exp == 0) {
    V.M = Man;
    V.E = 1 - F.Bias - int(F.ManBits);
  } else {
    V.M = Man | (1u << F.ManBits);
    V.E = int(Exp) - F.Bias - int(F.ManBits);
  }
  return V;
}

inline unsigned msb(u128 X) {
  uint64_t Hi = uint64_t(X >> 64);
  return Hi ? 127 - __builtin_clzll(Hi) : 63 - __builtin_clzll(uint64_t(X));
}

/// The largest finite encoding's magnitude bits.
inline uint32_t maxFinite(const Format &F) {
  uint32_t ExpMax = (1u << F.ExpBits) - 1, ManAll = (1u << F.ManBits) - 1;
  switch (F.Spec) {
  case Format::IEEE: return ((ExpMax - 1) << F.ManBits) | ManAll;
  case Format::E4M3: return (ExpMax << F.ManBits) | (ManAll - 1);
  default:           return (ExpMax << F.ManBits) | ManAll;
  }
}

/// Round a value into F. Overflow is IEEE's at 16 and 32 bits -- to infinity
/// or to the largest finite, by rounding direction -- and saturation at 8 and 4.
inline uint32_t encode(const Format &F, const Value &V, Round R) {
  const uint32_t Sign = uint32_t(V.Neg) << (F.Bits - 1);
  const uint32_t Max = maxFinite(F);
  const uint32_t InfBits = ((1u << F.ExpBits) - 1) << F.ManBits;
  auto overflow = [&]() -> uint32_t {
    if (F.Saturates)
      return TestNoSaturate ? F.NaN : (Sign | Max);
    bool ToInf = R == Round::RN || (R == Round::RP && !V.Neg) ||
                 (R == Round::RM && V.Neg);
    return Sign | (ToInf ? InfBits : Max);
  };
  if (V.K == Value::NaN)
    return F.NaN;
  if (V.K == Value::Inf)
    return F.Saturates ? (Sign | Max) : (Sign | InfBits);
  if (V.M == 0 && !V.Sticky)
    return Sign;

  // The least significant bit the result can carry: ManBits below its leading
  // bit, but never below the subnormal step.
  const int EMin = 1 - F.Bias;                       // the smallest normal's exponent
  int Lead = V.M ? int(msb(V.M)) + V.E : V.E - 1;    // a sticky-only value is tiny
  int Lsb = std::max(Lead, EMin) - int(F.ManBits);
  int Shift = Lsb - V.E;
  u128 Q;
  bool Gt = false, Eq = false, Inexact = V.Sticky;
  if (Shift <= 0) {
    Q = V.M << -Shift;               // exact; the sticky lies below the LSB
    Gt = false;                      // below half an LSB, however small
  } else if (Shift > 120) {
    Q = 0;
    Inexact = Inexact || V.M;        // far below half an LSB
  } else {
    Q = V.M >> Shift;
    u128 Rem = V.M & ((u128(1) << Shift) - 1);
    u128 Half = u128(1) << (Shift - 1);
    Gt = Rem > Half || (Rem == Half && V.Sticky);
    Eq = Rem == Half && !V.Sticky;
    Inexact = Inexact || Rem;
  }
  bool Up = false;
  switch (R) {
  case Round::RN: Up = Gt || (Eq && (Q & 1)); break;
  case Round::RZ: Up = false; break;
  case Round::RP: Up = Inexact && !V.Neg; break;
  case Round::RM: Up = Inexact && V.Neg; break;
  }
  Q += Up;
  if (Q >> (F.ManBits + 1)) {        // the round carried into a new binade
    Q >>= 1;
    ++Lsb;
  }
  if (Q == 0)
    return Sign;
  int BiasedExp = Q >> F.ManBits ? Lsb + int(F.ManBits) + F.Bias : 0;
  if (TestFtz && BiasedExp == 0)
    return Sign;
  if (BiasedExp > int((1u << F.ExpBits) - 1))
    return overflow();
  uint32_t Bits = (uint32_t(BiasedExp) << F.ManBits) |
                  uint32_t(Q & ((1u << F.ManBits) - 1));
  if (Bits > Max)
    return overflow();
  return Sign | Bits;
}

/// a + b, exactly (to 128 bits and a sticky bit). Sub is add of -b.
inline Value add(Value A, Value B, Round R) {
  Value Z;
  if (A.K == Value::NaN || B.K == Value::NaN) { Z.K = Value::NaN; return Z; }
  if (A.K == Value::Inf || B.K == Value::Inf) {
    if (A.K == Value::Inf && B.K == Value::Inf && A.Neg != B.Neg) {
      Z.K = Value::NaN;
      return Z;
    }
    return A.K == Value::Inf ? A : B;
  }
  if (A.M == 0 && B.M == 0) {        // signed zeros: IEEE's rule
    Z.Neg = A.Neg == B.Neg ? A.Neg : R == Round::RM;
    return Z;
  }
  if (A.M == 0) return B;
  if (B.M == 0) return A;
  if (A.E < B.E) std::swap(A, B);    // A has the larger exponent
  int D = A.E - B.E;
  bool Sticky = false;
  if (D <= 64) {
    A.M <<= D;
    A.E = B.E;
  } else {                           // B is far below A's last bit: jam it
    A.M <<= 64;
    A.E -= 64;
    B.M = 0;
    Sticky = true;
  }
  Z.E = A.E;
  if (A.Neg == B.Neg) {
    Z.Neg = A.Neg;
    Z.M = A.M + B.M;
    Z.Sticky = Sticky;
  } else if (Sticky) {               // A minus something tiny
    Z.Neg = A.Neg;
    Z.M = A.M - 1;
    Z.Sticky = true;
  } else if (A.M >= B.M) {
    Z.Neg = A.Neg;
    Z.M = A.M - B.M;
    if (Z.M == 0)
      Z.Neg = R == Round::RM;
  } else {
    Z.Neg = B.Neg;
    Z.M = B.M - A.M;
  }
  return Z;
}

inline Value mul(const Value &A, const Value &B) {
  Value Z;
  Z.Neg = A.Neg != B.Neg;
  if (A.K == Value::NaN || B.K == Value::NaN) { Z.K = Value::NaN; return Z; }
  if (A.K == Value::Inf || B.K == Value::Inf) {
    if (A.isZero() || B.isZero()) { Z.K = Value::NaN; return Z; }
    Z.K = Value::Inf;
    return Z;
  }
  Z.M = A.M * B.M;                   // at most 48 bits for FP32 operands
  Z.E = A.E + B.E;
  return Z;
}

inline Value neg(Value V) { V.Neg = !V.Neg; return V; }

/// Magnitude order for minNum/maxNum; -0 orders below +0.
inline int compare(const Value &A, const Value &B) {
  auto Key = [](const Value &V) { return V.K == Value::Inf ? 1 : 0; };
  if (A.Neg != B.Neg)
    return A.Neg ? -1 : 1;
  int Mag;
  if (Key(A) != Key(B)) {
    Mag = Key(A) - Key(B);
  } else if (A.K == Value::Inf) {
    Mag = 0;
  } else if (A.M == 0 || B.M == 0) {
    Mag = (A.M != 0) - (B.M != 0);
  } else {
    int LA = int(msb(A.M)) + A.E, LB = int(msb(B.M)) + B.E;
    if (LA != LB) {
      Mag = LA < LB ? -1 : 1;
    } else {
      int E = std::min(A.E, B.E);
      u128 MA = A.M << (A.E - E), MB = B.M << (B.E - E);
      Mag = MA < MB ? -1 : MA > MB ? 1 : 0;
    }
  }
  return A.Neg ? -Mag : Mag;
}

/// An integer of W bits, signed or not, as a value.
inline Value fromInt(uint32_t Bits, unsigned W, bool Signed) {
  Value V;
  uint64_t Mask = W == 32 ? 0xffffffffull : ((1ull << W) - 1);
  uint64_t X = Bits & Mask;
  if (Signed && (X >> (W - 1)) & 1) {
    V.Neg = true;
    X = ((~X) + 1) & Mask;
    if (X == 0) X = 1ull << (W - 1);  // the most negative value
  }
  V.M = X;
  return V;
}

/// A value to a W-bit integer: rounded as R says, NaN to zero, out of range
/// saturated (§4's conversion contract).
inline uint32_t toInt(const Value &V, unsigned W, bool Signed, Round R) {
  int64_t Lo = Signed ? -(int64_t(1) << (W - 1)) : 0;
  int64_t Hi = Signed ? (int64_t(1) << (W - 1)) - 1 : (int64_t(1) << W) - 1;
  uint32_t Mask = W == 32 ? 0xffffffffu : ((1u << W) - 1);
  auto pack = [&](int64_t X) { return uint32_t(uint64_t(X)) & Mask; };
  if (V.K == Value::NaN)
    return 0;
  if (V.K == Value::Inf)
    return pack(V.Neg ? Lo : Hi);
  // Magnitude rounded to an integer, in the direction R gives for the sign.
  u128 Q;
  bool Inexact = V.Sticky, Gt = false, Eq = false;
  if (V.E >= 0) {
    if (V.M && (msb(V.M) + V.E > 70))
      return pack(V.Neg ? Lo : Hi);
    Q = V.M << V.E;
  } else if (-V.E > 120) {
    Q = 0;
    Inexact = Inexact || V.M;
  } else {
    int S = -V.E;
    Q = V.M >> S;
    u128 Rem = V.M & ((u128(1) << S) - 1), Half = u128(1) << (S - 1);
    Gt = Rem > Half || (Rem == Half && V.Sticky);
    Eq = Rem == Half && !V.Sticky;
    Inexact = Inexact || Rem;
  }
  bool Up = R == Round::RN ? (Gt || (Eq && (Q & 1)))
          : R == Round::RP ? (Inexact && !V.Neg)
          : R == Round::RM ? (Inexact && V.Neg) : false;
  Q += Up;
  if (Q > (u128(1) << 40))           // past every width's range, either sign
    return pack(V.Neg ? Lo : Hi);
  int64_t X = V.Neg ? -int64_t(uint64_t(Q)) : int64_t(uint64_t(Q));
  if (!V.Neg && Q > u128(Hi)) X = Hi;
  if (X < Lo) X = Lo;
  if (X > Hi) X = Hi;
  return pack(X);
}

} // namespace nfp

#endif
