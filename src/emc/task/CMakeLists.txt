cmake_minimum_required(VERSION 3.13)
set (project task)

set(${project}_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/task.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/taskclass.hh
)

include_directories(../)

set(EMCSVR_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/emcsvr.cc
)

add_executable(mksvr ${EMCSVR_SOURCES} ${${project}_HEADERS} )
target_link_libraries(mksvr nml mk mkini rtapi_math)

install(TARGETS mksvr
    RUNTIME DESTINATION bin
)

# disabled:	emc/task/iotaskintf.cc
set(MILLTASK_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/../motion/emcmotglb.c
	${CMAKE_CURRENT_SOURCE_DIR}/../motion/usrmotintf.cc
	${CMAKE_CURRENT_SOURCE_DIR}/../motion/emcmotutil.c
	${CMAKE_CURRENT_SOURCE_DIR}/../motion/dbuf.c
	${CMAKE_CURRENT_SOURCE_DIR}/../motion/stashf.c
	${CMAKE_CURRENT_SOURCE_DIR}/emctask.cc
	${CMAKE_CURRENT_SOURCE_DIR}/emccanon.cc
	${CMAKE_CURRENT_SOURCE_DIR}/emctaskmain.cc
	${CMAKE_CURRENT_SOURCE_DIR}/taskintf.cc
	${CMAKE_CURRENT_SOURCE_DIR}/taskmodule.cc
	${CMAKE_CURRENT_SOURCE_DIR}/taskclass.cc
	${CMAKE_CURRENT_SOURCE_DIR}/backtrace.cc
)

add_executable(milltask ${MILLTASK_SOURCES} ${${project}_HEADERS} )
target_link_libraries(milltask rs274 mk nml mkini posemath mkhal pyplugin rtapi_math Boost::python27 ${PYTHON_LIBRARIES})

install(TARGETS milltask 
    RUNTIME DESTINATION bin
)
