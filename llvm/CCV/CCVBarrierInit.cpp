//===-- CCVBarrierInit.cpp - one bar.init per barrier, or none ------------===//
//
// O-74. A barrier's count is CTA state that `bar.init #id, n` sets and that
// applies at once; count 0, the state at launch, is the every-live-lane rule
// of `__syncthreads()`. PTX instead carries the count on every `bar.sync` and
// `bar.arrive`, so selection gives every use its own bar.init (CCVISelDAGToDAG,
// CCVExpandPTXAsm). That is always right, since re-setting the count a phase
// already has changes nothing, and it costs an instruction a barrier.
//
// In a kernel that calls nothing, where every use of an ID asks for the same
// count, it is set once instead: not at all for count 0, which is how the
// launch leaves it, and at the entry for any other. Anywhere else -- a device
// function, whose caller may use the ID with another count, or a kernel whose
// callee may -- each use keeps its own.
//
//===----------------------------------------------------------------------===//

#include "CCVFrameLowering.h"
#include "CCVInstrInfo.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

using namespace llvm;

namespace {

class CCVBarrierInit : public MachineFunctionPass {
public:
  static char ID;
  CCVBarrierInit() : MachineFunctionPass(ID) {}
  StringRef getPassName() const override { return "CCV bar.init placement"; }
  bool runOnMachineFunction(MachineFunction &MF) override;
};

char CCVBarrierInit::ID = 0;

bool CCVBarrierInit::runOnMachineFunction(MachineFunction &MF) {
  if (!ccvIsKernel(MF.getFunction()))
    return false;
  DenseMap<int64_t, SmallVector<MachineInstr *, 4>> Inits;
  for (MachineBasicBlock &MBB : MF)
    for (MachineInstr &MI : MBB) {
      if (MI.isCall())
        return false;
      if (MI.getOpcode() == CCV::BAR_INIT)
        Inits[MI.getOperand(0).getImm()].push_back(&MI);
    }
  const TargetInstrInfo *TII = MF.getSubtarget().getInstrInfo();
  MachineBasicBlock &Entry = MF.front();
  bool Changed = false;
  for (auto &[Id, Uses] : Inits) {
    int64_t Count = Uses.front()->getOperand(1).getImm();
    if (any_of(Uses, [&](MachineInstr *MI) {
          return MI->getOperand(1).getImm() != Count;
        }))
      continue;
    if (Count)
      BuildMI(Entry, Entry.begin(), Uses.front()->getDebugLoc(),
              TII->get(CCV::BAR_INIT))
          .addImm(Id)
          .addImm(Count);
    for (MachineInstr *MI : Uses)
      MI->eraseFromParent();
    Changed = true;
  }
  return Changed;
}

} // namespace

namespace llvm {
FunctionPass *createCCVBarrierInit() { return new CCVBarrierInit(); }
} // namespace llvm
