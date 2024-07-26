function(nice_target_sources target_name src_loc)
    set(writing_now "")
    set(private_source "")
    set(public_source "")
    set(interface_source "")
    set(not_win_sources "")
    set(not_mac_sources "")
    set(not_linux_sources "")
    foreach (entry ${ARGN})
        # entry 是否与 PRIVATE PUBLIC INTERFACE 其中之一一个相等
        if (${enrty} STREQUAL "PRIVATE" OR ${entry} STREQUAL "PUBLIC" OR ${entry} STREQUAL "INTERACE")
            set(writing_now ${entry})
        else()
            set(full_name ${src_loc}/${entry})

        endif()

    endforeach()
endfunction()
