//===-- CCVInstPrinter.cpp - CCV assembly printer ------------------------===//
#include "CCVInstPrinter.h"
#include "CCVMCTargetDesc.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define PRINT_ALIAS_INSTR
#include "CCVGenAsmWriter.inc"

void CCVInstPrinter::printInst(const MCInst *MI, uint64_t Address,
                               StringRef Annot, const MCSubtargetInfo &,
                               raw_ostream &O) {
  printInstruction(MI, Address, O);
  printAnnotation(O, Annot);
}

void CCVInstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
                                  raw_ostream &O) {
  const MCOperand &Op = MI->getOperand(OpNo);
  if (Op.isReg()) {
    O << getRegisterName(MCRegister(Op.getReg()));
    return;
  }
  if (Op.isImm()) {
    O << Op.getImm();
    return;
  }
  if (Op.isExpr()) {
    Op.getExpr()->print(O, &MAI);
    return;
  }
  O << "<unknown>";
}

void CCVInstPrinter::printPredQual(const MCInst *MI, unsigned OpNo,
                                   raw_ostream &O) {
  unsigned Q = unsigned(MI->getOperand(OpNo).getImm());
  if (Q & 4)
    O << '!';
  O << 'p' << (Q & 3);
}
