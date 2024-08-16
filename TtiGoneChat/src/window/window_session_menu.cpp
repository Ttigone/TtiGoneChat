#include "window/window_session_menu.h"

#include <QPainter>

#include "data/data_session_label.h"
#include "storage/session_storage.h"

namespace Window {
SessionLabelDelegate::SessionLabelDelegate(QObject* parent)
{ qDebug() << "SessionLabelDelegate";
}

void SessionLabelDelegate::paint(QPainter* painter,
                                 const QStyleOptionViewItem& option,
                                 const QModelIndex& index) const {
  //qDebug() << "paint";
  if (index.isValid()) {
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

  //  QVariant var = index.data(tRole);
  //  // 转换成对应类型的数据
  //  auto data = var.value<StorageSessionLabel>();

  //  QRectF rect;
  //  rect.setX(option.rect.x());
  //  rect.setY(option.rect.y());
  //  rect.setWidth(option.rect.width() - 1);
  //  rect.setHeight(option.rect.height() - 1);

  //  QPainterPath path;
  //  path.moveTo(rect.topLeft());
  //  path.lineTo(rect.topRight());
  //  path.quadTo(rect.topRight(), rect.topRight());
  //  path.lineTo(rect.bottomRight());
  //  path.quadTo(rect.bottomRight(), rect.bottomRight());
  //  path.lineTo(rect.bottomLeft());
  //  path.quadTo(rect.bottomLeft(), rect.bottomLeft());
  //  path.lineTo(rect.topLeft());
  //  path.quadTo(rect.topLeft(), rect.topLeft());

  //  // 当前被选中
  //  if (option.state.testFlag(QStyle::State_Selected)) {
  //    painter->setPen(QPen(QColor("#e3e3e5")));
  //    painter->setBrush(QBrush(QColor("#e3e3e5")));
  //    painter->drawPath(path);
  //  }
  //  // 鼠标移动到上面
  //  if (option.state.testFlag(QStyle::State_MouseOver)) {
  //    painter->setPen(QPen(QColor("#ebeced")));
  //    painter->setBrush(QBrush(QColor("#ebeced")));
  //    painter->drawPath(path);
  //  }

  //  // 设定图片, 名称, 最新消息, 时间 的位置
  //  QRectF iconRect = QRectF(rect.x() + 6, rect.y() + 11, 35, 35);
  //  QRectF nameRect =
  //      QRectF(iconRect.right() + 3, iconRect.top() - 3, rect.width() - 36, 20);
  //  QRectF msgRect =
  //      QRectF(nameRect.x(), nameRect.bottom() + 3, nameRect.width() - 36, 20);
  //  QRectF timeRect = QRectF(rect.width() - 40, iconRect.top(), 40, 20);

  //  // painter->drawPixmap(iconRect,
  //  // QPixmap::fromImage(QImage(data.session_label_icon_path)));
  //  // painter->drawPixmap(iconRect, QPixmap(data.session_label_icon_path));
  //  // 绘制头像
  //  auto p = QPixmap(data.session_label_icon_path);
  //  painter->drawPixmap(iconRect.toRect(),
  //                      p.scaled(iconRect.size().toSize(), Qt::KeepAspectRatio,
  //                               Qt::SmoothTransformation));

  //  // 绘制名称
  //  painter->setPen(QPen(Qt::black));
  //  painter->setFont(QFont("Arial", 10));
  //  painter->drawText(nameRect, data.session_label_name);

  //  // 绘制最新消息
  //  painter->setPen(QPen(Qt::gray));
  //  painter->drawText(msgRect, data.session_label_earily_msg);

  //  // 绘制时间
  //  painter->setPen(QPen(Qt::gray));
  //  painter->drawText(timeRect, data.session_label_time);

    painter->restore();
  }
    //return QStyledItemDelegate().paint(painter, option, index);

}

QSize SessionLabelDelegate::sizeHint(const QStyleOptionViewItem& option,
                                     const QModelIndex& index) const {
  // return QStyledItemDelegate::sizeHint(option, index);
  return QSize(200, 58l);
}

SessionMenu::SessionMenu(QWidget* parent)
//session_label_delegate_(new SessionLabelDelegate(this)),
//  session_label_model_(new Data::SessionLabelModel(this))
	{ init(); }

SessionMenu::~SessionMenu() {}

void SessionMenu::init() {
  qDebug() << "init";
  //session_label_delegate_ = std::make_unique<SessionLabelDelegate>(this);
  //this->setItemDelegate(session_label_delegate_.get());
  //session_label_model_ = std::make_unique<Data::SessionLabelModel>(this);
  //this->setModel(session_label_model_.get());

  session_label_delegate_ = new SessionLabelDelegate(this);
  this->setItemDelegate(session_label_delegate_);
  session_label_model_ = new Data::SessionLabelModel(this);
  this->setModel(session_label_model_);
}
}  // namespace Window