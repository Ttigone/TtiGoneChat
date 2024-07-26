#include "sandbox.h"

#include <QDateTime>

#include "window/launcher.h"
#include "base/invoke_queued.h"

#include "core/application.h"

#include <QThread>
#include <QEvent>
#include <QWidget>
#include <QSessionManager>

namespace Window {
class Launcher;
} // namespace Window

namespace Core {

bool SandBox::quit_when_started__request = false;

SandBox::SandBox(int &argc, char **argv)
    : QApplication(argc, argv), main_thread_id_(QThread::currentThreadId()) {
  //qDebug() << "id :" << main_thread_id_;
}

int SandBox::start() {
  started_ = true;

	// 检查是否已经有实例在运行
  singleInstanceChecked();


   // 系统请求应用程序保存其状态时发出,
   // 通常发生在应用程序即将退出或会话即将结束
   connect(this, &QGuiApplication::saveStateRequest, [](auto &manager){
       // 会话管理器应用程序在会话结束后不应该被重启
       //可以用于确保应用程序在某些情况下（如更新或用户手动退出时）不会自动重启
       manager.setRestartHint(QSessionManager::RestartNever);
   });

	connect(this, &QCoreApplication::aboutToQuit, [=] {
    //qDebug() <<"CONECT\n";
    closeApplication();
  });


  if (quit_when_started__request)
  {
    closeApplication();
    return 0;
  }
  return exec();
}

bool SandBox::notifyOrInvoke(QObject *receiver, QEvent *e) {
  // sandbox 调用 app.run() 的事件类型
  if (e->type() == base::InvokeQueuedEvent::Type())
  {
    // 调用 lambda 函数
    //qDebug() << "113213123123TEST";
    static_cast<base::InvokeQueuedEvent *>(e)->invoke();
    return true;
  }
  return QApplication::notify(receiver, e);
}

// 会处理 显示窗口 的状态情况 e->type()
bool SandBox::notify(QObject *receiver, QEvent *e) {
  //qDebug() << QThread::currentThreadId();
  //int64 startTime = QDateTime::currentMSecsSinceEpoch();
  // 过滤事件 分别执行,  如果当前线程不是 主线程
  bool result;
  if (QThread::currentThread() != main_thread_id_) {
    result = notifyOrInvoke(receiver, e);
    return result;
  } else
  {
	  
  }
  //qint64 endTime = QDateTime::currentMSecsSinceEpoch();
  //qDebug() << "Event processing time for" << e->type() << ":"
  //         << (endTime - startTime) << "ms";
  return notifyOrInvoke(receiver, e);
}

void SandBox::QuitWhenStarted() {
  // 没有实例或者没有启动
  if (!QApplication::instance() || !Instance().started_) {
    quit_when_started__request = true;
    qDebug() << "11\n";
  } else
  {
    // 进来了
    qDebug() << "22\n";
    quit();
  }
}

SandBox::~SandBox() = default;

bool SandBox::event(QEvent *e) {
    //qDebug() << "TTTT";

  //qDebug() << "Event Type: " << e->type();
  if (e->type() == QEvent::Quit) {
    // return QCoreApplication::event(e);
    if (Quitting())
    {
      return QCoreApplication::event(e);
    } else
    {
			Quit(QuitReason::QtQuitEvent);
			e->ignore();
			// 继续传递事件 -- 父亲对象
			return false;
    }
  } else if (e->type() == QEvent::Close) {
    qDebug() << "Close Event";
    Quit();
  }
  
  return QApplication::event(e);
}

bool SandBox::nativeEventFilter(const QByteArray &eventType, void *message,
                                qintptr *result) {
  // 返回 false, 表示事件应继续传递
  // 当前的原生事件过滤器没有处理这个事件
  return false;
}

void SandBox::singleInstanceChecked() { launchApplication(); }

void SandBox::launchApplication() {
  // 向在  sandBox 的线程发送 application.run()
  InvokeQueued(this, [=] {
    // 即将暂停状态
    if (Quitting()) {
      quit();
    } else if (application_) {
     //qDebug() << "cacasdascacaccacacaca";
      return;
    }
    //qDebug() << "caicaicai";
    //qDebug() << QThread::currentThreadId();

    // 设置屏幕比例
    setupScreenScale();

    // 创造实例
    application_ = std::make_unique<Application>();

    // 安装原生事件过滤器
    installNativeEventFilter(this);

    // 运行 app
    application_->run();
  });
}

void SandBox::closeApplication() {
  // 处理关闭应用程序
  if (CurrentLaunchState() == LaunchState::ProcessedQuit) {
    return;
  }
  SetLaunchState(LaunchState::ProcessedQuit);

  application_ = nullptr;

  qDebug() << "true";

}

void SandBox::setupScreenScale() {}

}  // namespace Core
