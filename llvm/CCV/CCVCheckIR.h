//===-- CCVCheckIR.h --------------------------------------------------*- C++ -*-===//
#ifndef CCV_CCVCHECKIR_H
#define CCV_CCVCHECKIR_H

namespace llvm {
class Module;
class raw_ostream;
/// Returns false and writes diagnostics if the module uses constructs the
/// target cannot lower. Runs before codegen so those become errors rather than
/// crashes inside the type legalizer.
bool checkCCVModule(Module &M, raw_ostream &Err);
/// F-22 for calls: a device function's pointer parameters and return become
/// (rbase, roffset) pairs. Runs before checkCCVModule, which then reports only
/// the pointers that could not be split. CCVPointerPairs.cpp.
void lowerCCVPointerPairs(Module &M);
/// F-21 step 5: function pointers become i32 code addresses, and indirect
/// calls record the functions they may reach. Runs first, so CCVPointerPairs
/// never mistakes a code pointer for a data pointer. CCVCodePointers.cpp.
void lowerCCVCodePointers(Module &M);
/// O-61: every global becomes part of one data image, addressed as (word 28
/// of the launch block, offset). Runs first. CCVModuleData.cpp.
void lowerCCVModuleData(Module &M);
/// CP-6 stage 2b: a double that is only a float widened and read as its 64
/// bits (NVIDIA's software FP4 and __NV_NOSAT conversions) is rebuilt on i64.
/// Runs before checkCCVModule, which reports any FP64 that remains.
/// CCVFP64Bits.cpp.
void lowerCCVFP64Bits(Module &M);
} // namespace llvm

#endif
