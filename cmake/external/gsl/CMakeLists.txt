add_library(external_gsl INTERFACE IMPORTED GLOBAL)
add_library(desktop-app::external_gsl ALIAS external_gsl)

if (NOT EXISTS ${third_party}/GSL/include)
    message(FATAL_ERROR "Guidelines Support Library is not found")
endif()

target_include_directories(external_gsl SYSTEM
INTERFACE
    ${third_party}/GSL/include
)

