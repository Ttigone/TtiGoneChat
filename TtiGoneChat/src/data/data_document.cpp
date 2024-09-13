#include "data/data_document.h"
namespace Data {

DocumentData::DocumentData() {}
void FriendDocumentData::appendChatMsgs(
    const std::vector<std::shared_ptr<TextTalkData>> text_vec) {
  for (const auto& text : text_vec) {
    chat_msgs_.push_back(text);
  }
}
}  // namespace Data