#include "ui/widgets/fields/completer_field.h"

#include "ui/widgets/fields/customize_fields.h"

namespace Window {
CompleterField::CompleterField(QWidget* parent) :
	Ui::MbWidget(parent),
	customize_fields_(new Ui::Widgets::CustomizeFields(this)),
	layout_(new QVBoxLayout(this))
{
  init();
}
CompleterField::~CompleterField()
{


}

void CompleterField::init()
{
	layout_->addWidget(customize_fields_);
  layout_->setContentsMargins(10, 5, 10, 5);
  layout_->setSpacing(0);
}
}  // namespace Window
