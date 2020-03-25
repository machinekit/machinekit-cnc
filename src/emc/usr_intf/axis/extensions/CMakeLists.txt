cmake_minimum_required(VERSION 2.8)
set (project extensions)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/togl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/minigl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/_toglmodule.c
    ${CMAKE_CURRENT_SOURCE_DIR}/emcmodule.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/togl.h
)

include_directories(../../../)
include_directories(${TCL_INCLUDE_PATH})

add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
