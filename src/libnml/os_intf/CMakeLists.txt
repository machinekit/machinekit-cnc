cmake_minimum_required(VERSION 2.8)
set (project os_intf)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/inetnull.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/_sem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sem.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/_shm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/shm.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/_timer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/inetfile.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/_sem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/sem.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/_shm.h
    ${CMAKE_CURRENT_SOURCE_DIR}/shm.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/_timer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.hh
)

include_directories(../)

add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
