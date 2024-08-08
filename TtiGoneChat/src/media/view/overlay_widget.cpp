#include "media/view/overlay_widget.h"

#include "window/sidebar.h"



#include <QLabel>
#include <QVBoxLayout>



namespace Media {
namespace View {

OverlayWidget::OverlayWidget(QWidget* parent) {
  // QLayout *layout = new QVBoxLayout(this);
  // layout->setContentsMargins(QMargins());
  // layout->setSpacing(0);
  // Ui::CommonButton *button = new
  // Ui::CommonButton("C:/Users/cssss/Downloads/chat-hover.svg", this);
  // layout->addWidget(button);

  // Ui::WordsButton * button1 = new Ui::WordsButton("TEST", this);
  // layout->addWidget(button1);
  // button1->setConnerEnable(true);
  // //Ui::CommonButton* button1 = new
  // Ui::CommonButton("C:/Users/cssss/Downloads/chat-hover.svg");
  // //layout->addWidget(button1);

  QHBoxLayout* layout = new QHBoxLayout(this);
  side_bar_ = std::make_unique<Window::SideBar>(this);
  layout->addWidget(side_bar_.get(), Qt::AlignLeft);
  layout->addStretch();
}

OverlayWidget::~OverlayWidget() = default;

}  // namespace View

}  // namespace Media
