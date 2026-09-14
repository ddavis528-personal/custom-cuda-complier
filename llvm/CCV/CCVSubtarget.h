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
  CCVInstrInfo InstrInfo;
  CCVFrameLowering FrameLowering;
  CCVTargetLowering TLInfo;

public:
  CCVSubtarget(const Triple &TT, StringRef CPU, StringRef FS,
               const TargetMachine &TM);

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
