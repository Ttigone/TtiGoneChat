# 有 Qt 的环境
# if (DEFINED ENV{QT})
#     set(qt_version $ENV{QT} CACHE STRING "Qt version" FORCE)
# endif()


# # 没有 Qt 环境
# if (NOT DEFINED qt_version)
#     message(FATAL_ERROR "Qt version is unknown, set `QT` enviroment variable")
# endif()

if (WIN32)
    set(qt_loc)
elseif(APPLE)

else()

endif()

# # 没有定义主版本号
if (NOT DEFINED QT_VERSION_MAJOR)
    if (NOT WIN32)
        find_package(QT NAMES Qt6 COMPONENTS Core)
    # message("TTT")
    endif()
#     if (NOT QT_FOUND)
#         find_package(QT NAMES Qt5 COMPONENTS Core)
#     endif()
#     if (NOT QT_FOUND)
#         message(FATAL_ERROR "Neither Qt6 nor Qt5 is found")
#     endif()
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Network Svg REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS Quick QuickWidgets QUIET)

if (QT_VERSION_MAJOR GREATER_EQUAL 6)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS OpenGL OpenGLWidgets REQUIRED)
endif()

if (LINUX)
    find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS DBus WaylandClient WaylandCompositor QUIET)
endif()

set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "(gen)")
set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER "(gen)")
