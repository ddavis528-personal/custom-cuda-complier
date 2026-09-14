//===-- CCVSubtarget.cpp --------------------------------------------------===//
#include "CCVSubtarget.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "CCVGenSubtargetInfo.inc"

using namespace llvm;

void CCVSubtarget::anchor() {}

CCVSubtarget::CCVSubtarget(const Triple &TT, StringRef CPU, StringRef FS,
                           const TargetMachine &TM)
    : CCVGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), InstrInfo(),
      FrameLowering(), TLInfo(TM, *this) {}
