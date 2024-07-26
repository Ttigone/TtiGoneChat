# add_library(qt-material GLOBAL)
# add_library(external_qt-material INTERFACE IMPORTED GLOBAL)
# add_library(external_qt-material OBJECT)
add_library(external_qt-material STATIC)
# add_library(desktop-app::external_qt-material ALIAS external_qt-material)

# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)

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


# 生成动态库
# add_library(qt-material SHARED)
# add_library(desktop-app::external-qt-material ALIAS qt-material)

find_package(Qt6 REQUIRED COMPONENTS StateMachine)
# target_link_libraries(qt-material PRIVATE external-qt Qt6::StateMachine)
target_link_libraries(external_qt-material PUBLIC external-qt Qt6::StateMachine)

# target_include_directories(qt-material PRIVATE ${PROJECT_INC})
target_include_directories(external_qt-material PUBLIC ${PROJECT_INC})

# target_sources(qt-material PRIVATE ${PROJECT_SRC})
target_sources(external_qt-material PUBLIC ${PROJECT_SRC})

# set_target_properties(qt-material PROPERTIES
set_target_properties(external_qt-material PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)


