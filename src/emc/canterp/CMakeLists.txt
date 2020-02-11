cmake_minimum_required(VERSION 2.8)
set (project canterp)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/canterp.cc
)

add_library(${project} ${${project}_SOURCES} )
