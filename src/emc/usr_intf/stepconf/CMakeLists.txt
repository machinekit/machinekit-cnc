cmake_minimum_required(VERSION 3.12)
set (project stepconf)

set(GLADES
	${CMAKE_CURRENT_SOURCE_DIR}/main_page.glade
	${CMAKE_CURRENT_SOURCE_DIR}/base.glade
	${CMAKE_CURRENT_SOURCE_DIR}/start.glade
	${CMAKE_CURRENT_SOURCE_DIR}/pport1.glade
	${CMAKE_CURRENT_SOURCE_DIR}/pport2.glade
	${CMAKE_CURRENT_SOURCE_DIR}/spindle.glade
	${CMAKE_CURRENT_SOURCE_DIR}/options.glade
	${CMAKE_CURRENT_SOURCE_DIR}/axisx.glade
	${CMAKE_CURRENT_SOURCE_DIR}/axisy.glade
	${CMAKE_CURRENT_SOURCE_DIR}/axisz.glade
	${CMAKE_CURRENT_SOURCE_DIR}/axisa.glade
	${CMAKE_CURRENT_SOURCE_DIR}/finished.glade
)

install(
    FILES ${GLADES}
    DESTINATION share/machinekit/${project}
)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "")

set(STEPCONF_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/pages
    ${CMAKE_CURRENT_SOURCE_DIR}/build_INI
    ${CMAKE_CURRENT_SOURCE_DIR}/build_HAL
    ${CMAKE_CURRENT_BINARY_DIR}/__init__
)

# Check syntax of modules
foreach(module ${STEPCONF_MODULES})
    add_custom_command(
        OUTPUT "${module}.pyc"
        COMMAND ${Python2_Interp} -m py_compile "${module}.py"
        DEPENDS "${module}.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

list(TRANSFORM STEPCONF_MODULES APPEND ".py")

install(
    FILES ${STEPCONF_MODULES}
    DESTINATION ${Python2_SITELIB}/${project}
)

# Check syntax of stepconf
add_custom_command(
    OUTPUT ${project}.pyc
    COMMAND ${Python2_Interp} -m py_compile ${project}.py
    DEPENDS ${project}.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Stage stepconf executable for installation
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

# TODO - not sure how to handle I18N stuff yet
#PYI18NSRCS += emc/usr_intf/stepconf/stepconf.py $(patsubst %,emc/usr_intf/stepconf/%.py,$(STEPCONF_MODULES)) \
#	emc/usr_intf/stepconf/main_page.glade \
#	emc/usr_intf/stepconf/base.glade \
#	emc/usr_intf/stepconf/start.glade \
#	emc/usr_intf/stepconf/pport1.glade \
#	emc/usr_intf/stepconf/pport2.glade \
#	emc/usr_intf/stepconf/spindle.glade \
#	emc/usr_intf/stepconf/options.glade \
#	emc/usr_intf/stepconf/axisx.glade \
#	emc/usr_intf/stepconf/axisy.glade \
#	emc/usr_intf/stepconf/axisz.glade \
#	emc/usr_intf/stepconf/axisa.glade \
#	emc/usr_intf/stepconf/finished.glade
