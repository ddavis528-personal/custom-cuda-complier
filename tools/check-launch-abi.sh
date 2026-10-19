#!/usr/bin/env bash
# The launch-block ABI constants are written down three times and must agree.
#
# `CCVLowerKernelArgs.cpp` owns the kernel-argument layout, `CCVFrameLowering.cpp`
# needs the base again for the `.local` window, and since O-45 both the
# simulator's AGU and the ISel matcher need them to resolve a launch slot. There
# is no shared header between the compiler and the simulator, so the numbers are
# duplicated -- which the ISA document already noted was living "in both places
# until the ABI document exists", and is now living in four.
#
# A constant that disagrees with itself here produces a kernel that reads the
# wrong argument. It does not produce anything that looks like a compile error.
set -uo pipefail
cd "$(dirname "$0")/.."
fail=0

get() { grep -oP "$2" "$1" | head -1; }

base_args=$(get llvm/CCV/IR/CCVLowerKernelArgs.cpp 'cl::init\(\K0x[0-9a-fA-F]+')
base_frame=$(get llvm/CCV/CCVFrameLowering.cpp 'cl::init\(\K0x[0-9a-fA-F]+')
base_sim=$(get tools/ccv-sim/Interp.cpp 'kLaunchBase = \K0x[0-9a-fA-F]+')
base_isel=$(get llvm/CCV/CCVISelLowering.cpp 'cl::init\(\K0x[0-9a-fA-F]+')
off_isel=$(get llvm/CCV/CCVISelLowering.cpp 'kOffArgs = \K[0-9]+')
off_args=$(get llvm/CCV/IR/CCVLowerKernelArgs.cpp 'OffArgs\s*=\s*\K[0-9]+')
off_sim=$(get tools/ccv-sim/Interp.cpp 'kOffArgs\s*=\s*\K[0-9]+')
# The SLOT STRIDE is the fourth constant, and the one that changed meaning:
# DA's response CP-4 (2026-10-08) re-scaled it from 4 to 8 so that a slot can
# only land on a pointer argument's window word. The compiler steps pointer
# arguments by it, the ISel matcher divides by it and the simulator's AGU
# multiplies by it. A disagreement here reads the wrong argument silently.
stride_isel=$(get llvm/CCV/CCVISelLowering.cpp 'kSlotStride = \K[0-9]+')
stride_sim=$(get tools/ccv-sim/Interp.cpp 'kSlotStride = \K[0-9]+')
# First `Cursor +=` in the pass is the pointer step, which IS the stride.
stride_args=$(get llvm/CCV/IR/CCVLowerKernelArgs.cpp 'Cursor \+= \K[0-9]+')

for v in "$base_args" "$base_frame" "$base_sim" "$base_isel" \
          "$off_args" "$off_sim" "$off_isel" \
          "$stride_isel" "$stride_sim" "$stride_args"; do
  [ -n "$v" ] || { echo "  FAIL  a launch-ABI constant could not be read -- the"
                   echo "        pattern has moved and this check is not checking"; exit 1; }
done

if [ "$base_args" != "$base_frame" ] || [ "$base_args" != "$base_sim" ] || \
   [ "$base_args" != "$base_isel" ]; then
  echo "  FAIL  launch base disagrees: args=$base_args frame=$base_frame"
  echo "        sim=$base_sim isel=$base_isel"
  fail=1
fi
if [ "$off_args" != "$off_sim" ] || [ "$off_args" != "$off_isel" ]; then
  echo "  FAIL  argument offset disagrees: args=$off_args sim=$off_sim isel=$off_isel"
  fail=1
fi
if [ "$stride_isel" != "$stride_sim" ] || [ "$stride_isel" != "$stride_args" ]; then
  echo "  FAIL  slot stride disagrees: isel=$stride_isel sim=$stride_sim"
  echo "        args=$stride_args"
  fail=1
fi
[ $fail -eq 0 ] && echo "  PASS  launch ABI agrees across all four copies (base $base_args, args +$off_args, slot stride $stride_isel)"
exit $fail
