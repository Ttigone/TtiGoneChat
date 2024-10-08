﻿cmake_minimum_required(VERSION 3.16)

project(TtiGoneChat VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

 #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=leak -fno-omit-frame-pointer")

 
#if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=leak -fno-omit-frame-pointer")
#elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zi /fsanitize=address /Oy- /analyze")
#endif()


set(PROJECT_SOURCES
        src/settings.h src/settings.cpp

        src/ui/chat/message_bubble.h src/ui/chat/message_bubble.cpp
        src/ui/chat/chat_item.h src/ui/chat/chat_item.cpp
        src/ui/widgets/self_window.h src/ui/widgets/self_window.cpp
        src/ui/widgets/windowbar.h src/ui/widgets/windowbar.cpp
        src/ui/widgets/windowbar_p.h
        src/ui/widgets/windowbar_button.h src/ui/widgets/windowbar_button.cpp
        src/ui/widgets/windowbar_button_p.h
        src/ui/set_style.h src/ui/set_style.cpp
        src/ui/widgets/fields/auto_complete_input_field.h src/ui/widgets/fields/auto_complete_input_field.cpp
        src/ui/widgets/fields/completer_field.h src/ui/widgets/fields/completer_field.cpp

        src/local/account.h src/local/account.cpp
        src/local/domain.h src/local/domain.cpp
        src/local/user_account.h src/local/user_account.cpp

        src/core/launcher.h src/core/launcher.cpp
        src/core/sandbox.h src/core/sandbox.cpp
        src/core/base_intergration.h src/core/base_intergration.cpp
        src/core/application.h src/core/application.cpp
        src/core/settings.h src/core/settings.cpp
        src/core/tray.h src/core/tray.cpp

        src/window/controller.h src/window/controller.cpp
        src/window/mainwindow.h src/window/mainwindow.cpp
        src/window/session_controller.h src/window/session_controller.cpp
        src/window/sidebar.h src/window/sidebar.cpp
        src/window/window_media_preview.h src/window/window_media_preview.cpp
        src/window/window_session_menu.h src/window/window_session_menu.cpp
        src/window/window_stack.h src/window/window_stack.cpp

        src/window/themes/window_theme.h src/window/themes/window_theme.cpp

        src/main.cpp
        src/stdafx.h
        src/config.h src/config.cpp
        src/main_window.h src/main_window.cpp
        src/main_widget.h src/main_widget.cpp

        src/lang/lang_translator.h src/lang/lang_translator.cpp

        src/layout/horizontal_layout.h src/layout/horizontal_layout.cpp
        src/layout/vertical_layout.h src/layout/vertical_layout.cpp


        src/storage/local_storage.h src/storage/local_storage.cpp
        src/storage/session_storage.h src/storage/session_storage.cpp
        src/storage/history_storage.h src/storage/history_storage.cpp

        src/data/data_talk.h src/data/data_talk.cpp
        src/data/data_talk_id.h src/data/data_talk_id.cpp
        src/data/data_msg_id.h src/data/data_msg_id.cpp
        src/data/data_history_message.h src/data/data_history_message.cpp
        src/data/data_session_label.h src/data/data_session_label.cpp
        src/data/data_talk_init.h src/data/data_talk_init.cpp
        src/data/data_document.h src/data/data_document.cpp

        src/settings/settings_type.h
        src/settings/common.h src/settings/common.cpp
        src/settings/common_session.h src/settings/common_session.cpp

        src/proto/sender.h
        src/proto/config.h src/proto/config.cpp
        src/proto/instance.h src/proto/instance.cpp

        src/media/view/open_common.h
        src/media/view/overlay_widget.h src/media/view/overlay_widget.cpp


        src/history/history_widget.h src/history/history_widget.cpp
)

# 仅拷贝
configure_file(src/window/window_config.json window_config.json COPYONLY)
configure_file(src/settings/databases/config.ini config.ini COPYONLY)


get_filename_component(src_loc src REALPATH)
get_filename_component(res_loc res REALPATH)


if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)


    set(RES_QRC
            res/TtigoneChat.qrc
            res/ui/icons/chat/T_Chat.qrc
    )

    qt_add_executable(TtiGoneChat
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            # res/TtigoneChat.qrc
            ${RES_QRC}

            # lib_base/base/basic_types.h
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET TtiGoneChat APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
    # else()
    #     if(ANDROID)
    #         add_library(TtiGoneChat SHARED
    #             ${PROJECT_SOURCES}
    #         )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    # else()
    #     add_executable(TtiGoneChat
    #         ${PROJECT_SOURCES}
    #     )
    # endif()
endif ()

# target_sources(TtiGoneChat src_qrc)

include_directories(src)


add_subdirectory(lib_base)
add_subdirectory(lib_ui)
add_subdirectory(lib_storage)


include_directories(${third_party})


# target_link_libraries(TtiGoneChat PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


target_link_libraries(TtiGoneChat
        PRIVATE
        desktop-app::lib_base
        desktop-app::lib_ui
        desktop-app::lib_storage
        # qt-material
        # desktop-app::external_qt-material
        external_qt-material
        QWindowKit::Widgets
        QsLog
        #external_qwindowkit-main
)

target_precompile_headers(TtiGoneChat PRIVATE $<$<COMPILE_LANGUAGE:CXX,OBJCXX>:${src_loc}/stdafx.h>)

install(TARGETS TtiGoneChat DESTINATION bin)

install(FILES src/settings/databases/config.ini DESTINATION etc)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
# if(${QT_VERSION} VERSION_LESS 6.1.0)
#   set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TtiGoneChat)
# endif()
# set_target_properties(TtiGoneChat PROPERTIES
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# include(GNUInstallDirs)
# install(TARGETS TtiGoneChat
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(TtiGoneChat)
# endif()
