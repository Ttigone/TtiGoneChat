#include "storage/session_storage.h"
#include "storage/local_storage.h"

#include "storage/storage_databases.h"

#include <QSettings>

// 使用宏来定义 StorageSessionLabel 结构体的成员信息
DEFINE_STRUCT_MEMBERS(
    StorageSessionLabel,
    MEMBER_TYPE_AND_NAME(StorageSessionLabel, session_label_id),
    MEMBER_TYPE_AND_NAME(StorageSessionLabel, session_label_icon_path),
    MEMBER_TYPE_AND_NAME(StorageSessionLabel, session_label_name),
    MEMBER_TYPE_AND_NAME(StorageSessionLabel, session_label_earily_msg),
    MEMBER_TYPE_AND_NAME(StorageSessionLabel, session_label_time));

DatabaseConfig readDatabaseConfig(const QString& file_path) {
  if (QFile::exists(file_path)) {
    LOG_INFO() << QObject::tr("数据库配置相关文件存在");
    QSettings settings(file_path, QSettings::IniFormat);
    settings.beginGroup("Database");
    DatabaseConfig config;
    config.name = settings.value("name").toString();
    config.table = settings.value("table").toString();
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

std::vector<StorageSessionLabel> readInitialUser(const QString& file_path) {
  std::vector<StorageSessionLabel> userConfig;
  if (QFile::exists(file_path)) {
    LOG_INFO() << QObject::tr("正在读取初始时已经存在的用户");
    QSettings settings(file_path, QSettings::IniFormat);
    QStringList groups = settings.childGroups();
    for (const QString& group : groups) {
      if (group.startsWith("InitialTalk")) {
        settings.beginGroup(group);
        StorageSessionLabel config;
        config.session_label_id = settings.value("id_").toInt();
        config.session_label_icon_path =
            settings.value("icon_path_").toString();
        config.session_label_name = settings.value("name_").toString();
        config.session_label_earily_msg =
            settings.value("earily_msg_").toString();
        config.session_label_time = settings.value("time_").toString();
        settings.endGroup();
        userConfig.push_back(config);
      }
    }
  } else {
    LOG_FATAL() << QObject::tr("数据库配置相关文件不存在");
    return {};
  }
  return userConfig;
}

namespace Storage {

DatabaseConfig tSessionLabelConfig;

QVector<StorageSessionLabel> tSessionLabelData;

void writeSessionLabelLocation() {
  tSessionLabelConfig = readDatabaseConfig(
      "F:/MyProject/TtiGoneChat/TtiGoneChat/src/settings/databases/config.ini");

  if (tSessionLabelConfig.isValid()) {
    auto dataBases =
        Singleton<storage::Databases>::Instance(tSessionLabelConfig);
    dataBases->openDb();

    dataBases->createTable<StorageSessionLabel>(tSessionLabelConfig.table);

    //StorageSessionLabel label = {0, "path/to/icon", "Name", "Last message",
    //                             "2024-08-01"};

    //auto tem = readInitialUser("F:/MyProject/TtiGoneChat/TtiGoneChat/src/settings/databases/config.ini");

    //qDebug() << tem.size();
    //dataBases->insertMultipleData(tSessionLabelConfig.table, tem);

    //auto t = dataBases->queryDataById<StorageSessionLabel>(tSessionLabelConfig.table, 0);
    //if (t.has_value())
    //{
    //  auto val = t.value();
    //  qDebug() << val.session_label_icon_path;
    //}

    //storage::DataInserter inserter(dataBases);
    //if (!inserter.insertSingleData("session_labels", label)) {
    //}
    //dataBases->deleteDataById(config.table, 0);

    //std::vector<StorageSessionLabel> labels = {
    //    {2, "path/to/iconsdsadasdasdas", "Name2", "Last message2", "2024-08-02"},
    //    {3, "path/to/icosdasdasdn3", "Name3", "Last message3", "2024-08-03"}};
    //t->insertMultipleData(config.table, labels);

    //if (!inserter.insertMultipleData("session_labels", labels)) {
    //  //return -1;
    //}

  } else {
    LOG_FATAL() << QObject::tr("数据库配置文件错误");
  }
}

int64 readStorageSessionLabelLocation() {
  auto dataBases = Singleton<storage::Databases>::Instance(tSessionLabelConfig);
  dataBases->openDb();

  //tSessionLabelData =
  //    dataBases->queryAllData<StorageSessionLabel>(tSessionLabelConfig.table);
  tSessionLabelData = fetchDataFromDatabase(1, 10);

  //Singleton<storage::Databases>::destroy();
  return tSessionLabelData.size();
}

QVector<StorageSessionLabel> fetchDataFromDatabase(int page, int page_size) {
  auto dataBases = Singleton<storage::Databases>::Instance(tSessionLabelConfig);
  dataBases->openDb();

  return dataBases->queryDataByPage<StorageSessionLabel>(tSessionLabelConfig.table, page, page_size);
}
}  // namespace Storage
