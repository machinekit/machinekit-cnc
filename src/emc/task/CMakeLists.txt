cmake_minimum_required(VERSION 2.8)
set (project task)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsvr.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/taskintf.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/iotaskintf.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/signalhandler.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/taskmodule.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emccanon.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/backtrace.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/taskclass.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emctask.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emctaskmain.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/task.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/taskclass.hh
)

include_directories(../)

#add_library(${project} ${${project}_SOURCES} ${${project}_HEADERS} )
add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
