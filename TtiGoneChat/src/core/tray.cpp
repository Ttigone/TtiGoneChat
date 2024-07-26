#include "core/tray.h"

#include "core/application.h"
#include "core/settings.h"

#include <QApplication>
 


namespace Core {
Tray::Tray() {}
void Tray::create() {
  rebuildMenu();
  if (Core::App().settings().workMode() != Settings::WorkMode::WindowOnly) {
    //tray

  }
}
bool Tray::has() const { return false; }
void Tray::rebuildMenu() {}
}  // namespace Core
