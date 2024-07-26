# This file is part of Desktop App Toolkit,
# a set of libraries for developing nice desktop applications.

add_library(external_qwindowkit-main INTERFACE IMPORTED GLOBAL)
# add_library(desktop-app::external_qwindowkit-main ALIAS external-qwindowkit-main)

# # 被连接到 接口库
# add_library(external_qwindowkit-main_bundled STATIC)
# init_target(external_qwindowkit-main_bundled "(external)")


set(qwindowkit-main_loc ${third_party}/qwindowkit-main)
set(qwindowkit-main_src ${third_party}/qwindowkit-main/src)

# 核心模块
# set(Build_qwindowkit-main_core_src qwindowkit-main_src/core)

# set(Build_qwindowkit-main_core_inc qwindowkit-main_src/core)

# file(GLOB Build_qwindowkit-main_core_src "${qwindowkit-main_src}/*.cpp")
# file(GLOB Build_qwindowkit-main_core_inc "${qwindowkit-main_src}/*.h")

# file(GLOB Build_qwindowkit-main_core
#      "${SOURCE_DIR}/*.cpp"
#      "${SOURCE_DIR}/*.cc"
#      "${SOURCE_DIR}/*.c"

#  )
# message("test${qwindowkit-main_loc}")


# target_link_libraries(external_qwindowkit-main
# INTERFACE
#     external_qwindowkit-main_bundled
# )

# add_subdirectory(${qwindowkit-main_loc} build)



# project(QWKCore
#     VERSION ${QWINDOWKIT_VERSION}
#     LANGUAGES CXX
# )

set(_src
    ${qwindowkit-main_src}/core/qwkglobal.h
    ${qwindowkit-main_src}/core/qwkglobal_p.h
    ${qwindowkit-main_src}/core/windowagentbase.h
    ${qwindowkit-main_src}/core/windowagentbase_p.h
    ${qwindowkit-main_src}/core/windowagentbase.cpp
    ${qwindowkit-main_src}/core/windowitemdelegate_p.h
    ${qwindowkit-main_src}/core/windowitemdelegate.cpp
    ${qwindowkit-main_src}/core/kernel/nativeeventfilter_p.h
    ${qwindowkit-main_src}/core/kernel/nativeeventfilter.cpp
    ${qwindowkit-main_src}/core/kernel/sharedeventfilter_p.h
    ${qwindowkit-main_src}/core/kernel/sharedeventfilter.cpp
    ${qwindowkit-main_src}/core/shared/systemwindow_p.h
    ${qwindowkit-main_src}/core/contexts/abstractwindowcontext_p.h
    ${qwindowkit-main_src}/core/contexts/abstractwindowcontext.cpp
)

set(_links_private)

if(WIN32)
    list(APPEND _src
        ${qwindowkit-main_src}/core/qwindowkit_windows.h
        ${qwindowkit-main_src}/core/qwindowkit_windows.cpp
        ${qwindowkit-main_src}/core/shared/qwkwindowsextra_p.h
    )
elseif(APPLE)
else()
    list(APPEND _src
        ${qwindowkit-main_src}/core/qwindowkit_linux.h
    )
endif()

if(QWINDOWKIT_ENABLE_QT_WINDOW_CONTEXT)
    list(APPEND _src
        ${qwindowkit-main_src}/core/contexts/qtwindowcontext_p.h
        ${qwindowkit-main_src}/core/contexts/qtwindowcontext.cpp
    )
else()
    if(WIN32)
        list(APPEND _src
            ${qwindowkit-main_src}/core/contexts/win32windowcontext_p.h
            ${qwindowkit-main_src}/core/contexts/win32windowcontext.cpp
        )
        list(APPEND _links_private uxtheme)
    elseif(APPLE)
        list(APPEND _src
            ${qwindowkit-main_src}/core/contexts/cocoawindowcontext_p.h
            ${qwindowkit-main_src}/core/contexts/cocoawindowcontext.mm
        )
        list(APPEND _links_private
            "-framework Foundation"
            "-framework Cocoa"
            "-framework AppKit"
        )
    else()
        list(APPEND _src
            ${qwindowkit-main_src}/core/contexts/qtwindowcontext_p.h
            ${qwindowkit-main_src}/core/contexts/qtwindowcontext.cpp
        )
    endif()
endif()

set(_sync_include_options)

if(QWINDOWKIT_ENABLE_STYLE_AGENT)
    list(APPEND _src
        ${qwindowkit-main_src}/core/style/styleagent.h
        ${qwindowkit-main_src}/core/style/styleagent_p.h
        ${qwindowkit-main_src}/core/style/styleagent.cpp

    )

    if(WIN32)
        list(APPEND _src ${qwindowkit-main_src}/core/style/styleagent_win.cpp)
    elseif(APPLE)
        list(APPEND _src ${qwindowkit-main_src}/core/style/styleagent_mac.mm)
    else()
        list(APPEND _src ${qwindowkit-main_src}/core/style/styleagent_linux.cpp)
    endif()
else()
    list(APPEND _sync_include_options EXCLUDE "style/\\.+")
endif()


macro(qwk_add_library _target)
    # 设置 bool 变量
    set(options AUTOGEN NO_SYNC_INCLUDE NO_WIN_RC)
    # 设置一个参数
    set(oneValueArgs SYNC_INCLUDE_PREFIX PREFIX)
    # 多个参数
    set(multiValueArgs SYNC_INCLUDE_OPTIONS)
    # 解析参数  参数带有  FUNC_
    cmake_parse_arguments(FUNC "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # 如果设置了 AUTOGEN  参数
    if(FUNC_AUTOGEN)
        # moc 文件
        set(CMAKE_AUTOMOC ON)
        # uic 文件
        set(CMAKE_AUTOUIC ON)
        # rcc 文件
        set(CMAKE_AUTORCC ON)
    endif()


    if(QWINDOWKIT_BUILD_STATIC)
    # 静态库
        set(_type STATIC)
    else()
    # 动态库
        set(_type SHARED)
    endif()

    # 生成库文件 动态库
    # add_library(${_target} ${_type})
    add_library(qwindowkit-main ${_type})

    # windows 平台  没有 NO_WIN_RC 参数 库类型是 动态库
    # if(WIN32 AND NOT FUNC_NO_WIN_RC AND(${_type} STREQUAL "SHARED"))
    #     qm_add_win_rc(${_target}
    #         NAME ${QWINDOWKIT_INSTALL_NAME}
    #         DESCRIPTION ${QWINDOWKIT_PROJECT_DESCRIPTION}
    #         COPYRIGHT ${QWINDOWKIT_PROJECT_COPYRIGHT}
    #     )
    # endif()

    # 参数 PREFIX
    if(FUNC_PREFIX)
        set(_prefix_option PREFIX ${FUNC_PREFIX})
    else()
        set(_prefix_option)
    endif()

    # # Set global definitions
    # qm_export_defines(${_target} ${_prefix_option})

    # # Configure target
    # qm_configure_target(${_target} ${FUNC_UNPARSED_ARGUMENTS})

    # Add include directories
    target_include_directories(${_target} PRIVATE ${QWINDOWKIT_BUILD_INCLUDE_DIR})
    target_include_directories(${_target} PRIVATE .)

    # Library name
    if(${_target} MATCHES "^QWK(.+)")
        set(_name ${CMAKE_MATCH_1})
        set_target_properties(${_target} PROPERTIES EXPORT_NAME ${_name})
    else()
        set(_name ${_target})
    endif()

    # 生成库在
    # add_library(${QWINDOWKIT_INSTALL_NAME}::${_name} ALIAS ${_target})

    if(FUNC_SYNC_INCLUDE_PREFIX)
        set(_inc_name ${FUNC_SYNC_INCLUDE_PREFIX})
    else()
        set(_inc_name ${_target})
    endif()

    set(_install_options)

    if(QWINDOWKIT_INSTALL)
        install(TARGETS ${_target}
            EXPORT ${QWINDOWKIT_INSTALL_NAME}Targets
            RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" OPTIONAL
            LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}" OPTIONAL
            ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}" OPTIONAL
        )

        target_include_directories(${_target} PUBLIC
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${QWINDOWKIT_INSTALL_NAME}>"
        )

        set(_install_options
            INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}/${QWINDOWKIT_INSTALL_NAME}/${_inc_name}"
        )
    endif()

    if(NOT FUNC_NO_SYNC_INCLUDE)
        # Generate a standard include directory in build directory
        # qm_sync_include(. "${QWINDOWKIT_GENERATED_INCLUDE_DIR}/${_inc_name}" ${_install_options}
        #     ${FUNC_SYNC_INCLUDE_OPTIONS} FORCE
        # )
        target_include_directories(${_target} PUBLIC
            "$<BUILD_INTERFACE:${QWINDOWKIT_GENERATED_INCLUDE_DIR}>"
        )
    endif()
endmacro()



qwk_add_library(${PROJECT_NAME} AUTOGEN
    SOURCES ${_src}
    LINKS
    LINKS_PRIVATE ${_links_private}
    QT_LINKS Core Gui
    QT_INCLUDE_PRIVATE Core Gui
    INCLUDE_PRIVATE kernel contexts shared
    PREFIX QWK_CORE
    SYNC_INCLUDE_OPTIONS ${_sync_include_options}
)

#
#set_target_properties(${PROJECT_NAME} PROPERTIES
#    CXX_STANDARD 17
#    CXX_STANDARD_REQUIRED TRUE
#)

set(QWINDOWKIT_ENABLED_TARGETS ${QWINDOWKIT_ENABLED_TARGETS} ${PROJECT_NAME} PARENT_SCOPE)
set(QWINDOWKIT_ENABLED_SUBDIRECTORIES ${QWINDOWKIT_ENABLED_SUBDIRECTORIES} core PARENT_SCOPE)
