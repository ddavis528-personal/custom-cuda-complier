//===-- SfuMath.h - the FP SFU's values, without a host library --*- C++ -*-===//
//
// O-70 bounds the FP SFU's error and says what ccv-sim returns by default: the
// correctly rounded value, depending on no host library. These compute it from
// integer arithmetic alone, so an oracle is the same on every build host.
//
//===----------------------------------------------------------------------===//

#ifndef CCV_SIM_SFUMATH_H
#define CCV_SIM_SFUMATH_H

#include <cstdint>

namespace sfu {

enum Fn { Rcp, Rsqrt, Sqrt, Ex2, Lg2, Sin, Cos };

/// The correctly rounded value of F at X, round to nearest even, both FP32 bit
/// patterns. A NaN result is 0x7FFFFFFF (O-66). Subnormals are kept.
uint32_t eval(Fn F, uint32_t X);

/// -sfu-error-ulps N: a value O-70 permits at X, at most N units from the
/// exact result and chosen by X's bits, so a run is reproducible. The unit is
/// an ulp of the exact result (down to 2^-149), except where O-70 bounds the
/// error absolutely: 2^-23 for lg2 on [1/2, 2] and 2^-22 for sin and cos on
/// [-pi, pi], so N = 2 is the bound itself. Beyond pi, sin and cos may be any
/// value in [-1, 1], and with N > 0 they are one, chosen by X. O-70's exact
/// special values are never moved, nor is an infinite or zero result moved to
/// or from one.
uint32_t evalWithin(Fn F, uint32_t X, unsigned N);

/// Mutation control for the checker: truncate instead of rounding to nearest.
extern bool TestTruncate;

} // namespace sfu

#endif
