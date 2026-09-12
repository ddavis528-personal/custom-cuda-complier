//===-- CCGSubtarget.h ------------------------------------------*- C++ -*-===//
#ifndef CCG_CCGSUBTARGET_H
#define CCG_CCGSUBTARGET_H

#include "CCGFrameLowering.h"
#include "CCGISelLowering.h"
#include "CCGInstrInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"

#define GET_SUBTARGETINFO_HEADER
#include "CCGGenSubtargetInfo.inc"

namespace llvm {
class CCGSubtarget : public CCGGenSubtargetInfo {
  virtual void anchor();
  CCGInstrInfo InstrInfo;
  CCGFrameLowering FrameLowering;
  CCGTargetLowering TLInfo;

public:
  CCGSubtarget(const Triple &TT, StringRef CPU, StringRef FS,
               const TargetMachine &TM);

  const CCGInstrInfo *getInstrInfo() const override { return &InstrInfo; }
  const CCGFrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }
  const CCGRegisterInfo *getRegisterInfo() const override {
    return &InstrInfo.getRegisterInfo();
  }
  const CCGTargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }
  void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS);
};
} // namespace llvm
#endif
