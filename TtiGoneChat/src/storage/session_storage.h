/*****************************************************************//**
 * \file   session_storage.h
 * \brief  SessionLabel 的存储配置
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef SESSION_STORAGE_H
#define SESSION_STORAGE_H

#include "storage/storage_databases.h"
#include "base/singleton.h"

namespace storage
{
class Databases;
} // namespace storage

struct StorageSessionLabel {
  int64 session_label_id;            // id 号
  QString session_label_icon_path;   // 图标路径
  QString session_label_name;        // 名称
  QString session_label_earily_msg;  // 最近消息
  QString session_label_time;        // 最近聊天时间
};


namespace Storage {

using base::Singleton;

static DatabaseConfig tSessionLabelConfig;

static std::vector<StorageSessionLabel> tSessionLabelData;

// 初始时写入用户信息
extern void writeSessionLabelLocation();

// 初始时读取用户信息
extern int64 readStorageSessionLabelLocation();



}  // namespace Storage

#endif  // SESSION_STORAGE_H
