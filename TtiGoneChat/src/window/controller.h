#ifndef CONTROLLER_H
#define CONTROLLER_H

// 主目录下的 mainWindow
#include "main_window.h"
#include "local/account.h"
#include "data/data_msg_id.h"
#include "base/timer.h"

namespace Data {
class TalkData;
}  // namespace Data


namespace Local {
class Account;
class Session;
}  // namespace Local

namespace Media::View {
class NeedRequest;
}  // namespace Media::View

namespace Window {

class SessionController;

class Controller {
 public:
  Controller();
  explicit Controller(Local::Account *account);
  //Controller(Data::TalkData *talk, MsgId id);
  ~Controller();

  Controller(const Controller &other) = delete;
  Controller &operator=(const Controller &other) = delete;

  void showAccount(Local::Account *account);
	
	[[nodiscard]] Data::TalkData *singleTalk() const;
  [[nodiscard]] bool isPrimary() const;

  [[nodiscard]] SessionController *sessionController() const;

  [[nodiscard]] ::MainWindow *widget() { return &widget_; }
  [[nodiscard]] Local::Account &account() const {
    if (account_ != nullptr) {
      return *account_;
    } else {
      //return Local::Account();
    }
  }

  /// @brief 是否锁定
	[[nodiscard]] bool locked() const;

  Local::Session *maybeSession() const;

  void firstShow();
  void finishFirstShow();

  void setupPasscodeLock();
  void clearPasscodeLock();

  void showSettings();

  void active();
  void updateIsActiveFocus();
  void updateIsActiveBlur();
  void updateIsActive();
  void minimize();
  void close();

  //[[nodiscard]] 

  [[nodiscard]] std::unique_ptr<Media::View::NeedRequest>
  openForMediaViewRequest() const;


 private:
  struct Args
  {
    Data::TalkData *talk = nullptr;
  };
  explicit Controller(Args &&args);

  Data::TalkData *talk_ = nullptr;            /// 会话数据
  Local::Account *account_ = nullptr;         /// 账户数据
  base::Timer is_active_timer_;               /// 是否活跃的定时器
  // 窗口界面  为什么是存储在 栈区, 而非内存分配在 堆区
  // 主目录的 MainWindow
  ::MainWindow widget_;
  std::unique_ptr<Window::SessionController> session_controller_; /// 会话管理器

		
};

} // namespace Window

#endif // CONTROLLER_H
