cmake_minimum_required(VERSION 3.0.2)

project(machinekit-cnc)

include(CheckIncludeFiles)

set(MK_VERSION_MAJOR 0)
set(MK_VERSION_MINOR 3)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(PROJECT_PYTHON_DIR ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/python)
set(PROJECT_LIBEXEC_DIR ${PROJECT_BINARY_DIR}/lib/machinekit)
set(PROJECT_LIB_DIR ${PROJECT_BINARY_DIR}/lib)
set(PROJECT_SYSCONF_DIR ${PROJECT_BINARY_DIR}/etc)
set(PROJECT_BIN_DIR ${PROJECT_BINARY_DIR}/bin)
set(PROJECT_DATA_DIR ${PROJECT_BINARY_DIR}/share/machinekit)
set(PROJECT_LOCALE_DIR ${PROJECT_DATA_DIR}/locale)
set(PROJECT_MAN_DIR ${PROJECT_BINARY_DIR}/man)
set(INCLUDE_DIR ${PROJECT_BINARY_DIR}/include)
set(SCRIPTS_DIR ${CMAKE_SOURCE_DIR}/scripts)
set(PROJECT_TCL_DIR ${PROJECT_BINARY_DIR}/lib/tcltk)

if("${CMAKE_INSTALL_PREFIX}" STREQUAL "/usr")
    set(INSTALL_SYSCONF_DIR "/etc")
else()
    set(INSTALL_SYSCONF_DIR "${CMAKE_INSTALL_PREFIX}/etc")
endif()

include(Options)
include(Dependencies)
include(Macros)

include_directories(${INCLUDE_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(scripts)
#add_subdirectory(po)


# Note, maybe this should source from <machinekit/config.h>?
# Setting the include directory for the application to find config.h
#include_directories( ${CMAKE_BINARY_DIR} )
# Since we have created a config.h add a global define for it
#add_definitions( "-DHAVE_CONFIG_H" )
