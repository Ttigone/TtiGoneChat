#ifndef COMMON_SESSION_H
#define COMMON_SESSION_H

#include "common.h"

class QWidget;
class QPointer;

namespace Settings {

/// <summary>
/// 抽象会话工厂  一个聊天记录 ???
/// </summary>
struct AbstractSectionFactory {
  //[[nodiscard]] 
  [[nodiscard]] virtual QPointer<AbstractSection> create(QWidget *parent) const = 0;

  virtual ~AbstractSectionFactory() = default;
};

}  // namespace Settings

#endif  // COMMON_SESSION_H
