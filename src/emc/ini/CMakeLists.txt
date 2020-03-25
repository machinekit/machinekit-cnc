cmake_minimum_required(VERSION 2.8)
set (project ini)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/initraj.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/iniaxis.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/inihal.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/initool.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcIniFile.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/iniaxis.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/inihal.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/initraj.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/initool.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/emcIniFile.hh
)

include_directories(../)

#add_library(${project} ${${project}_SOURCES} ${${project}_HEADERS} )
add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
