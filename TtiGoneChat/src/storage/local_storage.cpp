#include "storage/local_storage.h"

#include "storage/history_storage.h"
#include "storage/session_storage.h"

#include "config.h"
#include "base/debug_log.h"
#include "core/application.h"
#include "local/user_account.h"

#include "window/themes/window_theme.h"


#include <QSettings>

DatabaseConfig dbcg;

namespace Window
{
	namespace Theme
	{
		
	}
}


namespace Storage
{


void start() {
  LOG_DEBUG() << "读取设置";
  LoadConfigFile();
  InitialLoadTheme();
  readLangPack();

  ReadDataBaseConfig();


  Storage::CreateSessionLabelTable();

  //Storage::writeSessionLabelLocation();

  Storage::readStorageSessionLabelLocation();

  Storage::CreateHistoryDataTable(dbcg);

  // 设置信息传来的用户信息
  // 本地用戶
  Local::UserAccount::Instance()->SetUserInfo(
      std::make_shared<Data::DocumentData>(
          0, "USER1", ":/chat/private/boy_7.jpg", 1, "LASTMSG"));


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



DatabaseConfig readDatabaseConfig(const QString& file_path) {
  if (QFile::exists(file_path)) {
    LOG_INFO() << QObject::tr("数据库配置相关文件存在");
    QSettings settings(file_path, QSettings::IniFormat);
    settings.beginGroup("Database");
    DatabaseConfig config;
    config.name = settings.value("name").toString();
    //config.table = settings.value("table").toString();
    config.host = settings.value("host").toString();
    config.port = settings.value("port").toInt();
    config.user = settings.value("user").toString();
    config.password = settings.value("password").toString();
    settings.endGroup();
    return config;
  } else {
    LOG_FATAL() << QObject::tr("数据库配置相关文件不存在");
    return {};
  }
}


void ReadDataBaseConfig() {

  dbcg = readDatabaseConfig(
      "F:/MyProject/TtiGoneChat/TtiGoneChat/src/settings/databases/config.ini");
}


} // namespace Storage
