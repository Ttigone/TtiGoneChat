/*****************************************************************/ /**
 * \file   storage_databases.h
 * \brief  数据库操作
 *
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef STORAGE_DATABASES_H
#define STORAGE_DATABASES_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <type_traits>

// 定义宏来获取结构体成员的名称和类型
#define MEMBER_TYPE_AND_NAME(type, member) \
  { #member, offsetof(type, member), typeid(type::member).name() }

// constexpr auto MEMBER_TYPE_AND_NAME = [](auto type, auto member) {
//   return std::make_tuple(#member, offsetof(decltype(type), member), typeid(decltype(type)::member).name());
// };

// 定义一个宏来简化结构体成员信息的定义
#define DEFINE_STRUCT_MEMBERS(type, ...)                    \
  template <>                                               \
  std::vector<MemberTypeAndName> getStructMembers<type>() { \
    return {__VA_ARGS__};                                   \
  }

struct MemberTypeAndName {
  QString name;
  size_t offset;  // 偏移量
  QString type;
};

// 获取结构体成员信息的模板函数
template <typename T>
inline std::vector<MemberTypeAndName> getStructMembers() {
  return {};
}

inline QString CppTypeToSqliteType(const QString& cpp_type) {
  if (cpp_type == typeid(QString).name()) {
    return "TEXT";
  } else if (cpp_type == typeid(int64).name() ||
             cpp_type == typeid(int).name()) {
    return "INTEGER";
  } else if (cpp_type == typeid(double).name()) {
    return "REAL";
  } else {
    return "BLOB";
  }
}

// 生成插入数据的 SQL 语句
QString generateQueryString(const QString& table_name, const QString& columns,
                            const QString& values) {
  QString query = "Insert INTO" + table_name + " (" + columns + ") VALUES (" +
                  values + ");";
  return query;
}

template <typename T>
inline std::pair<QString, QString> generateCreateTableQuery(
    const QString& table_name) {
  auto members = getStructMembers<T>();
  QString query = "CREATE TABLE " + table_name + " (";

  // 字段名 + 字段类型
  for (const auto& member : members) {
    query += member.name + " " + CppTypeToSqliteType(member.type) + ", ";
  }
  query.chop(2);  // 移除最后一个逗号和空格
  query += ");";
  // 返回创建表的 SQL 语句以及 主键
  return {query, members.at(0).name};
}

// 生成插入数据的 SQL 语句
template <typename T>
QString generateInsertQuery(const QString& tableName, const T& data) {
  auto members = getStructMembers<T>();
  // QString query = "INSERT INTO " + tableName + " (";
  // QString values = "VALUES (";
  QString columns, values;
  for (const auto& member : members) {
    columns += member.name + ", ";
    values += ":" + member.name + ", ";
  }
  columns.chop(2);  // 移除最后一个逗号和空格
  values.chop(2);   // 移除最后一个逗号和空格
  // query += ") " + values + ");";
  // return query;
  return generateQueryString(tableName, columns, values);
}

// 绑定值
template <typename T>
void bindMemberValues(QSqlQuery& query, const T& data,
                      const std::vector<MemberTypeAndName>& members) {
  for (const auto& member : members) {
    const char* dataPtr = reinterpret_cast<const char*>(&data) + member.offset;
    if (member.type == typeid(QString).name()) {
      query.bindValue(":" + member.name,
                      *reinterpret_cast<const QString*>(dataPtr));
    } else if (member.type == typeid(int64_t).name()) {
      query.bindValue(":" + member.name,
                      *reinterpret_cast<const int64_t*>(dataPtr));
    })
  }
}

// 绑定数据到 QSqlQuery
template <typename T>
void bindValues(QSqlQuery& query, const T& data) {
  auto members = getStructMembers<T>();
  // for (const auto& member : members) {
  //   const char* dataPtr = reinterpret_cast<const char*>(&data) + member.offset;
  //   if (member.type == typeid(QString).name()) {
  //     query.bindValue(":" + member.name,
  //                     *reinterpret_cast<const QString*>(dataPtr));
  //   } else if (member.type == typeid(int64_t).name()) {
  //     query.bindValue(":" + member.name,
  //                     *reinterpret_cast<const int64_t*>(dataPtr));
  //   }
  //   // 其他类型可以继续添加
  // }
  bindMemberValues(query, members);
}

struct DatabaseConfig {
  QString name;
  QString table;
  QString host;
  int port;
  QString user;
  QString password;

  [[nodiscard]] bool isValid() const {
    return !name.isEmpty() && !table.isEmpty() && !host.isEmpty() && port > 0 &&
           !user.isEmpty() && !password.isEmpty();
  }
};

enum class DatabaseType : uchar {
  SQLite = 0,
  MySQL,
  PostgreSQL,
  Oracle,
  SQLServer,
};

namespace storage {

class Databases {
 public:
  // static Databases &Instance();
  Databases(const DatabaseConfig& cfg);
  ~Databases();

  static QSqlDatabase getDatabase();
  static QSqlDatabase getDatabase(const QString& connectionName);

  [[nodiscard]] bool openDb();

  [[nodiscard]] bool createTable(const QString& query_sen,
                                 const QString& table_name);

  template <typename T>
  [[nodiscard]] bool createTable(const QString& table_name) {
    auto tpair = generateCreateTableQuery<T>(table_name);
    setPrimaryKey(tpair.second);

    // 在开发过程中, 可能会导致 主键消失
    if (isTableExist(table_name)) {
      LOG_INFO() << "Table already exists.";
      return true;
    }

    if (!database_.isOpen()) {
      LOG_FATAL()
          << "Error: Fail to open database. Because the databases is not opened"
          << database_.lastError();
      return false;
    }

    QSqlQuery query(database_);
    if (!query.exec(tpair.first)) {
      LOG_FATAL() << "Error: Fail to create table." << database_.lastError();
      return false;
    }
    LOG_INFO() << "Table created successfully";
    return true;
  }

  [[nodiscard]] bool isTableExist(const QString& table_name);

  // 带有模板的成员函数需要在头文件中实现
  template <typename T>
  void insertSingleData(const QString& table_name, const T& data) {
    if (!database_.isOpen()) {
      LOG_DEBUG() << "Error: Fail to insert single data. Because the databases "
                     "is not opened"
                  << database_.lastError();
      return;
    }
    QString queryStr = generateInsertQuery(table_name, data);
    QSqlQuery query(database_);

    query.prepare(queryStr);
    bindValues(query, data);
    if (!query.exec()) {
      qDebug() << "Failed to insert data:" << query.lastError().text();
    }
  }
  template <typename T>
  void insertMultipleData(const QString& tableName,
                          const std::vector<T>& dataList) {
    for (const auto& data : dataList) {
      insertSingleData(tableName, data);
    }
  }

  // 根据 id 删除数据
  void deleteDataById(const QString& table_name, int64 id) {
    if (!database_.isOpen()) {
      LOG_FATAL()
          << "Error: Fail to delete data. Because the databases is not opened"
          << database_.lastError();
      return;
    }
    QString queryStr = QString("DELETE FROM %1 WHERE %2 = :id")
                           .arg(table_name)
                           .arg(primary_key_.toString());
    QSqlQuery query(database_);
    query.prepare(queryStr);
    query.bindValue(":id", id);
    if (!query.exec()) {
      LOG_FATAL() << "Failed to delete data:" << query.lastError().text();
      return;
    }
  }

  // 查询所有数据(根据主键)
  template <typename T>
  std::optional<T> queryDataById(const QString& table_name, const int64& id) {
    if (!database_.isOpen()) {
      LOG_FATAL()
          << "Error: Fail to delete data. Because the databases is not opened"
          << database_.lastError();
      return std::nullopt;
    }
    qDebug() << primary_key_.toString();
    QString queryStr = QString("SELECT * FROM %1 WHERE %2 = :id")
                           .arg(table_name)
                           .arg(primary_key_.toString());
    QSqlQuery query(database_);
    qDebug() << queryStr;
    query.prepare(queryStr);
    query.bindValue(":id", id);
    qDebug() << query.boundValues();

    // 执行查询语句后, 使用 next() 遍历记录
    if (!query.exec()) {
      LOG_WARN() << "When query by id: " << id
                 << ".Failed to query data: " << query.lastError().text();
      return std::nullopt;
    }
    if (query.next()) {
      T data;
      // 获取结构体成员信息
      auto members = getStructMembers<T>();
      // dataPtr 指针解引用成指定的类型, 然后赋值
      for (const auto& member : members) {
        char* dataPtr = reinterpret_cast<char*>(&data) + member.offset;
        if (member.type == typeid(QString).name()) {
          *reinterpret_cast<QString*>(dataPtr) =
              query.value(member.name).toString();
        } else if (member.type == typeid(int64_t).name()) {
          *reinterpret_cast<int64_t*>(dataPtr) =
              query.value(member.name).toLongLong();
        }
        // 添加其他类型
      }
      return data;
    }
    return std::nullopt;
  }

  template <typename T>
  QVector<T> queryAllData(const QString& table_name) {
    QVector<T> dataList;
    if (!database_.isOpen()) {
      LOG_FATAL() << "Error: Fail to query all data. Because the databases is "
                     "not opened"
                  << database_.lastError();
      return dataList;
    }
    QString queryStr = QString("SELECT * FROM %1").arg(table_name);
    QSqlQuery query(database_);
    query.prepare(queryStr);
    if (!query.exec()) {
      LOG_WARN() << "Failed to query all data: " << query.lastError().text();
      return dataList;
    }
    while (query.next()) {
      T data;
      auto members = getStructMembers<T>();
      for (const auto& member : members) {
        char* dataPtr = reinterpret_cast<char*>(&data) + member.offset;
        if (member.type == typeid(QString).name()) {
          *reinterpret_cast<QString*>(dataPtr) =
              query.value(member.name).toString();
        } else if (member.type == typeid(int64_t).name()) {
          *reinterpret_cast<int64_t*>(dataPtr) =
              query.value(member.name).toLongLong();
        }
        // 其他类型可以继续添加
      }
      dataList.push_back(data);
    }
    return dataList;
  }

  template <typename T>
  QVector<T> queryDataByPage(const QString& table_name, int page,
                             int page_size) {
    QVector<T> dataList;
    if (!database_.isOpen()) {
      LOG_FATAL() << "Error: Fail to query all data. Because the databases is "
                     "not opened"
                  << database_.lastError();
      return dataList;
    }
    // 已读取过的页数
    int offset = page * page_size;
    QString queryStr = QString("SELECT * FROM %1 LIMIT %2 OFFSET %3")
                           .arg(table_name)
                           .arg(page_size)
                           .arg(offset);
    QSqlQuery query(database_);
    query.prepare(queryStr);
    if (!query.exec()) {
      LOG_WARN() << "Failed to query all data: " << query.lastError().text();
      return dataList;
    }
    while (query.next()) {
      T data;
      auto members = getStructMembers<T>();
      for (const auto& member : members) {
        char* dataPtr = reinterpret_cast<char*>(&data) + member.offset;
        if (member.type == typeid(QString).name()) {
          *reinterpret_cast<QString*>(dataPtr) =
              query.value(member.name).toString();
        } else if (member.type == typeid(int64_t).name()) {
          *reinterpret_cast<int64_t*>(dataPtr) =
              query.value(member.name).toLongLong();
        }
        // 其他类型可以继续添加
      }
      dataList.push_back(data);
    }
    return dataList;
  }

  // 统计记录的个数
  int countRecords(const QString& table_name) {
    if (!database_.isOpen()) {
      LOG_FATAL()
          << "Error: Fail to count records. Because the databases is not opened"
          << database_.lastError();
      return -1;
    }
    QString queryStr = QString("SELECT COUNT(*) FROM %1").arg(table_name);
    QSqlQuery query(database_);
    if (!query.exec(queryStr)) {
      LOG_WARN() << "Failed to count records: " << query.lastError().text();
      return -1;
    }
    if (query.next()) {
      return query.value(0).toInt();
    }
    return 0;
  }

  void setPrimaryKey(const QVariant& key);
  QVariant primaryKey();

 private:
  Databases(const Databases&) = delete;
  Databases& operator=(const Databases&) = delete;

  QVariant primary_key_;
  QSqlDatabase database_;
  DatabaseConfig config_;
};

class DataInserter {
 public:
  DataInserter(not_null<Databases*> db) : db_(db) {}

  template <typename T>
  bool insertSingleData(const QString& tableName, const T& data) {
    QString queryStr = generateInsertQuery(tableName, data);
    QSqlQuery query(db_->getDatabase());
    query.prepare(queryStr);
    bindValues(query, data);
    if (!query.exec()) {
      qDebug() << "Failed to insert data:" << query.lastError().text();
      return false;
    }
    return true;
  }

  template <typename T>
  bool insertMultipleData(const QString& tableName,
                          const std::vector<T> &dataList) {
    for (const auto &data : dataList) {
      if (!insertSingleData(tableName, data)) {
        return false;
      }
    }
    return true;
  }

 private:
  const not_null<Databases *> db_;
};

}  // namespace storage


#endif  // STORAGE_DATABASES_H