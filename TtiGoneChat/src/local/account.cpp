#include "local/account.h"
#include "local/session.h"
#include "local/domain.h"

#include "proto/instance.h"

namespace Local {

Account::Account(Domain* domain, const QString& data_name, int index)
    : domain_(domain) {}

Account::~Account() {}

Domain& Account::domain() const
{
  return *domain_;
}

Proto::Instance& Account::proto() const
{
  	return *proto_;
}

Session& Account::session() const { return *session_; }

Session* Account::maybySession() const { return session_.get(); }

bool Account::sessionExists() const
{
  return session_.get() != nullptr;
}


}  // namespace Local
