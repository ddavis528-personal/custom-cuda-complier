/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register Enum Values                                                *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM

namespace llvm {

class MCRegisterClass;
extern const MCRegisterClass CCVMCRegisterClasses[];

namespace CCV {
enum {
  NoRegister,
  P0 = 1,
  P1 = 2,
  P2 = 3,
  P3 = 4,
  R0 = 5,
  R1 = 6,
  R2 = 7,
  R3 = 8,
  R4 = 9,
  R5 = 10,
  R6 = 11,
  R7 = 12,
  R8 = 13,
  R9 = 14,
  R10 = 15,
  R11 = 16,
  R12 = 17,
  R13 = 18,
  R14 = 19,
  R15 = 20,
  NUM_TARGET_REGS // 21
};
} // end namespace CCV

// Register classes

namespace CCV {
enum {
  PRRegClassID = 0,
  GPR16RegClassID = 1,
  GPRRegClassID = 2,

};
} // end namespace CCV

// Register pressure sets enum.
namespace CCV {
enum RegisterPressureSets {
  PR = 0,
  GPR16 = 1,
};
} // end namespace CCV

} // end namespace llvm

#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* MC Register Information                                                    *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC

namespace llvm {

extern const int16_t CCVRegDiffLists[] = {
  /* 0 */ 0,
};

extern const LaneBitmask CCVLaneMaskLists[] = {
  /* 0 */ LaneBitmask(0xFFFFFFFFFFFFFFFF), LaneBitmask::getAll(),
};

extern const uint16_t CCVSubRegIdxLists[] = {
  /* 0 */ 0,
};

extern const MCRegisterInfo::SubRegCoveredBits CCVSubRegIdxRanges[] = {
  { 65535, 65535 },
};


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char CCVRegStrings[] = {
  /* 0 */ "R10\0"
  /* 4 */ "P0\0"
  /* 7 */ "R0\0"
  /* 10 */ "R11\0"
  /* 14 */ "P1\0"
  /* 17 */ "R1\0"
  /* 20 */ "R12\0"
  /* 24 */ "P2\0"
  /* 27 */ "R2\0"
  /* 30 */ "R13\0"
  /* 34 */ "P3\0"
  /* 37 */ "R3\0"
  /* 40 */ "R14\0"
  /* 44 */ "R4\0"
  /* 47 */ "R15\0"
  /* 51 */ "R5\0"
  /* 54 */ "R6\0"
  /* 57 */ "R7\0"
  /* 60 */ "R8\0"
  /* 63 */ "R9\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const MCRegisterDesc CCVRegDesc[] = { // Descriptors
  { 3, 0, 0, 0, 0, 0 },
  { 4, 0, 0, 0, 0, 0 },
  { 14, 0, 0, 0, 1, 0 },
  { 24, 0, 0, 0, 2, 0 },
  { 34, 0, 0, 0, 3, 0 },
  { 7, 0, 0, 0, 4, 0 },
  { 17, 0, 0, 0, 5, 0 },
  { 27, 0, 0, 0, 6, 0 },
  { 37, 0, 0, 0, 7, 0 },
  { 44, 0, 0, 0, 8, 0 },
  { 51, 0, 0, 0, 9, 0 },
  { 54, 0, 0, 0, 10, 0 },
  { 57, 0, 0, 0, 11, 0 },
  { 60, 0, 0, 0, 12, 0 },
  { 63, 0, 0, 0, 13, 0 },
  { 0, 0, 0, 0, 14, 0 },
  { 10, 0, 0, 0, 15, 0 },
  { 20, 0, 0, 0, 16, 0 },
  { 30, 0, 0, 0, 17, 0 },
  { 40, 0, 0, 0, 18, 0 },
  { 47, 0, 0, 0, 19, 0 },
};

extern const MCPhysReg CCVRegUnitRoots[][2] = {
  { CCV::P0 },
  { CCV::P1 },
  { CCV::P2 },
  { CCV::P3 },
  { CCV::R0 },
  { CCV::R1 },
  { CCV::R2 },
  { CCV::R3 },
  { CCV::R4 },
  { CCV::R5 },
  { CCV::R6 },
  { CCV::R7 },
  { CCV::R8 },
  { CCV::R9 },
  { CCV::R10 },
  { CCV::R11 },
  { CCV::R12 },
  { CCV::R13 },
  { CCV::R14 },
  { CCV::R15 },
};

namespace {     // Register classes...
  // PR Register Class...
  const MCPhysReg PR[] = {
    CCV::P0, CCV::P1, CCV::P2, CCV::P3, 
  };

  // PR Bit set.
  const uint8_t PRBits[] = {
    0x1e, 
  };

  // GPR16 Register Class...
  const MCPhysReg GPR16[] = {
    CCV::R14, CCV::R13, CCV::R12, CCV::R11, CCV::R10, CCV::R9, CCV::R8, CCV::R7, CCV::R6, CCV::R5, CCV::R4, CCV::R3, CCV::R2, CCV::R1, CCV::R0, CCV::R15, 
  };

  // GPR16 Bit set.
  const uint8_t GPR16Bits[] = {
    0xe0, 0xff, 0x1f, 
  };

  // GPR Register Class...
  const MCPhysReg GPR[] = {
    CCV::R0, CCV::R1, CCV::R2, CCV::R3, CCV::R4, CCV::R5, CCV::R6, CCV::R7, CCV::R8, CCV::R9, CCV::R10, CCV::R11, CCV::R12, CCV::R13, CCV::R14, CCV::R15, 
  };

  // GPR Bit set.
  const uint8_t GPRBits[] = {
    0xe0, 0xff, 0x1f, 
  };

} // end anonymous namespace


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char CCVRegClassStrings[] = {
  /* 0 */ "GPR16\0"
  /* 6 */ "GPR\0"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const MCRegisterClass CCVMCRegisterClasses[] = {
  { PR, PRBits, 7, 4, sizeof(PRBits), CCV::PRRegClassID, 1, 1, true },
  { GPR16, GPR16Bits, 0, 16, sizeof(GPR16Bits), CCV::GPR16RegClassID, 16, 1, true },
  { GPR, GPRBits, 6, 16, sizeof(GPRBits), CCV::GPRRegClassID, 32, 1, true },
};

extern const uint16_t CCVRegEncodingTable[] = {
  0,
  0,
  1,
  2,
  3,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
};
static inline void InitCCVMCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(CCVRegDesc, 21, RA, PC, CCVMCRegisterClasses, 3, CCVRegUnitRoots, 20, CCVRegDiffLists, CCVLaneMaskLists, CCVRegStrings, CCVRegClassStrings, CCVSubRegIdxLists, 1,
CCVSubRegIdxRanges, CCVRegEncodingTable);

}

} // end namespace llvm

#endif // GET_REGINFO_MC_DESC

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Register Information Header Fragment                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_HEADER
#undef GET_REGINFO_HEADER

#include "llvm/CodeGen/TargetRegisterInfo.h"

namespace llvm {

class CCVFrameLowering;

struct CCVGenRegisterInfo : public TargetRegisterInfo {
  explicit CCVGenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0,
      unsigned PC = 0, unsigned HwMode = 0);
  const RegClassWeight &getRegClassWeight(const TargetRegisterClass *RC) const override;
  unsigned getRegUnitWeight(unsigned RegUnit) const override;
  unsigned getNumRegPressureSets() const override;
  const char *getRegPressureSetName(unsigned Idx) const override;
  unsigned getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const override;
  const int *getRegClassPressureSets(const TargetRegisterClass *RC) const override;
  const int *getRegUnitPressureSets(unsigned RegUnit) const override;
  ArrayRef<const char *> getRegMaskNames() const override;
  ArrayRef<const uint32_t *> getRegMasks() const override;
  bool isGeneralPurposeRegister(const MachineFunction &, MCRegister) const override;
  bool isFixedRegister(const MachineFunction &, MCRegister) const override;
  bool isArgumentRegister(const MachineFunction &, MCRegister) const override;
  bool isConstantPhysReg(MCRegister PhysReg) const override final;
  /// Devirtualized TargetFrameLowering.
  static const CCVFrameLowering *getFrameLowering(
      const MachineFunction &MF);
};

namespace CCV { // Register classes
  extern const TargetRegisterClass PRRegClass;
  extern const TargetRegisterClass GPR16RegClass;
  extern const TargetRegisterClass GPRRegClass;
} // end namespace CCV

} // end namespace llvm

#endif // GET_REGINFO_HEADER

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register and Register Classes Information                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_TARGET_DESC
#undef GET_REGINFO_TARGET_DESC

namespace llvm {

extern const MCRegisterClass CCVMCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i1, MVT::Other,
  /* 2 */ MVT::i16, MVT::Other,
  /* 4 */ MVT::i32, MVT::f32, MVT::Other,
};

static const char *SubRegIndexNameTable[] = { "" };


static const LaneBitmask SubRegIndexLaneMaskTable[] = {
  LaneBitmask::getAll(),
 };



static const TargetRegisterInfo::RegClassInfo RegClassInfos[] = {
  // Mode = 0 (Default)
  { 1, 1, 32, /*VTLists+*/0 },    // PR
  { 16, 16, 32, /*VTLists+*/2 },    // GPR16
  { 32, 32, 32, /*VTLists+*/4 },    // GPR
};

static const TargetRegisterClass *const NullRegClasses[] = { nullptr };

static const uint32_t PRSubClassMask[] = {
  0x00000001, 
};

static const uint32_t GPR16SubClassMask[] = {
  0x00000006, 
};

static const uint32_t GPRSubClassMask[] = {
  0x00000004, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 0,
};

static const TargetRegisterClass *const GPRSuperclasses[] = {
  &CCV::GPR16RegClass,
  nullptr
};


namespace CCV {   // Register class instances
  extern const TargetRegisterClass PRRegClass = {
    &CCVMCRegisterClasses[PRRegClassID],
    PRSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass GPR16RegClass = {
    &CCVMCRegisterClasses[GPR16RegClassID],
    GPR16SubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass GPRRegClass = {
    &CCVMCRegisterClasses[GPRRegClassID],
    GPRSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false,
    0x00, /* TSFlags */
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    GPRSuperclasses,
    nullptr
  };

} // end namespace CCV

namespace {
  const TargetRegisterClass *const RegisterClasses[] = {
    &CCV::PRRegClass,
    &CCV::GPR16RegClass,
    &CCV::GPRRegClass,
  };
} // end anonymous namespace

static const uint8_t CostPerUseTable[] = { 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };


static const bool InAllocatableClassTable[] = { 
false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, };


static const TargetRegisterInfoDesc CCVRegInfoDesc = { // Extra Descriptors
CostPerUseTable, 1, InAllocatableClassTable};

/// Get the weight in units of pressure for this register class.
const RegClassWeight &CCVGenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 4},  	// PR
    {1, 16},  	// GPR16
    {1, 16},  	// GPR
  };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned CCVGenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 20 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned CCVGenRegisterInfo::getNumRegPressureSets() const {
  return 2;
}

// Get the name of this register unit pressure set.
const char *CCVGenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *PressureNameTable[] = {
    "PR",
    "GPR16",
  };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned CCVGenRegisterInfo::
getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const {
  static const uint8_t PressureLimitTable[] = {
    4,  	// 0: PR
    16,  	// 1: GPR16
  };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
  /* 0 */ 0, -1,
  /* 2 */ 1, -1,
};

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int *CCVGenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const uint8_t RCSetStartTable[] = {
    0,2,2,};
  return &RCSetsTable[RCSetStartTable[RC->getID()]];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int *CCVGenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 20 && "invalid register unit");
  static const uint8_t RUSetStartTable[] = {
    0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,};
  return &RCSetsTable[RUSetStartTable[RegUnit]];
}

extern const MCRegisterDesc CCVRegDesc[];
extern const int16_t CCVRegDiffLists[];
extern const LaneBitmask CCVLaneMaskLists[];
extern const char CCVRegStrings[];
extern const char CCVRegClassStrings[];
extern const MCPhysReg CCVRegUnitRoots[][2];
extern const uint16_t CCVSubRegIdxLists[];
extern const MCRegisterInfo::SubRegCoveredBits CCVSubRegIdxRanges[];
extern const uint16_t CCVRegEncodingTable[];
CCVGenRegisterInfo::
CCVGenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour,
      unsigned PC, unsigned HwMode)
  : TargetRegisterInfo(&CCVRegInfoDesc, RegisterClasses, RegisterClasses+3,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable,
             LaneBitmask(0xFFFFFFFFFFFFFFFF), RegClassInfos, VTLists, HwMode) {
  InitMCRegisterInfo(CCVRegDesc, 21, RA, PC,
                     CCVMCRegisterClasses, 3,
                     CCVRegUnitRoots,
                     20,
                     CCVRegDiffLists,
                     CCVLaneMaskLists,
                     CCVRegStrings,
                     CCVRegClassStrings,
                     CCVSubRegIdxLists,
                     1,
                     CCVSubRegIdxRanges,
                     CCVRegEncodingTable);

}

static const MCPhysReg CSR_CCV_SaveList[] = { 0 };
static const uint32_t CSR_CCV_RegMask[] = { 0x00000000, };


ArrayRef<const uint32_t *> CCVGenRegisterInfo::getRegMasks() const {
  static const uint32_t *const Masks[] = {
    CSR_CCV_RegMask,
  };
  return ArrayRef(Masks);
}

bool CCVGenRegisterInfo::
isGeneralPurposeRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool CCVGenRegisterInfo::
isFixedRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool CCVGenRegisterInfo::
isArgumentRegister(const MachineFunction &MF, MCRegister PhysReg) const {
  return
      false;
}

bool CCVGenRegisterInfo::
isConstantPhysReg(MCRegister PhysReg) const {
  return
      false;
}

ArrayRef<const char *> CCVGenRegisterInfo::getRegMaskNames() const {
  static const char *Names[] = {
    "CSR_CCV",
  };
  return ArrayRef(Names);
}

const CCVFrameLowering *
CCVGenRegisterInfo::getFrameLowering(const MachineFunction &MF) {
  return static_cast<const CCVFrameLowering *>(
      MF.getSubtarget().getFrameLowering());
}

} // end namespace llvm

#endif // GET_REGINFO_TARGET_DESC

