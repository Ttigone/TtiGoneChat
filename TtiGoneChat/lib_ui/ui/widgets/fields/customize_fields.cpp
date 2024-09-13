#include "ui/widgets/fields/customize_fields.h"


namespace Ui {
namespace Widgets {

CustomizeFields::CustomizeFields(QWidget* parent)
    : QLineEdit(parent), max_len_(15) {
  init();

}

CustomizeFields::~CustomizeFields() {}

void CustomizeFields::setMaxWidth(int width) { max_len_ = width; }

void CustomizeFields::focusOutEvent(QFocusEvent* event) {
  QLineEdit::focusOutEvent(event);
  emit sig_foucus_out();
}

void CustomizeFields::init() {
  this->setStyleSheet(
      "background-color: #2e333d;"
      "border: 0px;"
      "border-radius: 10px;"  // 设置圆角半径为10px
      "padding: 10px;"         // 内边距
  );

  //this->setContentsMargins(QMargins(10, 5, 10, 5));

  front_action_ = new QAction(this);
  front_action_->setIcon(QIcon(":/icon/ui/icons/mediaview/search-normal.png"));
  this->addAction(front_action_, QLineEdit::LeadingPosition);

  end_action_ = new QAction(this);
	end_action_->setIcon(QIcon(":/icon/ui/icons/mediaview/circle_close-normal.png"));
  this->addAction(end_action_, QLineEdit::TrailingPosition);
  end_action_->setVisible(false);
	end_action_->setEnabled(false);

  this->setPlaceholderText("Search");


  connect(this, &QLineEdit::textChanged, this,
          &CustomizeFields::textChangedCallBack);
  connect(end_action_, &QAction::triggered, this, [this]() {
    this->clear();
    this->clearFocus();
  });
}


void CustomizeFields::textChangedCallBack(const QString &text) {
  limitTextLength(text);
  if (!text.isEmpty()) {
	  //end_action_->setIcon(QIcon(":/icon/ui/icons/mediaview/circle_close-normal.png"));
		end_action_->setEnabled(true);
		end_action_->setVisible(true);
  } else
  {
		//end_action_->setIcon(QIcon());
    end_action_->setVisible(false);
    end_action_->setEnabled(false);
  }
}

void CustomizeFields::limitTextLength(QString text) {
  if (max_len_ < 0) {
    return;
  }
  QByteArray byteArray = text.toUtf8();
  // 超过长度
  if (byteArray.size() > max_len_) {
    // 去掉超过的部分
    byteArray = byteArray.left(max_len_);
    this->setText(QString::fromUtf8(byteArray));
  }
}

}  // namespace Widgets
}  // namespace Ui
