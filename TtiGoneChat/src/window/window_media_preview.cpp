#include "window_media_preview.h"
#include "session_controller.h"

namespace Window {

MediaPreviewWidget::MediaPreviewWidget(QWidget* parent,
                                       not_null<SessionController*> controller)
    : MbWidget(parent), controller_(controller) {
  setAttribute(Qt::WA_TransparentForMouseEvents);
}

MediaPreviewWidget::MediaPreviewWidget(QWidget* parent)
		: MbWidget(parent) , controller_(new SessionController()) 
{

}

MediaPreviewWidget::~MediaPreviewWidget() {}

void MediaPreviewWidget::paintEvent(QPaintEvent* event) {}

void MediaPreviewWidget::resizeEvent(QResizeEvent* event) {}

void MediaPreviewWidget::startShow() {}


} // namespace Window

