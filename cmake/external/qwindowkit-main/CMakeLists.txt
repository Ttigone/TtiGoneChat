# This file is part of Desktop App Toolkit,
# a set of libraries for developing nice desktop applications.

#add_library(external_qwindowkit-main INTERFACE IMPORTED GLOBAL)
# add_library(desktop-app::external_qwindowkit-main ALIAS external-qwindowkit-main)

# # 被连接到 接口库
# add_library(external_qwindowkit-main_bundled STATIC)
# init_target(external_qwindowkit-main_bundled "(external)")



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

#message (${CMAKE_BINARY_DIR})
add_subdirectory(${third_party}/qwindowkit-main ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/third)


