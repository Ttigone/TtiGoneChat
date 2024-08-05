#include "ui/controls/common_button.h"

#include <QMouseEvent>
#include <QPainter>


namespace Ui {
CommonButton::CommonButton(QWidget* parent) : QWidget(parent)
{ initialSize(30, 30); }

CommonButton::CommonButton(const QImage& image, QWidget* parent) :
  CommonButton(parent)
{
}

CommonButton::CommonButton(const QString& image_path, QWidget* parent)
    : CommonButton(parent) {
  image_ = QImage(image_path);
}

CommonButton::~CommonButton() {}

QImage CommonButton::image() const {
  if (!image_.isNull()) {
    return image_;
  }
  return QImage();
}

void CommonButton::setImage(const QImage &image)
{ image_ = image; }

void CommonButton::setImage(const QString& image_path) {
  if (image_path.isEmpty()) {
    return;
  }
  // 不存在图像
  if (QImage(image_path).isNull()) {
    qWarning() << "no image" << __LINE__;
    return;
  }
  image_ = QImage(image_path);
}

void CommonButton::paintEvent(QPaintEvent* event) {
  QWidget::paintEvent(event);
  if (image_.isNull()) {
    return;
  }
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

  image_rect_ = QRectF(0, 0, this->width(), this->height());

  // painter.drawImage(rect,
  //                   image_.scaled(rect.size().toSize(), Qt::KeepAspectRatio,
  //                                 Qt::SmoothTransformation));

  painter.drawImage(
      image_rect_, image_.scaled(image_rect_.size().toSize(), Qt::KeepAspectRatio,
                               Qt::SmoothTransformation));
}

void CommonButton::enterEvent(QEnterEvent* event)
{
  mouse_is_inside_ = true;
  setStyleSheet("background-color: rgba(255, 255, 255, 15%)");
	QWidget::enterEvent(event);
}

void CommonButton::leaveEvent(QEvent* event)
{
  mouse_is_inside_ = false;
  setStyleSheet("");
	QWidget::leaveEvent(event);
}

void CommonButton::mouseMoveEvent(QMouseEvent* event)
{
	QWidget::mouseMoveEvent(event);
}

void CommonButton::mousePressEvent(QMouseEvent* event)
{
  if (event->button() == Qt::LeftButton)
  {
    setStyleSheet("background-color: rgba(255, 255, 255, 20%)");
  }
	QWidget::mousePressEvent(event);
}

void CommonButton::mouseReleaseEvent(QMouseEvent* event)
{
  if (event->button() == Qt::LeftButton)
  {
  setStyleSheet("background-color: rgba(255, 255, 255, 15%)");
  }
	QWidget::mouseReleaseEvent(event);
}

void CommonButton::initialSize(int w, int h) { this->setMaximumSize(w, h); }
}  // namespace Ui
