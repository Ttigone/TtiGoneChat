#ifndef COMMON_H
#define COMMON_H

#include <qwidget.h>

#include "settings_type.h"

namespace Settings {

class AbstractSection : public QWidget {
 public:
  /// <summary>
  /// 返回类型
  /// </summary>
  /// <returns></returns>
  [[nodiscard]] virtual Type id() const = 0;
  virtual void showFinished() {}
  virtual QString title() const = 0;

};

} // namespace Settings

#endif  // COMMON_H
