#include "main_window.h"

#include <qevent.h>

#include "main_widget.h"
#include "window/session_controller.h"

#include "core/settings.h"
#include "core/application.h"
#include "core/sandbox.h"
#include "local/account.h"

#include "local/domain.h"


MainWindow::MainWindow(Window::Controller* controller)
    : Window::MainWindow(controller) {
  setAttribute(Qt::WA_OpaquePaintEvent);
}

MainWindow::~MainWindow()
{
}


void MainWindow::preventOrInvoke(std::function<void()> callback)
{
}

void MainWindow::showSettings() {
  if (const auto session = sessionController()) {
  }
}

void MainWindow::showMainMenu()
{
}

void MainWindow::finishFirstShow()
{ applyInitialWorkMode();
  createGloablMenu();
  setAttribute(Qt::WA_NoSystemBackground);
  //if (!pass)
  
}

MainWidget* MainWindow::sessionContent() const { return main_->get();
  
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
	return Window::MainWindow::eventFilter(watched, event);
}

void MainWindow::closeEvent(QCloseEvent* event) {
  // 处于正在保存 会话 或者 退出状态
  if (Core::SandBox::Instance().isSavingSession() || Core::Quitting()) {
    event->accept();
    Core::Quit();
    return;
  } else if (Core::App().closeNonLastAsync(&controller())) {
    event->accept();
    return;
  }
  event->ignore();
  const auto hasAuth = [&] {
    // domain 尚未启动
    if (!Core::App().domain().started()) {
      return false;
    }
    for (const auto& [_, account] : Core::App().domain().accounts()) {
			if (account->sessionExists()) {
				return true;
			}
		}
    return false;
  }();
  if (!hasAuth || !hideNoQuit())
  {
    Core::Quit();
  }
  // 有响应
  // qDebug() << "CLOSE";

  //Window::MainWindow::closeEvent(event);
}

void MainWindow::applyInitialWorkMode() {
  const auto workMode = Core::App().settings().workMode();

}
