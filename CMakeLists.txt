set(project_langs C CXX)

cmake_minimum_required(VERSION 3.16)

project(TtiGoneChat
    LANGUAGES ${project_langs}
    DESCRIPTION "Official TtiGoneChat Desktop messenger"
    HOMEPAGE_URL "none"
)

# 第三方 src 库 
get_filename_component(third_party "TtiGoneChat/3rdparty" REALPATH)


include(cmake/version.cmake)

# 自定义的 cmake 函数文件  全局的 CMakeLists.txt 都可以使用
include(cmake/init_target.cmake)
include(cmake/nice_target_sources.cmake)

include(cmake/external/qt/package.cmake)



set(desktop_app_skip_libs
    glibmm
    variant
)

add_subdirectory(cmake)
add_subdirectory(TtiGoneChat)
