#include "layout/vertical_layout.h"

#include <QWidget>

namespace Layout {

VerticalLayout::VerticalLayout(QWidget* parent, int margin, int spacing)
    : QLayout(parent) {
  setContentsMargins(margin, margin, margin, margin);
  setSpacing(spacing);
}

VerticalLayout::VerticalLayout(int spacing) : QLayout() { setSpacing(spacing); }

VerticalLayout::~VerticalLayout() {
  QLayoutItem* item;
  while ((item = takeAt(0)) != nullptr) {
    // if (item->widget()) {
    //   item->widget()->setParent(nullptr);
    // }
    delete item;
  }
}

void VerticalLayout::addItem(QLayoutItem* item) { item_list_.append(item); }

// void VerticalLayout::addWidget(QWidget* widget) {
//   widget->setParent(parentWidget());
//   addItem(new QWidgetItem(widget));
//   //qDebug() << "Widget: " << widget->width() << widget->height() <<
//   widget->objectName();
//   //widget->setMinimumHeight(100);
//   // 设置父对象
// }

int VerticalLayout::count() const { return item_list_.size(); }

QLayoutItem* VerticalLayout::itemAt(int index) const {
  return item_list_.value(index);
}

QLayoutItem* VerticalLayout::takeAt(int index) {
  if (index >= 0 && index < item_list_.size()) {
    return item_list_.takeAt(index);
  }
  return nullptr;
}

void VerticalLayout::setGeometry(const QRect& rect) {
  QLayout::setGeometry(rect);
  if (item_list_.isEmpty()) {
    return;
  }

  //// 当前 rect 的高度
  //int totalHeight = rect.height();
  //qDebug() << "total" << totalHeight;

  //int itemHeight = totalHeight / item_list_.size();  // 平均分配高度

  //int y = rect.y();
  //for (auto item : item_list_) {
  //  QSize itemSize = item->sizeHint();
  //  item->setGeometry(QRect(rect.x(), y, rect.width(), itemHeight));
  //  y += itemSize.height();
  //}

          //QLayout::setGeometry(rect);

  int y = rect.y();
  int totalHeight = 0;

  // 计算总高度
  for (auto item : item_list_) {
    totalHeight += item->sizeHint().height();
  }

  // 计算可用空间
  int remainingHeight = rect.height() - totalHeight;
  int stretchCount = 0;

  // 计算拉伸项的数量
  for (auto item : item_list_) {
    if (item->expandingDirections() & Qt::Vertical) {
      stretchCount++;
    }
  }

  int stretchHeight = stretchCount > 0 ? remainingHeight / stretchCount : 0;

  // 设置每个项的几何形状
  for (auto item : item_list_) {
    int itemHeight = item->sizeHint().height();
    if (item->expandingDirections() & Qt::Vertical) {
      itemHeight += stretchHeight;
    }
    item->setGeometry(QRect(rect.x(), y, rect.width(), itemHeight));
    y += itemHeight;
  }

}

QSize VerticalLayout::sizeHint() const {
  // return minimumSize();
  QSize s(0, 0);
  for (const QLayoutItem* item : item_list_) {
    // qDebug() << item->widget()->width() << item->widget()->height();
    s = s.expandedTo(item->sizeHint());
  }
  return s;
}

QSize VerticalLayout::minimumSize() const {
  QSize size(0, 0);
  for (const QLayoutItem* item : item_list_) {
    size = size.expandedTo(item->minimumSize());
  }
  // return size + QSize(0, item_list_.size() * spacing());
  return size;
}

void VerticalLayout::addSpacerItem(QSpacerItem* spacerItem) {
  addItem(spacerItem);
}

void VerticalLayout::addStretch(int stretch) {
  addSpacerItem(
      new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void VerticalLayout::addWidget(QWidget* widget, int stretch,
                               Qt::Alignment alignment) {
  widget->setParent(parentWidget());
  QWidgetItem* item = new QWidgetItem(widget);
  item->setAlignment(alignment);
  addItem(item);

  if (stretch > 0) {
    addStretch(stretch);
  }
}

}  // namespace Layout
