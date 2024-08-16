/*****************************************************************//**
 * \file   window_media_preview.h
 * \brief  
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef WINDOW_MEDIA_PREVIEW_H
#define WINDOW_MEDIA_PREVIEW_H


#include "ui/mb_widget.h"

namespace Window {

class SessionController;

class MediaPreviewWidget final : public Ui::MbWidget {
 public:
  MediaPreviewWidget(QWidget *parent, not_null<Window::SessionController *>controller);
  MediaPreviewWidget(QWidget *parent);
  ~MediaPreviewWidget();

  protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

    private:
    void startShow();
    //void 

    not_null<Window::SessionController *> controller_;

    bool hiding_ = false;


};

} // namespace Window


#endif	// WINDOW_MEDIA_PREVIEW_H
