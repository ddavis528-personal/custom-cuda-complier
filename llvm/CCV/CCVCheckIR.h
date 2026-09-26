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
} // namespace llvm

#endif
