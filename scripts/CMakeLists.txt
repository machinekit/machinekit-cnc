# TODO: replace all EMC2xx variables

set(REALTIME ${PROJECT_BIN_DIR}/realtime)
set(EMC2_BIN_DIR ${PROJECT_BIN_DIR})
set(EMC2_RTLIB_DIR ${PROJECT_LIBEXEC_DIR})
set(prefix ${PROJECT_BINARY_DIR})
set(exec_prefix ${PROJECT_BINARY_DIR})
set(EMC2_SYSTEM_CONFIG_DIR ${PROJECT_SYSCONF_DIR}/machinekit)
set(EMC2_LIBEXEC_DIR ${PROJECT_LIBEXEC_DIR})
set(EMC2_TCL_LIB_DIR ${PROJECT_TCL_DIR})

set(TCLSH ${TCL_TCLSH})

set(RUN_IN_PLACE "yes")
string(TIMESTAMP DATE UTC)
set(configure_input "built with cmake")

string(REPLACE ";" " " _BUILD_THREAD_FLAVORS "${BUILD_THREAD_FLAVORS}")
#configure_file("${CMAKE_SOURCE_DIR}/src/Makefile.in" "${PROJECT_DATA_DIR}/Makefile.modinc" @ONLY)

# create exec
foreach(build_docker build_source_package fix-tp-loading g1-to-g23 gcode-to-ngc get-git-sha get-version-from-git githelper.sh latency-histogram latency-plot latency-test latency-test-atom linuxcnc_info machinekit torture.py)
    file(COPY ${CMAKE_CURRENT_BINARY_DIR}/${tool}
        DESTINATION ${PROJECT_BIN_DIR}
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ
        GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endforeach()

# create files for installation
set(PROJECT_SYSCONF_DIR "${INSTALL_SYSCONF_DIR}")
set(PROJECT_LIBEXEC_DIR "${CMAKE_INSTALL_PREFIX}/lib/machinekit")
set(PROJECT_BINARY_DIR "${CMAKE_INSTALL_PREFIX}")
set(PROJECT_BIN_DIR "${CMAKE_INSTALL_PREFIX}/bin")
set(PROJECT_DATA_DIR "${CMAKE_INSTALL_PREFIX}/share/machinekit")
set(INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/include/machinekit")
set(PROJECT_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib")

set(REALTIME ${PROJECT_BIN_DIR}/realtime)
set(EMC2_BIN_DIR ${PROJECT_BIN_DIR})
set(EMC2_RTLIB_DIR ${PROJECT_LIBEXEC_DIR})
set(prefix ${PROJECT_BINARY_DIR})
set(exec_prefix ${PROJECT_BINARY_DIR})
set(EMC2_SYSTEM_CONFIG_DIR ${PROJECT_SYSCONF_DIR}/machinekit)
set(EMC2_LIBEXEC_DIR ${PROJECT_LIBEXEC_DIR})
set(EMC2_TCL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib/tcltk/machinekit")

set(RUN_IN_PLACE "no")

configure_file("check-build-vs-configure-sha.in" "check-build-vs-configure-sha.dist" @ONLY)
configure_file("linuxcnc.in" "linuxcnc.dist" @ONLY)
configure_file("linuxcncmkdesktop.in" "linuxcncmkdesktop.dist" @ONLY)

#configure_file("${CMAKE_SOURCE_DIR}/src/Makefile.in" "Makefile.modinc.dist" @ONLY)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/check-build-vs-configure-sha.dist
    DESTINATION bin
    RENAME check-build-vs-configure-sha)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/linuxcnc.dist
    DESTINATION bin
    RENAME linuxcnc)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/linuxcncmkdesktop.dist
    DESTINATION bin
    RENAME linuxcncmkdesktop)
