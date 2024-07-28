/*****************************************************************//**
 * \file   button_p.h
 * \brief  impl 隐私按钮类
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef BUTTON_P_H
#define BUTTON_P_H

#include "ui/widgets/button.h"

namespace Ui {

class ButtonPrivate {
  Q_DECLARE_PUBLIC(Button)

 public:
  ButtonPrivate();
  virtual ~ButtonPrivate();

  void init();

  Button *q_ptr;

  QIcon iconNormal;
  QIcon iconChecked;
  QIcon iconDisabled;

  void reloadIcon();
};

}  // namespace Ui

#endif  // BUTTON_P_H
