#include "window/sidebar.h"
#include "ui/widgets/buttons.h"
#include "layout/vertical_layout.h"

namespace Window {
SideBar::SideBar(QWidget* parent) :
  layout_(new QVBoxLayout(this)),
  widget_(new QWidget(this)),
	//side_bar_layout_(new Layout::VerticalLayout(widget_.get()))
	side_bar_layout_(new QVBoxLayout(widget_.get()))
	{
  layout_->setContentsMargins(QMargins());
  layout_->setSpacing(0);
  layout_->addWidget(widget_);

  this->setStyleSheet("background-color: #131313");
  setObjectName("SideBar");
  init();
  setMaximumWidth(60);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

}
SideBar::~SideBar() {}

void SideBar::init() {
  label_ = new QLabel("TtiGoneChat", this);
  all_chats_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/chat-normal.png",
                                   ":/icon/ui/icons/mediaview/chat-hover.png",
                                   "All Chats", this);
  all_chats_->setConnerEnable(true);
  work_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/work-normal.png",
                              ":/icon/ui/icons/mediaview/work-hover.png",
                              "Work", this);
  meet_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/attachment-normal.png",
                              ":/icon/ui/icons/mediaview/attachment-hover.png",
                              "Meet", this);
  calendar_ = new Ui::WordsButton(
      //":/icon/ui/icons/mediaview/calendar-normal.svg",
      //":/icon/ui/icons/mediaview/calendar-hover.svg", "Calendar", this);
      ":/icon/ui/icons/mediaview/calendar-normal.png",
      ":/icon/ui/icons/mediaview/calendar-hover.png", "Calendar", this);
  rating_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/rating-normal.png",
                                ":/icon/ui/icons/mediaview/rating-hover.png",
                                "Rating", this);
  saved = new Ui::WordsButton(":/icon/ui/icons/mediaview/mark-normal.png",
                              ":/icon/ui/icons/mediaview/mark-hover.png",
                              "Saved", this);
  settings_ = new Ui::WordsButton(
      ":/icon/ui/icons/mediaview/settings-normal.png",
      ":/icon/ui/icons/mediaview/settings-hover.png", "Settings", this);

  side_bar_layout_->setContentsMargins(QMargins());
  side_bar_layout_->setSpacing(0);

  side_bar_layout_->addWidget(label_, 0, Qt::AlignCenter);
  side_bar_layout_->addSpacerItem(new QSpacerItem(0, 10));
  side_bar_layout_->addWidget(all_chats_, 0, Qt::AlignCenter);
  side_bar_layout_->addSpacerItem(new QSpacerItem(0, 10));
  side_bar_layout_->addWidget(work_, 0, Qt::AlignCenter);
  side_bar_layout_->addSpacerItem(new QSpacerItem(0, 10));
  side_bar_layout_->addWidget(meet_, 0, Qt::AlignCenter);
  side_bar_layout_->addSpacerItem(new QSpacerItem(0, 20));
  side_bar_layout_->addWidget(calendar_, 0, Qt::AlignCenter);
  side_bar_layout_->addSpacerItem(new QSpacerItem(0, 10));
  side_bar_layout_->addWidget(rating_, 0, Qt::AlignCenter);
  side_bar_layout_->addSpacerItem(new QSpacerItem(0, 10));
  side_bar_layout_->addWidget(saved, 0, Qt::AlignCenter);
  side_bar_layout_->addStretch();
  side_bar_layout_->addWidget(settings_, 0, Qt::AlignCenter);
}
}  // namespace Window
