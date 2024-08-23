#ifndef MESSAGE_BUBBLE_H
#define MESSAGE_BUBBLE_H

#include "data/data_talk.h"

#include <QFrame>
#include <QTextEdit>

namespace Data {
class TalkData;
}  // namespace Data

namespace Ui {

constexpr int width_draw = 8;

class BubbleFrame : public QFrame {
  Q_OBJECT

 public:
  BubbleFrame(Data::TalkData role, QWidget* parent);
  void setMargin(int margin);
  void setWidget(QWidget* widget);

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  QHBoxLayout* layout_ = nullptr;
  Data::TalkData role_;
  int margin_;
};

class TextBubble : public BubbleFrame {
  Q_OBJECT
 public:
  TextBubble(Data::TalkData role, const QString& text,
             QWidget* parent = nullptr);

 protected:
  bool eventFilter(QObject* watched, QEvent* event) override;

 private:
  /// @brief 初始化操作
  void init(const QString& text);
  /// @brief 调整文本高度
  void adjustTextHeight();
  /// @brief 设置文本
  /// @param text 文本内容
  void setPlainText(const QString& text);

  QTextEdit* text_edit_;
};

}  // namespace Ui

#endif  // MESSAGE_BUBBLE_H
