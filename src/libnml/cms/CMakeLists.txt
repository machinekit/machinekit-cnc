cmake_minimum_required(VERSION 2.8)
set (project cms)

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/cms.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_aup.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_cfg.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_dup.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_in.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_pm.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_srv.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_up.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_xup.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cmsdiag.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/cmssvrp.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/tcp_opts.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/tcp_srv.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/cms.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_aup.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_cfg.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_dup.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_srv.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_up.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_user.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cms_xup.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/cmsdiag.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/tcp_opts.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/tcp_srv.hh
)

add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
