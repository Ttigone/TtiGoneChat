/*****************************************************************/ /**
 * \file   chat_item.h
 * \brief  
 * 
 * \author cssss
 * \date   August 2024
 *********************************************************************/

#ifndef UI_CHAT_ITEM_H
#define UI_CHAT_ITEM_H

#include <data/data_talk.h>

#include <QTextEdit>


namespace Data {}  // namespace Data

namespace Ui {
class ChatItemBase : public QWidget {
  Q_OBJECT
 public:
  explicit ChatItemBase(Data::TalkPropertyData role, QWidget* parent = nullptr);
  void setUserName(const QString& name);
  void setUserIcon(const QPixmap& icon);
  void setWidget(QWidget* w);



 private:
  /// @brief 初始化操作
  //void init(const QString &text);
  void init();

  Data::TalkPropertyData role_;
  QLabel* name_label_;
  QLabel* icon_label_;
  QWidget* bubble_;

  //QString text_;
  //QTextEdit* text_edit_;
};
}  // namespace Ui

#endif  // UI_CHAT_ITEM_H
