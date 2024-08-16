cmake_minimum_required(VERSION 3.16)
add_library(lib_storage STATIC)
add_library(desktop-app::lib_storage ALIAS lib_storage)

get_filename_component(src_loc . REALPATH)


#target_precompile_headers(lib_storage PRIVATE $<$<COMPILE_LANGUAGE:CXX,OBJCXX>:${src_loc}/storage/storage_pch.h>)
target_precompile_headers(lib_storage PRIVATE ${src_loc}/storage/storage_pch.h)
#target_precompile_headers(lib_storage PRIVATE $<$<COMPILE_LANGUAGE:CXX,OBJCXX>:${src_loc}/storage/storage_pch.h>)


target_sources(lib_storage PRIVATE 
	storage/storage_pch.h
	storage/storage_databases.h storage/storage_databases.cpp

)
target_include_directories(lib_storage
PUBLIC
  ${src_loc}
)

find_package(Qt6 REQUIRED COMPONENTS Sql) 
target_link_libraries(lib_storage PRIVATE Qt6::Sql)

target_link_libraries(lib_storage
PUBLIC
	desktop-app::lib_base
)
