#ifndef SENDER_H
#define SENDER_H

#include "proto/instance.h"

namespace Proto {


class Sender {
public:
  explicit Sender(Instance* instance) noexcept :
    instance_(instance) {

  }

  [[nodiscard]] Instance& instance() const {
    return *instance_;
  }

  private:
	Instance* instance_;
};
}  // namespace Proto

#endif // SENDER_H