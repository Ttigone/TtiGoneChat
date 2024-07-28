
#include "window/mainwindow.h"
#include "window/session_controller.h"
#include "window/controller.h"

#include "core/application.h"
#include "core/tray.h"

#include "main_widget.h"


#include <QGuiApplication>
#include <QScreen>

namespace Window 
{

MainWindow::MainWindow(Window::Controller* controller)
	: controller_(controller)
{
}

MainWindow::~MainWindow()
{
  hide();
}

void MainWindow::showSettings() {
  if (const auto session = sessionController()) {
    session->showSettings();
  } else
  {
	  
  }
}

bool MainWindow::isPrimary() const
{
  return controller_->isPrimary();
}

Window::Controller& MainWindow::controller() const
{ return *controller_; }

SessionController* MainWindow::sessionController() const
{
  return session_controller_.get();
}

bool MainWindow::hideNoQuit() {
  if (Core::Quitting()) {
    return false;
  }
  const auto workMode = Core::App().settings().workMode();
  if (workMode == Core::Settings::WorkMode::TrayOnly ||
      workMode == Core::Settings::WorkMode::WindowAndTray) {
    //if ()
  }
}

void MainWindow::active() {
  bool wasHidden = !isVisible();
  // 设置可见， 非最小化
  setWindowState(windowState() & ~Qt::MinimumSize);
  setVisible(true);

  activateWindow();
  // 聚焦状态
  controller().updateIsActiveFocus();
  // 上一刻是 隐藏状态
  if (wasHidden) {
    if (const auto session = sessionController())
    {
      session->content()->windowShown();
    }
  }
}

void MainWindow::init()
{
}

void MainWindow::updateIsActive()
{
}

bool MainWindow::isActive() const { return !isHidden() && is_active_; }

bool MainWindow::positionInited() const
{
  return position_inited_;
}

void MainWindow::positionUpdated()
{
}

void MainWindow::showRightColumn(QWidget* widget)
{
}

void MainWindow::clearWidgets()
{
}

void MainWindow::updateGlobalMenu()
{
}

void MainWindow::setupPasscodeLock()
{
}

void MainWindow::clearPasscodeLock()
{
}

// 自身去 show, 但是为什么还要存储一个  controller(包含一个 ::MainWindow) ?
void MainWindow::firstShow()
{
  //QWidget* t = new QWidget;
  // 更新最小面积
  //updateMiniSize();
  //if (initGeometryFromSystem())
  //{
  //  show();
  //  return;
  //}


  // 计算初始值的位置
  //const auto geometry = countInitialGeometry(initialPosition());

	//setGeometry(geometry);
  //qDebug() << geometry;
  show();
        //t->show();
}

bool MainWindow::minimizeToTray() {
  // 处于即将暂停 或者 没有处于托盘
  if (Core::Quitting() || !Core::App().tray().has()) {
    return false;
  }
  closeWithoutDestory();
  controller().updateIsActiveBlur();
  updateGlobalMenu();
  return true;
}


Core::WindowPosition MainWindow::initialPosition() const {
  //return Core::WindowPosition();
  // 活跃的窗口控制器
  const auto active = Core::App().activeWindow();
  // 不存在或者活跃的窗口控制器是当前的控制器
  if (!active || active == &controller())
  {
    return Core::AdjustToScale(Core::App().settings().windowPosition(), u"Window"_q);
  } else
  {
    // 更新当前 活动的控制器窗口
    return active->widget()->initialNextPosition(isPrimary());
  }
}

Core::WindowPosition MainWindow::initialNextPosition(bool primary) const
{
  // 原始矩形 去除了指定的边距后的结果
  const auto rect = geometry().marginsRemoved(QMargins(0, 0, 10, 0));
  const auto position = rect.topLeft();
  return Core::WindowPosition{0, 0, position.x(), position.y(), rect.width(), rect.height()};
}


QRect MainWindow::countInitialGeometry(Core::WindowPosition position, Core::WindowPosition initial,
                                       QSize min_size) const
{
  if (!position.w || !position.h)
  {
    return initial.rect();  
  }
  return QRect();
}

void MainWindow::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
}


void MainWindow::closeWithoutDestory() { hide(); }

void MainWindow::updateMiniSize()
{
}

QRect MainWindow::countInitialGeometry(Core::WindowPosition position) const {
  const auto primaryScreen = QGuiApplication::primaryScreen();
  const auto primaryAvailableGeometry =
      primaryScreen ? primaryScreen->availableGeometry() : QRect();

#if __cplusplus >= 202002L
  // 初始化位置，面积参数
  const auto initial = Core::WindowPosition{.x = primaryAvailableGeometry.x(),
                                            .y = primaryAvailableGeometry.y(),
                                            .w = 880,
                                            .h = 450};
#else
  const auto initial = Core::WindowPosition(0, 0, primaryAvailableGeometry.x(), primaryAvailableGeometry.y(), 880, 450);

#endif

  return countInitialGeometry(position, initial, QSize(880, 450));
}

} // namespace Window
