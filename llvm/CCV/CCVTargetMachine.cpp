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
FunctionPass *createCCVSpillStats();
FunctionPass *createCCVNarrowUses();
FunctionPass *createCCVExpandPTXAsm();
FunctionPass *createCCVBarrierInit();
FunctionPass *createCCVFormFP8();
FunctionPass *createCCVMaskUniform();
FunctionPass *createCCVFuseRcpSeed();
FunctionPass *createCCVInsertChwidth();
FunctionPass *createCCVExpandDivision();
FunctionPass *createCCVUniformity();
FunctionPass *createCCVNarrowKernels();
ModulePass *createCCVLowerShared();
ModulePass *createCCVInternalize();
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
  for (unsigned N = 2; N <= 6; ++N)
    NarrowST[N - 2] = std::make_unique<CCVSubtarget>(
        TT, CPU.empty() ? "generic" : CPU, FS, *this, N);
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
    // CUDA's inline PTX conversions, while the machine code is still SSA and
    // before CSE and dead-code elimination see it (CP-6).
    addPass(createCCVExpandPTXAsm());
    // O-74: every barrier was given its own bar.init; one per kernel, or
    // none, where one count serves.
    addPass(createCCVBarrierInit());
    return false;
  }
  /// §5.1 makes `.shared` flat 32-bit, so a shared object's address is a
  /// compile-time constant and the layout is the whole of its lowering.
  void addIRPasses() override {
    // O-72: an atomic Format M has no point for (a float add, a sub-word
    // width) becomes a CAS loop, and fences go around anything stronger than
    // relaxed. First, so everything after sees the expanded form.
    addPass(createAtomicExpandPass());
    // Before anything relies on a device function's linkage (F-21).
    addPass(createCCVInternalize());
    addPass(createCCVLowerShared());
    // Before anything can ask for a division libcall that does not exist.
    addPass(createCCVExpandDivision());
    // An FP8 dot product written in FP32 is one dp4 (CP-6, stage 3).
    addPass(createCCVFormFP8());
    // Reporting only, behind -ccv-uniformity-stats; changes nothing.
    addPass(createCCVUniformity());
    // F-200: a call-free kernel with 16-bit integer work gets the subtarget
    // that keeps them at width 16, in registers set once at the entry. Before
    // CodeGenPrepare, the first pass that asks for the function's subtarget.
    addPass(createCCVNarrowKernels());
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
  /// Straight after allocation, while every spill still names its frame index
  /// -- once PEI resolves those to `r15 + offset` the slot identity is gone
  /// and only a total is left, which is the measurement F-113 exists to
  /// replace.
  /// F-169: a narrow use of a value also read wider gets its own copy, which
  /// allocation then pays for, spilling if it has to.
  void addPreRegAlloc() override {
    addPass(createCCVNarrowUses());
  }

  void addPostRegAlloc() override {
    addPass(createCCVSpillStats());
  }

  void addPreEmitPass() override {
    // Before pseudo expansion and compression, and after register allocation --
    // `chwidth` names a physical register, so it cannot be placed any earlier
    // (F-3).
    addPass(createCCVInsertChwidth());
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
