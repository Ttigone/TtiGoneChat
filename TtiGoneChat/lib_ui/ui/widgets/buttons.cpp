﻿#include "ui/widgets/buttons.h"

#include "ui/abstract_button.h"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QMouseEvent>
#include <QPixmap>

namespace Ui {
CommonButton::CommonButton(QWidget* parent) : AbstractButton(parent) {
  // this->setStyleSheet("background-color:Coral");
}

CommonButton::CommonButton(const QImage& image, QWidget* parent)
    : AbstractButton(image, parent) {
  // this->setStyleSheet("background-color:Coral");
}

CommonButton::CommonButton(const QString& image_path, QWidget* parent)
    : AbstractButton(image_path, parent) {
  // this->setStyleSheet("background-color:Coral");
}

CommonButton::CommonButton(const QImage& normal_image,
                           const QImage& entry_image, QWidget* parent)
    : AbstractButton(normal_image, entry_image, parent) {
  // this->setStyleSheet("background-color:Coral");
}

CommonButton::CommonButton(const QString& normal_image_path,
                           const QString& entry_image_path, QWidget* parent)
    : AbstractButton(normal_image_path, entry_image_path, parent) {
  // this->setStyleSheet("background-color:Coral");
  // qDebug() << image().at(0) << image().at(1);
}

CommonButton::~CommonButton() {}

void CommonButton::paintEvent(QPaintEvent* event) {
  QRectF rect(0, 0, this->width(), this->height());
  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

  auto img = isHover() ? getImage().at(1) : getImage().at(0);

  auto test_ = QPixmap::fromImage(img);
  painter.drawPixmap(rect.toRect(),
      test_.scaled(rect.size().toSize(), Qt::KeepAspectRatio,
                   Qt::SmoothTransformation));

  //painter.drawImage(rect, img.scaled(rect.size().toSize(), Qt::KeepAspectRatio,
  //                                   Qt::SmoothTransformation));

  AbstractButton::paintEvent(event);
}

// ConnerButton::ConnerButton(QWidget *parent) : QWidget(parent) {
ConnerButton::ConnerButton(QWidget* parent) : AbstractButton(parent) {
  setFixedSize(40, 40);
  conner_rect_ = QRectF(this->width() - icon_rect_.x() - 22, icon_rect_.y(), 18,
                        12);  // 留出一点边距，防止图像紧贴边缘
  conner_rect_w = 18, conner_rect_h = 12;

  conner_font_.setFamily("Arial");
  conner_font_.setBold(true);

  // font_size_ = 7;
  // font_begin_size_ = 7;
  // font_end_size_ = 9;

  setMouseTracking(true);
  conner_rect_animation_ = new QPropertyAnimation(this, "rect");
  // font_animation_ = new QPropertyAnimation(this, "font");
  // 持续 200 ms
  conner_rect_animation_->setDuration(100);
  // font_animation_->setDuration(50);

  animation_group_ = new QParallelAnimationGroup(this);
  animation_group_->addAnimation(conner_rect_animation_);
  // animation_group_->addAnimation(font_animation_);
}

ConnerButton::ConnerButton(const QString& normal_image_path,
                           const QString& entry_image_path, QWidget* parent)
    : ConnerButton(parent) {
  setImage(normal_image_path, entry_image_path);
}

ConnerButton::ConnerButton(const QImage& normal_image,
                           const QImage& entry_image, QWidget* parent)
    : ConnerButton(parent) {
  setImage(normal_image, entry_image);
}

QString ConnerButton::connerText() const { return text_; }

void ConnerButton::setConnerText(const QString& new_text) {
  if (text_ != new_text) {
    text_ = new_text;
    update();
  }
}

QRectF ConnerButton::rect() const { return conner_rect_; }

void ConnerButton::setRect(const QRectF& rect) {
  conner_rect_ = rect;
  update();
}

qint16 ConnerButton::fontSize() const { return font_size_; }

void ConnerButton::setFontSize(const qint16& font_size) {
  // qDebug() << "Get" << font_size;
  font_size_ = font_size;
  update();
}

void ConnerButton::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event);
  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

  // 加载和绘制图像

  // QSvgRenderer svgRenderer(QString("C:/Users/cssss/Downloads/chat-3-fill
  // (1).svg")); svgRenderer.render(&painter, iconRect);

  // QString imagePath = is_hovering_image_ ?
  // "C:/Users/cssss/Downloads/chat-hover.svg" :
  // "C:/Users/cssss/Downloads/chat-normal.svg";
  // QString imagePath = is_hovering_ ?
  // "C:/Users/cssss/Downloads/chat-hover.svg"
  //: "C:/Users/cssss/Downloads/chat-normal.svg";
  // QImage image(imagePath);
  // painter.drawImage(
  //     icon_rect_, image.scaled(icon_rect_.size().toSize(),
  //     Qt::KeepAspectRatio,
  //                              Qt::SmoothTransformation));
  // qDebug() << isHover();
  // auto img = isHover() ? image().at(1) : image().at(0);
  auto img = is_hovering_ ? getImage().at(1) : getImage().at(0);
  auto test_ = QPixmap::fromImage(img);
  painter.drawPixmap(
      icon_rect_.toRect(),
      test_.scaled(icon_rect_.size().toSize(), Qt::KeepAspectRatio,
                   Qt::SmoothTransformation));

  // conner_rect_ = QRectF(rect.width() - icon_Rect_.x() - 18, icon_Rect_.y(),
  // 18, 14); // 留出一点边距，防止图像紧贴边缘
  qreal radius = 6;  // 圆角半径
  if (conner_rect_.width() > this->width() / 2) {
    radius = 8;
  } else {
    radius = 6;
  }

  // 底色
  QBrush brush(QColor("#6f6f6f"));
  painter.setBrush(brush);
  painter.setPen(Qt::NoPen);  // 无边框

  // 绘制矩形
  // qDebug() << conner_rect_;
  painter.drawRoundedRect(conner_rect_, radius, radius);

  QPen textPen(QColor("#c4c4c4"));
  painter.setPen(textPen);
  // 绘制文本
  // QString text = "+99";
  // qDebug() << ++i;
  // 7 - 9
  // QFont font("Arial", font_begin_size_, QFont::Bold); // 设置字体
  // qDebug() << font_size_;
  // QFont font("Arial", font_size_, QFont::Bold); // 设置字体
  conner_font_.setPixelSize(9);
  // QFont font("Arial", 7, QFont::Bold); // 设置字体
  // QFont font("Arial", 7, QFont::Bold); // 设置字体
  painter.setFont(conner_font_);
  // 计算文本的绘制位置
  painter.drawText(conner_rect_, Qt::AlignCenter, text_);
  AbstractButton::paintEvent(event);
}

void ConnerButton::enterEvent(QEnterEvent* event) {
  Q_UNUSED(event);
  is_hovering_ = true;
  // qDebug() << "e";
  update();
}

void ConnerButton::leaveEvent(QEvent* event) {
  is_hovering_ = false;
  is_hovering_image_ = false;
  // qDebug() << "l";
  // if (conner_rect_.width() > 18) {
  //     animation_->setStartValue(conner_rect_);
  //     animation_->setEndValue(QRectF(conner_rect_.x() + 4, conner_rect_.y() +
  //     4, conner_rect_.width() - 8, conner_rect_.height() - 8));
  //     animation_->start();
  // }
  // if (animation_->state() == QPropertyAnimation::Running) {
  //     // qDebug() << ++i;
  //     // qDebug() << "CC";
  //     animation_->setStartValue(conner_rect_);
  //     animation_->setEndValue(QRectF(conner_rect_.x() + 2, conner_rect_.y() +
  //     2, conner_rect_.width() - 6, conner_rect_.height() - 6));
  //     animation_->start();
  // }
  update();
}

void ConnerButton::mouseMoveEvent(QMouseEvent* event) {
  // qDebug() << this->width();
  // QRectF iconRect(2, 6, 30, 30); // 图像区域
  // 处于图像区域
  if (icon_rect_.contains(event->pos())) {
    if (!is_hovering_image_) {
      is_hovering_image_ = true;
      update();
    }
  } else {
    if (is_hovering_image_) {
      is_hovering_image_ = false;
      update();
    }
  }
  // qDebug() << font_animation_->state();
  auto offset = zoom_radio_ * width();
  if (conner_rect_.contains(event->pos())) {
    // qDebug() << "TEST";
    // qDebug() << conner_rect_;
    if (conner_rect_.width() < (conner_rect_w + offset * 3)) {
      // if ((conner_rect_animation_->state() != QPropertyAnimation::Running) &&
      // (font_animation_->state() != QPropertyAnimation::Running)) {
      if (animation_group_->state() != QPropertyAnimation::Running) {
        // qDebug() << ++i;
        conner_rect_animation_->setStartValue(conner_rect_);
        conner_rect_animation_->setEndValue(
            QRectF(conner_rect_.x() - offset, conner_rect_.y() - offset,
                   conner_rect_.width() + offset * 3,
                   conner_rect_.height() + offset * 3));

        // 字体变大 7 - 9
        // qDebug() << "out: " << font_size_;
        // font_animation_->setStartValue(font_size_);
        // font_animation_->setEndValue(font_size_ + 2);
        // font_animation_->setEasingCurve(QEasingCurve::Linear);
        // font_animation_->start();
        // conner_rect_animation_->start();
        animation_group_->start();
      }
    }
  } else {
    if (conner_rect_.width() > conner_rect_w) {
      // if ((conner_rect_animation_->state() != QPropertyAnimation::Running) &&
      // (font_animation_->state() != QPropertyAnimation::Running)) {
      if (animation_group_->state() != QPropertyAnimation::Running) {
        // qDebug() << ++i;
        conner_rect_animation_->setStartValue(conner_rect_);
        conner_rect_animation_->setEndValue(
            QRectF(conner_rect_.x() + offset, conner_rect_.y() + offset,
                   conner_rect_.width() - offset * 3,
                   conner_rect_.height() - offset * 3));

        // qDebug() << font_begin_size_;
        // qDebug() << "In: " << font_size_;
        // font_animation_->setStartValue(font_size_);
        // font_animation_->setEndValue(font_size_ - 2);

        animation_group_->start();
      }
    }
  }
  QWidget::mouseMoveEvent(event);
}

WordsButton::WordsButton(const QString& text, QWidget* parent)
    : AbstractButton(parent), bottom_words_(text) {
  setFixedSize(40, 50);
  setImageSize(30, 30);
  words_size_ = QSize(40, 10);
}

WordsButton::WordsButton(const QImage& image, const QString& text,
                         QWidget* parent)
    //: AbstractButton(image, parent), bottom_words_(text)
    : WordsButton(text, parent) {
  setImage(image);
  if (!is_conner_enable_) {
    if (!getImage().empty()) {
      cooperate_btn_ =
          new CommonButton(getImage().at(0), getImage().at(1), this);
    }
  }
}

WordsButton::WordsButton(const QString& normal_image_path,
                         const QString& entry_image_path, const QString& text,
                         QWidget* parent)
    : WordsButton(text, parent) {
  setImage(normal_image_path, entry_image_path);
  if (!is_conner_enable_) {
    if (!getImage().empty()) {
      cooperate_btn_ =
          new CommonButton(getImage().at(0), getImage().at(1), this);
    }
  }
}

WordsButton::~WordsButton() {}

QString WordsButton::bottomText() const { return bottom_words_; }

void WordsButton::setBottomText(const QString& text) { bottom_words_ = text; }

QSize WordsButton::imageSize() const { return image_size_; }

void WordsButton::setImageSize(qreal w, qreal h) { image_size_ = QSize(w, h); }

bool WordsButton::isConnerEnable() const { return is_conner_enable_; }

void WordsButton::setConnerEnable(bool enable) {
  is_conner_enable_ = enable;
  // 启用角标
  if (enable) {
    // cooperate_btn_ = static_cast<ConnerButton *>(cooperate_btn_);
    cooperate_btn_->deleteLater();
    cooperate_btn_ = new ConnerButton(getImage().at(0), getImage().at(1), this);
  } else {
    cooperate_btn_->deleteLater();
    cooperate_btn_ = new CommonButton(getImage().at(0), this);
    // cooperate_btn_ = static_cast<CommonButton *>(cooperate_btn_);
  }
}

void WordsButton::paintEvent(QPaintEvent* event) {
  // if (image().isNull()) {
  //   return;
  // }
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

  QRectF rect;
  rect.setX(this->x());
  rect.setY(this->y());
  rect.setWidth(this->width() - 1);
  rect.setHeight(this->height() - 1);

  // QImage image(image_path);
  // qDebug() << "test";

  // image_rect_ = QRectF(0, 0, this->width(), this->height());
  setImageRect(0, 0, image_size_.width(), image_size_.height());

  // CommonButton::paintEvent(event);
  auto imgRet = imageRect();

  // auto img = isHover() ? image().at(1) : image().at(0);
  // painter.drawImage(
  //     imgRet, img.scaled(imgRet.size().toSize(), Qt::KeepAspectRatio,
  //                              Qt::SmoothTransformation));

  painter.setFont(QFont("Arial", 7));
  if (state() == StateFlag::Hover) {
    painter.setPen(QPen("#ffffff"));
  } else {
    painter.setPen(QPen("#a9beae"));
  }
  painter.drawText(QRect(this->x(), this->height() - 10, words_size_.width(),
                         words_size_.height()),
                   Qt::AlignCenter, bottom_words_);
  AbstractButton::paintEvent(event);
}

void WordsButton::enterEvent(QEnterEvent* event) {
  AbstractButton::enterEvent(event);
}

void WordsButton::leaveEvent(QEvent* event) {
  AbstractButton::leaveEvent(event);
}
}  // namespace Ui
