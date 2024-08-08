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
  QLabel *label_;



  Ui::WordsButton *all_chats_;
  // Ui::CommonButton *all_chats_;
  Ui::WordsButton *work_;
  Ui::WordsButton *meet_;
  Ui::WordsButton *calendar_;
  Ui::WordsButton *rating_;
  Ui::WordsButton *saved;
  Ui::WordsButton *settings_;

  Layout::VerticalLayout *layout_;
  // QVBoxLayout *layout_;
};

} // namespace Window


#endif  // SIDEBAR_H
