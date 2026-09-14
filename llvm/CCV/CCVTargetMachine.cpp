//===-- CCVTargetMachine.cpp ----------------------------------------------===//
#include "CCVTargetMachine.h"
#include "CCVTargetTransformInfo.h"
#include "TargetInfo/CCVTargetInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Passes/PassBuilder.h"

using namespace llvm;

namespace llvm {
FunctionPass *createCCVISelDag(CCVTargetMachine &TM, CodeGenOptLevel OL);
FunctionPass *createCCVExpandPseudos();
FunctionPass *createCCVWindowRemat();
FunctionPass *createCCVCompress();
FunctionPass *createCCVMaskUniform();
FunctionPass *createCCVFuseRcpSeed();
FunctionPass *createCCVExpandDivision();
FunctionPass *createCCVUniformity();
ModulePass *createCCVLowerShared();
}

// Pointers are 64 bits wide as clang emits them; no register holds one
// (invariant 11). The address model splits them in the AGU, and
// CCVLowerKernelArgs has already expressed that split as IR arithmetic.
// Address spaces follow NVVM's numbering so clang's device IR needs no
// rewriting (roadmap F-7): 1 global, 3 shared, 4 constant, 5 local.
static std::string computeDataLayout() {
  return "e-p:64:64-p1:64:64-p3:32:32-p4:64:64-p5:32:32-"
         "i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-n32";
}

CCVTargetMachine::CCVTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : LLVMTargetMachine(T, computeDataLayout(), TT, CPU.empty() ? "generic" : CPU,
                        FS, Options, RM.value_or(Reloc::Static),
                        CM.value_or(CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      ST(TT, CPU.empty() ? "generic" : CPU, FS, *this) {
  initAsmInfo();
}

namespace {
class CCVPassConfig : public TargetPassConfig {
public:
  CCVPassConfig(CCVTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}
  CCVTargetMachine &getCCVTargetMachine() const {
    return getTM<CCVTargetMachine>();
  }
  bool addInstSelector() override {
    addPass(createCCVISelDag(getCCVTargetMachine(), getOptLevel()));
    return false;
  }
  /// §5.1 makes `.shared` flat 32-bit, so a shared object's address is a
  /// compile-time constant and the layout is the whole of its lowering.
  void addIRPasses() override {
    addPass(createCCVLowerShared());
    // Before anything can ask for a division libcall that does not exist.
    addPass(createCCVExpandDivision());
    // Reporting only, behind -ccv-uniformity-stats; changes nothing.
    addPass(createCCVUniformity());
    TargetPassConfig::addIRPasses();
  }

  /// Last thing before instruction selection: §5.1's window arithmetic is
  /// cloned into every block that uses it, so the DAGCombine that folds it into
  /// an addressing mode always sees it locally. Placed after the default
  /// CodeGenPrepare so nothing can hoist it back out.
  /// O-33: after instruction selection, before allocation -- uniformity is a
  /// dataflow property and SSA virtual registers are what makes it cheap to
  /// compute.
  bool addILPOpts() override {
    // Before masking: fusing five instructions into one changes what there is
    // to mask, and `rcp.u32` has no predicated form (§4 263, above A′'s reach).
    addPass(createCCVFuseRcpSeed());
    addPass(createCCVMaskUniform());
    return true;
  }

  void addCodeGenPrepare() override {
    TargetPassConfig::addCodeGenPrepare();
    addPass(createCCVWindowRemat());
  }

  /// After register allocation: predicate registers become qualifier
  /// immediates, which is only possible once allocation has run.
  /// Pseudo expansion first, so the instructions it produces are compressible
  /// too; then Format K compression, which only shrinks what already fits.
  void addPreEmitPass() override {
    addPass(createCCVExpandPseudos());
    addPass(createCCVCompress());
  }
};
} // namespace

TargetTransformInfo
CCVTargetMachine::getTargetTransformInfo(const Function &F) const {
  return TargetTransformInfo(CCVTTIImpl(this, F));
}

TargetPassConfig *CCVTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new CCVPassConfig(*this, PM);
}

extern "C" void LLVMInitializeCCVTarget() {
  RegisterTargetMachine<CCVTargetMachine> X(getTheCCVTarget());
}
