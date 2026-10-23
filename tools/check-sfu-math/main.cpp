//===-- check-sfu-math - ccv-sim's FP SFU values against a reference -------===//
//
// ccv-sim's FP SFU values come from tools/ccv-sim/SfuMath.cpp, integer
// arithmetic only (O-70). This holds them down against two references that
// share none of that code:
//
//   - the host's double-precision functions, each within an ulp of double, so
//     their rounding to FP32 is the correctly rounded value except within a few
//     double ulps of an FP32 midpoint;
//   - for those inputs, test/sfu-hard-cases.txt: every one in FP32, found by an
//     exhaustive run of this tool and judged by mpmath at 400 bits
//     (tools/gen-sfu-hard-cases.sh).
//
//   check-sfu-math --sample S        every S-th input of every function, and
//                                    every judged input; correctly rounded
//   check-sfu-math --all FN          every input of FN (minutes); prints the
//                                    inputs too near a midpoint as HARD
//   check-sfu-math --within N B S    -sfu-error-ulps N, every S-th input, against
//                                    O-70's bound taken at B units
//   --control                        rounds by truncation, which must be caught
//
//===----------------------------------------------------------------------===//

#include "SfuMath.h"
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

namespace {

const char *Names[] = {"rcp", "rsqrt", "sqrt", "ex2", "lg2", "sin", "cos"};

float bitsf(uint32_t B) { float F; std::memcpy(&F, &B, 4); return F; }
uint32_t fbits(float F) { uint32_t B; std::memcpy(&B, &F, 4); return B; }

double ref(sfu::Fn F, double X) {
  switch (F) {
  case sfu::Rcp:   return 1.0 / X;
  case sfu::Rsqrt: return 1.0 / std::sqrt(X);
  case sfu::Sqrt:  return std::sqrt(X);
  case sfu::Ex2:   return std::exp2(X);
  case sfu::Lg2:   return std::log2(X);
  case sfu::Sin:   return std::sin(X);
  case sfu::Cos:   return std::cos(X);
  }
  return 0;
}

/// O-70's exact special values, where IEEE double says otherwise or not at all.
bool special(sfu::Fn F, uint32_t X, uint32_t &R) {
  const uint32_t A = X & 0x7FFFFFFFu;
  if (A > 0x7F800000u) return R = 0x7FFFFFFFu, true;
  if (F == sfu::Rsqrt && A == 0) return R = X | 0x7F800000u, true;
  if ((F == sfu::Sin || F == sfu::Cos) && A == 0x7F800000u)
    return R = 0x7FFFFFFFu, true;
  if (F == sfu::Lg2 && (X >> 31) && A) return R = 0x7FFFFFFFu, true;
  return false;
}

/// The FP32 rounding of D, and whether D is too near a midpoint to trust.
uint32_t round32(double D, bool &Hard) {
  float C = float(D);
  Hard = false;
  if (std::isnan(D)) return 0x7FFFFFFFu;
  if (std::isinf(D)) return fbits(C);
  double Eps = 4 * std::fabs(std::nextafter(D, INFINITY) - D);
  for (float N : {std::nextafterf(C, -INFINITY), std::nextafterf(C, INFINITY)}) {
    double Mid = std::isinf(N) ? std::copysign(std::ldexp(2 - std::ldexp(1.0, -24), 127), N)
                               : (double(C) + double(N)) / 2;
    if (std::fabs(D - Mid) <= Eps) Hard = true;
  }
  return fbits(C);
}

std::map<std::pair<int, uint32_t>, uint32_t> Judged;

bool loadJudged(const char *Path) {
  std::ifstream In(Path);
  if (!In) return false;
  std::string Fn;
  std::string X, R;
  while (In >> Fn >> X >> R) {
    if (Fn[0] == '#') { std::getline(In, Fn); continue; }
    for (int I = 0; I != 7; ++I)
      if (Fn == Names[I])
        Judged[{I, uint32_t(std::stoul(X, 0, 16))}] = uint32_t(std::stoul(R, 0, 16));
  }
  return true;
}

/// Runs Body(X) over Count inputs Start + i * Stride on every core; returns the
/// number of failures Body reported.
template <class B> uint64_t over(uint64_t Start, uint64_t Stride, uint64_t Count, B Body) {
  std::atomic<uint64_t> Bad{0};
  unsigned T = std::max(1u, std::thread::hardware_concurrency());
  std::vector<std::thread> Th;
  for (unsigned W = 0; W != T; ++W)
    Th.emplace_back([&, W] {
      for (uint64_t I = W; I < Count; I += T)
        Bad += Body(uint32_t(Start + I * Stride));
    });
  for (auto &X : Th) X.join();
  return Bad;
}

std::mutex Out;
unsigned Shown = 0;
/// The first few failures, in full.
template <class... T> void report(const char *Fmt, T... Args) {
  std::lock_guard<std::mutex> L(Out);
  if (Shown++ < 8) std::printf(Fmt, Args...);
}

/// Correct rounding of F at X; prints HARD (and passes) for an unjudged input
/// near a midpoint when PrintHard, else counts it a failure.
unsigned checkOne(sfu::Fn F, uint32_t X, bool PrintHard) {
  uint32_t Got = sfu::eval(F, X), Want;
  if (!special(F, X, Want)) {
    auto J = Judged.find({int(F), X});
    if (J != Judged.end()) {
      Want = J->second;
    } else {
      bool Hard;
      Want = round32(ref(F, double(bitsf(X))), Hard);
      if (Hard) {
        if (PrintHard) {
          std::lock_guard<std::mutex> L(Out);
          std::printf("HARD %s %08x\n", Names[F], X);
          return 0;
        }
        report("        %s(%08x) is near a midpoint and not in the judged table "
               "(got %08x)\n", Names[F], X, Got);
        return 1;
      }
    }
  }
  if (Got == Want) return 0;
  report("        %s(%08x) = %08x, want %08x\n", Names[F], X, Got, Want);
  return 1;
}

/// Whether R is within O-70's bound at X, taken at B units; Units is how far R
/// is from the exact value, in units.
bool withinOne(sfu::Fn F, uint32_t X, uint32_t R, unsigned B, double &Units) {
  Units = 0;
  uint32_t Want;
  if (special(F, X, Want) || std::isnan(bitsf(R)))
    return R == (std::isnan(bitsf(R)) ? 0x7FFFFFFFu : Want) || R == Want;
  const float Xf = bitsf(X);
  const double D = ref(F, double(Xf)), Rv = bitsf(R);
  const uint32_t A = X & 0x7FFFFFFFu;
  // The correctly rounded value is always permitted; an infinite or zero one
  // is never moved.
  if (R == fbits(float(D)) || std::isinf(D) || float(D) == 0)
    return R == fbits(float(D));
  // An ulp of the exact value, or O-70's absolute unit.
  double Unit;
  if (F == sfu::Lg2 && Xf >= 0.5f && Xf <= 2.0f) Unit = std::ldexp(1.0, -23);
  else if (F == sfu::Sin || F == sfu::Cos) {
    if (A > 0x40490FDAu) return std::fabs(Rv) <= 1;        // beyond pi
    Unit = std::ldexp(1.0, -22);
  } else {
    int E;
    std::frexp(D, &E);
    Unit = std::ldexp(1.0, std::max(E - 1, -126) - 23);
  }
  Units = std::fabs(Rv - D) / Unit;
  if (std::isinf(Rv) || Rv == 0) return false;
  return Units <= B * (1 + 1e-9) + std::fabs(D) * 0x1p-50 / Unit;
}

} // namespace

int main(int Argc, char **Argv) {
  std::vector<std::string> A(Argv + 1, Argv + Argc);
  bool Control = false;
  for (auto It = A.begin(); It != A.end();)
    if (*It == "--control") { Control = true; It = A.erase(It); } else ++It;
  sfu::TestTruncate = Control;
  if (A.size() >= 2 && A[0] == "--all") {
    int Fi = -1;
    for (int I = 0; I != 7; ++I) if (A[1] == Names[I]) Fi = I;
    if (Fi < 0) return 2;
    uint64_t Bad = over(0, 1, 1ull << 32, [&](uint32_t X) {
      return checkOne(sfu::Fn(Fi), X, true); });
    std::fprintf(stderr, "%s: every input, %llu wrong\n", Names[Fi], (unsigned long long)Bad);
    return Bad != 0;
  }
  const char *Table = std::getenv("CCV_SFU_HARD") ? std::getenv("CCV_SFU_HARD")
                                                  : "test/sfu-hard-cases.txt";
  if (!loadJudged(Table)) {
    std::printf("  FAIL  cannot read %s\n", Table);
    return 1;
  }
  if (A.size() == 2 && A[0] == "--sample") {
    uint64_t S = std::stoull(A[1]), Fail = 0;
    for (int Fi = 0; Fi != 7; ++Fi) {
      sfu::Fn F = sfu::Fn(Fi);
      uint64_t N = ((1ull << 32) + S - 1) / S, J = 0, Bad;
      Bad = over(0, S, N, [&](uint32_t X) { return checkOne(F, X, false); });
      for (auto &[K, V] : Judged)
        if (K.first == Fi) { ++J; Bad += checkOne(F, K.second, false); }
      std::printf("  %s  %-5s correctly rounded: %llu inputs (every %llu-th) and "
                  "%llu judged near a midpoint%s\n", Bad ? "FAIL" : "PASS", Names[Fi],
                  (unsigned long long)N, (unsigned long long)S, (unsigned long long)J,
                  Bad ? (", " + std::to_string(Bad) + " wrong").c_str() : "");
      Fail += Bad;
    }
    return Fail != 0;
  }
  if (A.size() == 4 && A[0] == "--within") {
    unsigned N = std::stoul(A[1]), B = std::stoul(A[2]);
    uint64_t S = std::stoull(A[3]), Fail = 0;
    for (int Fi = 0; Fi != 7; ++Fi) {
      sfu::Fn F = sfu::Fn(Fi);
      std::atomic<uint64_t> Moved{0};
      std::atomic<uint64_t> Peak{0};          // the largest excursion, in 1/1000 units
      uint64_t Cnt = ((1ull << 32) + S - 1) / S;
      uint64_t Bad = over(0, S, Cnt, [&](uint32_t X) -> unsigned {
        uint32_t R = sfu::evalWithin(F, X, N);
        double U;
        bool Ok = withinOne(F, X, R, B, U);
        if (R != sfu::eval(F, X)) ++Moved;
        uint64_t P = uint64_t(U * 1000), Q = Peak;
        while (P > Q && !Peak.compare_exchange_weak(Q, P)) {}
        if (!Ok) report("        %s(%08x) = %08x is outside the bound (correctly "
                        "rounded %08x)\n", Names[Fi], X, R, sfu::eval(F, X));
        return !Ok;
      });
      std::printf("  %s  %-5s -sfu-error-ulps %u within %u units: %llu inputs, %.0f%% "
                  "moved, the farthest %.2f units%s\n", Bad ? "FAIL" : "PASS", Names[Fi],
                  N, B, (unsigned long long)Cnt, 100.0 * Moved / Cnt, Peak / 1000.0,
                  Bad ? (", " + std::to_string(Bad) + " outside").c_str() : "");
      Fail += Bad;
    }
    return Fail != 0;
  }
  std::fprintf(stderr, "usage: check-sfu-math --sample S | --all FN | "
                       "--within N B S  [--control]\n");
  return 2;
}
