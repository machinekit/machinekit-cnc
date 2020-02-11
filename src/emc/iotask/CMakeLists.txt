cmake_minimum_required(VERSION 2.8)
set (project iotask)

include_directories(../)

add_executable(io ioControl.cc)
target_link_libraries(io nml mkhal mkini mk)

add_executable(iov2 ioControl_v2.cc )
target_link_libraries(iov2 nml mkhal mkini mk)
