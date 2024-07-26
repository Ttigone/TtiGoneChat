#include "controller.h"

#include "core/application.h"
#include "window/session_controller.h"
#include "media/view/open_common.h"

#include "local/session.h"


namespace Window {

Controller::Controller() : Controller(Args{}) {}

Controller::Controller(Local::Account* account) : Controller(Args{}) {
  showAccount(account);
}


Controller::~Controller()
{
	widget_.clearWidgets();
  session_controller_ = nullptr;

}

void Controller::showAccount(Local::Account* account) {}

Data::TalkData* Controller::singleTalk() const
{ return talk_; }

bool Controller::isPrimary() const { return singleTalk() == nullptr; }

SessionController* Controller::sessionController() const
{
    return session_controller_.get();
}

bool Controller::locked() const
{
	return false;
}

Local::Session* Controller::maybeSession() const
{
  return account_ ? account_->maybySession() : nullptr;

  //return account_ ? &account_->session() : nullptr;
}

//{ if (Core::App().) }

void Controller::firstShow() {
  // 会执行 window 目录下的  mainwindow firstshow(), 继承原因
  widget_.firstShow();
}

void Controller::finishFirstShow()
{
	widget_.finishFirstShow();
}

void Controller::setupPasscodeLock() {}

void Controller::clearPasscodeLock() {}

void Controller::showSettings()
{
  widget_.showSettings();
}

void Controller::active()
{
}

void Controller::updateIsActiveFocus() {}
//{ is_active_timer_.callOnce(sessionController() ? sessionController()->session()); }

void Controller::updateIsActiveBlur()
{
}

void Controller::updateIsActive()
{
}

void Controller::minimize()
{
}

void Controller::close()
{
}

std::unique_ptr<Media::View::NeedRequest> Controller::openForMediaViewRequest() const
{
	return nullptr;
}

Controller::Controller(Args&& args) : talk_(args.talk), widget_(this){
}

}  // namespace Window

