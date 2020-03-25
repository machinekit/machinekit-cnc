set(files
    hal/lib/config_module.h
    hal/lib/hal.h
    hal/lib/hal_accessor.h
    hal/lib/hal_accessor_macros.h
    hal/lib/hal_group.h
    hal/lib/hal_internal.h
    hal/lib/hal_list.h
    hal/lib/hal_logging.h
    hal/lib/hal_object.h
    hal/lib/hal_object_selectors.h
    hal/lib/hal_parport.h
    hal/lib/hal_priv.h
    hal/lib/hal_rcomp.h
    hal/lib/hal_ring.h
    hal/lib/hal_types.h
    hal/utils/halcmd_rtapiapp.h
    libnml/inifile/inifile.h
    libnml/inifile/inifile.hh
    rtapi/multiframe.h
    rtapi/multiframe_flag.h
    rtapi/ring.h
    rtapi/rtapi.h
    rtapi/rtapi_app.h
    rtapi/rtapi_atomics.h
    rtapi/rtapi_bitops.h
    rtapi/rtapi_byteorder.h
    rtapi/rtapi_common.h
    rtapi/rtapi_ctype.h
    rtapi/rtapi_errno.h
    rtapi/rtapi_exception.h
    rtapi/rtapi_export.h
    rtapi/rtapi_global.h
    rtapi/rtapi_heap.h
    rtapi/rtapi_heap_private.h
    rtapi/rtapi_hexdump.h
    rtapi/rtapi_int.h
    rtapi/rtapi_io.h
    rtapi/rtapi_math.h
    rtapi/rtapi_math64.h
    rtapi/rtapi_pci.h
    rtapi/rtapi_shmkeys.h
    rtapi/rtapi_string.h
    rtapi/shmdrv/shmdrv.h
    rtapi/rt-preempt.h
    rtapi/rtapi_compat.h
    rtapi/triple-buffer.h
    rtapi/xenomai.h
    machinetalk/protobuf/canon.npb.h
    machinetalk/protobuf/canon.pb.h
    machinetalk/protobuf/config.npb.h
    machinetalk/protobuf/config.pb.h
    machinetalk/protobuf/emcclass.npb.h
    machinetalk/protobuf/emcclass.pb.h
    machinetalk/protobuf/firmware.npb.h
    machinetalk/protobuf/firmware.pb.h
    machinetalk/protobuf/jplan.npb.h
    machinetalk/protobuf/jplan.pb.h
    machinetalk/protobuf/log.npb.h
    machinetalk/protobuf/log.pb.h
    machinetalk/protobuf/message.npb.h
    machinetalk/protobuf/message.pb.h
    machinetalk/protobuf/motcmds.npb.h
    machinetalk/protobuf/motcmds.pb.h
    machinetalk/protobuf/nanopb.npb.h
    machinetalk/protobuf/nanopb.pb.h
    machinetalk/protobuf/object.npb.h
    machinetalk/protobuf/object.pb.h
    machinetalk/protobuf/preview.npb.h
    machinetalk/protobuf/preview.pb.h
    machinetalk/protobuf/ros.npb.h
    machinetalk/protobuf/ros.pb.h
    machinetalk/protobuf/rtapi_message.npb.h
    machinetalk/protobuf/rtapi_message.pb.h
    machinetalk/protobuf/rtapicommand.npb.h
    machinetalk/protobuf/rtapicommand.pb.h
    machinetalk/protobuf/status.npb.h
    machinetalk/protobuf/status.pb.h
    machinetalk/protobuf/task.npb.h
    machinetalk/protobuf/task.pb.h
    machinetalk/protobuf/test.npb.h
    machinetalk/protobuf/test.pb.h
    machinetalk/protobuf/types.npb.h
    machinetalk/protobuf/types.pb.h
    machinetalk/protobuf/value.npb.h
    machinetalk/protobuf/value.pb.h)


execute_process(COMMAND ${CMAKE_COMMAND} -E 
                    make_directory ${INCLUDE_DIR}/protobuf)

unset(_headers)
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
                        ${CMAKE_SOURCE_DIR}/src/${file} ${INCLUDE_DIR}/${name})
    set(_headers ${_headers} ${INCLUDE_DIR}/${name})
endforeach()

foreach(file pb.h pb_decode.h pb_encode.h)
    execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
                        ${CMAKE_SOURCE_DIR}/src/machinetalk/nanopb/${file}
                        ${INCLUDE_DIR}/protobuf/${file})
    set(_headers ${_headers} ${INCLUDE_DIR}/protobuf/${file})
endforeach()

if(WITH_USERMODE_PCI)
    set(mesa_files
        hal/drivers/mesa-hostmot2/bitfile.h
        hal/drivers/mesa-hostmot2/hm2_pci.h
        hal/drivers/mesa-hostmot2/hostmot2.h
        hal/drivers/mesa-hostmot2/hm2_7i43.h
        hal/drivers/mesa-hostmot2/hm2_soc_ol.h
        hal/drivers/mesa-hostmot2/lbp16.h
        hal/drivers/mesa-hostmot2/hm2_7i90.h
        hal/drivers/mesa-hostmot2/hm2_test.h
        hal/drivers/mesa-hostmot2/sserial.h
        hal/drivers/mesa-hostmot2/hm2_eth.h
        hal/drivers/mesa-hostmot2/hostmot2-lowlevel.h)

    execute_process(COMMAND ${CMAKE_COMMAND} -E 
                        make_directory ${INCLUDE_DIR}/mesa
                    COMMAND ${CMAKE_COMMAND} -E 
                        make_directory ${INCLUDE_DIR}/userpci)

    foreach(file ${mesa_files})
        get_filename_component(name ${file} NAME)
        execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
                            ${CMAKE_SOURCE_DIR}/src/${file} 
                            ${INCLUDE_DIR}/mesa/${name})
        set(_headers ${_headers} ${INCLUDE_DIR}/mesa/${name})
    endforeach()

    set(uspci_files
        rtapi/userpci/device.h
        rtapi/userpci/firmware.h
        rtapi/userpci/gfp.h
        rtapi/userpci/list.h
        rtapi/userpci/module.h
        rtapi/userpci/slab.h
        rtapi/userpci/string.h)

    foreach(file ${uspci_files})
        get_filename_component(name ${file} NAME)
        execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
                            ${CMAKE_SOURCE_DIR}/src/${file} 
                            ${INCLUDE_DIR}/userpci/${name})
        set(_headers ${_headers} ${INCLUDE_DIR}/userpci/${name})
    endforeach()
endif()
