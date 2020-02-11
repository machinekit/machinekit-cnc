cmake_minimum_required(VERSION 3.13)
set (project mk)

add_definitions(-DEMC2_DEFAULT_NMLFILE="${CMAKE_INSTALL_PREFIX}/configs/common/linuxcnc.nml")

include_directories(../libnml)
include_directories(${Python2_INCLUDE_DIRS})

# For libnml
link_directories(${LIBRARY_OUTPUT_DIRECTORY})

add_subdirectory(iotask)
add_subdirectory(motion)
add_subdirectory(nml_intf)
add_subdirectory(rs274ngc)
add_subdirectory(tp)
add_subdirectory(task)
add_subdirectory(toolstore)
add_subdirectory(canterp)
add_subdirectory(kinematics)
add_subdirectory(usr_intf)
add_subdirectory(pythonplugin)
add_subdirectory(sai)
add_subdirectory(ini)

add_library(${project} STATIC 
    $<TARGET_OBJECTS:ini>
    $<TARGET_OBJECTS:nml_intf>
    $<TARGET_OBJECTS:rs274_objs>
)

add_library(${project}_SHARED SHARED
    $<TARGET_OBJECTS:ini>
    $<TARGET_OBJECTS:nml_intf>
    $<TARGET_OBJECTS:rs274_objs>
)

install(TARGETS ${project}
    ARCHIVE DESTINATION lib
)

install(TARGETS ${${project}_SHARED}
    LIBRARY DESTINATION lib
)
