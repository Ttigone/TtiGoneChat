/*****************************************************************//**
 * \file   mb_window.h
 * \brief  最底层的窗口类
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef MB_WINDOW_H
#define MB_WINDOW_H

//#include "config.h"

#include <QVBoxLayout>
#include <QWidget>

#include "base/basic_types.h"

namespace Layout
{
class VerticalLayout;
} // namespace Layout

namespace QWK
{
class WidgetWindowAgent;
} // namespace QWK

// 附带自定义的窗口标题栏
namespace Ui {
class MbWindow : public QWidget {
  Q_OBJECT
 public:
  explicit MbWindow(QWidget *parent = nullptr);
  virtual ~MbWindow();

  /// @brief 设置窗口内容
  /// @param w 设置需要展示的窗口
  void setContentWidget(QWidget *w);

  void setTitle(const QString &title);
  void setMinimumSize(int w, int h);
  void setMinimumSize(QSize size);

  void setFixedSize(QSize size);
  void setGeometry(QRect rect);
  //void showFullScreen();
  //void showNormal();
  //void close();

 private:
  void installWindowAgent();
  bool checkLayout(const QString &widget_name);

  QWK::WidgetWindowAgent *agent_;
  /// @brief 主界面布局
  QVBoxLayout *layout_ = nullptr;

  QWidget* central_widget = nullptr;
  Layout::VerticalLayout *central_widget_layout_ = nullptr;
  //QVBoxLayout *central_widget_layout_ = nullptr;
  /// @brief 布局中的控件数量
  int16 count_layout_item = 0;


};

}  // namespace Ui


#endif  // MB_WINDOW_H
