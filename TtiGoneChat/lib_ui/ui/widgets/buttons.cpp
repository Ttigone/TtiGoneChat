#include "ui/widgets/buttons.h"

#include "ui/abstract_button.h"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QMouseEvent>
#include <QPixmap>

namespace Ui {
CommonButton::CommonButton(QWidget* parent) : AbstractButton(parent) {
}

CommonButton::CommonButton(const QImage& image, QWidget* parent)
    : AbstractButton(image, parent) {
}

CommonButton::CommonButton(const QString& image_path, QWidget* parent)
    : AbstractButton(image_path, parent) {
}

CommonButton::CommonButton(const QImage& normal_image,
                           const QImage& entry_image, QWidget* parent)
    : AbstractButton(normal_image, entry_image, parent) {
}

CommonButton::CommonButton(const int &w, const int &h, const QImage& normal_image,
                           const QImage& entry_image, QWidget* parent)
    : AbstractButton(w, h, normal_image, entry_image, parent) {
}

CommonButton::CommonButton(const QString& normal_image_path,
                           const QString& entry_image_path, QWidget* parent)
    : AbstractButton(normal_image_path, entry_image_path, parent) {
}

CommonButton::CommonButton(const int &w, const int &h, const QString& normal_image_path,
                           const QString& entry_image_path, QWidget* parent)
    : AbstractButton(w, h, normal_image_path, entry_image_path, parent) {
}

CommonButton::~CommonButton() {}

void CommonButton::paintEvent(QPaintEvent* event) {
  QRectF rect(0, 0, this->width(), this->height());
  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

  const auto img = isHover() ? getImage().at(1) : getImage().at(0);
  const auto &test_ = QPixmap::fromImage(img);
  painter.drawPixmap(rect.toRect(),
      test_.scaled(rect.size().toSize(), Qt::KeepAspectRatio,
                   Qt::SmoothTransformation));

  AbstractButton::paintEvent(event);
}

ConnerButton::ConnerButton(QWidget* parent) : AbstractButton(parent) {
  setFixedSize(40, 40);
  conner_rect_ = QRectF(this->width() - icon_rect_.x() - 22, icon_rect_.y(), 18,
                        12);  // 留出一点边距，防止图像紧贴边缘
  conner_rect_w = 18, conner_rect_h = 12;

  conner_font_.setFamily("Arial");
  conner_font_.setBold(true);

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

  const auto img = is_hovering_ ? getImage().at(1) : getImage().at(0);
  const auto test_ = QPixmap::fromImage(img);
  painter.drawPixmap(
      icon_rect_.toRect(),
      test_.scaled(icon_rect_.size().toSize(), Qt::KeepAspectRatio,
                   Qt::SmoothTransformation));

  // conner_rect_ = QRectF(rect.width() - icon_Rect_.x() - 18, icon_Rect_.y(),
  // 18, 14); // 留出一点边距，防止图像紧贴边缘
  const qreal radius = (conner_rect_.width() > this->width() / 2) ? 8 : 6;  // 圆角半径

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
  update();
}

void ConnerButton::mouseMoveEvent(QMouseEvent* event) {
  // qDebug() << this->width();
  // QRectF iconRect(2, 6, 30, 30); // 图像区域
  // 处于图像区域
  const bool was_hovering_image = is_hovering_image_;
	is_hovering_image_ = icon_rect_.contains(event->pos());
  if (was_hovering_image != is_hovering_image_) {
		update();
	}
  const auto offset = zoom_radio_ * width();
	const bool is_in_conner_rect = conner_rect_.contains(event->pos());
  // 放大
  const bool should_expand = is_in_conner_rect && conner_rect_.width() < (conner_rect_w + offset * 3);
  // 缩小
  const bool should_shrink = !is_in_conner_rect && conner_rect_.width() > conner_rect_w;

  // 有操作发生
  if ((should_expand || should_shrink) &&
      animation_group_->state() != QPropertyAnimation::Running) {
    conner_rect_animation_->setStartValue(conner_rect_);
    conner_rect_animation_->setEndValue(QRectF(
        conner_rect_.x() + (should_expand ? -offset : offset),
        conner_rect_.y() + (should_expand ? -offset : offset),
        conner_rect_.width() + (should_expand ? offset * 3 : -offset * 3),
        conner_rect_.height() + (should_expand ? offset * 3 : -offset * 3)));
    animation_group_->start();
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
    : WordsButton(text, parent) {
  setImage(image);
  if (!is_conner_enable_ && !getImage().empty()) {
    cooperate_btn_ = new CommonButton(getImage().at(0), getImage().at(1), this);
  }
}

WordsButton::WordsButton(const QString& normal_image_path,
                         const QString& entry_image_path, const QString& text,
                         QWidget* parent)
    : WordsButton(text, parent) {
  setImage(normal_image_path, entry_image_path);
  if (!is_conner_enable_ && !getImage().empty()) {
    cooperate_btn_ = new CommonButton(getImage().at(0), getImage().at(1), this);
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
  cooperate_btn_->deleteLater();
  cooperate_btn_ = enable ? static_cast<AbstractButton*>(new ConnerButton(
                                getImage().at(0), getImage().at(1), this))
                          : static_cast<AbstractButton*>(
                                new CommonButton(getImage().at(0), this));
}

void WordsButton::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

  QRectF rect(0, 0, this->width() - 1, this->height() - 1);
  setImageRect(0, 0, image_size_.width(), image_size_.height());

  painter.setFont(QFont("Arial", 7));
  painter.setPen(QPen(state() == StateFlag::Hover ? "#ffffff" : "a9beae"));
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
