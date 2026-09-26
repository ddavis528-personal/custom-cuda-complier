//===-- CCVInstPrinter.h ----------------------------------------*- C++ -*-===//
#ifndef CCV_MCTARGETDESC_CCVINSTPRINTER_H
#define CCV_MCTARGETDESC_CCVINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCRegister.h"

namespace llvm {

class CCVInstPrinter : public MCInstPrinter {
public:
  CCVInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                 const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override;
  std::pair<const char *, uint64_t> getMnemonic(const MCInst *MI) override;

  void printInstruction(const MCInst *MI, uint64_t Address, raw_ostream &O);
  bool printAliasInstr(const MCInst *MI, uint64_t Address, raw_ostream &O);
  void printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  void printPredQual(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  static const char *getRegisterName(MCRegister Reg);
};

} // namespace llvm

#endif
