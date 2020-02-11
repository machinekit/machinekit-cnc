cmake_minimum_required(VERSION 2.8)
set (project canterp)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/canterp.cc
)

include_directories(../)

add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
