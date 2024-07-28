#include "ui/widgets/button.h"
#include "ui/widgets/button_p.h"

#include <QMouseEvent>
#include <QPainter>

namespace Ui {

ButtonPrivate::ButtonPrivate() = default;
ButtonPrivate::~ButtonPrivate() = default;

void ButtonPrivate::init() {}
void ButtonPrivate::reloadIcon() {
  Q_Q(Button);

  if (!q->isEnabled() && !iconDisabled.isNull()) {
    q->setIcon(iconDisabled);
    return;
  }
  if (q->isChecked() && !iconChecked.isNull()) {
    q->setIcon(iconChecked);
    return;
  }
  if (!iconNormal.isNull()) {
    q->setIcon(iconNormal);
  }
}

Button::Button(QWidget* parent) : Button(*new ButtonPrivate(), parent) {}

Button::~Button() = default;

QIcon Button::iconNormal() const {
  Q_D(const Button);
  return d->iconNormal;
}

void Button::setIconNormal(const QIcon& icon) {
  Q_D(Button);
  d->iconNormal = icon;
  d->reloadIcon();
}

QIcon Button::iconChecked() const {
  Q_D(const Button);
  return d->iconChecked;
}

void Button::setIconChecked(const QIcon& icon) {
  Q_D(Button);
  d->iconChecked = icon;
  d->reloadIcon();
}

QIcon Button::iconDisabled() const {
  Q_D(const Button);
  return d->iconDisabled;
}

void Button::setIconDisabled(const QIcon& icon) {
  Q_D(Button);
  d->iconDisabled = icon;
  d->reloadIcon();
}

void Button::checkStateSet() {
  Q_D(Button);
  d->reloadIcon();
  QAbstractButton::checkStateSet();
}

void Button::mouseDoubleClickEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    Q_EMIT doubleClicked();
  }
  QAbstractButton::mouseDoubleClickEvent(event);
}

void Button::paintEvent(QPaintEvent* event) { QPainter painter(this); }

void Button::mouseMoveEvent(QMouseEvent* event)
{
	QAbstractButton::mouseMoveEvent(event);
}

void Button::mousePressEvent(QMouseEvent* event)
{
	QAbstractButton::mousePressEvent(event);
}

void Button::mouseReleaseEvent(QMouseEvent* event)
{
	QAbstractButton::mouseReleaseEvent(event);
}

Button::Button(ButtonPrivate& d, QWidget* parent)
    : QAbstractButton(parent), d_ptr(&d) {
  d.q_ptr = this;
  d.init();
}
}  // namespace Ui