#
# Source: https://github.com/davidsansome/trochus/blob/master/cmake/FindKernelHeaders.cmake
#
# Find the kernel release, omit the arch
execute_process(
  COMMAND uname -r
  COMMAND cut "-f1" "-d-"
  OUTPUT_VARIABLE KERNEL_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

file(GLOB COMMON_HEADER_DIRS /usr/src/linux-headers-${KERNEL_VERSION}*-common)

# Find the headers
find_path(COMMON_KERNELHEADERS_DIR
  include/linux/device.h
  PATHS ${COMMON_HEADER_DIRS} /usr/src/linux-headers-${KERNEL_VERSION}-common
)

file(GLOB HEADER_DIRS /usr/src/linux-headers-${KERNEL_VERSION}*)
list(FILTER HEADER_DIRS EXCLUDE REGEX "common$")

find_path(KERNELHEADERS_DIR
  include/generated/bounds.h
  PATHS ${HEADER_DIRS} /usr/src/linux-headers-${KERNEL_RELEASE}
)

message(STATUS "Kernel release: ${KERNEL_RELEASE}")
message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}")
message(STATUS "Kernel headers (common): ${COMMON_KERNELHEADERS_DIR}")

if (KERNELHEADERS_DIR)
  set(KERNELHEADERS_INCLUDE_DIRS
    ${KERNELHEADERS_DIR}/include
    ${KERNELHEADERS_DIR}/arch/x86/include
    ${KERNELHEADERS_DIR}/arch/x86/include/generated
    ${COMMON_KERNELHEADERS_DIR}/include
    ${COMMON_KERNELHEADERS_DIR}/arch/x86/include
    ${COMMON_KERNELHEADERS_DIR}/arch/x86/include/generated
    CACHE PATH "Kernel headers include dirs"
  )
  message(STATUS "Kernel header directories: ${KERNELHEADERS_INCLUDE_DIRS}")
  set(KERNELHEADERS_FOUND 1 CACHE STRING "Set to 1 if kernel headers were found")
else (KERNELHEADERS_DIR)
  set(KERNELHEADERS_FOUND 0 CACHE STRING "Set to 1 if kernel headers were found")
endif (KERNELHEADERS_DIR)

mark_as_advanced(KERNELHEADERS_FOUND)
