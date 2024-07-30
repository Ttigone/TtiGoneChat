#
# 常用组件库
#

add_library(external_qt-material STATIC)

set(qt-material_loc ${third_party}/qt-material/components)

# 源文件
file(GLOB PROJECT_SRC
    ${qt-material_loc}/*.cpp
    ${qt-material_loc}/lib/*.cpp
    ${qt-material_loc}/layout/*.cpp
)

# 头文件
file(GLOB PROJECT_INC
    ${qt-material_loc}
    ${qt-material_loc}/lib
    ${qt-material_loc}/layout
)
find_package(Qt6 REQUIRED COMPONENTS StateMachine)
target_link_libraries(external_qt-material PUBLIC external-qt Qt6::StateMachine)

target_include_directories(external_qt-material PUBLIC ${PROJECT_INC})

target_sources(external_qt-material PUBLIC ${PROJECT_SRC})

set_target_properties(external_qt-material PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)


