//===-- CCGCheckIR.cpp - reject IR this target cannot lower --------------===//
//
// Invariant 11 says no register holds an address: an address exists only inside
// the AGU, formed from two 32-bit registers (§5.1). The backend honours that by
// consuming address arithmetic in a DAGCombine before type legalization sees it
// (F-20).
//
// That combine is a WHITELIST of two shapes. Anything outside it leaves a live
// i64 that reaches the type legalizer, which has no register class to expand it
// into. Left alone, LLVM does not report that -- it crashes, with SIGSEGV or a
// stack-smash abort and no diagnostic. A crash is not an acceptable failure
// mode for a compiler: it is indistinguishable from a bug in the compiler
// itself and tells the user nothing.
//
// This runs before codegen and turns every such case into a diagnostic naming
// the construct and why the target cannot express it.
//
//===----------------------------------------------------------------------===//

#include "CCGCheckIR.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Operator.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

// NVVM address-space numbering, which the target follows so clang's device IR
// needs no rewriting (F-7).
static constexpr unsigned AS_CONST = 4;
static constexpr unsigned kBaseShift = 16;

namespace {

void report(const Instruction &I, StringRef What, StringRef Why,
            SmallVectorImpl<std::string> &Out) {
  std::string S;
  raw_string_ostream OS(S);
  OS << What << " in @" << I.getFunction()->getName() << ": " << Why << "\n    ";
  I.print(OS);
  Out.push_back(OS.str());
}

/// Does this i64 match a shape CCGTargetLowering::PerformDAGCombine will
/// consume? Deliberately mirrors that matcher: if the two drift apart, this
/// check stops protecting anything.
bool isConsumableAddress(const Value *V) {
  if (isa<ConstantInt>(V) || isa<ConstantExpr>(V))
    return true; // a constant address -- Format D base+offset
  const auto *Add = dyn_cast<BinaryOperator>(V);
  if (!Add || Add->getOpcode() != Instruction::Add)
    return false;

  auto isWindow = [](const Value *X) {
    const auto *Shl = dyn_cast<BinaryOperator>(X);
    if (!Shl || Shl->getOpcode() != Instruction::Shl)
      return false;
    const auto *C = dyn_cast<ConstantInt>(Shl->getOperand(1));
    if (!C || C->getZExtValue() != kBaseShift)
      return false;
    const Value *In = Shl->getOperand(0);
    if (const auto *Z = dyn_cast<ZExtInst>(In))
      In = Z->getOperand(0);
    return In->getType()->isIntegerTy(32);
  };
  auto isIndex = [](const Value *X) {
    if (const auto *Z = dyn_cast<ZExtInst>(X))
      X = Z->getOperand(0);
    else if (const auto *Se = dyn_cast<SExtInst>(X))
      X = Se->getOperand(0);
    return X->getType()->isIntegerTy(32);
  };
  return (isWindow(Add->getOperand(0)) && isIndex(Add->getOperand(1))) ||
         (isWindow(Add->getOperand(1)) && isIndex(Add->getOperand(0)));
}

} // namespace

bool llvm::checkCCGModule(Module &M, raw_ostream &Err) {
  SmallVector<std::string, 8> Problems;

  for (Function &F : M) {
    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {
        // --- .const is read-only by contract (§3, §5.2) -------------------
        if (auto *SI = dyn_cast<StoreInst>(&I))
          if (SI->getPointerAddressSpace() == AS_CONST)
            report(I, "store to constant memory",
                   "addrspace(4) is .const, which §5.2 specifies as read-only "
                   "for the kernel's lifetime -- the launch block lives there",
                   Problems);

        // --- a pointer that escapes an addressing mode --------------------
        // Invariant 11: there is no register to materialise one into, and the
        // ISA has no 64-bit instruction to operate on a pair (span is deferred,
        // §10). Each of these needs a lowering convention that does not exist.
        if (auto *SI = dyn_cast<StoreInst>(&I))
          if (SI->getValueOperand()->getType()->isPointerTy())
            report(I, "pointer stored to memory",
                   "invariant 11: no register holds an address, so a pointer "
                   "cannot be materialised as a value. Needs an (rbase, "
                   "roffset) pair convention -- see F-22",
                   Problems);

        if (auto *CI = dyn_cast<ICmpInst>(&I))
          if (CI->getOperand(0)->getType()->isPointerTy())
            report(I, "pointer comparison",
                   "invariant 11: comparison would need both halves "
                   "materialised and lowered to two compares -- see F-22",
                   Problems);

        if (auto *PN = dyn_cast<PHINode>(&I))
          if (PN->getType()->isPointerTy())
            report(I, "pointer phi",
                   "invariant 11: a pointer cannot live in a register across a "
                   "control-flow merge -- see F-22",
                   Problems);

        if (auto *CB = dyn_cast<CallBase>(&I)) {
          if (CB->getIntrinsicID() == Intrinsic::not_intrinsic &&
              !CB->isInlineAsm())
            for (const Use &A : CB->args())
              if (A->getType()->isPointerTy()) {
                report(I, "pointer passed across a call",
                       "invariant 11: the calling convention has no way to pass "
                       "an address -- see F-22",
                       Problems);
                break;
              }
        }

        // --- an address the DAGCombine whitelist will not consume ---------
        const Value *Ptr = nullptr;
        if (auto *LI = dyn_cast<LoadInst>(&I))
          Ptr = LI->getPointerOperand();
        else if (auto *SI = dyn_cast<StoreInst>(&I))
          Ptr = SI->getPointerOperand();
        if (Ptr)
          if (const auto *ITP = dyn_cast<IntToPtrInst>(Ptr))
            if (!isConsumableAddress(ITP->getOperand(0)))
              report(I, "unsupported address shape",
                     "the address is not (rbase << 16) + index or a constant, "
                     "so it cannot be folded into a Format D addressing mode "
                     "and would leave a live i64 (F-20)",
                     Problems);
      }
    }
  }

  if (Problems.empty())
    return true;
  Err << "ccg: this module cannot be lowered for the CCG target:\n";
  for (const std::string &P : Problems)
    Err << "  - " << P << "\n";
  return false;
}
