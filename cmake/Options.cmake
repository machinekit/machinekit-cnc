# Options

cmake_minimum_required(VERSION 2.8)

# Option to build asciidoc documentation
option( WITH_DOCUMENTATION "Build asciidoc documentation" OFF )

# Option to build unstable development code
option( WITH_DEV "Build unstable development code" OFF )

# Option to hardware drivers
option( WITH_DRIVERS "Build the hardware drivers" ON )

# Option to build the emcweb interface
option( WITH_EMCWEB "Build the emcweb interface" OFF )

# Option to build included programming examples
option( WITH_EXAMPLES "Build included programming examples" ON )

# Option to enable the parts of Machinekit that depend on GTK
option( WITH_GTK "Enable the parts of Machinekit that depend on GTK" ON )

# Option to not use NLS
option( WITH_NLS "Enable NLS" ON )

# Option to enable NML-using parts
option( WITH_NML "Enable NML" ON )

# Option to build hal_parport using the ppdev ioctl instead of inb/outb
option( WITH_PORTABLE_PARPORT "Build hal_parport using the ppdev ioctl instead of inb/outb" OFF )

# Option to build Javascript bindings based on https://github.com/dcodeIO/ProtoBuf.js/wiki
option( WITH_PROTO_JS "Build Javascript bindings based on https://github.com/dcodeIO/ProtoBuf.js/wiki" ON )

# Option to enable python-pydot graphing
option( WITH_PYDOT "Enable python-pydot graphing" ON )

# Option to enable the parts of Machinekit that depend on Python
option( WITH_PYTHON "Enable the parts of Machinekit that depend on Python" ON )

# Option to enable remote zeroMQ services
option( WITH_REMOTE "Enable remote zeroMQ services" OFF )

# Option to use the common shared memory driver kernel module
option( WITH_SHMDRV "Use the common shared memory driver kernel module" OFF )

# Option to build PCI drivers with usermode PCI support
option( WITH_USERMODE_PCI "Build PCI drivers with usermode PCI support" ON )

# Option to enable webtalk
option( WITH_WEBTALK "Enable webtalk" ON )

option( WITH_RUN_IN_PLACE "Enable run-in-place (RIP)" OFF )

option(WITH_PC "Build for PC platform (default)" ON)
option(WITH_BEAGLEBONE "Build for Beaglebone platform" OFF)
option(WITH_CHIP "Build for Chip platform" OFF)
option(WITH_H3 "Build for H3 SoC platform" OFF)
option(WITH_RASPBERRY "Build for Raspberry" OFF)
option(WITH_SOCFPGA "Build for Socfpga platform" OFF)
option(WITH_ZEDBOARD "Build for Zedboard platform" OFF)

if(WITH_PC)
    set(TARGET_PLATFORM_PC 1)
elseif(WITH_BEAGLEBONE)
    set(TARGET_PLATFORM_BEAGLEBONE 1)
elseif(WITH_CHIP)
    set(TARGET_PLATFORM_CHIP 1)
elseif(WITH_H3)
    set(TARGET_PLATFORM_H3 1)
elseif(WITH_RASPBERRY)
    set(TARGET_PLATFORM_RASPBERRY 1)
elseif(WITH_SOCFPGA)
    set(TARGET_PLATFORM_SOCFPGA 1)
elseif(WITH_ZEDBOARD)
    set(TARGET_PLATFORM_ZEDBOARD 1)
endif()

option(WITH_POSIX "Build with POSIX thread support" ON)
option(WITH_RT_PREEMPT "Build with RT_PREEMPT thread support" OFF)
option(WITH_XENOMAI "Build with Xenomai userland thread support" OFF)
option(WITH_XENOMAI_KERNEL "Build Xenomai kernel thread support" OFF)
option(WITH_RTAI_KERNEL "Build RTAI thread support" OFF)

if(WITH_RT_PREEMPT)
    set(HAVE_RT_PREEMPT_THREADS 1)
    add_definitions(-DRTAPI)
    set(BUILD_THREAD_FLAVORS rt_preempt)
endif()

if(WITH_POSIX)
    set(HAVE_POSIX_THREADS 1)
    add_definitions(-DULAPI)
    set(BUILD_THREAD_FLAVORS ${BUILD_THREAD_FLAVORS} posix)
endif()

find_program(XENO_CONFIG xeno-config)
if(NOT XENO_CONFIG OR NOT WITH_XENOMAI)
    message(STATUS "xenomai flavor disabled")
    set(XENOMAI_SKIN native)
else()
    set(BUILD_THREAD_FLAVORS ${BUILD_THREAD_FLAVORS} xenomai)
    set(HAVE_XENOMAI_THREADS 1)
    execute_process(COMMAND ${XENO_CONFIG} --version
            OUTPUT_VARIABLE XENO_VERSION
            OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(XENO_VERSION MATCHES "^2.*")
        set(XENOMAI_SKIN native)
        set(XENOMAI_V2 1)
    else()
        set(XENOMAI_SKIN alchemy)
    endif()
    execute_process(COMMAND ${XENO_CONFIG} --skin ${XENOMAI_SKIN} --cflags
            OUTPUT_VARIABLE XENO_CFLAGS
            OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(COMMAND ${XENO_CONFIG} --skin ${XENOMAI_SKIN} --ldflags
            OUTPUT_VARIABLE XENO_LDFLAGS
            OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

set(RTAPI_POSIX_ID 0)
set(RTAPI_POSIX_NAME "posix")
set(POSIX_THREADS_SOURCE "rt-preempt.c")
set(POSIX_THREADS_RTFLAGS "-pthread")
set(POSIX_THREADS_LDFLAGS "-lpthread -lrt")
set(RTAPI_RT_PREEMPT_ID 1)
set(RTAPI_RT_PREEMPT_NAME "rt-preempt")
set(RT_PREEMPT_THREADS_SOURCE "rt-preempt.c")
set(RT_PREEMPT_THREADS_RTFLAGS "-pthread")
set(RT_PREEMPT_THREADS_LDFLAGS "-lpthread -lrt")
set(RTAPI_XENOMAI_ID 2)
set(RTAPI_XENOMAI_NAME "xenomai")
set(XENOMAI_THREADS_SOURCE "xenomai.c")
set(XENOMAI_THREADS_RTFLAGS "${XENO_CFLAGS}")
set(XENOMAI_THREADS_LDFLAGS "${XENO_LDFLAGS}")
set(RTAPI_XENOMAI_KERNEL_ID 3)
set(RTAPI_XENOMAI_KERNEL_NAME "xenomai-kernel")
set(RTAPI_RTAI_KERNEL_ID 4)
set(RTAPI_RTAI_KERNEL_NAME "rtai-kernel")

if( WITH_DOCUMENTATION )
    message(" DOCUMENTATION Enabled")
    set(BUILD_DOCUMENTATION 1)
endif( WITH_DOCUMENTATION )
if( WITH_DEV )
    message(" DEV Enabled")
    set(BUILD_DEV 1)
endif( WITH_DEV )
if( WITH_DRIVERS )
    message(" DRIVERS Enabled")
    set(BUILD_DRIVERS 1)
endif( WITH_DRIVERS )
if( WITH_EMCWEB )
    message(" EMCWEB Enabled")
    set(BUILD_EMCWEB 1)
endif( WITH_EMCWEB )
if( WITH_EXAMPLES )
    message(" EXAMPLES Enabled")
    set(BUILD_EXAMPLES 1)
endif( WITH_EXAMPLES )
if( WITH_GTK )
    message(" GTK Enabled")
    set(HAVE_GTK 1)
endif( WITH_GTK )
if( WITH_NLS )
    message(" NLS Enabled")
    set(HAVE_NLS 1)
endif( WITH_NLS )
if( WITH_NML )
    message(" NML Enabled")
    set(BUILD_NMLDEP 1)
endif( WITH_NML )
if( WITH_PORTABLE_PARPORT )
    message(" PORTABLE_PARPORT Enabled")
    set(USE_PORTABLE_PARPORT_IO 1)
endif( WITH_PORTABLE_PARPORT )
if( WITH_PROTO_JS )
    message(" PROTO_JS Enabled")
    set(HAVE_PROTO_JS 1)
endif( WITH_PROTO_JS )
if( WITH_PYDOT )
    message(" PYDOT Enabled")
endif( WITH_PYDOT )
if( WITH_PYTHON )
    message(" PYTHON Enabled")
endif( WITH_PYTHON )
if( WITH_REMOTE )
    message(" REMOTE Enabled")
endif( WITH_REMOTE )
if( WITH_SHMDRV )
    message(" SHMDRV Enabled")
    set(USE_SHMDRV 1)
endif( WITH_SHMDRV )
if( WITH_USERMODE_PCI )
    message(" USERMODE_PCI Enabled")
    set(USERMODE_PCI 1)
endif( WITH_USERMODE_PCI )
if( WITH_WEBTALK )
    message(" WEBTALK Enabled")
    set(HAVE_WEBTALK)
endif( WITH_WEBTALK )

if (WITH_RUN_IN_PLACE)
    add_definitions(-DRUN_IN_PLACE=yes)
    set(EMC2_HOME ${PROJECT_SOURCE_DIR})
    add_definitions(-DEMC2_HOME="${EMC2_HOME}")
    add_definitions(-DDEFAULT_NMLFILE="${EMC2_HOME}/configs/common/linuxcnc.nml")
    add_definitions(-DDEFAULT_TOOLTABLE="${EMC2_HOME}/configs/sim/sim.tbl")
    add_definitions(-DEMC2_NCFILES_DIR="${EMC2_HOME}/nc_files")
else()
    add_definitions(-DRUN_IN_PLACE=no)
    set(EMC2_HOME ${CMAKE_INSTALLATION_PREFIX})
    add_definitions(-DDEFAULT_NMLFILE="${EMC2_HOME}/share/common/linuxcnc.nml")
    add_definitions(-DEMC2_DEFAULT_TOOLTABLE="")
    add_definitions(-DEMC2_HOME="${EMC2_HOME}")
    add_definitions(-DEMC2_NCFILES_DIR="${EMC2_HOME}/share/linuxcnc/ncfiles")
endif()

set(USERPREIFX ${CMAKE_INSTALLATION_PREFIX})
