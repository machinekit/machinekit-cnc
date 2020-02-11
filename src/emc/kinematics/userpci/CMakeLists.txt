cmake_minimum_required(VERSION 2.8)
set (project userpci)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/module.h
    ${CMAKE_CURRENT_SOURCE_DIR}/slab.h
    ${CMAKE_CURRENT_SOURCE_DIR}/string.h
    ${CMAKE_CURRENT_SOURCE_DIR}/gfp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/rtapi_pci.h
    ${CMAKE_CURRENT_SOURCE_DIR}/firmware.h
    ${CMAKE_CURRENT_SOURCE_DIR}/list.h
    ${CMAKE_CURRENT_SOURCE_DIR}/device.h
    ${CMAKE_CURRENT_SOURCE_DIR}/config_module.h
)

#add_library(${project} STATIC ${${project}_HEADERS} )
