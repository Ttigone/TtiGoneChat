#ifndef SANDBOX_H
#define SANDBOX_H

#include "application.h"

#include <QApplication>
#include <QAbstractNativeEventFilter>

namespace Core {
class SandBox final : public QApplication, private QAbstractNativeEventFilter {
 public:
  SandBox(int &argc, char **argv);

  SandBox(const SandBox &other) = delete;
  SandBox &operator=(const SandBox &other) = delete;

  int start();

  // 重写事件处理逻辑
  bool notify(QObject *receiver, QEvent *e) override;

  // 单例
  static SandBox &Instance() {
    // 返回 sandBox Qt 实例
    return *static_cast<SandBox *>(QCoreApplication::instance());
  }

  /// @brief 被启动后 停止
  static void QuitWhenStarted();

  ~SandBox();

 protected:
  bool event(QEvent *e) override;

 private:
  /// 
  /// @param receiver 目标接收对象
  /// @param e 事件类型
  /// @return 
  bool notifyOrInvoke(QObject *receiver, QEvent *e);

  bool nativeEventFilter(const QByteArray &eventType, void *message,
                         qintptr *result) override;

  ///
  /// @brief singleInstanceChecked
  /// 单例登录检查无误
  void singleInstanceChecked();

  ///
  /// @brief launchApplication
  /// 登录 app
  void launchApplication();

  ///
  /// @brief closeApplication
  /// 关闭 app
  void closeApplication();

  ///
  /// @brief checkForQuit
  /// 检查暂停标志
  void checkForQuit();

  ///
  /// @brief setupScreenScale
  /// 设置 屏幕 规模
  void setupScreenScale();

 private:
  QEventLoopLocker event_loop_locker_;
  const Qt::HANDLE main_thread_id_ = nullptr;
  // std::unique_lock<
  std::unique_ptr<Application> application_;

  bool started_ = false;
  static bool quit_when_started__request;
};

} // namespace Core



#endif // SANDBOX_H
