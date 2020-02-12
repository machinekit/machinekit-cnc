cmake_minimum_required(VERSION 2.8)
set (project rs274)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_execute.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_base.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/rs274ngc_pre.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_internal.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_o_word.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_remap.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_inverse.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/pyemctypes.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/pyblock.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/canonmodule.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interpmodule.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_array.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_read.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_arc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_convert.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_setup.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_namedparams.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/pyparamclass.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_python.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_find.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_check.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_queue.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nurbs_additional_functions.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_cycles.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/tool_parse.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_write.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/pyinterp1.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/modal_state.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/gcodemodule.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/pyarrays.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_internal.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/modal_state.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/pb_decode.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tool_parse.h
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_array_types.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/array1.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/paramclass.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/rs274ngc_interp.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/pb_encode.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pb.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pb_common.h
    ${CMAKE_CURRENT_SOURCE_DIR}/rs274ngc.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_base.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/rs274ngc_return.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/pbutil.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/interp_queue.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/units.h
)

#add_subdirectory(preview)

include_directories(../)

add_library(${project}_objs OBJECT ${${project}_SOURCES} ${${project}_HEADERS} )
target_compile_options(${project}_objs PUBLIC -fPIC)

add_library(${project} SHARED ${${project}_SOURCES} ${${project}_HEADERS} )
target_link_libraries(${project} rtapi_math mkhal)

install(
    TARGETS ${project}
    LIBRARY DESTINATION lib
)

# -- libgcode

set(GCODE_MODULE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/gcodemodule.cc
)

# GCODEMODULE := ../lib/python/gcode.so
add_library(gcode SHARED ${GCODE_MODULE_SOURCES} ${${project}_HEADERS} )
target_link_libraries(gcode ${project} pyplugin Boost::python27)
set_target_properties(gcode PROPERTIES PREFIX "")

install(
    TARGETS gcode
    DESTINATION ${Python2_SITELIB}
)

# -- Preview

set(preview_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/previewmodule.cc
)

add_library(preview SHARED ${preview_SOURCES})
target_link_libraries(preview ${project} pyplugin mktalk-pb2++ mtalk Boost::python27 czmq protobuf stdc++)
set_target_properties(preview PROPERTIES PREFIX "")

install(TARGETS preview
    DESTINATION ${Python2_SITELIB}
)
