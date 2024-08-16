/*****************************************************************//**
 * \file   win_window.h
 * \brief  win ƽ̨
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef WIN_WINDOW_H
#define WIN_WINDOW_H

#include "ui/platform/platform_window.h"

#include <QAbstractNativeEventFilter>

namespace Ui {

namespace Platform {




class WindowHelper final : public BasicWindowHelper {
 public:
  explicit WindowHelper(not_null<MbWidget *> window);
  ~WindowHelper();

 private:

  class NativeFilter;
	  friend class NativeFilter;

  void init();
  void updateMargins();

  

  const HWND handle_ = nullptr;
  const not_null<MbWidget *> body_;
};

[[nodiscard]] HWND ResolveWindowHandle(not_null<QWidget *> widget);

[[nodiscard]] HWND GetWindowHandle(not_null<QWidget *> widget);
[[nodiscard]] HWND GetWindowHandle(not_null<QWindow *> window);

void SendWMPaintForce(not_null<QWidget *> widget);
void SendWMPaintForce(not_null<QWindow *> window);

}  // namespace Platform
}  // namespace Ui

#endif  // WIN_WINDOW_H
