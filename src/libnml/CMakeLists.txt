set (project nml)

add_subdirectory(buffer)
add_subdirectory(cms)
add_subdirectory(linklist)
add_subdirectory(nml)
add_subdirectory(rcs)
add_subdirectory(os_intf)

add_library(${project} SHARED
    $<TARGET_OBJECTS:buffer>
    $<TARGET_OBJECTS:cms>
    $<TARGET_OBJECTS:rcs>
    $<TARGET_OBJECTS:linklist>
    $<TARGET_OBJECTS:os_intf>
    $<TARGET_OBJECTS:nml_objs>
)

target_link_libraries(${project} rtapi_math)
