//===-- model-ieee-sfu - the IEEE divide and sqrt, over an approximate SFU --===//
//
// IS-12 makes the FP SFU approximate, so CUDA's IEEE `/`, `1.0f/x` and `sqrtf`
// are sequences over its seeds (CCVExpandDivision: fdiv32, sqrt32). This is
// those two functions, operation for operation, on the host's IEEE fp32 with a
// seed that may be off by up to N ulps either way, checked against an exact
// reference: NarrowFP.h's rounding of the exact quotient or square root, which
// shares no arithmetic with the sequences.
//
// What can be exhaustive is. The sequences' arithmetic depends only on the
// reduced operand, in [1, 2) or [1, 4), so:
//   - 1/x: every reduced divisor (2^23) at every seed error -N..N;
//   - sqrt: every reduced argument (2^24) at every seed error;
//   - with --all, every one of the 2^32 inputs to each, seed error from a hash;
//   - a / b: --divs random pairs, half drawn from the specials and the ends of
//     the exponent range, at a hashed seed error and at -N and +N.
//
// Usage: model-ieee-sfu [--ulps N] [--divs K] [--all] [--control]
//   --control breaks the sequences the way a correctly rounded SFU would have
//   hidden (the divide's residual check of the last bit and sqrt's Goldschmidt
//   step dropped), so the checker must fail.
//
//===----------------------------------------------------------------------===//

#include "../ccv-sim/NarrowFP.h"
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>
#include <string>

using namespace nfp;

static unsigned Ulps = 2;
static bool Control = false;

static float fb(uint32_t B) { float F; std::memcpy(&F, &B, 4); return F; }
static uint32_t bf(float F) { uint32_t B; std::memcpy(&B, &F, 4); return B; }

/// A seed off by D ulps (same rule as ccv-sim's sfuError).
static float seed(float Exact, int D) {
  uint32_t R = bf(Exact), M = R & 0x7FFFFFFFu;
  if (!M || (R & 0x7F800000u) == 0x7F800000u)
    return Exact;
  int64_t Moved = int64_t(M) + D;
  if (Moved < 1 || Moved >= 0x7F800000)
    return Exact;
  return fb((R & 0x80000000u) | uint32_t(Moved));
}
static int hashD(uint32_t X) {
  uint32_t H = X * 0x9E3779B1u;
  H ^= H >> 15;
  return int(H % (2 * Ulps + 1)) - int(Ulps);
}

// ---- The sequences, as CCVExpandDivision writes them ---------------------

static uint32_t fdiv32(uint32_t IA, uint32_t ID, int D) {
  uint32_t Sign = (IA ^ ID) & 0x80000000u;
  uint32_t MagA = IA & 0x7FFFFFFFu, MagD = ID & 0x7FFFFFFFu;
  auto reduce = [](uint32_t Mag, int &Ex) {
    bool Sub = Mag < 0x00800000u;
    uint32_t N = Sub ? bf(fb(Mag) * 16777216.0f) : Mag;
    Ex = int(N >> 23) - (Sub ? 24 : 0);
    return fb((N & 0x007FFFFFu) | 0x3F800000u);
  };
  int Ea, Eb;
  float Am = reduce(MagA, Ea), Bm = reduce(MagD, Eb);
  float Y = seed(1.0f / Bm, D);
  for (int I = 0; I != 2; ++I)
    Y = std::fmaf(Y, std::fmaf(-Bm, Y, 1.0f), Y);
  float Q = Am * Y;
  float Qm = std::fmaf(std::fmaf(-Bm, Q, Am), Y, Q);
  float R2 = std::fmaf(-Bm, Qm, Am);
  if (!Control) {                        // the last bit, from exact residuals
    uint32_t Iq = bf(Qm);
    float Up = fb(Iq + 1), Dn = fb(Iq - 1);
    float Mu = std::fmaf(-Bm, (Up - Qm) * 0.5f, R2);   // vs the midpoint above
    float Md = std::fmaf(Bm, (Qm - Dn) * 0.5f, R2);    // vs the midpoint below
    bool Odd = Iq & 1;
    if (R2 > 0 && (Mu > 0 || (Mu == 0 && Odd))) Qm = Up;
    else if (R2 < 0 && (Md < 0 || (Md == 0 && Odd))) Qm = Dn;
    R2 = std::fmaf(-Bm, Qm, Am);
  }
  uint32_t IQ = bf(Qm);
  int E = int(IQ >> 23) - 127 + (Ea - Eb);
  uint32_t Frac = IQ & 0x007FFFFFu, Res;
  if (E > 127) {
    Res = 0x7F800000u;
  } else if (E >= -126) {
    Res = (uint32_t(E + 127) << 23) | Frac;
  } else {
    uint32_t N24 = Frac | 0x00800000u;
    int Sh = -126 - E;
    bool Far = Sh > 24;
    int ShC = Far ? 24 : Sh;
    uint32_t Qs = N24 >> ShC, Rem = N24 & ((1u << ShC) - 1), Half = 1u << (ShC - 1);
    bool Up = Rem > Half || (Rem == Half && (R2 > 0 || (R2 == 0 && (Qs & 1))));
    Res = Far ? 0 : Qs + Up;
  }
  bool AZ = MagA == 0, DZ = MagD == 0, AI = MagA == 0x7F800000u,
       DI = MagD == 0x7F800000u;
  bool NaN = MagA > 0x7F800000u || MagD > 0x7F800000u || (AZ && DZ) || (AI && DI);
  if (AZ || DI) Res = 0;
  if (AI || DZ) Res = 0x7F800000u;
  Res |= Sign;
  return NaN ? 0x7FFFFFFFu : Res;
}

static uint32_t sqrt32(uint32_t IX, int D) {
  bool Sub = IX < 0x00800000u;
  uint32_t N = Sub ? bf(fb(IX) * 16777216.0f) : IX;
  int E = int(N >> 23) - 127 - (Sub ? 24 : 0);
  int Odd = E & 1;
  float M = fb((N & 0x007FFFFFu) | (uint32_t(127 + Odd) << 23));
  int J = (E - Odd) >> 1;
  float Y = seed(1.0f / std::sqrt(M), D);
  float G = M * Y, H = 0.5f * Y;
  if (!Control) {
    float R = std::fmaf(-G, H, 0.5f);
    G = std::fmaf(G, R, G);
    H = std::fmaf(H, R, H);
  }
  float S = std::fmaf(std::fmaf(-G, G, M), H, G);
  uint32_t Res = bf(S) + uint32_t(J << 23);
  uint32_t Mag = IX & 0x7FFFFFFFu;
  bool Self = Mag == 0 || IX == 0x7F800000u;
  bool NaN = Mag > 0x7F800000u || (Mag != 0 && int32_t(IX) < 0);
  if (Self) Res = IX;
  return NaN ? 0x7FFFFFFFu : Res;
}

// ---- Exact references -----------------------------------------------------

static const Format F32 = *format(0, 0);

static uint32_t refDiv(uint32_t IA, uint32_t ID) {
  Value A = decode(F32, IA), B = decode(F32, ID);
  bool Neg = A.Neg != B.Neg;
  if (A.K == Value::NaN || B.K == Value::NaN ||
      (A.K == Value::Inf && B.K == Value::Inf) || (A.isZero() && B.isZero()))
    return 0x7FFFFFFFu;
  uint32_t S = Neg ? 0x80000000u : 0;
  if (A.K == Value::Inf || B.isZero()) return S | 0x7F800000u;
  if (B.K == Value::Inf || A.isZero()) return S;
  // A.M, B.M < 2^24: (A.M << 80) / B.M has at least 57 bits, and the rest is
  // the sticky bit.
  u128 Num = A.M << 80;
  Value Q;
  Q.Neg = Neg;
  Q.M = Num / B.M;
  Q.Sticky = Num % B.M != 0;
  Q.E = A.E - B.E - 80;
  return encode(F32, Q, Round::RN);
}

static u128 isqrt(u128 V) {             // floor(sqrt(V))
  u128 R = u128(std::sqrt(double(V)));
  while (R * R > V) --R;
  while ((R + 1) * (R + 1) <= V) ++R;
  return R;
}

static uint32_t refSqrt(uint32_t IX) {
  Value X = decode(F32, IX);
  if (X.K == Value::NaN || (X.Neg && !X.isZero())) return 0x7FFFFFFFu;
  if (X.isZero() || X.K == Value::Inf) return IX;
  // X = M * 2^E. Shift M to 54 or 55 bits whatever its width (a subnormal's
  // can be one bit), with an even exponent left: the root then has 27 bits,
  // enough to round to 24 with a sticky bit.
  int Sh = 54 - int(msb(X.M));
  if ((X.E - Sh) & 1)
    ++Sh;
  u128 V = X.M << Sh;
  Value R;
  R.M = isqrt(V);
  R.Sticky = R.M * R.M != V;
  R.E = (X.E - Sh) / 2;
  return encode(F32, R, Round::RN);
}

// ---- The checks -----------------------------------------------------------

struct Tally {
  const char *Name;
  uint64_t N = 0, Bad = 0;
  uint32_t A = 0, B = 0, Got = 0, Want = 0;
  void see(uint32_t X, uint32_t Y, uint32_t G, uint32_t W) {
    ++N;
    if (G != W && !Bad++) A = X, B = Y, Got = G, Want = W;
  }
  bool report() const {
    if (Bad)
      std::printf("  FAIL  %s: %llu of %llu wrong; first %08x %08x -> %08x, want %08x\n",
                  Name, (unsigned long long)Bad, (unsigned long long)N, A, B, Got, Want);
    return !Bad;
  }
};

int main(int argc, char **argv) {
  uint64_t Divs = 2000000;
  bool All = false;
  for (int I = 1; I < argc; ++I) {
    std::string S = argv[I];
    if (S == "--ulps" && I + 1 < argc) Ulps = unsigned(std::atoi(argv[++I]));
    else if (S == "--divs" && I + 1 < argc) Divs = std::strtoull(argv[++I], nullptr, 10);
    else if (S == "--all") All = true;
    else if (S == "--control") Control = true;
    else { std::fprintf(stderr, "usage: %s [--ulps N] [--divs K] [--all] [--control]\n", argv[0]); return 2; }
  }
  bool OK = true;

  // 1/x over every reduced divisor, every seed error.
  Tally Rcp{"1/x, every reduced divisor x seed error"};
  for (uint32_t F = 0; F != 1u << 23; ++F)
    for (int D = -int(Ulps); D <= int(Ulps); ++D) {
      uint32_t X = 0x3F800000u | F;
      Rcp.see(X, uint32_t(D), fdiv32(0x3F800000u, X, D), refDiv(0x3F800000u, X));
    }
  OK &= Rcp.report();

  // sqrt over every reduced argument in [1, 4), every seed error.
  Tally Sq{"sqrt, every reduced argument x seed error"};
  for (uint32_t F = 0; F != 1u << 24; ++F)
    for (int D = -int(Ulps); D <= int(Ulps); ++D) {
      uint32_t X = 0x3F800000u + F;             // [1, 4): 2^24 encodings
      Sq.see(X, uint32_t(D), sqrt32(X, D), refSqrt(X));
    }
  OK &= Sq.report();

  // a / b, sampled, the specials and the exponent range's ends over-weighted.
  std::mt19937_64 Rng(12);
  const uint32_t Edge[] = {0, 0x80000000u, 1, 2, 3, 0x007FFFFFu, 0x00800000u,
                           0x00800001u, 0x3F800000u, 0x40000000u, 0x7F7FFFFFu,
                           0x7F800000u, 0x7FC00000u, 0x0B800000u, 0x73800000u,
                           0x4B800001u, 0x33800000u};
  auto draw = [&]() -> uint32_t {
    uint64_t R = Rng();
    switch (R & 7) {
    case 0: return Edge[(R >> 8) % (sizeof Edge / 4)] ^ (uint32_t(R >> 40) & 0x80000000u);
    case 1: return uint32_t(R >> 32) & 0x80FFFFFFu;            // subnormal / tiny
    case 2: return (uint32_t(R >> 32) & 0x80FFFFFFu) | 0x7E000000u;   // huge
    default: return uint32_t(R >> 32);
    }
  };
  Tally Dv{"a / b, sampled, at hashed, -N and +N seed errors"};
  for (uint64_t I = 0; I != Divs; ++I) {
    uint32_t A = draw(), B = draw(), W = refDiv(A, B);
    Dv.see(A, B, fdiv32(A, B, hashD(A ^ B)), W);
    Dv.see(A, B, fdiv32(A, B, -int(Ulps)), W);
    Dv.see(A, B, fdiv32(A, B, int(Ulps)), W);
  }
  OK &= Dv.report();

  uint64_t Total = Rcp.N + Sq.N + Dv.N;
  if (All) {
    Tally RA{"1/x, every float"}, SA{"sqrt, every float"};
    for (uint64_t X = 0; X <= 0xFFFFFFFFu; ++X) {
      uint32_t B = uint32_t(X);
      RA.see(0x3F800000u, B, fdiv32(0x3F800000u, B, hashD(B)), refDiv(0x3F800000u, B));
      SA.see(B, 0, sqrt32(B, hashD(B)), refSqrt(B));
    }
    OK &= RA.report();
    OK &= SA.report();
    Total += RA.N + SA.N;
  }
  if (OK)
    std::printf("  PASS  IEEE divide and sqrt over an SFU off by up to %u ulps: "
                "%llu cases correctly rounded%s\n", Ulps,
                (unsigned long long)Total, All ? " (every float for 1/x and sqrt)" : "");
  return OK ? 0 : 1;
}
