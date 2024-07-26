#include "settings.h"

namespace Core {
WindowPosition AdjustToScale(WindowPosition position, const QString& name) {
  // scale 不为 0
  if (!position.scale) {
    return position;
  }
  const auto scaleFactor = 1.1;
  if (scaleFactor != 1.0) {
    position.x = static_cast<int>(position.x * scaleFactor);
    position.y = static_cast<int>(position.y * scaleFactor);
    position.w = static_cast<int>(position.w * scaleFactor);
    position.h = static_cast<int>(position.h * scaleFactor);
  }
  return position;
}

Settings::Settings() {}

Settings::~Settings() {}
}  // namespace Core
