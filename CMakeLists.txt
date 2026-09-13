cmake_minimum_required(VERSION 3.20)
project(ccg-mc CXX)

# Out-of-tree build against an installed LLVM. The target is not registered with
# LLVM's build system, so TableGen is invoked directly and the generated .inc
# files land in the build directory.
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Using LLVM ${LLVM_PACKAGE_VERSION} from ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(LLVM_TBLGEN NAMES llvm-tblgen-${LLVM_VERSION_MAJOR} llvm-tblgen
             HINTS ${LLVM_TOOLS_BINARY_DIR} REQUIRED)

set(TD_DIR  ${CMAKE_SOURCE_DIR}/llvm/CCG)

# Every .td, not a hand-kept subset: CCGInstrPatterns.td and CCGCallingConv.td
# were missing from the dependency list, so pattern edits silently reused stale
# tables and TableGen's own errors never reached the build log.
file(GLOB CCG_TD_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/llvm/CCG/*.td)
set(GEN_DIR ${CMAKE_BINARY_DIR}/generated)
file(MAKE_DIRECTORY ${GEN_DIR})

# backend -> output file
set(CCG_TABLEGEN
    gen-register-info      CCGGenRegisterInfo.inc
    gen-instr-info         CCGGenInstrInfo.inc
    gen-subtarget          CCGGenSubtargetInfo.inc
    gen-emitter            CCGGenMCCodeEmitter.inc
    gen-asm-writer         CCGGenAsmWriter.inc
    gen-disassembler       CCGGenDisassemblerTables.inc
    gen-callingconv        CCGGenCallingConv.inc
    gen-dag-isel           CCGGenDAGISel.inc)

set(GENERATED_INCS "")
list(LENGTH CCG_TABLEGEN _n)
math(EXPR _last "${_n} / 2 - 1")
foreach(i RANGE ${_last})
  math(EXPR _bi "${i} * 2")
  math(EXPR _fi "${i} * 2 + 1")
  list(GET CCG_TABLEGEN ${_bi} _backend)
  list(GET CCG_TABLEGEN ${_fi} _out)
  add_custom_command(
    OUTPUT  ${GEN_DIR}/${_out}
    COMMAND ${LLVM_TBLGEN} -I ${LLVM_INCLUDE_DIRS} -I ${TD_DIR}
            --${_backend} ${TD_DIR}/CCG.td -o ${GEN_DIR}/${_out}
    DEPENDS ${CCG_TD_SOURCES}
    COMMENT "TableGen ${_backend}")
  list(APPEND GENERATED_INCS ${GEN_DIR}/${_out})
endforeach()

# Operand field widths for the round-trip tool, derived from the same .td.
add_custom_command(
  OUTPUT  ${GEN_DIR}/CCGOperandWidths.inc
  COMMAND ${LLVM_TBLGEN} -I ${LLVM_INCLUDE_DIRS} -I ${TD_DIR}
          --dump-json ${TD_DIR}/CCG.td -o ${GEN_DIR}/CCG.json
  COMMAND ${CMAKE_SOURCE_DIR}/tools/gen-operand-widths.py
          ${GEN_DIR}/CCG.json ${GEN_DIR}/CCGOperandWidths.inc
  DEPENDS ${CCG_TD_SOURCES} ${CMAKE_SOURCE_DIR}/tools/gen-operand-widths.py
  COMMENT "Generating operand field widths")
list(APPEND GENERATED_INCS ${GEN_DIR}/CCGOperandWidths.inc)

add_custom_target(CCGTableGen DEPENDS ${GENERATED_INCS})

add_library(CCGMC STATIC
  llvm/CCG/TargetInfo/CCGTargetInfo.cpp
  llvm/CCG/MCTargetDesc/CCGMCTargetDesc.cpp
  llvm/CCG/MCTargetDesc/CCGMCCodeEmitter.cpp
  llvm/CCG/MCTargetDesc/CCGInstPrinter.cpp
  llvm/CCG/Disassembler/CCGDisassembler.cpp
  llvm/CCG/CCGRegisterInfo.cpp
  llvm/CCG/CCGInstrInfo.cpp
  llvm/CCG/CCGISelLowering.cpp
  llvm/CCG/CCGSubtarget.cpp
  llvm/CCG/CCGTargetMachine.cpp
  llvm/CCG/CCGISelDAGToDAG.cpp
  llvm/CCG/CCGAsmPrinter.cpp
  llvm/CCG/CCGCheckIR.cpp
  llvm/CCG/CCGExpandPseudos.cpp
  llvm/CCG/CCGWindowRemat.cpp
  llvm/CCG/CCGLowerShared.cpp
  llvm/CCG/CCGCompress.cpp
  llvm/CCG/CCGExpandDivision.cpp
  llvm/CCG/CCGFrameLowering.cpp
  llvm/CCG/CCGTargetTransformInfo.cpp
  llvm/CCG/CCGUniformity.cpp
  llvm/CCG/MCTargetDesc/CCGAsmBackend.cpp)
add_dependencies(CCGMC CCGTableGen)
target_include_directories(CCGMC PUBLIC
  ${GEN_DIR} ${TD_DIR} ${CMAKE_SOURCE_DIR}/llvm/CCG ${LLVM_INCLUDE_DIRS})
target_compile_definitions(CCGMC PUBLIC ${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(LLVM_LIBS mc mcdisassembler support
                                codegen selectiondag asmprinter target analysis
                                irreader core bitreader mcparser)
target_link_libraries(CCGMC PUBLIC ${LLVM_LIBS})

add_executable(ccg-roundtrip tools/ccg-roundtrip/main.cpp)
add_dependencies(ccg-roundtrip CCGTableGen)
target_link_libraries(ccg-roundtrip PRIVATE CCGMC)

add_executable(ccg-llc tools/ccg-llc/main.cpp)
add_dependencies(ccg-llc CCGTableGen)
target_link_libraries(ccg-llc PRIVATE CCGMC)

add_executable(ccg-sim tools/ccg-sim/main.cpp tools/ccg-sim/Interp.cpp)
add_dependencies(ccg-sim CCGTableGen)
target_include_directories(ccg-sim PRIVATE ${CMAKE_SOURCE_DIR}/tools/ccg-sim)
target_link_libraries(ccg-sim PRIVATE CCGMC)

add_library(CCGLowerKernelArgs MODULE llvm/CCG/IR/CCGLowerKernelArgs.cpp)
target_include_directories(CCGLowerKernelArgs PRIVATE ${LLVM_INCLUDE_DIRS})
target_compile_definitions(CCGLowerKernelArgs PRIVATE ${LLVM_DEFINITIONS})
set_target_properties(CCGLowerKernelArgs PROPERTIES PREFIX "")

enable_testing()
add_test(NAME roundtrip COMMAND ccg-roundtrip)
