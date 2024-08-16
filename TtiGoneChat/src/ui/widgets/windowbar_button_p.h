/*****************************************************************//**
 * \file   button_p.h
 * \brief  impl 隐私按钮类
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef WINDOWBAR_BUTTON_P_H
#define WINDOWBAR_BUTTON_P_H

#include "ui/widgets/windowbar_button.h"

namespace Ui {

class WindowbarButtonPrivate {
  Q_DECLARE_PUBLIC(WindowbarButton)

 public:
  WindowbarButtonPrivate();
  virtual ~WindowbarButtonPrivate();

  void init();

  WindowbarButton *q_ptr;

  QIcon iconNormal;
  QIcon iconChecked;
  QIcon iconDisabled;

  void reloadIcon();
};

}  // namespace Ui

#endif  // WINDOWBAR_BUTTON_P_H
