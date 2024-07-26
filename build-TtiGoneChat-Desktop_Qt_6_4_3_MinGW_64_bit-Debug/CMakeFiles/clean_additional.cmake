# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "TtiGoneChat\\CMakeFiles\\TtiGoneChat_autogen.dir\\AutogenUsed.txt"
  "TtiGoneChat\\CMakeFiles\\TtiGoneChat_autogen.dir\\ParseCache.txt"
  "TtiGoneChat\\TtiGoneChat_autogen"
  "TtiGoneChat\\lib_base\\CMakeFiles\\lib_base_autogen.dir\\AutogenUsed.txt"
  "TtiGoneChat\\lib_base\\CMakeFiles\\lib_base_autogen.dir\\ParseCache.txt"
  "TtiGoneChat\\lib_base\\lib_base_autogen"
  "cmake\\external\\qwindowkit-main\\CMakeFiles\\qwindowkit-main_autogen.dir\\AutogenUsed.txt"
  "cmake\\external\\qwindowkit-main\\CMakeFiles\\qwindowkit-main_autogen.dir\\ParseCache.txt"
  "cmake\\external\\qwindowkit-main\\qwindowkit-main_autogen"
  )
endif()
