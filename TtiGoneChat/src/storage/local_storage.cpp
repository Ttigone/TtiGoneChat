#include "storage/local_storage.h"

#include "config.h"



namespace Storage
{

void start()
{
  LoadConfigFile();
	InitaLoadTheme();
	readLangPack();
}



void LoadConfigFile()
{
	Cfg::LoadConfig("window_config.json");
  qDebug() << Cfg::windowMinWidth;
}

/// @brief 加载主题
void InitaLoadTheme()
{
	
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
