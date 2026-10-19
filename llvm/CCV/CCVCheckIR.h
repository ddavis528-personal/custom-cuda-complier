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
} // namespace llvm

#endif
