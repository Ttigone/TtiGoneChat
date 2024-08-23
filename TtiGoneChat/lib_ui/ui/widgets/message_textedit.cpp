#include "message_textedit.h"

namespace Ui {
MessageEdit::MessageEdit(QWidget* parent) : QTextEdit(parent) {
  setMaximumHeight(80);
}
MessageEdit::~MessageEdit() {}
bool MessageEdit::isImage(QString url) {}
QVector<MessageEdit::MsgInfo> MessageEdit::getMsgList() {
  live_msg_list_.clear();
  QString doc = document()->toPlainText();
  int indexUrl = 0;
  int count = msg_list_.size();
}
void MessageEdit::textEditChanged() {}
void MessageEdit::dragEnterEvent(QDragEnterEvent* event) {
  QTextEdit::dragEnterEvent(event);
}
void MessageEdit::dropEvent(QDropEvent* event) {
  QTextEdit::dropEvent(event);
}
void MessageEdit::keyPressEvent(QKeyEvent* event) {
  QTextEdit::keyPressEvent(event);
}
void MessageEdit::insertMsgList(QVector<MsgInfo>& list, const QString flag,
                                const QString& text, const QPixmap pixmap) {}
QStringList MessageEdit::getUrl(const QString& text) {}
QPixmap MessageEdit::getFileIconPixmap(const QString& url) {}
QString MessageEdit::getFileSize(int64 size) {}
}  // namespace Ui