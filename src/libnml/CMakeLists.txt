set (project libnml)

add_subdirectory(buffer)
add_subdirectory(cms)
add_subdirectory(linklist)
add_subdirectory(nml)

add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS} )
