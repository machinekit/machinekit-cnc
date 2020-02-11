cmake_minimum_required(VERSION 3.12)
set (project stepconf)

set(GLADES
	main_page.glade
	base.glade
	start.glade
	pport1.glade
	pport2.glade
	spindle.glade
	options.glade
	axisx.glade
	axisy.glade
	axisz.glade
	axisa.glade
	finished.glade
)

install(
    FILES ${GLADES}
    DESTINATION share/machinekit/stepconf
)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "")

set(STEPCONF_MODULES
    pages
    build_INI
    build_HAL
    __init__
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
    DESTINATION ${Python2_SITELIB}/stepconf
)

# Check syntax of stepconf
add_custom_command(
    OUTPUT stepconf.pyc
    COMMAND ${Python2_Interp} -m py_compile stepconf.py
    DEPENDS stepconf.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Stage stepconf executable for installation
add_custom_target(stepconf
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/stepconf.py stepconf
    DEPENDS stepconf.pyc
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(
    FILES stepconf
    DESTINATION bin
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
