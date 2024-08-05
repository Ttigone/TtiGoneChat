#include "ui/controls/words_button.h"

namespace Ui {
WordsButton::WordsButton(QWidget *parent) : QWidget(parent)
{
	
}
WordsButton::~WordsButton() {}

QString WordsButton::bottomWords() const { return bottom_words_; }

void WordsButton::setBottomWords(QString words) { bottom_words_ = words; }
}  // namespace Ui
