/*****************************************************************//**
 * \file   common_button.h
 * \brief  普通按钮
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef COMMON_BUTTON_H
#define COMMON_BUTTON_H

#include <QWidget>

namespace Ui {


class CommonButton : public QWidget {
 public:
  explicit CommonButton(QWidget* parent = nullptr);
  explicit CommonButton(const QImage &image, QWidget* parent = nullptr);
  explicit CommonButton(const QString &image_path, QWidget* parent = nullptr);
  ~CommonButton();

  QImage image() const;
  void setImage(const QImage &image);
  void setImage(const QString &image_path);

 protected:
  void paintEvent(QPaintEvent* event) override;
  void enterEvent(QEnterEvent* event) override;
  void leaveEvent(QEvent* event) override;

  void mouseMoveEvent(QMouseEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  //void mouse

 private:
  void initialSize(int w, int h);

  QImage image_;
  QRectF image_rect_;
  bool mouse_is_inside_;
  QString image_path_;
};


} // namespace Ui

#endif  // COMMON_BUTTON_H
