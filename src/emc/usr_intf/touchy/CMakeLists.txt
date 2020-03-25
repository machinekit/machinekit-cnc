cmake_minimum_required(VERSION 3.12)
set (project touchy)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "")

set(TOUCHY_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/mdi
    ${CMAKE_CURRENT_SOURCE_DIR}/emc_interface
    ${CMAKE_CURRENT_SOURCE_DIR}/hal_interface
    ${CMAKE_CURRENT_SOURCE_DIR}/filechooser
    ${CMAKE_CURRENT_SOURCE_DIR}/listing
    ${CMAKE_CURRENT_SOURCE_DIR}/preferences
    ${CMAKE_CURRENT_BINARY_DIR}/__init__
)

# Check syntax of modules
foreach(module ${TOUCHY_MODULES})
    add_custom_command(
        OUTPUT "${module}.pyc"
        COMMAND ${Python2_Interp} -m py_compile "${module}.py"
        DEPENDS "${module}.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

list(TRANSFORM TOUCHY_MODULES APPEND ".py")

install(
    FILES ${TOUCHY_MODULES}
    DESTINATION ${Python2_SITELIB}/${project}
)

# Check syntax of touchy
add_custom_command(
    OUTPUT ${project}.pyc
    COMMAND ${Python2_Interp} -m py_compile ${project}.py
    DEPENDS ${project}.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Stage touchy executable for installation
add_custom_target(${project}
    COMMAND cp "${CMAKE_CURRENT_SOURCE_DIR}/${project}.py" ${project}
    DEPENDS ${project}.pyc
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(
    FILES "${project}.py"
    DESTINATION bin
    RENAME ${project}
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/touchy.glade
    DESTINATION share/machinekit
)

# TODO - not sure how to handle I18N stuff yet
#PYI18NSRCS += emc/usr_intf/touchy/touchy.py $(patsubst %,emc/usr_intf/touchy/%.py,$(TOUCHY_MODULES)) \
#	emc/usr_intf/touchy/touchy.glade

