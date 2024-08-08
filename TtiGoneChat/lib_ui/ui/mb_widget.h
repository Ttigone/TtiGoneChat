/*****************************************************************//**
 * \file   mb_widget.h
 * \brief  ×Ô¶¨ÒåQWidget
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef MB_WIDGET_H
#define MB_WIDGET_H

#include <QWidget>
#include <QPointer>
#include <QtEvents>

namespace Ui
{

} // namespace Ui

class MbWidget;

template <typename Base>
class MBWidgetHelper : public Base {
 public:
  virtual QMargins getMarigns() const { return QMargins(); }

  void moveToLeft(int x, int y, int outerw = 0);
  void moveToRight(int x, int y, int outerw = 0);
  void setGeometryToLeft(const QRect &rect, int outerw = 0);
  void setGeometryToLeft(int x, int y, int w, int h, int outerw = 0);
  void setGeometryToRight(const QRect &rect, int outerw = 0);
  void setGeometryToRight(int x, int y, int w, int h, int outerw = 0);

 protected:
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
  void enterEvent(QEnterEvent *event) override {
    if (auto parent = mbParent()) {

    }
    return enterEvent(event);
  }

#else
  void enterEvent(QEvent *event) override {
    if (auto parent = mbParent()) {

    }
    return enterEvent(staitc_cast<QEnterEvent *>(event));
  }
#endif

  virtual void enterEventHook(QEnterEvent *event)
  {
	  return Base::enterEvent(event);
  }

  void leaveEvent(QEvent *event) final override {
		if (auto parent = mbParent()) {

		}
		return leaveEvent(event);
	}
  virtual void leaveEventHook(QEvent *event)
	{
	  return Base::leaveEvent(event);
	}


 private:
  MbWidget *mbParent() {
    return qobject_cast<MbWidget *>(Base::parentWidget());
  }

  const MbWidget *mbParent() const {
		return qobject_cast<const MbWidget *>(Base::parentWidget());
	}
};


class MbWidget : public MBWidgetHelper<QWidget> {
  Q_OBJECT
 public:
  MbWidget(QWidget *parent = nullptr);

  virtual int naturalWidth() const { return -1; }

  void resizeToWidth(int new_width) {
    auto margins = getMarigns();
    auto fullWidth = margins.left() + new_width + margins.right();
    auto fullHeight = margins.top() + resizeGetHieght() + margins.bottom();
    auto newSize = QSize(fullWidth, fullHeight);
    if (newSize != size()) {
      resize(newSize);
      update();
    }
  }

  void resizeToNaturalWidth(int new_width) {
    const auto natural = naturalWidth();
    resizeToWidth((natural > 0) ? qMin(new_width, natural) : new_width);
  }

  QRect rectNoMargins() const { return rect().marginsRemoved(getMarigns()); }

  int widthNoMargins() const { return rectNoMargins().width(); }

  int heightNoMargins() const { return rectNoMargins().height(); }

  int bottomNoMargins() const {
    auto rectWithoutMargins = rectNoMargins();
    return y() + rectWithoutMargins.y() + rectNoMargins().height();
  }

  QSize sizeNoMargins() const
  {
	  return rectNoMargins().size();
  }

  void setVisibleTopBottom(int visible_top, int visible_bottom)
  {
    const auto max = std::max(height(), 0);
		//visi
  }
protected:
  void setChildVisibleTopBottom(MbWidget *child, int visble_top, int visible_bottom)
  {
   if (child)
   {
      auto top = child->y();
     child->setVisibleTopBottom(visble_top - top, visible_bottom - top);
   }
  }

  virtual int resizeGetHieght() const { return heightNoMargins(); }

  virtual void visibleTopBottomUpdated(int visible_top, int visible_bottom)
  {
	  
  }

};

#endif  // MB_WIDGET_H
