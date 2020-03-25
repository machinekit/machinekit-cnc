cmake_minimum_required(VERSION 2.8)
set (project motion)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/homing.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stashf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/command.c
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_tp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/emcmotglb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/motion.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dbuf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/control.c
    ${CMAKE_CURRENT_SOURCE_DIR}/emcmotutil.c
    ${CMAKE_CURRENT_SOURCE_DIR}/usrmotintf.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/motion_debug.h
    ${CMAKE_CURRENT_SOURCE_DIR}/motion_id.h
    ${CMAKE_CURRENT_SOURCE_DIR}/motion_struct.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emcmotglb.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emcmotcfg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/usrmotintf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/state_tag.h
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_tp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/stashf_wrap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/motion.h
    ${CMAKE_CURRENT_SOURCE_DIR}/mot_priv.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dbuf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/stashf.h
)

include_directories(../)
include_directories(${KERNELHEADERS_INCLUDE_DIRS})

#add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
#target_compile_options(${project} PUBLIC)
