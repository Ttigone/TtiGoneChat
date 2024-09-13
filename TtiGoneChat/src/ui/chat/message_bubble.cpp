#include "ui/chat/message_bubble.h"

#include <QColor>
#include <QHBoxLayout>
#include <QTextBlock>

#include "data/data_talk.h"

namespace Ui {
BubbleFrame::BubbleFrame(Data::TalkPropertyData role, QWidget* parent)
    : QFrame(parent), role_(role),layout_(new QVBoxLayout(this)){
  init();
}


void BubbleFrame::setWidget(QWidget* widget) {
  if (need_name_) {
    QLayoutItem *item = layout_->takeAt(1);
    if (item != nullptr) {
      delete item->widget();
      delete item;
    }
    layout_->insertWidget(1, widget);
  } else {
    QLayoutItem *item = layout_->itemAt(0);
    if (item != nullptr) {
      item->widget()->deleteLater();
      delete item;
    }
    layout_->insertWidget(0, widget);
  }
}

void BubbleFrame::paintEvent(QPaintEvent* event) {
  QFrame::paintEvent(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setPen(Qt::NoPen);
  if (role_.isUser()) {
    QColor color("#2e333d");
    painter.setBrush(color);
    // 本体
    QRect orect = QRect(10, 0, this->width() - 10, this->height());
    painter.drawRoundedRect(orect, 10, 10);
    // 创建QPainterPath对象

    // 填充
    int side = 8;
    int x = 10;
    int y = this->height() - 8;
    painter.drawRect(x, y, side, side);

    // 倾角
    QPainterPath path_ten;
    // 高度 40
    path_ten.moveTo(10, this->height() - 24);
    //// 导数最小
    path_ten.quadTo( 8, this->height() - 2,
                0, this->height());

    // 创建一个封闭的路径用于填充
    QPainterPath fillPath = path_ten;
    fillPath.lineTo(0, this->height());
    // 水平线
    fillPath.lineTo(11, this->height());
    // 向上
    fillPath.lineTo(11, this->height() - 24);

    // 设置填充颜色
    painter.fillPath(fillPath, QBrush(color));

    // 绘制辅助线
    painter.drawLine(0, this->height(), 10, this->height());
    painter.drawLine(this->height() - 10, this->height(), 10, this->height() - 24);

  } else {
    QColor color("#6b8afd");
    painter.setBrush(color);
    // 本体
    QRect orect = QRect(0, 0, this->width() - 10, this->height());
    painter.drawRoundedRect(orect, 10, 10);
    // 创建QPainterPath对象

    // 填充
    int side = 8;
    int x = this->width() - 8 - 10;
    int y = this->height() - 8;
    painter.drawRect(x, y, side, side);

    //// 倾角
    QPainterPath path_ten;
    //// 高度 40
    path_ten.moveTo(this->width() - 10, this->height() - 24);
    //// 导数最小
    path_ten.quadTo(this->width() - 8, this->height() - 2,
                this->width(), this->height());
    //painter.drawPath(path);

    //// 创建一个封闭的路径用于填充
    QPainterPath fillPath = path_ten;
    fillPath.lineTo(this->width(), this->height());
    // 水平线
    fillPath.lineTo(this->width() - 11, this->height());
    // 向上
    fillPath.lineTo(this->width() - 11, this->height() - 24);

    //// 设置填充颜色
    painter.fillPath(fillPath, QBrush(color));

    // 绘制辅助线
    painter.drawLine(this->width(), this->height(), this->width() - 10, this->height());
    painter.drawLine(this->height() - 10, this->height(), this->width() - 10, this->height() - 24);
  }

  //return QWidget::paintEvent(event);
}

void BubbleFrame::init() {
  QMargins margins = layout_->contentsMargins();
  // 设置布局中各个部件之间的间距
  layout_->setSpacing(1);
  setLayout(layout_);
  if (need_name_) {
    name_label_ = new QLabel("Lili Wilson", this);
    QFont font("Arial", 9, QFont::Normal);
    name_label_->setFont(font);
    name_label_->setFixedHeight(12);
    if (role_.isSelf()) {
      name_label_->setContentsMargins(0, 0, 10, 0);
      name_label_->setAlignment(Qt::AlignRight);
    } else {
      name_label_->setContentsMargins(10, 0, 0, 0);
      name_label_->setAlignment(Qt::AlignLeft);
    }
    name_label_->setStyleSheet("background: transparent; color: #d3d4d6");

    layout_->addWidget(name_label_);
  }
  // 占位
  QWidget *placeholderWidget = new QWidget(this);
  //placeholderWidget->setFixedHeight(5);
  layout_->addWidget(placeholderWidget);

  //// 多样化窗口(心情, 时间, 已读人数)
  diversification_window_ = std::make_shared<QWidget>(this);
  QHBoxLayout* d_layout = new QHBoxLayout(diversification_window_.get());
  d_layout->setContentsMargins(QMargins());
  d_layout->setSpacing(0);
  diversification_window_->setFixedHeight(14);
  diversification_window_->setStyleSheet("background: transparent;");
  QLabel *time_label = new QLabel("10:00", diversification_window_.get());
  QFont font("Arial", 8, QFont::Normal);
  time_label->setFont(font);
  time_label->setFixedHeight(10);
  time_label->setContentsMargins(0, 0, 10, 0);
  time_label->setAlignment(Qt::AlignRight);
  time_label->setStyleSheet("background: transparent; color: #d3d4d6");
  d_layout->addWidget(time_label, Qt::AlignRight);
  diversification_window_->setLayout(d_layout);
  layout_->addWidget(diversification_window_.get());
}

void BubbleFrame::setUserName(const QString& name) {
  if (need_name_) {
    name_label_->setText(name);
  }
}

TextBubble::TextBubble(Data::TalkPropertyData role, const QString& text,
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
  text_edit_->setStyleSheet("QTextEdit{background:transparent;border:none;color: #d3d4d6}");
}
void TextBubble::adjustTextHeight() {
  // 字体到边距的距离
  qreal doc_margin = text_edit_->document()->documentMargin();
  // qreal doc_margin = m_pTextEdit->document()->documentMargin();    //字体到边框的距离默认为4
  QTextDocument* doc = text_edit_->document();
  qreal text_height = 0;
  //把每一段的高度相加=文本高
  for (QTextBlock it = doc->begin(); it != doc->end(); it = it.next()) {
    QTextLayout* pLayout = it.layout();
    QRectF text_rect = pLayout->boundingRect();  //这段的rect
    text_height += text_rect.height();
  }
  int vMargin = this->layout()->contentsMargins().top();
  //设置这个气泡需要的高度 文本高+文本边距+TextEdit边框到气泡边框的距离
  // label 
  // 底部widget
  setFixedHeight(text_height + doc_margin * 2 + vMargin * 2 + 12 + 14);
}
void TextBubble::setPlainText(const QString& text) {
  text_edit_->setPlainText(text);
  //m_pTextEdit->setHtml(text);
  //找到段落中最大宽度
  qreal doc_margin = text_edit_->document()->documentMargin();
  int margin_left = this->layout()->contentsMargins().left();
  int margin_right = this->layout()->contentsMargins().right();
  QFontMetricsF fm(text_edit_->font());
  QTextDocument* doc = text_edit_->document();
  int max_width = 0;
  //遍历每一段找到 最宽的那一段
  for (QTextBlock it = doc->begin(); it != doc->end();
       it = it.next())  //字体总长
  {
    int txtW = int(fm.horizontalAdvance(it.text()));
    max_width = max_width < txtW ? txtW : max_width;  //找到最长的那段
  }
  //设置这个气泡的最大宽度 只需要设置一次
  setMaximumWidth(max_width + doc_margin * 2 +
                  (margin_left + margin_right));  //设置最大宽度
}
PictureBubble::PictureBubble(const QPixmap& picture,
                             Data::TalkPropertyData role, QWidget* parent)
    : BubbleFrame(role, parent) {
  QLabel* label = new QLabel();
  label->setScaledContents(true);
  QPixmap pix = picture.scaled(QSize(42, 42), Qt::KeepAspectRatio);
  label->setPixmap(pix);
  this->setWidget(label);

  int leftMargin = this->layout()->contentsMargins().left();
  int rightMargin = this->layout()->contentsMargins().right();
  int vMargin = this->layout()->contentsMargins().bottom();
  setFixedSize(pix.width()+leftMargin + rightMargin, pix.height() + vMargin *2);
}

void PictureBubble::init() {}

}  // namespace Ui
