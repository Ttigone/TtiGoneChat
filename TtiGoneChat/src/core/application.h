#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <set>
#include <map>

#include "window/controller.h"


namespace Window {
class Controller;
}  // namespace Window

namespace Lang {
class Translator;
}  // namespace Lang

namespace Local {
class Session;
class Account;
class Domain;
} // namespace Local

namespace Media {
namespace View {
class OverlayWidget;
}  // namespace View
}  // namespace Media

namespace Core {

class Settings;
class Tray;

enum class LaunchState {
  Running,
  RequestedQuit,
  ProcessedQuit,
};

enum class QuitReason {
  Default,
  QtQuitEvent,
};

class Application final : public QObject {
 public:
  Application();
  Application(const Application &other) = delete;
  Application &operator=(const Application &other) = delete;
  ~Application();

  void run();


  [[nodiscard]] Tray &tray() const;

  bool hasActiveWindow(Local::Session *session) const;

  [[nodiscard]] Window::Controller *findWindow(QWidget *widget) const;
  [[nodiscard]] Window::Controller *activeWindow() const;
  [[nodiscard]] Window::Controller *activePrimaryWindow() const;

  /// @brief 异步关闭最后一个窗口
  [[nodiscard]] bool closeNonLastAsync(Window::Controller *window);
  void closeWindow(Window::Controller *window);
  void windowActived(Window::Controller *window);

  bool closeActiveWindow();
  bool minimizeActiveWindow();

  /// @brief 触发活动窗口最大化
  bool toggleActiveWindowMaximized();

  /// @brief 关闭特定的聊天记录窗口
  void closeChatFromWindows();

  /// @brief 登出
  void logout(Local::Account *account = nullptr);

  /// @brief 有检查的登出
  void logoutWidthChecks(Local::Account *account = nullptr);

  /// @brief 强制登出
  void forceLogout(Local::Account *account, const QString text);

  /// @brief 检查本地时间
  void checkLocalTime();

  /// @brief 密码锁住
  void lockByPasscode();

  /// @brief 可能被密码锁住
  void maybeLockByPasscode();

  /// @brief 解锁
  void unlockByPasscode();

  [[nodiscard]] bool passcodeLocked() const;

  /// @brief 阻止强制退出
  [[nodiscard]] bool preventsQuit(QuitReason reason);

  /// @brief 保留注册的离开订阅组
  void registerLeaveSubscription(QWidget *widget);

  /// @brief 取消注册并且离开订阅者
  void unregisterLeaveSubscription(QWidget *widget);

  void refreshGlobalProxy();
  void refreshApplicationIcon();

  /// @brief 停止先前的已经完成的任务
  void qutiPreventFinished();

  /// @brief 处理 app 是否活跃
  void handleApplicationActived();

  /// @brief 处理 app 不活跃
  void handleApplicationDeactived();

  /// @brief 不活跃的原因
  [[nodiscard]] bool appDeactivatedValue() const;

  void preventOrInvoke();

  /// @brief 设置屏幕是否锁住
  void setScreenIsLocked(bool locked);
  bool scrrenIsLocked() const;

  /// @brief 开启设置和背景
  void startSettingsAndBackground();
  /// @return 设置属性
  [[nodiscard]] Settings &settings();
  [[nodiscard]] const Settings &settings() const;
  /// @brief 在 延迟时间段 后保留设置
  void saveSettingsDelayed();
  void saveSettings();

  [[nodiscard]] Local::Domain &domain() const;

 protected:
  /// @brief 事件过滤器
  bool eventFilter(QObject *watched, QEvent *event) override;

 private:
  friend Application &App();
  friend bool IsAppLaunched();

  /// @brief 本地存储
  void startLocalStorage();

  /// @brief 快捷
  void startShortcuts();

  /// @brief
  void startDomain();

  /// @brief 打开中间层界面
  void startMediaView();

  /// @brief 更新窗口标题
  void updateWindowTitles();

  /// @brief 设置最新活动的窗口
  void setLastActiveWindow(Window::Controller *window);

  /// @brief 展示用户
  void showAccount(Local::Account *account);

  /// @brief 尝试退出
  friend void AttemptQuit();
  /// @brief 准备退出
  [[nodiscard]] bool readyToQuit();
  /// @brief 延迟退出
  void delayedQuit();

  void processCreateWindow(Window::Controller *window);

  /// 单例模式
  static Application *instance_;

  struct InstanceGuard {
    InstanceGuard(Application *instance) { instance_ = instance; }
		//~InstanceGuard() { delete instance_; }
	};
  InstanceGuard instance_guard_{this};

  struct Private;
  const std::unique_ptr<Private> private_;
  // 翻译
  std::unique_ptr<Lang::Translator> translator_;

  // 窗口管理  账户 和  窗口对应
  std::map<Local::Account *, std::unique_ptr<Window::Controller>>
      primary_windows_;

  // 异步关闭窗口
  std::set<Window::Controller *> closing_async_windows_;

  // 次级窗口
  // std::map<History *, std::unique_ptr<Window::Controller>>
  // secondary_windows_;

  // 窗口数组
  std::vector<Window::Controller *> window_stack_;
  // 最新活动的 窗口
  Window::Controller *last_active_window_ = nullptr;
  // 最新活动的 主要窗口
  Window::Controller *last_active_primary_window_ = nullptr;
  // 处于设置的窗口
  Window::Controller *window_in_settings_ = nullptr;

  std::unique_ptr<Media::View::OverlayWidget> media_view_;
  //Media::View::OverlayWidget *media_view_;

  bool passcodeLock;
  bool screen_locked_ = false;

  const std::unique_ptr<Tray> tray_;

  std::unique_ptr<Local::Domain> domain_;
};

[[nodiscard]] Application &App();
[[nodiscard]] bool IsAppLaunched();

void SetLaunchState(LaunchState state);
[[nodiscard]] LaunchState CurrentLaunchState();

void Quit(QuitReason reason = QuitReason::Default);
[[nodiscard]] bool Quitting();

void Restart();

}  // namespace Core
	
#endif // APPLICATION_H
