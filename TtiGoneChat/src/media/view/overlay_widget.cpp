#include "media/view/overlay_widget.h"

#include <QLabel>
#include <QVBoxLayout>

#include "ui/controls/common_button.h"
#include "ui/controls/conner_button.h"


namespace Media {
namespace View {
OverlayWidget::OverlayWidget(QWidget* parent) {
  QLayout *layout = new QVBoxLayout(this);
  layout->setContentsMargins(QMargins());
  layout->setSpacing(0);
  //QLabel* label = new QLabel("TTTTTTTTTTTT", this);
  //layout->addWidget(label);
  Ui::ConnerButton* button = new Ui::ConnerButton();
  layout->addWidget(button);
  Ui::CommonButton* button1 = new Ui::CommonButton("C:/Users/cssss/Downloads/chat-hover.svg");
  layout->addWidget(button1);
  
}

OverlayWidget::~OverlayWidget() = default;
}  // namespace View

}  // namespace Media
