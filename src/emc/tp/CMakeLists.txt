cmake_minimum_required(VERSION 3.13)
set (project tp)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/tpmain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/spherical_arc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/blendmath.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tcq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tp.c
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/tc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tp_debug.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tcq.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tp_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/spherical_arc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/blendmath.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tc_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tp_private.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tp_shared.h
)

include_directories(../)
include_directories(${KERNELHEADERS_INCLUDE_DIRS})

#add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
#target_compile_options(${project} PUBLIC)
