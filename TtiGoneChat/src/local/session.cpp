#include "local/session.h"
#include "local/account.h"

namespace Local {

Session::Session(Account* account)
	: account_(account)
{
}

Account& Session::account() const
{
	return *account_;
}

} // namespace Local