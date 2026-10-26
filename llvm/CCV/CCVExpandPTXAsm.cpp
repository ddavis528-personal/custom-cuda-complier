//===-- CCVExpandPTXAsm.cpp - CUDA's inline PTX conversions, made native --===//
//
// CP-6, stage 2. The compatibility contract is CUDA source (§5.8, O-55), and
// CUDA's FP8 types are cuda_fp8.h's. For an architecture with FP8 conversion
// (sm_89 and later) that header computes them in inline PTX, so this is the IR
// clang hands the backend for `__nv_fp8_e4m3(x)` and `float(__nv_fp8_e4m3)`:
//
//   %h = call i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"
//   %r = call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"
//   %f = call float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"
//
// LLVM 18 has no NVVM intrinsic for any FP8 conversion, so there is nothing
// else to select from. Each template here is one §4 conversion per element,
// plus the packing PTX's x2 forms do: an x2 value's first-named source is its
// HIGH element, as PTX defines it.
//
// The asm operands arrive in virtual registers of the constraint's class
// (`h` GPR16, `r` and `f` GPR; CCVISelLowering), so this runs straight after
// selection, in SSA form, and the CSE and dead-code passes that follow see
// ordinary instructions: `float(fp8)` asks for an x2 conversion and reads one
// half, and the other half's conversion is then dead.
//
// It also selects the templates CCVFormFP8 writes, since LLVM 18 has no IR
// for them either: `ccv.dp4.e4m3`/`.e5m2` for a dot product, and
// `ccv.fadd.e4m3` and its kin for one native FP8 operation. CCVFoldFP4 writes
// `ccv.cvt.e2m1.f32` and `ccv.cvt.f32.e2m1` for cuda_fp4.hpp's conversions.
//
// Anything else written in inline PTX is refused by name, not emitted: the
// asm printer would put PTX text into a CCV object.
//
//===----------------------------------------------------------------------===//

#include "CCVInstrInfo.h"
#include "CCVSubtarget.h"
#include "MCTargetDesc/CCVMCTargetDesc.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/Regex.h"
#include <optional>

using namespace llvm;

// Mutation control for tools/check-fp8.sh: put an x2's elements in the wrong
// halves, as a misreading of PTX's operand order would.
static cl::opt<bool> TestSwapX2(
    "ccv-test-ptx-swap-x2", cl::init(false), cl::Hidden,
    cl::desc("swap the halves of an inline PTX x2 conversion, to test that it "
             "is caught"));

// Mutation control for tools/check-fp8.sh: an FP8 add in the other format.
static cl::opt<bool> TestWrongFormat(
    "ccv-test-fp8-wrong-format", cl::init(false), cl::Hidden,
    cl::desc("give a native FP8 add the other format code, to test that it is "
             "caught"));

namespace {

class CCVExpandPTXAsm : public MachineFunctionPass {
public:
  static char ID;
  CCVExpandPTXAsm() : MachineFunctionPass(ID) {}
  bool runOnMachineFunction(MachineFunction &MF) override;
  StringRef getPassName() const override { return "CCV expand PTX asm"; }
};

char CCVExpandPTXAsm::ID = 0;

/// The template's text without braces, the trailing newline and spacing, as
/// cuda_fp8.hpp and cuda_fp16.hpp write it: "{cvt.f32.f16 $0, $1;}\n".
std::string normalize(StringRef S) {
  std::string Out;
  for (char C : S)
    if (C != '{' && C != '}' && C != '\n' && C != ';')
      Out += C;
  return StringRef(Out).trim().str();
}

/// Is R +0.0, through copies? cuda_fp8.hpp converts a scalar as the low half
/// of an x2 whose high source is the constant 0.0f, so that half is known.
bool isPosZero(const MachineRegisterInfo &MRI, Register R) {
  while (R.isVirtual()) {
    const MachineInstr *D = MRI.getUniqueVRegDef(R);
    if (!D)
      return false;
    if (D->isCopy()) {
      R = D->getOperand(1).getReg();
      continue;
    }
    return (D->getOpcode() == CCV::MOVI || D->getOpcode() == CCV::MOVI48) &&
           D->getOperand(1).isImm() && D->getOperand(1).getImm() == 0;
  }
  return false;
}

/// R's value, if it is a constant through copies: an inline PTX barrier's
/// operands arrive in registers, but O-74's ID and count are immediates.
std::optional<int64_t> constantOf(const MachineRegisterInfo &MRI, Register R) {
  while (R.isVirtual()) {
    const MachineInstr *D = MRI.getUniqueVRegDef(R);
    if (!D)
      return std::nullopt;
    if (D->isCopy()) {
      R = D->getOperand(1).getReg();
      continue;
    }
    if ((D->getOpcode() == CCV::MOVI || D->getOpcode() == CCV::MOVI48) &&
        D->getOperand(1).isImm())
      return D->getOperand(1).getImm();
    return std::nullopt;
  }
  return std::nullopt;
}

/// Does every read of R take only its low 16 bits -- a `trunc` to i16, which
/// selection makes a COPY into GPR16? `float(fp8)` converts an x2 and keeps
/// the low half, so the high half's conversion is then never needed.
bool onlyLowHalfRead(const MachineRegisterInfo &MRI, Register R) {
  for (const MachineInstr &U : MRI.use_nodbg_instructions(R))
    if (!U.isCopy() || !U.getOperand(0).getReg().isVirtual() ||
        MRI.getRegClass(U.getOperand(0).getReg()) != &CCV::GPR16RegClass)
      return false;
  return true;
}

bool CCVExpandPTXAsm::runOnMachineFunction(MachineFunction &MF) {
  MachineRegisterInfo &MRI = MF.getRegInfo();
  const TargetInstrInfo *TII = MF.getSubtarget().getInstrInfo();
  bool Changed = false;

  for (MachineBasicBlock &MBB : MF)
    for (MachineInstr &MI : llvm::make_early_inc_range(MBB)) {
      if (!MI.isInlineAsm())
        continue;
      StringRef Text =
          MI.getOperand(InlineAsm::MIOp_AsmString).getSymbolName();
      std::string T = normalize(Text);

      // The asm's operands in $-number order: definitions first, then uses,
      // as the constraint string lists them.
      SmallVector<Register, 4> Ops;
      for (unsigned I = InlineAsm::MIOp_FirstOperand, E = MI.getNumOperands();
           I < E;) {
        const MachineOperand &FO = MI.getOperand(I);
        if (!FO.isImm())
          break;
        InlineAsm::Flag F(FO.getImm());
        unsigned N = F.getNumOperandRegisters();
        if ((F.isRegDefKind() || F.isRegUseKind()) && N == 1)
          Ops.push_back(MI.getOperand(I + 1).getReg());
        else if (!F.isClobberKind())
          report_fatal_error("CCV: inline PTX '" + Twine(T) +
                             "' has an operand CCV does not take (CP-6)");
        I += 1 + N;
      }

      SmallVector<StringRef, 4> M;
      auto op = [&](StringRef Num) -> Register {
        unsigned K = 0;
        if (Num.getAsInteger(10, K) || K >= Ops.size())
          report_fatal_error("CCV: inline PTX '" + Twine(T) +
                             "' names an operand it does not have");
        return Ops[K];
      };
      const DebugLoc &DL = MI.getDebugLoc();
      auto vreg = [&](const TargetRegisterClass &RC) {
        return MRI.createVirtualRegister(&RC);
      };
      // One conversion: all three source fields name the one source, as the
      // single-source conversions are emitted everywhere (CVT_SEXT).
      auto cvt = [&](unsigned Opc, Register D, Register S) {
        BuildMI(MBB, MI, DL, TII->get(Opc), D).addReg(S).addReg(S).addReg(S);
      };
      auto copy = [&](Register D, Register S) {
        BuildMI(MBB, MI, DL, TII->get(TargetOpcode::COPY), D).addReg(S);
      };

      static const Regex ToX2(
          "^cvt\\.rn\\.satfinite\\.(e4m3|e5m2)x2\\.f32 \\$([0-9]+), "
          "\\$([0-9]+), \\$([0-9]+)$");
      static const Regex FromX2(
          "^cvt\\.rn\\.f16x2\\.(e4m3|e5m2)x2 \\$([0-9]+), \\$([0-9]+)$");
      static const Regex Dot4(
          "^ccv\\.dp4\\.(e4m3|e5m2) \\$([0-9]+), \\$([0-9]+), \\$([0-9]+), "
          "\\$([0-9]+)$");
      static const Regex Arith8(
          "^ccv\\.(fadd|fsub|fmul)\\.(e4m3|e5m2) \\$([0-9]+), \\$([0-9]+), "
          "\\$([0-9]+)$");
      static const Regex F32F16("^cvt\\.f32\\.f16 \\$([0-9]+), \\$([0-9]+)$");
      static const Regex ToE2M1(
          "^ccv\\.cvt\\.e2m1\\.f32 \\$([0-9]+), \\$([0-9]+)$");
      static const Regex FromE2M1(
          "^ccv\\.cvt\\.f32\\.e2m1 \\$([0-9]+), \\$([0-9]+)$");
      // PTX's named barriers as CUDA code writes them, CUTLASS's
      // NamedBarrier among it: `bar.arrive a, b` and `bar.sync a{, b}`, also
      // spelled `barrier{.cta}.arrive/sync{.aligned}`.
      static const Regex Bar(
          "^(bar|barrier)(\\.cta)?\\.(arrive|sync)(\\.aligned)? "
          "(\\$[0-9]+|[0-9]+)(, (\\$[0-9]+|[0-9]+))?$");
      // O-83: %privoff, srd #3, for CCVLowerKernelArgs's __ccv_privbase.
      static const Regex PrivOff("^ccv\\.privoff \\$([0-9]+)$");
      static const Regex F16F32(
          "^cvt\\.rn\\.f16\\.f32 \\$([0-9]+), \\$([0-9]+)$");

      if (ToX2.match(T, &M)) {
        // d = {cvt(a) : cvt(b)}, a in bits [15:8]. Each converts at chwidth 8
        // and saturates (O-53); widening zero-extends (O-38), so the pair is
        // a shift and an or at 32 bits, narrowed to the 16-bit result.
        unsigned Opc = M[1] == "e4m3" ? CCV::CVT_D0_S0_R0_W8_32
                                      : CCV::CVT_D1_S0_R0_W8_32;
        Register Hi8 = vreg(CCV::GPR8RegClass), Lo8 = vreg(CCV::GPR8RegClass);
        cvt(Opc, Lo8, op(M[4]));
        if (isPosZero(MRI, op(M[3]))) {
          // The high element converts +0.0, which is 0x00: the result is the
          // low element, zero-extended (O-38).
          copy(op(M[2]), Lo8);
          MI.eraseFromParent();
          Changed = true;
          continue;
        }
        cvt(Opc, Hi8, op(M[3]));
        if (TestSwapX2)
          std::swap(Hi8, Lo8);
        Register Hi = vreg(CCV::GPRRegClass), Lo = vreg(CCV::GPRRegClass);
        Register Sh = vreg(CCV::GPRRegClass), Or = vreg(CCV::GPRRegClass);
        copy(Hi, Hi8);
        copy(Lo, Lo8);
        BuildMI(MBB, MI, DL, TII->get(CCV::SHLI), Sh).addReg(Hi).addImm(8);
        BuildMI(MBB, MI, DL, TII->get(CCV::OR), Or)
            .addReg(Sh).addReg(Lo).addReg(Sh);
        copy(op(M[2]), Or);
      } else if (FromX2.match(T, &M)) {
        // d = {f16(a[15:8]) : f16(a[7:0])}: each byte converted at chwidth 8
        // into an FP16 element, packed into the 32-bit result.
        unsigned Opc = M[1] == "e4m3" ? CCV::CVT_D0_S0_R0_W16_8
                                      : CCV::CVT_D0_S1_R0_W16_8;
        Register Src = op(M[3]);
        Register W = vreg(CCV::GPRRegClass), HiB = vreg(CCV::GPRRegClass);
        copy(W, Src);
        BuildMI(MBB, MI, DL, TII->get(CCV::SHRI), HiB).addReg(W).addImm(8);
        Register Lo8 = vreg(CCV::GPR8RegClass), Hi8 = vreg(CCV::GPR8RegClass);
        copy(Lo8, W);
        copy(Hi8, HiB);
        Register Lo16 = vreg(CCV::GPR16RegClass), Hi16 = vreg(CCV::GPR16RegClass);
        cvt(Opc, Lo16, Lo8);
        if (onlyLowHalfRead(MRI, op(M[2]))) {
          copy(op(M[2]), Lo16);
          MI.eraseFromParent();
          Changed = true;
          continue;
        }
        cvt(Opc, Hi16, Hi8);
        Register Lo = vreg(CCV::GPRRegClass), Hi = vreg(CCV::GPRRegClass);
        Register Sh = vreg(CCV::GPRRegClass);
        copy(Lo, Lo16);
        copy(Hi, Hi16);
        BuildMI(MBB, MI, DL, TII->get(CCV::SHLI), Sh).addReg(Hi).addImm(16);
        BuildMI(MBB, MI, DL, TII->get(CCV::OR), op(M[2]))
            .addReg(Sh).addReg(Lo).addReg(Sh);
      } else if (Arith8.match(T, &M)) {
        // CCVFormFP8's: the low bytes of two i16 sources, one native
        // operation at chwidth 8, zero-extended into the i16 result (O-38).
        bool F1 = M[2] == "e5m2";
        unsigned Opc = M[1] == "fadd" ? (F1 ? CCV::FADD_F1_W8 : CCV::FADD_W8)
                     : M[1] == "fsub" ? (F1 ? CCV::FSUB_F1_W8 : CCV::FSUB_W8)
                                      : (F1 ? CCV::FMUL_F1_W8 : CCV::FMUL_W8);
        if (TestWrongFormat)
          Opc = Opc == CCV::FADD_W8 ? CCV::FADD_F1_W8
              : Opc == CCV::FADD_F1_W8 ? CCV::FADD_W8 : Opc;
        Register A8 = vreg(CCV::GPR8RegClass), B8 = vreg(CCV::GPR8RegClass);
        Register R8 = vreg(CCV::GPR8RegClass);
        copy(A8, op(M[4]));
        copy(B8, op(M[5]));
        BuildMI(MBB, MI, DL, TII->get(Opc), R8).addReg(A8).addReg(B8).addReg(A8);
        copy(op(M[3]), R8);
      } else if (Dot4.match(T, &M)) {
        // CCVFormFP8Dot's: rd = rs2 + the four products of rs0's and rs1's
        // bytes, summed exactly and rounded once (O-44).
        unsigned Opc = M[1] == "e4m3" ? CCV::DP4_E4M3 : CCV::DP4_E5M2;
        BuildMI(MBB, MI, DL, TII->get(Opc), op(M[2]))
            .addReg(op(M[3])).addReg(op(M[4])).addReg(op(M[5]));
      } else if (F32F16.match(T, &M)) {
        // float(fp8) is fp8 -> f16 -> f32 in CUDA's header. FP16 holds every
        // E4M3 and E5M2 value exactly, so the pair is one conversion from the
        // byte; the f16 step is then dead.
        Register S = op(M[2]);
        const MachineInstr *D = MRI.getUniqueVRegDef(S);
        while (D && D->isCopy() && D->getOperand(1).getReg().isVirtual())
          D = MRI.getUniqueVRegDef(D->getOperand(1).getReg());
        unsigned Opc = CCV::CVT_D0_S0_R0_W32_16;
        if (D && (D->getOpcode() == CCV::CVT_D0_S0_R0_W16_8 ||
                  D->getOpcode() == CCV::CVT_D0_S1_R0_W16_8)) {
          Opc = D->getOpcode() == CCV::CVT_D0_S0_R0_W16_8
                    ? CCV::CVT_D0_S0_R0_W32_8 : CCV::CVT_D0_S1_R0_W32_8;
          S = D->getOperand(1).getReg();
        }
        cvt(Opc, op(M[1]), S);
      } else if (F16F32.match(T, &M)) {
        unsigned Opc = CCV::CVT_D0_S0_R0_W16_32;
        cvt(Opc, op(M[1]), op(M[2]));
      } else if (PrivOff.match(T, &M)) {
        BuildMI(MBB, MI, DL, TII->get(CCV::SRD), op(M[1])).addImm(3);
      } else if (Bar.match(T, &M)) {
        // O-74: bar.init #a, b, then the arrival, then for a sync the wait,
        // as the intrinsics select (CCVISelDAGToDAG). a and b must be
        // constants: the ISA's are immediates.
        auto value = [&](StringRef V) -> int64_t {
          int64_t K;
          if (!V.starts_with("$")) {
            V.getAsInteger(10, K);
            return K;
          }
          if (auto C = constantOf(MRI, op(V.drop_front())))
            return *C;
          report_fatal_error("CCV: inline PTX '" + Twine(T) + "' names a " +
                             "barrier or a thread count that is not a " +
                             "constant; bar.init's are immediates (O-74)");
        };
        int64_t Id = value(M[5]), Count = M[7].empty() ? 0 : value(M[7]);
        if (M[3] == "arrive" && M[7].empty())
          report_fatal_error("CCV: inline PTX '" + Twine(T) +
                             "' arrives with no thread count, which PTX refuses");
        if (Id < 0 || Id >= 16 || Count < 0 || Count > 1024 || Count % 32)
          report_fatal_error("CCV: inline PTX '" + Twine(T) + "' needs a " +
                             "barrier below 16 (O-59) and a thread count that " +
                             "is a multiple of 32, at most 1024");
        BuildMI(MBB, MI, DL, TII->get(CCV::BAR_INIT))
            .addImm(Id).addImm(Count == 1024 ? 0 : Count);
        BuildMI(MBB, MI, DL, TII->get(CCV::C_BAR_ARRIVE)).addImm(Id);
        if (M[3] == "sync")
          BuildMI(MBB, MI, DL, TII->get(CCV::C_BAR_WAIT)).addImm(Id);
      } else if (ToE2M1.match(T, &M)) {
        // CCVFoldFP4's: FP32 to E2M1 at chwidth 4, widened into the i32
        // result, which clears bits [31:4] (O-38).
        unsigned Opc = CCV::CVT_D0_S0_R0_W4_32;
        Register N = vreg(CCV::GPR4RegClass);
        cvt(Opc, N, op(M[2]));
        copy(op(M[1]), N);
      } else if (FromE2M1.match(T, &M)) {
        // And back: the i32 source narrowed to its low nibble.
        Register N = vreg(CCV::GPR4RegClass);
        copy(N, op(M[2]));
        unsigned Opc = CCV::CVT_D0_S0_R0_W32_4;
        cvt(Opc, op(M[1]), N);
      } else {
        report_fatal_error("CCV: inline PTX '" + Twine(T) +
                           "' is not one CCV implements (CP-6)");
      }
      MI.eraseFromParent();
      Changed = true;
    }
  return Changed;
}

} // namespace

namespace llvm {
FunctionPass *createCCVExpandPTXAsm() { return new CCVExpandPTXAsm(); }
} // namespace llvm
