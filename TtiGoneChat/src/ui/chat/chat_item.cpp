#include "ui/chat/chat_item.h"

#include <QTextBlock>

namespace Ui {
ChatItemBase::ChatItemBase(Data::TalkPropertyData role, QWidget* parent)
    : QWidget(parent), role_(role) {
  init();
}
void ChatItemBase::setUserName(const QString& name) {
  //name_label_->setText(name);
}
void ChatItemBase::setUserIcon(const QPixmap& icon) {
  icon_label_->setPixmap(icon);
}
void ChatItemBase::setWidget(QWidget* w) {
  QGridLayout* layout = qobject_cast<QGridLayout*>(this->layout());
  layout->replaceWidget(bubble_, w);
  bubble_->deleteLater();
  bubble_ = w;
}
void ChatItemBase::init() {
  // 推到右边
  if (role_.isSelf()) {
    icon_label_ = new QLabel();
    icon_label_->setScaledContents(true);
    icon_label_->setFixedSize(36, 36);
    // 左边一整个是 bubble
    bubble_ = new QWidget();
    QGridLayout* layout = new QGridLayout();
    //QHBoxLayout* layout = new QHBoxLayout();
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(3);
    layout->setContentsMargins(QMargins(3, 3, 3, 3));
    QSpacerItem* spacerItem =
        new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    // 3 icon
    layout->addWidget(icon_label_, 0, 2, 1, 1, Qt::AlignBottom);
    // 弹簧
    layout->addItem(spacerItem, 0, 0, 1, 1);
    // 4 5 bubble
    layout->addWidget(bubble_, 0, 1, 1, 1);
    //第一列占2/5
    layout->setColumnStretch(0, 2);
    // 第二列占3/5
    layout->setColumnStretch(1, 3);

    this->setLayout(layout);
    this->setStyleSheet("background-color: transparent");
  } else {
    // 左边
    icon_label_ = new QLabel();
    icon_label_->setScaledContents(true);
    icon_label_->setFixedSize(36, 36);
    // 左边一整个是 bubble
    bubble_ = new QWidget();
    QGridLayout* layout = new QGridLayout();
    //QHBoxLayout* layout = new QHBoxLayout();
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(3);
    layout->setContentsMargins(QMargins(3, 3, 3, 3));
    QSpacerItem* spacerItem =
        new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    // 3 icon
    layout->addWidget(icon_label_, 0, 0, 1, 1, Qt::AlignBottom);
    // 4 5 bubble
    layout->addWidget(bubble_, 0, 1, 1, 1);
    // 弹簧
    layout->addItem(spacerItem, 0, 2, 1, 1);
    //第一列占2/5
    layout->setColumnStretch(0, 3);
    // 第二列占3/5
    layout->setColumnStretch(1, 2);

    this->setLayout(layout);
    this->setStyleSheet("background-color: transparent");
  }
}


}  // namespace Ui
