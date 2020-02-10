cmake_minimum_required(VERSION 2.8)
set (project buffer)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/locmem.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/memsem.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/phantom.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/physmem.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/recvn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sendn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/shmem.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/tcpmem.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/locmem.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/memsem.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/phantom.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/physmem.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/recvn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/rem_msg.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/sendn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/shmem.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/tcpmem.hh
)

add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
