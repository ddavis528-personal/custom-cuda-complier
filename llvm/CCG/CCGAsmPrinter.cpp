//===-- CCGAsmPrinter.cpp -------------------------------------------------===//
#include "CCGSubtarget.h"
#include "CCGTargetMachine.h"
#include "MCTargetDesc/CCGMCTargetDesc.h"
#include "TargetInfo/CCGTargetInfo.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

namespace {
class CCGAsmPrinter : public AsmPrinter {
public:
  CCGAsmPrinter(TargetMachine &TM, std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)) {}

  StringRef getPassName() const override { return "CCG Assembly Printer"; }
  void emitInstruction(const MachineInstr *MI) override;
};
} // namespace

void CCGAsmPrinter::emitInstruction(const MachineInstr *MI) {
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
    default:
      report_fatal_error("CCG: unhandled machine operand in asm printing");
    }
  }
  EmitToStreamer(*OutStreamer, Inst);
}

extern "C" void LLVMInitializeCCGAsmPrinter() {
  RegisterAsmPrinter<CCGAsmPrinter> X(getTheCCGTarget());
}
