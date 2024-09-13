/*****************************************************************/ /**
 * \file   user_account.h
 * \brief  
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef LOCAL_USER_ACCOUNT_H
#define LOCAL_USER_ACCOUNT_H

#include "base/singleton.h"
#include "data/data_document.h"

namespace Local {
class UserAccount : public QObject,
                    public base::Singleton<UserAccount>,
                    public std::enable_shared_from_this<UserAccount> {
  Q_OBJECT
 public:
  friend class Singleton<UserAccount>;
  ~UserAccount();
  void SetUserInfo(std::shared_ptr<Data::DocumentData> user_info);
  void SetToken(QString token);
  int GetUid();
  QString GetName();
  QString GetIcon();
  std::shared_ptr<Data::DocumentData> GetUserInfo();

 private:
  UserAccount();
  std::shared_ptr<Data::DocumentData> document_data_;
  // std::vector<>
  QString token_;
  int chat_load_;
  int contact_loaded_;
};
}  // namespace Local

#endif  // LOCAL_USER_ACCOUNT_H
