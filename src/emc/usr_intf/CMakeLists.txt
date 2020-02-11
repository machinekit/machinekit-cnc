cmake_minimum_required(VERSION 3.13)
set (project usr_intf)

if (WITH_RUN_IN_PLACE)
    add_definitions(-D__DIR__=${EMC2_HOME})
else()
    add_definitions(-D__DIR__="/var/cache/linuxcnc")
endif()

set(${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsched.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/schedrmt.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsh.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emclcd.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcrsh.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/keystick.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/xemc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sockets.c
    ${CMAKE_CURRENT_SOURCE_DIR}/emcweb.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emccontroller.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.cc
)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsched.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/emccontroller.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/sockets.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emcweb/singleton.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/emcweb/mongoose.h
    ${CMAKE_CURRENT_SOURCE_DIR}/emcweb/mongoose_wrapper.hh
)


add_subdirectory(axis)
add_subdirectory(gmoccapy)
add_subdirectory(pncconf)
add_subdirectory(emcweb)
add_subdirectory(touchy)
add_subdirectory(gremlin)
add_subdirectory(stepconf)
add_subdirectory(gscreen)

include_directories(../)
include_directories(${TCL_INCLUDE_PATH})
include_directories(${TK_INCLUDE_PATH})

set(EMCSH_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsh.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.cc
)

set(EMCRSH_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emcrsh.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.cc
)

set(EMCSCHED_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/schedrmt.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/emcsched.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.cc
)

set(EMCLCD_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emclcd.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sockets.c
)

set(EMCWEB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/shcom.cc
	${CMAKE_CURRENT_SOURCE_DIR}/emccontroller.cc
	${CMAKE_CURRENT_SOURCE_DIR}/emcweb.cc
	${CMAKE_CURRENT_SOURCE_DIR}/emcweb/mongoose.c
	${CMAKE_CURRENT_SOURCE_DIR}/emcweb/mongoose_wrapper.cc
)

if(XINERAMA_FOUND)
    add_library(tclmk SHARED ${EMCSH_SOURCES} ${${project}_HEADERS} )
    target_link_libraries(tclmk ${XINERAMA_LIBRARIES})
endif()

add_executable(mkcncrsh ${EMCRSH_SOURCES} ${${project}_HEADERS} )
target_link_libraries(mkcncrsh nml mk mkini pthread)

add_executable(schedrmt ${EMCSCHED_SOURCES} ${${project}_HEADERS} )
target_link_libraries(schedrmt nml mk mkini pthread)

add_executable(mkclcd ${EMCLCD_SOURCES} ${${project}_HEADERS} )
target_link_libraries(mkclcd nml mk mkini)

if(CURSES_FOUND)
    set(KEYSTICK_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/keystick.cc
    )

    add_executable(keystick ${KEYSTICK_SOURCES} ${${project}_HEADERS} )
    target_link_libraries(keystick nml mk mkini ${CURSES_LIBRARIES})
endif()

if(HAVE_XAW)
    set(XEMC_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/xemc.cc
    )

    add_executable(xmk ${XEMC_SOURCES} ${${project}_HEADERS} )
    target_link_libraries(xmk nml mk mkini ${XAW_LIBRARIES})
endif()

if(WITH_EMCWEB)
    #include_directories(${Boost_INCLUDE_DIRS})

    # For libnml
    #link_directories(${LIBRARY_OUTPUT_DIRECTORY})

    add_executable(emcweb ${EMCWEB_SOURCES} ${${project}_HEADERS} )
    target_link_libraries(emcweb nml mk mkini Boost::thread Boost::system pthread dl)
endif()
