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

add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
