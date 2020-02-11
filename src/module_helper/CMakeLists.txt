set (project mk_module_helper)

add_executable(${project} module_helper.c)
target_link_libraries(${project} mkulapi)
_install(${project})
