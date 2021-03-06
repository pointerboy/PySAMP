project(PySAMP)

add_compile_options(-std=c++11)


cmake_minimum_required(VERSION 2.8)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#find_package (Python3 COMPONENTS Interpreter Development)

find_package (PythonInterp 3.5.3)
find_package (PythonLibs 3.5.3)

include(AMXConfig)
include(AddSAMPPlugin)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/amx
  ${CMAKE_CURRENT_SOURCE_DIR}/bindings
  ${CMAKE_CURRENT_SOURCE_DIR}/pysamp
  ${PYTHON_INCLUDE_DIR}
)

message(STATUS "PYTHON_LIBRARY = ${PYTHON_LIBRARY}")
message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIR = ${PYTHON_INCLUDE_DIR}")

add_definitions(-DSAMPGDK_AMALGAMATION)

link_libraries(${PYTHON_LIBRARIES})

add_samp_plugin(pySAMP
  amxplugin.cpp
  main.h
  main.cpp
  main.def
  sampgdk.c
  sampgdk.h
  pysamp/pysamp.cpp
  pysamp/pysamp.h
  pysamp/pygamemode.cpp
  pysamp/pygamemode.h
  bindings/callbacks.h
  bindings/samp.h
  bindings/const.h
  bindings/const.cpp
  test/callbackstest.h
  test/callbackstest.cpp
)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
  )
endif(DOXYGEN_FOUND)
