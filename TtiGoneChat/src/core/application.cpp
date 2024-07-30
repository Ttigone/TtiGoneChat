#include "core/application.h"

#include "core/sandbox.h"
#include "core/settings.h"
#include "core/tray.h"

#include "storage/local_storage.h"

#include "ui/style/style_font.h"
#include "ui/set_style.h"

#include "local/session.h"
#include "local/account.h"
#include "local/domain.h"

#include "lang/lang_translator.h"

#include "window/controller.h"
#include "window/launcher.h"
#include "window/themes/window_theme.h"

#include <iostream>
#include <QDir>

#include "base/debug_log.h"

#include "ui/widgets/mb_window.h"

namespace Core {

namespace {
// 默认运行状态
LaunchState GlobalLaunchState;

}  // namespace

Application* Application::instance_ = nullptr;

struct Application::Private {
  base::Timer timer;
  Settings settings;
};

Application::Application() : QObject(), private_(std::make_unique<Private>()) {}

Application::~Application() { instance_ = nullptr; }

void Application::run() {
  // 开启本地存储服务
  startLocalStorage();


  // 设置字体
  style::SetCustomFont(settings().customFontFamily());
  style::internal::StartFonts();

  // 翻译器
  translator_ = std::make_unique<Lang::Translator>();
  // 安装翻译器
  QCoreApplication::instance()->installTranslator(translator_.get());

  // 开启快捷方法
  startShortcuts();

  // 创建微型数据库, 方便快速启动
  // ....

  // map 中 新建一个 首要窗口 空账户
  // 所有权仍在 primary_window_ 上, 其他都只是原始指针的引用
  primary_windows_.emplace(nullptr, std::make_unique<Window::Controller>());
  // 获取指向 Controller 的原始指针, 将其设置为 最新激活的窗口
  setLastActiveWindow((*primary_windows_.begin()).second.get());

  // 上一个函数 为 last_active_window_ 设置了 emplace 中创建的值
  // 这里的 last_active_window_ 与 last_active_primary_window_ 是相同的
  window_in_settings_ = last_active_primary_window_ = last_active_window_;

  QCoreApplication::instance()->installEventFilter(this);

  appDeactivatedValue();

  LOG_DEBUG() << "正在创建";

  // 开启领域
  startDomain();

  // Ui::MbWindow *m = new Ui::MbWindow();
  // m->setStyleSheet(QString::fromUtf8(Window::Theme::readThemeContent("F:/MyProject/TtiGoneChat/TtiGoneChat/res/themes/dark-style.qss")));
  // m->show();
  // 首次展示
  last_active_primary_window_->firstShow();

  startMediaView();
  LOG_DEBUG() << "渲染窗口";

  Ui::SetStyle(last_active_primary_window_->widget(),
               Window::Theme::readThemeContent(":/qss/themes/dark-style.qss"));


  LOG_DEBUG() << "显示窗口";

  // 完成第一次展示
  last_active_primary_window_->finishFirstShow();

  // 最新激活的窗口没有 冷却
  if (!last_active_primary_window_->locked()) {
    last_active_primary_window_->showSettings();
  }
  // 处于 窗口聚焦状态
  last_active_primary_window_->updateIsActiveFocus();

  processCreateWindow(last_active_primary_window_);
}

Tray& Application::tray() const { return *tray_; }

Window::Controller* Application::findWindow(QWidget* widget) const {
  // 获取窗口句柄
  const auto window = widget->window();
  // 恰好找到
  if (last_active_window_ && last_active_window_->widget() == window) {
    return last_active_window_;
  }
  // 遍历 primaryWindow
  for (const auto& [account, primary] : primary_windows_) {
    // 找到
    if (primary->widget() == window) {
      return primary.get();
    }
  }
  // for (const auto& [account, primaty] : se)
  return nullptr;
}

Window::Controller* Application::activeWindow() const {
  return last_active_window_;
}

bool Application::closeNonLastAsync(Window::Controller* window) {
  const auto hasOther = [&] {
    for (const auto& [account, primary] : primary_windows_) {
      // 找不到关闭的窗口  或者 没有 会话状态
      if ((closing_async_windows_.find(primary.get()) ==
           closing_async_windows_.end()) &&
          primary.get() != window && primary->maybeSession()) {
        return true;
      }
    }
    return false;
  }();
  // 异步窗口 中 没有找到
  if (!hasOther) {
    return false;
  }
  // 构造
  closing_async_windows_.emplace(window);

  // 处理关闭窗口的异步逻辑
	// .....

  return true;
}

void Application::closeWindow(Window::Controller* window)
{
  const auto it = std::find(window_stack_.begin(), window_stack_.end(), window);

  //if (window_stack_.empty())
  //{
  //}


}

bool Application::passcodeLocked() const { return passcodeLock; }

bool Application::preventsQuit(QuitReason reason) { return true; }

bool Application::appDeactivatedValue() const {
  const auto& app = static_cast<QGuiApplication*>(QCoreApplication::instance());
  return true;
}

Settings& Application::settings() { return private_->settings; }

Local::Domain& Application::domain() const { return *domain_; }

bool Application::eventFilter(QObject* watched, QEvent* event) {
  //switch (event->type())
  //{
  //case QEvent::Close:
  //    qDebug() << "Close";

  //}
 	return QObject::eventFilter(watched, event);
}

void Application::startLocalStorage() { Storage::start(); }

void Application::startShortcuts() {}

void Application::startDomain() {}

void Application::startMediaView() {
  // 获取到 几何形状
  const auto current = last_active_primary_window_->widget()->geometry();
}

void Application::updateWindowTitles() {}

void Application::setLastActiveWindow(Window::Controller* window) {
  last_active_window_ = window;
  // 有效的窗口
  if (window) {
    // 查找窗口
    const auto i =
        std::find(window_stack_.begin(), window_stack_.end(), window);
    if (i == window_stack_.end()) {
      // 没有在 stack 中找到, 则添加
      window_stack_.push_back(window);
    } else if (i + 1 != window_stack_.end()) {
      // 找到了 并且不是最后一个元素
      // 将 window 窗口放置到最后
      std::rotate(i, i + 1, window_stack_.end());
    }
  }
  // 非有效的窗口
  if (!window) {
    return;
  }
}

void Application::showAccount(Local::Account* account) {}

bool Application::readyToQuit() {
  bool prevented = false;
  // if (domain)
  //{

  //}
  prevented = true;
  if (prevented) {
    delayedQuit();
    return false;
  }
  return false;
}


void Application::delayedQuit() {
  for (const auto& [account, window] : primary_windows_) {
    window->widget()->hide();
  }
  if (private_->timer.isActive())
  {
    private_->timer.setCallBack([] { SandBox::QuitWhenStarted(); });
    private_->timer.callOnce(1500);
  }
}

void Application::processCreateWindow(Window::Controller* window)
{
  //window.ope
}

void AttemptQuit() {
  const auto savingSession = SandBox::Instance().isSavingSession();
  if (!IsAppLaunched() || savingSession || App().readyToQuit()) {
    //qDebug() << "Quitting...";
    SandBox::QuitWhenStarted();
  }
}

void SetLaunchState(LaunchState state) { GlobalLaunchState = state; }

LaunchState CurrentLaunchState() { return GlobalLaunchState; }

void Quit(QuitReason reason) {
  if (Quitting()) {
    qDebug() << "Quitting already in progress";
    return;
  } else if (IsAppLaunched() && App().preventsQuit(reason)) {
    return;
  }
  // 设置 请求退出状态
  SetLaunchState(LaunchState::RequestedQuit);

  AttemptQuit();
}

bool Quitting() { return GlobalLaunchState != LaunchState::Running; }

void Restart() {}

bool IsAppLaunched() { return false; }

Application& App() {
  //std::cout << Application::instance_;
  return *Application::instance_;
}

}  // namespace Core
