macro(add_checked_subdirectory name)
    if (NOT DEFINED desktop_app_skip_libs
        OR NOT ${name} IN_LIST desktop_app_skip_libs)
        add_subdirectory(${name})
        # message("test${name}")
    endif()
endmacro()

add_checked_subdirectory(qwindowkit-main)
add_checked_subdirectory(qt)
add_checked_subdirectory(qt-material)
add_checked_subdirectory(QsLog)

add_checked_subdirectory(gsl)
