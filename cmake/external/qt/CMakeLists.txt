add_library(external-qt INTERFACE IMPORTED GLOBAL)
# add_library(desktop-app::external-qt ALIAS external_qt)

target_link_libraries(external-qt
    INTERFACE
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::WidgetsPrivate
    Qt::GuiPrivate
)

target_include_directories(external-qt SYSTEM
INTERFACE
)

