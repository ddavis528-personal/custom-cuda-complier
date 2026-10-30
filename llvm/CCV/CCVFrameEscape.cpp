//===-- CCVFrameEscape.cpp - &local handed to other threads, as a warning ---===//
//
// IS-25 (DA tab rev 97): a thread's frame is at the bottom of its O-83 region,
// which MIU interleaves by lane. A pointer into it is lane-relative, as every
// pointer into the run is: the same value names each thread's own bytes. So a
// frame pointer handed to another thread -- stored to .shared or .global, or
// given to an atomic -- names the receiver's frame there, not the sender's.
// CUDA leaves that undefined for local memory, and no corpus kernel does it
// (CP-67); what O-30's flat frame pointers gave such a program is what IS-25
// lost. This finds the visible cases and says so.
//
// It follows each alloca's address through GEPs, casts, phis and selects, and
// into the device functions it is passed to, and warns where it is
//   - stored as a value to memory that is not itself in a frame,
//   - the value of an atomic or a compare-and-swap,
//   - handed to inline asm or a function the module does not define, or
//   - turned into an integer used for anything but a comparison or a
//     difference (possibly, since the integer can be stored).
// A frame pointer stored in another frame object and loaded back is not
// followed: the store is private, and what is done with the load is not seen.
// That is the limit of "visible".
//
// A warning, not an error: the program may never read the pointer in another
// thread. Runs first in ccv-llc, while globals and their address spaces are
// still what the source wrote.
//
//===----------------------------------------------------------------------===//
#include "CCVCheckIR.h"
#include "CCVFrameLowering.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
// §5.2's .shared, as CCVCheckIR numbers it.
constexpr unsigned AS_SHARED = 3;

/// Is P's memory in some thread's frame? An alloca is; a device function's
/// pointer parameter is if every call passes one (the module is closed, F-21).
bool inFrame(const Value *P, unsigned Depth = 0) {
  const Value *O = getUnderlyingObject(P);
  if (isa<AllocaInst>(O))
    return true;
  const auto *A = dyn_cast<Argument>(O);
  if (!A || Depth > 4)
    return false;
  const Function *F = A->getParent();
  if (F->use_empty())
    return false;
  for (const User *U : F->users()) {
    const auto *CB = dyn_cast<CallBase>(U);
    if (!CB || CB->getCalledFunction() != F ||
        !inFrame(CB->getArgOperand(A->getArgNo()), Depth + 1))
      return false;
  }
  return true;
}

std::string where(const Value *P) {
  const Value *O = getUnderlyingObject(P);
  if (const auto *G = dyn_cast<GlobalVariable>(O))
    return (G->getAddressSpace() == AS_SHARED ? ".shared '" : ".global '") +
           G->getName().str() + "'";
  if (P->getType()->getPointerAddressSpace() == AS_SHARED)
    return ".shared";
  return "memory outside the thread's frame";
}
} // namespace

namespace llvm {
unsigned warnCCVFrameEscapes(Module &M, raw_ostream &OS) {
  if (!ccvFrameInPriv())
    return 0;
  unsigned N = 0;
  for (Function &F : M)
    for (Instruction &I : instructions(F)) {
      auto *AI = dyn_cast<AllocaInst>(&I);
      if (!AI)
        continue;
      std::string Name = AI->hasName() ? "'" + AI->getName().str() + "'"
                                       : std::string("a local");
      SmallVector<const Value *, 16> Work{AI};
      SmallPtrSet<const Value *, 16> Seen{AI};
      SmallPtrSet<const Instruction *, 4> Warned;
      auto warn = [&](const Instruction *At, const Twine &What) {
        if (!Warned.insert(At).second)
          return;
        ++N;
        OS << "warning: CCV: in " << At->getFunction()->getName()
           << ", the address of " << Name << " (a frame object of "
           << F.getName() << ") " << What
           << ": under IS-25 a frame pointer is lane-relative, so another "
              "thread that uses it reaches its own frame, not this one's "
              "(DA tab rev 97)\n";
      };
      auto follow = [&](const Value *V) {
        if (Seen.insert(V).second)
          Work.push_back(V);
      };
      while (!Work.empty()) {
        const Value *V = Work.pop_back_val();
        for (const Use &U : V->uses()) {
          const auto *UI = dyn_cast<Instruction>(U.getUser());
          if (!UI)
            continue;
          if (isa<GetElementPtrInst, BitCastInst, AddrSpaceCastInst, PHINode,
                  FreezeInst>(UI)) {
            follow(UI);
          } else if (const auto *Sel = dyn_cast<SelectInst>(UI)) {
            if (U.getOperandNo() != 0)
              follow(Sel);
          } else if (const auto *St = dyn_cast<StoreInst>(UI)) {
            if (U.getOperandNo() == 0 && !inFrame(St->getPointerOperand()))
              warn(St, "is stored to " + where(St->getPointerOperand()));
          } else if (const auto *RMW = dyn_cast<AtomicRMWInst>(UI)) {
            if (U.getOperandNo() == 1)
              warn(RMW, "is the value of an atomic");
          } else if (const auto *CX = dyn_cast<AtomicCmpXchgInst>(UI)) {
            if (U.getOperandNo() != 0)
              warn(CX, "is the value of a compare-and-swap");
          } else if (const auto *P2I = dyn_cast<PtrToIntInst>(UI)) {
            bool Compared = all_of(P2I->users(), [](const User *W) {
              const auto *B = dyn_cast<BinaryOperator>(W);
              return isa<ICmpInst>(W) ||
                     (B && B->getOpcode() == Instruction::Sub);
            });
            if (!Compared)
              warn(P2I, "becomes an integer that may be stored");
          } else if (const auto *CB = dyn_cast<CallBase>(UI)) {
            if (CB->isCallee(&U) || isa<IntrinsicInst>(CB))
              continue;               // lifetime markers, memcpy's pointers
            if (CB->isInlineAsm()) {
              warn(CB, "is handed to inline asm");
              continue;
            }
            const Function *Callee = CB->getCalledFunction();
            if (!Callee || Callee->isDeclaration()) {
              warn(CB, "is passed to a function this module does not define");
              continue;
            }
            if (CB->isArgOperand(&U))
              follow(Callee->getArg(CB->getArgOperandNo(&U)));
          }
        }
      }
    }
  return N;
}
} // namespace llvm
