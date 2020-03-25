cmake_minimum_required(VERSION 2.8)
set (project gscreen)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "")

set(gscreen_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/mdi
    ${CMAKE_CURRENT_SOURCE_DIR}/emc_interface
    ${CMAKE_CURRENT_SOURCE_DIR}/preferences
    ${CMAKE_CURRENT_SOURCE_DIR}/keybindings
    ${CMAKE_CURRENT_BINARY_DIR}/__init__
)

# Check syntax of modules
foreach(module ${gscreen_MODULES})
    add_custom_command(
        OUTPUT "${module}.pyc"
        COMMAND ${Python2_Interp} -m py_compile "${module}.py"
        DEPENDS "${module}.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

list(TRANSFORM gscreen_MODULES APPEND ".py")

install(
    FILES ${gscreen_MODULES}
    DESTINATION ${Python2_SITELIB}/${project}
)

# Check syntax of gscreen
add_custom_command(
    OUTPUT "${project}.pyc"
    COMMAND ${Python2_Interp} -m py_compile "${project}.py"
    DEPENDS "${project}.py"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Stage gscreen executable for installation
add_custom_target(${project}
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${project}.py ${project}
    DEPENDS ${project}.pyc
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(
    FILES "${project}.py"
    DESTINATION bin
    RENAME ${project}
)

set(gscreen_GLADES
    ${CMAKE_CURRENT_SOURCE_DIR}/gscreen.glade
    ${CMAKE_CURRENT_SOURCE_DIR}/gscreen2.glade
)

install(
    FILES ${gscreen_GLADES}
    DESTINATION share/machinekit
)

# TODO - not sure how to handle I18N stuff yet
#PYI18NSRCS += emc/usr_intf/gscreen/gscreen.py $(patsubst %,emc/usr_intf/gscreen/%.py,$(GSCREEN_MODULES)) \
#	emc/usr_intf/gscreen/gscreen.glade \
#	emc/usr_intf/gscreen/gscreen2.glade

