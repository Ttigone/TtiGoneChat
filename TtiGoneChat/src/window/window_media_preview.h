/*****************************************************************/ /**
 * \file   window_media_preview.h
 * \brief  右侧聊天栏 ??
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef WINDOW_MEDIA_PREVIEW_H
#define WINDOW_MEDIA_PREVIEW_H

#include "storage/session_storage.h"
#include "ui/mb_widget.h"


// #include

namespace Data {
class DocumentData;
class TextTalkData;
}  // namespace Data

namespace History {
class HistoryWidget;
}  // namespace History

namespace Ui {
class CommonButton;
} // namespace Ui

namespace Window {

class SessionController;

class MediaPreviewWidget final : public Ui::MbWidget {
  Q_OBJECT
 public:
  MediaPreviewWidget(QWidget* parent);
  ~MediaPreviewWidget();

  void setInfo(std::shared_ptr<Data::DocumentData> user_info);

  /// @brief 初始化聊天框添加信息
  /// @param data
  void appendChatMsg(std::shared_ptr<Data::TextTalkData> data);

  bool isPrivateChat();

 protected:
  void paintEvent(QPaintEvent* event) override;
  // void resizeEvent(QResizeEvent* event) override;

 private:
  /// @brief 初始化操作
  void init();
  void startShow();

  // 标题标签
  QLabel* title_label_;
  QVBoxLayout* layout_;
  //QGridLayout *layout_;
  History::HistoryWidget* widget_;

  //QHBoxLayout* title_layout_;
  QGridLayout *title_layout_;
  QWidget* title_window_;

  bool hiding_ = false;
  std::shared_ptr<Data::DocumentData> user_info_;
  QMap<QString, QWidget*> bubble_map_;

  std::shared_ptr<QLabel> member_online_num_;
  //std::shared_ptr<QLabel> online_num_;
  std::shared_ptr<QLabel> online_time_;

  //std::shared_ptr<Ui::CommonButton> search_btn_;
  //std::shared_ptr<Ui::CommonButton> multimedia_btn_;
  //std::shared_ptr<Ui::CommonButton> fold_btn_;
  //std::shared_ptr<Ui::CommonButton> detail_btn;


  std::unique_ptr<Ui::CommonButton> search_btn_;
  std::unique_ptr<Ui::CommonButton> multimedia_btn_;
  std::unique_ptr<Ui::CommonButton> fold_btn_;
  std::unique_ptr<Ui::CommonButton> detail_btn;

  //Ui::CommonButton *search_btn_;
  //Ui::CommonButton *multimedia_btn_;
  //Ui::CommonButton *fold_btn_;
  //Ui::CommonButton *detail_btn;

};

}  // namespace Window

#endif  // WINDOW_MEDIA_PREVIEW_H
