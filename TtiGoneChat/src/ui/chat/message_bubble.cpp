#include "ui/chat/message_bubble.h"

#include <qrgb.h>
#include <QColor>
#include <QHBoxLayout>

#include "data/data_talk.h"

namespace Ui {
BubbleFrame::BubbleFrame(Data::TalkData role, QWidget* parent)
    : QFrame(parent), role_(role), margin_(3) {
  layout_ = new QHBoxLayout();
  this->setLayout(layout_);
}

void BubbleFrame::setMargin(int margin) {
  // layout_.set
}

void BubbleFrame::setWidget(QWidget* widget) {
  if (layout_->count() > 0) {
    return;
  } else {
    layout_->addWidget(widget);
  }
}

void BubbleFrame::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setPen(Qt::NoPen);
  if (role_.isChat()) {
    //QColor color(qrgb(255, 255, 255));
    QColor color(255, 255, 255);
    painter.setBrush(color);
    QRect orect = QRect(20, 0, this->width() - 20, this->height());
    painter.drawRoundedRect(orect, 10, 10);
    QPointF points[3] = {
        QPointF(orect.x(), 12),
        QPointF(orect.x(), 10 + 30 + 2),
        QPointF(orect.x() - 30, 10 + 30 - 30 / 2),
    };
    painter.drawPolygon(points, 3);
  } else {
  }

  return QFrame::paintEvent(event);
}

TextBubble::TextBubble(Data::TalkData role, const QString& text,
                       QWidget* parent)
    : BubbleFrame(role, parent) {
  init(text);
}
bool TextBubble::eventFilter(QObject* watched, QEvent* event) {
  if (text_edit_ == watched && event->type() == QEvent::Paint) {
    adjustTextHeight();
  }
  return BubbleFrame::eventFilter(watched, event);
}
void TextBubble::init(const QString& text) {
  text_edit_ = new QTextEdit();
  // 只读
  text_edit_->setReadOnly(true);
  text_edit_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  text_edit_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  text_edit_->installEventFilter(this);
  QFont font("Arial", 12);
  text_edit_->setFont(font);
  setPlainText(text);
  setWidget(text_edit_);
  text_edit_->setStyleSheet("QTextEdit{background:transparent;border:none}");
}
void TextBubble::adjustTextHeight() {
  // 字体到边距的距离
  qreal doc_margin = text_edit_->document()->documentMargin();
}
void TextBubble::setPlainText(const QString& text) {}
}  // namespace Ui
