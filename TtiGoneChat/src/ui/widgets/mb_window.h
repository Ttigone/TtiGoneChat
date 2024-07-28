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

namespace QWK
{
class WidgetWindowAgent;
}

// 附带自定义的窗口标题栏
namespace Ui {
class MbWindow : public QWidget {
  Q_OBJECT
 public:
  explicit MbWindow(QWidget *parent = nullptr);
  virtual ~MbWindow();

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

  QWK::WidgetWindowAgent *agent_;
  /// @brief 主界面布局
  QVBoxLayout *layout_ = nullptr;

};

}  // namespace Ui


#endif  // MB_WINDOW_H
