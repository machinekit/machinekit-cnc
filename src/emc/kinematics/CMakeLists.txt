cmake_minimum_required(VERSION 2.8)
set (project kinematics)

set(USER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/genserkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drawbotkins.c
)

set(PY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/lineardeltakins.c
)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/tripodkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/rotatekins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lineardeltakins.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/XYZACkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/genhexkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/5axiskins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/maxkins.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cubic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/scarakins.c
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

include_directories(../)

#add_library(${project} OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
#target_compile_options(${project} PUBLIC)

## -- DELTA_MODULE

set(DELTA_MODULE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/lineardeltakins.c
)

add_library(lineardeltakins SHARED ${DELTA_MODULE_SOURCES} )
target_link_libraries(lineardeltakins Boost::python)
target_compile_options(lineardeltakins PUBLIC -x c++ -Wno-declaration-after-statement -fpermissive )

## -- GEN_SERKINS

set(GEN_SERKINS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/genserkins.c
)

add_executable(genserkins ${GEN_SERKINS_SOURCES})
target_link_libraries(genserkins mkhal posemath rtapi_math)

## -- DRAW_BOTKINS

set(DRAW_BOTKINS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/drawbotkins.c
)
add_executable(drawbotkins ${GEN_SERKINS_SOURCES})
target_link_libraries(drawbotkins mkhal posemath rtapi_math)
