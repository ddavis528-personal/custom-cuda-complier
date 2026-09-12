//===-- CCGCheckIR.h --------------------------------------------------*- C++ -*-===//
#ifndef CCG_CCGCHECKIR_H
#define CCG_CCGCHECKIR_H

namespace llvm {
class Module;
class raw_ostream;
/// Returns false and writes diagnostics if the module uses constructs the
/// target cannot lower. Runs before codegen so those become errors rather than
/// crashes inside the type legalizer.
bool checkCCGModule(Module &M, raw_ostream &Err);
} // namespace llvm

#endif
