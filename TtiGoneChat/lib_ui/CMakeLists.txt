add_library(lib_ui STATIC
)
add_library(desktop-app::lib_ui ALIAS lib_ui)

get_filename_component(src_loc . REALPATH)


set_target_properties(lib_ui PROPERTIES AUTOMOC ON)

# ���� uic, ���� ui_pch.h ��ʶ��Ϊ .ui �ļ� 
set_target_properties(lib_ui PROPERTIES AUTOUIC OFF)


# Ԥ����ͷ�ļ�
target_precompile_headers(lib_ui PRIVATE $<$<COMPILE_LANGUAGE:CXX,OBJCXX>:${src_loc}/ui/ui_pch.h>)

target_sources(lib_ui PRIVATE
        ui/ui_pch.h
        ui/style/style_font.h ui/style/style_font.cpp
        ui/widgets/buttons.h ui/widgets/buttons.cpp
        ui/abstract_button.h ui/abstract_button.cpp
        ui/style/style_core_types.h
        ui/mb_widget.h ui/mb_widget.cpp

        ui/widgets/mb_window.h ui/widgets/mb_window.cpp

        ui/platform/platform_window.h ui/platform/platform_window.cpp

        ui/platform/win/win_window.cpp ui/platform/win/win_window.h

        ui/ui_utility.h ui/ui_utility.cpp
        ui/widgets/labels.h ui/widgets/labels.cpp
        ui/click_handler.h ui/click_handler.cpp

        ui/text/text_entity.h ui/text/text_entity.cpp

        ui/text/text.h ui/text/text.cpp
        ui/widgets/popup_menu.h ui/widgets/popup_menu.cpp
        ui/effects/animation_value.h ui/effects/animation_value.cpp

        ui/widgets/fields/customize_fields.cpp ui/widgets/fields/customize_fields.h
        ui/widgets/message_textedit.cpp ui/widgets/message_textedit.h
        ui/widgets/snack_bar.cpp ui/widgets/snack_bar.h

)

target_include_directories(lib_ui
        PUBLIC
        ${src_loc}
)


target_link_libraries(lib_ui
        PUBLIC
        desktop-app::lib_base
)


