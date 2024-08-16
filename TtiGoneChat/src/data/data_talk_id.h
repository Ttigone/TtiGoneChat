#ifndef DATA_TALK_ID_H
#define DATA_TALK_ID_H


namespace Data {

struct TalkId {
  constexpr TalkId() noexcept = default;
  
  uint64 value = 0;
};

} // namespace Data

#endif  // !DATA_TALK_ID_H
