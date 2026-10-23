//===-- SfuMath.cpp - the FP SFU's values, without a host library ---------===//
//
// Every value here comes from integer arithmetic: 128-bit fixed point for the
// series, Payne-Hanek with 608 bits of 2/pi for sin and cos, and exact integer
// roots and quotients for rcp, rsqrt and sqrt. Nothing calls the host's libm
// or its floating-point unit, so the same input gives the same bits on every
// build host (O-70; IS-12's original finding was std::exp2f and friends).
//
// The series are carried to 2^-120 or better, relative, and FP32's hardest
// cases for these functions are nowhere near that close to a rounding
// boundary, so rounding the approximation gives the correctly rounded value.
// tools/check-sfu-math.py holds that down against an independent reference.
//
//===----------------------------------------------------------------------===//

#include "SfuMath.h"

namespace sfu {

bool TestTruncate = false;

namespace {

using u64 = uint64_t;
using u128 = unsigned __int128;
using i128 = __int128;

/// A real m * 2^(e - 127) with m's bit 127 set, so e is the floor of its log2;
/// m == 0 is zero. Inexact says it was truncated from a value that is not a
/// float, which decides a would-be tie upward (truncation only lowers it).
struct BF {
  u128 m = 0;
  int e = 0;
  bool neg = false;
  bool inexact = false;
};

int clz128(u128 X) {
  u64 Hi = u64(X >> 64);
  return Hi ? __builtin_clzll(Hi) : 64 + __builtin_clzll(u64(X));
}

/// m * 2^(e - 127) for any nonzero m, normalized.
BF norm(u128 M, int E, bool Neg, bool Inexact) {
  if (!M)
    return {0, 0, Neg, Inexact};
  int S = clz128(M);
  return {M << S, E - S, Neg, Inexact};
}

/// The high 128 bits of A * B.
u128 mulhi(u128 A, u128 B) {
  u64 A1 = u64(A >> 64), A0 = u64(A), B1 = u64(B >> 64), B0 = u64(B);
  u128 P00 = u128(A0) * B0, P01 = u128(A0) * B1, P10 = u128(A1) * B0,
       P11 = u128(A1) * B1;
  u128 Mid = (P00 >> 64) + u64(P01) + u64(P10);
  return P11 + (P01 >> 64) + (P10 >> 64) + (Mid >> 64);
}

BF mul(const BF &A, const BF &B) {
  // A.m * B.m = hi * 2^128 + lo, so the product is hi * 2^(A.e + B.e - 126).
  return norm(mulhi(A.m, B.m), A.e + B.e + 1, A.neg != B.neg, true);
}

/// floor(A * 2^128 / B), for A < B < 2^64.
u128 divfrac(u64 A, u64 B) {
  u128 N = u128(A) << 64;
  u128 Q1 = N / B, R = N % B;
  return (Q1 << 64) | ((R << 64) / B);
}

/// Round to nearest even, into FP32's normal and subnormal range.
uint32_t toFloat(const BF &V) {
  const uint32_t Sign = V.neg ? 0x80000000u : 0;
  if (!V.m)
    return Sign;
  if (V.e > 127)
    return Sign | 0x7F800000u;
  // The significant bits FP32 keeps at this magnitude: 24 when normal, down to
  // the 2^-149 bit when subnormal.
  int Kept = V.e >= -126 ? 24 : V.e + 150;
  if (Kept < 0)
    return Sign;
  u128 R = Kept ? V.m >> (128 - Kept) : 0;
  u128 Rem = Kept ? V.m << Kept : V.m;
  bool Half = Rem >> 127, Rest = (Rem << 1) != 0 || V.inexact;
  if (!TestTruncate && Half && (Rest || (R & 1)))
    ++R;
  if (V.e < -126)            // subnormal, or the least normal if it rounded up
    return Sign | uint32_t(R);
  int E = V.e;
  if (R >> 24) {
    R >>= 1;
    ++E;
  }
  if (E > 127)
    return Sign | 0x7F800000u;
  return Sign | uint32_t(E + 127) << 23 | (uint32_t(R) & 0x7FFFFFu);
}

/// |X| = M * 2^K with M in [2^23, 2^24), for a finite nonzero X.
void decode(uint32_t X, u64 &M, int &K) {
  uint32_t E = (X >> 23) & 0xFF;
  M = X & 0x7FFFFF;
  if (E) {
    M |= 0x800000;
    K = int(E) - 150;
    return;
  }
  K = -149;
  while (M < 0x800000) {
    M <<= 1;
    --K;
  }
}

BF fromFloat(uint32_t X) {
  u64 M;
  int K;
  decode(X, M, K);
  return norm(M, K + 127, X >> 31, false);
}

// ---- constants -------------------------------------------------------------

const u128 Ln2 =                            // ln 2, Q0.128
    u128(0xb17217f7d1cf79abull) << 64 | 0xc9e3b39803f2f6afull;
const u128 Log2e =                          // log2 e, Q1.127
    u128(0xb8aa3b295c17f0bbull) << 64 | 0xbe87fed0691d3e88ull;
const BF PiOver2 = {u128(0xc90fdaa22168c234ull) << 64 | 0xc4c6628b80dc1cd1ull,
                    0, false, true};
// 2/pi to 608 bits, most significant word first.
const uint32_t TwoOverPi[19] = {
    0xa2f9836e, 0x4e441529, 0xfc2757d1, 0xf534ddc0, 0xdb629599,
    0x3c439041, 0xfe5163ab, 0xdebbc561, 0xb7246e3a, 0x424dd2e0,
    0x06492eea, 0x09d1921c, 0xfe1deb1c, 0xb129a73e, 0xe88235f5,
    0x2ebb4484, 0xe99c7026, 0xb45f7e41, 0x3991d639};

const uint32_t QNaN = 0x7FFFFFFFu, PInf = 0x7F800000u, NInf = 0xFF800000u,
               One = 0x3F800000u;

bool isNaN(uint32_t X) { return (X & 0x7FFFFFFFu) > 0x7F800000u; }

// ---- the functions -----------------------------------------------------------
//
// Each returns true with R set for a special value O-70 fixes exactly, and
// otherwise sets V to the value (exact, or truncated and marked inexact).

bool rcp(uint32_t X, uint32_t &R, BF &V) {
  if (isNaN(X)) return R = QNaN, true;
  if (!(X & 0x7FFFFFFFu)) return R = (X & 0x80000000u) | PInf, true;
  if ((X & 0x7FFFFFFFu) == PInf) return R = X & 0x80000000u, true;
  u64 M;
  int K;
  decode(X, M, K);
  // 1/x = (2^23 / M) * 2^(-23 - K): 128 bits of the quotient, and never a
  // tie, since 1/M is a midpoint only if M is a power of two.
  V = M == (u64(1) << 23) ? BF{u128(1) << 127, -23 - K, X >> 31 != 0, false}
                          : BF{divfrac(u64(1) << 23, M), -24 - K, X >> 31 != 0, true};
  return false;
}

/// floor(sqrt(N)).
u128 isqrt(u128 N) {
  u128 R = 0, B = u128(1) << 126;
  while (B > N) B >>= 2;
  while (B) {
    if (N >= R + B) {
      N -= R + B;
      R = (R >> 1) + B;
    } else {
      R >>= 1;
    }
    B >>= 2;
  }
  return R;
}

bool sqrt(uint32_t X, uint32_t &R, BF &V) {
  if (isNaN(X)) return R = QNaN, true;
  if (!(X & 0x7FFFFFFFu)) return R = X, true;
  if (X >> 31) return R = QNaN, true;
  if (X == PInf) return R = PInf, true;
  u64 M;
  int K;
  decode(X, M, K);
  if (K & 1) {
    M <<= 1;
    --K;
  }
  // sqrt(M * 2^100) = sqrt(M) * 2^50, about 62 bits, its remainder the sticky.
  u128 N = u128(M) << 100, S = isqrt(N);
  V = norm(S, 127 + K / 2 - 50, false, S * S != N);
  return false;
}

bool rsqrt(uint32_t X, uint32_t &R, BF &V, BF &Ex) {
  if (isNaN(X)) return R = QNaN, true;
  if (!(X & 0x7FFFFFFFu)) return R = (X & 0x80000000u) | PInf, true;
  if (X >> 31) return R = QNaN, true;
  if (X == PInf) return R = 0, true;
  u64 M;
  int K;
  decode(X, M, K);
  if (K & 1) {
    M <<= 1;
    --K;
  }
  // The largest Q with Q^2 * M <= 2^120: floor(2^60 / sqrt(M)), about 47 bits.
  const u128 Top = u128(1) << 120;
  u128 Q = 0;
  for (int B = 50; B >= 0; --B) {
    u128 T = Q | (u128(1) << B);
    if (T * T <= Top / M && T * T * M <= Top)
      Q = T;
  }
  V = norm(Q, 127 - 60 - K / 2, false, Q * Q * M != Top);
  // That is exact enough to round, not to measure an excursion by: 1/x^(1/2)
  // again, to 2^-62, as 2^128 / sqrt(M * 2^102) = 2^77 / sqrt(M).
  u128 S = isqrt(u128(M) << 102);
  Ex = norm(divfrac(1, u64(S)), 50 - K / 2, false, true);
  return false;
}

bool ex2(uint32_t X, uint32_t &R, BF &V) {
  if (isNaN(X)) return R = QNaN, true;
  if (X == PInf) return R = PInf, true;
  if (X == NInf) return R = 0, true;
  if (!(X & 0x7FFFFFFFu)) return R = One, true;
  const uint32_t A = X & 0x7FFFFFFFu;
  const bool Neg = X >> 31;
  // Below |x| = 2^-100, 2^x is 1 to within 2^-100: it rounds to 1, and the
  // value is kept on the right side of 1 for -sfu-error-ulps.
  if (A < 0x0D800000u) {
    V = Neg ? BF{~u128(0), -1, false, true}
            : BF{(u128(1) << 127) | 1, 0, false, true};
    return false;
  }
  if (!Neg && A >= 0x43000000u) {           // x >= 128: 2^x overflows
    V = {u128(1) << 127, 128, false, false};
    return false;
  }
  if (Neg && A > 0x43170000u) {             // x < -151: below 2^-151
    V = {u128(1) << 127, -152, false, true};
    return false;
  }
  u64 M;
  int K;
  decode(X, M, K);
  // x = n + f with f in [0, 1), f in Q0.128. K is in [-123, 7] here.
  int64_t N;
  u128 F;
  if (K >= 0) {
    N = int64_t(M << K);
    F = 0;
  } else if (K <= -24) {
    N = 0;
    F = u128(M) << (128 + K);
  } else {
    N = int64_t(M >> -K);
    F = u128(M & ((u64(1) << -K) - 1)) << (128 + K);
  }
  if (Neg) {
    N = -N;
    if (F) {
      --N;
      F = -F;
    }
  }
  // 2^f = e^(f ln 2), the series in Q1.127.
  u128 T = mulhi(F, Ln2), Sum = u128(1) << 127, Term = Sum;
  for (unsigned J = 1; Term; ++J) {
    Term = mulhi(Term, T) / J;
    Sum += Term;
  }
  V = {Sum, int(N), false, F != 0};
  return false;
}

bool lg2(uint32_t X, uint32_t &R, BF &V) {
  if (isNaN(X)) return R = QNaN, true;
  if (!(X & 0x7FFFFFFFu)) return R = NInf, true;
  if (X >> 31) return R = QNaN, true;
  if (X == PInf) return R = PInf, true;
  if (X == One) return R = 0, true;
  u64 M;
  int K;
  decode(X, M, K);
  // x = m * 2^e with m in [sqrt(1/2), sqrt(2)): m = M / D.
  int E = K + 23;
  u64 D = u64(1) << 23;
  if (M > 11863283) {                       // sqrt(2) * 2^23 = 11863283.2
    D <<= 1;
    ++E;
  }
  // ln m = 2 atanh(s), s = (m - 1) / (m + 1), |s| <= 0.1716; Q0.128.
  const bool Below = M < D;
  u128 Lg = 0;                              // log2 m, Q.126
  if (M != D) {
    u128 S = divfrac(Below ? D - M : M - D, M + D), S2 = mulhi(S, S);
    u128 Sum = S, Term = S;
    for (unsigned J = 1;; ++J) {
      Term = mulhi(Term, S2);
      if (!Term)
        break;
      Sum += Term / (2 * J + 1);
    }
    Lg = mulhi(Sum, Log2e);                 // atanh * log2 e * 2^127
  }
  if (E == 0) {
    V = norm(Lg, 1, Below, true);
    return false;
  }
  i128 Lq = i128(Lg >> 8), Tot = (i128(E) << 118) + (Below ? -Lq : Lq);
  V = norm(u128(Tot < 0 ? -Tot : Tot), 9, Tot < 0, true);
  return false;
}

/// sin(r)/r and cos(r) for |r| <= pi/4, from r^2 in Q0.128; Q1.127.
u128 trigSeries(u128 R2, bool Cosine) {
  u128 Sum = u128(1) << 127, Term = Sum;
  for (unsigned J = 1;; ++J) {
    u128 D = Cosine ? u128(2 * J - 1) * (2 * J) : u128(2 * J) * (2 * J + 1);
    Term = mulhi(Term, R2) / D;
    if (!Term)
      break;
    if (J & 1)
      Sum -= Term;
    else
      Sum += Term;
  }
  return Sum;
}

bool trig(uint32_t X, bool Cosine, uint32_t &R, BF &V) {
  const uint32_t A = X & 0x7FFFFFFFu;
  const bool Neg = X >> 31;
  if (A >= PInf) return R = QNaN, true;
  if (!A) return R = Cosine ? One : X, true;
  // x = (q + f) pi/2 with f in [-1/2, 1/2): r = f pi/2.
  BF Rd;
  unsigned Q = 0;
  if (A <= 0x3F490FDAu) {                   // below pi/4
    Rd = fromFloat(A);
  } else {
    u64 M;
    int K;
    decode(A, M, K);
    // y = M * T * 2^(K - 608), T the 2/pi words; the point is at bit 608 - K.
    uint32_t P[20];
    u64 Carry = 0;
    for (int I = 0; I != 19; ++I) {
      u64 Cur = M * TwoOverPi[18 - I] + Carry;
      P[I] = uint32_t(Cur);
      Carry = Cur >> 32;
    }
    P[19] = uint32_t(Carry);
    auto Bits = [&](int Lo) -> u64 {        // bits [Lo, Lo + 64)
      int W = Lo / 32, Off = Lo % 32;
      u128 V = 0;
      for (int I = 2; I >= 0; --I)
        V = (V << 32) | (W + I < 20 ? P[W + I] : 0);
      return u64(V >> Off);
    };
    const int B0 = 608 - K;                 // K in [-24, 104]
    Q = unsigned(Bits(B0)) & 3;
    u64 F2 = Bits(B0 - 64), F1 = Bits(B0 - 128), F0 = Bits(B0 - 192);
    bool RNeg = false;
    if (F2 >> 63) {                         // f >= 1/2: take f - 1, a quadrant on
      F0 = ~F0 + 1;
      F1 = ~F1 + (F0 == 0);
      F2 = ~F2 + (F0 == 0 && F1 == 0);
      Q = (Q + 1) & 3;
      RNeg = true;
    }
    int Z = 0;
    while (!F2 && Z < 192) {
      F2 = F1;
      F1 = F0;
      F0 = 0;
      Z += 64;
    }
    if (int S = F2 ? __builtin_clzll(F2) : 0) {
      F2 = F2 << S | F1 >> (64 - S);
      F1 = F1 << S | F0 >> (64 - S);
      Z += S;
    }
    BF Fb = {u128(F2) << 64 | F1, -1 - Z, RNeg, true};
    Rd = mul(Fb, PiOver2);
  }
  // r^2, Q0.128: r = m * 2^(e - 127), so r * 2^128 = m >> -(e + 1).
  const int Sh = -(Rd.e + 1);
  const u128 Rq = Sh >= 128 ? 0 : Rd.m >> Sh, R2 = mulhi(Rq, Rq);
  // Which of sin r, cos r, and its sign: sin and cos by quadrant.
  bool UseCos = (Q & 1) != Cosine;
  bool Flip = Cosine ? (Q == 1 || Q == 2) : (Q >= 2);
  if (UseCos) {
    V = norm(trigSeries(R2, true), 0, false, true);
  } else {
    V = mul(Rd, norm(trigSeries(R2, false), 0, false, true));
  }
  V.neg ^= Flip;
  if (!Cosine)
    V.neg ^= Neg;
  return false;
}

/// V rounds to the correctly rounded value; Ex, when it is not V, is a finer
/// value for measuring an excursion from.
bool compute(Fn F, uint32_t X, uint32_t &R, BF &V, BF &Ex) {
  Ex.m = 0;
  switch (F) {
  case Rcp:   return rcp(X, R, V);
  case Rsqrt: return rsqrt(X, R, V, Ex);
  case Sqrt:  return sqrt(X, R, V);
  case Ex2:   return ex2(X, R, V);
  case Lg2:   return lg2(X, R, V);
  case Sin:   return trig(X, false, R, V);
  case Cos:   return trig(X, true, R, V);
  }
  return R = QNaN, true;
}

// ---- -sfu-error-ulps -----------------------------------------------------------

/// A value as a signed integer count of 2^U.
i128 inUnits(const BF &V, int U) {
  int Sh = V.e - 127 - U;                   // V = m * 2^(Sh + U)
  u128 Mag = Sh >= 0 ? (Sh >= 128 ? ~u128(0) >> 1 : V.m << Sh)
                     : (-Sh >= 128 ? 0 : V.m >> -Sh);
  return V.neg ? -i128(Mag) : i128(Mag);
}

/// The FP32 value next to B in the direction of Up, through zero and in
/// value order, never past the largest finite value.
uint32_t step(uint32_t B, bool Up) {
  int64_t O = (B >> 31) ? -int64_t(B & 0x7FFFFFFFu) : int64_t(B);
  O += Up ? 1 : -1;
  if (O >= 0x7F800000) O = 0x7F7FFFFF;
  if (O <= -0x7F800000) O = -0x7F7FFFFF;
  return O < 0 ? 0x80000000u | uint32_t(-O) : uint32_t(O);
}

} // namespace

uint32_t eval(Fn F, uint32_t X) {
  uint32_t R;
  BF V, Ex;
  return compute(F, X, R, V, Ex) ? R : toFloat(V);
}

uint32_t evalWithin(Fn F, uint32_t X, unsigned N) {
  uint32_t R;
  BF V, Finer;
  if (compute(F, X, R, V, Finer))
    return R;
  const uint32_t C = toFloat(V);
  if (Finer.m)
    V = Finer;
  if (!N || !(C & 0x7FFFFFFFu) || (C & 0x7FFFFFFFu) == PInf)
    return C;
  uint32_t H = X * 0x9E3779B1u;             // Fibonacci hash of the input
  H ^= H >> 15;
  const int64_t D = int64_t(H % (2 * u64(N) + 1)) - int64_t(N);
  const uint32_t A = X & 0x7FFFFFFFu;
  const bool Trig = F == Sin || F == Cos;
  if (Trig && A > 0x40490FDAu) {            // beyond pi: any value in [-1, 1]
    if (!D)
      return C;
    u64 Mag = u64(D < 0 ? -D : D);
    BF T = Mag == N ? BF{u128(1) << 127, 0, D < 0, false}
                    : norm(divfrac(Mag, N), -1, D < 0, true);
    return toFloat(T);
  }
  // The unit: an ulp of the exact value, or O-70's absolute unit.
  int UnitExp;
  if (F == Lg2 && X >= 0x3F000000u && X <= 0x40000000u)
    UnitExp = -23;
  else if (Trig)
    UnitExp = -22;
  else
    UnitExp = (V.e < -126 ? -126 : V.e) - 23;
  // Everything in units of 2^(UnitExp - 64): the bound is N * 2^64 of them.
  const int U = UnitExp - 64;
  const i128 Ex = inUnits(V, U), Bound = i128(N) << 64;
  BF Target;
  {
    i128 T = Ex + i128(D) * (i128(1) << 64);
    Target = norm(u128(T < 0 ? -T : T), U + 127, T < 0, false);
  }
  uint32_t Cand = toFloat(Target);
  for (int I = 0; I != 64; ++I) {
    bool Bad = !(Cand & 0x7FFFFFFFu) || (Cand & 0x7FFFFFFFu) >= PInf;
    i128 Cv = Bad ? 0 : inUnits(fromFloat(Cand), U);
    i128 Dist = Cv - Ex;
    if (!Bad && (Dist < 0 ? -Dist : Dist) <= Bound)
      return Cand;
    if ((Cand & 0x7FFFFFFFu) >= PInf)
      Cand = step(Cand, Cand >> 31);
    else
      Cand = step(Cand, Cv < Ex);
  }
  return C;
}

} // namespace sfu
