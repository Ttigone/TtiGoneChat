#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "window/mainwindow.h"

#include <QPointer>

class MainWidget;


namespace Window
{
	
} // namespace Window

// 继承自 window 目录下的 MainWindow 类
class MainWindow : public Window::MainWindow {
 public:
  explicit MainWindow(Window::Controller* controller);
  ~MainWindow();

  /// @brief 回调
  void preventOrInvoke(std::function<void()> callback);

  /// @brief 展示设置
  void showSettings();

  /// @brief 展示主菜单
  void showMainMenu();

  /// @brief 首次展示
  void finishFirstShow();

  MainWidget* sessionContent() const;

 protected:
  bool eventFilter(QObject* watched, QEvent* event) override;
  void closeEvent(QCloseEvent* event) override;

  // void initHook() override;

 private:
  /// @brief 应用初始工作模式
  void applyInitialWorkMode();

  std::unique_ptr<MainWidget>* main_ = nullptr;
};

#endif // MAIN_WINDOW_H
