#ifndef SESSION_H
#define SESSION_H

namespace PROTO
{
struct ConfigFields;
} // namespace PROTO

namespace Local {
	
class Account;

class Session {
public:
	Session(Account* account);
 ~Session() = default;

	Session(const Session &other) = delete;
	Session &operator=(const Session &other) = delete;

	[[nodiscard]] Account& account() const;

	[[nodiscard]] const PROTO::ConfigFields &serverConfig() const;


private:
	Account *account_;
};

} // namespace Local

#endif // SESSION_H


