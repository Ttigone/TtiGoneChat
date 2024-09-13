#include "window/window_stack.h"

#include <memory>

namespace Window {

MediaStackWidget::MediaStackWidget() : stack_widget_(std::make_unique<QStackedWidget>(nullptr)) {
  
}

MediaStackWidget::~MediaStackWidget() = default;

QStackedWidget* MediaStackWidget::body() const {
  return stack_widget_.get();
  //return stack_widget_;
}

void MediaStackWidget::addWidget(int uid, QWidget *w) {
  // 不存在 
  if (uid_map_.find(uid) == uid_map_.end()) {
    stack_widget_->insertWidget(uid_map_.size(), w);
    uid_map_[uid] = uid_map_.size();
  }
}

void MediaStackWidget::deleteWidget(int uid) {
  // 没有找到
  if (uid_map_.find(uid) == uid_map_.end()) {
    return;
  } else {
    QWidget* widget = stack_widget_->widget(uid_map_[uid]);
    if (widget) {
      stack_widget_->removeWidget(widget);
      delete widget;
    }
  }
}


}  // namespace Window
