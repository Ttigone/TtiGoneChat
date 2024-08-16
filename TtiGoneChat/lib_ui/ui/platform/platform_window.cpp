#include "ui/platform/platform_window.h"

#include "ui/mb_widget.h"

namespace Ui {
namespace Platform {
BasicWindowHelper::BasicWindowHelper(not_null<MbWidget*> window)
    : window_(window) {
  window_->setWindowFlag(Qt::Window);
}

BasicWindowHelper::~BasicWindowHelper() {}

void BasicWindowHelper::initInWindow(not_null<MbWidget*> window) {}

not_null<MbWidget*> BasicWindowHelper::body() { return window_; }

QMargins BasicWindowHelper::frameMargins() { return nativeFrameMargins(); }

int BasicWindowHelper::addtionalContenPadding() const { return 0; }

void BasicWindowHelper::setTitle(const QString& title)
{
  window_->setWindowTitle(title);
}

void BasicWindowHelper::setNativeFrame(bool enable)
{
}

void BasicWindowHelper::setMinimumSize(QSize size)
{
  window_->setMinimumSize(size);
}

void BasicWindowHelper::setFixedSize(QSize size)
{
  window_->setFixedSize(size);
}

void BasicWindowHelper::setGeometry(QRect rect)
{
  window_->setGeometry(rect);
}

void BasicWindowHelper::showFullScreen()
{
  window_->showFullScreen();
}

void BasicWindowHelper::showNormal()
{
  window_->showNormal();
}

void BasicWindowHelper::close() {}

QMargins BasicWindowHelper::nativeFrameMargins() const {
  const auto inner = window()->geometry();
  const auto outer = window()->frameGeometry();
  return QMargins(inner.x() - outer.x(), inner.y() - outer.y(),
                  outer.x() + outer.width() - inner.x() - inner.width(),
                  outer.y() + outer.height() - inner.y() - inner.height());
}

void BasicWindowHelper::setupBodyTitleAreaEvents() {}

std::unique_ptr<BasicWindowHelper> CreateSpecialBasicWindowHelper(
    not_null<MbWidget*> window) {
  return std::make_unique<BasicWindowHelper>(window);
}
}  // namespace Platform
}  // namespace Ui