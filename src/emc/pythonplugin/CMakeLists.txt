cmake_minimum_required(VERSION 2.8)
set (project pyplugin)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/exec.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/testpp.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/python_plugin.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/python_plugin.hh
)

add_library(${project} SHARED ${${project}_SOURCES} ${${project}_HEADERS} )
target_link_libraries(${project} mkini)

install(TARGETS ${project}
    LIBRARY DESTINATION lib
)
