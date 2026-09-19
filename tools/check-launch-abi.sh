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

for v in "$base_args" "$base_frame" "$base_sim" "$base_isel" \
          "$off_args" "$off_sim" "$off_isel"; do
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
[ $fail -eq 0 ] && echo "  PASS  launch ABI agrees across all four copies (base $base_args, args +$off_args)"
exit $fail
