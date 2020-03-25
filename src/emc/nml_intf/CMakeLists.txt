cmake_minimum_required(VERSION 2.8)
set (project nml_intf)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emcglb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/emcargs.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcops.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcpose.c
    ${CMAKE_CURRENT_SOURCE_DIR}/canon_position.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interpl.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emc.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/interpl.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/emcglb.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emc_nml.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_return.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/emc.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/motion_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emccfg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/debugflags.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emcpose.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emctool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/canon_position.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/emcpos.h
    ${CMAKE_CURRENT_SOURCE_DIR}/canon.hh
)

include_directories(../)

add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
