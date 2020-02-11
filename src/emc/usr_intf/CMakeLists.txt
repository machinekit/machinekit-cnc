cmake_minimum_required(VERSION 2.8)
set (project usr_intf)

if (WITH_RUN_IN_PLACE)
    add_definitions(-D__DIR__=${EMC2_HOME})
else()
    add_definitions(-D__DIR__="/var/cache/linuxcnc")
endif()

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsched.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/schedrmt.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsh.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emclcd.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcrsh.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/keystick.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/xemc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sockets.c
    ${CMAKE_CURRENT_SOURCE_DIR}/emcweb.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emccontroller.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsched.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/emccontroller.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/sockets.h
)

add_subdirectory(axis)
add_subdirectory(gmoccapy)
add_subdirectory(pncconf)
add_subdirectory(emcweb)
add_subdirectory(touchy)
add_subdirectory(gremlin)
add_subdirectory(stepconf)
add_subdirectory(gscreen)

include_directories(../)
include_directories(${TCL_INCLUDE_PATH})
include_directories(${TK_INCLUDE_PATH})

add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
