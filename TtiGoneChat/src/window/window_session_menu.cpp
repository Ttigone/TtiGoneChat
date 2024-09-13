#include "window/window_session_menu.h"

#include "data/data_session_label.h"
#include "data/data_talk_init.h"
#include "storage/session_storage.h"

#include <QPainter>
#include <QPointer>
#include <QScrollBar>

#include <QTimer>

namespace Window {
SessionLabelDelegate::SessionLabelDelegate(QObject* parent) {}

void SessionLabelDelegate::paint(QPainter* painter,
                                 const QStyleOptionViewItem& option,
                                 const QModelIndex& index) const {
  if (!index.isValid()) {
    return;
  }
  painter->save();

  // 超出范围 vector
  QVariant var = index.data(tRole);
  //  // 转换成对应类型的数据
  Data::SessionLabelData data = var.value<Data::SessionLabelData>();

  const QRectF rect(option.rect.x(), option.rect.y(), option.rect.width(),
                    option.rect.height());

  // int scrollBarWidth =
  //     option.widget->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
  // qDebug() << scrollBarWidth;

  // int fixedWidth = option.rect.width() - scrollBarWidth - 1;

  QPainterPath path;
  path.addRoundedRect(rect, 0, 0);

  painter->setPen(QPen(Qt::NoPen));
  // 当前被选中
  if (option.state.testFlag(QStyle::State_Selected)) {
    painter->setBrush(QBrush(QColor("#2e333d")));
  }
  // 鼠标移动到上面
  else if (option.state.testFlag(QStyle::State_MouseOver)) {
    painter->setBrush(QBrush(QColor("#272b33")));
  } else {
    //painter->setBrush(QBrush(Qt::NoBrush));
    // 默认状态
    painter->setBrush(QBrush(QColor("#202329")));
  }
  painter->drawPath(path);

  // 设定图片, 名称, 最新消息, 时间 的位置
  QRectF iconRect = QRectF(rect.x() + 6, rect.y() + 11, 35, 35);
  QRectF nameRect =
      QRectF(iconRect.right() + 3, iconRect.top() - 3, rect.width() - 36, 20);

  QRectF msgRect =
      QRectF(nameRect.x(), nameRect.bottom() + 3, nameRect.width() - 36, 20);

  QRectF timeRect = QRectF(rect.width() - 60, iconRect.top(), 60, 20);

  QPixmap p;
  if (icon_cache.contains(data.icon_path_)) {
    p = icon_cache.value(data.icon_path_);
  } else {
    p = QPixmap(data.icon_path_);
    icon_cache.insert(data.icon_path_, p);
  }
  painter->drawPixmap(iconRect.toRect(),
                      p.scaled(iconRect.size().toSize(), Qt::KeepAspectRatio,
                               Qt::SmoothTransformation));

  // 绘制名称
  painter->setPen(QPen(Qt::black));
  painter->setFont(QFont("Arial", 10));
  painter->drawText(nameRect, data.name_);

  // 绘制最新消息
  painter->setPen(QPen(Qt::gray));
  painter->drawText(msgRect, data.earily_msg_);

  // 绘制时间
  painter->setPen(QPen(Qt::gray));
  painter->drawText(timeRect, data.time_);

  painter->restore();
}

QSize SessionLabelDelegate::sizeHint(const QStyleOptionViewItem& option,
                                     const QModelIndex& index) const {
  //return QStyledItemDelegate::sizeHint(option, index);
  return QSize(250, 60);
}

SessionMenu::SessionMenu(QWidget* parent)
    : QListView(parent),
      session_label_delegate_(std::make_unique<SessionLabelDelegate>(this)),
      session_label_model_(std::make_unique<Data::SessionLabelModel>(this)),
      enterTimer(new QTimer(this)),
      leaveTimer(new QTimer(this)),
      isScrollBarVisible(false) {
  init();
  setupModel();
}

SessionMenu::~SessionMenu() {}

bool SessionMenu::eventFilter(QObject* watched, QEvent* event) {
  if (watched == this->viewport() || watched == this->verticalScrollBar()) {
    if (event->type() == QEvent::Enter || event->type() == QEvent::MouseMove) {
      leaveTimer->stop();
      if (!isScrollBarVisible) {
        enterTimer->start(100);
      }
    } else if (event->type() == QEvent::Leave) {
      enterTimer->stop();
      if (isScrollBarVisible) {
        leaveTimer->start(100);
      }
    }
  }

  if (watched == this->viewport() && event->type() == QEvent::Wheel) {
    QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
    int numDegrees = wheelEvent->angleDelta().y() / 8;
    int numSteps = numDegrees / 15;
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() -
                                        numSteps);

    QScrollBar* scrollBar = this->verticalScrollBar();
    int maxScrollValue = scrollBar->maximum();
    int currentValue = scrollBar->value();
    if (maxScrollValue - currentValue <= 0) {
      //qDebug() << "到底了";
      loadMoreData();
    }
    return true;
  }

  return QListView::eventFilter(watched, event);
}

void SessionMenu::loadMoreData() {
  if (!session_label_model_->loadData(currentPage, pageSize)) {
    return;
  }
  currentPage++;
}

void SessionMenu::showScrollBar() {
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  isScrollBarVisible = true;
}

void SessionMenu::hideScrollBar() {
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  isScrollBarVisible = false;
}

void SessionMenu::init() {
  // session_label_delegate_ = std::make_unique<SessionLabelDelegate>(this);
  // this->setItemDelegate(session_label_delegate_.get());
  // session_label_model_ = std::make_unique<Data::SessionLabelModel>(this);
  // this->setModel(session_label_model_.get());

  // session_label_delegate_ = new SessionLabelDelegate(this);
  this->setItemDelegate(session_label_delegate_.get());
  // session_label_model_ = new Data::SessionLabelModel(this);
  this->setModel(session_label_model_.get());
  this->viewport()->installEventFilter(this);
  this->verticalScrollBar()->installEventFilter(this);
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  enterTimer->setSingleShot(true);
  leaveTimer->setSingleShot(true);
  connect(enterTimer, &QTimer::timeout, this, &SessionMenu::showScrollBar);
  connect(leaveTimer, &QTimer::timeout, this, &SessionMenu::hideScrollBar);

  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void SessionMenu::setupModel()
{ loadMoreData(); }
}  // namespace Window
