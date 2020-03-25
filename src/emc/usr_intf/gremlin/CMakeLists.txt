cmake_minimum_required(VERSION 2.8)
set (project gremlin)

set(gremlin_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/gremlin
)

# Check syntax of modules
foreach(module ${gremlin_MODULES})
    add_custom_command(
        OUTPUT "${module}.pyc"
        COMMAND ${Python2_Interp} -m py_compile "${module}.py"
        DEPENDS "${module}.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

list(TRANSFORM gremlin_MODULES APPEND ".py")

install(
    FILES ${gremlin_MODULES}
    DESTINATION ${Python2_SITELIB}/
)

# Check syntax of gremlin-run
add_custom_command(
    OUTPUT "${project}-run.pyc"
    COMMAND ${Python2_Interp} -m py_compile "${project}-run.py"
    DEPENDS "${project}-run.py"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Stage gremlin executable for installation
add_custom_target(${project}
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${project}-run.py ${project}-run
    DEPENDS ${project}-run.pyc
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(
    FILES ${project}-run
    DESTINATION bin
)

# TODO - not sure how to handle I18N stuff yet
#PYI18NSRCS += emc/usr_intf/gremlin/gremlin.py

