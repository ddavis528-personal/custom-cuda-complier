//===-- CCV.td - Top-level target description ---------------*- tablegen -*-===//
//
// CCV -- placeholder target name for the custom CUDA-compatible GPU ISA.
// See llvm/CCV/README.md for the rename procedure if a real name is chosen.
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

include "CCVRegisterInfo.td"
include "CCVInstrFormats.td"
include "CCVInstrInfo.td"
include "CCVCallingConv.td"
include "CCVInstrPatterns.td"

def CCVInstrInfo : InstrInfo;

// No subtarget features are defined. The GPR count is deliberately NOT one:
// per §1 and roadmap F-12, a 32-register file is a second encoding rather than
// a feature flip -- Format J overruns 16 bits at 5-bit register fields. A
// SubtargetFeature here would misrepresent that.
def : ProcessorModel<"generic", NoSchedModel, []>;

def CCVAsmParser : AsmParser { let ShouldEmitMatchRegisterName = 1; }

def CCV : Target {
  let InstructionSet = CCVInstrInfo;
  let AssemblyParsers = [CCVAsmParser];
}
