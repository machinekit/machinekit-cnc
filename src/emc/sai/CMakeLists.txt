cmake_minimum_required(VERSION 3.13)
set (project sai)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/builtin_modules.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/dummyemcstat.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/driver.cc
)

if(WITH_NULLCANON)
    list(APPEND ${project}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/nullcanon.cc")
else()
    list(APPEND ${project}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/saicanon.cc")
endif()

# for pythonplugin
include_directories(../)

link_directories(${READLINE_LIBRARY_PATH})

add_executable(${project} ${${project}_SOURCES} ${${project}_HEADERS} )
target_link_libraries(${project} mk nml mkhal pyplugin rtapi_math Boost::python27 ${PYTHON_LIBRARIES} readline dl)

install(TARGETS ${project}
    RUNTIME DESTINATION bin
    RENAME rs274
)
