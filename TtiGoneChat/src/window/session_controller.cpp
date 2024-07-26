#include "session_controller.h"

#include "controller.h"

namespace Window {
	SessionController::SessionController(Local::Session* session, Controller* window)
	{
	}

	SessionController::~SessionController()
	{
	}

	Controller& SessionController::window()
	{
		return *window_;
	}

	bool SessionController::isPrimary() const
	{
		return is_primary;
	}

	Local::Session& SessionController::session() const
	{ return *session_;
	}

	::MainWindow* SessionController::widget() const
	{
			return window_->widget();
	}

	::MainWidget* SessionController::content() const
	{
          return widget()->sessionContent();
	}


	void SessionController::showSettings(const SectionShow& parms)
	{
	}
} // namespace Window