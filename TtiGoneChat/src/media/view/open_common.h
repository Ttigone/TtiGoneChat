#ifndef OPEN_COMMON_H
#define OPEN_COMMON_H

#include "data/data_msg_id.h"
#include "data/data_talk.h"

namespace Data
{
class TalkData;
}

namespace Window {
class SessionController;
} // namespace Window

/// <summary>
/// 提出请求(窗口展示...)
/// </summary>
namespace Media::View {

class NeedRequest {
 public:
  NeedRequest() = default;
  NeedRequest(Window::SessionController* controller, MsgId topic_Root_id)
      : controller_(controller), topic_Root_id_(topic_Root_id) {}

  NeedRequest(Window::SessionController* controller, Data::TalkData* talk)
      : controller_(controller), talk_(talk) {}

  [[nodiscard]] Data::TalkData* talk() const { return talk_; }

  [[nodiscard]] MsgId topicRootId() const { return topic_Root_id_; }

  [[nodiscard]] Window::SessionController* controller() const {
    return controller_;
  }

  [[nodiscard]] int64 startTime() const { return start_time_; }

 private:
  Window::SessionController* controller_;
  Data::TalkData* talk_;
  MsgId topic_Root_id_;
  int64 start_time_ = 0;
};

}  // namespace Media::View

#endif  // OPEN_COMMON_H
