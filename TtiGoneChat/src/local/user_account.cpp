#include "local/user_account.h"

namespace Local {

UserAccount::~UserAccount() {}
void UserAccount::SetUserInfo(std::shared_ptr<Data::DocumentData> user_info) {
  document_data_ = user_info;
}
void UserAccount::SetToken(QString token) {
  token_ = token;
}
int UserAccount::GetUid() {
  return document_data_->getUid();
}
QString UserAccount::GetName() {
  return document_data_->getName();
}
QString UserAccount::GetIcon() {
  return document_data_->getIcon();
}
std::shared_ptr<Data::DocumentData> UserAccount::GetUserInfo() {
  return document_data_;
}

UserAccount::UserAccount() : document_data_(nullptr){}
}  // namespace Local
