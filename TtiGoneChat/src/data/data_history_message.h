/*****************************************************************//**
 * \file   data_history_message.h
 * \brief  历史消息存储
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef DATA_HISTORY_MESSAGE_H
#define DATA_HISTORY_MESSAGE_H


namespace Data {


struct HistoryData {
  HistoryData(){};
  HistoryData(int64 msg_id, int64 uid, int64 sender_id, int64 receiver_id,
              QString msg, QString time)
      : msg_id_(msg_id),
        uid_(uid),
        sender_id_(sender_id),
        receiver_id_(receiver_id),
        message_(msg),
        time_stamp_(time) {}

  int64 msg_id_;        // 消息 id
  int64 uid_;           // 朋友 uid 号
  int64 sender_id_;     // 发送者 id
  int64 receiver_id_;   // 接收者 id
  QString message_;     // 消息
  QString time_stamp_;  // 时间戳
};

} // namespace Data


#endif // DATA_HISTORY_MESSAGE_H
