add_library(lib_base STATIC)
add_library(desktop-app::lib_base ALIAS lib_base)

get_filename_component(src_loc . REALPATH)

target_precompile_headers(lib_base PRIVATE $<$<COMPILE_LANGUAGE:CXX,OBJCXX>:${src_loc}/base/basic_pch.h>)

target_sources(lib_base PRIVATE 
  base/basic_pch.h
  base/basic_types.h
  base/integration.h base/integration.cpp

  base/invoke_queued.h
  base/timer.h base/timer.cpp
)

target_include_directories(lib_base
PUBLIC
  ${src_loc}
)

target_link_libraries(lib_base
PUBLIC
    external-qt
)




