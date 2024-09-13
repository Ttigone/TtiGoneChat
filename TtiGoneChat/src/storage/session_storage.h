/*****************************************************************/ /**
 * \file   session_storage.h
 * \brief  SessionLabel 的存储配置
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef SESSION_STORAGE_H
#define SESSION_STORAGE_H

#include "base/singleton.h"
#include "storage/storage_databases.h"

const QString tSessionLabelTableName = "session_label";


namespace Data {
struct SessionLabelData;
}  // namespace Data

namespace storage {
class Databases;
}  // namespace storage


namespace Storage {

using base::Singleton;


extern QVector<Data::SessionLabelData> tSessionLabelData;


void CreateSessionLabelTable();

// 初始时写入用户信息
extern void writeSessionLabelLocation();

// 初始时读取用户信息
extern int64 readStorageSessionLabelLocation();

// 动态读取用户信息
extern QVector<Data::SessionLabelData> fetchDataFromDatabase(int page,
                                                             int page_size);

}  // namespace Storage

#endif  // SESSION_STORAGE_H
