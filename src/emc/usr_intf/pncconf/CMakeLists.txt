cmake_minimum_required(VERSION 2.8)
set (project pncconf)

set(GLADES
    pncconf.glade
)

install(
    FILES ${GLADES}
    DESTINATION share/machinekit
)

# Check syntax of pncconf 
add_custom_command(
    OUTPUT pncconf.pyc
    COMMAND ${Python2_Interp} -m py_compile pncconf.py
    DEPENDS pncconf.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Stage pncconf executable for installation
add_custom_target(pncconf
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/pncconf.py pncconf
    DEPENDS pncconf.pyc
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(
    FILES pncconf
    DESTINATION bin
)

# TODO - not sure how to handle I18N stuff yet
# PYI18NSRCS += emc/usr_intf/pncconf/pncconf.py emc/usr_intf/pncconf/pncconf.glade
