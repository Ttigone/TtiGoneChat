/*****************************************************************//**
 * \file   sidebar.h
 * \brief  侧边任务切换栏
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QLabel>

//#include "ui/controls/conner_button.h"
//#include "layout/vertical_layout.h"

namespace Ui
{
class ConnerButton;
} // namespace Ui

namespace Layout
{
	class VerticalLayout;
} // namespace Layout

namespace Window {

class SideBar : public QWidget {
  Q_OBJECT
 public:
	SideBar(QWidget *parent = nullptr);
	~SideBar();

 private:
	QLabel *label_;
	Ui::ConnerButton *all_chats_;
	
	Layout::VerticalLayout *layout_;

};

} // namespace Window


#endif  // SIDEBAR_H
