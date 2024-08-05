/*****************************************************************//**
 * \file   conner_button.h
 * \brief  具有右上角角标的按钮
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef CONNER_BUTTON_H
#define CONNER_BUTTON_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPropertyAnimation;
class QParallelAnimationGroup;
QT_END_NAMESPACE


namespace Ui {

class ConnerButton : public QWidget {
  Q_OBJECT
  Q_PROPERTY(QRectF rect READ rect WRITE setRect)
  Q_PROPERTY(qint16 font READ fontSize WRITE setFontSize)

 public:
  explicit ConnerButton(QWidget *parent = nullptr);

  void setConnerText(const QString &new_text);

  QRectF rect() const;
  void setRect(const QRectF &rect);

  qint16 fontSize() const;
  void setFontSize(const qint16 &font_size);

 protected:
  void paintEvent(QPaintEvent *event) override;
  void enterEvent(QEnterEvent *event) override;
  void leaveEvent(QEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;

 private:
  // QRectF icon_Rect_ = QRectF(2, 6, 30, 30);
  // 图标框
  QRectF icon_rect_ = QRectF(2, 6, 30, 30);
  // 角标框
  QRectF conner_rect_;
  qint16 conner_rect_w;
  qint16 conner_rect_h;
  // 角标缩放比例
  float zoom_radio_ = 0.05;
  // float zoom_radio_ = 0.03;
  // 底层图片路径
  QString image_path;
  // 角标字体
  QFont conner_font_;
  qint16 font_size_;
  qint16 font_begin_size_;
  qint16 font_end_size_;

  QString text_ = "+99";
  bool is_hovering_ = false;
  bool is_hovering_image_ = false;
  QPropertyAnimation *conner_rect_animation_;
  QPropertyAnimation *font_animation_;
  QParallelAnimationGroup *animation_group_;
};

class WordsButton : public QWidget
{

};

}  // namespace Ui


#endif  // CONNER_BUTTON_H
