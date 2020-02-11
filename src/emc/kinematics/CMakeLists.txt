cmake_minimum_required(VERSION 2.8)
set (project kinematics)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/tripodkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/rotatekins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lineardeltakins.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/XYZACkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lineardeltakins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/genhexkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/5axiskins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/maxkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/genserkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cubic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/scarakins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drawbotkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/trivkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/gantrykins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pumakins.c
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/rtai-kernel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/genserkins.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pumakins.h
    ${CMAKE_CURRENT_SOURCE_DIR}/genhexkins.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kinematics.h
    ${CMAKE_CURRENT_SOURCE_DIR}/rt-preempt.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lineardeltakins-common.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cubic.h
)

add_subdirectory(userpci)
add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
