cmake_minimum_required(VERSION 2.8)
set (project emcweb)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/mongoose_wrapper.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/mongoose.c
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/singleton.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/mongoose.h
    ${CMAKE_CURRENT_SOURCE_DIR}/mongoose_wrapper.hh
)

add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
