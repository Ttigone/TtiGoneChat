/*****************************************************************//**
 * \file   buttons.h
 * \brief  底层按钮(基于 QWidget)
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef UI_WIDGETS_BUTTONS_H
#define UI_WIDGETS_BUTTONS_H

#include "ui/abstract_button.h"
//#include  "ui/controls/conner_button.h"

QT_BEGIN_NAMESPACE
class QPropertyAnimation;
class QParallelAnimationGroup;
QT_END_NAMESPACE

namespace Ui {

class CommonButton : public AbstractButton {
 public:
  explicit CommonButton(QWidget *parent = nullptr);
  explicit CommonButton(const QImage &image, QWidget *parent = nullptr);
  explicit CommonButton(const QString &image_path, QWidget *parent = nullptr);
  explicit CommonButton(const QImage &normal_image, const QImage &entry_image, QWidget *parent = nullptr);
  explicit CommonButton(const QString &normal_image_path, const QString &entry_image_path, QWidget *parent = nullptr);
  ~CommonButton();
protected:
  void paintEvent(QPaintEvent *event) override;

};


//class ConnerButton : public QWidget {
class ConnerButton : public AbstractButton {
  Q_OBJECT
  Q_PROPERTY(QRectF rect READ rect WRITE setRect)
  Q_PROPERTY(qint16 font READ fontSize WRITE setFontSize)

 public:
  explicit ConnerButton(QWidget *parent = nullptr);
  explicit ConnerButton(const QString &normal_image_path, const QString &entry_image_path, QWidget *parent = nullptr);
  explicit ConnerButton(const QImage &normal_image_path, const QImage &entry_image_path, QWidget *parent = nullptr);

  QString connerText() const;
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


class WordsButton : public AbstractButton {
  // class WordsButton : public CommonButton {
 public:
  WordsButton(const QString &text, QWidget *parent = nullptr);
  WordsButton(const QImage &image, const QString &text, QWidget *parent = nullptr);
  WordsButton(const QString &normal_image_path, const QString &entry_image_path, const QString &text, QWidget *parent = nullptr);
  ~WordsButton();

  QString bottomText() const;
  void setBottomText(const QString &text);

  QSize imageSize() const;
  void setImageSize(qreal w, qreal h);

  /// @brief 是否禁用角标
  /// @return true - yes
  [[nodiscard]] bool isConnerEnable() const;
  void setConnerEnable(bool enable = false);



 protected:
  void paintEvent(QPaintEvent *event) override;
  void enterEvent(QEnterEvent *event) override;
  void leaveEvent(QEvent *event) override;

 private:
  QSize image_size_;
  QSize words_size_;

  QString bottom_words_;

  bool is_conner_enable_ = false;
  // ConnerButton* test;
  AbstractButton *cooperate_btn_;



};

}  // namespace Ui


#endif  // UI_WIDGETS_BUTTONS_H
