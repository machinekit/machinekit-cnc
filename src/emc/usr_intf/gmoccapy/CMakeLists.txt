cmake_minimum_required(VERSION 3.13)
set (project gmoccapy)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/__init__.py "")

set(gmoccapy_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs
    ${CMAKE_CURRENT_SOURCE_DIR}/getiniinfo
    ${CMAKE_CURRENT_SOURCE_DIR}/notification
    ${CMAKE_CURRENT_SOURCE_DIR}/player
    ${CMAKE_CURRENT_SOURCE_DIR}/preferences
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets
    ${CMAKE_CURRENT_BINARY_DIR}/__init__
)

# Check syntax of modules
foreach(module ${gmoccapy_MODULES})
    add_custom_command(
        OUTPUT "${module}.pyc"
        COMMAND ${Python2_Interp} -m py_compile "${module}.py"
        DEPENDS "${module}.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

list(TRANSFORM gmoccapy_MODULES APPEND ".py")

install(
    FILES ${gmoccapy_MODULES}
    DESTINATION ${Python2_SITELIB}/${project}
)

# Check syntax of gmoccapy
add_custom_command(
    OUTPUT "${project}.pyc"
    COMMAND ${Python2_Interp} -m py_compile "${project}.py"
    DEPENDS "${project}.py"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Stage gmoccapy executable for installation
add_custom_target(${project}
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${project}.py ${project}
    DEPENDS ${project}.pyc
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(
    FILES ${project}
    DESTINATION bin
)

set(gmoccapy_GLADES
    ${CMAKE_CURRENT_SOURCE_DIR}/gmoccapy.glade
)

install(
    FILES ${gmoccapy_GLADES}
    DESTINATION share/machinekit
)

# TODO - not sure how to handle I18N stuff yet
#PYTARGETS += ../bin/gmoccapy ../lib/python/gmoccapy/__init__.py $(patsubst %,../lib/python/gmoccapy/%.py,$(GMOCCAPY_MODULES)) \
#	../share/gmoccapy/gmoccapy.glade 
