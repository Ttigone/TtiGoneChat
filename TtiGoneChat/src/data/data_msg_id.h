#ifndef DATA_MSG_ID_H
#define DATA_MSG_ID_H

#include "base/basic_types.h"
#include "data_talk_id.h"

namespace Data {
class TalkData;
class TalkId;
}  // namespace Data

/// <summary>
/// 消息ID
/// </summary>
class MsgId {
 public:
	constexpr MsgId() noexcept = default;
  constexpr MsgId(int64 value) noexcept : value_(value) {}

	[[nodiscard]] constexpr explicit operator bool() const noexcept {
    return (value_ != 0);
  }

 private:
  int64 value_;
};

//Q_DECLARE_METATYPE(MsgId);

struct FullMsgId
{
  constexpr FullMsgId() noexcept = default;
  constexpr FullMsgId(Data::TalkId talk, MsgId msg) noexcept : talk_(talk), msg_(msg) {}

	//Data::TalkData talk_;
	Data::TalkId talk_;
  MsgId msg_;
};

#endif  // DATA_MSG_ID_H
