cmake_minimum_required(VERSION 2.8)
set (project linklist)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/linklist.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/linklist.hh
)

add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
