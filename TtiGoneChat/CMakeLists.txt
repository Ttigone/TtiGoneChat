cmake_minimum_required(VERSION 3.5)

project(TtiGoneChat VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(PROJECT_SOURCES
    src/settings.h src/settings.cpp

    src/ui/chat/message_bubble.h src/ui/chat/message_bubble.cpp
    src/ui/widgets/fields/auto_complete_input_field.h src/ui/widgets/fields/auto_complete_input_field.cpp
    src/ui/widgets/mb_window.h src/ui/widgets/mb_window.cpp
    src/ui/widgets/windowbar.h src/ui/widgets/windowbar.cpp
    src/ui/widgets/windowbar_p.h 
    src/ui/widgets/button.h src/ui/widgets/button.cpp
    src/ui/widgets/button_p.h 
    src/ui/set_style.h src/ui/set_style.cpp
    src/ui/controls/conner_button.h src/ui/controls/conner_button.cpp

    src/local/account.h src/local/account.cpp
    src/local/domain.h src/local/domain.cpp

    src/core/launcher.h src/core/launcher.cpp
    src/core/sandbox.h src/core/sandbox.cpp
    src/core/base_intergration.h src/core/base_intergration.cpp
    src/core/application.h src/core/application.cpp
    src/core/settings.h src/core/settings.cpp
    src/core/tray.h src/core/tray.cpp

    src/window/launcher.h src/window/launcher.cpp
    src/window/controller.h src/window/controller.cpp
    src/window/mainwindow.h src/window/mainwindow.cpp
    src/window/session_controller.h src/window/session_controller.cpp
    src/window/sidebar.h src/window/sidebar.cpp

    src/window/themes/window_theme.h src/window/themes/window_theme.cpp

    src/main.cpp
    #src/app.h src/app.cpp
    src/stdafx.h
    src/config.h src/config.cpp
    src/main_window.h src/main_window.cpp
    src/main_widget.h src/main_widget.cpp

    src/lang/lang_translator.h src/lang/lang_translator.cpp


    src/storage/local_storage.h src/storage/local_storage.cpp

    src/data/data_talk.h  src/data/data_talk.cpp
    src/data/data_talk_id.h  src/data/data_talk_id.cpp
    src/data/data_msg_id.h  src/data/data_msg_id.cpp
    src/data/data_history_message.h  src/data/data_history_message.cpp

    src/settings/settings_type.h
    src/settings/common.h src/settings/common.cpp
    src/settings/common_session.h src/settings/common_session.cpp

    src/proto/sender.h 
    src/proto/config.h src/proto/config.cpp
    src/proto/instance.h src/proto/instance.cpp

    src/media/view/open_common.h
    src/media/view/overlay_widget.h src/media/view/overlay_widget.cpp
)

# 仅拷贝
configure_file(src/window/window_config.json window_config.json  COPYONLY)


get_filename_component(src_loc src REALPATH)
get_filename_component(res_loc res REALPATH)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)


qt_add_executable(TtiGoneChat
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res/TtigoneChat.qrc

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
endif()

# target_sources(TtiGoneChat src_qrc)

include_directories(src)


add_subdirectory(lib_base)
add_subdirectory(lib_ui)




include_directories(${third_party})


# target_link_libraries(TtiGoneChat PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_link_libraries(TtiGoneChat
    PRIVATE
    desktop-app::lib_base
    desktop-app::lib_ui
    # qt-material
    # desktop-app::external_qt-material
    external_qt-material
    QWindowKit::Widgets
    QsLog
    #external_qwindowkit-main
)



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
