/*****************************************************************//**
 * \file   vertical_layout.h
 * \brief  垂直布局
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef VERTICAL_LAYOUT_H
#define VERTICAL_LAYOUT_H
 
#include <QLayout>
#include <QSpacerItem>

namespace Layout {
class VerticalLayout : public QLayout {
 public:
  VerticalLayout(QWidget *parent = nullptr, int margin = 0, int spacing = 0);
  VerticalLayout(int spacing = -1);
  ~VerticalLayout();

  void addItem(QLayoutItem *item) override;
  // void addWidget(QWidget *widget);
  int count() const override;
  QLayoutItem *itemAt(int index) const override;
  QLayoutItem *takeAt(int index) override;

  void setGeometry(const QRect &rect) override;
  ///
  /// @return 布局的建议面积
  QSize sizeHint() const override;
  ///
  /// @return 布局最小面积
  QSize minimumSize() const override;

  void addSpacerItem(QSpacerItem *spacerItem);

  void addStretch(int stretch = 0);

  // void setSpacing(int spacing);
  // int spacing() const;

  // Qt::Orientations expandingDirections() const override;
  // bool hasHeightForWidth() const override;
  // int heightForWidth(int width) const override;
  // int minimumHeightForWidth(int width) const override;

 private:
  QList<QLayoutItem *> item_list_;
  int spacing_;
};
}  // namespace Layout

#endif	// VERTICAL_LAYOUT_H
