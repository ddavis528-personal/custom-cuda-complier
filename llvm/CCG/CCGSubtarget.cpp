//===-- CCGSubtarget.cpp --------------------------------------------------===//
#include "CCGSubtarget.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "CCGGenSubtargetInfo.inc"

using namespace llvm;

void CCGSubtarget::anchor() {}

CCGSubtarget::CCGSubtarget(const Triple &TT, StringRef CPU, StringRef FS,
                           const TargetMachine &TM)
    : CCGGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), InstrInfo(),
      FrameLowering(), TLInfo(TM, *this) {}
