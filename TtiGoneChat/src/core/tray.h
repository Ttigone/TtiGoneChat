/*****************************************************************//**
 * \file   tray.h
 * \brief  托盘
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef TRAY_H
#define TRAY_H

#include "base/basic_types.h"

namespace Core {

class Tray final {
 public:
  Tray();

  void create();
  void updateMenuText();
  void updateIconCounters();

  [[nodiscard]] bool has() const;

 private:
  void rebuildMenu();
  void toggleSoundNotifications();


  bool activeForTrayIconAction = false;
  int64 lastTrayClickTime = 0;

};
}  // namespace Core

#endif  // TRAY_H
