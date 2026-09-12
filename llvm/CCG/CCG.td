//===-- CCG.td - Top-level target description ---------------*- tablegen -*-===//
//
// CCG -- placeholder target name for the custom CUDA-compatible GPU ISA.
// See llvm/CCG/README.md for the rename procedure if a real name is chosen.
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

include "CCGRegisterInfo.td"
include "CCGInstrFormats.td"
include "CCGInstrInfo.td"

def CCGInstrInfo : InstrInfo;

// No subtarget features are defined. The GPR count is deliberately NOT one:
// per §1 and roadmap F-12, a 32-register file is a second encoding rather than
// a feature flip -- Format J overruns 16 bits at 5-bit register fields. A
// SubtargetFeature here would misrepresent that.
def : ProcessorModel<"generic", NoSchedModel, []>;

def CCGAsmParser : AsmParser { let ShouldEmitMatchRegisterName = 1; }

def CCG : Target {
  let InstructionSet = CCGInstrInfo;
  let AssemblyParsers = [CCGAsmParser];
}
