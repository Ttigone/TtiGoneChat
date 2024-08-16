#include "ui/platform/win/win_window.h"
#include "ui/widgets/mb_window.h"

#include "base/invoke_queued.h"

#include <QWindow>

#include <dwmapi.h>
#include <shellapi.h>
#include <uxtheme.h>
#include <windowsx.h>


namespace Ui
	{
namespace Platform {


class WindowHelper::NativeFilter final :  public QAbstractNativeEventFilter
{
public:
  void registerWindow(HWND handle, not_null<WindowHelper *> helper);
  void unregisterWindow(HWND handle);

  bool nativeEventFilter(const QByteArray &event_type, void *message,
                         qintptr *result) override;
private:
  std::map<HWND, not_null<WindowHelper *>> window_by_handle_;



};

bool WindowHelper::NativeFilter::nativeEventFilter(const QByteArray &event_type,
                                                   void *message,
                                                   qintptr *result) {
  auto filtered = false;
  const auto msg = reinterpret_cast<MSG *>(message);
  // 查找 窗口
  const auto i = window_by_handle_.find(msg->hwnd);
  if (i != window_by_handle_.end()) {
    // 主事件循环
  }
  return filtered;
}


WindowHelper::WindowHelper(not_null<MbWidget*> window)
    : BasicWindowHelper(window),
      handle_(ResolveWindowHandle(window)),
      body_(new MbWidget())
{
  //requires
	
}

WindowHelper::~WindowHelper()
{
}


HWND ResolveWindowHandle(not_null<QWidget *> widget)
{
	const auto result = GetWindowHandle(widget);
  return result;
}

HWND GetWindowHandle(not_null<QWidget*> widget) {
  const auto topLevel = widget->window();
  topLevel->createWinId();
  return GetWindowHandle(topLevel->windowHandle());
}

HWND GetWindowHandle(not_null<QWindow*> window) {
  return reinterpret_cast<HWND>(window->winId());
}

void SendWMPaintForce(not_null<QWidget*> widget) {
  const auto topLevel = widget->window();
  topLevel->createWinId();
  SendWMPaintForce(topLevel->windowHandle());
}

void SendWMPaintForce(not_null<QWindow*> window) {
  ::InvalidateRect(GetWindowHandle(window), nullptr, FALSE);
}




}  // namespace Platform
} // namespace Ui
