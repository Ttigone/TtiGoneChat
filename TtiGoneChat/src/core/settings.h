#ifndef SETTINGS_H
#define SETTINGS_H

#include <QRect>
#include <QString>

namespace Core {

struct WindowPosition {
  WindowPosition(int maximize, int scale, int x, int y, int w, int h)
      : maximized(maximize), scale(scale), x(x), y(y), w(w), h(h) {}

  WindowPosition() = default;

  int maximized = 0;
  int scale = 0;
  int x = 0;
  int y = 0;
  int w = 0;
  int h = 0;

  [[nodiscard]] QRect rect() const { return QRect(x, y, w, h); }
};

[[nodiscard]] WindowPosition AdjustToScale(WindowPosition position,
                                           const QString &name);

struct WindowTitleContext {
#if __cplusplus >= 202002L
  bool hideChatName : 1 = false;
  bool hideAccountName : 1 = false;
  bool hideTotalUnread : 1 = false;
#elif __cplusplus >= 201703L
  bool hideChatName : 1;
  bool hideAccountName : 1;
  bool hideTotalUnread : 1;

  WindowTitleContext()
      : hideChatName(false), hideAccountName(false), hideTotalUnread(false) {}
#else
  bool hideChatName;
  bool hideAccountName;
  bool hideTotalUnread;
#endif
};

class Settings final {
 public:
  enum class ScreenCorner : uchar {
    TopLeft = 0,
    TopRight = 1,
    BottomLeft = 2,
    BottomRight = 3,
  };

  // 通知的界面
  enum class Notifyview : uchar {
    showPreview = 0,
    showName = 1,
    showNothing = 2,
  };

  enum class WorkMode {
    WindowAndTray = 0,
    TrayOnly = 1,
    WindowOnly = 2,
  };

  // 默认音频大小
  static constexpr auto default_volume = 0.8;

  Settings();
  ~Settings();

  [[nodiscard]] QString customFontFamily() const { return custom_font_family_; }
  void setCustomFontFamily(const QString &font_family) {
    custom_font_family_ = font_family;
  }

  [[nodiscard]] WorkMode workMode() const { return work_mode_; }
  void setWorkMode(const WorkMode &work_mode) { work_mode_ = work_mode; }

  [[nodiscard]] const WindowPosition &windowPosition() const {
    return window_position_;
  };
  void setwindowPosition(const WindowPosition &position) {
    window_position_ = position;
  }

 private:
  QString custom_font_family_;
  WorkMode work_mode_ = WorkMode::WindowAndTray;
  WindowPosition window_position_;
};

}  // namespace Core

#endif // SETTINGS_H
