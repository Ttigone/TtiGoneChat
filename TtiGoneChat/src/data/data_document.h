/*****************************************************************/ /**
 * \file   data_document.h
 * \brief  
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef DATA_DOCUMENT_H
#define DATA_DOCUMENT_H

namespace Data {

class TextTalkData;

class DocumentData final {
 public:
  DocumentData();
  DocumentData(int uid, QString name, QString icon, bool sex, QString last_msg)
      : uid_(uid), name_(name), icon_(icon), sex_(sex) {}

  int getUid() const { return uid_; }
  void setUid(const int& uid) { uid_ = uid; }

  QString getName() const { return name_; }
  void setName(const QString& name) { name_ = name; }

  QString getIcon() const { return icon_; }
  void setIcon(const QString& icon) { icon_ = icon; }


  QVector<std::shared_ptr<TextTalkData>> getChatMsg() const {
    return chat_msg_;
  }
  void appendChagMsg(std::shared_ptr<TextTalkData> data) {
    chat_msg_.push_back(std::move(data));
  }

 private:
  int uid_;         // 朋友唯一标识符
  QString name_;
  QString nick_;
  QString icon_;
  bool sex_;
  QString last_msg;
  QVector<std::shared_ptr<TextTalkData>> chat_msg_;
};

class FriendDocumentData final {
 public:
  void appendChatMsgs(
      const std::vector<std::shared_ptr<TextTalkData>> text_vec);

 private:
  std::vector<std::shared_ptr<TextTalkData>> chat_msgs_;
};

}  // namespace Data

#endif  // DATA_DOCUMENT_H
