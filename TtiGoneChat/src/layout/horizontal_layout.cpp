#include "layout/horizontal_layout.h"

namespace Layout
{

HorizontalLayout::HorizontalLayout(QWidget* parent, int margin, int spacing)
	:QLayout(parent)
{
  setContentsMargins(margin, margin, margin, margin);
  setSpacing(spacing);
}

HorizontalLayout::HorizontalLayout(int spacing)
{ setSpacing(spacing); }

HorizontalLayout::~HorizontalLayout()
{
  QLayoutItem* item;
  while ((item = takeAt(0)) != nullptr) {
    delete item;
  }
}

void HorizontalLayout::addItem(QLayoutItem* item)
{ item_list_.append(item); }

int HorizontalLayout::count() const
{ return item_list_.size(); }

QLayoutItem* HorizontalLayout::itemAt(int index) const
{
  return item_list_.value(index);
}

QLayoutItem* HorizontalLayout::takeAt(int index)
{
  if (index >= 0 && index < item_list_.size()) {
    return item_list_.takeAt(index);
  }
  return nullptr;
}

void HorizontalLayout::setGeometry(const QRect& rect)
{
	QLayout::setGeometry(rect);
  QLayout::setGeometry(rect);
  if (item_list_.isEmpty()) {
    return;
  }

  int x = rect.x();
  int totalWidth = 0;

  // 计算总宽度
  for (auto item : item_list_) {
    totalWidth += item->sizeHint().width();
  }

  // 计算可用空间
  int remainingWidth = rect.width() - totalWidth;
  int stretchCount = 0;

  // 计算拉伸项的数量
  for (auto item : item_list_) {
    if (item->expandingDirections() & Qt::Horizontal) {
      stretchCount++;
    }
  }

  int stretchWidth = stretchCount > 0 ? remainingWidth / stretchCount : 0;

  // 设置每个项的几何形状
  for (auto item : item_list_) {
    int itemWidth = item->sizeHint().width();
    if (item->expandingDirections() & Qt::Horizontal) {
      itemWidth += stretchWidth;
    }
    item->setGeometry(QRect(x, rect.y(), itemWidth, rect.height()));
    x += itemWidth + spacing();
  }
}

QSize HorizontalLayout::sizeHint() const
{
  QSize s(0, 0);
  for (const QLayoutItem* item : item_list_) {
    s = s.expandedTo(item->sizeHint());
  }
  return s;
}

QSize HorizontalLayout::minimumSize() const
{
  QSize size(0, 0);
  for (const QLayoutItem* item : item_list_) {
    size = size.expandedTo(item->minimumSize());
  }
  return size;
}

void HorizontalLayout::addSpacerItem(QSpacerItem* spacerItem)
{
  addItem(spacerItem);
}

void HorizontalLayout::addStretch(int stretch)
{
  addSpacerItem(
      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
}

void HorizontalLayout::addWidget(QWidget* widget, int stretch, Qt::Alignment alignment)
{
    QWidgetItem* item = new QWidgetItem(widget);
    item->setAlignment(alignment);
    item_list_.append(item);
    if (stretch > 0) {
      addStretch(stretch);
    }
}

} // namespace Layout
