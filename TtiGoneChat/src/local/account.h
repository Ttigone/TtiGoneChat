#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

namespace Proto
{
class Instance;
} // namespace PROTO


namespace Local
{

class Domain;
class Session;

class Account
{
public:
	Account(Domain *domain, const QString &data_name, int index);
	~Account();

	[[nodiscard]] Domain &domain() const;
	[[nodiscard]] Proto::Instance &proto() const;
	[[nodiscard]] Session &session() const;
	[[nodiscard]] Session *maybySession() const;
	[[nodiscard]] bool sessionExists() const;

private:
	Domain *domain_;

	std::unique_ptr<Proto::Instance> proto_;

	std::unique_ptr<Session> session_;

};

} // Local

#endif // ACCOUNT_H
 
