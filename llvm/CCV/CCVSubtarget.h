//===-- CCVSubtarget.h ------------------------------------------*- C++ -*-===//
#ifndef CCV_CCVSUBTARGET_H
#define CCV_CCVSUBTARGET_H

#include "CCVFrameLowering.h"
#include "CCVISelLowering.h"
#include "CCVInstrInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"

#define GET_SUBTARGETINFO_HEADER
#include "CCVGenSubtargetInfo.inc"

namespace llvm {
class CCVSubtarget : public CCVGenSubtargetInfo {
  virtual void anchor();
  /// F-200: 16-bit integers at width 16 in a kernel CCVNarrowKernels marks
  /// "ccv-narrow-int", set once at its converged entry: how many of R8-R13,
  /// from R13 down, hold them. 0 in any other function.
  unsigned NarrowRegs;
  CCVInstrInfo InstrInfo;
  CCVFrameLowering FrameLowering;
  CCVTargetLowering TLInfo;

public:
  CCVSubtarget(const Triple &TT, StringRef CPU, StringRef FS,
               const TargetMachine &TM, unsigned NarrowRegs = 0);
  bool narrowInt() const { return NarrowRegs != 0; }
  unsigned narrowRegs() const { return NarrowRegs; }
  /// One of a narrow kernel's 16-bit registers.
  bool isNarrowReg(MCRegister R) const {
    return NarrowRegs && R >= CCV::R13 + 1 - NarrowRegs && R <= CCV::R13;
  }

  const CCVInstrInfo *getInstrInfo() const override { return &InstrInfo; }
  const CCVFrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }
  const CCVRegisterInfo *getRegisterInfo() const override {
    return &InstrInfo.getRegisterInfo();
  }
  const CCVTargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }
  void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS);
};
} // namespace llvm
#endif
