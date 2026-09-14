//===-- CCVWindowRemat.cpp - keep window arithmetic block-local ----------===//
//
// Invariant 11 says no register holds an address. The backend honours that by
// folding `(rbase << 16) + index` back into a Format D addressing mode in a
// DAGCombine -- but SelectionDAG builds one basic block at a time, so a window
// value defined in one block and used in another is already a cross-block i64
// by the time the combine could see it. It becomes a CopyFromReg of a 64-bit
// virtual register, there is no 64-bit register class to hold it, and the type
// legalizer aborts with "Do not know how to expand this operator's operand".
//
// That is not a hypothetical: it is what any kernel with control flow does.
// `vadd` only escaped it because its whole body is one basic block.
//
// The window chain is a load from `.const` marked `invariant.load`, a zext and
// a shift -- pure, cheap, and rematerializable anywhere. So rather than teach
// the backend to hold an address in a register, clone the chain into each block
// that uses it. The combine then always sees the arithmetic locally, and the
// i64 never becomes a value.
//
// This runs immediately before instruction selection, after CodeGenPrepare,
// so nothing downstream can hoist the chain back out.
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Pass.h"
#include "llvm/IR/ValueHandle.h"
#include "llvm/Transforms/Utils/Local.h"

using namespace llvm;

namespace llvm {
FunctionPass *createCCVWindowRemat();
}

#define DEBUG_TYPE "ccv-window-remat"

namespace {

/// Can this instruction be cloned to an arbitrary point without changing
/// behaviour? Launch-block loads qualify because §5.2 makes the block read-only
/// for the lifetime of the kernel, which is what `invariant.load` records.
bool isRematerializable(const Instruction *I) {
  if (const auto *LI = dyn_cast<LoadInst>(I))
    return LI->isSimple() && LI->getMetadata(LLVMContext::MD_invariant_load) &&
           LI->getPointerAddressSpace() == 4;
  switch (I->getOpcode()) {
  case Instruction::ZExt:
  case Instruction::SExt:
  case Instruction::Trunc:
  case Instruction::Shl:
  case Instruction::Add:
  case Instruction::Or:
  case Instruction::IntToPtr:
  case Instruction::PtrToInt:
  case Instruction::GetElementPtr:
    return true;
  default:
    return false;
  }
}

/// Collect the operand cone of Root in dependency order, or return false if any
/// of it cannot be cloned. Constants and arguments are leaves and need no
/// cloning, so they are not collected.
bool collectChain(Instruction *Root, SmallVectorImpl<Instruction *> &Order) {
  SmallPtrSet<Instruction *, 8> Seen;
  // Depth first, post-order: operands land ahead of the user.
  SmallVector<std::pair<Instruction *, bool>, 8> Stack{{Root, false}};
  while (!Stack.empty()) {
    auto [I, Expanded] = Stack.pop_back_val();
    if (Expanded) {
      Order.push_back(I);
      continue;
    }
    if (!Seen.insert(I).second)
      continue;
    if (!isRematerializable(I))
      return false;
    // A chain longer than this is not a window computation; refuse rather than
    // clone something large into every block.
    if (Order.size() + Stack.size() > 16)
      return false;
    Stack.push_back({I, true});
    for (Value *Op : I->operands())
      if (auto *OpI = dyn_cast<Instruction>(Op))
        Stack.push_back({OpI, false});
  }
  return true;
}

/// Where a clone for this use must go. For a phi operand that is the end of the
/// incoming block, not the phi itself -- inserting before a phi is invalid IR.
Instruction *insertionPoint(Use &U) {
  auto *User = cast<Instruction>(U.getUser());
  if (auto *PN = dyn_cast<PHINode>(User))
    return PN->getIncomingBlock(U)->getTerminator();
  return User;
}

bool runOnFn(Function &F) {
  // Roots are the values that must not cross a block: pointers produced by
  // inttoptr, which is how §5.1's window arithmetic re-enters the pointer
  // domain.
  SmallVector<IntToPtrInst *, 8> Roots;
  for (Instruction &I : instructions(F))
    if (auto *ITP = dyn_cast<IntToPtrInst>(&I))
      Roots.push_back(ITP);

  bool Changed = false;
  for (IntToPtrInst *Root : Roots) {
    SmallVector<Instruction *, 8> Chain;
    if (!collectChain(Root, Chain)) continue;

    for (Use &U : llvm::make_early_inc_range(Root->uses())) {
      Instruction *IP = insertionPoint(U);
      BasicBlock *BB = IP->getParent();

      // The whole cone has to be local, not just the root. CodeGenPrepare
      // already sinks the inttoptr into the using block on its own; what it
      // leaves behind is the i64 shift feeding it, which is precisely the
      // value that cannot be held in a register.
      if (llvm::all_of(Chain, [&](Instruction *I) {
            return I->getParent() == BB;
          }))
        continue;

      // Clone the cone ahead of the use, rewriting operands as we go.
      DenseMap<Value *, Value *> Map;
      for (Instruction *I : Chain) {
        Instruction *C = I->clone();
        for (Use &Op : C->operands())
          if (Value *R = Map.lookup(Op.get()))
            Op.set(R);
        C->insertBefore(IP);
        if (I->hasName())
          C->setName(I->getName() + ".remat");
        Map[I] = C;
      }
      U.set(Map[Root]);
      Changed = true;
    }
  }

  // The originals are usually dead now; if a use survived in the defining
  // block they stay, which is correct.
  //
  // Weak handles, not raw pointers: two roots can share operands, so deleting
  // one recursively deletes instructions that are still in this list. Holding
  // raw pointers here is a use-after-free -- it showed up as heap corruption
  // in the GEMM, whose several window chains share a launch-block load, and
  // not in any earlier kernel, whose chains were disjoint.
  if (Changed) {
    SmallVector<WeakTrackingVH, 8> Handles(Roots.begin(), Roots.end());
    for (WeakTrackingVH &H : llvm::reverse(Handles))
      if (H)
        RecursivelyDeleteTriviallyDeadInstructions(cast<Instruction>(H));
  }
  return Changed;
}

class CCVWindowRemat : public FunctionPass {
public:
  static char ID;
  CCVWindowRemat() : FunctionPass(ID) {}
  bool runOnFunction(Function &F) override { return runOnFn(F); }
  StringRef getPassName() const override {
    return "CCV window rematerialization";
  }
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesCFG();
  }
};

} // namespace

char CCVWindowRemat::ID = 0;

FunctionPass *llvm::createCCVWindowRemat() { return new CCVWindowRemat(); }
