//===-- CCVAsmPrinter.cpp -------------------------------------------------===//
#include "CCVSubtarget.h"
#include "CCVTargetMachine.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "TargetInfo/CCVTargetInfo.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Target/TargetLoweringObjectFile.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"

using namespace llvm;

// Where the image is loaded, for a function's code address as a value: the low
// 32 bits of its PC (ISA v1.8 §3 Format E), a link-time constant against the
// load address (AR-22). Must match ccv-sim's -code-base default and ccv-as's
// @label.
static cl::opt<uint64_t> CodeBase("ccv-code-base", cl::init(0x1000),
                                  cl::desc("the image's load address, for "
                                           "function pointers"));

namespace {
class CCVAsmPrinter : public AsmPrinter {
public:
  CCVAsmPrinter(TargetMachine &TM, std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)) {}

  StringRef getPassName() const override { return "CCV Assembly Printer"; }
  void emitInstruction(const MachineInstr *MI) override;
  void emitStartOfAsmFile(Module &M) override;
  void emitFunctionBodyEnd() override;

private:
  /// The start of .text, which is image offset 0: a code address is its
  /// distance from here plus the load address, which the assembler resolves
  /// with no relocation. Made only for a module with function pointers, so
  /// every other listing is unchanged.
  MCSymbol *TextStart = nullptr;
};
} // namespace

void CCVAsmPrinter::emitInstruction(const MachineInstr *MI) {
  MCInst Inst;
  Inst.setOpcode(MI->getOpcode());
  for (const MachineOperand &MO : MI->operands()) {
    switch (MO.getType()) {
    case MachineOperand::MO_Register:
      if (MO.isImplicit())
        continue;
      Inst.addOperand(MCOperand::createReg(MO.getReg()));
      break;
    case MachineOperand::MO_Immediate:
      Inst.addOperand(MCOperand::createImm(MO.getImm()));
      break;
    case MachineOperand::MO_MachineBasicBlock:
      Inst.addOperand(MCOperand::createExpr(
          MCSymbolRefExpr::create(MO.getMBB()->getSymbol(), OutContext)));
      break;
    case MachineOperand::MO_GlobalAddress: { // a call's target (F-21)
      const MCExpr *E = MCSymbolRefExpr::create(getSymbol(MO.getGlobal()), OutContext);
      if (MO.getTargetFlags() == CCVII::MO_CODEADDR) {
        if (!TextStart)
          report_fatal_error("CCV: a code address with no image start to "
                             "measure it from");
        E = MCBinaryExpr::createAdd(
            MCBinaryExpr::createSub(
                E, MCSymbolRefExpr::create(TextStart, OutContext), OutContext),
            MCConstantExpr::create(int64_t(CodeBase & 0xffffffff), OutContext),
            OutContext);
      }
      Inst.addOperand(MCOperand::createExpr(E));
      break;
    }
    case MachineOperand::MO_MCSymbol:        // an indirect call's stub
      Inst.addOperand(MCOperand::createExpr(
          MCSymbolRefExpr::create(MO.getMCSymbol(), OutContext)));
      break;
    case MachineOperand::MO_RegisterMask:    // a call's clobbers: codegen only
      continue;
    default:
      report_fatal_error("CCV: unhandled machine operand in asm printing");
    }
  }
  EmitToStreamer(*OutStreamer, Inst);
}

void CCVAsmPrinter::emitStartOfAsmFile(Module &M) {
  if (none_of(M, [](const Function &F) { return F.hasAddressTaken(); }))
    return;
  OutStreamer->switchSection(getObjFileLowering().getTextSection());
  TextStart = OutContext.getOrCreateSymbol(".Lccv_text");
  OutStreamer->emitLabel(TextStart);
}

/// An indirect call's stub (calling-convention.md §4): `call R14` lands here
/// with the target in R7, and `ret r7` jumps to it, leaving the link the call
/// wrote for the target to return through.
void CCVAsmPrinter::emitFunctionBodyEnd() {
  MCSymbol *Stub =
      OutContext.lookupSymbol(".Lccv_icall_" + MF->getName());
  if (!Stub)
    return;
  OutStreamer->emitLabel(Stub);
  MCInst Ret;
  Ret.setOpcode(CCV::C_RET);
  Ret.addOperand(MCOperand::createImm(  // rs is [15:12], the payload's high nibble
      MF->getSubtarget().getRegisterInfo()->getEncodingValue(CCV::R7) << 4));
  EmitToStreamer(*OutStreamer, Ret);
}

extern "C" void LLVMInitializeCCVAsmPrinter() {
  RegisterAsmPrinter<CCVAsmPrinter> X(getTheCCVTarget());
}
