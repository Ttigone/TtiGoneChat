/*****************************************************************//**
 * \file   buttons.h
 * \brief  底层按钮(基于 QWidget)
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/


#ifndef BUTTONS_H
#define BUTTONS_H

#include "base/flags.h"

namespace Ui {

class AbstractButton : public QWidget {
 public:
  AbstractButton(QWidget* parent);
  virtual ~AbstractButton();

  void setDisabled(bool disabled = true);
  virtual void clearState();
  [[nodiscard]] bool isHover() const;
  [[nodiscard]] bool isDown() const;
  [[nodiscard]] bool isDisabled() const;

 protected:
  void enterEvent(QEnterEvent* event) override;
  void leaveEvent(QEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;

 protected:
  enum class StateFlag {
    None = 0,
    Hover = (1 << 0),
    Down = (1 << 1),
    Disabled = (1 << 2),
  };
  using State = base::flags<StateFlag>;
  State state() const { return state_; }

  enum class StateChangedSource {
    ByUser = 0x00,
    ByPress = 0x01,
    ByHover = 0x02,
  };
  void setHover(bool hover,
                StateChangedSource source = StateChangedSource::ByUser);
  bool setDown(bool down, StateChangedSource source,
               Qt::KeyboardModifier modifiers, Qt::MouseButton button);
  virtual void onStateChanged(
      State was, StateChangedSource source = StateChangedSource::ByUser) {}

 private:
  void updateCursor();
  void checkContainPoint(QPoint point);

  State state_ = StateFlag::None;
  bool enable_pointer_cursor_ = false;
  bool pointer_cursor_ = false;
  bool accept_both_ = false;
};

}  // namespace Ui


#endif  // BUTTONS_H
