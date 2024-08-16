#include "storage/local_storage.h"

#include "config.h"
#include "base/debug_log.h"
#include "core/application.h"
#include "window/controller.h"

#include "window/themes/window_theme.h"

#include "storage/session_storage.h"

namespace Window
{
	namespace Theme
	{
		
	}
}


namespace Storage
{

void start()
{
  LOG_DEBUG() << "读取设置";
  LoadConfigFile();
	InitialLoadTheme();
	readLangPack();

	Storage::writeSessionLabelLocation();

  Storage::readStorageSessionLabelLocation();

}



void LoadConfigFile()
{
  LOG_DEBUG() << "加载配置中";
	Cfg::LoadConfig("window_config.json");
}

/// @brief 加载主题
void InitialLoadTheme() {
  LOG_DEBUG() << "加载主题中";

  // QFile qss(QStringLiteral(":/resources/theme/Login/dark-style.qss"));
  // if (qss.open(QIODevice::ReadOnly | QIODevice::Text)) {
  //   //setStyleSheet(QString::fromUtf8(qss.readAll()));
  //   qss.close();
  // }
  //Core::App().activeWindow()->widget()->setStyleSheet(
  //    Window::Theme::readThemeContent(":/icon/day-custom.qss"));
}

/// @brief 读写设置项
void writeSettings()
{
	
}

/// @brief 是否需要重写设置项
void rewriteSettingsIfNeeded()
{
	
}

/// @brief 读取语言包 .qm
void readLangPack()
{
	
}

/// @brief 应用默认夜间模式
bool ApplyDefaultNightMode()
{
	return true;
}



} // namespace Storage
