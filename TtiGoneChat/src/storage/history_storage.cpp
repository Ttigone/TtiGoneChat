#include "storage/history_storage.h"

#include "data/data_history_message.h"

#include "storage/local_storage.h"


extern  DatabaseConfig dbcg;

// 定义 HistoryData 结构体的成员信息
DEFINE_STRUCT_MEMBERS(Data::HistoryData,
                      MEMBER_TYPE_AND_NAME(Data::HistoryData, msg_id_),
                      MEMBER_TYPE_AND_NAME(Data::HistoryData, uid_),
                      MEMBER_TYPE_AND_NAME(Data::HistoryData, sender_id_),
                      MEMBER_TYPE_AND_NAME(Data::HistoryData, receiver_id_),
                      MEMBER_TYPE_AND_NAME(Data::HistoryData, message_),
                      MEMBER_TYPE_AND_NAME(Data::HistoryData, time_stamp_));



namespace Storage {


void CreateHistoryDataTable(const DatabaseConfig &cfg) {
  auto dataBases = storage::Databases::Instance(cfg);
  dataBases->openDb();

  QString sen =
      QString(
          "CREATE TABLE %1 ("
          "msg_id_ INTEGER PRIMARY KEY,"
          "uid_ INTEGER,"
          "sender_id_ INTEGER NOT NULL,"
          "receiver_id_ INTEGER NOT NULL,"
          "message_ TEXT NOT NULL,"
          "time_stamp_ TEXT NOT NULL"
          ");"
          )
          .arg(tHistoryDataTableName);

  if (!dataBases->createTable(sen, tHistoryDataTableName)) {
    qDebug() << "Error: Fail to create history data table.";
  }
  dataBases->setPrimaryKey("msg_id_");

  dataBases->exec(
      "CREATE INDEX IF NOT EXISTS idx_sender_id ON history_data "
      "(sender_id_);");

  dataBases->exec(
      "CREATE INDEX IF NOT EXISTS idx_receiver_id ON history_data "
      "(receiver_id_);");

  dataBases->exec(
      "CREATE INDEX IF NOT EXISTS idx_msg_id ON history_data "
      "(msg_id_);");
}



extern void InsertHistoryData(const Data::HistoryData& data) {
  auto dataBases = storage::Databases::Instance(dbcg);
  dataBases->openDb();
  dataBases->insertSingleData<Data::HistoryData>(tHistoryDataTableName, data);
}

std::vector<Data::HistoryData> readHistoryData(int64 uid) {
  auto dataBases = storage::Databases::Instance(dbcg);
  dataBases->openDb();
  return dataBases->queryDataByField<Data::HistoryData>(tHistoryDataTableName, "uid_", uid);
}

}  // namespace Storage
