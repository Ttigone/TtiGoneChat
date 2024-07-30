#include "ui/set_style.h"

#include <QWidget>

namespace Ui {



void SetStyle(QWidget* widget, const QByteArray& style)
{
		widget->setStyleSheet(style);
}

}  // namespace Ui
