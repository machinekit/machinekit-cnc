cmake_minimum_required(VERSION 2.8)
set (project rcs)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/rcs_exit.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/rcs_print.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/rcs_exit.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/rcs.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/rcs_print.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/rcsversion.h
)

include_directories(../)

add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)

