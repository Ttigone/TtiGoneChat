#include "window/window_media_preview.h"

#include "data/data_document.h"
#include "data/data_talk_init.h"
#include "history/history_widget.h"
#include "local/user_account.h"
#include "ui/chat/chat_item.h"
#include "ui/widgets/buttons.h"

namespace Window {

MediaPreviewWidget::MediaPreviewWidget(QWidget* parent)
    : MbWidget(parent),
      title_label_(new QLabel),
      layout_(new QVBoxLayout),
      widget_(new History::HistoryWidget),
      //title_layout_(new QHBoxLayout),
      title_layout_(new QGridLayout),
      title_window_(new QWidget)
{
  init();
  // setAttribute(Qt::WA_TransparentForMouseEvents);
}

MediaPreviewWidget::~MediaPreviewWidget() {}

void MediaPreviewWidget::setInfo(
    std::shared_ptr<Data::DocumentData> user_info) {
  user_info_ = user_info;
  title_label_->setText(user_info->getName());
  widget_->removeAllItem();
   for (auto& msg : user_info->getChatMsg()) {
     appendChatMsg(msg);
   }
}
void MediaPreviewWidget::appendChatMsg(
    std::shared_ptr<Data::TextTalkData> data) {
  auto self = Local::UserAccount::Instance()->GetUserInfo();
  Data::TalkPropertyData role;
  // 我方发送消息
  //qDebug() << "From: " << data->getFromUid() << "TO: " << self->getUid();
  if (data->getFromUid() == self->getUid()) {
    role = Data::TalkPropertyData::TalkType::Self;
    Ui::ChatItemBase* item = new Ui::ChatItemBase(role, this);

    item->setUserName(self->getName());
    item->setUserIcon(QPixmap(self->getIcon()));

    QWidget* bubble = nullptr;
    // 新建一个 bubble
    bubble = new Ui::TextBubble(role, data->getMsgContent());

    item->setWidget(bubble);

    widget_->appendChatItem(item);
  } else {
    //qDebug() << "TT";
    // 其他人发送消息
    role = Data::TalkPropertyData::TalkType::User;
    Ui::ChatItemBase* item = new Ui::ChatItemBase(role);
    item->setUserName(self->getName());
    item->setUserIcon(QPixmap(self->getIcon()));

    QWidget* bubble = nullptr;
    // 新建一个 bubble
    bubble = new Ui::TextBubble(role, data->getMsgContent());

    item->setWidget(bubble);

    widget_->appendChatItem(item);
  }
}

bool MediaPreviewWidget::isPrivateChat() {
  return true;
}

void MediaPreviewWidget::paintEvent(QPaintEvent* event) {
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void MediaPreviewWidget::init() {
  //title_layout_->addWidget(title_label_, 0, Qt::AlignLeft);
  title_layout_->setContentsMargins(QMargins());
  title_layout_->addWidget(title_label_, 0, 0, 1, 1, Qt::AlignLeft);
  QMargins t = title_layout_->contentsMargins();
  //t.right() - 
  //MarM
  if (isPrivateChat()) {
    // 私聊, 仅显示在线时间
    online_time_ = std::make_shared<QLabel>();
    online_time_->setText("在线时间: 1小时");
    title_layout_->addWidget(online_time_.get(), 1, 0, 1, 1, Qt::AlignLeft);
  } else {
    // 群聊, 显示成员和在线人数
    member_online_num_ = std::make_shared<QLabel>();
    //online_num_ = std::make_shared<QLabel>();
    title_layout_->addWidget(member_online_num_.get(), 1, 0, 1, 1,
                             Qt::AlignLeft);
  }
  //search_btn_ = std::make_unique<Ui::CommonButton>(
  //    20, 20, ":/icon/ui/icons/mediaview/search-normal.png",
  //    ":/icon/ui/icons/mediaview/search-hover.png", this);
  //search_btn_(std::make_unique<Ui::CommonButton>(20, 20, ":/icon/ui/icons/mediaview/search-normal.png", ":/icon/ui/icons/mediaview/search-hover.png", this));
  //multimedia_btn_ = std::make_unique<Ui::CommonButton>(":/icon/ui/icons/calls/phone-normal.png", ":/icon/ui/icons/calls/phone-hover.png", this);
  //fold_btn_ = std::make_unique<Ui::CommonButton>(":/icon/ui/icons/mediaview/fold-normal.png", ":/icon/ui/icons/mediaview/fold-hover.png", this);
  //detail_btn = std::make_unique<Ui::CommonButton>(":/icon/ui/icons/mediaview/detail-normal.png", ":/icon/ui/icons/mediaview/detail-hover.png", this);

  //// 弹窗
  QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  title_layout_->addItem(spacer, 0, 1, 2, 1, Qt::AlignRight);

  //title_layout_->addWidget(search_btn_.get(), 0, 2, 2, 1, Qt::AlignCenter);
  //title_layout_->addWidget(multimedia_btn_.get(), 0, 3, 2, 1, Qt::AlignCenter);
  //title_layout_->addWidget(fold_btn_.get(), 0, 4, 2, 1, Qt::AlignCenter);
  //title_layout_->addWidget(detail_btn.get(), 0, 5, 2, 1, Qt::AlignCenter | Qt::AlignRight);

  title_window_->setLayout(title_layout_);
  layout_->setContentsMargins(QMargins());
  layout_->addWidget(title_window_);
  layout_->addWidget(widget_);
  setLayout(layout_);
}

// void MediaPreviewWidget::resizeEvent(QResizeEvent* event) {}

void MediaPreviewWidget::startShow() {}

}  // namespace Window
