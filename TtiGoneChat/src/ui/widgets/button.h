/*****************************************************************//**
 * \file   button.h
 * \brief  抽象按钮类
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef UI_WIDGET_BUTTON_H
#define UI_WIDGET_BUTTON_H

#include <QPushButton>

namespace Ui {

class ButtonPrivate;

class Button : public QPushButton {
  Q_OBJECT
  Q_DECLARE_PRIVATE(Button)
  Q_PROPERTY(QIcon iconNormal READ iconNormal WRITE setIconNormal FINAL)
  Q_PROPERTY(QIcon iconChecked READ iconChecked WRITE setIconChecked FINAL)
  Q_PROPERTY(QIcon iconDisabled READ iconDisabled WRITE setIconDisabled FINAL)

 public:
  explicit Button(QWidget *parent = nullptr);
  ~Button();

 public:
  QIcon iconNormal() const;
  void setIconNormal(const QIcon &icon);

  QIcon iconChecked() const;
  void setIconChecked(const QIcon &icon);

  QIcon iconDisabled() const;
  void setIconDisabled(const QIcon &icon);

 signals:
  void doubleClicked();

 protected:
  void checkStateSet() override;
  void mouseDoubleClickEvent(QMouseEvent *event) override;
  // void paintEvent(QPaintEvent* event) override;
  // void mouseMoveEvent(QMouseEvent* event) override;
  // void mousePressEvent(QMouseEvent* event) override;
  // void mouseReleaseEvent(QMouseEvent* event) override;

 protected:
  Button(ButtonPrivate &d, QWidget *parent = nullptr);

  QScopedPointer<ButtonPrivate> d_ptr;
};

} // namespace Ui

#endif // UI_WIDGET_BUTTON_H
