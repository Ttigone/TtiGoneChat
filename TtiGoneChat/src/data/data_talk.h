#ifndef DATA_TALK_H
#define DATA_TALK_H

namespace Local {
class Account;
class Session;
} // namespace Local


namespace Data {

class TalkData {
 public:
  TalkData();
  virtual ~TalkData();

  TalkData(const TalkData& other) = delete;
  TalkData &operator=(const TalkData& other) = delete;

  [[nodiscard]] Local::Session &session() const ;
  [[nodiscard]] Local::Account &account() const;

  /// @brief 是否是用户
  [[nodiscard]] bool isUser() const { return true; }
  /// @brief 是否是聊天
  [[nodiscard]] bool isChat() const { return true; }
  /// @brief 是否是群组
  [[nodiscard]] bool isGroup() const { return true; }
  /// @brief 是否是自己
  [[nodiscard]] bool isSelf() const { return true; }
  /// @brief 是否是传输助手
  [[nodiscard]] bool isTransport() const { return true; }
	/// @brief 是通知用户
  [[nodiscard]] bool isNotificationUser() const { return true; }
	/// @brief 是服务用户
  [[nodiscard]] bool isServerUser() const { return true; }




};

} // namespace Data
#endif  // !DATA_TALK_H
