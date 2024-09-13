/*****************************************************************/ /**
 * \file   history_widget.h
 * \brief  历史聊天界面
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef HSITORY_WIDGET_H
#define HSITORY_WIDGET_H

#include "ui/chat/message_bubble.h"

#include <QScrollArea>

namespace History {

class HistoryWidget : public QWidget {
 public:
  HistoryWidget(QWidget* parent = nullptr);

  void appendChatItem(QWidget* item);
  void insertChatItem();
  void removeAllItem();

 protected:
  bool eventFilter(QObject* object, QEvent* event) override;
  void paintEvent(QPaintEvent* event) override;

 private slots:
  void scrollBarMoved(int min, int max);

 private:
  void init();
  // 滚动区域 包含一个 widget(容纳 气泡)
  QScrollArea* scroll_area_;
  bool is_appended_;
};

}  // namespace History

#endif  // HSITORY_WIDGET_H
