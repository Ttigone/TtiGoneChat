/*****************************************************************//**
 * \file   session_controller.h
 * \brief  
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/


#ifndef SESSIONCONTROLLER_H
#define SESSIONCONTROLLER_H

#include "settings/settings_type.h"

class MainWindow;
class MainWidget;

namespace Local {
class Session;
} // namespace Local

namespace Window {

class Controller;

struct SectionShow {

  enum class Way { Forward, Backward, ClearStack };

	struct OriginMsg
	{
		
	};
};


class SessionController {
public:
	// 会话管理器, 窗口控制器
	SessionController(Local::Session *session, Controller *window);
	SessionController();
	~SessionController();


	[[nodiscard]] Controller &window();

	[[nodiscard]] bool isPrimary() const;

	[[nodiscard]] Local::Session &session() const; 
	[[nodiscard]] ::MainWindow *widget() const;
	[[nodiscard]] ::MainWidget *content() const;

	void showSettings(Settings::Type type, const SectionShow &parms = SectionShow());
	void showSettings(const SectionShow &parms = SectionShow());
	

private:
	//const Local::Session *session_;
	Local::Session *session_;


	Controller* window_;	

	const bool is_primary = false;

};

} // namespace Window


#endif // SESSIONCONTROLLER_H
