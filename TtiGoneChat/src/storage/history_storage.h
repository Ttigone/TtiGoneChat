/*****************************************************************//**
 * \file   history_storage.h
 * \brief  历史消息存储
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef HISTORY_STORAGE_H
#define HISTORY_STORAGE_H

#include "storage/storage_databases.h"
#include "data/data_history_message.h"


const QString tHistoryDataTableName = "history_data";

namespace Storage {

void CreateHistoryDataTable(const DatabaseConfig &cfg);

//void InsertHistoryData();
// 从输入框中发送消息, 保存到数据库  
extern void InsertHistoryData(const Data::HistoryData& data);

// 根据聊天用户，读取聊天信息
extern std::vector<Data::HistoryData> readHistoryData(int64 uid);

} // namespace Storage



#endif  // HISTORY_STORAGE_H
