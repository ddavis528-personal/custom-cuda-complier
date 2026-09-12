//===-- CCGInstPrinter.cpp - CCG assembly printer ------------------------===//
#include "CCGInstPrinter.h"
#include "CCGMCTargetDesc.h"
#include "llvm/MC/MCInst.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define PRINT_ALIAS_INSTR
#include "CCGGenAsmWriter.inc"

void CCGInstPrinter::printInst(const MCInst *MI, uint64_t Address,
                               StringRef Annot, const MCSubtargetInfo &,
                               raw_ostream &O) {
  printInstruction(MI, Address, O);
  printAnnotation(O, Annot);
}

void CCGInstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
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
  O << "<expr>";
}
