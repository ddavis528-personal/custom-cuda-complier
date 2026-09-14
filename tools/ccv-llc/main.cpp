//===-- main.cpp - ccv-llc ------------------------------------------------===//
//
// llc for an out-of-tree target: stock llc only knows targets linked into it,
// so the CCV pipeline needs its own driver. Reads LLVM IR, runs codegen, writes
// assembly or an object file.
//
//===----------------------------------------------------------------------===//

#include "CCVCheckIR.h"
#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

extern "C" void LLVMInitializeCCVTargetInfo();
extern "C" void LLVMInitializeCCVTargetMC();
extern "C" void LLVMInitializeCCVTarget();
extern "C" void LLVMInitializeCCVAsmPrinter();
extern "C" void LLVMInitializeCCVDisassembler();

static cl::opt<std::string> InputFile(cl::Positional, cl::Required,
                                      cl::desc("<input.ll>"));
static cl::opt<std::string> OutputFile("o", cl::Required, cl::desc("output"));
static cl::opt<bool> EmitObj("obj", cl::desc("emit an object file (default: assembly)"));

int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv, "CCV code generator\n");

  LLVMInitializeCCVTargetInfo();
  LLVMInitializeCCVTargetMC();
  LLVMInitializeCCVTarget();
  LLVMInitializeCCVAsmPrinter();
  LLVMInitializeCCVDisassembler();

  LLVMContext Ctx;
  SMDiagnostic Err;
  auto M = parseIRFile(InputFile, Err, Ctx);
  if (!M) {
    Err.print(argv[0], errs());
    return 1;
  }

  // Before codegen: constructs the target cannot lower become diagnostics here
  // rather than crashes inside the type legalizer (F-20, F-22).
  if (!checkCCVModule(*M, errs()))
    return 1;

  std::string Error;
  Triple TT("ccv-unknown-unknown");
  const Target *T = TargetRegistry::lookupTarget("ccv", TT, Error);
  if (!T) {
    errs() << "error: " << Error << "\n";
    return 1;
  }

  TargetOptions Options;
  std::unique_ptr<TargetMachine> TM(T->createTargetMachine(
      TT.str(), "generic", "", Options, Reloc::Static, CodeModel::Small,
      CodeGenOptLevel::Default));

  M->setTargetTriple(TT.str());
  M->setDataLayout(TM->createDataLayout());

  std::error_code EC;
  raw_fd_ostream Out(OutputFile, EC,
                     EmitObj ? sys::fs::OF_None : sys::fs::OF_Text);
  if (EC) {
    errs() << "error: " << EC.message() << "\n";
    return 1;
  }

  legacy::PassManager PM;
  if (TM->addPassesToEmitFile(PM, Out, nullptr,
                              EmitObj ? CodeGenFileType::ObjectFile
                                      : CodeGenFileType::AssemblyFile)) {
    errs() << "error: target cannot emit this file type\n";
    return 1;
  }
  PM.run(*M);
  Out.flush();
  return 0;
}
