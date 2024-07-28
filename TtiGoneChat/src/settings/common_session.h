#ifndef COMMON_SESSION_H
#define COMMON_SESSION_H

#include "common.h"

class QWidget;
class QPointer;

namespace Settings {

/// <summary>
/// ����Ự����  һ�������¼ ???
/// </summary>
struct AbstractSectionFactory {
  //[[nodiscard]] 
  [[nodiscard]] virtual QPointer<AbstractSection> create(QWidget *parent) const = 0;

  virtual ~AbstractSectionFactory() = default;
};

}  // namespace Settings

#endif  // COMMON_SESSION_H
