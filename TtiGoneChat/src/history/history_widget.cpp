#include "history/history_widget.h"

#include <QScrollBar>
#include <QStyleOption>
#include <QTimer>

namespace History {
HistoryWidget::HistoryWidget(QWidget* parent)
    : QWidget(parent), is_appended_(false) {
  QVBoxLayout* mainLayout = new QVBoxLayout(this);
  this->setLayout(mainLayout);
  mainLayout->setContentsMargins(QMargins());

  // 可以滚动的区域
  scroll_area_ = new QScrollArea();
  scroll_area_->setObjectName("history_scroll_area");
  mainLayout->addWidget(scroll_area_);

  // 滚动区域的 widget (存放气泡)
  QWidget* tem = new QWidget(this);
  tem->setObjectName("history_basic");
  // 填充背景颜色
  tem->setAutoFillBackground(true);
  QVBoxLayout* tem_layout = new QVBoxLayout(tem);
  tem_layout->setContentsMargins(QMargins());
  // 预留高度
  // tem_layout 存放一个个 气泡 widget
  tem_layout->addWidget(new QWidget(), 100000);
  tem->setLayout(tem_layout);

  // 设置了一个 widget  真正的信息窗体
  scroll_area_->setWidget(tem);

  // 关闭垂直滚动条
  scroll_area_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  // 取出滚动条
  QScrollBar* verticalScrollBar = scroll_area_->verticalScrollBar();
  // 滚动条滚动时触发
  connect(verticalScrollBar, &QScrollBar::rangeChanged, this,
          &HistoryWidget::scrollBarMoved);
  QHBoxLayout* tem_layout2 = new QHBoxLayout();
  // 右边的滚动条
  tem_layout2->addWidget(verticalScrollBar, 0, Qt::AlignRight);
  tem_layout2->setContentsMargins(QMargins());
  // 又设置一个 布局 这个布局添加了一个 原本是 area 的滚动条, 放置最右边, 被压缩
  scroll_area_->setLayout(tem_layout2);
  verticalScrollBar->setHidden(true);

  scroll_area_->setWidgetResizable(true);
  scroll_area_->installEventFilter(this);
  init();
}

void HistoryWidget::appendChatItem(QWidget* item) {
  // 获取垂直布局
  // 消息体 tem 的布局
  QVBoxLayout* vl =
      qobject_cast<QVBoxLayout*>(scroll_area_->widget()->layout());
  // 插入到最后一个位置
  vl->insertWidget(vl->count() - 1, item);
  is_appended_ = true;
}

void HistoryWidget::insertChatItem() {}

void HistoryWidget::removeAllItem() {
  QVBoxLayout* layout =
      qobject_cast<QVBoxLayout*>(scroll_area_->widget()->layout());
  int count = layout->count();
  for (int i = 0; i < count - 1; ++i) {
    QLayoutItem* item = layout->takeAt(0);  // 从第一个删除
    if (item) {
      if (QWidget* w = item->widget()) {
        w->deleteLater();
      }
      delete item;
    }
  }
}
bool HistoryWidget::eventFilter(QObject* object, QEvent* event) {
  if (event->type() == QEvent::Enter && object == scroll_area_) {
    // 有数据显示, 没数据隐藏
    scroll_area_->verticalScrollBar()->setHidden(
        scroll_area_->verticalScrollBar()->maximum() == 0);
  } else if (event->type() == QEvent::Leave && object == scroll_area_) {
    scroll_area_->verticalScrollBar()->setHidden(true);
  }
  return QWidget::eventFilter(object, event);
}

void HistoryWidget::paintEvent(QPaintEvent* event) {
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
  QWidget::paintEvent(event);
}
void HistoryWidget::scrollBarMoved(int min, int max) {
  if (is_appended_) {
    QScrollBar* scrollBar = scroll_area_->verticalScrollBar();
    // 滚到最下面
    scrollBar->setSliderPosition(scrollBar->maximum());
    // 500ms 调用 1 次
    QTimer::singleShot(500, [this]() { is_appended_ = false; });
  }
}
void HistoryWidget::init(){
}
}  // namespace History
