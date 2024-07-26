#include "domain.h"

#include "local/account.h"

namespace Local {

Domain::Domain(const QString& data_name)
	: data_name_(data_name)
{
}

Domain::~Domain()
{
}

bool Domain::started() const
{
	return false;
}

void Domain::finsh()
{
}

int Domain::maxAccounts() const
{
	return 0;
}

const std::vector<Domain::AccountWidthIndex>& Domain::accounts() const
{
	return accounts_;
}

} // Local
