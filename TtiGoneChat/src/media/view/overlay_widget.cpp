#include "media/view/overlay_widget.h"

#include "window/sidebar.h"
#include "window/window_media_preview.h"
#include "window/window_session_menu.h"
#include "window/session_controller.h"

#include "layout/horizontal_layout.h"

#include "ui/widgets/fields/completer_field.h"


#include <QLabel>
#include <QVBoxLayout>

//namespace Window {
//
//class SessionMenu;
//
//} // namespace Window


namespace Media {
namespace View {

OverlayWidget::OverlayWidget(QWidget* parent)
    : widget_(new Ui::MbWidget(this)),
      main_layout_(new QHBoxLayout()),
      window_(new Ui::MbWindow(this))
{
  widget_->setLayout(main_layout_);
  main_layout_->setContentsMargins(QMargins());
  main_layout_->setSpacing(0);

  QHBoxLayout* layout = new QHBoxLayout();
  // QHBoxLayout* layout = new QHBoxLayout();
  layout->setContentsMargins(QMargins());
  layout->setSpacing(0);
  this->setLayout(layout);

  // side_bar_ = std::make_unique<Window::SideBar>(this);

  layout->addWidget(widget_);

  side_bar_ = std::make_unique<Window::SideBar>();
  main_layout_->addWidget(side_bar_.get(), Qt::AlignLeft);

  // QWidget * widget = new QWidget();
  // widget->setMinimumWidth(30);
  // widget->setStyleSheet("background-color:Coral");
  // window_->setFixedWidth(30);
  // qDebug() << window_->minimumWidth();

  // main_layout_->addStretch();
  // main_layout_->addWidget(window_, Qt::AlignHCenter);

  // const not_null<Ui::MbWidget*> window_ = new Ui::MbWidget(this);
  // window_->setStyleSheet("background-color:Coral");
  // qDebug() << window_->geometry();
  // const not_null<Ui::MbWidget*> window_ = new Ui::MbWidget(this);
  // window_->setFixedWidth(30);

  //window_->setStyleSheet("background-color:Coral");
  //main_layout_->addWidget(window_);

  QVBoxLayout *t_layout = new QVBoxLayout();

  //Ui::Widgets::*t_input = new Ui::Widgets::CustomizeFields(this);
  Window::CompleterField *t_input = new Window::CompleterField(this);




  Window::SessionMenu* t_menu = new Window::SessionMenu(this);
  t_menu->setMinimumWidth(200);
  //t_menu->setStyleSheet("QListView { border: none; }");

  t_layout->addWidget(t_input);
  t_layout->addWidget(t_menu);

  main_layout_->addLayout(t_layout);
  //main_layout_->addWidget(t_menu);



  //Window::MediaPreviewWidget *t_window = new Window::MediaPreviewWidget(this, Window::SessionController());
  Window::MediaPreviewWidget* t_window = new Window::MediaPreviewWidget(this);
  t_window->setMinimumWidth(100);
  t_window->setStyleSheet("background-color: #a9beae");

  main_layout_->addWidget(t_window);
}

OverlayWidget::~OverlayWidget() = default;

}  // namespace View

}  // namespace Media
