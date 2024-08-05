#include "buttons.h"

namespace Ui
{
AbstractButton::AbstractButton(QWidget* parent)
	: QWidget(parent)
{
  setMouseTracking(true);
}

AbstractButton::~AbstractButton() {}

void AbstractButton::setDisabled(bool disabled) {
  auto was = state_;
  // ���ý���״̬, ����֮ǰ�����ڽ���״̬
  if (disabled && !(state_ & StateFlag::Disabled)) {
    state_ |= StateFlag::Disabled;
    onStateChanged(was, StateChangedSource::ByUser);
  } else if (!disabled && (state_ & StateFlag::Disabled)) {
    state_ &= ~State(StateFlag::Disabled);
    onStateChanged(was, StateChangedSource::ByUser);
  }
}

void AbstractButton::clearState()
{
	auto was = state_;
  state_ = StateFlag::None;
  onStateChanged(was, StateChangedSource::ByUser);
}

bool AbstractButton::isHover() const
{ return state_ & StateFlag::Hover; }

void AbstractButton::enterEvent(QEnterEvent* event)
{
	QWidget::enterEvent(event);
}

void AbstractButton::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
}

void AbstractButton::mousePressEvent(QMouseEvent* event)
{
	QWidget::mousePressEvent(event);
}

void AbstractButton::mouseMoveEvent(QMouseEvent* event)
{
	QWidget::mouseMoveEvent(event);
}

void AbstractButton::mouseReleaseEvent(QMouseEvent* event)
{
	QWidget::mouseReleaseEvent(event);
}

void AbstractButton::setHover(bool hover, StateChangedSource source) {
  // �����ڸ���
  if (hover == isHover()) {
    return;
  }
  const auto was = state_;
  if (hover) {
    state_ |= StateFlag::Hover;
  } else
  {
    state_ &= ~State(StateFlag::Hover);
  }
  onStateChanged(was, source);
  updateCursor();
  update();
}

void AbstractButton::updateCursor() {
  // �������ָ��, ���Ҹ���
  const auto pointerCursor = enable_pointer_cursor_ && isHover();
  // ֮ǰ�������״̬, ��Ҫ�����ı�
  if (pointerCursor != pointer_cursor_) {
    pointer_cursor_ = pointerCursor;
    setCursor(pointer_cursor_ ? style::cur_pointer : style::cur_default);
  }
}

void AbstractButton::checkContainPoint(QPoint point) {
  auto t = rect().marginsRemoved(contentsMargins()).contains(point);

}
} // namespace Ui