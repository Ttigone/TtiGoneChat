/*****************************************************************/ /**
 * \file   data_talk_init.h
 * \brief  初始化 session 的 label
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef DATA_TALK_INIT_H
#define DATA_TALK_INIT_H

namespace Data {

// 会话标签数据
struct SessionLabelData {
  SessionLabelData(){};
  SessionLabelData(int64 id, QString icon_path, QString name,
                   QString earily_msg, QString time)
      : id_(id),
        icon_path_(icon_path),
        name_(name),
        earily_msg_(earily_msg),
        time_(time) {}

  int64 id_;            // id 号
  QString icon_path_;   // 图标路径
  QString name_;        // 名称
  QString earily_msg_;  // 最近消息
  QString time_;        // 最近聊天时间
};

Q_DECLARE_METATYPE(SessionLabelData)

}  // namespace Data

#endif  // DATA_TALK_INIT_H
