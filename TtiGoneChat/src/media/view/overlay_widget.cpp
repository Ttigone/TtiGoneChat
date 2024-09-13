#include "media/view/overlay_widget.h"


#include "window/session_controller.h"
#include "window/sidebar.h"
#include "window/window_media_preview.h"
#include "window/window_session_menu.h"
#include "window/window_stack.h"

#include "layout/horizontal_layout.h"

#include "ui/widgets/fields/completer_field.h"
#include "ui/widgets/fields/customize_edit.h"


#include "data/data_document.h"
#include "data/data_session_label.h"
#include "data/data_talk.h"
#include "data/data_talk_init.h"
#include "local/user_account.h"
#include "storage/history_storage.h"


#include <memory>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QSplitter>
#include <QStackedWidget>


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
      completer_field_(new Window::CompleterField(this)),
      session_menu_(new Window::SessionMenu(this)),
      window_(new Ui::MbWindow(this)),
    //input_edit_(new QTextEdit(this))
    input_edit_(new Ui::CustomizeTextEdit(this))
//stack_(std::make_shared<Window::MediaStackWidget>())
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

  QVBoxLayout* t_layout = new QVBoxLayout();

  session_menu_->setMinimumWidth(200);

  t_layout->addWidget(completer_field_);
  t_layout->addWidget(session_menu_);

  main_layout_->addLayout(t_layout);

  // 谈论数据
  std::shared_ptr<Data::TextTalkData> o1 =
      std::make_shared<Data::TextTalkData>(2, "sdsadasdas", 0, 2);

  // 有一个文档信息, 存储了聊天内容
  std::shared_ptr<Data::DocumentData> test =
      std::make_shared<Data::DocumentData>();

  // 信息发送者
  // 根据 发送者建立一张表
  test->setUid(1);

  test->setName("TEST");
  test->appendChagMsg(o1);
  qDebug() << QDateTime::currentDateTime().toString(Qt::ISODate);

  Data::HistoryData t(o1->getMsgId(), 0, o1->getFromUid(), o1->getToUid(),
                o1->getMsgContent(), QString("TEST"));

  Storage::InsertHistoryData(t);

  Storage::readHistoryData(0);

  

  //auto& stack_ = Window::MediaStackWidget::Instance();
  //main_layout_->addWidget(stack_.body());

  QSplitter *splitter = new QSplitter(Qt::Vertical, this);
  // 获取了所有权
  //splitter->addWidget(stack_.body());
  // 使用信号槽机制
  splitter->addWidget(Window::MediaStackWidget::Instance().body());

  input_edit_->setPlaceholderText("Your Message");
  //input_edit_->setTextColor(Qt::blue);


  splitter->addWidget(input_edit_.get());

  main_layout_->addWidget(splitter);

  connect(session_menu_, &QListView::clicked,
          //[&stack_, this](const QModelIndex& index) {
          [this](const QModelIndex& index) {
            if (index.isValid()) {
              auto q = qvariant_cast<Data::SessionLabelData>(
                  session_menu_->model()->data(index, tRole));
              qDebug() << "index : " << q.id_;
              // 切换的时候采取加载 ???
              // 动态加载
              //stack_.body()->setCurrentIndex(q.id_);
            }
          });
}

OverlayWidget::~OverlayWidget() = default;

}  // namespace View

}  // namespace Media
