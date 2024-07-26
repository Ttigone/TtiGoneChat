# 解析版本号

function(desktop_app_parse_version file)
  # 遍历 file 文件, 获取的每一行保存为字符串, 存储到 lines 中
  file(STRINGS ${file} lines)
  # 遍历每一行字符串
  foreach(line ${lines})
    string(REPLACE " " ";" parts ${line})
    list(GET parts 0 name)
    if (${name} STREQUAL "AppVersionOriginal")
      list(LENGTH parts length)
      math(EXPR index "${length} - 1")
      list(GET parts ${index} version)
      break()
    endif()
  endforeach()

  
  
endfunction()
