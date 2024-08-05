#include "layout/vertical_layout.h"

#include <QWidget>

namespace Layout {

VerticalLayout::VerticalLayout(QWidget* parent, int margin, int spacing)
    : QLayout(parent)
{
  setContentsMargins(margin, margin, margin, margin);
  setSpacing(spacing);
}

VerticalLayout::VerticalLayout(int spacing) : QLayout() { setSpacing(spacing); }

VerticalLayout::~VerticalLayout() {
  QLayoutItem* item;
  while ((item = takeAt(0)) != nullptr) {
    //if (item->widget()) {
    //  item->widget()->setParent(nullptr);
    //}
    delete item;
  }
}

void VerticalLayout::addItem(QLayoutItem* item) { item_list_.append(item); }

//void VerticalLayout::addWidget(QWidget* widget) {
//  widget->setParent(parentWidget());
//  addItem(new QWidgetItem(widget));
//  //qDebug() << "Widget: " << widget->width() << widget->height() << widget->objectName();
//  //widget->setMinimumHeight(100);
//  // 设置父对象
//}

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
  // //左上角 y 坐标
  //int y = rect.y();
  //for (QLayoutItem* item : item_list_) {
  //  // 获取控件的的高度
  //  int itemHeight = item->sizeHint().height();
  //  item->setGeometry(QRect(rect.x(), y, rect.width(), itemHeight));
  //  //y += itemHeight + spacing();
  //  y += itemHeight;
  //  //qDebug() << "Item Geometry: " << item->geometry();
  //  //item
  //}

	int totalHeight = rect.height();
  int itemHeight = totalHeight / item_list_.size();  // 平均分配高度

  int y = rect.y();
  for (QLayoutItem* item : item_list_) {
    QSize itemSize = item->sizeHint();
    item->setGeometry(QRect(rect.x(), y, rect.width(), itemHeight));
    //item->setGeometry(QRect(rect.x(), y, rect.width(), itemSize.height()));
    y += itemSize.height();
  }
}

QSize VerticalLayout::sizeHint() const
{
  //return minimumSize();
  QSize s(0, 0);
  for (const QLayoutItem* item : item_list_) {
    //qDebug() << item->widget()->width() << item->widget()->height();
    s = s.expandedTo(item->sizeHint());
  }
  return s;
}

QSize VerticalLayout::minimumSize() const
{
  QSize size(0, 0);
  for (const QLayoutItem* item : item_list_) {
		size = size.expandedTo(item->minimumSize());
	}
  //return size + QSize(0, item_list_.size() * spacing());
  return size;
}
}  // namespace Layout
