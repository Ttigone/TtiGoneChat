#include "main_widget.h"

#include "window/session_controller.h"

#include <QPointer>

MainWidget::MainWidget(QWidget* parent, Window::SessionController* controller)
	: QWidget(parent), controller_(controller) {
}

MainWidget::~MainWidget()
{
}

Local::Session &MainWidget::session() const
{
	return controller_->session();
}

Window::SessionController &MainWidget::controller() const
{
	return *controller_;
}

bool MainWidget::isPrimary() const
{
	return controller_->isPrimary();
}

bool MainWidget::isMainSectionShown() const
{
	return false;
}

bool MainWidget::isThirdSectionShown() const
{
	return false;
}

void MainWidget::showAnimated(QPixmap old_content_cache, bool back)
{
}

void MainWidget::activate()
{
}

void MainWidget::windowShown()
{
}

void MainWidget::paintEvent(QPaintEvent* event)
{
}

void MainWidget::resizeEvent(QResizeEvent* event)
{
}

bool MainWidget::eventFilter(QObject* obj, QEvent* event)
{
	return false;
}
