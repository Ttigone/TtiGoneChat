#include "window/sidebar.h"
#include "ui/widgets/buttons.h"
#include "layout/vertical_layout.h"

namespace Window {
SideBar::SideBar(QWidget* parent) :
	layout_(new Layout::VerticalLayout(this)) {
  this->setStyleSheet("background-color: #131313");
	//layout_(new QVBoxLayout(this)) {
  setObjectName("SideBar");
  init();
  setFixedWidth(250);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

}
SideBar::~SideBar() {}

void SideBar::init() {
  label_ = new QLabel("TtiGoneChat", this);
  all_chats_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/char-nomal.svg",
                                   ":/icon/ui/icons/mediaview/char-hover.svg",
                                   "All Chats", this);
  all_chats_->setConnerEnable(true);
  work_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/task-normal.svg",
                              ":/icon/ui/icons/mediaview/task-hover.svg",
                              "Work", this);
  meet_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/attachment-normal.svg",
                              ":/icon/ui/icons/mediaview/attachment-hover.svg",
                              "Meet", this);
  calendar_ = new Ui::WordsButton(
      ":/icon/ui/icons/mediaview/calendar-normal.svg",
      ":/icon/ui/icons/mediaview/calendar-hover.svg", "Calendar", this);
  rating_ = new Ui::WordsButton(":/icon/ui/icons/mediaview/rating-normal.svg",
                                ":/icon/ui/icons/mediaview/rating-hover.svg",
                                "Rating", this);
  saved = new Ui::WordsButton(":/icon/ui/icons/mediaview/mark-normal.svg",
                              ":/icon/ui/icons/mediaview/mark-hover.svg",
                              "Saved", this);
  settings_ = new Ui::WordsButton(
      ":/icon/ui/icons/mediaview/settings-normal.svg",
      ":/icon/ui/icons/mediaview/settings-hover.svg", "Settings", this);

  layout_->addWidget(label_);
  layout_->addSpacerItem(new QSpacerItem(0, 10));
  layout_->addWidget(all_chats_);
  layout_->addSpacerItem(new QSpacerItem(0, 10));
  layout_->addWidget(work_);
   layout_->addSpacerItem(new QSpacerItem(0, 10));
   layout_->addWidget(meet_);
   layout_->addSpacerItem(new QSpacerItem(0, 20));
   layout_->addWidget(calendar_);
   layout_->addSpacerItem(new QSpacerItem(0, 10));
   layout_->addWidget(rating_);
   layout_->addSpacerItem(new QSpacerItem(0, 10));
   layout_->addWidget(saved);
   layout_->addStretch();
   layout_->addWidget(settings_);
}
}  // namespace Window
