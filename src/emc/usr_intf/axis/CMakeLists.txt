cmake_minimum_required(VERSION 3.12)
set (project axis)

add_subdirectory(extensions)
add_subdirectory(etc)
add_subdirectory(scripts)

# PYTARGETS += $(EMCMODULE) $(MINIGLMODULE) $(TOGLMODULE)

set(AXIS_PY_TARGETS
    axis
    axis-remote
    linuxcnctop
    hal_manualtoolchange
    mdi
    image-to-gcode
    lintini
    debuglevel
    teach-in
    tracking-test
)

# image-to-gcode needs python-pil, numpy

# Check syntax of targets
foreach(_target ${AXIS_PY_TARGETS})
    add_custom_command(
        OUTPUT "${_target}.pyc"
        COMMAND ${Python2_Interp} -m py_compile "${CMAKE_CURRENT_SOURCE_DIR}/scripts/${_target}.py"
        DEPENDS "${_target}.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
    add_custom_target(${_target}
        COMMAND cp "${CMAKE_CURRENT_SOURCE_DIR}/scripts/${_target}.py" "${_target}"
        DEPENDS "{_target}.pyc"
        VERBATIM
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

# Fix target paths and file extentions
list(TRANSFORM AXIS_PY_TARGETS PREPEND "scripts/")
list(TRANSFORM AXIS_PY_TARGETS APPEND ".py")

install(
    FILES ${AXIS_PY_TARGETS}
    DESTINATION bin
)

# TODO - not sure how to handle I18N stuff yet
#PYI18NSRCS += $(addprefix emc/usr_intf/axis/scripts/, $(PYSCRIPTS))  \
#	../lib/python/propertywindow.py \
#	../share/axis/tcl/axis.tcl

include_directories(../../)
include_directories(${TCL_INCLUDE_PATH})
include_directories(${TK_INCLUDE_PATH})

set(EMC_MODULE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/extensions/emcmodule.cc
)
add_library(emcmodule SHARED ${EMC_MODULE_SOURCES})
#		-lGL

set(MINIGL_MODULE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/extensions/minigl.c
)
add_library(minigl SHARED ${MINIGL_MODULE_SOURCES})
#		-lGL -lGLU

set(TOGL_MODULE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/extensions/_toglmodule.c
)
add_library(_togl SHARED ${TOGL_MODULE_SOURCES})
#		-lX11 -lGL -lGLU -lXmu $(TCL_LIBS)
