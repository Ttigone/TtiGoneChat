/*****************************************************************//**
 * \file   overlay_widget.h
 * \brief  上层窗口(主界面)
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef OVERLAY_WIDGET_H
#define OVERLAY_WIDGET_H

#include <QWidget>

namespace Window
{
	class SideBar;
} // namespace Window 

namespace Media {

namespace View
{
class OverlayWidget final : public QWidget {
  Q_OBJECT
 public:
  explicit OverlayWidget(QWidget *parent = nullptr);
  ~OverlayWidget();

  //void hide();

 private:
   // 启动 opengl
  bool opengl_ = false;

  bool right_detial_visible_ = false;

  std::unique_ptr<Window::SideBar> side_bar_;


};

}  // namespace View

}  // namespace Media

#endif  // OVERLAY_WIDGET_H
