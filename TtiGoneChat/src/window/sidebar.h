/*****************************************************************//**
 * \file   sidebar.h
 * \brief  侧边任务切换栏
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "ui/mb_widget.h"


#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>



namespace Ui
{
class WordsButton;
class CommonButton;
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
  void init();

  QVBoxLayout *layout_;
  //const not_null<Ui::MbWidget *>
  const not_null<QWidget *> widget_;
  //Layout::VerticalLayout *side_bar_layout_;
  QVBoxLayout *side_bar_layout_;
  QLabel *label_;

  Ui::WordsButton *all_chats_;
  // Ui::CommonButton *all_chats_;
  Ui::WordsButton *work_;
  Ui::WordsButton *meet_;
  Ui::WordsButton *calendar_;
  Ui::WordsButton *rating_;
  Ui::WordsButton *saved;
  Ui::WordsButton *settings_;

  // QVBoxLayout *layout_;
};

} // namespace Window


#endif  // SIDEBAR_H
