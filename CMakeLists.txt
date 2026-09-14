cmake_minimum_required(VERSION 3.20)
project(ccv-mc CXX)

# Out-of-tree build against an installed LLVM. The target is not registered with
# LLVM's build system, so TableGen is invoked directly and the generated .inc
# files land in the build directory.
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Using LLVM ${LLVM_PACKAGE_VERSION} from ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(LLVM_TBLGEN NAMES llvm-tblgen-${LLVM_VERSION_MAJOR} llvm-tblgen
             HINTS ${LLVM_TOOLS_BINARY_DIR} REQUIRED)

set(TD_DIR  ${CMAKE_SOURCE_DIR}/llvm/CCV)

# Every .td, not a hand-kept subset: CCVInstrPatterns.td and CCVCallingConv.td
# were missing from the dependency list, so pattern edits silently reused stale
# tables and TableGen's own errors never reached the build log.
file(GLOB CCV_TD_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/llvm/CCV/*.td)
set(GEN_DIR ${CMAKE_BINARY_DIR}/generated)
file(MAKE_DIRECTORY ${GEN_DIR})

# backend -> output file
set(CCV_TABLEGEN
    gen-register-info      CCVGenRegisterInfo.inc
    gen-instr-info         CCVGenInstrInfo.inc
    gen-subtarget          CCVGenSubtargetInfo.inc
    gen-emitter            CCVGenMCCodeEmitter.inc
    gen-asm-writer         CCVGenAsmWriter.inc
    gen-disassembler       CCVGenDisassemblerTables.inc
    gen-callingconv        CCVGenCallingConv.inc
    gen-dag-isel           CCVGenDAGISel.inc)

set(GENERATED_INCS "")
list(LENGTH CCV_TABLEGEN _n)
math(EXPR _last "${_n} / 2 - 1")
foreach(i RANGE ${_last})
  math(EXPR _bi "${i} * 2")
  math(EXPR _fi "${i} * 2 + 1")
  list(GET CCV_TABLEGEN ${_bi} _backend)
  list(GET CCV_TABLEGEN ${_fi} _out)
  add_custom_command(
    OUTPUT  ${GEN_DIR}/${_out}
    COMMAND ${LLVM_TBLGEN} -I ${LLVM_INCLUDE_DIRS} -I ${TD_DIR}
            --${_backend} ${TD_DIR}/CCV.td -o ${GEN_DIR}/${_out}
    DEPENDS ${CCV_TD_SOURCES}
    COMMENT "TableGen ${_backend}")
  list(APPEND GENERATED_INCS ${GEN_DIR}/${_out})
endforeach()

# Operand field widths for the round-trip tool, derived from the same .td.
add_custom_command(
  OUTPUT  ${GEN_DIR}/CCVOperandWidths.inc
  COMMAND ${LLVM_TBLGEN} -I ${LLVM_INCLUDE_DIRS} -I ${TD_DIR}
          --dump-json ${TD_DIR}/CCV.td -o ${GEN_DIR}/CCV.json
  COMMAND ${CMAKE_SOURCE_DIR}/tools/gen-operand-widths.py
          ${GEN_DIR}/CCV.json ${GEN_DIR}/CCVOperandWidths.inc
  DEPENDS ${CCV_TD_SOURCES} ${CMAKE_SOURCE_DIR}/tools/gen-operand-widths.py
  COMMENT "Generating operand field widths")
list(APPEND GENERATED_INCS ${GEN_DIR}/CCVOperandWidths.inc)

add_custom_target(CCVTableGen DEPENDS ${GENERATED_INCS})

add_library(CCVMC STATIC
  llvm/CCV/TargetInfo/CCVTargetInfo.cpp
  llvm/CCV/MCTargetDesc/CCVMCTargetDesc.cpp
  llvm/CCV/MCTargetDesc/CCVMCCodeEmitter.cpp
  llvm/CCV/MCTargetDesc/CCVInstPrinter.cpp
  llvm/CCV/Disassembler/CCVDisassembler.cpp
  llvm/CCV/CCVRegisterInfo.cpp
  llvm/CCV/CCVInstrInfo.cpp
  llvm/CCV/CCVISelLowering.cpp
  llvm/CCV/CCVSubtarget.cpp
  llvm/CCV/CCVTargetMachine.cpp
  llvm/CCV/CCVISelDAGToDAG.cpp
  llvm/CCV/CCVAsmPrinter.cpp
  llvm/CCV/CCVCheckIR.cpp
  llvm/CCV/CCVExpandPseudos.cpp
  llvm/CCV/CCVWindowRemat.cpp
  llvm/CCV/CCVLowerShared.cpp
  llvm/CCV/CCVCompress.cpp
  llvm/CCV/CCVExpandDivision.cpp
  llvm/CCV/CCVFrameLowering.cpp
  llvm/CCV/CCVTargetTransformInfo.cpp
  llvm/CCV/CCVUniformity.cpp
  llvm/CCV/CCVMaskUniform.cpp
  llvm/CCV/CCVFuseRcpSeed.cpp
  llvm/CCV/MCTargetDesc/CCVAsmBackend.cpp)
add_dependencies(CCVMC CCVTableGen)
target_include_directories(CCVMC PUBLIC
  ${GEN_DIR} ${TD_DIR} ${CMAKE_SOURCE_DIR}/llvm/CCV ${LLVM_INCLUDE_DIRS})
target_compile_definitions(CCVMC PUBLIC ${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(LLVM_LIBS mc mcdisassembler support
                                codegen selectiondag asmprinter target analysis
                                irreader core bitreader mcparser)
target_link_libraries(CCVMC PUBLIC ${LLVM_LIBS})

add_executable(ccv-roundtrip tools/ccv-roundtrip/main.cpp)
add_dependencies(ccv-roundtrip CCVTableGen)
target_link_libraries(ccv-roundtrip PRIVATE CCVMC)

add_executable(ccv-llc tools/ccv-llc/main.cpp)
add_dependencies(ccv-llc CCVTableGen)
target_link_libraries(ccv-llc PRIVATE CCVMC)

add_executable(ccv-sim tools/ccv-sim/main.cpp tools/ccv-sim/Interp.cpp)
add_dependencies(ccv-sim CCVTableGen)
target_include_directories(ccv-sim PRIVATE ${CMAKE_SOURCE_DIR}/tools/ccv-sim)
target_link_libraries(ccv-sim PRIVATE CCVMC)

add_library(CCVLowerKernelArgs MODULE llvm/CCV/IR/CCVLowerKernelArgs.cpp)
target_include_directories(CCVLowerKernelArgs PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(CCVLowerKernelArgs PRIVATE ${LLVM_DEFINITIONS})
set_target_properties(CCVLowerKernelArgs PROPERTIES PREFIX "")

enable_testing()
add_test(NAME roundtrip COMMAND ccv-roundtrip)
