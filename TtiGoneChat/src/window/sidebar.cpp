#include "window/sidebar.h"

#include "layout/vertical_layout.h"

namespace Window {
SideBar::SideBar(QWidget* parent)
	: layout_(new Layout::VerticalLayout(this))
{
	
}
SideBar::~SideBar() {}
}  // namespace Window