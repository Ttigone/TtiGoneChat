/*****************************************************************//**
 * \file   words_button.h
 * \brief  在最底边处有一段词的按钮
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef WORDS_BUTTON_H
#define WORDS_BUTTON_H

#include <QWidget>


namespace Ui {

class CommonButton;
class ConnerButton;

class WordsButton : public QWidget {
 public:
  WordsButton(QWidget *parent = nullptr);
  ~WordsButton();

  QString bottomWords() const;
  void setBottomWords(QString words);

 private:
  //std::unique_ptr<CommonButton> common_button_;
  //std::unique_ptr<>

  QString bottom_words_;
};

} // namespace Ui


#endif  // WORDS_BUTTON_H
