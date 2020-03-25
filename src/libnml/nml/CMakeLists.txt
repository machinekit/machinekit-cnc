cmake_minimum_required(VERSION 2.8)
set (project nml_objs)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/cmd_msg.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nml.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nml_mod.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nml_oi.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nml_srv.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nmldiag.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nmlmsg.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/stat_msg.cc
)

# Header not used / residual?
#check_include_file(machinekit/inifile.hh MACHINEKIT_HAL_INI_FOUND)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/cmd_msg.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/nml.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/nml_mod.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/nml_oi.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/nml_srv.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/nml_type.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/nmldiag.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/nmlmsg.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/stat_msg.hh
)

include_directories(../)

add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project} PUBLIC -fPIC)
