cmake_minimum_required(VERSION 2.8)
set (project sai)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/builtin_modules.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/driver.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/saicanon.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/dummyemcstat.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nullcanon.cc
)

add_library(${project} STATIC ${${project}_SOURCES} )
