cmake_minimum_required(VERSION 2.8)
set (project pythonplugin)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/exec.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/testpp.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/python_plugin.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/python_plugin.hh
)

add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
