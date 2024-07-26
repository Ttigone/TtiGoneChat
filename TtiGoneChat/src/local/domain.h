#ifndef DOMAIN_H
#define DOMAIN_H

#include <QString>

namespace Local 
{

class Account;

class Domain {
public:
	explicit Domain(const QString &data_name);	
	~Domain();
	
	struct AccountWidthIndex {
		int index = 0;
		std::unique_ptr<Account> account;
	};

	[[nodiscard]] bool started() const;

	void finsh();

	[[nodiscard]] int maxAccounts() const;

	[[nodiscard]] const std::vector<AccountWidthIndex>& accounts() const;

private:
	const QString data_name_;
	std::vector<AccountWidthIndex> accounts_;


};

} // Local

#endif // DOMAIN_H