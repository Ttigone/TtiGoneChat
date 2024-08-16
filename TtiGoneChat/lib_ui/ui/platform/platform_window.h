/*****************************************************************//**
 * \file   platform_window.h
 * \brief  window ƽ̨
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef PLATFORM_WINDOW_H
#define PLATFORM_WINDOW_H

namespace Ui {
class MbWidget;
class MbWindow;

namespace Platform {
class BasicWindowHelper {
 public:
  explicit BasicWindowHelper(not_null<MbWidget *> window);
  virtual ~BasicWindowHelper();

  [[nodiscard]] not_null<MbWidget *> window() const { return window_; }

  virtual void initInWindow(not_null<MbWidget *> window);
  [[nodiscard]] virtual not_null<MbWidget *> body();
  [[nodiscard]] virtual QMargins frameMargins();
  [[nodiscard]] virtual int addtionalContenPadding() const;


  virtual void setTitle(const QString &title);
  virtual void setNativeFrame(bool enable);
  virtual void setMinimumSize(QSize size);
  virtual void setFixedSize(QSize size);
  virtual void setGeometry(QRect rect);
  virtual void showFullScreen();
  virtual void showNormal();
  virtual void close();
  [[nodiscard]] QMargins nativeFrameMargins() const;

 private:
  virtual void setupBodyTitleAreaEvents();

  const not_null<MbWidget *> window_;
  bool mouse_pressed_ = false;
};

[[nodiscard]] std::unique_ptr<BasicWindowHelper> CreateSpecialBasicWindowHelper(
    not_null<MbWidget *> window);

[[nodiscard]] inline std::unique_ptr<BasicWindowHelper> CreateBasicWindowHelper(
    not_null<MbWidget *> window) {
  if (auto special = CreateSpecialBasicWindowHelper(window)) {
    return special;
  }
  return std::make_unique<BasicWindowHelper>(window);
}

}  // namespace Platform

}  // namespace Ui




#endif  // PLATFORM_WINDOW_H
