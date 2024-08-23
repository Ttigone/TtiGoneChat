#include "storage/storage_databases.h"


namespace storage {

Databases::~Databases() {
  database_.close();
  //qDebug() << "TEST";
}

QSqlDatabase Databases::getDatabase() {
  if (QSqlDatabase::database().isValid()) {
    return QSqlDatabase::database("qt_sql_default_connection");
  } else {
    qDebug() << "no";
  }
}

QSqlDatabase Databases::getDatabase(const QString &connectionName) {
  return QSqlDatabase::database(connectionName);
}

bool Databases::openDb()
{
  if (!database_.open()) {
    LOG_DEBUG() << "Error: Failed to connect database." << database_.lastError();
  } else {
    LOG_DEBUG() << "成功打开";
  }
	return true;
}

bool Databases::createTable(const QString &query_sen, const QString &table_name) {
  if (!database_.isOpen())
  {
    LOG_DEBUG() << "Error: Fail to open database." << database_.lastError();
    return false;
  }

  if (isTableExist(table_name))
  {
    LOG_DEBUG() << "Table already exists.";
    return true;
  }
  QSqlQuery query(database_);
  if (!query.exec(query_sen))
  {
    LOG_FATAL() << "Error: Fail to create table." << database_.lastError();
		return false;
  } 
  return true;
}

bool Databases::isTableExist(const QString& table_name)
{
  QSqlQuery query(database_);
  query.prepare(
      "SELECT name FROM sqlite_master WHERE type='table' AND name=:tableName");
  query.bindValue(":tableName", table_name);
  if (!query.exec()) {
    LOG_DEBUG() << "Error: Failed to check if table exists" << query.lastError();
    return false;
  }
  return query.next();  // Returns true if the table exists
}

void Databases::setPrimaryKey(const QVariant& key)
{ primary_key_ = key; }

QVariant Databases::primaryKey()
{
  return primary_key_;
}


Databases::Databases(const DatabaseConfig &cfg)
    : config_(cfg)
	{
  // 是否已经存在默认数据库连接
  LOG_INFO() << QObject::tr("数据库正在尝试进行连接");
  // 使用表名作为连接名
  if (QSqlDatabase::contains("qt_sql_default_connection")) {
    database_ = QSqlDatabase::database("qt_sql_default_connection");
    LOG_INFO() << "has connect";
  } else {
    // 建立和SQlite数据库的连接
    database_ = QSqlDatabase::addDatabase("QSQLITE");
    LOG_TRACE() << "Create";
    // 设置数据库文件的名字
    database_.setDatabaseName(config_.name + ".db");
    database_.setHostName(config_.host);
    database_.setPort(config_.port);
    database_.setUserName(config_.user);
    database_.setPassword(config_.password);
  }
}

}  // namespace storage
