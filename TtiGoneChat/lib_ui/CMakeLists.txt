add_library(lib_ui STATIC)
add_library(desktop-app::lib_ui ALIAS lib_ui)

get_filename_component(src_loc . REALPATH)



set_target_properties(lib_ui PROPERTIES AUTOMOC ON)

# 禁用 uic, 避免 ui_pch.h 被识别为 .ui 文件 
set_target_properties(lib_ui PROPERTIES AUTOUIC OFF)


# 预编译头文件
target_precompile_headers(lib_ui PRIVATE $<$<COMPILE_LANGUAGE:CXX,OBJCXX>:${src_loc}/ui/ui_pch.h>)

target_sources(lib_ui PRIVATE 
  ui/ui_pch.h
  ui/style/style_font.h ui/style/style_font.cpp
)

target_include_directories(lib_ui
PUBLIC
  ${src_loc}
)


target_link_libraries(lib_ui
PUBLIC
	desktop-app::lib_base
)


