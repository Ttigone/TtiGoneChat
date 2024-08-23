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
#include <QHBoxLayout>

#include "ui/mb_widget.h"
#include "ui/widgets/mb_window.h"


namespace Layout
{
class HorizontalLayout;
} // namespace Layout

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

  enum class OverlayWidgetMode : uchar {
    SearchMode = 0x01,
		ChatMode,
    ContactMode,
  };
  // void hide();

 private:
  // 启动 opengl
  bool opengl_ = false;

  bool right_detial_visible_ = false;

  bool full_screen_inited_ = false;
  bool normal_geometry_inited_ = false;
  bool full_screen_ = false;

  OverlayWidgetMode mode_ = OverlayWidgetMode::ChatMode;
  OverlayWidgetMode state_ = OverlayWidgetMode::ChatMode;

  // const not_null<QWidget *> widget_;

  const not_null<Ui::MbWidget *> widget_;
  // QWidget * widget_;
  QHBoxLayout *main_layout_;
  // Layout::HorizontalLayout *main_layout_;

  std::unique_ptr<Window::SideBar> side_bar_;

  const not_null<Ui::MbWindow *> window_;
};

}  // namespace View

}  // namespace Media

#endif  // OVERLAY_WIDGET_H
