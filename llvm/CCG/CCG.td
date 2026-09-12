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

def CCGAsmParser : AsmParser { let ShouldEmitMatchRegisterName = 1; }

def CCG : Target {
  let InstructionSet = CCGInstrInfo;
  let AssemblyParsers = [CCGAsmParser];
}
