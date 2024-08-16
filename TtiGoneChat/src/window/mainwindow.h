#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui/widgets/self_window.h"
#include "core/settings.h"

namespace Core
{
struct WindowPosition;
enum class QuitReason;
} // namespace Core



namespace Window {

class Controller;
class SessionController;

class MainWindow : public Ui::SelfWindow {
 public:
  explicit MainWindow(Window::Controller* controller);
  virtual ~MainWindow();


  void showSettings();

  [[nodiscard]] bool isPrimary() const;
  [[nodiscard]] Window::Controller &controller() const;
  [[nodiscard]] SessionController* sessionController() const;

  bool hideNoQuit();
  void active();

  void init();

  void updateIsActive();

  [[nodiscard]] bool isActive() const;

  bool positionInited() const;

  void positionUpdated();

  void showRightColumn(QWidget *widget);

  void clearWidgets();

  void updateGlobalMenu();


  void setupPasscodeLock();
  void clearPasscodeLock();

  void firstShow();


  /// @brief 最小化托盘
  bool minimizeToTray();

  [[nodiscard]] Core::WindowPosition initialPosition() const;
  /// 
  /// @param primary 是否为主窗口
  /// @return 窗口位置
  [[nodiscard]] Core::WindowPosition initialNextPosition(bool primary) const;

  [[nodiscard]] QRect countInitialGeometry(Core::WindowPosition position,
                                           Core::WindowPosition initial,
                                           QSize min_size) const;

 protected:
  void leaveEvent(QEvent* event) override;
  void savePosition(Qt::WindowState state = Qt::WindowActive);
  void handleStateChanged(Qt::WindowState state);
  void handleActiveChanged();
  void handleVisibleChanged(bool visible);

  /// @brief 初始化钩子
  virtual void initHook() {}
  /// @brief 处理状态改变钩子
  virtual void handleVisibleChangedHook(bool visible) {}
  /// @brief 清理窗口钩子
  virtual void clearWidgetHook() {}
  /// @brief 状态改变钩子
  virtual void stateChangedHook(Qt::WindowState state) {}

  /// @brief 未处理消息数改变钩子
  virtual void unreadCounterChangedHook() {}
  /// @brief 关闭窗口，但不销毁, 隐藏
  virtual void closeWithoutDestory();
  /// @brief 更细全局菜单钩子
  virtual void updateGlobalMenuHook() {}
  /// @brief 更新工作模式
  virtual void workModeUpdated(Core::Settings::WorkMode mode) {}
  /// @brief 创建全局菜单
  virtual void createGloablMenu() {}
  /// @brief 从系统初始化几何形状
  virtual bool initGeometryFromSystem() { return false; }

 private:
  /// @brief 更新最小尺寸
  void updateMiniSize();

  [[nodiscard]] QRect countInitialGeometry(Core::WindowPosition position) const;

  //QWK::WidgetWindowAgen* window_agent_;

  Window::Controller* controller_;
  std::unique_ptr<SessionController> session_controller_;

  bool position_inited_ = false;
  bool is_active_ = false;
};

}  // namespace Window


#endif // MAINWINDOW_H
