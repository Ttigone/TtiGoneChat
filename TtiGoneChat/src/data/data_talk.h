#ifndef DATA_TALK_H
#define DATA_TALK_H

namespace Local {
class Account;
class Session;
}  // namespace Local

namespace Data {

class TalkPropertyData {
 public:
  enum class TalkType : int8 {
    Self = 0x01,
    User,
    Chat,
    Group,
    Transport,
    NotificationUser,
    ServerUser
  };

  TalkPropertyData() : type_(TalkType::Self) {}
  TalkPropertyData(TalkType type) : type_(type) {}
  ~TalkPropertyData() = default;

  /// @brief 是否是用户
  [[nodiscard]] bool isUser() const { return type_ == TalkType::User; }
  /// @brief 是否是聊天
  [[nodiscard]] bool isChat() const { return type_ == TalkType::Chat; }
  /// @brief 是否是群组
  [[nodiscard]] bool isGroup() const { return type_ == TalkType::Group; }
  /// @brief 是否是自己
  [[nodiscard]] bool isSelf() const { return type_ == TalkType::Self; }
  /// @brief 是否是传输助手
  [[nodiscard]] bool isTransport() const { return true; }
  /// @brief 是通知用户
  [[nodiscard]] bool isNotificationUser() const { return true; }
  /// @brief 是服务用户
  [[nodiscard]] bool isServerUser() const { return true; }

 private:
  TalkType type_;
};

class TextTalkData {
 public:
  TextTalkData(int64 msg_id, QString msg_content, int64 from_uid, int64 to_uid)
      : msg_id_(msg_id),
        msg_content_(msg_content),
        from_uid_(from_uid),
        to_uid_(to_uid) {}
  ~TextTalkData() = default;
  int64 getMsgId() const { return msg_id_; }
  QString getMsgContent() const { return msg_content_; }
  int64 getFromUid() const { return from_uid_; }
  int64 getToUid() const { return to_uid_; }

 private:
  int64 msg_id_;
  QString msg_content_;
  int64 from_uid_;
  int64 to_uid_;
};
}  // namespace Data
#endif  // !DATA_TALK_H
