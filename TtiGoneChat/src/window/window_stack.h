/*****************************************************************//**
 * \file   window_stack.h
 * \brief  右侧栈窗口
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef WINDOW_STACK_H
#define WINDOW_STACK_H

#include "base/singleton.h"

#include <QStackedWidget>


namespace Window {

class MediaStackWidget final {
 public:
  MediaStackWidget();
  ~MediaStackWidget();

  QStackedWidget* body() const;

  /// @brief 添加窗口，并设置对应的  uid
  /// @param uid 特定标识符
  void addWidget(int uid, QWidget *w);

  /// @brief 删除窗口
  /// @param uid 特定标识符
  void deleteWidget(int uid);

 private:
  MediaStackWidget(const MediaStackWidget&) = delete;
  MediaStackWidget& operator=(const MediaStackWidget&) = delete;

  //QStackedWidget* stack_widget_;
  std::unique_ptr<QStackedWidget> stack_widget_;
  QMap<int, int> uid_map_;
};

}  // namespace Window

#endif  // WINDOW_STACK_H
