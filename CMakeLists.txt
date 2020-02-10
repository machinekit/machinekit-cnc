cmake_minimum_required(VERSION 3.0.2)

project(machinekit-cnc)
set(MK_VERSION_MAJOR 0)
set(MK_VERSION_MINOR 3)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(PROJECT_PYTHON_DIR ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/python)
set(PROJECT_LIBEXEC_DIR ${PROJECT_BINARY_DIR}/lib/machinekit)
set(PROJECT_LIB_DIR ${PROJECT_BINARY_DIR}/lib)
set(PROJECT_SYSCONF_DIR ${PROJECT_BINARY_DIR}/etc)
set(PROJECT_BIN_DIR ${PROJECT_BINARY_DIR}/bin)
set(PROJECT_DATA_DIR ${PROJECT_BINARY_DIR}/share/machinekit)
set(PROJECT_LOCALE_DIR ${PROJECT_DATA_DIR}/locale)
set(PROJECT_MAN_DIR ${PROJECT_BINARY_DIR}/man)
set(INCLUDE_DIR ${PROJECT_BINARY_DIR}/include)
set(SCRIPTS_DIR ${CMAKE_SOURCE_DIR}/scripts)
set(PROJECT_TCL_DIR ${PROJECT_BINARY_DIR}/lib/tcltk)

if("${CMAKE_INSTALL_PREFIX}" STREQUAL "/usr")
    set(INSTALL_SYSCONF_DIR "/etc")
else()
    set(INSTALL_SYSCONF_DIR "${CMAKE_INSTALL_PREFIX}/etc")
endif()

include(Options)
include(Macros)

include_directories(${INCLUDE_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(scripts)

## !!! WARNING These are the defines that were defined regardless of an option.
## !!! Or the script couldn't match them. Match them accordingly, delete them or keep them
file(APPEND ${CONFIG_H} "/* zeroMQ czmq library available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_CZMQ  \n\n ")

file(APPEND ${CONFIG_H} "/* protobuf available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_PROTOBUF  \n\n ")

file(APPEND ${CONFIG_H} "/* jansson JSON C bindings available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_JANSSON  \n\n ")

file(APPEND ${CONFIG_H} "/* uriparser library available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_URIPARSER  \n\n ")

file(APPEND ${CONFIG_H} "/* libwebsockets library available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_LWS  \n\n ")

file(APPEND ${CONFIG_H} "/* libssl library available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_SSL  \n\n ")

file(APPEND ${CONFIG_H} "/* uuid library available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_UUID  \n\n ")

file(APPEND ${CONFIG_H} "/* avahi mDNS client library available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_AVAHI  \n\n ")


file(APPEND ${CONFIG_H} "/* Build POSIX threads */\n")
file(APPEND ${CONFIG_H} "#define [HAVE_POSIX_THREADS]  \n\n ")

file(APPEND ${CONFIG_H} "/* Build RT_PREEMPT threads */\n")
file(APPEND ${CONFIG_H} "#define [HAVE_RT_PREEMPT_THREADS]  \n\n ")

file(APPEND ${CONFIG_H} "/* Xenomai v.2 */\n")
file(APPEND ${CONFIG_H} "#define [XENOMAI_V2]  \n\n ")

file(APPEND ${CONFIG_H} "/* Build Xenomai userland threads */\n")
file(APPEND ${CONFIG_H} "#define [HAVE_XENOMAI_THREADS]  \n\n ")

file(APPEND ${CONFIG_H} "/* Build Xenomai kernel threads */\n")
file(APPEND ${CONFIG_H} "#define [HAVE_XENOMAI_KERNEL_THREADS]  \n\n ")

file(APPEND ${CONFIG_H} "/* Build RTAI threads */\n")
file(APPEND ${CONFIG_H} "#define [HAVE_RTAI_KERNEL_THREADS]  \n\n ")

file(APPEND ${CONFIG_H} "/* Define to 1 if asm/msr.h is usable and defines rdtscll */\n")
file(APPEND ${CONFIG_H} "#define [MSR_H_USABLE]  \n\n ")

file(APPEND ${CONFIG_H} "/* Define to 1 if linux/hidraw.h is usable and defines HIDIOCGRAWINFO */\n")
file(APPEND ${CONFIG_H} "#define [HIDRAW_H_USABLE]  \n\n ")

file(APPEND ${CONFIG_H} "/* if lttng-ust support is available */\n")
file(APPEND ${CONFIG_H} "#define [HAVE_LTTNG_UST]  \n\n ")

file(APPEND ${CONFIG_H} "/* Define to 1 if you have the 'readline' library -lreadline and required headers */\n")
file(APPEND ${CONFIG_H} "#define [HAVE_READLINE]  \n\n ")

file(APPEND ${CONFIG_H} "/* libbacktrace available */\n")
file(APPEND ${CONFIG_H} "#define HAVE_LIBBACKTRACE  \n\n ")

# Setting the include directory for the application to find config.h
include_directories( ${CMAKE_BINARY_DIR} )
# Since we have created a config.h add a global define for it
add_definitions( "-DHAVE_CONFIG_H" )
