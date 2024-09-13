#include "storage/session_storage.h"


#include "storage/storage_databases.h"
#include "data/data_talk_init.h"
#include "storage/local_storage.h"

#include <QSettings>

extern DatabaseConfig dbcg;

// 使用宏来定义 StorageSessionLabel 结构体的成员信息
DEFINE_STRUCT_MEMBERS(Data::SessionLabelData,
                      MEMBER_TYPE_AND_NAME(Data::SessionLabelData, id_),
                      MEMBER_TYPE_AND_NAME(Data::SessionLabelData, icon_path_),
                      MEMBER_TYPE_AND_NAME(Data::SessionLabelData, name_),
                      MEMBER_TYPE_AND_NAME(Data::SessionLabelData, earily_msg_),
                      MEMBER_TYPE_AND_NAME(Data::SessionLabelData, time_));




std::vector<Data::SessionLabelData> readInitialUser(const QString& file_path) {
  std::vector<Data::SessionLabelData> userConfig;
  if (QFile::exists(file_path)) {
    LOG_INFO() << QObject::tr("正在读取初始时已经存在的用户");
    QSettings settings(file_path, QSettings::IniFormat);
    QStringList groups = settings.childGroups();
    for (const QString& group : groups) {
      if (group.startsWith("InitialTalk")) {
        settings.beginGroup(group);
        Data::SessionLabelData config;
        config.id_ = settings.value("id_").toInt();
        config.icon_path_ = settings.value("icon_path_").toString();
        config.name_ = settings.value("name_").toString();
        config.earily_msg_ = settings.value("earily_msg_").toString();
        config.time_ = settings.value("time_").toString();
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


QVector<Data::SessionLabelData> tSessionLabelData;


void CreateSessionLabelTable() {

  if (dbcg.isValid()) {
    qDebug() << "数据库配置文件正确";
    auto dataBases = storage::Databases::Instance(dbcg);
    dataBases->openDb();

    dataBases->createTable<Data::SessionLabelData>(tSessionLabelTableName);
  } else {
    LOG_FATAL() << QObject::tr("数据库配置文件错误");
  }

}

void writeSessionLabelLocation() {

  auto dataBases = storage::Databases::Instance(dbcg);
  dataBases->openDb();
  auto tem = readInitialUser(
      "F:/MyProject/TtiGoneChat/TtiGoneChat/src/settings/databases/"
      "config.ini");

  dataBases->insertMultipleData(tSessionLabelTableName, tem);
}

int64 readStorageSessionLabelLocation() {
  auto dataBases = storage::Databases::Instance(dbcg);
  dataBases->openDb();

  //tSessionLabelData =
  //    dataBases->queryAllData<StorageSessionLabel>(tSessionLabelConfig.table);
  tSessionLabelData = fetchDataFromDatabase(1, 10);

  //Singleton<storage::Databases>::destroy();
  return tSessionLabelData.size();
}

QVector<Data::SessionLabelData> fetchDataFromDatabase(int page, int page_size) {
  auto dataBases = storage::Databases::Instance(dbcg);
  dataBases->openDb();

  return dataBases->queryDataByPage<Data::SessionLabelData>(tSessionLabelTableName, page, page_size);
}
}  // namespace Storage
