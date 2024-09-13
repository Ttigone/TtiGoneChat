#ifndef UI_MESSAGE_BUBBLE_H
#define UI_MESSAGE_BUBBLE_H

#include "data/data_talk.h"

#include <QFrame>
#include <QTextEdit>

namespace Data {
class TalkPropertyData;
}  // namespace Data

namespace Ui {

constexpr int width_draw = 8;

class BubbleFrame : public QFrame {
//class BubbleFrame : public QWidget {
  Q_OBJECT

 public:
  BubbleFrame(Data::TalkPropertyData role, QWidget* parent);
  void setWidget(QWidget* widget);

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  /// @brief 初始化操作
  void init();
  /// @brief 设置用户名
  /// @param name 名
  void setUserName(const QString& name);

  Data::TalkPropertyData role_;
  QVBoxLayout* layout_ = nullptr;
  // 是否需要名字
  bool need_name_ = true;
  QLabel* name_label_;
  QString name_;

  // 最底下的多样化窗口
  std::shared_ptr<QWidget> diversification_window_;
};

class TextBubble : public BubbleFrame {
  Q_OBJECT
 public:
  TextBubble(Data::TalkPropertyData role, const QString& text,
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

class PictureBubble : public BubbleFrame {
  Q_OBJECT
 public:
  PictureBubble(const QPixmap& picture, Data::TalkPropertyData role,
                QWidget* parent = nullptr);

private:
  /// @brief 初始化操作
  void init();
};
}  // namespace Ui

#endif  // MESSAGE_BUBBLE_H
